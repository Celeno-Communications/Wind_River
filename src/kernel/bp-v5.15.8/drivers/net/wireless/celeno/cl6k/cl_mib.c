// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_mib.h"
#include "reg_access.h"

#define NUM_OF_MIB_COUNTERS 254
#define MIB_REG_OFFSET 0x800

static void init_mib_counter_arr(char *mib_counter_names_arr[NUM_OF_MIB_COUNTERS])
{
	/*
	 * MIB element to count the number of unencrypted frames that have been
	 * discarded
	 */
	mib_counter_names_arr[0] = "dot11_wep_excluded_count";

	/* MIB element to count the receive FCS errors */
	mib_counter_names_arr[1] = "dot11_fcs_error_count";
	/*
	 * MIB element to count the number of PHY Errors reported during a
	 * receive transaction.
	 */
	mib_counter_names_arr[2] = "nx_rx_phy_error_count";
	/*
	 * MIB element to count the number of times the receive FIFO has
	 * overflowed
	 */
	mib_counter_names_arr[3] = "nx_rx_Discard_RHD";
	/*
	 * MIB element to count the number of times underrun has occurred on the
	 * transmit side
	 */
	mib_counter_names_arr[4] = "nx_tx_underrun_count";

	/* MIB element to count unicast transmitted MPDU */
	mib_counter_names_arr[5] = "nx_qos_utransmitted_mpdu_count[0]";
	mib_counter_names_arr[6] = "nx_qos_utransmitted_mpdu_count[1]";
	mib_counter_names_arr[7] = "nx_qos_utransmitted_mpdu_count[2]";
	mib_counter_names_arr[8] = "nx_qos_utransmitted_mpdu_count[3]";
	mib_counter_names_arr[9] = "nx_qos_utransmitted_mpdu_count[4]";
	mib_counter_names_arr[10] = "nx_qos_utransmitted_mpdu_count[5]";
	mib_counter_names_arr[11] = "nx_qos_utransmitted_mpdu_count[6]";
	mib_counter_names_arr[12] = "nx_qos_utransmitted_mpdu_count[7]";
	/* MIB element to count group addressed transmitted MPDU */
	mib_counter_names_arr[13] = "nx_qos_gtransmitted_mpdu_count[0]";
	mib_counter_names_arr[14] = "nx_qos_gtransmitted_mpdu_count[1]";
	mib_counter_names_arr[15] = "nx_qos_gtransmitted_mpdu_count[2]";
	mib_counter_names_arr[16] = "nx_qos_gtransmitted_mpdu_count[3]";
	mib_counter_names_arr[17] = "nx_qos_gtransmitted_mpdu_count[4]";
	mib_counter_names_arr[18] = "nx_qos_gtransmitted_mpdu_count[5]";
	mib_counter_names_arr[19] = "nx_qos_gtransmitted_mpdu_count[6]";
	mib_counter_names_arr[20] = "nx_qos_gtransmitted_mpdu_count[7]";
	/*
	 * MIB element to count the number of MSDUs or MMPDUs discarded
	 * because of retry-limit reached
	 */
	mib_counter_names_arr[21] = "dot11_qos_failed_count[0]";
	mib_counter_names_arr[22] = "dot11_qos_failed_count[1]";
	mib_counter_names_arr[23] = "dot11_qos_failed_count[2]";
	mib_counter_names_arr[24] = "dot11_qos_failed_count[3]";
	mib_counter_names_arr[25] = "dot11_qos_failed_count[4]";
	mib_counter_names_arr[26] = "dot11_qos_failed_count[5]";
	mib_counter_names_arr[27] = "dot11_qos_failed_count[6]";
	mib_counter_names_arr[28] = "dot11_qos_failed_count[7]";
	/*
	 * MIB element to count number of unfragmented MSDU's or MMPDU's
	 * transmitted successfully after 1 or more transmission
	 */
	mib_counter_names_arr[29] = "dot11_qos_retry_count[0]";
	mib_counter_names_arr[30] = "dot11_qos_retry_count[1]";
	mib_counter_names_arr[31] = "dot11_qos_retry_count[2]";
	mib_counter_names_arr[32] = "dot11_qos_retry_count[3]";
	mib_counter_names_arr[33] = "dot11_qos_retry_count[4]";
	mib_counter_names_arr[34] = "dot11_qos_retry_count[5]";
	mib_counter_names_arr[35] = "dot11_qos_retry_count[6]";
	mib_counter_names_arr[36] = "dot11_qos_retry_count[7]";
	/* MIB element to count number of successful RTS Frame transmission */
	mib_counter_names_arr[37] = "dot11_qos_rts_success_count[0]";
	mib_counter_names_arr[38] = "dot11_qos_rts_success_count[1]";
	mib_counter_names_arr[39] = "dot11_qos_rts_success_count[2]";
	mib_counter_names_arr[40] = "dot11_qos_rts_success_count[3]";
	mib_counter_names_arr[41] = "dot11_qos_rts_success_count[4]";
	mib_counter_names_arr[42] = "dot11_qos_rts_success_count[5]";
	mib_counter_names_arr[43] = "dot11_qos_rts_success_count[6]";
	mib_counter_names_arr[44] = "dot11_qos_rts_success_count[7]";
	/* MIB element to count number of unsuccessful RTS Frame transmission */
	mib_counter_names_arr[45] = "dot11_qos_rts_failure_count[0]";
	mib_counter_names_arr[46] = "dot11_qos_rts_failure_count[1]";
	mib_counter_names_arr[47] = "dot11_qos_rts_failure_count[2]";
	mib_counter_names_arr[48] = "dot11_qos_rts_failure_count[3]";
	mib_counter_names_arr[49] = "dot11_qos_rts_failure_count[4]";
	mib_counter_names_arr[50] = "dot11_qos_rts_failure_count[5]";
	mib_counter_names_arr[51] = "dot11_qos_rts_failure_count[6]";
	mib_counter_names_arr[52] = "dot11_qos_rts_failure_count[7]";
	/* MIB element to count number of MPDU's not received ACK */
	mib_counter_names_arr[53] = "nx_qos_ack_failure_count[0]";
	mib_counter_names_arr[54] = "nx_qos_ack_failure_count[1]";
	mib_counter_names_arr[55] = "nx_qos_ack_failure_count[2]";
	mib_counter_names_arr[56] = "nx_qos_ack_failure_count[3]";
	mib_counter_names_arr[57] = "nx_qos_ack_failure_count[4]";
	mib_counter_names_arr[58] = "nx_qos_ack_failure_count[5]";
	mib_counter_names_arr[59] = "nx_qos_ack_failure_count[6]";
	mib_counter_names_arr[60] = "nx_qos_ack_failure_count[7]";
	/* MIB element to count number of unicast MPDU's received successfully */
	mib_counter_names_arr[61] = "nx_qos_ureceived_mpdu_count[0]";
	mib_counter_names_arr[62] = "nx_qos_ureceived_mpdu_count[1]";
	mib_counter_names_arr[63] = "nx_qos_ureceived_mpdu_count[2]";
	mib_counter_names_arr[64] = "nx_qos_ureceived_mpdu_count[3]";
	mib_counter_names_arr[65] = "nx_qos_ureceived_mpdu_count[4]";
	mib_counter_names_arr[66] = "nx_qos_ureceived_mpdu_count[5]";
	mib_counter_names_arr[67] = "nx_qos_ureceived_mpdu_count[6]";
	mib_counter_names_arr[68] = "nx_qos_ureceived_mpdu_count[7]";
	/*
	 * MIB element to count number of group addressed MPDU's received
	 * successfully
	 */
	mib_counter_names_arr[69] = "nx_qos_greceived_mpdu_count[0]";
	mib_counter_names_arr[70] = "nx_qos_greceived_mpdu_count[1]";
	mib_counter_names_arr[71] = "nx_qos_greceived_mpdu_count[2]";
	mib_counter_names_arr[72] = "nx_qos_greceived_mpdu_count[3]";
	mib_counter_names_arr[73] = "nx_qos_greceived_mpdu_count[4]";
	mib_counter_names_arr[74] = "nx_qos_greceived_mpdu_count[5]";
	mib_counter_names_arr[75] = "nx_qos_greceived_mpdu_count[6]";
	mib_counter_names_arr[76] = "nx_qos_greceived_mpdu_count[7]";
	/*
	 * MIB element to count the number of unicast MPDUs not destined to
	 * this device received successfully.
	 */
	mib_counter_names_arr[77] = "nx_qos_ureceived_other_mpdu[0]";
	mib_counter_names_arr[78] = "nx_qos_ureceived_other_mpdu[1]";
	mib_counter_names_arr[79] = "nx_qos_ureceived_other_mpdu[2]";
	mib_counter_names_arr[80] = "nx_qos_ureceived_other_mpdu[3]";
	mib_counter_names_arr[81] = "nx_qos_ureceived_other_mpdu[4]";
	mib_counter_names_arr[82] = "nx_qos_ureceived_other_mpdu[5]";
	mib_counter_names_arr[83] = "nx_qos_ureceived_other_mpdu[6]";
	mib_counter_names_arr[84] = "nx_qos_ureceived_other_mpdu[7]";
	/*
	 * MIB element to count the number of MPDUs received with retry bit
	 * set
	 */
	mib_counter_names_arr[85] = "dot11_qos_retries_received_count[0]";
	mib_counter_names_arr[86] = "dot11_qos_retries_received_count[1]";
	mib_counter_names_arr[87] = "dot11_qos_retries_received_count[2]";
	mib_counter_names_arr[88] = "dot11_qos_retries_received_count[3]";
	mib_counter_names_arr[89] = "dot11_qos_retries_received_count[4]";
	mib_counter_names_arr[90] = "dot11_qos_retries_received_count[5]";
	mib_counter_names_arr[91] = "dot11_qos_retries_received_count[6]";
	mib_counter_names_arr[92] = "dot11_qos_retries_received_count[7]";
	/*
	 * MIB element to count the number of unicast A-MSDUs that were
	 * transmitted successfully
	 */
	mib_counter_names_arr[93] = "nx_utransmitted_amsdu_count[0]";
	mib_counter_names_arr[94] = "nx_utransmitted_amsdu_count[1]";
	mib_counter_names_arr[95] = "nx_utransmitted_amsdu_count[2]";
	mib_counter_names_arr[96] = "nx_utransmitted_amsdu_count[3]";
	mib_counter_names_arr[97] = "nx_utransmitted_amsdu_count[4]";
	mib_counter_names_arr[98] = "nx_utransmitted_amsdu_count[5]";
	mib_counter_names_arr[99] = "nx_utransmitted_amsdu_count[6]";
	mib_counter_names_arr[100] = "nx_utransmitted_amsdu_count[7]";
	/*
	 * MIB element to count the number of group-addressed A-MSDUs that were
	 * transmitted successfully
	 */
	mib_counter_names_arr[101] = "nx_gtransmitted_amsdu_count[0]";
	mib_counter_names_arr[102] = "nx_gtransmitted_amsdu_count[1]";
	mib_counter_names_arr[103] = "nx_gtransmitted_amsdu_count[2]";
	mib_counter_names_arr[104] = "nx_gtransmitted_amsdu_count[3]";
	mib_counter_names_arr[105] = "nx_gtransmitted_amsdu_count[4]";
	mib_counter_names_arr[106] = "nx_gtransmitted_amsdu_count[5]";
	mib_counter_names_arr[107] = "nx_gtransmitted_amsdu_count[6]";
	mib_counter_names_arr[108] = "nx_gtransmitted_amsdu_count[7]";
	/*
	 * MIB element to count number of AMSDU's discarded because of retry
	 * limit reached
	 */
	mib_counter_names_arr[109] = "dot11_failed_amsdu_count[0]";
	mib_counter_names_arr[110] = "dot11_failed_amsdu_count[1]";
	mib_counter_names_arr[111] = "dot11_failed_amsdu_count[2]";
	mib_counter_names_arr[112] = "dot11_failed_amsdu_count[3]";
	mib_counter_names_arr[113] = "dot11_failed_amsdu_count[4]";
	mib_counter_names_arr[114] = "dot11_failed_amsdu_count[5]";
	mib_counter_names_arr[115] = "dot11_failed_amsdu_count[6]";
	mib_counter_names_arr[116] = "dot11_failed_amsdu_count[7]";
	/*
	 * MIB element to count number of A-MSDU's transmitted successfully
	 * with retry
	 */
	mib_counter_names_arr[117] = "dot11_retry_amsdu_count[0]";
	mib_counter_names_arr[118] = "dot11_retry_amsdu_count[1]";
	mib_counter_names_arr[119] = "dot11_retry_amsdu_count[2]";
	mib_counter_names_arr[120] = "dot11_retry_amsdu_count[3]";
	mib_counter_names_arr[121] = "dot11_retry_amsdu_count[4]";
	mib_counter_names_arr[122] = "dot11_retry_amsdu_count[5]";
	mib_counter_names_arr[123] = "dot11_retry_amsdu_count[6]";
	mib_counter_names_arr[124] = "dot11_retry_amsdu_count[7]";
	/*
	 * MIB element to count number of bytes of an A-MSDU that was
	 * transmitted successfully
	 */
	mib_counter_names_arr[125] = "dot11_transmitted_octets_in_amsdu[0]";
	mib_counter_names_arr[126] = "dot11_transmitted_octets_in_amsdu[1]";
	mib_counter_names_arr[127] = "dot11_transmitted_octets_in_amsdu[2]";
	mib_counter_names_arr[128] = "dot11_transmitted_octets_in_amsdu[3]";
	mib_counter_names_arr[129] = "dot11_transmitted_octets_in_amsdu[4]";
	mib_counter_names_arr[130] = "dot11_transmitted_octets_in_amsdu[5]";
	mib_counter_names_arr[131] = "dot11_transmitted_octets_in_amsdu[6]";
	mib_counter_names_arr[132] = "dot11_transmitted_octets_in_amsdu[7]";
	/*
	 * MIB element to counts the number of A-MSDUs that did not receive an
	 * ACK frame successfully in response
	 */
	mib_counter_names_arr[133] = "dot11_amsdu_ack_failure_count[0]";
	mib_counter_names_arr[134] = "dot11_amsdu_ack_failure_count[1]";
	mib_counter_names_arr[135] = "dot11_amsdu_ack_failure_count[2]";
	mib_counter_names_arr[136] = "dot11_amsdu_ack_failure_count[3]";
	mib_counter_names_arr[137] = "dot11_amsdu_ack_failure_count[4]";
	mib_counter_names_arr[138] = "dot11_amsdu_ack_failure_count[5]";
	mib_counter_names_arr[139] = "dot11_amsdu_ack_failure_count[6]";
	mib_counter_names_arr[140] = "dot11_amsdu_ack_failure_count[7]";
	/*
	 * MIB element to count number of unicast A-MSDUs received
	 * successfully
	 */
	mib_counter_names_arr[141] = "nx_ureceived_amsdu_count[0]";
	mib_counter_names_arr[142] = "nx_ureceived_amsdu_count[1]";
	mib_counter_names_arr[143] = "nx_ureceived_amsdu_count[2]";
	mib_counter_names_arr[144] = "nx_ureceived_amsdu_count[3]";
	mib_counter_names_arr[145] = "nx_ureceived_amsdu_count[4]";
	mib_counter_names_arr[146] = "nx_ureceived_amsdu_count[5]";
	mib_counter_names_arr[147] = "nx_ureceived_amsdu_count[6]";
	mib_counter_names_arr[148] = "nx_ureceived_amsdu_count[7]";
	/*
	 * MIB element to count number of group addressed A-MSDUs received
	 * successfully
	 */
	mib_counter_names_arr[149] = "nx_greceived_amsdu_count[0]";
	mib_counter_names_arr[150] = "nx_greceived_amsdu_count[1]";
	mib_counter_names_arr[151] = "nx_greceived_amsdu_count[2]";
	mib_counter_names_arr[152] = "nx_greceived_amsdu_count[3]";
	mib_counter_names_arr[153] = "nx_greceived_amsdu_count[4]";
	mib_counter_names_arr[154] = "nx_greceived_amsdu_count[5]";
	mib_counter_names_arr[155] = "nx_greceived_amsdu_count[6]";
	mib_counter_names_arr[156] = "nx_greceived_amsdu_count[7]";
	/*
	 * MIB element to count number of unicast A-MSDUs not destined to
	 * this device received successfully
	 */
	mib_counter_names_arr[157] = "nx_ureceived_other_amsdu[0]";
	mib_counter_names_arr[158] = "nx_ureceived_other_amsdu[1]";
	mib_counter_names_arr[159] = "nx_ureceived_other_amsdu[2]";
	mib_counter_names_arr[160] = "nx_ureceived_other_amsdu[3]";
	mib_counter_names_arr[161] = "nx_ureceived_other_amsdu[4]";
	mib_counter_names_arr[162] = "nx_ureceived_other_amsdu[5]";
	mib_counter_names_arr[163] = "nx_ureceived_other_amsdu[6]";
	mib_counter_names_arr[164] = "nx_ureceived_other_amsdu[7]";
	/* MIB element to count number of bytes in an A-MSDU is received */
	mib_counter_names_arr[165] = "dot11_received_octets_in_amsdu_count[0]";
	mib_counter_names_arr[166] = "dot11_received_octets_in_amsdu_count[1]";
	mib_counter_names_arr[167] = "dot11_received_octets_in_amsdu_count[2]";
	mib_counter_names_arr[168] = "dot11_received_octets_in_amsdu_count[3]";
	mib_counter_names_arr[169] = "dot11_received_octets_in_amsdu_count[4]";
	mib_counter_names_arr[170] = "dot11_received_octets_in_amsdu_count[5]";
	mib_counter_names_arr[171] = "dot11_received_octets_in_amsdu_count[6]";
	mib_counter_names_arr[172] = "dot11_received_octets_in_amsdu_count[7]";
	/* Reserved */
	mib_counter_names_arr[173] = "reserved";
	mib_counter_names_arr[174] = "reserved";
	mib_counter_names_arr[175] = "reserved";

	mib_counter_names_arr[176] = "dot11_beamforming_frame_count";
	mib_counter_names_arr[177] = "beamforming_received_frame_count";
	mib_counter_names_arr[178] = "su_bfr_transmitted_count";
	mib_counter_names_arr[179] = "mu_bfr_transmitted_count";
	mib_counter_names_arr[180] = "bfr_received_count";
	mib_counter_names_arr[181] = "mu_received_frame_count";
	mib_counter_names_arr[182] = "respSetByFW";
	mib_counter_names_arr[183] = "respForcedByFW";
	mib_counter_names_arr[184] = "respForcedByHW";
	mib_counter_names_arr[185] = "respForcedByHW";
	mib_counter_names_arr[186] = "rxUnexpectedFrameTypeInAmpdu";
	mib_counter_names_arr[187] = "rxMultiTid";
	mib_counter_names_arr[188] = "ksrMissQosDataInAmpdu";
	mib_counter_names_arr[189] = "ksrMissMultiTid";
	mib_counter_names_arr[190] = "ksrMissQosDataInAmpduHeTB";
	mib_counter_names_arr[191] = "rxUnassociatedMgmtInHeTB";
	mib_counter_names_arr[192] = "HtpFailedMeduimCheckCount";
	mib_counter_names_arr[193] = "mibRxErrorVector[0]";
	mib_counter_names_arr[194] = "mibRxErrorVector[1]";
	mib_counter_names_arr[195] = "mibRxErrorVector[2]";
	mib_counter_names_arr[196] = "mibRxErrorVector[3]";
	mib_counter_names_arr[197] = "mibRxErrorVector[4]";
	mib_counter_names_arr[198] = "mibRxErrorVector[5]";
	mib_counter_names_arr[199] = "mibRxErrorVector[6]";
	mib_counter_names_arr[200] = "mibRxErrorVector[7]";
	mib_counter_names_arr[201] = "mibRxErrorVector[8]";
	mib_counter_names_arr[202] = "mibRxErrorVector[9]";
	mib_counter_names_arr[203] = "mibRxErrorVector[10]";

	/* MIB element to count number of A-MPDUs transmitted successfully */
	mib_counter_names_arr[204] = "dot11_transmitted_ampdu_count";
	/* MIB element to count number of MPDUs transmitted in an A-MPDU */
	mib_counter_names_arr[205] = "dot11_transmitted_mpdus_in_ampdu_count";
	/* MIB element to count the number of bytes in a transmitted A-MPDU */
	mib_counter_names_arr[206] = "dot11_transmitted_octets_in_ampdu_count";
	/* MIB element to count number of unicast A-MPDU's received */
	mib_counter_names_arr[207] = "wnlu_ampdu_received_count";
	/* MIB element to count number of group addressed A-MPDU's received */
	mib_counter_names_arr[208] = "nx_gampdu_received_count";
	/*
	 * MIB element to count number of unicast A-MPDUs received not destined
	 * to this device
	 */
	mib_counter_names_arr[209] = "nx_other_ampdu_received_count";
	/* MIB element to count number of MPDUs received in an A-MPDU */
	mib_counter_names_arr[210] = "dot11_mpdu_in_received_ampdu_count";
	/* MIB element to count number of bytes received in an A-MPDU */
	mib_counter_names_arr[211] = "dot11_received_octets_in_ampdu_count";
	/* MIB element to count number of CRC errors in MPDU delimeter of and A-MPDU */
	mib_counter_names_arr[212] = "dot11_ampdu_delimiter_crc_error_count";
	/*
	 * MIB element to count number of implicit BAR frames that did not received
	 * BA frame successfully in response
	 */
	mib_counter_names_arr[213] = "dot11_implicit_bar_failure_count";
	/*
	 * MIB element to count number of explicit BAR frames that did not received
	 * BA frame successfully in response
	 */
	mib_counter_names_arr[214] = "dot11_explicit_bar_failure_count";
	mib_counter_names_arr[215] = "mibRxErrorVector[11]";
	mib_counter_names_arr[216] = "mibRxErrorVector[12]";
	mib_counter_names_arr[217] = "mibRxErrorVector[13]";
	mib_counter_names_arr[218] = "mibRxErrorVector[14]";
	mib_counter_names_arr[219] = "mibRxErrorVector[15]";
	/* MIB element to count the number of frames transmitted at 20 MHz BW */
	mib_counter_names_arr[220] = "dot11_20mhz_frame_transmitted_count";
	/* MIB element to count the number of frames transmitted at 40 MHz BW */
	mib_counter_names_arr[221] = "dot11_40mhz_frame_transmitted_count";
	mib_counter_names_arr[222] = "dot11_80mhz_frame_transmitted_count";
	mib_counter_names_arr[223] = "dot11_160mhz_frame_transmitted_count";
	/* MIB element to count the number of frames received at 20 MHz BW */
	mib_counter_names_arr[224] = "dot11_20mhz_frame_received_count";
	/* MIB element to count the number of frames received at 40 MHz BW */
	mib_counter_names_arr[225] = "dot11_40mhz_frame_received_count";
	mib_counter_names_arr[226] = "dot11_80mhz_frame_received_count";
	mib_counter_names_arr[227] = "dot11_160mhz_frame_received_count";
	/* MIB element to count the number of attempts made to acquire a 40 MHz TXOP */
	mib_counter_names_arr[228] = "nx_failed_20mhz_txop";
	mib_counter_names_arr[229] = "nx_succsessful_20mhz_txop";

	mib_counter_names_arr[230] = "nx_failed_40mhz_txop";
	mib_counter_names_arr[231] = "nx_succsessful_40mhz_txop";

	mib_counter_names_arr[232] = "nx_failed_80mhz_txop";
	mib_counter_names_arr[233] = "nx_succsessful_80mhz_txop";

	mib_counter_names_arr[234] = "nx_failed_160mhz_txop";
	mib_counter_names_arr[235] = "nx_succsessful_160mhz_txop";

	mib_counter_names_arr[236] = "dynamic_bw_drop_count";
	mib_counter_names_arr[237] = "static_bw_failed_count";

	/* Reserved */
	mib_counter_names_arr[238] = "reserved";
	mib_counter_names_arr[239] = "reserved";

	/* MIB element to count the number of times the dual CTS fails */
	mib_counter_names_arr[240] = "dot11_dualcts_success_count";
	/*
	 * MIB element to count the number of times the AP does not detect a collision
	 * PIFS after transmitting a STBC CTS frame
	 */
	mib_counter_names_arr[241] = "dot11_stbc_cts_success_count";
	/*
	 * MIB element to count the number of times the AP detects a collision PIFS after
	 * transmitting a STBC CTS frame
	 */
	mib_counter_names_arr[242] = "dot11_stbc_cts_failure_count";
	/*
	 * MIB element to count the number of times the AP does not detect a collision PIFS
	 * after transmitting a non-STBC CTS frame
	 */
	mib_counter_names_arr[243] = "dot11_non_stbc_cts_success_count";
	/*
	 * MIB element to count the number of times the AP detects a collision PIFS after
	 * transmitting a non-STBC CTS frame
	 */
	mib_counter_names_arr[244] = "dot11_non_stbc_cts_failure_count";
	mib_counter_names_arr[245] = "dot11_txund_discard_fcs_count";
	mib_counter_names_arr[246] = "dot11_rx_ampdu_incorrect_received_count";
	mib_counter_names_arr[247] = "cl_rx_class_match_count[0]";
	mib_counter_names_arr[248] = "cl_rx_class_match_count[1]";
	mib_counter_names_arr[249] = "cl_rx_class_match_count[2]";
	mib_counter_names_arr[250] = "cl_rx_class_match_count[3]";
	mib_counter_names_arr[251] = "cl_rx_class_match_count[4]";
	mib_counter_names_arr[252] = "cl_rx_class_match_count[5]";
	mib_counter_names_arr[253] = "dot11_rx_mpif_overflow_count";
}

void cl_mib_cntrs_dump(struct cl_hw *cl_hw)
{
	static char *mib_counter_names_arr[NUM_OF_MIB_COUNTERS];
	int i = 0;
	u32 mib_reg_addr = 0;
	u32 mib_reg_val = 0;

	init_mib_counter_arr(mib_counter_names_arr);

	pr_debug("------------------------------------------------------------\n");
	pr_debug("Counter                                   Address  Value\n");
	pr_debug("------------------------------------------------------------\n");

	for (i = 0; i < NUM_OF_MIB_COUNTERS; i++) {
		/* Reserved registers */
		if (i == 173 || i == 174 || i == 175 || i == 238 || i == 239)
			continue;

		mib_reg_addr = MIB_REG_OFFSET + (i * 4);
		mib_reg_val = cl_mib_cntr_read(cl_hw, mib_reg_addr);

		if (mib_reg_val == 0)
			continue;

		pr_debug("%-40s  0x%X    %u\n",
			 mib_counter_names_arr[i], mib_reg_addr, mib_reg_val);
	}

	pr_debug("------------------------------------------------------------\n");
}

u32 cl_mib_cntr_read(struct cl_hw *cl_hw, u32 addr)
{
	return cl_reg_read(cl_hw->chip, REG_MAC_HW_BASE_ADDR + addr);
}

