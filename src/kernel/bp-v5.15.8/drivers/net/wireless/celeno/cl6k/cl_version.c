// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_version.h"
#include "cl_msg_tx.h"
#include "chip.h"
#include "cl_utils.h"
#include "usb.h"

#ifndef DRV_VERSION
#define DRV_VERSION "6.1.0.30"
#endif /* DRV_VERSION */

#define IW_CMD_DOC_VERSION "2.6"

#define AGC_PARAM_MAJOR_MASK   0x00ff0000
#define AGC_PARAM_MINOR_MASK   0x0000ff00
#define AGC_PARAM_INTER_MASK   0x000000ff

#define AGC_PARAM_MAJOR(agc_param) \
        u32_get_bits(agc_param, AGC_PARAM_MAJOR_MASK)
#define AGC_PARAM_MINOR(agc_param) \
        u32_get_bits(agc_param, AGC_PARAM_MINOR_MASK)
#define AGC_PARAM_INTER(agc_param) \
        u32_get_bits(agc_param, AGC_PARAM_INTER_MASK)

#define AGC_RAM_MAJOR_MASK   0x00ff0000
#define AGC_RAM_MINOR_MASK   0x0000ff00
#define AGC_RAM_INTER_MASK   0x000000ff

#define AGC_RAM_MAJOR(agc_ram) \
        u32_get_bits(agc_ram, AGC_RAM_MAJOR_MASK)
#define AGC_RAM_MINOR(agc_ram) \
        u32_get_bits(agc_ram, AGC_RAM_MINOR_MASK)
#define AGC_RAM_INTER(agc_ram) \
        u32_get_bits(agc_ram, AGC_RAM_INTER_MASK)

int cl_version_read(struct cl_hw *cl_hw, bool reply)
{
	struct mm_version_cfm *version_cfm = NULL;
	struct cl_chip *chip = cl_hw->chip;
	int ret = 0;
	char *buf = NULL;
	ssize_t buf_size;
	int len = 0;
	u32 version_agcram;
	u32 version_agcparam;
	u32 major;
	u32 minor;
	u32 internal;
	struct tm tm;

	ret = cl_msg_tx_version(cl_hw);
	if (ret)
		return ret;

	version_cfm = (struct mm_version_cfm *)cl_hw->msg_cfm_params[MM_VERSION_CFM];

	if (!version_cfm)
		return -1;

	cl_snprintf(&buf, &len, &buf_size,
		    "HP VERSION: %s\n", DRV_VERSION);
	cl_snprintf(&buf, &len, &buf_size,
		    "DSP VERSION: 0x%-.8X\n",
		    le32_to_cpu(version_cfm->version_dsp));

	version_agcparam = le32_to_cpu(version_cfm->rf_version.version_agc_param);
	major = AGC_PARAM_MAJOR(version_agcparam);
	minor = AGC_PARAM_MINOR(version_agcparam);
	internal =AGC_PARAM_INTER(version_agcparam);
	cl_snprintf(&buf, &len, &buf_size,
		    "AGC PARAM VERSION: %x.%x.%x\n",
		    major, minor, internal);

	cl_snprintf(&buf, &len, &buf_size,
		    "IW_COMMANDS DOC VERSION: %s\n", IW_CMD_DOC_VERSION);

	version_agcram = le32_to_cpu(version_cfm->version_agcram);
	major = AGC_RAM_MAJOR(version_agcram);
	minor = AGC_RAM_MINOR(version_agcram);
	internal = AGC_RAM_INTER(version_agcram);
	cl_snprintf(&buf, &len, &buf_size,
		    "AGC RAM VERSION: %x.%x.%x\n",
		    major, minor, internal);

	cl_snprintf(&buf, &len, &buf_size, "TX POWER VERSION: %u\n", cl_hw->tx_power_version);

	switch (chip->conf->ci_phy_dev) {
	case PHY_DEV_DENALI:
		cl_snprintf(&buf, &len, &buf_size, "RFIC TYPE: DENALI\n");
		break;
	case PHY_DEV_RESERVED:
		cl_snprintf(&buf, &len, &buf_size, "RFIC TYPE: RESERVED\n");
		break;
	case PHY_DEV_DUMMY:
		cl_snprintf(&buf, &len, &buf_size, "RFIC TYPE: DUMMY\n");
		break;
	case PHY_DEV_FRU:
		cl_snprintf(&buf, &len, &buf_size, "RFIC TYPE: FRU\n");
		break;
	}

	if (chip->conf->ce_bt_mode != BT_MODE_OFF) {
		time64_to_tm(chip->bt_ram_timestamp + CL_TIMESTAMP_1_1_2020, 0, &tm);

		cl_snprintf(&buf, &len, &buf_size, "BT ROM version: %u\n", chip->bt_rom_version);
		cl_snprintf(&buf, &len, &buf_size, "BT RAM version: %u %s\n",
			    chip->bt_ram_version & 0x7fffffff,
			    (chip->bt_ram_version & 0x80000000) ? "(M)" : "");
		cl_snprintf(&buf, &len, &buf_size,
			    "BT RAM timestamp: %d.%02d.%ld %d:%02d:%02d UTC\n",
			    tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,
			    tm.tm_hour, tm.tm_min, tm.tm_sec);
	}

	if (IS_USB_BUS_TYPE(chip)) {
		struct cli_usb_param_version version;

		ret = chip_ops_get_umac_version(chip, &version);
		if (!ret)
			cl_snprintf(&buf, &len, &buf_size,
				    "UMAC protocol: 0x%x firmware=0x%x\n",
				    version.protocol, version.firmware);
	}

	cl_snprintf(&buf, &len, &buf_size, "RF VERSIONS: %u.%u.%u.%u.%u.%u\n",
		    le32_to_cpu(version_cfm->rf_version.version_wifi_mode_transition),
		    le32_to_cpu(version_cfm->rf_version.version_bt_mode_transition),
		    le32_to_cpu(version_cfm->rf_version.version_rfic_lut),
		    le32_to_cpu(version_cfm->rf_version.version_wifi_pll),
		    le32_to_cpu(version_cfm->rf_version.version_rfic_sw),
		    le32_to_cpu(version_cfm->rf_version.version_lo_configuration));

	cl_msg_tx_free_cfm_params(cl_hw, MM_VERSION_CFM);

	if (reply)
		ret = cl_vendor_reply(cl_hw, buf, len);
	else
		pr_debug("%s\n", buf);

	kfree(buf);

	return ret;
}

int cl_version_cli(struct cl_hw *cl_hw)
{
	return cl_version_read(cl_hw, true);
}

