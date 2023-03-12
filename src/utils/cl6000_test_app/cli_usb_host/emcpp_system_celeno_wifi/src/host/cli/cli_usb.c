/**
 * @file
 * @brief   CLI implementation
 * @author  <guenter.hildebrandte@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/system/celeno/host/cli/cli_usb.h"
#include "emc/usb/vendor/celeno/cli/host/FunctionProxy.h"
#include "emc/usb/vendor/celeno/cli/host/FunctionProxy_private.h"
#include "emc/usb/vendor/celeno/cli/host/test/GenericProtocol_functional_test_impl.h"
#include "emc/usb/host/hal/HAL.h"
#include "emc/std/assert.h"
#include "emc/std/string.h"
#include "emc/std/ext/ct_assert.h"

#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#define MAX_BURST_SIZE 0x8000

const uint32_t mg_cl_usb_max_cli_protocol_supported = EMC_USB_VENDOR_CELENO_CLI_PROTOCOL_VERSION;

static EMC_USB_CELENO_CLI_FunctionProxy function_proxy;
static CLI_USB_Config                   config;
static uint32_t                         protocol_version;
static uint32_t                         firmware_version;
static int                              last_error;

static void set_error(int status)
{
  EMC_CT_ASSERT(EMC_USB_CELENO_CLI_Error_PENDING == CL_USB_Error_PENDING);
  EMC_CT_ASSERT(EMC_USB_CELENO_CLI_Error_SUCCESS == CL_USB_Error_SUCCESS);
  EMC_CT_ASSERT(EMC_USB_CELENO_CLI_Error_TIMEOUT == CL_USB_Error_TIMEOUT);
  EMC_CT_ASSERT(EMC_USB_CELENO_CLI_Error_CONNECTION_ERROR == CL_USB_Error_CONNECTION_ERROR);
  EMC_CT_ASSERT(EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER == CL_USB_Error_INVALID_PARAMETER);
  EMC_CT_ASSERT(EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_TYPE == CL_USB_Error_INVALID_RESPONSE_TYPE);
  EMC_CT_ASSERT(EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_STATUS == CL_USB_Error_INVALID_RESPONSE_STATUS);
  EMC_CT_ASSERT(EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_LENGTH == CL_USB_Error_INVALID_RESPONSE_LENGTH);
  EMC_CT_ASSERT(EMC_USB_CELENO_CLI_Error_INVALID_VERSION == CL_USB_Error_INVALID_VERSION);
  EMC_CT_ASSERT(EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED == CL_USB_Error_QUEUEING_NOT_ALLOWED);
  EMC_CT_ASSERT(EMC_USB_CELENO_CLI_Error_QUEUE_OVERFLOW == CL_USB_Error_QUEUE_OVERFLOW);
  EMC_CT_ASSERT(EMC_USB_CELENO_CLI_Error_QUEUE_EMPTY == CL_USB_Error_QUEUE_EMPTY);
  EMC_CT_ASSERT(EMC_USB_CELENO_CLI_Error_GENERIC == CL_USB_Error_GENERIC);

  if (last_error == 0) {
    switch (status) {
    case EMC_USB_CELENO_CLI_Error_PENDING: break;
    case EMC_USB_CELENO_CLI_Error_SUCCESS: break;
    default: last_error = status; break;
    }
  }
}

static void check_status(const char* message, int status)
{
  if (status < 0) {
    set_error(status);
    if (config.silent == 0) {
      fprintf(stderr, "Error: %s: %s\n", message, EMC_USB_CELENO_CLI_Error_as_string(status));
    }
  }
}

int cl_usb_self_test(uint32_t memory_128k_address, const CLI_USB_Config* config)
{
  char* argv[] = {"cl_usb_self_test", "0x40080000", "0", "0x0", "0x0"};
  int   argc = 4;
  char  addr_str[16];
  char  timeout_str[16];
  char  pid_str[16];

  if (memory_128k_address != 0) {
    snprintf(&addr_str[0], sizeof(addr_str), "0x%08x", memory_128k_address);
    argv[1] = addr_str;
  }
  snprintf(&timeout_str[0], sizeof(timeout_str), "%d", config->transfer_timeout_ms);
  argv[2] = timeout_str;
  snprintf(&pid_str[0], sizeof(pid_str), "0x%04x", config->pid);
  argv[3] = pid_str;
  if (config->sn) {
    argv[4] = (char*)config->sn;
    argc = 5;
  }
  return GenericProtocol_functional_test_run(argc, argv);
}

void cl_usb_config_init(CLI_USB_Config* config)
{
  emc_std_memset(config, 0, sizeof(CLI_USB_Config));
  config->transfer_timeout_ms = 1000;
}

static int cl_usb_open_impl(void)
{
  int                                    status;
  EMC_USB_HOST_HAL_Error                 host_error;
  EMC_USB_CELENO_CLI_FunctionProxyConfig proxy_config;

  last_error = 0;

  host_error = EMC_USB_HOST_HAL_init();
  if (host_error != EMC_USB_HOST_HAL_Error_NONE) {
    check_status("EMC_USB_HOST_HAL_init", host_error);
    return host_error;
  }

  EMC_USB_CELENO_CLI_FunctionProxyConfig_init(&proxy_config);
  proxy_config.transfer_timeout_ms = config.transfer_timeout_ms;
  proxy_config.pid = config.pid;
  proxy_config.bcd_device = config.bcd_device;
  proxy_config.sn = config.sn;

  status = EMC_USB_CELENO_CLI_FunctionProxy_init(&function_proxy, &proxy_config);
  if (status) {
    check_status("EMC_USB_CELENO_CLI_FunctionProxy_init", status);
    EMC_USB_HOST_HAL_exit();
    return status;
  }

  EMC_USB_CELENO_CLI_FunctionProxy_start(&function_proxy);
  status = EMC_USB_CELENO_CLI_FunctionProxy_get_version(&function_proxy, &protocol_version, &firmware_version);
  check_status("EMC_USB_CELENO_CLI_FunctionProxy_get_version", status);
  if (status) {
    cl_usb_close();
    return status;
  }

  // support latest version and all previous ones - which are intended to be backward compatible
  if ((EMC_USB_VENDOR_CELENO_CLI_PROTOCOL_VERSION != protocol_version) &&
      (0x00000104 != protocol_version) &&
      (0x00000103 != protocol_version) &&
      (0x00000102 != protocol_version) &&
      (0x00000101 != protocol_version))
  {
    cl_usb_close();
    check_status("Invalid protocol version", EMC_USB_CELENO_CLI_Error_INVALID_VERSION);
    fprintf(stderr,
            "expect: 0x%06X.%02X, device returned 0x%06X.%02X\n",
            EMC_USB_VENDOR_CELENO_CLI_PROTOCOL_VERSION >> 8, EMC_USB_VENDOR_CELENO_CLI_PROTOCOL_VERSION & 0xFF,
            protocol_version >> 8, protocol_version & 0xFF);
    return EMC_USB_CELENO_CLI_Error_INVALID_VERSION;
  }
  return 0;
}

static void print_config(const CLI_USB_Config* cfg, const char* context)
{
  fprintf(stderr, "%s CLI_USB_Config\n", context);
  fprintf(stderr, "    .silent = %d\n", cfg->silent);
  fprintf(stderr, "    .verbose = %d\n", cfg->verbose);
  fprintf(stderr, "    .transfer_timeout_ms = %dms\n", cfg->transfer_timeout_ms);
  fprintf(stderr, "    .connection_timeout_ms = %dms\n", cfg->connection_timeout_ms);
  fprintf(stderr, "    .pid = 0x%04X\n", cfg->pid);
  fprintf(stderr, "    .bdDevice = 0x%04X\n", cfg->bcd_device);
  fprintf(stderr, "    .sn = \"%s\"\n", cfg->sn);
}

int cl_usb_open(const CLI_USB_Config* cfg)
{
  int      status;
  uint16_t connect_count = 0;
  uint32_t max_reconnect_count = 0;

  emc_std_memcpy(&config, cfg, sizeof(config));

  if (config.verbose != 0) {
    print_config(cfg, __func__);
  }

  max_reconnect_count = (config.connection_timeout_ms + 999) / 1000;
  status = cl_usb_open_impl();
  while ((status != EMC_USB_CELENO_CLI_Error_SUCCESS) && (connect_count < max_reconnect_count)) {
    sleep(1);
    if (config.verbose != 0) {
      fprintf(stderr, "%s - Retry [%d/%d] ...\n", __func__, connect_count + 1, max_reconnect_count);
    }
    status = cl_usb_open_impl();
    connect_count++;
  }

  if ((status != EMC_USB_CELENO_CLI_Error_SUCCESS) && !config.silent) {
    print_config(cfg, "Failed to open with");
  }

  return status;
}

uint16_t cl_usb_get_pid(void)
{
  if (EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy) && function_proxy.hal_interface) {
    return EMC_USB_HOST_HAL_interface_get_pid(function_proxy.hal_interface);
  }
  return 0;
}

uint16_t cl_usb_get_fw_version(void)
{
  if (EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy) && function_proxy.hal_interface) {
    return EMC_USB_HOST_HAL_interface_get_fw_version(function_proxy.hal_interface);
  }
  return 0;
}

const uint8_t* cl_usb_get_sn(void)
{
  if (EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy) && function_proxy.hal_interface) {
    return EMC_USB_HOST_HAL_interface_get_sn(function_proxy.hal_interface);
  }
  return 0;
}

CL_USB_SPEED cl_usb_get_speed(void)
{
  switch (EMC_USB_HOST_HAL_get_device_speed()) {
  case EMC_USB_Speed_LOW: return CL_USB_SPEED_LOW;
  case EMC_USB_Speed_FULL: return CL_USB_SPEED_FULL;
  case EMC_USB_Speed_HIGH: return CL_USB_SPEED_HIGH;
  case EMC_USB_Speed_SUPER: return CL_USB_SPEED_SUPER;
  case EMC_USB_Speed_SUPER_PLUS: return CL_USB_SPEED_SUPER_PLUS;
  case EMC_USB_Speed_UNDEFINED: return CL_USB_SPEED_UNDEFINED;
  default: return CL_USB_SPEED_UNDEFINED;
  }
}

void cl_usb_close(void)
{
  if (config.verbose != 0) {
    fprintf(stderr, "%s\n", __func__);
  }
  if (EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy)) {
    EMC_USB_CELENO_CLI_FunctionProxy_stop(&function_proxy);
    EMC_USB_CELENO_CLI_FunctionProxy_exit(&function_proxy);
  }
  EMC_USB_HOST_HAL_exit();
}

int cl_usb_last_error(void)
{
  return last_error;
}

int cl_usb_reset(void)
{
  int status = 0;

  if (!EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy)) {
    return EMC_USB_CELENO_CLI_Error_GENERIC;
  }

  status = EMC_USB_CELENO_CLI_FunctionProxy_reset(&function_proxy);
  check_status("EMC_USB_CELENO_CLI_FunctionProxy_reset", status);
  return status;
}

int cl_usb_keep_alive(void)
{
  int status = 0;

  if (!EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy)) {
    return EMC_USB_CELENO_CLI_Error_GENERIC;
  }

  status = EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(&function_proxy);
  check_status("EMC_USB_CELENO_CLI_FunctionProxy_keep_alive", status);
  return status;
}

int cl_usb_get_version(uint32_t* protocol,
                       uint32_t* firmware)
{
  if (!EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy)) {
    return EMC_USB_CELENO_CLI_Error_GENERIC;
  }

  if ((protocol == 0) || (firmware == 0)) {
    check_status("cl_usb_get_version", EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER);
    return EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER;
  }
  *protocol = protocol_version;
  *firmware = firmware_version;
  return 0;
}

const char* cl_usb_app_id_as_string(uint8_t app_id)
{
  static const char* const app_names[] = {
    "Undefined",
    "USB Bootloader",
    "USB Wifi/Bluetooth APP",
    "USB Transport Throughput APP"
  };
  static const char*       app_name_unknown = "Unknown";

  if (app_id >= sizeof(app_names) / sizeof(app_names[0])) {
    return app_name_unknown;
  }

  return app_names[app_id];
}

int cl_usb_read32(uint32_t offset, uint32_t* data)
{
  int32_t status;

  if (!EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy)) {
    return EMC_USB_CELENO_CLI_Error_GENERIC;
  }

  status = EMC_USB_CELENO_CLI_FunctionProxy_read(&function_proxy, offset, data);
  check_status("EMC_USB_CELENO_CLI_FunctionProxy_read", status);
  if (status != EMC_USB_CELENO_CLI_Error_SUCCESS) {
    *data = 0;
  }
  return status;
}

int cl_usb_write32_mask(uint32_t offset, uint32_t value, uint32_t mask)
{
  int status = 0;

  if (!EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy)) {
    return EMC_USB_CELENO_CLI_Error_GENERIC;
  }

  status = EMC_USB_CELENO_CLI_FunctionProxy_write(&function_proxy, offset, value, mask);
  check_status("EMC_USB_CELENO_CLI_FunctionProxy_write", status);
  return status;
}

int cl_usb_write32_mask_fast(uint32_t offset, uint32_t value, uint32_t mask)
{
  int status = 0;

  if (!EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy)) {
    return EMC_USB_CELENO_CLI_Error_GENERIC;
  }

  status = EMC_USB_CELENO_CLI_FunctionProxy_write_fast(&function_proxy, offset, value, mask);
  check_status("EMC_USB_CELENO_CLI_FunctionProxy_write_fast", status);
  return status;
}

int cl_usb_burst_read(uint32_t offset, void* data, size_t size, bool zero_copy)
{
  uint8_t* ptr = (uint8_t*)data;
  uint32_t transfer_size = 0;
  int      status = 0;

  if (!EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy)) {
    return EMC_USB_CELENO_CLI_Error_GENERIC;
  }

  for (; size > 0;) {
    transfer_size = (uint32_t)(size < MAX_BURST_SIZE ? size : MAX_BURST_SIZE);
    status = EMC_USB_CELENO_CLI_FunctionProxy_burst_read(&function_proxy, offset, ptr, transfer_size, zero_copy);
    check_status("EMC_USB_CELENO_CLI_FunctionProxy_burst_read", status);
    if (status != EMC_USB_CELENO_CLI_Error_SUCCESS) {
      break;
    }
    ptr += transfer_size;
    offset += transfer_size;
    size -= transfer_size;
  }
  return status;
}

static int burst_write_impl(uint32_t offset, const void* data, size_t size, bool fast, bool zero_copy)
{
  const uint8_t* ptr = (const uint8_t*)data;
  uint32_t       transfer_size = 0;
  int            status = 0;

  if (!EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy)) {
    return EMC_USB_CELENO_CLI_Error_GENERIC;
  }

  for (; size > 0;) {
    transfer_size = (uint32_t)(size < MAX_BURST_SIZE ? size : MAX_BURST_SIZE);
    if (fast) {
      status =
        EMC_USB_CELENO_CLI_FunctionProxy_burst_write_fast(&function_proxy, offset, ptr, transfer_size, zero_copy);
    } else {
      status = EMC_USB_CELENO_CLI_FunctionProxy_burst_write(&function_proxy, offset, ptr, transfer_size, zero_copy);
    }
    check_status("EMC_USB_CELENO_CLI_FunctionProxy_burst_write/write_fast", status);
    if (status != EMC_USB_CELENO_CLI_Error_SUCCESS) {
      break;
    }
    ptr += transfer_size;
    offset += transfer_size;
    size -= transfer_size;
  }
  return status;
}

int cl_usb_burst_write(uint32_t offset, const void* data, size_t size, bool zero_copy)
{
  return burst_write_impl(offset, data, size, false, zero_copy);
}

int cl_usb_burst_write_fast(uint32_t offset, const void* data, size_t size, bool zero_copy)
{
  return burst_write_impl(offset, data, size, true, zero_copy);
}

int cl_usb_disconnect(uint32_t usb_disconnect_delay_ms)
{
  int status = 0;

  if (!EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy)) {
    return EMC_USB_CELENO_CLI_Error_GENERIC;
  }

  status = EMC_USB_CELENO_CLI_FunctionProxy_usb_disconnect(&function_proxy,
                                                           usb_disconnect_delay_ms);
  check_status("EMC_USB_CELENO_CLI_FunctionProxy_usb_disconnect", status);

  return status;
}

int cl_usb_umac_execute(uint32_t jump_address)
{
  int status = 0;

  if (!EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy)) {
    return EMC_USB_CELENO_CLI_Error_GENERIC;
  }

  status = EMC_USB_CELENO_CLI_FunctionProxy_umac_execute(&function_proxy, jump_address);
  check_status("EMC_USB_CELENO_CLI_FunctionProxy_umac_execute", status);

  return status;
}

int cl_usb_umac_restart(uint32_t usb_disconnect_delay_ms, uint32_t restart_delay_ms, uint32_t jump_address)
{
  int status = 0;

  if (!EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy)) {
    return EMC_USB_CELENO_CLI_Error_GENERIC;
  }

  status = EMC_USB_CELENO_CLI_FunctionProxy_umac_restart(&function_proxy,
                                                         usb_disconnect_delay_ms,
                                                         restart_delay_ms,
                                                         jump_address);
  check_status("EMC_USB_CELENO_CLI_FunctionProxy_umac_restart", status);

  return status;
}

int cl_usb_function_ioctl(uint32_t function_index,
                          uint32_t command_id,
                          uint32_t param1,
                          uint32_t param2,
                          uint32_t* result1,
                          uint32_t* result2)
{
  int status = 0;

  if (!EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy)) {
    return EMC_USB_CELENO_CLI_Error_GENERIC;
  }

  status = EMC_USB_CELENO_CLI_FunctionProxy_function_ioctl(&function_proxy,
                                                           function_index,
                                                           command_id,
                                                           param1,
                                                           param2,
                                                           result1,
                                                           result2);

  check_status("EMC_USB_CELENO_CLI_FunctionProxy_function_ioctl", status);

  return status;
}

int cl_usb_queue_start(void)
{
  if (!EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy)) {
    return EMC_USB_CELENO_CLI_Error_GENERIC;
  }

  EMC_USB_CELENO_CLI_FunctionProxy_queue_begin(&function_proxy);
  return 0;
}

int cl_usb_queue_process(void)
{
  int status = 0;

  if (!EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy)) {
    return EMC_USB_CELENO_CLI_Error_GENERIC;
  }

  status = EMC_USB_CELENO_CLI_FunctionProxy_queue_process(&function_proxy);
  check_status("EMC_USB_CELENO_CLI_FunctionProxy_queue_process", status);
  return status;
}

int cl_usb_logger_get_info(uint32_t index, char* info_string, size_t size)
{
  int status = 0;

  if (!EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy)) {
    return EMC_USB_CELENO_CLI_Error_GENERIC;
  }

  status = EMC_USB_CELENO_CLI_FunctionProxy_logger_info_get(&function_proxy, index, info_string, size);
  check_status("EMC_USB_CELENO_CLI_FunctionProxy_logger_info_get", status);

  return status;
}

int cl_usb_logger_get_level(uint32_t index, uint32_t* level)
{
  int status = 0;

  if (!EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy)) {
    return EMC_USB_CELENO_CLI_Error_GENERIC;
  }

  status = EMC_USB_CELENO_CLI_FunctionProxy_logger_level_get(&function_proxy, index, level);
  check_status("EMC_USB_CELENO_CLI_FunctionProxy_logger_level_get", status);

  return status;
}

int cl_usb_logger_set_level(uint32_t index, uint32_t level)
{
  int status = 0;

  if (!EMC_USB_CELENO_CLI_FunctionProxy_initialized(&function_proxy)) {
    return EMC_USB_CELENO_CLI_Error_GENERIC;
  }

  status = EMC_USB_CELENO_CLI_FunctionProxy_logger_level_set(&function_proxy, index, level);
  check_status("EMC_USB_CELENO_CLI_FunctionProxy_logger_level_set", status);

  return status;
}

int cl_usb_logger_level_as_int(const char* name, uint32_t* level)
{
  char  level_string[64];
  char* level_string_ws;

  if ((level == 0) || (name == 0)) {
    check_status("cl_usb_logger_level_from_string", EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER);
    return EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER;
  }
  *level = EMC_Log_priority_from_string(name);
  cl_usb_logger_level_as_string(*level, level_string, sizeof(level_string));
  // level string is potentially padded with whitespaces
  level_string_ws = strchr(level_string, ' ');
  if (strncmp(name, level_string,
              level_string_ws ? (unsigned int)(level_string_ws - level_string) : sizeof(level_string)) != 0)
  {
    return EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER;
  }
  return EMC_USB_CELENO_CLI_Error_SUCCESS;
}

int cl_usb_logger_level_as_string(uint32_t level, char* name, size_t name_size)
{
  char unknown[] = "Unknown";
  if (name == 0) {
    check_status("cl_usb_logger_level_as_string", EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER);
    return EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER;
  }
  if ((level <= EMC_LOG_PRIORITY_TRACE)) {
    strncpy(name, EMC_Log_priority_as_string(level), name_size);
  } else {
    strncpy(name, unknown, name_size);
  }
  return EMC_USB_CELENO_CLI_Error_SUCCESS;
}
