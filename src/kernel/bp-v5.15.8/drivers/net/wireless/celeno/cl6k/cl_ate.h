/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_ATE_H
#define CL_ATE_H

#include "cl_hw.h"

int cl_ate_reset(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len);
int cl_ate_mode(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len);
int cl_ate_bw(struct wiphy *wiphy, struct wireless_dev *wdev,
	      const void *data, int data_len);
int cl_ate_mcs(struct wiphy *wiphy, struct wireless_dev *wdev,
	       const void *data, int data_len);
int cl_ate_nss(struct wiphy *wiphy, struct wireless_dev *wdev,
	       const void *data, int data_len);
int cl_ate_gi(struct wiphy *wiphy, struct wireless_dev *wdev,
	      const void *data, int data_len);
int cl_ate_ltf(struct wiphy *wiphy, struct wireless_dev *wdev,
	       const void *data, int data_len);
int cl_ate_ldpc(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len);
int cl_ate_channel(struct wiphy *wiphy, struct wireless_dev *wdev,
		   const void *data, int data_len);
int cl_ate_ant(struct wiphy *wiphy, struct wireless_dev *wdev,
	       const void *data, int data_len);
int cl_ate_multi_ant(struct wiphy *wiphy, struct wireless_dev *wdev,
		     const void *data, int data_len);
int cl_ate_packet_len(struct wiphy *wiphy, struct wireless_dev *wdev,
		      const void *data, int data_len);
int cl_ate_freq_offset(struct wiphy *wiphy, struct wireless_dev *wdev,
		       const void *data, int data_len);
int cl_ate_stat(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len);
int cl_ate_stat_reset(struct wiphy *wiphy, struct wireless_dev *wdev,
		      const void *data, int data_len);
int cl_ate_power(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len);
int cl_ate_power_offset(struct wiphy *wiphy, struct wireless_dev *wdev,
			const void *data, int data_len);
int cl_ate_tx_start(struct wiphy *wiphy, struct wireless_dev *wdev,
		    const void *data, int data_len);
int cl_ate_tx_continuous(struct wiphy *wiphy, struct wireless_dev *wdev,
			 const void *data, int data_len);
int cl_ate_tx_agg(struct wiphy *wiphy, struct wireless_dev *wdev,
		  const void *data, int data_len);
int cl_ate_stop(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len);
int cl_ate_dummy_sta(struct wiphy *wiphy, struct wireless_dev *wdev,
		     const void *data, int data_len);
int cl_ate_help(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len);

enum cl_ate_cmd {
	CL_ATE_RESET,
	CL_ATE_MODE,
	CL_ATE_BW,
	CL_ATE_MCS,
	CL_ATE_NSS,
	CL_ATE_GI,
	CL_ATE_LTF,
	CL_ATE_LDPC,
	CL_ATE_CHANNEL,
	CL_ATE_ANT,
	CL_ATE_MULTI_ANT,
	CL_ATE_PACKET_LEN,
	CL_ATE_FREQ_OFFSET,
	CL_ATE_STAT_RESET,
	CL_ATE_STAT,
	CL_ATE_POWER,
	CL_ATE_POWER_OFFSET,
	CL_ATE_TX_START,
	CL_ATE_TX_CONTINUOUS,
	CL_ATE_TX_AGG,
	CL_ATE_STOP,
	CL_ATE_DUMMY_STA,

	CL_ATE_MAX
};

#endif /* CL_ATE_H */
