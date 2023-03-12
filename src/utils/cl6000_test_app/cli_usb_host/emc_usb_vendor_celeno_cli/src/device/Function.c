/** Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/usb/vendor/celeno/cli/device/Function.h"
#include "emc/usb/vendor/celeno/cli/device/Function_private.h"
#include "emc/usb/vendor/celeno/cli/device/ResponseInit.h"

#include "emc/usb/vendor/celeno/cli/Command.h"
#include "emc/usb/vendor/celeno/cli/Response.h"

#include "emc/usb/device/Device.h"
#include "emc/usb/device/Interface.h"
#include "emc/usb/device/Function.h"

#include "emc/usb/device/hal/UsbHal.h"
#include "emc/usb/usb.h"

#include "emc/std/assert.h"
#include "emc/std/ext/ct_assert.h"
#include "emc/std/string.h"

#include "emc/data/numop.h"

#if EMC_PRINT
#  include "emc/std/stdio.h"
#  include "emc/data/form/helper_macros.h"
#  include "emc/data/form/indent.h"
#endif

#include "emc/usb/vendor/celeno/cli/TargetMemory.h"
#include "emc/usb/vendor/celeno/cli/device/TargetOperations.h"

#include "../dma_copy.h"
#include "emc/log/log.h"
#include "emc/log/log_payload.h"

EMC_STATIC_LOG_LEVEL_DEFINE(EMC_USB_VENDOR_CELENO_CLI_LOG_LEVEL);

EMC_USB_CELENO_CLI_Function* mg_function = 0;

static emc_std_bool prepare_rx_data(EMC_USB_CELENO_CLI_Function* self);

const char* EMC_USB_CELENO_CLI_State_as_string(EMC_USB_CELENO_CLI_State state)
{
  const char* result;
  switch (state) {
  case EMC_USB_CELENO_CLI_State_RX_COMMAND: result = "RX_COMMAND"; break;
  case EMC_USB_CELENO_CLI_State_RX_DATA: result = "RX_DATA"; break;
  case EMC_USB_CELENO_CLI_State_RX_DUMMY_DATA: result = "RX_DUMMY_DATA"; break;
  case EMC_USB_CELENO_CLI_State_TX_RESPONSE: result = "TX_RESPONSE"; break;
  case EMC_USB_CELENO_CLI_State_TX_DATA: result = "TX_DATA"; break;
  default:
    result = "Unknown";
  }
  return result;
}

static void set_state(EMC_USB_CELENO_CLI_Function* function, EMC_USB_CELENO_CLI_State state)
{
  if (state != function->state) {
    EMC_LOG1(function->logger, DEBUG, "state=%s", EMC_USB_CELENO_CLI_State_as_string(state));
    function->state = state;
  }
}

static void process_get_version(EMC_USB_CELENO_CLI_Function* function)
{
  EMC_FUNCTION(function->logger, INFO);

  EMC_USB_CELENO_CLI_Response_set_version(&function->response, &function->version);
}

static void process_keep_alive(EMC_USB_CELENO_CLI_Function* function)
{
  EMC_FUNCTION(function->logger, INFO);
  UNUSED_PARAM(function);
}

static void process_disconnect(EMC_USB_CELENO_CLI_Function* function)
{
  EMC_LOG1(function->logger, INFO, "USBDisconnectDelay=%dms",
           function->command.param.disconnect.usb_disconnect_delay_ms);
  EMC_USB_CELENO_CLI_usb_disconnect(function->command.param.disconnect.usb_disconnect_delay_ms, 0);
  EMC_LOG(function->logger, DEBUG, "done");
}

static void process_execute(EMC_USB_CELENO_CLI_Function* function)
{
  uintptr_t address = function->command.param.execute.address;
  EMC_LOG1(function->logger, INFO, "jump_address=0x%08x", address);
  EMC_USB_CELENO_CLI_umac_execute((void*)address);
}

static void process_umac_restart(EMC_USB_CELENO_CLI_Function* function)
{
  uintptr_t jump_address = function->command.param.restart.jump_address;
  EMC_LOG3(function->logger, INFO, "USBDisconnectDelay=%dms RestartDelay=%dms JumpAddress=0x%08X",
           function->command.param.restart.usb_disconnect_delay_ms, function->command.param.restart.restart_delay_ms,
           jump_address);
  EMC_USB_CELENO_CLI_usb_disconnect(function->command.param.restart.usb_disconnect_delay_ms,
                                    function->command.param.restart.restart_delay_ms);
  EMC_USB_CELENO_CLI_umac_execute((void*)jump_address);
  EMC_LOG(function->logger, DEBUG, "done");
}

static void process_logger_get_level(EMC_USB_CELENO_CLI_Function* function)
{
  const emc_logger_t* logger;
  emc_std_uint32_t    index = function->command.param.logger_get.index;

  logger = EMC_Log_logger_by_index(index);
  if (!logger) {
    EMC_LOG1(function->logger, INFO, "no logger for index %u", index);
    function->response.status = EMC_USB_CELENO_CLI_Status_INVALID_ADDRESS;
  } else {
    uint32_t level = EMC_Log_priority(logger);
    EMC_LOG2(function->logger, INFO, "index %u = %d", index, level);
    function->response.param.data = level;
  }
}

static void process_logger_set_level(EMC_USB_CELENO_CLI_Function* function)
{
  emc_logger_t*    logger;
  emc_std_uint32_t index = function->command.param.logger_level_set.index;

  logger = EMC_Log_logger_by_index(index);
  if (!logger) {
    EMC_LOG1(function->logger, INFO, "no logger for index %u", index);
    function->response.status = EMC_USB_CELENO_CLI_Status_INVALID_ADDRESS;
  } else {
    uint32_t new_level = function->command.param.logger_level_set.level;
    EMC_LOG2(function->logger, INFO, "index %u = %d", index, new_level);
    EMC_Log_set_priority(logger, new_level);
  }
}

static void process_logger_get_info(EMC_USB_CELENO_CLI_Function* function)
{
  emc_logger_t*    logger;
  void*            dst = function->tx_buffer;
  emc_std_uint32_t index = function->command.param.logger_get.index;

  function->bulk_data_zero_copy = emc_std_false;

  logger = EMC_Log_logger_by_index(index);
  if (!logger) {
    EMC_LOG1(function->logger, INFO, "no logger for index %u", index);
    *(emc_std_uint32_t*)dst = 0x0;
    function->data_length = sizeof(emc_std_uint32_t);
  } else {
    EMC_LOG1(function->logger, INFO, "index %u", index);
    function->data_length = (emc_std_uint32_t)EMC_Log_logger_info(logger, dst, function->tx_buffer_size);
  }
  function->tx_data_in_tx_buffer = emc_std_true;
}

static void process_read(EMC_USB_CELENO_CLI_Function* function)
{
  emc_std_uint32_t address = function->command.param.read.address;

  if (address % sizeof(emc_std_uint32_t)) {
    function->response.status = EMC_USB_CELENO_CLI_Status_INVALID_ADDRESS;
  } else {
    emc_std_uint32_t data = EMC_USB_CELENO_CLI_TargetMemory_read(address);

    EMC_LOG2(function->logger, INFO, "address=0x%08x data=0x%08x", address, data);

    EMC_USB_CELENO_CLI_Response_set_data(&function->response, data);
  }
}

static void process_write(EMC_USB_CELENO_CLI_Function* function)
{
  emc_std_uint32_t address = function->command.param.write.address;
  EMC_LOG3(function->logger, INFO, "address=0x%08x data=0x%08x mask=0x%08x", address,
           function->command.param.write.data,
           function->command.param.write.mask);

  if (address % sizeof(emc_std_uint32_t)) {
    function->response.status = EMC_USB_CELENO_CLI_Status_INVALID_ADDRESS;
  } else {
    EMC_USB_CELENO_CLI_TargetMemory_write(address,
                                          function->command.param.write.data,
                                          function->command.param.write.mask);
  }
}

static void process_burst_read(EMC_USB_CELENO_CLI_Function* function, emc_std_bool zero_copy)
{
  emc_std_uint32_t address = function->command.param.burst_read.address;
  emc_std_uint32_t data_length = function->command.param.burst_read.length;
  function->bulk_data_zero_copy = zero_copy;

  if (address % sizeof(emc_std_uint32_t) || data_length % sizeof(emc_std_uint32_t)) {
    function->data_address = 0;
    function->data_length = 0;
    function->response.status = EMC_USB_CELENO_CLI_Status_INVALID_ADDRESS;
    EMC_LOG2(function->logger, WARN, "alignment issue address=0x%08x, length=0x%04x", address, data_length);
  } else {
    function->data_address = address;
    function->data_length = data_length;
  }
  EMC_LOG3(function->logger, INFO, "address=0x%08x length=0x%04x zerocopy=%d",
           function->data_address, function->data_length, zero_copy);
}

static void process_burst_write(EMC_USB_CELENO_CLI_Function* function, emc_std_bool zero_copy)
{
  emc_std_uint32_t                     address = function->command.param.burst_write.address;
  emc_std_uint32_t*                    target_address = EMC_USB_CELENO_CLI_TargetMemory_ptr(address);
  emc_std_uint32_t                     data_length = function->command.param.burst_write.length;
  emc_std_uint32_t                     transfer_length;
  EMC_USB_DEVICE_HAL_EP_BufferStatus_t buffer_status;

  function->bulk_data_zero_copy = zero_copy;
  function->data_address = address;
  function->data_length = data_length;

  EMC_LOG3(function->logger, INFO, "address=0x%08x length=0x%04x zerocopy=%d", function->data_address,
           function->data_length, zero_copy);

  if (function->bulk_data_zero_copy) {
    if (address % sizeof(emc_std_uint32_t) || data_length % sizeof(emc_std_uint32_t)) {
      set_state(function, EMC_USB_CELENO_CLI_State_RX_DUMMY_DATA);
      function->response.status = EMC_USB_CELENO_CLI_Status_INVALID_ADDRESS;
      EMC_LOG2(function->logger, WARN, "alignment issue address=0x%08x length=%d", address, data_length);
      prepare_rx_data(function);
    } else {
      set_state(function, EMC_USB_CELENO_CLI_State_RX_DATA);
      transfer_length = ((data_length / function->rx_ep_max_packet_size) + 1) * function->rx_ep_max_packet_size;
      buffer_status = EMC_USB_DEVICE_HAL_ep_prepare_read(function->rx_ep_handle, transfer_length, target_address);
      if (EMC_USB_DEVICE_HAL_EP_BUFFER_STATUS_FILLED != buffer_status) {
        EMC_LOG1(function->logger, WARN, "ep_prepare_read failed with buffer_status=0x%x", buffer_status);
      }
    }
  } else {
    set_state(function, EMC_USB_CELENO_CLI_State_RX_DATA);

    if (address % sizeof(emc_std_uint32_t) || data_length % sizeof(emc_std_uint32_t)) {
      function->response.status = EMC_USB_CELENO_CLI_Status_INVALID_ADDRESS;
      EMC_LOG2(function->logger, WARN, "alignment issue address=0x%08x length=%d", address, data_length);
    }
  }
}

static void process_function_ioctl(EMC_USB_CELENO_CLI_Function* function, emc_std_uint32_t index)
{
  emc_std_bool result;
  emc_std_assert(index < EMC_USB_CELENO_CLI_FUNCTION_IOCTL_MAX);
  EMC_LOG4(function->logger,
           INFO,
           "fct[%d] cmd=0x%08x p1=0x%08x  p1=0x%08x",
           index,
           function->command.param.function_ioctl_param.command,
           function->command.param.function_ioctl_param.param1,
           function->command.param.function_ioctl_param.param2);
  if (function->ioctl_functions[index].function) {
    result = (function->ioctl_functions[index].function)(
      function->ioctl_functions[index].context,
      function->command.param.function_ioctl_param.command,
      function->command.param.function_ioctl_param.param1,
      function->command.param.function_ioctl_param.param2,
      &function->response.param.function_data.data1,
      &function->response.param.function_data.data2
      );
    if (!result) {
      function->response.status = EMC_USB_CELENO_CLI_Status_FUNCTION_ERROR;
    }
    EMC_LOG3(function->logger, INFO, "result=%d d1=0x%08x  d2=0x%08x", result,
             function->response.param.function_data.data1, function->response.param.function_data.data2);
  } else {
    EMC_LOG1(function->logger, WARN, "no io-control registered for fct[idx=%d]", index);
    function->response.status = EMC_USB_CELENO_CLI_Status_INVALID_FUNCTION_ERROR;
  }
}

static void process_invalid(EMC_USB_CELENO_CLI_Function* function)
{
  EMC_LOG5(function->logger, WARN, "cmd=0x%04x, seq=0x%04x, p[0]=0x%08x, p[1]=0x%08x, p[2]=0x%08x",
           function->command.id, function->command.sequence_id, function->command.param.reserved[0],
           function->command.param.reserved[1], function->command.param.reserved[2]);
  function->response.status = EMC_USB_CELENO_CLI_Status_INVALID_COMMAND_CODE;
}

static void process_command(EMC_USB_CELENO_CLI_Function* function)
{
  EMC_LOG5(function->logger, DEBUG, "cmd=0x%04x, seq=0x%04x, p[0]=0x%08x, p[1]=0x%08x, p[2]=0x%08x",
           function->command.id, function->command.sequence_id, function->command.param.reserved[0],
           function->command.param.reserved[1], function->command.param.reserved[2]);

  if (function->command_hook_function.function) {
    function->command_hook_function.function(function->command_hook_function.context,
                                             function->command.param.function_ioctl_param.command);
  }

  switch (function->command.id) {
  case EMC_USB_CELENO_CLI_CommandId_GET_VERSION:
    process_get_version(function);
    break;
  case EMC_USB_CELENO_CLI_CommandId_KEEP_ALIVE:
    process_keep_alive(function);
    break;
  case EMC_USB_CELENO_CLI_CommandId_SINGLE_READ:
    process_read(function);
    break;
  case EMC_USB_CELENO_CLI_CommandId_SINGLE_WRITE:
  case EMC_USB_CELENO_CLI_CommandId_SINGLE_WRITE_FAST:
    process_write(function);
    break;
  case EMC_USB_CELENO_CLI_CommandId_DISCONNECT_USB:
    process_disconnect(function);
    break;
  case EMC_USB_CELENO_CLI_CommandId_UMAC_EXECUTE:
    process_execute(function);
    break;
  case EMC_USB_CELENO_CLI_CommandId_UMAC_RESTART:
    process_umac_restart(function);
    break;
  case EMC_USB_CELENO_CLI_CommandId_LOGGER_LEVEL_GET:
    process_logger_get_level(function);
    break;
  case EMC_USB_CELENO_CLI_CommandId_LOGGER_LEVEL_SET:
    process_logger_set_level(function);
    break;
  case EMC_USB_CELENO_CLI_CommandId_LOGGER_INFO_GET:
    // no additional checks for response, will be processed finally on tx_response event
    break;
  case EMC_USB_CELENO_CLI_CommandId_BULK_READ:
    process_burst_read(function, emc_std_false);
    break;
  case EMC_USB_CELENO_CLI_CommandId_BULK_READ_ZCOPY:
    process_burst_read(function, emc_std_true);
    break;
  case EMC_USB_CELENO_CLI_CommandId_BULK_WRITE:
  case EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_FAST:
    process_burst_write(function, emc_std_false);
    break;
  case EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_ZCOPY:
  case EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_FAST_ZCOPY:
    process_burst_write(function, emc_std_true);
    break;
  case EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_0:
    process_function_ioctl(function, 0);
    break;
  case EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_1:
    process_function_ioctl(function, 1);
    break;
  case EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_2:
    process_function_ioctl(function, 2);
    break;
  case EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_3:
    process_function_ioctl(function, 3);
    break;
  default:
    process_invalid(function);
  }
}

static emc_std_bool prepare_rx_command(EMC_USB_CELENO_CLI_Function* self)
{
  emc_std_bool                         result = emc_std_true;
  EMC_USB_DEVICE_HAL_EP_BufferStatus_t buffer_status;

  EMC_FUNCTION(self->logger, DEBUG);

  set_state(self, EMC_USB_CELENO_CLI_State_RX_COMMAND);
  self->tx_data_in_tx_buffer = emc_std_false;
  buffer_status = EMC_USB_DEVICE_HAL_ep_prepare_read(self->rx_ep_handle, self->rx_buffer_size, self->rx_buffer);

  if (EMC_USB_DEVICE_HAL_EP_BUFFER_STATUS_FILLED != buffer_status) {
    EMC_LOG1(self->logger, WARN, "ep_prepare_read failed with buffer_status=0x%x", buffer_status);
    result = emc_std_false;
  }
  return result;
}

static emc_std_bool prepare_rx_data(EMC_USB_CELENO_CLI_Function* self)
{
  emc_std_bool                         result = emc_std_true;
  EMC_USB_DEVICE_HAL_EP_BufferStatus_t buffer_status;

  EMC_FUNCTION(self->logger, DEBUG);

  buffer_status = EMC_USB_DEVICE_HAL_ep_prepare_read(self->rx_ep_handle, self->rx_buffer_size, self->rx_buffer);

  if (EMC_USB_DEVICE_HAL_EP_BUFFER_STATUS_FILLED != buffer_status) {
    EMC_LOG1(self->logger, WARN, "ep_prepare_read failed with buffer_status=0x%x", buffer_status);
    result = emc_std_false;
  }
  return result;
}

static void store_response(EMC_USB_CELENO_CLI_Function* self)
{
  void* tx_ptr = self->tx_buffer_wptr;

  set_state(self, EMC_USB_CELENO_CLI_State_TX_RESPONSE);

  EMC_LOG5(self->logger, DEBUG, "cmd=0x%04x, seq=0x%04x, status=0x%04x, p[0]=0x%08x, p[1]=0x%08x",
           self->response.id, self->response.sequence_id, self->response.status, self->response.param.reserved[0],
           self->response.param.reserved[1]);

  EMC_USB_CELENO_CLI_Response_put(&self->response, &tx_ptr);
  self->tx_buffer_wptr = (emc_std_uint32_t*)tx_ptr;
}

static void transmit_responses(EMC_USB_CELENO_CLI_Function* self)
{
  unsigned int                         tx_length;
  EMC_USB_DEVICE_HAL_EP_BufferStatus_t buffer_status;

  EMC_FUNCTION(self->logger, DEBUG);

  tx_length = (unsigned int)(self->tx_buffer_wptr - self->tx_buffer) * 4;
  buffer_status = EMC_USB_DEVICE_HAL_ep_write(self->tx_ep_handle, tx_length, self->tx_buffer);
  self->tx_buffer_wptr = self->tx_buffer;

  if (EMC_USB_DEVICE_HAL_EP_BUFFER_STATUS_FILLED != buffer_status) {
    EMC_LOG1(self->logger, WARN, "ep_write failed with buffer_status=0x%x", buffer_status);
  }
}

static void transmit_data(EMC_USB_CELENO_CLI_Function* self)
{
  EMC_USB_DEVICE_HAL_EP_BufferStatus_t buffer_status;
  emc_std_uint32_t*                    src_address;
  emc_std_uint32_t                     transfer_length;

  EMC_LOG2(self->logger, DEBUG, "address=0x%08x length=0x%04x", self->data_address, self->data_length);

  set_state(self, EMC_USB_CELENO_CLI_State_TX_DATA);
  if (!self->tx_data_in_tx_buffer) {
    if (self->bulk_data_zero_copy) {
      transfer_length = self->data_length;
      src_address = EMC_USB_CELENO_CLI_TargetMemory_ptr(self->data_address);
    } else {
      transfer_length = self->tx_buffer_size < self->data_length ? self->tx_buffer_size : self->data_length;
      EMC_USB_CELENO_CLI_TargetMemory_burst_read(self->data_address, self->tx_buffer, transfer_length);
      src_address = (emc_std_uint32_t*)self->tx_buffer;
      self->data_address += transfer_length;
      self->data_length -= transfer_length;
    }
  } else {
    transfer_length = self->data_length;
    src_address = (emc_std_uint32_t*)self->tx_buffer;
    self->data_length -= transfer_length;
  }

  EMC_LOG_PAYLOAD(self->logger, TRACE, src_address, self->data_length);

  buffer_status = EMC_USB_DEVICE_HAL_ep_write(self->tx_ep_handle, transfer_length, src_address);
  if ((self->data_length % self->tx_ep_max_packet_size) == 0) {
    EMC_LOG1(self->logger, DEBUG, "additional zero packet required in completion for length=%d",
             self->data_length);
  }
  if (EMC_USB_DEVICE_HAL_EP_BUFFER_STATUS_FILLED != buffer_status) {
    EMC_LOG1(self->logger, WARN, "ep_write failed with buffer_status=0x%x", buffer_status);
  }
}

static void transmit_zlp(EMC_USB_CELENO_CLI_Function* self)
{
  EMC_USB_DEVICE_HAL_EP_BufferStatus_t buffer_status;

  EMC_FUNCTION(self->logger, DEBUG);

  set_state(self, EMC_USB_CELENO_CLI_State_TX_DATA);

  buffer_status = EMC_USB_DEVICE_HAL_ep_write(self->tx_ep_handle, 0, EMC_STD_NULL);

  if (EMC_USB_DEVICE_HAL_EP_BUFFER_STATUS_FILLED != buffer_status) {
    EMC_LOG1(self->logger, WARN, "ep_write(ZLP) failed with buffer_status=0x%x", buffer_status);
  }
}

static void process_rx_command(EMC_USB_CELENO_CLI_Function* self,
                               unsigned int rx_length,
                               EMC_USB_DEVICE_HAL_EP_XFER_Status_t status)
{
  emc_std_bool response_required;
  unsigned int remaining_length = rx_length;

  void* rx_ptr = self->rx_buffer;

  EMC_LOG2(self->logger, DEBUG, "rx_length=%d status=0x%x", rx_length, status);

  if (status != EMC_USB_DEVICE_HAL_EP_XFER_STATUS_SUCCESS) {
    EMC_LOG(self->logger, WARN, "should not occur");
    return;
  }
  if (rx_length == 0) {
    EMC_LOG(self->logger, WARN, "received zero length command, ignored");
    return;
  }
  while (remaining_length >= EMC_USB_CELENO_CLI_Command_SIZE) {
    remaining_length -= EMC_USB_CELENO_CLI_Command_SIZE;
    EMC_USB_CELENO_CLI_Command_get(&self->command, &rx_ptr); /* moves rx_ptr forward! */
    // validate ?
    response_required = EMC_USB_CELENO_CLI_Response_init(&self->response, &self->command);
    process_command(self);

    if ((self->state == EMC_USB_CELENO_CLI_State_RX_DATA) || (self->state == EMC_USB_CELENO_CLI_State_RX_DUMMY_DATA)) { // WRITE_BULK
      if (self->bulk_data_zero_copy) {
        return;
      } else {
        break;
      }
    }
    if (response_required) {
      store_response(self);
    }
  }
  if (remaining_length != 0) {
    EMC_LOG1(self->logger, WARN, "received command with length %d, ignored", remaining_length);
  }
  if (self->state == EMC_USB_CELENO_CLI_State_RX_DATA) {
    prepare_rx_data(self);
    return;
  }
  if (self->state == EMC_USB_CELENO_CLI_State_TX_RESPONSE) {
    transmit_responses(self);
  } else {
    if (emc_std_true != prepare_rx_command(self)) {
      EMC_LOG(self->logger, WARN, "could not prepare rx command");
    }
  }
}

static void process_rx_data(EMC_USB_CELENO_CLI_Function* self,
                            unsigned int rx_length,
                            EMC_USB_DEVICE_HAL_EP_XFER_Status_t status)
{
  EMC_LOG2(self->logger, DEBUG, "rx_length=%d status=0x%x", rx_length, status);

  if (status != EMC_USB_DEVICE_HAL_EP_XFER_STATUS_SUCCESS) {
    /* should not occur */
    return;
  }

  if (self->bulk_data_zero_copy) {
    if ((rx_length == self->rx_buffer_size) && (self->state == EMC_USB_CELENO_CLI_State_RX_DUMMY_DATA)) {
      // read until short packet
      prepare_rx_data(self);
      return;
    }
  } else {
    if (rx_length <= self->data_length) {
      if ((0 == (self->data_address % sizeof(emc_std_uint32_t))) &&
          (0 == (self->data_length % sizeof(emc_std_uint32_t))))
      {
        EMC_USB_CELENO_CLI_TargetMemory_burst_write(self->data_address, self->rx_buffer, rx_length);
        self->data_address += rx_length;
        self->data_length -= rx_length;
      }
    }
    if (rx_length == EMC_USB_VENDOR_CELENO_CLI_MAX_COMMAND_TRANSFER_LENGTH) {
      prepare_rx_data(self);
      return;
    }
  }

  if ((self->command.id == EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_FAST) ||
      (self->command.id == EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_FAST_ZCOPY))
  {
    prepare_rx_command(self);
  } else {
    store_response(self);
    transmit_responses(self);
  }
}

static void process_rx_ep_done(EMC_USB_CELENO_CLI_Function* self,
                               unsigned int rx_length,
                               EMC_USB_DEVICE_HAL_EP_XFER_Status_t status)
{
  EMC_LOG2(self->logger, DEBUG, "rx_length=%d status=0x%x", rx_length, status);

  if (status == EMC_USB_DEVICE_HAL_EP_XFER_STATUS_SUCCESS) {
    if (self->state == EMC_USB_CELENO_CLI_State_RX_COMMAND) {
      process_rx_command(self, rx_length, status);
    } else if ((self->state == EMC_USB_CELENO_CLI_State_RX_DATA) ||
               (self->state == EMC_USB_CELENO_CLI_State_RX_DUMMY_DATA))
    {
      process_rx_data(self, rx_length, status);
    } else {
      EMC_LOG1(self->logger, WARN, "unexpected state=%s", EMC_USB_CELENO_CLI_State_as_string(self->state));
    }
  } else {
    EMC_LOG(self->logger, WARN, "transfer canceled, no restart");
    // we do no restart here as the cause of the error is most likely RX EP cancel
  }
}

static void done_tx_response(EMC_USB_CELENO_CLI_Function* self,
                             unsigned int tx_length,
                             EMC_USB_DEVICE_HAL_EP_XFER_Status_t status)
{
  EMC_LOG2(self->logger, DEBUG, "tx_length=%d status=0x%x", tx_length, status);

  if (status != EMC_USB_DEVICE_HAL_EP_XFER_STATUS_SUCCESS) {
    return;
  }

  if (self->response.id == EMC_USB_CELENO_CLI_CommandId_LOGGER_INFO_GET) {
    process_logger_get_info(self);
  }

  if ((self->response.id == EMC_USB_CELENO_CLI_CommandId_BULK_READ) ||
      (self->response.id == EMC_USB_CELENO_CLI_CommandId_BULK_READ_ZCOPY) ||
      (self->response.id == EMC_USB_CELENO_CLI_CommandId_LOGGER_INFO_GET))
  {
    if (self->response.status == EMC_USB_CELENO_CLI_Status_SUCCESS) {
      transmit_data(self);
    } else {
      EMC_LOG1(self->logger, DEBUG, "response status=0x%x, no data transfer", status);
      prepare_rx_command(self);
    }
  } else {
    if (emc_std_true != prepare_rx_command(self)) {
      EMC_LOG(self->logger, WARN, "could not prepare rx comand");
    }
  }
  UNUSED_PARAM(tx_length);
}

static void done_tx_data(EMC_USB_CELENO_CLI_Function* self,
                         unsigned int tx_length,
                         EMC_USB_DEVICE_HAL_EP_XFER_Status_t status)
{
  EMC_LOG2(self->logger, DEBUG, "tx_length=%d status=0x%x", tx_length, status);

  if (tx_length == 0) {
    EMC_LOG(self->logger, DEBUG, "zero data packet transmitted");
    prepare_rx_command(self);
  } else {
    if (self->bulk_data_zero_copy) {
      if (tx_length == self->data_length) {
        if ((self->data_length % self->tx_ep_max_packet_size) == 0) {
          EMC_LOG1(self->logger, DEBUG, "generate zero packet for length=%d", self->data_length);
          transmit_zlp(self);
        } else {
          prepare_rx_command(self);
        }
      } else {
        EMC_LOG2(self->logger, WARN, "unexpected length=%d, exected", tx_length, self->data_length);
        prepare_rx_command(self);
      }
    } else {
      if (self->data_length > 0) {
        transmit_data(self);
      } else {
        if ((tx_length > 0) && ((tx_length % self->tx_ep_max_packet_size) == 0)) {
          EMC_LOG1(self->logger, DEBUG, "generate zero packet for length=%d", self->data_length);
          transmit_zlp(self);
        } else {
          prepare_rx_command(self);
        }
      }
    }
  }

  UNUSED_PARAM(status);
}

static void process_tx_ep_done(EMC_USB_CELENO_CLI_Function* self,
                               unsigned int tx_length,
                               EMC_USB_DEVICE_HAL_EP_XFER_Status_t status)
{
  if (status == EMC_USB_DEVICE_HAL_EP_XFER_STATUS_SUCCESS) {
    if (self->state == EMC_USB_CELENO_CLI_State_TX_RESPONSE) {
      done_tx_response(self, tx_length, status);
    } else if (self->state == EMC_USB_CELENO_CLI_State_TX_DATA) {
      done_tx_data(self, tx_length, status);
    } else {
      EMC_LOG1(self->logger, WARN, "unexpected state=%s", EMC_USB_CELENO_CLI_State_as_string(self->state));
    }
  } else {
    EMC_LOG(self->logger, WARN, "transfer canceled, no restart");
    // we do no restart here as the cause of the error is most likely RX EP cancel
  }
}

static void rx_ep_handler(EMC_USB_DEVICE_HAL_EPHandle_t ep_handle,
                          void* context,
                          EMC_USB_DEVICE_HAL_EP_XFER_Status_t status,
                          unsigned int xfer_bytes)
{
  EMC_USB_CELENO_CLI_Function* function = mg_function;
  UNUSED_PARAM(context);
  if (function) {

    if (function->rx_ep_handle != ep_handle) {
      EMC_LOG1(function->logger, WARN, "unexpected rx completion callback for ep=0x%02x", ep_handle);
    } else {
      process_rx_ep_done(function, xfer_bytes, status);
    }
  }
}

static void tx_ep_handler(EMC_USB_DEVICE_HAL_EPHandle_t ep_handle,
                          void* context,
                          EMC_USB_DEVICE_HAL_EP_XFER_Status_t status,
                          unsigned int xfer_bytes)
{
  EMC_USB_CELENO_CLI_Function* function = mg_function;
  UNUSED_PARAM(context);
  if (function) {

    if (function->tx_ep_handle != ep_handle) {
      EMC_LOG1(function->logger, WARN, "unexpected tx completion callback for ep=0x%02x", ep_handle);
    } else {
      process_tx_ep_done(function, xfer_bytes, status);
    }
  }
}

static void set_configuration(EMC_USB_CELENO_CLI_Function* self, unsigned int configured)
{
  EMC_LOG1(self->logger, INFO, "configured=%u", configured);

  self->interface->as = 0;
  if (configured) {
    if (!self->configured) {
      unsigned short bulk_mps = 0;
      EMC_USB_Speed  enumerated_speed = EMC_USB_DEVICE_HAL_enumerated_speed();

      EMC_USB_DEVICE_HAL_lpm_wakeup();
      self->configured = 1;
      self->sequence_id = 0;

      switch (enumerated_speed) {
      case EMC_USB_Speed_SUPER_PLUS:
      case EMC_USB_Speed_SUPER:
        bulk_mps = USB_EP_MPS_BULK_SUPER_SPEED;
        break;
      case EMC_USB_Speed_HIGH:
        bulk_mps = USB_EP_MPS_BULK_HIGH_SPEED;
        break;
      case EMC_USB_Speed_FULL:
      case EMC_USB_Speed_LOW:
      case EMC_USB_Speed_UNDEFINED:
      default:
        bulk_mps = USB_EP_MPS_BULK_FULL_SPEED;
        break;
      }

      self->rx_ep_addr = CELENO_CLI_BULK_OUT;
      self->tx_ep_addr = CELENO_CLI_BULK_IN;
      self->rx_ep_max_packet_size = bulk_mps;
      self->tx_ep_max_packet_size = bulk_mps;

      EMC_USB_CELENO_CLI_Function_start(self);
    }
  } else {
    if (self->configured) {
      EMC_USB_CELENO_CLI_Function_stop(self);

      self->configured = 0;

      EMC_USB_DEVICE_HAL_lpm_enable();
    }
  }
}

static EMC_USB_Error notify_device_event(void* context, EMC_USB_DeviceEventId event)
{
  EMC_USB_CELENO_CLI_Function* self = (EMC_USB_CELENO_CLI_Function*)context;
  EMC_USB_Device*              device = EMC_USB_Device_GetDevice();

  if (self) {
    EMC_LOG2(self->logger, DEBUG, "device=%p, ev=%d", device, event);
    if (device) {
      if (EMC_USB_DEVICE_EVENT_STATUS_CONFIGURED == event) {
        set_configuration(self, 1);
      } else if ((EMC_USB_DEVICE_EVENT_STATUS_DEFAULT == event) ||
                 (EMC_USB_DEVICE_EVENT_STATUS_ADDRESSED == event))
      {
        set_configuration(self, 0);
      }
    }
  }
  return EMC_USB_NO_ERROR;
}

static EMC_USB_Error set_alternate_setting(void* context, emc_std_uint8_t alt_setting)
{
  EMC_USB_CELENO_CLI_Function* self = (EMC_USB_CELENO_CLI_Function*)context;

  EMC_LOG1(self->logger, INFO, "as=%d", alt_setting);

  if (self) {
    if (self->interface->as == alt_setting) {
      EMC_LOG1(self->logger, INFO, "as=%d already active", alt_setting);
    } else {
      if (alt_setting == 0) {
        // start function
        EMC_USB_CELENO_CLI_Function_start(self);
      } else {
        // stop function
        EMC_USB_CELENO_CLI_Function_stop(self);
      }
    }
  }
  return EMC_USB_NO_ERROR;
}

static const EMC_USB_Function ftbl = {
  &notify_device_event,
  &set_alternate_setting,
  EMC_STD_NULL,
  EMC_STD_NULL
};

#define MIN_BUFFER_LENGTH (2 * EMC_USB_VENDOR_CELENO_CLI_MAX_COMMAND_TRANSFER_LENGTH)

void EMC_USB_CELENO_CLI_FunctionConfig_init(EMC_USB_CELENO_CLI_FunctionConfig* self)
{
  emc_std_memset(self, 0, sizeof(EMC_USB_CELENO_CLI_FunctionConfig));
}

void EMC_USB_CELENO_CLI_Function_init(EMC_USB_CELENO_CLI_Function* self,
                                      const EMC_USB_CELENO_CLI_FunctionConfig* config)
{
  EMC_USB_Device* device;

  emc_std_uint8_t* ptr;

  EMC_LOG1(self->logger, INFO, "IF 0x%02X", config->interface_number);
  EMC_CT_ASSERT(0 == (EMC_USB_CELENO_CLI_Command_SIZE % sizeof(emc_std_uint32_t)));
  EMC_CT_ASSERT(sizeof(EMC_USB_CELENO_CLI_Command) == EMC_USB_CELENO_CLI_Command_SIZE);
  EMC_CT_ASSERT(sizeof(EMC_USB_CELENO_CLI_Response) == EMC_USB_CELENO_CLI_Command_SIZE);

  emc_std_assert(self);
  emc_std_assert(config);
  emc_std_assert(config->buffer_size >= MIN_BUFFER_LENGTH);

  emc_std_memset(self, 0, sizeof(EMC_USB_CELENO_CLI_Function));

  self->logger = EMC_Log_logger("emc.usb.dev.cli");
  self->logger_rx = EMC_Log_logger("emc.usb.dev.cli.rx_" EMC_STRINGIZE(CELENO_CLI_BULK_OUT));
  self->logger_tx = EMC_Log_logger("emc.usb.dev.cli.tx_" EMC_STRINGIZE(CELENO_CLI_BULK_IN));

  self->bulk_data_zero_copy = emc_std_true;
  self->tx_data_in_tx_buffer = emc_std_false;
  self->config = *config;

  ptr = config->buffer;

  self->rx_buffer = (void*)ptr;
  self->rx_buffer_size = EMC_USB_VENDOR_CELENO_CLI_MAX_COMMAND_TRANSFER_LENGTH;
  ptr += EMC_USB_VENDOR_CELENO_CLI_MAX_COMMAND_TRANSFER_LENGTH;

  self->tx_buffer = (void*)ptr;
  self->tx_buffer_wptr = self->tx_buffer;
  self->tx_buffer_size = EMC_USB_VENDOR_CELENO_CLI_MAX_COMMAND_TRANSFER_LENGTH;
  ptr += EMC_USB_VENDOR_CELENO_CLI_MAX_COMMAND_TRANSFER_LENGTH;

  self->sequence_id = 0;
  EMC_USB_CELENO_CLI_Version_init(&self->version, config->app_version);

  device = EMC_USB_Device_GetDevice();

  self->interface = EMC_USB_Interface_create_from_number(device, config->interface_number);
  if (self->interface) {
    self->interface->function_ftbl = &ftbl;
    self->interface->function_context = self;
  }

  mg_function = self;
}

emc_std_bool EMC_USB_CELENO_CLI_Function_start(EMC_USB_CELENO_CLI_Function* self)
{
  EMC_USB_EndpointAttributes rx_ep_attrib;
  EMC_USB_EndpointAttributes tx_ep_attrib;

  EMC_FUNCTION(self->logger, INFO);

  emc_std_assert(self);

  EMC_USB_EndpointAttributes_init_bulk(&rx_ep_attrib,
                                       self->rx_ep_addr, self->rx_ep_max_packet_size);
  EMC_USB_EndpointAttributes_init_bulk(&tx_ep_attrib,
                                       self->tx_ep_addr, self->tx_ep_max_packet_size);

  rx_ep_attrib.logger = self->logger_rx ? self->logger_rx : self->logger;
  tx_ep_attrib.logger = self->logger_tx ? self->logger_tx : self->logger;

  self->rx_ep_handle = EMC_USB_DEVICE_HAL_ep_enable(&rx_ep_handler, self, &rx_ep_attrib);
  self->tx_ep_handle = EMC_USB_DEVICE_HAL_ep_enable(&tx_ep_handler, self, &tx_ep_attrib);

  EMC_LOG4(self->logger, TRACE, "rx_ep(addr=0x%02x, mps=%d), tx_ep(addr=0x%02x, mps=%d)",
           self->rx_ep_addr,
           self->rx_ep_max_packet_size,
           self->tx_ep_addr,
           self->tx_ep_max_packet_size
           );

  return prepare_rx_command(self);
}

void EMC_USB_CELENO_CLI_Function_stop(EMC_USB_CELENO_CLI_Function* self)
{
  EMC_USB_DEVICE_HAL_Error_t error;

  emc_std_assert(self);
  EMC_FUNCTION(self->logger, INFO);

  error = EMC_USB_DEVICE_HAL_ep_disable(self->rx_ep_handle);
  if (error) {
    EMC_LOG2(self->logger, WARN, "error=0x%x during ep_disable(0x%x)", error, self->rx_ep_handle);
  }
  error = EMC_USB_DEVICE_HAL_ep_disable(self->tx_ep_handle);
  if (error) {
    EMC_LOG2(self->logger, WARN, "error=0x%x during ep_disable(0x%x)", error, self->tx_ep_handle);
  }
  self->rx_ep_handle = EMC_USB_DEVICE_HAL_EP_HANDLE_INVALID;
  self->tx_ep_handle = EMC_USB_DEVICE_HAL_EP_HANDLE_INVALID;
}

void EMC_USB_CELENO_CLI_Function_register_function_ioctl(EMC_USB_CELENO_CLI_Function* self,
                                                         emc_std_uint32_t index,
                                                         EMC_USB_CELENO_CLI_FunctionIoctl* function,
                                                         void* context)
{
  emc_std_assert(self);
  emc_std_assert(index < EMC_USB_CELENO_CLI_FUNCTION_IOCTL_MAX);

  self->ioctl_functions[index].function = function;
  self->ioctl_functions[index].context = context;
}

void EMC_USB_CELENO_CLI_Function_register_command_hook(EMC_USB_CELENO_CLI_Function* self,
                                                       EMC_USB_CELENO_CLI_CommandCallback* function,
                                                       void* context)
{
  emc_std_assert(self);
  self->command_hook_function.function = function;
  self->command_hook_function.context = context;
}

#if EMC_PRINT
void EMC_USB_CELENO_CLI_Function_print(const EMC_USB_CELENO_CLI_Function* self, FILE* file)
{
  emc_std_assert(self);
  FORM_START_HEAD(file, EMC_USB_CELENO_CLI_Function);
  FORM_ATTR_HEX(file, sequence_id, self->sequence_id);
  FORM_ATTR_STR(file, state, EMC_USB_CELENO_CLI_State_as_string(self->state));
  FORM_END_HEAD(file);

  FORM_DATA_HEX(file, tx_ep_addr, self->tx_ep_addr);
  FORM_DATA_HEX(file, rx_ep_addr, self->rx_ep_addr);
  FORM_DATA_HEX(file, tx_ep_handle, self->tx_ep_handle);
  FORM_DATA_HEX(file, rx_ep_handle, self->rx_ep_handle);

  FORM_DATA_HEX(file, tx_ep_max_packet_size, self->tx_ep_max_packet_size);
  FORM_DATA_HEX(file, rx_ep_max_packet_size, self->rx_ep_max_packet_size);

  FORM_END(file, EMC_USB_CELENO_CLI_Function);
}

#endif /*EMC_PRINT*/
