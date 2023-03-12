#ifndef _REG_MACDSP_API1_H_
#define _REG_MACDSP_API1_H_

#include <stdint.h>
#include "_reg_macdsp_api1.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_MACDSP_API1__H__FILEID__

#define REG_MACDSP_API1_COUNT  291


/**
 * @brief CONFIG_SPACE register definition
 *  ConfigSpace register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:26 active_antenna_set        0x0
 *    25:20 rx_cck_active_chain       0x0
 *    19:14 rx_ofdm_active_chain      0x0
 *    13:08 tx_cck_active_chain       0x0
 *    07:06 band                      0x0
 *    05:04 channel_bandwidth         0x0
 *    03    ofdm_only                 0              
 *    02    rx_sensing_mode           0              
 *    01    update_sync               0              
 *    00    startup_sync              0              
 * </pre>
 */
#define MACDSP_API1_CONFIG_SPACE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000010)
#define MACDSP_API1_CONFIG_SPACE_OFFSET      0x00000010
#define MACDSP_API1_CONFIG_SPACE_INDEX       0x00000004
#define MACDSP_API1_CONFIG_SPACE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_config_space_get(void)
{
	return REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR);
}

__INLINE void macdsp_api1_config_space_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_CONFIG_SPACE_ADDR, value);
}

// field definitions
#define MACDSP_API1_CONFIG_SPACE_ACTIVE_ANTENNA_SET_MASK    ((uint32_t)0xFC000000)
#define MACDSP_API1_CONFIG_SPACE_ACTIVE_ANTENNA_SET_LSB    26
#define MACDSP_API1_CONFIG_SPACE_ACTIVE_ANTENNA_SET_WIDTH    ((uint32_t)0x00000006)
#define MACDSP_API1_CONFIG_SPACE_RX_CCK_ACTIVE_CHAIN_MASK    ((uint32_t)0x03F00000)
#define MACDSP_API1_CONFIG_SPACE_RX_CCK_ACTIVE_CHAIN_LSB    20
#define MACDSP_API1_CONFIG_SPACE_RX_CCK_ACTIVE_CHAIN_WIDTH    ((uint32_t)0x00000006)
#define MACDSP_API1_CONFIG_SPACE_RX_OFDM_ACTIVE_CHAIN_MASK    ((uint32_t)0x000FC000)
#define MACDSP_API1_CONFIG_SPACE_RX_OFDM_ACTIVE_CHAIN_LSB    14
#define MACDSP_API1_CONFIG_SPACE_RX_OFDM_ACTIVE_CHAIN_WIDTH    ((uint32_t)0x00000006)
#define MACDSP_API1_CONFIG_SPACE_TX_CCK_ACTIVE_CHAIN_MASK    ((uint32_t)0x00003F00)
#define MACDSP_API1_CONFIG_SPACE_TX_CCK_ACTIVE_CHAIN_LSB    8
#define MACDSP_API1_CONFIG_SPACE_TX_CCK_ACTIVE_CHAIN_WIDTH    ((uint32_t)0x00000006)
#define MACDSP_API1_CONFIG_SPACE_BAND_MASK    ((uint32_t)0x000000C0)
#define MACDSP_API1_CONFIG_SPACE_BAND_LSB    6
#define MACDSP_API1_CONFIG_SPACE_BAND_WIDTH    ((uint32_t)0x00000002)
#define MACDSP_API1_CONFIG_SPACE_CHANNEL_BANDWIDTH_MASK    ((uint32_t)0x00000030)
#define MACDSP_API1_CONFIG_SPACE_CHANNEL_BANDWIDTH_LSB    4
#define MACDSP_API1_CONFIG_SPACE_CHANNEL_BANDWIDTH_WIDTH    ((uint32_t)0x00000002)
#define MACDSP_API1_CONFIG_SPACE_OFDM_ONLY_BIT    ((uint32_t)0x00000008)
#define MACDSP_API1_CONFIG_SPACE_OFDM_ONLY_POS    3
#define MACDSP_API1_CONFIG_SPACE_RX_SENSING_MODE_BIT    ((uint32_t)0x00000004)
#define MACDSP_API1_CONFIG_SPACE_RX_SENSING_MODE_POS    2
#define MACDSP_API1_CONFIG_SPACE_UPDATE_SYNC_BIT    ((uint32_t)0x00000002)
#define MACDSP_API1_CONFIG_SPACE_UPDATE_SYNC_POS    1
#define MACDSP_API1_CONFIG_SPACE_STARTUP_SYNC_BIT    ((uint32_t)0x00000001)
#define MACDSP_API1_CONFIG_SPACE_STARTUP_SYNC_POS    0

#define MACDSP_API1_CONFIG_SPACE_ACTIVE_ANTENNA_SET_RST    0x0
#define MACDSP_API1_CONFIG_SPACE_RX_CCK_ACTIVE_CHAIN_RST    0x0
#define MACDSP_API1_CONFIG_SPACE_RX_OFDM_ACTIVE_CHAIN_RST    0x0
#define MACDSP_API1_CONFIG_SPACE_TX_CCK_ACTIVE_CHAIN_RST    0x0
#define MACDSP_API1_CONFIG_SPACE_BAND_RST    0x0
#define MACDSP_API1_CONFIG_SPACE_CHANNEL_BANDWIDTH_RST    0x0
#define MACDSP_API1_CONFIG_SPACE_OFDM_ONLY_RST    0x0
#define MACDSP_API1_CONFIG_SPACE_RX_SENSING_MODE_RST    0x0
#define MACDSP_API1_CONFIG_SPACE_UPDATE_SYNC_RST    0x0
#define MACDSP_API1_CONFIG_SPACE_STARTUP_SYNC_RST    0x0

__INLINE void macdsp_api1_config_space_pack(uint8_t active_antenna_set, uint8_t rx_cck_active_chain, uint8_t rx_ofdm_active_chain, uint8_t tx_cck_active_chain, uint8_t band, uint8_t channel_bandwidth, uint8_t ofdm_only, uint8_t rx_sensing_mode, uint8_t update_sync, uint8_t startup_sync)
{
	ASSERT_ERR((((uint32_t)active_antenna_set << 26) & ~((uint32_t)0xFC000000)) == 0);
	ASSERT_ERR((((uint32_t)rx_cck_active_chain << 20) & ~((uint32_t)0x03F00000)) == 0);
	ASSERT_ERR((((uint32_t)rx_ofdm_active_chain << 14) & ~((uint32_t)0x000FC000)) == 0);
	ASSERT_ERR((((uint32_t)tx_cck_active_chain << 8) & ~((uint32_t)0x00003F00)) == 0);
	ASSERT_ERR((((uint32_t)band << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)channel_bandwidth << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)ofdm_only << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)rx_sensing_mode << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)update_sync << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)startup_sync << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACDSP_API1_CONFIG_SPACE_ADDR,  ((uint32_t)active_antenna_set << 26) |((uint32_t)rx_cck_active_chain << 20) |((uint32_t)rx_ofdm_active_chain << 14) |((uint32_t)tx_cck_active_chain << 8) |((uint32_t)band << 6) |((uint32_t)channel_bandwidth << 4) |((uint32_t)ofdm_only << 3) |((uint32_t)rx_sensing_mode << 2) |((uint32_t)update_sync << 1) |((uint32_t)startup_sync << 0));
}

__INLINE void macdsp_api1_config_space_unpack(uint8_t* active_antenna_set, uint8_t* rx_cck_active_chain, uint8_t* rx_ofdm_active_chain, uint8_t* tx_cck_active_chain, uint8_t* band, uint8_t* channel_bandwidth, uint8_t* ofdm_only, uint8_t* rx_sensing_mode, uint8_t* update_sync, uint8_t* startup_sync)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR);

	*active_antenna_set = (localVal & ((uint32_t)0xFC000000)) >>  26;
	*rx_cck_active_chain = (localVal & ((uint32_t)0x03F00000)) >>  20;
	*rx_ofdm_active_chain = (localVal & ((uint32_t)0x000FC000)) >>  14;
	*tx_cck_active_chain = (localVal & ((uint32_t)0x00003F00)) >>  8;
	*band = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*channel_bandwidth = (localVal & ((uint32_t)0x00000030)) >>  4;
	*ofdm_only = (localVal & ((uint32_t)0x00000008)) >>  3;
	*rx_sensing_mode = (localVal & ((uint32_t)0x00000004)) >>  2;
	*update_sync = (localVal & ((uint32_t)0x00000002)) >>  1;
	*startup_sync = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t macdsp_api1_config_space_active_antenna_set_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFC000000)) >> 26);
}
__INLINE void macdsp_api1_config_space_active_antenna_set_setf(uint8_t activeantennaset)
{
	ASSERT_ERR((((uint32_t)activeantennaset << 26) & ~((uint32_t)0xFC000000)) == 0);
	REG_PL_WR(MACDSP_API1_CONFIG_SPACE_ADDR, (REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR) & ~((uint32_t)0xFC000000)) | ((uint32_t)activeantennaset <<26));
}
__INLINE uint8_t macdsp_api1_config_space_rx_cck_active_chain_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x03F00000)) >> 20);
}
__INLINE void macdsp_api1_config_space_rx_cck_active_chain_setf(uint8_t rxcckactivechain)
{
	ASSERT_ERR((((uint32_t)rxcckactivechain << 20) & ~((uint32_t)0x03F00000)) == 0);
	REG_PL_WR(MACDSP_API1_CONFIG_SPACE_ADDR, (REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR) & ~((uint32_t)0x03F00000)) | ((uint32_t)rxcckactivechain <<20));
}
__INLINE uint8_t macdsp_api1_config_space_rx_ofdm_active_chain_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000FC000)) >> 14);
}
__INLINE void macdsp_api1_config_space_rx_ofdm_active_chain_setf(uint8_t rxofdmactivechain)
{
	ASSERT_ERR((((uint32_t)rxofdmactivechain << 14) & ~((uint32_t)0x000FC000)) == 0);
	REG_PL_WR(MACDSP_API1_CONFIG_SPACE_ADDR, (REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR) & ~((uint32_t)0x000FC000)) | ((uint32_t)rxofdmactivechain <<14));
}
__INLINE uint8_t macdsp_api1_config_space_tx_cck_active_chain_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003F00)) >> 8);
}
__INLINE void macdsp_api1_config_space_tx_cck_active_chain_setf(uint8_t txcckactivechain)
{
	ASSERT_ERR((((uint32_t)txcckactivechain << 8) & ~((uint32_t)0x00003F00)) == 0);
	REG_PL_WR(MACDSP_API1_CONFIG_SPACE_ADDR, (REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)txcckactivechain <<8));
}
__INLINE uint8_t macdsp_api1_config_space_band_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void macdsp_api1_config_space_band_setf(uint8_t band)
{
	ASSERT_ERR((((uint32_t)band << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(MACDSP_API1_CONFIG_SPACE_ADDR, (REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)band <<6));
}
__INLINE uint8_t macdsp_api1_config_space_channel_bandwidth_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void macdsp_api1_config_space_channel_bandwidth_setf(uint8_t channelbandwidth)
{
	ASSERT_ERR((((uint32_t)channelbandwidth << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(MACDSP_API1_CONFIG_SPACE_ADDR, (REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)channelbandwidth <<4));
}
__INLINE uint8_t macdsp_api1_config_space_ofdm_only_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void macdsp_api1_config_space_ofdm_only_setf(uint8_t ofdmonly)
{
	ASSERT_ERR((((uint32_t)ofdmonly << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(MACDSP_API1_CONFIG_SPACE_ADDR, (REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)ofdmonly <<3));
}
__INLINE uint8_t macdsp_api1_config_space_rx_sensing_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void macdsp_api1_config_space_rx_sensing_mode_setf(uint8_t rxsensingmode)
{
	ASSERT_ERR((((uint32_t)rxsensingmode << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(MACDSP_API1_CONFIG_SPACE_ADDR, (REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)rxsensingmode <<2));
}
__INLINE uint8_t macdsp_api1_config_space_update_sync_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void macdsp_api1_config_space_update_sync_setf(uint8_t updatesync)
{
	ASSERT_ERR((((uint32_t)updatesync << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(MACDSP_API1_CONFIG_SPACE_ADDR, (REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)updatesync <<1));
}
__INLINE uint8_t macdsp_api1_config_space_startup_sync_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void macdsp_api1_config_space_startup_sync_setf(uint8_t startupsync)
{
	ASSERT_ERR((((uint32_t)startupsync << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACDSP_API1_CONFIG_SPACE_ADDR, (REG_PL_RD(MACDSP_API1_CONFIG_SPACE_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)startupsync <<0));
}

/**
 * @brief MAC_DSP_API_0 register definition
 *  MAC_DSP_API_0 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 current_ant_iq_calib      0x0
 *    22:20 gain_update_enable        0x0
 *    19:17 mac_dsp_api_0_reserved0   0x0
 *    16    td_csd_enable             0              
 *    15    No_Capture_Noise_Sleep_AGC_state 0              
 *    14    RICU_loopback             0              
 *    13    tx_power_baypss           0              
 *    12:11 hr_factor_mode            0x0
 *    10    radar_mask_en             0              
 *    09    phy_id                    0              
 *    08:04 xmem_block_size           0x10
 *    03    signal_ext_en             0              
 *    02:01 available_bw              0x2
 *    00    bw_signaling_en           1              
 * </pre>
 */
#define MACDSP_API1_MAC_DSP_API_0_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000014)
#define MACDSP_API1_MAC_DSP_API_0_OFFSET      0x00000014
#define MACDSP_API1_MAC_DSP_API_0_INDEX       0x00000005
#define MACDSP_API1_MAC_DSP_API_0_RESET       0x00000105

__INLINE uint32_t  macdsp_api1_mac_dsp_api_0_get(void)
{
	return REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR);
}

__INLINE void macdsp_api1_mac_dsp_api_0_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_MAC_DSP_API_0_ADDR, value);
}

// field definitions
#define MACDSP_API1_MAC_DSP_API_0_CURRENT_ANT_IQ_CALIB_MASK    ((uint32_t)0xFF000000)
#define MACDSP_API1_MAC_DSP_API_0_CURRENT_ANT_IQ_CALIB_LSB    24
#define MACDSP_API1_MAC_DSP_API_0_CURRENT_ANT_IQ_CALIB_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_MAC_DSP_API_0_GAIN_UPDATE_ENABLE_MASK    ((uint32_t)0x00700000)
#define MACDSP_API1_MAC_DSP_API_0_GAIN_UPDATE_ENABLE_LSB    20
#define MACDSP_API1_MAC_DSP_API_0_GAIN_UPDATE_ENABLE_WIDTH    ((uint32_t)0x00000003)
#define MACDSP_API1_MAC_DSP_API_0_MAC_DSP_API_0_RESERVED_0_MASK    ((uint32_t)0x000E0000)
#define MACDSP_API1_MAC_DSP_API_0_MAC_DSP_API_0_RESERVED_0_LSB    17
#define MACDSP_API1_MAC_DSP_API_0_MAC_DSP_API_0_RESERVED_0_WIDTH    ((uint32_t)0x00000003)
#define MACDSP_API1_MAC_DSP_API_0_TD_CSD_ENABLE_BIT    ((uint32_t)0x00010000)
#define MACDSP_API1_MAC_DSP_API_0_TD_CSD_ENABLE_POS    16
#define MACDSP_API1_MAC_DSP_API_0_NO_CAPTURE_NOISE_SLEEP_AGC_STATE_BIT    ((uint32_t)0x00008000)
#define MACDSP_API1_MAC_DSP_API_0_NO_CAPTURE_NOISE_SLEEP_AGC_STATE_POS    15
#define MACDSP_API1_MAC_DSP_API_0_RICU_LOOPBACK_BIT    ((uint32_t)0x00004000)
#define MACDSP_API1_MAC_DSP_API_0_RICU_LOOPBACK_POS    14
#define MACDSP_API1_MAC_DSP_API_0_TX_POWER_BAYPSS_BIT    ((uint32_t)0x00002000)
#define MACDSP_API1_MAC_DSP_API_0_TX_POWER_BAYPSS_POS    13
#define MACDSP_API1_MAC_DSP_API_0_HR_FACTOR_MODE_MASK    ((uint32_t)0x00001800)
#define MACDSP_API1_MAC_DSP_API_0_HR_FACTOR_MODE_LSB    11
#define MACDSP_API1_MAC_DSP_API_0_HR_FACTOR_MODE_WIDTH    ((uint32_t)0x00000002)
#define MACDSP_API1_MAC_DSP_API_0_RADAR_MASK_EN_BIT    ((uint32_t)0x00000400)
#define MACDSP_API1_MAC_DSP_API_0_RADAR_MASK_EN_POS    10
#define MACDSP_API1_MAC_DSP_API_0_PHY_ID_BIT    ((uint32_t)0x00000200)
#define MACDSP_API1_MAC_DSP_API_0_PHY_ID_POS    9
#define MACDSP_API1_MAC_DSP_API_0_XMEM_BLOCK_SIZE_MASK    ((uint32_t)0x000001F0)
#define MACDSP_API1_MAC_DSP_API_0_XMEM_BLOCK_SIZE_LSB    4
#define MACDSP_API1_MAC_DSP_API_0_XMEM_BLOCK_SIZE_WIDTH    ((uint32_t)0x00000005)
#define MACDSP_API1_MAC_DSP_API_0_SIGNAL_EXT_EN_BIT    ((uint32_t)0x00000008)
#define MACDSP_API1_MAC_DSP_API_0_SIGNAL_EXT_EN_POS    3
#define MACDSP_API1_MAC_DSP_API_0_AVAILABLE_BW_MASK    ((uint32_t)0x00000006)
#define MACDSP_API1_MAC_DSP_API_0_AVAILABLE_BW_LSB    1
#define MACDSP_API1_MAC_DSP_API_0_AVAILABLE_BW_WIDTH    ((uint32_t)0x00000002)
#define MACDSP_API1_MAC_DSP_API_0_BW_SIGNALING_EN_BIT    ((uint32_t)0x00000001)
#define MACDSP_API1_MAC_DSP_API_0_BW_SIGNALING_EN_POS    0

#define MACDSP_API1_MAC_DSP_API_0_CURRENT_ANT_IQ_CALIB_RST    0x0
#define MACDSP_API1_MAC_DSP_API_0_GAIN_UPDATE_ENABLE_RST    0x0
#define MACDSP_API1_MAC_DSP_API_0_MAC_DSP_API_0_RESERVED_0_RST    0x0
#define MACDSP_API1_MAC_DSP_API_0_TD_CSD_ENABLE_RST    0x0
#define MACDSP_API1_MAC_DSP_API_0_NO_CAPTURE_NOISE_SLEEP_AGC_STATE_RST    0x0
#define MACDSP_API1_MAC_DSP_API_0_RICU_LOOPBACK_RST    0x0
#define MACDSP_API1_MAC_DSP_API_0_TX_POWER_BAYPSS_RST    0x0
#define MACDSP_API1_MAC_DSP_API_0_HR_FACTOR_MODE_RST    0x0
#define MACDSP_API1_MAC_DSP_API_0_RADAR_MASK_EN_RST    0x0
#define MACDSP_API1_MAC_DSP_API_0_PHY_ID_RST    0x0
#define MACDSP_API1_MAC_DSP_API_0_XMEM_BLOCK_SIZE_RST    0x10
#define MACDSP_API1_MAC_DSP_API_0_SIGNAL_EXT_EN_RST    0x0
#define MACDSP_API1_MAC_DSP_API_0_AVAILABLE_BW_RST    0x2
#define MACDSP_API1_MAC_DSP_API_0_BW_SIGNALING_EN_RST    0x1

__INLINE void macdsp_api1_mac_dsp_api_0_pack(uint8_t current_ant_iq_calib, uint8_t gain_update_enable, uint8_t mac_dsp_api_0_reserved0, uint8_t td_csd_enable, uint8_t no_capture_noise_sleep_agc_state, uint8_t ricu_loopback, uint8_t tx_power_baypss, uint8_t hr_factor_mode, uint8_t radar_mask_en, uint8_t phy_id, uint8_t xmem_block_size, uint8_t signal_ext_en, uint8_t available_bw, uint8_t bw_signaling_en)
{
	ASSERT_ERR((((uint32_t)current_ant_iq_calib << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)gain_update_enable << 20) & ~((uint32_t)0x00700000)) == 0);
	ASSERT_ERR((((uint32_t)mac_dsp_api_0_reserved0 << 17) & ~((uint32_t)0x000E0000)) == 0);
	ASSERT_ERR((((uint32_t)td_csd_enable << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)no_capture_noise_sleep_agc_state << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)ricu_loopback << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)tx_power_baypss << 13) & ~((uint32_t)0x00002000)) == 0);
	ASSERT_ERR((((uint32_t)hr_factor_mode << 11) & ~((uint32_t)0x00001800)) == 0);
	ASSERT_ERR((((uint32_t)radar_mask_en << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)phy_id << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)xmem_block_size << 4) & ~((uint32_t)0x000001F0)) == 0);
	ASSERT_ERR((((uint32_t)signal_ext_en << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)available_bw << 1) & ~((uint32_t)0x00000006)) == 0);
	ASSERT_ERR((((uint32_t)bw_signaling_en << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_DSP_API_0_ADDR,  ((uint32_t)current_ant_iq_calib << 24) |((uint32_t)gain_update_enable << 20) |((uint32_t)mac_dsp_api_0_reserved0 << 17) |((uint32_t)td_csd_enable << 16) |((uint32_t)no_capture_noise_sleep_agc_state << 15) |((uint32_t)ricu_loopback << 14) |((uint32_t)tx_power_baypss << 13) |((uint32_t)hr_factor_mode << 11) |((uint32_t)radar_mask_en << 10) |((uint32_t)phy_id << 9) |((uint32_t)xmem_block_size << 4) |((uint32_t)signal_ext_en << 3) |((uint32_t)available_bw << 1) |((uint32_t)bw_signaling_en << 0));
}

__INLINE void macdsp_api1_mac_dsp_api_0_unpack(uint8_t* current_ant_iq_calib, uint8_t* gain_update_enable, uint8_t* mac_dsp_api_0_reserved0, uint8_t* td_csd_enable, uint8_t* no_capture_noise_sleep_agc_state, uint8_t* ricu_loopback, uint8_t* tx_power_baypss, uint8_t* hr_factor_mode, uint8_t* radar_mask_en, uint8_t* phy_id, uint8_t* xmem_block_size, uint8_t* signal_ext_en, uint8_t* available_bw, uint8_t* bw_signaling_en)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR);

	*current_ant_iq_calib = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*gain_update_enable = (localVal & ((uint32_t)0x00700000)) >>  20;
	*mac_dsp_api_0_reserved0 = (localVal & ((uint32_t)0x000E0000)) >>  17;
	*td_csd_enable = (localVal & ((uint32_t)0x00010000)) >>  16;
	*no_capture_noise_sleep_agc_state = (localVal & ((uint32_t)0x00008000)) >>  15;
	*ricu_loopback = (localVal & ((uint32_t)0x00004000)) >>  14;
	*tx_power_baypss = (localVal & ((uint32_t)0x00002000)) >>  13;
	*hr_factor_mode = (localVal & ((uint32_t)0x00001800)) >>  11;
	*radar_mask_en = (localVal & ((uint32_t)0x00000400)) >>  10;
	*phy_id = (localVal & ((uint32_t)0x00000200)) >>  9;
	*xmem_block_size = (localVal & ((uint32_t)0x000001F0)) >>  4;
	*signal_ext_en = (localVal & ((uint32_t)0x00000008)) >>  3;
	*available_bw = (localVal & ((uint32_t)0x00000006)) >>  1;
	*bw_signaling_en = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t macdsp_api1_mac_dsp_api_0_current_ant_iq_calib_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE uint8_t macdsp_api1_mac_dsp_api_0_gain_update_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00700000)) >> 20);
}
__INLINE void macdsp_api1_mac_dsp_api_0_gain_update_enable_setf(uint8_t gainupdateenable)
{
	ASSERT_ERR((((uint32_t)gainupdateenable << 20) & ~((uint32_t)0x00700000)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_DSP_API_0_ADDR, (REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR) & ~((uint32_t)0x00700000)) | ((uint32_t)gainupdateenable <<20));
}
__INLINE uint8_t macdsp_api1_mac_dsp_api_0_mac_dsp_api_0_reserved_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000E0000)) >> 17);
}
__INLINE void macdsp_api1_mac_dsp_api_0_mac_dsp_api_0_reserved_0_setf(uint8_t macdspapi0reserved0)
{
	ASSERT_ERR((((uint32_t)macdspapi0reserved0 << 17) & ~((uint32_t)0x000E0000)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_DSP_API_0_ADDR, (REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR) & ~((uint32_t)0x000E0000)) | ((uint32_t)macdspapi0reserved0 <<17));
}
__INLINE uint8_t macdsp_api1_mac_dsp_api_0_td_csd_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void macdsp_api1_mac_dsp_api_0_td_csd_enable_setf(uint8_t tdcsdenable)
{
	ASSERT_ERR((((uint32_t)tdcsdenable << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_DSP_API_0_ADDR, (REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)tdcsdenable <<16));
}
__INLINE uint8_t macdsp_api1_mac_dsp_api_0_no_capture_noise_sleep_agc_state_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void macdsp_api1_mac_dsp_api_0_no_capture_noise_sleep_agc_state_setf(uint8_t nocapturenoisesleepagcstate)
{
	ASSERT_ERR((((uint32_t)nocapturenoisesleepagcstate << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_DSP_API_0_ADDR, (REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)nocapturenoisesleepagcstate <<15));
}
__INLINE uint8_t macdsp_api1_mac_dsp_api_0_ricu_loopback_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void macdsp_api1_mac_dsp_api_0_ricu_loopback_setf(uint8_t riculoopback)
{
	ASSERT_ERR((((uint32_t)riculoopback << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_DSP_API_0_ADDR, (REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)riculoopback <<14));
}
__INLINE uint8_t macdsp_api1_mac_dsp_api_0_tx_power_baypss_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00002000)) >> 13);
}
__INLINE void macdsp_api1_mac_dsp_api_0_tx_power_baypss_setf(uint8_t txpowerbaypss)
{
	ASSERT_ERR((((uint32_t)txpowerbaypss << 13) & ~((uint32_t)0x00002000)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_DSP_API_0_ADDR, (REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)txpowerbaypss <<13));
}
__INLINE uint8_t macdsp_api1_mac_dsp_api_0_hr_factor_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001800)) >> 11);
}
__INLINE void macdsp_api1_mac_dsp_api_0_hr_factor_mode_setf(uint8_t hrfactormode)
{
	ASSERT_ERR((((uint32_t)hrfactormode << 11) & ~((uint32_t)0x00001800)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_DSP_API_0_ADDR, (REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR) & ~((uint32_t)0x00001800)) | ((uint32_t)hrfactormode <<11));
}
__INLINE uint8_t macdsp_api1_mac_dsp_api_0_radar_mask_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void macdsp_api1_mac_dsp_api_0_radar_mask_en_setf(uint8_t radarmasken)
{
	ASSERT_ERR((((uint32_t)radarmasken << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_DSP_API_0_ADDR, (REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)radarmasken <<10));
}
__INLINE uint8_t macdsp_api1_mac_dsp_api_0_phy_id_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE uint8_t macdsp_api1_mac_dsp_api_0_xmem_block_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000001F0)) >> 4);
}
__INLINE void macdsp_api1_mac_dsp_api_0_xmem_block_size_setf(uint8_t xmemblocksize)
{
	ASSERT_ERR((((uint32_t)xmemblocksize << 4) & ~((uint32_t)0x000001F0)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_DSP_API_0_ADDR, (REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR) & ~((uint32_t)0x000001F0)) | ((uint32_t)xmemblocksize <<4));
}
__INLINE uint8_t macdsp_api1_mac_dsp_api_0_signal_ext_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void macdsp_api1_mac_dsp_api_0_signal_ext_en_setf(uint8_t signalexten)
{
	ASSERT_ERR((((uint32_t)signalexten << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_DSP_API_0_ADDR, (REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)signalexten <<3));
}
__INLINE uint8_t macdsp_api1_mac_dsp_api_0_available_bw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000006)) >> 1);
}
__INLINE void macdsp_api1_mac_dsp_api_0_available_bw_setf(uint8_t availablebw)
{
	ASSERT_ERR((((uint32_t)availablebw << 1) & ~((uint32_t)0x00000006)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_DSP_API_0_ADDR, (REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR) & ~((uint32_t)0x00000006)) | ((uint32_t)availablebw <<1));
}
__INLINE uint8_t macdsp_api1_mac_dsp_api_0_bw_signaling_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void macdsp_api1_mac_dsp_api_0_bw_signaling_en_setf(uint8_t bwsignalingen)
{
	ASSERT_ERR((((uint32_t)bwsignalingen << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_DSP_API_0_ADDR, (REG_PL_RD(MACDSP_API1_MAC_DSP_API_0_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)bwsignalingen <<0));
}

/**
 * @brief MAC_DSP_AGC_API register definition
 *  MAC_DSP_AGC_API register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 agc_rx_delay_after_ht_vht_ofdm_tx 0x0
 *    23:16 agc_rx_delay_after_legacy_ofdm_tx 0x0
 *    15:08 agc_rx_delay_after_cck_tx 0x0
 *    07:00 agc_rx_delay_addr_offset  0x0
 * </pre>
 */
#define MACDSP_API1_MAC_DSP_AGC_API_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000018)
#define MACDSP_API1_MAC_DSP_AGC_API_OFFSET      0x00000018
#define MACDSP_API1_MAC_DSP_AGC_API_INDEX       0x00000006
#define MACDSP_API1_MAC_DSP_AGC_API_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_mac_dsp_agc_api_get(void)
{
	return REG_PL_RD(MACDSP_API1_MAC_DSP_AGC_API_ADDR);
}

__INLINE void macdsp_api1_mac_dsp_agc_api_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_MAC_DSP_AGC_API_ADDR, value);
}

// field definitions
#define MACDSP_API1_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_HT_VHT_OFDM_TX_MASK    ((uint32_t)0xFF000000)
#define MACDSP_API1_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_HT_VHT_OFDM_TX_LSB    24
#define MACDSP_API1_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_HT_VHT_OFDM_TX_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_LEGACY_OFDM_TX_MASK    ((uint32_t)0x00FF0000)
#define MACDSP_API1_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_LEGACY_OFDM_TX_LSB    16
#define MACDSP_API1_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_LEGACY_OFDM_TX_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_CCK_TX_MASK    ((uint32_t)0x0000FF00)
#define MACDSP_API1_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_CCK_TX_LSB    8
#define MACDSP_API1_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_CCK_TX_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_MAC_DSP_AGC_API_AGC_RX_DELAY_ADDR_OFFSET_MASK    ((uint32_t)0x000000FF)
#define MACDSP_API1_MAC_DSP_AGC_API_AGC_RX_DELAY_ADDR_OFFSET_LSB    0
#define MACDSP_API1_MAC_DSP_AGC_API_AGC_RX_DELAY_ADDR_OFFSET_WIDTH    ((uint32_t)0x00000008)

#define MACDSP_API1_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_HT_VHT_OFDM_TX_RST    0x0
#define MACDSP_API1_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_LEGACY_OFDM_TX_RST    0x0
#define MACDSP_API1_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_CCK_TX_RST    0x0
#define MACDSP_API1_MAC_DSP_AGC_API_AGC_RX_DELAY_ADDR_OFFSET_RST    0x0

__INLINE void macdsp_api1_mac_dsp_agc_api_pack(uint8_t agc_rx_delay_after_ht_vht_ofdm_tx, uint8_t agc_rx_delay_after_legacy_ofdm_tx, uint8_t agc_rx_delay_after_cck_tx, uint8_t agc_rx_delay_addr_offset)
{
	ASSERT_ERR((((uint32_t)agc_rx_delay_after_ht_vht_ofdm_tx << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)agc_rx_delay_after_legacy_ofdm_tx << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)agc_rx_delay_after_cck_tx << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)agc_rx_delay_addr_offset << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_DSP_AGC_API_ADDR,  ((uint32_t)agc_rx_delay_after_ht_vht_ofdm_tx << 24) |((uint32_t)agc_rx_delay_after_legacy_ofdm_tx << 16) |((uint32_t)agc_rx_delay_after_cck_tx << 8) |((uint32_t)agc_rx_delay_addr_offset << 0));
}

__INLINE void macdsp_api1_mac_dsp_agc_api_unpack(uint8_t* agc_rx_delay_after_ht_vht_ofdm_tx, uint8_t* agc_rx_delay_after_legacy_ofdm_tx, uint8_t* agc_rx_delay_after_cck_tx, uint8_t* agc_rx_delay_addr_offset)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_AGC_API_ADDR);

	*agc_rx_delay_after_ht_vht_ofdm_tx = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*agc_rx_delay_after_legacy_ofdm_tx = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*agc_rx_delay_after_cck_tx = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*agc_rx_delay_addr_offset = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t macdsp_api1_mac_dsp_agc_api_agc_rx_delay_after_ht_vht_ofdm_tx_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_AGC_API_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void macdsp_api1_mac_dsp_agc_api_agc_rx_delay_after_ht_vht_ofdm_tx_setf(uint8_t agcrxdelayafterhtvhtofdmtx)
{
	ASSERT_ERR((((uint32_t)agcrxdelayafterhtvhtofdmtx << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_DSP_AGC_API_ADDR, (REG_PL_RD(MACDSP_API1_MAC_DSP_AGC_API_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)agcrxdelayafterhtvhtofdmtx <<24));
}
__INLINE uint8_t macdsp_api1_mac_dsp_agc_api_agc_rx_delay_after_legacy_ofdm_tx_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_AGC_API_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void macdsp_api1_mac_dsp_agc_api_agc_rx_delay_after_legacy_ofdm_tx_setf(uint8_t agcrxdelayafterlegacyofdmtx)
{
	ASSERT_ERR((((uint32_t)agcrxdelayafterlegacyofdmtx << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_DSP_AGC_API_ADDR, (REG_PL_RD(MACDSP_API1_MAC_DSP_AGC_API_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)agcrxdelayafterlegacyofdmtx <<16));
}
__INLINE uint8_t macdsp_api1_mac_dsp_agc_api_agc_rx_delay_after_cck_tx_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_AGC_API_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void macdsp_api1_mac_dsp_agc_api_agc_rx_delay_after_cck_tx_setf(uint8_t agcrxdelayafterccktx)
{
	ASSERT_ERR((((uint32_t)agcrxdelayafterccktx << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_DSP_AGC_API_ADDR, (REG_PL_RD(MACDSP_API1_MAC_DSP_AGC_API_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)agcrxdelayafterccktx <<8));
}
__INLINE uint8_t macdsp_api1_mac_dsp_agc_api_agc_rx_delay_addr_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_DSP_AGC_API_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void macdsp_api1_mac_dsp_agc_api_agc_rx_delay_addr_offset_setf(uint8_t agcrxdelayaddroffset)
{
	ASSERT_ERR((((uint32_t)agcrxdelayaddroffset << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_DSP_AGC_API_ADDR, (REG_PL_RD(MACDSP_API1_MAC_DSP_AGC_API_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)agcrxdelayaddroffset <<0));
}

/**
 * @brief ANT_SELECT register definition
 *  ANT_SELECT register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 ant_select_default_rx     0x0
 *    15:08 ant_select_reserved0      0x0
 *    07:00 ant_select_en             0x0
 * </pre>
 */
#define MACDSP_API1_ANT_SELECT_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000001C)
#define MACDSP_API1_ANT_SELECT_OFFSET      0x0000001C
#define MACDSP_API1_ANT_SELECT_INDEX       0x00000007
#define MACDSP_API1_ANT_SELECT_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_ant_select_get(void)
{
	return REG_PL_RD(MACDSP_API1_ANT_SELECT_ADDR);
}

__INLINE void macdsp_api1_ant_select_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_ANT_SELECT_ADDR, value);
}

// field definitions
#define MACDSP_API1_ANT_SELECT_ANT_SELECT_DEFAULT_RX_MASK    ((uint32_t)0xFFFF0000)
#define MACDSP_API1_ANT_SELECT_ANT_SELECT_DEFAULT_RX_LSB    16
#define MACDSP_API1_ANT_SELECT_ANT_SELECT_DEFAULT_RX_WIDTH    ((uint32_t)0x00000010)
#define MACDSP_API1_ANT_SELECT_ANT_SELECT_RESERVED_0_MASK    ((uint32_t)0x0000FF00)
#define MACDSP_API1_ANT_SELECT_ANT_SELECT_RESERVED_0_LSB    8
#define MACDSP_API1_ANT_SELECT_ANT_SELECT_RESERVED_0_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_ANT_SELECT_ANT_SELECT_EN_MASK    ((uint32_t)0x000000FF)
#define MACDSP_API1_ANT_SELECT_ANT_SELECT_EN_LSB    0
#define MACDSP_API1_ANT_SELECT_ANT_SELECT_EN_WIDTH    ((uint32_t)0x00000008)

#define MACDSP_API1_ANT_SELECT_ANT_SELECT_DEFAULT_RX_RST    0x0
#define MACDSP_API1_ANT_SELECT_ANT_SELECT_RESERVED_0_RST    0x0
#define MACDSP_API1_ANT_SELECT_ANT_SELECT_EN_RST    0x0

__INLINE void macdsp_api1_ant_select_pack(uint16_t ant_select_default_rx, uint8_t ant_select_reserved0, uint8_t ant_select_en)
{
	ASSERT_ERR((((uint32_t)ant_select_default_rx << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)ant_select_reserved0 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)ant_select_en << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_ANT_SELECT_ADDR,  ((uint32_t)ant_select_default_rx << 16) |((uint32_t)ant_select_reserved0 << 8) |((uint32_t)ant_select_en << 0));
}

__INLINE void macdsp_api1_ant_select_unpack(uint16_t* ant_select_default_rx, uint8_t* ant_select_reserved0, uint8_t* ant_select_en)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_ANT_SELECT_ADDR);

	*ant_select_default_rx = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*ant_select_reserved0 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*ant_select_en = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint16_t macdsp_api1_ant_select_ant_select_default_rx_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_ANT_SELECT_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void macdsp_api1_ant_select_ant_select_default_rx_setf(uint16_t antselectdefaultrx)
{
	ASSERT_ERR((((uint32_t)antselectdefaultrx << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MACDSP_API1_ANT_SELECT_ADDR, (REG_PL_RD(MACDSP_API1_ANT_SELECT_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)antselectdefaultrx <<16));
}
__INLINE uint8_t macdsp_api1_ant_select_ant_select_reserved_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_ANT_SELECT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void macdsp_api1_ant_select_ant_select_reserved_0_setf(uint8_t antselectreserved0)
{
	ASSERT_ERR((((uint32_t)antselectreserved0 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(MACDSP_API1_ANT_SELECT_ADDR, (REG_PL_RD(MACDSP_API1_ANT_SELECT_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)antselectreserved0 <<8));
}
__INLINE uint8_t macdsp_api1_ant_select_ant_select_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_ANT_SELECT_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void macdsp_api1_ant_select_ant_select_en_setf(uint8_t antselecten)
{
	ASSERT_ERR((((uint32_t)antselecten << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_ANT_SELECT_ADDR, (REG_PL_RD(MACDSP_API1_ANT_SELECT_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)antselecten <<0));
}

/**
 * @brief DYNAMIC_TX_IQ_COMMAND register definition
 *  Dynamic_Tx_IQ_command register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:04 Dynamic_Tx_IQ_reserved0   0x0
 *    03:00 Dynamic_Tx_IQ_command     0x0
 * </pre>
 */
#define MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000020)
#define MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_OFFSET      0x00000020
#define MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_INDEX       0x00000008
#define MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_dynamic_tx_iq_command_get(void)
{
	return REG_PL_RD(MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_ADDR);
}

__INLINE void macdsp_api1_dynamic_tx_iq_command_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_ADDR, value);
}

// field definitions
#define MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_DYNAMIC_TX_IQ_RESERVED_0_MASK    ((uint32_t)0xFFFFFFF0)
#define MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_DYNAMIC_TX_IQ_RESERVED_0_LSB    4
#define MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_DYNAMIC_TX_IQ_RESERVED_0_WIDTH    ((uint32_t)0x0000001C)
#define MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_DYNAMIC_TX_IQ_COMMAND_MASK    ((uint32_t)0x0000000F)
#define MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_DYNAMIC_TX_IQ_COMMAND_LSB    0
#define MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_DYNAMIC_TX_IQ_COMMAND_WIDTH    ((uint32_t)0x00000004)

#define MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_DYNAMIC_TX_IQ_RESERVED_0_RST    0x0
#define MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_DYNAMIC_TX_IQ_COMMAND_RST    0x0

__INLINE void macdsp_api1_dynamic_tx_iq_command_pack(uint32_t dynamic_tx_iq_reserved0, uint8_t dynamic_tx_iq_command)
{
	ASSERT_ERR((((uint32_t)dynamic_tx_iq_reserved0 << 4) & ~((uint32_t)0xFFFFFFF0)) == 0);
	ASSERT_ERR((((uint32_t)dynamic_tx_iq_command << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_ADDR,  ((uint32_t)dynamic_tx_iq_reserved0 << 4) |((uint32_t)dynamic_tx_iq_command << 0));
}

__INLINE void macdsp_api1_dynamic_tx_iq_command_unpack(uint32_t* dynamic_tx_iq_reserved0, uint8_t* dynamic_tx_iq_command)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_ADDR);

	*dynamic_tx_iq_reserved0 = (localVal & ((uint32_t)0xFFFFFFF0)) >>  4;
	*dynamic_tx_iq_command = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint32_t macdsp_api1_dynamic_tx_iq_command_dynamic_tx_iq_reserved_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0xFFFFFFF0)) >> 4);
}
__INLINE void macdsp_api1_dynamic_tx_iq_command_dynamic_tx_iq_reserved_0_setf(uint32_t dynamictxiqreserved0)
{
	ASSERT_ERR((((uint32_t)dynamictxiqreserved0 << 4) & ~((uint32_t)0xFFFFFFF0)) == 0);
	REG_PL_WR(MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_ADDR, (REG_PL_RD(MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_ADDR) & ~((uint32_t)0xFFFFFFF0)) | ((uint32_t)dynamictxiqreserved0 <<4));
}
__INLINE uint8_t macdsp_api1_dynamic_tx_iq_command_dynamic_tx_iq_command_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void macdsp_api1_dynamic_tx_iq_command_dynamic_tx_iq_command_setf(uint8_t dynamictxiqcommand)
{
	ASSERT_ERR((((uint32_t)dynamictxiqcommand << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_ADDR, (REG_PL_RD(MACDSP_API1_DYNAMIC_TX_IQ_COMMAND_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)dynamictxiqcommand <<0));
}

/**
 * @brief CCA_CTRL register definition
 *  Mirror of RIU register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RWNXAGCCCACTRL            0x0
 * </pre>
 */
#define MACDSP_API1_CCA_CTRL_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000024)
#define MACDSP_API1_CCA_CTRL_OFFSET      0x00000024
#define MACDSP_API1_CCA_CTRL_INDEX       0x00000009
#define MACDSP_API1_CCA_CTRL_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_cca_ctrl_get(void)
{
	return REG_PL_RD(MACDSP_API1_CCA_CTRL_ADDR);
}

__INLINE void macdsp_api1_cca_ctrl_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_CCA_CTRL_ADDR, value);
}

// field definitions
#define MACDSP_API1_CCA_CTRL_RWNXAGCCCACTRL_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_CCA_CTRL_RWNXAGCCCACTRL_LSB    0
#define MACDSP_API1_CCA_CTRL_RWNXAGCCCACTRL_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_CCA_CTRL_RWNXAGCCCACTRL_RST    0x0

__INLINE uint32_t macdsp_api1_cca_ctrl_rwnxagcccactrl_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CCA_CTRL_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_cca_ctrl_rwnxagcccactrl_setf(uint32_t rwnxagcccactrl)
{
	ASSERT_ERR((((uint32_t)rwnxagcccactrl << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_CCA_CTRL_ADDR, (uint32_t)rwnxagcccactrl << 0);
}

/**
 * @brief CCA_CTRL_2 register definition
 *  Mirror of RIU register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RWNXAGCCCACTRL2           0x0
 * </pre>
 */
#define MACDSP_API1_CCA_CTRL_2_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000028)
#define MACDSP_API1_CCA_CTRL_2_OFFSET      0x00000028
#define MACDSP_API1_CCA_CTRL_2_INDEX       0x0000000A
#define MACDSP_API1_CCA_CTRL_2_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_cca_ctrl_2_get(void)
{
	return REG_PL_RD(MACDSP_API1_CCA_CTRL_2_ADDR);
}

__INLINE void macdsp_api1_cca_ctrl_2_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_CCA_CTRL_2_ADDR, value);
}

// field definitions
#define MACDSP_API1_CCA_CTRL_2_RWNXAGCCCACTRL_2_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_CCA_CTRL_2_RWNXAGCCCACTRL_2_LSB    0
#define MACDSP_API1_CCA_CTRL_2_RWNXAGCCCACTRL_2_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_CCA_CTRL_2_RWNXAGCCCACTRL_2_RST    0x0

__INLINE uint32_t macdsp_api1_cca_ctrl_2_rwnxagcccactrl_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CCA_CTRL_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_cca_ctrl_2_rwnxagcccactrl_2_setf(uint32_t rwnxagcccactrl2)
{
	ASSERT_ERR((((uint32_t)rwnxagcccactrl2 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_CCA_CTRL_2_ADDR, (uint32_t)rwnxagcccactrl2 << 0);
}

/**
 * @brief ACTIVE_TX_CHAINS register definition
 *  ACTIVE_TX_CHAINS register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    21:16 cck                       0x0
 *    13:08 he                        0x0
 *    05:00 non_he_ofdm               0x0
 * </pre>
 */
#define MACDSP_API1_ACTIVE_TX_CHAINS_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000002C)
#define MACDSP_API1_ACTIVE_TX_CHAINS_OFFSET      0x0000002C
#define MACDSP_API1_ACTIVE_TX_CHAINS_INDEX       0x0000000B
#define MACDSP_API1_ACTIVE_TX_CHAINS_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_active_tx_chains_get(void)
{
	return REG_PL_RD(MACDSP_API1_ACTIVE_TX_CHAINS_ADDR);
}

__INLINE void macdsp_api1_active_tx_chains_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_ACTIVE_TX_CHAINS_ADDR, value);
}

// field definitions
#define MACDSP_API1_ACTIVE_TX_CHAINS_CCK_MASK    ((uint32_t)0x003F0000)
#define MACDSP_API1_ACTIVE_TX_CHAINS_CCK_LSB    16
#define MACDSP_API1_ACTIVE_TX_CHAINS_CCK_WIDTH    ((uint32_t)0x00000006)
#define MACDSP_API1_ACTIVE_TX_CHAINS_HE_MASK    ((uint32_t)0x00003F00)
#define MACDSP_API1_ACTIVE_TX_CHAINS_HE_LSB    8
#define MACDSP_API1_ACTIVE_TX_CHAINS_HE_WIDTH    ((uint32_t)0x00000006)
#define MACDSP_API1_ACTIVE_TX_CHAINS_NON_HE_OFDM_MASK    ((uint32_t)0x0000003F)
#define MACDSP_API1_ACTIVE_TX_CHAINS_NON_HE_OFDM_LSB    0
#define MACDSP_API1_ACTIVE_TX_CHAINS_NON_HE_OFDM_WIDTH    ((uint32_t)0x00000006)

#define MACDSP_API1_ACTIVE_TX_CHAINS_CCK_RST    0x0
#define MACDSP_API1_ACTIVE_TX_CHAINS_HE_RST    0x0
#define MACDSP_API1_ACTIVE_TX_CHAINS_NON_HE_OFDM_RST    0x0

__INLINE void macdsp_api1_active_tx_chains_pack(uint8_t cck, uint8_t he, uint8_t non_he_ofdm)
{
	ASSERT_ERR((((uint32_t)cck << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)he << 8) & ~((uint32_t)0x00003F00)) == 0);
	ASSERT_ERR((((uint32_t)non_he_ofdm << 0) & ~((uint32_t)0x0000003F)) == 0);
	REG_PL_WR(MACDSP_API1_ACTIVE_TX_CHAINS_ADDR,  ((uint32_t)cck << 16) |((uint32_t)he << 8) |((uint32_t)non_he_ofdm << 0));
}

__INLINE void macdsp_api1_active_tx_chains_unpack(uint8_t* cck, uint8_t* he, uint8_t* non_he_ofdm)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_ACTIVE_TX_CHAINS_ADDR);

	*cck = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*he = (localVal & ((uint32_t)0x00003F00)) >>  8;
	*non_he_ofdm = (localVal & ((uint32_t)0x0000003F)) >>  0;
}

__INLINE uint8_t macdsp_api1_active_tx_chains_cck_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_ACTIVE_TX_CHAINS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void macdsp_api1_active_tx_chains_cck_setf(uint8_t cck)
{
	ASSERT_ERR((((uint32_t)cck << 16) & ~((uint32_t)0x003F0000)) == 0);
	REG_PL_WR(MACDSP_API1_ACTIVE_TX_CHAINS_ADDR, (REG_PL_RD(MACDSP_API1_ACTIVE_TX_CHAINS_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)cck <<16));
}
__INLINE uint8_t macdsp_api1_active_tx_chains_he_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_ACTIVE_TX_CHAINS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003F00)) >> 8);
}
__INLINE void macdsp_api1_active_tx_chains_he_setf(uint8_t he)
{
	ASSERT_ERR((((uint32_t)he << 8) & ~((uint32_t)0x00003F00)) == 0);
	REG_PL_WR(MACDSP_API1_ACTIVE_TX_CHAINS_ADDR, (REG_PL_RD(MACDSP_API1_ACTIVE_TX_CHAINS_ADDR) & ~((uint32_t)0x00003F00)) | ((uint32_t)he <<8));
}
__INLINE uint8_t macdsp_api1_active_tx_chains_non_he_ofdm_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_ACTIVE_TX_CHAINS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000003F)) >> 0);
}
__INLINE void macdsp_api1_active_tx_chains_non_he_ofdm_setf(uint8_t nonheofdm)
{
	ASSERT_ERR((((uint32_t)nonheofdm << 0) & ~((uint32_t)0x0000003F)) == 0);
	REG_PL_WR(MACDSP_API1_ACTIVE_TX_CHAINS_ADDR, (REG_PL_RD(MACDSP_API1_ACTIVE_TX_CHAINS_ADDR) & ~((uint32_t)0x0000003F)) | ((uint32_t)nonheofdm <<0));
}

/**
 * @brief RIU_AGC_EVENT_4 register definition
 *  RIU_AGC_EVENT_4 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RIU_agc_event_4_register  0x0
 * </pre>
 */
#define MACDSP_API1_RIU_AGC_EVENT_4_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000030)
#define MACDSP_API1_RIU_AGC_EVENT_4_OFFSET      0x00000030
#define MACDSP_API1_RIU_AGC_EVENT_4_INDEX       0x0000000C
#define MACDSP_API1_RIU_AGC_EVENT_4_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_riu_agc_event_4_get(void)
{
	return REG_PL_RD(MACDSP_API1_RIU_AGC_EVENT_4_ADDR);
}

__INLINE void macdsp_api1_riu_agc_event_4_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RIU_AGC_EVENT_4_ADDR, value);
}

// field definitions
#define MACDSP_API1_RIU_AGC_EVENT_4_RIU_AGC_EVENT_4_REGISTER_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_RIU_AGC_EVENT_4_RIU_AGC_EVENT_4_REGISTER_LSB    0
#define MACDSP_API1_RIU_AGC_EVENT_4_RIU_AGC_EVENT_4_REGISTER_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_RIU_AGC_EVENT_4_RIU_AGC_EVENT_4_REGISTER_RST    0x0

__INLINE uint32_t macdsp_api1_riu_agc_event_4_riu_agc_event_4_register_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RIU_AGC_EVENT_4_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_riu_agc_event_4_riu_agc_event_4_register_setf(uint32_t riuagcevent4register)
{
	ASSERT_ERR((((uint32_t)riuagcevent4register << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RIU_AGC_EVENT_4_ADDR, (uint32_t)riuagcevent4register << 0);
}

/**
 * @brief MAC_0_TO_MAC_1_FRC_DELTA register definition
 *  MAC0_TO_MAC1_FRC_DELTA  register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 frc_delta                 0x0
 * </pre>
 */
#define MACDSP_API1_MAC_0_TO_MAC_1_FRC_DELTA_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000034)
#define MACDSP_API1_MAC_0_TO_MAC_1_FRC_DELTA_OFFSET      0x00000034
#define MACDSP_API1_MAC_0_TO_MAC_1_FRC_DELTA_INDEX       0x0000000D
#define MACDSP_API1_MAC_0_TO_MAC_1_FRC_DELTA_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_mac_0_to_mac_1_frc_delta_get(void)
{
	return REG_PL_RD(MACDSP_API1_MAC_0_TO_MAC_1_FRC_DELTA_ADDR);
}

__INLINE void macdsp_api1_mac_0_to_mac_1_frc_delta_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_MAC_0_TO_MAC_1_FRC_DELTA_ADDR, value);
}

// field definitions
#define MACDSP_API1_MAC_0_TO_MAC_1_FRC_DELTA_FRC_DELTA_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_MAC_0_TO_MAC_1_FRC_DELTA_FRC_DELTA_LSB    0
#define MACDSP_API1_MAC_0_TO_MAC_1_FRC_DELTA_FRC_DELTA_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_MAC_0_TO_MAC_1_FRC_DELTA_FRC_DELTA_RST    0x0

__INLINE uint32_t macdsp_api1_mac_0_to_mac_1_frc_delta_frc_delta_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_0_TO_MAC_1_FRC_DELTA_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_mac_0_to_mac_1_frc_delta_frc_delta_setf(uint32_t frcdelta)
{
	ASSERT_ERR((((uint32_t)frcdelta << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_0_TO_MAC_1_FRC_DELTA_ADDR, (uint32_t)frcdelta << 0);
}

/**
 * @brief MAX_NC register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 max_nc_reserved0          0x0
 *    15:08 max_nc_HE                 0x0
 *    07:00 max_nc_VHT                0x0
 * </pre>
 */
#define MACDSP_API1_MAX_NC_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000038)
#define MACDSP_API1_MAX_NC_OFFSET      0x00000038
#define MACDSP_API1_MAX_NC_INDEX       0x0000000E
#define MACDSP_API1_MAX_NC_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_max_nc_get(void)
{
	return REG_PL_RD(MACDSP_API1_MAX_NC_ADDR);
}

__INLINE void macdsp_api1_max_nc_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_MAX_NC_ADDR, value);
}

// field definitions
#define MACDSP_API1_MAX_NC_MAX_NC_RESERVED_0_MASK    ((uint32_t)0xFFFF0000)
#define MACDSP_API1_MAX_NC_MAX_NC_RESERVED_0_LSB    16
#define MACDSP_API1_MAX_NC_MAX_NC_RESERVED_0_WIDTH    ((uint32_t)0x00000010)
#define MACDSP_API1_MAX_NC_MAX_NC_HE_MASK    ((uint32_t)0x0000FF00)
#define MACDSP_API1_MAX_NC_MAX_NC_HE_LSB    8
#define MACDSP_API1_MAX_NC_MAX_NC_HE_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_MAX_NC_MAX_NC_VHT_MASK    ((uint32_t)0x000000FF)
#define MACDSP_API1_MAX_NC_MAX_NC_VHT_LSB    0
#define MACDSP_API1_MAX_NC_MAX_NC_VHT_WIDTH    ((uint32_t)0x00000008)

#define MACDSP_API1_MAX_NC_MAX_NC_RESERVED_0_RST    0x0
#define MACDSP_API1_MAX_NC_MAX_NC_HE_RST    0x0
#define MACDSP_API1_MAX_NC_MAX_NC_VHT_RST    0x0

__INLINE void macdsp_api1_max_nc_pack(uint16_t max_nc_reserved0, uint8_t max_nc_he, uint8_t max_nc_vht)
{
	ASSERT_ERR((((uint32_t)max_nc_reserved0 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)max_nc_he << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)max_nc_vht << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_MAX_NC_ADDR,  ((uint32_t)max_nc_reserved0 << 16) |((uint32_t)max_nc_he << 8) |((uint32_t)max_nc_vht << 0));
}

__INLINE void macdsp_api1_max_nc_unpack(uint16_t* max_nc_reserved0, uint8_t* max_nc_he, uint8_t* max_nc_vht)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAX_NC_ADDR);

	*max_nc_reserved0 = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*max_nc_he = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*max_nc_vht = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint16_t macdsp_api1_max_nc_max_nc_reserved_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAX_NC_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void macdsp_api1_max_nc_max_nc_reserved_0_setf(uint16_t maxncreserved0)
{
	ASSERT_ERR((((uint32_t)maxncreserved0 << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MACDSP_API1_MAX_NC_ADDR, (REG_PL_RD(MACDSP_API1_MAX_NC_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)maxncreserved0 <<16));
}
__INLINE uint8_t macdsp_api1_max_nc_max_nc_he_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAX_NC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void macdsp_api1_max_nc_max_nc_he_setf(uint8_t maxnche)
{
	ASSERT_ERR((((uint32_t)maxnche << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(MACDSP_API1_MAX_NC_ADDR, (REG_PL_RD(MACDSP_API1_MAX_NC_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)maxnche <<8));
}
__INLINE uint8_t macdsp_api1_max_nc_max_nc_vht_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAX_NC_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void macdsp_api1_max_nc_max_nc_vht_setf(uint8_t maxncvht)
{
	ASSERT_ERR((((uint32_t)maxncvht << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_MAX_NC_ADDR, (REG_PL_RD(MACDSP_API1_MAX_NC_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)maxncvht <<0));
}

/**
 * @brief ASSERT_INFO register definition
 *  explains the assert reason register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 assert_info               0x0
 * </pre>
 */
#define MACDSP_API1_ASSERT_INFO_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000003C)
#define MACDSP_API1_ASSERT_INFO_OFFSET      0x0000003C
#define MACDSP_API1_ASSERT_INFO_INDEX       0x0000000F
#define MACDSP_API1_ASSERT_INFO_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_assert_info_get(void)
{
	return REG_PL_RD(MACDSP_API1_ASSERT_INFO_ADDR);
}

__INLINE void macdsp_api1_assert_info_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_ASSERT_INFO_ADDR, value);
}

// field definitions
#define MACDSP_API1_ASSERT_INFO_ASSERT_INFO_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_ASSERT_INFO_ASSERT_INFO_LSB    0
#define MACDSP_API1_ASSERT_INFO_ASSERT_INFO_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_ASSERT_INFO_ASSERT_INFO_RST    0x0

__INLINE uint32_t macdsp_api1_assert_info_assert_info_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_ASSERT_INFO_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_assert_info_assert_info_setf(uint32_t assertinfo)
{
	ASSERT_ERR((((uint32_t)assertinfo << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_ASSERT_INFO_ADDR, (uint32_t)assertinfo << 0);
}

/**
 * @brief TOD_HIGH register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 tod_h                     0x0
 * </pre>
 */
#define MACDSP_API1_TOD_HIGH_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000040)
#define MACDSP_API1_TOD_HIGH_OFFSET      0x00000040
#define MACDSP_API1_TOD_HIGH_INDEX       0x00000010
#define MACDSP_API1_TOD_HIGH_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tod_high_get(void)
{
	return REG_PL_RD(MACDSP_API1_TOD_HIGH_ADDR);
}

__INLINE void macdsp_api1_tod_high_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TOD_HIGH_ADDR, value);
}

// field definitions
#define MACDSP_API1_TOD_HIGH_TOD_H_MASK     ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_TOD_HIGH_TOD_H_LSB      0
#define MACDSP_API1_TOD_HIGH_TOD_H_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_TOD_HIGH_TOD_H_RST      0x0

__INLINE uint32_t macdsp_api1_tod_high_tod_h_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TOD_HIGH_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_tod_high_tod_h_setf(uint32_t todh)
{
	ASSERT_ERR((((uint32_t)todh << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TOD_HIGH_ADDR, (uint32_t)todh << 0);
}

/**
 * @brief TOD_LOW register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 tod_l                     0x0
 * </pre>
 */
#define MACDSP_API1_TOD_LOW_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000044)
#define MACDSP_API1_TOD_LOW_OFFSET      0x00000044
#define MACDSP_API1_TOD_LOW_INDEX       0x00000011
#define MACDSP_API1_TOD_LOW_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tod_low_get(void)
{
	return REG_PL_RD(MACDSP_API1_TOD_LOW_ADDR);
}

__INLINE void macdsp_api1_tod_low_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TOD_LOW_ADDR, value);
}

// field definitions
#define MACDSP_API1_TOD_LOW_TOD_L_MASK      ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_TOD_LOW_TOD_L_LSB       0
#define MACDSP_API1_TOD_LOW_TOD_L_WIDTH     ((uint32_t)0x00000020)

#define MACDSP_API1_TOD_LOW_TOD_L_RST       0x0

__INLINE uint32_t macdsp_api1_tod_low_tod_l_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TOD_LOW_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_tod_low_tod_l_setf(uint32_t todl)
{
	ASSERT_ERR((((uint32_t)todl << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TOD_LOW_ADDR, (uint32_t)todl << 0);
}

/**
 * @brief TOA_HIGH register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 tod_h                     0x0
 * </pre>
 */
#define MACDSP_API1_TOA_HIGH_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000048)
#define MACDSP_API1_TOA_HIGH_OFFSET      0x00000048
#define MACDSP_API1_TOA_HIGH_INDEX       0x00000012
#define MACDSP_API1_TOA_HIGH_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_toa_high_get(void)
{
	return REG_PL_RD(MACDSP_API1_TOA_HIGH_ADDR);
}

__INLINE void macdsp_api1_toa_high_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TOA_HIGH_ADDR, value);
}

// field definitions
#define MACDSP_API1_TOA_HIGH_TOD_H_MASK     ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_TOA_HIGH_TOD_H_LSB      0
#define MACDSP_API1_TOA_HIGH_TOD_H_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_TOA_HIGH_TOD_H_RST      0x0

__INLINE uint32_t macdsp_api1_toa_high_tod_h_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TOA_HIGH_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_toa_high_tod_h_setf(uint32_t todh)
{
	ASSERT_ERR((((uint32_t)todh << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TOA_HIGH_ADDR, (uint32_t)todh << 0);
}

/**
 * @brief TOA_LOW register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 toa_l                     0x0
 * </pre>
 */
#define MACDSP_API1_TOA_LOW_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000004C)
#define MACDSP_API1_TOA_LOW_OFFSET      0x0000004C
#define MACDSP_API1_TOA_LOW_INDEX       0x00000013
#define MACDSP_API1_TOA_LOW_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_toa_low_get(void)
{
	return REG_PL_RD(MACDSP_API1_TOA_LOW_ADDR);
}

__INLINE void macdsp_api1_toa_low_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TOA_LOW_ADDR, value);
}

// field definitions
#define MACDSP_API1_TOA_LOW_TOA_L_MASK      ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_TOA_LOW_TOA_L_LSB       0
#define MACDSP_API1_TOA_LOW_TOA_L_WIDTH     ((uint32_t)0x00000020)

#define MACDSP_API1_TOA_LOW_TOA_L_RST       0x0

__INLINE uint32_t macdsp_api1_toa_low_toa_l_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TOA_LOW_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_toa_low_toa_l_setf(uint32_t toal)
{
	ASSERT_ERR((((uint32_t)toal << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TOA_LOW_ADDR, (uint32_t)toal << 0);
}

/**
 * @brief TOD_ERR_SN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:20 tod_err_sn_Reserved0      0x0
 *    19:16 tod_sn                    0x0
 *    15:00 tod_err                   0x0
 * </pre>
 */
#define MACDSP_API1_TOD_ERR_SN_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000050)
#define MACDSP_API1_TOD_ERR_SN_OFFSET      0x00000050
#define MACDSP_API1_TOD_ERR_SN_INDEX       0x00000014
#define MACDSP_API1_TOD_ERR_SN_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tod_err_sn_get(void)
{
	return REG_PL_RD(MACDSP_API1_TOD_ERR_SN_ADDR);
}

__INLINE void macdsp_api1_tod_err_sn_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TOD_ERR_SN_ADDR, value);
}

// field definitions
#define MACDSP_API1_TOD_ERR_SN_TOD_ERR_SN_RESERVED_0_MASK    ((uint32_t)0xFFF00000)
#define MACDSP_API1_TOD_ERR_SN_TOD_ERR_SN_RESERVED_0_LSB    20
#define MACDSP_API1_TOD_ERR_SN_TOD_ERR_SN_RESERVED_0_WIDTH    ((uint32_t)0x0000000C)
#define MACDSP_API1_TOD_ERR_SN_TOD_SN_MASK    ((uint32_t)0x000F0000)
#define MACDSP_API1_TOD_ERR_SN_TOD_SN_LSB    16
#define MACDSP_API1_TOD_ERR_SN_TOD_SN_WIDTH    ((uint32_t)0x00000004)
#define MACDSP_API1_TOD_ERR_SN_TOD_ERR_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_TOD_ERR_SN_TOD_ERR_LSB    0
#define MACDSP_API1_TOD_ERR_SN_TOD_ERR_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_TOD_ERR_SN_TOD_ERR_SN_RESERVED_0_RST    0x0
#define MACDSP_API1_TOD_ERR_SN_TOD_SN_RST    0x0
#define MACDSP_API1_TOD_ERR_SN_TOD_ERR_RST    0x0

__INLINE void macdsp_api1_tod_err_sn_pack(uint16_t tod_err_sn_reserved0, uint8_t tod_sn, uint16_t tod_err)
{
	ASSERT_ERR((((uint32_t)tod_err_sn_reserved0 << 20) & ~((uint32_t)0xFFF00000)) == 0);
	ASSERT_ERR((((uint32_t)tod_sn << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)tod_err << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TOD_ERR_SN_ADDR,  ((uint32_t)tod_err_sn_reserved0 << 20) |((uint32_t)tod_sn << 16) |((uint32_t)tod_err << 0));
}

__INLINE void macdsp_api1_tod_err_sn_unpack(uint16_t* tod_err_sn_reserved0, uint8_t* tod_sn, uint16_t* tod_err)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TOD_ERR_SN_ADDR);

	*tod_err_sn_reserved0 = (localVal & ((uint32_t)0xFFF00000)) >>  20;
	*tod_sn = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*tod_err = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t macdsp_api1_tod_err_sn_tod_err_sn_reserved_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TOD_ERR_SN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFF00000)) >> 20);
}
__INLINE void macdsp_api1_tod_err_sn_tod_err_sn_reserved_0_setf(uint16_t toderrsnreserved0)
{
	ASSERT_ERR((((uint32_t)toderrsnreserved0 << 20) & ~((uint32_t)0xFFF00000)) == 0);
	REG_PL_WR(MACDSP_API1_TOD_ERR_SN_ADDR, (REG_PL_RD(MACDSP_API1_TOD_ERR_SN_ADDR) & ~((uint32_t)0xFFF00000)) | ((uint32_t)toderrsnreserved0 <<20));
}
__INLINE uint8_t macdsp_api1_tod_err_sn_tod_sn_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TOD_ERR_SN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void macdsp_api1_tod_err_sn_tod_sn_setf(uint8_t todsn)
{
	ASSERT_ERR((((uint32_t)todsn << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(MACDSP_API1_TOD_ERR_SN_ADDR, (REG_PL_RD(MACDSP_API1_TOD_ERR_SN_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)todsn <<16));
}
__INLINE uint16_t macdsp_api1_tod_err_sn_tod_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TOD_ERR_SN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void macdsp_api1_tod_err_sn_tod_err_setf(uint16_t toderr)
{
	ASSERT_ERR((((uint32_t)toderr << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TOD_ERR_SN_ADDR, (REG_PL_RD(MACDSP_API1_TOD_ERR_SN_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)toderr <<0));
}

/**
 * @brief TOA_ERR_SN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:20 toa_err                   0x0
 *    19:16 toa_sn                    0x0
 *    15:00 toa_err_sn_Reserved0      0x0
 * </pre>
 */
#define MACDSP_API1_TOA_ERR_SN_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000054)
#define MACDSP_API1_TOA_ERR_SN_OFFSET      0x00000054
#define MACDSP_API1_TOA_ERR_SN_INDEX       0x00000015
#define MACDSP_API1_TOA_ERR_SN_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_toa_err_sn_get(void)
{
	return REG_PL_RD(MACDSP_API1_TOA_ERR_SN_ADDR);
}

__INLINE void macdsp_api1_toa_err_sn_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TOA_ERR_SN_ADDR, value);
}

// field definitions
#define MACDSP_API1_TOA_ERR_SN_TOA_ERR_MASK    ((uint32_t)0xFFF00000)
#define MACDSP_API1_TOA_ERR_SN_TOA_ERR_LSB    20
#define MACDSP_API1_TOA_ERR_SN_TOA_ERR_WIDTH    ((uint32_t)0x0000000C)
#define MACDSP_API1_TOA_ERR_SN_TOA_SN_MASK    ((uint32_t)0x000F0000)
#define MACDSP_API1_TOA_ERR_SN_TOA_SN_LSB    16
#define MACDSP_API1_TOA_ERR_SN_TOA_SN_WIDTH    ((uint32_t)0x00000004)
#define MACDSP_API1_TOA_ERR_SN_TOA_ERR_SN_RESERVED_0_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_TOA_ERR_SN_TOA_ERR_SN_RESERVED_0_LSB    0
#define MACDSP_API1_TOA_ERR_SN_TOA_ERR_SN_RESERVED_0_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_TOA_ERR_SN_TOA_ERR_RST    0x0
#define MACDSP_API1_TOA_ERR_SN_TOA_SN_RST    0x0
#define MACDSP_API1_TOA_ERR_SN_TOA_ERR_SN_RESERVED_0_RST    0x0

__INLINE void macdsp_api1_toa_err_sn_pack(uint16_t toa_err, uint8_t toa_sn, uint16_t toa_err_sn_reserved0)
{
	ASSERT_ERR((((uint32_t)toa_err << 20) & ~((uint32_t)0xFFF00000)) == 0);
	ASSERT_ERR((((uint32_t)toa_sn << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)toa_err_sn_reserved0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TOA_ERR_SN_ADDR,  ((uint32_t)toa_err << 20) |((uint32_t)toa_sn << 16) |((uint32_t)toa_err_sn_reserved0 << 0));
}

__INLINE void macdsp_api1_toa_err_sn_unpack(uint16_t* toa_err, uint8_t* toa_sn, uint16_t* toa_err_sn_reserved0)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TOA_ERR_SN_ADDR);

	*toa_err = (localVal & ((uint32_t)0xFFF00000)) >>  20;
	*toa_sn = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*toa_err_sn_reserved0 = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t macdsp_api1_toa_err_sn_toa_err_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TOA_ERR_SN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFF00000)) >> 20);
}
__INLINE void macdsp_api1_toa_err_sn_toa_err_setf(uint16_t toaerr)
{
	ASSERT_ERR((((uint32_t)toaerr << 20) & ~((uint32_t)0xFFF00000)) == 0);
	REG_PL_WR(MACDSP_API1_TOA_ERR_SN_ADDR, (REG_PL_RD(MACDSP_API1_TOA_ERR_SN_ADDR) & ~((uint32_t)0xFFF00000)) | ((uint32_t)toaerr <<20));
}
__INLINE uint8_t macdsp_api1_toa_err_sn_toa_sn_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TOA_ERR_SN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void macdsp_api1_toa_err_sn_toa_sn_setf(uint8_t toasn)
{
	ASSERT_ERR((((uint32_t)toasn << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(MACDSP_API1_TOA_ERR_SN_ADDR, (REG_PL_RD(MACDSP_API1_TOA_ERR_SN_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)toasn <<16));
}
__INLINE uint16_t macdsp_api1_toa_err_sn_toa_err_sn_reserved_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TOA_ERR_SN_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void macdsp_api1_toa_err_sn_toa_err_sn_reserved_0_setf(uint16_t toaerrsnreserved0)
{
	ASSERT_ERR((((uint32_t)toaerrsnreserved0 << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TOA_ERR_SN_ADDR, (REG_PL_RD(MACDSP_API1_TOA_ERR_SN_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)toaerrsnreserved0 <<0));
}

/**
 * @brief TRIGGER_TB_PARM register definition
 *  TRIGGER_TB_PARM register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:11 trigger_tb_parm_reserved0 0x0
 *    10    mu_type                   0              
 *    09:08 frame_bw                  0x0
 *    07:00 num_user                  0x0
 * </pre>
 */
#define MACDSP_API1_TRIGGER_TB_PARM_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000058)
#define MACDSP_API1_TRIGGER_TB_PARM_OFFSET      0x00000058
#define MACDSP_API1_TRIGGER_TB_PARM_INDEX       0x00000016
#define MACDSP_API1_TRIGGER_TB_PARM_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_trigger_tb_parm_get(void)
{
	return REG_PL_RD(MACDSP_API1_TRIGGER_TB_PARM_ADDR);
}

__INLINE void macdsp_api1_trigger_tb_parm_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TRIGGER_TB_PARM_ADDR, value);
}

// field definitions
#define MACDSP_API1_TRIGGER_TB_PARM_TRIGGER_TB_PARM_RESERVED_0_MASK    ((uint32_t)0xFFFFF800)
#define MACDSP_API1_TRIGGER_TB_PARM_TRIGGER_TB_PARM_RESERVED_0_LSB    11
#define MACDSP_API1_TRIGGER_TB_PARM_TRIGGER_TB_PARM_RESERVED_0_WIDTH    ((uint32_t)0x00000015)
#define MACDSP_API1_TRIGGER_TB_PARM_MU_TYPE_BIT    ((uint32_t)0x00000400)
#define MACDSP_API1_TRIGGER_TB_PARM_MU_TYPE_POS    10
#define MACDSP_API1_TRIGGER_TB_PARM_FRAME_BW_MASK    ((uint32_t)0x00000300)
#define MACDSP_API1_TRIGGER_TB_PARM_FRAME_BW_LSB    8
#define MACDSP_API1_TRIGGER_TB_PARM_FRAME_BW_WIDTH    ((uint32_t)0x00000002)
#define MACDSP_API1_TRIGGER_TB_PARM_NUM_USER_MASK    ((uint32_t)0x000000FF)
#define MACDSP_API1_TRIGGER_TB_PARM_NUM_USER_LSB    0
#define MACDSP_API1_TRIGGER_TB_PARM_NUM_USER_WIDTH    ((uint32_t)0x00000008)

#define MACDSP_API1_TRIGGER_TB_PARM_TRIGGER_TB_PARM_RESERVED_0_RST    0x0
#define MACDSP_API1_TRIGGER_TB_PARM_MU_TYPE_RST    0x0
#define MACDSP_API1_TRIGGER_TB_PARM_FRAME_BW_RST    0x0
#define MACDSP_API1_TRIGGER_TB_PARM_NUM_USER_RST    0x0

__INLINE void macdsp_api1_trigger_tb_parm_pack(uint32_t trigger_tb_parm_reserved0, uint8_t mu_type, uint8_t frame_bw, uint8_t num_user)
{
	ASSERT_ERR((((uint32_t)trigger_tb_parm_reserved0 << 11) & ~((uint32_t)0xFFFFF800)) == 0);
	ASSERT_ERR((((uint32_t)mu_type << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)frame_bw << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)num_user << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_TRIGGER_TB_PARM_ADDR,  ((uint32_t)trigger_tb_parm_reserved0 << 11) |((uint32_t)mu_type << 10) |((uint32_t)frame_bw << 8) |((uint32_t)num_user << 0));
}

__INLINE void macdsp_api1_trigger_tb_parm_unpack(uint32_t* trigger_tb_parm_reserved0, uint8_t* mu_type, uint8_t* frame_bw, uint8_t* num_user)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TRIGGER_TB_PARM_ADDR);

	*trigger_tb_parm_reserved0 = (localVal & ((uint32_t)0xFFFFF800)) >>  11;
	*mu_type = (localVal & ((uint32_t)0x00000400)) >>  10;
	*frame_bw = (localVal & ((uint32_t)0x00000300)) >>  8;
	*num_user = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint32_t macdsp_api1_trigger_tb_parm_trigger_tb_parm_reserved_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TRIGGER_TB_PARM_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0xFFFFF800)) >> 11);
}
__INLINE void macdsp_api1_trigger_tb_parm_trigger_tb_parm_reserved_0_setf(uint32_t triggertbparmreserved0)
{
	ASSERT_ERR((((uint32_t)triggertbparmreserved0 << 11) & ~((uint32_t)0xFFFFF800)) == 0);
	REG_PL_WR(MACDSP_API1_TRIGGER_TB_PARM_ADDR, (REG_PL_RD(MACDSP_API1_TRIGGER_TB_PARM_ADDR) & ~((uint32_t)0xFFFFF800)) | ((uint32_t)triggertbparmreserved0 <<11));
}
__INLINE uint8_t macdsp_api1_trigger_tb_parm_mu_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TRIGGER_TB_PARM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void macdsp_api1_trigger_tb_parm_mu_type_setf(uint8_t mutype)
{
	ASSERT_ERR((((uint32_t)mutype << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(MACDSP_API1_TRIGGER_TB_PARM_ADDR, (REG_PL_RD(MACDSP_API1_TRIGGER_TB_PARM_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)mutype <<10));
}
__INLINE uint8_t macdsp_api1_trigger_tb_parm_frame_bw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TRIGGER_TB_PARM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void macdsp_api1_trigger_tb_parm_frame_bw_setf(uint8_t framebw)
{
	ASSERT_ERR((((uint32_t)framebw << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(MACDSP_API1_TRIGGER_TB_PARM_ADDR, (REG_PL_RD(MACDSP_API1_TRIGGER_TB_PARM_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)framebw <<8));
}
__INLINE uint8_t macdsp_api1_trigger_tb_parm_num_user_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TRIGGER_TB_PARM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void macdsp_api1_trigger_tb_parm_num_user_setf(uint8_t numuser)
{
	ASSERT_ERR((((uint32_t)numuser << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_TRIGGER_TB_PARM_ADDR, (REG_PL_RD(MACDSP_API1_TRIGGER_TB_PARM_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)numuser <<0));
}

/**
 * @brief PHY_ERROR_REASON register definition
 *  PHY_ERROR_REASON register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:08 Error_details             0x0
 *    07    Auto_response             0              
 *    06:00 Error_reason              0x0
 * </pre>
 */
#define MACDSP_API1_PHY_ERROR_REASON_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000005C)
#define MACDSP_API1_PHY_ERROR_REASON_OFFSET      0x0000005C
#define MACDSP_API1_PHY_ERROR_REASON_INDEX       0x00000017
#define MACDSP_API1_PHY_ERROR_REASON_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_phy_error_reason_get(void)
{
	return REG_PL_RD(MACDSP_API1_PHY_ERROR_REASON_ADDR);
}

__INLINE void macdsp_api1_phy_error_reason_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_PHY_ERROR_REASON_ADDR, value);
}

// field definitions
#define MACDSP_API1_PHY_ERROR_REASON_ERROR_DETAILS_MASK    ((uint32_t)0xFFFFFF00)
#define MACDSP_API1_PHY_ERROR_REASON_ERROR_DETAILS_LSB    8
#define MACDSP_API1_PHY_ERROR_REASON_ERROR_DETAILS_WIDTH    ((uint32_t)0x00000018)
#define MACDSP_API1_PHY_ERROR_REASON_AUTO_RESPONSE_BIT    ((uint32_t)0x00000080)
#define MACDSP_API1_PHY_ERROR_REASON_AUTO_RESPONSE_POS    7
#define MACDSP_API1_PHY_ERROR_REASON_ERROR_REASON_MASK    ((uint32_t)0x0000007F)
#define MACDSP_API1_PHY_ERROR_REASON_ERROR_REASON_LSB    0
#define MACDSP_API1_PHY_ERROR_REASON_ERROR_REASON_WIDTH    ((uint32_t)0x00000007)

#define MACDSP_API1_PHY_ERROR_REASON_ERROR_DETAILS_RST    0x0
#define MACDSP_API1_PHY_ERROR_REASON_AUTO_RESPONSE_RST    0x0
#define MACDSP_API1_PHY_ERROR_REASON_ERROR_REASON_RST    0x0

__INLINE void macdsp_api1_phy_error_reason_pack(uint32_t error_details, uint8_t auto_response, uint8_t error_reason)
{
	ASSERT_ERR((((uint32_t)error_details << 8) & ~((uint32_t)0xFFFFFF00)) == 0);
	ASSERT_ERR((((uint32_t)auto_response << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)error_reason << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(MACDSP_API1_PHY_ERROR_REASON_ADDR,  ((uint32_t)error_details << 8) |((uint32_t)auto_response << 7) |((uint32_t)error_reason << 0));
}

__INLINE void macdsp_api1_phy_error_reason_unpack(uint32_t* error_details, uint8_t* auto_response, uint8_t* error_reason)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_PHY_ERROR_REASON_ADDR);

	*error_details = (localVal & ((uint32_t)0xFFFFFF00)) >>  8;
	*auto_response = (localVal & ((uint32_t)0x00000080)) >>  7;
	*error_reason = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint32_t macdsp_api1_phy_error_reason_error_details_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_PHY_ERROR_REASON_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0xFFFFFF00)) >> 8);
}
__INLINE void macdsp_api1_phy_error_reason_error_details_setf(uint32_t errordetails)
{
	ASSERT_ERR((((uint32_t)errordetails << 8) & ~((uint32_t)0xFFFFFF00)) == 0);
	REG_PL_WR(MACDSP_API1_PHY_ERROR_REASON_ADDR, (REG_PL_RD(MACDSP_API1_PHY_ERROR_REASON_ADDR) & ~((uint32_t)0xFFFFFF00)) | ((uint32_t)errordetails <<8));
}
__INLINE uint8_t macdsp_api1_phy_error_reason_auto_response_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_PHY_ERROR_REASON_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void macdsp_api1_phy_error_reason_auto_response_setf(uint8_t autoresponse)
{
	ASSERT_ERR((((uint32_t)autoresponse << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(MACDSP_API1_PHY_ERROR_REASON_ADDR, (REG_PL_RD(MACDSP_API1_PHY_ERROR_REASON_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)autoresponse <<7));
}
__INLINE uint8_t macdsp_api1_phy_error_reason_error_reason_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_PHY_ERROR_REASON_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}
__INLINE void macdsp_api1_phy_error_reason_error_reason_setf(uint8_t errorreason)
{
	ASSERT_ERR((((uint32_t)errorreason << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(MACDSP_API1_PHY_ERROR_REASON_ADDR, (REG_PL_RD(MACDSP_API1_PHY_ERROR_REASON_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)errorreason <<0));
}

/**
 * @brief VGEN_REQ_PART_1 register definition
 *  Beamformee_V_MATRIX_GEN_REQ_PART_1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 Vgen_Dialog_token         0x0
 *    23:21 Vgen_Reserved             0x0
 *    20    Vgen_CQI                  0              
 *    19:16 Vgen_Grouping             0x0
 *    15:13 Vgen_Codebook_information 0x0
 *    12:10 Vgen_Nc_Index             0x0
 *    09:08 Vgen_Feedback_Type        0x0
 *    07    Vgen_Sounding_Type        0              
 *    06:05 Vgen_Format               0x0
 *    04    Vgen_Request_Valid        0              
 *    03:00 Vgen_Request_sequence_id  0x0
 * </pre>
 */
#define MACDSP_API1_VGEN_REQ_PART_1_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000060)
#define MACDSP_API1_VGEN_REQ_PART_1_OFFSET      0x00000060
#define MACDSP_API1_VGEN_REQ_PART_1_INDEX       0x00000018
#define MACDSP_API1_VGEN_REQ_PART_1_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_vgen_req_part_1_get(void)
{
	return REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR);
}

__INLINE void macdsp_api1_vgen_req_part_1_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_1_ADDR, value);
}

// field definitions
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_DIALOG_TOKEN_MASK    ((uint32_t)0xFF000000)
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_DIALOG_TOKEN_LSB    24
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_DIALOG_TOKEN_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_RESERVED_MASK    ((uint32_t)0x00E00000)
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_RESERVED_LSB    21
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_RESERVED_WIDTH    ((uint32_t)0x00000003)
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_CQI_BIT    ((uint32_t)0x00100000)
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_CQI_POS    20
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_GROUPING_MASK    ((uint32_t)0x000F0000)
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_GROUPING_LSB    16
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_GROUPING_WIDTH    ((uint32_t)0x00000004)
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_CODEBOOK_INFORMATION_MASK    ((uint32_t)0x0000E000)
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_CODEBOOK_INFORMATION_LSB    13
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_CODEBOOK_INFORMATION_WIDTH    ((uint32_t)0x00000003)
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_NC_INDEX_MASK    ((uint32_t)0x00001C00)
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_NC_INDEX_LSB    10
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_NC_INDEX_WIDTH    ((uint32_t)0x00000003)
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_FEEDBACK_TYPE_MASK    ((uint32_t)0x00000300)
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_FEEDBACK_TYPE_LSB    8
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_FEEDBACK_TYPE_WIDTH    ((uint32_t)0x00000002)
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_SOUNDING_TYPE_BIT    ((uint32_t)0x00000080)
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_SOUNDING_TYPE_POS    7
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_FORMAT_MASK    ((uint32_t)0x00000060)
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_FORMAT_LSB    5
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_FORMAT_WIDTH    ((uint32_t)0x00000002)
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_REQUEST_VALID_BIT    ((uint32_t)0x00000010)
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_REQUEST_VALID_POS    4
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_REQUEST_SEQUENCE_ID_MASK    ((uint32_t)0x0000000F)
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_REQUEST_SEQUENCE_ID_LSB    0
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_REQUEST_SEQUENCE_ID_WIDTH    ((uint32_t)0x00000004)

#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_DIALOG_TOKEN_RST    0x0
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_RESERVED_RST    0x0
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_CQI_RST    0x0
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_GROUPING_RST    0x0
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_CODEBOOK_INFORMATION_RST    0x0
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_NC_INDEX_RST    0x0
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_FEEDBACK_TYPE_RST    0x0
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_SOUNDING_TYPE_RST    0x0
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_FORMAT_RST    0x0
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_REQUEST_VALID_RST    0x0
#define MACDSP_API1_VGEN_REQ_PART_1_VGEN_REQUEST_SEQUENCE_ID_RST    0x0

__INLINE void macdsp_api1_vgen_req_part_1_pack(uint8_t vgen_dialog_token, uint8_t vgen_reserved, uint8_t vgen_cqi, uint8_t vgen_grouping, uint8_t vgen_codebook_information, uint8_t vgen_nc_index, uint8_t vgen_feedback_type, uint8_t vgen_sounding_type, uint8_t vgen_format, uint8_t vgen_request_valid, uint8_t vgen_request_sequence_id)
{
	ASSERT_ERR((((uint32_t)vgen_dialog_token << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)vgen_reserved << 21) & ~((uint32_t)0x00E00000)) == 0);
	ASSERT_ERR((((uint32_t)vgen_cqi << 20) & ~((uint32_t)0x00100000)) == 0);
	ASSERT_ERR((((uint32_t)vgen_grouping << 16) & ~((uint32_t)0x000F0000)) == 0);
	ASSERT_ERR((((uint32_t)vgen_codebook_information << 13) & ~((uint32_t)0x0000E000)) == 0);
	ASSERT_ERR((((uint32_t)vgen_nc_index << 10) & ~((uint32_t)0x00001C00)) == 0);
	ASSERT_ERR((((uint32_t)vgen_feedback_type << 8) & ~((uint32_t)0x00000300)) == 0);
	ASSERT_ERR((((uint32_t)vgen_sounding_type << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)vgen_format << 5) & ~((uint32_t)0x00000060)) == 0);
	ASSERT_ERR((((uint32_t)vgen_request_valid << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)vgen_request_sequence_id << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_1_ADDR,  ((uint32_t)vgen_dialog_token << 24) |((uint32_t)vgen_reserved << 21) |((uint32_t)vgen_cqi << 20) |((uint32_t)vgen_grouping << 16) |((uint32_t)vgen_codebook_information << 13) |((uint32_t)vgen_nc_index << 10) |((uint32_t)vgen_feedback_type << 8) |((uint32_t)vgen_sounding_type << 7) |((uint32_t)vgen_format << 5) |((uint32_t)vgen_request_valid << 4) |((uint32_t)vgen_request_sequence_id << 0));
}

__INLINE void macdsp_api1_vgen_req_part_1_unpack(uint8_t* vgen_dialog_token, uint8_t* vgen_reserved, uint8_t* vgen_cqi, uint8_t* vgen_grouping, uint8_t* vgen_codebook_information, uint8_t* vgen_nc_index, uint8_t* vgen_feedback_type, uint8_t* vgen_sounding_type, uint8_t* vgen_format, uint8_t* vgen_request_valid, uint8_t* vgen_request_sequence_id)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR);

	*vgen_dialog_token = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*vgen_reserved = (localVal & ((uint32_t)0x00E00000)) >>  21;
	*vgen_cqi = (localVal & ((uint32_t)0x00100000)) >>  20;
	*vgen_grouping = (localVal & ((uint32_t)0x000F0000)) >>  16;
	*vgen_codebook_information = (localVal & ((uint32_t)0x0000E000)) >>  13;
	*vgen_nc_index = (localVal & ((uint32_t)0x00001C00)) >>  10;
	*vgen_feedback_type = (localVal & ((uint32_t)0x00000300)) >>  8;
	*vgen_sounding_type = (localVal & ((uint32_t)0x00000080)) >>  7;
	*vgen_format = (localVal & ((uint32_t)0x00000060)) >>  5;
	*vgen_request_valid = (localVal & ((uint32_t)0x00000010)) >>  4;
	*vgen_request_sequence_id = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t macdsp_api1_vgen_req_part_1_vgen_dialog_token_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void macdsp_api1_vgen_req_part_1_vgen_dialog_token_setf(uint8_t vgendialogtoken)
{
	ASSERT_ERR((((uint32_t)vgendialogtoken << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_1_ADDR, (REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)vgendialogtoken <<24));
}
__INLINE uint8_t macdsp_api1_vgen_req_part_1_vgen_reserved_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00E00000)) >> 21);
}
__INLINE void macdsp_api1_vgen_req_part_1_vgen_reserved_setf(uint8_t vgenreserved)
{
	ASSERT_ERR((((uint32_t)vgenreserved << 21) & ~((uint32_t)0x00E00000)) == 0);
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_1_ADDR, (REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR) & ~((uint32_t)0x00E00000)) | ((uint32_t)vgenreserved <<21));
}
__INLINE uint8_t macdsp_api1_vgen_req_part_1_vgen_cqi_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00100000)) >> 20);
}
__INLINE void macdsp_api1_vgen_req_part_1_vgen_cqi_setf(uint8_t vgencqi)
{
	ASSERT_ERR((((uint32_t)vgencqi << 20) & ~((uint32_t)0x00100000)) == 0);
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_1_ADDR, (REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR) & ~((uint32_t)0x00100000)) | ((uint32_t)vgencqi <<20));
}
__INLINE uint8_t macdsp_api1_vgen_req_part_1_vgen_grouping_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000F0000)) >> 16);
}
__INLINE void macdsp_api1_vgen_req_part_1_vgen_grouping_setf(uint8_t vgengrouping)
{
	ASSERT_ERR((((uint32_t)vgengrouping << 16) & ~((uint32_t)0x000F0000)) == 0);
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_1_ADDR, (REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR) & ~((uint32_t)0x000F0000)) | ((uint32_t)vgengrouping <<16));
}
__INLINE uint8_t macdsp_api1_vgen_req_part_1_vgen_codebook_information_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000E000)) >> 13);
}
__INLINE void macdsp_api1_vgen_req_part_1_vgen_codebook_information_setf(uint8_t vgencodebookinformation)
{
	ASSERT_ERR((((uint32_t)vgencodebookinformation << 13) & ~((uint32_t)0x0000E000)) == 0);
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_1_ADDR, (REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR) & ~((uint32_t)0x0000E000)) | ((uint32_t)vgencodebookinformation <<13));
}
__INLINE uint8_t macdsp_api1_vgen_req_part_1_vgen_nc_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001C00)) >> 10);
}
__INLINE void macdsp_api1_vgen_req_part_1_vgen_nc_index_setf(uint8_t vgenncindex)
{
	ASSERT_ERR((((uint32_t)vgenncindex << 10) & ~((uint32_t)0x00001C00)) == 0);
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_1_ADDR, (REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR) & ~((uint32_t)0x00001C00)) | ((uint32_t)vgenncindex <<10));
}
__INLINE uint8_t macdsp_api1_vgen_req_part_1_vgen_feedback_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000300)) >> 8);
}
__INLINE void macdsp_api1_vgen_req_part_1_vgen_feedback_type_setf(uint8_t vgenfeedbacktype)
{
	ASSERT_ERR((((uint32_t)vgenfeedbacktype << 8) & ~((uint32_t)0x00000300)) == 0);
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_1_ADDR, (REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR) & ~((uint32_t)0x00000300)) | ((uint32_t)vgenfeedbacktype <<8));
}
__INLINE uint8_t macdsp_api1_vgen_req_part_1_vgen_sounding_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void macdsp_api1_vgen_req_part_1_vgen_sounding_type_setf(uint8_t vgensoundingtype)
{
	ASSERT_ERR((((uint32_t)vgensoundingtype << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_1_ADDR, (REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)vgensoundingtype <<7));
}
__INLINE uint8_t macdsp_api1_vgen_req_part_1_vgen_format_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000060)) >> 5);
}
__INLINE void macdsp_api1_vgen_req_part_1_vgen_format_setf(uint8_t vgenformat)
{
	ASSERT_ERR((((uint32_t)vgenformat << 5) & ~((uint32_t)0x00000060)) == 0);
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_1_ADDR, (REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR) & ~((uint32_t)0x00000060)) | ((uint32_t)vgenformat <<5));
}
__INLINE uint8_t macdsp_api1_vgen_req_part_1_vgen_request_valid_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void macdsp_api1_vgen_req_part_1_vgen_request_valid_setf(uint8_t vgenrequestvalid)
{
	ASSERT_ERR((((uint32_t)vgenrequestvalid << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_1_ADDR, (REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)vgenrequestvalid <<4));
}
__INLINE uint8_t macdsp_api1_vgen_req_part_1_vgen_request_sequence_id_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void macdsp_api1_vgen_req_part_1_vgen_request_sequence_id_setf(uint8_t vgenrequestsequenceid)
{
	ASSERT_ERR((((uint32_t)vgenrequestsequenceid << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_1_ADDR, (REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_1_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)vgenrequestsequenceid <<0));
}

/**
 * @brief VGEN_REQ_PART_2 register definition
 *  Beamformee_V_MATRIX_GEN_REQ_PART_2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:22 Vgen_Reserved2            0x0
 *    21:16 Vgen_Header_length        0x0
 *    15:14 Vgen_Reserved1            0x0
 *    13:07 Vgen_RU_end_Index         0x0
 *    06:00 Vgen_RU_start_Index       0x0
 * </pre>
 */
#define MACDSP_API1_VGEN_REQ_PART_2_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000064)
#define MACDSP_API1_VGEN_REQ_PART_2_OFFSET      0x00000064
#define MACDSP_API1_VGEN_REQ_PART_2_INDEX       0x00000019
#define MACDSP_API1_VGEN_REQ_PART_2_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_vgen_req_part_2_get(void)
{
	return REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_2_ADDR);
}

__INLINE void macdsp_api1_vgen_req_part_2_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_2_ADDR, value);
}

// field definitions
#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_RESERVED_2_MASK    ((uint32_t)0xFFC00000)
#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_RESERVED_2_LSB    22
#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_RESERVED_2_WIDTH    ((uint32_t)0x0000000A)
#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_HEADER_LENGTH_MASK    ((uint32_t)0x003F0000)
#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_HEADER_LENGTH_LSB    16
#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_HEADER_LENGTH_WIDTH    ((uint32_t)0x00000006)
#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_RESERVED_1_MASK    ((uint32_t)0x0000C000)
#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_RESERVED_1_LSB    14
#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_RESERVED_1_WIDTH    ((uint32_t)0x00000002)
#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_RU_END_INDEX_MASK    ((uint32_t)0x00003F80)
#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_RU_END_INDEX_LSB    7
#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_RU_END_INDEX_WIDTH    ((uint32_t)0x00000007)
#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_RU_START_INDEX_MASK    ((uint32_t)0x0000007F)
#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_RU_START_INDEX_LSB    0
#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_RU_START_INDEX_WIDTH    ((uint32_t)0x00000007)

#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_RESERVED_2_RST    0x0
#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_HEADER_LENGTH_RST    0x0
#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_RESERVED_1_RST    0x0
#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_RU_END_INDEX_RST    0x0
#define MACDSP_API1_VGEN_REQ_PART_2_VGEN_RU_START_INDEX_RST    0x0

__INLINE void macdsp_api1_vgen_req_part_2_pack(uint16_t vgen_reserved2, uint8_t vgen_header_length, uint8_t vgen_reserved1, uint8_t vgen_ru_end_index, uint8_t vgen_ru_start_index)
{
	ASSERT_ERR((((uint32_t)vgen_reserved2 << 22) & ~((uint32_t)0xFFC00000)) == 0);
	ASSERT_ERR((((uint32_t)vgen_header_length << 16) & ~((uint32_t)0x003F0000)) == 0);
	ASSERT_ERR((((uint32_t)vgen_reserved1 << 14) & ~((uint32_t)0x0000C000)) == 0);
	ASSERT_ERR((((uint32_t)vgen_ru_end_index << 7) & ~((uint32_t)0x00003F80)) == 0);
	ASSERT_ERR((((uint32_t)vgen_ru_start_index << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_2_ADDR,  ((uint32_t)vgen_reserved2 << 22) |((uint32_t)vgen_header_length << 16) |((uint32_t)vgen_reserved1 << 14) |((uint32_t)vgen_ru_end_index << 7) |((uint32_t)vgen_ru_start_index << 0));
}

__INLINE void macdsp_api1_vgen_req_part_2_unpack(uint16_t* vgen_reserved2, uint8_t* vgen_header_length, uint8_t* vgen_reserved1, uint8_t* vgen_ru_end_index, uint8_t* vgen_ru_start_index)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_2_ADDR);

	*vgen_reserved2 = (localVal & ((uint32_t)0xFFC00000)) >>  22;
	*vgen_header_length = (localVal & ((uint32_t)0x003F0000)) >>  16;
	*vgen_reserved1 = (localVal & ((uint32_t)0x0000C000)) >>  14;
	*vgen_ru_end_index = (localVal & ((uint32_t)0x00003F80)) >>  7;
	*vgen_ru_start_index = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint16_t macdsp_api1_vgen_req_part_2_vgen_reserved_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFC00000)) >> 22);
}
__INLINE void macdsp_api1_vgen_req_part_2_vgen_reserved_2_setf(uint16_t vgenreserved2)
{
	ASSERT_ERR((((uint32_t)vgenreserved2 << 22) & ~((uint32_t)0xFFC00000)) == 0);
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_2_ADDR, (REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_2_ADDR) & ~((uint32_t)0xFFC00000)) | ((uint32_t)vgenreserved2 <<22));
}
__INLINE uint8_t macdsp_api1_vgen_req_part_2_vgen_header_length_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x003F0000)) >> 16);
}
__INLINE void macdsp_api1_vgen_req_part_2_vgen_header_length_setf(uint8_t vgenheaderlength)
{
	ASSERT_ERR((((uint32_t)vgenheaderlength << 16) & ~((uint32_t)0x003F0000)) == 0);
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_2_ADDR, (REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_2_ADDR) & ~((uint32_t)0x003F0000)) | ((uint32_t)vgenheaderlength <<16));
}
__INLINE uint8_t macdsp_api1_vgen_req_part_2_vgen_reserved_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000C000)) >> 14);
}
__INLINE void macdsp_api1_vgen_req_part_2_vgen_reserved_1_setf(uint8_t vgenreserved1)
{
	ASSERT_ERR((((uint32_t)vgenreserved1 << 14) & ~((uint32_t)0x0000C000)) == 0);
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_2_ADDR, (REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_2_ADDR) & ~((uint32_t)0x0000C000)) | ((uint32_t)vgenreserved1 <<14));
}
__INLINE uint8_t macdsp_api1_vgen_req_part_2_vgen_ru_end_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003F80)) >> 7);
}
__INLINE void macdsp_api1_vgen_req_part_2_vgen_ru_end_index_setf(uint8_t vgenruendindex)
{
	ASSERT_ERR((((uint32_t)vgenruendindex << 7) & ~((uint32_t)0x00003F80)) == 0);
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_2_ADDR, (REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_2_ADDR) & ~((uint32_t)0x00003F80)) | ((uint32_t)vgenruendindex <<7));
}
__INLINE uint8_t macdsp_api1_vgen_req_part_2_vgen_ru_start_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}
__INLINE void macdsp_api1_vgen_req_part_2_vgen_ru_start_index_setf(uint8_t vgenrustartindex)
{
	ASSERT_ERR((((uint32_t)vgenrustartindex << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(MACDSP_API1_VGEN_REQ_PART_2_ADDR, (REG_PL_RD(MACDSP_API1_VGEN_REQ_PART_2_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)vgenrustartindex <<0));
}

/**
 * @brief FREQUENCY_OFFSET register definition
 *  frequency read option for the mac from the dsp register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 frequency_offset          0x0
 * </pre>
 */
#define MACDSP_API1_FREQUENCY_OFFSET_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000068)
#define MACDSP_API1_FREQUENCY_OFFSET_OFFSET      0x00000068
#define MACDSP_API1_FREQUENCY_OFFSET_INDEX       0x0000001A
#define MACDSP_API1_FREQUENCY_OFFSET_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_frequency_offset_get(void)
{
	return REG_PL_RD(MACDSP_API1_FREQUENCY_OFFSET_ADDR);
}

__INLINE void macdsp_api1_frequency_offset_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_FREQUENCY_OFFSET_ADDR, value);
}

// field definitions
#define MACDSP_API1_FREQUENCY_OFFSET_FREQUENCY_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_FREQUENCY_OFFSET_FREQUENCY_OFFSET_LSB    0
#define MACDSP_API1_FREQUENCY_OFFSET_FREQUENCY_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_FREQUENCY_OFFSET_FREQUENCY_OFFSET_RST    0x0

__INLINE uint32_t macdsp_api1_frequency_offset_frequency_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_FREQUENCY_OFFSET_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_frequency_offset_frequency_offset_setf(uint32_t frequencyoffset)
{
	ASSERT_ERR((((uint32_t)frequencyoffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_FREQUENCY_OFFSET_ADDR, (uint32_t)frequencyoffset << 0);
}

/**
 * @brief STA_CONF register definition
 *  Non-AP STA configuration register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    10:00 HE_STA_ID                 0x0
 * </pre>
 */
#define MACDSP_API1_STA_CONF_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000006C)
#define MACDSP_API1_STA_CONF_OFFSET      0x0000006C
#define MACDSP_API1_STA_CONF_INDEX       0x0000001B
#define MACDSP_API1_STA_CONF_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_sta_conf_get(void)
{
	return REG_PL_RD(MACDSP_API1_STA_CONF_ADDR);
}

__INLINE void macdsp_api1_sta_conf_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_STA_CONF_ADDR, value);
}

// field definitions
#define MACDSP_API1_STA_CONF_HE_STA_ID_MASK    ((uint32_t)0x000007FF)
#define MACDSP_API1_STA_CONF_HE_STA_ID_LSB    0
#define MACDSP_API1_STA_CONF_HE_STA_ID_WIDTH    ((uint32_t)0x0000000B)

#define MACDSP_API1_STA_CONF_HE_STA_ID_RST    0x0

__INLINE uint16_t macdsp_api1_sta_conf_he_sta_id_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_STA_CONF_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_sta_conf_he_sta_id_setf(uint16_t hestaid)
{
	ASSERT_ERR((((uint32_t)hestaid << 0) & ~((uint32_t)0x000007FF)) == 0);
	REG_PL_WR(MACDSP_API1_STA_CONF_ADDR, (uint32_t)hestaid << 0);
}

/**
 * @brief CARRIER_FREQ_MHZ register definition
 *  Carrier frequency in MHz register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Carrier_Freq_Mhz          0x0
 * </pre>
 */
#define MACDSP_API1_CARRIER_FREQ_MHZ_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000070)
#define MACDSP_API1_CARRIER_FREQ_MHZ_OFFSET      0x00000070
#define MACDSP_API1_CARRIER_FREQ_MHZ_INDEX       0x0000001C
#define MACDSP_API1_CARRIER_FREQ_MHZ_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_carrier_freq_mhz_get(void)
{
	return REG_PL_RD(MACDSP_API1_CARRIER_FREQ_MHZ_ADDR);
}

__INLINE void macdsp_api1_carrier_freq_mhz_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_CARRIER_FREQ_MHZ_ADDR, value);
}

// field definitions
#define MACDSP_API1_CARRIER_FREQ_MHZ_CARRIER_FREQ_MHZ_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_CARRIER_FREQ_MHZ_CARRIER_FREQ_MHZ_LSB    0
#define MACDSP_API1_CARRIER_FREQ_MHZ_CARRIER_FREQ_MHZ_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_CARRIER_FREQ_MHZ_CARRIER_FREQ_MHZ_RST    0x0

__INLINE uint32_t macdsp_api1_carrier_freq_mhz_carrier_freq_mhz_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CARRIER_FREQ_MHZ_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_carrier_freq_mhz_carrier_freq_mhz_setf(uint32_t carrierfreqmhz)
{
	ASSERT_ERR((((uint32_t)carrierfreqmhz << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_CARRIER_FREQ_MHZ_ADDR, (uint32_t)carrierfreqmhz << 0);
}

/**
 * @brief TX_DIG_GAIN_SINGLE_ANT register definition
 *  tx_dig_gain_single_ant register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TX_DIG_GAIN_SINGLE_ANT    0x0
 * </pre>
 */
#define MACDSP_API1_TX_DIG_GAIN_SINGLE_ANT_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000074)
#define MACDSP_API1_TX_DIG_GAIN_SINGLE_ANT_OFFSET      0x00000074
#define MACDSP_API1_TX_DIG_GAIN_SINGLE_ANT_INDEX       0x0000001D
#define MACDSP_API1_TX_DIG_GAIN_SINGLE_ANT_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tx_dig_gain_single_ant_get(void)
{
	return REG_PL_RD(MACDSP_API1_TX_DIG_GAIN_SINGLE_ANT_ADDR);
}

__INLINE void macdsp_api1_tx_dig_gain_single_ant_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TX_DIG_GAIN_SINGLE_ANT_ADDR, value);
}

// field definitions
#define MACDSP_API1_TX_DIG_GAIN_SINGLE_ANT_TX_DIG_GAIN_SINGLE_ANT_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_TX_DIG_GAIN_SINGLE_ANT_TX_DIG_GAIN_SINGLE_ANT_LSB    0
#define MACDSP_API1_TX_DIG_GAIN_SINGLE_ANT_TX_DIG_GAIN_SINGLE_ANT_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_TX_DIG_GAIN_SINGLE_ANT_TX_DIG_GAIN_SINGLE_ANT_RST    0x0

__INLINE uint32_t macdsp_api1_tx_dig_gain_single_ant_tx_dig_gain_single_ant_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_DIG_GAIN_SINGLE_ANT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_tx_dig_gain_single_ant_tx_dig_gain_single_ant_setf(uint32_t txdiggainsingleant)
{
	ASSERT_ERR((((uint32_t)txdiggainsingleant << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TX_DIG_GAIN_SINGLE_ANT_ADDR, (uint32_t)txdiggainsingleant << 0);
}

/**
 * @brief TX_DIG_GAIN_ALL_ANTS register definition
 *  tx_dig_gain_all_ants register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TX_DIG_GAIN_ALL_ANTS      0x0
 * </pre>
 */
#define MACDSP_API1_TX_DIG_GAIN_ALL_ANTS_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000078)
#define MACDSP_API1_TX_DIG_GAIN_ALL_ANTS_OFFSET      0x00000078
#define MACDSP_API1_TX_DIG_GAIN_ALL_ANTS_INDEX       0x0000001E
#define MACDSP_API1_TX_DIG_GAIN_ALL_ANTS_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tx_dig_gain_all_ants_get(void)
{
	return REG_PL_RD(MACDSP_API1_TX_DIG_GAIN_ALL_ANTS_ADDR);
}

__INLINE void macdsp_api1_tx_dig_gain_all_ants_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TX_DIG_GAIN_ALL_ANTS_ADDR, value);
}

// field definitions
#define MACDSP_API1_TX_DIG_GAIN_ALL_ANTS_TX_DIG_GAIN_ALL_ANTS_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_TX_DIG_GAIN_ALL_ANTS_TX_DIG_GAIN_ALL_ANTS_LSB    0
#define MACDSP_API1_TX_DIG_GAIN_ALL_ANTS_TX_DIG_GAIN_ALL_ANTS_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_TX_DIG_GAIN_ALL_ANTS_TX_DIG_GAIN_ALL_ANTS_RST    0x0

__INLINE uint32_t macdsp_api1_tx_dig_gain_all_ants_tx_dig_gain_all_ants_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_DIG_GAIN_ALL_ANTS_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_tx_dig_gain_all_ants_tx_dig_gain_all_ants_setf(uint32_t txdiggainallants)
{
	ASSERT_ERR((((uint32_t)txdiggainallants << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TX_DIG_GAIN_ALL_ANTS_ADDR, (uint32_t)txdiggainallants << 0);
}

/**
 * @brief DSP_VER register definition
 *  DSP version register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 major_version_number      0x0
 *    23:16 minor_version_number      0x0
 *    15:08 internal_version          0x0
 *    07:04 hw_step                   0x0
 *    03:00 platform_type             0x0
 * </pre>
 */
#define MACDSP_API1_DSP_VER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000080)
#define MACDSP_API1_DSP_VER_OFFSET      0x00000080
#define MACDSP_API1_DSP_VER_INDEX       0x00000020
#define MACDSP_API1_DSP_VER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_dsp_ver_get(void)
{
	return REG_PL_RD(MACDSP_API1_DSP_VER_ADDR);
}

// field definitions
#define MACDSP_API1_DSP_VER_MAJOR_VERSION_NUMBER_MASK    ((uint32_t)0xFF000000)
#define MACDSP_API1_DSP_VER_MAJOR_VERSION_NUMBER_LSB    24
#define MACDSP_API1_DSP_VER_MAJOR_VERSION_NUMBER_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_DSP_VER_MINOR_VERSION_NUMBER_MASK    ((uint32_t)0x00FF0000)
#define MACDSP_API1_DSP_VER_MINOR_VERSION_NUMBER_LSB    16
#define MACDSP_API1_DSP_VER_MINOR_VERSION_NUMBER_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_DSP_VER_INTERNAL_VERSION_MASK    ((uint32_t)0x0000FF00)
#define MACDSP_API1_DSP_VER_INTERNAL_VERSION_LSB    8
#define MACDSP_API1_DSP_VER_INTERNAL_VERSION_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_DSP_VER_HW_STEP_MASK    ((uint32_t)0x000000F0)
#define MACDSP_API1_DSP_VER_HW_STEP_LSB     4
#define MACDSP_API1_DSP_VER_HW_STEP_WIDTH    ((uint32_t)0x00000004)
#define MACDSP_API1_DSP_VER_PLATFORM_TYPE_MASK    ((uint32_t)0x0000000F)
#define MACDSP_API1_DSP_VER_PLATFORM_TYPE_LSB    0
#define MACDSP_API1_DSP_VER_PLATFORM_TYPE_WIDTH    ((uint32_t)0x00000004)

#define MACDSP_API1_DSP_VER_MAJOR_VERSION_NUMBER_RST    0x0
#define MACDSP_API1_DSP_VER_MINOR_VERSION_NUMBER_RST    0x0
#define MACDSP_API1_DSP_VER_INTERNAL_VERSION_RST    0x0
#define MACDSP_API1_DSP_VER_HW_STEP_RST     0x0
#define MACDSP_API1_DSP_VER_PLATFORM_TYPE_RST    0x0

__INLINE void macdsp_api1_dsp_ver_unpack(uint8_t* major_version_number, uint8_t* minor_version_number, uint8_t* internal_version, uint8_t* hw_step, uint8_t* platform_type)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_VER_ADDR);

	*major_version_number = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*minor_version_number = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*internal_version = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*hw_step = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*platform_type = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t macdsp_api1_dsp_ver_major_version_number_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_VER_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE uint8_t macdsp_api1_dsp_ver_minor_version_number_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_VER_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE uint8_t macdsp_api1_dsp_ver_internal_version_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_VER_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE uint8_t macdsp_api1_dsp_ver_hw_step_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_VER_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE uint8_t macdsp_api1_dsp_ver_platform_type_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_VER_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}

/**
 * @brief DSP_API_VER register definition
 *  The DSP API version number (RO by Host/MAC) register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 api_version               0x10
 * </pre>
 */
#define MACDSP_API1_DSP_API_VER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000084)
#define MACDSP_API1_DSP_API_VER_OFFSET      0x00000084
#define MACDSP_API1_DSP_API_VER_INDEX       0x00000021
#define MACDSP_API1_DSP_API_VER_RESET       0x00000010

__INLINE uint32_t  macdsp_api1_dsp_api_ver_get(void)
{
	return REG_PL_RD(MACDSP_API1_DSP_API_VER_ADDR);
}

// field definitions
#define MACDSP_API1_DSP_API_VER_API_VERSION_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_DSP_API_VER_API_VERSION_LSB    0
#define MACDSP_API1_DSP_API_VER_API_VERSION_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_DSP_API_VER_API_VERSION_RST    0x10

__INLINE uint32_t macdsp_api1_dsp_api_ver_api_version_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_API_VER_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief PPS_SS_1 register definition
 *  Post_process_SNR_of_Spatial_stream_1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Post_process_SNR_of_Spatial_stream_1 0x0
 * </pre>
 */
#define MACDSP_API1_PPS_SS_1_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000088)
#define MACDSP_API1_PPS_SS_1_OFFSET      0x00000088
#define MACDSP_API1_PPS_SS_1_INDEX       0x00000022
#define MACDSP_API1_PPS_SS_1_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_pps_ss_1_get(void)
{
	return REG_PL_RD(MACDSP_API1_PPS_SS_1_ADDR);
}

// field definitions
#define MACDSP_API1_PPS_SS_1_POST_PROCESS_SNR_OF_SPATIAL_STREAM_1_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_PPS_SS_1_POST_PROCESS_SNR_OF_SPATIAL_STREAM_1_LSB    0
#define MACDSP_API1_PPS_SS_1_POST_PROCESS_SNR_OF_SPATIAL_STREAM_1_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_PPS_SS_1_POST_PROCESS_SNR_OF_SPATIAL_STREAM_1_RST    0x0

__INLINE uint32_t macdsp_api1_pps_ss_1_post_process_snr_of_spatial_stream_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_PPS_SS_1_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief PPS_SS_2 register definition
 *  Post_process_SNR_of_Spatial_stream_2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Post_process_SNR_of_Spatial_stream_2 0x0
 * </pre>
 */
#define MACDSP_API1_PPS_SS_2_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000008C)
#define MACDSP_API1_PPS_SS_2_OFFSET      0x0000008C
#define MACDSP_API1_PPS_SS_2_INDEX       0x00000023
#define MACDSP_API1_PPS_SS_2_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_pps_ss_2_get(void)
{
	return REG_PL_RD(MACDSP_API1_PPS_SS_2_ADDR);
}

// field definitions
#define MACDSP_API1_PPS_SS_2_POST_PROCESS_SNR_OF_SPATIAL_STREAM_2_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_PPS_SS_2_POST_PROCESS_SNR_OF_SPATIAL_STREAM_2_LSB    0
#define MACDSP_API1_PPS_SS_2_POST_PROCESS_SNR_OF_SPATIAL_STREAM_2_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_PPS_SS_2_POST_PROCESS_SNR_OF_SPATIAL_STREAM_2_RST    0x0

__INLINE uint32_t macdsp_api1_pps_ss_2_post_process_snr_of_spatial_stream_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_PPS_SS_2_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief PPS_SS_3 register definition
 *  Post_process_SNR_of_Spatial_stream_3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Post_process_SNR_of_Spatial_stream_3 0x0
 * </pre>
 */
#define MACDSP_API1_PPS_SS_3_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000090)
#define MACDSP_API1_PPS_SS_3_OFFSET      0x00000090
#define MACDSP_API1_PPS_SS_3_INDEX       0x00000024
#define MACDSP_API1_PPS_SS_3_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_pps_ss_3_get(void)
{
	return REG_PL_RD(MACDSP_API1_PPS_SS_3_ADDR);
}

// field definitions
#define MACDSP_API1_PPS_SS_3_POST_PROCESS_SNR_OF_SPATIAL_STREAM_3_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_PPS_SS_3_POST_PROCESS_SNR_OF_SPATIAL_STREAM_3_LSB    0
#define MACDSP_API1_PPS_SS_3_POST_PROCESS_SNR_OF_SPATIAL_STREAM_3_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_PPS_SS_3_POST_PROCESS_SNR_OF_SPATIAL_STREAM_3_RST    0x0

__INLINE uint32_t macdsp_api1_pps_ss_3_post_process_snr_of_spatial_stream_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_PPS_SS_3_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief PPS_SS_4 register definition
 *  Post_process_SNR_of_Spatial_stream_4 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Post_process_SNR_of_Spatial_stream_4 0x0
 * </pre>
 */
#define MACDSP_API1_PPS_SS_4_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000094)
#define MACDSP_API1_PPS_SS_4_OFFSET      0x00000094
#define MACDSP_API1_PPS_SS_4_INDEX       0x00000025
#define MACDSP_API1_PPS_SS_4_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_pps_ss_4_get(void)
{
	return REG_PL_RD(MACDSP_API1_PPS_SS_4_ADDR);
}

// field definitions
#define MACDSP_API1_PPS_SS_4_POST_PROCESS_SNR_OF_SPATIAL_STREAM_4_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_PPS_SS_4_POST_PROCESS_SNR_OF_SPATIAL_STREAM_4_LSB    0
#define MACDSP_API1_PPS_SS_4_POST_PROCESS_SNR_OF_SPATIAL_STREAM_4_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_PPS_SS_4_POST_PROCESS_SNR_OF_SPATIAL_STREAM_4_RST    0x0

__INLINE uint32_t macdsp_api1_pps_ss_4_post_process_snr_of_spatial_stream_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_PPS_SS_4_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief FRAME_DESCRIPTION register definition
 *  Frame_Description register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:17 ldpc_block_num            0x0
 *    16    ldpc_error                0              
 *    15    evm_glitch                0              
 *    14    coding                    0              
 *    13:12 giltf                     0x0
 *    11:10 frame_description_nss     0x0
 *    09:06 mcs                       0x0
 *    05:04 bw                        0x0
 *    03:00 format                    0x0
 * </pre>
 */
#define MACDSP_API1_FRAME_DESCRIPTION_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000098)
#define MACDSP_API1_FRAME_DESCRIPTION_OFFSET      0x00000098
#define MACDSP_API1_FRAME_DESCRIPTION_INDEX       0x00000026
#define MACDSP_API1_FRAME_DESCRIPTION_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_frame_description_get(void)
{
	return REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR);
}

__INLINE void macdsp_api1_frame_description_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_FRAME_DESCRIPTION_ADDR, value);
}

// field definitions
#define MACDSP_API1_FRAME_DESCRIPTION_LDPC_BLOCK_NUM_MASK    ((uint32_t)0x7FFE0000)
#define MACDSP_API1_FRAME_DESCRIPTION_LDPC_BLOCK_NUM_LSB    17
#define MACDSP_API1_FRAME_DESCRIPTION_LDPC_BLOCK_NUM_WIDTH    ((uint32_t)0x0000000E)
#define MACDSP_API1_FRAME_DESCRIPTION_LDPC_ERROR_BIT    ((uint32_t)0x00010000)
#define MACDSP_API1_FRAME_DESCRIPTION_LDPC_ERROR_POS    16
#define MACDSP_API1_FRAME_DESCRIPTION_EVM_GLITCH_BIT    ((uint32_t)0x00008000)
#define MACDSP_API1_FRAME_DESCRIPTION_EVM_GLITCH_POS    15
#define MACDSP_API1_FRAME_DESCRIPTION_CODING_BIT    ((uint32_t)0x00004000)
#define MACDSP_API1_FRAME_DESCRIPTION_CODING_POS    14
#define MACDSP_API1_FRAME_DESCRIPTION_GILTF_MASK    ((uint32_t)0x00003000)
#define MACDSP_API1_FRAME_DESCRIPTION_GILTF_LSB    12
#define MACDSP_API1_FRAME_DESCRIPTION_GILTF_WIDTH    ((uint32_t)0x00000002)
#define MACDSP_API1_FRAME_DESCRIPTION_FRAME_DESCRIPTION_NSS_MASK    ((uint32_t)0x00000C00)
#define MACDSP_API1_FRAME_DESCRIPTION_FRAME_DESCRIPTION_NSS_LSB    10
#define MACDSP_API1_FRAME_DESCRIPTION_FRAME_DESCRIPTION_NSS_WIDTH    ((uint32_t)0x00000002)
#define MACDSP_API1_FRAME_DESCRIPTION_MCS_MASK    ((uint32_t)0x000003C0)
#define MACDSP_API1_FRAME_DESCRIPTION_MCS_LSB    6
#define MACDSP_API1_FRAME_DESCRIPTION_MCS_WIDTH    ((uint32_t)0x00000004)
#define MACDSP_API1_FRAME_DESCRIPTION_BW_MASK    ((uint32_t)0x00000030)
#define MACDSP_API1_FRAME_DESCRIPTION_BW_LSB    4
#define MACDSP_API1_FRAME_DESCRIPTION_BW_WIDTH    ((uint32_t)0x00000002)
#define MACDSP_API1_FRAME_DESCRIPTION_FORMAT_MASK    ((uint32_t)0x0000000F)
#define MACDSP_API1_FRAME_DESCRIPTION_FORMAT_LSB    0
#define MACDSP_API1_FRAME_DESCRIPTION_FORMAT_WIDTH    ((uint32_t)0x00000004)

#define MACDSP_API1_FRAME_DESCRIPTION_LDPC_BLOCK_NUM_RST    0x0
#define MACDSP_API1_FRAME_DESCRIPTION_LDPC_ERROR_RST    0x0
#define MACDSP_API1_FRAME_DESCRIPTION_EVM_GLITCH_RST    0x0
#define MACDSP_API1_FRAME_DESCRIPTION_CODING_RST    0x0
#define MACDSP_API1_FRAME_DESCRIPTION_GILTF_RST    0x0
#define MACDSP_API1_FRAME_DESCRIPTION_FRAME_DESCRIPTION_NSS_RST    0x0
#define MACDSP_API1_FRAME_DESCRIPTION_MCS_RST    0x0
#define MACDSP_API1_FRAME_DESCRIPTION_BW_RST    0x0
#define MACDSP_API1_FRAME_DESCRIPTION_FORMAT_RST    0x0

__INLINE void macdsp_api1_frame_description_pack(uint16_t ldpc_block_num, uint8_t ldpc_error, uint8_t evm_glitch, uint8_t coding, uint8_t giltf, uint8_t frame_description_nss, uint8_t mcs, uint8_t bw, uint8_t format)
{
	ASSERT_ERR((((uint32_t)ldpc_block_num << 17) & ~((uint32_t)0x7FFE0000)) == 0);
	ASSERT_ERR((((uint32_t)ldpc_error << 16) & ~((uint32_t)0x00010000)) == 0);
	ASSERT_ERR((((uint32_t)evm_glitch << 15) & ~((uint32_t)0x00008000)) == 0);
	ASSERT_ERR((((uint32_t)coding << 14) & ~((uint32_t)0x00004000)) == 0);
	ASSERT_ERR((((uint32_t)giltf << 12) & ~((uint32_t)0x00003000)) == 0);
	ASSERT_ERR((((uint32_t)frame_description_nss << 10) & ~((uint32_t)0x00000C00)) == 0);
	ASSERT_ERR((((uint32_t)mcs << 6) & ~((uint32_t)0x000003C0)) == 0);
	ASSERT_ERR((((uint32_t)bw << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)format << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MACDSP_API1_FRAME_DESCRIPTION_ADDR,  ((uint32_t)ldpc_block_num << 17) |((uint32_t)ldpc_error << 16) |((uint32_t)evm_glitch << 15) |((uint32_t)coding << 14) |((uint32_t)giltf << 12) |((uint32_t)frame_description_nss << 10) |((uint32_t)mcs << 6) |((uint32_t)bw << 4) |((uint32_t)format << 0));
}

__INLINE void macdsp_api1_frame_description_unpack(uint16_t* ldpc_block_num, uint8_t* ldpc_error, uint8_t* evm_glitch, uint8_t* coding, uint8_t* giltf, uint8_t* frame_description_nss, uint8_t* mcs, uint8_t* bw, uint8_t* format)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR);

	*ldpc_block_num = (localVal & ((uint32_t)0x7FFE0000)) >>  17;
	*ldpc_error = (localVal & ((uint32_t)0x00010000)) >>  16;
	*evm_glitch = (localVal & ((uint32_t)0x00008000)) >>  15;
	*coding = (localVal & ((uint32_t)0x00004000)) >>  14;
	*giltf = (localVal & ((uint32_t)0x00003000)) >>  12;
	*frame_description_nss = (localVal & ((uint32_t)0x00000C00)) >>  10;
	*mcs = (localVal & ((uint32_t)0x000003C0)) >>  6;
	*bw = (localVal & ((uint32_t)0x00000030)) >>  4;
	*format = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint16_t macdsp_api1_frame_description_ldpc_block_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x7FFE0000)) >> 17);
}
__INLINE void macdsp_api1_frame_description_ldpc_block_num_setf(uint16_t ldpcblocknum)
{
	ASSERT_ERR((((uint32_t)ldpcblocknum << 17) & ~((uint32_t)0x7FFE0000)) == 0);
	REG_PL_WR(MACDSP_API1_FRAME_DESCRIPTION_ADDR, (REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR) & ~((uint32_t)0x7FFE0000)) | ((uint32_t)ldpcblocknum <<17));
}
__INLINE uint8_t macdsp_api1_frame_description_ldpc_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00010000)) >> 16);
}
__INLINE void macdsp_api1_frame_description_ldpc_error_setf(uint8_t ldpcerror)
{
	ASSERT_ERR((((uint32_t)ldpcerror << 16) & ~((uint32_t)0x00010000)) == 0);
	REG_PL_WR(MACDSP_API1_FRAME_DESCRIPTION_ADDR, (REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR) & ~((uint32_t)0x00010000)) | ((uint32_t)ldpcerror <<16));
}
__INLINE uint8_t macdsp_api1_frame_description_evm_glitch_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00008000)) >> 15);
}
__INLINE void macdsp_api1_frame_description_evm_glitch_setf(uint8_t evmglitch)
{
	ASSERT_ERR((((uint32_t)evmglitch << 15) & ~((uint32_t)0x00008000)) == 0);
	REG_PL_WR(MACDSP_API1_FRAME_DESCRIPTION_ADDR, (REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR) & ~((uint32_t)0x00008000)) | ((uint32_t)evmglitch <<15));
}
__INLINE uint8_t macdsp_api1_frame_description_coding_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00004000)) >> 14);
}
__INLINE void macdsp_api1_frame_description_coding_setf(uint8_t coding)
{
	ASSERT_ERR((((uint32_t)coding << 14) & ~((uint32_t)0x00004000)) == 0);
	REG_PL_WR(MACDSP_API1_FRAME_DESCRIPTION_ADDR, (REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)coding <<14));
}
__INLINE uint8_t macdsp_api1_frame_description_giltf_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00003000)) >> 12);
}
__INLINE void macdsp_api1_frame_description_giltf_setf(uint8_t giltf)
{
	ASSERT_ERR((((uint32_t)giltf << 12) & ~((uint32_t)0x00003000)) == 0);
	REG_PL_WR(MACDSP_API1_FRAME_DESCRIPTION_ADDR, (REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR) & ~((uint32_t)0x00003000)) | ((uint32_t)giltf <<12));
}
__INLINE uint8_t macdsp_api1_frame_description_frame_description_nss_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000C00)) >> 10);
}
__INLINE void macdsp_api1_frame_description_frame_description_nss_setf(uint8_t framedescriptionnss)
{
	ASSERT_ERR((((uint32_t)framedescriptionnss << 10) & ~((uint32_t)0x00000C00)) == 0);
	REG_PL_WR(MACDSP_API1_FRAME_DESCRIPTION_ADDR, (REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR) & ~((uint32_t)0x00000C00)) | ((uint32_t)framedescriptionnss <<10));
}
__INLINE uint8_t macdsp_api1_frame_description_mcs_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000003C0)) >> 6);
}
__INLINE void macdsp_api1_frame_description_mcs_setf(uint8_t mcs)
{
	ASSERT_ERR((((uint32_t)mcs << 6) & ~((uint32_t)0x000003C0)) == 0);
	REG_PL_WR(MACDSP_API1_FRAME_DESCRIPTION_ADDR, (REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR) & ~((uint32_t)0x000003C0)) | ((uint32_t)mcs <<6));
}
__INLINE uint8_t macdsp_api1_frame_description_bw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void macdsp_api1_frame_description_bw_setf(uint8_t bw)
{
	ASSERT_ERR((((uint32_t)bw << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(MACDSP_API1_FRAME_DESCRIPTION_ADDR, (REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)bw <<4));
}
__INLINE uint8_t macdsp_api1_frame_description_format_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void macdsp_api1_frame_description_format_setf(uint8_t format)
{
	ASSERT_ERR((((uint32_t)format << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MACDSP_API1_FRAME_DESCRIPTION_ADDR, (REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)format <<0));
}

/**
 * @brief FRAME_DESCRIPTION_2 register definition
 *  Frame_Description register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:11 BPU_BLOCK_ERR_SYMB_NUM    0x0
 *    09:00 EVM_DROP_SYMB_NUM         0x0
 * </pre>
 */
#define MACDSP_API1_FRAME_DESCRIPTION_2_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000009C)
#define MACDSP_API1_FRAME_DESCRIPTION_2_OFFSET      0x0000009C
#define MACDSP_API1_FRAME_DESCRIPTION_2_INDEX       0x00000027
#define MACDSP_API1_FRAME_DESCRIPTION_2_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_frame_description_2_get(void)
{
	return REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_2_ADDR);
}

__INLINE void macdsp_api1_frame_description_2_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_FRAME_DESCRIPTION_2_ADDR, value);
}

// field definitions
#define MACDSP_API1_FRAME_DESCRIPTION_2_BPU_BLOCK_ERR_SYMB_NUM_MASK    ((uint32_t)0xFFFFF800)
#define MACDSP_API1_FRAME_DESCRIPTION_2_BPU_BLOCK_ERR_SYMB_NUM_LSB    11
#define MACDSP_API1_FRAME_DESCRIPTION_2_BPU_BLOCK_ERR_SYMB_NUM_WIDTH    ((uint32_t)0x00000015)
#define MACDSP_API1_FRAME_DESCRIPTION_2_EVM_DROP_SYMB_NUM_MASK    ((uint32_t)0x000003FF)
#define MACDSP_API1_FRAME_DESCRIPTION_2_EVM_DROP_SYMB_NUM_LSB    0
#define MACDSP_API1_FRAME_DESCRIPTION_2_EVM_DROP_SYMB_NUM_WIDTH    ((uint32_t)0x0000000A)

#define MACDSP_API1_FRAME_DESCRIPTION_2_BPU_BLOCK_ERR_SYMB_NUM_RST    0x0
#define MACDSP_API1_FRAME_DESCRIPTION_2_EVM_DROP_SYMB_NUM_RST    0x0

__INLINE void macdsp_api1_frame_description_2_pack(uint32_t bpu_block_err_symb_num, uint16_t evm_drop_symb_num)
{
	ASSERT_ERR((((uint32_t)bpu_block_err_symb_num << 11) & ~((uint32_t)0xFFFFF800)) == 0);
	ASSERT_ERR((((uint32_t)evm_drop_symb_num << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(MACDSP_API1_FRAME_DESCRIPTION_2_ADDR,  ((uint32_t)bpu_block_err_symb_num << 11) |((uint32_t)evm_drop_symb_num << 0));
}

__INLINE void macdsp_api1_frame_description_2_unpack(uint32_t* bpu_block_err_symb_num, uint16_t* evm_drop_symb_num)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_2_ADDR);

	*bpu_block_err_symb_num = (localVal & ((uint32_t)0xFFFFF800)) >>  11;
	*evm_drop_symb_num = (localVal & ((uint32_t)0x000003FF)) >>  0;
}

__INLINE uint32_t macdsp_api1_frame_description_2_bpu_block_err_symb_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_2_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0xFFFFF800)) >> 11);
}
__INLINE void macdsp_api1_frame_description_2_bpu_block_err_symb_num_setf(uint32_t bpublockerrsymbnum)
{
	ASSERT_ERR((((uint32_t)bpublockerrsymbnum << 11) & ~((uint32_t)0xFFFFF800)) == 0);
	REG_PL_WR(MACDSP_API1_FRAME_DESCRIPTION_2_ADDR, (REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_2_ADDR) & ~((uint32_t)0xFFFFF800)) | ((uint32_t)bpublockerrsymbnum <<11));
}
__INLINE uint16_t macdsp_api1_frame_description_2_evm_drop_symb_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x000003FF)) >> 0);
}
__INLINE void macdsp_api1_frame_description_2_evm_drop_symb_num_setf(uint16_t evmdropsymbnum)
{
	ASSERT_ERR((((uint32_t)evmdropsymbnum << 0) & ~((uint32_t)0x000003FF)) == 0);
	REG_PL_WR(MACDSP_API1_FRAME_DESCRIPTION_2_ADDR, (REG_PL_RD(MACDSP_API1_FRAME_DESCRIPTION_2_ADDR) & ~((uint32_t)0x000003FF)) | ((uint32_t)evmdropsymbnum <<0));
}

/**
 * @brief DSP_DEBUGS_BASE_ADDRESS_1 register definition
 *  DspDebugsBaseAddress1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Dsp_Debugs_Base_Address   0x0
 * </pre>
 */
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_1_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000100)
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_1_OFFSET      0x00000100
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_1_INDEX       0x00000040
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_1_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_dsp_debugs_base_address_1_get(void)
{
	return REG_PL_RD(MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_1_ADDR);
}

// field definitions
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_1_DSP_DEBUGS_BASE_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_1_DSP_DEBUGS_BASE_ADDRESS_LSB    0
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_1_DSP_DEBUGS_BASE_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_1_DSP_DEBUGS_BASE_ADDRESS_RST    0x0

__INLINE uint32_t macdsp_api1_dsp_debugs_base_address_1_dsp_debugs_base_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_1_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief DSP_DEBUGS_SECTION_SIZE_1 register definition
 *  DspDebugsSectionSize1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Dsp_Debugs_Section_Size   0x0
 * </pre>
 */
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_1_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000104)
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_1_OFFSET      0x00000104
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_1_INDEX       0x00000041
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_1_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_dsp_debugs_section_size_1_get(void)
{
	return REG_PL_RD(MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_1_ADDR);
}

// field definitions
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_1_DSP_DEBUGS_SECTION_SIZE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_1_DSP_DEBUGS_SECTION_SIZE_LSB    0
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_1_DSP_DEBUGS_SECTION_SIZE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_1_DSP_DEBUGS_SECTION_SIZE_RST    0x0

__INLINE uint32_t macdsp_api1_dsp_debugs_section_size_1_dsp_debugs_section_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_1_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief DSP_DEBUGS_BASE_ADDRESS_2 register definition
 *  DspDebugsBaseAddress2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Dsp_Debugs_Base_Address   0x0
 * </pre>
 */
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_2_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000108)
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_2_OFFSET      0x00000108
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_2_INDEX       0x00000042
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_2_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_dsp_debugs_base_address_2_get(void)
{
	return REG_PL_RD(MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_2_ADDR);
}

// field definitions
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_2_DSP_DEBUGS_BASE_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_2_DSP_DEBUGS_BASE_ADDRESS_LSB    0
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_2_DSP_DEBUGS_BASE_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_2_DSP_DEBUGS_BASE_ADDRESS_RST    0x0

__INLINE uint32_t macdsp_api1_dsp_debugs_base_address_2_dsp_debugs_base_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_2_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief DSP_DEBUGS_SECTION_SIZE_2 register definition
 *  DspDebugsSectionSize2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Dsp_Debugs_Section_Size   0x0
 * </pre>
 */
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_2_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000010C)
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_2_OFFSET      0x0000010C
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_2_INDEX       0x00000043
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_2_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_dsp_debugs_section_size_2_get(void)
{
	return REG_PL_RD(MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_2_ADDR);
}

// field definitions
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_2_DSP_DEBUGS_SECTION_SIZE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_2_DSP_DEBUGS_SECTION_SIZE_LSB    0
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_2_DSP_DEBUGS_SECTION_SIZE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_2_DSP_DEBUGS_SECTION_SIZE_RST    0x0

__INLINE uint32_t macdsp_api1_dsp_debugs_section_size_2_dsp_debugs_section_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_2_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief DSP_DEBUGS_BASE_ADDRESS_3 register definition
 *  DspDebugsBaseAddress3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Dsp_Debugs_Base_Address   0x0
 * </pre>
 */
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_3_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000110)
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_3_OFFSET      0x00000110
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_3_INDEX       0x00000044
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_3_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_dsp_debugs_base_address_3_get(void)
{
	return REG_PL_RD(MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_3_ADDR);
}

// field definitions
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_3_DSP_DEBUGS_BASE_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_3_DSP_DEBUGS_BASE_ADDRESS_LSB    0
#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_3_DSP_DEBUGS_BASE_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_3_DSP_DEBUGS_BASE_ADDRESS_RST    0x0

__INLINE uint32_t macdsp_api1_dsp_debugs_base_address_3_dsp_debugs_base_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_DEBUGS_BASE_ADDRESS_3_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief DSP_DEBUGS_SECTION_SIZE_3 register definition
 *  DspDebugsSectionSize3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Dsp_Debugs_Section_Size   0x0
 * </pre>
 */
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_3_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000114)
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_3_OFFSET      0x00000114
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_3_INDEX       0x00000045
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_3_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_dsp_debugs_section_size_3_get(void)
{
	return REG_PL_RD(MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_3_ADDR);
}

// field definitions
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_3_DSP_DEBUGS_SECTION_SIZE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_3_DSP_DEBUGS_SECTION_SIZE_LSB    0
#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_3_DSP_DEBUGS_SECTION_SIZE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_3_DSP_DEBUGS_SECTION_SIZE_RST    0x0

__INLINE uint32_t macdsp_api1_dsp_debugs_section_size_3_dsp_debugs_section_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_DEBUGS_SECTION_SIZE_3_ADDR);
	return (uint32_t)(localVal >> 0);
}

/**
 * @brief USER_POSITION_TBL_BASE register definition
 *  USER_POSITION_TBL_BASE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 User_Position_Tbl_Base_Addr 0x0
 * </pre>
 */
#define MACDSP_API1_USER_POSITION_TBL_BASE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000118)
#define MACDSP_API1_USER_POSITION_TBL_BASE_OFFSET      0x00000118
#define MACDSP_API1_USER_POSITION_TBL_BASE_INDEX       0x00000046
#define MACDSP_API1_USER_POSITION_TBL_BASE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_user_position_tbl_base_get(void)
{
	return REG_PL_RD(MACDSP_API1_USER_POSITION_TBL_BASE_ADDR);
}

__INLINE void macdsp_api1_user_position_tbl_base_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_USER_POSITION_TBL_BASE_ADDR, value);
}

// field definitions
#define MACDSP_API1_USER_POSITION_TBL_BASE_USER_POSITION_TBL_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_USER_POSITION_TBL_BASE_USER_POSITION_TBL_BASE_ADDR_LSB    0
#define MACDSP_API1_USER_POSITION_TBL_BASE_USER_POSITION_TBL_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_USER_POSITION_TBL_BASE_USER_POSITION_TBL_BASE_ADDR_RST    0x0

__INLINE uint32_t macdsp_api1_user_position_tbl_base_user_position_tbl_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_USER_POSITION_TBL_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_user_position_tbl_base_user_position_tbl_base_addr_setf(uint32_t userpositiontblbaseaddr)
{
	ASSERT_ERR((((uint32_t)userpositiontblbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_USER_POSITION_TBL_BASE_ADDR, (uint32_t)userpositiontblbaseaddr << 0);
}

/**
 * @brief USER_POSITION_TBL_SIZE register definition
 *  USER_POSITION_TBL_SIZE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 User_Position_Tbl_Section_Size 0x0
 * </pre>
 */
#define MACDSP_API1_USER_POSITION_TBL_SIZE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000011C)
#define MACDSP_API1_USER_POSITION_TBL_SIZE_OFFSET      0x0000011C
#define MACDSP_API1_USER_POSITION_TBL_SIZE_INDEX       0x00000047
#define MACDSP_API1_USER_POSITION_TBL_SIZE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_user_position_tbl_size_get(void)
{
	return REG_PL_RD(MACDSP_API1_USER_POSITION_TBL_SIZE_ADDR);
}

__INLINE void macdsp_api1_user_position_tbl_size_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_USER_POSITION_TBL_SIZE_ADDR, value);
}

// field definitions
#define MACDSP_API1_USER_POSITION_TBL_SIZE_USER_POSITION_TBL_SECTION_SIZE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_USER_POSITION_TBL_SIZE_USER_POSITION_TBL_SECTION_SIZE_LSB    0
#define MACDSP_API1_USER_POSITION_TBL_SIZE_USER_POSITION_TBL_SECTION_SIZE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_USER_POSITION_TBL_SIZE_USER_POSITION_TBL_SECTION_SIZE_RST    0x0

__INLINE uint32_t macdsp_api1_user_position_tbl_size_user_position_tbl_section_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_USER_POSITION_TBL_SIZE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_user_position_tbl_size_user_position_tbl_section_size_setf(uint32_t userpositiontblsectionsize)
{
	ASSERT_ERR((((uint32_t)userpositiontblsectionsize << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_USER_POSITION_TBL_SIZE_ADDR, (uint32_t)userpositiontblsectionsize << 0);
}

/**
 * @brief XMEM_QMATRIX_TBL_BASE register definition
 *  XMEM_QMATRIX_TBL_BASE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Xmem_Qmatrix_Tbl_Base_Addr 0x0
 * </pre>
 */
#define MACDSP_API1_XMEM_QMATRIX_TBL_BASE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000120)
#define MACDSP_API1_XMEM_QMATRIX_TBL_BASE_OFFSET      0x00000120
#define MACDSP_API1_XMEM_QMATRIX_TBL_BASE_INDEX       0x00000048
#define MACDSP_API1_XMEM_QMATRIX_TBL_BASE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_xmem_qmatrix_tbl_base_get(void)
{
	return REG_PL_RD(MACDSP_API1_XMEM_QMATRIX_TBL_BASE_ADDR);
}

__INLINE void macdsp_api1_xmem_qmatrix_tbl_base_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_XMEM_QMATRIX_TBL_BASE_ADDR, value);
}

// field definitions
#define MACDSP_API1_XMEM_QMATRIX_TBL_BASE_XMEM_QMATRIX_TBL_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_XMEM_QMATRIX_TBL_BASE_XMEM_QMATRIX_TBL_BASE_ADDR_LSB    0
#define MACDSP_API1_XMEM_QMATRIX_TBL_BASE_XMEM_QMATRIX_TBL_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_XMEM_QMATRIX_TBL_BASE_XMEM_QMATRIX_TBL_BASE_ADDR_RST    0x0

__INLINE uint32_t macdsp_api1_xmem_qmatrix_tbl_base_xmem_qmatrix_tbl_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_XMEM_QMATRIX_TBL_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_xmem_qmatrix_tbl_base_xmem_qmatrix_tbl_base_addr_setf(uint32_t xmemqmatrixtblbaseaddr)
{
	ASSERT_ERR((((uint32_t)xmemqmatrixtblbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_XMEM_QMATRIX_TBL_BASE_ADDR, (uint32_t)xmemqmatrixtblbaseaddr << 0);
}

/**
 * @brief XMEM_QMATRIX_TBL_SIZE register definition
 *  XMEM_QMATRIX_TBL_SIZE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Xmem_Qmatrix_Tbl_Section_Size 0x0
 * </pre>
 */
#define MACDSP_API1_XMEM_QMATRIX_TBL_SIZE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000124)
#define MACDSP_API1_XMEM_QMATRIX_TBL_SIZE_OFFSET      0x00000124
#define MACDSP_API1_XMEM_QMATRIX_TBL_SIZE_INDEX       0x00000049
#define MACDSP_API1_XMEM_QMATRIX_TBL_SIZE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_xmem_qmatrix_tbl_size_get(void)
{
	return REG_PL_RD(MACDSP_API1_XMEM_QMATRIX_TBL_SIZE_ADDR);
}

__INLINE void macdsp_api1_xmem_qmatrix_tbl_size_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_XMEM_QMATRIX_TBL_SIZE_ADDR, value);
}

// field definitions
#define MACDSP_API1_XMEM_QMATRIX_TBL_SIZE_XMEM_QMATRIX_TBL_SECTION_SIZE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_XMEM_QMATRIX_TBL_SIZE_XMEM_QMATRIX_TBL_SECTION_SIZE_LSB    0
#define MACDSP_API1_XMEM_QMATRIX_TBL_SIZE_XMEM_QMATRIX_TBL_SECTION_SIZE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_XMEM_QMATRIX_TBL_SIZE_XMEM_QMATRIX_TBL_SECTION_SIZE_RST    0x0

__INLINE uint32_t macdsp_api1_xmem_qmatrix_tbl_size_xmem_qmatrix_tbl_section_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_XMEM_QMATRIX_TBL_SIZE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_xmem_qmatrix_tbl_size_xmem_qmatrix_tbl_section_size_setf(uint32_t xmemqmatrixtblsectionsize)
{
	ASSERT_ERR((((uint32_t)xmemqmatrixtblsectionsize << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_XMEM_QMATRIX_TBL_SIZE_ADDR, (uint32_t)xmemqmatrixtblsectionsize << 0);
}

/**
 * @brief XMEM_QMIRROR_TBL_BASE register definition
 *  XMEM_QMIRROR_TBL_BASE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Xmem_Qmirror_Tbl_Base_Addr 0x0
 * </pre>
 */
#define MACDSP_API1_XMEM_QMIRROR_TBL_BASE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000128)
#define MACDSP_API1_XMEM_QMIRROR_TBL_BASE_OFFSET      0x00000128
#define MACDSP_API1_XMEM_QMIRROR_TBL_BASE_INDEX       0x0000004A
#define MACDSP_API1_XMEM_QMIRROR_TBL_BASE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_xmem_qmirror_tbl_base_get(void)
{
	return REG_PL_RD(MACDSP_API1_XMEM_QMIRROR_TBL_BASE_ADDR);
}

__INLINE void macdsp_api1_xmem_qmirror_tbl_base_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_XMEM_QMIRROR_TBL_BASE_ADDR, value);
}

// field definitions
#define MACDSP_API1_XMEM_QMIRROR_TBL_BASE_XMEM_QMIRROR_TBL_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_XMEM_QMIRROR_TBL_BASE_XMEM_QMIRROR_TBL_BASE_ADDR_LSB    0
#define MACDSP_API1_XMEM_QMIRROR_TBL_BASE_XMEM_QMIRROR_TBL_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_XMEM_QMIRROR_TBL_BASE_XMEM_QMIRROR_TBL_BASE_ADDR_RST    0x0

__INLINE uint32_t macdsp_api1_xmem_qmirror_tbl_base_xmem_qmirror_tbl_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_XMEM_QMIRROR_TBL_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_xmem_qmirror_tbl_base_xmem_qmirror_tbl_base_addr_setf(uint32_t xmemqmirrortblbaseaddr)
{
	ASSERT_ERR((((uint32_t)xmemqmirrortblbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_XMEM_QMIRROR_TBL_BASE_ADDR, (uint32_t)xmemqmirrortblbaseaddr << 0);
}

/**
 * @brief XMEM_QMIRROR_TBL_SIZE register definition
 *  XMEM_QMIRROR_TBL_SIZE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Xmem_Qmirror_Tbl_Section_Size 0x0
 * </pre>
 */
#define MACDSP_API1_XMEM_QMIRROR_TBL_SIZE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000012C)
#define MACDSP_API1_XMEM_QMIRROR_TBL_SIZE_OFFSET      0x0000012C
#define MACDSP_API1_XMEM_QMIRROR_TBL_SIZE_INDEX       0x0000004B
#define MACDSP_API1_XMEM_QMIRROR_TBL_SIZE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_xmem_qmirror_tbl_size_get(void)
{
	return REG_PL_RD(MACDSP_API1_XMEM_QMIRROR_TBL_SIZE_ADDR);
}

__INLINE void macdsp_api1_xmem_qmirror_tbl_size_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_XMEM_QMIRROR_TBL_SIZE_ADDR, value);
}

// field definitions
#define MACDSP_API1_XMEM_QMIRROR_TBL_SIZE_XMEM_QMIRROR_TBL_SECTION_SIZE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_XMEM_QMIRROR_TBL_SIZE_XMEM_QMIRROR_TBL_SECTION_SIZE_LSB    0
#define MACDSP_API1_XMEM_QMIRROR_TBL_SIZE_XMEM_QMIRROR_TBL_SECTION_SIZE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_XMEM_QMIRROR_TBL_SIZE_XMEM_QMIRROR_TBL_SECTION_SIZE_RST    0x0

__INLINE uint32_t macdsp_api1_xmem_qmirror_tbl_size_xmem_qmirror_tbl_section_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_XMEM_QMIRROR_TBL_SIZE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_xmem_qmirror_tbl_size_xmem_qmirror_tbl_section_size_setf(uint32_t xmemqmirrortblsectionsize)
{
	ASSERT_ERR((((uint32_t)xmemqmirrortblsectionsize << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_XMEM_QMIRROR_TBL_SIZE_ADDR, (uint32_t)xmemqmirrortblsectionsize << 0);
}

/**
 * @brief VMATTRIX_TBL_BASE register definition
 *  VMATTRIX_TBL_BASE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Dmem_Vmatrix_Tbl_Base_Addr 0x0
 * </pre>
 */
#define MACDSP_API1_VMATTRIX_TBL_BASE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000130)
#define MACDSP_API1_VMATTRIX_TBL_BASE_OFFSET      0x00000130
#define MACDSP_API1_VMATTRIX_TBL_BASE_INDEX       0x0000004C
#define MACDSP_API1_VMATTRIX_TBL_BASE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_vmattrix_tbl_base_get(void)
{
	return REG_PL_RD(MACDSP_API1_VMATTRIX_TBL_BASE_ADDR);
}

__INLINE void macdsp_api1_vmattrix_tbl_base_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_VMATTRIX_TBL_BASE_ADDR, value);
}

// field definitions
#define MACDSP_API1_VMATTRIX_TBL_BASE_DMEM_VMATRIX_TBL_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_VMATTRIX_TBL_BASE_DMEM_VMATRIX_TBL_BASE_ADDR_LSB    0
#define MACDSP_API1_VMATTRIX_TBL_BASE_DMEM_VMATRIX_TBL_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_VMATTRIX_TBL_BASE_DMEM_VMATRIX_TBL_BASE_ADDR_RST    0x0

__INLINE uint32_t macdsp_api1_vmattrix_tbl_base_dmem_vmatrix_tbl_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VMATTRIX_TBL_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_vmattrix_tbl_base_dmem_vmatrix_tbl_base_addr_setf(uint32_t dmemvmatrixtblbaseaddr)
{
	ASSERT_ERR((((uint32_t)dmemvmatrixtblbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_VMATTRIX_TBL_BASE_ADDR, (uint32_t)dmemvmatrixtblbaseaddr << 0);
}

/**
 * @brief VMATTRIX_TBL_SIZE register definition
 *  VMATTRIX_TBL_ADDRESS register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Dmem_Vmatrix_Tbl_Section_Size 0x0
 * </pre>
 */
#define MACDSP_API1_VMATTRIX_TBL_SIZE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000134)
#define MACDSP_API1_VMATTRIX_TBL_SIZE_OFFSET      0x00000134
#define MACDSP_API1_VMATTRIX_TBL_SIZE_INDEX       0x0000004D
#define MACDSP_API1_VMATTRIX_TBL_SIZE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_vmattrix_tbl_size_get(void)
{
	return REG_PL_RD(MACDSP_API1_VMATTRIX_TBL_SIZE_ADDR);
}

__INLINE void macdsp_api1_vmattrix_tbl_size_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_VMATTRIX_TBL_SIZE_ADDR, value);
}

// field definitions
#define MACDSP_API1_VMATTRIX_TBL_SIZE_DMEM_VMATRIX_TBL_SECTION_SIZE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_VMATTRIX_TBL_SIZE_DMEM_VMATRIX_TBL_SECTION_SIZE_LSB    0
#define MACDSP_API1_VMATTRIX_TBL_SIZE_DMEM_VMATRIX_TBL_SECTION_SIZE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_VMATTRIX_TBL_SIZE_DMEM_VMATRIX_TBL_SECTION_SIZE_RST    0x0

__INLINE uint32_t macdsp_api1_vmattrix_tbl_size_dmem_vmatrix_tbl_section_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VMATTRIX_TBL_SIZE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_vmattrix_tbl_size_dmem_vmatrix_tbl_section_size_setf(uint32_t dmemvmatrixtblsectionsize)
{
	ASSERT_ERR((((uint32_t)dmemvmatrixtblsectionsize << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_VMATTRIX_TBL_SIZE_ADDR, (uint32_t)dmemvmatrixtblsectionsize << 0);
}

/**
 * @brief CALIB_REQUEST_STRUCTURE_ADDRESS register definition
 *  CALIB_REQUEST_STRUCTURE_ADDRESS register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Structure_Address         0x0
 * </pre>
 */
#define MACDSP_API1_CALIB_REQUEST_STRUCTURE_ADDRESS_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000138)
#define MACDSP_API1_CALIB_REQUEST_STRUCTURE_ADDRESS_OFFSET      0x00000138
#define MACDSP_API1_CALIB_REQUEST_STRUCTURE_ADDRESS_INDEX       0x0000004E
#define MACDSP_API1_CALIB_REQUEST_STRUCTURE_ADDRESS_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_calib_request_structure_address_get(void)
{
	return REG_PL_RD(MACDSP_API1_CALIB_REQUEST_STRUCTURE_ADDRESS_ADDR);
}

__INLINE void macdsp_api1_calib_request_structure_address_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_CALIB_REQUEST_STRUCTURE_ADDRESS_ADDR, value);
}

// field definitions
#define MACDSP_API1_CALIB_REQUEST_STRUCTURE_ADDRESS_STRUCTURE_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_CALIB_REQUEST_STRUCTURE_ADDRESS_STRUCTURE_ADDRESS_LSB    0
#define MACDSP_API1_CALIB_REQUEST_STRUCTURE_ADDRESS_STRUCTURE_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_CALIB_REQUEST_STRUCTURE_ADDRESS_STRUCTURE_ADDRESS_RST    0x0

__INLINE uint32_t macdsp_api1_calib_request_structure_address_structure_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CALIB_REQUEST_STRUCTURE_ADDRESS_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_calib_request_structure_address_structure_address_setf(uint32_t structureaddress)
{
	ASSERT_ERR((((uint32_t)structureaddress << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_CALIB_REQUEST_STRUCTURE_ADDRESS_ADDR, (uint32_t)structureaddress << 0);
}

/**
 * @brief CALIB_REQUEST_STRUCTURE_SIZE register definition
 *  CALIB_REQUEST_STRUCTURE_SIZE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Structure_Size            0x0
 * </pre>
 */
#define MACDSP_API1_CALIB_REQUEST_STRUCTURE_SIZE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000013C)
#define MACDSP_API1_CALIB_REQUEST_STRUCTURE_SIZE_OFFSET      0x0000013C
#define MACDSP_API1_CALIB_REQUEST_STRUCTURE_SIZE_INDEX       0x0000004F
#define MACDSP_API1_CALIB_REQUEST_STRUCTURE_SIZE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_calib_request_structure_size_get(void)
{
	return REG_PL_RD(MACDSP_API1_CALIB_REQUEST_STRUCTURE_SIZE_ADDR);
}

__INLINE void macdsp_api1_calib_request_structure_size_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_CALIB_REQUEST_STRUCTURE_SIZE_ADDR, value);
}

// field definitions
#define MACDSP_API1_CALIB_REQUEST_STRUCTURE_SIZE_STRUCTURE_SIZE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_CALIB_REQUEST_STRUCTURE_SIZE_STRUCTURE_SIZE_LSB    0
#define MACDSP_API1_CALIB_REQUEST_STRUCTURE_SIZE_STRUCTURE_SIZE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_CALIB_REQUEST_STRUCTURE_SIZE_STRUCTURE_SIZE_RST    0x0

__INLINE uint32_t macdsp_api1_calib_request_structure_size_structure_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CALIB_REQUEST_STRUCTURE_SIZE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_calib_request_structure_size_structure_size_setf(uint32_t structuresize)
{
	ASSERT_ERR((((uint32_t)structuresize << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_CALIB_REQUEST_STRUCTURE_SIZE_ADDR, (uint32_t)structuresize << 0);
}

/**
 * @brief CALIB_RESPONSE_STRUCTURE_ADDRESS register definition
 *  CALIB_RESPONSE_STRUCTURE_ADDRESS register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Structure_Address         0x0
 * </pre>
 */
#define MACDSP_API1_CALIB_RESPONSE_STRUCTURE_ADDRESS_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000140)
#define MACDSP_API1_CALIB_RESPONSE_STRUCTURE_ADDRESS_OFFSET      0x00000140
#define MACDSP_API1_CALIB_RESPONSE_STRUCTURE_ADDRESS_INDEX       0x00000050
#define MACDSP_API1_CALIB_RESPONSE_STRUCTURE_ADDRESS_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_calib_response_structure_address_get(void)
{
	return REG_PL_RD(MACDSP_API1_CALIB_RESPONSE_STRUCTURE_ADDRESS_ADDR);
}

__INLINE void macdsp_api1_calib_response_structure_address_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_CALIB_RESPONSE_STRUCTURE_ADDRESS_ADDR, value);
}

// field definitions
#define MACDSP_API1_CALIB_RESPONSE_STRUCTURE_ADDRESS_STRUCTURE_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_CALIB_RESPONSE_STRUCTURE_ADDRESS_STRUCTURE_ADDRESS_LSB    0
#define MACDSP_API1_CALIB_RESPONSE_STRUCTURE_ADDRESS_STRUCTURE_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_CALIB_RESPONSE_STRUCTURE_ADDRESS_STRUCTURE_ADDRESS_RST    0x0

__INLINE uint32_t macdsp_api1_calib_response_structure_address_structure_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CALIB_RESPONSE_STRUCTURE_ADDRESS_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_calib_response_structure_address_structure_address_setf(uint32_t structureaddress)
{
	ASSERT_ERR((((uint32_t)structureaddress << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_CALIB_RESPONSE_STRUCTURE_ADDRESS_ADDR, (uint32_t)structureaddress << 0);
}

/**
 * @brief CALIB_RESPONSE_STRUCTURE_SIZE register definition
 *  CALIB_RESPONSE_STRUCTURE_SIZE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Structure_Size            0x0
 * </pre>
 */
#define MACDSP_API1_CALIB_RESPONSE_STRUCTURE_SIZE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000144)
#define MACDSP_API1_CALIB_RESPONSE_STRUCTURE_SIZE_OFFSET      0x00000144
#define MACDSP_API1_CALIB_RESPONSE_STRUCTURE_SIZE_INDEX       0x00000051
#define MACDSP_API1_CALIB_RESPONSE_STRUCTURE_SIZE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_calib_response_structure_size_get(void)
{
	return REG_PL_RD(MACDSP_API1_CALIB_RESPONSE_STRUCTURE_SIZE_ADDR);
}

__INLINE void macdsp_api1_calib_response_structure_size_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_CALIB_RESPONSE_STRUCTURE_SIZE_ADDR, value);
}

// field definitions
#define MACDSP_API1_CALIB_RESPONSE_STRUCTURE_SIZE_STRUCTURE_SIZE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_CALIB_RESPONSE_STRUCTURE_SIZE_STRUCTURE_SIZE_LSB    0
#define MACDSP_API1_CALIB_RESPONSE_STRUCTURE_SIZE_STRUCTURE_SIZE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_CALIB_RESPONSE_STRUCTURE_SIZE_STRUCTURE_SIZE_RST    0x0

__INLINE uint32_t macdsp_api1_calib_response_structure_size_structure_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CALIB_RESPONSE_STRUCTURE_SIZE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_calib_response_structure_size_structure_size_setf(uint32_t structuresize)
{
	ASSERT_ERR((((uint32_t)structuresize << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_CALIB_RESPONSE_STRUCTURE_SIZE_ADDR, (uint32_t)structuresize << 0);
}

/**
 * @brief BFEE_PBD_1_ADDRESS register definition
 *  BFR PBD1 location in DMEM register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 BFEE_PBD1_ADDRESS         0x0
 * </pre>
 */
#define MACDSP_API1_BFEE_PBD_1_ADDRESS_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000148)
#define MACDSP_API1_BFEE_PBD_1_ADDRESS_OFFSET      0x00000148
#define MACDSP_API1_BFEE_PBD_1_ADDRESS_INDEX       0x00000052
#define MACDSP_API1_BFEE_PBD_1_ADDRESS_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_bfee_pbd_1_address_get(void)
{
	return REG_PL_RD(MACDSP_API1_BFEE_PBD_1_ADDRESS_ADDR);
}

__INLINE void macdsp_api1_bfee_pbd_1_address_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_BFEE_PBD_1_ADDRESS_ADDR, value);
}

// field definitions
#define MACDSP_API1_BFEE_PBD_1_ADDRESS_BFEE_PBD_1_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_BFEE_PBD_1_ADDRESS_BFEE_PBD_1_ADDRESS_LSB    0
#define MACDSP_API1_BFEE_PBD_1_ADDRESS_BFEE_PBD_1_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_BFEE_PBD_1_ADDRESS_BFEE_PBD_1_ADDRESS_RST    0x0

__INLINE uint32_t macdsp_api1_bfee_pbd_1_address_bfee_pbd_1_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_BFEE_PBD_1_ADDRESS_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_bfee_pbd_1_address_bfee_pbd_1_address_setf(uint32_t bfeepbd1address)
{
	ASSERT_ERR((((uint32_t)bfeepbd1address << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_BFEE_PBD_1_ADDRESS_ADDR, (uint32_t)bfeepbd1address << 0);
}

/**
 * @brief ATHD_ADDRESS register definition
 *  BFR ATHD location in DMEM register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 ATHD_ADDRESS              0x0
 * </pre>
 */
#define MACDSP_API1_ATHD_ADDRESS_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000014C)
#define MACDSP_API1_ATHD_ADDRESS_OFFSET      0x0000014C
#define MACDSP_API1_ATHD_ADDRESS_INDEX       0x00000053
#define MACDSP_API1_ATHD_ADDRESS_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_athd_address_get(void)
{
	return REG_PL_RD(MACDSP_API1_ATHD_ADDRESS_ADDR);
}

__INLINE void macdsp_api1_athd_address_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_ATHD_ADDRESS_ADDR, value);
}

// field definitions
#define MACDSP_API1_ATHD_ADDRESS_ATHD_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_ATHD_ADDRESS_ATHD_ADDRESS_LSB    0
#define MACDSP_API1_ATHD_ADDRESS_ATHD_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_ATHD_ADDRESS_ATHD_ADDRESS_RST    0x0

__INLINE uint32_t macdsp_api1_athd_address_athd_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_ATHD_ADDRESS_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_athd_address_athd_address_setf(uint32_t athdaddress)
{
	ASSERT_ERR((((uint32_t)athdaddress << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_ATHD_ADDRESS_ADDR, (uint32_t)athdaddress << 0);
}

/**
 * @brief THD_ADDRESS register definition
 *  BFR THD location in DMEM register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 THD_ADDRESS               0x0
 * </pre>
 */
#define MACDSP_API1_THD_ADDRESS_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000150)
#define MACDSP_API1_THD_ADDRESS_OFFSET      0x00000150
#define MACDSP_API1_THD_ADDRESS_INDEX       0x00000054
#define MACDSP_API1_THD_ADDRESS_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_thd_address_get(void)
{
	return REG_PL_RD(MACDSP_API1_THD_ADDRESS_ADDR);
}

__INLINE void macdsp_api1_thd_address_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_THD_ADDRESS_ADDR, value);
}

// field definitions
#define MACDSP_API1_THD_ADDRESS_THD_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_THD_ADDRESS_THD_ADDRESS_LSB    0
#define MACDSP_API1_THD_ADDRESS_THD_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_THD_ADDRESS_THD_ADDRESS_RST    0x0

__INLINE uint32_t macdsp_api1_thd_address_thd_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_THD_ADDRESS_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_thd_address_thd_address_setf(uint32_t thdaddress)
{
	ASSERT_ERR((((uint32_t)thdaddress << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_THD_ADDRESS_ADDR, (uint32_t)thdaddress << 0);
}

/**
 * @brief TXVEC_PHY_ERROR_TBL_BASE register definition
 *  TxVector placement on DMEM register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Tx_Vector_Tbl_Base_Addr   0x0
 * </pre>
 */
#define MACDSP_API1_TXVEC_PHY_ERROR_TBL_BASE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000154)
#define MACDSP_API1_TXVEC_PHY_ERROR_TBL_BASE_OFFSET      0x00000154
#define MACDSP_API1_TXVEC_PHY_ERROR_TBL_BASE_INDEX       0x00000055
#define MACDSP_API1_TXVEC_PHY_ERROR_TBL_BASE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_txvec_phy_error_tbl_base_get(void)
{
	return REG_PL_RD(MACDSP_API1_TXVEC_PHY_ERROR_TBL_BASE_ADDR);
}

__INLINE void macdsp_api1_txvec_phy_error_tbl_base_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TXVEC_PHY_ERROR_TBL_BASE_ADDR, value);
}

// field definitions
#define MACDSP_API1_TXVEC_PHY_ERROR_TBL_BASE_TX_VECTOR_TBL_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_TXVEC_PHY_ERROR_TBL_BASE_TX_VECTOR_TBL_BASE_ADDR_LSB    0
#define MACDSP_API1_TXVEC_PHY_ERROR_TBL_BASE_TX_VECTOR_TBL_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_TXVEC_PHY_ERROR_TBL_BASE_TX_VECTOR_TBL_BASE_ADDR_RST    0x0

__INLINE uint32_t macdsp_api1_txvec_phy_error_tbl_base_tx_vector_tbl_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TXVEC_PHY_ERROR_TBL_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_txvec_phy_error_tbl_base_tx_vector_tbl_base_addr_setf(uint32_t txvectortblbaseaddr)
{
	ASSERT_ERR((((uint32_t)txvectortblbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TXVEC_PHY_ERROR_TBL_BASE_ADDR, (uint32_t)txvectortblbaseaddr << 0);
}

/**
 * @brief TXVEC_PHY_ERROR_TBL_SIZE register definition
 *  V-matrix placement on DMEM register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Tx_Vector_Tbl_Section_Size 0x0
 * </pre>
 */
#define MACDSP_API1_TXVEC_PHY_ERROR_TBL_SIZE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000158)
#define MACDSP_API1_TXVEC_PHY_ERROR_TBL_SIZE_OFFSET      0x00000158
#define MACDSP_API1_TXVEC_PHY_ERROR_TBL_SIZE_INDEX       0x00000056
#define MACDSP_API1_TXVEC_PHY_ERROR_TBL_SIZE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_txvec_phy_error_tbl_size_get(void)
{
	return REG_PL_RD(MACDSP_API1_TXVEC_PHY_ERROR_TBL_SIZE_ADDR);
}

__INLINE void macdsp_api1_txvec_phy_error_tbl_size_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TXVEC_PHY_ERROR_TBL_SIZE_ADDR, value);
}

// field definitions
#define MACDSP_API1_TXVEC_PHY_ERROR_TBL_SIZE_TX_VECTOR_TBL_SECTION_SIZE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_TXVEC_PHY_ERROR_TBL_SIZE_TX_VECTOR_TBL_SECTION_SIZE_LSB    0
#define MACDSP_API1_TXVEC_PHY_ERROR_TBL_SIZE_TX_VECTOR_TBL_SECTION_SIZE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_TXVEC_PHY_ERROR_TBL_SIZE_TX_VECTOR_TBL_SECTION_SIZE_RST    0x0

__INLINE uint32_t macdsp_api1_txvec_phy_error_tbl_size_tx_vector_tbl_section_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TXVEC_PHY_ERROR_TBL_SIZE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_txvec_phy_error_tbl_size_tx_vector_tbl_section_size_setf(uint32_t txvectortblsectionsize)
{
	ASSERT_ERR((((uint32_t)txvectortblsectionsize << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TXVEC_PHY_ERROR_TBL_SIZE_ADDR, (uint32_t)txvectortblsectionsize << 0);
}

/**
 * @brief DSP_2_MAC_MAILBOX_BASE register definition
 *  DSP2MAC_MAILBOX_BASE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Dsp2_Mac_Mail_Box_Base_Addr 0x0
 * </pre>
 */
#define MACDSP_API1_DSP_2_MAC_MAILBOX_BASE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000160)
#define MACDSP_API1_DSP_2_MAC_MAILBOX_BASE_OFFSET      0x00000160
#define MACDSP_API1_DSP_2_MAC_MAILBOX_BASE_INDEX       0x00000058
#define MACDSP_API1_DSP_2_MAC_MAILBOX_BASE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_dsp_2_mac_mailbox_base_get(void)
{
	return REG_PL_RD(MACDSP_API1_DSP_2_MAC_MAILBOX_BASE_ADDR);
}

__INLINE void macdsp_api1_dsp_2_mac_mailbox_base_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_DSP_2_MAC_MAILBOX_BASE_ADDR, value);
}

// field definitions
#define MACDSP_API1_DSP_2_MAC_MAILBOX_BASE_DSP_2_MAC_MAIL_BOX_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_DSP_2_MAC_MAILBOX_BASE_DSP_2_MAC_MAIL_BOX_BASE_ADDR_LSB    0
#define MACDSP_API1_DSP_2_MAC_MAILBOX_BASE_DSP_2_MAC_MAIL_BOX_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_DSP_2_MAC_MAILBOX_BASE_DSP_2_MAC_MAIL_BOX_BASE_ADDR_RST    0x0

__INLINE uint32_t macdsp_api1_dsp_2_mac_mailbox_base_dsp_2_mac_mail_box_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_2_MAC_MAILBOX_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_dsp_2_mac_mailbox_base_dsp_2_mac_mail_box_base_addr_setf(uint32_t dsp2macmailboxbaseaddr)
{
	ASSERT_ERR((((uint32_t)dsp2macmailboxbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_DSP_2_MAC_MAILBOX_BASE_ADDR, (uint32_t)dsp2macmailboxbaseaddr << 0);
}

/**
 * @brief DSP_2_MAC_MAILBOX_SIZE register definition
 *  DSP2MAC_MAILBOX_SIZE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 message_size              0x0
 *    15:00 mailbox_size              0x0
 * </pre>
 */
#define MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000164)
#define MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_OFFSET      0x00000164
#define MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_INDEX       0x00000059
#define MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_dsp_2_mac_mailbox_size_get(void)
{
	return REG_PL_RD(MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_ADDR);
}

__INLINE void macdsp_api1_dsp_2_mac_mailbox_size_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_ADDR, value);
}

// field definitions
#define MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_MESSAGE_SIZE_MASK    ((uint32_t)0xFFFF0000)
#define MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_MESSAGE_SIZE_LSB    16
#define MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_MESSAGE_SIZE_WIDTH    ((uint32_t)0x00000010)
#define MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_MAILBOX_SIZE_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_MAILBOX_SIZE_LSB    0
#define MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_MAILBOX_SIZE_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_MESSAGE_SIZE_RST    0x0
#define MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_MAILBOX_SIZE_RST    0x0

__INLINE void macdsp_api1_dsp_2_mac_mailbox_size_pack(uint16_t message_size, uint16_t mailbox_size)
{
	ASSERT_ERR((((uint32_t)message_size << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)mailbox_size << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_ADDR,  ((uint32_t)message_size << 16) |((uint32_t)mailbox_size << 0));
}

__INLINE void macdsp_api1_dsp_2_mac_mailbox_size_unpack(uint16_t* message_size, uint16_t* mailbox_size)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_ADDR);

	*message_size = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*mailbox_size = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t macdsp_api1_dsp_2_mac_mailbox_size_message_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void macdsp_api1_dsp_2_mac_mailbox_size_message_size_setf(uint16_t messagesize)
{
	ASSERT_ERR((((uint32_t)messagesize << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_ADDR, (REG_PL_RD(MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)messagesize <<16));
}
__INLINE uint16_t macdsp_api1_dsp_2_mac_mailbox_size_mailbox_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void macdsp_api1_dsp_2_mac_mailbox_size_mailbox_size_setf(uint16_t mailboxsize)
{
	ASSERT_ERR((((uint32_t)mailboxsize << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_ADDR, (REG_PL_RD(MACDSP_API1_DSP_2_MAC_MAILBOX_SIZE_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)mailboxsize <<0));
}

/**
 * @brief DSP_2_MAC_MAILBOX_RD_IND register definition
 *  DSP2MAC_MAILBOX_RD_IND register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Dsp2_Mac_Mail_Box_Read_Idx_Address 0x0
 * </pre>
 */
#define MACDSP_API1_DSP_2_MAC_MAILBOX_RD_IND_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000168)
#define MACDSP_API1_DSP_2_MAC_MAILBOX_RD_IND_OFFSET      0x00000168
#define MACDSP_API1_DSP_2_MAC_MAILBOX_RD_IND_INDEX       0x0000005A
#define MACDSP_API1_DSP_2_MAC_MAILBOX_RD_IND_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_dsp_2_mac_mailbox_rd_ind_get(void)
{
	return REG_PL_RD(MACDSP_API1_DSP_2_MAC_MAILBOX_RD_IND_ADDR);
}

__INLINE void macdsp_api1_dsp_2_mac_mailbox_rd_ind_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_DSP_2_MAC_MAILBOX_RD_IND_ADDR, value);
}

// field definitions
#define MACDSP_API1_DSP_2_MAC_MAILBOX_RD_IND_DSP_2_MAC_MAIL_BOX_READ_IDX_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_DSP_2_MAC_MAILBOX_RD_IND_DSP_2_MAC_MAIL_BOX_READ_IDX_ADDRESS_LSB    0
#define MACDSP_API1_DSP_2_MAC_MAILBOX_RD_IND_DSP_2_MAC_MAIL_BOX_READ_IDX_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_DSP_2_MAC_MAILBOX_RD_IND_DSP_2_MAC_MAIL_BOX_READ_IDX_ADDRESS_RST    0x0

__INLINE uint32_t macdsp_api1_dsp_2_mac_mailbox_rd_ind_dsp_2_mac_mail_box_read_idx_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_2_MAC_MAILBOX_RD_IND_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_dsp_2_mac_mailbox_rd_ind_dsp_2_mac_mail_box_read_idx_address_setf(uint32_t dsp2macmailboxreadidxaddress)
{
	ASSERT_ERR((((uint32_t)dsp2macmailboxreadidxaddress << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_DSP_2_MAC_MAILBOX_RD_IND_ADDR, (uint32_t)dsp2macmailboxreadidxaddress << 0);
}

/**
 * @brief DSP_2_MAC_MAILBOX_WR_IND register definition
 *  DSP2MAC_MAILBOX_WR_IND register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Dsp2_Mac_Mail_Box_Write_Idx_Address 0x0
 * </pre>
 */
#define MACDSP_API1_DSP_2_MAC_MAILBOX_WR_IND_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000016C)
#define MACDSP_API1_DSP_2_MAC_MAILBOX_WR_IND_OFFSET      0x0000016C
#define MACDSP_API1_DSP_2_MAC_MAILBOX_WR_IND_INDEX       0x0000005B
#define MACDSP_API1_DSP_2_MAC_MAILBOX_WR_IND_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_dsp_2_mac_mailbox_wr_ind_get(void)
{
	return REG_PL_RD(MACDSP_API1_DSP_2_MAC_MAILBOX_WR_IND_ADDR);
}

__INLINE void macdsp_api1_dsp_2_mac_mailbox_wr_ind_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_DSP_2_MAC_MAILBOX_WR_IND_ADDR, value);
}

// field definitions
#define MACDSP_API1_DSP_2_MAC_MAILBOX_WR_IND_DSP_2_MAC_MAIL_BOX_WRITE_IDX_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_DSP_2_MAC_MAILBOX_WR_IND_DSP_2_MAC_MAIL_BOX_WRITE_IDX_ADDRESS_LSB    0
#define MACDSP_API1_DSP_2_MAC_MAILBOX_WR_IND_DSP_2_MAC_MAIL_BOX_WRITE_IDX_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_DSP_2_MAC_MAILBOX_WR_IND_DSP_2_MAC_MAIL_BOX_WRITE_IDX_ADDRESS_RST    0x0

__INLINE uint32_t macdsp_api1_dsp_2_mac_mailbox_wr_ind_dsp_2_mac_mail_box_write_idx_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_2_MAC_MAILBOX_WR_IND_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_dsp_2_mac_mailbox_wr_ind_dsp_2_mac_mail_box_write_idx_address_setf(uint32_t dsp2macmailboxwriteidxaddress)
{
	ASSERT_ERR((((uint32_t)dsp2macmailboxwriteidxaddress << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_DSP_2_MAC_MAILBOX_WR_IND_ADDR, (uint32_t)dsp2macmailboxwriteidxaddress << 0);
}

/**
 * @brief MAC_2_DSP_MAILBOX_BASE register definition
 *  MAC2DSP_MAILBOX_SIZE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Mac2_Dsp_Mail_Box_Base_Addr 0x0
 * </pre>
 */
#define MACDSP_API1_MAC_2_DSP_MAILBOX_BASE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000170)
#define MACDSP_API1_MAC_2_DSP_MAILBOX_BASE_OFFSET      0x00000170
#define MACDSP_API1_MAC_2_DSP_MAILBOX_BASE_INDEX       0x0000005C
#define MACDSP_API1_MAC_2_DSP_MAILBOX_BASE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_mac_2_dsp_mailbox_base_get(void)
{
	return REG_PL_RD(MACDSP_API1_MAC_2_DSP_MAILBOX_BASE_ADDR);
}

__INLINE void macdsp_api1_mac_2_dsp_mailbox_base_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_MAC_2_DSP_MAILBOX_BASE_ADDR, value);
}

// field definitions
#define MACDSP_API1_MAC_2_DSP_MAILBOX_BASE_MAC_2_DSP_MAIL_BOX_BASE_ADDR_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_MAC_2_DSP_MAILBOX_BASE_MAC_2_DSP_MAIL_BOX_BASE_ADDR_LSB    0
#define MACDSP_API1_MAC_2_DSP_MAILBOX_BASE_MAC_2_DSP_MAIL_BOX_BASE_ADDR_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_MAC_2_DSP_MAILBOX_BASE_MAC_2_DSP_MAIL_BOX_BASE_ADDR_RST    0x0

__INLINE uint32_t macdsp_api1_mac_2_dsp_mailbox_base_mac_2_dsp_mail_box_base_addr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_2_DSP_MAILBOX_BASE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_mac_2_dsp_mailbox_base_mac_2_dsp_mail_box_base_addr_setf(uint32_t mac2dspmailboxbaseaddr)
{
	ASSERT_ERR((((uint32_t)mac2dspmailboxbaseaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_2_DSP_MAILBOX_BASE_ADDR, (uint32_t)mac2dspmailboxbaseaddr << 0);
}

/**
 * @brief MAC_2_DSP_MAILBOX_SIZE register definition
 *  MAC2DSP _MAILBOX_SIZE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 message_size              0x0
 *    15:00 mailbox_size              0x0
 * </pre>
 */
#define MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000174)
#define MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_OFFSET      0x00000174
#define MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_INDEX       0x0000005D
#define MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_mac_2_dsp_mailbox_size_get(void)
{
	return REG_PL_RD(MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_ADDR);
}

__INLINE void macdsp_api1_mac_2_dsp_mailbox_size_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_ADDR, value);
}

// field definitions
#define MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_MESSAGE_SIZE_MASK    ((uint32_t)0xFFFF0000)
#define MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_MESSAGE_SIZE_LSB    16
#define MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_MESSAGE_SIZE_WIDTH    ((uint32_t)0x00000010)
#define MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_MAILBOX_SIZE_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_MAILBOX_SIZE_LSB    0
#define MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_MAILBOX_SIZE_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_MESSAGE_SIZE_RST    0x0
#define MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_MAILBOX_SIZE_RST    0x0

__INLINE void macdsp_api1_mac_2_dsp_mailbox_size_pack(uint16_t message_size, uint16_t mailbox_size)
{
	ASSERT_ERR((((uint32_t)message_size << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)mailbox_size << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_ADDR,  ((uint32_t)message_size << 16) |((uint32_t)mailbox_size << 0));
}

__INLINE void macdsp_api1_mac_2_dsp_mailbox_size_unpack(uint16_t* message_size, uint16_t* mailbox_size)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_ADDR);

	*message_size = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*mailbox_size = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t macdsp_api1_mac_2_dsp_mailbox_size_message_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void macdsp_api1_mac_2_dsp_mailbox_size_message_size_setf(uint16_t messagesize)
{
	ASSERT_ERR((((uint32_t)messagesize << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_ADDR, (REG_PL_RD(MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)messagesize <<16));
}
__INLINE uint16_t macdsp_api1_mac_2_dsp_mailbox_size_mailbox_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void macdsp_api1_mac_2_dsp_mailbox_size_mailbox_size_setf(uint16_t mailboxsize)
{
	ASSERT_ERR((((uint32_t)mailboxsize << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_ADDR, (REG_PL_RD(MACDSP_API1_MAC_2_DSP_MAILBOX_SIZE_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)mailboxsize <<0));
}

/**
 * @brief MAC_2_DSP_MAILBOX_RD_IND register definition
 *  MAC2DSP_MAILBOX_RD_IND register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Mac2_Dsp_Mail_Box_Read_Idx_Address 0x0
 * </pre>
 */
#define MACDSP_API1_MAC_2_DSP_MAILBOX_RD_IND_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000178)
#define MACDSP_API1_MAC_2_DSP_MAILBOX_RD_IND_OFFSET      0x00000178
#define MACDSP_API1_MAC_2_DSP_MAILBOX_RD_IND_INDEX       0x0000005E
#define MACDSP_API1_MAC_2_DSP_MAILBOX_RD_IND_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_mac_2_dsp_mailbox_rd_ind_get(void)
{
	return REG_PL_RD(MACDSP_API1_MAC_2_DSP_MAILBOX_RD_IND_ADDR);
}

__INLINE void macdsp_api1_mac_2_dsp_mailbox_rd_ind_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_MAC_2_DSP_MAILBOX_RD_IND_ADDR, value);
}

// field definitions
#define MACDSP_API1_MAC_2_DSP_MAILBOX_RD_IND_MAC_2_DSP_MAIL_BOX_READ_IDX_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_MAC_2_DSP_MAILBOX_RD_IND_MAC_2_DSP_MAIL_BOX_READ_IDX_ADDRESS_LSB    0
#define MACDSP_API1_MAC_2_DSP_MAILBOX_RD_IND_MAC_2_DSP_MAIL_BOX_READ_IDX_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_MAC_2_DSP_MAILBOX_RD_IND_MAC_2_DSP_MAIL_BOX_READ_IDX_ADDRESS_RST    0x0

__INLINE uint32_t macdsp_api1_mac_2_dsp_mailbox_rd_ind_mac_2_dsp_mail_box_read_idx_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_2_DSP_MAILBOX_RD_IND_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_mac_2_dsp_mailbox_rd_ind_mac_2_dsp_mail_box_read_idx_address_setf(uint32_t mac2dspmailboxreadidxaddress)
{
	ASSERT_ERR((((uint32_t)mac2dspmailboxreadidxaddress << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_2_DSP_MAILBOX_RD_IND_ADDR, (uint32_t)mac2dspmailboxreadidxaddress << 0);
}

/**
 * @brief MAC_2_DSP_MAILBOX_WR_IND register definition
 *  MAC2DSP_MAILBOX_WR_IND register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Mac2_Dsp_Mail_Box_Write_Idx_Address 0x0
 * </pre>
 */
#define MACDSP_API1_MAC_2_DSP_MAILBOX_WR_IND_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000017C)
#define MACDSP_API1_MAC_2_DSP_MAILBOX_WR_IND_OFFSET      0x0000017C
#define MACDSP_API1_MAC_2_DSP_MAILBOX_WR_IND_INDEX       0x0000005F
#define MACDSP_API1_MAC_2_DSP_MAILBOX_WR_IND_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_mac_2_dsp_mailbox_wr_ind_get(void)
{
	return REG_PL_RD(MACDSP_API1_MAC_2_DSP_MAILBOX_WR_IND_ADDR);
}

__INLINE void macdsp_api1_mac_2_dsp_mailbox_wr_ind_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_MAC_2_DSP_MAILBOX_WR_IND_ADDR, value);
}

// field definitions
#define MACDSP_API1_MAC_2_DSP_MAILBOX_WR_IND_MAC_2_DSP_MAIL_BOX_WRITE_IDX_ADDRESS_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_MAC_2_DSP_MAILBOX_WR_IND_MAC_2_DSP_MAIL_BOX_WRITE_IDX_ADDRESS_LSB    0
#define MACDSP_API1_MAC_2_DSP_MAILBOX_WR_IND_MAC_2_DSP_MAIL_BOX_WRITE_IDX_ADDRESS_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_MAC_2_DSP_MAILBOX_WR_IND_MAC_2_DSP_MAIL_BOX_WRITE_IDX_ADDRESS_RST    0x0

__INLINE uint32_t macdsp_api1_mac_2_dsp_mailbox_wr_ind_mac_2_dsp_mail_box_write_idx_address_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MAC_2_DSP_MAILBOX_WR_IND_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_mac_2_dsp_mailbox_wr_ind_mac_2_dsp_mail_box_write_idx_address_setf(uint32_t mac2dspmailboxwriteidxaddress)
{
	ASSERT_ERR((((uint32_t)mac2dspmailboxwriteidxaddress << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_MAC_2_DSP_MAILBOX_WR_IND_ADDR, (uint32_t)mac2dspmailboxwriteidxaddress << 0);
}

/**
 * @brief CAL_ERROR_REASON_ADDRESS register definition
 *  CAL_ERROR_REASON_ADDRESS register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 * </pre>
 */
#define MACDSP_API1_CAL_ERROR_REASON_ADDRESS_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000180)
#define MACDSP_API1_CAL_ERROR_REASON_ADDRESS_OFFSET      0x00000180
#define MACDSP_API1_CAL_ERROR_REASON_ADDRESS_INDEX       0x00000060
#define MACDSP_API1_CAL_ERROR_REASON_ADDRESS_RESET       0x00000000

// field definitions



/**
 * @brief CAL_ERROR_REASON_SIZE register definition
 *  CAL_ERROR_REASON_SIZE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 * </pre>
 */
#define MACDSP_API1_CAL_ERROR_REASON_SIZE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000184)
#define MACDSP_API1_CAL_ERROR_REASON_SIZE_OFFSET      0x00000184
#define MACDSP_API1_CAL_ERROR_REASON_SIZE_INDEX       0x00000061
#define MACDSP_API1_CAL_ERROR_REASON_SIZE_RESET       0x00000000

// field definitions



/**
 * @brief AGC_RAMP_UP_VALUE register definition
 *  AGC_RAMP_UP_VALUE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 agc_ramp_up_value         0x0
 * </pre>
 */
#define MACDSP_API1_AGC_RAMP_UP_VALUE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000188)
#define MACDSP_API1_AGC_RAMP_UP_VALUE_OFFSET      0x00000188
#define MACDSP_API1_AGC_RAMP_UP_VALUE_INDEX       0x00000062
#define MACDSP_API1_AGC_RAMP_UP_VALUE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_agc_ramp_up_value_get(void)
{
	return REG_PL_RD(MACDSP_API1_AGC_RAMP_UP_VALUE_ADDR);
}

__INLINE void macdsp_api1_agc_ramp_up_value_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_AGC_RAMP_UP_VALUE_ADDR, value);
}

// field definitions
#define MACDSP_API1_AGC_RAMP_UP_VALUE_AGC_RAMP_UP_VALUE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_AGC_RAMP_UP_VALUE_AGC_RAMP_UP_VALUE_LSB    0
#define MACDSP_API1_AGC_RAMP_UP_VALUE_AGC_RAMP_UP_VALUE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_AGC_RAMP_UP_VALUE_AGC_RAMP_UP_VALUE_RST    0x0

__INLINE uint32_t macdsp_api1_agc_ramp_up_value_agc_ramp_up_value_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_AGC_RAMP_UP_VALUE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_agc_ramp_up_value_agc_ramp_up_value_setf(uint32_t agcrampupvalue)
{
	ASSERT_ERR((((uint32_t)agcrampupvalue << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_AGC_RAMP_UP_VALUE_ADDR, (uint32_t)agcrampupvalue << 0);
}

/**
 * @brief IDLE_COUNTER register definition
 *  IdleCounter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Idle_Counter              0x0
 * </pre>
 */
#define MACDSP_API1_IDLE_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000300)
#define MACDSP_API1_IDLE_COUNTER_OFFSET      0x00000300
#define MACDSP_API1_IDLE_COUNTER_INDEX       0x000000C0
#define MACDSP_API1_IDLE_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_idle_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_IDLE_COUNTER_ADDR);
}

__INLINE void macdsp_api1_idle_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_IDLE_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_IDLE_COUNTER_IDLE_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_IDLE_COUNTER_IDLE_COUNTER_LSB    0
#define MACDSP_API1_IDLE_COUNTER_IDLE_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_IDLE_COUNTER_IDLE_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_idle_counter_idle_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_IDLE_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_idle_counter_idle_counter_setf(uint16_t idlecounter)
{
	ASSERT_ERR((((uint32_t)idlecounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_IDLE_COUNTER_ADDR, (uint32_t)idlecounter << 0);
}

/**
 * @brief TFU_ERR_COUNTER register definition
 *  TfuErrCounter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Tfu_Err_Counter           0x0
 * </pre>
 */
#define MACDSP_API1_TFU_ERR_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000302)
#define MACDSP_API1_TFU_ERR_COUNTER_OFFSET      0x00000302
#define MACDSP_API1_TFU_ERR_COUNTER_INDEX       0x000000C0
#define MACDSP_API1_TFU_ERR_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tfu_err_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_TFU_ERR_COUNTER_ADDR);
}

__INLINE void macdsp_api1_tfu_err_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TFU_ERR_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_TFU_ERR_COUNTER_TFU_ERR_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_TFU_ERR_COUNTER_TFU_ERR_COUNTER_LSB    0
#define MACDSP_API1_TFU_ERR_COUNTER_TFU_ERR_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_TFU_ERR_COUNTER_TFU_ERR_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_tfu_err_counter_tfu_err_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TFU_ERR_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_tfu_err_counter_tfu_err_counter_setf(uint16_t tfuerrcounter)
{
	ASSERT_ERR((((uint32_t)tfuerrcounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TFU_ERR_COUNTER_ADDR, (uint32_t)tfuerrcounter << 0);
}

/**
 * @brief RX_TERMINATE_TOTAL_COUNTER register definition
 *  RxTerminateTotalCounter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Total_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TOTAL_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000304)
#define MACDSP_API1_RX_TERMINATE_TOTAL_COUNTER_OFFSET      0x00000304
#define MACDSP_API1_RX_TERMINATE_TOTAL_COUNTER_INDEX       0x000000C1
#define MACDSP_API1_RX_TERMINATE_TOTAL_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_total_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TOTAL_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_total_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TOTAL_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TOTAL_COUNTER_RX_TERMINATE_TOTAL_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TOTAL_COUNTER_RX_TERMINATE_TOTAL_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TOTAL_COUNTER_RX_TERMINATE_TOTAL_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TOTAL_COUNTER_RX_TERMINATE_TOTAL_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_total_counter_rx_terminate_total_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TOTAL_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_total_counter_rx_terminate_total_counter_setf(uint16_t rxterminatetotalcounter)
{
	ASSERT_ERR((((uint32_t)rxterminatetotalcounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TOTAL_COUNTER_ADDR, (uint32_t)rxterminatetotalcounter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_0_COUNTER register definition
 *  RxTerminateType0Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type0_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_0_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000306)
#define MACDSP_API1_RX_TERMINATE_TYPE_0_COUNTER_OFFSET      0x00000306
#define MACDSP_API1_RX_TERMINATE_TYPE_0_COUNTER_INDEX       0x000000C1
#define MACDSP_API1_RX_TERMINATE_TYPE_0_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_0_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_0_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_0_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_0_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_0_COUNTER_RX_TERMINATE_TYPE_0_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_0_COUNTER_RX_TERMINATE_TYPE_0_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_0_COUNTER_RX_TERMINATE_TYPE_0_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_0_COUNTER_RX_TERMINATE_TYPE_0_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_0_counter_rx_terminate_type_0_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_0_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_0_counter_rx_terminate_type_0_counter_setf(uint16_t rxterminatetype0counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype0counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_0_COUNTER_ADDR, (uint32_t)rxterminatetype0counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_1_COUNTER register definition
 *  RxTerminateType1Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type1_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_1_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000308)
#define MACDSP_API1_RX_TERMINATE_TYPE_1_COUNTER_OFFSET      0x00000308
#define MACDSP_API1_RX_TERMINATE_TYPE_1_COUNTER_INDEX       0x000000C2
#define MACDSP_API1_RX_TERMINATE_TYPE_1_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_1_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_1_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_1_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_1_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_1_COUNTER_RX_TERMINATE_TYPE_1_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_1_COUNTER_RX_TERMINATE_TYPE_1_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_1_COUNTER_RX_TERMINATE_TYPE_1_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_1_COUNTER_RX_TERMINATE_TYPE_1_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_1_counter_rx_terminate_type_1_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_1_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_1_counter_rx_terminate_type_1_counter_setf(uint16_t rxterminatetype1counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype1counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_1_COUNTER_ADDR, (uint32_t)rxterminatetype1counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_2_COUNTER register definition
 *  RxTerminateType2Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type2_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_2_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000030A)
#define MACDSP_API1_RX_TERMINATE_TYPE_2_COUNTER_OFFSET      0x0000030A
#define MACDSP_API1_RX_TERMINATE_TYPE_2_COUNTER_INDEX       0x000000C2
#define MACDSP_API1_RX_TERMINATE_TYPE_2_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_2_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_2_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_2_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_2_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_2_COUNTER_RX_TERMINATE_TYPE_2_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_2_COUNTER_RX_TERMINATE_TYPE_2_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_2_COUNTER_RX_TERMINATE_TYPE_2_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_2_COUNTER_RX_TERMINATE_TYPE_2_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_2_counter_rx_terminate_type_2_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_2_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_2_counter_rx_terminate_type_2_counter_setf(uint16_t rxterminatetype2counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype2counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_2_COUNTER_ADDR, (uint32_t)rxterminatetype2counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_3_COUNTER register definition
 *  RxTerminateType3Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type3_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_3_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000030C)
#define MACDSP_API1_RX_TERMINATE_TYPE_3_COUNTER_OFFSET      0x0000030C
#define MACDSP_API1_RX_TERMINATE_TYPE_3_COUNTER_INDEX       0x000000C3
#define MACDSP_API1_RX_TERMINATE_TYPE_3_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_3_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_3_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_3_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_3_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_3_COUNTER_RX_TERMINATE_TYPE_3_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_3_COUNTER_RX_TERMINATE_TYPE_3_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_3_COUNTER_RX_TERMINATE_TYPE_3_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_3_COUNTER_RX_TERMINATE_TYPE_3_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_3_counter_rx_terminate_type_3_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_3_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_3_counter_rx_terminate_type_3_counter_setf(uint16_t rxterminatetype3counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype3counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_3_COUNTER_ADDR, (uint32_t)rxterminatetype3counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_4_COUNTER register definition
 *  RxTerminateType4Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type4_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_4_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000030E)
#define MACDSP_API1_RX_TERMINATE_TYPE_4_COUNTER_OFFSET      0x0000030E
#define MACDSP_API1_RX_TERMINATE_TYPE_4_COUNTER_INDEX       0x000000C3
#define MACDSP_API1_RX_TERMINATE_TYPE_4_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_4_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_4_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_4_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_4_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_4_COUNTER_RX_TERMINATE_TYPE_4_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_4_COUNTER_RX_TERMINATE_TYPE_4_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_4_COUNTER_RX_TERMINATE_TYPE_4_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_4_COUNTER_RX_TERMINATE_TYPE_4_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_4_counter_rx_terminate_type_4_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_4_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_4_counter_rx_terminate_type_4_counter_setf(uint16_t rxterminatetype4counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype4counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_4_COUNTER_ADDR, (uint32_t)rxterminatetype4counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_5_COUNTER register definition
 *  RxTerminateType5Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type5_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_5_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000310)
#define MACDSP_API1_RX_TERMINATE_TYPE_5_COUNTER_OFFSET      0x00000310
#define MACDSP_API1_RX_TERMINATE_TYPE_5_COUNTER_INDEX       0x000000C4
#define MACDSP_API1_RX_TERMINATE_TYPE_5_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_5_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_5_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_5_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_5_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_5_COUNTER_RX_TERMINATE_TYPE_5_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_5_COUNTER_RX_TERMINATE_TYPE_5_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_5_COUNTER_RX_TERMINATE_TYPE_5_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_5_COUNTER_RX_TERMINATE_TYPE_5_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_5_counter_rx_terminate_type_5_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_5_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_5_counter_rx_terminate_type_5_counter_setf(uint16_t rxterminatetype5counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype5counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_5_COUNTER_ADDR, (uint32_t)rxterminatetype5counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_6_COUNTER register definition
 *  RxTerminateType6Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type6_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_6_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000312)
#define MACDSP_API1_RX_TERMINATE_TYPE_6_COUNTER_OFFSET      0x00000312
#define MACDSP_API1_RX_TERMINATE_TYPE_6_COUNTER_INDEX       0x000000C4
#define MACDSP_API1_RX_TERMINATE_TYPE_6_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_6_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_6_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_6_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_6_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_6_COUNTER_RX_TERMINATE_TYPE_6_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_6_COUNTER_RX_TERMINATE_TYPE_6_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_6_COUNTER_RX_TERMINATE_TYPE_6_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_6_COUNTER_RX_TERMINATE_TYPE_6_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_6_counter_rx_terminate_type_6_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_6_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_6_counter_rx_terminate_type_6_counter_setf(uint16_t rxterminatetype6counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype6counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_6_COUNTER_ADDR, (uint32_t)rxterminatetype6counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_7_COUNTER register definition
 *  RxTerminateType7Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type7_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_7_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000314)
#define MACDSP_API1_RX_TERMINATE_TYPE_7_COUNTER_OFFSET      0x00000314
#define MACDSP_API1_RX_TERMINATE_TYPE_7_COUNTER_INDEX       0x000000C5
#define MACDSP_API1_RX_TERMINATE_TYPE_7_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_7_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_7_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_7_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_7_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_7_COUNTER_RX_TERMINATE_TYPE_7_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_7_COUNTER_RX_TERMINATE_TYPE_7_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_7_COUNTER_RX_TERMINATE_TYPE_7_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_7_COUNTER_RX_TERMINATE_TYPE_7_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_7_counter_rx_terminate_type_7_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_7_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_7_counter_rx_terminate_type_7_counter_setf(uint16_t rxterminatetype7counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype7counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_7_COUNTER_ADDR, (uint32_t)rxterminatetype7counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_8_COUNTER register definition
 *  RxTerminateType8Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type8_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_8_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000316)
#define MACDSP_API1_RX_TERMINATE_TYPE_8_COUNTER_OFFSET      0x00000316
#define MACDSP_API1_RX_TERMINATE_TYPE_8_COUNTER_INDEX       0x000000C5
#define MACDSP_API1_RX_TERMINATE_TYPE_8_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_8_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_8_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_8_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_8_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_8_COUNTER_RX_TERMINATE_TYPE_8_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_8_COUNTER_RX_TERMINATE_TYPE_8_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_8_COUNTER_RX_TERMINATE_TYPE_8_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_8_COUNTER_RX_TERMINATE_TYPE_8_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_8_counter_rx_terminate_type_8_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_8_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_8_counter_rx_terminate_type_8_counter_setf(uint16_t rxterminatetype8counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype8counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_8_COUNTER_ADDR, (uint32_t)rxterminatetype8counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_9_COUNTER register definition
 *  RxTerminateType9Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type9_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_9_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000318)
#define MACDSP_API1_RX_TERMINATE_TYPE_9_COUNTER_OFFSET      0x00000318
#define MACDSP_API1_RX_TERMINATE_TYPE_9_COUNTER_INDEX       0x000000C6
#define MACDSP_API1_RX_TERMINATE_TYPE_9_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_9_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_9_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_9_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_9_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_9_COUNTER_RX_TERMINATE_TYPE_9_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_9_COUNTER_RX_TERMINATE_TYPE_9_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_9_COUNTER_RX_TERMINATE_TYPE_9_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_9_COUNTER_RX_TERMINATE_TYPE_9_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_9_counter_rx_terminate_type_9_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_9_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_9_counter_rx_terminate_type_9_counter_setf(uint16_t rxterminatetype9counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype9counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_9_COUNTER_ADDR, (uint32_t)rxterminatetype9counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_10_COUNTER register definition
 *  RxTerminateType10Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type10_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_10_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000031A)
#define MACDSP_API1_RX_TERMINATE_TYPE_10_COUNTER_OFFSET      0x0000031A
#define MACDSP_API1_RX_TERMINATE_TYPE_10_COUNTER_INDEX       0x000000C6
#define MACDSP_API1_RX_TERMINATE_TYPE_10_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_10_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_10_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_10_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_10_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_10_COUNTER_RX_TERMINATE_TYPE_10_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_10_COUNTER_RX_TERMINATE_TYPE_10_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_10_COUNTER_RX_TERMINATE_TYPE_10_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_10_COUNTER_RX_TERMINATE_TYPE_10_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_10_counter_rx_terminate_type_10_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_10_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_10_counter_rx_terminate_type_10_counter_setf(uint16_t rxterminatetype10counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype10counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_10_COUNTER_ADDR, (uint32_t)rxterminatetype10counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_11_COUNTER register definition
 *  RxTerminateType11Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type11_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_11_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000031C)
#define MACDSP_API1_RX_TERMINATE_TYPE_11_COUNTER_OFFSET      0x0000031C
#define MACDSP_API1_RX_TERMINATE_TYPE_11_COUNTER_INDEX       0x000000C7
#define MACDSP_API1_RX_TERMINATE_TYPE_11_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_11_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_11_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_11_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_11_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_11_COUNTER_RX_TERMINATE_TYPE_11_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_11_COUNTER_RX_TERMINATE_TYPE_11_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_11_COUNTER_RX_TERMINATE_TYPE_11_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_11_COUNTER_RX_TERMINATE_TYPE_11_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_11_counter_rx_terminate_type_11_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_11_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_11_counter_rx_terminate_type_11_counter_setf(uint16_t rxterminatetype11counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype11counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_11_COUNTER_ADDR, (uint32_t)rxterminatetype11counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_12_COUNTER register definition
 *  RxTerminateType12Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type12_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_12_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000031E)
#define MACDSP_API1_RX_TERMINATE_TYPE_12_COUNTER_OFFSET      0x0000031E
#define MACDSP_API1_RX_TERMINATE_TYPE_12_COUNTER_INDEX       0x000000C7
#define MACDSP_API1_RX_TERMINATE_TYPE_12_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_12_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_12_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_12_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_12_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_12_COUNTER_RX_TERMINATE_TYPE_12_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_12_COUNTER_RX_TERMINATE_TYPE_12_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_12_COUNTER_RX_TERMINATE_TYPE_12_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_12_COUNTER_RX_TERMINATE_TYPE_12_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_12_counter_rx_terminate_type_12_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_12_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_12_counter_rx_terminate_type_12_counter_setf(uint16_t rxterminatetype12counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype12counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_12_COUNTER_ADDR, (uint32_t)rxterminatetype12counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_13_COUNTER register definition
 *  RxTerminateType13Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type13_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_13_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000320)
#define MACDSP_API1_RX_TERMINATE_TYPE_13_COUNTER_OFFSET      0x00000320
#define MACDSP_API1_RX_TERMINATE_TYPE_13_COUNTER_INDEX       0x000000C8
#define MACDSP_API1_RX_TERMINATE_TYPE_13_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_13_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_13_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_13_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_13_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_13_COUNTER_RX_TERMINATE_TYPE_13_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_13_COUNTER_RX_TERMINATE_TYPE_13_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_13_COUNTER_RX_TERMINATE_TYPE_13_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_13_COUNTER_RX_TERMINATE_TYPE_13_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_13_counter_rx_terminate_type_13_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_13_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_13_counter_rx_terminate_type_13_counter_setf(uint16_t rxterminatetype13counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype13counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_13_COUNTER_ADDR, (uint32_t)rxterminatetype13counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_14_COUNTER register definition
 *  RxTerminateType14Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type14_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_14_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000322)
#define MACDSP_API1_RX_TERMINATE_TYPE_14_COUNTER_OFFSET      0x00000322
#define MACDSP_API1_RX_TERMINATE_TYPE_14_COUNTER_INDEX       0x000000C8
#define MACDSP_API1_RX_TERMINATE_TYPE_14_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_14_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_14_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_14_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_14_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_14_COUNTER_RX_TERMINATE_TYPE_14_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_14_COUNTER_RX_TERMINATE_TYPE_14_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_14_COUNTER_RX_TERMINATE_TYPE_14_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_14_COUNTER_RX_TERMINATE_TYPE_14_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_14_counter_rx_terminate_type_14_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_14_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_14_counter_rx_terminate_type_14_counter_setf(uint16_t rxterminatetype14counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype14counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_14_COUNTER_ADDR, (uint32_t)rxterminatetype14counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_15_COUNTER register definition
 *  RxTerminateType15Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type15_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_15_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000324)
#define MACDSP_API1_RX_TERMINATE_TYPE_15_COUNTER_OFFSET      0x00000324
#define MACDSP_API1_RX_TERMINATE_TYPE_15_COUNTER_INDEX       0x000000C9
#define MACDSP_API1_RX_TERMINATE_TYPE_15_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_15_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_15_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_15_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_15_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_15_COUNTER_RX_TERMINATE_TYPE_15_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_15_COUNTER_RX_TERMINATE_TYPE_15_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_15_COUNTER_RX_TERMINATE_TYPE_15_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_15_COUNTER_RX_TERMINATE_TYPE_15_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_15_counter_rx_terminate_type_15_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_15_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_15_counter_rx_terminate_type_15_counter_setf(uint16_t rxterminatetype15counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype15counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_15_COUNTER_ADDR, (uint32_t)rxterminatetype15counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_16_COUNTER register definition
 *  RxTerminateType16Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type16_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_16_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000326)
#define MACDSP_API1_RX_TERMINATE_TYPE_16_COUNTER_OFFSET      0x00000326
#define MACDSP_API1_RX_TERMINATE_TYPE_16_COUNTER_INDEX       0x000000C9
#define MACDSP_API1_RX_TERMINATE_TYPE_16_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_16_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_16_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_16_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_16_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_16_COUNTER_RX_TERMINATE_TYPE_16_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_16_COUNTER_RX_TERMINATE_TYPE_16_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_16_COUNTER_RX_TERMINATE_TYPE_16_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_16_COUNTER_RX_TERMINATE_TYPE_16_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_16_counter_rx_terminate_type_16_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_16_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_16_counter_rx_terminate_type_16_counter_setf(uint16_t rxterminatetype16counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype16counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_16_COUNTER_ADDR, (uint32_t)rxterminatetype16counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_17_COUNTER register definition
 *  RxTerminateType17Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type17_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_17_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000328)
#define MACDSP_API1_RX_TERMINATE_TYPE_17_COUNTER_OFFSET      0x00000328
#define MACDSP_API1_RX_TERMINATE_TYPE_17_COUNTER_INDEX       0x000000CA
#define MACDSP_API1_RX_TERMINATE_TYPE_17_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_17_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_17_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_17_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_17_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_17_COUNTER_RX_TERMINATE_TYPE_17_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_17_COUNTER_RX_TERMINATE_TYPE_17_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_17_COUNTER_RX_TERMINATE_TYPE_17_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_17_COUNTER_RX_TERMINATE_TYPE_17_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_17_counter_rx_terminate_type_17_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_17_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_17_counter_rx_terminate_type_17_counter_setf(uint16_t rxterminatetype17counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype17counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_17_COUNTER_ADDR, (uint32_t)rxterminatetype17counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_18_COUNTER register definition
 *  RxTerminateType18Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type18_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_18_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000032A)
#define MACDSP_API1_RX_TERMINATE_TYPE_18_COUNTER_OFFSET      0x0000032A
#define MACDSP_API1_RX_TERMINATE_TYPE_18_COUNTER_INDEX       0x000000CA
#define MACDSP_API1_RX_TERMINATE_TYPE_18_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_18_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_18_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_18_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_18_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_18_COUNTER_RX_TERMINATE_TYPE_18_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_18_COUNTER_RX_TERMINATE_TYPE_18_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_18_COUNTER_RX_TERMINATE_TYPE_18_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_18_COUNTER_RX_TERMINATE_TYPE_18_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_18_counter_rx_terminate_type_18_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_18_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_18_counter_rx_terminate_type_18_counter_setf(uint16_t rxterminatetype18counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype18counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_18_COUNTER_ADDR, (uint32_t)rxterminatetype18counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_19_COUNTER register definition
 *  RxTerminateType19Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type19_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_19_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000032C)
#define MACDSP_API1_RX_TERMINATE_TYPE_19_COUNTER_OFFSET      0x0000032C
#define MACDSP_API1_RX_TERMINATE_TYPE_19_COUNTER_INDEX       0x000000CB
#define MACDSP_API1_RX_TERMINATE_TYPE_19_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_19_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_19_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_19_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_19_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_19_COUNTER_RX_TERMINATE_TYPE_19_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_19_COUNTER_RX_TERMINATE_TYPE_19_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_19_COUNTER_RX_TERMINATE_TYPE_19_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_19_COUNTER_RX_TERMINATE_TYPE_19_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_19_counter_rx_terminate_type_19_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_19_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_19_counter_rx_terminate_type_19_counter_setf(uint16_t rxterminatetype19counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype19counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_19_COUNTER_ADDR, (uint32_t)rxterminatetype19counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_20_COUNTER register definition
 *  RxTerminateType20Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type20_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_20_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000032E)
#define MACDSP_API1_RX_TERMINATE_TYPE_20_COUNTER_OFFSET      0x0000032E
#define MACDSP_API1_RX_TERMINATE_TYPE_20_COUNTER_INDEX       0x000000CB
#define MACDSP_API1_RX_TERMINATE_TYPE_20_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_20_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_20_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_20_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_20_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_20_COUNTER_RX_TERMINATE_TYPE_20_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_20_COUNTER_RX_TERMINATE_TYPE_20_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_20_COUNTER_RX_TERMINATE_TYPE_20_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_20_COUNTER_RX_TERMINATE_TYPE_20_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_20_counter_rx_terminate_type_20_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_20_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_20_counter_rx_terminate_type_20_counter_setf(uint16_t rxterminatetype20counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype20counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_20_COUNTER_ADDR, (uint32_t)rxterminatetype20counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_21_COUNTER register definition
 *  RxTerminateType21Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type21_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_21_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000330)
#define MACDSP_API1_RX_TERMINATE_TYPE_21_COUNTER_OFFSET      0x00000330
#define MACDSP_API1_RX_TERMINATE_TYPE_21_COUNTER_INDEX       0x000000CC
#define MACDSP_API1_RX_TERMINATE_TYPE_21_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_21_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_21_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_21_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_21_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_21_COUNTER_RX_TERMINATE_TYPE_21_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_21_COUNTER_RX_TERMINATE_TYPE_21_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_21_COUNTER_RX_TERMINATE_TYPE_21_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_21_COUNTER_RX_TERMINATE_TYPE_21_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_21_counter_rx_terminate_type_21_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_21_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_21_counter_rx_terminate_type_21_counter_setf(uint16_t rxterminatetype21counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype21counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_21_COUNTER_ADDR, (uint32_t)rxterminatetype21counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_22_COUNTER register definition
 *  RxTerminateType22Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type22_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_22_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000332)
#define MACDSP_API1_RX_TERMINATE_TYPE_22_COUNTER_OFFSET      0x00000332
#define MACDSP_API1_RX_TERMINATE_TYPE_22_COUNTER_INDEX       0x000000CC
#define MACDSP_API1_RX_TERMINATE_TYPE_22_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_22_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_22_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_22_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_22_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_22_COUNTER_RX_TERMINATE_TYPE_22_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_22_COUNTER_RX_TERMINATE_TYPE_22_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_22_COUNTER_RX_TERMINATE_TYPE_22_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_22_COUNTER_RX_TERMINATE_TYPE_22_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_22_counter_rx_terminate_type_22_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_22_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_22_counter_rx_terminate_type_22_counter_setf(uint16_t rxterminatetype22counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype22counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_22_COUNTER_ADDR, (uint32_t)rxterminatetype22counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_23_COUNTER register definition
 *  RxTerminateType23Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type23_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_23_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000334)
#define MACDSP_API1_RX_TERMINATE_TYPE_23_COUNTER_OFFSET      0x00000334
#define MACDSP_API1_RX_TERMINATE_TYPE_23_COUNTER_INDEX       0x000000CD
#define MACDSP_API1_RX_TERMINATE_TYPE_23_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_23_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_23_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_23_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_23_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_23_COUNTER_RX_TERMINATE_TYPE_23_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_23_COUNTER_RX_TERMINATE_TYPE_23_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_23_COUNTER_RX_TERMINATE_TYPE_23_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_23_COUNTER_RX_TERMINATE_TYPE_23_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_23_counter_rx_terminate_type_23_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_23_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_23_counter_rx_terminate_type_23_counter_setf(uint16_t rxterminatetype23counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype23counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_23_COUNTER_ADDR, (uint32_t)rxterminatetype23counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_24_COUNTER register definition
 *  RxTerminateType24Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type24_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_24_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000336)
#define MACDSP_API1_RX_TERMINATE_TYPE_24_COUNTER_OFFSET      0x00000336
#define MACDSP_API1_RX_TERMINATE_TYPE_24_COUNTER_INDEX       0x000000CD
#define MACDSP_API1_RX_TERMINATE_TYPE_24_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_24_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_24_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_24_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_24_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_24_COUNTER_RX_TERMINATE_TYPE_24_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_24_COUNTER_RX_TERMINATE_TYPE_24_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_24_COUNTER_RX_TERMINATE_TYPE_24_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_24_COUNTER_RX_TERMINATE_TYPE_24_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_24_counter_rx_terminate_type_24_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_24_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_24_counter_rx_terminate_type_24_counter_setf(uint16_t rxterminatetype24counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype24counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_24_COUNTER_ADDR, (uint32_t)rxterminatetype24counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_25_COUNTER register definition
 *  RxTerminateType25Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type25_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_25_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000338)
#define MACDSP_API1_RX_TERMINATE_TYPE_25_COUNTER_OFFSET      0x00000338
#define MACDSP_API1_RX_TERMINATE_TYPE_25_COUNTER_INDEX       0x000000CE
#define MACDSP_API1_RX_TERMINATE_TYPE_25_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_25_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_25_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_25_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_25_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_25_COUNTER_RX_TERMINATE_TYPE_25_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_25_COUNTER_RX_TERMINATE_TYPE_25_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_25_COUNTER_RX_TERMINATE_TYPE_25_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_25_COUNTER_RX_TERMINATE_TYPE_25_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_25_counter_rx_terminate_type_25_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_25_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_25_counter_rx_terminate_type_25_counter_setf(uint16_t rxterminatetype25counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype25counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_25_COUNTER_ADDR, (uint32_t)rxterminatetype25counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_26_COUNTER register definition
 *  RxTerminateType26Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type26_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_26_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000033A)
#define MACDSP_API1_RX_TERMINATE_TYPE_26_COUNTER_OFFSET      0x0000033A
#define MACDSP_API1_RX_TERMINATE_TYPE_26_COUNTER_INDEX       0x000000CE
#define MACDSP_API1_RX_TERMINATE_TYPE_26_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_26_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_26_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_26_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_26_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_26_COUNTER_RX_TERMINATE_TYPE_26_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_26_COUNTER_RX_TERMINATE_TYPE_26_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_26_COUNTER_RX_TERMINATE_TYPE_26_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_26_COUNTER_RX_TERMINATE_TYPE_26_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_26_counter_rx_terminate_type_26_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_26_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_26_counter_rx_terminate_type_26_counter_setf(uint16_t rxterminatetype26counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype26counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_26_COUNTER_ADDR, (uint32_t)rxterminatetype26counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_27_COUNTER register definition
 *  RxTerminateType27Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type27_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_27_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000033C)
#define MACDSP_API1_RX_TERMINATE_TYPE_27_COUNTER_OFFSET      0x0000033C
#define MACDSP_API1_RX_TERMINATE_TYPE_27_COUNTER_INDEX       0x000000CF
#define MACDSP_API1_RX_TERMINATE_TYPE_27_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_27_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_27_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_27_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_27_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_27_COUNTER_RX_TERMINATE_TYPE_27_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_27_COUNTER_RX_TERMINATE_TYPE_27_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_27_COUNTER_RX_TERMINATE_TYPE_27_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_27_COUNTER_RX_TERMINATE_TYPE_27_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_27_counter_rx_terminate_type_27_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_27_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_27_counter_rx_terminate_type_27_counter_setf(uint16_t rxterminatetype27counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype27counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_27_COUNTER_ADDR, (uint32_t)rxterminatetype27counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_28_COUNTER register definition
 *  RxTerminateType28Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type28_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_28_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000033E)
#define MACDSP_API1_RX_TERMINATE_TYPE_28_COUNTER_OFFSET      0x0000033E
#define MACDSP_API1_RX_TERMINATE_TYPE_28_COUNTER_INDEX       0x000000CF
#define MACDSP_API1_RX_TERMINATE_TYPE_28_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_28_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_28_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_28_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_28_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_28_COUNTER_RX_TERMINATE_TYPE_28_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_28_COUNTER_RX_TERMINATE_TYPE_28_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_28_COUNTER_RX_TERMINATE_TYPE_28_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_28_COUNTER_RX_TERMINATE_TYPE_28_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_28_counter_rx_terminate_type_28_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_28_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_28_counter_rx_terminate_type_28_counter_setf(uint16_t rxterminatetype28counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype28counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_28_COUNTER_ADDR, (uint32_t)rxterminatetype28counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_29_COUNTER register definition
 *  RxTerminateType29Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type29_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_29_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000340)
#define MACDSP_API1_RX_TERMINATE_TYPE_29_COUNTER_OFFSET      0x00000340
#define MACDSP_API1_RX_TERMINATE_TYPE_29_COUNTER_INDEX       0x000000D0
#define MACDSP_API1_RX_TERMINATE_TYPE_29_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_29_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_29_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_29_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_29_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_29_COUNTER_RX_TERMINATE_TYPE_29_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_29_COUNTER_RX_TERMINATE_TYPE_29_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_29_COUNTER_RX_TERMINATE_TYPE_29_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_29_COUNTER_RX_TERMINATE_TYPE_29_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_29_counter_rx_terminate_type_29_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_29_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_29_counter_rx_terminate_type_29_counter_setf(uint16_t rxterminatetype29counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype29counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_29_COUNTER_ADDR, (uint32_t)rxterminatetype29counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_30_COUNTER register definition
 *  RxTerminateType30Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type30_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_30_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000342)
#define MACDSP_API1_RX_TERMINATE_TYPE_30_COUNTER_OFFSET      0x00000342
#define MACDSP_API1_RX_TERMINATE_TYPE_30_COUNTER_INDEX       0x000000D0
#define MACDSP_API1_RX_TERMINATE_TYPE_30_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_30_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_30_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_30_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_30_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_30_COUNTER_RX_TERMINATE_TYPE_30_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_30_COUNTER_RX_TERMINATE_TYPE_30_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_30_COUNTER_RX_TERMINATE_TYPE_30_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_30_COUNTER_RX_TERMINATE_TYPE_30_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_30_counter_rx_terminate_type_30_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_30_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_30_counter_rx_terminate_type_30_counter_setf(uint16_t rxterminatetype30counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype30counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_30_COUNTER_ADDR, (uint32_t)rxterminatetype30counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_31_COUNTER register definition
 *  RxTerminateType31Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type31_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_31_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000344)
#define MACDSP_API1_RX_TERMINATE_TYPE_31_COUNTER_OFFSET      0x00000344
#define MACDSP_API1_RX_TERMINATE_TYPE_31_COUNTER_INDEX       0x000000D1
#define MACDSP_API1_RX_TERMINATE_TYPE_31_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_31_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_31_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_31_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_31_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_31_COUNTER_RX_TERMINATE_TYPE_31_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_31_COUNTER_RX_TERMINATE_TYPE_31_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_31_COUNTER_RX_TERMINATE_TYPE_31_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_31_COUNTER_RX_TERMINATE_TYPE_31_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_31_counter_rx_terminate_type_31_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_31_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_31_counter_rx_terminate_type_31_counter_setf(uint16_t rxterminatetype31counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype31counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_31_COUNTER_ADDR, (uint32_t)rxterminatetype31counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_32_COUNTER register definition
 *  RxTerminateType32Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type32_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_32_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000346)
#define MACDSP_API1_RX_TERMINATE_TYPE_32_COUNTER_OFFSET      0x00000346
#define MACDSP_API1_RX_TERMINATE_TYPE_32_COUNTER_INDEX       0x000000D1
#define MACDSP_API1_RX_TERMINATE_TYPE_32_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_32_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_32_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_32_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_32_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_32_COUNTER_RX_TERMINATE_TYPE_32_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_32_COUNTER_RX_TERMINATE_TYPE_32_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_32_COUNTER_RX_TERMINATE_TYPE_32_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_32_COUNTER_RX_TERMINATE_TYPE_32_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_32_counter_rx_terminate_type_32_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_32_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_32_counter_rx_terminate_type_32_counter_setf(uint16_t rxterminatetype32counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype32counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_32_COUNTER_ADDR, (uint32_t)rxterminatetype32counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_33_COUNTER register definition
 *  RxTerminateType33Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type33_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_33_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000348)
#define MACDSP_API1_RX_TERMINATE_TYPE_33_COUNTER_OFFSET      0x00000348
#define MACDSP_API1_RX_TERMINATE_TYPE_33_COUNTER_INDEX       0x000000D2
#define MACDSP_API1_RX_TERMINATE_TYPE_33_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_33_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_33_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_33_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_33_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_33_COUNTER_RX_TERMINATE_TYPE_33_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_33_COUNTER_RX_TERMINATE_TYPE_33_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_33_COUNTER_RX_TERMINATE_TYPE_33_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_33_COUNTER_RX_TERMINATE_TYPE_33_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_33_counter_rx_terminate_type_33_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_33_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_33_counter_rx_terminate_type_33_counter_setf(uint16_t rxterminatetype33counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype33counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_33_COUNTER_ADDR, (uint32_t)rxterminatetype33counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_34_COUNTER register definition
 *  RxTerminateType34Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type34_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_34_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000034A)
#define MACDSP_API1_RX_TERMINATE_TYPE_34_COUNTER_OFFSET      0x0000034A
#define MACDSP_API1_RX_TERMINATE_TYPE_34_COUNTER_INDEX       0x000000D2
#define MACDSP_API1_RX_TERMINATE_TYPE_34_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_34_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_34_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_34_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_34_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_34_COUNTER_RX_TERMINATE_TYPE_34_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_34_COUNTER_RX_TERMINATE_TYPE_34_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_34_COUNTER_RX_TERMINATE_TYPE_34_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_34_COUNTER_RX_TERMINATE_TYPE_34_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_34_counter_rx_terminate_type_34_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_34_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_34_counter_rx_terminate_type_34_counter_setf(uint16_t rxterminatetype34counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype34counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_34_COUNTER_ADDR, (uint32_t)rxterminatetype34counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_35_COUNTER register definition
 *  RxTerminateType35Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type35_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_35_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000034C)
#define MACDSP_API1_RX_TERMINATE_TYPE_35_COUNTER_OFFSET      0x0000034C
#define MACDSP_API1_RX_TERMINATE_TYPE_35_COUNTER_INDEX       0x000000D3
#define MACDSP_API1_RX_TERMINATE_TYPE_35_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_35_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_35_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_35_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_35_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_35_COUNTER_RX_TERMINATE_TYPE_35_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_35_COUNTER_RX_TERMINATE_TYPE_35_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_35_COUNTER_RX_TERMINATE_TYPE_35_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_35_COUNTER_RX_TERMINATE_TYPE_35_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_35_counter_rx_terminate_type_35_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_35_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_35_counter_rx_terminate_type_35_counter_setf(uint16_t rxterminatetype35counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype35counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_35_COUNTER_ADDR, (uint32_t)rxterminatetype35counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_36_COUNTER register definition
 *  RxTerminateType36Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type36_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_36_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000034E)
#define MACDSP_API1_RX_TERMINATE_TYPE_36_COUNTER_OFFSET      0x0000034E
#define MACDSP_API1_RX_TERMINATE_TYPE_36_COUNTER_INDEX       0x000000D3
#define MACDSP_API1_RX_TERMINATE_TYPE_36_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_36_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_36_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_36_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_36_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_36_COUNTER_RX_TERMINATE_TYPE_36_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_36_COUNTER_RX_TERMINATE_TYPE_36_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_36_COUNTER_RX_TERMINATE_TYPE_36_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_36_COUNTER_RX_TERMINATE_TYPE_36_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_36_counter_rx_terminate_type_36_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_36_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_36_counter_rx_terminate_type_36_counter_setf(uint16_t rxterminatetype36counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype36counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_36_COUNTER_ADDR, (uint32_t)rxterminatetype36counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_37_COUNTER register definition
 *  RxTerminateType37Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type37_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_37_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000350)
#define MACDSP_API1_RX_TERMINATE_TYPE_37_COUNTER_OFFSET      0x00000350
#define MACDSP_API1_RX_TERMINATE_TYPE_37_COUNTER_INDEX       0x000000D4
#define MACDSP_API1_RX_TERMINATE_TYPE_37_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_37_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_37_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_37_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_37_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_37_COUNTER_RX_TERMINATE_TYPE_37_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_37_COUNTER_RX_TERMINATE_TYPE_37_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_37_COUNTER_RX_TERMINATE_TYPE_37_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_37_COUNTER_RX_TERMINATE_TYPE_37_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_37_counter_rx_terminate_type_37_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_37_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_37_counter_rx_terminate_type_37_counter_setf(uint16_t rxterminatetype37counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype37counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_37_COUNTER_ADDR, (uint32_t)rxterminatetype37counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_38_COUNTER register definition
 *  RxTerminateType38Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type38_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_38_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000352)
#define MACDSP_API1_RX_TERMINATE_TYPE_38_COUNTER_OFFSET      0x00000352
#define MACDSP_API1_RX_TERMINATE_TYPE_38_COUNTER_INDEX       0x000000D4
#define MACDSP_API1_RX_TERMINATE_TYPE_38_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_38_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_38_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_38_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_38_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_38_COUNTER_RX_TERMINATE_TYPE_38_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_38_COUNTER_RX_TERMINATE_TYPE_38_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_38_COUNTER_RX_TERMINATE_TYPE_38_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_38_COUNTER_RX_TERMINATE_TYPE_38_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_38_counter_rx_terminate_type_38_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_38_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_38_counter_rx_terminate_type_38_counter_setf(uint16_t rxterminatetype38counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype38counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_38_COUNTER_ADDR, (uint32_t)rxterminatetype38counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_39_COUNTER register definition
 *  RxTerminateType39Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type39_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_39_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000354)
#define MACDSP_API1_RX_TERMINATE_TYPE_39_COUNTER_OFFSET      0x00000354
#define MACDSP_API1_RX_TERMINATE_TYPE_39_COUNTER_INDEX       0x000000D5
#define MACDSP_API1_RX_TERMINATE_TYPE_39_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_39_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_39_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_39_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_39_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_39_COUNTER_RX_TERMINATE_TYPE_39_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_39_COUNTER_RX_TERMINATE_TYPE_39_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_39_COUNTER_RX_TERMINATE_TYPE_39_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_39_COUNTER_RX_TERMINATE_TYPE_39_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_39_counter_rx_terminate_type_39_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_39_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_39_counter_rx_terminate_type_39_counter_setf(uint16_t rxterminatetype39counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype39counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_39_COUNTER_ADDR, (uint32_t)rxterminatetype39counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_40_COUNTER register definition
 *  RxTerminateType40Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type40_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_40_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000356)
#define MACDSP_API1_RX_TERMINATE_TYPE_40_COUNTER_OFFSET      0x00000356
#define MACDSP_API1_RX_TERMINATE_TYPE_40_COUNTER_INDEX       0x000000D5
#define MACDSP_API1_RX_TERMINATE_TYPE_40_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_40_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_40_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_40_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_40_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_40_COUNTER_RX_TERMINATE_TYPE_40_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_40_COUNTER_RX_TERMINATE_TYPE_40_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_40_COUNTER_RX_TERMINATE_TYPE_40_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_40_COUNTER_RX_TERMINATE_TYPE_40_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_40_counter_rx_terminate_type_40_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_40_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_40_counter_rx_terminate_type_40_counter_setf(uint16_t rxterminatetype40counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype40counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_40_COUNTER_ADDR, (uint32_t)rxterminatetype40counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_41_COUNTER register definition
 *  RxTerminateType41Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type41_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_41_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000358)
#define MACDSP_API1_RX_TERMINATE_TYPE_41_COUNTER_OFFSET      0x00000358
#define MACDSP_API1_RX_TERMINATE_TYPE_41_COUNTER_INDEX       0x000000D6
#define MACDSP_API1_RX_TERMINATE_TYPE_41_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_41_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_41_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_41_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_41_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_41_COUNTER_RX_TERMINATE_TYPE_41_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_41_COUNTER_RX_TERMINATE_TYPE_41_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_41_COUNTER_RX_TERMINATE_TYPE_41_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_41_COUNTER_RX_TERMINATE_TYPE_41_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_41_counter_rx_terminate_type_41_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_41_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_41_counter_rx_terminate_type_41_counter_setf(uint16_t rxterminatetype41counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype41counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_41_COUNTER_ADDR, (uint32_t)rxterminatetype41counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_42_COUNTER register definition
 *  RxTerminateType42Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type42_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_42_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000035A)
#define MACDSP_API1_RX_TERMINATE_TYPE_42_COUNTER_OFFSET      0x0000035A
#define MACDSP_API1_RX_TERMINATE_TYPE_42_COUNTER_INDEX       0x000000D6
#define MACDSP_API1_RX_TERMINATE_TYPE_42_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_42_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_42_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_42_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_42_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_42_COUNTER_RX_TERMINATE_TYPE_42_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_42_COUNTER_RX_TERMINATE_TYPE_42_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_42_COUNTER_RX_TERMINATE_TYPE_42_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_42_COUNTER_RX_TERMINATE_TYPE_42_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_42_counter_rx_terminate_type_42_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_42_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_42_counter_rx_terminate_type_42_counter_setf(uint16_t rxterminatetype42counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype42counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_42_COUNTER_ADDR, (uint32_t)rxterminatetype42counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_43_COUNTER register definition
 *  RxTerminateType43Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type43_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_43_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000035C)
#define MACDSP_API1_RX_TERMINATE_TYPE_43_COUNTER_OFFSET      0x0000035C
#define MACDSP_API1_RX_TERMINATE_TYPE_43_COUNTER_INDEX       0x000000D7
#define MACDSP_API1_RX_TERMINATE_TYPE_43_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_43_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_43_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_43_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_43_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_43_COUNTER_RX_TERMINATE_TYPE_43_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_43_COUNTER_RX_TERMINATE_TYPE_43_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_43_COUNTER_RX_TERMINATE_TYPE_43_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_43_COUNTER_RX_TERMINATE_TYPE_43_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_43_counter_rx_terminate_type_43_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_43_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_43_counter_rx_terminate_type_43_counter_setf(uint16_t rxterminatetype43counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype43counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_43_COUNTER_ADDR, (uint32_t)rxterminatetype43counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_44_COUNTER register definition
 *  RxTerminateType44Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type44_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_44_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000035E)
#define MACDSP_API1_RX_TERMINATE_TYPE_44_COUNTER_OFFSET      0x0000035E
#define MACDSP_API1_RX_TERMINATE_TYPE_44_COUNTER_INDEX       0x000000D7
#define MACDSP_API1_RX_TERMINATE_TYPE_44_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_44_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_44_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_44_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_44_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_44_COUNTER_RX_TERMINATE_TYPE_44_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_44_COUNTER_RX_TERMINATE_TYPE_44_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_44_COUNTER_RX_TERMINATE_TYPE_44_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_44_COUNTER_RX_TERMINATE_TYPE_44_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_44_counter_rx_terminate_type_44_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_44_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_44_counter_rx_terminate_type_44_counter_setf(uint16_t rxterminatetype44counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype44counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_44_COUNTER_ADDR, (uint32_t)rxterminatetype44counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_45_COUNTER register definition
 *  RxTerminateType45Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type45_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_45_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000360)
#define MACDSP_API1_RX_TERMINATE_TYPE_45_COUNTER_OFFSET      0x00000360
#define MACDSP_API1_RX_TERMINATE_TYPE_45_COUNTER_INDEX       0x000000D8
#define MACDSP_API1_RX_TERMINATE_TYPE_45_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_45_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_45_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_45_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_45_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_45_COUNTER_RX_TERMINATE_TYPE_45_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_45_COUNTER_RX_TERMINATE_TYPE_45_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_45_COUNTER_RX_TERMINATE_TYPE_45_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_45_COUNTER_RX_TERMINATE_TYPE_45_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_45_counter_rx_terminate_type_45_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_45_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_45_counter_rx_terminate_type_45_counter_setf(uint16_t rxterminatetype45counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype45counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_45_COUNTER_ADDR, (uint32_t)rxterminatetype45counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_46_COUNTER register definition
 *  RxTerminateType46Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type46_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_46_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000362)
#define MACDSP_API1_RX_TERMINATE_TYPE_46_COUNTER_OFFSET      0x00000362
#define MACDSP_API1_RX_TERMINATE_TYPE_46_COUNTER_INDEX       0x000000D8
#define MACDSP_API1_RX_TERMINATE_TYPE_46_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_46_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_46_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_46_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_46_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_46_COUNTER_RX_TERMINATE_TYPE_46_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_46_COUNTER_RX_TERMINATE_TYPE_46_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_46_COUNTER_RX_TERMINATE_TYPE_46_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_46_COUNTER_RX_TERMINATE_TYPE_46_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_46_counter_rx_terminate_type_46_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_46_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_46_counter_rx_terminate_type_46_counter_setf(uint16_t rxterminatetype46counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype46counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_46_COUNTER_ADDR, (uint32_t)rxterminatetype46counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_47_COUNTER register definition
 *  RxTerminateType47Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type47_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_47_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000364)
#define MACDSP_API1_RX_TERMINATE_TYPE_47_COUNTER_OFFSET      0x00000364
#define MACDSP_API1_RX_TERMINATE_TYPE_47_COUNTER_INDEX       0x000000D9
#define MACDSP_API1_RX_TERMINATE_TYPE_47_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_47_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_47_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_47_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_47_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_47_COUNTER_RX_TERMINATE_TYPE_47_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_47_COUNTER_RX_TERMINATE_TYPE_47_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_47_COUNTER_RX_TERMINATE_TYPE_47_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_47_COUNTER_RX_TERMINATE_TYPE_47_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_47_counter_rx_terminate_type_47_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_47_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_47_counter_rx_terminate_type_47_counter_setf(uint16_t rxterminatetype47counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype47counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_47_COUNTER_ADDR, (uint32_t)rxterminatetype47counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_48_COUNTER register definition
 *  RxTerminateType48Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type48_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_48_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000366)
#define MACDSP_API1_RX_TERMINATE_TYPE_48_COUNTER_OFFSET      0x00000366
#define MACDSP_API1_RX_TERMINATE_TYPE_48_COUNTER_INDEX       0x000000D9
#define MACDSP_API1_RX_TERMINATE_TYPE_48_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_48_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_48_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_48_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_48_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_48_COUNTER_RX_TERMINATE_TYPE_48_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_48_COUNTER_RX_TERMINATE_TYPE_48_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_48_COUNTER_RX_TERMINATE_TYPE_48_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_48_COUNTER_RX_TERMINATE_TYPE_48_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_48_counter_rx_terminate_type_48_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_48_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_48_counter_rx_terminate_type_48_counter_setf(uint16_t rxterminatetype48counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype48counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_48_COUNTER_ADDR, (uint32_t)rxterminatetype48counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_49_COUNTER register definition
 *  RxTerminateType49Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type49_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_49_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000368)
#define MACDSP_API1_RX_TERMINATE_TYPE_49_COUNTER_OFFSET      0x00000368
#define MACDSP_API1_RX_TERMINATE_TYPE_49_COUNTER_INDEX       0x000000DA
#define MACDSP_API1_RX_TERMINATE_TYPE_49_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_49_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_49_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_49_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_49_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_49_COUNTER_RX_TERMINATE_TYPE_49_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_49_COUNTER_RX_TERMINATE_TYPE_49_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_49_COUNTER_RX_TERMINATE_TYPE_49_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_49_COUNTER_RX_TERMINATE_TYPE_49_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_49_counter_rx_terminate_type_49_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_49_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_49_counter_rx_terminate_type_49_counter_setf(uint16_t rxterminatetype49counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype49counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_49_COUNTER_ADDR, (uint32_t)rxterminatetype49counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_50_COUNTER register definition
 *  RxTerminateType50Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type50_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_50_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000036A)
#define MACDSP_API1_RX_TERMINATE_TYPE_50_COUNTER_OFFSET      0x0000036A
#define MACDSP_API1_RX_TERMINATE_TYPE_50_COUNTER_INDEX       0x000000DA
#define MACDSP_API1_RX_TERMINATE_TYPE_50_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_50_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_50_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_50_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_50_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_50_COUNTER_RX_TERMINATE_TYPE_50_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_50_COUNTER_RX_TERMINATE_TYPE_50_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_50_COUNTER_RX_TERMINATE_TYPE_50_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_50_COUNTER_RX_TERMINATE_TYPE_50_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_50_counter_rx_terminate_type_50_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_50_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_50_counter_rx_terminate_type_50_counter_setf(uint16_t rxterminatetype50counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype50counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_50_COUNTER_ADDR, (uint32_t)rxterminatetype50counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_51_COUNTER register definition
 *  RxTerminateType51Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type51_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_51_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000036C)
#define MACDSP_API1_RX_TERMINATE_TYPE_51_COUNTER_OFFSET      0x0000036C
#define MACDSP_API1_RX_TERMINATE_TYPE_51_COUNTER_INDEX       0x000000DB
#define MACDSP_API1_RX_TERMINATE_TYPE_51_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_51_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_51_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_51_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_51_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_51_COUNTER_RX_TERMINATE_TYPE_51_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_51_COUNTER_RX_TERMINATE_TYPE_51_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_51_COUNTER_RX_TERMINATE_TYPE_51_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_51_COUNTER_RX_TERMINATE_TYPE_51_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_51_counter_rx_terminate_type_51_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_51_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_51_counter_rx_terminate_type_51_counter_setf(uint16_t rxterminatetype51counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype51counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_51_COUNTER_ADDR, (uint32_t)rxterminatetype51counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_52_COUNTER register definition
 *  RxTerminateType52Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type52_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_52_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000036E)
#define MACDSP_API1_RX_TERMINATE_TYPE_52_COUNTER_OFFSET      0x0000036E
#define MACDSP_API1_RX_TERMINATE_TYPE_52_COUNTER_INDEX       0x000000DB
#define MACDSP_API1_RX_TERMINATE_TYPE_52_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_52_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_52_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_52_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_52_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_52_COUNTER_RX_TERMINATE_TYPE_52_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_52_COUNTER_RX_TERMINATE_TYPE_52_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_52_COUNTER_RX_TERMINATE_TYPE_52_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_52_COUNTER_RX_TERMINATE_TYPE_52_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_52_counter_rx_terminate_type_52_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_52_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_52_counter_rx_terminate_type_52_counter_setf(uint16_t rxterminatetype52counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype52counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_52_COUNTER_ADDR, (uint32_t)rxterminatetype52counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_53_COUNTER register definition
 *  RxTerminateType53Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type53_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_53_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000370)
#define MACDSP_API1_RX_TERMINATE_TYPE_53_COUNTER_OFFSET      0x00000370
#define MACDSP_API1_RX_TERMINATE_TYPE_53_COUNTER_INDEX       0x000000DC
#define MACDSP_API1_RX_TERMINATE_TYPE_53_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_53_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_53_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_53_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_53_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_53_COUNTER_RX_TERMINATE_TYPE_53_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_53_COUNTER_RX_TERMINATE_TYPE_53_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_53_COUNTER_RX_TERMINATE_TYPE_53_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_53_COUNTER_RX_TERMINATE_TYPE_53_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_53_counter_rx_terminate_type_53_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_53_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_53_counter_rx_terminate_type_53_counter_setf(uint16_t rxterminatetype53counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype53counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_53_COUNTER_ADDR, (uint32_t)rxterminatetype53counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_54_COUNTER register definition
 *  RxTerminateType54Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type54_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_54_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000372)
#define MACDSP_API1_RX_TERMINATE_TYPE_54_COUNTER_OFFSET      0x00000372
#define MACDSP_API1_RX_TERMINATE_TYPE_54_COUNTER_INDEX       0x000000DC
#define MACDSP_API1_RX_TERMINATE_TYPE_54_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_54_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_54_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_54_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_54_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_54_COUNTER_RX_TERMINATE_TYPE_54_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_54_COUNTER_RX_TERMINATE_TYPE_54_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_54_COUNTER_RX_TERMINATE_TYPE_54_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_54_COUNTER_RX_TERMINATE_TYPE_54_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_54_counter_rx_terminate_type_54_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_54_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_54_counter_rx_terminate_type_54_counter_setf(uint16_t rxterminatetype54counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype54counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_54_COUNTER_ADDR, (uint32_t)rxterminatetype54counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_55_COUNTER register definition
 *  RxTerminateType55Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type55_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_55_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000374)
#define MACDSP_API1_RX_TERMINATE_TYPE_55_COUNTER_OFFSET      0x00000374
#define MACDSP_API1_RX_TERMINATE_TYPE_55_COUNTER_INDEX       0x000000DD
#define MACDSP_API1_RX_TERMINATE_TYPE_55_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_55_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_55_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_55_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_55_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_55_COUNTER_RX_TERMINATE_TYPE_55_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_55_COUNTER_RX_TERMINATE_TYPE_55_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_55_COUNTER_RX_TERMINATE_TYPE_55_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_55_COUNTER_RX_TERMINATE_TYPE_55_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_55_counter_rx_terminate_type_55_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_55_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_55_counter_rx_terminate_type_55_counter_setf(uint16_t rxterminatetype55counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype55counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_55_COUNTER_ADDR, (uint32_t)rxterminatetype55counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_56_COUNTER register definition
 *  RxTerminateType56Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type56_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_56_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000376)
#define MACDSP_API1_RX_TERMINATE_TYPE_56_COUNTER_OFFSET      0x00000376
#define MACDSP_API1_RX_TERMINATE_TYPE_56_COUNTER_INDEX       0x000000DD
#define MACDSP_API1_RX_TERMINATE_TYPE_56_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_56_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_56_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_56_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_56_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_56_COUNTER_RX_TERMINATE_TYPE_56_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_56_COUNTER_RX_TERMINATE_TYPE_56_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_56_COUNTER_RX_TERMINATE_TYPE_56_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_56_COUNTER_RX_TERMINATE_TYPE_56_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_56_counter_rx_terminate_type_56_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_56_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_56_counter_rx_terminate_type_56_counter_setf(uint16_t rxterminatetype56counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype56counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_56_COUNTER_ADDR, (uint32_t)rxterminatetype56counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_57_COUNTER register definition
 *  RxTerminateType57Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type57_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_57_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000378)
#define MACDSP_API1_RX_TERMINATE_TYPE_57_COUNTER_OFFSET      0x00000378
#define MACDSP_API1_RX_TERMINATE_TYPE_57_COUNTER_INDEX       0x000000DE
#define MACDSP_API1_RX_TERMINATE_TYPE_57_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_57_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_57_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_57_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_57_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_57_COUNTER_RX_TERMINATE_TYPE_57_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_57_COUNTER_RX_TERMINATE_TYPE_57_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_57_COUNTER_RX_TERMINATE_TYPE_57_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_57_COUNTER_RX_TERMINATE_TYPE_57_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_57_counter_rx_terminate_type_57_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_57_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_57_counter_rx_terminate_type_57_counter_setf(uint16_t rxterminatetype57counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype57counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_57_COUNTER_ADDR, (uint32_t)rxterminatetype57counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_58_COUNTER register definition
 *  RxTerminateType58Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type58_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_58_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000037A)
#define MACDSP_API1_RX_TERMINATE_TYPE_58_COUNTER_OFFSET      0x0000037A
#define MACDSP_API1_RX_TERMINATE_TYPE_58_COUNTER_INDEX       0x000000DE
#define MACDSP_API1_RX_TERMINATE_TYPE_58_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_58_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_58_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_58_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_58_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_58_COUNTER_RX_TERMINATE_TYPE_58_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_58_COUNTER_RX_TERMINATE_TYPE_58_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_58_COUNTER_RX_TERMINATE_TYPE_58_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_58_COUNTER_RX_TERMINATE_TYPE_58_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_58_counter_rx_terminate_type_58_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_58_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_58_counter_rx_terminate_type_58_counter_setf(uint16_t rxterminatetype58counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype58counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_58_COUNTER_ADDR, (uint32_t)rxterminatetype58counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_59_COUNTER register definition
 *  RxTerminateType59Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type59_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_59_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000037C)
#define MACDSP_API1_RX_TERMINATE_TYPE_59_COUNTER_OFFSET      0x0000037C
#define MACDSP_API1_RX_TERMINATE_TYPE_59_COUNTER_INDEX       0x000000DF
#define MACDSP_API1_RX_TERMINATE_TYPE_59_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_59_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_59_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_59_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_59_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_59_COUNTER_RX_TERMINATE_TYPE_59_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_59_COUNTER_RX_TERMINATE_TYPE_59_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_59_COUNTER_RX_TERMINATE_TYPE_59_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_59_COUNTER_RX_TERMINATE_TYPE_59_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_59_counter_rx_terminate_type_59_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_59_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_59_counter_rx_terminate_type_59_counter_setf(uint16_t rxterminatetype59counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype59counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_59_COUNTER_ADDR, (uint32_t)rxterminatetype59counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_60_COUNTER register definition
 *  RxTerminateType60Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type60_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_60_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000037E)
#define MACDSP_API1_RX_TERMINATE_TYPE_60_COUNTER_OFFSET      0x0000037E
#define MACDSP_API1_RX_TERMINATE_TYPE_60_COUNTER_INDEX       0x000000DF
#define MACDSP_API1_RX_TERMINATE_TYPE_60_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_60_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_60_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_60_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_60_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_60_COUNTER_RX_TERMINATE_TYPE_60_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_60_COUNTER_RX_TERMINATE_TYPE_60_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_60_COUNTER_RX_TERMINATE_TYPE_60_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_60_COUNTER_RX_TERMINATE_TYPE_60_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_60_counter_rx_terminate_type_60_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_60_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_60_counter_rx_terminate_type_60_counter_setf(uint16_t rxterminatetype60counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype60counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_60_COUNTER_ADDR, (uint32_t)rxterminatetype60counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_61_COUNTER register definition
 *  RxTerminateType61Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type61_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_61_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000380)
#define MACDSP_API1_RX_TERMINATE_TYPE_61_COUNTER_OFFSET      0x00000380
#define MACDSP_API1_RX_TERMINATE_TYPE_61_COUNTER_INDEX       0x000000E0
#define MACDSP_API1_RX_TERMINATE_TYPE_61_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_61_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_61_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_61_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_61_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_61_COUNTER_RX_TERMINATE_TYPE_61_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_61_COUNTER_RX_TERMINATE_TYPE_61_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_61_COUNTER_RX_TERMINATE_TYPE_61_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_61_COUNTER_RX_TERMINATE_TYPE_61_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_61_counter_rx_terminate_type_61_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_61_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_61_counter_rx_terminate_type_61_counter_setf(uint16_t rxterminatetype61counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype61counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_61_COUNTER_ADDR, (uint32_t)rxterminatetype61counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_62_COUNTER register definition
 *  RxTerminateType62Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type62_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_62_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000382)
#define MACDSP_API1_RX_TERMINATE_TYPE_62_COUNTER_OFFSET      0x00000382
#define MACDSP_API1_RX_TERMINATE_TYPE_62_COUNTER_INDEX       0x000000E0
#define MACDSP_API1_RX_TERMINATE_TYPE_62_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_62_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_62_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_62_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_62_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_62_COUNTER_RX_TERMINATE_TYPE_62_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_62_COUNTER_RX_TERMINATE_TYPE_62_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_62_COUNTER_RX_TERMINATE_TYPE_62_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_62_COUNTER_RX_TERMINATE_TYPE_62_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_62_counter_rx_terminate_type_62_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_62_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_62_counter_rx_terminate_type_62_counter_setf(uint16_t rxterminatetype62counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype62counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_62_COUNTER_ADDR, (uint32_t)rxterminatetype62counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_63_COUNTER register definition
 *  RxTerminateType63Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type63_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_63_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000384)
#define MACDSP_API1_RX_TERMINATE_TYPE_63_COUNTER_OFFSET      0x00000384
#define MACDSP_API1_RX_TERMINATE_TYPE_63_COUNTER_INDEX       0x000000E1
#define MACDSP_API1_RX_TERMINATE_TYPE_63_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_63_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_63_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_63_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_63_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_63_COUNTER_RX_TERMINATE_TYPE_63_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_63_COUNTER_RX_TERMINATE_TYPE_63_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_63_COUNTER_RX_TERMINATE_TYPE_63_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_63_COUNTER_RX_TERMINATE_TYPE_63_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_63_counter_rx_terminate_type_63_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_63_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_63_counter_rx_terminate_type_63_counter_setf(uint16_t rxterminatetype63counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype63counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_63_COUNTER_ADDR, (uint32_t)rxterminatetype63counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_64_COUNTER register definition
 *  RxTerminateType64Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type64_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_64_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000386)
#define MACDSP_API1_RX_TERMINATE_TYPE_64_COUNTER_OFFSET      0x00000386
#define MACDSP_API1_RX_TERMINATE_TYPE_64_COUNTER_INDEX       0x000000E1
#define MACDSP_API1_RX_TERMINATE_TYPE_64_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_64_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_64_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_64_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_64_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_64_COUNTER_RX_TERMINATE_TYPE_64_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_64_COUNTER_RX_TERMINATE_TYPE_64_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_64_COUNTER_RX_TERMINATE_TYPE_64_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_64_COUNTER_RX_TERMINATE_TYPE_64_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_64_counter_rx_terminate_type_64_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_64_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_64_counter_rx_terminate_type_64_counter_setf(uint16_t rxterminatetype64counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype64counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_64_COUNTER_ADDR, (uint32_t)rxterminatetype64counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_65_COUNTER register definition
 *  RxTerminateType65Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type65_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_65_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000388)
#define MACDSP_API1_RX_TERMINATE_TYPE_65_COUNTER_OFFSET      0x00000388
#define MACDSP_API1_RX_TERMINATE_TYPE_65_COUNTER_INDEX       0x000000E2
#define MACDSP_API1_RX_TERMINATE_TYPE_65_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_65_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_65_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_65_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_65_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_65_COUNTER_RX_TERMINATE_TYPE_65_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_65_COUNTER_RX_TERMINATE_TYPE_65_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_65_COUNTER_RX_TERMINATE_TYPE_65_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_65_COUNTER_RX_TERMINATE_TYPE_65_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_65_counter_rx_terminate_type_65_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_65_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_65_counter_rx_terminate_type_65_counter_setf(uint16_t rxterminatetype65counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype65counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_65_COUNTER_ADDR, (uint32_t)rxterminatetype65counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_66_COUNTER register definition
 *  RxTerminateType66Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type66_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_66_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000038A)
#define MACDSP_API1_RX_TERMINATE_TYPE_66_COUNTER_OFFSET      0x0000038A
#define MACDSP_API1_RX_TERMINATE_TYPE_66_COUNTER_INDEX       0x000000E2
#define MACDSP_API1_RX_TERMINATE_TYPE_66_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_66_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_66_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_66_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_66_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_66_COUNTER_RX_TERMINATE_TYPE_66_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_66_COUNTER_RX_TERMINATE_TYPE_66_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_66_COUNTER_RX_TERMINATE_TYPE_66_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_66_COUNTER_RX_TERMINATE_TYPE_66_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_66_counter_rx_terminate_type_66_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_66_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_66_counter_rx_terminate_type_66_counter_setf(uint16_t rxterminatetype66counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype66counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_66_COUNTER_ADDR, (uint32_t)rxterminatetype66counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_67_COUNTER register definition
 *  RxTerminateType67Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type67_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_67_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000038C)
#define MACDSP_API1_RX_TERMINATE_TYPE_67_COUNTER_OFFSET      0x0000038C
#define MACDSP_API1_RX_TERMINATE_TYPE_67_COUNTER_INDEX       0x000000E3
#define MACDSP_API1_RX_TERMINATE_TYPE_67_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_67_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_67_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_67_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_67_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_67_COUNTER_RX_TERMINATE_TYPE_67_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_67_COUNTER_RX_TERMINATE_TYPE_67_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_67_COUNTER_RX_TERMINATE_TYPE_67_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_67_COUNTER_RX_TERMINATE_TYPE_67_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_67_counter_rx_terminate_type_67_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_67_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_67_counter_rx_terminate_type_67_counter_setf(uint16_t rxterminatetype67counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype67counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_67_COUNTER_ADDR, (uint32_t)rxterminatetype67counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_68_COUNTER register definition
 *  RxTerminateType68Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type68_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_68_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000038E)
#define MACDSP_API1_RX_TERMINATE_TYPE_68_COUNTER_OFFSET      0x0000038E
#define MACDSP_API1_RX_TERMINATE_TYPE_68_COUNTER_INDEX       0x000000E3
#define MACDSP_API1_RX_TERMINATE_TYPE_68_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_68_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_68_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_68_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_68_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_68_COUNTER_RX_TERMINATE_TYPE_68_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_68_COUNTER_RX_TERMINATE_TYPE_68_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_68_COUNTER_RX_TERMINATE_TYPE_68_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_68_COUNTER_RX_TERMINATE_TYPE_68_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_68_counter_rx_terminate_type_68_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_68_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_68_counter_rx_terminate_type_68_counter_setf(uint16_t rxterminatetype68counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype68counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_68_COUNTER_ADDR, (uint32_t)rxterminatetype68counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_69_COUNTER register definition
 *  RxTerminateType69Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type69_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_69_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000390)
#define MACDSP_API1_RX_TERMINATE_TYPE_69_COUNTER_OFFSET      0x00000390
#define MACDSP_API1_RX_TERMINATE_TYPE_69_COUNTER_INDEX       0x000000E4
#define MACDSP_API1_RX_TERMINATE_TYPE_69_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_69_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_69_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_69_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_69_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_69_COUNTER_RX_TERMINATE_TYPE_69_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_69_COUNTER_RX_TERMINATE_TYPE_69_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_69_COUNTER_RX_TERMINATE_TYPE_69_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_69_COUNTER_RX_TERMINATE_TYPE_69_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_69_counter_rx_terminate_type_69_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_69_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_69_counter_rx_terminate_type_69_counter_setf(uint16_t rxterminatetype69counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype69counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_69_COUNTER_ADDR, (uint32_t)rxterminatetype69counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_70_COUNTER register definition
 *  RxTerminateType70Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type70_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_70_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000392)
#define MACDSP_API1_RX_TERMINATE_TYPE_70_COUNTER_OFFSET      0x00000392
#define MACDSP_API1_RX_TERMINATE_TYPE_70_COUNTER_INDEX       0x000000E4
#define MACDSP_API1_RX_TERMINATE_TYPE_70_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_70_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_70_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_70_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_70_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_70_COUNTER_RX_TERMINATE_TYPE_70_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_70_COUNTER_RX_TERMINATE_TYPE_70_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_70_COUNTER_RX_TERMINATE_TYPE_70_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_70_COUNTER_RX_TERMINATE_TYPE_70_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_70_counter_rx_terminate_type_70_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_70_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_70_counter_rx_terminate_type_70_counter_setf(uint16_t rxterminatetype70counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype70counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_70_COUNTER_ADDR, (uint32_t)rxterminatetype70counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_71_COUNTER register definition
 *  RxTerminateType71Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type71_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_71_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000394)
#define MACDSP_API1_RX_TERMINATE_TYPE_71_COUNTER_OFFSET      0x00000394
#define MACDSP_API1_RX_TERMINATE_TYPE_71_COUNTER_INDEX       0x000000E5
#define MACDSP_API1_RX_TERMINATE_TYPE_71_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_71_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_71_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_71_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_71_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_71_COUNTER_RX_TERMINATE_TYPE_71_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_71_COUNTER_RX_TERMINATE_TYPE_71_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_71_COUNTER_RX_TERMINATE_TYPE_71_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_71_COUNTER_RX_TERMINATE_TYPE_71_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_71_counter_rx_terminate_type_71_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_71_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_71_counter_rx_terminate_type_71_counter_setf(uint16_t rxterminatetype71counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype71counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_71_COUNTER_ADDR, (uint32_t)rxterminatetype71counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_72_COUNTER register definition
 *  RxTerminateType72Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type72_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_72_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000396)
#define MACDSP_API1_RX_TERMINATE_TYPE_72_COUNTER_OFFSET      0x00000396
#define MACDSP_API1_RX_TERMINATE_TYPE_72_COUNTER_INDEX       0x000000E5
#define MACDSP_API1_RX_TERMINATE_TYPE_72_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_72_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_72_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_72_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_72_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_72_COUNTER_RX_TERMINATE_TYPE_72_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_72_COUNTER_RX_TERMINATE_TYPE_72_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_72_COUNTER_RX_TERMINATE_TYPE_72_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_72_COUNTER_RX_TERMINATE_TYPE_72_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_72_counter_rx_terminate_type_72_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_72_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_72_counter_rx_terminate_type_72_counter_setf(uint16_t rxterminatetype72counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype72counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_72_COUNTER_ADDR, (uint32_t)rxterminatetype72counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_73_COUNTER register definition
 *  RxTerminateType73Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type73_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_73_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000398)
#define MACDSP_API1_RX_TERMINATE_TYPE_73_COUNTER_OFFSET      0x00000398
#define MACDSP_API1_RX_TERMINATE_TYPE_73_COUNTER_INDEX       0x000000E6
#define MACDSP_API1_RX_TERMINATE_TYPE_73_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_73_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_73_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_73_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_73_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_73_COUNTER_RX_TERMINATE_TYPE_73_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_73_COUNTER_RX_TERMINATE_TYPE_73_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_73_COUNTER_RX_TERMINATE_TYPE_73_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_73_COUNTER_RX_TERMINATE_TYPE_73_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_73_counter_rx_terminate_type_73_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_73_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_73_counter_rx_terminate_type_73_counter_setf(uint16_t rxterminatetype73counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype73counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_73_COUNTER_ADDR, (uint32_t)rxterminatetype73counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_74_COUNTER register definition
 *  RxTerminateType74Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type74_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_74_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000039A)
#define MACDSP_API1_RX_TERMINATE_TYPE_74_COUNTER_OFFSET      0x0000039A
#define MACDSP_API1_RX_TERMINATE_TYPE_74_COUNTER_INDEX       0x000000E6
#define MACDSP_API1_RX_TERMINATE_TYPE_74_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_74_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_74_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_74_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_74_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_74_COUNTER_RX_TERMINATE_TYPE_74_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_74_COUNTER_RX_TERMINATE_TYPE_74_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_74_COUNTER_RX_TERMINATE_TYPE_74_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_74_COUNTER_RX_TERMINATE_TYPE_74_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_74_counter_rx_terminate_type_74_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_74_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_74_counter_rx_terminate_type_74_counter_setf(uint16_t rxterminatetype74counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype74counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_74_COUNTER_ADDR, (uint32_t)rxterminatetype74counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_75_COUNTER register definition
 *  RxTerminateType75Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type75_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_75_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000039C)
#define MACDSP_API1_RX_TERMINATE_TYPE_75_COUNTER_OFFSET      0x0000039C
#define MACDSP_API1_RX_TERMINATE_TYPE_75_COUNTER_INDEX       0x000000E7
#define MACDSP_API1_RX_TERMINATE_TYPE_75_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_75_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_75_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_75_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_75_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_75_COUNTER_RX_TERMINATE_TYPE_75_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_75_COUNTER_RX_TERMINATE_TYPE_75_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_75_COUNTER_RX_TERMINATE_TYPE_75_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_75_COUNTER_RX_TERMINATE_TYPE_75_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_75_counter_rx_terminate_type_75_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_75_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_75_counter_rx_terminate_type_75_counter_setf(uint16_t rxterminatetype75counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype75counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_75_COUNTER_ADDR, (uint32_t)rxterminatetype75counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_76_COUNTER register definition
 *  RxTerminateType76Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type76_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_76_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000039E)
#define MACDSP_API1_RX_TERMINATE_TYPE_76_COUNTER_OFFSET      0x0000039E
#define MACDSP_API1_RX_TERMINATE_TYPE_76_COUNTER_INDEX       0x000000E7
#define MACDSP_API1_RX_TERMINATE_TYPE_76_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_76_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_76_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_76_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_76_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_76_COUNTER_RX_TERMINATE_TYPE_76_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_76_COUNTER_RX_TERMINATE_TYPE_76_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_76_COUNTER_RX_TERMINATE_TYPE_76_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_76_COUNTER_RX_TERMINATE_TYPE_76_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_76_counter_rx_terminate_type_76_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_76_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_76_counter_rx_terminate_type_76_counter_setf(uint16_t rxterminatetype76counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype76counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_76_COUNTER_ADDR, (uint32_t)rxterminatetype76counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_77_COUNTER register definition
 *  RxTerminateType77Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type77_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_77_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000003A0)
#define MACDSP_API1_RX_TERMINATE_TYPE_77_COUNTER_OFFSET      0x000003A0
#define MACDSP_API1_RX_TERMINATE_TYPE_77_COUNTER_INDEX       0x000000E8
#define MACDSP_API1_RX_TERMINATE_TYPE_77_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_77_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_77_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_77_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_77_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_77_COUNTER_RX_TERMINATE_TYPE_77_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_77_COUNTER_RX_TERMINATE_TYPE_77_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_77_COUNTER_RX_TERMINATE_TYPE_77_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_77_COUNTER_RX_TERMINATE_TYPE_77_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_77_counter_rx_terminate_type_77_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_77_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_77_counter_rx_terminate_type_77_counter_setf(uint16_t rxterminatetype77counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype77counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_77_COUNTER_ADDR, (uint32_t)rxterminatetype77counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_78_COUNTER register definition
 *  RxTerminateType78Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type78_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_78_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000003A2)
#define MACDSP_API1_RX_TERMINATE_TYPE_78_COUNTER_OFFSET      0x000003A2
#define MACDSP_API1_RX_TERMINATE_TYPE_78_COUNTER_INDEX       0x000000E8
#define MACDSP_API1_RX_TERMINATE_TYPE_78_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_78_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_78_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_78_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_78_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_78_COUNTER_RX_TERMINATE_TYPE_78_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_78_COUNTER_RX_TERMINATE_TYPE_78_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_78_COUNTER_RX_TERMINATE_TYPE_78_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_78_COUNTER_RX_TERMINATE_TYPE_78_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_78_counter_rx_terminate_type_78_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_78_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_78_counter_rx_terminate_type_78_counter_setf(uint16_t rxterminatetype78counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype78counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_78_COUNTER_ADDR, (uint32_t)rxterminatetype78counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_79_COUNTER register definition
 *  RxTerminateType79Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type79_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_79_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000003A4)
#define MACDSP_API1_RX_TERMINATE_TYPE_79_COUNTER_OFFSET      0x000003A4
#define MACDSP_API1_RX_TERMINATE_TYPE_79_COUNTER_INDEX       0x000000E9
#define MACDSP_API1_RX_TERMINATE_TYPE_79_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_79_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_79_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_79_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_79_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_79_COUNTER_RX_TERMINATE_TYPE_79_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_79_COUNTER_RX_TERMINATE_TYPE_79_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_79_COUNTER_RX_TERMINATE_TYPE_79_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_79_COUNTER_RX_TERMINATE_TYPE_79_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_79_counter_rx_terminate_type_79_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_79_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_79_counter_rx_terminate_type_79_counter_setf(uint16_t rxterminatetype79counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype79counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_79_COUNTER_ADDR, (uint32_t)rxterminatetype79counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_80_COUNTER register definition
 *  RxTerminateType80Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type80_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_80_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000003A6)
#define MACDSP_API1_RX_TERMINATE_TYPE_80_COUNTER_OFFSET      0x000003A6
#define MACDSP_API1_RX_TERMINATE_TYPE_80_COUNTER_INDEX       0x000000E9
#define MACDSP_API1_RX_TERMINATE_TYPE_80_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_80_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_80_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_80_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_80_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_80_COUNTER_RX_TERMINATE_TYPE_80_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_80_COUNTER_RX_TERMINATE_TYPE_80_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_80_COUNTER_RX_TERMINATE_TYPE_80_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_80_COUNTER_RX_TERMINATE_TYPE_80_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_80_counter_rx_terminate_type_80_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_80_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_80_counter_rx_terminate_type_80_counter_setf(uint16_t rxterminatetype80counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype80counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_80_COUNTER_ADDR, (uint32_t)rxterminatetype80counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_81_COUNTER register definition
 *  RxTerminateType81Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type81_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_81_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000003A8)
#define MACDSP_API1_RX_TERMINATE_TYPE_81_COUNTER_OFFSET      0x000003A8
#define MACDSP_API1_RX_TERMINATE_TYPE_81_COUNTER_INDEX       0x000000EA
#define MACDSP_API1_RX_TERMINATE_TYPE_81_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_81_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_81_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_81_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_81_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_81_COUNTER_RX_TERMINATE_TYPE_81_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_81_COUNTER_RX_TERMINATE_TYPE_81_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_81_COUNTER_RX_TERMINATE_TYPE_81_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_81_COUNTER_RX_TERMINATE_TYPE_81_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_81_counter_rx_terminate_type_81_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_81_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_81_counter_rx_terminate_type_81_counter_setf(uint16_t rxterminatetype81counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype81counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_81_COUNTER_ADDR, (uint32_t)rxterminatetype81counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_82_COUNTER register definition
 *  RxTerminateType82Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type82_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_82_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000003AA)
#define MACDSP_API1_RX_TERMINATE_TYPE_82_COUNTER_OFFSET      0x000003AA
#define MACDSP_API1_RX_TERMINATE_TYPE_82_COUNTER_INDEX       0x000000EA
#define MACDSP_API1_RX_TERMINATE_TYPE_82_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_82_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_82_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_82_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_82_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_82_COUNTER_RX_TERMINATE_TYPE_82_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_82_COUNTER_RX_TERMINATE_TYPE_82_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_82_COUNTER_RX_TERMINATE_TYPE_82_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_82_COUNTER_RX_TERMINATE_TYPE_82_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_82_counter_rx_terminate_type_82_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_82_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_82_counter_rx_terminate_type_82_counter_setf(uint16_t rxterminatetype82counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype82counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_82_COUNTER_ADDR, (uint32_t)rxterminatetype82counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_83_COUNTER register definition
 *  RxTerminateType83Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type83_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_83_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000003AC)
#define MACDSP_API1_RX_TERMINATE_TYPE_83_COUNTER_OFFSET      0x000003AC
#define MACDSP_API1_RX_TERMINATE_TYPE_83_COUNTER_INDEX       0x000000EB
#define MACDSP_API1_RX_TERMINATE_TYPE_83_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_83_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_83_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_83_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_83_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_83_COUNTER_RX_TERMINATE_TYPE_83_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_83_COUNTER_RX_TERMINATE_TYPE_83_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_83_COUNTER_RX_TERMINATE_TYPE_83_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_83_COUNTER_RX_TERMINATE_TYPE_83_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_83_counter_rx_terminate_type_83_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_83_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_83_counter_rx_terminate_type_83_counter_setf(uint16_t rxterminatetype83counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype83counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_83_COUNTER_ADDR, (uint32_t)rxterminatetype83counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_84_COUNTER register definition
 *  RxTerminateType84Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type84_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_84_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000003AE)
#define MACDSP_API1_RX_TERMINATE_TYPE_84_COUNTER_OFFSET      0x000003AE
#define MACDSP_API1_RX_TERMINATE_TYPE_84_COUNTER_INDEX       0x000000EB
#define MACDSP_API1_RX_TERMINATE_TYPE_84_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_84_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_84_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_84_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_84_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_84_COUNTER_RX_TERMINATE_TYPE_84_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_84_COUNTER_RX_TERMINATE_TYPE_84_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_84_COUNTER_RX_TERMINATE_TYPE_84_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_84_COUNTER_RX_TERMINATE_TYPE_84_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_84_counter_rx_terminate_type_84_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_84_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_84_counter_rx_terminate_type_84_counter_setf(uint16_t rxterminatetype84counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype84counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_84_COUNTER_ADDR, (uint32_t)rxterminatetype84counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_85_COUNTER register definition
 *  RxTerminateType85Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type85_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_85_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000003B0)
#define MACDSP_API1_RX_TERMINATE_TYPE_85_COUNTER_OFFSET      0x000003B0
#define MACDSP_API1_RX_TERMINATE_TYPE_85_COUNTER_INDEX       0x000000EC
#define MACDSP_API1_RX_TERMINATE_TYPE_85_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_85_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_85_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_85_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_85_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_85_COUNTER_RX_TERMINATE_TYPE_85_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_85_COUNTER_RX_TERMINATE_TYPE_85_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_85_COUNTER_RX_TERMINATE_TYPE_85_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_85_COUNTER_RX_TERMINATE_TYPE_85_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_85_counter_rx_terminate_type_85_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_85_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_85_counter_rx_terminate_type_85_counter_setf(uint16_t rxterminatetype85counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype85counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_85_COUNTER_ADDR, (uint32_t)rxterminatetype85counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_86_COUNTER register definition
 *  RxTerminateType86Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type86_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_86_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000003B2)
#define MACDSP_API1_RX_TERMINATE_TYPE_86_COUNTER_OFFSET      0x000003B2
#define MACDSP_API1_RX_TERMINATE_TYPE_86_COUNTER_INDEX       0x000000EC
#define MACDSP_API1_RX_TERMINATE_TYPE_86_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_86_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_86_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_86_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_86_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_86_COUNTER_RX_TERMINATE_TYPE_86_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_86_COUNTER_RX_TERMINATE_TYPE_86_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_86_COUNTER_RX_TERMINATE_TYPE_86_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_86_COUNTER_RX_TERMINATE_TYPE_86_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_86_counter_rx_terminate_type_86_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_86_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_86_counter_rx_terminate_type_86_counter_setf(uint16_t rxterminatetype86counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype86counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_86_COUNTER_ADDR, (uint32_t)rxterminatetype86counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_87_COUNTER register definition
 *  RxTerminateType87Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type87_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_87_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000003B4)
#define MACDSP_API1_RX_TERMINATE_TYPE_87_COUNTER_OFFSET      0x000003B4
#define MACDSP_API1_RX_TERMINATE_TYPE_87_COUNTER_INDEX       0x000000ED
#define MACDSP_API1_RX_TERMINATE_TYPE_87_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_87_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_87_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_87_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_87_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_87_COUNTER_RX_TERMINATE_TYPE_87_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_87_COUNTER_RX_TERMINATE_TYPE_87_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_87_COUNTER_RX_TERMINATE_TYPE_87_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_87_COUNTER_RX_TERMINATE_TYPE_87_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_87_counter_rx_terminate_type_87_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_87_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_87_counter_rx_terminate_type_87_counter_setf(uint16_t rxterminatetype87counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype87counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_87_COUNTER_ADDR, (uint32_t)rxterminatetype87counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_88_COUNTER register definition
 *  RxTerminateType88Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type88_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_88_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000003B6)
#define MACDSP_API1_RX_TERMINATE_TYPE_88_COUNTER_OFFSET      0x000003B6
#define MACDSP_API1_RX_TERMINATE_TYPE_88_COUNTER_INDEX       0x000000ED
#define MACDSP_API1_RX_TERMINATE_TYPE_88_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_88_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_88_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_88_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_88_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_88_COUNTER_RX_TERMINATE_TYPE_88_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_88_COUNTER_RX_TERMINATE_TYPE_88_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_88_COUNTER_RX_TERMINATE_TYPE_88_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_88_COUNTER_RX_TERMINATE_TYPE_88_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_88_counter_rx_terminate_type_88_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_88_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_88_counter_rx_terminate_type_88_counter_setf(uint16_t rxterminatetype88counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype88counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_88_COUNTER_ADDR, (uint32_t)rxterminatetype88counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_89_COUNTER register definition
 *  RxTerminateType89Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type89_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_89_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000003B8)
#define MACDSP_API1_RX_TERMINATE_TYPE_89_COUNTER_OFFSET      0x000003B8
#define MACDSP_API1_RX_TERMINATE_TYPE_89_COUNTER_INDEX       0x000000EE
#define MACDSP_API1_RX_TERMINATE_TYPE_89_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_89_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_89_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_89_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_89_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_89_COUNTER_RX_TERMINATE_TYPE_89_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_89_COUNTER_RX_TERMINATE_TYPE_89_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_89_COUNTER_RX_TERMINATE_TYPE_89_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_89_COUNTER_RX_TERMINATE_TYPE_89_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_89_counter_rx_terminate_type_89_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_89_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_89_counter_rx_terminate_type_89_counter_setf(uint16_t rxterminatetype89counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype89counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_89_COUNTER_ADDR, (uint32_t)rxterminatetype89counter << 0);
}

/**
 * @brief RX_TERMINATE_TYPE_90_COUNTER register definition
 *  RxTerminateType90Counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Terminate_Type90_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_TERMINATE_TYPE_90_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000003BA)
#define MACDSP_API1_RX_TERMINATE_TYPE_90_COUNTER_OFFSET      0x000003BA
#define MACDSP_API1_RX_TERMINATE_TYPE_90_COUNTER_INDEX       0x000000EE
#define MACDSP_API1_RX_TERMINATE_TYPE_90_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_terminate_type_90_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_90_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_terminate_type_90_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_90_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TERMINATE_TYPE_90_COUNTER_RX_TERMINATE_TYPE_90_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_TERMINATE_TYPE_90_COUNTER_RX_TERMINATE_TYPE_90_COUNTER_LSB    0
#define MACDSP_API1_RX_TERMINATE_TYPE_90_COUNTER_RX_TERMINATE_TYPE_90_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_TERMINATE_TYPE_90_COUNTER_RX_TERMINATE_TYPE_90_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_terminate_type_90_counter_rx_terminate_type_90_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TERMINATE_TYPE_90_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_terminate_type_90_counter_rx_terminate_type_90_counter_setf(uint16_t rxterminatetype90counter)
{
	ASSERT_ERR((((uint32_t)rxterminatetype90counter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TERMINATE_TYPE_90_COUNTER_ADDR, (uint32_t)rxterminatetype90counter << 0);
}

/**
 * @brief PROC_LIM_COUNTER register definition
 *  proc_lim_counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 proc_lim_counter          0x0
 * </pre>
 */
#define MACDSP_API1_PROC_LIM_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000003BC)
#define MACDSP_API1_PROC_LIM_COUNTER_OFFSET      0x000003BC
#define MACDSP_API1_PROC_LIM_COUNTER_INDEX       0x000000EF
#define MACDSP_API1_PROC_LIM_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_proc_lim_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_PROC_LIM_COUNTER_ADDR);
}

__INLINE void macdsp_api1_proc_lim_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_PROC_LIM_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_PROC_LIM_COUNTER_PROC_LIM_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_PROC_LIM_COUNTER_PROC_LIM_COUNTER_LSB    0
#define MACDSP_API1_PROC_LIM_COUNTER_PROC_LIM_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_PROC_LIM_COUNTER_PROC_LIM_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_proc_lim_counter_proc_lim_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_PROC_LIM_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_proc_lim_counter_proc_lim_counter_setf(uint16_t proclimcounter)
{
	ASSERT_ERR((((uint32_t)proclimcounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_PROC_LIM_COUNTER_ADDR, (uint32_t)proclimcounter << 0);
}

/**
 * @brief RESAMPLER_CLIPPING_COUNTER register definition
 *  resampler_clipping_counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 resampler_clipping_counter 0x0
 * </pre>
 */
#define MACDSP_API1_RESAMPLER_CLIPPING_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000003BE)
#define MACDSP_API1_RESAMPLER_CLIPPING_COUNTER_OFFSET      0x000003BE
#define MACDSP_API1_RESAMPLER_CLIPPING_COUNTER_INDEX       0x000000EF
#define MACDSP_API1_RESAMPLER_CLIPPING_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_resampler_clipping_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RESAMPLER_CLIPPING_COUNTER_ADDR);
}

__INLINE void macdsp_api1_resampler_clipping_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RESAMPLER_CLIPPING_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RESAMPLER_CLIPPING_COUNTER_RESAMPLER_CLIPPING_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RESAMPLER_CLIPPING_COUNTER_RESAMPLER_CLIPPING_COUNTER_LSB    0
#define MACDSP_API1_RESAMPLER_CLIPPING_COUNTER_RESAMPLER_CLIPPING_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RESAMPLER_CLIPPING_COUNTER_RESAMPLER_CLIPPING_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_resampler_clipping_counter_resampler_clipping_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RESAMPLER_CLIPPING_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_resampler_clipping_counter_resampler_clipping_counter_setf(uint16_t resamplerclippingcounter)
{
	ASSERT_ERR((((uint32_t)resamplerclippingcounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RESAMPLER_CLIPPING_COUNTER_ADDR, (uint32_t)resamplerclippingcounter << 0);
}

/**
 * @brief SKIPHOLD_COUNTER register definition
 *  skiphold_counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 skiphold_counter          0x0
 * </pre>
 */
#define MACDSP_API1_SKIPHOLD_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000003C0)
#define MACDSP_API1_SKIPHOLD_COUNTER_OFFSET      0x000003C0
#define MACDSP_API1_SKIPHOLD_COUNTER_INDEX       0x000000F0
#define MACDSP_API1_SKIPHOLD_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_skiphold_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_SKIPHOLD_COUNTER_ADDR);
}

__INLINE void macdsp_api1_skiphold_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SKIPHOLD_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_SKIPHOLD_COUNTER_SKIPHOLD_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_SKIPHOLD_COUNTER_SKIPHOLD_COUNTER_LSB    0
#define MACDSP_API1_SKIPHOLD_COUNTER_SKIPHOLD_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_SKIPHOLD_COUNTER_SKIPHOLD_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_skiphold_counter_skiphold_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SKIPHOLD_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_skiphold_counter_skiphold_counter_setf(uint16_t skipholdcounter)
{
	ASSERT_ERR((((uint32_t)skipholdcounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SKIPHOLD_COUNTER_ADDR, (uint32_t)skipholdcounter << 0);
}

/**
 * @brief TX_END_COUNTER register definition
 *  tx_end_counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 tx_end_counter            0x0
 * </pre>
 */
#define MACDSP_API1_TX_END_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000003C2)
#define MACDSP_API1_TX_END_COUNTER_OFFSET      0x000003C2
#define MACDSP_API1_TX_END_COUNTER_INDEX       0x000000F0
#define MACDSP_API1_TX_END_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tx_end_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_TX_END_COUNTER_ADDR);
}

__INLINE void macdsp_api1_tx_end_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TX_END_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_TX_END_COUNTER_TX_END_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_TX_END_COUNTER_TX_END_COUNTER_LSB    0
#define MACDSP_API1_TX_END_COUNTER_TX_END_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_TX_END_COUNTER_TX_END_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_tx_end_counter_tx_end_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_END_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_tx_end_counter_tx_end_counter_setf(uint16_t txendcounter)
{
	ASSERT_ERR((((uint32_t)txendcounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TX_END_COUNTER_ADDR, (uint32_t)txendcounter << 0);
}

/**
 * @brief CPE_WRAPPING_COUNTER register definition
 *  CPE_WRAPPING_COUNTER register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 cpe_wraping_counter       0x0
 * </pre>
 */
#define MACDSP_API1_CPE_WRAPPING_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000003C4)
#define MACDSP_API1_CPE_WRAPPING_COUNTER_OFFSET      0x000003C4
#define MACDSP_API1_CPE_WRAPPING_COUNTER_INDEX       0x000000F1
#define MACDSP_API1_CPE_WRAPPING_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_cpe_wrapping_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_CPE_WRAPPING_COUNTER_ADDR);
}

__INLINE void macdsp_api1_cpe_wrapping_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_CPE_WRAPPING_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_CPE_WRAPPING_COUNTER_CPE_WRAPING_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_CPE_WRAPPING_COUNTER_CPE_WRAPING_COUNTER_LSB    0
#define MACDSP_API1_CPE_WRAPPING_COUNTER_CPE_WRAPING_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_CPE_WRAPPING_COUNTER_CPE_WRAPING_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_cpe_wrapping_counter_cpe_wraping_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CPE_WRAPPING_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_cpe_wrapping_counter_cpe_wraping_counter_setf(uint16_t cpewrapingcounter)
{
	ASSERT_ERR((((uint32_t)cpewrapingcounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_CPE_WRAPPING_COUNTER_ADDR, (uint32_t)cpewrapingcounter << 0);
}

/**
 * @brief AGC_UL_DATA_NOT_EXPECTED_COUNTER register definition
 *  AgcUlDataNotExpectedCounter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Agc_Ul_Data_Not_Expected_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_AGC_UL_DATA_NOT_EXPECTED_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000400)
#define MACDSP_API1_AGC_UL_DATA_NOT_EXPECTED_COUNTER_OFFSET      0x00000400
#define MACDSP_API1_AGC_UL_DATA_NOT_EXPECTED_COUNTER_INDEX       0x00000100
#define MACDSP_API1_AGC_UL_DATA_NOT_EXPECTED_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_agc_ul_data_not_expected_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_AGC_UL_DATA_NOT_EXPECTED_COUNTER_ADDR);
}

__INLINE void macdsp_api1_agc_ul_data_not_expected_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_AGC_UL_DATA_NOT_EXPECTED_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_AGC_UL_DATA_NOT_EXPECTED_COUNTER_AGC_UL_DATA_NOT_EXPECTED_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_AGC_UL_DATA_NOT_EXPECTED_COUNTER_AGC_UL_DATA_NOT_EXPECTED_COUNTER_LSB    0
#define MACDSP_API1_AGC_UL_DATA_NOT_EXPECTED_COUNTER_AGC_UL_DATA_NOT_EXPECTED_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_AGC_UL_DATA_NOT_EXPECTED_COUNTER_AGC_UL_DATA_NOT_EXPECTED_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_agc_ul_data_not_expected_counter_agc_ul_data_not_expected_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_AGC_UL_DATA_NOT_EXPECTED_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_agc_ul_data_not_expected_counter_agc_ul_data_not_expected_counter_setf(uint16_t agculdatanotexpectedcounter)
{
	ASSERT_ERR((((uint32_t)agculdatanotexpectedcounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_AGC_UL_DATA_NOT_EXPECTED_COUNTER_ADDR, (uint32_t)agculdatanotexpectedcounter << 0);
}

/**
 * @brief AGC_UL_IDLE_COUNTER register definition
 *  AgcUlIdleCounter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Agc_Ul_Idle_Counter       0x0
 * </pre>
 */
#define MACDSP_API1_AGC_UL_IDLE_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000402)
#define MACDSP_API1_AGC_UL_IDLE_COUNTER_OFFSET      0x00000402
#define MACDSP_API1_AGC_UL_IDLE_COUNTER_INDEX       0x00000100
#define MACDSP_API1_AGC_UL_IDLE_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_agc_ul_idle_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_AGC_UL_IDLE_COUNTER_ADDR);
}

__INLINE void macdsp_api1_agc_ul_idle_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_AGC_UL_IDLE_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_AGC_UL_IDLE_COUNTER_AGC_UL_IDLE_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_AGC_UL_IDLE_COUNTER_AGC_UL_IDLE_COUNTER_LSB    0
#define MACDSP_API1_AGC_UL_IDLE_COUNTER_AGC_UL_IDLE_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_AGC_UL_IDLE_COUNTER_AGC_UL_IDLE_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_agc_ul_idle_counter_agc_ul_idle_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_AGC_UL_IDLE_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_agc_ul_idle_counter_agc_ul_idle_counter_setf(uint16_t agculidlecounter)
{
	ASSERT_ERR((((uint32_t)agculidlecounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_AGC_UL_IDLE_COUNTER_ADDR, (uint32_t)agculidlecounter << 0);
}

/**
 * @brief AGC_UL_WHILE_TX_COUNTER register definition
 *  AgcUlWhileTxCounter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Agc_Ul_While_Tx_Counter   0x0
 * </pre>
 */
#define MACDSP_API1_AGC_UL_WHILE_TX_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000404)
#define MACDSP_API1_AGC_UL_WHILE_TX_COUNTER_OFFSET      0x00000404
#define MACDSP_API1_AGC_UL_WHILE_TX_COUNTER_INDEX       0x00000101
#define MACDSP_API1_AGC_UL_WHILE_TX_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_agc_ul_while_tx_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_AGC_UL_WHILE_TX_COUNTER_ADDR);
}

__INLINE void macdsp_api1_agc_ul_while_tx_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_AGC_UL_WHILE_TX_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_AGC_UL_WHILE_TX_COUNTER_AGC_UL_WHILE_TX_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_AGC_UL_WHILE_TX_COUNTER_AGC_UL_WHILE_TX_COUNTER_LSB    0
#define MACDSP_API1_AGC_UL_WHILE_TX_COUNTER_AGC_UL_WHILE_TX_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_AGC_UL_WHILE_TX_COUNTER_AGC_UL_WHILE_TX_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_agc_ul_while_tx_counter_agc_ul_while_tx_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_AGC_UL_WHILE_TX_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_agc_ul_while_tx_counter_agc_ul_while_tx_counter_setf(uint16_t agculwhiletxcounter)
{
	ASSERT_ERR((((uint32_t)agculwhiletxcounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_AGC_UL_WHILE_TX_COUNTER_ADDR, (uint32_t)agculwhiletxcounter << 0);
}

/**
 * @brief PF_SEARCH_ILLEGAL_END_COUNTER register definition
 *  PfSearchIllegalEndCounter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Pf_Search_Illegal_End_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_PF_SEARCH_ILLEGAL_END_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000406)
#define MACDSP_API1_PF_SEARCH_ILLEGAL_END_COUNTER_OFFSET      0x00000406
#define MACDSP_API1_PF_SEARCH_ILLEGAL_END_COUNTER_INDEX       0x00000101
#define MACDSP_API1_PF_SEARCH_ILLEGAL_END_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_pf_search_illegal_end_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_PF_SEARCH_ILLEGAL_END_COUNTER_ADDR);
}

__INLINE void macdsp_api1_pf_search_illegal_end_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_PF_SEARCH_ILLEGAL_END_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_PF_SEARCH_ILLEGAL_END_COUNTER_PF_SEARCH_ILLEGAL_END_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_PF_SEARCH_ILLEGAL_END_COUNTER_PF_SEARCH_ILLEGAL_END_COUNTER_LSB    0
#define MACDSP_API1_PF_SEARCH_ILLEGAL_END_COUNTER_PF_SEARCH_ILLEGAL_END_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_PF_SEARCH_ILLEGAL_END_COUNTER_PF_SEARCH_ILLEGAL_END_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_pf_search_illegal_end_counter_pf_search_illegal_end_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_PF_SEARCH_ILLEGAL_END_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_pf_search_illegal_end_counter_pf_search_illegal_end_counter_setf(uint16_t pfsearchillegalendcounter)
{
	ASSERT_ERR((((uint32_t)pfsearchillegalendcounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_PF_SEARCH_ILLEGAL_END_COUNTER_ADDR, (uint32_t)pfsearchillegalendcounter << 0);
}

/**
 * @brief RECEPTION_STARTED_COUNTER register definition
 *  ReceptionStartedCounter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Reception_Started_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RECEPTION_STARTED_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000408)
#define MACDSP_API1_RECEPTION_STARTED_COUNTER_OFFSET      0x00000408
#define MACDSP_API1_RECEPTION_STARTED_COUNTER_INDEX       0x00000102
#define MACDSP_API1_RECEPTION_STARTED_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_reception_started_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RECEPTION_STARTED_COUNTER_ADDR);
}

__INLINE void macdsp_api1_reception_started_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RECEPTION_STARTED_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RECEPTION_STARTED_COUNTER_RECEPTION_STARTED_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RECEPTION_STARTED_COUNTER_RECEPTION_STARTED_COUNTER_LSB    0
#define MACDSP_API1_RECEPTION_STARTED_COUNTER_RECEPTION_STARTED_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RECEPTION_STARTED_COUNTER_RECEPTION_STARTED_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_reception_started_counter_reception_started_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RECEPTION_STARTED_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_reception_started_counter_reception_started_counter_setf(uint16_t receptionstartedcounter)
{
	ASSERT_ERR((((uint32_t)receptionstartedcounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RECEPTION_STARTED_COUNTER_ADDR, (uint32_t)receptionstartedcounter << 0);
}

/**
 * @brief RX_VECTOR_MODEM_B_COUNTER register definition
 *  RxVectorModemBCounter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Vector_Modem_BCounter  0x0
 * </pre>
 */
#define MACDSP_API1_RX_VECTOR_MODEM_B_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000040A)
#define MACDSP_API1_RX_VECTOR_MODEM_B_COUNTER_OFFSET      0x0000040A
#define MACDSP_API1_RX_VECTOR_MODEM_B_COUNTER_INDEX       0x00000102
#define MACDSP_API1_RX_VECTOR_MODEM_B_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_vector_modem_b_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_VECTOR_MODEM_B_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_vector_modem_b_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_VECTOR_MODEM_B_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_VECTOR_MODEM_B_COUNTER_RX_VECTOR_MODEM_BCOUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_VECTOR_MODEM_B_COUNTER_RX_VECTOR_MODEM_BCOUNTER_LSB    0
#define MACDSP_API1_RX_VECTOR_MODEM_B_COUNTER_RX_VECTOR_MODEM_BCOUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_VECTOR_MODEM_B_COUNTER_RX_VECTOR_MODEM_BCOUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_vector_modem_b_counter_rx_vector_modem_bcounter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_VECTOR_MODEM_B_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_vector_modem_b_counter_rx_vector_modem_bcounter_setf(uint16_t rxvectormodembcounter)
{
	ASSERT_ERR((((uint32_t)rxvectormodembcounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_VECTOR_MODEM_B_COUNTER_ADDR, (uint32_t)rxvectormodembcounter << 0);
}

/**
 * @brief RX_VECTOR_MODEM_B_ERROR_COUNTER register definition
 *  RxVectorModemBErrorCounter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Vector_Modem_BError_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_VECTOR_MODEM_B_ERROR_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000040C)
#define MACDSP_API1_RX_VECTOR_MODEM_B_ERROR_COUNTER_OFFSET      0x0000040C
#define MACDSP_API1_RX_VECTOR_MODEM_B_ERROR_COUNTER_INDEX       0x00000103
#define MACDSP_API1_RX_VECTOR_MODEM_B_ERROR_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_vector_modem_b_error_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_VECTOR_MODEM_B_ERROR_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_vector_modem_b_error_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_VECTOR_MODEM_B_ERROR_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_VECTOR_MODEM_B_ERROR_COUNTER_RX_VECTOR_MODEM_BERROR_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_VECTOR_MODEM_B_ERROR_COUNTER_RX_VECTOR_MODEM_BERROR_COUNTER_LSB    0
#define MACDSP_API1_RX_VECTOR_MODEM_B_ERROR_COUNTER_RX_VECTOR_MODEM_BERROR_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_VECTOR_MODEM_B_ERROR_COUNTER_RX_VECTOR_MODEM_BERROR_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_vector_modem_b_error_counter_rx_vector_modem_berror_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_VECTOR_MODEM_B_ERROR_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_vector_modem_b_error_counter_rx_vector_modem_berror_counter_setf(uint16_t rxvectormodemberrorcounter)
{
	ASSERT_ERR((((uint32_t)rxvectormodemberrorcounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_VECTOR_MODEM_B_ERROR_COUNTER_ADDR, (uint32_t)rxvectormodemberrorcounter << 0);
}

/**
 * @brief TX_STOP_JUMP_COUNTER register definition
 *  TxStopJumpCounter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Tx_Stop_Jump_Counter      0x0
 * </pre>
 */
#define MACDSP_API1_TX_STOP_JUMP_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000040E)
#define MACDSP_API1_TX_STOP_JUMP_COUNTER_OFFSET      0x0000040E
#define MACDSP_API1_TX_STOP_JUMP_COUNTER_INDEX       0x00000103
#define MACDSP_API1_TX_STOP_JUMP_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tx_stop_jump_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_TX_STOP_JUMP_COUNTER_ADDR);
}

__INLINE void macdsp_api1_tx_stop_jump_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TX_STOP_JUMP_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_TX_STOP_JUMP_COUNTER_TX_STOP_JUMP_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_TX_STOP_JUMP_COUNTER_TX_STOP_JUMP_COUNTER_LSB    0
#define MACDSP_API1_TX_STOP_JUMP_COUNTER_TX_STOP_JUMP_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_TX_STOP_JUMP_COUNTER_TX_STOP_JUMP_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_tx_stop_jump_counter_tx_stop_jump_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_STOP_JUMP_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_tx_stop_jump_counter_tx_stop_jump_counter_setf(uint16_t txstopjumpcounter)
{
	ASSERT_ERR((((uint32_t)txstopjumpcounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TX_STOP_JUMP_COUNTER_ADDR, (uint32_t)txstopjumpcounter << 0);
}

/**
 * @brief TX_ERR_TOT_COUNTER register definition
 *  TxErrTotCounter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Tx_Err_Tot_Counter        0x0
 * </pre>
 */
#define MACDSP_API1_TX_ERR_TOT_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000410)
#define MACDSP_API1_TX_ERR_TOT_COUNTER_OFFSET      0x00000410
#define MACDSP_API1_TX_ERR_TOT_COUNTER_INDEX       0x00000104
#define MACDSP_API1_TX_ERR_TOT_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tx_err_tot_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_TX_ERR_TOT_COUNTER_ADDR);
}

__INLINE void macdsp_api1_tx_err_tot_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TX_ERR_TOT_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_TX_ERR_TOT_COUNTER_TX_ERR_TOT_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_TX_ERR_TOT_COUNTER_TX_ERR_TOT_COUNTER_LSB    0
#define MACDSP_API1_TX_ERR_TOT_COUNTER_TX_ERR_TOT_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_TX_ERR_TOT_COUNTER_TX_ERR_TOT_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_tx_err_tot_counter_tx_err_tot_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_ERR_TOT_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_tx_err_tot_counter_tx_err_tot_counter_setf(uint16_t txerrtotcounter)
{
	ASSERT_ERR((((uint32_t)txerrtotcounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TX_ERR_TOT_COUNTER_ADDR, (uint32_t)txerrtotcounter << 0);
}

/**
 * @brief IQ_CALIB_DONE_CNT_COUNTER register definition
 *  IqCalibDoneCntCounter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Iq_Calib_Done_Cnt_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_IQ_CALIB_DONE_CNT_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000412)
#define MACDSP_API1_IQ_CALIB_DONE_CNT_COUNTER_OFFSET      0x00000412
#define MACDSP_API1_IQ_CALIB_DONE_CNT_COUNTER_INDEX       0x00000104
#define MACDSP_API1_IQ_CALIB_DONE_CNT_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_iq_calib_done_cnt_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_IQ_CALIB_DONE_CNT_COUNTER_ADDR);
}

__INLINE void macdsp_api1_iq_calib_done_cnt_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_IQ_CALIB_DONE_CNT_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_IQ_CALIB_DONE_CNT_COUNTER_IQ_CALIB_DONE_CNT_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_IQ_CALIB_DONE_CNT_COUNTER_IQ_CALIB_DONE_CNT_COUNTER_LSB    0
#define MACDSP_API1_IQ_CALIB_DONE_CNT_COUNTER_IQ_CALIB_DONE_CNT_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_IQ_CALIB_DONE_CNT_COUNTER_IQ_CALIB_DONE_CNT_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_iq_calib_done_cnt_counter_iq_calib_done_cnt_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_IQ_CALIB_DONE_CNT_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_iq_calib_done_cnt_counter_iq_calib_done_cnt_counter_setf(uint16_t iqcalibdonecntcounter)
{
	ASSERT_ERR((((uint32_t)iqcalibdonecntcounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_IQ_CALIB_DONE_CNT_COUNTER_ADDR, (uint32_t)iqcalibdonecntcounter << 0);
}

/**
 * @brief RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER register definition
 *  RxParityErrorWhileRxModemBCounter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Rx_Parity_Error_While_Rx_Modem_BCounter 0x0
 * </pre>
 */
#define MACDSP_API1_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000414)
#define MACDSP_API1_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_OFFSET      0x00000414
#define MACDSP_API1_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_INDEX       0x00000105
#define MACDSP_API1_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_parity_error_while_rx_modem_b_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_ADDR);
}

__INLINE void macdsp_api1_rx_parity_error_while_rx_modem_b_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_RX_PARITY_ERROR_WHILE_RX_MODEM_BCOUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_RX_PARITY_ERROR_WHILE_RX_MODEM_BCOUNTER_LSB    0
#define MACDSP_API1_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_RX_PARITY_ERROR_WHILE_RX_MODEM_BCOUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_RX_PARITY_ERROR_WHILE_RX_MODEM_BCOUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_rx_parity_error_while_rx_modem_b_counter_rx_parity_error_while_rx_modem_bcounter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_parity_error_while_rx_modem_b_counter_rx_parity_error_while_rx_modem_bcounter_setf(uint16_t rxparityerrorwhilerxmodembcounter)
{
	ASSERT_ERR((((uint32_t)rxparityerrorwhilerxmodembcounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_ADDR, (uint32_t)rxparityerrorwhilerxmodembcounter << 0);
}

/**
 * @brief NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER register definition
 *  NumberOfReceviedModemBPacketsCounter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Number_Of_Recevied_Modem_BPackets_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000416)
#define MACDSP_API1_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_OFFSET      0x00000416
#define MACDSP_API1_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_INDEX       0x00000105
#define MACDSP_API1_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_number_of_recevied_modem_b_packets_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR);
}

__INLINE void macdsp_api1_number_of_recevied_modem_b_packets_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_RECEVIED_MODEM_BPACKETS_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_RECEVIED_MODEM_BPACKETS_COUNTER_LSB    0
#define MACDSP_API1_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_RECEVIED_MODEM_BPACKETS_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_RECEVIED_MODEM_BPACKETS_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_number_of_recevied_modem_b_packets_counter_number_of_recevied_modem_bpackets_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_number_of_recevied_modem_b_packets_counter_number_of_recevied_modem_bpackets_counter_setf(uint16_t numberofreceviedmodembpacketscounter)
{
	ASSERT_ERR((((uint32_t)numberofreceviedmodembpacketscounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR, (uint32_t)numberofreceviedmodembpacketscounter << 0);
}

/**
 * @brief NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER register definition
 *  NumberOfAckReceviedModemBPacketsCounter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Number_Of_Ack_Recevied_Modem_BPackets_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000418)
#define MACDSP_API1_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_OFFSET      0x00000418
#define MACDSP_API1_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_INDEX       0x00000106
#define MACDSP_API1_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_number_of_ack_recevied_modem_b_packets_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR);
}

__INLINE void macdsp_api1_number_of_ack_recevied_modem_b_packets_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_ACK_RECEVIED_MODEM_BPACKETS_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_ACK_RECEVIED_MODEM_BPACKETS_COUNTER_LSB    0
#define MACDSP_API1_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_ACK_RECEVIED_MODEM_BPACKETS_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_ACK_RECEVIED_MODEM_BPACKETS_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_number_of_ack_recevied_modem_b_packets_counter_number_of_ack_recevied_modem_bpackets_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_number_of_ack_recevied_modem_b_packets_counter_number_of_ack_recevied_modem_bpackets_counter_setf(uint16_t numberofackreceviedmodembpacketscounter)
{
	ASSERT_ERR((((uint32_t)numberofackreceviedmodembpacketscounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR, (uint32_t)numberofackreceviedmodembpacketscounter << 0);
}

/**
 * @brief NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER register definition
 *  NumberOfTransmittedModemBPacketsCounter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 Number_Of_Transmitted_Modem_BPackets_Counter 0x0
 * </pre>
 */
#define MACDSP_API1_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000041A)
#define MACDSP_API1_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_OFFSET      0x0000041A
#define MACDSP_API1_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_INDEX       0x00000106
#define MACDSP_API1_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_number_of_transmitted_modem_b_packets_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_ADDR);
}

__INLINE void macdsp_api1_number_of_transmitted_modem_b_packets_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_TRANSMITTED_MODEM_BPACKETS_COUNTER_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_TRANSMITTED_MODEM_BPACKETS_COUNTER_LSB    0
#define MACDSP_API1_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_TRANSMITTED_MODEM_BPACKETS_COUNTER_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_TRANSMITTED_MODEM_BPACKETS_COUNTER_RST    0x0

__INLINE uint16_t macdsp_api1_number_of_transmitted_modem_b_packets_counter_number_of_transmitted_modem_bpackets_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_number_of_transmitted_modem_b_packets_counter_number_of_transmitted_modem_bpackets_counter_setf(uint16_t numberoftransmittedmodembpacketscounter)
{
	ASSERT_ERR((((uint32_t)numberoftransmittedmodembpacketscounter << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_ADDR, (uint32_t)numberoftransmittedmodembpacketscounter << 0);
}

/**
 * @brief LEGACY_RATE_6_COUNTER register definition
 *  LEGACY_RATE_6_COUNTER register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LEGACY_RATE_6_COUNTER     0x0
 * </pre>
 */
#define MACDSP_API1_LEGACY_RATE_6_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000430)
#define MACDSP_API1_LEGACY_RATE_6_COUNTER_OFFSET      0x00000430
#define MACDSP_API1_LEGACY_RATE_6_COUNTER_INDEX       0x0000010C
#define MACDSP_API1_LEGACY_RATE_6_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_legacy_rate_6_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_LEGACY_RATE_6_COUNTER_ADDR);
}

__INLINE void macdsp_api1_legacy_rate_6_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_LEGACY_RATE_6_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_LEGACY_RATE_6_COUNTER_LEGACY_RATE_6_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_LEGACY_RATE_6_COUNTER_LEGACY_RATE_6_COUNTER_LSB    0
#define MACDSP_API1_LEGACY_RATE_6_COUNTER_LEGACY_RATE_6_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_LEGACY_RATE_6_COUNTER_LEGACY_RATE_6_COUNTER_RST    0x0

__INLINE uint32_t macdsp_api1_legacy_rate_6_counter_legacy_rate_6_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LEGACY_RATE_6_COUNTER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_legacy_rate_6_counter_legacy_rate_6_counter_setf(uint32_t legacyrate6counter)
{
	ASSERT_ERR((((uint32_t)legacyrate6counter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_LEGACY_RATE_6_COUNTER_ADDR, (uint32_t)legacyrate6counter << 0);
}

/**
 * @brief LEGACY_RATE_NOT_6_COUNTER register definition
 *  LEGACY_RATE_NOT6_COUNTER register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 LEGACY_RATE_NOT6_COUNTER  0x0
 * </pre>
 */
#define MACDSP_API1_LEGACY_RATE_NOT_6_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000434)
#define MACDSP_API1_LEGACY_RATE_NOT_6_COUNTER_OFFSET      0x00000434
#define MACDSP_API1_LEGACY_RATE_NOT_6_COUNTER_INDEX       0x0000010D
#define MACDSP_API1_LEGACY_RATE_NOT_6_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_legacy_rate_not_6_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_LEGACY_RATE_NOT_6_COUNTER_ADDR);
}

__INLINE void macdsp_api1_legacy_rate_not_6_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_LEGACY_RATE_NOT_6_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_LEGACY_RATE_NOT_6_COUNTER_LEGACY_RATE_NOT_6_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_LEGACY_RATE_NOT_6_COUNTER_LEGACY_RATE_NOT_6_COUNTER_LSB    0
#define MACDSP_API1_LEGACY_RATE_NOT_6_COUNTER_LEGACY_RATE_NOT_6_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_LEGACY_RATE_NOT_6_COUNTER_LEGACY_RATE_NOT_6_COUNTER_RST    0x0

__INLINE uint32_t macdsp_api1_legacy_rate_not_6_counter_legacy_rate_not_6_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LEGACY_RATE_NOT_6_COUNTER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_legacy_rate_not_6_counter_legacy_rate_not_6_counter_setf(uint32_t legacyratenot6counter)
{
	ASSERT_ERR((((uint32_t)legacyratenot6counter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_LEGACY_RATE_NOT_6_COUNTER_ADDR, (uint32_t)legacyratenot6counter << 0);
}

/**
 * @brief HT_RECIEVED_COUNTER register definition
 *  HT_RECIEVED_COUNTER register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 HT_RECIEVED_COUNTER       0x0
 * </pre>
 */
#define MACDSP_API1_HT_RECIEVED_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000438)
#define MACDSP_API1_HT_RECIEVED_COUNTER_OFFSET      0x00000438
#define MACDSP_API1_HT_RECIEVED_COUNTER_INDEX       0x0000010E
#define MACDSP_API1_HT_RECIEVED_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_ht_recieved_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_HT_RECIEVED_COUNTER_ADDR);
}

__INLINE void macdsp_api1_ht_recieved_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_HT_RECIEVED_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_HT_RECIEVED_COUNTER_HT_RECIEVED_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_HT_RECIEVED_COUNTER_HT_RECIEVED_COUNTER_LSB    0
#define MACDSP_API1_HT_RECIEVED_COUNTER_HT_RECIEVED_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_HT_RECIEVED_COUNTER_HT_RECIEVED_COUNTER_RST    0x0

__INLINE uint32_t macdsp_api1_ht_recieved_counter_ht_recieved_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_HT_RECIEVED_COUNTER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_ht_recieved_counter_ht_recieved_counter_setf(uint32_t htrecievedcounter)
{
	ASSERT_ERR((((uint32_t)htrecievedcounter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_HT_RECIEVED_COUNTER_ADDR, (uint32_t)htrecievedcounter << 0);
}

/**
 * @brief VHT_RECIEVED_COUNTER register definition
 *  VHT_RECIEVED_COUNTER register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 VHT_RECIEVED_COUNTER      0x0
 * </pre>
 */
#define MACDSP_API1_VHT_RECIEVED_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000043C)
#define MACDSP_API1_VHT_RECIEVED_COUNTER_OFFSET      0x0000043C
#define MACDSP_API1_VHT_RECIEVED_COUNTER_INDEX       0x0000010F
#define MACDSP_API1_VHT_RECIEVED_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_vht_recieved_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_VHT_RECIEVED_COUNTER_ADDR);
}

__INLINE void macdsp_api1_vht_recieved_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_VHT_RECIEVED_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_VHT_RECIEVED_COUNTER_VHT_RECIEVED_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_VHT_RECIEVED_COUNTER_VHT_RECIEVED_COUNTER_LSB    0
#define MACDSP_API1_VHT_RECIEVED_COUNTER_VHT_RECIEVED_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_VHT_RECIEVED_COUNTER_VHT_RECIEVED_COUNTER_RST    0x0

__INLINE uint32_t macdsp_api1_vht_recieved_counter_vht_recieved_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_VHT_RECIEVED_COUNTER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_vht_recieved_counter_vht_recieved_counter_setf(uint32_t vhtrecievedcounter)
{
	ASSERT_ERR((((uint32_t)vhtrecievedcounter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_VHT_RECIEVED_COUNTER_ADDR, (uint32_t)vhtrecievedcounter << 0);
}

/**
 * @brief HE_RECIEVED_COUNTER register definition
 *  HE_RECIEVED_COUNTER register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 HE_RECIEVED_COUNTER       0x0
 * </pre>
 */
#define MACDSP_API1_HE_RECIEVED_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000440)
#define MACDSP_API1_HE_RECIEVED_COUNTER_OFFSET      0x00000440
#define MACDSP_API1_HE_RECIEVED_COUNTER_INDEX       0x00000110
#define MACDSP_API1_HE_RECIEVED_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_he_recieved_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_HE_RECIEVED_COUNTER_ADDR);
}

__INLINE void macdsp_api1_he_recieved_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_HE_RECIEVED_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_HE_RECIEVED_COUNTER_HE_RECIEVED_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_HE_RECIEVED_COUNTER_HE_RECIEVED_COUNTER_LSB    0
#define MACDSP_API1_HE_RECIEVED_COUNTER_HE_RECIEVED_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_HE_RECIEVED_COUNTER_HE_RECIEVED_COUNTER_RST    0x0

__INLINE uint32_t macdsp_api1_he_recieved_counter_he_recieved_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_HE_RECIEVED_COUNTER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_he_recieved_counter_he_recieved_counter_setf(uint32_t herecievedcounter)
{
	ASSERT_ERR((((uint32_t)herecievedcounter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_HE_RECIEVED_COUNTER_ADDR, (uint32_t)herecievedcounter << 0);
}

/**
 * @brief ANY_FAIL_BEFORE_ES_COUNTER register definition
 *  any fail before early split register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 ANY_FAIL_BEFORE_ES        0x0
 * </pre>
 */
#define MACDSP_API1_ANY_FAIL_BEFORE_ES_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000444)
#define MACDSP_API1_ANY_FAIL_BEFORE_ES_COUNTER_OFFSET      0x00000444
#define MACDSP_API1_ANY_FAIL_BEFORE_ES_COUNTER_INDEX       0x00000111
#define MACDSP_API1_ANY_FAIL_BEFORE_ES_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_any_fail_before_es_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_ANY_FAIL_BEFORE_ES_COUNTER_ADDR);
}

__INLINE void macdsp_api1_any_fail_before_es_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_ANY_FAIL_BEFORE_ES_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_ANY_FAIL_BEFORE_ES_COUNTER_ANY_FAIL_BEFORE_ES_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_ANY_FAIL_BEFORE_ES_COUNTER_ANY_FAIL_BEFORE_ES_LSB    0
#define MACDSP_API1_ANY_FAIL_BEFORE_ES_COUNTER_ANY_FAIL_BEFORE_ES_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_ANY_FAIL_BEFORE_ES_COUNTER_ANY_FAIL_BEFORE_ES_RST    0x0

__INLINE uint32_t macdsp_api1_any_fail_before_es_counter_any_fail_before_es_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_ANY_FAIL_BEFORE_ES_COUNTER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_any_fail_before_es_counter_any_fail_before_es_setf(uint32_t anyfailbeforees)
{
	ASSERT_ERR((((uint32_t)anyfailbeforees << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_ANY_FAIL_BEFORE_ES_COUNTER_ADDR, (uint32_t)anyfailbeforees << 0);
}

/**
 * @brief ANY_FAIL_AFTER_ES_COUNTER register definition
 *  any fail after early split counter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 ANY_FAIL_AFTER_ES_COUNTER 0x0
 * </pre>
 */
#define MACDSP_API1_ANY_FAIL_AFTER_ES_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000448)
#define MACDSP_API1_ANY_FAIL_AFTER_ES_COUNTER_OFFSET      0x00000448
#define MACDSP_API1_ANY_FAIL_AFTER_ES_COUNTER_INDEX       0x00000112
#define MACDSP_API1_ANY_FAIL_AFTER_ES_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_any_fail_after_es_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_ANY_FAIL_AFTER_ES_COUNTER_ADDR);
}

__INLINE void macdsp_api1_any_fail_after_es_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_ANY_FAIL_AFTER_ES_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_ANY_FAIL_AFTER_ES_COUNTER_ANY_FAIL_AFTER_ES_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_ANY_FAIL_AFTER_ES_COUNTER_ANY_FAIL_AFTER_ES_COUNTER_LSB    0
#define MACDSP_API1_ANY_FAIL_AFTER_ES_COUNTER_ANY_FAIL_AFTER_ES_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_ANY_FAIL_AFTER_ES_COUNTER_ANY_FAIL_AFTER_ES_COUNTER_RST    0x0

__INLINE uint32_t macdsp_api1_any_fail_after_es_counter_any_fail_after_es_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_ANY_FAIL_AFTER_ES_COUNTER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_any_fail_after_es_counter_any_fail_after_es_counter_setf(uint32_t anyfailafterescounter)
{
	ASSERT_ERR((((uint32_t)anyfailafterescounter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_ANY_FAIL_AFTER_ES_COUNTER_ADDR, (uint32_t)anyfailafterescounter << 0);
}

/**
 * @brief RADAR_DETECTION_COUNTER register definition
 *  RADAR_DETECTION_COUNTER register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RADAR_DETECTION_COUNTER   0x0
 * </pre>
 */
#define MACDSP_API1_RADAR_DETECTION_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000044C)
#define MACDSP_API1_RADAR_DETECTION_COUNTER_OFFSET      0x0000044C
#define MACDSP_API1_RADAR_DETECTION_COUNTER_INDEX       0x00000113
#define MACDSP_API1_RADAR_DETECTION_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_radar_detection_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_RADAR_DETECTION_COUNTER_ADDR);
}

__INLINE void macdsp_api1_radar_detection_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RADAR_DETECTION_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_RADAR_DETECTION_COUNTER_RADAR_DETECTION_COUNTER_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_RADAR_DETECTION_COUNTER_RADAR_DETECTION_COUNTER_LSB    0
#define MACDSP_API1_RADAR_DETECTION_COUNTER_RADAR_DETECTION_COUNTER_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_RADAR_DETECTION_COUNTER_RADAR_DETECTION_COUNTER_RST    0x0

__INLINE uint32_t macdsp_api1_radar_detection_counter_radar_detection_counter_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RADAR_DETECTION_COUNTER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_radar_detection_counter_radar_detection_counter_setf(uint32_t radardetectioncounter)
{
	ASSERT_ERR((((uint32_t)radardetectioncounter << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RADAR_DETECTION_COUNTER_ADDR, (uint32_t)radardetectioncounter << 0);
}

/**
 * @brief TX_BF_COUNTER register definition
 *  TxBfCounter register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 NUM_TX_VECTORS_WITH_BF_ON 0x0
 *    15:00 NUM_TX_VECTORS_WITH_BF_OFF 0x0
 * </pre>
 */
#define MACDSP_API1_TX_BF_COUNTER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000450)
#define MACDSP_API1_TX_BF_COUNTER_OFFSET      0x00000450
#define MACDSP_API1_TX_BF_COUNTER_INDEX       0x00000114
#define MACDSP_API1_TX_BF_COUNTER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tx_bf_counter_get(void)
{
	return REG_PL_RD(MACDSP_API1_TX_BF_COUNTER_ADDR);
}

__INLINE void macdsp_api1_tx_bf_counter_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TX_BF_COUNTER_ADDR, value);
}

// field definitions
#define MACDSP_API1_TX_BF_COUNTER_NUM_TX_VECTORS_WITH_BF_ON_MASK    ((uint32_t)0xFFFF0000)
#define MACDSP_API1_TX_BF_COUNTER_NUM_TX_VECTORS_WITH_BF_ON_LSB    16
#define MACDSP_API1_TX_BF_COUNTER_NUM_TX_VECTORS_WITH_BF_ON_WIDTH    ((uint32_t)0x00000010)
#define MACDSP_API1_TX_BF_COUNTER_NUM_TX_VECTORS_WITH_BF_OFF_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_TX_BF_COUNTER_NUM_TX_VECTORS_WITH_BF_OFF_LSB    0
#define MACDSP_API1_TX_BF_COUNTER_NUM_TX_VECTORS_WITH_BF_OFF_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_TX_BF_COUNTER_NUM_TX_VECTORS_WITH_BF_ON_RST    0x0
#define MACDSP_API1_TX_BF_COUNTER_NUM_TX_VECTORS_WITH_BF_OFF_RST    0x0

__INLINE void macdsp_api1_tx_bf_counter_pack(uint16_t num_tx_vectors_with_bf_on, uint16_t num_tx_vectors_with_bf_off)
{
	ASSERT_ERR((((uint32_t)num_tx_vectors_with_bf_on << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)num_tx_vectors_with_bf_off << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TX_BF_COUNTER_ADDR,  ((uint32_t)num_tx_vectors_with_bf_on << 16) |((uint32_t)num_tx_vectors_with_bf_off << 0));
}

__INLINE void macdsp_api1_tx_bf_counter_unpack(uint16_t* num_tx_vectors_with_bf_on, uint16_t* num_tx_vectors_with_bf_off)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_BF_COUNTER_ADDR);

	*num_tx_vectors_with_bf_on = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*num_tx_vectors_with_bf_off = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t macdsp_api1_tx_bf_counter_num_tx_vectors_with_bf_on_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_BF_COUNTER_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void macdsp_api1_tx_bf_counter_num_tx_vectors_with_bf_on_setf(uint16_t numtxvectorswithbfon)
{
	ASSERT_ERR((((uint32_t)numtxvectorswithbfon << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MACDSP_API1_TX_BF_COUNTER_ADDR, (REG_PL_RD(MACDSP_API1_TX_BF_COUNTER_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)numtxvectorswithbfon <<16));
}
__INLINE uint16_t macdsp_api1_tx_bf_counter_num_tx_vectors_with_bf_off_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_BF_COUNTER_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void macdsp_api1_tx_bf_counter_num_tx_vectors_with_bf_off_setf(uint16_t numtxvectorswithbfoff)
{
	ASSERT_ERR((((uint32_t)numtxvectorswithbfoff << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TX_BF_COUNTER_ADDR, (REG_PL_RD(MACDSP_API1_TX_BF_COUNTER_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)numtxvectorswithbfoff <<0));
}

/**
 * @brief LAST_SIG_B_PROCESS_FLAG register definition
 *  LAST_SIG_B_PROCESS_FLAG register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 last_sigb_proc_flag       0x0
 * </pre>
 */
#define MACDSP_API1_LAST_SIG_B_PROCESS_FLAG_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000600)
#define MACDSP_API1_LAST_SIG_B_PROCESS_FLAG_OFFSET      0x00000600
#define MACDSP_API1_LAST_SIG_B_PROCESS_FLAG_INDEX       0x00000180
#define MACDSP_API1_LAST_SIG_B_PROCESS_FLAG_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_last_sig_b_process_flag_get(void)
{
	return REG_PL_RD(MACDSP_API1_LAST_SIG_B_PROCESS_FLAG_ADDR);
}

__INLINE void macdsp_api1_last_sig_b_process_flag_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_LAST_SIG_B_PROCESS_FLAG_ADDR, value);
}

// field definitions
#define MACDSP_API1_LAST_SIG_B_PROCESS_FLAG_LAST_SIGB_PROC_FLAG_MASK    ((uint32_t)0x000000FF)
#define MACDSP_API1_LAST_SIG_B_PROCESS_FLAG_LAST_SIGB_PROC_FLAG_LSB    0
#define MACDSP_API1_LAST_SIG_B_PROCESS_FLAG_LAST_SIGB_PROC_FLAG_WIDTH    ((uint32_t)0x00000008)

#define MACDSP_API1_LAST_SIG_B_PROCESS_FLAG_LAST_SIGB_PROC_FLAG_RST    0x0

__INLINE uint8_t macdsp_api1_last_sig_b_process_flag_last_sigb_proc_flag_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LAST_SIG_B_PROCESS_FLAG_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void macdsp_api1_last_sig_b_process_flag_last_sigb_proc_flag_setf(uint8_t lastsigbprocflag)
{
	ASSERT_ERR((((uint32_t)lastsigbprocflag << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_LAST_SIG_B_PROCESS_FLAG_ADDR, (uint32_t)lastsigbprocflag << 0);
}

/**
 * @brief SET_DSP_TO_FINE_DC_TRACKING register definition
 *  SET_DSP_TO_FINE_DC_TRACKING register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 set_dsp_to_fine_dc_track  0x0
 * </pre>
 */
#define MACDSP_API1_SET_DSP_TO_FINE_DC_TRACKING_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000602)
#define MACDSP_API1_SET_DSP_TO_FINE_DC_TRACKING_OFFSET      0x00000602
#define MACDSP_API1_SET_DSP_TO_FINE_DC_TRACKING_INDEX       0x00000180
#define MACDSP_API1_SET_DSP_TO_FINE_DC_TRACKING_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_set_dsp_to_fine_dc_tracking_get(void)
{
	return REG_PL_RD(MACDSP_API1_SET_DSP_TO_FINE_DC_TRACKING_ADDR);
}

__INLINE void macdsp_api1_set_dsp_to_fine_dc_tracking_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SET_DSP_TO_FINE_DC_TRACKING_ADDR, value);
}

// field definitions
#define MACDSP_API1_SET_DSP_TO_FINE_DC_TRACKING_SET_DSP_TO_FINE_DC_TRACK_MASK    ((uint32_t)0x000000FF)
#define MACDSP_API1_SET_DSP_TO_FINE_DC_TRACKING_SET_DSP_TO_FINE_DC_TRACK_LSB    0
#define MACDSP_API1_SET_DSP_TO_FINE_DC_TRACKING_SET_DSP_TO_FINE_DC_TRACK_WIDTH    ((uint32_t)0x00000008)

#define MACDSP_API1_SET_DSP_TO_FINE_DC_TRACKING_SET_DSP_TO_FINE_DC_TRACK_RST    0x0

__INLINE uint8_t macdsp_api1_set_dsp_to_fine_dc_tracking_set_dsp_to_fine_dc_track_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SET_DSP_TO_FINE_DC_TRACKING_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void macdsp_api1_set_dsp_to_fine_dc_tracking_set_dsp_to_fine_dc_track_setf(uint8_t setdsptofinedctrack)
{
	ASSERT_ERR((((uint32_t)setdsptofinedctrack << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_SET_DSP_TO_FINE_DC_TRACKING_ADDR, (uint32_t)setdsptofinedctrack << 0);
}

/**
 * @brief DISABLE_CDI_LIMIT register definition
 *  disable_cdi_limit register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    disable_cdi               0              
 * </pre>
 */
#define MACDSP_API1_DISABLE_CDI_LIMIT_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000620)
#define MACDSP_API1_DISABLE_CDI_LIMIT_OFFSET      0x00000620
#define MACDSP_API1_DISABLE_CDI_LIMIT_INDEX       0x00000188
#define MACDSP_API1_DISABLE_CDI_LIMIT_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_disable_cdi_limit_get(void)
{
	return REG_PL_RD(MACDSP_API1_DISABLE_CDI_LIMIT_ADDR);
}

__INLINE void macdsp_api1_disable_cdi_limit_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_DISABLE_CDI_LIMIT_ADDR, value);
}

// field definitions
#define MACDSP_API1_DISABLE_CDI_LIMIT_DISABLE_CDI_BIT    ((uint32_t)0x00000001)
#define MACDSP_API1_DISABLE_CDI_LIMIT_DISABLE_CDI_POS    0

#define MACDSP_API1_DISABLE_CDI_LIMIT_DISABLE_CDI_RST    0x0

__INLINE uint8_t macdsp_api1_disable_cdi_limit_disable_cdi_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DISABLE_CDI_LIMIT_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void macdsp_api1_disable_cdi_limit_disable_cdi_setf(uint8_t disablecdi)
{
	ASSERT_ERR((((uint32_t)disablecdi << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACDSP_API1_DISABLE_CDI_LIMIT_ADDR, (uint32_t)disablecdi << 0);
}

/**
 * @brief NUM_OF_SYM_IN_COARSE register definition
 *  num_of_sym_in_coarse register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 num_of_sym                0x0
 * </pre>
 */
#define MACDSP_API1_NUM_OF_SYM_IN_COARSE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000622)
#define MACDSP_API1_NUM_OF_SYM_IN_COARSE_OFFSET      0x00000622
#define MACDSP_API1_NUM_OF_SYM_IN_COARSE_INDEX       0x00000188
#define MACDSP_API1_NUM_OF_SYM_IN_COARSE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_num_of_sym_in_coarse_get(void)
{
	return REG_PL_RD(MACDSP_API1_NUM_OF_SYM_IN_COARSE_ADDR);
}

__INLINE void macdsp_api1_num_of_sym_in_coarse_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_NUM_OF_SYM_IN_COARSE_ADDR, value);
}

// field definitions
#define MACDSP_API1_NUM_OF_SYM_IN_COARSE_NUM_OF_SYM_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_NUM_OF_SYM_IN_COARSE_NUM_OF_SYM_LSB    0
#define MACDSP_API1_NUM_OF_SYM_IN_COARSE_NUM_OF_SYM_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_NUM_OF_SYM_IN_COARSE_NUM_OF_SYM_RST    0x0

__INLINE uint16_t macdsp_api1_num_of_sym_in_coarse_num_of_sym_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_NUM_OF_SYM_IN_COARSE_ADDR);
	return (uint16_t)(localVal >> 0);
}
__INLINE void macdsp_api1_num_of_sym_in_coarse_num_of_sym_setf(uint16_t numofsym)
{
	ASSERT_ERR((((uint32_t)numofsym << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_NUM_OF_SYM_IN_COARSE_ADDR, (uint32_t)numofsym << 0);
}

/**
 * @brief TB_FORCED register definition
 *  tb_forced register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    tb_forced                 0              
 * </pre>
 */
#define MACDSP_API1_TB_FORCED_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000624)
#define MACDSP_API1_TB_FORCED_OFFSET      0x00000624
#define MACDSP_API1_TB_FORCED_INDEX       0x00000189
#define MACDSP_API1_TB_FORCED_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tb_forced_get(void)
{
	return REG_PL_RD(MACDSP_API1_TB_FORCED_ADDR);
}

__INLINE void macdsp_api1_tb_forced_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TB_FORCED_ADDR, value);
}

// field definitions
#define MACDSP_API1_TB_FORCED_TB_FORCED_BIT    ((uint32_t)0x00000001)
#define MACDSP_API1_TB_FORCED_TB_FORCED_POS    0

#define MACDSP_API1_TB_FORCED_TB_FORCED_RST    0x0

__INLINE uint8_t macdsp_api1_tb_forced_tb_forced_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TB_FORCED_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void macdsp_api1_tb_forced_tb_forced_setf(uint8_t tbforced)
{
	ASSERT_ERR((((uint32_t)tbforced << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACDSP_API1_TB_FORCED_ADDR, (uint32_t)tbforced << 0);
}

/**
 * @brief RESAMPLER_EST_TYPE register definition
 *  resampler_clk_estim_type register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    resampler_mode            0              
 * </pre>
 */
#define MACDSP_API1_RESAMPLER_EST_TYPE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000626)
#define MACDSP_API1_RESAMPLER_EST_TYPE_OFFSET      0x00000626
#define MACDSP_API1_RESAMPLER_EST_TYPE_INDEX       0x00000189
#define MACDSP_API1_RESAMPLER_EST_TYPE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_resampler_est_type_get(void)
{
	return REG_PL_RD(MACDSP_API1_RESAMPLER_EST_TYPE_ADDR);
}

__INLINE void macdsp_api1_resampler_est_type_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RESAMPLER_EST_TYPE_ADDR, value);
}

// field definitions
#define MACDSP_API1_RESAMPLER_EST_TYPE_RESAMPLER_MODE_BIT    ((uint32_t)0x00000001)
#define MACDSP_API1_RESAMPLER_EST_TYPE_RESAMPLER_MODE_POS    0

#define MACDSP_API1_RESAMPLER_EST_TYPE_RESAMPLER_MODE_RST    0x0

__INLINE uint8_t macdsp_api1_resampler_est_type_resampler_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RESAMPLER_EST_TYPE_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void macdsp_api1_resampler_est_type_resampler_mode_setf(uint8_t resamplermode)
{
	ASSERT_ERR((((uint32_t)resamplermode << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACDSP_API1_RESAMPLER_EST_TYPE_ADDR, (uint32_t)resamplermode << 0);
}

/**
 * @brief DISABLE_TFU_EST_OPT register definition
 *  disable_tfu_freq_update_from_cpe register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    disable_freq_est_opt      0              
 * </pre>
 */
#define MACDSP_API1_DISABLE_TFU_EST_OPT_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000628)
#define MACDSP_API1_DISABLE_TFU_EST_OPT_OFFSET      0x00000628
#define MACDSP_API1_DISABLE_TFU_EST_OPT_INDEX       0x0000018A
#define MACDSP_API1_DISABLE_TFU_EST_OPT_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_disable_tfu_est_opt_get(void)
{
	return REG_PL_RD(MACDSP_API1_DISABLE_TFU_EST_OPT_ADDR);
}

__INLINE void macdsp_api1_disable_tfu_est_opt_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_DISABLE_TFU_EST_OPT_ADDR, value);
}

// field definitions
#define MACDSP_API1_DISABLE_TFU_EST_OPT_DISABLE_FREQ_EST_OPT_BIT    ((uint32_t)0x00000001)
#define MACDSP_API1_DISABLE_TFU_EST_OPT_DISABLE_FREQ_EST_OPT_POS    0

#define MACDSP_API1_DISABLE_TFU_EST_OPT_DISABLE_FREQ_EST_OPT_RST    0x0

__INLINE uint8_t macdsp_api1_disable_tfu_est_opt_disable_freq_est_opt_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DISABLE_TFU_EST_OPT_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void macdsp_api1_disable_tfu_est_opt_disable_freq_est_opt_setf(uint8_t disablefreqestopt)
{
	ASSERT_ERR((((uint32_t)disablefreqestopt << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACDSP_API1_DISABLE_TFU_EST_OPT_ADDR, (uint32_t)disablefreqestopt << 0);
}

/**
 * @brief RX_LISTEN_ASSERT register definition
 *  Enable_RX_listen_assert register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    Enable_RX_listen_assert   0              
 * </pre>
 */
#define MACDSP_API1_RX_LISTEN_ASSERT_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000062A)
#define MACDSP_API1_RX_LISTEN_ASSERT_OFFSET      0x0000062A
#define MACDSP_API1_RX_LISTEN_ASSERT_INDEX       0x0000018A
#define MACDSP_API1_RX_LISTEN_ASSERT_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_listen_assert_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_LISTEN_ASSERT_ADDR);
}

__INLINE void macdsp_api1_rx_listen_assert_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_LISTEN_ASSERT_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_LISTEN_ASSERT_ENABLE_RX_LISTEN_ASSERT_BIT    ((uint32_t)0x00000001)
#define MACDSP_API1_RX_LISTEN_ASSERT_ENABLE_RX_LISTEN_ASSERT_POS    0

#define MACDSP_API1_RX_LISTEN_ASSERT_ENABLE_RX_LISTEN_ASSERT_RST    0x0

__INLINE uint8_t macdsp_api1_rx_listen_assert_enable_rx_listen_assert_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_LISTEN_ASSERT_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_listen_assert_enable_rx_listen_assert_setf(uint8_t enablerxlistenassert)
{
	ASSERT_ERR((((uint32_t)enablerxlistenassert << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACDSP_API1_RX_LISTEN_ASSERT_ADDR, (uint32_t)enablerxlistenassert << 0);
}

/**
 * @brief OLYMPUS_A_FLAG register definition
 *  OLYMPUS_A_flag register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    OLYMPUS_A_flag            0              
 * </pre>
 */
#define MACDSP_API1_OLYMPUS_A_FLAG_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000062C)
#define MACDSP_API1_OLYMPUS_A_FLAG_OFFSET      0x0000062C
#define MACDSP_API1_OLYMPUS_A_FLAG_INDEX       0x0000018B
#define MACDSP_API1_OLYMPUS_A_FLAG_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_olympus_a_flag_get(void)
{
	return REG_PL_RD(MACDSP_API1_OLYMPUS_A_FLAG_ADDR);
}

__INLINE void macdsp_api1_olympus_a_flag_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_OLYMPUS_A_FLAG_ADDR, value);
}

// field definitions
#define MACDSP_API1_OLYMPUS_A_FLAG_OLYMPUS_A_FLAG_BIT    ((uint32_t)0x00000001)
#define MACDSP_API1_OLYMPUS_A_FLAG_OLYMPUS_A_FLAG_POS    0

#define MACDSP_API1_OLYMPUS_A_FLAG_OLYMPUS_A_FLAG_RST    0x0

__INLINE uint8_t macdsp_api1_olympus_a_flag_olympus_a_flag_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_OLYMPUS_A_FLAG_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void macdsp_api1_olympus_a_flag_olympus_a_flag_setf(uint8_t olympusaflag)
{
	ASSERT_ERR((((uint32_t)olympusaflag << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACDSP_API1_OLYMPUS_A_FLAG_ADDR, (uint32_t)olympusaflag << 0);
}

/**
 * @brief TX_CSD_ANT_0_1_PTR register definition
 *  TX_CSD_ANT0_1_PTR register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 ANT0_1_PTR                0x0
 * </pre>
 */
#define MACDSP_API1_TX_CSD_ANT_0_1_PTR_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000630)
#define MACDSP_API1_TX_CSD_ANT_0_1_PTR_OFFSET      0x00000630
#define MACDSP_API1_TX_CSD_ANT_0_1_PTR_INDEX       0x0000018C
#define MACDSP_API1_TX_CSD_ANT_0_1_PTR_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tx_csd_ant_0_1_ptr_get(void)
{
	return REG_PL_RD(MACDSP_API1_TX_CSD_ANT_0_1_PTR_ADDR);
}

__INLINE void macdsp_api1_tx_csd_ant_0_1_ptr_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TX_CSD_ANT_0_1_PTR_ADDR, value);
}

// field definitions
#define MACDSP_API1_TX_CSD_ANT_0_1_PTR_ANT_0_1_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_TX_CSD_ANT_0_1_PTR_ANT_0_1_PTR_LSB    0
#define MACDSP_API1_TX_CSD_ANT_0_1_PTR_ANT_0_1_PTR_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_TX_CSD_ANT_0_1_PTR_ANT_0_1_PTR_RST    0x0

__INLINE uint32_t macdsp_api1_tx_csd_ant_0_1_ptr_ant_0_1_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_CSD_ANT_0_1_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_tx_csd_ant_0_1_ptr_ant_0_1_ptr_setf(uint32_t ant01ptr)
{
	ASSERT_ERR((((uint32_t)ant01ptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TX_CSD_ANT_0_1_PTR_ADDR, (uint32_t)ant01ptr << 0);
}

/**
 * @brief TX_CSD_ANT_2_3_PTR register definition
 *  TX_CSD_ANT2_3_PTR register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TX_ANT2_3_PTR             0x0
 * </pre>
 */
#define MACDSP_API1_TX_CSD_ANT_2_3_PTR_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000634)
#define MACDSP_API1_TX_CSD_ANT_2_3_PTR_OFFSET      0x00000634
#define MACDSP_API1_TX_CSD_ANT_2_3_PTR_INDEX       0x0000018D
#define MACDSP_API1_TX_CSD_ANT_2_3_PTR_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tx_csd_ant_2_3_ptr_get(void)
{
	return REG_PL_RD(MACDSP_API1_TX_CSD_ANT_2_3_PTR_ADDR);
}

__INLINE void macdsp_api1_tx_csd_ant_2_3_ptr_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TX_CSD_ANT_2_3_PTR_ADDR, value);
}

// field definitions
#define MACDSP_API1_TX_CSD_ANT_2_3_PTR_TX_ANT_2_3_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_TX_CSD_ANT_2_3_PTR_TX_ANT_2_3_PTR_LSB    0
#define MACDSP_API1_TX_CSD_ANT_2_3_PTR_TX_ANT_2_3_PTR_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_TX_CSD_ANT_2_3_PTR_TX_ANT_2_3_PTR_RST    0x0

__INLINE uint32_t macdsp_api1_tx_csd_ant_2_3_ptr_tx_ant_2_3_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_CSD_ANT_2_3_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_tx_csd_ant_2_3_ptr_tx_ant_2_3_ptr_setf(uint32_t txant23ptr)
{
	ASSERT_ERR((((uint32_t)txant23ptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TX_CSD_ANT_2_3_PTR_ADDR, (uint32_t)txant23ptr << 0);
}

/**
 * @brief TX_CSD_ANT_4_5_PTR register definition
 *  TX_CSD_ANT4_5_PTR register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TX_CSD_ANT4_5_PTR         0x0
 * </pre>
 */
#define MACDSP_API1_TX_CSD_ANT_4_5_PTR_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000638)
#define MACDSP_API1_TX_CSD_ANT_4_5_PTR_OFFSET      0x00000638
#define MACDSP_API1_TX_CSD_ANT_4_5_PTR_INDEX       0x0000018E
#define MACDSP_API1_TX_CSD_ANT_4_5_PTR_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tx_csd_ant_4_5_ptr_get(void)
{
	return REG_PL_RD(MACDSP_API1_TX_CSD_ANT_4_5_PTR_ADDR);
}

__INLINE void macdsp_api1_tx_csd_ant_4_5_ptr_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TX_CSD_ANT_4_5_PTR_ADDR, value);
}

// field definitions
#define MACDSP_API1_TX_CSD_ANT_4_5_PTR_TX_CSD_ANT_4_5_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_TX_CSD_ANT_4_5_PTR_TX_CSD_ANT_4_5_PTR_LSB    0
#define MACDSP_API1_TX_CSD_ANT_4_5_PTR_TX_CSD_ANT_4_5_PTR_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_TX_CSD_ANT_4_5_PTR_TX_CSD_ANT_4_5_PTR_RST    0x0

__INLINE uint32_t macdsp_api1_tx_csd_ant_4_5_ptr_tx_csd_ant_4_5_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_CSD_ANT_4_5_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_tx_csd_ant_4_5_ptr_tx_csd_ant_4_5_ptr_setf(uint32_t txcsdant45ptr)
{
	ASSERT_ERR((((uint32_t)txcsdant45ptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TX_CSD_ANT_4_5_PTR_ADDR, (uint32_t)txcsdant45ptr << 0);
}

/**
 * @brief TX_CSD_UPDATE_INDEX register definition
 *  TX_CSD_UPDATE_INDEX register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:12 TX_CSD_TABLE_INDEX        0x0
 *    11:08 TX_CSD_BW                 0x0
 *    07:04 TX_CSD_NSS                0x0
 *    03:00 TX_CSD_FORMAT_MODE        0x0
 * </pre>
 */
#define MACDSP_API1_TX_CSD_UPDATE_INDEX_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000063C)
#define MACDSP_API1_TX_CSD_UPDATE_INDEX_OFFSET      0x0000063C
#define MACDSP_API1_TX_CSD_UPDATE_INDEX_INDEX       0x0000018F
#define MACDSP_API1_TX_CSD_UPDATE_INDEX_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tx_csd_update_index_get(void)
{
	return REG_PL_RD(MACDSP_API1_TX_CSD_UPDATE_INDEX_ADDR);
}

__INLINE void macdsp_api1_tx_csd_update_index_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TX_CSD_UPDATE_INDEX_ADDR, value);
}

// field definitions
#define MACDSP_API1_TX_CSD_UPDATE_INDEX_TX_CSD_TABLE_INDEX_MASK    ((uint32_t)0x0000F000)
#define MACDSP_API1_TX_CSD_UPDATE_INDEX_TX_CSD_TABLE_INDEX_LSB    12
#define MACDSP_API1_TX_CSD_UPDATE_INDEX_TX_CSD_TABLE_INDEX_WIDTH    ((uint32_t)0x00000004)
#define MACDSP_API1_TX_CSD_UPDATE_INDEX_TX_CSD_BW_MASK    ((uint32_t)0x00000F00)
#define MACDSP_API1_TX_CSD_UPDATE_INDEX_TX_CSD_BW_LSB    8
#define MACDSP_API1_TX_CSD_UPDATE_INDEX_TX_CSD_BW_WIDTH    ((uint32_t)0x00000004)
#define MACDSP_API1_TX_CSD_UPDATE_INDEX_TX_CSD_NSS_MASK    ((uint32_t)0x000000F0)
#define MACDSP_API1_TX_CSD_UPDATE_INDEX_TX_CSD_NSS_LSB    4
#define MACDSP_API1_TX_CSD_UPDATE_INDEX_TX_CSD_NSS_WIDTH    ((uint32_t)0x00000004)
#define MACDSP_API1_TX_CSD_UPDATE_INDEX_TX_CSD_FORMAT_MODE_MASK    ((uint32_t)0x0000000F)
#define MACDSP_API1_TX_CSD_UPDATE_INDEX_TX_CSD_FORMAT_MODE_LSB    0
#define MACDSP_API1_TX_CSD_UPDATE_INDEX_TX_CSD_FORMAT_MODE_WIDTH    ((uint32_t)0x00000004)

#define MACDSP_API1_TX_CSD_UPDATE_INDEX_TX_CSD_TABLE_INDEX_RST    0x0
#define MACDSP_API1_TX_CSD_UPDATE_INDEX_TX_CSD_BW_RST    0x0
#define MACDSP_API1_TX_CSD_UPDATE_INDEX_TX_CSD_NSS_RST    0x0
#define MACDSP_API1_TX_CSD_UPDATE_INDEX_TX_CSD_FORMAT_MODE_RST    0x0

__INLINE void macdsp_api1_tx_csd_update_index_pack(uint8_t tx_csd_table_index, uint8_t tx_csd_bw, uint8_t tx_csd_nss, uint8_t tx_csd_format_mode)
{
	ASSERT_ERR((((uint32_t)tx_csd_table_index << 12) & ~((uint32_t)0x0000F000)) == 0);
	ASSERT_ERR((((uint32_t)tx_csd_bw << 8) & ~((uint32_t)0x00000F00)) == 0);
	ASSERT_ERR((((uint32_t)tx_csd_nss << 4) & ~((uint32_t)0x000000F0)) == 0);
	ASSERT_ERR((((uint32_t)tx_csd_format_mode << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MACDSP_API1_TX_CSD_UPDATE_INDEX_ADDR,  ((uint32_t)tx_csd_table_index << 12) |((uint32_t)tx_csd_bw << 8) |((uint32_t)tx_csd_nss << 4) |((uint32_t)tx_csd_format_mode << 0));
}

__INLINE void macdsp_api1_tx_csd_update_index_unpack(uint8_t* tx_csd_table_index, uint8_t* tx_csd_bw, uint8_t* tx_csd_nss, uint8_t* tx_csd_format_mode)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_CSD_UPDATE_INDEX_ADDR);

	*tx_csd_table_index = (localVal & ((uint32_t)0x0000F000)) >>  12;
	*tx_csd_bw = (localVal & ((uint32_t)0x00000F00)) >>  8;
	*tx_csd_nss = (localVal & ((uint32_t)0x000000F0)) >>  4;
	*tx_csd_format_mode = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t macdsp_api1_tx_csd_update_index_tx_csd_table_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_CSD_UPDATE_INDEX_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000F000)) >> 12);
}
__INLINE void macdsp_api1_tx_csd_update_index_tx_csd_table_index_setf(uint8_t txcsdtableindex)
{
	ASSERT_ERR((((uint32_t)txcsdtableindex << 12) & ~((uint32_t)0x0000F000)) == 0);
	REG_PL_WR(MACDSP_API1_TX_CSD_UPDATE_INDEX_ADDR, (REG_PL_RD(MACDSP_API1_TX_CSD_UPDATE_INDEX_ADDR) & ~((uint32_t)0x0000F000)) | ((uint32_t)txcsdtableindex <<12));
}
__INLINE uint8_t macdsp_api1_tx_csd_update_index_tx_csd_bw_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_CSD_UPDATE_INDEX_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000F00)) >> 8);
}
__INLINE void macdsp_api1_tx_csd_update_index_tx_csd_bw_setf(uint8_t txcsdbw)
{
	ASSERT_ERR((((uint32_t)txcsdbw << 8) & ~((uint32_t)0x00000F00)) == 0);
	REG_PL_WR(MACDSP_API1_TX_CSD_UPDATE_INDEX_ADDR, (REG_PL_RD(MACDSP_API1_TX_CSD_UPDATE_INDEX_ADDR) & ~((uint32_t)0x00000F00)) | ((uint32_t)txcsdbw <<8));
}
__INLINE uint8_t macdsp_api1_tx_csd_update_index_tx_csd_nss_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_CSD_UPDATE_INDEX_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000F0)) >> 4);
}
__INLINE void macdsp_api1_tx_csd_update_index_tx_csd_nss_setf(uint8_t txcsdnss)
{
	ASSERT_ERR((((uint32_t)txcsdnss << 4) & ~((uint32_t)0x000000F0)) == 0);
	REG_PL_WR(MACDSP_API1_TX_CSD_UPDATE_INDEX_ADDR, (REG_PL_RD(MACDSP_API1_TX_CSD_UPDATE_INDEX_ADDR) & ~((uint32_t)0x000000F0)) | ((uint32_t)txcsdnss <<4));
}
__INLINE uint8_t macdsp_api1_tx_csd_update_index_tx_csd_format_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_CSD_UPDATE_INDEX_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void macdsp_api1_tx_csd_update_index_tx_csd_format_mode_setf(uint8_t txcsdformatmode)
{
	ASSERT_ERR((((uint32_t)txcsdformatmode << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MACDSP_API1_TX_CSD_UPDATE_INDEX_ADDR, (REG_PL_RD(MACDSP_API1_TX_CSD_UPDATE_INDEX_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)txcsdformatmode <<0));
}

/**
 * @brief CONFIG_SPACE_SHADOW_VALUE register definition
 *  ConfigSpaceShadowValue register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Config_Space_Shadow_Value 0x0
 * </pre>
 */
#define MACDSP_API1_CONFIG_SPACE_SHADOW_VALUE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000700)
#define MACDSP_API1_CONFIG_SPACE_SHADOW_VALUE_OFFSET      0x00000700
#define MACDSP_API1_CONFIG_SPACE_SHADOW_VALUE_INDEX       0x000001C0
#define MACDSP_API1_CONFIG_SPACE_SHADOW_VALUE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_config_space_shadow_value_get(void)
{
	return REG_PL_RD(MACDSP_API1_CONFIG_SPACE_SHADOW_VALUE_ADDR);
}

__INLINE void macdsp_api1_config_space_shadow_value_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_CONFIG_SPACE_SHADOW_VALUE_ADDR, value);
}

// field definitions
#define MACDSP_API1_CONFIG_SPACE_SHADOW_VALUE_CONFIG_SPACE_SHADOW_VALUE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_CONFIG_SPACE_SHADOW_VALUE_CONFIG_SPACE_SHADOW_VALUE_LSB    0
#define MACDSP_API1_CONFIG_SPACE_SHADOW_VALUE_CONFIG_SPACE_SHADOW_VALUE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_CONFIG_SPACE_SHADOW_VALUE_CONFIG_SPACE_SHADOW_VALUE_RST    0x0

__INLINE uint32_t macdsp_api1_config_space_shadow_value_config_space_shadow_value_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CONFIG_SPACE_SHADOW_VALUE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_config_space_shadow_value_config_space_shadow_value_setf(uint32_t configspaceshadowvalue)
{
	ASSERT_ERR((((uint32_t)configspaceshadowvalue << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_CONFIG_SPACE_SHADOW_VALUE_ADDR, (uint32_t)configspaceshadowvalue << 0);
}

/**
 * @brief AGC_STAT_GAIN_VALUE register definition
 *  AgcStatGainValue register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Agc_Stat_Gain_Value       0x0
 * </pre>
 */
#define MACDSP_API1_AGC_STAT_GAIN_VALUE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000704)
#define MACDSP_API1_AGC_STAT_GAIN_VALUE_OFFSET      0x00000704
#define MACDSP_API1_AGC_STAT_GAIN_VALUE_INDEX       0x000001C1
#define MACDSP_API1_AGC_STAT_GAIN_VALUE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_agc_stat_gain_value_get(void)
{
	return REG_PL_RD(MACDSP_API1_AGC_STAT_GAIN_VALUE_ADDR);
}

__INLINE void macdsp_api1_agc_stat_gain_value_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_AGC_STAT_GAIN_VALUE_ADDR, value);
}

// field definitions
#define MACDSP_API1_AGC_STAT_GAIN_VALUE_AGC_STAT_GAIN_VALUE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_AGC_STAT_GAIN_VALUE_AGC_STAT_GAIN_VALUE_LSB    0
#define MACDSP_API1_AGC_STAT_GAIN_VALUE_AGC_STAT_GAIN_VALUE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_AGC_STAT_GAIN_VALUE_AGC_STAT_GAIN_VALUE_RST    0x0

__INLINE uint32_t macdsp_api1_agc_stat_gain_value_agc_stat_gain_value_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_AGC_STAT_GAIN_VALUE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_agc_stat_gain_value_agc_stat_gain_value_setf(uint32_t agcstatgainvalue)
{
	ASSERT_ERR((((uint32_t)agcstatgainvalue << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_AGC_STAT_GAIN_VALUE_ADDR, (uint32_t)agcstatgainvalue << 0);
}

/**
 * @brief STF_END_INDEX_VALUE register definition
 *  StfEndIndexValue register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Stf_End_Index_Value       0x0
 * </pre>
 */
#define MACDSP_API1_STF_END_INDEX_VALUE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000708)
#define MACDSP_API1_STF_END_INDEX_VALUE_OFFSET      0x00000708
#define MACDSP_API1_STF_END_INDEX_VALUE_INDEX       0x000001C2
#define MACDSP_API1_STF_END_INDEX_VALUE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_stf_end_index_value_get(void)
{
	return REG_PL_RD(MACDSP_API1_STF_END_INDEX_VALUE_ADDR);
}

__INLINE void macdsp_api1_stf_end_index_value_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_STF_END_INDEX_VALUE_ADDR, value);
}

// field definitions
#define MACDSP_API1_STF_END_INDEX_VALUE_STF_END_INDEX_VALUE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_STF_END_INDEX_VALUE_STF_END_INDEX_VALUE_LSB    0
#define MACDSP_API1_STF_END_INDEX_VALUE_STF_END_INDEX_VALUE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_STF_END_INDEX_VALUE_STF_END_INDEX_VALUE_RST    0x0

__INLINE uint32_t macdsp_api1_stf_end_index_value_stf_end_index_value_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_STF_END_INDEX_VALUE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_stf_end_index_value_stf_end_index_value_setf(uint32_t stfendindexvalue)
{
	ASSERT_ERR((((uint32_t)stfendindexvalue << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_STF_END_INDEX_VALUE_ADDR, (uint32_t)stfendindexvalue << 0);
}

/**
 * @brief FFO_PLUS_CFO_VALUE register definition
 *  FfoPlusCfoValue register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Ffo_Plus_Cfo_Value        0x0
 * </pre>
 */
#define MACDSP_API1_FFO_PLUS_CFO_VALUE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000070C)
#define MACDSP_API1_FFO_PLUS_CFO_VALUE_OFFSET      0x0000070C
#define MACDSP_API1_FFO_PLUS_CFO_VALUE_INDEX       0x000001C3
#define MACDSP_API1_FFO_PLUS_CFO_VALUE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_ffo_plus_cfo_value_get(void)
{
	return REG_PL_RD(MACDSP_API1_FFO_PLUS_CFO_VALUE_ADDR);
}

__INLINE void macdsp_api1_ffo_plus_cfo_value_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_FFO_PLUS_CFO_VALUE_ADDR, value);
}

// field definitions
#define MACDSP_API1_FFO_PLUS_CFO_VALUE_FFO_PLUS_CFO_VALUE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_FFO_PLUS_CFO_VALUE_FFO_PLUS_CFO_VALUE_LSB    0
#define MACDSP_API1_FFO_PLUS_CFO_VALUE_FFO_PLUS_CFO_VALUE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_FFO_PLUS_CFO_VALUE_FFO_PLUS_CFO_VALUE_RST    0x0

__INLINE uint32_t macdsp_api1_ffo_plus_cfo_value_ffo_plus_cfo_value_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_FFO_PLUS_CFO_VALUE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_ffo_plus_cfo_value_ffo_plus_cfo_value_setf(uint32_t ffopluscfovalue)
{
	ASSERT_ERR((((uint32_t)ffopluscfovalue << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_FFO_PLUS_CFO_VALUE_ADDR, (uint32_t)ffopluscfovalue << 0);
}

/**
 * @brief SYNC_FIX_VALUE register definition
 *  SyncFixValue register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Sync_Fix_Value            0x0
 * </pre>
 */
#define MACDSP_API1_SYNC_FIX_VALUE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000710)
#define MACDSP_API1_SYNC_FIX_VALUE_OFFSET      0x00000710
#define MACDSP_API1_SYNC_FIX_VALUE_INDEX       0x000001C4
#define MACDSP_API1_SYNC_FIX_VALUE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_sync_fix_value_get(void)
{
	return REG_PL_RD(MACDSP_API1_SYNC_FIX_VALUE_ADDR);
}

__INLINE void macdsp_api1_sync_fix_value_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SYNC_FIX_VALUE_ADDR, value);
}

// field definitions
#define MACDSP_API1_SYNC_FIX_VALUE_SYNC_FIX_VALUE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_SYNC_FIX_VALUE_SYNC_FIX_VALUE_LSB    0
#define MACDSP_API1_SYNC_FIX_VALUE_SYNC_FIX_VALUE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_SYNC_FIX_VALUE_SYNC_FIX_VALUE_RST    0x0

__INLINE uint32_t macdsp_api1_sync_fix_value_sync_fix_value_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SYNC_FIX_VALUE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_sync_fix_value_sync_fix_value_setf(uint32_t syncfixvalue)
{
	ASSERT_ERR((((uint32_t)syncfixvalue << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SYNC_FIX_VALUE_ADDR, (uint32_t)syncfixvalue << 0);
}

/**
 * @brief LEG_REMAIN_SYM_VALUE register definition
 *  LegRemainSymValue register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Leg_Remain_Sym_Value      0x0
 * </pre>
 */
#define MACDSP_API1_LEG_REMAIN_SYM_VALUE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000714)
#define MACDSP_API1_LEG_REMAIN_SYM_VALUE_OFFSET      0x00000714
#define MACDSP_API1_LEG_REMAIN_SYM_VALUE_INDEX       0x000001C5
#define MACDSP_API1_LEG_REMAIN_SYM_VALUE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_leg_remain_sym_value_get(void)
{
	return REG_PL_RD(MACDSP_API1_LEG_REMAIN_SYM_VALUE_ADDR);
}

__INLINE void macdsp_api1_leg_remain_sym_value_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_LEG_REMAIN_SYM_VALUE_ADDR, value);
}

// field definitions
#define MACDSP_API1_LEG_REMAIN_SYM_VALUE_LEG_REMAIN_SYM_VALUE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_LEG_REMAIN_SYM_VALUE_LEG_REMAIN_SYM_VALUE_LSB    0
#define MACDSP_API1_LEG_REMAIN_SYM_VALUE_LEG_REMAIN_SYM_VALUE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_LEG_REMAIN_SYM_VALUE_LEG_REMAIN_SYM_VALUE_RST    0x0

__INLINE uint32_t macdsp_api1_leg_remain_sym_value_leg_remain_sym_value_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LEG_REMAIN_SYM_VALUE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_leg_remain_sym_value_leg_remain_sym_value_setf(uint32_t legremainsymvalue)
{
	ASSERT_ERR((((uint32_t)legremainsymvalue << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_LEG_REMAIN_SYM_VALUE_ADDR, (uint32_t)legremainsymvalue << 0);
}

/**
 * @brief HT_REMIAN_SYMB_VALUE register definition
 *  HtRemianSymbValue register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Ht_Remian_Symb_Value      0x0
 * </pre>
 */
#define MACDSP_API1_HT_REMIAN_SYMB_VALUE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000718)
#define MACDSP_API1_HT_REMIAN_SYMB_VALUE_OFFSET      0x00000718
#define MACDSP_API1_HT_REMIAN_SYMB_VALUE_INDEX       0x000001C6
#define MACDSP_API1_HT_REMIAN_SYMB_VALUE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_ht_remian_symb_value_get(void)
{
	return REG_PL_RD(MACDSP_API1_HT_REMIAN_SYMB_VALUE_ADDR);
}

__INLINE void macdsp_api1_ht_remian_symb_value_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_HT_REMIAN_SYMB_VALUE_ADDR, value);
}

// field definitions
#define MACDSP_API1_HT_REMIAN_SYMB_VALUE_HT_REMIAN_SYMB_VALUE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_HT_REMIAN_SYMB_VALUE_HT_REMIAN_SYMB_VALUE_LSB    0
#define MACDSP_API1_HT_REMIAN_SYMB_VALUE_HT_REMIAN_SYMB_VALUE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_HT_REMIAN_SYMB_VALUE_HT_REMIAN_SYMB_VALUE_RST    0x0

__INLINE uint32_t macdsp_api1_ht_remian_symb_value_ht_remian_symb_value_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_HT_REMIAN_SYMB_VALUE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_ht_remian_symb_value_ht_remian_symb_value_setf(uint32_t htremiansymbvalue)
{
	ASSERT_ERR((((uint32_t)htremiansymbvalue << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_HT_REMIAN_SYMB_VALUE_ADDR, (uint32_t)htremiansymbvalue << 0);
}

/**
 * @brief PPS_SUM_PER_SS_0_VALUE register definition
 *  PpsSumPerSs0Value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Pps_Sum_Per_Ss0_Value     0x0
 * </pre>
 */
#define MACDSP_API1_PPS_SUM_PER_SS_0_VALUE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000071C)
#define MACDSP_API1_PPS_SUM_PER_SS_0_VALUE_OFFSET      0x0000071C
#define MACDSP_API1_PPS_SUM_PER_SS_0_VALUE_INDEX       0x000001C7
#define MACDSP_API1_PPS_SUM_PER_SS_0_VALUE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_pps_sum_per_ss_0_value_get(void)
{
	return REG_PL_RD(MACDSP_API1_PPS_SUM_PER_SS_0_VALUE_ADDR);
}

__INLINE void macdsp_api1_pps_sum_per_ss_0_value_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_PPS_SUM_PER_SS_0_VALUE_ADDR, value);
}

// field definitions
#define MACDSP_API1_PPS_SUM_PER_SS_0_VALUE_PPS_SUM_PER_SS_0_VALUE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_PPS_SUM_PER_SS_0_VALUE_PPS_SUM_PER_SS_0_VALUE_LSB    0
#define MACDSP_API1_PPS_SUM_PER_SS_0_VALUE_PPS_SUM_PER_SS_0_VALUE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_PPS_SUM_PER_SS_0_VALUE_PPS_SUM_PER_SS_0_VALUE_RST    0x0

__INLINE uint32_t macdsp_api1_pps_sum_per_ss_0_value_pps_sum_per_ss_0_value_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_PPS_SUM_PER_SS_0_VALUE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_pps_sum_per_ss_0_value_pps_sum_per_ss_0_value_setf(uint32_t ppssumperss0value)
{
	ASSERT_ERR((((uint32_t)ppssumperss0value << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_PPS_SUM_PER_SS_0_VALUE_ADDR, (uint32_t)ppssumperss0value << 0);
}

/**
 * @brief PPS_SUM_PER_SS_1_VALUE register definition
 *  PpsSumPerSs1Value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Pps_Sum_Per_Ss1_Value     0x0
 * </pre>
 */
#define MACDSP_API1_PPS_SUM_PER_SS_1_VALUE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000720)
#define MACDSP_API1_PPS_SUM_PER_SS_1_VALUE_OFFSET      0x00000720
#define MACDSP_API1_PPS_SUM_PER_SS_1_VALUE_INDEX       0x000001C8
#define MACDSP_API1_PPS_SUM_PER_SS_1_VALUE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_pps_sum_per_ss_1_value_get(void)
{
	return REG_PL_RD(MACDSP_API1_PPS_SUM_PER_SS_1_VALUE_ADDR);
}

__INLINE void macdsp_api1_pps_sum_per_ss_1_value_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_PPS_SUM_PER_SS_1_VALUE_ADDR, value);
}

// field definitions
#define MACDSP_API1_PPS_SUM_PER_SS_1_VALUE_PPS_SUM_PER_SS_1_VALUE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_PPS_SUM_PER_SS_1_VALUE_PPS_SUM_PER_SS_1_VALUE_LSB    0
#define MACDSP_API1_PPS_SUM_PER_SS_1_VALUE_PPS_SUM_PER_SS_1_VALUE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_PPS_SUM_PER_SS_1_VALUE_PPS_SUM_PER_SS_1_VALUE_RST    0x0

__INLINE uint32_t macdsp_api1_pps_sum_per_ss_1_value_pps_sum_per_ss_1_value_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_PPS_SUM_PER_SS_1_VALUE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_pps_sum_per_ss_1_value_pps_sum_per_ss_1_value_setf(uint32_t ppssumperss1value)
{
	ASSERT_ERR((((uint32_t)ppssumperss1value << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_PPS_SUM_PER_SS_1_VALUE_ADDR, (uint32_t)ppssumperss1value << 0);
}

/**
 * @brief PPS_SUM_PER_SS_2_VALUE register definition
 *  PpsSumPerSs2Value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Pps_Sum_Per_Ss2_Value     0x0
 * </pre>
 */
#define MACDSP_API1_PPS_SUM_PER_SS_2_VALUE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000724)
#define MACDSP_API1_PPS_SUM_PER_SS_2_VALUE_OFFSET      0x00000724
#define MACDSP_API1_PPS_SUM_PER_SS_2_VALUE_INDEX       0x000001C9
#define MACDSP_API1_PPS_SUM_PER_SS_2_VALUE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_pps_sum_per_ss_2_value_get(void)
{
	return REG_PL_RD(MACDSP_API1_PPS_SUM_PER_SS_2_VALUE_ADDR);
}

__INLINE void macdsp_api1_pps_sum_per_ss_2_value_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_PPS_SUM_PER_SS_2_VALUE_ADDR, value);
}

// field definitions
#define MACDSP_API1_PPS_SUM_PER_SS_2_VALUE_PPS_SUM_PER_SS_2_VALUE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_PPS_SUM_PER_SS_2_VALUE_PPS_SUM_PER_SS_2_VALUE_LSB    0
#define MACDSP_API1_PPS_SUM_PER_SS_2_VALUE_PPS_SUM_PER_SS_2_VALUE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_PPS_SUM_PER_SS_2_VALUE_PPS_SUM_PER_SS_2_VALUE_RST    0x0

__INLINE uint32_t macdsp_api1_pps_sum_per_ss_2_value_pps_sum_per_ss_2_value_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_PPS_SUM_PER_SS_2_VALUE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_pps_sum_per_ss_2_value_pps_sum_per_ss_2_value_setf(uint32_t ppssumperss2value)
{
	ASSERT_ERR((((uint32_t)ppssumperss2value << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_PPS_SUM_PER_SS_2_VALUE_ADDR, (uint32_t)ppssumperss2value << 0);
}

/**
 * @brief PPS_SUM_PER_SS_3_VALUE register definition
 *  PpsSumPerSs3Value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Pps_Sum_Per_Ss3_Value     0x0
 * </pre>
 */
#define MACDSP_API1_PPS_SUM_PER_SS_3_VALUE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000728)
#define MACDSP_API1_PPS_SUM_PER_SS_3_VALUE_OFFSET      0x00000728
#define MACDSP_API1_PPS_SUM_PER_SS_3_VALUE_INDEX       0x000001CA
#define MACDSP_API1_PPS_SUM_PER_SS_3_VALUE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_pps_sum_per_ss_3_value_get(void)
{
	return REG_PL_RD(MACDSP_API1_PPS_SUM_PER_SS_3_VALUE_ADDR);
}

__INLINE void macdsp_api1_pps_sum_per_ss_3_value_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_PPS_SUM_PER_SS_3_VALUE_ADDR, value);
}

// field definitions
#define MACDSP_API1_PPS_SUM_PER_SS_3_VALUE_PPS_SUM_PER_SS_3_VALUE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_PPS_SUM_PER_SS_3_VALUE_PPS_SUM_PER_SS_3_VALUE_LSB    0
#define MACDSP_API1_PPS_SUM_PER_SS_3_VALUE_PPS_SUM_PER_SS_3_VALUE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_PPS_SUM_PER_SS_3_VALUE_PPS_SUM_PER_SS_3_VALUE_RST    0x0

__INLINE uint32_t macdsp_api1_pps_sum_per_ss_3_value_pps_sum_per_ss_3_value_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_PPS_SUM_PER_SS_3_VALUE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_pps_sum_per_ss_3_value_pps_sum_per_ss_3_value_setf(uint32_t ppssumperss3value)
{
	ASSERT_ERR((((uint32_t)ppssumperss3value << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_PPS_SUM_PER_SS_3_VALUE_ADDR, (uint32_t)ppssumperss3value << 0);
}

/**
 * @brief PPS_SUM_PER_SS_4_VALUE register definition
 *  PpsSumPerSs4Value register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Pps_Sum_Per_Ss4_Value     0x0
 * </pre>
 */
#define MACDSP_API1_PPS_SUM_PER_SS_4_VALUE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000072C)
#define MACDSP_API1_PPS_SUM_PER_SS_4_VALUE_OFFSET      0x0000072C
#define MACDSP_API1_PPS_SUM_PER_SS_4_VALUE_INDEX       0x000001CB
#define MACDSP_API1_PPS_SUM_PER_SS_4_VALUE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_pps_sum_per_ss_4_value_get(void)
{
	return REG_PL_RD(MACDSP_API1_PPS_SUM_PER_SS_4_VALUE_ADDR);
}

__INLINE void macdsp_api1_pps_sum_per_ss_4_value_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_PPS_SUM_PER_SS_4_VALUE_ADDR, value);
}

// field definitions
#define MACDSP_API1_PPS_SUM_PER_SS_4_VALUE_PPS_SUM_PER_SS_4_VALUE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_PPS_SUM_PER_SS_4_VALUE_PPS_SUM_PER_SS_4_VALUE_LSB    0
#define MACDSP_API1_PPS_SUM_PER_SS_4_VALUE_PPS_SUM_PER_SS_4_VALUE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_PPS_SUM_PER_SS_4_VALUE_PPS_SUM_PER_SS_4_VALUE_RST    0x0

__INLINE uint32_t macdsp_api1_pps_sum_per_ss_4_value_pps_sum_per_ss_4_value_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_PPS_SUM_PER_SS_4_VALUE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_pps_sum_per_ss_4_value_pps_sum_per_ss_4_value_setf(uint32_t ppssumperss4value)
{
	ASSERT_ERR((((uint32_t)ppssumperss4value << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_PPS_SUM_PER_SS_4_VALUE_ADDR, (uint32_t)ppssumperss4value << 0);
}

/**
 * @brief RX_N_STS_VALUE register definition
 *  RxNStsValue register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Rx_NSts_Value             0x0
 * </pre>
 */
#define MACDSP_API1_RX_N_STS_VALUE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000730)
#define MACDSP_API1_RX_N_STS_VALUE_OFFSET      0x00000730
#define MACDSP_API1_RX_N_STS_VALUE_INDEX       0x000001CC
#define MACDSP_API1_RX_N_STS_VALUE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_n_sts_value_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_N_STS_VALUE_ADDR);
}

__INLINE void macdsp_api1_rx_n_sts_value_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_N_STS_VALUE_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_N_STS_VALUE_RX_NSTS_VALUE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_RX_N_STS_VALUE_RX_NSTS_VALUE_LSB    0
#define MACDSP_API1_RX_N_STS_VALUE_RX_NSTS_VALUE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_RX_N_STS_VALUE_RX_NSTS_VALUE_RST    0x0

__INLINE uint32_t macdsp_api1_rx_n_sts_value_rx_nsts_value_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_N_STS_VALUE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_n_sts_value_rx_nsts_value_setf(uint32_t rxnstsvalue)
{
	ASSERT_ERR((((uint32_t)rxnstsvalue << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_N_STS_VALUE_ADDR, (uint32_t)rxnstsvalue << 0);
}

/**
 * @brief CALIBRATION_IDX_VALUE register definition
 *  CalibrationIdxValue register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Calibration_Idx_Value     0x0
 * </pre>
 */
#define MACDSP_API1_CALIBRATION_IDX_VALUE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000734)
#define MACDSP_API1_CALIBRATION_IDX_VALUE_OFFSET      0x00000734
#define MACDSP_API1_CALIBRATION_IDX_VALUE_INDEX       0x000001CD
#define MACDSP_API1_CALIBRATION_IDX_VALUE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_calibration_idx_value_get(void)
{
	return REG_PL_RD(MACDSP_API1_CALIBRATION_IDX_VALUE_ADDR);
}

__INLINE void macdsp_api1_calibration_idx_value_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_CALIBRATION_IDX_VALUE_ADDR, value);
}

// field definitions
#define MACDSP_API1_CALIBRATION_IDX_VALUE_CALIBRATION_IDX_VALUE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_CALIBRATION_IDX_VALUE_CALIBRATION_IDX_VALUE_LSB    0
#define MACDSP_API1_CALIBRATION_IDX_VALUE_CALIBRATION_IDX_VALUE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_CALIBRATION_IDX_VALUE_CALIBRATION_IDX_VALUE_RST    0x0

__INLINE uint32_t macdsp_api1_calibration_idx_value_calibration_idx_value_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CALIBRATION_IDX_VALUE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_calibration_idx_value_calibration_idx_value_setf(uint32_t calibrationidxvalue)
{
	ASSERT_ERR((((uint32_t)calibrationidxvalue << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_CALIBRATION_IDX_VALUE_ADDR, (uint32_t)calibrationidxvalue << 0);
}

/**
 * @brief HE_EVM_VAL register definition
 *  EVM TOTAL VALUE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 HE_EVM_VAL                0x0
 * </pre>
 */
#define MACDSP_API1_HE_EVM_VAL_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000738)
#define MACDSP_API1_HE_EVM_VAL_OFFSET      0x00000738
#define MACDSP_API1_HE_EVM_VAL_INDEX       0x000001CE
#define MACDSP_API1_HE_EVM_VAL_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_he_evm_val_get(void)
{
	return REG_PL_RD(MACDSP_API1_HE_EVM_VAL_ADDR);
}

__INLINE void macdsp_api1_he_evm_val_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_HE_EVM_VAL_ADDR, value);
}

// field definitions
#define MACDSP_API1_HE_EVM_VAL_HE_EVM_VAL_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_HE_EVM_VAL_HE_EVM_VAL_LSB    0
#define MACDSP_API1_HE_EVM_VAL_HE_EVM_VAL_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_HE_EVM_VAL_HE_EVM_VAL_RST    0x0

__INLINE uint32_t macdsp_api1_he_evm_val_he_evm_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_HE_EVM_VAL_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_he_evm_val_he_evm_val_setf(uint32_t heevmval)
{
	ASSERT_ERR((((uint32_t)heevmval << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_HE_EVM_VAL_ADDR, (uint32_t)heevmval << 0);
}

/**
 * @brief HE_EVM_SYMB register definition
 *  SYMBOL COUNTER FOR  HE EVM register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 HE_EVM_SYMB               0x0
 * </pre>
 */
#define MACDSP_API1_HE_EVM_SYMB_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000073C)
#define MACDSP_API1_HE_EVM_SYMB_OFFSET      0x0000073C
#define MACDSP_API1_HE_EVM_SYMB_INDEX       0x000001CF
#define MACDSP_API1_HE_EVM_SYMB_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_he_evm_symb_get(void)
{
	return REG_PL_RD(MACDSP_API1_HE_EVM_SYMB_ADDR);
}

__INLINE void macdsp_api1_he_evm_symb_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_HE_EVM_SYMB_ADDR, value);
}

// field definitions
#define MACDSP_API1_HE_EVM_SYMB_HE_EVM_SYMB_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_HE_EVM_SYMB_HE_EVM_SYMB_LSB    0
#define MACDSP_API1_HE_EVM_SYMB_HE_EVM_SYMB_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_HE_EVM_SYMB_HE_EVM_SYMB_RST    0x0

__INLINE uint32_t macdsp_api1_he_evm_symb_he_evm_symb_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_HE_EVM_SYMB_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_he_evm_symb_he_evm_symb_setf(uint32_t heevmsymb)
{
	ASSERT_ERR((((uint32_t)heevmsymb << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_HE_EVM_SYMB_ADDR, (uint32_t)heevmsymb << 0);
}

/**
 * @brief SE_TX_HE_NDP_TABLE_SET register definition
 *  SE_TX_HE_NDP_TABLE_SET register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 SE_TX_HE_NDP_TABLE_SET_FLAG 0x0
 * </pre>
 */
#define MACDSP_API1_SE_TX_HE_NDP_TABLE_SET_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000740)
#define MACDSP_API1_SE_TX_HE_NDP_TABLE_SET_OFFSET      0x00000740
#define MACDSP_API1_SE_TX_HE_NDP_TABLE_SET_INDEX       0x000001D0
#define MACDSP_API1_SE_TX_HE_NDP_TABLE_SET_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_se_tx_he_ndp_table_set_get(void)
{
	return REG_PL_RD(MACDSP_API1_SE_TX_HE_NDP_TABLE_SET_ADDR);
}

__INLINE void macdsp_api1_se_tx_he_ndp_table_set_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SE_TX_HE_NDP_TABLE_SET_ADDR, value);
}

// field definitions
#define MACDSP_API1_SE_TX_HE_NDP_TABLE_SET_SE_TX_HE_NDP_TABLE_SET_FLAG_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_SE_TX_HE_NDP_TABLE_SET_SE_TX_HE_NDP_TABLE_SET_FLAG_LSB    0
#define MACDSP_API1_SE_TX_HE_NDP_TABLE_SET_SE_TX_HE_NDP_TABLE_SET_FLAG_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_SE_TX_HE_NDP_TABLE_SET_SE_TX_HE_NDP_TABLE_SET_FLAG_RST    0x0

__INLINE uint32_t macdsp_api1_se_tx_he_ndp_table_set_se_tx_he_ndp_table_set_flag_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SE_TX_HE_NDP_TABLE_SET_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_se_tx_he_ndp_table_set_se_tx_he_ndp_table_set_flag_setf(uint32_t setxhendptablesetflag)
{
	ASSERT_ERR((((uint32_t)setxhendptablesetflag << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SE_TX_HE_NDP_TABLE_SET_ADDR, (uint32_t)setxhendptablesetflag << 0);
}

/**
 * @brief SCALE_A_HELTF_R_01_FROM_MATLAB register definition
 *  HeLTF AlphaR boost factor RUs 0 1 From Matlab register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_A_HELTF_R1_MATLAB   0x0
 *    15:00 SCALE_A_HELTF_R0_MATLAB   0x0
 * </pre>
 */
#define MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000800)
#define MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_OFFSET      0x00000800
#define MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_INDEX       0x00000200
#define MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_scale_a_heltf_r_01_from_matlab_get(void)
{
	return REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR);
}

__INLINE void macdsp_api1_scale_a_heltf_r_01_from_matlab_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR, value);
}

// field definitions
#define MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_SCALE_A_HELTF_R_1_MATLAB_MASK    ((uint32_t)0xFFFF0000)
#define MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_SCALE_A_HELTF_R_1_MATLAB_LSB    16
#define MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_SCALE_A_HELTF_R_1_MATLAB_WIDTH    ((uint32_t)0x00000010)
#define MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_SCALE_A_HELTF_R_0_MATLAB_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_SCALE_A_HELTF_R_0_MATLAB_LSB    0
#define MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_SCALE_A_HELTF_R_0_MATLAB_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_SCALE_A_HELTF_R_1_MATLAB_RST    0x0
#define MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_SCALE_A_HELTF_R_0_MATLAB_RST    0x0

__INLINE void macdsp_api1_scale_a_heltf_r_01_from_matlab_pack(uint16_t scale_a_heltf_r1_matlab, uint16_t scale_a_heltf_r0_matlab)
{
	ASSERT_ERR((((uint32_t)scale_a_heltf_r1_matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_a_heltf_r0_matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR,  ((uint32_t)scale_a_heltf_r1_matlab << 16) |((uint32_t)scale_a_heltf_r0_matlab << 0));
}

__INLINE void macdsp_api1_scale_a_heltf_r_01_from_matlab_unpack(uint16_t* scale_a_heltf_r1_matlab, uint16_t* scale_a_heltf_r0_matlab)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR);

	*scale_a_heltf_r1_matlab = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_a_heltf_r0_matlab = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t macdsp_api1_scale_a_heltf_r_01_from_matlab_scale_a_heltf_r_1_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void macdsp_api1_scale_a_heltf_r_01_from_matlab_scale_a_heltf_r_1_matlab_setf(uint16_t scaleaheltfr1matlab)
{
	ASSERT_ERR((((uint32_t)scaleaheltfr1matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleaheltfr1matlab <<16));
}
__INLINE uint16_t macdsp_api1_scale_a_heltf_r_01_from_matlab_scale_a_heltf_r_0_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void macdsp_api1_scale_a_heltf_r_01_from_matlab_scale_a_heltf_r_0_matlab_setf(uint16_t scaleaheltfr0matlab)
{
	ASSERT_ERR((((uint32_t)scaleaheltfr0matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleaheltfr0matlab <<0));
}

/**
 * @brief SCALE_A_HELTF_R_23_FROM_MATLAB register definition
 *  HeLTF AlphaR boost factor RUs 2 3 From Matlab register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_A_HELTF_R3_MATLAB   0x0
 *    15:00 SCALE_A_HELTF_R2_MATLAB   0x0
 * </pre>
 */
#define MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000804)
#define MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_OFFSET      0x00000804
#define MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_INDEX       0x00000201
#define MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_scale_a_heltf_r_23_from_matlab_get(void)
{
	return REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR);
}

__INLINE void macdsp_api1_scale_a_heltf_r_23_from_matlab_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR, value);
}

// field definitions
#define MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_SCALE_A_HELTF_R_3_MATLAB_MASK    ((uint32_t)0xFFFF0000)
#define MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_SCALE_A_HELTF_R_3_MATLAB_LSB    16
#define MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_SCALE_A_HELTF_R_3_MATLAB_WIDTH    ((uint32_t)0x00000010)
#define MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_SCALE_A_HELTF_R_2_MATLAB_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_SCALE_A_HELTF_R_2_MATLAB_LSB    0
#define MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_SCALE_A_HELTF_R_2_MATLAB_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_SCALE_A_HELTF_R_3_MATLAB_RST    0x0
#define MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_SCALE_A_HELTF_R_2_MATLAB_RST    0x0

__INLINE void macdsp_api1_scale_a_heltf_r_23_from_matlab_pack(uint16_t scale_a_heltf_r3_matlab, uint16_t scale_a_heltf_r2_matlab)
{
	ASSERT_ERR((((uint32_t)scale_a_heltf_r3_matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_a_heltf_r2_matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR,  ((uint32_t)scale_a_heltf_r3_matlab << 16) |((uint32_t)scale_a_heltf_r2_matlab << 0));
}

__INLINE void macdsp_api1_scale_a_heltf_r_23_from_matlab_unpack(uint16_t* scale_a_heltf_r3_matlab, uint16_t* scale_a_heltf_r2_matlab)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR);

	*scale_a_heltf_r3_matlab = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_a_heltf_r2_matlab = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t macdsp_api1_scale_a_heltf_r_23_from_matlab_scale_a_heltf_r_3_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void macdsp_api1_scale_a_heltf_r_23_from_matlab_scale_a_heltf_r_3_matlab_setf(uint16_t scaleaheltfr3matlab)
{
	ASSERT_ERR((((uint32_t)scaleaheltfr3matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleaheltfr3matlab <<16));
}
__INLINE uint16_t macdsp_api1_scale_a_heltf_r_23_from_matlab_scale_a_heltf_r_2_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void macdsp_api1_scale_a_heltf_r_23_from_matlab_scale_a_heltf_r_2_matlab_setf(uint16_t scaleaheltfr2matlab)
{
	ASSERT_ERR((((uint32_t)scaleaheltfr2matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleaheltfr2matlab <<0));
}

/**
 * @brief SCALE_A_HELTF_R_45_FROM_MATLAB register definition
 *  HeLTF AlphaR boost factor RUs 4 5 From Matlab register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_A_HELTF_R5_MATLAB   0x0
 *    15:00 SCALE_A_HELTF_R4_MATLAB   0x0
 * </pre>
 */
#define MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000808)
#define MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_OFFSET      0x00000808
#define MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_INDEX       0x00000202
#define MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_scale_a_heltf_r_45_from_matlab_get(void)
{
	return REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR);
}

__INLINE void macdsp_api1_scale_a_heltf_r_45_from_matlab_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR, value);
}

// field definitions
#define MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_SCALE_A_HELTF_R_5_MATLAB_MASK    ((uint32_t)0xFFFF0000)
#define MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_SCALE_A_HELTF_R_5_MATLAB_LSB    16
#define MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_SCALE_A_HELTF_R_5_MATLAB_WIDTH    ((uint32_t)0x00000010)
#define MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_SCALE_A_HELTF_R_4_MATLAB_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_SCALE_A_HELTF_R_4_MATLAB_LSB    0
#define MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_SCALE_A_HELTF_R_4_MATLAB_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_SCALE_A_HELTF_R_5_MATLAB_RST    0x0
#define MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_SCALE_A_HELTF_R_4_MATLAB_RST    0x0

__INLINE void macdsp_api1_scale_a_heltf_r_45_from_matlab_pack(uint16_t scale_a_heltf_r5_matlab, uint16_t scale_a_heltf_r4_matlab)
{
	ASSERT_ERR((((uint32_t)scale_a_heltf_r5_matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_a_heltf_r4_matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR,  ((uint32_t)scale_a_heltf_r5_matlab << 16) |((uint32_t)scale_a_heltf_r4_matlab << 0));
}

__INLINE void macdsp_api1_scale_a_heltf_r_45_from_matlab_unpack(uint16_t* scale_a_heltf_r5_matlab, uint16_t* scale_a_heltf_r4_matlab)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR);

	*scale_a_heltf_r5_matlab = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_a_heltf_r4_matlab = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t macdsp_api1_scale_a_heltf_r_45_from_matlab_scale_a_heltf_r_5_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void macdsp_api1_scale_a_heltf_r_45_from_matlab_scale_a_heltf_r_5_matlab_setf(uint16_t scaleaheltfr5matlab)
{
	ASSERT_ERR((((uint32_t)scaleaheltfr5matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleaheltfr5matlab <<16));
}
__INLINE uint16_t macdsp_api1_scale_a_heltf_r_45_from_matlab_scale_a_heltf_r_4_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void macdsp_api1_scale_a_heltf_r_45_from_matlab_scale_a_heltf_r_4_matlab_setf(uint16_t scaleaheltfr4matlab)
{
	ASSERT_ERR((((uint32_t)scaleaheltfr4matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleaheltfr4matlab <<0));
}

/**
 * @brief SCALE_A_HELTF_R_67_FROM_MATLAB register definition
 *  HeLTF AlphaR boost factor RUs 6 7 From Matlab register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_A_HELTF_R7_MATLAB   0x0
 *    15:00 SCALE_A_HELTF_R6_MATLAB   0x0
 * </pre>
 */
#define MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000080C)
#define MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_OFFSET      0x0000080C
#define MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_INDEX       0x00000203
#define MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_scale_a_heltf_r_67_from_matlab_get(void)
{
	return REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR);
}

__INLINE void macdsp_api1_scale_a_heltf_r_67_from_matlab_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR, value);
}

// field definitions
#define MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_SCALE_A_HELTF_R_7_MATLAB_MASK    ((uint32_t)0xFFFF0000)
#define MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_SCALE_A_HELTF_R_7_MATLAB_LSB    16
#define MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_SCALE_A_HELTF_R_7_MATLAB_WIDTH    ((uint32_t)0x00000010)
#define MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_SCALE_A_HELTF_R_6_MATLAB_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_SCALE_A_HELTF_R_6_MATLAB_LSB    0
#define MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_SCALE_A_HELTF_R_6_MATLAB_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_SCALE_A_HELTF_R_7_MATLAB_RST    0x0
#define MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_SCALE_A_HELTF_R_6_MATLAB_RST    0x0

__INLINE void macdsp_api1_scale_a_heltf_r_67_from_matlab_pack(uint16_t scale_a_heltf_r7_matlab, uint16_t scale_a_heltf_r6_matlab)
{
	ASSERT_ERR((((uint32_t)scale_a_heltf_r7_matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_a_heltf_r6_matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR,  ((uint32_t)scale_a_heltf_r7_matlab << 16) |((uint32_t)scale_a_heltf_r6_matlab << 0));
}

__INLINE void macdsp_api1_scale_a_heltf_r_67_from_matlab_unpack(uint16_t* scale_a_heltf_r7_matlab, uint16_t* scale_a_heltf_r6_matlab)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR);

	*scale_a_heltf_r7_matlab = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_a_heltf_r6_matlab = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t macdsp_api1_scale_a_heltf_r_67_from_matlab_scale_a_heltf_r_7_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void macdsp_api1_scale_a_heltf_r_67_from_matlab_scale_a_heltf_r_7_matlab_setf(uint16_t scaleaheltfr7matlab)
{
	ASSERT_ERR((((uint32_t)scaleaheltfr7matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleaheltfr7matlab <<16));
}
__INLINE uint16_t macdsp_api1_scale_a_heltf_r_67_from_matlab_scale_a_heltf_r_6_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void macdsp_api1_scale_a_heltf_r_67_from_matlab_scale_a_heltf_r_6_matlab_setf(uint16_t scaleaheltfr6matlab)
{
	ASSERT_ERR((((uint32_t)scaleaheltfr6matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleaheltfr6matlab <<0));
}

/**
 * @brief SCALE_A_HESTF_R_01_FROM_MATLAB register definition
 *  HeSTF AlphaR boost factor RUs 0 1 From Matlab register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_A_HESTF_R1_MATLAB   0x0
 *    15:00 SCALE_A_HESTF_R0_MATLAB   0x0
 * </pre>
 */
#define MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000810)
#define MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_OFFSET      0x00000810
#define MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_INDEX       0x00000204
#define MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_scale_a_hestf_r_01_from_matlab_get(void)
{
	return REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR);
}

__INLINE void macdsp_api1_scale_a_hestf_r_01_from_matlab_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR, value);
}

// field definitions
#define MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_SCALE_A_HESTF_R_1_MATLAB_MASK    ((uint32_t)0xFFFF0000)
#define MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_SCALE_A_HESTF_R_1_MATLAB_LSB    16
#define MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_SCALE_A_HESTF_R_1_MATLAB_WIDTH    ((uint32_t)0x00000010)
#define MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_SCALE_A_HESTF_R_0_MATLAB_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_SCALE_A_HESTF_R_0_MATLAB_LSB    0
#define MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_SCALE_A_HESTF_R_0_MATLAB_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_SCALE_A_HESTF_R_1_MATLAB_RST    0x0
#define MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_SCALE_A_HESTF_R_0_MATLAB_RST    0x0

__INLINE void macdsp_api1_scale_a_hestf_r_01_from_matlab_pack(uint16_t scale_a_hestf_r1_matlab, uint16_t scale_a_hestf_r0_matlab)
{
	ASSERT_ERR((((uint32_t)scale_a_hestf_r1_matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_a_hestf_r0_matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR,  ((uint32_t)scale_a_hestf_r1_matlab << 16) |((uint32_t)scale_a_hestf_r0_matlab << 0));
}

__INLINE void macdsp_api1_scale_a_hestf_r_01_from_matlab_unpack(uint16_t* scale_a_hestf_r1_matlab, uint16_t* scale_a_hestf_r0_matlab)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR);

	*scale_a_hestf_r1_matlab = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_a_hestf_r0_matlab = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t macdsp_api1_scale_a_hestf_r_01_from_matlab_scale_a_hestf_r_1_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void macdsp_api1_scale_a_hestf_r_01_from_matlab_scale_a_hestf_r_1_matlab_setf(uint16_t scaleahestfr1matlab)
{
	ASSERT_ERR((((uint32_t)scaleahestfr1matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleahestfr1matlab <<16));
}
__INLINE uint16_t macdsp_api1_scale_a_hestf_r_01_from_matlab_scale_a_hestf_r_0_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void macdsp_api1_scale_a_hestf_r_01_from_matlab_scale_a_hestf_r_0_matlab_setf(uint16_t scaleahestfr0matlab)
{
	ASSERT_ERR((((uint32_t)scaleahestfr0matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleahestfr0matlab <<0));
}

/**
 * @brief SCALE_A_HESTF_R_23_FROM_MATLAB register definition
 *  HeSTF AlphaR boost factor RUs 2 3 From Matlab register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_A_HESTF_R3_MATLAB   0x0
 *    15:00 SCALE_A_HESTF_R2_MATLAB   0x0
 * </pre>
 */
#define MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000814)
#define MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_OFFSET      0x00000814
#define MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_INDEX       0x00000205
#define MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_scale_a_hestf_r_23_from_matlab_get(void)
{
	return REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR);
}

__INLINE void macdsp_api1_scale_a_hestf_r_23_from_matlab_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR, value);
}

// field definitions
#define MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_SCALE_A_HESTF_R_3_MATLAB_MASK    ((uint32_t)0xFFFF0000)
#define MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_SCALE_A_HESTF_R_3_MATLAB_LSB    16
#define MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_SCALE_A_HESTF_R_3_MATLAB_WIDTH    ((uint32_t)0x00000010)
#define MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_SCALE_A_HESTF_R_2_MATLAB_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_SCALE_A_HESTF_R_2_MATLAB_LSB    0
#define MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_SCALE_A_HESTF_R_2_MATLAB_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_SCALE_A_HESTF_R_3_MATLAB_RST    0x0
#define MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_SCALE_A_HESTF_R_2_MATLAB_RST    0x0

__INLINE void macdsp_api1_scale_a_hestf_r_23_from_matlab_pack(uint16_t scale_a_hestf_r3_matlab, uint16_t scale_a_hestf_r2_matlab)
{
	ASSERT_ERR((((uint32_t)scale_a_hestf_r3_matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_a_hestf_r2_matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR,  ((uint32_t)scale_a_hestf_r3_matlab << 16) |((uint32_t)scale_a_hestf_r2_matlab << 0));
}

__INLINE void macdsp_api1_scale_a_hestf_r_23_from_matlab_unpack(uint16_t* scale_a_hestf_r3_matlab, uint16_t* scale_a_hestf_r2_matlab)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR);

	*scale_a_hestf_r3_matlab = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_a_hestf_r2_matlab = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t macdsp_api1_scale_a_hestf_r_23_from_matlab_scale_a_hestf_r_3_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void macdsp_api1_scale_a_hestf_r_23_from_matlab_scale_a_hestf_r_3_matlab_setf(uint16_t scaleahestfr3matlab)
{
	ASSERT_ERR((((uint32_t)scaleahestfr3matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleahestfr3matlab <<16));
}
__INLINE uint16_t macdsp_api1_scale_a_hestf_r_23_from_matlab_scale_a_hestf_r_2_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void macdsp_api1_scale_a_hestf_r_23_from_matlab_scale_a_hestf_r_2_matlab_setf(uint16_t scaleahestfr2matlab)
{
	ASSERT_ERR((((uint32_t)scaleahestfr2matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleahestfr2matlab <<0));
}

/**
 * @brief SCALE_A_HESTF_R_45_FROM_MATLAB register definition
 *  HeSTF AlphaR boost factor RUs 4 5 From Matlab register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_A_HESTF_R5_MATLAB   0x0
 *    15:00 SCALE_A_HESTF_R4_MATLAB   0x0
 * </pre>
 */
#define MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000818)
#define MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_OFFSET      0x00000818
#define MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_INDEX       0x00000206
#define MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_scale_a_hestf_r_45_from_matlab_get(void)
{
	return REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR);
}

__INLINE void macdsp_api1_scale_a_hestf_r_45_from_matlab_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR, value);
}

// field definitions
#define MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_SCALE_A_HESTF_R_5_MATLAB_MASK    ((uint32_t)0xFFFF0000)
#define MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_SCALE_A_HESTF_R_5_MATLAB_LSB    16
#define MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_SCALE_A_HESTF_R_5_MATLAB_WIDTH    ((uint32_t)0x00000010)
#define MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_SCALE_A_HESTF_R_4_MATLAB_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_SCALE_A_HESTF_R_4_MATLAB_LSB    0
#define MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_SCALE_A_HESTF_R_4_MATLAB_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_SCALE_A_HESTF_R_5_MATLAB_RST    0x0
#define MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_SCALE_A_HESTF_R_4_MATLAB_RST    0x0

__INLINE void macdsp_api1_scale_a_hestf_r_45_from_matlab_pack(uint16_t scale_a_hestf_r5_matlab, uint16_t scale_a_hestf_r4_matlab)
{
	ASSERT_ERR((((uint32_t)scale_a_hestf_r5_matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_a_hestf_r4_matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR,  ((uint32_t)scale_a_hestf_r5_matlab << 16) |((uint32_t)scale_a_hestf_r4_matlab << 0));
}

__INLINE void macdsp_api1_scale_a_hestf_r_45_from_matlab_unpack(uint16_t* scale_a_hestf_r5_matlab, uint16_t* scale_a_hestf_r4_matlab)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR);

	*scale_a_hestf_r5_matlab = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_a_hestf_r4_matlab = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t macdsp_api1_scale_a_hestf_r_45_from_matlab_scale_a_hestf_r_5_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void macdsp_api1_scale_a_hestf_r_45_from_matlab_scale_a_hestf_r_5_matlab_setf(uint16_t scaleahestfr5matlab)
{
	ASSERT_ERR((((uint32_t)scaleahestfr5matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleahestfr5matlab <<16));
}
__INLINE uint16_t macdsp_api1_scale_a_hestf_r_45_from_matlab_scale_a_hestf_r_4_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void macdsp_api1_scale_a_hestf_r_45_from_matlab_scale_a_hestf_r_4_matlab_setf(uint16_t scaleahestfr4matlab)
{
	ASSERT_ERR((((uint32_t)scaleahestfr4matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleahestfr4matlab <<0));
}

/**
 * @brief SCALE_A_HESTF_R_67_FROM_MATLAB register definition
 *  HeSTF AlphaR boost factor RUs 6 7 From Matlab register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_A_HESTF_R7_MATLAB   0x0
 *    15:00 SCALE_A_HESTF_R6_MATLAB   0x0
 * </pre>
 */
#define MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000081C)
#define MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_OFFSET      0x0000081C
#define MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_INDEX       0x00000207
#define MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_scale_a_hestf_r_67_from_matlab_get(void)
{
	return REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR);
}

__INLINE void macdsp_api1_scale_a_hestf_r_67_from_matlab_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR, value);
}

// field definitions
#define MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_SCALE_A_HESTF_R_7_MATLAB_MASK    ((uint32_t)0xFFFF0000)
#define MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_SCALE_A_HESTF_R_7_MATLAB_LSB    16
#define MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_SCALE_A_HESTF_R_7_MATLAB_WIDTH    ((uint32_t)0x00000010)
#define MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_SCALE_A_HESTF_R_6_MATLAB_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_SCALE_A_HESTF_R_6_MATLAB_LSB    0
#define MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_SCALE_A_HESTF_R_6_MATLAB_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_SCALE_A_HESTF_R_7_MATLAB_RST    0x0
#define MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_SCALE_A_HESTF_R_6_MATLAB_RST    0x0

__INLINE void macdsp_api1_scale_a_hestf_r_67_from_matlab_pack(uint16_t scale_a_hestf_r7_matlab, uint16_t scale_a_hestf_r6_matlab)
{
	ASSERT_ERR((((uint32_t)scale_a_hestf_r7_matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_a_hestf_r6_matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR,  ((uint32_t)scale_a_hestf_r7_matlab << 16) |((uint32_t)scale_a_hestf_r6_matlab << 0));
}

__INLINE void macdsp_api1_scale_a_hestf_r_67_from_matlab_unpack(uint16_t* scale_a_hestf_r7_matlab, uint16_t* scale_a_hestf_r6_matlab)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR);

	*scale_a_hestf_r7_matlab = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_a_hestf_r6_matlab = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t macdsp_api1_scale_a_hestf_r_67_from_matlab_scale_a_hestf_r_7_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void macdsp_api1_scale_a_hestf_r_67_from_matlab_scale_a_hestf_r_7_matlab_setf(uint16_t scaleahestfr7matlab)
{
	ASSERT_ERR((((uint32_t)scaleahestfr7matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scaleahestfr7matlab <<16));
}
__INLINE uint16_t macdsp_api1_scale_a_hestf_r_67_from_matlab_scale_a_hestf_r_6_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void macdsp_api1_scale_a_hestf_r_67_from_matlab_scale_a_hestf_r_6_matlab_setf(uint16_t scaleahestfr6matlab)
{
	ASSERT_ERR((((uint32_t)scaleahestfr6matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scaleahestfr6matlab <<0));
}

/**
 * @brief SCALE_ALPHA_R_01_FROM_MATLAB register definition
 *  HeData AlphaR boost factor RUs 0 1 From Matlab register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_ALPHA_R1_Matlab     0x0
 *    15:00 SCALE_ALPHA_R0_Matlab     0x0
 * </pre>
 */
#define MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000820)
#define MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_OFFSET      0x00000820
#define MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_INDEX       0x00000208
#define MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_scale_alpha_r_01_from_matlab_get(void)
{
	return REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR);
}

__INLINE void macdsp_api1_scale_alpha_r_01_from_matlab_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR, value);
}

// field definitions
#define MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_SCALE_ALPHA_R_1_MATLAB_MASK    ((uint32_t)0xFFFF0000)
#define MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_SCALE_ALPHA_R_1_MATLAB_LSB    16
#define MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_SCALE_ALPHA_R_1_MATLAB_WIDTH    ((uint32_t)0x00000010)
#define MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_SCALE_ALPHA_R_0_MATLAB_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_SCALE_ALPHA_R_0_MATLAB_LSB    0
#define MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_SCALE_ALPHA_R_0_MATLAB_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_SCALE_ALPHA_R_1_MATLAB_RST    0x0
#define MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_SCALE_ALPHA_R_0_MATLAB_RST    0x0

__INLINE void macdsp_api1_scale_alpha_r_01_from_matlab_pack(uint16_t scale_alpha_r1_matlab, uint16_t scale_alpha_r0_matlab)
{
	ASSERT_ERR((((uint32_t)scale_alpha_r1_matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_alpha_r0_matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR,  ((uint32_t)scale_alpha_r1_matlab << 16) |((uint32_t)scale_alpha_r0_matlab << 0));
}

__INLINE void macdsp_api1_scale_alpha_r_01_from_matlab_unpack(uint16_t* scale_alpha_r1_matlab, uint16_t* scale_alpha_r0_matlab)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR);

	*scale_alpha_r1_matlab = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_alpha_r0_matlab = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t macdsp_api1_scale_alpha_r_01_from_matlab_scale_alpha_r_1_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void macdsp_api1_scale_alpha_r_01_from_matlab_scale_alpha_r_1_matlab_setf(uint16_t scalealphar1matlab)
{
	ASSERT_ERR((((uint32_t)scalealphar1matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalealphar1matlab <<16));
}
__INLINE uint16_t macdsp_api1_scale_alpha_r_01_from_matlab_scale_alpha_r_0_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void macdsp_api1_scale_alpha_r_01_from_matlab_scale_alpha_r_0_matlab_setf(uint16_t scalealphar0matlab)
{
	ASSERT_ERR((((uint32_t)scalealphar0matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalealphar0matlab <<0));
}

/**
 * @brief SCALE_ALPHA_R_23_FROM_MATLAB register definition
 *  HeData AlphaR boost factor RUs 2 3 From Matlab register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_ALPHA_R3_Matlab     0x0
 *    15:00 SCALE_ALPHA_R2_Matlab     0x0
 * </pre>
 */
#define MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000824)
#define MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_OFFSET      0x00000824
#define MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_INDEX       0x00000209
#define MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_scale_alpha_r_23_from_matlab_get(void)
{
	return REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR);
}

__INLINE void macdsp_api1_scale_alpha_r_23_from_matlab_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR, value);
}

// field definitions
#define MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_SCALE_ALPHA_R_3_MATLAB_MASK    ((uint32_t)0xFFFF0000)
#define MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_SCALE_ALPHA_R_3_MATLAB_LSB    16
#define MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_SCALE_ALPHA_R_3_MATLAB_WIDTH    ((uint32_t)0x00000010)
#define MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_SCALE_ALPHA_R_2_MATLAB_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_SCALE_ALPHA_R_2_MATLAB_LSB    0
#define MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_SCALE_ALPHA_R_2_MATLAB_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_SCALE_ALPHA_R_3_MATLAB_RST    0x0
#define MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_SCALE_ALPHA_R_2_MATLAB_RST    0x0

__INLINE void macdsp_api1_scale_alpha_r_23_from_matlab_pack(uint16_t scale_alpha_r3_matlab, uint16_t scale_alpha_r2_matlab)
{
	ASSERT_ERR((((uint32_t)scale_alpha_r3_matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_alpha_r2_matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR,  ((uint32_t)scale_alpha_r3_matlab << 16) |((uint32_t)scale_alpha_r2_matlab << 0));
}

__INLINE void macdsp_api1_scale_alpha_r_23_from_matlab_unpack(uint16_t* scale_alpha_r3_matlab, uint16_t* scale_alpha_r2_matlab)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR);

	*scale_alpha_r3_matlab = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_alpha_r2_matlab = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t macdsp_api1_scale_alpha_r_23_from_matlab_scale_alpha_r_3_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void macdsp_api1_scale_alpha_r_23_from_matlab_scale_alpha_r_3_matlab_setf(uint16_t scalealphar3matlab)
{
	ASSERT_ERR((((uint32_t)scalealphar3matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalealphar3matlab <<16));
}
__INLINE uint16_t macdsp_api1_scale_alpha_r_23_from_matlab_scale_alpha_r_2_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void macdsp_api1_scale_alpha_r_23_from_matlab_scale_alpha_r_2_matlab_setf(uint16_t scalealphar2matlab)
{
	ASSERT_ERR((((uint32_t)scalealphar2matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalealphar2matlab <<0));
}

/**
 * @brief SCALE_ALPHA_R_45_FROM_MATLAB register definition
 *  HeData AlphaR boost factor RUs 4 5 From Matlab register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_ALPHA_R5_Matlab     0x0
 *    15:00 SCALE_ALPHA_R4_Matlab     0x0
 * </pre>
 */
#define MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000828)
#define MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_OFFSET      0x00000828
#define MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_INDEX       0x0000020A
#define MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_scale_alpha_r_45_from_matlab_get(void)
{
	return REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR);
}

__INLINE void macdsp_api1_scale_alpha_r_45_from_matlab_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR, value);
}

// field definitions
#define MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_SCALE_ALPHA_R_5_MATLAB_MASK    ((uint32_t)0xFFFF0000)
#define MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_SCALE_ALPHA_R_5_MATLAB_LSB    16
#define MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_SCALE_ALPHA_R_5_MATLAB_WIDTH    ((uint32_t)0x00000010)
#define MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_SCALE_ALPHA_R_4_MATLAB_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_SCALE_ALPHA_R_4_MATLAB_LSB    0
#define MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_SCALE_ALPHA_R_4_MATLAB_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_SCALE_ALPHA_R_5_MATLAB_RST    0x0
#define MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_SCALE_ALPHA_R_4_MATLAB_RST    0x0

__INLINE void macdsp_api1_scale_alpha_r_45_from_matlab_pack(uint16_t scale_alpha_r5_matlab, uint16_t scale_alpha_r4_matlab)
{
	ASSERT_ERR((((uint32_t)scale_alpha_r5_matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_alpha_r4_matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR,  ((uint32_t)scale_alpha_r5_matlab << 16) |((uint32_t)scale_alpha_r4_matlab << 0));
}

__INLINE void macdsp_api1_scale_alpha_r_45_from_matlab_unpack(uint16_t* scale_alpha_r5_matlab, uint16_t* scale_alpha_r4_matlab)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR);

	*scale_alpha_r5_matlab = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_alpha_r4_matlab = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t macdsp_api1_scale_alpha_r_45_from_matlab_scale_alpha_r_5_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void macdsp_api1_scale_alpha_r_45_from_matlab_scale_alpha_r_5_matlab_setf(uint16_t scalealphar5matlab)
{
	ASSERT_ERR((((uint32_t)scalealphar5matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalealphar5matlab <<16));
}
__INLINE uint16_t macdsp_api1_scale_alpha_r_45_from_matlab_scale_alpha_r_4_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void macdsp_api1_scale_alpha_r_45_from_matlab_scale_alpha_r_4_matlab_setf(uint16_t scalealphar4matlab)
{
	ASSERT_ERR((((uint32_t)scalealphar4matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalealphar4matlab <<0));
}

/**
 * @brief SCALE_ALPHA_R_67_FROM_MATLAB register definition
 *  HeData AlphaR boost factor RUs 6 7 From Matlab register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SCALE_ALPHA_R7_Matlab     0x0
 *    15:00 SCALE_ALPHA_R6_Matlab     0x0
 * </pre>
 */
#define MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000082C)
#define MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_OFFSET      0x0000082C
#define MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_INDEX       0x0000020B
#define MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_scale_alpha_r_67_from_matlab_get(void)
{
	return REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR);
}

__INLINE void macdsp_api1_scale_alpha_r_67_from_matlab_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR, value);
}

// field definitions
#define MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_SCALE_ALPHA_R_7_MATLAB_MASK    ((uint32_t)0xFFFF0000)
#define MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_SCALE_ALPHA_R_7_MATLAB_LSB    16
#define MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_SCALE_ALPHA_R_7_MATLAB_WIDTH    ((uint32_t)0x00000010)
#define MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_SCALE_ALPHA_R_6_MATLAB_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_SCALE_ALPHA_R_6_MATLAB_LSB    0
#define MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_SCALE_ALPHA_R_6_MATLAB_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_SCALE_ALPHA_R_7_MATLAB_RST    0x0
#define MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_SCALE_ALPHA_R_6_MATLAB_RST    0x0

__INLINE void macdsp_api1_scale_alpha_r_67_from_matlab_pack(uint16_t scale_alpha_r7_matlab, uint16_t scale_alpha_r6_matlab)
{
	ASSERT_ERR((((uint32_t)scale_alpha_r7_matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)scale_alpha_r6_matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR,  ((uint32_t)scale_alpha_r7_matlab << 16) |((uint32_t)scale_alpha_r6_matlab << 0));
}

__INLINE void macdsp_api1_scale_alpha_r_67_from_matlab_unpack(uint16_t* scale_alpha_r7_matlab, uint16_t* scale_alpha_r6_matlab)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR);

	*scale_alpha_r7_matlab = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*scale_alpha_r6_matlab = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t macdsp_api1_scale_alpha_r_67_from_matlab_scale_alpha_r_7_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void macdsp_api1_scale_alpha_r_67_from_matlab_scale_alpha_r_7_matlab_setf(uint16_t scalealphar7matlab)
{
	ASSERT_ERR((((uint32_t)scalealphar7matlab << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)scalealphar7matlab <<16));
}
__INLINE uint16_t macdsp_api1_scale_alpha_r_67_from_matlab_scale_alpha_r_6_matlab_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void macdsp_api1_scale_alpha_r_67_from_matlab_scale_alpha_r_6_matlab_setf(uint16_t scalealphar6matlab)
{
	ASSERT_ERR((((uint32_t)scalealphar6matlab << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR, (REG_PL_RD(MACDSP_API1_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)scalealphar6matlab <<0));
}

/**
 * @brief RXTIME register definition
 *  RxTimeInUsec register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RX_TIME                   0x0
 * </pre>
 */
#define MACDSP_API1_RXTIME_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000830)
#define MACDSP_API1_RXTIME_OFFSET      0x00000830
#define MACDSP_API1_RXTIME_INDEX       0x0000020C
#define MACDSP_API1_RXTIME_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rxtime_get(void)
{
	return REG_PL_RD(MACDSP_API1_RXTIME_ADDR);
}

__INLINE void macdsp_api1_rxtime_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RXTIME_ADDR, value);
}

// field definitions
#define MACDSP_API1_RXTIME_RX_TIME_MASK     ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_RXTIME_RX_TIME_LSB      0
#define MACDSP_API1_RXTIME_RX_TIME_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_RXTIME_RX_TIME_RST      0x0

__INLINE uint32_t macdsp_api1_rxtime_rx_time_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RXTIME_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rxtime_rx_time_setf(uint32_t rxtime)
{
	ASSERT_ERR((((uint32_t)rxtime << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RXTIME_ADDR, (uint32_t)rxtime << 0);
}

/**
 * @brief RX_NUM_DATA_SYM register definition
 *  RxNumDataSym register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RX_NUM_DATA_SYM           0x0
 * </pre>
 */
#define MACDSP_API1_RX_NUM_DATA_SYM_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000834)
#define MACDSP_API1_RX_NUM_DATA_SYM_OFFSET      0x00000834
#define MACDSP_API1_RX_NUM_DATA_SYM_INDEX       0x0000020D
#define MACDSP_API1_RX_NUM_DATA_SYM_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_num_data_sym_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_NUM_DATA_SYM_ADDR);
}

__INLINE void macdsp_api1_rx_num_data_sym_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_NUM_DATA_SYM_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_NUM_DATA_SYM_RX_NUM_DATA_SYM_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_RX_NUM_DATA_SYM_RX_NUM_DATA_SYM_LSB    0
#define MACDSP_API1_RX_NUM_DATA_SYM_RX_NUM_DATA_SYM_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_RX_NUM_DATA_SYM_RX_NUM_DATA_SYM_RST    0x0

__INLINE uint32_t macdsp_api1_rx_num_data_sym_rx_num_data_sym_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_NUM_DATA_SYM_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_num_data_sym_rx_num_data_sym_setf(uint32_t rxnumdatasym)
{
	ASSERT_ERR((((uint32_t)rxnumdatasym << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_NUM_DATA_SYM_ADDR, (uint32_t)rxnumdatasym << 0);
}

/**
 * @brief RX_HTSFT_START_EST register definition
 *  RxHtSftStartEst register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RX_HTSFT_START_EST        0x0
 * </pre>
 */
#define MACDSP_API1_RX_HTSFT_START_EST_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000838)
#define MACDSP_API1_RX_HTSFT_START_EST_OFFSET      0x00000838
#define MACDSP_API1_RX_HTSFT_START_EST_INDEX       0x0000020E
#define MACDSP_API1_RX_HTSFT_START_EST_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_htsft_start_est_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_HTSFT_START_EST_ADDR);
}

__INLINE void macdsp_api1_rx_htsft_start_est_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_HTSFT_START_EST_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_HTSFT_START_EST_RX_HTSFT_START_EST_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_RX_HTSFT_START_EST_RX_HTSFT_START_EST_LSB    0
#define MACDSP_API1_RX_HTSFT_START_EST_RX_HTSFT_START_EST_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_RX_HTSFT_START_EST_RX_HTSFT_START_EST_RST    0x0

__INLINE uint32_t macdsp_api1_rx_htsft_start_est_rx_htsft_start_est_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_HTSFT_START_EST_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_htsft_start_est_rx_htsft_start_est_setf(uint32_t rxhtsftstartest)
{
	ASSERT_ERR((((uint32_t)rxhtsftstartest << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_HTSFT_START_EST_ADDR, (uint32_t)rxhtsftstartest << 0);
}

/**
 * @brief RX_HTSTF_GAIN_UPDATE register definition
 *  RxHtStfGainUpdate register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RX_HTSTF_GAIN_UPDATE      0x0
 * </pre>
 */
#define MACDSP_API1_RX_HTSTF_GAIN_UPDATE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000083C)
#define MACDSP_API1_RX_HTSTF_GAIN_UPDATE_OFFSET      0x0000083C
#define MACDSP_API1_RX_HTSTF_GAIN_UPDATE_INDEX       0x0000020F
#define MACDSP_API1_RX_HTSTF_GAIN_UPDATE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_htstf_gain_update_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_HTSTF_GAIN_UPDATE_ADDR);
}

__INLINE void macdsp_api1_rx_htstf_gain_update_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_HTSTF_GAIN_UPDATE_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_HTSTF_GAIN_UPDATE_RX_HTSTF_GAIN_UPDATE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_RX_HTSTF_GAIN_UPDATE_RX_HTSTF_GAIN_UPDATE_LSB    0
#define MACDSP_API1_RX_HTSTF_GAIN_UPDATE_RX_HTSTF_GAIN_UPDATE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_RX_HTSTF_GAIN_UPDATE_RX_HTSTF_GAIN_UPDATE_RST    0x0

__INLINE uint32_t macdsp_api1_rx_htstf_gain_update_rx_htstf_gain_update_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_HTSTF_GAIN_UPDATE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_htstf_gain_update_rx_htstf_gain_update_setf(uint32_t rxhtstfgainupdate)
{
	ASSERT_ERR((((uint32_t)rxhtstfgainupdate << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_HTSTF_GAIN_UPDATE_ADDR, (uint32_t)rxhtstfgainupdate << 0);
}

/**
 * @brief TXTIME register definition
 *  TxTime register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 TXTIME                    0x0
 * </pre>
 */
#define MACDSP_API1_TXTIME_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000840)
#define MACDSP_API1_TXTIME_OFFSET      0x00000840
#define MACDSP_API1_TXTIME_INDEX       0x00000210
#define MACDSP_API1_TXTIME_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_txtime_get(void)
{
	return REG_PL_RD(MACDSP_API1_TXTIME_ADDR);
}

__INLINE void macdsp_api1_txtime_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TXTIME_ADDR, value);
}

// field definitions
#define MACDSP_API1_TXTIME_TXTIME_MASK      ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_TXTIME_TXTIME_LSB       0
#define MACDSP_API1_TXTIME_TXTIME_WIDTH     ((uint32_t)0x00000020)

#define MACDSP_API1_TXTIME_TXTIME_RST       0x0

__INLINE uint32_t macdsp_api1_txtime_txtime_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TXTIME_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_txtime_txtime_setf(uint32_t txtime)
{
	ASSERT_ERR((((uint32_t)txtime << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TXTIME_ADDR, (uint32_t)txtime << 0);
}

/**
 * @brief CPE_FINE_CHECK register definition
 *  CpeFine register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Cpe_Fine                  0x0
 * </pre>
 */
#define MACDSP_API1_CPE_FINE_CHECK_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000844)
#define MACDSP_API1_CPE_FINE_CHECK_OFFSET      0x00000844
#define MACDSP_API1_CPE_FINE_CHECK_INDEX       0x00000211
#define MACDSP_API1_CPE_FINE_CHECK_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_cpe_fine_check_get(void)
{
	return REG_PL_RD(MACDSP_API1_CPE_FINE_CHECK_ADDR);
}

__INLINE void macdsp_api1_cpe_fine_check_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_CPE_FINE_CHECK_ADDR, value);
}

// field definitions
#define MACDSP_API1_CPE_FINE_CHECK_CPE_FINE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_CPE_FINE_CHECK_CPE_FINE_LSB    0
#define MACDSP_API1_CPE_FINE_CHECK_CPE_FINE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_CPE_FINE_CHECK_CPE_FINE_RST    0x0

__INLINE uint32_t macdsp_api1_cpe_fine_check_cpe_fine_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_CPE_FINE_CHECK_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_cpe_fine_check_cpe_fine_setf(uint32_t cpefine)
{
	ASSERT_ERR((((uint32_t)cpefine << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_CPE_FINE_CHECK_ADDR, (uint32_t)cpefine << 0);
}

/**
 * @brief STO_FINE_CHECK register definition
 *  StoFine register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Sto_Fine                  0x0
 * </pre>
 */
#define MACDSP_API1_STO_FINE_CHECK_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000848)
#define MACDSP_API1_STO_FINE_CHECK_OFFSET      0x00000848
#define MACDSP_API1_STO_FINE_CHECK_INDEX       0x00000212
#define MACDSP_API1_STO_FINE_CHECK_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_sto_fine_check_get(void)
{
	return REG_PL_RD(MACDSP_API1_STO_FINE_CHECK_ADDR);
}

__INLINE void macdsp_api1_sto_fine_check_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_STO_FINE_CHECK_ADDR, value);
}

// field definitions
#define MACDSP_API1_STO_FINE_CHECK_STO_FINE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_STO_FINE_CHECK_STO_FINE_LSB    0
#define MACDSP_API1_STO_FINE_CHECK_STO_FINE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_STO_FINE_CHECK_STO_FINE_RST    0x0

__INLINE uint32_t macdsp_api1_sto_fine_check_sto_fine_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_STO_FINE_CHECK_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_sto_fine_check_sto_fine_setf(uint32_t stofine)
{
	ASSERT_ERR((((uint32_t)stofine << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_STO_FINE_CHECK_ADDR, (uint32_t)stofine << 0);
}

/**
 * @brief TX_TB_SPU_STO_INIT register definition
 *  TxTbSpuStoInit register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Tx_Tb_Spu_Sto_Init        0x0
 * </pre>
 */
#define MACDSP_API1_TX_TB_SPU_STO_INIT_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000084C)
#define MACDSP_API1_TX_TB_SPU_STO_INIT_OFFSET      0x0000084C
#define MACDSP_API1_TX_TB_SPU_STO_INIT_INDEX       0x00000213
#define MACDSP_API1_TX_TB_SPU_STO_INIT_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tx_tb_spu_sto_init_get(void)
{
	return REG_PL_RD(MACDSP_API1_TX_TB_SPU_STO_INIT_ADDR);
}

__INLINE void macdsp_api1_tx_tb_spu_sto_init_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TX_TB_SPU_STO_INIT_ADDR, value);
}

// field definitions
#define MACDSP_API1_TX_TB_SPU_STO_INIT_TX_TB_SPU_STO_INIT_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_TX_TB_SPU_STO_INIT_TX_TB_SPU_STO_INIT_LSB    0
#define MACDSP_API1_TX_TB_SPU_STO_INIT_TX_TB_SPU_STO_INIT_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_TX_TB_SPU_STO_INIT_TX_TB_SPU_STO_INIT_RST    0x0

__INLINE uint32_t macdsp_api1_tx_tb_spu_sto_init_tx_tb_spu_sto_init_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_TB_SPU_STO_INIT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_tx_tb_spu_sto_init_tx_tb_spu_sto_init_setf(uint32_t txtbspustoinit)
{
	ASSERT_ERR((((uint32_t)txtbspustoinit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TX_TB_SPU_STO_INIT_ADDR, (uint32_t)txtbspustoinit << 0);
}

/**
 * @brief TX_TB_SPU_STO_STF_DELTA register definition
 *  TxTbSpuStoStfDelta register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Tx_Tb_Spu_Sto_Stf_Delta   0x0
 * </pre>
 */
#define MACDSP_API1_TX_TB_SPU_STO_STF_DELTA_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000850)
#define MACDSP_API1_TX_TB_SPU_STO_STF_DELTA_OFFSET      0x00000850
#define MACDSP_API1_TX_TB_SPU_STO_STF_DELTA_INDEX       0x00000214
#define MACDSP_API1_TX_TB_SPU_STO_STF_DELTA_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tx_tb_spu_sto_stf_delta_get(void)
{
	return REG_PL_RD(MACDSP_API1_TX_TB_SPU_STO_STF_DELTA_ADDR);
}

__INLINE void macdsp_api1_tx_tb_spu_sto_stf_delta_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TX_TB_SPU_STO_STF_DELTA_ADDR, value);
}

// field definitions
#define MACDSP_API1_TX_TB_SPU_STO_STF_DELTA_TX_TB_SPU_STO_STF_DELTA_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_TX_TB_SPU_STO_STF_DELTA_TX_TB_SPU_STO_STF_DELTA_LSB    0
#define MACDSP_API1_TX_TB_SPU_STO_STF_DELTA_TX_TB_SPU_STO_STF_DELTA_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_TX_TB_SPU_STO_STF_DELTA_TX_TB_SPU_STO_STF_DELTA_RST    0x0

__INLINE uint32_t macdsp_api1_tx_tb_spu_sto_stf_delta_tx_tb_spu_sto_stf_delta_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_TB_SPU_STO_STF_DELTA_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_tx_tb_spu_sto_stf_delta_tx_tb_spu_sto_stf_delta_setf(uint32_t txtbspustostfdelta)
{
	ASSERT_ERR((((uint32_t)txtbspustostfdelta << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TX_TB_SPU_STO_STF_DELTA_ADDR, (uint32_t)txtbspustostfdelta << 0);
}

/**
 * @brief TX_TB_SPU_STO_LTF_DELTA register definition
 *  TxTbSpuStoLtfDelta register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Tx_Tb_Spu_Sto_Ltf_Delta   0x0
 * </pre>
 */
#define MACDSP_API1_TX_TB_SPU_STO_LTF_DELTA_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000854)
#define MACDSP_API1_TX_TB_SPU_STO_LTF_DELTA_OFFSET      0x00000854
#define MACDSP_API1_TX_TB_SPU_STO_LTF_DELTA_INDEX       0x00000215
#define MACDSP_API1_TX_TB_SPU_STO_LTF_DELTA_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tx_tb_spu_sto_ltf_delta_get(void)
{
	return REG_PL_RD(MACDSP_API1_TX_TB_SPU_STO_LTF_DELTA_ADDR);
}

__INLINE void macdsp_api1_tx_tb_spu_sto_ltf_delta_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TX_TB_SPU_STO_LTF_DELTA_ADDR, value);
}

// field definitions
#define MACDSP_API1_TX_TB_SPU_STO_LTF_DELTA_TX_TB_SPU_STO_LTF_DELTA_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_TX_TB_SPU_STO_LTF_DELTA_TX_TB_SPU_STO_LTF_DELTA_LSB    0
#define MACDSP_API1_TX_TB_SPU_STO_LTF_DELTA_TX_TB_SPU_STO_LTF_DELTA_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_TX_TB_SPU_STO_LTF_DELTA_TX_TB_SPU_STO_LTF_DELTA_RST    0x0

__INLINE uint32_t macdsp_api1_tx_tb_spu_sto_ltf_delta_tx_tb_spu_sto_ltf_delta_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_TB_SPU_STO_LTF_DELTA_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_tx_tb_spu_sto_ltf_delta_tx_tb_spu_sto_ltf_delta_setf(uint32_t txtbspustoltfdelta)
{
	ASSERT_ERR((((uint32_t)txtbspustoltfdelta << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TX_TB_SPU_STO_LTF_DELTA_ADDR, (uint32_t)txtbspustoltfdelta << 0);
}

/**
 * @brief TX_TB_SPU_STO_DATA_DELTA register definition
 *  TxTbSpuStoDataDelta register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Tx_Tb_Spu_Sto_Data_Delta  0x0
 * </pre>
 */
#define MACDSP_API1_TX_TB_SPU_STO_DATA_DELTA_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000858)
#define MACDSP_API1_TX_TB_SPU_STO_DATA_DELTA_OFFSET      0x00000858
#define MACDSP_API1_TX_TB_SPU_STO_DATA_DELTA_INDEX       0x00000216
#define MACDSP_API1_TX_TB_SPU_STO_DATA_DELTA_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tx_tb_spu_sto_data_delta_get(void)
{
	return REG_PL_RD(MACDSP_API1_TX_TB_SPU_STO_DATA_DELTA_ADDR);
}

__INLINE void macdsp_api1_tx_tb_spu_sto_data_delta_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TX_TB_SPU_STO_DATA_DELTA_ADDR, value);
}

// field definitions
#define MACDSP_API1_TX_TB_SPU_STO_DATA_DELTA_TX_TB_SPU_STO_DATA_DELTA_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_TX_TB_SPU_STO_DATA_DELTA_TX_TB_SPU_STO_DATA_DELTA_LSB    0
#define MACDSP_API1_TX_TB_SPU_STO_DATA_DELTA_TX_TB_SPU_STO_DATA_DELTA_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_TX_TB_SPU_STO_DATA_DELTA_TX_TB_SPU_STO_DATA_DELTA_RST    0x0

__INLINE uint32_t macdsp_api1_tx_tb_spu_sto_data_delta_tx_tb_spu_sto_data_delta_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_TB_SPU_STO_DATA_DELTA_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_tx_tb_spu_sto_data_delta_tx_tb_spu_sto_data_delta_setf(uint32_t txtbspustodatadelta)
{
	ASSERT_ERR((((uint32_t)txtbspustodatadelta << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TX_TB_SPU_STO_DATA_DELTA_ADDR, (uint32_t)txtbspustodatadelta << 0);
}

/**
 * @brief TX_TB_SPU_STO_LIMIT register definition
 *  TxTbSpuStoLimit register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Tx_Tb_Spu_Sto_Limit       0x0
 * </pre>
 */
#define MACDSP_API1_TX_TB_SPU_STO_LIMIT_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000085C)
#define MACDSP_API1_TX_TB_SPU_STO_LIMIT_OFFSET      0x0000085C
#define MACDSP_API1_TX_TB_SPU_STO_LIMIT_INDEX       0x00000217
#define MACDSP_API1_TX_TB_SPU_STO_LIMIT_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tx_tb_spu_sto_limit_get(void)
{
	return REG_PL_RD(MACDSP_API1_TX_TB_SPU_STO_LIMIT_ADDR);
}

__INLINE void macdsp_api1_tx_tb_spu_sto_limit_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TX_TB_SPU_STO_LIMIT_ADDR, value);
}

// field definitions
#define MACDSP_API1_TX_TB_SPU_STO_LIMIT_TX_TB_SPU_STO_LIMIT_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_TX_TB_SPU_STO_LIMIT_TX_TB_SPU_STO_LIMIT_LSB    0
#define MACDSP_API1_TX_TB_SPU_STO_LIMIT_TX_TB_SPU_STO_LIMIT_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_TX_TB_SPU_STO_LIMIT_TX_TB_SPU_STO_LIMIT_RST    0x0

__INLINE uint32_t macdsp_api1_tx_tb_spu_sto_limit_tx_tb_spu_sto_limit_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_TB_SPU_STO_LIMIT_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_tx_tb_spu_sto_limit_tx_tb_spu_sto_limit_setf(uint32_t txtbspustolimit)
{
	ASSERT_ERR((((uint32_t)txtbspustolimit << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TX_TB_SPU_STO_LIMIT_ADDR, (uint32_t)txtbspustolimit << 0);
}

/**
 * @brief SMU_CHECKER_ADDR_PART_1 register definition
 *  SmuCheckerAddrrPart1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28:27 Smu_Number_Of_Steps       0x0
 *    26:17 Smu_Number_Of_Valid_SC    0x0
 *    16:00 Smu_Checker_Part1_Addrr   0x0
 * </pre>
 */
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_1_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000860)
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_1_OFFSET      0x00000860
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_1_INDEX       0x00000218
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_1_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_smu_checker_addr_part_1_get(void)
{
	return REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_1_ADDR);
}

__INLINE void macdsp_api1_smu_checker_addr_part_1_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SMU_CHECKER_ADDR_PART_1_ADDR, value);
}

// field definitions
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_1_SMU_NUMBER_OF_STEPS_MASK    ((uint32_t)0x18000000)
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_1_SMU_NUMBER_OF_STEPS_LSB    27
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_1_SMU_NUMBER_OF_STEPS_WIDTH    ((uint32_t)0x00000002)
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_1_SMU_NUMBER_OF_VALID_SC_MASK    ((uint32_t)0x07FE0000)
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_1_SMU_NUMBER_OF_VALID_SC_LSB    17
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_1_SMU_NUMBER_OF_VALID_SC_WIDTH    ((uint32_t)0x0000000A)
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_1_SMU_CHECKER_PART_1_ADDRR_MASK    ((uint32_t)0x0001FFFF)
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_1_SMU_CHECKER_PART_1_ADDRR_LSB    0
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_1_SMU_CHECKER_PART_1_ADDRR_WIDTH    ((uint32_t)0x00000011)

#define MACDSP_API1_SMU_CHECKER_ADDR_PART_1_SMU_NUMBER_OF_STEPS_RST    0x0
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_1_SMU_NUMBER_OF_VALID_SC_RST    0x0
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_1_SMU_CHECKER_PART_1_ADDRR_RST    0x0

__INLINE void macdsp_api1_smu_checker_addr_part_1_pack(uint8_t smu_number_of_steps, uint16_t smu_number_of_valid_sc, uint32_t smu_checker_part1_addrr)
{
	ASSERT_ERR((((uint32_t)smu_number_of_steps << 27) & ~((uint32_t)0x18000000)) == 0);
	ASSERT_ERR((((uint32_t)smu_number_of_valid_sc << 17) & ~((uint32_t)0x07FE0000)) == 0);
	ASSERT_ERR((((uint32_t)smu_checker_part1_addrr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SMU_CHECKER_ADDR_PART_1_ADDR,  ((uint32_t)smu_number_of_steps << 27) |((uint32_t)smu_number_of_valid_sc << 17) |((uint32_t)smu_checker_part1_addrr << 0));
}

__INLINE void macdsp_api1_smu_checker_addr_part_1_unpack(uint8_t* smu_number_of_steps, uint16_t* smu_number_of_valid_sc, uint32_t* smu_checker_part1_addrr)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_1_ADDR);

	*smu_number_of_steps = (localVal & ((uint32_t)0x18000000)) >>  27;
	*smu_number_of_valid_sc = (localVal & ((uint32_t)0x07FE0000)) >>  17;
	*smu_checker_part1_addrr = (localVal & ((uint32_t)0x0001FFFF)) >>  0;
}

__INLINE uint8_t macdsp_api1_smu_checker_addr_part_1_smu_number_of_steps_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x18000000)) >> 27);
}
__INLINE void macdsp_api1_smu_checker_addr_part_1_smu_number_of_steps_setf(uint8_t smunumberofsteps)
{
	ASSERT_ERR((((uint32_t)smunumberofsteps << 27) & ~((uint32_t)0x18000000)) == 0);
	REG_PL_WR(MACDSP_API1_SMU_CHECKER_ADDR_PART_1_ADDR, (REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_1_ADDR) & ~((uint32_t)0x18000000)) | ((uint32_t)smunumberofsteps <<27));
}
__INLINE uint16_t macdsp_api1_smu_checker_addr_part_1_smu_number_of_valid_sc_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_1_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x07FE0000)) >> 17);
}
__INLINE void macdsp_api1_smu_checker_addr_part_1_smu_number_of_valid_sc_setf(uint16_t smunumberofvalidsc)
{
	ASSERT_ERR((((uint32_t)smunumberofvalidsc << 17) & ~((uint32_t)0x07FE0000)) == 0);
	REG_PL_WR(MACDSP_API1_SMU_CHECKER_ADDR_PART_1_ADDR, (REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_1_ADDR) & ~((uint32_t)0x07FE0000)) | ((uint32_t)smunumberofvalidsc <<17));
}
__INLINE uint32_t macdsp_api1_smu_checker_addr_part_1_smu_checker_part_1_addrr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_1_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0x0001FFFF)) >> 0);
}
__INLINE void macdsp_api1_smu_checker_addr_part_1_smu_checker_part_1_addrr_setf(uint32_t smucheckerpart1addrr)
{
	ASSERT_ERR((((uint32_t)smucheckerpart1addrr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SMU_CHECKER_ADDR_PART_1_ADDR, (REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_1_ADDR) & ~((uint32_t)0x0001FFFF)) | ((uint32_t)smucheckerpart1addrr <<0));
}

/**
 * @brief SMU_CHECKER_ADDR_PART_2 register definition
 *  SmuCheckerAddrrPart2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    29:27 Smu_Checker_Addrr_Part2_Nss 0x0
 *    26:17 Smu_FFTPer_Step           0x0
 *    16:00 Smu_Checker_Part2_Addrr   0x0
 * </pre>
 */
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_2_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000864)
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_2_OFFSET      0x00000864
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_2_INDEX       0x00000219
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_2_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_smu_checker_addr_part_2_get(void)
{
	return REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_2_ADDR);
}

__INLINE void macdsp_api1_smu_checker_addr_part_2_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SMU_CHECKER_ADDR_PART_2_ADDR, value);
}

// field definitions
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_2_SMU_CHECKER_ADDRR_PART_2_NSS_MASK    ((uint32_t)0x38000000)
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_2_SMU_CHECKER_ADDRR_PART_2_NSS_LSB    27
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_2_SMU_CHECKER_ADDRR_PART_2_NSS_WIDTH    ((uint32_t)0x00000003)
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_2_SMU_FFTPER_STEP_MASK    ((uint32_t)0x07FE0000)
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_2_SMU_FFTPER_STEP_LSB    17
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_2_SMU_FFTPER_STEP_WIDTH    ((uint32_t)0x0000000A)
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_2_SMU_CHECKER_PART_2_ADDRR_MASK    ((uint32_t)0x0001FFFF)
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_2_SMU_CHECKER_PART_2_ADDRR_LSB    0
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_2_SMU_CHECKER_PART_2_ADDRR_WIDTH    ((uint32_t)0x00000011)

#define MACDSP_API1_SMU_CHECKER_ADDR_PART_2_SMU_CHECKER_ADDRR_PART_2_NSS_RST    0x0
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_2_SMU_FFTPER_STEP_RST    0x0
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_2_SMU_CHECKER_PART_2_ADDRR_RST    0x0

__INLINE void macdsp_api1_smu_checker_addr_part_2_pack(uint8_t smu_checker_addrr_part2_nss, uint16_t smu_fftper_step, uint32_t smu_checker_part2_addrr)
{
	ASSERT_ERR((((uint32_t)smu_checker_addrr_part2_nss << 27) & ~((uint32_t)0x38000000)) == 0);
	ASSERT_ERR((((uint32_t)smu_fftper_step << 17) & ~((uint32_t)0x07FE0000)) == 0);
	ASSERT_ERR((((uint32_t)smu_checker_part2_addrr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SMU_CHECKER_ADDR_PART_2_ADDR,  ((uint32_t)smu_checker_addrr_part2_nss << 27) |((uint32_t)smu_fftper_step << 17) |((uint32_t)smu_checker_part2_addrr << 0));
}

__INLINE void macdsp_api1_smu_checker_addr_part_2_unpack(uint8_t* smu_checker_addrr_part2_nss, uint16_t* smu_fftper_step, uint32_t* smu_checker_part2_addrr)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_2_ADDR);

	*smu_checker_addrr_part2_nss = (localVal & ((uint32_t)0x38000000)) >>  27;
	*smu_fftper_step = (localVal & ((uint32_t)0x07FE0000)) >>  17;
	*smu_checker_part2_addrr = (localVal & ((uint32_t)0x0001FFFF)) >>  0;
}

__INLINE uint8_t macdsp_api1_smu_checker_addr_part_2_smu_checker_addrr_part_2_nss_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x38000000)) >> 27);
}
__INLINE void macdsp_api1_smu_checker_addr_part_2_smu_checker_addrr_part_2_nss_setf(uint8_t smucheckeraddrrpart2nss)
{
	ASSERT_ERR((((uint32_t)smucheckeraddrrpart2nss << 27) & ~((uint32_t)0x38000000)) == 0);
	REG_PL_WR(MACDSP_API1_SMU_CHECKER_ADDR_PART_2_ADDR, (REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_2_ADDR) & ~((uint32_t)0x38000000)) | ((uint32_t)smucheckeraddrrpart2nss <<27));
}
__INLINE uint16_t macdsp_api1_smu_checker_addr_part_2_smu_fftper_step_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_2_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x07FE0000)) >> 17);
}
__INLINE void macdsp_api1_smu_checker_addr_part_2_smu_fftper_step_setf(uint16_t smufftperstep)
{
	ASSERT_ERR((((uint32_t)smufftperstep << 17) & ~((uint32_t)0x07FE0000)) == 0);
	REG_PL_WR(MACDSP_API1_SMU_CHECKER_ADDR_PART_2_ADDR, (REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_2_ADDR) & ~((uint32_t)0x07FE0000)) | ((uint32_t)smufftperstep <<17));
}
__INLINE uint32_t macdsp_api1_smu_checker_addr_part_2_smu_checker_part_2_addrr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_2_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0x0001FFFF)) >> 0);
}
__INLINE void macdsp_api1_smu_checker_addr_part_2_smu_checker_part_2_addrr_setf(uint32_t smucheckerpart2addrr)
{
	ASSERT_ERR((((uint32_t)smucheckerpart2addrr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SMU_CHECKER_ADDR_PART_2_ADDR, (REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_2_ADDR) & ~((uint32_t)0x0001FFFF)) | ((uint32_t)smucheckerpart2addrr <<0));
}

/**
 * @brief SMU_CHECKER_ADDR_PART_3 register definition
 *  SmuCheckerAddrrPart3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:17 NRx                       0x0
 *    16:00 Smu_Checker_Part3_Addrr   0x0
 * </pre>
 */
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_3_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000868)
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_3_OFFSET      0x00000868
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_3_INDEX       0x0000021A
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_3_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_smu_checker_addr_part_3_get(void)
{
	return REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_3_ADDR);
}

__INLINE void macdsp_api1_smu_checker_addr_part_3_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SMU_CHECKER_ADDR_PART_3_ADDR, value);
}

// field definitions
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_3_NRX_MASK    ((uint32_t)0x000E0000)
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_3_NRX_LSB    17
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_3_NRX_WIDTH    ((uint32_t)0x00000003)
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_3_SMU_CHECKER_PART_3_ADDRR_MASK    ((uint32_t)0x0001FFFF)
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_3_SMU_CHECKER_PART_3_ADDRR_LSB    0
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_3_SMU_CHECKER_PART_3_ADDRR_WIDTH    ((uint32_t)0x00000011)

#define MACDSP_API1_SMU_CHECKER_ADDR_PART_3_NRX_RST    0x0
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_3_SMU_CHECKER_PART_3_ADDRR_RST    0x0

__INLINE void macdsp_api1_smu_checker_addr_part_3_pack(uint8_t nrx, uint32_t smu_checker_part3_addrr)
{
	ASSERT_ERR((((uint32_t)nrx << 17) & ~((uint32_t)0x000E0000)) == 0);
	ASSERT_ERR((((uint32_t)smu_checker_part3_addrr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SMU_CHECKER_ADDR_PART_3_ADDR,  ((uint32_t)nrx << 17) |((uint32_t)smu_checker_part3_addrr << 0));
}

__INLINE void macdsp_api1_smu_checker_addr_part_3_unpack(uint8_t* nrx, uint32_t* smu_checker_part3_addrr)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_3_ADDR);

	*nrx = (localVal & ((uint32_t)0x000E0000)) >>  17;
	*smu_checker_part3_addrr = (localVal & ((uint32_t)0x0001FFFF)) >>  0;
}

__INLINE uint8_t macdsp_api1_smu_checker_addr_part_3_nrx_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_3_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000E0000)) >> 17);
}
__INLINE void macdsp_api1_smu_checker_addr_part_3_nrx_setf(uint8_t nrx)
{
	ASSERT_ERR((((uint32_t)nrx << 17) & ~((uint32_t)0x000E0000)) == 0);
	REG_PL_WR(MACDSP_API1_SMU_CHECKER_ADDR_PART_3_ADDR, (REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_3_ADDR) & ~((uint32_t)0x000E0000)) | ((uint32_t)nrx <<17));
}
__INLINE uint32_t macdsp_api1_smu_checker_addr_part_3_smu_checker_part_3_addrr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_3_ADDR);
	return (uint32_t)((localVal & ((uint32_t)0x0001FFFF)) >> 0);
}
__INLINE void macdsp_api1_smu_checker_addr_part_3_smu_checker_part_3_addrr_setf(uint32_t smucheckerpart3addrr)
{
	ASSERT_ERR((((uint32_t)smucheckerpart3addrr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SMU_CHECKER_ADDR_PART_3_ADDR, (REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_3_ADDR) & ~((uint32_t)0x0001FFFF)) | ((uint32_t)smucheckerpart3addrr <<0));
}

/**
 * @brief SMU_CHECKER_ADDR_PART_4 register definition
 *  SmuCheckerAddrrPart4 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    16:00 Smu_Checker_Part4_Addrr   0x0
 * </pre>
 */
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_4_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000086C)
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_4_OFFSET      0x0000086C
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_4_INDEX       0x0000021B
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_4_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_smu_checker_addr_part_4_get(void)
{
	return REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_4_ADDR);
}

__INLINE void macdsp_api1_smu_checker_addr_part_4_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_SMU_CHECKER_ADDR_PART_4_ADDR, value);
}

// field definitions
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_4_SMU_CHECKER_PART_4_ADDRR_MASK    ((uint32_t)0x0001FFFF)
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_4_SMU_CHECKER_PART_4_ADDRR_LSB    0
#define MACDSP_API1_SMU_CHECKER_ADDR_PART_4_SMU_CHECKER_PART_4_ADDRR_WIDTH    ((uint32_t)0x00000011)

#define MACDSP_API1_SMU_CHECKER_ADDR_PART_4_SMU_CHECKER_PART_4_ADDRR_RST    0x0

__INLINE uint32_t macdsp_api1_smu_checker_addr_part_4_smu_checker_part_4_addrr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_SMU_CHECKER_ADDR_PART_4_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_smu_checker_addr_part_4_smu_checker_part_4_addrr_setf(uint32_t smucheckerpart4addrr)
{
	ASSERT_ERR((((uint32_t)smucheckerpart4addrr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_SMU_CHECKER_ADDR_PART_4_ADDR, (uint32_t)smucheckerpart4addrr << 0);
}

/**
 * @brief TX_TB_FREQ_OFFSET register definition
 *  TX_TB_FREQUENCY_OFFSET register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    20:00 TX_TB_FREQ_OFFSET_VAL     0x0
 * </pre>
 */
#define MACDSP_API1_TX_TB_FREQ_OFFSET_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000870)
#define MACDSP_API1_TX_TB_FREQ_OFFSET_OFFSET      0x00000870
#define MACDSP_API1_TX_TB_FREQ_OFFSET_INDEX       0x0000021C
#define MACDSP_API1_TX_TB_FREQ_OFFSET_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tx_tb_freq_offset_get(void)
{
	return REG_PL_RD(MACDSP_API1_TX_TB_FREQ_OFFSET_ADDR);
}

__INLINE void macdsp_api1_tx_tb_freq_offset_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TX_TB_FREQ_OFFSET_ADDR, value);
}

// field definitions
#define MACDSP_API1_TX_TB_FREQ_OFFSET_TX_TB_FREQ_OFFSET_VAL_MASK    ((uint32_t)0x001FFFFF)
#define MACDSP_API1_TX_TB_FREQ_OFFSET_TX_TB_FREQ_OFFSET_VAL_LSB    0
#define MACDSP_API1_TX_TB_FREQ_OFFSET_TX_TB_FREQ_OFFSET_VAL_WIDTH    ((uint32_t)0x00000015)

#define MACDSP_API1_TX_TB_FREQ_OFFSET_TX_TB_FREQ_OFFSET_VAL_RST    0x0

__INLINE uint32_t macdsp_api1_tx_tb_freq_offset_tx_tb_freq_offset_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_TB_FREQ_OFFSET_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_tx_tb_freq_offset_tx_tb_freq_offset_val_setf(uint32_t txtbfreqoffsetval)
{
	ASSERT_ERR((((uint32_t)txtbfreqoffsetval << 0) & ~((uint32_t)0x001FFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TX_TB_FREQ_OFFSET_ADDR, (uint32_t)txtbfreqoffsetval << 0);
}

/**
 * @brief TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB register definition
 *  TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET 0x0
 * </pre>
 */
#define MACDSP_API1_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000874)
#define MACDSP_API1_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_OFFSET      0x00000874
#define MACDSP_API1_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_INDEX       0x0000021D
#define MACDSP_API1_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_tx_riu_resampler_delta_offset_from_matlab_get(void)
{
	return REG_PL_RD(MACDSP_API1_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR);
}

__INLINE void macdsp_api1_tx_riu_resampler_delta_offset_from_matlab_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR, value);
}

// field definitions
#define MACDSP_API1_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_LSB    0
#define MACDSP_API1_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_RST    0x0

__INLINE uint32_t macdsp_api1_tx_riu_resampler_delta_offset_from_matlab_macdsp_api_tx_riu_resampler_delta_offset_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_tx_riu_resampler_delta_offset_from_matlab_macdsp_api_tx_riu_resampler_delta_offset_setf(uint32_t macdspapitxriuresamplerdeltaoffset)
{
	ASSERT_ERR((((uint32_t)macdspapitxriuresamplerdeltaoffset << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR, (uint32_t)macdspapitxriuresamplerdeltaoffset << 0);
}

/**
 * @brief RX_EVM_DEBUG_1 register definition
 *  RxEvmDebug1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVM_DEBUG_1               0x0
 * </pre>
 */
#define MACDSP_API1_RX_EVM_DEBUG_1_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000878)
#define MACDSP_API1_RX_EVM_DEBUG_1_OFFSET      0x00000878
#define MACDSP_API1_RX_EVM_DEBUG_1_INDEX       0x0000021E
#define MACDSP_API1_RX_EVM_DEBUG_1_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_evm_debug_1_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_EVM_DEBUG_1_ADDR);
}

__INLINE void macdsp_api1_rx_evm_debug_1_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_EVM_DEBUG_1_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_EVM_DEBUG_1_EVM_DEBUG_1_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_RX_EVM_DEBUG_1_EVM_DEBUG_1_LSB    0
#define MACDSP_API1_RX_EVM_DEBUG_1_EVM_DEBUG_1_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_RX_EVM_DEBUG_1_EVM_DEBUG_1_RST    0x0

__INLINE uint32_t macdsp_api1_rx_evm_debug_1_evm_debug_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_EVM_DEBUG_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_evm_debug_1_evm_debug_1_setf(uint32_t evmdebug1)
{
	ASSERT_ERR((((uint32_t)evmdebug1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_EVM_DEBUG_1_ADDR, (uint32_t)evmdebug1 << 0);
}

/**
 * @brief RX_EVM_DEBUG_2 register definition
 *  RxEvmDebug2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVM_DEBUG_2               0x0
 * </pre>
 */
#define MACDSP_API1_RX_EVM_DEBUG_2_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000087C)
#define MACDSP_API1_RX_EVM_DEBUG_2_OFFSET      0x0000087C
#define MACDSP_API1_RX_EVM_DEBUG_2_INDEX       0x0000021F
#define MACDSP_API1_RX_EVM_DEBUG_2_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_evm_debug_2_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_EVM_DEBUG_2_ADDR);
}

__INLINE void macdsp_api1_rx_evm_debug_2_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_EVM_DEBUG_2_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_EVM_DEBUG_2_EVM_DEBUG_2_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_RX_EVM_DEBUG_2_EVM_DEBUG_2_LSB    0
#define MACDSP_API1_RX_EVM_DEBUG_2_EVM_DEBUG_2_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_RX_EVM_DEBUG_2_EVM_DEBUG_2_RST    0x0

__INLINE uint32_t macdsp_api1_rx_evm_debug_2_evm_debug_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_EVM_DEBUG_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_evm_debug_2_evm_debug_2_setf(uint32_t evmdebug2)
{
	ASSERT_ERR((((uint32_t)evmdebug2 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_EVM_DEBUG_2_ADDR, (uint32_t)evmdebug2 << 0);
}

/**
 * @brief RX_EVM_DEBUG_3 register definition
 *  RxEvmDebug3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVM_DEBUG_3               0x0
 * </pre>
 */
#define MACDSP_API1_RX_EVM_DEBUG_3_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000880)
#define MACDSP_API1_RX_EVM_DEBUG_3_OFFSET      0x00000880
#define MACDSP_API1_RX_EVM_DEBUG_3_INDEX       0x00000220
#define MACDSP_API1_RX_EVM_DEBUG_3_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_evm_debug_3_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_EVM_DEBUG_3_ADDR);
}

__INLINE void macdsp_api1_rx_evm_debug_3_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_EVM_DEBUG_3_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_EVM_DEBUG_3_EVM_DEBUG_3_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_RX_EVM_DEBUG_3_EVM_DEBUG_3_LSB    0
#define MACDSP_API1_RX_EVM_DEBUG_3_EVM_DEBUG_3_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_RX_EVM_DEBUG_3_EVM_DEBUG_3_RST    0x0

__INLINE uint32_t macdsp_api1_rx_evm_debug_3_evm_debug_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_EVM_DEBUG_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_evm_debug_3_evm_debug_3_setf(uint32_t evmdebug3)
{
	ASSERT_ERR((((uint32_t)evmdebug3 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_EVM_DEBUG_3_ADDR, (uint32_t)evmdebug3 << 0);
}

/**
 * @brief DEPACKER_GETREADY_FLAG register definition
 *  DEPACKER_GETREADY_FLAG register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DEPACKER_GETREADY_FLAG    0x0
 * </pre>
 */
#define MACDSP_API1_DEPACKER_GETREADY_FLAG_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000884)
#define MACDSP_API1_DEPACKER_GETREADY_FLAG_OFFSET      0x00000884
#define MACDSP_API1_DEPACKER_GETREADY_FLAG_INDEX       0x00000221
#define MACDSP_API1_DEPACKER_GETREADY_FLAG_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_depacker_getready_flag_get(void)
{
	return REG_PL_RD(MACDSP_API1_DEPACKER_GETREADY_FLAG_ADDR);
}

__INLINE void macdsp_api1_depacker_getready_flag_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_DEPACKER_GETREADY_FLAG_ADDR, value);
}

// field definitions
#define MACDSP_API1_DEPACKER_GETREADY_FLAG_DEPACKER_GETREADY_FLAG_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_DEPACKER_GETREADY_FLAG_DEPACKER_GETREADY_FLAG_LSB    0
#define MACDSP_API1_DEPACKER_GETREADY_FLAG_DEPACKER_GETREADY_FLAG_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_DEPACKER_GETREADY_FLAG_DEPACKER_GETREADY_FLAG_RST    0x0

__INLINE uint32_t macdsp_api1_depacker_getready_flag_depacker_getready_flag_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DEPACKER_GETREADY_FLAG_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_depacker_getready_flag_depacker_getready_flag_setf(uint32_t depackergetreadyflag)
{
	ASSERT_ERR((((uint32_t)depackergetreadyflag << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_DEPACKER_GETREADY_FLAG_ADDR, (uint32_t)depackergetreadyflag << 0);
}

/**
 * @brief DSP_CNTR_EVM_DROP register definition
 *  EVM_DROP_COUNTER register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 * </pre>
 */
#define MACDSP_API1_DSP_CNTR_EVM_DROP_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000898)
#define MACDSP_API1_DSP_CNTR_EVM_DROP_OFFSET      0x00000898
#define MACDSP_API1_DSP_CNTR_EVM_DROP_INDEX       0x00000226
#define MACDSP_API1_DSP_CNTR_EVM_DROP_RESET       0x00000000

// field definitions



/**
 * @brief RX_TB_FRC_VAL register definition
 *  RX_TB_FRC_VAL register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RX_TB_FRC_VAL             0x0
 * </pre>
 */
#define MACDSP_API1_RX_TB_FRC_VAL_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000089C)
#define MACDSP_API1_RX_TB_FRC_VAL_OFFSET      0x0000089C
#define MACDSP_API1_RX_TB_FRC_VAL_INDEX       0x00000227
#define MACDSP_API1_RX_TB_FRC_VAL_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_tb_frc_val_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_TB_FRC_VAL_ADDR);
}

__INLINE void macdsp_api1_rx_tb_frc_val_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_TB_FRC_VAL_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_TB_FRC_VAL_RX_TB_FRC_VAL_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_RX_TB_FRC_VAL_RX_TB_FRC_VAL_LSB    0
#define MACDSP_API1_RX_TB_FRC_VAL_RX_TB_FRC_VAL_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_RX_TB_FRC_VAL_RX_TB_FRC_VAL_RST    0x0

__INLINE uint32_t macdsp_api1_rx_tb_frc_val_rx_tb_frc_val_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_TB_FRC_VAL_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_tb_frc_val_rx_tb_frc_val_setf(uint32_t rxtbfrcval)
{
	ASSERT_ERR((((uint32_t)rxtbfrcval << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_TB_FRC_VAL_ADDR, (uint32_t)rxtbfrcval << 0);
}

/**
 * @brief DSP_ERR_IND_BIT_MASK register definition
 *  DSP_ERR_IND_BIT_MASK register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    CPE_EXCEED_16_BIT         0              
 *    00    TB_RX_WRONG_STF_INDEX     0              
 * </pre>
 */
#define MACDSP_API1_DSP_ERR_IND_BIT_MASK_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000008A0)
#define MACDSP_API1_DSP_ERR_IND_BIT_MASK_OFFSET      0x000008A0
#define MACDSP_API1_DSP_ERR_IND_BIT_MASK_INDEX       0x00000228
#define MACDSP_API1_DSP_ERR_IND_BIT_MASK_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_dsp_err_ind_bit_mask_get(void)
{
	return REG_PL_RD(MACDSP_API1_DSP_ERR_IND_BIT_MASK_ADDR);
}

__INLINE void macdsp_api1_dsp_err_ind_bit_mask_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_DSP_ERR_IND_BIT_MASK_ADDR, value);
}

// field definitions
#define MACDSP_API1_DSP_ERR_IND_BIT_MASK_CPE_EXCEED_16_BIT_BIT    ((uint32_t)0x00000002)
#define MACDSP_API1_DSP_ERR_IND_BIT_MASK_CPE_EXCEED_16_BIT_POS    1
#define MACDSP_API1_DSP_ERR_IND_BIT_MASK_TB_RX_WRONG_STF_INDEX_BIT    ((uint32_t)0x00000001)
#define MACDSP_API1_DSP_ERR_IND_BIT_MASK_TB_RX_WRONG_STF_INDEX_POS    0

#define MACDSP_API1_DSP_ERR_IND_BIT_MASK_CPE_EXCEED_16_BIT_RST    0x0
#define MACDSP_API1_DSP_ERR_IND_BIT_MASK_TB_RX_WRONG_STF_INDEX_RST    0x0

__INLINE void macdsp_api1_dsp_err_ind_bit_mask_pack(uint8_t cpe_exceed_16_bit, uint8_t tb_rx_wrong_stf_index)
{
	ASSERT_ERR((((uint32_t)cpe_exceed_16_bit << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)tb_rx_wrong_stf_index << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACDSP_API1_DSP_ERR_IND_BIT_MASK_ADDR,  ((uint32_t)cpe_exceed_16_bit << 1) |((uint32_t)tb_rx_wrong_stf_index << 0));
}

__INLINE void macdsp_api1_dsp_err_ind_bit_mask_unpack(uint8_t* cpe_exceed_16_bit, uint8_t* tb_rx_wrong_stf_index)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_ERR_IND_BIT_MASK_ADDR);

	*cpe_exceed_16_bit = (localVal & ((uint32_t)0x00000002)) >>  1;
	*tb_rx_wrong_stf_index = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t macdsp_api1_dsp_err_ind_bit_mask_cpe_exceed_16_bit_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_ERR_IND_BIT_MASK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void macdsp_api1_dsp_err_ind_bit_mask_cpe_exceed_16_bit_setf(uint8_t cpeexceed16bit)
{
	ASSERT_ERR((((uint32_t)cpeexceed16bit << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(MACDSP_API1_DSP_ERR_IND_BIT_MASK_ADDR, (REG_PL_RD(MACDSP_API1_DSP_ERR_IND_BIT_MASK_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)cpeexceed16bit <<1));
}
__INLINE uint8_t macdsp_api1_dsp_err_ind_bit_mask_tb_rx_wrong_stf_index_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DSP_ERR_IND_BIT_MASK_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void macdsp_api1_dsp_err_ind_bit_mask_tb_rx_wrong_stf_index_setf(uint8_t tbrxwrongstfindex)
{
	ASSERT_ERR((((uint32_t)tbrxwrongstfindex << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACDSP_API1_DSP_ERR_IND_BIT_MASK_ADDR, (REG_PL_RD(MACDSP_API1_DSP_ERR_IND_BIT_MASK_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)tbrxwrongstfindex <<0));
}

/**
 * @brief PACKER_INPUT_STATUS register definition
 *  For Packer input ready indication by palladium register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    Packer_Input_Ready        0              
 * </pre>
 */
#define MACDSP_API1_PACKER_INPUT_STATUS_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000008B8)
#define MACDSP_API1_PACKER_INPUT_STATUS_OFFSET      0x000008B8
#define MACDSP_API1_PACKER_INPUT_STATUS_INDEX       0x0000022E
#define MACDSP_API1_PACKER_INPUT_STATUS_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_packer_input_status_get(void)
{
	return REG_PL_RD(MACDSP_API1_PACKER_INPUT_STATUS_ADDR);
}

__INLINE void macdsp_api1_packer_input_status_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_PACKER_INPUT_STATUS_ADDR, value);
}

// field definitions
#define MACDSP_API1_PACKER_INPUT_STATUS_PACKER_INPUT_READY_BIT    ((uint32_t)0x00000001)
#define MACDSP_API1_PACKER_INPUT_STATUS_PACKER_INPUT_READY_POS    0

#define MACDSP_API1_PACKER_INPUT_STATUS_PACKER_INPUT_READY_RST    0x0

__INLINE uint8_t macdsp_api1_packer_input_status_packer_input_ready_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_PACKER_INPUT_STATUS_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void macdsp_api1_packer_input_status_packer_input_ready_setf(uint8_t packerinputready)
{
	ASSERT_ERR((((uint32_t)packerinputready << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACDSP_API1_PACKER_INPUT_STATUS_ADDR, (uint32_t)packerinputready << 0);
}

/**
 * @brief V_MATRIX_OFFSET_0 register definition
 *  Input for the depacker user 0 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DEPACKER_INPUT_BUFF_0     0x0
 * </pre>
 */
#define MACDSP_API1_V_MATRIX_OFFSET_0_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000008C0)
#define MACDSP_API1_V_MATRIX_OFFSET_0_OFFSET      0x000008C0
#define MACDSP_API1_V_MATRIX_OFFSET_0_INDEX       0x00000230
#define MACDSP_API1_V_MATRIX_OFFSET_0_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_v_matrix_offset_0_get(void)
{
	return REG_PL_RD(MACDSP_API1_V_MATRIX_OFFSET_0_ADDR);
}

__INLINE void macdsp_api1_v_matrix_offset_0_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_V_MATRIX_OFFSET_0_ADDR, value);
}

// field definitions
#define MACDSP_API1_V_MATRIX_OFFSET_0_DEPACKER_INPUT_BUFF_0_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_V_MATRIX_OFFSET_0_DEPACKER_INPUT_BUFF_0_LSB    0
#define MACDSP_API1_V_MATRIX_OFFSET_0_DEPACKER_INPUT_BUFF_0_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_V_MATRIX_OFFSET_0_DEPACKER_INPUT_BUFF_0_RST    0x0

__INLINE uint32_t macdsp_api1_v_matrix_offset_0_depacker_input_buff_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_V_MATRIX_OFFSET_0_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_v_matrix_offset_0_depacker_input_buff_0_setf(uint32_t depackerinputbuff0)
{
	ASSERT_ERR((((uint32_t)depackerinputbuff0 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_V_MATRIX_OFFSET_0_ADDR, (uint32_t)depackerinputbuff0 << 0);
}

/**
 * @brief V_MATRIX_OFFSET_1 register definition
 *  Input for the depacker user 1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DEPACKER_INPUT_BUFF_1     0x0
 * </pre>
 */
#define MACDSP_API1_V_MATRIX_OFFSET_1_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000008C4)
#define MACDSP_API1_V_MATRIX_OFFSET_1_OFFSET      0x000008C4
#define MACDSP_API1_V_MATRIX_OFFSET_1_INDEX       0x00000231
#define MACDSP_API1_V_MATRIX_OFFSET_1_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_v_matrix_offset_1_get(void)
{
	return REG_PL_RD(MACDSP_API1_V_MATRIX_OFFSET_1_ADDR);
}

__INLINE void macdsp_api1_v_matrix_offset_1_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_V_MATRIX_OFFSET_1_ADDR, value);
}

// field definitions
#define MACDSP_API1_V_MATRIX_OFFSET_1_DEPACKER_INPUT_BUFF_1_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_V_MATRIX_OFFSET_1_DEPACKER_INPUT_BUFF_1_LSB    0
#define MACDSP_API1_V_MATRIX_OFFSET_1_DEPACKER_INPUT_BUFF_1_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_V_MATRIX_OFFSET_1_DEPACKER_INPUT_BUFF_1_RST    0x0

__INLINE uint32_t macdsp_api1_v_matrix_offset_1_depacker_input_buff_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_V_MATRIX_OFFSET_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_v_matrix_offset_1_depacker_input_buff_1_setf(uint32_t depackerinputbuff1)
{
	ASSERT_ERR((((uint32_t)depackerinputbuff1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_V_MATRIX_OFFSET_1_ADDR, (uint32_t)depackerinputbuff1 << 0);
}

/**
 * @brief V_MATRIX_OFFSET_2 register definition
 *  Input for the depacker user 2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DEPACKER_INPUT_BUFF_2     0x0
 * </pre>
 */
#define MACDSP_API1_V_MATRIX_OFFSET_2_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000008C8)
#define MACDSP_API1_V_MATRIX_OFFSET_2_OFFSET      0x000008C8
#define MACDSP_API1_V_MATRIX_OFFSET_2_INDEX       0x00000232
#define MACDSP_API1_V_MATRIX_OFFSET_2_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_v_matrix_offset_2_get(void)
{
	return REG_PL_RD(MACDSP_API1_V_MATRIX_OFFSET_2_ADDR);
}

__INLINE void macdsp_api1_v_matrix_offset_2_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_V_MATRIX_OFFSET_2_ADDR, value);
}

// field definitions
#define MACDSP_API1_V_MATRIX_OFFSET_2_DEPACKER_INPUT_BUFF_2_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_V_MATRIX_OFFSET_2_DEPACKER_INPUT_BUFF_2_LSB    0
#define MACDSP_API1_V_MATRIX_OFFSET_2_DEPACKER_INPUT_BUFF_2_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_V_MATRIX_OFFSET_2_DEPACKER_INPUT_BUFF_2_RST    0x0

__INLINE uint32_t macdsp_api1_v_matrix_offset_2_depacker_input_buff_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_V_MATRIX_OFFSET_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_v_matrix_offset_2_depacker_input_buff_2_setf(uint32_t depackerinputbuff2)
{
	ASSERT_ERR((((uint32_t)depackerinputbuff2 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_V_MATRIX_OFFSET_2_ADDR, (uint32_t)depackerinputbuff2 << 0);
}

/**
 * @brief V_MATRIX_OFFSET_3 register definition
 *  Input for the depacker user 3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 DEPACKER_INPUT_BUFF_3     0x0
 * </pre>
 */
#define MACDSP_API1_V_MATRIX_OFFSET_3_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000008CC)
#define MACDSP_API1_V_MATRIX_OFFSET_3_OFFSET      0x000008CC
#define MACDSP_API1_V_MATRIX_OFFSET_3_INDEX       0x00000233
#define MACDSP_API1_V_MATRIX_OFFSET_3_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_v_matrix_offset_3_get(void)
{
	return REG_PL_RD(MACDSP_API1_V_MATRIX_OFFSET_3_ADDR);
}

__INLINE void macdsp_api1_v_matrix_offset_3_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_V_MATRIX_OFFSET_3_ADDR, value);
}

// field definitions
#define MACDSP_API1_V_MATRIX_OFFSET_3_DEPACKER_INPUT_BUFF_3_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_V_MATRIX_OFFSET_3_DEPACKER_INPUT_BUFF_3_LSB    0
#define MACDSP_API1_V_MATRIX_OFFSET_3_DEPACKER_INPUT_BUFF_3_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_V_MATRIX_OFFSET_3_DEPACKER_INPUT_BUFF_3_RST    0x0

__INLINE uint32_t macdsp_api1_v_matrix_offset_3_depacker_input_buff_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_V_MATRIX_OFFSET_3_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_v_matrix_offset_3_depacker_input_buff_3_setf(uint32_t depackerinputbuff3)
{
	ASSERT_ERR((((uint32_t)depackerinputbuff3 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_V_MATRIX_OFFSET_3_ADDR, (uint32_t)depackerinputbuff3 << 0);
}

/**
 * @brief DCOC_STAND_ALONE_TRIGGER register definition
 *  trigger area for DCOC stand alone register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 dcoc_stand_alone_trigger_reserved0 0x0
 * </pre>
 */
#define MACDSP_API1_DCOC_STAND_ALONE_TRIGGER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000008D0)
#define MACDSP_API1_DCOC_STAND_ALONE_TRIGGER_OFFSET      0x000008D0
#define MACDSP_API1_DCOC_STAND_ALONE_TRIGGER_INDEX       0x00000234
#define MACDSP_API1_DCOC_STAND_ALONE_TRIGGER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_dcoc_stand_alone_trigger_get(void)
{
	return REG_PL_RD(MACDSP_API1_DCOC_STAND_ALONE_TRIGGER_ADDR);
}

__INLINE void macdsp_api1_dcoc_stand_alone_trigger_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_DCOC_STAND_ALONE_TRIGGER_ADDR, value);
}

// field definitions
#define MACDSP_API1_DCOC_STAND_ALONE_TRIGGER_DCOC_STAND_ALONE_TRIGGER_RESERVED_0_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_DCOC_STAND_ALONE_TRIGGER_DCOC_STAND_ALONE_TRIGGER_RESERVED_0_LSB    0
#define MACDSP_API1_DCOC_STAND_ALONE_TRIGGER_DCOC_STAND_ALONE_TRIGGER_RESERVED_0_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_DCOC_STAND_ALONE_TRIGGER_DCOC_STAND_ALONE_TRIGGER_RESERVED_0_RST    0x0

__INLINE uint32_t macdsp_api1_dcoc_stand_alone_trigger_dcoc_stand_alone_trigger_reserved_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DCOC_STAND_ALONE_TRIGGER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_dcoc_stand_alone_trigger_dcoc_stand_alone_trigger_reserved_0_setf(uint32_t dcocstandalonetriggerreserved0)
{
	ASSERT_ERR((((uint32_t)dcocstandalonetriggerreserved0 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_DCOC_STAND_ALONE_TRIGGER_ADDR, (uint32_t)dcocstandalonetriggerreserved0 << 0);
}

/**
 * @brief RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB register definition
 *  RX RIU RESAMPLER DELTA OFFSET FROM MATLAB register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLA 0x0
 * </pre>
 */
#define MACDSP_API1_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000008D4)
#define MACDSP_API1_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_OFFSET      0x000008D4
#define MACDSP_API1_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_INDEX       0x00000235
#define MACDSP_API1_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_riu_resampler_delta_offset_from_matlab_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR);
}

__INLINE void macdsp_api1_rx_riu_resampler_delta_offset_from_matlab_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLA_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLA_LSB    0
#define MACDSP_API1_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLA_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLA_RST    0x0

__INLINE uint32_t macdsp_api1_rx_riu_resampler_delta_offset_from_matlab_rx_riu_resampler_delta_offset_from_matla_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_riu_resampler_delta_offset_from_matlab_rx_riu_resampler_delta_offset_from_matla_setf(uint32_t rxriuresamplerdeltaoffsetfrommatla)
{
	ASSERT_ERR((((uint32_t)rxriuresamplerdeltaoffsetfrommatla << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR, (uint32_t)rxriuresamplerdeltaoffsetfrommatla << 0);
}

/**
 * @brief PLDM_RIUOUT_FLAGS register definition
 *  PLDM_RIUOUT_FLAG_INDICATION register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    RIUOUT_ON                 0              
 * </pre>
 */
#define MACDSP_API1_PLDM_RIUOUT_FLAGS_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000008D8)
#define MACDSP_API1_PLDM_RIUOUT_FLAGS_OFFSET      0x000008D8
#define MACDSP_API1_PLDM_RIUOUT_FLAGS_INDEX       0x00000236
#define MACDSP_API1_PLDM_RIUOUT_FLAGS_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_pldm_riuout_flags_get(void)
{
	return REG_PL_RD(MACDSP_API1_PLDM_RIUOUT_FLAGS_ADDR);
}

__INLINE void macdsp_api1_pldm_riuout_flags_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_PLDM_RIUOUT_FLAGS_ADDR, value);
}

// field definitions
#define MACDSP_API1_PLDM_RIUOUT_FLAGS_RIUOUT_ON_BIT    ((uint32_t)0x00000001)
#define MACDSP_API1_PLDM_RIUOUT_FLAGS_RIUOUT_ON_POS    0

#define MACDSP_API1_PLDM_RIUOUT_FLAGS_RIUOUT_ON_RST    0x0

__INLINE uint8_t macdsp_api1_pldm_riuout_flags_riuout_on_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_PLDM_RIUOUT_FLAGS_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void macdsp_api1_pldm_riuout_flags_riuout_on_setf(uint8_t riuouton)
{
	ASSERT_ERR((((uint32_t)riuouton << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACDSP_API1_PLDM_RIUOUT_FLAGS_ADDR, (uint32_t)riuouton << 0);
}

/**
 * @brief Q_GEN_REQ_PARAMS_PLDM register definition
 *  Q_GEN_REQ_PARAMS_PLDM register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    17:16 TARGET_REGROUPING_PLDM    0x0
 *    14:12 TARGET_NC_PLDM            0x0
 *    11:04 MIRROR_VECTOR_INDEX_PLDM  0x0
 *    03:00 V_MATRIXES_NUMBER_MINUS_ONE_PLDM 0x0
 * </pre>
 */
#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000008DC)
#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_OFFSET      0x000008DC
#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_INDEX       0x00000237
#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_q_gen_req_params_pldm_get(void)
{
	return REG_PL_RD(MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_ADDR);
}

__INLINE void macdsp_api1_q_gen_req_params_pldm_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_ADDR, value);
}

// field definitions
#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_TARGET_REGROUPING_PLDM_MASK    ((uint32_t)0x00030000)
#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_TARGET_REGROUPING_PLDM_LSB    16
#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_TARGET_REGROUPING_PLDM_WIDTH    ((uint32_t)0x00000002)
#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_TARGET_NC_PLDM_MASK    ((uint32_t)0x00007000)
#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_TARGET_NC_PLDM_LSB    12
#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_TARGET_NC_PLDM_WIDTH    ((uint32_t)0x00000003)
#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_MIRROR_VECTOR_INDEX_PLDM_MASK    ((uint32_t)0x00000FF0)
#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_MIRROR_VECTOR_INDEX_PLDM_LSB    4
#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_MIRROR_VECTOR_INDEX_PLDM_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_V_MATRIXES_NUMBER_MINUS_ONE_PLDM_MASK    ((uint32_t)0x0000000F)
#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_V_MATRIXES_NUMBER_MINUS_ONE_PLDM_LSB    0
#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_V_MATRIXES_NUMBER_MINUS_ONE_PLDM_WIDTH    ((uint32_t)0x00000004)

#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_TARGET_REGROUPING_PLDM_RST    0x0
#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_TARGET_NC_PLDM_RST    0x0
#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_MIRROR_VECTOR_INDEX_PLDM_RST    0x0
#define MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_V_MATRIXES_NUMBER_MINUS_ONE_PLDM_RST    0x0

__INLINE void macdsp_api1_q_gen_req_params_pldm_pack(uint8_t target_regrouping_pldm, uint8_t target_nc_pldm, uint8_t mirror_vector_index_pldm, uint8_t v_matrixes_number_minus_one_pldm)
{
	ASSERT_ERR((((uint32_t)target_regrouping_pldm << 16) & ~((uint32_t)0x00030000)) == 0);
	ASSERT_ERR((((uint32_t)target_nc_pldm << 12) & ~((uint32_t)0x00007000)) == 0);
	ASSERT_ERR((((uint32_t)mirror_vector_index_pldm << 4) & ~((uint32_t)0x00000FF0)) == 0);
	ASSERT_ERR((((uint32_t)v_matrixes_number_minus_one_pldm << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_ADDR,  ((uint32_t)target_regrouping_pldm << 16) |((uint32_t)target_nc_pldm << 12) |((uint32_t)mirror_vector_index_pldm << 4) |((uint32_t)v_matrixes_number_minus_one_pldm << 0));
}

__INLINE void macdsp_api1_q_gen_req_params_pldm_unpack(uint8_t* target_regrouping_pldm, uint8_t* target_nc_pldm, uint8_t* mirror_vector_index_pldm, uint8_t* v_matrixes_number_minus_one_pldm)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_ADDR);

	*target_regrouping_pldm = (localVal & ((uint32_t)0x00030000)) >>  16;
	*target_nc_pldm = (localVal & ((uint32_t)0x00007000)) >>  12;
	*mirror_vector_index_pldm = (localVal & ((uint32_t)0x00000FF0)) >>  4;
	*v_matrixes_number_minus_one_pldm = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t macdsp_api1_q_gen_req_params_pldm_target_regrouping_pldm_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00030000)) >> 16);
}
__INLINE void macdsp_api1_q_gen_req_params_pldm_target_regrouping_pldm_setf(uint8_t targetregroupingpldm)
{
	ASSERT_ERR((((uint32_t)targetregroupingpldm << 16) & ~((uint32_t)0x00030000)) == 0);
	REG_PL_WR(MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_ADDR, (REG_PL_RD(MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_ADDR) & ~((uint32_t)0x00030000)) | ((uint32_t)targetregroupingpldm <<16));
}
__INLINE uint8_t macdsp_api1_q_gen_req_params_pldm_target_nc_pldm_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007000)) >> 12);
}
__INLINE void macdsp_api1_q_gen_req_params_pldm_target_nc_pldm_setf(uint8_t targetncpldm)
{
	ASSERT_ERR((((uint32_t)targetncpldm << 12) & ~((uint32_t)0x00007000)) == 0);
	REG_PL_WR(MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_ADDR, (REG_PL_RD(MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_ADDR) & ~((uint32_t)0x00007000)) | ((uint32_t)targetncpldm <<12));
}
__INLINE uint8_t macdsp_api1_q_gen_req_params_pldm_mirror_vector_index_pldm_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000FF0)) >> 4);
}
__INLINE void macdsp_api1_q_gen_req_params_pldm_mirror_vector_index_pldm_setf(uint8_t mirrorvectorindexpldm)
{
	ASSERT_ERR((((uint32_t)mirrorvectorindexpldm << 4) & ~((uint32_t)0x00000FF0)) == 0);
	REG_PL_WR(MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_ADDR, (REG_PL_RD(MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_ADDR) & ~((uint32_t)0x00000FF0)) | ((uint32_t)mirrorvectorindexpldm <<4));
}
__INLINE uint8_t macdsp_api1_q_gen_req_params_pldm_v_matrixes_number_minus_one_pldm_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void macdsp_api1_q_gen_req_params_pldm_v_matrixes_number_minus_one_pldm_setf(uint8_t vmatrixesnumberminusonepldm)
{
	ASSERT_ERR((((uint32_t)vmatrixesnumberminusonepldm << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_ADDR, (REG_PL_RD(MACDSP_API1_Q_GEN_REQ_PARAMS_PLDM_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)vmatrixesnumberminusonepldm <<0));
}

/**
 * @brief MATLAB_GENIE_CPE_STO register definition
 *  values for cpe and sto from Matlab register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 MATLAB_GENIE_CPE_STO      0x0
 * </pre>
 */
#define MACDSP_API1_MATLAB_GENIE_CPE_STO_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000008E0)
#define MACDSP_API1_MATLAB_GENIE_CPE_STO_OFFSET      0x000008E0
#define MACDSP_API1_MATLAB_GENIE_CPE_STO_INDEX       0x00000238
#define MACDSP_API1_MATLAB_GENIE_CPE_STO_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_matlab_genie_cpe_sto_get(void)
{
	return REG_PL_RD(MACDSP_API1_MATLAB_GENIE_CPE_STO_ADDR);
}

__INLINE void macdsp_api1_matlab_genie_cpe_sto_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_MATLAB_GENIE_CPE_STO_ADDR, value);
}

// field definitions
#define MACDSP_API1_MATLAB_GENIE_CPE_STO_MATLAB_GENIE_CPE_STO_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_MATLAB_GENIE_CPE_STO_MATLAB_GENIE_CPE_STO_LSB    0
#define MACDSP_API1_MATLAB_GENIE_CPE_STO_MATLAB_GENIE_CPE_STO_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_MATLAB_GENIE_CPE_STO_MATLAB_GENIE_CPE_STO_RST    0x0

__INLINE uint32_t macdsp_api1_matlab_genie_cpe_sto_matlab_genie_cpe_sto_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_MATLAB_GENIE_CPE_STO_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_matlab_genie_cpe_sto_matlab_genie_cpe_sto_setf(uint32_t matlabgeniecpesto)
{
	ASSERT_ERR((((uint32_t)matlabgeniecpesto << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_MATLAB_GENIE_CPE_STO_ADDR, (uint32_t)matlabgeniecpesto << 0);
}

/**
 * @brief GENIE_RIUOUT_ENABLE register definition
 *  indication for genie and riuout register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    RIUOUT_ENABLE             0              
 *    00    GENIE_ENABLE              0              
 * </pre>
 */
#define MACDSP_API1_GENIE_RIUOUT_ENABLE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000008E4)
#define MACDSP_API1_GENIE_RIUOUT_ENABLE_OFFSET      0x000008E4
#define MACDSP_API1_GENIE_RIUOUT_ENABLE_INDEX       0x00000239
#define MACDSP_API1_GENIE_RIUOUT_ENABLE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_genie_riuout_enable_get(void)
{
	return REG_PL_RD(MACDSP_API1_GENIE_RIUOUT_ENABLE_ADDR);
}

__INLINE void macdsp_api1_genie_riuout_enable_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_GENIE_RIUOUT_ENABLE_ADDR, value);
}

// field definitions
#define MACDSP_API1_GENIE_RIUOUT_ENABLE_RIUOUT_ENABLE_BIT    ((uint32_t)0x00000002)
#define MACDSP_API1_GENIE_RIUOUT_ENABLE_RIUOUT_ENABLE_POS    1
#define MACDSP_API1_GENIE_RIUOUT_ENABLE_GENIE_ENABLE_BIT    ((uint32_t)0x00000001)
#define MACDSP_API1_GENIE_RIUOUT_ENABLE_GENIE_ENABLE_POS    0

#define MACDSP_API1_GENIE_RIUOUT_ENABLE_RIUOUT_ENABLE_RST    0x0
#define MACDSP_API1_GENIE_RIUOUT_ENABLE_GENIE_ENABLE_RST    0x0

__INLINE void macdsp_api1_genie_riuout_enable_pack(uint8_t riuout_enable, uint8_t genie_enable)
{
	ASSERT_ERR((((uint32_t)riuout_enable << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)genie_enable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACDSP_API1_GENIE_RIUOUT_ENABLE_ADDR,  ((uint32_t)riuout_enable << 1) |((uint32_t)genie_enable << 0));
}

__INLINE void macdsp_api1_genie_riuout_enable_unpack(uint8_t* riuout_enable, uint8_t* genie_enable)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_GENIE_RIUOUT_ENABLE_ADDR);

	*riuout_enable = (localVal & ((uint32_t)0x00000002)) >>  1;
	*genie_enable = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t macdsp_api1_genie_riuout_enable_riuout_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_GENIE_RIUOUT_ENABLE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void macdsp_api1_genie_riuout_enable_riuout_enable_setf(uint8_t riuoutenable)
{
	ASSERT_ERR((((uint32_t)riuoutenable << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(MACDSP_API1_GENIE_RIUOUT_ENABLE_ADDR, (REG_PL_RD(MACDSP_API1_GENIE_RIUOUT_ENABLE_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)riuoutenable <<1));
}
__INLINE uint8_t macdsp_api1_genie_riuout_enable_genie_enable_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_GENIE_RIUOUT_ENABLE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void macdsp_api1_genie_riuout_enable_genie_enable_setf(uint8_t genieenable)
{
	ASSERT_ERR((((uint32_t)genieenable << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACDSP_API1_GENIE_RIUOUT_ENABLE_ADDR, (REG_PL_RD(MACDSP_API1_GENIE_RIUOUT_ENABLE_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)genieenable <<0));
}

/**
 * @brief BFR_TX_DELAY register definition
 *  Delay used by the DSP before writing BFR PBDs register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 SECOND_SHOT_DELAY         0x0
 *    15:00 FIRST_SHOT_DELAY          0x0
 * </pre>
 */
#define MACDSP_API1_BFR_TX_DELAY_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000008E8)
#define MACDSP_API1_BFR_TX_DELAY_OFFSET      0x000008E8
#define MACDSP_API1_BFR_TX_DELAY_INDEX       0x0000023A
#define MACDSP_API1_BFR_TX_DELAY_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_bfr_tx_delay_get(void)
{
	return REG_PL_RD(MACDSP_API1_BFR_TX_DELAY_ADDR);
}

__INLINE void macdsp_api1_bfr_tx_delay_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_BFR_TX_DELAY_ADDR, value);
}

// field definitions
#define MACDSP_API1_BFR_TX_DELAY_SECOND_SHOT_DELAY_MASK    ((uint32_t)0xFFFF0000)
#define MACDSP_API1_BFR_TX_DELAY_SECOND_SHOT_DELAY_LSB    16
#define MACDSP_API1_BFR_TX_DELAY_SECOND_SHOT_DELAY_WIDTH    ((uint32_t)0x00000010)
#define MACDSP_API1_BFR_TX_DELAY_FIRST_SHOT_DELAY_MASK    ((uint32_t)0x0000FFFF)
#define MACDSP_API1_BFR_TX_DELAY_FIRST_SHOT_DELAY_LSB    0
#define MACDSP_API1_BFR_TX_DELAY_FIRST_SHOT_DELAY_WIDTH    ((uint32_t)0x00000010)

#define MACDSP_API1_BFR_TX_DELAY_SECOND_SHOT_DELAY_RST    0x0
#define MACDSP_API1_BFR_TX_DELAY_FIRST_SHOT_DELAY_RST    0x0

__INLINE void macdsp_api1_bfr_tx_delay_pack(uint16_t second_shot_delay, uint16_t first_shot_delay)
{
	ASSERT_ERR((((uint32_t)second_shot_delay << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	ASSERT_ERR((((uint32_t)first_shot_delay << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_BFR_TX_DELAY_ADDR,  ((uint32_t)second_shot_delay << 16) |((uint32_t)first_shot_delay << 0));
}

__INLINE void macdsp_api1_bfr_tx_delay_unpack(uint16_t* second_shot_delay, uint16_t* first_shot_delay)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_BFR_TX_DELAY_ADDR);

	*second_shot_delay = (localVal & ((uint32_t)0xFFFF0000)) >>  16;
	*first_shot_delay = (localVal & ((uint32_t)0x0000FFFF)) >>  0;
}

__INLINE uint16_t macdsp_api1_bfr_tx_delay_second_shot_delay_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_BFR_TX_DELAY_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}
__INLINE void macdsp_api1_bfr_tx_delay_second_shot_delay_setf(uint16_t secondshotdelay)
{
	ASSERT_ERR((((uint32_t)secondshotdelay << 16) & ~((uint32_t)0xFFFF0000)) == 0);
	REG_PL_WR(MACDSP_API1_BFR_TX_DELAY_ADDR, (REG_PL_RD(MACDSP_API1_BFR_TX_DELAY_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)secondshotdelay <<16));
}
__INLINE uint16_t macdsp_api1_bfr_tx_delay_first_shot_delay_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_BFR_TX_DELAY_ADDR);
	return (uint16_t)((localVal & ((uint32_t)0x0000FFFF)) >> 0);
}
__INLINE void macdsp_api1_bfr_tx_delay_first_shot_delay_setf(uint16_t firstshotdelay)
{
	ASSERT_ERR((((uint32_t)firstshotdelay << 0) & ~((uint32_t)0x0000FFFF)) == 0);
	REG_PL_WR(MACDSP_API1_BFR_TX_DELAY_ADDR, (REG_PL_RD(MACDSP_API1_BFR_TX_DELAY_ADDR) & ~((uint32_t)0x0000FFFF)) | ((uint32_t)firstshotdelay <<0));
}

/**
 * @brief AGCINBDPOW_20_P register definition
 *  INBD_POWER_FOR_MAC_ANT03 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 INBDPOW20_PDBA3_MAC       0x0
 *    23:16 INBDPOW20_PDBA2_MAC       0x0
 *    15:08 INBDPOW20_PDBA1_MAC       0x0
 *    07:00 INBDPOW20_PDBA0_MAC       0x0
 * </pre>
 */
#define MACDSP_API1_AGCINBDPOW_20_P_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000008EC)
#define MACDSP_API1_AGCINBDPOW_20_P_OFFSET      0x000008EC
#define MACDSP_API1_AGCINBDPOW_20_P_INDEX       0x0000023B
#define MACDSP_API1_AGCINBDPOW_20_P_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_agcinbdpow_20_p_get(void)
{
	return REG_PL_RD(MACDSP_API1_AGCINBDPOW_20_P_ADDR);
}

__INLINE void macdsp_api1_agcinbdpow_20_p_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_AGCINBDPOW_20_P_ADDR, value);
}

// field definitions
#define MACDSP_API1_AGCINBDPOW_20_P_INBDPOW_20_PDBA_3_MAC_MASK    ((uint32_t)0xFF000000)
#define MACDSP_API1_AGCINBDPOW_20_P_INBDPOW_20_PDBA_3_MAC_LSB    24
#define MACDSP_API1_AGCINBDPOW_20_P_INBDPOW_20_PDBA_3_MAC_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_AGCINBDPOW_20_P_INBDPOW_20_PDBA_2_MAC_MASK    ((uint32_t)0x00FF0000)
#define MACDSP_API1_AGCINBDPOW_20_P_INBDPOW_20_PDBA_2_MAC_LSB    16
#define MACDSP_API1_AGCINBDPOW_20_P_INBDPOW_20_PDBA_2_MAC_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_AGCINBDPOW_20_P_INBDPOW_20_PDBA_1_MAC_MASK    ((uint32_t)0x0000FF00)
#define MACDSP_API1_AGCINBDPOW_20_P_INBDPOW_20_PDBA_1_MAC_LSB    8
#define MACDSP_API1_AGCINBDPOW_20_P_INBDPOW_20_PDBA_1_MAC_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_AGCINBDPOW_20_P_INBDPOW_20_PDBA_0_MAC_MASK    ((uint32_t)0x000000FF)
#define MACDSP_API1_AGCINBDPOW_20_P_INBDPOW_20_PDBA_0_MAC_LSB    0
#define MACDSP_API1_AGCINBDPOW_20_P_INBDPOW_20_PDBA_0_MAC_WIDTH    ((uint32_t)0x00000008)

#define MACDSP_API1_AGCINBDPOW_20_P_INBDPOW_20_PDBA_3_MAC_RST    0x0
#define MACDSP_API1_AGCINBDPOW_20_P_INBDPOW_20_PDBA_2_MAC_RST    0x0
#define MACDSP_API1_AGCINBDPOW_20_P_INBDPOW_20_PDBA_1_MAC_RST    0x0
#define MACDSP_API1_AGCINBDPOW_20_P_INBDPOW_20_PDBA_0_MAC_RST    0x0

__INLINE void macdsp_api1_agcinbdpow_20_p_pack(uint8_t inbdpow20_pdba3_mac, uint8_t inbdpow20_pdba2_mac, uint8_t inbdpow20_pdba1_mac, uint8_t inbdpow20_pdba0_mac)
{
	ASSERT_ERR((((uint32_t)inbdpow20_pdba3_mac << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)inbdpow20_pdba2_mac << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)inbdpow20_pdba1_mac << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)inbdpow20_pdba0_mac << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_AGCINBDPOW_20_P_ADDR,  ((uint32_t)inbdpow20_pdba3_mac << 24) |((uint32_t)inbdpow20_pdba2_mac << 16) |((uint32_t)inbdpow20_pdba1_mac << 8) |((uint32_t)inbdpow20_pdba0_mac << 0));
}

__INLINE void macdsp_api1_agcinbdpow_20_p_unpack(uint8_t* inbdpow20_pdba3_mac, uint8_t* inbdpow20_pdba2_mac, uint8_t* inbdpow20_pdba1_mac, uint8_t* inbdpow20_pdba0_mac)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_AGCINBDPOW_20_P_ADDR);

	*inbdpow20_pdba3_mac = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*inbdpow20_pdba2_mac = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*inbdpow20_pdba1_mac = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*inbdpow20_pdba0_mac = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t macdsp_api1_agcinbdpow_20_p_inbdpow_20_pdba_3_mac_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_AGCINBDPOW_20_P_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void macdsp_api1_agcinbdpow_20_p_inbdpow_20_pdba_3_mac_setf(uint8_t inbdpow20pdba3mac)
{
	ASSERT_ERR((((uint32_t)inbdpow20pdba3mac << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(MACDSP_API1_AGCINBDPOW_20_P_ADDR, (REG_PL_RD(MACDSP_API1_AGCINBDPOW_20_P_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)inbdpow20pdba3mac <<24));
}
__INLINE uint8_t macdsp_api1_agcinbdpow_20_p_inbdpow_20_pdba_2_mac_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_AGCINBDPOW_20_P_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void macdsp_api1_agcinbdpow_20_p_inbdpow_20_pdba_2_mac_setf(uint8_t inbdpow20pdba2mac)
{
	ASSERT_ERR((((uint32_t)inbdpow20pdba2mac << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(MACDSP_API1_AGCINBDPOW_20_P_ADDR, (REG_PL_RD(MACDSP_API1_AGCINBDPOW_20_P_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)inbdpow20pdba2mac <<16));
}
__INLINE uint8_t macdsp_api1_agcinbdpow_20_p_inbdpow_20_pdba_1_mac_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_AGCINBDPOW_20_P_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void macdsp_api1_agcinbdpow_20_p_inbdpow_20_pdba_1_mac_setf(uint8_t inbdpow20pdba1mac)
{
	ASSERT_ERR((((uint32_t)inbdpow20pdba1mac << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(MACDSP_API1_AGCINBDPOW_20_P_ADDR, (REG_PL_RD(MACDSP_API1_AGCINBDPOW_20_P_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)inbdpow20pdba1mac <<8));
}
__INLINE uint8_t macdsp_api1_agcinbdpow_20_p_inbdpow_20_pdba_0_mac_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_AGCINBDPOW_20_P_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void macdsp_api1_agcinbdpow_20_p_inbdpow_20_pdba_0_mac_setf(uint8_t inbdpow20pdba0mac)
{
	ASSERT_ERR((((uint32_t)inbdpow20pdba0mac << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_AGCINBDPOW_20_P_ADDR, (REG_PL_RD(MACDSP_API1_AGCINBDPOW_20_P_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)inbdpow20pdba0mac <<0));
}

/**
 * @brief AGCINBDPOW_20_P_2 register definition
 *  INBD_POWER_FOR_MAC_ANT45 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:08 INBDPOW20_PDBA5_MAC       0x0
 *    07:00 INBDPOW20_PDBA4_MAC       0x0
 * </pre>
 */
#define MACDSP_API1_AGCINBDPOW_20_P_2_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000008F0)
#define MACDSP_API1_AGCINBDPOW_20_P_2_OFFSET      0x000008F0
#define MACDSP_API1_AGCINBDPOW_20_P_2_INDEX       0x0000023C
#define MACDSP_API1_AGCINBDPOW_20_P_2_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_agcinbdpow_20_p_2_get(void)
{
	return REG_PL_RD(MACDSP_API1_AGCINBDPOW_20_P_2_ADDR);
}

__INLINE void macdsp_api1_agcinbdpow_20_p_2_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_AGCINBDPOW_20_P_2_ADDR, value);
}

// field definitions
#define MACDSP_API1_AGCINBDPOW_20_P_2_INBDPOW_20_PDBA_5_MAC_MASK    ((uint32_t)0x0000FF00)
#define MACDSP_API1_AGCINBDPOW_20_P_2_INBDPOW_20_PDBA_5_MAC_LSB    8
#define MACDSP_API1_AGCINBDPOW_20_P_2_INBDPOW_20_PDBA_5_MAC_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_AGCINBDPOW_20_P_2_INBDPOW_20_PDBA_4_MAC_MASK    ((uint32_t)0x000000FF)
#define MACDSP_API1_AGCINBDPOW_20_P_2_INBDPOW_20_PDBA_4_MAC_LSB    0
#define MACDSP_API1_AGCINBDPOW_20_P_2_INBDPOW_20_PDBA_4_MAC_WIDTH    ((uint32_t)0x00000008)

#define MACDSP_API1_AGCINBDPOW_20_P_2_INBDPOW_20_PDBA_5_MAC_RST    0x0
#define MACDSP_API1_AGCINBDPOW_20_P_2_INBDPOW_20_PDBA_4_MAC_RST    0x0

__INLINE void macdsp_api1_agcinbdpow_20_p_2_pack(uint8_t inbdpow20_pdba5_mac, uint8_t inbdpow20_pdba4_mac)
{
	ASSERT_ERR((((uint32_t)inbdpow20_pdba5_mac << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)inbdpow20_pdba4_mac << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_AGCINBDPOW_20_P_2_ADDR,  ((uint32_t)inbdpow20_pdba5_mac << 8) |((uint32_t)inbdpow20_pdba4_mac << 0));
}

__INLINE void macdsp_api1_agcinbdpow_20_p_2_unpack(uint8_t* inbdpow20_pdba5_mac, uint8_t* inbdpow20_pdba4_mac)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_AGCINBDPOW_20_P_2_ADDR);

	*inbdpow20_pdba5_mac = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*inbdpow20_pdba4_mac = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t macdsp_api1_agcinbdpow_20_p_2_inbdpow_20_pdba_5_mac_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_AGCINBDPOW_20_P_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void macdsp_api1_agcinbdpow_20_p_2_inbdpow_20_pdba_5_mac_setf(uint8_t inbdpow20pdba5mac)
{
	ASSERT_ERR((((uint32_t)inbdpow20pdba5mac << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(MACDSP_API1_AGCINBDPOW_20_P_2_ADDR, (REG_PL_RD(MACDSP_API1_AGCINBDPOW_20_P_2_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)inbdpow20pdba5mac <<8));
}
__INLINE uint8_t macdsp_api1_agcinbdpow_20_p_2_inbdpow_20_pdba_4_mac_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_AGCINBDPOW_20_P_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void macdsp_api1_agcinbdpow_20_p_2_inbdpow_20_pdba_4_mac_setf(uint8_t inbdpow20pdba4mac)
{
	ASSERT_ERR((((uint32_t)inbdpow20pdba4mac << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_AGCINBDPOW_20_P_2_ADDR, (REG_PL_RD(MACDSP_API1_AGCINBDPOW_20_P_2_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)inbdpow20pdba4mac <<0));
}

/**
 * @brief RADAR_PULSE_FIFO_1 register definition
 *  RADAR_R_W_FIFO_FRIST_VALUE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RADAR_FIFO_FRIST_VALUE    0x0
 * </pre>
 */
#define MACDSP_API1_RADAR_PULSE_FIFO_1_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000008F4)
#define MACDSP_API1_RADAR_PULSE_FIFO_1_OFFSET      0x000008F4
#define MACDSP_API1_RADAR_PULSE_FIFO_1_INDEX       0x0000023D
#define MACDSP_API1_RADAR_PULSE_FIFO_1_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_radar_pulse_fifo_1_get(void)
{
	return REG_PL_RD(MACDSP_API1_RADAR_PULSE_FIFO_1_ADDR);
}

__INLINE void macdsp_api1_radar_pulse_fifo_1_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RADAR_PULSE_FIFO_1_ADDR, value);
}

// field definitions
#define MACDSP_API1_RADAR_PULSE_FIFO_1_RADAR_FIFO_FRIST_VALUE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_RADAR_PULSE_FIFO_1_RADAR_FIFO_FRIST_VALUE_LSB    0
#define MACDSP_API1_RADAR_PULSE_FIFO_1_RADAR_FIFO_FRIST_VALUE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_RADAR_PULSE_FIFO_1_RADAR_FIFO_FRIST_VALUE_RST    0x0

__INLINE uint32_t macdsp_api1_radar_pulse_fifo_1_radar_fifo_frist_value_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RADAR_PULSE_FIFO_1_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_radar_pulse_fifo_1_radar_fifo_frist_value_setf(uint32_t radarfifofristvalue)
{
	ASSERT_ERR((((uint32_t)radarfifofristvalue << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RADAR_PULSE_FIFO_1_ADDR, (uint32_t)radarfifofristvalue << 0);
}

/**
 * @brief RADAR_PULSE_FIFO_2 register definition
 *  RADAR_R_W_FIFO_SECOND_VALUE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RADAR_FIFO_SECOND_VALUE   0x0
 * </pre>
 */
#define MACDSP_API1_RADAR_PULSE_FIFO_2_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000008F8)
#define MACDSP_API1_RADAR_PULSE_FIFO_2_OFFSET      0x000008F8
#define MACDSP_API1_RADAR_PULSE_FIFO_2_INDEX       0x0000023E
#define MACDSP_API1_RADAR_PULSE_FIFO_2_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_radar_pulse_fifo_2_get(void)
{
	return REG_PL_RD(MACDSP_API1_RADAR_PULSE_FIFO_2_ADDR);
}

__INLINE void macdsp_api1_radar_pulse_fifo_2_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RADAR_PULSE_FIFO_2_ADDR, value);
}

// field definitions
#define MACDSP_API1_RADAR_PULSE_FIFO_2_RADAR_FIFO_SECOND_VALUE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_RADAR_PULSE_FIFO_2_RADAR_FIFO_SECOND_VALUE_LSB    0
#define MACDSP_API1_RADAR_PULSE_FIFO_2_RADAR_FIFO_SECOND_VALUE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_RADAR_PULSE_FIFO_2_RADAR_FIFO_SECOND_VALUE_RST    0x0

__INLINE uint32_t macdsp_api1_radar_pulse_fifo_2_radar_fifo_second_value_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RADAR_PULSE_FIFO_2_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_radar_pulse_fifo_2_radar_fifo_second_value_setf(uint32_t radarfifosecondvalue)
{
	ASSERT_ERR((((uint32_t)radarfifosecondvalue << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RADAR_PULSE_FIFO_2_ADDR, (uint32_t)radarfifosecondvalue << 0);
}

/**
 * @brief RADAR_CTRL_0 register definition
 *  radar_config register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11    SEC_PATH_EST_ANT_MRC_FLOW 1              
 *    10    SEC_PATH_EST_MRC_FLOW_EN  1              
 *    09    ANT_NUM_TO_PROC           0              
 *    08    MRC_EN                    0              
 *    07:05 SEC_ANT_SEL               0x0
 *    04:02 MAIN_ANT_SEL              0x0
 *    01:00 RADAR_SAMPLE_RATE         0x0
 * </pre>
 */
#define MACDSP_API1_RADAR_CTRL_0_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000008FC)
#define MACDSP_API1_RADAR_CTRL_0_OFFSET      0x000008FC
#define MACDSP_API1_RADAR_CTRL_0_INDEX       0x0000023F
#define MACDSP_API1_RADAR_CTRL_0_RESET       0x00000C00

__INLINE uint32_t  macdsp_api1_radar_ctrl_0_get(void)
{
	return REG_PL_RD(MACDSP_API1_RADAR_CTRL_0_ADDR);
}

__INLINE void macdsp_api1_radar_ctrl_0_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RADAR_CTRL_0_ADDR, value);
}

// field definitions
#define MACDSP_API1_RADAR_CTRL_0_SEC_PATH_EST_ANT_MRC_FLOW_BIT    ((uint32_t)0x00000800)
#define MACDSP_API1_RADAR_CTRL_0_SEC_PATH_EST_ANT_MRC_FLOW_POS    11
#define MACDSP_API1_RADAR_CTRL_0_SEC_PATH_EST_MRC_FLOW_EN_BIT    ((uint32_t)0x00000400)
#define MACDSP_API1_RADAR_CTRL_0_SEC_PATH_EST_MRC_FLOW_EN_POS    10
#define MACDSP_API1_RADAR_CTRL_0_ANT_NUM_TO_PROC_BIT    ((uint32_t)0x00000200)
#define MACDSP_API1_RADAR_CTRL_0_ANT_NUM_TO_PROC_POS    9
#define MACDSP_API1_RADAR_CTRL_0_MRC_EN_BIT    ((uint32_t)0x00000100)
#define MACDSP_API1_RADAR_CTRL_0_MRC_EN_POS    8
#define MACDSP_API1_RADAR_CTRL_0_SEC_ANT_SEL_MASK    ((uint32_t)0x000000E0)
#define MACDSP_API1_RADAR_CTRL_0_SEC_ANT_SEL_LSB    5
#define MACDSP_API1_RADAR_CTRL_0_SEC_ANT_SEL_WIDTH    ((uint32_t)0x00000003)
#define MACDSP_API1_RADAR_CTRL_0_MAIN_ANT_SEL_MASK    ((uint32_t)0x0000001C)
#define MACDSP_API1_RADAR_CTRL_0_MAIN_ANT_SEL_LSB    2
#define MACDSP_API1_RADAR_CTRL_0_MAIN_ANT_SEL_WIDTH    ((uint32_t)0x00000003)
#define MACDSP_API1_RADAR_CTRL_0_RADAR_SAMPLE_RATE_MASK    ((uint32_t)0x00000003)
#define MACDSP_API1_RADAR_CTRL_0_RADAR_SAMPLE_RATE_LSB    0
#define MACDSP_API1_RADAR_CTRL_0_RADAR_SAMPLE_RATE_WIDTH    ((uint32_t)0x00000002)

#define MACDSP_API1_RADAR_CTRL_0_SEC_PATH_EST_ANT_MRC_FLOW_RST    0x1
#define MACDSP_API1_RADAR_CTRL_0_SEC_PATH_EST_MRC_FLOW_EN_RST    0x1
#define MACDSP_API1_RADAR_CTRL_0_ANT_NUM_TO_PROC_RST    0x0
#define MACDSP_API1_RADAR_CTRL_0_MRC_EN_RST    0x0
#define MACDSP_API1_RADAR_CTRL_0_SEC_ANT_SEL_RST    0x0
#define MACDSP_API1_RADAR_CTRL_0_MAIN_ANT_SEL_RST    0x0
#define MACDSP_API1_RADAR_CTRL_0_RADAR_SAMPLE_RATE_RST    0x0

__INLINE void macdsp_api1_radar_ctrl_0_pack(uint8_t sec_path_est_ant_mrc_flow, uint8_t sec_path_est_mrc_flow_en, uint8_t ant_num_to_proc, uint8_t mrc_en, uint8_t sec_ant_sel, uint8_t main_ant_sel, uint8_t radar_sample_rate)
{
	ASSERT_ERR((((uint32_t)sec_path_est_ant_mrc_flow << 11) & ~((uint32_t)0x00000800)) == 0);
	ASSERT_ERR((((uint32_t)sec_path_est_mrc_flow_en << 10) & ~((uint32_t)0x00000400)) == 0);
	ASSERT_ERR((((uint32_t)ant_num_to_proc << 9) & ~((uint32_t)0x00000200)) == 0);
	ASSERT_ERR((((uint32_t)mrc_en << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)sec_ant_sel << 5) & ~((uint32_t)0x000000E0)) == 0);
	ASSERT_ERR((((uint32_t)main_ant_sel << 2) & ~((uint32_t)0x0000001C)) == 0);
	ASSERT_ERR((((uint32_t)radar_sample_rate << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACDSP_API1_RADAR_CTRL_0_ADDR,  ((uint32_t)sec_path_est_ant_mrc_flow << 11) |((uint32_t)sec_path_est_mrc_flow_en << 10) |((uint32_t)ant_num_to_proc << 9) |((uint32_t)mrc_en << 8) |((uint32_t)sec_ant_sel << 5) |((uint32_t)main_ant_sel << 2) |((uint32_t)radar_sample_rate << 0));
}

__INLINE void macdsp_api1_radar_ctrl_0_unpack(uint8_t* sec_path_est_ant_mrc_flow, uint8_t* sec_path_est_mrc_flow_en, uint8_t* ant_num_to_proc, uint8_t* mrc_en, uint8_t* sec_ant_sel, uint8_t* main_ant_sel, uint8_t* radar_sample_rate)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RADAR_CTRL_0_ADDR);

	*sec_path_est_ant_mrc_flow = (localVal & ((uint32_t)0x00000800)) >>  11;
	*sec_path_est_mrc_flow_en = (localVal & ((uint32_t)0x00000400)) >>  10;
	*ant_num_to_proc = (localVal & ((uint32_t)0x00000200)) >>  9;
	*mrc_en = (localVal & ((uint32_t)0x00000100)) >>  8;
	*sec_ant_sel = (localVal & ((uint32_t)0x000000E0)) >>  5;
	*main_ant_sel = (localVal & ((uint32_t)0x0000001C)) >>  2;
	*radar_sample_rate = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t macdsp_api1_radar_ctrl_0_sec_path_est_ant_mrc_flow_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RADAR_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000800)) >> 11);
}
__INLINE void macdsp_api1_radar_ctrl_0_sec_path_est_ant_mrc_flow_setf(uint8_t secpathestantmrcflow)
{
	ASSERT_ERR((((uint32_t)secpathestantmrcflow << 11) & ~((uint32_t)0x00000800)) == 0);
	REG_PL_WR(MACDSP_API1_RADAR_CTRL_0_ADDR, (REG_PL_RD(MACDSP_API1_RADAR_CTRL_0_ADDR) & ~((uint32_t)0x00000800)) | ((uint32_t)secpathestantmrcflow <<11));
}
__INLINE uint8_t macdsp_api1_radar_ctrl_0_sec_path_est_mrc_flow_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RADAR_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000400)) >> 10);
}
__INLINE void macdsp_api1_radar_ctrl_0_sec_path_est_mrc_flow_en_setf(uint8_t secpathestmrcflowen)
{
	ASSERT_ERR((((uint32_t)secpathestmrcflowen << 10) & ~((uint32_t)0x00000400)) == 0);
	REG_PL_WR(MACDSP_API1_RADAR_CTRL_0_ADDR, (REG_PL_RD(MACDSP_API1_RADAR_CTRL_0_ADDR) & ~((uint32_t)0x00000400)) | ((uint32_t)secpathestmrcflowen <<10));
}
__INLINE uint8_t macdsp_api1_radar_ctrl_0_ant_num_to_proc_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RADAR_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000200)) >> 9);
}
__INLINE void macdsp_api1_radar_ctrl_0_ant_num_to_proc_setf(uint8_t antnumtoproc)
{
	ASSERT_ERR((((uint32_t)antnumtoproc << 9) & ~((uint32_t)0x00000200)) == 0);
	REG_PL_WR(MACDSP_API1_RADAR_CTRL_0_ADDR, (REG_PL_RD(MACDSP_API1_RADAR_CTRL_0_ADDR) & ~((uint32_t)0x00000200)) | ((uint32_t)antnumtoproc <<9));
}
__INLINE uint8_t macdsp_api1_radar_ctrl_0_mrc_en_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RADAR_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void macdsp_api1_radar_ctrl_0_mrc_en_setf(uint8_t mrcen)
{
	ASSERT_ERR((((uint32_t)mrcen << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(MACDSP_API1_RADAR_CTRL_0_ADDR, (REG_PL_RD(MACDSP_API1_RADAR_CTRL_0_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)mrcen <<8));
}
__INLINE uint8_t macdsp_api1_radar_ctrl_0_sec_ant_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RADAR_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000E0)) >> 5);
}
__INLINE void macdsp_api1_radar_ctrl_0_sec_ant_sel_setf(uint8_t secantsel)
{
	ASSERT_ERR((((uint32_t)secantsel << 5) & ~((uint32_t)0x000000E0)) == 0);
	REG_PL_WR(MACDSP_API1_RADAR_CTRL_0_ADDR, (REG_PL_RD(MACDSP_API1_RADAR_CTRL_0_ADDR) & ~((uint32_t)0x000000E0)) | ((uint32_t)secantsel <<5));
}
__INLINE uint8_t macdsp_api1_radar_ctrl_0_main_ant_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RADAR_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001C)) >> 2);
}
__INLINE void macdsp_api1_radar_ctrl_0_main_ant_sel_setf(uint8_t mainantsel)
{
	ASSERT_ERR((((uint32_t)mainantsel << 2) & ~((uint32_t)0x0000001C)) == 0);
	REG_PL_WR(MACDSP_API1_RADAR_CTRL_0_ADDR, (REG_PL_RD(MACDSP_API1_RADAR_CTRL_0_ADDR) & ~((uint32_t)0x0000001C)) | ((uint32_t)mainantsel <<2));
}
__INLINE uint8_t macdsp_api1_radar_ctrl_0_radar_sample_rate_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RADAR_CTRL_0_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void macdsp_api1_radar_ctrl_0_radar_sample_rate_setf(uint8_t radarsamplerate)
{
	ASSERT_ERR((((uint32_t)radarsamplerate << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(MACDSP_API1_RADAR_CTRL_0_ADDR, (REG_PL_RD(MACDSP_API1_RADAR_CTRL_0_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)radarsamplerate <<0));
}

/**
 * @brief LCU_PRE_CONFIG register definition
 *  LCU_PRE_CONFIG register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 PRE_CONFIG                0x0
 * </pre>
 */
#define MACDSP_API1_LCU_PRE_CONFIG_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000900)
#define MACDSP_API1_LCU_PRE_CONFIG_OFFSET      0x00000900
#define MACDSP_API1_LCU_PRE_CONFIG_INDEX       0x00000240
#define MACDSP_API1_LCU_PRE_CONFIG_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_lcu_pre_config_get(void)
{
	return REG_PL_RD(MACDSP_API1_LCU_PRE_CONFIG_ADDR);
}

__INLINE void macdsp_api1_lcu_pre_config_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_LCU_PRE_CONFIG_ADDR, value);
}

// field definitions
#define MACDSP_API1_LCU_PRE_CONFIG_PRE_CONFIG_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_LCU_PRE_CONFIG_PRE_CONFIG_LSB    0
#define MACDSP_API1_LCU_PRE_CONFIG_PRE_CONFIG_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_LCU_PRE_CONFIG_PRE_CONFIG_RST    0x0

__INLINE uint32_t macdsp_api1_lcu_pre_config_pre_config_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LCU_PRE_CONFIG_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_lcu_pre_config_pre_config_setf(uint32_t preconfig)
{
	ASSERT_ERR((((uint32_t)preconfig << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_LCU_PRE_CONFIG_ADDR, (uint32_t)preconfig << 0);
}

/**
 * @brief LCU_PRAM_FOR_TRIGGER register definition
 *  LCU_PRAM_FOR_TRIGGER register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 POFG_PRAM_MODE            0x0
 * </pre>
 */
#define MACDSP_API1_LCU_PRAM_FOR_TRIGGER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000904)
#define MACDSP_API1_LCU_PRAM_FOR_TRIGGER_OFFSET      0x00000904
#define MACDSP_API1_LCU_PRAM_FOR_TRIGGER_INDEX       0x00000241
#define MACDSP_API1_LCU_PRAM_FOR_TRIGGER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_lcu_pram_for_trigger_get(void)
{
	return REG_PL_RD(MACDSP_API1_LCU_PRAM_FOR_TRIGGER_ADDR);
}

__INLINE void macdsp_api1_lcu_pram_for_trigger_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_LCU_PRAM_FOR_TRIGGER_ADDR, value);
}

// field definitions
#define MACDSP_API1_LCU_PRAM_FOR_TRIGGER_POFG_PRAM_MODE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_LCU_PRAM_FOR_TRIGGER_POFG_PRAM_MODE_LSB    0
#define MACDSP_API1_LCU_PRAM_FOR_TRIGGER_POFG_PRAM_MODE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_LCU_PRAM_FOR_TRIGGER_POFG_PRAM_MODE_RST    0x0

__INLINE uint32_t macdsp_api1_lcu_pram_for_trigger_pofg_pram_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LCU_PRAM_FOR_TRIGGER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_lcu_pram_for_trigger_pofg_pram_mode_setf(uint32_t pofgprammode)
{
	ASSERT_ERR((((uint32_t)pofgprammode << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_LCU_PRAM_FOR_TRIGGER_ADDR, (uint32_t)pofgprammode << 0);
}

/**
 * @brief LCU_EVM_DROP_LEVEL register definition
 *  LCU_EVM_DROP_LEVEL register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVM_DROP_LEVEL            0x0
 * </pre>
 */
#define MACDSP_API1_LCU_EVM_DROP_LEVEL_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000908)
#define MACDSP_API1_LCU_EVM_DROP_LEVEL_OFFSET      0x00000908
#define MACDSP_API1_LCU_EVM_DROP_LEVEL_INDEX       0x00000242
#define MACDSP_API1_LCU_EVM_DROP_LEVEL_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_lcu_evm_drop_level_get(void)
{
	return REG_PL_RD(MACDSP_API1_LCU_EVM_DROP_LEVEL_ADDR);
}

__INLINE void macdsp_api1_lcu_evm_drop_level_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_LCU_EVM_DROP_LEVEL_ADDR, value);
}

// field definitions
#define MACDSP_API1_LCU_EVM_DROP_LEVEL_EVM_DROP_LEVEL_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_LCU_EVM_DROP_LEVEL_EVM_DROP_LEVEL_LSB    0
#define MACDSP_API1_LCU_EVM_DROP_LEVEL_EVM_DROP_LEVEL_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_LCU_EVM_DROP_LEVEL_EVM_DROP_LEVEL_RST    0x0

__INLINE uint32_t macdsp_api1_lcu_evm_drop_level_evm_drop_level_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LCU_EVM_DROP_LEVEL_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_lcu_evm_drop_level_evm_drop_level_setf(uint32_t evmdroplevel)
{
	ASSERT_ERR((((uint32_t)evmdroplevel << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_LCU_EVM_DROP_LEVEL_ADDR, (uint32_t)evmdroplevel << 0);
}

/**
 * @brief LCU_H_BUF_USER_NUM register definition
 *  LCU_H_BUF_USER_NUM register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 H_BUF_USER_NUM            0x0
 * </pre>
 */
#define MACDSP_API1_LCU_H_BUF_USER_NUM_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000090C)
#define MACDSP_API1_LCU_H_BUF_USER_NUM_OFFSET      0x0000090C
#define MACDSP_API1_LCU_H_BUF_USER_NUM_INDEX       0x00000243
#define MACDSP_API1_LCU_H_BUF_USER_NUM_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_lcu_h_buf_user_num_get(void)
{
	return REG_PL_RD(MACDSP_API1_LCU_H_BUF_USER_NUM_ADDR);
}

__INLINE void macdsp_api1_lcu_h_buf_user_num_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_LCU_H_BUF_USER_NUM_ADDR, value);
}

// field definitions
#define MACDSP_API1_LCU_H_BUF_USER_NUM_H_BUF_USER_NUM_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_LCU_H_BUF_USER_NUM_H_BUF_USER_NUM_LSB    0
#define MACDSP_API1_LCU_H_BUF_USER_NUM_H_BUF_USER_NUM_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_LCU_H_BUF_USER_NUM_H_BUF_USER_NUM_RST    0x0

__INLINE uint32_t macdsp_api1_lcu_h_buf_user_num_h_buf_user_num_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LCU_H_BUF_USER_NUM_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_lcu_h_buf_user_num_h_buf_user_num_setf(uint32_t hbufusernum)
{
	ASSERT_ERR((((uint32_t)hbufusernum << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_LCU_H_BUF_USER_NUM_ADDR, (uint32_t)hbufusernum << 0);
}

/**
 * @brief LCU_STOP_TRIGGER register definition
 *  LCU_STOP_TRIGGER register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 STOP_TRIGGER              0x0
 * </pre>
 */
#define MACDSP_API1_LCU_STOP_TRIGGER_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000918)
#define MACDSP_API1_LCU_STOP_TRIGGER_OFFSET      0x00000918
#define MACDSP_API1_LCU_STOP_TRIGGER_INDEX       0x00000246
#define MACDSP_API1_LCU_STOP_TRIGGER_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_lcu_stop_trigger_get(void)
{
	return REG_PL_RD(MACDSP_API1_LCU_STOP_TRIGGER_ADDR);
}

__INLINE void macdsp_api1_lcu_stop_trigger_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_LCU_STOP_TRIGGER_ADDR, value);
}

// field definitions
#define MACDSP_API1_LCU_STOP_TRIGGER_STOP_TRIGGER_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_LCU_STOP_TRIGGER_STOP_TRIGGER_LSB    0
#define MACDSP_API1_LCU_STOP_TRIGGER_STOP_TRIGGER_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_LCU_STOP_TRIGGER_STOP_TRIGGER_RST    0x0

__INLINE uint32_t macdsp_api1_lcu_stop_trigger_stop_trigger_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LCU_STOP_TRIGGER_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_lcu_stop_trigger_stop_trigger_setf(uint32_t stoptrigger)
{
	ASSERT_ERR((((uint32_t)stoptrigger << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_LCU_STOP_TRIGGER_ADDR, (uint32_t)stoptrigger << 0);
}

/**
 * @brief AGC_GAIN register definition
 *  Latch_AGC_Gain register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 Agcgain3                  0x0
 *    23:16 Agcgain2                  0x0
 *    15:08 Agcgain1                  0x0
 *    07:00 Agcgain0                  0x0
 * </pre>
 */
#define MACDSP_API1_AGC_GAIN_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000968)
#define MACDSP_API1_AGC_GAIN_OFFSET      0x00000968
#define MACDSP_API1_AGC_GAIN_INDEX       0x0000025A
#define MACDSP_API1_AGC_GAIN_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_agc_gain_get(void)
{
	return REG_PL_RD(MACDSP_API1_AGC_GAIN_ADDR);
}

__INLINE void macdsp_api1_agc_gain_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_AGC_GAIN_ADDR, value);
}

// field definitions
#define MACDSP_API1_AGC_GAIN_AGCGAIN_3_MASK    ((uint32_t)0xFF000000)
#define MACDSP_API1_AGC_GAIN_AGCGAIN_3_LSB    24
#define MACDSP_API1_AGC_GAIN_AGCGAIN_3_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_AGC_GAIN_AGCGAIN_2_MASK    ((uint32_t)0x00FF0000)
#define MACDSP_API1_AGC_GAIN_AGCGAIN_2_LSB    16
#define MACDSP_API1_AGC_GAIN_AGCGAIN_2_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_AGC_GAIN_AGCGAIN_1_MASK    ((uint32_t)0x0000FF00)
#define MACDSP_API1_AGC_GAIN_AGCGAIN_1_LSB    8
#define MACDSP_API1_AGC_GAIN_AGCGAIN_1_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_AGC_GAIN_AGCGAIN_0_MASK    ((uint32_t)0x000000FF)
#define MACDSP_API1_AGC_GAIN_AGCGAIN_0_LSB    0
#define MACDSP_API1_AGC_GAIN_AGCGAIN_0_WIDTH    ((uint32_t)0x00000008)

#define MACDSP_API1_AGC_GAIN_AGCGAIN_3_RST    0x0
#define MACDSP_API1_AGC_GAIN_AGCGAIN_2_RST    0x0
#define MACDSP_API1_AGC_GAIN_AGCGAIN_1_RST    0x0
#define MACDSP_API1_AGC_GAIN_AGCGAIN_0_RST    0x0

__INLINE void macdsp_api1_agc_gain_pack(uint8_t agcgain3, uint8_t agcgain2, uint8_t agcgain1, uint8_t agcgain0)
{
	ASSERT_ERR((((uint32_t)agcgain3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)agcgain2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)agcgain1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)agcgain0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_AGC_GAIN_ADDR,  ((uint32_t)agcgain3 << 24) |((uint32_t)agcgain2 << 16) |((uint32_t)agcgain1 << 8) |((uint32_t)agcgain0 << 0));
}

__INLINE void macdsp_api1_agc_gain_unpack(uint8_t* agcgain3, uint8_t* agcgain2, uint8_t* agcgain1, uint8_t* agcgain0)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_AGC_GAIN_ADDR);

	*agcgain3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*agcgain2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*agcgain1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*agcgain0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t macdsp_api1_agc_gain_agcgain_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_AGC_GAIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void macdsp_api1_agc_gain_agcgain_3_setf(uint8_t agcgain3)
{
	ASSERT_ERR((((uint32_t)agcgain3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(MACDSP_API1_AGC_GAIN_ADDR, (REG_PL_RD(MACDSP_API1_AGC_GAIN_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)agcgain3 <<24));
}
__INLINE uint8_t macdsp_api1_agc_gain_agcgain_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_AGC_GAIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void macdsp_api1_agc_gain_agcgain_2_setf(uint8_t agcgain2)
{
	ASSERT_ERR((((uint32_t)agcgain2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(MACDSP_API1_AGC_GAIN_ADDR, (REG_PL_RD(MACDSP_API1_AGC_GAIN_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)agcgain2 <<16));
}
__INLINE uint8_t macdsp_api1_agc_gain_agcgain_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_AGC_GAIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void macdsp_api1_agc_gain_agcgain_1_setf(uint8_t agcgain1)
{
	ASSERT_ERR((((uint32_t)agcgain1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(MACDSP_API1_AGC_GAIN_ADDR, (REG_PL_RD(MACDSP_API1_AGC_GAIN_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)agcgain1 <<8));
}
__INLINE uint8_t macdsp_api1_agc_gain_agcgain_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_AGC_GAIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void macdsp_api1_agc_gain_agcgain_0_setf(uint8_t agcgain0)
{
	ASSERT_ERR((((uint32_t)agcgain0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_AGC_GAIN_ADDR, (REG_PL_RD(MACDSP_API1_AGC_GAIN_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)agcgain0 <<0));
}

/**
 * @brief LNA_VGA_0_2 register definition
 *  Latch_LNA_VGA_Gains_Ants_0_2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28    Agcrfgain2_Extlna         0              
 *    27:25 Agcrfgain2_Lna            0x0
 *    24:20 Agcrfgain2_Vga            0x0
 *    18    Agcrfgain1_Extlna         0              
 *    17:15 Agcrfgain1_Lna            0x0
 *    14:10 Agcrfgain1_Vga            0x0
 *    08    Agcrfgain0_Extlna         0              
 *    07:05 Agcrfgain0_Lna            0x0
 *    04:00 Agcrfgain0_Vga            0x0
 * </pre>
 */
#define MACDSP_API1_LNA_VGA_0_2_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000096C)
#define MACDSP_API1_LNA_VGA_0_2_OFFSET      0x0000096C
#define MACDSP_API1_LNA_VGA_0_2_INDEX       0x0000025B
#define MACDSP_API1_LNA_VGA_0_2_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_lna_vga_0_2_get(void)
{
	return REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR);
}

__INLINE void macdsp_api1_lna_vga_0_2_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_LNA_VGA_0_2_ADDR, value);
}

// field definitions
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_2_EXTLNA_BIT    ((uint32_t)0x10000000)
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_2_EXTLNA_POS    28
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_2_LNA_MASK    ((uint32_t)0x0E000000)
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_2_LNA_LSB    25
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_2_LNA_WIDTH    ((uint32_t)0x00000003)
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_2_VGA_MASK    ((uint32_t)0x01F00000)
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_2_VGA_LSB    20
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_2_VGA_WIDTH    ((uint32_t)0x00000005)
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_1_EXTLNA_BIT    ((uint32_t)0x00040000)
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_1_EXTLNA_POS    18
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_1_LNA_MASK    ((uint32_t)0x00038000)
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_1_LNA_LSB    15
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_1_LNA_WIDTH    ((uint32_t)0x00000003)
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_1_VGA_MASK    ((uint32_t)0x00007C00)
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_1_VGA_LSB    10
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_1_VGA_WIDTH    ((uint32_t)0x00000005)
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_0_EXTLNA_BIT    ((uint32_t)0x00000100)
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_0_EXTLNA_POS    8
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_0_LNA_MASK    ((uint32_t)0x000000E0)
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_0_LNA_LSB    5
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_0_LNA_WIDTH    ((uint32_t)0x00000003)
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_0_VGA_MASK    ((uint32_t)0x0000001F)
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_0_VGA_LSB    0
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_0_VGA_WIDTH    ((uint32_t)0x00000005)

#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_2_EXTLNA_RST    0x0
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_2_LNA_RST    0x0
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_2_VGA_RST    0x0
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_1_EXTLNA_RST    0x0
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_1_LNA_RST    0x0
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_1_VGA_RST    0x0
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_0_EXTLNA_RST    0x0
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_0_LNA_RST    0x0
#define MACDSP_API1_LNA_VGA_0_2_AGCRFGAIN_0_VGA_RST    0x0

__INLINE void macdsp_api1_lna_vga_0_2_pack(uint8_t agcrfgain2_extlna, uint8_t agcrfgain2_lna, uint8_t agcrfgain2_vga, uint8_t agcrfgain1_extlna, uint8_t agcrfgain1_lna, uint8_t agcrfgain1_vga, uint8_t agcrfgain0_extlna, uint8_t agcrfgain0_lna, uint8_t agcrfgain0_vga)
{
	ASSERT_ERR((((uint32_t)agcrfgain2_extlna << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)agcrfgain2_lna << 25) & ~((uint32_t)0x0E000000)) == 0);
	ASSERT_ERR((((uint32_t)agcrfgain2_vga << 20) & ~((uint32_t)0x01F00000)) == 0);
	ASSERT_ERR((((uint32_t)agcrfgain1_extlna << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)agcrfgain1_lna << 15) & ~((uint32_t)0x00038000)) == 0);
	ASSERT_ERR((((uint32_t)agcrfgain1_vga << 10) & ~((uint32_t)0x00007C00)) == 0);
	ASSERT_ERR((((uint32_t)agcrfgain0_extlna << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)agcrfgain0_lna << 5) & ~((uint32_t)0x000000E0)) == 0);
	ASSERT_ERR((((uint32_t)agcrfgain0_vga << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_0_2_ADDR,  ((uint32_t)agcrfgain2_extlna << 28) |((uint32_t)agcrfgain2_lna << 25) |((uint32_t)agcrfgain2_vga << 20) |((uint32_t)agcrfgain1_extlna << 18) |((uint32_t)agcrfgain1_lna << 15) |((uint32_t)agcrfgain1_vga << 10) |((uint32_t)agcrfgain0_extlna << 8) |((uint32_t)agcrfgain0_lna << 5) |((uint32_t)agcrfgain0_vga << 0));
}

__INLINE void macdsp_api1_lna_vga_0_2_unpack(uint8_t* agcrfgain2_extlna, uint8_t* agcrfgain2_lna, uint8_t* agcrfgain2_vga, uint8_t* agcrfgain1_extlna, uint8_t* agcrfgain1_lna, uint8_t* agcrfgain1_vga, uint8_t* agcrfgain0_extlna, uint8_t* agcrfgain0_lna, uint8_t* agcrfgain0_vga)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR);

	*agcrfgain2_extlna = (localVal & ((uint32_t)0x10000000)) >>  28;
	*agcrfgain2_lna = (localVal & ((uint32_t)0x0E000000)) >>  25;
	*agcrfgain2_vga = (localVal & ((uint32_t)0x01F00000)) >>  20;
	*agcrfgain1_extlna = (localVal & ((uint32_t)0x00040000)) >>  18;
	*agcrfgain1_lna = (localVal & ((uint32_t)0x00038000)) >>  15;
	*agcrfgain1_vga = (localVal & ((uint32_t)0x00007C00)) >>  10;
	*agcrfgain0_extlna = (localVal & ((uint32_t)0x00000100)) >>  8;
	*agcrfgain0_lna = (localVal & ((uint32_t)0x000000E0)) >>  5;
	*agcrfgain0_vga = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t macdsp_api1_lna_vga_0_2_agcrfgain_2_extlna_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE void macdsp_api1_lna_vga_0_2_agcrfgain_2_extlna_setf(uint8_t agcrfgain2extlna)
{
	ASSERT_ERR((((uint32_t)agcrfgain2extlna << 28) & ~((uint32_t)0x10000000)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_0_2_ADDR, (REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)agcrfgain2extlna <<28));
}
__INLINE uint8_t macdsp_api1_lna_vga_0_2_agcrfgain_2_lna_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0E000000)) >> 25);
}
__INLINE void macdsp_api1_lna_vga_0_2_agcrfgain_2_lna_setf(uint8_t agcrfgain2lna)
{
	ASSERT_ERR((((uint32_t)agcrfgain2lna << 25) & ~((uint32_t)0x0E000000)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_0_2_ADDR, (REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR) & ~((uint32_t)0x0E000000)) | ((uint32_t)agcrfgain2lna <<25));
}
__INLINE uint8_t macdsp_api1_lna_vga_0_2_agcrfgain_2_vga_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01F00000)) >> 20);
}
__INLINE void macdsp_api1_lna_vga_0_2_agcrfgain_2_vga_setf(uint8_t agcrfgain2vga)
{
	ASSERT_ERR((((uint32_t)agcrfgain2vga << 20) & ~((uint32_t)0x01F00000)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_0_2_ADDR, (REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR) & ~((uint32_t)0x01F00000)) | ((uint32_t)agcrfgain2vga <<20));
}
__INLINE uint8_t macdsp_api1_lna_vga_0_2_agcrfgain_1_extlna_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void macdsp_api1_lna_vga_0_2_agcrfgain_1_extlna_setf(uint8_t agcrfgain1extlna)
{
	ASSERT_ERR((((uint32_t)agcrfgain1extlna << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_0_2_ADDR, (REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)agcrfgain1extlna <<18));
}
__INLINE uint8_t macdsp_api1_lna_vga_0_2_agcrfgain_1_lna_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00038000)) >> 15);
}
__INLINE void macdsp_api1_lna_vga_0_2_agcrfgain_1_lna_setf(uint8_t agcrfgain1lna)
{
	ASSERT_ERR((((uint32_t)agcrfgain1lna << 15) & ~((uint32_t)0x00038000)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_0_2_ADDR, (REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR) & ~((uint32_t)0x00038000)) | ((uint32_t)agcrfgain1lna <<15));
}
__INLINE uint8_t macdsp_api1_lna_vga_0_2_agcrfgain_1_vga_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007C00)) >> 10);
}
__INLINE void macdsp_api1_lna_vga_0_2_agcrfgain_1_vga_setf(uint8_t agcrfgain1vga)
{
	ASSERT_ERR((((uint32_t)agcrfgain1vga << 10) & ~((uint32_t)0x00007C00)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_0_2_ADDR, (REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR) & ~((uint32_t)0x00007C00)) | ((uint32_t)agcrfgain1vga <<10));
}
__INLINE uint8_t macdsp_api1_lna_vga_0_2_agcrfgain_0_extlna_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void macdsp_api1_lna_vga_0_2_agcrfgain_0_extlna_setf(uint8_t agcrfgain0extlna)
{
	ASSERT_ERR((((uint32_t)agcrfgain0extlna << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_0_2_ADDR, (REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)agcrfgain0extlna <<8));
}
__INLINE uint8_t macdsp_api1_lna_vga_0_2_agcrfgain_0_lna_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000E0)) >> 5);
}
__INLINE void macdsp_api1_lna_vga_0_2_agcrfgain_0_lna_setf(uint8_t agcrfgain0lna)
{
	ASSERT_ERR((((uint32_t)agcrfgain0lna << 5) & ~((uint32_t)0x000000E0)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_0_2_ADDR, (REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR) & ~((uint32_t)0x000000E0)) | ((uint32_t)agcrfgain0lna <<5));
}
__INLINE uint8_t macdsp_api1_lna_vga_0_2_agcrfgain_0_vga_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void macdsp_api1_lna_vga_0_2_agcrfgain_0_vga_setf(uint8_t agcrfgain0vga)
{
	ASSERT_ERR((((uint32_t)agcrfgain0vga << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_0_2_ADDR, (REG_PL_RD(MACDSP_API1_LNA_VGA_0_2_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)agcrfgain0vga <<0));
}

/**
 * @brief ADC_POW register definition
 *  Latch_ADC_Power register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:24 Adcpowdbv3                0x0
 *    22:16 Adcpowdbv2                0x0
 *    14:08 Adcpowdbv1                0x0
 *    06:00 Adcpowdbv0                0x0
 * </pre>
 */
#define MACDSP_API1_ADC_POW_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000970)
#define MACDSP_API1_ADC_POW_OFFSET      0x00000970
#define MACDSP_API1_ADC_POW_INDEX       0x0000025C
#define MACDSP_API1_ADC_POW_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_adc_pow_get(void)
{
	return REG_PL_RD(MACDSP_API1_ADC_POW_ADDR);
}

__INLINE void macdsp_api1_adc_pow_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_ADC_POW_ADDR, value);
}

// field definitions
#define MACDSP_API1_ADC_POW_ADCPOWDBV_3_MASK    ((uint32_t)0x7F000000)
#define MACDSP_API1_ADC_POW_ADCPOWDBV_3_LSB    24
#define MACDSP_API1_ADC_POW_ADCPOWDBV_3_WIDTH    ((uint32_t)0x00000007)
#define MACDSP_API1_ADC_POW_ADCPOWDBV_2_MASK    ((uint32_t)0x007F0000)
#define MACDSP_API1_ADC_POW_ADCPOWDBV_2_LSB    16
#define MACDSP_API1_ADC_POW_ADCPOWDBV_2_WIDTH    ((uint32_t)0x00000007)
#define MACDSP_API1_ADC_POW_ADCPOWDBV_1_MASK    ((uint32_t)0x00007F00)
#define MACDSP_API1_ADC_POW_ADCPOWDBV_1_LSB    8
#define MACDSP_API1_ADC_POW_ADCPOWDBV_1_WIDTH    ((uint32_t)0x00000007)
#define MACDSP_API1_ADC_POW_ADCPOWDBV_0_MASK    ((uint32_t)0x0000007F)
#define MACDSP_API1_ADC_POW_ADCPOWDBV_0_LSB    0
#define MACDSP_API1_ADC_POW_ADCPOWDBV_0_WIDTH    ((uint32_t)0x00000007)

#define MACDSP_API1_ADC_POW_ADCPOWDBV_3_RST    0x0
#define MACDSP_API1_ADC_POW_ADCPOWDBV_2_RST    0x0
#define MACDSP_API1_ADC_POW_ADCPOWDBV_1_RST    0x0
#define MACDSP_API1_ADC_POW_ADCPOWDBV_0_RST    0x0

__INLINE void macdsp_api1_adc_pow_pack(uint8_t adcpowdbv3, uint8_t adcpowdbv2, uint8_t adcpowdbv1, uint8_t adcpowdbv0)
{
	ASSERT_ERR((((uint32_t)adcpowdbv3 << 24) & ~((uint32_t)0x7F000000)) == 0);
	ASSERT_ERR((((uint32_t)adcpowdbv2 << 16) & ~((uint32_t)0x007F0000)) == 0);
	ASSERT_ERR((((uint32_t)adcpowdbv1 << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)adcpowdbv0 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(MACDSP_API1_ADC_POW_ADDR,  ((uint32_t)adcpowdbv3 << 24) |((uint32_t)adcpowdbv2 << 16) |((uint32_t)adcpowdbv1 << 8) |((uint32_t)adcpowdbv0 << 0));
}

__INLINE void macdsp_api1_adc_pow_unpack(uint8_t* adcpowdbv3, uint8_t* adcpowdbv2, uint8_t* adcpowdbv1, uint8_t* adcpowdbv0)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_ADC_POW_ADDR);

	*adcpowdbv3 = (localVal & ((uint32_t)0x7F000000)) >>  24;
	*adcpowdbv2 = (localVal & ((uint32_t)0x007F0000)) >>  16;
	*adcpowdbv1 = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*adcpowdbv0 = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint8_t macdsp_api1_adc_pow_adcpowdbv_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_ADC_POW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x7F000000)) >> 24);
}
__INLINE void macdsp_api1_adc_pow_adcpowdbv_3_setf(uint8_t adcpowdbv3)
{
	ASSERT_ERR((((uint32_t)adcpowdbv3 << 24) & ~((uint32_t)0x7F000000)) == 0);
	REG_PL_WR(MACDSP_API1_ADC_POW_ADDR, (REG_PL_RD(MACDSP_API1_ADC_POW_ADDR) & ~((uint32_t)0x7F000000)) | ((uint32_t)adcpowdbv3 <<24));
}
__INLINE uint8_t macdsp_api1_adc_pow_adcpowdbv_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_ADC_POW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x007F0000)) >> 16);
}
__INLINE void macdsp_api1_adc_pow_adcpowdbv_2_setf(uint8_t adcpowdbv2)
{
	ASSERT_ERR((((uint32_t)adcpowdbv2 << 16) & ~((uint32_t)0x007F0000)) == 0);
	REG_PL_WR(MACDSP_API1_ADC_POW_ADDR, (REG_PL_RD(MACDSP_API1_ADC_POW_ADDR) & ~((uint32_t)0x007F0000)) | ((uint32_t)adcpowdbv2 <<16));
}
__INLINE uint8_t macdsp_api1_adc_pow_adcpowdbv_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_ADC_POW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void macdsp_api1_adc_pow_adcpowdbv_1_setf(uint8_t adcpowdbv1)
{
	ASSERT_ERR((((uint32_t)adcpowdbv1 << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(MACDSP_API1_ADC_POW_ADDR, (REG_PL_RD(MACDSP_API1_ADC_POW_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)adcpowdbv1 <<8));
}
__INLINE uint8_t macdsp_api1_adc_pow_adcpowdbv_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_ADC_POW_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}
__INLINE void macdsp_api1_adc_pow_adcpowdbv_0_setf(uint8_t adcpowdbv0)
{
	ASSERT_ERR((((uint32_t)adcpowdbv0 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(MACDSP_API1_ADC_POW_ADDR, (REG_PL_RD(MACDSP_API1_ADC_POW_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)adcpowdbv0 <<0));
}

/**
 * @brief INBDPOW_20 register definition
 *  Latch_InBand20p register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 Inbdpow20_Pdbm3           0x0
 *    23:16 Inbdpow20_Pdbm2           0x0
 *    15:08 Inbdpow20_Pdbm1           0x0
 *    07:00 Inbdpow20_Pdbm0           0x0
 * </pre>
 */
#define MACDSP_API1_INBDPOW_20_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000974)
#define MACDSP_API1_INBDPOW_20_OFFSET      0x00000974
#define MACDSP_API1_INBDPOW_20_INDEX       0x0000025D
#define MACDSP_API1_INBDPOW_20_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_inbdpow_20_get(void)
{
	return REG_PL_RD(MACDSP_API1_INBDPOW_20_ADDR);
}

__INLINE void macdsp_api1_inbdpow_20_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_INBDPOW_20_ADDR, value);
}

// field definitions
#define MACDSP_API1_INBDPOW_20_INBDPOW_20_PDBM_3_MASK    ((uint32_t)0xFF000000)
#define MACDSP_API1_INBDPOW_20_INBDPOW_20_PDBM_3_LSB    24
#define MACDSP_API1_INBDPOW_20_INBDPOW_20_PDBM_3_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_INBDPOW_20_INBDPOW_20_PDBM_2_MASK    ((uint32_t)0x00FF0000)
#define MACDSP_API1_INBDPOW_20_INBDPOW_20_PDBM_2_LSB    16
#define MACDSP_API1_INBDPOW_20_INBDPOW_20_PDBM_2_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_INBDPOW_20_INBDPOW_20_PDBM_1_MASK    ((uint32_t)0x0000FF00)
#define MACDSP_API1_INBDPOW_20_INBDPOW_20_PDBM_1_LSB    8
#define MACDSP_API1_INBDPOW_20_INBDPOW_20_PDBM_1_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_INBDPOW_20_INBDPOW_20_PDBM_0_MASK    ((uint32_t)0x000000FF)
#define MACDSP_API1_INBDPOW_20_INBDPOW_20_PDBM_0_LSB    0
#define MACDSP_API1_INBDPOW_20_INBDPOW_20_PDBM_0_WIDTH    ((uint32_t)0x00000008)

#define MACDSP_API1_INBDPOW_20_INBDPOW_20_PDBM_3_RST    0x0
#define MACDSP_API1_INBDPOW_20_INBDPOW_20_PDBM_2_RST    0x0
#define MACDSP_API1_INBDPOW_20_INBDPOW_20_PDBM_1_RST    0x0
#define MACDSP_API1_INBDPOW_20_INBDPOW_20_PDBM_0_RST    0x0

__INLINE void macdsp_api1_inbdpow_20_pack(uint8_t inbdpow20_pdbm3, uint8_t inbdpow20_pdbm2, uint8_t inbdpow20_pdbm1, uint8_t inbdpow20_pdbm0)
{
	ASSERT_ERR((((uint32_t)inbdpow20_pdbm3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	ASSERT_ERR((((uint32_t)inbdpow20_pdbm2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	ASSERT_ERR((((uint32_t)inbdpow20_pdbm1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)inbdpow20_pdbm0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_INBDPOW_20_ADDR,  ((uint32_t)inbdpow20_pdbm3 << 24) |((uint32_t)inbdpow20_pdbm2 << 16) |((uint32_t)inbdpow20_pdbm1 << 8) |((uint32_t)inbdpow20_pdbm0 << 0));
}

__INLINE void macdsp_api1_inbdpow_20_unpack(uint8_t* inbdpow20_pdbm3, uint8_t* inbdpow20_pdbm2, uint8_t* inbdpow20_pdbm1, uint8_t* inbdpow20_pdbm0)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_INBDPOW_20_ADDR);

	*inbdpow20_pdbm3 = (localVal & ((uint32_t)0xFF000000)) >>  24;
	*inbdpow20_pdbm2 = (localVal & ((uint32_t)0x00FF0000)) >>  16;
	*inbdpow20_pdbm1 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*inbdpow20_pdbm0 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t macdsp_api1_inbdpow_20_inbdpow_20_pdbm_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_INBDPOW_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0xFF000000)) >> 24);
}
__INLINE void macdsp_api1_inbdpow_20_inbdpow_20_pdbm_3_setf(uint8_t inbdpow20pdbm3)
{
	ASSERT_ERR((((uint32_t)inbdpow20pdbm3 << 24) & ~((uint32_t)0xFF000000)) == 0);
	REG_PL_WR(MACDSP_API1_INBDPOW_20_ADDR, (REG_PL_RD(MACDSP_API1_INBDPOW_20_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)inbdpow20pdbm3 <<24));
}
__INLINE uint8_t macdsp_api1_inbdpow_20_inbdpow_20_pdbm_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_INBDPOW_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00FF0000)) >> 16);
}
__INLINE void macdsp_api1_inbdpow_20_inbdpow_20_pdbm_2_setf(uint8_t inbdpow20pdbm2)
{
	ASSERT_ERR((((uint32_t)inbdpow20pdbm2 << 16) & ~((uint32_t)0x00FF0000)) == 0);
	REG_PL_WR(MACDSP_API1_INBDPOW_20_ADDR, (REG_PL_RD(MACDSP_API1_INBDPOW_20_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)inbdpow20pdbm2 <<16));
}
__INLINE uint8_t macdsp_api1_inbdpow_20_inbdpow_20_pdbm_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_INBDPOW_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void macdsp_api1_inbdpow_20_inbdpow_20_pdbm_1_setf(uint8_t inbdpow20pdbm1)
{
	ASSERT_ERR((((uint32_t)inbdpow20pdbm1 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(MACDSP_API1_INBDPOW_20_ADDR, (REG_PL_RD(MACDSP_API1_INBDPOW_20_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)inbdpow20pdbm1 <<8));
}
__INLINE uint8_t macdsp_api1_inbdpow_20_inbdpow_20_pdbm_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_INBDPOW_20_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void macdsp_api1_inbdpow_20_inbdpow_20_pdbm_0_setf(uint8_t inbdpow20pdbm0)
{
	ASSERT_ERR((((uint32_t)inbdpow20pdbm0 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_INBDPOW_20_ADDR, (REG_PL_RD(MACDSP_API1_INBDPOW_20_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)inbdpow20pdbm0 <<0));
}

/**
 * @brief LNA_VGA_3_5 register definition
 *  Latch_LNA_VGA_Gains_Ants_3_5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    28    Agcrfgain5_Extlna         0              
 *    27:25 Agcrfgain5_Lna            0x0
 *    24:20 Agcrfgain5_Vga            0x0
 *    18    Agcrfgain4_Extlna         0              
 *    17:15 Agcrfgain4_Lna            0x0
 *    14:10 Agcrfgain4_Vga            0x0
 *    08    Agcrfgain3_Extlna         0              
 *    07:05 Agcrfgain3_Lna            0x0
 *    04:00 Agcrfgain3_Vga            0x0
 * </pre>
 */
#define MACDSP_API1_LNA_VGA_3_5_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000978)
#define MACDSP_API1_LNA_VGA_3_5_OFFSET      0x00000978
#define MACDSP_API1_LNA_VGA_3_5_INDEX       0x0000025E
#define MACDSP_API1_LNA_VGA_3_5_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_lna_vga_3_5_get(void)
{
	return REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR);
}

__INLINE void macdsp_api1_lna_vga_3_5_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_LNA_VGA_3_5_ADDR, value);
}

// field definitions
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_5_EXTLNA_BIT    ((uint32_t)0x10000000)
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_5_EXTLNA_POS    28
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_5_LNA_MASK    ((uint32_t)0x0E000000)
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_5_LNA_LSB    25
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_5_LNA_WIDTH    ((uint32_t)0x00000003)
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_5_VGA_MASK    ((uint32_t)0x01F00000)
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_5_VGA_LSB    20
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_5_VGA_WIDTH    ((uint32_t)0x00000005)
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_4_EXTLNA_BIT    ((uint32_t)0x00040000)
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_4_EXTLNA_POS    18
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_4_LNA_MASK    ((uint32_t)0x00038000)
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_4_LNA_LSB    15
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_4_LNA_WIDTH    ((uint32_t)0x00000003)
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_4_VGA_MASK    ((uint32_t)0x00007C00)
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_4_VGA_LSB    10
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_4_VGA_WIDTH    ((uint32_t)0x00000005)
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_3_EXTLNA_BIT    ((uint32_t)0x00000100)
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_3_EXTLNA_POS    8
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_3_LNA_MASK    ((uint32_t)0x000000E0)
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_3_LNA_LSB    5
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_3_LNA_WIDTH    ((uint32_t)0x00000003)
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_3_VGA_MASK    ((uint32_t)0x0000001F)
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_3_VGA_LSB    0
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_3_VGA_WIDTH    ((uint32_t)0x00000005)

#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_5_EXTLNA_RST    0x0
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_5_LNA_RST    0x0
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_5_VGA_RST    0x0
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_4_EXTLNA_RST    0x0
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_4_LNA_RST    0x0
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_4_VGA_RST    0x0
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_3_EXTLNA_RST    0x0
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_3_LNA_RST    0x0
#define MACDSP_API1_LNA_VGA_3_5_AGCRFGAIN_3_VGA_RST    0x0

__INLINE void macdsp_api1_lna_vga_3_5_pack(uint8_t agcrfgain5_extlna, uint8_t agcrfgain5_lna, uint8_t agcrfgain5_vga, uint8_t agcrfgain4_extlna, uint8_t agcrfgain4_lna, uint8_t agcrfgain4_vga, uint8_t agcrfgain3_extlna, uint8_t agcrfgain3_lna, uint8_t agcrfgain3_vga)
{
	ASSERT_ERR((((uint32_t)agcrfgain5_extlna << 28) & ~((uint32_t)0x10000000)) == 0);
	ASSERT_ERR((((uint32_t)agcrfgain5_lna << 25) & ~((uint32_t)0x0E000000)) == 0);
	ASSERT_ERR((((uint32_t)agcrfgain5_vga << 20) & ~((uint32_t)0x01F00000)) == 0);
	ASSERT_ERR((((uint32_t)agcrfgain4_extlna << 18) & ~((uint32_t)0x00040000)) == 0);
	ASSERT_ERR((((uint32_t)agcrfgain4_lna << 15) & ~((uint32_t)0x00038000)) == 0);
	ASSERT_ERR((((uint32_t)agcrfgain4_vga << 10) & ~((uint32_t)0x00007C00)) == 0);
	ASSERT_ERR((((uint32_t)agcrfgain3_extlna << 8) & ~((uint32_t)0x00000100)) == 0);
	ASSERT_ERR((((uint32_t)agcrfgain3_lna << 5) & ~((uint32_t)0x000000E0)) == 0);
	ASSERT_ERR((((uint32_t)agcrfgain3_vga << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_3_5_ADDR,  ((uint32_t)agcrfgain5_extlna << 28) |((uint32_t)agcrfgain5_lna << 25) |((uint32_t)agcrfgain5_vga << 20) |((uint32_t)agcrfgain4_extlna << 18) |((uint32_t)agcrfgain4_lna << 15) |((uint32_t)agcrfgain4_vga << 10) |((uint32_t)agcrfgain3_extlna << 8) |((uint32_t)agcrfgain3_lna << 5) |((uint32_t)agcrfgain3_vga << 0));
}

__INLINE void macdsp_api1_lna_vga_3_5_unpack(uint8_t* agcrfgain5_extlna, uint8_t* agcrfgain5_lna, uint8_t* agcrfgain5_vga, uint8_t* agcrfgain4_extlna, uint8_t* agcrfgain4_lna, uint8_t* agcrfgain4_vga, uint8_t* agcrfgain3_extlna, uint8_t* agcrfgain3_lna, uint8_t* agcrfgain3_vga)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR);

	*agcrfgain5_extlna = (localVal & ((uint32_t)0x10000000)) >>  28;
	*agcrfgain5_lna = (localVal & ((uint32_t)0x0E000000)) >>  25;
	*agcrfgain5_vga = (localVal & ((uint32_t)0x01F00000)) >>  20;
	*agcrfgain4_extlna = (localVal & ((uint32_t)0x00040000)) >>  18;
	*agcrfgain4_lna = (localVal & ((uint32_t)0x00038000)) >>  15;
	*agcrfgain4_vga = (localVal & ((uint32_t)0x00007C00)) >>  10;
	*agcrfgain3_extlna = (localVal & ((uint32_t)0x00000100)) >>  8;
	*agcrfgain3_lna = (localVal & ((uint32_t)0x000000E0)) >>  5;
	*agcrfgain3_vga = (localVal & ((uint32_t)0x0000001F)) >>  0;
}

__INLINE uint8_t macdsp_api1_lna_vga_3_5_agcrfgain_5_extlna_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x10000000)) >> 28);
}
__INLINE void macdsp_api1_lna_vga_3_5_agcrfgain_5_extlna_setf(uint8_t agcrfgain5extlna)
{
	ASSERT_ERR((((uint32_t)agcrfgain5extlna << 28) & ~((uint32_t)0x10000000)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_3_5_ADDR, (REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR) & ~((uint32_t)0x10000000)) | ((uint32_t)agcrfgain5extlna <<28));
}
__INLINE uint8_t macdsp_api1_lna_vga_3_5_agcrfgain_5_lna_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0E000000)) >> 25);
}
__INLINE void macdsp_api1_lna_vga_3_5_agcrfgain_5_lna_setf(uint8_t agcrfgain5lna)
{
	ASSERT_ERR((((uint32_t)agcrfgain5lna << 25) & ~((uint32_t)0x0E000000)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_3_5_ADDR, (REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR) & ~((uint32_t)0x0E000000)) | ((uint32_t)agcrfgain5lna <<25));
}
__INLINE uint8_t macdsp_api1_lna_vga_3_5_agcrfgain_5_vga_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x01F00000)) >> 20);
}
__INLINE void macdsp_api1_lna_vga_3_5_agcrfgain_5_vga_setf(uint8_t agcrfgain5vga)
{
	ASSERT_ERR((((uint32_t)agcrfgain5vga << 20) & ~((uint32_t)0x01F00000)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_3_5_ADDR, (REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR) & ~((uint32_t)0x01F00000)) | ((uint32_t)agcrfgain5vga <<20));
}
__INLINE uint8_t macdsp_api1_lna_vga_3_5_agcrfgain_4_extlna_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00040000)) >> 18);
}
__INLINE void macdsp_api1_lna_vga_3_5_agcrfgain_4_extlna_setf(uint8_t agcrfgain4extlna)
{
	ASSERT_ERR((((uint32_t)agcrfgain4extlna << 18) & ~((uint32_t)0x00040000)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_3_5_ADDR, (REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR) & ~((uint32_t)0x00040000)) | ((uint32_t)agcrfgain4extlna <<18));
}
__INLINE uint8_t macdsp_api1_lna_vga_3_5_agcrfgain_4_lna_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00038000)) >> 15);
}
__INLINE void macdsp_api1_lna_vga_3_5_agcrfgain_4_lna_setf(uint8_t agcrfgain4lna)
{
	ASSERT_ERR((((uint32_t)agcrfgain4lna << 15) & ~((uint32_t)0x00038000)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_3_5_ADDR, (REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR) & ~((uint32_t)0x00038000)) | ((uint32_t)agcrfgain4lna <<15));
}
__INLINE uint8_t macdsp_api1_lna_vga_3_5_agcrfgain_4_vga_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007C00)) >> 10);
}
__INLINE void macdsp_api1_lna_vga_3_5_agcrfgain_4_vga_setf(uint8_t agcrfgain4vga)
{
	ASSERT_ERR((((uint32_t)agcrfgain4vga << 10) & ~((uint32_t)0x00007C00)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_3_5_ADDR, (REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR) & ~((uint32_t)0x00007C00)) | ((uint32_t)agcrfgain4vga <<10));
}
__INLINE uint8_t macdsp_api1_lna_vga_3_5_agcrfgain_3_extlna_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000100)) >> 8);
}
__INLINE void macdsp_api1_lna_vga_3_5_agcrfgain_3_extlna_setf(uint8_t agcrfgain3extlna)
{
	ASSERT_ERR((((uint32_t)agcrfgain3extlna << 8) & ~((uint32_t)0x00000100)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_3_5_ADDR, (REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)agcrfgain3extlna <<8));
}
__INLINE uint8_t macdsp_api1_lna_vga_3_5_agcrfgain_3_lna_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000E0)) >> 5);
}
__INLINE void macdsp_api1_lna_vga_3_5_agcrfgain_3_lna_setf(uint8_t agcrfgain3lna)
{
	ASSERT_ERR((((uint32_t)agcrfgain3lna << 5) & ~((uint32_t)0x000000E0)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_3_5_ADDR, (REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR) & ~((uint32_t)0x000000E0)) | ((uint32_t)agcrfgain3lna <<5));
}
__INLINE uint8_t macdsp_api1_lna_vga_3_5_agcrfgain_3_vga_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000001F)) >> 0);
}
__INLINE void macdsp_api1_lna_vga_3_5_agcrfgain_3_vga_setf(uint8_t agcrfgain3vga)
{
	ASSERT_ERR((((uint32_t)agcrfgain3vga << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(MACDSP_API1_LNA_VGA_3_5_ADDR, (REG_PL_RD(MACDSP_API1_LNA_VGA_3_5_ADDR) & ~((uint32_t)0x0000001F)) | ((uint32_t)agcrfgain3vga <<0));
}

/**
 * @brief DIG_GAIN register definition
 *  Latch_Digital_Gain register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    30:24 Diggain20_Ant3            0x0
 *    22:16 Diggain20_Ant2            0x0
 *    14:08 Diggain20_Ant1            0x0
 *    06:00 Diggain20_Ant0            0x0
 * </pre>
 */
#define MACDSP_API1_DIG_GAIN_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x0000097C)
#define MACDSP_API1_DIG_GAIN_OFFSET      0x0000097C
#define MACDSP_API1_DIG_GAIN_INDEX       0x0000025F
#define MACDSP_API1_DIG_GAIN_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_dig_gain_get(void)
{
	return REG_PL_RD(MACDSP_API1_DIG_GAIN_ADDR);
}

__INLINE void macdsp_api1_dig_gain_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_DIG_GAIN_ADDR, value);
}

// field definitions
#define MACDSP_API1_DIG_GAIN_DIGGAIN_20_ANT_3_MASK    ((uint32_t)0x7F000000)
#define MACDSP_API1_DIG_GAIN_DIGGAIN_20_ANT_3_LSB    24
#define MACDSP_API1_DIG_GAIN_DIGGAIN_20_ANT_3_WIDTH    ((uint32_t)0x00000007)
#define MACDSP_API1_DIG_GAIN_DIGGAIN_20_ANT_2_MASK    ((uint32_t)0x007F0000)
#define MACDSP_API1_DIG_GAIN_DIGGAIN_20_ANT_2_LSB    16
#define MACDSP_API1_DIG_GAIN_DIGGAIN_20_ANT_2_WIDTH    ((uint32_t)0x00000007)
#define MACDSP_API1_DIG_GAIN_DIGGAIN_20_ANT_1_MASK    ((uint32_t)0x00007F00)
#define MACDSP_API1_DIG_GAIN_DIGGAIN_20_ANT_1_LSB    8
#define MACDSP_API1_DIG_GAIN_DIGGAIN_20_ANT_1_WIDTH    ((uint32_t)0x00000007)
#define MACDSP_API1_DIG_GAIN_DIGGAIN_20_ANT_0_MASK    ((uint32_t)0x0000007F)
#define MACDSP_API1_DIG_GAIN_DIGGAIN_20_ANT_0_LSB    0
#define MACDSP_API1_DIG_GAIN_DIGGAIN_20_ANT_0_WIDTH    ((uint32_t)0x00000007)

#define MACDSP_API1_DIG_GAIN_DIGGAIN_20_ANT_3_RST    0x0
#define MACDSP_API1_DIG_GAIN_DIGGAIN_20_ANT_2_RST    0x0
#define MACDSP_API1_DIG_GAIN_DIGGAIN_20_ANT_1_RST    0x0
#define MACDSP_API1_DIG_GAIN_DIGGAIN_20_ANT_0_RST    0x0

__INLINE void macdsp_api1_dig_gain_pack(uint8_t diggain20_ant3, uint8_t diggain20_ant2, uint8_t diggain20_ant1, uint8_t diggain20_ant0)
{
	ASSERT_ERR((((uint32_t)diggain20_ant3 << 24) & ~((uint32_t)0x7F000000)) == 0);
	ASSERT_ERR((((uint32_t)diggain20_ant2 << 16) & ~((uint32_t)0x007F0000)) == 0);
	ASSERT_ERR((((uint32_t)diggain20_ant1 << 8) & ~((uint32_t)0x00007F00)) == 0);
	ASSERT_ERR((((uint32_t)diggain20_ant0 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(MACDSP_API1_DIG_GAIN_ADDR,  ((uint32_t)diggain20_ant3 << 24) |((uint32_t)diggain20_ant2 << 16) |((uint32_t)diggain20_ant1 << 8) |((uint32_t)diggain20_ant0 << 0));
}

__INLINE void macdsp_api1_dig_gain_unpack(uint8_t* diggain20_ant3, uint8_t* diggain20_ant2, uint8_t* diggain20_ant1, uint8_t* diggain20_ant0)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DIG_GAIN_ADDR);

	*diggain20_ant3 = (localVal & ((uint32_t)0x7F000000)) >>  24;
	*diggain20_ant2 = (localVal & ((uint32_t)0x007F0000)) >>  16;
	*diggain20_ant1 = (localVal & ((uint32_t)0x00007F00)) >>  8;
	*diggain20_ant0 = (localVal & ((uint32_t)0x0000007F)) >>  0;
}

__INLINE uint8_t macdsp_api1_dig_gain_diggain_20_ant_3_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DIG_GAIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x7F000000)) >> 24);
}
__INLINE void macdsp_api1_dig_gain_diggain_20_ant_3_setf(uint8_t diggain20ant3)
{
	ASSERT_ERR((((uint32_t)diggain20ant3 << 24) & ~((uint32_t)0x7F000000)) == 0);
	REG_PL_WR(MACDSP_API1_DIG_GAIN_ADDR, (REG_PL_RD(MACDSP_API1_DIG_GAIN_ADDR) & ~((uint32_t)0x7F000000)) | ((uint32_t)diggain20ant3 <<24));
}
__INLINE uint8_t macdsp_api1_dig_gain_diggain_20_ant_2_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DIG_GAIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x007F0000)) >> 16);
}
__INLINE void macdsp_api1_dig_gain_diggain_20_ant_2_setf(uint8_t diggain20ant2)
{
	ASSERT_ERR((((uint32_t)diggain20ant2 << 16) & ~((uint32_t)0x007F0000)) == 0);
	REG_PL_WR(MACDSP_API1_DIG_GAIN_ADDR, (REG_PL_RD(MACDSP_API1_DIG_GAIN_ADDR) & ~((uint32_t)0x007F0000)) | ((uint32_t)diggain20ant2 <<16));
}
__INLINE uint8_t macdsp_api1_dig_gain_diggain_20_ant_1_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DIG_GAIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00007F00)) >> 8);
}
__INLINE void macdsp_api1_dig_gain_diggain_20_ant_1_setf(uint8_t diggain20ant1)
{
	ASSERT_ERR((((uint32_t)diggain20ant1 << 8) & ~((uint32_t)0x00007F00)) == 0);
	REG_PL_WR(MACDSP_API1_DIG_GAIN_ADDR, (REG_PL_RD(MACDSP_API1_DIG_GAIN_ADDR) & ~((uint32_t)0x00007F00)) | ((uint32_t)diggain20ant1 <<8));
}
__INLINE uint8_t macdsp_api1_dig_gain_diggain_20_ant_0_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_DIG_GAIN_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007F)) >> 0);
}
__INLINE void macdsp_api1_dig_gain_diggain_20_ant_0_setf(uint8_t diggain20ant0)
{
	ASSERT_ERR((((uint32_t)diggain20ant0 << 0) & ~((uint32_t)0x0000007F)) == 0);
	REG_PL_WR(MACDSP_API1_DIG_GAIN_ADDR, (REG_PL_RD(MACDSP_API1_DIG_GAIN_ADDR) & ~((uint32_t)0x0000007F)) | ((uint32_t)diggain20ant0 <<0));
}

/**
 * @brief INBDPOW_20_1 register definition
 *  Latch_InBand20p_1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:08 Inbdpow20_Pdbm5           0x0
 *    07:00 Inbdpow20_Pdbm4           0x0
 * </pre>
 */
#define MACDSP_API1_INBDPOW_20_1_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x00000980)
#define MACDSP_API1_INBDPOW_20_1_OFFSET      0x00000980
#define MACDSP_API1_INBDPOW_20_1_INDEX       0x00000260
#define MACDSP_API1_INBDPOW_20_1_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_inbdpow_20_1_get(void)
{
	return REG_PL_RD(MACDSP_API1_INBDPOW_20_1_ADDR);
}

__INLINE void macdsp_api1_inbdpow_20_1_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_INBDPOW_20_1_ADDR, value);
}

// field definitions
#define MACDSP_API1_INBDPOW_20_1_INBDPOW_20_PDBM_5_MASK    ((uint32_t)0x0000FF00)
#define MACDSP_API1_INBDPOW_20_1_INBDPOW_20_PDBM_5_LSB    8
#define MACDSP_API1_INBDPOW_20_1_INBDPOW_20_PDBM_5_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_INBDPOW_20_1_INBDPOW_20_PDBM_4_MASK    ((uint32_t)0x000000FF)
#define MACDSP_API1_INBDPOW_20_1_INBDPOW_20_PDBM_4_LSB    0
#define MACDSP_API1_INBDPOW_20_1_INBDPOW_20_PDBM_4_WIDTH    ((uint32_t)0x00000008)

#define MACDSP_API1_INBDPOW_20_1_INBDPOW_20_PDBM_5_RST    0x0
#define MACDSP_API1_INBDPOW_20_1_INBDPOW_20_PDBM_4_RST    0x0

__INLINE void macdsp_api1_inbdpow_20_1_pack(uint8_t inbdpow20_pdbm5, uint8_t inbdpow20_pdbm4)
{
	ASSERT_ERR((((uint32_t)inbdpow20_pdbm5 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	ASSERT_ERR((((uint32_t)inbdpow20_pdbm4 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_INBDPOW_20_1_ADDR,  ((uint32_t)inbdpow20_pdbm5 << 8) |((uint32_t)inbdpow20_pdbm4 << 0));
}

__INLINE void macdsp_api1_inbdpow_20_1_unpack(uint8_t* inbdpow20_pdbm5, uint8_t* inbdpow20_pdbm4)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_INBDPOW_20_1_ADDR);

	*inbdpow20_pdbm5 = (localVal & ((uint32_t)0x0000FF00)) >>  8;
	*inbdpow20_pdbm4 = (localVal & ((uint32_t)0x000000FF)) >>  0;
}

__INLINE uint8_t macdsp_api1_inbdpow_20_1_inbdpow_20_pdbm_5_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_INBDPOW_20_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000FF00)) >> 8);
}
__INLINE void macdsp_api1_inbdpow_20_1_inbdpow_20_pdbm_5_setf(uint8_t inbdpow20pdbm5)
{
	ASSERT_ERR((((uint32_t)inbdpow20pdbm5 << 8) & ~((uint32_t)0x0000FF00)) == 0);
	REG_PL_WR(MACDSP_API1_INBDPOW_20_1_ADDR, (REG_PL_RD(MACDSP_API1_INBDPOW_20_1_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)inbdpow20pdbm5 <<8));
}
__INLINE uint8_t macdsp_api1_inbdpow_20_1_inbdpow_20_pdbm_4_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_INBDPOW_20_1_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000FF)) >> 0);
}
__INLINE void macdsp_api1_inbdpow_20_1_inbdpow_20_pdbm_4_setf(uint8_t inbdpow20pdbm4)
{
	ASSERT_ERR((((uint32_t)inbdpow20pdbm4 << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(MACDSP_API1_INBDPOW_20_1_ADDR, (REG_PL_RD(MACDSP_API1_INBDPOW_20_1_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)inbdpow20pdbm4 <<0));
}

/**
 * @brief RX_DMEM_DEBUG_MODE register definition
 *  RX_DEBUG_CONTROL register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    12    STOP_CAPTURE              0              
 *    11:04 NUMBER_OF_SYMBOL_N        0x0
 *    03:00 SYMBOL_CAPTURE_MODE       0x0
 * </pre>
 */
#define MACDSP_API1_RX_DMEM_DEBUG_MODE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000009DC)
#define MACDSP_API1_RX_DMEM_DEBUG_MODE_OFFSET      0x000009DC
#define MACDSP_API1_RX_DMEM_DEBUG_MODE_INDEX       0x00000277
#define MACDSP_API1_RX_DMEM_DEBUG_MODE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_dmem_debug_mode_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_DMEM_DEBUG_MODE_ADDR);
}

__INLINE void macdsp_api1_rx_dmem_debug_mode_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_DMEM_DEBUG_MODE_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_DMEM_DEBUG_MODE_STOP_CAPTURE_BIT    ((uint32_t)0x00001000)
#define MACDSP_API1_RX_DMEM_DEBUG_MODE_STOP_CAPTURE_POS    12
#define MACDSP_API1_RX_DMEM_DEBUG_MODE_NUMBER_OF_SYMBOL_N_MASK    ((uint32_t)0x00000FF0)
#define MACDSP_API1_RX_DMEM_DEBUG_MODE_NUMBER_OF_SYMBOL_N_LSB    4
#define MACDSP_API1_RX_DMEM_DEBUG_MODE_NUMBER_OF_SYMBOL_N_WIDTH    ((uint32_t)0x00000008)
#define MACDSP_API1_RX_DMEM_DEBUG_MODE_SYMBOL_CAPTURE_MODE_MASK    ((uint32_t)0x0000000F)
#define MACDSP_API1_RX_DMEM_DEBUG_MODE_SYMBOL_CAPTURE_MODE_LSB    0
#define MACDSP_API1_RX_DMEM_DEBUG_MODE_SYMBOL_CAPTURE_MODE_WIDTH    ((uint32_t)0x00000004)

#define MACDSP_API1_RX_DMEM_DEBUG_MODE_STOP_CAPTURE_RST    0x0
#define MACDSP_API1_RX_DMEM_DEBUG_MODE_NUMBER_OF_SYMBOL_N_RST    0x0
#define MACDSP_API1_RX_DMEM_DEBUG_MODE_SYMBOL_CAPTURE_MODE_RST    0x0

__INLINE void macdsp_api1_rx_dmem_debug_mode_pack(uint8_t stop_capture, uint8_t number_of_symbol_n, uint8_t symbol_capture_mode)
{
	ASSERT_ERR((((uint32_t)stop_capture << 12) & ~((uint32_t)0x00001000)) == 0);
	ASSERT_ERR((((uint32_t)number_of_symbol_n << 4) & ~((uint32_t)0x00000FF0)) == 0);
	ASSERT_ERR((((uint32_t)symbol_capture_mode << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MACDSP_API1_RX_DMEM_DEBUG_MODE_ADDR,  ((uint32_t)stop_capture << 12) |((uint32_t)number_of_symbol_n << 4) |((uint32_t)symbol_capture_mode << 0));
}

__INLINE void macdsp_api1_rx_dmem_debug_mode_unpack(uint8_t* stop_capture, uint8_t* number_of_symbol_n, uint8_t* symbol_capture_mode)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_DMEM_DEBUG_MODE_ADDR);

	*stop_capture = (localVal & ((uint32_t)0x00001000)) >>  12;
	*number_of_symbol_n = (localVal & ((uint32_t)0x00000FF0)) >>  4;
	*symbol_capture_mode = (localVal & ((uint32_t)0x0000000F)) >>  0;
}

__INLINE uint8_t macdsp_api1_rx_dmem_debug_mode_stop_capture_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_DMEM_DEBUG_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00001000)) >> 12);
}
__INLINE void macdsp_api1_rx_dmem_debug_mode_stop_capture_setf(uint8_t stopcapture)
{
	ASSERT_ERR((((uint32_t)stopcapture << 12) & ~((uint32_t)0x00001000)) == 0);
	REG_PL_WR(MACDSP_API1_RX_DMEM_DEBUG_MODE_ADDR, (REG_PL_RD(MACDSP_API1_RX_DMEM_DEBUG_MODE_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)stopcapture <<12));
}
__INLINE uint8_t macdsp_api1_rx_dmem_debug_mode_number_of_symbol_n_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_DMEM_DEBUG_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000FF0)) >> 4);
}
__INLINE void macdsp_api1_rx_dmem_debug_mode_number_of_symbol_n_setf(uint8_t numberofsymboln)
{
	ASSERT_ERR((((uint32_t)numberofsymboln << 4) & ~((uint32_t)0x00000FF0)) == 0);
	REG_PL_WR(MACDSP_API1_RX_DMEM_DEBUG_MODE_ADDR, (REG_PL_RD(MACDSP_API1_RX_DMEM_DEBUG_MODE_ADDR) & ~((uint32_t)0x00000FF0)) | ((uint32_t)numberofsymboln <<4));
}
__INLINE uint8_t macdsp_api1_rx_dmem_debug_mode_symbol_capture_mode_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_DMEM_DEBUG_MODE_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000F)) >> 0);
}
__INLINE void macdsp_api1_rx_dmem_debug_mode_symbol_capture_mode_setf(uint8_t symbolcapturemode)
{
	ASSERT_ERR((((uint32_t)symbolcapturemode << 0) & ~((uint32_t)0x0000000F)) == 0);
	REG_PL_WR(MACDSP_API1_RX_DMEM_DEBUG_MODE_ADDR, (REG_PL_RD(MACDSP_API1_RX_DMEM_DEBUG_MODE_ADDR) & ~((uint32_t)0x0000000F)) | ((uint32_t)symbolcapturemode <<0));
}

/**
 * @brief RX_DMEM_DEBUG_PTR register definition
 *  RX_DEUBG_PTR register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 Rx_debug_ptr              0x0
 * </pre>
 */
#define MACDSP_API1_RX_DMEM_DEBUG_PTR_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000009E0)
#define MACDSP_API1_RX_DMEM_DEBUG_PTR_OFFSET      0x000009E0
#define MACDSP_API1_RX_DMEM_DEBUG_PTR_INDEX       0x00000278
#define MACDSP_API1_RX_DMEM_DEBUG_PTR_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_dmem_debug_ptr_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_DMEM_DEBUG_PTR_ADDR);
}

__INLINE void macdsp_api1_rx_dmem_debug_ptr_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_DMEM_DEBUG_PTR_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_DMEM_DEBUG_PTR_RX_DEBUG_PTR_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_RX_DMEM_DEBUG_PTR_RX_DEBUG_PTR_LSB    0
#define MACDSP_API1_RX_DMEM_DEBUG_PTR_RX_DEBUG_PTR_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_RX_DMEM_DEBUG_PTR_RX_DEBUG_PTR_RST    0x0

__INLINE uint32_t macdsp_api1_rx_dmem_debug_ptr_rx_debug_ptr_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_DMEM_DEBUG_PTR_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_dmem_debug_ptr_rx_debug_ptr_setf(uint32_t rxdebugptr)
{
	ASSERT_ERR((((uint32_t)rxdebugptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_DMEM_DEBUG_PTR_ADDR, (uint32_t)rxdebugptr << 0);
}

/**
 * @brief RX_DEBUG_AUTOMATION_FLAGS register definition
 *  RX_DEBUG_AUTOMATION_FLAGS register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    01    TB_AUTO_LDPC_EXTRA_SYMBOL 0              
 *    00    TB_AUTO_TEST_RUN          0              
 * </pre>
 */
#define MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000009E4)
#define MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_OFFSET      0x000009E4
#define MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_INDEX       0x00000279
#define MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_debug_automation_flags_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_ADDR);
}

__INLINE void macdsp_api1_rx_debug_automation_flags_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_TB_AUTO_LDPC_EXTRA_SYMBOL_BIT    ((uint32_t)0x00000002)
#define MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_TB_AUTO_LDPC_EXTRA_SYMBOL_POS    1
#define MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_TB_AUTO_TEST_RUN_BIT    ((uint32_t)0x00000001)
#define MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_TB_AUTO_TEST_RUN_POS    0

#define MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_TB_AUTO_LDPC_EXTRA_SYMBOL_RST    0x0
#define MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_TB_AUTO_TEST_RUN_RST    0x0

__INLINE void macdsp_api1_rx_debug_automation_flags_pack(uint8_t tb_auto_ldpc_extra_symbol, uint8_t tb_auto_test_run)
{
	ASSERT_ERR((((uint32_t)tb_auto_ldpc_extra_symbol << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)tb_auto_test_run << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_ADDR,  ((uint32_t)tb_auto_ldpc_extra_symbol << 1) |((uint32_t)tb_auto_test_run << 0));
}

__INLINE void macdsp_api1_rx_debug_automation_flags_unpack(uint8_t* tb_auto_ldpc_extra_symbol, uint8_t* tb_auto_test_run)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_ADDR);

	*tb_auto_ldpc_extra_symbol = (localVal & ((uint32_t)0x00000002)) >>  1;
	*tb_auto_test_run = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t macdsp_api1_rx_debug_automation_flags_tb_auto_ldpc_extra_symbol_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void macdsp_api1_rx_debug_automation_flags_tb_auto_ldpc_extra_symbol_setf(uint8_t tbautoldpcextrasymbol)
{
	ASSERT_ERR((((uint32_t)tbautoldpcextrasymbol << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_ADDR, (REG_PL_RD(MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)tbautoldpcextrasymbol <<1));
}
__INLINE uint8_t macdsp_api1_rx_debug_automation_flags_tb_auto_test_run_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void macdsp_api1_rx_debug_automation_flags_tb_auto_test_run_setf(uint8_t tbautotestrun)
{
	ASSERT_ERR((((uint32_t)tbautotestrun << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_ADDR, (REG_PL_RD(MACDSP_API1_RX_DEBUG_AUTOMATION_FLAGS_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)tbautotestrun <<0));
}

/**
 * @brief RX_DMEM_DEBUG_SIZE register definition
 *  size_of_dmem_struct register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 dmem_size                 0x0
 * </pre>
 */
#define MACDSP_API1_RX_DMEM_DEBUG_SIZE_ADDR        (REG_MACDSP_API1_BASE_ADDR+0x000009E8)
#define MACDSP_API1_RX_DMEM_DEBUG_SIZE_OFFSET      0x000009E8
#define MACDSP_API1_RX_DMEM_DEBUG_SIZE_INDEX       0x0000027A
#define MACDSP_API1_RX_DMEM_DEBUG_SIZE_RESET       0x00000000

__INLINE uint32_t  macdsp_api1_rx_dmem_debug_size_get(void)
{
	return REG_PL_RD(MACDSP_API1_RX_DMEM_DEBUG_SIZE_ADDR);
}

__INLINE void macdsp_api1_rx_dmem_debug_size_set(uint32_t value)
{
	REG_PL_WR(MACDSP_API1_RX_DMEM_DEBUG_SIZE_ADDR, value);
}

// field definitions
#define MACDSP_API1_RX_DMEM_DEBUG_SIZE_DMEM_SIZE_MASK    ((uint32_t)0xFFFFFFFF)
#define MACDSP_API1_RX_DMEM_DEBUG_SIZE_DMEM_SIZE_LSB    0
#define MACDSP_API1_RX_DMEM_DEBUG_SIZE_DMEM_SIZE_WIDTH    ((uint32_t)0x00000020)

#define MACDSP_API1_RX_DMEM_DEBUG_SIZE_DMEM_SIZE_RST    0x0

__INLINE uint32_t macdsp_api1_rx_dmem_debug_size_dmem_size_getf(void)
{
	uint32_t localVal = REG_PL_RD(MACDSP_API1_RX_DMEM_DEBUG_SIZE_ADDR);
	return (uint32_t)(localVal >> 0);
}
__INLINE void macdsp_api1_rx_dmem_debug_size_dmem_size_setf(uint32_t dmemsize)
{
	ASSERT_ERR((((uint32_t)dmemsize << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
	REG_PL_WR(MACDSP_API1_RX_DMEM_DEBUG_SIZE_ADDR, (uint32_t)dmemsize << 0);
}


#undef DBG_FILEID
#endif //_REG_MACDSP_API1_H_
