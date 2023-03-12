#ifndef _REG_ETH2WLAN_H_
#define _REG_ETH2WLAN_H_

#include <stdint.h>
#include "_reg_eth2wlan.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_ETH2WLAN__H__FILEID__

#define REG_ETH2WLAN_COUNT  21


/**
 * @brief DMA_LLI_DESC_BASE register definition
 *  base address of TX buffer register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 dma_tx_base               0x0
 * </pre>
 */
#define ETH2WLAN_DMA_LLI_DESC_BASE_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x00000000)
#define ETH2WLAN_DMA_LLI_DESC_BASE_OFFSET      0x00000000
#define ETH2WLAN_DMA_LLI_DESC_BASE_INDEX       0x00000000
#define ETH2WLAN_DMA_LLI_DESC_BASE_RESET       0x00000000

__INLINE uint32_t  eth2wlan_dma_lli_desc_base_get(void)
{
	return REG_PL_RD(ETH2WLAN_DMA_LLI_DESC_BASE_ADDR);
}

__INLINE void eth2wlan_dma_lli_desc_base_set(uint32_t value)
{
	REG_PL_WR(ETH2WLAN_DMA_LLI_DESC_BASE_ADDR, value);
}

// field definitions
#define ETH2WLAN_DMA_LLI_DESC_BASE_DMA_TX_BASE_MASK    ((uint32_t)0xFFFFFFFC)
#define ETH2WLAN_DMA_LLI_DESC_BASE_DMA_TX_BASE_LSB    2
#define ETH2WLAN_DMA_LLI_DESC_BASE_DMA_TX_BASE_WIDTH    ((uint32_t)0x0000001E)

#define ETH2WLAN_DMA_LLI_DESC_BASE_DMA_TX_BASE_RST    0x0

__INLINE uint32_t eth2wlan_dma_lli_desc_base_dma_tx_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_DMA_LLI_DESC_BASE_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void eth2wlan_dma_lli_desc_base_dma_tx_base_setf(uint32_t dmatxbase)
{
	ASSERT_ERR((((uint32_t)dmatxbase << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(ETH2WLAN_DMA_LLI_DESC_BASE_ADDR, (uint32_t)dmatxbase << 2);
}

/**
 * @brief BAND_1_COUNTERS_BASE register definition
 *  base address for packet counters in memory register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 counters_base             0x0
 * </pre>
 */
#define ETH2WLAN_BAND_1_COUNTERS_BASE_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x00000004)
#define ETH2WLAN_BAND_1_COUNTERS_BASE_OFFSET      0x00000004
#define ETH2WLAN_BAND_1_COUNTERS_BASE_INDEX       0x00000001
#define ETH2WLAN_BAND_1_COUNTERS_BASE_RESET       0x00000000

__INLINE uint32_t  eth2wlan_band_1_counters_base_get(void)
{
	return REG_PL_RD(ETH2WLAN_BAND_1_COUNTERS_BASE_ADDR);
}

__INLINE void eth2wlan_band_1_counters_base_set(uint32_t value)
{
	REG_PL_WR(ETH2WLAN_BAND_1_COUNTERS_BASE_ADDR, value);
}

// field definitions
#define ETH2WLAN_BAND_1_COUNTERS_BASE_COUNTERS_BASE_MASK    ((uint32_t)0xFFFFFFFC)
#define ETH2WLAN_BAND_1_COUNTERS_BASE_COUNTERS_BASE_LSB    2
#define ETH2WLAN_BAND_1_COUNTERS_BASE_COUNTERS_BASE_WIDTH    ((uint32_t)0x0000001E)

#define ETH2WLAN_BAND_1_COUNTERS_BASE_COUNTERS_BASE_RST    0x0

__INLINE uint32_t eth2wlan_band_1_counters_base_counters_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_BAND_1_COUNTERS_BASE_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void eth2wlan_band_1_counters_base_counters_base_setf(uint32_t countersbase)
{
	ASSERT_ERR((((uint32_t)countersbase << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(ETH2WLAN_BAND_1_COUNTERS_BASE_ADDR, (uint32_t)countersbase << 2);
}

/**
 * @brief BAND_1_STA_DB_BASE register definition
 *  Station Database base address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 sta_db_base               0x0
 * </pre>
 */
#define ETH2WLAN_BAND_1_STA_DB_BASE_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x00000008)
#define ETH2WLAN_BAND_1_STA_DB_BASE_OFFSET      0x00000008
#define ETH2WLAN_BAND_1_STA_DB_BASE_INDEX       0x00000002
#define ETH2WLAN_BAND_1_STA_DB_BASE_RESET       0x00000000

__INLINE uint32_t  eth2wlan_band_1_sta_db_base_get(void)
{
	return REG_PL_RD(ETH2WLAN_BAND_1_STA_DB_BASE_ADDR);
}

__INLINE void eth2wlan_band_1_sta_db_base_set(uint32_t value)
{
	REG_PL_WR(ETH2WLAN_BAND_1_STA_DB_BASE_ADDR, value);
}

// field definitions
#define ETH2WLAN_BAND_1_STA_DB_BASE_STA_DB_BASE_MASK    ((uint32_t)0xFFFFFFFC)
#define ETH2WLAN_BAND_1_STA_DB_BASE_STA_DB_BASE_LSB    2
#define ETH2WLAN_BAND_1_STA_DB_BASE_STA_DB_BASE_WIDTH    ((uint32_t)0x0000001E)

#define ETH2WLAN_BAND_1_STA_DB_BASE_STA_DB_BASE_RST    0x0

__INLINE uint32_t eth2wlan_band_1_sta_db_base_sta_db_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_BAND_1_STA_DB_BASE_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void eth2wlan_band_1_sta_db_base_sta_db_base_setf(uint32_t stadbbase)
{
	ASSERT_ERR((((uint32_t)stadbbase << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(ETH2WLAN_BAND_1_STA_DB_BASE_ADDR, (uint32_t)stadbbase << 2);
}

/**
 * @brief BAND_1_VIF_TABLE_BASE register definition
 *  base address for VIF table register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 vif_table_base            0x0
 * </pre>
 */
#define ETH2WLAN_BAND_1_VIF_TABLE_BASE_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x0000000C)
#define ETH2WLAN_BAND_1_VIF_TABLE_BASE_OFFSET      0x0000000C
#define ETH2WLAN_BAND_1_VIF_TABLE_BASE_INDEX       0x00000003
#define ETH2WLAN_BAND_1_VIF_TABLE_BASE_RESET       0x00000000

__INLINE uint32_t  eth2wlan_band_1_vif_table_base_get(void)
{
	return REG_PL_RD(ETH2WLAN_BAND_1_VIF_TABLE_BASE_ADDR);
}

__INLINE void eth2wlan_band_1_vif_table_base_set(uint32_t value)
{
	REG_PL_WR(ETH2WLAN_BAND_1_VIF_TABLE_BASE_ADDR, value);
}

// field definitions
#define ETH2WLAN_BAND_1_VIF_TABLE_BASE_VIF_TABLE_BASE_MASK    ((uint32_t)0xFFFFFFFC)
#define ETH2WLAN_BAND_1_VIF_TABLE_BASE_VIF_TABLE_BASE_LSB    2
#define ETH2WLAN_BAND_1_VIF_TABLE_BASE_VIF_TABLE_BASE_WIDTH    ((uint32_t)0x0000001E)

#define ETH2WLAN_BAND_1_VIF_TABLE_BASE_VIF_TABLE_BASE_RST    0x0

__INLINE uint32_t eth2wlan_band_1_vif_table_base_vif_table_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_BAND_1_VIF_TABLE_BASE_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void eth2wlan_band_1_vif_table_base_vif_table_base_setf(uint32_t viftablebase)
{
	ASSERT_ERR((((uint32_t)viftablebase << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(ETH2WLAN_BAND_1_VIF_TABLE_BASE_ADDR, (uint32_t)viftablebase << 2);
}

/**
 * @brief BAND_0_COUNTERS_BASE register definition
 *  base address for packet counters in memory register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 counters_base             0x0
 * </pre>
 */
#define ETH2WLAN_BAND_0_COUNTERS_BASE_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x00000010)
#define ETH2WLAN_BAND_0_COUNTERS_BASE_OFFSET      0x00000010
#define ETH2WLAN_BAND_0_COUNTERS_BASE_INDEX       0x00000004
#define ETH2WLAN_BAND_0_COUNTERS_BASE_RESET       0x00000000

__INLINE uint32_t  eth2wlan_band_0_counters_base_get(void)
{
	return REG_PL_RD(ETH2WLAN_BAND_0_COUNTERS_BASE_ADDR);
}

__INLINE void eth2wlan_band_0_counters_base_set(uint32_t value)
{
	REG_PL_WR(ETH2WLAN_BAND_0_COUNTERS_BASE_ADDR, value);
}

// field definitions
#define ETH2WLAN_BAND_0_COUNTERS_BASE_COUNTERS_BASE_MASK    ((uint32_t)0xFFFFFFFC)
#define ETH2WLAN_BAND_0_COUNTERS_BASE_COUNTERS_BASE_LSB    2
#define ETH2WLAN_BAND_0_COUNTERS_BASE_COUNTERS_BASE_WIDTH    ((uint32_t)0x0000001E)

#define ETH2WLAN_BAND_0_COUNTERS_BASE_COUNTERS_BASE_RST    0x0

__INLINE uint32_t eth2wlan_band_0_counters_base_counters_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_BAND_0_COUNTERS_BASE_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void eth2wlan_band_0_counters_base_counters_base_setf(uint32_t countersbase)
{
	ASSERT_ERR((((uint32_t)countersbase << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(ETH2WLAN_BAND_0_COUNTERS_BASE_ADDR, (uint32_t)countersbase << 2);
}

/**
 * @brief BAND_0_STA_DB_BASE register definition
 *  Station Database base address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 sta_db_base               0x0
 * </pre>
 */
#define ETH2WLAN_BAND_0_STA_DB_BASE_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x00000018)
#define ETH2WLAN_BAND_0_STA_DB_BASE_OFFSET      0x00000018
#define ETH2WLAN_BAND_0_STA_DB_BASE_INDEX       0x00000006
#define ETH2WLAN_BAND_0_STA_DB_BASE_RESET       0x00000000

__INLINE uint32_t  eth2wlan_band_0_sta_db_base_get(void)
{
	return REG_PL_RD(ETH2WLAN_BAND_0_STA_DB_BASE_ADDR);
}

__INLINE void eth2wlan_band_0_sta_db_base_set(uint32_t value)
{
	REG_PL_WR(ETH2WLAN_BAND_0_STA_DB_BASE_ADDR, value);
}

// field definitions
#define ETH2WLAN_BAND_0_STA_DB_BASE_STA_DB_BASE_MASK    ((uint32_t)0xFFFFFFFC)
#define ETH2WLAN_BAND_0_STA_DB_BASE_STA_DB_BASE_LSB    2
#define ETH2WLAN_BAND_0_STA_DB_BASE_STA_DB_BASE_WIDTH    ((uint32_t)0x0000001E)

#define ETH2WLAN_BAND_0_STA_DB_BASE_STA_DB_BASE_RST    0x0

__INLINE uint32_t eth2wlan_band_0_sta_db_base_sta_db_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_BAND_0_STA_DB_BASE_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void eth2wlan_band_0_sta_db_base_sta_db_base_setf(uint32_t stadbbase)
{
	ASSERT_ERR((((uint32_t)stadbbase << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(ETH2WLAN_BAND_0_STA_DB_BASE_ADDR, (uint32_t)stadbbase << 2);
}

/**
 * @brief ETH_2_WLAN_ADD_PARAMS register definition
 *  Additional parameters for ETH2WLAN Tx conversion register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:26 tx_desc_ptr_offset        0x0
 *    23:18 dma_desc_size             0x5
 *    15:10 payload_offset            0xd
 *    07:02 thd_tbd_size              0x1c
 * </pre>
 */
#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x0000001C)
#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_OFFSET      0x0000001C
#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_INDEX       0x00000007
#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_RESET       0x00143470

__INLINE uint32_t  eth2wlan_eth_2_wlan_add_params_get(void)
{
	return REG_PL_RD(ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_ADDR);
}

__INLINE void eth2wlan_eth_2_wlan_add_params_set(uint32_t value)
{
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_ADDR, value);
}

// field definitions
#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_TX_DESC_PTR_OFFSET_MASK    ((uint32_t)0xFC000000)
#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_TX_DESC_PTR_OFFSET_LSB    26
#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_TX_DESC_PTR_OFFSET_WIDTH    ((uint32_t)0x00000006)
#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_DMA_DESC_SIZE_MASK    ((uint32_t)0x00FC0000)
#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_DMA_DESC_SIZE_LSB    18
#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_DMA_DESC_SIZE_WIDTH    ((uint32_t)0x00000006)
#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_PAYLOAD_OFFSET_MASK    ((uint32_t)0x0000FC00)
#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_PAYLOAD_OFFSET_LSB    10
#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_PAYLOAD_OFFSET_WIDTH    ((uint32_t)0x00000006)
#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_THD_TBD_SIZE_MASK    ((uint32_t)0x000000FC)
#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_THD_TBD_SIZE_LSB    2
#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_THD_TBD_SIZE_WIDTH    ((uint32_t)0x00000006)

#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_TX_DESC_PTR_OFFSET_RST    0x0
#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_DMA_DESC_SIZE_RST    0x5
#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_PAYLOAD_OFFSET_RST    0xd
#define ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_THD_TBD_SIZE_RST    0x1c

__INLINE void eth2wlan_eth_2_wlan_add_params_pack(uint8_t tx_desc_ptr_offset, uint8_t dma_desc_size, uint8_t payload_offset, uint8_t thd_tbd_size)
{
	ASSERT_ERR((((uint32_t)tx_desc_ptr_offset << 26) & ~((uint32_t)0xFC000000)) == 0);
	ASSERT_ERR((((uint32_t)dma_desc_size << 18) & ~((uint32_t)0x00FC0000)) == 0);
	ASSERT_ERR((((uint32_t)payload_offset << 10) & ~((uint32_t)0x0000FC00)) == 0);
	ASSERT_ERR((((uint32_t)thd_tbd_size << 2) & ~((uint32_t)0x000000FC)) == 0);
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_ADDR,  ((uint32_t)tx_desc_ptr_offset << 26) |((uint32_t)dma_desc_size << 18) |((uint32_t)payload_offset << 10) |((uint32_t)thd_tbd_size << 2));
}

__INLINE void eth2wlan_eth_2_wlan_add_params_unpack(uint8_t* tx_desc_ptr_offset, uint8_t* dma_desc_size, uint8_t* payload_offset, uint8_t* thd_tbd_size)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_ADDR);

	*tx_desc_ptr_offset = (localVal & ((uint32_t)0xFC000000)) >>  26;
	*dma_desc_size = (localVal & ((uint32_t)0x00FC0000)) >>  18;
	*payload_offset = (localVal & ((uint32_t)0x0000FC00)) >>  10;
	*thd_tbd_size = (localVal & ((uint32_t)0x000000FC)) >>  2;
}

__INLINE uint8_t eth2wlan_eth_2_wlan_add_params_tx_desc_ptr_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFC000000)) >> 26);
}
__INLINE void eth2wlan_eth_2_wlan_add_params_tx_desc_ptr_offset_setf(uint8_t txdescptroffset)
{
	ASSERT_ERR((((uint32_t)txdescptroffset << 26) & ~((uint32_t)0xFC000000)) == 0);
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_ADDR, (REG_PL_RD(ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_ADDR) & ~((uint32_t)0xFC000000)) | ((uint32_t)txdescptroffset <<26));
}
__INLINE uint8_t eth2wlan_eth_2_wlan_add_params_dma_desc_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FC0000)) >> 18);
}
__INLINE void eth2wlan_eth_2_wlan_add_params_dma_desc_size_setf(uint8_t dmadescsize)
{
	ASSERT_ERR((((uint32_t)dmadescsize << 18) & ~((uint32_t)0x00FC0000)) == 0);
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_ADDR, (REG_PL_RD(ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_ADDR) & ~((uint32_t)0x00FC0000)) | ((uint32_t)dmadescsize <<18));
}
__INLINE uint8_t eth2wlan_eth_2_wlan_add_params_payload_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FC00)) >> 10);
}
__INLINE void eth2wlan_eth_2_wlan_add_params_payload_offset_setf(uint8_t payloadoffset)
{
	ASSERT_ERR((((uint32_t)payloadoffset << 10) & ~((uint32_t)0x0000FC00)) == 0);
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_ADDR, (REG_PL_RD(ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_ADDR) & ~((uint32_t)0x0000FC00)) | ((uint32_t)payloadoffset <<10));
}
__INLINE uint8_t eth2wlan_eth_2_wlan_add_params_thd_tbd_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FC)) >> 2);
}
__INLINE void eth2wlan_eth_2_wlan_add_params_thd_tbd_size_setf(uint8_t thdtbdsize)
{
	ASSERT_ERR((((uint32_t)thdtbdsize << 2) & ~((uint32_t)0x000000FC)) == 0);
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_ADDR, (REG_PL_RD(ETH2WLAN_ETH_2_WLAN_ADD_PARAMS_ADDR) & ~((uint32_t)0x000000FC)) | ((uint32_t)thdtbdsize <<2));
}

/**
 * @brief STA_ENTRY_OFFSETS register definition
 *  Offset of BSSID and RA definitions in STA_DB entry register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:18 vif_table_entry_size      0x0
 *    15:10 sta_entry_offset          0x0
 *    07:02 sta_db_entry_size         0x0
 * </pre>
 */
#define ETH2WLAN_STA_ENTRY_OFFSETS_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x00000020)
#define ETH2WLAN_STA_ENTRY_OFFSETS_OFFSET      0x00000020
#define ETH2WLAN_STA_ENTRY_OFFSETS_INDEX       0x00000008
#define ETH2WLAN_STA_ENTRY_OFFSETS_RESET       0x00000000

__INLINE uint32_t  eth2wlan_sta_entry_offsets_get(void)
{
	return REG_PL_RD(ETH2WLAN_STA_ENTRY_OFFSETS_ADDR);
}

__INLINE void eth2wlan_sta_entry_offsets_set(uint32_t value)
{
	REG_PL_WR(ETH2WLAN_STA_ENTRY_OFFSETS_ADDR, value);
}

// field definitions
#define ETH2WLAN_STA_ENTRY_OFFSETS_VIF_TABLE_ENTRY_SIZE_MASK    ((uint32_t)0x00FC0000)
#define ETH2WLAN_STA_ENTRY_OFFSETS_VIF_TABLE_ENTRY_SIZE_LSB    18
#define ETH2WLAN_STA_ENTRY_OFFSETS_VIF_TABLE_ENTRY_SIZE_WIDTH    ((uint32_t)0x00000006)
#define ETH2WLAN_STA_ENTRY_OFFSETS_STA_ENTRY_OFFSET_MASK    ((uint32_t)0x0000FC00)
#define ETH2WLAN_STA_ENTRY_OFFSETS_STA_ENTRY_OFFSET_LSB    10
#define ETH2WLAN_STA_ENTRY_OFFSETS_STA_ENTRY_OFFSET_WIDTH    ((uint32_t)0x00000006)
#define ETH2WLAN_STA_ENTRY_OFFSETS_STA_DB_ENTRY_SIZE_MASK    ((uint32_t)0x000000FC)
#define ETH2WLAN_STA_ENTRY_OFFSETS_STA_DB_ENTRY_SIZE_LSB    2
#define ETH2WLAN_STA_ENTRY_OFFSETS_STA_DB_ENTRY_SIZE_WIDTH    ((uint32_t)0x00000006)

#define ETH2WLAN_STA_ENTRY_OFFSETS_VIF_TABLE_ENTRY_SIZE_RST    0x0
#define ETH2WLAN_STA_ENTRY_OFFSETS_STA_ENTRY_OFFSET_RST    0x0
#define ETH2WLAN_STA_ENTRY_OFFSETS_STA_DB_ENTRY_SIZE_RST    0x0

__INLINE void eth2wlan_sta_entry_offsets_pack(uint8_t vif_table_entry_size, uint8_t sta_entry_offset, uint8_t sta_db_entry_size)
{
	ASSERT_ERR((((uint32_t)vif_table_entry_size << 18) & ~((uint32_t)0x00FC0000)) == 0);
	ASSERT_ERR((((uint32_t)sta_entry_offset << 10) & ~((uint32_t)0x0000FC00)) == 0);
	ASSERT_ERR((((uint32_t)sta_db_entry_size << 2) & ~((uint32_t)0x000000FC)) == 0);
	REG_PL_WR(ETH2WLAN_STA_ENTRY_OFFSETS_ADDR,  ((uint32_t)vif_table_entry_size << 18) |((uint32_t)sta_entry_offset << 10) |((uint32_t)sta_db_entry_size << 2));
}

__INLINE void eth2wlan_sta_entry_offsets_unpack(uint8_t* vif_table_entry_size, uint8_t* sta_entry_offset, uint8_t* sta_db_entry_size)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_STA_ENTRY_OFFSETS_ADDR);

	*vif_table_entry_size = (localVal & ((uint32_t)0x00FC0000)) >>  18;
	*sta_entry_offset = (localVal & ((uint32_t)0x0000FC00)) >>  10;
	*sta_db_entry_size = (localVal & ((uint32_t)0x000000FC)) >>  2;
}

__INLINE uint8_t eth2wlan_sta_entry_offsets_vif_table_entry_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_STA_ENTRY_OFFSETS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FC0000)) >> 18);
}
__INLINE void eth2wlan_sta_entry_offsets_vif_table_entry_size_setf(uint8_t viftableentrysize)
{
	ASSERT_ERR((((uint32_t)viftableentrysize << 18) & ~((uint32_t)0x00FC0000)) == 0);
	REG_PL_WR(ETH2WLAN_STA_ENTRY_OFFSETS_ADDR, (REG_PL_RD(ETH2WLAN_STA_ENTRY_OFFSETS_ADDR) & ~((uint32_t)0x00FC0000)) | ((uint32_t)viftableentrysize <<18));
}
__INLINE uint8_t eth2wlan_sta_entry_offsets_sta_entry_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_STA_ENTRY_OFFSETS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FC00)) >> 10);
}
__INLINE void eth2wlan_sta_entry_offsets_sta_entry_offset_setf(uint8_t staentryoffset)
{
	ASSERT_ERR((((uint32_t)staentryoffset << 10) & ~((uint32_t)0x0000FC00)) == 0);
	REG_PL_WR(ETH2WLAN_STA_ENTRY_OFFSETS_ADDR, (REG_PL_RD(ETH2WLAN_STA_ENTRY_OFFSETS_ADDR) & ~((uint32_t)0x0000FC00)) | ((uint32_t)staentryoffset <<10));
}
__INLINE uint8_t eth2wlan_sta_entry_offsets_sta_db_entry_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_STA_ENTRY_OFFSETS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FC)) >> 2);
}
__INLINE void eth2wlan_sta_entry_offsets_sta_db_entry_size_setf(uint8_t stadbentrysize)
{
	ASSERT_ERR((((uint32_t)stadbentrysize << 2) & ~((uint32_t)0x000000FC)) == 0);
	REG_PL_WR(ETH2WLAN_STA_ENTRY_OFFSETS_ADDR, (REG_PL_RD(ETH2WLAN_STA_ENTRY_OFFSETS_ADDR) & ~((uint32_t)0x000000FC)) | ((uint32_t)stadbentrysize <<2));
}

/**
 * @brief TX_DESC_OFFSETS_1 register definition
 *  Offset of packet parameters written in Tx Descript register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:26 tkip_ccmp_sequence_num_offset 0x0
 *    23:18 ht_control_offset         0x0
 *    15:10 eth2wlan_natt_common_offset 0x0
 *    07:02 frame_control_seq_control_offset 0x0
 * </pre>
 */
#define ETH2WLAN_TX_DESC_OFFSETS_1_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x00000024)
#define ETH2WLAN_TX_DESC_OFFSETS_1_OFFSET      0x00000024
#define ETH2WLAN_TX_DESC_OFFSETS_1_INDEX       0x00000009
#define ETH2WLAN_TX_DESC_OFFSETS_1_RESET       0x00000000

__INLINE uint32_t  eth2wlan_tx_desc_offsets_1_get(void)
{
	return REG_PL_RD(ETH2WLAN_TX_DESC_OFFSETS_1_ADDR);
}

__INLINE void eth2wlan_tx_desc_offsets_1_set(uint32_t value)
{
	REG_PL_WR(ETH2WLAN_TX_DESC_OFFSETS_1_ADDR, value);
}

// field definitions
#define ETH2WLAN_TX_DESC_OFFSETS_1_TKIP_CCMP_SEQUENCE_NUM_OFFSET_MASK    ((uint32_t)0xFC000000)
#define ETH2WLAN_TX_DESC_OFFSETS_1_TKIP_CCMP_SEQUENCE_NUM_OFFSET_LSB    26
#define ETH2WLAN_TX_DESC_OFFSETS_1_TKIP_CCMP_SEQUENCE_NUM_OFFSET_WIDTH    ((uint32_t)0x00000006)
#define ETH2WLAN_TX_DESC_OFFSETS_1_HT_CONTROL_OFFSET_MASK    ((uint32_t)0x00FC0000)
#define ETH2WLAN_TX_DESC_OFFSETS_1_HT_CONTROL_OFFSET_LSB    18
#define ETH2WLAN_TX_DESC_OFFSETS_1_HT_CONTROL_OFFSET_WIDTH    ((uint32_t)0x00000006)
#define ETH2WLAN_TX_DESC_OFFSETS_1_ETH_2_WLAN_NATT_COMMON_OFFSET_MASK    ((uint32_t)0x0000FC00)
#define ETH2WLAN_TX_DESC_OFFSETS_1_ETH_2_WLAN_NATT_COMMON_OFFSET_LSB    10
#define ETH2WLAN_TX_DESC_OFFSETS_1_ETH_2_WLAN_NATT_COMMON_OFFSET_WIDTH    ((uint32_t)0x00000006)
#define ETH2WLAN_TX_DESC_OFFSETS_1_FRAME_CONTROL_SEQ_CONTROL_OFFSET_MASK    ((uint32_t)0x000000FC)
#define ETH2WLAN_TX_DESC_OFFSETS_1_FRAME_CONTROL_SEQ_CONTROL_OFFSET_LSB    2
#define ETH2WLAN_TX_DESC_OFFSETS_1_FRAME_CONTROL_SEQ_CONTROL_OFFSET_WIDTH    ((uint32_t)0x00000006)

#define ETH2WLAN_TX_DESC_OFFSETS_1_TKIP_CCMP_SEQUENCE_NUM_OFFSET_RST    0x0
#define ETH2WLAN_TX_DESC_OFFSETS_1_HT_CONTROL_OFFSET_RST    0x0
#define ETH2WLAN_TX_DESC_OFFSETS_1_ETH_2_WLAN_NATT_COMMON_OFFSET_RST    0x0
#define ETH2WLAN_TX_DESC_OFFSETS_1_FRAME_CONTROL_SEQ_CONTROL_OFFSET_RST    0x0

__INLINE void eth2wlan_tx_desc_offsets_1_pack(uint8_t tkip_ccmp_sequence_num_offset, uint8_t ht_control_offset, uint8_t eth2wlan_natt_common_offset, uint8_t frame_control_seq_control_offset)
{
	ASSERT_ERR((((uint32_t)tkip_ccmp_sequence_num_offset << 26) & ~((uint32_t)0xFC000000)) == 0);
	ASSERT_ERR((((uint32_t)ht_control_offset << 18) & ~((uint32_t)0x00FC0000)) == 0);
	ASSERT_ERR((((uint32_t)eth2wlan_natt_common_offset << 10) & ~((uint32_t)0x0000FC00)) == 0);
	ASSERT_ERR((((uint32_t)frame_control_seq_control_offset << 2) & ~((uint32_t)0x000000FC)) == 0);
	REG_PL_WR(ETH2WLAN_TX_DESC_OFFSETS_1_ADDR,  ((uint32_t)tkip_ccmp_sequence_num_offset << 26) |((uint32_t)ht_control_offset << 18) |((uint32_t)eth2wlan_natt_common_offset << 10) |((uint32_t)frame_control_seq_control_offset << 2));
}

__INLINE void eth2wlan_tx_desc_offsets_1_unpack(uint8_t* tkip_ccmp_sequence_num_offset, uint8_t* ht_control_offset, uint8_t* eth2wlan_natt_common_offset, uint8_t* frame_control_seq_control_offset)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_TX_DESC_OFFSETS_1_ADDR);

	*tkip_ccmp_sequence_num_offset = (localVal & ((uint32_t)0xFC000000)) >>  26;
	*ht_control_offset = (localVal & ((uint32_t)0x00FC0000)) >>  18;
	*eth2wlan_natt_common_offset = (localVal & ((uint32_t)0x0000FC00)) >>  10;
	*frame_control_seq_control_offset = (localVal & ((uint32_t)0x000000FC)) >>  2;
}

__INLINE uint8_t eth2wlan_tx_desc_offsets_1_tkip_ccmp_sequence_num_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_TX_DESC_OFFSETS_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFC000000)) >> 26);
}
__INLINE void eth2wlan_tx_desc_offsets_1_tkip_ccmp_sequence_num_offset_setf(uint8_t tkipccmpsequencenumoffset)
{
	ASSERT_ERR((((uint32_t)tkipccmpsequencenumoffset << 26) & ~((uint32_t)0xFC000000)) == 0);
	REG_PL_WR(ETH2WLAN_TX_DESC_OFFSETS_1_ADDR, (REG_PL_RD(ETH2WLAN_TX_DESC_OFFSETS_1_ADDR) & ~((uint32_t)0xFC000000)) | ((uint32_t)tkipccmpsequencenumoffset <<26));
}
__INLINE uint8_t eth2wlan_tx_desc_offsets_1_ht_control_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_TX_DESC_OFFSETS_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FC0000)) >> 18);
}
__INLINE void eth2wlan_tx_desc_offsets_1_ht_control_offset_setf(uint8_t htcontroloffset)
{
	ASSERT_ERR((((uint32_t)htcontroloffset << 18) & ~((uint32_t)0x00FC0000)) == 0);
	REG_PL_WR(ETH2WLAN_TX_DESC_OFFSETS_1_ADDR, (REG_PL_RD(ETH2WLAN_TX_DESC_OFFSETS_1_ADDR) & ~((uint32_t)0x00FC0000)) | ((uint32_t)htcontroloffset <<18));
}
__INLINE uint8_t eth2wlan_tx_desc_offsets_1_eth_2_wlan_natt_common_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_TX_DESC_OFFSETS_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FC00)) >> 10);
}
__INLINE void eth2wlan_tx_desc_offsets_1_eth_2_wlan_natt_common_offset_setf(uint8_t eth2wlannattcommonoffset)
{
	ASSERT_ERR((((uint32_t)eth2wlannattcommonoffset << 10) & ~((uint32_t)0x0000FC00)) == 0);
	REG_PL_WR(ETH2WLAN_TX_DESC_OFFSETS_1_ADDR, (REG_PL_RD(ETH2WLAN_TX_DESC_OFFSETS_1_ADDR) & ~((uint32_t)0x0000FC00)) | ((uint32_t)eth2wlannattcommonoffset <<10));
}
__INLINE uint8_t eth2wlan_tx_desc_offsets_1_frame_control_seq_control_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_TX_DESC_OFFSETS_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FC)) >> 2);
}
__INLINE void eth2wlan_tx_desc_offsets_1_frame_control_seq_control_offset_setf(uint8_t framecontrolseqcontroloffset)
{
	ASSERT_ERR((((uint32_t)framecontrolseqcontroloffset << 2) & ~((uint32_t)0x000000FC)) == 0);
	REG_PL_WR(ETH2WLAN_TX_DESC_OFFSETS_1_ADDR, (REG_PL_RD(ETH2WLAN_TX_DESC_OFFSETS_1_ADDR) & ~((uint32_t)0x000000FC)) | ((uint32_t)framecontrolseqcontroloffset <<2));
}

/**
 * @brief ETH_2_WLAN_MODE register definition
 *  Defines modes of operation register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11    eth2wlan_dis_unique_tbd_pat_wr 0              
 *    10    update_cntr_dis           0              
 *    09    add_zld_field             0              
 *    08    eth2wlan_dis_uniq_pat_wr  0              
 *    04    tx_add_llc                0              
 *    02    tx_hw_trig_disable        0              
 * </pre>
 */
#define ETH2WLAN_ETH_2_WLAN_MODE_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x00000028)
#define ETH2WLAN_ETH_2_WLAN_MODE_OFFSET      0x00000028
#define ETH2WLAN_ETH_2_WLAN_MODE_INDEX       0x0000000A
#define ETH2WLAN_ETH_2_WLAN_MODE_RESET       0x00000000

__INLINE uint32_t  eth2wlan_eth_2_wlan_mode_get(void)
{
	return REG_PL_RD(ETH2WLAN_ETH_2_WLAN_MODE_ADDR);
}

__INLINE void eth2wlan_eth_2_wlan_mode_set(uint32_t value)
{
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_MODE_ADDR, value);
}

// field definitions
#define ETH2WLAN_ETH_2_WLAN_MODE_ETH_2_WLAN_DIS_UNIQUE_TBD_PAT_WR_BIT    ((uint32_t)0x00000800)
#define ETH2WLAN_ETH_2_WLAN_MODE_ETH_2_WLAN_DIS_UNIQUE_TBD_PAT_WR_POS    11
#define ETH2WLAN_ETH_2_WLAN_MODE_UPDATE_CNTR_DIS_BIT    ((uint32_t)0x00000400)
#define ETH2WLAN_ETH_2_WLAN_MODE_UPDATE_CNTR_DIS_POS    10
#define ETH2WLAN_ETH_2_WLAN_MODE_ADD_ZLD_FIELD_BIT    ((uint32_t)0x00000200)
#define ETH2WLAN_ETH_2_WLAN_MODE_ADD_ZLD_FIELD_POS    9
#define ETH2WLAN_ETH_2_WLAN_MODE_ETH_2_WLAN_DIS_UNIQ_PAT_WR_BIT    ((uint32_t)0x00000100)
#define ETH2WLAN_ETH_2_WLAN_MODE_ETH_2_WLAN_DIS_UNIQ_PAT_WR_POS    8
#define ETH2WLAN_ETH_2_WLAN_MODE_TX_ADD_LLC_BIT    ((uint32_t)0x00000010)
#define ETH2WLAN_ETH_2_WLAN_MODE_TX_ADD_LLC_POS    4
#define ETH2WLAN_ETH_2_WLAN_MODE_TX_HW_TRIG_DISABLE_BIT    ((uint32_t)0x00000004)
#define ETH2WLAN_ETH_2_WLAN_MODE_TX_HW_TRIG_DISABLE_POS    2

#define ETH2WLAN_ETH_2_WLAN_MODE_ETH_2_WLAN_DIS_UNIQUE_TBD_PAT_WR_RST    0x0
#define ETH2WLAN_ETH_2_WLAN_MODE_UPDATE_CNTR_DIS_RST    0x0
#define ETH2WLAN_ETH_2_WLAN_MODE_ADD_ZLD_FIELD_RST    0x0
#define ETH2WLAN_ETH_2_WLAN_MODE_ETH_2_WLAN_DIS_UNIQ_PAT_WR_RST    0x0
#define ETH2WLAN_ETH_2_WLAN_MODE_TX_ADD_LLC_RST    0x0
#define ETH2WLAN_ETH_2_WLAN_MODE_TX_HW_TRIG_DISABLE_RST    0x0

__INLINE void eth2wlan_eth_2_wlan_mode_pack(uint8_t eth2wlan_dis_unique_tbd_pat_wr, uint8_t update_cntr_dis, uint8_t add_zld_field, uint8_t eth2wlan_dis_uniq_pat_wr, uint8_t tx_add_llc, uint8_t tx_hw_trig_disable)
{
	ASSERT_ERR((((uint32_t)eth2wlan_dis_unique_tbd_pat_wr << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)update_cntr_dis << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)add_zld_field << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)eth2wlan_dis_uniq_pat_wr << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)tx_add_llc << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)tx_hw_trig_disable << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_MODE_ADDR,  ((uint32_t)eth2wlan_dis_unique_tbd_pat_wr << 11) |((uint32_t)update_cntr_dis << 10) |((uint32_t)add_zld_field << 9) |((uint32_t)eth2wlan_dis_uniq_pat_wr << 8) |((uint32_t)tx_add_llc << 4) |((uint32_t)tx_hw_trig_disable << 2));
}

__INLINE void eth2wlan_eth_2_wlan_mode_unpack(uint8_t* eth2wlan_dis_unique_tbd_pat_wr, uint8_t* update_cntr_dis, uint8_t* add_zld_field, uint8_t* eth2wlan_dis_uniq_pat_wr, uint8_t* tx_add_llc, uint8_t* tx_hw_trig_disable)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_ETH_2_WLAN_MODE_ADDR);

	*eth2wlan_dis_unique_tbd_pat_wr = (localVal & ((uint32_t)0x00000800)) >>  11;
	*update_cntr_dis = (localVal & ((uint32_t)0x00000400)) >>  10;
	*add_zld_field = (localVal & ((uint32_t)0x00000200)) >>  9;
	*eth2wlan_dis_uniq_pat_wr = (localVal & ((uint32_t)0x00000100)) >>  8;
	*tx_add_llc = (localVal & ((uint32_t)0x00000010)) >>  4;
	*tx_hw_trig_disable = (localVal & ((uint32_t)0x00000004)) >>  2;
}

__INLINE uint8_t eth2wlan_eth_2_wlan_mode_eth_2_wlan_dis_unique_tbd_pat_wr_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_ETH_2_WLAN_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void eth2wlan_eth_2_wlan_mode_eth_2_wlan_dis_unique_tbd_pat_wr_setf(uint8_t eth2wlandisuniquetbdpatwr)
{
	ASSERT_ERR((((uint32_t)eth2wlandisuniquetbdpatwr << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_MODE_ADDR, (REG_PL_RD(ETH2WLAN_ETH_2_WLAN_MODE_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)eth2wlandisuniquetbdpatwr <<11));
}
__INLINE uint8_t eth2wlan_eth_2_wlan_mode_update_cntr_dis_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_ETH_2_WLAN_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void eth2wlan_eth_2_wlan_mode_update_cntr_dis_setf(uint8_t updatecntrdis)
{
	ASSERT_ERR((((uint32_t)updatecntrdis << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_MODE_ADDR, (REG_PL_RD(ETH2WLAN_ETH_2_WLAN_MODE_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)updatecntrdis <<10));
}
__INLINE uint8_t eth2wlan_eth_2_wlan_mode_add_zld_field_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_ETH_2_WLAN_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void eth2wlan_eth_2_wlan_mode_add_zld_field_setf(uint8_t addzldfield)
{
	ASSERT_ERR((((uint32_t)addzldfield << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_MODE_ADDR, (REG_PL_RD(ETH2WLAN_ETH_2_WLAN_MODE_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)addzldfield <<9));
}
__INLINE uint8_t eth2wlan_eth_2_wlan_mode_eth_2_wlan_dis_uniq_pat_wr_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_ETH_2_WLAN_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void eth2wlan_eth_2_wlan_mode_eth_2_wlan_dis_uniq_pat_wr_setf(uint8_t eth2wlandisuniqpatwr)
{
	ASSERT_ERR((((uint32_t)eth2wlandisuniqpatwr << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_MODE_ADDR, (REG_PL_RD(ETH2WLAN_ETH_2_WLAN_MODE_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)eth2wlandisuniqpatwr <<8));
}
__INLINE uint8_t eth2wlan_eth_2_wlan_mode_tx_add_llc_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_ETH_2_WLAN_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void eth2wlan_eth_2_wlan_mode_tx_add_llc_setf(uint8_t txaddllc)
{
	ASSERT_ERR((((uint32_t)txaddllc << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_MODE_ADDR, (REG_PL_RD(ETH2WLAN_ETH_2_WLAN_MODE_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)txaddllc <<4));
}
__INLINE uint8_t eth2wlan_eth_2_wlan_mode_tx_hw_trig_disable_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_ETH_2_WLAN_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void eth2wlan_eth_2_wlan_mode_tx_hw_trig_disable_setf(uint8_t txhwtrigdisable)
{
	ASSERT_ERR((((uint32_t)txhwtrigdisable << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_MODE_ADDR, (REG_PL_RD(ETH2WLAN_ETH_2_WLAN_MODE_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)txhwtrigdisable <<2));
}

/**
 * @brief BAND_0_VIF_TABLE_BASE register definition
 *  base address for VIF table register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 vif_table_base            0x0
 * </pre>
 */
#define ETH2WLAN_BAND_0_VIF_TABLE_BASE_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x0000002C)
#define ETH2WLAN_BAND_0_VIF_TABLE_BASE_OFFSET      0x0000002C
#define ETH2WLAN_BAND_0_VIF_TABLE_BASE_INDEX       0x0000000B
#define ETH2WLAN_BAND_0_VIF_TABLE_BASE_RESET       0x00000000

__INLINE uint32_t  eth2wlan_band_0_vif_table_base_get(void)
{
	return REG_PL_RD(ETH2WLAN_BAND_0_VIF_TABLE_BASE_ADDR);
}

__INLINE void eth2wlan_band_0_vif_table_base_set(uint32_t value)
{
	REG_PL_WR(ETH2WLAN_BAND_0_VIF_TABLE_BASE_ADDR, value);
}

// field definitions
#define ETH2WLAN_BAND_0_VIF_TABLE_BASE_VIF_TABLE_BASE_MASK    ((uint32_t)0xFFFFFFFC)
#define ETH2WLAN_BAND_0_VIF_TABLE_BASE_VIF_TABLE_BASE_LSB    2
#define ETH2WLAN_BAND_0_VIF_TABLE_BASE_VIF_TABLE_BASE_WIDTH    ((uint32_t)0x0000001E)

#define ETH2WLAN_BAND_0_VIF_TABLE_BASE_VIF_TABLE_BASE_RST    0x0

__INLINE uint32_t eth2wlan_band_0_vif_table_base_vif_table_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_BAND_0_VIF_TABLE_BASE_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void eth2wlan_band_0_vif_table_base_vif_table_base_setf(uint32_t viftablebase)
{
	ASSERT_ERR((((uint32_t)viftablebase << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(ETH2WLAN_BAND_0_VIF_TABLE_BASE_ADDR, (uint32_t)viftablebase << 2);
}

/**
 * @brief AMSDU_SUB_PARAM_OFFSET register definition
 *  Offset to the AMSDU sub frame payload register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 amsdu_payload_offset      0x0
 * </pre>
 */
#define ETH2WLAN_AMSDU_SUB_PARAM_OFFSET_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x00000030)
#define ETH2WLAN_AMSDU_SUB_PARAM_OFFSET_OFFSET      0x00000030
#define ETH2WLAN_AMSDU_SUB_PARAM_OFFSET_INDEX       0x0000000C
#define ETH2WLAN_AMSDU_SUB_PARAM_OFFSET_RESET       0x00000000

__INLINE uint32_t  eth2wlan_amsdu_sub_param_offset_get(void)
{
	return REG_PL_RD(ETH2WLAN_AMSDU_SUB_PARAM_OFFSET_ADDR);
}

__INLINE void eth2wlan_amsdu_sub_param_offset_set(uint32_t value)
{
	REG_PL_WR(ETH2WLAN_AMSDU_SUB_PARAM_OFFSET_ADDR, value);
}

// field definitions
#define ETH2WLAN_AMSDU_SUB_PARAM_OFFSET_AMSDU_PAYLOAD_OFFSET_MASK    ((uint32_t)0x000000FF)
#define ETH2WLAN_AMSDU_SUB_PARAM_OFFSET_AMSDU_PAYLOAD_OFFSET_LSB    0
#define ETH2WLAN_AMSDU_SUB_PARAM_OFFSET_AMSDU_PAYLOAD_OFFSET_WIDTH    ((uint32_t)0x00000008)

#define ETH2WLAN_AMSDU_SUB_PARAM_OFFSET_AMSDU_PAYLOAD_OFFSET_RST    0x0

__INLINE uint8_t eth2wlan_amsdu_sub_param_offset_amsdu_payload_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_AMSDU_SUB_PARAM_OFFSET_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void eth2wlan_amsdu_sub_param_offset_amsdu_payload_offset_setf(uint8_t amsdupayloadoffset)
{
	ASSERT_ERR((((uint32_t)amsdupayloadoffset << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(ETH2WLAN_AMSDU_SUB_PARAM_OFFSET_ADDR, (uint32_t)amsdupayloadoffset << 0);
}

/**
 * @brief TX_DESC_OFFSETS_2 register definition
 *  Offset of packet parameters written in Tx Descript register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:02 NATT_RESULT_OFFSET        0x0
 * </pre>
 */
#define ETH2WLAN_TX_DESC_OFFSETS_2_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x00000034)
#define ETH2WLAN_TX_DESC_OFFSETS_2_OFFSET      0x00000034
#define ETH2WLAN_TX_DESC_OFFSETS_2_INDEX       0x0000000D
#define ETH2WLAN_TX_DESC_OFFSETS_2_RESET       0x00000000

__INLINE uint32_t  eth2wlan_tx_desc_offsets_2_get(void)
{
	return REG_PL_RD(ETH2WLAN_TX_DESC_OFFSETS_2_ADDR);
}

__INLINE void eth2wlan_tx_desc_offsets_2_set(uint32_t value)
{
	REG_PL_WR(ETH2WLAN_TX_DESC_OFFSETS_2_ADDR, value);
}

// field definitions
#define ETH2WLAN_TX_DESC_OFFSETS_2_NATT_RESULT_OFFSET_MASK    ((uint32_t)0x000000FC)
#define ETH2WLAN_TX_DESC_OFFSETS_2_NATT_RESULT_OFFSET_LSB    2
#define ETH2WLAN_TX_DESC_OFFSETS_2_NATT_RESULT_OFFSET_WIDTH    ((uint32_t)0x00000006)

#define ETH2WLAN_TX_DESC_OFFSETS_2_NATT_RESULT_OFFSET_RST    0x0

__INLINE uint8_t eth2wlan_tx_desc_offsets_2_natt_result_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_TX_DESC_OFFSETS_2_ADDR);
	return (uint8_t)(localVal >> 2);
}
__INLINE void eth2wlan_tx_desc_offsets_2_natt_result_offset_setf(uint8_t nattresultoffset)
{
	ASSERT_ERR((((uint32_t)nattresultoffset << 2) & ~((uint32_t)0x000000FC)) == 0);
	REG_PL_WR(ETH2WLAN_TX_DESC_OFFSETS_2_ADDR, (uint32_t)nattresultoffset << 2);
}

/**
 * @brief ETH_2_WLAN_COMMAND register definition
 *  Command to ETH2WLAN register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    05:04 AMSDU                     0x0
 *    00    tx_conv                   0              
 * </pre>
 */
#define ETH2WLAN_ETH_2_WLAN_COMMAND_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x00000040)
#define ETH2WLAN_ETH_2_WLAN_COMMAND_OFFSET      0x00000040
#define ETH2WLAN_ETH_2_WLAN_COMMAND_INDEX       0x00000010
#define ETH2WLAN_ETH_2_WLAN_COMMAND_RESET       0x00000000

__INLINE uint32_t  eth2wlan_eth_2_wlan_command_get(void)
{
	return REG_PL_RD(ETH2WLAN_ETH_2_WLAN_COMMAND_ADDR);
}

__INLINE void eth2wlan_eth_2_wlan_command_set(uint32_t value)
{
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_COMMAND_ADDR, value);
}

// field definitions
#define ETH2WLAN_ETH_2_WLAN_COMMAND_AMSDU_MASK    ((uint32_t)0x00000030)
#define ETH2WLAN_ETH_2_WLAN_COMMAND_AMSDU_LSB    4
#define ETH2WLAN_ETH_2_WLAN_COMMAND_AMSDU_WIDTH    ((uint32_t)0x00000002)
#define ETH2WLAN_ETH_2_WLAN_COMMAND_TX_CONV_BIT    ((uint32_t)0x00000001)
#define ETH2WLAN_ETH_2_WLAN_COMMAND_TX_CONV_POS    0

#define ETH2WLAN_ETH_2_WLAN_COMMAND_AMSDU_RST    0x0
#define ETH2WLAN_ETH_2_WLAN_COMMAND_TX_CONV_RST    0x0

__INLINE void eth2wlan_eth_2_wlan_command_pack(uint8_t amsdu, uint8_t tx_conv)
{
	ASSERT_ERR((((uint32_t)amsdu << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)tx_conv << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_COMMAND_ADDR,  ((uint32_t)amsdu << 4) |((uint32_t)tx_conv << 0));
}

__INLINE void eth2wlan_eth_2_wlan_command_unpack(uint8_t* amsdu, uint8_t* tx_conv)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_ETH_2_WLAN_COMMAND_ADDR);

	*amsdu = (localVal & ((uint32_t)0x00000030)) >>  4;
	*tx_conv = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t eth2wlan_eth_2_wlan_command_amsdu_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_ETH_2_WLAN_COMMAND_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void eth2wlan_eth_2_wlan_command_amsdu_setf(uint8_t amsdu)
{
	ASSERT_ERR((((uint32_t)amsdu << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_COMMAND_ADDR, (REG_PL_RD(ETH2WLAN_ETH_2_WLAN_COMMAND_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)amsdu <<4));
}
__INLINE uint8_t eth2wlan_eth_2_wlan_command_tx_conv_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_ETH_2_WLAN_COMMAND_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void eth2wlan_eth_2_wlan_command_tx_conv_setf(uint8_t txconv)
{
	ASSERT_ERR((((uint32_t)txconv << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_COMMAND_ADDR, (REG_PL_RD(ETH2WLAN_ETH_2_WLAN_COMMAND_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)txconv <<0));
}

/**
 * @brief ETH_2_WLAN_STATUS register definition
 *  Status of ETH2WLAN register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    08    eth2wlan_busy             0              
 *    00    eth2wlan_tx_done          0              
 * </pre>
 */
#define ETH2WLAN_ETH_2_WLAN_STATUS_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x00000044)
#define ETH2WLAN_ETH_2_WLAN_STATUS_OFFSET      0x00000044
#define ETH2WLAN_ETH_2_WLAN_STATUS_INDEX       0x00000011
#define ETH2WLAN_ETH_2_WLAN_STATUS_RESET       0x00000000

__INLINE uint32_t  eth2wlan_eth_2_wlan_status_get(void)
{
	return REG_PL_RD(ETH2WLAN_ETH_2_WLAN_STATUS_ADDR);
}

// field definitions
#define ETH2WLAN_ETH_2_WLAN_STATUS_ETH_2_WLAN_BUSY_BIT    ((uint32_t)0x00000100)
#define ETH2WLAN_ETH_2_WLAN_STATUS_ETH_2_WLAN_BUSY_POS    8
#define ETH2WLAN_ETH_2_WLAN_STATUS_ETH_2_WLAN_TX_DONE_BIT    ((uint32_t)0x00000001)
#define ETH2WLAN_ETH_2_WLAN_STATUS_ETH_2_WLAN_TX_DONE_POS    0

#define ETH2WLAN_ETH_2_WLAN_STATUS_ETH_2_WLAN_BUSY_RST    0x0
#define ETH2WLAN_ETH_2_WLAN_STATUS_ETH_2_WLAN_TX_DONE_RST    0x0

__INLINE void eth2wlan_eth_2_wlan_status_unpack(uint8_t* eth2wlan_busy, uint8_t* eth2wlan_tx_done)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_ETH_2_WLAN_STATUS_ADDR);

	*eth2wlan_busy = (localVal & ((uint32_t)0x00000100)) >>  8;
	*eth2wlan_tx_done = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t eth2wlan_eth_2_wlan_status_eth_2_wlan_busy_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_ETH_2_WLAN_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE uint8_t eth2wlan_eth_2_wlan_status_eth_2_wlan_tx_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_ETH_2_WLAN_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief ETH_2_WLAN_STATUS_CLR register definition
 *  Clear ETH2WLAN status register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    eth2wlan_tx_int_clr       0              
 * </pre>
 */
#define ETH2WLAN_ETH_2_WLAN_STATUS_CLR_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x00000048)
#define ETH2WLAN_ETH_2_WLAN_STATUS_CLR_OFFSET      0x00000048
#define ETH2WLAN_ETH_2_WLAN_STATUS_CLR_INDEX       0x00000012
#define ETH2WLAN_ETH_2_WLAN_STATUS_CLR_RESET       0x00000000

__INLINE uint32_t  eth2wlan_eth_2_wlan_status_clr_get(void)
{
	return REG_PL_RD(ETH2WLAN_ETH_2_WLAN_STATUS_CLR_ADDR);
}

__INLINE void eth2wlan_eth_2_wlan_status_clr_set(uint32_t value)
{
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_STATUS_CLR_ADDR, value);
}

// field definitions
#define ETH2WLAN_ETH_2_WLAN_STATUS_CLR_ETH_2_WLAN_TX_INT_CLR_BIT    ((uint32_t)0x00000001)
#define ETH2WLAN_ETH_2_WLAN_STATUS_CLR_ETH_2_WLAN_TX_INT_CLR_POS    0

#define ETH2WLAN_ETH_2_WLAN_STATUS_CLR_ETH_2_WLAN_TX_INT_CLR_RST    0x0

__INLINE uint8_t eth2wlan_eth_2_wlan_status_clr_eth_2_wlan_tx_int_clr_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_ETH_2_WLAN_STATUS_CLR_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void eth2wlan_eth_2_wlan_status_clr_eth_2_wlan_tx_int_clr_setf(uint8_t eth2wlantxintclr)
{
	ASSERT_ERR((((uint32_t)eth2wlantxintclr << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(ETH2WLAN_ETH_2_WLAN_STATUS_CLR_ADDR, (uint32_t)eth2wlantxintclr << 0);
}

/**
 * @brief WAPI_PN_MOST_0 register definition
 *  Byte 10 to 7 of WAPI PN register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 WAPI_PN_HIGH_LOW          0x0
 * </pre>
 */
#define ETH2WLAN_WAPI_PN_MOST_0_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x00000050)
#define ETH2WLAN_WAPI_PN_MOST_0_OFFSET      0x00000050
#define ETH2WLAN_WAPI_PN_MOST_0_INDEX       0x00000014
#define ETH2WLAN_WAPI_PN_MOST_0_RESET       0x00000000

__INLINE uint32_t  eth2wlan_wapi_pn_most_0_get(void)
{
	return REG_PL_RD(ETH2WLAN_WAPI_PN_MOST_0_ADDR);
}

__INLINE void eth2wlan_wapi_pn_most_0_set(uint32_t value)
{
	REG_PL_WR(ETH2WLAN_WAPI_PN_MOST_0_ADDR, value);
}

// field definitions
#define ETH2WLAN_WAPI_PN_MOST_0_WAPI_PN_HIGH_LOW_MASK    ((uint32_t)0xFFFFFFFF)
#define ETH2WLAN_WAPI_PN_MOST_0_WAPI_PN_HIGH_LOW_LSB    0
#define ETH2WLAN_WAPI_PN_MOST_0_WAPI_PN_HIGH_LOW_WIDTH    ((uint32_t)0x00000020)

#define ETH2WLAN_WAPI_PN_MOST_0_WAPI_PN_HIGH_LOW_RST    0x0

__INLINE uint32_t eth2wlan_wapi_pn_most_0_wapi_pn_high_low_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_WAPI_PN_MOST_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void eth2wlan_wapi_pn_most_0_wapi_pn_high_low_setf(uint32_t wapipnhighlow)
{
	ASSERT_ERR((((uint32_t)wapipnhighlow << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(ETH2WLAN_WAPI_PN_MOST_0_ADDR, (uint32_t)wapipnhighlow << 0);
}

/**
 * @brief WAPI_PN_MOST_1 register definition
 *  Byte 14 to 11 of WAPI PN register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 WAPI_PN_HIGH_MID          0x0
 * </pre>
 */
#define ETH2WLAN_WAPI_PN_MOST_1_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x00000054)
#define ETH2WLAN_WAPI_PN_MOST_1_OFFSET      0x00000054
#define ETH2WLAN_WAPI_PN_MOST_1_INDEX       0x00000015
#define ETH2WLAN_WAPI_PN_MOST_1_RESET       0x00000000

__INLINE uint32_t  eth2wlan_wapi_pn_most_1_get(void)
{
	return REG_PL_RD(ETH2WLAN_WAPI_PN_MOST_1_ADDR);
}

__INLINE void eth2wlan_wapi_pn_most_1_set(uint32_t value)
{
	REG_PL_WR(ETH2WLAN_WAPI_PN_MOST_1_ADDR, value);
}

// field definitions
#define ETH2WLAN_WAPI_PN_MOST_1_WAPI_PN_HIGH_MID_MASK    ((uint32_t)0xFFFFFFFF)
#define ETH2WLAN_WAPI_PN_MOST_1_WAPI_PN_HIGH_MID_LSB    0
#define ETH2WLAN_WAPI_PN_MOST_1_WAPI_PN_HIGH_MID_WIDTH    ((uint32_t)0x00000020)

#define ETH2WLAN_WAPI_PN_MOST_1_WAPI_PN_HIGH_MID_RST    0x0

__INLINE uint32_t eth2wlan_wapi_pn_most_1_wapi_pn_high_mid_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_WAPI_PN_MOST_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void eth2wlan_wapi_pn_most_1_wapi_pn_high_mid_setf(uint32_t wapipnhighmid)
{
	ASSERT_ERR((((uint32_t)wapipnhighmid << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(ETH2WLAN_WAPI_PN_MOST_1_ADDR, (uint32_t)wapipnhighmid << 0);
}

/**
 * @brief WAPI_PN_MOST_2 register definition
 *  Byte 16 to 15 of WAPI PN register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 WAPI_PN_HIGH_HIGH         0x0
 * </pre>
 */
#define ETH2WLAN_WAPI_PN_MOST_2_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x00000058)
#define ETH2WLAN_WAPI_PN_MOST_2_OFFSET      0x00000058
#define ETH2WLAN_WAPI_PN_MOST_2_INDEX       0x00000016
#define ETH2WLAN_WAPI_PN_MOST_2_RESET       0x00000000

__INLINE uint32_t  eth2wlan_wapi_pn_most_2_get(void)
{
	return REG_PL_RD(ETH2WLAN_WAPI_PN_MOST_2_ADDR);
}

__INLINE void eth2wlan_wapi_pn_most_2_set(uint32_t value)
{
	REG_PL_WR(ETH2WLAN_WAPI_PN_MOST_2_ADDR, value);
}

// field definitions
#define ETH2WLAN_WAPI_PN_MOST_2_WAPI_PN_HIGH_HIGH_MASK    ((uint32_t)0x0000FFFF)
#define ETH2WLAN_WAPI_PN_MOST_2_WAPI_PN_HIGH_HIGH_LSB    0
#define ETH2WLAN_WAPI_PN_MOST_2_WAPI_PN_HIGH_HIGH_WIDTH    ((uint32_t)0x00000010)

#define ETH2WLAN_WAPI_PN_MOST_2_WAPI_PN_HIGH_HIGH_RST    0x0

__INLINE uint16_t eth2wlan_wapi_pn_most_2_wapi_pn_high_high_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_WAPI_PN_MOST_2_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void eth2wlan_wapi_pn_most_2_wapi_pn_high_high_setf(uint16_t wapipnhighhigh)
{
	ASSERT_ERR((((uint32_t)wapipnhighhigh << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(ETH2WLAN_WAPI_PN_MOST_2_ADDR, (uint32_t)wapipnhighhigh << 0);
}

/**
 * @brief CUR_TX_BASE register definition
 *  Current Tx buffer base address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 cur_tx_base               0x0
 * </pre>
 */
#define ETH2WLAN_CUR_TX_BASE_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x00000080)
#define ETH2WLAN_CUR_TX_BASE_OFFSET      0x00000080
#define ETH2WLAN_CUR_TX_BASE_INDEX       0x00000020
#define ETH2WLAN_CUR_TX_BASE_RESET       0x00000000

__INLINE uint32_t  eth2wlan_cur_tx_base_get(void)
{
	return REG_PL_RD(ETH2WLAN_CUR_TX_BASE_ADDR);
}

// field definitions
#define ETH2WLAN_CUR_TX_BASE_CUR_TX_BASE_MASK    ((uint32_t)0xFFFFFFFF)
#define ETH2WLAN_CUR_TX_BASE_CUR_TX_BASE_LSB    0
#define ETH2WLAN_CUR_TX_BASE_CUR_TX_BASE_WIDTH    ((uint32_t)0x00000020)

#define ETH2WLAN_CUR_TX_BASE_CUR_TX_BASE_RST    0x0

__INLINE uint32_t eth2wlan_cur_tx_base_cur_tx_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_CUR_TX_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief CUR_THD_BASE register definition
 *  Current Transmit Header Descriptor base address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 cur_thd_base              0x0
 * </pre>
 */
#define ETH2WLAN_CUR_THD_BASE_ADDR        (REG_ETH2WLAN_BASE_ADDR+0x00000084)
#define ETH2WLAN_CUR_THD_BASE_OFFSET      0x00000084
#define ETH2WLAN_CUR_THD_BASE_INDEX       0x00000021
#define ETH2WLAN_CUR_THD_BASE_RESET       0x00000000

__INLINE uint32_t  eth2wlan_cur_thd_base_get(void)
{
	return REG_PL_RD(ETH2WLAN_CUR_THD_BASE_ADDR);
}

// field definitions
#define ETH2WLAN_CUR_THD_BASE_CUR_THD_BASE_MASK    ((uint32_t)0xFFFFFFFF)
#define ETH2WLAN_CUR_THD_BASE_CUR_THD_BASE_LSB    0
#define ETH2WLAN_CUR_THD_BASE_CUR_THD_BASE_WIDTH    ((uint32_t)0x00000020)

#define ETH2WLAN_CUR_THD_BASE_CUR_THD_BASE_RST    0x0

__INLINE uint32_t eth2wlan_cur_thd_base_cur_thd_base_getf(void)
{
	uint32_t localVal = REG_PL_RD(ETH2WLAN_CUR_THD_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}


#undef DBG_FILEID
#endif //_REG_ETH2WLAN_H_
