/* Copyright (C) 2019 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EXT_PRIVATE_timestamp_embos_H
#define EMC_STD_EXT_PRIVATE_timestamp_embos_H

#include "external/embos/rtos.h"

#define EMC_TIMESTAMP_TICKS_PER_SECOND (1000000LL)
#define EMC_TIMESTAMP_TICKS_PER_MILLISECOND (1000LL)
#define EMC_TIMESTAMP_WRAP (0xFFFFFFFFULL)

/** Return a system tick count with a resolution of @emc_timestamp_ticks_per_second() */
static inline timestamp_t emc_timestamp(void)
{
  return (timestamp_t)OS_TIME_Getus64();
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
  return (timestamp_t)(difference / EMC_TIMESTAMP_TICKS_PER_SECOND);
}

/** Calculates the time in milliseconds from a time difference */
static inline timestamp_t emc_timestamp_to_milliseconds(timestamp_t difference)
{
  return difference / EMC_TIMESTAMP_TICKS_PER_MILLISECOND;
}

/** Calculates the time in microseconds from a time difference */
static inline timestamp_t emc_timestamp_to_microseconds(timestamp_t difference)
{
  return difference;
}

static inline timestamp_t emc_timestamp_difference(timestamp_t subtrahend, timestamp_t minuend)
{
  return subtrahend - minuend;
}

#endif /* #ifndef EMC_STD_EXT_PRIVATE_timestamp_embos_H */
