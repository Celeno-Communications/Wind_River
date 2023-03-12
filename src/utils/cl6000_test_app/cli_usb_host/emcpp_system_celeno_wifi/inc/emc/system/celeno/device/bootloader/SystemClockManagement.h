/**
 * @file
 *
 * @author  Ralf Oberländer
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#ifndef EMC_SYSTEM_CELENO_DEVICE_BOOTLOADER_SystemClockManagement_H
#define EMC_SYSTEM_CELENO_DEVICE_BOOTLOADER_SystemClockManagement_H

#include "emc/system/celeno/configure.h"
#include "emc/std/stdint.h"

void system_clock_mng_init();
void system_clock_mng_start();
void system_clock_set_tick_cycles(emc_std_uint32_t cycles_us);

#endif /* EMC_SYSTEM_CELENO_DEVICE_BOOTLOADER_SystemClockManagement_H */
