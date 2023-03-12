/* Copyright (C) 2017 emsys Embedded Systems GmbH */

#include "emc/std/ext/dma_malloc.h"
#include "emc/std/stdlib.h"
#include "emc/std/stddef.h"
#include "emc/std/assert.h"

#if EMC_TEST
static emc_std_size_t mg_cache_line_size = 16;
#else
static emc_std_size_t mg_cache_line_size = 0;
#endif

extern void* emc_std_malloc_aligned(emc_std_size_t size, emc_std_size_t alignment);
extern void emc_std_free_aligned(void* ptr);

void emc_set_dma_cache_line_size(emc_std_size_t cache_line_size)
{
  mg_cache_line_size = cache_line_size;
}

emc_std_size_t emc_dma_cache_line_size()
{
  return mg_cache_line_size;
}

void* emc_dma_malloc(emc_std_size_t size)
{
  emc_std_assert(mg_cache_line_size); // uninitialized ?
  return emc_std_malloc_aligned(size, mg_cache_line_size);
}

void emc_dma_free(void* ptr)
{
  emc_std_free_aligned(ptr);
}

void emc_std_dma_malloc_init(void* buffer, size_t buffer_size)
{
  UNUSED_PARAM(buffer);
  UNUSED_PARAM(buffer_size);
}
