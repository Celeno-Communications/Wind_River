#ifndef _REG_SPU_H_
#define _REG_SPU_H_

#include <stdint.h>
#include "phy/_reg_spu.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_SPU__H__FILEID__

#define REG_SPU_COUNT  130


/**
 * @brief STATIC_CONF_0 register definition
 *  Common config register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:22 TX_SEG_SIZE               0x0
 *    20    START_RU_INDEXING         0              
 *    18    HELTF_2_BIT_MODE          0              
 *    17    DBG_MODE                  0              
 *    16    LUT_INIT_REQ              0              
 *    15    FIC_ISOBAR_ON             0              
 *    14    MCCI_DBG_MASK             0              
 *    12:10 MCCI_ERR_MASK             0x0
 *    09:05 MCCI_ERR_PTR              0x0
 *    04:00 MCCI_DBG_PTR              0x0
 * </pre>
 */
#define SPU_STATIC_CONF_0_ADDR        (REG_SPU_BASE_ADDR+0x00000000)
#define SPU_STATIC_CONF_0_OFFSET      0x00000000
#define SPU_STATIC_CONF_0_INDEX       0x00000000
#define SPU_STATIC_CONF_0_RESET       0x00000000

__INLINE uint32_t  spu_static_conf_0_get(void)
{
	return REG_PL_RD(SPU_STATIC_CONF_0_ADDR);
}

__INLINE void spu_static_conf_0_set(uint32_t value)
{
	REG_PL_WR(SPU_STATIC_CONF_0_ADDR, value);
}

// field definitions
#define SPU_STATIC_CONF_0_TX_SEG_SIZE_MASK    ((uint32_t)0x7FC00000)
#define SPU_STATIC_CONF_0_TX_SEG_SIZE_LSB    22
#define SPU_STATIC_CONF_0_TX_SEG_SIZE_WIDTH    ((uint32_t)0x00000009)
#define SPU_STATIC_CONF_0_START_RU_INDEXING_BIT    ((uint32_t)0x00100000)
#define SPU_STATIC_CONF_0_START_RU_INDEXING_POS    20
#define SPU_STATIC_CONF_0_HELTF_2_BIT_MODE_BIT    ((uint32_t)0x00040000)
#define SPU_STATIC_CONF_0_HELTF_2_BIT_MODE_POS    18
#define SPU_STATIC_CONF_0_DBG_MODE_BIT      ((uint32_t)0x00020000)
#define SPU_STATIC_CONF_0_DBG_MODE_POS      17
#define SPU_STATIC_CONF_0_LUT_INIT_REQ_BIT    ((uint32_t)0x00010000)
#define SPU_STATIC_CONF_0_LUT_INIT_REQ_POS    16
#define SPU_STATIC_CONF_0_FIC_ISOBAR_ON_BIT    ((uint32_t)0x00008000)
#define SPU_STATIC_CONF_0_FIC_ISOBAR_ON_POS    15
#define SPU_STATIC_CONF_0_MCCI_DBG_MASK_BIT    ((uint32_t)0x00004000)
#define SPU_STATIC_CONF_0_MCCI_DBG_MASK_POS    14
#define SPU_STATIC_CONF_0_MCCI_ERR_MASK_MASK    ((uint32_t)0x00001C00)
#define SPU_STATIC_CONF_0_MCCI_ERR_MASK_LSB    10
#define SPU_STATIC_CONF_0_MCCI_ERR_MASK_WIDTH    ((uint32_t)0x00000003)
#define SPU_STATIC_CONF_0_MCCI_ERR_PTR_MASK    ((uint32_t)0x000003E0)
#define SPU_STATIC_CONF_0_MCCI_ERR_PTR_LSB    5
#define SPU_STATIC_CONF_0_MCCI_ERR_PTR_WIDTH    ((uint32_t)0x00000005)
#define SPU_STATIC_CONF_0_MCCI_DBG_PTR_MASK    ((uint32_t)0x0000001F)
#define SPU_STATIC_CONF_0_MCCI_DBG_PTR_LSB    0
#define SPU_STATIC_CONF_0_MCCI_DBG_PTR_WIDTH    ((uint32_t)0x00000005)

#define SPU_STATIC_CONF_0_TX_SEG_SIZE_RST    0x0
#define SPU_STATIC_CONF_0_START_RU_INDEXING_RST    0x0
#define SPU_STATIC_CONF_0_HELTF_2_BIT_MODE_RST    0x0
#define SPU_STATIC_CONF_0_DBG_MODE_RST      0x0
#define SPU_STATIC_CONF_0_LUT_INIT_REQ_RST    0x0
#define SPU_STATIC_CONF_0_FIC_ISOBAR_ON_RST    0x0
#define SPU_STATIC_CONF_0_MCCI_DBG_MASK_RST    0x0
#define SPU_STATIC_CONF_0_MCCI_ERR_MASK_RST    0x0
#define SPU_STATIC_CONF_0_MCCI_ERR_PTR_RST    0x0
#define SPU_STATIC_CONF_0_MCCI_DBG_PTR_RST    0x0

__INLINE void spu_static_conf_0_pack(uint16_t tx_seg_size, uint8_t start_ru_indexing, uint8_t heltf_2_bit_mode, uint8_t dbg_mode, uint8_t lut_init_req, uint8_t fic_isobar_on, uint8_t mcci_dbg_mask, uint8_t mcci_err_mask, uint8_t mcci_err_ptr, uint8_t mcci_dbg_ptr)
{
	ASSERT_ERR((((uint32_t)tx_seg_size << 22) & ~((uint32_t)0x7FC00000)) == 0);
	ASSERT_ERR((((uint32_t)start_ru_indexing << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)heltf_2_bit_mode << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)dbg_mode << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)lut_init_req << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)fic_isobar_on << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)mcci_dbg_mask << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)mcci_err_mask << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)mcci_err_ptr << 5) & ~((uint32_t)0x000003E0)) == 0);
	ASSERT_ERR((((uint32_t)mcci_dbg_ptr << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_0_ADDR,  ((uint32_t)tx_seg_size << 22) |((uint32_t)start_ru_indexing << 20) |((uint32_t)heltf_2_bit_mode << 18) |((uint32_t)dbg_mode << 17) |((uint32_t)lut_init_req << 16) |((uint32_t)fic_isobar_on << 15) |((uint32_t)mcci_dbg_mask << 14) |((uint32_t)mcci_err_mask << 10) |((uint32_t)mcci_err_ptr << 5) |((uint32_t)mcci_dbg_ptr << 0));
}

__INLINE void spu_static_conf_0_unpack(uint16_t* tx_seg_size, uint8_t* start_ru_indexing, uint8_t* heltf_2_bit_mode, uint8_t* dbg_mode, uint8_t* lut_init_req, uint8_t* fic_isobar_on, uint8_t* mcci_dbg_mask, uint8_t* mcci_err_mask, uint8_t* mcci_err_ptr, uint8_t* mcci_dbg_ptr)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_0_ADDR);

	*tx_seg_size = (localVal & ((uint32_t)0x7FC00000)) >>  22;
	*start_ru_indexing = (localVal & ((uint32_t)0x00100000)) >>  20;
	*heltf_2_bit_mode = (localVal & ((uint32_t)0x00040000)) >>  18;
	*dbg_mode = (localVal & ((uint32_t)0x00020000)) >>  17;
	*lut_init_req = (localVal & ((uint32_t)0x00010000)) >>  16;
	*fic_isobar_on = (localVal & ((uint32_t)0x00008000)) >>  15;
	*mcci_dbg_mask = (localVal & ((uint32_t)0x00004000)) >>  14;
	*mcci_err_mask = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*mcci_err_ptr = (localVal & ((uint32_t)0x000003E0)) >>  5;
	*mcci_dbg_ptr = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint16_t spu_static_conf_0_tx_seg_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x7FC00000)) >> 22);
}
__INLINE void spu_static_conf_0_tx_seg_size_setf(uint16_t txsegsize)
{
	ASSERT_ERR((((uint32_t)txsegsize << 22) & ~((uint32_t)0x7FC00000)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_0_ADDR, (REG_PL_RD(SPU_STATIC_CONF_0_ADDR) & ~((uint32_t)0x7FC00000)) | ((uint32_t)txsegsize <<22));
}
__INLINE uint8_t spu_static_conf_0_start_ru_indexing_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE void spu_static_conf_0_start_ru_indexing_setf(uint8_t startruindexing)
{
	ASSERT_ERR((((uint32_t)startruindexing << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_0_ADDR, (REG_PL_RD(SPU_STATIC_CONF_0_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)startruindexing <<20));
}
__INLINE uint8_t spu_static_conf_0_heltf_2_bit_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void spu_static_conf_0_heltf_2_bit_mode_setf(uint8_t heltf2bitmode)
{
	ASSERT_ERR((((uint32_t)heltf2bitmode << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_0_ADDR, (REG_PL_RD(SPU_STATIC_CONF_0_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)heltf2bitmode <<18));
}
__INLINE uint8_t spu_static_conf_0_dbg_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void spu_static_conf_0_dbg_mode_setf(uint8_t dbgmode)
{
	ASSERT_ERR((((uint32_t)dbgmode << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_0_ADDR, (REG_PL_RD(SPU_STATIC_CONF_0_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)dbgmode <<17));
}
__INLINE uint8_t spu_static_conf_0_lut_init_req_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void spu_static_conf_0_lut_init_req_setf(uint8_t lutinitreq)
{
	ASSERT_ERR((((uint32_t)lutinitreq << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_0_ADDR, (REG_PL_RD(SPU_STATIC_CONF_0_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)lutinitreq <<16));
}
__INLINE uint8_t spu_static_conf_0_fic_isobar_on_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void spu_static_conf_0_fic_isobar_on_setf(uint8_t ficisobaron)
{
	ASSERT_ERR((((uint32_t)ficisobaron << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_0_ADDR, (REG_PL_RD(SPU_STATIC_CONF_0_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)ficisobaron <<15));
}
__INLINE uint8_t spu_static_conf_0_mcci_dbg_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void spu_static_conf_0_mcci_dbg_mask_setf(uint8_t mccidbgmask)
{
	ASSERT_ERR((((uint32_t)mccidbgmask << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_0_ADDR, (REG_PL_RD(SPU_STATIC_CONF_0_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)mccidbgmask <<14));
}
__INLINE uint8_t spu_static_conf_0_mcci_err_mask_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void spu_static_conf_0_mcci_err_mask_setf(uint8_t mccierrmask)
{
	ASSERT_ERR((((uint32_t)mccierrmask << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_0_ADDR, (REG_PL_RD(SPU_STATIC_CONF_0_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)mccierrmask <<10));
}
__INLINE uint8_t spu_static_conf_0_mcci_err_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003E0)) >> 5);
}
__INLINE void spu_static_conf_0_mcci_err_ptr_setf(uint8_t mccierrptr)
{
	ASSERT_ERR((((uint32_t)mccierrptr << 5) & ~((uint32_t)0x000003E0)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_0_ADDR, (REG_PL_RD(SPU_STATIC_CONF_0_ADDR) & ~((uint32_t)0x000003E0)) | ((uint32_t)mccierrptr <<5));
}
__INLINE uint8_t spu_static_conf_0_mcci_dbg_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void spu_static_conf_0_mcci_dbg_ptr_setf(uint8_t mccidbgptr)
{
	ASSERT_ERR((((uint32_t)mccidbgptr << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_0_ADDR, (REG_PL_RD(SPU_STATIC_CONF_0_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)mccidbgptr <<0));
}

/**
 * @brief STATIC_CONF_1 register definition
 *  Common config register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:28 NRX                       0x0
 *    27:26 CSD_LUT_SCALE             0x0
 *    25    HE_SU_NDP                 0              
 *    24    HELTF_MASKING             0              
 *    23    PILOTS_MASKED             0              
 *    22:21 HELTF_TYPE                0x0
 *    20:18 HELTF_NUM                 0x0
 *    17:13 HESIGB_NUM                0x0
 *    12:10 HESIGA_NUM                0x0
 *    09:08 HE_FORMAT                 0x0
 *    07:06 BW                        0x0
 *    05:03 NTX                       0x0
 *    02    MAPPER_EN                 0              
 *    01    TX_EN                     0              
 *    00    RX_EN                     0              
 * </pre>
 */
#define SPU_STATIC_CONF_1_ADDR        (REG_SPU_BASE_ADDR+0x00000004)
#define SPU_STATIC_CONF_1_OFFSET      0x00000004
#define SPU_STATIC_CONF_1_INDEX       0x00000001
#define SPU_STATIC_CONF_1_RESET       0x00000000

__INLINE uint32_t  spu_static_conf_1_get(void)
{
	return REG_PL_RD(SPU_STATIC_CONF_1_ADDR);
}

__INLINE void spu_static_conf_1_set(uint32_t value)
{
	REG_PL_WR(SPU_STATIC_CONF_1_ADDR, value);
}

// field definitions
#define SPU_STATIC_CONF_1_NRX_MASK          ((uint32_t)0x70000000)
#define SPU_STATIC_CONF_1_NRX_LSB           28
#define SPU_STATIC_CONF_1_NRX_WIDTH         ((uint32_t)0x00000003)
#define SPU_STATIC_CONF_1_CSD_LUT_SCALE_MASK    ((uint32_t)0x0C000000)
#define SPU_STATIC_CONF_1_CSD_LUT_SCALE_LSB    26
#define SPU_STATIC_CONF_1_CSD_LUT_SCALE_WIDTH    ((uint32_t)0x00000002)
#define SPU_STATIC_CONF_1_HE_SU_NDP_BIT     ((uint32_t)0x02000000)
#define SPU_STATIC_CONF_1_HE_SU_NDP_POS     25
#define SPU_STATIC_CONF_1_HELTF_MASKING_BIT    ((uint32_t)0x01000000)
#define SPU_STATIC_CONF_1_HELTF_MASKING_POS    24
#define SPU_STATIC_CONF_1_PILOTS_MASKED_BIT    ((uint32_t)0x00800000)
#define SPU_STATIC_CONF_1_PILOTS_MASKED_POS    23
#define SPU_STATIC_CONF_1_HELTF_TYPE_MASK    ((uint32_t)0x00600000)
#define SPU_STATIC_CONF_1_HELTF_TYPE_LSB    21
#define SPU_STATIC_CONF_1_HELTF_TYPE_WIDTH    ((uint32_t)0x00000002)
#define SPU_STATIC_CONF_1_HELTF_NUM_MASK    ((uint32_t)0x001C0000)
#define SPU_STATIC_CONF_1_HELTF_NUM_LSB     18
#define SPU_STATIC_CONF_1_HELTF_NUM_WIDTH    ((uint32_t)0x00000003)
#define SPU_STATIC_CONF_1_HESIGB_NUM_MASK    ((uint32_t)0x0003E000)
#define SPU_STATIC_CONF_1_HESIGB_NUM_LSB    13
#define SPU_STATIC_CONF_1_HESIGB_NUM_WIDTH    ((uint32_t)0x00000005)
#define SPU_STATIC_CONF_1_HESIGA_NUM_MASK    ((uint32_t)0x00001C00)
#define SPU_STATIC_CONF_1_HESIGA_NUM_LSB    10
#define SPU_STATIC_CONF_1_HESIGA_NUM_WIDTH    ((uint32_t)0x00000003)
#define SPU_STATIC_CONF_1_HE_FORMAT_MASK    ((uint32_t)0x00000300)
#define SPU_STATIC_CONF_1_HE_FORMAT_LSB     8
#define SPU_STATIC_CONF_1_HE_FORMAT_WIDTH    ((uint32_t)0x00000002)
#define SPU_STATIC_CONF_1_BW_MASK           ((uint32_t)0x000000C0)
#define SPU_STATIC_CONF_1_BW_LSB            6
#define SPU_STATIC_CONF_1_BW_WIDTH          ((uint32_t)0x00000002)
#define SPU_STATIC_CONF_1_NTX_MASK          ((uint32_t)0x00000038)
#define SPU_STATIC_CONF_1_NTX_LSB           3
#define SPU_STATIC_CONF_1_NTX_WIDTH         ((uint32_t)0x00000003)
#define SPU_STATIC_CONF_1_MAPPER_EN_BIT     ((uint32_t)0x00000004)
#define SPU_STATIC_CONF_1_MAPPER_EN_POS     2
#define SPU_STATIC_CONF_1_TX_EN_BIT         ((uint32_t)0x00000002)
#define SPU_STATIC_CONF_1_TX_EN_POS         1
#define SPU_STATIC_CONF_1_RX_EN_BIT         ((uint32_t)0x00000001)
#define SPU_STATIC_CONF_1_RX_EN_POS         0

#define SPU_STATIC_CONF_1_NRX_RST           0x0
#define SPU_STATIC_CONF_1_CSD_LUT_SCALE_RST    0x0
#define SPU_STATIC_CONF_1_HE_SU_NDP_RST     0x0
#define SPU_STATIC_CONF_1_HELTF_MASKING_RST    0x0
#define SPU_STATIC_CONF_1_PILOTS_MASKED_RST    0x0
#define SPU_STATIC_CONF_1_HELTF_TYPE_RST    0x0
#define SPU_STATIC_CONF_1_HELTF_NUM_RST     0x0
#define SPU_STATIC_CONF_1_HESIGB_NUM_RST    0x0
#define SPU_STATIC_CONF_1_HESIGA_NUM_RST    0x0
#define SPU_STATIC_CONF_1_HE_FORMAT_RST     0x0
#define SPU_STATIC_CONF_1_BW_RST            0x0
#define SPU_STATIC_CONF_1_NTX_RST           0x0
#define SPU_STATIC_CONF_1_MAPPER_EN_RST     0x0
#define SPU_STATIC_CONF_1_TX_EN_RST         0x0
#define SPU_STATIC_CONF_1_RX_EN_RST         0x0

__INLINE void spu_static_conf_1_pack(uint8_t nrx, uint8_t csd_lut_scale, uint8_t he_su_ndp, uint8_t heltf_masking, uint8_t pilots_masked, uint8_t heltf_type, uint8_t heltf_num, uint8_t hesigb_num, uint8_t hesiga_num, uint8_t he_format, uint8_t bw, uint8_t ntx, uint8_t mapper_en, uint8_t tx_en, uint8_t rx_en)
{
	ASSERT_ERR((((uint32_t)nrx << 28) & ~((uint32_t)0x70000000)) == 0);
	ASSERT_ERR((((uint32_t)csd_lut_scale << 26) & ~((uint32_t)0x0C000000)) == 0);
	ASSERT_ERR((((uint32_t)he_su_ndp << 25) & ~((uint32_t)0x02000000)) == 0);
	ASSERT_ERR((((uint32_t)heltf_masking << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)pilots_masked << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)heltf_type << 21) & ~((uint32_t)0x00600000)) == 0);
	ASSERT_ERR((((uint32_t)heltf_num << 18) & ~((uint32_t)0x001C0000)) == 0);
	ASSERT_ERR((((uint32_t)hesigb_num << 13) & ~((uint32_t)0x0003E000)) == 0);
	ASSERT_ERR((((uint32_t)hesiga_num << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)he_format << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)bw << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)ntx << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)mapper_en << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)tx_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)rx_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_1_ADDR,  ((uint32_t)nrx << 28) |((uint32_t)csd_lut_scale << 26) |((uint32_t)he_su_ndp << 25) |((uint32_t)heltf_masking << 24) |((uint32_t)pilots_masked << 23) |((uint32_t)heltf_type << 21) |((uint32_t)heltf_num << 18) |((uint32_t)hesigb_num << 13) |((uint32_t)hesiga_num << 10) |((uint32_t)he_format << 8) |((uint32_t)bw << 6) |((uint32_t)ntx << 3) |((uint32_t)mapper_en << 2) |((uint32_t)tx_en << 1) |((uint32_t)rx_en << 0));
}

__INLINE void spu_static_conf_1_unpack(uint8_t* nrx, uint8_t* csd_lut_scale, uint8_t* he_su_ndp, uint8_t* heltf_masking, uint8_t* pilots_masked, uint8_t* heltf_type, uint8_t* heltf_num, uint8_t* hesigb_num, uint8_t* hesiga_num, uint8_t* he_format, uint8_t* bw, uint8_t* ntx, uint8_t* mapper_en, uint8_t* tx_en, uint8_t* rx_en)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_1_ADDR);

	*nrx = (localVal & ((uint32_t)0x70000000)) >>  28;
	*csd_lut_scale = (localVal & ((uint32_t)0x0C000000)) >>  26;
	*he_su_ndp = (localVal & ((uint32_t)0x02000000)) >>  25;
	*heltf_masking = (localVal & ((uint32_t)0x01000000)) >>  24;
	*pilots_masked = (localVal & ((uint32_t)0x00800000)) >>  23;
	*heltf_type = (localVal & ((uint32_t)0x00600000)) >>  21;
	*heltf_num = (localVal & ((uint32_t)0x001C0000)) >>  18;
	*hesigb_num = (localVal & ((uint32_t)0x0003E000)) >>  13;
	*hesiga_num = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*he_format = (localVal & ((uint32_t)0x00000300)) >>  8;
	*bw = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*ntx = (localVal & ((uint32_t)0x00000038)) >>  3;
	*mapper_en = (localVal & ((uint32_t)0x00000004)) >>  2;
	*tx_en = (localVal & ((uint32_t)0x00000002)) >>  1;
	*rx_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t spu_static_conf_1_nrx_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x70000000)) >> 28);
}
__INLINE void spu_static_conf_1_nrx_setf(uint8_t nrx)
{
	ASSERT_ERR((((uint32_t)nrx << 28) & ~((uint32_t)0x70000000)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_1_ADDR, (REG_PL_RD(SPU_STATIC_CONF_1_ADDR) & ~((uint32_t)0x70000000)) | ((uint32_t)nrx <<28));
}
__INLINE uint8_t spu_static_conf_1_csd_lut_scale_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0C000000)) >> 26);
}
__INLINE void spu_static_conf_1_csd_lut_scale_setf(uint8_t csdlutscale)
{
	ASSERT_ERR((((uint32_t)csdlutscale << 26) & ~((uint32_t)0x0C000000)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_1_ADDR, (REG_PL_RD(SPU_STATIC_CONF_1_ADDR) & ~((uint32_t)0x0C000000)) | ((uint32_t)csdlutscale <<26));
}
__INLINE uint8_t spu_static_conf_1_he_su_ndp_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE void spu_static_conf_1_he_su_ndp_setf(uint8_t hesundp)
{
	ASSERT_ERR((((uint32_t)hesundp << 25) & ~((uint32_t)0x02000000)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_1_ADDR, (REG_PL_RD(SPU_STATIC_CONF_1_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)hesundp <<25));
}
__INLINE uint8_t spu_static_conf_1_heltf_masking_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE void spu_static_conf_1_heltf_masking_setf(uint8_t heltfmasking)
{
	ASSERT_ERR((((uint32_t)heltfmasking << 24) & ~((uint32_t)0x01000000)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_1_ADDR, (REG_PL_RD(SPU_STATIC_CONF_1_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)heltfmasking <<24));
}
__INLINE uint8_t spu_static_conf_1_pilots_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE void spu_static_conf_1_pilots_masked_setf(uint8_t pilotsmasked)
{
	ASSERT_ERR((((uint32_t)pilotsmasked << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_1_ADDR, (REG_PL_RD(SPU_STATIC_CONF_1_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)pilotsmasked <<23));
}
__INLINE uint8_t spu_static_conf_1_heltf_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00600000)) >> 21);
}
__INLINE void spu_static_conf_1_heltf_type_setf(uint8_t heltftype)
{
	ASSERT_ERR((((uint32_t)heltftype << 21) & ~((uint32_t)0x00600000)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_1_ADDR, (REG_PL_RD(SPU_STATIC_CONF_1_ADDR) & ~((uint32_t)0x00600000)) | ((uint32_t)heltftype <<21));
}
__INLINE uint8_t spu_static_conf_1_heltf_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001C0000)) >> 18);
}
__INLINE void spu_static_conf_1_heltf_num_setf(uint8_t heltfnum)
{
	ASSERT_ERR((((uint32_t)heltfnum << 18) & ~((uint32_t)0x001C0000)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_1_ADDR, (REG_PL_RD(SPU_STATIC_CONF_1_ADDR) & ~((uint32_t)0x001C0000)) | ((uint32_t)heltfnum <<18));
}
__INLINE uint8_t spu_static_conf_1_hesigb_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0003E000)) >> 13);
}
__INLINE void spu_static_conf_1_hesigb_num_setf(uint8_t hesigbnum)
{
	ASSERT_ERR((((uint32_t)hesigbnum << 13) & ~((uint32_t)0x0003E000)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_1_ADDR, (REG_PL_RD(SPU_STATIC_CONF_1_ADDR) & ~((uint32_t)0x0003E000)) | ((uint32_t)hesigbnum <<13));
}
__INLINE uint8_t spu_static_conf_1_hesiga_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void spu_static_conf_1_hesiga_num_setf(uint8_t hesiganum)
{
	ASSERT_ERR((((uint32_t)hesiganum << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_1_ADDR, (REG_PL_RD(SPU_STATIC_CONF_1_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)hesiganum <<10));
}
__INLINE uint8_t spu_static_conf_1_he_format_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void spu_static_conf_1_he_format_setf(uint8_t heformat)
{
	ASSERT_ERR((((uint32_t)heformat << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_1_ADDR, (REG_PL_RD(SPU_STATIC_CONF_1_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)heformat <<8));
}
__INLINE uint8_t spu_static_conf_1_bw_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void spu_static_conf_1_bw_setf(uint8_t bw)
{
	ASSERT_ERR((((uint32_t)bw << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_1_ADDR, (REG_PL_RD(SPU_STATIC_CONF_1_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)bw <<6));
}
__INLINE uint8_t spu_static_conf_1_ntx_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void spu_static_conf_1_ntx_setf(uint8_t ntx)
{
	ASSERT_ERR((((uint32_t)ntx << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_1_ADDR, (REG_PL_RD(SPU_STATIC_CONF_1_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)ntx <<3));
}
__INLINE uint8_t spu_static_conf_1_mapper_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void spu_static_conf_1_mapper_en_setf(uint8_t mapperen)
{
	ASSERT_ERR((((uint32_t)mapperen << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_1_ADDR, (REG_PL_RD(SPU_STATIC_CONF_1_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)mapperen <<2));
}
__INLINE uint8_t spu_static_conf_1_tx_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void spu_static_conf_1_tx_en_setf(uint8_t txen)
{
	ASSERT_ERR((((uint32_t)txen << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_1_ADDR, (REG_PL_RD(SPU_STATIC_CONF_1_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)txen <<1));
}
__INLINE uint8_t spu_static_conf_1_rx_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STATIC_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void spu_static_conf_1_rx_en_setf(uint8_t rxen)
{
	ASSERT_ERR((((uint32_t)rxen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_STATIC_CONF_1_ADDR, (REG_PL_RD(SPU_STATIC_CONF_1_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)rxen <<0));
}

/**
 * @brief P_8_X_8_CONF_0 register definition
 *  P 8x8 matrix elements 00 to 37 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 P8_X8_00_37               0x0
 * </pre>
 */
#define SPU_P_8_X_8_CONF_0_ADDR        (REG_SPU_BASE_ADDR+0x00000008)
#define SPU_P_8_X_8_CONF_0_OFFSET      0x00000008
#define SPU_P_8_X_8_CONF_0_INDEX       0x00000002
#define SPU_P_8_X_8_CONF_0_RESET       0x00000000

__INLINE uint32_t  spu_p_8_x_8_conf_0_get(void)
{
	return REG_PL_RD(SPU_P_8_X_8_CONF_0_ADDR);
}

__INLINE void spu_p_8_x_8_conf_0_set(uint32_t value)
{
	REG_PL_WR(SPU_P_8_X_8_CONF_0_ADDR, value);
}

// field definitions
#define SPU_P_8_X_8_CONF_0_P_8_X_8_00_37_MASK    ((uint32_t)0xFFFFFFFF)
#define SPU_P_8_X_8_CONF_0_P_8_X_8_00_37_LSB    0
#define SPU_P_8_X_8_CONF_0_P_8_X_8_00_37_WIDTH    ((uint32_t)0x00000020)

#define SPU_P_8_X_8_CONF_0_P_8_X_8_00_37_RST    0x0

__INLINE uint32_t spu_p_8_x_8_conf_0_p_8_x_8_00_37_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_8_X_8_CONF_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void spu_p_8_x_8_conf_0_p_8_x_8_00_37_setf(uint32_t p8x80037)
{
	ASSERT_ERR((((uint32_t)p8x80037 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SPU_P_8_X_8_CONF_0_ADDR, (uint32_t)p8x80037 << 0);
}

/**
 * @brief P_8_X_8_CONF_1 register definition
 *  P 8x8 matrix elements 40 to 77 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 P8_X8_40_77               0x0
 * </pre>
 */
#define SPU_P_8_X_8_CONF_1_ADDR        (REG_SPU_BASE_ADDR+0x0000000C)
#define SPU_P_8_X_8_CONF_1_OFFSET      0x0000000C
#define SPU_P_8_X_8_CONF_1_INDEX       0x00000003
#define SPU_P_8_X_8_CONF_1_RESET       0x00000000

__INLINE uint32_t  spu_p_8_x_8_conf_1_get(void)
{
	return REG_PL_RD(SPU_P_8_X_8_CONF_1_ADDR);
}

__INLINE void spu_p_8_x_8_conf_1_set(uint32_t value)
{
	REG_PL_WR(SPU_P_8_X_8_CONF_1_ADDR, value);
}

// field definitions
#define SPU_P_8_X_8_CONF_1_P_8_X_8_40_77_MASK    ((uint32_t)0xFFFFFFFF)
#define SPU_P_8_X_8_CONF_1_P_8_X_8_40_77_LSB    0
#define SPU_P_8_X_8_CONF_1_P_8_X_8_40_77_WIDTH    ((uint32_t)0x00000020)

#define SPU_P_8_X_8_CONF_1_P_8_X_8_40_77_RST    0x0

__INLINE uint32_t spu_p_8_x_8_conf_1_p_8_x_8_40_77_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_8_X_8_CONF_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void spu_p_8_x_8_conf_1_p_8_x_8_40_77_setf(uint32_t p8x84077)
{
	ASSERT_ERR((((uint32_t)p8x84077 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SPU_P_8_X_8_CONF_1_ADDR, (uint32_t)p8x84077 << 0);
}

/**
 * @brief CSD_01_CONF register definition
 *  CSD LUT streams 0 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 CSD1                      0x0
 *    15:00 CSD0                      0x0
 * </pre>
 */
#define SPU_CSD_01_CONF_ADDR        (REG_SPU_BASE_ADDR+0x00000010)
#define SPU_CSD_01_CONF_OFFSET      0x00000010
#define SPU_CSD_01_CONF_INDEX       0x00000004
#define SPU_CSD_01_CONF_RESET       0x00000000

__INLINE uint32_t  spu_csd_01_conf_get(void)
{
	return REG_PL_RD(SPU_CSD_01_CONF_ADDR);
}

__INLINE void spu_csd_01_conf_set(uint32_t value)
{
	REG_PL_WR(SPU_CSD_01_CONF_ADDR, value);
}

// field definitions
#define SPU_CSD_01_CONF_CSD_1_MASK          ((uint32_t)0xFFFF0000)
#define SPU_CSD_01_CONF_CSD_1_LSB           16
#define SPU_CSD_01_CONF_CSD_1_WIDTH         ((uint32_t)0x00000010)
#define SPU_CSD_01_CONF_CSD_0_MASK          ((uint32_t)0x0000FFFF)
#define SPU_CSD_01_CONF_CSD_0_LSB           0
#define SPU_CSD_01_CONF_CSD_0_WIDTH         ((uint32_t)0x00000010)

#define SPU_CSD_01_CONF_CSD_1_RST           0x0
#define SPU_CSD_01_CONF_CSD_0_RST           0x0

__INLINE void spu_csd_01_conf_pack(uint16_t csd1, uint16_t csd0)
{
	ASSERT_ERR((((uint32_t)csd1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)csd0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_CSD_01_CONF_ADDR,  ((uint32_t)csd1 << 16) |((uint32_t)csd0 << 0));
}

__INLINE void spu_csd_01_conf_unpack(uint16_t* csd1, uint16_t* csd0)
{
	uint32_t localVal = REG_PL_RD(SPU_CSD_01_CONF_ADDR);

	*csd1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*csd0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_csd_01_conf_csd_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_CSD_01_CONF_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_csd_01_conf_csd_1_setf(uint16_t csd1)
{
	ASSERT_ERR((((uint32_t)csd1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_CSD_01_CONF_ADDR, (REG_PL_RD(SPU_CSD_01_CONF_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)csd1 <<16));
}
__INLINE uint16_t spu_csd_01_conf_csd_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_CSD_01_CONF_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_csd_01_conf_csd_0_setf(uint16_t csd0)
{
	ASSERT_ERR((((uint32_t)csd0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_CSD_01_CONF_ADDR, (REG_PL_RD(SPU_CSD_01_CONF_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)csd0 <<0));
}

/**
 * @brief CSD_23_CONF register definition
 *  CSD LUT streams 2 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 CSD3                      0x0
 *    15:00 CSD2                      0x0
 * </pre>
 */
#define SPU_CSD_23_CONF_ADDR        (REG_SPU_BASE_ADDR+0x00000014)
#define SPU_CSD_23_CONF_OFFSET      0x00000014
#define SPU_CSD_23_CONF_INDEX       0x00000005
#define SPU_CSD_23_CONF_RESET       0x00000000

__INLINE uint32_t  spu_csd_23_conf_get(void)
{
	return REG_PL_RD(SPU_CSD_23_CONF_ADDR);
}

__INLINE void spu_csd_23_conf_set(uint32_t value)
{
	REG_PL_WR(SPU_CSD_23_CONF_ADDR, value);
}

// field definitions
#define SPU_CSD_23_CONF_CSD_3_MASK          ((uint32_t)0xFFFF0000)
#define SPU_CSD_23_CONF_CSD_3_LSB           16
#define SPU_CSD_23_CONF_CSD_3_WIDTH         ((uint32_t)0x00000010)
#define SPU_CSD_23_CONF_CSD_2_MASK          ((uint32_t)0x0000FFFF)
#define SPU_CSD_23_CONF_CSD_2_LSB           0
#define SPU_CSD_23_CONF_CSD_2_WIDTH         ((uint32_t)0x00000010)

#define SPU_CSD_23_CONF_CSD_3_RST           0x0
#define SPU_CSD_23_CONF_CSD_2_RST           0x0

__INLINE void spu_csd_23_conf_pack(uint16_t csd3, uint16_t csd2)
{
	ASSERT_ERR((((uint32_t)csd3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)csd2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_CSD_23_CONF_ADDR,  ((uint32_t)csd3 << 16) |((uint32_t)csd2 << 0));
}

__INLINE void spu_csd_23_conf_unpack(uint16_t* csd3, uint16_t* csd2)
{
	uint32_t localVal = REG_PL_RD(SPU_CSD_23_CONF_ADDR);

	*csd3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*csd2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_csd_23_conf_csd_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_CSD_23_CONF_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_csd_23_conf_csd_3_setf(uint16_t csd3)
{
	ASSERT_ERR((((uint32_t)csd3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_CSD_23_CONF_ADDR, (REG_PL_RD(SPU_CSD_23_CONF_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)csd3 <<16));
}
__INLINE uint16_t spu_csd_23_conf_csd_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_CSD_23_CONF_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_csd_23_conf_csd_2_setf(uint16_t csd2)
{
	ASSERT_ERR((((uint32_t)csd2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_CSD_23_CONF_ADDR, (REG_PL_RD(SPU_CSD_23_CONF_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)csd2 <<0));
}

/**
 * @brief CSD_45_CONF register definition
 *  CSD LUT streams 4 5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 CSD5                      0x0
 *    15:00 CSD4                      0x0
 * </pre>
 */
#define SPU_CSD_45_CONF_ADDR        (REG_SPU_BASE_ADDR+0x00000018)
#define SPU_CSD_45_CONF_OFFSET      0x00000018
#define SPU_CSD_45_CONF_INDEX       0x00000006
#define SPU_CSD_45_CONF_RESET       0x00000000

__INLINE uint32_t  spu_csd_45_conf_get(void)
{
	return REG_PL_RD(SPU_CSD_45_CONF_ADDR);
}

__INLINE void spu_csd_45_conf_set(uint32_t value)
{
	REG_PL_WR(SPU_CSD_45_CONF_ADDR, value);
}

// field definitions
#define SPU_CSD_45_CONF_CSD_5_MASK          ((uint32_t)0xFFFF0000)
#define SPU_CSD_45_CONF_CSD_5_LSB           16
#define SPU_CSD_45_CONF_CSD_5_WIDTH         ((uint32_t)0x00000010)
#define SPU_CSD_45_CONF_CSD_4_MASK          ((uint32_t)0x0000FFFF)
#define SPU_CSD_45_CONF_CSD_4_LSB           0
#define SPU_CSD_45_CONF_CSD_4_WIDTH         ((uint32_t)0x00000010)

#define SPU_CSD_45_CONF_CSD_5_RST           0x0
#define SPU_CSD_45_CONF_CSD_4_RST           0x0

__INLINE void spu_csd_45_conf_pack(uint16_t csd5, uint16_t csd4)
{
	ASSERT_ERR((((uint32_t)csd5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)csd4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_CSD_45_CONF_ADDR,  ((uint32_t)csd5 << 16) |((uint32_t)csd4 << 0));
}

__INLINE void spu_csd_45_conf_unpack(uint16_t* csd5, uint16_t* csd4)
{
	uint32_t localVal = REG_PL_RD(SPU_CSD_45_CONF_ADDR);

	*csd5 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*csd4 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_csd_45_conf_csd_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_CSD_45_CONF_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_csd_45_conf_csd_5_setf(uint16_t csd5)
{
	ASSERT_ERR((((uint32_t)csd5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_CSD_45_CONF_ADDR, (REG_PL_RD(SPU_CSD_45_CONF_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)csd5 <<16));
}
__INLINE uint16_t spu_csd_45_conf_csd_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_CSD_45_CONF_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_csd_45_conf_csd_4_setf(uint16_t csd4)
{
	ASSERT_ERR((((uint32_t)csd4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_CSD_45_CONF_ADDR, (REG_PL_RD(SPU_CSD_45_CONF_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)csd4 <<0));
}

/**
 * @brief CSD_67_CONF register definition
 *  CSD LUT streams 6 7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 CSD7                      0x0
 *    15:00 CSD6                      0x0
 * </pre>
 */
#define SPU_CSD_67_CONF_ADDR        (REG_SPU_BASE_ADDR+0x0000001C)
#define SPU_CSD_67_CONF_OFFSET      0x0000001C
#define SPU_CSD_67_CONF_INDEX       0x00000007
#define SPU_CSD_67_CONF_RESET       0x00000000

__INLINE uint32_t  spu_csd_67_conf_get(void)
{
	return REG_PL_RD(SPU_CSD_67_CONF_ADDR);
}

__INLINE void spu_csd_67_conf_set(uint32_t value)
{
	REG_PL_WR(SPU_CSD_67_CONF_ADDR, value);
}

// field definitions
#define SPU_CSD_67_CONF_CSD_7_MASK          ((uint32_t)0xFFFF0000)
#define SPU_CSD_67_CONF_CSD_7_LSB           16
#define SPU_CSD_67_CONF_CSD_7_WIDTH         ((uint32_t)0x00000010)
#define SPU_CSD_67_CONF_CSD_6_MASK          ((uint32_t)0x0000FFFF)
#define SPU_CSD_67_CONF_CSD_6_LSB           0
#define SPU_CSD_67_CONF_CSD_6_WIDTH         ((uint32_t)0x00000010)

#define SPU_CSD_67_CONF_CSD_7_RST           0x0
#define SPU_CSD_67_CONF_CSD_6_RST           0x0

__INLINE void spu_csd_67_conf_pack(uint16_t csd7, uint16_t csd6)
{
	ASSERT_ERR((((uint32_t)csd7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)csd6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_CSD_67_CONF_ADDR,  ((uint32_t)csd7 << 16) |((uint32_t)csd6 << 0));
}

__INLINE void spu_csd_67_conf_unpack(uint16_t* csd7, uint16_t* csd6)
{
	uint32_t localVal = REG_PL_RD(SPU_CSD_67_CONF_ADDR);

	*csd7 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*csd6 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_csd_67_conf_csd_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_CSD_67_CONF_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_csd_67_conf_csd_7_setf(uint16_t csd7)
{
	ASSERT_ERR((((uint32_t)csd7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_CSD_67_CONF_ADDR, (REG_PL_RD(SPU_CSD_67_CONF_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)csd7 <<16));
}
__INLINE uint16_t spu_csd_67_conf_csd_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_CSD_67_CONF_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_csd_67_conf_csd_6_setf(uint16_t csd6)
{
	ASSERT_ERR((((uint32_t)csd6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_CSD_67_CONF_ADDR, (REG_PL_RD(SPU_CSD_67_CONF_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)csd6 <<0));
}

/**
 * @brief HW_LOAD register definition
 *  Load mpu inputs register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    MPU_LOAD                  0              
 * </pre>
 */
#define SPU_HW_LOAD_ADDR        (REG_SPU_BASE_ADDR+0x00000020)
#define SPU_HW_LOAD_OFFSET      0x00000020
#define SPU_HW_LOAD_INDEX       0x00000008
#define SPU_HW_LOAD_RESET       0x00000000

__INLINE uint32_t  spu_hw_load_get(void)
{
	return REG_PL_RD(SPU_HW_LOAD_ADDR);
}

__INLINE void spu_hw_load_set(uint32_t value)
{
	REG_PL_WR(SPU_HW_LOAD_ADDR, value);
}

// field definitions
#define SPU_HW_LOAD_MPU_LOAD_BIT            ((uint32_t)0x00000001)
#define SPU_HW_LOAD_MPU_LOAD_POS            0

#define SPU_HW_LOAD_MPU_LOAD_RST            0x0

__INLINE uint8_t spu_hw_load_mpu_load_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_HW_LOAD_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void spu_hw_load_mpu_load_setf(uint8_t mpuload)
{
	ASSERT_ERR((((uint32_t)mpuload << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_HW_LOAD_ADDR, (uint32_t)mpuload << 0);
}

/**
 * @brief DEBUG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:24 DEBUG_SEL_4               0x0
 *    22:16 DEBUG_SEL_3               0x0
 *    14:08 DEBUG_SEL_2               0x0
 *    06:00 DEBUG_SEL_1               0x0
 * </pre>
 */
#define SPU_DEBUG_1_ADDR        (REG_SPU_BASE_ADDR+0x00000024)
#define SPU_DEBUG_1_OFFSET      0x00000024
#define SPU_DEBUG_1_INDEX       0x00000009
#define SPU_DEBUG_1_RESET       0x00000000

__INLINE uint32_t  spu_debug_1_get(void)
{
	return REG_PL_RD(SPU_DEBUG_1_ADDR);
}

__INLINE void spu_debug_1_set(uint32_t value)
{
	REG_PL_WR(SPU_DEBUG_1_ADDR, value);
}

// field definitions
#define SPU_DEBUG_1_DEBUG_SEL_4_MASK        ((uint32_t)0x7F000000)
#define SPU_DEBUG_1_DEBUG_SEL_4_LSB         24
#define SPU_DEBUG_1_DEBUG_SEL_4_WIDTH       ((uint32_t)0x00000007)
#define SPU_DEBUG_1_DEBUG_SEL_3_MASK        ((uint32_t)0x007F0000)
#define SPU_DEBUG_1_DEBUG_SEL_3_LSB         16
#define SPU_DEBUG_1_DEBUG_SEL_3_WIDTH       ((uint32_t)0x00000007)
#define SPU_DEBUG_1_DEBUG_SEL_2_MASK        ((uint32_t)0x00007F00)
#define SPU_DEBUG_1_DEBUG_SEL_2_LSB         8
#define SPU_DEBUG_1_DEBUG_SEL_2_WIDTH       ((uint32_t)0x00000007)
#define SPU_DEBUG_1_DEBUG_SEL_1_MASK        ((uint32_t)0x0000007F)
#define SPU_DEBUG_1_DEBUG_SEL_1_LSB         0
#define SPU_DEBUG_1_DEBUG_SEL_1_WIDTH       ((uint32_t)0x00000007)

#define SPU_DEBUG_1_DEBUG_SEL_4_RST         0x0
#define SPU_DEBUG_1_DEBUG_SEL_3_RST         0x0
#define SPU_DEBUG_1_DEBUG_SEL_2_RST         0x0
#define SPU_DEBUG_1_DEBUG_SEL_1_RST         0x0

__INLINE void spu_debug_1_pack(uint8_t debug_sel_4, uint8_t debug_sel_3, uint8_t debug_sel_2, uint8_t debug_sel_1)
{
	ASSERT_ERR((((uint32_t)debug_sel_4 << 24) & ~((uint32_t)0x7F000000)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_3 << 16) & ~((uint32_t)0x007F0000)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_2 << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_1 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(SPU_DEBUG_1_ADDR,  ((uint32_t)debug_sel_4 << 24) |((uint32_t)debug_sel_3 << 16) |((uint32_t)debug_sel_2 << 8) |((uint32_t)debug_sel_1 << 0));
}

__INLINE void spu_debug_1_unpack(uint8_t* debug_sel_4, uint8_t* debug_sel_3, uint8_t* debug_sel_2, uint8_t* debug_sel_1)
{
	uint32_t localVal = REG_PL_RD(SPU_DEBUG_1_ADDR);

	*debug_sel_4 = (localVal & ((uint32_t)0x7F000000)) >>  24;
	*debug_sel_3 = (localVal & ((uint32_t)0x007F0000)) >>  16;
	*debug_sel_2 = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*debug_sel_1 = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint8_t spu_debug_1_debug_sel_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_DEBUG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x7F000000)) >> 24);
}
__INLINE void spu_debug_1_debug_sel_4_setf(uint8_t debugsel4)
{
	ASSERT_ERR((((uint32_t)debugsel4 << 24) & ~((uint32_t)0x7F000000)) == 0);
	REG_PL_WR(SPU_DEBUG_1_ADDR, (REG_PL_RD(SPU_DEBUG_1_ADDR) & ~((uint32_t)0x7F000000)) | ((uint32_t)debugsel4 <<24));
}
__INLINE uint8_t spu_debug_1_debug_sel_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_DEBUG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x007F0000)) >> 16);
}
__INLINE void spu_debug_1_debug_sel_3_setf(uint8_t debugsel3)
{
	ASSERT_ERR((((uint32_t)debugsel3 << 16) & ~((uint32_t)0x007F0000)) == 0);
	REG_PL_WR(SPU_DEBUG_1_ADDR, (REG_PL_RD(SPU_DEBUG_1_ADDR) & ~((uint32_t)0x007F0000)) | ((uint32_t)debugsel3 <<16));
}
__INLINE uint8_t spu_debug_1_debug_sel_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_DEBUG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void spu_debug_1_debug_sel_2_setf(uint8_t debugsel2)
{
	ASSERT_ERR((((uint32_t)debugsel2 << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(SPU_DEBUG_1_ADDR, (REG_PL_RD(SPU_DEBUG_1_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)debugsel2 <<8));
}
__INLINE uint8_t spu_debug_1_debug_sel_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_DEBUG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}
__INLINE void spu_debug_1_debug_sel_1_setf(uint8_t debugsel1)
{
	ASSERT_ERR((((uint32_t)debugsel1 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(SPU_DEBUG_1_ADDR, (REG_PL_RD(SPU_DEBUG_1_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)debugsel1 <<0));
}

/**
 * @brief DEBUG_2 register definition
 *  Debug register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28    MUL_FICR_IS_STOPPED       0              
 *    27    CW_BUF_RX_FICR_IS_STOPPED 0              
 *    26    CW_BUF_RX_FICW_IS_STOPPED 0              
 *    25    CW_BUF_TX_FICR_IS_STOPPED 0              
 *    24    CW_BUF_TX_FICW_IS_STOPPED 0              
 *    17    DEBUG_EN                  0              
 *    16    HELTF_APB_EN              0              
 *    14:08 DEBUG_SEL_6               0x0
 *    06:00 DEBUG_SEL_5               0x0
 * </pre>
 */
#define SPU_DEBUG_2_ADDR        (REG_SPU_BASE_ADDR+0x00000028)
#define SPU_DEBUG_2_OFFSET      0x00000028
#define SPU_DEBUG_2_INDEX       0x0000000A
#define SPU_DEBUG_2_RESET       0x00000000

__INLINE uint32_t  spu_debug_2_get(void)
{
	return REG_PL_RD(SPU_DEBUG_2_ADDR);
}

__INLINE void spu_debug_2_set(uint32_t value)
{
	REG_PL_WR(SPU_DEBUG_2_ADDR, value);
}

// field definitions
#define SPU_DEBUG_2_MUL_FICR_IS_STOPPED_BIT    ((uint32_t)0x10000000)
#define SPU_DEBUG_2_MUL_FICR_IS_STOPPED_POS    28
#define SPU_DEBUG_2_CW_BUF_RX_FICR_IS_STOPPED_BIT    ((uint32_t)0x08000000)
#define SPU_DEBUG_2_CW_BUF_RX_FICR_IS_STOPPED_POS    27
#define SPU_DEBUG_2_CW_BUF_RX_FICW_IS_STOPPED_BIT    ((uint32_t)0x04000000)
#define SPU_DEBUG_2_CW_BUF_RX_FICW_IS_STOPPED_POS    26
#define SPU_DEBUG_2_CW_BUF_TX_FICR_IS_STOPPED_BIT    ((uint32_t)0x02000000)
#define SPU_DEBUG_2_CW_BUF_TX_FICR_IS_STOPPED_POS    25
#define SPU_DEBUG_2_CW_BUF_TX_FICW_IS_STOPPED_BIT    ((uint32_t)0x01000000)
#define SPU_DEBUG_2_CW_BUF_TX_FICW_IS_STOPPED_POS    24
#define SPU_DEBUG_2_DEBUG_EN_BIT            ((uint32_t)0x00020000)
#define SPU_DEBUG_2_DEBUG_EN_POS            17
#define SPU_DEBUG_2_HELTF_APB_EN_BIT        ((uint32_t)0x00010000)
#define SPU_DEBUG_2_HELTF_APB_EN_POS        16
#define SPU_DEBUG_2_DEBUG_SEL_6_MASK        ((uint32_t)0x00007F00)
#define SPU_DEBUG_2_DEBUG_SEL_6_LSB         8
#define SPU_DEBUG_2_DEBUG_SEL_6_WIDTH       ((uint32_t)0x00000007)
#define SPU_DEBUG_2_DEBUG_SEL_5_MASK        ((uint32_t)0x0000007F)
#define SPU_DEBUG_2_DEBUG_SEL_5_LSB         0
#define SPU_DEBUG_2_DEBUG_SEL_5_WIDTH       ((uint32_t)0x00000007)

#define SPU_DEBUG_2_MUL_FICR_IS_STOPPED_RST    0x0
#define SPU_DEBUG_2_CW_BUF_RX_FICR_IS_STOPPED_RST    0x0
#define SPU_DEBUG_2_CW_BUF_RX_FICW_IS_STOPPED_RST    0x0
#define SPU_DEBUG_2_CW_BUF_TX_FICR_IS_STOPPED_RST    0x0
#define SPU_DEBUG_2_CW_BUF_TX_FICW_IS_STOPPED_RST    0x0
#define SPU_DEBUG_2_DEBUG_EN_RST            0x0
#define SPU_DEBUG_2_HELTF_APB_EN_RST        0x0
#define SPU_DEBUG_2_DEBUG_SEL_6_RST         0x0
#define SPU_DEBUG_2_DEBUG_SEL_5_RST         0x0

__INLINE void spu_debug_2_pack(uint8_t mul_ficr_is_stopped, uint8_t cw_buf_rx_ficr_is_stopped, uint8_t cw_buf_rx_ficw_is_stopped, uint8_t cw_buf_tx_ficr_is_stopped, uint8_t cw_buf_tx_ficw_is_stopped, uint8_t debug_en, uint8_t heltf_apb_en, uint8_t debug_sel_6, uint8_t debug_sel_5)
{
	ASSERT_ERR((((uint32_t)mul_ficr_is_stopped << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)cw_buf_rx_ficr_is_stopped << 27) & ~((uint32_t)0x08000000)) == 0);
	ASSERT_ERR((((uint32_t)cw_buf_rx_ficw_is_stopped << 26) & ~((uint32_t)0x04000000)) == 0);
	ASSERT_ERR((((uint32_t)cw_buf_tx_ficr_is_stopped << 25) & ~((uint32_t)0x02000000)) == 0);
	ASSERT_ERR((((uint32_t)cw_buf_tx_ficw_is_stopped << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)debug_en << 17) & ~((uint32_t)0x00020000)) == 0);
	ASSERT_ERR((((uint32_t)heltf_apb_en << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_6 << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)debug_sel_5 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(SPU_DEBUG_2_ADDR,  ((uint32_t)mul_ficr_is_stopped << 28) |((uint32_t)cw_buf_rx_ficr_is_stopped << 27) |((uint32_t)cw_buf_rx_ficw_is_stopped << 26) |((uint32_t)cw_buf_tx_ficr_is_stopped << 25) |((uint32_t)cw_buf_tx_ficw_is_stopped << 24) |((uint32_t)debug_en << 17) |((uint32_t)heltf_apb_en << 16) |((uint32_t)debug_sel_6 << 8) |((uint32_t)debug_sel_5 << 0));
}

__INLINE void spu_debug_2_unpack(uint8_t* mul_ficr_is_stopped, uint8_t* cw_buf_rx_ficr_is_stopped, uint8_t* cw_buf_rx_ficw_is_stopped, uint8_t* cw_buf_tx_ficr_is_stopped, uint8_t* cw_buf_tx_ficw_is_stopped, uint8_t* debug_en, uint8_t* heltf_apb_en, uint8_t* debug_sel_6, uint8_t* debug_sel_5)
{
	uint32_t localVal = REG_PL_RD(SPU_DEBUG_2_ADDR);

	*mul_ficr_is_stopped = (localVal & ((uint32_t)0x10000000)) >>  28;
	*cw_buf_rx_ficr_is_stopped = (localVal & ((uint32_t)0x08000000)) >>  27;
	*cw_buf_rx_ficw_is_stopped = (localVal & ((uint32_t)0x04000000)) >>  26;
	*cw_buf_tx_ficr_is_stopped = (localVal & ((uint32_t)0x02000000)) >>  25;
	*cw_buf_tx_ficw_is_stopped = (localVal & ((uint32_t)0x01000000)) >>  24;
	*debug_en = (localVal & ((uint32_t)0x00020000)) >>  17;
	*heltf_apb_en = (localVal & ((uint32_t)0x00010000)) >>  16;
	*debug_sel_6 = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*debug_sel_5 = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint8_t spu_debug_2_mul_ficr_is_stopped_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_DEBUG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE uint8_t spu_debug_2_cw_buf_rx_ficr_is_stopped_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_DEBUG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE uint8_t spu_debug_2_cw_buf_rx_ficw_is_stopped_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_DEBUG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE uint8_t spu_debug_2_cw_buf_tx_ficr_is_stopped_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_DEBUG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE uint8_t spu_debug_2_cw_buf_tx_ficw_is_stopped_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_DEBUG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE uint8_t spu_debug_2_debug_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_DEBUG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE void spu_debug_2_debug_en_setf(uint8_t debugen)
{
	ASSERT_ERR((((uint32_t)debugen << 17) & ~((uint32_t)0x00020000)) == 0);
	REG_PL_WR(SPU_DEBUG_2_ADDR, (REG_PL_RD(SPU_DEBUG_2_ADDR) & ~((uint32_t)0x00020000)) | ((uint32_t)debugen <<17));
}
__INLINE uint8_t spu_debug_2_heltf_apb_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_DEBUG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void spu_debug_2_heltf_apb_en_setf(uint8_t heltfapben)
{
	ASSERT_ERR((((uint32_t)heltfapben << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(SPU_DEBUG_2_ADDR, (REG_PL_RD(SPU_DEBUG_2_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)heltfapben <<16));
}
__INLINE uint8_t spu_debug_2_debug_sel_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_DEBUG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void spu_debug_2_debug_sel_6_setf(uint8_t debugsel6)
{
	ASSERT_ERR((((uint32_t)debugsel6 << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(SPU_DEBUG_2_ADDR, (REG_PL_RD(SPU_DEBUG_2_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)debugsel6 <<8));
}
__INLINE uint8_t spu_debug_2_debug_sel_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_DEBUG_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}
__INLINE void spu_debug_2_debug_sel_5_setf(uint8_t debugsel5)
{
	ASSERT_ERR((((uint32_t)debugsel5 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(SPU_DEBUG_2_ADDR, (REG_PL_RD(SPU_DEBUG_2_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)debugsel5 <<0));
}

/**
 * @brief P_6_X_6_CONF_0 register definition
 *  P 6x6 matrix elements 00 to 12 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 P6_X6_12                  0x0
 *    23:21 P6_X6_11                  0x0
 *    20:18 P6_X6_10                  0x0
 *    17:15 P6_X6_05                  0x0
 *    14:12 P6_X6_04                  0x0
 *    11:09 P6_X6_03                  0x0
 *    08:06 P6_X6_02                  0x0
 *    05:03 P6_X6_01                  0x0
 *    02:00 P6_X6_00                  0x0
 * </pre>
 */
#define SPU_P_6_X_6_CONF_0_ADDR        (REG_SPU_BASE_ADDR+0x00000030)
#define SPU_P_6_X_6_CONF_0_OFFSET      0x00000030
#define SPU_P_6_X_6_CONF_0_INDEX       0x0000000C
#define SPU_P_6_X_6_CONF_0_RESET       0x00000000

__INLINE uint32_t  spu_p_6_x_6_conf_0_get(void)
{
	return REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR);
}

__INLINE void spu_p_6_x_6_conf_0_set(uint32_t value)
{
	REG_PL_WR(SPU_P_6_X_6_CONF_0_ADDR, value);
}

// field definitions
#define SPU_P_6_X_6_CONF_0_P_6_X_6_12_MASK    ((uint32_t)0x07000000)
#define SPU_P_6_X_6_CONF_0_P_6_X_6_12_LSB    24
#define SPU_P_6_X_6_CONF_0_P_6_X_6_12_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_0_P_6_X_6_11_MASK    ((uint32_t)0x00E00000)
#define SPU_P_6_X_6_CONF_0_P_6_X_6_11_LSB    21
#define SPU_P_6_X_6_CONF_0_P_6_X_6_11_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_0_P_6_X_6_10_MASK    ((uint32_t)0x001C0000)
#define SPU_P_6_X_6_CONF_0_P_6_X_6_10_LSB    18
#define SPU_P_6_X_6_CONF_0_P_6_X_6_10_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_0_P_6_X_6_05_MASK    ((uint32_t)0x00038000)
#define SPU_P_6_X_6_CONF_0_P_6_X_6_05_LSB    15
#define SPU_P_6_X_6_CONF_0_P_6_X_6_05_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_0_P_6_X_6_04_MASK    ((uint32_t)0x00007000)
#define SPU_P_6_X_6_CONF_0_P_6_X_6_04_LSB    12
#define SPU_P_6_X_6_CONF_0_P_6_X_6_04_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_0_P_6_X_6_03_MASK    ((uint32_t)0x00000E00)
#define SPU_P_6_X_6_CONF_0_P_6_X_6_03_LSB    9
#define SPU_P_6_X_6_CONF_0_P_6_X_6_03_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_0_P_6_X_6_02_MASK    ((uint32_t)0x000001C0)
#define SPU_P_6_X_6_CONF_0_P_6_X_6_02_LSB    6
#define SPU_P_6_X_6_CONF_0_P_6_X_6_02_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_0_P_6_X_6_01_MASK    ((uint32_t)0x00000038)
#define SPU_P_6_X_6_CONF_0_P_6_X_6_01_LSB    3
#define SPU_P_6_X_6_CONF_0_P_6_X_6_01_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_0_P_6_X_6_00_MASK    ((uint32_t)0x00000007)
#define SPU_P_6_X_6_CONF_0_P_6_X_6_00_LSB    0
#define SPU_P_6_X_6_CONF_0_P_6_X_6_00_WIDTH    ((uint32_t)0x00000003)

#define SPU_P_6_X_6_CONF_0_P_6_X_6_12_RST    0x0
#define SPU_P_6_X_6_CONF_0_P_6_X_6_11_RST    0x0
#define SPU_P_6_X_6_CONF_0_P_6_X_6_10_RST    0x0
#define SPU_P_6_X_6_CONF_0_P_6_X_6_05_RST    0x0
#define SPU_P_6_X_6_CONF_0_P_6_X_6_04_RST    0x0
#define SPU_P_6_X_6_CONF_0_P_6_X_6_03_RST    0x0
#define SPU_P_6_X_6_CONF_0_P_6_X_6_02_RST    0x0
#define SPU_P_6_X_6_CONF_0_P_6_X_6_01_RST    0x0
#define SPU_P_6_X_6_CONF_0_P_6_X_6_00_RST    0x0

__INLINE void spu_p_6_x_6_conf_0_pack(uint8_t p6_x6_12, uint8_t p6_x6_11, uint8_t p6_x6_10, uint8_t p6_x6_05, uint8_t p6_x6_04, uint8_t p6_x6_03, uint8_t p6_x6_02, uint8_t p6_x6_01, uint8_t p6_x6_00)
{
	ASSERT_ERR((((uint32_t)p6_x6_12 << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_11 << 21) & ~((uint32_t)0x00E00000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_10 << 18) & ~((uint32_t)0x001C0000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_05 << 15) & ~((uint32_t)0x00038000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_04 << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_03 << 9) & ~((uint32_t)0x00000E00)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_02 << 6) & ~((uint32_t)0x000001C0)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_01 << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_00 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_0_ADDR,  ((uint32_t)p6_x6_12 << 24) |((uint32_t)p6_x6_11 << 21) |((uint32_t)p6_x6_10 << 18) |((uint32_t)p6_x6_05 << 15) |((uint32_t)p6_x6_04 << 12) |((uint32_t)p6_x6_03 << 9) |((uint32_t)p6_x6_02 << 6) |((uint32_t)p6_x6_01 << 3) |((uint32_t)p6_x6_00 << 0));
}

__INLINE void spu_p_6_x_6_conf_0_unpack(uint8_t* p6_x6_12, uint8_t* p6_x6_11, uint8_t* p6_x6_10, uint8_t* p6_x6_05, uint8_t* p6_x6_04, uint8_t* p6_x6_03, uint8_t* p6_x6_02, uint8_t* p6_x6_01, uint8_t* p6_x6_00)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR);

	*p6_x6_12 = (localVal & ((uint32_t)0x07000000)) >>  24;
	*p6_x6_11 = (localVal & ((uint32_t)0x00E00000)) >>  21;
	*p6_x6_10 = (localVal & ((uint32_t)0x001C0000)) >>  18;
	*p6_x6_05 = (localVal & ((uint32_t)0x00038000)) >>  15;
	*p6_x6_04 = (localVal & ((uint32_t)0x00007000)) >>  12;
	*p6_x6_03 = (localVal & ((uint32_t)0x00000E00)) >>  9;
	*p6_x6_02 = (localVal & ((uint32_t)0x000001C0)) >>  6;
	*p6_x6_01 = (localVal & ((uint32_t)0x00000038)) >>  3;
	*p6_x6_00 = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t spu_p_6_x_6_conf_0_p_6_x_6_12_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void spu_p_6_x_6_conf_0_p_6_x_6_12_setf(uint8_t p6x612)
{
	ASSERT_ERR((((uint32_t)p6x612 << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_0_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)p6x612 <<24));
}
__INLINE uint8_t spu_p_6_x_6_conf_0_p_6_x_6_11_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00E00000)) >> 21);
}
__INLINE void spu_p_6_x_6_conf_0_p_6_x_6_11_setf(uint8_t p6x611)
{
	ASSERT_ERR((((uint32_t)p6x611 << 21) & ~((uint32_t)0x00E00000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_0_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR) & ~((uint32_t)0x00E00000)) | ((uint32_t)p6x611 <<21));
}
__INLINE uint8_t spu_p_6_x_6_conf_0_p_6_x_6_10_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001C0000)) >> 18);
}
__INLINE void spu_p_6_x_6_conf_0_p_6_x_6_10_setf(uint8_t p6x610)
{
	ASSERT_ERR((((uint32_t)p6x610 << 18) & ~((uint32_t)0x001C0000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_0_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR) & ~((uint32_t)0x001C0000)) | ((uint32_t)p6x610 <<18));
}
__INLINE uint8_t spu_p_6_x_6_conf_0_p_6_x_6_05_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00038000)) >> 15);
}
__INLINE void spu_p_6_x_6_conf_0_p_6_x_6_05_setf(uint8_t p6x605)
{
	ASSERT_ERR((((uint32_t)p6x605 << 15) & ~((uint32_t)0x00038000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_0_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR) & ~((uint32_t)0x00038000)) | ((uint32_t)p6x605 <<15));
}
__INLINE uint8_t spu_p_6_x_6_conf_0_p_6_x_6_04_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void spu_p_6_x_6_conf_0_p_6_x_6_04_setf(uint8_t p6x604)
{
	ASSERT_ERR((((uint32_t)p6x604 << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_0_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)p6x604 <<12));
}
__INLINE uint8_t spu_p_6_x_6_conf_0_p_6_x_6_03_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000E00)) >> 9);
}
__INLINE void spu_p_6_x_6_conf_0_p_6_x_6_03_setf(uint8_t p6x603)
{
	ASSERT_ERR((((uint32_t)p6x603 << 9) & ~((uint32_t)0x00000E00)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_0_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR) & ~((uint32_t)0x00000E00)) | ((uint32_t)p6x603 <<9));
}
__INLINE uint8_t spu_p_6_x_6_conf_0_p_6_x_6_02_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000001C0)) >> 6);
}
__INLINE void spu_p_6_x_6_conf_0_p_6_x_6_02_setf(uint8_t p6x602)
{
	ASSERT_ERR((((uint32_t)p6x602 << 6) & ~((uint32_t)0x000001C0)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_0_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR) & ~((uint32_t)0x000001C0)) | ((uint32_t)p6x602 <<6));
}
__INLINE uint8_t spu_p_6_x_6_conf_0_p_6_x_6_01_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void spu_p_6_x_6_conf_0_p_6_x_6_01_setf(uint8_t p6x601)
{
	ASSERT_ERR((((uint32_t)p6x601 << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_0_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)p6x601 <<3));
}
__INLINE uint8_t spu_p_6_x_6_conf_0_p_6_x_6_00_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void spu_p_6_x_6_conf_0_p_6_x_6_00_setf(uint8_t p6x600)
{
	ASSERT_ERR((((uint32_t)p6x600 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_0_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_0_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)p6x600 <<0));
}

/**
 * @brief P_6_X_6_CONF_1 register definition
 *  P 6x6 matrix elements 13 to 25 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 P6_X6_25                  0x0
 *    23:21 P6_X6_24                  0x0
 *    20:18 P6_X6_23                  0x0
 *    17:15 P6_X6_22                  0x0
 *    14:12 P6_X6_21                  0x0
 *    11:09 P6_X6_20                  0x0
 *    08:06 P6_X6_15                  0x0
 *    05:03 P6_X6_14                  0x0
 *    02:00 P6_X6_13                  0x0
 * </pre>
 */
#define SPU_P_6_X_6_CONF_1_ADDR        (REG_SPU_BASE_ADDR+0x00000034)
#define SPU_P_6_X_6_CONF_1_OFFSET      0x00000034
#define SPU_P_6_X_6_CONF_1_INDEX       0x0000000D
#define SPU_P_6_X_6_CONF_1_RESET       0x00000000

__INLINE uint32_t  spu_p_6_x_6_conf_1_get(void)
{
	return REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR);
}

__INLINE void spu_p_6_x_6_conf_1_set(uint32_t value)
{
	REG_PL_WR(SPU_P_6_X_6_CONF_1_ADDR, value);
}

// field definitions
#define SPU_P_6_X_6_CONF_1_P_6_X_6_25_MASK    ((uint32_t)0x07000000)
#define SPU_P_6_X_6_CONF_1_P_6_X_6_25_LSB    24
#define SPU_P_6_X_6_CONF_1_P_6_X_6_25_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_1_P_6_X_6_24_MASK    ((uint32_t)0x00E00000)
#define SPU_P_6_X_6_CONF_1_P_6_X_6_24_LSB    21
#define SPU_P_6_X_6_CONF_1_P_6_X_6_24_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_1_P_6_X_6_23_MASK    ((uint32_t)0x001C0000)
#define SPU_P_6_X_6_CONF_1_P_6_X_6_23_LSB    18
#define SPU_P_6_X_6_CONF_1_P_6_X_6_23_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_1_P_6_X_6_22_MASK    ((uint32_t)0x00038000)
#define SPU_P_6_X_6_CONF_1_P_6_X_6_22_LSB    15
#define SPU_P_6_X_6_CONF_1_P_6_X_6_22_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_1_P_6_X_6_21_MASK    ((uint32_t)0x00007000)
#define SPU_P_6_X_6_CONF_1_P_6_X_6_21_LSB    12
#define SPU_P_6_X_6_CONF_1_P_6_X_6_21_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_1_P_6_X_6_20_MASK    ((uint32_t)0x00000E00)
#define SPU_P_6_X_6_CONF_1_P_6_X_6_20_LSB    9
#define SPU_P_6_X_6_CONF_1_P_6_X_6_20_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_1_P_6_X_6_15_MASK    ((uint32_t)0x000001C0)
#define SPU_P_6_X_6_CONF_1_P_6_X_6_15_LSB    6
#define SPU_P_6_X_6_CONF_1_P_6_X_6_15_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_1_P_6_X_6_14_MASK    ((uint32_t)0x00000038)
#define SPU_P_6_X_6_CONF_1_P_6_X_6_14_LSB    3
#define SPU_P_6_X_6_CONF_1_P_6_X_6_14_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_1_P_6_X_6_13_MASK    ((uint32_t)0x00000007)
#define SPU_P_6_X_6_CONF_1_P_6_X_6_13_LSB    0
#define SPU_P_6_X_6_CONF_1_P_6_X_6_13_WIDTH    ((uint32_t)0x00000003)

#define SPU_P_6_X_6_CONF_1_P_6_X_6_25_RST    0x0
#define SPU_P_6_X_6_CONF_1_P_6_X_6_24_RST    0x0
#define SPU_P_6_X_6_CONF_1_P_6_X_6_23_RST    0x0
#define SPU_P_6_X_6_CONF_1_P_6_X_6_22_RST    0x0
#define SPU_P_6_X_6_CONF_1_P_6_X_6_21_RST    0x0
#define SPU_P_6_X_6_CONF_1_P_6_X_6_20_RST    0x0
#define SPU_P_6_X_6_CONF_1_P_6_X_6_15_RST    0x0
#define SPU_P_6_X_6_CONF_1_P_6_X_6_14_RST    0x0
#define SPU_P_6_X_6_CONF_1_P_6_X_6_13_RST    0x0

__INLINE void spu_p_6_x_6_conf_1_pack(uint8_t p6_x6_25, uint8_t p6_x6_24, uint8_t p6_x6_23, uint8_t p6_x6_22, uint8_t p6_x6_21, uint8_t p6_x6_20, uint8_t p6_x6_15, uint8_t p6_x6_14, uint8_t p6_x6_13)
{
	ASSERT_ERR((((uint32_t)p6_x6_25 << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_24 << 21) & ~((uint32_t)0x00E00000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_23 << 18) & ~((uint32_t)0x001C0000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_22 << 15) & ~((uint32_t)0x00038000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_21 << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_20 << 9) & ~((uint32_t)0x00000E00)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_15 << 6) & ~((uint32_t)0x000001C0)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_14 << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_13 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_1_ADDR,  ((uint32_t)p6_x6_25 << 24) |((uint32_t)p6_x6_24 << 21) |((uint32_t)p6_x6_23 << 18) |((uint32_t)p6_x6_22 << 15) |((uint32_t)p6_x6_21 << 12) |((uint32_t)p6_x6_20 << 9) |((uint32_t)p6_x6_15 << 6) |((uint32_t)p6_x6_14 << 3) |((uint32_t)p6_x6_13 << 0));
}

__INLINE void spu_p_6_x_6_conf_1_unpack(uint8_t* p6_x6_25, uint8_t* p6_x6_24, uint8_t* p6_x6_23, uint8_t* p6_x6_22, uint8_t* p6_x6_21, uint8_t* p6_x6_20, uint8_t* p6_x6_15, uint8_t* p6_x6_14, uint8_t* p6_x6_13)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR);

	*p6_x6_25 = (localVal & ((uint32_t)0x07000000)) >>  24;
	*p6_x6_24 = (localVal & ((uint32_t)0x00E00000)) >>  21;
	*p6_x6_23 = (localVal & ((uint32_t)0x001C0000)) >>  18;
	*p6_x6_22 = (localVal & ((uint32_t)0x00038000)) >>  15;
	*p6_x6_21 = (localVal & ((uint32_t)0x00007000)) >>  12;
	*p6_x6_20 = (localVal & ((uint32_t)0x00000E00)) >>  9;
	*p6_x6_15 = (localVal & ((uint32_t)0x000001C0)) >>  6;
	*p6_x6_14 = (localVal & ((uint32_t)0x00000038)) >>  3;
	*p6_x6_13 = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t spu_p_6_x_6_conf_1_p_6_x_6_25_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void spu_p_6_x_6_conf_1_p_6_x_6_25_setf(uint8_t p6x625)
{
	ASSERT_ERR((((uint32_t)p6x625 << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_1_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)p6x625 <<24));
}
__INLINE uint8_t spu_p_6_x_6_conf_1_p_6_x_6_24_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00E00000)) >> 21);
}
__INLINE void spu_p_6_x_6_conf_1_p_6_x_6_24_setf(uint8_t p6x624)
{
	ASSERT_ERR((((uint32_t)p6x624 << 21) & ~((uint32_t)0x00E00000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_1_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR) & ~((uint32_t)0x00E00000)) | ((uint32_t)p6x624 <<21));
}
__INLINE uint8_t spu_p_6_x_6_conf_1_p_6_x_6_23_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001C0000)) >> 18);
}
__INLINE void spu_p_6_x_6_conf_1_p_6_x_6_23_setf(uint8_t p6x623)
{
	ASSERT_ERR((((uint32_t)p6x623 << 18) & ~((uint32_t)0x001C0000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_1_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR) & ~((uint32_t)0x001C0000)) | ((uint32_t)p6x623 <<18));
}
__INLINE uint8_t spu_p_6_x_6_conf_1_p_6_x_6_22_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00038000)) >> 15);
}
__INLINE void spu_p_6_x_6_conf_1_p_6_x_6_22_setf(uint8_t p6x622)
{
	ASSERT_ERR((((uint32_t)p6x622 << 15) & ~((uint32_t)0x00038000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_1_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR) & ~((uint32_t)0x00038000)) | ((uint32_t)p6x622 <<15));
}
__INLINE uint8_t spu_p_6_x_6_conf_1_p_6_x_6_21_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void spu_p_6_x_6_conf_1_p_6_x_6_21_setf(uint8_t p6x621)
{
	ASSERT_ERR((((uint32_t)p6x621 << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_1_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)p6x621 <<12));
}
__INLINE uint8_t spu_p_6_x_6_conf_1_p_6_x_6_20_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000E00)) >> 9);
}
__INLINE void spu_p_6_x_6_conf_1_p_6_x_6_20_setf(uint8_t p6x620)
{
	ASSERT_ERR((((uint32_t)p6x620 << 9) & ~((uint32_t)0x00000E00)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_1_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR) & ~((uint32_t)0x00000E00)) | ((uint32_t)p6x620 <<9));
}
__INLINE uint8_t spu_p_6_x_6_conf_1_p_6_x_6_15_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000001C0)) >> 6);
}
__INLINE void spu_p_6_x_6_conf_1_p_6_x_6_15_setf(uint8_t p6x615)
{
	ASSERT_ERR((((uint32_t)p6x615 << 6) & ~((uint32_t)0x000001C0)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_1_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR) & ~((uint32_t)0x000001C0)) | ((uint32_t)p6x615 <<6));
}
__INLINE uint8_t spu_p_6_x_6_conf_1_p_6_x_6_14_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void spu_p_6_x_6_conf_1_p_6_x_6_14_setf(uint8_t p6x614)
{
	ASSERT_ERR((((uint32_t)p6x614 << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_1_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)p6x614 <<3));
}
__INLINE uint8_t spu_p_6_x_6_conf_1_p_6_x_6_13_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void spu_p_6_x_6_conf_1_p_6_x_6_13_setf(uint8_t p6x613)
{
	ASSERT_ERR((((uint32_t)p6x613 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_1_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_1_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)p6x613 <<0));
}

/**
 * @brief P_6_X_6_CONF_2 register definition
 *  P 6x6 matrix elements 30 to 42 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 P6_X6_42                  0x0
 *    23:21 P6_X6_41                  0x0
 *    20:18 P6_X6_40                  0x0
 *    17:15 P6_X6_35                  0x0
 *    14:12 P6_X6_34                  0x0
 *    11:09 P6_X6_33                  0x0
 *    08:06 P6_X6_32                  0x0
 *    05:03 P6_X6_31                  0x0
 *    02:00 P6_X6_30                  0x0
 * </pre>
 */
#define SPU_P_6_X_6_CONF_2_ADDR        (REG_SPU_BASE_ADDR+0x00000038)
#define SPU_P_6_X_6_CONF_2_OFFSET      0x00000038
#define SPU_P_6_X_6_CONF_2_INDEX       0x0000000E
#define SPU_P_6_X_6_CONF_2_RESET       0x00000000

__INLINE uint32_t  spu_p_6_x_6_conf_2_get(void)
{
	return REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR);
}

__INLINE void spu_p_6_x_6_conf_2_set(uint32_t value)
{
	REG_PL_WR(SPU_P_6_X_6_CONF_2_ADDR, value);
}

// field definitions
#define SPU_P_6_X_6_CONF_2_P_6_X_6_42_MASK    ((uint32_t)0x07000000)
#define SPU_P_6_X_6_CONF_2_P_6_X_6_42_LSB    24
#define SPU_P_6_X_6_CONF_2_P_6_X_6_42_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_2_P_6_X_6_41_MASK    ((uint32_t)0x00E00000)
#define SPU_P_6_X_6_CONF_2_P_6_X_6_41_LSB    21
#define SPU_P_6_X_6_CONF_2_P_6_X_6_41_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_2_P_6_X_6_40_MASK    ((uint32_t)0x001C0000)
#define SPU_P_6_X_6_CONF_2_P_6_X_6_40_LSB    18
#define SPU_P_6_X_6_CONF_2_P_6_X_6_40_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_2_P_6_X_6_35_MASK    ((uint32_t)0x00038000)
#define SPU_P_6_X_6_CONF_2_P_6_X_6_35_LSB    15
#define SPU_P_6_X_6_CONF_2_P_6_X_6_35_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_2_P_6_X_6_34_MASK    ((uint32_t)0x00007000)
#define SPU_P_6_X_6_CONF_2_P_6_X_6_34_LSB    12
#define SPU_P_6_X_6_CONF_2_P_6_X_6_34_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_2_P_6_X_6_33_MASK    ((uint32_t)0x00000E00)
#define SPU_P_6_X_6_CONF_2_P_6_X_6_33_LSB    9
#define SPU_P_6_X_6_CONF_2_P_6_X_6_33_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_2_P_6_X_6_32_MASK    ((uint32_t)0x000001C0)
#define SPU_P_6_X_6_CONF_2_P_6_X_6_32_LSB    6
#define SPU_P_6_X_6_CONF_2_P_6_X_6_32_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_2_P_6_X_6_31_MASK    ((uint32_t)0x00000038)
#define SPU_P_6_X_6_CONF_2_P_6_X_6_31_LSB    3
#define SPU_P_6_X_6_CONF_2_P_6_X_6_31_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_2_P_6_X_6_30_MASK    ((uint32_t)0x00000007)
#define SPU_P_6_X_6_CONF_2_P_6_X_6_30_LSB    0
#define SPU_P_6_X_6_CONF_2_P_6_X_6_30_WIDTH    ((uint32_t)0x00000003)

#define SPU_P_6_X_6_CONF_2_P_6_X_6_42_RST    0x0
#define SPU_P_6_X_6_CONF_2_P_6_X_6_41_RST    0x0
#define SPU_P_6_X_6_CONF_2_P_6_X_6_40_RST    0x0
#define SPU_P_6_X_6_CONF_2_P_6_X_6_35_RST    0x0
#define SPU_P_6_X_6_CONF_2_P_6_X_6_34_RST    0x0
#define SPU_P_6_X_6_CONF_2_P_6_X_6_33_RST    0x0
#define SPU_P_6_X_6_CONF_2_P_6_X_6_32_RST    0x0
#define SPU_P_6_X_6_CONF_2_P_6_X_6_31_RST    0x0
#define SPU_P_6_X_6_CONF_2_P_6_X_6_30_RST    0x0

__INLINE void spu_p_6_x_6_conf_2_pack(uint8_t p6_x6_42, uint8_t p6_x6_41, uint8_t p6_x6_40, uint8_t p6_x6_35, uint8_t p6_x6_34, uint8_t p6_x6_33, uint8_t p6_x6_32, uint8_t p6_x6_31, uint8_t p6_x6_30)
{
	ASSERT_ERR((((uint32_t)p6_x6_42 << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_41 << 21) & ~((uint32_t)0x00E00000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_40 << 18) & ~((uint32_t)0x001C0000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_35 << 15) & ~((uint32_t)0x00038000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_34 << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_33 << 9) & ~((uint32_t)0x00000E00)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_32 << 6) & ~((uint32_t)0x000001C0)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_31 << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_30 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_2_ADDR,  ((uint32_t)p6_x6_42 << 24) |((uint32_t)p6_x6_41 << 21) |((uint32_t)p6_x6_40 << 18) |((uint32_t)p6_x6_35 << 15) |((uint32_t)p6_x6_34 << 12) |((uint32_t)p6_x6_33 << 9) |((uint32_t)p6_x6_32 << 6) |((uint32_t)p6_x6_31 << 3) |((uint32_t)p6_x6_30 << 0));
}

__INLINE void spu_p_6_x_6_conf_2_unpack(uint8_t* p6_x6_42, uint8_t* p6_x6_41, uint8_t* p6_x6_40, uint8_t* p6_x6_35, uint8_t* p6_x6_34, uint8_t* p6_x6_33, uint8_t* p6_x6_32, uint8_t* p6_x6_31, uint8_t* p6_x6_30)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR);

	*p6_x6_42 = (localVal & ((uint32_t)0x07000000)) >>  24;
	*p6_x6_41 = (localVal & ((uint32_t)0x00E00000)) >>  21;
	*p6_x6_40 = (localVal & ((uint32_t)0x001C0000)) >>  18;
	*p6_x6_35 = (localVal & ((uint32_t)0x00038000)) >>  15;
	*p6_x6_34 = (localVal & ((uint32_t)0x00007000)) >>  12;
	*p6_x6_33 = (localVal & ((uint32_t)0x00000E00)) >>  9;
	*p6_x6_32 = (localVal & ((uint32_t)0x000001C0)) >>  6;
	*p6_x6_31 = (localVal & ((uint32_t)0x00000038)) >>  3;
	*p6_x6_30 = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t spu_p_6_x_6_conf_2_p_6_x_6_42_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void spu_p_6_x_6_conf_2_p_6_x_6_42_setf(uint8_t p6x642)
{
	ASSERT_ERR((((uint32_t)p6x642 << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_2_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)p6x642 <<24));
}
__INLINE uint8_t spu_p_6_x_6_conf_2_p_6_x_6_41_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00E00000)) >> 21);
}
__INLINE void spu_p_6_x_6_conf_2_p_6_x_6_41_setf(uint8_t p6x641)
{
	ASSERT_ERR((((uint32_t)p6x641 << 21) & ~((uint32_t)0x00E00000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_2_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR) & ~((uint32_t)0x00E00000)) | ((uint32_t)p6x641 <<21));
}
__INLINE uint8_t spu_p_6_x_6_conf_2_p_6_x_6_40_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001C0000)) >> 18);
}
__INLINE void spu_p_6_x_6_conf_2_p_6_x_6_40_setf(uint8_t p6x640)
{
	ASSERT_ERR((((uint32_t)p6x640 << 18) & ~((uint32_t)0x001C0000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_2_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR) & ~((uint32_t)0x001C0000)) | ((uint32_t)p6x640 <<18));
}
__INLINE uint8_t spu_p_6_x_6_conf_2_p_6_x_6_35_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00038000)) >> 15);
}
__INLINE void spu_p_6_x_6_conf_2_p_6_x_6_35_setf(uint8_t p6x635)
{
	ASSERT_ERR((((uint32_t)p6x635 << 15) & ~((uint32_t)0x00038000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_2_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR) & ~((uint32_t)0x00038000)) | ((uint32_t)p6x635 <<15));
}
__INLINE uint8_t spu_p_6_x_6_conf_2_p_6_x_6_34_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void spu_p_6_x_6_conf_2_p_6_x_6_34_setf(uint8_t p6x634)
{
	ASSERT_ERR((((uint32_t)p6x634 << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_2_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)p6x634 <<12));
}
__INLINE uint8_t spu_p_6_x_6_conf_2_p_6_x_6_33_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000E00)) >> 9);
}
__INLINE void spu_p_6_x_6_conf_2_p_6_x_6_33_setf(uint8_t p6x633)
{
	ASSERT_ERR((((uint32_t)p6x633 << 9) & ~((uint32_t)0x00000E00)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_2_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR) & ~((uint32_t)0x00000E00)) | ((uint32_t)p6x633 <<9));
}
__INLINE uint8_t spu_p_6_x_6_conf_2_p_6_x_6_32_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000001C0)) >> 6);
}
__INLINE void spu_p_6_x_6_conf_2_p_6_x_6_32_setf(uint8_t p6x632)
{
	ASSERT_ERR((((uint32_t)p6x632 << 6) & ~((uint32_t)0x000001C0)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_2_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR) & ~((uint32_t)0x000001C0)) | ((uint32_t)p6x632 <<6));
}
__INLINE uint8_t spu_p_6_x_6_conf_2_p_6_x_6_31_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void spu_p_6_x_6_conf_2_p_6_x_6_31_setf(uint8_t p6x631)
{
	ASSERT_ERR((((uint32_t)p6x631 << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_2_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)p6x631 <<3));
}
__INLINE uint8_t spu_p_6_x_6_conf_2_p_6_x_6_30_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void spu_p_6_x_6_conf_2_p_6_x_6_30_setf(uint8_t p6x630)
{
	ASSERT_ERR((((uint32_t)p6x630 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_2_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_2_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)p6x630 <<0));
}

/**
 * @brief P_6_X_6_CONF_3 register definition
 *  P 6x6 matrix elements 43 to 55 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 P6_X6_55                  0x0
 *    23:21 P6_X6_54                  0x0
 *    20:18 P6_X6_53                  0x0
 *    17:15 P6_X6_52                  0x0
 *    14:12 P6_X6_51                  0x0
 *    11:09 P6_X6_50                  0x0
 *    08:06 P6_X6_45                  0x0
 *    05:03 P6_X6_44                  0x0
 *    02:00 P6_X6_43                  0x0
 * </pre>
 */
#define SPU_P_6_X_6_CONF_3_ADDR        (REG_SPU_BASE_ADDR+0x0000003C)
#define SPU_P_6_X_6_CONF_3_OFFSET      0x0000003C
#define SPU_P_6_X_6_CONF_3_INDEX       0x0000000F
#define SPU_P_6_X_6_CONF_3_RESET       0x00000000

__INLINE uint32_t  spu_p_6_x_6_conf_3_get(void)
{
	return REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR);
}

__INLINE void spu_p_6_x_6_conf_3_set(uint32_t value)
{
	REG_PL_WR(SPU_P_6_X_6_CONF_3_ADDR, value);
}

// field definitions
#define SPU_P_6_X_6_CONF_3_P_6_X_6_55_MASK    ((uint32_t)0x07000000)
#define SPU_P_6_X_6_CONF_3_P_6_X_6_55_LSB    24
#define SPU_P_6_X_6_CONF_3_P_6_X_6_55_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_3_P_6_X_6_54_MASK    ((uint32_t)0x00E00000)
#define SPU_P_6_X_6_CONF_3_P_6_X_6_54_LSB    21
#define SPU_P_6_X_6_CONF_3_P_6_X_6_54_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_3_P_6_X_6_53_MASK    ((uint32_t)0x001C0000)
#define SPU_P_6_X_6_CONF_3_P_6_X_6_53_LSB    18
#define SPU_P_6_X_6_CONF_3_P_6_X_6_53_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_3_P_6_X_6_52_MASK    ((uint32_t)0x00038000)
#define SPU_P_6_X_6_CONF_3_P_6_X_6_52_LSB    15
#define SPU_P_6_X_6_CONF_3_P_6_X_6_52_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_3_P_6_X_6_51_MASK    ((uint32_t)0x00007000)
#define SPU_P_6_X_6_CONF_3_P_6_X_6_51_LSB    12
#define SPU_P_6_X_6_CONF_3_P_6_X_6_51_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_3_P_6_X_6_50_MASK    ((uint32_t)0x00000E00)
#define SPU_P_6_X_6_CONF_3_P_6_X_6_50_LSB    9
#define SPU_P_6_X_6_CONF_3_P_6_X_6_50_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_3_P_6_X_6_45_MASK    ((uint32_t)0x000001C0)
#define SPU_P_6_X_6_CONF_3_P_6_X_6_45_LSB    6
#define SPU_P_6_X_6_CONF_3_P_6_X_6_45_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_3_P_6_X_6_44_MASK    ((uint32_t)0x00000038)
#define SPU_P_6_X_6_CONF_3_P_6_X_6_44_LSB    3
#define SPU_P_6_X_6_CONF_3_P_6_X_6_44_WIDTH    ((uint32_t)0x00000003)
#define SPU_P_6_X_6_CONF_3_P_6_X_6_43_MASK    ((uint32_t)0x00000007)
#define SPU_P_6_X_6_CONF_3_P_6_X_6_43_LSB    0
#define SPU_P_6_X_6_CONF_3_P_6_X_6_43_WIDTH    ((uint32_t)0x00000003)

#define SPU_P_6_X_6_CONF_3_P_6_X_6_55_RST    0x0
#define SPU_P_6_X_6_CONF_3_P_6_X_6_54_RST    0x0
#define SPU_P_6_X_6_CONF_3_P_6_X_6_53_RST    0x0
#define SPU_P_6_X_6_CONF_3_P_6_X_6_52_RST    0x0
#define SPU_P_6_X_6_CONF_3_P_6_X_6_51_RST    0x0
#define SPU_P_6_X_6_CONF_3_P_6_X_6_50_RST    0x0
#define SPU_P_6_X_6_CONF_3_P_6_X_6_45_RST    0x0
#define SPU_P_6_X_6_CONF_3_P_6_X_6_44_RST    0x0
#define SPU_P_6_X_6_CONF_3_P_6_X_6_43_RST    0x0

__INLINE void spu_p_6_x_6_conf_3_pack(uint8_t p6_x6_55, uint8_t p6_x6_54, uint8_t p6_x6_53, uint8_t p6_x6_52, uint8_t p6_x6_51, uint8_t p6_x6_50, uint8_t p6_x6_45, uint8_t p6_x6_44, uint8_t p6_x6_43)
{
	ASSERT_ERR((((uint32_t)p6_x6_55 << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_54 << 21) & ~((uint32_t)0x00E00000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_53 << 18) & ~((uint32_t)0x001C0000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_52 << 15) & ~((uint32_t)0x00038000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_51 << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_50 << 9) & ~((uint32_t)0x00000E00)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_45 << 6) & ~((uint32_t)0x000001C0)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_44 << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)p6_x6_43 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_3_ADDR,  ((uint32_t)p6_x6_55 << 24) |((uint32_t)p6_x6_54 << 21) |((uint32_t)p6_x6_53 << 18) |((uint32_t)p6_x6_52 << 15) |((uint32_t)p6_x6_51 << 12) |((uint32_t)p6_x6_50 << 9) |((uint32_t)p6_x6_45 << 6) |((uint32_t)p6_x6_44 << 3) |((uint32_t)p6_x6_43 << 0));
}

__INLINE void spu_p_6_x_6_conf_3_unpack(uint8_t* p6_x6_55, uint8_t* p6_x6_54, uint8_t* p6_x6_53, uint8_t* p6_x6_52, uint8_t* p6_x6_51, uint8_t* p6_x6_50, uint8_t* p6_x6_45, uint8_t* p6_x6_44, uint8_t* p6_x6_43)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR);

	*p6_x6_55 = (localVal & ((uint32_t)0x07000000)) >>  24;
	*p6_x6_54 = (localVal & ((uint32_t)0x00E00000)) >>  21;
	*p6_x6_53 = (localVal & ((uint32_t)0x001C0000)) >>  18;
	*p6_x6_52 = (localVal & ((uint32_t)0x00038000)) >>  15;
	*p6_x6_51 = (localVal & ((uint32_t)0x00007000)) >>  12;
	*p6_x6_50 = (localVal & ((uint32_t)0x00000E00)) >>  9;
	*p6_x6_45 = (localVal & ((uint32_t)0x000001C0)) >>  6;
	*p6_x6_44 = (localVal & ((uint32_t)0x00000038)) >>  3;
	*p6_x6_43 = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t spu_p_6_x_6_conf_3_p_6_x_6_55_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void spu_p_6_x_6_conf_3_p_6_x_6_55_setf(uint8_t p6x655)
{
	ASSERT_ERR((((uint32_t)p6x655 << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_3_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)p6x655 <<24));
}
__INLINE uint8_t spu_p_6_x_6_conf_3_p_6_x_6_54_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00E00000)) >> 21);
}
__INLINE void spu_p_6_x_6_conf_3_p_6_x_6_54_setf(uint8_t p6x654)
{
	ASSERT_ERR((((uint32_t)p6x654 << 21) & ~((uint32_t)0x00E00000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_3_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR) & ~((uint32_t)0x00E00000)) | ((uint32_t)p6x654 <<21));
}
__INLINE uint8_t spu_p_6_x_6_conf_3_p_6_x_6_53_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001C0000)) >> 18);
}
__INLINE void spu_p_6_x_6_conf_3_p_6_x_6_53_setf(uint8_t p6x653)
{
	ASSERT_ERR((((uint32_t)p6x653 << 18) & ~((uint32_t)0x001C0000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_3_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR) & ~((uint32_t)0x001C0000)) | ((uint32_t)p6x653 <<18));
}
__INLINE uint8_t spu_p_6_x_6_conf_3_p_6_x_6_52_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00038000)) >> 15);
}
__INLINE void spu_p_6_x_6_conf_3_p_6_x_6_52_setf(uint8_t p6x652)
{
	ASSERT_ERR((((uint32_t)p6x652 << 15) & ~((uint32_t)0x00038000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_3_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR) & ~((uint32_t)0x00038000)) | ((uint32_t)p6x652 <<15));
}
__INLINE uint8_t spu_p_6_x_6_conf_3_p_6_x_6_51_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void spu_p_6_x_6_conf_3_p_6_x_6_51_setf(uint8_t p6x651)
{
	ASSERT_ERR((((uint32_t)p6x651 << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_3_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)p6x651 <<12));
}
__INLINE uint8_t spu_p_6_x_6_conf_3_p_6_x_6_50_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000E00)) >> 9);
}
__INLINE void spu_p_6_x_6_conf_3_p_6_x_6_50_setf(uint8_t p6x650)
{
	ASSERT_ERR((((uint32_t)p6x650 << 9) & ~((uint32_t)0x00000E00)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_3_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR) & ~((uint32_t)0x00000E00)) | ((uint32_t)p6x650 <<9));
}
__INLINE uint8_t spu_p_6_x_6_conf_3_p_6_x_6_45_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000001C0)) >> 6);
}
__INLINE void spu_p_6_x_6_conf_3_p_6_x_6_45_setf(uint8_t p6x645)
{
	ASSERT_ERR((((uint32_t)p6x645 << 6) & ~((uint32_t)0x000001C0)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_3_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR) & ~((uint32_t)0x000001C0)) | ((uint32_t)p6x645 <<6));
}
__INLINE uint8_t spu_p_6_x_6_conf_3_p_6_x_6_44_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE void spu_p_6_x_6_conf_3_p_6_x_6_44_setf(uint8_t p6x644)
{
	ASSERT_ERR((((uint32_t)p6x644 << 3) & ~((uint32_t)0x00000038)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_3_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR) & ~((uint32_t)0x00000038)) | ((uint32_t)p6x644 <<3));
}
__INLINE uint8_t spu_p_6_x_6_conf_3_p_6_x_6_43_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void spu_p_6_x_6_conf_3_p_6_x_6_43_setf(uint8_t p6x643)
{
	ASSERT_ERR((((uint32_t)p6x643 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(SPU_P_6_X_6_CONF_3_ADDR, (REG_PL_RD(SPU_P_6_X_6_CONF_3_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)p6x643 <<0));
}

/**
 * @brief INT_STAT_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03:00 INT_STAT_EN               0x0
 * </pre>
 */
#define SPU_INT_STAT_EN_ADDR        (REG_SPU_BASE_ADDR+0x00000040)
#define SPU_INT_STAT_EN_OFFSET      0x00000040
#define SPU_INT_STAT_EN_INDEX       0x00000010
#define SPU_INT_STAT_EN_RESET       0x00000000

__INLINE uint32_t  spu_int_stat_en_get(void)
{
	return REG_PL_RD(SPU_INT_STAT_EN_ADDR);
}

__INLINE void spu_int_stat_en_set(uint32_t value)
{
	REG_PL_WR(SPU_INT_STAT_EN_ADDR, value);
}

// field definitions
#define SPU_INT_STAT_EN_INT_STAT_EN_MASK    ((uint32_t)0x0000000F)
#define SPU_INT_STAT_EN_INT_STAT_EN_LSB     0
#define SPU_INT_STAT_EN_INT_STAT_EN_WIDTH    ((uint32_t)0x00000004)

#define SPU_INT_STAT_EN_INT_STAT_EN_RST     0x0

__INLINE uint8_t spu_int_stat_en_int_stat_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_INT_STAT_EN_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void spu_int_stat_en_int_stat_en_setf(uint8_t intstaten)
{
	ASSERT_ERR((((uint32_t)intstaten << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(SPU_INT_STAT_EN_ADDR, (uint32_t)intstaten << 0);
}

/**
 * @brief RX_STAT_DBG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:20 TFU_SC_INDEX              0x0
 *    19:18 TFU_FOB_BUF_SEL           0x0
 *    17    STALL                     1              
 *    16    LAST_SC_IN_RU             0              
 *    14:06 SYM_CNT                   0x0
 *    05:03 RU_NUM                    0x0
 *    02:00 RX_CTL_STATE              0x0
 * </pre>
 */
#define SPU_RX_STAT_DBG_1_ADDR        (REG_SPU_BASE_ADDR+0x00000050)
#define SPU_RX_STAT_DBG_1_OFFSET      0x00000050
#define SPU_RX_STAT_DBG_1_INDEX       0x00000014
#define SPU_RX_STAT_DBG_1_RESET       0x00020000

__INLINE uint32_t  spu_rx_stat_dbg_1_get(void)
{
	return REG_PL_RD(SPU_RX_STAT_DBG_1_ADDR);
}

// field definitions
#define SPU_RX_STAT_DBG_1_TFU_SC_INDEX_MASK    ((uint32_t)0x7FF00000)
#define SPU_RX_STAT_DBG_1_TFU_SC_INDEX_LSB    20
#define SPU_RX_STAT_DBG_1_TFU_SC_INDEX_WIDTH    ((uint32_t)0x0000000B)
#define SPU_RX_STAT_DBG_1_TFU_FOB_BUF_SEL_MASK    ((uint32_t)0x000C0000)
#define SPU_RX_STAT_DBG_1_TFU_FOB_BUF_SEL_LSB    18
#define SPU_RX_STAT_DBG_1_TFU_FOB_BUF_SEL_WIDTH    ((uint32_t)0x00000002)
#define SPU_RX_STAT_DBG_1_STALL_BIT         ((uint32_t)0x00020000)
#define SPU_RX_STAT_DBG_1_STALL_POS         17
#define SPU_RX_STAT_DBG_1_LAST_SC_IN_RU_BIT    ((uint32_t)0x00010000)
#define SPU_RX_STAT_DBG_1_LAST_SC_IN_RU_POS    16
#define SPU_RX_STAT_DBG_1_SYM_CNT_MASK      ((uint32_t)0x00007FC0)
#define SPU_RX_STAT_DBG_1_SYM_CNT_LSB       6
#define SPU_RX_STAT_DBG_1_SYM_CNT_WIDTH     ((uint32_t)0x00000009)
#define SPU_RX_STAT_DBG_1_RU_NUM_MASK       ((uint32_t)0x00000038)
#define SPU_RX_STAT_DBG_1_RU_NUM_LSB        3
#define SPU_RX_STAT_DBG_1_RU_NUM_WIDTH      ((uint32_t)0x00000003)
#define SPU_RX_STAT_DBG_1_RX_CTL_STATE_MASK    ((uint32_t)0x00000007)
#define SPU_RX_STAT_DBG_1_RX_CTL_STATE_LSB    0
#define SPU_RX_STAT_DBG_1_RX_CTL_STATE_WIDTH    ((uint32_t)0x00000003)

#define SPU_RX_STAT_DBG_1_TFU_SC_INDEX_RST    0x0
#define SPU_RX_STAT_DBG_1_TFU_FOB_BUF_SEL_RST    0x0
#define SPU_RX_STAT_DBG_1_STALL_RST         0x1
#define SPU_RX_STAT_DBG_1_LAST_SC_IN_RU_RST    0x0
#define SPU_RX_STAT_DBG_1_SYM_CNT_RST       0x0
#define SPU_RX_STAT_DBG_1_RU_NUM_RST        0x0
#define SPU_RX_STAT_DBG_1_RX_CTL_STATE_RST    0x0

__INLINE void spu_rx_stat_dbg_1_unpack(uint16_t* tfu_sc_index, uint8_t* tfu_fob_buf_sel, uint8_t* stall, uint8_t* last_sc_in_ru, uint16_t* sym_cnt, uint8_t* ru_num, uint8_t* rx_ctl_state)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_STAT_DBG_1_ADDR);

	*tfu_sc_index = (localVal & ((uint32_t)0x7FF00000)) >>  20;
	*tfu_fob_buf_sel = (localVal & ((uint32_t)0x000C0000)) >>  18;
	*stall = (localVal & ((uint32_t)0x00020000)) >>  17;
	*last_sc_in_ru = (localVal & ((uint32_t)0x00010000)) >>  16;
	*sym_cnt = (localVal & ((uint32_t)0x00007FC0)) >>  6;
	*ru_num = (localVal & ((uint32_t)0x00000038)) >>  3;
	*rx_ctl_state = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint16_t spu_rx_stat_dbg_1_tfu_sc_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_STAT_DBG_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x7FF00000)) >> 20);
}
__INLINE uint8_t spu_rx_stat_dbg_1_tfu_fob_buf_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_STAT_DBG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000C0000)) >> 18);
}
__INLINE uint8_t spu_rx_stat_dbg_1_stall_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_STAT_DBG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE uint8_t spu_rx_stat_dbg_1_last_sc_in_ru_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_STAT_DBG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint16_t spu_rx_stat_dbg_1_sym_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_STAT_DBG_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00007FC0)) >> 6);
}
__INLINE uint8_t spu_rx_stat_dbg_1_ru_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_STAT_DBG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE uint8_t spu_rx_stat_dbg_1_rx_ctl_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_STAT_DBG_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}

/**
 * @brief RX_STAT_DBG_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:16 ROT_STALL_CNT             0x0
 *    10:00 TFU_RD_CNT                0x0
 * </pre>
 */
#define SPU_RX_STAT_DBG_2_ADDR        (REG_SPU_BASE_ADDR+0x00000054)
#define SPU_RX_STAT_DBG_2_OFFSET      0x00000054
#define SPU_RX_STAT_DBG_2_INDEX       0x00000015
#define SPU_RX_STAT_DBG_2_RESET       0x00000000

__INLINE uint32_t  spu_rx_stat_dbg_2_get(void)
{
	return REG_PL_RD(SPU_RX_STAT_DBG_2_ADDR);
}

// field definitions
#define SPU_RX_STAT_DBG_2_ROT_STALL_CNT_MASK    ((uint32_t)0x1FFF0000)
#define SPU_RX_STAT_DBG_2_ROT_STALL_CNT_LSB    16
#define SPU_RX_STAT_DBG_2_ROT_STALL_CNT_WIDTH    ((uint32_t)0x0000000D)
#define SPU_RX_STAT_DBG_2_TFU_RD_CNT_MASK    ((uint32_t)0x000007FF)
#define SPU_RX_STAT_DBG_2_TFU_RD_CNT_LSB    0
#define SPU_RX_STAT_DBG_2_TFU_RD_CNT_WIDTH    ((uint32_t)0x0000000B)

#define SPU_RX_STAT_DBG_2_ROT_STALL_CNT_RST    0x0
#define SPU_RX_STAT_DBG_2_TFU_RD_CNT_RST    0x0

__INLINE void spu_rx_stat_dbg_2_unpack(uint16_t* rot_stall_cnt, uint16_t* tfu_rd_cnt)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_STAT_DBG_2_ADDR);

	*rot_stall_cnt = (localVal & ((uint32_t)0x1FFF0000)) >>  16;
	*tfu_rd_cnt = (localVal & ((uint32_t)0x000007FF)) >>  0;
}

__INLINE uint16_t spu_rx_stat_dbg_2_rot_stall_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_STAT_DBG_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x1FFF0000)) >> 16);
}
__INLINE uint16_t spu_rx_stat_dbg_2_tfu_rd_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_STAT_DBG_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000007FF)) >> 0);
}

/**
 * @brief RX_STAT_DBG_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    22:00 CW_BUF_FULL_CNT           0x0
 * </pre>
 */
#define SPU_RX_STAT_DBG_3_ADDR        (REG_SPU_BASE_ADDR+0x00000058)
#define SPU_RX_STAT_DBG_3_OFFSET      0x00000058
#define SPU_RX_STAT_DBG_3_INDEX       0x00000016
#define SPU_RX_STAT_DBG_3_RESET       0x00000000

__INLINE uint32_t  spu_rx_stat_dbg_3_get(void)
{
	return REG_PL_RD(SPU_RX_STAT_DBG_3_ADDR);
}

// field definitions
#define SPU_RX_STAT_DBG_3_CW_BUF_FULL_CNT_MASK    ((uint32_t)0x007FFFFF)
#define SPU_RX_STAT_DBG_3_CW_BUF_FULL_CNT_LSB    0
#define SPU_RX_STAT_DBG_3_CW_BUF_FULL_CNT_WIDTH    ((uint32_t)0x00000017)

#define SPU_RX_STAT_DBG_3_CW_BUF_FULL_CNT_RST    0x0

__INLINE uint32_t spu_rx_stat_dbg_3_cw_buf_full_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_STAT_DBG_3_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief CLK_GATE_CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:08 CLK_GATE_DLY              0x10
 *    04    FORCE_FIC_ISOLATION       1              
 *    02    COMMON_CLK_GATE_EN        1              
 *    01    RX_CLK_GATE_EN            1              
 *    00    TX_CLK_GATE_EN            1              
 * </pre>
 */
#define SPU_CLK_GATE_CFG_ADDR        (REG_SPU_BASE_ADDR+0x00000060)
#define SPU_CLK_GATE_CFG_OFFSET      0x00000060
#define SPU_CLK_GATE_CFG_INDEX       0x00000018
#define SPU_CLK_GATE_CFG_RESET       0x00001017

__INLINE uint32_t  spu_clk_gate_cfg_get(void)
{
	return REG_PL_RD(SPU_CLK_GATE_CFG_ADDR);
}

__INLINE void spu_clk_gate_cfg_set(uint32_t value)
{
	REG_PL_WR(SPU_CLK_GATE_CFG_ADDR, value);
}

// field definitions
#define SPU_CLK_GATE_CFG_CLK_GATE_DLY_MASK    ((uint32_t)0x0000FF00)
#define SPU_CLK_GATE_CFG_CLK_GATE_DLY_LSB    8
#define SPU_CLK_GATE_CFG_CLK_GATE_DLY_WIDTH    ((uint32_t)0x00000008)
#define SPU_CLK_GATE_CFG_FORCE_FIC_ISOLATION_BIT    ((uint32_t)0x00000010)
#define SPU_CLK_GATE_CFG_FORCE_FIC_ISOLATION_POS    4
#define SPU_CLK_GATE_CFG_COMMON_CLK_GATE_EN_BIT    ((uint32_t)0x00000004)
#define SPU_CLK_GATE_CFG_COMMON_CLK_GATE_EN_POS    2
#define SPU_CLK_GATE_CFG_RX_CLK_GATE_EN_BIT    ((uint32_t)0x00000002)
#define SPU_CLK_GATE_CFG_RX_CLK_GATE_EN_POS    1
#define SPU_CLK_GATE_CFG_TX_CLK_GATE_EN_BIT    ((uint32_t)0x00000001)
#define SPU_CLK_GATE_CFG_TX_CLK_GATE_EN_POS    0

#define SPU_CLK_GATE_CFG_CLK_GATE_DLY_RST    0x10
#define SPU_CLK_GATE_CFG_FORCE_FIC_ISOLATION_RST    0x1
#define SPU_CLK_GATE_CFG_COMMON_CLK_GATE_EN_RST    0x1
#define SPU_CLK_GATE_CFG_RX_CLK_GATE_EN_RST    0x1
#define SPU_CLK_GATE_CFG_TX_CLK_GATE_EN_RST    0x1

__INLINE void spu_clk_gate_cfg_pack(uint8_t clk_gate_dly, uint8_t force_fic_isolation, uint8_t common_clk_gate_en, uint8_t rx_clk_gate_en, uint8_t tx_clk_gate_en)
{
	ASSERT_ERR((((uint32_t)clk_gate_dly << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)force_fic_isolation << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)common_clk_gate_en << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)rx_clk_gate_en << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)tx_clk_gate_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_CLK_GATE_CFG_ADDR,  ((uint32_t)clk_gate_dly << 8) |((uint32_t)force_fic_isolation << 4) |((uint32_t)common_clk_gate_en << 2) |((uint32_t)rx_clk_gate_en << 1) |((uint32_t)tx_clk_gate_en << 0));
}

__INLINE void spu_clk_gate_cfg_unpack(uint8_t* clk_gate_dly, uint8_t* force_fic_isolation, uint8_t* common_clk_gate_en, uint8_t* rx_clk_gate_en, uint8_t* tx_clk_gate_en)
{
	uint32_t localVal = REG_PL_RD(SPU_CLK_GATE_CFG_ADDR);

	*clk_gate_dly = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*force_fic_isolation = (localVal & ((uint32_t)0x00000010)) >>  4;
	*common_clk_gate_en = (localVal & ((uint32_t)0x00000004)) >>  2;
	*rx_clk_gate_en = (localVal & ((uint32_t)0x00000002)) >>  1;
	*tx_clk_gate_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t spu_clk_gate_cfg_clk_gate_dly_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_CLK_GATE_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void spu_clk_gate_cfg_clk_gate_dly_setf(uint8_t clkgatedly)
{
	ASSERT_ERR((((uint32_t)clkgatedly << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(SPU_CLK_GATE_CFG_ADDR, (REG_PL_RD(SPU_CLK_GATE_CFG_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)clkgatedly <<8));
}
__INLINE uint8_t spu_clk_gate_cfg_force_fic_isolation_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_CLK_GATE_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void spu_clk_gate_cfg_force_fic_isolation_setf(uint8_t forceficisolation)
{
	ASSERT_ERR((((uint32_t)forceficisolation << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(SPU_CLK_GATE_CFG_ADDR, (REG_PL_RD(SPU_CLK_GATE_CFG_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)forceficisolation <<4));
}
__INLINE uint8_t spu_clk_gate_cfg_common_clk_gate_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_CLK_GATE_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void spu_clk_gate_cfg_common_clk_gate_en_setf(uint8_t commonclkgateen)
{
	ASSERT_ERR((((uint32_t)commonclkgateen << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(SPU_CLK_GATE_CFG_ADDR, (REG_PL_RD(SPU_CLK_GATE_CFG_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)commonclkgateen <<2));
}
__INLINE uint8_t spu_clk_gate_cfg_rx_clk_gate_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_CLK_GATE_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void spu_clk_gate_cfg_rx_clk_gate_en_setf(uint8_t rxclkgateen)
{
	ASSERT_ERR((((uint32_t)rxclkgateen << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(SPU_CLK_GATE_CFG_ADDR, (REG_PL_RD(SPU_CLK_GATE_CFG_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)rxclkgateen <<1));
}
__INLINE uint8_t spu_clk_gate_cfg_tx_clk_gate_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_CLK_GATE_CFG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void spu_clk_gate_cfg_tx_clk_gate_en_setf(uint8_t txclkgateen)
{
	ASSERT_ERR((((uint32_t)txclkgateen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_CLK_GATE_CFG_ADDR, (REG_PL_RD(SPU_CLK_GATE_CFG_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)txclkgateen <<0));
}

/**
 * @brief RX_POST_SYM_WAIT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 RX_POST_SYM_WAIT          0x0
 * </pre>
 */
#define SPU_RX_POST_SYM_WAIT_ADDR        (REG_SPU_BASE_ADDR+0x00000064)
#define SPU_RX_POST_SYM_WAIT_OFFSET      0x00000064
#define SPU_RX_POST_SYM_WAIT_INDEX       0x00000019
#define SPU_RX_POST_SYM_WAIT_RESET       0x00000000

__INLINE uint32_t  spu_rx_post_sym_wait_get(void)
{
	return REG_PL_RD(SPU_RX_POST_SYM_WAIT_ADDR);
}

__INLINE void spu_rx_post_sym_wait_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_POST_SYM_WAIT_ADDR, value);
}

// field definitions
#define SPU_RX_POST_SYM_WAIT_RX_POST_SYM_WAIT_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_POST_SYM_WAIT_RX_POST_SYM_WAIT_LSB    0
#define SPU_RX_POST_SYM_WAIT_RX_POST_SYM_WAIT_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_POST_SYM_WAIT_RX_POST_SYM_WAIT_RST    0x0

__INLINE uint16_t spu_rx_post_sym_wait_rx_post_sym_wait_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_POST_SYM_WAIT_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void spu_rx_post_sym_wait_rx_post_sym_wait_setf(uint16_t rxpostsymwait)
{
	ASSERT_ERR((((uint32_t)rxpostsymwait << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_POST_SYM_WAIT_ADDR, (uint32_t)rxpostsymwait << 0);
}

/**
 * @brief USER_0_CONF register definition
 *  User0 config register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    21:16 RU_SLOT_U0                0x0
 *    15:14 SS_NUM_U0                 0x0
 *    13:11 SS_POS_U0                 0x0
 *    10:08 RU_INDEX_U0               0x0
 *    06:04 RU_TYPE_U0                0x0
 *    03    STBC_U0                   0              
 *    02    BF_EN_U0                  0              
 *    01    DCM_EN_U0                 0              
 *    00    FEC_TYPE_U0               0              
 * </pre>
 */
#define SPU_USER_0_CONF_ADDR        (REG_SPU_BASE_ADDR+0x00000080)
#define SPU_USER_0_CONF_OFFSET      0x00000080
#define SPU_USER_0_CONF_INDEX       0x00000020
#define SPU_USER_0_CONF_RESET       0x00000000

__INLINE uint32_t  spu_user_0_conf_get(void)
{
	return REG_PL_RD(SPU_USER_0_CONF_ADDR);
}

__INLINE void spu_user_0_conf_set(uint32_t value)
{
	REG_PL_WR(SPU_USER_0_CONF_ADDR, value);
}

// field definitions
#define SPU_USER_0_CONF_RU_SLOT_U_0_MASK    ((uint32_t)0x003F0000)
#define SPU_USER_0_CONF_RU_SLOT_U_0_LSB     16
#define SPU_USER_0_CONF_RU_SLOT_U_0_WIDTH    ((uint32_t)0x00000006)
#define SPU_USER_0_CONF_SS_NUM_U_0_MASK     ((uint32_t)0x0000C000)
#define SPU_USER_0_CONF_SS_NUM_U_0_LSB      14
#define SPU_USER_0_CONF_SS_NUM_U_0_WIDTH    ((uint32_t)0x00000002)
#define SPU_USER_0_CONF_SS_POS_U_0_MASK     ((uint32_t)0x00003800)
#define SPU_USER_0_CONF_SS_POS_U_0_LSB      11
#define SPU_USER_0_CONF_SS_POS_U_0_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_0_CONF_RU_INDEX_U_0_MASK    ((uint32_t)0x00000700)
#define SPU_USER_0_CONF_RU_INDEX_U_0_LSB    8
#define SPU_USER_0_CONF_RU_INDEX_U_0_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_0_CONF_RU_TYPE_U_0_MASK    ((uint32_t)0x00000070)
#define SPU_USER_0_CONF_RU_TYPE_U_0_LSB     4
#define SPU_USER_0_CONF_RU_TYPE_U_0_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_0_CONF_STBC_U_0_BIT        ((uint32_t)0x00000008)
#define SPU_USER_0_CONF_STBC_U_0_POS        3
#define SPU_USER_0_CONF_BF_EN_U_0_BIT       ((uint32_t)0x00000004)
#define SPU_USER_0_CONF_BF_EN_U_0_POS       2
#define SPU_USER_0_CONF_DCM_EN_U_0_BIT      ((uint32_t)0x00000002)
#define SPU_USER_0_CONF_DCM_EN_U_0_POS      1
#define SPU_USER_0_CONF_FEC_TYPE_U_0_BIT    ((uint32_t)0x00000001)
#define SPU_USER_0_CONF_FEC_TYPE_U_0_POS    0

#define SPU_USER_0_CONF_RU_SLOT_U_0_RST     0x0
#define SPU_USER_0_CONF_SS_NUM_U_0_RST      0x0
#define SPU_USER_0_CONF_SS_POS_U_0_RST      0x0
#define SPU_USER_0_CONF_RU_INDEX_U_0_RST    0x0
#define SPU_USER_0_CONF_RU_TYPE_U_0_RST     0x0
#define SPU_USER_0_CONF_STBC_U_0_RST        0x0
#define SPU_USER_0_CONF_BF_EN_U_0_RST       0x0
#define SPU_USER_0_CONF_DCM_EN_U_0_RST      0x0
#define SPU_USER_0_CONF_FEC_TYPE_U_0_RST    0x0

__INLINE void spu_user_0_conf_pack(uint8_t ru_slot_u0, uint8_t ss_num_u0, uint8_t ss_pos_u0, uint8_t ru_index_u0, uint8_t ru_type_u0, uint8_t stbc_u0, uint8_t bf_en_u0, uint8_t dcm_en_u0, uint8_t fec_type_u0)
{
	ASSERT_ERR((((uint32_t)ru_slot_u0 << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)ss_num_u0 << 14) & ~((uint32_t)0x0000C000)) == 0);
	ASSERT_ERR((((uint32_t)ss_pos_u0 << 11) & ~((uint32_t)0x00003800)) == 0);
	ASSERT_ERR((((uint32_t)ru_index_u0 << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)ru_type_u0 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)stbc_u0 << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)bf_en_u0 << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)dcm_en_u0 << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)fec_type_u0 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_USER_0_CONF_ADDR,  ((uint32_t)ru_slot_u0 << 16) |((uint32_t)ss_num_u0 << 14) |((uint32_t)ss_pos_u0 << 11) |((uint32_t)ru_index_u0 << 8) |((uint32_t)ru_type_u0 << 4) |((uint32_t)stbc_u0 << 3) |((uint32_t)bf_en_u0 << 2) |((uint32_t)dcm_en_u0 << 1) |((uint32_t)fec_type_u0 << 0));
}

__INLINE void spu_user_0_conf_unpack(uint8_t* ru_slot_u0, uint8_t* ss_num_u0, uint8_t* ss_pos_u0, uint8_t* ru_index_u0, uint8_t* ru_type_u0, uint8_t* stbc_u0, uint8_t* bf_en_u0, uint8_t* dcm_en_u0, uint8_t* fec_type_u0)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_0_CONF_ADDR);

	*ru_slot_u0 = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*ss_num_u0 = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*ss_pos_u0 = (localVal & ((uint32_t)0x00003800)) >>  11;
	*ru_index_u0 = (localVal & ((uint32_t)0x00000700)) >>  8;
	*ru_type_u0 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*stbc_u0 = (localVal & ((uint32_t)0x00000008)) >>  3;
	*bf_en_u0 = (localVal & ((uint32_t)0x00000004)) >>  2;
	*dcm_en_u0 = (localVal & ((uint32_t)0x00000002)) >>  1;
	*fec_type_u0 = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t spu_user_0_conf_ru_slot_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_0_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void spu_user_0_conf_ru_slot_u_0_setf(uint8_t ruslotu0)
{
	ASSERT_ERR((((uint32_t)ruslotu0 << 16) & ~((uint32_t)0x003F0000)) == 0);
	REG_PL_WR(SPU_USER_0_CONF_ADDR, (REG_PL_RD(SPU_USER_0_CONF_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)ruslotu0 <<16));
}
__INLINE uint8_t spu_user_0_conf_ss_num_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_0_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE void spu_user_0_conf_ss_num_u_0_setf(uint8_t ssnumu0)
{
	ASSERT_ERR((((uint32_t)ssnumu0 << 14) & ~((uint32_t)0x0000C000)) == 0);
	REG_PL_WR(SPU_USER_0_CONF_ADDR, (REG_PL_RD(SPU_USER_0_CONF_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)ssnumu0 <<14));
}
__INLINE uint8_t spu_user_0_conf_ss_pos_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_0_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003800)) >> 11);
}
__INLINE void spu_user_0_conf_ss_pos_u_0_setf(uint8_t ssposu0)
{
	ASSERT_ERR((((uint32_t)ssposu0 << 11) & ~((uint32_t)0x00003800)) == 0);
	REG_PL_WR(SPU_USER_0_CONF_ADDR, (REG_PL_RD(SPU_USER_0_CONF_ADDR) & ~((uint32_t)0x00003800)) | ((uint32_t)ssposu0 <<11));
}
__INLINE uint8_t spu_user_0_conf_ru_index_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_0_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void spu_user_0_conf_ru_index_u_0_setf(uint8_t ruindexu0)
{
	ASSERT_ERR((((uint32_t)ruindexu0 << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(SPU_USER_0_CONF_ADDR, (REG_PL_RD(SPU_USER_0_CONF_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)ruindexu0 <<8));
}
__INLINE uint8_t spu_user_0_conf_ru_type_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_0_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void spu_user_0_conf_ru_type_u_0_setf(uint8_t rutypeu0)
{
	ASSERT_ERR((((uint32_t)rutypeu0 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(SPU_USER_0_CONF_ADDR, (REG_PL_RD(SPU_USER_0_CONF_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)rutypeu0 <<4));
}
__INLINE uint8_t spu_user_0_conf_stbc_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_0_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void spu_user_0_conf_stbc_u_0_setf(uint8_t stbcu0)
{
	ASSERT_ERR((((uint32_t)stbcu0 << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(SPU_USER_0_CONF_ADDR, (REG_PL_RD(SPU_USER_0_CONF_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)stbcu0 <<3));
}
__INLINE uint8_t spu_user_0_conf_bf_en_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_0_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void spu_user_0_conf_bf_en_u_0_setf(uint8_t bfenu0)
{
	ASSERT_ERR((((uint32_t)bfenu0 << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(SPU_USER_0_CONF_ADDR, (REG_PL_RD(SPU_USER_0_CONF_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)bfenu0 <<2));
}
__INLINE uint8_t spu_user_0_conf_dcm_en_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_0_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void spu_user_0_conf_dcm_en_u_0_setf(uint8_t dcmenu0)
{
	ASSERT_ERR((((uint32_t)dcmenu0 << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(SPU_USER_0_CONF_ADDR, (REG_PL_RD(SPU_USER_0_CONF_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)dcmenu0 <<1));
}
__INLINE uint8_t spu_user_0_conf_fec_type_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_0_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void spu_user_0_conf_fec_type_u_0_setf(uint8_t fectypeu0)
{
	ASSERT_ERR((((uint32_t)fectypeu0 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_USER_0_CONF_ADDR, (REG_PL_RD(SPU_USER_0_CONF_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)fectypeu0 <<0));
}

/**
 * @brief USER_1_CONF register definition
 *  User1 config register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    21:16 RU_SLOT_U1                0x0
 *    15:14 SS_NUM_U1                 0x0
 *    13:11 SS_POS_U1                 0x0
 *    10:08 RU_INDEX_U1               0x0
 *    06:04 RU_TYPE_U1                0x0
 *    03    STBC_U1                   0              
 *    02    BF_EN_U1                  0              
 *    01    DCM_EN_U1                 0              
 *    00    FEC_TYPE_U1               0              
 * </pre>
 */
#define SPU_USER_1_CONF_ADDR        (REG_SPU_BASE_ADDR+0x00000084)
#define SPU_USER_1_CONF_OFFSET      0x00000084
#define SPU_USER_1_CONF_INDEX       0x00000021
#define SPU_USER_1_CONF_RESET       0x00000000

__INLINE uint32_t  spu_user_1_conf_get(void)
{
	return REG_PL_RD(SPU_USER_1_CONF_ADDR);
}

__INLINE void spu_user_1_conf_set(uint32_t value)
{
	REG_PL_WR(SPU_USER_1_CONF_ADDR, value);
}

// field definitions
#define SPU_USER_1_CONF_RU_SLOT_U_1_MASK    ((uint32_t)0x003F0000)
#define SPU_USER_1_CONF_RU_SLOT_U_1_LSB     16
#define SPU_USER_1_CONF_RU_SLOT_U_1_WIDTH    ((uint32_t)0x00000006)
#define SPU_USER_1_CONF_SS_NUM_U_1_MASK     ((uint32_t)0x0000C000)
#define SPU_USER_1_CONF_SS_NUM_U_1_LSB      14
#define SPU_USER_1_CONF_SS_NUM_U_1_WIDTH    ((uint32_t)0x00000002)
#define SPU_USER_1_CONF_SS_POS_U_1_MASK     ((uint32_t)0x00003800)
#define SPU_USER_1_CONF_SS_POS_U_1_LSB      11
#define SPU_USER_1_CONF_SS_POS_U_1_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_1_CONF_RU_INDEX_U_1_MASK    ((uint32_t)0x00000700)
#define SPU_USER_1_CONF_RU_INDEX_U_1_LSB    8
#define SPU_USER_1_CONF_RU_INDEX_U_1_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_1_CONF_RU_TYPE_U_1_MASK    ((uint32_t)0x00000070)
#define SPU_USER_1_CONF_RU_TYPE_U_1_LSB     4
#define SPU_USER_1_CONF_RU_TYPE_U_1_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_1_CONF_STBC_U_1_BIT        ((uint32_t)0x00000008)
#define SPU_USER_1_CONF_STBC_U_1_POS        3
#define SPU_USER_1_CONF_BF_EN_U_1_BIT       ((uint32_t)0x00000004)
#define SPU_USER_1_CONF_BF_EN_U_1_POS       2
#define SPU_USER_1_CONF_DCM_EN_U_1_BIT      ((uint32_t)0x00000002)
#define SPU_USER_1_CONF_DCM_EN_U_1_POS      1
#define SPU_USER_1_CONF_FEC_TYPE_U_1_BIT    ((uint32_t)0x00000001)
#define SPU_USER_1_CONF_FEC_TYPE_U_1_POS    0

#define SPU_USER_1_CONF_RU_SLOT_U_1_RST     0x0
#define SPU_USER_1_CONF_SS_NUM_U_1_RST      0x0
#define SPU_USER_1_CONF_SS_POS_U_1_RST      0x0
#define SPU_USER_1_CONF_RU_INDEX_U_1_RST    0x0
#define SPU_USER_1_CONF_RU_TYPE_U_1_RST     0x0
#define SPU_USER_1_CONF_STBC_U_1_RST        0x0
#define SPU_USER_1_CONF_BF_EN_U_1_RST       0x0
#define SPU_USER_1_CONF_DCM_EN_U_1_RST      0x0
#define SPU_USER_1_CONF_FEC_TYPE_U_1_RST    0x0

__INLINE void spu_user_1_conf_pack(uint8_t ru_slot_u1, uint8_t ss_num_u1, uint8_t ss_pos_u1, uint8_t ru_index_u1, uint8_t ru_type_u1, uint8_t stbc_u1, uint8_t bf_en_u1, uint8_t dcm_en_u1, uint8_t fec_type_u1)
{
	ASSERT_ERR((((uint32_t)ru_slot_u1 << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)ss_num_u1 << 14) & ~((uint32_t)0x0000C000)) == 0);
	ASSERT_ERR((((uint32_t)ss_pos_u1 << 11) & ~((uint32_t)0x00003800)) == 0);
	ASSERT_ERR((((uint32_t)ru_index_u1 << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)ru_type_u1 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)stbc_u1 << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)bf_en_u1 << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)dcm_en_u1 << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)fec_type_u1 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_USER_1_CONF_ADDR,  ((uint32_t)ru_slot_u1 << 16) |((uint32_t)ss_num_u1 << 14) |((uint32_t)ss_pos_u1 << 11) |((uint32_t)ru_index_u1 << 8) |((uint32_t)ru_type_u1 << 4) |((uint32_t)stbc_u1 << 3) |((uint32_t)bf_en_u1 << 2) |((uint32_t)dcm_en_u1 << 1) |((uint32_t)fec_type_u1 << 0));
}

__INLINE void spu_user_1_conf_unpack(uint8_t* ru_slot_u1, uint8_t* ss_num_u1, uint8_t* ss_pos_u1, uint8_t* ru_index_u1, uint8_t* ru_type_u1, uint8_t* stbc_u1, uint8_t* bf_en_u1, uint8_t* dcm_en_u1, uint8_t* fec_type_u1)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_1_CONF_ADDR);

	*ru_slot_u1 = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*ss_num_u1 = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*ss_pos_u1 = (localVal & ((uint32_t)0x00003800)) >>  11;
	*ru_index_u1 = (localVal & ((uint32_t)0x00000700)) >>  8;
	*ru_type_u1 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*stbc_u1 = (localVal & ((uint32_t)0x00000008)) >>  3;
	*bf_en_u1 = (localVal & ((uint32_t)0x00000004)) >>  2;
	*dcm_en_u1 = (localVal & ((uint32_t)0x00000002)) >>  1;
	*fec_type_u1 = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t spu_user_1_conf_ru_slot_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_1_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void spu_user_1_conf_ru_slot_u_1_setf(uint8_t ruslotu1)
{
	ASSERT_ERR((((uint32_t)ruslotu1 << 16) & ~((uint32_t)0x003F0000)) == 0);
	REG_PL_WR(SPU_USER_1_CONF_ADDR, (REG_PL_RD(SPU_USER_1_CONF_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)ruslotu1 <<16));
}
__INLINE uint8_t spu_user_1_conf_ss_num_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_1_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE void spu_user_1_conf_ss_num_u_1_setf(uint8_t ssnumu1)
{
	ASSERT_ERR((((uint32_t)ssnumu1 << 14) & ~((uint32_t)0x0000C000)) == 0);
	REG_PL_WR(SPU_USER_1_CONF_ADDR, (REG_PL_RD(SPU_USER_1_CONF_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)ssnumu1 <<14));
}
__INLINE uint8_t spu_user_1_conf_ss_pos_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_1_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003800)) >> 11);
}
__INLINE void spu_user_1_conf_ss_pos_u_1_setf(uint8_t ssposu1)
{
	ASSERT_ERR((((uint32_t)ssposu1 << 11) & ~((uint32_t)0x00003800)) == 0);
	REG_PL_WR(SPU_USER_1_CONF_ADDR, (REG_PL_RD(SPU_USER_1_CONF_ADDR) & ~((uint32_t)0x00003800)) | ((uint32_t)ssposu1 <<11));
}
__INLINE uint8_t spu_user_1_conf_ru_index_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_1_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void spu_user_1_conf_ru_index_u_1_setf(uint8_t ruindexu1)
{
	ASSERT_ERR((((uint32_t)ruindexu1 << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(SPU_USER_1_CONF_ADDR, (REG_PL_RD(SPU_USER_1_CONF_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)ruindexu1 <<8));
}
__INLINE uint8_t spu_user_1_conf_ru_type_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_1_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void spu_user_1_conf_ru_type_u_1_setf(uint8_t rutypeu1)
{
	ASSERT_ERR((((uint32_t)rutypeu1 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(SPU_USER_1_CONF_ADDR, (REG_PL_RD(SPU_USER_1_CONF_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)rutypeu1 <<4));
}
__INLINE uint8_t spu_user_1_conf_stbc_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_1_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void spu_user_1_conf_stbc_u_1_setf(uint8_t stbcu1)
{
	ASSERT_ERR((((uint32_t)stbcu1 << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(SPU_USER_1_CONF_ADDR, (REG_PL_RD(SPU_USER_1_CONF_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)stbcu1 <<3));
}
__INLINE uint8_t spu_user_1_conf_bf_en_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_1_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void spu_user_1_conf_bf_en_u_1_setf(uint8_t bfenu1)
{
	ASSERT_ERR((((uint32_t)bfenu1 << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(SPU_USER_1_CONF_ADDR, (REG_PL_RD(SPU_USER_1_CONF_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)bfenu1 <<2));
}
__INLINE uint8_t spu_user_1_conf_dcm_en_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_1_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void spu_user_1_conf_dcm_en_u_1_setf(uint8_t dcmenu1)
{
	ASSERT_ERR((((uint32_t)dcmenu1 << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(SPU_USER_1_CONF_ADDR, (REG_PL_RD(SPU_USER_1_CONF_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)dcmenu1 <<1));
}
__INLINE uint8_t spu_user_1_conf_fec_type_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_1_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void spu_user_1_conf_fec_type_u_1_setf(uint8_t fectypeu1)
{
	ASSERT_ERR((((uint32_t)fectypeu1 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_USER_1_CONF_ADDR, (REG_PL_RD(SPU_USER_1_CONF_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)fectypeu1 <<0));
}

/**
 * @brief USER_2_CONF register definition
 *  User2 config register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    21:16 RU_SLOT_U2                0x0
 *    15:14 SS_NUM_U2                 0x0
 *    13:11 SS_POS_U2                 0x0
 *    10:08 RU_INDEX_U2               0x0
 *    06:04 RU_TYPE_U2                0x0
 *    03    STBC_U2                   0              
 *    02    BF_EN_U2                  0              
 *    01    DCM_EN_U2                 0              
 *    00    FEC_TYPE_U2               0              
 * </pre>
 */
#define SPU_USER_2_CONF_ADDR        (REG_SPU_BASE_ADDR+0x00000088)
#define SPU_USER_2_CONF_OFFSET      0x00000088
#define SPU_USER_2_CONF_INDEX       0x00000022
#define SPU_USER_2_CONF_RESET       0x00000000

__INLINE uint32_t  spu_user_2_conf_get(void)
{
	return REG_PL_RD(SPU_USER_2_CONF_ADDR);
}

__INLINE void spu_user_2_conf_set(uint32_t value)
{
	REG_PL_WR(SPU_USER_2_CONF_ADDR, value);
}

// field definitions
#define SPU_USER_2_CONF_RU_SLOT_U_2_MASK    ((uint32_t)0x003F0000)
#define SPU_USER_2_CONF_RU_SLOT_U_2_LSB     16
#define SPU_USER_2_CONF_RU_SLOT_U_2_WIDTH    ((uint32_t)0x00000006)
#define SPU_USER_2_CONF_SS_NUM_U_2_MASK     ((uint32_t)0x0000C000)
#define SPU_USER_2_CONF_SS_NUM_U_2_LSB      14
#define SPU_USER_2_CONF_SS_NUM_U_2_WIDTH    ((uint32_t)0x00000002)
#define SPU_USER_2_CONF_SS_POS_U_2_MASK     ((uint32_t)0x00003800)
#define SPU_USER_2_CONF_SS_POS_U_2_LSB      11
#define SPU_USER_2_CONF_SS_POS_U_2_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_2_CONF_RU_INDEX_U_2_MASK    ((uint32_t)0x00000700)
#define SPU_USER_2_CONF_RU_INDEX_U_2_LSB    8
#define SPU_USER_2_CONF_RU_INDEX_U_2_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_2_CONF_RU_TYPE_U_2_MASK    ((uint32_t)0x00000070)
#define SPU_USER_2_CONF_RU_TYPE_U_2_LSB     4
#define SPU_USER_2_CONF_RU_TYPE_U_2_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_2_CONF_STBC_U_2_BIT        ((uint32_t)0x00000008)
#define SPU_USER_2_CONF_STBC_U_2_POS        3
#define SPU_USER_2_CONF_BF_EN_U_2_BIT       ((uint32_t)0x00000004)
#define SPU_USER_2_CONF_BF_EN_U_2_POS       2
#define SPU_USER_2_CONF_DCM_EN_U_2_BIT      ((uint32_t)0x00000002)
#define SPU_USER_2_CONF_DCM_EN_U_2_POS      1
#define SPU_USER_2_CONF_FEC_TYPE_U_2_BIT    ((uint32_t)0x00000001)
#define SPU_USER_2_CONF_FEC_TYPE_U_2_POS    0

#define SPU_USER_2_CONF_RU_SLOT_U_2_RST     0x0
#define SPU_USER_2_CONF_SS_NUM_U_2_RST      0x0
#define SPU_USER_2_CONF_SS_POS_U_2_RST      0x0
#define SPU_USER_2_CONF_RU_INDEX_U_2_RST    0x0
#define SPU_USER_2_CONF_RU_TYPE_U_2_RST     0x0
#define SPU_USER_2_CONF_STBC_U_2_RST        0x0
#define SPU_USER_2_CONF_BF_EN_U_2_RST       0x0
#define SPU_USER_2_CONF_DCM_EN_U_2_RST      0x0
#define SPU_USER_2_CONF_FEC_TYPE_U_2_RST    0x0

__INLINE void spu_user_2_conf_pack(uint8_t ru_slot_u2, uint8_t ss_num_u2, uint8_t ss_pos_u2, uint8_t ru_index_u2, uint8_t ru_type_u2, uint8_t stbc_u2, uint8_t bf_en_u2, uint8_t dcm_en_u2, uint8_t fec_type_u2)
{
	ASSERT_ERR((((uint32_t)ru_slot_u2 << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)ss_num_u2 << 14) & ~((uint32_t)0x0000C000)) == 0);
	ASSERT_ERR((((uint32_t)ss_pos_u2 << 11) & ~((uint32_t)0x00003800)) == 0);
	ASSERT_ERR((((uint32_t)ru_index_u2 << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)ru_type_u2 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)stbc_u2 << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)bf_en_u2 << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)dcm_en_u2 << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)fec_type_u2 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_USER_2_CONF_ADDR,  ((uint32_t)ru_slot_u2 << 16) |((uint32_t)ss_num_u2 << 14) |((uint32_t)ss_pos_u2 << 11) |((uint32_t)ru_index_u2 << 8) |((uint32_t)ru_type_u2 << 4) |((uint32_t)stbc_u2 << 3) |((uint32_t)bf_en_u2 << 2) |((uint32_t)dcm_en_u2 << 1) |((uint32_t)fec_type_u2 << 0));
}

__INLINE void spu_user_2_conf_unpack(uint8_t* ru_slot_u2, uint8_t* ss_num_u2, uint8_t* ss_pos_u2, uint8_t* ru_index_u2, uint8_t* ru_type_u2, uint8_t* stbc_u2, uint8_t* bf_en_u2, uint8_t* dcm_en_u2, uint8_t* fec_type_u2)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_2_CONF_ADDR);

	*ru_slot_u2 = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*ss_num_u2 = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*ss_pos_u2 = (localVal & ((uint32_t)0x00003800)) >>  11;
	*ru_index_u2 = (localVal & ((uint32_t)0x00000700)) >>  8;
	*ru_type_u2 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*stbc_u2 = (localVal & ((uint32_t)0x00000008)) >>  3;
	*bf_en_u2 = (localVal & ((uint32_t)0x00000004)) >>  2;
	*dcm_en_u2 = (localVal & ((uint32_t)0x00000002)) >>  1;
	*fec_type_u2 = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t spu_user_2_conf_ru_slot_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_2_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void spu_user_2_conf_ru_slot_u_2_setf(uint8_t ruslotu2)
{
	ASSERT_ERR((((uint32_t)ruslotu2 << 16) & ~((uint32_t)0x003F0000)) == 0);
	REG_PL_WR(SPU_USER_2_CONF_ADDR, (REG_PL_RD(SPU_USER_2_CONF_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)ruslotu2 <<16));
}
__INLINE uint8_t spu_user_2_conf_ss_num_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_2_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE void spu_user_2_conf_ss_num_u_2_setf(uint8_t ssnumu2)
{
	ASSERT_ERR((((uint32_t)ssnumu2 << 14) & ~((uint32_t)0x0000C000)) == 0);
	REG_PL_WR(SPU_USER_2_CONF_ADDR, (REG_PL_RD(SPU_USER_2_CONF_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)ssnumu2 <<14));
}
__INLINE uint8_t spu_user_2_conf_ss_pos_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_2_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003800)) >> 11);
}
__INLINE void spu_user_2_conf_ss_pos_u_2_setf(uint8_t ssposu2)
{
	ASSERT_ERR((((uint32_t)ssposu2 << 11) & ~((uint32_t)0x00003800)) == 0);
	REG_PL_WR(SPU_USER_2_CONF_ADDR, (REG_PL_RD(SPU_USER_2_CONF_ADDR) & ~((uint32_t)0x00003800)) | ((uint32_t)ssposu2 <<11));
}
__INLINE uint8_t spu_user_2_conf_ru_index_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_2_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void spu_user_2_conf_ru_index_u_2_setf(uint8_t ruindexu2)
{
	ASSERT_ERR((((uint32_t)ruindexu2 << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(SPU_USER_2_CONF_ADDR, (REG_PL_RD(SPU_USER_2_CONF_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)ruindexu2 <<8));
}
__INLINE uint8_t spu_user_2_conf_ru_type_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_2_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void spu_user_2_conf_ru_type_u_2_setf(uint8_t rutypeu2)
{
	ASSERT_ERR((((uint32_t)rutypeu2 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(SPU_USER_2_CONF_ADDR, (REG_PL_RD(SPU_USER_2_CONF_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)rutypeu2 <<4));
}
__INLINE uint8_t spu_user_2_conf_stbc_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_2_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void spu_user_2_conf_stbc_u_2_setf(uint8_t stbcu2)
{
	ASSERT_ERR((((uint32_t)stbcu2 << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(SPU_USER_2_CONF_ADDR, (REG_PL_RD(SPU_USER_2_CONF_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)stbcu2 <<3));
}
__INLINE uint8_t spu_user_2_conf_bf_en_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_2_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void spu_user_2_conf_bf_en_u_2_setf(uint8_t bfenu2)
{
	ASSERT_ERR((((uint32_t)bfenu2 << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(SPU_USER_2_CONF_ADDR, (REG_PL_RD(SPU_USER_2_CONF_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)bfenu2 <<2));
}
__INLINE uint8_t spu_user_2_conf_dcm_en_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_2_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void spu_user_2_conf_dcm_en_u_2_setf(uint8_t dcmenu2)
{
	ASSERT_ERR((((uint32_t)dcmenu2 << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(SPU_USER_2_CONF_ADDR, (REG_PL_RD(SPU_USER_2_CONF_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)dcmenu2 <<1));
}
__INLINE uint8_t spu_user_2_conf_fec_type_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_2_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void spu_user_2_conf_fec_type_u_2_setf(uint8_t fectypeu2)
{
	ASSERT_ERR((((uint32_t)fectypeu2 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_USER_2_CONF_ADDR, (REG_PL_RD(SPU_USER_2_CONF_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)fectypeu2 <<0));
}

/**
 * @brief USER_3_CONF register definition
 *  User3 config register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    21:16 RU_SLOT_U3                0x0
 *    15:14 SS_NUM_U3                 0x0
 *    13:11 SS_POS_U3                 0x0
 *    10:08 RU_INDEX_U3               0x0
 *    06:04 RU_TYPE_U3                0x0
 *    03    STBC_U3                   0              
 *    02    BF_EN_U3                  0              
 *    01    DCM_EN_U3                 0              
 *    00    FEC_TYPE_U3               0              
 * </pre>
 */
#define SPU_USER_3_CONF_ADDR        (REG_SPU_BASE_ADDR+0x0000008C)
#define SPU_USER_3_CONF_OFFSET      0x0000008C
#define SPU_USER_3_CONF_INDEX       0x00000023
#define SPU_USER_3_CONF_RESET       0x00000000

__INLINE uint32_t  spu_user_3_conf_get(void)
{
	return REG_PL_RD(SPU_USER_3_CONF_ADDR);
}

__INLINE void spu_user_3_conf_set(uint32_t value)
{
	REG_PL_WR(SPU_USER_3_CONF_ADDR, value);
}

// field definitions
#define SPU_USER_3_CONF_RU_SLOT_U_3_MASK    ((uint32_t)0x003F0000)
#define SPU_USER_3_CONF_RU_SLOT_U_3_LSB     16
#define SPU_USER_3_CONF_RU_SLOT_U_3_WIDTH    ((uint32_t)0x00000006)
#define SPU_USER_3_CONF_SS_NUM_U_3_MASK     ((uint32_t)0x0000C000)
#define SPU_USER_3_CONF_SS_NUM_U_3_LSB      14
#define SPU_USER_3_CONF_SS_NUM_U_3_WIDTH    ((uint32_t)0x00000002)
#define SPU_USER_3_CONF_SS_POS_U_3_MASK     ((uint32_t)0x00003800)
#define SPU_USER_3_CONF_SS_POS_U_3_LSB      11
#define SPU_USER_3_CONF_SS_POS_U_3_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_3_CONF_RU_INDEX_U_3_MASK    ((uint32_t)0x00000700)
#define SPU_USER_3_CONF_RU_INDEX_U_3_LSB    8
#define SPU_USER_3_CONF_RU_INDEX_U_3_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_3_CONF_RU_TYPE_U_3_MASK    ((uint32_t)0x00000070)
#define SPU_USER_3_CONF_RU_TYPE_U_3_LSB     4
#define SPU_USER_3_CONF_RU_TYPE_U_3_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_3_CONF_STBC_U_3_BIT        ((uint32_t)0x00000008)
#define SPU_USER_3_CONF_STBC_U_3_POS        3
#define SPU_USER_3_CONF_BF_EN_U_3_BIT       ((uint32_t)0x00000004)
#define SPU_USER_3_CONF_BF_EN_U_3_POS       2
#define SPU_USER_3_CONF_DCM_EN_U_3_BIT      ((uint32_t)0x00000002)
#define SPU_USER_3_CONF_DCM_EN_U_3_POS      1
#define SPU_USER_3_CONF_FEC_TYPE_U_3_BIT    ((uint32_t)0x00000001)
#define SPU_USER_3_CONF_FEC_TYPE_U_3_POS    0

#define SPU_USER_3_CONF_RU_SLOT_U_3_RST     0x0
#define SPU_USER_3_CONF_SS_NUM_U_3_RST      0x0
#define SPU_USER_3_CONF_SS_POS_U_3_RST      0x0
#define SPU_USER_3_CONF_RU_INDEX_U_3_RST    0x0
#define SPU_USER_3_CONF_RU_TYPE_U_3_RST     0x0
#define SPU_USER_3_CONF_STBC_U_3_RST        0x0
#define SPU_USER_3_CONF_BF_EN_U_3_RST       0x0
#define SPU_USER_3_CONF_DCM_EN_U_3_RST      0x0
#define SPU_USER_3_CONF_FEC_TYPE_U_3_RST    0x0

__INLINE void spu_user_3_conf_pack(uint8_t ru_slot_u3, uint8_t ss_num_u3, uint8_t ss_pos_u3, uint8_t ru_index_u3, uint8_t ru_type_u3, uint8_t stbc_u3, uint8_t bf_en_u3, uint8_t dcm_en_u3, uint8_t fec_type_u3)
{
	ASSERT_ERR((((uint32_t)ru_slot_u3 << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)ss_num_u3 << 14) & ~((uint32_t)0x0000C000)) == 0);
	ASSERT_ERR((((uint32_t)ss_pos_u3 << 11) & ~((uint32_t)0x00003800)) == 0);
	ASSERT_ERR((((uint32_t)ru_index_u3 << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)ru_type_u3 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)stbc_u3 << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)bf_en_u3 << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)dcm_en_u3 << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)fec_type_u3 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_USER_3_CONF_ADDR,  ((uint32_t)ru_slot_u3 << 16) |((uint32_t)ss_num_u3 << 14) |((uint32_t)ss_pos_u3 << 11) |((uint32_t)ru_index_u3 << 8) |((uint32_t)ru_type_u3 << 4) |((uint32_t)stbc_u3 << 3) |((uint32_t)bf_en_u3 << 2) |((uint32_t)dcm_en_u3 << 1) |((uint32_t)fec_type_u3 << 0));
}

__INLINE void spu_user_3_conf_unpack(uint8_t* ru_slot_u3, uint8_t* ss_num_u3, uint8_t* ss_pos_u3, uint8_t* ru_index_u3, uint8_t* ru_type_u3, uint8_t* stbc_u3, uint8_t* bf_en_u3, uint8_t* dcm_en_u3, uint8_t* fec_type_u3)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_3_CONF_ADDR);

	*ru_slot_u3 = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*ss_num_u3 = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*ss_pos_u3 = (localVal & ((uint32_t)0x00003800)) >>  11;
	*ru_index_u3 = (localVal & ((uint32_t)0x00000700)) >>  8;
	*ru_type_u3 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*stbc_u3 = (localVal & ((uint32_t)0x00000008)) >>  3;
	*bf_en_u3 = (localVal & ((uint32_t)0x00000004)) >>  2;
	*dcm_en_u3 = (localVal & ((uint32_t)0x00000002)) >>  1;
	*fec_type_u3 = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t spu_user_3_conf_ru_slot_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_3_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void spu_user_3_conf_ru_slot_u_3_setf(uint8_t ruslotu3)
{
	ASSERT_ERR((((uint32_t)ruslotu3 << 16) & ~((uint32_t)0x003F0000)) == 0);
	REG_PL_WR(SPU_USER_3_CONF_ADDR, (REG_PL_RD(SPU_USER_3_CONF_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)ruslotu3 <<16));
}
__INLINE uint8_t spu_user_3_conf_ss_num_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_3_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE void spu_user_3_conf_ss_num_u_3_setf(uint8_t ssnumu3)
{
	ASSERT_ERR((((uint32_t)ssnumu3 << 14) & ~((uint32_t)0x0000C000)) == 0);
	REG_PL_WR(SPU_USER_3_CONF_ADDR, (REG_PL_RD(SPU_USER_3_CONF_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)ssnumu3 <<14));
}
__INLINE uint8_t spu_user_3_conf_ss_pos_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_3_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003800)) >> 11);
}
__INLINE void spu_user_3_conf_ss_pos_u_3_setf(uint8_t ssposu3)
{
	ASSERT_ERR((((uint32_t)ssposu3 << 11) & ~((uint32_t)0x00003800)) == 0);
	REG_PL_WR(SPU_USER_3_CONF_ADDR, (REG_PL_RD(SPU_USER_3_CONF_ADDR) & ~((uint32_t)0x00003800)) | ((uint32_t)ssposu3 <<11));
}
__INLINE uint8_t spu_user_3_conf_ru_index_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_3_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void spu_user_3_conf_ru_index_u_3_setf(uint8_t ruindexu3)
{
	ASSERT_ERR((((uint32_t)ruindexu3 << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(SPU_USER_3_CONF_ADDR, (REG_PL_RD(SPU_USER_3_CONF_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)ruindexu3 <<8));
}
__INLINE uint8_t spu_user_3_conf_ru_type_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_3_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void spu_user_3_conf_ru_type_u_3_setf(uint8_t rutypeu3)
{
	ASSERT_ERR((((uint32_t)rutypeu3 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(SPU_USER_3_CONF_ADDR, (REG_PL_RD(SPU_USER_3_CONF_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)rutypeu3 <<4));
}
__INLINE uint8_t spu_user_3_conf_stbc_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_3_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void spu_user_3_conf_stbc_u_3_setf(uint8_t stbcu3)
{
	ASSERT_ERR((((uint32_t)stbcu3 << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(SPU_USER_3_CONF_ADDR, (REG_PL_RD(SPU_USER_3_CONF_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)stbcu3 <<3));
}
__INLINE uint8_t spu_user_3_conf_bf_en_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_3_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void spu_user_3_conf_bf_en_u_3_setf(uint8_t bfenu3)
{
	ASSERT_ERR((((uint32_t)bfenu3 << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(SPU_USER_3_CONF_ADDR, (REG_PL_RD(SPU_USER_3_CONF_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)bfenu3 <<2));
}
__INLINE uint8_t spu_user_3_conf_dcm_en_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_3_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void spu_user_3_conf_dcm_en_u_3_setf(uint8_t dcmenu3)
{
	ASSERT_ERR((((uint32_t)dcmenu3 << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(SPU_USER_3_CONF_ADDR, (REG_PL_RD(SPU_USER_3_CONF_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)dcmenu3 <<1));
}
__INLINE uint8_t spu_user_3_conf_fec_type_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_3_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void spu_user_3_conf_fec_type_u_3_setf(uint8_t fectypeu3)
{
	ASSERT_ERR((((uint32_t)fectypeu3 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_USER_3_CONF_ADDR, (REG_PL_RD(SPU_USER_3_CONF_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)fectypeu3 <<0));
}

/**
 * @brief USER_4_CONF register definition
 *  User4 config register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    21:16 RU_SLOT_U4                0x0
 *    15:14 SS_NUM_U4                 0x0
 *    13:11 SS_POS_U4                 0x0
 *    10:08 RU_INDEX_U4               0x0
 *    06:04 RU_TYPE_U4                0x0
 *    03    STBC_U4                   0              
 *    02    BF_EN_U4                  0              
 *    01    DCM_EN_U4                 0              
 *    00    FEC_TYPE_U4               0              
 * </pre>
 */
#define SPU_USER_4_CONF_ADDR        (REG_SPU_BASE_ADDR+0x00000090)
#define SPU_USER_4_CONF_OFFSET      0x00000090
#define SPU_USER_4_CONF_INDEX       0x00000024
#define SPU_USER_4_CONF_RESET       0x00000000

__INLINE uint32_t  spu_user_4_conf_get(void)
{
	return REG_PL_RD(SPU_USER_4_CONF_ADDR);
}

__INLINE void spu_user_4_conf_set(uint32_t value)
{
	REG_PL_WR(SPU_USER_4_CONF_ADDR, value);
}

// field definitions
#define SPU_USER_4_CONF_RU_SLOT_U_4_MASK    ((uint32_t)0x003F0000)
#define SPU_USER_4_CONF_RU_SLOT_U_4_LSB     16
#define SPU_USER_4_CONF_RU_SLOT_U_4_WIDTH    ((uint32_t)0x00000006)
#define SPU_USER_4_CONF_SS_NUM_U_4_MASK     ((uint32_t)0x0000C000)
#define SPU_USER_4_CONF_SS_NUM_U_4_LSB      14
#define SPU_USER_4_CONF_SS_NUM_U_4_WIDTH    ((uint32_t)0x00000002)
#define SPU_USER_4_CONF_SS_POS_U_4_MASK     ((uint32_t)0x00003800)
#define SPU_USER_4_CONF_SS_POS_U_4_LSB      11
#define SPU_USER_4_CONF_SS_POS_U_4_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_4_CONF_RU_INDEX_U_4_MASK    ((uint32_t)0x00000700)
#define SPU_USER_4_CONF_RU_INDEX_U_4_LSB    8
#define SPU_USER_4_CONF_RU_INDEX_U_4_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_4_CONF_RU_TYPE_U_4_MASK    ((uint32_t)0x00000070)
#define SPU_USER_4_CONF_RU_TYPE_U_4_LSB     4
#define SPU_USER_4_CONF_RU_TYPE_U_4_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_4_CONF_STBC_U_4_BIT        ((uint32_t)0x00000008)
#define SPU_USER_4_CONF_STBC_U_4_POS        3
#define SPU_USER_4_CONF_BF_EN_U_4_BIT       ((uint32_t)0x00000004)
#define SPU_USER_4_CONF_BF_EN_U_4_POS       2
#define SPU_USER_4_CONF_DCM_EN_U_4_BIT      ((uint32_t)0x00000002)
#define SPU_USER_4_CONF_DCM_EN_U_4_POS      1
#define SPU_USER_4_CONF_FEC_TYPE_U_4_BIT    ((uint32_t)0x00000001)
#define SPU_USER_4_CONF_FEC_TYPE_U_4_POS    0

#define SPU_USER_4_CONF_RU_SLOT_U_4_RST     0x0
#define SPU_USER_4_CONF_SS_NUM_U_4_RST      0x0
#define SPU_USER_4_CONF_SS_POS_U_4_RST      0x0
#define SPU_USER_4_CONF_RU_INDEX_U_4_RST    0x0
#define SPU_USER_4_CONF_RU_TYPE_U_4_RST     0x0
#define SPU_USER_4_CONF_STBC_U_4_RST        0x0
#define SPU_USER_4_CONF_BF_EN_U_4_RST       0x0
#define SPU_USER_4_CONF_DCM_EN_U_4_RST      0x0
#define SPU_USER_4_CONF_FEC_TYPE_U_4_RST    0x0

__INLINE void spu_user_4_conf_pack(uint8_t ru_slot_u4, uint8_t ss_num_u4, uint8_t ss_pos_u4, uint8_t ru_index_u4, uint8_t ru_type_u4, uint8_t stbc_u4, uint8_t bf_en_u4, uint8_t dcm_en_u4, uint8_t fec_type_u4)
{
	ASSERT_ERR((((uint32_t)ru_slot_u4 << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)ss_num_u4 << 14) & ~((uint32_t)0x0000C000)) == 0);
	ASSERT_ERR((((uint32_t)ss_pos_u4 << 11) & ~((uint32_t)0x00003800)) == 0);
	ASSERT_ERR((((uint32_t)ru_index_u4 << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)ru_type_u4 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)stbc_u4 << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)bf_en_u4 << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)dcm_en_u4 << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)fec_type_u4 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_USER_4_CONF_ADDR,  ((uint32_t)ru_slot_u4 << 16) |((uint32_t)ss_num_u4 << 14) |((uint32_t)ss_pos_u4 << 11) |((uint32_t)ru_index_u4 << 8) |((uint32_t)ru_type_u4 << 4) |((uint32_t)stbc_u4 << 3) |((uint32_t)bf_en_u4 << 2) |((uint32_t)dcm_en_u4 << 1) |((uint32_t)fec_type_u4 << 0));
}

__INLINE void spu_user_4_conf_unpack(uint8_t* ru_slot_u4, uint8_t* ss_num_u4, uint8_t* ss_pos_u4, uint8_t* ru_index_u4, uint8_t* ru_type_u4, uint8_t* stbc_u4, uint8_t* bf_en_u4, uint8_t* dcm_en_u4, uint8_t* fec_type_u4)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_4_CONF_ADDR);

	*ru_slot_u4 = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*ss_num_u4 = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*ss_pos_u4 = (localVal & ((uint32_t)0x00003800)) >>  11;
	*ru_index_u4 = (localVal & ((uint32_t)0x00000700)) >>  8;
	*ru_type_u4 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*stbc_u4 = (localVal & ((uint32_t)0x00000008)) >>  3;
	*bf_en_u4 = (localVal & ((uint32_t)0x00000004)) >>  2;
	*dcm_en_u4 = (localVal & ((uint32_t)0x00000002)) >>  1;
	*fec_type_u4 = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t spu_user_4_conf_ru_slot_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_4_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void spu_user_4_conf_ru_slot_u_4_setf(uint8_t ruslotu4)
{
	ASSERT_ERR((((uint32_t)ruslotu4 << 16) & ~((uint32_t)0x003F0000)) == 0);
	REG_PL_WR(SPU_USER_4_CONF_ADDR, (REG_PL_RD(SPU_USER_4_CONF_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)ruslotu4 <<16));
}
__INLINE uint8_t spu_user_4_conf_ss_num_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_4_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE void spu_user_4_conf_ss_num_u_4_setf(uint8_t ssnumu4)
{
	ASSERT_ERR((((uint32_t)ssnumu4 << 14) & ~((uint32_t)0x0000C000)) == 0);
	REG_PL_WR(SPU_USER_4_CONF_ADDR, (REG_PL_RD(SPU_USER_4_CONF_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)ssnumu4 <<14));
}
__INLINE uint8_t spu_user_4_conf_ss_pos_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_4_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003800)) >> 11);
}
__INLINE void spu_user_4_conf_ss_pos_u_4_setf(uint8_t ssposu4)
{
	ASSERT_ERR((((uint32_t)ssposu4 << 11) & ~((uint32_t)0x00003800)) == 0);
	REG_PL_WR(SPU_USER_4_CONF_ADDR, (REG_PL_RD(SPU_USER_4_CONF_ADDR) & ~((uint32_t)0x00003800)) | ((uint32_t)ssposu4 <<11));
}
__INLINE uint8_t spu_user_4_conf_ru_index_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_4_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void spu_user_4_conf_ru_index_u_4_setf(uint8_t ruindexu4)
{
	ASSERT_ERR((((uint32_t)ruindexu4 << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(SPU_USER_4_CONF_ADDR, (REG_PL_RD(SPU_USER_4_CONF_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)ruindexu4 <<8));
}
__INLINE uint8_t spu_user_4_conf_ru_type_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_4_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void spu_user_4_conf_ru_type_u_4_setf(uint8_t rutypeu4)
{
	ASSERT_ERR((((uint32_t)rutypeu4 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(SPU_USER_4_CONF_ADDR, (REG_PL_RD(SPU_USER_4_CONF_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)rutypeu4 <<4));
}
__INLINE uint8_t spu_user_4_conf_stbc_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_4_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void spu_user_4_conf_stbc_u_4_setf(uint8_t stbcu4)
{
	ASSERT_ERR((((uint32_t)stbcu4 << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(SPU_USER_4_CONF_ADDR, (REG_PL_RD(SPU_USER_4_CONF_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)stbcu4 <<3));
}
__INLINE uint8_t spu_user_4_conf_bf_en_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_4_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void spu_user_4_conf_bf_en_u_4_setf(uint8_t bfenu4)
{
	ASSERT_ERR((((uint32_t)bfenu4 << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(SPU_USER_4_CONF_ADDR, (REG_PL_RD(SPU_USER_4_CONF_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)bfenu4 <<2));
}
__INLINE uint8_t spu_user_4_conf_dcm_en_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_4_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void spu_user_4_conf_dcm_en_u_4_setf(uint8_t dcmenu4)
{
	ASSERT_ERR((((uint32_t)dcmenu4 << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(SPU_USER_4_CONF_ADDR, (REG_PL_RD(SPU_USER_4_CONF_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)dcmenu4 <<1));
}
__INLINE uint8_t spu_user_4_conf_fec_type_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_4_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void spu_user_4_conf_fec_type_u_4_setf(uint8_t fectypeu4)
{
	ASSERT_ERR((((uint32_t)fectypeu4 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_USER_4_CONF_ADDR, (REG_PL_RD(SPU_USER_4_CONF_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)fectypeu4 <<0));
}

/**
 * @brief USER_5_CONF register definition
 *  User5 config register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    21:16 RU_SLOT_U5                0x0
 *    15:14 SS_NUM_U5                 0x0
 *    13:11 SS_POS_U5                 0x0
 *    10:08 RU_INDEX_U5               0x0
 *    06:04 RU_TYPE_U5                0x0
 *    03    STBC_U5                   0              
 *    02    BF_EN_U5                  0              
 *    01    DCM_EN_U5                 0              
 *    00    FEC_TYPE_U5               0              
 * </pre>
 */
#define SPU_USER_5_CONF_ADDR        (REG_SPU_BASE_ADDR+0x00000094)
#define SPU_USER_5_CONF_OFFSET      0x00000094
#define SPU_USER_5_CONF_INDEX       0x00000025
#define SPU_USER_5_CONF_RESET       0x00000000

__INLINE uint32_t  spu_user_5_conf_get(void)
{
	return REG_PL_RD(SPU_USER_5_CONF_ADDR);
}

__INLINE void spu_user_5_conf_set(uint32_t value)
{
	REG_PL_WR(SPU_USER_5_CONF_ADDR, value);
}

// field definitions
#define SPU_USER_5_CONF_RU_SLOT_U_5_MASK    ((uint32_t)0x003F0000)
#define SPU_USER_5_CONF_RU_SLOT_U_5_LSB     16
#define SPU_USER_5_CONF_RU_SLOT_U_5_WIDTH    ((uint32_t)0x00000006)
#define SPU_USER_5_CONF_SS_NUM_U_5_MASK     ((uint32_t)0x0000C000)
#define SPU_USER_5_CONF_SS_NUM_U_5_LSB      14
#define SPU_USER_5_CONF_SS_NUM_U_5_WIDTH    ((uint32_t)0x00000002)
#define SPU_USER_5_CONF_SS_POS_U_5_MASK     ((uint32_t)0x00003800)
#define SPU_USER_5_CONF_SS_POS_U_5_LSB      11
#define SPU_USER_5_CONF_SS_POS_U_5_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_5_CONF_RU_INDEX_U_5_MASK    ((uint32_t)0x00000700)
#define SPU_USER_5_CONF_RU_INDEX_U_5_LSB    8
#define SPU_USER_5_CONF_RU_INDEX_U_5_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_5_CONF_RU_TYPE_U_5_MASK    ((uint32_t)0x00000070)
#define SPU_USER_5_CONF_RU_TYPE_U_5_LSB     4
#define SPU_USER_5_CONF_RU_TYPE_U_5_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_5_CONF_STBC_U_5_BIT        ((uint32_t)0x00000008)
#define SPU_USER_5_CONF_STBC_U_5_POS        3
#define SPU_USER_5_CONF_BF_EN_U_5_BIT       ((uint32_t)0x00000004)
#define SPU_USER_5_CONF_BF_EN_U_5_POS       2
#define SPU_USER_5_CONF_DCM_EN_U_5_BIT      ((uint32_t)0x00000002)
#define SPU_USER_5_CONF_DCM_EN_U_5_POS      1
#define SPU_USER_5_CONF_FEC_TYPE_U_5_BIT    ((uint32_t)0x00000001)
#define SPU_USER_5_CONF_FEC_TYPE_U_5_POS    0

#define SPU_USER_5_CONF_RU_SLOT_U_5_RST     0x0
#define SPU_USER_5_CONF_SS_NUM_U_5_RST      0x0
#define SPU_USER_5_CONF_SS_POS_U_5_RST      0x0
#define SPU_USER_5_CONF_RU_INDEX_U_5_RST    0x0
#define SPU_USER_5_CONF_RU_TYPE_U_5_RST     0x0
#define SPU_USER_5_CONF_STBC_U_5_RST        0x0
#define SPU_USER_5_CONF_BF_EN_U_5_RST       0x0
#define SPU_USER_5_CONF_DCM_EN_U_5_RST      0x0
#define SPU_USER_5_CONF_FEC_TYPE_U_5_RST    0x0

__INLINE void spu_user_5_conf_pack(uint8_t ru_slot_u5, uint8_t ss_num_u5, uint8_t ss_pos_u5, uint8_t ru_index_u5, uint8_t ru_type_u5, uint8_t stbc_u5, uint8_t bf_en_u5, uint8_t dcm_en_u5, uint8_t fec_type_u5)
{
	ASSERT_ERR((((uint32_t)ru_slot_u5 << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)ss_num_u5 << 14) & ~((uint32_t)0x0000C000)) == 0);
	ASSERT_ERR((((uint32_t)ss_pos_u5 << 11) & ~((uint32_t)0x00003800)) == 0);
	ASSERT_ERR((((uint32_t)ru_index_u5 << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)ru_type_u5 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)stbc_u5 << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)bf_en_u5 << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)dcm_en_u5 << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)fec_type_u5 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_USER_5_CONF_ADDR,  ((uint32_t)ru_slot_u5 << 16) |((uint32_t)ss_num_u5 << 14) |((uint32_t)ss_pos_u5 << 11) |((uint32_t)ru_index_u5 << 8) |((uint32_t)ru_type_u5 << 4) |((uint32_t)stbc_u5 << 3) |((uint32_t)bf_en_u5 << 2) |((uint32_t)dcm_en_u5 << 1) |((uint32_t)fec_type_u5 << 0));
}

__INLINE void spu_user_5_conf_unpack(uint8_t* ru_slot_u5, uint8_t* ss_num_u5, uint8_t* ss_pos_u5, uint8_t* ru_index_u5, uint8_t* ru_type_u5, uint8_t* stbc_u5, uint8_t* bf_en_u5, uint8_t* dcm_en_u5, uint8_t* fec_type_u5)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_5_CONF_ADDR);

	*ru_slot_u5 = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*ss_num_u5 = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*ss_pos_u5 = (localVal & ((uint32_t)0x00003800)) >>  11;
	*ru_index_u5 = (localVal & ((uint32_t)0x00000700)) >>  8;
	*ru_type_u5 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*stbc_u5 = (localVal & ((uint32_t)0x00000008)) >>  3;
	*bf_en_u5 = (localVal & ((uint32_t)0x00000004)) >>  2;
	*dcm_en_u5 = (localVal & ((uint32_t)0x00000002)) >>  1;
	*fec_type_u5 = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t spu_user_5_conf_ru_slot_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_5_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void spu_user_5_conf_ru_slot_u_5_setf(uint8_t ruslotu5)
{
	ASSERT_ERR((((uint32_t)ruslotu5 << 16) & ~((uint32_t)0x003F0000)) == 0);
	REG_PL_WR(SPU_USER_5_CONF_ADDR, (REG_PL_RD(SPU_USER_5_CONF_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)ruslotu5 <<16));
}
__INLINE uint8_t spu_user_5_conf_ss_num_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_5_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE void spu_user_5_conf_ss_num_u_5_setf(uint8_t ssnumu5)
{
	ASSERT_ERR((((uint32_t)ssnumu5 << 14) & ~((uint32_t)0x0000C000)) == 0);
	REG_PL_WR(SPU_USER_5_CONF_ADDR, (REG_PL_RD(SPU_USER_5_CONF_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)ssnumu5 <<14));
}
__INLINE uint8_t spu_user_5_conf_ss_pos_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_5_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003800)) >> 11);
}
__INLINE void spu_user_5_conf_ss_pos_u_5_setf(uint8_t ssposu5)
{
	ASSERT_ERR((((uint32_t)ssposu5 << 11) & ~((uint32_t)0x00003800)) == 0);
	REG_PL_WR(SPU_USER_5_CONF_ADDR, (REG_PL_RD(SPU_USER_5_CONF_ADDR) & ~((uint32_t)0x00003800)) | ((uint32_t)ssposu5 <<11));
}
__INLINE uint8_t spu_user_5_conf_ru_index_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_5_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void spu_user_5_conf_ru_index_u_5_setf(uint8_t ruindexu5)
{
	ASSERT_ERR((((uint32_t)ruindexu5 << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(SPU_USER_5_CONF_ADDR, (REG_PL_RD(SPU_USER_5_CONF_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)ruindexu5 <<8));
}
__INLINE uint8_t spu_user_5_conf_ru_type_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_5_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void spu_user_5_conf_ru_type_u_5_setf(uint8_t rutypeu5)
{
	ASSERT_ERR((((uint32_t)rutypeu5 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(SPU_USER_5_CONF_ADDR, (REG_PL_RD(SPU_USER_5_CONF_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)rutypeu5 <<4));
}
__INLINE uint8_t spu_user_5_conf_stbc_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_5_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void spu_user_5_conf_stbc_u_5_setf(uint8_t stbcu5)
{
	ASSERT_ERR((((uint32_t)stbcu5 << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(SPU_USER_5_CONF_ADDR, (REG_PL_RD(SPU_USER_5_CONF_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)stbcu5 <<3));
}
__INLINE uint8_t spu_user_5_conf_bf_en_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_5_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void spu_user_5_conf_bf_en_u_5_setf(uint8_t bfenu5)
{
	ASSERT_ERR((((uint32_t)bfenu5 << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(SPU_USER_5_CONF_ADDR, (REG_PL_RD(SPU_USER_5_CONF_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)bfenu5 <<2));
}
__INLINE uint8_t spu_user_5_conf_dcm_en_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_5_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void spu_user_5_conf_dcm_en_u_5_setf(uint8_t dcmenu5)
{
	ASSERT_ERR((((uint32_t)dcmenu5 << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(SPU_USER_5_CONF_ADDR, (REG_PL_RD(SPU_USER_5_CONF_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)dcmenu5 <<1));
}
__INLINE uint8_t spu_user_5_conf_fec_type_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_5_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void spu_user_5_conf_fec_type_u_5_setf(uint8_t fectypeu5)
{
	ASSERT_ERR((((uint32_t)fectypeu5 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_USER_5_CONF_ADDR, (REG_PL_RD(SPU_USER_5_CONF_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)fectypeu5 <<0));
}

/**
 * @brief USER_6_CONF register definition
 *  User6 config register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    21:16 RU_SLOT_U6                0x0
 *    15:14 SS_NUM_U6                 0x0
 *    13:11 SS_POS_U6                 0x0
 *    10:08 RU_INDEX_U6               0x0
 *    06:04 RU_TYPE_U6                0x0
 *    03    STBC_U6                   0              
 *    02    BF_EN_U6                  0              
 *    01    DCM_EN_U6                 0              
 *    00    FEC_TYPE_U6               0              
 * </pre>
 */
#define SPU_USER_6_CONF_ADDR        (REG_SPU_BASE_ADDR+0x00000098)
#define SPU_USER_6_CONF_OFFSET      0x00000098
#define SPU_USER_6_CONF_INDEX       0x00000026
#define SPU_USER_6_CONF_RESET       0x00000000

__INLINE uint32_t  spu_user_6_conf_get(void)
{
	return REG_PL_RD(SPU_USER_6_CONF_ADDR);
}

__INLINE void spu_user_6_conf_set(uint32_t value)
{
	REG_PL_WR(SPU_USER_6_CONF_ADDR, value);
}

// field definitions
#define SPU_USER_6_CONF_RU_SLOT_U_6_MASK    ((uint32_t)0x003F0000)
#define SPU_USER_6_CONF_RU_SLOT_U_6_LSB     16
#define SPU_USER_6_CONF_RU_SLOT_U_6_WIDTH    ((uint32_t)0x00000006)
#define SPU_USER_6_CONF_SS_NUM_U_6_MASK     ((uint32_t)0x0000C000)
#define SPU_USER_6_CONF_SS_NUM_U_6_LSB      14
#define SPU_USER_6_CONF_SS_NUM_U_6_WIDTH    ((uint32_t)0x00000002)
#define SPU_USER_6_CONF_SS_POS_U_6_MASK     ((uint32_t)0x00003800)
#define SPU_USER_6_CONF_SS_POS_U_6_LSB      11
#define SPU_USER_6_CONF_SS_POS_U_6_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_6_CONF_RU_INDEX_U_6_MASK    ((uint32_t)0x00000700)
#define SPU_USER_6_CONF_RU_INDEX_U_6_LSB    8
#define SPU_USER_6_CONF_RU_INDEX_U_6_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_6_CONF_RU_TYPE_U_6_MASK    ((uint32_t)0x00000070)
#define SPU_USER_6_CONF_RU_TYPE_U_6_LSB     4
#define SPU_USER_6_CONF_RU_TYPE_U_6_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_6_CONF_STBC_U_6_BIT        ((uint32_t)0x00000008)
#define SPU_USER_6_CONF_STBC_U_6_POS        3
#define SPU_USER_6_CONF_BF_EN_U_6_BIT       ((uint32_t)0x00000004)
#define SPU_USER_6_CONF_BF_EN_U_6_POS       2
#define SPU_USER_6_CONF_DCM_EN_U_6_BIT      ((uint32_t)0x00000002)
#define SPU_USER_6_CONF_DCM_EN_U_6_POS      1
#define SPU_USER_6_CONF_FEC_TYPE_U_6_BIT    ((uint32_t)0x00000001)
#define SPU_USER_6_CONF_FEC_TYPE_U_6_POS    0

#define SPU_USER_6_CONF_RU_SLOT_U_6_RST     0x0
#define SPU_USER_6_CONF_SS_NUM_U_6_RST      0x0
#define SPU_USER_6_CONF_SS_POS_U_6_RST      0x0
#define SPU_USER_6_CONF_RU_INDEX_U_6_RST    0x0
#define SPU_USER_6_CONF_RU_TYPE_U_6_RST     0x0
#define SPU_USER_6_CONF_STBC_U_6_RST        0x0
#define SPU_USER_6_CONF_BF_EN_U_6_RST       0x0
#define SPU_USER_6_CONF_DCM_EN_U_6_RST      0x0
#define SPU_USER_6_CONF_FEC_TYPE_U_6_RST    0x0

__INLINE void spu_user_6_conf_pack(uint8_t ru_slot_u6, uint8_t ss_num_u6, uint8_t ss_pos_u6, uint8_t ru_index_u6, uint8_t ru_type_u6, uint8_t stbc_u6, uint8_t bf_en_u6, uint8_t dcm_en_u6, uint8_t fec_type_u6)
{
	ASSERT_ERR((((uint32_t)ru_slot_u6 << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)ss_num_u6 << 14) & ~((uint32_t)0x0000C000)) == 0);
	ASSERT_ERR((((uint32_t)ss_pos_u6 << 11) & ~((uint32_t)0x00003800)) == 0);
	ASSERT_ERR((((uint32_t)ru_index_u6 << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)ru_type_u6 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)stbc_u6 << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)bf_en_u6 << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)dcm_en_u6 << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)fec_type_u6 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_USER_6_CONF_ADDR,  ((uint32_t)ru_slot_u6 << 16) |((uint32_t)ss_num_u6 << 14) |((uint32_t)ss_pos_u6 << 11) |((uint32_t)ru_index_u6 << 8) |((uint32_t)ru_type_u6 << 4) |((uint32_t)stbc_u6 << 3) |((uint32_t)bf_en_u6 << 2) |((uint32_t)dcm_en_u6 << 1) |((uint32_t)fec_type_u6 << 0));
}

__INLINE void spu_user_6_conf_unpack(uint8_t* ru_slot_u6, uint8_t* ss_num_u6, uint8_t* ss_pos_u6, uint8_t* ru_index_u6, uint8_t* ru_type_u6, uint8_t* stbc_u6, uint8_t* bf_en_u6, uint8_t* dcm_en_u6, uint8_t* fec_type_u6)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_6_CONF_ADDR);

	*ru_slot_u6 = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*ss_num_u6 = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*ss_pos_u6 = (localVal & ((uint32_t)0x00003800)) >>  11;
	*ru_index_u6 = (localVal & ((uint32_t)0x00000700)) >>  8;
	*ru_type_u6 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*stbc_u6 = (localVal & ((uint32_t)0x00000008)) >>  3;
	*bf_en_u6 = (localVal & ((uint32_t)0x00000004)) >>  2;
	*dcm_en_u6 = (localVal & ((uint32_t)0x00000002)) >>  1;
	*fec_type_u6 = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t spu_user_6_conf_ru_slot_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_6_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void spu_user_6_conf_ru_slot_u_6_setf(uint8_t ruslotu6)
{
	ASSERT_ERR((((uint32_t)ruslotu6 << 16) & ~((uint32_t)0x003F0000)) == 0);
	REG_PL_WR(SPU_USER_6_CONF_ADDR, (REG_PL_RD(SPU_USER_6_CONF_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)ruslotu6 <<16));
}
__INLINE uint8_t spu_user_6_conf_ss_num_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_6_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE void spu_user_6_conf_ss_num_u_6_setf(uint8_t ssnumu6)
{
	ASSERT_ERR((((uint32_t)ssnumu6 << 14) & ~((uint32_t)0x0000C000)) == 0);
	REG_PL_WR(SPU_USER_6_CONF_ADDR, (REG_PL_RD(SPU_USER_6_CONF_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)ssnumu6 <<14));
}
__INLINE uint8_t spu_user_6_conf_ss_pos_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_6_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003800)) >> 11);
}
__INLINE void spu_user_6_conf_ss_pos_u_6_setf(uint8_t ssposu6)
{
	ASSERT_ERR((((uint32_t)ssposu6 << 11) & ~((uint32_t)0x00003800)) == 0);
	REG_PL_WR(SPU_USER_6_CONF_ADDR, (REG_PL_RD(SPU_USER_6_CONF_ADDR) & ~((uint32_t)0x00003800)) | ((uint32_t)ssposu6 <<11));
}
__INLINE uint8_t spu_user_6_conf_ru_index_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_6_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void spu_user_6_conf_ru_index_u_6_setf(uint8_t ruindexu6)
{
	ASSERT_ERR((((uint32_t)ruindexu6 << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(SPU_USER_6_CONF_ADDR, (REG_PL_RD(SPU_USER_6_CONF_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)ruindexu6 <<8));
}
__INLINE uint8_t spu_user_6_conf_ru_type_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_6_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void spu_user_6_conf_ru_type_u_6_setf(uint8_t rutypeu6)
{
	ASSERT_ERR((((uint32_t)rutypeu6 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(SPU_USER_6_CONF_ADDR, (REG_PL_RD(SPU_USER_6_CONF_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)rutypeu6 <<4));
}
__INLINE uint8_t spu_user_6_conf_stbc_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_6_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void spu_user_6_conf_stbc_u_6_setf(uint8_t stbcu6)
{
	ASSERT_ERR((((uint32_t)stbcu6 << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(SPU_USER_6_CONF_ADDR, (REG_PL_RD(SPU_USER_6_CONF_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)stbcu6 <<3));
}
__INLINE uint8_t spu_user_6_conf_bf_en_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_6_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void spu_user_6_conf_bf_en_u_6_setf(uint8_t bfenu6)
{
	ASSERT_ERR((((uint32_t)bfenu6 << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(SPU_USER_6_CONF_ADDR, (REG_PL_RD(SPU_USER_6_CONF_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)bfenu6 <<2));
}
__INLINE uint8_t spu_user_6_conf_dcm_en_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_6_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void spu_user_6_conf_dcm_en_u_6_setf(uint8_t dcmenu6)
{
	ASSERT_ERR((((uint32_t)dcmenu6 << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(SPU_USER_6_CONF_ADDR, (REG_PL_RD(SPU_USER_6_CONF_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)dcmenu6 <<1));
}
__INLINE uint8_t spu_user_6_conf_fec_type_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_6_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void spu_user_6_conf_fec_type_u_6_setf(uint8_t fectypeu6)
{
	ASSERT_ERR((((uint32_t)fectypeu6 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_USER_6_CONF_ADDR, (REG_PL_RD(SPU_USER_6_CONF_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)fectypeu6 <<0));
}

/**
 * @brief USER_7_CONF register definition
 *  User7 config register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    21:16 RU_SLOT_U7                0x0
 *    15:14 SS_NUM_U7                 0x0
 *    13:11 SS_POS_U7                 0x0
 *    10:08 RU_INDEX_U7               0x0
 *    06:04 RU_TYPE_U7                0x0
 *    03    STBC_U7                   0              
 *    02    BF_EN_U7                  0              
 *    01    DCM_EN_U7                 0              
 *    00    FEC_TYPE_U7               0              
 * </pre>
 */
#define SPU_USER_7_CONF_ADDR        (REG_SPU_BASE_ADDR+0x0000009C)
#define SPU_USER_7_CONF_OFFSET      0x0000009C
#define SPU_USER_7_CONF_INDEX       0x00000027
#define SPU_USER_7_CONF_RESET       0x00000000

__INLINE uint32_t  spu_user_7_conf_get(void)
{
	return REG_PL_RD(SPU_USER_7_CONF_ADDR);
}

__INLINE void spu_user_7_conf_set(uint32_t value)
{
	REG_PL_WR(SPU_USER_7_CONF_ADDR, value);
}

// field definitions
#define SPU_USER_7_CONF_RU_SLOT_U_7_MASK    ((uint32_t)0x003F0000)
#define SPU_USER_7_CONF_RU_SLOT_U_7_LSB     16
#define SPU_USER_7_CONF_RU_SLOT_U_7_WIDTH    ((uint32_t)0x00000006)
#define SPU_USER_7_CONF_SS_NUM_U_7_MASK     ((uint32_t)0x0000C000)
#define SPU_USER_7_CONF_SS_NUM_U_7_LSB      14
#define SPU_USER_7_CONF_SS_NUM_U_7_WIDTH    ((uint32_t)0x00000002)
#define SPU_USER_7_CONF_SS_POS_U_7_MASK     ((uint32_t)0x00003800)
#define SPU_USER_7_CONF_SS_POS_U_7_LSB      11
#define SPU_USER_7_CONF_SS_POS_U_7_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_7_CONF_RU_INDEX_U_7_MASK    ((uint32_t)0x00000700)
#define SPU_USER_7_CONF_RU_INDEX_U_7_LSB    8
#define SPU_USER_7_CONF_RU_INDEX_U_7_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_7_CONF_RU_TYPE_U_7_MASK    ((uint32_t)0x00000070)
#define SPU_USER_7_CONF_RU_TYPE_U_7_LSB     4
#define SPU_USER_7_CONF_RU_TYPE_U_7_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_7_CONF_STBC_U_7_BIT        ((uint32_t)0x00000008)
#define SPU_USER_7_CONF_STBC_U_7_POS        3
#define SPU_USER_7_CONF_BF_EN_U_7_BIT       ((uint32_t)0x00000004)
#define SPU_USER_7_CONF_BF_EN_U_7_POS       2
#define SPU_USER_7_CONF_DCM_EN_U_7_BIT      ((uint32_t)0x00000002)
#define SPU_USER_7_CONF_DCM_EN_U_7_POS      1
#define SPU_USER_7_CONF_FEC_TYPE_U_7_BIT    ((uint32_t)0x00000001)
#define SPU_USER_7_CONF_FEC_TYPE_U_7_POS    0

#define SPU_USER_7_CONF_RU_SLOT_U_7_RST     0x0
#define SPU_USER_7_CONF_SS_NUM_U_7_RST      0x0
#define SPU_USER_7_CONF_SS_POS_U_7_RST      0x0
#define SPU_USER_7_CONF_RU_INDEX_U_7_RST    0x0
#define SPU_USER_7_CONF_RU_TYPE_U_7_RST     0x0
#define SPU_USER_7_CONF_STBC_U_7_RST        0x0
#define SPU_USER_7_CONF_BF_EN_U_7_RST       0x0
#define SPU_USER_7_CONF_DCM_EN_U_7_RST      0x0
#define SPU_USER_7_CONF_FEC_TYPE_U_7_RST    0x0

__INLINE void spu_user_7_conf_pack(uint8_t ru_slot_u7, uint8_t ss_num_u7, uint8_t ss_pos_u7, uint8_t ru_index_u7, uint8_t ru_type_u7, uint8_t stbc_u7, uint8_t bf_en_u7, uint8_t dcm_en_u7, uint8_t fec_type_u7)
{
	ASSERT_ERR((((uint32_t)ru_slot_u7 << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)ss_num_u7 << 14) & ~((uint32_t)0x0000C000)) == 0);
	ASSERT_ERR((((uint32_t)ss_pos_u7 << 11) & ~((uint32_t)0x00003800)) == 0);
	ASSERT_ERR((((uint32_t)ru_index_u7 << 8) & ~((uint32_t)0x00000700)) == 0);
	ASSERT_ERR((((uint32_t)ru_type_u7 << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)stbc_u7 << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)bf_en_u7 << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)dcm_en_u7 << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)fec_type_u7 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_USER_7_CONF_ADDR,  ((uint32_t)ru_slot_u7 << 16) |((uint32_t)ss_num_u7 << 14) |((uint32_t)ss_pos_u7 << 11) |((uint32_t)ru_index_u7 << 8) |((uint32_t)ru_type_u7 << 4) |((uint32_t)stbc_u7 << 3) |((uint32_t)bf_en_u7 << 2) |((uint32_t)dcm_en_u7 << 1) |((uint32_t)fec_type_u7 << 0));
}

__INLINE void spu_user_7_conf_unpack(uint8_t* ru_slot_u7, uint8_t* ss_num_u7, uint8_t* ss_pos_u7, uint8_t* ru_index_u7, uint8_t* ru_type_u7, uint8_t* stbc_u7, uint8_t* bf_en_u7, uint8_t* dcm_en_u7, uint8_t* fec_type_u7)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_7_CONF_ADDR);

	*ru_slot_u7 = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*ss_num_u7 = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*ss_pos_u7 = (localVal & ((uint32_t)0x00003800)) >>  11;
	*ru_index_u7 = (localVal & ((uint32_t)0x00000700)) >>  8;
	*ru_type_u7 = (localVal & ((uint32_t)0x00000070)) >>  4;
	*stbc_u7 = (localVal & ((uint32_t)0x00000008)) >>  3;
	*bf_en_u7 = (localVal & ((uint32_t)0x00000004)) >>  2;
	*dcm_en_u7 = (localVal & ((uint32_t)0x00000002)) >>  1;
	*fec_type_u7 = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t spu_user_7_conf_ru_slot_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_7_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void spu_user_7_conf_ru_slot_u_7_setf(uint8_t ruslotu7)
{
	ASSERT_ERR((((uint32_t)ruslotu7 << 16) & ~((uint32_t)0x003F0000)) == 0);
	REG_PL_WR(SPU_USER_7_CONF_ADDR, (REG_PL_RD(SPU_USER_7_CONF_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)ruslotu7 <<16));
}
__INLINE uint8_t spu_user_7_conf_ss_num_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_7_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE void spu_user_7_conf_ss_num_u_7_setf(uint8_t ssnumu7)
{
	ASSERT_ERR((((uint32_t)ssnumu7 << 14) & ~((uint32_t)0x0000C000)) == 0);
	REG_PL_WR(SPU_USER_7_CONF_ADDR, (REG_PL_RD(SPU_USER_7_CONF_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)ssnumu7 <<14));
}
__INLINE uint8_t spu_user_7_conf_ss_pos_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_7_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003800)) >> 11);
}
__INLINE void spu_user_7_conf_ss_pos_u_7_setf(uint8_t ssposu7)
{
	ASSERT_ERR((((uint32_t)ssposu7 << 11) & ~((uint32_t)0x00003800)) == 0);
	REG_PL_WR(SPU_USER_7_CONF_ADDR, (REG_PL_RD(SPU_USER_7_CONF_ADDR) & ~((uint32_t)0x00003800)) | ((uint32_t)ssposu7 <<11));
}
__INLINE uint8_t spu_user_7_conf_ru_index_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_7_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000700)) >> 8);
}
__INLINE void spu_user_7_conf_ru_index_u_7_setf(uint8_t ruindexu7)
{
	ASSERT_ERR((((uint32_t)ruindexu7 << 8) & ~((uint32_t)0x00000700)) == 0);
	REG_PL_WR(SPU_USER_7_CONF_ADDR, (REG_PL_RD(SPU_USER_7_CONF_ADDR) & ~((uint32_t)0x00000700)) | ((uint32_t)ruindexu7 <<8));
}
__INLINE uint8_t spu_user_7_conf_ru_type_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_7_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void spu_user_7_conf_ru_type_u_7_setf(uint8_t rutypeu7)
{
	ASSERT_ERR((((uint32_t)rutypeu7 << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(SPU_USER_7_CONF_ADDR, (REG_PL_RD(SPU_USER_7_CONF_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)rutypeu7 <<4));
}
__INLINE uint8_t spu_user_7_conf_stbc_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_7_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void spu_user_7_conf_stbc_u_7_setf(uint8_t stbcu7)
{
	ASSERT_ERR((((uint32_t)stbcu7 << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(SPU_USER_7_CONF_ADDR, (REG_PL_RD(SPU_USER_7_CONF_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)stbcu7 <<3));
}
__INLINE uint8_t spu_user_7_conf_bf_en_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_7_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void spu_user_7_conf_bf_en_u_7_setf(uint8_t bfenu7)
{
	ASSERT_ERR((((uint32_t)bfenu7 << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(SPU_USER_7_CONF_ADDR, (REG_PL_RD(SPU_USER_7_CONF_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)bfenu7 <<2));
}
__INLINE uint8_t spu_user_7_conf_dcm_en_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_7_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void spu_user_7_conf_dcm_en_u_7_setf(uint8_t dcmenu7)
{
	ASSERT_ERR((((uint32_t)dcmenu7 << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(SPU_USER_7_CONF_ADDR, (REG_PL_RD(SPU_USER_7_CONF_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)dcmenu7 <<1));
}
__INLINE uint8_t spu_user_7_conf_fec_type_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_7_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void spu_user_7_conf_fec_type_u_7_setf(uint8_t fectypeu7)
{
	ASSERT_ERR((((uint32_t)fectypeu7 << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_USER_7_CONF_ADDR, (REG_PL_RD(SPU_USER_7_CONF_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)fectypeu7 <<0));
}

/**
 * @brief SCALE_HESTF_U_01 register definition
 *  HESTF scaling users 0 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_HESTF_U1            0x0
 *    15:00 SCALE_HESTF_U0            0x0
 * </pre>
 */
#define SPU_SCALE_HESTF_U_01_ADDR        (REG_SPU_BASE_ADDR+0x000000A0)
#define SPU_SCALE_HESTF_U_01_OFFSET      0x000000A0
#define SPU_SCALE_HESTF_U_01_INDEX       0x00000028
#define SPU_SCALE_HESTF_U_01_RESET       0x00000000

__INLINE uint32_t  spu_scale_hestf_u_01_get(void)
{
	return REG_PL_RD(SPU_SCALE_HESTF_U_01_ADDR);
}

__INLINE void spu_scale_hestf_u_01_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_HESTF_U_01_ADDR, value);
}

// field definitions
#define SPU_SCALE_HESTF_U_01_SCALE_HESTF_U_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_HESTF_U_01_SCALE_HESTF_U_1_LSB    16
#define SPU_SCALE_HESTF_U_01_SCALE_HESTF_U_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_HESTF_U_01_SCALE_HESTF_U_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_HESTF_U_01_SCALE_HESTF_U_0_LSB    0
#define SPU_SCALE_HESTF_U_01_SCALE_HESTF_U_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_HESTF_U_01_SCALE_HESTF_U_1_RST    0x0
#define SPU_SCALE_HESTF_U_01_SCALE_HESTF_U_0_RST    0x0

__INLINE void spu_scale_hestf_u_01_pack(uint16_t scale_hestf_u1, uint16_t scale_hestf_u0)
{
	ASSERT_ERR((((uint32_t)scale_hestf_u1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_hestf_u0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_HESTF_U_01_ADDR,  ((uint32_t)scale_hestf_u1 << 16) |((uint32_t)scale_hestf_u0 << 0));
}

__INLINE void spu_scale_hestf_u_01_unpack(uint16_t* scale_hestf_u1, uint16_t* scale_hestf_u0)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HESTF_U_01_ADDR);

	*scale_hestf_u1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_hestf_u0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_hestf_u_01_scale_hestf_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HESTF_U_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_hestf_u_01_scale_hestf_u_1_setf(uint16_t scalehestfu1)
{
	ASSERT_ERR((((uint32_t)scalehestfu1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_HESTF_U_01_ADDR, (REG_PL_RD(SPU_SCALE_HESTF_U_01_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalehestfu1 <<16));
}
__INLINE uint16_t spu_scale_hestf_u_01_scale_hestf_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HESTF_U_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_hestf_u_01_scale_hestf_u_0_setf(uint16_t scalehestfu0)
{
	ASSERT_ERR((((uint32_t)scalehestfu0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_HESTF_U_01_ADDR, (REG_PL_RD(SPU_SCALE_HESTF_U_01_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalehestfu0 <<0));
}

/**
 * @brief SCALE_HESTF_U_23 register definition
 *  HESTF scaling users 2 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_HESTF_U3            0x0
 *    15:00 SCALE_HESTF_U2            0x0
 * </pre>
 */
#define SPU_SCALE_HESTF_U_23_ADDR        (REG_SPU_BASE_ADDR+0x000000A4)
#define SPU_SCALE_HESTF_U_23_OFFSET      0x000000A4
#define SPU_SCALE_HESTF_U_23_INDEX       0x00000029
#define SPU_SCALE_HESTF_U_23_RESET       0x00000000

__INLINE uint32_t  spu_scale_hestf_u_23_get(void)
{
	return REG_PL_RD(SPU_SCALE_HESTF_U_23_ADDR);
}

__INLINE void spu_scale_hestf_u_23_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_HESTF_U_23_ADDR, value);
}

// field definitions
#define SPU_SCALE_HESTF_U_23_SCALE_HESTF_U_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_HESTF_U_23_SCALE_HESTF_U_3_LSB    16
#define SPU_SCALE_HESTF_U_23_SCALE_HESTF_U_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_HESTF_U_23_SCALE_HESTF_U_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_HESTF_U_23_SCALE_HESTF_U_2_LSB    0
#define SPU_SCALE_HESTF_U_23_SCALE_HESTF_U_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_HESTF_U_23_SCALE_HESTF_U_3_RST    0x0
#define SPU_SCALE_HESTF_U_23_SCALE_HESTF_U_2_RST    0x0

__INLINE void spu_scale_hestf_u_23_pack(uint16_t scale_hestf_u3, uint16_t scale_hestf_u2)
{
	ASSERT_ERR((((uint32_t)scale_hestf_u3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_hestf_u2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_HESTF_U_23_ADDR,  ((uint32_t)scale_hestf_u3 << 16) |((uint32_t)scale_hestf_u2 << 0));
}

__INLINE void spu_scale_hestf_u_23_unpack(uint16_t* scale_hestf_u3, uint16_t* scale_hestf_u2)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HESTF_U_23_ADDR);

	*scale_hestf_u3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_hestf_u2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_hestf_u_23_scale_hestf_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HESTF_U_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_hestf_u_23_scale_hestf_u_3_setf(uint16_t scalehestfu3)
{
	ASSERT_ERR((((uint32_t)scalehestfu3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_HESTF_U_23_ADDR, (REG_PL_RD(SPU_SCALE_HESTF_U_23_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalehestfu3 <<16));
}
__INLINE uint16_t spu_scale_hestf_u_23_scale_hestf_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HESTF_U_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_hestf_u_23_scale_hestf_u_2_setf(uint16_t scalehestfu2)
{
	ASSERT_ERR((((uint32_t)scalehestfu2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_HESTF_U_23_ADDR, (REG_PL_RD(SPU_SCALE_HESTF_U_23_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalehestfu2 <<0));
}

/**
 * @brief SCALE_HESTF_U_45 register definition
 *  HESTF scaling users 4 5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_HESTF_U5            0x0
 *    15:00 SCALE_HESTF_U4            0x0
 * </pre>
 */
#define SPU_SCALE_HESTF_U_45_ADDR        (REG_SPU_BASE_ADDR+0x000000A8)
#define SPU_SCALE_HESTF_U_45_OFFSET      0x000000A8
#define SPU_SCALE_HESTF_U_45_INDEX       0x0000002A
#define SPU_SCALE_HESTF_U_45_RESET       0x00000000

__INLINE uint32_t  spu_scale_hestf_u_45_get(void)
{
	return REG_PL_RD(SPU_SCALE_HESTF_U_45_ADDR);
}

__INLINE void spu_scale_hestf_u_45_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_HESTF_U_45_ADDR, value);
}

// field definitions
#define SPU_SCALE_HESTF_U_45_SCALE_HESTF_U_5_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_HESTF_U_45_SCALE_HESTF_U_5_LSB    16
#define SPU_SCALE_HESTF_U_45_SCALE_HESTF_U_5_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_HESTF_U_45_SCALE_HESTF_U_4_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_HESTF_U_45_SCALE_HESTF_U_4_LSB    0
#define SPU_SCALE_HESTF_U_45_SCALE_HESTF_U_4_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_HESTF_U_45_SCALE_HESTF_U_5_RST    0x0
#define SPU_SCALE_HESTF_U_45_SCALE_HESTF_U_4_RST    0x0

__INLINE void spu_scale_hestf_u_45_pack(uint16_t scale_hestf_u5, uint16_t scale_hestf_u4)
{
	ASSERT_ERR((((uint32_t)scale_hestf_u5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_hestf_u4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_HESTF_U_45_ADDR,  ((uint32_t)scale_hestf_u5 << 16) |((uint32_t)scale_hestf_u4 << 0));
}

__INLINE void spu_scale_hestf_u_45_unpack(uint16_t* scale_hestf_u5, uint16_t* scale_hestf_u4)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HESTF_U_45_ADDR);

	*scale_hestf_u5 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_hestf_u4 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_hestf_u_45_scale_hestf_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HESTF_U_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_hestf_u_45_scale_hestf_u_5_setf(uint16_t scalehestfu5)
{
	ASSERT_ERR((((uint32_t)scalehestfu5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_HESTF_U_45_ADDR, (REG_PL_RD(SPU_SCALE_HESTF_U_45_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalehestfu5 <<16));
}
__INLINE uint16_t spu_scale_hestf_u_45_scale_hestf_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HESTF_U_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_hestf_u_45_scale_hestf_u_4_setf(uint16_t scalehestfu4)
{
	ASSERT_ERR((((uint32_t)scalehestfu4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_HESTF_U_45_ADDR, (REG_PL_RD(SPU_SCALE_HESTF_U_45_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalehestfu4 <<0));
}

/**
 * @brief SCALE_HESTF_U_67 register definition
 *  HESTF scaling users 6 7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_HESTF_U7            0x0
 *    15:00 SCALE_HESTF_U6            0x0
 * </pre>
 */
#define SPU_SCALE_HESTF_U_67_ADDR        (REG_SPU_BASE_ADDR+0x000000AC)
#define SPU_SCALE_HESTF_U_67_OFFSET      0x000000AC
#define SPU_SCALE_HESTF_U_67_INDEX       0x0000002B
#define SPU_SCALE_HESTF_U_67_RESET       0x00000000

__INLINE uint32_t  spu_scale_hestf_u_67_get(void)
{
	return REG_PL_RD(SPU_SCALE_HESTF_U_67_ADDR);
}

__INLINE void spu_scale_hestf_u_67_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_HESTF_U_67_ADDR, value);
}

// field definitions
#define SPU_SCALE_HESTF_U_67_SCALE_HESTF_U_7_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_HESTF_U_67_SCALE_HESTF_U_7_LSB    16
#define SPU_SCALE_HESTF_U_67_SCALE_HESTF_U_7_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_HESTF_U_67_SCALE_HESTF_U_6_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_HESTF_U_67_SCALE_HESTF_U_6_LSB    0
#define SPU_SCALE_HESTF_U_67_SCALE_HESTF_U_6_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_HESTF_U_67_SCALE_HESTF_U_7_RST    0x0
#define SPU_SCALE_HESTF_U_67_SCALE_HESTF_U_6_RST    0x0

__INLINE void spu_scale_hestf_u_67_pack(uint16_t scale_hestf_u7, uint16_t scale_hestf_u6)
{
	ASSERT_ERR((((uint32_t)scale_hestf_u7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_hestf_u6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_HESTF_U_67_ADDR,  ((uint32_t)scale_hestf_u7 << 16) |((uint32_t)scale_hestf_u6 << 0));
}

__INLINE void spu_scale_hestf_u_67_unpack(uint16_t* scale_hestf_u7, uint16_t* scale_hestf_u6)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HESTF_U_67_ADDR);

	*scale_hestf_u7 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_hestf_u6 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_hestf_u_67_scale_hestf_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HESTF_U_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_hestf_u_67_scale_hestf_u_7_setf(uint16_t scalehestfu7)
{
	ASSERT_ERR((((uint32_t)scalehestfu7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_HESTF_U_67_ADDR, (REG_PL_RD(SPU_SCALE_HESTF_U_67_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalehestfu7 <<16));
}
__INLINE uint16_t spu_scale_hestf_u_67_scale_hestf_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HESTF_U_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_hestf_u_67_scale_hestf_u_6_setf(uint16_t scalehestfu6)
{
	ASSERT_ERR((((uint32_t)scalehestfu6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_HESTF_U_67_ADDR, (REG_PL_RD(SPU_SCALE_HESTF_U_67_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalehestfu6 <<0));
}

/**
 * @brief SCALE_HELTF_U_01 register definition
 *  HELTF scaling users 0 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_HELTF_U1            0x0
 *    15:00 SCALE_HELTF_U0            0x0
 * </pre>
 */
#define SPU_SCALE_HELTF_U_01_ADDR        (REG_SPU_BASE_ADDR+0x000000B0)
#define SPU_SCALE_HELTF_U_01_OFFSET      0x000000B0
#define SPU_SCALE_HELTF_U_01_INDEX       0x0000002C
#define SPU_SCALE_HELTF_U_01_RESET       0x00000000

__INLINE uint32_t  spu_scale_heltf_u_01_get(void)
{
	return REG_PL_RD(SPU_SCALE_HELTF_U_01_ADDR);
}

__INLINE void spu_scale_heltf_u_01_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_HELTF_U_01_ADDR, value);
}

// field definitions
#define SPU_SCALE_HELTF_U_01_SCALE_HELTF_U_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_HELTF_U_01_SCALE_HELTF_U_1_LSB    16
#define SPU_SCALE_HELTF_U_01_SCALE_HELTF_U_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_HELTF_U_01_SCALE_HELTF_U_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_HELTF_U_01_SCALE_HELTF_U_0_LSB    0
#define SPU_SCALE_HELTF_U_01_SCALE_HELTF_U_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_HELTF_U_01_SCALE_HELTF_U_1_RST    0x0
#define SPU_SCALE_HELTF_U_01_SCALE_HELTF_U_0_RST    0x0

__INLINE void spu_scale_heltf_u_01_pack(uint16_t scale_heltf_u1, uint16_t scale_heltf_u0)
{
	ASSERT_ERR((((uint32_t)scale_heltf_u1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_heltf_u0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_HELTF_U_01_ADDR,  ((uint32_t)scale_heltf_u1 << 16) |((uint32_t)scale_heltf_u0 << 0));
}

__INLINE void spu_scale_heltf_u_01_unpack(uint16_t* scale_heltf_u1, uint16_t* scale_heltf_u0)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HELTF_U_01_ADDR);

	*scale_heltf_u1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_heltf_u0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_heltf_u_01_scale_heltf_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HELTF_U_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_heltf_u_01_scale_heltf_u_1_setf(uint16_t scaleheltfu1)
{
	ASSERT_ERR((((uint32_t)scaleheltfu1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_HELTF_U_01_ADDR, (REG_PL_RD(SPU_SCALE_HELTF_U_01_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleheltfu1 <<16));
}
__INLINE uint16_t spu_scale_heltf_u_01_scale_heltf_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HELTF_U_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_heltf_u_01_scale_heltf_u_0_setf(uint16_t scaleheltfu0)
{
	ASSERT_ERR((((uint32_t)scaleheltfu0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_HELTF_U_01_ADDR, (REG_PL_RD(SPU_SCALE_HELTF_U_01_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleheltfu0 <<0));
}

/**
 * @brief SCALE_HELTF_U_23 register definition
 *  HELTF scaling users 2 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_HELTF_U3            0x0
 *    15:00 SCALE_HELTF_U2            0x0
 * </pre>
 */
#define SPU_SCALE_HELTF_U_23_ADDR        (REG_SPU_BASE_ADDR+0x000000B4)
#define SPU_SCALE_HELTF_U_23_OFFSET      0x000000B4
#define SPU_SCALE_HELTF_U_23_INDEX       0x0000002D
#define SPU_SCALE_HELTF_U_23_RESET       0x00000000

__INLINE uint32_t  spu_scale_heltf_u_23_get(void)
{
	return REG_PL_RD(SPU_SCALE_HELTF_U_23_ADDR);
}

__INLINE void spu_scale_heltf_u_23_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_HELTF_U_23_ADDR, value);
}

// field definitions
#define SPU_SCALE_HELTF_U_23_SCALE_HELTF_U_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_HELTF_U_23_SCALE_HELTF_U_3_LSB    16
#define SPU_SCALE_HELTF_U_23_SCALE_HELTF_U_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_HELTF_U_23_SCALE_HELTF_U_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_HELTF_U_23_SCALE_HELTF_U_2_LSB    0
#define SPU_SCALE_HELTF_U_23_SCALE_HELTF_U_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_HELTF_U_23_SCALE_HELTF_U_3_RST    0x0
#define SPU_SCALE_HELTF_U_23_SCALE_HELTF_U_2_RST    0x0

__INLINE void spu_scale_heltf_u_23_pack(uint16_t scale_heltf_u3, uint16_t scale_heltf_u2)
{
	ASSERT_ERR((((uint32_t)scale_heltf_u3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_heltf_u2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_HELTF_U_23_ADDR,  ((uint32_t)scale_heltf_u3 << 16) |((uint32_t)scale_heltf_u2 << 0));
}

__INLINE void spu_scale_heltf_u_23_unpack(uint16_t* scale_heltf_u3, uint16_t* scale_heltf_u2)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HELTF_U_23_ADDR);

	*scale_heltf_u3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_heltf_u2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_heltf_u_23_scale_heltf_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HELTF_U_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_heltf_u_23_scale_heltf_u_3_setf(uint16_t scaleheltfu3)
{
	ASSERT_ERR((((uint32_t)scaleheltfu3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_HELTF_U_23_ADDR, (REG_PL_RD(SPU_SCALE_HELTF_U_23_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleheltfu3 <<16));
}
__INLINE uint16_t spu_scale_heltf_u_23_scale_heltf_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HELTF_U_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_heltf_u_23_scale_heltf_u_2_setf(uint16_t scaleheltfu2)
{
	ASSERT_ERR((((uint32_t)scaleheltfu2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_HELTF_U_23_ADDR, (REG_PL_RD(SPU_SCALE_HELTF_U_23_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleheltfu2 <<0));
}

/**
 * @brief SCALE_HELTF_U_45 register definition
 *  HELTF scaling users 4 5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_HELTF_U5            0x0
 *    15:00 SCALE_HELTF_U4            0x0
 * </pre>
 */
#define SPU_SCALE_HELTF_U_45_ADDR        (REG_SPU_BASE_ADDR+0x000000B8)
#define SPU_SCALE_HELTF_U_45_OFFSET      0x000000B8
#define SPU_SCALE_HELTF_U_45_INDEX       0x0000002E
#define SPU_SCALE_HELTF_U_45_RESET       0x00000000

__INLINE uint32_t  spu_scale_heltf_u_45_get(void)
{
	return REG_PL_RD(SPU_SCALE_HELTF_U_45_ADDR);
}

__INLINE void spu_scale_heltf_u_45_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_HELTF_U_45_ADDR, value);
}

// field definitions
#define SPU_SCALE_HELTF_U_45_SCALE_HELTF_U_5_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_HELTF_U_45_SCALE_HELTF_U_5_LSB    16
#define SPU_SCALE_HELTF_U_45_SCALE_HELTF_U_5_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_HELTF_U_45_SCALE_HELTF_U_4_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_HELTF_U_45_SCALE_HELTF_U_4_LSB    0
#define SPU_SCALE_HELTF_U_45_SCALE_HELTF_U_4_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_HELTF_U_45_SCALE_HELTF_U_5_RST    0x0
#define SPU_SCALE_HELTF_U_45_SCALE_HELTF_U_4_RST    0x0

__INLINE void spu_scale_heltf_u_45_pack(uint16_t scale_heltf_u5, uint16_t scale_heltf_u4)
{
	ASSERT_ERR((((uint32_t)scale_heltf_u5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_heltf_u4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_HELTF_U_45_ADDR,  ((uint32_t)scale_heltf_u5 << 16) |((uint32_t)scale_heltf_u4 << 0));
}

__INLINE void spu_scale_heltf_u_45_unpack(uint16_t* scale_heltf_u5, uint16_t* scale_heltf_u4)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HELTF_U_45_ADDR);

	*scale_heltf_u5 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_heltf_u4 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_heltf_u_45_scale_heltf_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HELTF_U_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_heltf_u_45_scale_heltf_u_5_setf(uint16_t scaleheltfu5)
{
	ASSERT_ERR((((uint32_t)scaleheltfu5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_HELTF_U_45_ADDR, (REG_PL_RD(SPU_SCALE_HELTF_U_45_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleheltfu5 <<16));
}
__INLINE uint16_t spu_scale_heltf_u_45_scale_heltf_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HELTF_U_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_heltf_u_45_scale_heltf_u_4_setf(uint16_t scaleheltfu4)
{
	ASSERT_ERR((((uint32_t)scaleheltfu4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_HELTF_U_45_ADDR, (REG_PL_RD(SPU_SCALE_HELTF_U_45_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleheltfu4 <<0));
}

/**
 * @brief SCALE_HELTF_U_67 register definition
 *  HELTF scaling users 6 7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_HELTF_U7            0x0
 *    15:00 SCALE_HELTF_U6            0x0
 * </pre>
 */
#define SPU_SCALE_HELTF_U_67_ADDR        (REG_SPU_BASE_ADDR+0x000000BC)
#define SPU_SCALE_HELTF_U_67_OFFSET      0x000000BC
#define SPU_SCALE_HELTF_U_67_INDEX       0x0000002F
#define SPU_SCALE_HELTF_U_67_RESET       0x00000000

__INLINE uint32_t  spu_scale_heltf_u_67_get(void)
{
	return REG_PL_RD(SPU_SCALE_HELTF_U_67_ADDR);
}

__INLINE void spu_scale_heltf_u_67_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_HELTF_U_67_ADDR, value);
}

// field definitions
#define SPU_SCALE_HELTF_U_67_SCALE_HELTF_U_7_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_HELTF_U_67_SCALE_HELTF_U_7_LSB    16
#define SPU_SCALE_HELTF_U_67_SCALE_HELTF_U_7_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_HELTF_U_67_SCALE_HELTF_U_6_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_HELTF_U_67_SCALE_HELTF_U_6_LSB    0
#define SPU_SCALE_HELTF_U_67_SCALE_HELTF_U_6_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_HELTF_U_67_SCALE_HELTF_U_7_RST    0x0
#define SPU_SCALE_HELTF_U_67_SCALE_HELTF_U_6_RST    0x0

__INLINE void spu_scale_heltf_u_67_pack(uint16_t scale_heltf_u7, uint16_t scale_heltf_u6)
{
	ASSERT_ERR((((uint32_t)scale_heltf_u7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_heltf_u6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_HELTF_U_67_ADDR,  ((uint32_t)scale_heltf_u7 << 16) |((uint32_t)scale_heltf_u6 << 0));
}

__INLINE void spu_scale_heltf_u_67_unpack(uint16_t* scale_heltf_u7, uint16_t* scale_heltf_u6)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HELTF_U_67_ADDR);

	*scale_heltf_u7 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_heltf_u6 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_heltf_u_67_scale_heltf_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HELTF_U_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_heltf_u_67_scale_heltf_u_7_setf(uint16_t scaleheltfu7)
{
	ASSERT_ERR((((uint32_t)scaleheltfu7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_HELTF_U_67_ADDR, (REG_PL_RD(SPU_SCALE_HELTF_U_67_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleheltfu7 <<16));
}
__INLINE uint16_t spu_scale_heltf_u_67_scale_heltf_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_HELTF_U_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_heltf_u_67_scale_heltf_u_6_setf(uint16_t scaleheltfu6)
{
	ASSERT_ERR((((uint32_t)scaleheltfu6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_HELTF_U_67_ADDR, (REG_PL_RD(SPU_SCALE_HELTF_U_67_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleheltfu6 <<0));
}

/**
 * @brief SCALE_CM_U_01 register definition
 *  Constellation Mapper scaling users 0 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_CM_U1               0x0
 *    15:00 SCALE_CM_U0               0x0
 * </pre>
 */
#define SPU_SCALE_CM_U_01_ADDR        (REG_SPU_BASE_ADDR+0x000000C0)
#define SPU_SCALE_CM_U_01_OFFSET      0x000000C0
#define SPU_SCALE_CM_U_01_INDEX       0x00000030
#define SPU_SCALE_CM_U_01_RESET       0x00000000

__INLINE uint32_t  spu_scale_cm_u_01_get(void)
{
	return REG_PL_RD(SPU_SCALE_CM_U_01_ADDR);
}

__INLINE void spu_scale_cm_u_01_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_CM_U_01_ADDR, value);
}

// field definitions
#define SPU_SCALE_CM_U_01_SCALE_CM_U_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_CM_U_01_SCALE_CM_U_1_LSB    16
#define SPU_SCALE_CM_U_01_SCALE_CM_U_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_CM_U_01_SCALE_CM_U_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_CM_U_01_SCALE_CM_U_0_LSB    0
#define SPU_SCALE_CM_U_01_SCALE_CM_U_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_CM_U_01_SCALE_CM_U_1_RST    0x0
#define SPU_SCALE_CM_U_01_SCALE_CM_U_0_RST    0x0

__INLINE void spu_scale_cm_u_01_pack(uint16_t scale_cm_u1, uint16_t scale_cm_u0)
{
	ASSERT_ERR((((uint32_t)scale_cm_u1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_cm_u0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_CM_U_01_ADDR,  ((uint32_t)scale_cm_u1 << 16) |((uint32_t)scale_cm_u0 << 0));
}

__INLINE void spu_scale_cm_u_01_unpack(uint16_t* scale_cm_u1, uint16_t* scale_cm_u0)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_CM_U_01_ADDR);

	*scale_cm_u1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_cm_u0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_cm_u_01_scale_cm_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_CM_U_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_cm_u_01_scale_cm_u_1_setf(uint16_t scalecmu1)
{
	ASSERT_ERR((((uint32_t)scalecmu1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_CM_U_01_ADDR, (REG_PL_RD(SPU_SCALE_CM_U_01_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalecmu1 <<16));
}
__INLINE uint16_t spu_scale_cm_u_01_scale_cm_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_CM_U_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_cm_u_01_scale_cm_u_0_setf(uint16_t scalecmu0)
{
	ASSERT_ERR((((uint32_t)scalecmu0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_CM_U_01_ADDR, (REG_PL_RD(SPU_SCALE_CM_U_01_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalecmu0 <<0));
}

/**
 * @brief SCALE_CM_U_23 register definition
 *  Constellation Mapper scaling users 2 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_CM_U3               0x0
 *    15:00 SCALE_CM_U2               0x0
 * </pre>
 */
#define SPU_SCALE_CM_U_23_ADDR        (REG_SPU_BASE_ADDR+0x000000C4)
#define SPU_SCALE_CM_U_23_OFFSET      0x000000C4
#define SPU_SCALE_CM_U_23_INDEX       0x00000031
#define SPU_SCALE_CM_U_23_RESET       0x00000000

__INLINE uint32_t  spu_scale_cm_u_23_get(void)
{
	return REG_PL_RD(SPU_SCALE_CM_U_23_ADDR);
}

__INLINE void spu_scale_cm_u_23_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_CM_U_23_ADDR, value);
}

// field definitions
#define SPU_SCALE_CM_U_23_SCALE_CM_U_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_CM_U_23_SCALE_CM_U_3_LSB    16
#define SPU_SCALE_CM_U_23_SCALE_CM_U_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_CM_U_23_SCALE_CM_U_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_CM_U_23_SCALE_CM_U_2_LSB    0
#define SPU_SCALE_CM_U_23_SCALE_CM_U_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_CM_U_23_SCALE_CM_U_3_RST    0x0
#define SPU_SCALE_CM_U_23_SCALE_CM_U_2_RST    0x0

__INLINE void spu_scale_cm_u_23_pack(uint16_t scale_cm_u3, uint16_t scale_cm_u2)
{
	ASSERT_ERR((((uint32_t)scale_cm_u3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_cm_u2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_CM_U_23_ADDR,  ((uint32_t)scale_cm_u3 << 16) |((uint32_t)scale_cm_u2 << 0));
}

__INLINE void spu_scale_cm_u_23_unpack(uint16_t* scale_cm_u3, uint16_t* scale_cm_u2)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_CM_U_23_ADDR);

	*scale_cm_u3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_cm_u2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_cm_u_23_scale_cm_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_CM_U_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_cm_u_23_scale_cm_u_3_setf(uint16_t scalecmu3)
{
	ASSERT_ERR((((uint32_t)scalecmu3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_CM_U_23_ADDR, (REG_PL_RD(SPU_SCALE_CM_U_23_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalecmu3 <<16));
}
__INLINE uint16_t spu_scale_cm_u_23_scale_cm_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_CM_U_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_cm_u_23_scale_cm_u_2_setf(uint16_t scalecmu2)
{
	ASSERT_ERR((((uint32_t)scalecmu2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_CM_U_23_ADDR, (REG_PL_RD(SPU_SCALE_CM_U_23_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalecmu2 <<0));
}

/**
 * @brief SCALE_CM_U_45 register definition
 *  Constellation Mapper scaling users 4 5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_CM_U5               0x0
 *    15:00 SCALE_CM_U4               0x0
 * </pre>
 */
#define SPU_SCALE_CM_U_45_ADDR        (REG_SPU_BASE_ADDR+0x000000C8)
#define SPU_SCALE_CM_U_45_OFFSET      0x000000C8
#define SPU_SCALE_CM_U_45_INDEX       0x00000032
#define SPU_SCALE_CM_U_45_RESET       0x00000000

__INLINE uint32_t  spu_scale_cm_u_45_get(void)
{
	return REG_PL_RD(SPU_SCALE_CM_U_45_ADDR);
}

__INLINE void spu_scale_cm_u_45_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_CM_U_45_ADDR, value);
}

// field definitions
#define SPU_SCALE_CM_U_45_SCALE_CM_U_5_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_CM_U_45_SCALE_CM_U_5_LSB    16
#define SPU_SCALE_CM_U_45_SCALE_CM_U_5_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_CM_U_45_SCALE_CM_U_4_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_CM_U_45_SCALE_CM_U_4_LSB    0
#define SPU_SCALE_CM_U_45_SCALE_CM_U_4_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_CM_U_45_SCALE_CM_U_5_RST    0x0
#define SPU_SCALE_CM_U_45_SCALE_CM_U_4_RST    0x0

__INLINE void spu_scale_cm_u_45_pack(uint16_t scale_cm_u5, uint16_t scale_cm_u4)
{
	ASSERT_ERR((((uint32_t)scale_cm_u5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_cm_u4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_CM_U_45_ADDR,  ((uint32_t)scale_cm_u5 << 16) |((uint32_t)scale_cm_u4 << 0));
}

__INLINE void spu_scale_cm_u_45_unpack(uint16_t* scale_cm_u5, uint16_t* scale_cm_u4)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_CM_U_45_ADDR);

	*scale_cm_u5 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_cm_u4 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_cm_u_45_scale_cm_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_CM_U_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_cm_u_45_scale_cm_u_5_setf(uint16_t scalecmu5)
{
	ASSERT_ERR((((uint32_t)scalecmu5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_CM_U_45_ADDR, (REG_PL_RD(SPU_SCALE_CM_U_45_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalecmu5 <<16));
}
__INLINE uint16_t spu_scale_cm_u_45_scale_cm_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_CM_U_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_cm_u_45_scale_cm_u_4_setf(uint16_t scalecmu4)
{
	ASSERT_ERR((((uint32_t)scalecmu4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_CM_U_45_ADDR, (REG_PL_RD(SPU_SCALE_CM_U_45_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalecmu4 <<0));
}

/**
 * @brief SCALE_CM_U_67 register definition
 *  Constellation Mapper scaling users 6 7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_CM_U7               0x0
 *    15:00 SCALE_CM_U6               0x0
 * </pre>
 */
#define SPU_SCALE_CM_U_67_ADDR        (REG_SPU_BASE_ADDR+0x000000CC)
#define SPU_SCALE_CM_U_67_OFFSET      0x000000CC
#define SPU_SCALE_CM_U_67_INDEX       0x00000033
#define SPU_SCALE_CM_U_67_RESET       0x00000000

__INLINE uint32_t  spu_scale_cm_u_67_get(void)
{
	return REG_PL_RD(SPU_SCALE_CM_U_67_ADDR);
}

__INLINE void spu_scale_cm_u_67_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_CM_U_67_ADDR, value);
}

// field definitions
#define SPU_SCALE_CM_U_67_SCALE_CM_U_7_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_CM_U_67_SCALE_CM_U_7_LSB    16
#define SPU_SCALE_CM_U_67_SCALE_CM_U_7_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_CM_U_67_SCALE_CM_U_6_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_CM_U_67_SCALE_CM_U_6_LSB    0
#define SPU_SCALE_CM_U_67_SCALE_CM_U_6_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_CM_U_67_SCALE_CM_U_7_RST    0x0
#define SPU_SCALE_CM_U_67_SCALE_CM_U_6_RST    0x0

__INLINE void spu_scale_cm_u_67_pack(uint16_t scale_cm_u7, uint16_t scale_cm_u6)
{
	ASSERT_ERR((((uint32_t)scale_cm_u7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_cm_u6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_CM_U_67_ADDR,  ((uint32_t)scale_cm_u7 << 16) |((uint32_t)scale_cm_u6 << 0));
}

__INLINE void spu_scale_cm_u_67_unpack(uint16_t* scale_cm_u7, uint16_t* scale_cm_u6)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_CM_U_67_ADDR);

	*scale_cm_u7 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_cm_u6 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_cm_u_67_scale_cm_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_CM_U_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_cm_u_67_scale_cm_u_7_setf(uint16_t scalecmu7)
{
	ASSERT_ERR((((uint32_t)scalecmu7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_CM_U_67_ADDR, (REG_PL_RD(SPU_SCALE_CM_U_67_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalecmu7 <<16));
}
__INLINE uint16_t spu_scale_cm_u_67_scale_cm_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_CM_U_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_cm_u_67_scale_cm_u_6_setf(uint16_t scalecmu6)
{
	ASSERT_ERR((((uint32_t)scalecmu6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_CM_U_67_ADDR, (REG_PL_RD(SPU_SCALE_CM_U_67_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalecmu6 <<0));
}

/**
 * @brief SCALE_PG_U_01 register definition
 *  Pilot Generator scaling users 0 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_PG_U1               0x0
 *    15:00 SCALE_PG_U0               0x0
 * </pre>
 */
#define SPU_SCALE_PG_U_01_ADDR        (REG_SPU_BASE_ADDR+0x000000D0)
#define SPU_SCALE_PG_U_01_OFFSET      0x000000D0
#define SPU_SCALE_PG_U_01_INDEX       0x00000034
#define SPU_SCALE_PG_U_01_RESET       0x00000000

__INLINE uint32_t  spu_scale_pg_u_01_get(void)
{
	return REG_PL_RD(SPU_SCALE_PG_U_01_ADDR);
}

__INLINE void spu_scale_pg_u_01_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_PG_U_01_ADDR, value);
}

// field definitions
#define SPU_SCALE_PG_U_01_SCALE_PG_U_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_PG_U_01_SCALE_PG_U_1_LSB    16
#define SPU_SCALE_PG_U_01_SCALE_PG_U_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_PG_U_01_SCALE_PG_U_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_PG_U_01_SCALE_PG_U_0_LSB    0
#define SPU_SCALE_PG_U_01_SCALE_PG_U_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_PG_U_01_SCALE_PG_U_1_RST    0x0
#define SPU_SCALE_PG_U_01_SCALE_PG_U_0_RST    0x0

__INLINE void spu_scale_pg_u_01_pack(uint16_t scale_pg_u1, uint16_t scale_pg_u0)
{
	ASSERT_ERR((((uint32_t)scale_pg_u1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_pg_u0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_PG_U_01_ADDR,  ((uint32_t)scale_pg_u1 << 16) |((uint32_t)scale_pg_u0 << 0));
}

__INLINE void spu_scale_pg_u_01_unpack(uint16_t* scale_pg_u1, uint16_t* scale_pg_u0)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_PG_U_01_ADDR);

	*scale_pg_u1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_pg_u0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_pg_u_01_scale_pg_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_PG_U_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_pg_u_01_scale_pg_u_1_setf(uint16_t scalepgu1)
{
	ASSERT_ERR((((uint32_t)scalepgu1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_PG_U_01_ADDR, (REG_PL_RD(SPU_SCALE_PG_U_01_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalepgu1 <<16));
}
__INLINE uint16_t spu_scale_pg_u_01_scale_pg_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_PG_U_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_pg_u_01_scale_pg_u_0_setf(uint16_t scalepgu0)
{
	ASSERT_ERR((((uint32_t)scalepgu0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_PG_U_01_ADDR, (REG_PL_RD(SPU_SCALE_PG_U_01_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalepgu0 <<0));
}

/**
 * @brief SCALE_PG_U_23 register definition
 *  Pilot Generator scaling users 2 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_PG_U3               0x0
 *    15:00 SCALE_PG_U2               0x0
 * </pre>
 */
#define SPU_SCALE_PG_U_23_ADDR        (REG_SPU_BASE_ADDR+0x000000D4)
#define SPU_SCALE_PG_U_23_OFFSET      0x000000D4
#define SPU_SCALE_PG_U_23_INDEX       0x00000035
#define SPU_SCALE_PG_U_23_RESET       0x00000000

__INLINE uint32_t  spu_scale_pg_u_23_get(void)
{
	return REG_PL_RD(SPU_SCALE_PG_U_23_ADDR);
}

__INLINE void spu_scale_pg_u_23_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_PG_U_23_ADDR, value);
}

// field definitions
#define SPU_SCALE_PG_U_23_SCALE_PG_U_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_PG_U_23_SCALE_PG_U_3_LSB    16
#define SPU_SCALE_PG_U_23_SCALE_PG_U_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_PG_U_23_SCALE_PG_U_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_PG_U_23_SCALE_PG_U_2_LSB    0
#define SPU_SCALE_PG_U_23_SCALE_PG_U_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_PG_U_23_SCALE_PG_U_3_RST    0x0
#define SPU_SCALE_PG_U_23_SCALE_PG_U_2_RST    0x0

__INLINE void spu_scale_pg_u_23_pack(uint16_t scale_pg_u3, uint16_t scale_pg_u2)
{
	ASSERT_ERR((((uint32_t)scale_pg_u3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_pg_u2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_PG_U_23_ADDR,  ((uint32_t)scale_pg_u3 << 16) |((uint32_t)scale_pg_u2 << 0));
}

__INLINE void spu_scale_pg_u_23_unpack(uint16_t* scale_pg_u3, uint16_t* scale_pg_u2)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_PG_U_23_ADDR);

	*scale_pg_u3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_pg_u2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_pg_u_23_scale_pg_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_PG_U_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_pg_u_23_scale_pg_u_3_setf(uint16_t scalepgu3)
{
	ASSERT_ERR((((uint32_t)scalepgu3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_PG_U_23_ADDR, (REG_PL_RD(SPU_SCALE_PG_U_23_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalepgu3 <<16));
}
__INLINE uint16_t spu_scale_pg_u_23_scale_pg_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_PG_U_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_pg_u_23_scale_pg_u_2_setf(uint16_t scalepgu2)
{
	ASSERT_ERR((((uint32_t)scalepgu2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_PG_U_23_ADDR, (REG_PL_RD(SPU_SCALE_PG_U_23_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalepgu2 <<0));
}

/**
 * @brief SCALE_PG_U_45 register definition
 *  Pilot Generator scaling users 4 5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_PG_U7               0x0
 *    15:00 SCALE_PG_U6               0x0
 * </pre>
 */
#define SPU_SCALE_PG_U_45_ADDR        (REG_SPU_BASE_ADDR+0x000000D8)
#define SPU_SCALE_PG_U_45_OFFSET      0x000000D8
#define SPU_SCALE_PG_U_45_INDEX       0x00000036
#define SPU_SCALE_PG_U_45_RESET       0x00000000

__INLINE uint32_t  spu_scale_pg_u_45_get(void)
{
	return REG_PL_RD(SPU_SCALE_PG_U_45_ADDR);
}

__INLINE void spu_scale_pg_u_45_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_PG_U_45_ADDR, value);
}

// field definitions
#define SPU_SCALE_PG_U_45_SCALE_PG_U_7_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_PG_U_45_SCALE_PG_U_7_LSB    16
#define SPU_SCALE_PG_U_45_SCALE_PG_U_7_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_PG_U_45_SCALE_PG_U_6_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_PG_U_45_SCALE_PG_U_6_LSB    0
#define SPU_SCALE_PG_U_45_SCALE_PG_U_6_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_PG_U_45_SCALE_PG_U_7_RST    0x0
#define SPU_SCALE_PG_U_45_SCALE_PG_U_6_RST    0x0

__INLINE void spu_scale_pg_u_45_pack(uint16_t scale_pg_u7, uint16_t scale_pg_u6)
{
	ASSERT_ERR((((uint32_t)scale_pg_u7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_pg_u6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_PG_U_45_ADDR,  ((uint32_t)scale_pg_u7 << 16) |((uint32_t)scale_pg_u6 << 0));
}

__INLINE void spu_scale_pg_u_45_unpack(uint16_t* scale_pg_u7, uint16_t* scale_pg_u6)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_PG_U_45_ADDR);

	*scale_pg_u7 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_pg_u6 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_pg_u_45_scale_pg_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_PG_U_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_pg_u_45_scale_pg_u_7_setf(uint16_t scalepgu7)
{
	ASSERT_ERR((((uint32_t)scalepgu7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_PG_U_45_ADDR, (REG_PL_RD(SPU_SCALE_PG_U_45_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalepgu7 <<16));
}
__INLINE uint16_t spu_scale_pg_u_45_scale_pg_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_PG_U_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_pg_u_45_scale_pg_u_6_setf(uint16_t scalepgu6)
{
	ASSERT_ERR((((uint32_t)scalepgu6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_PG_U_45_ADDR, (REG_PL_RD(SPU_SCALE_PG_U_45_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalepgu6 <<0));
}

/**
 * @brief SCALE_PG_U_67 register definition
 *  Pilot Generator scaling users 6 7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_PG_U7               0x0
 *    15:00 SCALE_PG_U6               0x0
 * </pre>
 */
#define SPU_SCALE_PG_U_67_ADDR        (REG_SPU_BASE_ADDR+0x000000DC)
#define SPU_SCALE_PG_U_67_OFFSET      0x000000DC
#define SPU_SCALE_PG_U_67_INDEX       0x00000037
#define SPU_SCALE_PG_U_67_RESET       0x00000000

__INLINE uint32_t  spu_scale_pg_u_67_get(void)
{
	return REG_PL_RD(SPU_SCALE_PG_U_67_ADDR);
}

__INLINE void spu_scale_pg_u_67_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_PG_U_67_ADDR, value);
}

// field definitions
#define SPU_SCALE_PG_U_67_SCALE_PG_U_7_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_PG_U_67_SCALE_PG_U_7_LSB    16
#define SPU_SCALE_PG_U_67_SCALE_PG_U_7_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_PG_U_67_SCALE_PG_U_6_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_PG_U_67_SCALE_PG_U_6_LSB    0
#define SPU_SCALE_PG_U_67_SCALE_PG_U_6_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_PG_U_67_SCALE_PG_U_7_RST    0x0
#define SPU_SCALE_PG_U_67_SCALE_PG_U_6_RST    0x0

__INLINE void spu_scale_pg_u_67_pack(uint16_t scale_pg_u7, uint16_t scale_pg_u6)
{
	ASSERT_ERR((((uint32_t)scale_pg_u7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_pg_u6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_PG_U_67_ADDR,  ((uint32_t)scale_pg_u7 << 16) |((uint32_t)scale_pg_u6 << 0));
}

__INLINE void spu_scale_pg_u_67_unpack(uint16_t* scale_pg_u7, uint16_t* scale_pg_u6)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_PG_U_67_ADDR);

	*scale_pg_u7 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_pg_u6 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_pg_u_67_scale_pg_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_PG_U_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_pg_u_67_scale_pg_u_7_setf(uint16_t scalepgu7)
{
	ASSERT_ERR((((uint32_t)scalepgu7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_PG_U_67_ADDR, (REG_PL_RD(SPU_SCALE_PG_U_67_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalepgu7 <<16));
}
__INLINE uint16_t spu_scale_pg_u_67_scale_pg_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_PG_U_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_pg_u_67_scale_pg_u_6_setf(uint16_t scalepgu6)
{
	ASSERT_ERR((((uint32_t)scalepgu6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_PG_U_67_ADDR, (REG_PL_RD(SPU_SCALE_PG_U_67_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalepgu6 <<0));
}

/**
 * @brief SCALE_STREAM_U_01 register definition
 *  Stream scaling users 0 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_STREAM_U1           0x0
 *    15:00 SCALE_STREAM_U0           0x0
 * </pre>
 */
#define SPU_SCALE_STREAM_U_01_ADDR        (REG_SPU_BASE_ADDR+0x000000E0)
#define SPU_SCALE_STREAM_U_01_OFFSET      0x000000E0
#define SPU_SCALE_STREAM_U_01_INDEX       0x00000038
#define SPU_SCALE_STREAM_U_01_RESET       0x00000000

__INLINE uint32_t  spu_scale_stream_u_01_get(void)
{
	return REG_PL_RD(SPU_SCALE_STREAM_U_01_ADDR);
}

__INLINE void spu_scale_stream_u_01_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_STREAM_U_01_ADDR, value);
}

// field definitions
#define SPU_SCALE_STREAM_U_01_SCALE_STREAM_U_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_STREAM_U_01_SCALE_STREAM_U_1_LSB    16
#define SPU_SCALE_STREAM_U_01_SCALE_STREAM_U_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_STREAM_U_01_SCALE_STREAM_U_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_STREAM_U_01_SCALE_STREAM_U_0_LSB    0
#define SPU_SCALE_STREAM_U_01_SCALE_STREAM_U_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_STREAM_U_01_SCALE_STREAM_U_1_RST    0x0
#define SPU_SCALE_STREAM_U_01_SCALE_STREAM_U_0_RST    0x0

__INLINE void spu_scale_stream_u_01_pack(uint16_t scale_stream_u1, uint16_t scale_stream_u0)
{
	ASSERT_ERR((((uint32_t)scale_stream_u1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_stream_u0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_STREAM_U_01_ADDR,  ((uint32_t)scale_stream_u1 << 16) |((uint32_t)scale_stream_u0 << 0));
}

__INLINE void spu_scale_stream_u_01_unpack(uint16_t* scale_stream_u1, uint16_t* scale_stream_u0)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_STREAM_U_01_ADDR);

	*scale_stream_u1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_stream_u0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_stream_u_01_scale_stream_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_STREAM_U_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_stream_u_01_scale_stream_u_1_setf(uint16_t scalestreamu1)
{
	ASSERT_ERR((((uint32_t)scalestreamu1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_STREAM_U_01_ADDR, (REG_PL_RD(SPU_SCALE_STREAM_U_01_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalestreamu1 <<16));
}
__INLINE uint16_t spu_scale_stream_u_01_scale_stream_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_STREAM_U_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_stream_u_01_scale_stream_u_0_setf(uint16_t scalestreamu0)
{
	ASSERT_ERR((((uint32_t)scalestreamu0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_STREAM_U_01_ADDR, (REG_PL_RD(SPU_SCALE_STREAM_U_01_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalestreamu0 <<0));
}

/**
 * @brief SCALE_STREAM_U_23 register definition
 *  Stream scaling users 2 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_STREAM_U3           0x0
 *    15:00 SCALE_STREAM_U2           0x0
 * </pre>
 */
#define SPU_SCALE_STREAM_U_23_ADDR        (REG_SPU_BASE_ADDR+0x000000E4)
#define SPU_SCALE_STREAM_U_23_OFFSET      0x000000E4
#define SPU_SCALE_STREAM_U_23_INDEX       0x00000039
#define SPU_SCALE_STREAM_U_23_RESET       0x00000000

__INLINE uint32_t  spu_scale_stream_u_23_get(void)
{
	return REG_PL_RD(SPU_SCALE_STREAM_U_23_ADDR);
}

__INLINE void spu_scale_stream_u_23_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_STREAM_U_23_ADDR, value);
}

// field definitions
#define SPU_SCALE_STREAM_U_23_SCALE_STREAM_U_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_STREAM_U_23_SCALE_STREAM_U_3_LSB    16
#define SPU_SCALE_STREAM_U_23_SCALE_STREAM_U_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_STREAM_U_23_SCALE_STREAM_U_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_STREAM_U_23_SCALE_STREAM_U_2_LSB    0
#define SPU_SCALE_STREAM_U_23_SCALE_STREAM_U_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_STREAM_U_23_SCALE_STREAM_U_3_RST    0x0
#define SPU_SCALE_STREAM_U_23_SCALE_STREAM_U_2_RST    0x0

__INLINE void spu_scale_stream_u_23_pack(uint16_t scale_stream_u3, uint16_t scale_stream_u2)
{
	ASSERT_ERR((((uint32_t)scale_stream_u3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_stream_u2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_STREAM_U_23_ADDR,  ((uint32_t)scale_stream_u3 << 16) |((uint32_t)scale_stream_u2 << 0));
}

__INLINE void spu_scale_stream_u_23_unpack(uint16_t* scale_stream_u3, uint16_t* scale_stream_u2)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_STREAM_U_23_ADDR);

	*scale_stream_u3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_stream_u2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_stream_u_23_scale_stream_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_STREAM_U_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_stream_u_23_scale_stream_u_3_setf(uint16_t scalestreamu3)
{
	ASSERT_ERR((((uint32_t)scalestreamu3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_STREAM_U_23_ADDR, (REG_PL_RD(SPU_SCALE_STREAM_U_23_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalestreamu3 <<16));
}
__INLINE uint16_t spu_scale_stream_u_23_scale_stream_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_STREAM_U_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_stream_u_23_scale_stream_u_2_setf(uint16_t scalestreamu2)
{
	ASSERT_ERR((((uint32_t)scalestreamu2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_STREAM_U_23_ADDR, (REG_PL_RD(SPU_SCALE_STREAM_U_23_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalestreamu2 <<0));
}

/**
 * @brief SCALE_STREAM_U_45 register definition
 *  Stream scaling users 4 5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_STREAM_U5           0x0
 *    15:00 SCALE_STREAM_U4           0x0
 * </pre>
 */
#define SPU_SCALE_STREAM_U_45_ADDR        (REG_SPU_BASE_ADDR+0x000000E8)
#define SPU_SCALE_STREAM_U_45_OFFSET      0x000000E8
#define SPU_SCALE_STREAM_U_45_INDEX       0x0000003A
#define SPU_SCALE_STREAM_U_45_RESET       0x00000000

__INLINE uint32_t  spu_scale_stream_u_45_get(void)
{
	return REG_PL_RD(SPU_SCALE_STREAM_U_45_ADDR);
}

__INLINE void spu_scale_stream_u_45_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_STREAM_U_45_ADDR, value);
}

// field definitions
#define SPU_SCALE_STREAM_U_45_SCALE_STREAM_U_5_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_STREAM_U_45_SCALE_STREAM_U_5_LSB    16
#define SPU_SCALE_STREAM_U_45_SCALE_STREAM_U_5_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_STREAM_U_45_SCALE_STREAM_U_4_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_STREAM_U_45_SCALE_STREAM_U_4_LSB    0
#define SPU_SCALE_STREAM_U_45_SCALE_STREAM_U_4_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_STREAM_U_45_SCALE_STREAM_U_5_RST    0x0
#define SPU_SCALE_STREAM_U_45_SCALE_STREAM_U_4_RST    0x0

__INLINE void spu_scale_stream_u_45_pack(uint16_t scale_stream_u5, uint16_t scale_stream_u4)
{
	ASSERT_ERR((((uint32_t)scale_stream_u5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_stream_u4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_STREAM_U_45_ADDR,  ((uint32_t)scale_stream_u5 << 16) |((uint32_t)scale_stream_u4 << 0));
}

__INLINE void spu_scale_stream_u_45_unpack(uint16_t* scale_stream_u5, uint16_t* scale_stream_u4)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_STREAM_U_45_ADDR);

	*scale_stream_u5 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_stream_u4 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_stream_u_45_scale_stream_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_STREAM_U_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_stream_u_45_scale_stream_u_5_setf(uint16_t scalestreamu5)
{
	ASSERT_ERR((((uint32_t)scalestreamu5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_STREAM_U_45_ADDR, (REG_PL_RD(SPU_SCALE_STREAM_U_45_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalestreamu5 <<16));
}
__INLINE uint16_t spu_scale_stream_u_45_scale_stream_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_STREAM_U_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_stream_u_45_scale_stream_u_4_setf(uint16_t scalestreamu4)
{
	ASSERT_ERR((((uint32_t)scalestreamu4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_STREAM_U_45_ADDR, (REG_PL_RD(SPU_SCALE_STREAM_U_45_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalestreamu4 <<0));
}

/**
 * @brief SCALE_STREAM_U_67 register definition
 *  Stream scaling users 6 7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_STREAM_U7           0x0
 *    15:00 SCALE_STREAM_U6           0x0
 * </pre>
 */
#define SPU_SCALE_STREAM_U_67_ADDR        (REG_SPU_BASE_ADDR+0x000000EC)
#define SPU_SCALE_STREAM_U_67_OFFSET      0x000000EC
#define SPU_SCALE_STREAM_U_67_INDEX       0x0000003B
#define SPU_SCALE_STREAM_U_67_RESET       0x00000000

__INLINE uint32_t  spu_scale_stream_u_67_get(void)
{
	return REG_PL_RD(SPU_SCALE_STREAM_U_67_ADDR);
}

__INLINE void spu_scale_stream_u_67_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_STREAM_U_67_ADDR, value);
}

// field definitions
#define SPU_SCALE_STREAM_U_67_SCALE_STREAM_U_7_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_STREAM_U_67_SCALE_STREAM_U_7_LSB    16
#define SPU_SCALE_STREAM_U_67_SCALE_STREAM_U_7_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_STREAM_U_67_SCALE_STREAM_U_6_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_STREAM_U_67_SCALE_STREAM_U_6_LSB    0
#define SPU_SCALE_STREAM_U_67_SCALE_STREAM_U_6_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_STREAM_U_67_SCALE_STREAM_U_7_RST    0x0
#define SPU_SCALE_STREAM_U_67_SCALE_STREAM_U_6_RST    0x0

__INLINE void spu_scale_stream_u_67_pack(uint16_t scale_stream_u7, uint16_t scale_stream_u6)
{
	ASSERT_ERR((((uint32_t)scale_stream_u7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_stream_u6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_STREAM_U_67_ADDR,  ((uint32_t)scale_stream_u7 << 16) |((uint32_t)scale_stream_u6 << 0));
}

__INLINE void spu_scale_stream_u_67_unpack(uint16_t* scale_stream_u7, uint16_t* scale_stream_u6)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_STREAM_U_67_ADDR);

	*scale_stream_u7 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_stream_u6 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_stream_u_67_scale_stream_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_STREAM_U_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_stream_u_67_scale_stream_u_7_setf(uint16_t scalestreamu7)
{
	ASSERT_ERR((((uint32_t)scalestreamu7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_STREAM_U_67_ADDR, (REG_PL_RD(SPU_SCALE_STREAM_U_67_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalestreamu7 <<16));
}
__INLINE uint16_t spu_scale_stream_u_67_scale_stream_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_STREAM_U_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_stream_u_67_scale_stream_u_6_setf(uint16_t scalestreamu6)
{
	ASSERT_ERR((((uint32_t)scalestreamu6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_STREAM_U_67_ADDR, (REG_PL_RD(SPU_SCALE_STREAM_U_67_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalestreamu6 <<0));
}

/**
 * @brief SCALE_ALPHA_R_01 register definition
 *  HeData AlphaR boost factor RUs 0  1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_ALPHA_R1            0x0
 *    15:00 SCALE_ALPHA_R0            0x0
 * </pre>
 */
#define SPU_SCALE_ALPHA_R_01_ADDR        (REG_SPU_BASE_ADDR+0x000000F0)
#define SPU_SCALE_ALPHA_R_01_OFFSET      0x000000F0
#define SPU_SCALE_ALPHA_R_01_INDEX       0x0000003C
#define SPU_SCALE_ALPHA_R_01_RESET       0x00000000

__INLINE uint32_t  spu_scale_alpha_r_01_get(void)
{
	return REG_PL_RD(SPU_SCALE_ALPHA_R_01_ADDR);
}

__INLINE void spu_scale_alpha_r_01_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_ALPHA_R_01_ADDR, value);
}

// field definitions
#define SPU_SCALE_ALPHA_R_01_SCALE_ALPHA_R_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_ALPHA_R_01_SCALE_ALPHA_R_1_LSB    16
#define SPU_SCALE_ALPHA_R_01_SCALE_ALPHA_R_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_ALPHA_R_01_SCALE_ALPHA_R_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_ALPHA_R_01_SCALE_ALPHA_R_0_LSB    0
#define SPU_SCALE_ALPHA_R_01_SCALE_ALPHA_R_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_ALPHA_R_01_SCALE_ALPHA_R_1_RST    0x0
#define SPU_SCALE_ALPHA_R_01_SCALE_ALPHA_R_0_RST    0x0

__INLINE void spu_scale_alpha_r_01_pack(uint16_t scale_alpha_r1, uint16_t scale_alpha_r0)
{
	ASSERT_ERR((((uint32_t)scale_alpha_r1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_alpha_r0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_ALPHA_R_01_ADDR,  ((uint32_t)scale_alpha_r1 << 16) |((uint32_t)scale_alpha_r0 << 0));
}

__INLINE void spu_scale_alpha_r_01_unpack(uint16_t* scale_alpha_r1, uint16_t* scale_alpha_r0)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_ALPHA_R_01_ADDR);

	*scale_alpha_r1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_alpha_r0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_alpha_r_01_scale_alpha_r_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_ALPHA_R_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_alpha_r_01_scale_alpha_r_1_setf(uint16_t scalealphar1)
{
	ASSERT_ERR((((uint32_t)scalealphar1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_ALPHA_R_01_ADDR, (REG_PL_RD(SPU_SCALE_ALPHA_R_01_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalealphar1 <<16));
}
__INLINE uint16_t spu_scale_alpha_r_01_scale_alpha_r_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_ALPHA_R_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_alpha_r_01_scale_alpha_r_0_setf(uint16_t scalealphar0)
{
	ASSERT_ERR((((uint32_t)scalealphar0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_ALPHA_R_01_ADDR, (REG_PL_RD(SPU_SCALE_ALPHA_R_01_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalealphar0 <<0));
}

/**
 * @brief SCALE_ALPHA_R_23 register definition
 *  HeData AlphaR boost factor RUs 2 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_ALPHA_R3            0x0
 *    15:00 SCALE_ALPHA_R2            0x0
 * </pre>
 */
#define SPU_SCALE_ALPHA_R_23_ADDR        (REG_SPU_BASE_ADDR+0x000000F4)
#define SPU_SCALE_ALPHA_R_23_OFFSET      0x000000F4
#define SPU_SCALE_ALPHA_R_23_INDEX       0x0000003D
#define SPU_SCALE_ALPHA_R_23_RESET       0x00000000

__INLINE uint32_t  spu_scale_alpha_r_23_get(void)
{
	return REG_PL_RD(SPU_SCALE_ALPHA_R_23_ADDR);
}

__INLINE void spu_scale_alpha_r_23_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_ALPHA_R_23_ADDR, value);
}

// field definitions
#define SPU_SCALE_ALPHA_R_23_SCALE_ALPHA_R_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_ALPHA_R_23_SCALE_ALPHA_R_3_LSB    16
#define SPU_SCALE_ALPHA_R_23_SCALE_ALPHA_R_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_ALPHA_R_23_SCALE_ALPHA_R_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_ALPHA_R_23_SCALE_ALPHA_R_2_LSB    0
#define SPU_SCALE_ALPHA_R_23_SCALE_ALPHA_R_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_ALPHA_R_23_SCALE_ALPHA_R_3_RST    0x0
#define SPU_SCALE_ALPHA_R_23_SCALE_ALPHA_R_2_RST    0x0

__INLINE void spu_scale_alpha_r_23_pack(uint16_t scale_alpha_r3, uint16_t scale_alpha_r2)
{
	ASSERT_ERR((((uint32_t)scale_alpha_r3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_alpha_r2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_ALPHA_R_23_ADDR,  ((uint32_t)scale_alpha_r3 << 16) |((uint32_t)scale_alpha_r2 << 0));
}

__INLINE void spu_scale_alpha_r_23_unpack(uint16_t* scale_alpha_r3, uint16_t* scale_alpha_r2)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_ALPHA_R_23_ADDR);

	*scale_alpha_r3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_alpha_r2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_alpha_r_23_scale_alpha_r_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_ALPHA_R_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_alpha_r_23_scale_alpha_r_3_setf(uint16_t scalealphar3)
{
	ASSERT_ERR((((uint32_t)scalealphar3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_ALPHA_R_23_ADDR, (REG_PL_RD(SPU_SCALE_ALPHA_R_23_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalealphar3 <<16));
}
__INLINE uint16_t spu_scale_alpha_r_23_scale_alpha_r_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_ALPHA_R_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_alpha_r_23_scale_alpha_r_2_setf(uint16_t scalealphar2)
{
	ASSERT_ERR((((uint32_t)scalealphar2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_ALPHA_R_23_ADDR, (REG_PL_RD(SPU_SCALE_ALPHA_R_23_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalealphar2 <<0));
}

/**
 * @brief SCALE_ALPHA_R_45 register definition
 *  HeData AlphaR boost factor RUs 4 5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_ALPHA_R5            0x0
 *    15:00 SCALE_ALPHA_R4            0x0
 * </pre>
 */
#define SPU_SCALE_ALPHA_R_45_ADDR        (REG_SPU_BASE_ADDR+0x000000F8)
#define SPU_SCALE_ALPHA_R_45_OFFSET      0x000000F8
#define SPU_SCALE_ALPHA_R_45_INDEX       0x0000003E
#define SPU_SCALE_ALPHA_R_45_RESET       0x00000000

__INLINE uint32_t  spu_scale_alpha_r_45_get(void)
{
	return REG_PL_RD(SPU_SCALE_ALPHA_R_45_ADDR);
}

__INLINE void spu_scale_alpha_r_45_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_ALPHA_R_45_ADDR, value);
}

// field definitions
#define SPU_SCALE_ALPHA_R_45_SCALE_ALPHA_R_5_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_ALPHA_R_45_SCALE_ALPHA_R_5_LSB    16
#define SPU_SCALE_ALPHA_R_45_SCALE_ALPHA_R_5_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_ALPHA_R_45_SCALE_ALPHA_R_4_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_ALPHA_R_45_SCALE_ALPHA_R_4_LSB    0
#define SPU_SCALE_ALPHA_R_45_SCALE_ALPHA_R_4_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_ALPHA_R_45_SCALE_ALPHA_R_5_RST    0x0
#define SPU_SCALE_ALPHA_R_45_SCALE_ALPHA_R_4_RST    0x0

__INLINE void spu_scale_alpha_r_45_pack(uint16_t scale_alpha_r5, uint16_t scale_alpha_r4)
{
	ASSERT_ERR((((uint32_t)scale_alpha_r5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_alpha_r4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_ALPHA_R_45_ADDR,  ((uint32_t)scale_alpha_r5 << 16) |((uint32_t)scale_alpha_r4 << 0));
}

__INLINE void spu_scale_alpha_r_45_unpack(uint16_t* scale_alpha_r5, uint16_t* scale_alpha_r4)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_ALPHA_R_45_ADDR);

	*scale_alpha_r5 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_alpha_r4 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_alpha_r_45_scale_alpha_r_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_ALPHA_R_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_alpha_r_45_scale_alpha_r_5_setf(uint16_t scalealphar5)
{
	ASSERT_ERR((((uint32_t)scalealphar5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_ALPHA_R_45_ADDR, (REG_PL_RD(SPU_SCALE_ALPHA_R_45_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalealphar5 <<16));
}
__INLINE uint16_t spu_scale_alpha_r_45_scale_alpha_r_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_ALPHA_R_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_alpha_r_45_scale_alpha_r_4_setf(uint16_t scalealphar4)
{
	ASSERT_ERR((((uint32_t)scalealphar4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_ALPHA_R_45_ADDR, (REG_PL_RD(SPU_SCALE_ALPHA_R_45_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalealphar4 <<0));
}

/**
 * @brief SCALE_ALPHA_R_67 register definition
 *  HeData AlphaR boost factor RUs 6 7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_ALPHA_R7            0x0
 *    15:00 SCALE_ALPHA_R6            0x0
 * </pre>
 */
#define SPU_SCALE_ALPHA_R_67_ADDR        (REG_SPU_BASE_ADDR+0x000000FC)
#define SPU_SCALE_ALPHA_R_67_OFFSET      0x000000FC
#define SPU_SCALE_ALPHA_R_67_INDEX       0x0000003F
#define SPU_SCALE_ALPHA_R_67_RESET       0x00000000

__INLINE uint32_t  spu_scale_alpha_r_67_get(void)
{
	return REG_PL_RD(SPU_SCALE_ALPHA_R_67_ADDR);
}

__INLINE void spu_scale_alpha_r_67_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_ALPHA_R_67_ADDR, value);
}

// field definitions
#define SPU_SCALE_ALPHA_R_67_SCALE_ALPHA_R_7_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_ALPHA_R_67_SCALE_ALPHA_R_7_LSB    16
#define SPU_SCALE_ALPHA_R_67_SCALE_ALPHA_R_7_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_ALPHA_R_67_SCALE_ALPHA_R_6_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_ALPHA_R_67_SCALE_ALPHA_R_6_LSB    0
#define SPU_SCALE_ALPHA_R_67_SCALE_ALPHA_R_6_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_ALPHA_R_67_SCALE_ALPHA_R_7_RST    0x0
#define SPU_SCALE_ALPHA_R_67_SCALE_ALPHA_R_6_RST    0x0

__INLINE void spu_scale_alpha_r_67_pack(uint16_t scale_alpha_r7, uint16_t scale_alpha_r6)
{
	ASSERT_ERR((((uint32_t)scale_alpha_r7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_alpha_r6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_ALPHA_R_67_ADDR,  ((uint32_t)scale_alpha_r7 << 16) |((uint32_t)scale_alpha_r6 << 0));
}

__INLINE void spu_scale_alpha_r_67_unpack(uint16_t* scale_alpha_r7, uint16_t* scale_alpha_r6)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_ALPHA_R_67_ADDR);

	*scale_alpha_r7 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_alpha_r6 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_alpha_r_67_scale_alpha_r_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_ALPHA_R_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_alpha_r_67_scale_alpha_r_7_setf(uint16_t scalealphar7)
{
	ASSERT_ERR((((uint32_t)scalealphar7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_ALPHA_R_67_ADDR, (REG_PL_RD(SPU_SCALE_ALPHA_R_67_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalealphar7 <<16));
}
__INLINE uint16_t spu_scale_alpha_r_67_scale_alpha_r_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_ALPHA_R_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_alpha_r_67_scale_alpha_r_6_setf(uint16_t scalealphar6)
{
	ASSERT_ERR((((uint32_t)scalealphar6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_ALPHA_R_67_ADDR, (REG_PL_RD(SPU_SCALE_ALPHA_R_67_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalealphar6 <<0));
}

/**
 * @brief CSD_CLK_BIAS register definition
 *  Common config register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26    CLK_BIAS_UPDATE_ACK       1              
 *    25    LOAD_CLK_BIAS             0              
 *    24    FORCE_WAIT_NEW_CLK_BIAS   0              
 *    23:00 CSD_CLK_BIAS_VAL          0x0
 * </pre>
 */
#define SPU_CSD_CLK_BIAS_ADDR        (REG_SPU_BASE_ADDR+0x00000100)
#define SPU_CSD_CLK_BIAS_OFFSET      0x00000100
#define SPU_CSD_CLK_BIAS_INDEX       0x00000040
#define SPU_CSD_CLK_BIAS_RESET       0x04000000

__INLINE uint32_t  spu_csd_clk_bias_get(void)
{
	return REG_PL_RD(SPU_CSD_CLK_BIAS_ADDR);
}

__INLINE void spu_csd_clk_bias_set(uint32_t value)
{
	REG_PL_WR(SPU_CSD_CLK_BIAS_ADDR, value);
}

// field definitions
#define SPU_CSD_CLK_BIAS_CLK_BIAS_UPDATE_ACK_BIT    ((uint32_t)0x04000000)
#define SPU_CSD_CLK_BIAS_CLK_BIAS_UPDATE_ACK_POS    26
#define SPU_CSD_CLK_BIAS_LOAD_CLK_BIAS_BIT    ((uint32_t)0x02000000)
#define SPU_CSD_CLK_BIAS_LOAD_CLK_BIAS_POS    25
#define SPU_CSD_CLK_BIAS_FORCE_WAIT_NEW_CLK_BIAS_BIT    ((uint32_t)0x01000000)
#define SPU_CSD_CLK_BIAS_FORCE_WAIT_NEW_CLK_BIAS_POS    24
#define SPU_CSD_CLK_BIAS_CSD_CLK_BIAS_VAL_MASK    ((uint32_t)0x00FFFFFF)
#define SPU_CSD_CLK_BIAS_CSD_CLK_BIAS_VAL_LSB    0
#define SPU_CSD_CLK_BIAS_CSD_CLK_BIAS_VAL_WIDTH    ((uint32_t)0x00000018)

#define SPU_CSD_CLK_BIAS_CLK_BIAS_UPDATE_ACK_RST    0x1
#define SPU_CSD_CLK_BIAS_LOAD_CLK_BIAS_RST    0x0
#define SPU_CSD_CLK_BIAS_FORCE_WAIT_NEW_CLK_BIAS_RST    0x0
#define SPU_CSD_CLK_BIAS_CSD_CLK_BIAS_VAL_RST    0x0

__INLINE void spu_csd_clk_bias_pack(uint8_t clk_bias_update_ack, uint8_t load_clk_bias, uint8_t force_wait_new_clk_bias, uint32_t csd_clk_bias_val)
{
	ASSERT_ERR((((uint32_t)clk_bias_update_ack << 26) & ~((uint32_t)0x04000000)) == 0);
	ASSERT_ERR((((uint32_t)load_clk_bias << 25) & ~((uint32_t)0x02000000)) == 0);
	ASSERT_ERR((((uint32_t)force_wait_new_clk_bias << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)csd_clk_bias_val << 0) & ~((uint32_t)0x00FFFFFF)) == 0);
	REG_PL_WR(SPU_CSD_CLK_BIAS_ADDR,  ((uint32_t)clk_bias_update_ack << 26) |((uint32_t)load_clk_bias << 25) |((uint32_t)force_wait_new_clk_bias << 24) |((uint32_t)csd_clk_bias_val << 0));
}

__INLINE void spu_csd_clk_bias_unpack(uint8_t* clk_bias_update_ack, uint8_t* load_clk_bias, uint8_t* force_wait_new_clk_bias, uint32_t* csd_clk_bias_val)
{
	uint32_t localVal = REG_PL_RD(SPU_CSD_CLK_BIAS_ADDR);

	*clk_bias_update_ack = (localVal & ((uint32_t)0x04000000)) >>  26;
	*load_clk_bias = (localVal & ((uint32_t)0x02000000)) >>  25;
	*force_wait_new_clk_bias = (localVal & ((uint32_t)0x01000000)) >>  24;
	*csd_clk_bias_val = (localVal & ((uint32_t)0x00FFFFFF)) >>  0;
}

__INLINE uint8_t spu_csd_clk_bias_clk_bias_update_ack_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_CSD_CLK_BIAS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE void spu_csd_clk_bias_load_clk_bias_setf(uint8_t loadclkbias)
{
	ASSERT_ERR((((uint32_t)loadclkbias << 25) & ~((uint32_t)0x02000000)) == 0);
	REG_PL_WR(SPU_CSD_CLK_BIAS_ADDR, (REG_PL_RD(SPU_CSD_CLK_BIAS_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)loadclkbias <<25));
}
__INLINE uint8_t spu_csd_clk_bias_force_wait_new_clk_bias_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_CSD_CLK_BIAS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE void spu_csd_clk_bias_force_wait_new_clk_bias_setf(uint8_t forcewaitnewclkbias)
{
	ASSERT_ERR((((uint32_t)forcewaitnewclkbias << 24) & ~((uint32_t)0x01000000)) == 0);
	REG_PL_WR(SPU_CSD_CLK_BIAS_ADDR, (REG_PL_RD(SPU_CSD_CLK_BIAS_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)forcewaitnewclkbias <<24));
}
__INLINE uint32_t spu_csd_clk_bias_csd_clk_bias_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_CSD_CLK_BIAS_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0x00FFFFFF)) >> 0);
}
__INLINE void spu_csd_clk_bias_csd_clk_bias_val_setf(uint32_t csdclkbiasval)
{
	ASSERT_ERR((((uint32_t)csdclkbiasval << 0) & ~((uint32_t)0x00FFFFFF)) == 0);
	REG_PL_WR(SPU_CSD_CLK_BIAS_ADDR, (REG_PL_RD(SPU_CSD_CLK_BIAS_ADDR) & ~((uint32_t)0x00FFFFFF)) | ((uint32_t)csdclkbiasval <<0));
}

/**
 * @brief CSD_CLK_BIAS_OFFSET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:00 CLK_BIAS_OFFSET           0x0
 * </pre>
 */
#define SPU_CSD_CLK_BIAS_OFFSET_ADDR        (REG_SPU_BASE_ADDR+0x00000104)
#define SPU_CSD_CLK_BIAS_OFFSET_OFFSET      0x00000104
#define SPU_CSD_CLK_BIAS_OFFSET_INDEX       0x00000041
#define SPU_CSD_CLK_BIAS_OFFSET_RESET       0x00000000

__INLINE uint32_t  spu_csd_clk_bias_offset_get(void)
{
	return REG_PL_RD(SPU_CSD_CLK_BIAS_OFFSET_ADDR);
}

__INLINE void spu_csd_clk_bias_offset_set(uint32_t value)
{
	REG_PL_WR(SPU_CSD_CLK_BIAS_OFFSET_ADDR, value);
}

// field definitions
#define SPU_CSD_CLK_BIAS_OFFSET_CLK_BIAS_OFFSET_MASK    ((uint32_t)0x00FFFFFF)
#define SPU_CSD_CLK_BIAS_OFFSET_CLK_BIAS_OFFSET_LSB    0
#define SPU_CSD_CLK_BIAS_OFFSET_CLK_BIAS_OFFSET_WIDTH    ((uint32_t)0x00000018)

#define SPU_CSD_CLK_BIAS_OFFSET_CLK_BIAS_OFFSET_RST    0x0

__INLINE uint32_t spu_csd_clk_bias_offset_clk_bias_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_CSD_CLK_BIAS_OFFSET_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void spu_csd_clk_bias_offset_clk_bias_offset_setf(uint32_t clkbiasoffset)
{
	ASSERT_ERR((((uint32_t)clkbiasoffset << 0) & ~((uint32_t)0x00FFFFFF)) == 0);
	REG_PL_WR(SPU_CSD_CLK_BIAS_OFFSET_ADDR, (uint32_t)clkbiasoffset << 0);
}

/**
 * @brief CSD_CLK_BIAS_SEG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:00 CSD_CLK_BIAS_VAL_SEG1     0x0
 * </pre>
 */
#define SPU_CSD_CLK_BIAS_SEG_1_ADDR        (REG_SPU_BASE_ADDR+0x00000108)
#define SPU_CSD_CLK_BIAS_SEG_1_OFFSET      0x00000108
#define SPU_CSD_CLK_BIAS_SEG_1_INDEX       0x00000042
#define SPU_CSD_CLK_BIAS_SEG_1_RESET       0x00000000

__INLINE uint32_t  spu_csd_clk_bias_seg_1_get(void)
{
	return REG_PL_RD(SPU_CSD_CLK_BIAS_SEG_1_ADDR);
}

__INLINE void spu_csd_clk_bias_seg_1_set(uint32_t value)
{
	REG_PL_WR(SPU_CSD_CLK_BIAS_SEG_1_ADDR, value);
}

// field definitions
#define SPU_CSD_CLK_BIAS_SEG_1_CSD_CLK_BIAS_VAL_SEG_1_MASK    ((uint32_t)0x00FFFFFF)
#define SPU_CSD_CLK_BIAS_SEG_1_CSD_CLK_BIAS_VAL_SEG_1_LSB    0
#define SPU_CSD_CLK_BIAS_SEG_1_CSD_CLK_BIAS_VAL_SEG_1_WIDTH    ((uint32_t)0x00000018)

#define SPU_CSD_CLK_BIAS_SEG_1_CSD_CLK_BIAS_VAL_SEG_1_RST    0x0

__INLINE uint32_t spu_csd_clk_bias_seg_1_csd_clk_bias_val_seg_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_CSD_CLK_BIAS_SEG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void spu_csd_clk_bias_seg_1_csd_clk_bias_val_seg_1_setf(uint32_t csdclkbiasvalseg1)
{
	ASSERT_ERR((((uint32_t)csdclkbiasvalseg1 << 0) & ~((uint32_t)0x00FFFFFF)) == 0);
	REG_PL_WR(SPU_CSD_CLK_BIAS_SEG_1_ADDR, (uint32_t)csdclkbiasvalseg1 << 0);
}

/**
 * @brief CSD_CLK_BIAS_OFFSET_SEG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:00 CLK_BIAS_OFFSET_SEG1      0x0
 * </pre>
 */
#define SPU_CSD_CLK_BIAS_OFFSET_SEG_1_ADDR        (REG_SPU_BASE_ADDR+0x0000010C)
#define SPU_CSD_CLK_BIAS_OFFSET_SEG_1_OFFSET      0x0000010C
#define SPU_CSD_CLK_BIAS_OFFSET_SEG_1_INDEX       0x00000043
#define SPU_CSD_CLK_BIAS_OFFSET_SEG_1_RESET       0x00000000

__INLINE uint32_t  spu_csd_clk_bias_offset_seg_1_get(void)
{
	return REG_PL_RD(SPU_CSD_CLK_BIAS_OFFSET_SEG_1_ADDR);
}

__INLINE void spu_csd_clk_bias_offset_seg_1_set(uint32_t value)
{
	REG_PL_WR(SPU_CSD_CLK_BIAS_OFFSET_SEG_1_ADDR, value);
}

// field definitions
#define SPU_CSD_CLK_BIAS_OFFSET_SEG_1_CLK_BIAS_OFFSET_SEG_1_MASK    ((uint32_t)0x00FFFFFF)
#define SPU_CSD_CLK_BIAS_OFFSET_SEG_1_CLK_BIAS_OFFSET_SEG_1_LSB    0
#define SPU_CSD_CLK_BIAS_OFFSET_SEG_1_CLK_BIAS_OFFSET_SEG_1_WIDTH    ((uint32_t)0x00000018)

#define SPU_CSD_CLK_BIAS_OFFSET_SEG_1_CLK_BIAS_OFFSET_SEG_1_RST    0x0

__INLINE uint32_t spu_csd_clk_bias_offset_seg_1_clk_bias_offset_seg_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_CSD_CLK_BIAS_OFFSET_SEG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void spu_csd_clk_bias_offset_seg_1_clk_bias_offset_seg_1_setf(uint32_t clkbiasoffsetseg1)
{
	ASSERT_ERR((((uint32_t)clkbiasoffsetseg1 << 0) & ~((uint32_t)0x00FFFFFF)) == 0);
	REG_PL_WR(SPU_CSD_CLK_BIAS_OFFSET_SEG_1_ADDR, (uint32_t)clkbiasoffsetseg1 << 0);
}

/**
 * @brief SCALE_A_HESTF_R_01 register definition
 *  HeSTF AlphaR boost factor RUs 0  1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_A_HESTF_R1          0x0
 *    15:00 SCALE_A_HESTF_R0          0x0
 * </pre>
 */
#define SPU_SCALE_A_HESTF_R_01_ADDR        (REG_SPU_BASE_ADDR+0x00000110)
#define SPU_SCALE_A_HESTF_R_01_OFFSET      0x00000110
#define SPU_SCALE_A_HESTF_R_01_INDEX       0x00000044
#define SPU_SCALE_A_HESTF_R_01_RESET       0x00000000

__INLINE uint32_t  spu_scale_a_hestf_r_01_get(void)
{
	return REG_PL_RD(SPU_SCALE_A_HESTF_R_01_ADDR);
}

__INLINE void spu_scale_a_hestf_r_01_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_A_HESTF_R_01_ADDR, value);
}

// field definitions
#define SPU_SCALE_A_HESTF_R_01_SCALE_A_HESTF_R_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_A_HESTF_R_01_SCALE_A_HESTF_R_1_LSB    16
#define SPU_SCALE_A_HESTF_R_01_SCALE_A_HESTF_R_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_A_HESTF_R_01_SCALE_A_HESTF_R_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_A_HESTF_R_01_SCALE_A_HESTF_R_0_LSB    0
#define SPU_SCALE_A_HESTF_R_01_SCALE_A_HESTF_R_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_A_HESTF_R_01_SCALE_A_HESTF_R_1_RST    0x0
#define SPU_SCALE_A_HESTF_R_01_SCALE_A_HESTF_R_0_RST    0x0

__INLINE void spu_scale_a_hestf_r_01_pack(uint16_t scale_a_hestf_r1, uint16_t scale_a_hestf_r0)
{
	ASSERT_ERR((((uint32_t)scale_a_hestf_r1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_a_hestf_r0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_A_HESTF_R_01_ADDR,  ((uint32_t)scale_a_hestf_r1 << 16) |((uint32_t)scale_a_hestf_r0 << 0));
}

__INLINE void spu_scale_a_hestf_r_01_unpack(uint16_t* scale_a_hestf_r1, uint16_t* scale_a_hestf_r0)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HESTF_R_01_ADDR);

	*scale_a_hestf_r1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_a_hestf_r0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_a_hestf_r_01_scale_a_hestf_r_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HESTF_R_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_a_hestf_r_01_scale_a_hestf_r_1_setf(uint16_t scaleahestfr1)
{
	ASSERT_ERR((((uint32_t)scaleahestfr1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_A_HESTF_R_01_ADDR, (REG_PL_RD(SPU_SCALE_A_HESTF_R_01_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleahestfr1 <<16));
}
__INLINE uint16_t spu_scale_a_hestf_r_01_scale_a_hestf_r_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HESTF_R_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_a_hestf_r_01_scale_a_hestf_r_0_setf(uint16_t scaleahestfr0)
{
	ASSERT_ERR((((uint32_t)scaleahestfr0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_A_HESTF_R_01_ADDR, (REG_PL_RD(SPU_SCALE_A_HESTF_R_01_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleahestfr0 <<0));
}

/**
 * @brief SCALE_A_HESTF_R_23 register definition
 *  HeSTF AlphaR boost factor RUs 2 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_A_HESTF_R3          0x0
 *    15:00 SCALE_A_HESTF_R2          0x0
 * </pre>
 */
#define SPU_SCALE_A_HESTF_R_23_ADDR        (REG_SPU_BASE_ADDR+0x00000114)
#define SPU_SCALE_A_HESTF_R_23_OFFSET      0x00000114
#define SPU_SCALE_A_HESTF_R_23_INDEX       0x00000045
#define SPU_SCALE_A_HESTF_R_23_RESET       0x00000000

__INLINE uint32_t  spu_scale_a_hestf_r_23_get(void)
{
	return REG_PL_RD(SPU_SCALE_A_HESTF_R_23_ADDR);
}

__INLINE void spu_scale_a_hestf_r_23_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_A_HESTF_R_23_ADDR, value);
}

// field definitions
#define SPU_SCALE_A_HESTF_R_23_SCALE_A_HESTF_R_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_A_HESTF_R_23_SCALE_A_HESTF_R_3_LSB    16
#define SPU_SCALE_A_HESTF_R_23_SCALE_A_HESTF_R_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_A_HESTF_R_23_SCALE_A_HESTF_R_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_A_HESTF_R_23_SCALE_A_HESTF_R_2_LSB    0
#define SPU_SCALE_A_HESTF_R_23_SCALE_A_HESTF_R_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_A_HESTF_R_23_SCALE_A_HESTF_R_3_RST    0x0
#define SPU_SCALE_A_HESTF_R_23_SCALE_A_HESTF_R_2_RST    0x0

__INLINE void spu_scale_a_hestf_r_23_pack(uint16_t scale_a_hestf_r3, uint16_t scale_a_hestf_r2)
{
	ASSERT_ERR((((uint32_t)scale_a_hestf_r3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_a_hestf_r2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_A_HESTF_R_23_ADDR,  ((uint32_t)scale_a_hestf_r3 << 16) |((uint32_t)scale_a_hestf_r2 << 0));
}

__INLINE void spu_scale_a_hestf_r_23_unpack(uint16_t* scale_a_hestf_r3, uint16_t* scale_a_hestf_r2)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HESTF_R_23_ADDR);

	*scale_a_hestf_r3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_a_hestf_r2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_a_hestf_r_23_scale_a_hestf_r_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HESTF_R_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_a_hestf_r_23_scale_a_hestf_r_3_setf(uint16_t scaleahestfr3)
{
	ASSERT_ERR((((uint32_t)scaleahestfr3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_A_HESTF_R_23_ADDR, (REG_PL_RD(SPU_SCALE_A_HESTF_R_23_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleahestfr3 <<16));
}
__INLINE uint16_t spu_scale_a_hestf_r_23_scale_a_hestf_r_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HESTF_R_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_a_hestf_r_23_scale_a_hestf_r_2_setf(uint16_t scaleahestfr2)
{
	ASSERT_ERR((((uint32_t)scaleahestfr2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_A_HESTF_R_23_ADDR, (REG_PL_RD(SPU_SCALE_A_HESTF_R_23_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleahestfr2 <<0));
}

/**
 * @brief SCALE_A_HESTF_R_45 register definition
 *  HeSTF AlphaR boost factor RUs 4 5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_A_HESTF_R5          0x0
 *    15:00 SCALE_A_HESTF_R4          0x0
 * </pre>
 */
#define SPU_SCALE_A_HESTF_R_45_ADDR        (REG_SPU_BASE_ADDR+0x00000118)
#define SPU_SCALE_A_HESTF_R_45_OFFSET      0x00000118
#define SPU_SCALE_A_HESTF_R_45_INDEX       0x00000046
#define SPU_SCALE_A_HESTF_R_45_RESET       0x00000000

__INLINE uint32_t  spu_scale_a_hestf_r_45_get(void)
{
	return REG_PL_RD(SPU_SCALE_A_HESTF_R_45_ADDR);
}

__INLINE void spu_scale_a_hestf_r_45_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_A_HESTF_R_45_ADDR, value);
}

// field definitions
#define SPU_SCALE_A_HESTF_R_45_SCALE_A_HESTF_R_5_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_A_HESTF_R_45_SCALE_A_HESTF_R_5_LSB    16
#define SPU_SCALE_A_HESTF_R_45_SCALE_A_HESTF_R_5_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_A_HESTF_R_45_SCALE_A_HESTF_R_4_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_A_HESTF_R_45_SCALE_A_HESTF_R_4_LSB    0
#define SPU_SCALE_A_HESTF_R_45_SCALE_A_HESTF_R_4_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_A_HESTF_R_45_SCALE_A_HESTF_R_5_RST    0x0
#define SPU_SCALE_A_HESTF_R_45_SCALE_A_HESTF_R_4_RST    0x0

__INLINE void spu_scale_a_hestf_r_45_pack(uint16_t scale_a_hestf_r5, uint16_t scale_a_hestf_r4)
{
	ASSERT_ERR((((uint32_t)scale_a_hestf_r5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_a_hestf_r4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_A_HESTF_R_45_ADDR,  ((uint32_t)scale_a_hestf_r5 << 16) |((uint32_t)scale_a_hestf_r4 << 0));
}

__INLINE void spu_scale_a_hestf_r_45_unpack(uint16_t* scale_a_hestf_r5, uint16_t* scale_a_hestf_r4)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HESTF_R_45_ADDR);

	*scale_a_hestf_r5 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_a_hestf_r4 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_a_hestf_r_45_scale_a_hestf_r_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HESTF_R_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_a_hestf_r_45_scale_a_hestf_r_5_setf(uint16_t scaleahestfr5)
{
	ASSERT_ERR((((uint32_t)scaleahestfr5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_A_HESTF_R_45_ADDR, (REG_PL_RD(SPU_SCALE_A_HESTF_R_45_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleahestfr5 <<16));
}
__INLINE uint16_t spu_scale_a_hestf_r_45_scale_a_hestf_r_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HESTF_R_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_a_hestf_r_45_scale_a_hestf_r_4_setf(uint16_t scaleahestfr4)
{
	ASSERT_ERR((((uint32_t)scaleahestfr4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_A_HESTF_R_45_ADDR, (REG_PL_RD(SPU_SCALE_A_HESTF_R_45_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleahestfr4 <<0));
}

/**
 * @brief SCALE_A_HESTF_R_67 register definition
 *  HeSTF AlphaR boost factor RUs 6 7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_A_HESTF_R7          0x0
 *    15:00 SCALE_A_HESTF_R6          0x0
 * </pre>
 */
#define SPU_SCALE_A_HESTF_R_67_ADDR        (REG_SPU_BASE_ADDR+0x0000011C)
#define SPU_SCALE_A_HESTF_R_67_OFFSET      0x0000011C
#define SPU_SCALE_A_HESTF_R_67_INDEX       0x00000047
#define SPU_SCALE_A_HESTF_R_67_RESET       0x00000000

__INLINE uint32_t  spu_scale_a_hestf_r_67_get(void)
{
	return REG_PL_RD(SPU_SCALE_A_HESTF_R_67_ADDR);
}

__INLINE void spu_scale_a_hestf_r_67_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_A_HESTF_R_67_ADDR, value);
}

// field definitions
#define SPU_SCALE_A_HESTF_R_67_SCALE_A_HESTF_R_7_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_A_HESTF_R_67_SCALE_A_HESTF_R_7_LSB    16
#define SPU_SCALE_A_HESTF_R_67_SCALE_A_HESTF_R_7_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_A_HESTF_R_67_SCALE_A_HESTF_R_6_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_A_HESTF_R_67_SCALE_A_HESTF_R_6_LSB    0
#define SPU_SCALE_A_HESTF_R_67_SCALE_A_HESTF_R_6_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_A_HESTF_R_67_SCALE_A_HESTF_R_7_RST    0x0
#define SPU_SCALE_A_HESTF_R_67_SCALE_A_HESTF_R_6_RST    0x0

__INLINE void spu_scale_a_hestf_r_67_pack(uint16_t scale_a_hestf_r7, uint16_t scale_a_hestf_r6)
{
	ASSERT_ERR((((uint32_t)scale_a_hestf_r7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_a_hestf_r6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_A_HESTF_R_67_ADDR,  ((uint32_t)scale_a_hestf_r7 << 16) |((uint32_t)scale_a_hestf_r6 << 0));
}

__INLINE void spu_scale_a_hestf_r_67_unpack(uint16_t* scale_a_hestf_r7, uint16_t* scale_a_hestf_r6)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HESTF_R_67_ADDR);

	*scale_a_hestf_r7 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_a_hestf_r6 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_a_hestf_r_67_scale_a_hestf_r_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HESTF_R_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_a_hestf_r_67_scale_a_hestf_r_7_setf(uint16_t scaleahestfr7)
{
	ASSERT_ERR((((uint32_t)scaleahestfr7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_A_HESTF_R_67_ADDR, (REG_PL_RD(SPU_SCALE_A_HESTF_R_67_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleahestfr7 <<16));
}
__INLINE uint16_t spu_scale_a_hestf_r_67_scale_a_hestf_r_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HESTF_R_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_a_hestf_r_67_scale_a_hestf_r_6_setf(uint16_t scaleahestfr6)
{
	ASSERT_ERR((((uint32_t)scaleahestfr6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_A_HESTF_R_67_ADDR, (REG_PL_RD(SPU_SCALE_A_HESTF_R_67_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleahestfr6 <<0));
}

/**
 * @brief SCALE_A_HELTF_R_01 register definition
 *  HeLTF AlphaR boost factor RUs 0 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_A_HELTF_R1          0x0
 *    15:00 SCALE_A_HELTF_R0          0x0
 * </pre>
 */
#define SPU_SCALE_A_HELTF_R_01_ADDR        (REG_SPU_BASE_ADDR+0x00000120)
#define SPU_SCALE_A_HELTF_R_01_OFFSET      0x00000120
#define SPU_SCALE_A_HELTF_R_01_INDEX       0x00000048
#define SPU_SCALE_A_HELTF_R_01_RESET       0x00000000

__INLINE uint32_t  spu_scale_a_heltf_r_01_get(void)
{
	return REG_PL_RD(SPU_SCALE_A_HELTF_R_01_ADDR);
}

__INLINE void spu_scale_a_heltf_r_01_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_A_HELTF_R_01_ADDR, value);
}

// field definitions
#define SPU_SCALE_A_HELTF_R_01_SCALE_A_HELTF_R_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_A_HELTF_R_01_SCALE_A_HELTF_R_1_LSB    16
#define SPU_SCALE_A_HELTF_R_01_SCALE_A_HELTF_R_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_A_HELTF_R_01_SCALE_A_HELTF_R_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_A_HELTF_R_01_SCALE_A_HELTF_R_0_LSB    0
#define SPU_SCALE_A_HELTF_R_01_SCALE_A_HELTF_R_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_A_HELTF_R_01_SCALE_A_HELTF_R_1_RST    0x0
#define SPU_SCALE_A_HELTF_R_01_SCALE_A_HELTF_R_0_RST    0x0

__INLINE void spu_scale_a_heltf_r_01_pack(uint16_t scale_a_heltf_r1, uint16_t scale_a_heltf_r0)
{
	ASSERT_ERR((((uint32_t)scale_a_heltf_r1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_a_heltf_r0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_A_HELTF_R_01_ADDR,  ((uint32_t)scale_a_heltf_r1 << 16) |((uint32_t)scale_a_heltf_r0 << 0));
}

__INLINE void spu_scale_a_heltf_r_01_unpack(uint16_t* scale_a_heltf_r1, uint16_t* scale_a_heltf_r0)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HELTF_R_01_ADDR);

	*scale_a_heltf_r1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_a_heltf_r0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_a_heltf_r_01_scale_a_heltf_r_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HELTF_R_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_a_heltf_r_01_scale_a_heltf_r_1_setf(uint16_t scaleaheltfr1)
{
	ASSERT_ERR((((uint32_t)scaleaheltfr1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_A_HELTF_R_01_ADDR, (REG_PL_RD(SPU_SCALE_A_HELTF_R_01_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleaheltfr1 <<16));
}
__INLINE uint16_t spu_scale_a_heltf_r_01_scale_a_heltf_r_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HELTF_R_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_a_heltf_r_01_scale_a_heltf_r_0_setf(uint16_t scaleaheltfr0)
{
	ASSERT_ERR((((uint32_t)scaleaheltfr0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_A_HELTF_R_01_ADDR, (REG_PL_RD(SPU_SCALE_A_HELTF_R_01_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleaheltfr0 <<0));
}

/**
 * @brief SCALE_A_HELTF_R_23 register definition
 *  HeLTF AlphaR boost factor RUs 2 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_A_HELTF_R3          0x0
 *    15:00 SCALE_A_HELTF_R2          0x0
 * </pre>
 */
#define SPU_SCALE_A_HELTF_R_23_ADDR        (REG_SPU_BASE_ADDR+0x00000124)
#define SPU_SCALE_A_HELTF_R_23_OFFSET      0x00000124
#define SPU_SCALE_A_HELTF_R_23_INDEX       0x00000049
#define SPU_SCALE_A_HELTF_R_23_RESET       0x00000000

__INLINE uint32_t  spu_scale_a_heltf_r_23_get(void)
{
	return REG_PL_RD(SPU_SCALE_A_HELTF_R_23_ADDR);
}

__INLINE void spu_scale_a_heltf_r_23_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_A_HELTF_R_23_ADDR, value);
}

// field definitions
#define SPU_SCALE_A_HELTF_R_23_SCALE_A_HELTF_R_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_A_HELTF_R_23_SCALE_A_HELTF_R_3_LSB    16
#define SPU_SCALE_A_HELTF_R_23_SCALE_A_HELTF_R_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_A_HELTF_R_23_SCALE_A_HELTF_R_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_A_HELTF_R_23_SCALE_A_HELTF_R_2_LSB    0
#define SPU_SCALE_A_HELTF_R_23_SCALE_A_HELTF_R_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_A_HELTF_R_23_SCALE_A_HELTF_R_3_RST    0x0
#define SPU_SCALE_A_HELTF_R_23_SCALE_A_HELTF_R_2_RST    0x0

__INLINE void spu_scale_a_heltf_r_23_pack(uint16_t scale_a_heltf_r3, uint16_t scale_a_heltf_r2)
{
	ASSERT_ERR((((uint32_t)scale_a_heltf_r3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_a_heltf_r2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_A_HELTF_R_23_ADDR,  ((uint32_t)scale_a_heltf_r3 << 16) |((uint32_t)scale_a_heltf_r2 << 0));
}

__INLINE void spu_scale_a_heltf_r_23_unpack(uint16_t* scale_a_heltf_r3, uint16_t* scale_a_heltf_r2)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HELTF_R_23_ADDR);

	*scale_a_heltf_r3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_a_heltf_r2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_a_heltf_r_23_scale_a_heltf_r_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HELTF_R_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_a_heltf_r_23_scale_a_heltf_r_3_setf(uint16_t scaleaheltfr3)
{
	ASSERT_ERR((((uint32_t)scaleaheltfr3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_A_HELTF_R_23_ADDR, (REG_PL_RD(SPU_SCALE_A_HELTF_R_23_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleaheltfr3 <<16));
}
__INLINE uint16_t spu_scale_a_heltf_r_23_scale_a_heltf_r_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HELTF_R_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_a_heltf_r_23_scale_a_heltf_r_2_setf(uint16_t scaleaheltfr2)
{
	ASSERT_ERR((((uint32_t)scaleaheltfr2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_A_HELTF_R_23_ADDR, (REG_PL_RD(SPU_SCALE_A_HELTF_R_23_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleaheltfr2 <<0));
}

/**
 * @brief SCALE_A_HELTF_R_45 register definition
 *  HeLTF AlphaR boost factor RUs 4 5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_A_HELTF_R5          0x0
 *    15:00 SCALE_A_HELTF_R4          0x0
 * </pre>
 */
#define SPU_SCALE_A_HELTF_R_45_ADDR        (REG_SPU_BASE_ADDR+0x00000128)
#define SPU_SCALE_A_HELTF_R_45_OFFSET      0x00000128
#define SPU_SCALE_A_HELTF_R_45_INDEX       0x0000004A
#define SPU_SCALE_A_HELTF_R_45_RESET       0x00000000

__INLINE uint32_t  spu_scale_a_heltf_r_45_get(void)
{
	return REG_PL_RD(SPU_SCALE_A_HELTF_R_45_ADDR);
}

__INLINE void spu_scale_a_heltf_r_45_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_A_HELTF_R_45_ADDR, value);
}

// field definitions
#define SPU_SCALE_A_HELTF_R_45_SCALE_A_HELTF_R_5_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_A_HELTF_R_45_SCALE_A_HELTF_R_5_LSB    16
#define SPU_SCALE_A_HELTF_R_45_SCALE_A_HELTF_R_5_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_A_HELTF_R_45_SCALE_A_HELTF_R_4_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_A_HELTF_R_45_SCALE_A_HELTF_R_4_LSB    0
#define SPU_SCALE_A_HELTF_R_45_SCALE_A_HELTF_R_4_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_A_HELTF_R_45_SCALE_A_HELTF_R_5_RST    0x0
#define SPU_SCALE_A_HELTF_R_45_SCALE_A_HELTF_R_4_RST    0x0

__INLINE void spu_scale_a_heltf_r_45_pack(uint16_t scale_a_heltf_r5, uint16_t scale_a_heltf_r4)
{
	ASSERT_ERR((((uint32_t)scale_a_heltf_r5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_a_heltf_r4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_A_HELTF_R_45_ADDR,  ((uint32_t)scale_a_heltf_r5 << 16) |((uint32_t)scale_a_heltf_r4 << 0));
}

__INLINE void spu_scale_a_heltf_r_45_unpack(uint16_t* scale_a_heltf_r5, uint16_t* scale_a_heltf_r4)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HELTF_R_45_ADDR);

	*scale_a_heltf_r5 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_a_heltf_r4 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_a_heltf_r_45_scale_a_heltf_r_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HELTF_R_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_a_heltf_r_45_scale_a_heltf_r_5_setf(uint16_t scaleaheltfr5)
{
	ASSERT_ERR((((uint32_t)scaleaheltfr5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_A_HELTF_R_45_ADDR, (REG_PL_RD(SPU_SCALE_A_HELTF_R_45_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleaheltfr5 <<16));
}
__INLINE uint16_t spu_scale_a_heltf_r_45_scale_a_heltf_r_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HELTF_R_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_a_heltf_r_45_scale_a_heltf_r_4_setf(uint16_t scaleaheltfr4)
{
	ASSERT_ERR((((uint32_t)scaleaheltfr4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_A_HELTF_R_45_ADDR, (REG_PL_RD(SPU_SCALE_A_HELTF_R_45_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleaheltfr4 <<0));
}

/**
 * @brief SCALE_A_HELTF_R_67 register definition
 *  HeLTF AlphaR boost factor RUs 6 7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_A_HELTF_R7          0x0
 *    15:00 SCALE_A_HELTF_R6          0x0
 * </pre>
 */
#define SPU_SCALE_A_HELTF_R_67_ADDR        (REG_SPU_BASE_ADDR+0x0000012C)
#define SPU_SCALE_A_HELTF_R_67_OFFSET      0x0000012C
#define SPU_SCALE_A_HELTF_R_67_INDEX       0x0000004B
#define SPU_SCALE_A_HELTF_R_67_RESET       0x00000000

__INLINE uint32_t  spu_scale_a_heltf_r_67_get(void)
{
	return REG_PL_RD(SPU_SCALE_A_HELTF_R_67_ADDR);
}

__INLINE void spu_scale_a_heltf_r_67_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_A_HELTF_R_67_ADDR, value);
}

// field definitions
#define SPU_SCALE_A_HELTF_R_67_SCALE_A_HELTF_R_7_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_A_HELTF_R_67_SCALE_A_HELTF_R_7_LSB    16
#define SPU_SCALE_A_HELTF_R_67_SCALE_A_HELTF_R_7_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_A_HELTF_R_67_SCALE_A_HELTF_R_6_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_A_HELTF_R_67_SCALE_A_HELTF_R_6_LSB    0
#define SPU_SCALE_A_HELTF_R_67_SCALE_A_HELTF_R_6_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_A_HELTF_R_67_SCALE_A_HELTF_R_7_RST    0x0
#define SPU_SCALE_A_HELTF_R_67_SCALE_A_HELTF_R_6_RST    0x0

__INLINE void spu_scale_a_heltf_r_67_pack(uint16_t scale_a_heltf_r7, uint16_t scale_a_heltf_r6)
{
	ASSERT_ERR((((uint32_t)scale_a_heltf_r7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_a_heltf_r6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_A_HELTF_R_67_ADDR,  ((uint32_t)scale_a_heltf_r7 << 16) |((uint32_t)scale_a_heltf_r6 << 0));
}

__INLINE void spu_scale_a_heltf_r_67_unpack(uint16_t* scale_a_heltf_r7, uint16_t* scale_a_heltf_r6)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HELTF_R_67_ADDR);

	*scale_a_heltf_r7 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_a_heltf_r6 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_a_heltf_r_67_scale_a_heltf_r_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HELTF_R_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_a_heltf_r_67_scale_a_heltf_r_7_setf(uint16_t scaleaheltfr7)
{
	ASSERT_ERR((((uint32_t)scaleaheltfr7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_A_HELTF_R_67_ADDR, (REG_PL_RD(SPU_SCALE_A_HELTF_R_67_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleaheltfr7 <<16));
}
__INLINE uint16_t spu_scale_a_heltf_r_67_scale_a_heltf_r_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_A_HELTF_R_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_a_heltf_r_67_scale_a_heltf_r_6_setf(uint16_t scaleaheltfr6)
{
	ASSERT_ERR((((uint32_t)scaleaheltfr6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_A_HELTF_R_67_ADDR, (REG_PL_RD(SPU_SCALE_A_HELTF_R_67_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleaheltfr6 <<0));
}

/**
 * @brief NULL_POS_VAL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 NULL_POS_VAL_IM           0x0
 *    15:00 NULL_POS_VAL_RE           0x0
 * </pre>
 */
#define SPU_NULL_POS_VAL_ADDR        (REG_SPU_BASE_ADDR+0x00000130)
#define SPU_NULL_POS_VAL_OFFSET      0x00000130
#define SPU_NULL_POS_VAL_INDEX       0x0000004C
#define SPU_NULL_POS_VAL_RESET       0x00000000

__INLINE uint32_t  spu_null_pos_val_get(void)
{
	return REG_PL_RD(SPU_NULL_POS_VAL_ADDR);
}

__INLINE void spu_null_pos_val_set(uint32_t value)
{
	REG_PL_WR(SPU_NULL_POS_VAL_ADDR, value);
}

// field definitions
#define SPU_NULL_POS_VAL_NULL_POS_VAL_IM_MASK    ((uint32_t)0xFFFF0000)
#define SPU_NULL_POS_VAL_NULL_POS_VAL_IM_LSB    16
#define SPU_NULL_POS_VAL_NULL_POS_VAL_IM_WIDTH    ((uint32_t)0x00000010)
#define SPU_NULL_POS_VAL_NULL_POS_VAL_RE_MASK    ((uint32_t)0x0000FFFF)
#define SPU_NULL_POS_VAL_NULL_POS_VAL_RE_LSB    0
#define SPU_NULL_POS_VAL_NULL_POS_VAL_RE_WIDTH    ((uint32_t)0x00000010)

#define SPU_NULL_POS_VAL_NULL_POS_VAL_IM_RST    0x0
#define SPU_NULL_POS_VAL_NULL_POS_VAL_RE_RST    0x0

__INLINE void spu_null_pos_val_pack(uint16_t null_pos_val_im, uint16_t null_pos_val_re)
{
	ASSERT_ERR((((uint32_t)null_pos_val_im << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)null_pos_val_re << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_NULL_POS_VAL_ADDR,  ((uint32_t)null_pos_val_im << 16) |((uint32_t)null_pos_val_re << 0));
}

__INLINE void spu_null_pos_val_unpack(uint16_t* null_pos_val_im, uint16_t* null_pos_val_re)
{
	uint32_t localVal = REG_PL_RD(SPU_NULL_POS_VAL_ADDR);

	*null_pos_val_im = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*null_pos_val_re = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_null_pos_val_null_pos_val_im_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_NULL_POS_VAL_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_null_pos_val_null_pos_val_im_setf(uint16_t nullposvalim)
{
	ASSERT_ERR((((uint32_t)nullposvalim << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_NULL_POS_VAL_ADDR, (REG_PL_RD(SPU_NULL_POS_VAL_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)nullposvalim <<16));
}
__INLINE uint16_t spu_null_pos_val_null_pos_val_re_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_NULL_POS_VAL_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_null_pos_val_null_pos_val_re_setf(uint16_t nullposvalre)
{
	ASSERT_ERR((((uint32_t)nullposvalre << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_NULL_POS_VAL_ADDR, (REG_PL_RD(SPU_NULL_POS_VAL_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)nullposvalre <<0));
}

/**
 * @brief NULL_NEG_VAL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 NULL_NEG_VAL_IM           0x0
 *    15:00 NULL_NEG_VAL_RE           0x0
 * </pre>
 */
#define SPU_NULL_NEG_VAL_ADDR        (REG_SPU_BASE_ADDR+0x00000134)
#define SPU_NULL_NEG_VAL_OFFSET      0x00000134
#define SPU_NULL_NEG_VAL_INDEX       0x0000004D
#define SPU_NULL_NEG_VAL_RESET       0x00000000

__INLINE uint32_t  spu_null_neg_val_get(void)
{
	return REG_PL_RD(SPU_NULL_NEG_VAL_ADDR);
}

__INLINE void spu_null_neg_val_set(uint32_t value)
{
	REG_PL_WR(SPU_NULL_NEG_VAL_ADDR, value);
}

// field definitions
#define SPU_NULL_NEG_VAL_NULL_NEG_VAL_IM_MASK    ((uint32_t)0xFFFF0000)
#define SPU_NULL_NEG_VAL_NULL_NEG_VAL_IM_LSB    16
#define SPU_NULL_NEG_VAL_NULL_NEG_VAL_IM_WIDTH    ((uint32_t)0x00000010)
#define SPU_NULL_NEG_VAL_NULL_NEG_VAL_RE_MASK    ((uint32_t)0x0000FFFF)
#define SPU_NULL_NEG_VAL_NULL_NEG_VAL_RE_LSB    0
#define SPU_NULL_NEG_VAL_NULL_NEG_VAL_RE_WIDTH    ((uint32_t)0x00000010)

#define SPU_NULL_NEG_VAL_NULL_NEG_VAL_IM_RST    0x0
#define SPU_NULL_NEG_VAL_NULL_NEG_VAL_RE_RST    0x0

__INLINE void spu_null_neg_val_pack(uint16_t null_neg_val_im, uint16_t null_neg_val_re)
{
	ASSERT_ERR((((uint32_t)null_neg_val_im << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)null_neg_val_re << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_NULL_NEG_VAL_ADDR,  ((uint32_t)null_neg_val_im << 16) |((uint32_t)null_neg_val_re << 0));
}

__INLINE void spu_null_neg_val_unpack(uint16_t* null_neg_val_im, uint16_t* null_neg_val_re)
{
	uint32_t localVal = REG_PL_RD(SPU_NULL_NEG_VAL_ADDR);

	*null_neg_val_im = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*null_neg_val_re = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_null_neg_val_null_neg_val_im_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_NULL_NEG_VAL_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_null_neg_val_null_neg_val_im_setf(uint16_t nullnegvalim)
{
	ASSERT_ERR((((uint32_t)nullnegvalim << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_NULL_NEG_VAL_ADDR, (REG_PL_RD(SPU_NULL_NEG_VAL_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)nullnegvalim <<16));
}
__INLINE uint16_t spu_null_neg_val_null_neg_val_re_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_NULL_NEG_VAL_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_null_neg_val_null_neg_val_re_setf(uint16_t nullnegvalre)
{
	ASSERT_ERR((((uint32_t)nullnegvalre << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_NULL_NEG_VAL_ADDR, (REG_PL_RD(SPU_NULL_NEG_VAL_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)nullnegvalre <<0));
}

/**
 * @brief NULLS_LIST_0_15 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NULLS_LIST_0_15           0x0
 * </pre>
 */
#define SPU_NULLS_LIST_0_15_ADDR        (REG_SPU_BASE_ADDR+0x00000138)
#define SPU_NULLS_LIST_0_15_OFFSET      0x00000138
#define SPU_NULLS_LIST_0_15_INDEX       0x0000004E
#define SPU_NULLS_LIST_0_15_RESET       0x00000000

__INLINE uint32_t  spu_nulls_list_0_15_get(void)
{
	return REG_PL_RD(SPU_NULLS_LIST_0_15_ADDR);
}

__INLINE void spu_nulls_list_0_15_set(uint32_t value)
{
	REG_PL_WR(SPU_NULLS_LIST_0_15_ADDR, value);
}

// field definitions
#define SPU_NULLS_LIST_0_15_NULLS_LIST_0_15_MASK    ((uint32_t)0xFFFFFFFF)
#define SPU_NULLS_LIST_0_15_NULLS_LIST_0_15_LSB    0
#define SPU_NULLS_LIST_0_15_NULLS_LIST_0_15_WIDTH    ((uint32_t)0x00000020)

#define SPU_NULLS_LIST_0_15_NULLS_LIST_0_15_RST    0x0

__INLINE uint32_t spu_nulls_list_0_15_nulls_list_0_15_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_NULLS_LIST_0_15_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void spu_nulls_list_0_15_nulls_list_0_15_setf(uint32_t nullslist015)
{
	ASSERT_ERR((((uint32_t)nullslist015 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SPU_NULLS_LIST_0_15_ADDR, (uint32_t)nullslist015 << 0);
}

/**
 * @brief NULLS_LIST_16_31 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NULLS_LIST_16_31          0x0
 * </pre>
 */
#define SPU_NULLS_LIST_16_31_ADDR        (REG_SPU_BASE_ADDR+0x0000013C)
#define SPU_NULLS_LIST_16_31_OFFSET      0x0000013C
#define SPU_NULLS_LIST_16_31_INDEX       0x0000004F
#define SPU_NULLS_LIST_16_31_RESET       0x00000000

__INLINE uint32_t  spu_nulls_list_16_31_get(void)
{
	return REG_PL_RD(SPU_NULLS_LIST_16_31_ADDR);
}

__INLINE void spu_nulls_list_16_31_set(uint32_t value)
{
	REG_PL_WR(SPU_NULLS_LIST_16_31_ADDR, value);
}

// field definitions
#define SPU_NULLS_LIST_16_31_NULLS_LIST_16_31_MASK    ((uint32_t)0xFFFFFFFF)
#define SPU_NULLS_LIST_16_31_NULLS_LIST_16_31_LSB    0
#define SPU_NULLS_LIST_16_31_NULLS_LIST_16_31_WIDTH    ((uint32_t)0x00000020)

#define SPU_NULLS_LIST_16_31_NULLS_LIST_16_31_RST    0x0

__INLINE uint32_t spu_nulls_list_16_31_nulls_list_16_31_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_NULLS_LIST_16_31_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void spu_nulls_list_16_31_nulls_list_16_31_setf(uint32_t nullslist1631)
{
	ASSERT_ERR((((uint32_t)nullslist1631 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SPU_NULLS_LIST_16_31_ADDR, (uint32_t)nullslist1631 << 0);
}

/**
 * @brief NULLS_LIST_32_47 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NULLS_LIST_32_47          0x0
 * </pre>
 */
#define SPU_NULLS_LIST_32_47_ADDR        (REG_SPU_BASE_ADDR+0x00000140)
#define SPU_NULLS_LIST_32_47_OFFSET      0x00000140
#define SPU_NULLS_LIST_32_47_INDEX       0x00000050
#define SPU_NULLS_LIST_32_47_RESET       0x00000000

__INLINE uint32_t  spu_nulls_list_32_47_get(void)
{
	return REG_PL_RD(SPU_NULLS_LIST_32_47_ADDR);
}

__INLINE void spu_nulls_list_32_47_set(uint32_t value)
{
	REG_PL_WR(SPU_NULLS_LIST_32_47_ADDR, value);
}

// field definitions
#define SPU_NULLS_LIST_32_47_NULLS_LIST_32_47_MASK    ((uint32_t)0xFFFFFFFF)
#define SPU_NULLS_LIST_32_47_NULLS_LIST_32_47_LSB    0
#define SPU_NULLS_LIST_32_47_NULLS_LIST_32_47_WIDTH    ((uint32_t)0x00000020)

#define SPU_NULLS_LIST_32_47_NULLS_LIST_32_47_RST    0x0

__INLINE uint32_t spu_nulls_list_32_47_nulls_list_32_47_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_NULLS_LIST_32_47_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void spu_nulls_list_32_47_nulls_list_32_47_setf(uint32_t nullslist3247)
{
	ASSERT_ERR((((uint32_t)nullslist3247 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SPU_NULLS_LIST_32_47_ADDR, (uint32_t)nullslist3247 << 0);
}

/**
 * @brief NULLS_LIST_48_63 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 NULLS_LIST_48_63          0x0
 * </pre>
 */
#define SPU_NULLS_LIST_48_63_ADDR        (REG_SPU_BASE_ADDR+0x00000144)
#define SPU_NULLS_LIST_48_63_OFFSET      0x00000144
#define SPU_NULLS_LIST_48_63_INDEX       0x00000051
#define SPU_NULLS_LIST_48_63_RESET       0x00000000

__INLINE uint32_t  spu_nulls_list_48_63_get(void)
{
	return REG_PL_RD(SPU_NULLS_LIST_48_63_ADDR);
}

__INLINE void spu_nulls_list_48_63_set(uint32_t value)
{
	REG_PL_WR(SPU_NULLS_LIST_48_63_ADDR, value);
}

// field definitions
#define SPU_NULLS_LIST_48_63_NULLS_LIST_48_63_MASK    ((uint32_t)0xFFFFFFFF)
#define SPU_NULLS_LIST_48_63_NULLS_LIST_48_63_LSB    0
#define SPU_NULLS_LIST_48_63_NULLS_LIST_48_63_WIDTH    ((uint32_t)0x00000020)

#define SPU_NULLS_LIST_48_63_NULLS_LIST_48_63_RST    0x0

__INLINE uint32_t spu_nulls_list_48_63_nulls_list_48_63_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_NULLS_LIST_48_63_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void spu_nulls_list_48_63_nulls_list_48_63_setf(uint32_t nullslist4863)
{
	ASSERT_ERR((((uint32_t)nullslist4863 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(SPU_NULLS_LIST_48_63_ADDR, (uint32_t)nullslist4863 << 0);
}

/**
 * @brief STAT_0 register definition
 *  Status register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 SPU_ID                    0xC3
 *    22:20 RX_CLK_CTRL_STAT          0x0
 *    18:16 TX_CLK_CTRL_STAT          0x0
 *    14    SAT_AR_BOOSTER            0              
 *    13    SAT_STREAM_SCALER         0              
 *    12    SAT_CM                    0              
 *    11    RU_INDEX_VALID            0              
 *    10    RU_INDEX_CNT              0              
 *    09:00 SYM_NUM                   0x0
 * </pre>
 */
#define SPU_STAT_0_ADDR        (REG_SPU_BASE_ADDR+0x00000160)
#define SPU_STAT_0_OFFSET      0x00000160
#define SPU_STAT_0_INDEX       0x00000058
#define SPU_STAT_0_RESET       0xC3000000

__INLINE uint32_t  spu_stat_0_get(void)
{
	return REG_PL_RD(SPU_STAT_0_ADDR);
}

// field definitions
#define SPU_STAT_0_SPU_ID_MASK              ((uint32_t)0xFF000000)
#define SPU_STAT_0_SPU_ID_LSB               24
#define SPU_STAT_0_SPU_ID_WIDTH             ((uint32_t)0x00000008)
#define SPU_STAT_0_RX_CLK_CTRL_STAT_MASK    ((uint32_t)0x00700000)
#define SPU_STAT_0_RX_CLK_CTRL_STAT_LSB     20
#define SPU_STAT_0_RX_CLK_CTRL_STAT_WIDTH    ((uint32_t)0x00000003)
#define SPU_STAT_0_TX_CLK_CTRL_STAT_MASK    ((uint32_t)0x00070000)
#define SPU_STAT_0_TX_CLK_CTRL_STAT_LSB     16
#define SPU_STAT_0_TX_CLK_CTRL_STAT_WIDTH    ((uint32_t)0x00000003)
#define SPU_STAT_0_SAT_AR_BOOSTER_BIT       ((uint32_t)0x00004000)
#define SPU_STAT_0_SAT_AR_BOOSTER_POS       14
#define SPU_STAT_0_SAT_STREAM_SCALER_BIT    ((uint32_t)0x00002000)
#define SPU_STAT_0_SAT_STREAM_SCALER_POS    13
#define SPU_STAT_0_SAT_CM_BIT               ((uint32_t)0x00001000)
#define SPU_STAT_0_SAT_CM_POS               12
#define SPU_STAT_0_RU_INDEX_VALID_BIT       ((uint32_t)0x00000800)
#define SPU_STAT_0_RU_INDEX_VALID_POS       11
#define SPU_STAT_0_RU_INDEX_CNT_BIT         ((uint32_t)0x00000400)
#define SPU_STAT_0_RU_INDEX_CNT_POS         10
#define SPU_STAT_0_SYM_NUM_MASK             ((uint32_t)0x000003FF)
#define SPU_STAT_0_SYM_NUM_LSB              0
#define SPU_STAT_0_SYM_NUM_WIDTH            ((uint32_t)0x0000000A)

#define SPU_STAT_0_SPU_ID_RST               0xC3
#define SPU_STAT_0_RX_CLK_CTRL_STAT_RST     0x0
#define SPU_STAT_0_TX_CLK_CTRL_STAT_RST     0x0
#define SPU_STAT_0_SAT_AR_BOOSTER_RST       0x0
#define SPU_STAT_0_SAT_STREAM_SCALER_RST    0x0
#define SPU_STAT_0_SAT_CM_RST               0x0
#define SPU_STAT_0_RU_INDEX_VALID_RST       0x0
#define SPU_STAT_0_RU_INDEX_CNT_RST         0x0
#define SPU_STAT_0_SYM_NUM_RST              0x0

__INLINE void spu_stat_0_unpack(uint8_t* spu_id, uint8_t* rx_clk_ctrl_stat, uint8_t* tx_clk_ctrl_stat, uint8_t* sat_ar_booster, uint8_t* sat_stream_scaler, uint8_t* sat_cm, uint8_t* ru_index_valid, uint8_t* ru_index_cnt, uint16_t* sym_num)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_0_ADDR);

	*spu_id = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*rx_clk_ctrl_stat = (localVal & ((uint32_t)0x00700000)) >>  20;
	*tx_clk_ctrl_stat = (localVal & ((uint32_t)0x00070000)) >>  16;
	*sat_ar_booster = (localVal & ((uint32_t)0x00004000)) >>  14;
	*sat_stream_scaler = (localVal & ((uint32_t)0x00002000)) >>  13;
	*sat_cm = (localVal & ((uint32_t)0x00001000)) >>  12;
	*ru_index_valid = (localVal & ((uint32_t)0x00000800)) >>  11;
	*ru_index_cnt = (localVal & ((uint32_t)0x00000400)) >>  10;
	*sym_num = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint8_t spu_stat_0_spu_id_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE uint8_t spu_stat_0_rx_clk_ctrl_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE uint8_t spu_stat_0_tx_clk_ctrl_stat_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE uint8_t spu_stat_0_sat_ar_booster_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE uint8_t spu_stat_0_sat_stream_scaler_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t spu_stat_0_sat_cm_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t spu_stat_0_ru_index_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE uint8_t spu_stat_0_ru_index_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE uint16_t spu_stat_0_sym_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}

/**
 * @brief STAT_1 register definition
 *  Status register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 CM_SYM_CNT                0x0
 *    27:24 CM_USER_CNT               0x0
 *    23:16 CM_SS_CNT                 0x0
 *    15:00 CM_EGRESS_CNT             0x0
 * </pre>
 */
#define SPU_STAT_1_ADDR        (REG_SPU_BASE_ADDR+0x00000164)
#define SPU_STAT_1_OFFSET      0x00000164
#define SPU_STAT_1_INDEX       0x00000059
#define SPU_STAT_1_RESET       0x00000000

__INLINE uint32_t  spu_stat_1_get(void)
{
	return REG_PL_RD(SPU_STAT_1_ADDR);
}

// field definitions
#define SPU_STAT_1_CM_SYM_CNT_MASK          ((uint32_t)0xF0000000)
#define SPU_STAT_1_CM_SYM_CNT_LSB           28
#define SPU_STAT_1_CM_SYM_CNT_WIDTH         ((uint32_t)0x00000004)
#define SPU_STAT_1_CM_USER_CNT_MASK         ((uint32_t)0x0F000000)
#define SPU_STAT_1_CM_USER_CNT_LSB          24
#define SPU_STAT_1_CM_USER_CNT_WIDTH        ((uint32_t)0x00000004)
#define SPU_STAT_1_CM_SS_CNT_MASK           ((uint32_t)0x00FF0000)
#define SPU_STAT_1_CM_SS_CNT_LSB            16
#define SPU_STAT_1_CM_SS_CNT_WIDTH          ((uint32_t)0x00000008)
#define SPU_STAT_1_CM_EGRESS_CNT_MASK       ((uint32_t)0x0000FFFF)
#define SPU_STAT_1_CM_EGRESS_CNT_LSB        0
#define SPU_STAT_1_CM_EGRESS_CNT_WIDTH      ((uint32_t)0x00000010)

#define SPU_STAT_1_CM_SYM_CNT_RST           0x0
#define SPU_STAT_1_CM_USER_CNT_RST          0x0
#define SPU_STAT_1_CM_SS_CNT_RST            0x0
#define SPU_STAT_1_CM_EGRESS_CNT_RST        0x0

__INLINE void spu_stat_1_unpack(uint8_t* cm_sym_cnt, uint8_t* cm_user_cnt, uint8_t* cm_ss_cnt, uint16_t* cm_egress_cnt)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_1_ADDR);

	*cm_sym_cnt = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*cm_user_cnt = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*cm_ss_cnt = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*cm_egress_cnt = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint8_t spu_stat_1_cm_sym_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE uint8_t spu_stat_1_cm_user_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE uint8_t spu_stat_1_cm_ss_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE uint16_t spu_stat_1_cm_egress_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief STAT_2 register definition
 *  Status register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:08 PG_PILOT_CNT              0x0
 *    07:00 PG_DATA_SYM_CNT           0x0
 * </pre>
 */
#define SPU_STAT_2_ADDR        (REG_SPU_BASE_ADDR+0x00000168)
#define SPU_STAT_2_OFFSET      0x00000168
#define SPU_STAT_2_INDEX       0x0000005A
#define SPU_STAT_2_RESET       0x00000000

__INLINE uint32_t  spu_stat_2_get(void)
{
	return REG_PL_RD(SPU_STAT_2_ADDR);
}

// field definitions
#define SPU_STAT_2_PG_PILOT_CNT_MASK        ((uint32_t)0x0000FF00)
#define SPU_STAT_2_PG_PILOT_CNT_LSB         8
#define SPU_STAT_2_PG_PILOT_CNT_WIDTH       ((uint32_t)0x00000008)
#define SPU_STAT_2_PG_DATA_SYM_CNT_MASK     ((uint32_t)0x000000FF)
#define SPU_STAT_2_PG_DATA_SYM_CNT_LSB      0
#define SPU_STAT_2_PG_DATA_SYM_CNT_WIDTH    ((uint32_t)0x00000008)

#define SPU_STAT_2_PG_PILOT_CNT_RST         0x0
#define SPU_STAT_2_PG_DATA_SYM_CNT_RST      0x0

__INLINE void spu_stat_2_unpack(uint8_t* pg_pilot_cnt, uint8_t* pg_data_sym_cnt)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_2_ADDR);

	*pg_pilot_cnt = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*pg_data_sym_cnt = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t spu_stat_2_pg_pilot_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE uint8_t spu_stat_2_pg_data_sym_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}

/**
 * @brief STAT_3 register definition
 *  Status register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CW_BUF_EMPTY_LO           0xffffffff
 * </pre>
 */
#define SPU_STAT_3_ADDR        (REG_SPU_BASE_ADDR+0x0000016C)
#define SPU_STAT_3_OFFSET      0x0000016C
#define SPU_STAT_3_INDEX       0x0000005B
#define SPU_STAT_3_RESET       0xFFFFFFFF

__INLINE uint32_t  spu_stat_3_get(void)
{
	return REG_PL_RD(SPU_STAT_3_ADDR);
}

// field definitions
#define SPU_STAT_3_CW_BUF_EMPTY_LO_MASK     ((uint32_t)0xFFFFFFFF)
#define SPU_STAT_3_CW_BUF_EMPTY_LO_LSB      0
#define SPU_STAT_3_CW_BUF_EMPTY_LO_WIDTH    ((uint32_t)0x00000020)

#define SPU_STAT_3_CW_BUF_EMPTY_LO_RST      0xffffffff

__INLINE uint32_t spu_stat_3_cw_buf_empty_lo_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_3_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief STAT_4 register definition
 *  Status register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CW_BUF_EMPTY_HI           0xffffffff
 * </pre>
 */
#define SPU_STAT_4_ADDR        (REG_SPU_BASE_ADDR+0x00000170)
#define SPU_STAT_4_OFFSET      0x00000170
#define SPU_STAT_4_INDEX       0x0000005C
#define SPU_STAT_4_RESET       0xFFFFFFFF

__INLINE uint32_t  spu_stat_4_get(void)
{
	return REG_PL_RD(SPU_STAT_4_ADDR);
}

// field definitions
#define SPU_STAT_4_CW_BUF_EMPTY_HI_MASK     ((uint32_t)0xFFFFFFFF)
#define SPU_STAT_4_CW_BUF_EMPTY_HI_LSB      0
#define SPU_STAT_4_CW_BUF_EMPTY_HI_WIDTH    ((uint32_t)0x00000020)

#define SPU_STAT_4_CW_BUF_EMPTY_HI_RST      0xffffffff

__INLINE uint32_t spu_stat_4_cw_buf_empty_hi_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_4_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief STAT_5 register definition
 *  Status register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CW_BUF_READY_LO           0x0
 * </pre>
 */
#define SPU_STAT_5_ADDR        (REG_SPU_BASE_ADDR+0x00000174)
#define SPU_STAT_5_OFFSET      0x00000174
#define SPU_STAT_5_INDEX       0x0000005D
#define SPU_STAT_5_RESET       0x00000000

__INLINE uint32_t  spu_stat_5_get(void)
{
	return REG_PL_RD(SPU_STAT_5_ADDR);
}

// field definitions
#define SPU_STAT_5_CW_BUF_READY_LO_MASK     ((uint32_t)0xFFFFFFFF)
#define SPU_STAT_5_CW_BUF_READY_LO_LSB      0
#define SPU_STAT_5_CW_BUF_READY_LO_WIDTH    ((uint32_t)0x00000020)

#define SPU_STAT_5_CW_BUF_READY_LO_RST      0x0

__INLINE uint32_t spu_stat_5_cw_buf_ready_lo_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_5_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief STAT_6 register definition
 *  Status register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CW_BUF_READY_HI           0x0
 * </pre>
 */
#define SPU_STAT_6_ADDR        (REG_SPU_BASE_ADDR+0x00000178)
#define SPU_STAT_6_OFFSET      0x00000178
#define SPU_STAT_6_INDEX       0x0000005E
#define SPU_STAT_6_RESET       0x00000000

__INLINE uint32_t  spu_stat_6_get(void)
{
	return REG_PL_RD(SPU_STAT_6_ADDR);
}

// field definitions
#define SPU_STAT_6_CW_BUF_READY_HI_MASK     ((uint32_t)0xFFFFFFFF)
#define SPU_STAT_6_CW_BUF_READY_HI_LSB      0
#define SPU_STAT_6_CW_BUF_READY_HI_WIDTH    ((uint32_t)0x00000020)

#define SPU_STAT_6_CW_BUF_READY_HI_RST      0x0

__INLINE uint32_t spu_stat_6_cw_buf_ready_hi_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_6_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief STAT_7 register definition
 *  Status register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:27 TX_CTL_READER_OUTS_LOADS  0x0
 *    26:16 TX_CTL_READER_RU_FIRST_SC_IDX 0x0
 *    15:08 TX_CTL_READER_RU_PEND     0x0
 *    07    TX_CTL_READER_SEG_IDX     0              
 *    06    TX_CTL_READER_SYM_IDX     0              
 *    05:03 TX_CTL_READER_RU_IDX      0x0
 *    02:00 TX_CTL_READER_STATE       0x0
 * </pre>
 */
#define SPU_STAT_7_ADDR        (REG_SPU_BASE_ADDR+0x0000017C)
#define SPU_STAT_7_OFFSET      0x0000017C
#define SPU_STAT_7_INDEX       0x0000005F
#define SPU_STAT_7_RESET       0x00000000

__INLINE uint32_t  spu_stat_7_get(void)
{
	return REG_PL_RD(SPU_STAT_7_ADDR);
}

// field definitions
#define SPU_STAT_7_TX_CTL_READER_OUTS_LOADS_MASK    ((uint32_t)0xF8000000)
#define SPU_STAT_7_TX_CTL_READER_OUTS_LOADS_LSB    27
#define SPU_STAT_7_TX_CTL_READER_OUTS_LOADS_WIDTH    ((uint32_t)0x00000005)
#define SPU_STAT_7_TX_CTL_READER_RU_FIRST_SC_IDX_MASK    ((uint32_t)0x07FF0000)
#define SPU_STAT_7_TX_CTL_READER_RU_FIRST_SC_IDX_LSB    16
#define SPU_STAT_7_TX_CTL_READER_RU_FIRST_SC_IDX_WIDTH    ((uint32_t)0x0000000B)
#define SPU_STAT_7_TX_CTL_READER_RU_PEND_MASK    ((uint32_t)0x0000FF00)
#define SPU_STAT_7_TX_CTL_READER_RU_PEND_LSB    8
#define SPU_STAT_7_TX_CTL_READER_RU_PEND_WIDTH    ((uint32_t)0x00000008)
#define SPU_STAT_7_TX_CTL_READER_SEG_IDX_BIT    ((uint32_t)0x00000080)
#define SPU_STAT_7_TX_CTL_READER_SEG_IDX_POS    7
#define SPU_STAT_7_TX_CTL_READER_SYM_IDX_BIT    ((uint32_t)0x00000040)
#define SPU_STAT_7_TX_CTL_READER_SYM_IDX_POS    6
#define SPU_STAT_7_TX_CTL_READER_RU_IDX_MASK    ((uint32_t)0x00000038)
#define SPU_STAT_7_TX_CTL_READER_RU_IDX_LSB    3
#define SPU_STAT_7_TX_CTL_READER_RU_IDX_WIDTH    ((uint32_t)0x00000003)
#define SPU_STAT_7_TX_CTL_READER_STATE_MASK    ((uint32_t)0x00000007)
#define SPU_STAT_7_TX_CTL_READER_STATE_LSB    0
#define SPU_STAT_7_TX_CTL_READER_STATE_WIDTH    ((uint32_t)0x00000003)

#define SPU_STAT_7_TX_CTL_READER_OUTS_LOADS_RST    0x0
#define SPU_STAT_7_TX_CTL_READER_RU_FIRST_SC_IDX_RST    0x0
#define SPU_STAT_7_TX_CTL_READER_RU_PEND_RST    0x0
#define SPU_STAT_7_TX_CTL_READER_SEG_IDX_RST    0x0
#define SPU_STAT_7_TX_CTL_READER_SYM_IDX_RST    0x0
#define SPU_STAT_7_TX_CTL_READER_RU_IDX_RST    0x0
#define SPU_STAT_7_TX_CTL_READER_STATE_RST    0x0

__INLINE void spu_stat_7_unpack(uint8_t* tx_ctl_reader_outs_loads, uint16_t* tx_ctl_reader_ru_first_sc_idx, uint8_t* tx_ctl_reader_ru_pend, uint8_t* tx_ctl_reader_seg_idx, uint8_t* tx_ctl_reader_sym_idx, uint8_t* tx_ctl_reader_ru_idx, uint8_t* tx_ctl_reader_state)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_7_ADDR);

	*tx_ctl_reader_outs_loads = (localVal & ((uint32_t)0xF8000000)) >>  27;
	*tx_ctl_reader_ru_first_sc_idx = (localVal & ((uint32_t)0x07FF0000)) >>  16;
	*tx_ctl_reader_ru_pend = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*tx_ctl_reader_seg_idx = (localVal & ((uint32_t)0x00000080)) >>  7;
	*tx_ctl_reader_sym_idx = (localVal & ((uint32_t)0x00000040)) >>  6;
	*tx_ctl_reader_ru_idx = (localVal & ((uint32_t)0x00000038)) >>  3;
	*tx_ctl_reader_state = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t spu_stat_7_tx_ctl_reader_outs_loads_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF8000000)) >> 27);
}
__INLINE uint16_t spu_stat_7_tx_ctl_reader_ru_first_sc_idx_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_7_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x07FF0000)) >> 16);
}
__INLINE uint8_t spu_stat_7_tx_ctl_reader_ru_pend_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE uint8_t spu_stat_7_tx_ctl_reader_seg_idx_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE uint8_t spu_stat_7_tx_ctl_reader_sym_idx_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE uint8_t spu_stat_7_tx_ctl_reader_ru_idx_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE uint8_t spu_stat_7_tx_ctl_reader_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_7_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}

/**
 * @brief STAT_8 register definition
 *  Status register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07    TX_CTL_FSM_DEC            0              
 *    06:04 TX_CTL_FSM_REP            0x0
 *    03:02 TX_CTL_FSM_SYM_TYPE       0x3
 *    01:00 TX_CTL_FSM_STATE          0x0
 * </pre>
 */
#define SPU_STAT_8_ADDR        (REG_SPU_BASE_ADDR+0x00000180)
#define SPU_STAT_8_OFFSET      0x00000180
#define SPU_STAT_8_INDEX       0x00000060
#define SPU_STAT_8_RESET       0x0000000C

__INLINE uint32_t  spu_stat_8_get(void)
{
	return REG_PL_RD(SPU_STAT_8_ADDR);
}

// field definitions
#define SPU_STAT_8_TX_CTL_FSM_DEC_BIT       ((uint32_t)0x00000080)
#define SPU_STAT_8_TX_CTL_FSM_DEC_POS       7
#define SPU_STAT_8_TX_CTL_FSM_REP_MASK      ((uint32_t)0x00000070)
#define SPU_STAT_8_TX_CTL_FSM_REP_LSB       4
#define SPU_STAT_8_TX_CTL_FSM_REP_WIDTH     ((uint32_t)0x00000003)
#define SPU_STAT_8_TX_CTL_FSM_SYM_TYPE_MASK    ((uint32_t)0x0000000C)
#define SPU_STAT_8_TX_CTL_FSM_SYM_TYPE_LSB    2
#define SPU_STAT_8_TX_CTL_FSM_SYM_TYPE_WIDTH    ((uint32_t)0x00000002)
#define SPU_STAT_8_TX_CTL_FSM_STATE_MASK    ((uint32_t)0x00000003)
#define SPU_STAT_8_TX_CTL_FSM_STATE_LSB     0
#define SPU_STAT_8_TX_CTL_FSM_STATE_WIDTH    ((uint32_t)0x00000002)

#define SPU_STAT_8_TX_CTL_FSM_DEC_RST       0x0
#define SPU_STAT_8_TX_CTL_FSM_REP_RST       0x0
#define SPU_STAT_8_TX_CTL_FSM_SYM_TYPE_RST    0x3
#define SPU_STAT_8_TX_CTL_FSM_STATE_RST     0x0

__INLINE void spu_stat_8_unpack(uint8_t* tx_ctl_fsm_dec, uint8_t* tx_ctl_fsm_rep, uint8_t* tx_ctl_fsm_sym_type, uint8_t* tx_ctl_fsm_state)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_8_ADDR);

	*tx_ctl_fsm_dec = (localVal & ((uint32_t)0x00000080)) >>  7;
	*tx_ctl_fsm_rep = (localVal & ((uint32_t)0x00000070)) >>  4;
	*tx_ctl_fsm_sym_type = (localVal & ((uint32_t)0x0000000C)) >>  2;
	*tx_ctl_fsm_state = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t spu_stat_8_tx_ctl_fsm_dec_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE uint8_t spu_stat_8_tx_ctl_fsm_rep_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE uint8_t spu_stat_8_tx_ctl_fsm_sym_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000C)) >> 2);
}
__INLINE uint8_t spu_stat_8_tx_ctl_fsm_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_STAT_8_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief SCALE_S_HESTF_U_01 register definition
 *  HESTF stream scaling users 0 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_S_HESTF_U1          0x0
 *    15:00 SCALE_S_HESTF_U0          0x0
 * </pre>
 */
#define SPU_SCALE_S_HESTF_U_01_ADDR        (REG_SPU_BASE_ADDR+0x00000190)
#define SPU_SCALE_S_HESTF_U_01_OFFSET      0x00000190
#define SPU_SCALE_S_HESTF_U_01_INDEX       0x00000064
#define SPU_SCALE_S_HESTF_U_01_RESET       0x00000000

__INLINE uint32_t  spu_scale_s_hestf_u_01_get(void)
{
	return REG_PL_RD(SPU_SCALE_S_HESTF_U_01_ADDR);
}

__INLINE void spu_scale_s_hestf_u_01_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_S_HESTF_U_01_ADDR, value);
}

// field definitions
#define SPU_SCALE_S_HESTF_U_01_SCALE_S_HESTF_U_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_S_HESTF_U_01_SCALE_S_HESTF_U_1_LSB    16
#define SPU_SCALE_S_HESTF_U_01_SCALE_S_HESTF_U_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_S_HESTF_U_01_SCALE_S_HESTF_U_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_S_HESTF_U_01_SCALE_S_HESTF_U_0_LSB    0
#define SPU_SCALE_S_HESTF_U_01_SCALE_S_HESTF_U_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_S_HESTF_U_01_SCALE_S_HESTF_U_1_RST    0x0
#define SPU_SCALE_S_HESTF_U_01_SCALE_S_HESTF_U_0_RST    0x0

__INLINE void spu_scale_s_hestf_u_01_pack(uint16_t scale_s_hestf_u1, uint16_t scale_s_hestf_u0)
{
	ASSERT_ERR((((uint32_t)scale_s_hestf_u1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_s_hestf_u0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_S_HESTF_U_01_ADDR,  ((uint32_t)scale_s_hestf_u1 << 16) |((uint32_t)scale_s_hestf_u0 << 0));
}

__INLINE void spu_scale_s_hestf_u_01_unpack(uint16_t* scale_s_hestf_u1, uint16_t* scale_s_hestf_u0)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HESTF_U_01_ADDR);

	*scale_s_hestf_u1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_s_hestf_u0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_s_hestf_u_01_scale_s_hestf_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HESTF_U_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_s_hestf_u_01_scale_s_hestf_u_1_setf(uint16_t scaleshestfu1)
{
	ASSERT_ERR((((uint32_t)scaleshestfu1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_S_HESTF_U_01_ADDR, (REG_PL_RD(SPU_SCALE_S_HESTF_U_01_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleshestfu1 <<16));
}
__INLINE uint16_t spu_scale_s_hestf_u_01_scale_s_hestf_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HESTF_U_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_s_hestf_u_01_scale_s_hestf_u_0_setf(uint16_t scaleshestfu0)
{
	ASSERT_ERR((((uint32_t)scaleshestfu0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_S_HESTF_U_01_ADDR, (REG_PL_RD(SPU_SCALE_S_HESTF_U_01_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleshestfu0 <<0));
}

/**
 * @brief SCALE_S_HESTF_U_23 register definition
 *  HESTF stream scaling users  2 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_S_HESTF_U3          0x0
 *    15:00 SCALE_S_HESTF_U2          0x0
 * </pre>
 */
#define SPU_SCALE_S_HESTF_U_23_ADDR        (REG_SPU_BASE_ADDR+0x00000194)
#define SPU_SCALE_S_HESTF_U_23_OFFSET      0x00000194
#define SPU_SCALE_S_HESTF_U_23_INDEX       0x00000065
#define SPU_SCALE_S_HESTF_U_23_RESET       0x00000000

__INLINE uint32_t  spu_scale_s_hestf_u_23_get(void)
{
	return REG_PL_RD(SPU_SCALE_S_HESTF_U_23_ADDR);
}

__INLINE void spu_scale_s_hestf_u_23_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_S_HESTF_U_23_ADDR, value);
}

// field definitions
#define SPU_SCALE_S_HESTF_U_23_SCALE_S_HESTF_U_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_S_HESTF_U_23_SCALE_S_HESTF_U_3_LSB    16
#define SPU_SCALE_S_HESTF_U_23_SCALE_S_HESTF_U_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_S_HESTF_U_23_SCALE_S_HESTF_U_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_S_HESTF_U_23_SCALE_S_HESTF_U_2_LSB    0
#define SPU_SCALE_S_HESTF_U_23_SCALE_S_HESTF_U_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_S_HESTF_U_23_SCALE_S_HESTF_U_3_RST    0x0
#define SPU_SCALE_S_HESTF_U_23_SCALE_S_HESTF_U_2_RST    0x0

__INLINE void spu_scale_s_hestf_u_23_pack(uint16_t scale_s_hestf_u3, uint16_t scale_s_hestf_u2)
{
	ASSERT_ERR((((uint32_t)scale_s_hestf_u3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_s_hestf_u2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_S_HESTF_U_23_ADDR,  ((uint32_t)scale_s_hestf_u3 << 16) |((uint32_t)scale_s_hestf_u2 << 0));
}

__INLINE void spu_scale_s_hestf_u_23_unpack(uint16_t* scale_s_hestf_u3, uint16_t* scale_s_hestf_u2)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HESTF_U_23_ADDR);

	*scale_s_hestf_u3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_s_hestf_u2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_s_hestf_u_23_scale_s_hestf_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HESTF_U_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_s_hestf_u_23_scale_s_hestf_u_3_setf(uint16_t scaleshestfu3)
{
	ASSERT_ERR((((uint32_t)scaleshestfu3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_S_HESTF_U_23_ADDR, (REG_PL_RD(SPU_SCALE_S_HESTF_U_23_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleshestfu3 <<16));
}
__INLINE uint16_t spu_scale_s_hestf_u_23_scale_s_hestf_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HESTF_U_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_s_hestf_u_23_scale_s_hestf_u_2_setf(uint16_t scaleshestfu2)
{
	ASSERT_ERR((((uint32_t)scaleshestfu2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_S_HESTF_U_23_ADDR, (REG_PL_RD(SPU_SCALE_S_HESTF_U_23_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleshestfu2 <<0));
}

/**
 * @brief SCALE_S_HESTF_U_45 register definition
 *  HESTF stream scaling users 4 5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_S_HESTF_U5          0x0
 *    15:00 SCALE_S_HESTF_U4          0x0
 * </pre>
 */
#define SPU_SCALE_S_HESTF_U_45_ADDR        (REG_SPU_BASE_ADDR+0x00000198)
#define SPU_SCALE_S_HESTF_U_45_OFFSET      0x00000198
#define SPU_SCALE_S_HESTF_U_45_INDEX       0x00000066
#define SPU_SCALE_S_HESTF_U_45_RESET       0x00000000

__INLINE uint32_t  spu_scale_s_hestf_u_45_get(void)
{
	return REG_PL_RD(SPU_SCALE_S_HESTF_U_45_ADDR);
}

__INLINE void spu_scale_s_hestf_u_45_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_S_HESTF_U_45_ADDR, value);
}

// field definitions
#define SPU_SCALE_S_HESTF_U_45_SCALE_S_HESTF_U_5_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_S_HESTF_U_45_SCALE_S_HESTF_U_5_LSB    16
#define SPU_SCALE_S_HESTF_U_45_SCALE_S_HESTF_U_5_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_S_HESTF_U_45_SCALE_S_HESTF_U_4_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_S_HESTF_U_45_SCALE_S_HESTF_U_4_LSB    0
#define SPU_SCALE_S_HESTF_U_45_SCALE_S_HESTF_U_4_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_S_HESTF_U_45_SCALE_S_HESTF_U_5_RST    0x0
#define SPU_SCALE_S_HESTF_U_45_SCALE_S_HESTF_U_4_RST    0x0

__INLINE void spu_scale_s_hestf_u_45_pack(uint16_t scale_s_hestf_u5, uint16_t scale_s_hestf_u4)
{
	ASSERT_ERR((((uint32_t)scale_s_hestf_u5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_s_hestf_u4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_S_HESTF_U_45_ADDR,  ((uint32_t)scale_s_hestf_u5 << 16) |((uint32_t)scale_s_hestf_u4 << 0));
}

__INLINE void spu_scale_s_hestf_u_45_unpack(uint16_t* scale_s_hestf_u5, uint16_t* scale_s_hestf_u4)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HESTF_U_45_ADDR);

	*scale_s_hestf_u5 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_s_hestf_u4 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_s_hestf_u_45_scale_s_hestf_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HESTF_U_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_s_hestf_u_45_scale_s_hestf_u_5_setf(uint16_t scaleshestfu5)
{
	ASSERT_ERR((((uint32_t)scaleshestfu5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_S_HESTF_U_45_ADDR, (REG_PL_RD(SPU_SCALE_S_HESTF_U_45_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleshestfu5 <<16));
}
__INLINE uint16_t spu_scale_s_hestf_u_45_scale_s_hestf_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HESTF_U_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_s_hestf_u_45_scale_s_hestf_u_4_setf(uint16_t scaleshestfu4)
{
	ASSERT_ERR((((uint32_t)scaleshestfu4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_S_HESTF_U_45_ADDR, (REG_PL_RD(SPU_SCALE_S_HESTF_U_45_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleshestfu4 <<0));
}

/**
 * @brief SCALE_S_HESTF_U_67 register definition
 *  HESTF stream scaling users 6 7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_S_HESTF_U7          0x0
 *    15:00 SCALE_S_HESTF_U6          0x0
 * </pre>
 */
#define SPU_SCALE_S_HESTF_U_67_ADDR        (REG_SPU_BASE_ADDR+0x0000019C)
#define SPU_SCALE_S_HESTF_U_67_OFFSET      0x0000019C
#define SPU_SCALE_S_HESTF_U_67_INDEX       0x00000067
#define SPU_SCALE_S_HESTF_U_67_RESET       0x00000000

__INLINE uint32_t  spu_scale_s_hestf_u_67_get(void)
{
	return REG_PL_RD(SPU_SCALE_S_HESTF_U_67_ADDR);
}

__INLINE void spu_scale_s_hestf_u_67_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_S_HESTF_U_67_ADDR, value);
}

// field definitions
#define SPU_SCALE_S_HESTF_U_67_SCALE_S_HESTF_U_7_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_S_HESTF_U_67_SCALE_S_HESTF_U_7_LSB    16
#define SPU_SCALE_S_HESTF_U_67_SCALE_S_HESTF_U_7_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_S_HESTF_U_67_SCALE_S_HESTF_U_6_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_S_HESTF_U_67_SCALE_S_HESTF_U_6_LSB    0
#define SPU_SCALE_S_HESTF_U_67_SCALE_S_HESTF_U_6_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_S_HESTF_U_67_SCALE_S_HESTF_U_7_RST    0x0
#define SPU_SCALE_S_HESTF_U_67_SCALE_S_HESTF_U_6_RST    0x0

__INLINE void spu_scale_s_hestf_u_67_pack(uint16_t scale_s_hestf_u7, uint16_t scale_s_hestf_u6)
{
	ASSERT_ERR((((uint32_t)scale_s_hestf_u7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_s_hestf_u6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_S_HESTF_U_67_ADDR,  ((uint32_t)scale_s_hestf_u7 << 16) |((uint32_t)scale_s_hestf_u6 << 0));
}

__INLINE void spu_scale_s_hestf_u_67_unpack(uint16_t* scale_s_hestf_u7, uint16_t* scale_s_hestf_u6)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HESTF_U_67_ADDR);

	*scale_s_hestf_u7 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_s_hestf_u6 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_s_hestf_u_67_scale_s_hestf_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HESTF_U_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_s_hestf_u_67_scale_s_hestf_u_7_setf(uint16_t scaleshestfu7)
{
	ASSERT_ERR((((uint32_t)scaleshestfu7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_S_HESTF_U_67_ADDR, (REG_PL_RD(SPU_SCALE_S_HESTF_U_67_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleshestfu7 <<16));
}
__INLINE uint16_t spu_scale_s_hestf_u_67_scale_s_hestf_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HESTF_U_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_s_hestf_u_67_scale_s_hestf_u_6_setf(uint16_t scaleshestfu6)
{
	ASSERT_ERR((((uint32_t)scaleshestfu6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_S_HESTF_U_67_ADDR, (REG_PL_RD(SPU_SCALE_S_HESTF_U_67_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleshestfu6 <<0));
}

/**
 * @brief SCALE_S_HELTF_U_01 register definition
 *  HELTF stream scaling users 0 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_S_HELTF_U1          0x0
 *    15:00 SCALE_S_HELTF_U0          0x0
 * </pre>
 */
#define SPU_SCALE_S_HELTF_U_01_ADDR        (REG_SPU_BASE_ADDR+0x000001A0)
#define SPU_SCALE_S_HELTF_U_01_OFFSET      0x000001A0
#define SPU_SCALE_S_HELTF_U_01_INDEX       0x00000068
#define SPU_SCALE_S_HELTF_U_01_RESET       0x00000000

__INLINE uint32_t  spu_scale_s_heltf_u_01_get(void)
{
	return REG_PL_RD(SPU_SCALE_S_HELTF_U_01_ADDR);
}

__INLINE void spu_scale_s_heltf_u_01_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_S_HELTF_U_01_ADDR, value);
}

// field definitions
#define SPU_SCALE_S_HELTF_U_01_SCALE_S_HELTF_U_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_S_HELTF_U_01_SCALE_S_HELTF_U_1_LSB    16
#define SPU_SCALE_S_HELTF_U_01_SCALE_S_HELTF_U_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_S_HELTF_U_01_SCALE_S_HELTF_U_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_S_HELTF_U_01_SCALE_S_HELTF_U_0_LSB    0
#define SPU_SCALE_S_HELTF_U_01_SCALE_S_HELTF_U_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_S_HELTF_U_01_SCALE_S_HELTF_U_1_RST    0x0
#define SPU_SCALE_S_HELTF_U_01_SCALE_S_HELTF_U_0_RST    0x0

__INLINE void spu_scale_s_heltf_u_01_pack(uint16_t scale_s_heltf_u1, uint16_t scale_s_heltf_u0)
{
	ASSERT_ERR((((uint32_t)scale_s_heltf_u1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_s_heltf_u0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_S_HELTF_U_01_ADDR,  ((uint32_t)scale_s_heltf_u1 << 16) |((uint32_t)scale_s_heltf_u0 << 0));
}

__INLINE void spu_scale_s_heltf_u_01_unpack(uint16_t* scale_s_heltf_u1, uint16_t* scale_s_heltf_u0)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HELTF_U_01_ADDR);

	*scale_s_heltf_u1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_s_heltf_u0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_s_heltf_u_01_scale_s_heltf_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HELTF_U_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_s_heltf_u_01_scale_s_heltf_u_1_setf(uint16_t scalesheltfu1)
{
	ASSERT_ERR((((uint32_t)scalesheltfu1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_S_HELTF_U_01_ADDR, (REG_PL_RD(SPU_SCALE_S_HELTF_U_01_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalesheltfu1 <<16));
}
__INLINE uint16_t spu_scale_s_heltf_u_01_scale_s_heltf_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HELTF_U_01_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_s_heltf_u_01_scale_s_heltf_u_0_setf(uint16_t scalesheltfu0)
{
	ASSERT_ERR((((uint32_t)scalesheltfu0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_S_HELTF_U_01_ADDR, (REG_PL_RD(SPU_SCALE_S_HELTF_U_01_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalesheltfu0 <<0));
}

/**
 * @brief SCALE_S_HELTF_U_23 register definition
 *  HELTF stream scaling users  2 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_S_HELTF_U3          0x0
 *    15:00 SCALE_S_HELTF_U2          0x0
 * </pre>
 */
#define SPU_SCALE_S_HELTF_U_23_ADDR        (REG_SPU_BASE_ADDR+0x000001A4)
#define SPU_SCALE_S_HELTF_U_23_OFFSET      0x000001A4
#define SPU_SCALE_S_HELTF_U_23_INDEX       0x00000069
#define SPU_SCALE_S_HELTF_U_23_RESET       0x00000000

__INLINE uint32_t  spu_scale_s_heltf_u_23_get(void)
{
	return REG_PL_RD(SPU_SCALE_S_HELTF_U_23_ADDR);
}

__INLINE void spu_scale_s_heltf_u_23_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_S_HELTF_U_23_ADDR, value);
}

// field definitions
#define SPU_SCALE_S_HELTF_U_23_SCALE_S_HELTF_U_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_S_HELTF_U_23_SCALE_S_HELTF_U_3_LSB    16
#define SPU_SCALE_S_HELTF_U_23_SCALE_S_HELTF_U_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_S_HELTF_U_23_SCALE_S_HELTF_U_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_S_HELTF_U_23_SCALE_S_HELTF_U_2_LSB    0
#define SPU_SCALE_S_HELTF_U_23_SCALE_S_HELTF_U_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_S_HELTF_U_23_SCALE_S_HELTF_U_3_RST    0x0
#define SPU_SCALE_S_HELTF_U_23_SCALE_S_HELTF_U_2_RST    0x0

__INLINE void spu_scale_s_heltf_u_23_pack(uint16_t scale_s_heltf_u3, uint16_t scale_s_heltf_u2)
{
	ASSERT_ERR((((uint32_t)scale_s_heltf_u3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_s_heltf_u2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_S_HELTF_U_23_ADDR,  ((uint32_t)scale_s_heltf_u3 << 16) |((uint32_t)scale_s_heltf_u2 << 0));
}

__INLINE void spu_scale_s_heltf_u_23_unpack(uint16_t* scale_s_heltf_u3, uint16_t* scale_s_heltf_u2)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HELTF_U_23_ADDR);

	*scale_s_heltf_u3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_s_heltf_u2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_s_heltf_u_23_scale_s_heltf_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HELTF_U_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_s_heltf_u_23_scale_s_heltf_u_3_setf(uint16_t scalesheltfu3)
{
	ASSERT_ERR((((uint32_t)scalesheltfu3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_S_HELTF_U_23_ADDR, (REG_PL_RD(SPU_SCALE_S_HELTF_U_23_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalesheltfu3 <<16));
}
__INLINE uint16_t spu_scale_s_heltf_u_23_scale_s_heltf_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HELTF_U_23_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_s_heltf_u_23_scale_s_heltf_u_2_setf(uint16_t scalesheltfu2)
{
	ASSERT_ERR((((uint32_t)scalesheltfu2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_S_HELTF_U_23_ADDR, (REG_PL_RD(SPU_SCALE_S_HELTF_U_23_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalesheltfu2 <<0));
}

/**
 * @brief SCALE_S_HELTF_U_45 register definition
 *  HELTF stream scaling users 4 5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_S_HELTF_U5          0x0
 *    15:00 SCALE_S_HELTF_U4          0x0
 * </pre>
 */
#define SPU_SCALE_S_HELTF_U_45_ADDR        (REG_SPU_BASE_ADDR+0x000001A8)
#define SPU_SCALE_S_HELTF_U_45_OFFSET      0x000001A8
#define SPU_SCALE_S_HELTF_U_45_INDEX       0x0000006A
#define SPU_SCALE_S_HELTF_U_45_RESET       0x00000000

__INLINE uint32_t  spu_scale_s_heltf_u_45_get(void)
{
	return REG_PL_RD(SPU_SCALE_S_HELTF_U_45_ADDR);
}

__INLINE void spu_scale_s_heltf_u_45_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_S_HELTF_U_45_ADDR, value);
}

// field definitions
#define SPU_SCALE_S_HELTF_U_45_SCALE_S_HELTF_U_5_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_S_HELTF_U_45_SCALE_S_HELTF_U_5_LSB    16
#define SPU_SCALE_S_HELTF_U_45_SCALE_S_HELTF_U_5_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_S_HELTF_U_45_SCALE_S_HELTF_U_4_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_S_HELTF_U_45_SCALE_S_HELTF_U_4_LSB    0
#define SPU_SCALE_S_HELTF_U_45_SCALE_S_HELTF_U_4_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_S_HELTF_U_45_SCALE_S_HELTF_U_5_RST    0x0
#define SPU_SCALE_S_HELTF_U_45_SCALE_S_HELTF_U_4_RST    0x0

__INLINE void spu_scale_s_heltf_u_45_pack(uint16_t scale_s_heltf_u5, uint16_t scale_s_heltf_u4)
{
	ASSERT_ERR((((uint32_t)scale_s_heltf_u5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_s_heltf_u4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_S_HELTF_U_45_ADDR,  ((uint32_t)scale_s_heltf_u5 << 16) |((uint32_t)scale_s_heltf_u4 << 0));
}

__INLINE void spu_scale_s_heltf_u_45_unpack(uint16_t* scale_s_heltf_u5, uint16_t* scale_s_heltf_u4)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HELTF_U_45_ADDR);

	*scale_s_heltf_u5 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_s_heltf_u4 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_s_heltf_u_45_scale_s_heltf_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HELTF_U_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_s_heltf_u_45_scale_s_heltf_u_5_setf(uint16_t scalesheltfu5)
{
	ASSERT_ERR((((uint32_t)scalesheltfu5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_S_HELTF_U_45_ADDR, (REG_PL_RD(SPU_SCALE_S_HELTF_U_45_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalesheltfu5 <<16));
}
__INLINE uint16_t spu_scale_s_heltf_u_45_scale_s_heltf_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HELTF_U_45_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_s_heltf_u_45_scale_s_heltf_u_4_setf(uint16_t scalesheltfu4)
{
	ASSERT_ERR((((uint32_t)scalesheltfu4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_S_HELTF_U_45_ADDR, (REG_PL_RD(SPU_SCALE_S_HELTF_U_45_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalesheltfu4 <<0));
}

/**
 * @brief SCALE_S_HELTF_U_67 register definition
 *  HELTF stream scaling users 6 7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_S_HELTF_U7          0x0
 *    15:00 SCALE_S_HELTF_U6          0x0
 * </pre>
 */
#define SPU_SCALE_S_HELTF_U_67_ADDR        (REG_SPU_BASE_ADDR+0x000001AC)
#define SPU_SCALE_S_HELTF_U_67_OFFSET      0x000001AC
#define SPU_SCALE_S_HELTF_U_67_INDEX       0x0000006B
#define SPU_SCALE_S_HELTF_U_67_RESET       0x00000000

__INLINE uint32_t  spu_scale_s_heltf_u_67_get(void)
{
	return REG_PL_RD(SPU_SCALE_S_HELTF_U_67_ADDR);
}

__INLINE void spu_scale_s_heltf_u_67_set(uint32_t value)
{
	REG_PL_WR(SPU_SCALE_S_HELTF_U_67_ADDR, value);
}

// field definitions
#define SPU_SCALE_S_HELTF_U_67_SCALE_S_HELTF_U_7_MASK    ((uint32_t)0xFFFF0000)
#define SPU_SCALE_S_HELTF_U_67_SCALE_S_HELTF_U_7_LSB    16
#define SPU_SCALE_S_HELTF_U_67_SCALE_S_HELTF_U_7_WIDTH    ((uint32_t)0x00000010)
#define SPU_SCALE_S_HELTF_U_67_SCALE_S_HELTF_U_6_MASK    ((uint32_t)0x0000FFFF)
#define SPU_SCALE_S_HELTF_U_67_SCALE_S_HELTF_U_6_LSB    0
#define SPU_SCALE_S_HELTF_U_67_SCALE_S_HELTF_U_6_WIDTH    ((uint32_t)0x00000010)

#define SPU_SCALE_S_HELTF_U_67_SCALE_S_HELTF_U_7_RST    0x0
#define SPU_SCALE_S_HELTF_U_67_SCALE_S_HELTF_U_6_RST    0x0

__INLINE void spu_scale_s_heltf_u_67_pack(uint16_t scale_s_heltf_u7, uint16_t scale_s_heltf_u6)
{
	ASSERT_ERR((((uint32_t)scale_s_heltf_u7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_s_heltf_u6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_S_HELTF_U_67_ADDR,  ((uint32_t)scale_s_heltf_u7 << 16) |((uint32_t)scale_s_heltf_u6 << 0));
}

__INLINE void spu_scale_s_heltf_u_67_unpack(uint16_t* scale_s_heltf_u7, uint16_t* scale_s_heltf_u6)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HELTF_U_67_ADDR);

	*scale_s_heltf_u7 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_s_heltf_u6 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_scale_s_heltf_u_67_scale_s_heltf_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HELTF_U_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_scale_s_heltf_u_67_scale_s_heltf_u_7_setf(uint16_t scalesheltfu7)
{
	ASSERT_ERR((((uint32_t)scalesheltfu7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_SCALE_S_HELTF_U_67_ADDR, (REG_PL_RD(SPU_SCALE_S_HELTF_U_67_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalesheltfu7 <<16));
}
__INLINE uint16_t spu_scale_s_heltf_u_67_scale_s_heltf_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_SCALE_S_HELTF_U_67_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_scale_s_heltf_u_67_scale_s_heltf_u_6_setf(uint16_t scalesheltfu6)
{
	ASSERT_ERR((((uint32_t)scalesheltfu6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_SCALE_S_HELTF_U_67_ADDR, (REG_PL_RD(SPU_SCALE_S_HELTF_U_67_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalesheltfu6 <<0));
}

/**
 * @brief USER_0_CONF_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 RX_MOD_TYPE_U0            0x0
 *    23:12 CW_LIM_U0                 0x0
 *    11:00 CW_BASE_U0                0x0
 * </pre>
 */
#define SPU_USER_0_CONF_2_ADDR        (REG_SPU_BASE_ADDR+0x000001B0)
#define SPU_USER_0_CONF_2_OFFSET      0x000001B0
#define SPU_USER_0_CONF_2_INDEX       0x0000006C
#define SPU_USER_0_CONF_2_RESET       0x00000000

__INLINE uint32_t  spu_user_0_conf_2_get(void)
{
	return REG_PL_RD(SPU_USER_0_CONF_2_ADDR);
}

__INLINE void spu_user_0_conf_2_set(uint32_t value)
{
	REG_PL_WR(SPU_USER_0_CONF_2_ADDR, value);
}

// field definitions
#define SPU_USER_0_CONF_2_RX_MOD_TYPE_U_0_MASK    ((uint32_t)0x07000000)
#define SPU_USER_0_CONF_2_RX_MOD_TYPE_U_0_LSB    24
#define SPU_USER_0_CONF_2_RX_MOD_TYPE_U_0_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_0_CONF_2_CW_LIM_U_0_MASK    ((uint32_t)0x00FFF000)
#define SPU_USER_0_CONF_2_CW_LIM_U_0_LSB    12
#define SPU_USER_0_CONF_2_CW_LIM_U_0_WIDTH    ((uint32_t)0x0000000C)
#define SPU_USER_0_CONF_2_CW_BASE_U_0_MASK    ((uint32_t)0x00000FFF)
#define SPU_USER_0_CONF_2_CW_BASE_U_0_LSB    0
#define SPU_USER_0_CONF_2_CW_BASE_U_0_WIDTH    ((uint32_t)0x0000000C)

#define SPU_USER_0_CONF_2_RX_MOD_TYPE_U_0_RST    0x0
#define SPU_USER_0_CONF_2_CW_LIM_U_0_RST    0x0
#define SPU_USER_0_CONF_2_CW_BASE_U_0_RST    0x0

__INLINE void spu_user_0_conf_2_pack(uint8_t rx_mod_type_u0, uint16_t cw_lim_u0, uint16_t cw_base_u0)
{
	ASSERT_ERR((((uint32_t)rx_mod_type_u0 << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)cw_lim_u0 << 12) & ~((uint32_t)0x00FFF000)) == 0);
	ASSERT_ERR((((uint32_t)cw_base_u0 << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(SPU_USER_0_CONF_2_ADDR,  ((uint32_t)rx_mod_type_u0 << 24) |((uint32_t)cw_lim_u0 << 12) |((uint32_t)cw_base_u0 << 0));
}

__INLINE void spu_user_0_conf_2_unpack(uint8_t* rx_mod_type_u0, uint16_t* cw_lim_u0, uint16_t* cw_base_u0)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_0_CONF_2_ADDR);

	*rx_mod_type_u0 = (localVal & ((uint32_t)0x07000000)) >>  24;
	*cw_lim_u0 = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*cw_base_u0 = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t spu_user_0_conf_2_rx_mod_type_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_0_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void spu_user_0_conf_2_rx_mod_type_u_0_setf(uint8_t rxmodtypeu0)
{
	ASSERT_ERR((((uint32_t)rxmodtypeu0 << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SPU_USER_0_CONF_2_ADDR, (REG_PL_RD(SPU_USER_0_CONF_2_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)rxmodtypeu0 <<24));
}
__INLINE uint16_t spu_user_0_conf_2_cw_lim_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_0_CONF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE void spu_user_0_conf_2_cw_lim_u_0_setf(uint16_t cwlimu0)
{
	ASSERT_ERR((((uint32_t)cwlimu0 << 12) & ~((uint32_t)0x00FFF000)) == 0);
	REG_PL_WR(SPU_USER_0_CONF_2_ADDR, (REG_PL_RD(SPU_USER_0_CONF_2_ADDR) & ~((uint32_t)0x00FFF000)) | ((uint32_t)cwlimu0 <<12));
}
__INLINE uint16_t spu_user_0_conf_2_cw_base_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_0_CONF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void spu_user_0_conf_2_cw_base_u_0_setf(uint16_t cwbaseu0)
{
	ASSERT_ERR((((uint32_t)cwbaseu0 << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(SPU_USER_0_CONF_2_ADDR, (REG_PL_RD(SPU_USER_0_CONF_2_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)cwbaseu0 <<0));
}

/**
 * @brief USER_1_CONF_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 RX_MOD_TYPE_U1            0x0
 *    23:12 CW_LIM_U1                 0x0
 *    11:00 CW_BASE_U1                0x0
 * </pre>
 */
#define SPU_USER_1_CONF_2_ADDR        (REG_SPU_BASE_ADDR+0x000001B4)
#define SPU_USER_1_CONF_2_OFFSET      0x000001B4
#define SPU_USER_1_CONF_2_INDEX       0x0000006D
#define SPU_USER_1_CONF_2_RESET       0x00000000

__INLINE uint32_t  spu_user_1_conf_2_get(void)
{
	return REG_PL_RD(SPU_USER_1_CONF_2_ADDR);
}

__INLINE void spu_user_1_conf_2_set(uint32_t value)
{
	REG_PL_WR(SPU_USER_1_CONF_2_ADDR, value);
}

// field definitions
#define SPU_USER_1_CONF_2_RX_MOD_TYPE_U_1_MASK    ((uint32_t)0x07000000)
#define SPU_USER_1_CONF_2_RX_MOD_TYPE_U_1_LSB    24
#define SPU_USER_1_CONF_2_RX_MOD_TYPE_U_1_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_1_CONF_2_CW_LIM_U_1_MASK    ((uint32_t)0x00FFF000)
#define SPU_USER_1_CONF_2_CW_LIM_U_1_LSB    12
#define SPU_USER_1_CONF_2_CW_LIM_U_1_WIDTH    ((uint32_t)0x0000000C)
#define SPU_USER_1_CONF_2_CW_BASE_U_1_MASK    ((uint32_t)0x00000FFF)
#define SPU_USER_1_CONF_2_CW_BASE_U_1_LSB    0
#define SPU_USER_1_CONF_2_CW_BASE_U_1_WIDTH    ((uint32_t)0x0000000C)

#define SPU_USER_1_CONF_2_RX_MOD_TYPE_U_1_RST    0x0
#define SPU_USER_1_CONF_2_CW_LIM_U_1_RST    0x0
#define SPU_USER_1_CONF_2_CW_BASE_U_1_RST    0x0

__INLINE void spu_user_1_conf_2_pack(uint8_t rx_mod_type_u1, uint16_t cw_lim_u1, uint16_t cw_base_u1)
{
	ASSERT_ERR((((uint32_t)rx_mod_type_u1 << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)cw_lim_u1 << 12) & ~((uint32_t)0x00FFF000)) == 0);
	ASSERT_ERR((((uint32_t)cw_base_u1 << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(SPU_USER_1_CONF_2_ADDR,  ((uint32_t)rx_mod_type_u1 << 24) |((uint32_t)cw_lim_u1 << 12) |((uint32_t)cw_base_u1 << 0));
}

__INLINE void spu_user_1_conf_2_unpack(uint8_t* rx_mod_type_u1, uint16_t* cw_lim_u1, uint16_t* cw_base_u1)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_1_CONF_2_ADDR);

	*rx_mod_type_u1 = (localVal & ((uint32_t)0x07000000)) >>  24;
	*cw_lim_u1 = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*cw_base_u1 = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t spu_user_1_conf_2_rx_mod_type_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_1_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void spu_user_1_conf_2_rx_mod_type_u_1_setf(uint8_t rxmodtypeu1)
{
	ASSERT_ERR((((uint32_t)rxmodtypeu1 << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SPU_USER_1_CONF_2_ADDR, (REG_PL_RD(SPU_USER_1_CONF_2_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)rxmodtypeu1 <<24));
}
__INLINE uint16_t spu_user_1_conf_2_cw_lim_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_1_CONF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE void spu_user_1_conf_2_cw_lim_u_1_setf(uint16_t cwlimu1)
{
	ASSERT_ERR((((uint32_t)cwlimu1 << 12) & ~((uint32_t)0x00FFF000)) == 0);
	REG_PL_WR(SPU_USER_1_CONF_2_ADDR, (REG_PL_RD(SPU_USER_1_CONF_2_ADDR) & ~((uint32_t)0x00FFF000)) | ((uint32_t)cwlimu1 <<12));
}
__INLINE uint16_t spu_user_1_conf_2_cw_base_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_1_CONF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void spu_user_1_conf_2_cw_base_u_1_setf(uint16_t cwbaseu1)
{
	ASSERT_ERR((((uint32_t)cwbaseu1 << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(SPU_USER_1_CONF_2_ADDR, (REG_PL_RD(SPU_USER_1_CONF_2_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)cwbaseu1 <<0));
}

/**
 * @brief USER_2_CONF_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 RX_MOD_TYPE_U2            0x0
 *    23:12 CW_LIM_U2                 0x0
 *    11:00 CW_BASE_U2                0x0
 * </pre>
 */
#define SPU_USER_2_CONF_2_ADDR        (REG_SPU_BASE_ADDR+0x000001B8)
#define SPU_USER_2_CONF_2_OFFSET      0x000001B8
#define SPU_USER_2_CONF_2_INDEX       0x0000006E
#define SPU_USER_2_CONF_2_RESET       0x00000000

__INLINE uint32_t  spu_user_2_conf_2_get(void)
{
	return REG_PL_RD(SPU_USER_2_CONF_2_ADDR);
}

__INLINE void spu_user_2_conf_2_set(uint32_t value)
{
	REG_PL_WR(SPU_USER_2_CONF_2_ADDR, value);
}

// field definitions
#define SPU_USER_2_CONF_2_RX_MOD_TYPE_U_2_MASK    ((uint32_t)0x07000000)
#define SPU_USER_2_CONF_2_RX_MOD_TYPE_U_2_LSB    24
#define SPU_USER_2_CONF_2_RX_MOD_TYPE_U_2_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_2_CONF_2_CW_LIM_U_2_MASK    ((uint32_t)0x00FFF000)
#define SPU_USER_2_CONF_2_CW_LIM_U_2_LSB    12
#define SPU_USER_2_CONF_2_CW_LIM_U_2_WIDTH    ((uint32_t)0x0000000C)
#define SPU_USER_2_CONF_2_CW_BASE_U_2_MASK    ((uint32_t)0x00000FFF)
#define SPU_USER_2_CONF_2_CW_BASE_U_2_LSB    0
#define SPU_USER_2_CONF_2_CW_BASE_U_2_WIDTH    ((uint32_t)0x0000000C)

#define SPU_USER_2_CONF_2_RX_MOD_TYPE_U_2_RST    0x0
#define SPU_USER_2_CONF_2_CW_LIM_U_2_RST    0x0
#define SPU_USER_2_CONF_2_CW_BASE_U_2_RST    0x0

__INLINE void spu_user_2_conf_2_pack(uint8_t rx_mod_type_u2, uint16_t cw_lim_u2, uint16_t cw_base_u2)
{
	ASSERT_ERR((((uint32_t)rx_mod_type_u2 << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)cw_lim_u2 << 12) & ~((uint32_t)0x00FFF000)) == 0);
	ASSERT_ERR((((uint32_t)cw_base_u2 << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(SPU_USER_2_CONF_2_ADDR,  ((uint32_t)rx_mod_type_u2 << 24) |((uint32_t)cw_lim_u2 << 12) |((uint32_t)cw_base_u2 << 0));
}

__INLINE void spu_user_2_conf_2_unpack(uint8_t* rx_mod_type_u2, uint16_t* cw_lim_u2, uint16_t* cw_base_u2)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_2_CONF_2_ADDR);

	*rx_mod_type_u2 = (localVal & ((uint32_t)0x07000000)) >>  24;
	*cw_lim_u2 = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*cw_base_u2 = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t spu_user_2_conf_2_rx_mod_type_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_2_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void spu_user_2_conf_2_rx_mod_type_u_2_setf(uint8_t rxmodtypeu2)
{
	ASSERT_ERR((((uint32_t)rxmodtypeu2 << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SPU_USER_2_CONF_2_ADDR, (REG_PL_RD(SPU_USER_2_CONF_2_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)rxmodtypeu2 <<24));
}
__INLINE uint16_t spu_user_2_conf_2_cw_lim_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_2_CONF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE void spu_user_2_conf_2_cw_lim_u_2_setf(uint16_t cwlimu2)
{
	ASSERT_ERR((((uint32_t)cwlimu2 << 12) & ~((uint32_t)0x00FFF000)) == 0);
	REG_PL_WR(SPU_USER_2_CONF_2_ADDR, (REG_PL_RD(SPU_USER_2_CONF_2_ADDR) & ~((uint32_t)0x00FFF000)) | ((uint32_t)cwlimu2 <<12));
}
__INLINE uint16_t spu_user_2_conf_2_cw_base_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_2_CONF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void spu_user_2_conf_2_cw_base_u_2_setf(uint16_t cwbaseu2)
{
	ASSERT_ERR((((uint32_t)cwbaseu2 << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(SPU_USER_2_CONF_2_ADDR, (REG_PL_RD(SPU_USER_2_CONF_2_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)cwbaseu2 <<0));
}

/**
 * @brief USER_3_CONF_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 RX_MOD_TYPE_U3            0x0
 *    23:12 CW_LIM_U3                 0x0
 *    11:00 CW_BASE_U3                0x0
 * </pre>
 */
#define SPU_USER_3_CONF_2_ADDR        (REG_SPU_BASE_ADDR+0x000001BC)
#define SPU_USER_3_CONF_2_OFFSET      0x000001BC
#define SPU_USER_3_CONF_2_INDEX       0x0000006F
#define SPU_USER_3_CONF_2_RESET       0x00000000

__INLINE uint32_t  spu_user_3_conf_2_get(void)
{
	return REG_PL_RD(SPU_USER_3_CONF_2_ADDR);
}

__INLINE void spu_user_3_conf_2_set(uint32_t value)
{
	REG_PL_WR(SPU_USER_3_CONF_2_ADDR, value);
}

// field definitions
#define SPU_USER_3_CONF_2_RX_MOD_TYPE_U_3_MASK    ((uint32_t)0x07000000)
#define SPU_USER_3_CONF_2_RX_MOD_TYPE_U_3_LSB    24
#define SPU_USER_3_CONF_2_RX_MOD_TYPE_U_3_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_3_CONF_2_CW_LIM_U_3_MASK    ((uint32_t)0x00FFF000)
#define SPU_USER_3_CONF_2_CW_LIM_U_3_LSB    12
#define SPU_USER_3_CONF_2_CW_LIM_U_3_WIDTH    ((uint32_t)0x0000000C)
#define SPU_USER_3_CONF_2_CW_BASE_U_3_MASK    ((uint32_t)0x00000FFF)
#define SPU_USER_3_CONF_2_CW_BASE_U_3_LSB    0
#define SPU_USER_3_CONF_2_CW_BASE_U_3_WIDTH    ((uint32_t)0x0000000C)

#define SPU_USER_3_CONF_2_RX_MOD_TYPE_U_3_RST    0x0
#define SPU_USER_3_CONF_2_CW_LIM_U_3_RST    0x0
#define SPU_USER_3_CONF_2_CW_BASE_U_3_RST    0x0

__INLINE void spu_user_3_conf_2_pack(uint8_t rx_mod_type_u3, uint16_t cw_lim_u3, uint16_t cw_base_u3)
{
	ASSERT_ERR((((uint32_t)rx_mod_type_u3 << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)cw_lim_u3 << 12) & ~((uint32_t)0x00FFF000)) == 0);
	ASSERT_ERR((((uint32_t)cw_base_u3 << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(SPU_USER_3_CONF_2_ADDR,  ((uint32_t)rx_mod_type_u3 << 24) |((uint32_t)cw_lim_u3 << 12) |((uint32_t)cw_base_u3 << 0));
}

__INLINE void spu_user_3_conf_2_unpack(uint8_t* rx_mod_type_u3, uint16_t* cw_lim_u3, uint16_t* cw_base_u3)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_3_CONF_2_ADDR);

	*rx_mod_type_u3 = (localVal & ((uint32_t)0x07000000)) >>  24;
	*cw_lim_u3 = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*cw_base_u3 = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t spu_user_3_conf_2_rx_mod_type_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_3_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void spu_user_3_conf_2_rx_mod_type_u_3_setf(uint8_t rxmodtypeu3)
{
	ASSERT_ERR((((uint32_t)rxmodtypeu3 << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SPU_USER_3_CONF_2_ADDR, (REG_PL_RD(SPU_USER_3_CONF_2_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)rxmodtypeu3 <<24));
}
__INLINE uint16_t spu_user_3_conf_2_cw_lim_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_3_CONF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE void spu_user_3_conf_2_cw_lim_u_3_setf(uint16_t cwlimu3)
{
	ASSERT_ERR((((uint32_t)cwlimu3 << 12) & ~((uint32_t)0x00FFF000)) == 0);
	REG_PL_WR(SPU_USER_3_CONF_2_ADDR, (REG_PL_RD(SPU_USER_3_CONF_2_ADDR) & ~((uint32_t)0x00FFF000)) | ((uint32_t)cwlimu3 <<12));
}
__INLINE uint16_t spu_user_3_conf_2_cw_base_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_3_CONF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void spu_user_3_conf_2_cw_base_u_3_setf(uint16_t cwbaseu3)
{
	ASSERT_ERR((((uint32_t)cwbaseu3 << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(SPU_USER_3_CONF_2_ADDR, (REG_PL_RD(SPU_USER_3_CONF_2_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)cwbaseu3 <<0));
}

/**
 * @brief USER_4_CONF_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 RX_MOD_TYPE_U4            0x0
 *    23:12 CW_LIM_U4                 0x0
 *    11:00 CW_BASE_U4                0x0
 * </pre>
 */
#define SPU_USER_4_CONF_2_ADDR        (REG_SPU_BASE_ADDR+0x000001C0)
#define SPU_USER_4_CONF_2_OFFSET      0x000001C0
#define SPU_USER_4_CONF_2_INDEX       0x00000070
#define SPU_USER_4_CONF_2_RESET       0x00000000

__INLINE uint32_t  spu_user_4_conf_2_get(void)
{
	return REG_PL_RD(SPU_USER_4_CONF_2_ADDR);
}

__INLINE void spu_user_4_conf_2_set(uint32_t value)
{
	REG_PL_WR(SPU_USER_4_CONF_2_ADDR, value);
}

// field definitions
#define SPU_USER_4_CONF_2_RX_MOD_TYPE_U_4_MASK    ((uint32_t)0x07000000)
#define SPU_USER_4_CONF_2_RX_MOD_TYPE_U_4_LSB    24
#define SPU_USER_4_CONF_2_RX_MOD_TYPE_U_4_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_4_CONF_2_CW_LIM_U_4_MASK    ((uint32_t)0x00FFF000)
#define SPU_USER_4_CONF_2_CW_LIM_U_4_LSB    12
#define SPU_USER_4_CONF_2_CW_LIM_U_4_WIDTH    ((uint32_t)0x0000000C)
#define SPU_USER_4_CONF_2_CW_BASE_U_4_MASK    ((uint32_t)0x00000FFF)
#define SPU_USER_4_CONF_2_CW_BASE_U_4_LSB    0
#define SPU_USER_4_CONF_2_CW_BASE_U_4_WIDTH    ((uint32_t)0x0000000C)

#define SPU_USER_4_CONF_2_RX_MOD_TYPE_U_4_RST    0x0
#define SPU_USER_4_CONF_2_CW_LIM_U_4_RST    0x0
#define SPU_USER_4_CONF_2_CW_BASE_U_4_RST    0x0

__INLINE void spu_user_4_conf_2_pack(uint8_t rx_mod_type_u4, uint16_t cw_lim_u4, uint16_t cw_base_u4)
{
	ASSERT_ERR((((uint32_t)rx_mod_type_u4 << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)cw_lim_u4 << 12) & ~((uint32_t)0x00FFF000)) == 0);
	ASSERT_ERR((((uint32_t)cw_base_u4 << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(SPU_USER_4_CONF_2_ADDR,  ((uint32_t)rx_mod_type_u4 << 24) |((uint32_t)cw_lim_u4 << 12) |((uint32_t)cw_base_u4 << 0));
}

__INLINE void spu_user_4_conf_2_unpack(uint8_t* rx_mod_type_u4, uint16_t* cw_lim_u4, uint16_t* cw_base_u4)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_4_CONF_2_ADDR);

	*rx_mod_type_u4 = (localVal & ((uint32_t)0x07000000)) >>  24;
	*cw_lim_u4 = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*cw_base_u4 = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t spu_user_4_conf_2_rx_mod_type_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_4_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void spu_user_4_conf_2_rx_mod_type_u_4_setf(uint8_t rxmodtypeu4)
{
	ASSERT_ERR((((uint32_t)rxmodtypeu4 << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SPU_USER_4_CONF_2_ADDR, (REG_PL_RD(SPU_USER_4_CONF_2_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)rxmodtypeu4 <<24));
}
__INLINE uint16_t spu_user_4_conf_2_cw_lim_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_4_CONF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE void spu_user_4_conf_2_cw_lim_u_4_setf(uint16_t cwlimu4)
{
	ASSERT_ERR((((uint32_t)cwlimu4 << 12) & ~((uint32_t)0x00FFF000)) == 0);
	REG_PL_WR(SPU_USER_4_CONF_2_ADDR, (REG_PL_RD(SPU_USER_4_CONF_2_ADDR) & ~((uint32_t)0x00FFF000)) | ((uint32_t)cwlimu4 <<12));
}
__INLINE uint16_t spu_user_4_conf_2_cw_base_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_4_CONF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void spu_user_4_conf_2_cw_base_u_4_setf(uint16_t cwbaseu4)
{
	ASSERT_ERR((((uint32_t)cwbaseu4 << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(SPU_USER_4_CONF_2_ADDR, (REG_PL_RD(SPU_USER_4_CONF_2_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)cwbaseu4 <<0));
}

/**
 * @brief USER_5_CONF_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 RX_MOD_TYPE_U5            0x0
 *    23:12 CW_LIM_U5                 0x0
 *    11:00 CW_BASE_U5                0x0
 * </pre>
 */
#define SPU_USER_5_CONF_2_ADDR        (REG_SPU_BASE_ADDR+0x000001C4)
#define SPU_USER_5_CONF_2_OFFSET      0x000001C4
#define SPU_USER_5_CONF_2_INDEX       0x00000071
#define SPU_USER_5_CONF_2_RESET       0x00000000

__INLINE uint32_t  spu_user_5_conf_2_get(void)
{
	return REG_PL_RD(SPU_USER_5_CONF_2_ADDR);
}

__INLINE void spu_user_5_conf_2_set(uint32_t value)
{
	REG_PL_WR(SPU_USER_5_CONF_2_ADDR, value);
}

// field definitions
#define SPU_USER_5_CONF_2_RX_MOD_TYPE_U_5_MASK    ((uint32_t)0x07000000)
#define SPU_USER_5_CONF_2_RX_MOD_TYPE_U_5_LSB    24
#define SPU_USER_5_CONF_2_RX_MOD_TYPE_U_5_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_5_CONF_2_CW_LIM_U_5_MASK    ((uint32_t)0x00FFF000)
#define SPU_USER_5_CONF_2_CW_LIM_U_5_LSB    12
#define SPU_USER_5_CONF_2_CW_LIM_U_5_WIDTH    ((uint32_t)0x0000000C)
#define SPU_USER_5_CONF_2_CW_BASE_U_5_MASK    ((uint32_t)0x00000FFF)
#define SPU_USER_5_CONF_2_CW_BASE_U_5_LSB    0
#define SPU_USER_5_CONF_2_CW_BASE_U_5_WIDTH    ((uint32_t)0x0000000C)

#define SPU_USER_5_CONF_2_RX_MOD_TYPE_U_5_RST    0x0
#define SPU_USER_5_CONF_2_CW_LIM_U_5_RST    0x0
#define SPU_USER_5_CONF_2_CW_BASE_U_5_RST    0x0

__INLINE void spu_user_5_conf_2_pack(uint8_t rx_mod_type_u5, uint16_t cw_lim_u5, uint16_t cw_base_u5)
{
	ASSERT_ERR((((uint32_t)rx_mod_type_u5 << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)cw_lim_u5 << 12) & ~((uint32_t)0x00FFF000)) == 0);
	ASSERT_ERR((((uint32_t)cw_base_u5 << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(SPU_USER_5_CONF_2_ADDR,  ((uint32_t)rx_mod_type_u5 << 24) |((uint32_t)cw_lim_u5 << 12) |((uint32_t)cw_base_u5 << 0));
}

__INLINE void spu_user_5_conf_2_unpack(uint8_t* rx_mod_type_u5, uint16_t* cw_lim_u5, uint16_t* cw_base_u5)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_5_CONF_2_ADDR);

	*rx_mod_type_u5 = (localVal & ((uint32_t)0x07000000)) >>  24;
	*cw_lim_u5 = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*cw_base_u5 = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t spu_user_5_conf_2_rx_mod_type_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_5_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void spu_user_5_conf_2_rx_mod_type_u_5_setf(uint8_t rxmodtypeu5)
{
	ASSERT_ERR((((uint32_t)rxmodtypeu5 << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SPU_USER_5_CONF_2_ADDR, (REG_PL_RD(SPU_USER_5_CONF_2_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)rxmodtypeu5 <<24));
}
__INLINE uint16_t spu_user_5_conf_2_cw_lim_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_5_CONF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE void spu_user_5_conf_2_cw_lim_u_5_setf(uint16_t cwlimu5)
{
	ASSERT_ERR((((uint32_t)cwlimu5 << 12) & ~((uint32_t)0x00FFF000)) == 0);
	REG_PL_WR(SPU_USER_5_CONF_2_ADDR, (REG_PL_RD(SPU_USER_5_CONF_2_ADDR) & ~((uint32_t)0x00FFF000)) | ((uint32_t)cwlimu5 <<12));
}
__INLINE uint16_t spu_user_5_conf_2_cw_base_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_5_CONF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void spu_user_5_conf_2_cw_base_u_5_setf(uint16_t cwbaseu5)
{
	ASSERT_ERR((((uint32_t)cwbaseu5 << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(SPU_USER_5_CONF_2_ADDR, (REG_PL_RD(SPU_USER_5_CONF_2_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)cwbaseu5 <<0));
}

/**
 * @brief USER_6_CONF_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 RX_MOD_TYPE_U6            0x0
 *    23:12 CW_LIM_U6                 0x0
 *    11:00 CW_BASE_U6                0x0
 * </pre>
 */
#define SPU_USER_6_CONF_2_ADDR        (REG_SPU_BASE_ADDR+0x000001C8)
#define SPU_USER_6_CONF_2_OFFSET      0x000001C8
#define SPU_USER_6_CONF_2_INDEX       0x00000072
#define SPU_USER_6_CONF_2_RESET       0x00000000

__INLINE uint32_t  spu_user_6_conf_2_get(void)
{
	return REG_PL_RD(SPU_USER_6_CONF_2_ADDR);
}

__INLINE void spu_user_6_conf_2_set(uint32_t value)
{
	REG_PL_WR(SPU_USER_6_CONF_2_ADDR, value);
}

// field definitions
#define SPU_USER_6_CONF_2_RX_MOD_TYPE_U_6_MASK    ((uint32_t)0x07000000)
#define SPU_USER_6_CONF_2_RX_MOD_TYPE_U_6_LSB    24
#define SPU_USER_6_CONF_2_RX_MOD_TYPE_U_6_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_6_CONF_2_CW_LIM_U_6_MASK    ((uint32_t)0x00FFF000)
#define SPU_USER_6_CONF_2_CW_LIM_U_6_LSB    12
#define SPU_USER_6_CONF_2_CW_LIM_U_6_WIDTH    ((uint32_t)0x0000000C)
#define SPU_USER_6_CONF_2_CW_BASE_U_6_MASK    ((uint32_t)0x00000FFF)
#define SPU_USER_6_CONF_2_CW_BASE_U_6_LSB    0
#define SPU_USER_6_CONF_2_CW_BASE_U_6_WIDTH    ((uint32_t)0x0000000C)

#define SPU_USER_6_CONF_2_RX_MOD_TYPE_U_6_RST    0x0
#define SPU_USER_6_CONF_2_CW_LIM_U_6_RST    0x0
#define SPU_USER_6_CONF_2_CW_BASE_U_6_RST    0x0

__INLINE void spu_user_6_conf_2_pack(uint8_t rx_mod_type_u6, uint16_t cw_lim_u6, uint16_t cw_base_u6)
{
	ASSERT_ERR((((uint32_t)rx_mod_type_u6 << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)cw_lim_u6 << 12) & ~((uint32_t)0x00FFF000)) == 0);
	ASSERT_ERR((((uint32_t)cw_base_u6 << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(SPU_USER_6_CONF_2_ADDR,  ((uint32_t)rx_mod_type_u6 << 24) |((uint32_t)cw_lim_u6 << 12) |((uint32_t)cw_base_u6 << 0));
}

__INLINE void spu_user_6_conf_2_unpack(uint8_t* rx_mod_type_u6, uint16_t* cw_lim_u6, uint16_t* cw_base_u6)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_6_CONF_2_ADDR);

	*rx_mod_type_u6 = (localVal & ((uint32_t)0x07000000)) >>  24;
	*cw_lim_u6 = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*cw_base_u6 = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t spu_user_6_conf_2_rx_mod_type_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_6_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void spu_user_6_conf_2_rx_mod_type_u_6_setf(uint8_t rxmodtypeu6)
{
	ASSERT_ERR((((uint32_t)rxmodtypeu6 << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SPU_USER_6_CONF_2_ADDR, (REG_PL_RD(SPU_USER_6_CONF_2_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)rxmodtypeu6 <<24));
}
__INLINE uint16_t spu_user_6_conf_2_cw_lim_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_6_CONF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE void spu_user_6_conf_2_cw_lim_u_6_setf(uint16_t cwlimu6)
{
	ASSERT_ERR((((uint32_t)cwlimu6 << 12) & ~((uint32_t)0x00FFF000)) == 0);
	REG_PL_WR(SPU_USER_6_CONF_2_ADDR, (REG_PL_RD(SPU_USER_6_CONF_2_ADDR) & ~((uint32_t)0x00FFF000)) | ((uint32_t)cwlimu6 <<12));
}
__INLINE uint16_t spu_user_6_conf_2_cw_base_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_6_CONF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void spu_user_6_conf_2_cw_base_u_6_setf(uint16_t cwbaseu6)
{
	ASSERT_ERR((((uint32_t)cwbaseu6 << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(SPU_USER_6_CONF_2_ADDR, (REG_PL_RD(SPU_USER_6_CONF_2_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)cwbaseu6 <<0));
}

/**
 * @brief USER_7_CONF_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 RX_MOD_TYPE_U7            0x0
 *    23:12 CW_LIM_U7                 0x0
 *    11:00 CW_BASE_U7                0x0
 * </pre>
 */
#define SPU_USER_7_CONF_2_ADDR        (REG_SPU_BASE_ADDR+0x000001CC)
#define SPU_USER_7_CONF_2_OFFSET      0x000001CC
#define SPU_USER_7_CONF_2_INDEX       0x00000073
#define SPU_USER_7_CONF_2_RESET       0x00000000

__INLINE uint32_t  spu_user_7_conf_2_get(void)
{
	return REG_PL_RD(SPU_USER_7_CONF_2_ADDR);
}

__INLINE void spu_user_7_conf_2_set(uint32_t value)
{
	REG_PL_WR(SPU_USER_7_CONF_2_ADDR, value);
}

// field definitions
#define SPU_USER_7_CONF_2_RX_MOD_TYPE_U_7_MASK    ((uint32_t)0x07000000)
#define SPU_USER_7_CONF_2_RX_MOD_TYPE_U_7_LSB    24
#define SPU_USER_7_CONF_2_RX_MOD_TYPE_U_7_WIDTH    ((uint32_t)0x00000003)
#define SPU_USER_7_CONF_2_CW_LIM_U_7_MASK    ((uint32_t)0x00FFF000)
#define SPU_USER_7_CONF_2_CW_LIM_U_7_LSB    12
#define SPU_USER_7_CONF_2_CW_LIM_U_7_WIDTH    ((uint32_t)0x0000000C)
#define SPU_USER_7_CONF_2_CW_BASE_U_7_MASK    ((uint32_t)0x00000FFF)
#define SPU_USER_7_CONF_2_CW_BASE_U_7_LSB    0
#define SPU_USER_7_CONF_2_CW_BASE_U_7_WIDTH    ((uint32_t)0x0000000C)

#define SPU_USER_7_CONF_2_RX_MOD_TYPE_U_7_RST    0x0
#define SPU_USER_7_CONF_2_CW_LIM_U_7_RST    0x0
#define SPU_USER_7_CONF_2_CW_BASE_U_7_RST    0x0

__INLINE void spu_user_7_conf_2_pack(uint8_t rx_mod_type_u7, uint16_t cw_lim_u7, uint16_t cw_base_u7)
{
	ASSERT_ERR((((uint32_t)rx_mod_type_u7 << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)cw_lim_u7 << 12) & ~((uint32_t)0x00FFF000)) == 0);
	ASSERT_ERR((((uint32_t)cw_base_u7 << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(SPU_USER_7_CONF_2_ADDR,  ((uint32_t)rx_mod_type_u7 << 24) |((uint32_t)cw_lim_u7 << 12) |((uint32_t)cw_base_u7 << 0));
}

__INLINE void spu_user_7_conf_2_unpack(uint8_t* rx_mod_type_u7, uint16_t* cw_lim_u7, uint16_t* cw_base_u7)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_7_CONF_2_ADDR);

	*rx_mod_type_u7 = (localVal & ((uint32_t)0x07000000)) >>  24;
	*cw_lim_u7 = (localVal & ((uint32_t)0x00FFF000)) >>  12;
	*cw_base_u7 = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t spu_user_7_conf_2_rx_mod_type_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_7_CONF_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE void spu_user_7_conf_2_rx_mod_type_u_7_setf(uint8_t rxmodtypeu7)
{
	ASSERT_ERR((((uint32_t)rxmodtypeu7 << 24) & ~((uint32_t)0x07000000)) == 0);
	REG_PL_WR(SPU_USER_7_CONF_2_ADDR, (REG_PL_RD(SPU_USER_7_CONF_2_ADDR) & ~((uint32_t)0x07000000)) | ((uint32_t)rxmodtypeu7 <<24));
}
__INLINE uint16_t spu_user_7_conf_2_cw_lim_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_7_CONF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00FFF000)) >> 12);
}
__INLINE void spu_user_7_conf_2_cw_lim_u_7_setf(uint16_t cwlimu7)
{
	ASSERT_ERR((((uint32_t)cwlimu7 << 12) & ~((uint32_t)0x00FFF000)) == 0);
	REG_PL_WR(SPU_USER_7_CONF_2_ADDR, (REG_PL_RD(SPU_USER_7_CONF_2_ADDR) & ~((uint32_t)0x00FFF000)) | ((uint32_t)cwlimu7 <<12));
}
__INLINE uint16_t spu_user_7_conf_2_cw_base_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_USER_7_CONF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
__INLINE void spu_user_7_conf_2_cw_base_u_7_setf(uint16_t cwbaseu7)
{
	ASSERT_ERR((((uint32_t)cwbaseu7 << 0) & ~((uint32_t)0x00000FFF)) == 0);
	REG_PL_WR(SPU_USER_7_CONF_2_ADDR, (REG_PL_RD(SPU_USER_7_CONF_2_ADDR) & ~((uint32_t)0x00000FFF)) | ((uint32_t)cwbaseu7 <<0));
}

/**
 * @brief RX_ROT_CPE_STO_U_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_ROT_CPE_U0             0x0
 *    15:00 RX_ROT_STO_U0             0x0
 * </pre>
 */
#define SPU_RX_ROT_CPE_STO_U_0_ADDR        (REG_SPU_BASE_ADDR+0x00000300)
#define SPU_RX_ROT_CPE_STO_U_0_OFFSET      0x00000300
#define SPU_RX_ROT_CPE_STO_U_0_INDEX       0x000000C0
#define SPU_RX_ROT_CPE_STO_U_0_RESET       0x00000000

__INLINE uint32_t  spu_rx_rot_cpe_sto_u_0_get(void)
{
	return REG_PL_RD(SPU_RX_ROT_CPE_STO_U_0_ADDR);
}

__INLINE void spu_rx_rot_cpe_sto_u_0_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_0_ADDR, value);
}

// field definitions
#define SPU_RX_ROT_CPE_STO_U_0_RX_ROT_CPE_U_0_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_ROT_CPE_STO_U_0_RX_ROT_CPE_U_0_LSB    16
#define SPU_RX_ROT_CPE_STO_U_0_RX_ROT_CPE_U_0_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_ROT_CPE_STO_U_0_RX_ROT_STO_U_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_ROT_CPE_STO_U_0_RX_ROT_STO_U_0_LSB    0
#define SPU_RX_ROT_CPE_STO_U_0_RX_ROT_STO_U_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_ROT_CPE_STO_U_0_RX_ROT_CPE_U_0_RST    0x0
#define SPU_RX_ROT_CPE_STO_U_0_RX_ROT_STO_U_0_RST    0x0

__INLINE void spu_rx_rot_cpe_sto_u_0_pack(uint16_t rx_rot_cpe_u0, uint16_t rx_rot_sto_u0)
{
	ASSERT_ERR((((uint32_t)rx_rot_cpe_u0 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_sto_u0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_0_ADDR,  ((uint32_t)rx_rot_cpe_u0 << 16) |((uint32_t)rx_rot_sto_u0 << 0));
}

__INLINE void spu_rx_rot_cpe_sto_u_0_unpack(uint16_t* rx_rot_cpe_u0, uint16_t* rx_rot_sto_u0)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_0_ADDR);

	*rx_rot_cpe_u0 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_rot_sto_u0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_rot_cpe_sto_u_0_rx_rot_cpe_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_rot_cpe_sto_u_0_rx_rot_cpe_u_0_setf(uint16_t rxrotcpeu0)
{
	ASSERT_ERR((((uint32_t)rxrotcpeu0 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_0_ADDR, (REG_PL_RD(SPU_RX_ROT_CPE_STO_U_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxrotcpeu0 <<16));
}
__INLINE uint16_t spu_rx_rot_cpe_sto_u_0_rx_rot_sto_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_rot_cpe_sto_u_0_rx_rot_sto_u_0_setf(uint16_t rxrotstou0)
{
	ASSERT_ERR((((uint32_t)rxrotstou0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_0_ADDR, (REG_PL_RD(SPU_RX_ROT_CPE_STO_U_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxrotstou0 <<0));
}

/**
 * @brief RX_ROT_CPE_STO_U_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_ROT_CPE_U1             0x0
 *    15:00 RX_ROT_STO_U1             0x0
 * </pre>
 */
#define SPU_RX_ROT_CPE_STO_U_1_ADDR        (REG_SPU_BASE_ADDR+0x00000304)
#define SPU_RX_ROT_CPE_STO_U_1_OFFSET      0x00000304
#define SPU_RX_ROT_CPE_STO_U_1_INDEX       0x000000C1
#define SPU_RX_ROT_CPE_STO_U_1_RESET       0x00000000

__INLINE uint32_t  spu_rx_rot_cpe_sto_u_1_get(void)
{
	return REG_PL_RD(SPU_RX_ROT_CPE_STO_U_1_ADDR);
}

__INLINE void spu_rx_rot_cpe_sto_u_1_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_1_ADDR, value);
}

// field definitions
#define SPU_RX_ROT_CPE_STO_U_1_RX_ROT_CPE_U_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_ROT_CPE_STO_U_1_RX_ROT_CPE_U_1_LSB    16
#define SPU_RX_ROT_CPE_STO_U_1_RX_ROT_CPE_U_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_ROT_CPE_STO_U_1_RX_ROT_STO_U_1_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_ROT_CPE_STO_U_1_RX_ROT_STO_U_1_LSB    0
#define SPU_RX_ROT_CPE_STO_U_1_RX_ROT_STO_U_1_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_ROT_CPE_STO_U_1_RX_ROT_CPE_U_1_RST    0x0
#define SPU_RX_ROT_CPE_STO_U_1_RX_ROT_STO_U_1_RST    0x0

__INLINE void spu_rx_rot_cpe_sto_u_1_pack(uint16_t rx_rot_cpe_u1, uint16_t rx_rot_sto_u1)
{
	ASSERT_ERR((((uint32_t)rx_rot_cpe_u1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_sto_u1 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_1_ADDR,  ((uint32_t)rx_rot_cpe_u1 << 16) |((uint32_t)rx_rot_sto_u1 << 0));
}

__INLINE void spu_rx_rot_cpe_sto_u_1_unpack(uint16_t* rx_rot_cpe_u1, uint16_t* rx_rot_sto_u1)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_1_ADDR);

	*rx_rot_cpe_u1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_rot_sto_u1 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_rot_cpe_sto_u_1_rx_rot_cpe_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_rot_cpe_sto_u_1_rx_rot_cpe_u_1_setf(uint16_t rxrotcpeu1)
{
	ASSERT_ERR((((uint32_t)rxrotcpeu1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_1_ADDR, (REG_PL_RD(SPU_RX_ROT_CPE_STO_U_1_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxrotcpeu1 <<16));
}
__INLINE uint16_t spu_rx_rot_cpe_sto_u_1_rx_rot_sto_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_rot_cpe_sto_u_1_rx_rot_sto_u_1_setf(uint16_t rxrotstou1)
{
	ASSERT_ERR((((uint32_t)rxrotstou1 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_1_ADDR, (REG_PL_RD(SPU_RX_ROT_CPE_STO_U_1_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxrotstou1 <<0));
}

/**
 * @brief RX_ROT_CPE_STO_U_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_ROT_CPE_U2             0x0
 *    15:00 RX_ROT_STO_U2             0x0
 * </pre>
 */
#define SPU_RX_ROT_CPE_STO_U_2_ADDR        (REG_SPU_BASE_ADDR+0x00000308)
#define SPU_RX_ROT_CPE_STO_U_2_OFFSET      0x00000308
#define SPU_RX_ROT_CPE_STO_U_2_INDEX       0x000000C2
#define SPU_RX_ROT_CPE_STO_U_2_RESET       0x00000000

__INLINE uint32_t  spu_rx_rot_cpe_sto_u_2_get(void)
{
	return REG_PL_RD(SPU_RX_ROT_CPE_STO_U_2_ADDR);
}

__INLINE void spu_rx_rot_cpe_sto_u_2_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_2_ADDR, value);
}

// field definitions
#define SPU_RX_ROT_CPE_STO_U_2_RX_ROT_CPE_U_2_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_ROT_CPE_STO_U_2_RX_ROT_CPE_U_2_LSB    16
#define SPU_RX_ROT_CPE_STO_U_2_RX_ROT_CPE_U_2_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_ROT_CPE_STO_U_2_RX_ROT_STO_U_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_ROT_CPE_STO_U_2_RX_ROT_STO_U_2_LSB    0
#define SPU_RX_ROT_CPE_STO_U_2_RX_ROT_STO_U_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_ROT_CPE_STO_U_2_RX_ROT_CPE_U_2_RST    0x0
#define SPU_RX_ROT_CPE_STO_U_2_RX_ROT_STO_U_2_RST    0x0

__INLINE void spu_rx_rot_cpe_sto_u_2_pack(uint16_t rx_rot_cpe_u2, uint16_t rx_rot_sto_u2)
{
	ASSERT_ERR((((uint32_t)rx_rot_cpe_u2 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_sto_u2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_2_ADDR,  ((uint32_t)rx_rot_cpe_u2 << 16) |((uint32_t)rx_rot_sto_u2 << 0));
}

__INLINE void spu_rx_rot_cpe_sto_u_2_unpack(uint16_t* rx_rot_cpe_u2, uint16_t* rx_rot_sto_u2)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_2_ADDR);

	*rx_rot_cpe_u2 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_rot_sto_u2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_rot_cpe_sto_u_2_rx_rot_cpe_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_rot_cpe_sto_u_2_rx_rot_cpe_u_2_setf(uint16_t rxrotcpeu2)
{
	ASSERT_ERR((((uint32_t)rxrotcpeu2 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_2_ADDR, (REG_PL_RD(SPU_RX_ROT_CPE_STO_U_2_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxrotcpeu2 <<16));
}
__INLINE uint16_t spu_rx_rot_cpe_sto_u_2_rx_rot_sto_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_rot_cpe_sto_u_2_rx_rot_sto_u_2_setf(uint16_t rxrotstou2)
{
	ASSERT_ERR((((uint32_t)rxrotstou2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_2_ADDR, (REG_PL_RD(SPU_RX_ROT_CPE_STO_U_2_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxrotstou2 <<0));
}

/**
 * @brief RX_ROT_CPE_STO_U_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_ROT_CPE_U3             0x0
 *    15:00 RX_ROT_STO_U3             0x0
 * </pre>
 */
#define SPU_RX_ROT_CPE_STO_U_3_ADDR        (REG_SPU_BASE_ADDR+0x0000030C)
#define SPU_RX_ROT_CPE_STO_U_3_OFFSET      0x0000030C
#define SPU_RX_ROT_CPE_STO_U_3_INDEX       0x000000C3
#define SPU_RX_ROT_CPE_STO_U_3_RESET       0x00000000

__INLINE uint32_t  spu_rx_rot_cpe_sto_u_3_get(void)
{
	return REG_PL_RD(SPU_RX_ROT_CPE_STO_U_3_ADDR);
}

__INLINE void spu_rx_rot_cpe_sto_u_3_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_3_ADDR, value);
}

// field definitions
#define SPU_RX_ROT_CPE_STO_U_3_RX_ROT_CPE_U_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_ROT_CPE_STO_U_3_RX_ROT_CPE_U_3_LSB    16
#define SPU_RX_ROT_CPE_STO_U_3_RX_ROT_CPE_U_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_ROT_CPE_STO_U_3_RX_ROT_STO_U_3_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_ROT_CPE_STO_U_3_RX_ROT_STO_U_3_LSB    0
#define SPU_RX_ROT_CPE_STO_U_3_RX_ROT_STO_U_3_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_ROT_CPE_STO_U_3_RX_ROT_CPE_U_3_RST    0x0
#define SPU_RX_ROT_CPE_STO_U_3_RX_ROT_STO_U_3_RST    0x0

__INLINE void spu_rx_rot_cpe_sto_u_3_pack(uint16_t rx_rot_cpe_u3, uint16_t rx_rot_sto_u3)
{
	ASSERT_ERR((((uint32_t)rx_rot_cpe_u3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_sto_u3 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_3_ADDR,  ((uint32_t)rx_rot_cpe_u3 << 16) |((uint32_t)rx_rot_sto_u3 << 0));
}

__INLINE void spu_rx_rot_cpe_sto_u_3_unpack(uint16_t* rx_rot_cpe_u3, uint16_t* rx_rot_sto_u3)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_3_ADDR);

	*rx_rot_cpe_u3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_rot_sto_u3 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_rot_cpe_sto_u_3_rx_rot_cpe_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_rot_cpe_sto_u_3_rx_rot_cpe_u_3_setf(uint16_t rxrotcpeu3)
{
	ASSERT_ERR((((uint32_t)rxrotcpeu3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_3_ADDR, (REG_PL_RD(SPU_RX_ROT_CPE_STO_U_3_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxrotcpeu3 <<16));
}
__INLINE uint16_t spu_rx_rot_cpe_sto_u_3_rx_rot_sto_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_rot_cpe_sto_u_3_rx_rot_sto_u_3_setf(uint16_t rxrotstou3)
{
	ASSERT_ERR((((uint32_t)rxrotstou3 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_3_ADDR, (REG_PL_RD(SPU_RX_ROT_CPE_STO_U_3_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxrotstou3 <<0));
}

/**
 * @brief RX_ROT_CPE_STO_U_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_ROT_CPE_U4             0x0
 *    15:00 RX_ROT_STO_U4             0x0
 * </pre>
 */
#define SPU_RX_ROT_CPE_STO_U_4_ADDR        (REG_SPU_BASE_ADDR+0x00000310)
#define SPU_RX_ROT_CPE_STO_U_4_OFFSET      0x00000310
#define SPU_RX_ROT_CPE_STO_U_4_INDEX       0x000000C4
#define SPU_RX_ROT_CPE_STO_U_4_RESET       0x00000000

__INLINE uint32_t  spu_rx_rot_cpe_sto_u_4_get(void)
{
	return REG_PL_RD(SPU_RX_ROT_CPE_STO_U_4_ADDR);
}

__INLINE void spu_rx_rot_cpe_sto_u_4_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_4_ADDR, value);
}

// field definitions
#define SPU_RX_ROT_CPE_STO_U_4_RX_ROT_CPE_U_4_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_ROT_CPE_STO_U_4_RX_ROT_CPE_U_4_LSB    16
#define SPU_RX_ROT_CPE_STO_U_4_RX_ROT_CPE_U_4_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_ROT_CPE_STO_U_4_RX_ROT_STO_U_4_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_ROT_CPE_STO_U_4_RX_ROT_STO_U_4_LSB    0
#define SPU_RX_ROT_CPE_STO_U_4_RX_ROT_STO_U_4_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_ROT_CPE_STO_U_4_RX_ROT_CPE_U_4_RST    0x0
#define SPU_RX_ROT_CPE_STO_U_4_RX_ROT_STO_U_4_RST    0x0

__INLINE void spu_rx_rot_cpe_sto_u_4_pack(uint16_t rx_rot_cpe_u4, uint16_t rx_rot_sto_u4)
{
	ASSERT_ERR((((uint32_t)rx_rot_cpe_u4 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_sto_u4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_4_ADDR,  ((uint32_t)rx_rot_cpe_u4 << 16) |((uint32_t)rx_rot_sto_u4 << 0));
}

__INLINE void spu_rx_rot_cpe_sto_u_4_unpack(uint16_t* rx_rot_cpe_u4, uint16_t* rx_rot_sto_u4)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_4_ADDR);

	*rx_rot_cpe_u4 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_rot_sto_u4 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_rot_cpe_sto_u_4_rx_rot_cpe_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_4_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_rot_cpe_sto_u_4_rx_rot_cpe_u_4_setf(uint16_t rxrotcpeu4)
{
	ASSERT_ERR((((uint32_t)rxrotcpeu4 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_4_ADDR, (REG_PL_RD(SPU_RX_ROT_CPE_STO_U_4_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxrotcpeu4 <<16));
}
__INLINE uint16_t spu_rx_rot_cpe_sto_u_4_rx_rot_sto_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_4_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_rot_cpe_sto_u_4_rx_rot_sto_u_4_setf(uint16_t rxrotstou4)
{
	ASSERT_ERR((((uint32_t)rxrotstou4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_4_ADDR, (REG_PL_RD(SPU_RX_ROT_CPE_STO_U_4_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxrotstou4 <<0));
}

/**
 * @brief RX_ROT_CPE_STO_U_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_ROT_CPE_U5             0x0
 *    15:00 RX_ROT_STO_U5             0x0
 * </pre>
 */
#define SPU_RX_ROT_CPE_STO_U_5_ADDR        (REG_SPU_BASE_ADDR+0x00000314)
#define SPU_RX_ROT_CPE_STO_U_5_OFFSET      0x00000314
#define SPU_RX_ROT_CPE_STO_U_5_INDEX       0x000000C5
#define SPU_RX_ROT_CPE_STO_U_5_RESET       0x00000000

__INLINE uint32_t  spu_rx_rot_cpe_sto_u_5_get(void)
{
	return REG_PL_RD(SPU_RX_ROT_CPE_STO_U_5_ADDR);
}

__INLINE void spu_rx_rot_cpe_sto_u_5_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_5_ADDR, value);
}

// field definitions
#define SPU_RX_ROT_CPE_STO_U_5_RX_ROT_CPE_U_5_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_ROT_CPE_STO_U_5_RX_ROT_CPE_U_5_LSB    16
#define SPU_RX_ROT_CPE_STO_U_5_RX_ROT_CPE_U_5_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_ROT_CPE_STO_U_5_RX_ROT_STO_U_5_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_ROT_CPE_STO_U_5_RX_ROT_STO_U_5_LSB    0
#define SPU_RX_ROT_CPE_STO_U_5_RX_ROT_STO_U_5_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_ROT_CPE_STO_U_5_RX_ROT_CPE_U_5_RST    0x0
#define SPU_RX_ROT_CPE_STO_U_5_RX_ROT_STO_U_5_RST    0x0

__INLINE void spu_rx_rot_cpe_sto_u_5_pack(uint16_t rx_rot_cpe_u5, uint16_t rx_rot_sto_u5)
{
	ASSERT_ERR((((uint32_t)rx_rot_cpe_u5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_sto_u5 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_5_ADDR,  ((uint32_t)rx_rot_cpe_u5 << 16) |((uint32_t)rx_rot_sto_u5 << 0));
}

__INLINE void spu_rx_rot_cpe_sto_u_5_unpack(uint16_t* rx_rot_cpe_u5, uint16_t* rx_rot_sto_u5)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_5_ADDR);

	*rx_rot_cpe_u5 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_rot_sto_u5 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_rot_cpe_sto_u_5_rx_rot_cpe_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_5_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_rot_cpe_sto_u_5_rx_rot_cpe_u_5_setf(uint16_t rxrotcpeu5)
{
	ASSERT_ERR((((uint32_t)rxrotcpeu5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_5_ADDR, (REG_PL_RD(SPU_RX_ROT_CPE_STO_U_5_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxrotcpeu5 <<16));
}
__INLINE uint16_t spu_rx_rot_cpe_sto_u_5_rx_rot_sto_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_5_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_rot_cpe_sto_u_5_rx_rot_sto_u_5_setf(uint16_t rxrotstou5)
{
	ASSERT_ERR((((uint32_t)rxrotstou5 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_5_ADDR, (REG_PL_RD(SPU_RX_ROT_CPE_STO_U_5_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxrotstou5 <<0));
}

/**
 * @brief RX_ROT_CPE_STO_U_6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_ROT_CPE_U6             0x0
 *    15:00 RX_ROT_STO_U6             0x0
 * </pre>
 */
#define SPU_RX_ROT_CPE_STO_U_6_ADDR        (REG_SPU_BASE_ADDR+0x00000318)
#define SPU_RX_ROT_CPE_STO_U_6_OFFSET      0x00000318
#define SPU_RX_ROT_CPE_STO_U_6_INDEX       0x000000C6
#define SPU_RX_ROT_CPE_STO_U_6_RESET       0x00000000

__INLINE uint32_t  spu_rx_rot_cpe_sto_u_6_get(void)
{
	return REG_PL_RD(SPU_RX_ROT_CPE_STO_U_6_ADDR);
}

__INLINE void spu_rx_rot_cpe_sto_u_6_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_6_ADDR, value);
}

// field definitions
#define SPU_RX_ROT_CPE_STO_U_6_RX_ROT_CPE_U_6_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_ROT_CPE_STO_U_6_RX_ROT_CPE_U_6_LSB    16
#define SPU_RX_ROT_CPE_STO_U_6_RX_ROT_CPE_U_6_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_ROT_CPE_STO_U_6_RX_ROT_STO_U_6_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_ROT_CPE_STO_U_6_RX_ROT_STO_U_6_LSB    0
#define SPU_RX_ROT_CPE_STO_U_6_RX_ROT_STO_U_6_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_ROT_CPE_STO_U_6_RX_ROT_CPE_U_6_RST    0x0
#define SPU_RX_ROT_CPE_STO_U_6_RX_ROT_STO_U_6_RST    0x0

__INLINE void spu_rx_rot_cpe_sto_u_6_pack(uint16_t rx_rot_cpe_u6, uint16_t rx_rot_sto_u6)
{
	ASSERT_ERR((((uint32_t)rx_rot_cpe_u6 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_sto_u6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_6_ADDR,  ((uint32_t)rx_rot_cpe_u6 << 16) |((uint32_t)rx_rot_sto_u6 << 0));
}

__INLINE void spu_rx_rot_cpe_sto_u_6_unpack(uint16_t* rx_rot_cpe_u6, uint16_t* rx_rot_sto_u6)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_6_ADDR);

	*rx_rot_cpe_u6 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_rot_sto_u6 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_rot_cpe_sto_u_6_rx_rot_cpe_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_6_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_rot_cpe_sto_u_6_rx_rot_cpe_u_6_setf(uint16_t rxrotcpeu6)
{
	ASSERT_ERR((((uint32_t)rxrotcpeu6 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_6_ADDR, (REG_PL_RD(SPU_RX_ROT_CPE_STO_U_6_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxrotcpeu6 <<16));
}
__INLINE uint16_t spu_rx_rot_cpe_sto_u_6_rx_rot_sto_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_6_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_rot_cpe_sto_u_6_rx_rot_sto_u_6_setf(uint16_t rxrotstou6)
{
	ASSERT_ERR((((uint32_t)rxrotstou6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_6_ADDR, (REG_PL_RD(SPU_RX_ROT_CPE_STO_U_6_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxrotstou6 <<0));
}

/**
 * @brief RX_ROT_CPE_STO_U_7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_ROT_CPE_U7             0x0
 *    15:00 RX_ROT_STO_U7             0x0
 * </pre>
 */
#define SPU_RX_ROT_CPE_STO_U_7_ADDR        (REG_SPU_BASE_ADDR+0x0000031C)
#define SPU_RX_ROT_CPE_STO_U_7_OFFSET      0x0000031C
#define SPU_RX_ROT_CPE_STO_U_7_INDEX       0x000000C7
#define SPU_RX_ROT_CPE_STO_U_7_RESET       0x00000000

__INLINE uint32_t  spu_rx_rot_cpe_sto_u_7_get(void)
{
	return REG_PL_RD(SPU_RX_ROT_CPE_STO_U_7_ADDR);
}

__INLINE void spu_rx_rot_cpe_sto_u_7_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_7_ADDR, value);
}

// field definitions
#define SPU_RX_ROT_CPE_STO_U_7_RX_ROT_CPE_U_7_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_ROT_CPE_STO_U_7_RX_ROT_CPE_U_7_LSB    16
#define SPU_RX_ROT_CPE_STO_U_7_RX_ROT_CPE_U_7_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_ROT_CPE_STO_U_7_RX_ROT_STO_U_7_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_ROT_CPE_STO_U_7_RX_ROT_STO_U_7_LSB    0
#define SPU_RX_ROT_CPE_STO_U_7_RX_ROT_STO_U_7_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_ROT_CPE_STO_U_7_RX_ROT_CPE_U_7_RST    0x0
#define SPU_RX_ROT_CPE_STO_U_7_RX_ROT_STO_U_7_RST    0x0

__INLINE void spu_rx_rot_cpe_sto_u_7_pack(uint16_t rx_rot_cpe_u7, uint16_t rx_rot_sto_u7)
{
	ASSERT_ERR((((uint32_t)rx_rot_cpe_u7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_sto_u7 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_7_ADDR,  ((uint32_t)rx_rot_cpe_u7 << 16) |((uint32_t)rx_rot_sto_u7 << 0));
}

__INLINE void spu_rx_rot_cpe_sto_u_7_unpack(uint16_t* rx_rot_cpe_u7, uint16_t* rx_rot_sto_u7)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_7_ADDR);

	*rx_rot_cpe_u7 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_rot_sto_u7 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_rot_cpe_sto_u_7_rx_rot_cpe_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_7_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_rot_cpe_sto_u_7_rx_rot_cpe_u_7_setf(uint16_t rxrotcpeu7)
{
	ASSERT_ERR((((uint32_t)rxrotcpeu7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_7_ADDR, (REG_PL_RD(SPU_RX_ROT_CPE_STO_U_7_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxrotcpeu7 <<16));
}
__INLINE uint16_t spu_rx_rot_cpe_sto_u_7_rx_rot_sto_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CPE_STO_U_7_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_rot_cpe_sto_u_7_rx_rot_sto_u_7_setf(uint16_t rxrotstou7)
{
	ASSERT_ERR((((uint32_t)rxrotstou7 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CPE_STO_U_7_ADDR, (REG_PL_RD(SPU_RX_ROT_CPE_STO_U_7_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxrotstou7 <<0));
}

/**
 * @brief RX_ROT_CSD_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_ROT_CSD_SS1            0x0
 *    15:00 RX_ROT_CSD_SS0            0x0
 * </pre>
 */
#define SPU_RX_ROT_CSD_0_ADDR        (REG_SPU_BASE_ADDR+0x00000320)
#define SPU_RX_ROT_CSD_0_OFFSET      0x00000320
#define SPU_RX_ROT_CSD_0_INDEX       0x000000C8
#define SPU_RX_ROT_CSD_0_RESET       0x00000000

__INLINE uint32_t  spu_rx_rot_csd_0_get(void)
{
	return REG_PL_RD(SPU_RX_ROT_CSD_0_ADDR);
}

__INLINE void spu_rx_rot_csd_0_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_ROT_CSD_0_ADDR, value);
}

// field definitions
#define SPU_RX_ROT_CSD_0_RX_ROT_CSD_SS_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_ROT_CSD_0_RX_ROT_CSD_SS_1_LSB    16
#define SPU_RX_ROT_CSD_0_RX_ROT_CSD_SS_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_ROT_CSD_0_RX_ROT_CSD_SS_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_ROT_CSD_0_RX_ROT_CSD_SS_0_LSB    0
#define SPU_RX_ROT_CSD_0_RX_ROT_CSD_SS_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_ROT_CSD_0_RX_ROT_CSD_SS_1_RST    0x0
#define SPU_RX_ROT_CSD_0_RX_ROT_CSD_SS_0_RST    0x0

__INLINE void spu_rx_rot_csd_0_pack(uint16_t rx_rot_csd_ss1, uint16_t rx_rot_csd_ss0)
{
	ASSERT_ERR((((uint32_t)rx_rot_csd_ss1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_csd_ss0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CSD_0_ADDR,  ((uint32_t)rx_rot_csd_ss1 << 16) |((uint32_t)rx_rot_csd_ss0 << 0));
}

__INLINE void spu_rx_rot_csd_0_unpack(uint16_t* rx_rot_csd_ss1, uint16_t* rx_rot_csd_ss0)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CSD_0_ADDR);

	*rx_rot_csd_ss1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_rot_csd_ss0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_rot_csd_0_rx_rot_csd_ss_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CSD_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_rot_csd_0_rx_rot_csd_ss_1_setf(uint16_t rxrotcsdss1)
{
	ASSERT_ERR((((uint32_t)rxrotcsdss1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_ROT_CSD_0_ADDR, (REG_PL_RD(SPU_RX_ROT_CSD_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxrotcsdss1 <<16));
}
__INLINE uint16_t spu_rx_rot_csd_0_rx_rot_csd_ss_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CSD_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_rot_csd_0_rx_rot_csd_ss_0_setf(uint16_t rxrotcsdss0)
{
	ASSERT_ERR((((uint32_t)rxrotcsdss0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CSD_0_ADDR, (REG_PL_RD(SPU_RX_ROT_CSD_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxrotcsdss0 <<0));
}

/**
 * @brief RX_ROT_CSD_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_ROT_CSD_SS3            0x0
 *    15:00 RX_ROT_CSD_SS2            0x0
 * </pre>
 */
#define SPU_RX_ROT_CSD_1_ADDR        (REG_SPU_BASE_ADDR+0x00000324)
#define SPU_RX_ROT_CSD_1_OFFSET      0x00000324
#define SPU_RX_ROT_CSD_1_INDEX       0x000000C9
#define SPU_RX_ROT_CSD_1_RESET       0x00000000

__INLINE uint32_t  spu_rx_rot_csd_1_get(void)
{
	return REG_PL_RD(SPU_RX_ROT_CSD_1_ADDR);
}

__INLINE void spu_rx_rot_csd_1_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_ROT_CSD_1_ADDR, value);
}

// field definitions
#define SPU_RX_ROT_CSD_1_RX_ROT_CSD_SS_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_ROT_CSD_1_RX_ROT_CSD_SS_3_LSB    16
#define SPU_RX_ROT_CSD_1_RX_ROT_CSD_SS_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_ROT_CSD_1_RX_ROT_CSD_SS_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_ROT_CSD_1_RX_ROT_CSD_SS_2_LSB    0
#define SPU_RX_ROT_CSD_1_RX_ROT_CSD_SS_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_ROT_CSD_1_RX_ROT_CSD_SS_3_RST    0x0
#define SPU_RX_ROT_CSD_1_RX_ROT_CSD_SS_2_RST    0x0

__INLINE void spu_rx_rot_csd_1_pack(uint16_t rx_rot_csd_ss3, uint16_t rx_rot_csd_ss2)
{
	ASSERT_ERR((((uint32_t)rx_rot_csd_ss3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_csd_ss2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CSD_1_ADDR,  ((uint32_t)rx_rot_csd_ss3 << 16) |((uint32_t)rx_rot_csd_ss2 << 0));
}

__INLINE void spu_rx_rot_csd_1_unpack(uint16_t* rx_rot_csd_ss3, uint16_t* rx_rot_csd_ss2)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CSD_1_ADDR);

	*rx_rot_csd_ss3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_rot_csd_ss2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_rot_csd_1_rx_rot_csd_ss_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CSD_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_rot_csd_1_rx_rot_csd_ss_3_setf(uint16_t rxrotcsdss3)
{
	ASSERT_ERR((((uint32_t)rxrotcsdss3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_ROT_CSD_1_ADDR, (REG_PL_RD(SPU_RX_ROT_CSD_1_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxrotcsdss3 <<16));
}
__INLINE uint16_t spu_rx_rot_csd_1_rx_rot_csd_ss_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CSD_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_rot_csd_1_rx_rot_csd_ss_2_setf(uint16_t rxrotcsdss2)
{
	ASSERT_ERR((((uint32_t)rxrotcsdss2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CSD_1_ADDR, (REG_PL_RD(SPU_RX_ROT_CSD_1_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxrotcsdss2 <<0));
}

/**
 * @brief RX_ROT_CSD_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_ROT_CSD_SS5            0x0
 *    15:00 RX_ROT_CSD_SS4            0x0
 * </pre>
 */
#define SPU_RX_ROT_CSD_2_ADDR        (REG_SPU_BASE_ADDR+0x00000328)
#define SPU_RX_ROT_CSD_2_OFFSET      0x00000328
#define SPU_RX_ROT_CSD_2_INDEX       0x000000CA
#define SPU_RX_ROT_CSD_2_RESET       0x00000000

__INLINE uint32_t  spu_rx_rot_csd_2_get(void)
{
	return REG_PL_RD(SPU_RX_ROT_CSD_2_ADDR);
}

__INLINE void spu_rx_rot_csd_2_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_ROT_CSD_2_ADDR, value);
}

// field definitions
#define SPU_RX_ROT_CSD_2_RX_ROT_CSD_SS_5_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_ROT_CSD_2_RX_ROT_CSD_SS_5_LSB    16
#define SPU_RX_ROT_CSD_2_RX_ROT_CSD_SS_5_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_ROT_CSD_2_RX_ROT_CSD_SS_4_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_ROT_CSD_2_RX_ROT_CSD_SS_4_LSB    0
#define SPU_RX_ROT_CSD_2_RX_ROT_CSD_SS_4_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_ROT_CSD_2_RX_ROT_CSD_SS_5_RST    0x0
#define SPU_RX_ROT_CSD_2_RX_ROT_CSD_SS_4_RST    0x0

__INLINE void spu_rx_rot_csd_2_pack(uint16_t rx_rot_csd_ss5, uint16_t rx_rot_csd_ss4)
{
	ASSERT_ERR((((uint32_t)rx_rot_csd_ss5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_csd_ss4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CSD_2_ADDR,  ((uint32_t)rx_rot_csd_ss5 << 16) |((uint32_t)rx_rot_csd_ss4 << 0));
}

__INLINE void spu_rx_rot_csd_2_unpack(uint16_t* rx_rot_csd_ss5, uint16_t* rx_rot_csd_ss4)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CSD_2_ADDR);

	*rx_rot_csd_ss5 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_rot_csd_ss4 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_rot_csd_2_rx_rot_csd_ss_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CSD_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_rot_csd_2_rx_rot_csd_ss_5_setf(uint16_t rxrotcsdss5)
{
	ASSERT_ERR((((uint32_t)rxrotcsdss5 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_ROT_CSD_2_ADDR, (REG_PL_RD(SPU_RX_ROT_CSD_2_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxrotcsdss5 <<16));
}
__INLINE uint16_t spu_rx_rot_csd_2_rx_rot_csd_ss_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CSD_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_rot_csd_2_rx_rot_csd_ss_4_setf(uint16_t rxrotcsdss4)
{
	ASSERT_ERR((((uint32_t)rxrotcsdss4 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CSD_2_ADDR, (REG_PL_RD(SPU_RX_ROT_CSD_2_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxrotcsdss4 <<0));
}

/**
 * @brief RX_ROT_CSD_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_ROT_CSD_SS7            0x0
 *    15:00 RX_ROT_CSD_SS6            0x0
 * </pre>
 */
#define SPU_RX_ROT_CSD_3_ADDR        (REG_SPU_BASE_ADDR+0x0000032C)
#define SPU_RX_ROT_CSD_3_OFFSET      0x0000032C
#define SPU_RX_ROT_CSD_3_INDEX       0x000000CB
#define SPU_RX_ROT_CSD_3_RESET       0x00000000

__INLINE uint32_t  spu_rx_rot_csd_3_get(void)
{
	return REG_PL_RD(SPU_RX_ROT_CSD_3_ADDR);
}

__INLINE void spu_rx_rot_csd_3_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_ROT_CSD_3_ADDR, value);
}

// field definitions
#define SPU_RX_ROT_CSD_3_RX_ROT_CSD_SS_7_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_ROT_CSD_3_RX_ROT_CSD_SS_7_LSB    16
#define SPU_RX_ROT_CSD_3_RX_ROT_CSD_SS_7_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_ROT_CSD_3_RX_ROT_CSD_SS_6_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_ROT_CSD_3_RX_ROT_CSD_SS_6_LSB    0
#define SPU_RX_ROT_CSD_3_RX_ROT_CSD_SS_6_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_ROT_CSD_3_RX_ROT_CSD_SS_7_RST    0x0
#define SPU_RX_ROT_CSD_3_RX_ROT_CSD_SS_6_RST    0x0

__INLINE void spu_rx_rot_csd_3_pack(uint16_t rx_rot_csd_ss7, uint16_t rx_rot_csd_ss6)
{
	ASSERT_ERR((((uint32_t)rx_rot_csd_ss7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_csd_ss6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CSD_3_ADDR,  ((uint32_t)rx_rot_csd_ss7 << 16) |((uint32_t)rx_rot_csd_ss6 << 0));
}

__INLINE void spu_rx_rot_csd_3_unpack(uint16_t* rx_rot_csd_ss7, uint16_t* rx_rot_csd_ss6)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CSD_3_ADDR);

	*rx_rot_csd_ss7 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_rot_csd_ss6 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_rot_csd_3_rx_rot_csd_ss_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CSD_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_rot_csd_3_rx_rot_csd_ss_7_setf(uint16_t rxrotcsdss7)
{
	ASSERT_ERR((((uint32_t)rxrotcsdss7 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_ROT_CSD_3_ADDR, (REG_PL_RD(SPU_RX_ROT_CSD_3_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxrotcsdss7 <<16));
}
__INLINE uint16_t spu_rx_rot_csd_3_rx_rot_csd_ss_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_CSD_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_rot_csd_3_rx_rot_csd_ss_6_setf(uint16_t rxrotcsdss6)
{
	ASSERT_ERR((((uint32_t)rxrotcsdss6 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_ROT_CSD_3_ADDR, (REG_PL_RD(SPU_RX_ROT_CSD_3_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxrotcsdss6 <<0));
}

/**
 * @brief RX_MCS register definition
 *  Rx MCS config register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 RX_MCS_U7                 0x0
 *    27:24 RX_MCS_U6                 0x0
 *    23:20 RX_MCS_U5                 0x0
 *    19:16 RX_MCS_U4                 0x0
 *    15:12 RX_MCS_U3                 0x0
 *    11:08 RX_MCS_U2                 0x0
 *    07:04 RX_MCS_U1                 0x0
 *    03:00 RX_MCS_U0                 0x0
 * </pre>
 */
#define SPU_RX_MCS_ADDR        (REG_SPU_BASE_ADDR+0x00000330)
#define SPU_RX_MCS_OFFSET      0x00000330
#define SPU_RX_MCS_INDEX       0x000000CC
#define SPU_RX_MCS_RESET       0x00000000

__INLINE uint32_t  spu_rx_mcs_get(void)
{
	return REG_PL_RD(SPU_RX_MCS_ADDR);
}

__INLINE void spu_rx_mcs_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_MCS_ADDR, value);
}

// field definitions
#define SPU_RX_MCS_RX_MCS_U_7_MASK          ((uint32_t)0xF0000000)
#define SPU_RX_MCS_RX_MCS_U_7_LSB           28
#define SPU_RX_MCS_RX_MCS_U_7_WIDTH         ((uint32_t)0x00000004)
#define SPU_RX_MCS_RX_MCS_U_6_MASK          ((uint32_t)0x0F000000)
#define SPU_RX_MCS_RX_MCS_U_6_LSB           24
#define SPU_RX_MCS_RX_MCS_U_6_WIDTH         ((uint32_t)0x00000004)
#define SPU_RX_MCS_RX_MCS_U_5_MASK          ((uint32_t)0x00F00000)
#define SPU_RX_MCS_RX_MCS_U_5_LSB           20
#define SPU_RX_MCS_RX_MCS_U_5_WIDTH         ((uint32_t)0x00000004)
#define SPU_RX_MCS_RX_MCS_U_4_MASK          ((uint32_t)0x000F0000)
#define SPU_RX_MCS_RX_MCS_U_4_LSB           16
#define SPU_RX_MCS_RX_MCS_U_4_WIDTH         ((uint32_t)0x00000004)
#define SPU_RX_MCS_RX_MCS_U_3_MASK          ((uint32_t)0x0000F000)
#define SPU_RX_MCS_RX_MCS_U_3_LSB           12
#define SPU_RX_MCS_RX_MCS_U_3_WIDTH         ((uint32_t)0x00000004)
#define SPU_RX_MCS_RX_MCS_U_2_MASK          ((uint32_t)0x00000F00)
#define SPU_RX_MCS_RX_MCS_U_2_LSB           8
#define SPU_RX_MCS_RX_MCS_U_2_WIDTH         ((uint32_t)0x00000004)
#define SPU_RX_MCS_RX_MCS_U_1_MASK          ((uint32_t)0x000000F0)
#define SPU_RX_MCS_RX_MCS_U_1_LSB           4
#define SPU_RX_MCS_RX_MCS_U_1_WIDTH         ((uint32_t)0x00000004)
#define SPU_RX_MCS_RX_MCS_U_0_MASK          ((uint32_t)0x0000000F)
#define SPU_RX_MCS_RX_MCS_U_0_LSB           0
#define SPU_RX_MCS_RX_MCS_U_0_WIDTH         ((uint32_t)0x00000004)

#define SPU_RX_MCS_RX_MCS_U_7_RST           0x0
#define SPU_RX_MCS_RX_MCS_U_6_RST           0x0
#define SPU_RX_MCS_RX_MCS_U_5_RST           0x0
#define SPU_RX_MCS_RX_MCS_U_4_RST           0x0
#define SPU_RX_MCS_RX_MCS_U_3_RST           0x0
#define SPU_RX_MCS_RX_MCS_U_2_RST           0x0
#define SPU_RX_MCS_RX_MCS_U_1_RST           0x0
#define SPU_RX_MCS_RX_MCS_U_0_RST           0x0

__INLINE void spu_rx_mcs_pack(uint8_t rx_mcs_u7, uint8_t rx_mcs_u6, uint8_t rx_mcs_u5, uint8_t rx_mcs_u4, uint8_t rx_mcs_u3, uint8_t rx_mcs_u2, uint8_t rx_mcs_u1, uint8_t rx_mcs_u0)
{
	ASSERT_ERR((((uint32_t)rx_mcs_u7 << 28) & ~((uint32_t)0xF0000000)) == 0);
	ASSERT_ERR((((uint32_t)rx_mcs_u6 << 24) & ~((uint32_t)0x0F000000)) == 0);
	ASSERT_ERR((((uint32_t)rx_mcs_u5 << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)rx_mcs_u4 << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_mcs_u3 << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)rx_mcs_u2 << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)rx_mcs_u1 << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)rx_mcs_u0 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(SPU_RX_MCS_ADDR,  ((uint32_t)rx_mcs_u7 << 28) |((uint32_t)rx_mcs_u6 << 24) |((uint32_t)rx_mcs_u5 << 20) |((uint32_t)rx_mcs_u4 << 16) |((uint32_t)rx_mcs_u3 << 12) |((uint32_t)rx_mcs_u2 << 8) |((uint32_t)rx_mcs_u1 << 4) |((uint32_t)rx_mcs_u0 << 0));
}

__INLINE void spu_rx_mcs_unpack(uint8_t* rx_mcs_u7, uint8_t* rx_mcs_u6, uint8_t* rx_mcs_u5, uint8_t* rx_mcs_u4, uint8_t* rx_mcs_u3, uint8_t* rx_mcs_u2, uint8_t* rx_mcs_u1, uint8_t* rx_mcs_u0)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_MCS_ADDR);

	*rx_mcs_u7 = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*rx_mcs_u6 = (localVal & ((uint32_t)0x0F000000)) >>  24;
	*rx_mcs_u5 = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*rx_mcs_u4 = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*rx_mcs_u3 = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*rx_mcs_u2 = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*rx_mcs_u1 = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*rx_mcs_u0 = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t spu_rx_mcs_rx_mcs_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_MCS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE void spu_rx_mcs_rx_mcs_u_7_setf(uint8_t rxmcsu7)
{
	ASSERT_ERR((((uint32_t)rxmcsu7 << 28) & ~((uint32_t)0xF0000000)) == 0);
	REG_PL_WR(SPU_RX_MCS_ADDR, (REG_PL_RD(SPU_RX_MCS_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)rxmcsu7 <<28));
}
__INLINE uint8_t spu_rx_mcs_rx_mcs_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_MCS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0F000000)) >> 24);
}
__INLINE void spu_rx_mcs_rx_mcs_u_6_setf(uint8_t rxmcsu6)
{
	ASSERT_ERR((((uint32_t)rxmcsu6 << 24) & ~((uint32_t)0x0F000000)) == 0);
	REG_PL_WR(SPU_RX_MCS_ADDR, (REG_PL_RD(SPU_RX_MCS_ADDR) & ~((uint32_t)0x0F000000)) | ((uint32_t)rxmcsu6 <<24));
}
__INLINE uint8_t spu_rx_mcs_rx_mcs_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_MCS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void spu_rx_mcs_rx_mcs_u_5_setf(uint8_t rxmcsu5)
{
	ASSERT_ERR((((uint32_t)rxmcsu5 << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(SPU_RX_MCS_ADDR, (REG_PL_RD(SPU_RX_MCS_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)rxmcsu5 <<20));
}
__INLINE uint8_t spu_rx_mcs_rx_mcs_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_MCS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void spu_rx_mcs_rx_mcs_u_4_setf(uint8_t rxmcsu4)
{
	ASSERT_ERR((((uint32_t)rxmcsu4 << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(SPU_RX_MCS_ADDR, (REG_PL_RD(SPU_RX_MCS_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)rxmcsu4 <<16));
}
__INLINE uint8_t spu_rx_mcs_rx_mcs_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_MCS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void spu_rx_mcs_rx_mcs_u_3_setf(uint8_t rxmcsu3)
{
	ASSERT_ERR((((uint32_t)rxmcsu3 << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(SPU_RX_MCS_ADDR, (REG_PL_RD(SPU_RX_MCS_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)rxmcsu3 <<12));
}
__INLINE uint8_t spu_rx_mcs_rx_mcs_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_MCS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void spu_rx_mcs_rx_mcs_u_2_setf(uint8_t rxmcsu2)
{
	ASSERT_ERR((((uint32_t)rxmcsu2 << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(SPU_RX_MCS_ADDR, (REG_PL_RD(SPU_RX_MCS_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)rxmcsu2 <<8));
}
__INLINE uint8_t spu_rx_mcs_rx_mcs_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_MCS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void spu_rx_mcs_rx_mcs_u_1_setf(uint8_t rxmcsu1)
{
	ASSERT_ERR((((uint32_t)rxmcsu1 << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(SPU_RX_MCS_ADDR, (REG_PL_RD(SPU_RX_MCS_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)rxmcsu1 <<4));
}
__INLINE uint8_t spu_rx_mcs_rx_mcs_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_MCS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void spu_rx_mcs_rx_mcs_u_0_setf(uint8_t rxmcsu0)
{
	ASSERT_ERR((((uint32_t)rxmcsu0 << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(SPU_RX_MCS_ADDR, (REG_PL_RD(SPU_RX_MCS_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)rxmcsu0 <<0));
}

/**
 * @brief RX_GAIN_0 register definition
 *  Rx Fine Gain RU0 SS0 SS1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_GAIN_RU0_SS1           0x0
 *    15:00 RX_GAIN_RU0_SS0           0x0
 * </pre>
 */
#define SPU_RX_GAIN_0_ADDR        (REG_SPU_BASE_ADDR+0x00000340)
#define SPU_RX_GAIN_0_OFFSET      0x00000340
#define SPU_RX_GAIN_0_INDEX       0x000000D0
#define SPU_RX_GAIN_0_RESET       0x00000000

__INLINE uint32_t  spu_rx_gain_0_get(void)
{
	return REG_PL_RD(SPU_RX_GAIN_0_ADDR);
}

__INLINE void spu_rx_gain_0_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_GAIN_0_ADDR, value);
}

// field definitions
#define SPU_RX_GAIN_0_RX_GAIN_RU_0_SS_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_GAIN_0_RX_GAIN_RU_0_SS_1_LSB    16
#define SPU_RX_GAIN_0_RX_GAIN_RU_0_SS_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_GAIN_0_RX_GAIN_RU_0_SS_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_GAIN_0_RX_GAIN_RU_0_SS_0_LSB    0
#define SPU_RX_GAIN_0_RX_GAIN_RU_0_SS_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_GAIN_0_RX_GAIN_RU_0_SS_1_RST    0x0
#define SPU_RX_GAIN_0_RX_GAIN_RU_0_SS_0_RST    0x0

__INLINE void spu_rx_gain_0_pack(uint16_t rx_gain_ru0_ss1, uint16_t rx_gain_ru0_ss0)
{
	ASSERT_ERR((((uint32_t)rx_gain_ru0_ss1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_gain_ru0_ss0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_0_ADDR,  ((uint32_t)rx_gain_ru0_ss1 << 16) |((uint32_t)rx_gain_ru0_ss0 << 0));
}

__INLINE void spu_rx_gain_0_unpack(uint16_t* rx_gain_ru0_ss1, uint16_t* rx_gain_ru0_ss0)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_0_ADDR);

	*rx_gain_ru0_ss1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_gain_ru0_ss0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_gain_0_rx_gain_ru_0_ss_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_gain_0_rx_gain_ru_0_ss_1_setf(uint16_t rxgainru0ss1)
{
	ASSERT_ERR((((uint32_t)rxgainru0ss1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_GAIN_0_ADDR, (REG_PL_RD(SPU_RX_GAIN_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxgainru0ss1 <<16));
}
__INLINE uint16_t spu_rx_gain_0_rx_gain_ru_0_ss_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_gain_0_rx_gain_ru_0_ss_0_setf(uint16_t rxgainru0ss0)
{
	ASSERT_ERR((((uint32_t)rxgainru0ss0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_0_ADDR, (REG_PL_RD(SPU_RX_GAIN_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxgainru0ss0 <<0));
}

/**
 * @brief RX_GAIN_1 register definition
 *  Rx Fine Gain RU0 SS2 SS3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_GAIN_RU0_SS3           0x0
 *    15:00 RX_GAIN_RU0_SS2           0x0
 * </pre>
 */
#define SPU_RX_GAIN_1_ADDR        (REG_SPU_BASE_ADDR+0x00000344)
#define SPU_RX_GAIN_1_OFFSET      0x00000344
#define SPU_RX_GAIN_1_INDEX       0x000000D1
#define SPU_RX_GAIN_1_RESET       0x00000000

__INLINE uint32_t  spu_rx_gain_1_get(void)
{
	return REG_PL_RD(SPU_RX_GAIN_1_ADDR);
}

__INLINE void spu_rx_gain_1_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_GAIN_1_ADDR, value);
}

// field definitions
#define SPU_RX_GAIN_1_RX_GAIN_RU_0_SS_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_GAIN_1_RX_GAIN_RU_0_SS_3_LSB    16
#define SPU_RX_GAIN_1_RX_GAIN_RU_0_SS_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_GAIN_1_RX_GAIN_RU_0_SS_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_GAIN_1_RX_GAIN_RU_0_SS_2_LSB    0
#define SPU_RX_GAIN_1_RX_GAIN_RU_0_SS_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_GAIN_1_RX_GAIN_RU_0_SS_3_RST    0x0
#define SPU_RX_GAIN_1_RX_GAIN_RU_0_SS_2_RST    0x0

__INLINE void spu_rx_gain_1_pack(uint16_t rx_gain_ru0_ss3, uint16_t rx_gain_ru0_ss2)
{
	ASSERT_ERR((((uint32_t)rx_gain_ru0_ss3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_gain_ru0_ss2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_1_ADDR,  ((uint32_t)rx_gain_ru0_ss3 << 16) |((uint32_t)rx_gain_ru0_ss2 << 0));
}

__INLINE void spu_rx_gain_1_unpack(uint16_t* rx_gain_ru0_ss3, uint16_t* rx_gain_ru0_ss2)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_1_ADDR);

	*rx_gain_ru0_ss3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_gain_ru0_ss2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_gain_1_rx_gain_ru_0_ss_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_gain_1_rx_gain_ru_0_ss_3_setf(uint16_t rxgainru0ss3)
{
	ASSERT_ERR((((uint32_t)rxgainru0ss3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_GAIN_1_ADDR, (REG_PL_RD(SPU_RX_GAIN_1_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxgainru0ss3 <<16));
}
__INLINE uint16_t spu_rx_gain_1_rx_gain_ru_0_ss_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_gain_1_rx_gain_ru_0_ss_2_setf(uint16_t rxgainru0ss2)
{
	ASSERT_ERR((((uint32_t)rxgainru0ss2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_1_ADDR, (REG_PL_RD(SPU_RX_GAIN_1_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxgainru0ss2 <<0));
}

/**
 * @brief RX_GAIN_2 register definition
 *  Rx Fine Gain RU1 SS0 SS1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_GAIN_RU1_SS1           0x0
 *    15:00 RX_GAIN_RU1_SS0           0x0
 * </pre>
 */
#define SPU_RX_GAIN_2_ADDR        (REG_SPU_BASE_ADDR+0x00000348)
#define SPU_RX_GAIN_2_OFFSET      0x00000348
#define SPU_RX_GAIN_2_INDEX       0x000000D2
#define SPU_RX_GAIN_2_RESET       0x00000000

__INLINE uint32_t  spu_rx_gain_2_get(void)
{
	return REG_PL_RD(SPU_RX_GAIN_2_ADDR);
}

__INLINE void spu_rx_gain_2_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_GAIN_2_ADDR, value);
}

// field definitions
#define SPU_RX_GAIN_2_RX_GAIN_RU_1_SS_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_GAIN_2_RX_GAIN_RU_1_SS_1_LSB    16
#define SPU_RX_GAIN_2_RX_GAIN_RU_1_SS_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_GAIN_2_RX_GAIN_RU_1_SS_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_GAIN_2_RX_GAIN_RU_1_SS_0_LSB    0
#define SPU_RX_GAIN_2_RX_GAIN_RU_1_SS_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_GAIN_2_RX_GAIN_RU_1_SS_1_RST    0x0
#define SPU_RX_GAIN_2_RX_GAIN_RU_1_SS_0_RST    0x0

__INLINE void spu_rx_gain_2_pack(uint16_t rx_gain_ru1_ss1, uint16_t rx_gain_ru1_ss0)
{
	ASSERT_ERR((((uint32_t)rx_gain_ru1_ss1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_gain_ru1_ss0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_2_ADDR,  ((uint32_t)rx_gain_ru1_ss1 << 16) |((uint32_t)rx_gain_ru1_ss0 << 0));
}

__INLINE void spu_rx_gain_2_unpack(uint16_t* rx_gain_ru1_ss1, uint16_t* rx_gain_ru1_ss0)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_2_ADDR);

	*rx_gain_ru1_ss1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_gain_ru1_ss0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_gain_2_rx_gain_ru_1_ss_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_gain_2_rx_gain_ru_1_ss_1_setf(uint16_t rxgainru1ss1)
{
	ASSERT_ERR((((uint32_t)rxgainru1ss1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_GAIN_2_ADDR, (REG_PL_RD(SPU_RX_GAIN_2_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxgainru1ss1 <<16));
}
__INLINE uint16_t spu_rx_gain_2_rx_gain_ru_1_ss_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_gain_2_rx_gain_ru_1_ss_0_setf(uint16_t rxgainru1ss0)
{
	ASSERT_ERR((((uint32_t)rxgainru1ss0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_2_ADDR, (REG_PL_RD(SPU_RX_GAIN_2_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxgainru1ss0 <<0));
}

/**
 * @brief RX_GAIN_3 register definition
 *  Rx Fine Gain RU1 SS2 SS3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_GAIN_RU1_SS3           0x0
 *    15:00 RX_GAIN_RU1_SS2           0x0
 * </pre>
 */
#define SPU_RX_GAIN_3_ADDR        (REG_SPU_BASE_ADDR+0x0000034C)
#define SPU_RX_GAIN_3_OFFSET      0x0000034C
#define SPU_RX_GAIN_3_INDEX       0x000000D3
#define SPU_RX_GAIN_3_RESET       0x00000000

__INLINE uint32_t  spu_rx_gain_3_get(void)
{
	return REG_PL_RD(SPU_RX_GAIN_3_ADDR);
}

__INLINE void spu_rx_gain_3_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_GAIN_3_ADDR, value);
}

// field definitions
#define SPU_RX_GAIN_3_RX_GAIN_RU_1_SS_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_GAIN_3_RX_GAIN_RU_1_SS_3_LSB    16
#define SPU_RX_GAIN_3_RX_GAIN_RU_1_SS_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_GAIN_3_RX_GAIN_RU_1_SS_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_GAIN_3_RX_GAIN_RU_1_SS_2_LSB    0
#define SPU_RX_GAIN_3_RX_GAIN_RU_1_SS_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_GAIN_3_RX_GAIN_RU_1_SS_3_RST    0x0
#define SPU_RX_GAIN_3_RX_GAIN_RU_1_SS_2_RST    0x0

__INLINE void spu_rx_gain_3_pack(uint16_t rx_gain_ru1_ss3, uint16_t rx_gain_ru1_ss2)
{
	ASSERT_ERR((((uint32_t)rx_gain_ru1_ss3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_gain_ru1_ss2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_3_ADDR,  ((uint32_t)rx_gain_ru1_ss3 << 16) |((uint32_t)rx_gain_ru1_ss2 << 0));
}

__INLINE void spu_rx_gain_3_unpack(uint16_t* rx_gain_ru1_ss3, uint16_t* rx_gain_ru1_ss2)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_3_ADDR);

	*rx_gain_ru1_ss3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_gain_ru1_ss2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_gain_3_rx_gain_ru_1_ss_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_gain_3_rx_gain_ru_1_ss_3_setf(uint16_t rxgainru1ss3)
{
	ASSERT_ERR((((uint32_t)rxgainru1ss3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_GAIN_3_ADDR, (REG_PL_RD(SPU_RX_GAIN_3_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxgainru1ss3 <<16));
}
__INLINE uint16_t spu_rx_gain_3_rx_gain_ru_1_ss_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_gain_3_rx_gain_ru_1_ss_2_setf(uint16_t rxgainru1ss2)
{
	ASSERT_ERR((((uint32_t)rxgainru1ss2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_3_ADDR, (REG_PL_RD(SPU_RX_GAIN_3_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxgainru1ss2 <<0));
}

/**
 * @brief RX_GAIN_4 register definition
 *  Rx Fine Gain RU2 SS0 SS1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_GAIN_RU2_SS1           0x0
 *    15:00 RX_GAIN_RU2_SS0           0x0
 * </pre>
 */
#define SPU_RX_GAIN_4_ADDR        (REG_SPU_BASE_ADDR+0x00000350)
#define SPU_RX_GAIN_4_OFFSET      0x00000350
#define SPU_RX_GAIN_4_INDEX       0x000000D4
#define SPU_RX_GAIN_4_RESET       0x00000000

__INLINE uint32_t  spu_rx_gain_4_get(void)
{
	return REG_PL_RD(SPU_RX_GAIN_4_ADDR);
}

__INLINE void spu_rx_gain_4_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_GAIN_4_ADDR, value);
}

// field definitions
#define SPU_RX_GAIN_4_RX_GAIN_RU_2_SS_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_GAIN_4_RX_GAIN_RU_2_SS_1_LSB    16
#define SPU_RX_GAIN_4_RX_GAIN_RU_2_SS_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_GAIN_4_RX_GAIN_RU_2_SS_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_GAIN_4_RX_GAIN_RU_2_SS_0_LSB    0
#define SPU_RX_GAIN_4_RX_GAIN_RU_2_SS_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_GAIN_4_RX_GAIN_RU_2_SS_1_RST    0x0
#define SPU_RX_GAIN_4_RX_GAIN_RU_2_SS_0_RST    0x0

__INLINE void spu_rx_gain_4_pack(uint16_t rx_gain_ru2_ss1, uint16_t rx_gain_ru2_ss0)
{
	ASSERT_ERR((((uint32_t)rx_gain_ru2_ss1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_gain_ru2_ss0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_4_ADDR,  ((uint32_t)rx_gain_ru2_ss1 << 16) |((uint32_t)rx_gain_ru2_ss0 << 0));
}

__INLINE void spu_rx_gain_4_unpack(uint16_t* rx_gain_ru2_ss1, uint16_t* rx_gain_ru2_ss0)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_4_ADDR);

	*rx_gain_ru2_ss1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_gain_ru2_ss0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_gain_4_rx_gain_ru_2_ss_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_4_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_gain_4_rx_gain_ru_2_ss_1_setf(uint16_t rxgainru2ss1)
{
	ASSERT_ERR((((uint32_t)rxgainru2ss1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_GAIN_4_ADDR, (REG_PL_RD(SPU_RX_GAIN_4_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxgainru2ss1 <<16));
}
__INLINE uint16_t spu_rx_gain_4_rx_gain_ru_2_ss_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_4_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_gain_4_rx_gain_ru_2_ss_0_setf(uint16_t rxgainru2ss0)
{
	ASSERT_ERR((((uint32_t)rxgainru2ss0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_4_ADDR, (REG_PL_RD(SPU_RX_GAIN_4_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxgainru2ss0 <<0));
}

/**
 * @brief RX_GAIN_5 register definition
 *  Rx Fine Gain RU2 SS2 SS3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_GAIN_RU2_SS3           0x0
 *    15:00 RX_GAIN_RU2_SS2           0x0
 * </pre>
 */
#define SPU_RX_GAIN_5_ADDR        (REG_SPU_BASE_ADDR+0x00000354)
#define SPU_RX_GAIN_5_OFFSET      0x00000354
#define SPU_RX_GAIN_5_INDEX       0x000000D5
#define SPU_RX_GAIN_5_RESET       0x00000000

__INLINE uint32_t  spu_rx_gain_5_get(void)
{
	return REG_PL_RD(SPU_RX_GAIN_5_ADDR);
}

__INLINE void spu_rx_gain_5_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_GAIN_5_ADDR, value);
}

// field definitions
#define SPU_RX_GAIN_5_RX_GAIN_RU_2_SS_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_GAIN_5_RX_GAIN_RU_2_SS_3_LSB    16
#define SPU_RX_GAIN_5_RX_GAIN_RU_2_SS_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_GAIN_5_RX_GAIN_RU_2_SS_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_GAIN_5_RX_GAIN_RU_2_SS_2_LSB    0
#define SPU_RX_GAIN_5_RX_GAIN_RU_2_SS_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_GAIN_5_RX_GAIN_RU_2_SS_3_RST    0x0
#define SPU_RX_GAIN_5_RX_GAIN_RU_2_SS_2_RST    0x0

__INLINE void spu_rx_gain_5_pack(uint16_t rx_gain_ru2_ss3, uint16_t rx_gain_ru2_ss2)
{
	ASSERT_ERR((((uint32_t)rx_gain_ru2_ss3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_gain_ru2_ss2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_5_ADDR,  ((uint32_t)rx_gain_ru2_ss3 << 16) |((uint32_t)rx_gain_ru2_ss2 << 0));
}

__INLINE void spu_rx_gain_5_unpack(uint16_t* rx_gain_ru2_ss3, uint16_t* rx_gain_ru2_ss2)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_5_ADDR);

	*rx_gain_ru2_ss3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_gain_ru2_ss2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_gain_5_rx_gain_ru_2_ss_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_5_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_gain_5_rx_gain_ru_2_ss_3_setf(uint16_t rxgainru2ss3)
{
	ASSERT_ERR((((uint32_t)rxgainru2ss3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_GAIN_5_ADDR, (REG_PL_RD(SPU_RX_GAIN_5_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxgainru2ss3 <<16));
}
__INLINE uint16_t spu_rx_gain_5_rx_gain_ru_2_ss_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_5_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_gain_5_rx_gain_ru_2_ss_2_setf(uint16_t rxgainru2ss2)
{
	ASSERT_ERR((((uint32_t)rxgainru2ss2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_5_ADDR, (REG_PL_RD(SPU_RX_GAIN_5_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxgainru2ss2 <<0));
}

/**
 * @brief RX_GAIN_6 register definition
 *  Rx Fine Gain RU3 SS0 SS1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_GAIN_RU3_SS1           0x0
 *    15:00 RX_GAIN_RU3_SS0           0x0
 * </pre>
 */
#define SPU_RX_GAIN_6_ADDR        (REG_SPU_BASE_ADDR+0x00000358)
#define SPU_RX_GAIN_6_OFFSET      0x00000358
#define SPU_RX_GAIN_6_INDEX       0x000000D6
#define SPU_RX_GAIN_6_RESET       0x00000000

__INLINE uint32_t  spu_rx_gain_6_get(void)
{
	return REG_PL_RD(SPU_RX_GAIN_6_ADDR);
}

__INLINE void spu_rx_gain_6_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_GAIN_6_ADDR, value);
}

// field definitions
#define SPU_RX_GAIN_6_RX_GAIN_RU_3_SS_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_GAIN_6_RX_GAIN_RU_3_SS_1_LSB    16
#define SPU_RX_GAIN_6_RX_GAIN_RU_3_SS_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_GAIN_6_RX_GAIN_RU_3_SS_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_GAIN_6_RX_GAIN_RU_3_SS_0_LSB    0
#define SPU_RX_GAIN_6_RX_GAIN_RU_3_SS_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_GAIN_6_RX_GAIN_RU_3_SS_1_RST    0x0
#define SPU_RX_GAIN_6_RX_GAIN_RU_3_SS_0_RST    0x0

__INLINE void spu_rx_gain_6_pack(uint16_t rx_gain_ru3_ss1, uint16_t rx_gain_ru3_ss0)
{
	ASSERT_ERR((((uint32_t)rx_gain_ru3_ss1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_gain_ru3_ss0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_6_ADDR,  ((uint32_t)rx_gain_ru3_ss1 << 16) |((uint32_t)rx_gain_ru3_ss0 << 0));
}

__INLINE void spu_rx_gain_6_unpack(uint16_t* rx_gain_ru3_ss1, uint16_t* rx_gain_ru3_ss0)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_6_ADDR);

	*rx_gain_ru3_ss1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_gain_ru3_ss0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_gain_6_rx_gain_ru_3_ss_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_6_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_gain_6_rx_gain_ru_3_ss_1_setf(uint16_t rxgainru3ss1)
{
	ASSERT_ERR((((uint32_t)rxgainru3ss1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_GAIN_6_ADDR, (REG_PL_RD(SPU_RX_GAIN_6_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxgainru3ss1 <<16));
}
__INLINE uint16_t spu_rx_gain_6_rx_gain_ru_3_ss_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_6_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_gain_6_rx_gain_ru_3_ss_0_setf(uint16_t rxgainru3ss0)
{
	ASSERT_ERR((((uint32_t)rxgainru3ss0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_6_ADDR, (REG_PL_RD(SPU_RX_GAIN_6_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxgainru3ss0 <<0));
}

/**
 * @brief RX_GAIN_7 register definition
 *  Rx Fine Gain RU3 SS2 SS3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_GAIN_RU3_SS3           0x0
 *    15:00 RX_GAIN_RU3_SS2           0x0
 * </pre>
 */
#define SPU_RX_GAIN_7_ADDR        (REG_SPU_BASE_ADDR+0x0000035C)
#define SPU_RX_GAIN_7_OFFSET      0x0000035C
#define SPU_RX_GAIN_7_INDEX       0x000000D7
#define SPU_RX_GAIN_7_RESET       0x00000000

__INLINE uint32_t  spu_rx_gain_7_get(void)
{
	return REG_PL_RD(SPU_RX_GAIN_7_ADDR);
}

__INLINE void spu_rx_gain_7_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_GAIN_7_ADDR, value);
}

// field definitions
#define SPU_RX_GAIN_7_RX_GAIN_RU_3_SS_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_GAIN_7_RX_GAIN_RU_3_SS_3_LSB    16
#define SPU_RX_GAIN_7_RX_GAIN_RU_3_SS_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_GAIN_7_RX_GAIN_RU_3_SS_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_GAIN_7_RX_GAIN_RU_3_SS_2_LSB    0
#define SPU_RX_GAIN_7_RX_GAIN_RU_3_SS_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_GAIN_7_RX_GAIN_RU_3_SS_3_RST    0x0
#define SPU_RX_GAIN_7_RX_GAIN_RU_3_SS_2_RST    0x0

__INLINE void spu_rx_gain_7_pack(uint16_t rx_gain_ru3_ss3, uint16_t rx_gain_ru3_ss2)
{
	ASSERT_ERR((((uint32_t)rx_gain_ru3_ss3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_gain_ru3_ss2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_7_ADDR,  ((uint32_t)rx_gain_ru3_ss3 << 16) |((uint32_t)rx_gain_ru3_ss2 << 0));
}

__INLINE void spu_rx_gain_7_unpack(uint16_t* rx_gain_ru3_ss3, uint16_t* rx_gain_ru3_ss2)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_7_ADDR);

	*rx_gain_ru3_ss3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_gain_ru3_ss2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_gain_7_rx_gain_ru_3_ss_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_7_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_gain_7_rx_gain_ru_3_ss_3_setf(uint16_t rxgainru3ss3)
{
	ASSERT_ERR((((uint32_t)rxgainru3ss3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_GAIN_7_ADDR, (REG_PL_RD(SPU_RX_GAIN_7_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxgainru3ss3 <<16));
}
__INLINE uint16_t spu_rx_gain_7_rx_gain_ru_3_ss_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_7_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_gain_7_rx_gain_ru_3_ss_2_setf(uint16_t rxgainru3ss2)
{
	ASSERT_ERR((((uint32_t)rxgainru3ss2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_7_ADDR, (REG_PL_RD(SPU_RX_GAIN_7_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxgainru3ss2 <<0));
}

/**
 * @brief RX_GAIN_8 register definition
 *  Rx Fine Gain RU4 SS0 SS1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_GAIN_RU4_SS1           0x0
 *    15:00 RX_GAIN_RU4_SS0           0x0
 * </pre>
 */
#define SPU_RX_GAIN_8_ADDR        (REG_SPU_BASE_ADDR+0x00000360)
#define SPU_RX_GAIN_8_OFFSET      0x00000360
#define SPU_RX_GAIN_8_INDEX       0x000000D8
#define SPU_RX_GAIN_8_RESET       0x00000000

__INLINE uint32_t  spu_rx_gain_8_get(void)
{
	return REG_PL_RD(SPU_RX_GAIN_8_ADDR);
}

__INLINE void spu_rx_gain_8_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_GAIN_8_ADDR, value);
}

// field definitions
#define SPU_RX_GAIN_8_RX_GAIN_RU_4_SS_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_GAIN_8_RX_GAIN_RU_4_SS_1_LSB    16
#define SPU_RX_GAIN_8_RX_GAIN_RU_4_SS_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_GAIN_8_RX_GAIN_RU_4_SS_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_GAIN_8_RX_GAIN_RU_4_SS_0_LSB    0
#define SPU_RX_GAIN_8_RX_GAIN_RU_4_SS_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_GAIN_8_RX_GAIN_RU_4_SS_1_RST    0x0
#define SPU_RX_GAIN_8_RX_GAIN_RU_4_SS_0_RST    0x0

__INLINE void spu_rx_gain_8_pack(uint16_t rx_gain_ru4_ss1, uint16_t rx_gain_ru4_ss0)
{
	ASSERT_ERR((((uint32_t)rx_gain_ru4_ss1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_gain_ru4_ss0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_8_ADDR,  ((uint32_t)rx_gain_ru4_ss1 << 16) |((uint32_t)rx_gain_ru4_ss0 << 0));
}

__INLINE void spu_rx_gain_8_unpack(uint16_t* rx_gain_ru4_ss1, uint16_t* rx_gain_ru4_ss0)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_8_ADDR);

	*rx_gain_ru4_ss1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_gain_ru4_ss0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_gain_8_rx_gain_ru_4_ss_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_8_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_gain_8_rx_gain_ru_4_ss_1_setf(uint16_t rxgainru4ss1)
{
	ASSERT_ERR((((uint32_t)rxgainru4ss1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_GAIN_8_ADDR, (REG_PL_RD(SPU_RX_GAIN_8_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxgainru4ss1 <<16));
}
__INLINE uint16_t spu_rx_gain_8_rx_gain_ru_4_ss_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_8_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_gain_8_rx_gain_ru_4_ss_0_setf(uint16_t rxgainru4ss0)
{
	ASSERT_ERR((((uint32_t)rxgainru4ss0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_8_ADDR, (REG_PL_RD(SPU_RX_GAIN_8_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxgainru4ss0 <<0));
}

/**
 * @brief RX_GAIN_9 register definition
 *  Rx Fine Gain RU4 SS2 SS3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_GAIN_RU4_SS3           0x0
 *    15:00 RX_GAIN_RU4_SS2           0x0
 * </pre>
 */
#define SPU_RX_GAIN_9_ADDR        (REG_SPU_BASE_ADDR+0x00000364)
#define SPU_RX_GAIN_9_OFFSET      0x00000364
#define SPU_RX_GAIN_9_INDEX       0x000000D9
#define SPU_RX_GAIN_9_RESET       0x00000000

__INLINE uint32_t  spu_rx_gain_9_get(void)
{
	return REG_PL_RD(SPU_RX_GAIN_9_ADDR);
}

__INLINE void spu_rx_gain_9_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_GAIN_9_ADDR, value);
}

// field definitions
#define SPU_RX_GAIN_9_RX_GAIN_RU_4_SS_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_GAIN_9_RX_GAIN_RU_4_SS_3_LSB    16
#define SPU_RX_GAIN_9_RX_GAIN_RU_4_SS_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_GAIN_9_RX_GAIN_RU_4_SS_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_GAIN_9_RX_GAIN_RU_4_SS_2_LSB    0
#define SPU_RX_GAIN_9_RX_GAIN_RU_4_SS_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_GAIN_9_RX_GAIN_RU_4_SS_3_RST    0x0
#define SPU_RX_GAIN_9_RX_GAIN_RU_4_SS_2_RST    0x0

__INLINE void spu_rx_gain_9_pack(uint16_t rx_gain_ru4_ss3, uint16_t rx_gain_ru4_ss2)
{
	ASSERT_ERR((((uint32_t)rx_gain_ru4_ss3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_gain_ru4_ss2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_9_ADDR,  ((uint32_t)rx_gain_ru4_ss3 << 16) |((uint32_t)rx_gain_ru4_ss2 << 0));
}

__INLINE void spu_rx_gain_9_unpack(uint16_t* rx_gain_ru4_ss3, uint16_t* rx_gain_ru4_ss2)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_9_ADDR);

	*rx_gain_ru4_ss3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_gain_ru4_ss2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_gain_9_rx_gain_ru_4_ss_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_9_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_gain_9_rx_gain_ru_4_ss_3_setf(uint16_t rxgainru4ss3)
{
	ASSERT_ERR((((uint32_t)rxgainru4ss3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_GAIN_9_ADDR, (REG_PL_RD(SPU_RX_GAIN_9_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxgainru4ss3 <<16));
}
__INLINE uint16_t spu_rx_gain_9_rx_gain_ru_4_ss_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_9_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_gain_9_rx_gain_ru_4_ss_2_setf(uint16_t rxgainru4ss2)
{
	ASSERT_ERR((((uint32_t)rxgainru4ss2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_9_ADDR, (REG_PL_RD(SPU_RX_GAIN_9_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxgainru4ss2 <<0));
}

/**
 * @brief RX_GAIN_10 register definition
 *  Rx Fine Gain RU5 SS0 SS1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_GAIN_RU5_SS1           0x0
 *    15:00 RX_GAIN_RU5_SS0           0x0
 * </pre>
 */
#define SPU_RX_GAIN_10_ADDR        (REG_SPU_BASE_ADDR+0x00000368)
#define SPU_RX_GAIN_10_OFFSET      0x00000368
#define SPU_RX_GAIN_10_INDEX       0x000000DA
#define SPU_RX_GAIN_10_RESET       0x00000000

__INLINE uint32_t  spu_rx_gain_10_get(void)
{
	return REG_PL_RD(SPU_RX_GAIN_10_ADDR);
}

__INLINE void spu_rx_gain_10_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_GAIN_10_ADDR, value);
}

// field definitions
#define SPU_RX_GAIN_10_RX_GAIN_RU_5_SS_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_GAIN_10_RX_GAIN_RU_5_SS_1_LSB    16
#define SPU_RX_GAIN_10_RX_GAIN_RU_5_SS_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_GAIN_10_RX_GAIN_RU_5_SS_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_GAIN_10_RX_GAIN_RU_5_SS_0_LSB    0
#define SPU_RX_GAIN_10_RX_GAIN_RU_5_SS_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_GAIN_10_RX_GAIN_RU_5_SS_1_RST    0x0
#define SPU_RX_GAIN_10_RX_GAIN_RU_5_SS_0_RST    0x0

__INLINE void spu_rx_gain_10_pack(uint16_t rx_gain_ru5_ss1, uint16_t rx_gain_ru5_ss0)
{
	ASSERT_ERR((((uint32_t)rx_gain_ru5_ss1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_gain_ru5_ss0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_10_ADDR,  ((uint32_t)rx_gain_ru5_ss1 << 16) |((uint32_t)rx_gain_ru5_ss0 << 0));
}

__INLINE void spu_rx_gain_10_unpack(uint16_t* rx_gain_ru5_ss1, uint16_t* rx_gain_ru5_ss0)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_10_ADDR);

	*rx_gain_ru5_ss1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_gain_ru5_ss0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_gain_10_rx_gain_ru_5_ss_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_10_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_gain_10_rx_gain_ru_5_ss_1_setf(uint16_t rxgainru5ss1)
{
	ASSERT_ERR((((uint32_t)rxgainru5ss1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_GAIN_10_ADDR, (REG_PL_RD(SPU_RX_GAIN_10_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxgainru5ss1 <<16));
}
__INLINE uint16_t spu_rx_gain_10_rx_gain_ru_5_ss_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_10_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_gain_10_rx_gain_ru_5_ss_0_setf(uint16_t rxgainru5ss0)
{
	ASSERT_ERR((((uint32_t)rxgainru5ss0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_10_ADDR, (REG_PL_RD(SPU_RX_GAIN_10_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxgainru5ss0 <<0));
}

/**
 * @brief RX_GAIN_11 register definition
 *  Rx Fine Gain RU5 SS2 SS3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_GAIN_RU5_SS3           0x0
 *    15:00 RX_GAIN_RU5_SS2           0x0
 * </pre>
 */
#define SPU_RX_GAIN_11_ADDR        (REG_SPU_BASE_ADDR+0x0000036C)
#define SPU_RX_GAIN_11_OFFSET      0x0000036C
#define SPU_RX_GAIN_11_INDEX       0x000000DB
#define SPU_RX_GAIN_11_RESET       0x00000000

__INLINE uint32_t  spu_rx_gain_11_get(void)
{
	return REG_PL_RD(SPU_RX_GAIN_11_ADDR);
}

__INLINE void spu_rx_gain_11_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_GAIN_11_ADDR, value);
}

// field definitions
#define SPU_RX_GAIN_11_RX_GAIN_RU_5_SS_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_GAIN_11_RX_GAIN_RU_5_SS_3_LSB    16
#define SPU_RX_GAIN_11_RX_GAIN_RU_5_SS_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_GAIN_11_RX_GAIN_RU_5_SS_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_GAIN_11_RX_GAIN_RU_5_SS_2_LSB    0
#define SPU_RX_GAIN_11_RX_GAIN_RU_5_SS_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_GAIN_11_RX_GAIN_RU_5_SS_3_RST    0x0
#define SPU_RX_GAIN_11_RX_GAIN_RU_5_SS_2_RST    0x0

__INLINE void spu_rx_gain_11_pack(uint16_t rx_gain_ru5_ss3, uint16_t rx_gain_ru5_ss2)
{
	ASSERT_ERR((((uint32_t)rx_gain_ru5_ss3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_gain_ru5_ss2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_11_ADDR,  ((uint32_t)rx_gain_ru5_ss3 << 16) |((uint32_t)rx_gain_ru5_ss2 << 0));
}

__INLINE void spu_rx_gain_11_unpack(uint16_t* rx_gain_ru5_ss3, uint16_t* rx_gain_ru5_ss2)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_11_ADDR);

	*rx_gain_ru5_ss3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_gain_ru5_ss2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_gain_11_rx_gain_ru_5_ss_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_11_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_gain_11_rx_gain_ru_5_ss_3_setf(uint16_t rxgainru5ss3)
{
	ASSERT_ERR((((uint32_t)rxgainru5ss3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_GAIN_11_ADDR, (REG_PL_RD(SPU_RX_GAIN_11_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxgainru5ss3 <<16));
}
__INLINE uint16_t spu_rx_gain_11_rx_gain_ru_5_ss_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_11_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_gain_11_rx_gain_ru_5_ss_2_setf(uint16_t rxgainru5ss2)
{
	ASSERT_ERR((((uint32_t)rxgainru5ss2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_11_ADDR, (REG_PL_RD(SPU_RX_GAIN_11_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxgainru5ss2 <<0));
}

/**
 * @brief RX_GAIN_12 register definition
 *  Rx Fine Gain RU6 SS0 SS1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_GAIN_RU6_SS1           0x0
 *    15:00 RX_GAIN_RU6_SS0           0x0
 * </pre>
 */
#define SPU_RX_GAIN_12_ADDR        (REG_SPU_BASE_ADDR+0x00000370)
#define SPU_RX_GAIN_12_OFFSET      0x00000370
#define SPU_RX_GAIN_12_INDEX       0x000000DC
#define SPU_RX_GAIN_12_RESET       0x00000000

__INLINE uint32_t  spu_rx_gain_12_get(void)
{
	return REG_PL_RD(SPU_RX_GAIN_12_ADDR);
}

__INLINE void spu_rx_gain_12_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_GAIN_12_ADDR, value);
}

// field definitions
#define SPU_RX_GAIN_12_RX_GAIN_RU_6_SS_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_GAIN_12_RX_GAIN_RU_6_SS_1_LSB    16
#define SPU_RX_GAIN_12_RX_GAIN_RU_6_SS_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_GAIN_12_RX_GAIN_RU_6_SS_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_GAIN_12_RX_GAIN_RU_6_SS_0_LSB    0
#define SPU_RX_GAIN_12_RX_GAIN_RU_6_SS_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_GAIN_12_RX_GAIN_RU_6_SS_1_RST    0x0
#define SPU_RX_GAIN_12_RX_GAIN_RU_6_SS_0_RST    0x0

__INLINE void spu_rx_gain_12_pack(uint16_t rx_gain_ru6_ss1, uint16_t rx_gain_ru6_ss0)
{
	ASSERT_ERR((((uint32_t)rx_gain_ru6_ss1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_gain_ru6_ss0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_12_ADDR,  ((uint32_t)rx_gain_ru6_ss1 << 16) |((uint32_t)rx_gain_ru6_ss0 << 0));
}

__INLINE void spu_rx_gain_12_unpack(uint16_t* rx_gain_ru6_ss1, uint16_t* rx_gain_ru6_ss0)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_12_ADDR);

	*rx_gain_ru6_ss1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_gain_ru6_ss0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_gain_12_rx_gain_ru_6_ss_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_12_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_gain_12_rx_gain_ru_6_ss_1_setf(uint16_t rxgainru6ss1)
{
	ASSERT_ERR((((uint32_t)rxgainru6ss1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_GAIN_12_ADDR, (REG_PL_RD(SPU_RX_GAIN_12_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxgainru6ss1 <<16));
}
__INLINE uint16_t spu_rx_gain_12_rx_gain_ru_6_ss_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_12_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_gain_12_rx_gain_ru_6_ss_0_setf(uint16_t rxgainru6ss0)
{
	ASSERT_ERR((((uint32_t)rxgainru6ss0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_12_ADDR, (REG_PL_RD(SPU_RX_GAIN_12_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxgainru6ss0 <<0));
}

/**
 * @brief RX_GAIN_13 register definition
 *  Rx Fine Gain RU6 SS2 SS3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_GAIN_RU6_SS3           0x0
 *    15:00 RX_GAIN_RU6_SS2           0x0
 * </pre>
 */
#define SPU_RX_GAIN_13_ADDR        (REG_SPU_BASE_ADDR+0x00000374)
#define SPU_RX_GAIN_13_OFFSET      0x00000374
#define SPU_RX_GAIN_13_INDEX       0x000000DD
#define SPU_RX_GAIN_13_RESET       0x00000000

__INLINE uint32_t  spu_rx_gain_13_get(void)
{
	return REG_PL_RD(SPU_RX_GAIN_13_ADDR);
}

__INLINE void spu_rx_gain_13_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_GAIN_13_ADDR, value);
}

// field definitions
#define SPU_RX_GAIN_13_RX_GAIN_RU_6_SS_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_GAIN_13_RX_GAIN_RU_6_SS_3_LSB    16
#define SPU_RX_GAIN_13_RX_GAIN_RU_6_SS_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_GAIN_13_RX_GAIN_RU_6_SS_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_GAIN_13_RX_GAIN_RU_6_SS_2_LSB    0
#define SPU_RX_GAIN_13_RX_GAIN_RU_6_SS_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_GAIN_13_RX_GAIN_RU_6_SS_3_RST    0x0
#define SPU_RX_GAIN_13_RX_GAIN_RU_6_SS_2_RST    0x0

__INLINE void spu_rx_gain_13_pack(uint16_t rx_gain_ru6_ss3, uint16_t rx_gain_ru6_ss2)
{
	ASSERT_ERR((((uint32_t)rx_gain_ru6_ss3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_gain_ru6_ss2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_13_ADDR,  ((uint32_t)rx_gain_ru6_ss3 << 16) |((uint32_t)rx_gain_ru6_ss2 << 0));
}

__INLINE void spu_rx_gain_13_unpack(uint16_t* rx_gain_ru6_ss3, uint16_t* rx_gain_ru6_ss2)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_13_ADDR);

	*rx_gain_ru6_ss3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_gain_ru6_ss2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_gain_13_rx_gain_ru_6_ss_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_13_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_gain_13_rx_gain_ru_6_ss_3_setf(uint16_t rxgainru6ss3)
{
	ASSERT_ERR((((uint32_t)rxgainru6ss3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_GAIN_13_ADDR, (REG_PL_RD(SPU_RX_GAIN_13_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxgainru6ss3 <<16));
}
__INLINE uint16_t spu_rx_gain_13_rx_gain_ru_6_ss_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_13_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_gain_13_rx_gain_ru_6_ss_2_setf(uint16_t rxgainru6ss2)
{
	ASSERT_ERR((((uint32_t)rxgainru6ss2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_13_ADDR, (REG_PL_RD(SPU_RX_GAIN_13_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxgainru6ss2 <<0));
}

/**
 * @brief RX_GAIN_14 register definition
 *  Rx Fine Gain RU7 SS0 SS1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_GAIN_RU7_SS1           0x0
 *    15:00 RX_GAIN_RU7_SS0           0x0
 * </pre>
 */
#define SPU_RX_GAIN_14_ADDR        (REG_SPU_BASE_ADDR+0x00000378)
#define SPU_RX_GAIN_14_OFFSET      0x00000378
#define SPU_RX_GAIN_14_INDEX       0x000000DE
#define SPU_RX_GAIN_14_RESET       0x00000000

__INLINE uint32_t  spu_rx_gain_14_get(void)
{
	return REG_PL_RD(SPU_RX_GAIN_14_ADDR);
}

__INLINE void spu_rx_gain_14_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_GAIN_14_ADDR, value);
}

// field definitions
#define SPU_RX_GAIN_14_RX_GAIN_RU_7_SS_1_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_GAIN_14_RX_GAIN_RU_7_SS_1_LSB    16
#define SPU_RX_GAIN_14_RX_GAIN_RU_7_SS_1_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_GAIN_14_RX_GAIN_RU_7_SS_0_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_GAIN_14_RX_GAIN_RU_7_SS_0_LSB    0
#define SPU_RX_GAIN_14_RX_GAIN_RU_7_SS_0_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_GAIN_14_RX_GAIN_RU_7_SS_1_RST    0x0
#define SPU_RX_GAIN_14_RX_GAIN_RU_7_SS_0_RST    0x0

__INLINE void spu_rx_gain_14_pack(uint16_t rx_gain_ru7_ss1, uint16_t rx_gain_ru7_ss0)
{
	ASSERT_ERR((((uint32_t)rx_gain_ru7_ss1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_gain_ru7_ss0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_14_ADDR,  ((uint32_t)rx_gain_ru7_ss1 << 16) |((uint32_t)rx_gain_ru7_ss0 << 0));
}

__INLINE void spu_rx_gain_14_unpack(uint16_t* rx_gain_ru7_ss1, uint16_t* rx_gain_ru7_ss0)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_14_ADDR);

	*rx_gain_ru7_ss1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_gain_ru7_ss0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_gain_14_rx_gain_ru_7_ss_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_14_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_gain_14_rx_gain_ru_7_ss_1_setf(uint16_t rxgainru7ss1)
{
	ASSERT_ERR((((uint32_t)rxgainru7ss1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_GAIN_14_ADDR, (REG_PL_RD(SPU_RX_GAIN_14_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxgainru7ss1 <<16));
}
__INLINE uint16_t spu_rx_gain_14_rx_gain_ru_7_ss_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_14_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_gain_14_rx_gain_ru_7_ss_0_setf(uint16_t rxgainru7ss0)
{
	ASSERT_ERR((((uint32_t)rxgainru7ss0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_14_ADDR, (REG_PL_RD(SPU_RX_GAIN_14_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxgainru7ss0 <<0));
}

/**
 * @brief RX_GAIN_15 register definition
 *  Rx Fine Gain RU7 SS2 SS3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_GAIN_RU7_SS3           0x0
 *    15:00 RX_GAIN_RU7_SS2           0x0
 * </pre>
 */
#define SPU_RX_GAIN_15_ADDR        (REG_SPU_BASE_ADDR+0x0000037C)
#define SPU_RX_GAIN_15_OFFSET      0x0000037C
#define SPU_RX_GAIN_15_INDEX       0x000000DF
#define SPU_RX_GAIN_15_RESET       0x00000000

__INLINE uint32_t  spu_rx_gain_15_get(void)
{
	return REG_PL_RD(SPU_RX_GAIN_15_ADDR);
}

__INLINE void spu_rx_gain_15_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_GAIN_15_ADDR, value);
}

// field definitions
#define SPU_RX_GAIN_15_RX_GAIN_RU_7_SS_3_MASK    ((uint32_t)0xFFFF0000)
#define SPU_RX_GAIN_15_RX_GAIN_RU_7_SS_3_LSB    16
#define SPU_RX_GAIN_15_RX_GAIN_RU_7_SS_3_WIDTH    ((uint32_t)0x00000010)
#define SPU_RX_GAIN_15_RX_GAIN_RU_7_SS_2_MASK    ((uint32_t)0x0000FFFF)
#define SPU_RX_GAIN_15_RX_GAIN_RU_7_SS_2_LSB    0
#define SPU_RX_GAIN_15_RX_GAIN_RU_7_SS_2_WIDTH    ((uint32_t)0x00000010)

#define SPU_RX_GAIN_15_RX_GAIN_RU_7_SS_3_RST    0x0
#define SPU_RX_GAIN_15_RX_GAIN_RU_7_SS_2_RST    0x0

__INLINE void spu_rx_gain_15_pack(uint16_t rx_gain_ru7_ss3, uint16_t rx_gain_ru7_ss2)
{
	ASSERT_ERR((((uint32_t)rx_gain_ru7_ss3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_gain_ru7_ss2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_15_ADDR,  ((uint32_t)rx_gain_ru7_ss3 << 16) |((uint32_t)rx_gain_ru7_ss2 << 0));
}

__INLINE void spu_rx_gain_15_unpack(uint16_t* rx_gain_ru7_ss3, uint16_t* rx_gain_ru7_ss2)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_15_ADDR);

	*rx_gain_ru7_ss3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_gain_ru7_ss2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t spu_rx_gain_15_rx_gain_ru_7_ss_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_15_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void spu_rx_gain_15_rx_gain_ru_7_ss_3_setf(uint16_t rxgainru7ss3)
{
	ASSERT_ERR((((uint32_t)rxgainru7ss3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(SPU_RX_GAIN_15_ADDR, (REG_PL_RD(SPU_RX_GAIN_15_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxgainru7ss3 <<16));
}
__INLINE uint16_t spu_rx_gain_15_rx_gain_ru_7_ss_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_15_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void spu_rx_gain_15_rx_gain_ru_7_ss_2_setf(uint16_t rxgainru7ss2)
{
	ASSERT_ERR((((uint32_t)rxgainru7ss2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(SPU_RX_GAIN_15_ADDR, (REG_PL_RD(SPU_RX_GAIN_15_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxgainru7ss2 <<0));
}

/**
 * @brief RX_STATIC_CONF register definition
 *  Rx static config register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    12    EFFICIENT_IC_EN           0              
 *    09    FORCE_WAIT_NEW_POEFG      0              
 *    08    FORCE_WAIT_NEW_CPE_STO    1              
 *    06:04 RX_STO_SHIFT              0x5
 *    01:00 RX_TOTAL_SS               0x0
 * </pre>
 */
#define SPU_RX_STATIC_CONF_ADDR        (REG_SPU_BASE_ADDR+0x00000380)
#define SPU_RX_STATIC_CONF_OFFSET      0x00000380
#define SPU_RX_STATIC_CONF_INDEX       0x000000E0
#define SPU_RX_STATIC_CONF_RESET       0x00000150

__INLINE uint32_t  spu_rx_static_conf_get(void)
{
	return REG_PL_RD(SPU_RX_STATIC_CONF_ADDR);
}

__INLINE void spu_rx_static_conf_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_STATIC_CONF_ADDR, value);
}

// field definitions
#define SPU_RX_STATIC_CONF_EFFICIENT_IC_EN_BIT    ((uint32_t)0x00001000)
#define SPU_RX_STATIC_CONF_EFFICIENT_IC_EN_POS    12
#define SPU_RX_STATIC_CONF_FORCE_WAIT_NEW_POEFG_BIT    ((uint32_t)0x00000200)
#define SPU_RX_STATIC_CONF_FORCE_WAIT_NEW_POEFG_POS    9
#define SPU_RX_STATIC_CONF_FORCE_WAIT_NEW_CPE_STO_BIT    ((uint32_t)0x00000100)
#define SPU_RX_STATIC_CONF_FORCE_WAIT_NEW_CPE_STO_POS    8
#define SPU_RX_STATIC_CONF_RX_STO_SHIFT_MASK    ((uint32_t)0x00000070)
#define SPU_RX_STATIC_CONF_RX_STO_SHIFT_LSB    4
#define SPU_RX_STATIC_CONF_RX_STO_SHIFT_WIDTH    ((uint32_t)0x00000003)
#define SPU_RX_STATIC_CONF_RX_TOTAL_SS_MASK    ((uint32_t)0x00000003)
#define SPU_RX_STATIC_CONF_RX_TOTAL_SS_LSB    0
#define SPU_RX_STATIC_CONF_RX_TOTAL_SS_WIDTH    ((uint32_t)0x00000002)

#define SPU_RX_STATIC_CONF_EFFICIENT_IC_EN_RST    0x0
#define SPU_RX_STATIC_CONF_FORCE_WAIT_NEW_POEFG_RST    0x0
#define SPU_RX_STATIC_CONF_FORCE_WAIT_NEW_CPE_STO_RST    0x1
#define SPU_RX_STATIC_CONF_RX_STO_SHIFT_RST    0x5
#define SPU_RX_STATIC_CONF_RX_TOTAL_SS_RST    0x0

__INLINE void spu_rx_static_conf_pack(uint8_t efficient_ic_en, uint8_t force_wait_new_poefg, uint8_t force_wait_new_cpe_sto, uint8_t rx_sto_shift, uint8_t rx_total_ss)
{
	ASSERT_ERR((((uint32_t)efficient_ic_en << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)force_wait_new_poefg << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)force_wait_new_cpe_sto << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)rx_sto_shift << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)rx_total_ss << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(SPU_RX_STATIC_CONF_ADDR,  ((uint32_t)efficient_ic_en << 12) |((uint32_t)force_wait_new_poefg << 9) |((uint32_t)force_wait_new_cpe_sto << 8) |((uint32_t)rx_sto_shift << 4) |((uint32_t)rx_total_ss << 0));
}

__INLINE void spu_rx_static_conf_unpack(uint8_t* efficient_ic_en, uint8_t* force_wait_new_poefg, uint8_t* force_wait_new_cpe_sto, uint8_t* rx_sto_shift, uint8_t* rx_total_ss)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_STATIC_CONF_ADDR);

	*efficient_ic_en = (localVal & ((uint32_t)0x00001000)) >>  12;
	*force_wait_new_poefg = (localVal & ((uint32_t)0x00000200)) >>  9;
	*force_wait_new_cpe_sto = (localVal & ((uint32_t)0x00000100)) >>  8;
	*rx_sto_shift = (localVal & ((uint32_t)0x00000070)) >>  4;
	*rx_total_ss = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t spu_rx_static_conf_efficient_ic_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_STATIC_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void spu_rx_static_conf_efficient_ic_en_setf(uint8_t efficienticen)
{
	ASSERT_ERR((((uint32_t)efficienticen << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(SPU_RX_STATIC_CONF_ADDR, (REG_PL_RD(SPU_RX_STATIC_CONF_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)efficienticen <<12));
}
__INLINE uint8_t spu_rx_static_conf_force_wait_new_poefg_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_STATIC_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void spu_rx_static_conf_force_wait_new_poefg_setf(uint8_t forcewaitnewpoefg)
{
	ASSERT_ERR((((uint32_t)forcewaitnewpoefg << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(SPU_RX_STATIC_CONF_ADDR, (REG_PL_RD(SPU_RX_STATIC_CONF_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)forcewaitnewpoefg <<9));
}
__INLINE uint8_t spu_rx_static_conf_force_wait_new_cpe_sto_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_STATIC_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void spu_rx_static_conf_force_wait_new_cpe_sto_setf(uint8_t forcewaitnewcpesto)
{
	ASSERT_ERR((((uint32_t)forcewaitnewcpesto << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(SPU_RX_STATIC_CONF_ADDR, (REG_PL_RD(SPU_RX_STATIC_CONF_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)forcewaitnewcpesto <<8));
}
__INLINE uint8_t spu_rx_static_conf_rx_sto_shift_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_STATIC_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void spu_rx_static_conf_rx_sto_shift_setf(uint8_t rxstoshift)
{
	ASSERT_ERR((((uint32_t)rxstoshift << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(SPU_RX_STATIC_CONF_ADDR, (REG_PL_RD(SPU_RX_STATIC_CONF_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)rxstoshift <<4));
}
__INLINE uint8_t spu_rx_static_conf_rx_total_ss_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_STATIC_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void spu_rx_static_conf_rx_total_ss_setf(uint8_t rxtotalss)
{
	ASSERT_ERR((((uint32_t)rxtotalss << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(SPU_RX_STATIC_CONF_ADDR, (REG_PL_RD(SPU_RX_STATIC_CONF_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)rxtotalss <<0));
}

/**
 * @brief RX_DYN_CONF register definition
 *  Rx Data Dynamic config register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    RX_GAIN_LOAD_GAIN         0              
 *    15    RX_ROT_LOAD_CPE_STO_U7    0              
 *    14    RX_ROT_LOAD_CPE_STO_U6    0              
 *    13    RX_ROT_LOAD_CPE_STO_U5    0              
 *    12    RX_ROT_LOAD_CPE_STO_U4    0              
 *    11    RX_ROT_LOAD_CPE_STO_U3    0              
 *    10    RX_ROT_LOAD_CPE_STO_U2    0              
 *    09    RX_ROT_LOAD_CPE_STO_U1    0              
 *    08    RX_ROT_LOAD_CPE_STO_U0    0              
 *    01    RX_GAIN_SYM_CNT_CLR       0              
 *    00    RX_ROT_SYM_CNT_CLR        0              
 * </pre>
 */
#define SPU_RX_DYN_CONF_ADDR        (REG_SPU_BASE_ADDR+0x00000384)
#define SPU_RX_DYN_CONF_OFFSET      0x00000384
#define SPU_RX_DYN_CONF_INDEX       0x000000E1
#define SPU_RX_DYN_CONF_RESET       0x00000000

__INLINE void spu_rx_dyn_conf_set(uint32_t value)
{
	REG_PL_WR(SPU_RX_DYN_CONF_ADDR, value);
}

// field definitions
#define SPU_RX_DYN_CONF_RX_GAIN_LOAD_GAIN_BIT    ((uint32_t)0x00010000)
#define SPU_RX_DYN_CONF_RX_GAIN_LOAD_GAIN_POS    16
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_7_BIT    ((uint32_t)0x00008000)
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_7_POS    15
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_6_BIT    ((uint32_t)0x00004000)
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_6_POS    14
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_5_BIT    ((uint32_t)0x00002000)
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_5_POS    13
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_4_BIT    ((uint32_t)0x00001000)
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_4_POS    12
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_3_BIT    ((uint32_t)0x00000800)
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_3_POS    11
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_2_BIT    ((uint32_t)0x00000400)
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_2_POS    10
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_1_BIT    ((uint32_t)0x00000200)
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_1_POS    9
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_0_BIT    ((uint32_t)0x00000100)
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_0_POS    8
#define SPU_RX_DYN_CONF_RX_GAIN_SYM_CNT_CLR_BIT    ((uint32_t)0x00000002)
#define SPU_RX_DYN_CONF_RX_GAIN_SYM_CNT_CLR_POS    1
#define SPU_RX_DYN_CONF_RX_ROT_SYM_CNT_CLR_BIT    ((uint32_t)0x00000001)
#define SPU_RX_DYN_CONF_RX_ROT_SYM_CNT_CLR_POS    0

#define SPU_RX_DYN_CONF_RX_GAIN_LOAD_GAIN_RST    0x0
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_7_RST    0x0
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_6_RST    0x0
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_5_RST    0x0
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_4_RST    0x0
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_3_RST    0x0
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_2_RST    0x0
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_1_RST    0x0
#define SPU_RX_DYN_CONF_RX_ROT_LOAD_CPE_STO_U_0_RST    0x0
#define SPU_RX_DYN_CONF_RX_GAIN_SYM_CNT_CLR_RST    0x0
#define SPU_RX_DYN_CONF_RX_ROT_SYM_CNT_CLR_RST    0x0

__INLINE void spu_rx_dyn_conf_pack(uint8_t rx_gain_load_gain, uint8_t rx_rot_load_cpe_sto_u7, uint8_t rx_rot_load_cpe_sto_u6, uint8_t rx_rot_load_cpe_sto_u5, uint8_t rx_rot_load_cpe_sto_u4, uint8_t rx_rot_load_cpe_sto_u3, uint8_t rx_rot_load_cpe_sto_u2, uint8_t rx_rot_load_cpe_sto_u1, uint8_t rx_rot_load_cpe_sto_u0, uint8_t rx_gain_sym_cnt_clr, uint8_t rx_rot_sym_cnt_clr)
{
	ASSERT_ERR((((uint32_t)rx_gain_load_gain << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_load_cpe_sto_u7 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_load_cpe_sto_u6 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_load_cpe_sto_u5 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_load_cpe_sto_u4 << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_load_cpe_sto_u3 << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_load_cpe_sto_u2 << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_load_cpe_sto_u1 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_load_cpe_sto_u0 << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)rx_gain_sym_cnt_clr << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)rx_rot_sym_cnt_clr << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_RX_DYN_CONF_ADDR,  ((uint32_t)rx_gain_load_gain << 16) |((uint32_t)rx_rot_load_cpe_sto_u7 << 15) |((uint32_t)rx_rot_load_cpe_sto_u6 << 14) |((uint32_t)rx_rot_load_cpe_sto_u5 << 13) |((uint32_t)rx_rot_load_cpe_sto_u4 << 12) |((uint32_t)rx_rot_load_cpe_sto_u3 << 11) |((uint32_t)rx_rot_load_cpe_sto_u2 << 10) |((uint32_t)rx_rot_load_cpe_sto_u1 << 9) |((uint32_t)rx_rot_load_cpe_sto_u0 << 8) |((uint32_t)rx_gain_sym_cnt_clr << 1) |((uint32_t)rx_rot_sym_cnt_clr << 0));
}

__INLINE void spu_rx_dyn_conf_rx_gain_load_gain_setf(uint8_t rxgainloadgain)
{
	ASSERT_ERR((((uint32_t)rxgainloadgain << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(SPU_RX_DYN_CONF_ADDR, (REG_PL_RD(SPU_RX_DYN_CONF_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)rxgainloadgain <<16));
}
__INLINE void spu_rx_dyn_conf_rx_rot_load_cpe_sto_u_7_setf(uint8_t rxrotloadcpestou7)
{
	ASSERT_ERR((((uint32_t)rxrotloadcpestou7 << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(SPU_RX_DYN_CONF_ADDR, (REG_PL_RD(SPU_RX_DYN_CONF_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)rxrotloadcpestou7 <<15));
}
__INLINE void spu_rx_dyn_conf_rx_rot_load_cpe_sto_u_6_setf(uint8_t rxrotloadcpestou6)
{
	ASSERT_ERR((((uint32_t)rxrotloadcpestou6 << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(SPU_RX_DYN_CONF_ADDR, (REG_PL_RD(SPU_RX_DYN_CONF_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)rxrotloadcpestou6 <<14));
}
__INLINE void spu_rx_dyn_conf_rx_rot_load_cpe_sto_u_5_setf(uint8_t rxrotloadcpestou5)
{
	ASSERT_ERR((((uint32_t)rxrotloadcpestou5 << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(SPU_RX_DYN_CONF_ADDR, (REG_PL_RD(SPU_RX_DYN_CONF_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)rxrotloadcpestou5 <<13));
}
__INLINE void spu_rx_dyn_conf_rx_rot_load_cpe_sto_u_4_setf(uint8_t rxrotloadcpestou4)
{
	ASSERT_ERR((((uint32_t)rxrotloadcpestou4 << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(SPU_RX_DYN_CONF_ADDR, (REG_PL_RD(SPU_RX_DYN_CONF_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)rxrotloadcpestou4 <<12));
}
__INLINE void spu_rx_dyn_conf_rx_rot_load_cpe_sto_u_3_setf(uint8_t rxrotloadcpestou3)
{
	ASSERT_ERR((((uint32_t)rxrotloadcpestou3 << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(SPU_RX_DYN_CONF_ADDR, (REG_PL_RD(SPU_RX_DYN_CONF_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)rxrotloadcpestou3 <<11));
}
__INLINE void spu_rx_dyn_conf_rx_rot_load_cpe_sto_u_2_setf(uint8_t rxrotloadcpestou2)
{
	ASSERT_ERR((((uint32_t)rxrotloadcpestou2 << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(SPU_RX_DYN_CONF_ADDR, (REG_PL_RD(SPU_RX_DYN_CONF_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)rxrotloadcpestou2 <<10));
}
__INLINE void spu_rx_dyn_conf_rx_rot_load_cpe_sto_u_1_setf(uint8_t rxrotloadcpestou1)
{
	ASSERT_ERR((((uint32_t)rxrotloadcpestou1 << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(SPU_RX_DYN_CONF_ADDR, (REG_PL_RD(SPU_RX_DYN_CONF_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)rxrotloadcpestou1 <<9));
}
__INLINE void spu_rx_dyn_conf_rx_rot_load_cpe_sto_u_0_setf(uint8_t rxrotloadcpestou0)
{
	ASSERT_ERR((((uint32_t)rxrotloadcpestou0 << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(SPU_RX_DYN_CONF_ADDR, (REG_PL_RD(SPU_RX_DYN_CONF_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)rxrotloadcpestou0 <<8));
}
__INLINE void spu_rx_dyn_conf_rx_gain_sym_cnt_clr_setf(uint8_t rxgainsymcntclr)
{
	ASSERT_ERR((((uint32_t)rxgainsymcntclr << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(SPU_RX_DYN_CONF_ADDR, (REG_PL_RD(SPU_RX_DYN_CONF_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)rxgainsymcntclr <<1));
}
__INLINE void spu_rx_dyn_conf_rx_rot_sym_cnt_clr_setf(uint8_t rxrotsymcntclr)
{
	ASSERT_ERR((((uint32_t)rxrotsymcntclr << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(SPU_RX_DYN_CONF_ADDR, (REG_PL_RD(SPU_RX_DYN_CONF_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)rxrotsymcntclr <<0));
}

/**
 * @brief RX_ROT_STAT register definition
 *  Rx status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23    RX_ROT_UPDATE_ACK_U7      1              
 *    22    RX_ROT_UPDATE_ACK_U6      1              
 *    21    RX_ROT_UPDATE_ACK_U5      1              
 *    20    RX_ROT_UPDATE_ACK_U4      1              
 *    19    RX_ROT_UPDATE_ACK_U3      1              
 *    18    RX_ROT_UPDATE_ACK_U2      1              
 *    17    RX_ROT_UPDATE_ACK_U1      1              
 *    16    RX_ROT_UPDATE_ACK_U0      1              
 *    11:00 RX_ROT_SYM_CNT            0x0
 * </pre>
 */
#define SPU_RX_ROT_STAT_ADDR        (REG_SPU_BASE_ADDR+0x000003F8)
#define SPU_RX_ROT_STAT_OFFSET      0x000003F8
#define SPU_RX_ROT_STAT_INDEX       0x000000FE
#define SPU_RX_ROT_STAT_RESET       0x00FF0000

__INLINE uint32_t  spu_rx_rot_stat_get(void)
{
	return REG_PL_RD(SPU_RX_ROT_STAT_ADDR);
}

// field definitions
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_7_BIT    ((uint32_t)0x00800000)
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_7_POS    23
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_6_BIT    ((uint32_t)0x00400000)
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_6_POS    22
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_5_BIT    ((uint32_t)0x00200000)
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_5_POS    21
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_4_BIT    ((uint32_t)0x00100000)
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_4_POS    20
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_3_BIT    ((uint32_t)0x00080000)
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_3_POS    19
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_2_BIT    ((uint32_t)0x00040000)
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_2_POS    18
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_1_BIT    ((uint32_t)0x00020000)
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_1_POS    17
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_0_BIT    ((uint32_t)0x00010000)
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_0_POS    16
#define SPU_RX_ROT_STAT_RX_ROT_SYM_CNT_MASK    ((uint32_t)0x00000FFF)
#define SPU_RX_ROT_STAT_RX_ROT_SYM_CNT_LSB    0
#define SPU_RX_ROT_STAT_RX_ROT_SYM_CNT_WIDTH    ((uint32_t)0x0000000C)

#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_7_RST    0x1
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_6_RST    0x1
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_5_RST    0x1
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_4_RST    0x1
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_3_RST    0x1
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_2_RST    0x1
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_1_RST    0x1
#define SPU_RX_ROT_STAT_RX_ROT_UPDATE_ACK_U_0_RST    0x1
#define SPU_RX_ROT_STAT_RX_ROT_SYM_CNT_RST    0x0

__INLINE void spu_rx_rot_stat_unpack(uint8_t* rx_rot_update_ack_u7, uint8_t* rx_rot_update_ack_u6, uint8_t* rx_rot_update_ack_u5, uint8_t* rx_rot_update_ack_u4, uint8_t* rx_rot_update_ack_u3, uint8_t* rx_rot_update_ack_u2, uint8_t* rx_rot_update_ack_u1, uint8_t* rx_rot_update_ack_u0, uint16_t* rx_rot_sym_cnt)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_STAT_ADDR);

	*rx_rot_update_ack_u7 = (localVal & ((uint32_t)0x00800000)) >>  23;
	*rx_rot_update_ack_u6 = (localVal & ((uint32_t)0x00400000)) >>  22;
	*rx_rot_update_ack_u5 = (localVal & ((uint32_t)0x00200000)) >>  21;
	*rx_rot_update_ack_u4 = (localVal & ((uint32_t)0x00100000)) >>  20;
	*rx_rot_update_ack_u3 = (localVal & ((uint32_t)0x00080000)) >>  19;
	*rx_rot_update_ack_u2 = (localVal & ((uint32_t)0x00040000)) >>  18;
	*rx_rot_update_ack_u1 = (localVal & ((uint32_t)0x00020000)) >>  17;
	*rx_rot_update_ack_u0 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*rx_rot_sym_cnt = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t spu_rx_rot_stat_rx_rot_update_ack_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE uint8_t spu_rx_rot_stat_rx_rot_update_ack_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE uint8_t spu_rx_rot_stat_rx_rot_update_ack_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE uint8_t spu_rx_rot_stat_rx_rot_update_ack_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE uint8_t spu_rx_rot_stat_rx_rot_update_ack_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE uint8_t spu_rx_rot_stat_rx_rot_update_ack_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE uint8_t spu_rx_rot_stat_rx_rot_update_ack_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00020000)) >> 17);
}
__INLINE uint8_t spu_rx_rot_stat_rx_rot_update_ack_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint16_t spu_rx_rot_stat_rx_rot_sym_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_ROT_STAT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}

/**
 * @brief RX_GAIN_STAT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    RX_GAIN_UPDATE_ACK        1              
 *    11:00 RX_GAIN_SYM_CNT           0x0
 * </pre>
 */
#define SPU_RX_GAIN_STAT_ADDR        (REG_SPU_BASE_ADDR+0x000003FC)
#define SPU_RX_GAIN_STAT_OFFSET      0x000003FC
#define SPU_RX_GAIN_STAT_INDEX       0x000000FF
#define SPU_RX_GAIN_STAT_RESET       0x00010000

__INLINE uint32_t  spu_rx_gain_stat_get(void)
{
	return REG_PL_RD(SPU_RX_GAIN_STAT_ADDR);
}

// field definitions
#define SPU_RX_GAIN_STAT_RX_GAIN_UPDATE_ACK_BIT    ((uint32_t)0x00010000)
#define SPU_RX_GAIN_STAT_RX_GAIN_UPDATE_ACK_POS    16
#define SPU_RX_GAIN_STAT_RX_GAIN_SYM_CNT_MASK    ((uint32_t)0x00000FFF)
#define SPU_RX_GAIN_STAT_RX_GAIN_SYM_CNT_LSB    0
#define SPU_RX_GAIN_STAT_RX_GAIN_SYM_CNT_WIDTH    ((uint32_t)0x0000000C)

#define SPU_RX_GAIN_STAT_RX_GAIN_UPDATE_ACK_RST    0x1
#define SPU_RX_GAIN_STAT_RX_GAIN_SYM_CNT_RST    0x0

__INLINE void spu_rx_gain_stat_unpack(uint8_t* rx_gain_update_ack, uint16_t* rx_gain_sym_cnt)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_STAT_ADDR);

	*rx_gain_update_ack = (localVal & ((uint32_t)0x00010000)) >>  16;
	*rx_gain_sym_cnt = (localVal & ((uint32_t)0x00000FFF)) >>  0;
}

__INLINE uint8_t spu_rx_gain_stat_rx_gain_update_ack_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_STAT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint16_t spu_rx_gain_stat_rx_gain_sym_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(SPU_RX_GAIN_STAT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00000FFF)) >> 0);
}
/**
 * @brief HELTF_RAM register definition
 *  1024 memory size
 * </pre>
 */
#define SPU_HELTF_RAM_ADDR        (REG_SPU_BASE_ADDR+0x00000400)
#define SPU_HELTF_RAM_OFFSET      0x00000400
#define SPU_HELTF_RAM_SIZE        0x00000400
#define SPU_HELTF_RAM_END_ADDR    (SPU_HELTF_RAM_ADDR + SPU_HELTF_RAM_SIZE - 1)


#undef DBG_FILEID
#endif //_REG_SPU_H_
