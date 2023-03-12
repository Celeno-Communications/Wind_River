/* Copyright (C) 2020 emsys Embedded Systems GmbH */

#pragma once

#include "emc/std/limits.h"

/* The required functions to fulfill the api have to be provided in a project specific module
 *
 */

/** Return a system tick count with a resolution of @emc_timestamp_ticks_per_second() */
timestamp_t emc_timestamp(void);

/** Return the ticks per second of the system abstracted function @emc_timestamp() */
timestamp_t emc_timestamp_ticks_per_second(void);

/** Return the maximum value that is returned by @emc_timestamp() */
timestamp_t emc_timestamp_wrap(void);

/** setup the timer hardware */
void emc_timestamp_init(void);

/** Calculates the time in seconds from a time difference */
static inline timestamp_t emc_timestamp_to_seconds(timestamp_t difference)
{
  return difference / emc_timestamp_ticks_per_second();
}

/** Calculates the time in milliseconds from a time difference */
static inline timestamp_t emc_timestamp_to_milliseconds(timestamp_t difference)
{
  return (1000 * difference) / emc_timestamp_ticks_per_second();
}

/** Calculates the time in microseconds from a time difference */
static inline timestamp_t emc_timestamp_to_microseconds(timestamp_t difference)
{
  return (1000000 * difference) / emc_timestamp_ticks_per_second();
}

/** calculates the difference between two time stamps and considers the wrap of the
 *  tick count of the system
 */
static inline timestamp_t emc_timestamp_difference(timestamp_t minuend, timestamp_t subtrahend)
{
  if (minuend >= subtrahend) {
    return minuend - subtrahend;
  } else {
    return minuend + (emc_timestamp_wrap() - subtrahend);
  }
}
