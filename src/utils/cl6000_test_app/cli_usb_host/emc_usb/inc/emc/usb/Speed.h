/**
 * @file
 * @brief   Speed
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0\n
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * @ingroup emdoc_emc_usb
 * Copyright (C) 2011-2013, 2020-2021 emsys Embedded Systems GmbH
 *
 ****************************************************************************/

#ifndef EMC_USB_Speed_H
#define EMC_USB_Speed_H

#include "emc/config/configure.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** The USB speed
    @ingroup emdoc_emc_usb
 */
typedef enum EMC_USB_Speed {
  EMC_USB_Speed_UNDEFINED, /**< Device speed undefined */
  EMC_USB_Speed_LOW,       /**< Device runs at USB-Low-speed */
  EMC_USB_Speed_FULL,      /**< Device runs at USB-Full-speed */
  EMC_USB_Speed_HIGH,      /**< Device runs at USB-High-speed */
  EMC_USB_Speed_SUPER,     /**< Device runs at USB-Super-speed */
  EMC_USB_Speed_SUPER_PLUS /**< Device runs at USB-Super-speed plus */
} EMC_USB_Speed;

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif
