/* Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/hw/memory/UncachedMemoryPool.h"
#include "emc/std/threads.h"

static EMC_MemoryRange mg_dma_pool_range;
static char            mg_dma_pool_mem[10 * 1024];
emc_std_once_flag      mg_dma_pool_created = EMC_STD_ONCE_FLAG_INIT;
EMC_MemoryPool*        mg_dma_pool = EMC_STD_NULL;

static void init_dma_pool_once(void)
{
  mg_dma_pool = EMC_UncachedMemoryPool_new(mg_dma_pool_mem, sizeof(mg_dma_pool_mem),
                                           (void*)mg_dma_pool_range.base, mg_dma_pool_range.size);
}

EMC_MemoryPool* EMC_UncachedMemoryPool_create(const EMC_MemoryRange* range)
{
  mg_dma_pool_range = *range;

  emc_std_call_once(&mg_dma_pool_created, init_dma_pool_once);

  return mg_dma_pool;
}
