/* Copyright (C) 2016 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EXT_PRIVATE_timestamp_windows_H
#define EMC_STD_EXT_PRIVATE_timestamp_windows_H

#include <windows.h>

#define EMC_TIMESTAMP_TICKS_PER_SECOND 1000ULL
#define EMC_TIMESTAMP_WRAP ((1ULL << 32) - 1)

/** Return a system tick count with a resolution of @emc_timestamp_ticks_per_second() */
static inline timestamp_t emc_timestamp(void)
{
  return (timestamp_t)GetTickCount();
}

/** Return the ticks per second of the system abstracted function @emc_timestamp() */
static inline timestamp_t emc_timestamp_ticks_per_second(void)
{
  return EMC_TIMESTAMP_TICKS_PER_SECOND;
}

/** Return the maximum value that is returned by @emc_timestamp() */
static inline timestamp_t emc_timestamp_wrap(void)
{
  return EMC_TIMESTAMP_WRAP;
}

/** Calculates the time in seconds from a time difference */
static inline timestamp_t emc_timestamp_to_seconds(timestamp_t difference)
{
  return (timestamp_t)(((emc_std_uint32_t)difference) / EMC_TIMESTAMP_TICKS_PER_SECOND);
}

/** Calculates the time in milliseconds from a time difference */
static inline timestamp_t emc_timestamp_to_milliseconds(timestamp_t difference)
{
  return difference;
}

/** Calculates the time in microseconds from a time difference */
static inline timestamp_t emc_timestamp_to_microseconds(timestamp_t difference)
{
  return (timestamp_t)(((emc_std_uint32_t)difference) * 1000);
}

static inline timestamp_t emc_timestamp_difference(timestamp_t subtrahend, timestamp_t minuend)
{
  return (((emc_std_uint32_t)subtrahend) - ((emc_std_uint32_t)minuend)) & EMC_TIMESTAMP_WRAP;
}

#endif /* EMC_STD_EXT_PRIVATE_timestamp_windows_H */
