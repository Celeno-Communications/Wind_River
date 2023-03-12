/** Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/usb/vendor/celeno/cli/Response.h"

#include "emc/std/assert.h"

#if EMC_PRINT
#  include "emc/std/stdio.h"
#  include "emc/data/form/helper_macros.h"
#  include "emc/data/form/indent.h"
#endif

#if EMC_PRINT

static void print_version_param(const EMC_USB_CELENO_CLI_Response* self, FILE* file)
{
  FORM_DATA_HEX(file, protocol_major, self->param.version.protocol);
  FORM_DATA_HEX(file, protocol_minor, self->param.version.firmware);
}

static void print_data_param(const EMC_USB_CELENO_CLI_Response* self, FILE* file)
{
  FORM_DATA_DEC(file, data, self->param.data);
}

static void print_ioctl_func_data(const EMC_USB_CELENO_CLI_Response* self, FILE* file)
{
  FORM_DATA_HEX(file, param1, self->param.function_data.data1);
  FORM_DATA_HEX(file, param2, self->param.function_data.data2);
}

static void print_reserved_param(const EMC_USB_CELENO_CLI_Response* self, FILE* file)
{
  for (unsigned i = 0; i < 2; ++i) {
    FORM_DATA_HEX(file, param, self->param.reserved[i]);
  }
}

void EMC_USB_CELENO_CLI_Response_print(const EMC_USB_CELENO_CLI_Response* self, FILE* file)
{
  emc_std_assert(self);
  FORM_START_HEAD(file, EMC_USB_CELENO_CLI_Response);
  FORM_ATTR_HEX(file, id, self->id);
  FORM_ATTR_HEX(file, sequence_id, self->sequence_id);
  FORM_ATTR_STR(file, name, EMC_USB_CELENO_CLI_CommandId_as_string(self->id));
  FORM_ATTR_STR(file, status, EMC_USB_CELENO_CLI_Status_as_string(self->status));
  FORM_END_HEAD(file);

  switch (self->id) {
  case EMC_USB_CELENO_CLI_CommandId_GET_VERSION:
    print_version_param(self, file);
    break;
  case EMC_USB_CELENO_CLI_CommandId_SINGLE_READ:
  case EMC_USB_CELENO_CLI_CommandId_LOGGER_LEVEL_GET:
    print_data_param(self, file);
    break;
  case EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_0:
  case EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_1:
  case EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_2:
  case EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_3:
    print_ioctl_func_data(self, file);
    break;
  case EMC_USB_CELENO_CLI_CommandId_SINGLE_WRITE:
  case EMC_USB_CELENO_CLI_CommandId_KEEP_ALIVE:
  case EMC_USB_CELENO_CLI_CommandId_DISCONNECT_USB:
  case EMC_USB_CELENO_CLI_CommandId_UMAC_EXECUTE:
  case EMC_USB_CELENO_CLI_CommandId_UMAC_RESTART:
  case EMC_USB_CELENO_CLI_CommandId_BULK_WRITE:
  case EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_ZCOPY:
  case EMC_USB_CELENO_CLI_CommandId_LOGGER_LEVEL_SET:
    /* no specific parameter */
    break;
  case EMC_USB_CELENO_CLI_CommandId_BULK_READ:
  case EMC_USB_CELENO_CLI_CommandId_BULK_READ_ZCOPY:
  case EMC_USB_CELENO_CLI_CommandId_LOGGER_INFO_GET:
    /* response has data phase */
    break;
  case EMC_USB_CELENO_CLI_CommandId_SINGLE_WRITE_FAST:
  case EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_FAST:
  case EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_FAST_ZCOPY:
  default:
    print_reserved_param(self, file);
  }

  FORM_END(file, EMC_USB_CELENO_CLI_Response);
}

#endif /*EMC_PRINT*/
