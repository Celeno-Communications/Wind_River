#ifndef EMC_USB_VENDOR_CELENO_CLI_SRC_dma_copy_H
#define EMC_USB_VENDOR_CELENO_CLI_SRC_dma_copy_H

#include "emc/usb/vendor/celeno/cli/configure.h"

#include "emc/std/stddef.h"
#include "emc/std/assert.h"

static inline void dma_word32_copy(void* target, const void* source, size_t size)
{
  emc_std_uint32_t*       ptr_target = target;
  const emc_std_uint32_t* ptr_source = source;

  emc_std_assert(0 == ((uintptr_t)target & 0x3));
  emc_std_assert(0 == ((uintptr_t)source & 0x3));
  emc_std_assert(0 == (size & 0x3));

  for (size_t i = (size / 4); i > 0; i--) {
    *ptr_target++ = *ptr_source++;
  }

}

#endif
