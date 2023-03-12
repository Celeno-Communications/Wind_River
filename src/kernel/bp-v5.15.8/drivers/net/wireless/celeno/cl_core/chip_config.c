// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "core_debug.h"
#include "chip_config.h"
#include "chip.h"
#include "file.h"
#include "config.h"

#define MAX_FIRST_MASK_BIT ((ETH_ALEN * 8) - 1)

static struct cl_chip_conf chip_conf = {
	.ce_tcv_enabled = {true, false},
	.ce_lmac = "lmacfw.bin",
	.ce_smac = TEST_NO_LOAD,
	.ce_umac = TEST_NO_LOAD,
	.ce_irq_smp_affinity = -1,
	.ce_eeprom_en = E2P_MODE_ENABLED,
	.ce_otp_mode = OTP_MODE_BIN,
	.ce_production_mode = false,
	.ci_pci_msi_enable = true,
	.ci_dma_lli_max_chan = {6, 3},
	.ce_country_code = "US",
	.ce_ela_mode = "default",
	.ci_phy_dev = PHY_DEV_DENALI,
	.ce_debug_level = DBG_LVL_ERROR,
	.ce_host_pci_gen_ver = 3,
	.ci_scale_down_fw = 1,
	.ce_temp_comp_en = false,
	.ce_temp_protect_en = TEMP_PROTECT_OFF,
	.ce_temp_protect_delta = 0,
	.ce_temp_protect_th_max = 110,
	.ce_temp_protect_th_min = 100,
	.ce_temp_protect_tx_period_ms = 50,
	.ce_temp_protect_radio_off_th = 115,
	.ci_phy_load_bootdrv = false,
	.ce_phys_mac_addr = {0},
	.ce_lam_enable = true,
	.ce_first_mask_bit = 0,
	.ci_no_capture_noise_sleep = true,
	.ci_twin_peak_mode = TWINPEAK_MODE_ALASKA,
	.ci_afe_vc_ref = 0x44444444,
	.ci_afe_loopback = false,
	.ci_afe_hw_mode = true,
	.ci_rx_resched_tasklet = false,
	.ci_rx_skb_max = 10000,
	.ce_bt_mode = BT_MODE_OFF,
	.ci_tx_usb_mode = {
		USB_TX_MODE_NORMAL, USB_TX_MODE_NORMAL,
		USB_TX_MODE_NORMAL, USB_TX_MODE_NORMAL,
		USB_TX_MODE_NORMAL, USB_TX_MODE_NORMAL
	},
	.ci_tx_usb_max_pdmas = {
		USB_TX_PDMAS_MAX, USB_TX_PDMAS_MAX,
		USB_TX_PDMAS_MAX, USB_TX_PDMAS_MAX,
		USB_TX_PDMAS_MAX, USB_TX_PDMAS_MAX
	},
	.ci_usb_rx_cont_num = {USB_RX_CONT_MAX, USB_RX_CONT_MAX},
	.ci_usb_rx_urb_num = {USB_RXM_DATA_URB_NUM, USB_RX_DATA_URB_NUM},
	.ci_pta_wifi_to = CL_PTA_WIFI_TIMEOUT,
	.ci_pta_bt_to = CL_PTA_BT_TIMEOUT,
	.ci_pta_conc_allow_more_2g = 1,
	.ci_fw_reg_dbg = 0,
	.ci_umac_wd_en = true,
	.ce_calib_runtime_en = false,
	.ce_calib_runtime_write_to_files_en = false,
	.ci_calib_eeprom_en = 0,
	.ci_calib_iq_plan_en = false,
	.ci_calib_runtime_force = false,
	.ci_calib_matlab_ip = {10, 14, 86, 45},/*{0,0,0,0},*/
	.ci_calib_matlab_user_name = "Math.Doron",
	.ci_dcoc_mv_thr = {150, 100, 100, 100},
	.ci_calib_check_errors = false,
	.ci_lolc_db_thr = -40,
	.ci_iq_db_thr = -46,
	.ci_dcoc_max_vga = 25,
	.ci_calib_is_dpd_enable = false,
	.ci_calib_init_rx_gain = {0, 0, 0x1c0, 0x1c0, 0x1c0, 0x1c0, 0x1c0, 0, 0, 0},
	.ci_calib_init_tx_gain = {0, 0, 0x3b, 0x3b, 0x3b, 0x3b, 0x3b, 0, 0, 0},
	.ci_calib_bt_channel_idx_1m = {0, 39, 78},
	.ci_calib_bt_channel_idx_2m = {1, 39, 77},
	.ci_calib_bt_num_of_ch_idx = 1,
	.ci_calib_bt_bw_bitmap = 3,
	.ci_calib_iq_mode_bitmap = 0x6,
	.ci_rf_init_dis = 0,
	.ci_rf_calib_dis = 0,
	.ci_rf_bt_init = 0,
	.ci_rx_ch_0_tx_ch_1_en = 0,
	.ci_rf_bt_zero_if_en = 1,
};

static int update_config_wifi(struct cl_chip *chip, char *name, char *value)
{
	struct cl_chip_conf *conf = chip->conf;
	int ret = -ENOENT;

	do {
		READ_BOOL_ARR(ce_tcv_enabled, TCV_MAX);
		READ_STR(ce_lmac);
		READ_STR(ce_smac);
		READ_STR(ce_umac);
		READ_S32(ce_irq_smp_affinity);
		READ_U8(ce_eeprom_en);
		READ_U8(ce_otp_mode);
		READ_BOOL(ce_production_mode);
		READ_BOOL(ci_pci_msi_enable);
		READ_U8_ARR(ci_dma_lli_max_chan, TCV_MAX);
		READ_STR(ce_country_code);
		READ_STR(ce_ela_mode);
		READ_U8(ci_phy_dev);
		READ_S8(ce_debug_level);
		READ_U8(ce_host_pci_gen_ver);
		READ_S32(ci_scale_down_fw);
		READ_BOOL(ce_temp_comp_en);
		READ_U8(ce_temp_protect_en);
		READ_S8(ce_temp_protect_delta);
		READ_S16(ce_temp_protect_th_max);
		READ_S16(ce_temp_protect_th_min);
		READ_U16(ce_temp_protect_tx_period_ms);
		READ_S16(ce_temp_protect_radio_off_th);
		READ_BOOL(ci_phy_load_bootdrv);
		READ_MAC(ce_phys_mac_addr);
		READ_BOOL(ce_lam_enable);
		READ_U8(ce_first_mask_bit);
		READ_BOOL(ci_no_capture_noise_sleep);
		READ_U8(ci_twin_peak_mode);
		READ_U32(ci_afe_vc_ref);
		READ_BOOL(ci_afe_loopback);
		READ_BOOL(ci_afe_hw_mode);
		READ_BOOL(ci_rx_resched_tasklet);
		READ_U32(ci_rx_skb_max);
		READ_U8(ce_bt_mode);
		READ_U8_ARR(ci_tx_usb_mode, UMAC_TX_LLI_CH_MAX);
		READ_U8_ARR(ci_tx_usb_max_pdmas, UMAC_TX_LLI_CH_MAX);
		READ_U16_ARR(ci_usb_rx_cont_num, CL_RX_BUF_MAX);
		READ_U16_ARR(ci_usb_rx_urb_num, CL_RX_BUF_MAX);
		READ_U32(ci_pta_wifi_to);
		READ_U32(ci_pta_bt_to);
		READ_U8(ci_pta_conc_allow_more_2g);
		READ_U8(ci_fw_reg_dbg);
		READ_BOOL(ci_umac_wd_en);
		READ_BOOL(ce_calib_runtime_en);
		READ_BOOL(ce_calib_runtime_write_to_files_en);
		READ_BOOL(ci_calib_eeprom_en);
		READ_BOOL(ci_calib_iq_plan_en);
		READ_BOOL(ci_calib_runtime_force);
		READ_IP(ci_calib_matlab_ip);
		READ_STR(ci_calib_matlab_user_name);
		READ_U8_ARR(ci_dcoc_mv_thr, CHNL_BW_MAX);
		READ_BOOL(ci_calib_check_errors);
		READ_S8(ci_lolc_db_thr);
		READ_S8(ci_iq_db_thr);
		READ_U8(ci_dcoc_max_vga);
		READ_BOOL(ci_calib_is_dpd_enable);
		READ_U16_ARR(ci_calib_init_rx_gain, MAX_CALIBRATION_TYPE_NUM);
		READ_U8_ARR(ci_calib_init_tx_gain, MAX_CALIBRATION_TYPE_NUM);
		READ_U8_ARR(ci_calib_bt_channel_idx_1m, BT_CALIBRATION_CHANNLES_NUM);
		READ_U8_ARR(ci_calib_bt_channel_idx_2m, BT_CALIBRATION_CHANNLES_NUM);
		READ_U8(ci_calib_bt_bw_bitmap);
		READ_U8(ci_calib_iq_mode_bitmap);
		READ_U8(ci_rf_init_dis);
		READ_U8(ci_rf_calib_dis);
		READ_U8(ci_rf_bt_init);
		READ_U8(ci_calib_bt_num_of_ch_idx);
		READ_U8(ci_rx_ch_0_tx_ch_1_en);
		READ_U8(ci_rf_bt_zero_if_en);
	} while (0);

	if (ret == -ENOENT) {
		if (cl_config_is_non_driver_param(name))
			ret = 0;
		else
			CL_DBG_ERROR_CHIP(chip, "No matching conf for nvram parameter %s\n", name);
	}

	return ret;
}

static int update_config_bt(struct cl_chip *chip, char *name, char *value)
{
	struct cl_chip_conf *conf = chip->conf;
	int ret = -ENOENT;

	do {
		READ_MAC(rw_data_public_addr);
	} while (0);

	return 0;
}

static int post_configuration(struct cl_chip *chip)
{
	struct cl_chip_conf *conf = chip->conf;

	if (!conf->ce_tcv_enabled[TCV0]) {
		CL_DBG_ERROR_CHIP(chip, "TCV0 must be enabled\n");
		return -1;
	}

	if (conf->ce_tcv_enabled[TCV1]) {
		CL_DBG_ERROR_CHIP(chip, "TCV1 can't be enabled\n");
		return -1;
	}

	if (conf->ce_eeprom_en >= E2P_MODE_MAX) {
		CL_DBG_ERROR_CHIP(chip,
				  "Invalid ce_eeprom_en [%u]. Must be 0 (disable) or 1 (enable)\n",
				  conf->ce_eeprom_en);
		return -1;
	}

	if (conf->ce_otp_mode >= OTP_MODE_MAX) {
		CL_DBG_ERROR_CHIP(chip,
				  "Invalid ce_otp_mode [%u]. Must be 0 (file) or 1 (otp)\n",
				  conf->ce_otp_mode);
		return -1;
	}

	if (conf->ce_first_mask_bit > MAX_FIRST_MASK_BIT) {
		CL_DBG_ERROR_CHIP(chip, "Invalid ce_first_mask_bit (%u). Must be <= %u\n",
				  conf->ce_first_mask_bit, MAX_FIRST_MASK_BIT);
		return -1;
	}

	chip->fw_test = strcmp(conf->ce_lmac, "lmacfw.bin") ||
		(strcmp(conf->ce_smac, TEST_NO_LOAD) && strcmp(conf->ce_smac, "smacfw.bin")) ||
		(strcmp(conf->ce_umac, TEST_NO_LOAD) && strcmp(conf->ce_umac, "umacfw.bin"));

	if (!IS_REAL_PHY(chip))
		conf->ci_scale_down_fw = 10;

	if (chip->conf->ci_twin_peak_mode == TWINPEAK_MODE_NO_RF)
		chip->conf->ci_rx_ch_0_tx_ch_1_en = 0;

	return 0;
}

static int set_all_params_from_buf(struct cl_chip *chip, char *buf, loff_t size,
				   int (*update_config)(struct cl_chip *,
							char *, char *))
{
	char *line = buf;
	char name[MAX_PARAM_NAME_LENGTH];
	char value[STR_LEN_512B];
	char *begin;
	char *end;
	int name_length = 0;
	int value_length = 0;

	while (line && strlen(line) && (line != (buf + size))) {
		if ((*line == '#') || (*line == '\n')) {
			/* Skip comment or blank line */
			line = strstr(line, "\n") + 1;
		} else if (*line) {
			begin = line;
			end = strstr(begin, "=");

			if (!end)
				return -1;

			end++;
			name_length = end - begin;
			value_length = strstr(end, "\n") - end + 1;

			if (name_length >= MAX_PARAM_NAME_LENGTH) {
				cl_dbg_chip_err(chip, "Name too long (%u)\n", name_length);
				return -1;
			}
			if (value_length >= STR_LEN_512B) {
				cl_dbg_chip_err(chip, "Value too long (%u)\n", value_length);
				return -1;
			}

			snprintf(name, name_length, "%s", begin);
			snprintf(value, value_length, "%s", end);

			if (update_config(chip, name, value))
				return -1;

			line = strstr(line, "\n") + 1;
		}
	}

	return 0;
}

int cl_chip_config_read(struct cl_chip *chip)
{
	char *buf = NULL;
	loff_t size = 0;
	char filename[CL_FILENAME_MAX] = {0};

	/* Allocate cl_chip_conf */
	if (!chip->conf)
		chip->conf = kzalloc(sizeof(*chip->conf), GFP_KERNEL);

	if (!chip->conf)
		return -ENOMEM;

	/* Copy default parameters */
	memcpy(chip->conf, &chip_conf, sizeof(struct cl_chip_conf));

	snprintf(filename, sizeof(filename), "cl_chip%u.dat", chip->idx);
	pr_debug("%s: %s\n", __func__, filename);
	size = cl_file_open_and_read(chip, filename, &buf);

	if (!buf) {
		pr_err("read %s failed !!!\n", filename);
		return -1;
	}

	if (set_all_params_from_buf(chip, buf, size, update_config_wifi)) {
		kfree(buf);
		return -1;
	}

	kfree(buf);
	buf = NULL;

	if (!cl_chip_is_enabled(chip)) {
		cl_dbg_chip_verbose(chip, "Disabled\n");
		return -1;
	}

	if (post_configuration(chip))
		return -1;

	if (chip->conf->ce_bt_mode) {
		snprintf(filename, sizeof(filename), "cl_chip%u_bt.dat",
			 chip->idx);
		size = cl_file_open_and_read(chip, filename, &buf);

		if (!buf) {
			cl_dbg_chip_verbose(chip, "read %s failed !!!\n",
					    filename);
			return -1;
		}

		if (set_all_params_from_buf(chip, buf, size, update_config_bt)) {
			kfree(buf);
			return -1;
		}

		kfree(buf);
	}

	return 0;
}

int cl_chip_config_set(struct cl_chip *chip, char *buf, loff_t size)
{
	loff_t new_size = size + 1;
	char *new_buf = kzalloc(new_size, GFP_KERNEL);
	int ret;

	if (!new_buf)
		return -1;

	/* Add '\n' at the end of the string, before the NULL */
	memcpy(new_buf, buf, size);
	new_buf[size - 1] = '\n';

	ret = set_all_params_from_buf(chip, new_buf, new_size,
				      update_config_wifi);

	if (ret == 0)
		ret = post_configuration(chip);

	kfree(new_buf);

	return ret;
}

void cl_chip_config_dealloc(struct cl_chip *chip)
{
	kfree(chip->conf);
	chip->conf = NULL;
}

void cl_chip_config_print(struct cl_chip *chip)
{
	struct cl_chip_conf *conf = chip->conf;

	pr_debug("=======================\n");
	pr_debug("  Chip%u configuration\n", chip->idx);
	pr_debug("=======================\n");

	print_unsigned_arr(ce_tcv_enabled, TCV_MAX);
	print_str(ce_lmac);
	print_str(ce_smac);
	print_str(ce_umac);
	print_signed(ce_irq_smp_affinity);
	print_unsigned(ce_eeprom_en);
	print_unsigned(ce_otp_mode);
	print_bool(ce_production_mode);
	print_bool(ci_pci_msi_enable);
	print_unsigned_arr(ci_dma_lli_max_chan, TCV_MAX);
	print_str(ce_country_code);
	print_str(ce_ela_mode);
	print_unsigned(ci_phy_dev);
	print_signed(ce_debug_level);
	print_unsigned(ce_host_pci_gen_ver);
	print_signed(ci_scale_down_fw);
	print_bool(ce_temp_comp_en);
	print_unsigned(ce_temp_protect_en);
	print_signed(ce_temp_protect_delta);
	print_signed(ce_temp_protect_th_max);
	print_signed(ce_temp_protect_th_min);
	print_unsigned(ce_temp_protect_tx_period_ms);
	print_signed(ce_temp_protect_radio_off_th);
	print_bool(ci_phy_load_bootdrv);
	print_mac(ce_phys_mac_addr);
	print_bool(ce_lam_enable);
	print_unsigned(ce_first_mask_bit);
	print_bool(ci_no_capture_noise_sleep);
	print_unsigned(ci_twin_peak_mode);
	print_hex(ci_afe_vc_ref);
	print_bool(ci_afe_loopback);
	print_bool(ci_afe_hw_mode);
	print_bool(ci_rx_resched_tasklet);
	print_unsigned(ci_rx_skb_max);
	print_unsigned(ce_bt_mode);
	print_unsigned_arr(ci_tx_usb_mode, UMAC_TX_LLI_CH_MAX);
	print_unsigned_arr(ci_tx_usb_max_pdmas, UMAC_TX_LLI_CH_MAX);
	print_unsigned_arr(ci_usb_rx_cont_num, CL_RX_BUF_MAX);
	print_unsigned_arr(ci_usb_rx_urb_num, CL_RX_BUF_MAX);
	print_unsigned(ci_pta_wifi_to);
	print_unsigned(ci_pta_bt_to);
	print_unsigned(ci_pta_conc_allow_more_2g);
	print_unsigned(ci_fw_reg_dbg);
	print_bool(ci_umac_wd_en);
	print_bool(ce_calib_runtime_en);
	print_bool(ce_calib_runtime_write_to_files_en);
	print_bool(ci_calib_eeprom_en);
	print_bool(ci_calib_iq_plan_en);
	print_bool(ci_calib_runtime_force);
	print_str(ci_calib_matlab_ip);
	print_str(ci_calib_matlab_user_name);
	print_unsigned_arr(ci_dcoc_mv_thr, CHNL_BW_MAX);
	print_bool(ci_calib_check_errors);
	print_signed(ci_lolc_db_thr);
	print_signed(ci_iq_db_thr);
	print_unsigned(ci_dcoc_max_vga);
	print_bool(ci_calib_is_dpd_enable);
	print_unsigned_arr(ci_calib_init_rx_gain, MAX_CALIBRATION_TYPE_NUM);
	print_unsigned_arr(ci_calib_init_tx_gain, MAX_CALIBRATION_TYPE_NUM);
	print_unsigned_arr(ci_calib_bt_channel_idx_1m, BT_CALIBRATION_CHANNLES_NUM);
	print_unsigned_arr(ci_calib_bt_channel_idx_2m, BT_CALIBRATION_CHANNLES_NUM);
	print_unsigned(ci_calib_bt_bw_bitmap);
	print_unsigned(ci_calib_iq_mode_bitmap);
	print_unsigned(ci_rf_init_dis);
	print_unsigned(ci_rf_calib_dis);
	print_unsigned(ci_rf_bt_init);
	print_unsigned(ci_calib_bt_num_of_ch_idx);
	print_unsigned(ci_rx_ch_0_tx_ch_1_en);
	print_unsigned(ci_rf_bt_zero_if_en);
}
