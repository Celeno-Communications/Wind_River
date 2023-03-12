/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CHIP_CONFIG_H
#define CHIP_CONFIG_H

#include <linux/types.h>
#include <linux/if_ether.h>
#include "string.h"
#include "def.h"

/* Each chip supports two TCVs */
#define TCV0    0
#define TCV1    1
#define TCV_MAX 2

#define CC_MAX_LEN 3 /* 2 characters + null */
#define FW_MAX_NAME 32
#define CL_PTA_WIFI_TIMEOUT         10000  /* Wifi - 10ms */
#define CL_PTA_BT_TIMEOUT           10000  /* Bt - 10ms */

#define USB_TX_PDMAS_MAX 16
#define USB_RX_DATA_URB_NUM 64
#define USB_RXM_DATA_URB_NUM 128
/* Maximum Rx containers per URB */
#define USB_RX_CONT_MAX 16

enum cl_chip_index {
	CHIP0,
	CHIP1,
	CHIP2,
	CHIP3,
	CHIP_MAX
};

#define TCV_TOTAL (CHIP_MAX * TCV_MAX)

enum cl_temp_state {
	TEMP_PROTECT_OFF,
	TEMP_PROTECT_INTERNAL,
	TEMP_PROTECT_EXTERNAL,
	TEMP_PROTECT_DIFF
};

enum cl_e2p_mode {
	E2P_MODE_DISABLED,
	E2P_MODE_ENABLED,

	E2P_MODE_MAX
};

enum cl_otp_mode {
	OTP_MODE_BIN,
	OTP_MODE,

	OTP_MODE_MAX
};

enum cl_wifi_mode {
	WIFI_MODE_PCI,
	WIFI_MODE_USB,

	WIFI_MODE_MAX
};

enum cl_twin_peak_mode {
	TWINPEAK_MODE_DISABLE,
	TWINPEAK_MODE_NO_RF,
	TWINPEAK_MODE_ALASKA,

	TWINPEAK_MODE_MAX
};

enum cl_module_hw_type_mode {
	MODULE_HW_MODE_PYTHON,
	MODULE_HW_MODE_PYTHON_PEAK,

	MODULE_HW_MODE_MAX
};

/* USB TX LLI channel index */
enum umac_tx_lli_channel_index {
	UMAC_TX_LLI_CH_DATA_AC0_IDX,
	UMAC_TX_LLI_CH_DATA_AC1_IDX,
	UMAC_TX_LLI_CH_DATA_AC2_IDX,
	UMAC_TX_LLI_CH_DATA_AC3_IDX,
	UMAC_TX_LLI_CH_BCAST_IDX,
	UMAC_TX_LLI_CH_HTP_IDX,

	UMAC_TX_LLI_CH_MAX
};

enum cl_usb_tx_mode {
	USB_TX_MODE_NORMAL,
	USB_TX_MODE_NO_XFER_SPLIT,
	USB_TX_MODE_PAD_PDMAS,
	USB_TX_MODE_RESERVED,
	USB_TX_MODE_BUFFERED,
	USB_TX_MODE_PLAIN_IDMA,
	USB_TX_MODE_BUFFERED_TCI_SPLIT,
	USB_TX_MODE_BUFFERED_TCI_ETH_NONSTD,

	USB_TX_MODE_MAX
};

/* This string in nvram file means that there is no binary image needed
 * to upload on this core
 */
#define TEST_NO_LOAD "no_load"

struct cl_chip_conf {
	bool ce_tcv_enabled[TCV_MAX];
	s8 ce_lmac[FW_MAX_NAME];
	s8 ce_smac[FW_MAX_NAME];
	s8 ce_umac[FW_MAX_NAME];
	s32 ce_irq_smp_affinity;
	u8 ce_eeprom_en;
	u8 ce_otp_mode;
	bool ce_production_mode;
	bool ci_pci_msi_enable;
	u8 ci_dma_lli_max_chan[TCV_MAX];
	s8 ce_country_code[CC_MAX_LEN];
	s8 ce_ela_mode[STR_LEN_64B];
	u8 ci_phy_dev;
	s8 ce_debug_level;
	u8 ce_host_pci_gen_ver;
	s32 ci_scale_down_fw;
	bool ce_temp_comp_en;
	u8 ce_temp_protect_en;
	s8 ce_temp_protect_delta;
	s16 ce_temp_protect_th_max;
	s16 ce_temp_protect_th_min;
	u16 ce_temp_protect_tx_period_ms;
	s16 ce_temp_protect_radio_off_th;
	bool ci_phy_load_bootdrv;
	u8 ce_phys_mac_addr[ETH_ALEN];
	bool ce_lam_enable;
	u8 ce_first_mask_bit;
	bool ci_no_capture_noise_sleep;
	u8 ci_twin_peak_mode;
	u32 ci_afe_vc_ref;
	bool ci_afe_loopback;
	bool ci_afe_hw_mode;
	bool ci_rx_resched_tasklet;
	u32 ci_rx_skb_max;
	u8 ce_bt_mode;
	u8 ci_tx_usb_mode[UMAC_TX_LLI_CH_MAX];
	u8 ci_tx_usb_max_pdmas[UMAC_TX_LLI_CH_MAX];
	u16 ci_usb_rx_cont_num[CL_RX_BUF_MAX];
	u16 ci_usb_rx_urb_num[CL_RX_BUF_MAX];
	u32 ci_pta_wifi_to;
	u32 ci_pta_bt_to;
	u8 ci_pta_conc_allow_more_2g;
	u8 ci_fw_reg_dbg;
	bool ci_umac_wd_en;
	bool ce_calib_runtime_en;
	bool ce_calib_runtime_write_to_files_en;
	bool ci_calib_eeprom_en;
	bool ci_calib_iq_plan_en;
	bool ci_calib_runtime_force;
	u8 ci_calib_matlab_ip[ETH_IP_ADDR_LEN];
	s8 ci_calib_matlab_user_name[MATLAB_USER_NAME_LEN];
	u8 ci_dcoc_mv_thr[CHNL_BW_MAX];
	bool ci_calib_check_errors;
	s8 ci_lolc_db_thr;
	s8 ci_iq_db_thr;
	u8 ci_dcoc_max_vga;
	bool ci_calib_is_dpd_enable;
	u16 ci_calib_init_rx_gain[MAX_CALIBRATION_TYPE_NUM];
	u8 ci_calib_init_tx_gain[MAX_CALIBRATION_TYPE_NUM];
	u8 ci_calib_bt_channel_idx_1m[BT_CALIBRATION_CHANNLES_NUM];
	u8 ci_calib_bt_channel_idx_2m[BT_CALIBRATION_CHANNLES_NUM];
	u8 ci_calib_bt_num_of_ch_idx;
	u8 ci_calib_bt_bw_bitmap;
	u8 ci_calib_iq_mode_bitmap;
	u8 rw_data_public_addr[ETH_ALEN];
	u8 ci_rf_init_dis;
	u8 ci_rf_calib_dis;
	u8 ci_rf_bt_init;
	u8 ci_rx_ch_0_tx_ch_1_en;
	u8 ci_rf_bt_zero_if_en;
	/* New NVRAM parameters must be added to cl_chip_config_print() */
};

struct cl_chip;

int cl_chip_config_read(struct cl_chip *chip);
int cl_chip_config_set(struct cl_chip *chip, char *buf, loff_t size);
void cl_chip_config_dealloc(struct cl_chip *chip);
void cl_chip_config_print(struct cl_chip *chip);

#endif /* CHIP_CONFIG_H */
