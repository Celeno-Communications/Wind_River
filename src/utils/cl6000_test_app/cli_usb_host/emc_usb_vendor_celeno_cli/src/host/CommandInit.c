/** Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/usb/vendor/celeno/cli/host/CommandInit.h"
#include "emc/std/assert.h"
#include "emc/std/string.h"

void EMC_USB_CELENO_CLI_Command_init_get_version(EMC_USB_CELENO_CLI_Command* self)
{
  emc_std_assert(self);
  emc_std_memset(self, 0, EMC_USB_CELENO_CLI_Command_SIZE);
  self->id = EMC_USB_CELENO_CLI_CommandId_GET_VERSION;
}

void EMC_USB_CELENO_CLI_Command_init_read(EMC_USB_CELENO_CLI_Command* self,
                                          emc_std_uint32_t address)
{
  emc_std_assert(self);
  emc_std_memset(self, 0, EMC_USB_CELENO_CLI_Command_SIZE);
  self->id = EMC_USB_CELENO_CLI_CommandId_SINGLE_READ;
  self->param.read.address = address;
}

void EMC_USB_CELENO_CLI_Command_init_write(EMC_USB_CELENO_CLI_Command* self,
                                           emc_std_uint32_t address,
                                           emc_std_uint32_t data,
                                           emc_std_uint32_t mask)
{
  emc_std_assert(self);
  emc_std_memset(self, 0, EMC_USB_CELENO_CLI_Command_SIZE);
  self->id = EMC_USB_CELENO_CLI_CommandId_SINGLE_WRITE;
  self->param.write.address = address;
  self->param.write.data = data;
  self->param.write.mask = mask;
}

void EMC_USB_CELENO_CLI_Command_init_write_fast(EMC_USB_CELENO_CLI_Command* self,
                                                emc_std_uint32_t address,
                                                emc_std_uint32_t data,
                                                emc_std_uint32_t mask)
{
  emc_std_assert(self);
  emc_std_memset(self, 0, EMC_USB_CELENO_CLI_Command_SIZE);
  self->id = EMC_USB_CELENO_CLI_CommandId_SINGLE_WRITE_FAST;
  self->param.write.address = address;
  self->param.write.data = data;
  self->param.write.mask = mask;
}

void EMC_USB_CELENO_CLI_Command_init_keep_alive(EMC_USB_CELENO_CLI_Command* self)
{
  emc_std_assert(self);
  emc_std_memset(self, 0, EMC_USB_CELENO_CLI_Command_SIZE);
  self->id = EMC_USB_CELENO_CLI_CommandId_KEEP_ALIVE;
}

void EMC_USB_CELENO_CLI_Command_init_usb_disconnect(EMC_USB_CELENO_CLI_Command* self,
                                                    emc_std_uint32_t usb_disconnect_delay_ms)
{
  emc_std_assert(self);
  emc_std_memset(self, 0, EMC_USB_CELENO_CLI_Command_SIZE);
  self->id = EMC_USB_CELENO_CLI_CommandId_DISCONNECT_USB;
  self->param.disconnect.usb_disconnect_delay_ms = usb_disconnect_delay_ms;
}

void EMC_USB_CELENO_CLI_Command_init_umac_execute(EMC_USB_CELENO_CLI_Command* self,
                                                  emc_std_uint32_t jump_address)
{
  emc_std_assert(self);
  emc_std_memset(self, 0, EMC_USB_CELENO_CLI_Command_SIZE);
  self->id = EMC_USB_CELENO_CLI_CommandId_UMAC_EXECUTE;
  self->param.execute.address = jump_address;
}

void EMC_USB_CELENO_CLI_Command_init_umac_restart(EMC_USB_CELENO_CLI_Command* self,
                                                  emc_std_uint32_t usb_disconnect_delay_ms,
                                                  emc_std_uint32_t restart_delay_ms,
                                                  emc_std_uint32_t jump_address)
{
  emc_std_assert(self);
  emc_std_memset(self, 0, EMC_USB_CELENO_CLI_Command_SIZE);
  self->id = EMC_USB_CELENO_CLI_CommandId_UMAC_RESTART;
  self->param.restart.usb_disconnect_delay_ms = usb_disconnect_delay_ms;
  self->param.restart.restart_delay_ms = restart_delay_ms;
  self->param.restart.jump_address = jump_address;
}

void EMC_USB_CELENO_CLI_Command_init_logger_level_get(EMC_USB_CELENO_CLI_Command* self,
                                                      emc_std_uint32_t index)
{
  emc_std_assert(self);
  emc_std_memset(self, 0, EMC_USB_CELENO_CLI_Command_SIZE);
  self->id = EMC_USB_CELENO_CLI_CommandId_LOGGER_LEVEL_GET;
  self->param.logger_get.index = index;
}

void EMC_USB_CELENO_CLI_Command_init_logger_level_set(EMC_USB_CELENO_CLI_Command* self,
                                                      emc_std_uint32_t index,
                                                      emc_std_uint32_t level)
{
  emc_std_assert(self);
  emc_std_memset(self, 0, EMC_USB_CELENO_CLI_Command_SIZE);
  self->id = EMC_USB_CELENO_CLI_CommandId_LOGGER_LEVEL_SET;
  self->param.logger_level_set.index = index;
  self->param.logger_level_set.level = level;
}

void EMC_USB_CELENO_CLI_Command_init_logger_info_get(EMC_USB_CELENO_CLI_Command* self,
                                                     emc_std_uint32_t index)
{
  emc_std_assert(self);
  emc_std_memset(self, 0, EMC_USB_CELENO_CLI_Command_SIZE);
  self->id = EMC_USB_CELENO_CLI_CommandId_LOGGER_INFO_GET;
  self->param.logger_get.index = index;
}

void EMC_USB_CELENO_CLI_Command_init_burst_read(EMC_USB_CELENO_CLI_Command* self,
                                                emc_std_uint32_t address,
                                                emc_std_uint32_t length,
                                                emc_std_bool zero_copy)
{
  emc_std_assert(self);
  emc_std_memset(self, 0, EMC_USB_CELENO_CLI_Command_SIZE);
  self->id = zero_copy ? EMC_USB_CELENO_CLI_CommandId_BULK_READ_ZCOPY : EMC_USB_CELENO_CLI_CommandId_BULK_READ;
  self->param.burst_read.address = address;
  self->param.burst_read.length = length;
}

void EMC_USB_CELENO_CLI_Command_init_burst_write(EMC_USB_CELENO_CLI_Command* self,
                                                 emc_std_uint32_t address,
                                                 emc_std_uint32_t length,
                                                 emc_std_bool zero_copy)
{
  emc_std_assert(self);
  emc_std_memset(self, 0, EMC_USB_CELENO_CLI_Command_SIZE);
  self->id = zero_copy ? EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_ZCOPY : EMC_USB_CELENO_CLI_CommandId_BULK_WRITE;
  self->param.burst_write.address = address;
  self->param.burst_write.length = length;
}

void EMC_USB_CELENO_CLI_Command_init_burst_write_fast(EMC_USB_CELENO_CLI_Command* self,
                                                      emc_std_uint32_t address,
                                                      emc_std_uint32_t length,
                                                      emc_std_bool zero_copy)
{
  emc_std_assert(self);
  emc_std_memset(self, 0, EMC_USB_CELENO_CLI_Command_SIZE);
  self->id =
    zero_copy ? EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_FAST_ZCOPY : EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_FAST;
  self->param.burst_write.address = address;
  self->param.burst_write.length = length;
}

void EMC_USB_CELENO_CLI_Command_init_function_ioctl(EMC_USB_CELENO_CLI_Command* self,
                                                    emc_std_uint32_t index,
                                                    emc_std_uint32_t command,
                                                    emc_std_uint32_t param1,
                                                    emc_std_uint32_t param2)
{
  emc_std_assert(self);
  emc_std_assert(index < EMC_USB_CELENO_CLI_FUNCTION_IOCTL_MAX);
  emc_std_memset(self, 0, EMC_USB_CELENO_CLI_Command_SIZE);
  self->id = EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_0 + index;
  self->param.function_ioctl_param.command = command;
  self->param.function_ioctl_param.param1 = param1;
  self->param.function_ioctl_param.param2 = param2;
}
