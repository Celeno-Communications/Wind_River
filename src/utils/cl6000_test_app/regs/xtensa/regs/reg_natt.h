#ifndef _REG_NATT_H_
#define _REG_NATT_H_

#include <stdint.h>
#include "_reg_natt.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_NATT__H__FILEID__

#define REG_NATT_COUNT  129


/**
 * @brief NTT_STA_DB_BASE register definition
 *  STA DB base address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_STA_DB_BASE           0x0
 * </pre>
 */
#define NATT_NTT_STA_DB_BASE_ADDR        (REG_NATT_BASE_ADDR+0x00000000)
#define NATT_NTT_STA_DB_BASE_OFFSET      0x00000000
#define NATT_NTT_STA_DB_BASE_INDEX       0x00000000
#define NATT_NTT_STA_DB_BASE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_sta_db_base_get(void)
{
	return REG_PL_RD(NATT_NTT_STA_DB_BASE_ADDR);
}

__INLINE void natt_ntt_sta_db_base_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STA_DB_BASE_ADDR, value);
}

// field definitions
#define NATT_NTT_STA_DB_BASE_NTT_STA_DB_BASE_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STA_DB_BASE_NTT_STA_DB_BASE_LSB    0
#define NATT_NTT_STA_DB_BASE_NTT_STA_DB_BASE_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STA_DB_BASE_NTT_STA_DB_BASE_RST    0x0

__INLINE uint32_t natt_ntt_sta_db_base_ntt_sta_db_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STA_DB_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_sta_db_base_ntt_sta_db_base_setf(uint32_t nttstadbbase)
{
	ASSERT_ERR((((uint32_t)nttstadbbase << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STA_DB_BASE_ADDR, (uint32_t)nttstadbbase << 0);
}

/**
 * @brief NTT_STA_DB_SIZE register definition
 *  STA DB element size register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:00 NTT_STA_DB_SIZE           0x0
 * </pre>
 */
#define NATT_NTT_STA_DB_SIZE_ADDR        (REG_NATT_BASE_ADDR+0x00000004)
#define NATT_NTT_STA_DB_SIZE_OFFSET      0x00000004
#define NATT_NTT_STA_DB_SIZE_INDEX       0x00000001
#define NATT_NTT_STA_DB_SIZE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_sta_db_size_get(void)
{
	return REG_PL_RD(NATT_NTT_STA_DB_SIZE_ADDR);
}

__INLINE void natt_ntt_sta_db_size_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STA_DB_SIZE_ADDR, value);
}

// field definitions
#define NATT_NTT_STA_DB_SIZE_NTT_STA_DB_SIZE_MASK    ((uint32_t)0x00000FFF)
#define NATT_NTT_STA_DB_SIZE_NTT_STA_DB_SIZE_LSB    0
#define NATT_NTT_STA_DB_SIZE_NTT_STA_DB_SIZE_WIDTH    ((uint32_t)0x0000000C)

#define NATT_NTT_STA_DB_SIZE_NTT_STA_DB_SIZE_RST    0x0

__INLINE uint16_t natt_ntt_sta_db_size_ntt_sta_db_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STA_DB_SIZE_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void natt_ntt_sta_db_size_ntt_sta_db_size_setf(uint16_t nttstadbsize)
{
	ASSERT_ERR((((uint32_t)nttstadbsize << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(NATT_NTT_STA_DB_SIZE_ADDR, (uint32_t)nttstadbsize << 0);
}

/**
 * @brief NTT_STA_DB_OFFSET register definition
 *  STA DB NATT parameters offset register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:00 NTT_STA_DB_OFFSET         0x0
 * </pre>
 */
#define NATT_NTT_STA_DB_OFFSET_ADDR        (REG_NATT_BASE_ADDR+0x00000008)
#define NATT_NTT_STA_DB_OFFSET_OFFSET      0x00000008
#define NATT_NTT_STA_DB_OFFSET_INDEX       0x00000002
#define NATT_NTT_STA_DB_OFFSET_RESET       0x00000000

__INLINE uint32_t  natt_ntt_sta_db_offset_get(void)
{
	return REG_PL_RD(NATT_NTT_STA_DB_OFFSET_ADDR);
}

__INLINE void natt_ntt_sta_db_offset_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STA_DB_OFFSET_ADDR, value);
}

// field definitions
#define NATT_NTT_STA_DB_OFFSET_NTT_STA_DB_OFFSET_MASK    ((uint32_t)0x00000FFF)
#define NATT_NTT_STA_DB_OFFSET_NTT_STA_DB_OFFSET_LSB    0
#define NATT_NTT_STA_DB_OFFSET_NTT_STA_DB_OFFSET_WIDTH    ((uint32_t)0x0000000C)

#define NATT_NTT_STA_DB_OFFSET_NTT_STA_DB_OFFSET_RST    0x0

__INLINE uint16_t natt_ntt_sta_db_offset_ntt_sta_db_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STA_DB_OFFSET_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void natt_ntt_sta_db_offset_ntt_sta_db_offset_setf(uint16_t nttstadboffset)
{
	ASSERT_ERR((((uint32_t)nttstadboffset << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(NATT_NTT_STA_DB_OFFSET_ADDR, (uint32_t)nttstadboffset << 0);
}

/**
 * @brief NTT_STR_0_PT_BASE register definition
 *  Policy Table register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_PT_BASE               0x0
 * </pre>
 */
#define NATT_NTT_STR_0_PT_BASE_ADDR        (REG_NATT_BASE_ADDR+0x0000000C)
#define NATT_NTT_STR_0_PT_BASE_OFFSET      0x0000000C
#define NATT_NTT_STR_0_PT_BASE_INDEX       0x00000003
#define NATT_NTT_STR_0_PT_BASE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_pt_base_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_PT_BASE_ADDR);
}

__INLINE void natt_ntt_str_0_pt_base_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_0_PT_BASE_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_0_PT_BASE_NTT_PT_BASE_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_0_PT_BASE_NTT_PT_BASE_LSB    0
#define NATT_NTT_STR_0_PT_BASE_NTT_PT_BASE_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_0_PT_BASE_NTT_PT_BASE_RST    0x0

__INLINE uint32_t natt_ntt_str_0_pt_base_ntt_pt_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_PT_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_0_pt_base_ntt_pt_base_setf(uint32_t nttptbase)
{
	ASSERT_ERR((((uint32_t)nttptbase << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_PT_BASE_ADDR, (uint32_t)nttptbase << 0);
}

/**
 * @brief NTT_STR_0_DESC_BASE register definition
 *  Descriptors chain base address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DESC_BASE             0x0
 * </pre>
 */
#define NATT_NTT_STR_0_DESC_BASE_ADDR        (REG_NATT_BASE_ADDR+0x00000010)
#define NATT_NTT_STR_0_DESC_BASE_OFFSET      0x00000010
#define NATT_NTT_STR_0_DESC_BASE_INDEX       0x00000004
#define NATT_NTT_STR_0_DESC_BASE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_desc_base_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_DESC_BASE_ADDR);
}

__INLINE void natt_ntt_str_0_desc_base_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_0_DESC_BASE_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_0_DESC_BASE_NTT_DESC_BASE_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_0_DESC_BASE_NTT_DESC_BASE_LSB    0
#define NATT_NTT_STR_0_DESC_BASE_NTT_DESC_BASE_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_0_DESC_BASE_NTT_DESC_BASE_RST    0x0

__INLINE uint32_t natt_ntt_str_0_desc_base_ntt_desc_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_DESC_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_0_desc_base_ntt_desc_base_setf(uint32_t nttdescbase)
{
	ASSERT_ERR((((uint32_t)nttdescbase << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_DESC_BASE_ADDR, (uint32_t)nttdescbase << 0);
}

/**
 * @brief NTT_DESC_SIZE register definition
 *  One descriptor size register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DESC_SIZE             0x0
 * </pre>
 */
#define NATT_NTT_DESC_SIZE_ADDR        (REG_NATT_BASE_ADDR+0x00000014)
#define NATT_NTT_DESC_SIZE_OFFSET      0x00000014
#define NATT_NTT_DESC_SIZE_INDEX       0x00000005
#define NATT_NTT_DESC_SIZE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_desc_size_get(void)
{
	return REG_PL_RD(NATT_NTT_DESC_SIZE_ADDR);
}

__INLINE void natt_ntt_desc_size_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_DESC_SIZE_ADDR, value);
}

// field definitions
#define NATT_NTT_DESC_SIZE_NTT_DESC_SIZE_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_DESC_SIZE_NTT_DESC_SIZE_LSB    0
#define NATT_NTT_DESC_SIZE_NTT_DESC_SIZE_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_DESC_SIZE_NTT_DESC_SIZE_RST    0x0

__INLINE uint32_t natt_ntt_desc_size_ntt_desc_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_DESC_SIZE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_desc_size_ntt_desc_size_setf(uint32_t nttdescsize)
{
	ASSERT_ERR((((uint32_t)nttdescsize << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_DESC_SIZE_ADDR, (uint32_t)nttdescsize << 0);
}

/**
 * @brief NTT_DESC_OFFSET register definition
 *  Internal descriptor offset to NATT parameters register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:00 NTT_DESC_PARAM_OFFSET     0x0
 * </pre>
 */
#define NATT_NTT_DESC_OFFSET_ADDR        (REG_NATT_BASE_ADDR+0x00000018)
#define NATT_NTT_DESC_OFFSET_OFFSET      0x00000018
#define NATT_NTT_DESC_OFFSET_INDEX       0x00000006
#define NATT_NTT_DESC_OFFSET_RESET       0x00000000

__INLINE uint32_t  natt_ntt_desc_offset_get(void)
{
	return REG_PL_RD(NATT_NTT_DESC_OFFSET_ADDR);
}

__INLINE void natt_ntt_desc_offset_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_DESC_OFFSET_ADDR, value);
}

// field definitions
#define NATT_NTT_DESC_OFFSET_NTT_DESC_PARAM_OFFSET_MASK    ((uint32_t)0x00000FFF)
#define NATT_NTT_DESC_OFFSET_NTT_DESC_PARAM_OFFSET_LSB    0
#define NATT_NTT_DESC_OFFSET_NTT_DESC_PARAM_OFFSET_WIDTH    ((uint32_t)0x0000000C)

#define NATT_NTT_DESC_OFFSET_NTT_DESC_PARAM_OFFSET_RST    0x0

__INLINE uint16_t natt_ntt_desc_offset_ntt_desc_param_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_DESC_OFFSET_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void natt_ntt_desc_offset_ntt_desc_param_offset_setf(uint16_t nttdescparamoffset)
{
	ASSERT_ERR((((uint32_t)nttdescparamoffset << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(NATT_NTT_DESC_OFFSET_ADDR, (uint32_t)nttdescparamoffset << 0);
}

/**
 * @brief NTT_STR_0_DESC_TSIZE register definition
 *  Total descriptors chain size register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DESC_TSIZE            0x0
 * </pre>
 */
#define NATT_NTT_STR_0_DESC_TSIZE_ADDR        (REG_NATT_BASE_ADDR+0x0000001C)
#define NATT_NTT_STR_0_DESC_TSIZE_OFFSET      0x0000001C
#define NATT_NTT_STR_0_DESC_TSIZE_INDEX       0x00000007
#define NATT_NTT_STR_0_DESC_TSIZE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_desc_tsize_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_DESC_TSIZE_ADDR);
}

__INLINE void natt_ntt_str_0_desc_tsize_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_0_DESC_TSIZE_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_0_DESC_TSIZE_NTT_DESC_TSIZE_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_0_DESC_TSIZE_NTT_DESC_TSIZE_LSB    0
#define NATT_NTT_STR_0_DESC_TSIZE_NTT_DESC_TSIZE_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_0_DESC_TSIZE_NTT_DESC_TSIZE_RST    0x0

__INLINE uint32_t natt_ntt_str_0_desc_tsize_ntt_desc_tsize_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_DESC_TSIZE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_0_desc_tsize_ntt_desc_tsize_setf(uint32_t nttdesctsize)
{
	ASSERT_ERR((((uint32_t)nttdesctsize << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_DESC_TSIZE_ADDR, (uint32_t)nttdesctsize << 0);
}

/**
 * @brief NTT_STR_0_DESC_START register definition
 *  Descriptors chain start address (1st MPDU) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DESC_START            0x0
 * </pre>
 */
#define NATT_NTT_STR_0_DESC_START_ADDR        (REG_NATT_BASE_ADDR+0x00000020)
#define NATT_NTT_STR_0_DESC_START_OFFSET      0x00000020
#define NATT_NTT_STR_0_DESC_START_INDEX       0x00000008
#define NATT_NTT_STR_0_DESC_START_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_desc_start_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_DESC_START_ADDR);
}

__INLINE void natt_ntt_str_0_desc_start_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_0_DESC_START_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_0_DESC_START_NTT_DESC_START_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_0_DESC_START_NTT_DESC_START_LSB    0
#define NATT_NTT_STR_0_DESC_START_NTT_DESC_START_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_0_DESC_START_NTT_DESC_START_RST    0x0

__INLINE uint32_t natt_ntt_str_0_desc_start_ntt_desc_start_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_DESC_START_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_0_desc_start_ntt_desc_start_setf(uint32_t nttdescstart)
{
	ASSERT_ERR((((uint32_t)nttdescstart << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_DESC_START_ADDR, (uint32_t)nttdescstart << 0);
}

/**
 * @brief NTT_STR_0_AIRTIME_LIMIT register definition
 *  AirTime Limit in usec register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 NTT_AIRTIME_LIMIT         0x0
 * </pre>
 */
#define NATT_NTT_STR_0_AIRTIME_LIMIT_ADDR        (REG_NATT_BASE_ADDR+0x00000024)
#define NATT_NTT_STR_0_AIRTIME_LIMIT_OFFSET      0x00000024
#define NATT_NTT_STR_0_AIRTIME_LIMIT_INDEX       0x00000009
#define NATT_NTT_STR_0_AIRTIME_LIMIT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_airtime_limit_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_AIRTIME_LIMIT_ADDR);
}

__INLINE void natt_ntt_str_0_airtime_limit_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_0_AIRTIME_LIMIT_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_0_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_0_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_LSB    0
#define NATT_NTT_STR_0_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_0_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_RST    0x0

__INLINE uint16_t natt_ntt_str_0_airtime_limit_ntt_airtime_limit_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_AIRTIME_LIMIT_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_0_airtime_limit_ntt_airtime_limit_setf(uint16_t nttairtimelimit)
{
	ASSERT_ERR((((uint32_t)nttairtimelimit << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_AIRTIME_LIMIT_ADDR, (uint32_t)nttairtimelimit << 0);
}

/**
 * @brief NTT_STR_0_MPDU_LIMIT register definition
 *  BA and valid MPDUs limit register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:24 NTT_STA_INDEX             0x0
 *    20:12 NTT_MAX_MPDU              0x0
 *    08:00 NTT_BA_WINDOW             0x0
 * </pre>
 */
#define NATT_NTT_STR_0_MPDU_LIMIT_ADDR        (REG_NATT_BASE_ADDR+0x00000028)
#define NATT_NTT_STR_0_MPDU_LIMIT_OFFSET      0x00000028
#define NATT_NTT_STR_0_MPDU_LIMIT_INDEX       0x0000000A
#define NATT_NTT_STR_0_MPDU_LIMIT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_mpdu_limit_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_MPDU_LIMIT_ADDR);
}

__INLINE void natt_ntt_str_0_mpdu_limit_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_0_MPDU_LIMIT_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_0_MPDU_LIMIT_NTT_STA_INDEX_MASK    ((uint32_t)0x7F000000)
#define NATT_NTT_STR_0_MPDU_LIMIT_NTT_STA_INDEX_LSB    24
#define NATT_NTT_STR_0_MPDU_LIMIT_NTT_STA_INDEX_WIDTH    ((uint32_t)0x00000007)
#define NATT_NTT_STR_0_MPDU_LIMIT_NTT_MAX_MPDU_MASK    ((uint32_t)0x001FF000)
#define NATT_NTT_STR_0_MPDU_LIMIT_NTT_MAX_MPDU_LSB    12
#define NATT_NTT_STR_0_MPDU_LIMIT_NTT_MAX_MPDU_WIDTH    ((uint32_t)0x00000009)
#define NATT_NTT_STR_0_MPDU_LIMIT_NTT_BA_WINDOW_MASK    ((uint32_t)0x000001FF)
#define NATT_NTT_STR_0_MPDU_LIMIT_NTT_BA_WINDOW_LSB    0
#define NATT_NTT_STR_0_MPDU_LIMIT_NTT_BA_WINDOW_WIDTH    ((uint32_t)0x00000009)

#define NATT_NTT_STR_0_MPDU_LIMIT_NTT_STA_INDEX_RST    0x0
#define NATT_NTT_STR_0_MPDU_LIMIT_NTT_MAX_MPDU_RST    0x0
#define NATT_NTT_STR_0_MPDU_LIMIT_NTT_BA_WINDOW_RST    0x0

__INLINE void natt_ntt_str_0_mpdu_limit_pack(uint8_t ntt_sta_index, uint16_t ntt_max_mpdu, uint16_t ntt_ba_window)
{
	ASSERT_ERR((((uint32_t)ntt_sta_index << 24) & ~((uint32_t)0x7F000000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_max_mpdu << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_ba_window << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_MPDU_LIMIT_ADDR,  ((uint32_t)ntt_sta_index << 24) |((uint32_t)ntt_max_mpdu << 12) |((uint32_t)ntt_ba_window << 0));
}

__INLINE void natt_ntt_str_0_mpdu_limit_unpack(uint8_t* ntt_sta_index, uint16_t* ntt_max_mpdu, uint16_t* ntt_ba_window)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_MPDU_LIMIT_ADDR);

	*ntt_sta_index = (localVal & ((uint32_t)0x7F000000)) >>  24;
	*ntt_max_mpdu = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*ntt_ba_window = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t natt_ntt_str_0_mpdu_limit_ntt_sta_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_MPDU_LIMIT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x7F000000)) >> 24);
}
__INLINE void natt_ntt_str_0_mpdu_limit_ntt_sta_index_setf(uint8_t nttstaindex)
{
	ASSERT_ERR((((uint32_t)nttstaindex << 24) & ~((uint32_t)0x7F000000)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_MPDU_LIMIT_ADDR, (REG_PL_RD(NATT_NTT_STR_0_MPDU_LIMIT_ADDR) & ~((uint32_t)0x7F000000)) | ((uint32_t)nttstaindex <<24));
}
__INLINE uint16_t natt_ntt_str_0_mpdu_limit_ntt_max_mpdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_MPDU_LIMIT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void natt_ntt_str_0_mpdu_limit_ntt_max_mpdu_setf(uint16_t nttmaxmpdu)
{
	ASSERT_ERR((((uint32_t)nttmaxmpdu << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_MPDU_LIMIT_ADDR, (REG_PL_RD(NATT_NTT_STR_0_MPDU_LIMIT_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)nttmaxmpdu <<12));
}
__INLINE uint16_t natt_ntt_str_0_mpdu_limit_ntt_ba_window_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_MPDU_LIMIT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void natt_ntt_str_0_mpdu_limit_ntt_ba_window_setf(uint16_t nttbawindow)
{
	ASSERT_ERR((((uint32_t)nttbawindow << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_MPDU_LIMIT_ADDR, (REG_PL_RD(NATT_NTT_STR_0_MPDU_LIMIT_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)nttbawindow <<0));
}

/**
 * @brief NTT_STR_0_THD_BASE_LOC register definition
 *  THD location for psdu_length register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_THD_LOC               0x0
 * </pre>
 */
#define NATT_NTT_STR_0_THD_BASE_LOC_ADDR        (REG_NATT_BASE_ADDR+0x0000002C)
#define NATT_NTT_STR_0_THD_BASE_LOC_OFFSET      0x0000002C
#define NATT_NTT_STR_0_THD_BASE_LOC_INDEX       0x0000000B
#define NATT_NTT_STR_0_THD_BASE_LOC_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_thd_base_loc_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_THD_BASE_LOC_ADDR);
}

__INLINE void natt_ntt_str_0_thd_base_loc_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_0_THD_BASE_LOC_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_0_THD_BASE_LOC_NTT_THD_LOC_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_0_THD_BASE_LOC_NTT_THD_LOC_LSB    0
#define NATT_NTT_STR_0_THD_BASE_LOC_NTT_THD_LOC_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_0_THD_BASE_LOC_NTT_THD_LOC_RST    0x0

__INLINE uint32_t natt_ntt_str_0_thd_base_loc_ntt_thd_loc_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_THD_BASE_LOC_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_0_thd_base_loc_ntt_thd_loc_setf(uint32_t nttthdloc)
{
	ASSERT_ERR((((uint32_t)nttthdloc << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_THD_BASE_LOC_ADDR, (uint32_t)nttthdloc << 0);
}

/**
 * @brief NTT_STR_0_CR_INFO register definition
 *  End of process closing reason register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05:00 NTT_CR_INFO               0x0
 * </pre>
 */
#define NATT_NTT_STR_0_CR_INFO_ADDR        (REG_NATT_BASE_ADDR+0x00000030)
#define NATT_NTT_STR_0_CR_INFO_OFFSET      0x00000030
#define NATT_NTT_STR_0_CR_INFO_INDEX       0x0000000C
#define NATT_NTT_STR_0_CR_INFO_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_cr_info_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_CR_INFO_ADDR);
}

// field definitions
#define NATT_NTT_STR_0_CR_INFO_NTT_CR_INFO_MASK    ((uint32_t)0x0000003F)
#define NATT_NTT_STR_0_CR_INFO_NTT_CR_INFO_LSB    0
#define NATT_NTT_STR_0_CR_INFO_NTT_CR_INFO_WIDTH    ((uint32_t)0x00000006)

#define NATT_NTT_STR_0_CR_INFO_NTT_CR_INFO_RST    0x0

__INLINE uint8_t natt_ntt_str_0_cr_info_ntt_cr_info_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_CR_INFO_ADDR);
	return (uint8_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_0_LD_INFO register definition
 *  End of process last description address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_LD_INFO               0x0
 * </pre>
 */
#define NATT_NTT_STR_0_LD_INFO_ADDR        (REG_NATT_BASE_ADDR+0x00000034)
#define NATT_NTT_STR_0_LD_INFO_OFFSET      0x00000034
#define NATT_NTT_STR_0_LD_INFO_INDEX       0x0000000D
#define NATT_NTT_STR_0_LD_INFO_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_ld_info_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_LD_INFO_ADDR);
}

// field definitions
#define NATT_NTT_STR_0_LD_INFO_NTT_LD_INFO_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_0_LD_INFO_NTT_LD_INFO_LSB    0
#define NATT_NTT_STR_0_LD_INFO_NTT_LD_INFO_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_0_LD_INFO_NTT_LD_INFO_RST    0x0

__INLINE uint32_t natt_ntt_str_0_ld_info_ntt_ld_info_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_LD_INFO_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_HE_MU_CONF register definition
 *  HE MU Configuration register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    10:08 NTT_HE_LTF_SYM_NUM        0x0
 *    04:00 NTT_HE_SIGB_NUM           0x8
 * </pre>
 */
#define NATT_NTT_HE_MU_CONF_ADDR        (REG_NATT_BASE_ADDR+0x00000038)
#define NATT_NTT_HE_MU_CONF_OFFSET      0x00000038
#define NATT_NTT_HE_MU_CONF_INDEX       0x0000000E
#define NATT_NTT_HE_MU_CONF_RESET       0x00000008

__INLINE uint32_t  natt_ntt_he_mu_conf_get(void)
{
	return REG_PL_RD(NATT_NTT_HE_MU_CONF_ADDR);
}

__INLINE void natt_ntt_he_mu_conf_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_HE_MU_CONF_ADDR, value);
}

// field definitions
#define NATT_NTT_HE_MU_CONF_NTT_HE_LTF_SYM_NUM_MASK    ((uint32_t)0x00000700)
#define NATT_NTT_HE_MU_CONF_NTT_HE_LTF_SYM_NUM_LSB    8
#define NATT_NTT_HE_MU_CONF_NTT_HE_LTF_SYM_NUM_WIDTH    ((uint32_t)0x00000003)
#define NATT_NTT_HE_MU_CONF_NTT_HE_SIGB_NUM_MASK    ((uint32_t)0x0000001F)
#define NATT_NTT_HE_MU_CONF_NTT_HE_SIGB_NUM_LSB    0
#define NATT_NTT_HE_MU_CONF_NTT_HE_SIGB_NUM_WIDTH    ((uint32_t)0x00000005)

#define NATT_NTT_HE_MU_CONF_NTT_HE_LTF_SYM_NUM_RST    0x0
#define NATT_NTT_HE_MU_CONF_NTT_HE_SIGB_NUM_RST    0x8

__INLINE void natt_ntt_he_mu_conf_pack(uint8_t ntt_he_ltf_sym_num, uint8_t ntt_he_sigb_num)
{
	ASSERT_ERR((((uint32_t)ntt_he_ltf_sym_num << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)ntt_he_sigb_num << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(NATT_NTT_HE_MU_CONF_ADDR,  ((uint32_t)ntt_he_ltf_sym_num << 8) |((uint32_t)ntt_he_sigb_num << 0));
}

__INLINE void natt_ntt_he_mu_conf_unpack(uint8_t* ntt_he_ltf_sym_num, uint8_t* ntt_he_sigb_num)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HE_MU_CONF_ADDR);

	*ntt_he_ltf_sym_num = (localVal & ((uint32_t)0x00000700)) >>  8;
	*ntt_he_sigb_num = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t natt_ntt_he_mu_conf_ntt_he_ltf_sym_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HE_MU_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void natt_ntt_he_mu_conf_ntt_he_ltf_sym_num_setf(uint8_t nttheltfsymnum)
{
	ASSERT_ERR((((uint32_t)nttheltfsymnum << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(NATT_NTT_HE_MU_CONF_ADDR, (REG_PL_RD(NATT_NTT_HE_MU_CONF_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)nttheltfsymnum <<8));
}
__INLINE uint8_t natt_ntt_he_mu_conf_ntt_he_sigb_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HE_MU_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void natt_ntt_he_mu_conf_ntt_he_sigb_num_setf(uint8_t ntthesigbnum)
{
	ASSERT_ERR((((uint32_t)ntthesigbnum << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(NATT_NTT_HE_MU_CONF_ADDR, (REG_PL_RD(NATT_NTT_HE_MU_CONF_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)ntthesigbnum <<0));
}

/**
 * @brief NTT_COMMAND register definition
 *  Start NATT computation register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    NTT_ACTIVATE              0              
 *    06:04 STR_CHOSEN                0x0
 *    01:00 CBW_CONF                  0x0
 * </pre>
 */
#define NATT_NTT_COMMAND_ADDR        (REG_NATT_BASE_ADDR+0x0000003C)
#define NATT_NTT_COMMAND_OFFSET      0x0000003C
#define NATT_NTT_COMMAND_INDEX       0x0000000F
#define NATT_NTT_COMMAND_RESET       0x00000000

__INLINE uint32_t  natt_ntt_command_get(void)
{
	return REG_PL_RD(NATT_NTT_COMMAND_ADDR);
}

__INLINE void natt_ntt_command_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_COMMAND_ADDR, value);
}

// field definitions
#define NATT_NTT_COMMAND_NTT_ACTIVATE_BIT    ((uint32_t)0x80000000)
#define NATT_NTT_COMMAND_NTT_ACTIVATE_POS    31
#define NATT_NTT_COMMAND_STR_CHOSEN_MASK    ((uint32_t)0x00000070)
#define NATT_NTT_COMMAND_STR_CHOSEN_LSB     4
#define NATT_NTT_COMMAND_STR_CHOSEN_WIDTH    ((uint32_t)0x00000003)
#define NATT_NTT_COMMAND_CBW_CONF_MASK      ((uint32_t)0x00000003)
#define NATT_NTT_COMMAND_CBW_CONF_LSB       0
#define NATT_NTT_COMMAND_CBW_CONF_WIDTH     ((uint32_t)0x00000002)

#define NATT_NTT_COMMAND_NTT_ACTIVATE_RST    0x0
#define NATT_NTT_COMMAND_STR_CHOSEN_RST     0x0
#define NATT_NTT_COMMAND_CBW_CONF_RST       0x0

__INLINE void natt_ntt_command_pack(uint8_t ntt_activate, uint8_t str_chosen, uint8_t cbw_conf)
{
	ASSERT_ERR((((uint32_t)ntt_activate << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)str_chosen << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)cbw_conf << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(NATT_NTT_COMMAND_ADDR,  ((uint32_t)ntt_activate << 31) |((uint32_t)str_chosen << 4) |((uint32_t)cbw_conf << 0));
}

__INLINE void natt_ntt_command_unpack(uint8_t* ntt_activate, uint8_t* str_chosen, uint8_t* cbw_conf)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_COMMAND_ADDR);

	*ntt_activate = (localVal & ((uint32_t)0x80000000)) >>  31;
	*str_chosen = (localVal & ((uint32_t)0x00000070)) >>  4;
	*cbw_conf = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE void natt_ntt_command_ntt_activate_setf(uint8_t nttactivate)
{
	ASSERT_ERR((((uint32_t)nttactivate << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(NATT_NTT_COMMAND_ADDR, (REG_PL_RD(NATT_NTT_COMMAND_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)nttactivate <<31));
}
__INLINE uint8_t natt_ntt_command_str_chosen_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_COMMAND_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void natt_ntt_command_str_chosen_setf(uint8_t strchosen)
{
	ASSERT_ERR((((uint32_t)strchosen << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(NATT_NTT_COMMAND_ADDR, (REG_PL_RD(NATT_NTT_COMMAND_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)strchosen <<4));
}
__INLINE uint8_t natt_ntt_command_cbw_conf_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_COMMAND_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void natt_ntt_command_cbw_conf_setf(uint8_t cbwconf)
{
	ASSERT_ERR((((uint32_t)cbwconf << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(NATT_NTT_COMMAND_ADDR, (REG_PL_RD(NATT_NTT_COMMAND_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)cbwconf <<0));
}

/**
 * @brief NTT_COMP_ONLY register definition
 *  Start Max. length computation (PhyRate*TXoP) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    NTT_COMP_ONLY             0              
 * </pre>
 */
#define NATT_NTT_COMP_ONLY_ADDR        (REG_NATT_BASE_ADDR+0x00000040)
#define NATT_NTT_COMP_ONLY_OFFSET      0x00000040
#define NATT_NTT_COMP_ONLY_INDEX       0x00000010
#define NATT_NTT_COMP_ONLY_RESET       0x00000000

__INLINE uint32_t  natt_ntt_comp_only_get(void)
{
	return REG_PL_RD(NATT_NTT_COMP_ONLY_ADDR);
}

__INLINE void natt_ntt_comp_only_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_COMP_ONLY_ADDR, value);
}

// field definitions
#define NATT_NTT_COMP_ONLY_NTT_COMP_ONLY_BIT    ((uint32_t)0x00000001)
#define NATT_NTT_COMP_ONLY_NTT_COMP_ONLY_POS    0

#define NATT_NTT_COMP_ONLY_NTT_COMP_ONLY_RST    0x0

__INLINE uint8_t natt_ntt_comp_only_ntt_comp_only_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_COMP_ONLY_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void natt_ntt_comp_only_ntt_comp_only_setf(uint8_t nttcomponly)
{
	ASSERT_ERR((((uint32_t)nttcomponly << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(NATT_NTT_COMP_ONLY_ADDR, (uint32_t)nttcomponly << 0);
}

/**
 * @brief NTT_COMP_RES register definition
 *  NTT_COMP_ONLY command results register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:00 NTT_COMP_RES              0x0
 * </pre>
 */
#define NATT_NTT_COMP_RES_ADDR        (REG_NATT_BASE_ADDR+0x00000044)
#define NATT_NTT_COMP_RES_OFFSET      0x00000044
#define NATT_NTT_COMP_RES_INDEX       0x00000011
#define NATT_NTT_COMP_RES_RESET       0x00000000

__INLINE uint32_t  natt_ntt_comp_res_get(void)
{
	return REG_PL_RD(NATT_NTT_COMP_RES_ADDR);
}

// field definitions
#define NATT_NTT_COMP_RES_NTT_COMP_RES_MASK    ((uint32_t)0x00FFFFFF)
#define NATT_NTT_COMP_RES_NTT_COMP_RES_LSB    0
#define NATT_NTT_COMP_RES_NTT_COMP_RES_WIDTH    ((uint32_t)0x00000018)

#define NATT_NTT_COMP_RES_NTT_COMP_RES_RST    0x0

__INLINE uint32_t natt_ntt_comp_res_ntt_comp_res_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_COMP_RES_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_INT_RAW_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    12:08 NTT_ERROR                 0x0
 *    04:00 NTT_DONE                  0x0
 * </pre>
 */
#define NATT_NTT_INT_RAW_STATUS_ADDR        (REG_NATT_BASE_ADDR+0x00000048)
#define NATT_NTT_INT_RAW_STATUS_OFFSET      0x00000048
#define NATT_NTT_INT_RAW_STATUS_INDEX       0x00000012
#define NATT_NTT_INT_RAW_STATUS_RESET       0x00000000

__INLINE uint32_t  natt_ntt_int_raw_status_get(void)
{
	return REG_PL_RD(NATT_NTT_INT_RAW_STATUS_ADDR);
}

// field definitions
#define NATT_NTT_INT_RAW_STATUS_NTT_ERROR_MASK    ((uint32_t)0x00001F00)
#define NATT_NTT_INT_RAW_STATUS_NTT_ERROR_LSB    8
#define NATT_NTT_INT_RAW_STATUS_NTT_ERROR_WIDTH    ((uint32_t)0x00000005)
#define NATT_NTT_INT_RAW_STATUS_NTT_DONE_MASK    ((uint32_t)0x0000001F)
#define NATT_NTT_INT_RAW_STATUS_NTT_DONE_LSB    0
#define NATT_NTT_INT_RAW_STATUS_NTT_DONE_WIDTH    ((uint32_t)0x00000005)

#define NATT_NTT_INT_RAW_STATUS_NTT_ERROR_RST    0x0
#define NATT_NTT_INT_RAW_STATUS_NTT_DONE_RST    0x0

__INLINE void natt_ntt_int_raw_status_unpack(uint8_t* ntt_error, uint8_t* ntt_done)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_INT_RAW_STATUS_ADDR);

	*ntt_error = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*ntt_done = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t natt_ntt_int_raw_status_ntt_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_INT_RAW_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE uint8_t natt_ntt_int_raw_status_ntt_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_INT_RAW_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}

/**
 * @brief NTT_INT_STATUS register definition
 *  Computation done interrupt register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    12:08 NTT_ERROR                 0x0
 *    04:00 NTT_DONE                  0x0
 * </pre>
 */
#define NATT_NTT_INT_STATUS_ADDR        (REG_NATT_BASE_ADDR+0x0000004C)
#define NATT_NTT_INT_STATUS_OFFSET      0x0000004C
#define NATT_NTT_INT_STATUS_INDEX       0x00000013
#define NATT_NTT_INT_STATUS_RESET       0x00000000

__INLINE uint32_t  natt_ntt_int_status_get(void)
{
	return REG_PL_RD(NATT_NTT_INT_STATUS_ADDR);
}

__INLINE void natt_ntt_int_status_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_INT_STATUS_ADDR, value);
}

// field definitions
#define NATT_NTT_INT_STATUS_NTT_ERROR_MASK    ((uint32_t)0x00001F00)
#define NATT_NTT_INT_STATUS_NTT_ERROR_LSB    8
#define NATT_NTT_INT_STATUS_NTT_ERROR_WIDTH    ((uint32_t)0x00000005)
#define NATT_NTT_INT_STATUS_NTT_DONE_MASK    ((uint32_t)0x0000001F)
#define NATT_NTT_INT_STATUS_NTT_DONE_LSB    0
#define NATT_NTT_INT_STATUS_NTT_DONE_WIDTH    ((uint32_t)0x00000005)

#define NATT_NTT_INT_STATUS_NTT_ERROR_RST    0x0
#define NATT_NTT_INT_STATUS_NTT_DONE_RST    0x0

__INLINE void natt_ntt_int_status_pack(uint8_t ntt_error, uint8_t ntt_done)
{
	ASSERT_ERR((((uint32_t)ntt_error << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)ntt_done << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(NATT_NTT_INT_STATUS_ADDR,  ((uint32_t)ntt_error << 8) |((uint32_t)ntt_done << 0));
}

__INLINE void natt_ntt_int_status_unpack(uint8_t* ntt_error, uint8_t* ntt_done)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_INT_STATUS_ADDR);

	*ntt_error = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*ntt_done = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t natt_ntt_int_status_ntt_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_INT_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void natt_ntt_int_status_ntt_error_setf(uint8_t ntterror)
{
	ASSERT_ERR((((uint32_t)ntterror << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(NATT_NTT_INT_STATUS_ADDR, (REG_PL_RD(NATT_NTT_INT_STATUS_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)ntterror <<8));
}
__INLINE uint8_t natt_ntt_int_status_ntt_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_INT_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void natt_ntt_int_status_ntt_done_setf(uint8_t nttdone)
{
	ASSERT_ERR((((uint32_t)nttdone << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(NATT_NTT_INT_STATUS_ADDR, (REG_PL_RD(NATT_NTT_INT_STATUS_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)nttdone <<0));
}

/**
 * @brief NTT_INT_CLR register definition
 *  Clear done interrupt (NTT_INT_STATUS) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    12:08 NTT_ERROR_CLR             0x0
 *    04:00 NTT_DONE_CLR              0x0
 * </pre>
 */
#define NATT_NTT_INT_CLR_ADDR        (REG_NATT_BASE_ADDR+0x00000050)
#define NATT_NTT_INT_CLR_OFFSET      0x00000050
#define NATT_NTT_INT_CLR_INDEX       0x00000014
#define NATT_NTT_INT_CLR_RESET       0x00000000

__INLINE uint32_t  natt_ntt_int_clr_get(void)
{
	return REG_PL_RD(NATT_NTT_INT_CLR_ADDR);
}

__INLINE void natt_ntt_int_clr_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_INT_CLR_ADDR, value);
}

// field definitions
#define NATT_NTT_INT_CLR_NTT_ERROR_CLR_MASK    ((uint32_t)0x00001F00)
#define NATT_NTT_INT_CLR_NTT_ERROR_CLR_LSB    8
#define NATT_NTT_INT_CLR_NTT_ERROR_CLR_WIDTH    ((uint32_t)0x00000005)
#define NATT_NTT_INT_CLR_NTT_DONE_CLR_MASK    ((uint32_t)0x0000001F)
#define NATT_NTT_INT_CLR_NTT_DONE_CLR_LSB    0
#define NATT_NTT_INT_CLR_NTT_DONE_CLR_WIDTH    ((uint32_t)0x00000005)

#define NATT_NTT_INT_CLR_NTT_ERROR_CLR_RST    0x0
#define NATT_NTT_INT_CLR_NTT_DONE_CLR_RST    0x0

__INLINE void natt_ntt_int_clr_pack(uint8_t ntt_error_clr, uint8_t ntt_done_clr)
{
	ASSERT_ERR((((uint32_t)ntt_error_clr << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)ntt_done_clr << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(NATT_NTT_INT_CLR_ADDR,  ((uint32_t)ntt_error_clr << 8) |((uint32_t)ntt_done_clr << 0));
}

__INLINE void natt_ntt_int_clr_unpack(uint8_t* ntt_error_clr, uint8_t* ntt_done_clr)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_INT_CLR_ADDR);

	*ntt_error_clr = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*ntt_done_clr = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t natt_ntt_int_clr_ntt_error_clr_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_INT_CLR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void natt_ntt_int_clr_ntt_error_clr_setf(uint8_t ntterrorclr)
{
	ASSERT_ERR((((uint32_t)ntterrorclr << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(NATT_NTT_INT_CLR_ADDR, (REG_PL_RD(NATT_NTT_INT_CLR_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)ntterrorclr <<8));
}
__INLINE uint8_t natt_ntt_int_clr_ntt_done_clr_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_INT_CLR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void natt_ntt_int_clr_ntt_done_clr_setf(uint8_t nttdoneclr)
{
	ASSERT_ERR((((uint32_t)nttdoneclr << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(NATT_NTT_INT_CLR_ADDR, (REG_PL_RD(NATT_NTT_INT_CLR_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)nttdoneclr <<0));
}

/**
 * @brief NTT_INT_ENABLE register definition
 *  Mask NTT_DONE interrupt register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    12:08 NTT_ERROR_ENABLE          0x0
 *    04:00 NTT_DONE_ENABLE           0x0
 * </pre>
 */
#define NATT_NTT_INT_ENABLE_ADDR        (REG_NATT_BASE_ADDR+0x00000054)
#define NATT_NTT_INT_ENABLE_OFFSET      0x00000054
#define NATT_NTT_INT_ENABLE_INDEX       0x00000015
#define NATT_NTT_INT_ENABLE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_int_enable_get(void)
{
	return REG_PL_RD(NATT_NTT_INT_ENABLE_ADDR);
}

__INLINE void natt_ntt_int_enable_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_INT_ENABLE_ADDR, value);
}

// field definitions
#define NATT_NTT_INT_ENABLE_NTT_ERROR_ENABLE_MASK    ((uint32_t)0x00001F00)
#define NATT_NTT_INT_ENABLE_NTT_ERROR_ENABLE_LSB    8
#define NATT_NTT_INT_ENABLE_NTT_ERROR_ENABLE_WIDTH    ((uint32_t)0x00000005)
#define NATT_NTT_INT_ENABLE_NTT_DONE_ENABLE_MASK    ((uint32_t)0x0000001F)
#define NATT_NTT_INT_ENABLE_NTT_DONE_ENABLE_LSB    0
#define NATT_NTT_INT_ENABLE_NTT_DONE_ENABLE_WIDTH    ((uint32_t)0x00000005)

#define NATT_NTT_INT_ENABLE_NTT_ERROR_ENABLE_RST    0x0
#define NATT_NTT_INT_ENABLE_NTT_DONE_ENABLE_RST    0x0

__INLINE void natt_ntt_int_enable_pack(uint8_t ntt_error_enable, uint8_t ntt_done_enable)
{
	ASSERT_ERR((((uint32_t)ntt_error_enable << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)ntt_done_enable << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(NATT_NTT_INT_ENABLE_ADDR,  ((uint32_t)ntt_error_enable << 8) |((uint32_t)ntt_done_enable << 0));
}

__INLINE void natt_ntt_int_enable_unpack(uint8_t* ntt_error_enable, uint8_t* ntt_done_enable)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_INT_ENABLE_ADDR);

	*ntt_error_enable = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*ntt_done_enable = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t natt_ntt_int_enable_ntt_error_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_INT_ENABLE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void natt_ntt_int_enable_ntt_error_enable_setf(uint8_t ntterrorenable)
{
	ASSERT_ERR((((uint32_t)ntterrorenable << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(NATT_NTT_INT_ENABLE_ADDR, (REG_PL_RD(NATT_NTT_INT_ENABLE_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)ntterrorenable <<8));
}
__INLINE uint8_t natt_ntt_int_enable_ntt_done_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_INT_ENABLE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void natt_ntt_int_enable_ntt_done_enable_setf(uint8_t nttdoneenable)
{
	ASSERT_ERR((((uint32_t)nttdoneenable << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(NATT_NTT_INT_ENABLE_ADDR, (REG_PL_RD(NATT_NTT_INT_ENABLE_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)nttdoneenable <<0));
}

/**
 * @brief NTT_INT_FORCE register definition
 *  Force NATT interrupt register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    12:08 NTT_ERROR_FORCE           0x0
 *    04:00 NTT_DONE_FORCE            0x0
 * </pre>
 */
#define NATT_NTT_INT_FORCE_ADDR        (REG_NATT_BASE_ADDR+0x00000058)
#define NATT_NTT_INT_FORCE_OFFSET      0x00000058
#define NATT_NTT_INT_FORCE_INDEX       0x00000016
#define NATT_NTT_INT_FORCE_RESET       0x00000000

__INLINE void natt_ntt_int_force_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_INT_FORCE_ADDR, value);
}

// field definitions
#define NATT_NTT_INT_FORCE_NTT_ERROR_FORCE_MASK    ((uint32_t)0x00001F00)
#define NATT_NTT_INT_FORCE_NTT_ERROR_FORCE_LSB    8
#define NATT_NTT_INT_FORCE_NTT_ERROR_FORCE_WIDTH    ((uint32_t)0x00000005)
#define NATT_NTT_INT_FORCE_NTT_DONE_FORCE_MASK    ((uint32_t)0x0000001F)
#define NATT_NTT_INT_FORCE_NTT_DONE_FORCE_LSB    0
#define NATT_NTT_INT_FORCE_NTT_DONE_FORCE_WIDTH    ((uint32_t)0x00000005)

#define NATT_NTT_INT_FORCE_NTT_ERROR_FORCE_RST    0x0
#define NATT_NTT_INT_FORCE_NTT_DONE_FORCE_RST    0x0

__INLINE void natt_ntt_int_force_pack(uint8_t ntt_error_force, uint8_t ntt_done_force)
{
	ASSERT_ERR((((uint32_t)ntt_error_force << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)ntt_done_force << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(NATT_NTT_INT_FORCE_ADDR,  ((uint32_t)ntt_error_force << 8) |((uint32_t)ntt_done_force << 0));
}

__INLINE void natt_ntt_int_force_ntt_error_force_setf(uint8_t ntterrorforce)
{
	ASSERT_ERR((((uint32_t)ntterrorforce << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(NATT_NTT_INT_FORCE_ADDR, (REG_PL_RD(NATT_NTT_INT_FORCE_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)ntterrorforce <<8));
}
__INLINE void natt_ntt_int_force_ntt_done_force_setf(uint8_t nttdoneforce)
{
	ASSERT_ERR((((uint32_t)nttdoneforce << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(NATT_NTT_INT_FORCE_ADDR, (REG_PL_RD(NATT_NTT_INT_FORCE_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)nttdoneforce <<0));
}

/**
 * @brief NTT_MODE register definition
 *  NATT mode register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    06    NTT_ABORT_IF_NO_FIT       0              
 *    05    NTT_RST_DESC_BASE         0              
 *    04    DISABLE_NTT_MAC_DONE      0              
 *    03    INCLUDE_SE                0              
 *    02    SKIP_TXD_WRITE            0              
 *    01    NTT_FAST_MODE             0              
 *    00    NTT_CMMN_ATL_MODE         0              
 * </pre>
 */
#define NATT_NTT_MODE_ADDR        (REG_NATT_BASE_ADDR+0x0000005C)
#define NATT_NTT_MODE_OFFSET      0x0000005C
#define NATT_NTT_MODE_INDEX       0x00000017
#define NATT_NTT_MODE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_mode_get(void)
{
	return REG_PL_RD(NATT_NTT_MODE_ADDR);
}

__INLINE void natt_ntt_mode_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_MODE_ADDR, value);
}

// field definitions
#define NATT_NTT_MODE_NTT_ABORT_IF_NO_FIT_BIT    ((uint32_t)0x00000040)
#define NATT_NTT_MODE_NTT_ABORT_IF_NO_FIT_POS    6
#define NATT_NTT_MODE_NTT_RST_DESC_BASE_BIT    ((uint32_t)0x00000020)
#define NATT_NTT_MODE_NTT_RST_DESC_BASE_POS    5
#define NATT_NTT_MODE_DISABLE_NTT_MAC_DONE_BIT    ((uint32_t)0x00000010)
#define NATT_NTT_MODE_DISABLE_NTT_MAC_DONE_POS    4
#define NATT_NTT_MODE_INCLUDE_SE_BIT        ((uint32_t)0x00000008)
#define NATT_NTT_MODE_INCLUDE_SE_POS        3
#define NATT_NTT_MODE_SKIP_TXD_WRITE_BIT    ((uint32_t)0x00000004)
#define NATT_NTT_MODE_SKIP_TXD_WRITE_POS    2
#define NATT_NTT_MODE_NTT_FAST_MODE_BIT     ((uint32_t)0x00000002)
#define NATT_NTT_MODE_NTT_FAST_MODE_POS     1
#define NATT_NTT_MODE_NTT_CMMN_ATL_MODE_BIT    ((uint32_t)0x00000001)
#define NATT_NTT_MODE_NTT_CMMN_ATL_MODE_POS    0

#define NATT_NTT_MODE_NTT_ABORT_IF_NO_FIT_RST    0x0
#define NATT_NTT_MODE_NTT_RST_DESC_BASE_RST    0x0
#define NATT_NTT_MODE_DISABLE_NTT_MAC_DONE_RST    0x0
#define NATT_NTT_MODE_INCLUDE_SE_RST        0x0
#define NATT_NTT_MODE_SKIP_TXD_WRITE_RST    0x0
#define NATT_NTT_MODE_NTT_FAST_MODE_RST     0x0
#define NATT_NTT_MODE_NTT_CMMN_ATL_MODE_RST    0x0

__INLINE void natt_ntt_mode_pack(uint8_t ntt_abort_if_no_fit, uint8_t ntt_rst_desc_base, uint8_t disable_ntt_mac_done, uint8_t include_se, uint8_t skip_txd_write, uint8_t ntt_fast_mode, uint8_t ntt_cmmn_atl_mode)
{
	ASSERT_ERR((((uint32_t)ntt_abort_if_no_fit << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)ntt_rst_desc_base << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)disable_ntt_mac_done << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)include_se << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)skip_txd_write << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)ntt_fast_mode << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)ntt_cmmn_atl_mode << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(NATT_NTT_MODE_ADDR,  ((uint32_t)ntt_abort_if_no_fit << 6) |((uint32_t)ntt_rst_desc_base << 5) |((uint32_t)disable_ntt_mac_done << 4) |((uint32_t)include_se << 3) |((uint32_t)skip_txd_write << 2) |((uint32_t)ntt_fast_mode << 1) |((uint32_t)ntt_cmmn_atl_mode << 0));
}

__INLINE void natt_ntt_mode_unpack(uint8_t* ntt_abort_if_no_fit, uint8_t* ntt_rst_desc_base, uint8_t* disable_ntt_mac_done, uint8_t* include_se, uint8_t* skip_txd_write, uint8_t* ntt_fast_mode, uint8_t* ntt_cmmn_atl_mode)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_MODE_ADDR);

	*ntt_abort_if_no_fit = (localVal & ((uint32_t)0x00000040)) >>  6;
	*ntt_rst_desc_base = (localVal & ((uint32_t)0x00000020)) >>  5;
	*disable_ntt_mac_done = (localVal & ((uint32_t)0x00000010)) >>  4;
	*include_se = (localVal & ((uint32_t)0x00000008)) >>  3;
	*skip_txd_write = (localVal & ((uint32_t)0x00000004)) >>  2;
	*ntt_fast_mode = (localVal & ((uint32_t)0x00000002)) >>  1;
	*ntt_cmmn_atl_mode = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t natt_ntt_mode_ntt_abort_if_no_fit_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void natt_ntt_mode_ntt_abort_if_no_fit_setf(uint8_t nttabortifnofit)
{
	ASSERT_ERR((((uint32_t)nttabortifnofit << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(NATT_NTT_MODE_ADDR, (REG_PL_RD(NATT_NTT_MODE_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)nttabortifnofit <<6));
}
__INLINE uint8_t natt_ntt_mode_ntt_rst_desc_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void natt_ntt_mode_ntt_rst_desc_base_setf(uint8_t nttrstdescbase)
{
	ASSERT_ERR((((uint32_t)nttrstdescbase << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(NATT_NTT_MODE_ADDR, (REG_PL_RD(NATT_NTT_MODE_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)nttrstdescbase <<5));
}
__INLINE uint8_t natt_ntt_mode_disable_ntt_mac_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void natt_ntt_mode_disable_ntt_mac_done_setf(uint8_t disablenttmacdone)
{
	ASSERT_ERR((((uint32_t)disablenttmacdone << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(NATT_NTT_MODE_ADDR, (REG_PL_RD(NATT_NTT_MODE_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)disablenttmacdone <<4));
}
__INLINE uint8_t natt_ntt_mode_include_se_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void natt_ntt_mode_include_se_setf(uint8_t includese)
{
	ASSERT_ERR((((uint32_t)includese << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(NATT_NTT_MODE_ADDR, (REG_PL_RD(NATT_NTT_MODE_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)includese <<3));
}
__INLINE uint8_t natt_ntt_mode_skip_txd_write_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t natt_ntt_mode_ntt_fast_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t natt_ntt_mode_ntt_cmmn_atl_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief NTT_STR_0_NON_DATA_INFO_1 register definition
 *  Number length and padding of nonDATA MPDUs register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17:16 NTT_NON_DATA1_PAD         0x0
 *    15:12 NTT_NON_DATA1_NUM         0x0
 *    09:00 NTT_NON_DATA1_LEN         0x0
 * </pre>
 */
#define NATT_NTT_STR_0_NON_DATA_INFO_1_ADDR        (REG_NATT_BASE_ADDR+0x00000060)
#define NATT_NTT_STR_0_NON_DATA_INFO_1_OFFSET      0x00000060
#define NATT_NTT_STR_0_NON_DATA_INFO_1_INDEX       0x00000018
#define NATT_NTT_STR_0_NON_DATA_INFO_1_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_non_data_info_1_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_NON_DATA_INFO_1_ADDR);
}

__INLINE void natt_ntt_str_0_non_data_info_1_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_0_NON_DATA_INFO_1_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_0_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_MASK    ((uint32_t)0x00030000)
#define NATT_NTT_STR_0_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_LSB    16
#define NATT_NTT_STR_0_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_WIDTH    ((uint32_t)0x00000002)
#define NATT_NTT_STR_0_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_MASK    ((uint32_t)0x0000F000)
#define NATT_NTT_STR_0_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_LSB    12
#define NATT_NTT_STR_0_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_WIDTH    ((uint32_t)0x00000004)
#define NATT_NTT_STR_0_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_MASK    ((uint32_t)0x000003FF)
#define NATT_NTT_STR_0_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_LSB    0
#define NATT_NTT_STR_0_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_WIDTH    ((uint32_t)0x0000000A)

#define NATT_NTT_STR_0_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_RST    0x0
#define NATT_NTT_STR_0_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_RST    0x0
#define NATT_NTT_STR_0_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_RST    0x0

__INLINE void natt_ntt_str_0_non_data_info_1_pack(uint8_t ntt_non_data1_pad, uint8_t ntt_non_data1_num, uint16_t ntt_non_data1_len)
{
	ASSERT_ERR((((uint32_t)ntt_non_data1_pad << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data1_num << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data1_len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_NON_DATA_INFO_1_ADDR,  ((uint32_t)ntt_non_data1_pad << 16) |((uint32_t)ntt_non_data1_num << 12) |((uint32_t)ntt_non_data1_len << 0));
}

__INLINE void natt_ntt_str_0_non_data_info_1_unpack(uint8_t* ntt_non_data1_pad, uint8_t* ntt_non_data1_num, uint16_t* ntt_non_data1_len)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_NON_DATA_INFO_1_ADDR);

	*ntt_non_data1_pad = (localVal & ((uint32_t)0x00030000)) >>  16;
	*ntt_non_data1_num = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*ntt_non_data1_len = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint8_t natt_ntt_str_0_non_data_info_1_ntt_non_data_1_pad_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_NON_DATA_INFO_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void natt_ntt_str_0_non_data_info_1_ntt_non_data_1_pad_setf(uint8_t nttnondata1pad)
{
	ASSERT_ERR((((uint32_t)nttnondata1pad << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_NON_DATA_INFO_1_ADDR, (REG_PL_RD(NATT_NTT_STR_0_NON_DATA_INFO_1_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)nttnondata1pad <<16));
}
__INLINE uint8_t natt_ntt_str_0_non_data_info_1_ntt_non_data_1_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_NON_DATA_INFO_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void natt_ntt_str_0_non_data_info_1_ntt_non_data_1_num_setf(uint8_t nttnondata1num)
{
	ASSERT_ERR((((uint32_t)nttnondata1num << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_NON_DATA_INFO_1_ADDR, (REG_PL_RD(NATT_NTT_STR_0_NON_DATA_INFO_1_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)nttnondata1num <<12));
}
__INLINE uint16_t natt_ntt_str_0_non_data_info_1_ntt_non_data_1_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_NON_DATA_INFO_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void natt_ntt_str_0_non_data_info_1_ntt_non_data_1_len_setf(uint16_t nttnondata1len)
{
	ASSERT_ERR((((uint32_t)nttnondata1len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_NON_DATA_INFO_1_ADDR, (REG_PL_RD(NATT_NTT_STR_0_NON_DATA_INFO_1_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)nttnondata1len <<0));
}

/**
 * @brief NTT_STR_0_NON_DATA_INFO_2 register definition
 *  Number length and padding of nonDATA MPDUs register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17:16 NTT_NON_DATA2_PAD         0x0
 *    15:12 NTT_NON_DATA2_NUM         0x0
 *    09:00 NTT_NON_DATA2_LEN         0x0
 * </pre>
 */
#define NATT_NTT_STR_0_NON_DATA_INFO_2_ADDR        (REG_NATT_BASE_ADDR+0x00000064)
#define NATT_NTT_STR_0_NON_DATA_INFO_2_OFFSET      0x00000064
#define NATT_NTT_STR_0_NON_DATA_INFO_2_INDEX       0x00000019
#define NATT_NTT_STR_0_NON_DATA_INFO_2_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_non_data_info_2_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_NON_DATA_INFO_2_ADDR);
}

__INLINE void natt_ntt_str_0_non_data_info_2_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_0_NON_DATA_INFO_2_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_0_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_MASK    ((uint32_t)0x00030000)
#define NATT_NTT_STR_0_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_LSB    16
#define NATT_NTT_STR_0_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_WIDTH    ((uint32_t)0x00000002)
#define NATT_NTT_STR_0_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_MASK    ((uint32_t)0x0000F000)
#define NATT_NTT_STR_0_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_LSB    12
#define NATT_NTT_STR_0_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_WIDTH    ((uint32_t)0x00000004)
#define NATT_NTT_STR_0_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_MASK    ((uint32_t)0x000003FF)
#define NATT_NTT_STR_0_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_LSB    0
#define NATT_NTT_STR_0_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_WIDTH    ((uint32_t)0x0000000A)

#define NATT_NTT_STR_0_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_RST    0x0
#define NATT_NTT_STR_0_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_RST    0x0
#define NATT_NTT_STR_0_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_RST    0x0

__INLINE void natt_ntt_str_0_non_data_info_2_pack(uint8_t ntt_non_data2_pad, uint8_t ntt_non_data2_num, uint16_t ntt_non_data2_len)
{
	ASSERT_ERR((((uint32_t)ntt_non_data2_pad << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data2_num << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data2_len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_NON_DATA_INFO_2_ADDR,  ((uint32_t)ntt_non_data2_pad << 16) |((uint32_t)ntt_non_data2_num << 12) |((uint32_t)ntt_non_data2_len << 0));
}

__INLINE void natt_ntt_str_0_non_data_info_2_unpack(uint8_t* ntt_non_data2_pad, uint8_t* ntt_non_data2_num, uint16_t* ntt_non_data2_len)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_NON_DATA_INFO_2_ADDR);

	*ntt_non_data2_pad = (localVal & ((uint32_t)0x00030000)) >>  16;
	*ntt_non_data2_num = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*ntt_non_data2_len = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint8_t natt_ntt_str_0_non_data_info_2_ntt_non_data_2_pad_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_NON_DATA_INFO_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void natt_ntt_str_0_non_data_info_2_ntt_non_data_2_pad_setf(uint8_t nttnondata2pad)
{
	ASSERT_ERR((((uint32_t)nttnondata2pad << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_NON_DATA_INFO_2_ADDR, (REG_PL_RD(NATT_NTT_STR_0_NON_DATA_INFO_2_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)nttnondata2pad <<16));
}
__INLINE uint8_t natt_ntt_str_0_non_data_info_2_ntt_non_data_2_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_NON_DATA_INFO_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void natt_ntt_str_0_non_data_info_2_ntt_non_data_2_num_setf(uint8_t nttnondata2num)
{
	ASSERT_ERR((((uint32_t)nttnondata2num << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_NON_DATA_INFO_2_ADDR, (REG_PL_RD(NATT_NTT_STR_0_NON_DATA_INFO_2_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)nttnondata2num <<12));
}
__INLINE uint16_t natt_ntt_str_0_non_data_info_2_ntt_non_data_2_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_NON_DATA_INFO_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void natt_ntt_str_0_non_data_info_2_ntt_non_data_2_len_setf(uint16_t nttnondata2len)
{
	ASSERT_ERR((((uint32_t)nttnondata2len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_NON_DATA_INFO_2_ADDR, (REG_PL_RD(NATT_NTT_STR_0_NON_DATA_INFO_2_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)nttnondata2len <<0));
}

/**
 * @brief NTT_STR_0_NON_DATA_1_RESULT register definition
 *  ZLDs and padding_in_bytes results for nonData register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 NTT_NON_DATA1_PADDING_IN_BYTES 0x0
 *    15:00 NTT_NON_DATA1_ZLD         0x0
 * </pre>
 */
#define NATT_NTT_STR_0_NON_DATA_1_RESULT_ADDR        (REG_NATT_BASE_ADDR+0x00000068)
#define NATT_NTT_STR_0_NON_DATA_1_RESULT_OFFSET      0x00000068
#define NATT_NTT_STR_0_NON_DATA_1_RESULT_INDEX       0x0000001A
#define NATT_NTT_STR_0_NON_DATA_1_RESULT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_non_data_1_result_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_NON_DATA_1_RESULT_ADDR);
}

// field definitions
#define NATT_NTT_STR_0_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_MASK    ((uint32_t)0xFFFF0000)
#define NATT_NTT_STR_0_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_LSB    16
#define NATT_NTT_STR_0_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_WIDTH    ((uint32_t)0x00000010)
#define NATT_NTT_STR_0_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_0_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_LSB    0
#define NATT_NTT_STR_0_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_0_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_RST    0x0
#define NATT_NTT_STR_0_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_RST    0x0

__INLINE void natt_ntt_str_0_non_data_1_result_unpack(uint16_t* ntt_non_data1_padding_in_bytes, uint16_t* ntt_non_data1_zld)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_NON_DATA_1_RESULT_ADDR);

	*ntt_non_data1_padding_in_bytes = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ntt_non_data1_zld = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t natt_ntt_str_0_non_data_1_result_ntt_non_data_1_padding_in_bytes_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_NON_DATA_1_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t natt_ntt_str_0_non_data_1_result_ntt_non_data_1_zld_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_NON_DATA_1_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief NTT_STR_0_NON_DATA_2_RESULT register definition
 *  ZLDs and padding_in_bytes results for nonData register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 NTT_NON_DATA2_PADDING_IN_BYTES 0x0
 *    15:00 TT_NON_DATA2_ZLD          0x0
 * </pre>
 */
#define NATT_NTT_STR_0_NON_DATA_2_RESULT_ADDR        (REG_NATT_BASE_ADDR+0x0000006C)
#define NATT_NTT_STR_0_NON_DATA_2_RESULT_OFFSET      0x0000006C
#define NATT_NTT_STR_0_NON_DATA_2_RESULT_INDEX       0x0000001B
#define NATT_NTT_STR_0_NON_DATA_2_RESULT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_non_data_2_result_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_NON_DATA_2_RESULT_ADDR);
}

// field definitions
#define NATT_NTT_STR_0_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_MASK    ((uint32_t)0xFFFF0000)
#define NATT_NTT_STR_0_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_LSB    16
#define NATT_NTT_STR_0_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_WIDTH    ((uint32_t)0x00000010)
#define NATT_NTT_STR_0_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_0_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_LSB    0
#define NATT_NTT_STR_0_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_0_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_RST    0x0
#define NATT_NTT_STR_0_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_RST    0x0

__INLINE void natt_ntt_str_0_non_data_2_result_unpack(uint16_t* ntt_non_data2_padding_in_bytes, uint16_t* tt_non_data2_zld)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_NON_DATA_2_RESULT_ADDR);

	*ntt_non_data2_padding_in_bytes = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*tt_non_data2_zld = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t natt_ntt_str_0_non_data_2_result_ntt_non_data_2_padding_in_bytes_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_NON_DATA_2_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t natt_ntt_str_0_non_data_2_result_tt_non_data_2_zld_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_NON_DATA_2_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief NTT_STR_0_MIN_SPACING_CONF register definition
 *  Min_spacing parameters for STA capabilities register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    FORCE_MIN_SPACING         0              
 *    07:04 MIN_SPACING_FACTOR        0x0
 *    03:00 MIN_SPACING               0x0
 * </pre>
 */
#define NATT_NTT_STR_0_MIN_SPACING_CONF_ADDR        (REG_NATT_BASE_ADDR+0x00000070)
#define NATT_NTT_STR_0_MIN_SPACING_CONF_OFFSET      0x00000070
#define NATT_NTT_STR_0_MIN_SPACING_CONF_INDEX       0x0000001C
#define NATT_NTT_STR_0_MIN_SPACING_CONF_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_min_spacing_conf_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_MIN_SPACING_CONF_ADDR);
}

__INLINE void natt_ntt_str_0_min_spacing_conf_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_0_MIN_SPACING_CONF_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_0_MIN_SPACING_CONF_FORCE_MIN_SPACING_BIT    ((uint32_t)0x80000000)
#define NATT_NTT_STR_0_MIN_SPACING_CONF_FORCE_MIN_SPACING_POS    31
#define NATT_NTT_STR_0_MIN_SPACING_CONF_MIN_SPACING_FACTOR_MASK    ((uint32_t)0x000000F0)
#define NATT_NTT_STR_0_MIN_SPACING_CONF_MIN_SPACING_FACTOR_LSB    4
#define NATT_NTT_STR_0_MIN_SPACING_CONF_MIN_SPACING_FACTOR_WIDTH    ((uint32_t)0x00000004)
#define NATT_NTT_STR_0_MIN_SPACING_CONF_MIN_SPACING_MASK    ((uint32_t)0x0000000F)
#define NATT_NTT_STR_0_MIN_SPACING_CONF_MIN_SPACING_LSB    0
#define NATT_NTT_STR_0_MIN_SPACING_CONF_MIN_SPACING_WIDTH    ((uint32_t)0x00000004)

#define NATT_NTT_STR_0_MIN_SPACING_CONF_FORCE_MIN_SPACING_RST    0x0
#define NATT_NTT_STR_0_MIN_SPACING_CONF_MIN_SPACING_FACTOR_RST    0x0
#define NATT_NTT_STR_0_MIN_SPACING_CONF_MIN_SPACING_RST    0x0

__INLINE void natt_ntt_str_0_min_spacing_conf_pack(uint8_t force_min_spacing, uint8_t min_spacing_factor, uint8_t min_spacing)
{
	ASSERT_ERR((((uint32_t)force_min_spacing << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)min_spacing_factor << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)min_spacing << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_MIN_SPACING_CONF_ADDR,  ((uint32_t)force_min_spacing << 31) |((uint32_t)min_spacing_factor << 4) |((uint32_t)min_spacing << 0));
}

__INLINE void natt_ntt_str_0_min_spacing_conf_unpack(uint8_t* force_min_spacing, uint8_t* min_spacing_factor, uint8_t* min_spacing)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_MIN_SPACING_CONF_ADDR);

	*force_min_spacing = (localVal & ((uint32_t)0x80000000)) >>  31;
	*min_spacing_factor = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*min_spacing = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t natt_ntt_str_0_min_spacing_conf_force_min_spacing_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_MIN_SPACING_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void natt_ntt_str_0_min_spacing_conf_force_min_spacing_setf(uint8_t forceminspacing)
{
	ASSERT_ERR((((uint32_t)forceminspacing << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_MIN_SPACING_CONF_ADDR, (REG_PL_RD(NATT_NTT_STR_0_MIN_SPACING_CONF_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)forceminspacing <<31));
}
__INLINE uint8_t natt_ntt_str_0_min_spacing_conf_min_spacing_factor_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_MIN_SPACING_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void natt_ntt_str_0_min_spacing_conf_min_spacing_factor_setf(uint8_t minspacingfactor)
{
	ASSERT_ERR((((uint32_t)minspacingfactor << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_MIN_SPACING_CONF_ADDR, (REG_PL_RD(NATT_NTT_STR_0_MIN_SPACING_CONF_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)minspacingfactor <<4));
}
__INLINE uint8_t natt_ntt_str_0_min_spacing_conf_min_spacing_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_MIN_SPACING_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void natt_ntt_str_0_min_spacing_conf_min_spacing_setf(uint8_t minspacing)
{
	ASSERT_ERR((((uint32_t)minspacing << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_MIN_SPACING_CONF_ADDR, (REG_PL_RD(NATT_NTT_STR_0_MIN_SPACING_CONF_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)minspacing <<0));
}

/**
 * @brief NTT_STR_0_DBG_CNT register definition
 *  Debug commands counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DBG_CNT               0x0
 * </pre>
 */
#define NATT_NTT_STR_0_DBG_CNT_ADDR        (REG_NATT_BASE_ADDR+0x00000074)
#define NATT_NTT_STR_0_DBG_CNT_OFFSET      0x00000074
#define NATT_NTT_STR_0_DBG_CNT_INDEX       0x0000001D
#define NATT_NTT_STR_0_DBG_CNT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_dbg_cnt_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_DBG_CNT_ADDR);
}

__INLINE void natt_ntt_str_0_dbg_cnt_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_0_DBG_CNT_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_0_DBG_CNT_NTT_DBG_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_0_DBG_CNT_NTT_DBG_CNT_LSB    0
#define NATT_NTT_STR_0_DBG_CNT_NTT_DBG_CNT_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_0_DBG_CNT_NTT_DBG_CNT_RST    0x0

__INLINE uint32_t natt_ntt_str_0_dbg_cnt_ntt_dbg_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_DBG_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_0_dbg_cnt_ntt_dbg_cnt_setf(uint32_t nttdbgcnt)
{
	ASSERT_ERR((((uint32_t)nttdbgcnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_0_DBG_CNT_ADDR, (uint32_t)nttdbgcnt << 0);
}

/**
 * @brief NTT_STR_0_PHY_RATE register definition
 *  Debug results of last packet (ndps+rate) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 NTT_PHY_RATE              0x0
 * </pre>
 */
#define NATT_NTT_STR_0_PHY_RATE_ADDR        (REG_NATT_BASE_ADDR+0x00000078)
#define NATT_NTT_STR_0_PHY_RATE_OFFSET      0x00000078
#define NATT_NTT_STR_0_PHY_RATE_INDEX       0x0000001E
#define NATT_NTT_STR_0_PHY_RATE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_phy_rate_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_PHY_RATE_ADDR);
}

// field definitions
#define NATT_NTT_STR_0_PHY_RATE_NTT_PHY_RATE_MASK    ((uint32_t)0x000FFFFF)
#define NATT_NTT_STR_0_PHY_RATE_NTT_PHY_RATE_LSB    0
#define NATT_NTT_STR_0_PHY_RATE_NTT_PHY_RATE_WIDTH    ((uint32_t)0x00000014)

#define NATT_NTT_STR_0_PHY_RATE_NTT_PHY_RATE_RST    0x0

__INLINE uint32_t natt_ntt_str_0_phy_rate_ntt_phy_rate_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_PHY_RATE_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_0_NDBPS register definition
 *  Number of data bits per symbol register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 NTT_NDBPS                 0x0
 * </pre>
 */
#define NATT_NTT_STR_0_NDBPS_ADDR        (REG_NATT_BASE_ADDR+0x0000007C)
#define NATT_NTT_STR_0_NDBPS_OFFSET      0x0000007C
#define NATT_NTT_STR_0_NDBPS_INDEX       0x0000001F
#define NATT_NTT_STR_0_NDBPS_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_ndbps_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_NDBPS_ADDR);
}

// field definitions
#define NATT_NTT_STR_0_NDBPS_NTT_NDBPS_MASK    ((uint32_t)0x000FFFFF)
#define NATT_NTT_STR_0_NDBPS_NTT_NDBPS_LSB    0
#define NATT_NTT_STR_0_NDBPS_NTT_NDBPS_WIDTH    ((uint32_t)0x00000014)

#define NATT_NTT_STR_0_NDBPS_NTT_NDBPS_RST    0x0

__INLINE uint32_t natt_ntt_str_0_ndbps_ntt_ndbps_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_NDBPS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_0_SYM_TIME register definition
 *  Debug results of last packet (symbols+datatime) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 NTT_SYMBOLS               0x0
 *    15:00 NTT_DAT_TIME              0x0
 * </pre>
 */
#define NATT_NTT_STR_0_SYM_TIME_ADDR        (REG_NATT_BASE_ADDR+0x00000080)
#define NATT_NTT_STR_0_SYM_TIME_OFFSET      0x00000080
#define NATT_NTT_STR_0_SYM_TIME_INDEX       0x00000020
#define NATT_NTT_STR_0_SYM_TIME_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_sym_time_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_SYM_TIME_ADDR);
}

// field definitions
#define NATT_NTT_STR_0_SYM_TIME_NTT_SYMBOLS_MASK    ((uint32_t)0xFFFF0000)
#define NATT_NTT_STR_0_SYM_TIME_NTT_SYMBOLS_LSB    16
#define NATT_NTT_STR_0_SYM_TIME_NTT_SYMBOLS_WIDTH    ((uint32_t)0x00000010)
#define NATT_NTT_STR_0_SYM_TIME_NTT_DAT_TIME_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_0_SYM_TIME_NTT_DAT_TIME_LSB    0
#define NATT_NTT_STR_0_SYM_TIME_NTT_DAT_TIME_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_0_SYM_TIME_NTT_SYMBOLS_RST    0x0
#define NATT_NTT_STR_0_SYM_TIME_NTT_DAT_TIME_RST    0x0

__INLINE void natt_ntt_str_0_sym_time_unpack(uint16_t* ntt_symbols, uint16_t* ntt_dat_time)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_SYM_TIME_ADDR);

	*ntt_symbols = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ntt_dat_time = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t natt_ntt_str_0_sym_time_ntt_symbols_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_SYM_TIME_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t natt_ntt_str_0_sym_time_ntt_dat_time_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_SYM_TIME_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief NTT_STR_0_TOT_TIME register definition
 *  Debug results of last packet (total time) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 NTT_TOT_TIME              0x0
 * </pre>
 */
#define NATT_NTT_STR_0_TOT_TIME_ADDR        (REG_NATT_BASE_ADDR+0x00000084)
#define NATT_NTT_STR_0_TOT_TIME_OFFSET      0x00000084
#define NATT_NTT_STR_0_TOT_TIME_INDEX       0x00000021
#define NATT_NTT_STR_0_TOT_TIME_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_tot_time_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_TOT_TIME_ADDR);
}

// field definitions
#define NATT_NTT_STR_0_TOT_TIME_NTT_TOT_TIME_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_0_TOT_TIME_NTT_TOT_TIME_LSB    0
#define NATT_NTT_STR_0_TOT_TIME_NTT_TOT_TIME_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_0_TOT_TIME_NTT_TOT_TIME_RST    0x0

__INLINE uint16_t natt_ntt_str_0_tot_time_ntt_tot_time_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_TOT_TIME_ADDR);
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_0_MPDU_NUM register definition
 *  Debug results of last packet (number of MPDUs) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    08:00 NTT_MPDU_NUM              0x0
 * </pre>
 */
#define NATT_NTT_STR_0_MPDU_NUM_ADDR        (REG_NATT_BASE_ADDR+0x00000088)
#define NATT_NTT_STR_0_MPDU_NUM_OFFSET      0x00000088
#define NATT_NTT_STR_0_MPDU_NUM_INDEX       0x00000022
#define NATT_NTT_STR_0_MPDU_NUM_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_mpdu_num_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_MPDU_NUM_ADDR);
}

// field definitions
#define NATT_NTT_STR_0_MPDU_NUM_NTT_MPDU_NUM_MASK    ((uint32_t)0x000001FF)
#define NATT_NTT_STR_0_MPDU_NUM_NTT_MPDU_NUM_LSB    0
#define NATT_NTT_STR_0_MPDU_NUM_NTT_MPDU_NUM_WIDTH    ((uint32_t)0x00000009)

#define NATT_NTT_STR_0_MPDU_NUM_NTT_MPDU_NUM_RST    0x0

__INLINE uint16_t natt_ntt_str_0_mpdu_num_ntt_mpdu_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_MPDU_NUM_ADDR);
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_0_AMPDU_LEN register definition
 *  AMPDU actual length in bytes register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:00 NTT_AMPDU_LEN             0x0
 * </pre>
 */
#define NATT_NTT_STR_0_AMPDU_LEN_ADDR        (REG_NATT_BASE_ADDR+0x0000008C)
#define NATT_NTT_STR_0_AMPDU_LEN_OFFSET      0x0000008C
#define NATT_NTT_STR_0_AMPDU_LEN_INDEX       0x00000023
#define NATT_NTT_STR_0_AMPDU_LEN_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_ampdu_len_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_AMPDU_LEN_ADDR);
}

// field definitions
#define NATT_NTT_STR_0_AMPDU_LEN_NTT_AMPDU_LEN_MASK    ((uint32_t)0x00FFFFFF)
#define NATT_NTT_STR_0_AMPDU_LEN_NTT_AMPDU_LEN_LSB    0
#define NATT_NTT_STR_0_AMPDU_LEN_NTT_AMPDU_LEN_WIDTH    ((uint32_t)0x00000018)

#define NATT_NTT_STR_0_AMPDU_LEN_NTT_AMPDU_LEN_RST    0x0

__INLINE uint32_t natt_ntt_str_0_ampdu_len_ntt_ampdu_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_AMPDU_LEN_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_0_MAX_AMPDU_LEN register definition
 *  MAX AMPDU Length in bytes register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:00 NTT_MAX_AMPDU_LEN         0x0
 * </pre>
 */
#define NATT_NTT_STR_0_MAX_AMPDU_LEN_ADDR        (REG_NATT_BASE_ADDR+0x00000090)
#define NATT_NTT_STR_0_MAX_AMPDU_LEN_OFFSET      0x00000090
#define NATT_NTT_STR_0_MAX_AMPDU_LEN_INDEX       0x00000024
#define NATT_NTT_STR_0_MAX_AMPDU_LEN_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_0_max_ampdu_len_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_0_MAX_AMPDU_LEN_ADDR);
}

// field definitions
#define NATT_NTT_STR_0_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_MASK    ((uint32_t)0x00FFFFFF)
#define NATT_NTT_STR_0_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_LSB    0
#define NATT_NTT_STR_0_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_WIDTH    ((uint32_t)0x00000018)

#define NATT_NTT_STR_0_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_RST    0x0

__INLINE uint32_t natt_ntt_str_0_max_ampdu_len_ntt_max_ampdu_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_0_MAX_AMPDU_LEN_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_STATUS register definition
 *  Indicates block is in a middle of operation register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    NTT_HALTED                0              
 *    00    NTT_BUSY                  0              
 * </pre>
 */
#define NATT_NTT_STATUS_ADDR        (REG_NATT_BASE_ADDR+0x00000094)
#define NATT_NTT_STATUS_OFFSET      0x00000094
#define NATT_NTT_STATUS_INDEX       0x00000025
#define NATT_NTT_STATUS_RESET       0x00000000

__INLINE uint32_t  natt_ntt_status_get(void)
{
	return REG_PL_RD(NATT_NTT_STATUS_ADDR);
}

// field definitions
#define NATT_NTT_STATUS_NTT_HALTED_BIT      ((uint32_t)0x00000002)
#define NATT_NTT_STATUS_NTT_HALTED_POS      1
#define NATT_NTT_STATUS_NTT_BUSY_BIT        ((uint32_t)0x00000001)
#define NATT_NTT_STATUS_NTT_BUSY_POS        0

#define NATT_NTT_STATUS_NTT_HALTED_RST      0x0
#define NATT_NTT_STATUS_NTT_BUSY_RST        0x0

__INLINE void natt_ntt_status_unpack(uint8_t* ntt_halted, uint8_t* ntt_busy)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STATUS_ADDR);

	*ntt_halted = (localVal & ((uint32_t)0x00000002)) >>  1;
	*ntt_busy = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t natt_ntt_status_ntt_halted_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t natt_ntt_status_ntt_busy_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief NTT_DEBUG register definition
 *  Debug information register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DEBUG                 0x11C000
 * </pre>
 */
#define NATT_NTT_DEBUG_ADDR        (REG_NATT_BASE_ADDR+0x00000098)
#define NATT_NTT_DEBUG_OFFSET      0x00000098
#define NATT_NTT_DEBUG_INDEX       0x00000026
#define NATT_NTT_DEBUG_RESET       0x0011C000

__INLINE uint32_t  natt_ntt_debug_get(void)
{
	return REG_PL_RD(NATT_NTT_DEBUG_ADDR);
}

// field definitions
#define NATT_NTT_DEBUG_NTT_DEBUG_MASK       ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_DEBUG_NTT_DEBUG_LSB        0
#define NATT_NTT_DEBUG_NTT_DEBUG_WIDTH      ((uint32_t)0x00000020)

#define NATT_NTT_DEBUG_NTT_DEBUG_RST        0x11C000

__INLINE uint32_t natt_ntt_debug_ntt_debug_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_DEBUG_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_RST register definition
 *  NATT SW Reset register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    NTT_RST                   0              
 * </pre>
 */
#define NATT_NTT_RST_ADDR        (REG_NATT_BASE_ADDR+0x0000009C)
#define NATT_NTT_RST_OFFSET      0x0000009C
#define NATT_NTT_RST_INDEX       0x00000027
#define NATT_NTT_RST_RESET       0x00000000

__INLINE void natt_ntt_rst_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_RST_ADDR, value);
}

// field definitions
#define NATT_NTT_RST_NTT_RST_BIT            ((uint32_t)0x00000001)
#define NATT_NTT_RST_NTT_RST_POS            0

#define NATT_NTT_RST_NTT_RST_RST            0x0

__INLINE void natt_ntt_rst_ntt_rst_setf(uint8_t nttrst)
{
	ASSERT_ERR((((uint32_t)nttrst << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(NATT_NTT_RST_ADDR, (uint32_t)nttrst << 0);
}

/**
 * @brief NTT_HE_TRIG_CONFIG register definition
 *  HETRIGB Configuration Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07    PE_disambiguity           0              
 *    06    Fec_coding_type           0              
 *    05:04 Pre_fec_padding_factor    0x0
 *    03    Ldpc_extra_symbol         0              
 *    02:00 Num_ltf_symbols           0x0
 * </pre>
 */
#define NATT_NTT_HE_TRIG_CONFIG_ADDR        (REG_NATT_BASE_ADDR+0x000000A0)
#define NATT_NTT_HE_TRIG_CONFIG_OFFSET      0x000000A0
#define NATT_NTT_HE_TRIG_CONFIG_INDEX       0x00000028
#define NATT_NTT_HE_TRIG_CONFIG_RESET       0x00000000

__INLINE uint32_t  natt_ntt_he_trig_config_get(void)
{
	return REG_PL_RD(NATT_NTT_HE_TRIG_CONFIG_ADDR);
}

__INLINE void natt_ntt_he_trig_config_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_HE_TRIG_CONFIG_ADDR, value);
}

// field definitions
#define NATT_NTT_HE_TRIG_CONFIG_PE_DISAMBIGUITY_BIT    ((uint32_t)0x00000080)
#define NATT_NTT_HE_TRIG_CONFIG_PE_DISAMBIGUITY_POS    7
#define NATT_NTT_HE_TRIG_CONFIG_FEC_CODING_TYPE_BIT    ((uint32_t)0x00000040)
#define NATT_NTT_HE_TRIG_CONFIG_FEC_CODING_TYPE_POS    6
#define NATT_NTT_HE_TRIG_CONFIG_PRE_FEC_PADDING_FACTOR_MASK    ((uint32_t)0x00000030)
#define NATT_NTT_HE_TRIG_CONFIG_PRE_FEC_PADDING_FACTOR_LSB    4
#define NATT_NTT_HE_TRIG_CONFIG_PRE_FEC_PADDING_FACTOR_WIDTH    ((uint32_t)0x00000002)
#define NATT_NTT_HE_TRIG_CONFIG_LDPC_EXTRA_SYMBOL_BIT    ((uint32_t)0x00000008)
#define NATT_NTT_HE_TRIG_CONFIG_LDPC_EXTRA_SYMBOL_POS    3
#define NATT_NTT_HE_TRIG_CONFIG_NUM_LTF_SYMBOLS_MASK    ((uint32_t)0x00000007)
#define NATT_NTT_HE_TRIG_CONFIG_NUM_LTF_SYMBOLS_LSB    0
#define NATT_NTT_HE_TRIG_CONFIG_NUM_LTF_SYMBOLS_WIDTH    ((uint32_t)0x00000003)

#define NATT_NTT_HE_TRIG_CONFIG_PE_DISAMBIGUITY_RST    0x0
#define NATT_NTT_HE_TRIG_CONFIG_FEC_CODING_TYPE_RST    0x0
#define NATT_NTT_HE_TRIG_CONFIG_PRE_FEC_PADDING_FACTOR_RST    0x0
#define NATT_NTT_HE_TRIG_CONFIG_LDPC_EXTRA_SYMBOL_RST    0x0
#define NATT_NTT_HE_TRIG_CONFIG_NUM_LTF_SYMBOLS_RST    0x0

__INLINE void natt_ntt_he_trig_config_pack(uint8_t pe_disambiguity, uint8_t fec_coding_type, uint8_t pre_fec_padding_factor, uint8_t ldpc_extra_symbol, uint8_t num_ltf_symbols)
{
	ASSERT_ERR((((uint32_t)pe_disambiguity << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)fec_coding_type << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)pre_fec_padding_factor << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)ldpc_extra_symbol << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)num_ltf_symbols << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(NATT_NTT_HE_TRIG_CONFIG_ADDR,  ((uint32_t)pe_disambiguity << 7) |((uint32_t)fec_coding_type << 6) |((uint32_t)pre_fec_padding_factor << 4) |((uint32_t)ldpc_extra_symbol << 3) |((uint32_t)num_ltf_symbols << 0));
}

__INLINE void natt_ntt_he_trig_config_unpack(uint8_t* pe_disambiguity, uint8_t* fec_coding_type, uint8_t* pre_fec_padding_factor, uint8_t* ldpc_extra_symbol, uint8_t* num_ltf_symbols)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HE_TRIG_CONFIG_ADDR);

	*pe_disambiguity = (localVal & ((uint32_t)0x00000080)) >>  7;
	*fec_coding_type = (localVal & ((uint32_t)0x00000040)) >>  6;
	*pre_fec_padding_factor = (localVal & ((uint32_t)0x00000030)) >>  4;
	*ldpc_extra_symbol = (localVal & ((uint32_t)0x00000008)) >>  3;
	*num_ltf_symbols = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t natt_ntt_he_trig_config_pe_disambiguity_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HE_TRIG_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void natt_ntt_he_trig_config_pe_disambiguity_setf(uint8_t pedisambiguity)
{
	ASSERT_ERR((((uint32_t)pedisambiguity << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(NATT_NTT_HE_TRIG_CONFIG_ADDR, (REG_PL_RD(NATT_NTT_HE_TRIG_CONFIG_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)pedisambiguity <<7));
}
__INLINE uint8_t natt_ntt_he_trig_config_fec_coding_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HE_TRIG_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void natt_ntt_he_trig_config_fec_coding_type_setf(uint8_t feccodingtype)
{
	ASSERT_ERR((((uint32_t)feccodingtype << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(NATT_NTT_HE_TRIG_CONFIG_ADDR, (REG_PL_RD(NATT_NTT_HE_TRIG_CONFIG_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)feccodingtype <<6));
}
__INLINE uint8_t natt_ntt_he_trig_config_pre_fec_padding_factor_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HE_TRIG_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void natt_ntt_he_trig_config_pre_fec_padding_factor_setf(uint8_t prefecpaddingfactor)
{
	ASSERT_ERR((((uint32_t)prefecpaddingfactor << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(NATT_NTT_HE_TRIG_CONFIG_ADDR, (REG_PL_RD(NATT_NTT_HE_TRIG_CONFIG_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)prefecpaddingfactor <<4));
}
__INLINE uint8_t natt_ntt_he_trig_config_ldpc_extra_symbol_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HE_TRIG_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void natt_ntt_he_trig_config_ldpc_extra_symbol_setf(uint8_t ldpcextrasymbol)
{
	ASSERT_ERR((((uint32_t)ldpcextrasymbol << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(NATT_NTT_HE_TRIG_CONFIG_ADDR, (REG_PL_RD(NATT_NTT_HE_TRIG_CONFIG_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)ldpcextrasymbol <<3));
}
__INLINE uint8_t natt_ntt_he_trig_config_num_ltf_symbols_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HE_TRIG_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void natt_ntt_he_trig_config_num_ltf_symbols_setf(uint8_t numltfsymbols)
{
	ASSERT_ERR((((uint32_t)numltfsymbols << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(NATT_NTT_HE_TRIG_CONFIG_ADDR, (REG_PL_RD(NATT_NTT_HE_TRIG_CONFIG_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)numltfsymbols <<0));
}

/**
 * @brief NTT_STR_1_PT_BASE register definition
 *  Policy Table register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_PT_BASE               0x0
 * </pre>
 */
#define NATT_NTT_STR_1_PT_BASE_ADDR        (REG_NATT_BASE_ADDR+0x0000010C)
#define NATT_NTT_STR_1_PT_BASE_OFFSET      0x0000010C
#define NATT_NTT_STR_1_PT_BASE_INDEX       0x00000043
#define NATT_NTT_STR_1_PT_BASE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_pt_base_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_PT_BASE_ADDR);
}

__INLINE void natt_ntt_str_1_pt_base_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_1_PT_BASE_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_1_PT_BASE_NTT_PT_BASE_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_1_PT_BASE_NTT_PT_BASE_LSB    0
#define NATT_NTT_STR_1_PT_BASE_NTT_PT_BASE_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_1_PT_BASE_NTT_PT_BASE_RST    0x0

__INLINE uint32_t natt_ntt_str_1_pt_base_ntt_pt_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_PT_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_1_pt_base_ntt_pt_base_setf(uint32_t nttptbase)
{
	ASSERT_ERR((((uint32_t)nttptbase << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_PT_BASE_ADDR, (uint32_t)nttptbase << 0);
}

/**
 * @brief NTT_STR_1_DESC_BASE register definition
 *  Descriptors chain base address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DESC_BASE             0x0
 * </pre>
 */
#define NATT_NTT_STR_1_DESC_BASE_ADDR        (REG_NATT_BASE_ADDR+0x00000110)
#define NATT_NTT_STR_1_DESC_BASE_OFFSET      0x00000110
#define NATT_NTT_STR_1_DESC_BASE_INDEX       0x00000044
#define NATT_NTT_STR_1_DESC_BASE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_desc_base_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_DESC_BASE_ADDR);
}

__INLINE void natt_ntt_str_1_desc_base_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_1_DESC_BASE_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_1_DESC_BASE_NTT_DESC_BASE_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_1_DESC_BASE_NTT_DESC_BASE_LSB    0
#define NATT_NTT_STR_1_DESC_BASE_NTT_DESC_BASE_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_1_DESC_BASE_NTT_DESC_BASE_RST    0x0

__INLINE uint32_t natt_ntt_str_1_desc_base_ntt_desc_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_DESC_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_1_desc_base_ntt_desc_base_setf(uint32_t nttdescbase)
{
	ASSERT_ERR((((uint32_t)nttdescbase << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_DESC_BASE_ADDR, (uint32_t)nttdescbase << 0);
}

/**
 * @brief NTT_STR_1_DESC_TSIZE register definition
 *  Total descriptors chain size register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DESC_TSIZE            0x0
 * </pre>
 */
#define NATT_NTT_STR_1_DESC_TSIZE_ADDR        (REG_NATT_BASE_ADDR+0x0000011C)
#define NATT_NTT_STR_1_DESC_TSIZE_OFFSET      0x0000011C
#define NATT_NTT_STR_1_DESC_TSIZE_INDEX       0x00000047
#define NATT_NTT_STR_1_DESC_TSIZE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_desc_tsize_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_DESC_TSIZE_ADDR);
}

__INLINE void natt_ntt_str_1_desc_tsize_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_1_DESC_TSIZE_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_1_DESC_TSIZE_NTT_DESC_TSIZE_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_1_DESC_TSIZE_NTT_DESC_TSIZE_LSB    0
#define NATT_NTT_STR_1_DESC_TSIZE_NTT_DESC_TSIZE_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_1_DESC_TSIZE_NTT_DESC_TSIZE_RST    0x0

__INLINE uint32_t natt_ntt_str_1_desc_tsize_ntt_desc_tsize_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_DESC_TSIZE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_1_desc_tsize_ntt_desc_tsize_setf(uint32_t nttdesctsize)
{
	ASSERT_ERR((((uint32_t)nttdesctsize << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_DESC_TSIZE_ADDR, (uint32_t)nttdesctsize << 0);
}

/**
 * @brief NTT_STR_1_DESC_START register definition
 *  Descriptors chain start address (1st MPDU) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DESC_START            0x0
 * </pre>
 */
#define NATT_NTT_STR_1_DESC_START_ADDR        (REG_NATT_BASE_ADDR+0x00000120)
#define NATT_NTT_STR_1_DESC_START_OFFSET      0x00000120
#define NATT_NTT_STR_1_DESC_START_INDEX       0x00000048
#define NATT_NTT_STR_1_DESC_START_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_desc_start_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_DESC_START_ADDR);
}

__INLINE void natt_ntt_str_1_desc_start_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_1_DESC_START_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_1_DESC_START_NTT_DESC_START_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_1_DESC_START_NTT_DESC_START_LSB    0
#define NATT_NTT_STR_1_DESC_START_NTT_DESC_START_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_1_DESC_START_NTT_DESC_START_RST    0x0

__INLINE uint32_t natt_ntt_str_1_desc_start_ntt_desc_start_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_DESC_START_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_1_desc_start_ntt_desc_start_setf(uint32_t nttdescstart)
{
	ASSERT_ERR((((uint32_t)nttdescstart << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_DESC_START_ADDR, (uint32_t)nttdescstart << 0);
}

/**
 * @brief NTT_STR_1_AIRTIME_LIMIT register definition
 *  AirTime Limit in usec register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 NTT_AIRTIME_LIMIT         0x0
 * </pre>
 */
#define NATT_NTT_STR_1_AIRTIME_LIMIT_ADDR        (REG_NATT_BASE_ADDR+0x00000124)
#define NATT_NTT_STR_1_AIRTIME_LIMIT_OFFSET      0x00000124
#define NATT_NTT_STR_1_AIRTIME_LIMIT_INDEX       0x00000049
#define NATT_NTT_STR_1_AIRTIME_LIMIT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_airtime_limit_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_AIRTIME_LIMIT_ADDR);
}

__INLINE void natt_ntt_str_1_airtime_limit_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_1_AIRTIME_LIMIT_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_1_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_1_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_LSB    0
#define NATT_NTT_STR_1_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_1_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_RST    0x0

__INLINE uint16_t natt_ntt_str_1_airtime_limit_ntt_airtime_limit_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_AIRTIME_LIMIT_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_1_airtime_limit_ntt_airtime_limit_setf(uint16_t nttairtimelimit)
{
	ASSERT_ERR((((uint32_t)nttairtimelimit << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_AIRTIME_LIMIT_ADDR, (uint32_t)nttairtimelimit << 0);
}

/**
 * @brief NTT_STR_1_MPDU_LIMIT register definition
 *  BA and valid MPDUs limit register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:24 NTT_STA_INDEX             0x0
 *    20:12 NTT_MAX_MPDU              0x0
 *    08:00 NTT_BA_WINDOW             0x0
 * </pre>
 */
#define NATT_NTT_STR_1_MPDU_LIMIT_ADDR        (REG_NATT_BASE_ADDR+0x00000128)
#define NATT_NTT_STR_1_MPDU_LIMIT_OFFSET      0x00000128
#define NATT_NTT_STR_1_MPDU_LIMIT_INDEX       0x0000004A
#define NATT_NTT_STR_1_MPDU_LIMIT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_mpdu_limit_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_MPDU_LIMIT_ADDR);
}

__INLINE void natt_ntt_str_1_mpdu_limit_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_1_MPDU_LIMIT_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_1_MPDU_LIMIT_NTT_STA_INDEX_MASK    ((uint32_t)0x7F000000)
#define NATT_NTT_STR_1_MPDU_LIMIT_NTT_STA_INDEX_LSB    24
#define NATT_NTT_STR_1_MPDU_LIMIT_NTT_STA_INDEX_WIDTH    ((uint32_t)0x00000007)
#define NATT_NTT_STR_1_MPDU_LIMIT_NTT_MAX_MPDU_MASK    ((uint32_t)0x001FF000)
#define NATT_NTT_STR_1_MPDU_LIMIT_NTT_MAX_MPDU_LSB    12
#define NATT_NTT_STR_1_MPDU_LIMIT_NTT_MAX_MPDU_WIDTH    ((uint32_t)0x00000009)
#define NATT_NTT_STR_1_MPDU_LIMIT_NTT_BA_WINDOW_MASK    ((uint32_t)0x000001FF)
#define NATT_NTT_STR_1_MPDU_LIMIT_NTT_BA_WINDOW_LSB    0
#define NATT_NTT_STR_1_MPDU_LIMIT_NTT_BA_WINDOW_WIDTH    ((uint32_t)0x00000009)

#define NATT_NTT_STR_1_MPDU_LIMIT_NTT_STA_INDEX_RST    0x0
#define NATT_NTT_STR_1_MPDU_LIMIT_NTT_MAX_MPDU_RST    0x0
#define NATT_NTT_STR_1_MPDU_LIMIT_NTT_BA_WINDOW_RST    0x0

__INLINE void natt_ntt_str_1_mpdu_limit_pack(uint8_t ntt_sta_index, uint16_t ntt_max_mpdu, uint16_t ntt_ba_window)
{
	ASSERT_ERR((((uint32_t)ntt_sta_index << 24) & ~((uint32_t)0x7F000000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_max_mpdu << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_ba_window << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_MPDU_LIMIT_ADDR,  ((uint32_t)ntt_sta_index << 24) |((uint32_t)ntt_max_mpdu << 12) |((uint32_t)ntt_ba_window << 0));
}

__INLINE void natt_ntt_str_1_mpdu_limit_unpack(uint8_t* ntt_sta_index, uint16_t* ntt_max_mpdu, uint16_t* ntt_ba_window)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_MPDU_LIMIT_ADDR);

	*ntt_sta_index = (localVal & ((uint32_t)0x7F000000)) >>  24;
	*ntt_max_mpdu = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*ntt_ba_window = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t natt_ntt_str_1_mpdu_limit_ntt_sta_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_MPDU_LIMIT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x7F000000)) >> 24);
}
__INLINE void natt_ntt_str_1_mpdu_limit_ntt_sta_index_setf(uint8_t nttstaindex)
{
	ASSERT_ERR((((uint32_t)nttstaindex << 24) & ~((uint32_t)0x7F000000)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_MPDU_LIMIT_ADDR, (REG_PL_RD(NATT_NTT_STR_1_MPDU_LIMIT_ADDR) & ~((uint32_t)0x7F000000)) | ((uint32_t)nttstaindex <<24));
}
__INLINE uint16_t natt_ntt_str_1_mpdu_limit_ntt_max_mpdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_MPDU_LIMIT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void natt_ntt_str_1_mpdu_limit_ntt_max_mpdu_setf(uint16_t nttmaxmpdu)
{
	ASSERT_ERR((((uint32_t)nttmaxmpdu << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_MPDU_LIMIT_ADDR, (REG_PL_RD(NATT_NTT_STR_1_MPDU_LIMIT_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)nttmaxmpdu <<12));
}
__INLINE uint16_t natt_ntt_str_1_mpdu_limit_ntt_ba_window_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_MPDU_LIMIT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void natt_ntt_str_1_mpdu_limit_ntt_ba_window_setf(uint16_t nttbawindow)
{
	ASSERT_ERR((((uint32_t)nttbawindow << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_MPDU_LIMIT_ADDR, (REG_PL_RD(NATT_NTT_STR_1_MPDU_LIMIT_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)nttbawindow <<0));
}

/**
 * @brief NTT_STR_1_THD_BASE_LOC register definition
 *  THD location for psdu_length register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_THD_LOC               0x0
 * </pre>
 */
#define NATT_NTT_STR_1_THD_BASE_LOC_ADDR        (REG_NATT_BASE_ADDR+0x0000012C)
#define NATT_NTT_STR_1_THD_BASE_LOC_OFFSET      0x0000012C
#define NATT_NTT_STR_1_THD_BASE_LOC_INDEX       0x0000004B
#define NATT_NTT_STR_1_THD_BASE_LOC_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_thd_base_loc_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_THD_BASE_LOC_ADDR);
}

__INLINE void natt_ntt_str_1_thd_base_loc_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_1_THD_BASE_LOC_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_1_THD_BASE_LOC_NTT_THD_LOC_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_1_THD_BASE_LOC_NTT_THD_LOC_LSB    0
#define NATT_NTT_STR_1_THD_BASE_LOC_NTT_THD_LOC_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_1_THD_BASE_LOC_NTT_THD_LOC_RST    0x0

__INLINE uint32_t natt_ntt_str_1_thd_base_loc_ntt_thd_loc_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_THD_BASE_LOC_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_1_thd_base_loc_ntt_thd_loc_setf(uint32_t nttthdloc)
{
	ASSERT_ERR((((uint32_t)nttthdloc << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_THD_BASE_LOC_ADDR, (uint32_t)nttthdloc << 0);
}

/**
 * @brief NTT_STR_1_CR_INFO register definition
 *  End of process closing reason register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05:00 NTT_CR_INFO               0x0
 * </pre>
 */
#define NATT_NTT_STR_1_CR_INFO_ADDR        (REG_NATT_BASE_ADDR+0x00000130)
#define NATT_NTT_STR_1_CR_INFO_OFFSET      0x00000130
#define NATT_NTT_STR_1_CR_INFO_INDEX       0x0000004C
#define NATT_NTT_STR_1_CR_INFO_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_cr_info_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_CR_INFO_ADDR);
}

// field definitions
#define NATT_NTT_STR_1_CR_INFO_NTT_CR_INFO_MASK    ((uint32_t)0x0000003F)
#define NATT_NTT_STR_1_CR_INFO_NTT_CR_INFO_LSB    0
#define NATT_NTT_STR_1_CR_INFO_NTT_CR_INFO_WIDTH    ((uint32_t)0x00000006)

#define NATT_NTT_STR_1_CR_INFO_NTT_CR_INFO_RST    0x0

__INLINE uint8_t natt_ntt_str_1_cr_info_ntt_cr_info_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_CR_INFO_ADDR);
	return (uint8_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_1_LD_INFO register definition
 *  End of process last description address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_LD_INFO               0x0
 * </pre>
 */
#define NATT_NTT_STR_1_LD_INFO_ADDR        (REG_NATT_BASE_ADDR+0x00000134)
#define NATT_NTT_STR_1_LD_INFO_OFFSET      0x00000134
#define NATT_NTT_STR_1_LD_INFO_INDEX       0x0000004D
#define NATT_NTT_STR_1_LD_INFO_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_ld_info_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_LD_INFO_ADDR);
}

// field definitions
#define NATT_NTT_STR_1_LD_INFO_NTT_LD_INFO_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_1_LD_INFO_NTT_LD_INFO_LSB    0
#define NATT_NTT_STR_1_LD_INFO_NTT_LD_INFO_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_1_LD_INFO_NTT_LD_INFO_RST    0x0

__INLINE uint32_t natt_ntt_str_1_ld_info_ntt_ld_info_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_LD_INFO_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_1_NON_DATA_INFO_1 register definition
 *  Number length and padding of nonDATA MPDUs register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17:16 NTT_NON_DATA1_PAD         0x0
 *    15:12 NTT_NON_DATA1_NUM         0x0
 *    09:00 NTT_NON_DATA1_LEN         0x0
 * </pre>
 */
#define NATT_NTT_STR_1_NON_DATA_INFO_1_ADDR        (REG_NATT_BASE_ADDR+0x00000160)
#define NATT_NTT_STR_1_NON_DATA_INFO_1_OFFSET      0x00000160
#define NATT_NTT_STR_1_NON_DATA_INFO_1_INDEX       0x00000058
#define NATT_NTT_STR_1_NON_DATA_INFO_1_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_non_data_info_1_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_NON_DATA_INFO_1_ADDR);
}

__INLINE void natt_ntt_str_1_non_data_info_1_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_1_NON_DATA_INFO_1_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_1_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_MASK    ((uint32_t)0x00030000)
#define NATT_NTT_STR_1_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_LSB    16
#define NATT_NTT_STR_1_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_WIDTH    ((uint32_t)0x00000002)
#define NATT_NTT_STR_1_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_MASK    ((uint32_t)0x0000F000)
#define NATT_NTT_STR_1_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_LSB    12
#define NATT_NTT_STR_1_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_WIDTH    ((uint32_t)0x00000004)
#define NATT_NTT_STR_1_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_MASK    ((uint32_t)0x000003FF)
#define NATT_NTT_STR_1_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_LSB    0
#define NATT_NTT_STR_1_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_WIDTH    ((uint32_t)0x0000000A)

#define NATT_NTT_STR_1_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_RST    0x0
#define NATT_NTT_STR_1_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_RST    0x0
#define NATT_NTT_STR_1_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_RST    0x0

__INLINE void natt_ntt_str_1_non_data_info_1_pack(uint8_t ntt_non_data1_pad, uint8_t ntt_non_data1_num, uint16_t ntt_non_data1_len)
{
	ASSERT_ERR((((uint32_t)ntt_non_data1_pad << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data1_num << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data1_len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_NON_DATA_INFO_1_ADDR,  ((uint32_t)ntt_non_data1_pad << 16) |((uint32_t)ntt_non_data1_num << 12) |((uint32_t)ntt_non_data1_len << 0));
}

__INLINE void natt_ntt_str_1_non_data_info_1_unpack(uint8_t* ntt_non_data1_pad, uint8_t* ntt_non_data1_num, uint16_t* ntt_non_data1_len)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_NON_DATA_INFO_1_ADDR);

	*ntt_non_data1_pad = (localVal & ((uint32_t)0x00030000)) >>  16;
	*ntt_non_data1_num = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*ntt_non_data1_len = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint8_t natt_ntt_str_1_non_data_info_1_ntt_non_data_1_pad_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_NON_DATA_INFO_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void natt_ntt_str_1_non_data_info_1_ntt_non_data_1_pad_setf(uint8_t nttnondata1pad)
{
	ASSERT_ERR((((uint32_t)nttnondata1pad << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_NON_DATA_INFO_1_ADDR, (REG_PL_RD(NATT_NTT_STR_1_NON_DATA_INFO_1_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)nttnondata1pad <<16));
}
__INLINE uint8_t natt_ntt_str_1_non_data_info_1_ntt_non_data_1_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_NON_DATA_INFO_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void natt_ntt_str_1_non_data_info_1_ntt_non_data_1_num_setf(uint8_t nttnondata1num)
{
	ASSERT_ERR((((uint32_t)nttnondata1num << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_NON_DATA_INFO_1_ADDR, (REG_PL_RD(NATT_NTT_STR_1_NON_DATA_INFO_1_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)nttnondata1num <<12));
}
__INLINE uint16_t natt_ntt_str_1_non_data_info_1_ntt_non_data_1_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_NON_DATA_INFO_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void natt_ntt_str_1_non_data_info_1_ntt_non_data_1_len_setf(uint16_t nttnondata1len)
{
	ASSERT_ERR((((uint32_t)nttnondata1len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_NON_DATA_INFO_1_ADDR, (REG_PL_RD(NATT_NTT_STR_1_NON_DATA_INFO_1_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)nttnondata1len <<0));
}

/**
 * @brief NTT_STR_1_NON_DATA_INFO_2 register definition
 *  Number length and padding of nonDATA MPDUs register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17:16 NTT_NON_DATA2_PAD         0x0
 *    15:12 NTT_NON_DATA2_NUM         0x0
 *    09:00 NTT_NON_DATA2_LEN         0x0
 * </pre>
 */
#define NATT_NTT_STR_1_NON_DATA_INFO_2_ADDR        (REG_NATT_BASE_ADDR+0x00000164)
#define NATT_NTT_STR_1_NON_DATA_INFO_2_OFFSET      0x00000164
#define NATT_NTT_STR_1_NON_DATA_INFO_2_INDEX       0x00000059
#define NATT_NTT_STR_1_NON_DATA_INFO_2_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_non_data_info_2_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_NON_DATA_INFO_2_ADDR);
}

__INLINE void natt_ntt_str_1_non_data_info_2_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_1_NON_DATA_INFO_2_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_1_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_MASK    ((uint32_t)0x00030000)
#define NATT_NTT_STR_1_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_LSB    16
#define NATT_NTT_STR_1_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_WIDTH    ((uint32_t)0x00000002)
#define NATT_NTT_STR_1_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_MASK    ((uint32_t)0x0000F000)
#define NATT_NTT_STR_1_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_LSB    12
#define NATT_NTT_STR_1_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_WIDTH    ((uint32_t)0x00000004)
#define NATT_NTT_STR_1_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_MASK    ((uint32_t)0x000003FF)
#define NATT_NTT_STR_1_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_LSB    0
#define NATT_NTT_STR_1_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_WIDTH    ((uint32_t)0x0000000A)

#define NATT_NTT_STR_1_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_RST    0x0
#define NATT_NTT_STR_1_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_RST    0x0
#define NATT_NTT_STR_1_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_RST    0x0

__INLINE void natt_ntt_str_1_non_data_info_2_pack(uint8_t ntt_non_data2_pad, uint8_t ntt_non_data2_num, uint16_t ntt_non_data2_len)
{
	ASSERT_ERR((((uint32_t)ntt_non_data2_pad << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data2_num << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data2_len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_NON_DATA_INFO_2_ADDR,  ((uint32_t)ntt_non_data2_pad << 16) |((uint32_t)ntt_non_data2_num << 12) |((uint32_t)ntt_non_data2_len << 0));
}

__INLINE void natt_ntt_str_1_non_data_info_2_unpack(uint8_t* ntt_non_data2_pad, uint8_t* ntt_non_data2_num, uint16_t* ntt_non_data2_len)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_NON_DATA_INFO_2_ADDR);

	*ntt_non_data2_pad = (localVal & ((uint32_t)0x00030000)) >>  16;
	*ntt_non_data2_num = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*ntt_non_data2_len = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint8_t natt_ntt_str_1_non_data_info_2_ntt_non_data_2_pad_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_NON_DATA_INFO_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void natt_ntt_str_1_non_data_info_2_ntt_non_data_2_pad_setf(uint8_t nttnondata2pad)
{
	ASSERT_ERR((((uint32_t)nttnondata2pad << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_NON_DATA_INFO_2_ADDR, (REG_PL_RD(NATT_NTT_STR_1_NON_DATA_INFO_2_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)nttnondata2pad <<16));
}
__INLINE uint8_t natt_ntt_str_1_non_data_info_2_ntt_non_data_2_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_NON_DATA_INFO_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void natt_ntt_str_1_non_data_info_2_ntt_non_data_2_num_setf(uint8_t nttnondata2num)
{
	ASSERT_ERR((((uint32_t)nttnondata2num << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_NON_DATA_INFO_2_ADDR, (REG_PL_RD(NATT_NTT_STR_1_NON_DATA_INFO_2_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)nttnondata2num <<12));
}
__INLINE uint16_t natt_ntt_str_1_non_data_info_2_ntt_non_data_2_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_NON_DATA_INFO_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void natt_ntt_str_1_non_data_info_2_ntt_non_data_2_len_setf(uint16_t nttnondata2len)
{
	ASSERT_ERR((((uint32_t)nttnondata2len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_NON_DATA_INFO_2_ADDR, (REG_PL_RD(NATT_NTT_STR_1_NON_DATA_INFO_2_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)nttnondata2len <<0));
}

/**
 * @brief NTT_STR_1_NON_DATA_1_RESULT register definition
 *  ZLDs and padding_in_bytes results for nonData register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 NTT_NON_DATA1_PADDING_IN_BYTES 0x0
 *    15:00 NTT_NON_DATA1_ZLD         0x0
 * </pre>
 */
#define NATT_NTT_STR_1_NON_DATA_1_RESULT_ADDR        (REG_NATT_BASE_ADDR+0x00000168)
#define NATT_NTT_STR_1_NON_DATA_1_RESULT_OFFSET      0x00000168
#define NATT_NTT_STR_1_NON_DATA_1_RESULT_INDEX       0x0000005A
#define NATT_NTT_STR_1_NON_DATA_1_RESULT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_non_data_1_result_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_NON_DATA_1_RESULT_ADDR);
}

// field definitions
#define NATT_NTT_STR_1_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_MASK    ((uint32_t)0xFFFF0000)
#define NATT_NTT_STR_1_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_LSB    16
#define NATT_NTT_STR_1_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_WIDTH    ((uint32_t)0x00000010)
#define NATT_NTT_STR_1_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_1_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_LSB    0
#define NATT_NTT_STR_1_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_1_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_RST    0x0
#define NATT_NTT_STR_1_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_RST    0x0

__INLINE void natt_ntt_str_1_non_data_1_result_unpack(uint16_t* ntt_non_data1_padding_in_bytes, uint16_t* ntt_non_data1_zld)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_NON_DATA_1_RESULT_ADDR);

	*ntt_non_data1_padding_in_bytes = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ntt_non_data1_zld = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t natt_ntt_str_1_non_data_1_result_ntt_non_data_1_padding_in_bytes_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_NON_DATA_1_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t natt_ntt_str_1_non_data_1_result_ntt_non_data_1_zld_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_NON_DATA_1_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief NTT_STR_1_NON_DATA_2_RESULT register definition
 *  ZLDs and padding_in_bytes results for nonData register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 NTT_NON_DATA2_PADDING_IN_BYTES 0x0
 *    15:00 TT_NON_DATA2_ZLD          0x0
 * </pre>
 */
#define NATT_NTT_STR_1_NON_DATA_2_RESULT_ADDR        (REG_NATT_BASE_ADDR+0x0000016C)
#define NATT_NTT_STR_1_NON_DATA_2_RESULT_OFFSET      0x0000016C
#define NATT_NTT_STR_1_NON_DATA_2_RESULT_INDEX       0x0000005B
#define NATT_NTT_STR_1_NON_DATA_2_RESULT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_non_data_2_result_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_NON_DATA_2_RESULT_ADDR);
}

// field definitions
#define NATT_NTT_STR_1_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_MASK    ((uint32_t)0xFFFF0000)
#define NATT_NTT_STR_1_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_LSB    16
#define NATT_NTT_STR_1_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_WIDTH    ((uint32_t)0x00000010)
#define NATT_NTT_STR_1_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_1_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_LSB    0
#define NATT_NTT_STR_1_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_1_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_RST    0x0
#define NATT_NTT_STR_1_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_RST    0x0

__INLINE void natt_ntt_str_1_non_data_2_result_unpack(uint16_t* ntt_non_data2_padding_in_bytes, uint16_t* tt_non_data2_zld)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_NON_DATA_2_RESULT_ADDR);

	*ntt_non_data2_padding_in_bytes = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*tt_non_data2_zld = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t natt_ntt_str_1_non_data_2_result_ntt_non_data_2_padding_in_bytes_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_NON_DATA_2_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t natt_ntt_str_1_non_data_2_result_tt_non_data_2_zld_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_NON_DATA_2_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief NTT_STR_1_MIN_SPACING_CONF register definition
 *  Min_spacing parameters for STA capabilities register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    FORCE_MIN_SPACING         0              
 *    07:04 MIN_SPACING_FACTOR        0x0
 *    03:00 MIN_SPACING               0x0
 * </pre>
 */
#define NATT_NTT_STR_1_MIN_SPACING_CONF_ADDR        (REG_NATT_BASE_ADDR+0x00000170)
#define NATT_NTT_STR_1_MIN_SPACING_CONF_OFFSET      0x00000170
#define NATT_NTT_STR_1_MIN_SPACING_CONF_INDEX       0x0000005C
#define NATT_NTT_STR_1_MIN_SPACING_CONF_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_min_spacing_conf_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_MIN_SPACING_CONF_ADDR);
}

__INLINE void natt_ntt_str_1_min_spacing_conf_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_1_MIN_SPACING_CONF_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_1_MIN_SPACING_CONF_FORCE_MIN_SPACING_BIT    ((uint32_t)0x80000000)
#define NATT_NTT_STR_1_MIN_SPACING_CONF_FORCE_MIN_SPACING_POS    31
#define NATT_NTT_STR_1_MIN_SPACING_CONF_MIN_SPACING_FACTOR_MASK    ((uint32_t)0x000000F0)
#define NATT_NTT_STR_1_MIN_SPACING_CONF_MIN_SPACING_FACTOR_LSB    4
#define NATT_NTT_STR_1_MIN_SPACING_CONF_MIN_SPACING_FACTOR_WIDTH    ((uint32_t)0x00000004)
#define NATT_NTT_STR_1_MIN_SPACING_CONF_MIN_SPACING_MASK    ((uint32_t)0x0000000F)
#define NATT_NTT_STR_1_MIN_SPACING_CONF_MIN_SPACING_LSB    0
#define NATT_NTT_STR_1_MIN_SPACING_CONF_MIN_SPACING_WIDTH    ((uint32_t)0x00000004)

#define NATT_NTT_STR_1_MIN_SPACING_CONF_FORCE_MIN_SPACING_RST    0x0
#define NATT_NTT_STR_1_MIN_SPACING_CONF_MIN_SPACING_FACTOR_RST    0x0
#define NATT_NTT_STR_1_MIN_SPACING_CONF_MIN_SPACING_RST    0x0

__INLINE void natt_ntt_str_1_min_spacing_conf_pack(uint8_t force_min_spacing, uint8_t min_spacing_factor, uint8_t min_spacing)
{
	ASSERT_ERR((((uint32_t)force_min_spacing << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)min_spacing_factor << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)min_spacing << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_MIN_SPACING_CONF_ADDR,  ((uint32_t)force_min_spacing << 31) |((uint32_t)min_spacing_factor << 4) |((uint32_t)min_spacing << 0));
}

__INLINE void natt_ntt_str_1_min_spacing_conf_unpack(uint8_t* force_min_spacing, uint8_t* min_spacing_factor, uint8_t* min_spacing)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_MIN_SPACING_CONF_ADDR);

	*force_min_spacing = (localVal & ((uint32_t)0x80000000)) >>  31;
	*min_spacing_factor = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*min_spacing = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t natt_ntt_str_1_min_spacing_conf_force_min_spacing_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_MIN_SPACING_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void natt_ntt_str_1_min_spacing_conf_force_min_spacing_setf(uint8_t forceminspacing)
{
	ASSERT_ERR((((uint32_t)forceminspacing << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_MIN_SPACING_CONF_ADDR, (REG_PL_RD(NATT_NTT_STR_1_MIN_SPACING_CONF_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)forceminspacing <<31));
}
__INLINE uint8_t natt_ntt_str_1_min_spacing_conf_min_spacing_factor_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_MIN_SPACING_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void natt_ntt_str_1_min_spacing_conf_min_spacing_factor_setf(uint8_t minspacingfactor)
{
	ASSERT_ERR((((uint32_t)minspacingfactor << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_MIN_SPACING_CONF_ADDR, (REG_PL_RD(NATT_NTT_STR_1_MIN_SPACING_CONF_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)minspacingfactor <<4));
}
__INLINE uint8_t natt_ntt_str_1_min_spacing_conf_min_spacing_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_MIN_SPACING_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void natt_ntt_str_1_min_spacing_conf_min_spacing_setf(uint8_t minspacing)
{
	ASSERT_ERR((((uint32_t)minspacing << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_MIN_SPACING_CONF_ADDR, (REG_PL_RD(NATT_NTT_STR_1_MIN_SPACING_CONF_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)minspacing <<0));
}

/**
 * @brief NTT_STR_1_DBG_CNT register definition
 *  Debug commands counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DBG_CNT               0x0
 * </pre>
 */
#define NATT_NTT_STR_1_DBG_CNT_ADDR        (REG_NATT_BASE_ADDR+0x00000174)
#define NATT_NTT_STR_1_DBG_CNT_OFFSET      0x00000174
#define NATT_NTT_STR_1_DBG_CNT_INDEX       0x0000005D
#define NATT_NTT_STR_1_DBG_CNT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_dbg_cnt_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_DBG_CNT_ADDR);
}

__INLINE void natt_ntt_str_1_dbg_cnt_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_1_DBG_CNT_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_1_DBG_CNT_NTT_DBG_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_1_DBG_CNT_NTT_DBG_CNT_LSB    0
#define NATT_NTT_STR_1_DBG_CNT_NTT_DBG_CNT_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_1_DBG_CNT_NTT_DBG_CNT_RST    0x0

__INLINE uint32_t natt_ntt_str_1_dbg_cnt_ntt_dbg_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_DBG_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_1_dbg_cnt_ntt_dbg_cnt_setf(uint32_t nttdbgcnt)
{
	ASSERT_ERR((((uint32_t)nttdbgcnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_1_DBG_CNT_ADDR, (uint32_t)nttdbgcnt << 0);
}

/**
 * @brief NTT_STR_1_PHY_RATE register definition
 *  Debug results of last packet (ndps+rate) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 NTT_PHY_RATE              0x0
 * </pre>
 */
#define NATT_NTT_STR_1_PHY_RATE_ADDR        (REG_NATT_BASE_ADDR+0x00000178)
#define NATT_NTT_STR_1_PHY_RATE_OFFSET      0x00000178
#define NATT_NTT_STR_1_PHY_RATE_INDEX       0x0000005E
#define NATT_NTT_STR_1_PHY_RATE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_phy_rate_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_PHY_RATE_ADDR);
}

// field definitions
#define NATT_NTT_STR_1_PHY_RATE_NTT_PHY_RATE_MASK    ((uint32_t)0x000FFFFF)
#define NATT_NTT_STR_1_PHY_RATE_NTT_PHY_RATE_LSB    0
#define NATT_NTT_STR_1_PHY_RATE_NTT_PHY_RATE_WIDTH    ((uint32_t)0x00000014)

#define NATT_NTT_STR_1_PHY_RATE_NTT_PHY_RATE_RST    0x0

__INLINE uint32_t natt_ntt_str_1_phy_rate_ntt_phy_rate_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_PHY_RATE_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_1_NDBPS register definition
 *  Number of data bits per symbol register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 NTT_NDBPS                 0x0
 * </pre>
 */
#define NATT_NTT_STR_1_NDBPS_ADDR        (REG_NATT_BASE_ADDR+0x0000017C)
#define NATT_NTT_STR_1_NDBPS_OFFSET      0x0000017C
#define NATT_NTT_STR_1_NDBPS_INDEX       0x0000005F
#define NATT_NTT_STR_1_NDBPS_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_ndbps_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_NDBPS_ADDR);
}

// field definitions
#define NATT_NTT_STR_1_NDBPS_NTT_NDBPS_MASK    ((uint32_t)0x000FFFFF)
#define NATT_NTT_STR_1_NDBPS_NTT_NDBPS_LSB    0
#define NATT_NTT_STR_1_NDBPS_NTT_NDBPS_WIDTH    ((uint32_t)0x00000014)

#define NATT_NTT_STR_1_NDBPS_NTT_NDBPS_RST    0x0

__INLINE uint32_t natt_ntt_str_1_ndbps_ntt_ndbps_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_NDBPS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_1_SYM_TIME register definition
 *  Debug results of last packet (symbols+datatime) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 NTT_SYMBOLS               0x0
 *    15:00 NTT_DAT_TIME              0x0
 * </pre>
 */
#define NATT_NTT_STR_1_SYM_TIME_ADDR        (REG_NATT_BASE_ADDR+0x00000180)
#define NATT_NTT_STR_1_SYM_TIME_OFFSET      0x00000180
#define NATT_NTT_STR_1_SYM_TIME_INDEX       0x00000060
#define NATT_NTT_STR_1_SYM_TIME_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_sym_time_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_SYM_TIME_ADDR);
}

// field definitions
#define NATT_NTT_STR_1_SYM_TIME_NTT_SYMBOLS_MASK    ((uint32_t)0xFFFF0000)
#define NATT_NTT_STR_1_SYM_TIME_NTT_SYMBOLS_LSB    16
#define NATT_NTT_STR_1_SYM_TIME_NTT_SYMBOLS_WIDTH    ((uint32_t)0x00000010)
#define NATT_NTT_STR_1_SYM_TIME_NTT_DAT_TIME_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_1_SYM_TIME_NTT_DAT_TIME_LSB    0
#define NATT_NTT_STR_1_SYM_TIME_NTT_DAT_TIME_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_1_SYM_TIME_NTT_SYMBOLS_RST    0x0
#define NATT_NTT_STR_1_SYM_TIME_NTT_DAT_TIME_RST    0x0

__INLINE void natt_ntt_str_1_sym_time_unpack(uint16_t* ntt_symbols, uint16_t* ntt_dat_time)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_SYM_TIME_ADDR);

	*ntt_symbols = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ntt_dat_time = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t natt_ntt_str_1_sym_time_ntt_symbols_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_SYM_TIME_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t natt_ntt_str_1_sym_time_ntt_dat_time_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_SYM_TIME_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief NTT_STR_1_TOT_TIME register definition
 *  Debug results of last packet (total time) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 NTT_TOT_TIME              0x0
 * </pre>
 */
#define NATT_NTT_STR_1_TOT_TIME_ADDR        (REG_NATT_BASE_ADDR+0x00000184)
#define NATT_NTT_STR_1_TOT_TIME_OFFSET      0x00000184
#define NATT_NTT_STR_1_TOT_TIME_INDEX       0x00000061
#define NATT_NTT_STR_1_TOT_TIME_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_tot_time_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_TOT_TIME_ADDR);
}

// field definitions
#define NATT_NTT_STR_1_TOT_TIME_NTT_TOT_TIME_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_1_TOT_TIME_NTT_TOT_TIME_LSB    0
#define NATT_NTT_STR_1_TOT_TIME_NTT_TOT_TIME_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_1_TOT_TIME_NTT_TOT_TIME_RST    0x0

__INLINE uint16_t natt_ntt_str_1_tot_time_ntt_tot_time_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_TOT_TIME_ADDR);
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_1_MPDU_NUM register definition
 *  Debug results of last packet (number of MPDUs) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    08:00 NTT_MPDU_NUM              0x0
 * </pre>
 */
#define NATT_NTT_STR_1_MPDU_NUM_ADDR        (REG_NATT_BASE_ADDR+0x00000188)
#define NATT_NTT_STR_1_MPDU_NUM_OFFSET      0x00000188
#define NATT_NTT_STR_1_MPDU_NUM_INDEX       0x00000062
#define NATT_NTT_STR_1_MPDU_NUM_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_mpdu_num_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_MPDU_NUM_ADDR);
}

// field definitions
#define NATT_NTT_STR_1_MPDU_NUM_NTT_MPDU_NUM_MASK    ((uint32_t)0x000001FF)
#define NATT_NTT_STR_1_MPDU_NUM_NTT_MPDU_NUM_LSB    0
#define NATT_NTT_STR_1_MPDU_NUM_NTT_MPDU_NUM_WIDTH    ((uint32_t)0x00000009)

#define NATT_NTT_STR_1_MPDU_NUM_NTT_MPDU_NUM_RST    0x0

__INLINE uint16_t natt_ntt_str_1_mpdu_num_ntt_mpdu_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_MPDU_NUM_ADDR);
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_1_AMPDU_LEN register definition
 *  AMPDU actual length in bytes register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:00 NTT_AMPDU_LEN             0x0
 * </pre>
 */
#define NATT_NTT_STR_1_AMPDU_LEN_ADDR        (REG_NATT_BASE_ADDR+0x0000018C)
#define NATT_NTT_STR_1_AMPDU_LEN_OFFSET      0x0000018C
#define NATT_NTT_STR_1_AMPDU_LEN_INDEX       0x00000063
#define NATT_NTT_STR_1_AMPDU_LEN_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_ampdu_len_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_AMPDU_LEN_ADDR);
}

// field definitions
#define NATT_NTT_STR_1_AMPDU_LEN_NTT_AMPDU_LEN_MASK    ((uint32_t)0x00FFFFFF)
#define NATT_NTT_STR_1_AMPDU_LEN_NTT_AMPDU_LEN_LSB    0
#define NATT_NTT_STR_1_AMPDU_LEN_NTT_AMPDU_LEN_WIDTH    ((uint32_t)0x00000018)

#define NATT_NTT_STR_1_AMPDU_LEN_NTT_AMPDU_LEN_RST    0x0

__INLINE uint32_t natt_ntt_str_1_ampdu_len_ntt_ampdu_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_AMPDU_LEN_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_1_MAX_AMPDU_LEN register definition
 *  MAX AMPDU Length in bytes register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:00 NTT_MAX_AMPDU_LEN         0x0
 * </pre>
 */
#define NATT_NTT_STR_1_MAX_AMPDU_LEN_ADDR        (REG_NATT_BASE_ADDR+0x00000190)
#define NATT_NTT_STR_1_MAX_AMPDU_LEN_OFFSET      0x00000190
#define NATT_NTT_STR_1_MAX_AMPDU_LEN_INDEX       0x00000064
#define NATT_NTT_STR_1_MAX_AMPDU_LEN_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_1_max_ampdu_len_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_1_MAX_AMPDU_LEN_ADDR);
}

// field definitions
#define NATT_NTT_STR_1_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_MASK    ((uint32_t)0x00FFFFFF)
#define NATT_NTT_STR_1_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_LSB    0
#define NATT_NTT_STR_1_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_WIDTH    ((uint32_t)0x00000018)

#define NATT_NTT_STR_1_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_RST    0x0

__INLINE uint32_t natt_ntt_str_1_max_ampdu_len_ntt_max_ampdu_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_1_MAX_AMPDU_LEN_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_2_PT_BASE register definition
 *  Policy Table register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_PT_BASE               0x0
 * </pre>
 */
#define NATT_NTT_STR_2_PT_BASE_ADDR        (REG_NATT_BASE_ADDR+0x0000020C)
#define NATT_NTT_STR_2_PT_BASE_OFFSET      0x0000020C
#define NATT_NTT_STR_2_PT_BASE_INDEX       0x00000083
#define NATT_NTT_STR_2_PT_BASE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_pt_base_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_PT_BASE_ADDR);
}

__INLINE void natt_ntt_str_2_pt_base_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_2_PT_BASE_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_2_PT_BASE_NTT_PT_BASE_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_2_PT_BASE_NTT_PT_BASE_LSB    0
#define NATT_NTT_STR_2_PT_BASE_NTT_PT_BASE_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_2_PT_BASE_NTT_PT_BASE_RST    0x0

__INLINE uint32_t natt_ntt_str_2_pt_base_ntt_pt_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_PT_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_2_pt_base_ntt_pt_base_setf(uint32_t nttptbase)
{
	ASSERT_ERR((((uint32_t)nttptbase << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_PT_BASE_ADDR, (uint32_t)nttptbase << 0);
}

/**
 * @brief NTT_STR_2_DESC_BASE register definition
 *  Descriptors chain base address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DESC_BASE             0x0
 * </pre>
 */
#define NATT_NTT_STR_2_DESC_BASE_ADDR        (REG_NATT_BASE_ADDR+0x00000210)
#define NATT_NTT_STR_2_DESC_BASE_OFFSET      0x00000210
#define NATT_NTT_STR_2_DESC_BASE_INDEX       0x00000084
#define NATT_NTT_STR_2_DESC_BASE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_desc_base_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_DESC_BASE_ADDR);
}

__INLINE void natt_ntt_str_2_desc_base_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_2_DESC_BASE_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_2_DESC_BASE_NTT_DESC_BASE_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_2_DESC_BASE_NTT_DESC_BASE_LSB    0
#define NATT_NTT_STR_2_DESC_BASE_NTT_DESC_BASE_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_2_DESC_BASE_NTT_DESC_BASE_RST    0x0

__INLINE uint32_t natt_ntt_str_2_desc_base_ntt_desc_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_DESC_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_2_desc_base_ntt_desc_base_setf(uint32_t nttdescbase)
{
	ASSERT_ERR((((uint32_t)nttdescbase << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_DESC_BASE_ADDR, (uint32_t)nttdescbase << 0);
}

/**
 * @brief NTT_STR_2_DESC_TSIZE register definition
 *  Total descriptors chain size register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DESC_TSIZE            0x0
 * </pre>
 */
#define NATT_NTT_STR_2_DESC_TSIZE_ADDR        (REG_NATT_BASE_ADDR+0x0000021C)
#define NATT_NTT_STR_2_DESC_TSIZE_OFFSET      0x0000021C
#define NATT_NTT_STR_2_DESC_TSIZE_INDEX       0x00000087
#define NATT_NTT_STR_2_DESC_TSIZE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_desc_tsize_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_DESC_TSIZE_ADDR);
}

__INLINE void natt_ntt_str_2_desc_tsize_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_2_DESC_TSIZE_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_2_DESC_TSIZE_NTT_DESC_TSIZE_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_2_DESC_TSIZE_NTT_DESC_TSIZE_LSB    0
#define NATT_NTT_STR_2_DESC_TSIZE_NTT_DESC_TSIZE_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_2_DESC_TSIZE_NTT_DESC_TSIZE_RST    0x0

__INLINE uint32_t natt_ntt_str_2_desc_tsize_ntt_desc_tsize_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_DESC_TSIZE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_2_desc_tsize_ntt_desc_tsize_setf(uint32_t nttdesctsize)
{
	ASSERT_ERR((((uint32_t)nttdesctsize << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_DESC_TSIZE_ADDR, (uint32_t)nttdesctsize << 0);
}

/**
 * @brief NTT_STR_2_DESC_START register definition
 *  Descriptors chain start address (1st MPDU) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DESC_START            0x0
 * </pre>
 */
#define NATT_NTT_STR_2_DESC_START_ADDR        (REG_NATT_BASE_ADDR+0x00000220)
#define NATT_NTT_STR_2_DESC_START_OFFSET      0x00000220
#define NATT_NTT_STR_2_DESC_START_INDEX       0x00000088
#define NATT_NTT_STR_2_DESC_START_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_desc_start_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_DESC_START_ADDR);
}

__INLINE void natt_ntt_str_2_desc_start_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_2_DESC_START_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_2_DESC_START_NTT_DESC_START_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_2_DESC_START_NTT_DESC_START_LSB    0
#define NATT_NTT_STR_2_DESC_START_NTT_DESC_START_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_2_DESC_START_NTT_DESC_START_RST    0x0

__INLINE uint32_t natt_ntt_str_2_desc_start_ntt_desc_start_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_DESC_START_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_2_desc_start_ntt_desc_start_setf(uint32_t nttdescstart)
{
	ASSERT_ERR((((uint32_t)nttdescstart << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_DESC_START_ADDR, (uint32_t)nttdescstart << 0);
}

/**
 * @brief NTT_STR_2_AIRTIME_LIMIT register definition
 *  AirTime Limit in usec register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 NTT_AIRTIME_LIMIT         0x0
 * </pre>
 */
#define NATT_NTT_STR_2_AIRTIME_LIMIT_ADDR        (REG_NATT_BASE_ADDR+0x00000224)
#define NATT_NTT_STR_2_AIRTIME_LIMIT_OFFSET      0x00000224
#define NATT_NTT_STR_2_AIRTIME_LIMIT_INDEX       0x00000089
#define NATT_NTT_STR_2_AIRTIME_LIMIT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_airtime_limit_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_AIRTIME_LIMIT_ADDR);
}

__INLINE void natt_ntt_str_2_airtime_limit_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_2_AIRTIME_LIMIT_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_2_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_2_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_LSB    0
#define NATT_NTT_STR_2_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_2_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_RST    0x0

__INLINE uint16_t natt_ntt_str_2_airtime_limit_ntt_airtime_limit_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_AIRTIME_LIMIT_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_2_airtime_limit_ntt_airtime_limit_setf(uint16_t nttairtimelimit)
{
	ASSERT_ERR((((uint32_t)nttairtimelimit << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_AIRTIME_LIMIT_ADDR, (uint32_t)nttairtimelimit << 0);
}

/**
 * @brief NTT_STR_2_MPDU_LIMIT register definition
 *  BA and valid MPDUs limit register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:24 NTT_STA_INDEX             0x0
 *    20:12 NTT_MAX_MPDU              0x0
 *    08:00 NTT_BA_WINDOW             0x0
 * </pre>
 */
#define NATT_NTT_STR_2_MPDU_LIMIT_ADDR        (REG_NATT_BASE_ADDR+0x00000228)
#define NATT_NTT_STR_2_MPDU_LIMIT_OFFSET      0x00000228
#define NATT_NTT_STR_2_MPDU_LIMIT_INDEX       0x0000008A
#define NATT_NTT_STR_2_MPDU_LIMIT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_mpdu_limit_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_MPDU_LIMIT_ADDR);
}

__INLINE void natt_ntt_str_2_mpdu_limit_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_2_MPDU_LIMIT_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_2_MPDU_LIMIT_NTT_STA_INDEX_MASK    ((uint32_t)0x7F000000)
#define NATT_NTT_STR_2_MPDU_LIMIT_NTT_STA_INDEX_LSB    24
#define NATT_NTT_STR_2_MPDU_LIMIT_NTT_STA_INDEX_WIDTH    ((uint32_t)0x00000007)
#define NATT_NTT_STR_2_MPDU_LIMIT_NTT_MAX_MPDU_MASK    ((uint32_t)0x001FF000)
#define NATT_NTT_STR_2_MPDU_LIMIT_NTT_MAX_MPDU_LSB    12
#define NATT_NTT_STR_2_MPDU_LIMIT_NTT_MAX_MPDU_WIDTH    ((uint32_t)0x00000009)
#define NATT_NTT_STR_2_MPDU_LIMIT_NTT_BA_WINDOW_MASK    ((uint32_t)0x000001FF)
#define NATT_NTT_STR_2_MPDU_LIMIT_NTT_BA_WINDOW_LSB    0
#define NATT_NTT_STR_2_MPDU_LIMIT_NTT_BA_WINDOW_WIDTH    ((uint32_t)0x00000009)

#define NATT_NTT_STR_2_MPDU_LIMIT_NTT_STA_INDEX_RST    0x0
#define NATT_NTT_STR_2_MPDU_LIMIT_NTT_MAX_MPDU_RST    0x0
#define NATT_NTT_STR_2_MPDU_LIMIT_NTT_BA_WINDOW_RST    0x0

__INLINE void natt_ntt_str_2_mpdu_limit_pack(uint8_t ntt_sta_index, uint16_t ntt_max_mpdu, uint16_t ntt_ba_window)
{
	ASSERT_ERR((((uint32_t)ntt_sta_index << 24) & ~((uint32_t)0x7F000000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_max_mpdu << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_ba_window << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_MPDU_LIMIT_ADDR,  ((uint32_t)ntt_sta_index << 24) |((uint32_t)ntt_max_mpdu << 12) |((uint32_t)ntt_ba_window << 0));
}

__INLINE void natt_ntt_str_2_mpdu_limit_unpack(uint8_t* ntt_sta_index, uint16_t* ntt_max_mpdu, uint16_t* ntt_ba_window)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_MPDU_LIMIT_ADDR);

	*ntt_sta_index = (localVal & ((uint32_t)0x7F000000)) >>  24;
	*ntt_max_mpdu = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*ntt_ba_window = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t natt_ntt_str_2_mpdu_limit_ntt_sta_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_MPDU_LIMIT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x7F000000)) >> 24);
}
__INLINE void natt_ntt_str_2_mpdu_limit_ntt_sta_index_setf(uint8_t nttstaindex)
{
	ASSERT_ERR((((uint32_t)nttstaindex << 24) & ~((uint32_t)0x7F000000)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_MPDU_LIMIT_ADDR, (REG_PL_RD(NATT_NTT_STR_2_MPDU_LIMIT_ADDR) & ~((uint32_t)0x7F000000)) | ((uint32_t)nttstaindex <<24));
}
__INLINE uint16_t natt_ntt_str_2_mpdu_limit_ntt_max_mpdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_MPDU_LIMIT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void natt_ntt_str_2_mpdu_limit_ntt_max_mpdu_setf(uint16_t nttmaxmpdu)
{
	ASSERT_ERR((((uint32_t)nttmaxmpdu << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_MPDU_LIMIT_ADDR, (REG_PL_RD(NATT_NTT_STR_2_MPDU_LIMIT_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)nttmaxmpdu <<12));
}
__INLINE uint16_t natt_ntt_str_2_mpdu_limit_ntt_ba_window_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_MPDU_LIMIT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void natt_ntt_str_2_mpdu_limit_ntt_ba_window_setf(uint16_t nttbawindow)
{
	ASSERT_ERR((((uint32_t)nttbawindow << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_MPDU_LIMIT_ADDR, (REG_PL_RD(NATT_NTT_STR_2_MPDU_LIMIT_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)nttbawindow <<0));
}

/**
 * @brief NTT_STR_2_THD_BASE_LOC register definition
 *  THD location for psdu_length register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_THD_LOC               0x0
 * </pre>
 */
#define NATT_NTT_STR_2_THD_BASE_LOC_ADDR        (REG_NATT_BASE_ADDR+0x0000022C)
#define NATT_NTT_STR_2_THD_BASE_LOC_OFFSET      0x0000022C
#define NATT_NTT_STR_2_THD_BASE_LOC_INDEX       0x0000008B
#define NATT_NTT_STR_2_THD_BASE_LOC_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_thd_base_loc_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_THD_BASE_LOC_ADDR);
}

__INLINE void natt_ntt_str_2_thd_base_loc_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_2_THD_BASE_LOC_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_2_THD_BASE_LOC_NTT_THD_LOC_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_2_THD_BASE_LOC_NTT_THD_LOC_LSB    0
#define NATT_NTT_STR_2_THD_BASE_LOC_NTT_THD_LOC_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_2_THD_BASE_LOC_NTT_THD_LOC_RST    0x0

__INLINE uint32_t natt_ntt_str_2_thd_base_loc_ntt_thd_loc_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_THD_BASE_LOC_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_2_thd_base_loc_ntt_thd_loc_setf(uint32_t nttthdloc)
{
	ASSERT_ERR((((uint32_t)nttthdloc << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_THD_BASE_LOC_ADDR, (uint32_t)nttthdloc << 0);
}

/**
 * @brief NTT_STR_2_CR_INFO register definition
 *  End of process closing reason register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05:00 NTT_CR_INFO               0x0
 * </pre>
 */
#define NATT_NTT_STR_2_CR_INFO_ADDR        (REG_NATT_BASE_ADDR+0x00000230)
#define NATT_NTT_STR_2_CR_INFO_OFFSET      0x00000230
#define NATT_NTT_STR_2_CR_INFO_INDEX       0x0000008C
#define NATT_NTT_STR_2_CR_INFO_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_cr_info_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_CR_INFO_ADDR);
}

// field definitions
#define NATT_NTT_STR_2_CR_INFO_NTT_CR_INFO_MASK    ((uint32_t)0x0000003F)
#define NATT_NTT_STR_2_CR_INFO_NTT_CR_INFO_LSB    0
#define NATT_NTT_STR_2_CR_INFO_NTT_CR_INFO_WIDTH    ((uint32_t)0x00000006)

#define NATT_NTT_STR_2_CR_INFO_NTT_CR_INFO_RST    0x0

__INLINE uint8_t natt_ntt_str_2_cr_info_ntt_cr_info_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_CR_INFO_ADDR);
	return (uint8_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_2_LD_INFO register definition
 *  End of process last description address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_LD_INFO               0x0
 * </pre>
 */
#define NATT_NTT_STR_2_LD_INFO_ADDR        (REG_NATT_BASE_ADDR+0x00000234)
#define NATT_NTT_STR_2_LD_INFO_OFFSET      0x00000234
#define NATT_NTT_STR_2_LD_INFO_INDEX       0x0000008D
#define NATT_NTT_STR_2_LD_INFO_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_ld_info_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_LD_INFO_ADDR);
}

// field definitions
#define NATT_NTT_STR_2_LD_INFO_NTT_LD_INFO_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_2_LD_INFO_NTT_LD_INFO_LSB    0
#define NATT_NTT_STR_2_LD_INFO_NTT_LD_INFO_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_2_LD_INFO_NTT_LD_INFO_RST    0x0

__INLINE uint32_t natt_ntt_str_2_ld_info_ntt_ld_info_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_LD_INFO_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_2_NON_DATA_INFO_1 register definition
 *  Number length and padding of nonDATA MPDUs register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17:16 NTT_NON_DATA1_PAD         0x0
 *    15:12 NTT_NON_DATA1_NUM         0x0
 *    09:00 NTT_NON_DATA1_LEN         0x0
 * </pre>
 */
#define NATT_NTT_STR_2_NON_DATA_INFO_1_ADDR        (REG_NATT_BASE_ADDR+0x00000260)
#define NATT_NTT_STR_2_NON_DATA_INFO_1_OFFSET      0x00000260
#define NATT_NTT_STR_2_NON_DATA_INFO_1_INDEX       0x00000098
#define NATT_NTT_STR_2_NON_DATA_INFO_1_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_non_data_info_1_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_NON_DATA_INFO_1_ADDR);
}

__INLINE void natt_ntt_str_2_non_data_info_1_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_2_NON_DATA_INFO_1_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_2_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_MASK    ((uint32_t)0x00030000)
#define NATT_NTT_STR_2_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_LSB    16
#define NATT_NTT_STR_2_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_WIDTH    ((uint32_t)0x00000002)
#define NATT_NTT_STR_2_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_MASK    ((uint32_t)0x0000F000)
#define NATT_NTT_STR_2_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_LSB    12
#define NATT_NTT_STR_2_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_WIDTH    ((uint32_t)0x00000004)
#define NATT_NTT_STR_2_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_MASK    ((uint32_t)0x000003FF)
#define NATT_NTT_STR_2_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_LSB    0
#define NATT_NTT_STR_2_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_WIDTH    ((uint32_t)0x0000000A)

#define NATT_NTT_STR_2_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_RST    0x0
#define NATT_NTT_STR_2_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_RST    0x0
#define NATT_NTT_STR_2_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_RST    0x0

__INLINE void natt_ntt_str_2_non_data_info_1_pack(uint8_t ntt_non_data1_pad, uint8_t ntt_non_data1_num, uint16_t ntt_non_data1_len)
{
	ASSERT_ERR((((uint32_t)ntt_non_data1_pad << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data1_num << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data1_len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_NON_DATA_INFO_1_ADDR,  ((uint32_t)ntt_non_data1_pad << 16) |((uint32_t)ntt_non_data1_num << 12) |((uint32_t)ntt_non_data1_len << 0));
}

__INLINE void natt_ntt_str_2_non_data_info_1_unpack(uint8_t* ntt_non_data1_pad, uint8_t* ntt_non_data1_num, uint16_t* ntt_non_data1_len)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_NON_DATA_INFO_1_ADDR);

	*ntt_non_data1_pad = (localVal & ((uint32_t)0x00030000)) >>  16;
	*ntt_non_data1_num = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*ntt_non_data1_len = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint8_t natt_ntt_str_2_non_data_info_1_ntt_non_data_1_pad_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_NON_DATA_INFO_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void natt_ntt_str_2_non_data_info_1_ntt_non_data_1_pad_setf(uint8_t nttnondata1pad)
{
	ASSERT_ERR((((uint32_t)nttnondata1pad << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_NON_DATA_INFO_1_ADDR, (REG_PL_RD(NATT_NTT_STR_2_NON_DATA_INFO_1_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)nttnondata1pad <<16));
}
__INLINE uint8_t natt_ntt_str_2_non_data_info_1_ntt_non_data_1_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_NON_DATA_INFO_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void natt_ntt_str_2_non_data_info_1_ntt_non_data_1_num_setf(uint8_t nttnondata1num)
{
	ASSERT_ERR((((uint32_t)nttnondata1num << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_NON_DATA_INFO_1_ADDR, (REG_PL_RD(NATT_NTT_STR_2_NON_DATA_INFO_1_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)nttnondata1num <<12));
}
__INLINE uint16_t natt_ntt_str_2_non_data_info_1_ntt_non_data_1_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_NON_DATA_INFO_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void natt_ntt_str_2_non_data_info_1_ntt_non_data_1_len_setf(uint16_t nttnondata1len)
{
	ASSERT_ERR((((uint32_t)nttnondata1len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_NON_DATA_INFO_1_ADDR, (REG_PL_RD(NATT_NTT_STR_2_NON_DATA_INFO_1_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)nttnondata1len <<0));
}

/**
 * @brief NTT_STR_2_NON_DATA_INFO_2 register definition
 *  Number length and padding of nonDATA MPDUs register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17:16 NTT_NON_DATA2_PAD         0x0
 *    15:12 NTT_NON_DATA2_NUM         0x0
 *    09:00 NTT_NON_DATA2_LEN         0x0
 * </pre>
 */
#define NATT_NTT_STR_2_NON_DATA_INFO_2_ADDR        (REG_NATT_BASE_ADDR+0x00000264)
#define NATT_NTT_STR_2_NON_DATA_INFO_2_OFFSET      0x00000264
#define NATT_NTT_STR_2_NON_DATA_INFO_2_INDEX       0x00000099
#define NATT_NTT_STR_2_NON_DATA_INFO_2_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_non_data_info_2_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_NON_DATA_INFO_2_ADDR);
}

__INLINE void natt_ntt_str_2_non_data_info_2_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_2_NON_DATA_INFO_2_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_2_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_MASK    ((uint32_t)0x00030000)
#define NATT_NTT_STR_2_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_LSB    16
#define NATT_NTT_STR_2_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_WIDTH    ((uint32_t)0x00000002)
#define NATT_NTT_STR_2_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_MASK    ((uint32_t)0x0000F000)
#define NATT_NTT_STR_2_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_LSB    12
#define NATT_NTT_STR_2_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_WIDTH    ((uint32_t)0x00000004)
#define NATT_NTT_STR_2_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_MASK    ((uint32_t)0x000003FF)
#define NATT_NTT_STR_2_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_LSB    0
#define NATT_NTT_STR_2_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_WIDTH    ((uint32_t)0x0000000A)

#define NATT_NTT_STR_2_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_RST    0x0
#define NATT_NTT_STR_2_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_RST    0x0
#define NATT_NTT_STR_2_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_RST    0x0

__INLINE void natt_ntt_str_2_non_data_info_2_pack(uint8_t ntt_non_data2_pad, uint8_t ntt_non_data2_num, uint16_t ntt_non_data2_len)
{
	ASSERT_ERR((((uint32_t)ntt_non_data2_pad << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data2_num << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data2_len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_NON_DATA_INFO_2_ADDR,  ((uint32_t)ntt_non_data2_pad << 16) |((uint32_t)ntt_non_data2_num << 12) |((uint32_t)ntt_non_data2_len << 0));
}

__INLINE void natt_ntt_str_2_non_data_info_2_unpack(uint8_t* ntt_non_data2_pad, uint8_t* ntt_non_data2_num, uint16_t* ntt_non_data2_len)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_NON_DATA_INFO_2_ADDR);

	*ntt_non_data2_pad = (localVal & ((uint32_t)0x00030000)) >>  16;
	*ntt_non_data2_num = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*ntt_non_data2_len = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint8_t natt_ntt_str_2_non_data_info_2_ntt_non_data_2_pad_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_NON_DATA_INFO_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void natt_ntt_str_2_non_data_info_2_ntt_non_data_2_pad_setf(uint8_t nttnondata2pad)
{
	ASSERT_ERR((((uint32_t)nttnondata2pad << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_NON_DATA_INFO_2_ADDR, (REG_PL_RD(NATT_NTT_STR_2_NON_DATA_INFO_2_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)nttnondata2pad <<16));
}
__INLINE uint8_t natt_ntt_str_2_non_data_info_2_ntt_non_data_2_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_NON_DATA_INFO_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void natt_ntt_str_2_non_data_info_2_ntt_non_data_2_num_setf(uint8_t nttnondata2num)
{
	ASSERT_ERR((((uint32_t)nttnondata2num << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_NON_DATA_INFO_2_ADDR, (REG_PL_RD(NATT_NTT_STR_2_NON_DATA_INFO_2_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)nttnondata2num <<12));
}
__INLINE uint16_t natt_ntt_str_2_non_data_info_2_ntt_non_data_2_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_NON_DATA_INFO_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void natt_ntt_str_2_non_data_info_2_ntt_non_data_2_len_setf(uint16_t nttnondata2len)
{
	ASSERT_ERR((((uint32_t)nttnondata2len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_NON_DATA_INFO_2_ADDR, (REG_PL_RD(NATT_NTT_STR_2_NON_DATA_INFO_2_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)nttnondata2len <<0));
}

/**
 * @brief NTT_STR_2_NON_DATA_1_RESULT register definition
 *  ZLDs and padding_in_bytes results for nonData register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 NTT_NON_DATA1_PADDING_IN_BYTES 0x0
 *    15:00 NTT_NON_DATA1_ZLD         0x0
 * </pre>
 */
#define NATT_NTT_STR_2_NON_DATA_1_RESULT_ADDR        (REG_NATT_BASE_ADDR+0x00000268)
#define NATT_NTT_STR_2_NON_DATA_1_RESULT_OFFSET      0x00000268
#define NATT_NTT_STR_2_NON_DATA_1_RESULT_INDEX       0x0000009A
#define NATT_NTT_STR_2_NON_DATA_1_RESULT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_non_data_1_result_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_NON_DATA_1_RESULT_ADDR);
}

// field definitions
#define NATT_NTT_STR_2_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_MASK    ((uint32_t)0xFFFF0000)
#define NATT_NTT_STR_2_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_LSB    16
#define NATT_NTT_STR_2_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_WIDTH    ((uint32_t)0x00000010)
#define NATT_NTT_STR_2_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_2_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_LSB    0
#define NATT_NTT_STR_2_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_2_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_RST    0x0
#define NATT_NTT_STR_2_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_RST    0x0

__INLINE void natt_ntt_str_2_non_data_1_result_unpack(uint16_t* ntt_non_data1_padding_in_bytes, uint16_t* ntt_non_data1_zld)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_NON_DATA_1_RESULT_ADDR);

	*ntt_non_data1_padding_in_bytes = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ntt_non_data1_zld = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t natt_ntt_str_2_non_data_1_result_ntt_non_data_1_padding_in_bytes_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_NON_DATA_1_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t natt_ntt_str_2_non_data_1_result_ntt_non_data_1_zld_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_NON_DATA_1_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief NTT_STR_2_NON_DATA_2_RESULT register definition
 *  ZLDs and padding_in_bytes results for nonData register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 NTT_NON_DATA2_PADDING_IN_BYTES 0x0
 *    15:00 TT_NON_DATA2_ZLD          0x0
 * </pre>
 */
#define NATT_NTT_STR_2_NON_DATA_2_RESULT_ADDR        (REG_NATT_BASE_ADDR+0x0000026C)
#define NATT_NTT_STR_2_NON_DATA_2_RESULT_OFFSET      0x0000026C
#define NATT_NTT_STR_2_NON_DATA_2_RESULT_INDEX       0x0000009B
#define NATT_NTT_STR_2_NON_DATA_2_RESULT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_non_data_2_result_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_NON_DATA_2_RESULT_ADDR);
}

// field definitions
#define NATT_NTT_STR_2_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_MASK    ((uint32_t)0xFFFF0000)
#define NATT_NTT_STR_2_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_LSB    16
#define NATT_NTT_STR_2_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_WIDTH    ((uint32_t)0x00000010)
#define NATT_NTT_STR_2_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_2_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_LSB    0
#define NATT_NTT_STR_2_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_2_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_RST    0x0
#define NATT_NTT_STR_2_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_RST    0x0

__INLINE void natt_ntt_str_2_non_data_2_result_unpack(uint16_t* ntt_non_data2_padding_in_bytes, uint16_t* tt_non_data2_zld)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_NON_DATA_2_RESULT_ADDR);

	*ntt_non_data2_padding_in_bytes = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*tt_non_data2_zld = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t natt_ntt_str_2_non_data_2_result_ntt_non_data_2_padding_in_bytes_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_NON_DATA_2_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t natt_ntt_str_2_non_data_2_result_tt_non_data_2_zld_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_NON_DATA_2_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief NTT_STR_2_MIN_SPACING_CONF register definition
 *  Min_spacing parameters for STA capabilities register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    FORCE_MIN_SPACING         0              
 *    07:04 MIN_SPACING_FACTOR        0x0
 *    03:00 MIN_SPACING               0x0
 * </pre>
 */
#define NATT_NTT_STR_2_MIN_SPACING_CONF_ADDR        (REG_NATT_BASE_ADDR+0x00000270)
#define NATT_NTT_STR_2_MIN_SPACING_CONF_OFFSET      0x00000270
#define NATT_NTT_STR_2_MIN_SPACING_CONF_INDEX       0x0000009C
#define NATT_NTT_STR_2_MIN_SPACING_CONF_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_min_spacing_conf_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_MIN_SPACING_CONF_ADDR);
}

__INLINE void natt_ntt_str_2_min_spacing_conf_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_2_MIN_SPACING_CONF_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_2_MIN_SPACING_CONF_FORCE_MIN_SPACING_BIT    ((uint32_t)0x80000000)
#define NATT_NTT_STR_2_MIN_SPACING_CONF_FORCE_MIN_SPACING_POS    31
#define NATT_NTT_STR_2_MIN_SPACING_CONF_MIN_SPACING_FACTOR_MASK    ((uint32_t)0x000000F0)
#define NATT_NTT_STR_2_MIN_SPACING_CONF_MIN_SPACING_FACTOR_LSB    4
#define NATT_NTT_STR_2_MIN_SPACING_CONF_MIN_SPACING_FACTOR_WIDTH    ((uint32_t)0x00000004)
#define NATT_NTT_STR_2_MIN_SPACING_CONF_MIN_SPACING_MASK    ((uint32_t)0x0000000F)
#define NATT_NTT_STR_2_MIN_SPACING_CONF_MIN_SPACING_LSB    0
#define NATT_NTT_STR_2_MIN_SPACING_CONF_MIN_SPACING_WIDTH    ((uint32_t)0x00000004)

#define NATT_NTT_STR_2_MIN_SPACING_CONF_FORCE_MIN_SPACING_RST    0x0
#define NATT_NTT_STR_2_MIN_SPACING_CONF_MIN_SPACING_FACTOR_RST    0x0
#define NATT_NTT_STR_2_MIN_SPACING_CONF_MIN_SPACING_RST    0x0

__INLINE void natt_ntt_str_2_min_spacing_conf_pack(uint8_t force_min_spacing, uint8_t min_spacing_factor, uint8_t min_spacing)
{
	ASSERT_ERR((((uint32_t)force_min_spacing << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)min_spacing_factor << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)min_spacing << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_MIN_SPACING_CONF_ADDR,  ((uint32_t)force_min_spacing << 31) |((uint32_t)min_spacing_factor << 4) |((uint32_t)min_spacing << 0));
}

__INLINE void natt_ntt_str_2_min_spacing_conf_unpack(uint8_t* force_min_spacing, uint8_t* min_spacing_factor, uint8_t* min_spacing)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_MIN_SPACING_CONF_ADDR);

	*force_min_spacing = (localVal & ((uint32_t)0x80000000)) >>  31;
	*min_spacing_factor = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*min_spacing = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t natt_ntt_str_2_min_spacing_conf_force_min_spacing_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_MIN_SPACING_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void natt_ntt_str_2_min_spacing_conf_force_min_spacing_setf(uint8_t forceminspacing)
{
	ASSERT_ERR((((uint32_t)forceminspacing << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_MIN_SPACING_CONF_ADDR, (REG_PL_RD(NATT_NTT_STR_2_MIN_SPACING_CONF_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)forceminspacing <<31));
}
__INLINE uint8_t natt_ntt_str_2_min_spacing_conf_min_spacing_factor_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_MIN_SPACING_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void natt_ntt_str_2_min_spacing_conf_min_spacing_factor_setf(uint8_t minspacingfactor)
{
	ASSERT_ERR((((uint32_t)minspacingfactor << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_MIN_SPACING_CONF_ADDR, (REG_PL_RD(NATT_NTT_STR_2_MIN_SPACING_CONF_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)minspacingfactor <<4));
}
__INLINE uint8_t natt_ntt_str_2_min_spacing_conf_min_spacing_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_MIN_SPACING_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void natt_ntt_str_2_min_spacing_conf_min_spacing_setf(uint8_t minspacing)
{
	ASSERT_ERR((((uint32_t)minspacing << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_MIN_SPACING_CONF_ADDR, (REG_PL_RD(NATT_NTT_STR_2_MIN_SPACING_CONF_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)minspacing <<0));
}

/**
 * @brief NTT_STR_2_DBG_CNT register definition
 *  Debug commands counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DBG_CNT               0x0
 * </pre>
 */
#define NATT_NTT_STR_2_DBG_CNT_ADDR        (REG_NATT_BASE_ADDR+0x00000274)
#define NATT_NTT_STR_2_DBG_CNT_OFFSET      0x00000274
#define NATT_NTT_STR_2_DBG_CNT_INDEX       0x0000009D
#define NATT_NTT_STR_2_DBG_CNT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_dbg_cnt_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_DBG_CNT_ADDR);
}

__INLINE void natt_ntt_str_2_dbg_cnt_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_2_DBG_CNT_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_2_DBG_CNT_NTT_DBG_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_2_DBG_CNT_NTT_DBG_CNT_LSB    0
#define NATT_NTT_STR_2_DBG_CNT_NTT_DBG_CNT_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_2_DBG_CNT_NTT_DBG_CNT_RST    0x0

__INLINE uint32_t natt_ntt_str_2_dbg_cnt_ntt_dbg_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_DBG_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_2_dbg_cnt_ntt_dbg_cnt_setf(uint32_t nttdbgcnt)
{
	ASSERT_ERR((((uint32_t)nttdbgcnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_2_DBG_CNT_ADDR, (uint32_t)nttdbgcnt << 0);
}

/**
 * @brief NTT_STR_2_PHY_RATE register definition
 *  Debug results of last packet (ndps+rate) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 NTT_PHY_RATE              0x0
 * </pre>
 */
#define NATT_NTT_STR_2_PHY_RATE_ADDR        (REG_NATT_BASE_ADDR+0x00000278)
#define NATT_NTT_STR_2_PHY_RATE_OFFSET      0x00000278
#define NATT_NTT_STR_2_PHY_RATE_INDEX       0x0000009E
#define NATT_NTT_STR_2_PHY_RATE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_phy_rate_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_PHY_RATE_ADDR);
}

// field definitions
#define NATT_NTT_STR_2_PHY_RATE_NTT_PHY_RATE_MASK    ((uint32_t)0x000FFFFF)
#define NATT_NTT_STR_2_PHY_RATE_NTT_PHY_RATE_LSB    0
#define NATT_NTT_STR_2_PHY_RATE_NTT_PHY_RATE_WIDTH    ((uint32_t)0x00000014)

#define NATT_NTT_STR_2_PHY_RATE_NTT_PHY_RATE_RST    0x0

__INLINE uint32_t natt_ntt_str_2_phy_rate_ntt_phy_rate_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_PHY_RATE_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_2_NDBPS register definition
 *  Number of data bits per symbol register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 NTT_NDBPS                 0x0
 * </pre>
 */
#define NATT_NTT_STR_2_NDBPS_ADDR        (REG_NATT_BASE_ADDR+0x0000027C)
#define NATT_NTT_STR_2_NDBPS_OFFSET      0x0000027C
#define NATT_NTT_STR_2_NDBPS_INDEX       0x0000009F
#define NATT_NTT_STR_2_NDBPS_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_ndbps_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_NDBPS_ADDR);
}

// field definitions
#define NATT_NTT_STR_2_NDBPS_NTT_NDBPS_MASK    ((uint32_t)0x000FFFFF)
#define NATT_NTT_STR_2_NDBPS_NTT_NDBPS_LSB    0
#define NATT_NTT_STR_2_NDBPS_NTT_NDBPS_WIDTH    ((uint32_t)0x00000014)

#define NATT_NTT_STR_2_NDBPS_NTT_NDBPS_RST    0x0

__INLINE uint32_t natt_ntt_str_2_ndbps_ntt_ndbps_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_NDBPS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_2_SYM_TIME register definition
 *  Debug results of last packet (symbols+datatime) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 NTT_SYMBOLS               0x0
 *    15:00 NTT_DAT_TIME              0x0
 * </pre>
 */
#define NATT_NTT_STR_2_SYM_TIME_ADDR        (REG_NATT_BASE_ADDR+0x00000280)
#define NATT_NTT_STR_2_SYM_TIME_OFFSET      0x00000280
#define NATT_NTT_STR_2_SYM_TIME_INDEX       0x000000A0
#define NATT_NTT_STR_2_SYM_TIME_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_sym_time_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_SYM_TIME_ADDR);
}

// field definitions
#define NATT_NTT_STR_2_SYM_TIME_NTT_SYMBOLS_MASK    ((uint32_t)0xFFFF0000)
#define NATT_NTT_STR_2_SYM_TIME_NTT_SYMBOLS_LSB    16
#define NATT_NTT_STR_2_SYM_TIME_NTT_SYMBOLS_WIDTH    ((uint32_t)0x00000010)
#define NATT_NTT_STR_2_SYM_TIME_NTT_DAT_TIME_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_2_SYM_TIME_NTT_DAT_TIME_LSB    0
#define NATT_NTT_STR_2_SYM_TIME_NTT_DAT_TIME_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_2_SYM_TIME_NTT_SYMBOLS_RST    0x0
#define NATT_NTT_STR_2_SYM_TIME_NTT_DAT_TIME_RST    0x0

__INLINE void natt_ntt_str_2_sym_time_unpack(uint16_t* ntt_symbols, uint16_t* ntt_dat_time)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_SYM_TIME_ADDR);

	*ntt_symbols = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ntt_dat_time = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t natt_ntt_str_2_sym_time_ntt_symbols_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_SYM_TIME_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t natt_ntt_str_2_sym_time_ntt_dat_time_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_SYM_TIME_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief NTT_STR_2_TOT_TIME register definition
 *  Debug results of last packet (total time) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 NTT_TOT_TIME              0x0
 * </pre>
 */
#define NATT_NTT_STR_2_TOT_TIME_ADDR        (REG_NATT_BASE_ADDR+0x00000284)
#define NATT_NTT_STR_2_TOT_TIME_OFFSET      0x00000284
#define NATT_NTT_STR_2_TOT_TIME_INDEX       0x000000A1
#define NATT_NTT_STR_2_TOT_TIME_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_tot_time_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_TOT_TIME_ADDR);
}

// field definitions
#define NATT_NTT_STR_2_TOT_TIME_NTT_TOT_TIME_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_2_TOT_TIME_NTT_TOT_TIME_LSB    0
#define NATT_NTT_STR_2_TOT_TIME_NTT_TOT_TIME_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_2_TOT_TIME_NTT_TOT_TIME_RST    0x0

__INLINE uint16_t natt_ntt_str_2_tot_time_ntt_tot_time_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_TOT_TIME_ADDR);
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_2_MPDU_NUM register definition
 *  Debug results of last packet (number of MPDUs) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    08:00 NTT_MPDU_NUM              0x0
 * </pre>
 */
#define NATT_NTT_STR_2_MPDU_NUM_ADDR        (REG_NATT_BASE_ADDR+0x00000288)
#define NATT_NTT_STR_2_MPDU_NUM_OFFSET      0x00000288
#define NATT_NTT_STR_2_MPDU_NUM_INDEX       0x000000A2
#define NATT_NTT_STR_2_MPDU_NUM_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_mpdu_num_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_MPDU_NUM_ADDR);
}

// field definitions
#define NATT_NTT_STR_2_MPDU_NUM_NTT_MPDU_NUM_MASK    ((uint32_t)0x000001FF)
#define NATT_NTT_STR_2_MPDU_NUM_NTT_MPDU_NUM_LSB    0
#define NATT_NTT_STR_2_MPDU_NUM_NTT_MPDU_NUM_WIDTH    ((uint32_t)0x00000009)

#define NATT_NTT_STR_2_MPDU_NUM_NTT_MPDU_NUM_RST    0x0

__INLINE uint16_t natt_ntt_str_2_mpdu_num_ntt_mpdu_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_MPDU_NUM_ADDR);
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_2_AMPDU_LEN register definition
 *  AMPDU actual length in bytes register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:00 NTT_AMPDU_LEN             0x0
 * </pre>
 */
#define NATT_NTT_STR_2_AMPDU_LEN_ADDR        (REG_NATT_BASE_ADDR+0x0000028C)
#define NATT_NTT_STR_2_AMPDU_LEN_OFFSET      0x0000028C
#define NATT_NTT_STR_2_AMPDU_LEN_INDEX       0x000000A3
#define NATT_NTT_STR_2_AMPDU_LEN_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_ampdu_len_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_AMPDU_LEN_ADDR);
}

// field definitions
#define NATT_NTT_STR_2_AMPDU_LEN_NTT_AMPDU_LEN_MASK    ((uint32_t)0x00FFFFFF)
#define NATT_NTT_STR_2_AMPDU_LEN_NTT_AMPDU_LEN_LSB    0
#define NATT_NTT_STR_2_AMPDU_LEN_NTT_AMPDU_LEN_WIDTH    ((uint32_t)0x00000018)

#define NATT_NTT_STR_2_AMPDU_LEN_NTT_AMPDU_LEN_RST    0x0

__INLINE uint32_t natt_ntt_str_2_ampdu_len_ntt_ampdu_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_AMPDU_LEN_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_2_MAX_AMPDU_LEN register definition
 *  MAX AMPDU Length in bytes register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:00 NTT_MAX_AMPDU_LEN         0x0
 * </pre>
 */
#define NATT_NTT_STR_2_MAX_AMPDU_LEN_ADDR        (REG_NATT_BASE_ADDR+0x00000290)
#define NATT_NTT_STR_2_MAX_AMPDU_LEN_OFFSET      0x00000290
#define NATT_NTT_STR_2_MAX_AMPDU_LEN_INDEX       0x000000A4
#define NATT_NTT_STR_2_MAX_AMPDU_LEN_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_2_max_ampdu_len_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_2_MAX_AMPDU_LEN_ADDR);
}

// field definitions
#define NATT_NTT_STR_2_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_MASK    ((uint32_t)0x00FFFFFF)
#define NATT_NTT_STR_2_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_LSB    0
#define NATT_NTT_STR_2_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_WIDTH    ((uint32_t)0x00000018)

#define NATT_NTT_STR_2_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_RST    0x0

__INLINE uint32_t natt_ntt_str_2_max_ampdu_len_ntt_max_ampdu_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_2_MAX_AMPDU_LEN_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_3_PT_BASE register definition
 *  Policy Table register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_PT_BASE               0x0
 * </pre>
 */
#define NATT_NTT_STR_3_PT_BASE_ADDR        (REG_NATT_BASE_ADDR+0x0000030C)
#define NATT_NTT_STR_3_PT_BASE_OFFSET      0x0000030C
#define NATT_NTT_STR_3_PT_BASE_INDEX       0x000000C3
#define NATT_NTT_STR_3_PT_BASE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_pt_base_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_PT_BASE_ADDR);
}

__INLINE void natt_ntt_str_3_pt_base_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_3_PT_BASE_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_3_PT_BASE_NTT_PT_BASE_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_3_PT_BASE_NTT_PT_BASE_LSB    0
#define NATT_NTT_STR_3_PT_BASE_NTT_PT_BASE_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_3_PT_BASE_NTT_PT_BASE_RST    0x0

__INLINE uint32_t natt_ntt_str_3_pt_base_ntt_pt_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_PT_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_3_pt_base_ntt_pt_base_setf(uint32_t nttptbase)
{
	ASSERT_ERR((((uint32_t)nttptbase << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_PT_BASE_ADDR, (uint32_t)nttptbase << 0);
}

/**
 * @brief NTT_STR_3_DESC_BASE register definition
 *  Descriptors chain base address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DESC_BASE             0x0
 * </pre>
 */
#define NATT_NTT_STR_3_DESC_BASE_ADDR        (REG_NATT_BASE_ADDR+0x00000310)
#define NATT_NTT_STR_3_DESC_BASE_OFFSET      0x00000310
#define NATT_NTT_STR_3_DESC_BASE_INDEX       0x000000C4
#define NATT_NTT_STR_3_DESC_BASE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_desc_base_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_DESC_BASE_ADDR);
}

__INLINE void natt_ntt_str_3_desc_base_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_3_DESC_BASE_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_3_DESC_BASE_NTT_DESC_BASE_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_3_DESC_BASE_NTT_DESC_BASE_LSB    0
#define NATT_NTT_STR_3_DESC_BASE_NTT_DESC_BASE_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_3_DESC_BASE_NTT_DESC_BASE_RST    0x0

__INLINE uint32_t natt_ntt_str_3_desc_base_ntt_desc_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_DESC_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_3_desc_base_ntt_desc_base_setf(uint32_t nttdescbase)
{
	ASSERT_ERR((((uint32_t)nttdescbase << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_DESC_BASE_ADDR, (uint32_t)nttdescbase << 0);
}

/**
 * @brief NTT_STR_3_DESC_TSIZE register definition
 *  Total descriptors chain size register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DESC_TSIZE            0x0
 * </pre>
 */
#define NATT_NTT_STR_3_DESC_TSIZE_ADDR        (REG_NATT_BASE_ADDR+0x0000031C)
#define NATT_NTT_STR_3_DESC_TSIZE_OFFSET      0x0000031C
#define NATT_NTT_STR_3_DESC_TSIZE_INDEX       0x000000C7
#define NATT_NTT_STR_3_DESC_TSIZE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_desc_tsize_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_DESC_TSIZE_ADDR);
}

__INLINE void natt_ntt_str_3_desc_tsize_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_3_DESC_TSIZE_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_3_DESC_TSIZE_NTT_DESC_TSIZE_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_3_DESC_TSIZE_NTT_DESC_TSIZE_LSB    0
#define NATT_NTT_STR_3_DESC_TSIZE_NTT_DESC_TSIZE_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_3_DESC_TSIZE_NTT_DESC_TSIZE_RST    0x0

__INLINE uint32_t natt_ntt_str_3_desc_tsize_ntt_desc_tsize_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_DESC_TSIZE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_3_desc_tsize_ntt_desc_tsize_setf(uint32_t nttdesctsize)
{
	ASSERT_ERR((((uint32_t)nttdesctsize << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_DESC_TSIZE_ADDR, (uint32_t)nttdesctsize << 0);
}

/**
 * @brief NTT_STR_3_DESC_START register definition
 *  Descriptors chain start address (1st MPDU) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DESC_START            0x0
 * </pre>
 */
#define NATT_NTT_STR_3_DESC_START_ADDR        (REG_NATT_BASE_ADDR+0x00000320)
#define NATT_NTT_STR_3_DESC_START_OFFSET      0x00000320
#define NATT_NTT_STR_3_DESC_START_INDEX       0x000000C8
#define NATT_NTT_STR_3_DESC_START_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_desc_start_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_DESC_START_ADDR);
}

__INLINE void natt_ntt_str_3_desc_start_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_3_DESC_START_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_3_DESC_START_NTT_DESC_START_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_3_DESC_START_NTT_DESC_START_LSB    0
#define NATT_NTT_STR_3_DESC_START_NTT_DESC_START_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_3_DESC_START_NTT_DESC_START_RST    0x0

__INLINE uint32_t natt_ntt_str_3_desc_start_ntt_desc_start_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_DESC_START_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_3_desc_start_ntt_desc_start_setf(uint32_t nttdescstart)
{
	ASSERT_ERR((((uint32_t)nttdescstart << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_DESC_START_ADDR, (uint32_t)nttdescstart << 0);
}

/**
 * @brief NTT_STR_3_AIRTIME_LIMIT register definition
 *  AirTime Limit in usec register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 NTT_AIRTIME_LIMIT         0x0
 * </pre>
 */
#define NATT_NTT_STR_3_AIRTIME_LIMIT_ADDR        (REG_NATT_BASE_ADDR+0x00000324)
#define NATT_NTT_STR_3_AIRTIME_LIMIT_OFFSET      0x00000324
#define NATT_NTT_STR_3_AIRTIME_LIMIT_INDEX       0x000000C9
#define NATT_NTT_STR_3_AIRTIME_LIMIT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_airtime_limit_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_AIRTIME_LIMIT_ADDR);
}

__INLINE void natt_ntt_str_3_airtime_limit_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_3_AIRTIME_LIMIT_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_3_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_3_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_LSB    0
#define NATT_NTT_STR_3_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_3_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_RST    0x0

__INLINE uint16_t natt_ntt_str_3_airtime_limit_ntt_airtime_limit_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_AIRTIME_LIMIT_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_3_airtime_limit_ntt_airtime_limit_setf(uint16_t nttairtimelimit)
{
	ASSERT_ERR((((uint32_t)nttairtimelimit << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_AIRTIME_LIMIT_ADDR, (uint32_t)nttairtimelimit << 0);
}

/**
 * @brief NTT_STR_3_MPDU_LIMIT register definition
 *  BA and valid MPDUs limit register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:24 NTT_STA_INDEX             0x0
 *    20:12 NTT_MAX_MPDU              0x0
 *    08:00 NTT_BA_WINDOW             0x0
 * </pre>
 */
#define NATT_NTT_STR_3_MPDU_LIMIT_ADDR        (REG_NATT_BASE_ADDR+0x00000328)
#define NATT_NTT_STR_3_MPDU_LIMIT_OFFSET      0x00000328
#define NATT_NTT_STR_3_MPDU_LIMIT_INDEX       0x000000CA
#define NATT_NTT_STR_3_MPDU_LIMIT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_mpdu_limit_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_MPDU_LIMIT_ADDR);
}

__INLINE void natt_ntt_str_3_mpdu_limit_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_3_MPDU_LIMIT_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_3_MPDU_LIMIT_NTT_STA_INDEX_MASK    ((uint32_t)0x7F000000)
#define NATT_NTT_STR_3_MPDU_LIMIT_NTT_STA_INDEX_LSB    24
#define NATT_NTT_STR_3_MPDU_LIMIT_NTT_STA_INDEX_WIDTH    ((uint32_t)0x00000007)
#define NATT_NTT_STR_3_MPDU_LIMIT_NTT_MAX_MPDU_MASK    ((uint32_t)0x001FF000)
#define NATT_NTT_STR_3_MPDU_LIMIT_NTT_MAX_MPDU_LSB    12
#define NATT_NTT_STR_3_MPDU_LIMIT_NTT_MAX_MPDU_WIDTH    ((uint32_t)0x00000009)
#define NATT_NTT_STR_3_MPDU_LIMIT_NTT_BA_WINDOW_MASK    ((uint32_t)0x000001FF)
#define NATT_NTT_STR_3_MPDU_LIMIT_NTT_BA_WINDOW_LSB    0
#define NATT_NTT_STR_3_MPDU_LIMIT_NTT_BA_WINDOW_WIDTH    ((uint32_t)0x00000009)

#define NATT_NTT_STR_3_MPDU_LIMIT_NTT_STA_INDEX_RST    0x0
#define NATT_NTT_STR_3_MPDU_LIMIT_NTT_MAX_MPDU_RST    0x0
#define NATT_NTT_STR_3_MPDU_LIMIT_NTT_BA_WINDOW_RST    0x0

__INLINE void natt_ntt_str_3_mpdu_limit_pack(uint8_t ntt_sta_index, uint16_t ntt_max_mpdu, uint16_t ntt_ba_window)
{
	ASSERT_ERR((((uint32_t)ntt_sta_index << 24) & ~((uint32_t)0x7F000000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_max_mpdu << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_ba_window << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_MPDU_LIMIT_ADDR,  ((uint32_t)ntt_sta_index << 24) |((uint32_t)ntt_max_mpdu << 12) |((uint32_t)ntt_ba_window << 0));
}

__INLINE void natt_ntt_str_3_mpdu_limit_unpack(uint8_t* ntt_sta_index, uint16_t* ntt_max_mpdu, uint16_t* ntt_ba_window)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_MPDU_LIMIT_ADDR);

	*ntt_sta_index = (localVal & ((uint32_t)0x7F000000)) >>  24;
	*ntt_max_mpdu = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*ntt_ba_window = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t natt_ntt_str_3_mpdu_limit_ntt_sta_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_MPDU_LIMIT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x7F000000)) >> 24);
}
__INLINE void natt_ntt_str_3_mpdu_limit_ntt_sta_index_setf(uint8_t nttstaindex)
{
	ASSERT_ERR((((uint32_t)nttstaindex << 24) & ~((uint32_t)0x7F000000)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_MPDU_LIMIT_ADDR, (REG_PL_RD(NATT_NTT_STR_3_MPDU_LIMIT_ADDR) & ~((uint32_t)0x7F000000)) | ((uint32_t)nttstaindex <<24));
}
__INLINE uint16_t natt_ntt_str_3_mpdu_limit_ntt_max_mpdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_MPDU_LIMIT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void natt_ntt_str_3_mpdu_limit_ntt_max_mpdu_setf(uint16_t nttmaxmpdu)
{
	ASSERT_ERR((((uint32_t)nttmaxmpdu << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_MPDU_LIMIT_ADDR, (REG_PL_RD(NATT_NTT_STR_3_MPDU_LIMIT_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)nttmaxmpdu <<12));
}
__INLINE uint16_t natt_ntt_str_3_mpdu_limit_ntt_ba_window_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_MPDU_LIMIT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void natt_ntt_str_3_mpdu_limit_ntt_ba_window_setf(uint16_t nttbawindow)
{
	ASSERT_ERR((((uint32_t)nttbawindow << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_MPDU_LIMIT_ADDR, (REG_PL_RD(NATT_NTT_STR_3_MPDU_LIMIT_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)nttbawindow <<0));
}

/**
 * @brief NTT_STR_3_THD_BASE_LOC register definition
 *  THD location for psdu_length register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_THD_LOC               0x0
 * </pre>
 */
#define NATT_NTT_STR_3_THD_BASE_LOC_ADDR        (REG_NATT_BASE_ADDR+0x0000032C)
#define NATT_NTT_STR_3_THD_BASE_LOC_OFFSET      0x0000032C
#define NATT_NTT_STR_3_THD_BASE_LOC_INDEX       0x000000CB
#define NATT_NTT_STR_3_THD_BASE_LOC_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_thd_base_loc_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_THD_BASE_LOC_ADDR);
}

__INLINE void natt_ntt_str_3_thd_base_loc_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_3_THD_BASE_LOC_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_3_THD_BASE_LOC_NTT_THD_LOC_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_3_THD_BASE_LOC_NTT_THD_LOC_LSB    0
#define NATT_NTT_STR_3_THD_BASE_LOC_NTT_THD_LOC_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_3_THD_BASE_LOC_NTT_THD_LOC_RST    0x0

__INLINE uint32_t natt_ntt_str_3_thd_base_loc_ntt_thd_loc_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_THD_BASE_LOC_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_3_thd_base_loc_ntt_thd_loc_setf(uint32_t nttthdloc)
{
	ASSERT_ERR((((uint32_t)nttthdloc << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_THD_BASE_LOC_ADDR, (uint32_t)nttthdloc << 0);
}

/**
 * @brief NTT_STR_3_CR_INFO register definition
 *  End of process closing reason register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05:00 NTT_CR_INFO               0x0
 * </pre>
 */
#define NATT_NTT_STR_3_CR_INFO_ADDR        (REG_NATT_BASE_ADDR+0x00000330)
#define NATT_NTT_STR_3_CR_INFO_OFFSET      0x00000330
#define NATT_NTT_STR_3_CR_INFO_INDEX       0x000000CC
#define NATT_NTT_STR_3_CR_INFO_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_cr_info_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_CR_INFO_ADDR);
}

// field definitions
#define NATT_NTT_STR_3_CR_INFO_NTT_CR_INFO_MASK    ((uint32_t)0x0000003F)
#define NATT_NTT_STR_3_CR_INFO_NTT_CR_INFO_LSB    0
#define NATT_NTT_STR_3_CR_INFO_NTT_CR_INFO_WIDTH    ((uint32_t)0x00000006)

#define NATT_NTT_STR_3_CR_INFO_NTT_CR_INFO_RST    0x0

__INLINE uint8_t natt_ntt_str_3_cr_info_ntt_cr_info_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_CR_INFO_ADDR);
	return (uint8_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_3_LD_INFO register definition
 *  End of process last description address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_LD_INFO               0x0
 * </pre>
 */
#define NATT_NTT_STR_3_LD_INFO_ADDR        (REG_NATT_BASE_ADDR+0x00000334)
#define NATT_NTT_STR_3_LD_INFO_OFFSET      0x00000334
#define NATT_NTT_STR_3_LD_INFO_INDEX       0x000000CD
#define NATT_NTT_STR_3_LD_INFO_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_ld_info_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_LD_INFO_ADDR);
}

// field definitions
#define NATT_NTT_STR_3_LD_INFO_NTT_LD_INFO_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_3_LD_INFO_NTT_LD_INFO_LSB    0
#define NATT_NTT_STR_3_LD_INFO_NTT_LD_INFO_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_3_LD_INFO_NTT_LD_INFO_RST    0x0

__INLINE uint32_t natt_ntt_str_3_ld_info_ntt_ld_info_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_LD_INFO_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_3_NON_DATA_INFO_1 register definition
 *  Number length and padding of nonDATA MPDUs register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17:16 NTT_NON_DATA1_PAD         0x0
 *    15:12 NTT_NON_DATA1_NUM         0x0
 *    09:00 NTT_NON_DATA1_LEN         0x0
 * </pre>
 */
#define NATT_NTT_STR_3_NON_DATA_INFO_1_ADDR        (REG_NATT_BASE_ADDR+0x00000360)
#define NATT_NTT_STR_3_NON_DATA_INFO_1_OFFSET      0x00000360
#define NATT_NTT_STR_3_NON_DATA_INFO_1_INDEX       0x000000D8
#define NATT_NTT_STR_3_NON_DATA_INFO_1_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_non_data_info_1_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_NON_DATA_INFO_1_ADDR);
}

__INLINE void natt_ntt_str_3_non_data_info_1_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_3_NON_DATA_INFO_1_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_3_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_MASK    ((uint32_t)0x00030000)
#define NATT_NTT_STR_3_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_LSB    16
#define NATT_NTT_STR_3_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_WIDTH    ((uint32_t)0x00000002)
#define NATT_NTT_STR_3_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_MASK    ((uint32_t)0x0000F000)
#define NATT_NTT_STR_3_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_LSB    12
#define NATT_NTT_STR_3_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_WIDTH    ((uint32_t)0x00000004)
#define NATT_NTT_STR_3_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_MASK    ((uint32_t)0x000003FF)
#define NATT_NTT_STR_3_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_LSB    0
#define NATT_NTT_STR_3_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_WIDTH    ((uint32_t)0x0000000A)

#define NATT_NTT_STR_3_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_RST    0x0
#define NATT_NTT_STR_3_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_RST    0x0
#define NATT_NTT_STR_3_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_RST    0x0

__INLINE void natt_ntt_str_3_non_data_info_1_pack(uint8_t ntt_non_data1_pad, uint8_t ntt_non_data1_num, uint16_t ntt_non_data1_len)
{
	ASSERT_ERR((((uint32_t)ntt_non_data1_pad << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data1_num << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data1_len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_NON_DATA_INFO_1_ADDR,  ((uint32_t)ntt_non_data1_pad << 16) |((uint32_t)ntt_non_data1_num << 12) |((uint32_t)ntt_non_data1_len << 0));
}

__INLINE void natt_ntt_str_3_non_data_info_1_unpack(uint8_t* ntt_non_data1_pad, uint8_t* ntt_non_data1_num, uint16_t* ntt_non_data1_len)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_NON_DATA_INFO_1_ADDR);

	*ntt_non_data1_pad = (localVal & ((uint32_t)0x00030000)) >>  16;
	*ntt_non_data1_num = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*ntt_non_data1_len = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint8_t natt_ntt_str_3_non_data_info_1_ntt_non_data_1_pad_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_NON_DATA_INFO_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void natt_ntt_str_3_non_data_info_1_ntt_non_data_1_pad_setf(uint8_t nttnondata1pad)
{
	ASSERT_ERR((((uint32_t)nttnondata1pad << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_NON_DATA_INFO_1_ADDR, (REG_PL_RD(NATT_NTT_STR_3_NON_DATA_INFO_1_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)nttnondata1pad <<16));
}
__INLINE uint8_t natt_ntt_str_3_non_data_info_1_ntt_non_data_1_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_NON_DATA_INFO_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void natt_ntt_str_3_non_data_info_1_ntt_non_data_1_num_setf(uint8_t nttnondata1num)
{
	ASSERT_ERR((((uint32_t)nttnondata1num << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_NON_DATA_INFO_1_ADDR, (REG_PL_RD(NATT_NTT_STR_3_NON_DATA_INFO_1_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)nttnondata1num <<12));
}
__INLINE uint16_t natt_ntt_str_3_non_data_info_1_ntt_non_data_1_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_NON_DATA_INFO_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void natt_ntt_str_3_non_data_info_1_ntt_non_data_1_len_setf(uint16_t nttnondata1len)
{
	ASSERT_ERR((((uint32_t)nttnondata1len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_NON_DATA_INFO_1_ADDR, (REG_PL_RD(NATT_NTT_STR_3_NON_DATA_INFO_1_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)nttnondata1len <<0));
}

/**
 * @brief NTT_STR_3_NON_DATA_INFO_2 register definition
 *  Number length and padding of nonDATA MPDUs register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17:16 NTT_NON_DATA2_PAD         0x0
 *    15:12 NTT_NON_DATA2_NUM         0x0
 *    09:00 NTT_NON_DATA2_LEN         0x0
 * </pre>
 */
#define NATT_NTT_STR_3_NON_DATA_INFO_2_ADDR        (REG_NATT_BASE_ADDR+0x00000364)
#define NATT_NTT_STR_3_NON_DATA_INFO_2_OFFSET      0x00000364
#define NATT_NTT_STR_3_NON_DATA_INFO_2_INDEX       0x000000D9
#define NATT_NTT_STR_3_NON_DATA_INFO_2_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_non_data_info_2_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_NON_DATA_INFO_2_ADDR);
}

__INLINE void natt_ntt_str_3_non_data_info_2_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_3_NON_DATA_INFO_2_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_3_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_MASK    ((uint32_t)0x00030000)
#define NATT_NTT_STR_3_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_LSB    16
#define NATT_NTT_STR_3_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_WIDTH    ((uint32_t)0x00000002)
#define NATT_NTT_STR_3_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_MASK    ((uint32_t)0x0000F000)
#define NATT_NTT_STR_3_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_LSB    12
#define NATT_NTT_STR_3_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_WIDTH    ((uint32_t)0x00000004)
#define NATT_NTT_STR_3_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_MASK    ((uint32_t)0x000003FF)
#define NATT_NTT_STR_3_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_LSB    0
#define NATT_NTT_STR_3_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_WIDTH    ((uint32_t)0x0000000A)

#define NATT_NTT_STR_3_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_RST    0x0
#define NATT_NTT_STR_3_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_RST    0x0
#define NATT_NTT_STR_3_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_RST    0x0

__INLINE void natt_ntt_str_3_non_data_info_2_pack(uint8_t ntt_non_data2_pad, uint8_t ntt_non_data2_num, uint16_t ntt_non_data2_len)
{
	ASSERT_ERR((((uint32_t)ntt_non_data2_pad << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data2_num << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data2_len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_NON_DATA_INFO_2_ADDR,  ((uint32_t)ntt_non_data2_pad << 16) |((uint32_t)ntt_non_data2_num << 12) |((uint32_t)ntt_non_data2_len << 0));
}

__INLINE void natt_ntt_str_3_non_data_info_2_unpack(uint8_t* ntt_non_data2_pad, uint8_t* ntt_non_data2_num, uint16_t* ntt_non_data2_len)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_NON_DATA_INFO_2_ADDR);

	*ntt_non_data2_pad = (localVal & ((uint32_t)0x00030000)) >>  16;
	*ntt_non_data2_num = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*ntt_non_data2_len = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint8_t natt_ntt_str_3_non_data_info_2_ntt_non_data_2_pad_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_NON_DATA_INFO_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void natt_ntt_str_3_non_data_info_2_ntt_non_data_2_pad_setf(uint8_t nttnondata2pad)
{
	ASSERT_ERR((((uint32_t)nttnondata2pad << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_NON_DATA_INFO_2_ADDR, (REG_PL_RD(NATT_NTT_STR_3_NON_DATA_INFO_2_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)nttnondata2pad <<16));
}
__INLINE uint8_t natt_ntt_str_3_non_data_info_2_ntt_non_data_2_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_NON_DATA_INFO_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void natt_ntt_str_3_non_data_info_2_ntt_non_data_2_num_setf(uint8_t nttnondata2num)
{
	ASSERT_ERR((((uint32_t)nttnondata2num << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_NON_DATA_INFO_2_ADDR, (REG_PL_RD(NATT_NTT_STR_3_NON_DATA_INFO_2_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)nttnondata2num <<12));
}
__INLINE uint16_t natt_ntt_str_3_non_data_info_2_ntt_non_data_2_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_NON_DATA_INFO_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void natt_ntt_str_3_non_data_info_2_ntt_non_data_2_len_setf(uint16_t nttnondata2len)
{
	ASSERT_ERR((((uint32_t)nttnondata2len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_NON_DATA_INFO_2_ADDR, (REG_PL_RD(NATT_NTT_STR_3_NON_DATA_INFO_2_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)nttnondata2len <<0));
}

/**
 * @brief NTT_STR_3_NON_DATA_1_RESULT register definition
 *  ZLDs and padding_in_bytes results for nonData register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 NTT_NON_DATA1_PADDING_IN_BYTES 0x0
 *    15:00 NTT_NON_DATA1_ZLD         0x0
 * </pre>
 */
#define NATT_NTT_STR_3_NON_DATA_1_RESULT_ADDR        (REG_NATT_BASE_ADDR+0x00000368)
#define NATT_NTT_STR_3_NON_DATA_1_RESULT_OFFSET      0x00000368
#define NATT_NTT_STR_3_NON_DATA_1_RESULT_INDEX       0x000000DA
#define NATT_NTT_STR_3_NON_DATA_1_RESULT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_non_data_1_result_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_NON_DATA_1_RESULT_ADDR);
}

// field definitions
#define NATT_NTT_STR_3_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_MASK    ((uint32_t)0xFFFF0000)
#define NATT_NTT_STR_3_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_LSB    16
#define NATT_NTT_STR_3_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_WIDTH    ((uint32_t)0x00000010)
#define NATT_NTT_STR_3_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_3_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_LSB    0
#define NATT_NTT_STR_3_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_3_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_RST    0x0
#define NATT_NTT_STR_3_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_RST    0x0

__INLINE void natt_ntt_str_3_non_data_1_result_unpack(uint16_t* ntt_non_data1_padding_in_bytes, uint16_t* ntt_non_data1_zld)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_NON_DATA_1_RESULT_ADDR);

	*ntt_non_data1_padding_in_bytes = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ntt_non_data1_zld = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t natt_ntt_str_3_non_data_1_result_ntt_non_data_1_padding_in_bytes_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_NON_DATA_1_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t natt_ntt_str_3_non_data_1_result_ntt_non_data_1_zld_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_NON_DATA_1_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief NTT_STR_3_NON_DATA_2_RESULT register definition
 *  ZLDs and padding_in_bytes results for nonData register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 NTT_NON_DATA2_PADDING_IN_BYTES 0x0
 *    15:00 TT_NON_DATA2_ZLD          0x0
 * </pre>
 */
#define NATT_NTT_STR_3_NON_DATA_2_RESULT_ADDR        (REG_NATT_BASE_ADDR+0x0000036C)
#define NATT_NTT_STR_3_NON_DATA_2_RESULT_OFFSET      0x0000036C
#define NATT_NTT_STR_3_NON_DATA_2_RESULT_INDEX       0x000000DB
#define NATT_NTT_STR_3_NON_DATA_2_RESULT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_non_data_2_result_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_NON_DATA_2_RESULT_ADDR);
}

// field definitions
#define NATT_NTT_STR_3_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_MASK    ((uint32_t)0xFFFF0000)
#define NATT_NTT_STR_3_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_LSB    16
#define NATT_NTT_STR_3_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_WIDTH    ((uint32_t)0x00000010)
#define NATT_NTT_STR_3_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_3_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_LSB    0
#define NATT_NTT_STR_3_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_3_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_RST    0x0
#define NATT_NTT_STR_3_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_RST    0x0

__INLINE void natt_ntt_str_3_non_data_2_result_unpack(uint16_t* ntt_non_data2_padding_in_bytes, uint16_t* tt_non_data2_zld)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_NON_DATA_2_RESULT_ADDR);

	*ntt_non_data2_padding_in_bytes = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*tt_non_data2_zld = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t natt_ntt_str_3_non_data_2_result_ntt_non_data_2_padding_in_bytes_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_NON_DATA_2_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t natt_ntt_str_3_non_data_2_result_tt_non_data_2_zld_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_NON_DATA_2_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief NTT_STR_3_MIN_SPACING_CONF register definition
 *  Min_spacing parameters for STA capabilities register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    FORCE_MIN_SPACING         0              
 *    07:04 MIN_SPACING_FACTOR        0x0
 *    03:00 MIN_SPACING               0x0
 * </pre>
 */
#define NATT_NTT_STR_3_MIN_SPACING_CONF_ADDR        (REG_NATT_BASE_ADDR+0x00000370)
#define NATT_NTT_STR_3_MIN_SPACING_CONF_OFFSET      0x00000370
#define NATT_NTT_STR_3_MIN_SPACING_CONF_INDEX       0x000000DC
#define NATT_NTT_STR_3_MIN_SPACING_CONF_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_min_spacing_conf_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_MIN_SPACING_CONF_ADDR);
}

__INLINE void natt_ntt_str_3_min_spacing_conf_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_3_MIN_SPACING_CONF_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_3_MIN_SPACING_CONF_FORCE_MIN_SPACING_BIT    ((uint32_t)0x80000000)
#define NATT_NTT_STR_3_MIN_SPACING_CONF_FORCE_MIN_SPACING_POS    31
#define NATT_NTT_STR_3_MIN_SPACING_CONF_MIN_SPACING_FACTOR_MASK    ((uint32_t)0x000000F0)
#define NATT_NTT_STR_3_MIN_SPACING_CONF_MIN_SPACING_FACTOR_LSB    4
#define NATT_NTT_STR_3_MIN_SPACING_CONF_MIN_SPACING_FACTOR_WIDTH    ((uint32_t)0x00000004)
#define NATT_NTT_STR_3_MIN_SPACING_CONF_MIN_SPACING_MASK    ((uint32_t)0x0000000F)
#define NATT_NTT_STR_3_MIN_SPACING_CONF_MIN_SPACING_LSB    0
#define NATT_NTT_STR_3_MIN_SPACING_CONF_MIN_SPACING_WIDTH    ((uint32_t)0x00000004)

#define NATT_NTT_STR_3_MIN_SPACING_CONF_FORCE_MIN_SPACING_RST    0x0
#define NATT_NTT_STR_3_MIN_SPACING_CONF_MIN_SPACING_FACTOR_RST    0x0
#define NATT_NTT_STR_3_MIN_SPACING_CONF_MIN_SPACING_RST    0x0

__INLINE void natt_ntt_str_3_min_spacing_conf_pack(uint8_t force_min_spacing, uint8_t min_spacing_factor, uint8_t min_spacing)
{
	ASSERT_ERR((((uint32_t)force_min_spacing << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)min_spacing_factor << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)min_spacing << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_MIN_SPACING_CONF_ADDR,  ((uint32_t)force_min_spacing << 31) |((uint32_t)min_spacing_factor << 4) |((uint32_t)min_spacing << 0));
}

__INLINE void natt_ntt_str_3_min_spacing_conf_unpack(uint8_t* force_min_spacing, uint8_t* min_spacing_factor, uint8_t* min_spacing)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_MIN_SPACING_CONF_ADDR);

	*force_min_spacing = (localVal & ((uint32_t)0x80000000)) >>  31;
	*min_spacing_factor = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*min_spacing = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t natt_ntt_str_3_min_spacing_conf_force_min_spacing_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_MIN_SPACING_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void natt_ntt_str_3_min_spacing_conf_force_min_spacing_setf(uint8_t forceminspacing)
{
	ASSERT_ERR((((uint32_t)forceminspacing << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_MIN_SPACING_CONF_ADDR, (REG_PL_RD(NATT_NTT_STR_3_MIN_SPACING_CONF_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)forceminspacing <<31));
}
__INLINE uint8_t natt_ntt_str_3_min_spacing_conf_min_spacing_factor_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_MIN_SPACING_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void natt_ntt_str_3_min_spacing_conf_min_spacing_factor_setf(uint8_t minspacingfactor)
{
	ASSERT_ERR((((uint32_t)minspacingfactor << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_MIN_SPACING_CONF_ADDR, (REG_PL_RD(NATT_NTT_STR_3_MIN_SPACING_CONF_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)minspacingfactor <<4));
}
__INLINE uint8_t natt_ntt_str_3_min_spacing_conf_min_spacing_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_MIN_SPACING_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void natt_ntt_str_3_min_spacing_conf_min_spacing_setf(uint8_t minspacing)
{
	ASSERT_ERR((((uint32_t)minspacing << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_MIN_SPACING_CONF_ADDR, (REG_PL_RD(NATT_NTT_STR_3_MIN_SPACING_CONF_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)minspacing <<0));
}

/**
 * @brief NTT_STR_3_DBG_CNT register definition
 *  Debug commands counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DBG_CNT               0x0
 * </pre>
 */
#define NATT_NTT_STR_3_DBG_CNT_ADDR        (REG_NATT_BASE_ADDR+0x00000374)
#define NATT_NTT_STR_3_DBG_CNT_OFFSET      0x00000374
#define NATT_NTT_STR_3_DBG_CNT_INDEX       0x000000DD
#define NATT_NTT_STR_3_DBG_CNT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_dbg_cnt_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_DBG_CNT_ADDR);
}

__INLINE void natt_ntt_str_3_dbg_cnt_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_STR_3_DBG_CNT_ADDR, value);
}

// field definitions
#define NATT_NTT_STR_3_DBG_CNT_NTT_DBG_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_STR_3_DBG_CNT_NTT_DBG_CNT_LSB    0
#define NATT_NTT_STR_3_DBG_CNT_NTT_DBG_CNT_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_STR_3_DBG_CNT_NTT_DBG_CNT_RST    0x0

__INLINE uint32_t natt_ntt_str_3_dbg_cnt_ntt_dbg_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_DBG_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_str_3_dbg_cnt_ntt_dbg_cnt_setf(uint32_t nttdbgcnt)
{
	ASSERT_ERR((((uint32_t)nttdbgcnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_STR_3_DBG_CNT_ADDR, (uint32_t)nttdbgcnt << 0);
}

/**
 * @brief NTT_STR_3_PHY_RATE register definition
 *  Debug results of last packet (ndps+rate) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 NTT_PHY_RATE              0x0
 * </pre>
 */
#define NATT_NTT_STR_3_PHY_RATE_ADDR        (REG_NATT_BASE_ADDR+0x00000378)
#define NATT_NTT_STR_3_PHY_RATE_OFFSET      0x00000378
#define NATT_NTT_STR_3_PHY_RATE_INDEX       0x000000DE
#define NATT_NTT_STR_3_PHY_RATE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_phy_rate_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_PHY_RATE_ADDR);
}

// field definitions
#define NATT_NTT_STR_3_PHY_RATE_NTT_PHY_RATE_MASK    ((uint32_t)0x000FFFFF)
#define NATT_NTT_STR_3_PHY_RATE_NTT_PHY_RATE_LSB    0
#define NATT_NTT_STR_3_PHY_RATE_NTT_PHY_RATE_WIDTH    ((uint32_t)0x00000014)

#define NATT_NTT_STR_3_PHY_RATE_NTT_PHY_RATE_RST    0x0

__INLINE uint32_t natt_ntt_str_3_phy_rate_ntt_phy_rate_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_PHY_RATE_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_3_NDBPS register definition
 *  Number of data bits per symbol register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 NTT_NDBPS                 0x0
 * </pre>
 */
#define NATT_NTT_STR_3_NDBPS_ADDR        (REG_NATT_BASE_ADDR+0x0000037C)
#define NATT_NTT_STR_3_NDBPS_OFFSET      0x0000037C
#define NATT_NTT_STR_3_NDBPS_INDEX       0x000000DF
#define NATT_NTT_STR_3_NDBPS_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_ndbps_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_NDBPS_ADDR);
}

// field definitions
#define NATT_NTT_STR_3_NDBPS_NTT_NDBPS_MASK    ((uint32_t)0x000FFFFF)
#define NATT_NTT_STR_3_NDBPS_NTT_NDBPS_LSB    0
#define NATT_NTT_STR_3_NDBPS_NTT_NDBPS_WIDTH    ((uint32_t)0x00000014)

#define NATT_NTT_STR_3_NDBPS_NTT_NDBPS_RST    0x0

__INLINE uint32_t natt_ntt_str_3_ndbps_ntt_ndbps_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_NDBPS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_3_SYM_TIME register definition
 *  Debug results of last packet (symbols+datatime) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 NTT_SYMBOLS               0x0
 *    15:00 NTT_DAT_TIME              0x0
 * </pre>
 */
#define NATT_NTT_STR_3_SYM_TIME_ADDR        (REG_NATT_BASE_ADDR+0x00000380)
#define NATT_NTT_STR_3_SYM_TIME_OFFSET      0x00000380
#define NATT_NTT_STR_3_SYM_TIME_INDEX       0x000000E0
#define NATT_NTT_STR_3_SYM_TIME_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_sym_time_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_SYM_TIME_ADDR);
}

// field definitions
#define NATT_NTT_STR_3_SYM_TIME_NTT_SYMBOLS_MASK    ((uint32_t)0xFFFF0000)
#define NATT_NTT_STR_3_SYM_TIME_NTT_SYMBOLS_LSB    16
#define NATT_NTT_STR_3_SYM_TIME_NTT_SYMBOLS_WIDTH    ((uint32_t)0x00000010)
#define NATT_NTT_STR_3_SYM_TIME_NTT_DAT_TIME_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_3_SYM_TIME_NTT_DAT_TIME_LSB    0
#define NATT_NTT_STR_3_SYM_TIME_NTT_DAT_TIME_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_3_SYM_TIME_NTT_SYMBOLS_RST    0x0
#define NATT_NTT_STR_3_SYM_TIME_NTT_DAT_TIME_RST    0x0

__INLINE void natt_ntt_str_3_sym_time_unpack(uint16_t* ntt_symbols, uint16_t* ntt_dat_time)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_SYM_TIME_ADDR);

	*ntt_symbols = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ntt_dat_time = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t natt_ntt_str_3_sym_time_ntt_symbols_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_SYM_TIME_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t natt_ntt_str_3_sym_time_ntt_dat_time_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_SYM_TIME_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief NTT_STR_3_TOT_TIME register definition
 *  Debug results of last packet (total time) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 NTT_TOT_TIME              0x0
 * </pre>
 */
#define NATT_NTT_STR_3_TOT_TIME_ADDR        (REG_NATT_BASE_ADDR+0x00000384)
#define NATT_NTT_STR_3_TOT_TIME_OFFSET      0x00000384
#define NATT_NTT_STR_3_TOT_TIME_INDEX       0x000000E1
#define NATT_NTT_STR_3_TOT_TIME_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_tot_time_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_TOT_TIME_ADDR);
}

// field definitions
#define NATT_NTT_STR_3_TOT_TIME_NTT_TOT_TIME_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_STR_3_TOT_TIME_NTT_TOT_TIME_LSB    0
#define NATT_NTT_STR_3_TOT_TIME_NTT_TOT_TIME_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_STR_3_TOT_TIME_NTT_TOT_TIME_RST    0x0

__INLINE uint16_t natt_ntt_str_3_tot_time_ntt_tot_time_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_TOT_TIME_ADDR);
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_3_MPDU_NUM register definition
 *  Debug results of last packet (number of MPDUs) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    08:00 NTT_MPDU_NUM              0x0
 * </pre>
 */
#define NATT_NTT_STR_3_MPDU_NUM_ADDR        (REG_NATT_BASE_ADDR+0x00000388)
#define NATT_NTT_STR_3_MPDU_NUM_OFFSET      0x00000388
#define NATT_NTT_STR_3_MPDU_NUM_INDEX       0x000000E2
#define NATT_NTT_STR_3_MPDU_NUM_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_mpdu_num_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_MPDU_NUM_ADDR);
}

// field definitions
#define NATT_NTT_STR_3_MPDU_NUM_NTT_MPDU_NUM_MASK    ((uint32_t)0x000001FF)
#define NATT_NTT_STR_3_MPDU_NUM_NTT_MPDU_NUM_LSB    0
#define NATT_NTT_STR_3_MPDU_NUM_NTT_MPDU_NUM_WIDTH    ((uint32_t)0x00000009)

#define NATT_NTT_STR_3_MPDU_NUM_NTT_MPDU_NUM_RST    0x0

__INLINE uint16_t natt_ntt_str_3_mpdu_num_ntt_mpdu_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_MPDU_NUM_ADDR);
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_3_AMPDU_LEN register definition
 *  AMPDU actual length in bytes register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:00 NTT_AMPDU_LEN             0x0
 * </pre>
 */
#define NATT_NTT_STR_3_AMPDU_LEN_ADDR        (REG_NATT_BASE_ADDR+0x0000038C)
#define NATT_NTT_STR_3_AMPDU_LEN_OFFSET      0x0000038C
#define NATT_NTT_STR_3_AMPDU_LEN_INDEX       0x000000E3
#define NATT_NTT_STR_3_AMPDU_LEN_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_ampdu_len_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_AMPDU_LEN_ADDR);
}

// field definitions
#define NATT_NTT_STR_3_AMPDU_LEN_NTT_AMPDU_LEN_MASK    ((uint32_t)0x00FFFFFF)
#define NATT_NTT_STR_3_AMPDU_LEN_NTT_AMPDU_LEN_LSB    0
#define NATT_NTT_STR_3_AMPDU_LEN_NTT_AMPDU_LEN_WIDTH    ((uint32_t)0x00000018)

#define NATT_NTT_STR_3_AMPDU_LEN_NTT_AMPDU_LEN_RST    0x0

__INLINE uint32_t natt_ntt_str_3_ampdu_len_ntt_ampdu_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_AMPDU_LEN_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_STR_3_MAX_AMPDU_LEN register definition
 *  MAX AMPDU Length in bytes register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:00 NTT_MAX_AMPDU_LEN         0x0
 * </pre>
 */
#define NATT_NTT_STR_3_MAX_AMPDU_LEN_ADDR        (REG_NATT_BASE_ADDR+0x00000390)
#define NATT_NTT_STR_3_MAX_AMPDU_LEN_OFFSET      0x00000390
#define NATT_NTT_STR_3_MAX_AMPDU_LEN_INDEX       0x000000E4
#define NATT_NTT_STR_3_MAX_AMPDU_LEN_RESET       0x00000000

__INLINE uint32_t  natt_ntt_str_3_max_ampdu_len_get(void)
{
	return REG_PL_RD(NATT_NTT_STR_3_MAX_AMPDU_LEN_ADDR);
}

// field definitions
#define NATT_NTT_STR_3_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_MASK    ((uint32_t)0x00FFFFFF)
#define NATT_NTT_STR_3_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_LSB    0
#define NATT_NTT_STR_3_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_WIDTH    ((uint32_t)0x00000018)

#define NATT_NTT_STR_3_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_RST    0x0

__INLINE uint32_t natt_ntt_str_3_max_ampdu_len_ntt_max_ampdu_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_STR_3_MAX_AMPDU_LEN_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_HTP_PT_BASE register definition
 *  Policy Table register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_PT_BASE               0x0
 * </pre>
 */
#define NATT_NTT_HTP_PT_BASE_ADDR        (REG_NATT_BASE_ADDR+0x0000040C)
#define NATT_NTT_HTP_PT_BASE_OFFSET      0x0000040C
#define NATT_NTT_HTP_PT_BASE_INDEX       0x00000103
#define NATT_NTT_HTP_PT_BASE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_pt_base_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_PT_BASE_ADDR);
}

__INLINE void natt_ntt_htp_pt_base_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_HTP_PT_BASE_ADDR, value);
}

// field definitions
#define NATT_NTT_HTP_PT_BASE_NTT_PT_BASE_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_HTP_PT_BASE_NTT_PT_BASE_LSB    0
#define NATT_NTT_HTP_PT_BASE_NTT_PT_BASE_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_HTP_PT_BASE_NTT_PT_BASE_RST    0x0

__INLINE uint32_t natt_ntt_htp_pt_base_ntt_pt_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_PT_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_htp_pt_base_ntt_pt_base_setf(uint32_t nttptbase)
{
	ASSERT_ERR((((uint32_t)nttptbase << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_HTP_PT_BASE_ADDR, (uint32_t)nttptbase << 0);
}

/**
 * @brief NTT_HTP_DESC_BASE register definition
 *  Descriptors chain base address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DESC_BASE             0x0
 * </pre>
 */
#define NATT_NTT_HTP_DESC_BASE_ADDR        (REG_NATT_BASE_ADDR+0x00000410)
#define NATT_NTT_HTP_DESC_BASE_OFFSET      0x00000410
#define NATT_NTT_HTP_DESC_BASE_INDEX       0x00000104
#define NATT_NTT_HTP_DESC_BASE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_desc_base_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_DESC_BASE_ADDR);
}

__INLINE void natt_ntt_htp_desc_base_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_HTP_DESC_BASE_ADDR, value);
}

// field definitions
#define NATT_NTT_HTP_DESC_BASE_NTT_DESC_BASE_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_HTP_DESC_BASE_NTT_DESC_BASE_LSB    0
#define NATT_NTT_HTP_DESC_BASE_NTT_DESC_BASE_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_HTP_DESC_BASE_NTT_DESC_BASE_RST    0x0

__INLINE uint32_t natt_ntt_htp_desc_base_ntt_desc_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_DESC_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_htp_desc_base_ntt_desc_base_setf(uint32_t nttdescbase)
{
	ASSERT_ERR((((uint32_t)nttdescbase << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_HTP_DESC_BASE_ADDR, (uint32_t)nttdescbase << 0);
}

/**
 * @brief NTT_HTP_DESC_TSIZE register definition
 *  Total descriptors chain size register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DESC_TSIZE            0x0
 * </pre>
 */
#define NATT_NTT_HTP_DESC_TSIZE_ADDR        (REG_NATT_BASE_ADDR+0x0000041C)
#define NATT_NTT_HTP_DESC_TSIZE_OFFSET      0x0000041C
#define NATT_NTT_HTP_DESC_TSIZE_INDEX       0x00000107
#define NATT_NTT_HTP_DESC_TSIZE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_desc_tsize_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_DESC_TSIZE_ADDR);
}

__INLINE void natt_ntt_htp_desc_tsize_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_HTP_DESC_TSIZE_ADDR, value);
}

// field definitions
#define NATT_NTT_HTP_DESC_TSIZE_NTT_DESC_TSIZE_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_HTP_DESC_TSIZE_NTT_DESC_TSIZE_LSB    0
#define NATT_NTT_HTP_DESC_TSIZE_NTT_DESC_TSIZE_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_HTP_DESC_TSIZE_NTT_DESC_TSIZE_RST    0x0

__INLINE uint32_t natt_ntt_htp_desc_tsize_ntt_desc_tsize_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_DESC_TSIZE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_htp_desc_tsize_ntt_desc_tsize_setf(uint32_t nttdesctsize)
{
	ASSERT_ERR((((uint32_t)nttdesctsize << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_HTP_DESC_TSIZE_ADDR, (uint32_t)nttdesctsize << 0);
}

/**
 * @brief NTT_HTP_DESC_START register definition
 *  Descriptors chain start address (1st MPDU) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DESC_START            0x0
 * </pre>
 */
#define NATT_NTT_HTP_DESC_START_ADDR        (REG_NATT_BASE_ADDR+0x00000420)
#define NATT_NTT_HTP_DESC_START_OFFSET      0x00000420
#define NATT_NTT_HTP_DESC_START_INDEX       0x00000108
#define NATT_NTT_HTP_DESC_START_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_desc_start_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_DESC_START_ADDR);
}

__INLINE void natt_ntt_htp_desc_start_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_HTP_DESC_START_ADDR, value);
}

// field definitions
#define NATT_NTT_HTP_DESC_START_NTT_DESC_START_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_HTP_DESC_START_NTT_DESC_START_LSB    0
#define NATT_NTT_HTP_DESC_START_NTT_DESC_START_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_HTP_DESC_START_NTT_DESC_START_RST    0x0

__INLINE uint32_t natt_ntt_htp_desc_start_ntt_desc_start_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_DESC_START_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_htp_desc_start_ntt_desc_start_setf(uint32_t nttdescstart)
{
	ASSERT_ERR((((uint32_t)nttdescstart << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_HTP_DESC_START_ADDR, (uint32_t)nttdescstart << 0);
}

/**
 * @brief NTT_HTP_AIRTIME_LIMIT register definition
 *  AirTime Limit in usec register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 NTT_AIRTIME_LIMIT         0x0
 * </pre>
 */
#define NATT_NTT_HTP_AIRTIME_LIMIT_ADDR        (REG_NATT_BASE_ADDR+0x00000424)
#define NATT_NTT_HTP_AIRTIME_LIMIT_OFFSET      0x00000424
#define NATT_NTT_HTP_AIRTIME_LIMIT_INDEX       0x00000109
#define NATT_NTT_HTP_AIRTIME_LIMIT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_airtime_limit_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_AIRTIME_LIMIT_ADDR);
}

__INLINE void natt_ntt_htp_airtime_limit_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_HTP_AIRTIME_LIMIT_ADDR, value);
}

// field definitions
#define NATT_NTT_HTP_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_HTP_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_LSB    0
#define NATT_NTT_HTP_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_HTP_AIRTIME_LIMIT_NTT_AIRTIME_LIMIT_RST    0x0

__INLINE uint16_t natt_ntt_htp_airtime_limit_ntt_airtime_limit_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_AIRTIME_LIMIT_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void natt_ntt_htp_airtime_limit_ntt_airtime_limit_setf(uint16_t nttairtimelimit)
{
	ASSERT_ERR((((uint32_t)nttairtimelimit << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(NATT_NTT_HTP_AIRTIME_LIMIT_ADDR, (uint32_t)nttairtimelimit << 0);
}

/**
 * @brief NTT_HTP_MPDU_LIMIT register definition
 *  BA and valid MPDUs limit register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:24 NTT_STA_INDEX             0x0
 *    20:12 NTT_MAX_MPDU              0x0
 *    08:00 NTT_BA_WINDOW             0x0
 * </pre>
 */
#define NATT_NTT_HTP_MPDU_LIMIT_ADDR        (REG_NATT_BASE_ADDR+0x00000428)
#define NATT_NTT_HTP_MPDU_LIMIT_OFFSET      0x00000428
#define NATT_NTT_HTP_MPDU_LIMIT_INDEX       0x0000010A
#define NATT_NTT_HTP_MPDU_LIMIT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_mpdu_limit_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_MPDU_LIMIT_ADDR);
}

__INLINE void natt_ntt_htp_mpdu_limit_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_HTP_MPDU_LIMIT_ADDR, value);
}

// field definitions
#define NATT_NTT_HTP_MPDU_LIMIT_NTT_STA_INDEX_MASK    ((uint32_t)0x7F000000)
#define NATT_NTT_HTP_MPDU_LIMIT_NTT_STA_INDEX_LSB    24
#define NATT_NTT_HTP_MPDU_LIMIT_NTT_STA_INDEX_WIDTH    ((uint32_t)0x00000007)
#define NATT_NTT_HTP_MPDU_LIMIT_NTT_MAX_MPDU_MASK    ((uint32_t)0x001FF000)
#define NATT_NTT_HTP_MPDU_LIMIT_NTT_MAX_MPDU_LSB    12
#define NATT_NTT_HTP_MPDU_LIMIT_NTT_MAX_MPDU_WIDTH    ((uint32_t)0x00000009)
#define NATT_NTT_HTP_MPDU_LIMIT_NTT_BA_WINDOW_MASK    ((uint32_t)0x000001FF)
#define NATT_NTT_HTP_MPDU_LIMIT_NTT_BA_WINDOW_LSB    0
#define NATT_NTT_HTP_MPDU_LIMIT_NTT_BA_WINDOW_WIDTH    ((uint32_t)0x00000009)

#define NATT_NTT_HTP_MPDU_LIMIT_NTT_STA_INDEX_RST    0x0
#define NATT_NTT_HTP_MPDU_LIMIT_NTT_MAX_MPDU_RST    0x0
#define NATT_NTT_HTP_MPDU_LIMIT_NTT_BA_WINDOW_RST    0x0

__INLINE void natt_ntt_htp_mpdu_limit_pack(uint8_t ntt_sta_index, uint16_t ntt_max_mpdu, uint16_t ntt_ba_window)
{
	ASSERT_ERR((((uint32_t)ntt_sta_index << 24) & ~((uint32_t)0x7F000000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_max_mpdu << 12) & ~((uint32_t)0x001FF000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_ba_window << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(NATT_NTT_HTP_MPDU_LIMIT_ADDR,  ((uint32_t)ntt_sta_index << 24) |((uint32_t)ntt_max_mpdu << 12) |((uint32_t)ntt_ba_window << 0));
}

__INLINE void natt_ntt_htp_mpdu_limit_unpack(uint8_t* ntt_sta_index, uint16_t* ntt_max_mpdu, uint16_t* ntt_ba_window)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_MPDU_LIMIT_ADDR);

	*ntt_sta_index = (localVal & ((uint32_t)0x7F000000)) >>  24;
	*ntt_max_mpdu = (localVal & ((uint32_t)0x001FF000)) >>  12;
	*ntt_ba_window = (localVal & ((uint32_t)0x000001FF)) >>  0;
}

__INLINE uint8_t natt_ntt_htp_mpdu_limit_ntt_sta_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_MPDU_LIMIT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x7F000000)) >> 24);
}
__INLINE void natt_ntt_htp_mpdu_limit_ntt_sta_index_setf(uint8_t nttstaindex)
{
	ASSERT_ERR((((uint32_t)nttstaindex << 24) & ~((uint32_t)0x7F000000)) == 0);
	REG_PL_WR(NATT_NTT_HTP_MPDU_LIMIT_ADDR, (REG_PL_RD(NATT_NTT_HTP_MPDU_LIMIT_ADDR) & ~((uint32_t)0x7F000000)) | ((uint32_t)nttstaindex <<24));
}
__INLINE uint16_t natt_ntt_htp_mpdu_limit_ntt_max_mpdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_MPDU_LIMIT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x001FF000)) >> 12);
}
__INLINE void natt_ntt_htp_mpdu_limit_ntt_max_mpdu_setf(uint16_t nttmaxmpdu)
{
	ASSERT_ERR((((uint32_t)nttmaxmpdu << 12) & ~((uint32_t)0x001FF000)) == 0);
	REG_PL_WR(NATT_NTT_HTP_MPDU_LIMIT_ADDR, (REG_PL_RD(NATT_NTT_HTP_MPDU_LIMIT_ADDR) & ~((uint32_t)0x001FF000)) | ((uint32_t)nttmaxmpdu <<12));
}
__INLINE uint16_t natt_ntt_htp_mpdu_limit_ntt_ba_window_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_MPDU_LIMIT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000001FF)) >> 0);
}
__INLINE void natt_ntt_htp_mpdu_limit_ntt_ba_window_setf(uint16_t nttbawindow)
{
	ASSERT_ERR((((uint32_t)nttbawindow << 0) & ~((uint32_t)0x000001FF)) == 0);
	REG_PL_WR(NATT_NTT_HTP_MPDU_LIMIT_ADDR, (REG_PL_RD(NATT_NTT_HTP_MPDU_LIMIT_ADDR) & ~((uint32_t)0x000001FF)) | ((uint32_t)nttbawindow <<0));
}

/**
 * @brief NTT_HTP_THD_BASE_LOC register definition
 *  THD location for psdu_length register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_THD_LOC               0x0
 * </pre>
 */
#define NATT_NTT_HTP_THD_BASE_LOC_ADDR        (REG_NATT_BASE_ADDR+0x0000042C)
#define NATT_NTT_HTP_THD_BASE_LOC_OFFSET      0x0000042C
#define NATT_NTT_HTP_THD_BASE_LOC_INDEX       0x0000010B
#define NATT_NTT_HTP_THD_BASE_LOC_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_thd_base_loc_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_THD_BASE_LOC_ADDR);
}

__INLINE void natt_ntt_htp_thd_base_loc_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_HTP_THD_BASE_LOC_ADDR, value);
}

// field definitions
#define NATT_NTT_HTP_THD_BASE_LOC_NTT_THD_LOC_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_HTP_THD_BASE_LOC_NTT_THD_LOC_LSB    0
#define NATT_NTT_HTP_THD_BASE_LOC_NTT_THD_LOC_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_HTP_THD_BASE_LOC_NTT_THD_LOC_RST    0x0

__INLINE uint32_t natt_ntt_htp_thd_base_loc_ntt_thd_loc_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_THD_BASE_LOC_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_htp_thd_base_loc_ntt_thd_loc_setf(uint32_t nttthdloc)
{
	ASSERT_ERR((((uint32_t)nttthdloc << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_HTP_THD_BASE_LOC_ADDR, (uint32_t)nttthdloc << 0);
}

/**
 * @brief NTT_HTP_CR_INFO register definition
 *  End of process closing reason register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05:00 NTT_CR_INFO               0x0
 * </pre>
 */
#define NATT_NTT_HTP_CR_INFO_ADDR        (REG_NATT_BASE_ADDR+0x00000430)
#define NATT_NTT_HTP_CR_INFO_OFFSET      0x00000430
#define NATT_NTT_HTP_CR_INFO_INDEX       0x0000010C
#define NATT_NTT_HTP_CR_INFO_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_cr_info_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_CR_INFO_ADDR);
}

// field definitions
#define NATT_NTT_HTP_CR_INFO_NTT_CR_INFO_MASK    ((uint32_t)0x0000003F)
#define NATT_NTT_HTP_CR_INFO_NTT_CR_INFO_LSB    0
#define NATT_NTT_HTP_CR_INFO_NTT_CR_INFO_WIDTH    ((uint32_t)0x00000006)

#define NATT_NTT_HTP_CR_INFO_NTT_CR_INFO_RST    0x0

__INLINE uint8_t natt_ntt_htp_cr_info_ntt_cr_info_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_CR_INFO_ADDR);
	return (uint8_t)(localVal >> 0);
}

/**
 * @brief NTT_HTP_LD_INFO register definition
 *  End of process last description address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_LD_INFO               0x0
 * </pre>
 */
#define NATT_NTT_HTP_LD_INFO_ADDR        (REG_NATT_BASE_ADDR+0x00000434)
#define NATT_NTT_HTP_LD_INFO_OFFSET      0x00000434
#define NATT_NTT_HTP_LD_INFO_INDEX       0x0000010D
#define NATT_NTT_HTP_LD_INFO_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_ld_info_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_LD_INFO_ADDR);
}

// field definitions
#define NATT_NTT_HTP_LD_INFO_NTT_LD_INFO_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_HTP_LD_INFO_NTT_LD_INFO_LSB    0
#define NATT_NTT_HTP_LD_INFO_NTT_LD_INFO_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_HTP_LD_INFO_NTT_LD_INFO_RST    0x0

__INLINE uint32_t natt_ntt_htp_ld_info_ntt_ld_info_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_LD_INFO_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_HTP_NON_DATA_INFO_1 register definition
 *  Number length and padding of nonDATA MPDUs register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17:16 NTT_NON_DATA1_PAD         0x0
 *    15:12 NTT_NON_DATA1_NUM         0x0
 *    09:00 NTT_NON_DATA1_LEN         0x0
 * </pre>
 */
#define NATT_NTT_HTP_NON_DATA_INFO_1_ADDR        (REG_NATT_BASE_ADDR+0x00000460)
#define NATT_NTT_HTP_NON_DATA_INFO_1_OFFSET      0x00000460
#define NATT_NTT_HTP_NON_DATA_INFO_1_INDEX       0x00000118
#define NATT_NTT_HTP_NON_DATA_INFO_1_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_non_data_info_1_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_NON_DATA_INFO_1_ADDR);
}

__INLINE void natt_ntt_htp_non_data_info_1_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_HTP_NON_DATA_INFO_1_ADDR, value);
}

// field definitions
#define NATT_NTT_HTP_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_MASK    ((uint32_t)0x00030000)
#define NATT_NTT_HTP_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_LSB    16
#define NATT_NTT_HTP_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_WIDTH    ((uint32_t)0x00000002)
#define NATT_NTT_HTP_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_MASK    ((uint32_t)0x0000F000)
#define NATT_NTT_HTP_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_LSB    12
#define NATT_NTT_HTP_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_WIDTH    ((uint32_t)0x00000004)
#define NATT_NTT_HTP_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_MASK    ((uint32_t)0x000003FF)
#define NATT_NTT_HTP_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_LSB    0
#define NATT_NTT_HTP_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_WIDTH    ((uint32_t)0x0000000A)

#define NATT_NTT_HTP_NON_DATA_INFO_1_NTT_NON_DATA_1_PAD_RST    0x0
#define NATT_NTT_HTP_NON_DATA_INFO_1_NTT_NON_DATA_1_NUM_RST    0x0
#define NATT_NTT_HTP_NON_DATA_INFO_1_NTT_NON_DATA_1_LEN_RST    0x0

__INLINE void natt_ntt_htp_non_data_info_1_pack(uint8_t ntt_non_data1_pad, uint8_t ntt_non_data1_num, uint16_t ntt_non_data1_len)
{
	ASSERT_ERR((((uint32_t)ntt_non_data1_pad << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data1_num << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data1_len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_HTP_NON_DATA_INFO_1_ADDR,  ((uint32_t)ntt_non_data1_pad << 16) |((uint32_t)ntt_non_data1_num << 12) |((uint32_t)ntt_non_data1_len << 0));
}

__INLINE void natt_ntt_htp_non_data_info_1_unpack(uint8_t* ntt_non_data1_pad, uint8_t* ntt_non_data1_num, uint16_t* ntt_non_data1_len)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_NON_DATA_INFO_1_ADDR);

	*ntt_non_data1_pad = (localVal & ((uint32_t)0x00030000)) >>  16;
	*ntt_non_data1_num = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*ntt_non_data1_len = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint8_t natt_ntt_htp_non_data_info_1_ntt_non_data_1_pad_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_NON_DATA_INFO_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void natt_ntt_htp_non_data_info_1_ntt_non_data_1_pad_setf(uint8_t nttnondata1pad)
{
	ASSERT_ERR((((uint32_t)nttnondata1pad << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(NATT_NTT_HTP_NON_DATA_INFO_1_ADDR, (REG_PL_RD(NATT_NTT_HTP_NON_DATA_INFO_1_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)nttnondata1pad <<16));
}
__INLINE uint8_t natt_ntt_htp_non_data_info_1_ntt_non_data_1_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_NON_DATA_INFO_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void natt_ntt_htp_non_data_info_1_ntt_non_data_1_num_setf(uint8_t nttnondata1num)
{
	ASSERT_ERR((((uint32_t)nttnondata1num << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(NATT_NTT_HTP_NON_DATA_INFO_1_ADDR, (REG_PL_RD(NATT_NTT_HTP_NON_DATA_INFO_1_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)nttnondata1num <<12));
}
__INLINE uint16_t natt_ntt_htp_non_data_info_1_ntt_non_data_1_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_NON_DATA_INFO_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void natt_ntt_htp_non_data_info_1_ntt_non_data_1_len_setf(uint16_t nttnondata1len)
{
	ASSERT_ERR((((uint32_t)nttnondata1len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_HTP_NON_DATA_INFO_1_ADDR, (REG_PL_RD(NATT_NTT_HTP_NON_DATA_INFO_1_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)nttnondata1len <<0));
}

/**
 * @brief NTT_HTP_NON_DATA_INFO_2 register definition
 *  Number length and padding of nonDATA MPDUs register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17:16 NTT_NON_DATA2_PAD         0x0
 *    15:12 NTT_NON_DATA2_NUM         0x0
 *    09:00 NTT_NON_DATA2_LEN         0x0
 * </pre>
 */
#define NATT_NTT_HTP_NON_DATA_INFO_2_ADDR        (REG_NATT_BASE_ADDR+0x00000464)
#define NATT_NTT_HTP_NON_DATA_INFO_2_OFFSET      0x00000464
#define NATT_NTT_HTP_NON_DATA_INFO_2_INDEX       0x00000119
#define NATT_NTT_HTP_NON_DATA_INFO_2_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_non_data_info_2_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_NON_DATA_INFO_2_ADDR);
}

__INLINE void natt_ntt_htp_non_data_info_2_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_HTP_NON_DATA_INFO_2_ADDR, value);
}

// field definitions
#define NATT_NTT_HTP_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_MASK    ((uint32_t)0x00030000)
#define NATT_NTT_HTP_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_LSB    16
#define NATT_NTT_HTP_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_WIDTH    ((uint32_t)0x00000002)
#define NATT_NTT_HTP_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_MASK    ((uint32_t)0x0000F000)
#define NATT_NTT_HTP_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_LSB    12
#define NATT_NTT_HTP_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_WIDTH    ((uint32_t)0x00000004)
#define NATT_NTT_HTP_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_MASK    ((uint32_t)0x000003FF)
#define NATT_NTT_HTP_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_LSB    0
#define NATT_NTT_HTP_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_WIDTH    ((uint32_t)0x0000000A)

#define NATT_NTT_HTP_NON_DATA_INFO_2_NTT_NON_DATA_2_PAD_RST    0x0
#define NATT_NTT_HTP_NON_DATA_INFO_2_NTT_NON_DATA_2_NUM_RST    0x0
#define NATT_NTT_HTP_NON_DATA_INFO_2_NTT_NON_DATA_2_LEN_RST    0x0

__INLINE void natt_ntt_htp_non_data_info_2_pack(uint8_t ntt_non_data2_pad, uint8_t ntt_non_data2_num, uint16_t ntt_non_data2_len)
{
	ASSERT_ERR((((uint32_t)ntt_non_data2_pad << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data2_num << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)ntt_non_data2_len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_HTP_NON_DATA_INFO_2_ADDR,  ((uint32_t)ntt_non_data2_pad << 16) |((uint32_t)ntt_non_data2_num << 12) |((uint32_t)ntt_non_data2_len << 0));
}

__INLINE void natt_ntt_htp_non_data_info_2_unpack(uint8_t* ntt_non_data2_pad, uint8_t* ntt_non_data2_num, uint16_t* ntt_non_data2_len)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_NON_DATA_INFO_2_ADDR);

	*ntt_non_data2_pad = (localVal & ((uint32_t)0x00030000)) >>  16;
	*ntt_non_data2_num = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*ntt_non_data2_len = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint8_t natt_ntt_htp_non_data_info_2_ntt_non_data_2_pad_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_NON_DATA_INFO_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void natt_ntt_htp_non_data_info_2_ntt_non_data_2_pad_setf(uint8_t nttnondata2pad)
{
	ASSERT_ERR((((uint32_t)nttnondata2pad << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(NATT_NTT_HTP_NON_DATA_INFO_2_ADDR, (REG_PL_RD(NATT_NTT_HTP_NON_DATA_INFO_2_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)nttnondata2pad <<16));
}
__INLINE uint8_t natt_ntt_htp_non_data_info_2_ntt_non_data_2_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_NON_DATA_INFO_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void natt_ntt_htp_non_data_info_2_ntt_non_data_2_num_setf(uint8_t nttnondata2num)
{
	ASSERT_ERR((((uint32_t)nttnondata2num << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(NATT_NTT_HTP_NON_DATA_INFO_2_ADDR, (REG_PL_RD(NATT_NTT_HTP_NON_DATA_INFO_2_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)nttnondata2num <<12));
}
__INLINE uint16_t natt_ntt_htp_non_data_info_2_ntt_non_data_2_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_NON_DATA_INFO_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void natt_ntt_htp_non_data_info_2_ntt_non_data_2_len_setf(uint16_t nttnondata2len)
{
	ASSERT_ERR((((uint32_t)nttnondata2len << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(NATT_NTT_HTP_NON_DATA_INFO_2_ADDR, (REG_PL_RD(NATT_NTT_HTP_NON_DATA_INFO_2_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)nttnondata2len <<0));
}

/**
 * @brief NTT_HTP_NON_DATA_1_RESULT register definition
 *  ZLDs and padding_in_bytes results for nonData register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 NTT_NON_DATA1_PADDING_IN_BYTES 0x0
 *    15:00 NTT_NON_DATA1_ZLD         0x0
 * </pre>
 */
#define NATT_NTT_HTP_NON_DATA_1_RESULT_ADDR        (REG_NATT_BASE_ADDR+0x00000468)
#define NATT_NTT_HTP_NON_DATA_1_RESULT_OFFSET      0x00000468
#define NATT_NTT_HTP_NON_DATA_1_RESULT_INDEX       0x0000011A
#define NATT_NTT_HTP_NON_DATA_1_RESULT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_non_data_1_result_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_NON_DATA_1_RESULT_ADDR);
}

// field definitions
#define NATT_NTT_HTP_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_MASK    ((uint32_t)0xFFFF0000)
#define NATT_NTT_HTP_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_LSB    16
#define NATT_NTT_HTP_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_WIDTH    ((uint32_t)0x00000010)
#define NATT_NTT_HTP_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_HTP_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_LSB    0
#define NATT_NTT_HTP_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_HTP_NON_DATA_1_RESULT_NTT_NON_DATA_1_PADDING_IN_BYTES_RST    0x0
#define NATT_NTT_HTP_NON_DATA_1_RESULT_NTT_NON_DATA_1_ZLD_RST    0x0

__INLINE void natt_ntt_htp_non_data_1_result_unpack(uint16_t* ntt_non_data1_padding_in_bytes, uint16_t* ntt_non_data1_zld)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_NON_DATA_1_RESULT_ADDR);

	*ntt_non_data1_padding_in_bytes = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ntt_non_data1_zld = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t natt_ntt_htp_non_data_1_result_ntt_non_data_1_padding_in_bytes_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_NON_DATA_1_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t natt_ntt_htp_non_data_1_result_ntt_non_data_1_zld_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_NON_DATA_1_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief NTT_HTP_NON_DATA_2_RESULT register definition
 *  ZLDs and padding_in_bytes results for nonData register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 NTT_NON_DATA2_PADDING_IN_BYTES 0x0
 *    15:00 TT_NON_DATA2_ZLD          0x0
 * </pre>
 */
#define NATT_NTT_HTP_NON_DATA_2_RESULT_ADDR        (REG_NATT_BASE_ADDR+0x0000046C)
#define NATT_NTT_HTP_NON_DATA_2_RESULT_OFFSET      0x0000046C
#define NATT_NTT_HTP_NON_DATA_2_RESULT_INDEX       0x0000011B
#define NATT_NTT_HTP_NON_DATA_2_RESULT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_non_data_2_result_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_NON_DATA_2_RESULT_ADDR);
}

// field definitions
#define NATT_NTT_HTP_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_MASK    ((uint32_t)0xFFFF0000)
#define NATT_NTT_HTP_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_LSB    16
#define NATT_NTT_HTP_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_WIDTH    ((uint32_t)0x00000010)
#define NATT_NTT_HTP_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_HTP_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_LSB    0
#define NATT_NTT_HTP_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_HTP_NON_DATA_2_RESULT_NTT_NON_DATA_2_PADDING_IN_BYTES_RST    0x0
#define NATT_NTT_HTP_NON_DATA_2_RESULT_TT_NON_DATA_2_ZLD_RST    0x0

__INLINE void natt_ntt_htp_non_data_2_result_unpack(uint16_t* ntt_non_data2_padding_in_bytes, uint16_t* tt_non_data2_zld)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_NON_DATA_2_RESULT_ADDR);

	*ntt_non_data2_padding_in_bytes = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*tt_non_data2_zld = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t natt_ntt_htp_non_data_2_result_ntt_non_data_2_padding_in_bytes_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_NON_DATA_2_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t natt_ntt_htp_non_data_2_result_tt_non_data_2_zld_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_NON_DATA_2_RESULT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief NTT_HTP_MIN_SPACING_CONF register definition
 *  Min_spacing parameters for STA capabilities register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    FORCE_MIN_SPACING         0              
 *    07:04 MIN_SPACING_FACTOR        0x0
 *    03:00 MIN_SPACING               0x0
 * </pre>
 */
#define NATT_NTT_HTP_MIN_SPACING_CONF_ADDR        (REG_NATT_BASE_ADDR+0x00000470)
#define NATT_NTT_HTP_MIN_SPACING_CONF_OFFSET      0x00000470
#define NATT_NTT_HTP_MIN_SPACING_CONF_INDEX       0x0000011C
#define NATT_NTT_HTP_MIN_SPACING_CONF_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_min_spacing_conf_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_MIN_SPACING_CONF_ADDR);
}

__INLINE void natt_ntt_htp_min_spacing_conf_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_HTP_MIN_SPACING_CONF_ADDR, value);
}

// field definitions
#define NATT_NTT_HTP_MIN_SPACING_CONF_FORCE_MIN_SPACING_BIT    ((uint32_t)0x80000000)
#define NATT_NTT_HTP_MIN_SPACING_CONF_FORCE_MIN_SPACING_POS    31
#define NATT_NTT_HTP_MIN_SPACING_CONF_MIN_SPACING_FACTOR_MASK    ((uint32_t)0x000000F0)
#define NATT_NTT_HTP_MIN_SPACING_CONF_MIN_SPACING_FACTOR_LSB    4
#define NATT_NTT_HTP_MIN_SPACING_CONF_MIN_SPACING_FACTOR_WIDTH    ((uint32_t)0x00000004)
#define NATT_NTT_HTP_MIN_SPACING_CONF_MIN_SPACING_MASK    ((uint32_t)0x0000000F)
#define NATT_NTT_HTP_MIN_SPACING_CONF_MIN_SPACING_LSB    0
#define NATT_NTT_HTP_MIN_SPACING_CONF_MIN_SPACING_WIDTH    ((uint32_t)0x00000004)

#define NATT_NTT_HTP_MIN_SPACING_CONF_FORCE_MIN_SPACING_RST    0x0
#define NATT_NTT_HTP_MIN_SPACING_CONF_MIN_SPACING_FACTOR_RST    0x0
#define NATT_NTT_HTP_MIN_SPACING_CONF_MIN_SPACING_RST    0x0

__INLINE void natt_ntt_htp_min_spacing_conf_pack(uint8_t force_min_spacing, uint8_t min_spacing_factor, uint8_t min_spacing)
{
	ASSERT_ERR((((uint32_t)force_min_spacing << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)min_spacing_factor << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)min_spacing << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(NATT_NTT_HTP_MIN_SPACING_CONF_ADDR,  ((uint32_t)force_min_spacing << 31) |((uint32_t)min_spacing_factor << 4) |((uint32_t)min_spacing << 0));
}

__INLINE void natt_ntt_htp_min_spacing_conf_unpack(uint8_t* force_min_spacing, uint8_t* min_spacing_factor, uint8_t* min_spacing)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_MIN_SPACING_CONF_ADDR);

	*force_min_spacing = (localVal & ((uint32_t)0x80000000)) >>  31;
	*min_spacing_factor = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*min_spacing = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t natt_ntt_htp_min_spacing_conf_force_min_spacing_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_MIN_SPACING_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void natt_ntt_htp_min_spacing_conf_force_min_spacing_setf(uint8_t forceminspacing)
{
	ASSERT_ERR((((uint32_t)forceminspacing << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(NATT_NTT_HTP_MIN_SPACING_CONF_ADDR, (REG_PL_RD(NATT_NTT_HTP_MIN_SPACING_CONF_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)forceminspacing <<31));
}
__INLINE uint8_t natt_ntt_htp_min_spacing_conf_min_spacing_factor_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_MIN_SPACING_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void natt_ntt_htp_min_spacing_conf_min_spacing_factor_setf(uint8_t minspacingfactor)
{
	ASSERT_ERR((((uint32_t)minspacingfactor << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(NATT_NTT_HTP_MIN_SPACING_CONF_ADDR, (REG_PL_RD(NATT_NTT_HTP_MIN_SPACING_CONF_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)minspacingfactor <<4));
}
__INLINE uint8_t natt_ntt_htp_min_spacing_conf_min_spacing_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_MIN_SPACING_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void natt_ntt_htp_min_spacing_conf_min_spacing_setf(uint8_t minspacing)
{
	ASSERT_ERR((((uint32_t)minspacing << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(NATT_NTT_HTP_MIN_SPACING_CONF_ADDR, (REG_PL_RD(NATT_NTT_HTP_MIN_SPACING_CONF_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)minspacing <<0));
}

/**
 * @brief NTT_HTP_DBG_CNT register definition
 *  Debug commands counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NTT_DBG_CNT               0x0
 * </pre>
 */
#define NATT_NTT_HTP_DBG_CNT_ADDR        (REG_NATT_BASE_ADDR+0x00000474)
#define NATT_NTT_HTP_DBG_CNT_OFFSET      0x00000474
#define NATT_NTT_HTP_DBG_CNT_INDEX       0x0000011D
#define NATT_NTT_HTP_DBG_CNT_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_dbg_cnt_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_DBG_CNT_ADDR);
}

__INLINE void natt_ntt_htp_dbg_cnt_set(uint32_t value)
{
	REG_PL_WR(NATT_NTT_HTP_DBG_CNT_ADDR, value);
}

// field definitions
#define NATT_NTT_HTP_DBG_CNT_NTT_DBG_CNT_MASK    ((uint32_t)0xFFFFFFFF)
#define NATT_NTT_HTP_DBG_CNT_NTT_DBG_CNT_LSB    0
#define NATT_NTT_HTP_DBG_CNT_NTT_DBG_CNT_WIDTH    ((uint32_t)0x00000020)

#define NATT_NTT_HTP_DBG_CNT_NTT_DBG_CNT_RST    0x0

__INLINE uint32_t natt_ntt_htp_dbg_cnt_ntt_dbg_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_DBG_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void natt_ntt_htp_dbg_cnt_ntt_dbg_cnt_setf(uint32_t nttdbgcnt)
{
	ASSERT_ERR((((uint32_t)nttdbgcnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(NATT_NTT_HTP_DBG_CNT_ADDR, (uint32_t)nttdbgcnt << 0);
}

/**
 * @brief NTT_HTP_PHY_RATE register definition
 *  Debug results of last packet (ndps+rate) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 NTT_PHY_RATE              0x0
 * </pre>
 */
#define NATT_NTT_HTP_PHY_RATE_ADDR        (REG_NATT_BASE_ADDR+0x00000478)
#define NATT_NTT_HTP_PHY_RATE_OFFSET      0x00000478
#define NATT_NTT_HTP_PHY_RATE_INDEX       0x0000011E
#define NATT_NTT_HTP_PHY_RATE_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_phy_rate_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_PHY_RATE_ADDR);
}

// field definitions
#define NATT_NTT_HTP_PHY_RATE_NTT_PHY_RATE_MASK    ((uint32_t)0x000FFFFF)
#define NATT_NTT_HTP_PHY_RATE_NTT_PHY_RATE_LSB    0
#define NATT_NTT_HTP_PHY_RATE_NTT_PHY_RATE_WIDTH    ((uint32_t)0x00000014)

#define NATT_NTT_HTP_PHY_RATE_NTT_PHY_RATE_RST    0x0

__INLINE uint32_t natt_ntt_htp_phy_rate_ntt_phy_rate_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_PHY_RATE_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_HTP_NDBPS register definition
 *  Number of data bits per symbol register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:00 NTT_NDBPS                 0x0
 * </pre>
 */
#define NATT_NTT_HTP_NDBPS_ADDR        (REG_NATT_BASE_ADDR+0x0000047C)
#define NATT_NTT_HTP_NDBPS_OFFSET      0x0000047C
#define NATT_NTT_HTP_NDBPS_INDEX       0x0000011F
#define NATT_NTT_HTP_NDBPS_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_ndbps_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_NDBPS_ADDR);
}

// field definitions
#define NATT_NTT_HTP_NDBPS_NTT_NDBPS_MASK    ((uint32_t)0x000FFFFF)
#define NATT_NTT_HTP_NDBPS_NTT_NDBPS_LSB    0
#define NATT_NTT_HTP_NDBPS_NTT_NDBPS_WIDTH    ((uint32_t)0x00000014)

#define NATT_NTT_HTP_NDBPS_NTT_NDBPS_RST    0x0

__INLINE uint32_t natt_ntt_htp_ndbps_ntt_ndbps_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_NDBPS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_HTP_SYM_TIME register definition
 *  Debug results of last packet (symbols+datatime) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 NTT_SYMBOLS               0x0
 *    15:00 NTT_DAT_TIME              0x0
 * </pre>
 */
#define NATT_NTT_HTP_SYM_TIME_ADDR        (REG_NATT_BASE_ADDR+0x00000480)
#define NATT_NTT_HTP_SYM_TIME_OFFSET      0x00000480
#define NATT_NTT_HTP_SYM_TIME_INDEX       0x00000120
#define NATT_NTT_HTP_SYM_TIME_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_sym_time_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_SYM_TIME_ADDR);
}

// field definitions
#define NATT_NTT_HTP_SYM_TIME_NTT_SYMBOLS_MASK    ((uint32_t)0xFFFF0000)
#define NATT_NTT_HTP_SYM_TIME_NTT_SYMBOLS_LSB    16
#define NATT_NTT_HTP_SYM_TIME_NTT_SYMBOLS_WIDTH    ((uint32_t)0x00000010)
#define NATT_NTT_HTP_SYM_TIME_NTT_DAT_TIME_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_HTP_SYM_TIME_NTT_DAT_TIME_LSB    0
#define NATT_NTT_HTP_SYM_TIME_NTT_DAT_TIME_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_HTP_SYM_TIME_NTT_SYMBOLS_RST    0x0
#define NATT_NTT_HTP_SYM_TIME_NTT_DAT_TIME_RST    0x0

__INLINE void natt_ntt_htp_sym_time_unpack(uint16_t* ntt_symbols, uint16_t* ntt_dat_time)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_SYM_TIME_ADDR);

	*ntt_symbols = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ntt_dat_time = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t natt_ntt_htp_sym_time_ntt_symbols_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_SYM_TIME_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t natt_ntt_htp_sym_time_ntt_dat_time_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_SYM_TIME_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief NTT_HTP_TOT_TIME register definition
 *  Debug results of last packet (total time) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 NTT_TOT_TIME              0x0
 * </pre>
 */
#define NATT_NTT_HTP_TOT_TIME_ADDR        (REG_NATT_BASE_ADDR+0x00000484)
#define NATT_NTT_HTP_TOT_TIME_OFFSET      0x00000484
#define NATT_NTT_HTP_TOT_TIME_INDEX       0x00000121
#define NATT_NTT_HTP_TOT_TIME_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_tot_time_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_TOT_TIME_ADDR);
}

// field definitions
#define NATT_NTT_HTP_TOT_TIME_NTT_TOT_TIME_MASK    ((uint32_t)0x0000FFFF)
#define NATT_NTT_HTP_TOT_TIME_NTT_TOT_TIME_LSB    0
#define NATT_NTT_HTP_TOT_TIME_NTT_TOT_TIME_WIDTH    ((uint32_t)0x00000010)

#define NATT_NTT_HTP_TOT_TIME_NTT_TOT_TIME_RST    0x0

__INLINE uint16_t natt_ntt_htp_tot_time_ntt_tot_time_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_TOT_TIME_ADDR);
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief NTT_HTP_MPDU_NUM register definition
 *  Debug results of last packet (number of MPDUs) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    08:00 NTT_MPDU_NUM              0x0
 * </pre>
 */
#define NATT_NTT_HTP_MPDU_NUM_ADDR        (REG_NATT_BASE_ADDR+0x00000488)
#define NATT_NTT_HTP_MPDU_NUM_OFFSET      0x00000488
#define NATT_NTT_HTP_MPDU_NUM_INDEX       0x00000122
#define NATT_NTT_HTP_MPDU_NUM_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_mpdu_num_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_MPDU_NUM_ADDR);
}

// field definitions
#define NATT_NTT_HTP_MPDU_NUM_NTT_MPDU_NUM_MASK    ((uint32_t)0x000001FF)
#define NATT_NTT_HTP_MPDU_NUM_NTT_MPDU_NUM_LSB    0
#define NATT_NTT_HTP_MPDU_NUM_NTT_MPDU_NUM_WIDTH    ((uint32_t)0x00000009)

#define NATT_NTT_HTP_MPDU_NUM_NTT_MPDU_NUM_RST    0x0

__INLINE uint16_t natt_ntt_htp_mpdu_num_ntt_mpdu_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_MPDU_NUM_ADDR);
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief NTT_HTP_AMPDU_LEN register definition
 *  AMPDU actual length in bytes register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:00 NTT_AMPDU_LEN             0x0
 * </pre>
 */
#define NATT_NTT_HTP_AMPDU_LEN_ADDR        (REG_NATT_BASE_ADDR+0x0000048C)
#define NATT_NTT_HTP_AMPDU_LEN_OFFSET      0x0000048C
#define NATT_NTT_HTP_AMPDU_LEN_INDEX       0x00000123
#define NATT_NTT_HTP_AMPDU_LEN_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_ampdu_len_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_AMPDU_LEN_ADDR);
}

// field definitions
#define NATT_NTT_HTP_AMPDU_LEN_NTT_AMPDU_LEN_MASK    ((uint32_t)0x00FFFFFF)
#define NATT_NTT_HTP_AMPDU_LEN_NTT_AMPDU_LEN_LSB    0
#define NATT_NTT_HTP_AMPDU_LEN_NTT_AMPDU_LEN_WIDTH    ((uint32_t)0x00000018)

#define NATT_NTT_HTP_AMPDU_LEN_NTT_AMPDU_LEN_RST    0x0

__INLINE uint32_t natt_ntt_htp_ampdu_len_ntt_ampdu_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_AMPDU_LEN_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief NTT_HTP_MAX_AMPDU_LEN register definition
 *  MAX AMPDU Length in bytes register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:00 NTT_MAX_AMPDU_LEN         0x0
 * </pre>
 */
#define NATT_NTT_HTP_MAX_AMPDU_LEN_ADDR        (REG_NATT_BASE_ADDR+0x00000490)
#define NATT_NTT_HTP_MAX_AMPDU_LEN_OFFSET      0x00000490
#define NATT_NTT_HTP_MAX_AMPDU_LEN_INDEX       0x00000124
#define NATT_NTT_HTP_MAX_AMPDU_LEN_RESET       0x00000000

__INLINE uint32_t  natt_ntt_htp_max_ampdu_len_get(void)
{
	return REG_PL_RD(NATT_NTT_HTP_MAX_AMPDU_LEN_ADDR);
}

// field definitions
#define NATT_NTT_HTP_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_MASK    ((uint32_t)0x00FFFFFF)
#define NATT_NTT_HTP_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_LSB    0
#define NATT_NTT_HTP_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_WIDTH    ((uint32_t)0x00000018)

#define NATT_NTT_HTP_MAX_AMPDU_LEN_NTT_MAX_AMPDU_LEN_RST    0x0

__INLINE uint32_t natt_ntt_htp_max_ampdu_len_ntt_max_ampdu_len_getf(void)
{
	uint32_t localVal = REG_PL_RD(NATT_NTT_HTP_MAX_AMPDU_LEN_ADDR);
	return (uint32_t)(localVal >> 0);
}


#undef DBG_FILEID
#endif //_REG_NATT_H_
