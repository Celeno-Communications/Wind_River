// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_rx_filter.h"
#include "cl_msg_tx.h"
#include "ieee80211_i.h"

static int cl_rx_filter_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "rx_filter usage:\n"
		 "-c : Print configuration\n"
		 "-s : Set Filter [Hex]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static int cl_rx_filter_cli_configuration(struct cl_hw *cl_hw)
{
	char buf[STR_LEN_16B] = {0};

	snprintf(buf, STR_LEN_16B, "0x%08x", cl_hw->rx_filter);

	return cl_vendor_reply(cl_hw, buf, strlen(buf));
}

u32 cl_rx_filter_update_flags(struct cl_hw *cl_hw, u32 filter)
{
	u32 rx_filter = 0;

	if (filter & FIF_ALLMULTI)
		rx_filter |= RX_CNTRL_ACCEPT_MULTICAST_BIT;

	if (filter & (FIF_FCSFAIL | FIF_PLCPFAIL))
		rx_filter |= RX_CNTRL_ACCEPT_ERROR_FRAMES_BIT;

	if (filter & FIF_BCN_PRBRESP_PROMISC)
		rx_filter |= RX_CNTRL_ACCEPT_OTHER_BSSID_BIT;

	if (filter & FIF_CONTROL)
		rx_filter |= RX_CNTRL_ACCEPT_OTHER_CNTRL_FRAMES_BIT |
			     RX_CNTRL_ACCEPT_CF_END_BIT |
			     RX_CNTRL_ACCEPT_ACK_BIT |
			     RX_CNTRL_ACCEPT_CTS_BIT |
			     RX_CNTRL_ACCEPT_RTS_BIT |
			     RX_CNTRL_ACCEPT_BA_BIT | RX_CNTRL_ACCEPT_BAR_BIT;

	if (filter & FIF_OTHER_BSS)
		rx_filter |= RX_CNTRL_ACCEPT_OTHER_BSSID_BIT;

	if (filter & FIF_PSPOLL)
		rx_filter |= RX_CNTRL_ACCEPT_PS_POLL_BIT;

	if (filter & FIF_PROBE_REQ)
		rx_filter |= RX_CNTRL_ACCEPT_PROBE_REQ_BIT;

	/* Add the filter flags that are set by default and cannot be changed here */
	rx_filter |= CL_MAC80211_NOT_CHANGEABLE;

	if (ieee80211_hw_check(cl_hw->hw, AMPDU_AGGREGATION))
		rx_filter |= RX_CNTRL_ACCEPT_BA_BIT;

	rx_filter |= RX_CNTRL_ACCEPT_BAR_BIT | RX_CNTRL_ACCEPT_RTS_BIT;

	return rx_filter;
}

static u32 cl_filter_get_flags(struct net_device *dev)
{
	struct ieee80211_sub_if_data *sdata = IEEE80211_DEV_TO_SUB_IF(dev);

	return sdata->local->filter_flags;
}

void cl_rx_filter_restore_flags(struct cl_hw *cl_hw)
{
	struct net_device *dev = cl_vif_get_first_net_device(cl_hw);
	u32 filter = 0;

	if (!dev)
		return;

	filter = cl_filter_get_flags(dev);
	cl_dbg_verbose(cl_hw, "Restoring filter flags to 0x%x\n", filter);
	cl_msg_tx_set_filter(cl_hw, filter, false);
}

void cl_rx_filter_set_promiscuous_off(unsigned long data)
{
	struct cl_hw *cl_hw = (struct cl_hw *)data;

	cl_rx_filter_restore_flags(cl_hw);
}

void cl_rx_filter_set_promiscuous(struct cl_hw *cl_hw)
{
	u32 filter = ~(FIF_FCSFAIL | FIF_PLCPFAIL | (1 << 31));

	cl_dbg_verbose(cl_hw, "set promiscuous mode 0x%x\n", filter);
	cl_msg_tx_set_filter(cl_hw, filter, false);
}

int cl_rx_filter_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	u32 expected_params = 0;
	bool configuration = false;
	bool set_filter = false;

	switch (cli_params->option) {
	case 'c':
		configuration = true;
		expected_params = 0;
		break;
	case 's':
		set_filter = true;
		expected_params = 1;
		break;
	case '?':
		return cl_rx_filter_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option %c\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (configuration)
		return cl_rx_filter_cli_configuration(cl_hw);

	if (set_filter)
		return cl_msg_tx_set_filter(cl_hw, cli_params->params[0], true);

out_err:
	return -EIO;
}
