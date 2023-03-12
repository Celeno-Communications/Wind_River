/**
 * @file
 * @brief
 * @author  <ralf.oberlaender@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/usb/vendor/celeno/cli/device/TargetOperations.h"
#include "emc/std/stdint.h"
#include "emc/std/assert.h"
#include "emc/usb/device/Device.h"

#ifdef __XTENSA__
void EMC_USB_Driver_wait_us(unsigned int microSeconds);
#endif

void EMC_USB_CELENO_CLI_usb_disconnect(uint32_t usb_disconnect_time_ms, uint32_t idle_time_ms)
{
#ifdef __XTENSA__
  EMC_USB_Driver_wait_us(usb_disconnect_time_ms * 1000);
  EMC_USB_Device_set_connect(0);
  EMC_USB_Driver_wait_us(idle_time_ms * 1000);
#else
  (void)usb_disconnect_time_ms;
  (void)idle_time_ms;
#endif
}

void EMC_USB_CELENO_CLI_umac_execute(void* jump_address)
{
#ifdef __XTENSA__
  void (*jump_to)(void) = jump_address;

  (*jump_to)();
#else
  (void)jump_address;
#endif
}
