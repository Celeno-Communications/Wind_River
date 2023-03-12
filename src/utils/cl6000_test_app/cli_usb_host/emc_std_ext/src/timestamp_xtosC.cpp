/** @file
 *  @brief Use dedicated implementation, because it requires usage of C++ helper functions from
 *  customer side.
 *  Copyright (C) 2017 emsys Embedded Systems GmbH
 **/

#include "emcpp/system/intel/audio/xtos/adsp_platform_defs_fwd.h"
#include "emcpp/system/intel/audio/xtos/common_defs_fwd.h"
#include "emc/std/stdint.h"
#include "emc/std/ext/timestamp.h"
#include "emc/std/limits.h"

#define EMC_TIMESTAMP_TICKS_PER_SECOND GET_VALUE(WALLCLOCK_FREQUENCY)
#define EMC_TIMESTAMP_WRAP -1 /* EMC_STD_U_LONG_LONG_MAX or 0xffffffffffffffffULL */

timestamp_t emc_timestamp(void)
{
  emc_std_uint64_t* wc_register = (emc_std_uint64_t*)DSP_WC_COUNTER_BA;
  return *wc_register;
}

timestamp_t emc_timestamp_ticks_per_second(void)
{
  return EMC_TIMESTAMP_TICKS_PER_SECOND;
}

timestamp_t emc_timestamp_wrap(void)
{
  return EMC_TIMESTAMP_WRAP;
}

timestamp_t emc_timestamp_to_seconds(timestamp_t difference)
{
  return difference / EMC_TIMESTAMP_TICKS_PER_SECOND;
}

timestamp_t emc_timestamp_to_milliseconds(timestamp_t difference)
{
  return (1000 * difference) / EMC_TIMESTAMP_TICKS_PER_SECOND;
}

timestamp_t emc_timestamp_to_microseconds(timestamp_t difference)
{
  return (1000000 * difference) / EMC_TIMESTAMP_TICKS_PER_SECOND;
}

timestamp_t emc_timestamp_difference(timestamp_t subtrahend, timestamp_t minuend)
{
  return subtrahend - minuend;
}
