// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_config.h"
#include "chip_config.h"
#include "chip_ops.h"
#include "cl_msg_tx.h"

char *cl_install_dir = "/cl6k";
module_param_named(cl_install_dir, cl_install_dir, charp, 0644);
MODULE_PARM_DESC(cl_install_dir, "Driver installation folder");

char *cl_config_dir = "/nvram/cl6k";
module_param_named(cl_config_dir, cl_config_dir, charp, 0644);
MODULE_PARM_DESC(cl_config_dir, "Driver configuration folder");

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

static int cl_config_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "config usage:\n"
		 "-b : Set BW Signaling Mode (For Debug)\n"
		 "-c : Print chip configuration\n"
		 "-n : Set NDP TX parameters [chain mask][bw][format][num_ltf]\n"
		 "-t : Print tcv configuration\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

int cl_config_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	bool set_bw_sig = false;
	bool print_chip = false;
	bool set_ndp_tx_ctrl = false;
	bool print_tcv = false;
	int expected_params = -1;

	switch (cli_params->option) {
	case 'b':
		set_bw_sig = true;
		expected_params = 1;
		break;
	case 'c':
		print_chip = true;
		expected_params = 0;
		break;
	case 'n':
		set_ndp_tx_ctrl = true;
		expected_params = 4;
		break;
	case 't':
		print_tcv = true;
		expected_params = 0;
		break;
	case '?':
		return cl_config_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (set_bw_sig) {
		cl_hw->conf->ce_bw_signaling_mode = (u8)cli_params->params[0];
		cl_msg_tx_bw_signaling_mode(cl_hw, cl_hw->conf->ce_bw_signaling_mode);
		return 0;
	}

	if (print_chip) {
		chip_ops_config_print(cl_hw->chip);
		return 0;
	}

	if (set_ndp_tx_ctrl) {
		u8 chain_mask = (u8)cli_params->params[0];
		u8 bw = (u8)cli_params->params[1];
		u8 format = (u8)cli_params->params[2];
		u8 num_ltf = (u8)cli_params->params[3];

		if (IS_VALID_TX_CHAINS(chain_mask) &&
		    bw < CHNL_BW_MAX &&
		    format < FORMATMOD_MAX &&
		    num_ltf < LTF_MAX) {
			cl_hw->conf->ci_ndp_tx_chain_mask = chain_mask;
			cl_hw->conf->ci_ndp_tx_bw = bw;
			cl_hw->conf->ci_ndp_tx_format = format;
			cl_hw->conf->ci_ndp_tx_num_ltf = num_ltf;
			cl_msg_tx_ndp_tx_control(cl_hw, chain_mask, bw, format, num_ltf);
		} else {
			pr_err("Invalid parametets [chain_mask %x][bw %u][format %u][num_ltf %u]\n",
			       chain_mask, bw, format, num_ltf);
		}
		return 0;
	}

	if (print_tcv) {
		cl_tcv_config_print(cl_hw);
		return 0;
	}

out_err:
	return -EIO;
}
