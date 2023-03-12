/** @file
    @brief MemoryPool.
    Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#ifndef EMC_HW_MEMORY_MemoryPool_H
#define EMC_HW_MEMORY_MemoryPool_H

#include "emc/hw/memory/Memory.h"
#include "emc/std/stdbool.h"
#include "emc/std/stddef.h"

EMC_EXTERN_C_BEGIN;

/** Private virtual functions of a MemoryPool */
struct EMC_MemoryPoolFunctionTable;

/** A MemoryPool can allocate Memory objects */
typedef struct EMC_MemoryPool {
  /** The virtual function table */
  const struct EMC_MemoryPoolFunctionTable* vtable;
} EMC_MemoryPool;

/** Constructor.
    @memberof EMC_MemoryPool */
struct EMC_MemoryPool* EMC_MemoryPool_new(void* begin, emc_std_size_t size);

/** @memberof EMC_MemoryPool
    @brief Destructor */
void EMC_MemoryPool_destroy(struct EMC_MemoryPool* self);

/** @memberof EMC_MemoryPool
    @brief Destroy and delete a pool */
void EMC_MemoryPool_delete(struct EMC_MemoryPool* self);

/** Allocate memory from a given pool.
    @param self The pool context
    @param size the requested size to allocate
    @param alignment the required alignment of the allocated memory chunk
    @param out_memory the allocated memory

    Assert if no memory is available.
    The Memory must be deallocated before the MemoryPool is destroyed.
    @see EMC_Memory_deallocate
    @memberof EMC_MemoryPool */
void EMC_MemoryPool_allocate_aligned(struct EMC_MemoryPool* self,
                                     emc_std_size_t size,
                                     emc_std_size_t alignment,
                                     struct EMC_Memory* out_memory);

EMC_EXTERN_C_END;

#endif /* EMC_HW_MEMORY_MemoryPool_H */
