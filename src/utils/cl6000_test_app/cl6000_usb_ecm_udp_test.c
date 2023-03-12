#include "cl6000_usb_test.h"
#include "cl6000_usb_test_wrapper_priv.h"
#include "libusb-1.0/libusb.h"
#include <arpa/inet.h>
#include <fcntl.h>
#include <inttypes.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PACKET_COUNT (8192)
#define VERSION (4)
#define TEST_TIMEOUT 400
#define TPUT_SECURITY_GAP 0.0

#define DEVICE_IP "10.10.10.200"
#define MY_IP "10.10.10.100"
#define TEST_PORT (10000)

int usb_udp_test();
static bool usb_test_is_finished();
static bool usb_test_wait_started(int32_t timeout_seconds);

#define VOID_PARAM {USBW_VOID,{0,0,0,0}}

static struct USBW_TestCase testcases_umac[] = {
    //#01
    {"UDP-US-1472", 0.0, 0.0, TPUT_SECURITY_GAP, 0,VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x0, 0, 0, USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT * 1472, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {"UDP-US-1472-CRC", 0.0, 0.0,  TPUT_SECURITY_GAP, 0,VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x0, 0, 0, USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT * 1472, USBW_CRC32}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {"UDP-US-1024", 0.0, 0.0,  TPUT_SECURITY_GAP, 0,VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x0, 0, 0, USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT * 1024, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {"UDP-US-512", 0.0, 0.0,  TPUT_SECURITY_GAP, 0,VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x0, 0, 0, USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT * 512, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {"UDP-US-64", 0.0, 0.0,  TPUT_SECURITY_GAP, 0,VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x0, 0, 0, USBW_UP_STREAM, {PACKET_COUNT, PACKET_COUNT * 64, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {"UDP-DS-1472", 0.0, 0.0,  TPUT_SECURITY_GAP, 0,VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x0, 0, 0, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT * 1472, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {"UDP-DS-1024", 0.0, 0.0,  TPUT_SECURITY_GAP, 0,VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x0, 0, 0, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT * 1024, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {"UDP-DS-512", 0.0, 0.0,  TPUT_SECURITY_GAP, 0,VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x0, 0, 0, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT * 512, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
    {"UDP-DS-64", 0.0, 0.0,  TPUT_SECURITY_GAP, 0,VOID_PARAM, {VERSION, 0, USBW_IDLE, 0x0, 0, 0, USBW_DOWN_STREAM, {PACKET_COUNT, PACKET_COUNT * 64, USBW_DONT_CARE}, 0xFFFFFF, USBW_STOP_ON_ERROR, {USBW_LOOP_COUNT, 1}}},
};

static size_t number_testcases = sizeof(testcases_umac) / sizeof(testcases_umac[0]);

int apre_usb_udp_test() {
  int result = PASSED;
  result = usb_udp_test();

  return result;
}

static int do_percent(int old_percent, int current, int all) {
  int percent = (current * 20) / all;
  if (percent != old_percent) {
    printf(".");
    fflush(stdout);
    old_percent = percent;
    if (usb_test_is_finished()) {
      return -1;
    }
  }
  return old_percent;
}

static int transfer_data(struct USBW_TestCase *tc) {
  size_t transfers = tc->control_request.packets.packet_count;
  size_t size = tc->control_request.packets.number_bytes / tc->control_request.packets.packet_count;
  int result = PASSED;
  size_t i = 0;
  int bytes = 0;
  // int len_in = 0;
  uint8_t *data_out = 0;
  uint8_t *data_in = 0;
  int old_percent = 0;
  errno = 0;
  result = 0;

  int fd;
  struct sockaddr_in servaddr_other;
  struct sockaddr_in servaddr_me;
  uint servaddr_len = sizeof(servaddr_other);

  if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket creation failed");
    return FAILED;
  }

  TEST_INFO("\n        Running");

  memset(&servaddr_other, 0, sizeof(servaddr_other));
  memset(&servaddr_me, 0, sizeof(servaddr_me));
  if (tc->control_request.direction == USBW_DOWN_STREAM) {
    usb_wrapper_test_write_request_at(UMAC_WRAPPER_TEST_CONTROL_BASE, &tc->control_request);
    if (!usb_test_wait_started(10)) {
      close(fd);
      return FAILED;
    }
    servaddr_other.sin_family = AF_INET; // IPv4
    servaddr_other.sin_addr.s_addr = inet_addr(DEVICE_IP);
    servaddr_other.sin_port = htons(TEST_PORT);

    data_out = malloc(size);
    TEST_INFO("\n        sending %zu packets", transfers);
    while (i < transfers) {
      data_out[0] = i;
      bytes = sendto(fd, (const char *)data_out, size, MSG_CONFIRM, (const struct sockaddr *)&servaddr_other, servaddr_len);
      if (bytes < 0) {
        TEST_INFO("Error: write failed. ec: %d \n", bytes);
        result = -1;
        break;
      } else {
        if (bytes != size) {
          TEST_INFO("Error: write failed. only : %d \n", bytes);
        }
        i++;
      }
      if ((old_percent = do_percent(old_percent, i, transfers)) < 0) {
        break;
      }
    }
  }

  if (tc->control_request.direction == USBW_UP_STREAM) {
    servaddr_other.sin_family = AF_INET; // IPv4
    servaddr_other.sin_port = htons(10000);
    data_in = malloc(size);
    if (bind(fd, (struct sockaddr *)&servaddr_other, servaddr_len) != 0) {
      result = -1;
      TEST_INFO("Error: bind failed\n");
    }
    usb_wrapper_test_write_request_at(UMAC_WRAPPER_TEST_CONTROL_BASE, &tc->control_request);
    TEST_INFO("\n        receiving %zu packets", transfers);
    while (i < transfers && result == PASSED) {
      bytes = recvfrom(fd, data_in, size, 0, (struct sockaddr *)&servaddr_other, &servaddr_len);
      if (bytes >= 0) {
        if (bytes == size) {
          i++;
        } else {
          TEST_INFO("Error: read failed. only : %d received\n", bytes);
        }
      } else {
        TEST_INFO("Error: read failed. ec: %d \n", bytes);
        result = -1;
        break;
      }
      if ((old_percent = do_percent(old_percent, i, transfers)) < 0)
        break;
    }
  }
  if (data_in) {
    free(data_in);
  }
  if (data_out) {
    free(data_out);
  }
  close(fd);
  TEST_INFO("\n        done");
  return result ? FAILED : PASSED;

  return FAILED;
}

static bool usb_test_is_finished() {
  uint32_t test_status = 0;
  cl_usb_read32(UMAC_WRAPPER_TEST_STATUS_BASE + WRAPPER_TEST_STATUS_STATE_OFFSET, &test_status);
  return test_status == USBW_STATUS_FINISHED;
}

static void usb_test_wait_finished(int32_t timeout_seconds) {
  TEST_INFO("\n        Wait for finish");
  uint32_t test_status = 0;
  cl_usb_read32(UMAC_WRAPPER_TEST_STATUS_BASE + WRAPPER_TEST_STATUS_STATE_OFFSET, &test_status);
  while ((test_status != USBW_STATUS_FINISHED) && (timeout_seconds > 0)) {
    sleep(1);
    timeout_seconds -= 1;
    cl_usb_read32(UMAC_WRAPPER_TEST_STATUS_BASE + WRAPPER_TEST_STATUS_STATE_OFFSET, &test_status);
    TEST_INFO(".");
    fflush(stdout);
  }

  if (timeout_seconds <= 0) {
    TEST_INFO("\n*** Timeout , test not finished");
  } else {
    TEST_INFO("\n. done");
  }
}

static bool usb_test_wait_started(int32_t timeout_seconds) {
  uint32_t test_status = 0;
  cl_usb_read32(UMAC_WRAPPER_TEST_STATUS_BASE + WRAPPER_TEST_STATUS_STATE_OFFSET, &test_status);
  while ((test_status != USBW_STATUS_STARTED) && (timeout_seconds > 0)) {
    sleep(1);
    timeout_seconds -= 1;
    cl_usb_read32(UMAC_WRAPPER_TEST_STATUS_BASE + WRAPPER_TEST_STATUS_STATE_OFFSET, &test_status);
  }

  if (timeout_seconds <= 0) {
    TEST_INFO("*** Timeout , test not started\n");
    return false;
  }
  return true;
}

static int usb_udp_single_test(struct USBW_TestCase *tc, int tc_idx,CL_USB_SPEED speed) {
  int result = 0;
  tc->control_request.cmd = USBW_START;
  tc->control_request.sequence_id = tc_idx + 1;
  usb_wrapper_clear_control_area();
  result = transfer_data(tc);
  if (result == PASSED) {
    usb_test_wait_finished(10);
    result = usb_wrapper_test_evaluate(UMAC_WRAPPER_TEST_STATUS_BASE, tc, 0, speed);
  }
  return result;
}

int usb_udp_test() {
  int result = PASSED;
  size_t passed = 0;
  size_t failed = 0;
  int ping_status = 0;
  int ping_retry = 5;
  CL_USB_SPEED speed = CL_USB_SPEED_SUPER;

  ping_status = system("ping " DEVICE_IP " -c1");
  while (ping_status && ping_retry--) {
    ping_status = system("ping " DEVICE_IP " -c1");
    sleep(1);
  }
  if (ping_status) {
    TEST_INFO("*** Error %d device not pingable at %s\n", ping_status,DEVICE_IP);
    TEST_INFO("Have you configured interface ? \n"
              "sudo ifconfig eth2 %s netmask 255.255.255.0 up",MY_IP);
    return FAILED;
  }

  TEST_INFO("\n\nUDP Loopback test\n");
  if (boot_drv_usb_cfg()->test_selected == -1) {
    for (size_t tc = 0; tc < number_testcases; tc++) {
      TEST_INFO("\n\nExecute test %s %zu/%zu\n", testcases_umac[tc].description, tc + 1, number_testcases);
      result = usb_udp_single_test(&testcases_umac[tc], tc, speed);
      if (result) {
        failed++;
      } else {
        passed++;
      }
    }
  } else {
    if (boot_drv_usb_cfg()->test_selected >= number_testcases) {
      TEST_INFO("\nFAILED: testindex out-of-range %d of [1..%d]\n", boot_drv_usb_cfg()->test_selected + 1, (int)number_testcases);
      return FAILED;
    }
    TEST_INFO("\nTest case %d selected (number available testcases: %zu)\n", boot_drv_usb_cfg()->test_selected + 1, number_testcases);
    TEST_INFO("\n\nExecute test %s\n", testcases_umac[boot_drv_usb_cfg()->test_selected].description);
    result = usb_udp_single_test(&testcases_umac[boot_drv_usb_cfg()->test_selected], boot_drv_usb_cfg()->test_selected,speed);
    if (result) {
      failed++;
    } else {
      passed++;
    }
  }
  if (failed) {
    TEST_INFO("\n\nFAILED: %zu/%zu\n", failed, number_testcases);
  } else {
    TEST_INFO("\n\nPASSED: %zu/%zu\n", number_testcases, number_testcases);
  }

  return result;
}
