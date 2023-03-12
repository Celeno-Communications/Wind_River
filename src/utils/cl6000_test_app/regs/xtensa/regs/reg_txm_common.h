#ifndef _REG_TXM_COMMON_H_
#define _REG_TXM_COMMON_H_

#include <stdint.h>
#include "_reg_txm_common.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_TXM_COMMON__H__FILEID__

#define REG_TXM_COMMON_COUNT  22


/**
 * @brief TXM_SW_RST register definition
 *  Setting this bit resets the TXM register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    SW_RST                    0              
 * </pre>
 */
#define TXM_COMMON_TXM_SW_RST_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x00000000)
#define TXM_COMMON_TXM_SW_RST_OFFSET      0x00000000
#define TXM_COMMON_TXM_SW_RST_INDEX       0x00000000
#define TXM_COMMON_TXM_SW_RST_RESET       0x00000000

__INLINE void txm_common_txm_sw_rst_set(uint32_t value)
{
	REG_PL_WR(TXM_COMMON_TXM_SW_RST_ADDR, value);
}

// field definitions
#define TXM_COMMON_TXM_SW_RST_SW_RST_BIT    ((uint32_t)0x00000001)
#define TXM_COMMON_TXM_SW_RST_SW_RST_POS    0

#define TXM_COMMON_TXM_SW_RST_SW_RST_RST    0x0

__INLINE void txm_common_txm_sw_rst_sw_rst_setf(uint8_t swrst)
{
	ASSERT_ERR((((uint32_t)swrst << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_SW_RST_ADDR, (uint32_t)swrst << 0);
}

/**
 * @brief TXM_MODES register definition
 *  General TXM modes register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    E2_W_ACTIVATION           1              
 *    00    HB_MODE                   0              
 * </pre>
 */
#define TXM_COMMON_TXM_MODES_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x00000004)
#define TXM_COMMON_TXM_MODES_OFFSET      0x00000004
#define TXM_COMMON_TXM_MODES_INDEX       0x00000001
#define TXM_COMMON_TXM_MODES_RESET       0x00000002

__INLINE uint32_t  txm_common_txm_modes_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_MODES_ADDR);
}

__INLINE void txm_common_txm_modes_set(uint32_t value)
{
	REG_PL_WR(TXM_COMMON_TXM_MODES_ADDR, value);
}

// field definitions
#define TXM_COMMON_TXM_MODES_E_2_W_ACTIVATION_BIT    ((uint32_t)0x00000002)
#define TXM_COMMON_TXM_MODES_E_2_W_ACTIVATION_POS    1
#define TXM_COMMON_TXM_MODES_HB_MODE_BIT    ((uint32_t)0x00000001)
#define TXM_COMMON_TXM_MODES_HB_MODE_POS    0

#define TXM_COMMON_TXM_MODES_E_2_W_ACTIVATION_RST    0x1
#define TXM_COMMON_TXM_MODES_HB_MODE_RST    0x0

__INLINE void txm_common_txm_modes_pack(uint8_t e2_w_activation, uint8_t hb_mode)
{
	ASSERT_ERR((((uint32_t)e2_w_activation << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)hb_mode << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_MODES_ADDR,  ((uint32_t)e2_w_activation << 1) |((uint32_t)hb_mode << 0));
}

__INLINE void txm_common_txm_modes_unpack(uint8_t* e2_w_activation, uint8_t* hb_mode)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_MODES_ADDR);

	*e2_w_activation = (localVal & ((uint32_t)0x00000002)) >>  1;
	*hb_mode = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t txm_common_txm_modes_e_2_w_activation_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_MODES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void txm_common_txm_modes_e_2_w_activation_setf(uint8_t e2wactivation)
{
	ASSERT_ERR((((uint32_t)e2wactivation << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_MODES_ADDR, (REG_PL_RD(TXM_COMMON_TXM_MODES_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)e2wactivation <<1));
}
__INLINE uint8_t txm_common_txm_modes_hb_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_MODES_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void txm_common_txm_modes_hb_mode_setf(uint8_t hbmode)
{
	ASSERT_ERR((((uint32_t)hbmode << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_MODES_ADDR, (REG_PL_RD(TXM_COMMON_TXM_MODES_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)hbmode <<0));
}

/**
 * @brief TXM_INT_RAWSTAT register definition
 *  Raw interrupt all streams register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    ERR                       0              
 *    04    PRF_BUFF_FULL             0              
 *    03    THD_DONE                  0              
 *    02    STR_BUFF_FREE             0              
 *    01    STR_INACTIVE              0              
 *    00    TXD_PREFETCH_END          0              
 * </pre>
 */
#define TXM_COMMON_TXM_INT_RAWSTAT_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x00000008)
#define TXM_COMMON_TXM_INT_RAWSTAT_OFFSET      0x00000008
#define TXM_COMMON_TXM_INT_RAWSTAT_INDEX       0x00000002
#define TXM_COMMON_TXM_INT_RAWSTAT_RESET       0x00000000

__INLINE uint32_t  txm_common_txm_int_rawstat_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_INT_RAWSTAT_ADDR);
}

// field definitions
#define TXM_COMMON_TXM_INT_RAWSTAT_ERR_BIT    ((uint32_t)0x00000020)
#define TXM_COMMON_TXM_INT_RAWSTAT_ERR_POS    5
#define TXM_COMMON_TXM_INT_RAWSTAT_PRF_BUFF_FULL_BIT    ((uint32_t)0x00000010)
#define TXM_COMMON_TXM_INT_RAWSTAT_PRF_BUFF_FULL_POS    4
#define TXM_COMMON_TXM_INT_RAWSTAT_THD_DONE_BIT    ((uint32_t)0x00000008)
#define TXM_COMMON_TXM_INT_RAWSTAT_THD_DONE_POS    3
#define TXM_COMMON_TXM_INT_RAWSTAT_STR_BUFF_FREE_BIT    ((uint32_t)0x00000004)
#define TXM_COMMON_TXM_INT_RAWSTAT_STR_BUFF_FREE_POS    2
#define TXM_COMMON_TXM_INT_RAWSTAT_STR_INACTIVE_BIT    ((uint32_t)0x00000002)
#define TXM_COMMON_TXM_INT_RAWSTAT_STR_INACTIVE_POS    1
#define TXM_COMMON_TXM_INT_RAWSTAT_TXD_PREFETCH_END_BIT    ((uint32_t)0x00000001)
#define TXM_COMMON_TXM_INT_RAWSTAT_TXD_PREFETCH_END_POS    0

#define TXM_COMMON_TXM_INT_RAWSTAT_ERR_RST    0x0
#define TXM_COMMON_TXM_INT_RAWSTAT_PRF_BUFF_FULL_RST    0x0
#define TXM_COMMON_TXM_INT_RAWSTAT_THD_DONE_RST    0x0
#define TXM_COMMON_TXM_INT_RAWSTAT_STR_BUFF_FREE_RST    0x0
#define TXM_COMMON_TXM_INT_RAWSTAT_STR_INACTIVE_RST    0x0
#define TXM_COMMON_TXM_INT_RAWSTAT_TXD_PREFETCH_END_RST    0x0

__INLINE void txm_common_txm_int_rawstat_unpack(uint8_t* err, uint8_t* prf_buff_full, uint8_t* thd_done, uint8_t* str_buff_free, uint8_t* str_inactive, uint8_t* txd_prefetch_end)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_RAWSTAT_ADDR);

	*err = (localVal & ((uint32_t)0x00000020)) >>  5;
	*prf_buff_full = (localVal & ((uint32_t)0x00000010)) >>  4;
	*thd_done = (localVal & ((uint32_t)0x00000008)) >>  3;
	*str_buff_free = (localVal & ((uint32_t)0x00000004)) >>  2;
	*str_inactive = (localVal & ((uint32_t)0x00000002)) >>  1;
	*txd_prefetch_end = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t txm_common_txm_int_rawstat_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_RAWSTAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t txm_common_txm_int_rawstat_prf_buff_full_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_RAWSTAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t txm_common_txm_int_rawstat_thd_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_RAWSTAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t txm_common_txm_int_rawstat_str_buff_free_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_RAWSTAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t txm_common_txm_int_rawstat_str_inactive_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_RAWSTAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t txm_common_txm_int_rawstat_txd_prefetch_end_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_RAWSTAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief TXM_INT_STAT register definition
 *  Interrupt after enable register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    ERR                       0              
 *    04    PRF_BUFF_OVERFLOW         0              
 *    03    THD_DONE_EN               0              
 *    02    STR_BUFF_FREE             0              
 *    01    STR_INACTIVE              0              
 *    00    TXD_PREFETCH_END          0              
 * </pre>
 */
#define TXM_COMMON_TXM_INT_STAT_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x00000010)
#define TXM_COMMON_TXM_INT_STAT_OFFSET      0x00000010
#define TXM_COMMON_TXM_INT_STAT_INDEX       0x00000004
#define TXM_COMMON_TXM_INT_STAT_RESET       0x00000000

__INLINE uint32_t  txm_common_txm_int_stat_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_INT_STAT_ADDR);
}

// field definitions
#define TXM_COMMON_TXM_INT_STAT_ERR_BIT     ((uint32_t)0x00000020)
#define TXM_COMMON_TXM_INT_STAT_ERR_POS     5
#define TXM_COMMON_TXM_INT_STAT_PRF_BUFF_OVERFLOW_BIT    ((uint32_t)0x00000010)
#define TXM_COMMON_TXM_INT_STAT_PRF_BUFF_OVERFLOW_POS    4
#define TXM_COMMON_TXM_INT_STAT_THD_DONE_EN_BIT    ((uint32_t)0x00000008)
#define TXM_COMMON_TXM_INT_STAT_THD_DONE_EN_POS    3
#define TXM_COMMON_TXM_INT_STAT_STR_BUFF_FREE_BIT    ((uint32_t)0x00000004)
#define TXM_COMMON_TXM_INT_STAT_STR_BUFF_FREE_POS    2
#define TXM_COMMON_TXM_INT_STAT_STR_INACTIVE_BIT    ((uint32_t)0x00000002)
#define TXM_COMMON_TXM_INT_STAT_STR_INACTIVE_POS    1
#define TXM_COMMON_TXM_INT_STAT_TXD_PREFETCH_END_BIT    ((uint32_t)0x00000001)
#define TXM_COMMON_TXM_INT_STAT_TXD_PREFETCH_END_POS    0

#define TXM_COMMON_TXM_INT_STAT_ERR_RST     0x0
#define TXM_COMMON_TXM_INT_STAT_PRF_BUFF_OVERFLOW_RST    0x0
#define TXM_COMMON_TXM_INT_STAT_THD_DONE_EN_RST    0x0
#define TXM_COMMON_TXM_INT_STAT_STR_BUFF_FREE_RST    0x0
#define TXM_COMMON_TXM_INT_STAT_STR_INACTIVE_RST    0x0
#define TXM_COMMON_TXM_INT_STAT_TXD_PREFETCH_END_RST    0x0

__INLINE void txm_common_txm_int_stat_unpack(uint8_t* err, uint8_t* prf_buff_overflow, uint8_t* thd_done_en, uint8_t* str_buff_free, uint8_t* str_inactive, uint8_t* txd_prefetch_end)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_STAT_ADDR);

	*err = (localVal & ((uint32_t)0x00000020)) >>  5;
	*prf_buff_overflow = (localVal & ((uint32_t)0x00000010)) >>  4;
	*thd_done_en = (localVal & ((uint32_t)0x00000008)) >>  3;
	*str_buff_free = (localVal & ((uint32_t)0x00000004)) >>  2;
	*str_inactive = (localVal & ((uint32_t)0x00000002)) >>  1;
	*txd_prefetch_end = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t txm_common_txm_int_stat_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t txm_common_txm_int_stat_prf_buff_overflow_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t txm_common_txm_int_stat_thd_done_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t txm_common_txm_int_stat_str_buff_free_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t txm_common_txm_int_stat_str_inactive_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t txm_common_txm_int_stat_txd_prefetch_end_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief TXM_INT_FORCE register definition
 *  Force interrupt for debug register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    ERR_FORCE                 0              
 *    04    PRF_BUFF_OVERFLOW         0              
 *    03    THD_DONE_FORCE            0              
 *    02    STR_BUFF_FREE_FORCE       0              
 *    01    STR_INACTIVE_FORCE        0              
 *    00    TXD_PREFETCH_END_FORCE    0              
 * </pre>
 */
#define TXM_COMMON_TXM_INT_FORCE_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x00000018)
#define TXM_COMMON_TXM_INT_FORCE_OFFSET      0x00000018
#define TXM_COMMON_TXM_INT_FORCE_INDEX       0x00000006
#define TXM_COMMON_TXM_INT_FORCE_RESET       0x00000000

__INLINE uint32_t  txm_common_txm_int_force_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_INT_FORCE_ADDR);
}

__INLINE void txm_common_txm_int_force_set(uint32_t value)
{
	REG_PL_WR(TXM_COMMON_TXM_INT_FORCE_ADDR, value);
}

// field definitions
#define TXM_COMMON_TXM_INT_FORCE_ERR_FORCE_BIT    ((uint32_t)0x00000020)
#define TXM_COMMON_TXM_INT_FORCE_ERR_FORCE_POS    5
#define TXM_COMMON_TXM_INT_FORCE_PRF_BUFF_OVERFLOW_BIT    ((uint32_t)0x00000010)
#define TXM_COMMON_TXM_INT_FORCE_PRF_BUFF_OVERFLOW_POS    4
#define TXM_COMMON_TXM_INT_FORCE_THD_DONE_FORCE_BIT    ((uint32_t)0x00000008)
#define TXM_COMMON_TXM_INT_FORCE_THD_DONE_FORCE_POS    3
#define TXM_COMMON_TXM_INT_FORCE_STR_BUFF_FREE_FORCE_BIT    ((uint32_t)0x00000004)
#define TXM_COMMON_TXM_INT_FORCE_STR_BUFF_FREE_FORCE_POS    2
#define TXM_COMMON_TXM_INT_FORCE_STR_INACTIVE_FORCE_BIT    ((uint32_t)0x00000002)
#define TXM_COMMON_TXM_INT_FORCE_STR_INACTIVE_FORCE_POS    1
#define TXM_COMMON_TXM_INT_FORCE_TXD_PREFETCH_END_FORCE_BIT    ((uint32_t)0x00000001)
#define TXM_COMMON_TXM_INT_FORCE_TXD_PREFETCH_END_FORCE_POS    0

#define TXM_COMMON_TXM_INT_FORCE_ERR_FORCE_RST    0x0
#define TXM_COMMON_TXM_INT_FORCE_PRF_BUFF_OVERFLOW_RST    0x0
#define TXM_COMMON_TXM_INT_FORCE_THD_DONE_FORCE_RST    0x0
#define TXM_COMMON_TXM_INT_FORCE_STR_BUFF_FREE_FORCE_RST    0x0
#define TXM_COMMON_TXM_INT_FORCE_STR_INACTIVE_FORCE_RST    0x0
#define TXM_COMMON_TXM_INT_FORCE_TXD_PREFETCH_END_FORCE_RST    0x0

__INLINE void txm_common_txm_int_force_pack(uint8_t err_force, uint8_t prf_buff_overflow, uint8_t thd_done_force, uint8_t str_buff_free_force, uint8_t str_inactive_force, uint8_t txd_prefetch_end_force)
{
	ASSERT_ERR((((uint32_t)err_force << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)prf_buff_overflow << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)thd_done_force << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)str_buff_free_force << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)str_inactive_force << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)txd_prefetch_end_force << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_INT_FORCE_ADDR,  ((uint32_t)err_force << 5) |((uint32_t)prf_buff_overflow << 4) |((uint32_t)thd_done_force << 3) |((uint32_t)str_buff_free_force << 2) |((uint32_t)str_inactive_force << 1) |((uint32_t)txd_prefetch_end_force << 0));
}

__INLINE void txm_common_txm_int_force_unpack(uint8_t* err_force, uint8_t* prf_buff_overflow, uint8_t* thd_done_force, uint8_t* str_buff_free_force, uint8_t* str_inactive_force, uint8_t* txd_prefetch_end_force)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_FORCE_ADDR);

	*err_force = (localVal & ((uint32_t)0x00000020)) >>  5;
	*prf_buff_overflow = (localVal & ((uint32_t)0x00000010)) >>  4;
	*thd_done_force = (localVal & ((uint32_t)0x00000008)) >>  3;
	*str_buff_free_force = (localVal & ((uint32_t)0x00000004)) >>  2;
	*str_inactive_force = (localVal & ((uint32_t)0x00000002)) >>  1;
	*txd_prefetch_end_force = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t txm_common_txm_int_force_err_force_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_FORCE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void txm_common_txm_int_force_err_force_setf(uint8_t errforce)
{
	ASSERT_ERR((((uint32_t)errforce << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_INT_FORCE_ADDR, (REG_PL_RD(TXM_COMMON_TXM_INT_FORCE_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)errforce <<5));
}
__INLINE uint8_t txm_common_txm_int_force_prf_buff_overflow_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_FORCE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void txm_common_txm_int_force_prf_buff_overflow_setf(uint8_t prfbuffoverflow)
{
	ASSERT_ERR((((uint32_t)prfbuffoverflow << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_INT_FORCE_ADDR, (REG_PL_RD(TXM_COMMON_TXM_INT_FORCE_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)prfbuffoverflow <<4));
}
__INLINE uint8_t txm_common_txm_int_force_thd_done_force_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_FORCE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void txm_common_txm_int_force_thd_done_force_setf(uint8_t thddoneforce)
{
	ASSERT_ERR((((uint32_t)thddoneforce << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_INT_FORCE_ADDR, (REG_PL_RD(TXM_COMMON_TXM_INT_FORCE_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)thddoneforce <<3));
}
__INLINE uint8_t txm_common_txm_int_force_str_buff_free_force_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_FORCE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void txm_common_txm_int_force_str_buff_free_force_setf(uint8_t strbufffreeforce)
{
	ASSERT_ERR((((uint32_t)strbufffreeforce << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_INT_FORCE_ADDR, (REG_PL_RD(TXM_COMMON_TXM_INT_FORCE_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)strbufffreeforce <<2));
}
__INLINE uint8_t txm_common_txm_int_force_str_inactive_force_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_FORCE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void txm_common_txm_int_force_str_inactive_force_setf(uint8_t strinactiveforce)
{
	ASSERT_ERR((((uint32_t)strinactiveforce << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_INT_FORCE_ADDR, (REG_PL_RD(TXM_COMMON_TXM_INT_FORCE_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)strinactiveforce <<1));
}
__INLINE uint8_t txm_common_txm_int_force_txd_prefetch_end_force_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_FORCE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void txm_common_txm_int_force_txd_prefetch_end_force_setf(uint8_t txdprefetchendforce)
{
	ASSERT_ERR((((uint32_t)txdprefetchendforce << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_INT_FORCE_ADDR, (REG_PL_RD(TXM_COMMON_TXM_INT_FORCE_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)txdprefetchendforce <<0));
}

/**
 * @brief TXM_INT_R_0_1_STR_BMAP register definition
 *  Streams bitmap interrupt reasons 0 and 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:16 INT_R1_STR_BMAP           0x0
 *    10:00 INT_R0_STR_BMAP           0x0
 * </pre>
 */
#define TXM_COMMON_TXM_INT_R_0_1_STR_BMAP_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x0000001C)
#define TXM_COMMON_TXM_INT_R_0_1_STR_BMAP_OFFSET      0x0000001C
#define TXM_COMMON_TXM_INT_R_0_1_STR_BMAP_INDEX       0x00000007
#define TXM_COMMON_TXM_INT_R_0_1_STR_BMAP_RESET       0x00000000

__INLINE uint32_t  txm_common_txm_int_r_0_1_str_bmap_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_INT_R_0_1_STR_BMAP_ADDR);
}

// field definitions
#define TXM_COMMON_TXM_INT_R_0_1_STR_BMAP_INT_R_1_STR_BMAP_MASK    ((uint32_t)0x07FF0000)
#define TXM_COMMON_TXM_INT_R_0_1_STR_BMAP_INT_R_1_STR_BMAP_LSB    16
#define TXM_COMMON_TXM_INT_R_0_1_STR_BMAP_INT_R_1_STR_BMAP_WIDTH    ((uint32_t)0x0000000B)
#define TXM_COMMON_TXM_INT_R_0_1_STR_BMAP_INT_R_0_STR_BMAP_MASK    ((uint32_t)0x000007FF)
#define TXM_COMMON_TXM_INT_R_0_1_STR_BMAP_INT_R_0_STR_BMAP_LSB    0
#define TXM_COMMON_TXM_INT_R_0_1_STR_BMAP_INT_R_0_STR_BMAP_WIDTH    ((uint32_t)0x0000000B)

#define TXM_COMMON_TXM_INT_R_0_1_STR_BMAP_INT_R_1_STR_BMAP_RST    0x0
#define TXM_COMMON_TXM_INT_R_0_1_STR_BMAP_INT_R_0_STR_BMAP_RST    0x0

__INLINE void txm_common_txm_int_r_0_1_str_bmap_unpack(uint16_t* int_r1_str_bmap, uint16_t* int_r0_str_bmap)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_R_0_1_STR_BMAP_ADDR);

	*int_r1_str_bmap = (localVal & ((uint32_t)0x07FF0000)) >>  16;
	*int_r0_str_bmap = (localVal & ((uint32_t)0x000007FF)) >>  0;
}

__INLINE uint16_t txm_common_txm_int_r_0_1_str_bmap_int_r_1_str_bmap_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_R_0_1_STR_BMAP_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x07FF0000)) >> 16);
}
__INLINE uint16_t txm_common_txm_int_r_0_1_str_bmap_int_r_0_str_bmap_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_R_0_1_STR_BMAP_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000007FF)) >> 0);
}

/**
 * @brief TXM_INT_R_2_3_STR_BMAP register definition
 *  Streams bitmap interrupt reasons 2 and 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:16 INT_R3_STR_BMAP           0x0
 *    10:00 INT_R2_STR_BMAP           0x0
 * </pre>
 */
#define TXM_COMMON_TXM_INT_R_2_3_STR_BMAP_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x00000020)
#define TXM_COMMON_TXM_INT_R_2_3_STR_BMAP_OFFSET      0x00000020
#define TXM_COMMON_TXM_INT_R_2_3_STR_BMAP_INDEX       0x00000008
#define TXM_COMMON_TXM_INT_R_2_3_STR_BMAP_RESET       0x00000000

__INLINE uint32_t  txm_common_txm_int_r_2_3_str_bmap_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_INT_R_2_3_STR_BMAP_ADDR);
}

// field definitions
#define TXM_COMMON_TXM_INT_R_2_3_STR_BMAP_INT_R_3_STR_BMAP_MASK    ((uint32_t)0x07FF0000)
#define TXM_COMMON_TXM_INT_R_2_3_STR_BMAP_INT_R_3_STR_BMAP_LSB    16
#define TXM_COMMON_TXM_INT_R_2_3_STR_BMAP_INT_R_3_STR_BMAP_WIDTH    ((uint32_t)0x0000000B)
#define TXM_COMMON_TXM_INT_R_2_3_STR_BMAP_INT_R_2_STR_BMAP_MASK    ((uint32_t)0x000007FF)
#define TXM_COMMON_TXM_INT_R_2_3_STR_BMAP_INT_R_2_STR_BMAP_LSB    0
#define TXM_COMMON_TXM_INT_R_2_3_STR_BMAP_INT_R_2_STR_BMAP_WIDTH    ((uint32_t)0x0000000B)

#define TXM_COMMON_TXM_INT_R_2_3_STR_BMAP_INT_R_3_STR_BMAP_RST    0x0
#define TXM_COMMON_TXM_INT_R_2_3_STR_BMAP_INT_R_2_STR_BMAP_RST    0x0

__INLINE void txm_common_txm_int_r_2_3_str_bmap_unpack(uint16_t* int_r3_str_bmap, uint16_t* int_r2_str_bmap)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_R_2_3_STR_BMAP_ADDR);

	*int_r3_str_bmap = (localVal & ((uint32_t)0x07FF0000)) >>  16;
	*int_r2_str_bmap = (localVal & ((uint32_t)0x000007FF)) >>  0;
}

__INLINE uint16_t txm_common_txm_int_r_2_3_str_bmap_int_r_3_str_bmap_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_R_2_3_STR_BMAP_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x07FF0000)) >> 16);
}
__INLINE uint16_t txm_common_txm_int_r_2_3_str_bmap_int_r_2_str_bmap_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_R_2_3_STR_BMAP_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000007FF)) >> 0);
}

/**
 * @brief TXM_INT_R_4_5_STR_BMAP register definition
 *  Streams bitmap interrupt reason 4 and 5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:16 INT_R5_STR_BMAP           0x0
 *    10:00 INT_R4_STR_BMAP           0x0
 * </pre>
 */
#define TXM_COMMON_TXM_INT_R_4_5_STR_BMAP_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x00000024)
#define TXM_COMMON_TXM_INT_R_4_5_STR_BMAP_OFFSET      0x00000024
#define TXM_COMMON_TXM_INT_R_4_5_STR_BMAP_INDEX       0x00000009
#define TXM_COMMON_TXM_INT_R_4_5_STR_BMAP_RESET       0x00000000

__INLINE uint32_t  txm_common_txm_int_r_4_5_str_bmap_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_INT_R_4_5_STR_BMAP_ADDR);
}

// field definitions
#define TXM_COMMON_TXM_INT_R_4_5_STR_BMAP_INT_R_5_STR_BMAP_MASK    ((uint32_t)0x07FF0000)
#define TXM_COMMON_TXM_INT_R_4_5_STR_BMAP_INT_R_5_STR_BMAP_LSB    16
#define TXM_COMMON_TXM_INT_R_4_5_STR_BMAP_INT_R_5_STR_BMAP_WIDTH    ((uint32_t)0x0000000B)
#define TXM_COMMON_TXM_INT_R_4_5_STR_BMAP_INT_R_4_STR_BMAP_MASK    ((uint32_t)0x000007FF)
#define TXM_COMMON_TXM_INT_R_4_5_STR_BMAP_INT_R_4_STR_BMAP_LSB    0
#define TXM_COMMON_TXM_INT_R_4_5_STR_BMAP_INT_R_4_STR_BMAP_WIDTH    ((uint32_t)0x0000000B)

#define TXM_COMMON_TXM_INT_R_4_5_STR_BMAP_INT_R_5_STR_BMAP_RST    0x0
#define TXM_COMMON_TXM_INT_R_4_5_STR_BMAP_INT_R_4_STR_BMAP_RST    0x0

__INLINE void txm_common_txm_int_r_4_5_str_bmap_unpack(uint16_t* int_r5_str_bmap, uint16_t* int_r4_str_bmap)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_R_4_5_STR_BMAP_ADDR);

	*int_r5_str_bmap = (localVal & ((uint32_t)0x07FF0000)) >>  16;
	*int_r4_str_bmap = (localVal & ((uint32_t)0x000007FF)) >>  0;
}

__INLINE uint16_t txm_common_txm_int_r_4_5_str_bmap_int_r_5_str_bmap_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_R_4_5_STR_BMAP_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x07FF0000)) >> 16);
}
__INLINE uint16_t txm_common_txm_int_r_4_5_str_bmap_int_r_4_str_bmap_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_R_4_5_STR_BMAP_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000007FF)) >> 0);
}

/**
 * @brief TXM_INT_ALL_STR_BMAP register definition
 *  Streams bitmap indicating any interrupt reason register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    10:00 INT_ALL_STR_BMAP          0x0
 * </pre>
 */
#define TXM_COMMON_TXM_INT_ALL_STR_BMAP_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x00000028)
#define TXM_COMMON_TXM_INT_ALL_STR_BMAP_OFFSET      0x00000028
#define TXM_COMMON_TXM_INT_ALL_STR_BMAP_INDEX       0x0000000A
#define TXM_COMMON_TXM_INT_ALL_STR_BMAP_RESET       0x00000000

__INLINE uint32_t  txm_common_txm_int_all_str_bmap_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_INT_ALL_STR_BMAP_ADDR);
}

// field definitions
#define TXM_COMMON_TXM_INT_ALL_STR_BMAP_INT_ALL_STR_BMAP_MASK    ((uint32_t)0x000007FF)
#define TXM_COMMON_TXM_INT_ALL_STR_BMAP_INT_ALL_STR_BMAP_LSB    0
#define TXM_COMMON_TXM_INT_ALL_STR_BMAP_INT_ALL_STR_BMAP_WIDTH    ((uint32_t)0x0000000B)

#define TXM_COMMON_TXM_INT_ALL_STR_BMAP_INT_ALL_STR_BMAP_RST    0x0

__INLINE uint16_t txm_common_txm_int_all_str_bmap_int_all_str_bmap_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_INT_ALL_STR_BMAP_ADDR);
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief TXM_TXD_INFO register definition
 *  TXD fields offset register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:16 TXD_PACKET_ADDR_OFFSET    0x1c
 *    15:08 TXD_E2_W_NATT_PARAM_OFFSET 0x14
 *    07:00 TXD_TX_HOST_INFO_OFFSET   0x10
 * </pre>
 */
#define TXM_COMMON_TXM_TXD_INFO_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x00000030)
#define TXM_COMMON_TXM_TXD_INFO_OFFSET      0x00000030
#define TXM_COMMON_TXM_TXD_INFO_INDEX       0x0000000C
#define TXM_COMMON_TXM_TXD_INFO_RESET       0x001C1410

__INLINE uint32_t  txm_common_txm_txd_info_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_TXD_INFO_ADDR);
}

__INLINE void txm_common_txm_txd_info_set(uint32_t value)
{
	REG_PL_WR(TXM_COMMON_TXM_TXD_INFO_ADDR, value);
}

// field definitions
#define TXM_COMMON_TXM_TXD_INFO_TXD_PACKET_ADDR_OFFSET_MASK    ((uint32_t)0x00FF0000)
#define TXM_COMMON_TXM_TXD_INFO_TXD_PACKET_ADDR_OFFSET_LSB    16
#define TXM_COMMON_TXM_TXD_INFO_TXD_PACKET_ADDR_OFFSET_WIDTH    ((uint32_t)0x00000008)
#define TXM_COMMON_TXM_TXD_INFO_TXD_E_2_W_NATT_PARAM_OFFSET_MASK    ((uint32_t)0x0000FF00)
#define TXM_COMMON_TXM_TXD_INFO_TXD_E_2_W_NATT_PARAM_OFFSET_LSB    8
#define TXM_COMMON_TXM_TXD_INFO_TXD_E_2_W_NATT_PARAM_OFFSET_WIDTH    ((uint32_t)0x00000008)
#define TXM_COMMON_TXM_TXD_INFO_TXD_TX_HOST_INFO_OFFSET_MASK    ((uint32_t)0x000000FF)
#define TXM_COMMON_TXM_TXD_INFO_TXD_TX_HOST_INFO_OFFSET_LSB    0
#define TXM_COMMON_TXM_TXD_INFO_TXD_TX_HOST_INFO_OFFSET_WIDTH    ((uint32_t)0x00000008)

#define TXM_COMMON_TXM_TXD_INFO_TXD_PACKET_ADDR_OFFSET_RST    0x1c
#define TXM_COMMON_TXM_TXD_INFO_TXD_E_2_W_NATT_PARAM_OFFSET_RST    0x14
#define TXM_COMMON_TXM_TXD_INFO_TXD_TX_HOST_INFO_OFFSET_RST    0x10

__INLINE void txm_common_txm_txd_info_pack(uint8_t txd_packet_addr_offset, uint8_t txd_e2_w_natt_param_offset, uint8_t txd_tx_host_info_offset)
{
	ASSERT_ERR((((uint32_t)txd_packet_addr_offset << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)txd_e2_w_natt_param_offset << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)txd_tx_host_info_offset << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_TXD_INFO_ADDR,  ((uint32_t)txd_packet_addr_offset << 16) |((uint32_t)txd_e2_w_natt_param_offset << 8) |((uint32_t)txd_tx_host_info_offset << 0));
}

__INLINE void txm_common_txm_txd_info_unpack(uint8_t* txd_packet_addr_offset, uint8_t* txd_e2_w_natt_param_offset, uint8_t* txd_tx_host_info_offset)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_TXD_INFO_ADDR);

	*txd_packet_addr_offset = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*txd_e2_w_natt_param_offset = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*txd_tx_host_info_offset = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t txm_common_txm_txd_info_txd_packet_addr_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_TXD_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void txm_common_txm_txd_info_txd_packet_addr_offset_setf(uint8_t txdpacketaddroffset)
{
	ASSERT_ERR((((uint32_t)txdpacketaddroffset << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_TXD_INFO_ADDR, (REG_PL_RD(TXM_COMMON_TXM_TXD_INFO_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)txdpacketaddroffset <<16));
}
__INLINE uint8_t txm_common_txm_txd_info_txd_e_2_w_natt_param_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_TXD_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void txm_common_txm_txd_info_txd_e_2_w_natt_param_offset_setf(uint8_t txde2wnattparamoffset)
{
	ASSERT_ERR((((uint32_t)txde2wnattparamoffset << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_TXD_INFO_ADDR, (REG_PL_RD(TXM_COMMON_TXM_TXD_INFO_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)txde2wnattparamoffset <<8));
}
__INLINE uint8_t txm_common_txm_txd_info_txd_tx_host_info_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_TXD_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void txm_common_txm_txd_info_txd_tx_host_info_offset_setf(uint8_t txdtxhostinfooffset)
{
	ASSERT_ERR((((uint32_t)txdtxhostinfooffset << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_TXD_INFO_ADDR, (REG_PL_RD(TXM_COMMON_TXM_TXD_INFO_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)txdtxhostinfooffset <<0));
}

/**
 * @brief TXM_TXB_INFO register definition
 *  TXB global info register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:08 MSDU_HEAD_ROOM_SIZE       0x8
 *    07:00 WLH_HEAD_ROOM_SIZE        0x34
 * </pre>
 */
#define TXM_COMMON_TXM_TXB_INFO_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x00000034)
#define TXM_COMMON_TXM_TXB_INFO_OFFSET      0x00000034
#define TXM_COMMON_TXM_TXB_INFO_INDEX       0x0000000D
#define TXM_COMMON_TXM_TXB_INFO_RESET       0x00000834

__INLINE uint32_t  txm_common_txm_txb_info_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_TXB_INFO_ADDR);
}

__INLINE void txm_common_txm_txb_info_set(uint32_t value)
{
	REG_PL_WR(TXM_COMMON_TXM_TXB_INFO_ADDR, value);
}

// field definitions
#define TXM_COMMON_TXM_TXB_INFO_MSDU_HEAD_ROOM_SIZE_MASK    ((uint32_t)0x0000FF00)
#define TXM_COMMON_TXM_TXB_INFO_MSDU_HEAD_ROOM_SIZE_LSB    8
#define TXM_COMMON_TXM_TXB_INFO_MSDU_HEAD_ROOM_SIZE_WIDTH    ((uint32_t)0x00000008)
#define TXM_COMMON_TXM_TXB_INFO_WLH_HEAD_ROOM_SIZE_MASK    ((uint32_t)0x000000FF)
#define TXM_COMMON_TXM_TXB_INFO_WLH_HEAD_ROOM_SIZE_LSB    0
#define TXM_COMMON_TXM_TXB_INFO_WLH_HEAD_ROOM_SIZE_WIDTH    ((uint32_t)0x00000008)

#define TXM_COMMON_TXM_TXB_INFO_MSDU_HEAD_ROOM_SIZE_RST    0x8
#define TXM_COMMON_TXM_TXB_INFO_WLH_HEAD_ROOM_SIZE_RST    0x34

__INLINE void txm_common_txm_txb_info_pack(uint8_t msdu_head_room_size, uint8_t wlh_head_room_size)
{
	ASSERT_ERR((((uint32_t)msdu_head_room_size << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)wlh_head_room_size << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_TXB_INFO_ADDR,  ((uint32_t)msdu_head_room_size << 8) |((uint32_t)wlh_head_room_size << 0));
}

__INLINE void txm_common_txm_txb_info_unpack(uint8_t* msdu_head_room_size, uint8_t* wlh_head_room_size)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_TXB_INFO_ADDR);

	*msdu_head_room_size = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*wlh_head_room_size = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t txm_common_txm_txb_info_msdu_head_room_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_TXB_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void txm_common_txm_txb_info_msdu_head_room_size_setf(uint8_t msduheadroomsize)
{
	ASSERT_ERR((((uint32_t)msduheadroomsize << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_TXB_INFO_ADDR, (REG_PL_RD(TXM_COMMON_TXM_TXB_INFO_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)msduheadroomsize <<8));
}
__INLINE uint8_t txm_common_txm_txb_info_wlh_head_room_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_TXB_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void txm_common_txm_txb_info_wlh_head_room_size_setf(uint8_t wlhheadroomsize)
{
	ASSERT_ERR((((uint32_t)wlhheadroomsize << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_TXB_INFO_ADDR, (REG_PL_RD(TXM_COMMON_TXM_TXB_INFO_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)wlhheadroomsize <<0));
}

/**
 * @brief TXM_MSDU_INFO register definition
 *  MSDU headers size register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:12 VLAN_TAG_SIZE             0x4
 *    11:08 LLC_SNAP_HEADER_SIZE      0x6
 *    07:05 SPARE                     0x0
 *    04:00 ETH_HEADER_SIZE           0xc
 * </pre>
 */
#define TXM_COMMON_TXM_MSDU_INFO_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x00000038)
#define TXM_COMMON_TXM_MSDU_INFO_OFFSET      0x00000038
#define TXM_COMMON_TXM_MSDU_INFO_INDEX       0x0000000E
#define TXM_COMMON_TXM_MSDU_INFO_RESET       0x0000460C

__INLINE uint32_t  txm_common_txm_msdu_info_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_MSDU_INFO_ADDR);
}

__INLINE void txm_common_txm_msdu_info_set(uint32_t value)
{
	REG_PL_WR(TXM_COMMON_TXM_MSDU_INFO_ADDR, value);
}

// field definitions
#define TXM_COMMON_TXM_MSDU_INFO_VLAN_TAG_SIZE_MASK    ((uint32_t)0x0000F000)
#define TXM_COMMON_TXM_MSDU_INFO_VLAN_TAG_SIZE_LSB    12
#define TXM_COMMON_TXM_MSDU_INFO_VLAN_TAG_SIZE_WIDTH    ((uint32_t)0x00000004)
#define TXM_COMMON_TXM_MSDU_INFO_LLC_SNAP_HEADER_SIZE_MASK    ((uint32_t)0x00000F00)
#define TXM_COMMON_TXM_MSDU_INFO_LLC_SNAP_HEADER_SIZE_LSB    8
#define TXM_COMMON_TXM_MSDU_INFO_LLC_SNAP_HEADER_SIZE_WIDTH    ((uint32_t)0x00000004)
#define TXM_COMMON_TXM_MSDU_INFO_SPARE_MASK    ((uint32_t)0x000000E0)
#define TXM_COMMON_TXM_MSDU_INFO_SPARE_LSB    5
#define TXM_COMMON_TXM_MSDU_INFO_SPARE_WIDTH    ((uint32_t)0x00000003)
#define TXM_COMMON_TXM_MSDU_INFO_ETH_HEADER_SIZE_MASK    ((uint32_t)0x0000001F)
#define TXM_COMMON_TXM_MSDU_INFO_ETH_HEADER_SIZE_LSB    0
#define TXM_COMMON_TXM_MSDU_INFO_ETH_HEADER_SIZE_WIDTH    ((uint32_t)0x00000005)

#define TXM_COMMON_TXM_MSDU_INFO_VLAN_TAG_SIZE_RST    0x4
#define TXM_COMMON_TXM_MSDU_INFO_LLC_SNAP_HEADER_SIZE_RST    0x6
#define TXM_COMMON_TXM_MSDU_INFO_SPARE_RST    0x0
#define TXM_COMMON_TXM_MSDU_INFO_ETH_HEADER_SIZE_RST    0xc

__INLINE void txm_common_txm_msdu_info_pack(uint8_t vlan_tag_size, uint8_t llc_snap_header_size, uint8_t spare, uint8_t eth_header_size)
{
	ASSERT_ERR((((uint32_t)vlan_tag_size << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)llc_snap_header_size << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)spare << 5) & ~((uint32_t)0x000000E0)) == 0);
	ASSERT_ERR((((uint32_t)eth_header_size << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_MSDU_INFO_ADDR,  ((uint32_t)vlan_tag_size << 12) |((uint32_t)llc_snap_header_size << 8) |((uint32_t)spare << 5) |((uint32_t)eth_header_size << 0));
}

__INLINE void txm_common_txm_msdu_info_unpack(uint8_t* vlan_tag_size, uint8_t* llc_snap_header_size, uint8_t* spare, uint8_t* eth_header_size)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_MSDU_INFO_ADDR);

	*vlan_tag_size = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*llc_snap_header_size = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*spare = (localVal & ((uint32_t)0x000000E0)) >>  5;
	*eth_header_size = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t txm_common_txm_msdu_info_vlan_tag_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_MSDU_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void txm_common_txm_msdu_info_vlan_tag_size_setf(uint8_t vlantagsize)
{
	ASSERT_ERR((((uint32_t)vlantagsize << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_MSDU_INFO_ADDR, (REG_PL_RD(TXM_COMMON_TXM_MSDU_INFO_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)vlantagsize <<12));
}
__INLINE uint8_t txm_common_txm_msdu_info_llc_snap_header_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_MSDU_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void txm_common_txm_msdu_info_llc_snap_header_size_setf(uint8_t llcsnapheadersize)
{
	ASSERT_ERR((((uint32_t)llcsnapheadersize << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_MSDU_INFO_ADDR, (REG_PL_RD(TXM_COMMON_TXM_MSDU_INFO_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)llcsnapheadersize <<8));
}
__INLINE uint8_t txm_common_txm_msdu_info_spare_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_MSDU_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000E0)) >> 5);
}
__INLINE void txm_common_txm_msdu_info_spare_setf(uint8_t spare)
{
	ASSERT_ERR((((uint32_t)spare << 5) & ~((uint32_t)0x000000E0)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_MSDU_INFO_ADDR, (REG_PL_RD(TXM_COMMON_TXM_MSDU_INFO_ADDR) & ~((uint32_t)0x000000E0)) | ((uint32_t)spare <<5));
}
__INLINE uint8_t txm_common_txm_msdu_info_eth_header_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_MSDU_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void txm_common_txm_msdu_info_eth_header_size_setf(uint8_t ethheadersize)
{
	ASSERT_ERR((((uint32_t)ethheadersize << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_MSDU_INFO_ADDR, (REG_PL_RD(TXM_COMMON_TXM_MSDU_INFO_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)ethheadersize <<0));
}

/**
 * @brief TXM_THD_INFO register definition
 *  THD done read wait states register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:08 THD_DONE_RETRY_CNT        0x14
 *    07:00 THD_DONE_WS_CNT           0x4
 * </pre>
 */
#define TXM_COMMON_TXM_THD_INFO_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x0000003C)
#define TXM_COMMON_TXM_THD_INFO_OFFSET      0x0000003C
#define TXM_COMMON_TXM_THD_INFO_INDEX       0x0000000F
#define TXM_COMMON_TXM_THD_INFO_RESET       0x00001404

__INLINE uint32_t  txm_common_txm_thd_info_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_THD_INFO_ADDR);
}

__INLINE void txm_common_txm_thd_info_set(uint32_t value)
{
	REG_PL_WR(TXM_COMMON_TXM_THD_INFO_ADDR, value);
}

// field definitions
#define TXM_COMMON_TXM_THD_INFO_THD_DONE_RETRY_CNT_MASK    ((uint32_t)0x0000FF00)
#define TXM_COMMON_TXM_THD_INFO_THD_DONE_RETRY_CNT_LSB    8
#define TXM_COMMON_TXM_THD_INFO_THD_DONE_RETRY_CNT_WIDTH    ((uint32_t)0x00000008)
#define TXM_COMMON_TXM_THD_INFO_THD_DONE_WS_CNT_MASK    ((uint32_t)0x000000FF)
#define TXM_COMMON_TXM_THD_INFO_THD_DONE_WS_CNT_LSB    0
#define TXM_COMMON_TXM_THD_INFO_THD_DONE_WS_CNT_WIDTH    ((uint32_t)0x00000008)

#define TXM_COMMON_TXM_THD_INFO_THD_DONE_RETRY_CNT_RST    0x14
#define TXM_COMMON_TXM_THD_INFO_THD_DONE_WS_CNT_RST    0x4

__INLINE void txm_common_txm_thd_info_pack(uint8_t thd_done_retry_cnt, uint8_t thd_done_ws_cnt)
{
	ASSERT_ERR((((uint32_t)thd_done_retry_cnt << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)thd_done_ws_cnt << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_THD_INFO_ADDR,  ((uint32_t)thd_done_retry_cnt << 8) |((uint32_t)thd_done_ws_cnt << 0));
}

__INLINE void txm_common_txm_thd_info_unpack(uint8_t* thd_done_retry_cnt, uint8_t* thd_done_ws_cnt)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_THD_INFO_ADDR);

	*thd_done_retry_cnt = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*thd_done_ws_cnt = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t txm_common_txm_thd_info_thd_done_retry_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_THD_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void txm_common_txm_thd_info_thd_done_retry_cnt_setf(uint8_t thddoneretrycnt)
{
	ASSERT_ERR((((uint32_t)thddoneretrycnt << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_THD_INFO_ADDR, (REG_PL_RD(TXM_COMMON_TXM_THD_INFO_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)thddoneretrycnt <<8));
}
__INLINE uint8_t txm_common_txm_thd_info_thd_done_ws_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_THD_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void txm_common_txm_thd_info_thd_done_ws_cnt_setf(uint8_t thddonewscnt)
{
	ASSERT_ERR((((uint32_t)thddonewscnt << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_THD_INFO_ADDR, (REG_PL_RD(TXM_COMMON_TXM_THD_INFO_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)thddonewscnt <<0));
}

/**
 * @brief TXM_MACHW_INT_CLR_ADDR register definition
 *  MACHW interrupt clear reg address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MACHW_INT_CLR_ADDR        0x0
 * </pre>
 */
#define TXM_COMMON_TXM_MACHW_INT_CLR_ADDR_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x00000040)
#define TXM_COMMON_TXM_MACHW_INT_CLR_ADDR_OFFSET      0x00000040
#define TXM_COMMON_TXM_MACHW_INT_CLR_ADDR_INDEX       0x00000010
#define TXM_COMMON_TXM_MACHW_INT_CLR_ADDR_RESET       0x00000000

__INLINE uint32_t  txm_common_txm_machw_int_clr_addr_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_MACHW_INT_CLR_ADDR_ADDR);
}

__INLINE void txm_common_txm_machw_int_clr_addr_set(uint32_t value)
{
	REG_PL_WR(TXM_COMMON_TXM_MACHW_INT_CLR_ADDR_ADDR, value);
}

// field definitions
#define TXM_COMMON_TXM_MACHW_INT_CLR_ADDR_MACHW_INT_CLR_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_COMMON_TXM_MACHW_INT_CLR_ADDR_MACHW_INT_CLR_ADDR_LSB    0
#define TXM_COMMON_TXM_MACHW_INT_CLR_ADDR_MACHW_INT_CLR_ADDR_WIDTH    ((uint32_t)0x00000020)

#define TXM_COMMON_TXM_MACHW_INT_CLR_ADDR_MACHW_INT_CLR_ADDR_RST    0x0

__INLINE uint32_t txm_common_txm_machw_int_clr_addr_machw_int_clr_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_MACHW_INT_CLR_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_common_txm_machw_int_clr_addr_machw_int_clr_addr_setf(uint32_t machwintclraddr)
{
	ASSERT_ERR((((uint32_t)machwintclraddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_MACHW_INT_CLR_ADDR_ADDR, (uint32_t)machwintclraddr << 0);
}

/**
 * @brief TXM_MACHW_USER_ADDR_SHIFT register definition
 *  MACHW interrupt clear reg offset register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04:00 MACHW_USER_ADDR_SHIFT     0x10
 * </pre>
 */
#define TXM_COMMON_TXM_MACHW_USER_ADDR_SHIFT_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x00000044)
#define TXM_COMMON_TXM_MACHW_USER_ADDR_SHIFT_OFFSET      0x00000044
#define TXM_COMMON_TXM_MACHW_USER_ADDR_SHIFT_INDEX       0x00000011
#define TXM_COMMON_TXM_MACHW_USER_ADDR_SHIFT_RESET       0x00000010

__INLINE uint32_t  txm_common_txm_machw_user_addr_shift_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_MACHW_USER_ADDR_SHIFT_ADDR);
}

__INLINE void txm_common_txm_machw_user_addr_shift_set(uint32_t value)
{
	REG_PL_WR(TXM_COMMON_TXM_MACHW_USER_ADDR_SHIFT_ADDR, value);
}

// field definitions
#define TXM_COMMON_TXM_MACHW_USER_ADDR_SHIFT_MACHW_USER_ADDR_SHIFT_MASK    ((uint32_t)0x0000001F)
#define TXM_COMMON_TXM_MACHW_USER_ADDR_SHIFT_MACHW_USER_ADDR_SHIFT_LSB    0
#define TXM_COMMON_TXM_MACHW_USER_ADDR_SHIFT_MACHW_USER_ADDR_SHIFT_WIDTH    ((uint32_t)0x00000005)

#define TXM_COMMON_TXM_MACHW_USER_ADDR_SHIFT_MACHW_USER_ADDR_SHIFT_RST    0x10

__INLINE uint8_t txm_common_txm_machw_user_addr_shift_machw_user_addr_shift_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_MACHW_USER_ADDR_SHIFT_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void txm_common_txm_machw_user_addr_shift_machw_user_addr_shift_setf(uint8_t machwuseraddrshift)
{
	ASSERT_ERR((((uint32_t)machwuseraddrshift << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_MACHW_USER_ADDR_SHIFT_ADDR, (uint32_t)machwuseraddrshift << 0);
}

/**
 * @brief TXM_MACHW_INT_CLR_BMAP register definition
 *  MACHW interrupt clear bit map register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MACHW_INT_CLR_BMAP        0x2000
 * </pre>
 */
#define TXM_COMMON_TXM_MACHW_INT_CLR_BMAP_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x00000048)
#define TXM_COMMON_TXM_MACHW_INT_CLR_BMAP_OFFSET      0x00000048
#define TXM_COMMON_TXM_MACHW_INT_CLR_BMAP_INDEX       0x00000012
#define TXM_COMMON_TXM_MACHW_INT_CLR_BMAP_RESET       0x00002000

__INLINE uint32_t  txm_common_txm_machw_int_clr_bmap_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_MACHW_INT_CLR_BMAP_ADDR);
}

__INLINE void txm_common_txm_machw_int_clr_bmap_set(uint32_t value)
{
	REG_PL_WR(TXM_COMMON_TXM_MACHW_INT_CLR_BMAP_ADDR, value);
}

// field definitions
#define TXM_COMMON_TXM_MACHW_INT_CLR_BMAP_MACHW_INT_CLR_BMAP_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_COMMON_TXM_MACHW_INT_CLR_BMAP_MACHW_INT_CLR_BMAP_LSB    0
#define TXM_COMMON_TXM_MACHW_INT_CLR_BMAP_MACHW_INT_CLR_BMAP_WIDTH    ((uint32_t)0x00000020)

#define TXM_COMMON_TXM_MACHW_INT_CLR_BMAP_MACHW_INT_CLR_BMAP_RST    0x2000

__INLINE uint32_t txm_common_txm_machw_int_clr_bmap_machw_int_clr_bmap_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_MACHW_INT_CLR_BMAP_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void txm_common_txm_machw_int_clr_bmap_machw_int_clr_bmap_setf(uint32_t machwintclrbmap)
{
	ASSERT_ERR((((uint32_t)machwintclrbmap << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_MACHW_INT_CLR_BMAP_ADDR, (uint32_t)machwintclrbmap << 0);
}

/**
 * @brief TXM_CHANNEL_CLEAR register definition
 *  channel is clear bitmap register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    10:00 CHANNEL_CLEAR_BMAP        0x0
 * </pre>
 */
#define TXM_COMMON_TXM_CHANNEL_CLEAR_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x0000004C)
#define TXM_COMMON_TXM_CHANNEL_CLEAR_OFFSET      0x0000004C
#define TXM_COMMON_TXM_CHANNEL_CLEAR_INDEX       0x00000013
#define TXM_COMMON_TXM_CHANNEL_CLEAR_RESET       0x00000000

__INLINE void txm_common_txm_channel_clear_set(uint32_t value)
{
	REG_PL_WR(TXM_COMMON_TXM_CHANNEL_CLEAR_ADDR, value);
}

// field definitions
#define TXM_COMMON_TXM_CHANNEL_CLEAR_CHANNEL_CLEAR_BMAP_MASK    ((uint32_t)0x000007FF)
#define TXM_COMMON_TXM_CHANNEL_CLEAR_CHANNEL_CLEAR_BMAP_LSB    0
#define TXM_COMMON_TXM_CHANNEL_CLEAR_CHANNEL_CLEAR_BMAP_WIDTH    ((uint32_t)0x0000000B)

#define TXM_COMMON_TXM_CHANNEL_CLEAR_CHANNEL_CLEAR_BMAP_RST    0x0

__INLINE void txm_common_txm_channel_clear_channel_clear_bmap_setf(uint16_t channelclearbmap)
{
	ASSERT_ERR((((uint32_t)channelclearbmap << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_CHANNEL_CLEAR_ADDR, (uint32_t)channelclearbmap << 0);
}

/**
 * @brief TXM_THD_OFFSET_MEM_RD register definition
 *  THD history memory read address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    10:08 STR_INDEX                 0x0
 *    06:00 THD_INDEX                 0x0
 * </pre>
 */
#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x00000050)
#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_OFFSET      0x00000050
#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_INDEX       0x00000014
#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_RESET       0x00000000

__INLINE uint32_t  txm_common_txm_thd_offset_mem_rd_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_THD_OFFSET_MEM_RD_ADDR);
}

__INLINE void txm_common_txm_thd_offset_mem_rd_set(uint32_t value)
{
	REG_PL_WR(TXM_COMMON_TXM_THD_OFFSET_MEM_RD_ADDR, value);
}

// field definitions
#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_STR_INDEX_MASK    ((uint32_t)0x00000700)
#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_STR_INDEX_LSB    8
#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_STR_INDEX_WIDTH    ((uint32_t)0x00000003)
#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_THD_INDEX_MASK    ((uint32_t)0x0000007F)
#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_THD_INDEX_LSB    0
#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_THD_INDEX_WIDTH    ((uint32_t)0x00000007)

#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_STR_INDEX_RST    0x0
#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_THD_INDEX_RST    0x0

__INLINE void txm_common_txm_thd_offset_mem_rd_pack(uint8_t str_index, uint8_t thd_index)
{
	ASSERT_ERR((((uint32_t)str_index << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)thd_index << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_THD_OFFSET_MEM_RD_ADDR,  ((uint32_t)str_index << 8) |((uint32_t)thd_index << 0));
}

__INLINE void txm_common_txm_thd_offset_mem_rd_unpack(uint8_t* str_index, uint8_t* thd_index)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_THD_OFFSET_MEM_RD_ADDR);

	*str_index = (localVal & ((uint32_t)0x00000700)) >>  8;
	*thd_index = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint8_t txm_common_txm_thd_offset_mem_rd_str_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_THD_OFFSET_MEM_RD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void txm_common_txm_thd_offset_mem_rd_str_index_setf(uint8_t strindex)
{
	ASSERT_ERR((((uint32_t)strindex << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_THD_OFFSET_MEM_RD_ADDR, (REG_PL_RD(TXM_COMMON_TXM_THD_OFFSET_MEM_RD_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)strindex <<8));
}
__INLINE uint8_t txm_common_txm_thd_offset_mem_rd_thd_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_THD_OFFSET_MEM_RD_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}
__INLINE void txm_common_txm_thd_offset_mem_rd_thd_index_setf(uint8_t thdindex)
{
	ASSERT_ERR((((uint32_t)thdindex << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_THD_OFFSET_MEM_RD_ADDR, (REG_PL_RD(TXM_COMMON_TXM_THD_OFFSET_MEM_RD_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)thdindex <<0));
}

/**
 * @brief TXM_THD_OFFSET_MEM_RD_INFO register definition
 *  THD history memory read data register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 THD_PTR                   0x0
 * </pre>
 */
#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_INFO_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x00000054)
#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_INFO_OFFSET      0x00000054
#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_INFO_INDEX       0x00000015
#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_INFO_RESET       0x00000000

__INLINE uint32_t  txm_common_txm_thd_offset_mem_rd_info_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_THD_OFFSET_MEM_RD_INFO_ADDR);
}

// field definitions
#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_INFO_THD_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_INFO_THD_PTR_LSB    0
#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_INFO_THD_PTR_WIDTH    ((uint32_t)0x00000020)

#define TXM_COMMON_TXM_THD_OFFSET_MEM_RD_INFO_THD_PTR_RST    0x0

__INLINE uint32_t txm_common_txm_thd_offset_mem_rd_info_thd_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_THD_OFFSET_MEM_RD_INFO_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief TXM_AXI_DBG register definition
 *  AXI rd and wr debug state machines register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:04 AXI_WR_SM                 0x0
 *    01:00 AXI_RD_SM                 0x0
 * </pre>
 */
#define TXM_COMMON_TXM_AXI_DBG_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x000000F0)
#define TXM_COMMON_TXM_AXI_DBG_OFFSET      0x000000F0
#define TXM_COMMON_TXM_AXI_DBG_INDEX       0x0000003C
#define TXM_COMMON_TXM_AXI_DBG_RESET       0x00000000

__INLINE uint32_t  txm_common_txm_axi_dbg_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_AXI_DBG_ADDR);
}

// field definitions
#define TXM_COMMON_TXM_AXI_DBG_AXI_WR_SM_MASK    ((uint32_t)0x000000F0)
#define TXM_COMMON_TXM_AXI_DBG_AXI_WR_SM_LSB    4
#define TXM_COMMON_TXM_AXI_DBG_AXI_WR_SM_WIDTH    ((uint32_t)0x00000004)
#define TXM_COMMON_TXM_AXI_DBG_AXI_RD_SM_MASK    ((uint32_t)0x00000003)
#define TXM_COMMON_TXM_AXI_DBG_AXI_RD_SM_LSB    0
#define TXM_COMMON_TXM_AXI_DBG_AXI_RD_SM_WIDTH    ((uint32_t)0x00000002)

#define TXM_COMMON_TXM_AXI_DBG_AXI_WR_SM_RST    0x0
#define TXM_COMMON_TXM_AXI_DBG_AXI_RD_SM_RST    0x0

__INLINE void txm_common_txm_axi_dbg_unpack(uint8_t* axi_wr_sm, uint8_t* axi_rd_sm)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_AXI_DBG_ADDR);

	*axi_wr_sm = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*axi_rd_sm = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t txm_common_txm_axi_dbg_axi_wr_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_AXI_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t txm_common_txm_axi_dbg_axi_rd_sm_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_AXI_DBG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief TXM_DBG_CONFIG register definition
 *  LCU debug port configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05    DBG_EN                    0              
 *    04:00 DBG_SEL                   0x0
 * </pre>
 */
#define TXM_COMMON_TXM_DBG_CONFIG_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x000000F8)
#define TXM_COMMON_TXM_DBG_CONFIG_OFFSET      0x000000F8
#define TXM_COMMON_TXM_DBG_CONFIG_INDEX       0x0000003E
#define TXM_COMMON_TXM_DBG_CONFIG_RESET       0x00000000

__INLINE uint32_t  txm_common_txm_dbg_config_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_DBG_CONFIG_ADDR);
}

__INLINE void txm_common_txm_dbg_config_set(uint32_t value)
{
	REG_PL_WR(TXM_COMMON_TXM_DBG_CONFIG_ADDR, value);
}

// field definitions
#define TXM_COMMON_TXM_DBG_CONFIG_DBG_EN_BIT    ((uint32_t)0x00000020)
#define TXM_COMMON_TXM_DBG_CONFIG_DBG_EN_POS    5
#define TXM_COMMON_TXM_DBG_CONFIG_DBG_SEL_MASK    ((uint32_t)0x0000001F)
#define TXM_COMMON_TXM_DBG_CONFIG_DBG_SEL_LSB    0
#define TXM_COMMON_TXM_DBG_CONFIG_DBG_SEL_WIDTH    ((uint32_t)0x00000005)

#define TXM_COMMON_TXM_DBG_CONFIG_DBG_EN_RST    0x0
#define TXM_COMMON_TXM_DBG_CONFIG_DBG_SEL_RST    0x0

__INLINE void txm_common_txm_dbg_config_pack(uint8_t dbg_en, uint8_t dbg_sel)
{
	ASSERT_ERR((((uint32_t)dbg_en << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)dbg_sel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_DBG_CONFIG_ADDR,  ((uint32_t)dbg_en << 5) |((uint32_t)dbg_sel << 0));
}

__INLINE void txm_common_txm_dbg_config_unpack(uint8_t* dbg_en, uint8_t* dbg_sel)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_DBG_CONFIG_ADDR);

	*dbg_en = (localVal & ((uint32_t)0x00000020)) >>  5;
	*dbg_sel = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t txm_common_txm_dbg_config_dbg_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_DBG_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void txm_common_txm_dbg_config_dbg_en_setf(uint8_t dbgen)
{
	ASSERT_ERR((((uint32_t)dbgen << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_DBG_CONFIG_ADDR, (REG_PL_RD(TXM_COMMON_TXM_DBG_CONFIG_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)dbgen <<5));
}
__INLINE uint8_t txm_common_txm_dbg_config_dbg_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_DBG_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void txm_common_txm_dbg_config_dbg_sel_setf(uint8_t dbgsel)
{
	ASSERT_ERR((((uint32_t)dbgsel << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(TXM_COMMON_TXM_DBG_CONFIG_ADDR, (REG_PL_RD(TXM_COMMON_TXM_DBG_CONFIG_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)dbgsel <<0));
}

/**
 * @brief TXM_DBG register definition
 *  DBG data towards LCU register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DBG_DATA                  0x0
 * </pre>
 */
#define TXM_COMMON_TXM_DBG_ADDR        (REG_TXM_COMMON_BASE_ADDR+0x000000FC)
#define TXM_COMMON_TXM_DBG_OFFSET      0x000000FC
#define TXM_COMMON_TXM_DBG_INDEX       0x0000003F
#define TXM_COMMON_TXM_DBG_RESET       0x00000000

__INLINE uint32_t  txm_common_txm_dbg_get(void)
{
	return REG_PL_RD(TXM_COMMON_TXM_DBG_ADDR);
}

// field definitions
#define TXM_COMMON_TXM_DBG_DBG_DATA_MASK    ((uint32_t)0xFFFFFFFF)
#define TXM_COMMON_TXM_DBG_DBG_DATA_LSB     0
#define TXM_COMMON_TXM_DBG_DBG_DATA_WIDTH    ((uint32_t)0x00000020)

#define TXM_COMMON_TXM_DBG_DBG_DATA_RST     0x0

__INLINE uint32_t txm_common_txm_dbg_dbg_data_getf(void)
{
	uint32_t localVal = REG_PL_RD(TXM_COMMON_TXM_DBG_ADDR);
	return (uint32_t)(localVal >> 0);
}


#undef DBG_FILEID
#endif //_REG_TXM_COMMON_H_
