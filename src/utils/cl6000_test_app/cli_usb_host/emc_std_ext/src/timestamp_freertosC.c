/** @file
 *  Copyright (C) 2022 emsys Embedded Systems GmbH
 **/

#include "emc/std/ext/timestamp.h"
#include "external/freertos_kernel/FreeRTOS_wrap.h"

#include "emc/std/stdint.h"
#include "emc/std/limits.h"

static timestamp_t emc_tick_cycles = configCPU_CLOCK_HZ;

void emc_timer_set_tick_cycles_per_second(timestamp_t cycles_s)
{
  emc_tick_cycles = cycles_s;
}

#if defined(__XTENSA__)
void emc_timestamp_init(void) {}

#else
#  include <unistd.h>
void emc_timestamp_init(void)
{
  emc_tick_cycles = sysconf(_SC_CLK_TCK);
}

#endif

timestamp_t emc_timestamp(void)
{
  return (timestamp_t)portGET_RUN_TIME_COUNTER_VALUE();
}

timestamp_t emc_timestamp_ticks_per_second(void)
{
  return emc_tick_cycles;
}

timestamp_t emc_timestamp_wrap(void)
{
  return (uint32_t)-1;
}

timestamp_t emc_timestamp_to_seconds(timestamp_t difference)
{
  return difference / emc_tick_cycles;
}

timestamp_t emc_timestamp_to_milliseconds(timestamp_t difference)
{
  return (1000 * difference) / emc_tick_cycles;
}

timestamp_t emc_timestamp_to_microseconds(timestamp_t difference)
{
  return (1000000 * difference) / emc_tick_cycles;
}

timestamp_t emc_timestamp_difference(timestamp_t subtrahend, timestamp_t minuend)
{
  return subtrahend - minuend;
}
