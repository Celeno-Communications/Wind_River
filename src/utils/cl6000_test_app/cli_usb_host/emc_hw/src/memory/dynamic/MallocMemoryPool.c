/* Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#include <emc/std/stdlib.h>
#include <emc/std/string.h>
#include "emc/std/stdint.h"
#include "emc/std/assert.h"

#include "emc/hw/memory/private/Memory.h"
#include "emc/hw/memory/private/MemoryPool.h"
#include "emc/hw/memory/MallocMemoryPool.h"

static uintptr_t* memory_round_down_preceding_pointer(uintptr_t ptr)
{
  uintptr_t  round_down = ptr & ~(uintptr_t)(sizeof(uintptr_t) - 1);
  uintptr_t* preceding = ((uintptr_t*)round_down) - 1;
  return preceding;
}

/* Memory */

static char* memory_address(struct EMC_Memory self)
{
  emc_std_assert(sizeof(uintptr_t) <= sizeof(self.handle));
  return (char*)(uintptr_t)self.handle;
}

static void memory_free(struct EMC_Memory self, emc_std_size_t size_for_debugging)
{
  UNUSED_PARAM(size_for_debugging);
  emc_std_free((void*)*memory_round_down_preceding_pointer((uintptr_t)self.handle));
}

static void memory_read(struct EMC_Memory self,
                        emc_std_size_t offset,
                        void* buffer,
                        emc_std_size_t buffer_size)
{
  emc_std_memcpy(buffer, memory_address(self) + offset, buffer_size);
}

static void memory_write(struct EMC_Memory self,
                         emc_std_size_t offset,
                         const void* buffer,
                         emc_std_size_t buffer_size)
{
  emc_std_memcpy(memory_address(self) + offset, buffer, buffer_size);
}

struct EMC_PhysicalAddress memory_physical_address(struct EMC_Memory self)
{
  emc_std_assert(EMC_PhysicalAddress_is_supported());
  return EMC_PhysicalAddress_new(memory_address(self));
}

static const struct EMC_MemoryFunctionTable mg_memory_vtable = {
  memory_address, memory_free, memory_read, memory_write,
  memory_physical_address
};

/* MemoryPool */

static void pool_destroy(struct EMC_MemoryPool* pool)
{
  pool->vtable = 0;
}

static void pool_delete(struct EMC_MemoryPool* pool)
{
  pool_destroy(pool);
  emc_std_free(pool);
}

static void allocate_aligned_memory(struct EMC_MemoryPool* self,
                                    emc_std_size_t size,
                                    emc_std_size_t alignment,
                                    struct EMC_Memory* out_memory)
{
  emc_std_size_t extra_size = sizeof(uintptr_t) + alignment - 1;
  uintptr_t      memory = (uintptr_t)emc_std_malloc(extra_size + size);
  uintptr_t      rounded = (memory + extra_size) & ~(uintptr_t)(alignment - 1);
  UNUSED_PARAM(self);

  *memory_round_down_preceding_pointer(rounded) = memory;
  out_memory->vtable = &mg_memory_vtable;
  out_memory->handle = rounded; /* don't cast, warnings indicate a bug */
}

static const struct EMC_MemoryPoolFunctionTable mg_pool_vtable = {
  pool_destroy, pool_delete, allocate_aligned_memory
};

void EMC_MallocMemoryPool_initialize(struct EMC_MemoryPool* pool)
{
  pool->vtable = &mg_pool_vtable;
}

struct EMC_MemoryPool* EMC_MallocMemoryPool_new()
{
  struct EMC_MemoryPool* result = emc_std_malloc(sizeof(struct EMC_MemoryPool));
  EMC_MallocMemoryPool_initialize(result);
  return result;
}
