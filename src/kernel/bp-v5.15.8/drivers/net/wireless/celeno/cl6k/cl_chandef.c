// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_chandef.h"
#include "cl_band.h"

#define CENTER_FREQ_24G_BW_80MHZ  2442
#define CENTER_FREQ_24G_BW_160MHZ 2482

static int cl_chandef_calc_6g(struct cl_hw *cl_hw, u16 freq, u32 bw, u32 offset,
			      u32 *primary, u32 *center)
{
	u32 bw_mhz = BW_TO_MHZ(bw);
	u32 min_freq = 0;

	if (freq == FREQ6G(2)) {
		min_freq = FREQ6G(2);
	} else if (freq >= FREQ6G(1) && freq <= FREQ6G(233)) {
		min_freq = FREQ6G(1);
	} else {
		cl_dbg_err(cl_hw, "Invalid frequecy - %u\n", freq);
		return -EINVAL;
	}

	*primary = freq - (freq - min_freq) % 20;
	*center = *primary - (*primary - min_freq) % bw_mhz + offset;

	return 0;
}

static int cl_chandef_calc_5g(struct cl_hw *cl_hw, u16 freq, u32 bw, u32 offset,
			      u32 *primary, u32 *center)
{
	u32 bw_mhz = BW_TO_MHZ(bw);
	u32 min_freq = 0;

	if ((freq >= FREQ5G(36) && freq <= FREQ5G(64)) ||
	    (freq >= FREQ5G(100) && freq <= FREQ5G(144))) {
		min_freq = FREQ5G(36);
	} else if (freq >= FREQ5G(149) && freq <= FREQ5G(165)) {
		min_freq = FREQ5G(149);
	} else {
		cl_dbg_err(cl_hw, "Invalid frequecy - %u\n", freq);
		return -EINVAL;
	}

	*primary = freq - (freq - min_freq) % 20;
	*center = *primary - (*primary - min_freq) % bw_mhz + offset;

	return 0;
}

static int cl_chandef_calc_24g(struct cl_hw *cl_hw, u16 freq, u32 bw, u32 offset,
			       u32 *primary, u32 *center)
{
	u32 min_freq = 0;

	if (freq < FREQ2G(1) || freq > FREQ2G(14)) {
		cl_dbg_err(cl_hw, "Invalid frequecy - %u\n", freq);
		return -EINVAL;
	}

	min_freq = freq < FREQ2G(14) ? FREQ2G(1) : FREQ2G(14);
	*primary = freq - (freq - min_freq) % 5;

	if (bw == CHNL_BW_20) {
		*center = *primary;
	} else if (bw == CHNL_BW_40) {
		if (freq <= FREQ2G(4)) {
			/* Above extension channel */
			*center = *primary + offset;
		} else if (freq >= FREQ2G(10)) {
			/* Below extension channel */
			*center = *primary - offset;
		} else {
			/* Channels 5-9 must be below if channel 13 is not supported */
			if (!cl_chan_info_get(cl_hw, 13, CHNL_BW_20)) {
				*center = *primary - offset;
			} else {
				/* Set below/above according to NVRAM configuration */
				if (cl_hw->conf->ce_extension_channel == -1)
					*center = *primary - offset;
				else
					*center = *primary + offset;
			}
		}
	} else if (bw == CHNL_BW_80) {
		*center = CENTER_FREQ_24G_BW_80MHZ;
	} else {
		/* 160MHz */
		*center = CENTER_FREQ_24G_BW_160MHZ;
	}

	return 0;
}

int cl_chandef_calc(struct cl_hw *cl_hw, u32 channel, u32 bw,
		    enum nl80211_chan_width *width, u32 *primary, u32 *center)
{
	u16 freq = ieee80211_channel_to_frequency(channel, cl_hw->nl_band);
	u32 offset = 0;
	int ret = 0;

	switch (bw) {
	case CHNL_BW_20:
		offset = 0;
		if (channel == 14)
			*width = NL80211_CHAN_WIDTH_20_NOHT;
		else
			*width = NL80211_CHAN_WIDTH_20;
		break;
	case CHNL_BW_40:
		offset = 10;
		*width = NL80211_CHAN_WIDTH_40;
		break;
	case CHNL_BW_80:
		if (cl_band_is_24g(cl_hw)) {
			cl_dbg_err(cl_hw, "Invalid bandwidth - %u\n", bw);
			return -EINVAL;
		}
		offset = 30;
		*width = NL80211_CHAN_WIDTH_80;
		break;
	case CHNL_BW_160:
		if (cl_band_is_24g(cl_hw)) {
			cl_dbg_err(cl_hw, "Invalid bandwidth - %u\n", bw);
			return -EINVAL;
		}
		offset = 70;
		*width = NL80211_CHAN_WIDTH_160;
		break;
	default:
		cl_dbg_err(cl_hw, "Invalid bandwidth - %u\n", bw);
		return -EINVAL;
	}

	if (cl_band_is_6g(cl_hw))
		ret = cl_chandef_calc_6g(cl_hw, freq, bw, offset, primary, center);
	else if (cl_band_is_5g(cl_hw))
		ret = cl_chandef_calc_5g(cl_hw, freq, bw, offset, primary, center);
	else
		ret = cl_chandef_calc_24g(cl_hw, freq, bw, offset, primary, center);

	cl_dbg_trace(cl_hw, "primary=%u center=%u\n", *primary, *center);

	return ret;
}

/* This duplication to support multi-band calibration */
int cl_chandef_calc_calib(struct cl_hw *cl_hw, u32 channel, u32 bw,
			  enum nl80211_chan_width *width, u32 *primary, u32 *center,
			  u8 band)
{
	u16 freq = 0;
	u32 offset = 0;
	u8 nl_band;
	int ret = 0;

	if (cl_band_is_6g_band(band))
		nl_band = NL80211_BAND_6GHZ;
	else if (cl_band_is_5g_band(band))
		nl_band = NL80211_BAND_5GHZ;
	else
		nl_band = NL80211_BAND_2GHZ;
	freq = ieee80211_channel_to_frequency(channel, nl_band);

	switch (bw) {
	case CHNL_BW_20:
		offset = 0;
		if (channel == 14)
			*width = NL80211_CHAN_WIDTH_20_NOHT;
		else
			*width = NL80211_CHAN_WIDTH_20;
		break;
	case CHNL_BW_40:
		offset = 10;
		*width = NL80211_CHAN_WIDTH_40;
		break;
	case CHNL_BW_80:
		if (cl_band_is_24g_band(band)) {
			cl_dbg_err(cl_hw, "Invalid bandwidth - %u\n", bw);
			return -EINVAL;
		}
		offset = 30;
		*width = NL80211_CHAN_WIDTH_80;
		break;
	case CHNL_BW_160:
		if (cl_band_is_24g_band(band)) {
			cl_dbg_err(cl_hw, "Invalid bandwidth - %u\n", bw);
			return -EINVAL;
		}
		offset = 70;
		*width = NL80211_CHAN_WIDTH_160;
		break;
	default:
		cl_dbg_err(cl_hw, "Invalid bandwidth - %u\n", bw);
		return -EINVAL;
	}

	if (cl_band_is_6g_band(band))
		ret = cl_chandef_calc_6g(cl_hw, freq, bw, offset, primary, center);
	else if (cl_band_is_5g_band(band))
		ret = cl_chandef_calc_5g(cl_hw, freq, bw, offset, primary, center);
	else
		ret = cl_chandef_calc_24g(cl_hw, freq, bw, offset, primary, center);

	cl_dbg_trace(cl_hw, "primary=%u center=%u\n", *primary, *center);

	return ret;
}

int cl_chandef_get_default(struct cl_hw *cl_hw, enum nl80211_chan_width *width,
			   u32 *primary, u32 *center)
{
	u32 bw = cl_hw->conf->ce_channel_bandwidth;
	u32 channel = cl_hw->conf->ha_channel;

	return cl_chandef_calc(cl_hw, channel, bw, width, primary, center);
}
