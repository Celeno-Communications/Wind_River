// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_band.h"

bool cl_band_is_6g(struct cl_hw *cl_hw)
{
	return (cl_hw && cl_hw->conf->ci_band_num == 6);
}

bool cl_band_is_6g_freq(u16 freq)
{
	return (freq > 5935) ? true : false;
}

bool cl_band_is_6g_band(u8 band)
{
	return (band == BAND_6G);
}

bool cl_band_is_5g(struct cl_hw *cl_hw)
{
	return (cl_hw->conf->ci_band_num == 5);
}

bool cl_band_is_5g_freq(u16 freq)
{
	return (freq > 5000 && freq <= 5835) ? true : false;
}

bool cl_band_is_5g_band(u8 band)
{
	return (band == BAND_5G);
}

bool cl_band_is_24g(struct cl_hw *cl_hw)
{
	return (cl_hw->conf->ci_band_num == 24);
}

bool cl_band_is_24g_freq(u16 freq)
{
	return (freq < 5000) ? true : false;
}

bool cl_band_is_24g_band(u8 band)
{
	return (band == BAND_24G);
}

u8 cl_band_to_fw_idx(struct cl_hw *cl_hw)
{
	if (cl_hw->nl_band == NL80211_BAND_6GHZ)
		return FW_BAND_6GHZ;

	if (cl_hw->nl_band == NL80211_BAND_5GHZ)
		return FW_BAND_5GHZ;

	return FW_BAND_2GHZ;
}

u8 cl_band_num_to_fw_idx(u8 band_num)
{
	if (band_num == BAND_6G)
		return FW_BAND_6GHZ;

	if (band_num == BAND_5G)
		return FW_BAND_5GHZ;

	return FW_BAND_2GHZ;
}
static u8 fw_to_nl_band[FW_BAND_MAX] = {
	[FW_BAND_6GHZ] = NL80211_BAND_6GHZ,
	[FW_BAND_5GHZ] = NL80211_BAND_5GHZ,
	[FW_BAND_2GHZ] = NL80211_BAND_2GHZ,
};

u8 cl_band_from_fw_idx(u32 phy_band)
{
	if (phy_band < FW_BAND_MAX)
		return fw_to_nl_band[phy_band];

	return FW_BAND_MAX;
}

