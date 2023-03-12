/* Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#include "emc/hw/memory/private/MemoryPool.h"
#include "emc/std/stddef.h"

void EMC_MemoryPool_allocate_aligned(struct EMC_MemoryPool* self,
                                     emc_std_size_t size,
                                     emc_std_size_t alignment,
                                     struct EMC_Memory* out_memory)
{
  if (0U == alignment) {
    alignment = 1U;
  }
  (*self->vtable->allocate_aligned)(self, size, alignment, out_memory);
}

void EMC_MemoryPool_destroy(struct EMC_MemoryPool* self)
{
  if (self) {
    (*self->vtable->destroy_pool)(self);
  }
}

void EMC_MemoryPool_delete(struct EMC_MemoryPool* self)
{
  if (self) {
    (*self->vtable->delete_pool)(self);
  }
}
