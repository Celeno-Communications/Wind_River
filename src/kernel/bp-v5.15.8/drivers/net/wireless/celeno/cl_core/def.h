/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef DEF_H
#define DEF_H

#include <linux/stddef.h>

/* We support 32 stations and last station is assigned for high priority */
#define CL_MAX_NUM_STA 32
#define FW_MAX_NUM_STA (CL_MAX_NUM_STA + 1)

/* Access Category enumeration */
enum {
	AC_BK = 0,
	AC_BE,
	AC_VI,
	AC_VO,
	AC_MAX
};

enum rx_buf_type {
	CL_RX_BUF_RXM,
	CL_RX_BUF_FW,
	CL_RX_BUF_MAX
};

#define MAX_SINGLE_QUEUES   (AC_MAX * FW_MAX_NUM_STA)
#define HIGH_PRIORITY_QUEUE (MAX_SINGLE_QUEUES - 1)

#define ASSERT_ERR_CHIP(condition) \
	do { \
		if (unlikely(!(condition))) \
			cl_dbg_chip_err(chip, ":ASSERT_ERR(" #condition ")\n"); \
	} while (0)

#define CL_TIME_DIFF(a, b) ((a) - (b))

#define msecs_round(ms) jiffies_to_msecs(msecs_to_jiffies(ms))

#define CPU_MAX_NUM 8

/* Must be aligned to NX_VIRT_DEV_MAX definition in rwnx_config.h */
#define MAX_BSS_NUM 8

#define MAX_TX_SW_AMSDU_PACKET 15

#define RX_MAX_MSDU_IN_AMSDU 16

/* MAX/MIN number of antennas supported */
#define MIN_ANTENNAS 1
/* MUST BE THE SAME AS MAX_ANTENNAS in driver_api_phy.h */
#define MAX_ANTENNAS 2
#define MAX_POWER_LEVELS 4

#define ANT_MASK(ant) (BIT(ant) - 1)

/* 6GHz defines */
#define HE_6GHZ_CAP_MIN_MPDU_START_OFFSET    0
#define HE_6GHZ_CAP_MAX_AMPDU_LEN_EXP_OFFSET 3
#define HE_6GHZ_CAP_MAX_MPDU_LEN_OFFSET      6
#define HE_6GHZ_CAP_MAX_AMPDU_LEN_FACTOR     13
#define HE_6GHZ_CAP_MAX_AMPDU_LEN_EXP_MASK   0x38

#define MHZ_TO_BW(mhz) ilog2((mhz) / 20)
#define BW_TO_MHZ(bw)  ((1 << (bw)) * 20)
#define BW_TO_KHZ(bw)  ((1 << (bw)) * 20000)

#define ENCRYPT_TYPE_STR(cipher) \
	   ((cipher) == CL_CIPHER_SUITE_USE_GROUP ? "USE_GROUP" : \
	   ((cipher) == CL_CIPHER_SUITE_WEP40 ? "WEP40" : \
	   ((cipher) == CL_CIPHER_SUITE_TKIP ? "TKIP" : \
	   ((cipher) == CL_CIPHER_SUITE_CCMP ? "CCMP" : \
	   ((cipher) == CL_CIPHER_SUITE_WEP104 ? "WEP104" : \
	   ((cipher) == CL_CIPHER_SUITE_GCMP ? "GCMP" : \
	   ((cipher) == CL_CIPHER_SUITE_GCMP_256 ? "GCMP_256" : \
	   ((cipher) == CL_CIPHER_SUITE_CCMP_256 ? "CCMP_256" : \
	   ((cipher) == CL_CIPHER_SUITE_BIP_GMAC_128 ? "BIP_GMAC_128" : \
	   ((cipher) == CL_CIPHER_SUITE_BIP_GMAC_256 ? "BIP_GMAC_256" : \
	   ((cipher) == CL_CIPHER_SUITE_BIP_CMAC_256 ? "CMAC_256" : \
	   ((cipher) == CL_CIPHER_SUITE_USE_NONE ? "NONE" : ""))))))))))))

#define AUTH_MODE_STR(mode) \
		((mode) == CL_AKM_SUITE_OPEN ? "OPEN" : \
		((mode) == CL_AKM_SUITE_8021X ? "8021X" : \
		((mode) == CL_AKM_SUITE_PSK ? "PSK" : \
		((mode) == CL_AKM_SUITE_FT_8021X ? "FT_8021X" : \
		((mode) == CL_AKM_SUITE_FT_PSK ? "FT_PSK" : \
		((mode) == CL_AKM_SUITE_8021X_SHA256 ? "8021X_SHA256" : \
		((mode) == CL_AKM_SUITE_PSK_SHA256 ? "PSK_SHA256" : \
		((mode) == CL_AKM_SUITE_TDLS ? "TDLS" : \
		((mode) == CL_AKM_SUITE_SAE ? "SAE" : \
		((mode) == CL_AKM_SUITE_FT_OVER_SAE ? "FT_OVER_SAE" : \
		((mode) == CL_AKM_SUITE_8021X_SUITE_B ? "8021X_SUITE_B" : \
		((mode) == CL_AKM_SUITE_8021X_SUITE_B_192 ? "8021X_SUITE_B_192" : \
		((mode) == CL_AKM_SUITE_FILS_SHA256 ? "FILS_SHA256" : \
		((mode) == CL_AKM_SUITE_FILS_SHA384 ? "FILS_SHA384" : \
		((mode) == CL_AKM_SUITE_FT_FILS_SHA256 ? "FT_FILS_SHA256" : \
		((mode) == CL_AKM_SUITE_FT_FILS_SHA384 ? "FT_FILS_SHA384" : ""))))))))))))))))

#define IS_VALID_ENCRYPT_TYPE(encrypt_type) ((encrypt_type) <= CL_CIPHER_SUITE_BIP_CMAC_256)

#define CIPHER_SUITE_LIST_OFFSET 11
#define CIPHER_SUITE_LIST_SIZE   4

/* Cipher suite selectors */
#define CL_CIPHER_SUITE_USE_GROUP    0
#define CL_CIPHER_SUITE_WEP40        1
#define CL_CIPHER_SUITE_TKIP         2
#define CL_CIPHER_SUITE_CCMP         4
#define CL_CIPHER_SUITE_WEP104       5
#define CL_CIPHER_SUITE_AES_CMAC     6
#define CL_CIPHER_SUITE_GCMP         8
#define CL_CIPHER_SUITE_GCMP_256     9
#define CL_CIPHER_SUITE_CCMP_256     10
#define CL_CIPHER_SUITE_BIP_GMAC_128 11
#define CL_CIPHER_SUITE_BIP_GMAC_256 12
#define CL_CIPHER_SUITE_BIP_CMAC_256 13
#define CL_CIPHER_SUITE_USE_NONE     14

/* AKM suite selectors */
#define CL_AKM_SUITE_OPEN              0
#define CL_AKM_SUITE_8021X             1
#define CL_AKM_SUITE_PSK               2
#define CL_AKM_SUITE_FT_8021X          3
#define CL_AKM_SUITE_FT_PSK            4
#define CL_AKM_SUITE_8021X_SHA256      5
#define CL_AKM_SUITE_PSK_SHA256        6
#define CL_AKM_SUITE_TDLS              7
#define CL_AKM_SUITE_SAE               8
#define CL_AKM_SUITE_FT_OVER_SAE       9
#define CL_AKM_SUITE_8021X_SUITE_B     11
#define CL_AKM_SUITE_8021X_SUITE_B_192 12
#define CL_AKM_SUITE_FILS_SHA256       14
#define CL_AKM_SUITE_FILS_SHA384       15
#define CL_AKM_SUITE_FT_FILS_SHA256    16
#define CL_AKM_SUITE_FT_FILS_SHA384    17

#define CL_HWQ_BK  0
#define CL_HWQ_BE  1
#define CL_HWQ_VI  2
#define CL_HWQ_VO  3
#define CL_HWQ_BCN 4

/* Traffic ID enumeration */
enum {
	TID_0,
	TID_1,
	TID_2,
	TID_3,
	TID_4,
	TID_5,
	TID_6,
	TID_7,
	TID_MAX
};

enum cl_dev_flag {
	CL_DEV_HW_RESTART,
	CL_DEV_SW_RESTART,
	CL_DEV_STOP_HW,
	CL_DEV_STARTED,
	CL_DEV_INIT,
	CL_DEV_FW_SYNC,
	CL_DEV_FW_ERROR,
	CL_DEV_REPEATER,
	CL_DEV_MESH_AP,
};

enum cl_hw_mode {
	HW_MODE_A,
	HW_MODE_B,
	HW_MODE_G,
	HW_MODE_BG,

	HW_MODE_MAX,
};

enum cl_channel_bw {
	CHNL_BW_20,
	CHNL_BW_40,
	CHNL_BW_80,
	CHNL_BW_160,

	CHNL_BW_MAX,
};

#define CHNL_BW_MAX_HE   CHNL_BW_MAX
#define CHNL_BW_MAX_VHT  CHNL_BW_MAX
#define CHNL_BW_MAX_HT   CHNL_BW_80
#define CHNL_BW_MAX_OFDM CHNL_BW_40
#define CHNL_BW_MAX_CCK  CHNL_BW_40

#define CHNL_BW_2_5 4
#define CHNL_BW_5   5
#define CHNL_BW_10  6

enum cl_reg_standard {
	CL_STANDARD_NONE,
	CL_STANDARD_FCC,
	CL_STANDARD_ETSI,
};

enum cl_wireless_mode {
	WIRELESS_MODE_LEGACY,
	WIRELESS_MODE_HT,
	WIRELESS_MODE_HT_VHT,
	WIRELESS_MODE_HT_VHT_HE,
	WIRELESS_MODE_HE
};

enum cl_ndp_tx_chains {
	NDP_TX_PHY0 = 0x1,
	NDP_TX_PHY1 = 0x2,
	NDP_TX_PHY01 = 0x3,
};

#define IS_VALID_TX_CHAINS(mask) \
	(((mask) == NDP_TX_PHY0) || \
	 ((mask) == NDP_TX_PHY1) || \
	 ((mask) == NDP_TX_PHY01))

#define Q2_TO_FREQ(x)    ((x) >> 2)
#define FREQ_TO_Q2(freq) ((freq) << 2)

/* Values of the firmware FORMATMOD fields */
enum format_mode {
	FORMATMOD_NON_HT = 0,
	FORMATMOD_NON_HT_DUP_OFDM = 1,
	FORMATMOD_HT_MF = 2,
	FORMATMOD_HT_GF = 3,
	FORMATMOD_VHT = 4,
	FORMATMOD_HE_SU = 5,
	FORMATMOD_HE_MU = 6,
	FORMATMOD_HE_EXT = 7,
	FORMATMOD_HE_TRIG = 8,
	FORMATMOD_MAX = 9
};

#define CL_MU_MAX_STA_PER_GROUP     8
#define CL_MU_MIMO_MAX_STA_PER_GRP  4
#define CL_MU_OFDMA_MAX_STA_PER_GRP 8

#define ETH_IP_ADDR_LEN 4
#define MATLAB_USER_NAME_LEN 10

/* Must be the same value as phy_rfic_common.h and phy_matlab_calib.h */
#define MAX_CALIBRATION_TYPE_NUM 11
#define BT_CALIBRATION_CHANNLES_NUM 3

#endif /* DEF_H */
