/**
 ****************************************************************************************
 *
 * @file cl6000_usb_test_wrapper.c
 *
 * @brief CL6000 UMAC Wrapper test infrastructure.
 *
 * Copyright (C) emsys 2021
 *
 ****************************************************************************************
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include "usbtpt.h"
#include "cli/cli_usb.h"

#include "reg_logger_ram.h"
#include "cl6000_usb_test.h"
#include "cl6000_usb_test_wrapper_priv.h"
#include <sys/ioctl.h>
#include <fcntl.h>

#define PDMA_COUNT (4)
#define PACKET_COUNT (2048)
#define PACKET_COUNT_SHORT (512)
#define VERSION (4)
#define TEST_TIMEOUT 400
//#define TEST_TIMEOUT 60

#ifndef USB_WRAPPER_SMAC_SCO_INT_EP_TESTS
#define USB_WRAPPER_SMAC_SCO_INT_EP_TESTS 0
#endif

#define OTHER_EP_NO 0
#define OTHER_EP_YES 1

#define TPUT_SECURITY_GAP 0.25

#define VOID_PARAM {USBW_VOID, {0, 0, 0, EMC_CELENO_AGGR_OpMode_normal}}
#define DEF_DS_PARAM {USBW_DS_AGGR_REG, {16, (8-2), 20, EMC_CELENO_AGGR_OpMode_normal}}
#define NOSPLIT_DS_PARAM4PDMA {USBW_DS_AGGR_REG, {4, (8-2), 0xFFFFFFFF, EMC_CELENO_AGGR_OpMode_no_xfer_split}}
#define NOSPLIT_DS_PARAM16PDMA {USBW_DS_AGGR_REG, {8, (8-2), 0xFFFFFFFF, EMC_CELENO_AGGR_OpMode_no_xfer_split}}
#define PAD_DS_PARAM {USBW_DS_AGGR_REG, {16, (8-2), 20, EMC_CELENO_AGGR_OpMode_pad_pdmas}}
#define BUFFERED_DS_PARAM {USBW_DS_AGGR_REG, {16, (8-2), 20, EMC_CELENO_AGGR_OpMode_buffered}}
#define BUFFERED_SPLIT_DS_PARAM {USBW_DS_AGGR_REG, {16, (8-2), 20, EMC_CELENO_AGGR_OpMode_buffered_tci_split}}

static struct USBW_TestCase testcases_lmac[] = {

    //     TC
    {    "D00-AGR-LARGE" , 1100.0, 310.0, TPUT_SECURITY_GAP, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-SMALL" ,  110.0,  50.0, TPUT_SECURITY_GAP, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*  64, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D01-AGR-LARGE" , 1100.0, 310.0, TPUT_SECURITY_GAP, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x3,  USBW_D1, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D01-AGR-SMALL" ,  110.0,  50.0, TPUT_SECURITY_GAP, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x3,  USBW_D1, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*  64, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D02-AGR-LARGE" , 1100.0, 310.0, TPUT_SECURITY_GAP, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x4,  USBW_D2, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D02-AGR-SMALL" ,  110.0,  50.0, TPUT_SECURITY_GAP, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x4,  USBW_D2, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*  64, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D03-AGR-LARGE" , 1100.0, 310.0, TPUT_SECURITY_GAP, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x5,  USBW_D3, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D03-AGR-SMALL" ,  110.0,  50.0, TPUT_SECURITY_GAP, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x5,  USBW_D3, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*  64, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D04-AGR-LARGE" , 1100.0, 310.0, TPUT_SECURITY_GAP, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x6,  USBW_D4, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D04-AGR-SMALL" ,  110.0,  50.0, TPUT_SECURITY_GAP, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x6,  USBW_D4, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*  64, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    //#11
    {    "D05-AGR-LARGE" , 1100.0, 310.0, TPUT_SECURITY_GAP, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x7,  USBW_D5, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D05-AGR-SMALL" ,  110.0,  50.0, TPUT_SECURITY_GAP, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x7,  USBW_D5, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*  64, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D06-SPK-LARGE" ,  700.0, 180.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE,  0x8,  USBW_D6, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*1600, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D07-SPK-LARGE" ,  700.0, 180.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE,  0x9,  USBW_D7, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*1600, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U00-CONT-LARGE", 1150.0, 180.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x85,  USBW_U0, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U00-CONT-SMALL",  170.0,  57.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x85,  USBW_U0, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*  64, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U05-CONT-LARGE", 1150.0, 180.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x86,  USBW_U5, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U05-CONT-SMALL",  170.0,  57.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x86,  USBW_U5, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*  64, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {"U01-SPKT-MUX-LARGE",  650.0, 170.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x82,  USBW_U1, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {"U04-SPKT-MUX-LARGE",  650.0, 170.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x82,  USBW_U4, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    //#21
    {"U09-SPKT-MUX-LARGE" ,  650.0, 170.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x82,  USBW_U9, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {"U10-SPKT-MUX-LARGE" ,  650.0, 170.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x82, USBW_U10, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {"U01-SPKT-MUX-SMALL" ,   33.0,   7.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x82,  USBW_U1, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*  64, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U02-SPKT-SMALL" ,  160.0,  47.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x83,  USBW_U2, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT* 320, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U03-SPKT-LARGE" , 1100.0, 260.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x84,  USBW_U3, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*3072, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-PDMA06" , 1300.0, 310.0, TPUT_SECURITY_GAP, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0,          6, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-PDMA08" , 1800.0, 310.0, TPUT_SECURITY_GAP, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0,          8, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-PDMA12" , 1900.0, 310.0, TPUT_SECURITY_GAP, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0,         12, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-PDMA14" , 1900.0, 310.0, TPUT_SECURITY_GAP, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0,         14, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-PDMA16" , 1900.0, 310.0, TPUT_SECURITY_GAP, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0,         16, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-PDMA16-V" , 0.0, 0.0,    TPUT_SECURITY_GAP, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0,         16, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    //#31
    {    "U00-CONT-PDMA06", 900.0,  290.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x85,  USBW_U0,          6,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U00-CONT-PDMA08", 1300.0, 270.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x85,  USBW_U0,          8,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U00-CONT-PDMA12", 2000.0, 270.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x85,  USBW_U0,         12,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U00-CONT-PDMA14", 2100.0, 270.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x85,  USBW_U0,         14,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U00-CONT-PDMA16", 2100.0, 270.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x85,  USBW_U0,         16,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U00-CONT-PDMA18", 2100.0, 290.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x85,  USBW_U0,         18,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U00-CONT-PDMA20", 2100.0, 270.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x85,  USBW_U0,         20,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U00-CONT-PDMA24", 2100.0, 290.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x85,  USBW_U0,         24,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U00-CONT-PDMA28", 2000.0, 290.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x85,  USBW_U0,         28,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U00-CONT-PDMA16-ALL-EP", 2100.0, 53.0, TPUT_SECURITY_GAP, OTHER_EP_YES, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x85,  USBW_U0,         16,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    //#41
    // corner cases
    {    "U00-CONT-3x1532",  0.0, 0.00, 0.00, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x85,  USBW_U0,          8,   USBW_UP_STREAM, {   3,    3*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U00-CONT-4x1532",  0.0, 0.00, 0.00, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x85,  USBW_U0,          8,   USBW_UP_STREAM, {   4,    4*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U00-CONT-8x1532",  0.0, 0.00, 0.00, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x85,  USBW_U0,          8,   USBW_UP_STREAM, {   8,    8*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    //#44 with data verification
    //{    "U00-CONT-2x64",    0.0, 0.00, 0.00, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x85,  USBW_U0,          8,   USBW_UP_STREAM, {   2,      2*64, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U00-CONT-V",       0.0, 0.0, 0.00, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x85,  USBW_U0, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U01-SPKT-MUX-V",   0.0, 0.0, 0.00, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x82,  USBW_U1, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U02-SPKT-V",       0.0, 0.0, 0.00, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x83,  USBW_U2, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U03-SPKT-V",       0.0, 0.0, 0.00, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x84,  USBW_U3, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U04-SPKT-MUX-V",   0.0, 0.0, 0.00, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x82,  USBW_U4, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U05-CONT-V",       0.0, 0.0, 0.00, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x86,  USBW_U5, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-V",        0.0, 0.0, 0.00, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    //#51
    {    "D01-AGR-V",        0.0, 0.0, 0.00, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x3,  USBW_D1, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D02-AGR-V",        0.0, 0.0, 0.00, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x4,  USBW_D2, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D03-AGR-V",        0.0, 0.0, 0.00, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x5,  USBW_D3, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D04-AGR-V",        0.0, 0.0, 0.00, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x6,  USBW_D4, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D05-AGR-V",        0.0, 0.0, 0.00, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x7,  USBW_D5, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D06-SPK-V" ,       0.0, 0.0, 0.00, OTHER_EP_NO, VOID_PARAM,   {VERSION, 0, USBW_IDLE,  0x8,  USBW_D6, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    
    // TRB-cache-limit scenario
    {    "D00-AGR-PDMA16-64" , 0.0, 0.0, 0.0, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0,         16, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*64, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "U00-CONT-PDMA16-64", 0.0, 0.0, 0.0, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x85,  USBW_U0,         16,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*64, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},

    {    "D00-AGR-NOSPLIT-64-V",   0.0, 0.0, 0.00, OTHER_EP_NO, NOSPLIT_DS_PARAM4PDMA, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*64, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-NOSPLIT-1532-V", 0.0, 0.0, 0.00, OTHER_EP_NO, NOSPLIT_DS_PARAM4PDMA, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-NOSPLIT-64",     0.0, 0.0, 0.00, OTHER_EP_NO, NOSPLIT_DS_PARAM4PDMA, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*64  , USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-NOSPLIT-1532",   0.0, 0.0, 0.00, OTHER_EP_NO, NOSPLIT_DS_PARAM4PDMA, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-NOSPLIT-1532-PMDA16",   0.0, 0.0, 0.00, OTHER_EP_NO, NOSPLIT_DS_PARAM16PDMA, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, 16, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-NOSPLIT-1532-PMDA16-V",   0.0, 0.0, 0.00, OTHER_EP_NO, NOSPLIT_DS_PARAM16PDMA, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, 16, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},

    {    "D00-AGR-PAD-64-V",        0.0, 0.0, 0.00, OTHER_EP_NO, PAD_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*64, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-PAD-1532-V",      0.0, 0.0, 0.00, OTHER_EP_NO, PAD_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-PAD-64",          0.0, 0.0, 0.00, OTHER_EP_NO, PAD_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*64  , USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-PAD-PDMA4-1532",  0.0, 0.0, 0.00, OTHER_EP_NO, PAD_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, 4, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-PAD-PDMA6-1532",  0.0, 0.0, 0.00, OTHER_EP_NO, PAD_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, 6, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-PAD-PDMA8-1532",  0.0, 0.0, 0.00, OTHER_EP_NO, PAD_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, 8, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-PAD-PDMA16-1532", 0.0, 0.0, 0.00, OTHER_EP_NO, PAD_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, 16, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},

#if 0
    {    "D00-AGR-BUF-PDMA4-64",      0.0, 0.0, 0.00, OTHER_EP_NO, BUFFERED_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, 4, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*64  , USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-BUF-PDMA16-64-V",   0.0, 0.0, 0.00, OTHER_EP_NO, BUFFERED_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, 16, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*64, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-BUF-PDMA4-1532",    0.0, 0.0, 0.00, OTHER_EP_NO, BUFFERED_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, 4, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-BUF-PDMA16-1532",   0.0, 0.0, 0.00, OTHER_EP_NO, BUFFERED_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, 16, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-BUF-PDMA16-1532-V", 0.0, 0.0, 0.00, OTHER_EP_NO, BUFFERED_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, 16, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
#if 0
    {    "D00-AGR-BUF-SPLIT-PDMA4-64",      0.0, 0.0, 0.00, OTHER_EP_NO, BUFFERED_SPLIT_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, 4, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*64  , USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-BUF-SPLIT-PDMA16-64-V",   0.0, 0.0, 0.00, OTHER_EP_NO, BUFFERED_SPLIT_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, 16, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*64, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-BUF-SPLIT-PDMA4-1532",    0.0, 0.0, 0.00, OTHER_EP_NO, BUFFERED_SPLIT_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, 4, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-BUF-SPLIT-PDMA16-1532",   0.0, 0.0, 0.00, OTHER_EP_NO, BUFFERED_SPLIT_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, 16, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {    "D00-AGR-BUF-SPLIT-PDMA16-1532-V", 0.0, 0.0, 0.00, OTHER_EP_NO, BUFFERED_SPLIT_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  USBW_D0, 16, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*1532, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
#endif
#endif
    };

static struct USBW_TestCase testcases_smac[] = {
    { "U08-BT-INTR"    ,  0.0, 0.0, 0.00, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x87, USBW_U8, PDMA_COUNT,   USBW_UP_STREAM, {          16,           16*  64, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    { "D10-BT-HCI"     ,  0.0, 0.0, 0.00,  OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE,  0x0, USBW_D10,         1, USBW_DOWN_STREAM, {          16,           16*  64, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    { "D08-BT-BULK-128",  0.0, 0.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x0A, USBW_D8, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT* 128, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    { "D08-BT-BULK-32" ,  0.0, 0.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x0A, USBW_D8, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*  32, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    { "U06-BT-BULK-128",  0.0, 0.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x88, USBW_U6, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT* 128, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    { "U06-BT-BULK-32" ,  0.0, 0.0, TPUT_SECURITY_GAP, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x88, USBW_U6, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT_SHORT, PACKET_COUNT_SHORT*  32, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
#if USB_WRAPPER_SMAC_SCO_INT_EP_TESTS
    { "U07-BT-SCO-INT",  0.0, 0.0, 0.00, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x89,  USBW_U7,          1, USBW_UP_STREAM,   {         16,          16*  60, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    { "U07-BT-SCO-INT",  0.0, 0.0, 0.00, OTHER_EP_NO, VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x0B,  USBW_D9,          1, USBW_DOWN_STREAM, {         16,          16*  60, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
#endif
    };

static size_t number_testcases_lmac = sizeof(testcases_lmac) / sizeof(testcases_lmac[0]);
static size_t number_testcases_smac = sizeof(testcases_smac) / sizeof(testcases_smac[0]);
static uint32_t test_control_seq = 0;

static const char* usbw_lmac_fw_name = NULL;
static const char* usbw_smac_fw_name = NULL;


uint32_t number_testcases()
{
  if (is_lmac_running()){
    return number_testcases_lmac;
  }

  if (is_smac_running()){
    return number_testcases_smac;
  }

  return 0;
}

struct USBW_TestCase* testcases()
{
  if (is_lmac_running()){
    return testcases_lmac;
  }
  if (is_smac_running()){
    return testcases_smac;
  }

  return NULL;
}

uint32_t usb_wrapper_test_evaluate(uint32_t statusbase, struct USBW_TestCase* tc,struct tpt_statistics* host_stat, CL_USB_SPEED speed)
{
    uint32_t test_status;
    uint32_t test_result;
    int result = FAILED;
    struct USBW_TestControlRequest* req = &(tc->control_request);
    cl_usb_read32(statusbase + WRAPPER_TEST_STATUS_STATE_OFFSET, &test_status);
    cl_usb_read32(statusbase + WRAPPER_TEST_STATUS_RESULT, &test_result);

    if (test_status == USBW_STATUS_FINISHED) {
        uint32_t duration;
        cl_usb_read32(statusbase + WRAPPER_TEST_STATUS_EXEC_TIME, &duration);
        double payload = req->packets.number_bytes * 8.0 / (1024*1024);
        if(tc->control_request.direction == USBW_LOOP) {
          payload *=2;
        }
        double dt_s = duration / 1000.0;
        if (tc->control_request.version>=4){
          // Version >=4  duration in µs
          dt_s /= 1000.0;
        }
        double tput = payload / dt_s;
        double tput_min_mbps = (speed==CL_USB_SPEED_SUPER)? tc->tput_min_mbps_ss:tc->tput_min_mbps_hs;
        double tput_min = tput_min_mbps * (1 - tc->tput_eps);
        if (tput_min_mbps > 0.0f) {
          TEST_INFO("\n        duration: %u us throughput: %.2lf MBit/s (gap abs=%.2lf MBit/s eps=%.3lf)", duration, tput, tput - tput_min, (tput - tput_min) / tput);
        } else {
          TEST_INFO("\n        duration: %u us throughput: %.2lf MBit/s", duration, tput);
        }
        result = PASSED;
        if ((tput_min_mbps > 0.0f) && (tput < tput_min)) {
            TEST_INFO("\n***     tput.min violation: current %.1lf - threshold %.1f [%.1lf-eps]", tput, tput_min, tput_min_mbps);
            result = boot_drv_usb_cfg()->test_perf_as_error ? FAILED : WARN;
        }

        if(test_result != USBW_OK ){
          TEST_INFO("\n***     test result : %u",test_result);
          result = FAILED;
        }

        if(tc->control_request.packets.pattern != USBW_DONT_CARE  && tc->control_request.direction == USBW_UP_STREAM ) {
            if (host_stat && host_stat->content_error > 0) {
              TEST_INFO("\n***     content error");
              result = FAILED;
            }
        }
    }
    switch (result) {
      case  PASSED:
          TEST_INFO("\n        PASS");
          break;
       case WARN:
          TEST_INFO("\n        WARNING");
          break;
        default:
          TEST_INFO("\n***     FAILED");
          break;
    }
    return result;
}

static const char* wrapper_test_info(struct USBW_TestCase* tc, size_t index, size_t max_index, CL_USB_SPEED speed) {
  static char line[256];
  struct USBW_TestControlRequest* req = &(tc->control_request);

  float tput_min_mbps = (speed==CL_USB_SPEED_SUPER)? tc->tput_min_mbps_ss:tc->tput_min_mbps_hs;
  float tput_min = tput_min_mbps * (1 - tc->tput_eps);

  char channel_name[16];
  snprintf(channel_name, sizeof(channel_name), "%c%u", (req->direction==USBW_UP_STREAM) ? 'U' : 'D', req->lli_channel);
  char payload_desc[16];
  snprintf(payload_desc, sizeof(payload_desc), "%s-%ux%u", req->direction==USBW_UP_STREAM ? "US" : "DS", req->packets.packet_count, req->packets.number_bytes / req->packets.packet_count);
  char pdma_desc[16];
  snprintf(pdma_desc, sizeof(pdma_desc), "#PDMA=%02d", req->number_pdma);

  if (tput_min != 0.0) {
  snprintf(line, sizeof(line), "TC %2d/%d %s : LLI %3s EP:%02X %8s %8s %14s bytes, expected tput[eps] %6.1f MBit/s [%.3f => exp. >%6.1f MBit/s]",
        (unsigned int)index+1, (unsigned int)max_index, tc->description, channel_name, req->ep, pdma_desc,
        tc->description, payload_desc, tput_min_mbps, tc->tput_eps, tput_min);
  } else {
    snprintf(line, sizeof(line), "TC %2d/%d %s : LLI %3s EP:%02X %8s %8s %14s bytes",
        (unsigned int)index+1, (unsigned int)max_index, tc->description, channel_name, req->ep, pdma_desc, tc->description, payload_desc);
  }
  return line;
}

void usb_wrapper_test_list() {
  struct USBW_TestCase* tc = 0;
  TEST_INFO("\nUMAC USB Wrapper Tests LMAC:");
  for(uint32_t tc_index = 0; tc_index < number_testcases_lmac; tc_index++) {
    tc = &testcases_lmac[tc_index];
    TEST_INFO("\n    %s", wrapper_test_info(tc, tc_index, number_testcases_lmac, CL_USB_SPEED_SUPER));
  }
  TEST_INFO("\n");
  TEST_INFO("\nUMAC USB Wrapper Tests SMAC:");
  for(uint32_t tc_index = 0; tc_index < number_testcases_smac; tc_index++) {
    tc = &testcases_smac[tc_index];
    TEST_INFO("\n    %s", wrapper_test_info(tc, tc_index, number_testcases_smac, CL_USB_SPEED_SUPER));
  }
  TEST_INFO("\n");
}


EMC_CELENO_DOWNSTREAM_AGGR_Param default_ds_param = {};
EMC_CELENO_DOWNSTREAM_AGGR_Param current_ds_param[16] = {};


static int usb_wrapper_need_wifi_reset(struct USBW_TestCase* tc)
{
  if(tc->control_request.direction == USBW_DOWN_STREAM) {
    if (tc->param.type == USBW_DS_AGGR_REG ) {
        if (memcmp(tc->param.param, &current_ds_param[tc->control_request.lli_channel], sizeof(EMC_CELENO_DOWNSTREAM_AGGR_Param))){
          return 1;
        }
    }
  }
  return 0;
}

static int usb_wrapper_test_single(size_t tc_index, size_t tc_run, size_t max_tc_index,CL_USB_SPEED speed) {
  int result = FAILED;
  int fd_driver = 0;
  struct USBW_TestCase* tc = &testcases()[tc_index];
  struct USBW_TestControlRequest* req = &(tc->control_request);
  struct tpt_statistics host_stat;
  TEST_INFO("\n    %s", wrapper_test_info(tc, tc_run, max_tc_index, speed));
  if(usb_wrapper_need_wifi_reset(tc)) {
    TEST_INFO("\n        Test requires reset (DS-AGGR paramter different)\n");
    fd_driver=usb_test_open_driver(req);
    if (fd_driver < 0){
      return FAILED;
    }
    if(tc->control_request.direction == USBW_DOWN_STREAM && tc->param.type == USBW_DS_AGGR_REG) {
      write_umac_ds_register(ds_agg_addr(tc->control_request.lli_channel),(EMC_CELENO_DOWNSTREAM_AGGR_Param*)&tc->param.param[0]);
      usb_print_aggr_regs(ds_agg_addr(tc->control_request.lli_channel), tc->control_request.lli_channel);
      memcpy(&current_ds_param[tc->control_request.lli_channel],tc->param.param,sizeof(EMC_CELENO_DOWNSTREAM_AGGR_Param));
    }
    usbw_reset_wifi(fd_driver);

    if (load_start_lmac_smac(usbw_lmac_fw_name, usbw_smac_fw_name)!= 0) {
      return FAILED;
    }
  }

  int no_sg = 0;
  if (req->direction == USBW_DOWN_STREAM) {
    no_sg = ((req->packets.number_bytes / req->packets.packet_count) < 256) ? 1 : 0;
  }

  host_stat.content_error = -1;
  req->sequence_id = test_control_seq++;

  // start_host_app
  usb_wrapper_test_write_request(req);

  if((fd_driver = usb_wrapper_test_start_host_driver(tc, no_sg)) < 0){
      return FAILED;
  }

  cl_usb_write32(test_control_base_addr() + WRAPPER_TEST_CONTROL_REQUEST_OFFSET, USBW_START);
  cl_usb_write32(test_control_base_addr() + WRAPPER_TEST_CONTROL_SEQ_ID_OFFSET, test_control_seq);

  if (!usb_wrapper_test_wait_finished(fd_driver, TEST_TIMEOUT)) {
    return FAILED;
  }

  if(tc->control_request.direction == USBW_UP_STREAM) {
    if(!usb_wrapper_test_wait_host_received_all_data(fd_driver, &tc->control_request, 10)){
      TEST_INFO("\n*** Data not received on host side!\n");
      usb_wrapper_test_stop(fd_driver, &host_stat);
      return FAILED;
    }
  }
  if( !usb_wrapper_test_stop(fd_driver,&host_stat)){
      TEST_INFO("\n*** Could not stop running test! Aborted!\n");
      return FAILED;
  }

  result = usb_wrapper_test_evaluate(test_status_base_addr(),tc,&host_stat, speed);

  return result;
}

static void usb_wrapper_show_statistics(size_t tc_index)
{
  struct USBW_TestCase* tc = &testcases()[tc_index];

  EMC_USB_CELENO_Statistics stats;
  if (usb_read_umac_wifi_statistic(&stats)!=0){
    return;
  }
  usb_print_umac_wifi_statistic_lli (&stats, tc->control_request.lli_channel,(tc->control_request.direction==USBW_UP_STREAM)? 1:0);
}

static int testcase_index(const char* tag) {
    for(uint32_t tc_index = 0; tc_index < number_testcases(); tc_index++) {
      if (strcmp(tag,testcases()[tc_index].description) == 0){
        return tc_index;
      }
    }
    return -1;
}

typedef struct test_results_s {
  uint32_t passed;
  uint32_t passed_with_warning;
  uint32_t failed;
} test_results_t;

static void add_result(test_results_t* results ,TEST_RESULT result){
  switch (result) {
    case PASSED: results->passed++; break;
    case WARN: results->passed_with_warning++; break;
    default : results->failed++; break;
  }
}

int apre_usb_wrapper_test(const char* lmac_fw_name, const char* smac_fw_name)
{
  test_results_t results={0,0,0};
  TEST_RESULT current = 0;
  CL_USB_SPEED speed=CL_USB_SPEED_UNDEFINED;
  if (usb_test_restart_reconnect_umac() != 0) {
    TEST_INFO("\n*** Reconnect failed");
    return FAILED;
  }

  usbw_lmac_fw_name = lmac_fw_name;
  usbw_smac_fw_name = smac_fw_name;

  if (load_start_lmac_smac(usbw_lmac_fw_name,usbw_smac_fw_name)!= 0) {
    return FAILED;
  }

  for(int ds_lli=0;ds_lli<=5;ds_lli++){
    read_umac_ds_register(ds_agg_addr(ds_lli),&current_ds_param[ds_lli]);
  }

  if(usb_test_check_driver_loaded() != 0 ){
    TEST_INFO("\n*** host driver not loaded!\n");
    return FAILED;
  }
  speed = cl_usb_get_speed();
  if (speed == CL_USB_SPEED_HIGH) {
    TEST_INFO("\nUSB Highspeed device detected , using highspeed values\n\n");
  }

  if(usb_test_tags > 0) {
      TEST_INFO("\nTests to run : %u (of %u available)\n", (unsigned int)usb_test_tags, number_testcases());
      for(int i = 0; i < usb_test_tags; i++){
        int tc_index = testcase_index(usb_tc_tags[i].tag);
        if(tc_index < 0) {
          TEST_INFO("\nUnknown test tag %s\n", usb_tc_tags[i].tag);
          return FAILED;
        }
        if(usb_tc_tags[i].override_perf_limit != 0.0 ){
          testcases()[tc_index].tput_min_mbps_hs = usb_tc_tags[i].override_perf_limit;
          testcases()[tc_index].tput_min_mbps_ss = usb_tc_tags[i].override_perf_limit;
        }
        current = usb_wrapper_test_single(tc_index, i, usb_test_tags,speed);
        add_result(&results,current);
      }
  } else {
    if (boot_drv_usb_cfg()->test_selected == -1) {
      uint32_t tc_count = number_testcases();
      TEST_INFO("\nTests to run : %u\n", tc_count);
      for(uint32_t tc_index = 0; tc_index < tc_count; tc_index++) {
        current = usb_wrapper_test_single(tc_index,tc_index,number_testcases(),speed);
        add_result(&results,current);
      }
    } else {
      if (boot_drv_usb_cfg()->test_selected >= number_testcases()) {
        TEST_INFO("\nFAILED: testindex out-of-range %d of [1..%d]\n", (unsigned int)(boot_drv_usb_cfg()->test_selected + 1),number_testcases());
          return FAILED;
        }

        TEST_INFO("\nTest case %d selected (number available testcases: %u)\n", boot_drv_usb_cfg()->test_selected + 1, number_testcases());
        current = usb_wrapper_test_single(boot_drv_usb_cfg()->test_selected,boot_drv_usb_cfg()->test_selected,number_testcases(),speed);
        add_result(&results,current);
        usb_wrapper_show_statistics(boot_drv_usb_cfg()->test_selected);
    }
  }
  TEST_INFO("\n");
  if (results.failed > 0 ){
    TEST_INFO("\nFAILED USBW tests : %u failed of %u\n\n", results.failed, results.failed+results.passed_with_warning+results.passed);
    return FAILED;
  }else{
    if (results.passed_with_warning) {
      TEST_INFO("\nPASSED USBW tests (%u)\n", results.passed);
      TEST_INFO("\n       ***  test with warnings:%u\n\n", results.passed_with_warning);
    }else{
    TEST_INFO("\nPASSED USBW tests (%u)\n\n", results.passed);
    }
    return PASSED;
  }
}
