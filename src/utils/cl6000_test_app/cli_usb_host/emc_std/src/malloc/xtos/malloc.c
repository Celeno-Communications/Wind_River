/* Copyright (C) 2017 emsys Embedded Systems GmbH */
#include "emc/std/private/HeapUsage.h"
#include "emc/std/private/malloc_debug.h"

#include "emc/std/stdlib.h"
#include "emc/std/threads.h"
#include "emc/std/assert.h"
#include "emc/std/emu/xtos/wrapper.h"
#include "emc/std/stddef.h"

#if EMC_STD_MALLOC_LOCK_MUTEX
static emc_std_mtx_t mg_pool_lock;
#elif EMC_STD_MALLOC_LOCK_SPINLOCK
static emc_std_spin_t mg_pool_lock;
#else
#  error Define either EMC_STD_MALLOC_LOCK_MUTEX or EMC_STD_MALLOC_LOCK_SPINLOCK
#endif

static struct sue_allocator_pool_s mg_pool;
static void*                       mg_pool_memory[EMC_STD_MALLOC_HEAP_SIZE / sizeof(void*)];

static unsigned log_time(void) { return 0 /* EMC_Log_log_count(0) */; }

static void initialize_mg_pool(void)
{
#if EMC_STD_MALLOC_LOCK_MUTEX
  emc_std_mtx_init(&mg_pool_lock, emc_std_mtx_plain);
#else
  emc_std_spin_init(&mg_pool_lock);
#endif
  emc_malloc_debug_init(log_time);
  mg_pool.base = mg_pool_memory;
  mg_pool.end = &mg_pool_memory[EMC_STD_MALLOC_HEAP_SIZE / sizeof(void*)];

  sue_init(&mg_pool);
}

static emc_std_bool lock_mg_pool(void)
{
  static emc_std_once_flag once = EMC_STD_ONCE_FLAG_INIT;
  emc_std_bool             lock_ok = 0;
  emc_std_call_once(&once, initialize_mg_pool);

#if EMC_STD_MALLOC_LOCK_MUTEX
  lock_ok = emc_std_thrd_success == emc_std_mtx_lock(&mg_pool_lock);
#else
  lock_ok = emc_std_thrd_success == emc_std_spin_lock(&mg_pool_lock);
#endif
  emc_std_assert(lock_ok);
  return lock_ok;
}

static emc_std_bool unlock_mg_pool(void)
{
  emc_std_bool unlock_ok = 0;
#if EMC_STD_MALLOC_LOCK_MUTEX
  unlock_ok = emc_std_thrd_success == emc_std_mtx_unlock(&mg_pool_lock);
#else
  unlock_ok = emc_std_thrd_success == emc_std_spin_unlock(&mg_pool_lock);
#endif
  emc_std_assert(unlock_ok);
  return unlock_ok;
}

void* emc_std_malloc_aligned(emc_std_size_t size, emc_std_size_t alignment)
{
  void* ptr = 0;

  if (lock_mg_pool()) {
    ptr = sue_alloc_aligned(&mg_pool, alignment, size);
    unlock_mg_pool();
  }
  emc_malloc_debug_alloc(ptr, (unsigned)size);
  return ptr;
}

void emc_std_free_aligned(void* aligned_ptr)
{
  emc_malloc_debug_free(aligned_ptr);
  if (EMC_STD_NULL == aligned_ptr) {
    return;
  }

  if (lock_mg_pool()) {
    sue_free_aligned(&mg_pool, aligned_ptr);
    unlock_mg_pool();
  }
}

void* emc_std_malloc(emc_std_size_t size)
{
  void* ptr = 0;
  if (lock_mg_pool()) {
    ptr = sue_alloc(&mg_pool, size);
    unlock_mg_pool();
  }
  emc_malloc_debug_alloc(ptr, (unsigned)size);
  return ptr;
}

void emc_std_free(void* ptr)
{
  emc_malloc_debug_free(ptr);
  if (lock_mg_pool()) {
    sue_free(&mg_pool, ptr);
    unlock_mg_pool();
  }
}

void emc_heap_report(EmcHeapReport* report)
{
  UNUSED_PARAM(report);
}
