/* Copyright (C) 2019 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EXT_PRIVATE_timestamp_wdk_H
#define EMC_STD_EXT_PRIVATE_timestamp_wdk_H

#include "emc/std/limits.h"
#include <ntddk.h>

/** Return a system tick count with a resolution of @emc_timestamp_ticks_per_second() */
static inline timestamp_t emc_timestamp(void)
{
  LARGE_INTEGER ts = KeQueryPerformanceCounter(NULL);
  return (timestamp_t)ts.QuadPart;
}

/** Return the ticks per second of the system abstracted function @emc_timestamp() */
static inline timestamp_t emc_timestamp_ticks_per_second(void)
{
  LARGE_INTEGER freq;
  KeQueryPerformanceCounter(&freq);
  return freq.QuadPart;
}

/** Return the maximum value that is returned by @emc_timestamp() */
static inline timestamp_t emc_timestamp_wrap(void)
{
  return LLONG_MAX;
}

/** Calculates the time in seconds from a time difference */
static inline timestamp_t emc_timestamp_to_seconds(timestamp_t difference)
{
  return (timestamp_t)(difference / emc_timestamp_ticks_per_second());
}

/** Calculates the time in milliseconds from a time difference */
static inline timestamp_t emc_timestamp_to_milliseconds(timestamp_t difference)
{
  return (timestamp_t)((difference * 1000) / emc_timestamp_ticks_per_second());
}

/** Calculates the time in microseconds from a time difference */
static inline timestamp_t emc_timestamp_to_microseconds(timestamp_t difference)
{
  return (timestamp_t)((difference * (1000 * 1000)) / emc_timestamp_ticks_per_second());
}

static inline timestamp_t emc_timestamp_difference(timestamp_t subtrahend, timestamp_t minuend)
{
  return ((ULONGLONG)subtrahend - (ULONGLONG)minuend) & emc_timestamp_wrap();
}

#endif /* EMC_STD_EXT_PRIVATE_timestamp_wdk_H */
