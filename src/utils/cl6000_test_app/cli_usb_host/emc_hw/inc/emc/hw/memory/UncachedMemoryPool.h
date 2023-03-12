/** @file
    @brief uncached MemoryPool
    Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#ifndef EMC_HW_MEMORY_UncachedMemoryPool_H
#define EMC_HW_MEMORY_UncachedMemoryPool_H

#include "emc/hw/memory/MemoryPool.h"

EMC_EXTERN_C_BEGIN;

/** Uncached pools require this amount of cached memory in addition to
    the actually managed uncached memory. */
#define EMC_MEMORY_POOL_REQUIRED_CACHED_SIZE 3232

/** Initializes a memory pool for the specified memory range
    @memberof EMC_MemoryPool */
EMC_MemoryPool* EMC_UncachedMemoryPool_create(const EMC_MemoryRange* range);

/** @memberof EMC_MemoryPool
   This MemoryPool use (small) region of cached memory to manage uncached memory.
   @param cached        The start address of the cached memory region for managing the uncached memory
   @param cached_size   The size of this region
   @param uncached      The uncached memory to manage
   @param uncached_size The size of the uncached memory
 */
EMC_MemoryPool* EMC_UncachedMemoryPool_new(void* cached,
                                           emc_std_size_t cached_size,
                                           void* uncached,
                                           emc_std_size_t uncached_size);

EMC_EXTERN_C_END;

#endif /* EMC_HW_MEMORY_UncachedMemoryPool_H */
