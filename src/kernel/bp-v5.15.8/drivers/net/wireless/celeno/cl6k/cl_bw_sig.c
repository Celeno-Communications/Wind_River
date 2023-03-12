// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_bw_sig.h"
#include "cl_vif.h"
#include "cl_utils.h"
#include "cl_tx.h"
#include "cl_rx_filter.h"
#include "cl_msg_tx.h"

static int cl_bw_sig_send_ps_poll(struct cl_vif *cl_vif)
{
	struct cl_hw *cl_hw = cl_vif->cl_hw;
	struct ieee80211_pspoll *pspoll = NULL;
	struct ieee80211_tx_info *tx_info = NULL;
	struct cl_sta *cl_sta = NULL;
	struct sk_buff *skb = ieee80211_pspoll_get(cl_hw->hw, cl_vif->vif);

	if (!skb)
		return -ENOMEM;

	pspoll = (struct ieee80211_pspoll *)skb->data;
	pspoll->frame_control |= cpu_to_le16(IEEE80211_FCTL_PM);

	tx_info = IEEE80211_SKB_CB(skb);
	tx_info->hw_queue = CL_HWQ_VO;
	tx_info->control.vif = cl_vif->vif;

	cl_sta_lock_bh(cl_hw);
	cl_sta = cl_sta_get_by_addr(cl_hw, pspoll->bssid);
	cl_tx_single(cl_hw, cl_sta, skb, false, true);
	cl_sta_unlock_bh(cl_hw);

	return 0;
}

static int cl_bw_sig_handle_bar_test(struct cl_hw *cl_hw, int enable)
{
	int ret = 0;
	u32 test_params[TEST_MODE_PARAM_MAX + 1] = {0};
	u32 rx_filter = (enable ? (cl_hw->rx_filter | RX_CNTRL_ACCEPT_BAR_BIT) :
	    (cl_hw->rx_filter & ~RX_CNTRL_ACCEPT_BAR_BIT));

	test_params[0] = DBG_TEST_MODE_BW_SIG_PRINT;
	test_params[1] = enable ? CL_BW_SIG_DEBUG_BAR : 0;

	ret = cl_msg_tx_dbg_test_mode(cl_hw, test_params);
	if (ret) {
		cl_dbg_err(cl_hw, "cl_send_dbg_test_mode failed\n");
		return ret;
	}

	cl_hw->bw_sig_debug_mode = (enable ? CL_BW_SIG_DEBUG_BAR : 0);

	return cl_msg_tx_set_filter(cl_hw, rx_filter, true);
}

static int cl_bw_sig_handle_rts_test(struct cl_hw *cl_hw, int enable)
{
	int ret = 0;
	u32 test_params[TEST_MODE_PARAM_MAX + 1] = {0};
	u32 rx_filter = enable ?
		(cl_hw->rx_filter | (RX_CNTRL_ACCEPT_CTS_BIT | RX_CNTRL_ACCEPT_RTS_BIT)) :
		(cl_hw->rx_filter & ~(RX_CNTRL_ACCEPT_CTS_BIT | RX_CNTRL_ACCEPT_RTS_BIT));

	test_params[0] = DBG_TEST_MODE_BW_SIG_PRINT;
	test_params[1] = enable ? CL_BW_SIG_DEBUG_RTS : 0;

	ret = cl_msg_tx_dbg_test_mode(cl_hw, test_params);
	if (ret) {
		cl_dbg_err(cl_hw, "cl_send_dbg_test_mode failed\n");
		return ret;
	}

	cl_hw->bw_sig_debug_mode = (enable ? CL_BW_SIG_DEBUG_RTS : 0);
	return cl_msg_tx_set_filter(cl_hw, rx_filter, true);
}

static int cl_bw_sig_handle_ps_poll_test(struct cl_vif *cl_vif, int enable)
{
	struct cl_hw *cl_hw = cl_vif->cl_hw;
	int ret = 0;

	cl_hw->bw_sig_debug_mode = enable ? CL_BW_SIG_DEBUG_PS_POLL : 0;
	if (cl_vif->vif->type == NL80211_IFTYPE_STATION) {
		u32 rx_filter = enable ?
			(cl_hw->rx_filter | RX_CNTRL_ACCEPT_ACK_BIT) :
			(cl_hw->rx_filter & ~RX_CNTRL_ACCEPT_ACK_BIT);

		ret = cl_msg_tx_set_filter(cl_hw, rx_filter, true);
		if (ret) {
			cl_dbg_err(cl_hw, "cl_send_set_filter failed\n");
			return ret;
		}

		if (enable)
			ret = cl_bw_sig_send_ps_poll(cl_vif);
	}

	return ret;
}

static int cl_bw_sig_handle_sounding_test(struct cl_hw *cl_hw, int enable)
{
	int ret = 0;
	u32 test_params[TEST_MODE_PARAM_MAX + 1] = {0};

	test_params[0] = DBG_TEST_MODE_BW_SIG_PRINT;
	test_params[1] = enable ? CL_BW_SIG_DEBUG_SOUNDING : 0;

	ret = cl_msg_tx_dbg_test_mode(cl_hw, test_params);
	if (ret)
		cl_dbg_err(cl_hw, "cl_send_dbg_test_mode failed\n");

	return ret;
}

static int cl_bw_sig_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "bw_sig usage:\n"
		 "-a : Set BW Signaling Mode [mode]\n"
		 "-b : Enable/Disable BAR test [0/1]\n"
		 "-c : Enable/Disable RTS test [0/1]\n"
		 "-d : Enable/Disable PS-POLL test [0/1]\n"
		 "-e : Enable/Disable SOUNDING test [0/1]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

int cl_bw_sig_cli(struct cl_hw *cl_hw, struct cl_vif *cl_vif, struct cli_params *cli_params)
{
	u32 expected_params = 0;
	bool set_bw_sig_mode = false;
	bool bar_test = false;
	bool rts_test = false;
	bool ps_poll_test = false;
	bool sounding_test = false;

	switch (cli_params->option) {
	case 'a':
		set_bw_sig_mode = true;
		expected_params = 1;
		break;
	case 'b':
		bar_test = true;
		expected_params = 1;
		break;
	case 'c':
		rts_test = true;
		expected_params = 1;
		break;
	case 'd':
		ps_poll_test = true;
		expected_params = 1;
		break;
	case 'e':
		sounding_test = true;
		expected_params = 1;
		break;
	case '?':
		return cl_bw_sig_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option %c\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (set_bw_sig_mode) {
		cl_hw->conf->ce_bw_signaling_mode = (u8)cli_params->params[0];
		return cl_msg_tx_bw_signaling_mode(cl_hw, cl_hw->conf->ce_bw_signaling_mode);
	}

	if (bar_test)
		return cl_bw_sig_handle_bar_test(cl_hw, cli_params->params[0]);

	if (rts_test)
		return cl_bw_sig_handle_rts_test(cl_hw, cli_params->params[0]);

	if (ps_poll_test)
		return cl_bw_sig_handle_ps_poll_test(cl_vif, cli_params->params[0]);

	if (sounding_test)
		return cl_bw_sig_handle_sounding_test(cl_hw, cli_params->params[0]);

out_err:
	return -EIO;
}

