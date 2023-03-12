#include "emc/system/celeno/device/timer_ext.h"

static emc_std_uint32_t emc_system_celeno_tick_cycles = UMAC_START_CYCLES_PER_MICRO_SECOND;

void timer_set_tick_cycles(emc_std_uint32_t cycles_us)
{
  emc_system_celeno_tick_cycles = cycles_us;
}

emc_std_uint32_t timer_tick_cycles()
{
  return emc_system_celeno_tick_cycles;
}
