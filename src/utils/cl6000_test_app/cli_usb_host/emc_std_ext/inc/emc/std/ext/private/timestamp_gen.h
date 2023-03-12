/** @file
    @brief OS independent functions for timestsmp abstaction.
     Copyright (C) 2021 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EXT_PRIVATE_timestamp_gen_H
#define EMC_STD_EXT_PRIVATE_timestamp_gen_H

#ifndef EMC_STD_EXT_timestamp_H
#  error "include emc/std/ext/timestamp.h instead of this file"
#endif

/** Calculates the number of ticks for a given time period in ms. */
static inline timestamp_t emc_timestamp_ms_to_ticks(timestamp_t milliseconds)
{
  return (milliseconds * emc_timestamp_ticks_per_second()) / 1000;
}

/** Calculates the number of ticks for a given time period in µs. */
static inline timestamp_t emc_timestamp_us_to_ticks(timestamp_t microseconds)
{
  return (microseconds * emc_timestamp_ticks_per_second()) / 1000000;
}

#endif /* EMC_STD_EXT_PRIVATE_timestamp_gen_H */
