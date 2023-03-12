/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef REG_MACDSP_API_H
#define REG_MACDSP_API_H

#include <linux/types.h>
#include "reg_access.h"
#include "chip.h"

/**
 * @brief CONFIG_SPACE register definition
 *  Config Space register description
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
#define MACDSP_API_CONFIG_SPACE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000010)
#define MACDSP_API_CONFIG_SPACE_OFFSET      0x00000010
#define MACDSP_API_CONFIG_SPACE_INDEX       0x00000004
#define MACDSP_API_CONFIG_SPACE_RESET       0x00000000

static inline u32 macdsp_api_config_space_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR);
}

static inline void macdsp_api_config_space_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_CONFIG_SPACE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_CONFIG_SPACE_ACTIVE_ANTENNA_SET_MASK    ((u32)0xFC000000)
#define MACDSP_API_CONFIG_SPACE_ACTIVE_ANTENNA_SET_LSB    26
#define MACDSP_API_CONFIG_SPACE_ACTIVE_ANTENNA_SET_WIDTH    ((u32)0x00000006)
#define MACDSP_API_CONFIG_SPACE_RX_CCK_ACTIVE_CHAIN_MASK    ((u32)0x03F00000)
#define MACDSP_API_CONFIG_SPACE_RX_CCK_ACTIVE_CHAIN_LSB    20
#define MACDSP_API_CONFIG_SPACE_RX_CCK_ACTIVE_CHAIN_WIDTH    ((u32)0x00000006)
#define MACDSP_API_CONFIG_SPACE_RX_OFDM_ACTIVE_CHAIN_MASK    ((u32)0x000FC000)
#define MACDSP_API_CONFIG_SPACE_RX_OFDM_ACTIVE_CHAIN_LSB    14
#define MACDSP_API_CONFIG_SPACE_RX_OFDM_ACTIVE_CHAIN_WIDTH    ((u32)0x00000006)
#define MACDSP_API_CONFIG_SPACE_TX_CCK_ACTIVE_CHAIN_MASK    ((u32)0x00003F00)
#define MACDSP_API_CONFIG_SPACE_TX_CCK_ACTIVE_CHAIN_LSB    8
#define MACDSP_API_CONFIG_SPACE_TX_CCK_ACTIVE_CHAIN_WIDTH    ((u32)0x00000006)
#define MACDSP_API_CONFIG_SPACE_BAND_MASK    ((u32)0x000000C0)
#define MACDSP_API_CONFIG_SPACE_BAND_LSB    6
#define MACDSP_API_CONFIG_SPACE_BAND_WIDTH    ((u32)0x00000002)
#define MACDSP_API_CONFIG_SPACE_CHANNEL_BANDWIDTH_MASK    ((u32)0x00000030)
#define MACDSP_API_CONFIG_SPACE_CHANNEL_BANDWIDTH_LSB    4
#define MACDSP_API_CONFIG_SPACE_CHANNEL_BANDWIDTH_WIDTH    ((u32)0x00000002)
#define MACDSP_API_CONFIG_SPACE_OFDM_ONLY_BIT    ((u32)0x00000008)
#define MACDSP_API_CONFIG_SPACE_OFDM_ONLY_POS    3
#define MACDSP_API_CONFIG_SPACE_RX_SENSING_MODE_BIT    ((u32)0x00000004)
#define MACDSP_API_CONFIG_SPACE_RX_SENSING_MODE_POS    2
#define MACDSP_API_CONFIG_SPACE_UPDATE_SYNC_BIT    ((u32)0x00000002)
#define MACDSP_API_CONFIG_SPACE_UPDATE_SYNC_POS    1
#define MACDSP_API_CONFIG_SPACE_STARTUP_SYNC_BIT    ((u32)0x00000001)
#define MACDSP_API_CONFIG_SPACE_STARTUP_SYNC_POS    0

#define MACDSP_API_CONFIG_SPACE_ACTIVE_ANTENNA_SET_RST    0x0
#define MACDSP_API_CONFIG_SPACE_RX_CCK_ACTIVE_CHAIN_RST    0x0
#define MACDSP_API_CONFIG_SPACE_RX_OFDM_ACTIVE_CHAIN_RST    0x0
#define MACDSP_API_CONFIG_SPACE_TX_CCK_ACTIVE_CHAIN_RST    0x0
#define MACDSP_API_CONFIG_SPACE_BAND_RST    0x0
#define MACDSP_API_CONFIG_SPACE_CHANNEL_BANDWIDTH_RST    0x0
#define MACDSP_API_CONFIG_SPACE_OFDM_ONLY_RST    0x0
#define MACDSP_API_CONFIG_SPACE_RX_SENSING_MODE_RST    0x0
#define MACDSP_API_CONFIG_SPACE_UPDATE_SYNC_RST    0x0
#define MACDSP_API_CONFIG_SPACE_STARTUP_SYNC_RST    0x0

static inline void macdsp_api_config_space_pack(struct cl_chip *chip, u8 active_antenna_set, u8 rx_cck_active_chain, u8 rx_ofdm_active_chain, u8 tx_cck_active_chain, u8 band, u8 channel_bandwidth, u8 ofdm_only, u8 rx_sensing_mode, u8 update_sync, u8 startup_sync)
{
	ASSERT_ERR_CHIP((((u32)active_antenna_set << 26) & ~((u32)0xFC000000)) == 0);
	ASSERT_ERR_CHIP((((u32)rx_cck_active_chain << 20) & ~((u32)0x03F00000)) == 0);
	ASSERT_ERR_CHIP((((u32)rx_ofdm_active_chain << 14) & ~((u32)0x000FC000)) == 0);
	ASSERT_ERR_CHIP((((u32)tx_cck_active_chain << 8) & ~((u32)0x00003F00)) == 0);
	ASSERT_ERR_CHIP((((u32)band << 6) & ~((u32)0x000000C0)) == 0);
	ASSERT_ERR_CHIP((((u32)channel_bandwidth << 4) & ~((u32)0x00000030)) == 0);
	ASSERT_ERR_CHIP((((u32)ofdm_only << 3) & ~((u32)0x00000008)) == 0);
	ASSERT_ERR_CHIP((((u32)rx_sensing_mode << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)update_sync << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)startup_sync << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_CONFIG_SPACE_ADDR, ((u32)active_antenna_set << 26) | ((u32)rx_cck_active_chain << 20) | ((u32)rx_ofdm_active_chain << 14) | ((u32)tx_cck_active_chain << 8) | ((u32)band << 6) | ((u32)channel_bandwidth << 4) | ((u32)ofdm_only << 3) | ((u32)rx_sensing_mode << 2) | ((u32)update_sync << 1) | ((u32)startup_sync << 0));
}

static inline void macdsp_api_config_space_unpack(struct cl_chip *chip, u8 *active_antenna_set, u8 *rx_cck_active_chain, u8 *rx_ofdm_active_chain, u8 *tx_cck_active_chain, u8 *band, u8 *channel_bandwidth, u8 *ofdm_only, u8 *rx_sensing_mode, u8 *update_sync, u8 *startup_sync)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR);

	*active_antenna_set = (local_val & ((u32)0xFC000000)) >> 26;
	*rx_cck_active_chain = (local_val & ((u32)0x03F00000)) >> 20;
	*rx_ofdm_active_chain = (local_val & ((u32)0x000FC000)) >> 14;
	*tx_cck_active_chain = (local_val & ((u32)0x00003F00)) >> 8;
	*band = (local_val & ((u32)0x000000C0)) >> 6;
	*channel_bandwidth = (local_val & ((u32)0x00000030)) >> 4;
	*ofdm_only = (local_val & ((u32)0x00000008)) >> 3;
	*rx_sensing_mode = (local_val & ((u32)0x00000004)) >> 2;
	*update_sync = (local_val & ((u32)0x00000002)) >> 1;
	*startup_sync = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 macdsp_api_config_space_active_antenna_set_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR);

	return (u8)((local_val & ((u32)0xFC000000)) >> 26);
}

static inline void macdsp_api_config_space_active_antenna_set_setf(struct cl_chip *chip, u8 activeantennaset)
{
	ASSERT_ERR_CHIP((((u32)activeantennaset << 26) & ~((u32)0xFC000000)) == 0);
	cl_reg_write(chip, MACDSP_API_CONFIG_SPACE_ADDR, (cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR) & ~((u32)0xFC000000)) | ((u32)activeantennaset << 26));
}

static inline u8 macdsp_api_config_space_rx_cck_active_chain_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR);

	return (u8)((local_val & ((u32)0x03F00000)) >> 20);
}

static inline void macdsp_api_config_space_rx_cck_active_chain_setf(struct cl_chip *chip, u8 rxcckactivechain)
{
	ASSERT_ERR_CHIP((((u32)rxcckactivechain << 20) & ~((u32)0x03F00000)) == 0);
	cl_reg_write(chip, MACDSP_API_CONFIG_SPACE_ADDR, (cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR) & ~((u32)0x03F00000)) | ((u32)rxcckactivechain << 20));
}

static inline u8 macdsp_api_config_space_rx_ofdm_active_chain_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR);

	return (u8)((local_val & ((u32)0x000FC000)) >> 14);
}

static inline void macdsp_api_config_space_rx_ofdm_active_chain_setf(struct cl_chip *chip, u8 rxofdmactivechain)
{
	ASSERT_ERR_CHIP((((u32)rxofdmactivechain << 14) & ~((u32)0x000FC000)) == 0);
	cl_reg_write(chip, MACDSP_API_CONFIG_SPACE_ADDR, (cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR) & ~((u32)0x000FC000)) | ((u32)rxofdmactivechain << 14));
}

static inline u8 macdsp_api_config_space_tx_cck_active_chain_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR);

	return (u8)((local_val & ((u32)0x00003F00)) >> 8);
}

static inline void macdsp_api_config_space_tx_cck_active_chain_setf(struct cl_chip *chip, u8 txcckactivechain)
{
	ASSERT_ERR_CHIP((((u32)txcckactivechain << 8) & ~((u32)0x00003F00)) == 0);
	cl_reg_write(chip, MACDSP_API_CONFIG_SPACE_ADDR, (cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR) & ~((u32)0x00003F00)) | ((u32)txcckactivechain << 8));
}

static inline u8 macdsp_api_config_space_band_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR);

	return (u8)((local_val & ((u32)0x000000C0)) >> 6);
}

static inline void macdsp_api_config_space_band_setf(struct cl_chip *chip, u8 band)
{
	ASSERT_ERR_CHIP((((u32)band << 6) & ~((u32)0x000000C0)) == 0);
	cl_reg_write(chip, MACDSP_API_CONFIG_SPACE_ADDR, (cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR) & ~((u32)0x000000C0)) | ((u32)band << 6));
}

static inline u8 macdsp_api_config_space_channel_bandwidth_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR);

	return (u8)((local_val & ((u32)0x00000030)) >> 4);
}

static inline void macdsp_api_config_space_channel_bandwidth_setf(struct cl_chip *chip, u8 channelbandwidth)
{
	ASSERT_ERR_CHIP((((u32)channelbandwidth << 4) & ~((u32)0x00000030)) == 0);
	cl_reg_write(chip, MACDSP_API_CONFIG_SPACE_ADDR, (cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR) & ~((u32)0x00000030)) | ((u32)channelbandwidth << 4));
}

static inline u8 macdsp_api_config_space_ofdm_only_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR);

	return (u8)((local_val & ((u32)0x00000008)) >> 3);
}

static inline void macdsp_api_config_space_ofdm_only_setf(struct cl_chip *chip, u8 ofdmonly)
{
	ASSERT_ERR_CHIP((((u32)ofdmonly << 3) & ~((u32)0x00000008)) == 0);
	cl_reg_write(chip, MACDSP_API_CONFIG_SPACE_ADDR, (cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR) & ~((u32)0x00000008)) | ((u32)ofdmonly << 3));
}

static inline u8 macdsp_api_config_space_rx_sensing_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void macdsp_api_config_space_rx_sensing_mode_setf(struct cl_chip *chip, u8 rxsensingmode)
{
	ASSERT_ERR_CHIP((((u32)rxsensingmode << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, MACDSP_API_CONFIG_SPACE_ADDR, (cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR) & ~((u32)0x00000004)) | ((u32)rxsensingmode << 2));
}

static inline u8 macdsp_api_config_space_update_sync_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void macdsp_api_config_space_update_sync_setf(struct cl_chip *chip, u8 updatesync)
{
	ASSERT_ERR_CHIP((((u32)updatesync << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MACDSP_API_CONFIG_SPACE_ADDR, (cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR) & ~((u32)0x00000002)) | ((u32)updatesync << 1));
}

static inline u8 macdsp_api_config_space_startup_sync_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void macdsp_api_config_space_startup_sync_setf(struct cl_chip *chip, u8 startupsync)
{
	ASSERT_ERR_CHIP((((u32)startupsync << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_CONFIG_SPACE_ADDR, (cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_ADDR) & ~((u32)0x00000001)) | ((u32)startupsync << 0));
}

/**
 * @brief MAC_DSP_API_0 register definition
 *  MAC_DSP_API_0 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 current_ant_iq_calib      0x0
 *    23    iqdc_dpd_mode             0
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
#define MACDSP_API_MAC_DSP_API_0_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000014)
#define MACDSP_API_MAC_DSP_API_0_OFFSET      0x00000014
#define MACDSP_API_MAC_DSP_API_0_INDEX       0x00000005
#define MACDSP_API_MAC_DSP_API_0_RESET       0x00000105

static inline u32 macdsp_api_mac_dsp_api_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR);
}

static inline void macdsp_api_mac_dsp_api_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_MAC_DSP_API_0_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_MAC_DSP_API_0_CURRENT_ANT_IQ_CALIB_MASK    ((u32)0xFF000000)
#define MACDSP_API_MAC_DSP_API_0_CURRENT_ANT_IQ_CALIB_LSB    24
#define MACDSP_API_MAC_DSP_API_0_CURRENT_ANT_IQ_CALIB_WIDTH    ((u32)0x00000008)
#define MACDSP_API_MAC_DSP_API_0_IQDC_DPD_MODE_BIT    ((u32)0x00800000)
#define MACDSP_API_MAC_DSP_API_0_IQDC_DPD_MODE_POS    23
#define MACDSP_API_MAC_DSP_API_0_GAIN_UPDATE_ENABLE_MASK    ((u32)0x00700000)
#define MACDSP_API_MAC_DSP_API_0_GAIN_UPDATE_ENABLE_LSB    20
#define MACDSP_API_MAC_DSP_API_0_GAIN_UPDATE_ENABLE_WIDTH    ((u32)0x00000003)
#define MACDSP_API_MAC_DSP_API_0_MAC_DSP_API_0_RESERVED_0_MASK    ((u32)0x000E0000)
#define MACDSP_API_MAC_DSP_API_0_MAC_DSP_API_0_RESERVED_0_LSB    17
#define MACDSP_API_MAC_DSP_API_0_MAC_DSP_API_0_RESERVED_0_WIDTH    ((u32)0x00000003)
#define MACDSP_API_MAC_DSP_API_0_TD_CSD_ENABLE_BIT    ((u32)0x00010000)
#define MACDSP_API_MAC_DSP_API_0_TD_CSD_ENABLE_POS    16
#define MACDSP_API_MAC_DSP_API_0_NO_CAPTURE_NOISE_SLEEP_AGC_STATE_BIT    ((u32)0x00008000)
#define MACDSP_API_MAC_DSP_API_0_NO_CAPTURE_NOISE_SLEEP_AGC_STATE_POS    15
#define MACDSP_API_MAC_DSP_API_0_RICU_LOOPBACK_BIT    ((u32)0x00004000)
#define MACDSP_API_MAC_DSP_API_0_RICU_LOOPBACK_POS    14
#define MACDSP_API_MAC_DSP_API_0_TX_POWER_BAYPSS_BIT    ((u32)0x00002000)
#define MACDSP_API_MAC_DSP_API_0_TX_POWER_BAYPSS_POS    13
#define MACDSP_API_MAC_DSP_API_0_HR_FACTOR_MODE_MASK    ((u32)0x00001800)
#define MACDSP_API_MAC_DSP_API_0_HR_FACTOR_MODE_LSB    11
#define MACDSP_API_MAC_DSP_API_0_HR_FACTOR_MODE_WIDTH    ((u32)0x00000002)
#define MACDSP_API_MAC_DSP_API_0_RADAR_MASK_EN_BIT    ((u32)0x00000400)
#define MACDSP_API_MAC_DSP_API_0_RADAR_MASK_EN_POS    10
#define MACDSP_API_MAC_DSP_API_0_PHY_ID_BIT    ((u32)0x00000200)
#define MACDSP_API_MAC_DSP_API_0_PHY_ID_POS    9
#define MACDSP_API_MAC_DSP_API_0_XMEM_BLOCK_SIZE_MASK    ((u32)0x000001F0)
#define MACDSP_API_MAC_DSP_API_0_XMEM_BLOCK_SIZE_LSB    4
#define MACDSP_API_MAC_DSP_API_0_XMEM_BLOCK_SIZE_WIDTH    ((u32)0x00000005)
#define MACDSP_API_MAC_DSP_API_0_SIGNAL_EXT_EN_BIT    ((u32)0x00000008)
#define MACDSP_API_MAC_DSP_API_0_SIGNAL_EXT_EN_POS    3
#define MACDSP_API_MAC_DSP_API_0_AVAILABLE_BW_MASK    ((u32)0x00000006)
#define MACDSP_API_MAC_DSP_API_0_AVAILABLE_BW_LSB    1
#define MACDSP_API_MAC_DSP_API_0_AVAILABLE_BW_WIDTH    ((u32)0x00000002)
#define MACDSP_API_MAC_DSP_API_0_BW_SIGNALING_EN_BIT    ((u32)0x00000001)
#define MACDSP_API_MAC_DSP_API_0_BW_SIGNALING_EN_POS    0

#define MACDSP_API_MAC_DSP_API_0_CURRENT_ANT_IQ_CALIB_RST    0x0
#define MACDSP_API_MAC_DSP_API_0_IQDC_DPD_MODE_RST    0x0
#define MACDSP_API_MAC_DSP_API_0_GAIN_UPDATE_ENABLE_RST    0x0
#define MACDSP_API_MAC_DSP_API_0_MAC_DSP_API_0_RESERVED_0_RST    0x0
#define MACDSP_API_MAC_DSP_API_0_TD_CSD_ENABLE_RST    0x0
#define MACDSP_API_MAC_DSP_API_0_NO_CAPTURE_NOISE_SLEEP_AGC_STATE_RST    0x0
#define MACDSP_API_MAC_DSP_API_0_RICU_LOOPBACK_RST    0x0
#define MACDSP_API_MAC_DSP_API_0_TX_POWER_BAYPSS_RST    0x0
#define MACDSP_API_MAC_DSP_API_0_HR_FACTOR_MODE_RST    0x0
#define MACDSP_API_MAC_DSP_API_0_RADAR_MASK_EN_RST    0x0
#define MACDSP_API_MAC_DSP_API_0_PHY_ID_RST    0x0
#define MACDSP_API_MAC_DSP_API_0_XMEM_BLOCK_SIZE_RST    0x10
#define MACDSP_API_MAC_DSP_API_0_SIGNAL_EXT_EN_RST    0x0
#define MACDSP_API_MAC_DSP_API_0_AVAILABLE_BW_RST    0x2
#define MACDSP_API_MAC_DSP_API_0_BW_SIGNALING_EN_RST    0x1

static inline void macdsp_api_mac_dsp_api_0_pack(struct cl_chip *chip, u8 current_ant_iq_calib, u8 iqdc_dpd_mode, u8 gain_update_enable, u8 mac_dsp_api_0_reserved0, u8 td_csd_enable, u8 no_capture_noise_sleep_agc_state, u8 ricu_loopback, u8 tx_power_baypss, u8 hr_factor_mode, u8 radar_mask_en, u8 phy_id, u8 xmem_block_size, u8 signal_ext_en, u8 available_bw, u8 bw_signaling_en)
{
	ASSERT_ERR_CHIP((((u32)current_ant_iq_calib << 24) & ~((u32)0xFF000000)) == 0);
	ASSERT_ERR_CHIP((((u32)iqdc_dpd_mode << 23) & ~((u32)0x00800000)) == 0);
	ASSERT_ERR_CHIP((((u32)gain_update_enable << 20) & ~((u32)0x00700000)) == 0);
	ASSERT_ERR_CHIP((((u32)mac_dsp_api_0_reserved0 << 17) & ~((u32)0x000E0000)) == 0);
	ASSERT_ERR_CHIP((((u32)td_csd_enable << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)no_capture_noise_sleep_agc_state << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)ricu_loopback << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)tx_power_baypss << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)hr_factor_mode << 11) & ~((u32)0x00001800)) == 0);
	ASSERT_ERR_CHIP((((u32)radar_mask_en << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)phy_id << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)xmem_block_size << 4) & ~((u32)0x000001F0)) == 0);
	ASSERT_ERR_CHIP((((u32)signal_ext_en << 3) & ~((u32)0x00000008)) == 0);
	ASSERT_ERR_CHIP((((u32)available_bw << 1) & ~((u32)0x00000006)) == 0);
	ASSERT_ERR_CHIP((((u32)bw_signaling_en << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_DSP_API_0_ADDR, ((u32)current_ant_iq_calib << 24) | ((u32)iqdc_dpd_mode << 23) | ((u32)gain_update_enable << 20) | ((u32)mac_dsp_api_0_reserved0 << 17) | ((u32)td_csd_enable << 16) | ((u32)no_capture_noise_sleep_agc_state << 15) | ((u32)ricu_loopback << 14) | ((u32)tx_power_baypss << 13) | ((u32)hr_factor_mode << 11) | ((u32)radar_mask_en << 10) | ((u32)phy_id << 9) | ((u32)xmem_block_size << 4) | ((u32)signal_ext_en << 3) | ((u32)available_bw << 1) | ((u32)bw_signaling_en << 0));
}

static inline void macdsp_api_mac_dsp_api_0_unpack(struct cl_chip *chip, u8 *current_ant_iq_calib, u8 *iqdc_dpd_mode, u8 *gain_update_enable, u8 *mac_dsp_api_0_reserved0, u8 *td_csd_enable, u8 *no_capture_noise_sleep_agc_state, u8 *ricu_loopback, u8 *tx_power_baypss, u8 *hr_factor_mode, u8 *radar_mask_en, u8 *phy_id, u8 *xmem_block_size, u8 *signal_ext_en, u8 *available_bw, u8 *bw_signaling_en)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR);

	*current_ant_iq_calib = (local_val & ((u32)0xFF000000)) >> 24;
	*iqdc_dpd_mode = (local_val & ((u32)0x00800000)) >> 23;
	*gain_update_enable = (local_val & ((u32)0x00700000)) >> 20;
	*mac_dsp_api_0_reserved0 = (local_val & ((u32)0x000E0000)) >> 17;
	*td_csd_enable = (local_val & ((u32)0x00010000)) >> 16;
	*no_capture_noise_sleep_agc_state = (local_val & ((u32)0x00008000)) >> 15;
	*ricu_loopback = (local_val & ((u32)0x00004000)) >> 14;
	*tx_power_baypss = (local_val & ((u32)0x00002000)) >> 13;
	*hr_factor_mode = (local_val & ((u32)0x00001800)) >> 11;
	*radar_mask_en = (local_val & ((u32)0x00000400)) >> 10;
	*phy_id = (local_val & ((u32)0x00000200)) >> 9;
	*xmem_block_size = (local_val & ((u32)0x000001F0)) >> 4;
	*signal_ext_en = (local_val & ((u32)0x00000008)) >> 3;
	*available_bw = (local_val & ((u32)0x00000006)) >> 1;
	*bw_signaling_en = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 macdsp_api_mac_dsp_api_0_current_ant_iq_calib_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR);

	return (u8)((local_val & ((u32)0xFF000000)) >> 24);
}

static inline u8 macdsp_api_mac_dsp_api_0_iqdc_dpd_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR);

	return (u8)((local_val & ((u32)0x00800000)) >> 23);
}

static inline void macdsp_api_mac_dsp_api_0_iqdc_dpd_mode_setf(struct cl_chip *chip, u8 iqdcdpdmode)
{
	ASSERT_ERR_CHIP((((u32)iqdcdpdmode << 23) & ~((u32)0x00800000)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_DSP_API_0_ADDR, (cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR) & ~((u32)0x00800000)) | ((u32)iqdcdpdmode << 23));
}

static inline u8 macdsp_api_mac_dsp_api_0_gain_update_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR);

	return (u8)((local_val & ((u32)0x00700000)) >> 20);
}

static inline void macdsp_api_mac_dsp_api_0_gain_update_enable_setf(struct cl_chip *chip, u8 gainupdateenable)
{
	ASSERT_ERR_CHIP((((u32)gainupdateenable << 20) & ~((u32)0x00700000)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_DSP_API_0_ADDR, (cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR) & ~((u32)0x00700000)) | ((u32)gainupdateenable << 20));
}

static inline u8 macdsp_api_mac_dsp_api_0_mac_dsp_api_0_reserved_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR);

	return (u8)((local_val & ((u32)0x000E0000)) >> 17);
}

static inline void macdsp_api_mac_dsp_api_0_mac_dsp_api_0_reserved_0_setf(struct cl_chip *chip, u8 macdspapi0reserved0)
{
	ASSERT_ERR_CHIP((((u32)macdspapi0reserved0 << 17) & ~((u32)0x000E0000)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_DSP_API_0_ADDR, (cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR) & ~((u32)0x000E0000)) | ((u32)macdspapi0reserved0 << 17));
}

static inline u8 macdsp_api_mac_dsp_api_0_td_csd_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void macdsp_api_mac_dsp_api_0_td_csd_enable_setf(struct cl_chip *chip, u8 tdcsdenable)
{
	ASSERT_ERR_CHIP((((u32)tdcsdenable << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_DSP_API_0_ADDR, (cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR) & ~((u32)0x00010000)) | ((u32)tdcsdenable << 16));
}

static inline u8 macdsp_api_mac_dsp_api_0_no_capture_noise_sleep_agc_state_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void macdsp_api_mac_dsp_api_0_no_capture_noise_sleep_agc_state_setf(struct cl_chip *chip, u8 nocapturenoisesleepagcstate)
{
	ASSERT_ERR_CHIP((((u32)nocapturenoisesleepagcstate << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_DSP_API_0_ADDR, (cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR) & ~((u32)0x00008000)) | ((u32)nocapturenoisesleepagcstate << 15));
}

static inline u8 macdsp_api_mac_dsp_api_0_ricu_loopback_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void macdsp_api_mac_dsp_api_0_ricu_loopback_setf(struct cl_chip *chip, u8 riculoopback)
{
	ASSERT_ERR_CHIP((((u32)riculoopback << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_DSP_API_0_ADDR, (cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR) & ~((u32)0x00004000)) | ((u32)riculoopback << 14));
}

static inline u8 macdsp_api_mac_dsp_api_0_tx_power_baypss_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void macdsp_api_mac_dsp_api_0_tx_power_baypss_setf(struct cl_chip *chip, u8 txpowerbaypss)
{
	ASSERT_ERR_CHIP((((u32)txpowerbaypss << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_DSP_API_0_ADDR, (cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR) & ~((u32)0x00002000)) | ((u32)txpowerbaypss << 13));
}

static inline u8 macdsp_api_mac_dsp_api_0_hr_factor_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR);

	return (u8)((local_val & ((u32)0x00001800)) >> 11);
}

static inline void macdsp_api_mac_dsp_api_0_hr_factor_mode_setf(struct cl_chip *chip, u8 hrfactormode)
{
	ASSERT_ERR_CHIP((((u32)hrfactormode << 11) & ~((u32)0x00001800)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_DSP_API_0_ADDR, (cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR) & ~((u32)0x00001800)) | ((u32)hrfactormode << 11));
}

static inline u8 macdsp_api_mac_dsp_api_0_radar_mask_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void macdsp_api_mac_dsp_api_0_radar_mask_en_setf(struct cl_chip *chip, u8 radarmasken)
{
	ASSERT_ERR_CHIP((((u32)radarmasken << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_DSP_API_0_ADDR, (cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR) & ~((u32)0x00000400)) | ((u32)radarmasken << 10));
}

static inline u8 macdsp_api_mac_dsp_api_0_phy_id_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline u8 macdsp_api_mac_dsp_api_0_xmem_block_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR);

	return (u8)((local_val & ((u32)0x000001F0)) >> 4);
}

static inline void macdsp_api_mac_dsp_api_0_xmem_block_size_setf(struct cl_chip *chip, u8 xmemblocksize)
{
	ASSERT_ERR_CHIP((((u32)xmemblocksize << 4) & ~((u32)0x000001F0)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_DSP_API_0_ADDR, (cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR) & ~((u32)0x000001F0)) | ((u32)xmemblocksize << 4));
}

static inline u8 macdsp_api_mac_dsp_api_0_signal_ext_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR);

	return (u8)((local_val & ((u32)0x00000008)) >> 3);
}

static inline void macdsp_api_mac_dsp_api_0_signal_ext_en_setf(struct cl_chip *chip, u8 signalexten)
{
	ASSERT_ERR_CHIP((((u32)signalexten << 3) & ~((u32)0x00000008)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_DSP_API_0_ADDR, (cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR) & ~((u32)0x00000008)) | ((u32)signalexten << 3));
}

static inline u8 macdsp_api_mac_dsp_api_0_available_bw_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR);

	return (u8)((local_val & ((u32)0x00000006)) >> 1);
}

static inline void macdsp_api_mac_dsp_api_0_available_bw_setf(struct cl_chip *chip, u8 availablebw)
{
	ASSERT_ERR_CHIP((((u32)availablebw << 1) & ~((u32)0x00000006)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_DSP_API_0_ADDR, (cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR) & ~((u32)0x00000006)) | ((u32)availablebw << 1));
}

static inline u8 macdsp_api_mac_dsp_api_0_bw_signaling_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void macdsp_api_mac_dsp_api_0_bw_signaling_en_setf(struct cl_chip *chip, u8 bwsignalingen)
{
	ASSERT_ERR_CHIP((((u32)bwsignalingen << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_DSP_API_0_ADDR, (cl_reg_read(chip, MACDSP_API_MAC_DSP_API_0_ADDR) & ~((u32)0x00000001)) | ((u32)bwsignalingen << 0));
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
#define MACDSP_API_MAC_DSP_AGC_API_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000018)
#define MACDSP_API_MAC_DSP_AGC_API_OFFSET      0x00000018
#define MACDSP_API_MAC_DSP_AGC_API_INDEX       0x00000006
#define MACDSP_API_MAC_DSP_AGC_API_RESET       0x00000000

static inline u32 macdsp_api_mac_dsp_agc_api_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_MAC_DSP_AGC_API_ADDR);
}

static inline void macdsp_api_mac_dsp_agc_api_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_MAC_DSP_AGC_API_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_HT_VHT_OFDM_TX_MASK    ((u32)0xFF000000)
#define MACDSP_API_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_HT_VHT_OFDM_TX_LSB    24
#define MACDSP_API_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_HT_VHT_OFDM_TX_WIDTH    ((u32)0x00000008)
#define MACDSP_API_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_LEGACY_OFDM_TX_MASK    ((u32)0x00FF0000)
#define MACDSP_API_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_LEGACY_OFDM_TX_LSB    16
#define MACDSP_API_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_LEGACY_OFDM_TX_WIDTH    ((u32)0x00000008)
#define MACDSP_API_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_CCK_TX_MASK    ((u32)0x0000FF00)
#define MACDSP_API_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_CCK_TX_LSB    8
#define MACDSP_API_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_CCK_TX_WIDTH    ((u32)0x00000008)
#define MACDSP_API_MAC_DSP_AGC_API_AGC_RX_DELAY_ADDR_OFFSET_MASK    ((u32)0x000000FF)
#define MACDSP_API_MAC_DSP_AGC_API_AGC_RX_DELAY_ADDR_OFFSET_LSB    0
#define MACDSP_API_MAC_DSP_AGC_API_AGC_RX_DELAY_ADDR_OFFSET_WIDTH    ((u32)0x00000008)

#define MACDSP_API_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_HT_VHT_OFDM_TX_RST    0x0
#define MACDSP_API_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_LEGACY_OFDM_TX_RST    0x0
#define MACDSP_API_MAC_DSP_AGC_API_AGC_RX_DELAY_AFTER_CCK_TX_RST    0x0
#define MACDSP_API_MAC_DSP_AGC_API_AGC_RX_DELAY_ADDR_OFFSET_RST    0x0

static inline void macdsp_api_mac_dsp_agc_api_pack(struct cl_chip *chip, u8 agc_rx_delay_after_ht_vht_ofdm_tx, u8 agc_rx_delay_after_legacy_ofdm_tx, u8 agc_rx_delay_after_cck_tx, u8 agc_rx_delay_addr_offset)
{
	ASSERT_ERR_CHIP((((u32)agc_rx_delay_after_ht_vht_ofdm_tx << 24) & ~((u32)0xFF000000)) == 0);
	ASSERT_ERR_CHIP((((u32)agc_rx_delay_after_legacy_ofdm_tx << 16) & ~((u32)0x00FF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)agc_rx_delay_after_cck_tx << 8) & ~((u32)0x0000FF00)) == 0);
	ASSERT_ERR_CHIP((((u32)agc_rx_delay_addr_offset << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_DSP_AGC_API_ADDR, ((u32)agc_rx_delay_after_ht_vht_ofdm_tx << 24) | ((u32)agc_rx_delay_after_legacy_ofdm_tx << 16) | ((u32)agc_rx_delay_after_cck_tx << 8) | ((u32)agc_rx_delay_addr_offset << 0));
}

static inline void macdsp_api_mac_dsp_agc_api_unpack(struct cl_chip *chip, u8 *agc_rx_delay_after_ht_vht_ofdm_tx, u8 *agc_rx_delay_after_legacy_ofdm_tx, u8 *agc_rx_delay_after_cck_tx, u8 *agc_rx_delay_addr_offset)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_AGC_API_ADDR);

	*agc_rx_delay_after_ht_vht_ofdm_tx = (local_val & ((u32)0xFF000000)) >> 24;
	*agc_rx_delay_after_legacy_ofdm_tx = (local_val & ((u32)0x00FF0000)) >> 16;
	*agc_rx_delay_after_cck_tx = (local_val & ((u32)0x0000FF00)) >> 8;
	*agc_rx_delay_addr_offset = (local_val & ((u32)0x000000FF)) >> 0;
}

static inline u8 macdsp_api_mac_dsp_agc_api_agc_rx_delay_after_ht_vht_ofdm_tx_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_AGC_API_ADDR);

	return (u8)((local_val & ((u32)0xFF000000)) >> 24);
}

static inline void macdsp_api_mac_dsp_agc_api_agc_rx_delay_after_ht_vht_ofdm_tx_setf(struct cl_chip *chip, u8 agcrxdelayafterhtvhtofdmtx)
{
	ASSERT_ERR_CHIP((((u32)agcrxdelayafterhtvhtofdmtx << 24) & ~((u32)0xFF000000)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_DSP_AGC_API_ADDR, (cl_reg_read(chip, MACDSP_API_MAC_DSP_AGC_API_ADDR) & ~((u32)0xFF000000)) | ((u32)agcrxdelayafterhtvhtofdmtx << 24));
}

static inline u8 macdsp_api_mac_dsp_agc_api_agc_rx_delay_after_legacy_ofdm_tx_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_AGC_API_ADDR);

	return (u8)((local_val & ((u32)0x00FF0000)) >> 16);
}

static inline void macdsp_api_mac_dsp_agc_api_agc_rx_delay_after_legacy_ofdm_tx_setf(struct cl_chip *chip, u8 agcrxdelayafterlegacyofdmtx)
{
	ASSERT_ERR_CHIP((((u32)agcrxdelayafterlegacyofdmtx << 16) & ~((u32)0x00FF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_DSP_AGC_API_ADDR, (cl_reg_read(chip, MACDSP_API_MAC_DSP_AGC_API_ADDR) & ~((u32)0x00FF0000)) | ((u32)agcrxdelayafterlegacyofdmtx << 16));
}

static inline u8 macdsp_api_mac_dsp_agc_api_agc_rx_delay_after_cck_tx_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_AGC_API_ADDR);

	return (u8)((local_val & ((u32)0x0000FF00)) >> 8);
}

static inline void macdsp_api_mac_dsp_agc_api_agc_rx_delay_after_cck_tx_setf(struct cl_chip *chip, u8 agcrxdelayafterccktx)
{
	ASSERT_ERR_CHIP((((u32)agcrxdelayafterccktx << 8) & ~((u32)0x0000FF00)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_DSP_AGC_API_ADDR, (cl_reg_read(chip, MACDSP_API_MAC_DSP_AGC_API_ADDR) & ~((u32)0x0000FF00)) | ((u32)agcrxdelayafterccktx << 8));
}

static inline u8 macdsp_api_mac_dsp_agc_api_agc_rx_delay_addr_offset_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_DSP_AGC_API_ADDR);

	return (u8)((local_val & ((u32)0x000000FF)) >> 0);
}

static inline void macdsp_api_mac_dsp_agc_api_agc_rx_delay_addr_offset_setf(struct cl_chip *chip, u8 agcrxdelayaddroffset)
{
	ASSERT_ERR_CHIP((((u32)agcrxdelayaddroffset << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_DSP_AGC_API_ADDR, (cl_reg_read(chip, MACDSP_API_MAC_DSP_AGC_API_ADDR) & ~((u32)0x000000FF)) | ((u32)agcrxdelayaddroffset << 0));
}

/**
 * @brief AGC_RX_TX_DELAY register definition
 *  AGC_RX_TX_DELAY register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 sifs_10_tx_rx_delay       0x0
 *    15:00 sifs_16_tx_rx_delay       0x0
 * </pre>
 */
#define MACDSP_API_AGC_RX_TX_DELAY_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000001C)
#define MACDSP_API_AGC_RX_TX_DELAY_OFFSET      0x0000001C
#define MACDSP_API_AGC_RX_TX_DELAY_INDEX       0x00000007
#define MACDSP_API_AGC_RX_TX_DELAY_RESET       0x00000000

static inline u32 macdsp_api_agc_rx_tx_delay_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_AGC_RX_TX_DELAY_ADDR);
}

static inline void macdsp_api_agc_rx_tx_delay_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_AGC_RX_TX_DELAY_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_AGC_RX_TX_DELAY_SIFS_10_TX_RX_DELAY_MASK    ((u32)0xFFFF0000)
#define MACDSP_API_AGC_RX_TX_DELAY_SIFS_10_TX_RX_DELAY_LSB    16
#define MACDSP_API_AGC_RX_TX_DELAY_SIFS_10_TX_RX_DELAY_WIDTH    ((u32)0x00000010)
#define MACDSP_API_AGC_RX_TX_DELAY_SIFS_16_TX_RX_DELAY_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_AGC_RX_TX_DELAY_SIFS_16_TX_RX_DELAY_LSB    0
#define MACDSP_API_AGC_RX_TX_DELAY_SIFS_16_TX_RX_DELAY_WIDTH    ((u32)0x00000010)

#define MACDSP_API_AGC_RX_TX_DELAY_SIFS_10_TX_RX_DELAY_RST    0x0
#define MACDSP_API_AGC_RX_TX_DELAY_SIFS_16_TX_RX_DELAY_RST    0x0

static inline void macdsp_api_agc_rx_tx_delay_pack(struct cl_chip *chip, u16 sifs_10_tx_rx_delay, u16 sifs_16_tx_rx_delay)
{
	ASSERT_ERR_CHIP((((u32)sifs_10_tx_rx_delay << 16) & ~((u32)0xFFFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)sifs_16_tx_rx_delay << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_AGC_RX_TX_DELAY_ADDR, ((u32)sifs_10_tx_rx_delay << 16) | ((u32)sifs_16_tx_rx_delay << 0));
}

static inline void macdsp_api_agc_rx_tx_delay_unpack(struct cl_chip *chip, u16 *sifs_10_tx_rx_delay, u16 *sifs_16_tx_rx_delay)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_AGC_RX_TX_DELAY_ADDR);

	*sifs_10_tx_rx_delay = (local_val & ((u32)0xFFFF0000)) >> 16;
	*sifs_16_tx_rx_delay = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_agc_rx_tx_delay_sifs_10_tx_rx_delay_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_AGC_RX_TX_DELAY_ADDR);

	return (u16)((local_val & ((u32)0xFFFF0000)) >> 16);
}

static inline void macdsp_api_agc_rx_tx_delay_sifs_10_tx_rx_delay_setf(struct cl_chip *chip, u16 sifs10txrxdelay)
{
	ASSERT_ERR_CHIP((((u32)sifs10txrxdelay << 16) & ~((u32)0xFFFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_AGC_RX_TX_DELAY_ADDR, (cl_reg_read(chip, MACDSP_API_AGC_RX_TX_DELAY_ADDR) & ~((u32)0xFFFF0000)) | ((u32)sifs10txrxdelay << 16));
}

static inline u16 macdsp_api_agc_rx_tx_delay_sifs_16_tx_rx_delay_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_AGC_RX_TX_DELAY_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_agc_rx_tx_delay_sifs_16_tx_rx_delay_setf(struct cl_chip *chip, u16 sifs16txrxdelay)
{
	ASSERT_ERR_CHIP((((u32)sifs16txrxdelay << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_AGC_RX_TX_DELAY_ADDR, (cl_reg_read(chip, MACDSP_API_AGC_RX_TX_DELAY_ADDR) & ~((u32)0x0000FFFF)) | ((u32)sifs16txrxdelay << 0));
}

/**
 * @brief DFS_CENTER_FREQ_THR register definition
 *  threshold for center freq algorithm register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    11:08 FREQ_THR                  0x0
 *    07:00 FOM_THR                   0x0
 * </pre>
 */
#define MACDSP_API_DFS_CENTER_FREQ_THR_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000020)
#define MACDSP_API_DFS_CENTER_FREQ_THR_OFFSET      0x00000020
#define MACDSP_API_DFS_CENTER_FREQ_THR_INDEX       0x00000008
#define MACDSP_API_DFS_CENTER_FREQ_THR_RESET       0x00000000

static inline u32 macdsp_api_dfs_center_freq_thr_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_DFS_CENTER_FREQ_THR_ADDR);
}

static inline void macdsp_api_dfs_center_freq_thr_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_DFS_CENTER_FREQ_THR_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_DFS_CENTER_FREQ_THR_FREQ_THR_MASK    ((u32)0x00000F00)
#define MACDSP_API_DFS_CENTER_FREQ_THR_FREQ_THR_LSB    8
#define MACDSP_API_DFS_CENTER_FREQ_THR_FREQ_THR_WIDTH    ((u32)0x00000004)
#define MACDSP_API_DFS_CENTER_FREQ_THR_FOM_THR_MASK    ((u32)0x000000FF)
#define MACDSP_API_DFS_CENTER_FREQ_THR_FOM_THR_LSB    0
#define MACDSP_API_DFS_CENTER_FREQ_THR_FOM_THR_WIDTH    ((u32)0x00000008)

#define MACDSP_API_DFS_CENTER_FREQ_THR_FREQ_THR_RST    0x0
#define MACDSP_API_DFS_CENTER_FREQ_THR_FOM_THR_RST    0x0

static inline void macdsp_api_dfs_center_freq_thr_pack(struct cl_chip *chip, u8 freq_thr, u8 fom_thr)
{
	ASSERT_ERR_CHIP((((u32)freq_thr << 8) & ~((u32)0x00000F00)) == 0);
	ASSERT_ERR_CHIP((((u32)fom_thr << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MACDSP_API_DFS_CENTER_FREQ_THR_ADDR, ((u32)freq_thr << 8) | ((u32)fom_thr << 0));
}

static inline void macdsp_api_dfs_center_freq_thr_unpack(struct cl_chip *chip, u8 *freq_thr, u8 *fom_thr)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DFS_CENTER_FREQ_THR_ADDR);

	*freq_thr = (local_val & ((u32)0x00000F00)) >> 8;
	*fom_thr = (local_val & ((u32)0x000000FF)) >> 0;
}

static inline u8 macdsp_api_dfs_center_freq_thr_freq_thr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DFS_CENTER_FREQ_THR_ADDR);

	return (u8)((local_val & ((u32)0x00000F00)) >> 8);
}

static inline void macdsp_api_dfs_center_freq_thr_freq_thr_setf(struct cl_chip *chip, u8 freqthr)
{
	ASSERT_ERR_CHIP((((u32)freqthr << 8) & ~((u32)0x00000F00)) == 0);
	cl_reg_write(chip, MACDSP_API_DFS_CENTER_FREQ_THR_ADDR, (cl_reg_read(chip, MACDSP_API_DFS_CENTER_FREQ_THR_ADDR) & ~((u32)0x00000F00)) | ((u32)freqthr << 8));
}

static inline u8 macdsp_api_dfs_center_freq_thr_fom_thr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DFS_CENTER_FREQ_THR_ADDR);

	return (u8)((local_val & ((u32)0x000000FF)) >> 0);
}

static inline void macdsp_api_dfs_center_freq_thr_fom_thr_setf(struct cl_chip *chip, u8 fomthr)
{
	ASSERT_ERR_CHIP((((u32)fomthr << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MACDSP_API_DFS_CENTER_FREQ_THR_ADDR, (cl_reg_read(chip, MACDSP_API_DFS_CENTER_FREQ_THR_ADDR) & ~((u32)0x000000FF)) | ((u32)fomthr << 0));
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
#define MACDSP_API_CCA_CTRL_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000024)
#define MACDSP_API_CCA_CTRL_OFFSET      0x00000024
#define MACDSP_API_CCA_CTRL_INDEX       0x00000009
#define MACDSP_API_CCA_CTRL_RESET       0x00000000

static inline u32 macdsp_api_cca_ctrl_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_CCA_CTRL_ADDR);
}

static inline void macdsp_api_cca_ctrl_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_CCA_CTRL_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_CCA_CTRL_RWNXAGCCCACTRL_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_CCA_CTRL_RWNXAGCCCACTRL_LSB    0
#define MACDSP_API_CCA_CTRL_RWNXAGCCCACTRL_WIDTH    ((u32)0x00000020)

#define MACDSP_API_CCA_CTRL_RWNXAGCCCACTRL_RST    0x0

static inline u32 macdsp_api_cca_ctrl_rwnxagcccactrl_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CCA_CTRL_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_cca_ctrl_rwnxagcccactrl_setf(struct cl_chip *chip, u32 rwnxagcccactrl)
{
	ASSERT_ERR_CHIP((((u32)rwnxagcccactrl << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_CCA_CTRL_ADDR, (u32)rwnxagcccactrl << 0);
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
#define MACDSP_API_CCA_CTRL_2_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000028)
#define MACDSP_API_CCA_CTRL_2_OFFSET      0x00000028
#define MACDSP_API_CCA_CTRL_2_INDEX       0x0000000A
#define MACDSP_API_CCA_CTRL_2_RESET       0x00000000

static inline u32 macdsp_api_cca_ctrl_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_CCA_CTRL_2_ADDR);
}

static inline void macdsp_api_cca_ctrl_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_CCA_CTRL_2_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_CCA_CTRL_2_RWNXAGCCCACTRL_2_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_CCA_CTRL_2_RWNXAGCCCACTRL_2_LSB    0
#define MACDSP_API_CCA_CTRL_2_RWNXAGCCCACTRL_2_WIDTH    ((u32)0x00000020)

#define MACDSP_API_CCA_CTRL_2_RWNXAGCCCACTRL_2_RST    0x0

static inline u32 macdsp_api_cca_ctrl_2_rwnxagcccactrl_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CCA_CTRL_2_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_cca_ctrl_2_rwnxagcccactrl_2_setf(struct cl_chip *chip, u32 rwnxagcccactrl2)
{
	ASSERT_ERR_CHIP((((u32)rwnxagcccactrl2 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_CCA_CTRL_2_ADDR, (u32)rwnxagcccactrl2 << 0);
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
#define MACDSP_API_ACTIVE_TX_CHAINS_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000002C)
#define MACDSP_API_ACTIVE_TX_CHAINS_OFFSET      0x0000002C
#define MACDSP_API_ACTIVE_TX_CHAINS_INDEX       0x0000000B
#define MACDSP_API_ACTIVE_TX_CHAINS_RESET       0x00000000

static inline u32 macdsp_api_active_tx_chains_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_ACTIVE_TX_CHAINS_ADDR);
}

static inline void macdsp_api_active_tx_chains_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_ACTIVE_TX_CHAINS_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_ACTIVE_TX_CHAINS_CCK_MASK    ((u32)0x003F0000)
#define MACDSP_API_ACTIVE_TX_CHAINS_CCK_LSB    16
#define MACDSP_API_ACTIVE_TX_CHAINS_CCK_WIDTH    ((u32)0x00000006)
#define MACDSP_API_ACTIVE_TX_CHAINS_HE_MASK    ((u32)0x00003F00)
#define MACDSP_API_ACTIVE_TX_CHAINS_HE_LSB    8
#define MACDSP_API_ACTIVE_TX_CHAINS_HE_WIDTH    ((u32)0x00000006)
#define MACDSP_API_ACTIVE_TX_CHAINS_NON_HE_OFDM_MASK    ((u32)0x0000003F)
#define MACDSP_API_ACTIVE_TX_CHAINS_NON_HE_OFDM_LSB    0
#define MACDSP_API_ACTIVE_TX_CHAINS_NON_HE_OFDM_WIDTH    ((u32)0x00000006)

#define MACDSP_API_ACTIVE_TX_CHAINS_CCK_RST    0x0
#define MACDSP_API_ACTIVE_TX_CHAINS_HE_RST    0x0
#define MACDSP_API_ACTIVE_TX_CHAINS_NON_HE_OFDM_RST    0x0

static inline void macdsp_api_active_tx_chains_pack(struct cl_chip *chip, u8 cck, u8 he, u8 non_he_ofdm)
{
	ASSERT_ERR_CHIP((((u32)cck << 16) & ~((u32)0x003F0000)) == 0);
	ASSERT_ERR_CHIP((((u32)he << 8) & ~((u32)0x00003F00)) == 0);
	ASSERT_ERR_CHIP((((u32)non_he_ofdm << 0) & ~((u32)0x0000003F)) == 0);
	cl_reg_write(chip, MACDSP_API_ACTIVE_TX_CHAINS_ADDR, ((u32)cck << 16) | ((u32)he << 8) | ((u32)non_he_ofdm << 0));
}

static inline void macdsp_api_active_tx_chains_unpack(struct cl_chip *chip, u8 *cck, u8 *he, u8 *non_he_ofdm)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_ACTIVE_TX_CHAINS_ADDR);

	*cck = (local_val & ((u32)0x003F0000)) >> 16;
	*he = (local_val & ((u32)0x00003F00)) >> 8;
	*non_he_ofdm = (local_val & ((u32)0x0000003F)) >> 0;
}

static inline u8 macdsp_api_active_tx_chains_cck_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_ACTIVE_TX_CHAINS_ADDR);

	return (u8)((local_val & ((u32)0x003F0000)) >> 16);
}

static inline void macdsp_api_active_tx_chains_cck_setf(struct cl_chip *chip, u8 cck)
{
	ASSERT_ERR_CHIP((((u32)cck << 16) & ~((u32)0x003F0000)) == 0);
	cl_reg_write(chip, MACDSP_API_ACTIVE_TX_CHAINS_ADDR, (cl_reg_read(chip, MACDSP_API_ACTIVE_TX_CHAINS_ADDR) & ~((u32)0x003F0000)) | ((u32)cck << 16));
}

static inline u8 macdsp_api_active_tx_chains_he_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_ACTIVE_TX_CHAINS_ADDR);

	return (u8)((local_val & ((u32)0x00003F00)) >> 8);
}

static inline void macdsp_api_active_tx_chains_he_setf(struct cl_chip *chip, u8 he)
{
	ASSERT_ERR_CHIP((((u32)he << 8) & ~((u32)0x00003F00)) == 0);
	cl_reg_write(chip, MACDSP_API_ACTIVE_TX_CHAINS_ADDR, (cl_reg_read(chip, MACDSP_API_ACTIVE_TX_CHAINS_ADDR) & ~((u32)0x00003F00)) | ((u32)he << 8));
}

static inline u8 macdsp_api_active_tx_chains_non_he_ofdm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_ACTIVE_TX_CHAINS_ADDR);

	return (u8)((local_val & ((u32)0x0000003F)) >> 0);
}

static inline void macdsp_api_active_tx_chains_non_he_ofdm_setf(struct cl_chip *chip, u8 nonheofdm)
{
	ASSERT_ERR_CHIP((((u32)nonheofdm << 0) & ~((u32)0x0000003F)) == 0);
	cl_reg_write(chip, MACDSP_API_ACTIVE_TX_CHAINS_ADDR, (cl_reg_read(chip, MACDSP_API_ACTIVE_TX_CHAINS_ADDR) & ~((u32)0x0000003F)) | ((u32)nonheofdm << 0));
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
#define MACDSP_API_RIU_AGC_EVENT_4_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000030)
#define MACDSP_API_RIU_AGC_EVENT_4_OFFSET      0x00000030
#define MACDSP_API_RIU_AGC_EVENT_4_INDEX       0x0000000C
#define MACDSP_API_RIU_AGC_EVENT_4_RESET       0x00000000

static inline u32 macdsp_api_riu_agc_event_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RIU_AGC_EVENT_4_ADDR);
}

static inline void macdsp_api_riu_agc_event_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RIU_AGC_EVENT_4_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RIU_AGC_EVENT_4_RIU_AGC_EVENT_4_REGISTER_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_RIU_AGC_EVENT_4_RIU_AGC_EVENT_4_REGISTER_LSB    0
#define MACDSP_API_RIU_AGC_EVENT_4_RIU_AGC_EVENT_4_REGISTER_WIDTH    ((u32)0x00000020)

#define MACDSP_API_RIU_AGC_EVENT_4_RIU_AGC_EVENT_4_REGISTER_RST    0x0

static inline u32 macdsp_api_riu_agc_event_4_riu_agc_event_4_register_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RIU_AGC_EVENT_4_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_riu_agc_event_4_riu_agc_event_4_register_setf(struct cl_chip *chip, u32 riuagcevent4register)
{
	ASSERT_ERR_CHIP((((u32)riuagcevent4register << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RIU_AGC_EVENT_4_ADDR, (u32)riuagcevent4register << 0);
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
#define MACDSP_API_MAC_0_TO_MAC_1_FRC_DELTA_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000034)
#define MACDSP_API_MAC_0_TO_MAC_1_FRC_DELTA_OFFSET      0x00000034
#define MACDSP_API_MAC_0_TO_MAC_1_FRC_DELTA_INDEX       0x0000000D
#define MACDSP_API_MAC_0_TO_MAC_1_FRC_DELTA_RESET       0x00000000

static inline u32 macdsp_api_mac_0_to_mac_1_frc_delta_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_MAC_0_TO_MAC_1_FRC_DELTA_ADDR);
}

static inline void macdsp_api_mac_0_to_mac_1_frc_delta_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_MAC_0_TO_MAC_1_FRC_DELTA_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_MAC_0_TO_MAC_1_FRC_DELTA_FRC_DELTA_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_MAC_0_TO_MAC_1_FRC_DELTA_FRC_DELTA_LSB    0
#define MACDSP_API_MAC_0_TO_MAC_1_FRC_DELTA_FRC_DELTA_WIDTH    ((u32)0x00000020)

#define MACDSP_API_MAC_0_TO_MAC_1_FRC_DELTA_FRC_DELTA_RST    0x0

static inline u32 macdsp_api_mac_0_to_mac_1_frc_delta_frc_delta_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_0_TO_MAC_1_FRC_DELTA_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_mac_0_to_mac_1_frc_delta_frc_delta_setf(struct cl_chip *chip, u32 frcdelta)
{
	ASSERT_ERR_CHIP((((u32)frcdelta << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_0_TO_MAC_1_FRC_DELTA_ADDR, (u32)frcdelta << 0);
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
#define MACDSP_API_MAX_NC_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000038)
#define MACDSP_API_MAX_NC_OFFSET      0x00000038
#define MACDSP_API_MAX_NC_INDEX       0x0000000E
#define MACDSP_API_MAX_NC_RESET       0x00000000

static inline u32 macdsp_api_max_nc_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_MAX_NC_ADDR);
}

static inline void macdsp_api_max_nc_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_MAX_NC_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_MAX_NC_MAX_NC_RESERVED_0_MASK    ((u32)0xFFFF0000)
#define MACDSP_API_MAX_NC_MAX_NC_RESERVED_0_LSB    16
#define MACDSP_API_MAX_NC_MAX_NC_RESERVED_0_WIDTH    ((u32)0x00000010)
#define MACDSP_API_MAX_NC_MAX_NC_HE_MASK    ((u32)0x0000FF00)
#define MACDSP_API_MAX_NC_MAX_NC_HE_LSB     8
#define MACDSP_API_MAX_NC_MAX_NC_HE_WIDTH    ((u32)0x00000008)
#define MACDSP_API_MAX_NC_MAX_NC_VHT_MASK    ((u32)0x000000FF)
#define MACDSP_API_MAX_NC_MAX_NC_VHT_LSB    0
#define MACDSP_API_MAX_NC_MAX_NC_VHT_WIDTH    ((u32)0x00000008)

#define MACDSP_API_MAX_NC_MAX_NC_RESERVED_0_RST    0x0
#define MACDSP_API_MAX_NC_MAX_NC_HE_RST     0x0
#define MACDSP_API_MAX_NC_MAX_NC_VHT_RST    0x0

static inline void macdsp_api_max_nc_pack(struct cl_chip *chip, u16 max_nc_reserved0, u8 max_nc_he, u8 max_nc_vht)
{
	ASSERT_ERR_CHIP((((u32)max_nc_reserved0 << 16) & ~((u32)0xFFFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)max_nc_he << 8) & ~((u32)0x0000FF00)) == 0);
	ASSERT_ERR_CHIP((((u32)max_nc_vht << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MACDSP_API_MAX_NC_ADDR, ((u32)max_nc_reserved0 << 16) | ((u32)max_nc_he << 8) | ((u32)max_nc_vht << 0));
}

static inline void macdsp_api_max_nc_unpack(struct cl_chip *chip, u16 *max_nc_reserved0, u8 *max_nc_he, u8 *max_nc_vht)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAX_NC_ADDR);

	*max_nc_reserved0 = (local_val & ((u32)0xFFFF0000)) >> 16;
	*max_nc_he = (local_val & ((u32)0x0000FF00)) >> 8;
	*max_nc_vht = (local_val & ((u32)0x000000FF)) >> 0;
}

static inline u16 macdsp_api_max_nc_max_nc_reserved_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAX_NC_ADDR);

	return (u16)((local_val & ((u32)0xFFFF0000)) >> 16);
}

static inline void macdsp_api_max_nc_max_nc_reserved_0_setf(struct cl_chip *chip, u16 maxncreserved0)
{
	ASSERT_ERR_CHIP((((u32)maxncreserved0 << 16) & ~((u32)0xFFFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_MAX_NC_ADDR, (cl_reg_read(chip, MACDSP_API_MAX_NC_ADDR) & ~((u32)0xFFFF0000)) | ((u32)maxncreserved0 << 16));
}

static inline u8 macdsp_api_max_nc_max_nc_he_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAX_NC_ADDR);

	return (u8)((local_val & ((u32)0x0000FF00)) >> 8);
}

static inline void macdsp_api_max_nc_max_nc_he_setf(struct cl_chip *chip, u8 maxnche)
{
	ASSERT_ERR_CHIP((((u32)maxnche << 8) & ~((u32)0x0000FF00)) == 0);
	cl_reg_write(chip, MACDSP_API_MAX_NC_ADDR, (cl_reg_read(chip, MACDSP_API_MAX_NC_ADDR) & ~((u32)0x0000FF00)) | ((u32)maxnche << 8));
}

static inline u8 macdsp_api_max_nc_max_nc_vht_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAX_NC_ADDR);

	return (u8)((local_val & ((u32)0x000000FF)) >> 0);
}

static inline void macdsp_api_max_nc_max_nc_vht_setf(struct cl_chip *chip, u8 maxncvht)
{
	ASSERT_ERR_CHIP((((u32)maxncvht << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MACDSP_API_MAX_NC_ADDR, (cl_reg_read(chip, MACDSP_API_MAX_NC_ADDR) & ~((u32)0x000000FF)) | ((u32)maxncvht << 0));
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
#define MACDSP_API_ASSERT_INFO_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000003C)
#define MACDSP_API_ASSERT_INFO_OFFSET      0x0000003C
#define MACDSP_API_ASSERT_INFO_INDEX       0x0000000F
#define MACDSP_API_ASSERT_INFO_RESET       0x00000000

static inline u32 macdsp_api_assert_info_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_ASSERT_INFO_ADDR);
}

static inline void macdsp_api_assert_info_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_ASSERT_INFO_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_ASSERT_INFO_ASSERT_INFO_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_ASSERT_INFO_ASSERT_INFO_LSB    0
#define MACDSP_API_ASSERT_INFO_ASSERT_INFO_WIDTH    ((u32)0x00000020)

#define MACDSP_API_ASSERT_INFO_ASSERT_INFO_RST    0x0

static inline u32 macdsp_api_assert_info_assert_info_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_ASSERT_INFO_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_assert_info_assert_info_setf(struct cl_chip *chip, u32 assertinfo)
{
	ASSERT_ERR_CHIP((((u32)assertinfo << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_ASSERT_INFO_ADDR, (u32)assertinfo << 0);
}

/**
 * @brief TOD_HIGH register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 tod_h                     0x0
 * </pre>
 */
#define MACDSP_API_TOD_HIGH_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000040)
#define MACDSP_API_TOD_HIGH_OFFSET      0x00000040
#define MACDSP_API_TOD_HIGH_INDEX       0x00000010
#define MACDSP_API_TOD_HIGH_RESET       0x00000000

static inline u32 macdsp_api_tod_high_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TOD_HIGH_ADDR);
}

static inline void macdsp_api_tod_high_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TOD_HIGH_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TOD_HIGH_TOD_H_MASK      ((u32)0xFFFFFFFF)
#define MACDSP_API_TOD_HIGH_TOD_H_LSB       0
#define MACDSP_API_TOD_HIGH_TOD_H_WIDTH     ((u32)0x00000020)

#define MACDSP_API_TOD_HIGH_TOD_H_RST       0x0

static inline u32 macdsp_api_tod_high_tod_h_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TOD_HIGH_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_tod_high_tod_h_setf(struct cl_chip *chip, u32 todh)
{
	ASSERT_ERR_CHIP((((u32)todh << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TOD_HIGH_ADDR, (u32)todh << 0);
}

/**
 * @brief TOD_LOW register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 tod_l                     0x0
 * </pre>
 */
#define MACDSP_API_TOD_LOW_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000044)
#define MACDSP_API_TOD_LOW_OFFSET      0x00000044
#define MACDSP_API_TOD_LOW_INDEX       0x00000011
#define MACDSP_API_TOD_LOW_RESET       0x00000000

static inline u32 macdsp_api_tod_low_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TOD_LOW_ADDR);
}

static inline void macdsp_api_tod_low_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TOD_LOW_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TOD_LOW_TOD_L_MASK       ((u32)0xFFFFFFFF)
#define MACDSP_API_TOD_LOW_TOD_L_LSB        0
#define MACDSP_API_TOD_LOW_TOD_L_WIDTH      ((u32)0x00000020)

#define MACDSP_API_TOD_LOW_TOD_L_RST        0x0

static inline u32 macdsp_api_tod_low_tod_l_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TOD_LOW_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_tod_low_tod_l_setf(struct cl_chip *chip, u32 todl)
{
	ASSERT_ERR_CHIP((((u32)todl << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TOD_LOW_ADDR, (u32)todl << 0);
}

/**
 * @brief TOA_HIGH register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 tod_h                     0x0
 * </pre>
 */
#define MACDSP_API_TOA_HIGH_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000048)
#define MACDSP_API_TOA_HIGH_OFFSET      0x00000048
#define MACDSP_API_TOA_HIGH_INDEX       0x00000012
#define MACDSP_API_TOA_HIGH_RESET       0x00000000

static inline u32 macdsp_api_toa_high_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TOA_HIGH_ADDR);
}

static inline void macdsp_api_toa_high_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TOA_HIGH_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TOA_HIGH_TOD_H_MASK      ((u32)0xFFFFFFFF)
#define MACDSP_API_TOA_HIGH_TOD_H_LSB       0
#define MACDSP_API_TOA_HIGH_TOD_H_WIDTH     ((u32)0x00000020)

#define MACDSP_API_TOA_HIGH_TOD_H_RST       0x0

static inline u32 macdsp_api_toa_high_tod_h_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TOA_HIGH_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_toa_high_tod_h_setf(struct cl_chip *chip, u32 todh)
{
	ASSERT_ERR_CHIP((((u32)todh << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TOA_HIGH_ADDR, (u32)todh << 0);
}

/**
 * @brief TOA_LOW register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 toa_l                     0x0
 * </pre>
 */
#define MACDSP_API_TOA_LOW_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000004C)
#define MACDSP_API_TOA_LOW_OFFSET      0x0000004C
#define MACDSP_API_TOA_LOW_INDEX       0x00000013
#define MACDSP_API_TOA_LOW_RESET       0x00000000

static inline u32 macdsp_api_toa_low_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TOA_LOW_ADDR);
}

static inline void macdsp_api_toa_low_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TOA_LOW_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TOA_LOW_TOA_L_MASK       ((u32)0xFFFFFFFF)
#define MACDSP_API_TOA_LOW_TOA_L_LSB        0
#define MACDSP_API_TOA_LOW_TOA_L_WIDTH      ((u32)0x00000020)

#define MACDSP_API_TOA_LOW_TOA_L_RST        0x0

static inline u32 macdsp_api_toa_low_toa_l_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TOA_LOW_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_toa_low_toa_l_setf(struct cl_chip *chip, u32 toal)
{
	ASSERT_ERR_CHIP((((u32)toal << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TOA_LOW_ADDR, (u32)toal << 0);
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
#define MACDSP_API_TOD_ERR_SN_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000050)
#define MACDSP_API_TOD_ERR_SN_OFFSET      0x00000050
#define MACDSP_API_TOD_ERR_SN_INDEX       0x00000014
#define MACDSP_API_TOD_ERR_SN_RESET       0x00000000

static inline u32 macdsp_api_tod_err_sn_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TOD_ERR_SN_ADDR);
}

static inline void macdsp_api_tod_err_sn_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TOD_ERR_SN_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TOD_ERR_SN_TOD_ERR_SN_RESERVED_0_MASK    ((u32)0xFFF00000)
#define MACDSP_API_TOD_ERR_SN_TOD_ERR_SN_RESERVED_0_LSB    20
#define MACDSP_API_TOD_ERR_SN_TOD_ERR_SN_RESERVED_0_WIDTH    ((u32)0x0000000C)
#define MACDSP_API_TOD_ERR_SN_TOD_SN_MASK    ((u32)0x000F0000)
#define MACDSP_API_TOD_ERR_SN_TOD_SN_LSB    16
#define MACDSP_API_TOD_ERR_SN_TOD_SN_WIDTH    ((u32)0x00000004)
#define MACDSP_API_TOD_ERR_SN_TOD_ERR_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_TOD_ERR_SN_TOD_ERR_LSB    0
#define MACDSP_API_TOD_ERR_SN_TOD_ERR_WIDTH    ((u32)0x00000010)

#define MACDSP_API_TOD_ERR_SN_TOD_ERR_SN_RESERVED_0_RST    0x0
#define MACDSP_API_TOD_ERR_SN_TOD_SN_RST    0x0
#define MACDSP_API_TOD_ERR_SN_TOD_ERR_RST    0x0

static inline void macdsp_api_tod_err_sn_pack(struct cl_chip *chip, u16 tod_err_sn_reserved0, u8 tod_sn, u16 tod_err)
{
	ASSERT_ERR_CHIP((((u32)tod_err_sn_reserved0 << 20) & ~((u32)0xFFF00000)) == 0);
	ASSERT_ERR_CHIP((((u32)tod_sn << 16) & ~((u32)0x000F0000)) == 0);
	ASSERT_ERR_CHIP((((u32)tod_err << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TOD_ERR_SN_ADDR, ((u32)tod_err_sn_reserved0 << 20) | ((u32)tod_sn << 16) | ((u32)tod_err << 0));
}

static inline void macdsp_api_tod_err_sn_unpack(struct cl_chip *chip, u16 *tod_err_sn_reserved0, u8 *tod_sn, u16 *tod_err)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TOD_ERR_SN_ADDR);

	*tod_err_sn_reserved0 = (local_val & ((u32)0xFFF00000)) >> 20;
	*tod_sn = (local_val & ((u32)0x000F0000)) >> 16;
	*tod_err = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_tod_err_sn_tod_err_sn_reserved_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TOD_ERR_SN_ADDR);

	return (u16)((local_val & ((u32)0xFFF00000)) >> 20);
}

static inline void macdsp_api_tod_err_sn_tod_err_sn_reserved_0_setf(struct cl_chip *chip, u16 toderrsnreserved0)
{
	ASSERT_ERR_CHIP((((u32)toderrsnreserved0 << 20) & ~((u32)0xFFF00000)) == 0);
	cl_reg_write(chip, MACDSP_API_TOD_ERR_SN_ADDR, (cl_reg_read(chip, MACDSP_API_TOD_ERR_SN_ADDR) & ~((u32)0xFFF00000)) | ((u32)toderrsnreserved0 << 20));
}

static inline u8 macdsp_api_tod_err_sn_tod_sn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TOD_ERR_SN_ADDR);

	return (u8)((local_val & ((u32)0x000F0000)) >> 16);
}

static inline void macdsp_api_tod_err_sn_tod_sn_setf(struct cl_chip *chip, u8 todsn)
{
	ASSERT_ERR_CHIP((((u32)todsn << 16) & ~((u32)0x000F0000)) == 0);
	cl_reg_write(chip, MACDSP_API_TOD_ERR_SN_ADDR, (cl_reg_read(chip, MACDSP_API_TOD_ERR_SN_ADDR) & ~((u32)0x000F0000)) | ((u32)todsn << 16));
}

static inline u16 macdsp_api_tod_err_sn_tod_err_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TOD_ERR_SN_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_tod_err_sn_tod_err_setf(struct cl_chip *chip, u16 toderr)
{
	ASSERT_ERR_CHIP((((u32)toderr << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TOD_ERR_SN_ADDR, (cl_reg_read(chip, MACDSP_API_TOD_ERR_SN_ADDR) & ~((u32)0x0000FFFF)) | ((u32)toderr << 0));
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
#define MACDSP_API_TOA_ERR_SN_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000054)
#define MACDSP_API_TOA_ERR_SN_OFFSET      0x00000054
#define MACDSP_API_TOA_ERR_SN_INDEX       0x00000015
#define MACDSP_API_TOA_ERR_SN_RESET       0x00000000

static inline u32 macdsp_api_toa_err_sn_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TOA_ERR_SN_ADDR);
}

static inline void macdsp_api_toa_err_sn_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TOA_ERR_SN_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TOA_ERR_SN_TOA_ERR_MASK    ((u32)0xFFF00000)
#define MACDSP_API_TOA_ERR_SN_TOA_ERR_LSB    20
#define MACDSP_API_TOA_ERR_SN_TOA_ERR_WIDTH    ((u32)0x0000000C)
#define MACDSP_API_TOA_ERR_SN_TOA_SN_MASK    ((u32)0x000F0000)
#define MACDSP_API_TOA_ERR_SN_TOA_SN_LSB    16
#define MACDSP_API_TOA_ERR_SN_TOA_SN_WIDTH    ((u32)0x00000004)
#define MACDSP_API_TOA_ERR_SN_TOA_ERR_SN_RESERVED_0_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_TOA_ERR_SN_TOA_ERR_SN_RESERVED_0_LSB    0
#define MACDSP_API_TOA_ERR_SN_TOA_ERR_SN_RESERVED_0_WIDTH    ((u32)0x00000010)

#define MACDSP_API_TOA_ERR_SN_TOA_ERR_RST    0x0
#define MACDSP_API_TOA_ERR_SN_TOA_SN_RST    0x0
#define MACDSP_API_TOA_ERR_SN_TOA_ERR_SN_RESERVED_0_RST    0x0

static inline void macdsp_api_toa_err_sn_pack(struct cl_chip *chip, u16 toa_err, u8 toa_sn, u16 toa_err_sn_reserved0)
{
	ASSERT_ERR_CHIP((((u32)toa_err << 20) & ~((u32)0xFFF00000)) == 0);
	ASSERT_ERR_CHIP((((u32)toa_sn << 16) & ~((u32)0x000F0000)) == 0);
	ASSERT_ERR_CHIP((((u32)toa_err_sn_reserved0 << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TOA_ERR_SN_ADDR, ((u32)toa_err << 20) | ((u32)toa_sn << 16) | ((u32)toa_err_sn_reserved0 << 0));
}

static inline void macdsp_api_toa_err_sn_unpack(struct cl_chip *chip, u16 *toa_err, u8 *toa_sn, u16 *toa_err_sn_reserved0)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TOA_ERR_SN_ADDR);

	*toa_err = (local_val & ((u32)0xFFF00000)) >> 20;
	*toa_sn = (local_val & ((u32)0x000F0000)) >> 16;
	*toa_err_sn_reserved0 = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_toa_err_sn_toa_err_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TOA_ERR_SN_ADDR);

	return (u16)((local_val & ((u32)0xFFF00000)) >> 20);
}

static inline void macdsp_api_toa_err_sn_toa_err_setf(struct cl_chip *chip, u16 toaerr)
{
	ASSERT_ERR_CHIP((((u32)toaerr << 20) & ~((u32)0xFFF00000)) == 0);
	cl_reg_write(chip, MACDSP_API_TOA_ERR_SN_ADDR, (cl_reg_read(chip, MACDSP_API_TOA_ERR_SN_ADDR) & ~((u32)0xFFF00000)) | ((u32)toaerr << 20));
}

static inline u8 macdsp_api_toa_err_sn_toa_sn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TOA_ERR_SN_ADDR);

	return (u8)((local_val & ((u32)0x000F0000)) >> 16);
}

static inline void macdsp_api_toa_err_sn_toa_sn_setf(struct cl_chip *chip, u8 toasn)
{
	ASSERT_ERR_CHIP((((u32)toasn << 16) & ~((u32)0x000F0000)) == 0);
	cl_reg_write(chip, MACDSP_API_TOA_ERR_SN_ADDR, (cl_reg_read(chip, MACDSP_API_TOA_ERR_SN_ADDR) & ~((u32)0x000F0000)) | ((u32)toasn << 16));
}

static inline u16 macdsp_api_toa_err_sn_toa_err_sn_reserved_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TOA_ERR_SN_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_toa_err_sn_toa_err_sn_reserved_0_setf(struct cl_chip *chip, u16 toaerrsnreserved0)
{
	ASSERT_ERR_CHIP((((u32)toaerrsnreserved0 << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TOA_ERR_SN_ADDR, (cl_reg_read(chip, MACDSP_API_TOA_ERR_SN_ADDR) & ~((u32)0x0000FFFF)) | ((u32)toaerrsnreserved0 << 0));
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
#define MACDSP_API_TRIGGER_TB_PARM_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000058)
#define MACDSP_API_TRIGGER_TB_PARM_OFFSET      0x00000058
#define MACDSP_API_TRIGGER_TB_PARM_INDEX       0x00000016
#define MACDSP_API_TRIGGER_TB_PARM_RESET       0x00000000

static inline u32 macdsp_api_trigger_tb_parm_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TRIGGER_TB_PARM_ADDR);
}

static inline void macdsp_api_trigger_tb_parm_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TRIGGER_TB_PARM_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TRIGGER_TB_PARM_TRIGGER_TB_PARM_RESERVED_0_MASK    ((u32)0xFFFFF800)
#define MACDSP_API_TRIGGER_TB_PARM_TRIGGER_TB_PARM_RESERVED_0_LSB    11
#define MACDSP_API_TRIGGER_TB_PARM_TRIGGER_TB_PARM_RESERVED_0_WIDTH    ((u32)0x00000015)
#define MACDSP_API_TRIGGER_TB_PARM_MU_TYPE_BIT    ((u32)0x00000400)
#define MACDSP_API_TRIGGER_TB_PARM_MU_TYPE_POS    10
#define MACDSP_API_TRIGGER_TB_PARM_FRAME_BW_MASK    ((u32)0x00000300)
#define MACDSP_API_TRIGGER_TB_PARM_FRAME_BW_LSB    8
#define MACDSP_API_TRIGGER_TB_PARM_FRAME_BW_WIDTH    ((u32)0x00000002)
#define MACDSP_API_TRIGGER_TB_PARM_NUM_USER_MASK    ((u32)0x000000FF)
#define MACDSP_API_TRIGGER_TB_PARM_NUM_USER_LSB    0
#define MACDSP_API_TRIGGER_TB_PARM_NUM_USER_WIDTH    ((u32)0x00000008)

#define MACDSP_API_TRIGGER_TB_PARM_TRIGGER_TB_PARM_RESERVED_0_RST    0x0
#define MACDSP_API_TRIGGER_TB_PARM_MU_TYPE_RST    0x0
#define MACDSP_API_TRIGGER_TB_PARM_FRAME_BW_RST    0x0
#define MACDSP_API_TRIGGER_TB_PARM_NUM_USER_RST    0x0

static inline void macdsp_api_trigger_tb_parm_pack(struct cl_chip *chip, u32 trigger_tb_parm_reserved0, u8 mu_type, u8 frame_bw, u8 num_user)
{
	ASSERT_ERR_CHIP((((u32)trigger_tb_parm_reserved0 << 11) & ~((u32)0xFFFFF800)) == 0);
	ASSERT_ERR_CHIP((((u32)mu_type << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)frame_bw << 8) & ~((u32)0x00000300)) == 0);
	ASSERT_ERR_CHIP((((u32)num_user << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MACDSP_API_TRIGGER_TB_PARM_ADDR, ((u32)trigger_tb_parm_reserved0 << 11) | ((u32)mu_type << 10) | ((u32)frame_bw << 8) | ((u32)num_user << 0));
}

static inline void macdsp_api_trigger_tb_parm_unpack(struct cl_chip *chip, u32 *trigger_tb_parm_reserved0, u8 *mu_type, u8 *frame_bw, u8 *num_user)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TRIGGER_TB_PARM_ADDR);

	*trigger_tb_parm_reserved0 = (local_val & ((u32)0xFFFFF800)) >> 11;
	*mu_type = (local_val & ((u32)0x00000400)) >> 10;
	*frame_bw = (local_val & ((u32)0x00000300)) >> 8;
	*num_user = (local_val & ((u32)0x000000FF)) >> 0;
}

static inline u32 macdsp_api_trigger_tb_parm_trigger_tb_parm_reserved_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TRIGGER_TB_PARM_ADDR);

	return (u32)((local_val & ((u32)0xFFFFF800)) >> 11);
}

static inline void macdsp_api_trigger_tb_parm_trigger_tb_parm_reserved_0_setf(struct cl_chip *chip, u32 triggertbparmreserved0)
{
	ASSERT_ERR_CHIP((((u32)triggertbparmreserved0 << 11) & ~((u32)0xFFFFF800)) == 0);
	cl_reg_write(chip, MACDSP_API_TRIGGER_TB_PARM_ADDR, (cl_reg_read(chip, MACDSP_API_TRIGGER_TB_PARM_ADDR) & ~((u32)0xFFFFF800)) | ((u32)triggertbparmreserved0 << 11));
}

static inline u8 macdsp_api_trigger_tb_parm_mu_type_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TRIGGER_TB_PARM_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void macdsp_api_trigger_tb_parm_mu_type_setf(struct cl_chip *chip, u8 mutype)
{
	ASSERT_ERR_CHIP((((u32)mutype << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, MACDSP_API_TRIGGER_TB_PARM_ADDR, (cl_reg_read(chip, MACDSP_API_TRIGGER_TB_PARM_ADDR) & ~((u32)0x00000400)) | ((u32)mutype << 10));
}

static inline u8 macdsp_api_trigger_tb_parm_frame_bw_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TRIGGER_TB_PARM_ADDR);

	return (u8)((local_val & ((u32)0x00000300)) >> 8);
}

static inline void macdsp_api_trigger_tb_parm_frame_bw_setf(struct cl_chip *chip, u8 framebw)
{
	ASSERT_ERR_CHIP((((u32)framebw << 8) & ~((u32)0x00000300)) == 0);
	cl_reg_write(chip, MACDSP_API_TRIGGER_TB_PARM_ADDR, (cl_reg_read(chip, MACDSP_API_TRIGGER_TB_PARM_ADDR) & ~((u32)0x00000300)) | ((u32)framebw << 8));
}

static inline u8 macdsp_api_trigger_tb_parm_num_user_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TRIGGER_TB_PARM_ADDR);

	return (u8)((local_val & ((u32)0x000000FF)) >> 0);
}

static inline void macdsp_api_trigger_tb_parm_num_user_setf(struct cl_chip *chip, u8 numuser)
{
	ASSERT_ERR_CHIP((((u32)numuser << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MACDSP_API_TRIGGER_TB_PARM_ADDR, (cl_reg_read(chip, MACDSP_API_TRIGGER_TB_PARM_ADDR) & ~((u32)0x000000FF)) | ((u32)numuser << 0));
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
#define MACDSP_API_PHY_ERROR_REASON_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000005C)
#define MACDSP_API_PHY_ERROR_REASON_OFFSET      0x0000005C
#define MACDSP_API_PHY_ERROR_REASON_INDEX       0x00000017
#define MACDSP_API_PHY_ERROR_REASON_RESET       0x00000000

static inline u32 macdsp_api_phy_error_reason_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_PHY_ERROR_REASON_ADDR);
}

static inline void macdsp_api_phy_error_reason_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_PHY_ERROR_REASON_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_PHY_ERROR_REASON_ERROR_DETAILS_MASK    ((u32)0xFFFFFF00)
#define MACDSP_API_PHY_ERROR_REASON_ERROR_DETAILS_LSB    8
#define MACDSP_API_PHY_ERROR_REASON_ERROR_DETAILS_WIDTH    ((u32)0x00000018)
#define MACDSP_API_PHY_ERROR_REASON_AUTO_RESPONSE_BIT    ((u32)0x00000080)
#define MACDSP_API_PHY_ERROR_REASON_AUTO_RESPONSE_POS    7
#define MACDSP_API_PHY_ERROR_REASON_ERROR_REASON_MASK    ((u32)0x0000007F)
#define MACDSP_API_PHY_ERROR_REASON_ERROR_REASON_LSB    0
#define MACDSP_API_PHY_ERROR_REASON_ERROR_REASON_WIDTH    ((u32)0x00000007)

#define MACDSP_API_PHY_ERROR_REASON_ERROR_DETAILS_RST    0x0
#define MACDSP_API_PHY_ERROR_REASON_AUTO_RESPONSE_RST    0x0
#define MACDSP_API_PHY_ERROR_REASON_ERROR_REASON_RST    0x0

static inline void macdsp_api_phy_error_reason_pack(struct cl_chip *chip, u32 error_details, u8 auto_response, u8 error_reason)
{
	ASSERT_ERR_CHIP((((u32)error_details << 8) & ~((u32)0xFFFFFF00)) == 0);
	ASSERT_ERR_CHIP((((u32)auto_response << 7) & ~((u32)0x00000080)) == 0);
	ASSERT_ERR_CHIP((((u32)error_reason << 0) & ~((u32)0x0000007F)) == 0);
	cl_reg_write(chip, MACDSP_API_PHY_ERROR_REASON_ADDR, ((u32)error_details << 8) | ((u32)auto_response << 7) | ((u32)error_reason << 0));
}

static inline void macdsp_api_phy_error_reason_unpack(struct cl_chip *chip, u32 *error_details, u8 *auto_response, u8 *error_reason)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_PHY_ERROR_REASON_ADDR);

	*error_details = (local_val & ((u32)0xFFFFFF00)) >> 8;
	*auto_response = (local_val & ((u32)0x00000080)) >> 7;
	*error_reason = (local_val & ((u32)0x0000007F)) >> 0;
}

static inline u32 macdsp_api_phy_error_reason_error_details_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_PHY_ERROR_REASON_ADDR);

	return (u32)((local_val & ((u32)0xFFFFFF00)) >> 8);
}

static inline void macdsp_api_phy_error_reason_error_details_setf(struct cl_chip *chip, u32 errordetails)
{
	ASSERT_ERR_CHIP((((u32)errordetails << 8) & ~((u32)0xFFFFFF00)) == 0);
	cl_reg_write(chip, MACDSP_API_PHY_ERROR_REASON_ADDR, (cl_reg_read(chip, MACDSP_API_PHY_ERROR_REASON_ADDR) & ~((u32)0xFFFFFF00)) | ((u32)errordetails << 8));
}

static inline u8 macdsp_api_phy_error_reason_auto_response_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_PHY_ERROR_REASON_ADDR);

	return (u8)((local_val & ((u32)0x00000080)) >> 7);
}

static inline void macdsp_api_phy_error_reason_auto_response_setf(struct cl_chip *chip, u8 autoresponse)
{
	ASSERT_ERR_CHIP((((u32)autoresponse << 7) & ~((u32)0x00000080)) == 0);
	cl_reg_write(chip, MACDSP_API_PHY_ERROR_REASON_ADDR, (cl_reg_read(chip, MACDSP_API_PHY_ERROR_REASON_ADDR) & ~((u32)0x00000080)) | ((u32)autoresponse << 7));
}

static inline u8 macdsp_api_phy_error_reason_error_reason_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_PHY_ERROR_REASON_ADDR);

	return (u8)((local_val & ((u32)0x0000007F)) >> 0);
}

static inline void macdsp_api_phy_error_reason_error_reason_setf(struct cl_chip *chip, u8 errorreason)
{
	ASSERT_ERR_CHIP((((u32)errorreason << 0) & ~((u32)0x0000007F)) == 0);
	cl_reg_write(chip, MACDSP_API_PHY_ERROR_REASON_ADDR, (cl_reg_read(chip, MACDSP_API_PHY_ERROR_REASON_ADDR) & ~((u32)0x0000007F)) | ((u32)errorreason << 0));
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
#define MACDSP_API_VGEN_REQ_PART_1_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000060)
#define MACDSP_API_VGEN_REQ_PART_1_OFFSET      0x00000060
#define MACDSP_API_VGEN_REQ_PART_1_INDEX       0x00000018
#define MACDSP_API_VGEN_REQ_PART_1_RESET       0x00000000

static inline u32 macdsp_api_vgen_req_part_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR);
}

static inline void macdsp_api_vgen_req_part_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_DIALOG_TOKEN_MASK    ((u32)0xFF000000)
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_DIALOG_TOKEN_LSB    24
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_DIALOG_TOKEN_WIDTH    ((u32)0x00000008)
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_RESERVED_MASK    ((u32)0x00E00000)
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_RESERVED_LSB    21
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_RESERVED_WIDTH    ((u32)0x00000003)
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_CQI_BIT    ((u32)0x00100000)
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_CQI_POS    20
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_GROUPING_MASK    ((u32)0x000F0000)
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_GROUPING_LSB    16
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_GROUPING_WIDTH    ((u32)0x00000004)
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_CODEBOOK_INFORMATION_MASK    ((u32)0x0000E000)
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_CODEBOOK_INFORMATION_LSB    13
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_CODEBOOK_INFORMATION_WIDTH    ((u32)0x00000003)
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_NC_INDEX_MASK    ((u32)0x00001C00)
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_NC_INDEX_LSB    10
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_NC_INDEX_WIDTH    ((u32)0x00000003)
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_FEEDBACK_TYPE_MASK    ((u32)0x00000300)
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_FEEDBACK_TYPE_LSB    8
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_FEEDBACK_TYPE_WIDTH    ((u32)0x00000002)
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_SOUNDING_TYPE_BIT    ((u32)0x00000080)
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_SOUNDING_TYPE_POS    7
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_FORMAT_MASK    ((u32)0x00000060)
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_FORMAT_LSB    5
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_FORMAT_WIDTH    ((u32)0x00000002)
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_REQUEST_VALID_BIT    ((u32)0x00000010)
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_REQUEST_VALID_POS    4
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_REQUEST_SEQUENCE_ID_MASK    ((u32)0x0000000F)
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_REQUEST_SEQUENCE_ID_LSB    0
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_REQUEST_SEQUENCE_ID_WIDTH    ((u32)0x00000004)

#define MACDSP_API_VGEN_REQ_PART_1_VGEN_DIALOG_TOKEN_RST    0x0
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_RESERVED_RST    0x0
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_CQI_RST    0x0
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_GROUPING_RST    0x0
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_CODEBOOK_INFORMATION_RST    0x0
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_NC_INDEX_RST    0x0
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_FEEDBACK_TYPE_RST    0x0
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_SOUNDING_TYPE_RST    0x0
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_FORMAT_RST    0x0
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_REQUEST_VALID_RST    0x0
#define MACDSP_API_VGEN_REQ_PART_1_VGEN_REQUEST_SEQUENCE_ID_RST    0x0

static inline void macdsp_api_vgen_req_part_1_pack(struct cl_chip *chip, u8 vgen_dialog_token, u8 vgen_reserved, u8 vgen_cqi, u8 vgen_grouping, u8 vgen_codebook_information, u8 vgen_nc_index, u8 vgen_feedback_type, u8 vgen_sounding_type, u8 vgen_format, u8 vgen_request_valid, u8 vgen_request_sequence_id)
{
	ASSERT_ERR_CHIP((((u32)vgen_dialog_token << 24) & ~((u32)0xFF000000)) == 0);
	ASSERT_ERR_CHIP((((u32)vgen_reserved << 21) & ~((u32)0x00E00000)) == 0);
	ASSERT_ERR_CHIP((((u32)vgen_cqi << 20) & ~((u32)0x00100000)) == 0);
	ASSERT_ERR_CHIP((((u32)vgen_grouping << 16) & ~((u32)0x000F0000)) == 0);
	ASSERT_ERR_CHIP((((u32)vgen_codebook_information << 13) & ~((u32)0x0000E000)) == 0);
	ASSERT_ERR_CHIP((((u32)vgen_nc_index << 10) & ~((u32)0x00001C00)) == 0);
	ASSERT_ERR_CHIP((((u32)vgen_feedback_type << 8) & ~((u32)0x00000300)) == 0);
	ASSERT_ERR_CHIP((((u32)vgen_sounding_type << 7) & ~((u32)0x00000080)) == 0);
	ASSERT_ERR_CHIP((((u32)vgen_format << 5) & ~((u32)0x00000060)) == 0);
	ASSERT_ERR_CHIP((((u32)vgen_request_valid << 4) & ~((u32)0x00000010)) == 0);
	ASSERT_ERR_CHIP((((u32)vgen_request_sequence_id << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR, ((u32)vgen_dialog_token << 24) | ((u32)vgen_reserved << 21) | ((u32)vgen_cqi << 20) | ((u32)vgen_grouping << 16) | ((u32)vgen_codebook_information << 13) | ((u32)vgen_nc_index << 10) | ((u32)vgen_feedback_type << 8) | ((u32)vgen_sounding_type << 7) | ((u32)vgen_format << 5) | ((u32)vgen_request_valid << 4) | ((u32)vgen_request_sequence_id << 0));
}

static inline void macdsp_api_vgen_req_part_1_unpack(struct cl_chip *chip, u8 *vgen_dialog_token, u8 *vgen_reserved, u8 *vgen_cqi, u8 *vgen_grouping, u8 *vgen_codebook_information, u8 *vgen_nc_index, u8 *vgen_feedback_type, u8 *vgen_sounding_type, u8 *vgen_format, u8 *vgen_request_valid, u8 *vgen_request_sequence_id)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR);

	*vgen_dialog_token = (local_val & ((u32)0xFF000000)) >> 24;
	*vgen_reserved = (local_val & ((u32)0x00E00000)) >> 21;
	*vgen_cqi = (local_val & ((u32)0x00100000)) >> 20;
	*vgen_grouping = (local_val & ((u32)0x000F0000)) >> 16;
	*vgen_codebook_information = (local_val & ((u32)0x0000E000)) >> 13;
	*vgen_nc_index = (local_val & ((u32)0x00001C00)) >> 10;
	*vgen_feedback_type = (local_val & ((u32)0x00000300)) >> 8;
	*vgen_sounding_type = (local_val & ((u32)0x00000080)) >> 7;
	*vgen_format = (local_val & ((u32)0x00000060)) >> 5;
	*vgen_request_valid = (local_val & ((u32)0x00000010)) >> 4;
	*vgen_request_sequence_id = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 macdsp_api_vgen_req_part_1_vgen_dialog_token_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR);

	return (u8)((local_val & ((u32)0xFF000000)) >> 24);
}

static inline void macdsp_api_vgen_req_part_1_vgen_dialog_token_setf(struct cl_chip *chip, u8 vgendialogtoken)
{
	ASSERT_ERR_CHIP((((u32)vgendialogtoken << 24) & ~((u32)0xFF000000)) == 0);
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR, (cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR) & ~((u32)0xFF000000)) | ((u32)vgendialogtoken << 24));
}

static inline u8 macdsp_api_vgen_req_part_1_vgen_reserved_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR);

	return (u8)((local_val & ((u32)0x00E00000)) >> 21);
}

static inline void macdsp_api_vgen_req_part_1_vgen_reserved_setf(struct cl_chip *chip, u8 vgenreserved)
{
	ASSERT_ERR_CHIP((((u32)vgenreserved << 21) & ~((u32)0x00E00000)) == 0);
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR, (cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR) & ~((u32)0x00E00000)) | ((u32)vgenreserved << 21));
}

static inline u8 macdsp_api_vgen_req_part_1_vgen_cqi_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR);

	return (u8)((local_val & ((u32)0x00100000)) >> 20);
}

static inline void macdsp_api_vgen_req_part_1_vgen_cqi_setf(struct cl_chip *chip, u8 vgencqi)
{
	ASSERT_ERR_CHIP((((u32)vgencqi << 20) & ~((u32)0x00100000)) == 0);
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR, (cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR) & ~((u32)0x00100000)) | ((u32)vgencqi << 20));
}

static inline u8 macdsp_api_vgen_req_part_1_vgen_grouping_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR);

	return (u8)((local_val & ((u32)0x000F0000)) >> 16);
}

static inline void macdsp_api_vgen_req_part_1_vgen_grouping_setf(struct cl_chip *chip, u8 vgengrouping)
{
	ASSERT_ERR_CHIP((((u32)vgengrouping << 16) & ~((u32)0x000F0000)) == 0);
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR, (cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR) & ~((u32)0x000F0000)) | ((u32)vgengrouping << 16));
}

static inline u8 macdsp_api_vgen_req_part_1_vgen_codebook_information_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR);

	return (u8)((local_val & ((u32)0x0000E000)) >> 13);
}

static inline void macdsp_api_vgen_req_part_1_vgen_codebook_information_setf(struct cl_chip *chip, u8 vgencodebookinformation)
{
	ASSERT_ERR_CHIP((((u32)vgencodebookinformation << 13) & ~((u32)0x0000E000)) == 0);
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR, (cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR) & ~((u32)0x0000E000)) | ((u32)vgencodebookinformation << 13));
}

static inline u8 macdsp_api_vgen_req_part_1_vgen_nc_index_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR);

	return (u8)((local_val & ((u32)0x00001C00)) >> 10);
}

static inline void macdsp_api_vgen_req_part_1_vgen_nc_index_setf(struct cl_chip *chip, u8 vgenncindex)
{
	ASSERT_ERR_CHIP((((u32)vgenncindex << 10) & ~((u32)0x00001C00)) == 0);
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR, (cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR) & ~((u32)0x00001C00)) | ((u32)vgenncindex << 10));
}

static inline u8 macdsp_api_vgen_req_part_1_vgen_feedback_type_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR);

	return (u8)((local_val & ((u32)0x00000300)) >> 8);
}

static inline void macdsp_api_vgen_req_part_1_vgen_feedback_type_setf(struct cl_chip *chip, u8 vgenfeedbacktype)
{
	ASSERT_ERR_CHIP((((u32)vgenfeedbacktype << 8) & ~((u32)0x00000300)) == 0);
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR, (cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR) & ~((u32)0x00000300)) | ((u32)vgenfeedbacktype << 8));
}

static inline u8 macdsp_api_vgen_req_part_1_vgen_sounding_type_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR);

	return (u8)((local_val & ((u32)0x00000080)) >> 7);
}

static inline void macdsp_api_vgen_req_part_1_vgen_sounding_type_setf(struct cl_chip *chip, u8 vgensoundingtype)
{
	ASSERT_ERR_CHIP((((u32)vgensoundingtype << 7) & ~((u32)0x00000080)) == 0);
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR, (cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR) & ~((u32)0x00000080)) | ((u32)vgensoundingtype << 7));
}

static inline u8 macdsp_api_vgen_req_part_1_vgen_format_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR);

	return (u8)((local_val & ((u32)0x00000060)) >> 5);
}

static inline void macdsp_api_vgen_req_part_1_vgen_format_setf(struct cl_chip *chip, u8 vgenformat)
{
	ASSERT_ERR_CHIP((((u32)vgenformat << 5) & ~((u32)0x00000060)) == 0);
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR, (cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR) & ~((u32)0x00000060)) | ((u32)vgenformat << 5));
}

static inline u8 macdsp_api_vgen_req_part_1_vgen_request_valid_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR);

	return (u8)((local_val & ((u32)0x00000010)) >> 4);
}

static inline void macdsp_api_vgen_req_part_1_vgen_request_valid_setf(struct cl_chip *chip, u8 vgenrequestvalid)
{
	ASSERT_ERR_CHIP((((u32)vgenrequestvalid << 4) & ~((u32)0x00000010)) == 0);
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR, (cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR) & ~((u32)0x00000010)) | ((u32)vgenrequestvalid << 4));
}

static inline u8 macdsp_api_vgen_req_part_1_vgen_request_sequence_id_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void macdsp_api_vgen_req_part_1_vgen_request_sequence_id_setf(struct cl_chip *chip, u8 vgenrequestsequenceid)
{
	ASSERT_ERR_CHIP((((u32)vgenrequestsequenceid << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR, (cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_1_ADDR) & ~((u32)0x0000000F)) | ((u32)vgenrequestsequenceid << 0));
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
#define MACDSP_API_VGEN_REQ_PART_2_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000064)
#define MACDSP_API_VGEN_REQ_PART_2_OFFSET      0x00000064
#define MACDSP_API_VGEN_REQ_PART_2_INDEX       0x00000019
#define MACDSP_API_VGEN_REQ_PART_2_RESET       0x00000000

static inline u32 macdsp_api_vgen_req_part_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_2_ADDR);
}

static inline void macdsp_api_vgen_req_part_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_2_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_VGEN_REQ_PART_2_VGEN_RESERVED_2_MASK    ((u32)0xFFC00000)
#define MACDSP_API_VGEN_REQ_PART_2_VGEN_RESERVED_2_LSB    22
#define MACDSP_API_VGEN_REQ_PART_2_VGEN_RESERVED_2_WIDTH    ((u32)0x0000000A)
#define MACDSP_API_VGEN_REQ_PART_2_VGEN_HEADER_LENGTH_MASK    ((u32)0x003F0000)
#define MACDSP_API_VGEN_REQ_PART_2_VGEN_HEADER_LENGTH_LSB    16
#define MACDSP_API_VGEN_REQ_PART_2_VGEN_HEADER_LENGTH_WIDTH    ((u32)0x00000006)
#define MACDSP_API_VGEN_REQ_PART_2_VGEN_RESERVED_1_MASK    ((u32)0x0000C000)
#define MACDSP_API_VGEN_REQ_PART_2_VGEN_RESERVED_1_LSB    14
#define MACDSP_API_VGEN_REQ_PART_2_VGEN_RESERVED_1_WIDTH    ((u32)0x00000002)
#define MACDSP_API_VGEN_REQ_PART_2_VGEN_RU_END_INDEX_MASK    ((u32)0x00003F80)
#define MACDSP_API_VGEN_REQ_PART_2_VGEN_RU_END_INDEX_LSB    7
#define MACDSP_API_VGEN_REQ_PART_2_VGEN_RU_END_INDEX_WIDTH    ((u32)0x00000007)
#define MACDSP_API_VGEN_REQ_PART_2_VGEN_RU_START_INDEX_MASK    ((u32)0x0000007F)
#define MACDSP_API_VGEN_REQ_PART_2_VGEN_RU_START_INDEX_LSB    0
#define MACDSP_API_VGEN_REQ_PART_2_VGEN_RU_START_INDEX_WIDTH    ((u32)0x00000007)

#define MACDSP_API_VGEN_REQ_PART_2_VGEN_RESERVED_2_RST    0x0
#define MACDSP_API_VGEN_REQ_PART_2_VGEN_HEADER_LENGTH_RST    0x0
#define MACDSP_API_VGEN_REQ_PART_2_VGEN_RESERVED_1_RST    0x0
#define MACDSP_API_VGEN_REQ_PART_2_VGEN_RU_END_INDEX_RST    0x0
#define MACDSP_API_VGEN_REQ_PART_2_VGEN_RU_START_INDEX_RST    0x0

static inline void macdsp_api_vgen_req_part_2_pack(struct cl_chip *chip, u16 vgen_reserved2, u8 vgen_header_length, u8 vgen_reserved1, u8 vgen_ru_end_index, u8 vgen_ru_start_index)
{
	ASSERT_ERR_CHIP((((u32)vgen_reserved2 << 22) & ~((u32)0xFFC00000)) == 0);
	ASSERT_ERR_CHIP((((u32)vgen_header_length << 16) & ~((u32)0x003F0000)) == 0);
	ASSERT_ERR_CHIP((((u32)vgen_reserved1 << 14) & ~((u32)0x0000C000)) == 0);
	ASSERT_ERR_CHIP((((u32)vgen_ru_end_index << 7) & ~((u32)0x00003F80)) == 0);
	ASSERT_ERR_CHIP((((u32)vgen_ru_start_index << 0) & ~((u32)0x0000007F)) == 0);
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_2_ADDR, ((u32)vgen_reserved2 << 22) | ((u32)vgen_header_length << 16) | ((u32)vgen_reserved1 << 14) | ((u32)vgen_ru_end_index << 7) | ((u32)vgen_ru_start_index << 0));
}

static inline void macdsp_api_vgen_req_part_2_unpack(struct cl_chip *chip, u16 *vgen_reserved2, u8 *vgen_header_length, u8 *vgen_reserved1, u8 *vgen_ru_end_index, u8 *vgen_ru_start_index)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_2_ADDR);

	*vgen_reserved2 = (local_val & ((u32)0xFFC00000)) >> 22;
	*vgen_header_length = (local_val & ((u32)0x003F0000)) >> 16;
	*vgen_reserved1 = (local_val & ((u32)0x0000C000)) >> 14;
	*vgen_ru_end_index = (local_val & ((u32)0x00003F80)) >> 7;
	*vgen_ru_start_index = (local_val & ((u32)0x0000007F)) >> 0;
}

static inline u16 macdsp_api_vgen_req_part_2_vgen_reserved_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_2_ADDR);

	return (u16)((local_val & ((u32)0xFFC00000)) >> 22);
}

static inline void macdsp_api_vgen_req_part_2_vgen_reserved_2_setf(struct cl_chip *chip, u16 vgenreserved2)
{
	ASSERT_ERR_CHIP((((u32)vgenreserved2 << 22) & ~((u32)0xFFC00000)) == 0);
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_2_ADDR, (cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_2_ADDR) & ~((u32)0xFFC00000)) | ((u32)vgenreserved2 << 22));
}

static inline u8 macdsp_api_vgen_req_part_2_vgen_header_length_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_2_ADDR);

	return (u8)((local_val & ((u32)0x003F0000)) >> 16);
}

static inline void macdsp_api_vgen_req_part_2_vgen_header_length_setf(struct cl_chip *chip, u8 vgenheaderlength)
{
	ASSERT_ERR_CHIP((((u32)vgenheaderlength << 16) & ~((u32)0x003F0000)) == 0);
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_2_ADDR, (cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_2_ADDR) & ~((u32)0x003F0000)) | ((u32)vgenheaderlength << 16));
}

static inline u8 macdsp_api_vgen_req_part_2_vgen_reserved_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_2_ADDR);

	return (u8)((local_val & ((u32)0x0000C000)) >> 14);
}

static inline void macdsp_api_vgen_req_part_2_vgen_reserved_1_setf(struct cl_chip *chip, u8 vgenreserved1)
{
	ASSERT_ERR_CHIP((((u32)vgenreserved1 << 14) & ~((u32)0x0000C000)) == 0);
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_2_ADDR, (cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_2_ADDR) & ~((u32)0x0000C000)) | ((u32)vgenreserved1 << 14));
}

static inline u8 macdsp_api_vgen_req_part_2_vgen_ru_end_index_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_2_ADDR);

	return (u8)((local_val & ((u32)0x00003F80)) >> 7);
}

static inline void macdsp_api_vgen_req_part_2_vgen_ru_end_index_setf(struct cl_chip *chip, u8 vgenruendindex)
{
	ASSERT_ERR_CHIP((((u32)vgenruendindex << 7) & ~((u32)0x00003F80)) == 0);
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_2_ADDR, (cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_2_ADDR) & ~((u32)0x00003F80)) | ((u32)vgenruendindex << 7));
}

static inline u8 macdsp_api_vgen_req_part_2_vgen_ru_start_index_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_2_ADDR);

	return (u8)((local_val & ((u32)0x0000007F)) >> 0);
}

static inline void macdsp_api_vgen_req_part_2_vgen_ru_start_index_setf(struct cl_chip *chip, u8 vgenrustartindex)
{
	ASSERT_ERR_CHIP((((u32)vgenrustartindex << 0) & ~((u32)0x0000007F)) == 0);
	cl_reg_write(chip, MACDSP_API_VGEN_REQ_PART_2_ADDR, (cl_reg_read(chip, MACDSP_API_VGEN_REQ_PART_2_ADDR) & ~((u32)0x0000007F)) | ((u32)vgenrustartindex << 0));
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
#define MACDSP_API_FREQUENCY_OFFSET_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000068)
#define MACDSP_API_FREQUENCY_OFFSET_OFFSET      0x00000068
#define MACDSP_API_FREQUENCY_OFFSET_INDEX       0x0000001A
#define MACDSP_API_FREQUENCY_OFFSET_RESET       0x00000000

static inline u32 macdsp_api_frequency_offset_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_FREQUENCY_OFFSET_ADDR);
}

static inline void macdsp_api_frequency_offset_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_FREQUENCY_OFFSET_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_FREQUENCY_OFFSET_FREQUENCY_OFFSET_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_FREQUENCY_OFFSET_FREQUENCY_OFFSET_LSB    0
#define MACDSP_API_FREQUENCY_OFFSET_FREQUENCY_OFFSET_WIDTH    ((u32)0x00000020)

#define MACDSP_API_FREQUENCY_OFFSET_FREQUENCY_OFFSET_RST    0x0

static inline u32 macdsp_api_frequency_offset_frequency_offset_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_FREQUENCY_OFFSET_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_frequency_offset_frequency_offset_setf(struct cl_chip *chip, u32 frequencyoffset)
{
	ASSERT_ERR_CHIP((((u32)frequencyoffset << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_FREQUENCY_OFFSET_ADDR, (u32)frequencyoffset << 0);
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
#define MACDSP_API_STA_CONF_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000006C)
#define MACDSP_API_STA_CONF_OFFSET      0x0000006C
#define MACDSP_API_STA_CONF_INDEX       0x0000001B
#define MACDSP_API_STA_CONF_RESET       0x00000000

static inline u32 macdsp_api_sta_conf_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_STA_CONF_ADDR);
}

static inline void macdsp_api_sta_conf_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_STA_CONF_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_STA_CONF_HE_STA_ID_MASK    ((u32)0x000007FF)
#define MACDSP_API_STA_CONF_HE_STA_ID_LSB    0
#define MACDSP_API_STA_CONF_HE_STA_ID_WIDTH    ((u32)0x0000000B)

#define MACDSP_API_STA_CONF_HE_STA_ID_RST    0x0

static inline u16 macdsp_api_sta_conf_he_sta_id_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_STA_CONF_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_sta_conf_he_sta_id_setf(struct cl_chip *chip, u16 hestaid)
{
	ASSERT_ERR_CHIP((((u32)hestaid << 0) & ~((u32)0x000007FF)) == 0);
	cl_reg_write(chip, MACDSP_API_STA_CONF_ADDR, (u32)hestaid << 0);
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
#define MACDSP_API_CARRIER_FREQ_MHZ_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000070)
#define MACDSP_API_CARRIER_FREQ_MHZ_OFFSET      0x00000070
#define MACDSP_API_CARRIER_FREQ_MHZ_INDEX       0x0000001C
#define MACDSP_API_CARRIER_FREQ_MHZ_RESET       0x00000000

static inline u32 macdsp_api_carrier_freq_mhz_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_CARRIER_FREQ_MHZ_ADDR);
}

static inline void macdsp_api_carrier_freq_mhz_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_CARRIER_FREQ_MHZ_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_CARRIER_FREQ_MHZ_CARRIER_FREQ_MHZ_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_CARRIER_FREQ_MHZ_CARRIER_FREQ_MHZ_LSB    0
#define MACDSP_API_CARRIER_FREQ_MHZ_CARRIER_FREQ_MHZ_WIDTH    ((u32)0x00000020)

#define MACDSP_API_CARRIER_FREQ_MHZ_CARRIER_FREQ_MHZ_RST    0x0

static inline u32 macdsp_api_carrier_freq_mhz_carrier_freq_mhz_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CARRIER_FREQ_MHZ_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_carrier_freq_mhz_carrier_freq_mhz_setf(struct cl_chip *chip, u32 carrierfreqmhz)
{
	ASSERT_ERR_CHIP((((u32)carrierfreqmhz << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_CARRIER_FREQ_MHZ_ADDR, (u32)carrierfreqmhz << 0);
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
#define MACDSP_API_TX_DIG_GAIN_SINGLE_ANT_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000074)
#define MACDSP_API_TX_DIG_GAIN_SINGLE_ANT_OFFSET      0x00000074
#define MACDSP_API_TX_DIG_GAIN_SINGLE_ANT_INDEX       0x0000001D
#define MACDSP_API_TX_DIG_GAIN_SINGLE_ANT_RESET       0x00000000

static inline u32 macdsp_api_tx_dig_gain_single_ant_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TX_DIG_GAIN_SINGLE_ANT_ADDR);
}

static inline void macdsp_api_tx_dig_gain_single_ant_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TX_DIG_GAIN_SINGLE_ANT_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TX_DIG_GAIN_SINGLE_ANT_TX_DIG_GAIN_SINGLE_ANT_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_TX_DIG_GAIN_SINGLE_ANT_TX_DIG_GAIN_SINGLE_ANT_LSB    0
#define MACDSP_API_TX_DIG_GAIN_SINGLE_ANT_TX_DIG_GAIN_SINGLE_ANT_WIDTH    ((u32)0x00000020)

#define MACDSP_API_TX_DIG_GAIN_SINGLE_ANT_TX_DIG_GAIN_SINGLE_ANT_RST    0x0

static inline u32 macdsp_api_tx_dig_gain_single_ant_tx_dig_gain_single_ant_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_DIG_GAIN_SINGLE_ANT_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_tx_dig_gain_single_ant_tx_dig_gain_single_ant_setf(struct cl_chip *chip, u32 txdiggainsingleant)
{
	ASSERT_ERR_CHIP((((u32)txdiggainsingleant << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_DIG_GAIN_SINGLE_ANT_ADDR, (u32)txdiggainsingleant << 0);
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
#define MACDSP_API_TX_DIG_GAIN_ALL_ANTS_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000078)
#define MACDSP_API_TX_DIG_GAIN_ALL_ANTS_OFFSET      0x00000078
#define MACDSP_API_TX_DIG_GAIN_ALL_ANTS_INDEX       0x0000001E
#define MACDSP_API_TX_DIG_GAIN_ALL_ANTS_RESET       0x00000000

static inline u32 macdsp_api_tx_dig_gain_all_ants_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TX_DIG_GAIN_ALL_ANTS_ADDR);
}

static inline void macdsp_api_tx_dig_gain_all_ants_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TX_DIG_GAIN_ALL_ANTS_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TX_DIG_GAIN_ALL_ANTS_TX_DIG_GAIN_ALL_ANTS_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_TX_DIG_GAIN_ALL_ANTS_TX_DIG_GAIN_ALL_ANTS_LSB    0
#define MACDSP_API_TX_DIG_GAIN_ALL_ANTS_TX_DIG_GAIN_ALL_ANTS_WIDTH    ((u32)0x00000020)

#define MACDSP_API_TX_DIG_GAIN_ALL_ANTS_TX_DIG_GAIN_ALL_ANTS_RST    0x0

static inline u32 macdsp_api_tx_dig_gain_all_ants_tx_dig_gain_all_ants_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_DIG_GAIN_ALL_ANTS_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_tx_dig_gain_all_ants_tx_dig_gain_all_ants_setf(struct cl_chip *chip, u32 txdiggainallants)
{
	ASSERT_ERR_CHIP((((u32)txdiggainallants << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_DIG_GAIN_ALL_ANTS_ADDR, (u32)txdiggainallants << 0);
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
#define MACDSP_API_DSP_VER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000080)
#define MACDSP_API_DSP_VER_OFFSET      0x00000080
#define MACDSP_API_DSP_VER_INDEX       0x00000020
#define MACDSP_API_DSP_VER_RESET       0x00000000

static inline u32 macdsp_api_dsp_ver_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_DSP_VER_ADDR);
}

/* Field definitions */
#define MACDSP_API_DSP_VER_MAJOR_VERSION_NUMBER_MASK    ((u32)0xFF000000)
#define MACDSP_API_DSP_VER_MAJOR_VERSION_NUMBER_LSB    24
#define MACDSP_API_DSP_VER_MAJOR_VERSION_NUMBER_WIDTH    ((u32)0x00000008)
#define MACDSP_API_DSP_VER_MINOR_VERSION_NUMBER_MASK    ((u32)0x00FF0000)
#define MACDSP_API_DSP_VER_MINOR_VERSION_NUMBER_LSB    16
#define MACDSP_API_DSP_VER_MINOR_VERSION_NUMBER_WIDTH    ((u32)0x00000008)
#define MACDSP_API_DSP_VER_INTERNAL_VERSION_MASK    ((u32)0x0000FF00)
#define MACDSP_API_DSP_VER_INTERNAL_VERSION_LSB    8
#define MACDSP_API_DSP_VER_INTERNAL_VERSION_WIDTH    ((u32)0x00000008)
#define MACDSP_API_DSP_VER_HW_STEP_MASK     ((u32)0x000000F0)
#define MACDSP_API_DSP_VER_HW_STEP_LSB      4
#define MACDSP_API_DSP_VER_HW_STEP_WIDTH    ((u32)0x00000004)
#define MACDSP_API_DSP_VER_PLATFORM_TYPE_MASK    ((u32)0x0000000F)
#define MACDSP_API_DSP_VER_PLATFORM_TYPE_LSB    0
#define MACDSP_API_DSP_VER_PLATFORM_TYPE_WIDTH    ((u32)0x00000004)

#define MACDSP_API_DSP_VER_MAJOR_VERSION_NUMBER_RST    0x0
#define MACDSP_API_DSP_VER_MINOR_VERSION_NUMBER_RST    0x0
#define MACDSP_API_DSP_VER_INTERNAL_VERSION_RST    0x0
#define MACDSP_API_DSP_VER_HW_STEP_RST      0x0
#define MACDSP_API_DSP_VER_PLATFORM_TYPE_RST    0x0

static inline void macdsp_api_dsp_ver_unpack(struct cl_chip *chip, u8 *major_version_number, u8 *minor_version_number, u8 *internal_version, u8 *hw_step, u8 *platform_type)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_VER_ADDR);

	*major_version_number = (local_val & ((u32)0xFF000000)) >> 24;
	*minor_version_number = (local_val & ((u32)0x00FF0000)) >> 16;
	*internal_version = (local_val & ((u32)0x0000FF00)) >> 8;
	*hw_step = (local_val & ((u32)0x000000F0)) >> 4;
	*platform_type = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 macdsp_api_dsp_ver_major_version_number_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_VER_ADDR);

	return (u8)((local_val & ((u32)0xFF000000)) >> 24);
}

static inline u8 macdsp_api_dsp_ver_minor_version_number_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_VER_ADDR);

	return (u8)((local_val & ((u32)0x00FF0000)) >> 16);
}

static inline u8 macdsp_api_dsp_ver_internal_version_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_VER_ADDR);

	return (u8)((local_val & ((u32)0x0000FF00)) >> 8);
}

static inline u8 macdsp_api_dsp_ver_hw_step_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_VER_ADDR);

	return (u8)((local_val & ((u32)0x000000F0)) >> 4);
}

static inline u8 macdsp_api_dsp_ver_platform_type_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_VER_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
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
#define MACDSP_API_DSP_API_VER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000084)
#define MACDSP_API_DSP_API_VER_OFFSET      0x00000084
#define MACDSP_API_DSP_API_VER_INDEX       0x00000021
#define MACDSP_API_DSP_API_VER_RESET       0x00000010

static inline u32 macdsp_api_dsp_api_ver_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_DSP_API_VER_ADDR);
}

/* Field definitions */
#define MACDSP_API_DSP_API_VER_API_VERSION_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_DSP_API_VER_API_VERSION_LSB    0
#define MACDSP_API_DSP_API_VER_API_VERSION_WIDTH    ((u32)0x00000020)

#define MACDSP_API_DSP_API_VER_API_VERSION_RST    0x10

static inline u32 macdsp_api_dsp_api_ver_api_version_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_API_VER_ADDR);

	return (u32)(local_val >> 0);
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
#define MACDSP_API_PPS_SS_1_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000088)
#define MACDSP_API_PPS_SS_1_OFFSET      0x00000088
#define MACDSP_API_PPS_SS_1_INDEX       0x00000022
#define MACDSP_API_PPS_SS_1_RESET       0x00000000

static inline u32 macdsp_api_pps_ss_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_PPS_SS_1_ADDR);
}

/* Field definitions */
#define MACDSP_API_PPS_SS_1_POST_PROCESS_SNR_OF_SPATIAL_STREAM_1_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_PPS_SS_1_POST_PROCESS_SNR_OF_SPATIAL_STREAM_1_LSB    0
#define MACDSP_API_PPS_SS_1_POST_PROCESS_SNR_OF_SPATIAL_STREAM_1_WIDTH    ((u32)0x00000020)

#define MACDSP_API_PPS_SS_1_POST_PROCESS_SNR_OF_SPATIAL_STREAM_1_RST    0x0

static inline u32 macdsp_api_pps_ss_1_post_process_snr_of_spatial_stream_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_PPS_SS_1_ADDR);

	return (u32)(local_val >> 0);
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
#define MACDSP_API_PPS_SS_2_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000008C)
#define MACDSP_API_PPS_SS_2_OFFSET      0x0000008C
#define MACDSP_API_PPS_SS_2_INDEX       0x00000023
#define MACDSP_API_PPS_SS_2_RESET       0x00000000

static inline u32 macdsp_api_pps_ss_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_PPS_SS_2_ADDR);
}

/* Field definitions */
#define MACDSP_API_PPS_SS_2_POST_PROCESS_SNR_OF_SPATIAL_STREAM_2_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_PPS_SS_2_POST_PROCESS_SNR_OF_SPATIAL_STREAM_2_LSB    0
#define MACDSP_API_PPS_SS_2_POST_PROCESS_SNR_OF_SPATIAL_STREAM_2_WIDTH    ((u32)0x00000020)

#define MACDSP_API_PPS_SS_2_POST_PROCESS_SNR_OF_SPATIAL_STREAM_2_RST    0x0

static inline u32 macdsp_api_pps_ss_2_post_process_snr_of_spatial_stream_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_PPS_SS_2_ADDR);

	return (u32)(local_val >> 0);
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
#define MACDSP_API_PPS_SS_3_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000090)
#define MACDSP_API_PPS_SS_3_OFFSET      0x00000090
#define MACDSP_API_PPS_SS_3_INDEX       0x00000024
#define MACDSP_API_PPS_SS_3_RESET       0x00000000

static inline u32 macdsp_api_pps_ss_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_PPS_SS_3_ADDR);
}

/* Field definitions */
#define MACDSP_API_PPS_SS_3_POST_PROCESS_SNR_OF_SPATIAL_STREAM_3_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_PPS_SS_3_POST_PROCESS_SNR_OF_SPATIAL_STREAM_3_LSB    0
#define MACDSP_API_PPS_SS_3_POST_PROCESS_SNR_OF_SPATIAL_STREAM_3_WIDTH    ((u32)0x00000020)

#define MACDSP_API_PPS_SS_3_POST_PROCESS_SNR_OF_SPATIAL_STREAM_3_RST    0x0

static inline u32 macdsp_api_pps_ss_3_post_process_snr_of_spatial_stream_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_PPS_SS_3_ADDR);

	return (u32)(local_val >> 0);
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
#define MACDSP_API_PPS_SS_4_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000094)
#define MACDSP_API_PPS_SS_4_OFFSET      0x00000094
#define MACDSP_API_PPS_SS_4_INDEX       0x00000025
#define MACDSP_API_PPS_SS_4_RESET       0x00000000

static inline u32 macdsp_api_pps_ss_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_PPS_SS_4_ADDR);
}

/* Field definitions */
#define MACDSP_API_PPS_SS_4_POST_PROCESS_SNR_OF_SPATIAL_STREAM_4_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_PPS_SS_4_POST_PROCESS_SNR_OF_SPATIAL_STREAM_4_LSB    0
#define MACDSP_API_PPS_SS_4_POST_PROCESS_SNR_OF_SPATIAL_STREAM_4_WIDTH    ((u32)0x00000020)

#define MACDSP_API_PPS_SS_4_POST_PROCESS_SNR_OF_SPATIAL_STREAM_4_RST    0x0

static inline u32 macdsp_api_pps_ss_4_post_process_snr_of_spatial_stream_4_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_PPS_SS_4_ADDR);

	return (u32)(local_val >> 0);
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
#define MACDSP_API_FRAME_DESCRIPTION_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000098)
#define MACDSP_API_FRAME_DESCRIPTION_OFFSET      0x00000098
#define MACDSP_API_FRAME_DESCRIPTION_INDEX       0x00000026
#define MACDSP_API_FRAME_DESCRIPTION_RESET       0x00000000

static inline u32 macdsp_api_frame_description_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR);
}

static inline void macdsp_api_frame_description_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_FRAME_DESCRIPTION_LDPC_BLOCK_NUM_MASK    ((u32)0x7FFE0000)
#define MACDSP_API_FRAME_DESCRIPTION_LDPC_BLOCK_NUM_LSB    17
#define MACDSP_API_FRAME_DESCRIPTION_LDPC_BLOCK_NUM_WIDTH    ((u32)0x0000000E)
#define MACDSP_API_FRAME_DESCRIPTION_LDPC_ERROR_BIT    ((u32)0x00010000)
#define MACDSP_API_FRAME_DESCRIPTION_LDPC_ERROR_POS    16
#define MACDSP_API_FRAME_DESCRIPTION_EVM_GLITCH_BIT    ((u32)0x00008000)
#define MACDSP_API_FRAME_DESCRIPTION_EVM_GLITCH_POS    15
#define MACDSP_API_FRAME_DESCRIPTION_CODING_BIT    ((u32)0x00004000)
#define MACDSP_API_FRAME_DESCRIPTION_CODING_POS    14
#define MACDSP_API_FRAME_DESCRIPTION_GILTF_MASK    ((u32)0x00003000)
#define MACDSP_API_FRAME_DESCRIPTION_GILTF_LSB    12
#define MACDSP_API_FRAME_DESCRIPTION_GILTF_WIDTH    ((u32)0x00000002)
#define MACDSP_API_FRAME_DESCRIPTION_FRAME_DESCRIPTION_NSS_MASK    ((u32)0x00000C00)
#define MACDSP_API_FRAME_DESCRIPTION_FRAME_DESCRIPTION_NSS_LSB    10
#define MACDSP_API_FRAME_DESCRIPTION_FRAME_DESCRIPTION_NSS_WIDTH    ((u32)0x00000002)
#define MACDSP_API_FRAME_DESCRIPTION_MCS_MASK    ((u32)0x000003C0)
#define MACDSP_API_FRAME_DESCRIPTION_MCS_LSB    6
#define MACDSP_API_FRAME_DESCRIPTION_MCS_WIDTH    ((u32)0x00000004)
#define MACDSP_API_FRAME_DESCRIPTION_BW_MASK    ((u32)0x00000030)
#define MACDSP_API_FRAME_DESCRIPTION_BW_LSB    4
#define MACDSP_API_FRAME_DESCRIPTION_BW_WIDTH    ((u32)0x00000002)
#define MACDSP_API_FRAME_DESCRIPTION_FORMAT_MASK    ((u32)0x0000000F)
#define MACDSP_API_FRAME_DESCRIPTION_FORMAT_LSB    0
#define MACDSP_API_FRAME_DESCRIPTION_FORMAT_WIDTH    ((u32)0x00000004)

#define MACDSP_API_FRAME_DESCRIPTION_LDPC_BLOCK_NUM_RST    0x0
#define MACDSP_API_FRAME_DESCRIPTION_LDPC_ERROR_RST    0x0
#define MACDSP_API_FRAME_DESCRIPTION_EVM_GLITCH_RST    0x0
#define MACDSP_API_FRAME_DESCRIPTION_CODING_RST    0x0
#define MACDSP_API_FRAME_DESCRIPTION_GILTF_RST    0x0
#define MACDSP_API_FRAME_DESCRIPTION_FRAME_DESCRIPTION_NSS_RST    0x0
#define MACDSP_API_FRAME_DESCRIPTION_MCS_RST    0x0
#define MACDSP_API_FRAME_DESCRIPTION_BW_RST    0x0
#define MACDSP_API_FRAME_DESCRIPTION_FORMAT_RST    0x0

static inline void macdsp_api_frame_description_pack(struct cl_chip *chip, u16 ldpc_block_num, u8 ldpc_error, u8 evm_glitch, u8 coding, u8 giltf, u8 frame_description_nss, u8 mcs, u8 bw, u8 format)
{
	ASSERT_ERR_CHIP((((u32)ldpc_block_num << 17) & ~((u32)0x7FFE0000)) == 0);
	ASSERT_ERR_CHIP((((u32)ldpc_error << 16) & ~((u32)0x00010000)) == 0);
	ASSERT_ERR_CHIP((((u32)evm_glitch << 15) & ~((u32)0x00008000)) == 0);
	ASSERT_ERR_CHIP((((u32)coding << 14) & ~((u32)0x00004000)) == 0);
	ASSERT_ERR_CHIP((((u32)giltf << 12) & ~((u32)0x00003000)) == 0);
	ASSERT_ERR_CHIP((((u32)frame_description_nss << 10) & ~((u32)0x00000C00)) == 0);
	ASSERT_ERR_CHIP((((u32)mcs << 6) & ~((u32)0x000003C0)) == 0);
	ASSERT_ERR_CHIP((((u32)bw << 4) & ~((u32)0x00000030)) == 0);
	ASSERT_ERR_CHIP((((u32)format << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR, ((u32)ldpc_block_num << 17) | ((u32)ldpc_error << 16) | ((u32)evm_glitch << 15) | ((u32)coding << 14) | ((u32)giltf << 12) | ((u32)frame_description_nss << 10) | ((u32)mcs << 6) | ((u32)bw << 4) | ((u32)format << 0));
}

static inline void macdsp_api_frame_description_unpack(struct cl_chip *chip, u16 *ldpc_block_num, u8 *ldpc_error, u8 *evm_glitch, u8 *coding, u8 *giltf, u8 *frame_description_nss, u8 *mcs, u8 *bw, u8 *format)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR);

	*ldpc_block_num = (local_val & ((u32)0x7FFE0000)) >> 17;
	*ldpc_error = (local_val & ((u32)0x00010000)) >> 16;
	*evm_glitch = (local_val & ((u32)0x00008000)) >> 15;
	*coding = (local_val & ((u32)0x00004000)) >> 14;
	*giltf = (local_val & ((u32)0x00003000)) >> 12;
	*frame_description_nss = (local_val & ((u32)0x00000C00)) >> 10;
	*mcs = (local_val & ((u32)0x000003C0)) >> 6;
	*bw = (local_val & ((u32)0x00000030)) >> 4;
	*format = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u16 macdsp_api_frame_description_ldpc_block_num_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR);

	return (u16)((local_val & ((u32)0x7FFE0000)) >> 17);
}

static inline void macdsp_api_frame_description_ldpc_block_num_setf(struct cl_chip *chip, u16 ldpcblocknum)
{
	ASSERT_ERR_CHIP((((u32)ldpcblocknum << 17) & ~((u32)0x7FFE0000)) == 0);
	cl_reg_write(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR, (cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR) & ~((u32)0x7FFE0000)) | ((u32)ldpcblocknum << 17));
}

static inline u8 macdsp_api_frame_description_ldpc_error_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR);

	return (u8)((local_val & ((u32)0x00010000)) >> 16);
}

static inline void macdsp_api_frame_description_ldpc_error_setf(struct cl_chip *chip, u8 ldpcerror)
{
	ASSERT_ERR_CHIP((((u32)ldpcerror << 16) & ~((u32)0x00010000)) == 0);
	cl_reg_write(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR, (cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR) & ~((u32)0x00010000)) | ((u32)ldpcerror << 16));
}

static inline u8 macdsp_api_frame_description_evm_glitch_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR);

	return (u8)((local_val & ((u32)0x00008000)) >> 15);
}

static inline void macdsp_api_frame_description_evm_glitch_setf(struct cl_chip *chip, u8 evmglitch)
{
	ASSERT_ERR_CHIP((((u32)evmglitch << 15) & ~((u32)0x00008000)) == 0);
	cl_reg_write(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR, (cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR) & ~((u32)0x00008000)) | ((u32)evmglitch << 15));
}

static inline u8 macdsp_api_frame_description_coding_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR);

	return (u8)((local_val & ((u32)0x00004000)) >> 14);
}

static inline void macdsp_api_frame_description_coding_setf(struct cl_chip *chip, u8 coding)
{
	ASSERT_ERR_CHIP((((u32)coding << 14) & ~((u32)0x00004000)) == 0);
	cl_reg_write(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR, (cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR) & ~((u32)0x00004000)) | ((u32)coding << 14));
}

static inline u8 macdsp_api_frame_description_giltf_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR);

	return (u8)((local_val & ((u32)0x00003000)) >> 12);
}

static inline void macdsp_api_frame_description_giltf_setf(struct cl_chip *chip, u8 giltf)
{
	ASSERT_ERR_CHIP((((u32)giltf << 12) & ~((u32)0x00003000)) == 0);
	cl_reg_write(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR, (cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR) & ~((u32)0x00003000)) | ((u32)giltf << 12));
}

static inline u8 macdsp_api_frame_description_frame_description_nss_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR);

	return (u8)((local_val & ((u32)0x00000C00)) >> 10);
}

static inline void macdsp_api_frame_description_frame_description_nss_setf(struct cl_chip *chip, u8 framedescriptionnss)
{
	ASSERT_ERR_CHIP((((u32)framedescriptionnss << 10) & ~((u32)0x00000C00)) == 0);
	cl_reg_write(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR, (cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR) & ~((u32)0x00000C00)) | ((u32)framedescriptionnss << 10));
}

static inline u8 macdsp_api_frame_description_mcs_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR);

	return (u8)((local_val & ((u32)0x000003C0)) >> 6);
}

static inline void macdsp_api_frame_description_mcs_setf(struct cl_chip *chip, u8 mcs)
{
	ASSERT_ERR_CHIP((((u32)mcs << 6) & ~((u32)0x000003C0)) == 0);
	cl_reg_write(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR, (cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR) & ~((u32)0x000003C0)) | ((u32)mcs << 6));
}

static inline u8 macdsp_api_frame_description_bw_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR);

	return (u8)((local_val & ((u32)0x00000030)) >> 4);
}

static inline void macdsp_api_frame_description_bw_setf(struct cl_chip *chip, u8 bw)
{
	ASSERT_ERR_CHIP((((u32)bw << 4) & ~((u32)0x00000030)) == 0);
	cl_reg_write(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR, (cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR) & ~((u32)0x00000030)) | ((u32)bw << 4));
}

static inline u8 macdsp_api_frame_description_format_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void macdsp_api_frame_description_format_setf(struct cl_chip *chip, u8 format)
{
	ASSERT_ERR_CHIP((((u32)format << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR, (cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_ADDR) & ~((u32)0x0000000F)) | ((u32)format << 0));
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
#define MACDSP_API_FRAME_DESCRIPTION_2_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000009C)
#define MACDSP_API_FRAME_DESCRIPTION_2_OFFSET      0x0000009C
#define MACDSP_API_FRAME_DESCRIPTION_2_INDEX       0x00000027
#define MACDSP_API_FRAME_DESCRIPTION_2_RESET       0x00000000

static inline u32 macdsp_api_frame_description_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_2_ADDR);
}

static inline void macdsp_api_frame_description_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_FRAME_DESCRIPTION_2_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_FRAME_DESCRIPTION_2_BPU_BLOCK_ERR_SYMB_NUM_MASK    ((u32)0xFFFFF800)
#define MACDSP_API_FRAME_DESCRIPTION_2_BPU_BLOCK_ERR_SYMB_NUM_LSB    11
#define MACDSP_API_FRAME_DESCRIPTION_2_BPU_BLOCK_ERR_SYMB_NUM_WIDTH    ((u32)0x00000015)
#define MACDSP_API_FRAME_DESCRIPTION_2_EVM_DROP_SYMB_NUM_MASK    ((u32)0x000003FF)
#define MACDSP_API_FRAME_DESCRIPTION_2_EVM_DROP_SYMB_NUM_LSB    0
#define MACDSP_API_FRAME_DESCRIPTION_2_EVM_DROP_SYMB_NUM_WIDTH    ((u32)0x0000000A)

#define MACDSP_API_FRAME_DESCRIPTION_2_BPU_BLOCK_ERR_SYMB_NUM_RST    0x0
#define MACDSP_API_FRAME_DESCRIPTION_2_EVM_DROP_SYMB_NUM_RST    0x0

static inline void macdsp_api_frame_description_2_pack(struct cl_chip *chip, u32 bpu_block_err_symb_num, u16 evm_drop_symb_num)
{
	ASSERT_ERR_CHIP((((u32)bpu_block_err_symb_num << 11) & ~((u32)0xFFFFF800)) == 0);
	ASSERT_ERR_CHIP((((u32)evm_drop_symb_num << 0) & ~((u32)0x000003FF)) == 0);
	cl_reg_write(chip, MACDSP_API_FRAME_DESCRIPTION_2_ADDR, ((u32)bpu_block_err_symb_num << 11) | ((u32)evm_drop_symb_num << 0));
}

static inline void macdsp_api_frame_description_2_unpack(struct cl_chip *chip, u32 *bpu_block_err_symb_num, u16 *evm_drop_symb_num)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_2_ADDR);

	*bpu_block_err_symb_num = (local_val & ((u32)0xFFFFF800)) >> 11;
	*evm_drop_symb_num = (local_val & ((u32)0x000003FF)) >> 0;
}

static inline u32 macdsp_api_frame_description_2_bpu_block_err_symb_num_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_2_ADDR);

	return (u32)((local_val & ((u32)0xFFFFF800)) >> 11);
}

static inline void macdsp_api_frame_description_2_bpu_block_err_symb_num_setf(struct cl_chip *chip, u32 bpublockerrsymbnum)
{
	ASSERT_ERR_CHIP((((u32)bpublockerrsymbnum << 11) & ~((u32)0xFFFFF800)) == 0);
	cl_reg_write(chip, MACDSP_API_FRAME_DESCRIPTION_2_ADDR, (cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_2_ADDR) & ~((u32)0xFFFFF800)) | ((u32)bpublockerrsymbnum << 11));
}

static inline u16 macdsp_api_frame_description_2_evm_drop_symb_num_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_2_ADDR);

	return (u16)((local_val & ((u32)0x000003FF)) >> 0);
}

static inline void macdsp_api_frame_description_2_evm_drop_symb_num_setf(struct cl_chip *chip, u16 evmdropsymbnum)
{
	ASSERT_ERR_CHIP((((u32)evmdropsymbnum << 0) & ~((u32)0x000003FF)) == 0);
	cl_reg_write(chip, MACDSP_API_FRAME_DESCRIPTION_2_ADDR, (cl_reg_read(chip, MACDSP_API_FRAME_DESCRIPTION_2_ADDR) & ~((u32)0x000003FF)) | ((u32)evmdropsymbnum << 0));
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
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_1_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000100)
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_1_OFFSET      0x00000100
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_1_INDEX       0x00000040
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_1_RESET       0x00000000

static inline u32 macdsp_api_dsp_debugs_base_address_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_1_ADDR);
}

/* Field definitions */
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_1_DSP_DEBUGS_BASE_ADDRESS_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_1_DSP_DEBUGS_BASE_ADDRESS_LSB    0
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_1_DSP_DEBUGS_BASE_ADDRESS_WIDTH    ((u32)0x00000020)

#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_1_DSP_DEBUGS_BASE_ADDRESS_RST    0x0

static inline u32 macdsp_api_dsp_debugs_base_address_1_dsp_debugs_base_address_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_1_ADDR);

	return (u32)(local_val >> 0);
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
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_1_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000104)
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_1_OFFSET      0x00000104
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_1_INDEX       0x00000041
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_1_RESET       0x00000000

static inline u32 macdsp_api_dsp_debugs_section_size_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_DSP_DEBUGS_SECTION_SIZE_1_ADDR);
}

/* Field definitions */
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_1_DSP_DEBUGS_SECTION_SIZE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_1_DSP_DEBUGS_SECTION_SIZE_LSB    0
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_1_DSP_DEBUGS_SECTION_SIZE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_1_DSP_DEBUGS_SECTION_SIZE_RST    0x0

static inline u32 macdsp_api_dsp_debugs_section_size_1_dsp_debugs_section_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_DEBUGS_SECTION_SIZE_1_ADDR);

	return (u32)(local_val >> 0);
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
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_2_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000108)
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_2_OFFSET      0x00000108
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_2_INDEX       0x00000042
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_2_RESET       0x00000000

static inline u32 macdsp_api_dsp_debugs_base_address_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_2_ADDR);
}

/* Field definitions */
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_2_DSP_DEBUGS_BASE_ADDRESS_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_2_DSP_DEBUGS_BASE_ADDRESS_LSB    0
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_2_DSP_DEBUGS_BASE_ADDRESS_WIDTH    ((u32)0x00000020)

#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_2_DSP_DEBUGS_BASE_ADDRESS_RST    0x0

static inline u32 macdsp_api_dsp_debugs_base_address_2_dsp_debugs_base_address_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_2_ADDR);

	return (u32)(local_val >> 0);
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
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_2_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000010C)
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_2_OFFSET      0x0000010C
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_2_INDEX       0x00000043
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_2_RESET       0x00000000

static inline u32 macdsp_api_dsp_debugs_section_size_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_DSP_DEBUGS_SECTION_SIZE_2_ADDR);
}

/* Field definitions */
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_2_DSP_DEBUGS_SECTION_SIZE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_2_DSP_DEBUGS_SECTION_SIZE_LSB    0
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_2_DSP_DEBUGS_SECTION_SIZE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_2_DSP_DEBUGS_SECTION_SIZE_RST    0x0

static inline u32 macdsp_api_dsp_debugs_section_size_2_dsp_debugs_section_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_DEBUGS_SECTION_SIZE_2_ADDR);

	return (u32)(local_val >> 0);
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
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_3_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000110)
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_3_OFFSET      0x00000110
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_3_INDEX       0x00000044
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_3_RESET       0x00000000

static inline u32 macdsp_api_dsp_debugs_base_address_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_3_ADDR);
}

/* Field definitions */
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_3_DSP_DEBUGS_BASE_ADDRESS_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_3_DSP_DEBUGS_BASE_ADDRESS_LSB    0
#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_3_DSP_DEBUGS_BASE_ADDRESS_WIDTH    ((u32)0x00000020)

#define MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_3_DSP_DEBUGS_BASE_ADDRESS_RST    0x0

static inline u32 macdsp_api_dsp_debugs_base_address_3_dsp_debugs_base_address_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_DEBUGS_BASE_ADDRESS_3_ADDR);

	return (u32)(local_val >> 0);
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
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_3_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000114)
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_3_OFFSET      0x00000114
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_3_INDEX       0x00000045
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_3_RESET       0x00000000

static inline u32 macdsp_api_dsp_debugs_section_size_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_DSP_DEBUGS_SECTION_SIZE_3_ADDR);
}

/* Field definitions */
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_3_DSP_DEBUGS_SECTION_SIZE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_3_DSP_DEBUGS_SECTION_SIZE_LSB    0
#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_3_DSP_DEBUGS_SECTION_SIZE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_DSP_DEBUGS_SECTION_SIZE_3_DSP_DEBUGS_SECTION_SIZE_RST    0x0

static inline u32 macdsp_api_dsp_debugs_section_size_3_dsp_debugs_section_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_DEBUGS_SECTION_SIZE_3_ADDR);

	return (u32)(local_val >> 0);
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
#define MACDSP_API_USER_POSITION_TBL_BASE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000118)
#define MACDSP_API_USER_POSITION_TBL_BASE_OFFSET      0x00000118
#define MACDSP_API_USER_POSITION_TBL_BASE_INDEX       0x00000046
#define MACDSP_API_USER_POSITION_TBL_BASE_RESET       0x00000000

static inline u32 macdsp_api_user_position_tbl_base_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_USER_POSITION_TBL_BASE_ADDR);
}

static inline void macdsp_api_user_position_tbl_base_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_USER_POSITION_TBL_BASE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_USER_POSITION_TBL_BASE_USER_POSITION_TBL_BASE_ADDR_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_USER_POSITION_TBL_BASE_USER_POSITION_TBL_BASE_ADDR_LSB    0
#define MACDSP_API_USER_POSITION_TBL_BASE_USER_POSITION_TBL_BASE_ADDR_WIDTH    ((u32)0x00000020)

#define MACDSP_API_USER_POSITION_TBL_BASE_USER_POSITION_TBL_BASE_ADDR_RST    0x0

static inline u32 macdsp_api_user_position_tbl_base_user_position_tbl_base_addr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_USER_POSITION_TBL_BASE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_user_position_tbl_base_user_position_tbl_base_addr_setf(struct cl_chip *chip, u32 userpositiontblbaseaddr)
{
	ASSERT_ERR_CHIP((((u32)userpositiontblbaseaddr << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_USER_POSITION_TBL_BASE_ADDR, (u32)userpositiontblbaseaddr << 0);
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
#define MACDSP_API_USER_POSITION_TBL_SIZE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000011C)
#define MACDSP_API_USER_POSITION_TBL_SIZE_OFFSET      0x0000011C
#define MACDSP_API_USER_POSITION_TBL_SIZE_INDEX       0x00000047
#define MACDSP_API_USER_POSITION_TBL_SIZE_RESET       0x00000000

static inline u32 macdsp_api_user_position_tbl_size_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_USER_POSITION_TBL_SIZE_ADDR);
}

static inline void macdsp_api_user_position_tbl_size_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_USER_POSITION_TBL_SIZE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_USER_POSITION_TBL_SIZE_USER_POSITION_TBL_SECTION_SIZE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_USER_POSITION_TBL_SIZE_USER_POSITION_TBL_SECTION_SIZE_LSB    0
#define MACDSP_API_USER_POSITION_TBL_SIZE_USER_POSITION_TBL_SECTION_SIZE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_USER_POSITION_TBL_SIZE_USER_POSITION_TBL_SECTION_SIZE_RST    0x0

static inline u32 macdsp_api_user_position_tbl_size_user_position_tbl_section_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_USER_POSITION_TBL_SIZE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_user_position_tbl_size_user_position_tbl_section_size_setf(struct cl_chip *chip, u32 userpositiontblsectionsize)
{
	ASSERT_ERR_CHIP((((u32)userpositiontblsectionsize << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_USER_POSITION_TBL_SIZE_ADDR, (u32)userpositiontblsectionsize << 0);
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
#define MACDSP_API_XMEM_QMATRIX_TBL_BASE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000120)
#define MACDSP_API_XMEM_QMATRIX_TBL_BASE_OFFSET      0x00000120
#define MACDSP_API_XMEM_QMATRIX_TBL_BASE_INDEX       0x00000048
#define MACDSP_API_XMEM_QMATRIX_TBL_BASE_RESET       0x00000000

static inline u32 macdsp_api_xmem_qmatrix_tbl_base_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_XMEM_QMATRIX_TBL_BASE_ADDR);
}

static inline void macdsp_api_xmem_qmatrix_tbl_base_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_XMEM_QMATRIX_TBL_BASE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_XMEM_QMATRIX_TBL_BASE_XMEM_QMATRIX_TBL_BASE_ADDR_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_XMEM_QMATRIX_TBL_BASE_XMEM_QMATRIX_TBL_BASE_ADDR_LSB    0
#define MACDSP_API_XMEM_QMATRIX_TBL_BASE_XMEM_QMATRIX_TBL_BASE_ADDR_WIDTH    ((u32)0x00000020)

#define MACDSP_API_XMEM_QMATRIX_TBL_BASE_XMEM_QMATRIX_TBL_BASE_ADDR_RST    0x0

static inline u32 macdsp_api_xmem_qmatrix_tbl_base_xmem_qmatrix_tbl_base_addr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_XMEM_QMATRIX_TBL_BASE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_xmem_qmatrix_tbl_base_xmem_qmatrix_tbl_base_addr_setf(struct cl_chip *chip, u32 xmemqmatrixtblbaseaddr)
{
	ASSERT_ERR_CHIP((((u32)xmemqmatrixtblbaseaddr << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_XMEM_QMATRIX_TBL_BASE_ADDR, (u32)xmemqmatrixtblbaseaddr << 0);
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
#define MACDSP_API_XMEM_QMATRIX_TBL_SIZE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000124)
#define MACDSP_API_XMEM_QMATRIX_TBL_SIZE_OFFSET      0x00000124
#define MACDSP_API_XMEM_QMATRIX_TBL_SIZE_INDEX       0x00000049
#define MACDSP_API_XMEM_QMATRIX_TBL_SIZE_RESET       0x00000000

static inline u32 macdsp_api_xmem_qmatrix_tbl_size_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_XMEM_QMATRIX_TBL_SIZE_ADDR);
}

static inline void macdsp_api_xmem_qmatrix_tbl_size_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_XMEM_QMATRIX_TBL_SIZE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_XMEM_QMATRIX_TBL_SIZE_XMEM_QMATRIX_TBL_SECTION_SIZE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_XMEM_QMATRIX_TBL_SIZE_XMEM_QMATRIX_TBL_SECTION_SIZE_LSB    0
#define MACDSP_API_XMEM_QMATRIX_TBL_SIZE_XMEM_QMATRIX_TBL_SECTION_SIZE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_XMEM_QMATRIX_TBL_SIZE_XMEM_QMATRIX_TBL_SECTION_SIZE_RST    0x0

static inline u32 macdsp_api_xmem_qmatrix_tbl_size_xmem_qmatrix_tbl_section_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_XMEM_QMATRIX_TBL_SIZE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_xmem_qmatrix_tbl_size_xmem_qmatrix_tbl_section_size_setf(struct cl_chip *chip, u32 xmemqmatrixtblsectionsize)
{
	ASSERT_ERR_CHIP((((u32)xmemqmatrixtblsectionsize << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_XMEM_QMATRIX_TBL_SIZE_ADDR, (u32)xmemqmatrixtblsectionsize << 0);
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
#define MACDSP_API_XMEM_QMIRROR_TBL_BASE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000128)
#define MACDSP_API_XMEM_QMIRROR_TBL_BASE_OFFSET      0x00000128
#define MACDSP_API_XMEM_QMIRROR_TBL_BASE_INDEX       0x0000004A
#define MACDSP_API_XMEM_QMIRROR_TBL_BASE_RESET       0x00000000

static inline u32 macdsp_api_xmem_qmirror_tbl_base_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_XMEM_QMIRROR_TBL_BASE_ADDR);
}

static inline void macdsp_api_xmem_qmirror_tbl_base_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_XMEM_QMIRROR_TBL_BASE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_XMEM_QMIRROR_TBL_BASE_XMEM_QMIRROR_TBL_BASE_ADDR_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_XMEM_QMIRROR_TBL_BASE_XMEM_QMIRROR_TBL_BASE_ADDR_LSB    0
#define MACDSP_API_XMEM_QMIRROR_TBL_BASE_XMEM_QMIRROR_TBL_BASE_ADDR_WIDTH    ((u32)0x00000020)

#define MACDSP_API_XMEM_QMIRROR_TBL_BASE_XMEM_QMIRROR_TBL_BASE_ADDR_RST    0x0

static inline u32 macdsp_api_xmem_qmirror_tbl_base_xmem_qmirror_tbl_base_addr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_XMEM_QMIRROR_TBL_BASE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_xmem_qmirror_tbl_base_xmem_qmirror_tbl_base_addr_setf(struct cl_chip *chip, u32 xmemqmirrortblbaseaddr)
{
	ASSERT_ERR_CHIP((((u32)xmemqmirrortblbaseaddr << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_XMEM_QMIRROR_TBL_BASE_ADDR, (u32)xmemqmirrortblbaseaddr << 0);
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
#define MACDSP_API_XMEM_QMIRROR_TBL_SIZE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000012C)
#define MACDSP_API_XMEM_QMIRROR_TBL_SIZE_OFFSET      0x0000012C
#define MACDSP_API_XMEM_QMIRROR_TBL_SIZE_INDEX       0x0000004B
#define MACDSP_API_XMEM_QMIRROR_TBL_SIZE_RESET       0x00000000

static inline u32 macdsp_api_xmem_qmirror_tbl_size_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_XMEM_QMIRROR_TBL_SIZE_ADDR);
}

static inline void macdsp_api_xmem_qmirror_tbl_size_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_XMEM_QMIRROR_TBL_SIZE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_XMEM_QMIRROR_TBL_SIZE_XMEM_QMIRROR_TBL_SECTION_SIZE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_XMEM_QMIRROR_TBL_SIZE_XMEM_QMIRROR_TBL_SECTION_SIZE_LSB    0
#define MACDSP_API_XMEM_QMIRROR_TBL_SIZE_XMEM_QMIRROR_TBL_SECTION_SIZE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_XMEM_QMIRROR_TBL_SIZE_XMEM_QMIRROR_TBL_SECTION_SIZE_RST    0x0

static inline u32 macdsp_api_xmem_qmirror_tbl_size_xmem_qmirror_tbl_section_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_XMEM_QMIRROR_TBL_SIZE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_xmem_qmirror_tbl_size_xmem_qmirror_tbl_section_size_setf(struct cl_chip *chip, u32 xmemqmirrortblsectionsize)
{
	ASSERT_ERR_CHIP((((u32)xmemqmirrortblsectionsize << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_XMEM_QMIRROR_TBL_SIZE_ADDR, (u32)xmemqmirrortblsectionsize << 0);
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
#define MACDSP_API_VMATTRIX_TBL_BASE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000130)
#define MACDSP_API_VMATTRIX_TBL_BASE_OFFSET      0x00000130
#define MACDSP_API_VMATTRIX_TBL_BASE_INDEX       0x0000004C
#define MACDSP_API_VMATTRIX_TBL_BASE_RESET       0x00000000

static inline u32 macdsp_api_vmattrix_tbl_base_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_VMATTRIX_TBL_BASE_ADDR);
}

static inline void macdsp_api_vmattrix_tbl_base_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_VMATTRIX_TBL_BASE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_VMATTRIX_TBL_BASE_DMEM_VMATRIX_TBL_BASE_ADDR_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_VMATTRIX_TBL_BASE_DMEM_VMATRIX_TBL_BASE_ADDR_LSB    0
#define MACDSP_API_VMATTRIX_TBL_BASE_DMEM_VMATRIX_TBL_BASE_ADDR_WIDTH    ((u32)0x00000020)

#define MACDSP_API_VMATTRIX_TBL_BASE_DMEM_VMATRIX_TBL_BASE_ADDR_RST    0x0

static inline u32 macdsp_api_vmattrix_tbl_base_dmem_vmatrix_tbl_base_addr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VMATTRIX_TBL_BASE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_vmattrix_tbl_base_dmem_vmatrix_tbl_base_addr_setf(struct cl_chip *chip, u32 dmemvmatrixtblbaseaddr)
{
	ASSERT_ERR_CHIP((((u32)dmemvmatrixtblbaseaddr << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_VMATTRIX_TBL_BASE_ADDR, (u32)dmemvmatrixtblbaseaddr << 0);
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
#define MACDSP_API_VMATTRIX_TBL_SIZE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000134)
#define MACDSP_API_VMATTRIX_TBL_SIZE_OFFSET      0x00000134
#define MACDSP_API_VMATTRIX_TBL_SIZE_INDEX       0x0000004D
#define MACDSP_API_VMATTRIX_TBL_SIZE_RESET       0x00000000

static inline u32 macdsp_api_vmattrix_tbl_size_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_VMATTRIX_TBL_SIZE_ADDR);
}

static inline void macdsp_api_vmattrix_tbl_size_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_VMATTRIX_TBL_SIZE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_VMATTRIX_TBL_SIZE_DMEM_VMATRIX_TBL_SECTION_SIZE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_VMATTRIX_TBL_SIZE_DMEM_VMATRIX_TBL_SECTION_SIZE_LSB    0
#define MACDSP_API_VMATTRIX_TBL_SIZE_DMEM_VMATRIX_TBL_SECTION_SIZE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_VMATTRIX_TBL_SIZE_DMEM_VMATRIX_TBL_SECTION_SIZE_RST    0x0

static inline u32 macdsp_api_vmattrix_tbl_size_dmem_vmatrix_tbl_section_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VMATTRIX_TBL_SIZE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_vmattrix_tbl_size_dmem_vmatrix_tbl_section_size_setf(struct cl_chip *chip, u32 dmemvmatrixtblsectionsize)
{
	ASSERT_ERR_CHIP((((u32)dmemvmatrixtblsectionsize << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_VMATTRIX_TBL_SIZE_ADDR, (u32)dmemvmatrixtblsectionsize << 0);
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
#define MACDSP_API_CALIB_REQUEST_STRUCTURE_ADDRESS_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000138)
#define MACDSP_API_CALIB_REQUEST_STRUCTURE_ADDRESS_OFFSET      0x00000138
#define MACDSP_API_CALIB_REQUEST_STRUCTURE_ADDRESS_INDEX       0x0000004E
#define MACDSP_API_CALIB_REQUEST_STRUCTURE_ADDRESS_RESET       0x00000000

static inline u32 macdsp_api_calib_request_structure_address_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_CALIB_REQUEST_STRUCTURE_ADDRESS_ADDR);
}

static inline void macdsp_api_calib_request_structure_address_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_CALIB_REQUEST_STRUCTURE_ADDRESS_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_CALIB_REQUEST_STRUCTURE_ADDRESS_STRUCTURE_ADDRESS_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_CALIB_REQUEST_STRUCTURE_ADDRESS_STRUCTURE_ADDRESS_LSB    0
#define MACDSP_API_CALIB_REQUEST_STRUCTURE_ADDRESS_STRUCTURE_ADDRESS_WIDTH    ((u32)0x00000020)

#define MACDSP_API_CALIB_REQUEST_STRUCTURE_ADDRESS_STRUCTURE_ADDRESS_RST    0x0

static inline u32 macdsp_api_calib_request_structure_address_structure_address_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CALIB_REQUEST_STRUCTURE_ADDRESS_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_calib_request_structure_address_structure_address_setf(struct cl_chip *chip, u32 structureaddress)
{
	ASSERT_ERR_CHIP((((u32)structureaddress << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_CALIB_REQUEST_STRUCTURE_ADDRESS_ADDR, (u32)structureaddress << 0);
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
#define MACDSP_API_CALIB_REQUEST_STRUCTURE_SIZE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000013C)
#define MACDSP_API_CALIB_REQUEST_STRUCTURE_SIZE_OFFSET      0x0000013C
#define MACDSP_API_CALIB_REQUEST_STRUCTURE_SIZE_INDEX       0x0000004F
#define MACDSP_API_CALIB_REQUEST_STRUCTURE_SIZE_RESET       0x00000000

static inline u32 macdsp_api_calib_request_structure_size_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_CALIB_REQUEST_STRUCTURE_SIZE_ADDR);
}

static inline void macdsp_api_calib_request_structure_size_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_CALIB_REQUEST_STRUCTURE_SIZE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_CALIB_REQUEST_STRUCTURE_SIZE_STRUCTURE_SIZE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_CALIB_REQUEST_STRUCTURE_SIZE_STRUCTURE_SIZE_LSB    0
#define MACDSP_API_CALIB_REQUEST_STRUCTURE_SIZE_STRUCTURE_SIZE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_CALIB_REQUEST_STRUCTURE_SIZE_STRUCTURE_SIZE_RST    0x0

static inline u32 macdsp_api_calib_request_structure_size_structure_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CALIB_REQUEST_STRUCTURE_SIZE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_calib_request_structure_size_structure_size_setf(struct cl_chip *chip, u32 structuresize)
{
	ASSERT_ERR_CHIP((((u32)structuresize << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_CALIB_REQUEST_STRUCTURE_SIZE_ADDR, (u32)structuresize << 0);
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
#define MACDSP_API_CALIB_RESPONSE_STRUCTURE_ADDRESS_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000140)
#define MACDSP_API_CALIB_RESPONSE_STRUCTURE_ADDRESS_OFFSET      0x00000140
#define MACDSP_API_CALIB_RESPONSE_STRUCTURE_ADDRESS_INDEX       0x00000050
#define MACDSP_API_CALIB_RESPONSE_STRUCTURE_ADDRESS_RESET       0x00000000

static inline u32 macdsp_api_calib_response_structure_address_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_CALIB_RESPONSE_STRUCTURE_ADDRESS_ADDR);
}

static inline void macdsp_api_calib_response_structure_address_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_CALIB_RESPONSE_STRUCTURE_ADDRESS_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_CALIB_RESPONSE_STRUCTURE_ADDRESS_STRUCTURE_ADDRESS_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_CALIB_RESPONSE_STRUCTURE_ADDRESS_STRUCTURE_ADDRESS_LSB    0
#define MACDSP_API_CALIB_RESPONSE_STRUCTURE_ADDRESS_STRUCTURE_ADDRESS_WIDTH    ((u32)0x00000020)

#define MACDSP_API_CALIB_RESPONSE_STRUCTURE_ADDRESS_STRUCTURE_ADDRESS_RST    0x0

static inline u32 macdsp_api_calib_response_structure_address_structure_address_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CALIB_RESPONSE_STRUCTURE_ADDRESS_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_calib_response_structure_address_structure_address_setf(struct cl_chip *chip, u32 structureaddress)
{
	ASSERT_ERR_CHIP((((u32)structureaddress << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_CALIB_RESPONSE_STRUCTURE_ADDRESS_ADDR, (u32)structureaddress << 0);
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
#define MACDSP_API_CALIB_RESPONSE_STRUCTURE_SIZE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000144)
#define MACDSP_API_CALIB_RESPONSE_STRUCTURE_SIZE_OFFSET      0x00000144
#define MACDSP_API_CALIB_RESPONSE_STRUCTURE_SIZE_INDEX       0x00000051
#define MACDSP_API_CALIB_RESPONSE_STRUCTURE_SIZE_RESET       0x00000000

static inline u32 macdsp_api_calib_response_structure_size_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_CALIB_RESPONSE_STRUCTURE_SIZE_ADDR);
}

static inline void macdsp_api_calib_response_structure_size_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_CALIB_RESPONSE_STRUCTURE_SIZE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_CALIB_RESPONSE_STRUCTURE_SIZE_STRUCTURE_SIZE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_CALIB_RESPONSE_STRUCTURE_SIZE_STRUCTURE_SIZE_LSB    0
#define MACDSP_API_CALIB_RESPONSE_STRUCTURE_SIZE_STRUCTURE_SIZE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_CALIB_RESPONSE_STRUCTURE_SIZE_STRUCTURE_SIZE_RST    0x0

static inline u32 macdsp_api_calib_response_structure_size_structure_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CALIB_RESPONSE_STRUCTURE_SIZE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_calib_response_structure_size_structure_size_setf(struct cl_chip *chip, u32 structuresize)
{
	ASSERT_ERR_CHIP((((u32)structuresize << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_CALIB_RESPONSE_STRUCTURE_SIZE_ADDR, (u32)structuresize << 0);
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
#define MACDSP_API_BFEE_PBD_1_ADDRESS_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000148)
#define MACDSP_API_BFEE_PBD_1_ADDRESS_OFFSET      0x00000148
#define MACDSP_API_BFEE_PBD_1_ADDRESS_INDEX       0x00000052
#define MACDSP_API_BFEE_PBD_1_ADDRESS_RESET       0x00000000

static inline u32 macdsp_api_bfee_pbd_1_address_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_BFEE_PBD_1_ADDRESS_ADDR);
}

static inline void macdsp_api_bfee_pbd_1_address_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_BFEE_PBD_1_ADDRESS_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_BFEE_PBD_1_ADDRESS_BFEE_PBD_1_ADDRESS_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_BFEE_PBD_1_ADDRESS_BFEE_PBD_1_ADDRESS_LSB    0
#define MACDSP_API_BFEE_PBD_1_ADDRESS_BFEE_PBD_1_ADDRESS_WIDTH    ((u32)0x00000020)

#define MACDSP_API_BFEE_PBD_1_ADDRESS_BFEE_PBD_1_ADDRESS_RST    0x0

static inline u32 macdsp_api_bfee_pbd_1_address_bfee_pbd_1_address_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_BFEE_PBD_1_ADDRESS_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_bfee_pbd_1_address_bfee_pbd_1_address_setf(struct cl_chip *chip, u32 bfeepbd1address)
{
	ASSERT_ERR_CHIP((((u32)bfeepbd1address << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_BFEE_PBD_1_ADDRESS_ADDR, (u32)bfeepbd1address << 0);
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
#define MACDSP_API_ATHD_ADDRESS_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000014C)
#define MACDSP_API_ATHD_ADDRESS_OFFSET      0x0000014C
#define MACDSP_API_ATHD_ADDRESS_INDEX       0x00000053
#define MACDSP_API_ATHD_ADDRESS_RESET       0x00000000

static inline u32 macdsp_api_athd_address_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_ATHD_ADDRESS_ADDR);
}

static inline void macdsp_api_athd_address_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_ATHD_ADDRESS_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_ATHD_ADDRESS_ATHD_ADDRESS_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_ATHD_ADDRESS_ATHD_ADDRESS_LSB    0
#define MACDSP_API_ATHD_ADDRESS_ATHD_ADDRESS_WIDTH    ((u32)0x00000020)

#define MACDSP_API_ATHD_ADDRESS_ATHD_ADDRESS_RST    0x0

static inline u32 macdsp_api_athd_address_athd_address_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_ATHD_ADDRESS_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_athd_address_athd_address_setf(struct cl_chip *chip, u32 athdaddress)
{
	ASSERT_ERR_CHIP((((u32)athdaddress << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_ATHD_ADDRESS_ADDR, (u32)athdaddress << 0);
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
#define MACDSP_API_THD_ADDRESS_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000150)
#define MACDSP_API_THD_ADDRESS_OFFSET      0x00000150
#define MACDSP_API_THD_ADDRESS_INDEX       0x00000054
#define MACDSP_API_THD_ADDRESS_RESET       0x00000000

static inline u32 macdsp_api_thd_address_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_THD_ADDRESS_ADDR);
}

static inline void macdsp_api_thd_address_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_THD_ADDRESS_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_THD_ADDRESS_THD_ADDRESS_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_THD_ADDRESS_THD_ADDRESS_LSB    0
#define MACDSP_API_THD_ADDRESS_THD_ADDRESS_WIDTH    ((u32)0x00000020)

#define MACDSP_API_THD_ADDRESS_THD_ADDRESS_RST    0x0

static inline u32 macdsp_api_thd_address_thd_address_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_THD_ADDRESS_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_thd_address_thd_address_setf(struct cl_chip *chip, u32 thdaddress)
{
	ASSERT_ERR_CHIP((((u32)thdaddress << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_THD_ADDRESS_ADDR, (u32)thdaddress << 0);
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
#define MACDSP_API_TXVEC_PHY_ERROR_TBL_BASE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000154)
#define MACDSP_API_TXVEC_PHY_ERROR_TBL_BASE_OFFSET      0x00000154
#define MACDSP_API_TXVEC_PHY_ERROR_TBL_BASE_INDEX       0x00000055
#define MACDSP_API_TXVEC_PHY_ERROR_TBL_BASE_RESET       0x00000000

static inline u32 macdsp_api_txvec_phy_error_tbl_base_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TXVEC_PHY_ERROR_TBL_BASE_ADDR);
}

static inline void macdsp_api_txvec_phy_error_tbl_base_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TXVEC_PHY_ERROR_TBL_BASE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TXVEC_PHY_ERROR_TBL_BASE_TX_VECTOR_TBL_BASE_ADDR_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_TXVEC_PHY_ERROR_TBL_BASE_TX_VECTOR_TBL_BASE_ADDR_LSB    0
#define MACDSP_API_TXVEC_PHY_ERROR_TBL_BASE_TX_VECTOR_TBL_BASE_ADDR_WIDTH    ((u32)0x00000020)

#define MACDSP_API_TXVEC_PHY_ERROR_TBL_BASE_TX_VECTOR_TBL_BASE_ADDR_RST    0x0

static inline u32 macdsp_api_txvec_phy_error_tbl_base_tx_vector_tbl_base_addr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TXVEC_PHY_ERROR_TBL_BASE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_txvec_phy_error_tbl_base_tx_vector_tbl_base_addr_setf(struct cl_chip *chip, u32 txvectortblbaseaddr)
{
	ASSERT_ERR_CHIP((((u32)txvectortblbaseaddr << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TXVEC_PHY_ERROR_TBL_BASE_ADDR, (u32)txvectortblbaseaddr << 0);
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
#define MACDSP_API_TXVEC_PHY_ERROR_TBL_SIZE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000158)
#define MACDSP_API_TXVEC_PHY_ERROR_TBL_SIZE_OFFSET      0x00000158
#define MACDSP_API_TXVEC_PHY_ERROR_TBL_SIZE_INDEX       0x00000056
#define MACDSP_API_TXVEC_PHY_ERROR_TBL_SIZE_RESET       0x00000000

static inline u32 macdsp_api_txvec_phy_error_tbl_size_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TXVEC_PHY_ERROR_TBL_SIZE_ADDR);
}

static inline void macdsp_api_txvec_phy_error_tbl_size_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TXVEC_PHY_ERROR_TBL_SIZE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TXVEC_PHY_ERROR_TBL_SIZE_TX_VECTOR_TBL_SECTION_SIZE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_TXVEC_PHY_ERROR_TBL_SIZE_TX_VECTOR_TBL_SECTION_SIZE_LSB    0
#define MACDSP_API_TXVEC_PHY_ERROR_TBL_SIZE_TX_VECTOR_TBL_SECTION_SIZE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_TXVEC_PHY_ERROR_TBL_SIZE_TX_VECTOR_TBL_SECTION_SIZE_RST    0x0

static inline u32 macdsp_api_txvec_phy_error_tbl_size_tx_vector_tbl_section_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TXVEC_PHY_ERROR_TBL_SIZE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_txvec_phy_error_tbl_size_tx_vector_tbl_section_size_setf(struct cl_chip *chip, u32 txvectortblsectionsize)
{
	ASSERT_ERR_CHIP((((u32)txvectortblsectionsize << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TXVEC_PHY_ERROR_TBL_SIZE_ADDR, (u32)txvectortblsectionsize << 0);
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
#define MACDSP_API_DSP_2_MAC_MAILBOX_BASE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000160)
#define MACDSP_API_DSP_2_MAC_MAILBOX_BASE_OFFSET      0x00000160
#define MACDSP_API_DSP_2_MAC_MAILBOX_BASE_INDEX       0x00000058
#define MACDSP_API_DSP_2_MAC_MAILBOX_BASE_RESET       0x00000000

static inline u32 macdsp_api_dsp_2_mac_mailbox_base_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_DSP_2_MAC_MAILBOX_BASE_ADDR);
}

static inline void macdsp_api_dsp_2_mac_mailbox_base_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_DSP_2_MAC_MAILBOX_BASE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_DSP_2_MAC_MAILBOX_BASE_DSP_2_MAC_MAIL_BOX_BASE_ADDR_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_DSP_2_MAC_MAILBOX_BASE_DSP_2_MAC_MAIL_BOX_BASE_ADDR_LSB    0
#define MACDSP_API_DSP_2_MAC_MAILBOX_BASE_DSP_2_MAC_MAIL_BOX_BASE_ADDR_WIDTH    ((u32)0x00000020)

#define MACDSP_API_DSP_2_MAC_MAILBOX_BASE_DSP_2_MAC_MAIL_BOX_BASE_ADDR_RST    0x0

static inline u32 macdsp_api_dsp_2_mac_mailbox_base_dsp_2_mac_mail_box_base_addr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_2_MAC_MAILBOX_BASE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_dsp_2_mac_mailbox_base_dsp_2_mac_mail_box_base_addr_setf(struct cl_chip *chip, u32 dsp2macmailboxbaseaddr)
{
	ASSERT_ERR_CHIP((((u32)dsp2macmailboxbaseaddr << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_DSP_2_MAC_MAILBOX_BASE_ADDR, (u32)dsp2macmailboxbaseaddr << 0);
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
#define MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000164)
#define MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_OFFSET      0x00000164
#define MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_INDEX       0x00000059
#define MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_RESET       0x00000000

static inline u32 macdsp_api_dsp_2_mac_mailbox_size_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_ADDR);
}

static inline void macdsp_api_dsp_2_mac_mailbox_size_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_MESSAGE_SIZE_MASK    ((u32)0xFFFF0000)
#define MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_MESSAGE_SIZE_LSB    16
#define MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_MESSAGE_SIZE_WIDTH    ((u32)0x00000010)
#define MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_MAILBOX_SIZE_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_MAILBOX_SIZE_LSB    0
#define MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_MAILBOX_SIZE_WIDTH    ((u32)0x00000010)

#define MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_MESSAGE_SIZE_RST    0x0
#define MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_MAILBOX_SIZE_RST    0x0

static inline void macdsp_api_dsp_2_mac_mailbox_size_pack(struct cl_chip *chip, u16 message_size, u16 mailbox_size)
{
	ASSERT_ERR_CHIP((((u32)message_size << 16) & ~((u32)0xFFFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)mailbox_size << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_ADDR, ((u32)message_size << 16) | ((u32)mailbox_size << 0));
}

static inline void macdsp_api_dsp_2_mac_mailbox_size_unpack(struct cl_chip *chip, u16 *message_size, u16 *mailbox_size)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_ADDR);

	*message_size = (local_val & ((u32)0xFFFF0000)) >> 16;
	*mailbox_size = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_dsp_2_mac_mailbox_size_message_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_ADDR);

	return (u16)((local_val & ((u32)0xFFFF0000)) >> 16);
}

static inline void macdsp_api_dsp_2_mac_mailbox_size_message_size_setf(struct cl_chip *chip, u16 messagesize)
{
	ASSERT_ERR_CHIP((((u32)messagesize << 16) & ~((u32)0xFFFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_ADDR, (cl_reg_read(chip, MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_ADDR) & ~((u32)0xFFFF0000)) | ((u32)messagesize << 16));
}

static inline u16 macdsp_api_dsp_2_mac_mailbox_size_mailbox_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_dsp_2_mac_mailbox_size_mailbox_size_setf(struct cl_chip *chip, u16 mailboxsize)
{
	ASSERT_ERR_CHIP((((u32)mailboxsize << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_ADDR, (cl_reg_read(chip, MACDSP_API_DSP_2_MAC_MAILBOX_SIZE_ADDR) & ~((u32)0x0000FFFF)) | ((u32)mailboxsize << 0));
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
#define MACDSP_API_DSP_2_MAC_MAILBOX_RD_IND_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000168)
#define MACDSP_API_DSP_2_MAC_MAILBOX_RD_IND_OFFSET      0x00000168
#define MACDSP_API_DSP_2_MAC_MAILBOX_RD_IND_INDEX       0x0000005A
#define MACDSP_API_DSP_2_MAC_MAILBOX_RD_IND_RESET       0x00000000

static inline u32 macdsp_api_dsp_2_mac_mailbox_rd_ind_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_DSP_2_MAC_MAILBOX_RD_IND_ADDR);
}

static inline void macdsp_api_dsp_2_mac_mailbox_rd_ind_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_DSP_2_MAC_MAILBOX_RD_IND_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_DSP_2_MAC_MAILBOX_RD_IND_DSP_2_MAC_MAIL_BOX_READ_IDX_ADDRESS_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_DSP_2_MAC_MAILBOX_RD_IND_DSP_2_MAC_MAIL_BOX_READ_IDX_ADDRESS_LSB    0
#define MACDSP_API_DSP_2_MAC_MAILBOX_RD_IND_DSP_2_MAC_MAIL_BOX_READ_IDX_ADDRESS_WIDTH    ((u32)0x00000020)

#define MACDSP_API_DSP_2_MAC_MAILBOX_RD_IND_DSP_2_MAC_MAIL_BOX_READ_IDX_ADDRESS_RST    0x0

static inline u32 macdsp_api_dsp_2_mac_mailbox_rd_ind_dsp_2_mac_mail_box_read_idx_address_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_2_MAC_MAILBOX_RD_IND_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_dsp_2_mac_mailbox_rd_ind_dsp_2_mac_mail_box_read_idx_address_setf(struct cl_chip *chip, u32 dsp2macmailboxreadidxaddress)
{
	ASSERT_ERR_CHIP((((u32)dsp2macmailboxreadidxaddress << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_DSP_2_MAC_MAILBOX_RD_IND_ADDR, (u32)dsp2macmailboxreadidxaddress << 0);
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
#define MACDSP_API_DSP_2_MAC_MAILBOX_WR_IND_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000016C)
#define MACDSP_API_DSP_2_MAC_MAILBOX_WR_IND_OFFSET      0x0000016C
#define MACDSP_API_DSP_2_MAC_MAILBOX_WR_IND_INDEX       0x0000005B
#define MACDSP_API_DSP_2_MAC_MAILBOX_WR_IND_RESET       0x00000000

static inline u32 macdsp_api_dsp_2_mac_mailbox_wr_ind_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_DSP_2_MAC_MAILBOX_WR_IND_ADDR);
}

static inline void macdsp_api_dsp_2_mac_mailbox_wr_ind_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_DSP_2_MAC_MAILBOX_WR_IND_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_DSP_2_MAC_MAILBOX_WR_IND_DSP_2_MAC_MAIL_BOX_WRITE_IDX_ADDRESS_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_DSP_2_MAC_MAILBOX_WR_IND_DSP_2_MAC_MAIL_BOX_WRITE_IDX_ADDRESS_LSB    0
#define MACDSP_API_DSP_2_MAC_MAILBOX_WR_IND_DSP_2_MAC_MAIL_BOX_WRITE_IDX_ADDRESS_WIDTH    ((u32)0x00000020)

#define MACDSP_API_DSP_2_MAC_MAILBOX_WR_IND_DSP_2_MAC_MAIL_BOX_WRITE_IDX_ADDRESS_RST    0x0

static inline u32 macdsp_api_dsp_2_mac_mailbox_wr_ind_dsp_2_mac_mail_box_write_idx_address_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_2_MAC_MAILBOX_WR_IND_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_dsp_2_mac_mailbox_wr_ind_dsp_2_mac_mail_box_write_idx_address_setf(struct cl_chip *chip, u32 dsp2macmailboxwriteidxaddress)
{
	ASSERT_ERR_CHIP((((u32)dsp2macmailboxwriteidxaddress << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_DSP_2_MAC_MAILBOX_WR_IND_ADDR, (u32)dsp2macmailboxwriteidxaddress << 0);
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
#define MACDSP_API_MAC_2_DSP_MAILBOX_BASE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000170)
#define MACDSP_API_MAC_2_DSP_MAILBOX_BASE_OFFSET      0x00000170
#define MACDSP_API_MAC_2_DSP_MAILBOX_BASE_INDEX       0x0000005C
#define MACDSP_API_MAC_2_DSP_MAILBOX_BASE_RESET       0x00000000

static inline u32 macdsp_api_mac_2_dsp_mailbox_base_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_MAC_2_DSP_MAILBOX_BASE_ADDR);
}

static inline void macdsp_api_mac_2_dsp_mailbox_base_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_MAC_2_DSP_MAILBOX_BASE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_MAC_2_DSP_MAILBOX_BASE_MAC_2_DSP_MAIL_BOX_BASE_ADDR_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_MAC_2_DSP_MAILBOX_BASE_MAC_2_DSP_MAIL_BOX_BASE_ADDR_LSB    0
#define MACDSP_API_MAC_2_DSP_MAILBOX_BASE_MAC_2_DSP_MAIL_BOX_BASE_ADDR_WIDTH    ((u32)0x00000020)

#define MACDSP_API_MAC_2_DSP_MAILBOX_BASE_MAC_2_DSP_MAIL_BOX_BASE_ADDR_RST    0x0

static inline u32 macdsp_api_mac_2_dsp_mailbox_base_mac_2_dsp_mail_box_base_addr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_2_DSP_MAILBOX_BASE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_mac_2_dsp_mailbox_base_mac_2_dsp_mail_box_base_addr_setf(struct cl_chip *chip, u32 mac2dspmailboxbaseaddr)
{
	ASSERT_ERR_CHIP((((u32)mac2dspmailboxbaseaddr << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_2_DSP_MAILBOX_BASE_ADDR, (u32)mac2dspmailboxbaseaddr << 0);
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
#define MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000174)
#define MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_OFFSET      0x00000174
#define MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_INDEX       0x0000005D
#define MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_RESET       0x00000000

static inline u32 macdsp_api_mac_2_dsp_mailbox_size_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_ADDR);
}

static inline void macdsp_api_mac_2_dsp_mailbox_size_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_MESSAGE_SIZE_MASK    ((u32)0xFFFF0000)
#define MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_MESSAGE_SIZE_LSB    16
#define MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_MESSAGE_SIZE_WIDTH    ((u32)0x00000010)
#define MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_MAILBOX_SIZE_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_MAILBOX_SIZE_LSB    0
#define MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_MAILBOX_SIZE_WIDTH    ((u32)0x00000010)

#define MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_MESSAGE_SIZE_RST    0x0
#define MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_MAILBOX_SIZE_RST    0x0

static inline void macdsp_api_mac_2_dsp_mailbox_size_pack(struct cl_chip *chip, u16 message_size, u16 mailbox_size)
{
	ASSERT_ERR_CHIP((((u32)message_size << 16) & ~((u32)0xFFFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)mailbox_size << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_ADDR, ((u32)message_size << 16) | ((u32)mailbox_size << 0));
}

static inline void macdsp_api_mac_2_dsp_mailbox_size_unpack(struct cl_chip *chip, u16 *message_size, u16 *mailbox_size)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_ADDR);

	*message_size = (local_val & ((u32)0xFFFF0000)) >> 16;
	*mailbox_size = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_mac_2_dsp_mailbox_size_message_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_ADDR);

	return (u16)((local_val & ((u32)0xFFFF0000)) >> 16);
}

static inline void macdsp_api_mac_2_dsp_mailbox_size_message_size_setf(struct cl_chip *chip, u16 messagesize)
{
	ASSERT_ERR_CHIP((((u32)messagesize << 16) & ~((u32)0xFFFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_ADDR, (cl_reg_read(chip, MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_ADDR) & ~((u32)0xFFFF0000)) | ((u32)messagesize << 16));
}

static inline u16 macdsp_api_mac_2_dsp_mailbox_size_mailbox_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_mac_2_dsp_mailbox_size_mailbox_size_setf(struct cl_chip *chip, u16 mailboxsize)
{
	ASSERT_ERR_CHIP((((u32)mailboxsize << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_ADDR, (cl_reg_read(chip, MACDSP_API_MAC_2_DSP_MAILBOX_SIZE_ADDR) & ~((u32)0x0000FFFF)) | ((u32)mailboxsize << 0));
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
#define MACDSP_API_MAC_2_DSP_MAILBOX_RD_IND_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000178)
#define MACDSP_API_MAC_2_DSP_MAILBOX_RD_IND_OFFSET      0x00000178
#define MACDSP_API_MAC_2_DSP_MAILBOX_RD_IND_INDEX       0x0000005E
#define MACDSP_API_MAC_2_DSP_MAILBOX_RD_IND_RESET       0x00000000

static inline u32 macdsp_api_mac_2_dsp_mailbox_rd_ind_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_MAC_2_DSP_MAILBOX_RD_IND_ADDR);
}

static inline void macdsp_api_mac_2_dsp_mailbox_rd_ind_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_MAC_2_DSP_MAILBOX_RD_IND_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_MAC_2_DSP_MAILBOX_RD_IND_MAC_2_DSP_MAIL_BOX_READ_IDX_ADDRESS_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_MAC_2_DSP_MAILBOX_RD_IND_MAC_2_DSP_MAIL_BOX_READ_IDX_ADDRESS_LSB    0
#define MACDSP_API_MAC_2_DSP_MAILBOX_RD_IND_MAC_2_DSP_MAIL_BOX_READ_IDX_ADDRESS_WIDTH    ((u32)0x00000020)

#define MACDSP_API_MAC_2_DSP_MAILBOX_RD_IND_MAC_2_DSP_MAIL_BOX_READ_IDX_ADDRESS_RST    0x0

static inline u32 macdsp_api_mac_2_dsp_mailbox_rd_ind_mac_2_dsp_mail_box_read_idx_address_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_2_DSP_MAILBOX_RD_IND_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_mac_2_dsp_mailbox_rd_ind_mac_2_dsp_mail_box_read_idx_address_setf(struct cl_chip *chip, u32 mac2dspmailboxreadidxaddress)
{
	ASSERT_ERR_CHIP((((u32)mac2dspmailboxreadidxaddress << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_2_DSP_MAILBOX_RD_IND_ADDR, (u32)mac2dspmailboxreadidxaddress << 0);
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
#define MACDSP_API_MAC_2_DSP_MAILBOX_WR_IND_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000017C)
#define MACDSP_API_MAC_2_DSP_MAILBOX_WR_IND_OFFSET      0x0000017C
#define MACDSP_API_MAC_2_DSP_MAILBOX_WR_IND_INDEX       0x0000005F
#define MACDSP_API_MAC_2_DSP_MAILBOX_WR_IND_RESET       0x00000000

static inline u32 macdsp_api_mac_2_dsp_mailbox_wr_ind_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_MAC_2_DSP_MAILBOX_WR_IND_ADDR);
}

static inline void macdsp_api_mac_2_dsp_mailbox_wr_ind_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_MAC_2_DSP_MAILBOX_WR_IND_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_MAC_2_DSP_MAILBOX_WR_IND_MAC_2_DSP_MAIL_BOX_WRITE_IDX_ADDRESS_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_MAC_2_DSP_MAILBOX_WR_IND_MAC_2_DSP_MAIL_BOX_WRITE_IDX_ADDRESS_LSB    0
#define MACDSP_API_MAC_2_DSP_MAILBOX_WR_IND_MAC_2_DSP_MAIL_BOX_WRITE_IDX_ADDRESS_WIDTH    ((u32)0x00000020)

#define MACDSP_API_MAC_2_DSP_MAILBOX_WR_IND_MAC_2_DSP_MAIL_BOX_WRITE_IDX_ADDRESS_RST    0x0

static inline u32 macdsp_api_mac_2_dsp_mailbox_wr_ind_mac_2_dsp_mail_box_write_idx_address_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MAC_2_DSP_MAILBOX_WR_IND_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_mac_2_dsp_mailbox_wr_ind_mac_2_dsp_mail_box_write_idx_address_setf(struct cl_chip *chip, u32 mac2dspmailboxwriteidxaddress)
{
	ASSERT_ERR_CHIP((((u32)mac2dspmailboxwriteidxaddress << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_MAC_2_DSP_MAILBOX_WR_IND_ADDR, (u32)mac2dspmailboxwriteidxaddress << 0);
}

/**
 * @brief CAL_ERROR_REASON_ADDRESS register definition
 *  CAL_ERROR_REASON_ADDRESS register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 * </pre>
 */
#define MACDSP_API_CAL_ERROR_REASON_ADDRESS_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000180)
#define MACDSP_API_CAL_ERROR_REASON_ADDRESS_OFFSET      0x00000180
#define MACDSP_API_CAL_ERROR_REASON_ADDRESS_INDEX       0x00000060
#define MACDSP_API_CAL_ERROR_REASON_ADDRESS_RESET       0x00000000

/* Field definitions */

/**
 * @brief CAL_ERROR_REASON_SIZE register definition
 *  CAL_ERROR_REASON_SIZE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 * </pre>
 */
#define MACDSP_API_CAL_ERROR_REASON_SIZE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000184)
#define MACDSP_API_CAL_ERROR_REASON_SIZE_OFFSET      0x00000184
#define MACDSP_API_CAL_ERROR_REASON_SIZE_INDEX       0x00000061
#define MACDSP_API_CAL_ERROR_REASON_SIZE_RESET       0x00000000

/* Field definitions */

/**
 * @brief AGC_RAMP_UP_VALUE register definition
 *  AGC_RAMP_UP_VALUE register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 agc_ramp_up_value         0x10
 * </pre>
 */
#define MACDSP_API_AGC_RAMP_UP_VALUE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000188)
#define MACDSP_API_AGC_RAMP_UP_VALUE_OFFSET      0x00000188
#define MACDSP_API_AGC_RAMP_UP_VALUE_INDEX       0x00000062
#define MACDSP_API_AGC_RAMP_UP_VALUE_RESET       0x00000010

static inline u32 macdsp_api_agc_ramp_up_value_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_AGC_RAMP_UP_VALUE_ADDR);
}

static inline void macdsp_api_agc_ramp_up_value_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_AGC_RAMP_UP_VALUE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_AGC_RAMP_UP_VALUE_AGC_RAMP_UP_VALUE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_AGC_RAMP_UP_VALUE_AGC_RAMP_UP_VALUE_LSB    0
#define MACDSP_API_AGC_RAMP_UP_VALUE_AGC_RAMP_UP_VALUE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_AGC_RAMP_UP_VALUE_AGC_RAMP_UP_VALUE_RST    0x10

static inline u32 macdsp_api_agc_ramp_up_value_agc_ramp_up_value_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_AGC_RAMP_UP_VALUE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_agc_ramp_up_value_agc_ramp_up_value_setf(struct cl_chip *chip, u32 agcrampupvalue)
{
	ASSERT_ERR_CHIP((((u32)agcrampupvalue << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_AGC_RAMP_UP_VALUE_ADDR, (u32)agcrampupvalue << 0);
}

/**
 * @brief SENSING_FLAGS register definition
 *  SENSING_FLAGS register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:14 IMAGING_SN                0x0
 *    13    FFT_FOR_SLOW_BLOCK_ACK    0
 *    12    pri_enabled               0
 *    11:10 sync_chain                0x0
 *    09    ANGLES_ACK_MESSAGE        0
 *    08    ABS_ACK_MESSAGE           0
 *    07    FFT_ACK_MESSAGE           0
 *    06    gui_cntl                  0
 *    05:04 num_of_stream             0x0
 *    02    end_mode                  0
 *    01    rx_mode                   0
 *    00    tx_mode                   0
 * </pre>
 */
#define MACDSP_API_SENSING_FLAGS_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000018C)
#define MACDSP_API_SENSING_FLAGS_OFFSET      0x0000018C
#define MACDSP_API_SENSING_FLAGS_INDEX       0x00000063
#define MACDSP_API_SENSING_FLAGS_RESET       0x00000000

static inline u32 macdsp_api_sensing_flags_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR);
}

static inline void macdsp_api_sensing_flags_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SENSING_FLAGS_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SENSING_FLAGS_IMAGING_SN_MASK    ((u32)0x0000C000)
#define MACDSP_API_SENSING_FLAGS_IMAGING_SN_LSB    14
#define MACDSP_API_SENSING_FLAGS_IMAGING_SN_WIDTH    ((u32)0x00000002)
#define MACDSP_API_SENSING_FLAGS_FFT_FOR_SLOW_BLOCK_ACK_BIT    ((u32)0x00002000)
#define MACDSP_API_SENSING_FLAGS_FFT_FOR_SLOW_BLOCK_ACK_POS    13
#define MACDSP_API_SENSING_FLAGS_PRI_ENABLED_BIT    ((u32)0x00001000)
#define MACDSP_API_SENSING_FLAGS_PRI_ENABLED_POS    12
#define MACDSP_API_SENSING_FLAGS_SYNC_CHAIN_MASK    ((u32)0x00000C00)
#define MACDSP_API_SENSING_FLAGS_SYNC_CHAIN_LSB    10
#define MACDSP_API_SENSING_FLAGS_SYNC_CHAIN_WIDTH    ((u32)0x00000002)
#define MACDSP_API_SENSING_FLAGS_ANGLES_ACK_MESSAGE_BIT    ((u32)0x00000200)
#define MACDSP_API_SENSING_FLAGS_ANGLES_ACK_MESSAGE_POS    9
#define MACDSP_API_SENSING_FLAGS_ABS_ACK_MESSAGE_BIT    ((u32)0x00000100)
#define MACDSP_API_SENSING_FLAGS_ABS_ACK_MESSAGE_POS    8
#define MACDSP_API_SENSING_FLAGS_FFT_ACK_MESSAGE_BIT    ((u32)0x00000080)
#define MACDSP_API_SENSING_FLAGS_FFT_ACK_MESSAGE_POS    7
#define MACDSP_API_SENSING_FLAGS_GUI_CNTL_BIT    ((u32)0x00000040)
#define MACDSP_API_SENSING_FLAGS_GUI_CNTL_POS    6
#define MACDSP_API_SENSING_FLAGS_NUM_OF_STREAM_MASK    ((u32)0x00000030)
#define MACDSP_API_SENSING_FLAGS_NUM_OF_STREAM_LSB    4
#define MACDSP_API_SENSING_FLAGS_NUM_OF_STREAM_WIDTH    ((u32)0x00000002)
#define MACDSP_API_SENSING_FLAGS_END_MODE_BIT    ((u32)0x00000004)
#define MACDSP_API_SENSING_FLAGS_END_MODE_POS    2
#define MACDSP_API_SENSING_FLAGS_RX_MODE_BIT    ((u32)0x00000002)
#define MACDSP_API_SENSING_FLAGS_RX_MODE_POS    1
#define MACDSP_API_SENSING_FLAGS_TX_MODE_BIT    ((u32)0x00000001)
#define MACDSP_API_SENSING_FLAGS_TX_MODE_POS    0

#define MACDSP_API_SENSING_FLAGS_IMAGING_SN_RST    0x0
#define MACDSP_API_SENSING_FLAGS_FFT_FOR_SLOW_BLOCK_ACK_RST    0x0
#define MACDSP_API_SENSING_FLAGS_PRI_ENABLED_RST    0x0
#define MACDSP_API_SENSING_FLAGS_SYNC_CHAIN_RST    0x0
#define MACDSP_API_SENSING_FLAGS_ANGLES_ACK_MESSAGE_RST    0x0
#define MACDSP_API_SENSING_FLAGS_ABS_ACK_MESSAGE_RST    0x0
#define MACDSP_API_SENSING_FLAGS_FFT_ACK_MESSAGE_RST    0x0
#define MACDSP_API_SENSING_FLAGS_GUI_CNTL_RST    0x0
#define MACDSP_API_SENSING_FLAGS_NUM_OF_STREAM_RST    0x0
#define MACDSP_API_SENSING_FLAGS_END_MODE_RST    0x0
#define MACDSP_API_SENSING_FLAGS_RX_MODE_RST    0x0
#define MACDSP_API_SENSING_FLAGS_TX_MODE_RST    0x0

static inline void macdsp_api_sensing_flags_pack(struct cl_chip *chip, u8 imaging_sn, u8 fft_for_slow_block_ack, u8 pri_enabled, u8 sync_chain, u8 angles_ack_message, u8 abs_ack_message, u8 fft_ack_message, u8 gui_cntl, u8 num_of_stream, u8 end_mode, u8 rx_mode, u8 tx_mode)
{
	ASSERT_ERR_CHIP((((u32)imaging_sn << 14) & ~((u32)0x0000C000)) == 0);
	ASSERT_ERR_CHIP((((u32)fft_for_slow_block_ack << 13) & ~((u32)0x00002000)) == 0);
	ASSERT_ERR_CHIP((((u32)pri_enabled << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)sync_chain << 10) & ~((u32)0x00000C00)) == 0);
	ASSERT_ERR_CHIP((((u32)angles_ack_message << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)abs_ack_message << 8) & ~((u32)0x00000100)) == 0);
	ASSERT_ERR_CHIP((((u32)fft_ack_message << 7) & ~((u32)0x00000080)) == 0);
	ASSERT_ERR_CHIP((((u32)gui_cntl << 6) & ~((u32)0x00000040)) == 0);
	ASSERT_ERR_CHIP((((u32)num_of_stream << 4) & ~((u32)0x00000030)) == 0);
	ASSERT_ERR_CHIP((((u32)end_mode << 2) & ~((u32)0x00000004)) == 0);
	ASSERT_ERR_CHIP((((u32)rx_mode << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)tx_mode << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_FLAGS_ADDR, ((u32)imaging_sn << 14) | ((u32)fft_for_slow_block_ack << 13) | ((u32)pri_enabled << 12) | ((u32)sync_chain << 10) | ((u32)angles_ack_message << 9) | ((u32)abs_ack_message << 8) | ((u32)fft_ack_message << 7) | ((u32)gui_cntl << 6) | ((u32)num_of_stream << 4) | ((u32)end_mode << 2) | ((u32)rx_mode << 1) | ((u32)tx_mode << 0));
}

static inline void macdsp_api_sensing_flags_unpack(struct cl_chip *chip, u8 *imaging_sn, u8 *fft_for_slow_block_ack, u8 *pri_enabled, u8 *sync_chain, u8 *angles_ack_message, u8 *abs_ack_message, u8 *fft_ack_message, u8 *gui_cntl, u8 *num_of_stream, u8 *end_mode, u8 *rx_mode, u8 *tx_mode)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR);

	*imaging_sn = (local_val & ((u32)0x0000C000)) >> 14;
	*fft_for_slow_block_ack = (local_val & ((u32)0x00002000)) >> 13;
	*pri_enabled = (local_val & ((u32)0x00001000)) >> 12;
	*sync_chain = (local_val & ((u32)0x00000C00)) >> 10;
	*angles_ack_message = (local_val & ((u32)0x00000200)) >> 9;
	*abs_ack_message = (local_val & ((u32)0x00000100)) >> 8;
	*fft_ack_message = (local_val & ((u32)0x00000080)) >> 7;
	*gui_cntl = (local_val & ((u32)0x00000040)) >> 6;
	*num_of_stream = (local_val & ((u32)0x00000030)) >> 4;
	*end_mode = (local_val & ((u32)0x00000004)) >> 2;
	*rx_mode = (local_val & ((u32)0x00000002)) >> 1;
	*tx_mode = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 macdsp_api_sensing_flags_imaging_sn_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR);

	return (u8)((local_val & ((u32)0x0000C000)) >> 14);
}

static inline void macdsp_api_sensing_flags_imaging_sn_setf(struct cl_chip *chip, u8 imagingsn)
{
	ASSERT_ERR_CHIP((((u32)imagingsn << 14) & ~((u32)0x0000C000)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_FLAGS_ADDR, (cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR) & ~((u32)0x0000C000)) | ((u32)imagingsn << 14));
}

static inline u8 macdsp_api_sensing_flags_fft_for_slow_block_ack_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR);

	return (u8)((local_val & ((u32)0x00002000)) >> 13);
}

static inline void macdsp_api_sensing_flags_fft_for_slow_block_ack_setf(struct cl_chip *chip, u8 fftforslowblockack)
{
	ASSERT_ERR_CHIP((((u32)fftforslowblockack << 13) & ~((u32)0x00002000)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_FLAGS_ADDR, (cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR) & ~((u32)0x00002000)) | ((u32)fftforslowblockack << 13));
}

static inline u8 macdsp_api_sensing_flags_pri_enabled_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void macdsp_api_sensing_flags_pri_enabled_setf(struct cl_chip *chip, u8 prienabled)
{
	ASSERT_ERR_CHIP((((u32)prienabled << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_FLAGS_ADDR, (cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR) & ~((u32)0x00001000)) | ((u32)prienabled << 12));
}

static inline u8 macdsp_api_sensing_flags_sync_chain_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR);

	return (u8)((local_val & ((u32)0x00000C00)) >> 10);
}

static inline void macdsp_api_sensing_flags_sync_chain_setf(struct cl_chip *chip, u8 syncchain)
{
	ASSERT_ERR_CHIP((((u32)syncchain << 10) & ~((u32)0x00000C00)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_FLAGS_ADDR, (cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR) & ~((u32)0x00000C00)) | ((u32)syncchain << 10));
}

static inline u8 macdsp_api_sensing_flags_angles_ack_message_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void macdsp_api_sensing_flags_angles_ack_message_setf(struct cl_chip *chip, u8 anglesackmessage)
{
	ASSERT_ERR_CHIP((((u32)anglesackmessage << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_FLAGS_ADDR, (cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR) & ~((u32)0x00000200)) | ((u32)anglesackmessage << 9));
}

static inline u8 macdsp_api_sensing_flags_abs_ack_message_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR);

	return (u8)((local_val & ((u32)0x00000100)) >> 8);
}

static inline void macdsp_api_sensing_flags_abs_ack_message_setf(struct cl_chip *chip, u8 absackmessage)
{
	ASSERT_ERR_CHIP((((u32)absackmessage << 8) & ~((u32)0x00000100)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_FLAGS_ADDR, (cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR) & ~((u32)0x00000100)) | ((u32)absackmessage << 8));
}

static inline u8 macdsp_api_sensing_flags_fft_ack_message_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR);

	return (u8)((local_val & ((u32)0x00000080)) >> 7);
}

static inline void macdsp_api_sensing_flags_fft_ack_message_setf(struct cl_chip *chip, u8 fftackmessage)
{
	ASSERT_ERR_CHIP((((u32)fftackmessage << 7) & ~((u32)0x00000080)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_FLAGS_ADDR, (cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR) & ~((u32)0x00000080)) | ((u32)fftackmessage << 7));
}

static inline u8 macdsp_api_sensing_flags_gui_cntl_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR);

	return (u8)((local_val & ((u32)0x00000040)) >> 6);
}

static inline void macdsp_api_sensing_flags_gui_cntl_setf(struct cl_chip *chip, u8 guicntl)
{
	ASSERT_ERR_CHIP((((u32)guicntl << 6) & ~((u32)0x00000040)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_FLAGS_ADDR, (cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR) & ~((u32)0x00000040)) | ((u32)guicntl << 6));
}

static inline u8 macdsp_api_sensing_flags_num_of_stream_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR);

	return (u8)((local_val & ((u32)0x00000030)) >> 4);
}

static inline void macdsp_api_sensing_flags_num_of_stream_setf(struct cl_chip *chip, u8 numofstream)
{
	ASSERT_ERR_CHIP((((u32)numofstream << 4) & ~((u32)0x00000030)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_FLAGS_ADDR, (cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR) & ~((u32)0x00000030)) | ((u32)numofstream << 4));
}

static inline u8 macdsp_api_sensing_flags_end_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR);

	return (u8)((local_val & ((u32)0x00000004)) >> 2);
}

static inline void macdsp_api_sensing_flags_end_mode_setf(struct cl_chip *chip, u8 endmode)
{
	ASSERT_ERR_CHIP((((u32)endmode << 2) & ~((u32)0x00000004)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_FLAGS_ADDR, (cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR) & ~((u32)0x00000004)) | ((u32)endmode << 2));
}

static inline u8 macdsp_api_sensing_flags_rx_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void macdsp_api_sensing_flags_rx_mode_setf(struct cl_chip *chip, u8 rxmode)
{
	ASSERT_ERR_CHIP((((u32)rxmode << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_FLAGS_ADDR, (cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR) & ~((u32)0x00000002)) | ((u32)rxmode << 1));
}

static inline u8 macdsp_api_sensing_flags_tx_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void macdsp_api_sensing_flags_tx_mode_setf(struct cl_chip *chip, u8 txmode)
{
	ASSERT_ERR_CHIP((((u32)txmode << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_FLAGS_ADDR, (cl_reg_read(chip, MACDSP_API_SENSING_FLAGS_ADDR) & ~((u32)0x00000001)) | ((u32)txmode << 0));
}

/**
 * @brief SENSING_DSP_MAC_CONTROL register definition
 *  SENSING_DSP_MAC_CONTROL register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:08 N_FRAMES                  0x0
 *    07:00 N_TAPS                    0x0
 * </pre>
 */
#define MACDSP_API_SENSING_DSP_MAC_CONTROL_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000190)
#define MACDSP_API_SENSING_DSP_MAC_CONTROL_OFFSET      0x00000190
#define MACDSP_API_SENSING_DSP_MAC_CONTROL_INDEX       0x00000064
#define MACDSP_API_SENSING_DSP_MAC_CONTROL_RESET       0x00000000

static inline u32 macdsp_api_sensing_dsp_mac_control_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SENSING_DSP_MAC_CONTROL_ADDR);
}

static inline void macdsp_api_sensing_dsp_mac_control_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SENSING_DSP_MAC_CONTROL_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SENSING_DSP_MAC_CONTROL_N_FRAMES_MASK    ((u32)0xFFFFFF00)
#define MACDSP_API_SENSING_DSP_MAC_CONTROL_N_FRAMES_LSB    8
#define MACDSP_API_SENSING_DSP_MAC_CONTROL_N_FRAMES_WIDTH    ((u32)0x00000018)
#define MACDSP_API_SENSING_DSP_MAC_CONTROL_N_TAPS_MASK    ((u32)0x000000FF)
#define MACDSP_API_SENSING_DSP_MAC_CONTROL_N_TAPS_LSB    0
#define MACDSP_API_SENSING_DSP_MAC_CONTROL_N_TAPS_WIDTH    ((u32)0x00000008)

#define MACDSP_API_SENSING_DSP_MAC_CONTROL_N_FRAMES_RST    0x0
#define MACDSP_API_SENSING_DSP_MAC_CONTROL_N_TAPS_RST    0x0

static inline void macdsp_api_sensing_dsp_mac_control_pack(struct cl_chip *chip, u32 n_frames, u8 n_taps)
{
	ASSERT_ERR_CHIP((((u32)n_frames << 8) & ~((u32)0xFFFFFF00)) == 0);
	ASSERT_ERR_CHIP((((u32)n_taps << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_DSP_MAC_CONTROL_ADDR, ((u32)n_frames << 8) | ((u32)n_taps << 0));
}

static inline void macdsp_api_sensing_dsp_mac_control_unpack(struct cl_chip *chip, u32 *n_frames, u8 *n_taps)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_DSP_MAC_CONTROL_ADDR);

	*n_frames = (local_val & ((u32)0xFFFFFF00)) >> 8;
	*n_taps = (local_val & ((u32)0x000000FF)) >> 0;
}

static inline u32 macdsp_api_sensing_dsp_mac_control_n_frames_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_DSP_MAC_CONTROL_ADDR);

	return (u32)((local_val & ((u32)0xFFFFFF00)) >> 8);
}

static inline void macdsp_api_sensing_dsp_mac_control_n_frames_setf(struct cl_chip *chip, u32 nframes)
{
	ASSERT_ERR_CHIP((((u32)nframes << 8) & ~((u32)0xFFFFFF00)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_DSP_MAC_CONTROL_ADDR, (cl_reg_read(chip, MACDSP_API_SENSING_DSP_MAC_CONTROL_ADDR) & ~((u32)0xFFFFFF00)) | ((u32)nframes << 8));
}

static inline u8 macdsp_api_sensing_dsp_mac_control_n_taps_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_DSP_MAC_CONTROL_ADDR);

	return (u8)((local_val & ((u32)0x000000FF)) >> 0);
}

static inline void macdsp_api_sensing_dsp_mac_control_n_taps_setf(struct cl_chip *chip, u8 ntaps)
{
	ASSERT_ERR_CHIP((((u32)ntaps << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_DSP_MAC_CONTROL_ADDR, (cl_reg_read(chip, MACDSP_API_SENSING_DSP_MAC_CONTROL_ADDR) & ~((u32)0x000000FF)) | ((u32)ntaps << 0));
}

/**
 * @brief SENSING_SANITY_CHECK register definition
 *  SENSING_SANITY_CHECK register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    23:08 FFT_HOST_BUFFER_SIZE      0x3FF
 *    07:00 SAMPLE_SIZE               0x28
 * </pre>
 */
#define MACDSP_API_SENSING_SANITY_CHECK_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000194)
#define MACDSP_API_SENSING_SANITY_CHECK_OFFSET      0x00000194
#define MACDSP_API_SENSING_SANITY_CHECK_INDEX       0x00000065
#define MACDSP_API_SENSING_SANITY_CHECK_RESET       0x0003FF28

static inline u32 macdsp_api_sensing_sanity_check_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SENSING_SANITY_CHECK_ADDR);
}

static inline void macdsp_api_sensing_sanity_check_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SENSING_SANITY_CHECK_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SENSING_SANITY_CHECK_FFT_HOST_BUFFER_SIZE_MASK    ((u32)0x00FFFF00)
#define MACDSP_API_SENSING_SANITY_CHECK_FFT_HOST_BUFFER_SIZE_LSB    8
#define MACDSP_API_SENSING_SANITY_CHECK_FFT_HOST_BUFFER_SIZE_WIDTH    ((u32)0x00000010)
#define MACDSP_API_SENSING_SANITY_CHECK_SAMPLE_SIZE_MASK    ((u32)0x000000FF)
#define MACDSP_API_SENSING_SANITY_CHECK_SAMPLE_SIZE_LSB    0
#define MACDSP_API_SENSING_SANITY_CHECK_SAMPLE_SIZE_WIDTH    ((u32)0x00000008)

#define MACDSP_API_SENSING_SANITY_CHECK_FFT_HOST_BUFFER_SIZE_RST    0x3FF
#define MACDSP_API_SENSING_SANITY_CHECK_SAMPLE_SIZE_RST    0x28

static inline void macdsp_api_sensing_sanity_check_pack(struct cl_chip *chip, u16 fft_host_buffer_size, u8 sample_size)
{
	ASSERT_ERR_CHIP((((u32)fft_host_buffer_size << 8) & ~((u32)0x00FFFF00)) == 0);
	ASSERT_ERR_CHIP((((u32)sample_size << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_SANITY_CHECK_ADDR, ((u32)fft_host_buffer_size << 8) | ((u32)sample_size << 0));
}

static inline void macdsp_api_sensing_sanity_check_unpack(struct cl_chip *chip, u16 *fft_host_buffer_size, u8 *sample_size)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_SANITY_CHECK_ADDR);

	*fft_host_buffer_size = (local_val & ((u32)0x00FFFF00)) >> 8;
	*sample_size = (local_val & ((u32)0x000000FF)) >> 0;
}

static inline u16 macdsp_api_sensing_sanity_check_fft_host_buffer_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_SANITY_CHECK_ADDR);

	return (u16)((local_val & ((u32)0x00FFFF00)) >> 8);
}

static inline void macdsp_api_sensing_sanity_check_fft_host_buffer_size_setf(struct cl_chip *chip, u16 ffthostbuffersize)
{
	ASSERT_ERR_CHIP((((u32)ffthostbuffersize << 8) & ~((u32)0x00FFFF00)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_SANITY_CHECK_ADDR, (cl_reg_read(chip, MACDSP_API_SENSING_SANITY_CHECK_ADDR) & ~((u32)0x00FFFF00)) | ((u32)ffthostbuffersize << 8));
}

static inline u8 macdsp_api_sensing_sanity_check_sample_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_SANITY_CHECK_ADDR);

	return (u8)((local_val & ((u32)0x000000FF)) >> 0);
}

static inline void macdsp_api_sensing_sanity_check_sample_size_setf(struct cl_chip *chip, u8 samplesize)
{
	ASSERT_ERR_CHIP((((u32)samplesize << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_SANITY_CHECK_ADDR, (cl_reg_read(chip, MACDSP_API_SENSING_SANITY_CHECK_ADDR) & ~((u32)0x000000FF)) | ((u32)samplesize << 0));
}

/**
 * @brief SENSING_RES_1 register definition
 *  SENSING_RES1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RES1                      0x0
 * </pre>
 */
#define MACDSP_API_SENSING_RES_1_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000198)
#define MACDSP_API_SENSING_RES_1_OFFSET      0x00000198
#define MACDSP_API_SENSING_RES_1_INDEX       0x00000066
#define MACDSP_API_SENSING_RES_1_RESET       0x00000000

static inline u32 macdsp_api_sensing_res_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SENSING_RES_1_ADDR);
}

static inline void macdsp_api_sensing_res_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SENSING_RES_1_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SENSING_RES_1_RES_1_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_SENSING_RES_1_RES_1_LSB    0
#define MACDSP_API_SENSING_RES_1_RES_1_WIDTH    ((u32)0x00000020)

#define MACDSP_API_SENSING_RES_1_RES_1_RST    0x0

static inline u32 macdsp_api_sensing_res_1_res_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SENSING_RES_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_sensing_res_1_res_1_setf(struct cl_chip *chip, u32 res1)
{
	ASSERT_ERR_CHIP((((u32)res1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SENSING_RES_1_ADDR, (u32)res1 << 0);
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
#define MACDSP_API_IDLE_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000300)
#define MACDSP_API_IDLE_COUNTER_OFFSET      0x00000300
#define MACDSP_API_IDLE_COUNTER_INDEX       0x000000C0
#define MACDSP_API_IDLE_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_idle_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_IDLE_COUNTER_ADDR);
}

static inline void macdsp_api_idle_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_IDLE_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_IDLE_COUNTER_IDLE_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_IDLE_COUNTER_IDLE_COUNTER_LSB    0
#define MACDSP_API_IDLE_COUNTER_IDLE_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_IDLE_COUNTER_IDLE_COUNTER_RST    0x0

static inline u16 macdsp_api_idle_counter_idle_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_IDLE_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_idle_counter_idle_counter_setf(struct cl_chip *chip, u16 idlecounter)
{
	ASSERT_ERR_CHIP((((u32)idlecounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_IDLE_COUNTER_ADDR, (u32)idlecounter << 0);
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
#define MACDSP_API_TFU_ERR_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000302)
#define MACDSP_API_TFU_ERR_COUNTER_OFFSET      0x00000302
#define MACDSP_API_TFU_ERR_COUNTER_INDEX       0x000000C0
#define MACDSP_API_TFU_ERR_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_tfu_err_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TFU_ERR_COUNTER_ADDR);
}

static inline void macdsp_api_tfu_err_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TFU_ERR_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TFU_ERR_COUNTER_TFU_ERR_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_TFU_ERR_COUNTER_TFU_ERR_COUNTER_LSB    0
#define MACDSP_API_TFU_ERR_COUNTER_TFU_ERR_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_TFU_ERR_COUNTER_TFU_ERR_COUNTER_RST    0x0

static inline u16 macdsp_api_tfu_err_counter_tfu_err_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TFU_ERR_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_tfu_err_counter_tfu_err_counter_setf(struct cl_chip *chip, u16 tfuerrcounter)
{
	ASSERT_ERR_CHIP((((u32)tfuerrcounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TFU_ERR_COUNTER_ADDR, (u32)tfuerrcounter << 0);
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
#define MACDSP_API_RX_TERMINATE_TOTAL_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000304)
#define MACDSP_API_RX_TERMINATE_TOTAL_COUNTER_OFFSET      0x00000304
#define MACDSP_API_RX_TERMINATE_TOTAL_COUNTER_INDEX       0x000000C1
#define MACDSP_API_RX_TERMINATE_TOTAL_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_total_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TOTAL_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_total_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TOTAL_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TOTAL_COUNTER_RX_TERMINATE_TOTAL_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TOTAL_COUNTER_RX_TERMINATE_TOTAL_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TOTAL_COUNTER_RX_TERMINATE_TOTAL_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TOTAL_COUNTER_RX_TERMINATE_TOTAL_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_total_counter_rx_terminate_total_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TOTAL_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_total_counter_rx_terminate_total_counter_setf(struct cl_chip *chip, u16 rxterminatetotalcounter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetotalcounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TOTAL_COUNTER_ADDR, (u32)rxterminatetotalcounter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_0_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000306)
#define MACDSP_API_RX_TERMINATE_TYPE_0_COUNTER_OFFSET      0x00000306
#define MACDSP_API_RX_TERMINATE_TYPE_0_COUNTER_INDEX       0x000000C1
#define MACDSP_API_RX_TERMINATE_TYPE_0_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_0_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_0_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_0_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_0_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_0_COUNTER_RX_TERMINATE_TYPE_0_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_0_COUNTER_RX_TERMINATE_TYPE_0_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_0_COUNTER_RX_TERMINATE_TYPE_0_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_0_COUNTER_RX_TERMINATE_TYPE_0_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_0_counter_rx_terminate_type_0_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_0_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_0_counter_rx_terminate_type_0_counter_setf(struct cl_chip *chip, u16 rxterminatetype0counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype0counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_0_COUNTER_ADDR, (u32)rxterminatetype0counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_1_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000308)
#define MACDSP_API_RX_TERMINATE_TYPE_1_COUNTER_OFFSET      0x00000308
#define MACDSP_API_RX_TERMINATE_TYPE_1_COUNTER_INDEX       0x000000C2
#define MACDSP_API_RX_TERMINATE_TYPE_1_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_1_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_1_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_1_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_1_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_1_COUNTER_RX_TERMINATE_TYPE_1_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_1_COUNTER_RX_TERMINATE_TYPE_1_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_1_COUNTER_RX_TERMINATE_TYPE_1_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_1_COUNTER_RX_TERMINATE_TYPE_1_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_1_counter_rx_terminate_type_1_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_1_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_1_counter_rx_terminate_type_1_counter_setf(struct cl_chip *chip, u16 rxterminatetype1counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype1counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_1_COUNTER_ADDR, (u32)rxterminatetype1counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_2_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000030A)
#define MACDSP_API_RX_TERMINATE_TYPE_2_COUNTER_OFFSET      0x0000030A
#define MACDSP_API_RX_TERMINATE_TYPE_2_COUNTER_INDEX       0x000000C2
#define MACDSP_API_RX_TERMINATE_TYPE_2_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_2_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_2_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_2_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_2_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_2_COUNTER_RX_TERMINATE_TYPE_2_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_2_COUNTER_RX_TERMINATE_TYPE_2_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_2_COUNTER_RX_TERMINATE_TYPE_2_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_2_COUNTER_RX_TERMINATE_TYPE_2_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_2_counter_rx_terminate_type_2_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_2_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_2_counter_rx_terminate_type_2_counter_setf(struct cl_chip *chip, u16 rxterminatetype2counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype2counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_2_COUNTER_ADDR, (u32)rxterminatetype2counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_3_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000030C)
#define MACDSP_API_RX_TERMINATE_TYPE_3_COUNTER_OFFSET      0x0000030C
#define MACDSP_API_RX_TERMINATE_TYPE_3_COUNTER_INDEX       0x000000C3
#define MACDSP_API_RX_TERMINATE_TYPE_3_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_3_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_3_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_3_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_3_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_3_COUNTER_RX_TERMINATE_TYPE_3_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_3_COUNTER_RX_TERMINATE_TYPE_3_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_3_COUNTER_RX_TERMINATE_TYPE_3_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_3_COUNTER_RX_TERMINATE_TYPE_3_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_3_counter_rx_terminate_type_3_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_3_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_3_counter_rx_terminate_type_3_counter_setf(struct cl_chip *chip, u16 rxterminatetype3counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype3counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_3_COUNTER_ADDR, (u32)rxterminatetype3counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_4_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000030E)
#define MACDSP_API_RX_TERMINATE_TYPE_4_COUNTER_OFFSET      0x0000030E
#define MACDSP_API_RX_TERMINATE_TYPE_4_COUNTER_INDEX       0x000000C3
#define MACDSP_API_RX_TERMINATE_TYPE_4_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_4_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_4_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_4_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_4_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_4_COUNTER_RX_TERMINATE_TYPE_4_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_4_COUNTER_RX_TERMINATE_TYPE_4_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_4_COUNTER_RX_TERMINATE_TYPE_4_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_4_COUNTER_RX_TERMINATE_TYPE_4_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_4_counter_rx_terminate_type_4_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_4_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_4_counter_rx_terminate_type_4_counter_setf(struct cl_chip *chip, u16 rxterminatetype4counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype4counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_4_COUNTER_ADDR, (u32)rxterminatetype4counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_5_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000310)
#define MACDSP_API_RX_TERMINATE_TYPE_5_COUNTER_OFFSET      0x00000310
#define MACDSP_API_RX_TERMINATE_TYPE_5_COUNTER_INDEX       0x000000C4
#define MACDSP_API_RX_TERMINATE_TYPE_5_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_5_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_5_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_5_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_5_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_5_COUNTER_RX_TERMINATE_TYPE_5_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_5_COUNTER_RX_TERMINATE_TYPE_5_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_5_COUNTER_RX_TERMINATE_TYPE_5_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_5_COUNTER_RX_TERMINATE_TYPE_5_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_5_counter_rx_terminate_type_5_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_5_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_5_counter_rx_terminate_type_5_counter_setf(struct cl_chip *chip, u16 rxterminatetype5counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype5counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_5_COUNTER_ADDR, (u32)rxterminatetype5counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_6_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000312)
#define MACDSP_API_RX_TERMINATE_TYPE_6_COUNTER_OFFSET      0x00000312
#define MACDSP_API_RX_TERMINATE_TYPE_6_COUNTER_INDEX       0x000000C4
#define MACDSP_API_RX_TERMINATE_TYPE_6_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_6_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_6_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_6_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_6_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_6_COUNTER_RX_TERMINATE_TYPE_6_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_6_COUNTER_RX_TERMINATE_TYPE_6_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_6_COUNTER_RX_TERMINATE_TYPE_6_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_6_COUNTER_RX_TERMINATE_TYPE_6_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_6_counter_rx_terminate_type_6_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_6_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_6_counter_rx_terminate_type_6_counter_setf(struct cl_chip *chip, u16 rxterminatetype6counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype6counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_6_COUNTER_ADDR, (u32)rxterminatetype6counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_7_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000314)
#define MACDSP_API_RX_TERMINATE_TYPE_7_COUNTER_OFFSET      0x00000314
#define MACDSP_API_RX_TERMINATE_TYPE_7_COUNTER_INDEX       0x000000C5
#define MACDSP_API_RX_TERMINATE_TYPE_7_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_7_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_7_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_7_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_7_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_7_COUNTER_RX_TERMINATE_TYPE_7_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_7_COUNTER_RX_TERMINATE_TYPE_7_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_7_COUNTER_RX_TERMINATE_TYPE_7_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_7_COUNTER_RX_TERMINATE_TYPE_7_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_7_counter_rx_terminate_type_7_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_7_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_7_counter_rx_terminate_type_7_counter_setf(struct cl_chip *chip, u16 rxterminatetype7counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype7counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_7_COUNTER_ADDR, (u32)rxterminatetype7counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_8_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000316)
#define MACDSP_API_RX_TERMINATE_TYPE_8_COUNTER_OFFSET      0x00000316
#define MACDSP_API_RX_TERMINATE_TYPE_8_COUNTER_INDEX       0x000000C5
#define MACDSP_API_RX_TERMINATE_TYPE_8_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_8_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_8_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_8_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_8_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_8_COUNTER_RX_TERMINATE_TYPE_8_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_8_COUNTER_RX_TERMINATE_TYPE_8_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_8_COUNTER_RX_TERMINATE_TYPE_8_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_8_COUNTER_RX_TERMINATE_TYPE_8_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_8_counter_rx_terminate_type_8_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_8_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_8_counter_rx_terminate_type_8_counter_setf(struct cl_chip *chip, u16 rxterminatetype8counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype8counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_8_COUNTER_ADDR, (u32)rxterminatetype8counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_9_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000318)
#define MACDSP_API_RX_TERMINATE_TYPE_9_COUNTER_OFFSET      0x00000318
#define MACDSP_API_RX_TERMINATE_TYPE_9_COUNTER_INDEX       0x000000C6
#define MACDSP_API_RX_TERMINATE_TYPE_9_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_9_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_9_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_9_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_9_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_9_COUNTER_RX_TERMINATE_TYPE_9_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_9_COUNTER_RX_TERMINATE_TYPE_9_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_9_COUNTER_RX_TERMINATE_TYPE_9_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_9_COUNTER_RX_TERMINATE_TYPE_9_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_9_counter_rx_terminate_type_9_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_9_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_9_counter_rx_terminate_type_9_counter_setf(struct cl_chip *chip, u16 rxterminatetype9counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype9counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_9_COUNTER_ADDR, (u32)rxterminatetype9counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_10_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000031A)
#define MACDSP_API_RX_TERMINATE_TYPE_10_COUNTER_OFFSET      0x0000031A
#define MACDSP_API_RX_TERMINATE_TYPE_10_COUNTER_INDEX       0x000000C6
#define MACDSP_API_RX_TERMINATE_TYPE_10_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_10_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_10_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_10_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_10_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_10_COUNTER_RX_TERMINATE_TYPE_10_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_10_COUNTER_RX_TERMINATE_TYPE_10_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_10_COUNTER_RX_TERMINATE_TYPE_10_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_10_COUNTER_RX_TERMINATE_TYPE_10_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_10_counter_rx_terminate_type_10_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_10_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_10_counter_rx_terminate_type_10_counter_setf(struct cl_chip *chip, u16 rxterminatetype10counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype10counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_10_COUNTER_ADDR, (u32)rxterminatetype10counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_11_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000031C)
#define MACDSP_API_RX_TERMINATE_TYPE_11_COUNTER_OFFSET      0x0000031C
#define MACDSP_API_RX_TERMINATE_TYPE_11_COUNTER_INDEX       0x000000C7
#define MACDSP_API_RX_TERMINATE_TYPE_11_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_11_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_11_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_11_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_11_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_11_COUNTER_RX_TERMINATE_TYPE_11_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_11_COUNTER_RX_TERMINATE_TYPE_11_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_11_COUNTER_RX_TERMINATE_TYPE_11_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_11_COUNTER_RX_TERMINATE_TYPE_11_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_11_counter_rx_terminate_type_11_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_11_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_11_counter_rx_terminate_type_11_counter_setf(struct cl_chip *chip, u16 rxterminatetype11counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype11counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_11_COUNTER_ADDR, (u32)rxterminatetype11counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_12_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000031E)
#define MACDSP_API_RX_TERMINATE_TYPE_12_COUNTER_OFFSET      0x0000031E
#define MACDSP_API_RX_TERMINATE_TYPE_12_COUNTER_INDEX       0x000000C7
#define MACDSP_API_RX_TERMINATE_TYPE_12_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_12_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_12_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_12_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_12_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_12_COUNTER_RX_TERMINATE_TYPE_12_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_12_COUNTER_RX_TERMINATE_TYPE_12_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_12_COUNTER_RX_TERMINATE_TYPE_12_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_12_COUNTER_RX_TERMINATE_TYPE_12_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_12_counter_rx_terminate_type_12_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_12_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_12_counter_rx_terminate_type_12_counter_setf(struct cl_chip *chip, u16 rxterminatetype12counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype12counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_12_COUNTER_ADDR, (u32)rxterminatetype12counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_13_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000320)
#define MACDSP_API_RX_TERMINATE_TYPE_13_COUNTER_OFFSET      0x00000320
#define MACDSP_API_RX_TERMINATE_TYPE_13_COUNTER_INDEX       0x000000C8
#define MACDSP_API_RX_TERMINATE_TYPE_13_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_13_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_13_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_13_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_13_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_13_COUNTER_RX_TERMINATE_TYPE_13_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_13_COUNTER_RX_TERMINATE_TYPE_13_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_13_COUNTER_RX_TERMINATE_TYPE_13_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_13_COUNTER_RX_TERMINATE_TYPE_13_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_13_counter_rx_terminate_type_13_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_13_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_13_counter_rx_terminate_type_13_counter_setf(struct cl_chip *chip, u16 rxterminatetype13counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype13counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_13_COUNTER_ADDR, (u32)rxterminatetype13counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_14_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000322)
#define MACDSP_API_RX_TERMINATE_TYPE_14_COUNTER_OFFSET      0x00000322
#define MACDSP_API_RX_TERMINATE_TYPE_14_COUNTER_INDEX       0x000000C8
#define MACDSP_API_RX_TERMINATE_TYPE_14_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_14_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_14_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_14_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_14_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_14_COUNTER_RX_TERMINATE_TYPE_14_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_14_COUNTER_RX_TERMINATE_TYPE_14_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_14_COUNTER_RX_TERMINATE_TYPE_14_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_14_COUNTER_RX_TERMINATE_TYPE_14_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_14_counter_rx_terminate_type_14_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_14_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_14_counter_rx_terminate_type_14_counter_setf(struct cl_chip *chip, u16 rxterminatetype14counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype14counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_14_COUNTER_ADDR, (u32)rxterminatetype14counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_15_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000324)
#define MACDSP_API_RX_TERMINATE_TYPE_15_COUNTER_OFFSET      0x00000324
#define MACDSP_API_RX_TERMINATE_TYPE_15_COUNTER_INDEX       0x000000C9
#define MACDSP_API_RX_TERMINATE_TYPE_15_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_15_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_15_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_15_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_15_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_15_COUNTER_RX_TERMINATE_TYPE_15_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_15_COUNTER_RX_TERMINATE_TYPE_15_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_15_COUNTER_RX_TERMINATE_TYPE_15_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_15_COUNTER_RX_TERMINATE_TYPE_15_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_15_counter_rx_terminate_type_15_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_15_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_15_counter_rx_terminate_type_15_counter_setf(struct cl_chip *chip, u16 rxterminatetype15counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype15counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_15_COUNTER_ADDR, (u32)rxterminatetype15counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_16_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000326)
#define MACDSP_API_RX_TERMINATE_TYPE_16_COUNTER_OFFSET      0x00000326
#define MACDSP_API_RX_TERMINATE_TYPE_16_COUNTER_INDEX       0x000000C9
#define MACDSP_API_RX_TERMINATE_TYPE_16_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_16_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_16_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_16_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_16_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_16_COUNTER_RX_TERMINATE_TYPE_16_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_16_COUNTER_RX_TERMINATE_TYPE_16_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_16_COUNTER_RX_TERMINATE_TYPE_16_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_16_COUNTER_RX_TERMINATE_TYPE_16_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_16_counter_rx_terminate_type_16_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_16_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_16_counter_rx_terminate_type_16_counter_setf(struct cl_chip *chip, u16 rxterminatetype16counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype16counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_16_COUNTER_ADDR, (u32)rxterminatetype16counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_17_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000328)
#define MACDSP_API_RX_TERMINATE_TYPE_17_COUNTER_OFFSET      0x00000328
#define MACDSP_API_RX_TERMINATE_TYPE_17_COUNTER_INDEX       0x000000CA
#define MACDSP_API_RX_TERMINATE_TYPE_17_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_17_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_17_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_17_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_17_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_17_COUNTER_RX_TERMINATE_TYPE_17_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_17_COUNTER_RX_TERMINATE_TYPE_17_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_17_COUNTER_RX_TERMINATE_TYPE_17_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_17_COUNTER_RX_TERMINATE_TYPE_17_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_17_counter_rx_terminate_type_17_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_17_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_17_counter_rx_terminate_type_17_counter_setf(struct cl_chip *chip, u16 rxterminatetype17counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype17counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_17_COUNTER_ADDR, (u32)rxterminatetype17counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_18_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000032A)
#define MACDSP_API_RX_TERMINATE_TYPE_18_COUNTER_OFFSET      0x0000032A
#define MACDSP_API_RX_TERMINATE_TYPE_18_COUNTER_INDEX       0x000000CA
#define MACDSP_API_RX_TERMINATE_TYPE_18_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_18_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_18_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_18_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_18_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_18_COUNTER_RX_TERMINATE_TYPE_18_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_18_COUNTER_RX_TERMINATE_TYPE_18_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_18_COUNTER_RX_TERMINATE_TYPE_18_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_18_COUNTER_RX_TERMINATE_TYPE_18_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_18_counter_rx_terminate_type_18_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_18_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_18_counter_rx_terminate_type_18_counter_setf(struct cl_chip *chip, u16 rxterminatetype18counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype18counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_18_COUNTER_ADDR, (u32)rxterminatetype18counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_19_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000032C)
#define MACDSP_API_RX_TERMINATE_TYPE_19_COUNTER_OFFSET      0x0000032C
#define MACDSP_API_RX_TERMINATE_TYPE_19_COUNTER_INDEX       0x000000CB
#define MACDSP_API_RX_TERMINATE_TYPE_19_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_19_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_19_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_19_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_19_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_19_COUNTER_RX_TERMINATE_TYPE_19_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_19_COUNTER_RX_TERMINATE_TYPE_19_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_19_COUNTER_RX_TERMINATE_TYPE_19_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_19_COUNTER_RX_TERMINATE_TYPE_19_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_19_counter_rx_terminate_type_19_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_19_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_19_counter_rx_terminate_type_19_counter_setf(struct cl_chip *chip, u16 rxterminatetype19counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype19counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_19_COUNTER_ADDR, (u32)rxterminatetype19counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_20_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000032E)
#define MACDSP_API_RX_TERMINATE_TYPE_20_COUNTER_OFFSET      0x0000032E
#define MACDSP_API_RX_TERMINATE_TYPE_20_COUNTER_INDEX       0x000000CB
#define MACDSP_API_RX_TERMINATE_TYPE_20_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_20_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_20_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_20_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_20_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_20_COUNTER_RX_TERMINATE_TYPE_20_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_20_COUNTER_RX_TERMINATE_TYPE_20_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_20_COUNTER_RX_TERMINATE_TYPE_20_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_20_COUNTER_RX_TERMINATE_TYPE_20_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_20_counter_rx_terminate_type_20_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_20_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_20_counter_rx_terminate_type_20_counter_setf(struct cl_chip *chip, u16 rxterminatetype20counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype20counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_20_COUNTER_ADDR, (u32)rxterminatetype20counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_21_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000330)
#define MACDSP_API_RX_TERMINATE_TYPE_21_COUNTER_OFFSET      0x00000330
#define MACDSP_API_RX_TERMINATE_TYPE_21_COUNTER_INDEX       0x000000CC
#define MACDSP_API_RX_TERMINATE_TYPE_21_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_21_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_21_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_21_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_21_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_21_COUNTER_RX_TERMINATE_TYPE_21_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_21_COUNTER_RX_TERMINATE_TYPE_21_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_21_COUNTER_RX_TERMINATE_TYPE_21_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_21_COUNTER_RX_TERMINATE_TYPE_21_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_21_counter_rx_terminate_type_21_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_21_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_21_counter_rx_terminate_type_21_counter_setf(struct cl_chip *chip, u16 rxterminatetype21counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype21counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_21_COUNTER_ADDR, (u32)rxterminatetype21counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_22_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000332)
#define MACDSP_API_RX_TERMINATE_TYPE_22_COUNTER_OFFSET      0x00000332
#define MACDSP_API_RX_TERMINATE_TYPE_22_COUNTER_INDEX       0x000000CC
#define MACDSP_API_RX_TERMINATE_TYPE_22_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_22_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_22_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_22_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_22_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_22_COUNTER_RX_TERMINATE_TYPE_22_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_22_COUNTER_RX_TERMINATE_TYPE_22_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_22_COUNTER_RX_TERMINATE_TYPE_22_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_22_COUNTER_RX_TERMINATE_TYPE_22_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_22_counter_rx_terminate_type_22_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_22_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_22_counter_rx_terminate_type_22_counter_setf(struct cl_chip *chip, u16 rxterminatetype22counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype22counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_22_COUNTER_ADDR, (u32)rxterminatetype22counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_23_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000334)
#define MACDSP_API_RX_TERMINATE_TYPE_23_COUNTER_OFFSET      0x00000334
#define MACDSP_API_RX_TERMINATE_TYPE_23_COUNTER_INDEX       0x000000CD
#define MACDSP_API_RX_TERMINATE_TYPE_23_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_23_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_23_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_23_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_23_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_23_COUNTER_RX_TERMINATE_TYPE_23_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_23_COUNTER_RX_TERMINATE_TYPE_23_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_23_COUNTER_RX_TERMINATE_TYPE_23_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_23_COUNTER_RX_TERMINATE_TYPE_23_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_23_counter_rx_terminate_type_23_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_23_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_23_counter_rx_terminate_type_23_counter_setf(struct cl_chip *chip, u16 rxterminatetype23counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype23counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_23_COUNTER_ADDR, (u32)rxterminatetype23counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_24_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000336)
#define MACDSP_API_RX_TERMINATE_TYPE_24_COUNTER_OFFSET      0x00000336
#define MACDSP_API_RX_TERMINATE_TYPE_24_COUNTER_INDEX       0x000000CD
#define MACDSP_API_RX_TERMINATE_TYPE_24_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_24_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_24_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_24_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_24_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_24_COUNTER_RX_TERMINATE_TYPE_24_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_24_COUNTER_RX_TERMINATE_TYPE_24_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_24_COUNTER_RX_TERMINATE_TYPE_24_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_24_COUNTER_RX_TERMINATE_TYPE_24_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_24_counter_rx_terminate_type_24_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_24_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_24_counter_rx_terminate_type_24_counter_setf(struct cl_chip *chip, u16 rxterminatetype24counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype24counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_24_COUNTER_ADDR, (u32)rxterminatetype24counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_25_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000338)
#define MACDSP_API_RX_TERMINATE_TYPE_25_COUNTER_OFFSET      0x00000338
#define MACDSP_API_RX_TERMINATE_TYPE_25_COUNTER_INDEX       0x000000CE
#define MACDSP_API_RX_TERMINATE_TYPE_25_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_25_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_25_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_25_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_25_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_25_COUNTER_RX_TERMINATE_TYPE_25_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_25_COUNTER_RX_TERMINATE_TYPE_25_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_25_COUNTER_RX_TERMINATE_TYPE_25_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_25_COUNTER_RX_TERMINATE_TYPE_25_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_25_counter_rx_terminate_type_25_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_25_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_25_counter_rx_terminate_type_25_counter_setf(struct cl_chip *chip, u16 rxterminatetype25counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype25counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_25_COUNTER_ADDR, (u32)rxterminatetype25counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_26_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000033A)
#define MACDSP_API_RX_TERMINATE_TYPE_26_COUNTER_OFFSET      0x0000033A
#define MACDSP_API_RX_TERMINATE_TYPE_26_COUNTER_INDEX       0x000000CE
#define MACDSP_API_RX_TERMINATE_TYPE_26_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_26_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_26_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_26_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_26_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_26_COUNTER_RX_TERMINATE_TYPE_26_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_26_COUNTER_RX_TERMINATE_TYPE_26_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_26_COUNTER_RX_TERMINATE_TYPE_26_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_26_COUNTER_RX_TERMINATE_TYPE_26_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_26_counter_rx_terminate_type_26_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_26_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_26_counter_rx_terminate_type_26_counter_setf(struct cl_chip *chip, u16 rxterminatetype26counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype26counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_26_COUNTER_ADDR, (u32)rxterminatetype26counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_27_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000033C)
#define MACDSP_API_RX_TERMINATE_TYPE_27_COUNTER_OFFSET      0x0000033C
#define MACDSP_API_RX_TERMINATE_TYPE_27_COUNTER_INDEX       0x000000CF
#define MACDSP_API_RX_TERMINATE_TYPE_27_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_27_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_27_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_27_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_27_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_27_COUNTER_RX_TERMINATE_TYPE_27_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_27_COUNTER_RX_TERMINATE_TYPE_27_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_27_COUNTER_RX_TERMINATE_TYPE_27_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_27_COUNTER_RX_TERMINATE_TYPE_27_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_27_counter_rx_terminate_type_27_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_27_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_27_counter_rx_terminate_type_27_counter_setf(struct cl_chip *chip, u16 rxterminatetype27counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype27counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_27_COUNTER_ADDR, (u32)rxterminatetype27counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_28_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000033E)
#define MACDSP_API_RX_TERMINATE_TYPE_28_COUNTER_OFFSET      0x0000033E
#define MACDSP_API_RX_TERMINATE_TYPE_28_COUNTER_INDEX       0x000000CF
#define MACDSP_API_RX_TERMINATE_TYPE_28_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_28_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_28_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_28_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_28_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_28_COUNTER_RX_TERMINATE_TYPE_28_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_28_COUNTER_RX_TERMINATE_TYPE_28_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_28_COUNTER_RX_TERMINATE_TYPE_28_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_28_COUNTER_RX_TERMINATE_TYPE_28_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_28_counter_rx_terminate_type_28_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_28_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_28_counter_rx_terminate_type_28_counter_setf(struct cl_chip *chip, u16 rxterminatetype28counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype28counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_28_COUNTER_ADDR, (u32)rxterminatetype28counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_29_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000340)
#define MACDSP_API_RX_TERMINATE_TYPE_29_COUNTER_OFFSET      0x00000340
#define MACDSP_API_RX_TERMINATE_TYPE_29_COUNTER_INDEX       0x000000D0
#define MACDSP_API_RX_TERMINATE_TYPE_29_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_29_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_29_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_29_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_29_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_29_COUNTER_RX_TERMINATE_TYPE_29_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_29_COUNTER_RX_TERMINATE_TYPE_29_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_29_COUNTER_RX_TERMINATE_TYPE_29_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_29_COUNTER_RX_TERMINATE_TYPE_29_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_29_counter_rx_terminate_type_29_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_29_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_29_counter_rx_terminate_type_29_counter_setf(struct cl_chip *chip, u16 rxterminatetype29counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype29counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_29_COUNTER_ADDR, (u32)rxterminatetype29counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_30_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000342)
#define MACDSP_API_RX_TERMINATE_TYPE_30_COUNTER_OFFSET      0x00000342
#define MACDSP_API_RX_TERMINATE_TYPE_30_COUNTER_INDEX       0x000000D0
#define MACDSP_API_RX_TERMINATE_TYPE_30_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_30_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_30_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_30_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_30_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_30_COUNTER_RX_TERMINATE_TYPE_30_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_30_COUNTER_RX_TERMINATE_TYPE_30_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_30_COUNTER_RX_TERMINATE_TYPE_30_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_30_COUNTER_RX_TERMINATE_TYPE_30_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_30_counter_rx_terminate_type_30_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_30_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_30_counter_rx_terminate_type_30_counter_setf(struct cl_chip *chip, u16 rxterminatetype30counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype30counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_30_COUNTER_ADDR, (u32)rxterminatetype30counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_31_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000344)
#define MACDSP_API_RX_TERMINATE_TYPE_31_COUNTER_OFFSET      0x00000344
#define MACDSP_API_RX_TERMINATE_TYPE_31_COUNTER_INDEX       0x000000D1
#define MACDSP_API_RX_TERMINATE_TYPE_31_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_31_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_31_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_31_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_31_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_31_COUNTER_RX_TERMINATE_TYPE_31_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_31_COUNTER_RX_TERMINATE_TYPE_31_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_31_COUNTER_RX_TERMINATE_TYPE_31_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_31_COUNTER_RX_TERMINATE_TYPE_31_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_31_counter_rx_terminate_type_31_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_31_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_31_counter_rx_terminate_type_31_counter_setf(struct cl_chip *chip, u16 rxterminatetype31counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype31counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_31_COUNTER_ADDR, (u32)rxterminatetype31counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_32_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000346)
#define MACDSP_API_RX_TERMINATE_TYPE_32_COUNTER_OFFSET      0x00000346
#define MACDSP_API_RX_TERMINATE_TYPE_32_COUNTER_INDEX       0x000000D1
#define MACDSP_API_RX_TERMINATE_TYPE_32_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_32_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_32_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_32_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_32_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_32_COUNTER_RX_TERMINATE_TYPE_32_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_32_COUNTER_RX_TERMINATE_TYPE_32_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_32_COUNTER_RX_TERMINATE_TYPE_32_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_32_COUNTER_RX_TERMINATE_TYPE_32_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_32_counter_rx_terminate_type_32_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_32_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_32_counter_rx_terminate_type_32_counter_setf(struct cl_chip *chip, u16 rxterminatetype32counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype32counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_32_COUNTER_ADDR, (u32)rxterminatetype32counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_33_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000348)
#define MACDSP_API_RX_TERMINATE_TYPE_33_COUNTER_OFFSET      0x00000348
#define MACDSP_API_RX_TERMINATE_TYPE_33_COUNTER_INDEX       0x000000D2
#define MACDSP_API_RX_TERMINATE_TYPE_33_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_33_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_33_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_33_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_33_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_33_COUNTER_RX_TERMINATE_TYPE_33_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_33_COUNTER_RX_TERMINATE_TYPE_33_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_33_COUNTER_RX_TERMINATE_TYPE_33_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_33_COUNTER_RX_TERMINATE_TYPE_33_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_33_counter_rx_terminate_type_33_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_33_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_33_counter_rx_terminate_type_33_counter_setf(struct cl_chip *chip, u16 rxterminatetype33counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype33counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_33_COUNTER_ADDR, (u32)rxterminatetype33counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_34_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000034A)
#define MACDSP_API_RX_TERMINATE_TYPE_34_COUNTER_OFFSET      0x0000034A
#define MACDSP_API_RX_TERMINATE_TYPE_34_COUNTER_INDEX       0x000000D2
#define MACDSP_API_RX_TERMINATE_TYPE_34_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_34_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_34_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_34_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_34_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_34_COUNTER_RX_TERMINATE_TYPE_34_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_34_COUNTER_RX_TERMINATE_TYPE_34_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_34_COUNTER_RX_TERMINATE_TYPE_34_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_34_COUNTER_RX_TERMINATE_TYPE_34_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_34_counter_rx_terminate_type_34_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_34_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_34_counter_rx_terminate_type_34_counter_setf(struct cl_chip *chip, u16 rxterminatetype34counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype34counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_34_COUNTER_ADDR, (u32)rxterminatetype34counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_35_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000034C)
#define MACDSP_API_RX_TERMINATE_TYPE_35_COUNTER_OFFSET      0x0000034C
#define MACDSP_API_RX_TERMINATE_TYPE_35_COUNTER_INDEX       0x000000D3
#define MACDSP_API_RX_TERMINATE_TYPE_35_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_35_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_35_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_35_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_35_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_35_COUNTER_RX_TERMINATE_TYPE_35_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_35_COUNTER_RX_TERMINATE_TYPE_35_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_35_COUNTER_RX_TERMINATE_TYPE_35_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_35_COUNTER_RX_TERMINATE_TYPE_35_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_35_counter_rx_terminate_type_35_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_35_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_35_counter_rx_terminate_type_35_counter_setf(struct cl_chip *chip, u16 rxterminatetype35counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype35counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_35_COUNTER_ADDR, (u32)rxterminatetype35counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_36_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000034E)
#define MACDSP_API_RX_TERMINATE_TYPE_36_COUNTER_OFFSET      0x0000034E
#define MACDSP_API_RX_TERMINATE_TYPE_36_COUNTER_INDEX       0x000000D3
#define MACDSP_API_RX_TERMINATE_TYPE_36_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_36_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_36_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_36_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_36_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_36_COUNTER_RX_TERMINATE_TYPE_36_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_36_COUNTER_RX_TERMINATE_TYPE_36_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_36_COUNTER_RX_TERMINATE_TYPE_36_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_36_COUNTER_RX_TERMINATE_TYPE_36_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_36_counter_rx_terminate_type_36_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_36_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_36_counter_rx_terminate_type_36_counter_setf(struct cl_chip *chip, u16 rxterminatetype36counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype36counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_36_COUNTER_ADDR, (u32)rxterminatetype36counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_37_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000350)
#define MACDSP_API_RX_TERMINATE_TYPE_37_COUNTER_OFFSET      0x00000350
#define MACDSP_API_RX_TERMINATE_TYPE_37_COUNTER_INDEX       0x000000D4
#define MACDSP_API_RX_TERMINATE_TYPE_37_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_37_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_37_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_37_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_37_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_37_COUNTER_RX_TERMINATE_TYPE_37_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_37_COUNTER_RX_TERMINATE_TYPE_37_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_37_COUNTER_RX_TERMINATE_TYPE_37_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_37_COUNTER_RX_TERMINATE_TYPE_37_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_37_counter_rx_terminate_type_37_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_37_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_37_counter_rx_terminate_type_37_counter_setf(struct cl_chip *chip, u16 rxterminatetype37counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype37counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_37_COUNTER_ADDR, (u32)rxterminatetype37counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_38_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000352)
#define MACDSP_API_RX_TERMINATE_TYPE_38_COUNTER_OFFSET      0x00000352
#define MACDSP_API_RX_TERMINATE_TYPE_38_COUNTER_INDEX       0x000000D4
#define MACDSP_API_RX_TERMINATE_TYPE_38_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_38_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_38_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_38_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_38_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_38_COUNTER_RX_TERMINATE_TYPE_38_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_38_COUNTER_RX_TERMINATE_TYPE_38_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_38_COUNTER_RX_TERMINATE_TYPE_38_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_38_COUNTER_RX_TERMINATE_TYPE_38_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_38_counter_rx_terminate_type_38_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_38_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_38_counter_rx_terminate_type_38_counter_setf(struct cl_chip *chip, u16 rxterminatetype38counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype38counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_38_COUNTER_ADDR, (u32)rxterminatetype38counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_39_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000354)
#define MACDSP_API_RX_TERMINATE_TYPE_39_COUNTER_OFFSET      0x00000354
#define MACDSP_API_RX_TERMINATE_TYPE_39_COUNTER_INDEX       0x000000D5
#define MACDSP_API_RX_TERMINATE_TYPE_39_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_39_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_39_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_39_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_39_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_39_COUNTER_RX_TERMINATE_TYPE_39_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_39_COUNTER_RX_TERMINATE_TYPE_39_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_39_COUNTER_RX_TERMINATE_TYPE_39_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_39_COUNTER_RX_TERMINATE_TYPE_39_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_39_counter_rx_terminate_type_39_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_39_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_39_counter_rx_terminate_type_39_counter_setf(struct cl_chip *chip, u16 rxterminatetype39counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype39counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_39_COUNTER_ADDR, (u32)rxterminatetype39counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_40_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000356)
#define MACDSP_API_RX_TERMINATE_TYPE_40_COUNTER_OFFSET      0x00000356
#define MACDSP_API_RX_TERMINATE_TYPE_40_COUNTER_INDEX       0x000000D5
#define MACDSP_API_RX_TERMINATE_TYPE_40_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_40_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_40_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_40_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_40_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_40_COUNTER_RX_TERMINATE_TYPE_40_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_40_COUNTER_RX_TERMINATE_TYPE_40_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_40_COUNTER_RX_TERMINATE_TYPE_40_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_40_COUNTER_RX_TERMINATE_TYPE_40_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_40_counter_rx_terminate_type_40_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_40_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_40_counter_rx_terminate_type_40_counter_setf(struct cl_chip *chip, u16 rxterminatetype40counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype40counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_40_COUNTER_ADDR, (u32)rxterminatetype40counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_41_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000358)
#define MACDSP_API_RX_TERMINATE_TYPE_41_COUNTER_OFFSET      0x00000358
#define MACDSP_API_RX_TERMINATE_TYPE_41_COUNTER_INDEX       0x000000D6
#define MACDSP_API_RX_TERMINATE_TYPE_41_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_41_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_41_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_41_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_41_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_41_COUNTER_RX_TERMINATE_TYPE_41_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_41_COUNTER_RX_TERMINATE_TYPE_41_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_41_COUNTER_RX_TERMINATE_TYPE_41_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_41_COUNTER_RX_TERMINATE_TYPE_41_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_41_counter_rx_terminate_type_41_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_41_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_41_counter_rx_terminate_type_41_counter_setf(struct cl_chip *chip, u16 rxterminatetype41counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype41counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_41_COUNTER_ADDR, (u32)rxterminatetype41counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_42_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000035A)
#define MACDSP_API_RX_TERMINATE_TYPE_42_COUNTER_OFFSET      0x0000035A
#define MACDSP_API_RX_TERMINATE_TYPE_42_COUNTER_INDEX       0x000000D6
#define MACDSP_API_RX_TERMINATE_TYPE_42_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_42_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_42_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_42_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_42_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_42_COUNTER_RX_TERMINATE_TYPE_42_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_42_COUNTER_RX_TERMINATE_TYPE_42_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_42_COUNTER_RX_TERMINATE_TYPE_42_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_42_COUNTER_RX_TERMINATE_TYPE_42_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_42_counter_rx_terminate_type_42_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_42_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_42_counter_rx_terminate_type_42_counter_setf(struct cl_chip *chip, u16 rxterminatetype42counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype42counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_42_COUNTER_ADDR, (u32)rxterminatetype42counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_43_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000035C)
#define MACDSP_API_RX_TERMINATE_TYPE_43_COUNTER_OFFSET      0x0000035C
#define MACDSP_API_RX_TERMINATE_TYPE_43_COUNTER_INDEX       0x000000D7
#define MACDSP_API_RX_TERMINATE_TYPE_43_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_43_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_43_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_43_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_43_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_43_COUNTER_RX_TERMINATE_TYPE_43_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_43_COUNTER_RX_TERMINATE_TYPE_43_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_43_COUNTER_RX_TERMINATE_TYPE_43_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_43_COUNTER_RX_TERMINATE_TYPE_43_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_43_counter_rx_terminate_type_43_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_43_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_43_counter_rx_terminate_type_43_counter_setf(struct cl_chip *chip, u16 rxterminatetype43counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype43counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_43_COUNTER_ADDR, (u32)rxterminatetype43counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_44_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000035E)
#define MACDSP_API_RX_TERMINATE_TYPE_44_COUNTER_OFFSET      0x0000035E
#define MACDSP_API_RX_TERMINATE_TYPE_44_COUNTER_INDEX       0x000000D7
#define MACDSP_API_RX_TERMINATE_TYPE_44_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_44_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_44_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_44_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_44_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_44_COUNTER_RX_TERMINATE_TYPE_44_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_44_COUNTER_RX_TERMINATE_TYPE_44_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_44_COUNTER_RX_TERMINATE_TYPE_44_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_44_COUNTER_RX_TERMINATE_TYPE_44_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_44_counter_rx_terminate_type_44_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_44_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_44_counter_rx_terminate_type_44_counter_setf(struct cl_chip *chip, u16 rxterminatetype44counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype44counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_44_COUNTER_ADDR, (u32)rxterminatetype44counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_45_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000360)
#define MACDSP_API_RX_TERMINATE_TYPE_45_COUNTER_OFFSET      0x00000360
#define MACDSP_API_RX_TERMINATE_TYPE_45_COUNTER_INDEX       0x000000D8
#define MACDSP_API_RX_TERMINATE_TYPE_45_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_45_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_45_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_45_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_45_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_45_COUNTER_RX_TERMINATE_TYPE_45_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_45_COUNTER_RX_TERMINATE_TYPE_45_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_45_COUNTER_RX_TERMINATE_TYPE_45_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_45_COUNTER_RX_TERMINATE_TYPE_45_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_45_counter_rx_terminate_type_45_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_45_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_45_counter_rx_terminate_type_45_counter_setf(struct cl_chip *chip, u16 rxterminatetype45counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype45counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_45_COUNTER_ADDR, (u32)rxterminatetype45counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_46_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000362)
#define MACDSP_API_RX_TERMINATE_TYPE_46_COUNTER_OFFSET      0x00000362
#define MACDSP_API_RX_TERMINATE_TYPE_46_COUNTER_INDEX       0x000000D8
#define MACDSP_API_RX_TERMINATE_TYPE_46_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_46_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_46_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_46_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_46_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_46_COUNTER_RX_TERMINATE_TYPE_46_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_46_COUNTER_RX_TERMINATE_TYPE_46_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_46_COUNTER_RX_TERMINATE_TYPE_46_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_46_COUNTER_RX_TERMINATE_TYPE_46_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_46_counter_rx_terminate_type_46_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_46_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_46_counter_rx_terminate_type_46_counter_setf(struct cl_chip *chip, u16 rxterminatetype46counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype46counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_46_COUNTER_ADDR, (u32)rxterminatetype46counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_47_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000364)
#define MACDSP_API_RX_TERMINATE_TYPE_47_COUNTER_OFFSET      0x00000364
#define MACDSP_API_RX_TERMINATE_TYPE_47_COUNTER_INDEX       0x000000D9
#define MACDSP_API_RX_TERMINATE_TYPE_47_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_47_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_47_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_47_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_47_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_47_COUNTER_RX_TERMINATE_TYPE_47_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_47_COUNTER_RX_TERMINATE_TYPE_47_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_47_COUNTER_RX_TERMINATE_TYPE_47_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_47_COUNTER_RX_TERMINATE_TYPE_47_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_47_counter_rx_terminate_type_47_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_47_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_47_counter_rx_terminate_type_47_counter_setf(struct cl_chip *chip, u16 rxterminatetype47counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype47counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_47_COUNTER_ADDR, (u32)rxterminatetype47counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_48_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000366)
#define MACDSP_API_RX_TERMINATE_TYPE_48_COUNTER_OFFSET      0x00000366
#define MACDSP_API_RX_TERMINATE_TYPE_48_COUNTER_INDEX       0x000000D9
#define MACDSP_API_RX_TERMINATE_TYPE_48_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_48_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_48_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_48_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_48_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_48_COUNTER_RX_TERMINATE_TYPE_48_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_48_COUNTER_RX_TERMINATE_TYPE_48_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_48_COUNTER_RX_TERMINATE_TYPE_48_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_48_COUNTER_RX_TERMINATE_TYPE_48_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_48_counter_rx_terminate_type_48_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_48_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_48_counter_rx_terminate_type_48_counter_setf(struct cl_chip *chip, u16 rxterminatetype48counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype48counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_48_COUNTER_ADDR, (u32)rxterminatetype48counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_49_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000368)
#define MACDSP_API_RX_TERMINATE_TYPE_49_COUNTER_OFFSET      0x00000368
#define MACDSP_API_RX_TERMINATE_TYPE_49_COUNTER_INDEX       0x000000DA
#define MACDSP_API_RX_TERMINATE_TYPE_49_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_49_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_49_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_49_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_49_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_49_COUNTER_RX_TERMINATE_TYPE_49_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_49_COUNTER_RX_TERMINATE_TYPE_49_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_49_COUNTER_RX_TERMINATE_TYPE_49_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_49_COUNTER_RX_TERMINATE_TYPE_49_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_49_counter_rx_terminate_type_49_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_49_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_49_counter_rx_terminate_type_49_counter_setf(struct cl_chip *chip, u16 rxterminatetype49counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype49counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_49_COUNTER_ADDR, (u32)rxterminatetype49counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_50_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000036A)
#define MACDSP_API_RX_TERMINATE_TYPE_50_COUNTER_OFFSET      0x0000036A
#define MACDSP_API_RX_TERMINATE_TYPE_50_COUNTER_INDEX       0x000000DA
#define MACDSP_API_RX_TERMINATE_TYPE_50_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_50_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_50_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_50_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_50_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_50_COUNTER_RX_TERMINATE_TYPE_50_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_50_COUNTER_RX_TERMINATE_TYPE_50_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_50_COUNTER_RX_TERMINATE_TYPE_50_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_50_COUNTER_RX_TERMINATE_TYPE_50_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_50_counter_rx_terminate_type_50_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_50_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_50_counter_rx_terminate_type_50_counter_setf(struct cl_chip *chip, u16 rxterminatetype50counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype50counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_50_COUNTER_ADDR, (u32)rxterminatetype50counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_51_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000036C)
#define MACDSP_API_RX_TERMINATE_TYPE_51_COUNTER_OFFSET      0x0000036C
#define MACDSP_API_RX_TERMINATE_TYPE_51_COUNTER_INDEX       0x000000DB
#define MACDSP_API_RX_TERMINATE_TYPE_51_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_51_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_51_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_51_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_51_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_51_COUNTER_RX_TERMINATE_TYPE_51_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_51_COUNTER_RX_TERMINATE_TYPE_51_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_51_COUNTER_RX_TERMINATE_TYPE_51_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_51_COUNTER_RX_TERMINATE_TYPE_51_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_51_counter_rx_terminate_type_51_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_51_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_51_counter_rx_terminate_type_51_counter_setf(struct cl_chip *chip, u16 rxterminatetype51counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype51counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_51_COUNTER_ADDR, (u32)rxterminatetype51counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_52_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000036E)
#define MACDSP_API_RX_TERMINATE_TYPE_52_COUNTER_OFFSET      0x0000036E
#define MACDSP_API_RX_TERMINATE_TYPE_52_COUNTER_INDEX       0x000000DB
#define MACDSP_API_RX_TERMINATE_TYPE_52_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_52_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_52_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_52_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_52_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_52_COUNTER_RX_TERMINATE_TYPE_52_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_52_COUNTER_RX_TERMINATE_TYPE_52_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_52_COUNTER_RX_TERMINATE_TYPE_52_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_52_COUNTER_RX_TERMINATE_TYPE_52_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_52_counter_rx_terminate_type_52_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_52_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_52_counter_rx_terminate_type_52_counter_setf(struct cl_chip *chip, u16 rxterminatetype52counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype52counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_52_COUNTER_ADDR, (u32)rxterminatetype52counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_53_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000370)
#define MACDSP_API_RX_TERMINATE_TYPE_53_COUNTER_OFFSET      0x00000370
#define MACDSP_API_RX_TERMINATE_TYPE_53_COUNTER_INDEX       0x000000DC
#define MACDSP_API_RX_TERMINATE_TYPE_53_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_53_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_53_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_53_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_53_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_53_COUNTER_RX_TERMINATE_TYPE_53_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_53_COUNTER_RX_TERMINATE_TYPE_53_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_53_COUNTER_RX_TERMINATE_TYPE_53_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_53_COUNTER_RX_TERMINATE_TYPE_53_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_53_counter_rx_terminate_type_53_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_53_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_53_counter_rx_terminate_type_53_counter_setf(struct cl_chip *chip, u16 rxterminatetype53counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype53counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_53_COUNTER_ADDR, (u32)rxterminatetype53counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_54_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000372)
#define MACDSP_API_RX_TERMINATE_TYPE_54_COUNTER_OFFSET      0x00000372
#define MACDSP_API_RX_TERMINATE_TYPE_54_COUNTER_INDEX       0x000000DC
#define MACDSP_API_RX_TERMINATE_TYPE_54_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_54_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_54_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_54_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_54_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_54_COUNTER_RX_TERMINATE_TYPE_54_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_54_COUNTER_RX_TERMINATE_TYPE_54_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_54_COUNTER_RX_TERMINATE_TYPE_54_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_54_COUNTER_RX_TERMINATE_TYPE_54_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_54_counter_rx_terminate_type_54_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_54_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_54_counter_rx_terminate_type_54_counter_setf(struct cl_chip *chip, u16 rxterminatetype54counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype54counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_54_COUNTER_ADDR, (u32)rxterminatetype54counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_55_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000374)
#define MACDSP_API_RX_TERMINATE_TYPE_55_COUNTER_OFFSET      0x00000374
#define MACDSP_API_RX_TERMINATE_TYPE_55_COUNTER_INDEX       0x000000DD
#define MACDSP_API_RX_TERMINATE_TYPE_55_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_55_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_55_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_55_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_55_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_55_COUNTER_RX_TERMINATE_TYPE_55_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_55_COUNTER_RX_TERMINATE_TYPE_55_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_55_COUNTER_RX_TERMINATE_TYPE_55_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_55_COUNTER_RX_TERMINATE_TYPE_55_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_55_counter_rx_terminate_type_55_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_55_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_55_counter_rx_terminate_type_55_counter_setf(struct cl_chip *chip, u16 rxterminatetype55counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype55counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_55_COUNTER_ADDR, (u32)rxterminatetype55counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_56_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000376)
#define MACDSP_API_RX_TERMINATE_TYPE_56_COUNTER_OFFSET      0x00000376
#define MACDSP_API_RX_TERMINATE_TYPE_56_COUNTER_INDEX       0x000000DD
#define MACDSP_API_RX_TERMINATE_TYPE_56_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_56_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_56_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_56_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_56_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_56_COUNTER_RX_TERMINATE_TYPE_56_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_56_COUNTER_RX_TERMINATE_TYPE_56_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_56_COUNTER_RX_TERMINATE_TYPE_56_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_56_COUNTER_RX_TERMINATE_TYPE_56_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_56_counter_rx_terminate_type_56_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_56_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_56_counter_rx_terminate_type_56_counter_setf(struct cl_chip *chip, u16 rxterminatetype56counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype56counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_56_COUNTER_ADDR, (u32)rxterminatetype56counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_57_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000378)
#define MACDSP_API_RX_TERMINATE_TYPE_57_COUNTER_OFFSET      0x00000378
#define MACDSP_API_RX_TERMINATE_TYPE_57_COUNTER_INDEX       0x000000DE
#define MACDSP_API_RX_TERMINATE_TYPE_57_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_57_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_57_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_57_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_57_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_57_COUNTER_RX_TERMINATE_TYPE_57_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_57_COUNTER_RX_TERMINATE_TYPE_57_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_57_COUNTER_RX_TERMINATE_TYPE_57_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_57_COUNTER_RX_TERMINATE_TYPE_57_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_57_counter_rx_terminate_type_57_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_57_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_57_counter_rx_terminate_type_57_counter_setf(struct cl_chip *chip, u16 rxterminatetype57counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype57counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_57_COUNTER_ADDR, (u32)rxterminatetype57counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_58_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000037A)
#define MACDSP_API_RX_TERMINATE_TYPE_58_COUNTER_OFFSET      0x0000037A
#define MACDSP_API_RX_TERMINATE_TYPE_58_COUNTER_INDEX       0x000000DE
#define MACDSP_API_RX_TERMINATE_TYPE_58_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_58_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_58_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_58_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_58_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_58_COUNTER_RX_TERMINATE_TYPE_58_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_58_COUNTER_RX_TERMINATE_TYPE_58_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_58_COUNTER_RX_TERMINATE_TYPE_58_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_58_COUNTER_RX_TERMINATE_TYPE_58_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_58_counter_rx_terminate_type_58_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_58_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_58_counter_rx_terminate_type_58_counter_setf(struct cl_chip *chip, u16 rxterminatetype58counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype58counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_58_COUNTER_ADDR, (u32)rxterminatetype58counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_59_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000037C)
#define MACDSP_API_RX_TERMINATE_TYPE_59_COUNTER_OFFSET      0x0000037C
#define MACDSP_API_RX_TERMINATE_TYPE_59_COUNTER_INDEX       0x000000DF
#define MACDSP_API_RX_TERMINATE_TYPE_59_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_59_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_59_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_59_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_59_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_59_COUNTER_RX_TERMINATE_TYPE_59_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_59_COUNTER_RX_TERMINATE_TYPE_59_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_59_COUNTER_RX_TERMINATE_TYPE_59_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_59_COUNTER_RX_TERMINATE_TYPE_59_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_59_counter_rx_terminate_type_59_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_59_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_59_counter_rx_terminate_type_59_counter_setf(struct cl_chip *chip, u16 rxterminatetype59counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype59counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_59_COUNTER_ADDR, (u32)rxterminatetype59counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_60_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000037E)
#define MACDSP_API_RX_TERMINATE_TYPE_60_COUNTER_OFFSET      0x0000037E
#define MACDSP_API_RX_TERMINATE_TYPE_60_COUNTER_INDEX       0x000000DF
#define MACDSP_API_RX_TERMINATE_TYPE_60_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_60_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_60_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_60_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_60_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_60_COUNTER_RX_TERMINATE_TYPE_60_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_60_COUNTER_RX_TERMINATE_TYPE_60_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_60_COUNTER_RX_TERMINATE_TYPE_60_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_60_COUNTER_RX_TERMINATE_TYPE_60_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_60_counter_rx_terminate_type_60_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_60_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_60_counter_rx_terminate_type_60_counter_setf(struct cl_chip *chip, u16 rxterminatetype60counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype60counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_60_COUNTER_ADDR, (u32)rxterminatetype60counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_61_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000380)
#define MACDSP_API_RX_TERMINATE_TYPE_61_COUNTER_OFFSET      0x00000380
#define MACDSP_API_RX_TERMINATE_TYPE_61_COUNTER_INDEX       0x000000E0
#define MACDSP_API_RX_TERMINATE_TYPE_61_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_61_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_61_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_61_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_61_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_61_COUNTER_RX_TERMINATE_TYPE_61_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_61_COUNTER_RX_TERMINATE_TYPE_61_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_61_COUNTER_RX_TERMINATE_TYPE_61_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_61_COUNTER_RX_TERMINATE_TYPE_61_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_61_counter_rx_terminate_type_61_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_61_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_61_counter_rx_terminate_type_61_counter_setf(struct cl_chip *chip, u16 rxterminatetype61counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype61counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_61_COUNTER_ADDR, (u32)rxterminatetype61counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_62_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000382)
#define MACDSP_API_RX_TERMINATE_TYPE_62_COUNTER_OFFSET      0x00000382
#define MACDSP_API_RX_TERMINATE_TYPE_62_COUNTER_INDEX       0x000000E0
#define MACDSP_API_RX_TERMINATE_TYPE_62_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_62_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_62_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_62_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_62_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_62_COUNTER_RX_TERMINATE_TYPE_62_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_62_COUNTER_RX_TERMINATE_TYPE_62_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_62_COUNTER_RX_TERMINATE_TYPE_62_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_62_COUNTER_RX_TERMINATE_TYPE_62_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_62_counter_rx_terminate_type_62_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_62_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_62_counter_rx_terminate_type_62_counter_setf(struct cl_chip *chip, u16 rxterminatetype62counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype62counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_62_COUNTER_ADDR, (u32)rxterminatetype62counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_63_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000384)
#define MACDSP_API_RX_TERMINATE_TYPE_63_COUNTER_OFFSET      0x00000384
#define MACDSP_API_RX_TERMINATE_TYPE_63_COUNTER_INDEX       0x000000E1
#define MACDSP_API_RX_TERMINATE_TYPE_63_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_63_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_63_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_63_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_63_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_63_COUNTER_RX_TERMINATE_TYPE_63_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_63_COUNTER_RX_TERMINATE_TYPE_63_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_63_COUNTER_RX_TERMINATE_TYPE_63_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_63_COUNTER_RX_TERMINATE_TYPE_63_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_63_counter_rx_terminate_type_63_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_63_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_63_counter_rx_terminate_type_63_counter_setf(struct cl_chip *chip, u16 rxterminatetype63counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype63counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_63_COUNTER_ADDR, (u32)rxterminatetype63counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_64_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000386)
#define MACDSP_API_RX_TERMINATE_TYPE_64_COUNTER_OFFSET      0x00000386
#define MACDSP_API_RX_TERMINATE_TYPE_64_COUNTER_INDEX       0x000000E1
#define MACDSP_API_RX_TERMINATE_TYPE_64_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_64_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_64_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_64_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_64_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_64_COUNTER_RX_TERMINATE_TYPE_64_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_64_COUNTER_RX_TERMINATE_TYPE_64_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_64_COUNTER_RX_TERMINATE_TYPE_64_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_64_COUNTER_RX_TERMINATE_TYPE_64_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_64_counter_rx_terminate_type_64_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_64_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_64_counter_rx_terminate_type_64_counter_setf(struct cl_chip *chip, u16 rxterminatetype64counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype64counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_64_COUNTER_ADDR, (u32)rxterminatetype64counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_65_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000388)
#define MACDSP_API_RX_TERMINATE_TYPE_65_COUNTER_OFFSET      0x00000388
#define MACDSP_API_RX_TERMINATE_TYPE_65_COUNTER_INDEX       0x000000E2
#define MACDSP_API_RX_TERMINATE_TYPE_65_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_65_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_65_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_65_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_65_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_65_COUNTER_RX_TERMINATE_TYPE_65_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_65_COUNTER_RX_TERMINATE_TYPE_65_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_65_COUNTER_RX_TERMINATE_TYPE_65_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_65_COUNTER_RX_TERMINATE_TYPE_65_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_65_counter_rx_terminate_type_65_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_65_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_65_counter_rx_terminate_type_65_counter_setf(struct cl_chip *chip, u16 rxterminatetype65counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype65counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_65_COUNTER_ADDR, (u32)rxterminatetype65counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_66_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000038A)
#define MACDSP_API_RX_TERMINATE_TYPE_66_COUNTER_OFFSET      0x0000038A
#define MACDSP_API_RX_TERMINATE_TYPE_66_COUNTER_INDEX       0x000000E2
#define MACDSP_API_RX_TERMINATE_TYPE_66_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_66_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_66_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_66_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_66_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_66_COUNTER_RX_TERMINATE_TYPE_66_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_66_COUNTER_RX_TERMINATE_TYPE_66_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_66_COUNTER_RX_TERMINATE_TYPE_66_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_66_COUNTER_RX_TERMINATE_TYPE_66_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_66_counter_rx_terminate_type_66_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_66_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_66_counter_rx_terminate_type_66_counter_setf(struct cl_chip *chip, u16 rxterminatetype66counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype66counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_66_COUNTER_ADDR, (u32)rxterminatetype66counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_67_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000038C)
#define MACDSP_API_RX_TERMINATE_TYPE_67_COUNTER_OFFSET      0x0000038C
#define MACDSP_API_RX_TERMINATE_TYPE_67_COUNTER_INDEX       0x000000E3
#define MACDSP_API_RX_TERMINATE_TYPE_67_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_67_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_67_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_67_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_67_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_67_COUNTER_RX_TERMINATE_TYPE_67_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_67_COUNTER_RX_TERMINATE_TYPE_67_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_67_COUNTER_RX_TERMINATE_TYPE_67_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_67_COUNTER_RX_TERMINATE_TYPE_67_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_67_counter_rx_terminate_type_67_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_67_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_67_counter_rx_terminate_type_67_counter_setf(struct cl_chip *chip, u16 rxterminatetype67counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype67counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_67_COUNTER_ADDR, (u32)rxterminatetype67counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_68_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000038E)
#define MACDSP_API_RX_TERMINATE_TYPE_68_COUNTER_OFFSET      0x0000038E
#define MACDSP_API_RX_TERMINATE_TYPE_68_COUNTER_INDEX       0x000000E3
#define MACDSP_API_RX_TERMINATE_TYPE_68_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_68_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_68_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_68_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_68_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_68_COUNTER_RX_TERMINATE_TYPE_68_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_68_COUNTER_RX_TERMINATE_TYPE_68_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_68_COUNTER_RX_TERMINATE_TYPE_68_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_68_COUNTER_RX_TERMINATE_TYPE_68_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_68_counter_rx_terminate_type_68_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_68_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_68_counter_rx_terminate_type_68_counter_setf(struct cl_chip *chip, u16 rxterminatetype68counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype68counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_68_COUNTER_ADDR, (u32)rxterminatetype68counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_69_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000390)
#define MACDSP_API_RX_TERMINATE_TYPE_69_COUNTER_OFFSET      0x00000390
#define MACDSP_API_RX_TERMINATE_TYPE_69_COUNTER_INDEX       0x000000E4
#define MACDSP_API_RX_TERMINATE_TYPE_69_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_69_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_69_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_69_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_69_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_69_COUNTER_RX_TERMINATE_TYPE_69_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_69_COUNTER_RX_TERMINATE_TYPE_69_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_69_COUNTER_RX_TERMINATE_TYPE_69_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_69_COUNTER_RX_TERMINATE_TYPE_69_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_69_counter_rx_terminate_type_69_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_69_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_69_counter_rx_terminate_type_69_counter_setf(struct cl_chip *chip, u16 rxterminatetype69counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype69counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_69_COUNTER_ADDR, (u32)rxterminatetype69counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_70_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000392)
#define MACDSP_API_RX_TERMINATE_TYPE_70_COUNTER_OFFSET      0x00000392
#define MACDSP_API_RX_TERMINATE_TYPE_70_COUNTER_INDEX       0x000000E4
#define MACDSP_API_RX_TERMINATE_TYPE_70_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_70_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_70_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_70_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_70_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_70_COUNTER_RX_TERMINATE_TYPE_70_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_70_COUNTER_RX_TERMINATE_TYPE_70_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_70_COUNTER_RX_TERMINATE_TYPE_70_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_70_COUNTER_RX_TERMINATE_TYPE_70_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_70_counter_rx_terminate_type_70_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_70_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_70_counter_rx_terminate_type_70_counter_setf(struct cl_chip *chip, u16 rxterminatetype70counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype70counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_70_COUNTER_ADDR, (u32)rxterminatetype70counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_71_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000394)
#define MACDSP_API_RX_TERMINATE_TYPE_71_COUNTER_OFFSET      0x00000394
#define MACDSP_API_RX_TERMINATE_TYPE_71_COUNTER_INDEX       0x000000E5
#define MACDSP_API_RX_TERMINATE_TYPE_71_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_71_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_71_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_71_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_71_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_71_COUNTER_RX_TERMINATE_TYPE_71_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_71_COUNTER_RX_TERMINATE_TYPE_71_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_71_COUNTER_RX_TERMINATE_TYPE_71_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_71_COUNTER_RX_TERMINATE_TYPE_71_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_71_counter_rx_terminate_type_71_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_71_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_71_counter_rx_terminate_type_71_counter_setf(struct cl_chip *chip, u16 rxterminatetype71counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype71counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_71_COUNTER_ADDR, (u32)rxterminatetype71counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_72_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000396)
#define MACDSP_API_RX_TERMINATE_TYPE_72_COUNTER_OFFSET      0x00000396
#define MACDSP_API_RX_TERMINATE_TYPE_72_COUNTER_INDEX       0x000000E5
#define MACDSP_API_RX_TERMINATE_TYPE_72_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_72_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_72_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_72_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_72_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_72_COUNTER_RX_TERMINATE_TYPE_72_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_72_COUNTER_RX_TERMINATE_TYPE_72_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_72_COUNTER_RX_TERMINATE_TYPE_72_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_72_COUNTER_RX_TERMINATE_TYPE_72_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_72_counter_rx_terminate_type_72_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_72_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_72_counter_rx_terminate_type_72_counter_setf(struct cl_chip *chip, u16 rxterminatetype72counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype72counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_72_COUNTER_ADDR, (u32)rxterminatetype72counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_73_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000398)
#define MACDSP_API_RX_TERMINATE_TYPE_73_COUNTER_OFFSET      0x00000398
#define MACDSP_API_RX_TERMINATE_TYPE_73_COUNTER_INDEX       0x000000E6
#define MACDSP_API_RX_TERMINATE_TYPE_73_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_73_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_73_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_73_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_73_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_73_COUNTER_RX_TERMINATE_TYPE_73_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_73_COUNTER_RX_TERMINATE_TYPE_73_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_73_COUNTER_RX_TERMINATE_TYPE_73_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_73_COUNTER_RX_TERMINATE_TYPE_73_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_73_counter_rx_terminate_type_73_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_73_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_73_counter_rx_terminate_type_73_counter_setf(struct cl_chip *chip, u16 rxterminatetype73counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype73counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_73_COUNTER_ADDR, (u32)rxterminatetype73counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_74_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000039A)
#define MACDSP_API_RX_TERMINATE_TYPE_74_COUNTER_OFFSET      0x0000039A
#define MACDSP_API_RX_TERMINATE_TYPE_74_COUNTER_INDEX       0x000000E6
#define MACDSP_API_RX_TERMINATE_TYPE_74_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_74_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_74_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_74_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_74_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_74_COUNTER_RX_TERMINATE_TYPE_74_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_74_COUNTER_RX_TERMINATE_TYPE_74_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_74_COUNTER_RX_TERMINATE_TYPE_74_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_74_COUNTER_RX_TERMINATE_TYPE_74_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_74_counter_rx_terminate_type_74_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_74_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_74_counter_rx_terminate_type_74_counter_setf(struct cl_chip *chip, u16 rxterminatetype74counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype74counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_74_COUNTER_ADDR, (u32)rxterminatetype74counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_75_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000039C)
#define MACDSP_API_RX_TERMINATE_TYPE_75_COUNTER_OFFSET      0x0000039C
#define MACDSP_API_RX_TERMINATE_TYPE_75_COUNTER_INDEX       0x000000E7
#define MACDSP_API_RX_TERMINATE_TYPE_75_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_75_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_75_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_75_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_75_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_75_COUNTER_RX_TERMINATE_TYPE_75_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_75_COUNTER_RX_TERMINATE_TYPE_75_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_75_COUNTER_RX_TERMINATE_TYPE_75_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_75_COUNTER_RX_TERMINATE_TYPE_75_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_75_counter_rx_terminate_type_75_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_75_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_75_counter_rx_terminate_type_75_counter_setf(struct cl_chip *chip, u16 rxterminatetype75counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype75counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_75_COUNTER_ADDR, (u32)rxterminatetype75counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_76_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000039E)
#define MACDSP_API_RX_TERMINATE_TYPE_76_COUNTER_OFFSET      0x0000039E
#define MACDSP_API_RX_TERMINATE_TYPE_76_COUNTER_INDEX       0x000000E7
#define MACDSP_API_RX_TERMINATE_TYPE_76_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_76_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_76_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_76_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_76_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_76_COUNTER_RX_TERMINATE_TYPE_76_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_76_COUNTER_RX_TERMINATE_TYPE_76_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_76_COUNTER_RX_TERMINATE_TYPE_76_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_76_COUNTER_RX_TERMINATE_TYPE_76_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_76_counter_rx_terminate_type_76_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_76_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_76_counter_rx_terminate_type_76_counter_setf(struct cl_chip *chip, u16 rxterminatetype76counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype76counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_76_COUNTER_ADDR, (u32)rxterminatetype76counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_77_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000003A0)
#define MACDSP_API_RX_TERMINATE_TYPE_77_COUNTER_OFFSET      0x000003A0
#define MACDSP_API_RX_TERMINATE_TYPE_77_COUNTER_INDEX       0x000000E8
#define MACDSP_API_RX_TERMINATE_TYPE_77_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_77_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_77_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_77_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_77_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_77_COUNTER_RX_TERMINATE_TYPE_77_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_77_COUNTER_RX_TERMINATE_TYPE_77_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_77_COUNTER_RX_TERMINATE_TYPE_77_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_77_COUNTER_RX_TERMINATE_TYPE_77_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_77_counter_rx_terminate_type_77_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_77_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_77_counter_rx_terminate_type_77_counter_setf(struct cl_chip *chip, u16 rxterminatetype77counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype77counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_77_COUNTER_ADDR, (u32)rxterminatetype77counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_78_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000003A2)
#define MACDSP_API_RX_TERMINATE_TYPE_78_COUNTER_OFFSET      0x000003A2
#define MACDSP_API_RX_TERMINATE_TYPE_78_COUNTER_INDEX       0x000000E8
#define MACDSP_API_RX_TERMINATE_TYPE_78_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_78_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_78_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_78_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_78_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_78_COUNTER_RX_TERMINATE_TYPE_78_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_78_COUNTER_RX_TERMINATE_TYPE_78_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_78_COUNTER_RX_TERMINATE_TYPE_78_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_78_COUNTER_RX_TERMINATE_TYPE_78_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_78_counter_rx_terminate_type_78_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_78_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_78_counter_rx_terminate_type_78_counter_setf(struct cl_chip *chip, u16 rxterminatetype78counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype78counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_78_COUNTER_ADDR, (u32)rxterminatetype78counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_79_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000003A4)
#define MACDSP_API_RX_TERMINATE_TYPE_79_COUNTER_OFFSET      0x000003A4
#define MACDSP_API_RX_TERMINATE_TYPE_79_COUNTER_INDEX       0x000000E9
#define MACDSP_API_RX_TERMINATE_TYPE_79_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_79_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_79_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_79_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_79_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_79_COUNTER_RX_TERMINATE_TYPE_79_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_79_COUNTER_RX_TERMINATE_TYPE_79_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_79_COUNTER_RX_TERMINATE_TYPE_79_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_79_COUNTER_RX_TERMINATE_TYPE_79_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_79_counter_rx_terminate_type_79_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_79_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_79_counter_rx_terminate_type_79_counter_setf(struct cl_chip *chip, u16 rxterminatetype79counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype79counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_79_COUNTER_ADDR, (u32)rxterminatetype79counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_80_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000003A6)
#define MACDSP_API_RX_TERMINATE_TYPE_80_COUNTER_OFFSET      0x000003A6
#define MACDSP_API_RX_TERMINATE_TYPE_80_COUNTER_INDEX       0x000000E9
#define MACDSP_API_RX_TERMINATE_TYPE_80_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_80_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_80_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_80_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_80_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_80_COUNTER_RX_TERMINATE_TYPE_80_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_80_COUNTER_RX_TERMINATE_TYPE_80_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_80_COUNTER_RX_TERMINATE_TYPE_80_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_80_COUNTER_RX_TERMINATE_TYPE_80_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_80_counter_rx_terminate_type_80_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_80_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_80_counter_rx_terminate_type_80_counter_setf(struct cl_chip *chip, u16 rxterminatetype80counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype80counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_80_COUNTER_ADDR, (u32)rxterminatetype80counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_81_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000003A8)
#define MACDSP_API_RX_TERMINATE_TYPE_81_COUNTER_OFFSET      0x000003A8
#define MACDSP_API_RX_TERMINATE_TYPE_81_COUNTER_INDEX       0x000000EA
#define MACDSP_API_RX_TERMINATE_TYPE_81_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_81_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_81_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_81_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_81_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_81_COUNTER_RX_TERMINATE_TYPE_81_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_81_COUNTER_RX_TERMINATE_TYPE_81_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_81_COUNTER_RX_TERMINATE_TYPE_81_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_81_COUNTER_RX_TERMINATE_TYPE_81_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_81_counter_rx_terminate_type_81_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_81_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_81_counter_rx_terminate_type_81_counter_setf(struct cl_chip *chip, u16 rxterminatetype81counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype81counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_81_COUNTER_ADDR, (u32)rxterminatetype81counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_82_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000003AA)
#define MACDSP_API_RX_TERMINATE_TYPE_82_COUNTER_OFFSET      0x000003AA
#define MACDSP_API_RX_TERMINATE_TYPE_82_COUNTER_INDEX       0x000000EA
#define MACDSP_API_RX_TERMINATE_TYPE_82_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_82_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_82_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_82_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_82_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_82_COUNTER_RX_TERMINATE_TYPE_82_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_82_COUNTER_RX_TERMINATE_TYPE_82_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_82_COUNTER_RX_TERMINATE_TYPE_82_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_82_COUNTER_RX_TERMINATE_TYPE_82_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_82_counter_rx_terminate_type_82_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_82_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_82_counter_rx_terminate_type_82_counter_setf(struct cl_chip *chip, u16 rxterminatetype82counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype82counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_82_COUNTER_ADDR, (u32)rxterminatetype82counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_83_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000003AC)
#define MACDSP_API_RX_TERMINATE_TYPE_83_COUNTER_OFFSET      0x000003AC
#define MACDSP_API_RX_TERMINATE_TYPE_83_COUNTER_INDEX       0x000000EB
#define MACDSP_API_RX_TERMINATE_TYPE_83_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_83_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_83_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_83_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_83_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_83_COUNTER_RX_TERMINATE_TYPE_83_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_83_COUNTER_RX_TERMINATE_TYPE_83_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_83_COUNTER_RX_TERMINATE_TYPE_83_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_83_COUNTER_RX_TERMINATE_TYPE_83_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_83_counter_rx_terminate_type_83_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_83_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_83_counter_rx_terminate_type_83_counter_setf(struct cl_chip *chip, u16 rxterminatetype83counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype83counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_83_COUNTER_ADDR, (u32)rxterminatetype83counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_84_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000003AE)
#define MACDSP_API_RX_TERMINATE_TYPE_84_COUNTER_OFFSET      0x000003AE
#define MACDSP_API_RX_TERMINATE_TYPE_84_COUNTER_INDEX       0x000000EB
#define MACDSP_API_RX_TERMINATE_TYPE_84_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_84_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_84_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_84_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_84_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_84_COUNTER_RX_TERMINATE_TYPE_84_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_84_COUNTER_RX_TERMINATE_TYPE_84_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_84_COUNTER_RX_TERMINATE_TYPE_84_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_84_COUNTER_RX_TERMINATE_TYPE_84_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_84_counter_rx_terminate_type_84_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_84_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_84_counter_rx_terminate_type_84_counter_setf(struct cl_chip *chip, u16 rxterminatetype84counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype84counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_84_COUNTER_ADDR, (u32)rxterminatetype84counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_85_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000003B0)
#define MACDSP_API_RX_TERMINATE_TYPE_85_COUNTER_OFFSET      0x000003B0
#define MACDSP_API_RX_TERMINATE_TYPE_85_COUNTER_INDEX       0x000000EC
#define MACDSP_API_RX_TERMINATE_TYPE_85_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_85_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_85_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_85_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_85_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_85_COUNTER_RX_TERMINATE_TYPE_85_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_85_COUNTER_RX_TERMINATE_TYPE_85_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_85_COUNTER_RX_TERMINATE_TYPE_85_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_85_COUNTER_RX_TERMINATE_TYPE_85_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_85_counter_rx_terminate_type_85_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_85_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_85_counter_rx_terminate_type_85_counter_setf(struct cl_chip *chip, u16 rxterminatetype85counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype85counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_85_COUNTER_ADDR, (u32)rxterminatetype85counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_86_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000003B2)
#define MACDSP_API_RX_TERMINATE_TYPE_86_COUNTER_OFFSET      0x000003B2
#define MACDSP_API_RX_TERMINATE_TYPE_86_COUNTER_INDEX       0x000000EC
#define MACDSP_API_RX_TERMINATE_TYPE_86_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_86_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_86_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_86_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_86_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_86_COUNTER_RX_TERMINATE_TYPE_86_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_86_COUNTER_RX_TERMINATE_TYPE_86_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_86_COUNTER_RX_TERMINATE_TYPE_86_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_86_COUNTER_RX_TERMINATE_TYPE_86_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_86_counter_rx_terminate_type_86_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_86_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_86_counter_rx_terminate_type_86_counter_setf(struct cl_chip *chip, u16 rxterminatetype86counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype86counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_86_COUNTER_ADDR, (u32)rxterminatetype86counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_87_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000003B4)
#define MACDSP_API_RX_TERMINATE_TYPE_87_COUNTER_OFFSET      0x000003B4
#define MACDSP_API_RX_TERMINATE_TYPE_87_COUNTER_INDEX       0x000000ED
#define MACDSP_API_RX_TERMINATE_TYPE_87_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_87_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_87_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_87_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_87_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_87_COUNTER_RX_TERMINATE_TYPE_87_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_87_COUNTER_RX_TERMINATE_TYPE_87_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_87_COUNTER_RX_TERMINATE_TYPE_87_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_87_COUNTER_RX_TERMINATE_TYPE_87_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_87_counter_rx_terminate_type_87_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_87_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_87_counter_rx_terminate_type_87_counter_setf(struct cl_chip *chip, u16 rxterminatetype87counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype87counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_87_COUNTER_ADDR, (u32)rxterminatetype87counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_88_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000003B6)
#define MACDSP_API_RX_TERMINATE_TYPE_88_COUNTER_OFFSET      0x000003B6
#define MACDSP_API_RX_TERMINATE_TYPE_88_COUNTER_INDEX       0x000000ED
#define MACDSP_API_RX_TERMINATE_TYPE_88_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_88_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_88_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_88_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_88_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_88_COUNTER_RX_TERMINATE_TYPE_88_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_88_COUNTER_RX_TERMINATE_TYPE_88_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_88_COUNTER_RX_TERMINATE_TYPE_88_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_88_COUNTER_RX_TERMINATE_TYPE_88_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_88_counter_rx_terminate_type_88_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_88_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_88_counter_rx_terminate_type_88_counter_setf(struct cl_chip *chip, u16 rxterminatetype88counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype88counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_88_COUNTER_ADDR, (u32)rxterminatetype88counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_89_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000003B8)
#define MACDSP_API_RX_TERMINATE_TYPE_89_COUNTER_OFFSET      0x000003B8
#define MACDSP_API_RX_TERMINATE_TYPE_89_COUNTER_INDEX       0x000000EE
#define MACDSP_API_RX_TERMINATE_TYPE_89_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_89_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_89_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_89_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_89_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_89_COUNTER_RX_TERMINATE_TYPE_89_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_89_COUNTER_RX_TERMINATE_TYPE_89_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_89_COUNTER_RX_TERMINATE_TYPE_89_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_89_COUNTER_RX_TERMINATE_TYPE_89_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_89_counter_rx_terminate_type_89_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_89_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_89_counter_rx_terminate_type_89_counter_setf(struct cl_chip *chip, u16 rxterminatetype89counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype89counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_89_COUNTER_ADDR, (u32)rxterminatetype89counter << 0);
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
#define MACDSP_API_RX_TERMINATE_TYPE_90_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000003BA)
#define MACDSP_API_RX_TERMINATE_TYPE_90_COUNTER_OFFSET      0x000003BA
#define MACDSP_API_RX_TERMINATE_TYPE_90_COUNTER_INDEX       0x000000EE
#define MACDSP_API_RX_TERMINATE_TYPE_90_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_terminate_type_90_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_90_COUNTER_ADDR);
}

static inline void macdsp_api_rx_terminate_type_90_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_90_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TERMINATE_TYPE_90_COUNTER_RX_TERMINATE_TYPE_90_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_TERMINATE_TYPE_90_COUNTER_RX_TERMINATE_TYPE_90_COUNTER_LSB    0
#define MACDSP_API_RX_TERMINATE_TYPE_90_COUNTER_RX_TERMINATE_TYPE_90_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_TERMINATE_TYPE_90_COUNTER_RX_TERMINATE_TYPE_90_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_terminate_type_90_counter_rx_terminate_type_90_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TERMINATE_TYPE_90_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_terminate_type_90_counter_rx_terminate_type_90_counter_setf(struct cl_chip *chip, u16 rxterminatetype90counter)
{
	ASSERT_ERR_CHIP((((u32)rxterminatetype90counter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TERMINATE_TYPE_90_COUNTER_ADDR, (u32)rxterminatetype90counter << 0);
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
#define MACDSP_API_PROC_LIM_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000003BC)
#define MACDSP_API_PROC_LIM_COUNTER_OFFSET      0x000003BC
#define MACDSP_API_PROC_LIM_COUNTER_INDEX       0x000000EF
#define MACDSP_API_PROC_LIM_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_proc_lim_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_PROC_LIM_COUNTER_ADDR);
}

static inline void macdsp_api_proc_lim_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_PROC_LIM_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_PROC_LIM_COUNTER_PROC_LIM_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_PROC_LIM_COUNTER_PROC_LIM_COUNTER_LSB    0
#define MACDSP_API_PROC_LIM_COUNTER_PROC_LIM_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_PROC_LIM_COUNTER_PROC_LIM_COUNTER_RST    0x0

static inline u16 macdsp_api_proc_lim_counter_proc_lim_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_PROC_LIM_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_proc_lim_counter_proc_lim_counter_setf(struct cl_chip *chip, u16 proclimcounter)
{
	ASSERT_ERR_CHIP((((u32)proclimcounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_PROC_LIM_COUNTER_ADDR, (u32)proclimcounter << 0);
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
#define MACDSP_API_RESAMPLER_CLIPPING_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000003BE)
#define MACDSP_API_RESAMPLER_CLIPPING_COUNTER_OFFSET      0x000003BE
#define MACDSP_API_RESAMPLER_CLIPPING_COUNTER_INDEX       0x000000EF
#define MACDSP_API_RESAMPLER_CLIPPING_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_resampler_clipping_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RESAMPLER_CLIPPING_COUNTER_ADDR);
}

static inline void macdsp_api_resampler_clipping_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RESAMPLER_CLIPPING_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RESAMPLER_CLIPPING_COUNTER_RESAMPLER_CLIPPING_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RESAMPLER_CLIPPING_COUNTER_RESAMPLER_CLIPPING_COUNTER_LSB    0
#define MACDSP_API_RESAMPLER_CLIPPING_COUNTER_RESAMPLER_CLIPPING_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RESAMPLER_CLIPPING_COUNTER_RESAMPLER_CLIPPING_COUNTER_RST    0x0

static inline u16 macdsp_api_resampler_clipping_counter_resampler_clipping_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RESAMPLER_CLIPPING_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_resampler_clipping_counter_resampler_clipping_counter_setf(struct cl_chip *chip, u16 resamplerclippingcounter)
{
	ASSERT_ERR_CHIP((((u32)resamplerclippingcounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RESAMPLER_CLIPPING_COUNTER_ADDR, (u32)resamplerclippingcounter << 0);
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
#define MACDSP_API_SKIPHOLD_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000003C0)
#define MACDSP_API_SKIPHOLD_COUNTER_OFFSET      0x000003C0
#define MACDSP_API_SKIPHOLD_COUNTER_INDEX       0x000000F0
#define MACDSP_API_SKIPHOLD_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_skiphold_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SKIPHOLD_COUNTER_ADDR);
}

static inline void macdsp_api_skiphold_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SKIPHOLD_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SKIPHOLD_COUNTER_SKIPHOLD_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_SKIPHOLD_COUNTER_SKIPHOLD_COUNTER_LSB    0
#define MACDSP_API_SKIPHOLD_COUNTER_SKIPHOLD_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_SKIPHOLD_COUNTER_SKIPHOLD_COUNTER_RST    0x0

static inline u16 macdsp_api_skiphold_counter_skiphold_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SKIPHOLD_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_skiphold_counter_skiphold_counter_setf(struct cl_chip *chip, u16 skipholdcounter)
{
	ASSERT_ERR_CHIP((((u32)skipholdcounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SKIPHOLD_COUNTER_ADDR, (u32)skipholdcounter << 0);
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
#define MACDSP_API_TX_END_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000003C2)
#define MACDSP_API_TX_END_COUNTER_OFFSET      0x000003C2
#define MACDSP_API_TX_END_COUNTER_INDEX       0x000000F0
#define MACDSP_API_TX_END_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_tx_end_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TX_END_COUNTER_ADDR);
}

static inline void macdsp_api_tx_end_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TX_END_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TX_END_COUNTER_TX_END_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_TX_END_COUNTER_TX_END_COUNTER_LSB    0
#define MACDSP_API_TX_END_COUNTER_TX_END_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_TX_END_COUNTER_TX_END_COUNTER_RST    0x0

static inline u16 macdsp_api_tx_end_counter_tx_end_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_END_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_tx_end_counter_tx_end_counter_setf(struct cl_chip *chip, u16 txendcounter)
{
	ASSERT_ERR_CHIP((((u32)txendcounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_END_COUNTER_ADDR, (u32)txendcounter << 0);
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
#define MACDSP_API_CPE_WRAPPING_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000003C4)
#define MACDSP_API_CPE_WRAPPING_COUNTER_OFFSET      0x000003C4
#define MACDSP_API_CPE_WRAPPING_COUNTER_INDEX       0x000000F1
#define MACDSP_API_CPE_WRAPPING_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_cpe_wrapping_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_CPE_WRAPPING_COUNTER_ADDR);
}

static inline void macdsp_api_cpe_wrapping_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_CPE_WRAPPING_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_CPE_WRAPPING_COUNTER_CPE_WRAPING_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_CPE_WRAPPING_COUNTER_CPE_WRAPING_COUNTER_LSB    0
#define MACDSP_API_CPE_WRAPPING_COUNTER_CPE_WRAPING_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_CPE_WRAPPING_COUNTER_CPE_WRAPING_COUNTER_RST    0x0

static inline u16 macdsp_api_cpe_wrapping_counter_cpe_wraping_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CPE_WRAPPING_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_cpe_wrapping_counter_cpe_wraping_counter_setf(struct cl_chip *chip, u16 cpewrapingcounter)
{
	ASSERT_ERR_CHIP((((u32)cpewrapingcounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_CPE_WRAPPING_COUNTER_ADDR, (u32)cpewrapingcounter << 0);
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
#define MACDSP_API_AGC_UL_DATA_NOT_EXPECTED_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000400)
#define MACDSP_API_AGC_UL_DATA_NOT_EXPECTED_COUNTER_OFFSET      0x00000400
#define MACDSP_API_AGC_UL_DATA_NOT_EXPECTED_COUNTER_INDEX       0x00000100
#define MACDSP_API_AGC_UL_DATA_NOT_EXPECTED_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_agc_ul_data_not_expected_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_AGC_UL_DATA_NOT_EXPECTED_COUNTER_ADDR);
}

static inline void macdsp_api_agc_ul_data_not_expected_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_AGC_UL_DATA_NOT_EXPECTED_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_AGC_UL_DATA_NOT_EXPECTED_COUNTER_AGC_UL_DATA_NOT_EXPECTED_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_AGC_UL_DATA_NOT_EXPECTED_COUNTER_AGC_UL_DATA_NOT_EXPECTED_COUNTER_LSB    0
#define MACDSP_API_AGC_UL_DATA_NOT_EXPECTED_COUNTER_AGC_UL_DATA_NOT_EXPECTED_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_AGC_UL_DATA_NOT_EXPECTED_COUNTER_AGC_UL_DATA_NOT_EXPECTED_COUNTER_RST    0x0

static inline u16 macdsp_api_agc_ul_data_not_expected_counter_agc_ul_data_not_expected_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_AGC_UL_DATA_NOT_EXPECTED_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_agc_ul_data_not_expected_counter_agc_ul_data_not_expected_counter_setf(struct cl_chip *chip, u16 agculdatanotexpectedcounter)
{
	ASSERT_ERR_CHIP((((u32)agculdatanotexpectedcounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_AGC_UL_DATA_NOT_EXPECTED_COUNTER_ADDR, (u32)agculdatanotexpectedcounter << 0);
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
#define MACDSP_API_AGC_UL_IDLE_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000402)
#define MACDSP_API_AGC_UL_IDLE_COUNTER_OFFSET      0x00000402
#define MACDSP_API_AGC_UL_IDLE_COUNTER_INDEX       0x00000100
#define MACDSP_API_AGC_UL_IDLE_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_agc_ul_idle_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_AGC_UL_IDLE_COUNTER_ADDR);
}

static inline void macdsp_api_agc_ul_idle_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_AGC_UL_IDLE_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_AGC_UL_IDLE_COUNTER_AGC_UL_IDLE_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_AGC_UL_IDLE_COUNTER_AGC_UL_IDLE_COUNTER_LSB    0
#define MACDSP_API_AGC_UL_IDLE_COUNTER_AGC_UL_IDLE_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_AGC_UL_IDLE_COUNTER_AGC_UL_IDLE_COUNTER_RST    0x0

static inline u16 macdsp_api_agc_ul_idle_counter_agc_ul_idle_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_AGC_UL_IDLE_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_agc_ul_idle_counter_agc_ul_idle_counter_setf(struct cl_chip *chip, u16 agculidlecounter)
{
	ASSERT_ERR_CHIP((((u32)agculidlecounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_AGC_UL_IDLE_COUNTER_ADDR, (u32)agculidlecounter << 0);
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
#define MACDSP_API_AGC_UL_WHILE_TX_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000404)
#define MACDSP_API_AGC_UL_WHILE_TX_COUNTER_OFFSET      0x00000404
#define MACDSP_API_AGC_UL_WHILE_TX_COUNTER_INDEX       0x00000101
#define MACDSP_API_AGC_UL_WHILE_TX_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_agc_ul_while_tx_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_AGC_UL_WHILE_TX_COUNTER_ADDR);
}

static inline void macdsp_api_agc_ul_while_tx_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_AGC_UL_WHILE_TX_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_AGC_UL_WHILE_TX_COUNTER_AGC_UL_WHILE_TX_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_AGC_UL_WHILE_TX_COUNTER_AGC_UL_WHILE_TX_COUNTER_LSB    0
#define MACDSP_API_AGC_UL_WHILE_TX_COUNTER_AGC_UL_WHILE_TX_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_AGC_UL_WHILE_TX_COUNTER_AGC_UL_WHILE_TX_COUNTER_RST    0x0

static inline u16 macdsp_api_agc_ul_while_tx_counter_agc_ul_while_tx_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_AGC_UL_WHILE_TX_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_agc_ul_while_tx_counter_agc_ul_while_tx_counter_setf(struct cl_chip *chip, u16 agculwhiletxcounter)
{
	ASSERT_ERR_CHIP((((u32)agculwhiletxcounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_AGC_UL_WHILE_TX_COUNTER_ADDR, (u32)agculwhiletxcounter << 0);
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
#define MACDSP_API_PF_SEARCH_ILLEGAL_END_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000406)
#define MACDSP_API_PF_SEARCH_ILLEGAL_END_COUNTER_OFFSET      0x00000406
#define MACDSP_API_PF_SEARCH_ILLEGAL_END_COUNTER_INDEX       0x00000101
#define MACDSP_API_PF_SEARCH_ILLEGAL_END_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_pf_search_illegal_end_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_PF_SEARCH_ILLEGAL_END_COUNTER_ADDR);
}

static inline void macdsp_api_pf_search_illegal_end_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_PF_SEARCH_ILLEGAL_END_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_PF_SEARCH_ILLEGAL_END_COUNTER_PF_SEARCH_ILLEGAL_END_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_PF_SEARCH_ILLEGAL_END_COUNTER_PF_SEARCH_ILLEGAL_END_COUNTER_LSB    0
#define MACDSP_API_PF_SEARCH_ILLEGAL_END_COUNTER_PF_SEARCH_ILLEGAL_END_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_PF_SEARCH_ILLEGAL_END_COUNTER_PF_SEARCH_ILLEGAL_END_COUNTER_RST    0x0

static inline u16 macdsp_api_pf_search_illegal_end_counter_pf_search_illegal_end_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_PF_SEARCH_ILLEGAL_END_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_pf_search_illegal_end_counter_pf_search_illegal_end_counter_setf(struct cl_chip *chip, u16 pfsearchillegalendcounter)
{
	ASSERT_ERR_CHIP((((u32)pfsearchillegalendcounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_PF_SEARCH_ILLEGAL_END_COUNTER_ADDR, (u32)pfsearchillegalendcounter << 0);
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
#define MACDSP_API_RECEPTION_STARTED_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000408)
#define MACDSP_API_RECEPTION_STARTED_COUNTER_OFFSET      0x00000408
#define MACDSP_API_RECEPTION_STARTED_COUNTER_INDEX       0x00000102
#define MACDSP_API_RECEPTION_STARTED_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_reception_started_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RECEPTION_STARTED_COUNTER_ADDR);
}

static inline void macdsp_api_reception_started_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RECEPTION_STARTED_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RECEPTION_STARTED_COUNTER_RECEPTION_STARTED_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RECEPTION_STARTED_COUNTER_RECEPTION_STARTED_COUNTER_LSB    0
#define MACDSP_API_RECEPTION_STARTED_COUNTER_RECEPTION_STARTED_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RECEPTION_STARTED_COUNTER_RECEPTION_STARTED_COUNTER_RST    0x0

static inline u16 macdsp_api_reception_started_counter_reception_started_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RECEPTION_STARTED_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_reception_started_counter_reception_started_counter_setf(struct cl_chip *chip, u16 receptionstartedcounter)
{
	ASSERT_ERR_CHIP((((u32)receptionstartedcounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RECEPTION_STARTED_COUNTER_ADDR, (u32)receptionstartedcounter << 0);
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
#define MACDSP_API_RX_VECTOR_MODEM_B_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000040A)
#define MACDSP_API_RX_VECTOR_MODEM_B_COUNTER_OFFSET      0x0000040A
#define MACDSP_API_RX_VECTOR_MODEM_B_COUNTER_INDEX       0x00000102
#define MACDSP_API_RX_VECTOR_MODEM_B_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_vector_modem_b_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_VECTOR_MODEM_B_COUNTER_ADDR);
}

static inline void macdsp_api_rx_vector_modem_b_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_VECTOR_MODEM_B_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_VECTOR_MODEM_B_COUNTER_RX_VECTOR_MODEM_BCOUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_VECTOR_MODEM_B_COUNTER_RX_VECTOR_MODEM_BCOUNTER_LSB    0
#define MACDSP_API_RX_VECTOR_MODEM_B_COUNTER_RX_VECTOR_MODEM_BCOUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_VECTOR_MODEM_B_COUNTER_RX_VECTOR_MODEM_BCOUNTER_RST    0x0

static inline u16 macdsp_api_rx_vector_modem_b_counter_rx_vector_modem_bcounter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_VECTOR_MODEM_B_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_vector_modem_b_counter_rx_vector_modem_bcounter_setf(struct cl_chip *chip, u16 rxvectormodembcounter)
{
	ASSERT_ERR_CHIP((((u32)rxvectormodembcounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_VECTOR_MODEM_B_COUNTER_ADDR, (u32)rxvectormodembcounter << 0);
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
#define MACDSP_API_RX_VECTOR_MODEM_B_ERROR_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000040C)
#define MACDSP_API_RX_VECTOR_MODEM_B_ERROR_COUNTER_OFFSET      0x0000040C
#define MACDSP_API_RX_VECTOR_MODEM_B_ERROR_COUNTER_INDEX       0x00000103
#define MACDSP_API_RX_VECTOR_MODEM_B_ERROR_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_vector_modem_b_error_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_VECTOR_MODEM_B_ERROR_COUNTER_ADDR);
}

static inline void macdsp_api_rx_vector_modem_b_error_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_VECTOR_MODEM_B_ERROR_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_VECTOR_MODEM_B_ERROR_COUNTER_RX_VECTOR_MODEM_BERROR_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_VECTOR_MODEM_B_ERROR_COUNTER_RX_VECTOR_MODEM_BERROR_COUNTER_LSB    0
#define MACDSP_API_RX_VECTOR_MODEM_B_ERROR_COUNTER_RX_VECTOR_MODEM_BERROR_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_VECTOR_MODEM_B_ERROR_COUNTER_RX_VECTOR_MODEM_BERROR_COUNTER_RST    0x0

static inline u16 macdsp_api_rx_vector_modem_b_error_counter_rx_vector_modem_berror_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_VECTOR_MODEM_B_ERROR_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_vector_modem_b_error_counter_rx_vector_modem_berror_counter_setf(struct cl_chip *chip, u16 rxvectormodemberrorcounter)
{
	ASSERT_ERR_CHIP((((u32)rxvectormodemberrorcounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_VECTOR_MODEM_B_ERROR_COUNTER_ADDR, (u32)rxvectormodemberrorcounter << 0);
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
#define MACDSP_API_TX_STOP_JUMP_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000040E)
#define MACDSP_API_TX_STOP_JUMP_COUNTER_OFFSET      0x0000040E
#define MACDSP_API_TX_STOP_JUMP_COUNTER_INDEX       0x00000103
#define MACDSP_API_TX_STOP_JUMP_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_tx_stop_jump_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TX_STOP_JUMP_COUNTER_ADDR);
}

static inline void macdsp_api_tx_stop_jump_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TX_STOP_JUMP_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TX_STOP_JUMP_COUNTER_TX_STOP_JUMP_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_TX_STOP_JUMP_COUNTER_TX_STOP_JUMP_COUNTER_LSB    0
#define MACDSP_API_TX_STOP_JUMP_COUNTER_TX_STOP_JUMP_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_TX_STOP_JUMP_COUNTER_TX_STOP_JUMP_COUNTER_RST    0x0

static inline u16 macdsp_api_tx_stop_jump_counter_tx_stop_jump_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_STOP_JUMP_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_tx_stop_jump_counter_tx_stop_jump_counter_setf(struct cl_chip *chip, u16 txstopjumpcounter)
{
	ASSERT_ERR_CHIP((((u32)txstopjumpcounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_STOP_JUMP_COUNTER_ADDR, (u32)txstopjumpcounter << 0);
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
#define MACDSP_API_TX_ERR_TOT_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000410)
#define MACDSP_API_TX_ERR_TOT_COUNTER_OFFSET      0x00000410
#define MACDSP_API_TX_ERR_TOT_COUNTER_INDEX       0x00000104
#define MACDSP_API_TX_ERR_TOT_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_tx_err_tot_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TX_ERR_TOT_COUNTER_ADDR);
}

static inline void macdsp_api_tx_err_tot_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TX_ERR_TOT_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TX_ERR_TOT_COUNTER_TX_ERR_TOT_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_TX_ERR_TOT_COUNTER_TX_ERR_TOT_COUNTER_LSB    0
#define MACDSP_API_TX_ERR_TOT_COUNTER_TX_ERR_TOT_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_TX_ERR_TOT_COUNTER_TX_ERR_TOT_COUNTER_RST    0x0

static inline u16 macdsp_api_tx_err_tot_counter_tx_err_tot_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_ERR_TOT_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_tx_err_tot_counter_tx_err_tot_counter_setf(struct cl_chip *chip, u16 txerrtotcounter)
{
	ASSERT_ERR_CHIP((((u32)txerrtotcounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_ERR_TOT_COUNTER_ADDR, (u32)txerrtotcounter << 0);
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
#define MACDSP_API_IQ_CALIB_DONE_CNT_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000412)
#define MACDSP_API_IQ_CALIB_DONE_CNT_COUNTER_OFFSET      0x00000412
#define MACDSP_API_IQ_CALIB_DONE_CNT_COUNTER_INDEX       0x00000104
#define MACDSP_API_IQ_CALIB_DONE_CNT_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_iq_calib_done_cnt_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_IQ_CALIB_DONE_CNT_COUNTER_ADDR);
}

static inline void macdsp_api_iq_calib_done_cnt_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_IQ_CALIB_DONE_CNT_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_IQ_CALIB_DONE_CNT_COUNTER_IQ_CALIB_DONE_CNT_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_IQ_CALIB_DONE_CNT_COUNTER_IQ_CALIB_DONE_CNT_COUNTER_LSB    0
#define MACDSP_API_IQ_CALIB_DONE_CNT_COUNTER_IQ_CALIB_DONE_CNT_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_IQ_CALIB_DONE_CNT_COUNTER_IQ_CALIB_DONE_CNT_COUNTER_RST    0x0

static inline u16 macdsp_api_iq_calib_done_cnt_counter_iq_calib_done_cnt_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_IQ_CALIB_DONE_CNT_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_iq_calib_done_cnt_counter_iq_calib_done_cnt_counter_setf(struct cl_chip *chip, u16 iqcalibdonecntcounter)
{
	ASSERT_ERR_CHIP((((u32)iqcalibdonecntcounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_IQ_CALIB_DONE_CNT_COUNTER_ADDR, (u32)iqcalibdonecntcounter << 0);
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
#define MACDSP_API_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000414)
#define MACDSP_API_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_OFFSET      0x00000414
#define MACDSP_API_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_INDEX       0x00000105
#define MACDSP_API_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_rx_parity_error_while_rx_modem_b_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_ADDR);
}

static inline void macdsp_api_rx_parity_error_while_rx_modem_b_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_RX_PARITY_ERROR_WHILE_RX_MODEM_BCOUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_RX_PARITY_ERROR_WHILE_RX_MODEM_BCOUNTER_LSB    0
#define MACDSP_API_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_RX_PARITY_ERROR_WHILE_RX_MODEM_BCOUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_RX_PARITY_ERROR_WHILE_RX_MODEM_BCOUNTER_RST    0x0

static inline u16 macdsp_api_rx_parity_error_while_rx_modem_b_counter_rx_parity_error_while_rx_modem_bcounter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_rx_parity_error_while_rx_modem_b_counter_rx_parity_error_while_rx_modem_bcounter_setf(struct cl_chip *chip, u16 rxparityerrorwhilerxmodembcounter)
{
	ASSERT_ERR_CHIP((((u32)rxparityerrorwhilerxmodembcounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_PARITY_ERROR_WHILE_RX_MODEM_B_COUNTER_ADDR, (u32)rxparityerrorwhilerxmodembcounter << 0);
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
#define MACDSP_API_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000416)
#define MACDSP_API_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_OFFSET      0x00000416
#define MACDSP_API_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_INDEX       0x00000105
#define MACDSP_API_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_number_of_recevied_modem_b_packets_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR);
}

static inline void macdsp_api_number_of_recevied_modem_b_packets_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_RECEVIED_MODEM_BPACKETS_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_RECEVIED_MODEM_BPACKETS_COUNTER_LSB    0
#define MACDSP_API_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_RECEVIED_MODEM_BPACKETS_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_RECEVIED_MODEM_BPACKETS_COUNTER_RST    0x0

static inline u16 macdsp_api_number_of_recevied_modem_b_packets_counter_number_of_recevied_modem_bpackets_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_number_of_recevied_modem_b_packets_counter_number_of_recevied_modem_bpackets_counter_setf(struct cl_chip *chip, u16 numberofreceviedmodembpacketscounter)
{
	ASSERT_ERR_CHIP((((u32)numberofreceviedmodembpacketscounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_NUMBER_OF_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR, (u32)numberofreceviedmodembpacketscounter << 0);
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
#define MACDSP_API_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000418)
#define MACDSP_API_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_OFFSET      0x00000418
#define MACDSP_API_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_INDEX       0x00000106
#define MACDSP_API_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_number_of_ack_recevied_modem_b_packets_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR);
}

static inline void macdsp_api_number_of_ack_recevied_modem_b_packets_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_ACK_RECEVIED_MODEM_BPACKETS_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_ACK_RECEVIED_MODEM_BPACKETS_COUNTER_LSB    0
#define MACDSP_API_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_ACK_RECEVIED_MODEM_BPACKETS_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_ACK_RECEVIED_MODEM_BPACKETS_COUNTER_RST    0x0

static inline u16 macdsp_api_number_of_ack_recevied_modem_b_packets_counter_number_of_ack_recevied_modem_bpackets_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_number_of_ack_recevied_modem_b_packets_counter_number_of_ack_recevied_modem_bpackets_counter_setf(struct cl_chip *chip, u16 numberofackreceviedmodembpacketscounter)
{
	ASSERT_ERR_CHIP((((u32)numberofackreceviedmodembpacketscounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_NUMBER_OF_ACK_RECEVIED_MODEM_B_PACKETS_COUNTER_ADDR, (u32)numberofackreceviedmodembpacketscounter << 0);
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
#define MACDSP_API_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000041A)
#define MACDSP_API_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_OFFSET      0x0000041A
#define MACDSP_API_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_INDEX       0x00000106
#define MACDSP_API_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_number_of_transmitted_modem_b_packets_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_ADDR);
}

static inline void macdsp_api_number_of_transmitted_modem_b_packets_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_TRANSMITTED_MODEM_BPACKETS_COUNTER_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_TRANSMITTED_MODEM_BPACKETS_COUNTER_LSB    0
#define MACDSP_API_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_TRANSMITTED_MODEM_BPACKETS_COUNTER_WIDTH    ((u32)0x00000010)

#define MACDSP_API_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_NUMBER_OF_TRANSMITTED_MODEM_BPACKETS_COUNTER_RST    0x0

static inline u16 macdsp_api_number_of_transmitted_modem_b_packets_counter_number_of_transmitted_modem_bpackets_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_number_of_transmitted_modem_b_packets_counter_number_of_transmitted_modem_bpackets_counter_setf(struct cl_chip *chip, u16 numberoftransmittedmodembpacketscounter)
{
	ASSERT_ERR_CHIP((((u32)numberoftransmittedmodembpacketscounter << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_NUMBER_OF_TRANSMITTED_MODEM_B_PACKETS_COUNTER_ADDR, (u32)numberoftransmittedmodembpacketscounter << 0);
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
#define MACDSP_API_LEGACY_RATE_6_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000430)
#define MACDSP_API_LEGACY_RATE_6_COUNTER_OFFSET      0x00000430
#define MACDSP_API_LEGACY_RATE_6_COUNTER_INDEX       0x0000010C
#define MACDSP_API_LEGACY_RATE_6_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_legacy_rate_6_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_LEGACY_RATE_6_COUNTER_ADDR);
}

static inline void macdsp_api_legacy_rate_6_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_LEGACY_RATE_6_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_LEGACY_RATE_6_COUNTER_LEGACY_RATE_6_COUNTER_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_LEGACY_RATE_6_COUNTER_LEGACY_RATE_6_COUNTER_LSB    0
#define MACDSP_API_LEGACY_RATE_6_COUNTER_LEGACY_RATE_6_COUNTER_WIDTH    ((u32)0x00000020)

#define MACDSP_API_LEGACY_RATE_6_COUNTER_LEGACY_RATE_6_COUNTER_RST    0x0

static inline u32 macdsp_api_legacy_rate_6_counter_legacy_rate_6_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LEGACY_RATE_6_COUNTER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_legacy_rate_6_counter_legacy_rate_6_counter_setf(struct cl_chip *chip, u32 legacyrate6counter)
{
	ASSERT_ERR_CHIP((((u32)legacyrate6counter << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_LEGACY_RATE_6_COUNTER_ADDR, (u32)legacyrate6counter << 0);
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
#define MACDSP_API_LEGACY_RATE_NOT_6_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000434)
#define MACDSP_API_LEGACY_RATE_NOT_6_COUNTER_OFFSET      0x00000434
#define MACDSP_API_LEGACY_RATE_NOT_6_COUNTER_INDEX       0x0000010D
#define MACDSP_API_LEGACY_RATE_NOT_6_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_legacy_rate_not_6_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_LEGACY_RATE_NOT_6_COUNTER_ADDR);
}

static inline void macdsp_api_legacy_rate_not_6_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_LEGACY_RATE_NOT_6_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_LEGACY_RATE_NOT_6_COUNTER_LEGACY_RATE_NOT_6_COUNTER_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_LEGACY_RATE_NOT_6_COUNTER_LEGACY_RATE_NOT_6_COUNTER_LSB    0
#define MACDSP_API_LEGACY_RATE_NOT_6_COUNTER_LEGACY_RATE_NOT_6_COUNTER_WIDTH    ((u32)0x00000020)

#define MACDSP_API_LEGACY_RATE_NOT_6_COUNTER_LEGACY_RATE_NOT_6_COUNTER_RST    0x0

static inline u32 macdsp_api_legacy_rate_not_6_counter_legacy_rate_not_6_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LEGACY_RATE_NOT_6_COUNTER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_legacy_rate_not_6_counter_legacy_rate_not_6_counter_setf(struct cl_chip *chip, u32 legacyratenot6counter)
{
	ASSERT_ERR_CHIP((((u32)legacyratenot6counter << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_LEGACY_RATE_NOT_6_COUNTER_ADDR, (u32)legacyratenot6counter << 0);
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
#define MACDSP_API_HT_RECIEVED_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000438)
#define MACDSP_API_HT_RECIEVED_COUNTER_OFFSET      0x00000438
#define MACDSP_API_HT_RECIEVED_COUNTER_INDEX       0x0000010E
#define MACDSP_API_HT_RECIEVED_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_ht_recieved_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HT_RECIEVED_COUNTER_ADDR);
}

static inline void macdsp_api_ht_recieved_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HT_RECIEVED_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HT_RECIEVED_COUNTER_HT_RECIEVED_COUNTER_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_HT_RECIEVED_COUNTER_HT_RECIEVED_COUNTER_LSB    0
#define MACDSP_API_HT_RECIEVED_COUNTER_HT_RECIEVED_COUNTER_WIDTH    ((u32)0x00000020)

#define MACDSP_API_HT_RECIEVED_COUNTER_HT_RECIEVED_COUNTER_RST    0x0

static inline u32 macdsp_api_ht_recieved_counter_ht_recieved_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HT_RECIEVED_COUNTER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_ht_recieved_counter_ht_recieved_counter_setf(struct cl_chip *chip, u32 htrecievedcounter)
{
	ASSERT_ERR_CHIP((((u32)htrecievedcounter << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HT_RECIEVED_COUNTER_ADDR, (u32)htrecievedcounter << 0);
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
#define MACDSP_API_VHT_RECIEVED_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000043C)
#define MACDSP_API_VHT_RECIEVED_COUNTER_OFFSET      0x0000043C
#define MACDSP_API_VHT_RECIEVED_COUNTER_INDEX       0x0000010F
#define MACDSP_API_VHT_RECIEVED_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_vht_recieved_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_VHT_RECIEVED_COUNTER_ADDR);
}

static inline void macdsp_api_vht_recieved_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_VHT_RECIEVED_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_VHT_RECIEVED_COUNTER_VHT_RECIEVED_COUNTER_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_VHT_RECIEVED_COUNTER_VHT_RECIEVED_COUNTER_LSB    0
#define MACDSP_API_VHT_RECIEVED_COUNTER_VHT_RECIEVED_COUNTER_WIDTH    ((u32)0x00000020)

#define MACDSP_API_VHT_RECIEVED_COUNTER_VHT_RECIEVED_COUNTER_RST    0x0

static inline u32 macdsp_api_vht_recieved_counter_vht_recieved_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_VHT_RECIEVED_COUNTER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_vht_recieved_counter_vht_recieved_counter_setf(struct cl_chip *chip, u32 vhtrecievedcounter)
{
	ASSERT_ERR_CHIP((((u32)vhtrecievedcounter << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_VHT_RECIEVED_COUNTER_ADDR, (u32)vhtrecievedcounter << 0);
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
#define MACDSP_API_HE_RECIEVED_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000440)
#define MACDSP_API_HE_RECIEVED_COUNTER_OFFSET      0x00000440
#define MACDSP_API_HE_RECIEVED_COUNTER_INDEX       0x00000110
#define MACDSP_API_HE_RECIEVED_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_he_recieved_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_RECIEVED_COUNTER_ADDR);
}

static inline void macdsp_api_he_recieved_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_RECIEVED_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_RECIEVED_COUNTER_HE_RECIEVED_COUNTER_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_HE_RECIEVED_COUNTER_HE_RECIEVED_COUNTER_LSB    0
#define MACDSP_API_HE_RECIEVED_COUNTER_HE_RECIEVED_COUNTER_WIDTH    ((u32)0x00000020)

#define MACDSP_API_HE_RECIEVED_COUNTER_HE_RECIEVED_COUNTER_RST    0x0

static inline u32 macdsp_api_he_recieved_counter_he_recieved_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_RECIEVED_COUNTER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_he_recieved_counter_he_recieved_counter_setf(struct cl_chip *chip, u32 herecievedcounter)
{
	ASSERT_ERR_CHIP((((u32)herecievedcounter << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_RECIEVED_COUNTER_ADDR, (u32)herecievedcounter << 0);
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
#define MACDSP_API_ANY_FAIL_BEFORE_ES_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000444)
#define MACDSP_API_ANY_FAIL_BEFORE_ES_COUNTER_OFFSET      0x00000444
#define MACDSP_API_ANY_FAIL_BEFORE_ES_COUNTER_INDEX       0x00000111
#define MACDSP_API_ANY_FAIL_BEFORE_ES_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_any_fail_before_es_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_ANY_FAIL_BEFORE_ES_COUNTER_ADDR);
}

static inline void macdsp_api_any_fail_before_es_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_ANY_FAIL_BEFORE_ES_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_ANY_FAIL_BEFORE_ES_COUNTER_ANY_FAIL_BEFORE_ES_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_ANY_FAIL_BEFORE_ES_COUNTER_ANY_FAIL_BEFORE_ES_LSB    0
#define MACDSP_API_ANY_FAIL_BEFORE_ES_COUNTER_ANY_FAIL_BEFORE_ES_WIDTH    ((u32)0x00000020)

#define MACDSP_API_ANY_FAIL_BEFORE_ES_COUNTER_ANY_FAIL_BEFORE_ES_RST    0x0

static inline u32 macdsp_api_any_fail_before_es_counter_any_fail_before_es_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_ANY_FAIL_BEFORE_ES_COUNTER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_any_fail_before_es_counter_any_fail_before_es_setf(struct cl_chip *chip, u32 anyfailbeforees)
{
	ASSERT_ERR_CHIP((((u32)anyfailbeforees << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_ANY_FAIL_BEFORE_ES_COUNTER_ADDR, (u32)anyfailbeforees << 0);
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
#define MACDSP_API_ANY_FAIL_AFTER_ES_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000448)
#define MACDSP_API_ANY_FAIL_AFTER_ES_COUNTER_OFFSET      0x00000448
#define MACDSP_API_ANY_FAIL_AFTER_ES_COUNTER_INDEX       0x00000112
#define MACDSP_API_ANY_FAIL_AFTER_ES_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_any_fail_after_es_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_ANY_FAIL_AFTER_ES_COUNTER_ADDR);
}

static inline void macdsp_api_any_fail_after_es_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_ANY_FAIL_AFTER_ES_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_ANY_FAIL_AFTER_ES_COUNTER_ANY_FAIL_AFTER_ES_COUNTER_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_ANY_FAIL_AFTER_ES_COUNTER_ANY_FAIL_AFTER_ES_COUNTER_LSB    0
#define MACDSP_API_ANY_FAIL_AFTER_ES_COUNTER_ANY_FAIL_AFTER_ES_COUNTER_WIDTH    ((u32)0x00000020)

#define MACDSP_API_ANY_FAIL_AFTER_ES_COUNTER_ANY_FAIL_AFTER_ES_COUNTER_RST    0x0

static inline u32 macdsp_api_any_fail_after_es_counter_any_fail_after_es_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_ANY_FAIL_AFTER_ES_COUNTER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_any_fail_after_es_counter_any_fail_after_es_counter_setf(struct cl_chip *chip, u32 anyfailafterescounter)
{
	ASSERT_ERR_CHIP((((u32)anyfailafterescounter << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_ANY_FAIL_AFTER_ES_COUNTER_ADDR, (u32)anyfailafterescounter << 0);
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
#define MACDSP_API_RADAR_DETECTION_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000044C)
#define MACDSP_API_RADAR_DETECTION_COUNTER_OFFSET      0x0000044C
#define MACDSP_API_RADAR_DETECTION_COUNTER_INDEX       0x00000113
#define MACDSP_API_RADAR_DETECTION_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_radar_detection_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RADAR_DETECTION_COUNTER_ADDR);
}

static inline void macdsp_api_radar_detection_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RADAR_DETECTION_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RADAR_DETECTION_COUNTER_RADAR_DETECTION_COUNTER_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_RADAR_DETECTION_COUNTER_RADAR_DETECTION_COUNTER_LSB    0
#define MACDSP_API_RADAR_DETECTION_COUNTER_RADAR_DETECTION_COUNTER_WIDTH    ((u32)0x00000020)

#define MACDSP_API_RADAR_DETECTION_COUNTER_RADAR_DETECTION_COUNTER_RST    0x0

static inline u32 macdsp_api_radar_detection_counter_radar_detection_counter_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RADAR_DETECTION_COUNTER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_radar_detection_counter_radar_detection_counter_setf(struct cl_chip *chip, u32 radardetectioncounter)
{
	ASSERT_ERR_CHIP((((u32)radardetectioncounter << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RADAR_DETECTION_COUNTER_ADDR, (u32)radardetectioncounter << 0);
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
#define MACDSP_API_TX_BF_COUNTER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000450)
#define MACDSP_API_TX_BF_COUNTER_OFFSET      0x00000450
#define MACDSP_API_TX_BF_COUNTER_INDEX       0x00000114
#define MACDSP_API_TX_BF_COUNTER_RESET       0x00000000

static inline u32 macdsp_api_tx_bf_counter_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TX_BF_COUNTER_ADDR);
}

static inline void macdsp_api_tx_bf_counter_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TX_BF_COUNTER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TX_BF_COUNTER_NUM_TX_VECTORS_WITH_BF_ON_MASK    ((u32)0xFFFF0000)
#define MACDSP_API_TX_BF_COUNTER_NUM_TX_VECTORS_WITH_BF_ON_LSB    16
#define MACDSP_API_TX_BF_COUNTER_NUM_TX_VECTORS_WITH_BF_ON_WIDTH    ((u32)0x00000010)
#define MACDSP_API_TX_BF_COUNTER_NUM_TX_VECTORS_WITH_BF_OFF_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_TX_BF_COUNTER_NUM_TX_VECTORS_WITH_BF_OFF_LSB    0
#define MACDSP_API_TX_BF_COUNTER_NUM_TX_VECTORS_WITH_BF_OFF_WIDTH    ((u32)0x00000010)

#define MACDSP_API_TX_BF_COUNTER_NUM_TX_VECTORS_WITH_BF_ON_RST    0x0
#define MACDSP_API_TX_BF_COUNTER_NUM_TX_VECTORS_WITH_BF_OFF_RST    0x0

static inline void macdsp_api_tx_bf_counter_pack(struct cl_chip *chip, u16 num_tx_vectors_with_bf_on, u16 num_tx_vectors_with_bf_off)
{
	ASSERT_ERR_CHIP((((u32)num_tx_vectors_with_bf_on << 16) & ~((u32)0xFFFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)num_tx_vectors_with_bf_off << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_BF_COUNTER_ADDR, ((u32)num_tx_vectors_with_bf_on << 16) | ((u32)num_tx_vectors_with_bf_off << 0));
}

static inline void macdsp_api_tx_bf_counter_unpack(struct cl_chip *chip, u16 *num_tx_vectors_with_bf_on, u16 *num_tx_vectors_with_bf_off)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_BF_COUNTER_ADDR);

	*num_tx_vectors_with_bf_on = (local_val & ((u32)0xFFFF0000)) >> 16;
	*num_tx_vectors_with_bf_off = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_tx_bf_counter_num_tx_vectors_with_bf_on_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_BF_COUNTER_ADDR);

	return (u16)((local_val & ((u32)0xFFFF0000)) >> 16);
}

static inline void macdsp_api_tx_bf_counter_num_tx_vectors_with_bf_on_setf(struct cl_chip *chip, u16 numtxvectorswithbfon)
{
	ASSERT_ERR_CHIP((((u32)numtxvectorswithbfon << 16) & ~((u32)0xFFFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_BF_COUNTER_ADDR, (cl_reg_read(chip, MACDSP_API_TX_BF_COUNTER_ADDR) & ~((u32)0xFFFF0000)) | ((u32)numtxvectorswithbfon << 16));
}

static inline u16 macdsp_api_tx_bf_counter_num_tx_vectors_with_bf_off_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_BF_COUNTER_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_tx_bf_counter_num_tx_vectors_with_bf_off_setf(struct cl_chip *chip, u16 numtxvectorswithbfoff)
{
	ASSERT_ERR_CHIP((((u32)numtxvectorswithbfoff << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_BF_COUNTER_ADDR, (cl_reg_read(chip, MACDSP_API_TX_BF_COUNTER_ADDR) & ~((u32)0x0000FFFF)) | ((u32)numtxvectorswithbfoff << 0));
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
#define MACDSP_API_LAST_SIG_B_PROCESS_FLAG_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000600)
#define MACDSP_API_LAST_SIG_B_PROCESS_FLAG_OFFSET      0x00000600
#define MACDSP_API_LAST_SIG_B_PROCESS_FLAG_INDEX       0x00000180
#define MACDSP_API_LAST_SIG_B_PROCESS_FLAG_RESET       0x00000000

static inline u32 macdsp_api_last_sig_b_process_flag_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_LAST_SIG_B_PROCESS_FLAG_ADDR);
}

static inline void macdsp_api_last_sig_b_process_flag_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_LAST_SIG_B_PROCESS_FLAG_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_LAST_SIG_B_PROCESS_FLAG_LAST_SIGB_PROC_FLAG_MASK    ((u32)0x000000FF)
#define MACDSP_API_LAST_SIG_B_PROCESS_FLAG_LAST_SIGB_PROC_FLAG_LSB    0
#define MACDSP_API_LAST_SIG_B_PROCESS_FLAG_LAST_SIGB_PROC_FLAG_WIDTH    ((u32)0x00000008)

#define MACDSP_API_LAST_SIG_B_PROCESS_FLAG_LAST_SIGB_PROC_FLAG_RST    0x0

static inline u8 macdsp_api_last_sig_b_process_flag_last_sigb_proc_flag_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LAST_SIG_B_PROCESS_FLAG_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macdsp_api_last_sig_b_process_flag_last_sigb_proc_flag_setf(struct cl_chip *chip, u8 lastsigbprocflag)
{
	ASSERT_ERR_CHIP((((u32)lastsigbprocflag << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MACDSP_API_LAST_SIG_B_PROCESS_FLAG_ADDR, (u32)lastsigbprocflag << 0);
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
#define MACDSP_API_SET_DSP_TO_FINE_DC_TRACKING_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000602)
#define MACDSP_API_SET_DSP_TO_FINE_DC_TRACKING_OFFSET      0x00000602
#define MACDSP_API_SET_DSP_TO_FINE_DC_TRACKING_INDEX       0x00000180
#define MACDSP_API_SET_DSP_TO_FINE_DC_TRACKING_RESET       0x00000000

static inline u32 macdsp_api_set_dsp_to_fine_dc_tracking_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SET_DSP_TO_FINE_DC_TRACKING_ADDR);
}

static inline void macdsp_api_set_dsp_to_fine_dc_tracking_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SET_DSP_TO_FINE_DC_TRACKING_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SET_DSP_TO_FINE_DC_TRACKING_SET_DSP_TO_FINE_DC_TRACK_MASK    ((u32)0x000000FF)
#define MACDSP_API_SET_DSP_TO_FINE_DC_TRACKING_SET_DSP_TO_FINE_DC_TRACK_LSB    0
#define MACDSP_API_SET_DSP_TO_FINE_DC_TRACKING_SET_DSP_TO_FINE_DC_TRACK_WIDTH    ((u32)0x00000008)

#define MACDSP_API_SET_DSP_TO_FINE_DC_TRACKING_SET_DSP_TO_FINE_DC_TRACK_RST    0x0

static inline u8 macdsp_api_set_dsp_to_fine_dc_tracking_set_dsp_to_fine_dc_track_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SET_DSP_TO_FINE_DC_TRACKING_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macdsp_api_set_dsp_to_fine_dc_tracking_set_dsp_to_fine_dc_track_setf(struct cl_chip *chip, u8 setdsptofinedctrack)
{
	ASSERT_ERR_CHIP((((u32)setdsptofinedctrack << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MACDSP_API_SET_DSP_TO_FINE_DC_TRACKING_ADDR, (u32)setdsptofinedctrack << 0);
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
#define MACDSP_API_DISABLE_CDI_LIMIT_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000620)
#define MACDSP_API_DISABLE_CDI_LIMIT_OFFSET      0x00000620
#define MACDSP_API_DISABLE_CDI_LIMIT_INDEX       0x00000188
#define MACDSP_API_DISABLE_CDI_LIMIT_RESET       0x00000000

static inline u32 macdsp_api_disable_cdi_limit_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_DISABLE_CDI_LIMIT_ADDR);
}

static inline void macdsp_api_disable_cdi_limit_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_DISABLE_CDI_LIMIT_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_DISABLE_CDI_LIMIT_DISABLE_CDI_BIT    ((u32)0x00000001)
#define MACDSP_API_DISABLE_CDI_LIMIT_DISABLE_CDI_POS    0

#define MACDSP_API_DISABLE_CDI_LIMIT_DISABLE_CDI_RST    0x0

static inline u8 macdsp_api_disable_cdi_limit_disable_cdi_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DISABLE_CDI_LIMIT_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macdsp_api_disable_cdi_limit_disable_cdi_setf(struct cl_chip *chip, u8 disablecdi)
{
	ASSERT_ERR_CHIP((((u32)disablecdi << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_DISABLE_CDI_LIMIT_ADDR, (u32)disablecdi << 0);
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
#define MACDSP_API_NUM_OF_SYM_IN_COARSE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000622)
#define MACDSP_API_NUM_OF_SYM_IN_COARSE_OFFSET      0x00000622
#define MACDSP_API_NUM_OF_SYM_IN_COARSE_INDEX       0x00000188
#define MACDSP_API_NUM_OF_SYM_IN_COARSE_RESET       0x00000000

static inline u32 macdsp_api_num_of_sym_in_coarse_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_NUM_OF_SYM_IN_COARSE_ADDR);
}

static inline void macdsp_api_num_of_sym_in_coarse_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_NUM_OF_SYM_IN_COARSE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_NUM_OF_SYM_IN_COARSE_NUM_OF_SYM_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_NUM_OF_SYM_IN_COARSE_NUM_OF_SYM_LSB    0
#define MACDSP_API_NUM_OF_SYM_IN_COARSE_NUM_OF_SYM_WIDTH    ((u32)0x00000010)

#define MACDSP_API_NUM_OF_SYM_IN_COARSE_NUM_OF_SYM_RST    0x0

static inline u16 macdsp_api_num_of_sym_in_coarse_num_of_sym_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_NUM_OF_SYM_IN_COARSE_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_num_of_sym_in_coarse_num_of_sym_setf(struct cl_chip *chip, u16 numofsym)
{
	ASSERT_ERR_CHIP((((u32)numofsym << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_NUM_OF_SYM_IN_COARSE_ADDR, (u32)numofsym << 0);
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
#define MACDSP_API_TB_FORCED_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000624)
#define MACDSP_API_TB_FORCED_OFFSET      0x00000624
#define MACDSP_API_TB_FORCED_INDEX       0x00000189
#define MACDSP_API_TB_FORCED_RESET       0x00000000

static inline u32 macdsp_api_tb_forced_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TB_FORCED_ADDR);
}

static inline void macdsp_api_tb_forced_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TB_FORCED_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TB_FORCED_TB_FORCED_BIT    ((u32)0x00000001)
#define MACDSP_API_TB_FORCED_TB_FORCED_POS    0

#define MACDSP_API_TB_FORCED_TB_FORCED_RST    0x0

static inline u8 macdsp_api_tb_forced_tb_forced_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TB_FORCED_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macdsp_api_tb_forced_tb_forced_setf(struct cl_chip *chip, u8 tbforced)
{
	ASSERT_ERR_CHIP((((u32)tbforced << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_TB_FORCED_ADDR, (u32)tbforced << 0);
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
#define MACDSP_API_RESAMPLER_EST_TYPE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000626)
#define MACDSP_API_RESAMPLER_EST_TYPE_OFFSET      0x00000626
#define MACDSP_API_RESAMPLER_EST_TYPE_INDEX       0x00000189
#define MACDSP_API_RESAMPLER_EST_TYPE_RESET       0x00000000

static inline u32 macdsp_api_resampler_est_type_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RESAMPLER_EST_TYPE_ADDR);
}

static inline void macdsp_api_resampler_est_type_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RESAMPLER_EST_TYPE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RESAMPLER_EST_TYPE_RESAMPLER_MODE_BIT    ((u32)0x00000001)
#define MACDSP_API_RESAMPLER_EST_TYPE_RESAMPLER_MODE_POS    0

#define MACDSP_API_RESAMPLER_EST_TYPE_RESAMPLER_MODE_RST    0x0

static inline u8 macdsp_api_resampler_est_type_resampler_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RESAMPLER_EST_TYPE_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macdsp_api_resampler_est_type_resampler_mode_setf(struct cl_chip *chip, u8 resamplermode)
{
	ASSERT_ERR_CHIP((((u32)resamplermode << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_RESAMPLER_EST_TYPE_ADDR, (u32)resamplermode << 0);
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
#define MACDSP_API_DISABLE_TFU_EST_OPT_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000628)
#define MACDSP_API_DISABLE_TFU_EST_OPT_OFFSET      0x00000628
#define MACDSP_API_DISABLE_TFU_EST_OPT_INDEX       0x0000018A
#define MACDSP_API_DISABLE_TFU_EST_OPT_RESET       0x00000000

static inline u32 macdsp_api_disable_tfu_est_opt_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_DISABLE_TFU_EST_OPT_ADDR);
}

static inline void macdsp_api_disable_tfu_est_opt_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_DISABLE_TFU_EST_OPT_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_DISABLE_TFU_EST_OPT_DISABLE_FREQ_EST_OPT_BIT    ((u32)0x00000001)
#define MACDSP_API_DISABLE_TFU_EST_OPT_DISABLE_FREQ_EST_OPT_POS    0

#define MACDSP_API_DISABLE_TFU_EST_OPT_DISABLE_FREQ_EST_OPT_RST    0x0

static inline u8 macdsp_api_disable_tfu_est_opt_disable_freq_est_opt_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DISABLE_TFU_EST_OPT_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macdsp_api_disable_tfu_est_opt_disable_freq_est_opt_setf(struct cl_chip *chip, u8 disablefreqestopt)
{
	ASSERT_ERR_CHIP((((u32)disablefreqestopt << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_DISABLE_TFU_EST_OPT_ADDR, (u32)disablefreqestopt << 0);
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
#define MACDSP_API_RX_LISTEN_ASSERT_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000062A)
#define MACDSP_API_RX_LISTEN_ASSERT_OFFSET      0x0000062A
#define MACDSP_API_RX_LISTEN_ASSERT_INDEX       0x0000018A
#define MACDSP_API_RX_LISTEN_ASSERT_RESET       0x00000000

static inline u32 macdsp_api_rx_listen_assert_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_LISTEN_ASSERT_ADDR);
}

static inline void macdsp_api_rx_listen_assert_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_LISTEN_ASSERT_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_LISTEN_ASSERT_ENABLE_RX_LISTEN_ASSERT_BIT    ((u32)0x00000001)
#define MACDSP_API_RX_LISTEN_ASSERT_ENABLE_RX_LISTEN_ASSERT_POS    0

#define MACDSP_API_RX_LISTEN_ASSERT_ENABLE_RX_LISTEN_ASSERT_RST    0x0

static inline u8 macdsp_api_rx_listen_assert_enable_rx_listen_assert_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_LISTEN_ASSERT_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macdsp_api_rx_listen_assert_enable_rx_listen_assert_setf(struct cl_chip *chip, u8 enablerxlistenassert)
{
	ASSERT_ERR_CHIP((((u32)enablerxlistenassert << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_LISTEN_ASSERT_ADDR, (u32)enablerxlistenassert << 0);
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
#define MACDSP_API_OLYMPUS_A_FLAG_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000062C)
#define MACDSP_API_OLYMPUS_A_FLAG_OFFSET      0x0000062C
#define MACDSP_API_OLYMPUS_A_FLAG_INDEX       0x0000018B
#define MACDSP_API_OLYMPUS_A_FLAG_RESET       0x00000000

static inline u32 macdsp_api_olympus_a_flag_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_OLYMPUS_A_FLAG_ADDR);
}

static inline void macdsp_api_olympus_a_flag_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_OLYMPUS_A_FLAG_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_OLYMPUS_A_FLAG_OLYMPUS_A_FLAG_BIT    ((u32)0x00000001)
#define MACDSP_API_OLYMPUS_A_FLAG_OLYMPUS_A_FLAG_POS    0

#define MACDSP_API_OLYMPUS_A_FLAG_OLYMPUS_A_FLAG_RST    0x0

static inline u8 macdsp_api_olympus_a_flag_olympus_a_flag_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_OLYMPUS_A_FLAG_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macdsp_api_olympus_a_flag_olympus_a_flag_setf(struct cl_chip *chip, u8 olympusaflag)
{
	ASSERT_ERR_CHIP((((u32)olympusaflag << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_OLYMPUS_A_FLAG_ADDR, (u32)olympusaflag << 0);
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
#define MACDSP_API_TX_CSD_ANT_0_1_PTR_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000630)
#define MACDSP_API_TX_CSD_ANT_0_1_PTR_OFFSET      0x00000630
#define MACDSP_API_TX_CSD_ANT_0_1_PTR_INDEX       0x0000018C
#define MACDSP_API_TX_CSD_ANT_0_1_PTR_RESET       0x00000000

static inline u32 macdsp_api_tx_csd_ant_0_1_ptr_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TX_CSD_ANT_0_1_PTR_ADDR);
}

static inline void macdsp_api_tx_csd_ant_0_1_ptr_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TX_CSD_ANT_0_1_PTR_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TX_CSD_ANT_0_1_PTR_ANT_0_1_PTR_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_TX_CSD_ANT_0_1_PTR_ANT_0_1_PTR_LSB    0
#define MACDSP_API_TX_CSD_ANT_0_1_PTR_ANT_0_1_PTR_WIDTH    ((u32)0x00000020)

#define MACDSP_API_TX_CSD_ANT_0_1_PTR_ANT_0_1_PTR_RST    0x0

static inline u32 macdsp_api_tx_csd_ant_0_1_ptr_ant_0_1_ptr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_CSD_ANT_0_1_PTR_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_tx_csd_ant_0_1_ptr_ant_0_1_ptr_setf(struct cl_chip *chip, u32 ant01ptr)
{
	ASSERT_ERR_CHIP((((u32)ant01ptr << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_CSD_ANT_0_1_PTR_ADDR, (u32)ant01ptr << 0);
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
#define MACDSP_API_TX_CSD_ANT_2_3_PTR_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000634)
#define MACDSP_API_TX_CSD_ANT_2_3_PTR_OFFSET      0x00000634
#define MACDSP_API_TX_CSD_ANT_2_3_PTR_INDEX       0x0000018D
#define MACDSP_API_TX_CSD_ANT_2_3_PTR_RESET       0x00000000

static inline u32 macdsp_api_tx_csd_ant_2_3_ptr_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TX_CSD_ANT_2_3_PTR_ADDR);
}

static inline void macdsp_api_tx_csd_ant_2_3_ptr_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TX_CSD_ANT_2_3_PTR_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TX_CSD_ANT_2_3_PTR_TX_ANT_2_3_PTR_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_TX_CSD_ANT_2_3_PTR_TX_ANT_2_3_PTR_LSB    0
#define MACDSP_API_TX_CSD_ANT_2_3_PTR_TX_ANT_2_3_PTR_WIDTH    ((u32)0x00000020)

#define MACDSP_API_TX_CSD_ANT_2_3_PTR_TX_ANT_2_3_PTR_RST    0x0

static inline u32 macdsp_api_tx_csd_ant_2_3_ptr_tx_ant_2_3_ptr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_CSD_ANT_2_3_PTR_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_tx_csd_ant_2_3_ptr_tx_ant_2_3_ptr_setf(struct cl_chip *chip, u32 txant23ptr)
{
	ASSERT_ERR_CHIP((((u32)txant23ptr << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_CSD_ANT_2_3_PTR_ADDR, (u32)txant23ptr << 0);
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
#define MACDSP_API_TX_CSD_ANT_4_5_PTR_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000638)
#define MACDSP_API_TX_CSD_ANT_4_5_PTR_OFFSET      0x00000638
#define MACDSP_API_TX_CSD_ANT_4_5_PTR_INDEX       0x0000018E
#define MACDSP_API_TX_CSD_ANT_4_5_PTR_RESET       0x00000000

static inline u32 macdsp_api_tx_csd_ant_4_5_ptr_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TX_CSD_ANT_4_5_PTR_ADDR);
}

static inline void macdsp_api_tx_csd_ant_4_5_ptr_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TX_CSD_ANT_4_5_PTR_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TX_CSD_ANT_4_5_PTR_TX_CSD_ANT_4_5_PTR_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_TX_CSD_ANT_4_5_PTR_TX_CSD_ANT_4_5_PTR_LSB    0
#define MACDSP_API_TX_CSD_ANT_4_5_PTR_TX_CSD_ANT_4_5_PTR_WIDTH    ((u32)0x00000020)

#define MACDSP_API_TX_CSD_ANT_4_5_PTR_TX_CSD_ANT_4_5_PTR_RST    0x0

static inline u32 macdsp_api_tx_csd_ant_4_5_ptr_tx_csd_ant_4_5_ptr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_CSD_ANT_4_5_PTR_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_tx_csd_ant_4_5_ptr_tx_csd_ant_4_5_ptr_setf(struct cl_chip *chip, u32 txcsdant45ptr)
{
	ASSERT_ERR_CHIP((((u32)txcsdant45ptr << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_CSD_ANT_4_5_PTR_ADDR, (u32)txcsdant45ptr << 0);
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
#define MACDSP_API_TX_CSD_UPDATE_INDEX_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000063C)
#define MACDSP_API_TX_CSD_UPDATE_INDEX_OFFSET      0x0000063C
#define MACDSP_API_TX_CSD_UPDATE_INDEX_INDEX       0x0000018F
#define MACDSP_API_TX_CSD_UPDATE_INDEX_RESET       0x00000000

static inline u32 macdsp_api_tx_csd_update_index_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TX_CSD_UPDATE_INDEX_ADDR);
}

static inline void macdsp_api_tx_csd_update_index_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TX_CSD_UPDATE_INDEX_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TX_CSD_UPDATE_INDEX_TX_CSD_TABLE_INDEX_MASK    ((u32)0x0000F000)
#define MACDSP_API_TX_CSD_UPDATE_INDEX_TX_CSD_TABLE_INDEX_LSB    12
#define MACDSP_API_TX_CSD_UPDATE_INDEX_TX_CSD_TABLE_INDEX_WIDTH    ((u32)0x00000004)
#define MACDSP_API_TX_CSD_UPDATE_INDEX_TX_CSD_BW_MASK    ((u32)0x00000F00)
#define MACDSP_API_TX_CSD_UPDATE_INDEX_TX_CSD_BW_LSB    8
#define MACDSP_API_TX_CSD_UPDATE_INDEX_TX_CSD_BW_WIDTH    ((u32)0x00000004)
#define MACDSP_API_TX_CSD_UPDATE_INDEX_TX_CSD_NSS_MASK    ((u32)0x000000F0)
#define MACDSP_API_TX_CSD_UPDATE_INDEX_TX_CSD_NSS_LSB    4
#define MACDSP_API_TX_CSD_UPDATE_INDEX_TX_CSD_NSS_WIDTH    ((u32)0x00000004)
#define MACDSP_API_TX_CSD_UPDATE_INDEX_TX_CSD_FORMAT_MODE_MASK    ((u32)0x0000000F)
#define MACDSP_API_TX_CSD_UPDATE_INDEX_TX_CSD_FORMAT_MODE_LSB    0
#define MACDSP_API_TX_CSD_UPDATE_INDEX_TX_CSD_FORMAT_MODE_WIDTH    ((u32)0x00000004)

#define MACDSP_API_TX_CSD_UPDATE_INDEX_TX_CSD_TABLE_INDEX_RST    0x0
#define MACDSP_API_TX_CSD_UPDATE_INDEX_TX_CSD_BW_RST    0x0
#define MACDSP_API_TX_CSD_UPDATE_INDEX_TX_CSD_NSS_RST    0x0
#define MACDSP_API_TX_CSD_UPDATE_INDEX_TX_CSD_FORMAT_MODE_RST    0x0

static inline void macdsp_api_tx_csd_update_index_pack(struct cl_chip *chip, u8 tx_csd_table_index, u8 tx_csd_bw, u8 tx_csd_nss, u8 tx_csd_format_mode)
{
	ASSERT_ERR_CHIP((((u32)tx_csd_table_index << 12) & ~((u32)0x0000F000)) == 0);
	ASSERT_ERR_CHIP((((u32)tx_csd_bw << 8) & ~((u32)0x00000F00)) == 0);
	ASSERT_ERR_CHIP((((u32)tx_csd_nss << 4) & ~((u32)0x000000F0)) == 0);
	ASSERT_ERR_CHIP((((u32)tx_csd_format_mode << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_CSD_UPDATE_INDEX_ADDR, ((u32)tx_csd_table_index << 12) | ((u32)tx_csd_bw << 8) | ((u32)tx_csd_nss << 4) | ((u32)tx_csd_format_mode << 0));
}

static inline void macdsp_api_tx_csd_update_index_unpack(struct cl_chip *chip, u8 *tx_csd_table_index, u8 *tx_csd_bw, u8 *tx_csd_nss, u8 *tx_csd_format_mode)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_CSD_UPDATE_INDEX_ADDR);

	*tx_csd_table_index = (local_val & ((u32)0x0000F000)) >> 12;
	*tx_csd_bw = (local_val & ((u32)0x00000F00)) >> 8;
	*tx_csd_nss = (local_val & ((u32)0x000000F0)) >> 4;
	*tx_csd_format_mode = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 macdsp_api_tx_csd_update_index_tx_csd_table_index_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_CSD_UPDATE_INDEX_ADDR);

	return (u8)((local_val & ((u32)0x0000F000)) >> 12);
}

static inline void macdsp_api_tx_csd_update_index_tx_csd_table_index_setf(struct cl_chip *chip, u8 txcsdtableindex)
{
	ASSERT_ERR_CHIP((((u32)txcsdtableindex << 12) & ~((u32)0x0000F000)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_CSD_UPDATE_INDEX_ADDR, (cl_reg_read(chip, MACDSP_API_TX_CSD_UPDATE_INDEX_ADDR) & ~((u32)0x0000F000)) | ((u32)txcsdtableindex << 12));
}

static inline u8 macdsp_api_tx_csd_update_index_tx_csd_bw_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_CSD_UPDATE_INDEX_ADDR);

	return (u8)((local_val & ((u32)0x00000F00)) >> 8);
}

static inline void macdsp_api_tx_csd_update_index_tx_csd_bw_setf(struct cl_chip *chip, u8 txcsdbw)
{
	ASSERT_ERR_CHIP((((u32)txcsdbw << 8) & ~((u32)0x00000F00)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_CSD_UPDATE_INDEX_ADDR, (cl_reg_read(chip, MACDSP_API_TX_CSD_UPDATE_INDEX_ADDR) & ~((u32)0x00000F00)) | ((u32)txcsdbw << 8));
}

static inline u8 macdsp_api_tx_csd_update_index_tx_csd_nss_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_CSD_UPDATE_INDEX_ADDR);

	return (u8)((local_val & ((u32)0x000000F0)) >> 4);
}

static inline void macdsp_api_tx_csd_update_index_tx_csd_nss_setf(struct cl_chip *chip, u8 txcsdnss)
{
	ASSERT_ERR_CHIP((((u32)txcsdnss << 4) & ~((u32)0x000000F0)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_CSD_UPDATE_INDEX_ADDR, (cl_reg_read(chip, MACDSP_API_TX_CSD_UPDATE_INDEX_ADDR) & ~((u32)0x000000F0)) | ((u32)txcsdnss << 4));
}

static inline u8 macdsp_api_tx_csd_update_index_tx_csd_format_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_CSD_UPDATE_INDEX_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void macdsp_api_tx_csd_update_index_tx_csd_format_mode_setf(struct cl_chip *chip, u8 txcsdformatmode)
{
	ASSERT_ERR_CHIP((((u32)txcsdformatmode << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_CSD_UPDATE_INDEX_ADDR, (cl_reg_read(chip, MACDSP_API_TX_CSD_UPDATE_INDEX_ADDR) & ~((u32)0x0000000F)) | ((u32)txcsdformatmode << 0));
}

/**
 * @brief RX_RESMAPLER_OPT_FLAG register definition
 *  RX_RESAMPLER_OPT_FLAG register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:04 THD_VAL                   0x0
 *    00    DISABLE_OPT               0
 * </pre>
 */
#define MACDSP_API_RX_RESMAPLER_OPT_FLAG_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000640)
#define MACDSP_API_RX_RESMAPLER_OPT_FLAG_OFFSET      0x00000640
#define MACDSP_API_RX_RESMAPLER_OPT_FLAG_INDEX       0x00000190
#define MACDSP_API_RX_RESMAPLER_OPT_FLAG_RESET       0x00000000

static inline u32 macdsp_api_rx_resmapler_opt_flag_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_RESMAPLER_OPT_FLAG_ADDR);
}

static inline void macdsp_api_rx_resmapler_opt_flag_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_RESMAPLER_OPT_FLAG_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_RESMAPLER_OPT_FLAG_THD_VAL_MASK    ((u32)0x000FFFF0)
#define MACDSP_API_RX_RESMAPLER_OPT_FLAG_THD_VAL_LSB    4
#define MACDSP_API_RX_RESMAPLER_OPT_FLAG_THD_VAL_WIDTH    ((u32)0x00000010)
#define MACDSP_API_RX_RESMAPLER_OPT_FLAG_DISABLE_OPT_BIT    ((u32)0x00000001)
#define MACDSP_API_RX_RESMAPLER_OPT_FLAG_DISABLE_OPT_POS    0

#define MACDSP_API_RX_RESMAPLER_OPT_FLAG_THD_VAL_RST    0x0
#define MACDSP_API_RX_RESMAPLER_OPT_FLAG_DISABLE_OPT_RST    0x0

static inline void macdsp_api_rx_resmapler_opt_flag_pack(struct cl_chip *chip, u16 thd_val, u8 disable_opt)
{
	ASSERT_ERR_CHIP((((u32)thd_val << 4) & ~((u32)0x000FFFF0)) == 0);
	ASSERT_ERR_CHIP((((u32)disable_opt << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_RESMAPLER_OPT_FLAG_ADDR, ((u32)thd_val << 4) | ((u32)disable_opt << 0));
}

static inline void macdsp_api_rx_resmapler_opt_flag_unpack(struct cl_chip *chip, u16 *thd_val, u8 *disable_opt)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_RESMAPLER_OPT_FLAG_ADDR);

	*thd_val = (local_val & ((u32)0x000FFFF0)) >> 4;
	*disable_opt = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u16 macdsp_api_rx_resmapler_opt_flag_thd_val_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_RESMAPLER_OPT_FLAG_ADDR);

	return (u16)((local_val & ((u32)0x000FFFF0)) >> 4);
}

static inline void macdsp_api_rx_resmapler_opt_flag_thd_val_setf(struct cl_chip *chip, u16 thdval)
{
	ASSERT_ERR_CHIP((((u32)thdval << 4) & ~((u32)0x000FFFF0)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_RESMAPLER_OPT_FLAG_ADDR, (cl_reg_read(chip, MACDSP_API_RX_RESMAPLER_OPT_FLAG_ADDR) & ~((u32)0x000FFFF0)) | ((u32)thdval << 4));
}

static inline u8 macdsp_api_rx_resmapler_opt_flag_disable_opt_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_RESMAPLER_OPT_FLAG_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void macdsp_api_rx_resmapler_opt_flag_disable_opt_setf(struct cl_chip *chip, u8 disableopt)
{
	ASSERT_ERR_CHIP((((u32)disableopt << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_RESMAPLER_OPT_FLAG_ADDR, (cl_reg_read(chip, MACDSP_API_RX_RESMAPLER_OPT_FLAG_ADDR) & ~((u32)0x00000001)) | ((u32)disableopt << 0));
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
#define MACDSP_API_CONFIG_SPACE_SHADOW_VALUE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000700)
#define MACDSP_API_CONFIG_SPACE_SHADOW_VALUE_OFFSET      0x00000700
#define MACDSP_API_CONFIG_SPACE_SHADOW_VALUE_INDEX       0x000001C0
#define MACDSP_API_CONFIG_SPACE_SHADOW_VALUE_RESET       0x00000000

static inline u32 macdsp_api_config_space_shadow_value_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_SHADOW_VALUE_ADDR);
}

static inline void macdsp_api_config_space_shadow_value_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_CONFIG_SPACE_SHADOW_VALUE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_CONFIG_SPACE_SHADOW_VALUE_CONFIG_SPACE_SHADOW_VALUE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_CONFIG_SPACE_SHADOW_VALUE_CONFIG_SPACE_SHADOW_VALUE_LSB    0
#define MACDSP_API_CONFIG_SPACE_SHADOW_VALUE_CONFIG_SPACE_SHADOW_VALUE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_CONFIG_SPACE_SHADOW_VALUE_CONFIG_SPACE_SHADOW_VALUE_RST    0x0

static inline u32 macdsp_api_config_space_shadow_value_config_space_shadow_value_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CONFIG_SPACE_SHADOW_VALUE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_config_space_shadow_value_config_space_shadow_value_setf(struct cl_chip *chip, u32 configspaceshadowvalue)
{
	ASSERT_ERR_CHIP((((u32)configspaceshadowvalue << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_CONFIG_SPACE_SHADOW_VALUE_ADDR, (u32)configspaceshadowvalue << 0);
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
#define MACDSP_API_AGC_STAT_GAIN_VALUE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000704)
#define MACDSP_API_AGC_STAT_GAIN_VALUE_OFFSET      0x00000704
#define MACDSP_API_AGC_STAT_GAIN_VALUE_INDEX       0x000001C1
#define MACDSP_API_AGC_STAT_GAIN_VALUE_RESET       0x00000000

static inline u32 macdsp_api_agc_stat_gain_value_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_AGC_STAT_GAIN_VALUE_ADDR);
}

static inline void macdsp_api_agc_stat_gain_value_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_AGC_STAT_GAIN_VALUE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_AGC_STAT_GAIN_VALUE_AGC_STAT_GAIN_VALUE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_AGC_STAT_GAIN_VALUE_AGC_STAT_GAIN_VALUE_LSB    0
#define MACDSP_API_AGC_STAT_GAIN_VALUE_AGC_STAT_GAIN_VALUE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_AGC_STAT_GAIN_VALUE_AGC_STAT_GAIN_VALUE_RST    0x0

static inline u32 macdsp_api_agc_stat_gain_value_agc_stat_gain_value_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_AGC_STAT_GAIN_VALUE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_agc_stat_gain_value_agc_stat_gain_value_setf(struct cl_chip *chip, u32 agcstatgainvalue)
{
	ASSERT_ERR_CHIP((((u32)agcstatgainvalue << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_AGC_STAT_GAIN_VALUE_ADDR, (u32)agcstatgainvalue << 0);
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
#define MACDSP_API_STF_END_INDEX_VALUE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000708)
#define MACDSP_API_STF_END_INDEX_VALUE_OFFSET      0x00000708
#define MACDSP_API_STF_END_INDEX_VALUE_INDEX       0x000001C2
#define MACDSP_API_STF_END_INDEX_VALUE_RESET       0x00000000

static inline u32 macdsp_api_stf_end_index_value_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_STF_END_INDEX_VALUE_ADDR);
}

static inline void macdsp_api_stf_end_index_value_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_STF_END_INDEX_VALUE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_STF_END_INDEX_VALUE_STF_END_INDEX_VALUE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_STF_END_INDEX_VALUE_STF_END_INDEX_VALUE_LSB    0
#define MACDSP_API_STF_END_INDEX_VALUE_STF_END_INDEX_VALUE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_STF_END_INDEX_VALUE_STF_END_INDEX_VALUE_RST    0x0

static inline u32 macdsp_api_stf_end_index_value_stf_end_index_value_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_STF_END_INDEX_VALUE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_stf_end_index_value_stf_end_index_value_setf(struct cl_chip *chip, u32 stfendindexvalue)
{
	ASSERT_ERR_CHIP((((u32)stfendindexvalue << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_STF_END_INDEX_VALUE_ADDR, (u32)stfendindexvalue << 0);
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
#define MACDSP_API_FFO_PLUS_CFO_VALUE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000070C)
#define MACDSP_API_FFO_PLUS_CFO_VALUE_OFFSET      0x0000070C
#define MACDSP_API_FFO_PLUS_CFO_VALUE_INDEX       0x000001C3
#define MACDSP_API_FFO_PLUS_CFO_VALUE_RESET       0x00000000

static inline u32 macdsp_api_ffo_plus_cfo_value_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_FFO_PLUS_CFO_VALUE_ADDR);
}

static inline void macdsp_api_ffo_plus_cfo_value_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_FFO_PLUS_CFO_VALUE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_FFO_PLUS_CFO_VALUE_FFO_PLUS_CFO_VALUE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_FFO_PLUS_CFO_VALUE_FFO_PLUS_CFO_VALUE_LSB    0
#define MACDSP_API_FFO_PLUS_CFO_VALUE_FFO_PLUS_CFO_VALUE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_FFO_PLUS_CFO_VALUE_FFO_PLUS_CFO_VALUE_RST    0x0

static inline u32 macdsp_api_ffo_plus_cfo_value_ffo_plus_cfo_value_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_FFO_PLUS_CFO_VALUE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_ffo_plus_cfo_value_ffo_plus_cfo_value_setf(struct cl_chip *chip, u32 ffopluscfovalue)
{
	ASSERT_ERR_CHIP((((u32)ffopluscfovalue << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_FFO_PLUS_CFO_VALUE_ADDR, (u32)ffopluscfovalue << 0);
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
#define MACDSP_API_SYNC_FIX_VALUE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000710)
#define MACDSP_API_SYNC_FIX_VALUE_OFFSET      0x00000710
#define MACDSP_API_SYNC_FIX_VALUE_INDEX       0x000001C4
#define MACDSP_API_SYNC_FIX_VALUE_RESET       0x00000000

static inline u32 macdsp_api_sync_fix_value_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SYNC_FIX_VALUE_ADDR);
}

static inline void macdsp_api_sync_fix_value_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SYNC_FIX_VALUE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SYNC_FIX_VALUE_SYNC_FIX_VALUE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_SYNC_FIX_VALUE_SYNC_FIX_VALUE_LSB    0
#define MACDSP_API_SYNC_FIX_VALUE_SYNC_FIX_VALUE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_SYNC_FIX_VALUE_SYNC_FIX_VALUE_RST    0x0

static inline u32 macdsp_api_sync_fix_value_sync_fix_value_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SYNC_FIX_VALUE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_sync_fix_value_sync_fix_value_setf(struct cl_chip *chip, u32 syncfixvalue)
{
	ASSERT_ERR_CHIP((((u32)syncfixvalue << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SYNC_FIX_VALUE_ADDR, (u32)syncfixvalue << 0);
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
#define MACDSP_API_LEG_REMAIN_SYM_VALUE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000714)
#define MACDSP_API_LEG_REMAIN_SYM_VALUE_OFFSET      0x00000714
#define MACDSP_API_LEG_REMAIN_SYM_VALUE_INDEX       0x000001C5
#define MACDSP_API_LEG_REMAIN_SYM_VALUE_RESET       0x00000000

static inline u32 macdsp_api_leg_remain_sym_value_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_LEG_REMAIN_SYM_VALUE_ADDR);
}

static inline void macdsp_api_leg_remain_sym_value_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_LEG_REMAIN_SYM_VALUE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_LEG_REMAIN_SYM_VALUE_LEG_REMAIN_SYM_VALUE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_LEG_REMAIN_SYM_VALUE_LEG_REMAIN_SYM_VALUE_LSB    0
#define MACDSP_API_LEG_REMAIN_SYM_VALUE_LEG_REMAIN_SYM_VALUE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_LEG_REMAIN_SYM_VALUE_LEG_REMAIN_SYM_VALUE_RST    0x0

static inline u32 macdsp_api_leg_remain_sym_value_leg_remain_sym_value_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LEG_REMAIN_SYM_VALUE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_leg_remain_sym_value_leg_remain_sym_value_setf(struct cl_chip *chip, u32 legremainsymvalue)
{
	ASSERT_ERR_CHIP((((u32)legremainsymvalue << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_LEG_REMAIN_SYM_VALUE_ADDR, (u32)legremainsymvalue << 0);
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
#define MACDSP_API_HT_REMIAN_SYMB_VALUE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000718)
#define MACDSP_API_HT_REMIAN_SYMB_VALUE_OFFSET      0x00000718
#define MACDSP_API_HT_REMIAN_SYMB_VALUE_INDEX       0x000001C6
#define MACDSP_API_HT_REMIAN_SYMB_VALUE_RESET       0x00000000

static inline u32 macdsp_api_ht_remian_symb_value_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HT_REMIAN_SYMB_VALUE_ADDR);
}

static inline void macdsp_api_ht_remian_symb_value_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HT_REMIAN_SYMB_VALUE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HT_REMIAN_SYMB_VALUE_HT_REMIAN_SYMB_VALUE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_HT_REMIAN_SYMB_VALUE_HT_REMIAN_SYMB_VALUE_LSB    0
#define MACDSP_API_HT_REMIAN_SYMB_VALUE_HT_REMIAN_SYMB_VALUE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_HT_REMIAN_SYMB_VALUE_HT_REMIAN_SYMB_VALUE_RST    0x0

static inline u32 macdsp_api_ht_remian_symb_value_ht_remian_symb_value_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HT_REMIAN_SYMB_VALUE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_ht_remian_symb_value_ht_remian_symb_value_setf(struct cl_chip *chip, u32 htremiansymbvalue)
{
	ASSERT_ERR_CHIP((((u32)htremiansymbvalue << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HT_REMIAN_SYMB_VALUE_ADDR, (u32)htremiansymbvalue << 0);
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
#define MACDSP_API_PPS_SUM_PER_SS_0_VALUE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000071C)
#define MACDSP_API_PPS_SUM_PER_SS_0_VALUE_OFFSET      0x0000071C
#define MACDSP_API_PPS_SUM_PER_SS_0_VALUE_INDEX       0x000001C7
#define MACDSP_API_PPS_SUM_PER_SS_0_VALUE_RESET       0x00000000

static inline u32 macdsp_api_pps_sum_per_ss_0_value_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_PPS_SUM_PER_SS_0_VALUE_ADDR);
}

static inline void macdsp_api_pps_sum_per_ss_0_value_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_PPS_SUM_PER_SS_0_VALUE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_PPS_SUM_PER_SS_0_VALUE_PPS_SUM_PER_SS_0_VALUE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_PPS_SUM_PER_SS_0_VALUE_PPS_SUM_PER_SS_0_VALUE_LSB    0
#define MACDSP_API_PPS_SUM_PER_SS_0_VALUE_PPS_SUM_PER_SS_0_VALUE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_PPS_SUM_PER_SS_0_VALUE_PPS_SUM_PER_SS_0_VALUE_RST    0x0

static inline u32 macdsp_api_pps_sum_per_ss_0_value_pps_sum_per_ss_0_value_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_PPS_SUM_PER_SS_0_VALUE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_pps_sum_per_ss_0_value_pps_sum_per_ss_0_value_setf(struct cl_chip *chip, u32 ppssumperss0value)
{
	ASSERT_ERR_CHIP((((u32)ppssumperss0value << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_PPS_SUM_PER_SS_0_VALUE_ADDR, (u32)ppssumperss0value << 0);
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
#define MACDSP_API_PPS_SUM_PER_SS_1_VALUE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000720)
#define MACDSP_API_PPS_SUM_PER_SS_1_VALUE_OFFSET      0x00000720
#define MACDSP_API_PPS_SUM_PER_SS_1_VALUE_INDEX       0x000001C8
#define MACDSP_API_PPS_SUM_PER_SS_1_VALUE_RESET       0x00000000

static inline u32 macdsp_api_pps_sum_per_ss_1_value_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_PPS_SUM_PER_SS_1_VALUE_ADDR);
}

static inline void macdsp_api_pps_sum_per_ss_1_value_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_PPS_SUM_PER_SS_1_VALUE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_PPS_SUM_PER_SS_1_VALUE_PPS_SUM_PER_SS_1_VALUE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_PPS_SUM_PER_SS_1_VALUE_PPS_SUM_PER_SS_1_VALUE_LSB    0
#define MACDSP_API_PPS_SUM_PER_SS_1_VALUE_PPS_SUM_PER_SS_1_VALUE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_PPS_SUM_PER_SS_1_VALUE_PPS_SUM_PER_SS_1_VALUE_RST    0x0

static inline u32 macdsp_api_pps_sum_per_ss_1_value_pps_sum_per_ss_1_value_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_PPS_SUM_PER_SS_1_VALUE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_pps_sum_per_ss_1_value_pps_sum_per_ss_1_value_setf(struct cl_chip *chip, u32 ppssumperss1value)
{
	ASSERT_ERR_CHIP((((u32)ppssumperss1value << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_PPS_SUM_PER_SS_1_VALUE_ADDR, (u32)ppssumperss1value << 0);
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
#define MACDSP_API_PPS_SUM_PER_SS_2_VALUE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000724)
#define MACDSP_API_PPS_SUM_PER_SS_2_VALUE_OFFSET      0x00000724
#define MACDSP_API_PPS_SUM_PER_SS_2_VALUE_INDEX       0x000001C9
#define MACDSP_API_PPS_SUM_PER_SS_2_VALUE_RESET       0x00000000

static inline u32 macdsp_api_pps_sum_per_ss_2_value_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_PPS_SUM_PER_SS_2_VALUE_ADDR);
}

static inline void macdsp_api_pps_sum_per_ss_2_value_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_PPS_SUM_PER_SS_2_VALUE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_PPS_SUM_PER_SS_2_VALUE_PPS_SUM_PER_SS_2_VALUE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_PPS_SUM_PER_SS_2_VALUE_PPS_SUM_PER_SS_2_VALUE_LSB    0
#define MACDSP_API_PPS_SUM_PER_SS_2_VALUE_PPS_SUM_PER_SS_2_VALUE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_PPS_SUM_PER_SS_2_VALUE_PPS_SUM_PER_SS_2_VALUE_RST    0x0

static inline u32 macdsp_api_pps_sum_per_ss_2_value_pps_sum_per_ss_2_value_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_PPS_SUM_PER_SS_2_VALUE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_pps_sum_per_ss_2_value_pps_sum_per_ss_2_value_setf(struct cl_chip *chip, u32 ppssumperss2value)
{
	ASSERT_ERR_CHIP((((u32)ppssumperss2value << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_PPS_SUM_PER_SS_2_VALUE_ADDR, (u32)ppssumperss2value << 0);
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
#define MACDSP_API_PPS_SUM_PER_SS_3_VALUE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000728)
#define MACDSP_API_PPS_SUM_PER_SS_3_VALUE_OFFSET      0x00000728
#define MACDSP_API_PPS_SUM_PER_SS_3_VALUE_INDEX       0x000001CA
#define MACDSP_API_PPS_SUM_PER_SS_3_VALUE_RESET       0x00000000

static inline u32 macdsp_api_pps_sum_per_ss_3_value_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_PPS_SUM_PER_SS_3_VALUE_ADDR);
}

static inline void macdsp_api_pps_sum_per_ss_3_value_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_PPS_SUM_PER_SS_3_VALUE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_PPS_SUM_PER_SS_3_VALUE_PPS_SUM_PER_SS_3_VALUE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_PPS_SUM_PER_SS_3_VALUE_PPS_SUM_PER_SS_3_VALUE_LSB    0
#define MACDSP_API_PPS_SUM_PER_SS_3_VALUE_PPS_SUM_PER_SS_3_VALUE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_PPS_SUM_PER_SS_3_VALUE_PPS_SUM_PER_SS_3_VALUE_RST    0x0

static inline u32 macdsp_api_pps_sum_per_ss_3_value_pps_sum_per_ss_3_value_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_PPS_SUM_PER_SS_3_VALUE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_pps_sum_per_ss_3_value_pps_sum_per_ss_3_value_setf(struct cl_chip *chip, u32 ppssumperss3value)
{
	ASSERT_ERR_CHIP((((u32)ppssumperss3value << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_PPS_SUM_PER_SS_3_VALUE_ADDR, (u32)ppssumperss3value << 0);
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
#define MACDSP_API_PPS_SUM_PER_SS_4_VALUE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000072C)
#define MACDSP_API_PPS_SUM_PER_SS_4_VALUE_OFFSET      0x0000072C
#define MACDSP_API_PPS_SUM_PER_SS_4_VALUE_INDEX       0x000001CB
#define MACDSP_API_PPS_SUM_PER_SS_4_VALUE_RESET       0x00000000

static inline u32 macdsp_api_pps_sum_per_ss_4_value_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_PPS_SUM_PER_SS_4_VALUE_ADDR);
}

static inline void macdsp_api_pps_sum_per_ss_4_value_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_PPS_SUM_PER_SS_4_VALUE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_PPS_SUM_PER_SS_4_VALUE_PPS_SUM_PER_SS_4_VALUE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_PPS_SUM_PER_SS_4_VALUE_PPS_SUM_PER_SS_4_VALUE_LSB    0
#define MACDSP_API_PPS_SUM_PER_SS_4_VALUE_PPS_SUM_PER_SS_4_VALUE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_PPS_SUM_PER_SS_4_VALUE_PPS_SUM_PER_SS_4_VALUE_RST    0x0

static inline u32 macdsp_api_pps_sum_per_ss_4_value_pps_sum_per_ss_4_value_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_PPS_SUM_PER_SS_4_VALUE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_pps_sum_per_ss_4_value_pps_sum_per_ss_4_value_setf(struct cl_chip *chip, u32 ppssumperss4value)
{
	ASSERT_ERR_CHIP((((u32)ppssumperss4value << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_PPS_SUM_PER_SS_4_VALUE_ADDR, (u32)ppssumperss4value << 0);
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
#define MACDSP_API_RX_N_STS_VALUE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000730)
#define MACDSP_API_RX_N_STS_VALUE_OFFSET      0x00000730
#define MACDSP_API_RX_N_STS_VALUE_INDEX       0x000001CC
#define MACDSP_API_RX_N_STS_VALUE_RESET       0x00000000

static inline u32 macdsp_api_rx_n_sts_value_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_N_STS_VALUE_ADDR);
}

static inline void macdsp_api_rx_n_sts_value_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_N_STS_VALUE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_N_STS_VALUE_RX_NSTS_VALUE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_RX_N_STS_VALUE_RX_NSTS_VALUE_LSB    0
#define MACDSP_API_RX_N_STS_VALUE_RX_NSTS_VALUE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_RX_N_STS_VALUE_RX_NSTS_VALUE_RST    0x0

static inline u32 macdsp_api_rx_n_sts_value_rx_nsts_value_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_N_STS_VALUE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_rx_n_sts_value_rx_nsts_value_setf(struct cl_chip *chip, u32 rxnstsvalue)
{
	ASSERT_ERR_CHIP((((u32)rxnstsvalue << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_N_STS_VALUE_ADDR, (u32)rxnstsvalue << 0);
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
#define MACDSP_API_CALIBRATION_IDX_VALUE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000734)
#define MACDSP_API_CALIBRATION_IDX_VALUE_OFFSET      0x00000734
#define MACDSP_API_CALIBRATION_IDX_VALUE_INDEX       0x000001CD
#define MACDSP_API_CALIBRATION_IDX_VALUE_RESET       0x00000000

static inline u32 macdsp_api_calibration_idx_value_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_CALIBRATION_IDX_VALUE_ADDR);
}

static inline void macdsp_api_calibration_idx_value_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_CALIBRATION_IDX_VALUE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_CALIBRATION_IDX_VALUE_CALIBRATION_IDX_VALUE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_CALIBRATION_IDX_VALUE_CALIBRATION_IDX_VALUE_LSB    0
#define MACDSP_API_CALIBRATION_IDX_VALUE_CALIBRATION_IDX_VALUE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_CALIBRATION_IDX_VALUE_CALIBRATION_IDX_VALUE_RST    0x0

static inline u32 macdsp_api_calibration_idx_value_calibration_idx_value_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CALIBRATION_IDX_VALUE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_calibration_idx_value_calibration_idx_value_setf(struct cl_chip *chip, u32 calibrationidxvalue)
{
	ASSERT_ERR_CHIP((((u32)calibrationidxvalue << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_CALIBRATION_IDX_VALUE_ADDR, (u32)calibrationidxvalue << 0);
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
#define MACDSP_API_HE_EVM_VAL_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000738)
#define MACDSP_API_HE_EVM_VAL_OFFSET      0x00000738
#define MACDSP_API_HE_EVM_VAL_INDEX       0x000001CE
#define MACDSP_API_HE_EVM_VAL_RESET       0x00000000

static inline u32 macdsp_api_he_evm_val_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_EVM_VAL_ADDR);
}

static inline void macdsp_api_he_evm_val_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_EVM_VAL_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_EVM_VAL_HE_EVM_VAL_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_HE_EVM_VAL_HE_EVM_VAL_LSB    0
#define MACDSP_API_HE_EVM_VAL_HE_EVM_VAL_WIDTH    ((u32)0x00000020)

#define MACDSP_API_HE_EVM_VAL_HE_EVM_VAL_RST    0x0

static inline u32 macdsp_api_he_evm_val_he_evm_val_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_EVM_VAL_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_he_evm_val_he_evm_val_setf(struct cl_chip *chip, u32 heevmval)
{
	ASSERT_ERR_CHIP((((u32)heevmval << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_EVM_VAL_ADDR, (u32)heevmval << 0);
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
#define MACDSP_API_HE_EVM_SYMB_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000073C)
#define MACDSP_API_HE_EVM_SYMB_OFFSET      0x0000073C
#define MACDSP_API_HE_EVM_SYMB_INDEX       0x000001CF
#define MACDSP_API_HE_EVM_SYMB_RESET       0x00000000

static inline u32 macdsp_api_he_evm_symb_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_EVM_SYMB_ADDR);
}

static inline void macdsp_api_he_evm_symb_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_EVM_SYMB_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_EVM_SYMB_HE_EVM_SYMB_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_HE_EVM_SYMB_HE_EVM_SYMB_LSB    0
#define MACDSP_API_HE_EVM_SYMB_HE_EVM_SYMB_WIDTH    ((u32)0x00000020)

#define MACDSP_API_HE_EVM_SYMB_HE_EVM_SYMB_RST    0x0

static inline u32 macdsp_api_he_evm_symb_he_evm_symb_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_EVM_SYMB_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_he_evm_symb_he_evm_symb_setf(struct cl_chip *chip, u32 heevmsymb)
{
	ASSERT_ERR_CHIP((((u32)heevmsymb << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_EVM_SYMB_ADDR, (u32)heevmsymb << 0);
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
#define MACDSP_API_SE_TX_HE_NDP_TABLE_SET_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000740)
#define MACDSP_API_SE_TX_HE_NDP_TABLE_SET_OFFSET      0x00000740
#define MACDSP_API_SE_TX_HE_NDP_TABLE_SET_INDEX       0x000001D0
#define MACDSP_API_SE_TX_HE_NDP_TABLE_SET_RESET       0x00000000

static inline u32 macdsp_api_se_tx_he_ndp_table_set_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SE_TX_HE_NDP_TABLE_SET_ADDR);
}

static inline void macdsp_api_se_tx_he_ndp_table_set_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SE_TX_HE_NDP_TABLE_SET_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SE_TX_HE_NDP_TABLE_SET_SE_TX_HE_NDP_TABLE_SET_FLAG_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_SE_TX_HE_NDP_TABLE_SET_SE_TX_HE_NDP_TABLE_SET_FLAG_LSB    0
#define MACDSP_API_SE_TX_HE_NDP_TABLE_SET_SE_TX_HE_NDP_TABLE_SET_FLAG_WIDTH    ((u32)0x00000020)

#define MACDSP_API_SE_TX_HE_NDP_TABLE_SET_SE_TX_HE_NDP_TABLE_SET_FLAG_RST    0x0

static inline u32 macdsp_api_se_tx_he_ndp_table_set_se_tx_he_ndp_table_set_flag_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SE_TX_HE_NDP_TABLE_SET_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_se_tx_he_ndp_table_set_se_tx_he_ndp_table_set_flag_setf(struct cl_chip *chip, u32 setxhendptablesetflag)
{
	ASSERT_ERR_CHIP((((u32)setxhendptablesetflag << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SE_TX_HE_NDP_TABLE_SET_ADDR, (u32)setxhendptablesetflag << 0);
}

/**
 * @brief HE_EVM_1 register definition
 *  HE_EVM_1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVM                       0x0
 * </pre>
 */
#define MACDSP_API_HE_EVM_1_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000744)
#define MACDSP_API_HE_EVM_1_OFFSET      0x00000744
#define MACDSP_API_HE_EVM_1_INDEX       0x000001D1
#define MACDSP_API_HE_EVM_1_RESET       0x00000000

static inline u32 macdsp_api_he_evm_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_EVM_1_ADDR);
}

static inline void macdsp_api_he_evm_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_EVM_1_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_EVM_1_EVM_MASK        ((u32)0xFFFFFFFF)
#define MACDSP_API_HE_EVM_1_EVM_LSB         0
#define MACDSP_API_HE_EVM_1_EVM_WIDTH       ((u32)0x00000020)

#define MACDSP_API_HE_EVM_1_EVM_RST         0x0

static inline u32 macdsp_api_he_evm_1_evm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_EVM_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_he_evm_1_evm_setf(struct cl_chip *chip, u32 evm)
{
	ASSERT_ERR_CHIP((((u32)evm << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_EVM_1_ADDR, (u32)evm << 0);
}

/**
 * @brief HE_EVM_2 register definition
 *  HE_EVM_2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVM                       0x0
 * </pre>
 */
#define MACDSP_API_HE_EVM_2_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000748)
#define MACDSP_API_HE_EVM_2_OFFSET      0x00000748
#define MACDSP_API_HE_EVM_2_INDEX       0x000001D2
#define MACDSP_API_HE_EVM_2_RESET       0x00000000

static inline u32 macdsp_api_he_evm_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_EVM_2_ADDR);
}

static inline void macdsp_api_he_evm_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_EVM_2_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_EVM_2_EVM_MASK        ((u32)0xFFFFFFFF)
#define MACDSP_API_HE_EVM_2_EVM_LSB         0
#define MACDSP_API_HE_EVM_2_EVM_WIDTH       ((u32)0x00000020)

#define MACDSP_API_HE_EVM_2_EVM_RST         0x0

static inline u32 macdsp_api_he_evm_2_evm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_EVM_2_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_he_evm_2_evm_setf(struct cl_chip *chip, u32 evm)
{
	ASSERT_ERR_CHIP((((u32)evm << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_EVM_2_ADDR, (u32)evm << 0);
}

/**
 * @brief HE_EVM_3 register definition
 *  HE_EVM_3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVM                       0x0
 * </pre>
 */
#define MACDSP_API_HE_EVM_3_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000074C)
#define MACDSP_API_HE_EVM_3_OFFSET      0x0000074C
#define MACDSP_API_HE_EVM_3_INDEX       0x000001D3
#define MACDSP_API_HE_EVM_3_RESET       0x00000000

static inline u32 macdsp_api_he_evm_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_EVM_3_ADDR);
}

static inline void macdsp_api_he_evm_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_EVM_3_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_EVM_3_EVM_MASK        ((u32)0xFFFFFFFF)
#define MACDSP_API_HE_EVM_3_EVM_LSB         0
#define MACDSP_API_HE_EVM_3_EVM_WIDTH       ((u32)0x00000020)

#define MACDSP_API_HE_EVM_3_EVM_RST         0x0

static inline u32 macdsp_api_he_evm_3_evm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_EVM_3_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_he_evm_3_evm_setf(struct cl_chip *chip, u32 evm)
{
	ASSERT_ERR_CHIP((((u32)evm << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_EVM_3_ADDR, (u32)evm << 0);
}

/**
 * @brief HE_EVM_4 register definition
 *  HE_EVM_4 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVM                       0x0
 * </pre>
 */
#define MACDSP_API_HE_EVM_4_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000750)
#define MACDSP_API_HE_EVM_4_OFFSET      0x00000750
#define MACDSP_API_HE_EVM_4_INDEX       0x000001D4
#define MACDSP_API_HE_EVM_4_RESET       0x00000000

static inline u32 macdsp_api_he_evm_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_EVM_4_ADDR);
}

static inline void macdsp_api_he_evm_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_EVM_4_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_EVM_4_EVM_MASK        ((u32)0xFFFFFFFF)
#define MACDSP_API_HE_EVM_4_EVM_LSB         0
#define MACDSP_API_HE_EVM_4_EVM_WIDTH       ((u32)0x00000020)

#define MACDSP_API_HE_EVM_4_EVM_RST         0x0

static inline u32 macdsp_api_he_evm_4_evm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_EVM_4_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_he_evm_4_evm_setf(struct cl_chip *chip, u32 evm)
{
	ASSERT_ERR_CHIP((((u32)evm << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_EVM_4_ADDR, (u32)evm << 0);
}

/**
 * @brief HE_EVM_5 register definition
 *  HE_EVM_5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVM                       0x0
 * </pre>
 */
#define MACDSP_API_HE_EVM_5_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000754)
#define MACDSP_API_HE_EVM_5_OFFSET      0x00000754
#define MACDSP_API_HE_EVM_5_INDEX       0x000001D5
#define MACDSP_API_HE_EVM_5_RESET       0x00000000

static inline u32 macdsp_api_he_evm_5_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_EVM_5_ADDR);
}

static inline void macdsp_api_he_evm_5_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_EVM_5_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_EVM_5_EVM_MASK        ((u32)0xFFFFFFFF)
#define MACDSP_API_HE_EVM_5_EVM_LSB         0
#define MACDSP_API_HE_EVM_5_EVM_WIDTH       ((u32)0x00000020)

#define MACDSP_API_HE_EVM_5_EVM_RST         0x0

static inline u32 macdsp_api_he_evm_5_evm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_EVM_5_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_he_evm_5_evm_setf(struct cl_chip *chip, u32 evm)
{
	ASSERT_ERR_CHIP((((u32)evm << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_EVM_5_ADDR, (u32)evm << 0);
}

/**
 * @brief HE_EVM_6 register definition
 *  HE_EVM_6 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVM                       0x0
 * </pre>
 */
#define MACDSP_API_HE_EVM_6_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000758)
#define MACDSP_API_HE_EVM_6_OFFSET      0x00000758
#define MACDSP_API_HE_EVM_6_INDEX       0x000001D6
#define MACDSP_API_HE_EVM_6_RESET       0x00000000

static inline u32 macdsp_api_he_evm_6_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_EVM_6_ADDR);
}

static inline void macdsp_api_he_evm_6_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_EVM_6_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_EVM_6_EVM_MASK        ((u32)0xFFFFFFFF)
#define MACDSP_API_HE_EVM_6_EVM_LSB         0
#define MACDSP_API_HE_EVM_6_EVM_WIDTH       ((u32)0x00000020)

#define MACDSP_API_HE_EVM_6_EVM_RST         0x0

static inline u32 macdsp_api_he_evm_6_evm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_EVM_6_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_he_evm_6_evm_setf(struct cl_chip *chip, u32 evm)
{
	ASSERT_ERR_CHIP((((u32)evm << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_EVM_6_ADDR, (u32)evm << 0);
}

/**
 * @brief HE_EVM_7 register definition
 *  HE_EVM_7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVM                       0x0
 * </pre>
 */
#define MACDSP_API_HE_EVM_7_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000075C)
#define MACDSP_API_HE_EVM_7_OFFSET      0x0000075C
#define MACDSP_API_HE_EVM_7_INDEX       0x000001D7
#define MACDSP_API_HE_EVM_7_RESET       0x00000000

static inline u32 macdsp_api_he_evm_7_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_EVM_7_ADDR);
}

static inline void macdsp_api_he_evm_7_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_EVM_7_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_EVM_7_EVM_MASK        ((u32)0xFFFFFFFF)
#define MACDSP_API_HE_EVM_7_EVM_LSB         0
#define MACDSP_API_HE_EVM_7_EVM_WIDTH       ((u32)0x00000020)

#define MACDSP_API_HE_EVM_7_EVM_RST         0x0

static inline u32 macdsp_api_he_evm_7_evm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_EVM_7_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_he_evm_7_evm_setf(struct cl_chip *chip, u32 evm)
{
	ASSERT_ERR_CHIP((((u32)evm << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_EVM_7_ADDR, (u32)evm << 0);
}

/**
 * @brief HE_EVM_8 register definition
 *  HE_EVM_8 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVM                       0x0
 * </pre>
 */
#define MACDSP_API_HE_EVM_8_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000760)
#define MACDSP_API_HE_EVM_8_OFFSET      0x00000760
#define MACDSP_API_HE_EVM_8_INDEX       0x000001D8
#define MACDSP_API_HE_EVM_8_RESET       0x00000000

static inline u32 macdsp_api_he_evm_8_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_EVM_8_ADDR);
}

static inline void macdsp_api_he_evm_8_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_EVM_8_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_EVM_8_EVM_MASK        ((u32)0xFFFFFFFF)
#define MACDSP_API_HE_EVM_8_EVM_LSB         0
#define MACDSP_API_HE_EVM_8_EVM_WIDTH       ((u32)0x00000020)

#define MACDSP_API_HE_EVM_8_EVM_RST         0x0

static inline u32 macdsp_api_he_evm_8_evm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_EVM_8_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_he_evm_8_evm_setf(struct cl_chip *chip, u32 evm)
{
	ASSERT_ERR_CHIP((((u32)evm << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_EVM_8_ADDR, (u32)evm << 0);
}

/**
 * @brief HE_EVM_9 register definition
 *  HE_EVM_9 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVM                       0x0
 * </pre>
 */
#define MACDSP_API_HE_EVM_9_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000764)
#define MACDSP_API_HE_EVM_9_OFFSET      0x00000764
#define MACDSP_API_HE_EVM_9_INDEX       0x000001D9
#define MACDSP_API_HE_EVM_9_RESET       0x00000000

static inline u32 macdsp_api_he_evm_9_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_EVM_9_ADDR);
}

static inline void macdsp_api_he_evm_9_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_EVM_9_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_EVM_9_EVM_MASK        ((u32)0xFFFFFFFF)
#define MACDSP_API_HE_EVM_9_EVM_LSB         0
#define MACDSP_API_HE_EVM_9_EVM_WIDTH       ((u32)0x00000020)

#define MACDSP_API_HE_EVM_9_EVM_RST         0x0

static inline u32 macdsp_api_he_evm_9_evm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_EVM_9_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_he_evm_9_evm_setf(struct cl_chip *chip, u32 evm)
{
	ASSERT_ERR_CHIP((((u32)evm << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_EVM_9_ADDR, (u32)evm << 0);
}

/**
 * @brief HE_EVM_10 register definition
 *  HE_EVM_10 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVM                       0x0
 * </pre>
 */
#define MACDSP_API_HE_EVM_10_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000768)
#define MACDSP_API_HE_EVM_10_OFFSET      0x00000768
#define MACDSP_API_HE_EVM_10_INDEX       0x000001DA
#define MACDSP_API_HE_EVM_10_RESET       0x00000000

static inline u32 macdsp_api_he_evm_10_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_EVM_10_ADDR);
}

static inline void macdsp_api_he_evm_10_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_EVM_10_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_EVM_10_EVM_MASK       ((u32)0xFFFFFFFF)
#define MACDSP_API_HE_EVM_10_EVM_LSB        0
#define MACDSP_API_HE_EVM_10_EVM_WIDTH      ((u32)0x00000020)

#define MACDSP_API_HE_EVM_10_EVM_RST        0x0

static inline u32 macdsp_api_he_evm_10_evm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_EVM_10_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_he_evm_10_evm_setf(struct cl_chip *chip, u32 evm)
{
	ASSERT_ERR_CHIP((((u32)evm << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_EVM_10_ADDR, (u32)evm << 0);
}

/**
 * @brief HE_EVM_11 register definition
 *  HE_EVM_11 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVM                       0x0
 * </pre>
 */
#define MACDSP_API_HE_EVM_11_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000076C)
#define MACDSP_API_HE_EVM_11_OFFSET      0x0000076C
#define MACDSP_API_HE_EVM_11_INDEX       0x000001DB
#define MACDSP_API_HE_EVM_11_RESET       0x00000000

static inline u32 macdsp_api_he_evm_11_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_EVM_11_ADDR);
}

static inline void macdsp_api_he_evm_11_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_EVM_11_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_EVM_11_EVM_MASK       ((u32)0xFFFFFFFF)
#define MACDSP_API_HE_EVM_11_EVM_LSB        0
#define MACDSP_API_HE_EVM_11_EVM_WIDTH      ((u32)0x00000020)

#define MACDSP_API_HE_EVM_11_EVM_RST        0x0

static inline u32 macdsp_api_he_evm_11_evm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_EVM_11_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_he_evm_11_evm_setf(struct cl_chip *chip, u32 evm)
{
	ASSERT_ERR_CHIP((((u32)evm << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_EVM_11_ADDR, (u32)evm << 0);
}

/**
 * @brief HE_EVM_12 register definition
 *  HE_EVM_12 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVM                       0x0
 * </pre>
 */
#define MACDSP_API_HE_EVM_12_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000770)
#define MACDSP_API_HE_EVM_12_OFFSET      0x00000770
#define MACDSP_API_HE_EVM_12_INDEX       0x000001DC
#define MACDSP_API_HE_EVM_12_RESET       0x00000000

static inline u32 macdsp_api_he_evm_12_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_EVM_12_ADDR);
}

static inline void macdsp_api_he_evm_12_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_EVM_12_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_EVM_12_EVM_MASK       ((u32)0xFFFFFFFF)
#define MACDSP_API_HE_EVM_12_EVM_LSB        0
#define MACDSP_API_HE_EVM_12_EVM_WIDTH      ((u32)0x00000020)

#define MACDSP_API_HE_EVM_12_EVM_RST        0x0

static inline u32 macdsp_api_he_evm_12_evm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_EVM_12_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_he_evm_12_evm_setf(struct cl_chip *chip, u32 evm)
{
	ASSERT_ERR_CHIP((((u32)evm << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_EVM_12_ADDR, (u32)evm << 0);
}

/**
 * @brief HE_EVM_13 register definition
 *  HE_EVM_13 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVM                       0x0
 * </pre>
 */
#define MACDSP_API_HE_EVM_13_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000774)
#define MACDSP_API_HE_EVM_13_OFFSET      0x00000774
#define MACDSP_API_HE_EVM_13_INDEX       0x000001DD
#define MACDSP_API_HE_EVM_13_RESET       0x00000000

static inline u32 macdsp_api_he_evm_13_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_EVM_13_ADDR);
}

static inline void macdsp_api_he_evm_13_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_EVM_13_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_EVM_13_EVM_MASK       ((u32)0xFFFFFFFF)
#define MACDSP_API_HE_EVM_13_EVM_LSB        0
#define MACDSP_API_HE_EVM_13_EVM_WIDTH      ((u32)0x00000020)

#define MACDSP_API_HE_EVM_13_EVM_RST        0x0

static inline u32 macdsp_api_he_evm_13_evm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_EVM_13_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_he_evm_13_evm_setf(struct cl_chip *chip, u32 evm)
{
	ASSERT_ERR_CHIP((((u32)evm << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_EVM_13_ADDR, (u32)evm << 0);
}

/**
 * @brief HE_EVM_14 register definition
 *  HE_EVM_14 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVM                       0x0
 * </pre>
 */
#define MACDSP_API_HE_EVM_14_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000778)
#define MACDSP_API_HE_EVM_14_OFFSET      0x00000778
#define MACDSP_API_HE_EVM_14_INDEX       0x000001DE
#define MACDSP_API_HE_EVM_14_RESET       0x00000000

static inline u32 macdsp_api_he_evm_14_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_EVM_14_ADDR);
}

static inline void macdsp_api_he_evm_14_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_EVM_14_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_EVM_14_EVM_MASK       ((u32)0xFFFFFFFF)
#define MACDSP_API_HE_EVM_14_EVM_LSB        0
#define MACDSP_API_HE_EVM_14_EVM_WIDTH      ((u32)0x00000020)

#define MACDSP_API_HE_EVM_14_EVM_RST        0x0

static inline u32 macdsp_api_he_evm_14_evm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_EVM_14_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_he_evm_14_evm_setf(struct cl_chip *chip, u32 evm)
{
	ASSERT_ERR_CHIP((((u32)evm << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_EVM_14_ADDR, (u32)evm << 0);
}

/**
 * @brief HE_EVM_15 register definition
 *  HE_EVM_15 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    15:00 EVM                       0x0
 * </pre>
 */
#define MACDSP_API_HE_EVM_15_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000077C)
#define MACDSP_API_HE_EVM_15_OFFSET      0x0000077C
#define MACDSP_API_HE_EVM_15_INDEX       0x000001DF
#define MACDSP_API_HE_EVM_15_RESET       0x00000000

static inline u32 macdsp_api_he_evm_15_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_EVM_15_ADDR);
}

static inline void macdsp_api_he_evm_15_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_EVM_15_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_EVM_15_EVM_MASK       ((u32)0x0000FFFF)
#define MACDSP_API_HE_EVM_15_EVM_LSB        0
#define MACDSP_API_HE_EVM_15_EVM_WIDTH      ((u32)0x00000010)

#define MACDSP_API_HE_EVM_15_EVM_RST        0x0

static inline u16 macdsp_api_he_evm_15_evm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_EVM_15_ADDR);

	return (u16)(local_val >> 0);
}

static inline void macdsp_api_he_evm_15_evm_setf(struct cl_chip *chip, u16 evm)
{
	ASSERT_ERR_CHIP((((u32)evm << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_EVM_15_ADDR, (u32)evm << 0);
}

/**
 * @brief HE_EVM_16 register definition
 *  HE_EVM_16 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 EVM                       0x0
 * </pre>
 */
#define MACDSP_API_HE_EVM_16_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000780)
#define MACDSP_API_HE_EVM_16_OFFSET      0x00000780
#define MACDSP_API_HE_EVM_16_INDEX       0x000001E0
#define MACDSP_API_HE_EVM_16_RESET       0x00000000

static inline u32 macdsp_api_he_evm_16_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_EVM_16_ADDR);
}

static inline void macdsp_api_he_evm_16_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_EVM_16_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_EVM_16_EVM_MASK       ((u32)0xFFFFFFFF)
#define MACDSP_API_HE_EVM_16_EVM_LSB        0
#define MACDSP_API_HE_EVM_16_EVM_WIDTH      ((u32)0x00000020)

#define MACDSP_API_HE_EVM_16_EVM_RST        0x0

static inline u32 macdsp_api_he_evm_16_evm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_EVM_16_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_he_evm_16_evm_setf(struct cl_chip *chip, u32 evm)
{
	ASSERT_ERR_CHIP((((u32)evm << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_EVM_16_ADDR, (u32)evm << 0);
}

/**
 * @brief HE_AVG_SYMBOL_NUM register definition
 *  SYMBOL_NUM register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 HE_SYMB_NUM               0x0
 * </pre>
 */
#define MACDSP_API_HE_AVG_SYMBOL_NUM_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000784)
#define MACDSP_API_HE_AVG_SYMBOL_NUM_OFFSET      0x00000784
#define MACDSP_API_HE_AVG_SYMBOL_NUM_INDEX       0x000001E1
#define MACDSP_API_HE_AVG_SYMBOL_NUM_RESET       0x00000000

static inline u32 macdsp_api_he_avg_symbol_num_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_HE_AVG_SYMBOL_NUM_ADDR);
}

static inline void macdsp_api_he_avg_symbol_num_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_HE_AVG_SYMBOL_NUM_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_HE_AVG_SYMBOL_NUM_HE_SYMB_NUM_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_HE_AVG_SYMBOL_NUM_HE_SYMB_NUM_LSB    0
#define MACDSP_API_HE_AVG_SYMBOL_NUM_HE_SYMB_NUM_WIDTH    ((u32)0x00000020)

#define MACDSP_API_HE_AVG_SYMBOL_NUM_HE_SYMB_NUM_RST    0x0

static inline u32 macdsp_api_he_avg_symbol_num_he_symb_num_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_HE_AVG_SYMBOL_NUM_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_he_avg_symbol_num_he_symb_num_setf(struct cl_chip *chip, u32 hesymbnum)
{
	ASSERT_ERR_CHIP((((u32)hesymbnum << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_HE_AVG_SYMBOL_NUM_ADDR, (u32)hesymbnum << 0);
}

/**
 * @brief CPE_STO_END_FRAME_VAL_0 register definition
 *  CPE_STO_END_FRAME_VAL_0 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:16 CPE                       0x0
 *    15:00 STO                       0x0
 * </pre>
 */
#define MACDSP_API_CPE_STO_END_FRAME_VAL_0_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000788)
#define MACDSP_API_CPE_STO_END_FRAME_VAL_0_OFFSET      0x00000788
#define MACDSP_API_CPE_STO_END_FRAME_VAL_0_INDEX       0x000001E2
#define MACDSP_API_CPE_STO_END_FRAME_VAL_0_RESET       0x00000000

static inline u32 macdsp_api_cpe_sto_end_frame_val_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_CPE_STO_END_FRAME_VAL_0_ADDR);
}

static inline void macdsp_api_cpe_sto_end_frame_val_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_CPE_STO_END_FRAME_VAL_0_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_CPE_STO_END_FRAME_VAL_0_CPE_MASK    ((u32)0xFFFF0000)
#define MACDSP_API_CPE_STO_END_FRAME_VAL_0_CPE_LSB    16
#define MACDSP_API_CPE_STO_END_FRAME_VAL_0_CPE_WIDTH    ((u32)0x00000010)
#define MACDSP_API_CPE_STO_END_FRAME_VAL_0_STO_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_CPE_STO_END_FRAME_VAL_0_STO_LSB    0
#define MACDSP_API_CPE_STO_END_FRAME_VAL_0_STO_WIDTH    ((u32)0x00000010)

#define MACDSP_API_CPE_STO_END_FRAME_VAL_0_CPE_RST    0x0
#define MACDSP_API_CPE_STO_END_FRAME_VAL_0_STO_RST    0x0

static inline void macdsp_api_cpe_sto_end_frame_val_0_pack(struct cl_chip *chip, u16 cpe, u16 sto)
{
	ASSERT_ERR_CHIP((((u32)cpe << 16) & ~((u32)0xFFFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)sto << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_CPE_STO_END_FRAME_VAL_0_ADDR, ((u32)cpe << 16) | ((u32)sto << 0));
}

static inline void macdsp_api_cpe_sto_end_frame_val_0_unpack(struct cl_chip *chip, u16 *cpe, u16 *sto)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CPE_STO_END_FRAME_VAL_0_ADDR);

	*cpe = (local_val & ((u32)0xFFFF0000)) >> 16;
	*sto = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_cpe_sto_end_frame_val_0_cpe_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CPE_STO_END_FRAME_VAL_0_ADDR);

	return (u16)((local_val & ((u32)0xFFFF0000)) >> 16);
}

static inline void macdsp_api_cpe_sto_end_frame_val_0_cpe_setf(struct cl_chip *chip, u16 cpe)
{
	ASSERT_ERR_CHIP((((u32)cpe << 16) & ~((u32)0xFFFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_CPE_STO_END_FRAME_VAL_0_ADDR, (cl_reg_read(chip, MACDSP_API_CPE_STO_END_FRAME_VAL_0_ADDR) & ~((u32)0xFFFF0000)) | ((u32)cpe << 16));
}

static inline u16 macdsp_api_cpe_sto_end_frame_val_0_sto_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CPE_STO_END_FRAME_VAL_0_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_cpe_sto_end_frame_val_0_sto_setf(struct cl_chip *chip, u16 sto)
{
	ASSERT_ERR_CHIP((((u32)sto << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_CPE_STO_END_FRAME_VAL_0_ADDR, (cl_reg_read(chip, MACDSP_API_CPE_STO_END_FRAME_VAL_0_ADDR) & ~((u32)0x0000FFFF)) | ((u32)sto << 0));
}

/**
 * @brief CPE_STO_END_FRAME_VAL_1 register definition
 *  CPE_STO_END_FRAME_VAL_1 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 * </pre>
 */
#define MACDSP_API_CPE_STO_END_FRAME_VAL_1_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000078C)
#define MACDSP_API_CPE_STO_END_FRAME_VAL_1_OFFSET      0x0000078C
#define MACDSP_API_CPE_STO_END_FRAME_VAL_1_INDEX       0x000001E3
#define MACDSP_API_CPE_STO_END_FRAME_VAL_1_RESET       0x00000000

/* Field definitions */

/**
 * @brief CPE_STO_END_FRAME_VAL_2 register definition
 *  CPE_STO_END_FRAME_VAL_2 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 * </pre>
 */
#define MACDSP_API_CPE_STO_END_FRAME_VAL_2_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000790)
#define MACDSP_API_CPE_STO_END_FRAME_VAL_2_OFFSET      0x00000790
#define MACDSP_API_CPE_STO_END_FRAME_VAL_2_INDEX       0x000001E4
#define MACDSP_API_CPE_STO_END_FRAME_VAL_2_RESET       0x00000000

/* Field definitions */

/**
 * @brief CPE_STO_END_FRAME_VAL_3 register definition
 *  CPE_STO_END_FRAME_VAL_3 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 * </pre>
 */
#define MACDSP_API_CPE_STO_END_FRAME_VAL_3_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000794)
#define MACDSP_API_CPE_STO_END_FRAME_VAL_3_OFFSET      0x00000794
#define MACDSP_API_CPE_STO_END_FRAME_VAL_3_INDEX       0x000001E5
#define MACDSP_API_CPE_STO_END_FRAME_VAL_3_RESET       0x00000000

/* Field definitions */

/**
 * @brief CPE_STO_END_FRAME_VAL_4 register definition
 *  CPE_STO_END_FRAME_VAL_4 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 * </pre>
 */
#define MACDSP_API_CPE_STO_END_FRAME_VAL_4_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000798)
#define MACDSP_API_CPE_STO_END_FRAME_VAL_4_OFFSET      0x00000798
#define MACDSP_API_CPE_STO_END_FRAME_VAL_4_INDEX       0x000001E6
#define MACDSP_API_CPE_STO_END_FRAME_VAL_4_RESET       0x00000000

/* Field definitions */

/**
 * @brief CPE_STO_END_FRAME_VAL_5 register definition
 *  CPE_STO_END_FRAME_VAL_5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 * </pre>
 */
#define MACDSP_API_CPE_STO_END_FRAME_VAL_5_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000079C)
#define MACDSP_API_CPE_STO_END_FRAME_VAL_5_OFFSET      0x0000079C
#define MACDSP_API_CPE_STO_END_FRAME_VAL_5_INDEX       0x000001E7
#define MACDSP_API_CPE_STO_END_FRAME_VAL_5_RESET       0x00000000

/* Field definitions */

/**
 * @brief CPE_STO_END_FRAME_VAL_6 register definition
 *  CPE_STO_END_FRAME_VAL_6 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 * </pre>
 */
#define MACDSP_API_CPE_STO_END_FRAME_VAL_6_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000007A0)
#define MACDSP_API_CPE_STO_END_FRAME_VAL_6_OFFSET      0x000007A0
#define MACDSP_API_CPE_STO_END_FRAME_VAL_6_INDEX       0x000001E8
#define MACDSP_API_CPE_STO_END_FRAME_VAL_6_RESET       0x00000000

/* Field definitions */

/**
 * @brief CPE_STO_END_FRAME_VAL_7 register definition
 *  CPE_STO_END_FRAME_VAL_7 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 * </pre>
 */
#define MACDSP_API_CPE_STO_END_FRAME_VAL_7_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000007A4)
#define MACDSP_API_CPE_STO_END_FRAME_VAL_7_OFFSET      0x000007A4
#define MACDSP_API_CPE_STO_END_FRAME_VAL_7_INDEX       0x000001E9
#define MACDSP_API_CPE_STO_END_FRAME_VAL_7_RESET       0x00000000

/* Field definitions */

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
#define MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000800)
#define MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_OFFSET      0x00000800
#define MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_INDEX       0x00000200
#define MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_RESET       0x00000000

static inline u32 macdsp_api_scale_a_heltf_r_01_from_matlab_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR);
}

static inline void macdsp_api_scale_a_heltf_r_01_from_matlab_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_SCALE_A_HELTF_R_1_MATLAB_MASK    ((u32)0xFFFF0000)
#define MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_SCALE_A_HELTF_R_1_MATLAB_LSB    16
#define MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_SCALE_A_HELTF_R_1_MATLAB_WIDTH    ((u32)0x00000010)
#define MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_SCALE_A_HELTF_R_0_MATLAB_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_SCALE_A_HELTF_R_0_MATLAB_LSB    0
#define MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_SCALE_A_HELTF_R_0_MATLAB_WIDTH    ((u32)0x00000010)

#define MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_SCALE_A_HELTF_R_1_MATLAB_RST    0x0
#define MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_SCALE_A_HELTF_R_0_MATLAB_RST    0x0

static inline void macdsp_api_scale_a_heltf_r_01_from_matlab_pack(struct cl_chip *chip, u16 scale_a_heltf_r1_matlab, u16 scale_a_heltf_r0_matlab)
{
	ASSERT_ERR_CHIP((((u32)scale_a_heltf_r1_matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)scale_a_heltf_r0_matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR, ((u32)scale_a_heltf_r1_matlab << 16) | ((u32)scale_a_heltf_r0_matlab << 0));
}

static inline void macdsp_api_scale_a_heltf_r_01_from_matlab_unpack(struct cl_chip *chip, u16 *scale_a_heltf_r1_matlab, u16 *scale_a_heltf_r0_matlab)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR);

	*scale_a_heltf_r1_matlab = (local_val & ((u32)0xFFFF0000)) >> 16;
	*scale_a_heltf_r0_matlab = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_scale_a_heltf_r_01_from_matlab_scale_a_heltf_r_1_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0xFFFF0000)) >> 16);
}

static inline void macdsp_api_scale_a_heltf_r_01_from_matlab_scale_a_heltf_r_1_matlab_setf(struct cl_chip *chip, u16 scaleaheltfr1matlab)
{
	ASSERT_ERR_CHIP((((u32)scaleaheltfr1matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR) & ~((u32)0xFFFF0000)) | ((u32)scaleaheltfr1matlab << 16));
}

static inline u16 macdsp_api_scale_a_heltf_r_01_from_matlab_scale_a_heltf_r_0_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_scale_a_heltf_r_01_from_matlab_scale_a_heltf_r_0_matlab_setf(struct cl_chip *chip, u16 scaleaheltfr0matlab)
{
	ASSERT_ERR_CHIP((((u32)scaleaheltfr0matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_01_FROM_MATLAB_ADDR) & ~((u32)0x0000FFFF)) | ((u32)scaleaheltfr0matlab << 0));
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
#define MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000804)
#define MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_OFFSET      0x00000804
#define MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_INDEX       0x00000201
#define MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_RESET       0x00000000

static inline u32 macdsp_api_scale_a_heltf_r_23_from_matlab_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR);
}

static inline void macdsp_api_scale_a_heltf_r_23_from_matlab_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_SCALE_A_HELTF_R_3_MATLAB_MASK    ((u32)0xFFFF0000)
#define MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_SCALE_A_HELTF_R_3_MATLAB_LSB    16
#define MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_SCALE_A_HELTF_R_3_MATLAB_WIDTH    ((u32)0x00000010)
#define MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_SCALE_A_HELTF_R_2_MATLAB_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_SCALE_A_HELTF_R_2_MATLAB_LSB    0
#define MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_SCALE_A_HELTF_R_2_MATLAB_WIDTH    ((u32)0x00000010)

#define MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_SCALE_A_HELTF_R_3_MATLAB_RST    0x0
#define MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_SCALE_A_HELTF_R_2_MATLAB_RST    0x0

static inline void macdsp_api_scale_a_heltf_r_23_from_matlab_pack(struct cl_chip *chip, u16 scale_a_heltf_r3_matlab, u16 scale_a_heltf_r2_matlab)
{
	ASSERT_ERR_CHIP((((u32)scale_a_heltf_r3_matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)scale_a_heltf_r2_matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR, ((u32)scale_a_heltf_r3_matlab << 16) | ((u32)scale_a_heltf_r2_matlab << 0));
}

static inline void macdsp_api_scale_a_heltf_r_23_from_matlab_unpack(struct cl_chip *chip, u16 *scale_a_heltf_r3_matlab, u16 *scale_a_heltf_r2_matlab)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR);

	*scale_a_heltf_r3_matlab = (local_val & ((u32)0xFFFF0000)) >> 16;
	*scale_a_heltf_r2_matlab = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_scale_a_heltf_r_23_from_matlab_scale_a_heltf_r_3_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0xFFFF0000)) >> 16);
}

static inline void macdsp_api_scale_a_heltf_r_23_from_matlab_scale_a_heltf_r_3_matlab_setf(struct cl_chip *chip, u16 scaleaheltfr3matlab)
{
	ASSERT_ERR_CHIP((((u32)scaleaheltfr3matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR) & ~((u32)0xFFFF0000)) | ((u32)scaleaheltfr3matlab << 16));
}

static inline u16 macdsp_api_scale_a_heltf_r_23_from_matlab_scale_a_heltf_r_2_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_scale_a_heltf_r_23_from_matlab_scale_a_heltf_r_2_matlab_setf(struct cl_chip *chip, u16 scaleaheltfr2matlab)
{
	ASSERT_ERR_CHIP((((u32)scaleaheltfr2matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_23_FROM_MATLAB_ADDR) & ~((u32)0x0000FFFF)) | ((u32)scaleaheltfr2matlab << 0));
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
#define MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000808)
#define MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_OFFSET      0x00000808
#define MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_INDEX       0x00000202
#define MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_RESET       0x00000000

static inline u32 macdsp_api_scale_a_heltf_r_45_from_matlab_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR);
}

static inline void macdsp_api_scale_a_heltf_r_45_from_matlab_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_SCALE_A_HELTF_R_5_MATLAB_MASK    ((u32)0xFFFF0000)
#define MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_SCALE_A_HELTF_R_5_MATLAB_LSB    16
#define MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_SCALE_A_HELTF_R_5_MATLAB_WIDTH    ((u32)0x00000010)
#define MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_SCALE_A_HELTF_R_4_MATLAB_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_SCALE_A_HELTF_R_4_MATLAB_LSB    0
#define MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_SCALE_A_HELTF_R_4_MATLAB_WIDTH    ((u32)0x00000010)

#define MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_SCALE_A_HELTF_R_5_MATLAB_RST    0x0
#define MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_SCALE_A_HELTF_R_4_MATLAB_RST    0x0

static inline void macdsp_api_scale_a_heltf_r_45_from_matlab_pack(struct cl_chip *chip, u16 scale_a_heltf_r5_matlab, u16 scale_a_heltf_r4_matlab)
{
	ASSERT_ERR_CHIP((((u32)scale_a_heltf_r5_matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)scale_a_heltf_r4_matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR, ((u32)scale_a_heltf_r5_matlab << 16) | ((u32)scale_a_heltf_r4_matlab << 0));
}

static inline void macdsp_api_scale_a_heltf_r_45_from_matlab_unpack(struct cl_chip *chip, u16 *scale_a_heltf_r5_matlab, u16 *scale_a_heltf_r4_matlab)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR);

	*scale_a_heltf_r5_matlab = (local_val & ((u32)0xFFFF0000)) >> 16;
	*scale_a_heltf_r4_matlab = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_scale_a_heltf_r_45_from_matlab_scale_a_heltf_r_5_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0xFFFF0000)) >> 16);
}

static inline void macdsp_api_scale_a_heltf_r_45_from_matlab_scale_a_heltf_r_5_matlab_setf(struct cl_chip *chip, u16 scaleaheltfr5matlab)
{
	ASSERT_ERR_CHIP((((u32)scaleaheltfr5matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR) & ~((u32)0xFFFF0000)) | ((u32)scaleaheltfr5matlab << 16));
}

static inline u16 macdsp_api_scale_a_heltf_r_45_from_matlab_scale_a_heltf_r_4_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_scale_a_heltf_r_45_from_matlab_scale_a_heltf_r_4_matlab_setf(struct cl_chip *chip, u16 scaleaheltfr4matlab)
{
	ASSERT_ERR_CHIP((((u32)scaleaheltfr4matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_45_FROM_MATLAB_ADDR) & ~((u32)0x0000FFFF)) | ((u32)scaleaheltfr4matlab << 0));
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
#define MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000080C)
#define MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_OFFSET      0x0000080C
#define MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_INDEX       0x00000203
#define MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_RESET       0x00000000

static inline u32 macdsp_api_scale_a_heltf_r_67_from_matlab_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR);
}

static inline void macdsp_api_scale_a_heltf_r_67_from_matlab_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_SCALE_A_HELTF_R_7_MATLAB_MASK    ((u32)0xFFFF0000)
#define MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_SCALE_A_HELTF_R_7_MATLAB_LSB    16
#define MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_SCALE_A_HELTF_R_7_MATLAB_WIDTH    ((u32)0x00000010)
#define MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_SCALE_A_HELTF_R_6_MATLAB_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_SCALE_A_HELTF_R_6_MATLAB_LSB    0
#define MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_SCALE_A_HELTF_R_6_MATLAB_WIDTH    ((u32)0x00000010)

#define MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_SCALE_A_HELTF_R_7_MATLAB_RST    0x0
#define MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_SCALE_A_HELTF_R_6_MATLAB_RST    0x0

static inline void macdsp_api_scale_a_heltf_r_67_from_matlab_pack(struct cl_chip *chip, u16 scale_a_heltf_r7_matlab, u16 scale_a_heltf_r6_matlab)
{
	ASSERT_ERR_CHIP((((u32)scale_a_heltf_r7_matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)scale_a_heltf_r6_matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR, ((u32)scale_a_heltf_r7_matlab << 16) | ((u32)scale_a_heltf_r6_matlab << 0));
}

static inline void macdsp_api_scale_a_heltf_r_67_from_matlab_unpack(struct cl_chip *chip, u16 *scale_a_heltf_r7_matlab, u16 *scale_a_heltf_r6_matlab)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR);

	*scale_a_heltf_r7_matlab = (local_val & ((u32)0xFFFF0000)) >> 16;
	*scale_a_heltf_r6_matlab = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_scale_a_heltf_r_67_from_matlab_scale_a_heltf_r_7_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0xFFFF0000)) >> 16);
}

static inline void macdsp_api_scale_a_heltf_r_67_from_matlab_scale_a_heltf_r_7_matlab_setf(struct cl_chip *chip, u16 scaleaheltfr7matlab)
{
	ASSERT_ERR_CHIP((((u32)scaleaheltfr7matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR) & ~((u32)0xFFFF0000)) | ((u32)scaleaheltfr7matlab << 16));
}

static inline u16 macdsp_api_scale_a_heltf_r_67_from_matlab_scale_a_heltf_r_6_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_scale_a_heltf_r_67_from_matlab_scale_a_heltf_r_6_matlab_setf(struct cl_chip *chip, u16 scaleaheltfr6matlab)
{
	ASSERT_ERR_CHIP((((u32)scaleaheltfr6matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_A_HELTF_R_67_FROM_MATLAB_ADDR) & ~((u32)0x0000FFFF)) | ((u32)scaleaheltfr6matlab << 0));
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
#define MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000810)
#define MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_OFFSET      0x00000810
#define MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_INDEX       0x00000204
#define MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_RESET       0x00000000

static inline u32 macdsp_api_scale_a_hestf_r_01_from_matlab_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR);
}

static inline void macdsp_api_scale_a_hestf_r_01_from_matlab_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_SCALE_A_HESTF_R_1_MATLAB_MASK    ((u32)0xFFFF0000)
#define MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_SCALE_A_HESTF_R_1_MATLAB_LSB    16
#define MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_SCALE_A_HESTF_R_1_MATLAB_WIDTH    ((u32)0x00000010)
#define MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_SCALE_A_HESTF_R_0_MATLAB_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_SCALE_A_HESTF_R_0_MATLAB_LSB    0
#define MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_SCALE_A_HESTF_R_0_MATLAB_WIDTH    ((u32)0x00000010)

#define MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_SCALE_A_HESTF_R_1_MATLAB_RST    0x0
#define MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_SCALE_A_HESTF_R_0_MATLAB_RST    0x0

static inline void macdsp_api_scale_a_hestf_r_01_from_matlab_pack(struct cl_chip *chip, u16 scale_a_hestf_r1_matlab, u16 scale_a_hestf_r0_matlab)
{
	ASSERT_ERR_CHIP((((u32)scale_a_hestf_r1_matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)scale_a_hestf_r0_matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR, ((u32)scale_a_hestf_r1_matlab << 16) | ((u32)scale_a_hestf_r0_matlab << 0));
}

static inline void macdsp_api_scale_a_hestf_r_01_from_matlab_unpack(struct cl_chip *chip, u16 *scale_a_hestf_r1_matlab, u16 *scale_a_hestf_r0_matlab)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR);

	*scale_a_hestf_r1_matlab = (local_val & ((u32)0xFFFF0000)) >> 16;
	*scale_a_hestf_r0_matlab = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_scale_a_hestf_r_01_from_matlab_scale_a_hestf_r_1_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0xFFFF0000)) >> 16);
}

static inline void macdsp_api_scale_a_hestf_r_01_from_matlab_scale_a_hestf_r_1_matlab_setf(struct cl_chip *chip, u16 scaleahestfr1matlab)
{
	ASSERT_ERR_CHIP((((u32)scaleahestfr1matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR) & ~((u32)0xFFFF0000)) | ((u32)scaleahestfr1matlab << 16));
}

static inline u16 macdsp_api_scale_a_hestf_r_01_from_matlab_scale_a_hestf_r_0_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_scale_a_hestf_r_01_from_matlab_scale_a_hestf_r_0_matlab_setf(struct cl_chip *chip, u16 scaleahestfr0matlab)
{
	ASSERT_ERR_CHIP((((u32)scaleahestfr0matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_01_FROM_MATLAB_ADDR) & ~((u32)0x0000FFFF)) | ((u32)scaleahestfr0matlab << 0));
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
#define MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000814)
#define MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_OFFSET      0x00000814
#define MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_INDEX       0x00000205
#define MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_RESET       0x00000000

static inline u32 macdsp_api_scale_a_hestf_r_23_from_matlab_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR);
}

static inline void macdsp_api_scale_a_hestf_r_23_from_matlab_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_SCALE_A_HESTF_R_3_MATLAB_MASK    ((u32)0xFFFF0000)
#define MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_SCALE_A_HESTF_R_3_MATLAB_LSB    16
#define MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_SCALE_A_HESTF_R_3_MATLAB_WIDTH    ((u32)0x00000010)
#define MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_SCALE_A_HESTF_R_2_MATLAB_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_SCALE_A_HESTF_R_2_MATLAB_LSB    0
#define MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_SCALE_A_HESTF_R_2_MATLAB_WIDTH    ((u32)0x00000010)

#define MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_SCALE_A_HESTF_R_3_MATLAB_RST    0x0
#define MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_SCALE_A_HESTF_R_2_MATLAB_RST    0x0

static inline void macdsp_api_scale_a_hestf_r_23_from_matlab_pack(struct cl_chip *chip, u16 scale_a_hestf_r3_matlab, u16 scale_a_hestf_r2_matlab)
{
	ASSERT_ERR_CHIP((((u32)scale_a_hestf_r3_matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)scale_a_hestf_r2_matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR, ((u32)scale_a_hestf_r3_matlab << 16) | ((u32)scale_a_hestf_r2_matlab << 0));
}

static inline void macdsp_api_scale_a_hestf_r_23_from_matlab_unpack(struct cl_chip *chip, u16 *scale_a_hestf_r3_matlab, u16 *scale_a_hestf_r2_matlab)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR);

	*scale_a_hestf_r3_matlab = (local_val & ((u32)0xFFFF0000)) >> 16;
	*scale_a_hestf_r2_matlab = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_scale_a_hestf_r_23_from_matlab_scale_a_hestf_r_3_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0xFFFF0000)) >> 16);
}

static inline void macdsp_api_scale_a_hestf_r_23_from_matlab_scale_a_hestf_r_3_matlab_setf(struct cl_chip *chip, u16 scaleahestfr3matlab)
{
	ASSERT_ERR_CHIP((((u32)scaleahestfr3matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR) & ~((u32)0xFFFF0000)) | ((u32)scaleahestfr3matlab << 16));
}

static inline u16 macdsp_api_scale_a_hestf_r_23_from_matlab_scale_a_hestf_r_2_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_scale_a_hestf_r_23_from_matlab_scale_a_hestf_r_2_matlab_setf(struct cl_chip *chip, u16 scaleahestfr2matlab)
{
	ASSERT_ERR_CHIP((((u32)scaleahestfr2matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_23_FROM_MATLAB_ADDR) & ~((u32)0x0000FFFF)) | ((u32)scaleahestfr2matlab << 0));
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
#define MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000818)
#define MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_OFFSET      0x00000818
#define MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_INDEX       0x00000206
#define MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_RESET       0x00000000

static inline u32 macdsp_api_scale_a_hestf_r_45_from_matlab_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR);
}

static inline void macdsp_api_scale_a_hestf_r_45_from_matlab_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_SCALE_A_HESTF_R_5_MATLAB_MASK    ((u32)0xFFFF0000)
#define MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_SCALE_A_HESTF_R_5_MATLAB_LSB    16
#define MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_SCALE_A_HESTF_R_5_MATLAB_WIDTH    ((u32)0x00000010)
#define MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_SCALE_A_HESTF_R_4_MATLAB_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_SCALE_A_HESTF_R_4_MATLAB_LSB    0
#define MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_SCALE_A_HESTF_R_4_MATLAB_WIDTH    ((u32)0x00000010)

#define MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_SCALE_A_HESTF_R_5_MATLAB_RST    0x0
#define MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_SCALE_A_HESTF_R_4_MATLAB_RST    0x0

static inline void macdsp_api_scale_a_hestf_r_45_from_matlab_pack(struct cl_chip *chip, u16 scale_a_hestf_r5_matlab, u16 scale_a_hestf_r4_matlab)
{
	ASSERT_ERR_CHIP((((u32)scale_a_hestf_r5_matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)scale_a_hestf_r4_matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR, ((u32)scale_a_hestf_r5_matlab << 16) | ((u32)scale_a_hestf_r4_matlab << 0));
}

static inline void macdsp_api_scale_a_hestf_r_45_from_matlab_unpack(struct cl_chip *chip, u16 *scale_a_hestf_r5_matlab, u16 *scale_a_hestf_r4_matlab)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR);

	*scale_a_hestf_r5_matlab = (local_val & ((u32)0xFFFF0000)) >> 16;
	*scale_a_hestf_r4_matlab = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_scale_a_hestf_r_45_from_matlab_scale_a_hestf_r_5_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0xFFFF0000)) >> 16);
}

static inline void macdsp_api_scale_a_hestf_r_45_from_matlab_scale_a_hestf_r_5_matlab_setf(struct cl_chip *chip, u16 scaleahestfr5matlab)
{
	ASSERT_ERR_CHIP((((u32)scaleahestfr5matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR) & ~((u32)0xFFFF0000)) | ((u32)scaleahestfr5matlab << 16));
}

static inline u16 macdsp_api_scale_a_hestf_r_45_from_matlab_scale_a_hestf_r_4_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_scale_a_hestf_r_45_from_matlab_scale_a_hestf_r_4_matlab_setf(struct cl_chip *chip, u16 scaleahestfr4matlab)
{
	ASSERT_ERR_CHIP((((u32)scaleahestfr4matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_45_FROM_MATLAB_ADDR) & ~((u32)0x0000FFFF)) | ((u32)scaleahestfr4matlab << 0));
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
#define MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000081C)
#define MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_OFFSET      0x0000081C
#define MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_INDEX       0x00000207
#define MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_RESET       0x00000000

static inline u32 macdsp_api_scale_a_hestf_r_67_from_matlab_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR);
}

static inline void macdsp_api_scale_a_hestf_r_67_from_matlab_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_SCALE_A_HESTF_R_7_MATLAB_MASK    ((u32)0xFFFF0000)
#define MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_SCALE_A_HESTF_R_7_MATLAB_LSB    16
#define MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_SCALE_A_HESTF_R_7_MATLAB_WIDTH    ((u32)0x00000010)
#define MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_SCALE_A_HESTF_R_6_MATLAB_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_SCALE_A_HESTF_R_6_MATLAB_LSB    0
#define MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_SCALE_A_HESTF_R_6_MATLAB_WIDTH    ((u32)0x00000010)

#define MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_SCALE_A_HESTF_R_7_MATLAB_RST    0x0
#define MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_SCALE_A_HESTF_R_6_MATLAB_RST    0x0

static inline void macdsp_api_scale_a_hestf_r_67_from_matlab_pack(struct cl_chip *chip, u16 scale_a_hestf_r7_matlab, u16 scale_a_hestf_r6_matlab)
{
	ASSERT_ERR_CHIP((((u32)scale_a_hestf_r7_matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)scale_a_hestf_r6_matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR, ((u32)scale_a_hestf_r7_matlab << 16) | ((u32)scale_a_hestf_r6_matlab << 0));
}

static inline void macdsp_api_scale_a_hestf_r_67_from_matlab_unpack(struct cl_chip *chip, u16 *scale_a_hestf_r7_matlab, u16 *scale_a_hestf_r6_matlab)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR);

	*scale_a_hestf_r7_matlab = (local_val & ((u32)0xFFFF0000)) >> 16;
	*scale_a_hestf_r6_matlab = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_scale_a_hestf_r_67_from_matlab_scale_a_hestf_r_7_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0xFFFF0000)) >> 16);
}

static inline void macdsp_api_scale_a_hestf_r_67_from_matlab_scale_a_hestf_r_7_matlab_setf(struct cl_chip *chip, u16 scaleahestfr7matlab)
{
	ASSERT_ERR_CHIP((((u32)scaleahestfr7matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR) & ~((u32)0xFFFF0000)) | ((u32)scaleahestfr7matlab << 16));
}

static inline u16 macdsp_api_scale_a_hestf_r_67_from_matlab_scale_a_hestf_r_6_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_scale_a_hestf_r_67_from_matlab_scale_a_hestf_r_6_matlab_setf(struct cl_chip *chip, u16 scaleahestfr6matlab)
{
	ASSERT_ERR_CHIP((((u32)scaleahestfr6matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_A_HESTF_R_67_FROM_MATLAB_ADDR) & ~((u32)0x0000FFFF)) | ((u32)scaleahestfr6matlab << 0));
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
#define MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000820)
#define MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_OFFSET      0x00000820
#define MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_INDEX       0x00000208
#define MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_RESET       0x00000000

static inline u32 macdsp_api_scale_alpha_r_01_from_matlab_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR);
}

static inline void macdsp_api_scale_alpha_r_01_from_matlab_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_SCALE_ALPHA_R_1_MATLAB_MASK    ((u32)0xFFFF0000)
#define MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_SCALE_ALPHA_R_1_MATLAB_LSB    16
#define MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_SCALE_ALPHA_R_1_MATLAB_WIDTH    ((u32)0x00000010)
#define MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_SCALE_ALPHA_R_0_MATLAB_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_SCALE_ALPHA_R_0_MATLAB_LSB    0
#define MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_SCALE_ALPHA_R_0_MATLAB_WIDTH    ((u32)0x00000010)

#define MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_SCALE_ALPHA_R_1_MATLAB_RST    0x0
#define MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_SCALE_ALPHA_R_0_MATLAB_RST    0x0

static inline void macdsp_api_scale_alpha_r_01_from_matlab_pack(struct cl_chip *chip, u16 scale_alpha_r1_matlab, u16 scale_alpha_r0_matlab)
{
	ASSERT_ERR_CHIP((((u32)scale_alpha_r1_matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)scale_alpha_r0_matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR, ((u32)scale_alpha_r1_matlab << 16) | ((u32)scale_alpha_r0_matlab << 0));
}

static inline void macdsp_api_scale_alpha_r_01_from_matlab_unpack(struct cl_chip *chip, u16 *scale_alpha_r1_matlab, u16 *scale_alpha_r0_matlab)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR);

	*scale_alpha_r1_matlab = (local_val & ((u32)0xFFFF0000)) >> 16;
	*scale_alpha_r0_matlab = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_scale_alpha_r_01_from_matlab_scale_alpha_r_1_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0xFFFF0000)) >> 16);
}

static inline void macdsp_api_scale_alpha_r_01_from_matlab_scale_alpha_r_1_matlab_setf(struct cl_chip *chip, u16 scalealphar1matlab)
{
	ASSERT_ERR_CHIP((((u32)scalealphar1matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR) & ~((u32)0xFFFF0000)) | ((u32)scalealphar1matlab << 16));
}

static inline u16 macdsp_api_scale_alpha_r_01_from_matlab_scale_alpha_r_0_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_scale_alpha_r_01_from_matlab_scale_alpha_r_0_matlab_setf(struct cl_chip *chip, u16 scalealphar0matlab)
{
	ASSERT_ERR_CHIP((((u32)scalealphar0matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_01_FROM_MATLAB_ADDR) & ~((u32)0x0000FFFF)) | ((u32)scalealphar0matlab << 0));
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
#define MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000824)
#define MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_OFFSET      0x00000824
#define MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_INDEX       0x00000209
#define MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_RESET       0x00000000

static inline u32 macdsp_api_scale_alpha_r_23_from_matlab_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR);
}

static inline void macdsp_api_scale_alpha_r_23_from_matlab_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_SCALE_ALPHA_R_3_MATLAB_MASK    ((u32)0xFFFF0000)
#define MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_SCALE_ALPHA_R_3_MATLAB_LSB    16
#define MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_SCALE_ALPHA_R_3_MATLAB_WIDTH    ((u32)0x00000010)
#define MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_SCALE_ALPHA_R_2_MATLAB_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_SCALE_ALPHA_R_2_MATLAB_LSB    0
#define MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_SCALE_ALPHA_R_2_MATLAB_WIDTH    ((u32)0x00000010)

#define MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_SCALE_ALPHA_R_3_MATLAB_RST    0x0
#define MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_SCALE_ALPHA_R_2_MATLAB_RST    0x0

static inline void macdsp_api_scale_alpha_r_23_from_matlab_pack(struct cl_chip *chip, u16 scale_alpha_r3_matlab, u16 scale_alpha_r2_matlab)
{
	ASSERT_ERR_CHIP((((u32)scale_alpha_r3_matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)scale_alpha_r2_matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR, ((u32)scale_alpha_r3_matlab << 16) | ((u32)scale_alpha_r2_matlab << 0));
}

static inline void macdsp_api_scale_alpha_r_23_from_matlab_unpack(struct cl_chip *chip, u16 *scale_alpha_r3_matlab, u16 *scale_alpha_r2_matlab)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR);

	*scale_alpha_r3_matlab = (local_val & ((u32)0xFFFF0000)) >> 16;
	*scale_alpha_r2_matlab = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_scale_alpha_r_23_from_matlab_scale_alpha_r_3_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0xFFFF0000)) >> 16);
}

static inline void macdsp_api_scale_alpha_r_23_from_matlab_scale_alpha_r_3_matlab_setf(struct cl_chip *chip, u16 scalealphar3matlab)
{
	ASSERT_ERR_CHIP((((u32)scalealphar3matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR) & ~((u32)0xFFFF0000)) | ((u32)scalealphar3matlab << 16));
}

static inline u16 macdsp_api_scale_alpha_r_23_from_matlab_scale_alpha_r_2_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_scale_alpha_r_23_from_matlab_scale_alpha_r_2_matlab_setf(struct cl_chip *chip, u16 scalealphar2matlab)
{
	ASSERT_ERR_CHIP((((u32)scalealphar2matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_23_FROM_MATLAB_ADDR) & ~((u32)0x0000FFFF)) | ((u32)scalealphar2matlab << 0));
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
#define MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000828)
#define MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_OFFSET      0x00000828
#define MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_INDEX       0x0000020A
#define MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_RESET       0x00000000

static inline u32 macdsp_api_scale_alpha_r_45_from_matlab_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR);
}

static inline void macdsp_api_scale_alpha_r_45_from_matlab_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_SCALE_ALPHA_R_5_MATLAB_MASK    ((u32)0xFFFF0000)
#define MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_SCALE_ALPHA_R_5_MATLAB_LSB    16
#define MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_SCALE_ALPHA_R_5_MATLAB_WIDTH    ((u32)0x00000010)
#define MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_SCALE_ALPHA_R_4_MATLAB_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_SCALE_ALPHA_R_4_MATLAB_LSB    0
#define MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_SCALE_ALPHA_R_4_MATLAB_WIDTH    ((u32)0x00000010)

#define MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_SCALE_ALPHA_R_5_MATLAB_RST    0x0
#define MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_SCALE_ALPHA_R_4_MATLAB_RST    0x0

static inline void macdsp_api_scale_alpha_r_45_from_matlab_pack(struct cl_chip *chip, u16 scale_alpha_r5_matlab, u16 scale_alpha_r4_matlab)
{
	ASSERT_ERR_CHIP((((u32)scale_alpha_r5_matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)scale_alpha_r4_matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR, ((u32)scale_alpha_r5_matlab << 16) | ((u32)scale_alpha_r4_matlab << 0));
}

static inline void macdsp_api_scale_alpha_r_45_from_matlab_unpack(struct cl_chip *chip, u16 *scale_alpha_r5_matlab, u16 *scale_alpha_r4_matlab)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR);

	*scale_alpha_r5_matlab = (local_val & ((u32)0xFFFF0000)) >> 16;
	*scale_alpha_r4_matlab = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_scale_alpha_r_45_from_matlab_scale_alpha_r_5_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0xFFFF0000)) >> 16);
}

static inline void macdsp_api_scale_alpha_r_45_from_matlab_scale_alpha_r_5_matlab_setf(struct cl_chip *chip, u16 scalealphar5matlab)
{
	ASSERT_ERR_CHIP((((u32)scalealphar5matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR) & ~((u32)0xFFFF0000)) | ((u32)scalealphar5matlab << 16));
}

static inline u16 macdsp_api_scale_alpha_r_45_from_matlab_scale_alpha_r_4_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_scale_alpha_r_45_from_matlab_scale_alpha_r_4_matlab_setf(struct cl_chip *chip, u16 scalealphar4matlab)
{
	ASSERT_ERR_CHIP((((u32)scalealphar4matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_45_FROM_MATLAB_ADDR) & ~((u32)0x0000FFFF)) | ((u32)scalealphar4matlab << 0));
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
#define MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000082C)
#define MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_OFFSET      0x0000082C
#define MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_INDEX       0x0000020B
#define MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_RESET       0x00000000

static inline u32 macdsp_api_scale_alpha_r_67_from_matlab_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR);
}

static inline void macdsp_api_scale_alpha_r_67_from_matlab_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_SCALE_ALPHA_R_7_MATLAB_MASK    ((u32)0xFFFF0000)
#define MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_SCALE_ALPHA_R_7_MATLAB_LSB    16
#define MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_SCALE_ALPHA_R_7_MATLAB_WIDTH    ((u32)0x00000010)
#define MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_SCALE_ALPHA_R_6_MATLAB_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_SCALE_ALPHA_R_6_MATLAB_LSB    0
#define MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_SCALE_ALPHA_R_6_MATLAB_WIDTH    ((u32)0x00000010)

#define MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_SCALE_ALPHA_R_7_MATLAB_RST    0x0
#define MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_SCALE_ALPHA_R_6_MATLAB_RST    0x0

static inline void macdsp_api_scale_alpha_r_67_from_matlab_pack(struct cl_chip *chip, u16 scale_alpha_r7_matlab, u16 scale_alpha_r6_matlab)
{
	ASSERT_ERR_CHIP((((u32)scale_alpha_r7_matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)scale_alpha_r6_matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR, ((u32)scale_alpha_r7_matlab << 16) | ((u32)scale_alpha_r6_matlab << 0));
}

static inline void macdsp_api_scale_alpha_r_67_from_matlab_unpack(struct cl_chip *chip, u16 *scale_alpha_r7_matlab, u16 *scale_alpha_r6_matlab)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR);

	*scale_alpha_r7_matlab = (local_val & ((u32)0xFFFF0000)) >> 16;
	*scale_alpha_r6_matlab = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_scale_alpha_r_67_from_matlab_scale_alpha_r_7_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0xFFFF0000)) >> 16);
}

static inline void macdsp_api_scale_alpha_r_67_from_matlab_scale_alpha_r_7_matlab_setf(struct cl_chip *chip, u16 scalealphar7matlab)
{
	ASSERT_ERR_CHIP((((u32)scalealphar7matlab << 16) & ~((u32)0xFFFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR) & ~((u32)0xFFFF0000)) | ((u32)scalealphar7matlab << 16));
}

static inline u16 macdsp_api_scale_alpha_r_67_from_matlab_scale_alpha_r_6_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_scale_alpha_r_67_from_matlab_scale_alpha_r_6_matlab_setf(struct cl_chip *chip, u16 scalealphar6matlab)
{
	ASSERT_ERR_CHIP((((u32)scalealphar6matlab << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_SCALE_ALPHA_R_67_FROM_MATLAB_ADDR) & ~((u32)0x0000FFFF)) | ((u32)scalealphar6matlab << 0));
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
#define MACDSP_API_RXTIME_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000830)
#define MACDSP_API_RXTIME_OFFSET      0x00000830
#define MACDSP_API_RXTIME_INDEX       0x0000020C
#define MACDSP_API_RXTIME_RESET       0x00000000

static inline u32 macdsp_api_rxtime_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RXTIME_ADDR);
}

static inline void macdsp_api_rxtime_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RXTIME_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RXTIME_RX_TIME_MASK      ((u32)0xFFFFFFFF)
#define MACDSP_API_RXTIME_RX_TIME_LSB       0
#define MACDSP_API_RXTIME_RX_TIME_WIDTH     ((u32)0x00000020)

#define MACDSP_API_RXTIME_RX_TIME_RST       0x0

static inline u32 macdsp_api_rxtime_rx_time_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RXTIME_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_rxtime_rx_time_setf(struct cl_chip *chip, u32 rxtime)
{
	ASSERT_ERR_CHIP((((u32)rxtime << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RXTIME_ADDR, (u32)rxtime << 0);
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
#define MACDSP_API_RX_NUM_DATA_SYM_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000834)
#define MACDSP_API_RX_NUM_DATA_SYM_OFFSET      0x00000834
#define MACDSP_API_RX_NUM_DATA_SYM_INDEX       0x0000020D
#define MACDSP_API_RX_NUM_DATA_SYM_RESET       0x00000000

static inline u32 macdsp_api_rx_num_data_sym_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_NUM_DATA_SYM_ADDR);
}

static inline void macdsp_api_rx_num_data_sym_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_NUM_DATA_SYM_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_NUM_DATA_SYM_RX_NUM_DATA_SYM_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_RX_NUM_DATA_SYM_RX_NUM_DATA_SYM_LSB    0
#define MACDSP_API_RX_NUM_DATA_SYM_RX_NUM_DATA_SYM_WIDTH    ((u32)0x00000020)

#define MACDSP_API_RX_NUM_DATA_SYM_RX_NUM_DATA_SYM_RST    0x0

static inline u32 macdsp_api_rx_num_data_sym_rx_num_data_sym_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_NUM_DATA_SYM_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_rx_num_data_sym_rx_num_data_sym_setf(struct cl_chip *chip, u32 rxnumdatasym)
{
	ASSERT_ERR_CHIP((((u32)rxnumdatasym << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_NUM_DATA_SYM_ADDR, (u32)rxnumdatasym << 0);
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
#define MACDSP_API_RX_HTSFT_START_EST_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000838)
#define MACDSP_API_RX_HTSFT_START_EST_OFFSET      0x00000838
#define MACDSP_API_RX_HTSFT_START_EST_INDEX       0x0000020E
#define MACDSP_API_RX_HTSFT_START_EST_RESET       0x00000000

static inline u32 macdsp_api_rx_htsft_start_est_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_HTSFT_START_EST_ADDR);
}

static inline void macdsp_api_rx_htsft_start_est_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_HTSFT_START_EST_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_HTSFT_START_EST_RX_HTSFT_START_EST_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_RX_HTSFT_START_EST_RX_HTSFT_START_EST_LSB    0
#define MACDSP_API_RX_HTSFT_START_EST_RX_HTSFT_START_EST_WIDTH    ((u32)0x00000020)

#define MACDSP_API_RX_HTSFT_START_EST_RX_HTSFT_START_EST_RST    0x0

static inline u32 macdsp_api_rx_htsft_start_est_rx_htsft_start_est_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_HTSFT_START_EST_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_rx_htsft_start_est_rx_htsft_start_est_setf(struct cl_chip *chip, u32 rxhtsftstartest)
{
	ASSERT_ERR_CHIP((((u32)rxhtsftstartest << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_HTSFT_START_EST_ADDR, (u32)rxhtsftstartest << 0);
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
#define MACDSP_API_RX_HTSTF_GAIN_UPDATE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000083C)
#define MACDSP_API_RX_HTSTF_GAIN_UPDATE_OFFSET      0x0000083C
#define MACDSP_API_RX_HTSTF_GAIN_UPDATE_INDEX       0x0000020F
#define MACDSP_API_RX_HTSTF_GAIN_UPDATE_RESET       0x00000000

static inline u32 macdsp_api_rx_htstf_gain_update_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_HTSTF_GAIN_UPDATE_ADDR);
}

static inline void macdsp_api_rx_htstf_gain_update_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_HTSTF_GAIN_UPDATE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_HTSTF_GAIN_UPDATE_RX_HTSTF_GAIN_UPDATE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_RX_HTSTF_GAIN_UPDATE_RX_HTSTF_GAIN_UPDATE_LSB    0
#define MACDSP_API_RX_HTSTF_GAIN_UPDATE_RX_HTSTF_GAIN_UPDATE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_RX_HTSTF_GAIN_UPDATE_RX_HTSTF_GAIN_UPDATE_RST    0x0

static inline u32 macdsp_api_rx_htstf_gain_update_rx_htstf_gain_update_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_HTSTF_GAIN_UPDATE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_rx_htstf_gain_update_rx_htstf_gain_update_setf(struct cl_chip *chip, u32 rxhtstfgainupdate)
{
	ASSERT_ERR_CHIP((((u32)rxhtstfgainupdate << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_HTSTF_GAIN_UPDATE_ADDR, (u32)rxhtstfgainupdate << 0);
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
#define MACDSP_API_TXTIME_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000840)
#define MACDSP_API_TXTIME_OFFSET      0x00000840
#define MACDSP_API_TXTIME_INDEX       0x00000210
#define MACDSP_API_TXTIME_RESET       0x00000000

static inline u32 macdsp_api_txtime_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TXTIME_ADDR);
}

static inline void macdsp_api_txtime_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TXTIME_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TXTIME_TXTIME_MASK       ((u32)0xFFFFFFFF)
#define MACDSP_API_TXTIME_TXTIME_LSB        0
#define MACDSP_API_TXTIME_TXTIME_WIDTH      ((u32)0x00000020)

#define MACDSP_API_TXTIME_TXTIME_RST        0x0

static inline u32 macdsp_api_txtime_txtime_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TXTIME_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_txtime_txtime_setf(struct cl_chip *chip, u32 txtime)
{
	ASSERT_ERR_CHIP((((u32)txtime << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TXTIME_ADDR, (u32)txtime << 0);
}

/**
 * @brief CPE_STO_COMMON_INFO register definition
 *  CPE/STO automation common info register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31    reset_db_bit              0
 *    30:16 num_data_symbols          0x0
 *    15:12 he_ltf_type               0x0
 *    11:08 num_he_ltfs               0x0
 *    07:04 ru_type                   0x0
 *    03:02 GIType                    0x0
 *    01:00 Frame_BW                  0x0
 * </pre>
 */
#define MACDSP_API_CPE_STO_COMMON_INFO_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000844)
#define MACDSP_API_CPE_STO_COMMON_INFO_OFFSET      0x00000844
#define MACDSP_API_CPE_STO_COMMON_INFO_INDEX       0x00000211
#define MACDSP_API_CPE_STO_COMMON_INFO_RESET       0x00000000

static inline u32 macdsp_api_cpe_sto_common_info_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR);
}

static inline void macdsp_api_cpe_sto_common_info_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_CPE_STO_COMMON_INFO_RESET_DB_BIT_BIT    ((u32)0x80000000)
#define MACDSP_API_CPE_STO_COMMON_INFO_RESET_DB_BIT_POS    31
#define MACDSP_API_CPE_STO_COMMON_INFO_NUM_DATA_SYMBOLS_MASK    ((u32)0x7FFF0000)
#define MACDSP_API_CPE_STO_COMMON_INFO_NUM_DATA_SYMBOLS_LSB    16
#define MACDSP_API_CPE_STO_COMMON_INFO_NUM_DATA_SYMBOLS_WIDTH    ((u32)0x0000000F)
#define MACDSP_API_CPE_STO_COMMON_INFO_HE_LTF_TYPE_MASK    ((u32)0x0000F000)
#define MACDSP_API_CPE_STO_COMMON_INFO_HE_LTF_TYPE_LSB    12
#define MACDSP_API_CPE_STO_COMMON_INFO_HE_LTF_TYPE_WIDTH    ((u32)0x00000004)
#define MACDSP_API_CPE_STO_COMMON_INFO_NUM_HE_LTFS_MASK    ((u32)0x00000F00)
#define MACDSP_API_CPE_STO_COMMON_INFO_NUM_HE_LTFS_LSB    8
#define MACDSP_API_CPE_STO_COMMON_INFO_NUM_HE_LTFS_WIDTH    ((u32)0x00000004)
#define MACDSP_API_CPE_STO_COMMON_INFO_RU_TYPE_MASK    ((u32)0x000000F0)
#define MACDSP_API_CPE_STO_COMMON_INFO_RU_TYPE_LSB    4
#define MACDSP_API_CPE_STO_COMMON_INFO_RU_TYPE_WIDTH    ((u32)0x00000004)
#define MACDSP_API_CPE_STO_COMMON_INFO_GITYPE_MASK    ((u32)0x0000000C)
#define MACDSP_API_CPE_STO_COMMON_INFO_GITYPE_LSB    2
#define MACDSP_API_CPE_STO_COMMON_INFO_GITYPE_WIDTH    ((u32)0x00000002)
#define MACDSP_API_CPE_STO_COMMON_INFO_FRAME_BW_MASK    ((u32)0x00000003)
#define MACDSP_API_CPE_STO_COMMON_INFO_FRAME_BW_LSB    0
#define MACDSP_API_CPE_STO_COMMON_INFO_FRAME_BW_WIDTH    ((u32)0x00000002)

#define MACDSP_API_CPE_STO_COMMON_INFO_RESET_DB_BIT_RST    0x0
#define MACDSP_API_CPE_STO_COMMON_INFO_NUM_DATA_SYMBOLS_RST    0x0
#define MACDSP_API_CPE_STO_COMMON_INFO_HE_LTF_TYPE_RST    0x0
#define MACDSP_API_CPE_STO_COMMON_INFO_NUM_HE_LTFS_RST    0x0
#define MACDSP_API_CPE_STO_COMMON_INFO_RU_TYPE_RST    0x0
#define MACDSP_API_CPE_STO_COMMON_INFO_GITYPE_RST    0x0
#define MACDSP_API_CPE_STO_COMMON_INFO_FRAME_BW_RST    0x0

static inline void macdsp_api_cpe_sto_common_info_pack(struct cl_chip *chip, u8 reset_db_bit, u16 num_data_symbols, u8 he_ltf_type, u8 num_he_ltfs, u8 ru_type, u8 gitype, u8 frame_bw)
{
	ASSERT_ERR_CHIP((((u32)reset_db_bit << 31) & ~((u32)0x80000000)) == 0);
	ASSERT_ERR_CHIP((((u32)num_data_symbols << 16) & ~((u32)0x7FFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)he_ltf_type << 12) & ~((u32)0x0000F000)) == 0);
	ASSERT_ERR_CHIP((((u32)num_he_ltfs << 8) & ~((u32)0x00000F00)) == 0);
	ASSERT_ERR_CHIP((((u32)ru_type << 4) & ~((u32)0x000000F0)) == 0);
	ASSERT_ERR_CHIP((((u32)gitype << 2) & ~((u32)0x0000000C)) == 0);
	ASSERT_ERR_CHIP((((u32)frame_bw << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR, ((u32)reset_db_bit << 31) | ((u32)num_data_symbols << 16) | ((u32)he_ltf_type << 12) | ((u32)num_he_ltfs << 8) | ((u32)ru_type << 4) | ((u32)gitype << 2) | ((u32)frame_bw << 0));
}

static inline void macdsp_api_cpe_sto_common_info_unpack(struct cl_chip *chip, u8 *reset_db_bit, u16 *num_data_symbols, u8 *he_ltf_type, u8 *num_he_ltfs, u8 *ru_type, u8 *gitype, u8 *frame_bw)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR);

	*reset_db_bit = (local_val & ((u32)0x80000000)) >> 31;
	*num_data_symbols = (local_val & ((u32)0x7FFF0000)) >> 16;
	*he_ltf_type = (local_val & ((u32)0x0000F000)) >> 12;
	*num_he_ltfs = (local_val & ((u32)0x00000F00)) >> 8;
	*ru_type = (local_val & ((u32)0x000000F0)) >> 4;
	*gitype = (local_val & ((u32)0x0000000C)) >> 2;
	*frame_bw = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u8 macdsp_api_cpe_sto_common_info_reset_db_bit_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR);

	return (u8)((local_val & ((u32)0x80000000)) >> 31);
}

static inline void macdsp_api_cpe_sto_common_info_reset_db_bit_setf(struct cl_chip *chip, u8 resetdbbit)
{
	ASSERT_ERR_CHIP((((u32)resetdbbit << 31) & ~((u32)0x80000000)) == 0);
	cl_reg_write(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR, (cl_reg_read(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR) & ~((u32)0x80000000)) | ((u32)resetdbbit << 31));
}

static inline u16 macdsp_api_cpe_sto_common_info_num_data_symbols_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR);

	return (u16)((local_val & ((u32)0x7FFF0000)) >> 16);
}

static inline void macdsp_api_cpe_sto_common_info_num_data_symbols_setf(struct cl_chip *chip, u16 numdatasymbols)
{
	ASSERT_ERR_CHIP((((u32)numdatasymbols << 16) & ~((u32)0x7FFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR, (cl_reg_read(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR) & ~((u32)0x7FFF0000)) | ((u32)numdatasymbols << 16));
}

static inline u8 macdsp_api_cpe_sto_common_info_he_ltf_type_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR);

	return (u8)((local_val & ((u32)0x0000F000)) >> 12);
}

static inline void macdsp_api_cpe_sto_common_info_he_ltf_type_setf(struct cl_chip *chip, u8 heltftype)
{
	ASSERT_ERR_CHIP((((u32)heltftype << 12) & ~((u32)0x0000F000)) == 0);
	cl_reg_write(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR, (cl_reg_read(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR) & ~((u32)0x0000F000)) | ((u32)heltftype << 12));
}

static inline u8 macdsp_api_cpe_sto_common_info_num_he_ltfs_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR);

	return (u8)((local_val & ((u32)0x00000F00)) >> 8);
}

static inline void macdsp_api_cpe_sto_common_info_num_he_ltfs_setf(struct cl_chip *chip, u8 numheltfs)
{
	ASSERT_ERR_CHIP((((u32)numheltfs << 8) & ~((u32)0x00000F00)) == 0);
	cl_reg_write(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR, (cl_reg_read(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR) & ~((u32)0x00000F00)) | ((u32)numheltfs << 8));
}

static inline u8 macdsp_api_cpe_sto_common_info_ru_type_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR);

	return (u8)((local_val & ((u32)0x000000F0)) >> 4);
}

static inline void macdsp_api_cpe_sto_common_info_ru_type_setf(struct cl_chip *chip, u8 rutype)
{
	ASSERT_ERR_CHIP((((u32)rutype << 4) & ~((u32)0x000000F0)) == 0);
	cl_reg_write(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR, (cl_reg_read(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR) & ~((u32)0x000000F0)) | ((u32)rutype << 4));
}

static inline u8 macdsp_api_cpe_sto_common_info_gitype_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR);

	return (u8)((local_val & ((u32)0x0000000C)) >> 2);
}

static inline void macdsp_api_cpe_sto_common_info_gitype_setf(struct cl_chip *chip, u8 gitype)
{
	ASSERT_ERR_CHIP((((u32)gitype << 2) & ~((u32)0x0000000C)) == 0);
	cl_reg_write(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR, (cl_reg_read(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR) & ~((u32)0x0000000C)) | ((u32)gitype << 2));
}

static inline u8 macdsp_api_cpe_sto_common_info_frame_bw_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macdsp_api_cpe_sto_common_info_frame_bw_setf(struct cl_chip *chip, u8 framebw)
{
	ASSERT_ERR_CHIP((((u32)framebw << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR, (cl_reg_read(chip, MACDSP_API_CPE_STO_COMMON_INFO_ADDR) & ~((u32)0x00000003)) | ((u32)framebw << 0));
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
#define MACDSP_API_STO_FINE_CHECK_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000848)
#define MACDSP_API_STO_FINE_CHECK_OFFSET      0x00000848
#define MACDSP_API_STO_FINE_CHECK_INDEX       0x00000212
#define MACDSP_API_STO_FINE_CHECK_RESET       0x00000000

static inline u32 macdsp_api_sto_fine_check_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_STO_FINE_CHECK_ADDR);
}

static inline void macdsp_api_sto_fine_check_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_STO_FINE_CHECK_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_STO_FINE_CHECK_STO_FINE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_STO_FINE_CHECK_STO_FINE_LSB    0
#define MACDSP_API_STO_FINE_CHECK_STO_FINE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_STO_FINE_CHECK_STO_FINE_RST    0x0

static inline u32 macdsp_api_sto_fine_check_sto_fine_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_STO_FINE_CHECK_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_sto_fine_check_sto_fine_setf(struct cl_chip *chip, u32 stofine)
{
	ASSERT_ERR_CHIP((((u32)stofine << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_STO_FINE_CHECK_ADDR, (u32)stofine << 0);
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
#define MACDSP_API_TX_TB_SPU_STO_INIT_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000084C)
#define MACDSP_API_TX_TB_SPU_STO_INIT_OFFSET      0x0000084C
#define MACDSP_API_TX_TB_SPU_STO_INIT_INDEX       0x00000213
#define MACDSP_API_TX_TB_SPU_STO_INIT_RESET       0x00000000

static inline u32 macdsp_api_tx_tb_spu_sto_init_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TX_TB_SPU_STO_INIT_ADDR);
}

static inline void macdsp_api_tx_tb_spu_sto_init_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TX_TB_SPU_STO_INIT_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TX_TB_SPU_STO_INIT_TX_TB_SPU_STO_INIT_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_TX_TB_SPU_STO_INIT_TX_TB_SPU_STO_INIT_LSB    0
#define MACDSP_API_TX_TB_SPU_STO_INIT_TX_TB_SPU_STO_INIT_WIDTH    ((u32)0x00000020)

#define MACDSP_API_TX_TB_SPU_STO_INIT_TX_TB_SPU_STO_INIT_RST    0x0

static inline u32 macdsp_api_tx_tb_spu_sto_init_tx_tb_spu_sto_init_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_TB_SPU_STO_INIT_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_tx_tb_spu_sto_init_tx_tb_spu_sto_init_setf(struct cl_chip *chip, u32 txtbspustoinit)
{
	ASSERT_ERR_CHIP((((u32)txtbspustoinit << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_TB_SPU_STO_INIT_ADDR, (u32)txtbspustoinit << 0);
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
#define MACDSP_API_TX_TB_SPU_STO_STF_DELTA_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000850)
#define MACDSP_API_TX_TB_SPU_STO_STF_DELTA_OFFSET      0x00000850
#define MACDSP_API_TX_TB_SPU_STO_STF_DELTA_INDEX       0x00000214
#define MACDSP_API_TX_TB_SPU_STO_STF_DELTA_RESET       0x00000000

static inline u32 macdsp_api_tx_tb_spu_sto_stf_delta_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TX_TB_SPU_STO_STF_DELTA_ADDR);
}

static inline void macdsp_api_tx_tb_spu_sto_stf_delta_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TX_TB_SPU_STO_STF_DELTA_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TX_TB_SPU_STO_STF_DELTA_TX_TB_SPU_STO_STF_DELTA_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_TX_TB_SPU_STO_STF_DELTA_TX_TB_SPU_STO_STF_DELTA_LSB    0
#define MACDSP_API_TX_TB_SPU_STO_STF_DELTA_TX_TB_SPU_STO_STF_DELTA_WIDTH    ((u32)0x00000020)

#define MACDSP_API_TX_TB_SPU_STO_STF_DELTA_TX_TB_SPU_STO_STF_DELTA_RST    0x0

static inline u32 macdsp_api_tx_tb_spu_sto_stf_delta_tx_tb_spu_sto_stf_delta_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_TB_SPU_STO_STF_DELTA_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_tx_tb_spu_sto_stf_delta_tx_tb_spu_sto_stf_delta_setf(struct cl_chip *chip, u32 txtbspustostfdelta)
{
	ASSERT_ERR_CHIP((((u32)txtbspustostfdelta << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_TB_SPU_STO_STF_DELTA_ADDR, (u32)txtbspustostfdelta << 0);
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
#define MACDSP_API_TX_TB_SPU_STO_LTF_DELTA_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000854)
#define MACDSP_API_TX_TB_SPU_STO_LTF_DELTA_OFFSET      0x00000854
#define MACDSP_API_TX_TB_SPU_STO_LTF_DELTA_INDEX       0x00000215
#define MACDSP_API_TX_TB_SPU_STO_LTF_DELTA_RESET       0x00000000

static inline u32 macdsp_api_tx_tb_spu_sto_ltf_delta_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TX_TB_SPU_STO_LTF_DELTA_ADDR);
}

static inline void macdsp_api_tx_tb_spu_sto_ltf_delta_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TX_TB_SPU_STO_LTF_DELTA_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TX_TB_SPU_STO_LTF_DELTA_TX_TB_SPU_STO_LTF_DELTA_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_TX_TB_SPU_STO_LTF_DELTA_TX_TB_SPU_STO_LTF_DELTA_LSB    0
#define MACDSP_API_TX_TB_SPU_STO_LTF_DELTA_TX_TB_SPU_STO_LTF_DELTA_WIDTH    ((u32)0x00000020)

#define MACDSP_API_TX_TB_SPU_STO_LTF_DELTA_TX_TB_SPU_STO_LTF_DELTA_RST    0x0

static inline u32 macdsp_api_tx_tb_spu_sto_ltf_delta_tx_tb_spu_sto_ltf_delta_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_TB_SPU_STO_LTF_DELTA_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_tx_tb_spu_sto_ltf_delta_tx_tb_spu_sto_ltf_delta_setf(struct cl_chip *chip, u32 txtbspustoltfdelta)
{
	ASSERT_ERR_CHIP((((u32)txtbspustoltfdelta << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_TB_SPU_STO_LTF_DELTA_ADDR, (u32)txtbspustoltfdelta << 0);
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
#define MACDSP_API_TX_TB_SPU_STO_DATA_DELTA_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000858)
#define MACDSP_API_TX_TB_SPU_STO_DATA_DELTA_OFFSET      0x00000858
#define MACDSP_API_TX_TB_SPU_STO_DATA_DELTA_INDEX       0x00000216
#define MACDSP_API_TX_TB_SPU_STO_DATA_DELTA_RESET       0x00000000

static inline u32 macdsp_api_tx_tb_spu_sto_data_delta_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TX_TB_SPU_STO_DATA_DELTA_ADDR);
}

static inline void macdsp_api_tx_tb_spu_sto_data_delta_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TX_TB_SPU_STO_DATA_DELTA_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TX_TB_SPU_STO_DATA_DELTA_TX_TB_SPU_STO_DATA_DELTA_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_TX_TB_SPU_STO_DATA_DELTA_TX_TB_SPU_STO_DATA_DELTA_LSB    0
#define MACDSP_API_TX_TB_SPU_STO_DATA_DELTA_TX_TB_SPU_STO_DATA_DELTA_WIDTH    ((u32)0x00000020)

#define MACDSP_API_TX_TB_SPU_STO_DATA_DELTA_TX_TB_SPU_STO_DATA_DELTA_RST    0x0

static inline u32 macdsp_api_tx_tb_spu_sto_data_delta_tx_tb_spu_sto_data_delta_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_TB_SPU_STO_DATA_DELTA_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_tx_tb_spu_sto_data_delta_tx_tb_spu_sto_data_delta_setf(struct cl_chip *chip, u32 txtbspustodatadelta)
{
	ASSERT_ERR_CHIP((((u32)txtbspustodatadelta << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_TB_SPU_STO_DATA_DELTA_ADDR, (u32)txtbspustodatadelta << 0);
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
#define MACDSP_API_TX_TB_SPU_STO_LIMIT_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000085C)
#define MACDSP_API_TX_TB_SPU_STO_LIMIT_OFFSET      0x0000085C
#define MACDSP_API_TX_TB_SPU_STO_LIMIT_INDEX       0x00000217
#define MACDSP_API_TX_TB_SPU_STO_LIMIT_RESET       0x00000000

static inline u32 macdsp_api_tx_tb_spu_sto_limit_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TX_TB_SPU_STO_LIMIT_ADDR);
}

static inline void macdsp_api_tx_tb_spu_sto_limit_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TX_TB_SPU_STO_LIMIT_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TX_TB_SPU_STO_LIMIT_TX_TB_SPU_STO_LIMIT_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_TX_TB_SPU_STO_LIMIT_TX_TB_SPU_STO_LIMIT_LSB    0
#define MACDSP_API_TX_TB_SPU_STO_LIMIT_TX_TB_SPU_STO_LIMIT_WIDTH    ((u32)0x00000020)

#define MACDSP_API_TX_TB_SPU_STO_LIMIT_TX_TB_SPU_STO_LIMIT_RST    0x0

static inline u32 macdsp_api_tx_tb_spu_sto_limit_tx_tb_spu_sto_limit_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_TB_SPU_STO_LIMIT_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_tx_tb_spu_sto_limit_tx_tb_spu_sto_limit_setf(struct cl_chip *chip, u32 txtbspustolimit)
{
	ASSERT_ERR_CHIP((((u32)txtbspustolimit << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_TB_SPU_STO_LIMIT_ADDR, (u32)txtbspustolimit << 0);
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
#define MACDSP_API_SMU_CHECKER_ADDR_PART_1_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000860)
#define MACDSP_API_SMU_CHECKER_ADDR_PART_1_OFFSET      0x00000860
#define MACDSP_API_SMU_CHECKER_ADDR_PART_1_INDEX       0x00000218
#define MACDSP_API_SMU_CHECKER_ADDR_PART_1_RESET       0x00000000

static inline u32 macdsp_api_smu_checker_addr_part_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_1_ADDR);
}

static inline void macdsp_api_smu_checker_addr_part_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_1_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SMU_CHECKER_ADDR_PART_1_SMU_NUMBER_OF_STEPS_MASK    ((u32)0x18000000)
#define MACDSP_API_SMU_CHECKER_ADDR_PART_1_SMU_NUMBER_OF_STEPS_LSB    27
#define MACDSP_API_SMU_CHECKER_ADDR_PART_1_SMU_NUMBER_OF_STEPS_WIDTH    ((u32)0x00000002)
#define MACDSP_API_SMU_CHECKER_ADDR_PART_1_SMU_NUMBER_OF_VALID_SC_MASK    ((u32)0x07FE0000)
#define MACDSP_API_SMU_CHECKER_ADDR_PART_1_SMU_NUMBER_OF_VALID_SC_LSB    17
#define MACDSP_API_SMU_CHECKER_ADDR_PART_1_SMU_NUMBER_OF_VALID_SC_WIDTH    ((u32)0x0000000A)
#define MACDSP_API_SMU_CHECKER_ADDR_PART_1_SMU_CHECKER_PART_1_ADDRR_MASK    ((u32)0x0001FFFF)
#define MACDSP_API_SMU_CHECKER_ADDR_PART_1_SMU_CHECKER_PART_1_ADDRR_LSB    0
#define MACDSP_API_SMU_CHECKER_ADDR_PART_1_SMU_CHECKER_PART_1_ADDRR_WIDTH    ((u32)0x00000011)

#define MACDSP_API_SMU_CHECKER_ADDR_PART_1_SMU_NUMBER_OF_STEPS_RST    0x0
#define MACDSP_API_SMU_CHECKER_ADDR_PART_1_SMU_NUMBER_OF_VALID_SC_RST    0x0
#define MACDSP_API_SMU_CHECKER_ADDR_PART_1_SMU_CHECKER_PART_1_ADDRR_RST    0x0

static inline void macdsp_api_smu_checker_addr_part_1_pack(struct cl_chip *chip, u8 smu_number_of_steps, u16 smu_number_of_valid_sc, u32 smu_checker_part1_addrr)
{
	ASSERT_ERR_CHIP((((u32)smu_number_of_steps << 27) & ~((u32)0x18000000)) == 0);
	ASSERT_ERR_CHIP((((u32)smu_number_of_valid_sc << 17) & ~((u32)0x07FE0000)) == 0);
	ASSERT_ERR_CHIP((((u32)smu_checker_part1_addrr << 0) & ~((u32)0x0001FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_1_ADDR, ((u32)smu_number_of_steps << 27) | ((u32)smu_number_of_valid_sc << 17) | ((u32)smu_checker_part1_addrr << 0));
}

static inline void macdsp_api_smu_checker_addr_part_1_unpack(struct cl_chip *chip, u8 *smu_number_of_steps, u16 *smu_number_of_valid_sc, u32 *smu_checker_part1_addrr)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_1_ADDR);

	*smu_number_of_steps = (local_val & ((u32)0x18000000)) >> 27;
	*smu_number_of_valid_sc = (local_val & ((u32)0x07FE0000)) >> 17;
	*smu_checker_part1_addrr = (local_val & ((u32)0x0001FFFF)) >> 0;
}

static inline u8 macdsp_api_smu_checker_addr_part_1_smu_number_of_steps_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_1_ADDR);

	return (u8)((local_val & ((u32)0x18000000)) >> 27);
}

static inline void macdsp_api_smu_checker_addr_part_1_smu_number_of_steps_setf(struct cl_chip *chip, u8 smunumberofsteps)
{
	ASSERT_ERR_CHIP((((u32)smunumberofsteps << 27) & ~((u32)0x18000000)) == 0);
	cl_reg_write(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_1_ADDR, (cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_1_ADDR) & ~((u32)0x18000000)) | ((u32)smunumberofsteps << 27));
}

static inline u16 macdsp_api_smu_checker_addr_part_1_smu_number_of_valid_sc_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_1_ADDR);

	return (u16)((local_val & ((u32)0x07FE0000)) >> 17);
}

static inline void macdsp_api_smu_checker_addr_part_1_smu_number_of_valid_sc_setf(struct cl_chip *chip, u16 smunumberofvalidsc)
{
	ASSERT_ERR_CHIP((((u32)smunumberofvalidsc << 17) & ~((u32)0x07FE0000)) == 0);
	cl_reg_write(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_1_ADDR, (cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_1_ADDR) & ~((u32)0x07FE0000)) | ((u32)smunumberofvalidsc << 17));
}

static inline u32 macdsp_api_smu_checker_addr_part_1_smu_checker_part_1_addrr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_1_ADDR);

	return (u32)((local_val & ((u32)0x0001FFFF)) >> 0);
}

static inline void macdsp_api_smu_checker_addr_part_1_smu_checker_part_1_addrr_setf(struct cl_chip *chip, u32 smucheckerpart1addrr)
{
	ASSERT_ERR_CHIP((((u32)smucheckerpart1addrr << 0) & ~((u32)0x0001FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_1_ADDR, (cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_1_ADDR) & ~((u32)0x0001FFFF)) | ((u32)smucheckerpart1addrr << 0));
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
#define MACDSP_API_SMU_CHECKER_ADDR_PART_2_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000864)
#define MACDSP_API_SMU_CHECKER_ADDR_PART_2_OFFSET      0x00000864
#define MACDSP_API_SMU_CHECKER_ADDR_PART_2_INDEX       0x00000219
#define MACDSP_API_SMU_CHECKER_ADDR_PART_2_RESET       0x00000000

static inline u32 macdsp_api_smu_checker_addr_part_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_2_ADDR);
}

static inline void macdsp_api_smu_checker_addr_part_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_2_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SMU_CHECKER_ADDR_PART_2_SMU_CHECKER_ADDRR_PART_2_NSS_MASK    ((u32)0x38000000)
#define MACDSP_API_SMU_CHECKER_ADDR_PART_2_SMU_CHECKER_ADDRR_PART_2_NSS_LSB    27
#define MACDSP_API_SMU_CHECKER_ADDR_PART_2_SMU_CHECKER_ADDRR_PART_2_NSS_WIDTH    ((u32)0x00000003)
#define MACDSP_API_SMU_CHECKER_ADDR_PART_2_SMU_FFTPER_STEP_MASK    ((u32)0x07FE0000)
#define MACDSP_API_SMU_CHECKER_ADDR_PART_2_SMU_FFTPER_STEP_LSB    17
#define MACDSP_API_SMU_CHECKER_ADDR_PART_2_SMU_FFTPER_STEP_WIDTH    ((u32)0x0000000A)
#define MACDSP_API_SMU_CHECKER_ADDR_PART_2_SMU_CHECKER_PART_2_ADDRR_MASK    ((u32)0x0001FFFF)
#define MACDSP_API_SMU_CHECKER_ADDR_PART_2_SMU_CHECKER_PART_2_ADDRR_LSB    0
#define MACDSP_API_SMU_CHECKER_ADDR_PART_2_SMU_CHECKER_PART_2_ADDRR_WIDTH    ((u32)0x00000011)

#define MACDSP_API_SMU_CHECKER_ADDR_PART_2_SMU_CHECKER_ADDRR_PART_2_NSS_RST    0x0
#define MACDSP_API_SMU_CHECKER_ADDR_PART_2_SMU_FFTPER_STEP_RST    0x0
#define MACDSP_API_SMU_CHECKER_ADDR_PART_2_SMU_CHECKER_PART_2_ADDRR_RST    0x0

static inline void macdsp_api_smu_checker_addr_part_2_pack(struct cl_chip *chip, u8 smu_checker_addrr_part2_nss, u16 smu_fftper_step, u32 smu_checker_part2_addrr)
{
	ASSERT_ERR_CHIP((((u32)smu_checker_addrr_part2_nss << 27) & ~((u32)0x38000000)) == 0);
	ASSERT_ERR_CHIP((((u32)smu_fftper_step << 17) & ~((u32)0x07FE0000)) == 0);
	ASSERT_ERR_CHIP((((u32)smu_checker_part2_addrr << 0) & ~((u32)0x0001FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_2_ADDR, ((u32)smu_checker_addrr_part2_nss << 27) | ((u32)smu_fftper_step << 17) | ((u32)smu_checker_part2_addrr << 0));
}

static inline void macdsp_api_smu_checker_addr_part_2_unpack(struct cl_chip *chip, u8 *smu_checker_addrr_part2_nss, u16 *smu_fftper_step, u32 *smu_checker_part2_addrr)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_2_ADDR);

	*smu_checker_addrr_part2_nss = (local_val & ((u32)0x38000000)) >> 27;
	*smu_fftper_step = (local_val & ((u32)0x07FE0000)) >> 17;
	*smu_checker_part2_addrr = (local_val & ((u32)0x0001FFFF)) >> 0;
}

static inline u8 macdsp_api_smu_checker_addr_part_2_smu_checker_addrr_part_2_nss_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_2_ADDR);

	return (u8)((local_val & ((u32)0x38000000)) >> 27);
}

static inline void macdsp_api_smu_checker_addr_part_2_smu_checker_addrr_part_2_nss_setf(struct cl_chip *chip, u8 smucheckeraddrrpart2nss)
{
	ASSERT_ERR_CHIP((((u32)smucheckeraddrrpart2nss << 27) & ~((u32)0x38000000)) == 0);
	cl_reg_write(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_2_ADDR, (cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_2_ADDR) & ~((u32)0x38000000)) | ((u32)smucheckeraddrrpart2nss << 27));
}

static inline u16 macdsp_api_smu_checker_addr_part_2_smu_fftper_step_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_2_ADDR);

	return (u16)((local_val & ((u32)0x07FE0000)) >> 17);
}

static inline void macdsp_api_smu_checker_addr_part_2_smu_fftper_step_setf(struct cl_chip *chip, u16 smufftperstep)
{
	ASSERT_ERR_CHIP((((u32)smufftperstep << 17) & ~((u32)0x07FE0000)) == 0);
	cl_reg_write(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_2_ADDR, (cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_2_ADDR) & ~((u32)0x07FE0000)) | ((u32)smufftperstep << 17));
}

static inline u32 macdsp_api_smu_checker_addr_part_2_smu_checker_part_2_addrr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_2_ADDR);

	return (u32)((local_val & ((u32)0x0001FFFF)) >> 0);
}

static inline void macdsp_api_smu_checker_addr_part_2_smu_checker_part_2_addrr_setf(struct cl_chip *chip, u32 smucheckerpart2addrr)
{
	ASSERT_ERR_CHIP((((u32)smucheckerpart2addrr << 0) & ~((u32)0x0001FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_2_ADDR, (cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_2_ADDR) & ~((u32)0x0001FFFF)) | ((u32)smucheckerpart2addrr << 0));
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
#define MACDSP_API_SMU_CHECKER_ADDR_PART_3_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000868)
#define MACDSP_API_SMU_CHECKER_ADDR_PART_3_OFFSET      0x00000868
#define MACDSP_API_SMU_CHECKER_ADDR_PART_3_INDEX       0x0000021A
#define MACDSP_API_SMU_CHECKER_ADDR_PART_3_RESET       0x00000000

static inline u32 macdsp_api_smu_checker_addr_part_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_3_ADDR);
}

static inline void macdsp_api_smu_checker_addr_part_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_3_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SMU_CHECKER_ADDR_PART_3_NRX_MASK    ((u32)0x000E0000)
#define MACDSP_API_SMU_CHECKER_ADDR_PART_3_NRX_LSB    17
#define MACDSP_API_SMU_CHECKER_ADDR_PART_3_NRX_WIDTH    ((u32)0x00000003)
#define MACDSP_API_SMU_CHECKER_ADDR_PART_3_SMU_CHECKER_PART_3_ADDRR_MASK    ((u32)0x0001FFFF)
#define MACDSP_API_SMU_CHECKER_ADDR_PART_3_SMU_CHECKER_PART_3_ADDRR_LSB    0
#define MACDSP_API_SMU_CHECKER_ADDR_PART_3_SMU_CHECKER_PART_3_ADDRR_WIDTH    ((u32)0x00000011)

#define MACDSP_API_SMU_CHECKER_ADDR_PART_3_NRX_RST    0x0
#define MACDSP_API_SMU_CHECKER_ADDR_PART_3_SMU_CHECKER_PART_3_ADDRR_RST    0x0

static inline void macdsp_api_smu_checker_addr_part_3_pack(struct cl_chip *chip, u8 nrx, u32 smu_checker_part3_addrr)
{
	ASSERT_ERR_CHIP((((u32)nrx << 17) & ~((u32)0x000E0000)) == 0);
	ASSERT_ERR_CHIP((((u32)smu_checker_part3_addrr << 0) & ~((u32)0x0001FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_3_ADDR, ((u32)nrx << 17) | ((u32)smu_checker_part3_addrr << 0));
}

static inline void macdsp_api_smu_checker_addr_part_3_unpack(struct cl_chip *chip, u8 *nrx, u32 *smu_checker_part3_addrr)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_3_ADDR);

	*nrx = (local_val & ((u32)0x000E0000)) >> 17;
	*smu_checker_part3_addrr = (local_val & ((u32)0x0001FFFF)) >> 0;
}

static inline u8 macdsp_api_smu_checker_addr_part_3_nrx_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_3_ADDR);

	return (u8)((local_val & ((u32)0x000E0000)) >> 17);
}

static inline void macdsp_api_smu_checker_addr_part_3_nrx_setf(struct cl_chip *chip, u8 nrx)
{
	ASSERT_ERR_CHIP((((u32)nrx << 17) & ~((u32)0x000E0000)) == 0);
	cl_reg_write(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_3_ADDR, (cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_3_ADDR) & ~((u32)0x000E0000)) | ((u32)nrx << 17));
}

static inline u32 macdsp_api_smu_checker_addr_part_3_smu_checker_part_3_addrr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_3_ADDR);

	return (u32)((local_val & ((u32)0x0001FFFF)) >> 0);
}

static inline void macdsp_api_smu_checker_addr_part_3_smu_checker_part_3_addrr_setf(struct cl_chip *chip, u32 smucheckerpart3addrr)
{
	ASSERT_ERR_CHIP((((u32)smucheckerpart3addrr << 0) & ~((u32)0x0001FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_3_ADDR, (cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_3_ADDR) & ~((u32)0x0001FFFF)) | ((u32)smucheckerpart3addrr << 0));
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
#define MACDSP_API_SMU_CHECKER_ADDR_PART_4_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000086C)
#define MACDSP_API_SMU_CHECKER_ADDR_PART_4_OFFSET      0x0000086C
#define MACDSP_API_SMU_CHECKER_ADDR_PART_4_INDEX       0x0000021B
#define MACDSP_API_SMU_CHECKER_ADDR_PART_4_RESET       0x00000000

static inline u32 macdsp_api_smu_checker_addr_part_4_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_4_ADDR);
}

static inline void macdsp_api_smu_checker_addr_part_4_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_4_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_SMU_CHECKER_ADDR_PART_4_SMU_CHECKER_PART_4_ADDRR_MASK    ((u32)0x0001FFFF)
#define MACDSP_API_SMU_CHECKER_ADDR_PART_4_SMU_CHECKER_PART_4_ADDRR_LSB    0
#define MACDSP_API_SMU_CHECKER_ADDR_PART_4_SMU_CHECKER_PART_4_ADDRR_WIDTH    ((u32)0x00000011)

#define MACDSP_API_SMU_CHECKER_ADDR_PART_4_SMU_CHECKER_PART_4_ADDRR_RST    0x0

static inline u32 macdsp_api_smu_checker_addr_part_4_smu_checker_part_4_addrr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_4_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_smu_checker_addr_part_4_smu_checker_part_4_addrr_setf(struct cl_chip *chip, u32 smucheckerpart4addrr)
{
	ASSERT_ERR_CHIP((((u32)smucheckerpart4addrr << 0) & ~((u32)0x0001FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_SMU_CHECKER_ADDR_PART_4_ADDR, (u32)smucheckerpart4addrr << 0);
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
#define MACDSP_API_TX_TB_FREQ_OFFSET_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000870)
#define MACDSP_API_TX_TB_FREQ_OFFSET_OFFSET      0x00000870
#define MACDSP_API_TX_TB_FREQ_OFFSET_INDEX       0x0000021C
#define MACDSP_API_TX_TB_FREQ_OFFSET_RESET       0x00000000

static inline u32 macdsp_api_tx_tb_freq_offset_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TX_TB_FREQ_OFFSET_ADDR);
}

static inline void macdsp_api_tx_tb_freq_offset_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TX_TB_FREQ_OFFSET_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TX_TB_FREQ_OFFSET_TX_TB_FREQ_OFFSET_VAL_MASK    ((u32)0x001FFFFF)
#define MACDSP_API_TX_TB_FREQ_OFFSET_TX_TB_FREQ_OFFSET_VAL_LSB    0
#define MACDSP_API_TX_TB_FREQ_OFFSET_TX_TB_FREQ_OFFSET_VAL_WIDTH    ((u32)0x00000015)

#define MACDSP_API_TX_TB_FREQ_OFFSET_TX_TB_FREQ_OFFSET_VAL_RST    0x0

static inline u32 macdsp_api_tx_tb_freq_offset_tx_tb_freq_offset_val_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_TB_FREQ_OFFSET_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_tx_tb_freq_offset_tx_tb_freq_offset_val_setf(struct cl_chip *chip, u32 txtbfreqoffsetval)
{
	ASSERT_ERR_CHIP((((u32)txtbfreqoffsetval << 0) & ~((u32)0x001FFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_TB_FREQ_OFFSET_ADDR, (u32)txtbfreqoffsetval << 0);
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
#define MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000874)
#define MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_OFFSET      0x00000874
#define MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_INDEX       0x0000021D
#define MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_RESET       0x00000000

static inline u32 macdsp_api_tx_riu_resampler_delta_offset_from_matlab_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR);
}

static inline void macdsp_api_tx_riu_resampler_delta_offset_from_matlab_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_LSB    0
#define MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_WIDTH    ((u32)0x00000020)

#define MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_RST    0x0

static inline u32 macdsp_api_tx_riu_resampler_delta_offset_from_matlab_macdsp_api_tx_riu_resampler_delta_offset_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_tx_riu_resampler_delta_offset_from_matlab_macdsp_api_tx_riu_resampler_delta_offset_setf(struct cl_chip *chip, u32 macdspapitxriuresamplerdeltaoffset)
{
	ASSERT_ERR_CHIP((((u32)macdspapitxriuresamplerdeltaoffset << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_TX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR, (u32)macdspapitxriuresamplerdeltaoffset << 0);
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
#define MACDSP_API_RX_EVM_DEBUG_1_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000878)
#define MACDSP_API_RX_EVM_DEBUG_1_OFFSET      0x00000878
#define MACDSP_API_RX_EVM_DEBUG_1_INDEX       0x0000021E
#define MACDSP_API_RX_EVM_DEBUG_1_RESET       0x00000000

static inline u32 macdsp_api_rx_evm_debug_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_EVM_DEBUG_1_ADDR);
}

static inline void macdsp_api_rx_evm_debug_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_EVM_DEBUG_1_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_EVM_DEBUG_1_EVM_DEBUG_1_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_RX_EVM_DEBUG_1_EVM_DEBUG_1_LSB    0
#define MACDSP_API_RX_EVM_DEBUG_1_EVM_DEBUG_1_WIDTH    ((u32)0x00000020)

#define MACDSP_API_RX_EVM_DEBUG_1_EVM_DEBUG_1_RST    0x0

static inline u32 macdsp_api_rx_evm_debug_1_evm_debug_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_EVM_DEBUG_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_rx_evm_debug_1_evm_debug_1_setf(struct cl_chip *chip, u32 evmdebug1)
{
	ASSERT_ERR_CHIP((((u32)evmdebug1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_EVM_DEBUG_1_ADDR, (u32)evmdebug1 << 0);
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
#define MACDSP_API_RX_EVM_DEBUG_2_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000087C)
#define MACDSP_API_RX_EVM_DEBUG_2_OFFSET      0x0000087C
#define MACDSP_API_RX_EVM_DEBUG_2_INDEX       0x0000021F
#define MACDSP_API_RX_EVM_DEBUG_2_RESET       0x00000000

static inline u32 macdsp_api_rx_evm_debug_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_EVM_DEBUG_2_ADDR);
}

static inline void macdsp_api_rx_evm_debug_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_EVM_DEBUG_2_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_EVM_DEBUG_2_EVM_DEBUG_2_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_RX_EVM_DEBUG_2_EVM_DEBUG_2_LSB    0
#define MACDSP_API_RX_EVM_DEBUG_2_EVM_DEBUG_2_WIDTH    ((u32)0x00000020)

#define MACDSP_API_RX_EVM_DEBUG_2_EVM_DEBUG_2_RST    0x0

static inline u32 macdsp_api_rx_evm_debug_2_evm_debug_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_EVM_DEBUG_2_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_rx_evm_debug_2_evm_debug_2_setf(struct cl_chip *chip, u32 evmdebug2)
{
	ASSERT_ERR_CHIP((((u32)evmdebug2 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_EVM_DEBUG_2_ADDR, (u32)evmdebug2 << 0);
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
#define MACDSP_API_RX_EVM_DEBUG_3_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000880)
#define MACDSP_API_RX_EVM_DEBUG_3_OFFSET      0x00000880
#define MACDSP_API_RX_EVM_DEBUG_3_INDEX       0x00000220
#define MACDSP_API_RX_EVM_DEBUG_3_RESET       0x00000000

static inline u32 macdsp_api_rx_evm_debug_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_EVM_DEBUG_3_ADDR);
}

static inline void macdsp_api_rx_evm_debug_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_EVM_DEBUG_3_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_EVM_DEBUG_3_EVM_DEBUG_3_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_RX_EVM_DEBUG_3_EVM_DEBUG_3_LSB    0
#define MACDSP_API_RX_EVM_DEBUG_3_EVM_DEBUG_3_WIDTH    ((u32)0x00000020)

#define MACDSP_API_RX_EVM_DEBUG_3_EVM_DEBUG_3_RST    0x0

static inline u32 macdsp_api_rx_evm_debug_3_evm_debug_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_EVM_DEBUG_3_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_rx_evm_debug_3_evm_debug_3_setf(struct cl_chip *chip, u32 evmdebug3)
{
	ASSERT_ERR_CHIP((((u32)evmdebug3 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_EVM_DEBUG_3_ADDR, (u32)evmdebug3 << 0);
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
#define MACDSP_API_DEPACKER_GETREADY_FLAG_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000884)
#define MACDSP_API_DEPACKER_GETREADY_FLAG_OFFSET      0x00000884
#define MACDSP_API_DEPACKER_GETREADY_FLAG_INDEX       0x00000221
#define MACDSP_API_DEPACKER_GETREADY_FLAG_RESET       0x00000000

static inline u32 macdsp_api_depacker_getready_flag_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_DEPACKER_GETREADY_FLAG_ADDR);
}

static inline void macdsp_api_depacker_getready_flag_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_DEPACKER_GETREADY_FLAG_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_DEPACKER_GETREADY_FLAG_DEPACKER_GETREADY_FLAG_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_DEPACKER_GETREADY_FLAG_DEPACKER_GETREADY_FLAG_LSB    0
#define MACDSP_API_DEPACKER_GETREADY_FLAG_DEPACKER_GETREADY_FLAG_WIDTH    ((u32)0x00000020)

#define MACDSP_API_DEPACKER_GETREADY_FLAG_DEPACKER_GETREADY_FLAG_RST    0x0

static inline u32 macdsp_api_depacker_getready_flag_depacker_getready_flag_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DEPACKER_GETREADY_FLAG_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_depacker_getready_flag_depacker_getready_flag_setf(struct cl_chip *chip, u32 depackergetreadyflag)
{
	ASSERT_ERR_CHIP((((u32)depackergetreadyflag << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_DEPACKER_GETREADY_FLAG_ADDR, (u32)depackergetreadyflag << 0);
}

/**
 * @brief LCU_MODE_FLAG register definition
 *  LCU_MODE_FLAG register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    LCU_MODE_FLAG             0
 * </pre>
 */
#define MACDSP_API_LCU_MODE_FLAG_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000888)
#define MACDSP_API_LCU_MODE_FLAG_OFFSET      0x00000888
#define MACDSP_API_LCU_MODE_FLAG_INDEX       0x00000222
#define MACDSP_API_LCU_MODE_FLAG_RESET       0x00000000

static inline u32 macdsp_api_lcu_mode_flag_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_LCU_MODE_FLAG_ADDR);
}

static inline void macdsp_api_lcu_mode_flag_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_LCU_MODE_FLAG_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_LCU_MODE_FLAG_LCU_MODE_FLAG_BIT    ((u32)0x00000001)
#define MACDSP_API_LCU_MODE_FLAG_LCU_MODE_FLAG_POS    0

#define MACDSP_API_LCU_MODE_FLAG_LCU_MODE_FLAG_RST    0x0

static inline u8 macdsp_api_lcu_mode_flag_lcu_mode_flag_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LCU_MODE_FLAG_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macdsp_api_lcu_mode_flag_lcu_mode_flag_setf(struct cl_chip *chip, u8 lcumodeflag)
{
	ASSERT_ERR_CHIP((((u32)lcumodeflag << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_LCU_MODE_FLAG_ADDR, (u32)lcumodeflag << 0);
}

/**
 * @brief DSP_CNTR_EVM_DROP register definition
 *  EVM_DROP_COUNTER register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 * </pre>
 */
#define MACDSP_API_DSP_CNTR_EVM_DROP_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000898)
#define MACDSP_API_DSP_CNTR_EVM_DROP_OFFSET      0x00000898
#define MACDSP_API_DSP_CNTR_EVM_DROP_INDEX       0x00000226
#define MACDSP_API_DSP_CNTR_EVM_DROP_RESET       0x00000000

/* Field definitions */

/**
 * @brief RX_TB_FRC_VAL register definition
 *  RX_TB_FRC_VAL register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:00 RX_TB_FRC_VAL             0x0
 * </pre>
 */
#define MACDSP_API_RX_TB_FRC_VAL_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000089C)
#define MACDSP_API_RX_TB_FRC_VAL_OFFSET      0x0000089C
#define MACDSP_API_RX_TB_FRC_VAL_INDEX       0x00000227
#define MACDSP_API_RX_TB_FRC_VAL_RESET       0x00000000

static inline u32 macdsp_api_rx_tb_frc_val_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_TB_FRC_VAL_ADDR);
}

static inline void macdsp_api_rx_tb_frc_val_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_TB_FRC_VAL_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_TB_FRC_VAL_RX_TB_FRC_VAL_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_RX_TB_FRC_VAL_RX_TB_FRC_VAL_LSB    0
#define MACDSP_API_RX_TB_FRC_VAL_RX_TB_FRC_VAL_WIDTH    ((u32)0x00000020)

#define MACDSP_API_RX_TB_FRC_VAL_RX_TB_FRC_VAL_RST    0x0

static inline u32 macdsp_api_rx_tb_frc_val_rx_tb_frc_val_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_TB_FRC_VAL_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_rx_tb_frc_val_rx_tb_frc_val_setf(struct cl_chip *chip, u32 rxtbfrcval)
{
	ASSERT_ERR_CHIP((((u32)rxtbfrcval << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_TB_FRC_VAL_ADDR, (u32)rxtbfrcval << 0);
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
#define MACDSP_API_DSP_ERR_IND_BIT_MASK_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000008A0)
#define MACDSP_API_DSP_ERR_IND_BIT_MASK_OFFSET      0x000008A0
#define MACDSP_API_DSP_ERR_IND_BIT_MASK_INDEX       0x00000228
#define MACDSP_API_DSP_ERR_IND_BIT_MASK_RESET       0x00000000

static inline u32 macdsp_api_dsp_err_ind_bit_mask_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_DSP_ERR_IND_BIT_MASK_ADDR);
}

static inline void macdsp_api_dsp_err_ind_bit_mask_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_DSP_ERR_IND_BIT_MASK_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_DSP_ERR_IND_BIT_MASK_CPE_EXCEED_16_BIT_BIT    ((u32)0x00000002)
#define MACDSP_API_DSP_ERR_IND_BIT_MASK_CPE_EXCEED_16_BIT_POS    1
#define MACDSP_API_DSP_ERR_IND_BIT_MASK_TB_RX_WRONG_STF_INDEX_BIT    ((u32)0x00000001)
#define MACDSP_API_DSP_ERR_IND_BIT_MASK_TB_RX_WRONG_STF_INDEX_POS    0

#define MACDSP_API_DSP_ERR_IND_BIT_MASK_CPE_EXCEED_16_BIT_RST    0x0
#define MACDSP_API_DSP_ERR_IND_BIT_MASK_TB_RX_WRONG_STF_INDEX_RST    0x0

static inline void macdsp_api_dsp_err_ind_bit_mask_pack(struct cl_chip *chip, u8 cpe_exceed_16_bit, u8 tb_rx_wrong_stf_index)
{
	ASSERT_ERR_CHIP((((u32)cpe_exceed_16_bit << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)tb_rx_wrong_stf_index << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_DSP_ERR_IND_BIT_MASK_ADDR, ((u32)cpe_exceed_16_bit << 1) | ((u32)tb_rx_wrong_stf_index << 0));
}

static inline void macdsp_api_dsp_err_ind_bit_mask_unpack(struct cl_chip *chip, u8 *cpe_exceed_16_bit, u8 *tb_rx_wrong_stf_index)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_ERR_IND_BIT_MASK_ADDR);

	*cpe_exceed_16_bit = (local_val & ((u32)0x00000002)) >> 1;
	*tb_rx_wrong_stf_index = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 macdsp_api_dsp_err_ind_bit_mask_cpe_exceed_16_bit_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_ERR_IND_BIT_MASK_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void macdsp_api_dsp_err_ind_bit_mask_cpe_exceed_16_bit_setf(struct cl_chip *chip, u8 cpeexceed16bit)
{
	ASSERT_ERR_CHIP((((u32)cpeexceed16bit << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MACDSP_API_DSP_ERR_IND_BIT_MASK_ADDR, (cl_reg_read(chip, MACDSP_API_DSP_ERR_IND_BIT_MASK_ADDR) & ~((u32)0x00000002)) | ((u32)cpeexceed16bit << 1));
}

static inline u8 macdsp_api_dsp_err_ind_bit_mask_tb_rx_wrong_stf_index_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DSP_ERR_IND_BIT_MASK_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void macdsp_api_dsp_err_ind_bit_mask_tb_rx_wrong_stf_index_setf(struct cl_chip *chip, u8 tbrxwrongstfindex)
{
	ASSERT_ERR_CHIP((((u32)tbrxwrongstfindex << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_DSP_ERR_IND_BIT_MASK_ADDR, (cl_reg_read(chip, MACDSP_API_DSP_ERR_IND_BIT_MASK_ADDR) & ~((u32)0x00000001)) | ((u32)tbrxwrongstfindex << 0));
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
#define MACDSP_API_PACKER_INPUT_STATUS_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000008B8)
#define MACDSP_API_PACKER_INPUT_STATUS_OFFSET      0x000008B8
#define MACDSP_API_PACKER_INPUT_STATUS_INDEX       0x0000022E
#define MACDSP_API_PACKER_INPUT_STATUS_RESET       0x00000000

static inline u32 macdsp_api_packer_input_status_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_PACKER_INPUT_STATUS_ADDR);
}

static inline void macdsp_api_packer_input_status_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_PACKER_INPUT_STATUS_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_PACKER_INPUT_STATUS_PACKER_INPUT_READY_BIT    ((u32)0x00000001)
#define MACDSP_API_PACKER_INPUT_STATUS_PACKER_INPUT_READY_POS    0

#define MACDSP_API_PACKER_INPUT_STATUS_PACKER_INPUT_READY_RST    0x0

static inline u8 macdsp_api_packer_input_status_packer_input_ready_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_PACKER_INPUT_STATUS_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macdsp_api_packer_input_status_packer_input_ready_setf(struct cl_chip *chip, u8 packerinputready)
{
	ASSERT_ERR_CHIP((((u32)packerinputready << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_PACKER_INPUT_STATUS_ADDR, (u32)packerinputready << 0);
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
#define MACDSP_API_V_MATRIX_OFFSET_0_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000008C0)
#define MACDSP_API_V_MATRIX_OFFSET_0_OFFSET      0x000008C0
#define MACDSP_API_V_MATRIX_OFFSET_0_INDEX       0x00000230
#define MACDSP_API_V_MATRIX_OFFSET_0_RESET       0x00000000

static inline u32 macdsp_api_v_matrix_offset_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_V_MATRIX_OFFSET_0_ADDR);
}

static inline void macdsp_api_v_matrix_offset_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_V_MATRIX_OFFSET_0_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_V_MATRIX_OFFSET_0_DEPACKER_INPUT_BUFF_0_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_V_MATRIX_OFFSET_0_DEPACKER_INPUT_BUFF_0_LSB    0
#define MACDSP_API_V_MATRIX_OFFSET_0_DEPACKER_INPUT_BUFF_0_WIDTH    ((u32)0x00000020)

#define MACDSP_API_V_MATRIX_OFFSET_0_DEPACKER_INPUT_BUFF_0_RST    0x0

static inline u32 macdsp_api_v_matrix_offset_0_depacker_input_buff_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_V_MATRIX_OFFSET_0_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_v_matrix_offset_0_depacker_input_buff_0_setf(struct cl_chip *chip, u32 depackerinputbuff0)
{
	ASSERT_ERR_CHIP((((u32)depackerinputbuff0 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_V_MATRIX_OFFSET_0_ADDR, (u32)depackerinputbuff0 << 0);
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
#define MACDSP_API_V_MATRIX_OFFSET_1_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000008C4)
#define MACDSP_API_V_MATRIX_OFFSET_1_OFFSET      0x000008C4
#define MACDSP_API_V_MATRIX_OFFSET_1_INDEX       0x00000231
#define MACDSP_API_V_MATRIX_OFFSET_1_RESET       0x00000000

static inline u32 macdsp_api_v_matrix_offset_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_V_MATRIX_OFFSET_1_ADDR);
}

static inline void macdsp_api_v_matrix_offset_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_V_MATRIX_OFFSET_1_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_V_MATRIX_OFFSET_1_DEPACKER_INPUT_BUFF_1_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_V_MATRIX_OFFSET_1_DEPACKER_INPUT_BUFF_1_LSB    0
#define MACDSP_API_V_MATRIX_OFFSET_1_DEPACKER_INPUT_BUFF_1_WIDTH    ((u32)0x00000020)

#define MACDSP_API_V_MATRIX_OFFSET_1_DEPACKER_INPUT_BUFF_1_RST    0x0

static inline u32 macdsp_api_v_matrix_offset_1_depacker_input_buff_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_V_MATRIX_OFFSET_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_v_matrix_offset_1_depacker_input_buff_1_setf(struct cl_chip *chip, u32 depackerinputbuff1)
{
	ASSERT_ERR_CHIP((((u32)depackerinputbuff1 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_V_MATRIX_OFFSET_1_ADDR, (u32)depackerinputbuff1 << 0);
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
#define MACDSP_API_V_MATRIX_OFFSET_2_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000008C8)
#define MACDSP_API_V_MATRIX_OFFSET_2_OFFSET      0x000008C8
#define MACDSP_API_V_MATRIX_OFFSET_2_INDEX       0x00000232
#define MACDSP_API_V_MATRIX_OFFSET_2_RESET       0x00000000

static inline u32 macdsp_api_v_matrix_offset_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_V_MATRIX_OFFSET_2_ADDR);
}

static inline void macdsp_api_v_matrix_offset_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_V_MATRIX_OFFSET_2_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_V_MATRIX_OFFSET_2_DEPACKER_INPUT_BUFF_2_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_V_MATRIX_OFFSET_2_DEPACKER_INPUT_BUFF_2_LSB    0
#define MACDSP_API_V_MATRIX_OFFSET_2_DEPACKER_INPUT_BUFF_2_WIDTH    ((u32)0x00000020)

#define MACDSP_API_V_MATRIX_OFFSET_2_DEPACKER_INPUT_BUFF_2_RST    0x0

static inline u32 macdsp_api_v_matrix_offset_2_depacker_input_buff_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_V_MATRIX_OFFSET_2_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_v_matrix_offset_2_depacker_input_buff_2_setf(struct cl_chip *chip, u32 depackerinputbuff2)
{
	ASSERT_ERR_CHIP((((u32)depackerinputbuff2 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_V_MATRIX_OFFSET_2_ADDR, (u32)depackerinputbuff2 << 0);
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
#define MACDSP_API_V_MATRIX_OFFSET_3_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000008CC)
#define MACDSP_API_V_MATRIX_OFFSET_3_OFFSET      0x000008CC
#define MACDSP_API_V_MATRIX_OFFSET_3_INDEX       0x00000233
#define MACDSP_API_V_MATRIX_OFFSET_3_RESET       0x00000000

static inline u32 macdsp_api_v_matrix_offset_3_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_V_MATRIX_OFFSET_3_ADDR);
}

static inline void macdsp_api_v_matrix_offset_3_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_V_MATRIX_OFFSET_3_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_V_MATRIX_OFFSET_3_DEPACKER_INPUT_BUFF_3_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_V_MATRIX_OFFSET_3_DEPACKER_INPUT_BUFF_3_LSB    0
#define MACDSP_API_V_MATRIX_OFFSET_3_DEPACKER_INPUT_BUFF_3_WIDTH    ((u32)0x00000020)

#define MACDSP_API_V_MATRIX_OFFSET_3_DEPACKER_INPUT_BUFF_3_RST    0x0

static inline u32 macdsp_api_v_matrix_offset_3_depacker_input_buff_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_V_MATRIX_OFFSET_3_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_v_matrix_offset_3_depacker_input_buff_3_setf(struct cl_chip *chip, u32 depackerinputbuff3)
{
	ASSERT_ERR_CHIP((((u32)depackerinputbuff3 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_V_MATRIX_OFFSET_3_ADDR, (u32)depackerinputbuff3 << 0);
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
#define MACDSP_API_DCOC_STAND_ALONE_TRIGGER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000008D0)
#define MACDSP_API_DCOC_STAND_ALONE_TRIGGER_OFFSET      0x000008D0
#define MACDSP_API_DCOC_STAND_ALONE_TRIGGER_INDEX       0x00000234
#define MACDSP_API_DCOC_STAND_ALONE_TRIGGER_RESET       0x00000000

static inline u32 macdsp_api_dcoc_stand_alone_trigger_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_DCOC_STAND_ALONE_TRIGGER_ADDR);
}

static inline void macdsp_api_dcoc_stand_alone_trigger_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_DCOC_STAND_ALONE_TRIGGER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_DCOC_STAND_ALONE_TRIGGER_DCOC_STAND_ALONE_TRIGGER_RESERVED_0_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_DCOC_STAND_ALONE_TRIGGER_DCOC_STAND_ALONE_TRIGGER_RESERVED_0_LSB    0
#define MACDSP_API_DCOC_STAND_ALONE_TRIGGER_DCOC_STAND_ALONE_TRIGGER_RESERVED_0_WIDTH    ((u32)0x00000020)

#define MACDSP_API_DCOC_STAND_ALONE_TRIGGER_DCOC_STAND_ALONE_TRIGGER_RESERVED_0_RST    0x0

static inline u32 macdsp_api_dcoc_stand_alone_trigger_dcoc_stand_alone_trigger_reserved_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DCOC_STAND_ALONE_TRIGGER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_dcoc_stand_alone_trigger_dcoc_stand_alone_trigger_reserved_0_setf(struct cl_chip *chip, u32 dcocstandalonetriggerreserved0)
{
	ASSERT_ERR_CHIP((((u32)dcocstandalonetriggerreserved0 << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_DCOC_STAND_ALONE_TRIGGER_ADDR, (u32)dcocstandalonetriggerreserved0 << 0);
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
#define MACDSP_API_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000008D4)
#define MACDSP_API_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_OFFSET      0x000008D4
#define MACDSP_API_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_INDEX       0x00000235
#define MACDSP_API_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_RESET       0x00000000

static inline u32 macdsp_api_rx_riu_resampler_delta_offset_from_matlab_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR);
}

static inline void macdsp_api_rx_riu_resampler_delta_offset_from_matlab_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLA_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLA_LSB    0
#define MACDSP_API_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLA_WIDTH    ((u32)0x00000020)

#define MACDSP_API_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLA_RST    0x0

static inline u32 macdsp_api_rx_riu_resampler_delta_offset_from_matlab_rx_riu_resampler_delta_offset_from_matla_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_rx_riu_resampler_delta_offset_from_matlab_rx_riu_resampler_delta_offset_from_matla_setf(struct cl_chip *chip, u32 rxriuresamplerdeltaoffsetfrommatla)
{
	ASSERT_ERR_CHIP((((u32)rxriuresamplerdeltaoffsetfrommatla << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_RIU_RESAMPLER_DELTA_OFFSET_FROM_MATLAB_ADDR, (u32)rxriuresamplerdeltaoffsetfrommatla << 0);
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
#define MACDSP_API_PLDM_RIUOUT_FLAGS_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000008D8)
#define MACDSP_API_PLDM_RIUOUT_FLAGS_OFFSET      0x000008D8
#define MACDSP_API_PLDM_RIUOUT_FLAGS_INDEX       0x00000236
#define MACDSP_API_PLDM_RIUOUT_FLAGS_RESET       0x00000000

static inline u32 macdsp_api_pldm_riuout_flags_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_PLDM_RIUOUT_FLAGS_ADDR);
}

static inline void macdsp_api_pldm_riuout_flags_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_PLDM_RIUOUT_FLAGS_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_PLDM_RIUOUT_FLAGS_RIUOUT_ON_BIT    ((u32)0x00000001)
#define MACDSP_API_PLDM_RIUOUT_FLAGS_RIUOUT_ON_POS    0

#define MACDSP_API_PLDM_RIUOUT_FLAGS_RIUOUT_ON_RST    0x0

static inline u8 macdsp_api_pldm_riuout_flags_riuout_on_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_PLDM_RIUOUT_FLAGS_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macdsp_api_pldm_riuout_flags_riuout_on_setf(struct cl_chip *chip, u8 riuouton)
{
	ASSERT_ERR_CHIP((((u32)riuouton << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_PLDM_RIUOUT_FLAGS_ADDR, (u32)riuouton << 0);
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
#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000008DC)
#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_OFFSET      0x000008DC
#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_INDEX       0x00000237
#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_RESET       0x00000000

static inline u32 macdsp_api_q_gen_req_params_pldm_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_ADDR);
}

static inline void macdsp_api_q_gen_req_params_pldm_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_TARGET_REGROUPING_PLDM_MASK    ((u32)0x00030000)
#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_TARGET_REGROUPING_PLDM_LSB    16
#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_TARGET_REGROUPING_PLDM_WIDTH    ((u32)0x00000002)
#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_TARGET_NC_PLDM_MASK    ((u32)0x00007000)
#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_TARGET_NC_PLDM_LSB    12
#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_TARGET_NC_PLDM_WIDTH    ((u32)0x00000003)
#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_MIRROR_VECTOR_INDEX_PLDM_MASK    ((u32)0x00000FF0)
#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_MIRROR_VECTOR_INDEX_PLDM_LSB    4
#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_MIRROR_VECTOR_INDEX_PLDM_WIDTH    ((u32)0x00000008)
#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_V_MATRIXES_NUMBER_MINUS_ONE_PLDM_MASK    ((u32)0x0000000F)
#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_V_MATRIXES_NUMBER_MINUS_ONE_PLDM_LSB    0
#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_V_MATRIXES_NUMBER_MINUS_ONE_PLDM_WIDTH    ((u32)0x00000004)

#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_TARGET_REGROUPING_PLDM_RST    0x0
#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_TARGET_NC_PLDM_RST    0x0
#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_MIRROR_VECTOR_INDEX_PLDM_RST    0x0
#define MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_V_MATRIXES_NUMBER_MINUS_ONE_PLDM_RST    0x0

static inline void macdsp_api_q_gen_req_params_pldm_pack(struct cl_chip *chip, u8 target_regrouping_pldm, u8 target_nc_pldm, u8 mirror_vector_index_pldm, u8 v_matrixes_number_minus_one_pldm)
{
	ASSERT_ERR_CHIP((((u32)target_regrouping_pldm << 16) & ~((u32)0x00030000)) == 0);
	ASSERT_ERR_CHIP((((u32)target_nc_pldm << 12) & ~((u32)0x00007000)) == 0);
	ASSERT_ERR_CHIP((((u32)mirror_vector_index_pldm << 4) & ~((u32)0x00000FF0)) == 0);
	ASSERT_ERR_CHIP((((u32)v_matrixes_number_minus_one_pldm << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_ADDR, ((u32)target_regrouping_pldm << 16) | ((u32)target_nc_pldm << 12) | ((u32)mirror_vector_index_pldm << 4) | ((u32)v_matrixes_number_minus_one_pldm << 0));
}

static inline void macdsp_api_q_gen_req_params_pldm_unpack(struct cl_chip *chip, u8 *target_regrouping_pldm, u8 *target_nc_pldm, u8 *mirror_vector_index_pldm, u8 *v_matrixes_number_minus_one_pldm)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_ADDR);

	*target_regrouping_pldm = (local_val & ((u32)0x00030000)) >> 16;
	*target_nc_pldm = (local_val & ((u32)0x00007000)) >> 12;
	*mirror_vector_index_pldm = (local_val & ((u32)0x00000FF0)) >> 4;
	*v_matrixes_number_minus_one_pldm = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 macdsp_api_q_gen_req_params_pldm_target_regrouping_pldm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_ADDR);

	return (u8)((local_val & ((u32)0x00030000)) >> 16);
}

static inline void macdsp_api_q_gen_req_params_pldm_target_regrouping_pldm_setf(struct cl_chip *chip, u8 targetregroupingpldm)
{
	ASSERT_ERR_CHIP((((u32)targetregroupingpldm << 16) & ~((u32)0x00030000)) == 0);
	cl_reg_write(chip, MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_ADDR, (cl_reg_read(chip, MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_ADDR) & ~((u32)0x00030000)) | ((u32)targetregroupingpldm << 16));
}

static inline u8 macdsp_api_q_gen_req_params_pldm_target_nc_pldm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_ADDR);

	return (u8)((local_val & ((u32)0x00007000)) >> 12);
}

static inline void macdsp_api_q_gen_req_params_pldm_target_nc_pldm_setf(struct cl_chip *chip, u8 targetncpldm)
{
	ASSERT_ERR_CHIP((((u32)targetncpldm << 12) & ~((u32)0x00007000)) == 0);
	cl_reg_write(chip, MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_ADDR, (cl_reg_read(chip, MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_ADDR) & ~((u32)0x00007000)) | ((u32)targetncpldm << 12));
}

static inline u8 macdsp_api_q_gen_req_params_pldm_mirror_vector_index_pldm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_ADDR);

	return (u8)((local_val & ((u32)0x00000FF0)) >> 4);
}

static inline void macdsp_api_q_gen_req_params_pldm_mirror_vector_index_pldm_setf(struct cl_chip *chip, u8 mirrorvectorindexpldm)
{
	ASSERT_ERR_CHIP((((u32)mirrorvectorindexpldm << 4) & ~((u32)0x00000FF0)) == 0);
	cl_reg_write(chip, MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_ADDR, (cl_reg_read(chip, MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_ADDR) & ~((u32)0x00000FF0)) | ((u32)mirrorvectorindexpldm << 4));
}

static inline u8 macdsp_api_q_gen_req_params_pldm_v_matrixes_number_minus_one_pldm_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void macdsp_api_q_gen_req_params_pldm_v_matrixes_number_minus_one_pldm_setf(struct cl_chip *chip, u8 vmatrixesnumberminusonepldm)
{
	ASSERT_ERR_CHIP((((u32)vmatrixesnumberminusonepldm << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_ADDR, (cl_reg_read(chip, MACDSP_API_Q_GEN_REQ_PARAMS_PLDM_ADDR) & ~((u32)0x0000000F)) | ((u32)vmatrixesnumberminusonepldm << 0));
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
#define MACDSP_API_MATLAB_GENIE_CPE_STO_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000008E0)
#define MACDSP_API_MATLAB_GENIE_CPE_STO_OFFSET      0x000008E0
#define MACDSP_API_MATLAB_GENIE_CPE_STO_INDEX       0x00000238
#define MACDSP_API_MATLAB_GENIE_CPE_STO_RESET       0x00000000

static inline u32 macdsp_api_matlab_genie_cpe_sto_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_MATLAB_GENIE_CPE_STO_ADDR);
}

static inline void macdsp_api_matlab_genie_cpe_sto_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_MATLAB_GENIE_CPE_STO_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_MATLAB_GENIE_CPE_STO_MATLAB_GENIE_CPE_STO_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_MATLAB_GENIE_CPE_STO_MATLAB_GENIE_CPE_STO_LSB    0
#define MACDSP_API_MATLAB_GENIE_CPE_STO_MATLAB_GENIE_CPE_STO_WIDTH    ((u32)0x00000020)

#define MACDSP_API_MATLAB_GENIE_CPE_STO_MATLAB_GENIE_CPE_STO_RST    0x0

static inline u32 macdsp_api_matlab_genie_cpe_sto_matlab_genie_cpe_sto_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_MATLAB_GENIE_CPE_STO_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_matlab_genie_cpe_sto_matlab_genie_cpe_sto_setf(struct cl_chip *chip, u32 matlabgeniecpesto)
{
	ASSERT_ERR_CHIP((((u32)matlabgeniecpesto << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_MATLAB_GENIE_CPE_STO_ADDR, (u32)matlabgeniecpesto << 0);
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
#define MACDSP_API_GENIE_RIUOUT_ENABLE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000008E4)
#define MACDSP_API_GENIE_RIUOUT_ENABLE_OFFSET      0x000008E4
#define MACDSP_API_GENIE_RIUOUT_ENABLE_INDEX       0x00000239
#define MACDSP_API_GENIE_RIUOUT_ENABLE_RESET       0x00000000

static inline u32 macdsp_api_genie_riuout_enable_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_GENIE_RIUOUT_ENABLE_ADDR);
}

static inline void macdsp_api_genie_riuout_enable_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_GENIE_RIUOUT_ENABLE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_GENIE_RIUOUT_ENABLE_RIUOUT_ENABLE_BIT    ((u32)0x00000002)
#define MACDSP_API_GENIE_RIUOUT_ENABLE_RIUOUT_ENABLE_POS    1
#define MACDSP_API_GENIE_RIUOUT_ENABLE_GENIE_ENABLE_BIT    ((u32)0x00000001)
#define MACDSP_API_GENIE_RIUOUT_ENABLE_GENIE_ENABLE_POS    0

#define MACDSP_API_GENIE_RIUOUT_ENABLE_RIUOUT_ENABLE_RST    0x0
#define MACDSP_API_GENIE_RIUOUT_ENABLE_GENIE_ENABLE_RST    0x0

static inline void macdsp_api_genie_riuout_enable_pack(struct cl_chip *chip, u8 riuout_enable, u8 genie_enable)
{
	ASSERT_ERR_CHIP((((u32)riuout_enable << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)genie_enable << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_GENIE_RIUOUT_ENABLE_ADDR, ((u32)riuout_enable << 1) | ((u32)genie_enable << 0));
}

static inline void macdsp_api_genie_riuout_enable_unpack(struct cl_chip *chip, u8 *riuout_enable, u8 *genie_enable)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_GENIE_RIUOUT_ENABLE_ADDR);

	*riuout_enable = (local_val & ((u32)0x00000002)) >> 1;
	*genie_enable = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 macdsp_api_genie_riuout_enable_riuout_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_GENIE_RIUOUT_ENABLE_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void macdsp_api_genie_riuout_enable_riuout_enable_setf(struct cl_chip *chip, u8 riuoutenable)
{
	ASSERT_ERR_CHIP((((u32)riuoutenable << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MACDSP_API_GENIE_RIUOUT_ENABLE_ADDR, (cl_reg_read(chip, MACDSP_API_GENIE_RIUOUT_ENABLE_ADDR) & ~((u32)0x00000002)) | ((u32)riuoutenable << 1));
}

static inline u8 macdsp_api_genie_riuout_enable_genie_enable_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_GENIE_RIUOUT_ENABLE_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void macdsp_api_genie_riuout_enable_genie_enable_setf(struct cl_chip *chip, u8 genieenable)
{
	ASSERT_ERR_CHIP((((u32)genieenable << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_GENIE_RIUOUT_ENABLE_ADDR, (cl_reg_read(chip, MACDSP_API_GENIE_RIUOUT_ENABLE_ADDR) & ~((u32)0x00000001)) | ((u32)genieenable << 0));
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
#define MACDSP_API_BFR_TX_DELAY_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000008E8)
#define MACDSP_API_BFR_TX_DELAY_OFFSET      0x000008E8
#define MACDSP_API_BFR_TX_DELAY_INDEX       0x0000023A
#define MACDSP_API_BFR_TX_DELAY_RESET       0x00000000

static inline u32 macdsp_api_bfr_tx_delay_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_BFR_TX_DELAY_ADDR);
}

static inline void macdsp_api_bfr_tx_delay_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_BFR_TX_DELAY_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_BFR_TX_DELAY_SECOND_SHOT_DELAY_MASK    ((u32)0xFFFF0000)
#define MACDSP_API_BFR_TX_DELAY_SECOND_SHOT_DELAY_LSB    16
#define MACDSP_API_BFR_TX_DELAY_SECOND_SHOT_DELAY_WIDTH    ((u32)0x00000010)
#define MACDSP_API_BFR_TX_DELAY_FIRST_SHOT_DELAY_MASK    ((u32)0x0000FFFF)
#define MACDSP_API_BFR_TX_DELAY_FIRST_SHOT_DELAY_LSB    0
#define MACDSP_API_BFR_TX_DELAY_FIRST_SHOT_DELAY_WIDTH    ((u32)0x00000010)

#define MACDSP_API_BFR_TX_DELAY_SECOND_SHOT_DELAY_RST    0x0
#define MACDSP_API_BFR_TX_DELAY_FIRST_SHOT_DELAY_RST    0x0

static inline void macdsp_api_bfr_tx_delay_pack(struct cl_chip *chip, u16 second_shot_delay, u16 first_shot_delay)
{
	ASSERT_ERR_CHIP((((u32)second_shot_delay << 16) & ~((u32)0xFFFF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)first_shot_delay << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_BFR_TX_DELAY_ADDR, ((u32)second_shot_delay << 16) | ((u32)first_shot_delay << 0));
}

static inline void macdsp_api_bfr_tx_delay_unpack(struct cl_chip *chip, u16 *second_shot_delay, u16 *first_shot_delay)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_BFR_TX_DELAY_ADDR);

	*second_shot_delay = (local_val & ((u32)0xFFFF0000)) >> 16;
	*first_shot_delay = (local_val & ((u32)0x0000FFFF)) >> 0;
}

static inline u16 macdsp_api_bfr_tx_delay_second_shot_delay_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_BFR_TX_DELAY_ADDR);

	return (u16)((local_val & ((u32)0xFFFF0000)) >> 16);
}

static inline void macdsp_api_bfr_tx_delay_second_shot_delay_setf(struct cl_chip *chip, u16 secondshotdelay)
{
	ASSERT_ERR_CHIP((((u32)secondshotdelay << 16) & ~((u32)0xFFFF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_BFR_TX_DELAY_ADDR, (cl_reg_read(chip, MACDSP_API_BFR_TX_DELAY_ADDR) & ~((u32)0xFFFF0000)) | ((u32)secondshotdelay << 16));
}

static inline u16 macdsp_api_bfr_tx_delay_first_shot_delay_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_BFR_TX_DELAY_ADDR);

	return (u16)((local_val & ((u32)0x0000FFFF)) >> 0);
}

static inline void macdsp_api_bfr_tx_delay_first_shot_delay_setf(struct cl_chip *chip, u16 firstshotdelay)
{
	ASSERT_ERR_CHIP((((u32)firstshotdelay << 0) & ~((u32)0x0000FFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_BFR_TX_DELAY_ADDR, (cl_reg_read(chip, MACDSP_API_BFR_TX_DELAY_ADDR) & ~((u32)0x0000FFFF)) | ((u32)firstshotdelay << 0));
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
#define MACDSP_API_RADAR_PULSE_FIFO_1_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000008F4)
#define MACDSP_API_RADAR_PULSE_FIFO_1_OFFSET      0x000008F4
#define MACDSP_API_RADAR_PULSE_FIFO_1_INDEX       0x0000023D
#define MACDSP_API_RADAR_PULSE_FIFO_1_RESET       0x00000000

static inline u32 macdsp_api_radar_pulse_fifo_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RADAR_PULSE_FIFO_1_ADDR);
}

static inline void macdsp_api_radar_pulse_fifo_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RADAR_PULSE_FIFO_1_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RADAR_PULSE_FIFO_1_RADAR_FIFO_FRIST_VALUE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_RADAR_PULSE_FIFO_1_RADAR_FIFO_FRIST_VALUE_LSB    0
#define MACDSP_API_RADAR_PULSE_FIFO_1_RADAR_FIFO_FRIST_VALUE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_RADAR_PULSE_FIFO_1_RADAR_FIFO_FRIST_VALUE_RST    0x0

static inline u32 macdsp_api_radar_pulse_fifo_1_radar_fifo_frist_value_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RADAR_PULSE_FIFO_1_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_radar_pulse_fifo_1_radar_fifo_frist_value_setf(struct cl_chip *chip, u32 radarfifofristvalue)
{
	ASSERT_ERR_CHIP((((u32)radarfifofristvalue << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RADAR_PULSE_FIFO_1_ADDR, (u32)radarfifofristvalue << 0);
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
#define MACDSP_API_RADAR_PULSE_FIFO_2_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000008F8)
#define MACDSP_API_RADAR_PULSE_FIFO_2_OFFSET      0x000008F8
#define MACDSP_API_RADAR_PULSE_FIFO_2_INDEX       0x0000023E
#define MACDSP_API_RADAR_PULSE_FIFO_2_RESET       0x00000000

static inline u32 macdsp_api_radar_pulse_fifo_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RADAR_PULSE_FIFO_2_ADDR);
}

static inline void macdsp_api_radar_pulse_fifo_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RADAR_PULSE_FIFO_2_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RADAR_PULSE_FIFO_2_RADAR_FIFO_SECOND_VALUE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_RADAR_PULSE_FIFO_2_RADAR_FIFO_SECOND_VALUE_LSB    0
#define MACDSP_API_RADAR_PULSE_FIFO_2_RADAR_FIFO_SECOND_VALUE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_RADAR_PULSE_FIFO_2_RADAR_FIFO_SECOND_VALUE_RST    0x0

static inline u32 macdsp_api_radar_pulse_fifo_2_radar_fifo_second_value_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RADAR_PULSE_FIFO_2_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_radar_pulse_fifo_2_radar_fifo_second_value_setf(struct cl_chip *chip, u32 radarfifosecondvalue)
{
	ASSERT_ERR_CHIP((((u32)radarfifosecondvalue << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RADAR_PULSE_FIFO_2_ADDR, (u32)radarfifosecondvalue << 0);
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
#define MACDSP_API_RADAR_CTRL_0_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000008FC)
#define MACDSP_API_RADAR_CTRL_0_OFFSET      0x000008FC
#define MACDSP_API_RADAR_CTRL_0_INDEX       0x0000023F
#define MACDSP_API_RADAR_CTRL_0_RESET       0x00000C00

static inline u32 macdsp_api_radar_ctrl_0_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RADAR_CTRL_0_ADDR);
}

static inline void macdsp_api_radar_ctrl_0_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RADAR_CTRL_0_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RADAR_CTRL_0_SEC_PATH_EST_ANT_MRC_FLOW_BIT    ((u32)0x00000800)
#define MACDSP_API_RADAR_CTRL_0_SEC_PATH_EST_ANT_MRC_FLOW_POS    11
#define MACDSP_API_RADAR_CTRL_0_SEC_PATH_EST_MRC_FLOW_EN_BIT    ((u32)0x00000400)
#define MACDSP_API_RADAR_CTRL_0_SEC_PATH_EST_MRC_FLOW_EN_POS    10
#define MACDSP_API_RADAR_CTRL_0_ANT_NUM_TO_PROC_BIT    ((u32)0x00000200)
#define MACDSP_API_RADAR_CTRL_0_ANT_NUM_TO_PROC_POS    9
#define MACDSP_API_RADAR_CTRL_0_MRC_EN_BIT    ((u32)0x00000100)
#define MACDSP_API_RADAR_CTRL_0_MRC_EN_POS    8
#define MACDSP_API_RADAR_CTRL_0_SEC_ANT_SEL_MASK    ((u32)0x000000E0)
#define MACDSP_API_RADAR_CTRL_0_SEC_ANT_SEL_LSB    5
#define MACDSP_API_RADAR_CTRL_0_SEC_ANT_SEL_WIDTH    ((u32)0x00000003)
#define MACDSP_API_RADAR_CTRL_0_MAIN_ANT_SEL_MASK    ((u32)0x0000001C)
#define MACDSP_API_RADAR_CTRL_0_MAIN_ANT_SEL_LSB    2
#define MACDSP_API_RADAR_CTRL_0_MAIN_ANT_SEL_WIDTH    ((u32)0x00000003)
#define MACDSP_API_RADAR_CTRL_0_RADAR_SAMPLE_RATE_MASK    ((u32)0x00000003)
#define MACDSP_API_RADAR_CTRL_0_RADAR_SAMPLE_RATE_LSB    0
#define MACDSP_API_RADAR_CTRL_0_RADAR_SAMPLE_RATE_WIDTH    ((u32)0x00000002)

#define MACDSP_API_RADAR_CTRL_0_SEC_PATH_EST_ANT_MRC_FLOW_RST    0x1
#define MACDSP_API_RADAR_CTRL_0_SEC_PATH_EST_MRC_FLOW_EN_RST    0x1
#define MACDSP_API_RADAR_CTRL_0_ANT_NUM_TO_PROC_RST    0x0
#define MACDSP_API_RADAR_CTRL_0_MRC_EN_RST    0x0
#define MACDSP_API_RADAR_CTRL_0_SEC_ANT_SEL_RST    0x0
#define MACDSP_API_RADAR_CTRL_0_MAIN_ANT_SEL_RST    0x0
#define MACDSP_API_RADAR_CTRL_0_RADAR_SAMPLE_RATE_RST    0x0

static inline void macdsp_api_radar_ctrl_0_pack(struct cl_chip *chip, u8 sec_path_est_ant_mrc_flow, u8 sec_path_est_mrc_flow_en, u8 ant_num_to_proc, u8 mrc_en, u8 sec_ant_sel, u8 main_ant_sel, u8 radar_sample_rate)
{
	ASSERT_ERR_CHIP((((u32)sec_path_est_ant_mrc_flow << 11) & ~((u32)0x00000800)) == 0);
	ASSERT_ERR_CHIP((((u32)sec_path_est_mrc_flow_en << 10) & ~((u32)0x00000400)) == 0);
	ASSERT_ERR_CHIP((((u32)ant_num_to_proc << 9) & ~((u32)0x00000200)) == 0);
	ASSERT_ERR_CHIP((((u32)mrc_en << 8) & ~((u32)0x00000100)) == 0);
	ASSERT_ERR_CHIP((((u32)sec_ant_sel << 5) & ~((u32)0x000000E0)) == 0);
	ASSERT_ERR_CHIP((((u32)main_ant_sel << 2) & ~((u32)0x0000001C)) == 0);
	ASSERT_ERR_CHIP((((u32)radar_sample_rate << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACDSP_API_RADAR_CTRL_0_ADDR, ((u32)sec_path_est_ant_mrc_flow << 11) | ((u32)sec_path_est_mrc_flow_en << 10) | ((u32)ant_num_to_proc << 9) | ((u32)mrc_en << 8) | ((u32)sec_ant_sel << 5) | ((u32)main_ant_sel << 2) | ((u32)radar_sample_rate << 0));
}

static inline void macdsp_api_radar_ctrl_0_unpack(struct cl_chip *chip, u8 *sec_path_est_ant_mrc_flow, u8 *sec_path_est_mrc_flow_en, u8 *ant_num_to_proc, u8 *mrc_en, u8 *sec_ant_sel, u8 *main_ant_sel, u8 *radar_sample_rate)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RADAR_CTRL_0_ADDR);

	*sec_path_est_ant_mrc_flow = (local_val & ((u32)0x00000800)) >> 11;
	*sec_path_est_mrc_flow_en = (local_val & ((u32)0x00000400)) >> 10;
	*ant_num_to_proc = (local_val & ((u32)0x00000200)) >> 9;
	*mrc_en = (local_val & ((u32)0x00000100)) >> 8;
	*sec_ant_sel = (local_val & ((u32)0x000000E0)) >> 5;
	*main_ant_sel = (local_val & ((u32)0x0000001C)) >> 2;
	*radar_sample_rate = (local_val & ((u32)0x00000003)) >> 0;
}

static inline u8 macdsp_api_radar_ctrl_0_sec_path_est_ant_mrc_flow_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RADAR_CTRL_0_ADDR);

	return (u8)((local_val & ((u32)0x00000800)) >> 11);
}

static inline void macdsp_api_radar_ctrl_0_sec_path_est_ant_mrc_flow_setf(struct cl_chip *chip, u8 secpathestantmrcflow)
{
	ASSERT_ERR_CHIP((((u32)secpathestantmrcflow << 11) & ~((u32)0x00000800)) == 0);
	cl_reg_write(chip, MACDSP_API_RADAR_CTRL_0_ADDR, (cl_reg_read(chip, MACDSP_API_RADAR_CTRL_0_ADDR) & ~((u32)0x00000800)) | ((u32)secpathestantmrcflow << 11));
}

static inline u8 macdsp_api_radar_ctrl_0_sec_path_est_mrc_flow_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RADAR_CTRL_0_ADDR);

	return (u8)((local_val & ((u32)0x00000400)) >> 10);
}

static inline void macdsp_api_radar_ctrl_0_sec_path_est_mrc_flow_en_setf(struct cl_chip *chip, u8 secpathestmrcflowen)
{
	ASSERT_ERR_CHIP((((u32)secpathestmrcflowen << 10) & ~((u32)0x00000400)) == 0);
	cl_reg_write(chip, MACDSP_API_RADAR_CTRL_0_ADDR, (cl_reg_read(chip, MACDSP_API_RADAR_CTRL_0_ADDR) & ~((u32)0x00000400)) | ((u32)secpathestmrcflowen << 10));
}

static inline u8 macdsp_api_radar_ctrl_0_ant_num_to_proc_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RADAR_CTRL_0_ADDR);

	return (u8)((local_val & ((u32)0x00000200)) >> 9);
}

static inline void macdsp_api_radar_ctrl_0_ant_num_to_proc_setf(struct cl_chip *chip, u8 antnumtoproc)
{
	ASSERT_ERR_CHIP((((u32)antnumtoproc << 9) & ~((u32)0x00000200)) == 0);
	cl_reg_write(chip, MACDSP_API_RADAR_CTRL_0_ADDR, (cl_reg_read(chip, MACDSP_API_RADAR_CTRL_0_ADDR) & ~((u32)0x00000200)) | ((u32)antnumtoproc << 9));
}

static inline u8 macdsp_api_radar_ctrl_0_mrc_en_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RADAR_CTRL_0_ADDR);

	return (u8)((local_val & ((u32)0x00000100)) >> 8);
}

static inline void macdsp_api_radar_ctrl_0_mrc_en_setf(struct cl_chip *chip, u8 mrcen)
{
	ASSERT_ERR_CHIP((((u32)mrcen << 8) & ~((u32)0x00000100)) == 0);
	cl_reg_write(chip, MACDSP_API_RADAR_CTRL_0_ADDR, (cl_reg_read(chip, MACDSP_API_RADAR_CTRL_0_ADDR) & ~((u32)0x00000100)) | ((u32)mrcen << 8));
}

static inline u8 macdsp_api_radar_ctrl_0_sec_ant_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RADAR_CTRL_0_ADDR);

	return (u8)((local_val & ((u32)0x000000E0)) >> 5);
}

static inline void macdsp_api_radar_ctrl_0_sec_ant_sel_setf(struct cl_chip *chip, u8 secantsel)
{
	ASSERT_ERR_CHIP((((u32)secantsel << 5) & ~((u32)0x000000E0)) == 0);
	cl_reg_write(chip, MACDSP_API_RADAR_CTRL_0_ADDR, (cl_reg_read(chip, MACDSP_API_RADAR_CTRL_0_ADDR) & ~((u32)0x000000E0)) | ((u32)secantsel << 5));
}

static inline u8 macdsp_api_radar_ctrl_0_main_ant_sel_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RADAR_CTRL_0_ADDR);

	return (u8)((local_val & ((u32)0x0000001C)) >> 2);
}

static inline void macdsp_api_radar_ctrl_0_main_ant_sel_setf(struct cl_chip *chip, u8 mainantsel)
{
	ASSERT_ERR_CHIP((((u32)mainantsel << 2) & ~((u32)0x0000001C)) == 0);
	cl_reg_write(chip, MACDSP_API_RADAR_CTRL_0_ADDR, (cl_reg_read(chip, MACDSP_API_RADAR_CTRL_0_ADDR) & ~((u32)0x0000001C)) | ((u32)mainantsel << 2));
}

static inline u8 macdsp_api_radar_ctrl_0_radar_sample_rate_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RADAR_CTRL_0_ADDR);

	return (u8)((local_val & ((u32)0x00000003)) >> 0);
}

static inline void macdsp_api_radar_ctrl_0_radar_sample_rate_setf(struct cl_chip *chip, u8 radarsamplerate)
{
	ASSERT_ERR_CHIP((((u32)radarsamplerate << 0) & ~((u32)0x00000003)) == 0);
	cl_reg_write(chip, MACDSP_API_RADAR_CTRL_0_ADDR, (cl_reg_read(chip, MACDSP_API_RADAR_CTRL_0_ADDR) & ~((u32)0x00000003)) | ((u32)radarsamplerate << 0));
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
#define MACDSP_API_LCU_PRE_CONFIG_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000900)
#define MACDSP_API_LCU_PRE_CONFIG_OFFSET      0x00000900
#define MACDSP_API_LCU_PRE_CONFIG_INDEX       0x00000240
#define MACDSP_API_LCU_PRE_CONFIG_RESET       0x00000000

static inline u32 macdsp_api_lcu_pre_config_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_LCU_PRE_CONFIG_ADDR);
}

static inline void macdsp_api_lcu_pre_config_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_LCU_PRE_CONFIG_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_LCU_PRE_CONFIG_PRE_CONFIG_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_LCU_PRE_CONFIG_PRE_CONFIG_LSB    0
#define MACDSP_API_LCU_PRE_CONFIG_PRE_CONFIG_WIDTH    ((u32)0x00000020)

#define MACDSP_API_LCU_PRE_CONFIG_PRE_CONFIG_RST    0x0

static inline u32 macdsp_api_lcu_pre_config_pre_config_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LCU_PRE_CONFIG_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_lcu_pre_config_pre_config_setf(struct cl_chip *chip, u32 preconfig)
{
	ASSERT_ERR_CHIP((((u32)preconfig << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_LCU_PRE_CONFIG_ADDR, (u32)preconfig << 0);
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
#define MACDSP_API_LCU_PRAM_FOR_TRIGGER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000904)
#define MACDSP_API_LCU_PRAM_FOR_TRIGGER_OFFSET      0x00000904
#define MACDSP_API_LCU_PRAM_FOR_TRIGGER_INDEX       0x00000241
#define MACDSP_API_LCU_PRAM_FOR_TRIGGER_RESET       0x00000000

static inline u32 macdsp_api_lcu_pram_for_trigger_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_LCU_PRAM_FOR_TRIGGER_ADDR);
}

static inline void macdsp_api_lcu_pram_for_trigger_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_LCU_PRAM_FOR_TRIGGER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_LCU_PRAM_FOR_TRIGGER_POFG_PRAM_MODE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_LCU_PRAM_FOR_TRIGGER_POFG_PRAM_MODE_LSB    0
#define MACDSP_API_LCU_PRAM_FOR_TRIGGER_POFG_PRAM_MODE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_LCU_PRAM_FOR_TRIGGER_POFG_PRAM_MODE_RST    0x0

static inline u32 macdsp_api_lcu_pram_for_trigger_pofg_pram_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LCU_PRAM_FOR_TRIGGER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_lcu_pram_for_trigger_pofg_pram_mode_setf(struct cl_chip *chip, u32 pofgprammode)
{
	ASSERT_ERR_CHIP((((u32)pofgprammode << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_LCU_PRAM_FOR_TRIGGER_ADDR, (u32)pofgprammode << 0);
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
#define MACDSP_API_LCU_EVM_DROP_LEVEL_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000908)
#define MACDSP_API_LCU_EVM_DROP_LEVEL_OFFSET      0x00000908
#define MACDSP_API_LCU_EVM_DROP_LEVEL_INDEX       0x00000242
#define MACDSP_API_LCU_EVM_DROP_LEVEL_RESET       0x00000000

static inline u32 macdsp_api_lcu_evm_drop_level_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_LCU_EVM_DROP_LEVEL_ADDR);
}

static inline void macdsp_api_lcu_evm_drop_level_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_LCU_EVM_DROP_LEVEL_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_LCU_EVM_DROP_LEVEL_EVM_DROP_LEVEL_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_LCU_EVM_DROP_LEVEL_EVM_DROP_LEVEL_LSB    0
#define MACDSP_API_LCU_EVM_DROP_LEVEL_EVM_DROP_LEVEL_WIDTH    ((u32)0x00000020)

#define MACDSP_API_LCU_EVM_DROP_LEVEL_EVM_DROP_LEVEL_RST    0x0

static inline u32 macdsp_api_lcu_evm_drop_level_evm_drop_level_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LCU_EVM_DROP_LEVEL_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_lcu_evm_drop_level_evm_drop_level_setf(struct cl_chip *chip, u32 evmdroplevel)
{
	ASSERT_ERR_CHIP((((u32)evmdroplevel << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_LCU_EVM_DROP_LEVEL_ADDR, (u32)evmdroplevel << 0);
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
#define MACDSP_API_LCU_H_BUF_USER_NUM_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000090C)
#define MACDSP_API_LCU_H_BUF_USER_NUM_OFFSET      0x0000090C
#define MACDSP_API_LCU_H_BUF_USER_NUM_INDEX       0x00000243
#define MACDSP_API_LCU_H_BUF_USER_NUM_RESET       0x00000000

static inline u32 macdsp_api_lcu_h_buf_user_num_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_LCU_H_BUF_USER_NUM_ADDR);
}

static inline void macdsp_api_lcu_h_buf_user_num_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_LCU_H_BUF_USER_NUM_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_LCU_H_BUF_USER_NUM_H_BUF_USER_NUM_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_LCU_H_BUF_USER_NUM_H_BUF_USER_NUM_LSB    0
#define MACDSP_API_LCU_H_BUF_USER_NUM_H_BUF_USER_NUM_WIDTH    ((u32)0x00000020)

#define MACDSP_API_LCU_H_BUF_USER_NUM_H_BUF_USER_NUM_RST    0x0

static inline u32 macdsp_api_lcu_h_buf_user_num_h_buf_user_num_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LCU_H_BUF_USER_NUM_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_lcu_h_buf_user_num_h_buf_user_num_setf(struct cl_chip *chip, u32 hbufusernum)
{
	ASSERT_ERR_CHIP((((u32)hbufusernum << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_LCU_H_BUF_USER_NUM_ADDR, (u32)hbufusernum << 0);
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
#define MACDSP_API_LCU_STOP_TRIGGER_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000918)
#define MACDSP_API_LCU_STOP_TRIGGER_OFFSET      0x00000918
#define MACDSP_API_LCU_STOP_TRIGGER_INDEX       0x00000246
#define MACDSP_API_LCU_STOP_TRIGGER_RESET       0x00000000

static inline u32 macdsp_api_lcu_stop_trigger_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_LCU_STOP_TRIGGER_ADDR);
}

static inline void macdsp_api_lcu_stop_trigger_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_LCU_STOP_TRIGGER_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_LCU_STOP_TRIGGER_STOP_TRIGGER_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_LCU_STOP_TRIGGER_STOP_TRIGGER_LSB    0
#define MACDSP_API_LCU_STOP_TRIGGER_STOP_TRIGGER_WIDTH    ((u32)0x00000020)

#define MACDSP_API_LCU_STOP_TRIGGER_STOP_TRIGGER_RST    0x0

static inline u32 macdsp_api_lcu_stop_trigger_stop_trigger_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LCU_STOP_TRIGGER_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_lcu_stop_trigger_stop_trigger_setf(struct cl_chip *chip, u32 stoptrigger)
{
	ASSERT_ERR_CHIP((((u32)stoptrigger << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_LCU_STOP_TRIGGER_ADDR, (u32)stoptrigger << 0);
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
#define MACDSP_API_AGC_GAIN_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000968)
#define MACDSP_API_AGC_GAIN_OFFSET      0x00000968
#define MACDSP_API_AGC_GAIN_INDEX       0x0000025A
#define MACDSP_API_AGC_GAIN_RESET       0x00000000

static inline u32 macdsp_api_agc_gain_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_AGC_GAIN_ADDR);
}

static inline void macdsp_api_agc_gain_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_AGC_GAIN_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_AGC_GAIN_AGCGAIN_3_MASK    ((u32)0xFF000000)
#define MACDSP_API_AGC_GAIN_AGCGAIN_3_LSB    24
#define MACDSP_API_AGC_GAIN_AGCGAIN_3_WIDTH    ((u32)0x00000008)
#define MACDSP_API_AGC_GAIN_AGCGAIN_2_MASK    ((u32)0x00FF0000)
#define MACDSP_API_AGC_GAIN_AGCGAIN_2_LSB    16
#define MACDSP_API_AGC_GAIN_AGCGAIN_2_WIDTH    ((u32)0x00000008)
#define MACDSP_API_AGC_GAIN_AGCGAIN_1_MASK    ((u32)0x0000FF00)
#define MACDSP_API_AGC_GAIN_AGCGAIN_1_LSB    8
#define MACDSP_API_AGC_GAIN_AGCGAIN_1_WIDTH    ((u32)0x00000008)
#define MACDSP_API_AGC_GAIN_AGCGAIN_0_MASK    ((u32)0x000000FF)
#define MACDSP_API_AGC_GAIN_AGCGAIN_0_LSB    0
#define MACDSP_API_AGC_GAIN_AGCGAIN_0_WIDTH    ((u32)0x00000008)

#define MACDSP_API_AGC_GAIN_AGCGAIN_3_RST    0x0
#define MACDSP_API_AGC_GAIN_AGCGAIN_2_RST    0x0
#define MACDSP_API_AGC_GAIN_AGCGAIN_1_RST    0x0
#define MACDSP_API_AGC_GAIN_AGCGAIN_0_RST    0x0

static inline void macdsp_api_agc_gain_pack(struct cl_chip *chip, u8 agcgain3, u8 agcgain2, u8 agcgain1, u8 agcgain0)
{
	ASSERT_ERR_CHIP((((u32)agcgain3 << 24) & ~((u32)0xFF000000)) == 0);
	ASSERT_ERR_CHIP((((u32)agcgain2 << 16) & ~((u32)0x00FF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)agcgain1 << 8) & ~((u32)0x0000FF00)) == 0);
	ASSERT_ERR_CHIP((((u32)agcgain0 << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MACDSP_API_AGC_GAIN_ADDR, ((u32)agcgain3 << 24) | ((u32)agcgain2 << 16) | ((u32)agcgain1 << 8) | ((u32)agcgain0 << 0));
}

static inline void macdsp_api_agc_gain_unpack(struct cl_chip *chip, u8 *agcgain3, u8 *agcgain2, u8 *agcgain1, u8 *agcgain0)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_AGC_GAIN_ADDR);

	*agcgain3 = (local_val & ((u32)0xFF000000)) >> 24;
	*agcgain2 = (local_val & ((u32)0x00FF0000)) >> 16;
	*agcgain1 = (local_val & ((u32)0x0000FF00)) >> 8;
	*agcgain0 = (local_val & ((u32)0x000000FF)) >> 0;
}

static inline u8 macdsp_api_agc_gain_agcgain_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_AGC_GAIN_ADDR);

	return (u8)((local_val & ((u32)0xFF000000)) >> 24);
}

static inline void macdsp_api_agc_gain_agcgain_3_setf(struct cl_chip *chip, u8 agcgain3)
{
	ASSERT_ERR_CHIP((((u32)agcgain3 << 24) & ~((u32)0xFF000000)) == 0);
	cl_reg_write(chip, MACDSP_API_AGC_GAIN_ADDR, (cl_reg_read(chip, MACDSP_API_AGC_GAIN_ADDR) & ~((u32)0xFF000000)) | ((u32)agcgain3 << 24));
}

static inline u8 macdsp_api_agc_gain_agcgain_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_AGC_GAIN_ADDR);

	return (u8)((local_val & ((u32)0x00FF0000)) >> 16);
}

static inline void macdsp_api_agc_gain_agcgain_2_setf(struct cl_chip *chip, u8 agcgain2)
{
	ASSERT_ERR_CHIP((((u32)agcgain2 << 16) & ~((u32)0x00FF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_AGC_GAIN_ADDR, (cl_reg_read(chip, MACDSP_API_AGC_GAIN_ADDR) & ~((u32)0x00FF0000)) | ((u32)agcgain2 << 16));
}

static inline u8 macdsp_api_agc_gain_agcgain_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_AGC_GAIN_ADDR);

	return (u8)((local_val & ((u32)0x0000FF00)) >> 8);
}

static inline void macdsp_api_agc_gain_agcgain_1_setf(struct cl_chip *chip, u8 agcgain1)
{
	ASSERT_ERR_CHIP((((u32)agcgain1 << 8) & ~((u32)0x0000FF00)) == 0);
	cl_reg_write(chip, MACDSP_API_AGC_GAIN_ADDR, (cl_reg_read(chip, MACDSP_API_AGC_GAIN_ADDR) & ~((u32)0x0000FF00)) | ((u32)agcgain1 << 8));
}

static inline u8 macdsp_api_agc_gain_agcgain_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_AGC_GAIN_ADDR);

	return (u8)((local_val & ((u32)0x000000FF)) >> 0);
}

static inline void macdsp_api_agc_gain_agcgain_0_setf(struct cl_chip *chip, u8 agcgain0)
{
	ASSERT_ERR_CHIP((((u32)agcgain0 << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MACDSP_API_AGC_GAIN_ADDR, (cl_reg_read(chip, MACDSP_API_AGC_GAIN_ADDR) & ~((u32)0x000000FF)) | ((u32)agcgain0 << 0));
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
#define MACDSP_API_LNA_VGA_0_2_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000096C)
#define MACDSP_API_LNA_VGA_0_2_OFFSET      0x0000096C
#define MACDSP_API_LNA_VGA_0_2_INDEX       0x0000025B
#define MACDSP_API_LNA_VGA_0_2_RESET       0x00000000

static inline u32 macdsp_api_lna_vga_0_2_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR);
}

static inline void macdsp_api_lna_vga_0_2_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_LNA_VGA_0_2_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_2_EXTLNA_BIT    ((u32)0x10000000)
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_2_EXTLNA_POS    28
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_2_LNA_MASK    ((u32)0x0E000000)
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_2_LNA_LSB    25
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_2_LNA_WIDTH    ((u32)0x00000003)
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_2_VGA_MASK    ((u32)0x01F00000)
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_2_VGA_LSB    20
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_2_VGA_WIDTH    ((u32)0x00000005)
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_1_EXTLNA_BIT    ((u32)0x00040000)
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_1_EXTLNA_POS    18
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_1_LNA_MASK    ((u32)0x00038000)
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_1_LNA_LSB    15
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_1_LNA_WIDTH    ((u32)0x00000003)
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_1_VGA_MASK    ((u32)0x00007C00)
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_1_VGA_LSB    10
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_1_VGA_WIDTH    ((u32)0x00000005)
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_0_EXTLNA_BIT    ((u32)0x00000100)
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_0_EXTLNA_POS    8
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_0_LNA_MASK    ((u32)0x000000E0)
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_0_LNA_LSB    5
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_0_LNA_WIDTH    ((u32)0x00000003)
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_0_VGA_MASK    ((u32)0x0000001F)
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_0_VGA_LSB    0
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_0_VGA_WIDTH    ((u32)0x00000005)

#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_2_EXTLNA_RST    0x0
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_2_LNA_RST    0x0
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_2_VGA_RST    0x0
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_1_EXTLNA_RST    0x0
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_1_LNA_RST    0x0
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_1_VGA_RST    0x0
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_0_EXTLNA_RST    0x0
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_0_LNA_RST    0x0
#define MACDSP_API_LNA_VGA_0_2_AGCRFGAIN_0_VGA_RST    0x0

static inline void macdsp_api_lna_vga_0_2_pack(struct cl_chip *chip, u8 agcrfgain2_extlna, u8 agcrfgain2_lna, u8 agcrfgain2_vga, u8 agcrfgain1_extlna, u8 agcrfgain1_lna, u8 agcrfgain1_vga, u8 agcrfgain0_extlna, u8 agcrfgain0_lna, u8 agcrfgain0_vga)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain2_extlna << 28) & ~((u32)0x10000000)) == 0);
	ASSERT_ERR_CHIP((((u32)agcrfgain2_lna << 25) & ~((u32)0x0E000000)) == 0);
	ASSERT_ERR_CHIP((((u32)agcrfgain2_vga << 20) & ~((u32)0x01F00000)) == 0);
	ASSERT_ERR_CHIP((((u32)agcrfgain1_extlna << 18) & ~((u32)0x00040000)) == 0);
	ASSERT_ERR_CHIP((((u32)agcrfgain1_lna << 15) & ~((u32)0x00038000)) == 0);
	ASSERT_ERR_CHIP((((u32)agcrfgain1_vga << 10) & ~((u32)0x00007C00)) == 0);
	ASSERT_ERR_CHIP((((u32)agcrfgain0_extlna << 8) & ~((u32)0x00000100)) == 0);
	ASSERT_ERR_CHIP((((u32)agcrfgain0_lna << 5) & ~((u32)0x000000E0)) == 0);
	ASSERT_ERR_CHIP((((u32)agcrfgain0_vga << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_0_2_ADDR, ((u32)agcrfgain2_extlna << 28) | ((u32)agcrfgain2_lna << 25) | ((u32)agcrfgain2_vga << 20) | ((u32)agcrfgain1_extlna << 18) | ((u32)agcrfgain1_lna << 15) | ((u32)agcrfgain1_vga << 10) | ((u32)agcrfgain0_extlna << 8) | ((u32)agcrfgain0_lna << 5) | ((u32)agcrfgain0_vga << 0));
}

static inline void macdsp_api_lna_vga_0_2_unpack(struct cl_chip *chip, u8 *agcrfgain2_extlna, u8 *agcrfgain2_lna, u8 *agcrfgain2_vga, u8 *agcrfgain1_extlna, u8 *agcrfgain1_lna, u8 *agcrfgain1_vga, u8 *agcrfgain0_extlna, u8 *agcrfgain0_lna, u8 *agcrfgain0_vga)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR);

	*agcrfgain2_extlna = (local_val & ((u32)0x10000000)) >> 28;
	*agcrfgain2_lna = (local_val & ((u32)0x0E000000)) >> 25;
	*agcrfgain2_vga = (local_val & ((u32)0x01F00000)) >> 20;
	*agcrfgain1_extlna = (local_val & ((u32)0x00040000)) >> 18;
	*agcrfgain1_lna = (local_val & ((u32)0x00038000)) >> 15;
	*agcrfgain1_vga = (local_val & ((u32)0x00007C00)) >> 10;
	*agcrfgain0_extlna = (local_val & ((u32)0x00000100)) >> 8;
	*agcrfgain0_lna = (local_val & ((u32)0x000000E0)) >> 5;
	*agcrfgain0_vga = (local_val & ((u32)0x0000001F)) >> 0;
}

static inline u8 macdsp_api_lna_vga_0_2_agcrfgain_2_extlna_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR);

	return (u8)((local_val & ((u32)0x10000000)) >> 28);
}

static inline void macdsp_api_lna_vga_0_2_agcrfgain_2_extlna_setf(struct cl_chip *chip, u8 agcrfgain2extlna)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain2extlna << 28) & ~((u32)0x10000000)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_0_2_ADDR, (cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR) & ~((u32)0x10000000)) | ((u32)agcrfgain2extlna << 28));
}

static inline u8 macdsp_api_lna_vga_0_2_agcrfgain_2_lna_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR);

	return (u8)((local_val & ((u32)0x0E000000)) >> 25);
}

static inline void macdsp_api_lna_vga_0_2_agcrfgain_2_lna_setf(struct cl_chip *chip, u8 agcrfgain2lna)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain2lna << 25) & ~((u32)0x0E000000)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_0_2_ADDR, (cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR) & ~((u32)0x0E000000)) | ((u32)agcrfgain2lna << 25));
}

static inline u8 macdsp_api_lna_vga_0_2_agcrfgain_2_vga_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR);

	return (u8)((local_val & ((u32)0x01F00000)) >> 20);
}

static inline void macdsp_api_lna_vga_0_2_agcrfgain_2_vga_setf(struct cl_chip *chip, u8 agcrfgain2vga)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain2vga << 20) & ~((u32)0x01F00000)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_0_2_ADDR, (cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR) & ~((u32)0x01F00000)) | ((u32)agcrfgain2vga << 20));
}

static inline u8 macdsp_api_lna_vga_0_2_agcrfgain_1_extlna_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR);

	return (u8)((local_val & ((u32)0x00040000)) >> 18);
}

static inline void macdsp_api_lna_vga_0_2_agcrfgain_1_extlna_setf(struct cl_chip *chip, u8 agcrfgain1extlna)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain1extlna << 18) & ~((u32)0x00040000)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_0_2_ADDR, (cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR) & ~((u32)0x00040000)) | ((u32)agcrfgain1extlna << 18));
}

static inline u8 macdsp_api_lna_vga_0_2_agcrfgain_1_lna_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR);

	return (u8)((local_val & ((u32)0x00038000)) >> 15);
}

static inline void macdsp_api_lna_vga_0_2_agcrfgain_1_lna_setf(struct cl_chip *chip, u8 agcrfgain1lna)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain1lna << 15) & ~((u32)0x00038000)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_0_2_ADDR, (cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR) & ~((u32)0x00038000)) | ((u32)agcrfgain1lna << 15));
}

static inline u8 macdsp_api_lna_vga_0_2_agcrfgain_1_vga_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR);

	return (u8)((local_val & ((u32)0x00007C00)) >> 10);
}

static inline void macdsp_api_lna_vga_0_2_agcrfgain_1_vga_setf(struct cl_chip *chip, u8 agcrfgain1vga)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain1vga << 10) & ~((u32)0x00007C00)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_0_2_ADDR, (cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR) & ~((u32)0x00007C00)) | ((u32)agcrfgain1vga << 10));
}

static inline u8 macdsp_api_lna_vga_0_2_agcrfgain_0_extlna_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR);

	return (u8)((local_val & ((u32)0x00000100)) >> 8);
}

static inline void macdsp_api_lna_vga_0_2_agcrfgain_0_extlna_setf(struct cl_chip *chip, u8 agcrfgain0extlna)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain0extlna << 8) & ~((u32)0x00000100)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_0_2_ADDR, (cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR) & ~((u32)0x00000100)) | ((u32)agcrfgain0extlna << 8));
}

static inline u8 macdsp_api_lna_vga_0_2_agcrfgain_0_lna_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR);

	return (u8)((local_val & ((u32)0x000000E0)) >> 5);
}

static inline void macdsp_api_lna_vga_0_2_agcrfgain_0_lna_setf(struct cl_chip *chip, u8 agcrfgain0lna)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain0lna << 5) & ~((u32)0x000000E0)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_0_2_ADDR, (cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR) & ~((u32)0x000000E0)) | ((u32)agcrfgain0lna << 5));
}

static inline u8 macdsp_api_lna_vga_0_2_agcrfgain_0_vga_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR);

	return (u8)((local_val & ((u32)0x0000001F)) >> 0);
}

static inline void macdsp_api_lna_vga_0_2_agcrfgain_0_vga_setf(struct cl_chip *chip, u8 agcrfgain0vga)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain0vga << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_0_2_ADDR, (cl_reg_read(chip, MACDSP_API_LNA_VGA_0_2_ADDR) & ~((u32)0x0000001F)) | ((u32)agcrfgain0vga << 0));
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
#define MACDSP_API_ADC_POW_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000970)
#define MACDSP_API_ADC_POW_OFFSET      0x00000970
#define MACDSP_API_ADC_POW_INDEX       0x0000025C
#define MACDSP_API_ADC_POW_RESET       0x00000000

static inline u32 macdsp_api_adc_pow_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_ADC_POW_ADDR);
}

static inline void macdsp_api_adc_pow_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_ADC_POW_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_ADC_POW_ADCPOWDBV_3_MASK    ((u32)0x7F000000)
#define MACDSP_API_ADC_POW_ADCPOWDBV_3_LSB    24
#define MACDSP_API_ADC_POW_ADCPOWDBV_3_WIDTH    ((u32)0x00000007)
#define MACDSP_API_ADC_POW_ADCPOWDBV_2_MASK    ((u32)0x007F0000)
#define MACDSP_API_ADC_POW_ADCPOWDBV_2_LSB    16
#define MACDSP_API_ADC_POW_ADCPOWDBV_2_WIDTH    ((u32)0x00000007)
#define MACDSP_API_ADC_POW_ADCPOWDBV_1_MASK    ((u32)0x00007F00)
#define MACDSP_API_ADC_POW_ADCPOWDBV_1_LSB    8
#define MACDSP_API_ADC_POW_ADCPOWDBV_1_WIDTH    ((u32)0x00000007)
#define MACDSP_API_ADC_POW_ADCPOWDBV_0_MASK    ((u32)0x0000007F)
#define MACDSP_API_ADC_POW_ADCPOWDBV_0_LSB    0
#define MACDSP_API_ADC_POW_ADCPOWDBV_0_WIDTH    ((u32)0x00000007)

#define MACDSP_API_ADC_POW_ADCPOWDBV_3_RST    0x0
#define MACDSP_API_ADC_POW_ADCPOWDBV_2_RST    0x0
#define MACDSP_API_ADC_POW_ADCPOWDBV_1_RST    0x0
#define MACDSP_API_ADC_POW_ADCPOWDBV_0_RST    0x0

static inline void macdsp_api_adc_pow_pack(struct cl_chip *chip, u8 adcpowdbv3, u8 adcpowdbv2, u8 adcpowdbv1, u8 adcpowdbv0)
{
	ASSERT_ERR_CHIP((((u32)adcpowdbv3 << 24) & ~((u32)0x7F000000)) == 0);
	ASSERT_ERR_CHIP((((u32)adcpowdbv2 << 16) & ~((u32)0x007F0000)) == 0);
	ASSERT_ERR_CHIP((((u32)adcpowdbv1 << 8) & ~((u32)0x00007F00)) == 0);
	ASSERT_ERR_CHIP((((u32)adcpowdbv0 << 0) & ~((u32)0x0000007F)) == 0);
	cl_reg_write(chip, MACDSP_API_ADC_POW_ADDR, ((u32)adcpowdbv3 << 24) | ((u32)adcpowdbv2 << 16) | ((u32)adcpowdbv1 << 8) | ((u32)adcpowdbv0 << 0));
}

static inline void macdsp_api_adc_pow_unpack(struct cl_chip *chip, u8 *adcpowdbv3, u8 *adcpowdbv2, u8 *adcpowdbv1, u8 *adcpowdbv0)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_ADC_POW_ADDR);

	*adcpowdbv3 = (local_val & ((u32)0x7F000000)) >> 24;
	*adcpowdbv2 = (local_val & ((u32)0x007F0000)) >> 16;
	*adcpowdbv1 = (local_val & ((u32)0x00007F00)) >> 8;
	*adcpowdbv0 = (local_val & ((u32)0x0000007F)) >> 0;
}

static inline u8 macdsp_api_adc_pow_adcpowdbv_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_ADC_POW_ADDR);

	return (u8)((local_val & ((u32)0x7F000000)) >> 24);
}

static inline void macdsp_api_adc_pow_adcpowdbv_3_setf(struct cl_chip *chip, u8 adcpowdbv3)
{
	ASSERT_ERR_CHIP((((u32)adcpowdbv3 << 24) & ~((u32)0x7F000000)) == 0);
	cl_reg_write(chip, MACDSP_API_ADC_POW_ADDR, (cl_reg_read(chip, MACDSP_API_ADC_POW_ADDR) & ~((u32)0x7F000000)) | ((u32)adcpowdbv3 << 24));
}

static inline u8 macdsp_api_adc_pow_adcpowdbv_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_ADC_POW_ADDR);

	return (u8)((local_val & ((u32)0x007F0000)) >> 16);
}

static inline void macdsp_api_adc_pow_adcpowdbv_2_setf(struct cl_chip *chip, u8 adcpowdbv2)
{
	ASSERT_ERR_CHIP((((u32)adcpowdbv2 << 16) & ~((u32)0x007F0000)) == 0);
	cl_reg_write(chip, MACDSP_API_ADC_POW_ADDR, (cl_reg_read(chip, MACDSP_API_ADC_POW_ADDR) & ~((u32)0x007F0000)) | ((u32)adcpowdbv2 << 16));
}

static inline u8 macdsp_api_adc_pow_adcpowdbv_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_ADC_POW_ADDR);

	return (u8)((local_val & ((u32)0x00007F00)) >> 8);
}

static inline void macdsp_api_adc_pow_adcpowdbv_1_setf(struct cl_chip *chip, u8 adcpowdbv1)
{
	ASSERT_ERR_CHIP((((u32)adcpowdbv1 << 8) & ~((u32)0x00007F00)) == 0);
	cl_reg_write(chip, MACDSP_API_ADC_POW_ADDR, (cl_reg_read(chip, MACDSP_API_ADC_POW_ADDR) & ~((u32)0x00007F00)) | ((u32)adcpowdbv1 << 8));
}

static inline u8 macdsp_api_adc_pow_adcpowdbv_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_ADC_POW_ADDR);

	return (u8)((local_val & ((u32)0x0000007F)) >> 0);
}

static inline void macdsp_api_adc_pow_adcpowdbv_0_setf(struct cl_chip *chip, u8 adcpowdbv0)
{
	ASSERT_ERR_CHIP((((u32)adcpowdbv0 << 0) & ~((u32)0x0000007F)) == 0);
	cl_reg_write(chip, MACDSP_API_ADC_POW_ADDR, (cl_reg_read(chip, MACDSP_API_ADC_POW_ADDR) & ~((u32)0x0000007F)) | ((u32)adcpowdbv0 << 0));
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
#define MACDSP_API_INBDPOW_20_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000974)
#define MACDSP_API_INBDPOW_20_OFFSET      0x00000974
#define MACDSP_API_INBDPOW_20_INDEX       0x0000025D
#define MACDSP_API_INBDPOW_20_RESET       0x00000000

static inline u32 macdsp_api_inbdpow_20_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_INBDPOW_20_ADDR);
}

static inline void macdsp_api_inbdpow_20_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_INBDPOW_20_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_INBDPOW_20_INBDPOW_20_PDBM_3_MASK    ((u32)0xFF000000)
#define MACDSP_API_INBDPOW_20_INBDPOW_20_PDBM_3_LSB    24
#define MACDSP_API_INBDPOW_20_INBDPOW_20_PDBM_3_WIDTH    ((u32)0x00000008)
#define MACDSP_API_INBDPOW_20_INBDPOW_20_PDBM_2_MASK    ((u32)0x00FF0000)
#define MACDSP_API_INBDPOW_20_INBDPOW_20_PDBM_2_LSB    16
#define MACDSP_API_INBDPOW_20_INBDPOW_20_PDBM_2_WIDTH    ((u32)0x00000008)
#define MACDSP_API_INBDPOW_20_INBDPOW_20_PDBM_1_MASK    ((u32)0x0000FF00)
#define MACDSP_API_INBDPOW_20_INBDPOW_20_PDBM_1_LSB    8
#define MACDSP_API_INBDPOW_20_INBDPOW_20_PDBM_1_WIDTH    ((u32)0x00000008)
#define MACDSP_API_INBDPOW_20_INBDPOW_20_PDBM_0_MASK    ((u32)0x000000FF)
#define MACDSP_API_INBDPOW_20_INBDPOW_20_PDBM_0_LSB    0
#define MACDSP_API_INBDPOW_20_INBDPOW_20_PDBM_0_WIDTH    ((u32)0x00000008)

#define MACDSP_API_INBDPOW_20_INBDPOW_20_PDBM_3_RST    0x0
#define MACDSP_API_INBDPOW_20_INBDPOW_20_PDBM_2_RST    0x0
#define MACDSP_API_INBDPOW_20_INBDPOW_20_PDBM_1_RST    0x0
#define MACDSP_API_INBDPOW_20_INBDPOW_20_PDBM_0_RST    0x0

static inline void macdsp_api_inbdpow_20_pack(struct cl_chip *chip, u8 inbdpow20_pdbm3, u8 inbdpow20_pdbm2, u8 inbdpow20_pdbm1, u8 inbdpow20_pdbm0)
{
	ASSERT_ERR_CHIP((((u32)inbdpow20_pdbm3 << 24) & ~((u32)0xFF000000)) == 0);
	ASSERT_ERR_CHIP((((u32)inbdpow20_pdbm2 << 16) & ~((u32)0x00FF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)inbdpow20_pdbm1 << 8) & ~((u32)0x0000FF00)) == 0);
	ASSERT_ERR_CHIP((((u32)inbdpow20_pdbm0 << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MACDSP_API_INBDPOW_20_ADDR, ((u32)inbdpow20_pdbm3 << 24) | ((u32)inbdpow20_pdbm2 << 16) | ((u32)inbdpow20_pdbm1 << 8) | ((u32)inbdpow20_pdbm0 << 0));
}

static inline void macdsp_api_inbdpow_20_unpack(struct cl_chip *chip, u8 *inbdpow20_pdbm3, u8 *inbdpow20_pdbm2, u8 *inbdpow20_pdbm1, u8 *inbdpow20_pdbm0)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_INBDPOW_20_ADDR);

	*inbdpow20_pdbm3 = (local_val & ((u32)0xFF000000)) >> 24;
	*inbdpow20_pdbm2 = (local_val & ((u32)0x00FF0000)) >> 16;
	*inbdpow20_pdbm1 = (local_val & ((u32)0x0000FF00)) >> 8;
	*inbdpow20_pdbm0 = (local_val & ((u32)0x000000FF)) >> 0;
}

static inline u8 macdsp_api_inbdpow_20_inbdpow_20_pdbm_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_INBDPOW_20_ADDR);

	return (u8)((local_val & ((u32)0xFF000000)) >> 24);
}

static inline void macdsp_api_inbdpow_20_inbdpow_20_pdbm_3_setf(struct cl_chip *chip, u8 inbdpow20pdbm3)
{
	ASSERT_ERR_CHIP((((u32)inbdpow20pdbm3 << 24) & ~((u32)0xFF000000)) == 0);
	cl_reg_write(chip, MACDSP_API_INBDPOW_20_ADDR, (cl_reg_read(chip, MACDSP_API_INBDPOW_20_ADDR) & ~((u32)0xFF000000)) | ((u32)inbdpow20pdbm3 << 24));
}

static inline u8 macdsp_api_inbdpow_20_inbdpow_20_pdbm_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_INBDPOW_20_ADDR);

	return (u8)((local_val & ((u32)0x00FF0000)) >> 16);
}

static inline void macdsp_api_inbdpow_20_inbdpow_20_pdbm_2_setf(struct cl_chip *chip, u8 inbdpow20pdbm2)
{
	ASSERT_ERR_CHIP((((u32)inbdpow20pdbm2 << 16) & ~((u32)0x00FF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_INBDPOW_20_ADDR, (cl_reg_read(chip, MACDSP_API_INBDPOW_20_ADDR) & ~((u32)0x00FF0000)) | ((u32)inbdpow20pdbm2 << 16));
}

static inline u8 macdsp_api_inbdpow_20_inbdpow_20_pdbm_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_INBDPOW_20_ADDR);

	return (u8)((local_val & ((u32)0x0000FF00)) >> 8);
}

static inline void macdsp_api_inbdpow_20_inbdpow_20_pdbm_1_setf(struct cl_chip *chip, u8 inbdpow20pdbm1)
{
	ASSERT_ERR_CHIP((((u32)inbdpow20pdbm1 << 8) & ~((u32)0x0000FF00)) == 0);
	cl_reg_write(chip, MACDSP_API_INBDPOW_20_ADDR, (cl_reg_read(chip, MACDSP_API_INBDPOW_20_ADDR) & ~((u32)0x0000FF00)) | ((u32)inbdpow20pdbm1 << 8));
}

static inline u8 macdsp_api_inbdpow_20_inbdpow_20_pdbm_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_INBDPOW_20_ADDR);

	return (u8)((local_val & ((u32)0x000000FF)) >> 0);
}

static inline void macdsp_api_inbdpow_20_inbdpow_20_pdbm_0_setf(struct cl_chip *chip, u8 inbdpow20pdbm0)
{
	ASSERT_ERR_CHIP((((u32)inbdpow20pdbm0 << 0) & ~((u32)0x000000FF)) == 0);
	cl_reg_write(chip, MACDSP_API_INBDPOW_20_ADDR, (cl_reg_read(chip, MACDSP_API_INBDPOW_20_ADDR) & ~((u32)0x000000FF)) | ((u32)inbdpow20pdbm0 << 0));
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
#define MACDSP_API_LNA_VGA_3_5_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000978)
#define MACDSP_API_LNA_VGA_3_5_OFFSET      0x00000978
#define MACDSP_API_LNA_VGA_3_5_INDEX       0x0000025E
#define MACDSP_API_LNA_VGA_3_5_RESET       0x00000000

static inline u32 macdsp_api_lna_vga_3_5_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR);
}

static inline void macdsp_api_lna_vga_3_5_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_LNA_VGA_3_5_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_5_EXTLNA_BIT    ((u32)0x10000000)
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_5_EXTLNA_POS    28
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_5_LNA_MASK    ((u32)0x0E000000)
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_5_LNA_LSB    25
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_5_LNA_WIDTH    ((u32)0x00000003)
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_5_VGA_MASK    ((u32)0x01F00000)
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_5_VGA_LSB    20
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_5_VGA_WIDTH    ((u32)0x00000005)
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_4_EXTLNA_BIT    ((u32)0x00040000)
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_4_EXTLNA_POS    18
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_4_LNA_MASK    ((u32)0x00038000)
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_4_LNA_LSB    15
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_4_LNA_WIDTH    ((u32)0x00000003)
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_4_VGA_MASK    ((u32)0x00007C00)
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_4_VGA_LSB    10
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_4_VGA_WIDTH    ((u32)0x00000005)
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_3_EXTLNA_BIT    ((u32)0x00000100)
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_3_EXTLNA_POS    8
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_3_LNA_MASK    ((u32)0x000000E0)
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_3_LNA_LSB    5
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_3_LNA_WIDTH    ((u32)0x00000003)
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_3_VGA_MASK    ((u32)0x0000001F)
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_3_VGA_LSB    0
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_3_VGA_WIDTH    ((u32)0x00000005)

#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_5_EXTLNA_RST    0x0
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_5_LNA_RST    0x0
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_5_VGA_RST    0x0
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_4_EXTLNA_RST    0x0
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_4_LNA_RST    0x0
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_4_VGA_RST    0x0
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_3_EXTLNA_RST    0x0
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_3_LNA_RST    0x0
#define MACDSP_API_LNA_VGA_3_5_AGCRFGAIN_3_VGA_RST    0x0

static inline void macdsp_api_lna_vga_3_5_pack(struct cl_chip *chip, u8 agcrfgain5_extlna, u8 agcrfgain5_lna, u8 agcrfgain5_vga, u8 agcrfgain4_extlna, u8 agcrfgain4_lna, u8 agcrfgain4_vga, u8 agcrfgain3_extlna, u8 agcrfgain3_lna, u8 agcrfgain3_vga)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain5_extlna << 28) & ~((u32)0x10000000)) == 0);
	ASSERT_ERR_CHIP((((u32)agcrfgain5_lna << 25) & ~((u32)0x0E000000)) == 0);
	ASSERT_ERR_CHIP((((u32)agcrfgain5_vga << 20) & ~((u32)0x01F00000)) == 0);
	ASSERT_ERR_CHIP((((u32)agcrfgain4_extlna << 18) & ~((u32)0x00040000)) == 0);
	ASSERT_ERR_CHIP((((u32)agcrfgain4_lna << 15) & ~((u32)0x00038000)) == 0);
	ASSERT_ERR_CHIP((((u32)agcrfgain4_vga << 10) & ~((u32)0x00007C00)) == 0);
	ASSERT_ERR_CHIP((((u32)agcrfgain3_extlna << 8) & ~((u32)0x00000100)) == 0);
	ASSERT_ERR_CHIP((((u32)agcrfgain3_lna << 5) & ~((u32)0x000000E0)) == 0);
	ASSERT_ERR_CHIP((((u32)agcrfgain3_vga << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_3_5_ADDR, ((u32)agcrfgain5_extlna << 28) | ((u32)agcrfgain5_lna << 25) | ((u32)agcrfgain5_vga << 20) | ((u32)agcrfgain4_extlna << 18) | ((u32)agcrfgain4_lna << 15) | ((u32)agcrfgain4_vga << 10) | ((u32)agcrfgain3_extlna << 8) | ((u32)agcrfgain3_lna << 5) | ((u32)agcrfgain3_vga << 0));
}

static inline void macdsp_api_lna_vga_3_5_unpack(struct cl_chip *chip, u8 *agcrfgain5_extlna, u8 *agcrfgain5_lna, u8 *agcrfgain5_vga, u8 *agcrfgain4_extlna, u8 *agcrfgain4_lna, u8 *agcrfgain4_vga, u8 *agcrfgain3_extlna, u8 *agcrfgain3_lna, u8 *agcrfgain3_vga)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR);

	*agcrfgain5_extlna = (local_val & ((u32)0x10000000)) >> 28;
	*agcrfgain5_lna = (local_val & ((u32)0x0E000000)) >> 25;
	*agcrfgain5_vga = (local_val & ((u32)0x01F00000)) >> 20;
	*agcrfgain4_extlna = (local_val & ((u32)0x00040000)) >> 18;
	*agcrfgain4_lna = (local_val & ((u32)0x00038000)) >> 15;
	*agcrfgain4_vga = (local_val & ((u32)0x00007C00)) >> 10;
	*agcrfgain3_extlna = (local_val & ((u32)0x00000100)) >> 8;
	*agcrfgain3_lna = (local_val & ((u32)0x000000E0)) >> 5;
	*agcrfgain3_vga = (local_val & ((u32)0x0000001F)) >> 0;
}

static inline u8 macdsp_api_lna_vga_3_5_agcrfgain_5_extlna_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR);

	return (u8)((local_val & ((u32)0x10000000)) >> 28);
}

static inline void macdsp_api_lna_vga_3_5_agcrfgain_5_extlna_setf(struct cl_chip *chip, u8 agcrfgain5extlna)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain5extlna << 28) & ~((u32)0x10000000)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_3_5_ADDR, (cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR) & ~((u32)0x10000000)) | ((u32)agcrfgain5extlna << 28));
}

static inline u8 macdsp_api_lna_vga_3_5_agcrfgain_5_lna_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR);

	return (u8)((local_val & ((u32)0x0E000000)) >> 25);
}

static inline void macdsp_api_lna_vga_3_5_agcrfgain_5_lna_setf(struct cl_chip *chip, u8 agcrfgain5lna)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain5lna << 25) & ~((u32)0x0E000000)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_3_5_ADDR, (cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR) & ~((u32)0x0E000000)) | ((u32)agcrfgain5lna << 25));
}

static inline u8 macdsp_api_lna_vga_3_5_agcrfgain_5_vga_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR);

	return (u8)((local_val & ((u32)0x01F00000)) >> 20);
}

static inline void macdsp_api_lna_vga_3_5_agcrfgain_5_vga_setf(struct cl_chip *chip, u8 agcrfgain5vga)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain5vga << 20) & ~((u32)0x01F00000)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_3_5_ADDR, (cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR) & ~((u32)0x01F00000)) | ((u32)agcrfgain5vga << 20));
}

static inline u8 macdsp_api_lna_vga_3_5_agcrfgain_4_extlna_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR);

	return (u8)((local_val & ((u32)0x00040000)) >> 18);
}

static inline void macdsp_api_lna_vga_3_5_agcrfgain_4_extlna_setf(struct cl_chip *chip, u8 agcrfgain4extlna)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain4extlna << 18) & ~((u32)0x00040000)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_3_5_ADDR, (cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR) & ~((u32)0x00040000)) | ((u32)agcrfgain4extlna << 18));
}

static inline u8 macdsp_api_lna_vga_3_5_agcrfgain_4_lna_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR);

	return (u8)((local_val & ((u32)0x00038000)) >> 15);
}

static inline void macdsp_api_lna_vga_3_5_agcrfgain_4_lna_setf(struct cl_chip *chip, u8 agcrfgain4lna)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain4lna << 15) & ~((u32)0x00038000)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_3_5_ADDR, (cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR) & ~((u32)0x00038000)) | ((u32)agcrfgain4lna << 15));
}

static inline u8 macdsp_api_lna_vga_3_5_agcrfgain_4_vga_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR);

	return (u8)((local_val & ((u32)0x00007C00)) >> 10);
}

static inline void macdsp_api_lna_vga_3_5_agcrfgain_4_vga_setf(struct cl_chip *chip, u8 agcrfgain4vga)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain4vga << 10) & ~((u32)0x00007C00)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_3_5_ADDR, (cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR) & ~((u32)0x00007C00)) | ((u32)agcrfgain4vga << 10));
}

static inline u8 macdsp_api_lna_vga_3_5_agcrfgain_3_extlna_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR);

	return (u8)((local_val & ((u32)0x00000100)) >> 8);
}

static inline void macdsp_api_lna_vga_3_5_agcrfgain_3_extlna_setf(struct cl_chip *chip, u8 agcrfgain3extlna)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain3extlna << 8) & ~((u32)0x00000100)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_3_5_ADDR, (cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR) & ~((u32)0x00000100)) | ((u32)agcrfgain3extlna << 8));
}

static inline u8 macdsp_api_lna_vga_3_5_agcrfgain_3_lna_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR);

	return (u8)((local_val & ((u32)0x000000E0)) >> 5);
}

static inline void macdsp_api_lna_vga_3_5_agcrfgain_3_lna_setf(struct cl_chip *chip, u8 agcrfgain3lna)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain3lna << 5) & ~((u32)0x000000E0)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_3_5_ADDR, (cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR) & ~((u32)0x000000E0)) | ((u32)agcrfgain3lna << 5));
}

static inline u8 macdsp_api_lna_vga_3_5_agcrfgain_3_vga_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR);

	return (u8)((local_val & ((u32)0x0000001F)) >> 0);
}

static inline void macdsp_api_lna_vga_3_5_agcrfgain_3_vga_setf(struct cl_chip *chip, u8 agcrfgain3vga)
{
	ASSERT_ERR_CHIP((((u32)agcrfgain3vga << 0) & ~((u32)0x0000001F)) == 0);
	cl_reg_write(chip, MACDSP_API_LNA_VGA_3_5_ADDR, (cl_reg_read(chip, MACDSP_API_LNA_VGA_3_5_ADDR) & ~((u32)0x0000001F)) | ((u32)agcrfgain3vga << 0));
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
#define MACDSP_API_DIG_GAIN_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x0000097C)
#define MACDSP_API_DIG_GAIN_OFFSET      0x0000097C
#define MACDSP_API_DIG_GAIN_INDEX       0x0000025F
#define MACDSP_API_DIG_GAIN_RESET       0x00000000

static inline u32 macdsp_api_dig_gain_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_DIG_GAIN_ADDR);
}

static inline void macdsp_api_dig_gain_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_DIG_GAIN_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_DIG_GAIN_DIGGAIN_20_ANT_3_MASK    ((u32)0x7F000000)
#define MACDSP_API_DIG_GAIN_DIGGAIN_20_ANT_3_LSB    24
#define MACDSP_API_DIG_GAIN_DIGGAIN_20_ANT_3_WIDTH    ((u32)0x00000007)
#define MACDSP_API_DIG_GAIN_DIGGAIN_20_ANT_2_MASK    ((u32)0x007F0000)
#define MACDSP_API_DIG_GAIN_DIGGAIN_20_ANT_2_LSB    16
#define MACDSP_API_DIG_GAIN_DIGGAIN_20_ANT_2_WIDTH    ((u32)0x00000007)
#define MACDSP_API_DIG_GAIN_DIGGAIN_20_ANT_1_MASK    ((u32)0x00007F00)
#define MACDSP_API_DIG_GAIN_DIGGAIN_20_ANT_1_LSB    8
#define MACDSP_API_DIG_GAIN_DIGGAIN_20_ANT_1_WIDTH    ((u32)0x00000007)
#define MACDSP_API_DIG_GAIN_DIGGAIN_20_ANT_0_MASK    ((u32)0x0000007F)
#define MACDSP_API_DIG_GAIN_DIGGAIN_20_ANT_0_LSB    0
#define MACDSP_API_DIG_GAIN_DIGGAIN_20_ANT_0_WIDTH    ((u32)0x00000007)

#define MACDSP_API_DIG_GAIN_DIGGAIN_20_ANT_3_RST    0x0
#define MACDSP_API_DIG_GAIN_DIGGAIN_20_ANT_2_RST    0x0
#define MACDSP_API_DIG_GAIN_DIGGAIN_20_ANT_1_RST    0x0
#define MACDSP_API_DIG_GAIN_DIGGAIN_20_ANT_0_RST    0x0

static inline void macdsp_api_dig_gain_pack(struct cl_chip *chip, u8 diggain20_ant3, u8 diggain20_ant2, u8 diggain20_ant1, u8 diggain20_ant0)
{
	ASSERT_ERR_CHIP((((u32)diggain20_ant3 << 24) & ~((u32)0x7F000000)) == 0);
	ASSERT_ERR_CHIP((((u32)diggain20_ant2 << 16) & ~((u32)0x007F0000)) == 0);
	ASSERT_ERR_CHIP((((u32)diggain20_ant1 << 8) & ~((u32)0x00007F00)) == 0);
	ASSERT_ERR_CHIP((((u32)diggain20_ant0 << 0) & ~((u32)0x0000007F)) == 0);
	cl_reg_write(chip, MACDSP_API_DIG_GAIN_ADDR, ((u32)diggain20_ant3 << 24) | ((u32)diggain20_ant2 << 16) | ((u32)diggain20_ant1 << 8) | ((u32)diggain20_ant0 << 0));
}

static inline void macdsp_api_dig_gain_unpack(struct cl_chip *chip, u8 *diggain20_ant3, u8 *diggain20_ant2, u8 *diggain20_ant1, u8 *diggain20_ant0)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DIG_GAIN_ADDR);

	*diggain20_ant3 = (local_val & ((u32)0x7F000000)) >> 24;
	*diggain20_ant2 = (local_val & ((u32)0x007F0000)) >> 16;
	*diggain20_ant1 = (local_val & ((u32)0x00007F00)) >> 8;
	*diggain20_ant0 = (local_val & ((u32)0x0000007F)) >> 0;
}

static inline u8 macdsp_api_dig_gain_diggain_20_ant_3_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DIG_GAIN_ADDR);

	return (u8)((local_val & ((u32)0x7F000000)) >> 24);
}

static inline void macdsp_api_dig_gain_diggain_20_ant_3_setf(struct cl_chip *chip, u8 diggain20ant3)
{
	ASSERT_ERR_CHIP((((u32)diggain20ant3 << 24) & ~((u32)0x7F000000)) == 0);
	cl_reg_write(chip, MACDSP_API_DIG_GAIN_ADDR, (cl_reg_read(chip, MACDSP_API_DIG_GAIN_ADDR) & ~((u32)0x7F000000)) | ((u32)diggain20ant3 << 24));
}

static inline u8 macdsp_api_dig_gain_diggain_20_ant_2_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DIG_GAIN_ADDR);

	return (u8)((local_val & ((u32)0x007F0000)) >> 16);
}

static inline void macdsp_api_dig_gain_diggain_20_ant_2_setf(struct cl_chip *chip, u8 diggain20ant2)
{
	ASSERT_ERR_CHIP((((u32)diggain20ant2 << 16) & ~((u32)0x007F0000)) == 0);
	cl_reg_write(chip, MACDSP_API_DIG_GAIN_ADDR, (cl_reg_read(chip, MACDSP_API_DIG_GAIN_ADDR) & ~((u32)0x007F0000)) | ((u32)diggain20ant2 << 16));
}

static inline u8 macdsp_api_dig_gain_diggain_20_ant_1_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DIG_GAIN_ADDR);

	return (u8)((local_val & ((u32)0x00007F00)) >> 8);
}

static inline void macdsp_api_dig_gain_diggain_20_ant_1_setf(struct cl_chip *chip, u8 diggain20ant1)
{
	ASSERT_ERR_CHIP((((u32)diggain20ant1 << 8) & ~((u32)0x00007F00)) == 0);
	cl_reg_write(chip, MACDSP_API_DIG_GAIN_ADDR, (cl_reg_read(chip, MACDSP_API_DIG_GAIN_ADDR) & ~((u32)0x00007F00)) | ((u32)diggain20ant1 << 8));
}

static inline u8 macdsp_api_dig_gain_diggain_20_ant_0_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_DIG_GAIN_ADDR);

	return (u8)((local_val & ((u32)0x0000007F)) >> 0);
}

static inline void macdsp_api_dig_gain_diggain_20_ant_0_setf(struct cl_chip *chip, u8 diggain20ant0)
{
	ASSERT_ERR_CHIP((((u32)diggain20ant0 << 0) & ~((u32)0x0000007F)) == 0);
	cl_reg_write(chip, MACDSP_API_DIG_GAIN_ADDR, (cl_reg_read(chip, MACDSP_API_DIG_GAIN_ADDR) & ~((u32)0x0000007F)) | ((u32)diggain20ant0 << 0));
}

/**
 * @brief INBDPOW_20_1 register definition
 *  Latch_InBand20p_1_ADC_pow_ants_4_5 register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    31:24 Inbdpow20_Pdbm5           0x0
 *    23:16 Inbdpow20_Pdbm4           0x0
 *    14:08 Adcpowdbv5                0x0
 *    06:00 Adcpowdbv4                0x0
 * </pre>
 */
#define MACDSP_API_INBDPOW_20_1_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x00000980)
#define MACDSP_API_INBDPOW_20_1_OFFSET      0x00000980
#define MACDSP_API_INBDPOW_20_1_INDEX       0x00000260
#define MACDSP_API_INBDPOW_20_1_RESET       0x00000000

static inline u32 macdsp_api_inbdpow_20_1_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_INBDPOW_20_1_ADDR);
}

static inline void macdsp_api_inbdpow_20_1_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_INBDPOW_20_1_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_INBDPOW_20_1_INBDPOW_20_PDBM_5_MASK    ((u32)0xFF000000)
#define MACDSP_API_INBDPOW_20_1_INBDPOW_20_PDBM_5_LSB    24
#define MACDSP_API_INBDPOW_20_1_INBDPOW_20_PDBM_5_WIDTH    ((u32)0x00000008)
#define MACDSP_API_INBDPOW_20_1_INBDPOW_20_PDBM_4_MASK    ((u32)0x00FF0000)
#define MACDSP_API_INBDPOW_20_1_INBDPOW_20_PDBM_4_LSB    16
#define MACDSP_API_INBDPOW_20_1_INBDPOW_20_PDBM_4_WIDTH    ((u32)0x00000008)
#define MACDSP_API_INBDPOW_20_1_ADCPOWDBV_5_MASK    ((u32)0x00007F00)
#define MACDSP_API_INBDPOW_20_1_ADCPOWDBV_5_LSB    8
#define MACDSP_API_INBDPOW_20_1_ADCPOWDBV_5_WIDTH    ((u32)0x00000007)
#define MACDSP_API_INBDPOW_20_1_ADCPOWDBV_4_MASK    ((u32)0x0000007F)
#define MACDSP_API_INBDPOW_20_1_ADCPOWDBV_4_LSB    0
#define MACDSP_API_INBDPOW_20_1_ADCPOWDBV_4_WIDTH    ((u32)0x00000007)

#define MACDSP_API_INBDPOW_20_1_INBDPOW_20_PDBM_5_RST    0x0
#define MACDSP_API_INBDPOW_20_1_INBDPOW_20_PDBM_4_RST    0x0
#define MACDSP_API_INBDPOW_20_1_ADCPOWDBV_5_RST    0x0
#define MACDSP_API_INBDPOW_20_1_ADCPOWDBV_4_RST    0x0

static inline void macdsp_api_inbdpow_20_1_pack(struct cl_chip *chip, u8 inbdpow20_pdbm5, u8 inbdpow20_pdbm4, u8 adcpowdbv5, u8 adcpowdbv4)
{
	ASSERT_ERR_CHIP((((u32)inbdpow20_pdbm5 << 24) & ~((u32)0xFF000000)) == 0);
	ASSERT_ERR_CHIP((((u32)inbdpow20_pdbm4 << 16) & ~((u32)0x00FF0000)) == 0);
	ASSERT_ERR_CHIP((((u32)adcpowdbv5 << 8) & ~((u32)0x00007F00)) == 0);
	ASSERT_ERR_CHIP((((u32)adcpowdbv4 << 0) & ~((u32)0x0000007F)) == 0);
	cl_reg_write(chip, MACDSP_API_INBDPOW_20_1_ADDR, ((u32)inbdpow20_pdbm5 << 24) | ((u32)inbdpow20_pdbm4 << 16) | ((u32)adcpowdbv5 << 8) | ((u32)adcpowdbv4 << 0));
}

static inline void macdsp_api_inbdpow_20_1_unpack(struct cl_chip *chip, u8 *inbdpow20_pdbm5, u8 *inbdpow20_pdbm4, u8 *adcpowdbv5, u8 *adcpowdbv4)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_INBDPOW_20_1_ADDR);

	*inbdpow20_pdbm5 = (local_val & ((u32)0xFF000000)) >> 24;
	*inbdpow20_pdbm4 = (local_val & ((u32)0x00FF0000)) >> 16;
	*adcpowdbv5 = (local_val & ((u32)0x00007F00)) >> 8;
	*adcpowdbv4 = (local_val & ((u32)0x0000007F)) >> 0;
}

static inline u8 macdsp_api_inbdpow_20_1_inbdpow_20_pdbm_5_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_INBDPOW_20_1_ADDR);

	return (u8)((local_val & ((u32)0xFF000000)) >> 24);
}

static inline void macdsp_api_inbdpow_20_1_inbdpow_20_pdbm_5_setf(struct cl_chip *chip, u8 inbdpow20pdbm5)
{
	ASSERT_ERR_CHIP((((u32)inbdpow20pdbm5 << 24) & ~((u32)0xFF000000)) == 0);
	cl_reg_write(chip, MACDSP_API_INBDPOW_20_1_ADDR, (cl_reg_read(chip, MACDSP_API_INBDPOW_20_1_ADDR) & ~((u32)0xFF000000)) | ((u32)inbdpow20pdbm5 << 24));
}

static inline u8 macdsp_api_inbdpow_20_1_inbdpow_20_pdbm_4_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_INBDPOW_20_1_ADDR);

	return (u8)((local_val & ((u32)0x00FF0000)) >> 16);
}

static inline void macdsp_api_inbdpow_20_1_inbdpow_20_pdbm_4_setf(struct cl_chip *chip, u8 inbdpow20pdbm4)
{
	ASSERT_ERR_CHIP((((u32)inbdpow20pdbm4 << 16) & ~((u32)0x00FF0000)) == 0);
	cl_reg_write(chip, MACDSP_API_INBDPOW_20_1_ADDR, (cl_reg_read(chip, MACDSP_API_INBDPOW_20_1_ADDR) & ~((u32)0x00FF0000)) | ((u32)inbdpow20pdbm4 << 16));
}

static inline u8 macdsp_api_inbdpow_20_1_adcpowdbv_5_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_INBDPOW_20_1_ADDR);

	return (u8)((local_val & ((u32)0x00007F00)) >> 8);
}

static inline void macdsp_api_inbdpow_20_1_adcpowdbv_5_setf(struct cl_chip *chip, u8 adcpowdbv5)
{
	ASSERT_ERR_CHIP((((u32)adcpowdbv5 << 8) & ~((u32)0x00007F00)) == 0);
	cl_reg_write(chip, MACDSP_API_INBDPOW_20_1_ADDR, (cl_reg_read(chip, MACDSP_API_INBDPOW_20_1_ADDR) & ~((u32)0x00007F00)) | ((u32)adcpowdbv5 << 8));
}

static inline u8 macdsp_api_inbdpow_20_1_adcpowdbv_4_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_INBDPOW_20_1_ADDR);

	return (u8)((local_val & ((u32)0x0000007F)) >> 0);
}

static inline void macdsp_api_inbdpow_20_1_adcpowdbv_4_setf(struct cl_chip *chip, u8 adcpowdbv4)
{
	ASSERT_ERR_CHIP((((u32)adcpowdbv4 << 0) & ~((u32)0x0000007F)) == 0);
	cl_reg_write(chip, MACDSP_API_INBDPOW_20_1_ADDR, (cl_reg_read(chip, MACDSP_API_INBDPOW_20_1_ADDR) & ~((u32)0x0000007F)) | ((u32)adcpowdbv4 << 0));
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
#define MACDSP_API_RX_DMEM_DEBUG_MODE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000009DC)
#define MACDSP_API_RX_DMEM_DEBUG_MODE_OFFSET      0x000009DC
#define MACDSP_API_RX_DMEM_DEBUG_MODE_INDEX       0x00000277
#define MACDSP_API_RX_DMEM_DEBUG_MODE_RESET       0x00000000

static inline u32 macdsp_api_rx_dmem_debug_mode_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_DMEM_DEBUG_MODE_ADDR);
}

static inline void macdsp_api_rx_dmem_debug_mode_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_DMEM_DEBUG_MODE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_DMEM_DEBUG_MODE_STOP_CAPTURE_BIT    ((u32)0x00001000)
#define MACDSP_API_RX_DMEM_DEBUG_MODE_STOP_CAPTURE_POS    12
#define MACDSP_API_RX_DMEM_DEBUG_MODE_NUMBER_OF_SYMBOL_N_MASK    ((u32)0x00000FF0)
#define MACDSP_API_RX_DMEM_DEBUG_MODE_NUMBER_OF_SYMBOL_N_LSB    4
#define MACDSP_API_RX_DMEM_DEBUG_MODE_NUMBER_OF_SYMBOL_N_WIDTH    ((u32)0x00000008)
#define MACDSP_API_RX_DMEM_DEBUG_MODE_SYMBOL_CAPTURE_MODE_MASK    ((u32)0x0000000F)
#define MACDSP_API_RX_DMEM_DEBUG_MODE_SYMBOL_CAPTURE_MODE_LSB    0
#define MACDSP_API_RX_DMEM_DEBUG_MODE_SYMBOL_CAPTURE_MODE_WIDTH    ((u32)0x00000004)

#define MACDSP_API_RX_DMEM_DEBUG_MODE_STOP_CAPTURE_RST    0x0
#define MACDSP_API_RX_DMEM_DEBUG_MODE_NUMBER_OF_SYMBOL_N_RST    0x0
#define MACDSP_API_RX_DMEM_DEBUG_MODE_SYMBOL_CAPTURE_MODE_RST    0x0

static inline void macdsp_api_rx_dmem_debug_mode_pack(struct cl_chip *chip, u8 stop_capture, u8 number_of_symbol_n, u8 symbol_capture_mode)
{
	ASSERT_ERR_CHIP((((u32)stop_capture << 12) & ~((u32)0x00001000)) == 0);
	ASSERT_ERR_CHIP((((u32)number_of_symbol_n << 4) & ~((u32)0x00000FF0)) == 0);
	ASSERT_ERR_CHIP((((u32)symbol_capture_mode << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_DMEM_DEBUG_MODE_ADDR, ((u32)stop_capture << 12) | ((u32)number_of_symbol_n << 4) | ((u32)symbol_capture_mode << 0));
}

static inline void macdsp_api_rx_dmem_debug_mode_unpack(struct cl_chip *chip, u8 *stop_capture, u8 *number_of_symbol_n, u8 *symbol_capture_mode)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_DMEM_DEBUG_MODE_ADDR);

	*stop_capture = (local_val & ((u32)0x00001000)) >> 12;
	*number_of_symbol_n = (local_val & ((u32)0x00000FF0)) >> 4;
	*symbol_capture_mode = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 macdsp_api_rx_dmem_debug_mode_stop_capture_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_DMEM_DEBUG_MODE_ADDR);

	return (u8)((local_val & ((u32)0x00001000)) >> 12);
}

static inline void macdsp_api_rx_dmem_debug_mode_stop_capture_setf(struct cl_chip *chip, u8 stopcapture)
{
	ASSERT_ERR_CHIP((((u32)stopcapture << 12) & ~((u32)0x00001000)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_DMEM_DEBUG_MODE_ADDR, (cl_reg_read(chip, MACDSP_API_RX_DMEM_DEBUG_MODE_ADDR) & ~((u32)0x00001000)) | ((u32)stopcapture << 12));
}

static inline u8 macdsp_api_rx_dmem_debug_mode_number_of_symbol_n_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_DMEM_DEBUG_MODE_ADDR);

	return (u8)((local_val & ((u32)0x00000FF0)) >> 4);
}

static inline void macdsp_api_rx_dmem_debug_mode_number_of_symbol_n_setf(struct cl_chip *chip, u8 numberofsymboln)
{
	ASSERT_ERR_CHIP((((u32)numberofsymboln << 4) & ~((u32)0x00000FF0)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_DMEM_DEBUG_MODE_ADDR, (cl_reg_read(chip, MACDSP_API_RX_DMEM_DEBUG_MODE_ADDR) & ~((u32)0x00000FF0)) | ((u32)numberofsymboln << 4));
}

static inline u8 macdsp_api_rx_dmem_debug_mode_symbol_capture_mode_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_DMEM_DEBUG_MODE_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void macdsp_api_rx_dmem_debug_mode_symbol_capture_mode_setf(struct cl_chip *chip, u8 symbolcapturemode)
{
	ASSERT_ERR_CHIP((((u32)symbolcapturemode << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_DMEM_DEBUG_MODE_ADDR, (cl_reg_read(chip, MACDSP_API_RX_DMEM_DEBUG_MODE_ADDR) & ~((u32)0x0000000F)) | ((u32)symbolcapturemode << 0));
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
#define MACDSP_API_RX_DMEM_DEBUG_PTR_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000009E0)
#define MACDSP_API_RX_DMEM_DEBUG_PTR_OFFSET      0x000009E0
#define MACDSP_API_RX_DMEM_DEBUG_PTR_INDEX       0x00000278
#define MACDSP_API_RX_DMEM_DEBUG_PTR_RESET       0x00000000

static inline u32 macdsp_api_rx_dmem_debug_ptr_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_DMEM_DEBUG_PTR_ADDR);
}

static inline void macdsp_api_rx_dmem_debug_ptr_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_DMEM_DEBUG_PTR_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_DMEM_DEBUG_PTR_RX_DEBUG_PTR_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_RX_DMEM_DEBUG_PTR_RX_DEBUG_PTR_LSB    0
#define MACDSP_API_RX_DMEM_DEBUG_PTR_RX_DEBUG_PTR_WIDTH    ((u32)0x00000020)

#define MACDSP_API_RX_DMEM_DEBUG_PTR_RX_DEBUG_PTR_RST    0x0

static inline u32 macdsp_api_rx_dmem_debug_ptr_rx_debug_ptr_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_DMEM_DEBUG_PTR_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_rx_dmem_debug_ptr_rx_debug_ptr_setf(struct cl_chip *chip, u32 rxdebugptr)
{
	ASSERT_ERR_CHIP((((u32)rxdebugptr << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_DMEM_DEBUG_PTR_ADDR, (u32)rxdebugptr << 0);
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
#define MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000009E4)
#define MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_OFFSET      0x000009E4
#define MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_INDEX       0x00000279
#define MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_RESET       0x00000000

static inline u32 macdsp_api_rx_debug_automation_flags_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_ADDR);
}

static inline void macdsp_api_rx_debug_automation_flags_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_TB_AUTO_LDPC_EXTRA_SYMBOL_BIT    ((u32)0x00000002)
#define MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_TB_AUTO_LDPC_EXTRA_SYMBOL_POS    1
#define MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_TB_AUTO_TEST_RUN_BIT    ((u32)0x00000001)
#define MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_TB_AUTO_TEST_RUN_POS    0

#define MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_TB_AUTO_LDPC_EXTRA_SYMBOL_RST    0x0
#define MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_TB_AUTO_TEST_RUN_RST    0x0

static inline void macdsp_api_rx_debug_automation_flags_pack(struct cl_chip *chip, u8 tb_auto_ldpc_extra_symbol, u8 tb_auto_test_run)
{
	ASSERT_ERR_CHIP((((u32)tb_auto_ldpc_extra_symbol << 1) & ~((u32)0x00000002)) == 0);
	ASSERT_ERR_CHIP((((u32)tb_auto_test_run << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_ADDR, ((u32)tb_auto_ldpc_extra_symbol << 1) | ((u32)tb_auto_test_run << 0));
}

static inline void macdsp_api_rx_debug_automation_flags_unpack(struct cl_chip *chip, u8 *tb_auto_ldpc_extra_symbol, u8 *tb_auto_test_run)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_ADDR);

	*tb_auto_ldpc_extra_symbol = (local_val & ((u32)0x00000002)) >> 1;
	*tb_auto_test_run = (local_val & ((u32)0x00000001)) >> 0;
}

static inline u8 macdsp_api_rx_debug_automation_flags_tb_auto_ldpc_extra_symbol_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_ADDR);

	return (u8)((local_val & ((u32)0x00000002)) >> 1);
}

static inline void macdsp_api_rx_debug_automation_flags_tb_auto_ldpc_extra_symbol_setf(struct cl_chip *chip, u8 tbautoldpcextrasymbol)
{
	ASSERT_ERR_CHIP((((u32)tbautoldpcextrasymbol << 1) & ~((u32)0x00000002)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_ADDR, (cl_reg_read(chip, MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_ADDR) & ~((u32)0x00000002)) | ((u32)tbautoldpcextrasymbol << 1));
}

static inline u8 macdsp_api_rx_debug_automation_flags_tb_auto_test_run_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_ADDR);

	return (u8)((local_val & ((u32)0x00000001)) >> 0);
}

static inline void macdsp_api_rx_debug_automation_flags_tb_auto_test_run_setf(struct cl_chip *chip, u8 tbautotestrun)
{
	ASSERT_ERR_CHIP((((u32)tbautotestrun << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_ADDR, (cl_reg_read(chip, MACDSP_API_RX_DEBUG_AUTOMATION_FLAGS_ADDR) & ~((u32)0x00000001)) | ((u32)tbautotestrun << 0));
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
#define MACDSP_API_RX_DMEM_DEBUG_SIZE_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000009E8)
#define MACDSP_API_RX_DMEM_DEBUG_SIZE_OFFSET      0x000009E8
#define MACDSP_API_RX_DMEM_DEBUG_SIZE_INDEX       0x0000027A
#define MACDSP_API_RX_DMEM_DEBUG_SIZE_RESET       0x00000000

static inline u32 macdsp_api_rx_dmem_debug_size_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RX_DMEM_DEBUG_SIZE_ADDR);
}

static inline void macdsp_api_rx_dmem_debug_size_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RX_DMEM_DEBUG_SIZE_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RX_DMEM_DEBUG_SIZE_DMEM_SIZE_MASK    ((u32)0xFFFFFFFF)
#define MACDSP_API_RX_DMEM_DEBUG_SIZE_DMEM_SIZE_LSB    0
#define MACDSP_API_RX_DMEM_DEBUG_SIZE_DMEM_SIZE_WIDTH    ((u32)0x00000020)

#define MACDSP_API_RX_DMEM_DEBUG_SIZE_DMEM_SIZE_RST    0x0

static inline u32 macdsp_api_rx_dmem_debug_size_dmem_size_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RX_DMEM_DEBUG_SIZE_ADDR);

	return (u32)(local_val >> 0);
}

static inline void macdsp_api_rx_dmem_debug_size_dmem_size_setf(struct cl_chip *chip, u32 dmemsize)
{
	ASSERT_ERR_CHIP((((u32)dmemsize << 0) & ~((u32)0xFFFFFFFF)) == 0);
	cl_reg_write(chip, MACDSP_API_RX_DMEM_DEBUG_SIZE_ADDR, (u32)dmemsize << 0);
}

/**
 * @brief RIU_DPD_GAIN_ANT_0_FROM_MATLAB register definition
 *  RIU_DPD_GAIN_ANT_0_FROM_MATLAB register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    25:24 Out_Gain_Shift_matlab     0x0
 *    22:16 Out_Gain_Mult_matlab      0x0
 *    09:08 In_Gain_Shift_matlab      0x0
 *    06:00 In_Gain_Mult_matlab       0x0
 * </pre>
 */
#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000009EC)
#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_OFFSET      0x000009EC
#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_INDEX       0x0000027B
#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_RESET       0x00000000

static inline u32 macdsp_api_riu_dpd_gain_ant_0_from_matlab_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_ADDR);
}

static inline void macdsp_api_riu_dpd_gain_ant_0_from_matlab_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_OUT_GAIN_SHIFT_MATLAB_MASK    ((u32)0x03000000)
#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_OUT_GAIN_SHIFT_MATLAB_LSB    24
#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_OUT_GAIN_SHIFT_MATLAB_WIDTH    ((u32)0x00000002)
#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_OUT_GAIN_MULT_MATLAB_MASK    ((u32)0x007F0000)
#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_OUT_GAIN_MULT_MATLAB_LSB    16
#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_OUT_GAIN_MULT_MATLAB_WIDTH    ((u32)0x00000007)
#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_IN_GAIN_SHIFT_MATLAB_MASK    ((u32)0x00000300)
#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_IN_GAIN_SHIFT_MATLAB_LSB    8
#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_IN_GAIN_SHIFT_MATLAB_WIDTH    ((u32)0x00000002)
#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_IN_GAIN_MULT_MATLAB_MASK    ((u32)0x0000007F)
#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_IN_GAIN_MULT_MATLAB_LSB    0
#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_IN_GAIN_MULT_MATLAB_WIDTH    ((u32)0x00000007)

#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_OUT_GAIN_SHIFT_MATLAB_RST    0x0
#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_OUT_GAIN_MULT_MATLAB_RST    0x0
#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_IN_GAIN_SHIFT_MATLAB_RST    0x0
#define MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_IN_GAIN_MULT_MATLAB_RST    0x0

static inline void macdsp_api_riu_dpd_gain_ant_0_from_matlab_pack(struct cl_chip *chip, u8 out_gain_shift_matlab, u8 out_gain_mult_matlab, u8 in_gain_shift_matlab, u8 in_gain_mult_matlab)
{
	ASSERT_ERR_CHIP((((u32)out_gain_shift_matlab << 24) & ~((u32)0x03000000)) == 0);
	ASSERT_ERR_CHIP((((u32)out_gain_mult_matlab << 16) & ~((u32)0x007F0000)) == 0);
	ASSERT_ERR_CHIP((((u32)in_gain_shift_matlab << 8) & ~((u32)0x00000300)) == 0);
	ASSERT_ERR_CHIP((((u32)in_gain_mult_matlab << 0) & ~((u32)0x0000007F)) == 0);
	cl_reg_write(chip, MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_ADDR, ((u32)out_gain_shift_matlab << 24) | ((u32)out_gain_mult_matlab << 16) | ((u32)in_gain_shift_matlab << 8) | ((u32)in_gain_mult_matlab << 0));
}

static inline void macdsp_api_riu_dpd_gain_ant_0_from_matlab_unpack(struct cl_chip *chip, u8 *out_gain_shift_matlab, u8 *out_gain_mult_matlab, u8 *in_gain_shift_matlab, u8 *in_gain_mult_matlab)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_ADDR);

	*out_gain_shift_matlab = (local_val & ((u32)0x03000000)) >> 24;
	*out_gain_mult_matlab = (local_val & ((u32)0x007F0000)) >> 16;
	*in_gain_shift_matlab = (local_val & ((u32)0x00000300)) >> 8;
	*in_gain_mult_matlab = (local_val & ((u32)0x0000007F)) >> 0;
}

static inline u8 macdsp_api_riu_dpd_gain_ant_0_from_matlab_out_gain_shift_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_ADDR);

	return (u8)((local_val & ((u32)0x03000000)) >> 24);
}

static inline void macdsp_api_riu_dpd_gain_ant_0_from_matlab_out_gain_shift_matlab_setf(struct cl_chip *chip, u8 outgainshiftmatlab)
{
	ASSERT_ERR_CHIP((((u32)outgainshiftmatlab << 24) & ~((u32)0x03000000)) == 0);
	cl_reg_write(chip, MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_ADDR) & ~((u32)0x03000000)) | ((u32)outgainshiftmatlab << 24));
}

static inline u8 macdsp_api_riu_dpd_gain_ant_0_from_matlab_out_gain_mult_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_ADDR);

	return (u8)((local_val & ((u32)0x007F0000)) >> 16);
}

static inline void macdsp_api_riu_dpd_gain_ant_0_from_matlab_out_gain_mult_matlab_setf(struct cl_chip *chip, u8 outgainmultmatlab)
{
	ASSERT_ERR_CHIP((((u32)outgainmultmatlab << 16) & ~((u32)0x007F0000)) == 0);
	cl_reg_write(chip, MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_ADDR) & ~((u32)0x007F0000)) | ((u32)outgainmultmatlab << 16));
}

static inline u8 macdsp_api_riu_dpd_gain_ant_0_from_matlab_in_gain_shift_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_ADDR);

	return (u8)((local_val & ((u32)0x00000300)) >> 8);
}

static inline void macdsp_api_riu_dpd_gain_ant_0_from_matlab_in_gain_shift_matlab_setf(struct cl_chip *chip, u8 ingainshiftmatlab)
{
	ASSERT_ERR_CHIP((((u32)ingainshiftmatlab << 8) & ~((u32)0x00000300)) == 0);
	cl_reg_write(chip, MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_ADDR) & ~((u32)0x00000300)) | ((u32)ingainshiftmatlab << 8));
}

static inline u8 macdsp_api_riu_dpd_gain_ant_0_from_matlab_in_gain_mult_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_ADDR);

	return (u8)((local_val & ((u32)0x0000007F)) >> 0);
}

static inline void macdsp_api_riu_dpd_gain_ant_0_from_matlab_in_gain_mult_matlab_setf(struct cl_chip *chip, u8 ingainmultmatlab)
{
	ASSERT_ERR_CHIP((((u32)ingainmultmatlab << 0) & ~((u32)0x0000007F)) == 0);
	cl_reg_write(chip, MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_0_FROM_MATLAB_ADDR) & ~((u32)0x0000007F)) | ((u32)ingainmultmatlab << 0));
}

/**
 * @brief RIU_DPD_GAIN_ANT_1_FROM_MATLAB register definition
 *  RIU_DPD_GAIN_ANT_1_FROM_MATLAB register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    25:24 Out_Gain_Shift_matlab     0x0
 *    22:16 Out_Gain_Mult_matlab      0x0
 *    09:08 In_Gain_Shift_matlab      0x0
 *    06:00 In_Gain_Mult_matlab       0x0
 * </pre>
 */
#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000009F0)
#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_OFFSET      0x000009F0
#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_INDEX       0x0000027C
#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_RESET       0x00000000

static inline u32 macdsp_api_riu_dpd_gain_ant_1_from_matlab_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_ADDR);
}

static inline void macdsp_api_riu_dpd_gain_ant_1_from_matlab_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_OUT_GAIN_SHIFT_MATLAB_MASK    ((u32)0x03000000)
#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_OUT_GAIN_SHIFT_MATLAB_LSB    24
#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_OUT_GAIN_SHIFT_MATLAB_WIDTH    ((u32)0x00000002)
#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_OUT_GAIN_MULT_MATLAB_MASK    ((u32)0x007F0000)
#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_OUT_GAIN_MULT_MATLAB_LSB    16
#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_OUT_GAIN_MULT_MATLAB_WIDTH    ((u32)0x00000007)
#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_IN_GAIN_SHIFT_MATLAB_MASK    ((u32)0x00000300)
#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_IN_GAIN_SHIFT_MATLAB_LSB    8
#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_IN_GAIN_SHIFT_MATLAB_WIDTH    ((u32)0x00000002)
#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_IN_GAIN_MULT_MATLAB_MASK    ((u32)0x0000007F)
#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_IN_GAIN_MULT_MATLAB_LSB    0
#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_IN_GAIN_MULT_MATLAB_WIDTH    ((u32)0x00000007)

#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_OUT_GAIN_SHIFT_MATLAB_RST    0x0
#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_OUT_GAIN_MULT_MATLAB_RST    0x0
#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_IN_GAIN_SHIFT_MATLAB_RST    0x0
#define MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_IN_GAIN_MULT_MATLAB_RST    0x0

static inline void macdsp_api_riu_dpd_gain_ant_1_from_matlab_pack(struct cl_chip *chip, u8 out_gain_shift_matlab, u8 out_gain_mult_matlab, u8 in_gain_shift_matlab, u8 in_gain_mult_matlab)
{
	ASSERT_ERR_CHIP((((u32)out_gain_shift_matlab << 24) & ~((u32)0x03000000)) == 0);
	ASSERT_ERR_CHIP((((u32)out_gain_mult_matlab << 16) & ~((u32)0x007F0000)) == 0);
	ASSERT_ERR_CHIP((((u32)in_gain_shift_matlab << 8) & ~((u32)0x00000300)) == 0);
	ASSERT_ERR_CHIP((((u32)in_gain_mult_matlab << 0) & ~((u32)0x0000007F)) == 0);
	cl_reg_write(chip, MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_ADDR, ((u32)out_gain_shift_matlab << 24) | ((u32)out_gain_mult_matlab << 16) | ((u32)in_gain_shift_matlab << 8) | ((u32)in_gain_mult_matlab << 0));
}

static inline void macdsp_api_riu_dpd_gain_ant_1_from_matlab_unpack(struct cl_chip *chip, u8 *out_gain_shift_matlab, u8 *out_gain_mult_matlab, u8 *in_gain_shift_matlab, u8 *in_gain_mult_matlab)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_ADDR);

	*out_gain_shift_matlab = (local_val & ((u32)0x03000000)) >> 24;
	*out_gain_mult_matlab = (local_val & ((u32)0x007F0000)) >> 16;
	*in_gain_shift_matlab = (local_val & ((u32)0x00000300)) >> 8;
	*in_gain_mult_matlab = (local_val & ((u32)0x0000007F)) >> 0;
}

static inline u8 macdsp_api_riu_dpd_gain_ant_1_from_matlab_out_gain_shift_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_ADDR);

	return (u8)((local_val & ((u32)0x03000000)) >> 24);
}

static inline void macdsp_api_riu_dpd_gain_ant_1_from_matlab_out_gain_shift_matlab_setf(struct cl_chip *chip, u8 outgainshiftmatlab)
{
	ASSERT_ERR_CHIP((((u32)outgainshiftmatlab << 24) & ~((u32)0x03000000)) == 0);
	cl_reg_write(chip, MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_ADDR) & ~((u32)0x03000000)) | ((u32)outgainshiftmatlab << 24));
}

static inline u8 macdsp_api_riu_dpd_gain_ant_1_from_matlab_out_gain_mult_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_ADDR);

	return (u8)((local_val & ((u32)0x007F0000)) >> 16);
}

static inline void macdsp_api_riu_dpd_gain_ant_1_from_matlab_out_gain_mult_matlab_setf(struct cl_chip *chip, u8 outgainmultmatlab)
{
	ASSERT_ERR_CHIP((((u32)outgainmultmatlab << 16) & ~((u32)0x007F0000)) == 0);
	cl_reg_write(chip, MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_ADDR) & ~((u32)0x007F0000)) | ((u32)outgainmultmatlab << 16));
}

static inline u8 macdsp_api_riu_dpd_gain_ant_1_from_matlab_in_gain_shift_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_ADDR);

	return (u8)((local_val & ((u32)0x00000300)) >> 8);
}

static inline void macdsp_api_riu_dpd_gain_ant_1_from_matlab_in_gain_shift_matlab_setf(struct cl_chip *chip, u8 ingainshiftmatlab)
{
	ASSERT_ERR_CHIP((((u32)ingainshiftmatlab << 8) & ~((u32)0x00000300)) == 0);
	cl_reg_write(chip, MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_ADDR) & ~((u32)0x00000300)) | ((u32)ingainshiftmatlab << 8));
}

static inline u8 macdsp_api_riu_dpd_gain_ant_1_from_matlab_in_gain_mult_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_ADDR);

	return (u8)((local_val & ((u32)0x0000007F)) >> 0);
}

static inline void macdsp_api_riu_dpd_gain_ant_1_from_matlab_in_gain_mult_matlab_setf(struct cl_chip *chip, u8 ingainmultmatlab)
{
	ASSERT_ERR_CHIP((((u32)ingainmultmatlab << 0) & ~((u32)0x0000007F)) == 0);
	cl_reg_write(chip, MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_RIU_DPD_GAIN_ANT_1_FROM_MATLAB_ADDR) & ~((u32)0x0000007F)) | ((u32)ingainmultmatlab << 0));
}

/**
 * @brief RIU_DPD_CHAIN_SIZE_FROM_MATLAB register definition
 *  RIU_DPD_CHAIN_SIZE_FROM_MATLAB register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    19:16 chain_size_ant_1_matlab   0x0
 *    03:00 chain_size_ant_0_matlab   0x0
 * </pre>
 */
#define MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000009F4)
#define MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_OFFSET      0x000009F4
#define MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_INDEX       0x0000027D
#define MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_RESET       0x00000000

static inline u32 macdsp_api_riu_dpd_chain_size_from_matlab_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_ADDR);
}

static inline void macdsp_api_riu_dpd_chain_size_from_matlab_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_CHAIN_SIZE_ANT_1_MATLAB_MASK    ((u32)0x000F0000)
#define MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_CHAIN_SIZE_ANT_1_MATLAB_LSB    16
#define MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_CHAIN_SIZE_ANT_1_MATLAB_WIDTH    ((u32)0x00000004)
#define MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_CHAIN_SIZE_ANT_0_MATLAB_MASK    ((u32)0x0000000F)
#define MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_CHAIN_SIZE_ANT_0_MATLAB_LSB    0
#define MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_CHAIN_SIZE_ANT_0_MATLAB_WIDTH    ((u32)0x00000004)

#define MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_CHAIN_SIZE_ANT_1_MATLAB_RST    0x0
#define MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_CHAIN_SIZE_ANT_0_MATLAB_RST    0x0

static inline void macdsp_api_riu_dpd_chain_size_from_matlab_pack(struct cl_chip *chip, u8 chain_size_ant_1_matlab, u8 chain_size_ant_0_matlab)
{
	ASSERT_ERR_CHIP((((u32)chain_size_ant_1_matlab << 16) & ~((u32)0x000F0000)) == 0);
	ASSERT_ERR_CHIP((((u32)chain_size_ant_0_matlab << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_ADDR, ((u32)chain_size_ant_1_matlab << 16) | ((u32)chain_size_ant_0_matlab << 0));
}

static inline void macdsp_api_riu_dpd_chain_size_from_matlab_unpack(struct cl_chip *chip, u8 *chain_size_ant_1_matlab, u8 *chain_size_ant_0_matlab)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_ADDR);

	*chain_size_ant_1_matlab = (local_val & ((u32)0x000F0000)) >> 16;
	*chain_size_ant_0_matlab = (local_val & ((u32)0x0000000F)) >> 0;
}

static inline u8 macdsp_api_riu_dpd_chain_size_from_matlab_chain_size_ant_1_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_ADDR);

	return (u8)((local_val & ((u32)0x000F0000)) >> 16);
}

static inline void macdsp_api_riu_dpd_chain_size_from_matlab_chain_size_ant_1_matlab_setf(struct cl_chip *chip, u8 chainsizeant1matlab)
{
	ASSERT_ERR_CHIP((((u32)chainsizeant1matlab << 16) & ~((u32)0x000F0000)) == 0);
	cl_reg_write(chip, MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_ADDR) & ~((u32)0x000F0000)) | ((u32)chainsizeant1matlab << 16));
}

static inline u8 macdsp_api_riu_dpd_chain_size_from_matlab_chain_size_ant_0_matlab_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_ADDR);

	return (u8)((local_val & ((u32)0x0000000F)) >> 0);
}

static inline void macdsp_api_riu_dpd_chain_size_from_matlab_chain_size_ant_0_matlab_setf(struct cl_chip *chip, u8 chainsizeant0matlab)
{
	ASSERT_ERR_CHIP((((u32)chainsizeant0matlab << 0) & ~((u32)0x0000000F)) == 0);
	cl_reg_write(chip, MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_ADDR, (cl_reg_read(chip, MACDSP_API_RIU_DPD_CHAIN_SIZE_FROM_MATLAB_ADDR) & ~((u32)0x0000000F)) | ((u32)chainsizeant0matlab << 0));
}

/**
 * @brief RIU_IQDC_RX_LENGTH_CFG_FROM_ENV register definition
 *  RIU_IQDC_RX_LENGTH_CFG_FROM_ENV register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    00    LENGTH_CFG_FROM_ENV       0
 * </pre>
 */
#define MACDSP_API_RIU_IQDC_RX_LENGTH_CFG_FROM_ENV_ADDR        (REG_MACDSP_API_BASE_ADDR + 0x000009F8)
#define MACDSP_API_RIU_IQDC_RX_LENGTH_CFG_FROM_ENV_OFFSET      0x000009F8
#define MACDSP_API_RIU_IQDC_RX_LENGTH_CFG_FROM_ENV_INDEX       0x0000027E
#define MACDSP_API_RIU_IQDC_RX_LENGTH_CFG_FROM_ENV_RESET       0x00000000

static inline u32 macdsp_api_riu_iqdc_rx_length_cfg_from_env_get(struct cl_chip *chip)
{
	return cl_reg_read(chip, MACDSP_API_RIU_IQDC_RX_LENGTH_CFG_FROM_ENV_ADDR);
}

static inline void macdsp_api_riu_iqdc_rx_length_cfg_from_env_set(struct cl_chip *chip, u32 value)
{
	cl_reg_write(chip, MACDSP_API_RIU_IQDC_RX_LENGTH_CFG_FROM_ENV_ADDR, value);
}

/* Field definitions */
#define MACDSP_API_RIU_IQDC_RX_LENGTH_CFG_FROM_ENV_LENGTH_CFG_FROM_ENV_BIT    ((u32)0x00000001)
#define MACDSP_API_RIU_IQDC_RX_LENGTH_CFG_FROM_ENV_LENGTH_CFG_FROM_ENV_POS    0

#define MACDSP_API_RIU_IQDC_RX_LENGTH_CFG_FROM_ENV_LENGTH_CFG_FROM_ENV_RST    0x0

static inline u8 macdsp_api_riu_iqdc_rx_length_cfg_from_env_length_cfg_from_env_getf(struct cl_chip *chip)
{
	u32 local_val = cl_reg_read(chip, MACDSP_API_RIU_IQDC_RX_LENGTH_CFG_FROM_ENV_ADDR);

	return (u8)(local_val >> 0);
}

static inline void macdsp_api_riu_iqdc_rx_length_cfg_from_env_length_cfg_from_env_setf(struct cl_chip *chip, u8 lengthcfgfromenv)
{
	ASSERT_ERR_CHIP((((u32)lengthcfgfromenv << 0) & ~((u32)0x00000001)) == 0);
	cl_reg_write(chip, MACDSP_API_RIU_IQDC_RX_LENGTH_CFG_FROM_ENV_ADDR, (u32)lengthcfgfromenv << 0);
}

#endif /* REG_MACDSP_API_H */
