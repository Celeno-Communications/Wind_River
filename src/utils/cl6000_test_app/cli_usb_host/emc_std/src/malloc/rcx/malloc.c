#include "emc/log/log.h"
#include "rx_Includes.h"
#include "emc/std/private/malloc_debug.h"
#include "emc/std/stdatomic.h"

emc_std_atomic_once_flag init_malloc_debug_once = EMC_STD_ONCE_FLAG_INIT;

static unsigned log_time(void)
{
  return EMC_Log_log_count(0);
}

static unsigned init_malloc_debug(void)
{
  emc_malloc_debug_init(log_time);
}

void* emc_std_malloc(emc_std_size_t size)
{
  void* ptr = 0;
  rX_MemAllocateMemory(&ptr, size);
  emc_std_call_once(&init_malloc_debug_once, init_malloc_debug);
  emc_malloc_debug_alloc(ptr, (unsigned)size);
  return ptr;
}

void emc_std_free(void* ptr)
{
  if (!ptr) {
    return;
  }
  emc_malloc_debug_free(ptr);
  rX_MemFreeMemory(ptr);
}
