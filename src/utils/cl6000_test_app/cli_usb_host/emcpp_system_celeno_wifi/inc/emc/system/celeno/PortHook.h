/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_SYSTEM_CELENO_PortHook_H
#define EMC_SYSTEM_CELENO_PortHook_H

/** Initialize the port hook with @param base address of the USB controller */
void EMC_USB_CELENO_port_hook_init(emc_std_uintptr_t base_usb);

/** Instruct the port hook not to touch the DWC3 SS PM bits */
void EMC_USB_CELENO_port_hook_disable_ss_pm(void);

/** Instruct the port hook not to touch the DWC3 HS PM bits */
void EMC_USB_CELENO_port_hook_disable_hs_pm(void);

#endif /* EMC_SYSTEM_CELENO_PortHook_H */
