/**
 ****************************************************************************************
 *
 * @file cl6000_common_test.h
 *
 * @brief CL6000 common test infrastructure.
 *
 * Copyright (C) Emsys/Celeno 2021
 *
 ****************************************************************************************
 */

#ifndef CL6000_COMMON_H_
#define CL6000_COMMON_H_

#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include "cli_usb.h"
#include "../cl_reg/cl_reg.h"

typedef enum TEST_RESULT_t{
  PASSED = 0,
  FAILED = 1,
  WARN   = 2
} TEST_RESULT;


#define TEST_INFO(fmt, args...)       \
  {                                   \
    if (errno && (errno != EAGAIN)) { \
      perror("ERROR: ");              \
      errno = 0;                      \
    }                                 \
    printf(fmt, ##args);              \
  }

uint32_t CL6000_LOCAL_UMAC_IRAM_OFFSET();
uint32_t CL6000_LOCAL_UMAC_DRAM_BASE();
uint32_t CL6000_LOCAL_UMAC_IRAM_BASE();


#define CL6000_UMAC_VID 0x33DE
#define CL6000_UMAC_PID 0x6000

#define CL6000_UMAC_APP_BCD_DEV_WIFI_BT 0x0101
#define CL6000_UMAC_APP_BCD_DEV_WIFI    0x0102
#define CL6000_UMAC_APP_BCD_DEV_BT      0x0103
#define CL6000_UMAC_APP_BCD_DEV_YP      0x0104

#define CL6000_UMAC_IS_BOOTROM_RUNNING(bcdDevice) ((bcdDevice) < 0x0100)
#define CL6000_UMAC_IS_APP_RUNNING(bcdDevice)     (!CL6000_UMAC_IS_BOOTROM_RUNNING(bcdDevice))
#define CL6000_UMAC_APP_HAS_WIFI(bcdDevice)       (((bcdDevice) == 0x0101) || ((bcdDevice) == 0x0102))
#define CL6000_UMAC_APP_HAS_BT(bcdDevice)         (((bcdDevice) == 0x0101) || ((bcdDevice) == 0x0103))

#define CL6000_UMAC_POSTMORTEM_ADDR     0x60600588
#define CL6000_UMAC_BL_DUMP_START       0x60040000
#define CL6000_UMAC_BL_CRASH_DUMP_START 0x60050000
#define CL6000_UMAC_BL_DUMP_SIZE        0x10000
#define CL6000_UMAC_CONFIG              0x4002FF00
#define CL6000_UMAC_CRASH_INFO          0x4002FFD0
#define CL6000_UMAC_CRASH_INFO_SIZE     0x20

#define CL6000_UMAC_BL_CRASH_DUMP "umac_bl_crash_dump.hex"
#define CL6000_UMAC_BL_DUMP       "umac_bl_core_dump.hex"
#define CL6000_UMAC_APP_DUMP      "umac_app_core_dump.hex"

// bec. current limitation of the iwcl tool: cli payload must not be multiple of USB MPS and ascii output must not reach 4k
#define CL6000_IWCL_MAX_BURST_SIZE (0x200 + 4)

#define CL6000_LOCAL_SRAM_BASE  0x60000000
#define CL6000_LOCAL_SRAM_SIZE  0x00060000
#define CL6000_OFFSET_STATS_LOC 0x3C
#define UMAC_STARTUP_DELAY_TEST_MS 1000

int save_bootrom_dump();
int save_bootrom_crash_dump();
int save_app_dump();
void set_coredump_cl_read_use_driver(const char* device_name);

int cl6000_umac_bootrom_exception_test();
int cl6000_umac_ep0_stall_test();

enum  ASCI_VERS {
  ASIC_VERS_UNDEF = 0,
  ASIC_VERS_A = 1,
  ASIC_VERS_B = 2,
};

struct config_t {
  uint32_t asic_vers;
  uint32_t umac_disconnect_delay_ms;
  uint32_t umac_restart_delay_ms;
  uint8_t  verbose;
  char     fw_path[100];
  int      test_selected;
  uint8_t  test_perf_as_error;
  char     umac_reg_cfg_file[256];
  char     umac_dump_driver_device_name[64];
};

struct config_t* boot_drv_usb_cfg();

#endif // CL6000_COMMON_H_
