/* Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#ifndef EMC_HW_MEMORY_PRIVATE_Memory_H
#define EMC_HW_MEMORY_PRIVATE_Memory_H

#include "emc/hw/memory/Memory.h"

EMC_EXTERN_C_BEGIN;

/** the Memory specific FunctionTable
 */
struct EMC_MemoryFunctionTable {
  /** Get virtual address of memory*/
  char*(* address)(struct EMC_Memory self);
  /** The free function*/
  void (* free)(struct EMC_Memory, emc_std_size_t size_for_debugging);
  /** The read function*/
  void (* read)(struct EMC_Memory,
                emc_std_size_t offset,
                void* buffer,
                emc_std_size_t buffer_size);
  /** The write function*/
  void (* write)(struct EMC_Memory,
                 emc_std_size_t offset,
                 const void* buffer,
                 emc_std_size_t buffer_size);
  /** The physical address conversion member function */
  struct EMC_PhysicalAddress (* physical_address)(struct EMC_Memory);
};

EMC_EXTERN_C_END;

#endif /* EMC_HW_MEMORY_PRIVATE_Memory_H */
