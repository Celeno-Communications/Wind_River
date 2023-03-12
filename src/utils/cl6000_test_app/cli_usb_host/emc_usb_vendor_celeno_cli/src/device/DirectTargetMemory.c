/** Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/usb/vendor/celeno/cli/TargetMemory.h"

int EMC_USB_CELENO_CLI_TargetMemory_init(size_t size)
{
  UNUSED_PARAM(size);
  return 0;
}

int EMC_USB_CELENO_CLI_TargetMemory_exit()
{
  return 0;
}

emc_std_uint32_t EMC_USB_CELENO_CLI_TargetMemory_begin()
{
  return 0;
}

emc_std_uint32_t* EMC_USB_CELENO_CLI_TargetMemory_ptr(emc_std_uint32_t address)
{
  return (emc_std_uint32_t*)(emc_std_uintptr_t)address;
}
