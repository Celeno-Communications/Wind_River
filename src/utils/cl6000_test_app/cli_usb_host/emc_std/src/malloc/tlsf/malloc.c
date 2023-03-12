/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#include "external/baisoku/tlsf.h"
#include "emc/std/private/malloc_debug.h"
#include "emc/std/private/HeapUsage.h"
#include "emc/log/log.h"
#include "emc/std/stddef.h"
#include "emc/std/threads.h"
#include "emc/std/assert.h"

#if EMC_STD_MALLOC_LOCK_MUTEX
static emc_std_mtx_t mg_pool_lock;
#elif EMC_STD_MALLOC_LOCK_SPINLOCK
static emc_std_spin_t mg_pool_lock;
#else
#  error Define either EMC_STD_MALLOC_LOCK_MUTEX or EMC_STD_MALLOC_LOCK_SPINLOCK
#endif

static tlsf_pool mg_pool;
static void*     mg_pool_memory[EMC_STD_MALLOC_HEAP_SIZE / sizeof(void*)];

static EmcHeapReport mg_report;

static unsigned log_time(void) { return 0 /* EMC_Log_log_count(0) */; }

static void initialize_mg_pool(void)
{
#if EMC_STD_MALLOC_LOCK_MUTEX
  emc_std_mtx_init(&mg_pool_lock, emc_std_mtx_plain);
#else
  emc_std_spin_init(&mg_pool_lock);
#endif
  emc_malloc_debug_init(log_time);
  mg_pool = tlsf_create(mg_pool_memory, sizeof(mg_pool_memory));
  mg_report.used = 0;
  mg_report.max_used = 0;
  mg_report.size = sizeof(mg_pool_memory);
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

void* emc_std_malloc(emc_std_size_t size)
{
  void* ptr = 0;
  if (lock_mg_pool()) {
    ptr = tlsf_malloc(mg_pool, size);
    mg_report.used += emc_ext_tlsf_block_size(ptr);
    if (mg_report.used > mg_report.max_used) {
      mg_report.max_used = mg_report.used;
    }
    unlock_mg_pool();
  }
  emc_malloc_debug_alloc(ptr, (unsigned)size);
  return ptr;
}

void* emc_std_malloc_aligned(emc_std_size_t size, emc_std_size_t alignment)
{
  void* ptr = 0;
  if (lock_mg_pool()) {
    ptr = tlsf_memalign(mg_pool, alignment, size);
    mg_report.used += emc_ext_tlsf_block_size(ptr);
    if (mg_report.used > mg_report.max_used) {
      mg_report.max_used = mg_report.used;
    }
    unlock_mg_pool();
  }
  emc_malloc_debug_alloc(ptr, (unsigned)size);
  return ptr;
}

void emc_std_free(void* ptr)
{
  emc_malloc_debug_free(ptr);
  if (lock_mg_pool()) {
    if (ptr) {
      mg_report.used -= emc_ext_tlsf_block_size(ptr);
    }
    tlsf_free(mg_pool, ptr);
    unlock_mg_pool();
  }
}

void emc_heap_report(EmcHeapReport* report)
{
  if (lock_mg_pool()) {
    *report = mg_report;
    unlock_mg_pool();
  }
}
