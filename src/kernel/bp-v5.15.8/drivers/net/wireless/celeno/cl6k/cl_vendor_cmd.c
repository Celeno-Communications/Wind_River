// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <net/cfg80211.h>
#include <net/mac80211.h>
#include <linux/version.h>
#include "cl_vendor_cmd.h"
#include "cl_calibration.h"
#include "cl_e2p.h"
#include "cl_otp.h"
#include "cl_ate.h"
#include "cl_cecli.h"
#include "cl_utils.h"

static int vendor_reply(struct wiphy *wiphy, void *data, u16 len)
{
	/* Utility function to send reply message */
	struct sk_buff *msg = cfg80211_vendor_cmd_alloc_reply_skb(wiphy, len);
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cl_msg_data *msg_data = (struct cl_msg_data *)data;

	if (!msg)
		return -ENOMEM;

	if (data) {
		if (nla_put(msg, CL_VENDOR_ATTR_REPLY, len, (void *)msg_data) < 0) {
			kfree_skb(msg);
			return -ENOBUFS;
		}
	}

	/* Start timer if we waiting for more msg's from userspace */
	if (msg_data->more_data)
		cl_timer_enable(&cl_hw->vendor_timer);

	return cfg80211_vendor_cmd_reply(msg);
}

static int _cl_vendor_reply(struct cl_hw *cl_hw, void *data, u16 len, bool process_data)
{
	struct cl_vendor_msg *vendor_msg = &cl_hw->vendor_msg;
	struct cl_msg_data *msg_data = NULL;
	int ret = 0;
	u16 curr_size;

	if (!data || len == 0)
		return -EIO;

	msg_data = kzalloc(sizeof(*msg_data), GFP_KERNEL);
	if (!msg_data)
		return -ENOMEM;

	/* Messages 2..N */
	if (process_data) {
		curr_size = vendor_msg->len - vendor_msg->offset;
		if (curr_size <= MSG_SIZE) {
			vendor_msg->in_process = false;
		} else {
			curr_size = MSG_SIZE;
			msg_data->more_data = 1;
		}

		memcpy(msg_data->data, vendor_msg->buf + vendor_msg->offset, curr_size);
		vendor_msg->offset += curr_size;
		ret = vendor_reply(cl_hw->hw->wiphy, (void *)msg_data, sizeof(*msg_data));

		/* Last msg */
		if (!vendor_msg->in_process)
			memset(vendor_msg, 0, sizeof(*vendor_msg));

		goto out;
	}

	/* Single message */
	if (len < MSG_SIZE) {
		memcpy(msg_data->data, data, len);
		ret = vendor_reply(cl_hw->hw->wiphy, (void *)msg_data, sizeof(*msg_data));
		goto out;
	} else if (vendor_msg->in_process) {
		goto out;
	}

	/* First message */
	msg_data->more_data = 1;

	/* Allocate buffer in driver */
	vendor_msg->buf = data;

	vendor_msg->in_process = true;
	vendor_msg->len = len;

	memcpy(msg_data->data, data, MSG_SIZE);
	vendor_msg->offset += MSG_SIZE;
	ret = vendor_reply(cl_hw->hw->wiphy, (void *)msg_data, sizeof(*msg_data));

out:
	kfree(msg_data);
	return ret;
}

static int cl_vendor_cecli_handler(struct wiphy *wiphy,
				   struct wireless_dev *wdev,
				   const void *data, int len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	u8 cecli_cmd_id = *(u8 *)data;
	void *real_data = (u8 *)(data + 1);

	len--;

	cl_timer_disable_sync(&cl_hw->vendor_timer);
	if (cl_hw->vendor_msg.in_process &&
	    cecli_cmd_id == CL_CECLI_MORE_DATA)
		return _cl_vendor_reply(cl_hw, real_data, len, true);

	switch (cecli_cmd_id) {
	case CL_CECLI_AGC_PARAMS:
		return cl_cecli_agc_params(wiphy, wdev, real_data, len);
	case CL_CECLI_BF:
		return cl_cecli_bf(wiphy, wdev, real_data, len);
	case CL_CECLI_BSR:
		return cl_cecli_bsr(wiphy, wdev, real_data, len);
	case CL_CECLI_BSRP:
		return cl_cecli_bsrp(wiphy, wdev, real_data, len);
	case CL_CECLI_BSS_COLOR:
		return cl_cecli_bss_color(wiphy, wdev, real_data, len);
	case CL_CECLI_BW_SIG:
		return cl_cecli_bw_sig(wiphy, wdev, real_data, len);
	case CL_CECLI_CCA:
		return cl_cecli_cca(wiphy, wdev, real_data, len);
	case CL_CECLI_CHIP:
		return cl_cecli_chip(wiphy, wdev, real_data, len);
	case CL_CECLI_CMA:
		return cl_cecli_cma(wiphy, wdev, real_data, len);
	case CL_CECLI_CONFIG:
		return cl_cecli_config(wiphy, wdev, real_data, len);
	case CL_CECLI_DEBUG:
		return cl_cecli_debug(wiphy, wdev, real_data, len);
	case CL_CECLI_DUAL_NAV:
		return cl_cecli_dual_nav(wiphy, wdev, real_data, len);
	case CL_CECLI_EDCA:
		return cl_cecli_edca(wiphy, wdev, real_data, len);
	case CL_CECLI_ENVDET:
		return cl_cecli_envdet(wiphy, wdev, real_data, len);
	case CL_CECLI_FW:
		return cl_cecli_fw(wiphy, wdev, real_data, len);
	case CL_CECLI_IGMP:
		return cl_cecli_igmp(wiphy, wdev, real_data, len);
	case CL_CECLI_LCU:
		return cl_cecli_lcu(wiphy, wdev, real_data, len);
	case CL_CECLI_NCO:
		return cl_cecli_nco(wiphy, wdev, real_data, len);
	case CL_CECLI_NOISE:
		return cl_cecli_noise(wiphy, wdev, real_data, len);
	case CL_CECLI_OMI:
		return cl_cecli_omi(wiphy, wdev, real_data, len);
	case CL_CECLI_POWER:
		return cl_cecli_power(wiphy, wdev, real_data, len);
	case CL_CECLI_QOS:
		return cl_cecli_qos(wiphy, wdev, real_data, len);
	case CL_CECLI_RADIO:
		return cl_cecli_radio(wiphy, wdev, real_data, len);
	case CL_CECLI_REG:
		return cl_cecli_reg(wiphy, wdev, real_data, len);
	case CL_CECLI_RFIC:
		return cl_cecli_rfic(wiphy, wdev, real_data, len);
	case CL_CECLI_RSSI:
		return cl_cecli_rssi(wiphy, wdev, real_data, len);
	case CL_CECLI_RXSENS:
		return cl_cecli_rxsens(wiphy, wdev, real_data, len);
	case CL_CECLI_RX_FILTER:
		return cl_cecli_rx_filter(wiphy, wdev, real_data, len);
	case CL_CECLI_SOUNDING:
		return cl_cecli_sounding(wiphy, wdev, real_data, len);
	case CL_CECLI_STATS:
		return cl_cecli_stats(wiphy, wdev, real_data, len);
	case CL_CECLI_TCV:
		return cl_cecli_tcv(wiphy, wdev, real_data, len);
	case CL_CECLI_TEMP:
		return cl_cecli_temp(wiphy, wdev, real_data, len);
	case CL_CECLI_TF:
		return cl_cecli_tf(wiphy, wdev, real_data, len);
	case CL_CECLI_TIM:
		return cl_cecli_tim(wiphy, wdev, real_data, len);
	case CL_CECLI_TRAFFIC:
		return cl_cecli_traffic(wiphy, wdev, real_data, len);
	case CL_CECLI_TWT:
		return cl_cecli_twt(wiphy, wdev, real_data, len);
	case CL_CECLI_TX:
		return cl_cecli_tx(wiphy, wdev, real_data, len);
	case CL_CECLI_TXQ:
		return cl_cecli_txq(wiphy, wdev, real_data, len);
	case CL_CECLI_UL_RSSI:
		return cl_cecli_ul_rssi(wiphy, wdev, real_data, len);
	case CL_CECLI_VERSION:
		return cl_cecli_version(wiphy, wdev, real_data, len);
	case CL_CECLI_VNS:
		return cl_cecli_vns(wiphy, wdev, real_data, len);
	case CL_CECLI_VW:
		return cl_cecli_vw(wiphy, wdev, real_data, len);
	case CL_CECLI_WRS:
		return cl_cecli_wrs(wiphy, wdev, real_data, len);
	case CL_CECLI_OTP:
		return cl_cecli_otp(wiphy, wdev, real_data, len);
	case CL_CECLI_CALIB:
		return cl_cecli_calib(wiphy, wdev, real_data, len);
	default:
		return cl_cecli_help(wiphy, wdev, real_data, len);
	}

	return 0;
}

static int cl_vendor_e2p_handler(struct wiphy *wiphy,
				 struct wireless_dev *wdev,
				 const void *data, int len)
{
	u8 e2p_cmd_id = *(u8 *)data;
	void *real_data = (u8 *)(data + 1);

	len--;

	switch (e2p_cmd_id) {
	case CL_E2P_GET_ADDR:
	case CL_E2P_GET_POWER_LEVEL:
	case CL_E2P_GET_FREQ_OFFSET:
	case CL_E2P_GET_MODULE_HW_TYPE:
	case CL_E2P_GET_MODULE_HW_REVID:
	case CL_E2P_GET_RFIC_WIFI_VERSION_FOR_CALIB:
	case CL_E2P_GET_RFIC_BT_VERSION_FOR_CALIB:
	case CL_E2P_GET_RFIC_LUT_VERSION_FOR_CALIB:
	case CL_E2P_GET_TABLE:
		return cl_e2p_get_addr(wiphy, wdev, real_data, len);
	case CL_E2P_GET_CALIB:
		return cl_calibration_get_calib(wiphy, wdev, real_data, len, false);
	case CL_E2P_SET_ADDR:
	case CL_E2P_SET_POWER_LEVEL:
	case CL_E2P_SET_FREQ_OFFSET:
	case CL_E2P_SET_MODULE_HW_REVID:
	case CL_E2P_SET_RFIC_WIFI_VERSION_FOR_CALIB:
	case CL_E2P_SET_RFIC_BT_VERSION_FOR_CALIB:
	case CL_E2P_SET_RFIC_LUT_VERSION_FOR_CALIB:
		return cl_e2p_set_addr(wiphy, wdev, real_data, len);
	case CL_E2P_SET_MODULE_HW_TYPE:
		return cl_e2p_set_module_hw_type(wiphy, wdev, real_data, len);
	case CL_E2P_SET_CALIB:
		return cl_calibration_set_calib(wiphy, wdev, real_data, len, false);
	default:
		return cl_e2p_help(wiphy, wdev, real_data, len);
	}

	return 0;
}

static int cl_vendor_otp_handler(struct wiphy *wiphy,
				 struct wireless_dev *wdev,
				 const void *data, int len)
{
	u8 otp_cmd_id = *(u8 *)data;
	void *real_data = (u8 *)(data + 1);

	len--;

	switch (otp_cmd_id) {
	case CL_OTP_GET_MAC:
	case CL_OTP_GET_POWER_LEVEL:
	case CL_OTP_GET_FREQ_OFFSET:
	case CL_OTP_GET_MODULE_HW_TYPE:
	case CL_OTP_GET_MODULE_HW_REVID:
	case CL_OTP_GET_RFIC_WIFI_VERSION_FOR_CALIB:
	case CL_OTP_GET_RFIC_BT_VERSION_FOR_CALIB:
	case CL_OTP_GET_RFIC_LUT_VERSION_FOR_CALIB:
		return cl_otp_get_addr(wiphy, wdev, real_data, len);
	case CL_OTP_GET_CALIB:
		return cl_calibration_get_calib(wiphy, wdev, real_data, len, true);
	case CL_OTP_SET_ADDR:
	case CL_OTP_SET_MAC:
	case CL_OTP_SET_POWER_LEVEL:
	case CL_OTP_SET_FREQ_OFFSET:
	case CL_OTP_SET_MODULE_HW_REVID:
	case CL_OTP_SET_RFIC_WIFI_VERSION_FOR_CALIB:
	case CL_OTP_SET_RFIC_BT_VERSION_FOR_CALIB:
	case CL_OTP_SET_RFIC_LUT_VERSION_FOR_CALIB:
		return cl_otp_set_addr(wiphy, wdev, real_data, len);
	case CL_OTP_SET_MODULE_HW_TYPE:
		return cl_otp_set_module_hw_type(wiphy, wdev, real_data, len);
	case CL_OTP_SET_CALIB:
		return cl_calibration_set_calib(wiphy, wdev, real_data, len, true);
	default:
		return cl_otp_help(wiphy, wdev, real_data, len);
	}

	return 0;
}

static int cl_vendor_ate_handler(struct wiphy *wiphy,
				 struct wireless_dev *wdev,
				 const void *data, int len)
{
	u8 ate_cmd_id = *(u8 *)data;
	void *real_data = (u8 *)(data + 1);

	len--;

	switch (ate_cmd_id) {
	case CL_ATE_RESET:
		return cl_ate_reset(wiphy, wdev, real_data, len);
	case CL_ATE_MODE:
		return cl_ate_mode(wiphy, wdev, real_data, len);
	case CL_ATE_BW:
		return cl_ate_bw(wiphy, wdev, real_data, len);
	case CL_ATE_MCS:
		return cl_ate_mcs(wiphy, wdev, real_data, len);
	case CL_ATE_NSS:
		return cl_ate_nss(wiphy, wdev, real_data, len);
	case CL_ATE_GI:
		return cl_ate_gi(wiphy, wdev, real_data, len);
	case CL_ATE_LTF:
		return cl_ate_ltf(wiphy, wdev, real_data, len);
	case CL_ATE_LDPC:
		return cl_ate_ldpc(wiphy, wdev, real_data, len);
	case CL_ATE_CHANNEL:
		return cl_ate_channel(wiphy, wdev, real_data, len);
	case CL_ATE_ANT:
		return cl_ate_ant(wiphy, wdev, real_data, len);
	case CL_ATE_MULTI_ANT:
		return cl_ate_multi_ant(wiphy, wdev, real_data, len);
	case CL_ATE_PACKET_LEN:
		return cl_ate_packet_len(wiphy, wdev, real_data, len);
	case CL_ATE_FREQ_OFFSET:
		return cl_ate_freq_offset(wiphy, wdev, real_data, len);
	case CL_ATE_STAT_RESET:
		return cl_ate_stat_reset(wiphy, wdev, real_data, len);
	case CL_ATE_STAT:
		return cl_ate_stat(wiphy, wdev, real_data, len);
	case CL_ATE_POWER:
		return cl_ate_power(wiphy, wdev, real_data, len);
	case CL_ATE_POWER_OFFSET:
		return cl_ate_power_offset(wiphy, wdev, real_data, len);
	case CL_ATE_TX_START:
		return cl_ate_tx_start(wiphy, wdev, real_data, len);
	case CL_ATE_TX_CONTINUOUS:
		return cl_ate_tx_continuous(wiphy, wdev, real_data, len);
	case CL_ATE_TX_AGG:
		return cl_ate_tx_agg(wiphy, wdev, real_data, len);
	case CL_ATE_STOP:
		return cl_ate_stop(wiphy, wdev, real_data, len);
	case CL_ATE_DUMMY_STA:
		return cl_ate_dummy_sta(wiphy, wdev, real_data, len);
	default:
		return cl_ate_help(wiphy, wdev, real_data, len);
	}

	return 0;
}

static int cl_vendor_help_handler(struct wiphy *wiphy,
				  struct wireless_dev *wdev,
				  const void *data, int len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	char ret_buf[] = {
		"usage:\n"
		"cecli - Celeno driver related\n"
		"e2p   - Celeno eeprom related\n"
		"otp   - Celeno otp related\n"
		"ATE   - Celeno production related\n"
	};

	return cl_vendor_reply(cl_hw, ret_buf, strlen(ret_buf));
}

static void cl_vendor_handle_timeout(unsigned long data)
{
	struct cl_hw *cl_hw = (struct cl_hw *)data;
	struct cl_vendor_msg *vendor_msg = &cl_hw->vendor_msg;

	memset(vendor_msg, 0, sizeof(*vendor_msg));
	pr_warn("cl_vendor timer expired!\n");
}

int cl_vendor_reply(struct cl_hw *cl_hw, void *data, u16 len)
{
	return _cl_vendor_reply(cl_hw, data, len, false);
}

void cl_vendor_timer_init(struct cl_hw *cl_hw)
{
	/* Init vendor_cmd timer */
	cl_timer_init(&cl_hw->vendor_timer, cl_vendor_handle_timeout,
		      (unsigned long)cl_hw, VENDOR_CMD_TIMER_PERIOD_MS, false);
}

void cl_vendor_timer_close(struct cl_hw *cl_hw)
{
	cl_timer_disable_sync(&cl_hw->vendor_timer);
}

/* Vendor specific commands */
static const struct wiphy_vendor_command cl_vendor_cmds[] = {
	{
		.info.vendor_id = CELENO_OUI,
		.info.subcmd = CL_VNDR_CMDS_CECLI,
		.flags = WIPHY_VENDOR_CMD_NEED_WDEV |
			WIPHY_VENDOR_CMD_NEED_RUNNING |
			WIPHY_VENDOR_CMD_NEED_NETDEV,
		.policy = VENDOR_CMD_RAW_DATA,
		.doit = cl_vendor_cecli_handler
	},
	{
		.info.vendor_id = CELENO_OUI,
		.info.subcmd = CL_VNDR_CMDS_E2P,
		.flags = WIPHY_VENDOR_CMD_NEED_WDEV |
			WIPHY_VENDOR_CMD_NEED_RUNNING |
			WIPHY_VENDOR_CMD_NEED_NETDEV,
		.policy = VENDOR_CMD_RAW_DATA,
		.doit = cl_vendor_e2p_handler
	},
	{
		.info.vendor_id = CELENO_OUI,
		.info.subcmd = CL_VNDR_CMDS_OTP,
		.flags = WIPHY_VENDOR_CMD_NEED_WDEV |
			WIPHY_VENDOR_CMD_NEED_RUNNING |
			WIPHY_VENDOR_CMD_NEED_NETDEV,
		.policy = VENDOR_CMD_RAW_DATA,
		.doit = cl_vendor_otp_handler
	},
	{
		.info.vendor_id = CELENO_OUI,
		.info.subcmd = CL_VNDR_CMDS_ATE,
		.flags = WIPHY_VENDOR_CMD_NEED_WDEV |
			WIPHY_VENDOR_CMD_NEED_RUNNING |
			WIPHY_VENDOR_CMD_NEED_NETDEV,
		.policy = VENDOR_CMD_RAW_DATA,
		.doit = cl_vendor_ate_handler
	},
	{
		.info.vendor_id = CELENO_OUI,
		.info.subcmd = CL_VNDR_CMDS_HELP,
		.flags = WIPHY_VENDOR_CMD_NEED_WDEV |
			WIPHY_VENDOR_CMD_NEED_RUNNING |
			WIPHY_VENDOR_CMD_NEED_NETDEV,
		.policy = VENDOR_CMD_RAW_DATA,
		.doit = cl_vendor_help_handler
	},
};

/* Vendor specific events */
static const struct nl80211_vendor_cmd_info cl_vendor_events[] = {
	{
		.vendor_id = CELENO_OUI,
		.subcmd = CL_VENDOR_EVENT_ASYNC,
	}
};

void cl_vendor_cmds_init(struct wiphy *wiphy)
{
	/* Set celeno vendor commands used by nl80211 */
	wiphy->vendor_commands = cl_vendor_cmds;
	wiphy->n_vendor_commands = ARRAY_SIZE(cl_vendor_cmds);
	wiphy->vendor_events = cl_vendor_events;
	wiphy->n_vendor_events = ARRAY_SIZE(cl_vendor_events);
}

