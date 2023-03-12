/**
 * @file
 *
 * @author  Guenter Hildebrandt
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#include "emc/system/celeno/device/timer_ext.h"
#include "emc/usb/driver/system/Timer.h"
#include "emc/std/stdint.h"

uint32_t xthal_get_ccount();

void EMC_USB_Driver_wait_us(unsigned int microSeconds)
{
  uint32_t max_wait_time_us = (UINT32_MAX / 2 - 2) / timer_tick_cycles();
  while (microSeconds > 0) {
    uint32_t end_cycle;
    uint32_t wait_time_us = (microSeconds < max_wait_time_us) ? microSeconds : max_wait_time_us;
    microSeconds -= wait_time_us;
    end_cycle = xthal_get_ccount() + (wait_time_us * timer_tick_cycles());
    while ((int32_t)(end_cycle - xthal_get_ccount()) > 0) {}
  }
}
