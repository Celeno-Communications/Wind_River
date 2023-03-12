// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_cap.h"
#include "cl_utils.h"
#include "cl_band.h"
#include "cl_chan_info.h"
#include "cl_sta.h"
#include "cl_rx_amsdu.h"

#define CL_HT_CAPABILITIES                                              \
{                                                                       \
	.ht_supported = true,                                           \
	.cap = IEEE80211_HT_CAP_DSSSCCK40 | IEEE80211_HT_CAP_MAX_AMSDU, \
	.ampdu_factor = IEEE80211_HT_MAX_AMPDU_64K,                     \
	.ampdu_density = IEEE80211_HT_MPDU_DENSITY_2,                   \
	.mcs = {                                                        \
		.rx_mask = { 0xff, 0, 0, 0, 0, 0, 0, 0, 0, 0 },         \
		.tx_params = IEEE80211_HT_MCS_TX_DEFINED,               \
	},                                                              \
}

#define CL_VHT_CAPABILITIES                                             \
{                                                                       \
	.vht_supported = false,                                         \
	.cap =                                                          \
		IEEE80211_VHT_CAP_SU_BEAMFORMER_CAPABLE |               \
		IEEE80211_VHT_CAP_SU_BEAMFORMEE_CAPABLE |               \
		IEEE80211_VHT_CAP_MU_BEAMFORMER_CAPABLE |               \
		IEEE80211_VHT_CAP_MU_BEAMFORMEE_CAPABLE |               \
		(3 << IEEE80211_VHT_CAP_SOUNDING_DIMENSIONS_SHIFT) |    \
		(3 << IEEE80211_VHT_CAP_BEAMFORMEE_STS_SHIFT),          \
	.vht_mcs = {                                                    \
		.rx_mcs_map = cpu_to_le16(                              \
				IEEE80211_VHT_MCS_SUPPORT_0_7   << 0  | \
				IEEE80211_VHT_MCS_NOT_SUPPORTED << 2  | \
				IEEE80211_VHT_MCS_NOT_SUPPORTED << 4  | \
				IEEE80211_VHT_MCS_NOT_SUPPORTED << 6  | \
				IEEE80211_VHT_MCS_NOT_SUPPORTED << 8  | \
				IEEE80211_VHT_MCS_NOT_SUPPORTED << 10 | \
				IEEE80211_VHT_MCS_NOT_SUPPORTED << 12 | \
				IEEE80211_VHT_MCS_NOT_SUPPORTED << 14), \
		.tx_mcs_map = cpu_to_le16(                              \
				IEEE80211_VHT_MCS_SUPPORT_0_7   << 0  | \
				IEEE80211_VHT_MCS_NOT_SUPPORTED << 2  | \
				IEEE80211_VHT_MCS_NOT_SUPPORTED << 4  | \
				IEEE80211_VHT_MCS_NOT_SUPPORTED << 6  | \
				IEEE80211_VHT_MCS_NOT_SUPPORTED << 8  | \
				IEEE80211_VHT_MCS_NOT_SUPPORTED << 10 | \
				IEEE80211_VHT_MCS_NOT_SUPPORTED << 12 | \
				IEEE80211_VHT_MCS_NOT_SUPPORTED << 14), \
	}                                                               \
}

#define CL_HE_CAP_ELEM_STATION                                                       \
{                                                                                    \
	.mac_cap_info[0] = IEEE80211_HE_MAC_CAP0_HTC_HE,                             \
	.mac_cap_info[1] = 0,                                                        \
	.mac_cap_info[2] = 0,                                                        \
	.mac_cap_info[3] = IEEE80211_HE_MAC_CAP3_MAX_AMPDU_LEN_EXP_EXT_2,            \
	.mac_cap_info[4] = IEEE80211_HE_MAC_CAP4_BQR,                                \
	.mac_cap_info[5] = IEEE80211_HE_MAC_CAP5_HT_VHT_TRIG_FRAME_RX,               \
	.phy_cap_info[0] = IEEE80211_HE_PHY_CAP0_CHANNEL_WIDTH_SET_RU_MAPPING_IN_2G, \
	.phy_cap_info[1] = IEEE80211_HE_PHY_CAP1_DEVICE_CLASS_A,                     \
	.phy_cap_info[2] = 0,                                                        \
	.phy_cap_info[3] = 0,                                                        \
	.phy_cap_info[4] = 0,                                                        \
	.phy_cap_info[5] = 0,                                                        \
	.phy_cap_info[6] = 0,                                                        \
	.phy_cap_info[7] = 0,                                                        \
	.phy_cap_info[8] = IEEE80211_HE_PHY_CAP8_20MHZ_IN_40MHZ_HE_PPDU_IN_2G,       \
	.phy_cap_info[9] = IEEE80211_HE_PHY_CAP9_NOMIMAL_PKT_PADDING_16US,           \
	.phy_cap_info[10] = 0,                                                       \
}

#define CL_HE_CAP_ELEM_AP                                                       \
{                                                                               \
	.mac_cap_info[0] = IEEE80211_HE_MAC_CAP0_HTC_HE,                        \
	.mac_cap_info[1] = 0,                                                   \
	.mac_cap_info[2] = 0,                                                   \
	.mac_cap_info[3] = IEEE80211_HE_MAC_CAP3_MAX_AMPDU_LEN_EXP_EXT_2,       \
	.mac_cap_info[4] = IEEE80211_HE_MAC_CAP4_BQR,                           \
	.mac_cap_info[5] = 0,                                                   \
	.phy_cap_info[0] = 0,                                                   \
	.phy_cap_info[1] = IEEE80211_HE_PHY_CAP1_DEVICE_CLASS_A,                \
	.phy_cap_info[2] = 0,                                                   \
	.phy_cap_info[3] = 0,                                                   \
	.phy_cap_info[4] = 0,                                                   \
	.phy_cap_info[5] = 0,                                                   \
	.phy_cap_info[6] = 0,                                                   \
	.phy_cap_info[7] = 0,                                                   \
	.phy_cap_info[8] = 0,                                                   \
	.phy_cap_info[9] = IEEE80211_HE_PHY_CAP9_NOMIMAL_PKT_PADDING_16US,      \
	.phy_cap_info[10] = 0,                                                  \
}

#define CL_HE_CAP_ELEM_MESH_POINT                                               \
{                                                                               \
	.mac_cap_info[0] = IEEE80211_HE_MAC_CAP0_HTC_HE,                        \
	.mac_cap_info[1] = 0,                                                   \
	.mac_cap_info[2] = 0,                                                   \
	.mac_cap_info[3] = IEEE80211_HE_MAC_CAP3_MAX_AMPDU_LEN_EXP_EXT_2,       \
	.mac_cap_info[4] = IEEE80211_HE_MAC_CAP4_BQR,                           \
	.mac_cap_info[5] = 0,                                                   \
	.phy_cap_info[0] = 0,                                                   \
	.phy_cap_info[1] = IEEE80211_HE_PHY_CAP1_DEVICE_CLASS_A,                \
	.phy_cap_info[2] = 0,                                                   \
	.phy_cap_info[3] = 0,                                                   \
	.phy_cap_info[4] = 0,                                                   \
	.phy_cap_info[5] = 0,                                                   \
	.phy_cap_info[6] = 0,                                                   \
	.phy_cap_info[7] = 0,                                                   \
	.phy_cap_info[8] = 0,                                                   \
	.phy_cap_info[9] = IEEE80211_HE_PHY_CAP9_NOMIMAL_PKT_PADDING_16US,      \
	.phy_cap_info[10] = 0,                                                  \
}

#define CL_HE_MCS_NSS_SUPP                   \
{                                            \
	.rx_mcs_80 = cpu_to_le16(0xff00),    \
	.tx_mcs_80 = cpu_to_le16(0xff00),    \
	.rx_mcs_160 = cpu_to_le16(0xff00),   \
	.tx_mcs_160 = cpu_to_le16(0xff00),   \
	.rx_mcs_80p80 = cpu_to_le16(0xffff), \
	.tx_mcs_80p80 = cpu_to_le16(0xffff), \
}

#define RATE(_bitrate, _hw_rate, _flags) { \
	.bitrate = (_bitrate),             \
	.flags = (_flags),                 \
	.hw_value = (_hw_rate),            \
}

#define CHAN(_freq, _idx) {     \
	.center_freq = (_freq), \
	.hw_value = (_idx),     \
	.max_power = 18,        \
}

static struct ieee80211_sband_iftype_data cl_he_data[] = {
	{
		.types_mask = BIT(NL80211_IFTYPE_STATION),
		.he_cap = {
			.has_he = true,
			.he_cap_elem = CL_HE_CAP_ELEM_STATION,
			.he_mcs_nss_supp = CL_HE_MCS_NSS_SUPP,
		},
	},
	{
		.types_mask = BIT(NL80211_IFTYPE_AP),
		.he_cap = {
			.has_he = true,
			.he_cap_elem = CL_HE_CAP_ELEM_AP,
			.he_mcs_nss_supp = CL_HE_MCS_NSS_SUPP,
		},
	},
	{
		.types_mask = BIT(NL80211_IFTYPE_MESH_POINT),
		.he_cap = {
			.has_he = true,
			.he_cap_elem = CL_HE_CAP_ELEM_MESH_POINT,
			.he_mcs_nss_supp = CL_HE_MCS_NSS_SUPP,
		},
	},
};

static struct ieee80211_rate cl_ratetable[] = {
	RATE(10,  0x00, 0),
	RATE(20,  0x01, IEEE80211_RATE_SHORT_PREAMBLE),
	RATE(55,  0x02, IEEE80211_RATE_SHORT_PREAMBLE),
	RATE(110, 0x03, IEEE80211_RATE_SHORT_PREAMBLE),
	RATE(60,  0x04, 0),
	RATE(90,  0x05, 0),
	RATE(120, 0x06, 0),
	RATE(180, 0x07, 0),
	RATE(240, 0x08, 0),
	RATE(360, 0x09, 0),
	RATE(480, 0x0A, 0),
	RATE(540, 0x0B, 0),
};

/* The channels indexes here are not used anymore */
static struct ieee80211_channel cl_2ghz_channels[] = {
	CHAN(2412, 0),
	CHAN(2417, 1),
	CHAN(2422, 2),
	CHAN(2427, 3),
	CHAN(2432, 4),
	CHAN(2437, 5),
	CHAN(2442, 6),
	CHAN(2447, 7),
	CHAN(2452, 8),
	CHAN(2457, 9),
	CHAN(2462, 10),
	CHAN(2467, 11),
	CHAN(2472, 12),
	CHAN(2484, 13),
};

static struct ieee80211_channel cl_5ghz_channels[] = {
	CHAN(5180, 0),  /* 36 -  20MHz */
	CHAN(5200, 1),  /* 40 -  20MHz */
	CHAN(5220, 2),  /* 44 -  20MHz */
	CHAN(5240, 3),  /* 48 -  20MHz */
	CHAN(5260, 4),  /* 52 -  20MHz */
	CHAN(5280, 5),  /* 56 -  20MHz */
	CHAN(5300, 6),  /* 60 -  20MHz */
	CHAN(5320, 7),  /* 64 -  20MHz */
	CHAN(5500, 8),  /* 100 - 20MHz */
	CHAN(5520, 9),  /* 104 - 20MHz */
	CHAN(5540, 10), /* 108 - 20MHz */
	CHAN(5560, 11), /* 112 - 20MHz */
	CHAN(5580, 12), /* 116 - 20MHz */
	CHAN(5600, 13), /* 120 - 20MHz */
	CHAN(5620, 14), /* 124 - 20MHz */
	CHAN(5640, 15), /* 128 - 20MHz */
	CHAN(5660, 16), /* 132 - 20MHz */
	CHAN(5680, 17), /* 136 - 20MHz */
	CHAN(5700, 18), /* 140 - 20MHz */
	CHAN(5720, 19), /* 144 - 20MHz */
	CHAN(5745, 20), /* 149 - 20MHz */
	CHAN(5765, 21), /* 153 - 20MHz */
	CHAN(5785, 22), /* 157 - 20MHz */
	CHAN(5805, 23), /* 161 - 20MHz */
	CHAN(5825, 24), /* 165 - 20MHz */
};

static struct ieee80211_channel cl_6ghz_channels[] = {
	CHAN(5955, 1),  /* 1 - 20MHz */
	CHAN(5935, 2),  /* 2 - 20MHz */
	CHAN(5975, 5),  /* 5 - 20MHz */
	CHAN(5995, 9),  /* 9 - 20MHz */
	CHAN(6015, 13),  /* 13 - 20MHz */
	CHAN(6035, 17),  /* 17 - 20MHz */
	CHAN(6055, 21),  /* 21 - 20MHz */
	CHAN(6075, 25),  /* 25 - 20MHz */
	CHAN(6095, 29),  /* 29 - 20MHz */
	CHAN(6115, 33),  /* 33 - 20MHz */
	CHAN(6135, 37),  /* 37 - 20MHz */
	CHAN(6155, 41),  /* 41 - 20MHz */
	CHAN(6175, 45),  /* 45 - 20MHz */
	CHAN(6195, 49),  /* 49 - 20MHz */
	CHAN(6215, 53),  /* 53 - 20MHz */
	CHAN(6235, 57),  /* 57 - 20MHz */
	CHAN(6255, 61),  /* 61 - 20MHz */
	CHAN(6275, 65),  /* 65 - 20MHz */
	CHAN(6295, 69),  /* 69 - 20MHz */
	CHAN(6315, 73),  /* 73 - 20MHz */
	CHAN(6335, 77),  /* 77 - 20MHz */
	CHAN(6355, 81),  /* 81 - 20MHz */
	CHAN(6375, 85),  /* 85 - 20MHz */
	CHAN(6395, 89),  /* 89 - 20MHz */
	CHAN(6415, 93),  /* 93 - 20MHz */
	CHAN(6435, 97),  /* 97 - 20MHz */
	CHAN(6455, 101),  /* 101 - 20MHz */
	CHAN(6475, 105),  /* 105 - 20MHz */
	CHAN(6495, 109),  /* 109 - 20MHz */
	CHAN(6515, 113),  /* 113 - 20MHz */
	CHAN(6535, 117),  /* 117 - 20MHz */
	CHAN(6555, 121),  /* 121 - 20MHz */
	CHAN(6575, 125),  /* 125 - 20MHz */
	CHAN(6595, 129),  /* 129 - 20MHz */
	CHAN(6615, 133),  /* 133 - 20MHz */
	CHAN(6635, 137),  /* 137 - 20MHz */
	CHAN(6655, 141),  /* 141 - 20MHz */
	CHAN(6675, 145),  /* 145 - 20MHz */
	CHAN(6695, 149),  /* 149 - 20MHz */
	CHAN(6715, 153),  /* 153 - 20MHz */
	CHAN(6735, 157),  /* 157 - 20MHz */
	CHAN(6755, 161),  /* 161 - 20MHz */
	CHAN(6775, 165),  /* 165 - 20MHz */
	CHAN(6795, 169),  /* 169 - 20MHz */
	CHAN(6815, 173),  /* 173 - 20MHz */
	CHAN(6835, 177),  /* 177 - 20MHz */
	CHAN(6855, 181),  /* 181 - 20MHz */
	CHAN(6875, 188),  /* 185 - 20MHz */
	CHAN(6895, 189),  /* 189 - 20MHz */
	CHAN(6915, 193),  /* 193 - 20MHz */
	CHAN(6935, 197),  /* 197 - 20MHz */
	CHAN(6955, 201),  /* 201 - 20MHz */
	CHAN(6975, 205),  /* 205 - 20MHz */
	CHAN(6995, 209),  /* 209 - 20MHz */
	CHAN(7015, 213),  /* 213 - 20MHz */
	CHAN(7035, 217),  /* 217 - 20MHz */
	CHAN(7055, 221),  /* 221 - 20MHz */
	CHAN(7075, 225),  /* 225 - 20MHz */
	CHAN(7095, 229),  /* 229 - 20MHz */
	CHAN(7115, 233),  /* 233 - 20MHz */
};

static struct ieee80211_supported_band cl_band_2ghz = {
	.channels   = cl_2ghz_channels,
	.n_channels = ARRAY_SIZE(cl_2ghz_channels),
	.bitrates   = cl_ratetable,
	.n_bitrates = ARRAY_SIZE(cl_ratetable),
	.ht_cap     = CL_HT_CAPABILITIES,
	.vht_cap    = CL_VHT_CAPABILITIES,
};

static struct ieee80211_supported_band cl_band_5ghz = {
	.channels   = cl_5ghz_channels,
	.n_channels = ARRAY_SIZE(cl_5ghz_channels),
	.bitrates   = &cl_ratetable[4],
	.n_bitrates = ARRAY_SIZE(cl_ratetable) - 4,
	.ht_cap     = CL_HT_CAPABILITIES,
	.vht_cap    = CL_VHT_CAPABILITIES,
};

static struct ieee80211_supported_band cl_band_6ghz = {
	.channels   = cl_6ghz_channels,
	.n_channels = ARRAY_SIZE(cl_6ghz_channels),
	.bitrates   = &cl_ratetable[4],
	.n_bitrates = ARRAY_SIZE(cl_ratetable) - 4,
};

static const struct ieee80211_iface_limit cl_limits[] = {
	{
		.max   = MAX_BSS_NUM,
		.types = BIT(NL80211_IFTYPE_AP) |
			 BIT(NL80211_IFTYPE_STATION) |
			 BIT(NL80211_IFTYPE_MESH_POINT),
	},
};

static const struct ieee80211_iface_combination cl_combinations[] = {
	{
		.limits = cl_limits,
		.n_limits = ARRAY_SIZE(cl_limits),
		.num_different_channels = 1,
		.max_interfaces = MAX_BSS_NUM,
		.beacon_int_min_gcd = 100,
		.radar_detect_widths = BIT(NL80211_CHAN_WIDTH_20) |
				       BIT(NL80211_CHAN_WIDTH_40) |
				       BIT(NL80211_CHAN_WIDTH_80) |
				       BIT(NL80211_CHAN_WIDTH_160),
	}
};

static u8 he_mcs_supp_tx(struct cl_hw *cl_hw, u8 nss)
{
	u8 mcs = cl_hw->conf->ce_he_mcs_nss_supp_tx[nss];

	switch (mcs) {
	case WRS_MCS_7:
		return IEEE80211_HE_MCS_SUPPORT_0_7;
	case WRS_MCS_9:
		return IEEE80211_HE_MCS_SUPPORT_0_9;
	case WRS_MCS_11:
		return IEEE80211_HE_MCS_SUPPORT_0_11;
	}

	cl_dbg_err(cl_hw, "Invalid mcs %u for nss %u. Must be 7, 9 or 11!\n", mcs, nss);
	return IEEE80211_HE_MCS_NOT_SUPPORTED;
}

static u8 he_mcs_supp_rx(struct cl_hw *cl_hw, u8 nss)
{
	u8 mcs = cl_hw->conf->ce_he_mcs_nss_supp_rx[nss];

	switch (mcs) {
	case WRS_MCS_7:
		return IEEE80211_HE_MCS_SUPPORT_0_7;
	case WRS_MCS_9:
		return IEEE80211_HE_MCS_SUPPORT_0_9;
	case WRS_MCS_11:
		return IEEE80211_HE_MCS_SUPPORT_0_11;
	}

	cl_dbg_err(cl_hw, "Invalid mcs %u for nss %u. Must be 7, 9 or 11!\n", mcs, nss);
	return IEEE80211_HE_MCS_NOT_SUPPORTED;
}

static u8 vht_mcs_supp_tx(struct cl_hw *cl_hw, u8 nss)
{
	u8 mcs = cl_hw->conf->ce_vht_mcs_nss_supp_tx[nss];

	switch (mcs) {
	case WRS_MCS_7:
		return IEEE80211_VHT_MCS_SUPPORT_0_7;
	case WRS_MCS_8:
		return IEEE80211_VHT_MCS_SUPPORT_0_8;
	case WRS_MCS_9:
		return IEEE80211_VHT_MCS_SUPPORT_0_9;
	}

	cl_dbg_err(cl_hw, "Invalid mcs %u for nss %u. Must be 7-9!\n", mcs, nss);
	return IEEE80211_VHT_MCS_NOT_SUPPORTED;
}

static u8 vht_mcs_supp_rx(struct cl_hw *cl_hw, u8 nss)
{
	u8 mcs = cl_hw->conf->ce_vht_mcs_nss_supp_rx[nss];

	switch (mcs) {
	case WRS_MCS_7:
		return IEEE80211_VHT_MCS_SUPPORT_0_7;
	case WRS_MCS_8:
		return IEEE80211_VHT_MCS_SUPPORT_0_8;
	case WRS_MCS_9:
		return IEEE80211_VHT_MCS_SUPPORT_0_9;
	}

	cl_dbg_err(cl_hw, "Invalid mcs %u for nss %u. Must be 7-9!\n", mcs, nss);
	return IEEE80211_VHT_MCS_NOT_SUPPORTED;
}

static void cl_set_he_6ghz_capab(struct cl_hw *cl_hw)
{
	struct ieee80211_he_6ghz_capa *he_6ghz_cap0 = &cl_hw->iftype_data[0].he_6ghz_capa;
	struct ieee80211_he_6ghz_capa *he_6ghz_cap1 = &cl_hw->iftype_data[1].he_6ghz_capa;
	struct ieee80211_he_6ghz_capa *he_6ghz_cap2 = &cl_hw->iftype_data[2].he_6ghz_capa;

	he_6ghz_cap0->capa = cpu_to_le16(IEEE80211_HT_MPDU_DENSITY_2);

	he_6ghz_cap0->capa |=
		cpu_to_le16(cl_hw->conf->ha_max_mpdu_len << HE_6GHZ_CAP_MAX_MPDU_LEN_OFFSET);
	he_6ghz_cap0->capa |=
		cpu_to_le16(IEEE80211_VHT_MAX_AMPDU_1024K << HE_6GHZ_CAP_MAX_AMPDU_LEN_EXP_OFFSET);

	he_6ghz_cap1->capa = he_6ghz_cap0->capa;
	he_6ghz_cap2->capa = he_6ghz_cap0->capa;
}

static void _cl_set_he_capab(struct cl_hw *cl_hw, u8 idx)
{
	struct ieee80211_sta_he_cap *he_cap = &cl_hw->iftype_data[idx].he_cap;
	struct ieee80211_he_mcs_nss_supp *he_mcs_nss_supp = &he_cap->he_mcs_nss_supp;
	struct ieee80211_he_cap_elem *he_cap_elem = &he_cap->he_cap_elem;
	u8 rx_nss = cl_hw->conf->ce_rx_nss;
	u8 tx_nss = cl_hw->conf->ce_tx_nss;
	u8 bw = cl_hw->conf->ce_channel_bandwidth;
	int i = 0;

	if (BAND_IS_5G_6G(cl_hw)) {
		if (bw == CHNL_BW_160) {
			he_cap_elem->phy_cap_info[0] |=
				IEEE80211_HE_PHY_CAP0_CHANNEL_WIDTH_SET_160MHZ_IN_5G;

			for (i = 0; i < rx_nss; i++)
				he_mcs_nss_supp->rx_mcs_160 |=
					cpu_to_le16(he_mcs_supp_rx(cl_hw, i) << (i * 2));

			for (i = 0; i < tx_nss; i++)
				he_mcs_nss_supp->tx_mcs_160 |=
					cpu_to_le16(he_mcs_supp_tx(cl_hw, i) << (i * 2));
		}

		he_cap_elem->phy_cap_info[0] |=
			IEEE80211_HE_PHY_CAP0_CHANNEL_WIDTH_SET_40MHZ_80MHZ_IN_5G;

		for (i = 0; i < rx_nss; i++)
			he_mcs_nss_supp->rx_mcs_80 |=
				cpu_to_le16(he_mcs_supp_rx(cl_hw, i) << (i * 2));

		for (i = 0; i < tx_nss; i++)
			he_mcs_nss_supp->tx_mcs_80 |=
				cpu_to_le16(he_mcs_supp_tx(cl_hw, i) << (i * 2));
	} else {
		if (bw > CHNL_BW_20)
			he_cap_elem->phy_cap_info[0] |=
				IEEE80211_HE_PHY_CAP0_CHANNEL_WIDTH_SET_40MHZ_IN_2G;

		for (i = 0; i < rx_nss; i++)
			he_mcs_nss_supp->rx_mcs_80 |=
				cpu_to_le16(he_mcs_supp_rx(cl_hw, i) << (i * 2));

		for (i = 0; i < tx_nss; i++)
			he_mcs_nss_supp->tx_mcs_80 |=
				cpu_to_le16(he_mcs_supp_tx(cl_hw, i) << (i * 2));
	}

	for (i = rx_nss; i < 8; i++) {
		he_mcs_nss_supp->rx_mcs_80 |=
			cpu_to_le16(IEEE80211_HE_MCS_NOT_SUPPORTED << (i * 2));
		he_mcs_nss_supp->rx_mcs_160 |=
			cpu_to_le16(IEEE80211_HE_MCS_NOT_SUPPORTED << (i * 2));
	}

	for (i = tx_nss; i < 8; i++) {
		he_mcs_nss_supp->tx_mcs_80 |=
			cpu_to_le16(IEEE80211_HE_MCS_NOT_SUPPORTED << (i * 2));
		he_mcs_nss_supp->tx_mcs_160 |=
			cpu_to_le16(IEEE80211_HE_MCS_NOT_SUPPORTED << (i * 2));
	}

	if (cl_hw->conf->ce_he_rxldpc_en)
		he_cap_elem->phy_cap_info[1] |=
			IEEE80211_HE_PHY_CAP1_LDPC_CODING_IN_PAYLOAD;

	if (cl_hw->conf->ci_rx_he_mu_ppdu)
		he_cap_elem->phy_cap_info[3] |=
			IEEE80211_HE_PHY_CAP3_RX_PARTIAL_BW_SU_IN_20MHZ_MU;

	he_cap_elem->phy_cap_info[3] |=
		IEEE80211_HE_PHY_CAP3_SU_BEAMFORMER;
	he_cap_elem->phy_cap_info[5] |=
		IEEE80211_HE_PHY_CAP5_BEAMFORMEE_NUM_SND_DIM_UNDER_80MHZ_4;
}

static void cl_set_he_capab(struct cl_hw *cl_hw)
{
	struct ieee80211_sta_he_cap *he_cap0 = &cl_hw->iftype_data[0].he_cap;
	struct ieee80211_sta_he_cap *he_cap1 = &cl_hw->iftype_data[1].he_cap;
	struct ieee80211_he_cap_elem *he_cap_elem0 = &he_cap0->he_cap_elem;
	struct ieee80211_he_cap_elem *he_cap_elem1 = &he_cap1->he_cap_elem;

	struct cl_tcv_conf *conf = cl_hw->conf;
	u8 tf_mac_pad_dur = conf->ci_tf_mac_pad_dur;

	memcpy(&cl_hw->iftype_data, cl_he_data, sizeof(cl_hw->iftype_data));

	/* TWT support */
	if (conf->ce_twt_en) {
		/* STA mode */
		he_cap_elem0->mac_cap_info[0] |= IEEE80211_HE_MAC_CAP0_TWT_REQ;
		/* AP mode */
		he_cap_elem1->mac_cap_info[0] |= IEEE80211_HE_MAC_CAP0_TWT_RES;
	}

	/* OMI support */
	if (conf->ce_omi_en) {
		/* STA mode */
		he_cap_elem0->mac_cap_info[3] |= IEEE80211_HE_MAC_CAP3_OMI_CONTROL;
		/* AP mode */
		he_cap_elem1->mac_cap_info[3] |= IEEE80211_HE_MAC_CAP3_OMI_CONTROL;
		he_cap_elem1->mac_cap_info[5] |= IEEE80211_HE_MAC_CAP5_OM_CTRL_UL_MU_DATA_DIS_RX;
	}

	if (tf_mac_pad_dur == 1)
		he_cap_elem0->mac_cap_info[1] |= IEEE80211_HE_MAC_CAP1_TF_MAC_PAD_DUR_8US;
	else if (tf_mac_pad_dur == 2)
		he_cap_elem0->mac_cap_info[1] |= IEEE80211_HE_MAC_CAP1_TF_MAC_PAD_DUR_16US;

	_cl_set_he_capab(cl_hw, 0);
	_cl_set_he_capab(cl_hw, 1);
	_cl_set_he_capab(cl_hw, 2);

	if (cl_band_is_6g(cl_hw))
		cl_set_he_6ghz_capab(cl_hw);

	cl_hw->hw->wiphy->flags |= WIPHY_FLAG_SUPPORTS_BSS_COLOR;

	cl_hw->sband.n_iftype_data = ARRAY_SIZE(cl_he_data);
	cl_hw->sband.iftype_data = cl_hw->iftype_data;
}

void cl_cap_dyn_params(struct cl_hw *cl_hw)
{
	struct ieee80211_hw *hw = cl_hw->hw;
	struct wiphy *wiphy = hw->wiphy;
	struct cl_tcv_conf *conf = cl_hw->conf;
	u8 rx_nss = conf->ce_rx_nss;
	u8 tx_nss = conf->ce_tx_nss;
	u8 guard_interval = conf->ha_short_guard_interval;
	u8 i;
	u8 bw = cl_hw->conf->ce_channel_bandwidth;
	struct ieee80211_supported_band *sband = &cl_hw->sband;
	struct ieee80211_sta_ht_cap *sband_ht_cap = &sband->ht_cap;
	struct ieee80211_sta_vht_cap *sband_vht_cap = &sband->vht_cap;

	if (cl_band_is_6g(cl_hw)) {
		memcpy(sband, &cl_band_6ghz, sizeof(struct ieee80211_supported_band));
	} else if (cl_band_is_5g(cl_hw)) {
		memcpy(sband, &cl_band_5ghz, sizeof(struct ieee80211_supported_band));
	} else {
		memcpy(sband, &cl_band_2ghz, sizeof(struct ieee80211_supported_band));

		if (!conf->ci_vht_cap_24g)
			memset(&sband->vht_cap, 0, sizeof(struct ieee80211_sta_vht_cap));
	}

	/* 6GHz doesn't support HT/VHT */
	if (!cl_band_is_6g(cl_hw)) {
		if (bw > CHNL_BW_20)
			sband_ht_cap->cap |= IEEE80211_HT_CAP_SUP_WIDTH_20_40;

		/* Guard_interval */
		if (guard_interval) {
			sband_ht_cap->cap |= IEEE80211_HT_CAP_SGI_20;

			if (bw >= CHNL_BW_40)
				sband_ht_cap->cap |= IEEE80211_HT_CAP_SGI_40;

			if (bw >= CHNL_BW_80)
				sband_vht_cap->cap |= IEEE80211_VHT_CAP_SHORT_GI_80;

			if (bw == CHNL_BW_160)
				sband_vht_cap->cap |= IEEE80211_VHT_CAP_SHORT_GI_160;
		}
	}

	/* Amsdu */
	cl_rx_amsdu_hw_en(hw, conf->ce_rxamsdu_en);
	cl_hw->txamsdu_en = conf->ce_txamsdu_en;

	/* Hw flags */
	ieee80211_hw_set(hw, HOST_BROADCAST_PS_BUFFERING);
	ieee80211_hw_set(hw, SIGNAL_DBM);
	ieee80211_hw_set(hw, REPORTS_TX_ACK_STATUS);
	ieee80211_hw_set(hw, QUEUE_CONTROL);
	ieee80211_hw_set(hw, WANT_MONITOR_VIF);
	ieee80211_hw_set(hw, SPECTRUM_MGMT);
	ieee80211_hw_set(hw, SUPPORTS_HT_CCK_RATES);
	ieee80211_hw_set(hw, HAS_RATE_CONTROL);
	ieee80211_hw_set(hw, SUPPORT_FAST_XMIT);
	ieee80211_hw_set(hw, NO_AUTO_VIF);

	if (conf->ci_offload_reorder_mode != RX_REORDER_BY_MAC80211) {
		ieee80211_hw_set(hw, SUPPORTS_REORDERING_BUFFER);
		ieee80211_hw_set(hw, AP_LINK_PS);
	}

	/*
	 * To disable the dynamic PS we say to the stack that we support it in
	 * HW. This will force mac80211 rely on us to handle this.
	 */
	ieee80211_hw_set(hw, SUPPORTS_DYNAMIC_PS);

	if (conf->ci_agg_tx)
		ieee80211_hw_set(hw, AMPDU_AGGREGATION);

	if (cl_hw->ieee80211w)
		ieee80211_hw_set(hw, MFP_CAPABLE);

	wiphy->interface_modes = BIT(NL80211_IFTYPE_STATION) |
				 BIT(NL80211_IFTYPE_AP) |
				 BIT(NL80211_IFTYPE_MESH_POINT);

	wiphy->flags |= WIPHY_FLAG_HAS_REMAIN_ON_CHANNEL |
			WIPHY_FLAG_HAS_CHANNEL_SWITCH;

	if (conf->ce_uapsd_en)
		wiphy->flags |= WIPHY_FLAG_AP_UAPSD;

	wiphy->iface_combinations = cl_combinations;
	wiphy->n_iface_combinations = ARRAY_SIZE(cl_combinations);

	hw->max_rates = IEEE80211_TX_MAX_RATES;
	hw->max_report_rates = IEEE80211_TX_MAX_RATES;
	hw->max_rate_tries = 1;

	hw->max_tx_aggregation_subframes = conf->ce_max_agg_size_tx;
	hw->max_rx_aggregation_subframes = conf->ce_max_agg_size_rx;

	hw->vif_data_size = sizeof(struct cl_vif);
	hw->sta_data_size = sizeof(struct cl_sta);

	hw->extra_tx_headroom = 0;
	hw->queues = IEEE80211_MAX_QUEUES;
	hw->offchannel_tx_hw_queue = CL_HWQ_VO;

	if (!cl_band_is_6g(cl_hw)) {
		if (conf->ce_ht_rxldpc_en)
			sband_ht_cap->cap |= IEEE80211_HT_CAP_LDPC_CODING;

		sband_ht_cap->cap |= IEEE80211_HT_CAP_MAX_AMSDU;

		sband_vht_cap->cap |= cl_hw->conf->ha_max_mpdu_len;
	}

	if (cl_band_is_5g(cl_hw) || (cl_band_is_24g(cl_hw) && conf->ci_vht_cap_24g)) {
		if (bw == CHNL_BW_160)
			sband_vht_cap->cap |= IEEE80211_VHT_CAP_SUPP_CHAN_WIDTH_160MHZ;

		sband_vht_cap->cap |= (conf->ha_vht_max_ampdu_len_exp <<
				       IEEE80211_VHT_CAP_MAX_A_MPDU_LENGTH_EXPONENT_SHIFT);

		if (conf->ce_vht_rxldpc_en)
			sband_vht_cap->cap |= IEEE80211_VHT_CAP_RXLDPC;

		sband_vht_cap->vht_mcs.rx_mcs_map = cpu_to_le16(0);
		sband_vht_cap->vht_mcs.tx_mcs_map = cpu_to_le16(0);

		for (i = 0; i < rx_nss; i++)
			sband_vht_cap->vht_mcs.rx_mcs_map |=
				cpu_to_le16(vht_mcs_supp_rx(cl_hw, i) << (i * 2));

		for (; i < 8; i++)
			sband_vht_cap->vht_mcs.rx_mcs_map |=
				cpu_to_le16(IEEE80211_VHT_MCS_NOT_SUPPORTED << (i * 2));

		for (i = 0; i < tx_nss; i++)
			sband_vht_cap->vht_mcs.tx_mcs_map |=
				cpu_to_le16(vht_mcs_supp_tx(cl_hw, i) << (i * 2));

		for (; i < 8; i++)
			sband_vht_cap->vht_mcs.tx_mcs_map |=
				cpu_to_le16(IEEE80211_VHT_MCS_NOT_SUPPORTED << (i * 2));

		sband_vht_cap->vht_supported = true;
	}

	/* 6GHz band supports HE only */
	if (!cl_band_is_6g(cl_hw))
		for (i = 0; i < rx_nss; i++)
			sband_ht_cap->mcs.rx_mask[i] = U8_MAX;

	if (cl_hw->conf->ce_wireless_mode > WIRELESS_MODE_HT_VHT)
		cl_set_he_capab(cl_hw);

	/* Get channels and power limitations information from ChannelInfo file */
	cl_chan_info_init(cl_hw);

	if (cl_band_is_6g(cl_hw)) {
		wiphy->bands[NL80211_BAND_2GHZ] = NULL;
		wiphy->bands[NL80211_BAND_5GHZ] = NULL;
		wiphy->bands[NL80211_BAND_6GHZ] = sband;
	} else if (cl_band_is_5g(cl_hw)) {
		wiphy->bands[NL80211_BAND_2GHZ] = NULL;
		wiphy->bands[NL80211_BAND_5GHZ] = sband;
		wiphy->bands[NL80211_BAND_6GHZ] = NULL;
	} else {
		wiphy->bands[NL80211_BAND_2GHZ] = sband;
		wiphy->bands[NL80211_BAND_5GHZ] = NULL;
		wiphy->bands[NL80211_BAND_6GHZ] = NULL;
	}

	wiphy->regulatory_flags |= REGULATORY_WIPHY_SELF_MANAGED;
}

enum he_pkt_ext_constellations {
	HE_PKT_EXT_BPSK = 0,
	HE_PKT_EXT_QPSK,
	HE_PKT_EXT_16QAM,
	HE_PKT_EXT_64QAM,
	HE_PKT_EXT_256QAM,
	HE_PKT_EXT_1024QAM,
	HE_PKT_EXT_RESERVED,
	HE_PKT_EXT_NONE,
};

static u8 mcs_to_constellation[WRS_MCS_MAX_HE] = {
	HE_PKT_EXT_BPSK,
	HE_PKT_EXT_QPSK,
	HE_PKT_EXT_QPSK,
	HE_PKT_EXT_16QAM,
	HE_PKT_EXT_16QAM,
	HE_PKT_EXT_64QAM,
	HE_PKT_EXT_64QAM,
	HE_PKT_EXT_64QAM,
	HE_PKT_EXT_256QAM,
	HE_PKT_EXT_256QAM,
	HE_PKT_EXT_1024QAM,
	HE_PKT_EXT_1024QAM
};

#define QAM_THR_1 0
#define QAM_THR_2 1
#define QAM_THR_MAX 2

static u8 get_ppe_val(u8 *ppe, u8 ppe_pos_bit)
{
	u8 byte_num = ppe_pos_bit / 8;
	u8 bit_num = ppe_pos_bit % 8;
	u8 residue_bits;
	u8 res;

	if (bit_num <= 5)
		return (ppe[byte_num] >> bit_num) &
		       (BIT(IEEE80211_PPE_THRES_INFO_PPET_SIZE) - 1);

	/*
	 * If bit_num > 5, we have to combine bits with next byte.
	 * Calculate how many bits we need to take from current byte (called
	 * here "residue_bits"), and add them to bits from next byte.
	 */
	residue_bits = 8 - bit_num;

	res = (ppe[byte_num + 1] &
	       (BIT(IEEE80211_PPE_THRES_INFO_PPET_SIZE - residue_bits) - 1)) <<
	      residue_bits;
	res += (ppe[byte_num] >> bit_num) & (BIT(residue_bits) - 1);

	return res;
}

static void set_fixed_ppe_val(u8 pe_dur[CHNL_BW_MAX][WRS_MCS_MAX_HE], u8 dur)
{
	u8 val = ((dur << 6) | (dur << 4) | (dur << 2) | dur);

	memset(pe_dur, val, CHNL_BW_MAX * WRS_MCS_MAX_HE);
}

void cl_cap_ppe_duration(struct cl_hw *cl_hw, struct ieee80211_sta *sta,
			 u8 pe_dur[CHNL_BW_MAX][WRS_MCS_MAX_HE])
{
	/*
	 * struct iwl_he_pkt_ext - QAM thresholds
	 * The required PPE is set via HE Capabilities IE, per Nss x BW x MCS
	 * The IE is organized in the following way:
	 * Support for Nss x BW (or RU) matrix:
	 *	(0=SISO, 1=MIMO2) x (0-20MHz, 1-40MHz, 2-80MHz, 3-160MHz)
	 * Each entry contains 2 QAM thresholds for 8us and 16us:
	 *	0=BPSK, 1=QPSK, 2=16QAM, 3=64QAM, 4=256QAM, 5=1024QAM, 6=RES, 7=NONE
	 * i.e. QAM_th1 < QAM_th2 such if TX uses QAM_tx:
	 *	QAM_tx < QAM_th1            --> PPE=0us
	 *	QAM_th1 <= QAM_tx < QAM_th2 --> PPE=8us
	 *	QAM_th2 <= QAM_tx           --> PPE=16us
	 * @pkt_ext_qam_th: QAM thresholds
	 *	For each Nss/Bw define 2 QAM thrsholds (0..5)
	 *	For rates below the low_th, no need for PPE
	 *	For rates between low_th and high_th, need 8us PPE
	 *	For rates equal or higher then the high_th, need 16us PPE
	 *	Nss (0-siso, 1-mimo2) x BW (0-20MHz, 1-40MHz, 2-80MHz, 3-160MHz) x
	 *		(0-low_th, 1-high_th)
	 */
	u8 pkt_ext_qam_th[WRS_SS_MAX][CHNL_BW_MAX][QAM_THR_MAX] = {{{0}}};

	/* If PPE Thresholds exist, parse them into a FW-familiar format. */
	u8 nss = (sta->he_cap.ppe_thres[0] & IEEE80211_PPE_THRES_NSS_MASK) + 1;
	u8 ru_index_bitmap = u32_get_bits(sta->he_cap.ppe_thres[0],
					  IEEE80211_PPE_THRES_RU_INDEX_BITMASK_MASK);
	u8 *ppe = &sta->he_cap.ppe_thres[0];
	u8 ppe_pos_bit = 7; /* Starting after PPE header */
	u8 bw, ss, mcs, constellation;

	/* Force NVRAM parameter */
	if (cl_hw->conf->ci_pe_duration <= PPE_16US) {
		set_fixed_ppe_val(pe_dur, cl_hw->conf->ci_pe_duration);
		return;
	}

	/*
	 * If STA sets the PPE Threshold Present subfield to 0,
	 * the value should be set according to the Nominal Packet Padding subfield
	 */
	if ((sta->he_cap.he_cap_elem.phy_cap_info[6] &
	     IEEE80211_HE_PHY_CAP6_PPE_THRESHOLD_PRESENT) == 0) {
		switch (sta->he_cap.he_cap_elem.phy_cap_info[9] &
			IEEE80211_HE_PHY_CAP9_NOMIMAL_PKT_PADDING_MASK) {
		case IEEE80211_HE_PHY_CAP9_NOMIMAL_PKT_PADDING_0US:
			set_fixed_ppe_val(pe_dur, PPE_0US);
			break;
		case IEEE80211_HE_PHY_CAP9_NOMIMAL_PKT_PADDING_8US:
			set_fixed_ppe_val(pe_dur, PPE_8US);
			break;
		case IEEE80211_HE_PHY_CAP9_NOMIMAL_PKT_PADDING_16US:
		default:
			set_fixed_ppe_val(pe_dur, PPE_16US);
			break;
		}

		return;
	}

	if (nss > WRS_SS_MAX)
		nss = WRS_SS_MAX;

	for (ss = 0; ss < nss; ss++) {
		u8 ru_index_tmp = ru_index_bitmap << 1;

		for (bw = 0; bw <= cl_hw->bw; bw++) {
			ru_index_tmp >>= 1;
			if (!(ru_index_tmp & 1))
				continue;

			pkt_ext_qam_th[ss][bw][QAM_THR_2] = get_ppe_val(ppe, ppe_pos_bit);
			ppe_pos_bit += IEEE80211_PPE_THRES_INFO_PPET_SIZE;
			pkt_ext_qam_th[ss][bw][QAM_THR_1] = get_ppe_val(ppe, ppe_pos_bit);
			ppe_pos_bit += IEEE80211_PPE_THRES_INFO_PPET_SIZE;
		}
	}

	/* Reset PE duration before filling it */
	memset(pe_dur, 0, CHNL_BW_MAX * WRS_MCS_MAX_HE);

	for (ss = 0; ss < nss; ss++) {
		for (bw = 0; bw <= cl_hw->bw; bw++) {
			for (mcs = 0; mcs < WRS_MCS_MAX_HE; mcs++) {
				constellation = mcs_to_constellation[mcs];

				if (constellation < pkt_ext_qam_th[ss][bw][QAM_THR_1])
					pe_dur[bw][mcs] |= (PPE_0US << (ss * 2));
				else if (constellation < pkt_ext_qam_th[ss][bw][QAM_THR_2])
					pe_dur[bw][mcs] |= (PPE_8US << (ss * 2));
				else
					pe_dur[bw][mcs] |= (PPE_16US << (ss * 2));
			}
		}
	}
}
