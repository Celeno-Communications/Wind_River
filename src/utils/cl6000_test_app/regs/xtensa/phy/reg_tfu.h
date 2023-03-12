#ifndef _REG_TFU_H_
#define _REG_TFU_H_

#include <stdint.h>
#include "phy/_reg_tfu.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_TFU__H__FILEID__

#define REG_TFU_COUNT  81


/**
 * @brief VERSION register definition
 *  HW version number register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 VERSION                   0x2
 * </pre>
 */
#define TFU_VERSION_ADDR        (REG_TFU_BASE_ADDR+0x00000000)
#define TFU_VERSION_OFFSET      0x00000000
#define TFU_VERSION_INDEX       0x00000000
#define TFU_VERSION_RESET       0x00000002

__INLINE uint32_t  tfu_version_get(void)
{
	return REG_PL_RD(TFU_VERSION_ADDR);
}

// field definitions
#define TFU_VERSION_VERSION_MASK            ((uint32_t)0xFFFFFFFF)
#define TFU_VERSION_VERSION_LSB             0
#define TFU_VERSION_VERSION_WIDTH           ((uint32_t)0x00000020)

#define TFU_VERSION_VERSION_RST             0x2

__INLINE uint32_t tfu_version_version_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_VERSION_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief START_AND_STOP register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    09    FIC_SW_RESET              0              
 *    08    FORCE_STOP                0              
 *    04    STOP                      0              
 *    00    START                     0              
 * </pre>
 */
#define TFU_START_AND_STOP_ADDR        (REG_TFU_BASE_ADDR+0x00000004)
#define TFU_START_AND_STOP_OFFSET      0x00000004
#define TFU_START_AND_STOP_INDEX       0x00000001
#define TFU_START_AND_STOP_RESET       0x00000000

__INLINE uint32_t  tfu_start_and_stop_get(void)
{
	return REG_PL_RD(TFU_START_AND_STOP_ADDR);
}

__INLINE void tfu_start_and_stop_set(uint32_t value)
{
	REG_PL_WR(TFU_START_AND_STOP_ADDR, value);
}

// field definitions
#define TFU_START_AND_STOP_FIC_SW_RESET_BIT    ((uint32_t)0x00000200)
#define TFU_START_AND_STOP_FIC_SW_RESET_POS    9
#define TFU_START_AND_STOP_FORCE_STOP_BIT    ((uint32_t)0x00000100)
#define TFU_START_AND_STOP_FORCE_STOP_POS    8
#define TFU_START_AND_STOP_STOP_BIT         ((uint32_t)0x00000010)
#define TFU_START_AND_STOP_STOP_POS         4
#define TFU_START_AND_STOP_START_BIT        ((uint32_t)0x00000001)
#define TFU_START_AND_STOP_START_POS        0

#define TFU_START_AND_STOP_FIC_SW_RESET_RST    0x0
#define TFU_START_AND_STOP_FORCE_STOP_RST    0x0
#define TFU_START_AND_STOP_STOP_RST         0x0
#define TFU_START_AND_STOP_START_RST        0x0

__INLINE void tfu_start_and_stop_pack(uint8_t fic_sw_reset, uint8_t force_stop, uint8_t stop, uint8_t start)
{
	ASSERT_ERR((((uint32_t)fic_sw_reset << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)force_stop << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)stop << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)start << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(TFU_START_AND_STOP_ADDR,  ((uint32_t)fic_sw_reset << 9) |((uint32_t)force_stop << 8) |((uint32_t)stop << 4) |((uint32_t)start << 0));
}

__INLINE void tfu_start_and_stop_unpack(uint8_t* fic_sw_reset, uint8_t* force_stop, uint8_t* stop, uint8_t* start)
{
	uint32_t localVal = REG_PL_RD(TFU_START_AND_STOP_ADDR);

	*fic_sw_reset = (localVal & ((uint32_t)0x00000200)) >>  9;
	*force_stop = (localVal & ((uint32_t)0x00000100)) >>  8;
	*stop = (localVal & ((uint32_t)0x00000010)) >>  4;
	*start = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t tfu_start_and_stop_fic_sw_reset_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_START_AND_STOP_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void tfu_start_and_stop_fic_sw_reset_setf(uint8_t ficswreset)
{
	ASSERT_ERR((((uint32_t)ficswreset << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(TFU_START_AND_STOP_ADDR, (REG_PL_RD(TFU_START_AND_STOP_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)ficswreset <<9));
}
__INLINE uint8_t tfu_start_and_stop_force_stop_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_START_AND_STOP_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void tfu_start_and_stop_force_stop_setf(uint8_t forcestop)
{
	ASSERT_ERR((((uint32_t)forcestop << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(TFU_START_AND_STOP_ADDR, (REG_PL_RD(TFU_START_AND_STOP_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)forcestop <<8));
}
__INLINE uint8_t tfu_start_and_stop_stop_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_START_AND_STOP_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void tfu_start_and_stop_stop_setf(uint8_t stop)
{
	ASSERT_ERR((((uint32_t)stop << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(TFU_START_AND_STOP_ADDR, (REG_PL_RD(TFU_START_AND_STOP_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)stop <<4));
}
__INLINE uint8_t tfu_start_and_stop_start_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_START_AND_STOP_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void tfu_start_and_stop_start_setf(uint8_t start)
{
	ASSERT_ERR((((uint32_t)start << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(TFU_START_AND_STOP_ADDR, (REG_PL_RD(TFU_START_AND_STOP_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)start <<0));
}

/**
 * @brief STATIC_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    TX_HE_TB                  0              
 *    30:28 TX_HE_PE_SIZE             0x0
 *    27    TX_FFT_SHIFT_EN           0              
 *    26    RX_FFT_SHIFT_EN           0              
 *    25:24 FE_SCALING                0x0
 *    23    FFT_SCALING               0              
 *    22    DEBUG_EN                  0              
 *    21    FREQ_OFFSET_PER_ANT_MODE  0              
 *    20    TX_IFFT_SAT_EN            0              
 *    19    RX_PREAMBLE_40            0              
 *    18    RX_HE_EXTRACT_MODE        0              
 *    17:16 NBR_OF_MEM_PTR            0x0
 *    15:08 DC_EST_NBR_OF_PTS         0x0
 *    07:04 ANTENNA_RESERVED          0x0
 *    03:02 ANTENNA                   0x3
 *    01:00 CHANNEL_BW                0x0
 * </pre>
 */
#define TFU_STATIC_CONFIG_ADDR        (REG_TFU_BASE_ADDR+0x00000008)
#define TFU_STATIC_CONFIG_OFFSET      0x00000008
#define TFU_STATIC_CONFIG_INDEX       0x00000002
#define TFU_STATIC_CONFIG_RESET       0x0000000C

__INLINE uint32_t  tfu_static_config_get(void)
{
	return REG_PL_RD(TFU_STATIC_CONFIG_ADDR);
}

__INLINE void tfu_static_config_set(uint32_t value)
{
	REG_PL_WR(TFU_STATIC_CONFIG_ADDR, value);
}

// field definitions
#define TFU_STATIC_CONFIG_TX_HE_TB_BIT      ((uint32_t)0x80000000)
#define TFU_STATIC_CONFIG_TX_HE_TB_POS      31
#define TFU_STATIC_CONFIG_TX_HE_PE_SIZE_MASK    ((uint32_t)0x70000000)
#define TFU_STATIC_CONFIG_TX_HE_PE_SIZE_LSB    28
#define TFU_STATIC_CONFIG_TX_HE_PE_SIZE_WIDTH    ((uint32_t)0x00000003)
#define TFU_STATIC_CONFIG_TX_FFT_SHIFT_EN_BIT    ((uint32_t)0x08000000)
#define TFU_STATIC_CONFIG_TX_FFT_SHIFT_EN_POS    27
#define TFU_STATIC_CONFIG_RX_FFT_SHIFT_EN_BIT    ((uint32_t)0x04000000)
#define TFU_STATIC_CONFIG_RX_FFT_SHIFT_EN_POS    26
#define TFU_STATIC_CONFIG_FE_SCALING_MASK    ((uint32_t)0x03000000)
#define TFU_STATIC_CONFIG_FE_SCALING_LSB    24
#define TFU_STATIC_CONFIG_FE_SCALING_WIDTH    ((uint32_t)0x00000002)
#define TFU_STATIC_CONFIG_FFT_SCALING_BIT    ((uint32_t)0x00800000)
#define TFU_STATIC_CONFIG_FFT_SCALING_POS    23
#define TFU_STATIC_CONFIG_DEBUG_EN_BIT      ((uint32_t)0x00400000)
#define TFU_STATIC_CONFIG_DEBUG_EN_POS      22
#define TFU_STATIC_CONFIG_FREQ_OFFSET_PER_ANT_MODE_BIT    ((uint32_t)0x00200000)
#define TFU_STATIC_CONFIG_FREQ_OFFSET_PER_ANT_MODE_POS    21
#define TFU_STATIC_CONFIG_TX_IFFT_SAT_EN_BIT    ((uint32_t)0x00100000)
#define TFU_STATIC_CONFIG_TX_IFFT_SAT_EN_POS    20
#define TFU_STATIC_CONFIG_RX_PREAMBLE_40_BIT    ((uint32_t)0x00080000)
#define TFU_STATIC_CONFIG_RX_PREAMBLE_40_POS    19
#define TFU_STATIC_CONFIG_RX_HE_EXTRACT_MODE_BIT    ((uint32_t)0x00040000)
#define TFU_STATIC_CONFIG_RX_HE_EXTRACT_MODE_POS    18
#define TFU_STATIC_CONFIG_NBR_OF_MEM_PTR_MASK    ((uint32_t)0x00030000)
#define TFU_STATIC_CONFIG_NBR_OF_MEM_PTR_LSB    16
#define TFU_STATIC_CONFIG_NBR_OF_MEM_PTR_WIDTH    ((uint32_t)0x00000002)
#define TFU_STATIC_CONFIG_DC_EST_NBR_OF_PTS_MASK    ((uint32_t)0x0000FF00)
#define TFU_STATIC_CONFIG_DC_EST_NBR_OF_PTS_LSB    8
#define TFU_STATIC_CONFIG_DC_EST_NBR_OF_PTS_WIDTH    ((uint32_t)0x00000008)
#define TFU_STATIC_CONFIG_ANTENNA_RESERVED_MASK    ((uint32_t)0x000000F0)
#define TFU_STATIC_CONFIG_ANTENNA_RESERVED_LSB    4
#define TFU_STATIC_CONFIG_ANTENNA_RESERVED_WIDTH    ((uint32_t)0x00000004)
#define TFU_STATIC_CONFIG_ANTENNA_MASK      ((uint32_t)0x0000000C)
#define TFU_STATIC_CONFIG_ANTENNA_LSB       2
#define TFU_STATIC_CONFIG_ANTENNA_WIDTH     ((uint32_t)0x00000002)
#define TFU_STATIC_CONFIG_CHANNEL_BW_MASK    ((uint32_t)0x00000003)
#define TFU_STATIC_CONFIG_CHANNEL_BW_LSB    0
#define TFU_STATIC_CONFIG_CHANNEL_BW_WIDTH    ((uint32_t)0x00000002)

#define TFU_STATIC_CONFIG_TX_HE_TB_RST      0x0
#define TFU_STATIC_CONFIG_TX_HE_PE_SIZE_RST    0x0
#define TFU_STATIC_CONFIG_TX_FFT_SHIFT_EN_RST    0x0
#define TFU_STATIC_CONFIG_RX_FFT_SHIFT_EN_RST    0x0
#define TFU_STATIC_CONFIG_FE_SCALING_RST    0x0
#define TFU_STATIC_CONFIG_FFT_SCALING_RST    0x0
#define TFU_STATIC_CONFIG_DEBUG_EN_RST      0x0
#define TFU_STATIC_CONFIG_FREQ_OFFSET_PER_ANT_MODE_RST    0x0
#define TFU_STATIC_CONFIG_TX_IFFT_SAT_EN_RST    0x0
#define TFU_STATIC_CONFIG_RX_PREAMBLE_40_RST    0x0
#define TFU_STATIC_CONFIG_RX_HE_EXTRACT_MODE_RST    0x0
#define TFU_STATIC_CONFIG_NBR_OF_MEM_PTR_RST    0x0
#define TFU_STATIC_CONFIG_DC_EST_NBR_OF_PTS_RST    0x0
#define TFU_STATIC_CONFIG_ANTENNA_RESERVED_RST    0x0
#define TFU_STATIC_CONFIG_ANTENNA_RST       0x3
#define TFU_STATIC_CONFIG_CHANNEL_BW_RST    0x0

__INLINE void tfu_static_config_pack(uint8_t tx_he_tb, uint8_t tx_he_pe_size, uint8_t tx_fft_shift_en, uint8_t rx_fft_shift_en, uint8_t fe_scaling, uint8_t fft_scaling, uint8_t debug_en, uint8_t freq_offset_per_ant_mode, uint8_t tx_ifft_sat_en, uint8_t rx_preamble_40, uint8_t rx_he_extract_mode, uint8_t nbr_of_mem_ptr, uint8_t dc_est_nbr_of_pts, uint8_t antenna_reserved, uint8_t antenna, uint8_t channel_bw)
{
	ASSERT_ERR((((uint32_t)tx_he_tb << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)tx_he_pe_size << 28) & ~((uint32_t)0x70000000)) == 0);
	ASSERT_ERR((((uint32_t)tx_fft_shift_en << 27) & ~((uint32_t)0x08000000)) == 0);
	ASSERT_ERR((((uint32_t)rx_fft_shift_en << 26) & ~((uint32_t)0x04000000)) == 0);
	ASSERT_ERR((((uint32_t)fe_scaling << 24) & ~((uint32_t)0x03000000)) == 0);
	ASSERT_ERR((((uint32_t)fft_scaling << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)debug_en << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)freq_offset_per_ant_mode << 21) & ~((uint32_t)0x00200000)) == 0);
	ASSERT_ERR((((uint32_t)tx_ifft_sat_en << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)rx_preamble_40 << 19) & ~((uint32_t)0x00080000)) == 0);
	ASSERT_ERR((((uint32_t)rx_he_extract_mode << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)nbr_of_mem_ptr << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)dc_est_nbr_of_pts << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)antenna_reserved << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)antenna << 2) & ~((uint32_t)0x0000000C)) == 0);
	ASSERT_ERR((((uint32_t)channel_bw << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(TFU_STATIC_CONFIG_ADDR,  ((uint32_t)tx_he_tb << 31) |((uint32_t)tx_he_pe_size << 28) |((uint32_t)tx_fft_shift_en << 27) |((uint32_t)rx_fft_shift_en << 26) |((uint32_t)fe_scaling << 24) |((uint32_t)fft_scaling << 23) |((uint32_t)debug_en << 22) |((uint32_t)freq_offset_per_ant_mode << 21) |((uint32_t)tx_ifft_sat_en << 20) |((uint32_t)rx_preamble_40 << 19) |((uint32_t)rx_he_extract_mode << 18) |((uint32_t)nbr_of_mem_ptr << 16) |((uint32_t)dc_est_nbr_of_pts << 8) |((uint32_t)antenna_reserved << 4) |((uint32_t)antenna << 2) |((uint32_t)channel_bw << 0));
}

__INLINE void tfu_static_config_unpack(uint8_t* tx_he_tb, uint8_t* tx_he_pe_size, uint8_t* tx_fft_shift_en, uint8_t* rx_fft_shift_en, uint8_t* fe_scaling, uint8_t* fft_scaling, uint8_t* debug_en, uint8_t* freq_offset_per_ant_mode, uint8_t* tx_ifft_sat_en, uint8_t* rx_preamble_40, uint8_t* rx_he_extract_mode, uint8_t* nbr_of_mem_ptr, uint8_t* dc_est_nbr_of_pts, uint8_t* antenna_reserved, uint8_t* antenna, uint8_t* channel_bw)
{
	uint32_t localVal = REG_PL_RD(TFU_STATIC_CONFIG_ADDR);

	*tx_he_tb = (localVal & ((uint32_t)0x80000000)) >>  31;
	*tx_he_pe_size = (localVal & ((uint32_t)0x70000000)) >>  28;
	*tx_fft_shift_en = (localVal & ((uint32_t)0x08000000)) >>  27;
	*rx_fft_shift_en = (localVal & ((uint32_t)0x04000000)) >>  26;
	*fe_scaling = (localVal & ((uint32_t)0x03000000)) >>  24;
	*fft_scaling = (localVal & ((uint32_t)0x00800000)) >>  23;
	*debug_en = (localVal & ((uint32_t)0x00400000)) >>  22;
	*freq_offset_per_ant_mode = (localVal & ((uint32_t)0x00200000)) >>  21;
	*tx_ifft_sat_en = (localVal & ((uint32_t)0x00100000)) >>  20;
	*rx_preamble_40 = (localVal & ((uint32_t)0x00080000)) >>  19;
	*rx_he_extract_mode = (localVal & ((uint32_t)0x00040000)) >>  18;
	*nbr_of_mem_ptr = (localVal & ((uint32_t)0x00030000)) >>  16;
	*dc_est_nbr_of_pts = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*antenna_reserved = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*antenna = (localVal & ((uint32_t)0x0000000C)) >>  2;
	*channel_bw = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t tfu_static_config_tx_he_tb_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void tfu_static_config_tx_he_tb_setf(uint8_t txhetb)
{
	ASSERT_ERR((((uint32_t)txhetb << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(TFU_STATIC_CONFIG_ADDR, (REG_PL_RD(TFU_STATIC_CONFIG_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)txhetb <<31));
}
__INLINE uint8_t tfu_static_config_tx_he_pe_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x70000000)) >> 28);
}
__INLINE void tfu_static_config_tx_he_pe_size_setf(uint8_t txhepesize)
{
	ASSERT_ERR((((uint32_t)txhepesize << 28) & ~((uint32_t)0x70000000)) == 0);
	REG_PL_WR(TFU_STATIC_CONFIG_ADDR, (REG_PL_RD(TFU_STATIC_CONFIG_ADDR) & ~((uint32_t)0x70000000)) | ((uint32_t)txhepesize <<28));
}
__INLINE uint8_t tfu_static_config_tx_fft_shift_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x08000000)) >> 27);
}
__INLINE void tfu_static_config_tx_fft_shift_en_setf(uint8_t txfftshiften)
{
	ASSERT_ERR((((uint32_t)txfftshiften << 27) & ~((uint32_t)0x08000000)) == 0);
	REG_PL_WR(TFU_STATIC_CONFIG_ADDR, (REG_PL_RD(TFU_STATIC_CONFIG_ADDR) & ~((uint32_t)0x08000000)) | ((uint32_t)txfftshiften <<27));
}
__INLINE uint8_t tfu_static_config_rx_fft_shift_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x04000000)) >> 26);
}
__INLINE void tfu_static_config_rx_fft_shift_en_setf(uint8_t rxfftshiften)
{
	ASSERT_ERR((((uint32_t)rxfftshiften << 26) & ~((uint32_t)0x04000000)) == 0);
	REG_PL_WR(TFU_STATIC_CONFIG_ADDR, (REG_PL_RD(TFU_STATIC_CONFIG_ADDR) & ~((uint32_t)0x04000000)) | ((uint32_t)rxfftshiften <<26));
}
__INLINE uint8_t tfu_static_config_fe_scaling_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x03000000)) >> 24);
}
__INLINE void tfu_static_config_fe_scaling_setf(uint8_t fescaling)
{
	ASSERT_ERR((((uint32_t)fescaling << 24) & ~((uint32_t)0x03000000)) == 0);
	REG_PL_WR(TFU_STATIC_CONFIG_ADDR, (REG_PL_RD(TFU_STATIC_CONFIG_ADDR) & ~((uint32_t)0x03000000)) | ((uint32_t)fescaling <<24));
}
__INLINE uint8_t tfu_static_config_fft_scaling_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE void tfu_static_config_fft_scaling_setf(uint8_t fftscaling)
{
	ASSERT_ERR((((uint32_t)fftscaling << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(TFU_STATIC_CONFIG_ADDR, (REG_PL_RD(TFU_STATIC_CONFIG_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)fftscaling <<23));
}
__INLINE uint8_t tfu_static_config_debug_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE void tfu_static_config_debug_en_setf(uint8_t debugen)
{
	ASSERT_ERR((((uint32_t)debugen << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(TFU_STATIC_CONFIG_ADDR, (REG_PL_RD(TFU_STATIC_CONFIG_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)debugen <<22));
}
__INLINE uint8_t tfu_static_config_freq_offset_per_ant_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE void tfu_static_config_freq_offset_per_ant_mode_setf(uint8_t freqoffsetperantmode)
{
	ASSERT_ERR((((uint32_t)freqoffsetperantmode << 21) & ~((uint32_t)0x00200000)) == 0);
	REG_PL_WR(TFU_STATIC_CONFIG_ADDR, (REG_PL_RD(TFU_STATIC_CONFIG_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)freqoffsetperantmode <<21));
}
__INLINE uint8_t tfu_static_config_tx_ifft_sat_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE void tfu_static_config_tx_ifft_sat_en_setf(uint8_t txifftsaten)
{
	ASSERT_ERR((((uint32_t)txifftsaten << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(TFU_STATIC_CONFIG_ADDR, (REG_PL_RD(TFU_STATIC_CONFIG_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)txifftsaten <<20));
}
__INLINE uint8_t tfu_static_config_rx_preamble_40_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00080000)) >> 19);
}
__INLINE void tfu_static_config_rx_preamble_40_setf(uint8_t rxpreamble40)
{
	ASSERT_ERR((((uint32_t)rxpreamble40 << 19) & ~((uint32_t)0x00080000)) == 0);
	REG_PL_WR(TFU_STATIC_CONFIG_ADDR, (REG_PL_RD(TFU_STATIC_CONFIG_ADDR) & ~((uint32_t)0x00080000)) | ((uint32_t)rxpreamble40 <<19));
}
__INLINE uint8_t tfu_static_config_rx_he_extract_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void tfu_static_config_rx_he_extract_mode_setf(uint8_t rxheextractmode)
{
	ASSERT_ERR((((uint32_t)rxheextractmode << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(TFU_STATIC_CONFIG_ADDR, (REG_PL_RD(TFU_STATIC_CONFIG_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)rxheextractmode <<18));
}
__INLINE uint8_t tfu_static_config_nbr_of_mem_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void tfu_static_config_nbr_of_mem_ptr_setf(uint8_t nbrofmemptr)
{
	ASSERT_ERR((((uint32_t)nbrofmemptr << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(TFU_STATIC_CONFIG_ADDR, (REG_PL_RD(TFU_STATIC_CONFIG_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)nbrofmemptr <<16));
}
__INLINE uint8_t tfu_static_config_dc_est_nbr_of_pts_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void tfu_static_config_dc_est_nbr_of_pts_setf(uint8_t dcestnbrofpts)
{
	ASSERT_ERR((((uint32_t)dcestnbrofpts << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(TFU_STATIC_CONFIG_ADDR, (REG_PL_RD(TFU_STATIC_CONFIG_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)dcestnbrofpts <<8));
}
__INLINE uint8_t tfu_static_config_antenna_reserved_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t tfu_static_config_antenna_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000C)) >> 2);
}
__INLINE void tfu_static_config_antenna_setf(uint8_t antenna)
{
	ASSERT_ERR((((uint32_t)antenna << 2) & ~((uint32_t)0x0000000C)) == 0);
	REG_PL_WR(TFU_STATIC_CONFIG_ADDR, (REG_PL_RD(TFU_STATIC_CONFIG_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)antenna <<2));
}
__INLINE uint8_t tfu_static_config_channel_bw_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void tfu_static_config_channel_bw_setf(uint8_t channelbw)
{
	ASSERT_ERR((((uint32_t)channelbw << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(TFU_STATIC_CONFIG_ADDR, (REG_PL_RD(TFU_STATIC_CONFIG_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)channelbw <<0));
}

/**
 * @brief DYNAMIC_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:28 DC_MODE                   0x0
 *    25    Sample_Flush_On_AGC_Un_Lock_En 0              
 *    24    LAST_SYMBOL               0              
 *    20    FO_COMP_EN                0              
 *    19:18 HE_LTF_SIZE               0x0
 *    17:16 GI_TYPE                   0x0
 *    15    TXUNDERUN_CHK_EN          0              
 *    14:12 TX_HE_LTF_NUM             0x0
 *    11    TX_DMA_EN                 1              
 *    10    RX_DOUBLE_RATE            0              
 *    09:08 FFT_MODE                  0x0
 *    07:04 MODE                      0x0
 *    03    TX_IMG                    0              
 *    02    TX_HE                     0              
 *    01:00 FRAME_BW                  0x0
 * </pre>
 */
#define TFU_DYNAMIC_CONFIG_ADDR        (REG_TFU_BASE_ADDR+0x0000000C)
#define TFU_DYNAMIC_CONFIG_OFFSET      0x0000000C
#define TFU_DYNAMIC_CONFIG_INDEX       0x00000003
#define TFU_DYNAMIC_CONFIG_RESET       0x00000800

__INLINE uint32_t  tfu_dynamic_config_get(void)
{
	return REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR);
}

__INLINE void tfu_dynamic_config_set(uint32_t value)
{
	REG_PL_WR(TFU_DYNAMIC_CONFIG_ADDR, value);
}

// field definitions
#define TFU_DYNAMIC_CONFIG_DC_MODE_MASK     ((uint32_t)0x30000000)
#define TFU_DYNAMIC_CONFIG_DC_MODE_LSB      28
#define TFU_DYNAMIC_CONFIG_DC_MODE_WIDTH    ((uint32_t)0x00000002)
#define TFU_DYNAMIC_CONFIG_SAMPLE_FLUSH_ON_AGC_UN_LOCK_EN_BIT    ((uint32_t)0x02000000)
#define TFU_DYNAMIC_CONFIG_SAMPLE_FLUSH_ON_AGC_UN_LOCK_EN_POS    25
#define TFU_DYNAMIC_CONFIG_LAST_SYMBOL_BIT    ((uint32_t)0x01000000)
#define TFU_DYNAMIC_CONFIG_LAST_SYMBOL_POS    24
#define TFU_DYNAMIC_CONFIG_FO_COMP_EN_BIT    ((uint32_t)0x00100000)
#define TFU_DYNAMIC_CONFIG_FO_COMP_EN_POS    20
#define TFU_DYNAMIC_CONFIG_HE_LTF_SIZE_MASK    ((uint32_t)0x000C0000)
#define TFU_DYNAMIC_CONFIG_HE_LTF_SIZE_LSB    18
#define TFU_DYNAMIC_CONFIG_HE_LTF_SIZE_WIDTH    ((uint32_t)0x00000002)
#define TFU_DYNAMIC_CONFIG_GI_TYPE_MASK     ((uint32_t)0x00030000)
#define TFU_DYNAMIC_CONFIG_GI_TYPE_LSB      16
#define TFU_DYNAMIC_CONFIG_GI_TYPE_WIDTH    ((uint32_t)0x00000002)
#define TFU_DYNAMIC_CONFIG_TXUNDERUN_CHK_EN_BIT    ((uint32_t)0x00008000)
#define TFU_DYNAMIC_CONFIG_TXUNDERUN_CHK_EN_POS    15
#define TFU_DYNAMIC_CONFIG_TX_HE_LTF_NUM_MASK    ((uint32_t)0x00007000)
#define TFU_DYNAMIC_CONFIG_TX_HE_LTF_NUM_LSB    12
#define TFU_DYNAMIC_CONFIG_TX_HE_LTF_NUM_WIDTH    ((uint32_t)0x00000003)
#define TFU_DYNAMIC_CONFIG_TX_DMA_EN_BIT    ((uint32_t)0x00000800)
#define TFU_DYNAMIC_CONFIG_TX_DMA_EN_POS    11
#define TFU_DYNAMIC_CONFIG_RX_DOUBLE_RATE_BIT    ((uint32_t)0x00000400)
#define TFU_DYNAMIC_CONFIG_RX_DOUBLE_RATE_POS    10
#define TFU_DYNAMIC_CONFIG_FFT_MODE_MASK    ((uint32_t)0x00000300)
#define TFU_DYNAMIC_CONFIG_FFT_MODE_LSB     8
#define TFU_DYNAMIC_CONFIG_FFT_MODE_WIDTH    ((uint32_t)0x00000002)
#define TFU_DYNAMIC_CONFIG_MODE_MASK        ((uint32_t)0x000000F0)
#define TFU_DYNAMIC_CONFIG_MODE_LSB         4
#define TFU_DYNAMIC_CONFIG_MODE_WIDTH       ((uint32_t)0x00000004)
#define TFU_DYNAMIC_CONFIG_TX_IMG_BIT       ((uint32_t)0x00000008)
#define TFU_DYNAMIC_CONFIG_TX_IMG_POS       3
#define TFU_DYNAMIC_CONFIG_TX_HE_BIT        ((uint32_t)0x00000004)
#define TFU_DYNAMIC_CONFIG_TX_HE_POS        2
#define TFU_DYNAMIC_CONFIG_FRAME_BW_MASK    ((uint32_t)0x00000003)
#define TFU_DYNAMIC_CONFIG_FRAME_BW_LSB     0
#define TFU_DYNAMIC_CONFIG_FRAME_BW_WIDTH    ((uint32_t)0x00000002)

#define TFU_DYNAMIC_CONFIG_DC_MODE_RST      0x0
#define TFU_DYNAMIC_CONFIG_SAMPLE_FLUSH_ON_AGC_UN_LOCK_EN_RST    0x0
#define TFU_DYNAMIC_CONFIG_LAST_SYMBOL_RST    0x0
#define TFU_DYNAMIC_CONFIG_FO_COMP_EN_RST    0x0
#define TFU_DYNAMIC_CONFIG_HE_LTF_SIZE_RST    0x0
#define TFU_DYNAMIC_CONFIG_GI_TYPE_RST      0x0
#define TFU_DYNAMIC_CONFIG_TXUNDERUN_CHK_EN_RST    0x0
#define TFU_DYNAMIC_CONFIG_TX_HE_LTF_NUM_RST    0x0
#define TFU_DYNAMIC_CONFIG_TX_DMA_EN_RST    0x1
#define TFU_DYNAMIC_CONFIG_RX_DOUBLE_RATE_RST    0x0
#define TFU_DYNAMIC_CONFIG_FFT_MODE_RST     0x0
#define TFU_DYNAMIC_CONFIG_MODE_RST         0x0
#define TFU_DYNAMIC_CONFIG_TX_IMG_RST       0x0
#define TFU_DYNAMIC_CONFIG_TX_HE_RST        0x0
#define TFU_DYNAMIC_CONFIG_FRAME_BW_RST     0x0

__INLINE void tfu_dynamic_config_pack(uint8_t dc_mode, uint8_t sample_flush_on_agc_un_lock_en, uint8_t last_symbol, uint8_t fo_comp_en, uint8_t he_ltf_size, uint8_t gi_type, uint8_t txunderun_chk_en, uint8_t tx_he_ltf_num, uint8_t tx_dma_en, uint8_t rx_double_rate, uint8_t fft_mode, uint8_t mode, uint8_t tx_img, uint8_t tx_he, uint8_t frame_bw)
{
	ASSERT_ERR((((uint32_t)dc_mode << 28) & ~((uint32_t)0x30000000)) == 0);
	ASSERT_ERR((((uint32_t)sample_flush_on_agc_un_lock_en << 25) & ~((uint32_t)0x02000000)) == 0);
	ASSERT_ERR((((uint32_t)last_symbol << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)fo_comp_en << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)he_ltf_size << 18) & ~((uint32_t)0x000C0000)) == 0);
	ASSERT_ERR((((uint32_t)gi_type << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)txunderun_chk_en << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)tx_he_ltf_num << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)tx_dma_en << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)rx_double_rate << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)fft_mode << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)mode << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)tx_img << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)tx_he << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)frame_bw << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(TFU_DYNAMIC_CONFIG_ADDR,  ((uint32_t)dc_mode << 28) |((uint32_t)sample_flush_on_agc_un_lock_en << 25) |((uint32_t)last_symbol << 24) |((uint32_t)fo_comp_en << 20) |((uint32_t)he_ltf_size << 18) |((uint32_t)gi_type << 16) |((uint32_t)txunderun_chk_en << 15) |((uint32_t)tx_he_ltf_num << 12) |((uint32_t)tx_dma_en << 11) |((uint32_t)rx_double_rate << 10) |((uint32_t)fft_mode << 8) |((uint32_t)mode << 4) |((uint32_t)tx_img << 3) |((uint32_t)tx_he << 2) |((uint32_t)frame_bw << 0));
}

__INLINE void tfu_dynamic_config_unpack(uint8_t* dc_mode, uint8_t* sample_flush_on_agc_un_lock_en, uint8_t* last_symbol, uint8_t* fo_comp_en, uint8_t* he_ltf_size, uint8_t* gi_type, uint8_t* txunderun_chk_en, uint8_t* tx_he_ltf_num, uint8_t* tx_dma_en, uint8_t* rx_double_rate, uint8_t* fft_mode, uint8_t* mode, uint8_t* tx_img, uint8_t* tx_he, uint8_t* frame_bw)
{
	uint32_t localVal = REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR);

	*dc_mode = (localVal & ((uint32_t)0x30000000)) >>  28;
	*sample_flush_on_agc_un_lock_en = (localVal & ((uint32_t)0x02000000)) >>  25;
	*last_symbol = (localVal & ((uint32_t)0x01000000)) >>  24;
	*fo_comp_en = (localVal & ((uint32_t)0x00100000)) >>  20;
	*he_ltf_size = (localVal & ((uint32_t)0x000C0000)) >>  18;
	*gi_type = (localVal & ((uint32_t)0x00030000)) >>  16;
	*txunderun_chk_en = (localVal & ((uint32_t)0x00008000)) >>  15;
	*tx_he_ltf_num = (localVal & ((uint32_t)0x00007000)) >>  12;
	*tx_dma_en = (localVal & ((uint32_t)0x00000800)) >>  11;
	*rx_double_rate = (localVal & ((uint32_t)0x00000400)) >>  10;
	*fft_mode = (localVal & ((uint32_t)0x00000300)) >>  8;
	*mode = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*tx_img = (localVal & ((uint32_t)0x00000008)) >>  3;
	*tx_he = (localVal & ((uint32_t)0x00000004)) >>  2;
	*frame_bw = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t tfu_dynamic_config_dc_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x30000000)) >> 28);
}
__INLINE void tfu_dynamic_config_dc_mode_setf(uint8_t dcmode)
{
	ASSERT_ERR((((uint32_t)dcmode << 28) & ~((uint32_t)0x30000000)) == 0);
	REG_PL_WR(TFU_DYNAMIC_CONFIG_ADDR, (REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR) & ~((uint32_t)0x30000000)) | ((uint32_t)dcmode <<28));
}
__INLINE uint8_t tfu_dynamic_config_sample_flush_on_agc_un_lock_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE void tfu_dynamic_config_sample_flush_on_agc_un_lock_en_setf(uint8_t sampleflushonagcunlocken)
{
	ASSERT_ERR((((uint32_t)sampleflushonagcunlocken << 25) & ~((uint32_t)0x02000000)) == 0);
	REG_PL_WR(TFU_DYNAMIC_CONFIG_ADDR, (REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)sampleflushonagcunlocken <<25));
}
__INLINE uint8_t tfu_dynamic_config_last_symbol_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE void tfu_dynamic_config_last_symbol_setf(uint8_t lastsymbol)
{
	ASSERT_ERR((((uint32_t)lastsymbol << 24) & ~((uint32_t)0x01000000)) == 0);
	REG_PL_WR(TFU_DYNAMIC_CONFIG_ADDR, (REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)lastsymbol <<24));
}
__INLINE uint8_t tfu_dynamic_config_fo_comp_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE void tfu_dynamic_config_fo_comp_en_setf(uint8_t focompen)
{
	ASSERT_ERR((((uint32_t)focompen << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(TFU_DYNAMIC_CONFIG_ADDR, (REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)focompen <<20));
}
__INLINE uint8_t tfu_dynamic_config_he_ltf_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000C0000)) >> 18);
}
__INLINE void tfu_dynamic_config_he_ltf_size_setf(uint8_t heltfsize)
{
	ASSERT_ERR((((uint32_t)heltfsize << 18) & ~((uint32_t)0x000C0000)) == 0);
	REG_PL_WR(TFU_DYNAMIC_CONFIG_ADDR, (REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR) & ~((uint32_t)0x000C0000)) | ((uint32_t)heltfsize <<18));
}
__INLINE uint8_t tfu_dynamic_config_gi_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void tfu_dynamic_config_gi_type_setf(uint8_t gitype)
{
	ASSERT_ERR((((uint32_t)gitype << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(TFU_DYNAMIC_CONFIG_ADDR, (REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)gitype <<16));
}
__INLINE uint8_t tfu_dynamic_config_txunderun_chk_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void tfu_dynamic_config_txunderun_chk_en_setf(uint8_t txunderunchken)
{
	ASSERT_ERR((((uint32_t)txunderunchken << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(TFU_DYNAMIC_CONFIG_ADDR, (REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)txunderunchken <<15));
}
__INLINE uint8_t tfu_dynamic_config_tx_he_ltf_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void tfu_dynamic_config_tx_he_ltf_num_setf(uint8_t txheltfnum)
{
	ASSERT_ERR((((uint32_t)txheltfnum << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(TFU_DYNAMIC_CONFIG_ADDR, (REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)txheltfnum <<12));
}
__INLINE uint8_t tfu_dynamic_config_tx_dma_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void tfu_dynamic_config_tx_dma_en_setf(uint8_t txdmaen)
{
	ASSERT_ERR((((uint32_t)txdmaen << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(TFU_DYNAMIC_CONFIG_ADDR, (REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)txdmaen <<11));
}
__INLINE uint8_t tfu_dynamic_config_rx_double_rate_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void tfu_dynamic_config_rx_double_rate_setf(uint8_t rxdoublerate)
{
	ASSERT_ERR((((uint32_t)rxdoublerate << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(TFU_DYNAMIC_CONFIG_ADDR, (REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)rxdoublerate <<10));
}
__INLINE uint8_t tfu_dynamic_config_fft_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void tfu_dynamic_config_fft_mode_setf(uint8_t fftmode)
{
	ASSERT_ERR((((uint32_t)fftmode << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(TFU_DYNAMIC_CONFIG_ADDR, (REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)fftmode <<8));
}
__INLINE uint8_t tfu_dynamic_config_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void tfu_dynamic_config_mode_setf(uint8_t mode)
{
	ASSERT_ERR((((uint32_t)mode << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(TFU_DYNAMIC_CONFIG_ADDR, (REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)mode <<4));
}
__INLINE uint8_t tfu_dynamic_config_tx_img_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void tfu_dynamic_config_tx_img_setf(uint8_t tximg)
{
	ASSERT_ERR((((uint32_t)tximg << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(TFU_DYNAMIC_CONFIG_ADDR, (REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)tximg <<3));
}
__INLINE uint8_t tfu_dynamic_config_tx_he_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void tfu_dynamic_config_tx_he_setf(uint8_t txhe)
{
	ASSERT_ERR((((uint32_t)txhe << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(TFU_DYNAMIC_CONFIG_ADDR, (REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)txhe <<2));
}
__INLINE uint8_t tfu_dynamic_config_frame_bw_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void tfu_dynamic_config_frame_bw_setf(uint8_t framebw)
{
	ASSERT_ERR((((uint32_t)framebw << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(TFU_DYNAMIC_CONFIG_ADDR, (REG_PL_RD(TFU_DYNAMIC_CONFIG_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)framebw <<0));
}

/**
 * @brief RXMEM_PTR_0 register definition
 *  Pointer to Rx symbol buffer 0 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 RXMEM_PTR_0               0x0
 * </pre>
 */
#define TFU_RXMEM_PTR_0_ADDR        (REG_TFU_BASE_ADDR+0x00000010)
#define TFU_RXMEM_PTR_0_OFFSET      0x00000010
#define TFU_RXMEM_PTR_0_INDEX       0x00000004
#define TFU_RXMEM_PTR_0_RESET       0x00000000

__INLINE uint32_t  tfu_rxmem_ptr_0_get(void)
{
	return REG_PL_RD(TFU_RXMEM_PTR_0_ADDR);
}

__INLINE void tfu_rxmem_ptr_0_set(uint32_t value)
{
	REG_PL_WR(TFU_RXMEM_PTR_0_ADDR, value);
}

// field definitions
#define TFU_RXMEM_PTR_0_RXMEM_PTR_0_MASK    ((uint32_t)0xFFFFFFFC)
#define TFU_RXMEM_PTR_0_RXMEM_PTR_0_LSB     2
#define TFU_RXMEM_PTR_0_RXMEM_PTR_0_WIDTH    ((uint32_t)0x0000001E)

#define TFU_RXMEM_PTR_0_RXMEM_PTR_0_RST     0x0

__INLINE uint32_t tfu_rxmem_ptr_0_rxmem_ptr_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_RXMEM_PTR_0_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void tfu_rxmem_ptr_0_rxmem_ptr_0_setf(uint32_t rxmemptr0)
{
	ASSERT_ERR((((uint32_t)rxmemptr0 << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(TFU_RXMEM_PTR_0_ADDR, (uint32_t)rxmemptr0 << 2);
}

/**
 * @brief RXMEM_PTR_1 register definition
 *  Pointer to Rx symbol buffer 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 RXMEM_PTR_1               0x0
 * </pre>
 */
#define TFU_RXMEM_PTR_1_ADDR        (REG_TFU_BASE_ADDR+0x00000014)
#define TFU_RXMEM_PTR_1_OFFSET      0x00000014
#define TFU_RXMEM_PTR_1_INDEX       0x00000005
#define TFU_RXMEM_PTR_1_RESET       0x00000000

__INLINE uint32_t  tfu_rxmem_ptr_1_get(void)
{
	return REG_PL_RD(TFU_RXMEM_PTR_1_ADDR);
}

__INLINE void tfu_rxmem_ptr_1_set(uint32_t value)
{
	REG_PL_WR(TFU_RXMEM_PTR_1_ADDR, value);
}

// field definitions
#define TFU_RXMEM_PTR_1_RXMEM_PTR_1_MASK    ((uint32_t)0xFFFFFFFC)
#define TFU_RXMEM_PTR_1_RXMEM_PTR_1_LSB     2
#define TFU_RXMEM_PTR_1_RXMEM_PTR_1_WIDTH    ((uint32_t)0x0000001E)

#define TFU_RXMEM_PTR_1_RXMEM_PTR_1_RST     0x0

__INLINE uint32_t tfu_rxmem_ptr_1_rxmem_ptr_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_RXMEM_PTR_1_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void tfu_rxmem_ptr_1_rxmem_ptr_1_setf(uint32_t rxmemptr1)
{
	ASSERT_ERR((((uint32_t)rxmemptr1 << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(TFU_RXMEM_PTR_1_ADDR, (uint32_t)rxmemptr1 << 2);
}

/**
 * @brief RXMEM_PTR_2 register definition
 *  Pointer to Rx symbol buffer 2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 RXMEM_PTR_2               0x0
 * </pre>
 */
#define TFU_RXMEM_PTR_2_ADDR        (REG_TFU_BASE_ADDR+0x00000018)
#define TFU_RXMEM_PTR_2_OFFSET      0x00000018
#define TFU_RXMEM_PTR_2_INDEX       0x00000006
#define TFU_RXMEM_PTR_2_RESET       0x00000000

__INLINE uint32_t  tfu_rxmem_ptr_2_get(void)
{
	return REG_PL_RD(TFU_RXMEM_PTR_2_ADDR);
}

__INLINE void tfu_rxmem_ptr_2_set(uint32_t value)
{
	REG_PL_WR(TFU_RXMEM_PTR_2_ADDR, value);
}

// field definitions
#define TFU_RXMEM_PTR_2_RXMEM_PTR_2_MASK    ((uint32_t)0xFFFFFFFC)
#define TFU_RXMEM_PTR_2_RXMEM_PTR_2_LSB     2
#define TFU_RXMEM_PTR_2_RXMEM_PTR_2_WIDTH    ((uint32_t)0x0000001E)

#define TFU_RXMEM_PTR_2_RXMEM_PTR_2_RST     0x0

__INLINE uint32_t tfu_rxmem_ptr_2_rxmem_ptr_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_RXMEM_PTR_2_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void tfu_rxmem_ptr_2_rxmem_ptr_2_setf(uint32_t rxmemptr2)
{
	ASSERT_ERR((((uint32_t)rxmemptr2 << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(TFU_RXMEM_PTR_2_ADDR, (uint32_t)rxmemptr2 << 2);
}

/**
 * @brief RXMEM_PTR_3 register definition
 *  Pointer to Rx symbol buffer 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 RXMEM_PTR_3               0x0
 * </pre>
 */
#define TFU_RXMEM_PTR_3_ADDR        (REG_TFU_BASE_ADDR+0x0000001C)
#define TFU_RXMEM_PTR_3_OFFSET      0x0000001C
#define TFU_RXMEM_PTR_3_INDEX       0x00000007
#define TFU_RXMEM_PTR_3_RESET       0x00000000

__INLINE uint32_t  tfu_rxmem_ptr_3_get(void)
{
	return REG_PL_RD(TFU_RXMEM_PTR_3_ADDR);
}

__INLINE void tfu_rxmem_ptr_3_set(uint32_t value)
{
	REG_PL_WR(TFU_RXMEM_PTR_3_ADDR, value);
}

// field definitions
#define TFU_RXMEM_PTR_3_RXMEM_PTR_3_MASK    ((uint32_t)0xFFFFFFFC)
#define TFU_RXMEM_PTR_3_RXMEM_PTR_3_LSB     2
#define TFU_RXMEM_PTR_3_RXMEM_PTR_3_WIDTH    ((uint32_t)0x0000001E)

#define TFU_RXMEM_PTR_3_RXMEM_PTR_3_RST     0x0

__INLINE uint32_t tfu_rxmem_ptr_3_rxmem_ptr_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_RXMEM_PTR_3_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void tfu_rxmem_ptr_3_rxmem_ptr_3_setf(uint32_t rxmemptr3)
{
	ASSERT_ERR((((uint32_t)rxmemptr3 << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(TFU_RXMEM_PTR_3_ADDR, (uint32_t)rxmemptr3 << 2);
}

/**
 * @brief TX_MESS_PTR register definition
 *  Pointer to Tx MCCI message address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TX_MESS_PTR               0x0
 * </pre>
 */
#define TFU_TX_MESS_PTR_ADDR        (REG_TFU_BASE_ADDR+0x00000020)
#define TFU_TX_MESS_PTR_OFFSET      0x00000020
#define TFU_TX_MESS_PTR_INDEX       0x00000008
#define TFU_TX_MESS_PTR_RESET       0x00000000

__INLINE uint32_t  tfu_tx_mess_ptr_get(void)
{
	return REG_PL_RD(TFU_TX_MESS_PTR_ADDR);
}

__INLINE void tfu_tx_mess_ptr_set(uint32_t value)
{
	REG_PL_WR(TFU_TX_MESS_PTR_ADDR, value);
}

// field definitions
#define TFU_TX_MESS_PTR_TX_MESS_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TFU_TX_MESS_PTR_TX_MESS_PTR_LSB     0
#define TFU_TX_MESS_PTR_TX_MESS_PTR_WIDTH    ((uint32_t)0x00000020)

#define TFU_TX_MESS_PTR_TX_MESS_PTR_RST     0x0

__INLINE uint32_t tfu_tx_mess_ptr_tx_mess_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_MESS_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void tfu_tx_mess_ptr_tx_mess_ptr_setf(uint32_t txmessptr)
{
	ASSERT_ERR((((uint32_t)txmessptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(TFU_TX_MESS_PTR_ADDR, (uint32_t)txmessptr << 0);
}

/**
 * @brief RX_MESS_PTR register definition
 *  Pointer to Rx MCCI message address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RX_MESS_PTR               0x0
 * </pre>
 */
#define TFU_RX_MESS_PTR_ADDR        (REG_TFU_BASE_ADDR+0x00000024)
#define TFU_RX_MESS_PTR_OFFSET      0x00000024
#define TFU_RX_MESS_PTR_INDEX       0x00000009
#define TFU_RX_MESS_PTR_RESET       0x00000000

__INLINE uint32_t  tfu_rx_mess_ptr_get(void)
{
	return REG_PL_RD(TFU_RX_MESS_PTR_ADDR);
}

__INLINE void tfu_rx_mess_ptr_set(uint32_t value)
{
	REG_PL_WR(TFU_RX_MESS_PTR_ADDR, value);
}

// field definitions
#define TFU_RX_MESS_PTR_RX_MESS_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TFU_RX_MESS_PTR_RX_MESS_PTR_LSB     0
#define TFU_RX_MESS_PTR_RX_MESS_PTR_WIDTH    ((uint32_t)0x00000020)

#define TFU_RX_MESS_PTR_RX_MESS_PTR_RST     0x0

__INLINE uint32_t tfu_rx_mess_ptr_rx_mess_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_RX_MESS_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void tfu_rx_mess_ptr_rx_mess_ptr_setf(uint32_t rxmessptr)
{
	ASSERT_ERR((((uint32_t)rxmessptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(TFU_RX_MESS_PTR_ADDR, (uint32_t)rxmessptr << 0);
}

/**
 * @brief ERR_MESS_PTR register definition
 *  Pointer to MCCI error message address register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MESS_ERR_PTR              0x0
 * </pre>
 */
#define TFU_ERR_MESS_PTR_ADDR        (REG_TFU_BASE_ADDR+0x00000028)
#define TFU_ERR_MESS_PTR_OFFSET      0x00000028
#define TFU_ERR_MESS_PTR_INDEX       0x0000000A
#define TFU_ERR_MESS_PTR_RESET       0x00000000

__INLINE uint32_t  tfu_err_mess_ptr_get(void)
{
	return REG_PL_RD(TFU_ERR_MESS_PTR_ADDR);
}

__INLINE void tfu_err_mess_ptr_set(uint32_t value)
{
	REG_PL_WR(TFU_ERR_MESS_PTR_ADDR, value);
}

// field definitions
#define TFU_ERR_MESS_PTR_MESS_ERR_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TFU_ERR_MESS_PTR_MESS_ERR_PTR_LSB    0
#define TFU_ERR_MESS_PTR_MESS_ERR_PTR_WIDTH    ((uint32_t)0x00000020)

#define TFU_ERR_MESS_PTR_MESS_ERR_PTR_RST    0x0

__INLINE uint32_t tfu_err_mess_ptr_mess_err_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_ERR_MESS_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void tfu_err_mess_ptr_mess_err_ptr_setf(uint32_t messerrptr)
{
	ASSERT_ERR((((uint32_t)messerrptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(TFU_ERR_MESS_PTR_ADDR, (uint32_t)messerrptr << 0);
}

/**
 * @brief DMA_THRESHOLD_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 C1_DMA_OFFSET             0x0
 *    13    IMG_CAL_EN                0              
 *    12    MASK_IMG_SAMPLES          0              
 *    11    SAMPLE_MODE_TYPE          0              
 *    10    DMA_ALIGN_SMP_MODE_SYNC_SKIP 1              
 *    09    DMAAuto_Boundary_Align    0              
 *    08    Immediate_DMA_Thr_Mode    0              
 *    07:00 DMA_THR                   0x0
 * </pre>
 */
#define TFU_DMA_THRESHOLD_CONFIG_ADDR        (REG_TFU_BASE_ADDR+0x0000002C)
#define TFU_DMA_THRESHOLD_CONFIG_OFFSET      0x0000002C
#define TFU_DMA_THRESHOLD_CONFIG_INDEX       0x0000000B
#define TFU_DMA_THRESHOLD_CONFIG_RESET       0x00000400

__INLINE uint32_t  tfu_dma_threshold_config_get(void)
{
	return REG_PL_RD(TFU_DMA_THRESHOLD_CONFIG_ADDR);
}

__INLINE void tfu_dma_threshold_config_set(uint32_t value)
{
	REG_PL_WR(TFU_DMA_THRESHOLD_CONFIG_ADDR, value);
}

// field definitions
#define TFU_DMA_THRESHOLD_CONFIG_C_1_DMA_OFFSET_MASK    ((uint32_t)0xFFFF0000)
#define TFU_DMA_THRESHOLD_CONFIG_C_1_DMA_OFFSET_LSB    16
#define TFU_DMA_THRESHOLD_CONFIG_C_1_DMA_OFFSET_WIDTH    ((uint32_t)0x00000010)
#define TFU_DMA_THRESHOLD_CONFIG_IMG_CAL_EN_BIT    ((uint32_t)0x00002000)
#define TFU_DMA_THRESHOLD_CONFIG_IMG_CAL_EN_POS    13
#define TFU_DMA_THRESHOLD_CONFIG_MASK_IMG_SAMPLES_BIT    ((uint32_t)0x00001000)
#define TFU_DMA_THRESHOLD_CONFIG_MASK_IMG_SAMPLES_POS    12
#define TFU_DMA_THRESHOLD_CONFIG_SAMPLE_MODE_TYPE_BIT    ((uint32_t)0x00000800)
#define TFU_DMA_THRESHOLD_CONFIG_SAMPLE_MODE_TYPE_POS    11
#define TFU_DMA_THRESHOLD_CONFIG_DMA_ALIGN_SMP_MODE_SYNC_SKIP_BIT    ((uint32_t)0x00000400)
#define TFU_DMA_THRESHOLD_CONFIG_DMA_ALIGN_SMP_MODE_SYNC_SKIP_POS    10
#define TFU_DMA_THRESHOLD_CONFIG_DMAAUTO_BOUNDARY_ALIGN_BIT    ((uint32_t)0x00000200)
#define TFU_DMA_THRESHOLD_CONFIG_DMAAUTO_BOUNDARY_ALIGN_POS    9
#define TFU_DMA_THRESHOLD_CONFIG_IMMEDIATE_DMA_THR_MODE_BIT    ((uint32_t)0x00000100)
#define TFU_DMA_THRESHOLD_CONFIG_IMMEDIATE_DMA_THR_MODE_POS    8
#define TFU_DMA_THRESHOLD_CONFIG_DMA_THR_MASK    ((uint32_t)0x000000FF)
#define TFU_DMA_THRESHOLD_CONFIG_DMA_THR_LSB    0
#define TFU_DMA_THRESHOLD_CONFIG_DMA_THR_WIDTH    ((uint32_t)0x00000008)

#define TFU_DMA_THRESHOLD_CONFIG_C_1_DMA_OFFSET_RST    0x0
#define TFU_DMA_THRESHOLD_CONFIG_IMG_CAL_EN_RST    0x0
#define TFU_DMA_THRESHOLD_CONFIG_MASK_IMG_SAMPLES_RST    0x0
#define TFU_DMA_THRESHOLD_CONFIG_SAMPLE_MODE_TYPE_RST    0x0
#define TFU_DMA_THRESHOLD_CONFIG_DMA_ALIGN_SMP_MODE_SYNC_SKIP_RST    0x1
#define TFU_DMA_THRESHOLD_CONFIG_DMAAUTO_BOUNDARY_ALIGN_RST    0x0
#define TFU_DMA_THRESHOLD_CONFIG_IMMEDIATE_DMA_THR_MODE_RST    0x0
#define TFU_DMA_THRESHOLD_CONFIG_DMA_THR_RST    0x0

__INLINE void tfu_dma_threshold_config_pack(uint16_t c1_dma_offset, uint8_t img_cal_en, uint8_t mask_img_samples, uint8_t sample_mode_type, uint8_t dma_align_smp_mode_sync_skip, uint8_t dmaauto_boundary_align, uint8_t immediate_dma_thr_mode, uint8_t dma_thr)
{
	ASSERT_ERR((((uint32_t)c1_dma_offset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)img_cal_en << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)mask_img_samples << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)sample_mode_type << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)dma_align_smp_mode_sync_skip << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)dmaauto_boundary_align << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)immediate_dma_thr_mode << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)dma_thr << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(TFU_DMA_THRESHOLD_CONFIG_ADDR,  ((uint32_t)c1_dma_offset << 16) |((uint32_t)img_cal_en << 13) |((uint32_t)mask_img_samples << 12) |((uint32_t)sample_mode_type << 11) |((uint32_t)dma_align_smp_mode_sync_skip << 10) |((uint32_t)dmaauto_boundary_align << 9) |((uint32_t)immediate_dma_thr_mode << 8) |((uint32_t)dma_thr << 0));
}

__INLINE void tfu_dma_threshold_config_unpack(uint16_t* c1_dma_offset, uint8_t* img_cal_en, uint8_t* mask_img_samples, uint8_t* sample_mode_type, uint8_t* dma_align_smp_mode_sync_skip, uint8_t* dmaauto_boundary_align, uint8_t* immediate_dma_thr_mode, uint8_t* dma_thr)
{
	uint32_t localVal = REG_PL_RD(TFU_DMA_THRESHOLD_CONFIG_ADDR);

	*c1_dma_offset = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*img_cal_en = (localVal & ((uint32_t)0x00002000)) >>  13;
	*mask_img_samples = (localVal & ((uint32_t)0x00001000)) >>  12;
	*sample_mode_type = (localVal & ((uint32_t)0x00000800)) >>  11;
	*dma_align_smp_mode_sync_skip = (localVal & ((uint32_t)0x00000400)) >>  10;
	*dmaauto_boundary_align = (localVal & ((uint32_t)0x00000200)) >>  9;
	*immediate_dma_thr_mode = (localVal & ((uint32_t)0x00000100)) >>  8;
	*dma_thr = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint16_t tfu_dma_threshold_config_c_1_dma_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DMA_THRESHOLD_CONFIG_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void tfu_dma_threshold_config_c_1_dma_offset_setf(uint16_t c1dmaoffset)
{
	ASSERT_ERR((((uint32_t)c1dmaoffset << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(TFU_DMA_THRESHOLD_CONFIG_ADDR, (REG_PL_RD(TFU_DMA_THRESHOLD_CONFIG_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)c1dmaoffset <<16));
}
__INLINE uint8_t tfu_dma_threshold_config_img_cal_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DMA_THRESHOLD_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void tfu_dma_threshold_config_img_cal_en_setf(uint8_t imgcalen)
{
	ASSERT_ERR((((uint32_t)imgcalen << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(TFU_DMA_THRESHOLD_CONFIG_ADDR, (REG_PL_RD(TFU_DMA_THRESHOLD_CONFIG_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)imgcalen <<13));
}
__INLINE uint8_t tfu_dma_threshold_config_mask_img_samples_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DMA_THRESHOLD_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void tfu_dma_threshold_config_mask_img_samples_setf(uint8_t maskimgsamples)
{
	ASSERT_ERR((((uint32_t)maskimgsamples << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(TFU_DMA_THRESHOLD_CONFIG_ADDR, (REG_PL_RD(TFU_DMA_THRESHOLD_CONFIG_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)maskimgsamples <<12));
}
__INLINE uint8_t tfu_dma_threshold_config_sample_mode_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DMA_THRESHOLD_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void tfu_dma_threshold_config_sample_mode_type_setf(uint8_t samplemodetype)
{
	ASSERT_ERR((((uint32_t)samplemodetype << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(TFU_DMA_THRESHOLD_CONFIG_ADDR, (REG_PL_RD(TFU_DMA_THRESHOLD_CONFIG_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)samplemodetype <<11));
}
__INLINE uint8_t tfu_dma_threshold_config_dma_align_smp_mode_sync_skip_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DMA_THRESHOLD_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void tfu_dma_threshold_config_dma_align_smp_mode_sync_skip_setf(uint8_t dmaalignsmpmodesyncskip)
{
	ASSERT_ERR((((uint32_t)dmaalignsmpmodesyncskip << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(TFU_DMA_THRESHOLD_CONFIG_ADDR, (REG_PL_RD(TFU_DMA_THRESHOLD_CONFIG_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)dmaalignsmpmodesyncskip <<10));
}
__INLINE uint8_t tfu_dma_threshold_config_dmaauto_boundary_align_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DMA_THRESHOLD_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void tfu_dma_threshold_config_dmaauto_boundary_align_setf(uint8_t dmaautoboundaryalign)
{
	ASSERT_ERR((((uint32_t)dmaautoboundaryalign << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(TFU_DMA_THRESHOLD_CONFIG_ADDR, (REG_PL_RD(TFU_DMA_THRESHOLD_CONFIG_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)dmaautoboundaryalign <<9));
}
__INLINE uint8_t tfu_dma_threshold_config_immediate_dma_thr_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DMA_THRESHOLD_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void tfu_dma_threshold_config_immediate_dma_thr_mode_setf(uint8_t immediatedmathrmode)
{
	ASSERT_ERR((((uint32_t)immediatedmathrmode << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(TFU_DMA_THRESHOLD_CONFIG_ADDR, (REG_PL_RD(TFU_DMA_THRESHOLD_CONFIG_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)immediatedmathrmode <<8));
}
__INLINE uint8_t tfu_dma_threshold_config_dma_thr_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DMA_THRESHOLD_CONFIG_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void tfu_dma_threshold_config_dma_thr_setf(uint8_t dmathr)
{
	ASSERT_ERR((((uint32_t)dmathr << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(TFU_DMA_THRESHOLD_CONFIG_ADDR, (REG_PL_RD(TFU_DMA_THRESHOLD_CONFIG_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)dmathr <<0));
}

/**
 * @brief SYNC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SYNC40                    0x0
 *    15:00 SYNC20                    0x0
 * </pre>
 */
#define TFU_SYNC_ADDR        (REG_TFU_BASE_ADDR+0x00000030)
#define TFU_SYNC_OFFSET      0x00000030
#define TFU_SYNC_INDEX       0x0000000C
#define TFU_SYNC_RESET       0x00000000

__INLINE uint32_t  tfu_sync_get(void)
{
	return REG_PL_RD(TFU_SYNC_ADDR);
}

__INLINE void tfu_sync_set(uint32_t value)
{
	REG_PL_WR(TFU_SYNC_ADDR, value);
}

// field definitions
#define TFU_SYNC_SYNC_40_MASK               ((uint32_t)0xFFFF0000)
#define TFU_SYNC_SYNC_40_LSB                16
#define TFU_SYNC_SYNC_40_WIDTH              ((uint32_t)0x00000010)
#define TFU_SYNC_SYNC_20_MASK               ((uint32_t)0x0000FFFF)
#define TFU_SYNC_SYNC_20_LSB                0
#define TFU_SYNC_SYNC_20_WIDTH              ((uint32_t)0x00000010)

#define TFU_SYNC_SYNC_40_RST                0x0
#define TFU_SYNC_SYNC_20_RST                0x0

__INLINE void tfu_sync_pack(uint16_t sync40, uint16_t sync20)
{
	ASSERT_ERR((((uint32_t)sync40 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)sync20 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(TFU_SYNC_ADDR,  ((uint32_t)sync40 << 16) |((uint32_t)sync20 << 0));
}

__INLINE void tfu_sync_unpack(uint16_t* sync40, uint16_t* sync20)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_ADDR);

	*sync40 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*sync20 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t tfu_sync_sync_40_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void tfu_sync_sync_40_setf(uint16_t sync40)
{
	ASSERT_ERR((((uint32_t)sync40 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(TFU_SYNC_ADDR, (REG_PL_RD(TFU_SYNC_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)sync40 <<16));
}
__INLINE uint16_t tfu_sync_sync_20_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void tfu_sync_sync_20_setf(uint16_t sync20)
{
	ASSERT_ERR((((uint32_t)sync20 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(TFU_SYNC_ADDR, (REG_PL_RD(TFU_SYNC_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)sync20 <<0));
}

/**
 * @brief FFT_IN_OFFSET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    10:00 FFT_IN_OFFSET             0x0
 * </pre>
 */
#define TFU_FFT_IN_OFFSET_ADDR        (REG_TFU_BASE_ADDR+0x00000034)
#define TFU_FFT_IN_OFFSET_OFFSET      0x00000034
#define TFU_FFT_IN_OFFSET_INDEX       0x0000000D
#define TFU_FFT_IN_OFFSET_RESET       0x00000000

__INLINE uint32_t  tfu_fft_in_offset_get(void)
{
	return REG_PL_RD(TFU_FFT_IN_OFFSET_ADDR);
}

__INLINE void tfu_fft_in_offset_set(uint32_t value)
{
	REG_PL_WR(TFU_FFT_IN_OFFSET_ADDR, value);
}

// field definitions
#define TFU_FFT_IN_OFFSET_FFT_IN_OFFSET_MASK    ((uint32_t)0x000007FF)
#define TFU_FFT_IN_OFFSET_FFT_IN_OFFSET_LSB    0
#define TFU_FFT_IN_OFFSET_FFT_IN_OFFSET_WIDTH    ((uint32_t)0x0000000B)

#define TFU_FFT_IN_OFFSET_FFT_IN_OFFSET_RST    0x0

__INLINE uint16_t tfu_fft_in_offset_fft_in_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_FFT_IN_OFFSET_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void tfu_fft_in_offset_fft_in_offset_setf(uint16_t fftinoffset)
{
	ASSERT_ERR((((uint32_t)fftinoffset << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(TFU_FFT_IN_OFFSET_ADDR, (uint32_t)fftinoffset << 0);
}

/**
 * @brief DSP_BUF_0_CIRC_END_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 CIRC_END_ADDR             0xFFFF0000
 * </pre>
 */
#define TFU_DSP_BUF_0_CIRC_END_ADDR_ADDR        (REG_TFU_BASE_ADDR+0x00000038)
#define TFU_DSP_BUF_0_CIRC_END_ADDR_OFFSET      0x00000038
#define TFU_DSP_BUF_0_CIRC_END_ADDR_INDEX       0x0000000E
#define TFU_DSP_BUF_0_CIRC_END_ADDR_RESET       0xFFFF0000

__INLINE uint32_t  tfu_dsp_buf_0_circ_end_addr_get(void)
{
	return REG_PL_RD(TFU_DSP_BUF_0_CIRC_END_ADDR_ADDR);
}

__INLINE void tfu_dsp_buf_0_circ_end_addr_set(uint32_t value)
{
	REG_PL_WR(TFU_DSP_BUF_0_CIRC_END_ADDR_ADDR, value);
}

// field definitions
#define TFU_DSP_BUF_0_CIRC_END_ADDR_CIRC_END_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define TFU_DSP_BUF_0_CIRC_END_ADDR_CIRC_END_ADDR_LSB    0
#define TFU_DSP_BUF_0_CIRC_END_ADDR_CIRC_END_ADDR_WIDTH    ((uint32_t)0x00000020)

#define TFU_DSP_BUF_0_CIRC_END_ADDR_CIRC_END_ADDR_RST    0xFFFF0000

__INLINE uint32_t tfu_dsp_buf_0_circ_end_addr_circ_end_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DSP_BUF_0_CIRC_END_ADDR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void tfu_dsp_buf_0_circ_end_addr_circ_end_addr_setf(uint32_t circendaddr)
{
	ASSERT_ERR((((uint32_t)circendaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(TFU_DSP_BUF_0_CIRC_END_ADDR_ADDR, (uint32_t)circendaddr << 0);
}

/**
 * @brief DMA_GAP register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    10    Sample_Wr_Bugfix_Disable  0              
 *    09:00 RX_DMA_GAP                0x0
 * </pre>
 */
#define TFU_DMA_GAP_ADDR        (REG_TFU_BASE_ADDR+0x0000003C)
#define TFU_DMA_GAP_OFFSET      0x0000003C
#define TFU_DMA_GAP_INDEX       0x0000000F
#define TFU_DMA_GAP_RESET       0x00000000

__INLINE uint32_t  tfu_dma_gap_get(void)
{
	return REG_PL_RD(TFU_DMA_GAP_ADDR);
}

__INLINE void tfu_dma_gap_set(uint32_t value)
{
	REG_PL_WR(TFU_DMA_GAP_ADDR, value);
}

// field definitions
#define TFU_DMA_GAP_SAMPLE_WR_BUGFIX_DISABLE_BIT    ((uint32_t)0x00000400)
#define TFU_DMA_GAP_SAMPLE_WR_BUGFIX_DISABLE_POS    10
#define TFU_DMA_GAP_RX_DMA_GAP_MASK         ((uint32_t)0x000003FF)
#define TFU_DMA_GAP_RX_DMA_GAP_LSB          0
#define TFU_DMA_GAP_RX_DMA_GAP_WIDTH        ((uint32_t)0x0000000A)

#define TFU_DMA_GAP_SAMPLE_WR_BUGFIX_DISABLE_RST    0x0
#define TFU_DMA_GAP_RX_DMA_GAP_RST          0x0

__INLINE void tfu_dma_gap_pack(uint8_t sample_wr_bugfix_disable, uint16_t rx_dma_gap)
{
	ASSERT_ERR((((uint32_t)sample_wr_bugfix_disable << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)rx_dma_gap << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(TFU_DMA_GAP_ADDR,  ((uint32_t)sample_wr_bugfix_disable << 10) |((uint32_t)rx_dma_gap << 0));
}

__INLINE void tfu_dma_gap_unpack(uint8_t* sample_wr_bugfix_disable, uint16_t* rx_dma_gap)
{
	uint32_t localVal = REG_PL_RD(TFU_DMA_GAP_ADDR);

	*sample_wr_bugfix_disable = (localVal & ((uint32_t)0x00000400)) >>  10;
	*rx_dma_gap = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint8_t tfu_dma_gap_sample_wr_bugfix_disable_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DMA_GAP_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void tfu_dma_gap_sample_wr_bugfix_disable_setf(uint8_t samplewrbugfixdisable)
{
	ASSERT_ERR((((uint32_t)samplewrbugfixdisable << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(TFU_DMA_GAP_ADDR, (REG_PL_RD(TFU_DMA_GAP_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)samplewrbugfixdisable <<10));
}
__INLINE uint16_t tfu_dma_gap_rx_dma_gap_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DMA_GAP_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void tfu_dma_gap_rx_dma_gap_setf(uint16_t rxdmagap)
{
	ASSERT_ERR((((uint32_t)rxdmagap << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(TFU_DMA_GAP_ADDR, (REG_PL_RD(TFU_DMA_GAP_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)rxdmagap <<0));
}

/**
 * @brief TX_NB_SYMBOL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    12:00 Tx_Nb_Symbol              0x1fff
 * </pre>
 */
#define TFU_TX_NB_SYMBOL_ADDR        (REG_TFU_BASE_ADDR+0x00000058)
#define TFU_TX_NB_SYMBOL_OFFSET      0x00000058
#define TFU_TX_NB_SYMBOL_INDEX       0x00000016
#define TFU_TX_NB_SYMBOL_RESET       0x00001FFF

__INLINE uint32_t  tfu_tx_nb_symbol_get(void)
{
	return REG_PL_RD(TFU_TX_NB_SYMBOL_ADDR);
}

__INLINE void tfu_tx_nb_symbol_set(uint32_t value)
{
	REG_PL_WR(TFU_TX_NB_SYMBOL_ADDR, value);
}

// field definitions
#define TFU_TX_NB_SYMBOL_TX_NB_SYMBOL_MASK    ((uint32_t)0x00001FFF)
#define TFU_TX_NB_SYMBOL_TX_NB_SYMBOL_LSB    0
#define TFU_TX_NB_SYMBOL_TX_NB_SYMBOL_WIDTH    ((uint32_t)0x0000000D)

#define TFU_TX_NB_SYMBOL_TX_NB_SYMBOL_RST    0x1fff

__INLINE uint16_t tfu_tx_nb_symbol_tx_nb_symbol_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_NB_SYMBOL_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void tfu_tx_nb_symbol_tx_nb_symbol_setf(uint16_t txnbsymbol)
{
	ASSERT_ERR((((uint32_t)txnbsymbol << 0) & ~((uint32_t)0x00001FFF)) == 0);
	REG_PL_WR(TFU_TX_NB_SYMBOL_ADDR, (uint32_t)txnbsymbol << 0);
}

/**
 * @brief RX_NB_SYMBOL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    12:00 Rx_Nb_Symbol              0x1fff
 * </pre>
 */
#define TFU_RX_NB_SYMBOL_ADDR        (REG_TFU_BASE_ADDR+0x0000005C)
#define TFU_RX_NB_SYMBOL_OFFSET      0x0000005C
#define TFU_RX_NB_SYMBOL_INDEX       0x00000017
#define TFU_RX_NB_SYMBOL_RESET       0x00001FFF

__INLINE uint32_t  tfu_rx_nb_symbol_get(void)
{
	return REG_PL_RD(TFU_RX_NB_SYMBOL_ADDR);
}

__INLINE void tfu_rx_nb_symbol_set(uint32_t value)
{
	REG_PL_WR(TFU_RX_NB_SYMBOL_ADDR, value);
}

// field definitions
#define TFU_RX_NB_SYMBOL_RX_NB_SYMBOL_MASK    ((uint32_t)0x00001FFF)
#define TFU_RX_NB_SYMBOL_RX_NB_SYMBOL_LSB    0
#define TFU_RX_NB_SYMBOL_RX_NB_SYMBOL_WIDTH    ((uint32_t)0x0000000D)

#define TFU_RX_NB_SYMBOL_RX_NB_SYMBOL_RST    0x1fff

__INLINE uint16_t tfu_rx_nb_symbol_rx_nb_symbol_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_RX_NB_SYMBOL_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void tfu_rx_nb_symbol_rx_nb_symbol_setf(uint16_t rxnbsymbol)
{
	ASSERT_ERR((((uint32_t)rxnbsymbol << 0) & ~((uint32_t)0x00001FFF)) == 0);
	REG_PL_WR(TFU_RX_NB_SYMBOL_ADDR, (uint32_t)rxnbsymbol << 0);
}

/**
 * @brief TXMEM_PTR_0 register definition
 *  Pointer to Tx symbol buffer 0  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 TXMEM_PTR_0               0x0
 * </pre>
 */
#define TFU_TXMEM_PTR_0_ADDR        (REG_TFU_BASE_ADDR+0x00000064)
#define TFU_TXMEM_PTR_0_OFFSET      0x00000064
#define TFU_TXMEM_PTR_0_INDEX       0x00000019
#define TFU_TXMEM_PTR_0_RESET       0x00000000

__INLINE uint32_t  tfu_txmem_ptr_0_get(void)
{
	return REG_PL_RD(TFU_TXMEM_PTR_0_ADDR);
}

__INLINE void tfu_txmem_ptr_0_set(uint32_t value)
{
	REG_PL_WR(TFU_TXMEM_PTR_0_ADDR, value);
}

// field definitions
#define TFU_TXMEM_PTR_0_TXMEM_PTR_0_MASK    ((uint32_t)0xFFFFFFFC)
#define TFU_TXMEM_PTR_0_TXMEM_PTR_0_LSB     2
#define TFU_TXMEM_PTR_0_TXMEM_PTR_0_WIDTH    ((uint32_t)0x0000001E)

#define TFU_TXMEM_PTR_0_TXMEM_PTR_0_RST     0x0

__INLINE uint32_t tfu_txmem_ptr_0_txmem_ptr_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_TXMEM_PTR_0_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void tfu_txmem_ptr_0_txmem_ptr_0_setf(uint32_t txmemptr0)
{
	ASSERT_ERR((((uint32_t)txmemptr0 << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(TFU_TXMEM_PTR_0_ADDR, (uint32_t)txmemptr0 << 2);
}

/**
 * @brief TXMEM_PTR_1 register definition
 *  Pointer to Tx symbol buffer 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 TXMEM_PTR_1               0x0
 * </pre>
 */
#define TFU_TXMEM_PTR_1_ADDR        (REG_TFU_BASE_ADDR+0x00000068)
#define TFU_TXMEM_PTR_1_OFFSET      0x00000068
#define TFU_TXMEM_PTR_1_INDEX       0x0000001A
#define TFU_TXMEM_PTR_1_RESET       0x00000000

__INLINE uint32_t  tfu_txmem_ptr_1_get(void)
{
	return REG_PL_RD(TFU_TXMEM_PTR_1_ADDR);
}

__INLINE void tfu_txmem_ptr_1_set(uint32_t value)
{
	REG_PL_WR(TFU_TXMEM_PTR_1_ADDR, value);
}

// field definitions
#define TFU_TXMEM_PTR_1_TXMEM_PTR_1_MASK    ((uint32_t)0xFFFFFFFC)
#define TFU_TXMEM_PTR_1_TXMEM_PTR_1_LSB     2
#define TFU_TXMEM_PTR_1_TXMEM_PTR_1_WIDTH    ((uint32_t)0x0000001E)

#define TFU_TXMEM_PTR_1_TXMEM_PTR_1_RST     0x0

__INLINE uint32_t tfu_txmem_ptr_1_txmem_ptr_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_TXMEM_PTR_1_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void tfu_txmem_ptr_1_txmem_ptr_1_setf(uint32_t txmemptr1)
{
	ASSERT_ERR((((uint32_t)txmemptr1 << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(TFU_TXMEM_PTR_1_ADDR, (uint32_t)txmemptr1 << 2);
}

/**
 * @brief TXMEM_PTR_2 register definition
 *  Pointer to Tx symbol buffer 2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 TXMEM_PTR_2               0x0
 * </pre>
 */
#define TFU_TXMEM_PTR_2_ADDR        (REG_TFU_BASE_ADDR+0x0000006C)
#define TFU_TXMEM_PTR_2_OFFSET      0x0000006C
#define TFU_TXMEM_PTR_2_INDEX       0x0000001B
#define TFU_TXMEM_PTR_2_RESET       0x00000000

__INLINE uint32_t  tfu_txmem_ptr_2_get(void)
{
	return REG_PL_RD(TFU_TXMEM_PTR_2_ADDR);
}

__INLINE void tfu_txmem_ptr_2_set(uint32_t value)
{
	REG_PL_WR(TFU_TXMEM_PTR_2_ADDR, value);
}

// field definitions
#define TFU_TXMEM_PTR_2_TXMEM_PTR_2_MASK    ((uint32_t)0xFFFFFFFC)
#define TFU_TXMEM_PTR_2_TXMEM_PTR_2_LSB     2
#define TFU_TXMEM_PTR_2_TXMEM_PTR_2_WIDTH    ((uint32_t)0x0000001E)

#define TFU_TXMEM_PTR_2_TXMEM_PTR_2_RST     0x0

__INLINE uint32_t tfu_txmem_ptr_2_txmem_ptr_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_TXMEM_PTR_2_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void tfu_txmem_ptr_2_txmem_ptr_2_setf(uint32_t txmemptr2)
{
	ASSERT_ERR((((uint32_t)txmemptr2 << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(TFU_TXMEM_PTR_2_ADDR, (uint32_t)txmemptr2 << 2);
}

/**
 * @brief TXMEM_PTR_3 register definition
 *  Pointer to Tx symbol buffer 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 TXMEM_PTR_3               0x0
 * </pre>
 */
#define TFU_TXMEM_PTR_3_ADDR        (REG_TFU_BASE_ADDR+0x00000070)
#define TFU_TXMEM_PTR_3_OFFSET      0x00000070
#define TFU_TXMEM_PTR_3_INDEX       0x0000001C
#define TFU_TXMEM_PTR_3_RESET       0x00000000

__INLINE uint32_t  tfu_txmem_ptr_3_get(void)
{
	return REG_PL_RD(TFU_TXMEM_PTR_3_ADDR);
}

__INLINE void tfu_txmem_ptr_3_set(uint32_t value)
{
	REG_PL_WR(TFU_TXMEM_PTR_3_ADDR, value);
}

// field definitions
#define TFU_TXMEM_PTR_3_TXMEM_PTR_3_MASK    ((uint32_t)0xFFFFFFFC)
#define TFU_TXMEM_PTR_3_TXMEM_PTR_3_LSB     2
#define TFU_TXMEM_PTR_3_TXMEM_PTR_3_WIDTH    ((uint32_t)0x0000001E)

#define TFU_TXMEM_PTR_3_TXMEM_PTR_3_RST     0x0

__INLINE uint32_t tfu_txmem_ptr_3_txmem_ptr_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_TXMEM_PTR_3_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void tfu_txmem_ptr_3_txmem_ptr_3_setf(uint32_t txmemptr3)
{
	ASSERT_ERR((((uint32_t)txmemptr3 << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(TFU_TXMEM_PTR_3_ADDR, (uint32_t)txmemptr3 << 2);
}

/**
 * @brief TX_FREQ_OFFSET register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    TX_LAST_SYMB_MSG_EN       0              
 *    28:24 TX_UNDERUN_CHK_SETUP      0x0
 *    22    TX_FO_ENABLE              0              
 *    20:00 TX_FREQ_OFFSET            0x0
 * </pre>
 */
#define TFU_TX_FREQ_OFFSET_ADDR        (REG_TFU_BASE_ADDR+0x00000078)
#define TFU_TX_FREQ_OFFSET_OFFSET      0x00000078
#define TFU_TX_FREQ_OFFSET_INDEX       0x0000001E
#define TFU_TX_FREQ_OFFSET_RESET       0x00000000

__INLINE uint32_t  tfu_tx_freq_offset_get(void)
{
	return REG_PL_RD(TFU_TX_FREQ_OFFSET_ADDR);
}

__INLINE void tfu_tx_freq_offset_set(uint32_t value)
{
	REG_PL_WR(TFU_TX_FREQ_OFFSET_ADDR, value);
}

// field definitions
#define TFU_TX_FREQ_OFFSET_TX_LAST_SYMB_MSG_EN_BIT    ((uint32_t)0x80000000)
#define TFU_TX_FREQ_OFFSET_TX_LAST_SYMB_MSG_EN_POS    31
#define TFU_TX_FREQ_OFFSET_TX_UNDERUN_CHK_SETUP_MASK    ((uint32_t)0x1F000000)
#define TFU_TX_FREQ_OFFSET_TX_UNDERUN_CHK_SETUP_LSB    24
#define TFU_TX_FREQ_OFFSET_TX_UNDERUN_CHK_SETUP_WIDTH    ((uint32_t)0x00000005)
#define TFU_TX_FREQ_OFFSET_TX_FO_ENABLE_BIT    ((uint32_t)0x00400000)
#define TFU_TX_FREQ_OFFSET_TX_FO_ENABLE_POS    22
#define TFU_TX_FREQ_OFFSET_TX_FREQ_OFFSET_MASK    ((uint32_t)0x001FFFFF)
#define TFU_TX_FREQ_OFFSET_TX_FREQ_OFFSET_LSB    0
#define TFU_TX_FREQ_OFFSET_TX_FREQ_OFFSET_WIDTH    ((uint32_t)0x00000015)

#define TFU_TX_FREQ_OFFSET_TX_LAST_SYMB_MSG_EN_RST    0x0
#define TFU_TX_FREQ_OFFSET_TX_UNDERUN_CHK_SETUP_RST    0x0
#define TFU_TX_FREQ_OFFSET_TX_FO_ENABLE_RST    0x0
#define TFU_TX_FREQ_OFFSET_TX_FREQ_OFFSET_RST    0x0

__INLINE void tfu_tx_freq_offset_pack(uint8_t tx_last_symb_msg_en, uint8_t tx_underun_chk_setup, uint8_t tx_fo_enable, uint32_t tx_freq_offset)
{
	ASSERT_ERR((((uint32_t)tx_last_symb_msg_en << 31) & ~((uint32_t)0x80000000)) == 0);
	ASSERT_ERR((((uint32_t)tx_underun_chk_setup << 24) & ~((uint32_t)0x1F000000)) == 0);
	ASSERT_ERR((((uint32_t)tx_fo_enable << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)tx_freq_offset << 0) & ~((uint32_t)0x001FFFFF)) == 0);
	REG_PL_WR(TFU_TX_FREQ_OFFSET_ADDR,  ((uint32_t)tx_last_symb_msg_en << 31) |((uint32_t)tx_underun_chk_setup << 24) |((uint32_t)tx_fo_enable << 22) |((uint32_t)tx_freq_offset << 0));
}

__INLINE void tfu_tx_freq_offset_unpack(uint8_t* tx_last_symb_msg_en, uint8_t* tx_underun_chk_setup, uint8_t* tx_fo_enable, uint32_t* tx_freq_offset)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_FREQ_OFFSET_ADDR);

	*tx_last_symb_msg_en = (localVal & ((uint32_t)0x80000000)) >>  31;
	*tx_underun_chk_setup = (localVal & ((uint32_t)0x1F000000)) >>  24;
	*tx_fo_enable = (localVal & ((uint32_t)0x00400000)) >>  22;
	*tx_freq_offset = (localVal & ((uint32_t)0x001FFFFF)) >>  0;
}

__INLINE uint8_t tfu_tx_freq_offset_tx_last_symb_msg_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_FREQ_OFFSET_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x80000000)) >> 31);
}
__INLINE void tfu_tx_freq_offset_tx_last_symb_msg_en_setf(uint8_t txlastsymbmsgen)
{
	ASSERT_ERR((((uint32_t)txlastsymbmsgen << 31) & ~((uint32_t)0x80000000)) == 0);
	REG_PL_WR(TFU_TX_FREQ_OFFSET_ADDR, (REG_PL_RD(TFU_TX_FREQ_OFFSET_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)txlastsymbmsgen <<31));
}
__INLINE uint8_t tfu_tx_freq_offset_tx_underun_chk_setup_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_FREQ_OFFSET_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x1F000000)) >> 24);
}
__INLINE void tfu_tx_freq_offset_tx_underun_chk_setup_setf(uint8_t txunderunchksetup)
{
	ASSERT_ERR((((uint32_t)txunderunchksetup << 24) & ~((uint32_t)0x1F000000)) == 0);
	REG_PL_WR(TFU_TX_FREQ_OFFSET_ADDR, (REG_PL_RD(TFU_TX_FREQ_OFFSET_ADDR) & ~((uint32_t)0x1F000000)) | ((uint32_t)txunderunchksetup <<24));
}
__INLINE uint8_t tfu_tx_freq_offset_tx_fo_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_FREQ_OFFSET_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE void tfu_tx_freq_offset_tx_fo_enable_setf(uint8_t txfoenable)
{
	ASSERT_ERR((((uint32_t)txfoenable << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(TFU_TX_FREQ_OFFSET_ADDR, (REG_PL_RD(TFU_TX_FREQ_OFFSET_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)txfoenable <<22));
}
__INLINE uint32_t tfu_tx_freq_offset_tx_freq_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_FREQ_OFFSET_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0x001FFFFF)) >> 0);
}
__INLINE void tfu_tx_freq_offset_tx_freq_offset_setf(uint32_t txfreqoffset)
{
	ASSERT_ERR((((uint32_t)txfreqoffset << 0) & ~((uint32_t)0x001FFFFF)) == 0);
	REG_PL_WR(TFU_TX_FREQ_OFFSET_ADDR, (REG_PL_RD(TFU_TX_FREQ_OFFSET_ADDR) & ~((uint32_t)0x001FFFFF)) | ((uint32_t)txfreqoffset <<0));
}

/**
 * @brief STATUS_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 MCCI_CNT                  0x0
 *    23:16 TX_FFT_SHIFT_CNT          0x0
 *    15:08 RX_FFT_SHIFT_CNT          0x0
 *    04    TX_DATA_UNDERRUN          0              
 *    03    RX_HE_FFT_SHIFT_INPROGRESS 0              
 *    02    RX_FFT256_SHIFT_INPROGRESS 0              
 *    01    RX_FFT128_SHIFT_INPROGRESS 0              
 *    00    RX_FFT64_SHIFT_INPROGRESS 0              
 * </pre>
 */
#define TFU_STATUS_2_ADDR        (REG_TFU_BASE_ADDR+0x0000007C)
#define TFU_STATUS_2_OFFSET      0x0000007C
#define TFU_STATUS_2_INDEX       0x0000001F
#define TFU_STATUS_2_RESET       0x00000000

__INLINE uint32_t  tfu_status_2_get(void)
{
	return REG_PL_RD(TFU_STATUS_2_ADDR);
}

// field definitions
#define TFU_STATUS_2_MCCI_CNT_MASK          ((uint32_t)0xFF000000)
#define TFU_STATUS_2_MCCI_CNT_LSB           24
#define TFU_STATUS_2_MCCI_CNT_WIDTH         ((uint32_t)0x00000008)
#define TFU_STATUS_2_TX_FFT_SHIFT_CNT_MASK    ((uint32_t)0x00FF0000)
#define TFU_STATUS_2_TX_FFT_SHIFT_CNT_LSB    16
#define TFU_STATUS_2_TX_FFT_SHIFT_CNT_WIDTH    ((uint32_t)0x00000008)
#define TFU_STATUS_2_RX_FFT_SHIFT_CNT_MASK    ((uint32_t)0x0000FF00)
#define TFU_STATUS_2_RX_FFT_SHIFT_CNT_LSB    8
#define TFU_STATUS_2_RX_FFT_SHIFT_CNT_WIDTH    ((uint32_t)0x00000008)
#define TFU_STATUS_2_TX_DATA_UNDERRUN_BIT    ((uint32_t)0x00000010)
#define TFU_STATUS_2_TX_DATA_UNDERRUN_POS    4
#define TFU_STATUS_2_RX_HE_FFT_SHIFT_INPROGRESS_BIT    ((uint32_t)0x00000008)
#define TFU_STATUS_2_RX_HE_FFT_SHIFT_INPROGRESS_POS    3
#define TFU_STATUS_2_RX_FFT_256_SHIFT_INPROGRESS_BIT    ((uint32_t)0x00000004)
#define TFU_STATUS_2_RX_FFT_256_SHIFT_INPROGRESS_POS    2
#define TFU_STATUS_2_RX_FFT_128_SHIFT_INPROGRESS_BIT    ((uint32_t)0x00000002)
#define TFU_STATUS_2_RX_FFT_128_SHIFT_INPROGRESS_POS    1
#define TFU_STATUS_2_RX_FFT_64_SHIFT_INPROGRESS_BIT    ((uint32_t)0x00000001)
#define TFU_STATUS_2_RX_FFT_64_SHIFT_INPROGRESS_POS    0

#define TFU_STATUS_2_MCCI_CNT_RST           0x0
#define TFU_STATUS_2_TX_FFT_SHIFT_CNT_RST    0x0
#define TFU_STATUS_2_RX_FFT_SHIFT_CNT_RST    0x0
#define TFU_STATUS_2_TX_DATA_UNDERRUN_RST    0x0
#define TFU_STATUS_2_RX_HE_FFT_SHIFT_INPROGRESS_RST    0x0
#define TFU_STATUS_2_RX_FFT_256_SHIFT_INPROGRESS_RST    0x0
#define TFU_STATUS_2_RX_FFT_128_SHIFT_INPROGRESS_RST    0x0
#define TFU_STATUS_2_RX_FFT_64_SHIFT_INPROGRESS_RST    0x0

__INLINE void tfu_status_2_unpack(uint8_t* mcci_cnt, uint8_t* tx_fft_shift_cnt, uint8_t* rx_fft_shift_cnt, uint8_t* tx_data_underrun, uint8_t* rx_he_fft_shift_inprogress, uint8_t* rx_fft256_shift_inprogress, uint8_t* rx_fft128_shift_inprogress, uint8_t* rx_fft64_shift_inprogress)
{
	uint32_t localVal = REG_PL_RD(TFU_STATUS_2_ADDR);

	*mcci_cnt = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*tx_fft_shift_cnt = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*rx_fft_shift_cnt = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*tx_data_underrun = (localVal & ((uint32_t)0x00000010)) >>  4;
	*rx_he_fft_shift_inprogress = (localVal & ((uint32_t)0x00000008)) >>  3;
	*rx_fft256_shift_inprogress = (localVal & ((uint32_t)0x00000004)) >>  2;
	*rx_fft128_shift_inprogress = (localVal & ((uint32_t)0x00000002)) >>  1;
	*rx_fft64_shift_inprogress = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t tfu_status_2_mcci_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATUS_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE uint8_t tfu_status_2_tx_fft_shift_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATUS_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE uint8_t tfu_status_2_rx_fft_shift_cnt_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATUS_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE uint8_t tfu_status_2_tx_data_underrun_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATUS_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t tfu_status_2_rx_he_fft_shift_inprogress_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATUS_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t tfu_status_2_rx_fft_256_shift_inprogress_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATUS_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t tfu_status_2_rx_fft_128_shift_inprogress_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATUS_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t tfu_status_2_rx_fft_64_shift_inprogress_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATUS_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief SYNC_GI_20 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 SYNC20_GI32               0x0
 *    23:16 SYNC20_GI16               0x0
 *    15:08 SYNC20_GI08               0x0
 *    07:00 SYNC20_GI04               0x0
 * </pre>
 */
#define TFU_SYNC_GI_20_ADDR        (REG_TFU_BASE_ADDR+0x00000080)
#define TFU_SYNC_GI_20_OFFSET      0x00000080
#define TFU_SYNC_GI_20_INDEX       0x00000020
#define TFU_SYNC_GI_20_RESET       0x00000000

__INLINE uint32_t  tfu_sync_gi_20_get(void)
{
	return REG_PL_RD(TFU_SYNC_GI_20_ADDR);
}

__INLINE void tfu_sync_gi_20_set(uint32_t value)
{
	REG_PL_WR(TFU_SYNC_GI_20_ADDR, value);
}

// field definitions
#define TFU_SYNC_GI_20_SYNC_20_GI_32_MASK    ((uint32_t)0xFF000000)
#define TFU_SYNC_GI_20_SYNC_20_GI_32_LSB    24
#define TFU_SYNC_GI_20_SYNC_20_GI_32_WIDTH    ((uint32_t)0x00000008)
#define TFU_SYNC_GI_20_SYNC_20_GI_16_MASK    ((uint32_t)0x00FF0000)
#define TFU_SYNC_GI_20_SYNC_20_GI_16_LSB    16
#define TFU_SYNC_GI_20_SYNC_20_GI_16_WIDTH    ((uint32_t)0x00000008)
#define TFU_SYNC_GI_20_SYNC_20_GI_08_MASK    ((uint32_t)0x0000FF00)
#define TFU_SYNC_GI_20_SYNC_20_GI_08_LSB    8
#define TFU_SYNC_GI_20_SYNC_20_GI_08_WIDTH    ((uint32_t)0x00000008)
#define TFU_SYNC_GI_20_SYNC_20_GI_04_MASK    ((uint32_t)0x000000FF)
#define TFU_SYNC_GI_20_SYNC_20_GI_04_LSB    0
#define TFU_SYNC_GI_20_SYNC_20_GI_04_WIDTH    ((uint32_t)0x00000008)

#define TFU_SYNC_GI_20_SYNC_20_GI_32_RST    0x0
#define TFU_SYNC_GI_20_SYNC_20_GI_16_RST    0x0
#define TFU_SYNC_GI_20_SYNC_20_GI_08_RST    0x0
#define TFU_SYNC_GI_20_SYNC_20_GI_04_RST    0x0

__INLINE void tfu_sync_gi_20_pack(uint8_t sync20_gi32, uint8_t sync20_gi16, uint8_t sync20_gi08, uint8_t sync20_gi04)
{
	ASSERT_ERR((((uint32_t)sync20_gi32 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)sync20_gi16 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)sync20_gi08 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)sync20_gi04 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(TFU_SYNC_GI_20_ADDR,  ((uint32_t)sync20_gi32 << 24) |((uint32_t)sync20_gi16 << 16) |((uint32_t)sync20_gi08 << 8) |((uint32_t)sync20_gi04 << 0));
}

__INLINE void tfu_sync_gi_20_unpack(uint8_t* sync20_gi32, uint8_t* sync20_gi16, uint8_t* sync20_gi08, uint8_t* sync20_gi04)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_20_ADDR);

	*sync20_gi32 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*sync20_gi16 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*sync20_gi08 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*sync20_gi04 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t tfu_sync_gi_20_sync_20_gi_32_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void tfu_sync_gi_20_sync_20_gi_32_setf(uint8_t sync20gi32)
{
	ASSERT_ERR((((uint32_t)sync20gi32 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(TFU_SYNC_GI_20_ADDR, (REG_PL_RD(TFU_SYNC_GI_20_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)sync20gi32 <<24));
}
__INLINE uint8_t tfu_sync_gi_20_sync_20_gi_16_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void tfu_sync_gi_20_sync_20_gi_16_setf(uint8_t sync20gi16)
{
	ASSERT_ERR((((uint32_t)sync20gi16 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(TFU_SYNC_GI_20_ADDR, (REG_PL_RD(TFU_SYNC_GI_20_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)sync20gi16 <<16));
}
__INLINE uint8_t tfu_sync_gi_20_sync_20_gi_08_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void tfu_sync_gi_20_sync_20_gi_08_setf(uint8_t sync20gi08)
{
	ASSERT_ERR((((uint32_t)sync20gi08 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(TFU_SYNC_GI_20_ADDR, (REG_PL_RD(TFU_SYNC_GI_20_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)sync20gi08 <<8));
}
__INLINE uint8_t tfu_sync_gi_20_sync_20_gi_04_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void tfu_sync_gi_20_sync_20_gi_04_setf(uint8_t sync20gi04)
{
	ASSERT_ERR((((uint32_t)sync20gi04 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(TFU_SYNC_GI_20_ADDR, (REG_PL_RD(TFU_SYNC_GI_20_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)sync20gi04 <<0));
}

/**
 * @brief SYNC_GI_40 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 SYNC40_GI32               0x0
 *    23:16 SYNC40_GI16               0x0
 *    15:08 SYNC40_GI08               0x0
 *    07:00 SYNC40_GI04               0x0
 * </pre>
 */
#define TFU_SYNC_GI_40_ADDR        (REG_TFU_BASE_ADDR+0x00000084)
#define TFU_SYNC_GI_40_OFFSET      0x00000084
#define TFU_SYNC_GI_40_INDEX       0x00000021
#define TFU_SYNC_GI_40_RESET       0x00000000

__INLINE uint32_t  tfu_sync_gi_40_get(void)
{
	return REG_PL_RD(TFU_SYNC_GI_40_ADDR);
}

__INLINE void tfu_sync_gi_40_set(uint32_t value)
{
	REG_PL_WR(TFU_SYNC_GI_40_ADDR, value);
}

// field definitions
#define TFU_SYNC_GI_40_SYNC_40_GI_32_MASK    ((uint32_t)0xFF000000)
#define TFU_SYNC_GI_40_SYNC_40_GI_32_LSB    24
#define TFU_SYNC_GI_40_SYNC_40_GI_32_WIDTH    ((uint32_t)0x00000008)
#define TFU_SYNC_GI_40_SYNC_40_GI_16_MASK    ((uint32_t)0x00FF0000)
#define TFU_SYNC_GI_40_SYNC_40_GI_16_LSB    16
#define TFU_SYNC_GI_40_SYNC_40_GI_16_WIDTH    ((uint32_t)0x00000008)
#define TFU_SYNC_GI_40_SYNC_40_GI_08_MASK    ((uint32_t)0x0000FF00)
#define TFU_SYNC_GI_40_SYNC_40_GI_08_LSB    8
#define TFU_SYNC_GI_40_SYNC_40_GI_08_WIDTH    ((uint32_t)0x00000008)
#define TFU_SYNC_GI_40_SYNC_40_GI_04_MASK    ((uint32_t)0x000000FF)
#define TFU_SYNC_GI_40_SYNC_40_GI_04_LSB    0
#define TFU_SYNC_GI_40_SYNC_40_GI_04_WIDTH    ((uint32_t)0x00000008)

#define TFU_SYNC_GI_40_SYNC_40_GI_32_RST    0x0
#define TFU_SYNC_GI_40_SYNC_40_GI_16_RST    0x0
#define TFU_SYNC_GI_40_SYNC_40_GI_08_RST    0x0
#define TFU_SYNC_GI_40_SYNC_40_GI_04_RST    0x0

__INLINE void tfu_sync_gi_40_pack(uint8_t sync40_gi32, uint8_t sync40_gi16, uint8_t sync40_gi08, uint8_t sync40_gi04)
{
	ASSERT_ERR((((uint32_t)sync40_gi32 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)sync40_gi16 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)sync40_gi08 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)sync40_gi04 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(TFU_SYNC_GI_40_ADDR,  ((uint32_t)sync40_gi32 << 24) |((uint32_t)sync40_gi16 << 16) |((uint32_t)sync40_gi08 << 8) |((uint32_t)sync40_gi04 << 0));
}

__INLINE void tfu_sync_gi_40_unpack(uint8_t* sync40_gi32, uint8_t* sync40_gi16, uint8_t* sync40_gi08, uint8_t* sync40_gi04)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_40_ADDR);

	*sync40_gi32 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*sync40_gi16 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*sync40_gi08 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*sync40_gi04 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t tfu_sync_gi_40_sync_40_gi_32_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_40_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void tfu_sync_gi_40_sync_40_gi_32_setf(uint8_t sync40gi32)
{
	ASSERT_ERR((((uint32_t)sync40gi32 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(TFU_SYNC_GI_40_ADDR, (REG_PL_RD(TFU_SYNC_GI_40_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)sync40gi32 <<24));
}
__INLINE uint8_t tfu_sync_gi_40_sync_40_gi_16_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_40_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void tfu_sync_gi_40_sync_40_gi_16_setf(uint8_t sync40gi16)
{
	ASSERT_ERR((((uint32_t)sync40gi16 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(TFU_SYNC_GI_40_ADDR, (REG_PL_RD(TFU_SYNC_GI_40_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)sync40gi16 <<16));
}
__INLINE uint8_t tfu_sync_gi_40_sync_40_gi_08_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_40_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void tfu_sync_gi_40_sync_40_gi_08_setf(uint8_t sync40gi08)
{
	ASSERT_ERR((((uint32_t)sync40gi08 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(TFU_SYNC_GI_40_ADDR, (REG_PL_RD(TFU_SYNC_GI_40_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)sync40gi08 <<8));
}
__INLINE uint8_t tfu_sync_gi_40_sync_40_gi_04_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_40_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void tfu_sync_gi_40_sync_40_gi_04_setf(uint8_t sync40gi04)
{
	ASSERT_ERR((((uint32_t)sync40gi04 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(TFU_SYNC_GI_40_ADDR, (REG_PL_RD(TFU_SYNC_GI_40_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)sync40gi04 <<0));
}

/**
 * @brief SYNC_GI_80 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 SYNC80_GI32               0x0
 *    23:16 SYNC80_GI16               0x0
 *    15:08 SYNC80_GI08               0x0
 *    07:00 SYNC80_GI04               0x0
 * </pre>
 */
#define TFU_SYNC_GI_80_ADDR        (REG_TFU_BASE_ADDR+0x00000088)
#define TFU_SYNC_GI_80_OFFSET      0x00000088
#define TFU_SYNC_GI_80_INDEX       0x00000022
#define TFU_SYNC_GI_80_RESET       0x00000000

__INLINE uint32_t  tfu_sync_gi_80_get(void)
{
	return REG_PL_RD(TFU_SYNC_GI_80_ADDR);
}

__INLINE void tfu_sync_gi_80_set(uint32_t value)
{
	REG_PL_WR(TFU_SYNC_GI_80_ADDR, value);
}

// field definitions
#define TFU_SYNC_GI_80_SYNC_80_GI_32_MASK    ((uint32_t)0xFF000000)
#define TFU_SYNC_GI_80_SYNC_80_GI_32_LSB    24
#define TFU_SYNC_GI_80_SYNC_80_GI_32_WIDTH    ((uint32_t)0x00000008)
#define TFU_SYNC_GI_80_SYNC_80_GI_16_MASK    ((uint32_t)0x00FF0000)
#define TFU_SYNC_GI_80_SYNC_80_GI_16_LSB    16
#define TFU_SYNC_GI_80_SYNC_80_GI_16_WIDTH    ((uint32_t)0x00000008)
#define TFU_SYNC_GI_80_SYNC_80_GI_08_MASK    ((uint32_t)0x0000FF00)
#define TFU_SYNC_GI_80_SYNC_80_GI_08_LSB    8
#define TFU_SYNC_GI_80_SYNC_80_GI_08_WIDTH    ((uint32_t)0x00000008)
#define TFU_SYNC_GI_80_SYNC_80_GI_04_MASK    ((uint32_t)0x000000FF)
#define TFU_SYNC_GI_80_SYNC_80_GI_04_LSB    0
#define TFU_SYNC_GI_80_SYNC_80_GI_04_WIDTH    ((uint32_t)0x00000008)

#define TFU_SYNC_GI_80_SYNC_80_GI_32_RST    0x0
#define TFU_SYNC_GI_80_SYNC_80_GI_16_RST    0x0
#define TFU_SYNC_GI_80_SYNC_80_GI_08_RST    0x0
#define TFU_SYNC_GI_80_SYNC_80_GI_04_RST    0x0

__INLINE void tfu_sync_gi_80_pack(uint8_t sync80_gi32, uint8_t sync80_gi16, uint8_t sync80_gi08, uint8_t sync80_gi04)
{
	ASSERT_ERR((((uint32_t)sync80_gi32 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)sync80_gi16 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)sync80_gi08 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)sync80_gi04 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(TFU_SYNC_GI_80_ADDR,  ((uint32_t)sync80_gi32 << 24) |((uint32_t)sync80_gi16 << 16) |((uint32_t)sync80_gi08 << 8) |((uint32_t)sync80_gi04 << 0));
}

__INLINE void tfu_sync_gi_80_unpack(uint8_t* sync80_gi32, uint8_t* sync80_gi16, uint8_t* sync80_gi08, uint8_t* sync80_gi04)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_80_ADDR);

	*sync80_gi32 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*sync80_gi16 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*sync80_gi08 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*sync80_gi04 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t tfu_sync_gi_80_sync_80_gi_32_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_80_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void tfu_sync_gi_80_sync_80_gi_32_setf(uint8_t sync80gi32)
{
	ASSERT_ERR((((uint32_t)sync80gi32 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(TFU_SYNC_GI_80_ADDR, (REG_PL_RD(TFU_SYNC_GI_80_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)sync80gi32 <<24));
}
__INLINE uint8_t tfu_sync_gi_80_sync_80_gi_16_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_80_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void tfu_sync_gi_80_sync_80_gi_16_setf(uint8_t sync80gi16)
{
	ASSERT_ERR((((uint32_t)sync80gi16 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(TFU_SYNC_GI_80_ADDR, (REG_PL_RD(TFU_SYNC_GI_80_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)sync80gi16 <<16));
}
__INLINE uint8_t tfu_sync_gi_80_sync_80_gi_08_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_80_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void tfu_sync_gi_80_sync_80_gi_08_setf(uint8_t sync80gi08)
{
	ASSERT_ERR((((uint32_t)sync80gi08 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(TFU_SYNC_GI_80_ADDR, (REG_PL_RD(TFU_SYNC_GI_80_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)sync80gi08 <<8));
}
__INLINE uint8_t tfu_sync_gi_80_sync_80_gi_04_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_80_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void tfu_sync_gi_80_sync_80_gi_04_setf(uint8_t sync80gi04)
{
	ASSERT_ERR((((uint32_t)sync80gi04 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(TFU_SYNC_GI_80_ADDR, (REG_PL_RD(TFU_SYNC_GI_80_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)sync80gi04 <<0));
}

/**
 * @brief SYNC_GI_160 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 SYNC160_GI32              0x0
 *    23:16 SYNC160_GI16              0x0
 *    15:08 SYNC160_GI08              0x0
 *    07:00 SYNC160_GI04              0x0
 * </pre>
 */
#define TFU_SYNC_GI_160_ADDR        (REG_TFU_BASE_ADDR+0x0000008C)
#define TFU_SYNC_GI_160_OFFSET      0x0000008C
#define TFU_SYNC_GI_160_INDEX       0x00000023
#define TFU_SYNC_GI_160_RESET       0x00000000

__INLINE uint32_t  tfu_sync_gi_160_get(void)
{
	return REG_PL_RD(TFU_SYNC_GI_160_ADDR);
}

__INLINE void tfu_sync_gi_160_set(uint32_t value)
{
	REG_PL_WR(TFU_SYNC_GI_160_ADDR, value);
}

// field definitions
#define TFU_SYNC_GI_160_SYNC_160_GI_32_MASK    ((uint32_t)0xFF000000)
#define TFU_SYNC_GI_160_SYNC_160_GI_32_LSB    24
#define TFU_SYNC_GI_160_SYNC_160_GI_32_WIDTH    ((uint32_t)0x00000008)
#define TFU_SYNC_GI_160_SYNC_160_GI_16_MASK    ((uint32_t)0x00FF0000)
#define TFU_SYNC_GI_160_SYNC_160_GI_16_LSB    16
#define TFU_SYNC_GI_160_SYNC_160_GI_16_WIDTH    ((uint32_t)0x00000008)
#define TFU_SYNC_GI_160_SYNC_160_GI_08_MASK    ((uint32_t)0x0000FF00)
#define TFU_SYNC_GI_160_SYNC_160_GI_08_LSB    8
#define TFU_SYNC_GI_160_SYNC_160_GI_08_WIDTH    ((uint32_t)0x00000008)
#define TFU_SYNC_GI_160_SYNC_160_GI_04_MASK    ((uint32_t)0x000000FF)
#define TFU_SYNC_GI_160_SYNC_160_GI_04_LSB    0
#define TFU_SYNC_GI_160_SYNC_160_GI_04_WIDTH    ((uint32_t)0x00000008)

#define TFU_SYNC_GI_160_SYNC_160_GI_32_RST    0x0
#define TFU_SYNC_GI_160_SYNC_160_GI_16_RST    0x0
#define TFU_SYNC_GI_160_SYNC_160_GI_08_RST    0x0
#define TFU_SYNC_GI_160_SYNC_160_GI_04_RST    0x0

__INLINE void tfu_sync_gi_160_pack(uint8_t sync160_gi32, uint8_t sync160_gi16, uint8_t sync160_gi08, uint8_t sync160_gi04)
{
	ASSERT_ERR((((uint32_t)sync160_gi32 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)sync160_gi16 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)sync160_gi08 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)sync160_gi04 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(TFU_SYNC_GI_160_ADDR,  ((uint32_t)sync160_gi32 << 24) |((uint32_t)sync160_gi16 << 16) |((uint32_t)sync160_gi08 << 8) |((uint32_t)sync160_gi04 << 0));
}

__INLINE void tfu_sync_gi_160_unpack(uint8_t* sync160_gi32, uint8_t* sync160_gi16, uint8_t* sync160_gi08, uint8_t* sync160_gi04)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_160_ADDR);

	*sync160_gi32 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*sync160_gi16 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*sync160_gi08 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*sync160_gi04 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t tfu_sync_gi_160_sync_160_gi_32_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_160_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void tfu_sync_gi_160_sync_160_gi_32_setf(uint8_t sync160gi32)
{
	ASSERT_ERR((((uint32_t)sync160gi32 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(TFU_SYNC_GI_160_ADDR, (REG_PL_RD(TFU_SYNC_GI_160_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)sync160gi32 <<24));
}
__INLINE uint8_t tfu_sync_gi_160_sync_160_gi_16_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_160_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void tfu_sync_gi_160_sync_160_gi_16_setf(uint8_t sync160gi16)
{
	ASSERT_ERR((((uint32_t)sync160gi16 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(TFU_SYNC_GI_160_ADDR, (REG_PL_RD(TFU_SYNC_GI_160_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)sync160gi16 <<16));
}
__INLINE uint8_t tfu_sync_gi_160_sync_160_gi_08_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_160_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void tfu_sync_gi_160_sync_160_gi_08_setf(uint8_t sync160gi08)
{
	ASSERT_ERR((((uint32_t)sync160gi08 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(TFU_SYNC_GI_160_ADDR, (REG_PL_RD(TFU_SYNC_GI_160_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)sync160gi08 <<8));
}
__INLINE uint8_t tfu_sync_gi_160_sync_160_gi_04_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_GI_160_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void tfu_sync_gi_160_sync_160_gi_04_setf(uint8_t sync160gi04)
{
	ASSERT_ERR((((uint32_t)sync160gi04 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(TFU_SYNC_GI_160_ADDR, (REG_PL_RD(TFU_SYNC_GI_160_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)sync160gi04 <<0));
}

/**
 * @brief SYNC_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SYNC160                   0x0
 *    15:00 SYNC80                    0x0
 * </pre>
 */
#define TFU_SYNC_2_ADDR        (REG_TFU_BASE_ADDR+0x00000090)
#define TFU_SYNC_2_OFFSET      0x00000090
#define TFU_SYNC_2_INDEX       0x00000024
#define TFU_SYNC_2_RESET       0x00000000

__INLINE uint32_t  tfu_sync_2_get(void)
{
	return REG_PL_RD(TFU_SYNC_2_ADDR);
}

__INLINE void tfu_sync_2_set(uint32_t value)
{
	REG_PL_WR(TFU_SYNC_2_ADDR, value);
}

// field definitions
#define TFU_SYNC_2_SYNC_160_MASK            ((uint32_t)0xFFFF0000)
#define TFU_SYNC_2_SYNC_160_LSB             16
#define TFU_SYNC_2_SYNC_160_WIDTH           ((uint32_t)0x00000010)
#define TFU_SYNC_2_SYNC_80_MASK             ((uint32_t)0x0000FFFF)
#define TFU_SYNC_2_SYNC_80_LSB              0
#define TFU_SYNC_2_SYNC_80_WIDTH            ((uint32_t)0x00000010)

#define TFU_SYNC_2_SYNC_160_RST             0x0
#define TFU_SYNC_2_SYNC_80_RST              0x0

__INLINE void tfu_sync_2_pack(uint16_t sync160, uint16_t sync80)
{
	ASSERT_ERR((((uint32_t)sync160 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)sync80 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(TFU_SYNC_2_ADDR,  ((uint32_t)sync160 << 16) |((uint32_t)sync80 << 0));
}

__INLINE void tfu_sync_2_unpack(uint16_t* sync160, uint16_t* sync80)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_2_ADDR);

	*sync160 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*sync80 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t tfu_sync_2_sync_160_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void tfu_sync_2_sync_160_setf(uint16_t sync160)
{
	ASSERT_ERR((((uint32_t)sync160 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(TFU_SYNC_2_ADDR, (REG_PL_RD(TFU_SYNC_2_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)sync160 <<16));
}
__INLINE uint16_t tfu_sync_2_sync_80_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_SYNC_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void tfu_sync_2_sync_80_setf(uint16_t sync80)
{
	ASSERT_ERR((((uint32_t)sync80 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(TFU_SYNC_2_ADDR, (REG_PL_RD(TFU_SYNC_2_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)sync80 <<0));
}

/**
 * @brief FFT_DEC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:18 DMA_OFFSET_20_S           0x0
 *    15:08 TX_EXT_DMA_PREFETCH_BUSY_WAIT_TIME 0x3f
 *    07:06 TX_EXT_DMA_PREFETCH_DEPTH 0x1
 *    05    TX_FAST_STF_DISABLE       0              
 *    04    FFT_CLK_GATER_DISABLE     0              
 *    03:02 FFT_DEC_FACTOR_ENUM_NOT_FIRST_HE_LTF 0x0
 *    01:00 FFT_DEC_FACTOR_ENUM_FIRST_HE_LTF 0x0
 * </pre>
 */
#define TFU_FFT_DEC_ADDR        (REG_TFU_BASE_ADDR+0x00000094)
#define TFU_FFT_DEC_OFFSET      0x00000094
#define TFU_FFT_DEC_INDEX       0x00000025
#define TFU_FFT_DEC_RESET       0x00003F40

__INLINE uint32_t  tfu_fft_dec_get(void)
{
	return REG_PL_RD(TFU_FFT_DEC_ADDR);
}

__INLINE void tfu_fft_dec_set(uint32_t value)
{
	REG_PL_WR(TFU_FFT_DEC_ADDR, value);
}

// field definitions
#define TFU_FFT_DEC_DMA_OFFSET_20_S_MASK    ((uint32_t)0xFFFC0000)
#define TFU_FFT_DEC_DMA_OFFSET_20_S_LSB     18
#define TFU_FFT_DEC_DMA_OFFSET_20_S_WIDTH    ((uint32_t)0x0000000E)
#define TFU_FFT_DEC_TX_EXT_DMA_PREFETCH_BUSY_WAIT_TIME_MASK    ((uint32_t)0x0000FF00)
#define TFU_FFT_DEC_TX_EXT_DMA_PREFETCH_BUSY_WAIT_TIME_LSB    8
#define TFU_FFT_DEC_TX_EXT_DMA_PREFETCH_BUSY_WAIT_TIME_WIDTH    ((uint32_t)0x00000008)
#define TFU_FFT_DEC_TX_EXT_DMA_PREFETCH_DEPTH_MASK    ((uint32_t)0x000000C0)
#define TFU_FFT_DEC_TX_EXT_DMA_PREFETCH_DEPTH_LSB    6
#define TFU_FFT_DEC_TX_EXT_DMA_PREFETCH_DEPTH_WIDTH    ((uint32_t)0x00000002)
#define TFU_FFT_DEC_TX_FAST_STF_DISABLE_BIT    ((uint32_t)0x00000020)
#define TFU_FFT_DEC_TX_FAST_STF_DISABLE_POS    5
#define TFU_FFT_DEC_FFT_CLK_GATER_DISABLE_BIT    ((uint32_t)0x00000010)
#define TFU_FFT_DEC_FFT_CLK_GATER_DISABLE_POS    4
#define TFU_FFT_DEC_FFT_DEC_FACTOR_ENUM_NOT_FIRST_HE_LTF_MASK    ((uint32_t)0x0000000C)
#define TFU_FFT_DEC_FFT_DEC_FACTOR_ENUM_NOT_FIRST_HE_LTF_LSB    2
#define TFU_FFT_DEC_FFT_DEC_FACTOR_ENUM_NOT_FIRST_HE_LTF_WIDTH    ((uint32_t)0x00000002)
#define TFU_FFT_DEC_FFT_DEC_FACTOR_ENUM_FIRST_HE_LTF_MASK    ((uint32_t)0x00000003)
#define TFU_FFT_DEC_FFT_DEC_FACTOR_ENUM_FIRST_HE_LTF_LSB    0
#define TFU_FFT_DEC_FFT_DEC_FACTOR_ENUM_FIRST_HE_LTF_WIDTH    ((uint32_t)0x00000002)

#define TFU_FFT_DEC_DMA_OFFSET_20_S_RST     0x0
#define TFU_FFT_DEC_TX_EXT_DMA_PREFETCH_BUSY_WAIT_TIME_RST    0x3f
#define TFU_FFT_DEC_TX_EXT_DMA_PREFETCH_DEPTH_RST    0x1
#define TFU_FFT_DEC_TX_FAST_STF_DISABLE_RST    0x0
#define TFU_FFT_DEC_FFT_CLK_GATER_DISABLE_RST    0x0
#define TFU_FFT_DEC_FFT_DEC_FACTOR_ENUM_NOT_FIRST_HE_LTF_RST    0x0
#define TFU_FFT_DEC_FFT_DEC_FACTOR_ENUM_FIRST_HE_LTF_RST    0x0

__INLINE void tfu_fft_dec_pack(uint16_t dma_offset_20_s, uint8_t tx_ext_dma_prefetch_busy_wait_time, uint8_t tx_ext_dma_prefetch_depth, uint8_t tx_fast_stf_disable, uint8_t fft_clk_gater_disable, uint8_t fft_dec_factor_enum_not_first_he_ltf, uint8_t fft_dec_factor_enum_first_he_ltf)
{
	ASSERT_ERR((((uint32_t)dma_offset_20_s << 18) & ~((uint32_t)0xFFFC0000)) == 0);
	ASSERT_ERR((((uint32_t)tx_ext_dma_prefetch_busy_wait_time << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)tx_ext_dma_prefetch_depth << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)tx_fast_stf_disable << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)fft_clk_gater_disable << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)fft_dec_factor_enum_not_first_he_ltf << 2) & ~((uint32_t)0x0000000C)) == 0);
	ASSERT_ERR((((uint32_t)fft_dec_factor_enum_first_he_ltf << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(TFU_FFT_DEC_ADDR,  ((uint32_t)dma_offset_20_s << 18) |((uint32_t)tx_ext_dma_prefetch_busy_wait_time << 8) |((uint32_t)tx_ext_dma_prefetch_depth << 6) |((uint32_t)tx_fast_stf_disable << 5) |((uint32_t)fft_clk_gater_disable << 4) |((uint32_t)fft_dec_factor_enum_not_first_he_ltf << 2) |((uint32_t)fft_dec_factor_enum_first_he_ltf << 0));
}

__INLINE void tfu_fft_dec_unpack(uint16_t* dma_offset_20_s, uint8_t* tx_ext_dma_prefetch_busy_wait_time, uint8_t* tx_ext_dma_prefetch_depth, uint8_t* tx_fast_stf_disable, uint8_t* fft_clk_gater_disable, uint8_t* fft_dec_factor_enum_not_first_he_ltf, uint8_t* fft_dec_factor_enum_first_he_ltf)
{
	uint32_t localVal = REG_PL_RD(TFU_FFT_DEC_ADDR);

	*dma_offset_20_s = (localVal & ((uint32_t)0xFFFC0000)) >>  18;
	*tx_ext_dma_prefetch_busy_wait_time = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*tx_ext_dma_prefetch_depth = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*tx_fast_stf_disable = (localVal & ((uint32_t)0x00000020)) >>  5;
	*fft_clk_gater_disable = (localVal & ((uint32_t)0x00000010)) >>  4;
	*fft_dec_factor_enum_not_first_he_ltf = (localVal & ((uint32_t)0x0000000C)) >>  2;
	*fft_dec_factor_enum_first_he_ltf = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t tfu_fft_dec_dma_offset_20_s_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_FFT_DEC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFC0000)) >> 18);
}
__INLINE void tfu_fft_dec_dma_offset_20_s_setf(uint16_t dmaoffset20s)
{
	ASSERT_ERR((((uint32_t)dmaoffset20s << 18) & ~((uint32_t)0xFFFC0000)) == 0);
	REG_PL_WR(TFU_FFT_DEC_ADDR, (REG_PL_RD(TFU_FFT_DEC_ADDR) & ~((uint32_t)0xFFFC0000)) | ((uint32_t)dmaoffset20s <<18));
}
__INLINE uint8_t tfu_fft_dec_tx_ext_dma_prefetch_busy_wait_time_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_FFT_DEC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void tfu_fft_dec_tx_ext_dma_prefetch_busy_wait_time_setf(uint8_t txextdmaprefetchbusywaittime)
{
	ASSERT_ERR((((uint32_t)txextdmaprefetchbusywaittime << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(TFU_FFT_DEC_ADDR, (REG_PL_RD(TFU_FFT_DEC_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)txextdmaprefetchbusywaittime <<8));
}
__INLINE uint8_t tfu_fft_dec_tx_ext_dma_prefetch_depth_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_FFT_DEC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void tfu_fft_dec_tx_ext_dma_prefetch_depth_setf(uint8_t txextdmaprefetchdepth)
{
	ASSERT_ERR((((uint32_t)txextdmaprefetchdepth << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(TFU_FFT_DEC_ADDR, (REG_PL_RD(TFU_FFT_DEC_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)txextdmaprefetchdepth <<6));
}
__INLINE uint8_t tfu_fft_dec_tx_fast_stf_disable_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_FFT_DEC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void tfu_fft_dec_tx_fast_stf_disable_setf(uint8_t txfaststfdisable)
{
	ASSERT_ERR((((uint32_t)txfaststfdisable << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(TFU_FFT_DEC_ADDR, (REG_PL_RD(TFU_FFT_DEC_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)txfaststfdisable <<5));
}
__INLINE uint8_t tfu_fft_dec_fft_clk_gater_disable_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_FFT_DEC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void tfu_fft_dec_fft_clk_gater_disable_setf(uint8_t fftclkgaterdisable)
{
	ASSERT_ERR((((uint32_t)fftclkgaterdisable << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(TFU_FFT_DEC_ADDR, (REG_PL_RD(TFU_FFT_DEC_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)fftclkgaterdisable <<4));
}
__INLINE uint8_t tfu_fft_dec_fft_dec_factor_enum_not_first_he_ltf_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_FFT_DEC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000C)) >> 2);
}
__INLINE void tfu_fft_dec_fft_dec_factor_enum_not_first_he_ltf_setf(uint8_t fftdecfactorenumnotfirstheltf)
{
	ASSERT_ERR((((uint32_t)fftdecfactorenumnotfirstheltf << 2) & ~((uint32_t)0x0000000C)) == 0);
	REG_PL_WR(TFU_FFT_DEC_ADDR, (REG_PL_RD(TFU_FFT_DEC_ADDR) & ~((uint32_t)0x0000000C)) | ((uint32_t)fftdecfactorenumnotfirstheltf <<2));
}
__INLINE uint8_t tfu_fft_dec_fft_dec_factor_enum_first_he_ltf_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_FFT_DEC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void tfu_fft_dec_fft_dec_factor_enum_first_he_ltf_setf(uint8_t fftdecfactorenumfirstheltf)
{
	ASSERT_ERR((((uint32_t)fftdecfactorenumfirstheltf << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(TFU_FFT_DEC_ADDR, (REG_PL_RD(TFU_FFT_DEC_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)fftdecfactorenumfirstheltf <<0));
}

/**
 * @brief MPU_RX_INFO register definition
 *  MPU vector Rx parameters register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    22:20 MPU_RX_INFO_NSTS          0x0
 *    18:16 MPU_RX_INFO_HELTF_NUM     0x0
 *    15:14 MPU_RX_INFO_HELTF_SIZE    0x0
 *    12:08 MPU_RX_INFO_HESIGB_NUM    0x0
 *    07:06 MPU_RX_INFO_FRAME_BW      0x0
 *    05:04 MPU_RX_INFO_GI_TYPE       0x0
 *    03:00 MPU_RX_INFO_FORMAT_MODE   0x0
 * </pre>
 */
#define TFU_MPU_RX_INFO_ADDR        (REG_TFU_BASE_ADDR+0x00000098)
#define TFU_MPU_RX_INFO_OFFSET      0x00000098
#define TFU_MPU_RX_INFO_INDEX       0x00000026
#define TFU_MPU_RX_INFO_RESET       0x00000000

__INLINE uint32_t  tfu_mpu_rx_info_get(void)
{
	return REG_PL_RD(TFU_MPU_RX_INFO_ADDR);
}

__INLINE void tfu_mpu_rx_info_set(uint32_t value)
{
	REG_PL_WR(TFU_MPU_RX_INFO_ADDR, value);
}

// field definitions
#define TFU_MPU_RX_INFO_MPU_RX_INFO_NSTS_MASK    ((uint32_t)0x00700000)
#define TFU_MPU_RX_INFO_MPU_RX_INFO_NSTS_LSB    20
#define TFU_MPU_RX_INFO_MPU_RX_INFO_NSTS_WIDTH    ((uint32_t)0x00000003)
#define TFU_MPU_RX_INFO_MPU_RX_INFO_HELTF_NUM_MASK    ((uint32_t)0x00070000)
#define TFU_MPU_RX_INFO_MPU_RX_INFO_HELTF_NUM_LSB    16
#define TFU_MPU_RX_INFO_MPU_RX_INFO_HELTF_NUM_WIDTH    ((uint32_t)0x00000003)
#define TFU_MPU_RX_INFO_MPU_RX_INFO_HELTF_SIZE_MASK    ((uint32_t)0x0000C000)
#define TFU_MPU_RX_INFO_MPU_RX_INFO_HELTF_SIZE_LSB    14
#define TFU_MPU_RX_INFO_MPU_RX_INFO_HELTF_SIZE_WIDTH    ((uint32_t)0x00000002)
#define TFU_MPU_RX_INFO_MPU_RX_INFO_HESIGB_NUM_MASK    ((uint32_t)0x00001F00)
#define TFU_MPU_RX_INFO_MPU_RX_INFO_HESIGB_NUM_LSB    8
#define TFU_MPU_RX_INFO_MPU_RX_INFO_HESIGB_NUM_WIDTH    ((uint32_t)0x00000005)
#define TFU_MPU_RX_INFO_MPU_RX_INFO_FRAME_BW_MASK    ((uint32_t)0x000000C0)
#define TFU_MPU_RX_INFO_MPU_RX_INFO_FRAME_BW_LSB    6
#define TFU_MPU_RX_INFO_MPU_RX_INFO_FRAME_BW_WIDTH    ((uint32_t)0x00000002)
#define TFU_MPU_RX_INFO_MPU_RX_INFO_GI_TYPE_MASK    ((uint32_t)0x00000030)
#define TFU_MPU_RX_INFO_MPU_RX_INFO_GI_TYPE_LSB    4
#define TFU_MPU_RX_INFO_MPU_RX_INFO_GI_TYPE_WIDTH    ((uint32_t)0x00000002)
#define TFU_MPU_RX_INFO_MPU_RX_INFO_FORMAT_MODE_MASK    ((uint32_t)0x0000000F)
#define TFU_MPU_RX_INFO_MPU_RX_INFO_FORMAT_MODE_LSB    0
#define TFU_MPU_RX_INFO_MPU_RX_INFO_FORMAT_MODE_WIDTH    ((uint32_t)0x00000004)

#define TFU_MPU_RX_INFO_MPU_RX_INFO_NSTS_RST    0x0
#define TFU_MPU_RX_INFO_MPU_RX_INFO_HELTF_NUM_RST    0x0
#define TFU_MPU_RX_INFO_MPU_RX_INFO_HELTF_SIZE_RST    0x0
#define TFU_MPU_RX_INFO_MPU_RX_INFO_HESIGB_NUM_RST    0x0
#define TFU_MPU_RX_INFO_MPU_RX_INFO_FRAME_BW_RST    0x0
#define TFU_MPU_RX_INFO_MPU_RX_INFO_GI_TYPE_RST    0x0
#define TFU_MPU_RX_INFO_MPU_RX_INFO_FORMAT_MODE_RST    0x0

__INLINE void tfu_mpu_rx_info_pack(uint8_t mpu_rx_info_nsts, uint8_t mpu_rx_info_heltf_num, uint8_t mpu_rx_info_heltf_size, uint8_t mpu_rx_info_hesigb_num, uint8_t mpu_rx_info_frame_bw, uint8_t mpu_rx_info_gi_type, uint8_t mpu_rx_info_format_mode)
{
	ASSERT_ERR((((uint32_t)mpu_rx_info_nsts << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)mpu_rx_info_heltf_num << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)mpu_rx_info_heltf_size << 14) & ~((uint32_t)0x0000C000)) == 0);
	ASSERT_ERR((((uint32_t)mpu_rx_info_hesigb_num << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)mpu_rx_info_frame_bw << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)mpu_rx_info_gi_type << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)mpu_rx_info_format_mode << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(TFU_MPU_RX_INFO_ADDR,  ((uint32_t)mpu_rx_info_nsts << 20) |((uint32_t)mpu_rx_info_heltf_num << 16) |((uint32_t)mpu_rx_info_heltf_size << 14) |((uint32_t)mpu_rx_info_hesigb_num << 8) |((uint32_t)mpu_rx_info_frame_bw << 6) |((uint32_t)mpu_rx_info_gi_type << 4) |((uint32_t)mpu_rx_info_format_mode << 0));
}

__INLINE void tfu_mpu_rx_info_unpack(uint8_t* mpu_rx_info_nsts, uint8_t* mpu_rx_info_heltf_num, uint8_t* mpu_rx_info_heltf_size, uint8_t* mpu_rx_info_hesigb_num, uint8_t* mpu_rx_info_frame_bw, uint8_t* mpu_rx_info_gi_type, uint8_t* mpu_rx_info_format_mode)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RX_INFO_ADDR);

	*mpu_rx_info_nsts = (localVal & ((uint32_t)0x00700000)) >>  20;
	*mpu_rx_info_heltf_num = (localVal & ((uint32_t)0x00070000)) >>  16;
	*mpu_rx_info_heltf_size = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*mpu_rx_info_hesigb_num = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*mpu_rx_info_frame_bw = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*mpu_rx_info_gi_type = (localVal & ((uint32_t)0x00000030)) >>  4;
	*mpu_rx_info_format_mode = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t tfu_mpu_rx_info_mpu_rx_info_nsts_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RX_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void tfu_mpu_rx_info_mpu_rx_info_nsts_setf(uint8_t mpurxinfonsts)
{
	ASSERT_ERR((((uint32_t)mpurxinfonsts << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(TFU_MPU_RX_INFO_ADDR, (REG_PL_RD(TFU_MPU_RX_INFO_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)mpurxinfonsts <<20));
}
__INLINE uint8_t tfu_mpu_rx_info_mpu_rx_info_heltf_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RX_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE void tfu_mpu_rx_info_mpu_rx_info_heltf_num_setf(uint8_t mpurxinfoheltfnum)
{
	ASSERT_ERR((((uint32_t)mpurxinfoheltfnum << 16) & ~((uint32_t)0x00070000)) == 0);
	REG_PL_WR(TFU_MPU_RX_INFO_ADDR, (REG_PL_RD(TFU_MPU_RX_INFO_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)mpurxinfoheltfnum <<16));
}
__INLINE uint8_t tfu_mpu_rx_info_mpu_rx_info_heltf_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RX_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE void tfu_mpu_rx_info_mpu_rx_info_heltf_size_setf(uint8_t mpurxinfoheltfsize)
{
	ASSERT_ERR((((uint32_t)mpurxinfoheltfsize << 14) & ~((uint32_t)0x0000C000)) == 0);
	REG_PL_WR(TFU_MPU_RX_INFO_ADDR, (REG_PL_RD(TFU_MPU_RX_INFO_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)mpurxinfoheltfsize <<14));
}
__INLINE uint8_t tfu_mpu_rx_info_mpu_rx_info_hesigb_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RX_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void tfu_mpu_rx_info_mpu_rx_info_hesigb_num_setf(uint8_t mpurxinfohesigbnum)
{
	ASSERT_ERR((((uint32_t)mpurxinfohesigbnum << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(TFU_MPU_RX_INFO_ADDR, (REG_PL_RD(TFU_MPU_RX_INFO_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)mpurxinfohesigbnum <<8));
}
__INLINE uint8_t tfu_mpu_rx_info_mpu_rx_info_frame_bw_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RX_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void tfu_mpu_rx_info_mpu_rx_info_frame_bw_setf(uint8_t mpurxinfoframebw)
{
	ASSERT_ERR((((uint32_t)mpurxinfoframebw << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(TFU_MPU_RX_INFO_ADDR, (REG_PL_RD(TFU_MPU_RX_INFO_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)mpurxinfoframebw <<6));
}
__INLINE uint8_t tfu_mpu_rx_info_mpu_rx_info_gi_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RX_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void tfu_mpu_rx_info_mpu_rx_info_gi_type_setf(uint8_t mpurxinfogitype)
{
	ASSERT_ERR((((uint32_t)mpurxinfogitype << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(TFU_MPU_RX_INFO_ADDR, (REG_PL_RD(TFU_MPU_RX_INFO_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)mpurxinfogitype <<4));
}
__INLINE uint8_t tfu_mpu_rx_info_mpu_rx_info_format_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RX_INFO_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void tfu_mpu_rx_info_mpu_rx_info_format_mode_setf(uint8_t mpurxinfoformatmode)
{
	ASSERT_ERR((((uint32_t)mpurxinfoformatmode << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(TFU_MPU_RX_INFO_ADDR, (REG_PL_RD(TFU_MPU_RX_INFO_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)mpurxinfoformatmode <<0));
}

/**
 * @brief MPU_RU_TYPE register definition
 *  MPU info of users RU type register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:24 RU_TYPE_U8                0x0
 *    23:21 RU_TYPE_U7                0x0
 *    20:18 RU_TYPE_U6                0x0
 *    17:15 RU_TYPE_U5                0x0
 *    14:12 RU_TYPE_U4                0x0
 *    11:09 RU_TYPE_U3                0x0
 *    08:06 RU_TYPE_U2                0x0
 *    05:03 RU_TYPE_U1                0x0
 *    02:00 RU_TYPE_U0                0x0
 * </pre>
 */
#define TFU_MPU_RU_TYPE_ADDR        (REG_TFU_BASE_ADDR+0x0000009C)
#define TFU_MPU_RU_TYPE_OFFSET      0x0000009C
#define TFU_MPU_RU_TYPE_INDEX       0x00000027
#define TFU_MPU_RU_TYPE_RESET       0x00000000

__INLINE uint32_t  tfu_mpu_ru_type_get(void)
{
	return REG_PL_RD(TFU_MPU_RU_TYPE_ADDR);
}

__INLINE void tfu_mpu_ru_type_set(uint32_t value)
{
	REG_PL_WR(TFU_MPU_RU_TYPE_ADDR, value);
}

// field definitions
#define TFU_MPU_RU_TYPE_RU_TYPE_U_8_MASK    ((uint32_t)0x07000000)
#define TFU_MPU_RU_TYPE_RU_TYPE_U_8_LSB     24
#define TFU_MPU_RU_TYPE_RU_TYPE_U_8_WIDTH    ((uint32_t)0x00000003)
#define TFU_MPU_RU_TYPE_RU_TYPE_U_7_MASK    ((uint32_t)0x00E00000)
#define TFU_MPU_RU_TYPE_RU_TYPE_U_7_LSB     21
#define TFU_MPU_RU_TYPE_RU_TYPE_U_7_WIDTH    ((uint32_t)0x00000003)
#define TFU_MPU_RU_TYPE_RU_TYPE_U_6_MASK    ((uint32_t)0x001C0000)
#define TFU_MPU_RU_TYPE_RU_TYPE_U_6_LSB     18
#define TFU_MPU_RU_TYPE_RU_TYPE_U_6_WIDTH    ((uint32_t)0x00000003)
#define TFU_MPU_RU_TYPE_RU_TYPE_U_5_MASK    ((uint32_t)0x00038000)
#define TFU_MPU_RU_TYPE_RU_TYPE_U_5_LSB     15
#define TFU_MPU_RU_TYPE_RU_TYPE_U_5_WIDTH    ((uint32_t)0x00000003)
#define TFU_MPU_RU_TYPE_RU_TYPE_U_4_MASK    ((uint32_t)0x00007000)
#define TFU_MPU_RU_TYPE_RU_TYPE_U_4_LSB     12
#define TFU_MPU_RU_TYPE_RU_TYPE_U_4_WIDTH    ((uint32_t)0x00000003)
#define TFU_MPU_RU_TYPE_RU_TYPE_U_3_MASK    ((uint32_t)0x00000E00)
#define TFU_MPU_RU_TYPE_RU_TYPE_U_3_LSB     9
#define TFU_MPU_RU_TYPE_RU_TYPE_U_3_WIDTH    ((uint32_t)0x00000003)
#define TFU_MPU_RU_TYPE_RU_TYPE_U_2_MASK    ((uint32_t)0x000001C0)
#define TFU_MPU_RU_TYPE_RU_TYPE_U_2_LSB     6
#define TFU_MPU_RU_TYPE_RU_TYPE_U_2_WIDTH    ((uint32_t)0x00000003)
#define TFU_MPU_RU_TYPE_RU_TYPE_U_1_MASK    ((uint32_t)0x00000038)
#define TFU_MPU_RU_TYPE_RU_TYPE_U_1_LSB     3
#define TFU_MPU_RU_TYPE_RU_TYPE_U_1_WIDTH    ((uint32_t)0x00000003)
#define TFU_MPU_RU_TYPE_RU_TYPE_U_0_MASK    ((uint32_t)0x00000007)
#define TFU_MPU_RU_TYPE_RU_TYPE_U_0_LSB     0
#define TFU_MPU_RU_TYPE_RU_TYPE_U_0_WIDTH    ((uint32_t)0x00000003)

#define TFU_MPU_RU_TYPE_RU_TYPE_U_8_RST     0x0
#define TFU_MPU_RU_TYPE_RU_TYPE_U_7_RST     0x0
#define TFU_MPU_RU_TYPE_RU_TYPE_U_6_RST     0x0
#define TFU_MPU_RU_TYPE_RU_TYPE_U_5_RST     0x0
#define TFU_MPU_RU_TYPE_RU_TYPE_U_4_RST     0x0
#define TFU_MPU_RU_TYPE_RU_TYPE_U_3_RST     0x0
#define TFU_MPU_RU_TYPE_RU_TYPE_U_2_RST     0x0
#define TFU_MPU_RU_TYPE_RU_TYPE_U_1_RST     0x0
#define TFU_MPU_RU_TYPE_RU_TYPE_U_0_RST     0x0

__INLINE void tfu_mpu_ru_type_pack(uint8_t ru_type_u8, uint8_t ru_type_u7, uint8_t ru_type_u6, uint8_t ru_type_u5, uint8_t ru_type_u4, uint8_t ru_type_u3, uint8_t ru_type_u2, uint8_t ru_type_u1, uint8_t ru_type_u0)
{
	ASSERT_ERR((((uint32_t)ru_type_u8 << 24) & ~((uint32_t)0x07000000)) == 0);
	ASSERT_ERR((((uint32_t)ru_type_u7 << 21) & ~((uint32_t)0x00E00000)) == 0);
	ASSERT_ERR((((uint32_t)ru_type_u6 << 18) & ~((uint32_t)0x001C0000)) == 0);
	ASSERT_ERR((((uint32_t)ru_type_u5 << 15) & ~((uint32_t)0x00038000)) == 0);
	ASSERT_ERR((((uint32_t)ru_type_u4 << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)ru_type_u3 << 9) & ~((uint32_t)0x00000E00)) == 0);
	ASSERT_ERR((((uint32_t)ru_type_u2 << 6) & ~((uint32_t)0x000001C0)) == 0);
	ASSERT_ERR((((uint32_t)ru_type_u1 << 3) & ~((uint32_t)0x00000038)) == 0);
	ASSERT_ERR((((uint32_t)ru_type_u0 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(TFU_MPU_RU_TYPE_ADDR,  ((uint32_t)ru_type_u8 << 24) |((uint32_t)ru_type_u7 << 21) |((uint32_t)ru_type_u6 << 18) |((uint32_t)ru_type_u5 << 15) |((uint32_t)ru_type_u4 << 12) |((uint32_t)ru_type_u3 << 9) |((uint32_t)ru_type_u2 << 6) |((uint32_t)ru_type_u1 << 3) |((uint32_t)ru_type_u0 << 0));
}

__INLINE void tfu_mpu_ru_type_unpack(uint8_t* ru_type_u8, uint8_t* ru_type_u7, uint8_t* ru_type_u6, uint8_t* ru_type_u5, uint8_t* ru_type_u4, uint8_t* ru_type_u3, uint8_t* ru_type_u2, uint8_t* ru_type_u1, uint8_t* ru_type_u0)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_TYPE_ADDR);

	*ru_type_u8 = (localVal & ((uint32_t)0x07000000)) >>  24;
	*ru_type_u7 = (localVal & ((uint32_t)0x00E00000)) >>  21;
	*ru_type_u6 = (localVal & ((uint32_t)0x001C0000)) >>  18;
	*ru_type_u5 = (localVal & ((uint32_t)0x00038000)) >>  15;
	*ru_type_u4 = (localVal & ((uint32_t)0x00007000)) >>  12;
	*ru_type_u3 = (localVal & ((uint32_t)0x00000E00)) >>  9;
	*ru_type_u2 = (localVal & ((uint32_t)0x000001C0)) >>  6;
	*ru_type_u1 = (localVal & ((uint32_t)0x00000038)) >>  3;
	*ru_type_u0 = (localVal & ((uint32_t)0x00000007)) >>  0;
}

__INLINE uint8_t tfu_mpu_ru_type_ru_type_u_8_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_TYPE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x07000000)) >> 24);
}
__INLINE uint8_t tfu_mpu_ru_type_ru_type_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_TYPE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00E00000)) >> 21);
}
__INLINE uint8_t tfu_mpu_ru_type_ru_type_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_TYPE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x001C0000)) >> 18);
}
__INLINE uint8_t tfu_mpu_ru_type_ru_type_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_TYPE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00038000)) >> 15);
}
__INLINE uint8_t tfu_mpu_ru_type_ru_type_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_TYPE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE uint8_t tfu_mpu_ru_type_ru_type_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_TYPE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000E00)) >> 9);
}
__INLINE uint8_t tfu_mpu_ru_type_ru_type_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_TYPE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000001C0)) >> 6);
}
__INLINE uint8_t tfu_mpu_ru_type_ru_type_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_TYPE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000038)) >> 3);
}
__INLINE uint8_t tfu_mpu_ru_type_ru_type_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_TYPE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000007)) >> 0);
}
__INLINE void tfu_mpu_ru_type_ru_type_u_0_setf(uint8_t rutypeu0)
{
	ASSERT_ERR((((uint32_t)rutypeu0 << 0) & ~((uint32_t)0x00000007)) == 0);
	REG_PL_WR(TFU_MPU_RU_TYPE_ADDR, (REG_PL_RD(TFU_MPU_RU_TYPE_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)rutypeu0 <<0));
}

/**
 * @brief MPU_RU_SLOT_0 register definition
 *  MPU users 0-3 RU start index  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:24 RU_SLOT_INDEX_U3          0x0
 *    21:16 RU_SLOT_INDEX_U2          0x0
 *    13:08 RU_SLOT_INDEX_U1          0x0
 *    05:00 RU_SLOT_INDEX_U0          0x0
 * </pre>
 */
#define TFU_MPU_RU_SLOT_0_ADDR        (REG_TFU_BASE_ADDR+0x000000A0)
#define TFU_MPU_RU_SLOT_0_OFFSET      0x000000A0
#define TFU_MPU_RU_SLOT_0_INDEX       0x00000028
#define TFU_MPU_RU_SLOT_0_RESET       0x00000000

__INLINE uint32_t  tfu_mpu_ru_slot_0_get(void)
{
	return REG_PL_RD(TFU_MPU_RU_SLOT_0_ADDR);
}

__INLINE void tfu_mpu_ru_slot_0_set(uint32_t value)
{
	REG_PL_WR(TFU_MPU_RU_SLOT_0_ADDR, value);
}

// field definitions
#define TFU_MPU_RU_SLOT_0_RU_SLOT_INDEX_U_3_MASK    ((uint32_t)0x3F000000)
#define TFU_MPU_RU_SLOT_0_RU_SLOT_INDEX_U_3_LSB    24
#define TFU_MPU_RU_SLOT_0_RU_SLOT_INDEX_U_3_WIDTH    ((uint32_t)0x00000006)
#define TFU_MPU_RU_SLOT_0_RU_SLOT_INDEX_U_2_MASK    ((uint32_t)0x003F0000)
#define TFU_MPU_RU_SLOT_0_RU_SLOT_INDEX_U_2_LSB    16
#define TFU_MPU_RU_SLOT_0_RU_SLOT_INDEX_U_2_WIDTH    ((uint32_t)0x00000006)
#define TFU_MPU_RU_SLOT_0_RU_SLOT_INDEX_U_1_MASK    ((uint32_t)0x00003F00)
#define TFU_MPU_RU_SLOT_0_RU_SLOT_INDEX_U_1_LSB    8
#define TFU_MPU_RU_SLOT_0_RU_SLOT_INDEX_U_1_WIDTH    ((uint32_t)0x00000006)
#define TFU_MPU_RU_SLOT_0_RU_SLOT_INDEX_U_0_MASK    ((uint32_t)0x0000003F)
#define TFU_MPU_RU_SLOT_0_RU_SLOT_INDEX_U_0_LSB    0
#define TFU_MPU_RU_SLOT_0_RU_SLOT_INDEX_U_0_WIDTH    ((uint32_t)0x00000006)

#define TFU_MPU_RU_SLOT_0_RU_SLOT_INDEX_U_3_RST    0x0
#define TFU_MPU_RU_SLOT_0_RU_SLOT_INDEX_U_2_RST    0x0
#define TFU_MPU_RU_SLOT_0_RU_SLOT_INDEX_U_1_RST    0x0
#define TFU_MPU_RU_SLOT_0_RU_SLOT_INDEX_U_0_RST    0x0

__INLINE void tfu_mpu_ru_slot_0_pack(uint8_t ru_slot_index_u3, uint8_t ru_slot_index_u2, uint8_t ru_slot_index_u1, uint8_t ru_slot_index_u0)
{
	ASSERT_ERR((((uint32_t)ru_slot_index_u3 << 24) & ~((uint32_t)0x3F000000)) == 0);
	ASSERT_ERR((((uint32_t)ru_slot_index_u2 << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)ru_slot_index_u1 << 8) & ~((uint32_t)0x00003F00)) == 0);
	ASSERT_ERR((((uint32_t)ru_slot_index_u0 << 0) & ~((uint32_t)0x0000003F)) == 0);
	REG_PL_WR(TFU_MPU_RU_SLOT_0_ADDR,  ((uint32_t)ru_slot_index_u3 << 24) |((uint32_t)ru_slot_index_u2 << 16) |((uint32_t)ru_slot_index_u1 << 8) |((uint32_t)ru_slot_index_u0 << 0));
}

__INLINE void tfu_mpu_ru_slot_0_unpack(uint8_t* ru_slot_index_u3, uint8_t* ru_slot_index_u2, uint8_t* ru_slot_index_u1, uint8_t* ru_slot_index_u0)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_0_ADDR);

	*ru_slot_index_u3 = (localVal & ((uint32_t)0x3F000000)) >>  24;
	*ru_slot_index_u2 = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*ru_slot_index_u1 = (localVal & ((uint32_t)0x00003F00)) >>  8;
	*ru_slot_index_u0 = (localVal & ((uint32_t)0x0000003F)) >>  0;
}

__INLINE uint8_t tfu_mpu_ru_slot_0_ru_slot_index_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x3F000000)) >> 24);
}
__INLINE uint8_t tfu_mpu_ru_slot_0_ru_slot_index_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE uint8_t tfu_mpu_ru_slot_0_ru_slot_index_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003F00)) >> 8);
}
__INLINE uint8_t tfu_mpu_ru_slot_0_ru_slot_index_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000003F)) >> 0);
}
__INLINE void tfu_mpu_ru_slot_0_ru_slot_index_u_0_setf(uint8_t ruslotindexu0)
{
	ASSERT_ERR((((uint32_t)ruslotindexu0 << 0) & ~((uint32_t)0x0000003F)) == 0);
	REG_PL_WR(TFU_MPU_RU_SLOT_0_ADDR, (REG_PL_RD(TFU_MPU_RU_SLOT_0_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)ruslotindexu0 <<0));
}

/**
 * @brief MPU_RU_SLOT_1 register definition
 *  MPU users 4-7 RU start index  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:24 RU_SLOT_INDEX_U7          0x0
 *    21:16 RU_SLOT_INDEX_U6          0x0
 *    13:08 RU_SLOT_INDEX_U5          0x0
 *    05:00 RU_SLOT_INDEX_U4          0x0
 * </pre>
 */
#define TFU_MPU_RU_SLOT_1_ADDR        (REG_TFU_BASE_ADDR+0x000000A4)
#define TFU_MPU_RU_SLOT_1_OFFSET      0x000000A4
#define TFU_MPU_RU_SLOT_1_INDEX       0x00000029
#define TFU_MPU_RU_SLOT_1_RESET       0x00000000

__INLINE uint32_t  tfu_mpu_ru_slot_1_get(void)
{
	return REG_PL_RD(TFU_MPU_RU_SLOT_1_ADDR);
}

// field definitions
#define TFU_MPU_RU_SLOT_1_RU_SLOT_INDEX_U_7_MASK    ((uint32_t)0x3F000000)
#define TFU_MPU_RU_SLOT_1_RU_SLOT_INDEX_U_7_LSB    24
#define TFU_MPU_RU_SLOT_1_RU_SLOT_INDEX_U_7_WIDTH    ((uint32_t)0x00000006)
#define TFU_MPU_RU_SLOT_1_RU_SLOT_INDEX_U_6_MASK    ((uint32_t)0x003F0000)
#define TFU_MPU_RU_SLOT_1_RU_SLOT_INDEX_U_6_LSB    16
#define TFU_MPU_RU_SLOT_1_RU_SLOT_INDEX_U_6_WIDTH    ((uint32_t)0x00000006)
#define TFU_MPU_RU_SLOT_1_RU_SLOT_INDEX_U_5_MASK    ((uint32_t)0x00003F00)
#define TFU_MPU_RU_SLOT_1_RU_SLOT_INDEX_U_5_LSB    8
#define TFU_MPU_RU_SLOT_1_RU_SLOT_INDEX_U_5_WIDTH    ((uint32_t)0x00000006)
#define TFU_MPU_RU_SLOT_1_RU_SLOT_INDEX_U_4_MASK    ((uint32_t)0x0000003F)
#define TFU_MPU_RU_SLOT_1_RU_SLOT_INDEX_U_4_LSB    0
#define TFU_MPU_RU_SLOT_1_RU_SLOT_INDEX_U_4_WIDTH    ((uint32_t)0x00000006)

#define TFU_MPU_RU_SLOT_1_RU_SLOT_INDEX_U_7_RST    0x0
#define TFU_MPU_RU_SLOT_1_RU_SLOT_INDEX_U_6_RST    0x0
#define TFU_MPU_RU_SLOT_1_RU_SLOT_INDEX_U_5_RST    0x0
#define TFU_MPU_RU_SLOT_1_RU_SLOT_INDEX_U_4_RST    0x0

__INLINE void tfu_mpu_ru_slot_1_unpack(uint8_t* ru_slot_index_u7, uint8_t* ru_slot_index_u6, uint8_t* ru_slot_index_u5, uint8_t* ru_slot_index_u4)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_1_ADDR);

	*ru_slot_index_u7 = (localVal & ((uint32_t)0x3F000000)) >>  24;
	*ru_slot_index_u6 = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*ru_slot_index_u5 = (localVal & ((uint32_t)0x00003F00)) >>  8;
	*ru_slot_index_u4 = (localVal & ((uint32_t)0x0000003F)) >>  0;
}

__INLINE uint8_t tfu_mpu_ru_slot_1_ru_slot_index_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x3F000000)) >> 24);
}
__INLINE uint8_t tfu_mpu_ru_slot_1_ru_slot_index_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE uint8_t tfu_mpu_ru_slot_1_ru_slot_index_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003F00)) >> 8);
}
__INLINE uint8_t tfu_mpu_ru_slot_1_ru_slot_index_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000003F)) >> 0);
}

/**
 * @brief MPU_RU_SLOT_2 register definition
 *  MPU users RU band register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20    RU_BAND_POL_REV           0              
 *    16    BAND80_U8                 0              
 *    15    BAND80_U7                 0              
 *    14    BAND80_U6                 0              
 *    13    BAND80_U5                 0              
 *    12    BAND80_U4                 0              
 *    11    BAND80_U3                 0              
 *    10    BAND80_U2                 0              
 *    09    BAND80_U1                 0              
 *    08    BAND80_U0                 0              
 *    05:00 RU_SLOT_INDEX_U8          0x0
 * </pre>
 */
#define TFU_MPU_RU_SLOT_2_ADDR        (REG_TFU_BASE_ADDR+0x000000A8)
#define TFU_MPU_RU_SLOT_2_OFFSET      0x000000A8
#define TFU_MPU_RU_SLOT_2_INDEX       0x0000002A
#define TFU_MPU_RU_SLOT_2_RESET       0x00000000

__INLINE uint32_t  tfu_mpu_ru_slot_2_get(void)
{
	return REG_PL_RD(TFU_MPU_RU_SLOT_2_ADDR);
}

__INLINE void tfu_mpu_ru_slot_2_set(uint32_t value)
{
	REG_PL_WR(TFU_MPU_RU_SLOT_2_ADDR, value);
}

// field definitions
#define TFU_MPU_RU_SLOT_2_RU_BAND_POL_REV_BIT    ((uint32_t)0x00100000)
#define TFU_MPU_RU_SLOT_2_RU_BAND_POL_REV_POS    20
#define TFU_MPU_RU_SLOT_2_BAND_80_U_8_BIT    ((uint32_t)0x00010000)
#define TFU_MPU_RU_SLOT_2_BAND_80_U_8_POS    16
#define TFU_MPU_RU_SLOT_2_BAND_80_U_7_BIT    ((uint32_t)0x00008000)
#define TFU_MPU_RU_SLOT_2_BAND_80_U_7_POS    15
#define TFU_MPU_RU_SLOT_2_BAND_80_U_6_BIT    ((uint32_t)0x00004000)
#define TFU_MPU_RU_SLOT_2_BAND_80_U_6_POS    14
#define TFU_MPU_RU_SLOT_2_BAND_80_U_5_BIT    ((uint32_t)0x00002000)
#define TFU_MPU_RU_SLOT_2_BAND_80_U_5_POS    13
#define TFU_MPU_RU_SLOT_2_BAND_80_U_4_BIT    ((uint32_t)0x00001000)
#define TFU_MPU_RU_SLOT_2_BAND_80_U_4_POS    12
#define TFU_MPU_RU_SLOT_2_BAND_80_U_3_BIT    ((uint32_t)0x00000800)
#define TFU_MPU_RU_SLOT_2_BAND_80_U_3_POS    11
#define TFU_MPU_RU_SLOT_2_BAND_80_U_2_BIT    ((uint32_t)0x00000400)
#define TFU_MPU_RU_SLOT_2_BAND_80_U_2_POS    10
#define TFU_MPU_RU_SLOT_2_BAND_80_U_1_BIT    ((uint32_t)0x00000200)
#define TFU_MPU_RU_SLOT_2_BAND_80_U_1_POS    9
#define TFU_MPU_RU_SLOT_2_BAND_80_U_0_BIT    ((uint32_t)0x00000100)
#define TFU_MPU_RU_SLOT_2_BAND_80_U_0_POS    8
#define TFU_MPU_RU_SLOT_2_RU_SLOT_INDEX_U_8_MASK    ((uint32_t)0x0000003F)
#define TFU_MPU_RU_SLOT_2_RU_SLOT_INDEX_U_8_LSB    0
#define TFU_MPU_RU_SLOT_2_RU_SLOT_INDEX_U_8_WIDTH    ((uint32_t)0x00000006)

#define TFU_MPU_RU_SLOT_2_RU_BAND_POL_REV_RST    0x0
#define TFU_MPU_RU_SLOT_2_BAND_80_U_8_RST    0x0
#define TFU_MPU_RU_SLOT_2_BAND_80_U_7_RST    0x0
#define TFU_MPU_RU_SLOT_2_BAND_80_U_6_RST    0x0
#define TFU_MPU_RU_SLOT_2_BAND_80_U_5_RST    0x0
#define TFU_MPU_RU_SLOT_2_BAND_80_U_4_RST    0x0
#define TFU_MPU_RU_SLOT_2_BAND_80_U_3_RST    0x0
#define TFU_MPU_RU_SLOT_2_BAND_80_U_2_RST    0x0
#define TFU_MPU_RU_SLOT_2_BAND_80_U_1_RST    0x0
#define TFU_MPU_RU_SLOT_2_BAND_80_U_0_RST    0x0
#define TFU_MPU_RU_SLOT_2_RU_SLOT_INDEX_U_8_RST    0x0

__INLINE void tfu_mpu_ru_slot_2_pack(uint8_t ru_band_pol_rev, uint8_t band80_u8, uint8_t band80_u7, uint8_t band80_u6, uint8_t band80_u5, uint8_t band80_u4, uint8_t band80_u3, uint8_t band80_u2, uint8_t band80_u1, uint8_t band80_u0, uint8_t ru_slot_index_u8)
{
	ASSERT_ERR((((uint32_t)ru_band_pol_rev << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)band80_u8 << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)band80_u7 << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)band80_u6 << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)band80_u5 << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)band80_u4 << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)band80_u3 << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)band80_u2 << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)band80_u1 << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)band80_u0 << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)ru_slot_index_u8 << 0) & ~((uint32_t)0x0000003F)) == 0);
	REG_PL_WR(TFU_MPU_RU_SLOT_2_ADDR,  ((uint32_t)ru_band_pol_rev << 20) |((uint32_t)band80_u8 << 16) |((uint32_t)band80_u7 << 15) |((uint32_t)band80_u6 << 14) |((uint32_t)band80_u5 << 13) |((uint32_t)band80_u4 << 12) |((uint32_t)band80_u3 << 11) |((uint32_t)band80_u2 << 10) |((uint32_t)band80_u1 << 9) |((uint32_t)band80_u0 << 8) |((uint32_t)ru_slot_index_u8 << 0));
}

__INLINE void tfu_mpu_ru_slot_2_unpack(uint8_t* ru_band_pol_rev, uint8_t* band80_u8, uint8_t* band80_u7, uint8_t* band80_u6, uint8_t* band80_u5, uint8_t* band80_u4, uint8_t* band80_u3, uint8_t* band80_u2, uint8_t* band80_u1, uint8_t* band80_u0, uint8_t* ru_slot_index_u8)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_2_ADDR);

	*ru_band_pol_rev = (localVal & ((uint32_t)0x00100000)) >>  20;
	*band80_u8 = (localVal & ((uint32_t)0x00010000)) >>  16;
	*band80_u7 = (localVal & ((uint32_t)0x00008000)) >>  15;
	*band80_u6 = (localVal & ((uint32_t)0x00004000)) >>  14;
	*band80_u5 = (localVal & ((uint32_t)0x00002000)) >>  13;
	*band80_u4 = (localVal & ((uint32_t)0x00001000)) >>  12;
	*band80_u3 = (localVal & ((uint32_t)0x00000800)) >>  11;
	*band80_u2 = (localVal & ((uint32_t)0x00000400)) >>  10;
	*band80_u1 = (localVal & ((uint32_t)0x00000200)) >>  9;
	*band80_u0 = (localVal & ((uint32_t)0x00000100)) >>  8;
	*ru_slot_index_u8 = (localVal & ((uint32_t)0x0000003F)) >>  0;
}

__INLINE uint8_t tfu_mpu_ru_slot_2_ru_band_pol_rev_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE void tfu_mpu_ru_slot_2_ru_band_pol_rev_setf(uint8_t rubandpolrev)
{
	ASSERT_ERR((((uint32_t)rubandpolrev << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(TFU_MPU_RU_SLOT_2_ADDR, (REG_PL_RD(TFU_MPU_RU_SLOT_2_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)rubandpolrev <<20));
}
__INLINE uint8_t tfu_mpu_ru_slot_2_band_80_u_8_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint8_t tfu_mpu_ru_slot_2_band_80_u_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE uint8_t tfu_mpu_ru_slot_2_band_80_u_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE uint8_t tfu_mpu_ru_slot_2_band_80_u_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t tfu_mpu_ru_slot_2_band_80_u_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t tfu_mpu_ru_slot_2_band_80_u_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE uint8_t tfu_mpu_ru_slot_2_band_80_u_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE uint8_t tfu_mpu_ru_slot_2_band_80_u_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t tfu_mpu_ru_slot_2_band_80_u_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void tfu_mpu_ru_slot_2_band_80_u_0_setf(uint8_t band80u0)
{
	ASSERT_ERR((((uint32_t)band80u0 << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(TFU_MPU_RU_SLOT_2_ADDR, (REG_PL_RD(TFU_MPU_RU_SLOT_2_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)band80u0 <<8));
}
__INLINE uint8_t tfu_mpu_ru_slot_2_ru_slot_index_u_8_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MPU_RU_SLOT_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000003F)) >> 0);
}

/**
 * @brief TX_LAST_MSG_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TX_LAST_MSG_PTR           0x0
 * </pre>
 */
#define TFU_TX_LAST_MSG_PTR_ADDR        (REG_TFU_BASE_ADDR+0x000000AC)
#define TFU_TX_LAST_MSG_PTR_OFFSET      0x000000AC
#define TFU_TX_LAST_MSG_PTR_INDEX       0x0000002B
#define TFU_TX_LAST_MSG_PTR_RESET       0x00000000

__INLINE uint32_t  tfu_tx_last_msg_ptr_get(void)
{
	return REG_PL_RD(TFU_TX_LAST_MSG_PTR_ADDR);
}

__INLINE void tfu_tx_last_msg_ptr_set(uint32_t value)
{
	REG_PL_WR(TFU_TX_LAST_MSG_PTR_ADDR, value);
}

// field definitions
#define TFU_TX_LAST_MSG_PTR_TX_LAST_MSG_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define TFU_TX_LAST_MSG_PTR_TX_LAST_MSG_PTR_LSB    0
#define TFU_TX_LAST_MSG_PTR_TX_LAST_MSG_PTR_WIDTH    ((uint32_t)0x00000020)

#define TFU_TX_LAST_MSG_PTR_TX_LAST_MSG_PTR_RST    0x0

__INLINE uint32_t tfu_tx_last_msg_ptr_tx_last_msg_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_LAST_MSG_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void tfu_tx_last_msg_ptr_tx_last_msg_ptr_setf(uint32_t txlastmsgptr)
{
	ASSERT_ERR((((uint32_t)txlastmsgptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(TFU_TX_LAST_MSG_PTR_ADDR, (uint32_t)txlastmsgptr << 0);
}

/**
 * @brief COMPDLY_CONF_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:26 ECO_RSRVD                 0x0
 *    25    NO_INTERNAL_MU_MIMO_TONE_PLAN 0              
 *    24    MPU_RX_HESIGB_UPDATE_DISABLE 0              
 *    23    MPU_RX_VECTOR_UPDATE_DISABLE 0              
 *    22    SW_RX_HESIGB_UPDATE_DISABLE 0              
 *    21    SW_RX_VECTOR_UPDATE_DISABLE 0              
 *    20    NDP_HE_NUM_LTF_OVERRIDE   0              
 *    18:16 NDP_HE_NUM_LTF            0x0
 *    15:00 COMP_DLY_4_DC             0x8600
 * </pre>
 */
#define TFU_COMPDLY_CONF_0_ADDR        (REG_TFU_BASE_ADDR+0x000000C4)
#define TFU_COMPDLY_CONF_0_OFFSET      0x000000C4
#define TFU_COMPDLY_CONF_0_INDEX       0x00000031
#define TFU_COMPDLY_CONF_0_RESET       0x00008600

__INLINE uint32_t  tfu_compdly_conf_0_get(void)
{
	return REG_PL_RD(TFU_COMPDLY_CONF_0_ADDR);
}

__INLINE void tfu_compdly_conf_0_set(uint32_t value)
{
	REG_PL_WR(TFU_COMPDLY_CONF_0_ADDR, value);
}

// field definitions
#define TFU_COMPDLY_CONF_0_ECO_RSRVD_MASK    ((uint32_t)0xFC000000)
#define TFU_COMPDLY_CONF_0_ECO_RSRVD_LSB    26
#define TFU_COMPDLY_CONF_0_ECO_RSRVD_WIDTH    ((uint32_t)0x00000006)
#define TFU_COMPDLY_CONF_0_NO_INTERNAL_MU_MIMO_TONE_PLAN_BIT    ((uint32_t)0x02000000)
#define TFU_COMPDLY_CONF_0_NO_INTERNAL_MU_MIMO_TONE_PLAN_POS    25
#define TFU_COMPDLY_CONF_0_MPU_RX_HESIGB_UPDATE_DISABLE_BIT    ((uint32_t)0x01000000)
#define TFU_COMPDLY_CONF_0_MPU_RX_HESIGB_UPDATE_DISABLE_POS    24
#define TFU_COMPDLY_CONF_0_MPU_RX_VECTOR_UPDATE_DISABLE_BIT    ((uint32_t)0x00800000)
#define TFU_COMPDLY_CONF_0_MPU_RX_VECTOR_UPDATE_DISABLE_POS    23
#define TFU_COMPDLY_CONF_0_SW_RX_HESIGB_UPDATE_DISABLE_BIT    ((uint32_t)0x00400000)
#define TFU_COMPDLY_CONF_0_SW_RX_HESIGB_UPDATE_DISABLE_POS    22
#define TFU_COMPDLY_CONF_0_SW_RX_VECTOR_UPDATE_DISABLE_BIT    ((uint32_t)0x00200000)
#define TFU_COMPDLY_CONF_0_SW_RX_VECTOR_UPDATE_DISABLE_POS    21
#define TFU_COMPDLY_CONF_0_NDP_HE_NUM_LTF_OVERRIDE_BIT    ((uint32_t)0x00100000)
#define TFU_COMPDLY_CONF_0_NDP_HE_NUM_LTF_OVERRIDE_POS    20
#define TFU_COMPDLY_CONF_0_NDP_HE_NUM_LTF_MASK    ((uint32_t)0x00070000)
#define TFU_COMPDLY_CONF_0_NDP_HE_NUM_LTF_LSB    16
#define TFU_COMPDLY_CONF_0_NDP_HE_NUM_LTF_WIDTH    ((uint32_t)0x00000003)
#define TFU_COMPDLY_CONF_0_COMP_DLY_4_DC_MASK    ((uint32_t)0x0000FFFF)
#define TFU_COMPDLY_CONF_0_COMP_DLY_4_DC_LSB    0
#define TFU_COMPDLY_CONF_0_COMP_DLY_4_DC_WIDTH    ((uint32_t)0x00000010)

#define TFU_COMPDLY_CONF_0_ECO_RSRVD_RST    0x0
#define TFU_COMPDLY_CONF_0_NO_INTERNAL_MU_MIMO_TONE_PLAN_RST    0x0
#define TFU_COMPDLY_CONF_0_MPU_RX_HESIGB_UPDATE_DISABLE_RST    0x0
#define TFU_COMPDLY_CONF_0_MPU_RX_VECTOR_UPDATE_DISABLE_RST    0x0
#define TFU_COMPDLY_CONF_0_SW_RX_HESIGB_UPDATE_DISABLE_RST    0x0
#define TFU_COMPDLY_CONF_0_SW_RX_VECTOR_UPDATE_DISABLE_RST    0x0
#define TFU_COMPDLY_CONF_0_NDP_HE_NUM_LTF_OVERRIDE_RST    0x0
#define TFU_COMPDLY_CONF_0_NDP_HE_NUM_LTF_RST    0x0
#define TFU_COMPDLY_CONF_0_COMP_DLY_4_DC_RST    0x8600

__INLINE void tfu_compdly_conf_0_pack(uint8_t eco_rsrvd, uint8_t no_internal_mu_mimo_tone_plan, uint8_t mpu_rx_hesigb_update_disable, uint8_t mpu_rx_vector_update_disable, uint8_t sw_rx_hesigb_update_disable, uint8_t sw_rx_vector_update_disable, uint8_t ndp_he_num_ltf_override, uint8_t ndp_he_num_ltf, uint16_t comp_dly_4_dc)
{
	ASSERT_ERR((((uint32_t)eco_rsrvd << 26) & ~((uint32_t)0xFC000000)) == 0);
	ASSERT_ERR((((uint32_t)no_internal_mu_mimo_tone_plan << 25) & ~((uint32_t)0x02000000)) == 0);
	ASSERT_ERR((((uint32_t)mpu_rx_hesigb_update_disable << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)mpu_rx_vector_update_disable << 23) & ~((uint32_t)0x00800000)) == 0);
	ASSERT_ERR((((uint32_t)sw_rx_hesigb_update_disable << 22) & ~((uint32_t)0x00400000)) == 0);
	ASSERT_ERR((((uint32_t)sw_rx_vector_update_disable << 21) & ~((uint32_t)0x00200000)) == 0);
	ASSERT_ERR((((uint32_t)ndp_he_num_ltf_override << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)ndp_he_num_ltf << 16) & ~((uint32_t)0x00070000)) == 0);
	ASSERT_ERR((((uint32_t)comp_dly_4_dc << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(TFU_COMPDLY_CONF_0_ADDR,  ((uint32_t)eco_rsrvd << 26) |((uint32_t)no_internal_mu_mimo_tone_plan << 25) |((uint32_t)mpu_rx_hesigb_update_disable << 24) |((uint32_t)mpu_rx_vector_update_disable << 23) |((uint32_t)sw_rx_hesigb_update_disable << 22) |((uint32_t)sw_rx_vector_update_disable << 21) |((uint32_t)ndp_he_num_ltf_override << 20) |((uint32_t)ndp_he_num_ltf << 16) |((uint32_t)comp_dly_4_dc << 0));
}

__INLINE void tfu_compdly_conf_0_unpack(uint8_t* eco_rsrvd, uint8_t* no_internal_mu_mimo_tone_plan, uint8_t* mpu_rx_hesigb_update_disable, uint8_t* mpu_rx_vector_update_disable, uint8_t* sw_rx_hesigb_update_disable, uint8_t* sw_rx_vector_update_disable, uint8_t* ndp_he_num_ltf_override, uint8_t* ndp_he_num_ltf, uint16_t* comp_dly_4_dc)
{
	uint32_t localVal = REG_PL_RD(TFU_COMPDLY_CONF_0_ADDR);

	*eco_rsrvd = (localVal & ((uint32_t)0xFC000000)) >>  26;
	*no_internal_mu_mimo_tone_plan = (localVal & ((uint32_t)0x02000000)) >>  25;
	*mpu_rx_hesigb_update_disable = (localVal & ((uint32_t)0x01000000)) >>  24;
	*mpu_rx_vector_update_disable = (localVal & ((uint32_t)0x00800000)) >>  23;
	*sw_rx_hesigb_update_disable = (localVal & ((uint32_t)0x00400000)) >>  22;
	*sw_rx_vector_update_disable = (localVal & ((uint32_t)0x00200000)) >>  21;
	*ndp_he_num_ltf_override = (localVal & ((uint32_t)0x00100000)) >>  20;
	*ndp_he_num_ltf = (localVal & ((uint32_t)0x00070000)) >>  16;
	*comp_dly_4_dc = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint8_t tfu_compdly_conf_0_eco_rsrvd_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_COMPDLY_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFC000000)) >> 26);
}
__INLINE void tfu_compdly_conf_0_eco_rsrvd_setf(uint8_t ecorsrvd)
{
	ASSERT_ERR((((uint32_t)ecorsrvd << 26) & ~((uint32_t)0xFC000000)) == 0);
	REG_PL_WR(TFU_COMPDLY_CONF_0_ADDR, (REG_PL_RD(TFU_COMPDLY_CONF_0_ADDR) & ~((uint32_t)0xFC000000)) | ((uint32_t)ecorsrvd <<26));
}
__INLINE uint8_t tfu_compdly_conf_0_no_internal_mu_mimo_tone_plan_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_COMPDLY_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x02000000)) >> 25);
}
__INLINE void tfu_compdly_conf_0_no_internal_mu_mimo_tone_plan_setf(uint8_t nointernalmumimotoneplan)
{
	ASSERT_ERR((((uint32_t)nointernalmumimotoneplan << 25) & ~((uint32_t)0x02000000)) == 0);
	REG_PL_WR(TFU_COMPDLY_CONF_0_ADDR, (REG_PL_RD(TFU_COMPDLY_CONF_0_ADDR) & ~((uint32_t)0x02000000)) | ((uint32_t)nointernalmumimotoneplan <<25));
}
__INLINE uint8_t tfu_compdly_conf_0_mpu_rx_hesigb_update_disable_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_COMPDLY_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE void tfu_compdly_conf_0_mpu_rx_hesigb_update_disable_setf(uint8_t mpurxhesigbupdatedisable)
{
	ASSERT_ERR((((uint32_t)mpurxhesigbupdatedisable << 24) & ~((uint32_t)0x01000000)) == 0);
	REG_PL_WR(TFU_COMPDLY_CONF_0_ADDR, (REG_PL_RD(TFU_COMPDLY_CONF_0_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)mpurxhesigbupdatedisable <<24));
}
__INLINE uint8_t tfu_compdly_conf_0_mpu_rx_vector_update_disable_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_COMPDLY_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00800000)) >> 23);
}
__INLINE void tfu_compdly_conf_0_mpu_rx_vector_update_disable_setf(uint8_t mpurxvectorupdatedisable)
{
	ASSERT_ERR((((uint32_t)mpurxvectorupdatedisable << 23) & ~((uint32_t)0x00800000)) == 0);
	REG_PL_WR(TFU_COMPDLY_CONF_0_ADDR, (REG_PL_RD(TFU_COMPDLY_CONF_0_ADDR) & ~((uint32_t)0x00800000)) | ((uint32_t)mpurxvectorupdatedisable <<23));
}
__INLINE uint8_t tfu_compdly_conf_0_sw_rx_hesigb_update_disable_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_COMPDLY_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00400000)) >> 22);
}
__INLINE void tfu_compdly_conf_0_sw_rx_hesigb_update_disable_setf(uint8_t swrxhesigbupdatedisable)
{
	ASSERT_ERR((((uint32_t)swrxhesigbupdatedisable << 22) & ~((uint32_t)0x00400000)) == 0);
	REG_PL_WR(TFU_COMPDLY_CONF_0_ADDR, (REG_PL_RD(TFU_COMPDLY_CONF_0_ADDR) & ~((uint32_t)0x00400000)) | ((uint32_t)swrxhesigbupdatedisable <<22));
}
__INLINE uint8_t tfu_compdly_conf_0_sw_rx_vector_update_disable_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_COMPDLY_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00200000)) >> 21);
}
__INLINE void tfu_compdly_conf_0_sw_rx_vector_update_disable_setf(uint8_t swrxvectorupdatedisable)
{
	ASSERT_ERR((((uint32_t)swrxvectorupdatedisable << 21) & ~((uint32_t)0x00200000)) == 0);
	REG_PL_WR(TFU_COMPDLY_CONF_0_ADDR, (REG_PL_RD(TFU_COMPDLY_CONF_0_ADDR) & ~((uint32_t)0x00200000)) | ((uint32_t)swrxvectorupdatedisable <<21));
}
__INLINE void tfu_compdly_conf_0_ndp_he_num_ltf_override_setf(uint8_t ndphenumltfoverride)
{
	ASSERT_ERR((((uint32_t)ndphenumltfoverride << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(TFU_COMPDLY_CONF_0_ADDR, (REG_PL_RD(TFU_COMPDLY_CONF_0_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)ndphenumltfoverride <<20));
}
__INLINE uint8_t tfu_compdly_conf_0_ndp_he_num_ltf_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_COMPDLY_CONF_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00070000)) >> 16);
}
__INLINE void tfu_compdly_conf_0_ndp_he_num_ltf_setf(uint8_t ndphenumltf)
{
	ASSERT_ERR((((uint32_t)ndphenumltf << 16) & ~((uint32_t)0x00070000)) == 0);
	REG_PL_WR(TFU_COMPDLY_CONF_0_ADDR, (REG_PL_RD(TFU_COMPDLY_CONF_0_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)ndphenumltf <<16));
}
__INLINE uint16_t tfu_compdly_conf_0_comp_dly_4_dc_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_COMPDLY_CONF_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void tfu_compdly_conf_0_comp_dly_4_dc_setf(uint16_t compdly4dc)
{
	ASSERT_ERR((((uint32_t)compdly4dc << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(TFU_COMPDLY_CONF_0_ADDR, (REG_PL_RD(TFU_COMPDLY_CONF_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)compdly4dc <<0));
}

/**
 * @brief COMPDLY_CONF_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMP_DLY_GI1600           0x0
 *    15:00 COMP_DLY_GI3200           0x0
 * </pre>
 */
#define TFU_COMPDLY_CONF_1_ADDR        (REG_TFU_BASE_ADDR+0x000000C8)
#define TFU_COMPDLY_CONF_1_OFFSET      0x000000C8
#define TFU_COMPDLY_CONF_1_INDEX       0x00000032
#define TFU_COMPDLY_CONF_1_RESET       0x00000000

__INLINE uint32_t  tfu_compdly_conf_1_get(void)
{
	return REG_PL_RD(TFU_COMPDLY_CONF_1_ADDR);
}

__INLINE void tfu_compdly_conf_1_set(uint32_t value)
{
	REG_PL_WR(TFU_COMPDLY_CONF_1_ADDR, value);
}

// field definitions
#define TFU_COMPDLY_CONF_1_COMP_DLY_GI_1600_MASK    ((uint32_t)0xFFFF0000)
#define TFU_COMPDLY_CONF_1_COMP_DLY_GI_1600_LSB    16
#define TFU_COMPDLY_CONF_1_COMP_DLY_GI_1600_WIDTH    ((uint32_t)0x00000010)
#define TFU_COMPDLY_CONF_1_COMP_DLY_GI_3200_MASK    ((uint32_t)0x0000FFFF)
#define TFU_COMPDLY_CONF_1_COMP_DLY_GI_3200_LSB    0
#define TFU_COMPDLY_CONF_1_COMP_DLY_GI_3200_WIDTH    ((uint32_t)0x00000010)

#define TFU_COMPDLY_CONF_1_COMP_DLY_GI_1600_RST    0x0
#define TFU_COMPDLY_CONF_1_COMP_DLY_GI_3200_RST    0x0

__INLINE void tfu_compdly_conf_1_pack(uint16_t comp_dly_gi1600, uint16_t comp_dly_gi3200)
{
	ASSERT_ERR((((uint32_t)comp_dly_gi1600 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)comp_dly_gi3200 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(TFU_COMPDLY_CONF_1_ADDR,  ((uint32_t)comp_dly_gi1600 << 16) |((uint32_t)comp_dly_gi3200 << 0));
}

__INLINE void tfu_compdly_conf_1_unpack(uint16_t* comp_dly_gi1600, uint16_t* comp_dly_gi3200)
{
	uint32_t localVal = REG_PL_RD(TFU_COMPDLY_CONF_1_ADDR);

	*comp_dly_gi1600 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*comp_dly_gi3200 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t tfu_compdly_conf_1_comp_dly_gi_1600_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_COMPDLY_CONF_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void tfu_compdly_conf_1_comp_dly_gi_1600_setf(uint16_t compdlygi1600)
{
	ASSERT_ERR((((uint32_t)compdlygi1600 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(TFU_COMPDLY_CONF_1_ADDR, (REG_PL_RD(TFU_COMPDLY_CONF_1_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)compdlygi1600 <<16));
}
__INLINE uint16_t tfu_compdly_conf_1_comp_dly_gi_3200_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_COMPDLY_CONF_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void tfu_compdly_conf_1_comp_dly_gi_3200_setf(uint16_t compdlygi3200)
{
	ASSERT_ERR((((uint32_t)compdlygi3200 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(TFU_COMPDLY_CONF_1_ADDR, (REG_PL_RD(TFU_COMPDLY_CONF_1_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)compdlygi3200 <<0));
}

/**
 * @brief COMPDLY_CONF_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 COMP_DLY_GI400            0x0
 *    15:00 COMP_DLY_GI800            0x8600
 * </pre>
 */
#define TFU_COMPDLY_CONF_2_ADDR        (REG_TFU_BASE_ADDR+0x000000CC)
#define TFU_COMPDLY_CONF_2_OFFSET      0x000000CC
#define TFU_COMPDLY_CONF_2_INDEX       0x00000033
#define TFU_COMPDLY_CONF_2_RESET       0x00008600

__INLINE uint32_t  tfu_compdly_conf_2_get(void)
{
	return REG_PL_RD(TFU_COMPDLY_CONF_2_ADDR);
}

__INLINE void tfu_compdly_conf_2_set(uint32_t value)
{
	REG_PL_WR(TFU_COMPDLY_CONF_2_ADDR, value);
}

// field definitions
#define TFU_COMPDLY_CONF_2_COMP_DLY_GI_400_MASK    ((uint32_t)0xFFFF0000)
#define TFU_COMPDLY_CONF_2_COMP_DLY_GI_400_LSB    16
#define TFU_COMPDLY_CONF_2_COMP_DLY_GI_400_WIDTH    ((uint32_t)0x00000010)
#define TFU_COMPDLY_CONF_2_COMP_DLY_GI_800_MASK    ((uint32_t)0x0000FFFF)
#define TFU_COMPDLY_CONF_2_COMP_DLY_GI_800_LSB    0
#define TFU_COMPDLY_CONF_2_COMP_DLY_GI_800_WIDTH    ((uint32_t)0x00000010)

#define TFU_COMPDLY_CONF_2_COMP_DLY_GI_400_RST    0x0
#define TFU_COMPDLY_CONF_2_COMP_DLY_GI_800_RST    0x8600

__INLINE void tfu_compdly_conf_2_pack(uint16_t comp_dly_gi400, uint16_t comp_dly_gi800)
{
	ASSERT_ERR((((uint32_t)comp_dly_gi400 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)comp_dly_gi800 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(TFU_COMPDLY_CONF_2_ADDR,  ((uint32_t)comp_dly_gi400 << 16) |((uint32_t)comp_dly_gi800 << 0));
}

__INLINE void tfu_compdly_conf_2_unpack(uint16_t* comp_dly_gi400, uint16_t* comp_dly_gi800)
{
	uint32_t localVal = REG_PL_RD(TFU_COMPDLY_CONF_2_ADDR);

	*comp_dly_gi400 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*comp_dly_gi800 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t tfu_compdly_conf_2_comp_dly_gi_400_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_COMPDLY_CONF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void tfu_compdly_conf_2_comp_dly_gi_400_setf(uint16_t compdlygi400)
{
	ASSERT_ERR((((uint32_t)compdlygi400 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(TFU_COMPDLY_CONF_2_ADDR, (REG_PL_RD(TFU_COMPDLY_CONF_2_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)compdlygi400 <<16));
}
__INLINE uint16_t tfu_compdly_conf_2_comp_dly_gi_800_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_COMPDLY_CONF_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void tfu_compdly_conf_2_comp_dly_gi_800_setf(uint16_t compdlygi800)
{
	ASSERT_ERR((((uint32_t)compdlygi800 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(TFU_COMPDLY_CONF_2_ADDR, (REG_PL_RD(TFU_COMPDLY_CONF_2_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)compdlygi800 <<0));
}

/**
 * @brief MICTOR_CONF register definition
 *  Debug mictor configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:28 mictor_fob_sel            0x0
 *    27:25 mictor_user_sel           0x0
 *    24:20 mictor5_sel               0x0
 *    18:14 mictor4_sel               0x0
 *    12:08 mictor3_sel               0x0
 *    07:04 mictor2_sel               0x0
 *    03:00 mictor1_sel               0x0
 * </pre>
 */
#define TFU_MICTOR_CONF_ADDR        (REG_TFU_BASE_ADDR+0x000000D0)
#define TFU_MICTOR_CONF_OFFSET      0x000000D0
#define TFU_MICTOR_CONF_INDEX       0x00000034
#define TFU_MICTOR_CONF_RESET       0x00000000

__INLINE uint32_t  tfu_mictor_conf_get(void)
{
	return REG_PL_RD(TFU_MICTOR_CONF_ADDR);
}

__INLINE void tfu_mictor_conf_set(uint32_t value)
{
	REG_PL_WR(TFU_MICTOR_CONF_ADDR, value);
}

// field definitions
#define TFU_MICTOR_CONF_MICTOR_FOB_SEL_MASK    ((uint32_t)0xF0000000)
#define TFU_MICTOR_CONF_MICTOR_FOB_SEL_LSB    28
#define TFU_MICTOR_CONF_MICTOR_FOB_SEL_WIDTH    ((uint32_t)0x00000004)
#define TFU_MICTOR_CONF_MICTOR_USER_SEL_MASK    ((uint32_t)0x0E000000)
#define TFU_MICTOR_CONF_MICTOR_USER_SEL_LSB    25
#define TFU_MICTOR_CONF_MICTOR_USER_SEL_WIDTH    ((uint32_t)0x00000003)
#define TFU_MICTOR_CONF_MICTOR_5_SEL_MASK    ((uint32_t)0x01F00000)
#define TFU_MICTOR_CONF_MICTOR_5_SEL_LSB    20
#define TFU_MICTOR_CONF_MICTOR_5_SEL_WIDTH    ((uint32_t)0x00000005)
#define TFU_MICTOR_CONF_MICTOR_4_SEL_MASK    ((uint32_t)0x0007C000)
#define TFU_MICTOR_CONF_MICTOR_4_SEL_LSB    14
#define TFU_MICTOR_CONF_MICTOR_4_SEL_WIDTH    ((uint32_t)0x00000005)
#define TFU_MICTOR_CONF_MICTOR_3_SEL_MASK    ((uint32_t)0x00001F00)
#define TFU_MICTOR_CONF_MICTOR_3_SEL_LSB    8
#define TFU_MICTOR_CONF_MICTOR_3_SEL_WIDTH    ((uint32_t)0x00000005)
#define TFU_MICTOR_CONF_MICTOR_2_SEL_MASK    ((uint32_t)0x000000F0)
#define TFU_MICTOR_CONF_MICTOR_2_SEL_LSB    4
#define TFU_MICTOR_CONF_MICTOR_2_SEL_WIDTH    ((uint32_t)0x00000004)
#define TFU_MICTOR_CONF_MICTOR_1_SEL_MASK    ((uint32_t)0x0000000F)
#define TFU_MICTOR_CONF_MICTOR_1_SEL_LSB    0
#define TFU_MICTOR_CONF_MICTOR_1_SEL_WIDTH    ((uint32_t)0x00000004)

#define TFU_MICTOR_CONF_MICTOR_FOB_SEL_RST    0x0
#define TFU_MICTOR_CONF_MICTOR_USER_SEL_RST    0x0
#define TFU_MICTOR_CONF_MICTOR_5_SEL_RST    0x0
#define TFU_MICTOR_CONF_MICTOR_4_SEL_RST    0x0
#define TFU_MICTOR_CONF_MICTOR_3_SEL_RST    0x0
#define TFU_MICTOR_CONF_MICTOR_2_SEL_RST    0x0
#define TFU_MICTOR_CONF_MICTOR_1_SEL_RST    0x0

__INLINE void tfu_mictor_conf_pack(uint8_t mictor_fob_sel, uint8_t mictor_user_sel, uint8_t mictor5_sel, uint8_t mictor4_sel, uint8_t mictor3_sel, uint8_t mictor2_sel, uint8_t mictor1_sel)
{
	ASSERT_ERR((((uint32_t)mictor_fob_sel << 28) & ~((uint32_t)0xF0000000)) == 0);
	ASSERT_ERR((((uint32_t)mictor_user_sel << 25) & ~((uint32_t)0x0E000000)) == 0);
	ASSERT_ERR((((uint32_t)mictor5_sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	ASSERT_ERR((((uint32_t)mictor4_sel << 14) & ~((uint32_t)0x0007C000)) == 0);
	ASSERT_ERR((((uint32_t)mictor3_sel << 8) & ~((uint32_t)0x00001F00)) == 0);
	ASSERT_ERR((((uint32_t)mictor2_sel << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)mictor1_sel << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(TFU_MICTOR_CONF_ADDR,  ((uint32_t)mictor_fob_sel << 28) |((uint32_t)mictor_user_sel << 25) |((uint32_t)mictor5_sel << 20) |((uint32_t)mictor4_sel << 14) |((uint32_t)mictor3_sel << 8) |((uint32_t)mictor2_sel << 4) |((uint32_t)mictor1_sel << 0));
}

__INLINE void tfu_mictor_conf_unpack(uint8_t* mictor_fob_sel, uint8_t* mictor_user_sel, uint8_t* mictor5_sel, uint8_t* mictor4_sel, uint8_t* mictor3_sel, uint8_t* mictor2_sel, uint8_t* mictor1_sel)
{
	uint32_t localVal = REG_PL_RD(TFU_MICTOR_CONF_ADDR);

	*mictor_fob_sel = (localVal & ((uint32_t)0xF0000000)) >>  28;
	*mictor_user_sel = (localVal & ((uint32_t)0x0E000000)) >>  25;
	*mictor5_sel = (localVal & ((uint32_t)0x01F00000)) >>  20;
	*mictor4_sel = (localVal & ((uint32_t)0x0007C000)) >>  14;
	*mictor3_sel = (localVal & ((uint32_t)0x00001F00)) >>  8;
	*mictor2_sel = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*mictor1_sel = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t tfu_mictor_conf_mictor_fob_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MICTOR_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xF0000000)) >> 28);
}
__INLINE void tfu_mictor_conf_mictor_fob_sel_setf(uint8_t mictorfobsel)
{
	ASSERT_ERR((((uint32_t)mictorfobsel << 28) & ~((uint32_t)0xF0000000)) == 0);
	REG_PL_WR(TFU_MICTOR_CONF_ADDR, (REG_PL_RD(TFU_MICTOR_CONF_ADDR) & ~((uint32_t)0xF0000000)) | ((uint32_t)mictorfobsel <<28));
}
__INLINE uint8_t tfu_mictor_conf_mictor_user_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MICTOR_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0E000000)) >> 25);
}
__INLINE void tfu_mictor_conf_mictor_user_sel_setf(uint8_t mictorusersel)
{
	ASSERT_ERR((((uint32_t)mictorusersel << 25) & ~((uint32_t)0x0E000000)) == 0);
	REG_PL_WR(TFU_MICTOR_CONF_ADDR, (REG_PL_RD(TFU_MICTOR_CONF_ADDR) & ~((uint32_t)0x0E000000)) | ((uint32_t)mictorusersel <<25));
}
__INLINE uint8_t tfu_mictor_conf_mictor_5_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MICTOR_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01F00000)) >> 20);
}
__INLINE void tfu_mictor_conf_mictor_5_sel_setf(uint8_t mictor5sel)
{
	ASSERT_ERR((((uint32_t)mictor5sel << 20) & ~((uint32_t)0x01F00000)) == 0);
	REG_PL_WR(TFU_MICTOR_CONF_ADDR, (REG_PL_RD(TFU_MICTOR_CONF_ADDR) & ~((uint32_t)0x01F00000)) | ((uint32_t)mictor5sel <<20));
}
__INLINE uint8_t tfu_mictor_conf_mictor_4_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MICTOR_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0007C000)) >> 14);
}
__INLINE void tfu_mictor_conf_mictor_4_sel_setf(uint8_t mictor4sel)
{
	ASSERT_ERR((((uint32_t)mictor4sel << 14) & ~((uint32_t)0x0007C000)) == 0);
	REG_PL_WR(TFU_MICTOR_CONF_ADDR, (REG_PL_RD(TFU_MICTOR_CONF_ADDR) & ~((uint32_t)0x0007C000)) | ((uint32_t)mictor4sel <<14));
}
__INLINE uint8_t tfu_mictor_conf_mictor_3_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MICTOR_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001F00)) >> 8);
}
__INLINE void tfu_mictor_conf_mictor_3_sel_setf(uint8_t mictor3sel)
{
	ASSERT_ERR((((uint32_t)mictor3sel << 8) & ~((uint32_t)0x00001F00)) == 0);
	REG_PL_WR(TFU_MICTOR_CONF_ADDR, (REG_PL_RD(TFU_MICTOR_CONF_ADDR) & ~((uint32_t)0x00001F00)) | ((uint32_t)mictor3sel <<8));
}
__INLINE uint8_t tfu_mictor_conf_mictor_2_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MICTOR_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void tfu_mictor_conf_mictor_2_sel_setf(uint8_t mictor2sel)
{
	ASSERT_ERR((((uint32_t)mictor2sel << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(TFU_MICTOR_CONF_ADDR, (REG_PL_RD(TFU_MICTOR_CONF_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)mictor2sel <<4));
}
__INLINE uint8_t tfu_mictor_conf_mictor_1_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_MICTOR_CONF_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void tfu_mictor_conf_mictor_1_sel_setf(uint8_t mictor1sel)
{
	ASSERT_ERR((((uint32_t)mictor1sel << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(TFU_MICTOR_CONF_ADDR, (REG_PL_RD(TFU_MICTOR_CONF_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)mictor1sel <<0));
}

/**
 * @brief STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    26:16 Rx_HWAM2_Sync             0x0
 *    13    RX_DONE                   0              
 *    12    RX_ON_GOING               0              
 *    09    TX_DONE                   0              
 *    08    TX_ON_GOING               0              
 *    04    DC_UPDATED                0              
 *    01:00 MEM_PTR_USED              0x0
 * </pre>
 */
#define TFU_STATUS_ADDR        (REG_TFU_BASE_ADDR+0x00000200)
#define TFU_STATUS_OFFSET      0x00000200
#define TFU_STATUS_INDEX       0x00000080
#define TFU_STATUS_RESET       0x00000000

__INLINE uint32_t  tfu_status_get(void)
{
	return REG_PL_RD(TFU_STATUS_ADDR);
}

// field definitions
#define TFU_STATUS_RX_HWAM_2_SYNC_MASK      ((uint32_t)0x07FF0000)
#define TFU_STATUS_RX_HWAM_2_SYNC_LSB       16
#define TFU_STATUS_RX_HWAM_2_SYNC_WIDTH     ((uint32_t)0x0000000B)
#define TFU_STATUS_RX_DONE_BIT              ((uint32_t)0x00002000)
#define TFU_STATUS_RX_DONE_POS              13
#define TFU_STATUS_RX_ON_GOING_BIT          ((uint32_t)0x00001000)
#define TFU_STATUS_RX_ON_GOING_POS          12
#define TFU_STATUS_TX_DONE_BIT              ((uint32_t)0x00000200)
#define TFU_STATUS_TX_DONE_POS              9
#define TFU_STATUS_TX_ON_GOING_BIT          ((uint32_t)0x00000100)
#define TFU_STATUS_TX_ON_GOING_POS          8
#define TFU_STATUS_DC_UPDATED_BIT           ((uint32_t)0x00000010)
#define TFU_STATUS_DC_UPDATED_POS           4
#define TFU_STATUS_MEM_PTR_USED_MASK        ((uint32_t)0x00000003)
#define TFU_STATUS_MEM_PTR_USED_LSB         0
#define TFU_STATUS_MEM_PTR_USED_WIDTH       ((uint32_t)0x00000002)

#define TFU_STATUS_RX_HWAM_2_SYNC_RST       0x0
#define TFU_STATUS_RX_DONE_RST              0x0
#define TFU_STATUS_RX_ON_GOING_RST          0x0
#define TFU_STATUS_TX_DONE_RST              0x0
#define TFU_STATUS_TX_ON_GOING_RST          0x0
#define TFU_STATUS_DC_UPDATED_RST           0x0
#define TFU_STATUS_MEM_PTR_USED_RST         0x0

__INLINE void tfu_status_unpack(uint16_t* rx_hwam2_sync, uint8_t* rx_done, uint8_t* rx_on_going, uint8_t* tx_done, uint8_t* tx_on_going, uint8_t* dc_updated, uint8_t* mem_ptr_used)
{
	uint32_t localVal = REG_PL_RD(TFU_STATUS_ADDR);

	*rx_hwam2_sync = (localVal & ((uint32_t)0x07FF0000)) >>  16;
	*rx_done = (localVal & ((uint32_t)0x00002000)) >>  13;
	*rx_on_going = (localVal & ((uint32_t)0x00001000)) >>  12;
	*tx_done = (localVal & ((uint32_t)0x00000200)) >>  9;
	*tx_on_going = (localVal & ((uint32_t)0x00000100)) >>  8;
	*dc_updated = (localVal & ((uint32_t)0x00000010)) >>  4;
	*mem_ptr_used = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint16_t tfu_status_rx_hwam_2_sync_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATUS_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x07FF0000)) >> 16);
}
__INLINE uint8_t tfu_status_rx_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE uint8_t tfu_status_rx_on_going_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t tfu_status_tx_done_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t tfu_status_tx_on_going_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE uint8_t tfu_status_dc_updated_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t tfu_status_mem_ptr_used_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_STATUS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}

/**
 * @brief DMA_ALIGN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:00 DMA_ALIGN_ADDR            0x0
 * </pre>
 */
#define TFU_DMA_ALIGN_ADDR        (REG_TFU_BASE_ADDR+0x00000204)
#define TFU_DMA_ALIGN_OFFSET      0x00000204
#define TFU_DMA_ALIGN_INDEX       0x00000081
#define TFU_DMA_ALIGN_RESET       0x00000000

__INLINE uint32_t  tfu_dma_align_get(void)
{
	return REG_PL_RD(TFU_DMA_ALIGN_ADDR);
}

// field definitions
#define TFU_DMA_ALIGN_DMA_ALIGN_ADDR_MASK    ((uint32_t)0x00FFFFFF)
#define TFU_DMA_ALIGN_DMA_ALIGN_ADDR_LSB    0
#define TFU_DMA_ALIGN_DMA_ALIGN_ADDR_WIDTH    ((uint32_t)0x00000018)

#define TFU_DMA_ALIGN_DMA_ALIGN_ADDR_RST    0x0

__INLINE uint32_t tfu_dma_align_dma_align_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DMA_ALIGN_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief HE_PILOT_MEM_PTR_0 register definition
 *  Pointer to Rx symbol pilot buffer 0 and 1  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_HELTF_PILOT_PTR1       0x0
 *    15:00 RX_HELTF_PILOT_PTR0       0x0
 * </pre>
 */
#define TFU_HE_PILOT_MEM_PTR_0_ADDR        (REG_TFU_BASE_ADDR+0x00000220)
#define TFU_HE_PILOT_MEM_PTR_0_OFFSET      0x00000220
#define TFU_HE_PILOT_MEM_PTR_0_INDEX       0x00000088
#define TFU_HE_PILOT_MEM_PTR_0_RESET       0x00000000

__INLINE uint32_t  tfu_he_pilot_mem_ptr_0_get(void)
{
	return REG_PL_RD(TFU_HE_PILOT_MEM_PTR_0_ADDR);
}

__INLINE void tfu_he_pilot_mem_ptr_0_set(uint32_t value)
{
	REG_PL_WR(TFU_HE_PILOT_MEM_PTR_0_ADDR, value);
}

// field definitions
#define TFU_HE_PILOT_MEM_PTR_0_RX_HELTF_PILOT_PTR_1_MASK    ((uint32_t)0xFFFF0000)
#define TFU_HE_PILOT_MEM_PTR_0_RX_HELTF_PILOT_PTR_1_LSB    16
#define TFU_HE_PILOT_MEM_PTR_0_RX_HELTF_PILOT_PTR_1_WIDTH    ((uint32_t)0x00000010)
#define TFU_HE_PILOT_MEM_PTR_0_RX_HELTF_PILOT_PTR_0_MASK    ((uint32_t)0x0000FFFF)
#define TFU_HE_PILOT_MEM_PTR_0_RX_HELTF_PILOT_PTR_0_LSB    0
#define TFU_HE_PILOT_MEM_PTR_0_RX_HELTF_PILOT_PTR_0_WIDTH    ((uint32_t)0x00000010)

#define TFU_HE_PILOT_MEM_PTR_0_RX_HELTF_PILOT_PTR_1_RST    0x0
#define TFU_HE_PILOT_MEM_PTR_0_RX_HELTF_PILOT_PTR_0_RST    0x0

__INLINE void tfu_he_pilot_mem_ptr_0_pack(uint16_t rx_heltf_pilot_ptr1, uint16_t rx_heltf_pilot_ptr0)
{
	ASSERT_ERR((((uint32_t)rx_heltf_pilot_ptr1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_heltf_pilot_ptr0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(TFU_HE_PILOT_MEM_PTR_0_ADDR,  ((uint32_t)rx_heltf_pilot_ptr1 << 16) |((uint32_t)rx_heltf_pilot_ptr0 << 0));
}

__INLINE void tfu_he_pilot_mem_ptr_0_unpack(uint16_t* rx_heltf_pilot_ptr1, uint16_t* rx_heltf_pilot_ptr0)
{
	uint32_t localVal = REG_PL_RD(TFU_HE_PILOT_MEM_PTR_0_ADDR);

	*rx_heltf_pilot_ptr1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_heltf_pilot_ptr0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t tfu_he_pilot_mem_ptr_0_rx_heltf_pilot_ptr_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_HE_PILOT_MEM_PTR_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void tfu_he_pilot_mem_ptr_0_rx_heltf_pilot_ptr_1_setf(uint16_t rxheltfpilotptr1)
{
	ASSERT_ERR((((uint32_t)rxheltfpilotptr1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(TFU_HE_PILOT_MEM_PTR_0_ADDR, (REG_PL_RD(TFU_HE_PILOT_MEM_PTR_0_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxheltfpilotptr1 <<16));
}
__INLINE uint16_t tfu_he_pilot_mem_ptr_0_rx_heltf_pilot_ptr_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_HE_PILOT_MEM_PTR_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void tfu_he_pilot_mem_ptr_0_rx_heltf_pilot_ptr_0_setf(uint16_t rxheltfpilotptr0)
{
	ASSERT_ERR((((uint32_t)rxheltfpilotptr0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(TFU_HE_PILOT_MEM_PTR_0_ADDR, (REG_PL_RD(TFU_HE_PILOT_MEM_PTR_0_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxheltfpilotptr0 <<0));
}

/**
 * @brief HE_PILOT_MEM_PTR_1 register definition
 *  Pointer to Rx symbol pilot buffer 2 and 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 RX_HELTF_PILOT_PTR3       0x0
 *    15:00 RX_HELTF_PILOT_PTR2       0x0
 * </pre>
 */
#define TFU_HE_PILOT_MEM_PTR_1_ADDR        (REG_TFU_BASE_ADDR+0x00000224)
#define TFU_HE_PILOT_MEM_PTR_1_OFFSET      0x00000224
#define TFU_HE_PILOT_MEM_PTR_1_INDEX       0x00000089
#define TFU_HE_PILOT_MEM_PTR_1_RESET       0x00000000

__INLINE uint32_t  tfu_he_pilot_mem_ptr_1_get(void)
{
	return REG_PL_RD(TFU_HE_PILOT_MEM_PTR_1_ADDR);
}

__INLINE void tfu_he_pilot_mem_ptr_1_set(uint32_t value)
{
	REG_PL_WR(TFU_HE_PILOT_MEM_PTR_1_ADDR, value);
}

// field definitions
#define TFU_HE_PILOT_MEM_PTR_1_RX_HELTF_PILOT_PTR_3_MASK    ((uint32_t)0xFFFF0000)
#define TFU_HE_PILOT_MEM_PTR_1_RX_HELTF_PILOT_PTR_3_LSB    16
#define TFU_HE_PILOT_MEM_PTR_1_RX_HELTF_PILOT_PTR_3_WIDTH    ((uint32_t)0x00000010)
#define TFU_HE_PILOT_MEM_PTR_1_RX_HELTF_PILOT_PTR_2_MASK    ((uint32_t)0x0000FFFF)
#define TFU_HE_PILOT_MEM_PTR_1_RX_HELTF_PILOT_PTR_2_LSB    0
#define TFU_HE_PILOT_MEM_PTR_1_RX_HELTF_PILOT_PTR_2_WIDTH    ((uint32_t)0x00000010)

#define TFU_HE_PILOT_MEM_PTR_1_RX_HELTF_PILOT_PTR_3_RST    0x0
#define TFU_HE_PILOT_MEM_PTR_1_RX_HELTF_PILOT_PTR_2_RST    0x0

__INLINE void tfu_he_pilot_mem_ptr_1_pack(uint16_t rx_heltf_pilot_ptr3, uint16_t rx_heltf_pilot_ptr2)
{
	ASSERT_ERR((((uint32_t)rx_heltf_pilot_ptr3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)rx_heltf_pilot_ptr2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(TFU_HE_PILOT_MEM_PTR_1_ADDR,  ((uint32_t)rx_heltf_pilot_ptr3 << 16) |((uint32_t)rx_heltf_pilot_ptr2 << 0));
}

__INLINE void tfu_he_pilot_mem_ptr_1_unpack(uint16_t* rx_heltf_pilot_ptr3, uint16_t* rx_heltf_pilot_ptr2)
{
	uint32_t localVal = REG_PL_RD(TFU_HE_PILOT_MEM_PTR_1_ADDR);

	*rx_heltf_pilot_ptr3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*rx_heltf_pilot_ptr2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t tfu_he_pilot_mem_ptr_1_rx_heltf_pilot_ptr_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_HE_PILOT_MEM_PTR_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void tfu_he_pilot_mem_ptr_1_rx_heltf_pilot_ptr_3_setf(uint16_t rxheltfpilotptr3)
{
	ASSERT_ERR((((uint32_t)rxheltfpilotptr3 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(TFU_HE_PILOT_MEM_PTR_1_ADDR, (REG_PL_RD(TFU_HE_PILOT_MEM_PTR_1_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)rxheltfpilotptr3 <<16));
}
__INLINE uint16_t tfu_he_pilot_mem_ptr_1_rx_heltf_pilot_ptr_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_HE_PILOT_MEM_PTR_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void tfu_he_pilot_mem_ptr_1_rx_heltf_pilot_ptr_2_setf(uint16_t rxheltfpilotptr2)
{
	ASSERT_ERR((((uint32_t)rxheltfpilotptr2 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(TFU_HE_PILOT_MEM_PTR_1_ADDR, (REG_PL_RD(TFU_HE_PILOT_MEM_PTR_1_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)rxheltfpilotptr2 <<0));
}

/**
 * @brief TX_SAMPLE_ADJ register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    TX_SAMPLE_ADD             0              
 *    00    TX_SAMPLE_SKIP            0              
 * </pre>
 */
#define TFU_TX_SAMPLE_ADJ_ADDR        (REG_TFU_BASE_ADDR+0x00000228)
#define TFU_TX_SAMPLE_ADJ_OFFSET      0x00000228
#define TFU_TX_SAMPLE_ADJ_INDEX       0x0000008A
#define TFU_TX_SAMPLE_ADJ_RESET       0x00000000

__INLINE uint32_t  tfu_tx_sample_adj_get(void)
{
	return REG_PL_RD(TFU_TX_SAMPLE_ADJ_ADDR);
}

__INLINE void tfu_tx_sample_adj_set(uint32_t value)
{
	REG_PL_WR(TFU_TX_SAMPLE_ADJ_ADDR, value);
}

// field definitions
#define TFU_TX_SAMPLE_ADJ_TX_SAMPLE_ADD_BIT    ((uint32_t)0x00000002)
#define TFU_TX_SAMPLE_ADJ_TX_SAMPLE_ADD_POS    1
#define TFU_TX_SAMPLE_ADJ_TX_SAMPLE_SKIP_BIT    ((uint32_t)0x00000001)
#define TFU_TX_SAMPLE_ADJ_TX_SAMPLE_SKIP_POS    0

#define TFU_TX_SAMPLE_ADJ_TX_SAMPLE_ADD_RST    0x0
#define TFU_TX_SAMPLE_ADJ_TX_SAMPLE_SKIP_RST    0x0

__INLINE void tfu_tx_sample_adj_pack(uint8_t tx_sample_add, uint8_t tx_sample_skip)
{
	ASSERT_ERR((((uint32_t)tx_sample_add << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)tx_sample_skip << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(TFU_TX_SAMPLE_ADJ_ADDR,  ((uint32_t)tx_sample_add << 1) |((uint32_t)tx_sample_skip << 0));
}

__INLINE void tfu_tx_sample_adj_unpack(uint8_t* tx_sample_add, uint8_t* tx_sample_skip)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_SAMPLE_ADJ_ADDR);

	*tx_sample_add = (localVal & ((uint32_t)0x00000002)) >>  1;
	*tx_sample_skip = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t tfu_tx_sample_adj_tx_sample_add_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_SAMPLE_ADJ_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void tfu_tx_sample_adj_tx_sample_add_setf(uint8_t txsampleadd)
{
	ASSERT_ERR((((uint32_t)txsampleadd << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(TFU_TX_SAMPLE_ADJ_ADDR, (REG_PL_RD(TFU_TX_SAMPLE_ADJ_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)txsampleadd <<1));
}
__INLINE uint8_t tfu_tx_sample_adj_tx_sample_skip_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_SAMPLE_ADJ_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void tfu_tx_sample_adj_tx_sample_skip_setf(uint8_t txsampleskip)
{
	ASSERT_ERR((((uint32_t)txsampleskip << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(TFU_TX_SAMPLE_ADJ_ADDR, (REG_PL_RD(TFU_TX_SAMPLE_ADJ_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)txsampleskip <<0));
}

/**
 * @brief DC_OFFSET_EST_ANT_0 register definition
 *  HW DC estimation of I/Q ANT0 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:16 DC_OFFSET_EST_ANT_Q_0     0x0
 *    14:00 DC_OFFSET_EST_ANT_I_0     0x0
 * </pre>
 */
#define TFU_DC_OFFSET_EST_ANT_0_ADDR        (REG_TFU_BASE_ADDR+0x00000240)
#define TFU_DC_OFFSET_EST_ANT_0_OFFSET      0x00000240
#define TFU_DC_OFFSET_EST_ANT_0_INDEX       0x00000090
#define TFU_DC_OFFSET_EST_ANT_0_RESET       0x00000000

__INLINE uint32_t  tfu_dc_offset_est_ant_0_get(void)
{
	return REG_PL_RD(TFU_DC_OFFSET_EST_ANT_0_ADDR);
}

// field definitions
#define TFU_DC_OFFSET_EST_ANT_0_DC_OFFSET_EST_ANT_Q_0_MASK    ((uint32_t)0x7FFF0000)
#define TFU_DC_OFFSET_EST_ANT_0_DC_OFFSET_EST_ANT_Q_0_LSB    16
#define TFU_DC_OFFSET_EST_ANT_0_DC_OFFSET_EST_ANT_Q_0_WIDTH    ((uint32_t)0x0000000F)
#define TFU_DC_OFFSET_EST_ANT_0_DC_OFFSET_EST_ANT_I_0_MASK    ((uint32_t)0x00007FFF)
#define TFU_DC_OFFSET_EST_ANT_0_DC_OFFSET_EST_ANT_I_0_LSB    0
#define TFU_DC_OFFSET_EST_ANT_0_DC_OFFSET_EST_ANT_I_0_WIDTH    ((uint32_t)0x0000000F)

#define TFU_DC_OFFSET_EST_ANT_0_DC_OFFSET_EST_ANT_Q_0_RST    0x0
#define TFU_DC_OFFSET_EST_ANT_0_DC_OFFSET_EST_ANT_I_0_RST    0x0

__INLINE void tfu_dc_offset_est_ant_0_unpack(uint16_t* dc_offset_est_ant_q_0, uint16_t* dc_offset_est_ant_i_0)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_OFFSET_EST_ANT_0_ADDR);

	*dc_offset_est_ant_q_0 = (localVal & ((uint32_t)0x7FFF0000)) >>  16;
	*dc_offset_est_ant_i_0 = (localVal & ((uint32_t)0x00007FFF)) >>  0;
}

__INLINE uint16_t tfu_dc_offset_est_ant_0_dc_offset_est_ant_q_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_OFFSET_EST_ANT_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x7FFF0000)) >> 16);
}
__INLINE uint16_t tfu_dc_offset_est_ant_0_dc_offset_est_ant_i_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_OFFSET_EST_ANT_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00007FFF)) >> 0);
}

/**
 * @brief DC_OFFSET_EST_ANT_1 register definition
 *  HW DC estimation of I/Q ANT1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:16 DC_OFFSET_EST_ANT_Q_1     0x0
 *    14:00 DC_OFFSET_EST_ANT_I_1     0x0
 * </pre>
 */
#define TFU_DC_OFFSET_EST_ANT_1_ADDR        (REG_TFU_BASE_ADDR+0x00000244)
#define TFU_DC_OFFSET_EST_ANT_1_OFFSET      0x00000244
#define TFU_DC_OFFSET_EST_ANT_1_INDEX       0x00000091
#define TFU_DC_OFFSET_EST_ANT_1_RESET       0x00000000

__INLINE uint32_t  tfu_dc_offset_est_ant_1_get(void)
{
	return REG_PL_RD(TFU_DC_OFFSET_EST_ANT_1_ADDR);
}

// field definitions
#define TFU_DC_OFFSET_EST_ANT_1_DC_OFFSET_EST_ANT_Q_1_MASK    ((uint32_t)0x7FFF0000)
#define TFU_DC_OFFSET_EST_ANT_1_DC_OFFSET_EST_ANT_Q_1_LSB    16
#define TFU_DC_OFFSET_EST_ANT_1_DC_OFFSET_EST_ANT_Q_1_WIDTH    ((uint32_t)0x0000000F)
#define TFU_DC_OFFSET_EST_ANT_1_DC_OFFSET_EST_ANT_I_1_MASK    ((uint32_t)0x00007FFF)
#define TFU_DC_OFFSET_EST_ANT_1_DC_OFFSET_EST_ANT_I_1_LSB    0
#define TFU_DC_OFFSET_EST_ANT_1_DC_OFFSET_EST_ANT_I_1_WIDTH    ((uint32_t)0x0000000F)

#define TFU_DC_OFFSET_EST_ANT_1_DC_OFFSET_EST_ANT_Q_1_RST    0x0
#define TFU_DC_OFFSET_EST_ANT_1_DC_OFFSET_EST_ANT_I_1_RST    0x0

__INLINE void tfu_dc_offset_est_ant_1_unpack(uint16_t* dc_offset_est_ant_q_1, uint16_t* dc_offset_est_ant_i_1)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_OFFSET_EST_ANT_1_ADDR);

	*dc_offset_est_ant_q_1 = (localVal & ((uint32_t)0x7FFF0000)) >>  16;
	*dc_offset_est_ant_i_1 = (localVal & ((uint32_t)0x00007FFF)) >>  0;
}

__INLINE uint16_t tfu_dc_offset_est_ant_1_dc_offset_est_ant_q_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_OFFSET_EST_ANT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x7FFF0000)) >> 16);
}
__INLINE uint16_t tfu_dc_offset_est_ant_1_dc_offset_est_ant_i_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_OFFSET_EST_ANT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00007FFF)) >> 0);
}

/**
 * @brief DC_OFFSET_EST_ANT_2 register definition
 *  HW DC estimation of I/Q ANT2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:16 DC_OFFSET_EST_ANT_Q_2     0x0
 *    14:00 DC_OFFSET_EST_ANT_I_2     0x0
 * </pre>
 */
#define TFU_DC_OFFSET_EST_ANT_2_ADDR        (REG_TFU_BASE_ADDR+0x00000248)
#define TFU_DC_OFFSET_EST_ANT_2_OFFSET      0x00000248
#define TFU_DC_OFFSET_EST_ANT_2_INDEX       0x00000092
#define TFU_DC_OFFSET_EST_ANT_2_RESET       0x00000000

__INLINE uint32_t  tfu_dc_offset_est_ant_2_get(void)
{
	return REG_PL_RD(TFU_DC_OFFSET_EST_ANT_2_ADDR);
}

// field definitions
#define TFU_DC_OFFSET_EST_ANT_2_DC_OFFSET_EST_ANT_Q_2_MASK    ((uint32_t)0x7FFF0000)
#define TFU_DC_OFFSET_EST_ANT_2_DC_OFFSET_EST_ANT_Q_2_LSB    16
#define TFU_DC_OFFSET_EST_ANT_2_DC_OFFSET_EST_ANT_Q_2_WIDTH    ((uint32_t)0x0000000F)
#define TFU_DC_OFFSET_EST_ANT_2_DC_OFFSET_EST_ANT_I_2_MASK    ((uint32_t)0x00007FFF)
#define TFU_DC_OFFSET_EST_ANT_2_DC_OFFSET_EST_ANT_I_2_LSB    0
#define TFU_DC_OFFSET_EST_ANT_2_DC_OFFSET_EST_ANT_I_2_WIDTH    ((uint32_t)0x0000000F)

#define TFU_DC_OFFSET_EST_ANT_2_DC_OFFSET_EST_ANT_Q_2_RST    0x0
#define TFU_DC_OFFSET_EST_ANT_2_DC_OFFSET_EST_ANT_I_2_RST    0x0

__INLINE void tfu_dc_offset_est_ant_2_unpack(uint16_t* dc_offset_est_ant_q_2, uint16_t* dc_offset_est_ant_i_2)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_OFFSET_EST_ANT_2_ADDR);

	*dc_offset_est_ant_q_2 = (localVal & ((uint32_t)0x7FFF0000)) >>  16;
	*dc_offset_est_ant_i_2 = (localVal & ((uint32_t)0x00007FFF)) >>  0;
}

__INLINE uint16_t tfu_dc_offset_est_ant_2_dc_offset_est_ant_q_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_OFFSET_EST_ANT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x7FFF0000)) >> 16);
}
__INLINE uint16_t tfu_dc_offset_est_ant_2_dc_offset_est_ant_i_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_OFFSET_EST_ANT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00007FFF)) >> 0);
}

/**
 * @brief DC_OFFSET_EST_ANT_3 register definition
 *  HW DC estimation of I/Q ANT3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:16 DC_OFFSET_EST_ANT_Q_3     0x0
 *    14:00 DC_OFFSET_EST_ANT_I_3     0x0
 * </pre>
 */
#define TFU_DC_OFFSET_EST_ANT_3_ADDR        (REG_TFU_BASE_ADDR+0x0000024C)
#define TFU_DC_OFFSET_EST_ANT_3_OFFSET      0x0000024C
#define TFU_DC_OFFSET_EST_ANT_3_INDEX       0x00000093
#define TFU_DC_OFFSET_EST_ANT_3_RESET       0x00000000

__INLINE uint32_t  tfu_dc_offset_est_ant_3_get(void)
{
	return REG_PL_RD(TFU_DC_OFFSET_EST_ANT_3_ADDR);
}

// field definitions
#define TFU_DC_OFFSET_EST_ANT_3_DC_OFFSET_EST_ANT_Q_3_MASK    ((uint32_t)0x7FFF0000)
#define TFU_DC_OFFSET_EST_ANT_3_DC_OFFSET_EST_ANT_Q_3_LSB    16
#define TFU_DC_OFFSET_EST_ANT_3_DC_OFFSET_EST_ANT_Q_3_WIDTH    ((uint32_t)0x0000000F)
#define TFU_DC_OFFSET_EST_ANT_3_DC_OFFSET_EST_ANT_I_3_MASK    ((uint32_t)0x00007FFF)
#define TFU_DC_OFFSET_EST_ANT_3_DC_OFFSET_EST_ANT_I_3_LSB    0
#define TFU_DC_OFFSET_EST_ANT_3_DC_OFFSET_EST_ANT_I_3_WIDTH    ((uint32_t)0x0000000F)

#define TFU_DC_OFFSET_EST_ANT_3_DC_OFFSET_EST_ANT_Q_3_RST    0x0
#define TFU_DC_OFFSET_EST_ANT_3_DC_OFFSET_EST_ANT_I_3_RST    0x0

__INLINE void tfu_dc_offset_est_ant_3_unpack(uint16_t* dc_offset_est_ant_q_3, uint16_t* dc_offset_est_ant_i_3)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_OFFSET_EST_ANT_3_ADDR);

	*dc_offset_est_ant_q_3 = (localVal & ((uint32_t)0x7FFF0000)) >>  16;
	*dc_offset_est_ant_i_3 = (localVal & ((uint32_t)0x00007FFF)) >>  0;
}

__INLINE uint16_t tfu_dc_offset_est_ant_3_dc_offset_est_ant_q_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_OFFSET_EST_ANT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x7FFF0000)) >> 16);
}
__INLINE uint16_t tfu_dc_offset_est_ant_3_dc_offset_est_ant_i_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_OFFSET_EST_ANT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00007FFF)) >> 0);
}

/**
 * @brief DC_OFFSET_EST_ANT_4 register definition
 *  HW DC estimation of I/Q ANT4 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:16 DC_OFFSET_EST_ANT_Q_4     0x0
 *    14:00 DC_OFFSET_EST_ANT_I_4     0x0
 * </pre>
 */
#define TFU_DC_OFFSET_EST_ANT_4_ADDR        (REG_TFU_BASE_ADDR+0x00000250)
#define TFU_DC_OFFSET_EST_ANT_4_OFFSET      0x00000250
#define TFU_DC_OFFSET_EST_ANT_4_INDEX       0x00000094
#define TFU_DC_OFFSET_EST_ANT_4_RESET       0x00000000

__INLINE uint32_t  tfu_dc_offset_est_ant_4_get(void)
{
	return REG_PL_RD(TFU_DC_OFFSET_EST_ANT_4_ADDR);
}

// field definitions
#define TFU_DC_OFFSET_EST_ANT_4_DC_OFFSET_EST_ANT_Q_4_MASK    ((uint32_t)0x7FFF0000)
#define TFU_DC_OFFSET_EST_ANT_4_DC_OFFSET_EST_ANT_Q_4_LSB    16
#define TFU_DC_OFFSET_EST_ANT_4_DC_OFFSET_EST_ANT_Q_4_WIDTH    ((uint32_t)0x0000000F)
#define TFU_DC_OFFSET_EST_ANT_4_DC_OFFSET_EST_ANT_I_4_MASK    ((uint32_t)0x00007FFF)
#define TFU_DC_OFFSET_EST_ANT_4_DC_OFFSET_EST_ANT_I_4_LSB    0
#define TFU_DC_OFFSET_EST_ANT_4_DC_OFFSET_EST_ANT_I_4_WIDTH    ((uint32_t)0x0000000F)

#define TFU_DC_OFFSET_EST_ANT_4_DC_OFFSET_EST_ANT_Q_4_RST    0x0
#define TFU_DC_OFFSET_EST_ANT_4_DC_OFFSET_EST_ANT_I_4_RST    0x0

__INLINE void tfu_dc_offset_est_ant_4_unpack(uint16_t* dc_offset_est_ant_q_4, uint16_t* dc_offset_est_ant_i_4)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_OFFSET_EST_ANT_4_ADDR);

	*dc_offset_est_ant_q_4 = (localVal & ((uint32_t)0x7FFF0000)) >>  16;
	*dc_offset_est_ant_i_4 = (localVal & ((uint32_t)0x00007FFF)) >>  0;
}

__INLINE uint16_t tfu_dc_offset_est_ant_4_dc_offset_est_ant_q_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_OFFSET_EST_ANT_4_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x7FFF0000)) >> 16);
}
__INLINE uint16_t tfu_dc_offset_est_ant_4_dc_offset_est_ant_i_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_OFFSET_EST_ANT_4_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00007FFF)) >> 0);
}

/**
 * @brief DC_OFFSET_EST_ANT_5 register definition
 *  HW DC estimation of I/Q ANT5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:16 DC_OFFSET_EST_ANT_Q_5     0x0
 *    14:00 DC_OFFSET_EST_ANT_I_5     0x0
 * </pre>
 */
#define TFU_DC_OFFSET_EST_ANT_5_ADDR        (REG_TFU_BASE_ADDR+0x00000254)
#define TFU_DC_OFFSET_EST_ANT_5_OFFSET      0x00000254
#define TFU_DC_OFFSET_EST_ANT_5_INDEX       0x00000095
#define TFU_DC_OFFSET_EST_ANT_5_RESET       0x00000000

__INLINE uint32_t  tfu_dc_offset_est_ant_5_get(void)
{
	return REG_PL_RD(TFU_DC_OFFSET_EST_ANT_5_ADDR);
}

// field definitions
#define TFU_DC_OFFSET_EST_ANT_5_DC_OFFSET_EST_ANT_Q_5_MASK    ((uint32_t)0x7FFF0000)
#define TFU_DC_OFFSET_EST_ANT_5_DC_OFFSET_EST_ANT_Q_5_LSB    16
#define TFU_DC_OFFSET_EST_ANT_5_DC_OFFSET_EST_ANT_Q_5_WIDTH    ((uint32_t)0x0000000F)
#define TFU_DC_OFFSET_EST_ANT_5_DC_OFFSET_EST_ANT_I_5_MASK    ((uint32_t)0x00007FFF)
#define TFU_DC_OFFSET_EST_ANT_5_DC_OFFSET_EST_ANT_I_5_LSB    0
#define TFU_DC_OFFSET_EST_ANT_5_DC_OFFSET_EST_ANT_I_5_WIDTH    ((uint32_t)0x0000000F)

#define TFU_DC_OFFSET_EST_ANT_5_DC_OFFSET_EST_ANT_Q_5_RST    0x0
#define TFU_DC_OFFSET_EST_ANT_5_DC_OFFSET_EST_ANT_I_5_RST    0x0

__INLINE void tfu_dc_offset_est_ant_5_unpack(uint16_t* dc_offset_est_ant_q_5, uint16_t* dc_offset_est_ant_i_5)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_OFFSET_EST_ANT_5_ADDR);

	*dc_offset_est_ant_q_5 = (localVal & ((uint32_t)0x7FFF0000)) >>  16;
	*dc_offset_est_ant_i_5 = (localVal & ((uint32_t)0x00007FFF)) >>  0;
}

__INLINE uint16_t tfu_dc_offset_est_ant_5_dc_offset_est_ant_q_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_OFFSET_EST_ANT_5_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x7FFF0000)) >> 16);
}
__INLINE uint16_t tfu_dc_offset_est_ant_5_dc_offset_est_ant_i_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_OFFSET_EST_ANT_5_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00007FFF)) >> 0);
}

/**
 * @brief FREQ_OFFSET_ANT_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:00 FREQ_OFFSET_ANT0          0x0
 * </pre>
 */
#define TFU_FREQ_OFFSET_ANT_0_ADDR        (REG_TFU_BASE_ADDR+0x00000280)
#define TFU_FREQ_OFFSET_ANT_0_OFFSET      0x00000280
#define TFU_FREQ_OFFSET_ANT_0_INDEX       0x000000A0
#define TFU_FREQ_OFFSET_ANT_0_RESET       0x00000000

__INLINE uint32_t  tfu_freq_offset_ant_0_get(void)
{
	return REG_PL_RD(TFU_FREQ_OFFSET_ANT_0_ADDR);
}

__INLINE void tfu_freq_offset_ant_0_set(uint32_t value)
{
	REG_PL_WR(TFU_FREQ_OFFSET_ANT_0_ADDR, value);
}

// field definitions
#define TFU_FREQ_OFFSET_ANT_0_FREQ_OFFSET_ANT_0_MASK    ((uint32_t)0x001FFFFF)
#define TFU_FREQ_OFFSET_ANT_0_FREQ_OFFSET_ANT_0_LSB    0
#define TFU_FREQ_OFFSET_ANT_0_FREQ_OFFSET_ANT_0_WIDTH    ((uint32_t)0x00000015)

#define TFU_FREQ_OFFSET_ANT_0_FREQ_OFFSET_ANT_0_RST    0x0

__INLINE uint32_t tfu_freq_offset_ant_0_freq_offset_ant_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_FREQ_OFFSET_ANT_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void tfu_freq_offset_ant_0_freq_offset_ant_0_setf(uint32_t freqoffsetant0)
{
	ASSERT_ERR((((uint32_t)freqoffsetant0 << 0) & ~((uint32_t)0x001FFFFF)) == 0);
	REG_PL_WR(TFU_FREQ_OFFSET_ANT_0_ADDR, (uint32_t)freqoffsetant0 << 0);
}

/**
 * @brief FREQ_OFFSET_ANT_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:00 FREQ_OFFSET_ANT1          0x0
 * </pre>
 */
#define TFU_FREQ_OFFSET_ANT_1_ADDR        (REG_TFU_BASE_ADDR+0x00000284)
#define TFU_FREQ_OFFSET_ANT_1_OFFSET      0x00000284
#define TFU_FREQ_OFFSET_ANT_1_INDEX       0x000000A1
#define TFU_FREQ_OFFSET_ANT_1_RESET       0x00000000

__INLINE uint32_t  tfu_freq_offset_ant_1_get(void)
{
	return REG_PL_RD(TFU_FREQ_OFFSET_ANT_1_ADDR);
}

__INLINE void tfu_freq_offset_ant_1_set(uint32_t value)
{
	REG_PL_WR(TFU_FREQ_OFFSET_ANT_1_ADDR, value);
}

// field definitions
#define TFU_FREQ_OFFSET_ANT_1_FREQ_OFFSET_ANT_1_MASK    ((uint32_t)0x001FFFFF)
#define TFU_FREQ_OFFSET_ANT_1_FREQ_OFFSET_ANT_1_LSB    0
#define TFU_FREQ_OFFSET_ANT_1_FREQ_OFFSET_ANT_1_WIDTH    ((uint32_t)0x00000015)

#define TFU_FREQ_OFFSET_ANT_1_FREQ_OFFSET_ANT_1_RST    0x0

__INLINE uint32_t tfu_freq_offset_ant_1_freq_offset_ant_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_FREQ_OFFSET_ANT_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void tfu_freq_offset_ant_1_freq_offset_ant_1_setf(uint32_t freqoffsetant1)
{
	ASSERT_ERR((((uint32_t)freqoffsetant1 << 0) & ~((uint32_t)0x001FFFFF)) == 0);
	REG_PL_WR(TFU_FREQ_OFFSET_ANT_1_ADDR, (uint32_t)freqoffsetant1 << 0);
}

/**
 * @brief FREQ_OFFSET_ANT_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:00 FREQ_OFFSET_ANT2          0x0
 * </pre>
 */
#define TFU_FREQ_OFFSET_ANT_2_ADDR        (REG_TFU_BASE_ADDR+0x00000288)
#define TFU_FREQ_OFFSET_ANT_2_OFFSET      0x00000288
#define TFU_FREQ_OFFSET_ANT_2_INDEX       0x000000A2
#define TFU_FREQ_OFFSET_ANT_2_RESET       0x00000000

__INLINE uint32_t  tfu_freq_offset_ant_2_get(void)
{
	return REG_PL_RD(TFU_FREQ_OFFSET_ANT_2_ADDR);
}

// field definitions
#define TFU_FREQ_OFFSET_ANT_2_FREQ_OFFSET_ANT_2_MASK    ((uint32_t)0x001FFFFF)
#define TFU_FREQ_OFFSET_ANT_2_FREQ_OFFSET_ANT_2_LSB    0
#define TFU_FREQ_OFFSET_ANT_2_FREQ_OFFSET_ANT_2_WIDTH    ((uint32_t)0x00000015)

#define TFU_FREQ_OFFSET_ANT_2_FREQ_OFFSET_ANT_2_RST    0x0

__INLINE uint32_t tfu_freq_offset_ant_2_freq_offset_ant_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_FREQ_OFFSET_ANT_2_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief FREQ_OFFSET_ANT_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:00 FREQ_OFFSET_ANT3          0x0
 * </pre>
 */
#define TFU_FREQ_OFFSET_ANT_3_ADDR        (REG_TFU_BASE_ADDR+0x0000028C)
#define TFU_FREQ_OFFSET_ANT_3_OFFSET      0x0000028C
#define TFU_FREQ_OFFSET_ANT_3_INDEX       0x000000A3
#define TFU_FREQ_OFFSET_ANT_3_RESET       0x00000000

__INLINE uint32_t  tfu_freq_offset_ant_3_get(void)
{
	return REG_PL_RD(TFU_FREQ_OFFSET_ANT_3_ADDR);
}

// field definitions
#define TFU_FREQ_OFFSET_ANT_3_FREQ_OFFSET_ANT_3_MASK    ((uint32_t)0x001FFFFF)
#define TFU_FREQ_OFFSET_ANT_3_FREQ_OFFSET_ANT_3_LSB    0
#define TFU_FREQ_OFFSET_ANT_3_FREQ_OFFSET_ANT_3_WIDTH    ((uint32_t)0x00000015)

#define TFU_FREQ_OFFSET_ANT_3_FREQ_OFFSET_ANT_3_RST    0x0

__INLINE uint32_t tfu_freq_offset_ant_3_freq_offset_ant_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_FREQ_OFFSET_ANT_3_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief FREQ_OFFSET_ANT_4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:00 FREQ_OFFSET_ANT4          0x0
 * </pre>
 */
#define TFU_FREQ_OFFSET_ANT_4_ADDR        (REG_TFU_BASE_ADDR+0x00000290)
#define TFU_FREQ_OFFSET_ANT_4_OFFSET      0x00000290
#define TFU_FREQ_OFFSET_ANT_4_INDEX       0x000000A4
#define TFU_FREQ_OFFSET_ANT_4_RESET       0x00000000

__INLINE uint32_t  tfu_freq_offset_ant_4_get(void)
{
	return REG_PL_RD(TFU_FREQ_OFFSET_ANT_4_ADDR);
}

// field definitions
#define TFU_FREQ_OFFSET_ANT_4_FREQ_OFFSET_ANT_4_MASK    ((uint32_t)0x001FFFFF)
#define TFU_FREQ_OFFSET_ANT_4_FREQ_OFFSET_ANT_4_LSB    0
#define TFU_FREQ_OFFSET_ANT_4_FREQ_OFFSET_ANT_4_WIDTH    ((uint32_t)0x00000015)

#define TFU_FREQ_OFFSET_ANT_4_FREQ_OFFSET_ANT_4_RST    0x0

__INLINE uint32_t tfu_freq_offset_ant_4_freq_offset_ant_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_FREQ_OFFSET_ANT_4_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief FREQ_OFFSET_ANT_5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:00 FREQ_OFFSET_ANT5          0x0
 * </pre>
 */
#define TFU_FREQ_OFFSET_ANT_5_ADDR        (REG_TFU_BASE_ADDR+0x00000294)
#define TFU_FREQ_OFFSET_ANT_5_OFFSET      0x00000294
#define TFU_FREQ_OFFSET_ANT_5_INDEX       0x000000A5
#define TFU_FREQ_OFFSET_ANT_5_RESET       0x00000000

__INLINE uint32_t  tfu_freq_offset_ant_5_get(void)
{
	return REG_PL_RD(TFU_FREQ_OFFSET_ANT_5_ADDR);
}

// field definitions
#define TFU_FREQ_OFFSET_ANT_5_FREQ_OFFSET_ANT_5_MASK    ((uint32_t)0x001FFFFF)
#define TFU_FREQ_OFFSET_ANT_5_FREQ_OFFSET_ANT_5_LSB    0
#define TFU_FREQ_OFFSET_ANT_5_FREQ_OFFSET_ANT_5_WIDTH    ((uint32_t)0x00000015)

#define TFU_FREQ_OFFSET_ANT_5_FREQ_OFFSET_ANT_5_RST    0x0

__INLINE uint32_t tfu_freq_offset_ant_5_freq_offset_ant_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_FREQ_OFFSET_ANT_5_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief DC_CORRECTION_ANT_0 register definition
 *  SW DC correction of I/Q ANT0 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:16 DC_CORRECTION_ANT_Q_0     0x0
 *    14:00 DC_CORRECTION_ANT_I_0     0x0
 * </pre>
 */
#define TFU_DC_CORRECTION_ANT_0_ADDR        (REG_TFU_BASE_ADDR+0x000002C0)
#define TFU_DC_CORRECTION_ANT_0_OFFSET      0x000002C0
#define TFU_DC_CORRECTION_ANT_0_INDEX       0x000000B0
#define TFU_DC_CORRECTION_ANT_0_RESET       0x00000000

__INLINE uint32_t  tfu_dc_correction_ant_0_get(void)
{
	return REG_PL_RD(TFU_DC_CORRECTION_ANT_0_ADDR);
}

__INLINE void tfu_dc_correction_ant_0_set(uint32_t value)
{
	REG_PL_WR(TFU_DC_CORRECTION_ANT_0_ADDR, value);
}

// field definitions
#define TFU_DC_CORRECTION_ANT_0_DC_CORRECTION_ANT_Q_0_MASK    ((uint32_t)0x7FFF0000)
#define TFU_DC_CORRECTION_ANT_0_DC_CORRECTION_ANT_Q_0_LSB    16
#define TFU_DC_CORRECTION_ANT_0_DC_CORRECTION_ANT_Q_0_WIDTH    ((uint32_t)0x0000000F)
#define TFU_DC_CORRECTION_ANT_0_DC_CORRECTION_ANT_I_0_MASK    ((uint32_t)0x00007FFF)
#define TFU_DC_CORRECTION_ANT_0_DC_CORRECTION_ANT_I_0_LSB    0
#define TFU_DC_CORRECTION_ANT_0_DC_CORRECTION_ANT_I_0_WIDTH    ((uint32_t)0x0000000F)

#define TFU_DC_CORRECTION_ANT_0_DC_CORRECTION_ANT_Q_0_RST    0x0
#define TFU_DC_CORRECTION_ANT_0_DC_CORRECTION_ANT_I_0_RST    0x0

__INLINE void tfu_dc_correction_ant_0_pack(uint16_t dc_correction_ant_q_0, uint16_t dc_correction_ant_i_0)
{
	ASSERT_ERR((((uint32_t)dc_correction_ant_q_0 << 16) & ~((uint32_t)0x7FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)dc_correction_ant_i_0 << 0) & ~((uint32_t)0x00007FFF)) == 0);
	REG_PL_WR(TFU_DC_CORRECTION_ANT_0_ADDR,  ((uint32_t)dc_correction_ant_q_0 << 16) |((uint32_t)dc_correction_ant_i_0 << 0));
}

__INLINE void tfu_dc_correction_ant_0_unpack(uint16_t* dc_correction_ant_q_0, uint16_t* dc_correction_ant_i_0)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_CORRECTION_ANT_0_ADDR);

	*dc_correction_ant_q_0 = (localVal & ((uint32_t)0x7FFF0000)) >>  16;
	*dc_correction_ant_i_0 = (localVal & ((uint32_t)0x00007FFF)) >>  0;
}

__INLINE uint16_t tfu_dc_correction_ant_0_dc_correction_ant_q_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_CORRECTION_ANT_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x7FFF0000)) >> 16);
}
__INLINE void tfu_dc_correction_ant_0_dc_correction_ant_q_0_setf(uint16_t dccorrectionantq0)
{
	ASSERT_ERR((((uint32_t)dccorrectionantq0 << 16) & ~((uint32_t)0x7FFF0000)) == 0);
	REG_PL_WR(TFU_DC_CORRECTION_ANT_0_ADDR, (REG_PL_RD(TFU_DC_CORRECTION_ANT_0_ADDR) & ~((uint32_t)0x7FFF0000)) | ((uint32_t)dccorrectionantq0 <<16));
}
__INLINE uint16_t tfu_dc_correction_ant_0_dc_correction_ant_i_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_CORRECTION_ANT_0_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00007FFF)) >> 0);
}
__INLINE void tfu_dc_correction_ant_0_dc_correction_ant_i_0_setf(uint16_t dccorrectionanti0)
{
	ASSERT_ERR((((uint32_t)dccorrectionanti0 << 0) & ~((uint32_t)0x00007FFF)) == 0);
	REG_PL_WR(TFU_DC_CORRECTION_ANT_0_ADDR, (REG_PL_RD(TFU_DC_CORRECTION_ANT_0_ADDR) & ~((uint32_t)0x00007FFF)) | ((uint32_t)dccorrectionanti0 <<0));
}

/**
 * @brief DC_CORRECTION_ANT_1 register definition
 *  SW DC correction of I/Q ANT1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:16 DC_CORRECTION_ANT_Q_1     0x0
 *    14:00 DC_CORRECTION_ANT_I_1     0x0
 * </pre>
 */
#define TFU_DC_CORRECTION_ANT_1_ADDR        (REG_TFU_BASE_ADDR+0x000002C4)
#define TFU_DC_CORRECTION_ANT_1_OFFSET      0x000002C4
#define TFU_DC_CORRECTION_ANT_1_INDEX       0x000000B1
#define TFU_DC_CORRECTION_ANT_1_RESET       0x00000000

__INLINE uint32_t  tfu_dc_correction_ant_1_get(void)
{
	return REG_PL_RD(TFU_DC_CORRECTION_ANT_1_ADDR);
}

__INLINE void tfu_dc_correction_ant_1_set(uint32_t value)
{
	REG_PL_WR(TFU_DC_CORRECTION_ANT_1_ADDR, value);
}

// field definitions
#define TFU_DC_CORRECTION_ANT_1_DC_CORRECTION_ANT_Q_1_MASK    ((uint32_t)0x7FFF0000)
#define TFU_DC_CORRECTION_ANT_1_DC_CORRECTION_ANT_Q_1_LSB    16
#define TFU_DC_CORRECTION_ANT_1_DC_CORRECTION_ANT_Q_1_WIDTH    ((uint32_t)0x0000000F)
#define TFU_DC_CORRECTION_ANT_1_DC_CORRECTION_ANT_I_1_MASK    ((uint32_t)0x00007FFF)
#define TFU_DC_CORRECTION_ANT_1_DC_CORRECTION_ANT_I_1_LSB    0
#define TFU_DC_CORRECTION_ANT_1_DC_CORRECTION_ANT_I_1_WIDTH    ((uint32_t)0x0000000F)

#define TFU_DC_CORRECTION_ANT_1_DC_CORRECTION_ANT_Q_1_RST    0x0
#define TFU_DC_CORRECTION_ANT_1_DC_CORRECTION_ANT_I_1_RST    0x0

__INLINE void tfu_dc_correction_ant_1_pack(uint16_t dc_correction_ant_q_1, uint16_t dc_correction_ant_i_1)
{
	ASSERT_ERR((((uint32_t)dc_correction_ant_q_1 << 16) & ~((uint32_t)0x7FFF0000)) == 0);
	ASSERT_ERR((((uint32_t)dc_correction_ant_i_1 << 0) & ~((uint32_t)0x00007FFF)) == 0);
	REG_PL_WR(TFU_DC_CORRECTION_ANT_1_ADDR,  ((uint32_t)dc_correction_ant_q_1 << 16) |((uint32_t)dc_correction_ant_i_1 << 0));
}

__INLINE void tfu_dc_correction_ant_1_unpack(uint16_t* dc_correction_ant_q_1, uint16_t* dc_correction_ant_i_1)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_CORRECTION_ANT_1_ADDR);

	*dc_correction_ant_q_1 = (localVal & ((uint32_t)0x7FFF0000)) >>  16;
	*dc_correction_ant_i_1 = (localVal & ((uint32_t)0x00007FFF)) >>  0;
}

__INLINE uint16_t tfu_dc_correction_ant_1_dc_correction_ant_q_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_CORRECTION_ANT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x7FFF0000)) >> 16);
}
__INLINE void tfu_dc_correction_ant_1_dc_correction_ant_q_1_setf(uint16_t dccorrectionantq1)
{
	ASSERT_ERR((((uint32_t)dccorrectionantq1 << 16) & ~((uint32_t)0x7FFF0000)) == 0);
	REG_PL_WR(TFU_DC_CORRECTION_ANT_1_ADDR, (REG_PL_RD(TFU_DC_CORRECTION_ANT_1_ADDR) & ~((uint32_t)0x7FFF0000)) | ((uint32_t)dccorrectionantq1 <<16));
}
__INLINE uint16_t tfu_dc_correction_ant_1_dc_correction_ant_i_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_CORRECTION_ANT_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00007FFF)) >> 0);
}
__INLINE void tfu_dc_correction_ant_1_dc_correction_ant_i_1_setf(uint16_t dccorrectionanti1)
{
	ASSERT_ERR((((uint32_t)dccorrectionanti1 << 0) & ~((uint32_t)0x00007FFF)) == 0);
	REG_PL_WR(TFU_DC_CORRECTION_ANT_1_ADDR, (REG_PL_RD(TFU_DC_CORRECTION_ANT_1_ADDR) & ~((uint32_t)0x00007FFF)) | ((uint32_t)dccorrectionanti1 <<0));
}

/**
 * @brief DC_CORRECTION_ANT_2 register definition
 *  SW DC correction of I/Q ANT2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:16 DC_CORRECTION_ANT_Q_2     0x0
 *    14:00 DC_CORRECTION_ANT_I_2     0x0
 * </pre>
 */
#define TFU_DC_CORRECTION_ANT_2_ADDR        (REG_TFU_BASE_ADDR+0x000002C8)
#define TFU_DC_CORRECTION_ANT_2_OFFSET      0x000002C8
#define TFU_DC_CORRECTION_ANT_2_INDEX       0x000000B2
#define TFU_DC_CORRECTION_ANT_2_RESET       0x00000000

__INLINE uint32_t  tfu_dc_correction_ant_2_get(void)
{
	return REG_PL_RD(TFU_DC_CORRECTION_ANT_2_ADDR);
}

// field definitions
#define TFU_DC_CORRECTION_ANT_2_DC_CORRECTION_ANT_Q_2_MASK    ((uint32_t)0x7FFF0000)
#define TFU_DC_CORRECTION_ANT_2_DC_CORRECTION_ANT_Q_2_LSB    16
#define TFU_DC_CORRECTION_ANT_2_DC_CORRECTION_ANT_Q_2_WIDTH    ((uint32_t)0x0000000F)
#define TFU_DC_CORRECTION_ANT_2_DC_CORRECTION_ANT_I_2_MASK    ((uint32_t)0x00007FFF)
#define TFU_DC_CORRECTION_ANT_2_DC_CORRECTION_ANT_I_2_LSB    0
#define TFU_DC_CORRECTION_ANT_2_DC_CORRECTION_ANT_I_2_WIDTH    ((uint32_t)0x0000000F)

#define TFU_DC_CORRECTION_ANT_2_DC_CORRECTION_ANT_Q_2_RST    0x0
#define TFU_DC_CORRECTION_ANT_2_DC_CORRECTION_ANT_I_2_RST    0x0

__INLINE void tfu_dc_correction_ant_2_unpack(uint16_t* dc_correction_ant_q_2, uint16_t* dc_correction_ant_i_2)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_CORRECTION_ANT_2_ADDR);

	*dc_correction_ant_q_2 = (localVal & ((uint32_t)0x7FFF0000)) >>  16;
	*dc_correction_ant_i_2 = (localVal & ((uint32_t)0x00007FFF)) >>  0;
}

__INLINE uint16_t tfu_dc_correction_ant_2_dc_correction_ant_q_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_CORRECTION_ANT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x7FFF0000)) >> 16);
}
__INLINE uint16_t tfu_dc_correction_ant_2_dc_correction_ant_i_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_CORRECTION_ANT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00007FFF)) >> 0);
}

/**
 * @brief DC_CORRECTION_ANT_3 register definition
 *  SW DC correction of I/Q ANT3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:16 DC_CORRECTION_ANT_Q_3     0x0
 *    14:00 DC_CORRECTION_ANT_I_3     0x0
 * </pre>
 */
#define TFU_DC_CORRECTION_ANT_3_ADDR        (REG_TFU_BASE_ADDR+0x000002CC)
#define TFU_DC_CORRECTION_ANT_3_OFFSET      0x000002CC
#define TFU_DC_CORRECTION_ANT_3_INDEX       0x000000B3
#define TFU_DC_CORRECTION_ANT_3_RESET       0x00000000

__INLINE uint32_t  tfu_dc_correction_ant_3_get(void)
{
	return REG_PL_RD(TFU_DC_CORRECTION_ANT_3_ADDR);
}

// field definitions
#define TFU_DC_CORRECTION_ANT_3_DC_CORRECTION_ANT_Q_3_MASK    ((uint32_t)0x7FFF0000)
#define TFU_DC_CORRECTION_ANT_3_DC_CORRECTION_ANT_Q_3_LSB    16
#define TFU_DC_CORRECTION_ANT_3_DC_CORRECTION_ANT_Q_3_WIDTH    ((uint32_t)0x0000000F)
#define TFU_DC_CORRECTION_ANT_3_DC_CORRECTION_ANT_I_3_MASK    ((uint32_t)0x00007FFF)
#define TFU_DC_CORRECTION_ANT_3_DC_CORRECTION_ANT_I_3_LSB    0
#define TFU_DC_CORRECTION_ANT_3_DC_CORRECTION_ANT_I_3_WIDTH    ((uint32_t)0x0000000F)

#define TFU_DC_CORRECTION_ANT_3_DC_CORRECTION_ANT_Q_3_RST    0x0
#define TFU_DC_CORRECTION_ANT_3_DC_CORRECTION_ANT_I_3_RST    0x0

__INLINE void tfu_dc_correction_ant_3_unpack(uint16_t* dc_correction_ant_q_3, uint16_t* dc_correction_ant_i_3)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_CORRECTION_ANT_3_ADDR);

	*dc_correction_ant_q_3 = (localVal & ((uint32_t)0x7FFF0000)) >>  16;
	*dc_correction_ant_i_3 = (localVal & ((uint32_t)0x00007FFF)) >>  0;
}

__INLINE uint16_t tfu_dc_correction_ant_3_dc_correction_ant_q_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_CORRECTION_ANT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x7FFF0000)) >> 16);
}
__INLINE uint16_t tfu_dc_correction_ant_3_dc_correction_ant_i_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_CORRECTION_ANT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00007FFF)) >> 0);
}

/**
 * @brief DC_CORRECTION_ANT_4 register definition
 *  SW DC correction of I/Q ANT4 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:16 DC_CORRECTION_ANT_Q_4     0x0
 *    14:00 DC_CORRECTION_ANT_I_4     0x0
 * </pre>
 */
#define TFU_DC_CORRECTION_ANT_4_ADDR        (REG_TFU_BASE_ADDR+0x000002D0)
#define TFU_DC_CORRECTION_ANT_4_OFFSET      0x000002D0
#define TFU_DC_CORRECTION_ANT_4_INDEX       0x000000B4
#define TFU_DC_CORRECTION_ANT_4_RESET       0x00000000

__INLINE uint32_t  tfu_dc_correction_ant_4_get(void)
{
	return REG_PL_RD(TFU_DC_CORRECTION_ANT_4_ADDR);
}

// field definitions
#define TFU_DC_CORRECTION_ANT_4_DC_CORRECTION_ANT_Q_4_MASK    ((uint32_t)0x7FFF0000)
#define TFU_DC_CORRECTION_ANT_4_DC_CORRECTION_ANT_Q_4_LSB    16
#define TFU_DC_CORRECTION_ANT_4_DC_CORRECTION_ANT_Q_4_WIDTH    ((uint32_t)0x0000000F)
#define TFU_DC_CORRECTION_ANT_4_DC_CORRECTION_ANT_I_4_MASK    ((uint32_t)0x00007FFF)
#define TFU_DC_CORRECTION_ANT_4_DC_CORRECTION_ANT_I_4_LSB    0
#define TFU_DC_CORRECTION_ANT_4_DC_CORRECTION_ANT_I_4_WIDTH    ((uint32_t)0x0000000F)

#define TFU_DC_CORRECTION_ANT_4_DC_CORRECTION_ANT_Q_4_RST    0x0
#define TFU_DC_CORRECTION_ANT_4_DC_CORRECTION_ANT_I_4_RST    0x0

__INLINE void tfu_dc_correction_ant_4_unpack(uint16_t* dc_correction_ant_q_4, uint16_t* dc_correction_ant_i_4)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_CORRECTION_ANT_4_ADDR);

	*dc_correction_ant_q_4 = (localVal & ((uint32_t)0x7FFF0000)) >>  16;
	*dc_correction_ant_i_4 = (localVal & ((uint32_t)0x00007FFF)) >>  0;
}

__INLINE uint16_t tfu_dc_correction_ant_4_dc_correction_ant_q_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_CORRECTION_ANT_4_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x7FFF0000)) >> 16);
}
__INLINE uint16_t tfu_dc_correction_ant_4_dc_correction_ant_i_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_CORRECTION_ANT_4_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00007FFF)) >> 0);
}

/**
 * @brief DC_CORRECTION_ANT_5 register definition
 *  SW DC correction of I/Q ANT5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:16 DC_CORRECTION_ANT_Q_5     0x0
 *    14:00 DC_CORRECTION_ANT_I_5     0x0
 * </pre>
 */
#define TFU_DC_CORRECTION_ANT_5_ADDR        (REG_TFU_BASE_ADDR+0x000002D4)
#define TFU_DC_CORRECTION_ANT_5_OFFSET      0x000002D4
#define TFU_DC_CORRECTION_ANT_5_INDEX       0x000000B5
#define TFU_DC_CORRECTION_ANT_5_RESET       0x00000000

__INLINE uint32_t  tfu_dc_correction_ant_5_get(void)
{
	return REG_PL_RD(TFU_DC_CORRECTION_ANT_5_ADDR);
}

// field definitions
#define TFU_DC_CORRECTION_ANT_5_DC_CORRECTION_ANT_Q_5_MASK    ((uint32_t)0x7FFF0000)
#define TFU_DC_CORRECTION_ANT_5_DC_CORRECTION_ANT_Q_5_LSB    16
#define TFU_DC_CORRECTION_ANT_5_DC_CORRECTION_ANT_Q_5_WIDTH    ((uint32_t)0x0000000F)
#define TFU_DC_CORRECTION_ANT_5_DC_CORRECTION_ANT_I_5_MASK    ((uint32_t)0x00007FFF)
#define TFU_DC_CORRECTION_ANT_5_DC_CORRECTION_ANT_I_5_LSB    0
#define TFU_DC_CORRECTION_ANT_5_DC_CORRECTION_ANT_I_5_WIDTH    ((uint32_t)0x0000000F)

#define TFU_DC_CORRECTION_ANT_5_DC_CORRECTION_ANT_Q_5_RST    0x0
#define TFU_DC_CORRECTION_ANT_5_DC_CORRECTION_ANT_I_5_RST    0x0

__INLINE void tfu_dc_correction_ant_5_unpack(uint16_t* dc_correction_ant_q_5, uint16_t* dc_correction_ant_i_5)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_CORRECTION_ANT_5_ADDR);

	*dc_correction_ant_q_5 = (localVal & ((uint32_t)0x7FFF0000)) >>  16;
	*dc_correction_ant_i_5 = (localVal & ((uint32_t)0x00007FFF)) >>  0;
}

__INLINE uint16_t tfu_dc_correction_ant_5_dc_correction_ant_q_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_CORRECTION_ANT_5_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x7FFF0000)) >> 16);
}
__INLINE uint16_t tfu_dc_correction_ant_5_dc_correction_ant_i_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_DC_CORRECTION_ANT_5_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x00007FFF)) >> 0);
}

/**
 * @brief TX_CYCLIC_SHIFT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 TX_CYCLIC_SHIFT_ANT_1     0x0
 *    15:00 TX_CYCLIC_SHIFT_ANT_0     0x0
 * </pre>
 */
#define TFU_TX_CYCLIC_SHIFT_ADDR        (REG_TFU_BASE_ADDR+0x00000300)
#define TFU_TX_CYCLIC_SHIFT_OFFSET      0x00000300
#define TFU_TX_CYCLIC_SHIFT_INDEX       0x000000C0
#define TFU_TX_CYCLIC_SHIFT_RESET       0x00000000

__INLINE uint32_t  tfu_tx_cyclic_shift_get(void)
{
	return REG_PL_RD(TFU_TX_CYCLIC_SHIFT_ADDR);
}

__INLINE void tfu_tx_cyclic_shift_set(uint32_t value)
{
	REG_PL_WR(TFU_TX_CYCLIC_SHIFT_ADDR, value);
}

// field definitions
#define TFU_TX_CYCLIC_SHIFT_TX_CYCLIC_SHIFT_ANT_1_MASK    ((uint32_t)0xFFFF0000)
#define TFU_TX_CYCLIC_SHIFT_TX_CYCLIC_SHIFT_ANT_1_LSB    16
#define TFU_TX_CYCLIC_SHIFT_TX_CYCLIC_SHIFT_ANT_1_WIDTH    ((uint32_t)0x00000010)
#define TFU_TX_CYCLIC_SHIFT_TX_CYCLIC_SHIFT_ANT_0_MASK    ((uint32_t)0x0000FFFF)
#define TFU_TX_CYCLIC_SHIFT_TX_CYCLIC_SHIFT_ANT_0_LSB    0
#define TFU_TX_CYCLIC_SHIFT_TX_CYCLIC_SHIFT_ANT_0_WIDTH    ((uint32_t)0x00000010)

#define TFU_TX_CYCLIC_SHIFT_TX_CYCLIC_SHIFT_ANT_1_RST    0x0
#define TFU_TX_CYCLIC_SHIFT_TX_CYCLIC_SHIFT_ANT_0_RST    0x0

__INLINE void tfu_tx_cyclic_shift_pack(uint16_t tx_cyclic_shift_ant_1, uint16_t tx_cyclic_shift_ant_0)
{
	ASSERT_ERR((((uint32_t)tx_cyclic_shift_ant_1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)tx_cyclic_shift_ant_0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(TFU_TX_CYCLIC_SHIFT_ADDR,  ((uint32_t)tx_cyclic_shift_ant_1 << 16) |((uint32_t)tx_cyclic_shift_ant_0 << 0));
}

__INLINE void tfu_tx_cyclic_shift_unpack(uint16_t* tx_cyclic_shift_ant_1, uint16_t* tx_cyclic_shift_ant_0)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_CYCLIC_SHIFT_ADDR);

	*tx_cyclic_shift_ant_1 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*tx_cyclic_shift_ant_0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t tfu_tx_cyclic_shift_tx_cyclic_shift_ant_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_CYCLIC_SHIFT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void tfu_tx_cyclic_shift_tx_cyclic_shift_ant_1_setf(uint16_t txcyclicshiftant1)
{
	ASSERT_ERR((((uint32_t)txcyclicshiftant1 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(TFU_TX_CYCLIC_SHIFT_ADDR, (REG_PL_RD(TFU_TX_CYCLIC_SHIFT_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)txcyclicshiftant1 <<16));
}
__INLINE uint16_t tfu_tx_cyclic_shift_tx_cyclic_shift_ant_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_CYCLIC_SHIFT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void tfu_tx_cyclic_shift_tx_cyclic_shift_ant_0_setf(uint16_t txcyclicshiftant0)
{
	ASSERT_ERR((((uint32_t)txcyclicshiftant0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(TFU_TX_CYCLIC_SHIFT_ADDR, (REG_PL_RD(TFU_TX_CYCLIC_SHIFT_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)txcyclicshiftant0 <<0));
}

/**
 * @brief TX_CYCLIC_SHIFT_2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 TX_CYCLIC_SHIFT_ANT_3     0x0
 *    15:00 TX_CYCLIC_SHIFT_ANT_2     0x0
 * </pre>
 */
#define TFU_TX_CYCLIC_SHIFT_2_ADDR        (REG_TFU_BASE_ADDR+0x00000304)
#define TFU_TX_CYCLIC_SHIFT_2_OFFSET      0x00000304
#define TFU_TX_CYCLIC_SHIFT_2_INDEX       0x000000C1
#define TFU_TX_CYCLIC_SHIFT_2_RESET       0x00000000

__INLINE uint32_t  tfu_tx_cyclic_shift_2_get(void)
{
	return REG_PL_RD(TFU_TX_CYCLIC_SHIFT_2_ADDR);
}

// field definitions
#define TFU_TX_CYCLIC_SHIFT_2_TX_CYCLIC_SHIFT_ANT_3_MASK    ((uint32_t)0xFFFF0000)
#define TFU_TX_CYCLIC_SHIFT_2_TX_CYCLIC_SHIFT_ANT_3_LSB    16
#define TFU_TX_CYCLIC_SHIFT_2_TX_CYCLIC_SHIFT_ANT_3_WIDTH    ((uint32_t)0x00000010)
#define TFU_TX_CYCLIC_SHIFT_2_TX_CYCLIC_SHIFT_ANT_2_MASK    ((uint32_t)0x0000FFFF)
#define TFU_TX_CYCLIC_SHIFT_2_TX_CYCLIC_SHIFT_ANT_2_LSB    0
#define TFU_TX_CYCLIC_SHIFT_2_TX_CYCLIC_SHIFT_ANT_2_WIDTH    ((uint32_t)0x00000010)

#define TFU_TX_CYCLIC_SHIFT_2_TX_CYCLIC_SHIFT_ANT_3_RST    0x0
#define TFU_TX_CYCLIC_SHIFT_2_TX_CYCLIC_SHIFT_ANT_2_RST    0x0

__INLINE void tfu_tx_cyclic_shift_2_unpack(uint16_t* tx_cyclic_shift_ant_3, uint16_t* tx_cyclic_shift_ant_2)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_CYCLIC_SHIFT_2_ADDR);

	*tx_cyclic_shift_ant_3 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*tx_cyclic_shift_ant_2 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t tfu_tx_cyclic_shift_2_tx_cyclic_shift_ant_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_CYCLIC_SHIFT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t tfu_tx_cyclic_shift_2_tx_cyclic_shift_ant_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_CYCLIC_SHIFT_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief TX_CYCLIC_SHIFT_3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 TX_CYCLIC_SHIFT_ANT5      0x0
 *    15:00 TX_CYCLIC_SHIFT_ANT4      0x0
 * </pre>
 */
#define TFU_TX_CYCLIC_SHIFT_3_ADDR        (REG_TFU_BASE_ADDR+0x00000308)
#define TFU_TX_CYCLIC_SHIFT_3_OFFSET      0x00000308
#define TFU_TX_CYCLIC_SHIFT_3_INDEX       0x000000C2
#define TFU_TX_CYCLIC_SHIFT_3_RESET       0x00000000

__INLINE uint32_t  tfu_tx_cyclic_shift_3_get(void)
{
	return REG_PL_RD(TFU_TX_CYCLIC_SHIFT_3_ADDR);
}

// field definitions
#define TFU_TX_CYCLIC_SHIFT_3_TX_CYCLIC_SHIFT_ANT_5_MASK    ((uint32_t)0xFFFF0000)
#define TFU_TX_CYCLIC_SHIFT_3_TX_CYCLIC_SHIFT_ANT_5_LSB    16
#define TFU_TX_CYCLIC_SHIFT_3_TX_CYCLIC_SHIFT_ANT_5_WIDTH    ((uint32_t)0x00000010)
#define TFU_TX_CYCLIC_SHIFT_3_TX_CYCLIC_SHIFT_ANT_4_MASK    ((uint32_t)0x0000FFFF)
#define TFU_TX_CYCLIC_SHIFT_3_TX_CYCLIC_SHIFT_ANT_4_LSB    0
#define TFU_TX_CYCLIC_SHIFT_3_TX_CYCLIC_SHIFT_ANT_4_WIDTH    ((uint32_t)0x00000010)

#define TFU_TX_CYCLIC_SHIFT_3_TX_CYCLIC_SHIFT_ANT_5_RST    0x0
#define TFU_TX_CYCLIC_SHIFT_3_TX_CYCLIC_SHIFT_ANT_4_RST    0x0

__INLINE void tfu_tx_cyclic_shift_3_unpack(uint16_t* tx_cyclic_shift_ant5, uint16_t* tx_cyclic_shift_ant4)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_CYCLIC_SHIFT_3_ADDR);

	*tx_cyclic_shift_ant5 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*tx_cyclic_shift_ant4 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t tfu_tx_cyclic_shift_3_tx_cyclic_shift_ant_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_CYCLIC_SHIFT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE uint16_t tfu_tx_cyclic_shift_3_tx_cyclic_shift_ant_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_TX_CYCLIC_SHIFT_3_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}

/**
 * @brief RXIMGMEM_PTR_0 register definition
 *  Pointer to Rx Imgaing symbol buffer 0 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 RXIMGMEM_PTR_0            0x0
 * </pre>
 */
#define TFU_RXIMGMEM_PTR_0_ADDR        (REG_TFU_BASE_ADDR+0x00000340)
#define TFU_RXIMGMEM_PTR_0_OFFSET      0x00000340
#define TFU_RXIMGMEM_PTR_0_INDEX       0x000000D0
#define TFU_RXIMGMEM_PTR_0_RESET       0x00000000

__INLINE uint32_t  tfu_rximgmem_ptr_0_get(void)
{
	return REG_PL_RD(TFU_RXIMGMEM_PTR_0_ADDR);
}

__INLINE void tfu_rximgmem_ptr_0_set(uint32_t value)
{
	REG_PL_WR(TFU_RXIMGMEM_PTR_0_ADDR, value);
}

// field definitions
#define TFU_RXIMGMEM_PTR_0_RXIMGMEM_PTR_0_MASK    ((uint32_t)0xFFFFFFFC)
#define TFU_RXIMGMEM_PTR_0_RXIMGMEM_PTR_0_LSB    2
#define TFU_RXIMGMEM_PTR_0_RXIMGMEM_PTR_0_WIDTH    ((uint32_t)0x0000001E)

#define TFU_RXIMGMEM_PTR_0_RXIMGMEM_PTR_0_RST    0x0

__INLINE uint32_t tfu_rximgmem_ptr_0_rximgmem_ptr_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_RXIMGMEM_PTR_0_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void tfu_rximgmem_ptr_0_rximgmem_ptr_0_setf(uint32_t rximgmemptr0)
{
	ASSERT_ERR((((uint32_t)rximgmemptr0 << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(TFU_RXIMGMEM_PTR_0_ADDR, (uint32_t)rximgmemptr0 << 2);
}

/**
 * @brief RXIMGMEM_PTR_1 register definition
 *  Pointer to Rx Imgaing symbol buffer 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 RXIMGMEM_PTR_1            0x0
 * </pre>
 */
#define TFU_RXIMGMEM_PTR_1_ADDR        (REG_TFU_BASE_ADDR+0x00000344)
#define TFU_RXIMGMEM_PTR_1_OFFSET      0x00000344
#define TFU_RXIMGMEM_PTR_1_INDEX       0x000000D1
#define TFU_RXIMGMEM_PTR_1_RESET       0x00000000

__INLINE uint32_t  tfu_rximgmem_ptr_1_get(void)
{
	return REG_PL_RD(TFU_RXIMGMEM_PTR_1_ADDR);
}

__INLINE void tfu_rximgmem_ptr_1_set(uint32_t value)
{
	REG_PL_WR(TFU_RXIMGMEM_PTR_1_ADDR, value);
}

// field definitions
#define TFU_RXIMGMEM_PTR_1_RXIMGMEM_PTR_1_MASK    ((uint32_t)0xFFFFFFFC)
#define TFU_RXIMGMEM_PTR_1_RXIMGMEM_PTR_1_LSB    2
#define TFU_RXIMGMEM_PTR_1_RXIMGMEM_PTR_1_WIDTH    ((uint32_t)0x0000001E)

#define TFU_RXIMGMEM_PTR_1_RXIMGMEM_PTR_1_RST    0x0

__INLINE uint32_t tfu_rximgmem_ptr_1_rximgmem_ptr_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_RXIMGMEM_PTR_1_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void tfu_rximgmem_ptr_1_rximgmem_ptr_1_setf(uint32_t rximgmemptr1)
{
	ASSERT_ERR((((uint32_t)rximgmemptr1 << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(TFU_RXIMGMEM_PTR_1_ADDR, (uint32_t)rximgmemptr1 << 2);
}

/**
 * @brief RXIMGMEM_PTR_2 register definition
 *  Pointer to Rx Imgaing symbol buffer 2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 RXIMGMEM_PTR_2            0x0
 * </pre>
 */
#define TFU_RXIMGMEM_PTR_2_ADDR        (REG_TFU_BASE_ADDR+0x00000348)
#define TFU_RXIMGMEM_PTR_2_OFFSET      0x00000348
#define TFU_RXIMGMEM_PTR_2_INDEX       0x000000D2
#define TFU_RXIMGMEM_PTR_2_RESET       0x00000000

__INLINE uint32_t  tfu_rximgmem_ptr_2_get(void)
{
	return REG_PL_RD(TFU_RXIMGMEM_PTR_2_ADDR);
}

__INLINE void tfu_rximgmem_ptr_2_set(uint32_t value)
{
	REG_PL_WR(TFU_RXIMGMEM_PTR_2_ADDR, value);
}

// field definitions
#define TFU_RXIMGMEM_PTR_2_RXIMGMEM_PTR_2_MASK    ((uint32_t)0xFFFFFFFC)
#define TFU_RXIMGMEM_PTR_2_RXIMGMEM_PTR_2_LSB    2
#define TFU_RXIMGMEM_PTR_2_RXIMGMEM_PTR_2_WIDTH    ((uint32_t)0x0000001E)

#define TFU_RXIMGMEM_PTR_2_RXIMGMEM_PTR_2_RST    0x0

__INLINE uint32_t tfu_rximgmem_ptr_2_rximgmem_ptr_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_RXIMGMEM_PTR_2_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void tfu_rximgmem_ptr_2_rximgmem_ptr_2_setf(uint32_t rximgmemptr2)
{
	ASSERT_ERR((((uint32_t)rximgmemptr2 << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(TFU_RXIMGMEM_PTR_2_ADDR, (uint32_t)rximgmemptr2 << 2);
}

/**
 * @brief RXIMGMEM_PTR_3 register definition
 *  Pointer to Rx Imgaing symbol buffer 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 RXIMGMEM_PTR_3            0x0
 * </pre>
 */
#define TFU_RXIMGMEM_PTR_3_ADDR        (REG_TFU_BASE_ADDR+0x0000034C)
#define TFU_RXIMGMEM_PTR_3_OFFSET      0x0000034C
#define TFU_RXIMGMEM_PTR_3_INDEX       0x000000D3
#define TFU_RXIMGMEM_PTR_3_RESET       0x00000000

__INLINE uint32_t  tfu_rximgmem_ptr_3_get(void)
{
	return REG_PL_RD(TFU_RXIMGMEM_PTR_3_ADDR);
}

__INLINE void tfu_rximgmem_ptr_3_set(uint32_t value)
{
	REG_PL_WR(TFU_RXIMGMEM_PTR_3_ADDR, value);
}

// field definitions
#define TFU_RXIMGMEM_PTR_3_RXIMGMEM_PTR_3_MASK    ((uint32_t)0xFFFFFFFC)
#define TFU_RXIMGMEM_PTR_3_RXIMGMEM_PTR_3_LSB    2
#define TFU_RXIMGMEM_PTR_3_RXIMGMEM_PTR_3_WIDTH    ((uint32_t)0x0000001E)

#define TFU_RXIMGMEM_PTR_3_RXIMGMEM_PTR_3_RST    0x0

__INLINE uint32_t tfu_rximgmem_ptr_3_rximgmem_ptr_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_RXIMGMEM_PTR_3_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void tfu_rximgmem_ptr_3_rximgmem_ptr_3_setf(uint32_t rximgmemptr3)
{
	ASSERT_ERR((((uint32_t)rximgmemptr3 << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(TFU_RXIMGMEM_PTR_3_ADDR, (uint32_t)rximgmemptr3 << 2);
}

/**
 * @brief RXIMGMEM_PTR_4 register definition
 *  Pointer to Rx Imgaing symbol buffer 4 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 RXIMGMEM_PTR_4            0x0
 * </pre>
 */
#define TFU_RXIMGMEM_PTR_4_ADDR        (REG_TFU_BASE_ADDR+0x00000350)
#define TFU_RXIMGMEM_PTR_4_OFFSET      0x00000350
#define TFU_RXIMGMEM_PTR_4_INDEX       0x000000D4
#define TFU_RXIMGMEM_PTR_4_RESET       0x00000000

__INLINE uint32_t  tfu_rximgmem_ptr_4_get(void)
{
	return REG_PL_RD(TFU_RXIMGMEM_PTR_4_ADDR);
}

__INLINE void tfu_rximgmem_ptr_4_set(uint32_t value)
{
	REG_PL_WR(TFU_RXIMGMEM_PTR_4_ADDR, value);
}

// field definitions
#define TFU_RXIMGMEM_PTR_4_RXIMGMEM_PTR_4_MASK    ((uint32_t)0xFFFFFFFC)
#define TFU_RXIMGMEM_PTR_4_RXIMGMEM_PTR_4_LSB    2
#define TFU_RXIMGMEM_PTR_4_RXIMGMEM_PTR_4_WIDTH    ((uint32_t)0x0000001E)

#define TFU_RXIMGMEM_PTR_4_RXIMGMEM_PTR_4_RST    0x0

__INLINE uint32_t tfu_rximgmem_ptr_4_rximgmem_ptr_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_RXIMGMEM_PTR_4_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void tfu_rximgmem_ptr_4_rximgmem_ptr_4_setf(uint32_t rximgmemptr4)
{
	ASSERT_ERR((((uint32_t)rximgmemptr4 << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(TFU_RXIMGMEM_PTR_4_ADDR, (uint32_t)rximgmemptr4 << 2);
}

/**
 * @brief RXIMGMEM_PTR_5 register definition
 *  Pointer to Rx Imgaing symbol buffer 5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 RXIMGMEM_PTR_5            0x0
 * </pre>
 */
#define TFU_RXIMGMEM_PTR_5_ADDR        (REG_TFU_BASE_ADDR+0x00000354)
#define TFU_RXIMGMEM_PTR_5_OFFSET      0x00000354
#define TFU_RXIMGMEM_PTR_5_INDEX       0x000000D5
#define TFU_RXIMGMEM_PTR_5_RESET       0x00000000

__INLINE uint32_t  tfu_rximgmem_ptr_5_get(void)
{
	return REG_PL_RD(TFU_RXIMGMEM_PTR_5_ADDR);
}

__INLINE void tfu_rximgmem_ptr_5_set(uint32_t value)
{
	REG_PL_WR(TFU_RXIMGMEM_PTR_5_ADDR, value);
}

// field definitions
#define TFU_RXIMGMEM_PTR_5_RXIMGMEM_PTR_5_MASK    ((uint32_t)0xFFFFFFFC)
#define TFU_RXIMGMEM_PTR_5_RXIMGMEM_PTR_5_LSB    2
#define TFU_RXIMGMEM_PTR_5_RXIMGMEM_PTR_5_WIDTH    ((uint32_t)0x0000001E)

#define TFU_RXIMGMEM_PTR_5_RXIMGMEM_PTR_5_RST    0x0

__INLINE uint32_t tfu_rximgmem_ptr_5_rximgmem_ptr_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_RXIMGMEM_PTR_5_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void tfu_rximgmem_ptr_5_rximgmem_ptr_5_setf(uint32_t rximgmemptr5)
{
	ASSERT_ERR((((uint32_t)rximgmemptr5 << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(TFU_RXIMGMEM_PTR_5_ADDR, (uint32_t)rximgmemptr5 << 2);
}

/**
 * @brief RXIMGMEM_PTR_6 register definition
 *  Pointer to Rx Imgaing symbol buffer 6 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 RXIMGMEM_PTR_6            0x0
 * </pre>
 */
#define TFU_RXIMGMEM_PTR_6_ADDR        (REG_TFU_BASE_ADDR+0x00000358)
#define TFU_RXIMGMEM_PTR_6_OFFSET      0x00000358
#define TFU_RXIMGMEM_PTR_6_INDEX       0x000000D6
#define TFU_RXIMGMEM_PTR_6_RESET       0x00000000

__INLINE uint32_t  tfu_rximgmem_ptr_6_get(void)
{
	return REG_PL_RD(TFU_RXIMGMEM_PTR_6_ADDR);
}

__INLINE void tfu_rximgmem_ptr_6_set(uint32_t value)
{
	REG_PL_WR(TFU_RXIMGMEM_PTR_6_ADDR, value);
}

// field definitions
#define TFU_RXIMGMEM_PTR_6_RXIMGMEM_PTR_6_MASK    ((uint32_t)0xFFFFFFFC)
#define TFU_RXIMGMEM_PTR_6_RXIMGMEM_PTR_6_LSB    2
#define TFU_RXIMGMEM_PTR_6_RXIMGMEM_PTR_6_WIDTH    ((uint32_t)0x0000001E)

#define TFU_RXIMGMEM_PTR_6_RXIMGMEM_PTR_6_RST    0x0

__INLINE uint32_t tfu_rximgmem_ptr_6_rximgmem_ptr_6_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_RXIMGMEM_PTR_6_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void tfu_rximgmem_ptr_6_rximgmem_ptr_6_setf(uint32_t rximgmemptr6)
{
	ASSERT_ERR((((uint32_t)rximgmemptr6 << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(TFU_RXIMGMEM_PTR_6_ADDR, (uint32_t)rximgmemptr6 << 2);
}

/**
 * @brief RXIMGMEM_PTR_7 register definition
 *  Pointer to Rx Imgaing symbol buffer 7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:02 RXIMGMEM_PTR_7            0x0
 * </pre>
 */
#define TFU_RXIMGMEM_PTR_7_ADDR        (REG_TFU_BASE_ADDR+0x0000035C)
#define TFU_RXIMGMEM_PTR_7_OFFSET      0x0000035C
#define TFU_RXIMGMEM_PTR_7_INDEX       0x000000D7
#define TFU_RXIMGMEM_PTR_7_RESET       0x00000000

__INLINE uint32_t  tfu_rximgmem_ptr_7_get(void)
{
	return REG_PL_RD(TFU_RXIMGMEM_PTR_7_ADDR);
}

__INLINE void tfu_rximgmem_ptr_7_set(uint32_t value)
{
	REG_PL_WR(TFU_RXIMGMEM_PTR_7_ADDR, value);
}

// field definitions
#define TFU_RXIMGMEM_PTR_7_RXIMGMEM_PTR_7_MASK    ((uint32_t)0xFFFFFFFC)
#define TFU_RXIMGMEM_PTR_7_RXIMGMEM_PTR_7_LSB    2
#define TFU_RXIMGMEM_PTR_7_RXIMGMEM_PTR_7_WIDTH    ((uint32_t)0x0000001E)

#define TFU_RXIMGMEM_PTR_7_RXIMGMEM_PTR_7_RST    0x0

__INLINE uint32_t tfu_rximgmem_ptr_7_rximgmem_ptr_7_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_RXIMGMEM_PTR_7_ADDR);
	return (uint32_t)(localVal >> 2);
}
__INLINE void tfu_rximgmem_ptr_7_rximgmem_ptr_7_setf(uint32_t rximgmemptr7)
{
	ASSERT_ERR((((uint32_t)rximgmemptr7 << 2) & ~((uint32_t)0xFFFFFFFC)) == 0);
	REG_PL_WR(TFU_RXIMGMEM_PTR_7_ADDR, (uint32_t)rximgmemptr7 << 2);
}

/**
 * @brief RXIMGDMA_SMP_IGN register definition
 *  Number of 160MHz sample to ignore in DMA mode register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 NUM_SMP_IGN               0x0
 * </pre>
 */
#define TFU_RXIMGDMA_SMP_IGN_ADDR        (REG_TFU_BASE_ADDR+0x00000360)
#define TFU_RXIMGDMA_SMP_IGN_OFFSET      0x00000360
#define TFU_RXIMGDMA_SMP_IGN_INDEX       0x000000D8
#define TFU_RXIMGDMA_SMP_IGN_RESET       0x00000000

__INLINE uint32_t  tfu_rximgdma_smp_ign_get(void)
{
	return REG_PL_RD(TFU_RXIMGDMA_SMP_IGN_ADDR);
}

__INLINE void tfu_rximgdma_smp_ign_set(uint32_t value)
{
	REG_PL_WR(TFU_RXIMGDMA_SMP_IGN_ADDR, value);
}

// field definitions
#define TFU_RXIMGDMA_SMP_IGN_NUM_SMP_IGN_MASK    ((uint32_t)0x0000FFFF)
#define TFU_RXIMGDMA_SMP_IGN_NUM_SMP_IGN_LSB    0
#define TFU_RXIMGDMA_SMP_IGN_NUM_SMP_IGN_WIDTH    ((uint32_t)0x00000010)

#define TFU_RXIMGDMA_SMP_IGN_NUM_SMP_IGN_RST    0x0

__INLINE uint16_t tfu_rximgdma_smp_ign_num_smp_ign_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_RXIMGDMA_SMP_IGN_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void tfu_rximgdma_smp_ign_num_smp_ign_setf(uint16_t numsmpign)
{
	ASSERT_ERR((((uint32_t)numsmpign << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(TFU_RXIMGDMA_SMP_IGN_ADDR, (uint32_t)numsmpign << 0);
}

/**
 * @brief IMG_FFT_SCALING register definition
 *  Scaling of TFU Imaging FFT/IFFT Input/Output register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    24    RX_IMG_AUTO_SYMBOL_MODE_EN 0              
 *    23:20 RX_IMG_PREAMBLE_SYMBOL_NUM 0x0
 *    19:16 RX_IMG_IN_SCALE_HELTF     0x0
 *    15:12 TX_IMG_OUT_SCALE_HELTF    0x0
 *    11:08 TX_IMG_IN_SCALE_HELTF     0x0
 *    07:04 TX_IMG_OUT_SCALE_NON_HELTF 0x0
 *    03:00 TX_IMG_IN_SCALE_NON_HELTF 0x0
 * </pre>
 */
#define TFU_IMG_FFT_SCALING_ADDR        (REG_TFU_BASE_ADDR+0x00000364)
#define TFU_IMG_FFT_SCALING_OFFSET      0x00000364
#define TFU_IMG_FFT_SCALING_INDEX       0x000000D9
#define TFU_IMG_FFT_SCALING_RESET       0x00000000

__INLINE uint32_t  tfu_img_fft_scaling_get(void)
{
	return REG_PL_RD(TFU_IMG_FFT_SCALING_ADDR);
}

__INLINE void tfu_img_fft_scaling_set(uint32_t value)
{
	REG_PL_WR(TFU_IMG_FFT_SCALING_ADDR, value);
}

// field definitions
#define TFU_IMG_FFT_SCALING_RX_IMG_AUTO_SYMBOL_MODE_EN_BIT    ((uint32_t)0x01000000)
#define TFU_IMG_FFT_SCALING_RX_IMG_AUTO_SYMBOL_MODE_EN_POS    24
#define TFU_IMG_FFT_SCALING_RX_IMG_PREAMBLE_SYMBOL_NUM_MASK    ((uint32_t)0x00F00000)
#define TFU_IMG_FFT_SCALING_RX_IMG_PREAMBLE_SYMBOL_NUM_LSB    20
#define TFU_IMG_FFT_SCALING_RX_IMG_PREAMBLE_SYMBOL_NUM_WIDTH    ((uint32_t)0x00000004)
#define TFU_IMG_FFT_SCALING_RX_IMG_IN_SCALE_HELTF_MASK    ((uint32_t)0x000F0000)
#define TFU_IMG_FFT_SCALING_RX_IMG_IN_SCALE_HELTF_LSB    16
#define TFU_IMG_FFT_SCALING_RX_IMG_IN_SCALE_HELTF_WIDTH    ((uint32_t)0x00000004)
#define TFU_IMG_FFT_SCALING_TX_IMG_OUT_SCALE_HELTF_MASK    ((uint32_t)0x0000F000)
#define TFU_IMG_FFT_SCALING_TX_IMG_OUT_SCALE_HELTF_LSB    12
#define TFU_IMG_FFT_SCALING_TX_IMG_OUT_SCALE_HELTF_WIDTH    ((uint32_t)0x00000004)
#define TFU_IMG_FFT_SCALING_TX_IMG_IN_SCALE_HELTF_MASK    ((uint32_t)0x00000F00)
#define TFU_IMG_FFT_SCALING_TX_IMG_IN_SCALE_HELTF_LSB    8
#define TFU_IMG_FFT_SCALING_TX_IMG_IN_SCALE_HELTF_WIDTH    ((uint32_t)0x00000004)
#define TFU_IMG_FFT_SCALING_TX_IMG_OUT_SCALE_NON_HELTF_MASK    ((uint32_t)0x000000F0)
#define TFU_IMG_FFT_SCALING_TX_IMG_OUT_SCALE_NON_HELTF_LSB    4
#define TFU_IMG_FFT_SCALING_TX_IMG_OUT_SCALE_NON_HELTF_WIDTH    ((uint32_t)0x00000004)
#define TFU_IMG_FFT_SCALING_TX_IMG_IN_SCALE_NON_HELTF_MASK    ((uint32_t)0x0000000F)
#define TFU_IMG_FFT_SCALING_TX_IMG_IN_SCALE_NON_HELTF_LSB    0
#define TFU_IMG_FFT_SCALING_TX_IMG_IN_SCALE_NON_HELTF_WIDTH    ((uint32_t)0x00000004)

#define TFU_IMG_FFT_SCALING_RX_IMG_AUTO_SYMBOL_MODE_EN_RST    0x0
#define TFU_IMG_FFT_SCALING_RX_IMG_PREAMBLE_SYMBOL_NUM_RST    0x0
#define TFU_IMG_FFT_SCALING_RX_IMG_IN_SCALE_HELTF_RST    0x0
#define TFU_IMG_FFT_SCALING_TX_IMG_OUT_SCALE_HELTF_RST    0x0
#define TFU_IMG_FFT_SCALING_TX_IMG_IN_SCALE_HELTF_RST    0x0
#define TFU_IMG_FFT_SCALING_TX_IMG_OUT_SCALE_NON_HELTF_RST    0x0
#define TFU_IMG_FFT_SCALING_TX_IMG_IN_SCALE_NON_HELTF_RST    0x0

__INLINE void tfu_img_fft_scaling_pack(uint8_t rx_img_auto_symbol_mode_en, uint8_t rx_img_preamble_symbol_num, uint8_t rx_img_in_scale_heltf, uint8_t tx_img_out_scale_heltf, uint8_t tx_img_in_scale_heltf, uint8_t tx_img_out_scale_non_heltf, uint8_t tx_img_in_scale_non_heltf)
{
	ASSERT_ERR((((uint32_t)rx_img_auto_symbol_mode_en << 24) & ~((uint32_t)0x01000000)) == 0);
	ASSERT_ERR((((uint32_t)rx_img_preamble_symbol_num << 20) & ~((uint32_t)0x00F00000)) == 0);
	ASSERT_ERR((((uint32_t)rx_img_in_scale_heltf << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)tx_img_out_scale_heltf << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)tx_img_in_scale_heltf << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)tx_img_out_scale_non_heltf << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)tx_img_in_scale_non_heltf << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(TFU_IMG_FFT_SCALING_ADDR,  ((uint32_t)rx_img_auto_symbol_mode_en << 24) |((uint32_t)rx_img_preamble_symbol_num << 20) |((uint32_t)rx_img_in_scale_heltf << 16) |((uint32_t)tx_img_out_scale_heltf << 12) |((uint32_t)tx_img_in_scale_heltf << 8) |((uint32_t)tx_img_out_scale_non_heltf << 4) |((uint32_t)tx_img_in_scale_non_heltf << 0));
}

__INLINE void tfu_img_fft_scaling_unpack(uint8_t* rx_img_auto_symbol_mode_en, uint8_t* rx_img_preamble_symbol_num, uint8_t* rx_img_in_scale_heltf, uint8_t* tx_img_out_scale_heltf, uint8_t* tx_img_in_scale_heltf, uint8_t* tx_img_out_scale_non_heltf, uint8_t* tx_img_in_scale_non_heltf)
{
	uint32_t localVal = REG_PL_RD(TFU_IMG_FFT_SCALING_ADDR);

	*rx_img_auto_symbol_mode_en = (localVal & ((uint32_t)0x01000000)) >>  24;
	*rx_img_preamble_symbol_num = (localVal & ((uint32_t)0x00F00000)) >>  20;
	*rx_img_in_scale_heltf = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*tx_img_out_scale_heltf = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*tx_img_in_scale_heltf = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*tx_img_out_scale_non_heltf = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*tx_img_in_scale_non_heltf = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t tfu_img_fft_scaling_rx_img_auto_symbol_mode_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_IMG_FFT_SCALING_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01000000)) >> 24);
}
__INLINE void tfu_img_fft_scaling_rx_img_auto_symbol_mode_en_setf(uint8_t rximgautosymbolmodeen)
{
	ASSERT_ERR((((uint32_t)rximgautosymbolmodeen << 24) & ~((uint32_t)0x01000000)) == 0);
	REG_PL_WR(TFU_IMG_FFT_SCALING_ADDR, (REG_PL_RD(TFU_IMG_FFT_SCALING_ADDR) & ~((uint32_t)0x01000000)) | ((uint32_t)rximgautosymbolmodeen <<24));
}
__INLINE uint8_t tfu_img_fft_scaling_rx_img_preamble_symbol_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_IMG_FFT_SCALING_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00F00000)) >> 20);
}
__INLINE void tfu_img_fft_scaling_rx_img_preamble_symbol_num_setf(uint8_t rximgpreamblesymbolnum)
{
	ASSERT_ERR((((uint32_t)rximgpreamblesymbolnum << 20) & ~((uint32_t)0x00F00000)) == 0);
	REG_PL_WR(TFU_IMG_FFT_SCALING_ADDR, (REG_PL_RD(TFU_IMG_FFT_SCALING_ADDR) & ~((uint32_t)0x00F00000)) | ((uint32_t)rximgpreamblesymbolnum <<20));
}
__INLINE uint8_t tfu_img_fft_scaling_rx_img_in_scale_heltf_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_IMG_FFT_SCALING_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void tfu_img_fft_scaling_rx_img_in_scale_heltf_setf(uint8_t rximginscaleheltf)
{
	ASSERT_ERR((((uint32_t)rximginscaleheltf << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(TFU_IMG_FFT_SCALING_ADDR, (REG_PL_RD(TFU_IMG_FFT_SCALING_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)rximginscaleheltf <<16));
}
__INLINE uint8_t tfu_img_fft_scaling_tx_img_out_scale_heltf_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_IMG_FFT_SCALING_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void tfu_img_fft_scaling_tx_img_out_scale_heltf_setf(uint8_t tximgoutscaleheltf)
{
	ASSERT_ERR((((uint32_t)tximgoutscaleheltf << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(TFU_IMG_FFT_SCALING_ADDR, (REG_PL_RD(TFU_IMG_FFT_SCALING_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)tximgoutscaleheltf <<12));
}
__INLINE uint8_t tfu_img_fft_scaling_tx_img_in_scale_heltf_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_IMG_FFT_SCALING_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void tfu_img_fft_scaling_tx_img_in_scale_heltf_setf(uint8_t tximginscaleheltf)
{
	ASSERT_ERR((((uint32_t)tximginscaleheltf << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(TFU_IMG_FFT_SCALING_ADDR, (REG_PL_RD(TFU_IMG_FFT_SCALING_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)tximginscaleheltf <<8));
}
__INLINE uint8_t tfu_img_fft_scaling_tx_img_out_scale_non_heltf_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_IMG_FFT_SCALING_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void tfu_img_fft_scaling_tx_img_out_scale_non_heltf_setf(uint8_t tximgoutscalenonheltf)
{
	ASSERT_ERR((((uint32_t)tximgoutscalenonheltf << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(TFU_IMG_FFT_SCALING_ADDR, (REG_PL_RD(TFU_IMG_FFT_SCALING_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)tximgoutscalenonheltf <<4));
}
__INLINE uint8_t tfu_img_fft_scaling_tx_img_in_scale_non_heltf_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_IMG_FFT_SCALING_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void tfu_img_fft_scaling_tx_img_in_scale_non_heltf_setf(uint8_t tximginscalenonheltf)
{
	ASSERT_ERR((((uint32_t)tximginscalenonheltf << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(TFU_IMG_FFT_SCALING_ADDR, (REG_PL_RD(TFU_IMG_FFT_SCALING_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)tximginscalenonheltf <<0));
}

/**
 * @brief INT_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    UNDERFLOW_EN              0              
 *    12    OVERFLOW_EN               0              
 *    08    MSG_EN                    0              
 *    04    TX_DONE_EN                0              
 *    00    RX_DONE_EN                0              
 * </pre>
 */
#define TFU_INT_EN_ADDR        (REG_TFU_BASE_ADDR+0x00000400)
#define TFU_INT_EN_OFFSET      0x00000400
#define TFU_INT_EN_INDEX       0x00000100
#define TFU_INT_EN_RESET       0x00000000

__INLINE uint32_t  tfu_int_en_get(void)
{
	return REG_PL_RD(TFU_INT_EN_ADDR);
}

__INLINE void tfu_int_en_set(uint32_t value)
{
	REG_PL_WR(TFU_INT_EN_ADDR, value);
}

// field definitions
#define TFU_INT_EN_UNDERFLOW_EN_BIT         ((uint32_t)0x00010000)
#define TFU_INT_EN_UNDERFLOW_EN_POS         16
#define TFU_INT_EN_OVERFLOW_EN_BIT          ((uint32_t)0x00001000)
#define TFU_INT_EN_OVERFLOW_EN_POS          12
#define TFU_INT_EN_MSG_EN_BIT               ((uint32_t)0x00000100)
#define TFU_INT_EN_MSG_EN_POS               8
#define TFU_INT_EN_TX_DONE_EN_BIT           ((uint32_t)0x00000010)
#define TFU_INT_EN_TX_DONE_EN_POS           4
#define TFU_INT_EN_RX_DONE_EN_BIT           ((uint32_t)0x00000001)
#define TFU_INT_EN_RX_DONE_EN_POS           0

#define TFU_INT_EN_UNDERFLOW_EN_RST         0x0
#define TFU_INT_EN_OVERFLOW_EN_RST          0x0
#define TFU_INT_EN_MSG_EN_RST               0x0
#define TFU_INT_EN_TX_DONE_EN_RST           0x0
#define TFU_INT_EN_RX_DONE_EN_RST           0x0

__INLINE void tfu_int_en_pack(uint8_t underflow_en, uint8_t overflow_en, uint8_t msg_en, uint8_t tx_done_en, uint8_t rx_done_en)
{
	ASSERT_ERR((((uint32_t)underflow_en << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)overflow_en << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)msg_en << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)tx_done_en << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)rx_done_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(TFU_INT_EN_ADDR,  ((uint32_t)underflow_en << 16) |((uint32_t)overflow_en << 12) |((uint32_t)msg_en << 8) |((uint32_t)tx_done_en << 4) |((uint32_t)rx_done_en << 0));
}

__INLINE void tfu_int_en_unpack(uint8_t* underflow_en, uint8_t* overflow_en, uint8_t* msg_en, uint8_t* tx_done_en, uint8_t* rx_done_en)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_EN_ADDR);

	*underflow_en = (localVal & ((uint32_t)0x00010000)) >>  16;
	*overflow_en = (localVal & ((uint32_t)0x00001000)) >>  12;
	*msg_en = (localVal & ((uint32_t)0x00000100)) >>  8;
	*tx_done_en = (localVal & ((uint32_t)0x00000010)) >>  4;
	*rx_done_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t tfu_int_en_underflow_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void tfu_int_en_underflow_en_setf(uint8_t underflowen)
{
	ASSERT_ERR((((uint32_t)underflowen << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(TFU_INT_EN_ADDR, (REG_PL_RD(TFU_INT_EN_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)underflowen <<16));
}
__INLINE uint8_t tfu_int_en_overflow_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void tfu_int_en_overflow_en_setf(uint8_t overflowen)
{
	ASSERT_ERR((((uint32_t)overflowen << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(TFU_INT_EN_ADDR, (REG_PL_RD(TFU_INT_EN_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)overflowen <<12));
}
__INLINE uint8_t tfu_int_en_msg_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void tfu_int_en_msg_en_setf(uint8_t msgen)
{
	ASSERT_ERR((((uint32_t)msgen << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(TFU_INT_EN_ADDR, (REG_PL_RD(TFU_INT_EN_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)msgen <<8));
}
__INLINE uint8_t tfu_int_en_tx_done_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void tfu_int_en_tx_done_en_setf(uint8_t txdoneen)
{
	ASSERT_ERR((((uint32_t)txdoneen << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(TFU_INT_EN_ADDR, (REG_PL_RD(TFU_INT_EN_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)txdoneen <<4));
}
__INLINE uint8_t tfu_int_en_rx_done_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_EN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void tfu_int_en_rx_done_en_setf(uint8_t rxdoneen)
{
	ASSERT_ERR((((uint32_t)rxdoneen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(TFU_INT_EN_ADDR, (REG_PL_RD(TFU_INT_EN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)rxdoneen <<0));
}

/**
 * @brief INT_STAT_RAW register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    UNDERFLOW_RAW             0              
 *    12    OVERFLOW_RAW              0              
 *    08    MSG_RAW                   0              
 *    04    TX_DONE_RAW               0              
 *    00    RX_DONE_RAW               0              
 * </pre>
 */
#define TFU_INT_STAT_RAW_ADDR        (REG_TFU_BASE_ADDR+0x00000404)
#define TFU_INT_STAT_RAW_OFFSET      0x00000404
#define TFU_INT_STAT_RAW_INDEX       0x00000101
#define TFU_INT_STAT_RAW_RESET       0x00000000

__INLINE uint32_t  tfu_int_stat_raw_get(void)
{
	return REG_PL_RD(TFU_INT_STAT_RAW_ADDR);
}

// field definitions
#define TFU_INT_STAT_RAW_UNDERFLOW_RAW_BIT    ((uint32_t)0x00010000)
#define TFU_INT_STAT_RAW_UNDERFLOW_RAW_POS    16
#define TFU_INT_STAT_RAW_OVERFLOW_RAW_BIT    ((uint32_t)0x00001000)
#define TFU_INT_STAT_RAW_OVERFLOW_RAW_POS    12
#define TFU_INT_STAT_RAW_MSG_RAW_BIT        ((uint32_t)0x00000100)
#define TFU_INT_STAT_RAW_MSG_RAW_POS        8
#define TFU_INT_STAT_RAW_TX_DONE_RAW_BIT    ((uint32_t)0x00000010)
#define TFU_INT_STAT_RAW_TX_DONE_RAW_POS    4
#define TFU_INT_STAT_RAW_RX_DONE_RAW_BIT    ((uint32_t)0x00000001)
#define TFU_INT_STAT_RAW_RX_DONE_RAW_POS    0

#define TFU_INT_STAT_RAW_UNDERFLOW_RAW_RST    0x0
#define TFU_INT_STAT_RAW_OVERFLOW_RAW_RST    0x0
#define TFU_INT_STAT_RAW_MSG_RAW_RST        0x0
#define TFU_INT_STAT_RAW_TX_DONE_RAW_RST    0x0
#define TFU_INT_STAT_RAW_RX_DONE_RAW_RST    0x0

__INLINE void tfu_int_stat_raw_unpack(uint8_t* underflow_raw, uint8_t* overflow_raw, uint8_t* msg_raw, uint8_t* tx_done_raw, uint8_t* rx_done_raw)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_STAT_RAW_ADDR);

	*underflow_raw = (localVal & ((uint32_t)0x00010000)) >>  16;
	*overflow_raw = (localVal & ((uint32_t)0x00001000)) >>  12;
	*msg_raw = (localVal & ((uint32_t)0x00000100)) >>  8;
	*tx_done_raw = (localVal & ((uint32_t)0x00000010)) >>  4;
	*rx_done_raw = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t tfu_int_stat_raw_underflow_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint8_t tfu_int_stat_raw_overflow_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t tfu_int_stat_raw_msg_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE uint8_t tfu_int_stat_raw_tx_done_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t tfu_int_stat_raw_rx_done_raw_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_STAT_RAW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief INT_STAT_MASKED register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    UNDERFLOW_MASKED          0              
 *    12    OVERFLOW_MASKED           0              
 *    08    MSG_MASKED                0              
 *    04    TX_DONE_MASKED            0              
 *    00    RX_DONE_MASKED            0              
 * </pre>
 */
#define TFU_INT_STAT_MASKED_ADDR        (REG_TFU_BASE_ADDR+0x00000408)
#define TFU_INT_STAT_MASKED_OFFSET      0x00000408
#define TFU_INT_STAT_MASKED_INDEX       0x00000102
#define TFU_INT_STAT_MASKED_RESET       0x00000000

__INLINE uint32_t  tfu_int_stat_masked_get(void)
{
	return REG_PL_RD(TFU_INT_STAT_MASKED_ADDR);
}

// field definitions
#define TFU_INT_STAT_MASKED_UNDERFLOW_MASKED_BIT    ((uint32_t)0x00010000)
#define TFU_INT_STAT_MASKED_UNDERFLOW_MASKED_POS    16
#define TFU_INT_STAT_MASKED_OVERFLOW_MASKED_BIT    ((uint32_t)0x00001000)
#define TFU_INT_STAT_MASKED_OVERFLOW_MASKED_POS    12
#define TFU_INT_STAT_MASKED_MSG_MASKED_BIT    ((uint32_t)0x00000100)
#define TFU_INT_STAT_MASKED_MSG_MASKED_POS    8
#define TFU_INT_STAT_MASKED_TX_DONE_MASKED_BIT    ((uint32_t)0x00000010)
#define TFU_INT_STAT_MASKED_TX_DONE_MASKED_POS    4
#define TFU_INT_STAT_MASKED_RX_DONE_MASKED_BIT    ((uint32_t)0x00000001)
#define TFU_INT_STAT_MASKED_RX_DONE_MASKED_POS    0

#define TFU_INT_STAT_MASKED_UNDERFLOW_MASKED_RST    0x0
#define TFU_INT_STAT_MASKED_OVERFLOW_MASKED_RST    0x0
#define TFU_INT_STAT_MASKED_MSG_MASKED_RST    0x0
#define TFU_INT_STAT_MASKED_TX_DONE_MASKED_RST    0x0
#define TFU_INT_STAT_MASKED_RX_DONE_MASKED_RST    0x0

__INLINE void tfu_int_stat_masked_unpack(uint8_t* underflow_masked, uint8_t* overflow_masked, uint8_t* msg_masked, uint8_t* tx_done_masked, uint8_t* rx_done_masked)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_STAT_MASKED_ADDR);

	*underflow_masked = (localVal & ((uint32_t)0x00010000)) >>  16;
	*overflow_masked = (localVal & ((uint32_t)0x00001000)) >>  12;
	*msg_masked = (localVal & ((uint32_t)0x00000100)) >>  8;
	*tx_done_masked = (localVal & ((uint32_t)0x00000010)) >>  4;
	*rx_done_masked = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t tfu_int_stat_masked_underflow_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE uint8_t tfu_int_stat_masked_overflow_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE uint8_t tfu_int_stat_masked_msg_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE uint8_t tfu_int_stat_masked_tx_done_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t tfu_int_stat_masked_rx_done_masked_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_STAT_MASKED_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief INT_ACK register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    UNDERFLOW_ACK             0              
 *    12    OVERFLOW_ACK              0              
 *    08    MSG_ACK                   0              
 *    04    TX_DONE_ACK               0              
 *    00    RX_DONE_ACK               0              
 * </pre>
 */
#define TFU_INT_ACK_ADDR        (REG_TFU_BASE_ADDR+0x0000040C)
#define TFU_INT_ACK_OFFSET      0x0000040C
#define TFU_INT_ACK_INDEX       0x00000103
#define TFU_INT_ACK_RESET       0x00000000

__INLINE uint32_t  tfu_int_ack_get(void)
{
	return REG_PL_RD(TFU_INT_ACK_ADDR);
}

__INLINE void tfu_int_ack_set(uint32_t value)
{
	REG_PL_WR(TFU_INT_ACK_ADDR, value);
}

__INLINE void tfu_int_ack_clear(uint32_t value)
{
	REG_PL_WR(TFU_INT_ACK_ADDR, value);
}

// field definitions
#define TFU_INT_ACK_UNDERFLOW_ACK_BIT       ((uint32_t)0x00010000)
#define TFU_INT_ACK_UNDERFLOW_ACK_POS       16
#define TFU_INT_ACK_OVERFLOW_ACK_BIT        ((uint32_t)0x00001000)
#define TFU_INT_ACK_OVERFLOW_ACK_POS        12
#define TFU_INT_ACK_MSG_ACK_BIT             ((uint32_t)0x00000100)
#define TFU_INT_ACK_MSG_ACK_POS             8
#define TFU_INT_ACK_TX_DONE_ACK_BIT         ((uint32_t)0x00000010)
#define TFU_INT_ACK_TX_DONE_ACK_POS         4
#define TFU_INT_ACK_RX_DONE_ACK_BIT         ((uint32_t)0x00000001)
#define TFU_INT_ACK_RX_DONE_ACK_POS         0

#define TFU_INT_ACK_UNDERFLOW_ACK_RST       0x0
#define TFU_INT_ACK_OVERFLOW_ACK_RST        0x0
#define TFU_INT_ACK_MSG_ACK_RST             0x0
#define TFU_INT_ACK_TX_DONE_ACK_RST         0x0
#define TFU_INT_ACK_RX_DONE_ACK_RST         0x0

__INLINE void tfu_int_ack_pack(uint8_t underflow_ack, uint8_t overflow_ack, uint8_t msg_ack, uint8_t tx_done_ack, uint8_t rx_done_ack)
{
	ASSERT_ERR((((uint32_t)underflow_ack << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)overflow_ack << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)msg_ack << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)tx_done_ack << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)rx_done_ack << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(TFU_INT_ACK_ADDR,  ((uint32_t)underflow_ack << 16) |((uint32_t)overflow_ack << 12) |((uint32_t)msg_ack << 8) |((uint32_t)tx_done_ack << 4) |((uint32_t)rx_done_ack << 0));
}

__INLINE void tfu_int_ack_unpack(uint8_t* underflow_ack, uint8_t* overflow_ack, uint8_t* msg_ack, uint8_t* tx_done_ack, uint8_t* rx_done_ack)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_ACK_ADDR);

	*underflow_ack = (localVal & ((uint32_t)0x00010000)) >>  16;
	*overflow_ack = (localVal & ((uint32_t)0x00001000)) >>  12;
	*msg_ack = (localVal & ((uint32_t)0x00000100)) >>  8;
	*tx_done_ack = (localVal & ((uint32_t)0x00000010)) >>  4;
	*rx_done_ack = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t tfu_int_ack_underflow_ack_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_ACK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void tfu_int_ack_underflow_ack_setf(uint8_t underflowack)
{
	ASSERT_ERR((((uint32_t)underflowack << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(TFU_INT_ACK_ADDR, (REG_PL_RD(TFU_INT_ACK_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)underflowack <<16));
}
__INLINE void tfu_int_ack_underflow_ack_clearf(uint8_t underflowack)
{
	ASSERT_ERR((((uint32_t)underflowack << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(TFU_INT_ACK_ADDR, (REG_PL_RD(TFU_INT_ACK_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)underflowack << 16));
}
__INLINE uint8_t tfu_int_ack_overflow_ack_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_ACK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void tfu_int_ack_overflow_ack_setf(uint8_t overflowack)
{
	ASSERT_ERR((((uint32_t)overflowack << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(TFU_INT_ACK_ADDR, (REG_PL_RD(TFU_INT_ACK_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)overflowack <<12));
}
__INLINE void tfu_int_ack_overflow_ack_clearf(uint8_t overflowack)
{
	ASSERT_ERR((((uint32_t)overflowack << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(TFU_INT_ACK_ADDR, (REG_PL_RD(TFU_INT_ACK_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)overflowack << 12));
}
__INLINE uint8_t tfu_int_ack_msg_ack_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_ACK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void tfu_int_ack_msg_ack_setf(uint8_t msgack)
{
	ASSERT_ERR((((uint32_t)msgack << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(TFU_INT_ACK_ADDR, (REG_PL_RD(TFU_INT_ACK_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)msgack <<8));
}
__INLINE void tfu_int_ack_msg_ack_clearf(uint8_t msgack)
{
	ASSERT_ERR((((uint32_t)msgack << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(TFU_INT_ACK_ADDR, (REG_PL_RD(TFU_INT_ACK_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)msgack << 8));
}
__INLINE uint8_t tfu_int_ack_tx_done_ack_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_ACK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void tfu_int_ack_tx_done_ack_setf(uint8_t txdoneack)
{
	ASSERT_ERR((((uint32_t)txdoneack << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(TFU_INT_ACK_ADDR, (REG_PL_RD(TFU_INT_ACK_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)txdoneack <<4));
}
__INLINE void tfu_int_ack_tx_done_ack_clearf(uint8_t txdoneack)
{
	ASSERT_ERR((((uint32_t)txdoneack << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(TFU_INT_ACK_ADDR, (REG_PL_RD(TFU_INT_ACK_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)txdoneack << 4));
}
__INLINE uint8_t tfu_int_ack_rx_done_ack_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_ACK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void tfu_int_ack_rx_done_ack_setf(uint8_t rxdoneack)
{
	ASSERT_ERR((((uint32_t)rxdoneack << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(TFU_INT_ACK_ADDR, (REG_PL_RD(TFU_INT_ACK_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)rxdoneack <<0));
}
__INLINE void tfu_int_ack_rx_done_ack_clearf(uint8_t rxdoneack)
{
	ASSERT_ERR((((uint32_t)rxdoneack << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(TFU_INT_ACK_ADDR, (REG_PL_RD(TFU_INT_ACK_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)rxdoneack << 0));
}

/**
 * @brief INT_GEN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16    UNDERFLOW_GEN             0              
 *    12    OVERFLOW_GEN              0              
 *    08    MSG_GEN                   0              
 *    04    TX_DONE_GEN               0              
 *    00    RX_DONE_GEN               0              
 * </pre>
 */
#define TFU_INT_GEN_ADDR        (REG_TFU_BASE_ADDR+0x00000410)
#define TFU_INT_GEN_OFFSET      0x00000410
#define TFU_INT_GEN_INDEX       0x00000104
#define TFU_INT_GEN_RESET       0x00000000

__INLINE uint32_t  tfu_int_gen_get(void)
{
	return REG_PL_RD(TFU_INT_GEN_ADDR);
}

__INLINE void tfu_int_gen_set(uint32_t value)
{
	REG_PL_WR(TFU_INT_GEN_ADDR, value);
}

// field definitions
#define TFU_INT_GEN_UNDERFLOW_GEN_BIT       ((uint32_t)0x00010000)
#define TFU_INT_GEN_UNDERFLOW_GEN_POS       16
#define TFU_INT_GEN_OVERFLOW_GEN_BIT        ((uint32_t)0x00001000)
#define TFU_INT_GEN_OVERFLOW_GEN_POS        12
#define TFU_INT_GEN_MSG_GEN_BIT             ((uint32_t)0x00000100)
#define TFU_INT_GEN_MSG_GEN_POS             8
#define TFU_INT_GEN_TX_DONE_GEN_BIT         ((uint32_t)0x00000010)
#define TFU_INT_GEN_TX_DONE_GEN_POS         4
#define TFU_INT_GEN_RX_DONE_GEN_BIT         ((uint32_t)0x00000001)
#define TFU_INT_GEN_RX_DONE_GEN_POS         0

#define TFU_INT_GEN_UNDERFLOW_GEN_RST       0x0
#define TFU_INT_GEN_OVERFLOW_GEN_RST        0x0
#define TFU_INT_GEN_MSG_GEN_RST             0x0
#define TFU_INT_GEN_TX_DONE_GEN_RST         0x0
#define TFU_INT_GEN_RX_DONE_GEN_RST         0x0

__INLINE void tfu_int_gen_pack(uint8_t underflow_gen, uint8_t overflow_gen, uint8_t msg_gen, uint8_t tx_done_gen, uint8_t rx_done_gen)
{
	ASSERT_ERR((((uint32_t)underflow_gen << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)overflow_gen << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)msg_gen << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)tx_done_gen << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)rx_done_gen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(TFU_INT_GEN_ADDR,  ((uint32_t)underflow_gen << 16) |((uint32_t)overflow_gen << 12) |((uint32_t)msg_gen << 8) |((uint32_t)tx_done_gen << 4) |((uint32_t)rx_done_gen << 0));
}

__INLINE void tfu_int_gen_unpack(uint8_t* underflow_gen, uint8_t* overflow_gen, uint8_t* msg_gen, uint8_t* tx_done_gen, uint8_t* rx_done_gen)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_GEN_ADDR);

	*underflow_gen = (localVal & ((uint32_t)0x00010000)) >>  16;
	*overflow_gen = (localVal & ((uint32_t)0x00001000)) >>  12;
	*msg_gen = (localVal & ((uint32_t)0x00000100)) >>  8;
	*tx_done_gen = (localVal & ((uint32_t)0x00000010)) >>  4;
	*rx_done_gen = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t tfu_int_gen_underflow_gen_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_GEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void tfu_int_gen_underflow_gen_setf(uint8_t underflowgen)
{
	ASSERT_ERR((((uint32_t)underflowgen << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(TFU_INT_GEN_ADDR, (REG_PL_RD(TFU_INT_GEN_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)underflowgen <<16));
}
__INLINE uint8_t tfu_int_gen_overflow_gen_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_GEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void tfu_int_gen_overflow_gen_setf(uint8_t overflowgen)
{
	ASSERT_ERR((((uint32_t)overflowgen << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(TFU_INT_GEN_ADDR, (REG_PL_RD(TFU_INT_GEN_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)overflowgen <<12));
}
__INLINE uint8_t tfu_int_gen_msg_gen_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_GEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void tfu_int_gen_msg_gen_setf(uint8_t msggen)
{
	ASSERT_ERR((((uint32_t)msggen << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(TFU_INT_GEN_ADDR, (REG_PL_RD(TFU_INT_GEN_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)msggen <<8));
}
__INLINE uint8_t tfu_int_gen_tx_done_gen_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_GEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void tfu_int_gen_tx_done_gen_setf(uint8_t txdonegen)
{
	ASSERT_ERR((((uint32_t)txdonegen << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(TFU_INT_GEN_ADDR, (REG_PL_RD(TFU_INT_GEN_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)txdonegen <<4));
}
__INLINE uint8_t tfu_int_gen_rx_done_gen_getf(void)
{
	uint32_t localVal = REG_PL_RD(TFU_INT_GEN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void tfu_int_gen_rx_done_gen_setf(uint8_t rxdonegen)
{
	ASSERT_ERR((((uint32_t)rxdonegen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(TFU_INT_GEN_ADDR, (REG_PL_RD(TFU_INT_GEN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)rxdonegen <<0));
}


#undef DBG_FILEID
#endif //_REG_TFU_H_
