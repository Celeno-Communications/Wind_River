/** Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/usb/vendor/celeno/cli/Response.h"

#include "emc/std/assert.h"
#include "./dma_copy.h"

void EMC_USB_CELENO_CLI_Response_put(const EMC_USB_CELENO_CLI_Response* self, void** stream)
{
  emc_std_uint8_t* begin = *stream;

  // toto: convert byteorder from CPU to USB
  dma_word32_copy(begin, self, EMC_USB_CELENO_CLI_Response_SIZE);

  *stream = begin + EMC_USB_CELENO_CLI_Response_SIZE;
}

void EMC_USB_CELENO_CLI_Response_get(EMC_USB_CELENO_CLI_Response* self, void** stream)
{
  emc_std_uint8_t* begin = *stream;

  // todo: convert byteorder from USB to CPU
  dma_word32_copy(self, begin, EMC_USB_CELENO_CLI_Response_SIZE);

  *stream = begin + EMC_USB_CELENO_CLI_Response_SIZE;
}
