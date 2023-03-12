/**
 * @file
 * @brief
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_VENDOR_CELENO_configure_H
#define EMC_VENDOR_CELENO_configure_H

#include "emc/config/configure.h"

#include "emc_vendor_celeno/cmakeConfigure.h"

#define EMC_VENDOR_CELENO_ASIC_IS_A0 (EMC_VENDOR_CELENO_ASIC_STEPPING == 0x4130)
#define EMC_VENDOR_CELENO_ASIC_IS_B0 (EMC_VENDOR_CELENO_ASIC_STEPPING == 0x4230)

/** Vendor ID
   @ingroup emdoc_emc_usb_vendor_celeno_cli_Defines
   @showinitializer
 */
#define CELENO_VENDOR_ID 0x33DE

/** Product ID
   @ingroup emdoc_emc_usb_vendor_celeno_cli_Defines
   @showinitializer
 */
#define CELENO_PRODUCT_ID 0x6000

/** Version number, BCD-encoded (e.g., 0x1234 -> "12.3.4")
   @ingroup emdoc_emc_usb_vendor_celeno_cli_Defines
   @showinitializer
 */
#define CELENO_DEVICE_VERSION 0x0001

#endif /* EMC_VENDOR_CELENO_configure_H */
