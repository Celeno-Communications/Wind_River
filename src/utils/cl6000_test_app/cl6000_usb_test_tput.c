/**
 ****************************************************************************************
 *
 * @file cl6000_usb_test_tput.c
 *
 * @brief CL6000 UMAC TPut test infrastructure.
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

#include "reg_logger_ram.h"
#include "cl6000_usb_test.h"
#include "cl6000_usb_test_tput_priv.h"
#include <sys/ioctl.h>
#include <fcntl.h>

#define TEST_MIN_IN_PACKETS      40 // to ensure, that we transfer at minimum that amount of packets, checked on host side
#define TEST_MIN_OUT_COMPLETIONS  2 // to ensure, that we transfer at minimum 2 large buffers, checked on host side
#define TEST_TIMEOUT_SEC         60 // ... but abort latest after this timeout

#if 1
#define TEST_TIME                     5.0
#define US_LARGE_PERF              2215.0,300.0
#define US_UPPER_LARGE_PERF        1700.0,300.0
#define US_SMALL_PERF               120.0,50.0
#define DS_LARGE_PERF              1500.0,320.0
#define DS_SMALL_PERF               120.0,100.0
#define NO_PERF                       0.0,0.0
#else /// imx limited bandwith
#define TEST_TIME                     5.0
#define US_LARGE_PERF                 0.0
#define US_UPPER_LARGE_PERF           0.0
#define US_SMALL_PERF                 0.0
#define DS_LARGE_PERF                 0.0
#define DS_SMALL_PERF                 0.0
#define NO_PERF                       0.0
#endif

static struct USBTP_TestCase testcases[] = {
    {     "DS-LARGE-B2", DS_LARGE_PERF,  TEST_TIME, EP2_OUT, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "DS-SMALL-B2", DS_SMALL_PERF,  TEST_TIME, EP2_OUT, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "US-LARGE-B2", US_LARGE_PERF,  TEST_TIME, EP2_IN, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "US-SMALL-B2", US_SMALL_PERF,  TEST_TIME, EP2_IN, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "DS-LARGE-V-B2",       NO_PERF,  TEST_TIME, EP2_OUT, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-B2",       NO_PERF,  TEST_TIME, EP2_OUT, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "US-LARGE-V-B2",       NO_PERF,  TEST_TIME, EP2_IN, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-B2",       NO_PERF,  TEST_TIME, EP2_IN, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-I2",       NO_PERF,  TEST_TIME, EP2_OUT, INT, SMALL_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-I2",       NO_PERF,  TEST_TIME, EP2_IN, INT, SMALL_PACKETS, CHECK_DATA},
#if 1
    {     "DS-LARGE-B3", DS_LARGE_PERF,  TEST_TIME, EP3_OUT, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "DS-SMALL-B3", DS_SMALL_PERF,  TEST_TIME, EP3_OUT, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "US-LARGE-B3", US_LARGE_PERF,  TEST_TIME, EP3_IN, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "US-SMALL-B3", US_SMALL_PERF,  TEST_TIME, EP3_IN, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "DS-LARGE-V-B3",       NO_PERF,  TEST_TIME, EP3_OUT, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-B3",       NO_PERF,  TEST_TIME, EP3_OUT, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "US-LARGE-V-B3",       NO_PERF,  TEST_TIME, EP3_IN, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-B3",       NO_PERF,  TEST_TIME, EP3_IN, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-I3",       NO_PERF,  TEST_TIME, EP3_OUT, INT, SMALL_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-I3",       NO_PERF,  TEST_TIME, EP3_IN, INT, SMALL_PACKETS, CHECK_DATA},


    {     "DS-LARGE-B4", DS_LARGE_PERF,  TEST_TIME, EP4_OUT, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "DS-SMALL-B4", DS_SMALL_PERF,  TEST_TIME, EP4_OUT, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "US-LARGE-B4", US_LARGE_PERF,  TEST_TIME, EP4_IN, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "US-SMALL-B4", US_SMALL_PERF,  TEST_TIME, EP4_IN, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "DS-LARGE-V-B4",       NO_PERF,  TEST_TIME, EP4_OUT, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-B4",       NO_PERF,  TEST_TIME, EP4_OUT, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "US-LARGE-V-B4",       NO_PERF,  TEST_TIME, EP4_IN, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-B4",       NO_PERF,  TEST_TIME, EP4_IN, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-I4",       NO_PERF,  TEST_TIME, EP4_OUT, INT, SMALL_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-I4",       NO_PERF,  TEST_TIME, EP4_IN, INT, SMALL_PACKETS, CHECK_DATA},


    {     "DS-LARGE-B5", DS_LARGE_PERF,  TEST_TIME, EP5_OUT, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "DS-SMALL-B5", DS_SMALL_PERF,  TEST_TIME, EP5_OUT, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "US-LARGE-B5", US_LARGE_PERF,  TEST_TIME, EP5_IN, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "US-SMALL-B5", US_SMALL_PERF,  TEST_TIME, EP5_IN, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "DS-LARGE-V-B5",       NO_PERF,  TEST_TIME, EP5_OUT, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-B5",       NO_PERF,  TEST_TIME, EP5_OUT, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "US-LARGE-V-B5",       NO_PERF,  TEST_TIME, EP5_IN, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-B5",       NO_PERF,  TEST_TIME, EP5_IN, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-I5",       NO_PERF,  TEST_TIME, EP5_OUT, INT, SMALL_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-I5",      NO_PERF,  TEST_TIME, EP5_IN, INT, SMALL_PACKETS, CHECK_DATA},


    {     "DS-LARGE-B6", DS_LARGE_PERF,  TEST_TIME, EP6_OUT, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "DS-SMALL-B6", DS_SMALL_PERF,  TEST_TIME, EP6_OUT, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "US-LARGE-B6", US_LARGE_PERF,  TEST_TIME, EP6_IN, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "US-SMALL-B6", US_SMALL_PERF,  TEST_TIME, EP6_IN, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "DS-LARGE-V-B6",       NO_PERF,  TEST_TIME, EP6_OUT, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-B6",       NO_PERF,  TEST_TIME, EP6_OUT, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "US-LARGE-V-B6",       NO_PERF,  TEST_TIME, EP6_IN, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-B6",       NO_PERF,  TEST_TIME, EP6_IN, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-I6",       NO_PERF,  TEST_TIME, EP6_OUT, INT, SMALL_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-I6",       NO_PERF,  TEST_TIME, EP6_IN, INT, SMALL_PACKETS, CHECK_DATA},


    {     "DS-LARGE-B7", DS_LARGE_PERF,  TEST_TIME, EP7_OUT, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "DS-SMALL-B7", DS_SMALL_PERF,  TEST_TIME, EP7_OUT, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "US-LARGE-B7", US_LARGE_PERF,  TEST_TIME, EP7_IN, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "US-SMALL-B7", US_SMALL_PERF,  TEST_TIME, EP7_IN, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "DS-LARGE-V-B7",       NO_PERF,  TEST_TIME, EP7_OUT, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-B7",       NO_PERF,  TEST_TIME, EP7_OUT, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "US-LARGE-V-B7",       NO_PERF,  TEST_TIME, EP7_IN, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-B7",       NO_PERF,  TEST_TIME, EP7_IN, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-I7",       NO_PERF,  TEST_TIME, EP7_OUT, INT, SMALL_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-I7",       NO_PERF,  TEST_TIME, EP7_IN, INT, SMALL_PACKETS, CHECK_DATA},


    {     "DS-LARGE-B8", DS_LARGE_PERF,  TEST_TIME, EP8_OUT, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "DS-SMALL-B8", DS_SMALL_PERF,  TEST_TIME, EP8_OUT, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "US-LARGE-B8", US_LARGE_PERF,  TEST_TIME, EP8_IN, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "US-SMALL-B8", US_SMALL_PERF,  TEST_TIME, EP8_IN, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "DS-LARGE-V-B8",       NO_PERF,  TEST_TIME, EP8_OUT, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-B8",       NO_PERF,  TEST_TIME, EP8_OUT, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "US-LARGE-V-B8",       NO_PERF,  TEST_TIME, EP8_IN, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-B8",       NO_PERF,  TEST_TIME, EP8_IN, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-I8",       NO_PERF,  TEST_TIME, EP8_OUT, INT, SMALL_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-I8",       NO_PERF,  TEST_TIME, EP8_IN, INT, SMALL_PACKETS, CHECK_DATA},


    {     "DS-LARGE-B9", DS_LARGE_PERF,  TEST_TIME, EP9_OUT, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "DS-SMALL-B9", DS_SMALL_PERF,  TEST_TIME, EP9_OUT, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "US-LARGE-B9", US_UPPER_LARGE_PERF,  TEST_TIME, EP9_IN, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "US-SMALL-B9", US_SMALL_PERF,  TEST_TIME, EP9_IN, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "DS-LARGE-V-B9",       NO_PERF,  TEST_TIME, EP9_OUT, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-B9",       NO_PERF,  TEST_TIME, EP9_OUT, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "US-LARGE-V-B9",       NO_PERF,  TEST_TIME, EP9_IN, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-B9",       NO_PERF,  TEST_TIME, EP9_IN, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-I9",       NO_PERF,  TEST_TIME, EP9_OUT, INT, SMALL_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-I9",       NO_PERF,  TEST_TIME, EP9_IN, INT, SMALL_PACKETS, CHECK_DATA},


    {     "DS-LARGE-B10", DS_LARGE_PERF,  TEST_TIME, EP10_OUT, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "DS-SMALL-B10", DS_SMALL_PERF,  TEST_TIME, EP10_OUT, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "US-LARGE-B10", US_UPPER_LARGE_PERF,  TEST_TIME, EP10_IN, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "US-SMALL-B10", US_SMALL_PERF,  TEST_TIME, EP10_IN, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "DS-LARGE-V-B10",       NO_PERF,  TEST_TIME, EP10_OUT, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-B10",       NO_PERF,  TEST_TIME, EP10_OUT, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "US-LARGE-V-B10",       NO_PERF,  TEST_TIME, EP10_IN, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-B10",       NO_PERF,  TEST_TIME, EP10_IN, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-I10",       NO_PERF,  TEST_TIME, EP10_OUT, INT, SMALL_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-I10",       NO_PERF,  TEST_TIME, EP10_IN, INT, SMALL_PACKETS, CHECK_DATA},


    {     "DS-LARGE-B11", DS_LARGE_PERF,  TEST_TIME, EP11_OUT, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "DS-SMALL-B11", DS_SMALL_PERF,  TEST_TIME, EP11_OUT, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "US-LARGE-B11", US_UPPER_LARGE_PERF,  TEST_TIME, EP11_IN, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "US-SMALL-B11", US_SMALL_PERF,  TEST_TIME, EP11_IN, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "DS-LARGE-V-B11",       NO_PERF,  TEST_TIME, EP11_OUT, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-B11",       NO_PERF,  TEST_TIME, EP11_OUT, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "US-LARGE-V-B11",       NO_PERF,  TEST_TIME, EP11_IN, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-B11",       NO_PERF,  TEST_TIME, EP11_IN, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-I11",       NO_PERF,  TEST_TIME, EP11_OUT, INT, SMALL_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-I11",       NO_PERF,  TEST_TIME, EP11_IN, INT, SMALL_PACKETS, CHECK_DATA},

    {     "DS-LARGE-B12", DS_LARGE_PERF,  TEST_TIME, EP12_OUT, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "DS-SMALL-B12", DS_SMALL_PERF,  TEST_TIME, EP12_OUT, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "US-LARGE-B12", US_UPPER_LARGE_PERF,  TEST_TIME, EP12_IN, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "US-SMALL-B12", US_SMALL_PERF,  TEST_TIME, EP12_IN, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "DS-LARGE-V-B12",       NO_PERF,  TEST_TIME, EP12_OUT, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-B12",       NO_PERF,  TEST_TIME, EP12_OUT, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "US-LARGE-V-B12",       NO_PERF,  TEST_TIME, EP12_IN, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-B12",       NO_PERF,  TEST_TIME, EP12_IN, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-I12",       NO_PERF,  TEST_TIME, EP12_OUT, INT, SMALL_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-I12",       NO_PERF,  TEST_TIME, EP12_IN, INT, SMALL_PACKETS, CHECK_DATA},


    {     "DS-LARGE-B13", DS_LARGE_PERF,  TEST_TIME, EP13_OUT, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "DS-SMALL-B13", DS_SMALL_PERF,  TEST_TIME, EP13_OUT, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "US-LARGE-B13", US_UPPER_LARGE_PERF,  TEST_TIME, EP13_IN, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "US-SMALL-B13", US_SMALL_PERF,  TEST_TIME, EP13_IN, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "DS-LARGE-V-B13",       NO_PERF,  TEST_TIME, EP13_OUT, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-B13",       NO_PERF,  TEST_TIME, EP13_OUT, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "US-LARGE-V-B13",       NO_PERF,  TEST_TIME, EP13_IN, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-B13",       NO_PERF,  TEST_TIME, EP13_IN, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-I13",       NO_PERF,  TEST_TIME, EP13_OUT, INT, SMALL_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-I13",       NO_PERF,  TEST_TIME, EP13_IN, INT, SMALL_PACKETS, CHECK_DATA},


    {     "DS-LARGE-B14", DS_LARGE_PERF,  TEST_TIME, EP14_OUT, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "DS-SMALL-B14", DS_SMALL_PERF,  TEST_TIME, EP14_OUT, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "US-LARGE-B14", US_UPPER_LARGE_PERF,  TEST_TIME, EP14_IN, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "US-SMALL-B14", US_SMALL_PERF,  TEST_TIME, EP14_IN, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "DS-LARGE-V-B14",       NO_PERF,  TEST_TIME, EP14_OUT, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-B14",       NO_PERF,  TEST_TIME, EP14_OUT, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "US-LARGE-V-B14",       NO_PERF,  TEST_TIME, EP14_IN, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-B14",       NO_PERF,  TEST_TIME, EP14_IN, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-I14",       NO_PERF,  TEST_TIME, EP14_OUT, INT, SMALL_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-I14",       NO_PERF,  TEST_TIME, EP14_IN, INT, SMALL_PACKETS, CHECK_DATA},


    {     "DS-LARGE-B15", DS_LARGE_PERF,  TEST_TIME, EP15_OUT, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "DS-SMALL-B15", DS_SMALL_PERF,  TEST_TIME, EP15_OUT, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "US-LARGE-B15", US_UPPER_LARGE_PERF,  TEST_TIME, EP15_IN, BULK, LARGE_PACKETS, NO_DATA_CHECK},
    {     "US-SMALL-B15", US_SMALL_PERF,  TEST_TIME, EP15_IN, BULK, SMALL_PACKETS, NO_DATA_CHECK},
    {     "DS-LARGE-V-B15",       NO_PERF,  TEST_TIME, EP15_OUT, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-B15",       NO_PERF,  TEST_TIME, EP15_OUT, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "US-LARGE-V-B15",       NO_PERF,  TEST_TIME, EP15_IN, BULK, LARGE_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-B15",       NO_PERF,  TEST_TIME, EP15_IN, BULK, SMALL_PACKETS, CHECK_DATA},
    {     "DS-SMALL-V-I15",       NO_PERF,  TEST_TIME, EP15_OUT, INT, SMALL_PACKETS, CHECK_DATA},
    {     "US-SMALL-V-I15",       NO_PERF,  TEST_TIME, EP15_IN, INT, SMALL_PACKETS, CHECK_DATA},
#endif
};

static uint32_t failed_tests_content = 0;
static uint32_t failed_tests_xfer = 0;
static uint32_t failed_tests_perf = 0;


static size_t number_testcases = sizeof(testcases) / sizeof(testcases[0]);


const char* ep_as_string(enum USBTP_EP ep) {
  static char line[16];
  snprintf(line, sizeof(line), "EP%u_%s", (ep & 0xf) , (ep & 0x80) ? "IN":"OUT");
  return line;
}

unsigned char ep_is_in(enum USBTP_EP ep) {
  return ((ep & 0x80) != 0) ? 1 : 0;
}

static const char* tput_test_info(struct USBTP_TestCase* tc, size_t tc_run, size_t max_tc_index, CL_USB_SPEED speed) {
  static char line[256];

  char expected_line[64];
  double tput_min_mbps = (speed==CL_USB_SPEED_SUPER)? tc->tput_min_mbps_ss:tc->tput_min_mbps_hs;
  if (tput_min_mbps > 0.0) {
    snprintf(expected_line, sizeof(expected_line), ", expected %6.1f MBit/s", tput_min_mbps);
  } else {
    snprintf(expected_line, sizeof(expected_line), " ");
  }
  snprintf(line, sizeof(line), "TC %2d/%d %s %-8s %4s %s %13s %4.1f sec%s",
      (unsigned int)tc_run+1, (unsigned int)max_tc_index, tc->description, ep_as_string(tc->ep), transfer_mode_as_string(tc->transfer_mode),
      payload_size_as_string(tc->payload_size),check_data_as_string(tc->check_data), tc->duration, expected_line);
  return line;
}

void usb_tput_test_list() {
  TEST_INFO("\nUMAC USB TPut Tests:");
  for(uint32_t tc_index = 0; tc_index < number_testcases; tc_index++) {
    TEST_INFO("\n    %s", tput_test_info(&testcases[tc_index], tc_index, number_testcases, CL_USB_SPEED_SUPER));
  }
  TEST_INFO("\n");
}

static void print_driver_parameter(struct tpt_parameter* param, struct tpt_start* start) {
  TEST_INFO("\n    -> iep=0x%02x oep=0x%02x chunk_sz=%d chunk_cnt=%d pkts=%d bc=%d %s",
      param->in_ep, param->out_ep, param->chunk_size, param->chunk_count,
      param->packets_to_transfer, param->buffer_count, param->verify_content ? "CHECK_DATA" : "NO_DATA_CHECK");
  TEST_INFO(" m=%d rt=%.1fsec rawpkts=%d", start->mode , start->runtime * 1.0f, start->raw_packets);
}

static int usb_tput_test_start_host_driver(struct USBTP_TestCase* tc)
{
    int fd;
    struct tpt_start start_param = {
        .mode = (tc->payload_size == SMALL_PACKETS) ? 1 : 0,
        .alt_setting = (tc->transfer_mode==BULK) ? 0 : 1,
        .runtime = tc->duration,
        .raw_packets = 0};
    struct tpt_parameter param = {
      .in_ep = ep_is_out(tc->ep) ? 0 : tc->ep,
      .out_ep = ep_is_out(tc->ep) ? tc->ep : 0,
      .chunk_size = 1600,
      .chunk_count = 16,
      .packets_to_transfer = 0,
      .buffer_count = 4,
      .verify_content = (tc->check_data == CHECK_DATA) ? 1 : 0,
      .flags = 0};

    if (ep_is_out(tc->ep)) {
      if (tc->payload_size == LARGE_PACKETS) {
        param.chunk_size = 1532;
      } else {
        param.chunk_size = 64;
        param.flags |= TPT_PARAM_FLAG_NO_SG;
      }
    }


    fd = open("/dev/usbtpt0", O_RDWR);
    if (fd < 0) {
        TEST_INFO("\n*** error open driver: %s, code %d\n", strerror(-fd), fd);
        return fd;
    }

    if (boot_drv_usb_cfg()->verbose) {
      print_driver_parameter(&param, &start_param);
    }
    usb_test_driver_call_ioctl(fd, TPT_SET_PARAMETER, &param);
    usb_test_driver_call_ioctl(fd, TPT_START, &start_param);
    fflush(stdout);
    return fd;
}

static void print_driver_statistic(struct tpt_statistics* statistic) {
  TEST_INFO("\n    <- usb_err=%d runtime=%.3fms data_bytes=%lld usb_pkts=%lld ",
            statistic->usb_error, (statistic->runtime * 1.0f) / 1e6,
            (long long int)statistic->payload_data, (long long int)statistic->packets_transferred);
  TEST_INFO("buf_subm=%lld buf_cmpl=%lld d_errs=%lld xfer_errs=%lld last_urb_err=%d",
            (long long int)statistic->out_buffers_submitted, (long long int)statistic->out_buffers_completed,
            (long long int)statistic->content_error, (long long int)statistic->transfer_error, statistic->last_urb_error);
}


static void print_device_statistic(struct tpt_device_statistic* statistic) {
  TEST_INFO("\n    Results  bytes: %u packets: %u time: %.3lf ms content-error: %u xfer-error: %u",
            statistic->bytes,statistic->packets,((double)statistic->runtime_us/1e3),statistic->content_error,
            statistic->transfer_error);
}



int usb_tput_test_evaluate(int fd, struct USBTP_TestCase* tc,struct tpt_device_statistic* dev_stat, CL_USB_SPEED speed) {
  struct tpt_statistics* host_stats = usb_test_driver_statistic();
  double tp;
  char* error_cause="";
  if (boot_drv_usb_cfg()->verbose || host_stats->content_error!=0 || host_stats->transfer_error!=0) {
    print_driver_statistic(host_stats) ;
  }
  print_device_statistic(dev_stat);

  tp=dev_stat->bytes * 8.0 / ((double)dev_stat->runtime_us / 1e6);
  tp/=1e6;

  double tput_min_mbps = (speed==CL_USB_SPEED_SUPER)? tc->tput_min_mbps_ss:tc->tput_min_mbps_hs;

  if (tput_min_mbps > 0.0) {
    TEST_INFO("\n    Bandwidth: %.3lf Mbps" , tp);
  }
  if (tp < tput_min_mbps) {
    failed_tests_perf++;
    error_cause=" (performance)";
  }
  if(dev_stat->content_error || host_stats->content_error ){
    failed_tests_content++;
    error_cause=" (content)";
  }
  if(dev_stat->transfer_error || host_stats->transfer_error ){
    failed_tests_xfer++;
    error_cause=" (transfer error)";
  }

  TEST_RESULT ret=PASSED;
  if ((dev_stat->content_error != 0) || (dev_stat->transfer_error != 0)) {
    ret = FAILED;
  }
  if ((host_stats->content_error != 0) || (host_stats->transfer_error != 0)) {
    ret = FAILED;
  }
  if (ret == PASSED ) {
    if (tp <  tput_min_mbps) {
      ret = boot_drv_usb_cfg()->test_perf_as_error ? FAILED : WARN;
    }
  }
  switch(ret ) {
    case PASSED:
        TEST_INFO("\n    PASSED");
        break;
    case FAILED:
        TEST_INFO("\n    FAILED%s\n",error_cause);
    case WARN:
        TEST_INFO("\n    WARN%s\n",error_cause);
  }

  return ret;
}

static int usb_tput_test_single(size_t tc_index, size_t tc_run, size_t max_tc_index, CL_USB_SPEED speed) {
  TEST_RESULT result = FAILED;
  int fd_driver = 0;
  int io_result;
  struct USBTP_TestCase* tc = &testcases[tc_index];
  struct tpt_device_statistic dev_stat;
  struct tpt_statistics host_stat;
  unsigned int test_duration_sec = 0;

  // start_host_app
  TEST_INFO("\n    %s", tput_test_info(tc, tc_run, max_tc_index, speed));

  if((fd_driver = usb_tput_test_start_host_driver(tc)) < 0){
      return FAILED;
  }

  usb_test_keepalive_driver(fd_driver, tc->duration);
  test_duration_sec = tc->duration;
  do {
    io_result = usb_test_driver_call_ioctl(fd_driver, TPT_GET_STATISTICS, &host_stat);
    if (io_result < 0){
      return FAILED;
    }
    if (ep_is_in(tc->ep) && (host_stat.packets_transferred > TEST_MIN_IN_PACKETS)) {
      break;
    }
    if (!ep_is_in(tc->ep) && (host_stat.out_buffers_completed > TEST_MIN_OUT_COMPLETIONS)) {
      break;
    }
    if (test_duration_sec > TEST_TIMEOUT_SEC) {
      break;
    }
    sleep(1);
    test_duration_sec++;
  } while(1);

  usb_test_stop_driver(fd_driver);

  io_result=usb_test_driver_call_ioctl(fd_driver, TPT_GET_DEV_STATISTIC, &dev_stat);
  if(io_result < 0){
    TEST_INFO("\n  ioctl: %u",io_result);
    usb_test_stop_driver(fd_driver);
    usb_test_close_driver(fd_driver);
    return FAILED;
  }

  usb_test_driver_call_ioctl(fd_driver, TPT_ENDPOINT_RESET,NULL);
  usb_test_stop_driver(fd_driver);
  usb_test_close_driver(fd_driver);

  if (test_duration_sec > TEST_TIMEOUT_SEC) {
    TEST_INFO("\n  Test failed: Timeout - could not transfer min packets.");
    return FAILED;
  }

  result = usb_tput_test_evaluate(fd_driver, tc, &dev_stat, speed);

  return result;
}


static int testcase_index(const char* tag) {
    for(uint32_t tc_index = 0; tc_index < number_testcases; tc_index++) {
      if (strcmp(tag,testcases[tc_index].description) == 0){
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



static void add_result(test_results_t* results , TEST_RESULT result){
  switch (result) {
    case PASSED: results->passed++; break;
    case WARN: results->passed_with_warning++; break;
    default : results->failed++; break;
  }
}
int apre_usb_tp_test()
{
  test_results_t results={0,0,0};
  TEST_RESULT current = 0;
  CL_USB_SPEED speed=CL_USB_SPEED_UNDEFINED;

  if (usb_test_restart_reconnect_umac() != 0) {
    TEST_INFO("\n*** Reconnect failed");
    return FAILED;
  }

  if(usb_test_check_driver_loaded() != 0 ){
    TEST_INFO("\n*** host driver not loaded !\n");
    return FAILED;
  }

  speed=cl_usb_get_speed();
  if (speed == CL_USB_SPEED_HIGH) {
    TEST_INFO("\nUSB Highspeed device detected , using highspeed values\n\n");
  }

  if(usb_test_tags > 0) {
      TEST_INFO("\nTests to run : %u (of %u available)\n", (unsigned int)usb_test_tags, (unsigned int)number_testcases);
      for(int i = 0; i < usb_test_tags; i++){
        int tc_index = testcase_index(usb_tc_tags[i].tag);
        if(tc_index < 0) {
          TEST_INFO("\nUnknown test tag %s\n", usb_tc_tags[i].tag);
          return FAILED;
        }
        if(usb_tc_tags[i].override_perf_limit != 0.0 ){
          testcases[tc_index].tput_min_mbps_hs = usb_tc_tags[i].override_perf_limit;
          testcases[tc_index].tput_min_mbps_ss = usb_tc_tags[i].override_perf_limit;
        }

        current = usb_tput_test_single(tc_index, i, usb_test_tags, speed);
        add_result(&results,current);
      }
  }else {
    if (boot_drv_usb_cfg()->test_selected == -1) {
      TEST_INFO("\nTests to run : %u\n", (unsigned int)number_testcases);
      for(uint32_t tc_index = 0; tc_index < number_testcases; tc_index++) {
        current = usb_tput_test_single(tc_index, tc_index, number_testcases, speed);
        add_result(&results,current);
      }
    } else {
      if (boot_drv_usb_cfg()->test_selected >= number_testcases) {
        TEST_INFO("\nFAILED: testindex out-of-range %d of [1..%d]\n", (unsigned int)(boot_drv_usb_cfg()->test_selected + 1), (unsigned int)number_testcases);
        return FAILED;
      }

      TEST_INFO("\nTest case %d selected (number available testcases: %u)\n", boot_drv_usb_cfg()->test_selected + 1, (unsigned int)number_testcases);
      current = usb_tput_test_single(boot_drv_usb_cfg()->test_selected, boot_drv_usb_cfg()->test_selected, number_testcases, speed);
      add_result(&results,current);
    }
  }
  TEST_INFO("\n");
  if (results.failed > 0 ){
    TEST_INFO("\nFAILED USBTP tests : %u failed of %u\n\n", results.failed, results.failed + results.passed);
    TEST_INFO("\n                     %u failed by performance",failed_tests_perf);
    TEST_INFO("\n                     %u failed by data persistence",failed_tests_content);
    TEST_INFO("\n                     %u failed by transfer errors\n",failed_tests_xfer);
    return FAILED;
  }else{
    TEST_INFO("\nPASSED USBTP tests     (%u)\n", results.passed + results.passed_with_warning);
    if (results.passed_with_warning) {
      TEST_INFO("\n      with warnings    (%u)\n", results.passed_with_warning);
    }
    return PASSED;
  }
}
