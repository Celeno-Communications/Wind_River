/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_BAND_H
#define CL_BAND_H

#include "cl_hw.h"

#define BAND_6G  6
#define BAND_5G  5
#define BAND_24G 24

#define BAND_TO_STR(band) \
		((band) == 6 ? "6G" : \
		((band) == 5 ? "5G" : "24G"))

#define BAND_IS_5G_6G(cl_hw) \
		(cl_band_is_5g(cl_hw) || cl_band_is_6g(cl_hw))

bool cl_band_is_6g(struct cl_hw *cl_hw);
bool cl_band_is_6g_freq(u16 freq);
bool cl_band_is_6g_band(u8 band);

bool cl_band_is_5g(struct cl_hw *cl_hw);
bool cl_band_is_5g_freq(u16 freq);
bool cl_band_is_5g_band(u8 band);

bool cl_band_is_24g(struct cl_hw *cl_hw);
bool cl_band_is_24g_freq(u16 freq);
bool cl_band_is_24g_band(u8 band);

u8 cl_band_to_fw_idx(struct cl_hw *cl_hw);
u8 cl_band_from_fw_idx(u32 phy_band);
u8 cl_band_num_to_fw_idx(u8 band_num);
#endif /* CL_BAND_H */
