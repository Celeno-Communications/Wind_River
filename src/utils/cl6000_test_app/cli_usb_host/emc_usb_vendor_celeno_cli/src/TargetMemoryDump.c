/** Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/usb/vendor/celeno/cli/TargetMemoryDump.h"

#if EMC_PRINT
#  include <stdio.h>
#endif

void EMC_USB_CELENO_CLI_TargetMemory_dump(emc_std_uint32_t address, emc_std_uint32_t size)
{
#if EMC_PRINT
  unsigned i;
  fprintf(stderr, "\n");
  for (i = 0; i < size / sizeof(emc_std_uint32_t); ++i, address += 4) {
    fprintf(stderr, "[0x%08x] 0x%08x\n", address, EMC_USB_CELENO_CLI_TargetMemory_read(address));
  }
#else
  UNUSED_PARAM(address);
  UNUSED_PARAM(size);
#endif
}
