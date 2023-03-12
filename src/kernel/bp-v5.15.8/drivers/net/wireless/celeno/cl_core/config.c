// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/string.h>
#include <linux/firmware.h>
#include "core_debug.h"
#include "config.h"
#include "file.h"
#include "chip.h"

static char *non_driver_conf_params[] = {
	"ws_",
	"ha_",
	"uuid1",
	"ce_pci_id",
	"ce_rst_gpio",
	"ce_iface_eth",
	"ce_iface_vlan",
	"ce_iface_ip",
	"ci_sim_chip_num",
	"ci_lcu_dump_folder",
	"ci_server_addr",
	"ci_server_user",
	"ce_bridge_en",
	NULL
};

bool cl_config_is_non_driver_param(char *name)
{
	int i = 0;

	for (i = 0; non_driver_conf_params[i]; i++)
		if (!strncmp(name, non_driver_conf_params[i], strlen(non_driver_conf_params[i])))
			return true;

	return false;
}

int add_bt_config(struct cl_chip *chip, u8 *data)
{
	char filename[CL_FILENAME_MAX] = {0};
	const struct firmware *fw;
	int ret = 0;

	if (chip->conf->ce_bt_mode == BT_MODE_OFF)
		return 0;

	snprintf(filename, sizeof(filename), "cl6k/bt_config_%u.bin",
		 chip->idx);

	ret = request_firmware(&fw, filename, chip->dev);

	if (ret) {
		cl_dbg_chip_err(chip, "failed to get %s %x\n", filename, ret);
		return ret;
	}

	if (!fw || !fw->data || fw->size > SMAC_DRAM9_FILE_MAX_SIZE) {
		cl_dbg_chip_err(chip, "Invalid firmware %s\n", filename);
		ret = -EINVAL;
		goto out;
	}

	memcpy(data + SMAC_DRAM9_CONF_FILE_ADDR, fw->data, fw->size);

out:
	release_firmware(fw);

	return ret;
}
EXPORT_SYMBOL(add_bt_config);
