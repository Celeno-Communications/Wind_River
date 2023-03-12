/** @file
    @brief malloc based MemoryPool
    Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#ifndef EMC_HW_MEMORY_MallocMemoryPool_H
#define EMC_HW_MEMORY_MallocMemoryPool_H

#include "emc/hw/memory/MemoryPool.h"

EMC_EXTERN_C_BEGIN;

/** @memberof EMC_MemoryPool
    @brief Return a new pool based on malloc and free calls */
struct EMC_MemoryPool* EMC_MallocMemoryPool_new(void);

/** @memberof EMC_MemoryPool
    @brief Initialize a pool based on malloc and free calls */
void EMC_MallocMemoryPool_initialize(struct EMC_MemoryPool*);

EMC_EXTERN_C_END;

#endif /* EMC_HW_MEMORY_MallocMemoryPool_H */
