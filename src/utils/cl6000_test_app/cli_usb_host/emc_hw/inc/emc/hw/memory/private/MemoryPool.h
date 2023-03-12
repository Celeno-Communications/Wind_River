/* Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#ifndef EMC_HW_MEMORY_PRIVATE_MemoryPool_H
#define EMC_HW_MEMORY_PRIVATE_MemoryPool_H

#include "emc/hw/memory/MemoryPool.h"

EMC_EXTERN_C_BEGIN;

struct EMC_Memory;

/** The MemoryPool specific FunctionTable
 */
struct EMC_MemoryPoolFunctionTable {
  /** The destroy function */
  void (* destroy_pool)(struct EMC_MemoryPool*);
  /** The delete function */
  void (* delete_pool)(struct EMC_MemoryPool*);
  /** The allocate function */
  void (* allocate_aligned)(struct EMC_MemoryPool*,
                            emc_std_size_t size,
                            emc_std_size_t alignment,
                            struct EMC_Memory* out_memory);
};

EMC_EXTERN_C_END;

#endif /* EMC_HW_MEMORY_PRIVATE_MemoryPool_H */
