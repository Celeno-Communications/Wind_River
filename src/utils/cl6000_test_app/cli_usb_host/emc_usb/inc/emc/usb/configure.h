/**
 * @file
 * @brief   Setting limitations and information for USB (global, OTG, Device, ..)
 *
 * @author  Stefan Schulze <stefan.schulze@emsys.de> +49-3677-68977-22\n
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2011-2013, 2020 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_configure_H
#define EMC_USB_configure_H

#ifdef HAVE_CMAKE_CONFIGURE
#  include "emc_usb/cmakeConfigure.h"
#endif

#include "emc/config/configure.h"

// FIXME GUARDXREF - Rename switch
#ifndef EMC_USE_NOT_CUSTOMER_CONFIGURE_H
#  include "customer/emc/configure.h"
#endif

/** @defgroup emdoc_emc_usb emc_usb - EMC Universal Serial Bus Library
 *  @ingroup emsys_modules
 *
 * The EMC USB library provides
 * - emc_usb/device
 *   - USB Device
 *   - USB Interface
 *   - USB Endpoint
 *   - USB Message Handling
 * - emc_usb/host
 *   - USB Host
 *   - ...
 * - emc_usb/descriptor
 *   - logical descriptors
 *   - physical descriptors
 *   - DescriptorSet for device
 * - emc_usb/request
 *   - USB request structure
 *   - Request handling
 * - emc_usb/otg
 *   - bus power and connect detection
 *   - SRP, HNP ...
 */

/** @defgroup emdoc_emc_usb_config Configuration of the library
 *  @ingroup emdoc_emc_usb
 */

/** @defgroup emdoc_emc_usb_device Device implementation
 *  @ingroup emdoc_emc_usb
 */

/** @defgroup emdoc_emc_usb_device_hal Device HAL
 *  @ingroup emdoc_emc_usb_device
 */

/** @defgroup global_usb_conf Global USB Configuration Parameters
 *  @ingroup emdoc_emc_usb_config
 */
/*@{*/

/** @name USB Speed Configuration
 *
 * The library can be built at least in two ways:
 * with or without high-speed support
 */
/*@{*/

/** @def EMC_USB_MAX_SPEED
 * The selected USB speed */

#define EMC_USB_LOW_SPEED 1        /**< Build with only low-speed support */
#define EMC_USB_FULL_SPEED 2       /**< Build with only low and full-speed support */
#define EMC_USB_HIGH_SPEED 3       /**< Build with high-speed support */
#define EMC_USB_SUPER_SPEED 4      /**< Build with super-speed support */
#define EMC_USB_SUPER_PLUS_SPEED 5 /**< Build with super-speed plus support */

#ifndef EMC_USB_MAX_SPEED
#  define EMC_USB_MAX_SPEED EMC_USB_HIGH_SPEED
#endif
/*@}*/

/*@}*/

/*@{*/

/** Name of package */
#define EMC_USB_LIBRARY_NAME "emc_usb"

/** Define to the full name and version of this package. */
#define EMC_USB_LIBRARY_DESCRIPTION "EMC USB Stack"

/** The major version of the library. */
#define EMC_USB_LIBRARY_MAJOR_VERSION 3

/** The minor version of the library. */
#define EMC_USB_LIBRARY_MINOR_VERSION 1

/** The micro version of the library. */
#define EMC_USB_LIBRARY_MICRO_VERSION 0

EMC_DECLARE_MODULE(EMC_USB);

/*@}*/

#endif
