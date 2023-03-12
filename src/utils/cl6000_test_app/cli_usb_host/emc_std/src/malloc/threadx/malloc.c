#include <tx_api.h>
#include <emc/std/configure.h>

TX_BYTE_POOL* std_pool = NULL;
void emsys_init_heap(TX_BYTE_POOL* pool)
{
  std_pool = pool;
}

void* emc_std_malloc(size_t size)
{
  void* ptr = NULL;
  if (!std_pool) {
    return NULL;
  }

  if (tx_byte_allocate(std_pool, &ptr, size, TX_NO_WAIT) != TX_SUCCESS) {
    ptr = NULL;
  }
  return ptr;
}

void emc_std_free(void* ptr)
{
  if (!std_pool) {
    return;
  }
  tx_byte_release(ptr);
}
