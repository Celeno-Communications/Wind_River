#include "emc/std/stdlib.h"
#include "emc/std/ext/dma_malloc.h"

void emc_std_dma_malloc_init(void* buffer, size_t buffer_size)
{
  UNUSED_PARAM(buffer);
  UNUSED_PARAM(buffer_size);
}

void* emc_dma_malloc(size_t size)
{
  return emc_std_malloc(size);
}

void emc_dma_free(void* ptr)
{
  emc_std_free(ptr);
}

void emc_set_dma_cache_line_size(emc_std_size_t cache_line_size)
{
  UNUSED_PARAM(cache_line_size);
}

emc_std_size_t emc_dma_cache_line_size()
{
  return 0;
}
