/** Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/usb/vendor/celeno/cli/device/ResponseInit.h"
#include "emc/usb/vendor/celeno/cli/Command.h"
#include "emc/std/assert.h"
#include "emc/std/string.h"

emc_std_bool EMC_USB_CELENO_CLI_Response_init(EMC_USB_CELENO_CLI_Response* self,
                                              const EMC_USB_CELENO_CLI_Command* command)
{
  emc_std_bool has_response;
  emc_std_assert(self);
  emc_std_assert(command);
  has_response = EMC_USB_CELENO_CLI_CommandId_has_response(command->id);
  if (has_response) {
    emc_std_memset(self, 0, EMC_USB_CELENO_CLI_Command_SIZE);
    self->id = command->id;
    self->sequence_id = command->sequence_id;
  } else {
    emc_std_memset(self, 0, EMC_USB_CELENO_CLI_Command_SIZE); /* potentially optional */
  }

  return has_response;
}

void EMC_USB_CELENO_CLI_Response_set_version(EMC_USB_CELENO_CLI_Response* self,
                                             const EMC_USB_CELENO_CLI_Version* version)
{
  emc_std_assert(self);
  emc_std_assert(version);
  emc_std_assert(self->id == EMC_USB_CELENO_CLI_CommandId_GET_VERSION);

  self->param.version = *version;
}

void EMC_USB_CELENO_CLI_Response_set_data(EMC_USB_CELENO_CLI_Response* self,
                                          emc_std_uint32_t data)
{
  emc_std_assert(self);
  emc_std_assert(self->id == EMC_USB_CELENO_CLI_CommandId_SINGLE_READ);
  self->param.data = data;
}
