/**
 ****************************************************************************************
 *
 * @file cl6000_usb_test_wifireset.c
 *
 * @brief CL6000 UMAC test infrastructure.
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
#include "cl6000_usb_test_wrapper_priv.h"
#include <sys/ioctl.h>
#include <fcntl.h>
#include "regs.h"

#define PDMA_COUNT (4)
#define PACKET_COUNT (256)
#define VERSION (4)


#define DEF_DS_PARAM {USBW_DS_AGGR_REG,{16,(8-2),20,EMC_CELENO_AGGR_OpMode_normal}}

#define OTHER_EP_NO 0
static struct USBW_TestCase testcases[] = {
  {    "AGGR", 0.0, 0.0, 0.0, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x2,  0, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*1024, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
  {    "AGGR", 0.0, 0.0, 0.0, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x3,  1, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*1024, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
  {     "SPK", 0.0, 0.0, 0.0, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE,  0x8,  6, PDMA_COUNT, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT*1600, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
  {    "CONT", 0.0, 0.0, 0.0, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE, 0x85,  0, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
  {"SPKT-MUX", 0.0, 0.0, 0.0, OTHER_EP_NO, DEF_DS_PARAM, {VERSION, 0, USBW_IDLE, 0x82,  1, PDMA_COUNT,   USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT*1532, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
};

static size_t number_testcases = sizeof(testcases) / sizeof(testcases[0]);
static uint32_t test_control_seq = 0;
static const char* lmac_fw_name = 0;

static uint32_t test_evaluate(struct USBW_TestCase* tc)
{
    uint32_t test_status;
    int result = FAILED;
    cl_usb_read32(test_status_base_addr() + WRAPPER_TEST_STATUS_STATE_OFFSET, &test_status);

    if (test_status == USBW_STATUS_FINISHED) {
        result = PASSED;
    }
    if (result == PASSED) {
        TEST_INFO("\n        PASS\n");
    } else {
        TEST_INFO("\n***     FAILED\n");
    }
    return result;
}

static const char* test_info(size_t tc_index) {
  static char line[256];
  struct USBW_TestCase* tc = &testcases[tc_index];
  struct USBW_TestControlRequest* req = &(tc->control_request);

  char channel_name[16];
  snprintf(channel_name, sizeof(channel_name), "%c%u", (req->direction==USBW_UP_STREAM) ? 'U' : 'D', req->lli_channel);

  snprintf(line, sizeof(line), "TC %2d: LLI %3s EP:%02X #PDMA=%d %8s ",
      (unsigned int)tc_index+1,  channel_name, req->ep,  req->number_pdma, tc->description);
  return line;
}


#define REG_USBW_BASE_ADDR             (0x607D7000)

#define USBW_NUM_CH_PER_LLI_U0_U3 (0X240)
#define USBW_NUM_CH_PER_LLI_U4_U7 (0X244)
#define USBW_NUM_CH_PER_LLI_U8_U11 (0X248)
#define USBW_NUM_CH_PER_LLI_U12_U15 (0X24C)

#define USBW_NUM_CH_PER_LLI_D0_D3 (0X250)
#define USBW_NUM_CH_PER_LLI_D4_D7 (0X254)
#define USBW_NUM_CH_PER_LLI_D8_D11 (0X258)
#define USBW_NUM_CH_PER_LLI_D12_D15 (0X25C)

#define USBW_LLI_STOP               (0x204)
#define USBW_LLI_CNT_RST             (0x208)


void usb_wifireset_test_list() {
  TEST_INFO("\nUMAC USB Wifi-Reset Tests:");
  for(uint32_t tc_index = 0; tc_index < number_testcases; tc_index++) {
    TEST_INFO("\n    %s", test_info(tc_index));
  }
  TEST_INFO("\n");
}

static int usb_reset_test_single(size_t tc_index) {
  int result = FAILED;
  int fd_driver = 0;

  struct USBW_TestCase* tc = &testcases[tc_index];
  struct USBW_TestControlRequest* req = &(tc->control_request);
  struct tpt_start drv_start = usb_wrapper_test_get_tpt_start(tc);
  struct tpt_parameter drv_param = usb_wrapper_test_get_tpt_param(tc, 1);


  TEST_INFO("\n    %s", test_info(tc_index));

  req->sequence_id = test_control_seq++;
  usb_wrapper_test_write_request(req);
  drv_param.packets_to_transfer = 16;
  if((fd_driver = usb_wrapper_test_start_host_driver_with_param(tc, &drv_start, &drv_param)) < 0){
      return FAILED;
  }
  drv_param.packets_to_transfer = 0;
  cl_usb_write32(test_control_base_addr() + WRAPPER_TEST_CONTROL_REQUEST_OFFSET, USBW_START);
  cl_usb_write32(test_control_base_addr() + WRAPPER_TEST_CONTROL_SEQ_ID_OFFSET, test_control_seq++);
  usb_wrapper_test_wait_running(fd_driver,2);
  usb_wrapper_test_wait_finished(fd_driver,2);
  TEST_INFO("\n        Reset wifi interface");
  // test is now running, clear TestControl and reload lmac
  TEST_INFO("\n        Clear shared test control/status memory");
  usb_test_stop_driver(fd_driver);
  macsys_gcu_xt_control_lmac_run_stall_setf(1); // 0x607C50F0

  usb_wrapper_clear_control_area();
  usb_test_wifi_set_alternate_setting(fd_driver, 1);

  usb_test_close_driver(fd_driver);

  TEST_INFO("\n        Reload/Reset LMAC");
  load_and_start_lmac_fw(lmac_fw_name);

  TEST_INFO("\n        Continue with %s",test_info(tc_index));

  usb_wrapper_test_write_request(req);
  if((fd_driver = usb_wrapper_test_start_host_driver(tc, 1)) < 0){
      return FAILED;
  }

  sleep(2);
  cl_usb_write32(test_control_base_addr() + WRAPPER_TEST_CONTROL_REQUEST_OFFSET, USBW_START);
  cl_usb_write32(test_control_base_addr() + WRAPPER_TEST_CONTROL_SEQ_ID_OFFSET, test_control_seq++);

  if (!usb_wrapper_test_wait_finished(fd_driver, 30)) {
    return FAILED;
  }
  if( !usb_wrapper_test_stop(fd_driver, NULL)){
      TEST_INFO("\n*** Could not stop running test! Aborted!\n");
      return FAILED;
  }
  result = test_evaluate(tc);
  return result;
}

int apre_usb_wifi_reset_test(const char* lmac_fw)
{
  uint32_t passed_tests = 0;
  uint32_t failed_tests = 0;
  int current = 0;

  lmac_fw_name = lmac_fw;

  if (!strcmp(lmac_fw_name,"no_load")) {
    TEST_INFO("\n*** No lmac firmware specified. Can't start wifi reset tests!\n");
    return FAILED;
  }
  if (usb_test_restart_reconnect_umac() != 0) {
    TEST_INFO("\n*** Reconnect failed");
    return FAILED;
  }

  if(usb_test_check_driver_loaded() != 0 ){
    TEST_INFO("\n*** host driver not loaded !\n");
    return FAILED;
  }

  load_and_start_lmac_fw(lmac_fw_name);

  if (boot_drv_usb_cfg()->test_selected == -1) {
    TEST_INFO("\nTests to run : %u\n", (unsigned int)number_testcases);
    for(uint32_t tc_index = 0; tc_index < number_testcases; tc_index++) {
      current = usb_reset_test_single(tc_index);
      if (current == PASSED) {
        passed_tests++;
      } else {
        failed_tests++;
      }
    }
  } else {
    if (boot_drv_usb_cfg()->test_selected >= number_testcases) {
      TEST_INFO("\nFAILED: testindex out-of-range %d of [1..%d]\n", (unsigned int)(boot_drv_usb_cfg()->test_selected + 1),(unsigned int)number_testcases);
        return FAILED;
      }

      TEST_INFO("\nTest case %d selected (number available testcases: %u)\n", boot_drv_usb_cfg()->test_selected + 1, (unsigned int)number_testcases);
      current = usb_reset_test_single(boot_drv_usb_cfg()->test_selected);
      if (current == PASSED) {
        passed_tests++;
      } else {
        failed_tests++;
      }
  }

  TEST_INFO("\n");
  if (failed_tests > 0 ){
    TEST_INFO("\nFAILED Wifi Reset tests : %u failed of %u\n\n", failed_tests, failed_tests + passed_tests);
    return FAILED;
  }else{
    TEST_INFO("\nPASSED Wifi Reset tests (%u)\n\n", passed_tests);
    return PASSED;
  }
}
