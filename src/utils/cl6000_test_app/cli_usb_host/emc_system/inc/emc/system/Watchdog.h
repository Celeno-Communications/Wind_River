/**
 * @file
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_SYSTEM_Watchdog_H
#define EMC_SYSTEM_Watchdog_H

#include "emc/system/configure.h"
#include "emc/std/stdbool.h"
#include "emc/std/stdint.h"

/// enable the watch dog
void EMC_Watchdog_enable(emc_std_bool enable);

/// configure timeout for watchdog in ms
void EMC_Watchdog_set_timeout(emc_std_uint32_t timeout_ms);

/// send keepalive to watchdog
void EMC_Watchdog_keepalive(void);

/// return time left until watchdog triggers
emc_std_uint32_t EMC_Watchdog_timeleft(void);

/// software watchdog
void EMC_Watchdog_emulation(void);
#endif
