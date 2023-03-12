/** @file
 *  Copyright (C) 2022 emsys Embedded Systems GmbH
 **/

#ifndef EMC_STD_EXT_PRIVATE_timestamp_freertos_H
#define EMC_STD_EXT_PRIVATE_timestamp_freertos_H

#include "external/freertos_kernel/FreeRTOS_wrap.h"
#include "emc/std/stdint.h"

#ifndef portGET_RUN_TIME_COUNTER_VALUE
#  error timestamps requires portGET_RUN_TIME_COUNTER_VALUE be defined.
#endif /* portGET_RUN_TIME_COUNTER_VALUE */

/** To be updated if cpu clock has changed */
void emc_timer_set_tick_cycles_per_second(timestamp_t cycles_s);

/** setup the timer hardware */
void emc_timestamp_init(void);

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

#endif /* EMC_STD_EXT_PRIVATE_timestamp_freertos_H */
