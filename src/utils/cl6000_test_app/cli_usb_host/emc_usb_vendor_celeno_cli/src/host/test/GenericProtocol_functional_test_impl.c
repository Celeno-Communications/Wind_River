/**
 * @file
 * @brief   Generic Protocol functional test as unit tests
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/system/celeno/configure.h"

#include "emc/usb/vendor/celeno/cli/host/FunctionProxy.h"
#include "emc/usb/vendor/celeno/cli/host/FunctionProxy_private.h"
#include "emc/usb/vendor/celeno/cli/host/Error.h"

#include "emc/usb/vendor/celeno/cli/device/Function.h"

#include "emc/usb/host/hal/HAL.h"

#include "emc/usb/vendor/celeno/cli/host/test/GenericProtocol_functional_test_impl.h"

#ifdef EMC_TEST_GREYBOX
#  include "emc/usb/vendor/celeno/cli/device/test/DeviceMock.h"
#  include "emc/usb/vendor/celeno/cli/TargetMemory.h"
#  include "emc/usb/vendor/celeno/cli/TargetMemoryDump.h"
#endif /*EMC_TEST_GREYBOX*/

#include "emc/test/unittest.h"
#include "emc/std/string.h"
#include "emc/std/stdlib.h"

#include "emc/log/log.h"

#if EMC_LOG_LOGGING_VARIANT == EMC_LOG_LOGGING_EMCPP
#  include "emcpp/log/LoggerSystem.h"
static void configure_emcpp_logging(void)
{
  //EMC_LoggerSystem_create_memory_appender("root", sizeof(log_memory), log_memory);
  EMC_LoggerSystem_create_stdio_appender("root", "stderr");
  EMC_LoggerSystem_logger_set_attribute("", EMC_LOG_ATTRIBUTE_APPENDER, "root");
}

#endif

static EMC_USB_CELENO_CLI_FunctionProxy function_proxy;

#define CHECK_VALID 1
#define CHECK_INVALID 0

emc_std_uint32_t target_memory_begin = 0;
emc_std_uint32_t target_memory_end = 0;

uint32_t ram_base_address = 0;
uint32_t transfer_timeout_ms = 1000;
uint16_t usb_pid = 0;
char     usb_sn[256];

int device_enumerated = 0;
int host_enumerated = 0;
int run_count = 0;

static int EMC_USB_CELENO_CLI_FunctionProxy_reset_wrapper(EMC_USB_CELENO_CLI_FunctionProxy* self)
{
  int error;
#ifdef EMC_TEST_GREYBOX
  EMC_USB_CELENO_CLI_FunctionProxy_reset(self);
  set_alt_setting(0, 1);
  error = !set_alt_setting(0, 0);
#else
  error = EMC_USB_CELENO_CLI_FunctionProxy_reset(self);
#endif
  return error;
}

static int enumerated(void)
{
  return device_enumerated && host_enumerated;
}

static int create_and_enumerate_host(void)
{
  int                    error;
  EMC_USB_HOST_HAL_Error host_error = EMC_USB_HOST_HAL_init();
  if (host_error == EMC_USB_HOST_HAL_Error_NONE) {
    EMC_USB_CELENO_CLI_FunctionProxyConfig config;
    EMC_USB_CELENO_CLI_FunctionProxyConfig_init(&config);
    config.transfer_timeout_ms = transfer_timeout_ms;
    config.pid = usb_pid;
    config.sn = (uint8_t*)(strlen(usb_sn) ? usb_sn : 0);
    error = EMC_USB_CELENO_CLI_FunctionProxy_init(&function_proxy, &config);
    if (!error) {
      error = EMC_USB_CELENO_CLI_FunctionProxy_start(&function_proxy);
    }
    return error ? 0 : 1;
  } else {
    return 0;
  }
}

static void destroy_host(void)
{
  EMC_USB_CELENO_CLI_FunctionProxy_stop(&function_proxy);
  EMC_USB_CELENO_CLI_FunctionProxy_exit(&function_proxy);
  EMC_USB_HOST_HAL_exit();
}

void setUp(void)
{
#if EMC_LOG_LOGGING_VARIANT == EMC_LOG_LOGGING_EMCPP
  configure_emcpp_logging();
#endif
#ifdef EMC_TEST_GREYBOX
  {
    // for experimental logger configuration
    //EMC_Log_set_priority(EMC_Log_logger("emc.usb.dev"),EMC_LOG_PRIORITY_WARN);
    //EMC_Log_set_priority(EMC_Log_logger("emc.usb.dev.hw"),EMC_LOG_PRIORITY_TRACE);
    //EMC_Log_set_priority(EMC_Log_logger("emc.usb.dev.cli"),EMC_LOG_PRIORITY_TRACE);
    //EMC_Log_set_priority(EMC_Log_logger("emc.usb.host.cli"),EMC_LOG_PRIORITY_ERROR);
  }

  EMC_USB_CELENO_CLI_TargetMemory_init(EMC_USB_VENDOR_CELENO_TARGET_DRAM_MEMORY_SIZE);
  target_memory_begin = EMC_USB_CELENO_CLI_TargetMemory_begin();
  device_enumerated = create_and_enumerate_device();
#else
  target_memory_begin = ram_base_address;
  device_enumerated = 1;
#endif /*EMC_TEST_GREYBOX*/
  target_memory_end = target_memory_begin + EMC_USB_VENDOR_CELENO_TARGET_DRAM_MEMORY_SIZE;

  host_enumerated = create_and_enumerate_host();

  // run the first tests without reset
  if (run_count >= 2) {
    EMC_USB_CELENO_CLI_FunctionProxy_reset_wrapper(&function_proxy);
  }
  ++run_count;
}

void tearDown(void)
{
  destroy_host();
#ifdef EMC_TEST_GREYBOX
  destroy_device();
  EMC_USB_CELENO_CLI_TargetMemory_exit();
#endif /*EMC_TEST_GREYBOX*/
}

#ifdef EMC_TEST_GREYBOX
EMC_CUNIT_START_TEST(GenericProtocol_functional_test_unconfigure_configure) {
  EMC_CUNIT_ASSERT(enumerated());

  {
    int success;
    success = configure_device(0);
    EMC_CUNIT_ASSERT(success);

    success = configure_device(1);
    EMC_CUNIT_ASSERT(success);
  }
}
EMC_CUNIT_END_TEST
#endif /*EMC_TEST_GREYBOX*/

EMC_CUNIT_START_TEST(GenericProtocol_functional_test_init_cfg)
{
  EMC_USB_CELENO_CLI_FunctionProxyConfig config;
  EMC_USB_CELENO_CLI_FunctionProxyConfig config_ref;

  emc_std_memset(&config, 0xA5, sizeof(config));
  EMC_USB_CELENO_CLI_FunctionProxyConfig_init(&config);

  emc_std_memset(&config_ref, 0x0, sizeof(config_ref));
  config_ref.transfer_timeout_ms = 1000;

  EMC_CUNIT_ASSERT(0 == emc_std_memcmp(&config_ref, &config, sizeof(config)));
}

EMC_CUNIT_START_TEST(GenericProtocol_functional_test_keep_alive) {
  int error;
  EMC_CUNIT_ASSERT(enumerated());
  EMC_CUNIT_ASSERT(EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy));

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);

  EMC_CUNIT_ASSERT(!error);
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(GenericProtocol_functional_test_get_version)
{
  int error;

  uint32_t protocol_version;
  uint32_t firmware_version;

  EMC_CUNIT_ASSERT(enumerated());

  error = EMC_USB_CELENO_CLI_FunctionProxy_get_version(&function_proxy, &protocol_version, &firmware_version);

  EMC_CUNIT_ASSERT(!error);
  EMC_CUNIT_ASSERT(protocol_version >= 0x00000104); // Bootrom RC1 version is minimum.
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(GenericProtocol_functional_test_reset)
{
  int error;

  EMC_CUNIT_ASSERT(enumerated());

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_reset_wrapper(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(GenericProtocol_functional_test_logger_level_get)
{
  int              error;
  emc_std_uint32_t index;
  emc_std_uint32_t level;

  EMC_CUNIT_ASSERT(enumerated());

  index = 0;
  for (;; ++index) {
    error = EMC_USB_CELENO_CLI_FunctionProxy_logger_level_get(&function_proxy, index, &level);
    if (EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_STATUS == error) {
      break;
    }
    EMC_CUNIT_ASSERT(!error);
    EMC_CUNIT_ASSERT(level <= EMC_LOG_PRIORITY_TRACE);
#ifdef EMC_TEST_GREYBOX
    {
      emc_logger_t* logger = EMC_Log_logger_by_index(index);
      EMC_CUNIT_ASSERT(0 != logger);
      EMC_CUNIT_ASSERT(level == EMC_Log_priority(logger));
    }
#endif
    //printf("[%u] %u\n", index, level);
  }
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(GenericProtocol_functional_test_logger_level_set)
{
  int              error;
  emc_std_uint32_t index;
  emc_std_uint32_t level = EMC_LOG_PRIORITY_TRACE;
  emc_std_uint32_t original_level;

  EMC_CUNIT_ASSERT(enumerated());

  index = 0;
  for (;; ++index) {
    EMC_USB_CELENO_CLI_FunctionProxy_logger_level_get(&function_proxy, index, &original_level);
#ifdef EMC_TEST_GREYBOX
    {
      emc_logger_t* logger = EMC_Log_logger_by_index(index);
      if (logger) {
        EMC_Log_set_priority(logger, EMC_LOG_PRIORITY_OFF);
      }
    }
#endif
    error = EMC_USB_CELENO_CLI_FunctionProxy_logger_level_set(&function_proxy, index, level);
    if (EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_STATUS == error) {
      break;
    }
    EMC_CUNIT_ASSERT(!error);
#ifdef EMC_TEST_GREYBOX
    {
      emc_logger_t* logger = EMC_Log_logger_by_index(index);
      EMC_CUNIT_ASSERT(0 != logger);
      EMC_CUNIT_ASSERT(level == EMC_Log_priority(logger));
    }
#endif
    EMC_USB_CELENO_CLI_FunctionProxy_logger_level_set(&function_proxy, index, original_level);
  }
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(GenericProtocol_functional_test_logger_info_get)
{
  int              error;
  emc_std_uint32_t index;
  char             info_string[512];

  EMC_CUNIT_ASSERT(enumerated());

  index = 0;
  for (;; ++index) {
    error = EMC_USB_CELENO_CLI_FunctionProxy_logger_info_get(&function_proxy, index, info_string, sizeof(info_string));
    if ((EMC_USB_CELENO_CLI_Error_SUCCESS == error) && (emc_std_strnlen(info_string, sizeof(info_string)) == 0)) {
      break;
    }
    EMC_CUNIT_ASSERT(!error);
    EMC_CUNIT_ASSERT(emc_std_strnlen(info_string, sizeof(info_string)) > 0);
    //printf("[%u] %s\n", index, info_string);
#ifdef EMC_TEST_GREYBOX
    {
      emc_logger_t* logger = EMC_Log_logger_by_index(index);
      char          logger_string[512];
      EMC_CUNIT_ASSERT(0 != logger);
      EMC_CUNIT_ASSERT((emc_std_strnlen(info_string, sizeof(info_string)) + 1) ==
                       EMC_Log_logger_info(logger, logger_string, sizeof(logger_string)));
      EMC_CUNIT_ASSERT(0 == emc_std_strcmp(info_string, logger_string));
    }
#endif
    if (emc_std_strnlen(info_string, sizeof(info_string)) > 4) {
      error = EMC_USB_CELENO_CLI_FunctionProxy_logger_info_get(&function_proxy, index, info_string, 4);
      EMC_CUNIT_ASSERT(EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_LENGTH == error);
      //printf("[%u] %s\n", index, info_string);
    }
  }

  index = 255;
  error = EMC_USB_CELENO_CLI_FunctionProxy_logger_info_get(&function_proxy, index, info_string, sizeof(info_string));
  EMC_CUNIT_ASSERT(emc_std_strnlen(info_string, sizeof(info_string)) == 0);
  EMC_CUNIT_ASSERT(EMC_USB_CELENO_CLI_Error_SUCCESS == error);
}

#ifdef EMC_TEST_GREYBOX

extern struct EMC_USB_CELENO_CLI_Function* mg_function;

emc_std_bool ioctl_handler(void* context,
                           emc_std_uint32_t command,
                           emc_std_uint32_t param1,
                           emc_std_uint32_t param2,
                           emc_std_uint32_t* data1,
                           emc_std_uint32_t* data2
                           )
{
  //EMC_CUNIT_ASSERT(context == NULL);
  EMC_CUNIT_ASSERT(context == mg_function);
  EMC_CUNIT_ASSERT(param1 == 0);
  EMC_CUNIT_ASSERT(param2 == 0);
  EMC_CUNIT_ASSERT(data1 != NULL);
  EMC_CUNIT_ASSERT(data2 != NULL);
  return command == 1;
}

static emc_std_uint32_t cmd_hook_handler_calls = 0;
void cmd_hook_handler(void* context, emc_std_uint32_t command)
{
  UNUSED_PARAM(context);
  UNUSED_PARAM(command);
  cmd_hook_handler_calls++;
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(GenericProtocol_functional_test_function_ioctl)
{
  int              error;
  emc_std_uint32_t result1 = 0;
  emc_std_uint32_t result2 = 0;

  EMC_CUNIT_ASSERT(enumerated());
  EMC_CUNIT_ASSERT(mg_function != NULL);

  EMC_USB_CELENO_CLI_Function_register_command_hook(mg_function, cmd_hook_handler, NULL);
  EMC_USB_CELENO_CLI_Function_register_function_ioctl(mg_function, 0, ioctl_handler, mg_function);

  // send reset command to Wifi function and expect no error
  error = EMC_USB_CELENO_CLI_FunctionProxy_function_ioctl(&function_proxy, 0, 1, 0, 0, &result1, &result2);
  EMC_CUNIT_ASSERT(!error);

  // send valid command with NULL as result pointer, expect success
  error = EMC_USB_CELENO_CLI_FunctionProxy_function_ioctl(&function_proxy, 0, 1, 0, 0, NULL, NULL);
  EMC_CUNIT_ASSERT(!error);

  // send a command to a not supported function, index out of range, expect error
  error = EMC_USB_CELENO_CLI_FunctionProxy_function_ioctl(&function_proxy, 4, 0, 0, 0, &result1, &result2);
  EMC_CUNIT_ASSERT(error);

  // send a comand to function 3, no handler registered, expect error
  error = EMC_USB_CELENO_CLI_FunctionProxy_function_ioctl(&function_proxy, 3, 0, 0, 0, &result1, &result2);
  EMC_CUNIT_ASSERT(error);

  // send an invalid command ro registered handler on Wifi function, expect error
  error = EMC_USB_CELENO_CLI_FunctionProxy_function_ioctl(&function_proxy, 0, 0, 0, 0, &result1, &result2);
  EMC_CUNIT_ASSERT(error);

  EMC_CUNIT_ASSERT(cmd_hook_handler_calls != 0);
}

#endif

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(GenericProtocol_functional_test_function_ioctl_invalid)
{
  int              error;
  emc_std_uint32_t result1 = 0;
  emc_std_uint32_t result2 = 0;

  EMC_CUNIT_ASSERT(enumerated());

  // send a command to a not supported function, index out of range, expect error
  error = EMC_USB_CELENO_CLI_FunctionProxy_function_ioctl(&function_proxy, 4, 0, 0, 0, &result1, &result2);
  EMC_CUNIT_ASSERT(error);

  // send a comand to function 3, no handler registered, expect error
  error = EMC_USB_CELENO_CLI_FunctionProxy_function_ioctl(&function_proxy, 3, 0, 0, 0, &result1, &result2);
  EMC_CUNIT_ASSERT(error);

  // send an invalid command ro registered handler on Wifi function, expect error
  error = EMC_USB_CELENO_CLI_FunctionProxy_function_ioctl(&function_proxy, 0, 0, 0, 0, &result1, &result2);
  EMC_CUNIT_ASSERT(error);

}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(GenericProtocol_functional_test_write_reset)
{
  int error;
  /* burst write */
  emc_std_uint32_t data[] = {0x81, 0x00, 0, 0x100, 0};
  data[2] = target_memory_begin + 16;

  EMC_CUNIT_ASSERT(enumerated());

  /* violate the protocol and check it is not working */
  error = EMC_USB_CELENO_CLI_FunctionProxy_raw_write(&function_proxy, data, sizeof(data));
  EMC_CUNIT_ASSERT(!error);
  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_reset_wrapper(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(GenericProtocol_functional_test_read_reset)
{
  int error;
  /* burst read */
  emc_std_uint32_t data[] = {0x80, 0x00, 0, 0x100, 0};
  data[2] = target_memory_begin + 16;

  EMC_CUNIT_ASSERT(enumerated());

  /* violate the protocol and check it is not working */
  error = EMC_USB_CELENO_CLI_FunctionProxy_raw_write(&function_proxy, data, sizeof(data));
  EMC_CUNIT_ASSERT(!error);
  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_reset_wrapper(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(GenericProtocol_functional_test_write_read)
{
  int error;

  emc_std_uint32_t address = target_memory_begin;
  emc_std_uint32_t data = 0x01020304;
  emc_std_uint32_t mask = 0xFFFFFFFF;
  emc_std_uint32_t receive_data = 0;
  emc_std_uint32_t expected_data = 0;

  EMC_CUNIT_ASSERT(enumerated());

  EMC_CUNIT_ASSERT((address % 4) == 0);

#ifdef EMC_TEST_GREYBOX
  EMC_CUNIT_ASSERT(0xDEADBEEF == EMC_USB_CELENO_CLI_TargetMemory_read(address));
#endif /*EMC_TEST_GREYBOX*/

  error = EMC_USB_CELENO_CLI_FunctionProxy_write(&function_proxy, address, data, mask);
  EMC_CUNIT_ASSERT(!error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_read(&function_proxy, address, &receive_data);
  EMC_CUNIT_ASSERT(!error);
  EMC_CUNIT_ASSERT(receive_data == data);

#ifdef EMC_TEST_GREYBOX
  EMC_CUNIT_ASSERT(data == EMC_USB_CELENO_CLI_TargetMemory_read(address));
#endif /*EMC_TEST_GREYBOX*/

  data = 0;
  mask = 0xFFFF0000;
  expected_data = 0x00000304;

  error = EMC_USB_CELENO_CLI_FunctionProxy_write(&function_proxy, address, data, mask);
  EMC_CUNIT_ASSERT(!error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_read(&function_proxy, address, &receive_data);
  EMC_CUNIT_ASSERT(!error);
  EMC_CUNIT_ASSERT(receive_data == expected_data);

  data = 0xFFFF0000;
  mask = 0xFFFF0000;
  expected_data = 0xFFFF0304;

  error = EMC_USB_CELENO_CLI_FunctionProxy_write(&function_proxy, address, data, mask);
  EMC_CUNIT_ASSERT(!error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_read(&function_proxy, address, &receive_data);
  EMC_CUNIT_ASSERT(!error);
  EMC_CUNIT_ASSERT(receive_data == expected_data);
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(GenericProtocol_functional_test_write_fast_read)
{
  int              error;
  emc_std_uint32_t address = target_memory_begin + 4;

  emc_std_uint32_t data = 0x01020304;
  emc_std_uint32_t mask = 0xFFFFFFFF;
  emc_std_uint32_t receive_data = 0;

  EMC_CUNIT_ASSERT(enumerated());

#ifdef EMC_TEST_GREYBOX
  EMC_CUNIT_ASSERT(0xDEADBEEF == EMC_USB_CELENO_CLI_TargetMemory_read(address));
#endif /*EMC_TEST_GREYBOX*/

  error = EMC_USB_CELENO_CLI_FunctionProxy_write_fast(&function_proxy, address, data, mask);
  EMC_CUNIT_ASSERT(!error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_read(&function_proxy, address, &receive_data);
  EMC_CUNIT_ASSERT(!error);
  EMC_CUNIT_ASSERT(receive_data == data);

#ifdef EMC_TEST_GREYBOX
  EMC_CUNIT_ASSERT(data == EMC_USB_CELENO_CLI_TargetMemory_read(address));
#endif /*EMC_TEST_GREYBOX*/
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(GenericProtocol_functional_test_write_read_unaligned)
{
  int              error;
  emc_std_uint32_t address = target_memory_begin + 5;

  emc_std_uint32_t data = 0x01020304;
  emc_std_uint32_t mask = 0xFFFFFFFF;
  emc_std_uint32_t receive_data = 0;

  EMC_CUNIT_ASSERT(enumerated());

  error = EMC_USB_CELENO_CLI_FunctionProxy_write(&function_proxy, address, data, mask);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_STATUS);

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_read(&function_proxy, address, &receive_data);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_STATUS);

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_write_fast(&function_proxy, address, data, mask);
  // does not have response and does not check status
  //EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_STATUS);

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

}

void set_test_pattern(void* data, size_t size)
{
  uint8_t  pattern = 0;
  uint8_t* start = (uint8_t*)data;
  for (uint8_t* ptr = start; ptr < (start + size); ptr++) {
    if (((uintptr_t)ptr) % 2) {
      *ptr = pattern;
      pattern++;
    } else {
      *ptr = 0;
    }
  }
}

void GenericProtocol_functional_test_burst_write_read(emc_std_bool zero_copy)
{
  int error;

  emc_std_uint32_t address = target_memory_begin + (0x0004 * 3);
  emc_std_uint32_t tx_data[16];
  emc_std_uint32_t rx_data[16];

  set_test_pattern(tx_data, sizeof(tx_data));
  emc_std_memset(rx_data, 0xEE, sizeof(rx_data));

  EMC_CUNIT_ASSERT(enumerated());

  error = EMC_USB_CELENO_CLI_FunctionProxy_burst_write(&function_proxy, address, tx_data, sizeof(tx_data), zero_copy);
  EMC_CUNIT_ASSERT(!error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_burst_read(&function_proxy, address, rx_data, sizeof(rx_data), zero_copy);
  EMC_CUNIT_ASSERT(!error);
  EMC_CUNIT_ASSERT(emc_std_memcmp(tx_data, rx_data, sizeof(rx_data)) == 0);

  /* check if device accepts commands after data phase*/
  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(GenericProtocol_functional_test_burst_write_read_dma)
{
  GenericProtocol_functional_test_burst_write_read(emc_std_true);
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(GenericProtocol_functional_test_burst_write_read_buffered)
{
  GenericProtocol_functional_test_burst_write_read(emc_std_false);
}

void GenericProtocol_functional_test_burst_write_fast_read(emc_std_bool zero_copy)
{
  int error;

  emc_std_uint32_t address = target_memory_begin + (0x0004 * 3);
  emc_std_uint32_t tx_data[16];
  emc_std_uint32_t rx_data[16];

  set_test_pattern(tx_data, sizeof(tx_data));
  emc_std_memset(rx_data, 0x88, sizeof(rx_data));

  EMC_CUNIT_ASSERT(enumerated());

  error = EMC_USB_CELENO_CLI_FunctionProxy_burst_write_fast(&function_proxy,
                                                            address,
                                                            tx_data,
                                                            sizeof(tx_data),
                                                            zero_copy);
  EMC_CUNIT_ASSERT(!error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_burst_read(&function_proxy, address, rx_data, sizeof(rx_data), zero_copy);
  EMC_CUNIT_ASSERT(!error);
  EMC_CUNIT_ASSERT(emc_std_memcmp(tx_data, rx_data, sizeof(rx_data)) == 0);

  /* check if device accepts commands after data phase*/
  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(GenericProtocol_functional_test_burst_write_fast_read_dma)
{
  GenericProtocol_functional_test_burst_write_fast_read(emc_std_true);
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(GenericProtocol_functional_test_burst_write_fast_read_buffered)
{
  GenericProtocol_functional_test_burst_write_fast_read(emc_std_false);
}

void GenericProtocol_functional_test_burst_write_read_unaligned(emc_std_bool zero_copy)
{
  int              error;
  emc_std_uint32_t address = target_memory_begin + (0x0004 * 3) + 2;
  emc_std_uint32_t tx_data[16];
  emc_std_uint32_t rx_data[16];

  {
    emc_std_uint32_t initial_address = target_memory_begin;
    emc_std_uint32_t initial_tx_data[64];
    set_test_pattern(initial_tx_data, sizeof(initial_tx_data));
    error =
      EMC_USB_CELENO_CLI_FunctionProxy_burst_write(&function_proxy,
                                                   initial_address,
                                                   initial_tx_data,
                                                   sizeof(initial_tx_data),
                                                   zero_copy);
    EMC_CUNIT_ASSERT(!error);
  }

  emc_std_memset(tx_data, 0xFF, sizeof(tx_data));
  emc_std_memset(rx_data, 0xEE, sizeof(rx_data));

  EMC_CUNIT_ASSERT(enumerated());

  error = EMC_USB_CELENO_CLI_FunctionProxy_burst_write(&function_proxy, address, tx_data, sizeof(tx_data), zero_copy);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_STATUS);

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_burst_read(&function_proxy, address, rx_data, sizeof(rx_data), zero_copy);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_STATUS);

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_burst_write_fast(&function_proxy,
                                                            address,
                                                            tx_data,
                                                            sizeof(tx_data),
                                                            zero_copy);

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

  address = target_memory_begin + (0x0004 * 3); /* aligned address */

  error =
    EMC_USB_CELENO_CLI_FunctionProxy_burst_write(&function_proxy, address, tx_data, sizeof(tx_data) - 1, zero_copy);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_STATUS);

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

  error =
    EMC_USB_CELENO_CLI_FunctionProxy_burst_read(&function_proxy, address, rx_data, sizeof(rx_data) - 1, zero_copy);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_STATUS);

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

  {
    emc_std_uint32_t initial_address = target_memory_begin;
    emc_std_uint32_t initial_data[64];
    emc_std_uint32_t rx_data[64];

    set_test_pattern(initial_data, sizeof(initial_data));

    error = EMC_USB_CELENO_CLI_FunctionProxy_burst_read(&function_proxy,
                                                        initial_address,
                                                        rx_data,
                                                        sizeof(rx_data),
                                                        zero_copy);
    EMC_CUNIT_ASSERT(!error);

    EMC_CUNIT_ASSERT(emc_std_memcmp(rx_data, initial_data, sizeof(initial_data)) == 0);
  }

  error = EMC_USB_CELENO_CLI_FunctionProxy_burst_write_fast(&function_proxy,
                                                            address,
                                                            tx_data,
                                                            sizeof(tx_data),
                                                            zero_copy);

}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(GenericProtocol_functional_test_burst_write_read_unaligned_dma)
{
  GenericProtocol_functional_test_burst_write_read_unaligned(emc_std_true);
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(GenericProtocol_functional_test_burst_write_read_unaligned_buffered)
{
  GenericProtocol_functional_test_burst_write_read_unaligned(emc_std_false);
}

EMC_CUNIT_END_TEST

#if CHECK_VALID
int test_success_write_read_burst(emc_std_uint32_t address, emc_std_uint32_t size, emc_std_bool zero_copy)
{
  int error;

  emc_std_uint32_t* tx_data = malloc(size);
  emc_std_uint32_t* rx_data = malloc(size);

  set_test_pattern(tx_data, size);
  emc_std_memset(rx_data, 0xEE, size);

  error = EMC_USB_CELENO_CLI_FunctionProxy_burst_write(&function_proxy, address, tx_data, size, zero_copy);
  EMC_CUNIT_ASSERT(!error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_burst_read(&function_proxy, address, rx_data, size, zero_copy);
  EMC_CUNIT_ASSERT(!error);
  EMC_CUNIT_ASSERT(emc_std_memcmp(tx_data, rx_data, size) == 0);

  /* check if device accepts commands after data phase*/
  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

  free(tx_data);
  free(rx_data);

  return error;
}

#endif /*CHECK_VALID*/

#if CHECK_INVALID
int test_failed_write_read_burst(emc_std_uint32_t address, emc_std_uint32_t size)
{
  int error;
  int write_error;
  int read_error;

  emc_std_uint32_t* tx_data = malloc(size);
  emc_std_uint32_t* rx_data = malloc(size);

  set_test_pattern(tx_data, size);
  emc_std_memset(rx_data, 0xEE, size);

  write_error = EMC_USB_CELENO_CLI_FunctionProxy_burst_write(&function_proxy, address, tx_data, size);

  read_error = EMC_USB_CELENO_CLI_FunctionProxy_burst_read(&function_proxy, address, rx_data, size);

  /* check if device accepts commands after data phase*/
  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

  free(tx_data);
  free(rx_data);

  if (write_error) {
    error = write_error;
  } else if (read_error) {
    error = read_error;
  }
  return error;
}

#endif /*CHECK_INVALID*/

void GenericProtocol_functional_test_burst_write_read_zlp(emc_std_bool zero_copy)
{
  int  error;
  char message_buffer[120];

  emc_std_uint32_t address = target_memory_begin + (0x0004 * 3);

  EMC_CUNIT_ASSERT(enumerated());

#if CHECK_VALID
  {
    emc_std_uint32_t valid_size[] = {
      16,
      32,
#  ifndef EMC_TEST_GREYBOX   /* currently the mock does not support zlp handling*/
      64,
      64 - 4,
      64 + 4,
      512,
      512 - 4,
      512 + 4,
      1024,
      1024 - 4,
      1024 + 4,
      2 * 1024,
      2 * 1024 - 4,
      2 * 1024 + 4,
      4 * 1024,
      4 * 1024 - 4,
      4 * 1024 + 4,
      5 * 1024,
      5 * 1024 - 4,
      5 * 1024 + 4,
      8 * 1024,
      8 * 1024 - 4,
      8 * 1024 + 4,
      13 * 1024,
      13 * 1024 - 4,
      13 * 1024 + 4,
      16 * 1024,
      16 * 1024 - 4,
      16 * 1024 + 4,
      EMC_USB_VENDOR_CELENO_CLI_MAX_DATA_TRANSFER_LENGTH - 4,
      EMC_USB_VENDOR_CELENO_CLI_MAX_DATA_TRANSFER_LENGTH
#  endif /*EMC_TEST_GREYBOX*/
    };

    for (unsigned i = 0; i < sizeof(valid_size) / sizeof(valid_size[0]); ++i) {
      error = test_success_write_read_burst(address, valid_size[i], zero_copy);
      if (error) {
        snprintf(message_buffer,
                 sizeof(message_buffer),
                 "write_read_burst for size=0x%x failed with error=%d (%s)",
                 valid_size[i],
                 error,
                 EMC_USB_CELENO_CLI_Error_as_string(error));
        fprintf(stderr, "FAIL: %s\n", message_buffer);
        EMC_CUNIT_FAIL(message);
        EMC_CUNIT_ASSERT(!error);
      }
    }

  }
#endif /*CHECK_VALID*/

#if CHECK_INVALID
  {
    emc_std_uint32_t invalid_size[] = {
      EMC_USB_VENDOR_CELENO_CLI_MAX_DATA_TRANSFER_LENGTH + 1
    };

    for (unsigned i = 0; i < sizeof(invalid_size) / sizeof(invalid_size[0]); ++i) {
      error = test_failed_write_read_burst(address, invalid_size[i]);
      EMC_CUNIT_ASSERT(error);
    }
  }
#endif /* CHECK_INVALID*/
}

EMC_CUNIT_START_TEST(GenericProtocol_functional_test_burst_write_read_zlp_dma) {
  GenericProtocol_functional_test_burst_write_read_zlp(emc_std_false);
}

EMC_CUNIT_START_TEST(GenericProtocol_functional_test_burst_write_read_zlp_buffered) {
  GenericProtocol_functional_test_burst_write_read_zlp(emc_std_true);
}

EMC_CUNIT_START_TEST(GenericProtocol_functional_test_queued_read) {
  int              error;
  emc_std_uint32_t val[2] = {0x01020304, 0x05060708};
  emc_std_uint32_t reg[2] = {0, 0};
  emc_std_uint32_t address = target_memory_begin;

  EMC_CUNIT_ASSERT(enumerated());

  error = EMC_USB_CELENO_CLI_FunctionProxy_write(&function_proxy, address, val[0], 0xFFFFFFFF);
  EMC_CUNIT_ASSERT(!error);
  error = EMC_USB_CELENO_CLI_FunctionProxy_write(&function_proxy, address + 4, val[1], 0xFFFFFFFF);
  EMC_CUNIT_ASSERT(!error);

  EMC_USB_CELENO_CLI_FunctionProxy_queue_begin(&function_proxy);
  error = EMC_USB_CELENO_CLI_FunctionProxy_read(&function_proxy, address, &reg[0]);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_PENDING);
  error = EMC_USB_CELENO_CLI_FunctionProxy_read(&function_proxy, address + 4, &reg[1]);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_PENDING);

  error = EMC_USB_CELENO_CLI_FunctionProxy_queue_process(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

  EMC_CUNIT_ASSERT(reg[0] == val[0]);
  EMC_CUNIT_ASSERT(reg[1] == val[1]);

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);
}

EMC_CUNIT_START_TEST(GenericProtocol_functional_test_queued_write_fast) {
  int              error;
  emc_std_uint32_t val[2] = {0x01020304, 0x05060708};
  emc_std_uint32_t reg = 0;
  emc_std_uint32_t address = target_memory_begin;

  EMC_CUNIT_ASSERT(enumerated());

  EMC_USB_CELENO_CLI_FunctionProxy_queue_begin(&function_proxy);
  error = EMC_USB_CELENO_CLI_FunctionProxy_write_fast(&function_proxy, address, val[0], 0xFFFFFFFF);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_PENDING);
  error = EMC_USB_CELENO_CLI_FunctionProxy_write_fast(&function_proxy, address + 4, val[1], 0xFFFFFFFF);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_PENDING);

  error = EMC_USB_CELENO_CLI_FunctionProxy_queue_process(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_read(&function_proxy, address, &reg);
  EMC_CUNIT_ASSERT(!error);
  EMC_CUNIT_ASSERT(reg == val[0]);

  error = EMC_USB_CELENO_CLI_FunctionProxy_read(&function_proxy, address + 4, &reg);
  EMC_CUNIT_ASSERT(!error);
  EMC_CUNIT_ASSERT(reg == val[1]);
}

EMC_CUNIT_START_TEST(GenericProtocol_functional_test_queued_mixed) {
  int              error;
  emc_std_uint32_t val[4] = {0x01020304, 0x05060708, 0x090A0B0C, 0x0D0E0F10};
  emc_std_uint32_t reg = 0;
  emc_std_uint32_t address = target_memory_begin;

  EMC_CUNIT_ASSERT(enumerated());

  error = EMC_USB_CELENO_CLI_FunctionProxy_write(&function_proxy, address + 12, val[3], 0xFFFFFFFF);
  EMC_CUNIT_ASSERT(!error);

  EMC_USB_CELENO_CLI_FunctionProxy_queue_begin(&function_proxy);
  error = EMC_USB_CELENO_CLI_FunctionProxy_write_fast(&function_proxy, address, val[0], 0xFFFFFFFF);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_PENDING);
  error = EMC_USB_CELENO_CLI_FunctionProxy_write_fast(&function_proxy, address + 4, val[1], 0xFFFFFFFF);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_PENDING);
  error = EMC_USB_CELENO_CLI_FunctionProxy_write(&function_proxy, address + 8, val[2], 0xFFFFFFFF);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_PENDING);
  error = EMC_USB_CELENO_CLI_FunctionProxy_read(&function_proxy, address + 12, &reg);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_PENDING);

  error = EMC_USB_CELENO_CLI_FunctionProxy_queue_process(&function_proxy);
  EMC_CUNIT_ASSERT(!error);
  EMC_CUNIT_ASSERT(reg == val[3]);

  error = EMC_USB_CELENO_CLI_FunctionProxy_read(&function_proxy, address, &reg);
  EMC_CUNIT_ASSERT(!error);
  EMC_CUNIT_ASSERT(reg == val[0]);
  error = EMC_USB_CELENO_CLI_FunctionProxy_read(&function_proxy, address + 4, &reg);
  EMC_CUNIT_ASSERT(!error);
  EMC_CUNIT_ASSERT(reg == val[1]);
  error = EMC_USB_CELENO_CLI_FunctionProxy_read(&function_proxy, address + 8, &reg);
  EMC_CUNIT_ASSERT(!error);
  EMC_CUNIT_ASSERT(reg == val[2]);
}

static void GenericProtocol_functional_test_queued_not_allowed(emc_std_bool zero_copy)
{
  int              error;
  emc_std_uint32_t address = target_memory_begin;
  emc_std_uint32_t data;
  emc_std_uint32_t protocol_version;
  emc_std_uint32_t firmware_version;

  EMC_CUNIT_ASSERT(enumerated());

  EMC_USB_CELENO_CLI_FunctionProxy_queue_begin(&function_proxy);

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED);

  error = EMC_USB_CELENO_CLI_FunctionProxy_get_version(&function_proxy, &protocol_version, &firmware_version);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED);

  error = EMC_USB_CELENO_CLI_FunctionProxy_burst_write(&function_proxy, address, &data, 0, zero_copy);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED);

  error = EMC_USB_CELENO_CLI_FunctionProxy_burst_write_fast(&function_proxy, address, &data, 0, zero_copy);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED);

  error = EMC_USB_CELENO_CLI_FunctionProxy_burst_read(&function_proxy, address, &data, 0, zero_copy);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED);
}

EMC_CUNIT_START_TEST(GenericProtocol_functional_test_queued_not_allowed_dma) {
  GenericProtocol_functional_test_queued_not_allowed(emc_std_true);
}

EMC_CUNIT_START_TEST(GenericProtocol_functional_test_queued_not_allowed_buffered) {
  GenericProtocol_functional_test_queued_not_allowed(emc_std_false);
}

EMC_CUNIT_START_TEST(GenericProtocol_functional_test_queued_empty) {
  int error;

  EMC_USB_CELENO_CLI_FunctionProxy_queue_begin(&function_proxy);

  error = EMC_USB_CELENO_CLI_FunctionProxy_queue_process(&function_proxy);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_QUEUE_EMPTY);

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_queue_process(&function_proxy);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_QUEUE_EMPTY);

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);
}

static void GenericProtocol_functional_test_invalid_parameter(emc_std_bool zero_copy)
{
  int              error;
  emc_std_uint32_t address = target_memory_begin;
  emc_std_uint32_t version;

  EMC_CUNIT_ASSERT(enumerated());

  error = EMC_USB_CELENO_CLI_FunctionProxy_get_version(&function_proxy, 0, &version);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER);

  error = EMC_USB_CELENO_CLI_FunctionProxy_get_version(&function_proxy, &version, 0);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER);

  error = EMC_USB_CELENO_CLI_FunctionProxy_burst_write(&function_proxy, address, 0, 0, zero_copy);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER);

  error = EMC_USB_CELENO_CLI_FunctionProxy_read(&function_proxy, address, 0);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER);

  error = EMC_USB_CELENO_CLI_FunctionProxy_burst_write_fast(&function_proxy, address, 0, 0, zero_copy);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER);

  error = EMC_USB_CELENO_CLI_FunctionProxy_burst_read(&function_proxy, address, 0, 0, zero_copy);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER);
}

EMC_CUNIT_START_TEST(GenericProtocol_functional_test_invalid_parameter_dma) {
  GenericProtocol_functional_test_invalid_parameter(emc_std_true);
}

EMC_CUNIT_START_TEST(GenericProtocol_functional_test_invalid_parameter_buffered) {
  GenericProtocol_functional_test_invalid_parameter(emc_std_false);
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(GenericProtocol_functional_test_invalid_command)
{
  int error;

  error = EMC_USB_CELENO_CLI_FunctionProxy_any_command(&function_proxy, 0x0);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_STATUS);

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);

  error = EMC_USB_CELENO_CLI_FunctionProxy_any_command(&function_proxy, 0xFFFF0000);
  EMC_CUNIT_ASSERT(error == EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_STATUS);

  error = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  EMC_CUNIT_ASSERT(!error);
}

EMC_CUNIT_END_TEST EMC_CUNIT_TEST_SUITE(GenericProtocol_functional_test);

#ifdef EMC_TEST_GREYBOX
EMC_CUNIT_TEST(GenericProtocol_functional_test_unconfigure_configure);
#endif /*EMC_TEST_GREYBOX*/
EMC_CUNIT_TEST(GenericProtocol_functional_test_init_cfg);
EMC_CUNIT_TEST(GenericProtocol_functional_test_keep_alive);
EMC_CUNIT_TEST(GenericProtocol_functional_test_get_version);
EMC_CUNIT_TEST(GenericProtocol_functional_test_reset);
EMC_CUNIT_TEST(GenericProtocol_functional_test_logger_level_get);
EMC_CUNIT_TEST(GenericProtocol_functional_test_logger_level_set);
EMC_CUNIT_TEST(GenericProtocol_functional_test_logger_info_get);
#ifdef EMC_TEST_GREYBOX
EMC_CUNIT_TEST(GenericProtocol_functional_test_function_ioctl);
#endif
EMC_CUNIT_TEST(GenericProtocol_functional_test_function_ioctl_invalid);
EMC_CUNIT_TEST(GenericProtocol_functional_test_write_reset);
EMC_CUNIT_TEST(GenericProtocol_functional_test_read_reset);
EMC_CUNIT_TEST(GenericProtocol_functional_test_write_read);
EMC_CUNIT_TEST(GenericProtocol_functional_test_write_fast_read);
EMC_CUNIT_TEST(GenericProtocol_functional_test_write_read_unaligned);
EMC_CUNIT_TEST(GenericProtocol_functional_test_burst_write_read_dma);
EMC_CUNIT_TEST(GenericProtocol_functional_test_burst_write_read_buffered);
EMC_CUNIT_TEST(GenericProtocol_functional_test_burst_write_fast_read_dma);
EMC_CUNIT_TEST(GenericProtocol_functional_test_burst_write_fast_read_buffered);
EMC_CUNIT_TEST(GenericProtocol_functional_test_burst_write_read_unaligned_dma);
EMC_CUNIT_TEST(GenericProtocol_functional_test_burst_write_read_unaligned_buffered);
EMC_CUNIT_TEST(GenericProtocol_functional_test_burst_write_read_zlp_dma);
EMC_CUNIT_TEST(GenericProtocol_functional_test_burst_write_read_zlp_buffered);
EMC_CUNIT_TEST(GenericProtocol_functional_test_queued_read);
EMC_CUNIT_TEST(GenericProtocol_functional_test_queued_write_fast);
EMC_CUNIT_TEST(GenericProtocol_functional_test_queued_mixed);
EMC_CUNIT_TEST(GenericProtocol_functional_test_queued_not_allowed_dma);
EMC_CUNIT_TEST(GenericProtocol_functional_test_queued_not_allowed_buffered);
EMC_CUNIT_TEST(GenericProtocol_functional_test_queued_empty);
EMC_CUNIT_TEST(GenericProtocol_functional_test_invalid_parameter_dma);
EMC_CUNIT_TEST(GenericProtocol_functional_test_invalid_parameter_buffered);
EMC_CUNIT_TEST(GenericProtocol_functional_test_invalid_command);
EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(GenericProtocol_functional_test)

int GenericProtocol_functional_test_run(int argc, char* argv[])
{
  emc_std_memset(usb_sn, 0, sizeof(usb_sn));
  if (argc >= 2) {
    ram_base_address = (uint32_t)strtoul(argv[1], 0, 0);
    fprintf(stderr, "Set ram base address to 0x%08x.\n", ram_base_address);
  }
  if (argc >= 3) {
    transfer_timeout_ms = (uint32_t)strtoul(argv[2], 0, 0);
    fprintf(stderr, "Set transfer timeout to %dms.\n", transfer_timeout_ms);
  }
  if (argc >= 4) {
    usb_pid = (uint16_t)strtoul(argv[3], 0, 0);
    fprintf(stderr, "Set expected USB-PID=0x%04X.\n", usb_pid);
  }
  if (argc >= 5) {
    strncpy(usb_sn, argv[4], sizeof(usb_sn) - 1);
    fprintf(stderr, "Set expected USB-S/N=\"%s\".\n", (char*)usb_sn);
  }
  return EMC_TEST_RUNNER_MAIN(argc, argv);
}
