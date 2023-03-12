/**
 * @file
 * @brief   the PowerState
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0\n
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * @ingroup emdoc_emc_usb
 * Copyright (C) 2011-2013 emsys Embedded Systems GmbH
 *
 ****************************************************************************/
#ifndef EMC_USB_PowerState_H
#define EMC_USB_PowerState_H

#include "emc/config/configure.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** The USB power */
typedef enum EMC_USB_PowerState {
  EMC_USB_POWERSTATE_U0 = 0,
  EMC_USB_POWERSTATE_U1,
  EMC_USB_POWERSTATE_U2,
  EMC_USB_POWERSTATE_U3
} EMC_USB_PowerState;

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif
