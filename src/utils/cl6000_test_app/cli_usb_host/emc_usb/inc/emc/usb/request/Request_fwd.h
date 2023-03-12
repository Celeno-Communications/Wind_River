/**
 * @file
 * @brief   Forward declaration for USB_Request structure
 *
 * @author  Maik Otto <maik.otto@emsys.de> +49-3677-68977-0\n
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2011-2013 emsys Embedded Systems GmbH
 ****************************************************************************/

#ifndef EMC_USB_REQUEST_Request_fwd_H
#define EMC_USB_REQUEST_Request_fwd_H

#include "emc/usb/configure.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** Opaque type definition for USB_Request.*/
typedef struct EMC_USB_Request EMC_USB_Request;

/** @{ */

#define EMC_USB_EPX_BORN USB_EPX_BORN
#define EMC_USB_EPX_KILLED USB_EPX_KILLED
#define EMC_USB_EPX_READY USB_EPX_READY
#define EMC_USB_EPX_STALLED USB_EPX_STALLED
#define EMC_USB_EPX_DESTALLED USB_EPX_DESTALLED
#define EMC_USB_EPX_BUSY USB_EPX_BUSY

/** @} */

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif
