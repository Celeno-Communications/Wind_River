#ifndef EMC_SYSTEM_CELENO_DEVICE_timer_ext_H
#define EMC_SYSTEM_CELENO_DEVICE_timer_ext_H

#include "emc/system/celeno/configure.h"
#include "emc/std/stdint.h"

void timer_set_tick_cycles(emc_std_uint32_t cycles_us);

emc_std_uint32_t timer_tick_cycles();

#endif
