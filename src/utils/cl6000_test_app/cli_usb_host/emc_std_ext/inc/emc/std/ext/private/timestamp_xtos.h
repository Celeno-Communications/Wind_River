/** @file
 *  @brief Contains only declaration, because implementation requires usage of
 *  C++ helper functions from customer side.
 *  Copyright (C) 2017 emsys Embedded Systems GmbH
 **/

#ifndef EMC_STD_EXT_PRIVATE_timestamp_xtos_H
#define EMC_STD_EXT_PRIVATE_timestamp_xtos_H

/** Return a system tick count with a resolution of @emc_timestamp_ticks_per_second() */
timestamp_t emc_timestamp(void);

/** Return the ticks per second of the system abstracted function @emc_timestamp() */
timestamp_t emc_timestamp_ticks_per_second(void);

/** Return the maximum value that is returned by @emc_timestamp() */
timestamp_t emc_timestamp_wrap(void);

/** Calculates the time in seconds from a time difference */
timestamp_t emc_timestamp_to_seconds(timestamp_t difference);

/** Calculates the time in milliseconds from a time difference */
timestamp_t emc_timestamp_to_milliseconds(timestamp_t difference);

/** Calculates the time in microseconds from a time difference */
timestamp_t emc_timestamp_to_microseconds(timestamp_t difference);

/** calculates the difference between two time stamps and considers the wrap of the
 *  tick count of the system
 */
timestamp_t emc_timestamp_difference(timestamp_t subtrahend, timestamp_t minuend);

#endif /* EMC_STD_EXT_PRIVATE_timestamp_xtos_H */
