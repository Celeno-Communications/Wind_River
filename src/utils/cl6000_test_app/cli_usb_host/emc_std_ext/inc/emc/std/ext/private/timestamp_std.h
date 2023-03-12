/* Copyright (C) 2021 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EXT_PRIVATE_timestamp_std_H
#define EMC_STD_EXT_PRIVATE_timestamp_std_H

#include "emc/std/time.h"

#define EMC_TIMESTAMP_TICKS_PER_SECOND 1000000000
#define EMC_TIMESTAMP_WRAP ((timestamp_t)(-1))

/** Return a system tick count with a resolution of @emc_timestamp_ticks_per_second() */
static inline timestamp_t emc_timestamp(void)
{
  struct timespec time;
  timespec_get(&time, TIME_UTC);
  return (timestamp_t)(time.tv_sec) * EMC_TIMESTAMP_TICKS_PER_SECOND + time.tv_nsec;
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
  return difference / EMC_TIMESTAMP_TICKS_PER_SECOND;
}

/** Calculates the time in milliseconds from a time difference */
static inline timestamp_t emc_timestamp_to_milliseconds(timestamp_t difference)
{
  return difference / (EMC_TIMESTAMP_TICKS_PER_SECOND / 1000);
}

/** Calculates the time in microseconds from a time difference */
static inline timestamp_t emc_timestamp_to_microseconds(timestamp_t difference)
{
  return difference / (EMC_TIMESTAMP_TICKS_PER_SECOND / 1000000);
}

/** Calculates the difference between two time stamps and considers the wrap of the
 *  tick count of the system.
 */
static inline timestamp_t emc_timestamp_difference(timestamp_t subtrahend, timestamp_t minuend)
{
  return subtrahend - minuend;
}

#endif /* EMC_STD_EXT_PRIVATE_timestamp_std_H */
