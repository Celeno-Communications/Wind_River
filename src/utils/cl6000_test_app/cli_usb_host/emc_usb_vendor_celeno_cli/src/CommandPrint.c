/** Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/usb/vendor/celeno/cli/Command.h"

#include "emc/std/assert.h"

#if EMC_PRINT
#  include "emc/std/stdio.h"
#  include "emc/data/form/helper_macros.h"
#  include "emc/data/form/indent.h"
#endif

#if EMC_PRINT

static void print_read_param(const EMC_USB_CELENO_CLI_Command* self, FILE* file)
{
  FORM_DATA_HEX(file, address, self->param.read.address);
}

static void print_write_param(const EMC_USB_CELENO_CLI_Command* self, FILE* file)
{
  FORM_DATA_HEX(file, address, self->param.write.address);
  FORM_DATA_HEX(file, data, self->param.write.data);
  FORM_DATA_HEX(file, mask, self->param.write.mask);
}

static void print_disconnect_param(const EMC_USB_CELENO_CLI_Command* self, FILE* file)
{
  FORM_DATA_DEC(file, disconnect_time, self->param.disconnect.usb_disconnect_delay_ms);
}

static void print_umac_execute_param(const EMC_USB_CELENO_CLI_Command* self, FILE* file)
{
  FORM_DATA_HEX(file, jump_address, self->param.execute.address);
}

static void print_umac_restart_param(const EMC_USB_CELENO_CLI_Command* self, FILE* file)
{
  FORM_DATA_DEC(file, usb_disconnect_delay_ms, self->param.restart.usb_disconnect_delay_ms);
  FORM_DATA_DEC(file, restart_delay_ms, self->param.restart.restart_delay_ms);
  FORM_DATA_HEX(file, jump_address, self->param.restart.jump_address);
}

static void print_burst_write_param(const EMC_USB_CELENO_CLI_Command* self, FILE* file)
{
  FORM_DATA_HEX(file, address, self->param.burst_write.address);
  FORM_DATA_HEX(file, length, self->param.burst_write.length);
}

static void print_ioctl_func_param(const EMC_USB_CELENO_CLI_Command* self, FILE* file)
{
  FORM_DATA_HEX(file, command, self->param.function_ioctl_param.command);
  FORM_DATA_HEX(file, length, self->param.function_ioctl_param.param1);
  FORM_DATA_HEX(file, length, self->param.function_ioctl_param.param2);
}

static void print_burst_read_param(const EMC_USB_CELENO_CLI_Command* self, FILE* file)
{
  FORM_DATA_HEX(file, address, self->param.burst_read.address);
  FORM_DATA_HEX(file, length, self->param.burst_read.length);
}

static void print_logger_get_param(const EMC_USB_CELENO_CLI_Command* self, FILE* file)
{
  FORM_DATA_DEC(file, index, self->param.logger_get.index);
}

static void print_logger_level_set_param(const EMC_USB_CELENO_CLI_Command* self, FILE* file)
{
  FORM_DATA_DEC(file, index, self->param.logger_level_set.index);
  FORM_DATA_DEC(file, level, self->param.logger_level_set.level);
}

static void print_reserved_param(const EMC_USB_CELENO_CLI_Command* self, FILE* file)
{
  for (unsigned i = 0; i < 3; ++i) {
    FORM_DATA_HEX(file, param, self->param.reserved[i]);
  }
}

void EMC_USB_CELENO_CLI_Command_print(const EMC_USB_CELENO_CLI_Command* self, FILE* file)
{
  emc_std_assert(self);
  FORM_START_HEAD(file, EMC_USB_CELENO_CLI_Command);
  FORM_ATTR_HEX(file, id, self->id);
  FORM_ATTR_HEX(file, sequence_id, self->sequence_id);
  FORM_ATTR_STR(file, name, EMC_USB_CELENO_CLI_CommandId_as_string(self->id));
  FORM_END_HEAD(file);

  switch (self->id) {
  case EMC_USB_CELENO_CLI_CommandId_GET_VERSION:
  case EMC_USB_CELENO_CLI_CommandId_KEEP_ALIVE:
    break;
  case EMC_USB_CELENO_CLI_CommandId_LOGGER_LEVEL_GET:
  case EMC_USB_CELENO_CLI_CommandId_LOGGER_INFO_GET:
    print_logger_get_param(self, file);
    break;
  case EMC_USB_CELENO_CLI_CommandId_LOGGER_LEVEL_SET:
    print_logger_level_set_param(self, file);
    break;
  case EMC_USB_CELENO_CLI_CommandId_SINGLE_READ:
    print_read_param(self, file);
    break;
  case EMC_USB_CELENO_CLI_CommandId_SINGLE_WRITE:
  case EMC_USB_CELENO_CLI_CommandId_SINGLE_WRITE_FAST:
    print_write_param(self, file);
    break;
  case EMC_USB_CELENO_CLI_CommandId_DISCONNECT_USB:
    print_disconnect_param(self, file);
    break;
  case EMC_USB_CELENO_CLI_CommandId_UMAC_EXECUTE:
    print_umac_execute_param(self, file);
    break;
  case EMC_USB_CELENO_CLI_CommandId_UMAC_RESTART:
    print_umac_restart_param(self, file);
    break;
  case EMC_USB_CELENO_CLI_CommandId_BULK_READ:
  case EMC_USB_CELENO_CLI_CommandId_BULK_READ_ZCOPY:
    print_burst_read_param(self, file);
    break;
  case EMC_USB_CELENO_CLI_CommandId_BULK_WRITE:
  case EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_FAST:
  case EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_ZCOPY:
  case EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_FAST_ZCOPY:
    print_burst_write_param(self, file);
    break;
  case EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_0:
  case EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_1:
  case EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_2:
  case EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_3:
    print_ioctl_func_param(self, file);
    break;
  default:
    print_reserved_param(self, file);
  }
  FORM_END(file, EMC_USB_CELENO_CLI_Command);
}

#endif /*EMC_PRINT*/
