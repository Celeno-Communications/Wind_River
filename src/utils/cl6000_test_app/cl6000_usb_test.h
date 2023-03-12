/**
 ****************************************************************************************
 *
 * @file cl6000_usb_test.h
 *
 * @brief CL6000 UMAC USB test related test infrastructure.
 *
 * Copyright (C) Emsys/Celeno 2021
 *
 ****************************************************************************************
 */

#ifndef CL6000_USB_TEST_H_
#define CL6000_USB_TEST_H_

#include "cl6000_common.h"
#include "usbtpt.h"
#include "RegisterSet.h"


uint32_t CL6000_LMAC_RAM_ADDR();
uint32_t CL6000_LMAC_RAM_SIZE();
uint32_t CL6000_LMAC_DRAM_ADDR();
uint32_t CL6000_LMAC_DRAM_SIZE();
uint32_t CL6000_LMAC_IRAM_ADDR();
uint32_t CL6000_LMAC_IRAM_SIZE();
uint32_t CL6000_LOCAL_LMAC_IRAM_OFFSET();

uint32_t CL6000_SMAC_RAM_ADDR();
uint32_t CL6000_SMAC_RAM_SIZE();  
uint32_t CL6000_SMAC_DRAM_ADDR();
uint32_t CL6000_SMAC_DRAM_SIZE();
uint32_t CL6000_SMAC_IRAM_ADDR();
uint32_t CL6000_SMAC_IRAM_SIZE();
uint32_t CL6000_LOCAL_SMAC_IRAM_OFFSET();


uint32_t CL6000_UMAC_RAM_ADDR (); 
uint32_t CL6000_UMAC_RAM_SIZE (); 
uint32_t CL6000_UMAC_DRAM_ADDR ();
uint32_t CL6000_UMAC_DRAM_SIZE ();
uint32_t CL6000_UMAC_IRAM_ADDR ();
uint32_t CL6000_UMAC_IRAM_SIZE ();


#define WRAPPER_TEST_CONTROL_STATUS_SIZE 0x1000
#define UMAC_WRAPPER_TEST_CONTROL_BASE 0x60001000
#define UMAC_WRAPPER_TEST_STATUS_BASE  0x60001800
#define LMAC_WRAPPER_TEST_CONTROL_BASE 0x60002000
#define LMAC_WRAPPER_TEST_STATUS_BASE  0x60003000
#define SMAC_WRAPPER_TEST_CONTROL_BASE 0x60004000
#define SMAC_WRAPPER_TEST_STATUS_BASE  0x60005000

#include "cl6000_fw_test.h"
#include "cl6000_usb_test_wrapper_priv.h"
#include "Statistics.h"


/** The function index to reach this function */
#define EMC_USB_CELENO_Wifi_IOCTL_INDEX 0x00

/** enable normal statistics counter */
#define EMC_USB_CELENO_Wifi_IOCTL_CFG_STATISTICS_STAT (1U << 0)
/** enable performance counting */
#define EMC_USB_CELENO_Wifi_IOCTL_CFG_STATISTICS_PERF (1U << 1)

/**
 * Function IOCTL interface accessed by CLI command
 */
enum EMC_USB_CELENO_Wifi_IOCTL {
  /** reset the statistics
   * No parameters
   * No results
   */
  EMC_USB_CELENO_Wifi_IOCTL_RESET_STATISTICS     = 1,
  /** configure statistics
   * param1: a combination of EMC_USB_CELENO_Wifi_IOCTL_CFG_STATISTICS_xxx
   *         to enable the statistics type or 0 to turn it off
   * No results
   */
  EMC_USB_CELENO_Wifi_IOCTL_CONFIGURE_STATISTICS = 2,
  /** enable Watchdog
   * param1: "1" enabled the WD, "0" disables
   * param2: WD timeout in ms
   * No results
   */
  EMC_USB_CELENO_Wifi_IOCTL_ENABLE_WD = 3
};

// print info for all wrapper tests to stdout
void usb_wrapper_test_list();
// print info for all reset tests to stdout
void usb_wifireset_test_list();

// wait for test indication until timeout occurs
int usb_wait_4_test_end_ind(uint32_t timeout_s, uint32_t test_end_ind_addr);

// print info for all tput tests to stdout
void usb_tput_test_list();
// read list with testcases
int usb_test_select_by_file(FILE* fp);

// remove leading/trailing whitespace from string
char *trimwhitespace(char *str);

// list with test case tags
#define USB_MAX_TESTCASES 512
#define USB_TESTCASES_TAG_LEN 64
typedef struct usb_tc_tags_s{
  char tag[USB_TESTCASES_TAG_LEN];
  double override_perf_limit;
} usb_tc_tags_t;

extern usb_tc_tags_t usb_tc_tags[USB_MAX_TESTCASES];
extern size_t usb_test_tags;

int apre_usb_core_test();
int apre_usb_cli_test();
int apre_usb_tp_test();
int apre_usb_wifireset_test();
int apre_usb_ecm_test();
int apre_usb_udp_test();


struct tpt_start usb_wrapper_test_get_tpt_start(struct USBW_TestCase* tc);
struct tpt_parameter usb_wrapper_test_get_tpt_param(struct USBW_TestCase* tc, int no_sg);

int usb_wrapper_is_bluetooth_channel(struct USBW_TestControlRequest* req);
int usb_wrapper_is_bluetooth_channel_sco(struct USBW_TestControlRequest* req);
int usb_wrapper_test_start_host_driver(struct USBW_TestCase* req, int no_sg);
int usb_wrapper_test_start_host_driver_with_param(struct USBW_TestCase* tc, struct tpt_start* start, struct tpt_parameter* param);
void usb_wrapper_test_write_request(struct USBW_TestControlRequest* request);
void usb_wrapper_test_write_request_at(uint32_t addr,struct USBW_TestControlRequest* request);


void usb_wrapper_clear_control_area();
int usb_wrapper_test_wait_host_received_all_data(int driver,struct USBW_TestControlRequest* request,int32_t timeout_seconds);
bool usb_wrapper_test_wait_finished(int fd_driver, int32_t timeout_seconds);
bool usb_wrapper_test_wait_running(int fd_driver, int32_t timeout_seconds);

int usb_read_umac_wifi_statistic(EMC_USB_CELENO_Statistics* stats);
void usb_print_umac_wifi_statistic_lli (EMC_USB_CELENO_Statistics* stats, uint32_t lli_index, int upstream);
void usb_print_umac_wifi_statistic (EMC_USB_CELENO_Statistics* stats);
int usb_print_aggr_regs(uint32_t addr, uint8_t lli_index);
int usb_print_container_regs(uint32_t addr, uint8_t lli_index);
int cl6000_umac_config_show();

int usb_wrapper_test_stop(int fd_driver,struct tpt_statistics* host_stat);
void usb_test_stop_driver(int fd_driver);
int  usb_test_open_driver(struct USBW_TestControlRequest* req);
void usb_test_close_driver(int fd_driver);
void usb_test_wifi_set_alternate_setting(int fd_driver,int32_t alt_setting);
int usb_test_keepalive_driver(int fd_driver, int duration_sec);

int usb_test_restart_reconnect_umac();
int usb_test_check_driver_loaded();
struct tpt_statistics* usb_test_driver_statistic();
int usb_test_driver_call_ioctl(int fd, unsigned long request, void* param);

/// return if firmware is loaded
int is_lmac_running();
int is_smac_running();

// return base addresses for TestControl/Status structures for the xtensa core currently running the wrapper test
uint32_t test_control_base_addr();
uint32_t test_status_base_addr();

uint32_t usb_wrapper_test_evaluate(uint32_t statusbase, struct USBW_TestCase* tc,struct tpt_statistics* host_stat, CL_USB_SPEED speed);

// load and start lmac with given binary
void load_and_start_lmac_fw(const char* fw_name);
// load and start smac with given binary
void load_and_start_smac_fw(const char* fw_name);

/** Opens cli usb channel for USB device and pretty prints version info of the newly opened device
 * @return >=0 on success */
int cl_usb_open_pretty_print(const CLI_USB_Config* config);

#define DS_AGGR_D0_REGS_ADDR (0x4002FF50)
#define DS_AGGR_D1_REGS_ADDR (0x4002FF60)
#define DS_AGGR_D2_REGS_ADDR (0x4002FF70)
#define DS_AGGR_D3_REGS_ADDR (0x4002FF80)
#define DS_AGGR_D4_REGS_ADDR (0x4002FF90)
#define DS_AGGR_D5_REGS_ADDR (0x4002FFA0)

uint32_t ds_agg_addr(int lli);


// read umac register for lli channel
int read_umac_ds_register(uint32_t register_addr, EMC_CELENO_DOWNSTREAM_AGGR_Param* regs);
// write umac register for lli channel
int write_umac_ds_register(uint32_t register_addr, EMC_CELENO_DOWNSTREAM_AGGR_Param* regs);

int load_start_lmac_smac(const char* lmac_fw_name, const char* smac_fw_name);

int usbw_reset_wifi();
#endif // CL6000_USB_TEST_H_
