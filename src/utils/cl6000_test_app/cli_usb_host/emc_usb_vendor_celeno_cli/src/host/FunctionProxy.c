/** Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/system/celeno/configure.h"
#include "emc/vendor/celeno/configure.h"
#include "emc/usb/vendor/celeno/cli/host/FunctionProxy.h"
#include "emc/usb/vendor/celeno/cli/host/FunctionProxy_private.h"
#include "emc/usb/vendor/celeno/cli/host/CommandInit.h"

#include "emc/usb/host/hal/HAL.h"

#include "emc/usb/vendor/celeno/cli/Command.h"
#include "emc/usb/vendor/celeno/cli/Response.h"

#include "emc/std/assert.h"
#include "emc/std/ext/ct_assert.h"
#include "emc/std/string.h"

#if EMC_PRINT
#  include "emc/std/stdio.h"
#  include "emc/data/form/helper_macros.h"
#  include "emc/data/form/indent.h"
#endif

#include "emc/log/log.h"

EMC_STATIC_LOG_LEVEL_DEFINE(EMC_USB_VENDOR_CELENO_CLI_LOG_LEVEL);

static EMC_USB_CELENO_CLI_Error convert_error(EMC_USB_HOST_HAL_Error host_error)
{
  EMC_USB_CELENO_CLI_Error result;
  switch (host_error) {
  case EMC_USB_HOST_HAL_Error_NONE:
    result = EMC_USB_CELENO_CLI_Error_SUCCESS; break;
  case EMC_USB_HOST_HAL_Error_TIMEOUT:
    result = EMC_USB_CELENO_CLI_Error_TIMEOUT; break;
  case EMC_USB_HOST_HAL_Error_INVALID_PARAMETER:
  case EMC_USB_HOST_HAL_Error_INVALID_DEVICE:
  case EMC_USB_HOST_HAL_Error_INVALID_EP:
  case EMC_USB_HOST_HAL_Error_INVALID_BUFFER_SIZE:
    result = EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER; break;
  default:
    result = EMC_USB_CELENO_CLI_Error_CONNECTION_ERROR; break;
  }
  return result;
}

void EMC_USB_CELENO_CLI_FunctionProxyConfig_init(EMC_USB_CELENO_CLI_FunctionProxyConfig* config)
{
  emc_std_memset(config, 0, sizeof(EMC_USB_CELENO_CLI_FunctionProxyConfig));
  config->transfer_timeout_ms = 1000;
}

static EMC_USB_HOST_HAL_Interface* open_interface(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                  emc_std_uint16_t pid,
                                                  emc_std_uint16_t bcd_device,
                                                  emc_std_uint8_t* sn)
{
  (void)self;

  if (0 == pid) {
    pid = CELENO_PRODUCT_ID;
  }
  EMC_LOG3(self->logger, INFO, "try to open interface with pid: 0x%04X bcd: 0x%04X sn: %ls", pid, bcd_device, sn);
  return EMC_USB_HOST_HAL_interface_open(CELENO_CLI_IFC_NUM, CELENO_VENDOR_ID, pid, bcd_device, sn);
}

int EMC_USB_CELENO_CLI_FunctionProxy_init(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                          const EMC_USB_CELENO_CLI_FunctionProxyConfig* config)
{
  EMC_CT_ASSERT(0 == (EMC_USB_CELENO_CLI_Command_SIZE % sizeof(emc_std_uint32_t)));
  EMC_CT_ASSERT(sizeof(EMC_USB_CELENO_CLI_Command) == EMC_USB_CELENO_CLI_Command_SIZE);
  EMC_CT_ASSERT(sizeof(EMC_USB_CELENO_CLI_Response) == EMC_USB_CELENO_CLI_Command_SIZE);

  emc_std_assert(self);
  emc_std_memset(self, 0, sizeof(EMC_USB_CELENO_CLI_FunctionProxy));
  self->logger = EMC_Log_logger("emc.usb.host.cli");
  self->sequence_id = 0;
  self->rx_ep_max_packet_size = 1024; /* get from descriptor*/
  self->tx_ep_max_packet_size = 1024; /* get from descriptor*/
  self->tx_queue_depth = -1;
  self->tx_first_pending = 0;
  self->tx_buffer_wptr = self->tx_buffer;
  self->transfer_timeout_ms = config->transfer_timeout_ms;

  self->hal_interface = open_interface(self, config->pid, config->bcd_device, config->sn);
  return (self->hal_interface != NULL)
         ? EMC_USB_CELENO_CLI_Error_SUCCESS
         : EMC_USB_CELENO_CLI_Error_CONNECTION_ERROR;
}

int EMC_USB_CELENO_CLI_FunctionProxy_initialized(EMC_USB_CELENO_CLI_FunctionProxy* self)
{
  return (self->hal_interface != NULL) ? 1 : 0;
}

int EMC_USB_CELENO_CLI_FunctionProxy_start(EMC_USB_CELENO_CLI_FunctionProxy* self)
{
  emc_std_assert(self);

  self->tx_ep =
    EMC_USB_HOST_HAL_ep_enable(CELENO_CLI_BULK_OUT,
                               EMC_USB_TransferType_BULK,
                               self->transfer_timeout_ms,
                               &self->tx_ep_max_packet_size);
  self->rx_ep = EMC_USB_HOST_HAL_ep_enable(CELENO_CLI_BULK_IN,
                                           EMC_USB_TransferType_BULK,
                                           self->transfer_timeout_ms,
                                           &self->rx_ep_max_packet_size);

  return EMC_USB_CELENO_CLI_Error_SUCCESS;
}

int EMC_USB_CELENO_CLI_FunctionProxy_stop(EMC_USB_CELENO_CLI_FunctionProxy* self)
{
  emc_std_assert(self);
  EMC_USB_HOST_HAL_ep_disable(self->tx_ep);
  EMC_USB_HOST_HAL_ep_disable(self->rx_ep);
  return EMC_USB_CELENO_CLI_Error_SUCCESS;
}

int EMC_USB_CELENO_CLI_FunctionProxy_reset(EMC_USB_CELENO_CLI_FunctionProxy* self)
{
  int error = EMC_USB_CELENO_CLI_Error_SUCCESS;

  EMC_USB_CELENO_CLI_FunctionProxy_stop(self);
  error = EMC_USB_HOST_HAL_interface_set_alt_setting(1);
  error |= EMC_USB_HOST_HAL_interface_set_alt_setting(0);
  EMC_USB_CELENO_CLI_FunctionProxy_start(self);
  return error;
}

void EMC_USB_CELENO_CLI_FunctionProxy_exit(EMC_USB_CELENO_CLI_FunctionProxy* self)
{
  if (self) {
    EMC_USB_HOST_HAL_interface_close(self->hal_interface);
    emc_std_memset(self, 0, sizeof(EMC_USB_CELENO_CLI_FunctionProxy));
  }
}

static int is_queueing(EMC_USB_CELENO_CLI_FunctionProxy* self)
{
  return (self->tx_queue_depth < 0) ? 0 : 1;
}

static int store_command(EMC_USB_CELENO_CLI_FunctionProxy* self, EMC_USB_CELENO_CLI_Command* command)
{
  int error = EMC_USB_CELENO_CLI_Error_SUCCESS;

  self->sequence_id++;
  command->sequence_id = self->sequence_id;
  EMC_LOG2(self->logger, DEBUG, "command=0x%x, sequence_id=%d", command->id, command->sequence_id);

  if (is_queueing(self)) {
    self->tx_queue_depth++;
    if ((unsigned)self->tx_queue_depth > EMC_USB_VENDOR_CELENO_CLI_MAX_CMD_TRANSFER_ITEMS) {
      error = EMC_USB_CELENO_CLI_Error_QUEUE_OVERFLOW;
    } else {
      if (EMC_USB_CELENO_CLI_CommandId_has_response(command->id) && !self->tx_first_pending) {
        self->tx_first_pending = self->tx_buffer_wptr;
      }
      error = EMC_USB_CELENO_CLI_Error_PENDING;
    }
  }

  if (EMC_USB_CELENO_CLI_Error_QUEUE_OVERFLOW != error) {
    EMC_USB_CELENO_CLI_Command_put(command, (void**)&self->tx_buffer_wptr);
  }

  return error;
}

static int transmit_single_command(EMC_USB_CELENO_CLI_FunctionProxy* self, EMC_USB_CELENO_CLI_Command* command)
{
  int result;

  result = EMC_USB_HOST_HAL_ep_write(self->tx_ep, self->tx_buffer, EMC_USB_CELENO_CLI_Command_SIZE);
  self->tx_buffer_wptr = self->tx_buffer;

  if (result != EMC_USB_CELENO_CLI_Command_SIZE) {
    EMC_LOG3(self->logger, WARN, "write error %d for command=0x%x, sequence_id=%d",
             result, command->id, command->sequence_id);

    return EMC_USB_CELENO_CLI_Error_CONNECTION_ERROR;
  }

  return EMC_USB_CELENO_CLI_Error_SUCCESS;
}

static int transmit_queued_commands(EMC_USB_CELENO_CLI_FunctionProxy* self)
{
  int    result;
  size_t tx_length;

  if (self->tx_queue_depth <= 0) {
    EMC_LOG1(self->logger, WARN, "no queued commands (%d)", self->tx_queue_depth);
    return EMC_USB_CELENO_CLI_Error_QUEUE_EMPTY;
  }
  tx_length = (size_t)self->tx_queue_depth * EMC_USB_CELENO_CLI_Command_SIZE;

  result = EMC_USB_HOST_HAL_ep_write(self->tx_ep, self->tx_buffer, tx_length);
  self->tx_buffer_wptr = self->tx_buffer;

  if (result != (int)tx_length) {
    EMC_LOG1(self->logger, WARN, "queue write error %d", result);
    return EMC_USB_CELENO_CLI_Error_CONNECTION_ERROR;
  }

  return EMC_USB_CELENO_CLI_Error_SUCCESS;
}

static int transmit_data(EMC_USB_CELENO_CLI_FunctionProxy* self, const void* data, size_t size)
{
  int result;

  EMC_LOG2(self->logger, DEBUG, "data=0x%p, size=%d", data, size);

  result = EMC_USB_HOST_HAL_ep_write(self->tx_ep, data, size);

  if (result != (int)size) {
    EMC_LOG3(self->logger, WARN, "write error 0x%x for data=0x%p, size=%d",
             result, data, size);

    return EMC_USB_CELENO_CLI_Error_CONNECTION_ERROR;

  } else {
    if ((size % self->tx_ep_max_packet_size) == 0) {
      EMC_LOG1(self->logger, INFO, "generate zero packet for length=%d", size);
      result = EMC_USB_HOST_HAL_ep_write(self->tx_ep, EMC_STD_NULL, 0);
      if (result != 0) {
        return EMC_USB_CELENO_CLI_Error_CONNECTION_ERROR;
      }
    }

    return EMC_USB_CELENO_CLI_Error_SUCCESS;
  }

}

static int receive_responses_for_sequence(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                          emc_std_uint32_t sequence_id)
{
  unsigned                    retry_count = 1;
  int                         result;
  void*                       buffer_ptr = self->rx_buffer;
  EMC_USB_CELENO_CLI_Response response;

  EMC_LOG(self->logger, DEBUG, "");

  self->rx_responses = 0;
  while (retry_count) {
    result = EMC_USB_HOST_HAL_ep_read(self->rx_ep,
                                      self->rx_buffer,
                                      EMC_USB_VENDOR_CELENO_CLI_MAX_COMMAND_TRANSFER_LENGTH);
    if (result >= EMC_USB_CELENO_CLI_Response_SIZE) {
      EMC_USB_CELENO_CLI_Response_get(&response, &buffer_ptr);
      if (response.sequence_id == sequence_id) {
        break;
      } else {
        EMC_LOG3(self->logger,
                 WARN,
                 "response.sequence_id 0x%x does not match command.sequence_id 0x%x, retries left =%u",
                 response.sequence_id,
                 sequence_id,
                 retry_count);
      }
    } else if (result >= 0) {
      EMC_LOG1(self->logger, WARN, "invalid response transfer (%d bytes)", result);
      return EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_LENGTH;
    } else {
      EMC_LOG2(self->logger, WARN, "EMC_USB_HOST_HAL_ep_read failed (%d), retries left =%u", result, retry_count);
      return convert_error(result);
    }
    result = 0;
    --retry_count;
  }

  if (result < EMC_USB_CELENO_CLI_Response_SIZE) {
    return EMC_USB_CELENO_CLI_Error_TIMEOUT;
  }

  self->rx_responses = (emc_std_uint32_t)result / EMC_USB_CELENO_CLI_Response_SIZE;
  self->rx_buffer_rptr = self->rx_buffer;
  EMC_LOG1(self->logger, INFO, "received valid response(s) (%d bytes in total)", result);
  return EMC_USB_CELENO_CLI_Error_SUCCESS;
}

static int get_response_for_command(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                    EMC_USB_CELENO_CLI_Command* command,
                                    EMC_USB_CELENO_CLI_Response* response)
{
  if (!self->rx_responses) {
    EMC_LOG(self->logger, WARN, "no more responses");
    return EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_LENGTH;
  }
  EMC_USB_CELENO_CLI_Response_get(response, (void**)&self->rx_buffer_rptr);
  self->rx_responses--;

  if (response->status != EMC_USB_CELENO_CLI_Status_SUCCESS) {
    EMC_LOG1(self->logger, WARN, "error 0x%x for rx_response", response->status);
    return EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_STATUS;
  }
  if (response->id != command->id) {
    EMC_LOG2(self->logger, WARN, "response.id 0x%x does not match command.id 0x%x", response->id, command->id);
    return EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_TYPE;
  }
  EMC_LOG2(self->logger, INFO, "found response 0x%x (sequence %u)", response->id, response->sequence_id);

  return EMC_USB_CELENO_CLI_Error_SUCCESS;
}

static int receive_data(EMC_USB_CELENO_CLI_FunctionProxy* self, void* data, size_t size)
{
  int result;
  EMC_LOG2(self->logger, INFO, "data 0x%p, size = %d", data, size);

  result = EMC_USB_HOST_HAL_ep_read(self->rx_ep, self->data_buffer, sizeof(self->data_buffer));
  if (result > 0) {
    emc_std_memcpy(data, self->data_buffer, (emc_std_size_t)result);
    // read ZLP
    if (result == EMC_USB_VENDOR_CELENO_CLI_MAX_DATA_TRANSFER_LENGTH) {
      EMC_USB_HOST_HAL_ep_read(self->rx_ep, self->data_buffer, sizeof(self->data_buffer));
    }
  }

  if (result < 0) {
    EMC_LOG1(self->logger, WARN, "ep_read error=0x%x", result);
    return convert_error(result);
  } else {
    return result;
  }
}

static int process_command(EMC_USB_CELENO_CLI_FunctionProxy* self,
                           EMC_USB_CELENO_CLI_Command* command,
                           EMC_USB_CELENO_CLI_Response* response)
{
  int error = transmit_single_command(self, command);
  if (!error && response) {
    error = receive_responses_for_sequence(self, command->sequence_id);
    if (!error) {
      error = get_response_for_command(self, command, response);
    }
  }

  return error;
}

int EMC_USB_CELENO_CLI_FunctionProxy_any_command(EMC_USB_CELENO_CLI_FunctionProxy* self, uint32_t id)
{
  int error;

  EMC_USB_CELENO_CLI_Command  command;
  EMC_USB_CELENO_CLI_Response response;

  emc_std_memset(&command, 0, EMC_USB_CELENO_CLI_Command_SIZE);
  command.id = id;

  error = store_command(self, &command);
  if (!error) {
    error = process_command(self, &command, &response);
  }

  return error;
}

int EMC_USB_CELENO_CLI_FunctionProxy_get_version(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                 uint32_t* protocol,
                                                 uint32_t* firmware)
{
  int error = EMC_USB_CELENO_CLI_Error_SUCCESS;

  EMC_USB_CELENO_CLI_Command  command;
  EMC_USB_CELENO_CLI_Response response;

  if ((protocol == 0) || (firmware == 0)) {
    EMC_LOG(self->logger, ERROR, "Invalid Parameter");
    return EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER;
  }

  if (is_queueing(self)) {
    EMC_LOG(self->logger, WARN, "Queueing not allowed");
    error = EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED;
  }

  if (!error) {
    EMC_USB_CELENO_CLI_Command_init_get_version(&command);

    error = store_command(self, &command);
    if (!error) {
      error = process_command(self, &command, &response);
    }
    if (!error) {
      *protocol = response.param.version.protocol;
      *firmware = response.param.version.firmware;
    }
  }

  return error;
}

int EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(EMC_USB_CELENO_CLI_FunctionProxy* self)
{
  int error;

  EMC_USB_CELENO_CLI_Command  command;
  EMC_USB_CELENO_CLI_Response response;

  if (is_queueing(self)) {
    EMC_LOG(self->logger, WARN, "Queueing not allowed");
    return EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED;
  }

  EMC_USB_CELENO_CLI_Command_init_keep_alive(&command);

  error = store_command(self, &command);
  if (!error) {
    error = process_command(self, &command, &response);
  }

  return error;
}

int EMC_USB_CELENO_CLI_FunctionProxy_usb_disconnect(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                    emc_std_uint32_t usb_disconnect_delay_ms)
{
  int error;

  EMC_USB_CELENO_CLI_Command command;

  if (is_queueing(self)) {
    EMC_LOG(self->logger, WARN, "Queueing not allowed");
    return EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED;
  }

  EMC_USB_CELENO_CLI_Command_init_usb_disconnect(&command, usb_disconnect_delay_ms);

  error = store_command(self, &command);
  if (!error) {
    error = process_command(self, &command, 0);
  }

  return error;
}

int EMC_USB_CELENO_CLI_FunctionProxy_umac_execute(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                  emc_std_uint32_t jump_address)
{
  int error;

  EMC_USB_CELENO_CLI_Command command;

  if (is_queueing(self)) {
    EMC_LOG(self->logger, WARN, "Queueing not allowed");
    return EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED;
  }

  EMC_USB_CELENO_CLI_Command_init_umac_execute(&command, jump_address);

  error = store_command(self, &command);
  if (!error) {
    error = process_command(self, &command, 0);
  }

  return error;
}

int EMC_USB_CELENO_CLI_FunctionProxy_umac_restart(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                  emc_std_uint32_t usb_disconnect_delay_ms,
                                                  emc_std_uint32_t restart_delay_ms,
                                                  emc_std_uint32_t jump_address)
{
  int error;

  EMC_USB_CELENO_CLI_Command command;

  if (is_queueing(self)) {
    EMC_LOG(self->logger, WARN, "Queueing not allowed");
    return EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED;
  }

  EMC_USB_CELENO_CLI_Command_init_umac_restart(&command, usb_disconnect_delay_ms, restart_delay_ms, jump_address);

  error = store_command(self, &command);
  if (!error) {
    error = process_command(self, &command, 0);
  }

  return error;
}

int EMC_USB_CELENO_CLI_FunctionProxy_logger_level_get(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                      emc_std_uint32_t index,
                                                      emc_std_uint32_t* level)
{
  int error = EMC_USB_CELENO_CLI_Error_SUCCESS;

  EMC_USB_CELENO_CLI_Command  command;
  EMC_USB_CELENO_CLI_Response response;

  if (level == 0) {
    EMC_LOG(self->logger, ERROR, "Invalid Parameter");
    error = EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER;
  }

  if (!error) {
    if (is_queueing(self)) {
      EMC_LOG(self->logger, WARN, "Queueing not allowed");
      error = EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED;
    }
  }

  EMC_USB_CELENO_CLI_Command_init_logger_level_get(&command, index);
  error = store_command(self, &command);
  if (!error) {
    error = process_command(self, &command, &response);
  }
  if (!error) {
    *level = response.param.data;
  }

  return error;
}

int EMC_USB_CELENO_CLI_FunctionProxy_logger_level_set(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                      emc_std_uint32_t index,
                                                      emc_std_uint32_t level)
{
  int error = EMC_USB_CELENO_CLI_Error_SUCCESS;

  EMC_USB_CELENO_CLI_Command  command;
  EMC_USB_CELENO_CLI_Response response;

  if (!error) {
    if (is_queueing(self)) {
      EMC_LOG(self->logger, WARN, "Queueing not allowed");
      error = EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED;
    }
  }

  EMC_USB_CELENO_CLI_Command_init_logger_level_set(&command, index, level);
  error = store_command(self, &command);
  if (!error) {
    error = process_command(self, &command, &response);
  }

  return error;
}

int EMC_USB_CELENO_CLI_FunctionProxy_logger_info_get(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                     emc_std_uint32_t index,
                                                     char* info_string,
                                                     size_t size)
{
  char logger_info[256];
  int  error;

  EMC_USB_CELENO_CLI_Command  command;
  EMC_USB_CELENO_CLI_Response response;

  if ((info_string == 0) || (size == 0)) {
    EMC_LOG(self->logger, ERROR, "Invalid Parameter");
    return EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER;
  }

  if (is_queueing(self)) {
    EMC_LOG(self->logger, WARN, "Queueing not allowed");
    return EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED;
  }

  EMC_USB_CELENO_CLI_Command_init_logger_info_get(&command, index);
  store_command(self, &command);

  error = transmit_single_command(self, &command);
  if (!error) {
    error = receive_responses_for_sequence(self, command.sequence_id);
    if (!error) {
      error = get_response_for_command(self, &command, &response);
    }
  }
  if (!error) {
    error = receive_data(self, logger_info, sizeof(logger_info));
    if (error >= 0) {
      emc_std_size_t rx_length = (emc_std_size_t)error;
      EMC_LOG1(self->logger, WARN, "rx_length = %u", rx_length);
      if (rx_length <= size) {
        if ((rx_length == sizeof(emc_std_uint32_t)) && (logger_info[0] == '\0')) {
          // no logger for this index
          *info_string = 0;
          error = EMC_USB_CELENO_CLI_Error_SUCCESS;
        } else {
          emc_std_strncpy(info_string, logger_info, rx_length);
          error = EMC_USB_CELENO_CLI_Error_SUCCESS;
        }
      } else {
        // user buffer too small
        EMC_LOG1(self->logger, WARN, "Truncating info string by %u bytes", rx_length - size);
        rx_length = size;
        logger_info[rx_length - 1] = '\0';
        emc_std_strncpy(info_string, logger_info, rx_length);
        error = EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_LENGTH;
      }
    } else {
      info_string[0] = '\0';
    }
  }

  return error;
}

int EMC_USB_CELENO_CLI_FunctionProxy_function_ioctl(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                    emc_std_uint32_t function_index,
                                                    emc_std_uint32_t command_id,
                                                    emc_std_uint32_t param1,
                                                    emc_std_uint32_t param2,
                                                    emc_std_uint32_t* result1,
                                                    emc_std_uint32_t* result2
                                                    )
{
  int error;

  EMC_USB_CELENO_CLI_Command  command;
  EMC_USB_CELENO_CLI_Response response;

  if (is_queueing(self)) {
    EMC_LOG(self->logger, WARN, "Queueing not allowed");
    return EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED;
  }

  if (function_index >= EMC_USB_CELENO_CLI_FUNCTION_IOCTL_MAX) {
    EMC_LOG2(self->logger,
             WARN,
             "Index (%d) larger than expected %d",
             function_index,
             EMC_USB_CELENO_CLI_FUNCTION_IOCTL_MAX);
    return EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER;
  }

  EMC_USB_CELENO_CLI_Command_init_function_ioctl(&command, function_index, command_id, param1, param2);
  store_command(self, &command);

  error = process_command(self, &command, &response);
  if (!error) {
    if (result1) {
      *result1 = response.param.function_data.data1;
    }
    if (result2) {
      *result2 = response.param.function_data.data2;
    }
  }
  return error;
}

int EMC_USB_CELENO_CLI_FunctionProxy_write(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                           emc_std_uint32_t address,
                                           emc_std_uint32_t data,
                                           emc_std_uint32_t mask)
{
  int error;

  EMC_USB_CELENO_CLI_Command  command;
  EMC_USB_CELENO_CLI_Response response;

  EMC_USB_CELENO_CLI_Command_init_write(&command, address, data, mask);

  error = store_command(self, &command);
  if (!error) {
    error = process_command(self, &command, &response);
  }

  return error;
}

int EMC_USB_CELENO_CLI_FunctionProxy_write_fast(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                emc_std_uint32_t address,
                                                emc_std_uint32_t data,
                                                emc_std_uint32_t mask)
{
  int error;

  EMC_USB_CELENO_CLI_Command command;

  EMC_USB_CELENO_CLI_Command_init_write_fast(&command, address, data, mask);

  error = store_command(self, &command);
  if (!error) {
    error = process_command(self, &command, 0);
  }

  return error;
}

int EMC_USB_CELENO_CLI_FunctionProxy_read(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                          emc_std_uint32_t address,
                                          emc_std_uint32_t* data)
{
  int error;

  EMC_USB_CELENO_CLI_Command  command;
  EMC_USB_CELENO_CLI_Response response;

  if (data == 0) {
    EMC_LOG(self->logger, ERROR, "Invalid Parameter");
    return EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER;
  }

  EMC_USB_CELENO_CLI_Command_init_read(&command, address);

  if (is_queueing(self)) {
    self->rx_read_values[self->tx_queue_depth] = data;
  }

  error = store_command(self, &command);
  if (!error) {
    error = process_command(self, &command, &response);
  }
  if (!error) {
    *data = response.param.data;
  }

  return error;
}

int EMC_USB_CELENO_CLI_FunctionProxy_burst_write(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                 emc_std_uint32_t address,
                                                 const void* data,
                                                 size_t size,
                                                 emc_std_bool zero_copy)
{
  int error = EMC_USB_CELENO_CLI_Error_SUCCESS;

  EMC_USB_CELENO_CLI_Command  command;
  EMC_USB_CELENO_CLI_Response response;

  if (data == 0) {
    EMC_LOG(self->logger, ERROR, "Invalid Parameter");
    return EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER;
  }

  if (is_queueing(self)) {
    EMC_LOG(self->logger, WARN, "Queueing not allowed");
    error = EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED;
  }

  if (!error) {

    EMC_USB_CELENO_CLI_Command_init_burst_write(&command, address, (emc_std_uint32_t)size, zero_copy);
    store_command(self, &command);

    error = transmit_single_command(self, &command);
    if (!error) {
      error = transmit_data(self, data, size);
    }
    if (!error) {
      error = receive_responses_for_sequence(self, command.sequence_id);
      if (!error) {
        error = get_response_for_command(self, &command, &response);
      }
    }
  }

  return error;
}

int EMC_USB_CELENO_CLI_FunctionProxy_burst_write_fast(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                      emc_std_uint32_t address,
                                                      const void* data,
                                                      size_t size,
                                                      emc_std_bool zero_copy)
{
  int error = EMC_USB_CELENO_CLI_Error_SUCCESS;

  EMC_USB_CELENO_CLI_Command command;

  if (data == 0) {
    EMC_LOG(self->logger, ERROR, "Invalid Parameter");
    return EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER;
  }

  if (is_queueing(self)) {
    EMC_LOG(self->logger, WARN, "Queueing not allowed");
    error = EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED;
  }

  if (!error) {

    EMC_USB_CELENO_CLI_Command_init_burst_write_fast(&command, address, (emc_std_uint32_t)size, zero_copy);
    store_command(self, &command);

    error = transmit_single_command(self, &command);
    if (!error) {
      error = transmit_data(self, data, size);
    }
  }

  return error;
}

int EMC_USB_CELENO_CLI_FunctionProxy_burst_read(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                emc_std_uint32_t address,
                                                void* data,
                                                size_t size,
                                                emc_std_bool zero_copy)
{
  int error = EMC_USB_CELENO_CLI_Error_SUCCESS;
  int rx_length;

  EMC_USB_CELENO_CLI_Command  command;
  EMC_USB_CELENO_CLI_Response response;

  if (data == 0) {
    EMC_LOG(self->logger, ERROR, "Invalid Parameter");
    return EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER;
  }

  if (is_queueing(self)) {
    EMC_LOG(self->logger, WARN, "Queueing not allowed");
    error = EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED;
  }

  if (!error) {

    EMC_USB_CELENO_CLI_Command_init_burst_read(&command, address, (emc_std_uint32_t)size, zero_copy);
    store_command(self, &command);

    error = transmit_single_command(self, &command);
    if (!error) {
      error = receive_responses_for_sequence(self, command.sequence_id);
      if (!error) {
        error = get_response_for_command(self, &command, &response);
      }
    }
    if (!error) {
      rx_length = receive_data(self, data, size);
      if (rx_length != (int)size) {
        error = EMC_USB_CELENO_CLI_Error_CONNECTION_ERROR;
      }
    }
  }

  return error;
}

void EMC_USB_CELENO_CLI_FunctionProxy_queue_begin(EMC_USB_CELENO_CLI_FunctionProxy* self)
{
  self->tx_queue_depth = 0;
  self->tx_first_pending = 0;
  self->tx_buffer_wptr = self->tx_buffer;
}

int EMC_USB_CELENO_CLI_FunctionProxy_queue_process(EMC_USB_CELENO_CLI_FunctionProxy* self)
{
  int                         error;
  EMC_USB_CELENO_CLI_Command  command;
  EMC_USB_CELENO_CLI_Response response;

  void*            cmd_ptr;
  emc_std_uint32_t cmd_index;

  error = transmit_queued_commands(self);
  if (!error && self->tx_first_pending) {
    cmd_ptr = self->tx_first_pending;
    EMC_USB_CELENO_CLI_Command_get(&command, &cmd_ptr);
    error = receive_responses_for_sequence(self, command.sequence_id);
    if (!error) {
      cmd_ptr = self->tx_buffer;
      cmd_index = 0;
      while (self->tx_queue_depth) {
        EMC_USB_CELENO_CLI_Command_get(&command, &cmd_ptr);
        if (EMC_USB_CELENO_CLI_CommandId_has_response(command.id)) {
          error = get_response_for_command(self, &command, &response);
          if (error) {
            return error;
          }
          if (EMC_USB_CELENO_CLI_CommandId_SINGLE_READ == response.id) {
            *self->rx_read_values[cmd_index] = response.param.data;
          }
        }
        ++cmd_index;
        --self->tx_queue_depth;
      }
    }
  }

  self->tx_queue_depth = -1;
  return error;
}

int EMC_USB_CELENO_CLI_FunctionProxy_raw_write(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                               const void* data,
                                               emc_std_size_t size)
{
  return transmit_data(self, data, size);
}

#if EMC_PRINT
void EMC_USB_CELENO_CLI_FunctionProxy_print(const EMC_USB_CELENO_CLI_FunctionProxy* self, FILE* file)
{
  emc_std_assert(self);
  FORM_START_HEAD(file, EMC_USB_CELENO_CLI_FunctionProxy);
  FORM_ATTR_HEX(file, sequence_id, self->sequence_id);
  FORM_END_HEAD(file);
  FORM_END(file, EMC_USB_CELENO_CLI_FunctionProxy);
}

#endif /*EMC_PRINT*/
