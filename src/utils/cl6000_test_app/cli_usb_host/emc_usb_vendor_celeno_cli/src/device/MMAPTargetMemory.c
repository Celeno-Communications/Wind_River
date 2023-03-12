/** Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/usb/vendor/celeno/cli/TargetMemory.h"

#include <sys/mman.h>

/** maybe that will not work otherwise, when XOPEN_SOURCE is on*/
#ifndef MAP_32BIT
#  define MAP_32BIT 0x40      /* Only give out 32-bit addresses.  */
#endif
#ifndef MAP_ANONYMOUS
#  define MAP_ANONYMOUS 0x20  /* Don't use a file.  */
#endif

struct EMC_USB_CELENO_CLI_TargetMemory {
  size_t            size;  /**< the size of the memory */
  emc_std_uint32_t* begin; /**< the pointer to the begin of the memory */
};

static EMC_USB_CELENO_CLI_TargetMemory memory;

int EMC_USB_CELENO_CLI_TargetMemory_init(size_t size)
{
  memory.size = size;
  memory.begin = mmap(0, memory.size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED | MAP_32BIT, -1, 0);
  for (size_t i = 0; i < memory.size / sizeof(memory.begin[0]); ++i) {
    memory.begin[i] = 0xDEADBEEF;
  }
  return 0;
}

int EMC_USB_CELENO_CLI_TargetMemory_exit()
{
  munmap(memory.begin, memory.size);
  return 0;
}

emc_std_uint32_t EMC_USB_CELENO_CLI_TargetMemory_begin()
{
  return (emc_std_uint32_t)(emc_std_uintptr_t)(memory.begin);
}

emc_std_uint32_t* EMC_USB_CELENO_CLI_TargetMemory_ptr(emc_std_uint32_t address)
{
  return (emc_std_uint32_t*)(emc_std_uintptr_t)address;
}
