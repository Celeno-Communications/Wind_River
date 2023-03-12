/* Copyright (C) 2016 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EXT_PRIVATE_timestamp_uta_H
#define EMC_STD_EXT_PRIVATE_timestamp_uta_H

#include "uta_os.h"

#if EMC_STD_TIMESTAMP_USE_64BIT
/** time measurement on XMM7260, loop with 1000 counts
 *  emc_timestamp() with 32 bit: 1.07us /call
 *  emc_timestamp_to_microseconds(emc_timestamp()) with 32 bit: 1.5us /call
 *  emc_timestamp() with 64 bit: 2.55us /call
 *  emc_timestamp_to_microseconds(emc_timestamp()) with 64 bit: 3.01us /call
 */

#  define EMC_TIMESTAMP_TICKS_PER_SECOND 26000000ULL /* 26 MHz */
#  define EMC_TIMESTAMP_WRAP ((1ULL << 56) - 1)      /* 56 active bits */

/** Return a system tick count with a resolution of @emc_timestamp_ticks_per_second() */
static inline timestamp_t emc_timestamp(void)
{
  return (timestamp_t)UtaOsTimerGetTimestampCounter64bit();
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
  return difference / (EMC_TIMESTAMP_TICKS_PER_SECOND / 1000ULL);
}

/** Calculates the time in microseconds from a time difference */
static inline timestamp_t emc_timestamp_to_microseconds(timestamp_t difference)
{
  return difference / (EMC_TIMESTAMP_TICKS_PER_SECOND / 1000000ULL);
}

static inline timestamp_t emc_timestamp_difference(timestamp_t subtrahend, timestamp_t minuend)
{
  return (subtrahend - minuend) & EMC_TIMESTAMP_WRAP;
}

#else /* !EMC_STD_TIMESTAMP_USE_64BIT */

#  define EMC_TIMESTAMP_TICKS_PER_SECOND 26000000ULL /* 26 MHz */
#  define EMC_TIMESTAMP_WRAP ((1ULL << 32) - 1)      /* 32 active bits */

/** Return a system tick count with a resolution of @emc_timestamp_ticks_per_second() */
static inline timestamp_t emc_timestamp(void)
{
  return (timestamp_t)UtaOsTimerGetTimestampCounter32bit();
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
  return (timestamp_t)(((unsigned int)difference) / EMC_TIMESTAMP_TICKS_PER_SECOND);
}

/** Calculates the time in milliseconds from a time difference */
static inline timestamp_t emc_timestamp_to_milliseconds(timestamp_t difference)
{
  return (timestamp_t)(((unsigned int)difference) / (EMC_TIMESTAMP_TICKS_PER_SECOND / 1000ULL));
}

/** Calculates the time in microseconds from a time difference */
static inline timestamp_t emc_timestamp_to_microseconds(timestamp_t difference)
{
  return (timestamp_t)(((unsigned int)difference) / (EMC_TIMESTAMP_TICKS_PER_SECOND / 1000000ULL));

}

static inline timestamp_t emc_timestamp_difference(timestamp_t subtrahend, timestamp_t minuend)
{
  return (timestamp_t)(((unsigned int)subtrahend) - ((unsigned int)minuend));
}

#endif /* !EMC_STD_TIMESTAMP_USE_64BIT */

#endif /* EMC_STD_EXT_PRIVATE_timestamp_uta_H */
