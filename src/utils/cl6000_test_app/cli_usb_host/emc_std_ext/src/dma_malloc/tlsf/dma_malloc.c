/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#include "emc/std/ext/dma_malloc.h"

#include "emc/std/assert.h"
#include "emc/std/stdlib.h"
#include "emc/std/stddef.h"
#include "emc/std/threads.h"
#include "external/baisoku/tlsf.h"
#include "emc/std/private/HeapUsage.h"

#if EMC_STD_MALLOC_LOCK_MUTEX
static emc_std_mtx_t mg_pool_lock;
#elif EMC_STD_MALLOC_LOCK_SPINLOCK
static emc_std_spin_t mg_pool_lock;
#else
#  error Define either EMC_STD_MALLOC_LOCK_MUTEX or EMC_STD_MALLOC_LOCK_SPINLOCK
#endif

static emc_std_size_t mg_cache_line_size = 0;
static emc_std_size_t mg_alignment_mask = 0;
static tlsf_pool      mg_pool;
static void*          mg_pool_memory = 0;
static size_t         mg_pool_size = 0;
static EmcHeapReport  mg_report;

static emc_std_bool lock_mg_pool(void)
{
  emc_std_bool lock_ok = 0;
  emc_std_assert(mg_pool_memory);
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

void emc_std_dma_malloc_init(void* buffer, size_t buffer_size)
{
  mg_report.used = 0;
  mg_report.max_used = 0;
  mg_report.size = buffer_size;

  mg_pool_memory = buffer;
  mg_pool_size = buffer_size;
#if EMC_STD_MALLOC_LOCK_MUTEX
  emc_std_mtx_init(&mg_pool_lock, emc_std_mtx_plain);
#else
  emc_std_spin_init(&mg_pool_lock);
#endif
  mg_pool = tlsf_create(mg_pool_memory, mg_pool_size);
}

void emc_set_dma_cache_line_size(emc_std_size_t cache_line_size)
{
  mg_cache_line_size = cache_line_size;
  mg_alignment_mask = ~((~(size_t)0 / cache_line_size) * cache_line_size);
}

emc_std_size_t emc_dma_cache_line_size()
{
  return mg_cache_line_size;
}

// for debug break points
static void emc_dma_alloc_failed(emc_std_size_t size)
{
  UNUSED_PARAM(size);
}

static void* _malloc_aligned(emc_std_size_t size, emc_std_size_t alignment)
{
  void* ptr = 0;
  if (lock_mg_pool()) {
    ptr = tlsf_memalign(mg_pool, alignment, size);
    if (ptr) {
      mg_report.used += tlsf_block_size(ptr);
      if (mg_report.used > mg_report.max_used) {
        mg_report.max_used = mg_report.used;
      }
    } else {
      emc_dma_alloc_failed(size);
    }
    unlock_mg_pool();
  }
  return ptr;
}

void* emc_dma_malloc(emc_std_size_t size)
{
  emc_std_size_t aligned_size;

  emc_std_assert(mg_cache_line_size); // uninitialized ?

  aligned_size = size + (mg_cache_line_size - 1);
  aligned_size &= (~mg_alignment_mask);

  return _malloc_aligned(aligned_size, mg_cache_line_size);
}

void emc_dma_free(void* ptr)
{
  if (lock_mg_pool()) {
    if (ptr) {
      mg_report.used -= emc_ext_tlsf_block_size(ptr);
    }
    tlsf_free(mg_pool, ptr);
    unlock_mg_pool();
  }
}
