/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_CHAN_INFO_H
#define CL_CHAN_INFO_H

#include "cl_fw_msg.h"
#include <linux/rtnetlink.h>
#include <net/cfg80211.h>

#define CL_MAX_STR_BUFFER_SIZE 1024

#define CL_DEFAULT_CHANNEL_POWER_Q8 (30 << 8)

#define CL_20MHZ_CH_GAP  4
#define CL_40MHZ_CH_GAP  8
#define CL_80MHZ_CH_GAP  16
#define CL_160MHZ_CH_GAP 32
#define CL_40MHZ_HOP     2
#define CL_80MHZ_HOP     4
#define CL_160MHZ_HOP    8

void cl_chan_info_init(struct cl_hw *cl_hw);
void cl_chan_info_deinit(struct cl_hw *cl_hw);
struct cl_chan_info *cl_chan_info_get(struct cl_hw *cl_hw, u8 channel, u8 bw);
u8 cl_chan_info_get_max_bw(struct cl_hw *cl_hw, u8 channel);
s16 cl_chan_info_get_eirp_limit_q8(struct cl_hw *cl_hw, u8 bw);
s16 cl_chan_info_get_country_limit_q8(struct cl_hw *cl_hw, u8 channel, u8 bw);
s16 cl_chan_info_get_hardware_limit_q8(struct cl_hw *cl_hw, u8 channel, u8 bw);
u8 cl_chan_info_get_max_power(struct cl_hw *cl_hw, u8 channel);

#endif /* CL_CHAN_INFO_H */
