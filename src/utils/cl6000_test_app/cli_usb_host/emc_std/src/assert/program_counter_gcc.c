#include "emc/std/emu/program_counter.h"

void* emc_std_get_pc(void)
{
  return __builtin_return_address(0);
}
