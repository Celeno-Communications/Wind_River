/* Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#include "emc/hw/memory/StaticPortMemoryPool.h"
#include "emc/hw/memory/private/MemoryPool.h"
#include "emc/hw/memory/private/StaticPortMemory.h"

#include "emc/std/assert.h"
#include "emc/std/stdint.h"

static struct EMC_MemoryPool mg_pool[EMC_MEMORY_POOL_TYPE_STATIC_INSTANCES];

/* Return the memory "chunk" allocator function for the given size. */
static struct EMC_Memory (*pool_allocator(emc_std_size_t size))(ptrdiff_t) {
  if (size <= EMC_PORT_ALLOCATOR_SMALL_CHUNK_SIZE) {
    return EMC_StaticPortSmallMemory_allocate;
  } else if (size <= EMC_PORT_ALLOCATOR_MEDIUM_CHUNK_SIZE) {
    return EMC_StaticPortMediumMemory_allocate;
  } else if (size <= EMC_PORT_ALLOCATOR_LARGE_CHUNK_SIZE) {
    return EMC_StaticPortLargeMemory_allocate;
  } else {
#ifdef __KLOCWORK__
    /* Real code doesn't need this to raise SIGSEGV.
       Lint requires nothing or assert(zero) but not assert(0).
       Insight requires assert(0) but not nothing or assert(zero). */
    emc_std_assert(0);
#endif
    return 0;
  }
}

static void pool_allocate(struct EMC_MemoryPool* self,
                          emc_std_size_t size,
                          emc_std_size_t alignment,
                          struct EMC_Memory* out_memory)
{
  ptrdiff_t instance = self - mg_pool;
  emc_std_assert(0 <= instance && instance < EMC_MEMORY_POOL_TYPE_STATIC_INSTANCES);
#if !defined(__KLOCWORK__)
  /* klocwork warns on dereferencing of pointer which is returned from pool_allocator(size),
     but here we have a pointer to a function */
  *out_memory = (*pool_allocator(size))(instance);
#endif
  emc_std_assert((emc_std_uintptr_t)EMC_Memory_address(*out_memory) % alignment == 0);
  (void)alignment;
}

static void pool_destroy(struct EMC_MemoryPool* self)
{
  (void)self;
}

static void pool_delete(struct EMC_MemoryPool* self)
{
  pool_destroy(self);
  self->vtable = 0;
}

static const struct EMC_MemoryPoolFunctionTable mg_memory_pool_vtable = {
  pool_destroy, pool_delete, pool_allocate
};

struct EMC_MemoryPool* EMC_StaticPortMemoryPool_new()
{
  emc_std_size_t index = 0;
  for (index = 0; index < sizeof(mg_pool) / sizeof(mg_pool[0]); ++index) {
    if (0 == mg_pool[index].vtable) {
      mg_pool[index].vtable = &mg_memory_pool_vtable;
      return mg_pool + index;
    }
  }
  emc_std_assert(emc_lint_zero);
  return 0;
}
