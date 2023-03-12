#include "emc/std/configure.h"
#include <user_os.h>

static bytepool_t* std_pool = 0;
void emsys_init_heap(bytepool_t* pool)
{
  std_pool = pool;
}

void* emc_std_malloc(size_t size)
{
  void* ptr = NULL;
  if (!std_pool) {
    return NULL;
  }

  if (sys_bytes_allocate(std_pool, &ptr, size, SYS_MIN_TIMEOUT) != SYS_SUCCESS) {
    ptr = NULL;
  }
  return ptr;
}

void emc_std_free(void* ptr)
{
  if (!std_pool) {
    return;
  }
  sys_bytes_release(ptr);
}
