/* Copyright (C) 2016 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EXT_PRIVATE_timestamp_null_H
#define EMC_STD_EXT_PRIVATE_timestamp_null_H

#include "emc/std/limits.h"

#define EMC_TIMESTAMP_TICKS_PER_SECOND 1000000
#define EMC_TIMESTAMP_WRAP -1 /* EMC_STD_U_LONG_LONG_MAX or 0xffffffffffffffffULL */

/** setup the timer hardware */
static inline void emc_timestamp_init(void)
{}

/** Return a system tick count with a resolution of @emc_timestamp_ticks_per_second() */
static inline timestamp_t emc_timestamp(void)
{
  static timestamp_t counter;
  return counter++;
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
  return (1000 * difference) / EMC_TIMESTAMP_TICKS_PER_SECOND;
}

/** Calculates the time in microseconds from a time difference */
static inline timestamp_t emc_timestamp_to_microseconds(timestamp_t difference)
{
  return (1000000 * difference) / EMC_TIMESTAMP_TICKS_PER_SECOND;
}

/** calculates the difference between two time stamps and considers the wrap of the
 *  tick count of the system
 */
static inline timestamp_t emc_timestamp_difference(timestamp_t subtrahend, timestamp_t minuend)
{
  return subtrahend - minuend;
}

#endif /* EMC_STD_EXT_PRIVATE_timestamp_null_H */
