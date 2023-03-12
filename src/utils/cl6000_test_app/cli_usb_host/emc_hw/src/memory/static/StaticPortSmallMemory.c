/* Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#define EMC_PORT_POOL_NAME Small
#define EMC_PORT_POOL_ALIGNMENT 16
#define EMC_PORT_POOL_CHUNK_SIZE EMC_PORT_ALLOCATOR_SMALL_CHUNK_SIZE
#define EMC_PORT_POOL_NB_CHUNKS EMC_PORT_ALLOCATOR_NB_SMALL_CHUNKS

#include "emc/hw/memory/private/StaticPortMemoryTemplate.h"
