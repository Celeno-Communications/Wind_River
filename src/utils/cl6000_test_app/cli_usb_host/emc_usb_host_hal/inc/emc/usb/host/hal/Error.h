/**
 * @file
 * @brief   The USB Host HAL Error
 *
 * @author  Stefan Schulze <stefan.schulze@emsys.de> +49-3677-68977 - 22
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * @ingroup emdoc_emct_usb_hal
 *
 * Copyright (C) 2011-2013, 2020 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_HOST_HAL_Error_H
#define EMC_USB_HOST_HAL_Error_H

#include "emc/usb/host/hal/configure.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** USB HAL error
    @ingroup emdoc_emc_usb_host_hal
 */
typedef enum EMC_USB_HOST_HAL_Error {
  EMC_USB_HOST_HAL_Error_NONE                = 0,
  EMC_USB_HOST_HAL_Error_TIMEOUT             = -1,
  EMC_USB_HOST_HAL_Error_INVALID_PARAMETER   = -2,
  EMC_USB_HOST_HAL_Error_INVALID_DEVICE      = -3,
  EMC_USB_HOST_HAL_Error_INVALID_EP          = -4,
  EMC_USB_HOST_HAL_Error_INVALID_BUFFER_SIZE = -5
} EMC_USB_HOST_HAL_Error;

/*@}*/

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_HOST_HAL_Error_H */
