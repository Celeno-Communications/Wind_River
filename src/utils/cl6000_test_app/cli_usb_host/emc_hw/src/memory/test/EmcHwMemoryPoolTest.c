/* Copyright (C) 2013, 2020 emsys Embedded Systems GmbH */

#include "emc/hw/memory/MemoryPool.h"
#include "emc/hw/memory/UncachedMemoryPool.h"
#include "emc/std/threads.h"

#define CALL_ONCE_IMPLEMENTED 1

#if defined(EMC_STD_MUTEX_NULL) && EMC_STD_MUTEX_NULL
#  undef  CALL_ONCE_IMPLEMENTED
#  define CALL_ONCE_IMPLEMENTED 0
#elif defined(EMC_STD_MUTEX_NONE) && EMC_STD_MUTEX_NONE
#  undef  CALL_ONCE_IMPLEMENTED
#  define CALL_ONCE_IMPLEMENTED 0
#endif

static char mg_buffer[100 * 1024];

#if 8 == EMC_SIZEOF_POINTER
static char mg_cached[EMC_MEMORY_POOL_REQUIRED_CACHED_SIZE * 4];
#else
static char mg_cached[EMC_MEMORY_POOL_REQUIRED_CACHED_SIZE];
#endif
#include "stdio.h"
static emc_std_bool test_invalid_mem(struct EMC_MemoryPool* pool)
{
  struct EMC_Memory    mem;
  const emc_std_size_t SIZE = sizeof(mg_buffer) * 2;

  if (!pool) {
    return 0;
  }

  EMC_MemoryPool_allocate_aligned(pool, SIZE, 16, &mem);
  if (EMC_Memory_valid(mem)) {
    return 0;
  } else {
    return 1;
  }
}

static emc_std_bool test_pool(struct EMC_MemoryPool* pool)
{
  struct EMC_Memory    mem[16];
  const emc_std_size_t SIZE = 8 * 1024;
  emc_std_size_t       i;
  if (!pool) {
    return 0;
  }
  for (i = 0; i < sizeof(mem) / sizeof(mem[0]); ++i) {
    char* pointer;
    EMC_MemoryPool_allocate_aligned(pool, SIZE, 16, mem + i);
    pointer = EMC_Memory_address(mem[i]);
    if (pointer) {
      if (pointer < mg_buffer) {
        return 0;
      }
      if (pointer + SIZE > mg_buffer + sizeof(mg_buffer)) {
        return 0;
      }
    } else {
      if (i < 10) {
        return 0;
      }
      break;
    }
  }
  if (i == sizeof(mem) / sizeof(mem[0])) {
    return 0;
  }
  while (i--) {
    EMC_Memory_free(&mem[i], SIZE);
  }
  return 1;
}

static emc_std_bool test_default_pool(void)
{
  return test_pool(EMC_MemoryPool_new(mg_buffer, sizeof(mg_buffer)));
}

static emc_std_bool test_uncached_pool(void)
{
  return test_pool(EMC_UncachedMemoryPool_new(mg_cached, sizeof(mg_cached),
                                              mg_buffer, sizeof(mg_buffer)));
}

#if CALL_ONCE_IMPLEMENTED
static emc_std_bool test_uncached_pool_create_once(void)
{
  EMC_MemoryRange uncached_range = {(emc_std_uintptr_t)mg_buffer, sizeof(mg_buffer)};
  return test_pool(EMC_UncachedMemoryPool_create(&uncached_range));
}

#endif

int main(int argc, char* argv[])
{
  UNUSED_PARAM(argc);
  UNUSED_PARAM(argv);

  if (!test_default_pool()) {
    return 1;
  }
  if (!test_uncached_pool()) {
    return 1;
  }
  if (!test_invalid_mem(EMC_MemoryPool_new(mg_buffer, sizeof(mg_buffer)))) {
    return 1;
  }
#if CALL_ONCE_IMPLEMENTED
  if (!test_uncached_pool_create_once()) {
    return 1;
  }
#endif

  return 0;
}
