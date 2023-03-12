/**
 ****************************************************************************************
 *
 * @file cl6000_usb_test_common.c
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
#include <stdarg.h>
#include <inttypes.h>
#include <ctype.h>
#include <unistd.h>
#include <asm-generic/types.h>

#include "reg_logger_ram.h"
#include "cl6000_usb_test.h"
#include "regs.h"
#include "cl6000_common.h"
#include "libusb-1.0/libusb.h"
#include <sys/ioctl.h>
#include <fcntl.h>
#include <time.h>

struct tpt_statistics usb_test_statistic;

usb_tc_tags_t usb_tc_tags[USB_MAX_TESTCASES] = {};
size_t usb_test_tags = 0;

void cl6000_load_bin(ptrdiff_t mem_addr, size_t mem_size, const char *filename, size_t bin_offset);
void cl6000_mac_fw_init(uint8_t smac_boot_source_iram_init);


static struct config_t config = {
  ASIC_VERS_UNDEF ,  
  500,  // umac_disconnect_delay_ms, default for ASIC
  2000, // umac_restart_delay_ms, default for ASIC
  0,    // verbose
  {0},  // fw_path
  -1,   // usb_test_selected
  1,    // usb_test_perf_as_error
  {0},  // umac_reg_cfg_file
  {0}   // umac_dump_driver_device_name
};

struct config_t* boot_drv_usb_cfg() {
  return &config;
}

static int check_exception()
{
  uint32_t timeout = 1000; ///yes 1000 seconds because palladium ~1/800 speed to realtime
  uint32_t status = -1;
  uint32_t value;
  CLI_USB_Config tmp_config = *cl_get_usb_config();
  cl_usb_close();
  tmp_config.silent = boot_drv_usb_cfg()->verbose ? 0 : 1;
  TEST_INFO("    wait for re-enumeration ...\n");
  while((status != 0) && (--timeout > 0)){
    status =( cl_usb_open(&tmp_config) || cl_usb_read32(CL6000_UMAC_POSTMORTEM_ADDR, &value) );
    sleep(1);
  }
  if (timeout == 0) {
    TEST_INFO("Error: device not reenumerated\n");
    return FAILED;
  }
  if (value != 0) {
      TEST_INFO("    found exception info\n");
      if (save_bootrom_dump()) {
        TEST_INFO("Error: saving coredump\n");
        return FAILED;
      }
  } else {
        TEST_INFO("Error: coredump not set\n");
        return FAILED;
  }
  return PASSED;
}

uint32_t CL6000_LMAC_RAM_ADDR()          { return LMAC_DRAM_ADDR; }
uint32_t CL6000_LMAC_RAM_SIZE()          { return 0x80000; }
uint32_t CL6000_LMAC_DRAM_ADDR()         { return LMAC_DRAM_ADDR; }
uint32_t CL6000_LMAC_DRAM_SIZE()         { return LMAC_DRAM_SIZE; }
uint32_t CL6000_LMAC_IRAM_ADDR()         { return LMAC_IRAM_ADDR;  }
uint32_t CL6000_LMAC_IRAM_SIZE()         { return LMAC_IRAM_SIZE; }
uint32_t CL6000_LOCAL_LMAC_IRAM_OFFSET() { return 0x80000; }
uint32_t CL6000_SMAC_RAM_ADDR()          { return SMAC_DRAM_ADDR; }
uint32_t CL6000_SMAC_RAM_SIZE()          { return 0x80000; /* 256KB+256KB */}
uint32_t CL6000_SMAC_DRAM_ADDR()         { return SMAC_DRAM_ADDR; }
uint32_t CL6000_SMAC_DRAM_SIZE()         { return SMAC_DRAM_SIZE; }
uint32_t CL6000_SMAC_IRAM_ADDR()         { return SMAC_IRAM_ADDR; }
uint32_t CL6000_SMAC_IRAM_SIZE()         { return SMAC_IRAM_SIZE; }
uint32_t CL6000_LOCAL_SMAC_IRAM_OFFSET() { return 0x80000; }

uint32_t CL6000_LOCAL_UMAC_IRAM_OFFSET() { return 0x80000; }
uint32_t CL6000_LOCAL_UMAC_DRAM_BASE()   { return 0x40000000; }
uint32_t CL6000_LOCAL_UMAC_IRAM_BASE()   { return CL6000_LOCAL_UMAC_DRAM_BASE() + CL6000_LOCAL_UMAC_IRAM_OFFSET(); }

uint32_t CL6000_UMAC_RAM_ADDR()  { return UMAC_DRAM_ADDR; }
uint32_t CL6000_UMAC_RAM_SIZE()  { return 0x80000; }
uint32_t CL6000_UMAC_DRAM_ADDR() { return UMAC_DRAM_ADDR; }
uint32_t CL6000_UMAC_IRAM_ADDR() { return UMAC_IRAM_ADDR; }

uint32_t CL6000_UMAC_DRAM_SIZE() {
  if (boot_drv_usb_cfg()->asic_vers == ASIC_VERS_B) {
    return 0x40000;
  }
  return UMAC_DRAM_SIZE;
}

uint32_t CL6000_UMAC_IRAM_SIZE() 
{
  if (boot_drv_usb_cfg()->asic_vers == ASIC_VERS_B) {
    return 0x80000;
  }
  return UMAC_IRAM_SIZE;
}



int cl6000_umac_exception_write_at_0()
{
  TEST_INFO("TC Force exception by write at addr 0x00000000\n");
  TEST_INFO("    clear exception register\n");
  TEST_INFO("    throw PIF exception\n");
  cl_usb_write32(CL6000_UMAC_POSTMORTEM_ADDR, 0);
  cl_usb_write32_fast(0x0, 0xFF);
  if(check_exception() != PASSED){
    return FAILED;
  }
  return PASSED;
}

static int cl6000_umac_exception_jump_XXX()
{
  uint32_t status;
  TEST_INFO("TC Force exception by jump to %08X\n",CL6000_UMAC_POSTMORTEM_ADDR);
  TEST_INFO("    clear exception register\n");
  cl_usb_write32(CL6000_UMAC_POSTMORTEM_ADDR, 0);
  TEST_INFO("    throw illegal instruction exception\n");
  status = cl_usb_umac_execute(CL6000_UMAC_POSTMORTEM_ADDR);
  if (status) {
    TEST_INFO("Error: jump not possible\n");
    return FAILED;
  }
  if(check_exception() != PASSED){
    return FAILED;
  }
  return PASSED;
}


int cl6000_umac_bootrom_exception_test()
{
  uint32_t passed_tests = 0;
  uint32_t failed_tests = 0;
  CLI_USB_Config tmp_config = *cl_get_usb_config();
  tmp_config.silent = boot_drv_usb_cfg()->verbose ? 0 : 1;
  cl_usb_close();
  tmp_config.silent =  1;
  cl_usb_open(&tmp_config);
  TEST_INFO("\n");
  cl6000_umac_exception_write_at_0() == PASSED ? passed_tests++: failed_tests++;
  TEST_INFO("\n");
  cl6000_umac_exception_jump_XXX()    == PASSED ? passed_tests++: failed_tests++;
  TEST_INFO("\n");
  if (failed_tests){
    TEST_INFO("\nFAILED booloader exception tests (%u/%u)\n\n",failed_tests,failed_tests+passed_tests);
  }else{
    TEST_INFO("\nPASSED booloader exception tests (%u/%u)\n\n", passed_tests,passed_tests);
  }
  return failed_tests?FAILED:PASSED;
}


static libusb_device_handle* select_device(libusb_device** all_devices,
                                           ssize_t num_devices,
                                           uint16_t vendor_id,
                                           uint16_t product_id,
                                           const uint8_t* sn)
{
  for (ssize_t i = 0; i < num_devices; ++i) {
    struct libusb_device_descriptor desc;
    int                             status = libusb_get_device_descriptor(all_devices[i], &desc);
    if (status) {
      continue;
    }

    if ((desc.idVendor == vendor_id) && (desc.idProduct == product_id)) {
      if (sn) {
        if (desc.iSerialNumber) {
          libusb_device_handle* dev_handle;
          libusb_open(all_devices[i], &dev_handle);
          if (dev_handle) {
            unsigned char dev_sn[256];
            status = libusb_get_string_descriptor_ascii(dev_handle, desc.iSerialNumber, dev_sn, sizeof(dev_sn));
            if (0 == strncmp((const char*)sn, (const char*)dev_sn, sizeof(dev_sn))) {
              return dev_handle;
            } else {
              libusb_close(dev_handle);
            }
          }
        }
      } else {
        libusb_device_handle* dev_handle;
        libusb_open(all_devices[i], &dev_handle);
        if (dev_handle) {
          return dev_handle;
        }
      }
    }
  }
  return 0;
}

int cl6000_umac_ep0_stall_test()
{
  int result = PASSED;
  int rc;
  libusb_context*       context     = NULL;
  libusb_device_handle* handle      = NULL;
  libusb_device*        device      = NULL;
  libusb_device**       all_devices = NULL;
  ssize_t num_devices               = 0;
  uint16_t              vid         = CL6000_UMAC_VID;
  uint8_t               data_buffer[256];

  cl_usb_close();
  if (boot_drv_usb_cfg()->verbose) {
    TEST_INFO("Executing %s vid==0x%04x pid=0x%04x ...\n", __FUNCTION__, vid, cl_get_usb_config()->pid);
  }

  libusb_init(&context);
  num_devices = libusb_get_device_list(context, &all_devices);
  handle = select_device(all_devices, num_devices, vid, cl_get_usb_config()->pid, cl_get_usb_config()->sn);
  if (handle == NULL) {
    libusb_exit(context);
    TEST_INFO("Error: failed to open usb device\n");
    return FAILED;
  }

  device = libusb_get_device(handle);
  if (device == NULL) {
    libusb_close(handle);
    TEST_INFO("Error: failed to claim usb device\n");
    return FAILED;
  }

  // should be OK
  if (result != FAILED) {
    rc = libusb_get_descriptor(handle, LIBUSB_DT_DEVICE, 0, data_buffer,18);
    if (rc < 0) {
      TEST_INFO("     test standard request: FAILED\n ");
      result = FAILED;
    }else {
      if(boot_drv_usb_cfg()->verbose) {
        TEST_INFO("     test standard request: OK\n ");
      }
    }
  }

  // should STALL
  if (result != FAILED) {
    rc = libusb_get_descriptor(handle,LIBUSB_DT_DEVICE+32,0,
            data_buffer,18);
    if (rc >= 0) {
      TEST_INFO("    test invalid request (stall expected): FAILED\n ");
      result = FAILED;
    }else {
      if(boot_drv_usb_cfg()->verbose) {
        TEST_INFO("    test invalid request (stall expected): OK\n ");
      }
    }

  }

  // should be OK after stall
  if (result != FAILED) {
    rc = libusb_get_descriptor(handle,LIBUSB_DT_DEVICE,0,
            data_buffer,18);
    if (rc < 0) {
            TEST_INFO("    test standard request : FAILED\n ");
      result = FAILED;
    }else {
      if(boot_drv_usb_cfg()->verbose) {
        TEST_INFO("    test standard request :  OK\n ");
      }
    }

  }

  TEST_INFO("%s: cl6000_umac_ep0_stall_test\n",result==PASSED ? "PASS" : "FAILED");
  libusb_close(handle);
  libusb_free_device_list(all_devices, 1);
  libusb_exit(context);
  return result;
}

static uint32_t gcu_xt_control_cache=0;
int is_lmac_running()
{
  if (gcu_xt_control_cache==0){
     gcu_xt_control_cache=macsys_gcu_xt_control_get(); // 0x607C50F0
  }
  return  (gcu_xt_control_cache & MACSYS_GCU_XT_CONTROL_LMAC_RUN_STALL_BIT) ? 0: 1;
}

int is_smac_running()
{
  if (gcu_xt_control_cache==0){
    gcu_xt_control_cache=macsys_gcu_xt_control_get(); // 0x607C50F0
  }
  return  (gcu_xt_control_cache & MACSYS_GCU_XT_CONTROL_SMAC_RUN_STALL_BIT) ? 0: 1;
}

void load_and_start_lmac_fw(const char* fw_name)
{
  TEST_INFO("LMAC load/start %s", fw_name);

  cl6000_mac_fw_init(0);

   // now load LMAC code + data
  cl6000_load_bin(CL6000_LMAC_DRAM_ADDR(), CL6000_LMAC_DRAM_SIZE(), fw_name, 0);
  cl6000_load_bin(CL6000_LMAC_IRAM_ADDR(), CL6000_LMAC_IRAM_SIZE(), fw_name, CL6000_LOCAL_LMAC_IRAM_OFFSET());
  // run lmac fw (RUN_STALL=0)
  macsys_gcu_xt_control_lmac_run_stall_setf(0); // 0x607C50F0
}

void load_and_start_smac_fw(const char* fw_name)
{
    TEST_INFO("SMAC load/start %s", fw_name);

  cl6000_mac_fw_init(1);

   // now load LMAC code + data
  cl6000_load_bin(CL6000_SMAC_DRAM_ADDR(), CL6000_SMAC_DRAM_SIZE(), fw_name, 0);
  cl6000_load_bin(CL6000_SMAC_IRAM_ADDR(), CL6000_SMAC_IRAM_SIZE(), fw_name, CL6000_LOCAL_SMAC_IRAM_OFFSET());
  // run lmac fw (RUN_STALL=0)
  macsys_gcu_xt_control_smac_run_stall_setf(0); // 0x607C50F0
}

uint32_t test_control_base_addr() {
  if (is_lmac_running()) {
    return LMAC_WRAPPER_TEST_CONTROL_BASE;
  } else if (is_smac_running()) {
    return SMAC_WRAPPER_TEST_CONTROL_BASE;
  } else {
    TEST_INFO("\nNeither LMAC nor SMAC running: unable to compute test control base address\n");
    return 0;
  }
}

uint32_t test_status_base_addr() {
  if (is_lmac_running()) {
    return LMAC_WRAPPER_TEST_STATUS_BASE;
  } else if (is_smac_running()) {
    return SMAC_WRAPPER_TEST_STATUS_BASE;
  } else {
    TEST_INFO("\nNeither LMAC nor SMAC running: unable to compute test status base address\n");
    return 0;
  }
}

char *trimwhitespace(char *str)
{
  char *end;
  while(isspace((unsigned char)*str)) str++;
  if(*str == 0)  // All spaces?
    return str;
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;
  end[1] = '\0';
 return str;
}


typedef struct split_s{
  char tokens[10][100];
  int  cnt;
} split_t;

static split_t split(const char* src) {
  split_t ret;
  ret.cnt=0;
  char* pos = strstr(src,",");
  while(pos){
    if (pos) {
        strncpy(ret.tokens[ret.cnt],src, pos-src );
        trimwhitespace(ret.tokens[ret.cnt]);
        ret.cnt++;
        src=pos+1;
        pos = strstr(src,",");
    }
  }
  strcpy(ret.tokens[ret.cnt],src );
  trimwhitespace(ret.tokens[ret.cnt]);
  ret.cnt++;
  return ret;
}

int usb_test_select_by_file(FILE* fp) {
  char line[256];
  memset(usb_tc_tags, 0, sizeof(usb_tc_tags));
  usb_test_tags = 0;
  while(fgets(line, sizeof(line), fp)) {
    char* token = trimwhitespace(line);
    if ((!token) || (token[0] == 0) || (token[0] == '/') ||  (token[0] == '#')){
      continue;
    }
    memset(&usb_tc_tags[usb_test_tags],0,sizeof(usb_tc_tags_t));
    split_t split_res = split(token);
    for(int i = 0; i < split_res.cnt; i++) {
      switch(i) {
        case 0:
          strncpy(usb_tc_tags[usb_test_tags].tag, split_res.tokens[i], USB_TESTCASES_TAG_LEN);
          break;
        case 1:
          usb_tc_tags[usb_test_tags].override_perf_limit = atof(split_res.tokens[i]);
          break;
      }
    }
    usb_test_tags++;
    if (usb_test_tags == USB_MAX_TESTCASES){
      TEST_INFO("ERROR: to many test cases\n");
      return 0;
    }
  }
  return usb_test_tags > 0;
}

int cl_usb_open_pretty_print(const CLI_USB_Config* config) {
  int result = FAILED;
  result = cl_usb_open(config);
  if (result == 0) {
    uint32_t protocol_version;
    uint32_t firmware_version;
    result = cl_usb_get_version(&protocol_version, &firmware_version);
    if (result == 0) {
      printf("CLI Interface: ");
      printf("Prot: %06X.%02Xh ", protocol_version >> 8, protocol_version & 0xFF);
      printf("UMAC FW: %s - V%04X.%02Xh ", cl_usb_app_id_as_string((firmware_version >> 8) & 0xFF), firmware_version >> 16, firmware_version & 0xFF);
      printf("USB PID: 0x%04X ", cl_usb_get_pid());
      printf("bcdDevice: %x.%02x ", (cl_usb_get_fw_version() & 0xFF00) >> 8, cl_usb_get_fw_version() & 0xFF);
      printf("S/N: \"%s\"", cl_usb_get_sn());
      printf("\n");
    } else {
      printf("%s failed with status %d\n", "cl_usb_get_version", result);
    }
  }
  return result;
}


static uint8_t wait_for_app_enumeration(uint16_t pid)
{
  libusb_context*  context = NULL;
  libusb_device** all_devices;
  uint16_t result = 0;
  uint16_t connect_count = 0;
  uint32_t max_reconnect_count = 0;

  
  max_reconnect_count = (cl_get_usb_config()->connection_timeout_ms + 999) / 1000;
  while ((result == 0) && (connect_count < max_reconnect_count)) {
    libusb_init(&context);
    ssize_t num_devices = libusb_get_device_list(context, &all_devices);
    for (ssize_t i = 0; i < num_devices; ++i) {
      struct libusb_device_descriptor desc;
      int                             status = libusb_get_device_descriptor(all_devices[i], &desc);
      if (status) {
        continue;
      }
      if ((desc.idVendor == CL6000_UMAC_VID) && (desc.idProduct == pid) && CL6000_UMAC_IS_APP_RUNNING(desc.bcdDevice)) {
        result = 1;
        break;
      }
    }
    libusb_free_device_list(all_devices, 1);
    libusb_exit(context);
    if (result) {
      break;
    }
    sleep(1);
    if (boot_drv_usb_cfg()->verbose) {
      fprintf(stderr, "%s - Retry [%d/%d] ...\n", __func__, connect_count + 1, max_reconnect_count);
    }
    connect_count++;
  }
  return result;
}

int usb_wait_4_test_end_ind(uint32_t timeout_s, uint32_t test_end_ind_addr) {
  uint32_t counter = 0;
  uint32_t test_end_ind = 0;
  CLI_USB_Config tmp_config = *cl_get_usb_config();
  int result = 0;

  tmp_config.connection_timeout_ms = 0;
  tmp_config.silent = 1;  // be silent even for error

  cl_usb_umac_restart(boot_drv_usb_cfg()->umac_disconnect_delay_ms, boot_drv_usb_cfg()->umac_restart_delay_ms, CL6000_LOCAL_UMAC_IRAM_BASE());
  cl_usb_close();

  while (counter <= timeout_s)
  {
    result = cl_usb_open(&tmp_config);
    if (result == 0) {
      result = cl_usb_read32(test_end_ind_addr, &test_end_ind);
      cl_usb_close();
      if ((result == 0) && (test_end_ind == 0x1)) {
        cl_usb_open_pretty_print(cl_get_usb_config());
        return PASSED;
      }
    }
    sleep(1);
    counter++;
    fprintf(stderr, "%d/%d\r", counter, timeout_s);
  }
  cl_usb_open_pretty_print(cl_get_usb_config());
  TEST_INFO("\t\tTest Timed Out !!!\n");
  return FAILED;
}

int usb_test_restart_reconnect_umac() {
  int result = FAILED;
  uint16_t pid = cl_usb_get_pid();
  CLI_USB_Config tmp_config = *cl_get_usb_config();

  if (CL6000_UMAC_IS_APP_RUNNING(cl_usb_get_fw_version())) {
    TEST_INFO("\nUMAC Restart ... Wifi App already running ... skipped ...\n");
  } else {
    TEST_INFO("\nUMAC Restart ... reconnect ...\n");

    result = cl_usb_umac_restart(boot_drv_usb_cfg()->umac_disconnect_delay_ms, boot_drv_usb_cfg()->umac_restart_delay_ms, CL6000_LOCAL_UMAC_IRAM_BASE());
    if (result != 0) {
      TEST_INFO("\nUMAC Restart FAIL\n");
      return result;
    }
    cl_usb_close();

    usleep(1000000);

    tmp_config.silent = boot_drv_usb_cfg()->verbose ? 0 : 1;
    wait_for_app_enumeration(pid);
    result = cl_usb_open_pretty_print(&tmp_config);
    if (result != 0) {
      TEST_INFO("\t\t\tCLI Open FAIL\n");
      return result;
    }

    if (!CL6000_UMAC_IS_APP_RUNNING(cl_usb_get_fw_version())) {
      TEST_INFO("\nCLI Test FAIL: usb pid=0x%04x, bcdDevice=%x.%02x\n", cl_usb_get_pid(), (cl_usb_get_fw_version() & 0xFF00) >> 8, cl_usb_get_fw_version() & 0xFF);
      return 1;
    }

  }
  return 0;
}

int check_status(int status) {
  if (status < 0) {
    printf("check_status: error: %s, code %d\n", strerror(-status), status);
  }
  return status;
}

int usb_test_driver_call_ioctl(int fd, unsigned long request, void* param) {
  int retval = ioctl(fd, request, param);
  if (retval == -1) {
    retval = -errno;
  }
  if(check_status(retval)< 0){
    printf("fd %d, request %ld \n",fd, request);
  }
  return retval;
}


// clear sram area for WRAPPER_CONTROL and STATUS data exchange
void usb_wrapper_clear_control_area()
{
    /* USB Wrapper test */
    bool zero_copy = true;
    char* buffer = malloc(WRAPPER_TEST_CONTROL_STATUS_SIZE);
    memset(buffer, 0, WRAPPER_TEST_CONTROL_STATUS_SIZE);

    cl_usb_burst_write(UMAC_WRAPPER_TEST_CONTROL_BASE, buffer, WRAPPER_TEST_CONTROL_STATUS_SIZE, zero_copy);
    cl_usb_burst_write(UMAC_WRAPPER_TEST_STATUS_BASE, buffer, WRAPPER_TEST_CONTROL_STATUS_SIZE, zero_copy);

    cl_usb_burst_write(LMAC_WRAPPER_TEST_CONTROL_BASE, buffer, WRAPPER_TEST_CONTROL_STATUS_SIZE, zero_copy);
    cl_usb_burst_write(LMAC_WRAPPER_TEST_STATUS_BASE, buffer, WRAPPER_TEST_CONTROL_STATUS_SIZE, zero_copy);

    cl_usb_burst_write(SMAC_WRAPPER_TEST_CONTROL_BASE, buffer, WRAPPER_TEST_CONTROL_STATUS_SIZE, zero_copy);
    cl_usb_burst_write(SMAC_WRAPPER_TEST_STATUS_BASE, buffer, WRAPPER_TEST_CONTROL_STATUS_SIZE, zero_copy);
    free(buffer);
}

int usb_wrapper_test_wait_host_received_all_data(int driver,struct USBW_TestControlRequest* request,int32_t timeout_seconds)
{
    uint32_t bytes_expected=request->packets.number_bytes;
    struct tpt_statistics stats;
    int result = usb_test_driver_call_ioctl(driver, TPT_GET_STATISTICS, &stats);
    while (!result && timeout_seconds > 1){
        if(stats.payload_data >= bytes_expected){
          return 1;
        }
        timeout_seconds-=1;
        sleep(1);
        result = usb_test_driver_call_ioctl(driver, TPT_GET_STATISTICS, &stats);
    }
    return 0;

}

static int print_value(uint32_t addr, char* fmt){
  uint32_t value = 0;
  if (cl_usb_read32(addr, &value)) {
    TEST_INFO("\n*** cannot read value!\n");
    return 1;
  }
  printf(fmt, value);
  return 0;
}

int usb_print_container_regs(uint32_t addr, uint8_t lli_index){
  int ret = 0;
  TEST_INFO("\n        Setting USBW_US_CONT_REG[%d]\n", lli_index);
  ret |= print_value(addr + 0 * sizeof(uint32_t), "            host_container_count : %u\n");
  ret |= print_value(addr + 1 * sizeof(uint32_t), "            container_size       : %u\n");
  ret |= print_value(addr + 2 * sizeof(uint32_t), "            idle_time_us         : %u\n");
  ret |= print_value(addr + 3 * sizeof(uint32_t), "            copy_threshold       : %u\n");
  ret |= print_value(addr + 4 * sizeof(uint32_t), "            rxv_threshold        : %u\n");
  ret |= print_value(addr + 5 * sizeof(uint32_t), "            capabilities         : 0x%x");
  return ret;
}

int usb_print_aggr_regs(uint32_t addr, uint8_t lli_index) {
  int ret = 0;

  TEST_INFO("\n        Setting USBW_DS_AGGR_REG[%d]\n", lli_index);
  ret |= print_value(addr + 0 * sizeof(uint32_t), "            host_transfer_packets : %u\n");
  ret |= print_value(addr + 1 * sizeof(uint32_t), "            max_packets_per_io    : %u\n");
  ret |= print_value(addr + 2 * sizeof(uint32_t), "            idle_time_us          : %u\n");
  ret |= print_value(addr + 3 * sizeof(uint32_t), "            capabilities          : 0x%X");
  return ret;
}

// ... including padding
#define SIZE_GLOBAL (16)
#define SIZE_CONTAINER (32)
#define SIZE_AGGR (16)

int  cl6000_umac_config_show()
{
  int ret = 0 ;
  uint32_t value;
  uint32_t addr;
  printf("\numac config\n");
  if (cl_usb_read32(CL6000_UMAC_CONFIG, &value)) {
    TEST_INFO("\n*** cannot read config!\n");
    return 1;
  }
  printf("    GLOBAL_REGS:\n        [0x%08x]\n", CL6000_UMAC_CONFIG);
  cl_usb_read32(CL6000_UMAC_CONFIG, &value);
  printf("        magic_version : 0x%04x - 0x%04x\n", (value & 0xFFFF0000) >> 16, value & 0xFFFF);
  cl_usb_read32(CL6000_UMAC_CONFIG + 0x4, &value);
  printf("        file_size     : %u\n", value);
  cl_usb_read32(CL6000_UMAC_CONFIG + 0x8, &value);
  printf("        usb_profile   : %u\n", value);
  cl_usb_read32(CL6000_UMAC_CONFIG + 0xC, &value);
  printf("        usb_caps      : 0x%08X\n", value);

  addr = CL6000_UMAC_CONFIG + SIZE_GLOBAL;

  printf("    US_CONT_U0_REGS:\n        [0x%08x]\n", addr);
  ret |= usb_print_container_regs(addr, 0);
  addr += SIZE_CONTAINER;

  printf("    US_CONT_U5_REGS:\n        [0x%08x]\n", addr);
  ret |= usb_print_container_regs(addr, 1);
  addr += SIZE_CONTAINER;

  printf("    DS_AGGR_D0_REGS:\n        [0x%08x]\n", addr);
  ret |= usb_print_aggr_regs(addr, 0);
  addr += SIZE_AGGR;

  printf("    DS_AGGR_D1_REGS:\n        [0x%08x]\n", addr);
  ret |= usb_print_aggr_regs(addr, 1);
  addr += SIZE_AGGR;

  printf("    DS_AGGR_D2_REGS:\n        [0x%08x]\n", addr);
  ret |= usb_print_aggr_regs(addr, 2);
  addr += SIZE_AGGR;

  printf("    DS_AGGR_D3_REGS:\n        [0x%08x]\n", addr);
  ret |= usb_print_aggr_regs(addr, 3);
  addr += SIZE_AGGR;

  printf("    DS_AGGR_D4_REGS:\n        [0x%08x]\n", addr);
  ret |= usb_print_aggr_regs(addr, 4);
  addr += SIZE_AGGR;

  printf("    DS_AGGR_D5_REGS:\n        [0x%08x]\n", addr);
  ret |= usb_print_aggr_regs(addr, 5);
  addr += SIZE_AGGR;

  printf("    LLI Config U0..U15 [0x%08X]:\n", addr);
   cl_usb_read32(addr, &value);
  printf("        u0_u3   : 0x%08X\n", value);
   cl_usb_read32(addr + 0x04, &value);
  printf("        u4_u7   : 0x%08X\n", value);
   cl_usb_read32(addr + 0x08, &value);
  printf("        u8_u11  : 0x%08X\n", value);
   cl_usb_read32(addr + 0xc, &value);
  printf("        u12_u15 : 0x%08X\n", value);
  addr += 0x10;

  printf("    LLI Config D0..U7 [0x%08X]:\n", addr);
   cl_usb_read32(addr, &value);
  printf("        d0_d3   : 0x%08X\n", value);
   cl_usb_read32(addr + 0x4, &value);
  printf("        d4_d7   : 0x%08X\n", value);
  addr += 0x10;

 return ret;
}

int usb_read_umac_wifi_statistic(EMC_USB_CELENO_Statistics* stats){
  uint32_t stats_location;
    if (cl_usb_read32(CL6000_LOCAL_SRAM_BASE + CL6000_OFFSET_STATS_LOC, &stats_location)) {
    TEST_INFO("\n*** cannot read statistics location!\n");
    return 1;
  }
  if (cl_usb_burst_read(stats_location, stats, sizeof(EMC_USB_CELENO_Statistics), true)) {
    TEST_INFO("\n*** cannot read statistics!\n");
    return 1;
  }
  if (stats->version != EMC_USB_CELENO_UMAC_STATISTICS_VERSION) {
    TEST_INFO("\n*** statistics version mismatch, exp 0x%08X, got 0x%08X!\n", EMC_USB_CELENO_UMAC_STATISTICS_VERSION, stats->version);
    return 1;
  }
  if (stats->size != sizeof(EMC_USB_CELENO_Statistics)) {
    TEST_INFO("\n*** statistics size mismatch, exp %" PRIuPTR ", got %u!\n", sizeof(EMC_USB_CELENO_Statistics), stats->size);
    return 1;
  }
  return 0;
}

#define UMAC_CYCLES_PER_MICRO_SECOND 640.0
double ticks2us(uint32_t ticks)
{
  double us = ticks / UMAC_CYCLES_PER_MICRO_SECOND;
  return us;
}

double avg2us(uint64_t sum, uint32_t cnt)
{
  double us = sum / UMAC_CYCLES_PER_MICRO_SECOND;
  us /= cnt;
  return us;
}


void usb_print_umac_wifi_statistic_lli(EMC_USB_CELENO_Statistics* stats, uint32_t lli_index, int upstream)
{
  EMC_USB_CELENO_Statistics_LLI* stats_lli= upstream? &stats->lli_ul[lli_index]: &stats->lli_dl[lli_index] ;

  TEST_INFO("\n*** UMAC Statistics V %u\n", stats->version);
  TEST_INFO("  %s LLI #%u PDMA:\n",upstream?"UL":"DL", lli_index);
  TEST_INFO("    GET    %u\n", stats_lli->pdma_get);
  TEST_INFO("    DONE   %u\n", stats_lli->pdma_done);
  TEST_INFO("    FAILED %u\n", stats_lli->pdma_done_error);

  TEST_INFO("    Pending interval:\n");
  TEST_INFO("      Initial %.3lf us (%u ticks)\n", ticks2us(stats_lli->pdma_pending_initial), stats_lli->pdma_pending_initial);
  TEST_INFO("      Average %.3lf us (%" PRIu64 " ticks for %u pDMAs)\n",
            avg2us(stats_lli->pdma_pending_range.avg_sum, stats_lli->pdma_pending_range.avg_cnt),
            stats_lli->pdma_pending_range.avg_sum, stats_lli->pdma_pending_range.avg_cnt);
  TEST_INFO("      Minimum %.3lf us (%u ticks) @%u\n",
            ticks2us(stats_lli->pdma_pending_range.min), stats_lli->pdma_pending_range.min, stats_lli->pdma_done_pending_min);
  TEST_INFO("      Maximum %.3lf us (%u ticks) @%u\n",
             ticks2us(stats_lli->pdma_pending_range.max), stats_lli->pdma_pending_range.max, stats_lli->pdma_done_pending_max);

}

void usb_print_umac_wifi_statistic(EMC_USB_CELENO_Statistics* stats){
  TEST_INFO("\n*** UMAC Statistics V %u\n", stats->version);
  TEST_INFO("   |        |        |        |                Pending interval                          \n" );
  TEST_INFO("LLI|  #GET  | #DONE  |  #ERR  | Initial [us] | Average [us] |     Min[us] @#pdma  |      Max[us] @#pdma \n" );

  for(uint32_t upstream = 0; upstream < 2; upstream++) {
    for (uint32_t lli=0;lli<16;lli++){
      EMC_USB_CELENO_Statistics_LLI* stats_lli= upstream? &stats->lli_ul[lli]: &stats->lli_dl[lli] ;
      if (stats_lli->pdma_pending_range.avg_cnt > 0) {
        TEST_INFO("%s%02u| %6u | %6u | %6u |   %10.3lf |   %10.3lf |   %10.3lf@%6u | %10.3lf@%6u \n",
                      upstream ? "U" : "D", lli, stats_lli->pdma_get, stats_lli->pdma_done, stats_lli->pdma_done_error,
                      ticks2us(stats_lli->pdma_pending_initial), avg2us(stats_lli->pdma_pending_range.avg_sum, stats_lli->pdma_pending_range.avg_cnt),
                      ticks2us(stats_lli->pdma_pending_range.min),  stats_lli->pdma_done_pending_min,
                      ticks2us(stats_lli->pdma_pending_range.max),  stats_lli->pdma_done_pending_max
                      );
      }else{
        TEST_INFO("%s%02u| %6u | %6u | %6u |              |              |                     |                     \n",
                      upstream ? "U" : "D", lli, stats_lli->pdma_get, stats_lli->pdma_done, stats_lli->pdma_done_error);

      }
    }
  TEST_INFO("\n" );
  }
}

static bool is_timeout(time_t start,int32_t timeout_seconds){
  if (difftime(time(NULL),start)  > timeout_seconds ){
    return true;
  }
  return false;
}

bool usb_wrapper_test_wait_running(int fd_driver, int32_t timeout_seconds)
{
    uint32_t test_status=USBW_STATUS_IDLE;
    time_t start = time(NULL);
    cl_usb_read32(test_status_base_addr() + WRAPPER_TEST_STATUS_STATE_OFFSET, &test_status);
    while((test_status != USBW_STATUS_STARTED) && !is_timeout(start,timeout_seconds)){
      sleep(1);
      cl_usb_read32(test_status_base_addr() + WRAPPER_TEST_STATUS_STATE_OFFSET, &test_status);
    }
    if (is_timeout(start, timeout_seconds)){
      TEST_INFO("*** Timeout, test not started\n");
      return false;
    }

    return true;
}

bool usb_wrapper_test_wait_finished(int fd_driver, int32_t timeout_seconds)
{
    TEST_INFO("\n        Running ");
    uint32_t test_status=0;
    cl_usb_read32(test_status_base_addr() + WRAPPER_TEST_STATUS_STATE_OFFSET, &test_status);
    time_t start = time(NULL);
    usb_test_keepalive_driver(fd_driver, 0);
    int i = 0;
    while((test_status != USBW_STATUS_FINISHED) && !is_timeout(start,timeout_seconds)){
        sleep(1);
        if ((i % 5) == 0) {
          usb_test_keepalive_driver(fd_driver, 0);
          TEST_INFO(".");
        }
        cl_usb_read32(test_status_base_addr() + WRAPPER_TEST_STATUS_STATE_OFFSET, &test_status);
        fflush(stdout);
        i++;
    }

    if (is_timeout(start, timeout_seconds)){
        TEST_INFO("*** Timeout, test not finished");
        return false;
    }
    return true;
}

int usb_test_check_driver_loaded()
{
  FILE *fp;
  char output[128];
  int result = -1;

  /* Open the command for reading. */
  fp = popen("/sbin/lsmod", "r");
  if (fp == NULL) {
     TEST_INFO("*** failed to check driver state");
    return -2;
  }

  /* Read the output a line at a time - output it. */
  while (fgets(output, sizeof(output), fp) != NULL) {
    if (strstr(output,"usbtpt") != NULL ){
        result = 0;
    }
  }

  pclose(fp);
  return result;
}

struct tpt_statistics* usb_test_driver_statistic() {
    return &usb_test_statistic;
}

int do_keep_alive(int fd_driver) {
  int io_result;
  if (boot_drv_usb_cfg()->verbose) {
    TEST_INFO("\n      keep alive ...");
  }
  io_result=usb_test_driver_call_ioctl(fd_driver, TPT_KEEP_ALIVE, 0);
  if(io_result < 0){
    TEST_INFO("\n  keep alive failed: %u",io_result);
  }
  return io_result;
}
  
int usb_test_keepalive_driver(int fd_driver, int duration_sec) {
  if (duration_sec == 0) {
    return do_keep_alive(fd_driver);
  } else {
    int io_result = 0;
    for (int i = duration_sec; i > 0; i--) {
      io_result = do_keep_alive(fd_driver);
      sleep(1);
    }
    return io_result;
  }
}

void usb_test_stop_driver(int fd_driver)
{
    struct tpt_status tpt_status;

    usb_test_driver_call_ioctl(fd_driver, TPT_STOP, NULL);
    while (1) {
        usb_test_driver_call_ioctl(fd_driver, TPT_GET_STATUS, &tpt_status);
        if (tpt_status.is_running == 0) {
            break;
        }else{
          usleep(500000);
          fprintf(stderr, ".");
        }
    }
    usb_test_driver_call_ioctl(fd_driver, TPT_GET_STATISTICS, &usb_test_statistic);
}

void usb_test_wifi_set_alternate_setting(int fd_driver,int32_t alt_setting)
{
  struct tpt_alternate_setting as;
  as.alt_setting = alt_setting;
  usb_test_driver_call_ioctl(fd_driver, TPT_SET_ALT_SETTING, &as);
}

void usb_test_close_driver(int fd_driver)
{
  close(fd_driver);
}

void usb_wrapper_test_write_request(struct USBW_TestControlRequest* request)
{
    TEST_INFO("\n        Preparing ...");
    cl_usb_burst_write(test_control_base_addr(), request, sizeof(struct USBW_TestControlRequest), true);
}

void usb_wrapper_test_write_request_at(uint32_t addr,struct USBW_TestControlRequest* request)
{
    //TEST_INFO("\n        Write test request ...\n");
    cl_usb_burst_write(addr, request, sizeof(struct USBW_TestControlRequest), true);
}

int usb_wrapper_test_stop(int fd_driver, struct tpt_statistics* host_stat)
{
  uint32_t test_status=0;

  usb_test_stop_driver(fd_driver);

  if (host_stat){
    usb_test_driver_call_ioctl(fd_driver, TPT_GET_STATISTICS, host_stat);
  }
  usb_test_close_driver(fd_driver);
  cl_usb_write32(test_control_base_addr() + WRAPPER_TEST_CONTROL_REQUEST_OFFSET, USBW_IDLE);
  cl_usb_read32(test_status_base_addr() + WRAPPER_TEST_STATUS_STATE_OFFSET, &test_status);

  if ((test_status == USBW_STATUS_IDLE) || (test_status == USBW_STATUS_FINISHED)){
    return 1;
  }
  return 0;
}


int usb_wrapper_is_bluetooth_channel(struct USBW_TestControlRequest* req)
{
   if (req->direction == USBW_DOWN_STREAM){
     if (req->lli_channel == 10 ||
         req->lli_channel ==  9 ||
         req->lli_channel ==  8  ){
       return 1;
     }
   } else {
     if (req->lli_channel == 8 ||
         req->lli_channel == 7 ||
         req->lli_channel == 6 ){
       return 1;
     }
   }
  return 0;
}

int usb_wrapper_is_bluetooth_channel_sco(struct USBW_TestControlRequest* req)
{
   if ((req->direction == USBW_DOWN_STREAM) && (req->lli_channel ==  9)) {
     return 1;
   }
   if ((req->direction == USBW_UP_STREAM) && (req->lli_channel ==  7)) {
     return 1;
   }
  return 0;
}

static int is_raw_mode(struct USBW_TestControlRequest* req)
{
   if ((req->direction == USBW_DOWN_STREAM) ) {
     return (req->lli_channel <= 5) ? false: true;
   }else{
     if (req->lli_channel == 0 || req->lli_channel == 5){
       return false;
     }
     return true;
   }
}

int usb_test_open_driver(struct USBW_TestControlRequest* req)
{
  int ifc_index = 0;
  char device_name[64];
  if (usb_wrapper_is_bluetooth_channel(req)){
    if (usb_wrapper_is_bluetooth_channel_sco(req)){
      ifc_index = 2;
    } else {
      ifc_index = 1;
    }
    if (!CL6000_UMAC_APP_HAS_WIFI(cl_usb_get_fw_version())) {
      ifc_index--;
    }
  }
  snprintf(device_name, sizeof(device_name), "/dev/usbtpt%d", ifc_index & 0xF);
  return open(device_name, O_RDWR);
}

struct tpt_start usb_wrapper_test_get_tpt_start(struct USBW_TestCase* tc){
  struct USBW_TestControlRequest* req = &(tc->control_request);
  struct tpt_start start_param = {
      .mode = 0xff,
      .alt_setting = 0,
      .runtime = 90,
      .raw_packets = 1};

  if (usb_wrapper_is_bluetooth_channel_sco(req)) {
    start_param.alt_setting = 1;
  }
  start_param.raw_packets = is_raw_mode(req);
  return start_param;
}

struct tpt_parameter usb_wrapper_test_get_tpt_param(struct USBW_TestCase* tc, int no_sg) {
  struct USBW_TestControlRequest* req = &(tc->control_request);
  struct tpt_parameter param = {};
  EMC_CELENO_DOWNSTREAM_AGGR_Param* ds_aggr=(EMC_CELENO_DOWNSTREAM_AGGR_Param*)&tc->param.param[0];

  param.in_ep = 0;
  param.out_ep = 0;
  param.chunk_size = 1600;
  param.chunk_count = 16;

  param.packets_to_transfer = 0;
  param.flags = 0;
  param.buffer_count = 4;
  param.verify_content = (req->packets.pattern != USBW_DONT_CARE) ? 1 : 0;

  if (usb_wrapper_is_bluetooth_channel(req)){
    param.chunk_count = 1;
    param.buffer_count = 1;
  }

  if (tc->schedule_all_ep) {
    param.flags |= TPT_PARAM_FLAG_SCHEDULE_UNUSED_EPS;
  }
  if (no_sg) {
    param.flags |= TPT_PARAM_FLAG_NO_SG;
  }
  if (tc->param.type == USBW_DS_AGGR_REG){
    if (ds_aggr->capabilities == EMC_CELENO_AGGR_OpMode_pad_pdmas ){
        param.flags |= TPT_PARAM_FLAG_PAD_OUT_CHUNKS;
    }
    if (ds_aggr->capabilities == EMC_CELENO_AGGR_OpMode_no_xfer_split ){
        param.flags |= TPT_PARAM_FLAG_NO_TRANSFER_SPLIT;
        param.chunk_count= ds_aggr->host_transfer_packets;
        param.usb_packet_chunks = ds_aggr->max_pdmas_per_usb_packet;
    }

  }
  if (req->direction == USBW_UP_STREAM) {
    param.in_ep = req->ep;
  } else {
    param.out_ep = req->ep;
    param.chunk_size = req->packets.number_bytes / req->packets.packet_count;
    if ((ds_aggr->capabilities == EMC_CELENO_AGGR_OpMode_buffered) || 
        (ds_aggr->capabilities == EMC_CELENO_AGGR_OpMode_buffered_tci_split) || 
        (ds_aggr->capabilities == EMC_CELENO_AGGR_OpMode_buffered_tci_nonstd)){
      param.packets_to_transfer = req->packets.packet_count;
      param.flags |= TPT_PARAM_FLAG_ALWAYS_ZLP;
    }
    if(is_raw_mode(req)) {
      param.chunk_count = 1;
      if(param.verify_content){
        param.buffer_count = 1;
       }
     }
  }
  return param;
}

int usb_wrapper_test_start_host_driver_with_param(struct USBW_TestCase* tc,struct tpt_start* start_param, struct tpt_parameter* param)
{
  struct USBW_TestControlRequest* req = &(tc->control_request);
  int fd = usb_test_open_driver(req);
  if (fd < 0) {
    TEST_INFO("*** error open driver: %s, code %d\n", strerror(-fd), fd);
    return fd;
  }

  usb_test_driver_call_ioctl(fd, TPT_SET_PARAMETER, param);
  usb_test_driver_call_ioctl(fd, TPT_START, start_param);

  return fd;

}

int usb_wrapper_test_start_host_driver(struct USBW_TestCase* tc, int no_sg)
{
  struct tpt_start start_param =  usb_wrapper_test_get_tpt_start(tc);
  struct tpt_parameter param = usb_wrapper_test_get_tpt_param(tc, no_sg);
  return usb_wrapper_test_start_host_driver_with_param(tc, &start_param, &param);
}

int apre_usb_core_test() {
  return cl_usb_umac_restart(boot_drv_usb_cfg()->umac_disconnect_delay_ms, boot_drv_usb_cfg()->umac_restart_delay_ms, CL6000_LOCAL_UMAC_IRAM_BASE());
}

int apre_usb_cli_test()
{
  int result = FAILED;
  result = usb_test_restart_reconnect_umac();
  if (result != 0) {
    return FAILED;
  }

  TEST_INFO("Umac USB CLI test - running ...\n");
  cl_usb_close();
  result = cl_usb_self_test(REG_LOGGER_RAM_BASE_ADDR, cl_get_usb_config());
  if (result != 0) {
    TEST_INFO("\nCLI Test FAIL\n");
    return FAILED;
  }


  TEST_INFO("\nCLI Test SUCCESS\n");

  cl_usb_open_pretty_print(cl_get_usb_config());

  return PASSED;
}

uint32_t ds_agg_addr(int lli) {
  switch (lli) {
    case 0 : return DS_AGGR_D0_REGS_ADDR;
    case 1 : return DS_AGGR_D1_REGS_ADDR;
    case 2 : return DS_AGGR_D2_REGS_ADDR;
    case 3 : return DS_AGGR_D3_REGS_ADDR;
    case 4 : return DS_AGGR_D4_REGS_ADDR;
    case 5 : return DS_AGGR_D5_REGS_ADDR;
    default:  
      TEST_INFO("****ERROR invalid lli index");
      return 0;
  }
}


int read_umac_ds_register(uint32_t register_addr,EMC_CELENO_DOWNSTREAM_AGGR_Param*  regs)
{
  return cl_usb_burst_read(register_addr, regs, sizeof(EMC_CELENO_DOWNSTREAM_AGGR_Param), false);
}

int write_umac_ds_register(uint32_t register_addr,EMC_CELENO_DOWNSTREAM_AGGR_Param*  regs)
{
  return cl_usb_burst_write(register_addr, regs, sizeof(EMC_CELENO_DOWNSTREAM_AGGR_Param), false);
}

int usbw_reset_wifi(int fd_driver) 
{
  TEST_INFO("        Clear shared test control/status memory");
  usb_test_stop_driver(fd_driver);
  macsys_gcu_xt_control_lmac_run_stall_setf(1); // 0x607C50F0

  usb_wrapper_clear_control_area();

  usb_test_wifi_set_alternate_setting(fd_driver, 1);

  usb_test_close_driver(fd_driver);

  TEST_INFO("\n        Reload/Reset LMAC");
  return 0;
}

int load_start_lmac_smac(const char* lmac_fw_name, const char* smac_fw_name)
{
  if (lmac_fw_name) {
    load_and_start_lmac_fw(lmac_fw_name);
  } else if (smac_fw_name) {
    load_and_start_smac_fw(smac_fw_name);
  } else {
    TEST_INFO("\n*** Neither lmac nor smac firmware specified.\n");
    return -1;
  }
  return 0;
}  
