/** Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/usb/vendor/celeno/cli/Version.h"

#include "emc/std/assert.h"
#include "emc/std/ext/bitoperation.h"

void EMC_USB_CELENO_CLI_Version_init(EMC_USB_CELENO_CLI_Version* self,
                                     emc_std_uint32_t app_version)
{
  emc_std_assert(self);
  self->protocol = EMC_USB_VENDOR_CELENO_CLI_PROTOCOL_VERSION;
  self->firmware = app_version;
}
