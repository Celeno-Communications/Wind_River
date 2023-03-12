/* Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#ifndef EMC_HW_MEMORY_PRIVATE_StaticPortMemory_H
#define EMC_HW_MEMORY_PRIVATE_StaticPortMemory_H

#include <emc/std/stddef.h>
#include "emc/hw/memory/Memory.h"

struct EMC_Memory EMC_StaticPortSmallMemory_allocate(ptrdiff_t instance);
struct EMC_Memory EMC_StaticPortMediumMemory_allocate(ptrdiff_t instance);
struct EMC_Memory EMC_StaticPortLargeMemory_allocate(ptrdiff_t instance);

#endif /* EMC_HW_MEMORY_PRIVATE_StaticPortMemory_H */
