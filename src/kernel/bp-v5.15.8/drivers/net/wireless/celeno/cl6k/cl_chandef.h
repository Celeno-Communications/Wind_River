/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_CHANDEF_H
#define CL_CHANDEF_H

#include "cl_hw.h"

int cl_chandef_calc(struct cl_hw *cl_hw, u32 channel, u32 bw,
		    enum nl80211_chan_width *width, u32 *primary, u32 *center);
int cl_chandef_calc_calib(struct cl_hw *cl_hw, u32 channel, u32 bw,
			  enum nl80211_chan_width *width, u32 *primary, u32 *center,
			  u8 band);
int cl_chandef_get_default(struct cl_hw *cl_hw, enum nl80211_chan_width *width,
			   u32 *primary, u32 *center);

#endif /* CL_CHANDEF_H */
