/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CALIB_DB_H
#define CALIB_DB_H

#include "def.h"

#define MAX_SX					2
#define DCOC_LNA_GAIN_NUM		16
#define BT_DCOC_LNA_GAIN_NUM	2
#define MAX_NUM_BT_CHANNELS_CALIB 3
#define NUM_OF_BT_CHANNELS		79
#define FILE_PREFIX_DCOC				"cl_dcoc_chip"
#define FILE_PREFIX_BT_DCOC				"cl_bt_dcoc_chip"
#define FILE_PREFIX_DCOC_REPORT			"cl_dcoc_report_chip"
#define FILE_PREFIX_BT_DCOC_REPORT		"cl_bt_dcoc_report_chip"
#define FILE_PREFIX_LOLC				"cl_lolc_chip"
#define FILE_PREFIX_LOLC_REPORT			"cl_lolc_report_chip"
#define FILE_PREFIX_IQ_TX				"cl_iq_tx_chip"
#define FILE_PREFIX_IQ_TX_REPORT		"cl_iq_tx_report_chip"
#define FILE_PREFIX_IQ_RX				"cl_iq_rx_chip"
#define FILE_PREFIX_IQ_RX_REPORT		"cl_iq_rx_report_chip"
#define FILE_PREFIX_RX_GAIN_REPORT		"cl_rx_gain_report_chip"
#define FILE_PREFIX_CALIB_IQ_PLAN		"cl_calib_iq_plan_chip"
#define FILE_PREFIX_MATLAB_CALIB_REQ	"cl_matlab_calib_req"
#define FILE_PREFIX_MATLAB_CALIB_RES	"cl_matlab_calib_res"

#define FILE_TCV_HEADER    "# TCV = %hhu, Number of Antennas = %hhu\n"
#define FILE_TCV_SX_HEADER "# TCV = %hhu, SX = %hhu, Number of Antennas = %hhu\n"
#define FILE_TCV_FOOTER    "# End of TCV = %hhu, Number of Antennas = %hhu\n"
#define FILE_HR_FACTOR     "# HR factor = %s\n"
#define FILE_VERSION_ID    "# Version ID = %u\n"

#define FILE_TITLE_DCOC           "#<Channel>\t<BW>\t<Chain>\t<Band>\t<LNA>\t<Temp.>\t<I>\t<Q>\n"
#define FILE_TITLE_DCOC_REPORT    \
	"#<Channel>\t<BW>\t<Chain>\t<Band>\t<LNA>\t<Temp.>\t<I DC>\t<Iitr>\t<Q DC>\t<Qitr>\n"
#define FILE_TITLE_LOLC           "#<Channel>\t<BW>\t<Ant.>\t<Band>\t<Temp.>\t<I>\t<Q>\n"
#define FILE_TITLE_LOLC_REPORT    "#<Channel>\t<BW>\t<Ant.>\t<Band>\t<Temp.>\t<Itr.>\t<Qual>\n"
#define FILE_TITLE_IQ             \
	"#<Channel>\t<BW>\t<Ant.>\t<Band>\t<Temp.>\t<coef0>\t\t<coef1>\t\t<coef2>\t\t<gain>\n"
#define FILE_TITLE_IQ_REPORT      \
	"#calib_type,Channel,BW,Ant,Band,Temp,Tone #1,Tone #2,Tone #3,Tone #4" \
	",Tone #5,Tone #6,Tone #7,Tone #8,Tone #9,Tone #10,Tone #11" \
	",Tone #12,Tone #13,Tone #14,Tone #15,Tone #16,Tone AVG\n"
#define FILE_TITLE_RX_GAIN_REPORT \
	"#<Channel>,\t<BW>,\t<tx_ant>,\t<rx_ant>,\t<Init rx_gain>,\t<tx_gain>,\t<Init P2P>," \
	"\t<Final rx_gain>,\t<Final P2P>\n"
#define FILE_TITLE_SCORE_IQ \
	"#<Channel>\t<BW>\t<Ant.>\t<Band>\t<Tx_score>\t<Tx_worse>\t<Rx_score>\t<Rx_worse>\n"
#define FILE_TITLE_SCORE_LOLC \
	"#<Channel>\t<BW>\t<Ant.>\t<Band>\tLOLC_score>\n"
#define FILE_TITLE_SCORE_DCOC \
	"#<Channel>\t<BW>\t<Ant.>\t<Lna.>\t<Band>\t<I_MV>\t<Q_MV>\n"

#define MATLAB_UMH_SCRIPT \
	"scripts/Matlab_calib/cl_umh_matlab.sh"

enum calib_channel_idx_24g {
	CALIB_CHAN_24G_1,
	CALIB_CHAN_24G_6,
	CALIB_CHAN_24G_11,
	CALIB_CHAN_24G_MAX,
};

enum calib_channel_idx_5g {
	CALIB_CHAN_5G_36,
	CALIB_CHAN_5G_40,
	CALIB_CHAN_5G_44,
	CALIB_CHAN_5G_48,
	CALIB_CHAN_5G_52,
	CALIB_CHAN_5G_56,
	CALIB_CHAN_5G_60,
	CALIB_CHAN_5G_64,
	CALIB_CHAN_5G_100,
	CALIB_CHAN_5G_104,
	CALIB_CHAN_5G_108,
	CALIB_CHAN_5G_112,
	CALIB_CHAN_5G_116,
	CALIB_CHAN_5G_120,
	CALIB_CHAN_5G_124,
	CALIB_CHAN_5G_128,
	CALIB_CHAN_5G_132,
	CALIB_CHAN_5G_136,
	CALIB_CHAN_5G_140,
	CALIB_CHAN_5G_144,
	CALIB_CHAN_5G_149,
	CALIB_CHAN_5G_153,
	CALIB_CHAN_5G_157,
	CALIB_CHAN_5G_161,
	CALIB_CHAN_5G_165,
	CALIB_CHAN_5G_MAX
};

enum calib_channel_idx_6g {
	CALIB_CHAN_6G_1,
	CALIB_CHAN_6G_5,
	CALIB_CHAN_6G_9,
	CALIB_CHAN_6G_13,
	CALIB_CHAN_6G_17,
	CALIB_CHAN_6G_21,
	CALIB_CHAN_6G_25,
	CALIB_CHAN_6G_29,
	CALIB_CHAN_6G_33,
	CALIB_CHAN_6G_37,
	CALIB_CHAN_6G_41,
	CALIB_CHAN_6G_45,
	CALIB_CHAN_6G_49,
	CALIB_CHAN_6G_53,
	CALIB_CHAN_6G_57,
	CALIB_CHAN_6G_61,
	CALIB_CHAN_6G_65,
	CALIB_CHAN_6G_69,
	CALIB_CHAN_6G_73,
	CALIB_CHAN_6G_77,
	CALIB_CHAN_6G_81,
	CALIB_CHAN_6G_85,
	CALIB_CHAN_6G_89,
	CALIB_CHAN_6G_93,
	CALIB_CHAN_6G_97,
	CALIB_CHAN_6G_101,
	CALIB_CHAN_6G_105,
	CALIB_CHAN_6G_109,
	CALIB_CHAN_6G_113,
	CALIB_CHAN_6G_117,
	CALIB_CHAN_6G_121,
	CALIB_CHAN_6G_125,
	CALIB_CHAN_6G_129,
	CALIB_CHAN_6G_133,
	CALIB_CHAN_6G_137,
	CALIB_CHAN_6G_141,
	CALIB_CHAN_6G_145,
	CALIB_CHAN_6G_149,
	CALIB_CHAN_6G_153,
	CALIB_CHAN_6G_157,
	CALIB_CHAN_6G_161,
	CALIB_CHAN_6G_165,
	CALIB_CHAN_6G_169,
	CALIB_CHAN_6G_173,
	CALIB_CHAN_6G_177,
	CALIB_CHAN_6G_181,
	CALIB_CHAN_6G_185,
	CALIB_CHAN_6G_189,
	CALIB_CHAN_6G_193,
	CALIB_CHAN_6G_197,
	CALIB_CHAN_6G_201,
	CALIB_CHAN_6G_205,
	CALIB_CHAN_6G_209,
	CALIB_CHAN_6G_213,
	CALIB_CHAN_6G_217,
	CALIB_CHAN_6G_221,
	CALIB_CHAN_6G_225,
	CALIB_CHAN_6G_229,
	CALIB_CHAN_6G_233,
	CALIB_CHAN_6G_MAX,
};

enum bt_filter_bw {
	BT_FILTER_BW_1M,
	BT_FILTER_BW_2M,
	BT_FILTER_BW_MAX,
};

/* MAX(CALIB_CHAN_24G_MAX, CALIB_CHAN_5G_MAX, CALIB_CHAN_6G_MAX) */
#define CALIB_CHAN_MAX CALIB_CHAN_6G_MAX

struct cl_dcoc_calib {
	s8 i;
	s8 q;
};

struct cl_iq_calib {
	__le32 coef0;
	__le32 coef1;
	__le32 coef2;
	__le32 gain;
};

struct cl_calib_errors {
	u16 dcoc;
	u16 lolc;
	u16 iq_tx;
	u16 iq_rx;
};

struct cl_calib_file_flags {
	u8 dcoc;
	u8 bt_dcoc;
	u8 dcoc_report;
	u8 bt_dcoc_report;
	u8 lolc;
	u8 lolc_report;
	u8 iq_tx;
	u8 iq_tx_report;
	u8 iq_rx;
	u8 iq_rx_report;
	u8 rx_gain_report;
	bool iq_plan;
};

#endif
