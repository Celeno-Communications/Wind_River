/** Copyright (C) 2021 emsys Embedded Systems GmbH */
#include "emc/usb/vendor/celeno/cli/Command.h"

#include "emc/std/assert.h"
#include "./dma_copy.h"

void EMC_USB_CELENO_CLI_Command_put(const EMC_USB_CELENO_CLI_Command* self, void** stream)
{
  emc_std_uint8_t* begin = *stream;

  // todo: convert byteorder from CPU to USB
  dma_word32_copy(begin, self, EMC_USB_CELENO_CLI_Command_SIZE);

  *stream = begin + EMC_USB_CELENO_CLI_Command_SIZE;
}

void EMC_USB_CELENO_CLI_Command_get(EMC_USB_CELENO_CLI_Command* self, void** stream)
{
  emc_std_uint8_t* begin = *stream;

  // todo: convert byteorder from USB to CPU
  dma_word32_copy(self, begin, EMC_USB_CELENO_CLI_Command_SIZE);

  *stream = begin + EMC_USB_CELENO_CLI_Command_SIZE;
}
