// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_hw.h"
#include "cl_vif.h"
#include "cl_cecli.h"
#include "cl_vendor_cmd.h"
#include "cl_wrs_api.h"
#include "chip.h"
#include "cl_tx_queue.h"
#include "cl_tx.h"
#include "cl_stats.h"
#include "cl_power_cli.h"
#include "cl_bf.h"
#include "cl_edca.h"
#include "cl_traffic.h"
#include "cl_reg_cli.h"
#include "cl_radio.h"
#include "cl_temperature.h"
#include "cl_rx_sens.h"
#include "cl_rx_filter.h"
#include "cl_bw_sig.h"
#include "cl_env_det.h"
#include "cl_math.h"
#include "cl_cma.h"
#include "cl_cecli.h"
#include "cl_utils.h"
#include "cl_fw_dbg.h"
#include "cl_vlan_dscp.h"
#include "cl_igmp.h"
#include "cl_rfic.h"
#include "cl_lcu.h"
#include "cl_nco.h"
#include "cl_vns.h"
#include "cl_vw.h"
#include "cl_version.h"
#include "cl_enhanced_tim.h"
#include "cl_rssi.h"
#include "cl_dual_nav.h"
#include "cl_bss_color.h"
#include "cl_cca.h"
#include "cl_noise.h"
#include "cl_twt_cli.h"
#include "cl_bsr.h"
#include "cl_bsrp.h"
#include "cl_omi.h"
#include "cl_tf.h"
#include "cl_ul_rssi.h"
#include "cl_config.h"
#include "chip_ops.h"
#include "cl_otp.h"
#include "cl_calib_common_api.h"

int cl_cecli_agc_params(struct wiphy *wiphy, struct wireless_dev *wdev,
			const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cli_params *cli_params = (struct cli_params *)data;

	return cl_agc_params_cli(cl_hw, cli_params);
}

int cl_cecli_bf(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len)
{
	struct cli_params *cli_params = (struct cli_params *)data;
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	return cl_bf_cli(cl_hw, cli_params);
}

int cl_cecli_bsr(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cli_params *cli_params = (struct cli_params *)data;

	if (wdev->iftype == NL80211_IFTYPE_STATION)
		return cl_bsr_cli(cl_hw, cli_params);

	return 0;
}

int cl_cecli_bsrp(struct wiphy *wiphy, struct wireless_dev *wdev,
		  const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cli_params *cli_params = (struct cli_params *)data;

	if (wdev->iftype == NL80211_IFTYPE_AP)
		return cl_bsrp_cli(cl_hw, cli_params);

	return 0;
}

int cl_cecli_bss_color(struct wiphy *wiphy, struct wireless_dev *wdev,
		       const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cl_vif *cl_vif = NETDEV_TO_CL_VIF(wdev->netdev);
	struct cli_params *cli_params = (struct cli_params *)data;

	return cl_bss_color_cli(cl_hw, cl_vif, cli_params);
}

int cl_cecli_bw_sig(struct wiphy *wiphy, struct wireless_dev *wdev,
		    const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cl_vif *cl_vif = NETDEV_TO_CL_VIF(wdev->netdev);
	struct cli_params *cli_params = (struct cli_params *)data;

	return cl_bw_sig_cli(cl_hw, cl_vif, cli_params);
}

int cl_cecli_cca(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cli_params *cli_params = (struct cli_params *)data;

	return cl_cca_cli(cl_hw, cli_params);
}

int cl_cecli_chip(struct wiphy *wiphy, struct wireless_dev *wdev,
		  const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	if (data) {
		char *str = (char *)data;

		return chip_ops_config_set(cl_hw->chip, str, strlen(str) + 1);
	}

	return -1;
}

int cl_cecli_cma(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	return cl_cma_cli(cl_hw, (char *)data);
}

int cl_cecli_config(struct wiphy *wiphy, struct wireless_dev *wdev,
		    const void *data, int data_len)
{
	struct cli_params *cli_params = (struct cli_params *)data;
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	return cl_config_cli(cl_hw, cli_params);
}

int cl_cecli_debug(struct wiphy *wiphy, struct wireless_dev *wdev,
		   const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	cl_hw->conf->ce_debug_level = *(s8 *)data;
	cl_hw->chip->conf->ce_debug_level = *(s8 *)data;

	return 0;
}

int cl_cecli_dual_nav(struct wiphy *wiphy, struct wireless_dev *wdev,
		      const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cli_params *cli_params = (struct cli_params *)data;

	return cl_dual_nav_cli(cl_hw, cli_params);
}

int cl_cecli_edca(struct wiphy *wiphy, struct wireless_dev *wdev,
		  const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cli_params *cli_params = (struct cli_params *)data;

	return cl_edca_cli(cl_hw, cli_params);
}

int cl_cecli_envdet(struct wiphy *wiphy, struct wireless_dev *wdev,
		    const void *data, int data_len)
{
	struct cli_params *cli_params = (struct cli_params *)data;
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	return cl_env_det_cli(cl_hw, cli_params);
}

int cl_cecli_fw(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len)
{
	struct cli_params *cli_params = (struct cli_params *)data;
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	return cl_fw_dbg_cli(cl_hw, cli_params);
}

int cl_cecli_igmp(struct wiphy *wiphy, struct wireless_dev *wdev,
		  const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cl_vif *cl_vif = NETDEV_TO_CL_VIF(wdev->netdev);
	struct cli_params *cli_params = (struct cli_params *)data;

	return cl_igmp_cli(cl_hw, cl_vif, cli_params);
}

int cl_cecli_lcu(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	u16 ret_buf_len = PAGE_SIZE;
	char *ret_buf = kzalloc(ret_buf_len, GFP_KERNEL);

	if (ret_buf) {
		struct cli_params *cli_params = (struct cli_params *)data;

		if (cl_lcu_cli(cl_hw, cli_params, ret_buf, &ret_buf_len) > 0)
			cl_vendor_reply(cl_hw, ret_buf, (int)ret_buf_len);

		kfree(ret_buf);
	} else {
		return -ENOMEM;
	}

	return 0;
}

int cl_cecli_nco(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cli_params *cli_params = (struct cli_params *)data;

	return cl_nco_cli(cl_hw, cli_params);
}

int cl_cecli_noise(struct wiphy *wiphy, struct wireless_dev *wdev,
		   const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cli_params *cli_params = (struct cli_params *)data;

	return cl_noise_cli(cl_hw, cli_params);
}

int cl_cecli_omi(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len)
{
	struct cli_params *cli_params = (struct cli_params *)data;
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	return cl_omi_cli(cl_hw, cli_params);
}

int cl_cecli_power(struct wiphy *wiphy, struct wireless_dev *wdev,
		   const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cli_params *cli_params = (struct cli_params *)data;

	return cl_power_cli(cl_hw, cli_params);
}

int cl_cecli_qos(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cl_vif *cl_vif = NETDEV_TO_CL_VIF(wdev->netdev);

	return data ? cl_vlan_dscp_cli(cl_hw, cl_vif, (char *)data) : -1;
}

int cl_cecli_radio(struct wiphy *wiphy, struct wireless_dev *wdev,
		   const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	bool radio_on = *(bool *)data;

	return cl_radio_cli(cl_hw, radio_on);
}

int cl_cecli_reg(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len)
{
	struct cli_params *cli_params = (struct cli_params *)data;
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	return cl_reg_cli(cl_hw, cli_params);
}

int cl_cecli_rfic(struct wiphy *wiphy, struct wireless_dev *wdev,
		  const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cli_params *cli_params = (struct cli_params *)data;

	return cl_rfic_cli(cl_hw, cli_params);
}

int cl_cecli_rssi(struct wiphy *wiphy, struct wireless_dev *wdev,
		  const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cli_params *cli_params = (struct cli_params *)data;

	cl_rssi_cli(cl_hw, cli_params);
	return 0;
}

int cl_cecli_rxsens(struct wiphy *wiphy, struct wireless_dev *wdev,
		    const void *data, int data_len)
{
	struct cli_params *cli_params = (struct cli_params *)data;
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	return cl_rx_sens_cli(cl_hw, cli_params);
}

int cl_cecli_rx_filter(struct wiphy *wiphy, struct wireless_dev *wdev,
		       const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cli_params *cli_params = (struct cli_params *)data;

	return cl_rx_filter_cli(cl_hw, cli_params);
}

int cl_cecli_sounding(struct wiphy *wiphy, struct wireless_dev *wdev,
		      const void *data, int data_len)
{
	struct cli_params *cli_params = (struct cli_params *)data;
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	return cl_sounding_cli(cl_hw, cli_params);
}

int cl_cecli_stats(struct wiphy *wiphy, struct wireless_dev *wdev,
		   const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cl_vif *cl_vif = NETDEV_TO_CL_VIF(wdev->netdev);
	struct cli_params *cli_params = (struct cli_params *)data;

	return cl_stats_cli(cl_hw, cl_vif, cli_params);
}

int cl_cecli_tcv(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	if (data) {
		char *str = (char *)data;

		return cl_tcv_config_set(cl_hw, str, strlen(str) + 1);
	}

	return -1;
}

int cl_cecli_temp(struct wiphy *wiphy, struct wireless_dev *wdev,
		  const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cli_params *cli_params = (struct cli_params *)data;

	cl_temperature_cli(cl_hw, cli_params);
	return 0;
}

int cl_cecli_tf(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cli_params *cli_params = (struct cli_params *)data;

	if (wdev->iftype == NL80211_IFTYPE_AP ||
	    cl_hw->chip->conf->ce_production_mode)
		return cl_tf_cli(cl_hw, cli_params);

	return 0;
}

int cl_cecli_tim(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len)
{
	struct cli_params *cli_params = (struct cli_params *)data;
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	return cl_enhanced_tim_cli(cl_hw, cli_params);
}

int cl_cecli_traffic(struct wiphy *wiphy, struct wireless_dev *wdev,
		     const void *data, int data_len)
{
	struct cli_params *cli_params = (struct cli_params *)data;
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	return cl_traffic_cli(cl_hw, cli_params);
}

int cl_cecli_twt(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len)
{
	struct cli_params *cli_params = (struct cli_params *)data;
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	return cl_twt_cli(cl_hw, cli_params);
}

int cl_cecli_tx(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len)
{
	struct cli_params *cli_params = (struct cli_params *)data;
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	return cl_tx_cli(cl_hw, cli_params);
}

int cl_cecli_txq(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len)
{
	struct cli_params *cli_params = (struct cli_params *)data;
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	return cl_txq_cli(cl_hw, cli_params);
}

int cl_cecli_ul_rssi(struct wiphy *wiphy, struct wireless_dev *wdev,
		     const void *data, int data_len)
{
	struct cli_params *cli_params = (struct cli_params *)data;
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	return cl_ul_rssi_cli(cl_hw, cli_params);
}

int cl_cecli_version(struct wiphy *wiphy, struct wireless_dev *wdev,
		     const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	cl_version_cli(cl_hw);
	return 0;
}

int cl_cecli_vns(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len)
{
	struct cli_params *cli_params = (struct cli_params *)data;
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	return cl_vns_cli(cl_hw, cli_params);
}

int cl_cecli_vw(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len)
{
	struct cli_params *cli_params = (struct cli_params *)data;
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	return cl_vw_cli(cl_hw, cli_params);
}

int cl_cecli_wrs(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len)
{
	struct cli_params *cli_params = (struct cli_params *)data;
	struct cl_vif *cl_vif = NETDEV_TO_CL_VIF(wdev->netdev);
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	return cl_wrs_api_cli(cl_hw, cl_vif, cli_params);
}

int cl_cecli_otp(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len)
{
	struct cli_params *cli_params = (struct cli_params *)data;
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	return cl_otp_cli(cl_hw, cli_params);
}

int cl_cecli_calib(struct wiphy *wiphy, struct wireless_dev *wdev,
		   const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct cli_params *cli_params = (struct cli_params *)data;

	return cl_calib_common_cli(cl_hw, cli_params);
}

int cl_cecli_help(struct wiphy *wiphy, struct wireless_dev *wdev,
		  const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	char *ret_buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!ret_buf)
		return -ENOMEM;

	snprintf(ret_buf, PAGE_SIZE,
		 "usage:\n"
		 "agc_params -    AGC params\n"
		 "air_port -      Air Port feature\n"
		 "atm -           Air Time Management\n"
		 "bf -            Beem Forming\n"
		 "bsr -           Buffer Status Report\n"
		 "bsrp -          Buffer Status Report Poll\n"
		 "bss_color -     BSS Color feature\n"
		 "bw_sig -        BW Signaling\n"
		 "cca -           CCA related\n"
		 "chip -          Set nvram per chip\n"
		 "cls -           ATM Classifier\n"
		 "cma -           Clone Mac Address\n"
		 "config -        Debug configuration\n"
		 "debug -         Set Debug level\n"
		 "dual_nav -      Dual NAV debug\n"
		 "edca -          Enhanced Distributed Channel Access\n"
		 "envdet -        Environment Detector\n"
		 "fw -            Firmware related\n"
		 "igmp -          Internet Group Management Protocol\n"
		 "lcu -           LCU related\n"
		 "nco -           NCO related\n"
		 "noise -         Noise related\n"
		 "omi -           OM infrastructure\n"
		 "power -         Power related\n"
		 "qos -           Quality Of Service\n"
		 "radio -         Set radio on/off\n"
		 "reg -           Register related\n"
		 "rfic            RF related\n"
		 "rssi -          RSSI related\n"
		 "rx_filter -     Rx Filter\n"
		 "rxsens -        Rx sensitivity\n"
		 "sounding -      Sounding related\n"
		 "stats -         Statistics related\n"
		 "tcv -           Set nvram per tcv\n"
		 "temp -          Temperature related\n"
		 "tf -            Trigger Frame\n"
		 "tim -           Rx enhanced tim bit\n"
		 "traffic -       Traffic related\n"
		 "twt -           Target Wake Time\n"
		 "tx -            TX related\n"
		 "txq -           TX queue\n"
		 "ul_rssi -       UL RSSI\n"
		 "urs -           Uplink Rate Selection\n"
		 "version -       Read Version\n"
		 "vns -           Very Near Station\n"
		 "vw -            VeriWave\n"
		 "wrs -           Weighted Rate Selection\n");

	err = cl_vendor_reply(cl_hw, ret_buf, strlen(ret_buf));
	kfree(ret_buf);

	return err;
}
