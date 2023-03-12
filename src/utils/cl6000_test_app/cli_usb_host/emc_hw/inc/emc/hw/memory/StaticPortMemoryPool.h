/** @file
    @brief MemoryPool based on static arrays with port-specific sizes
    Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#ifndef EMC_HW_MEMORY_StaticPortMemoryPool_H
#define EMC_HW_MEMORY_StaticPortMemoryPool_H

#include "emc/hw/memory/MemoryPool.h"

EMC_EXTERN_C_BEGIN;

/** Constructor.
    Create a pool based on static arrays with port-specific sizes.
    @return the pool
    @memberof EMC_MemoryPool */
struct EMC_MemoryPool* EMC_StaticPortMemoryPool_new(void);

EMC_EXTERN_C_END;

#endif /* EMC_HW_MEMORY_StaticPortMemoryPool_H */
