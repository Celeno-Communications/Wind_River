#ifndef _REG_IPC_H_
#define _REG_IPC_H_

#include <stdint.h>
#include "_reg_ipc.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_IPC__H__FILEID__

#define REG_IPC_COUNT  70


/**
 * @brief XMAC_2_HOST_RAW_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 xmac2host_raw_status      0x0
 * </pre>
 */
#define IPC_XMAC_2_HOST_RAW_STATUS_ADDR        (REG_IPC_BASE_ADDR+0x00000004)
#define IPC_XMAC_2_HOST_RAW_STATUS_OFFSET      0x00000004
#define IPC_XMAC_2_HOST_RAW_STATUS_INDEX       0x00000001
#define IPC_XMAC_2_HOST_RAW_STATUS_RESET       0x00000000

__INLINE uint32_t  ipc_xmac_2_host_raw_status_get(void)
{
	return REG_PL_RD(IPC_XMAC_2_HOST_RAW_STATUS_ADDR);
}

// field definitions
#define IPC_XMAC_2_HOST_RAW_STATUS_XMAC_2_HOST_RAW_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_XMAC_2_HOST_RAW_STATUS_XMAC_2_HOST_RAW_STATUS_LSB    0
#define IPC_XMAC_2_HOST_RAW_STATUS_XMAC_2_HOST_RAW_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_XMAC_2_HOST_RAW_STATUS_XMAC_2_HOST_RAW_STATUS_RST    0x0

__INLINE uint32_t ipc_xmac_2_host_raw_status_xmac_2_host_raw_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_XMAC_2_HOST_RAW_STATUS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief XMAC_2_HOST_ACK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 xmac2host_trigger_clr     0x0
 * </pre>
 */
#define IPC_XMAC_2_HOST_ACK_ADDR        (REG_IPC_BASE_ADDR+0x00000008)
#define IPC_XMAC_2_HOST_ACK_OFFSET      0x00000008
#define IPC_XMAC_2_HOST_ACK_INDEX       0x00000002
#define IPC_XMAC_2_HOST_ACK_RESET       0x00000000

__INLINE void ipc_xmac_2_host_ack_set(uint32_t value)
{
	REG_PL_WR(IPC_XMAC_2_HOST_ACK_ADDR, value);
}

// field definitions
#define IPC_XMAC_2_HOST_ACK_XMAC_2_HOST_TRIGGER_CLR_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_XMAC_2_HOST_ACK_XMAC_2_HOST_TRIGGER_CLR_LSB    0
#define IPC_XMAC_2_HOST_ACK_XMAC_2_HOST_TRIGGER_CLR_WIDTH    ((uint32_t)0x00000020)

#define IPC_XMAC_2_HOST_ACK_XMAC_2_HOST_TRIGGER_CLR_RST    0x0

__INLINE void ipc_xmac_2_host_ack_xmac_2_host_trigger_clr_setf(uint32_t xmac2hosttriggerclr)
{
	ASSERT_ERR((((uint32_t)xmac2hosttriggerclr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_XMAC_2_HOST_ACK_ADDR, (uint32_t)xmac2hosttriggerclr << 0);
}

/**
 * @brief XMAC_2_HOST_ENABLE_SET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 xmac2host_enable_set      0x0
 * </pre>
 */
#define IPC_XMAC_2_HOST_ENABLE_SET_ADDR        (REG_IPC_BASE_ADDR+0x0000000C)
#define IPC_XMAC_2_HOST_ENABLE_SET_OFFSET      0x0000000C
#define IPC_XMAC_2_HOST_ENABLE_SET_INDEX       0x00000003
#define IPC_XMAC_2_HOST_ENABLE_SET_RESET       0x00000000

__INLINE void ipc_xmac_2_host_enable_set_set(uint32_t value)
{
	REG_PL_WR(IPC_XMAC_2_HOST_ENABLE_SET_ADDR, value);
}

// field definitions
#define IPC_XMAC_2_HOST_ENABLE_SET_XMAC_2_HOST_ENABLE_SET_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_XMAC_2_HOST_ENABLE_SET_XMAC_2_HOST_ENABLE_SET_LSB    0
#define IPC_XMAC_2_HOST_ENABLE_SET_XMAC_2_HOST_ENABLE_SET_WIDTH    ((uint32_t)0x00000020)

#define IPC_XMAC_2_HOST_ENABLE_SET_XMAC_2_HOST_ENABLE_SET_RST    0x0

__INLINE void ipc_xmac_2_host_enable_set_xmac_2_host_enable_set_setf(uint32_t xmac2hostenableset)
{
	ASSERT_ERR((((uint32_t)xmac2hostenableset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_XMAC_2_HOST_ENABLE_SET_ADDR, (uint32_t)xmac2hostenableset << 0);
}

/**
 * @brief XMAC_2_HOST_ENABLE_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 xmac2host_enable_clear    0x0
 * </pre>
 */
#define IPC_XMAC_2_HOST_ENABLE_CLEAR_ADDR        (REG_IPC_BASE_ADDR+0x00000010)
#define IPC_XMAC_2_HOST_ENABLE_CLEAR_OFFSET      0x00000010
#define IPC_XMAC_2_HOST_ENABLE_CLEAR_INDEX       0x00000004
#define IPC_XMAC_2_HOST_ENABLE_CLEAR_RESET       0x00000000

__INLINE void ipc_xmac_2_host_enable_clear_set(uint32_t value)
{
	REG_PL_WR(IPC_XMAC_2_HOST_ENABLE_CLEAR_ADDR, value);
}

// field definitions
#define IPC_XMAC_2_HOST_ENABLE_CLEAR_XMAC_2_HOST_ENABLE_CLEAR_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_XMAC_2_HOST_ENABLE_CLEAR_XMAC_2_HOST_ENABLE_CLEAR_LSB    0
#define IPC_XMAC_2_HOST_ENABLE_CLEAR_XMAC_2_HOST_ENABLE_CLEAR_WIDTH    ((uint32_t)0x00000020)

#define IPC_XMAC_2_HOST_ENABLE_CLEAR_XMAC_2_HOST_ENABLE_CLEAR_RST    0x0

__INLINE void ipc_xmac_2_host_enable_clear_xmac_2_host_enable_clear_setf(uint32_t xmac2hostenableclear)
{
	ASSERT_ERR((((uint32_t)xmac2hostenableclear << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_XMAC_2_HOST_ENABLE_CLEAR_ADDR, (uint32_t)xmac2hostenableclear << 0);
}

/**
 * @brief XMAC_2_HOST_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 xmac2host_status          0x0
 * </pre>
 */
#define IPC_XMAC_2_HOST_STATUS_ADDR        (REG_IPC_BASE_ADDR+0x00000014)
#define IPC_XMAC_2_HOST_STATUS_OFFSET      0x00000014
#define IPC_XMAC_2_HOST_STATUS_INDEX       0x00000005
#define IPC_XMAC_2_HOST_STATUS_RESET       0x00000000

__INLINE uint32_t  ipc_xmac_2_host_status_get(void)
{
	return REG_PL_RD(IPC_XMAC_2_HOST_STATUS_ADDR);
}

// field definitions
#define IPC_XMAC_2_HOST_STATUS_XMAC_2_HOST_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_XMAC_2_HOST_STATUS_XMAC_2_HOST_STATUS_LSB    0
#define IPC_XMAC_2_HOST_STATUS_XMAC_2_HOST_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_XMAC_2_HOST_STATUS_XMAC_2_HOST_STATUS_RST    0x0

__INLINE uint32_t ipc_xmac_2_host_status_xmac_2_host_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_XMAC_2_HOST_STATUS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief XMAC_2_HOST_STATUS_ACK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 xmac2host_status_clr      0x0
 * </pre>
 */
#define IPC_XMAC_2_HOST_STATUS_ACK_ADDR        (REG_IPC_BASE_ADDR+0x00000018)
#define IPC_XMAC_2_HOST_STATUS_ACK_OFFSET      0x00000018
#define IPC_XMAC_2_HOST_STATUS_ACK_INDEX       0x00000006
#define IPC_XMAC_2_HOST_STATUS_ACK_RESET       0x00000000

__INLINE uint32_t  ipc_xmac_2_host_status_ack_get(void)
{
	return REG_PL_RD(IPC_XMAC_2_HOST_STATUS_ACK_ADDR);
}

// field definitions
#define IPC_XMAC_2_HOST_STATUS_ACK_XMAC_2_HOST_STATUS_CLR_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_XMAC_2_HOST_STATUS_ACK_XMAC_2_HOST_STATUS_CLR_LSB    0
#define IPC_XMAC_2_HOST_STATUS_ACK_XMAC_2_HOST_STATUS_CLR_WIDTH    ((uint32_t)0x00000020)

#define IPC_XMAC_2_HOST_STATUS_ACK_XMAC_2_HOST_STATUS_CLR_RST    0x0

__INLINE uint32_t ipc_xmac_2_host_status_ack_xmac_2_host_status_clr_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_XMAC_2_HOST_STATUS_ACK_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief HOST_GLOBAL_INT_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    master_int_enable         0              
 * </pre>
 */
#define IPC_HOST_GLOBAL_INT_EN_ADDR        (REG_IPC_BASE_ADDR+0x00000030)
#define IPC_HOST_GLOBAL_INT_EN_OFFSET      0x00000030
#define IPC_HOST_GLOBAL_INT_EN_INDEX       0x0000000C
#define IPC_HOST_GLOBAL_INT_EN_RESET       0x00000000

__INLINE uint32_t  ipc_host_global_int_en_get(void)
{
	return REG_PL_RD(IPC_HOST_GLOBAL_INT_EN_ADDR);
}

__INLINE void ipc_host_global_int_en_set(uint32_t value)
{
	REG_PL_WR(IPC_HOST_GLOBAL_INT_EN_ADDR, value);
}

// field definitions
#define IPC_HOST_GLOBAL_INT_EN_MASTER_INT_ENABLE_BIT    ((uint32_t)0x00000001)
#define IPC_HOST_GLOBAL_INT_EN_MASTER_INT_ENABLE_POS    0

#define IPC_HOST_GLOBAL_INT_EN_MASTER_INT_ENABLE_RST    0x0

__INLINE uint8_t ipc_host_global_int_en_master_int_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_HOST_GLOBAL_INT_EN_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void ipc_host_global_int_en_master_int_enable_setf(uint8_t masterintenable)
{
	ASSERT_ERR((((uint32_t)masterintenable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(IPC_HOST_GLOBAL_INT_EN_ADDR, (uint32_t)masterintenable << 0);
}

/**
 * @brief LLI_UPSTRM_2_HOST_RAW_STAT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 lli_upstream2host_raw_status 0x0
 * </pre>
 */
#define IPC_LLI_UPSTRM_2_HOST_RAW_STAT_ADDR        (REG_IPC_BASE_ADDR+0x00000034)
#define IPC_LLI_UPSTRM_2_HOST_RAW_STAT_OFFSET      0x00000034
#define IPC_LLI_UPSTRM_2_HOST_RAW_STAT_INDEX       0x0000000D
#define IPC_LLI_UPSTRM_2_HOST_RAW_STAT_RESET       0x00000000

__INLINE uint32_t  ipc_lli_upstrm_2_host_raw_stat_get(void)
{
	return REG_PL_RD(IPC_LLI_UPSTRM_2_HOST_RAW_STAT_ADDR);
}

// field definitions
#define IPC_LLI_UPSTRM_2_HOST_RAW_STAT_LLI_UPSTREAM_2_HOST_RAW_STATUS_MASK    ((uint32_t)0x0000FFFF)
#define IPC_LLI_UPSTRM_2_HOST_RAW_STAT_LLI_UPSTREAM_2_HOST_RAW_STATUS_LSB    0
#define IPC_LLI_UPSTRM_2_HOST_RAW_STAT_LLI_UPSTREAM_2_HOST_RAW_STATUS_WIDTH    ((uint32_t)0x00000010)

#define IPC_LLI_UPSTRM_2_HOST_RAW_STAT_LLI_UPSTREAM_2_HOST_RAW_STATUS_RST    0x0

__INLINE uint16_t ipc_lli_upstrm_2_host_raw_stat_lli_upstream_2_host_raw_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_LLI_UPSTRM_2_HOST_RAW_STAT_ADDR);
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief LLI_UPSTRM_2_HOST_ACK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 lli_upstream2host_trigger_clr 0x0
 * </pre>
 */
#define IPC_LLI_UPSTRM_2_HOST_ACK_ADDR        (REG_IPC_BASE_ADDR+0x00000038)
#define IPC_LLI_UPSTRM_2_HOST_ACK_OFFSET      0x00000038
#define IPC_LLI_UPSTRM_2_HOST_ACK_INDEX       0x0000000E
#define IPC_LLI_UPSTRM_2_HOST_ACK_RESET       0x00000000

__INLINE void ipc_lli_upstrm_2_host_ack_set(uint32_t value)
{
	REG_PL_WR(IPC_LLI_UPSTRM_2_HOST_ACK_ADDR, value);
}

// field definitions
#define IPC_LLI_UPSTRM_2_HOST_ACK_LLI_UPSTREAM_2_HOST_TRIGGER_CLR_MASK    ((uint32_t)0x0000FFFF)
#define IPC_LLI_UPSTRM_2_HOST_ACK_LLI_UPSTREAM_2_HOST_TRIGGER_CLR_LSB    0
#define IPC_LLI_UPSTRM_2_HOST_ACK_LLI_UPSTREAM_2_HOST_TRIGGER_CLR_WIDTH    ((uint32_t)0x00000010)

#define IPC_LLI_UPSTRM_2_HOST_ACK_LLI_UPSTREAM_2_HOST_TRIGGER_CLR_RST    0x0

__INLINE void ipc_lli_upstrm_2_host_ack_lli_upstream_2_host_trigger_clr_setf(uint16_t lliupstream2hosttriggerclr)
{
	ASSERT_ERR((((uint32_t)lliupstream2hosttriggerclr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(IPC_LLI_UPSTRM_2_HOST_ACK_ADDR, (uint32_t)lliupstream2hosttriggerclr << 0);
}

/**
 * @brief LLI_UPSTRM_2_HOST_EN_SET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 lli_upstream2host_enable_set 0x0
 * </pre>
 */
#define IPC_LLI_UPSTRM_2_HOST_EN_SET_ADDR        (REG_IPC_BASE_ADDR+0x0000003C)
#define IPC_LLI_UPSTRM_2_HOST_EN_SET_OFFSET      0x0000003C
#define IPC_LLI_UPSTRM_2_HOST_EN_SET_INDEX       0x0000000F
#define IPC_LLI_UPSTRM_2_HOST_EN_SET_RESET       0x00000000

__INLINE void ipc_lli_upstrm_2_host_en_set_set(uint32_t value)
{
	REG_PL_WR(IPC_LLI_UPSTRM_2_HOST_EN_SET_ADDR, value);
}

// field definitions
#define IPC_LLI_UPSTRM_2_HOST_EN_SET_LLI_UPSTREAM_2_HOST_ENABLE_SET_MASK    ((uint32_t)0x0000FFFF)
#define IPC_LLI_UPSTRM_2_HOST_EN_SET_LLI_UPSTREAM_2_HOST_ENABLE_SET_LSB    0
#define IPC_LLI_UPSTRM_2_HOST_EN_SET_LLI_UPSTREAM_2_HOST_ENABLE_SET_WIDTH    ((uint32_t)0x00000010)

#define IPC_LLI_UPSTRM_2_HOST_EN_SET_LLI_UPSTREAM_2_HOST_ENABLE_SET_RST    0x0

__INLINE void ipc_lli_upstrm_2_host_en_set_lli_upstream_2_host_enable_set_setf(uint16_t lliupstream2hostenableset)
{
	ASSERT_ERR((((uint32_t)lliupstream2hostenableset << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(IPC_LLI_UPSTRM_2_HOST_EN_SET_ADDR, (uint32_t)lliupstream2hostenableset << 0);
}

/**
 * @brief LLI_UPSTRM_2_HOST_EN_CLR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 lli_upstream2host_enable_clear 0x0
 * </pre>
 */
#define IPC_LLI_UPSTRM_2_HOST_EN_CLR_ADDR        (REG_IPC_BASE_ADDR+0x00000040)
#define IPC_LLI_UPSTRM_2_HOST_EN_CLR_OFFSET      0x00000040
#define IPC_LLI_UPSTRM_2_HOST_EN_CLR_INDEX       0x00000010
#define IPC_LLI_UPSTRM_2_HOST_EN_CLR_RESET       0x00000000

__INLINE void ipc_lli_upstrm_2_host_en_clr_set(uint32_t value)
{
	REG_PL_WR(IPC_LLI_UPSTRM_2_HOST_EN_CLR_ADDR, value);
}

// field definitions
#define IPC_LLI_UPSTRM_2_HOST_EN_CLR_LLI_UPSTREAM_2_HOST_ENABLE_CLEAR_MASK    ((uint32_t)0x0000FFFF)
#define IPC_LLI_UPSTRM_2_HOST_EN_CLR_LLI_UPSTREAM_2_HOST_ENABLE_CLEAR_LSB    0
#define IPC_LLI_UPSTRM_2_HOST_EN_CLR_LLI_UPSTREAM_2_HOST_ENABLE_CLEAR_WIDTH    ((uint32_t)0x00000010)

#define IPC_LLI_UPSTRM_2_HOST_EN_CLR_LLI_UPSTREAM_2_HOST_ENABLE_CLEAR_RST    0x0

__INLINE void ipc_lli_upstrm_2_host_en_clr_lli_upstream_2_host_enable_clear_setf(uint16_t lliupstream2hostenableclear)
{
	ASSERT_ERR((((uint32_t)lliupstream2hostenableclear << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(IPC_LLI_UPSTRM_2_HOST_EN_CLR_ADDR, (uint32_t)lliupstream2hostenableclear << 0);
}

/**
 * @brief LLI_UPSTRM_2_HOST_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 lli_upstream2host_status  0x0
 * </pre>
 */
#define IPC_LLI_UPSTRM_2_HOST_STATUS_ADDR        (REG_IPC_BASE_ADDR+0x00000044)
#define IPC_LLI_UPSTRM_2_HOST_STATUS_OFFSET      0x00000044
#define IPC_LLI_UPSTRM_2_HOST_STATUS_INDEX       0x00000011
#define IPC_LLI_UPSTRM_2_HOST_STATUS_RESET       0x00000000

__INLINE uint32_t  ipc_lli_upstrm_2_host_status_get(void)
{
	return REG_PL_RD(IPC_LLI_UPSTRM_2_HOST_STATUS_ADDR);
}

// field definitions
#define IPC_LLI_UPSTRM_2_HOST_STATUS_LLI_UPSTREAM_2_HOST_STATUS_MASK    ((uint32_t)0x0000FFFF)
#define IPC_LLI_UPSTRM_2_HOST_STATUS_LLI_UPSTREAM_2_HOST_STATUS_LSB    0
#define IPC_LLI_UPSTRM_2_HOST_STATUS_LLI_UPSTREAM_2_HOST_STATUS_WIDTH    ((uint32_t)0x00000010)

#define IPC_LLI_UPSTRM_2_HOST_STATUS_LLI_UPSTREAM_2_HOST_STATUS_RST    0x0

__INLINE uint16_t ipc_lli_upstrm_2_host_status_lli_upstream_2_host_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_LLI_UPSTRM_2_HOST_STATUS_ADDR);
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief LLI_UPSTRM_2_HOST_STAT_ACK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 lli_upstream2host_status_clr 0x0
 * </pre>
 */
#define IPC_LLI_UPSTRM_2_HOST_STAT_ACK_ADDR        (REG_IPC_BASE_ADDR+0x00000048)
#define IPC_LLI_UPSTRM_2_HOST_STAT_ACK_OFFSET      0x00000048
#define IPC_LLI_UPSTRM_2_HOST_STAT_ACK_INDEX       0x00000012
#define IPC_LLI_UPSTRM_2_HOST_STAT_ACK_RESET       0x00000000

__INLINE uint32_t  ipc_lli_upstrm_2_host_stat_ack_get(void)
{
	return REG_PL_RD(IPC_LLI_UPSTRM_2_HOST_STAT_ACK_ADDR);
}

// field definitions
#define IPC_LLI_UPSTRM_2_HOST_STAT_ACK_LLI_UPSTREAM_2_HOST_STATUS_CLR_MASK    ((uint32_t)0x0000FFFF)
#define IPC_LLI_UPSTRM_2_HOST_STAT_ACK_LLI_UPSTREAM_2_HOST_STATUS_CLR_LSB    0
#define IPC_LLI_UPSTRM_2_HOST_STAT_ACK_LLI_UPSTREAM_2_HOST_STATUS_CLR_WIDTH    ((uint32_t)0x00000010)

#define IPC_LLI_UPSTRM_2_HOST_STAT_ACK_LLI_UPSTREAM_2_HOST_STATUS_CLR_RST    0x0

__INLINE uint16_t ipc_lli_upstrm_2_host_stat_ack_lli_upstream_2_host_status_clr_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_LLI_UPSTRM_2_HOST_STAT_ACK_ADDR);
	return (uint16_t)(localVal >> 0);
}

/**
 * @brief HOST_2_LMAC_TRIGGER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 host2lmac_trigger         0x0
 * </pre>
 */
#define IPC_HOST_2_LMAC_TRIGGER_ADDR        (REG_IPC_BASE_ADDR+0x00000080)
#define IPC_HOST_2_LMAC_TRIGGER_OFFSET      0x00000080
#define IPC_HOST_2_LMAC_TRIGGER_INDEX       0x00000020
#define IPC_HOST_2_LMAC_TRIGGER_RESET       0x00000000

__INLINE void ipc_host_2_lmac_trigger_set(uint32_t value)
{
	REG_PL_WR(IPC_HOST_2_LMAC_TRIGGER_ADDR, value);
}

// field definitions
#define IPC_HOST_2_LMAC_TRIGGER_HOST_2_LMAC_TRIGGER_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_HOST_2_LMAC_TRIGGER_HOST_2_LMAC_TRIGGER_LSB    0
#define IPC_HOST_2_LMAC_TRIGGER_HOST_2_LMAC_TRIGGER_WIDTH    ((uint32_t)0x00000020)

#define IPC_HOST_2_LMAC_TRIGGER_HOST_2_LMAC_TRIGGER_RST    0x0

__INLINE void ipc_host_2_lmac_trigger_host_2_lmac_trigger_setf(uint32_t host2lmactrigger)
{
	ASSERT_ERR((((uint32_t)host2lmactrigger << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_HOST_2_LMAC_TRIGGER_ADDR, (uint32_t)host2lmactrigger << 0);
}

/**
 * @brief HOST_2_UMAC_TRIGGER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 host2umac_trigger         0x0
 * </pre>
 */
#define IPC_HOST_2_UMAC_TRIGGER_ADDR        (REG_IPC_BASE_ADDR+0x00000084)
#define IPC_HOST_2_UMAC_TRIGGER_OFFSET      0x00000084
#define IPC_HOST_2_UMAC_TRIGGER_INDEX       0x00000021
#define IPC_HOST_2_UMAC_TRIGGER_RESET       0x00000000

__INLINE void ipc_host_2_umac_trigger_set(uint32_t value)
{
	REG_PL_WR(IPC_HOST_2_UMAC_TRIGGER_ADDR, value);
}

// field definitions
#define IPC_HOST_2_UMAC_TRIGGER_HOST_2_UMAC_TRIGGER_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_HOST_2_UMAC_TRIGGER_HOST_2_UMAC_TRIGGER_LSB    0
#define IPC_HOST_2_UMAC_TRIGGER_HOST_2_UMAC_TRIGGER_WIDTH    ((uint32_t)0x00000020)

#define IPC_HOST_2_UMAC_TRIGGER_HOST_2_UMAC_TRIGGER_RST    0x0

__INLINE void ipc_host_2_umac_trigger_host_2_umac_trigger_setf(uint32_t host2umactrigger)
{
	ASSERT_ERR((((uint32_t)host2umactrigger << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_HOST_2_UMAC_TRIGGER_ADDR, (uint32_t)host2umactrigger << 0);
}

/**
 * @brief HOST_2_SMAC_TRIGGER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 host2smac_trigger         0x0
 * </pre>
 */
#define IPC_HOST_2_SMAC_TRIGGER_ADDR        (REG_IPC_BASE_ADDR+0x00000088)
#define IPC_HOST_2_SMAC_TRIGGER_OFFSET      0x00000088
#define IPC_HOST_2_SMAC_TRIGGER_INDEX       0x00000022
#define IPC_HOST_2_SMAC_TRIGGER_RESET       0x00000000

__INLINE void ipc_host_2_smac_trigger_set(uint32_t value)
{
	REG_PL_WR(IPC_HOST_2_SMAC_TRIGGER_ADDR, value);
}

// field definitions
#define IPC_HOST_2_SMAC_TRIGGER_HOST_2_SMAC_TRIGGER_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_HOST_2_SMAC_TRIGGER_HOST_2_SMAC_TRIGGER_LSB    0
#define IPC_HOST_2_SMAC_TRIGGER_HOST_2_SMAC_TRIGGER_WIDTH    ((uint32_t)0x00000020)

#define IPC_HOST_2_SMAC_TRIGGER_HOST_2_SMAC_TRIGGER_RST    0x0

__INLINE void ipc_host_2_smac_trigger_host_2_smac_trigger_setf(uint32_t host2smactrigger)
{
	ASSERT_ERR((((uint32_t)host2smactrigger << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_HOST_2_SMAC_TRIGGER_ADDR, (uint32_t)host2smactrigger << 0);
}

/**
 * @brief XMAC_2_HOST_TRIGGER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Xmac2host_trigger         0x0
 * </pre>
 */
#define IPC_XMAC_2_HOST_TRIGGER_ADDR        (REG_IPC_BASE_ADDR+0x00000180)
#define IPC_XMAC_2_HOST_TRIGGER_OFFSET      0x00000180
#define IPC_XMAC_2_HOST_TRIGGER_INDEX       0x00000060
#define IPC_XMAC_2_HOST_TRIGGER_RESET       0x00000000

__INLINE void ipc_xmac_2_host_trigger_set(uint32_t value)
{
	REG_PL_WR(IPC_XMAC_2_HOST_TRIGGER_ADDR, value);
}

// field definitions
#define IPC_XMAC_2_HOST_TRIGGER_XMAC_2_HOST_TRIGGER_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_XMAC_2_HOST_TRIGGER_XMAC_2_HOST_TRIGGER_LSB    0
#define IPC_XMAC_2_HOST_TRIGGER_XMAC_2_HOST_TRIGGER_WIDTH    ((uint32_t)0x00000020)

#define IPC_XMAC_2_HOST_TRIGGER_XMAC_2_HOST_TRIGGER_RST    0x0

__INLINE void ipc_xmac_2_host_trigger_xmac_2_host_trigger_setf(uint32_t xmac2hosttrigger)
{
	ASSERT_ERR((((uint32_t)xmac2hosttrigger << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_XMAC_2_HOST_TRIGGER_ADDR, (uint32_t)xmac2hosttrigger << 0);
}

/**
 * @brief MSI_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    08:04 ven_msi_vector            0x0
 *    02:00 ven_msi_tc                0x0
 * </pre>
 */
#define IPC_MSI_CONFIG_ADDR        (REG_IPC_BASE_ADDR+0x000001C0)
#define IPC_MSI_CONFIG_OFFSET      0x000001C0
#define IPC_MSI_CONFIG_INDEX       0x00000070
#define IPC_MSI_CONFIG_RESET       0x00000000

__INLINE uint32_t  ipc_msi_config_get(void)
{
	return REG_PL_RD(IPC_MSI_CONFIG_ADDR);
}

__INLINE void ipc_msi_config_set(uint32_t value)
{
	REG_PL_WR(IPC_MSI_CONFIG_ADDR, value);
}

// field definitions
#define IPC_MSI_CONFIG_VEN_MSI_VECTOR_MASK    ((uint32_t)0x000001F0)
#define IPC_MSI_CONFIG_VEN_MSI_VECTOR_LSB    4
#define IPC_MSI_CONFIG_VEN_MSI_VECTOR_WIDTH    ((uint32_t)0x00000005)
#define IPC_MSI_CONFIG_VEN_MSI_TC_MASK      ((uint32_t)0x00000007)
#define IPC_MSI_CONFIG_VEN_MSI_TC_LSB       0
#define IPC_MSI_CONFIG_VEN_MSI_TC_WIDTH     ((uint32_t)0x00000003)

#define IPC_MSI_CONFIG_VEN_MSI_VECTOR_RST    0x0
#define IPC_MSI_CONFIG_VEN_MSI_TC_RST       0x0

__INLINE void ipc_msi_config_pack(uint8_t ven_msi_vector, uint8_t ven_msi_tc)
{
	ASSERT_ERR((((uint32_t)ven_msi_vector << 4) & ~((uint32_t)0x000001F0)) == 0);
	ASSERT_ERR((((uint32_t)ven_msi_tc << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IPC_MSI_CONFIG_ADDR,  ((uint32_t)ven_msi_vector << 4) |((uint32_t)ven_msi_tc << 0));
}

__INLINE void ipc_msi_config_unpack(uint8_t* ven_msi_vector, uint8_t* ven_msi_tc)
{
	uint32_t localVal = REG_PL_RD(IPC_MSI_CONFIG_ADDR);

	*ven_msi_vector = (localVal & ((uint32_t)0x000001F0)) >>  4;
	*ven_msi_tc = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t ipc_msi_config_ven_msi_vector_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_MSI_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000001F0)) >> 4);
}
__INLINE void ipc_msi_config_ven_msi_vector_setf(uint8_t venmsivector)
{
	ASSERT_ERR((((uint32_t)venmsivector << 4) & ~((uint32_t)0x000001F0)) == 0);
	REG_PL_WR(IPC_MSI_CONFIG_ADDR, (REG_PL_RD(IPC_MSI_CONFIG_ADDR) & ~((uint32_t)0x000001F0)) | ((uint32_t)venmsivector <<4));
}
__INLINE uint8_t ipc_msi_config_ven_msi_tc_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_MSI_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void ipc_msi_config_ven_msi_tc_setf(uint8_t venmsitc)
{
	ASSERT_ERR((((uint32_t)venmsitc << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(IPC_MSI_CONFIG_ADDR, (REG_PL_RD(IPC_MSI_CONFIG_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)venmsitc <<0));
}

/**
 * @brief HOST_INT_CNT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:00 int_counter               0x0
 * </pre>
 */
#define IPC_HOST_INT_CNT_ADDR        (REG_IPC_BASE_ADDR+0x000001C4)
#define IPC_HOST_INT_CNT_OFFSET      0x000001C4
#define IPC_HOST_INT_CNT_INDEX       0x00000071
#define IPC_HOST_INT_CNT_RESET       0x00000000

__INLINE uint32_t  ipc_host_int_cnt_get(void)
{
	return REG_PL_RD(IPC_HOST_INT_CNT_ADDR);
}

__INLINE void ipc_host_int_cnt_set(uint32_t value)
{
	REG_PL_WR(IPC_HOST_INT_CNT_ADDR, value);
}

// field definitions
#define IPC_HOST_INT_CNT_INT_COUNTER_MASK    ((uint32_t)0x00FFFFFF)
#define IPC_HOST_INT_CNT_INT_COUNTER_LSB    0
#define IPC_HOST_INT_CNT_INT_COUNTER_WIDTH    ((uint32_t)0x00000018)

#define IPC_HOST_INT_CNT_INT_COUNTER_RST    0x0

__INLINE uint32_t ipc_host_int_cnt_int_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_HOST_INT_CNT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void ipc_host_int_cnt_int_counter_setf(uint32_t intcounter)
{
	ASSERT_ERR((((uint32_t)intcounter << 0) & ~((uint32_t)0x00FFFFFF)) == 0);
	REG_PL_WR(IPC_HOST_INT_CNT_ADDR, (uint32_t)intcounter << 0);
}

/**
 * @brief LMAC_2_UMAC_RAW_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 lmac2umac_raw_status      0x0
 * </pre>
 */
#define IPC_LMAC_2_UMAC_RAW_STATUS_ADDR        (REG_IPC_BASE_ADDR+0x00000200)
#define IPC_LMAC_2_UMAC_RAW_STATUS_OFFSET      0x00000200
#define IPC_LMAC_2_UMAC_RAW_STATUS_INDEX       0x00000080
#define IPC_LMAC_2_UMAC_RAW_STATUS_RESET       0x00000000

__INLINE uint32_t  ipc_lmac_2_umac_raw_status_get(void)
{
	return REG_PL_RD(IPC_LMAC_2_UMAC_RAW_STATUS_ADDR);
}

// field definitions
#define IPC_LMAC_2_UMAC_RAW_STATUS_LMAC_2_UMAC_RAW_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_LMAC_2_UMAC_RAW_STATUS_LMAC_2_UMAC_RAW_STATUS_LSB    0
#define IPC_LMAC_2_UMAC_RAW_STATUS_LMAC_2_UMAC_RAW_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_LMAC_2_UMAC_RAW_STATUS_LMAC_2_UMAC_RAW_STATUS_RST    0x0

__INLINE uint32_t ipc_lmac_2_umac_raw_status_lmac_2_umac_raw_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_LMAC_2_UMAC_RAW_STATUS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief LMAC_2_UMAC_ACK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 lmac2umac_ack             0x0
 * </pre>
 */
#define IPC_LMAC_2_UMAC_ACK_ADDR        (REG_IPC_BASE_ADDR+0x00000204)
#define IPC_LMAC_2_UMAC_ACK_OFFSET      0x00000204
#define IPC_LMAC_2_UMAC_ACK_INDEX       0x00000081
#define IPC_LMAC_2_UMAC_ACK_RESET       0x00000000

__INLINE void ipc_lmac_2_umac_ack_set(uint32_t value)
{
	REG_PL_WR(IPC_LMAC_2_UMAC_ACK_ADDR, value);
}

// field definitions
#define IPC_LMAC_2_UMAC_ACK_LMAC_2_UMAC_ACK_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_LMAC_2_UMAC_ACK_LMAC_2_UMAC_ACK_LSB    0
#define IPC_LMAC_2_UMAC_ACK_LMAC_2_UMAC_ACK_WIDTH    ((uint32_t)0x00000020)

#define IPC_LMAC_2_UMAC_ACK_LMAC_2_UMAC_ACK_RST    0x0

__INLINE void ipc_lmac_2_umac_ack_lmac_2_umac_ack_setf(uint32_t lmac2umacack)
{
	ASSERT_ERR((((uint32_t)lmac2umacack << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_LMAC_2_UMAC_ACK_ADDR, (uint32_t)lmac2umacack << 0);
}

/**
 * @brief LMAC_2_UMAC_ENABLE_SET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 lmac2umac_enable_set      0x0
 * </pre>
 */
#define IPC_LMAC_2_UMAC_ENABLE_SET_ADDR        (REG_IPC_BASE_ADDR+0x00000208)
#define IPC_LMAC_2_UMAC_ENABLE_SET_OFFSET      0x00000208
#define IPC_LMAC_2_UMAC_ENABLE_SET_INDEX       0x00000082
#define IPC_LMAC_2_UMAC_ENABLE_SET_RESET       0x00000000

__INLINE void ipc_lmac_2_umac_enable_set_set(uint32_t value)
{
	REG_PL_WR(IPC_LMAC_2_UMAC_ENABLE_SET_ADDR, value);
}

// field definitions
#define IPC_LMAC_2_UMAC_ENABLE_SET_LMAC_2_UMAC_ENABLE_SET_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_LMAC_2_UMAC_ENABLE_SET_LMAC_2_UMAC_ENABLE_SET_LSB    0
#define IPC_LMAC_2_UMAC_ENABLE_SET_LMAC_2_UMAC_ENABLE_SET_WIDTH    ((uint32_t)0x00000020)

#define IPC_LMAC_2_UMAC_ENABLE_SET_LMAC_2_UMAC_ENABLE_SET_RST    0x0

__INLINE void ipc_lmac_2_umac_enable_set_lmac_2_umac_enable_set_setf(uint32_t lmac2umacenableset)
{
	ASSERT_ERR((((uint32_t)lmac2umacenableset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_LMAC_2_UMAC_ENABLE_SET_ADDR, (uint32_t)lmac2umacenableset << 0);
}

/**
 * @brief LMAC_2_UMAC_ENABLE_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 lmac2umac_enable_clear    0x0
 * </pre>
 */
#define IPC_LMAC_2_UMAC_ENABLE_CLEAR_ADDR        (REG_IPC_BASE_ADDR+0x0000020C)
#define IPC_LMAC_2_UMAC_ENABLE_CLEAR_OFFSET      0x0000020C
#define IPC_LMAC_2_UMAC_ENABLE_CLEAR_INDEX       0x00000083
#define IPC_LMAC_2_UMAC_ENABLE_CLEAR_RESET       0x00000000

__INLINE void ipc_lmac_2_umac_enable_clear_set(uint32_t value)
{
	REG_PL_WR(IPC_LMAC_2_UMAC_ENABLE_CLEAR_ADDR, value);
}

// field definitions
#define IPC_LMAC_2_UMAC_ENABLE_CLEAR_LMAC_2_UMAC_ENABLE_CLEAR_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_LMAC_2_UMAC_ENABLE_CLEAR_LMAC_2_UMAC_ENABLE_CLEAR_LSB    0
#define IPC_LMAC_2_UMAC_ENABLE_CLEAR_LMAC_2_UMAC_ENABLE_CLEAR_WIDTH    ((uint32_t)0x00000020)

#define IPC_LMAC_2_UMAC_ENABLE_CLEAR_LMAC_2_UMAC_ENABLE_CLEAR_RST    0x0

__INLINE void ipc_lmac_2_umac_enable_clear_lmac_2_umac_enable_clear_setf(uint32_t lmac2umacenableclear)
{
	ASSERT_ERR((((uint32_t)lmac2umacenableclear << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_LMAC_2_UMAC_ENABLE_CLEAR_ADDR, (uint32_t)lmac2umacenableclear << 0);
}

/**
 * @brief LMAC_2_UMAC_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 lmac2umac_status          0x0
 * </pre>
 */
#define IPC_LMAC_2_UMAC_STATUS_ADDR        (REG_IPC_BASE_ADDR+0x00000210)
#define IPC_LMAC_2_UMAC_STATUS_OFFSET      0x00000210
#define IPC_LMAC_2_UMAC_STATUS_INDEX       0x00000084
#define IPC_LMAC_2_UMAC_STATUS_RESET       0x00000000

__INLINE uint32_t  ipc_lmac_2_umac_status_get(void)
{
	return REG_PL_RD(IPC_LMAC_2_UMAC_STATUS_ADDR);
}

// field definitions
#define IPC_LMAC_2_UMAC_STATUS_LMAC_2_UMAC_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_LMAC_2_UMAC_STATUS_LMAC_2_UMAC_STATUS_LSB    0
#define IPC_LMAC_2_UMAC_STATUS_LMAC_2_UMAC_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_LMAC_2_UMAC_STATUS_LMAC_2_UMAC_STATUS_RST    0x0

__INLINE uint32_t ipc_lmac_2_umac_status_lmac_2_umac_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_LMAC_2_UMAC_STATUS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief LMAC_2_UMAC_TRIGGER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 lmac2umac_trigger         0x0
 * </pre>
 */
#define IPC_LMAC_2_UMAC_TRIGGER_ADDR        (REG_IPC_BASE_ADDR+0x00000214)
#define IPC_LMAC_2_UMAC_TRIGGER_OFFSET      0x00000214
#define IPC_LMAC_2_UMAC_TRIGGER_INDEX       0x00000085
#define IPC_LMAC_2_UMAC_TRIGGER_RESET       0x00000000

__INLINE void ipc_lmac_2_umac_trigger_set(uint32_t value)
{
	REG_PL_WR(IPC_LMAC_2_UMAC_TRIGGER_ADDR, value);
}

// field definitions
#define IPC_LMAC_2_UMAC_TRIGGER_LMAC_2_UMAC_TRIGGER_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_LMAC_2_UMAC_TRIGGER_LMAC_2_UMAC_TRIGGER_LSB    0
#define IPC_LMAC_2_UMAC_TRIGGER_LMAC_2_UMAC_TRIGGER_WIDTH    ((uint32_t)0x00000020)

#define IPC_LMAC_2_UMAC_TRIGGER_LMAC_2_UMAC_TRIGGER_RST    0x0

__INLINE void ipc_lmac_2_umac_trigger_lmac_2_umac_trigger_setf(uint32_t lmac2umactrigger)
{
	ASSERT_ERR((((uint32_t)lmac2umactrigger << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_LMAC_2_UMAC_TRIGGER_ADDR, (uint32_t)lmac2umactrigger << 0);
}

/**
 * @brief LMAC_2_SMAC_RAW_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 lmac2smac_raw_status      0x0
 * </pre>
 */
#define IPC_LMAC_2_SMAC_RAW_STATUS_ADDR        (REG_IPC_BASE_ADDR+0x00000220)
#define IPC_LMAC_2_SMAC_RAW_STATUS_OFFSET      0x00000220
#define IPC_LMAC_2_SMAC_RAW_STATUS_INDEX       0x00000088
#define IPC_LMAC_2_SMAC_RAW_STATUS_RESET       0x00000000

__INLINE uint32_t  ipc_lmac_2_smac_raw_status_get(void)
{
	return REG_PL_RD(IPC_LMAC_2_SMAC_RAW_STATUS_ADDR);
}

// field definitions
#define IPC_LMAC_2_SMAC_RAW_STATUS_LMAC_2_SMAC_RAW_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_LMAC_2_SMAC_RAW_STATUS_LMAC_2_SMAC_RAW_STATUS_LSB    0
#define IPC_LMAC_2_SMAC_RAW_STATUS_LMAC_2_SMAC_RAW_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_LMAC_2_SMAC_RAW_STATUS_LMAC_2_SMAC_RAW_STATUS_RST    0x0

__INLINE uint32_t ipc_lmac_2_smac_raw_status_lmac_2_smac_raw_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_LMAC_2_SMAC_RAW_STATUS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief LMAC_2_SMAC_ACK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 lmac2smac_ack             0x0
 * </pre>
 */
#define IPC_LMAC_2_SMAC_ACK_ADDR        (REG_IPC_BASE_ADDR+0x00000224)
#define IPC_LMAC_2_SMAC_ACK_OFFSET      0x00000224
#define IPC_LMAC_2_SMAC_ACK_INDEX       0x00000089
#define IPC_LMAC_2_SMAC_ACK_RESET       0x00000000

__INLINE void ipc_lmac_2_smac_ack_set(uint32_t value)
{
	REG_PL_WR(IPC_LMAC_2_SMAC_ACK_ADDR, value);
}

// field definitions
#define IPC_LMAC_2_SMAC_ACK_LMAC_2_SMAC_ACK_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_LMAC_2_SMAC_ACK_LMAC_2_SMAC_ACK_LSB    0
#define IPC_LMAC_2_SMAC_ACK_LMAC_2_SMAC_ACK_WIDTH    ((uint32_t)0x00000020)

#define IPC_LMAC_2_SMAC_ACK_LMAC_2_SMAC_ACK_RST    0x0

__INLINE void ipc_lmac_2_smac_ack_lmac_2_smac_ack_setf(uint32_t lmac2smacack)
{
	ASSERT_ERR((((uint32_t)lmac2smacack << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_LMAC_2_SMAC_ACK_ADDR, (uint32_t)lmac2smacack << 0);
}

/**
 * @brief LMAC_2_SMAC_ENABLE_SET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 lmac2smac_enable_set      0x0
 * </pre>
 */
#define IPC_LMAC_2_SMAC_ENABLE_SET_ADDR        (REG_IPC_BASE_ADDR+0x00000228)
#define IPC_LMAC_2_SMAC_ENABLE_SET_OFFSET      0x00000228
#define IPC_LMAC_2_SMAC_ENABLE_SET_INDEX       0x0000008A
#define IPC_LMAC_2_SMAC_ENABLE_SET_RESET       0x00000000

__INLINE void ipc_lmac_2_smac_enable_set_set(uint32_t value)
{
	REG_PL_WR(IPC_LMAC_2_SMAC_ENABLE_SET_ADDR, value);
}

// field definitions
#define IPC_LMAC_2_SMAC_ENABLE_SET_LMAC_2_SMAC_ENABLE_SET_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_LMAC_2_SMAC_ENABLE_SET_LMAC_2_SMAC_ENABLE_SET_LSB    0
#define IPC_LMAC_2_SMAC_ENABLE_SET_LMAC_2_SMAC_ENABLE_SET_WIDTH    ((uint32_t)0x00000020)

#define IPC_LMAC_2_SMAC_ENABLE_SET_LMAC_2_SMAC_ENABLE_SET_RST    0x0

__INLINE void ipc_lmac_2_smac_enable_set_lmac_2_smac_enable_set_setf(uint32_t lmac2smacenableset)
{
	ASSERT_ERR((((uint32_t)lmac2smacenableset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_LMAC_2_SMAC_ENABLE_SET_ADDR, (uint32_t)lmac2smacenableset << 0);
}

/**
 * @brief LMAC_2_SMAC_ENABLE_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 lmac2smac_enable_clear    0x0
 * </pre>
 */
#define IPC_LMAC_2_SMAC_ENABLE_CLEAR_ADDR        (REG_IPC_BASE_ADDR+0x0000022C)
#define IPC_LMAC_2_SMAC_ENABLE_CLEAR_OFFSET      0x0000022C
#define IPC_LMAC_2_SMAC_ENABLE_CLEAR_INDEX       0x0000008B
#define IPC_LMAC_2_SMAC_ENABLE_CLEAR_RESET       0x00000000

__INLINE void ipc_lmac_2_smac_enable_clear_set(uint32_t value)
{
	REG_PL_WR(IPC_LMAC_2_SMAC_ENABLE_CLEAR_ADDR, value);
}

// field definitions
#define IPC_LMAC_2_SMAC_ENABLE_CLEAR_LMAC_2_SMAC_ENABLE_CLEAR_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_LMAC_2_SMAC_ENABLE_CLEAR_LMAC_2_SMAC_ENABLE_CLEAR_LSB    0
#define IPC_LMAC_2_SMAC_ENABLE_CLEAR_LMAC_2_SMAC_ENABLE_CLEAR_WIDTH    ((uint32_t)0x00000020)

#define IPC_LMAC_2_SMAC_ENABLE_CLEAR_LMAC_2_SMAC_ENABLE_CLEAR_RST    0x0

__INLINE void ipc_lmac_2_smac_enable_clear_lmac_2_smac_enable_clear_setf(uint32_t lmac2smacenableclear)
{
	ASSERT_ERR((((uint32_t)lmac2smacenableclear << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_LMAC_2_SMAC_ENABLE_CLEAR_ADDR, (uint32_t)lmac2smacenableclear << 0);
}

/**
 * @brief LMAC_2_SMAC_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 lmac2smac_status          0x0
 * </pre>
 */
#define IPC_LMAC_2_SMAC_STATUS_ADDR        (REG_IPC_BASE_ADDR+0x00000230)
#define IPC_LMAC_2_SMAC_STATUS_OFFSET      0x00000230
#define IPC_LMAC_2_SMAC_STATUS_INDEX       0x0000008C
#define IPC_LMAC_2_SMAC_STATUS_RESET       0x00000000

__INLINE uint32_t  ipc_lmac_2_smac_status_get(void)
{
	return REG_PL_RD(IPC_LMAC_2_SMAC_STATUS_ADDR);
}

// field definitions
#define IPC_LMAC_2_SMAC_STATUS_LMAC_2_SMAC_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_LMAC_2_SMAC_STATUS_LMAC_2_SMAC_STATUS_LSB    0
#define IPC_LMAC_2_SMAC_STATUS_LMAC_2_SMAC_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_LMAC_2_SMAC_STATUS_LMAC_2_SMAC_STATUS_RST    0x0

__INLINE uint32_t ipc_lmac_2_smac_status_lmac_2_smac_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_LMAC_2_SMAC_STATUS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief LMAC_2_SMAC_TRIGGER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 lmac2smac_trigger         0x0
 * </pre>
 */
#define IPC_LMAC_2_SMAC_TRIGGER_ADDR        (REG_IPC_BASE_ADDR+0x00000234)
#define IPC_LMAC_2_SMAC_TRIGGER_OFFSET      0x00000234
#define IPC_LMAC_2_SMAC_TRIGGER_INDEX       0x0000008D
#define IPC_LMAC_2_SMAC_TRIGGER_RESET       0x00000000

__INLINE void ipc_lmac_2_smac_trigger_set(uint32_t value)
{
	REG_PL_WR(IPC_LMAC_2_SMAC_TRIGGER_ADDR, value);
}

// field definitions
#define IPC_LMAC_2_SMAC_TRIGGER_LMAC_2_SMAC_TRIGGER_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_LMAC_2_SMAC_TRIGGER_LMAC_2_SMAC_TRIGGER_LSB    0
#define IPC_LMAC_2_SMAC_TRIGGER_LMAC_2_SMAC_TRIGGER_WIDTH    ((uint32_t)0x00000020)

#define IPC_LMAC_2_SMAC_TRIGGER_LMAC_2_SMAC_TRIGGER_RST    0x0

__INLINE void ipc_lmac_2_smac_trigger_lmac_2_smac_trigger_setf(uint32_t lmac2smactrigger)
{
	ASSERT_ERR((((uint32_t)lmac2smactrigger << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_LMAC_2_SMAC_TRIGGER_ADDR, (uint32_t)lmac2smactrigger << 0);
}

/**
 * @brief UMAC_2_LMAC_RAW_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 umac2lmac_raw_status      0x0
 * </pre>
 */
#define IPC_UMAC_2_LMAC_RAW_STATUS_ADDR        (REG_IPC_BASE_ADDR+0x00000260)
#define IPC_UMAC_2_LMAC_RAW_STATUS_OFFSET      0x00000260
#define IPC_UMAC_2_LMAC_RAW_STATUS_INDEX       0x00000098
#define IPC_UMAC_2_LMAC_RAW_STATUS_RESET       0x00000000

__INLINE uint32_t  ipc_umac_2_lmac_raw_status_get(void)
{
	return REG_PL_RD(IPC_UMAC_2_LMAC_RAW_STATUS_ADDR);
}

// field definitions
#define IPC_UMAC_2_LMAC_RAW_STATUS_UMAC_2_LMAC_RAW_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_UMAC_2_LMAC_RAW_STATUS_UMAC_2_LMAC_RAW_STATUS_LSB    0
#define IPC_UMAC_2_LMAC_RAW_STATUS_UMAC_2_LMAC_RAW_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_UMAC_2_LMAC_RAW_STATUS_UMAC_2_LMAC_RAW_STATUS_RST    0x0

__INLINE uint32_t ipc_umac_2_lmac_raw_status_umac_2_lmac_raw_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_UMAC_2_LMAC_RAW_STATUS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief UMAC_2_LMAC_ACK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 umac2lmac_ack             0x0
 * </pre>
 */
#define IPC_UMAC_2_LMAC_ACK_ADDR        (REG_IPC_BASE_ADDR+0x00000264)
#define IPC_UMAC_2_LMAC_ACK_OFFSET      0x00000264
#define IPC_UMAC_2_LMAC_ACK_INDEX       0x00000099
#define IPC_UMAC_2_LMAC_ACK_RESET       0x00000000

__INLINE void ipc_umac_2_lmac_ack_set(uint32_t value)
{
	REG_PL_WR(IPC_UMAC_2_LMAC_ACK_ADDR, value);
}

// field definitions
#define IPC_UMAC_2_LMAC_ACK_UMAC_2_LMAC_ACK_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_UMAC_2_LMAC_ACK_UMAC_2_LMAC_ACK_LSB    0
#define IPC_UMAC_2_LMAC_ACK_UMAC_2_LMAC_ACK_WIDTH    ((uint32_t)0x00000020)

#define IPC_UMAC_2_LMAC_ACK_UMAC_2_LMAC_ACK_RST    0x0

__INLINE void ipc_umac_2_lmac_ack_umac_2_lmac_ack_setf(uint32_t umac2lmacack)
{
	ASSERT_ERR((((uint32_t)umac2lmacack << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_UMAC_2_LMAC_ACK_ADDR, (uint32_t)umac2lmacack << 0);
}

/**
 * @brief UMAC_2_LMAC_ENABLE_SET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 umac2lmac_enable_set      0x0
 * </pre>
 */
#define IPC_UMAC_2_LMAC_ENABLE_SET_ADDR        (REG_IPC_BASE_ADDR+0x00000268)
#define IPC_UMAC_2_LMAC_ENABLE_SET_OFFSET      0x00000268
#define IPC_UMAC_2_LMAC_ENABLE_SET_INDEX       0x0000009A
#define IPC_UMAC_2_LMAC_ENABLE_SET_RESET       0x00000000

__INLINE void ipc_umac_2_lmac_enable_set_set(uint32_t value)
{
	REG_PL_WR(IPC_UMAC_2_LMAC_ENABLE_SET_ADDR, value);
}

// field definitions
#define IPC_UMAC_2_LMAC_ENABLE_SET_UMAC_2_LMAC_ENABLE_SET_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_UMAC_2_LMAC_ENABLE_SET_UMAC_2_LMAC_ENABLE_SET_LSB    0
#define IPC_UMAC_2_LMAC_ENABLE_SET_UMAC_2_LMAC_ENABLE_SET_WIDTH    ((uint32_t)0x00000020)

#define IPC_UMAC_2_LMAC_ENABLE_SET_UMAC_2_LMAC_ENABLE_SET_RST    0x0

__INLINE void ipc_umac_2_lmac_enable_set_umac_2_lmac_enable_set_setf(uint32_t umac2lmacenableset)
{
	ASSERT_ERR((((uint32_t)umac2lmacenableset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_UMAC_2_LMAC_ENABLE_SET_ADDR, (uint32_t)umac2lmacenableset << 0);
}

/**
 * @brief UMAC_2_LMAC_ENABLE_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 umac2lmac_enable_clear    0x0
 * </pre>
 */
#define IPC_UMAC_2_LMAC_ENABLE_CLEAR_ADDR        (REG_IPC_BASE_ADDR+0x0000026C)
#define IPC_UMAC_2_LMAC_ENABLE_CLEAR_OFFSET      0x0000026C
#define IPC_UMAC_2_LMAC_ENABLE_CLEAR_INDEX       0x0000009B
#define IPC_UMAC_2_LMAC_ENABLE_CLEAR_RESET       0x00000000

__INLINE void ipc_umac_2_lmac_enable_clear_set(uint32_t value)
{
	REG_PL_WR(IPC_UMAC_2_LMAC_ENABLE_CLEAR_ADDR, value);
}

// field definitions
#define IPC_UMAC_2_LMAC_ENABLE_CLEAR_UMAC_2_LMAC_ENABLE_CLEAR_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_UMAC_2_LMAC_ENABLE_CLEAR_UMAC_2_LMAC_ENABLE_CLEAR_LSB    0
#define IPC_UMAC_2_LMAC_ENABLE_CLEAR_UMAC_2_LMAC_ENABLE_CLEAR_WIDTH    ((uint32_t)0x00000020)

#define IPC_UMAC_2_LMAC_ENABLE_CLEAR_UMAC_2_LMAC_ENABLE_CLEAR_RST    0x0

__INLINE void ipc_umac_2_lmac_enable_clear_umac_2_lmac_enable_clear_setf(uint32_t umac2lmacenableclear)
{
	ASSERT_ERR((((uint32_t)umac2lmacenableclear << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_UMAC_2_LMAC_ENABLE_CLEAR_ADDR, (uint32_t)umac2lmacenableclear << 0);
}

/**
 * @brief UMAC_2_LMAC_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 umac2lmac_status          0x0
 * </pre>
 */
#define IPC_UMAC_2_LMAC_STATUS_ADDR        (REG_IPC_BASE_ADDR+0x00000270)
#define IPC_UMAC_2_LMAC_STATUS_OFFSET      0x00000270
#define IPC_UMAC_2_LMAC_STATUS_INDEX       0x0000009C
#define IPC_UMAC_2_LMAC_STATUS_RESET       0x00000000

__INLINE uint32_t  ipc_umac_2_lmac_status_get(void)
{
	return REG_PL_RD(IPC_UMAC_2_LMAC_STATUS_ADDR);
}

// field definitions
#define IPC_UMAC_2_LMAC_STATUS_UMAC_2_LMAC_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_UMAC_2_LMAC_STATUS_UMAC_2_LMAC_STATUS_LSB    0
#define IPC_UMAC_2_LMAC_STATUS_UMAC_2_LMAC_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_UMAC_2_LMAC_STATUS_UMAC_2_LMAC_STATUS_RST    0x0

__INLINE uint32_t ipc_umac_2_lmac_status_umac_2_lmac_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_UMAC_2_LMAC_STATUS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief UMAC_2_LMAC_TRIGGER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 umac2lmac_trigger         0x0
 * </pre>
 */
#define IPC_UMAC_2_LMAC_TRIGGER_ADDR        (REG_IPC_BASE_ADDR+0x00000274)
#define IPC_UMAC_2_LMAC_TRIGGER_OFFSET      0x00000274
#define IPC_UMAC_2_LMAC_TRIGGER_INDEX       0x0000009D
#define IPC_UMAC_2_LMAC_TRIGGER_RESET       0x00000000

__INLINE void ipc_umac_2_lmac_trigger_set(uint32_t value)
{
	REG_PL_WR(IPC_UMAC_2_LMAC_TRIGGER_ADDR, value);
}

// field definitions
#define IPC_UMAC_2_LMAC_TRIGGER_UMAC_2_LMAC_TRIGGER_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_UMAC_2_LMAC_TRIGGER_UMAC_2_LMAC_TRIGGER_LSB    0
#define IPC_UMAC_2_LMAC_TRIGGER_UMAC_2_LMAC_TRIGGER_WIDTH    ((uint32_t)0x00000020)

#define IPC_UMAC_2_LMAC_TRIGGER_UMAC_2_LMAC_TRIGGER_RST    0x0

__INLINE void ipc_umac_2_lmac_trigger_umac_2_lmac_trigger_setf(uint32_t umac2lmactrigger)
{
	ASSERT_ERR((((uint32_t)umac2lmactrigger << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_UMAC_2_LMAC_TRIGGER_ADDR, (uint32_t)umac2lmactrigger << 0);
}

/**
 * @brief UMAC_2_SMAC_RAW_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 umac2smac_raw_status      0x0
 * </pre>
 */
#define IPC_UMAC_2_SMAC_RAW_STATUS_ADDR        (REG_IPC_BASE_ADDR+0x00000280)
#define IPC_UMAC_2_SMAC_RAW_STATUS_OFFSET      0x00000280
#define IPC_UMAC_2_SMAC_RAW_STATUS_INDEX       0x000000A0
#define IPC_UMAC_2_SMAC_RAW_STATUS_RESET       0x00000000

__INLINE uint32_t  ipc_umac_2_smac_raw_status_get(void)
{
	return REG_PL_RD(IPC_UMAC_2_SMAC_RAW_STATUS_ADDR);
}

// field definitions
#define IPC_UMAC_2_SMAC_RAW_STATUS_UMAC_2_SMAC_RAW_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_UMAC_2_SMAC_RAW_STATUS_UMAC_2_SMAC_RAW_STATUS_LSB    0
#define IPC_UMAC_2_SMAC_RAW_STATUS_UMAC_2_SMAC_RAW_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_UMAC_2_SMAC_RAW_STATUS_UMAC_2_SMAC_RAW_STATUS_RST    0x0

__INLINE uint32_t ipc_umac_2_smac_raw_status_umac_2_smac_raw_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_UMAC_2_SMAC_RAW_STATUS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief UMAC_2_SMAC_ACK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 umac2smac_ack             0x0
 * </pre>
 */
#define IPC_UMAC_2_SMAC_ACK_ADDR        (REG_IPC_BASE_ADDR+0x00000284)
#define IPC_UMAC_2_SMAC_ACK_OFFSET      0x00000284
#define IPC_UMAC_2_SMAC_ACK_INDEX       0x000000A1
#define IPC_UMAC_2_SMAC_ACK_RESET       0x00000000

__INLINE void ipc_umac_2_smac_ack_set(uint32_t value)
{
	REG_PL_WR(IPC_UMAC_2_SMAC_ACK_ADDR, value);
}

// field definitions
#define IPC_UMAC_2_SMAC_ACK_UMAC_2_SMAC_ACK_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_UMAC_2_SMAC_ACK_UMAC_2_SMAC_ACK_LSB    0
#define IPC_UMAC_2_SMAC_ACK_UMAC_2_SMAC_ACK_WIDTH    ((uint32_t)0x00000020)

#define IPC_UMAC_2_SMAC_ACK_UMAC_2_SMAC_ACK_RST    0x0

__INLINE void ipc_umac_2_smac_ack_umac_2_smac_ack_setf(uint32_t umac2smacack)
{
	ASSERT_ERR((((uint32_t)umac2smacack << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_UMAC_2_SMAC_ACK_ADDR, (uint32_t)umac2smacack << 0);
}

/**
 * @brief UMAC_2_SMAC_ENABLE_SET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 umac2smac_enable_set      0x0
 * </pre>
 */
#define IPC_UMAC_2_SMAC_ENABLE_SET_ADDR        (REG_IPC_BASE_ADDR+0x00000288)
#define IPC_UMAC_2_SMAC_ENABLE_SET_OFFSET      0x00000288
#define IPC_UMAC_2_SMAC_ENABLE_SET_INDEX       0x000000A2
#define IPC_UMAC_2_SMAC_ENABLE_SET_RESET       0x00000000

__INLINE void ipc_umac_2_smac_enable_set_set(uint32_t value)
{
	REG_PL_WR(IPC_UMAC_2_SMAC_ENABLE_SET_ADDR, value);
}

// field definitions
#define IPC_UMAC_2_SMAC_ENABLE_SET_UMAC_2_SMAC_ENABLE_SET_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_UMAC_2_SMAC_ENABLE_SET_UMAC_2_SMAC_ENABLE_SET_LSB    0
#define IPC_UMAC_2_SMAC_ENABLE_SET_UMAC_2_SMAC_ENABLE_SET_WIDTH    ((uint32_t)0x00000020)

#define IPC_UMAC_2_SMAC_ENABLE_SET_UMAC_2_SMAC_ENABLE_SET_RST    0x0

__INLINE void ipc_umac_2_smac_enable_set_umac_2_smac_enable_set_setf(uint32_t umac2smacenableset)
{
	ASSERT_ERR((((uint32_t)umac2smacenableset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_UMAC_2_SMAC_ENABLE_SET_ADDR, (uint32_t)umac2smacenableset << 0);
}

/**
 * @brief UMAC_2_SMAC_ENABLE_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 umac2smac_enable_clear    0x0
 * </pre>
 */
#define IPC_UMAC_2_SMAC_ENABLE_CLEAR_ADDR        (REG_IPC_BASE_ADDR+0x0000028C)
#define IPC_UMAC_2_SMAC_ENABLE_CLEAR_OFFSET      0x0000028C
#define IPC_UMAC_2_SMAC_ENABLE_CLEAR_INDEX       0x000000A3
#define IPC_UMAC_2_SMAC_ENABLE_CLEAR_RESET       0x00000000

__INLINE void ipc_umac_2_smac_enable_clear_set(uint32_t value)
{
	REG_PL_WR(IPC_UMAC_2_SMAC_ENABLE_CLEAR_ADDR, value);
}

// field definitions
#define IPC_UMAC_2_SMAC_ENABLE_CLEAR_UMAC_2_SMAC_ENABLE_CLEAR_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_UMAC_2_SMAC_ENABLE_CLEAR_UMAC_2_SMAC_ENABLE_CLEAR_LSB    0
#define IPC_UMAC_2_SMAC_ENABLE_CLEAR_UMAC_2_SMAC_ENABLE_CLEAR_WIDTH    ((uint32_t)0x00000020)

#define IPC_UMAC_2_SMAC_ENABLE_CLEAR_UMAC_2_SMAC_ENABLE_CLEAR_RST    0x0

__INLINE void ipc_umac_2_smac_enable_clear_umac_2_smac_enable_clear_setf(uint32_t umac2smacenableclear)
{
	ASSERT_ERR((((uint32_t)umac2smacenableclear << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_UMAC_2_SMAC_ENABLE_CLEAR_ADDR, (uint32_t)umac2smacenableclear << 0);
}

/**
 * @brief UMAC_2_SMAC_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 umac2smac_status          0x0
 * </pre>
 */
#define IPC_UMAC_2_SMAC_STATUS_ADDR        (REG_IPC_BASE_ADDR+0x00000290)
#define IPC_UMAC_2_SMAC_STATUS_OFFSET      0x00000290
#define IPC_UMAC_2_SMAC_STATUS_INDEX       0x000000A4
#define IPC_UMAC_2_SMAC_STATUS_RESET       0x00000000

__INLINE uint32_t  ipc_umac_2_smac_status_get(void)
{
	return REG_PL_RD(IPC_UMAC_2_SMAC_STATUS_ADDR);
}

// field definitions
#define IPC_UMAC_2_SMAC_STATUS_UMAC_2_SMAC_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_UMAC_2_SMAC_STATUS_UMAC_2_SMAC_STATUS_LSB    0
#define IPC_UMAC_2_SMAC_STATUS_UMAC_2_SMAC_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_UMAC_2_SMAC_STATUS_UMAC_2_SMAC_STATUS_RST    0x0

__INLINE uint32_t ipc_umac_2_smac_status_umac_2_smac_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_UMAC_2_SMAC_STATUS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief UMAC_2_SMAC_TRIGGER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 umac2smac_trigger         0x0
 * </pre>
 */
#define IPC_UMAC_2_SMAC_TRIGGER_ADDR        (REG_IPC_BASE_ADDR+0x00000294)
#define IPC_UMAC_2_SMAC_TRIGGER_OFFSET      0x00000294
#define IPC_UMAC_2_SMAC_TRIGGER_INDEX       0x000000A5
#define IPC_UMAC_2_SMAC_TRIGGER_RESET       0x00000000

__INLINE void ipc_umac_2_smac_trigger_set(uint32_t value)
{
	REG_PL_WR(IPC_UMAC_2_SMAC_TRIGGER_ADDR, value);
}

// field definitions
#define IPC_UMAC_2_SMAC_TRIGGER_UMAC_2_SMAC_TRIGGER_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_UMAC_2_SMAC_TRIGGER_UMAC_2_SMAC_TRIGGER_LSB    0
#define IPC_UMAC_2_SMAC_TRIGGER_UMAC_2_SMAC_TRIGGER_WIDTH    ((uint32_t)0x00000020)

#define IPC_UMAC_2_SMAC_TRIGGER_UMAC_2_SMAC_TRIGGER_RST    0x0

__INLINE void ipc_umac_2_smac_trigger_umac_2_smac_trigger_setf(uint32_t umac2smactrigger)
{
	ASSERT_ERR((((uint32_t)umac2smactrigger << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_UMAC_2_SMAC_TRIGGER_ADDR, (uint32_t)umac2smactrigger << 0);
}

/**
 * @brief SMAC_2_LMAC_RAW_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 smac2lmac_raw_status      0x0
 * </pre>
 */
#define IPC_SMAC_2_LMAC_RAW_STATUS_ADDR        (REG_IPC_BASE_ADDR+0x000002C0)
#define IPC_SMAC_2_LMAC_RAW_STATUS_OFFSET      0x000002C0
#define IPC_SMAC_2_LMAC_RAW_STATUS_INDEX       0x000000B0
#define IPC_SMAC_2_LMAC_RAW_STATUS_RESET       0x00000000

__INLINE uint32_t  ipc_smac_2_lmac_raw_status_get(void)
{
	return REG_PL_RD(IPC_SMAC_2_LMAC_RAW_STATUS_ADDR);
}

// field definitions
#define IPC_SMAC_2_LMAC_RAW_STATUS_SMAC_2_LMAC_RAW_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_SMAC_2_LMAC_RAW_STATUS_SMAC_2_LMAC_RAW_STATUS_LSB    0
#define IPC_SMAC_2_LMAC_RAW_STATUS_SMAC_2_LMAC_RAW_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_SMAC_2_LMAC_RAW_STATUS_SMAC_2_LMAC_RAW_STATUS_RST    0x0

__INLINE uint32_t ipc_smac_2_lmac_raw_status_smac_2_lmac_raw_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_SMAC_2_LMAC_RAW_STATUS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief SMAC_2_LMAC_ACK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 smac2lmac_ack             0x0
 * </pre>
 */
#define IPC_SMAC_2_LMAC_ACK_ADDR        (REG_IPC_BASE_ADDR+0x000002C4)
#define IPC_SMAC_2_LMAC_ACK_OFFSET      0x000002C4
#define IPC_SMAC_2_LMAC_ACK_INDEX       0x000000B1
#define IPC_SMAC_2_LMAC_ACK_RESET       0x00000000

__INLINE void ipc_smac_2_lmac_ack_set(uint32_t value)
{
	REG_PL_WR(IPC_SMAC_2_LMAC_ACK_ADDR, value);
}

// field definitions
#define IPC_SMAC_2_LMAC_ACK_SMAC_2_LMAC_ACK_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_SMAC_2_LMAC_ACK_SMAC_2_LMAC_ACK_LSB    0
#define IPC_SMAC_2_LMAC_ACK_SMAC_2_LMAC_ACK_WIDTH    ((uint32_t)0x00000020)

#define IPC_SMAC_2_LMAC_ACK_SMAC_2_LMAC_ACK_RST    0x0

__INLINE void ipc_smac_2_lmac_ack_smac_2_lmac_ack_setf(uint32_t smac2lmacack)
{
	ASSERT_ERR((((uint32_t)smac2lmacack << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_SMAC_2_LMAC_ACK_ADDR, (uint32_t)smac2lmacack << 0);
}

/**
 * @brief SMAC_2_LMAC_ENABLE_SET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 smac2lmac_enable_set      0x0
 * </pre>
 */
#define IPC_SMAC_2_LMAC_ENABLE_SET_ADDR        (REG_IPC_BASE_ADDR+0x000002C8)
#define IPC_SMAC_2_LMAC_ENABLE_SET_OFFSET      0x000002C8
#define IPC_SMAC_2_LMAC_ENABLE_SET_INDEX       0x000000B2
#define IPC_SMAC_2_LMAC_ENABLE_SET_RESET       0x00000000

__INLINE void ipc_smac_2_lmac_enable_set_set(uint32_t value)
{
	REG_PL_WR(IPC_SMAC_2_LMAC_ENABLE_SET_ADDR, value);
}

// field definitions
#define IPC_SMAC_2_LMAC_ENABLE_SET_SMAC_2_LMAC_ENABLE_SET_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_SMAC_2_LMAC_ENABLE_SET_SMAC_2_LMAC_ENABLE_SET_LSB    0
#define IPC_SMAC_2_LMAC_ENABLE_SET_SMAC_2_LMAC_ENABLE_SET_WIDTH    ((uint32_t)0x00000020)

#define IPC_SMAC_2_LMAC_ENABLE_SET_SMAC_2_LMAC_ENABLE_SET_RST    0x0

__INLINE void ipc_smac_2_lmac_enable_set_smac_2_lmac_enable_set_setf(uint32_t smac2lmacenableset)
{
	ASSERT_ERR((((uint32_t)smac2lmacenableset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_SMAC_2_LMAC_ENABLE_SET_ADDR, (uint32_t)smac2lmacenableset << 0);
}

/**
 * @brief SMAC_2_LMAC_ENABLE_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 smac2lmac_enable_clear    0x0
 * </pre>
 */
#define IPC_SMAC_2_LMAC_ENABLE_CLEAR_ADDR        (REG_IPC_BASE_ADDR+0x000002CC)
#define IPC_SMAC_2_LMAC_ENABLE_CLEAR_OFFSET      0x000002CC
#define IPC_SMAC_2_LMAC_ENABLE_CLEAR_INDEX       0x000000B3
#define IPC_SMAC_2_LMAC_ENABLE_CLEAR_RESET       0x00000000

__INLINE void ipc_smac_2_lmac_enable_clear_set(uint32_t value)
{
	REG_PL_WR(IPC_SMAC_2_LMAC_ENABLE_CLEAR_ADDR, value);
}

// field definitions
#define IPC_SMAC_2_LMAC_ENABLE_CLEAR_SMAC_2_LMAC_ENABLE_CLEAR_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_SMAC_2_LMAC_ENABLE_CLEAR_SMAC_2_LMAC_ENABLE_CLEAR_LSB    0
#define IPC_SMAC_2_LMAC_ENABLE_CLEAR_SMAC_2_LMAC_ENABLE_CLEAR_WIDTH    ((uint32_t)0x00000020)

#define IPC_SMAC_2_LMAC_ENABLE_CLEAR_SMAC_2_LMAC_ENABLE_CLEAR_RST    0x0

__INLINE void ipc_smac_2_lmac_enable_clear_smac_2_lmac_enable_clear_setf(uint32_t smac2lmacenableclear)
{
	ASSERT_ERR((((uint32_t)smac2lmacenableclear << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_SMAC_2_LMAC_ENABLE_CLEAR_ADDR, (uint32_t)smac2lmacenableclear << 0);
}

/**
 * @brief SMAC_2_LMAC_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 smac2lmac_status          0x0
 * </pre>
 */
#define IPC_SMAC_2_LMAC_STATUS_ADDR        (REG_IPC_BASE_ADDR+0x000002D0)
#define IPC_SMAC_2_LMAC_STATUS_OFFSET      0x000002D0
#define IPC_SMAC_2_LMAC_STATUS_INDEX       0x000000B4
#define IPC_SMAC_2_LMAC_STATUS_RESET       0x00000000

__INLINE uint32_t  ipc_smac_2_lmac_status_get(void)
{
	return REG_PL_RD(IPC_SMAC_2_LMAC_STATUS_ADDR);
}

// field definitions
#define IPC_SMAC_2_LMAC_STATUS_SMAC_2_LMAC_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_SMAC_2_LMAC_STATUS_SMAC_2_LMAC_STATUS_LSB    0
#define IPC_SMAC_2_LMAC_STATUS_SMAC_2_LMAC_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_SMAC_2_LMAC_STATUS_SMAC_2_LMAC_STATUS_RST    0x0

__INLINE uint32_t ipc_smac_2_lmac_status_smac_2_lmac_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_SMAC_2_LMAC_STATUS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief SMAC_2_LMAC_TRIGGER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 smac2lmac_trigger         0x0
 * </pre>
 */
#define IPC_SMAC_2_LMAC_TRIGGER_ADDR        (REG_IPC_BASE_ADDR+0x000002D4)
#define IPC_SMAC_2_LMAC_TRIGGER_OFFSET      0x000002D4
#define IPC_SMAC_2_LMAC_TRIGGER_INDEX       0x000000B5
#define IPC_SMAC_2_LMAC_TRIGGER_RESET       0x00000000

__INLINE void ipc_smac_2_lmac_trigger_set(uint32_t value)
{
	REG_PL_WR(IPC_SMAC_2_LMAC_TRIGGER_ADDR, value);
}

// field definitions
#define IPC_SMAC_2_LMAC_TRIGGER_SMAC_2_LMAC_TRIGGER_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_SMAC_2_LMAC_TRIGGER_SMAC_2_LMAC_TRIGGER_LSB    0
#define IPC_SMAC_2_LMAC_TRIGGER_SMAC_2_LMAC_TRIGGER_WIDTH    ((uint32_t)0x00000020)

#define IPC_SMAC_2_LMAC_TRIGGER_SMAC_2_LMAC_TRIGGER_RST    0x0

__INLINE void ipc_smac_2_lmac_trigger_smac_2_lmac_trigger_setf(uint32_t smac2lmactrigger)
{
	ASSERT_ERR((((uint32_t)smac2lmactrigger << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_SMAC_2_LMAC_TRIGGER_ADDR, (uint32_t)smac2lmactrigger << 0);
}

/**
 * @brief SMAC_2_UMAC_RAW_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 smac2umac_raw_status      0x0
 * </pre>
 */
#define IPC_SMAC_2_UMAC_RAW_STATUS_ADDR        (REG_IPC_BASE_ADDR+0x000002E0)
#define IPC_SMAC_2_UMAC_RAW_STATUS_OFFSET      0x000002E0
#define IPC_SMAC_2_UMAC_RAW_STATUS_INDEX       0x000000B8
#define IPC_SMAC_2_UMAC_RAW_STATUS_RESET       0x00000000

__INLINE uint32_t  ipc_smac_2_umac_raw_status_get(void)
{
	return REG_PL_RD(IPC_SMAC_2_UMAC_RAW_STATUS_ADDR);
}

// field definitions
#define IPC_SMAC_2_UMAC_RAW_STATUS_SMAC_2_UMAC_RAW_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_SMAC_2_UMAC_RAW_STATUS_SMAC_2_UMAC_RAW_STATUS_LSB    0
#define IPC_SMAC_2_UMAC_RAW_STATUS_SMAC_2_UMAC_RAW_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_SMAC_2_UMAC_RAW_STATUS_SMAC_2_UMAC_RAW_STATUS_RST    0x0

__INLINE uint32_t ipc_smac_2_umac_raw_status_smac_2_umac_raw_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_SMAC_2_UMAC_RAW_STATUS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief SMAC_2_UMAC_ACK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 smac2umac_ack             0x0
 * </pre>
 */
#define IPC_SMAC_2_UMAC_ACK_ADDR        (REG_IPC_BASE_ADDR+0x000002E4)
#define IPC_SMAC_2_UMAC_ACK_OFFSET      0x000002E4
#define IPC_SMAC_2_UMAC_ACK_INDEX       0x000000B9
#define IPC_SMAC_2_UMAC_ACK_RESET       0x00000000

__INLINE void ipc_smac_2_umac_ack_set(uint32_t value)
{
	REG_PL_WR(IPC_SMAC_2_UMAC_ACK_ADDR, value);
}

// field definitions
#define IPC_SMAC_2_UMAC_ACK_SMAC_2_UMAC_ACK_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_SMAC_2_UMAC_ACK_SMAC_2_UMAC_ACK_LSB    0
#define IPC_SMAC_2_UMAC_ACK_SMAC_2_UMAC_ACK_WIDTH    ((uint32_t)0x00000020)

#define IPC_SMAC_2_UMAC_ACK_SMAC_2_UMAC_ACK_RST    0x0

__INLINE void ipc_smac_2_umac_ack_smac_2_umac_ack_setf(uint32_t smac2umacack)
{
	ASSERT_ERR((((uint32_t)smac2umacack << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_SMAC_2_UMAC_ACK_ADDR, (uint32_t)smac2umacack << 0);
}

/**
 * @brief SMAC_2_UMAC_ENABLE_SET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 smac2umac_enable_set      0x0
 * </pre>
 */
#define IPC_SMAC_2_UMAC_ENABLE_SET_ADDR        (REG_IPC_BASE_ADDR+0x000002E8)
#define IPC_SMAC_2_UMAC_ENABLE_SET_OFFSET      0x000002E8
#define IPC_SMAC_2_UMAC_ENABLE_SET_INDEX       0x000000BA
#define IPC_SMAC_2_UMAC_ENABLE_SET_RESET       0x00000000

__INLINE void ipc_smac_2_umac_enable_set_set(uint32_t value)
{
	REG_PL_WR(IPC_SMAC_2_UMAC_ENABLE_SET_ADDR, value);
}

// field definitions
#define IPC_SMAC_2_UMAC_ENABLE_SET_SMAC_2_UMAC_ENABLE_SET_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_SMAC_2_UMAC_ENABLE_SET_SMAC_2_UMAC_ENABLE_SET_LSB    0
#define IPC_SMAC_2_UMAC_ENABLE_SET_SMAC_2_UMAC_ENABLE_SET_WIDTH    ((uint32_t)0x00000020)

#define IPC_SMAC_2_UMAC_ENABLE_SET_SMAC_2_UMAC_ENABLE_SET_RST    0x0

__INLINE void ipc_smac_2_umac_enable_set_smac_2_umac_enable_set_setf(uint32_t smac2umacenableset)
{
	ASSERT_ERR((((uint32_t)smac2umacenableset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_SMAC_2_UMAC_ENABLE_SET_ADDR, (uint32_t)smac2umacenableset << 0);
}

/**
 * @brief SMAC_2_UMAC_ENABLE_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 smac2umac_enable_clear    0x0
 * </pre>
 */
#define IPC_SMAC_2_UMAC_ENABLE_CLEAR_ADDR        (REG_IPC_BASE_ADDR+0x000002EC)
#define IPC_SMAC_2_UMAC_ENABLE_CLEAR_OFFSET      0x000002EC
#define IPC_SMAC_2_UMAC_ENABLE_CLEAR_INDEX       0x000000BB
#define IPC_SMAC_2_UMAC_ENABLE_CLEAR_RESET       0x00000000

__INLINE void ipc_smac_2_umac_enable_clear_set(uint32_t value)
{
	REG_PL_WR(IPC_SMAC_2_UMAC_ENABLE_CLEAR_ADDR, value);
}

// field definitions
#define IPC_SMAC_2_UMAC_ENABLE_CLEAR_SMAC_2_UMAC_ENABLE_CLEAR_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_SMAC_2_UMAC_ENABLE_CLEAR_SMAC_2_UMAC_ENABLE_CLEAR_LSB    0
#define IPC_SMAC_2_UMAC_ENABLE_CLEAR_SMAC_2_UMAC_ENABLE_CLEAR_WIDTH    ((uint32_t)0x00000020)

#define IPC_SMAC_2_UMAC_ENABLE_CLEAR_SMAC_2_UMAC_ENABLE_CLEAR_RST    0x0

__INLINE void ipc_smac_2_umac_enable_clear_smac_2_umac_enable_clear_setf(uint32_t smac2umacenableclear)
{
	ASSERT_ERR((((uint32_t)smac2umacenableclear << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_SMAC_2_UMAC_ENABLE_CLEAR_ADDR, (uint32_t)smac2umacenableclear << 0);
}

/**
 * @brief SMAC_2_UMAC_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 smac2umac_status          0x0
 * </pre>
 */
#define IPC_SMAC_2_UMAC_STATUS_ADDR        (REG_IPC_BASE_ADDR+0x000002F0)
#define IPC_SMAC_2_UMAC_STATUS_OFFSET      0x000002F0
#define IPC_SMAC_2_UMAC_STATUS_INDEX       0x000000BC
#define IPC_SMAC_2_UMAC_STATUS_RESET       0x00000000

__INLINE uint32_t  ipc_smac_2_umac_status_get(void)
{
	return REG_PL_RD(IPC_SMAC_2_UMAC_STATUS_ADDR);
}

// field definitions
#define IPC_SMAC_2_UMAC_STATUS_SMAC_2_UMAC_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_SMAC_2_UMAC_STATUS_SMAC_2_UMAC_STATUS_LSB    0
#define IPC_SMAC_2_UMAC_STATUS_SMAC_2_UMAC_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_SMAC_2_UMAC_STATUS_SMAC_2_UMAC_STATUS_RST    0x0

__INLINE uint32_t ipc_smac_2_umac_status_smac_2_umac_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_SMAC_2_UMAC_STATUS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief SMAC_2_UMAC_TRIGGER register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 smac2umac_trigger         0x0
 * </pre>
 */
#define IPC_SMAC_2_UMAC_TRIGGER_ADDR        (REG_IPC_BASE_ADDR+0x000002F4)
#define IPC_SMAC_2_UMAC_TRIGGER_OFFSET      0x000002F4
#define IPC_SMAC_2_UMAC_TRIGGER_INDEX       0x000000BD
#define IPC_SMAC_2_UMAC_TRIGGER_RESET       0x00000000

__INLINE void ipc_smac_2_umac_trigger_set(uint32_t value)
{
	REG_PL_WR(IPC_SMAC_2_UMAC_TRIGGER_ADDR, value);
}

// field definitions
#define IPC_SMAC_2_UMAC_TRIGGER_SMAC_2_UMAC_TRIGGER_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_SMAC_2_UMAC_TRIGGER_SMAC_2_UMAC_TRIGGER_LSB    0
#define IPC_SMAC_2_UMAC_TRIGGER_SMAC_2_UMAC_TRIGGER_WIDTH    ((uint32_t)0x00000020)

#define IPC_SMAC_2_UMAC_TRIGGER_SMAC_2_UMAC_TRIGGER_RST    0x0

__INLINE void ipc_smac_2_umac_trigger_smac_2_umac_trigger_setf(uint32_t smac2umactrigger)
{
	ASSERT_ERR((((uint32_t)smac2umactrigger << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_SMAC_2_UMAC_TRIGGER_ADDR, (uint32_t)smac2umactrigger << 0);
}

/**
 * @brief HOST_2_LMAC_RAW_STAT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 host2lmac_raw_status      0x0
 * </pre>
 */
#define IPC_HOST_2_LMAC_RAW_STAT_ADDR        (REG_IPC_BASE_ADDR+0x00000300)
#define IPC_HOST_2_LMAC_RAW_STAT_OFFSET      0x00000300
#define IPC_HOST_2_LMAC_RAW_STAT_INDEX       0x000000C0
#define IPC_HOST_2_LMAC_RAW_STAT_RESET       0x00000000

__INLINE uint32_t  ipc_host_2_lmac_raw_stat_get(void)
{
	return REG_PL_RD(IPC_HOST_2_LMAC_RAW_STAT_ADDR);
}

// field definitions
#define IPC_HOST_2_LMAC_RAW_STAT_HOST_2_LMAC_RAW_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_HOST_2_LMAC_RAW_STAT_HOST_2_LMAC_RAW_STATUS_LSB    0
#define IPC_HOST_2_LMAC_RAW_STAT_HOST_2_LMAC_RAW_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_HOST_2_LMAC_RAW_STAT_HOST_2_LMAC_RAW_STATUS_RST    0x0

__INLINE uint32_t ipc_host_2_lmac_raw_stat_host_2_lmac_raw_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_HOST_2_LMAC_RAW_STAT_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief HOST_2_LMAC_ACK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 host2lmac_ack             0x0
 * </pre>
 */
#define IPC_HOST_2_LMAC_ACK_ADDR        (REG_IPC_BASE_ADDR+0x00000304)
#define IPC_HOST_2_LMAC_ACK_OFFSET      0x00000304
#define IPC_HOST_2_LMAC_ACK_INDEX       0x000000C1
#define IPC_HOST_2_LMAC_ACK_RESET       0x00000000

__INLINE void ipc_host_2_lmac_ack_set(uint32_t value)
{
	REG_PL_WR(IPC_HOST_2_LMAC_ACK_ADDR, value);
}

// field definitions
#define IPC_HOST_2_LMAC_ACK_HOST_2_LMAC_ACK_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_HOST_2_LMAC_ACK_HOST_2_LMAC_ACK_LSB    0
#define IPC_HOST_2_LMAC_ACK_HOST_2_LMAC_ACK_WIDTH    ((uint32_t)0x00000020)

#define IPC_HOST_2_LMAC_ACK_HOST_2_LMAC_ACK_RST    0x0

__INLINE void ipc_host_2_lmac_ack_host_2_lmac_ack_setf(uint32_t host2lmacack)
{
	ASSERT_ERR((((uint32_t)host2lmacack << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_HOST_2_LMAC_ACK_ADDR, (uint32_t)host2lmacack << 0);
}

/**
 * @brief HOST_2_LMAC_ENABLE_SET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 host2lmac_enable_set      0x0
 * </pre>
 */
#define IPC_HOST_2_LMAC_ENABLE_SET_ADDR        (REG_IPC_BASE_ADDR+0x00000308)
#define IPC_HOST_2_LMAC_ENABLE_SET_OFFSET      0x00000308
#define IPC_HOST_2_LMAC_ENABLE_SET_INDEX       0x000000C2
#define IPC_HOST_2_LMAC_ENABLE_SET_RESET       0x00000000

__INLINE void ipc_host_2_lmac_enable_set_set(uint32_t value)
{
	REG_PL_WR(IPC_HOST_2_LMAC_ENABLE_SET_ADDR, value);
}

// field definitions
#define IPC_HOST_2_LMAC_ENABLE_SET_HOST_2_LMAC_ENABLE_SET_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_HOST_2_LMAC_ENABLE_SET_HOST_2_LMAC_ENABLE_SET_LSB    0
#define IPC_HOST_2_LMAC_ENABLE_SET_HOST_2_LMAC_ENABLE_SET_WIDTH    ((uint32_t)0x00000020)

#define IPC_HOST_2_LMAC_ENABLE_SET_HOST_2_LMAC_ENABLE_SET_RST    0x0

__INLINE void ipc_host_2_lmac_enable_set_host_2_lmac_enable_set_setf(uint32_t host2lmacenableset)
{
	ASSERT_ERR((((uint32_t)host2lmacenableset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_HOST_2_LMAC_ENABLE_SET_ADDR, (uint32_t)host2lmacenableset << 0);
}

/**
 * @brief HOST_2_LMAC_ENABLE_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 host2lmac_enable_clear    0x0
 * </pre>
 */
#define IPC_HOST_2_LMAC_ENABLE_CLEAR_ADDR        (REG_IPC_BASE_ADDR+0x0000030C)
#define IPC_HOST_2_LMAC_ENABLE_CLEAR_OFFSET      0x0000030C
#define IPC_HOST_2_LMAC_ENABLE_CLEAR_INDEX       0x000000C3
#define IPC_HOST_2_LMAC_ENABLE_CLEAR_RESET       0x00000000

__INLINE void ipc_host_2_lmac_enable_clear_set(uint32_t value)
{
	REG_PL_WR(IPC_HOST_2_LMAC_ENABLE_CLEAR_ADDR, value);
}

// field definitions
#define IPC_HOST_2_LMAC_ENABLE_CLEAR_HOST_2_LMAC_ENABLE_CLEAR_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_HOST_2_LMAC_ENABLE_CLEAR_HOST_2_LMAC_ENABLE_CLEAR_LSB    0
#define IPC_HOST_2_LMAC_ENABLE_CLEAR_HOST_2_LMAC_ENABLE_CLEAR_WIDTH    ((uint32_t)0x00000020)

#define IPC_HOST_2_LMAC_ENABLE_CLEAR_HOST_2_LMAC_ENABLE_CLEAR_RST    0x0

__INLINE void ipc_host_2_lmac_enable_clear_host_2_lmac_enable_clear_setf(uint32_t host2lmacenableclear)
{
	ASSERT_ERR((((uint32_t)host2lmacenableclear << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_HOST_2_LMAC_ENABLE_CLEAR_ADDR, (uint32_t)host2lmacenableclear << 0);
}

/**
 * @brief HOST_2_LMAC_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 host2lmac_status          0x0
 * </pre>
 */
#define IPC_HOST_2_LMAC_STATUS_ADDR        (REG_IPC_BASE_ADDR+0x00000310)
#define IPC_HOST_2_LMAC_STATUS_OFFSET      0x00000310
#define IPC_HOST_2_LMAC_STATUS_INDEX       0x000000C4
#define IPC_HOST_2_LMAC_STATUS_RESET       0x00000000

__INLINE uint32_t  ipc_host_2_lmac_status_get(void)
{
	return REG_PL_RD(IPC_HOST_2_LMAC_STATUS_ADDR);
}

// field definitions
#define IPC_HOST_2_LMAC_STATUS_HOST_2_LMAC_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_HOST_2_LMAC_STATUS_HOST_2_LMAC_STATUS_LSB    0
#define IPC_HOST_2_LMAC_STATUS_HOST_2_LMAC_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_HOST_2_LMAC_STATUS_HOST_2_LMAC_STATUS_RST    0x0

__INLINE uint32_t ipc_host_2_lmac_status_host_2_lmac_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_HOST_2_LMAC_STATUS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief HOST_2_UMAC_RAW_STAT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 host2umac_raw_status      0x0
 * </pre>
 */
#define IPC_HOST_2_UMAC_RAW_STAT_ADDR        (REG_IPC_BASE_ADDR+0x00000320)
#define IPC_HOST_2_UMAC_RAW_STAT_OFFSET      0x00000320
#define IPC_HOST_2_UMAC_RAW_STAT_INDEX       0x000000C8
#define IPC_HOST_2_UMAC_RAW_STAT_RESET       0x00000000

__INLINE uint32_t  ipc_host_2_umac_raw_stat_get(void)
{
	return REG_PL_RD(IPC_HOST_2_UMAC_RAW_STAT_ADDR);
}

// field definitions
#define IPC_HOST_2_UMAC_RAW_STAT_HOST_2_UMAC_RAW_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_HOST_2_UMAC_RAW_STAT_HOST_2_UMAC_RAW_STATUS_LSB    0
#define IPC_HOST_2_UMAC_RAW_STAT_HOST_2_UMAC_RAW_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_HOST_2_UMAC_RAW_STAT_HOST_2_UMAC_RAW_STATUS_RST    0x0

__INLINE uint32_t ipc_host_2_umac_raw_stat_host_2_umac_raw_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_HOST_2_UMAC_RAW_STAT_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief HOST_2_UMAC_ACK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 host2umac_ack             0x0
 * </pre>
 */
#define IPC_HOST_2_UMAC_ACK_ADDR        (REG_IPC_BASE_ADDR+0x00000324)
#define IPC_HOST_2_UMAC_ACK_OFFSET      0x00000324
#define IPC_HOST_2_UMAC_ACK_INDEX       0x000000C9
#define IPC_HOST_2_UMAC_ACK_RESET       0x00000000

__INLINE void ipc_host_2_umac_ack_set(uint32_t value)
{
	REG_PL_WR(IPC_HOST_2_UMAC_ACK_ADDR, value);
}

// field definitions
#define IPC_HOST_2_UMAC_ACK_HOST_2_UMAC_ACK_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_HOST_2_UMAC_ACK_HOST_2_UMAC_ACK_LSB    0
#define IPC_HOST_2_UMAC_ACK_HOST_2_UMAC_ACK_WIDTH    ((uint32_t)0x00000020)

#define IPC_HOST_2_UMAC_ACK_HOST_2_UMAC_ACK_RST    0x0

__INLINE void ipc_host_2_umac_ack_host_2_umac_ack_setf(uint32_t host2umacack)
{
	ASSERT_ERR((((uint32_t)host2umacack << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_HOST_2_UMAC_ACK_ADDR, (uint32_t)host2umacack << 0);
}

/**
 * @brief HOST_2_UMAC_ENABLE_SET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 host2umac_enable_set      0x0
 * </pre>
 */
#define IPC_HOST_2_UMAC_ENABLE_SET_ADDR        (REG_IPC_BASE_ADDR+0x00000328)
#define IPC_HOST_2_UMAC_ENABLE_SET_OFFSET      0x00000328
#define IPC_HOST_2_UMAC_ENABLE_SET_INDEX       0x000000CA
#define IPC_HOST_2_UMAC_ENABLE_SET_RESET       0x00000000

__INLINE void ipc_host_2_umac_enable_set_set(uint32_t value)
{
	REG_PL_WR(IPC_HOST_2_UMAC_ENABLE_SET_ADDR, value);
}

// field definitions
#define IPC_HOST_2_UMAC_ENABLE_SET_HOST_2_UMAC_ENABLE_SET_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_HOST_2_UMAC_ENABLE_SET_HOST_2_UMAC_ENABLE_SET_LSB    0
#define IPC_HOST_2_UMAC_ENABLE_SET_HOST_2_UMAC_ENABLE_SET_WIDTH    ((uint32_t)0x00000020)

#define IPC_HOST_2_UMAC_ENABLE_SET_HOST_2_UMAC_ENABLE_SET_RST    0x0

__INLINE void ipc_host_2_umac_enable_set_host_2_umac_enable_set_setf(uint32_t host2umacenableset)
{
	ASSERT_ERR((((uint32_t)host2umacenableset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_HOST_2_UMAC_ENABLE_SET_ADDR, (uint32_t)host2umacenableset << 0);
}

/**
 * @brief HOST_2_UMAC_ENABLE_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 host2umac_enable_clear    0x0
 * </pre>
 */
#define IPC_HOST_2_UMAC_ENABLE_CLEAR_ADDR        (REG_IPC_BASE_ADDR+0x0000032C)
#define IPC_HOST_2_UMAC_ENABLE_CLEAR_OFFSET      0x0000032C
#define IPC_HOST_2_UMAC_ENABLE_CLEAR_INDEX       0x000000CB
#define IPC_HOST_2_UMAC_ENABLE_CLEAR_RESET       0x00000000

__INLINE void ipc_host_2_umac_enable_clear_set(uint32_t value)
{
	REG_PL_WR(IPC_HOST_2_UMAC_ENABLE_CLEAR_ADDR, value);
}

// field definitions
#define IPC_HOST_2_UMAC_ENABLE_CLEAR_HOST_2_UMAC_ENABLE_CLEAR_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_HOST_2_UMAC_ENABLE_CLEAR_HOST_2_UMAC_ENABLE_CLEAR_LSB    0
#define IPC_HOST_2_UMAC_ENABLE_CLEAR_HOST_2_UMAC_ENABLE_CLEAR_WIDTH    ((uint32_t)0x00000020)

#define IPC_HOST_2_UMAC_ENABLE_CLEAR_HOST_2_UMAC_ENABLE_CLEAR_RST    0x0

__INLINE void ipc_host_2_umac_enable_clear_host_2_umac_enable_clear_setf(uint32_t host2umacenableclear)
{
	ASSERT_ERR((((uint32_t)host2umacenableclear << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_HOST_2_UMAC_ENABLE_CLEAR_ADDR, (uint32_t)host2umacenableclear << 0);
}

/**
 * @brief HOST_2_UMAC_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 host2umac_status          0x0
 * </pre>
 */
#define IPC_HOST_2_UMAC_STATUS_ADDR        (REG_IPC_BASE_ADDR+0x00000330)
#define IPC_HOST_2_UMAC_STATUS_OFFSET      0x00000330
#define IPC_HOST_2_UMAC_STATUS_INDEX       0x000000CC
#define IPC_HOST_2_UMAC_STATUS_RESET       0x00000000

__INLINE uint32_t  ipc_host_2_umac_status_get(void)
{
	return REG_PL_RD(IPC_HOST_2_UMAC_STATUS_ADDR);
}

// field definitions
#define IPC_HOST_2_UMAC_STATUS_HOST_2_UMAC_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_HOST_2_UMAC_STATUS_HOST_2_UMAC_STATUS_LSB    0
#define IPC_HOST_2_UMAC_STATUS_HOST_2_UMAC_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_HOST_2_UMAC_STATUS_HOST_2_UMAC_STATUS_RST    0x0

__INLINE uint32_t ipc_host_2_umac_status_host_2_umac_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_HOST_2_UMAC_STATUS_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief HOST_2_SMAC_RAW_STAT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 host2smac_raw_status      0x0
 * </pre>
 */
#define IPC_HOST_2_SMAC_RAW_STAT_ADDR        (REG_IPC_BASE_ADDR+0x00000340)
#define IPC_HOST_2_SMAC_RAW_STAT_OFFSET      0x00000340
#define IPC_HOST_2_SMAC_RAW_STAT_INDEX       0x000000D0
#define IPC_HOST_2_SMAC_RAW_STAT_RESET       0x00000000

__INLINE uint32_t  ipc_host_2_smac_raw_stat_get(void)
{
	return REG_PL_RD(IPC_HOST_2_SMAC_RAW_STAT_ADDR);
}

// field definitions
#define IPC_HOST_2_SMAC_RAW_STAT_HOST_2_SMAC_RAW_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_HOST_2_SMAC_RAW_STAT_HOST_2_SMAC_RAW_STATUS_LSB    0
#define IPC_HOST_2_SMAC_RAW_STAT_HOST_2_SMAC_RAW_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_HOST_2_SMAC_RAW_STAT_HOST_2_SMAC_RAW_STATUS_RST    0x0

__INLINE uint32_t ipc_host_2_smac_raw_stat_host_2_smac_raw_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_HOST_2_SMAC_RAW_STAT_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief HOST_2_SMAC_ACK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 host2smac_ack             0x0
 * </pre>
 */
#define IPC_HOST_2_SMAC_ACK_ADDR        (REG_IPC_BASE_ADDR+0x00000344)
#define IPC_HOST_2_SMAC_ACK_OFFSET      0x00000344
#define IPC_HOST_2_SMAC_ACK_INDEX       0x000000D1
#define IPC_HOST_2_SMAC_ACK_RESET       0x00000000

__INLINE void ipc_host_2_smac_ack_set(uint32_t value)
{
	REG_PL_WR(IPC_HOST_2_SMAC_ACK_ADDR, value);
}

// field definitions
#define IPC_HOST_2_SMAC_ACK_HOST_2_SMAC_ACK_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_HOST_2_SMAC_ACK_HOST_2_SMAC_ACK_LSB    0
#define IPC_HOST_2_SMAC_ACK_HOST_2_SMAC_ACK_WIDTH    ((uint32_t)0x00000020)

#define IPC_HOST_2_SMAC_ACK_HOST_2_SMAC_ACK_RST    0x0

__INLINE void ipc_host_2_smac_ack_host_2_smac_ack_setf(uint32_t host2smacack)
{
	ASSERT_ERR((((uint32_t)host2smacack << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_HOST_2_SMAC_ACK_ADDR, (uint32_t)host2smacack << 0);
}

/**
 * @brief HOST_2_SMAC_ENABLE_SET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 host2smac_enable_set      0x0
 * </pre>
 */
#define IPC_HOST_2_SMAC_ENABLE_SET_ADDR        (REG_IPC_BASE_ADDR+0x00000348)
#define IPC_HOST_2_SMAC_ENABLE_SET_OFFSET      0x00000348
#define IPC_HOST_2_SMAC_ENABLE_SET_INDEX       0x000000D2
#define IPC_HOST_2_SMAC_ENABLE_SET_RESET       0x00000000

__INLINE void ipc_host_2_smac_enable_set_set(uint32_t value)
{
	REG_PL_WR(IPC_HOST_2_SMAC_ENABLE_SET_ADDR, value);
}

// field definitions
#define IPC_HOST_2_SMAC_ENABLE_SET_HOST_2_SMAC_ENABLE_SET_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_HOST_2_SMAC_ENABLE_SET_HOST_2_SMAC_ENABLE_SET_LSB    0
#define IPC_HOST_2_SMAC_ENABLE_SET_HOST_2_SMAC_ENABLE_SET_WIDTH    ((uint32_t)0x00000020)

#define IPC_HOST_2_SMAC_ENABLE_SET_HOST_2_SMAC_ENABLE_SET_RST    0x0

__INLINE void ipc_host_2_smac_enable_set_host_2_smac_enable_set_setf(uint32_t host2smacenableset)
{
	ASSERT_ERR((((uint32_t)host2smacenableset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_HOST_2_SMAC_ENABLE_SET_ADDR, (uint32_t)host2smacenableset << 0);
}

/**
 * @brief HOST_2_SMAC_ENABLE_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 host2smac_enable_clear    0x0
 * </pre>
 */
#define IPC_HOST_2_SMAC_ENABLE_CLEAR_ADDR        (REG_IPC_BASE_ADDR+0x0000034C)
#define IPC_HOST_2_SMAC_ENABLE_CLEAR_OFFSET      0x0000034C
#define IPC_HOST_2_SMAC_ENABLE_CLEAR_INDEX       0x000000D3
#define IPC_HOST_2_SMAC_ENABLE_CLEAR_RESET       0x00000000

__INLINE void ipc_host_2_smac_enable_clear_set(uint32_t value)
{
	REG_PL_WR(IPC_HOST_2_SMAC_ENABLE_CLEAR_ADDR, value);
}

// field definitions
#define IPC_HOST_2_SMAC_ENABLE_CLEAR_HOST_2_SMAC_ENABLE_CLEAR_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_HOST_2_SMAC_ENABLE_CLEAR_HOST_2_SMAC_ENABLE_CLEAR_LSB    0
#define IPC_HOST_2_SMAC_ENABLE_CLEAR_HOST_2_SMAC_ENABLE_CLEAR_WIDTH    ((uint32_t)0x00000020)

#define IPC_HOST_2_SMAC_ENABLE_CLEAR_HOST_2_SMAC_ENABLE_CLEAR_RST    0x0

__INLINE void ipc_host_2_smac_enable_clear_host_2_smac_enable_clear_setf(uint32_t host2smacenableclear)
{
	ASSERT_ERR((((uint32_t)host2smacenableclear << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(IPC_HOST_2_SMAC_ENABLE_CLEAR_ADDR, (uint32_t)host2smacenableclear << 0);
}

/**
 * @brief HOST_2_SMAC_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 host2smac_status          0x0
 * </pre>
 */
#define IPC_HOST_2_SMAC_STATUS_ADDR        (REG_IPC_BASE_ADDR+0x00000350)
#define IPC_HOST_2_SMAC_STATUS_OFFSET      0x00000350
#define IPC_HOST_2_SMAC_STATUS_INDEX       0x000000D4
#define IPC_HOST_2_SMAC_STATUS_RESET       0x00000000

__INLINE uint32_t  ipc_host_2_smac_status_get(void)
{
	return REG_PL_RD(IPC_HOST_2_SMAC_STATUS_ADDR);
}

// field definitions
#define IPC_HOST_2_SMAC_STATUS_HOST_2_SMAC_STATUS_MASK    ((uint32_t)0xFFFFFFFF)
#define IPC_HOST_2_SMAC_STATUS_HOST_2_SMAC_STATUS_LSB    0
#define IPC_HOST_2_SMAC_STATUS_HOST_2_SMAC_STATUS_WIDTH    ((uint32_t)0x00000020)

#define IPC_HOST_2_SMAC_STATUS_HOST_2_SMAC_STATUS_RST    0x0

__INLINE uint32_t ipc_host_2_smac_status_host_2_smac_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(IPC_HOST_2_SMAC_STATUS_ADDR);
	return (uint32_t)(localVal >> 0);
}


/** --------------------------------------
 *  CDB support 
 *  parsing all ipc_host_2_xmac_ type func
 *  PRIM_BAND functions are _lmac_ type. 
 *  SEC_BAND  functions are _smac_ type. 
 *  use wrapper define '_xmac_'.
 * -----------------------------------------
 **/


#if PRIM_BAND
#define  ipc_host_2_xmac_trigger_set_wrap  ipc_host_2_lmac_trigger_set
#else
#define  ipc_host_2_xmac_trigger_set_wrap  ipc_host_2_smac_trigger_set
#endif


#if PRIM_BAND
#define  ipc_host_2_xmac_trigger_host_2_xmac_trigger_setf_wrap  ipc_host_2_lmac_trigger_host_2_lmac_trigger_setf
#else
#define  ipc_host_2_xmac_trigger_host_2_xmac_trigger_setf_wrap  ipc_host_2_smac_trigger_host_2_smac_trigger_setf
#endif


#if PRIM_BAND
#define   ipc_host_2_xmac_raw_stat_get_wrap   ipc_host_2_lmac_raw_stat_get
#else
#define   ipc_host_2_xmac_raw_stat_get_wrap   ipc_host_2_smac_raw_stat_get
#endif


#if PRIM_BAND
#define  ipc_host_2_xmac_raw_stat_host_2_xmac_raw_status_getf_wrap  ipc_host_2_lmac_raw_stat_host_2_lmac_raw_status_getf
#else
#define  ipc_host_2_xmac_raw_stat_host_2_xmac_raw_status_getf_wrap  ipc_host_2_smac_raw_stat_host_2_smac_raw_status_getf
#endif


#if PRIM_BAND
#define  ipc_host_2_xmac_ack_set_wrap  ipc_host_2_lmac_ack_set
#else
#define  ipc_host_2_xmac_ack_set_wrap  ipc_host_2_smac_ack_set
#endif


#if PRIM_BAND
#define  ipc_host_2_xmac_ack_host_2_xmac_ack_setf_wrap  ipc_host_2_lmac_ack_host_2_lmac_ack_setf
#else
#define  ipc_host_2_xmac_ack_host_2_xmac_ack_setf_wrap  ipc_host_2_smac_ack_host_2_smac_ack_setf
#endif


#if PRIM_BAND
#define  ipc_host_2_xmac_enable_set_set_wrap  ipc_host_2_lmac_enable_set_set
#else
#define  ipc_host_2_xmac_enable_set_set_wrap  ipc_host_2_smac_enable_set_set
#endif


#if PRIM_BAND
#define  ipc_host_2_xmac_enable_set_host_2_xmac_enable_set_setf_wrap  ipc_host_2_lmac_enable_set_host_2_lmac_enable_set_setf
#else
#define  ipc_host_2_xmac_enable_set_host_2_xmac_enable_set_setf_wrap  ipc_host_2_smac_enable_set_host_2_smac_enable_set_setf
#endif


#if PRIM_BAND
#define  ipc_host_2_xmac_enable_clear_set_wrap  ipc_host_2_lmac_enable_clear_set
#else
#define  ipc_host_2_xmac_enable_clear_set_wrap  ipc_host_2_smac_enable_clear_set
#endif


#if PRIM_BAND
#define  ipc_host_2_xmac_enable_clear_host_2_xmac_enable_clear_setf_wrap  ipc_host_2_lmac_enable_clear_host_2_lmac_enable_clear_setf
#else
#define  ipc_host_2_xmac_enable_clear_host_2_xmac_enable_clear_setf_wrap  ipc_host_2_smac_enable_clear_host_2_smac_enable_clear_setf
#endif


#if PRIM_BAND
#define   ipc_host_2_xmac_status_get_wrap   ipc_host_2_lmac_status_get
#else
#define   ipc_host_2_xmac_status_get_wrap   ipc_host_2_smac_status_get
#endif


#if PRIM_BAND
#define  ipc_host_2_xmac_status_host_2_xmac_status_getf_wrap  ipc_host_2_lmac_status_host_2_lmac_status_getf
#else
#define  ipc_host_2_xmac_status_host_2_xmac_status_getf_wrap  ipc_host_2_smac_status_host_2_smac_status_getf
#endif


// end CDB support section
//-------------------------
#undef DBG_FILEID
#endif //_REG_IPC_H_
