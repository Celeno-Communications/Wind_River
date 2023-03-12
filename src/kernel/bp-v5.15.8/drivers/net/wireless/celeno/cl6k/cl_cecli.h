/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_CECLI_H
#define CL_CECLI_H

#include <net/cfg80211.h>
#include <net/mac80211.h>
#include <linux/version.h>

int cl_cecli_agc_params(struct wiphy *wiphy, struct wireless_dev *wdev,
			const void *data, int data_len);
int cl_cecli_bf(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len);
int cl_cecli_bsr(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len);
int cl_cecli_bsrp(struct wiphy *wiphy, struct wireless_dev *wdev,
		  const void *data, int data_len);
int cl_cecli_bss_color(struct wiphy *wiphy, struct wireless_dev *wdev,
		       const void *data, int data_len);
int cl_cecli_bw_sig(struct wiphy *wiphy, struct wireless_dev *wdev,
		    const void *data, int data_len);
int cl_cecli_cca(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len);
int cl_cecli_chip(struct wiphy *wiphy, struct wireless_dev *wdev,
		  const void *data, int data_len);
int cl_cecli_cma(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len);
int cl_cecli_config(struct wiphy *wiphy, struct wireless_dev *wdev,
		    const void *data, int data_len);
int cl_cecli_debug(struct wiphy *wiphy, struct wireless_dev *wdev,
		   const void *data, int data_len);
int cl_cecli_dual_nav(struct wiphy *wiphy, struct wireless_dev *wdev,
		      const void *data, int data_len);
int cl_cecli_edca(struct wiphy *wiphy, struct wireless_dev *wdev,
		  const void *data, int data_len);
int cl_cecli_envdet(struct wiphy *wiphy, struct wireless_dev *wdev,
		    const void *data, int data_len);
int cl_cecli_fw(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len);
int cl_cecli_igmp(struct wiphy *wiphy, struct wireless_dev *wdev,
		  const void *data, int data_len);
int cl_cecli_lcu(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len);
int cl_cecli_nco(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len);
int cl_cecli_noise(struct wiphy *wiphy, struct wireless_dev *wdev,
		   const void *data, int data_len);
int cl_cecli_omi(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len);
int cl_cecli_power(struct wiphy *wiphy, struct wireless_dev *wdev,
		   const void *data, int data_len);
int cl_cecli_qos(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len);
int cl_cecli_radio(struct wiphy *wiphy, struct wireless_dev *wdev,
		   const void *data, int data_len);
int cl_cecli_reg(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len);
int cl_cecli_rssi(struct wiphy *wiphy, struct wireless_dev *wdev,
		  const void *data, int data_len);
int cl_cecli_rxsens(struct wiphy *wiphy, struct wireless_dev *wdev,
		    const void *data, int data_len);
int cl_cecli_rx_filter(struct wiphy *wiphy, struct wireless_dev *wdev,
		       const void *data, int data_len);
int cl_cecli_sounding(struct wiphy *wiphy, struct wireless_dev *wdev,
		      const void *data, int data_len);
int cl_cecli_stats(struct wiphy *wiphy, struct wireless_dev *wdev,
		   const void *data, int data_len);
int cl_cecli_tcv(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len);
int cl_cecli_temp(struct wiphy *wiphy, struct wireless_dev *wdev,
		  const void *data, int data_len);
int cl_cecli_tf(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len);
int cl_cecli_tim(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len);
int cl_cecli_traffic(struct wiphy *wiphy, struct wireless_dev *wdev,
		     const void *data, int data_len);
int cl_cecli_twt(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len);
int cl_cecli_tx(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len);
int cl_cecli_txq(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len);
int cl_cecli_ul_rssi(struct wiphy *wiphy, struct wireless_dev *wdev,
		     const void *data, int data_len);
int cl_cecli_version(struct wiphy *wiphy, struct wireless_dev *wdev,
		     const void *data, int data_len);
int cl_cecli_vns(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len);
int cl_cecli_vw(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len);
int cl_cecli_wrs(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len);
int cl_cecli_otp(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len);
int cl_cecli_help(struct wiphy *wiphy, struct wireless_dev *wdev,
		  const void *data, int data_len);
int cl_cecli_rfic(struct wiphy *wiphy, struct wireless_dev *wdev,
		  const void *data, int data_len);
int cl_cecli_calib(struct wiphy *wiphy, struct wireless_dev *wdev,
		   const void *data, int data_len);

enum cl_cecli_cmd {
	CL_CECLI_AGC_PARAMS,
	CL_CECLI_BF,
	CL_CECLI_BSR,
	CL_CECLI_BSRP,
	CL_CECLI_BSS_COLOR,
	CL_CECLI_BW_SIG,
	CL_CECLI_CCA,
	CL_CECLI_CHIP,
	CL_CECLI_CMA,
	CL_CECLI_CONFIG,
	CL_CECLI_DEBUG,
	CL_CECLI_DUAL_NAV,
	CL_CECLI_EDCA,
	CL_CECLI_ENVDET,
	CL_CECLI_FW,
	CL_CECLI_IGMP,
	CL_CECLI_LCU,
	CL_CECLI_MORE_DATA,
	CL_CECLI_NCO,
	CL_CECLI_NOISE,
	CL_CECLI_OMI,
	CL_CECLI_POWER,
	CL_CECLI_QOS,
	CL_CECLI_RADIO,
	CL_CECLI_REG,
	CL_CECLI_RFIC,
	CL_CECLI_RSSI,
	CL_CECLI_RXSENS,
	CL_CECLI_RX_FILTER,
	CL_CECLI_SOUNDING,
	CL_CECLI_STATS,
	CL_CECLI_TCV,
	CL_CECLI_TEMP,
	CL_CECLI_TF,
	CL_CECLI_TIM,
	CL_CECLI_TRAFFIC,
	CL_CECLI_TWT,
	CL_CECLI_TX,
	CL_CECLI_TXQ,
	CL_CECLI_UL_RSSI,
	CL_CECLI_VERSION,
	CL_CECLI_VNS,
	CL_CECLI_VW,
	CL_CECLI_WRS,
	CL_CECLI_OTP,
	CL_CECLI_CALIB,

	CL_CECLI_MAX
};

#endif /* CL_CECLI_H */
