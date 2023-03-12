/** @file
    @brief Configuration values for the Keil C251 C compiler.
    Copyright (C) 2004-2009 emsys Embedded Systems GmbH
 */
#ifndef EMC_CONFIG_COMPILER_cfg_keil251_H
#define EMC_CONFIG_COMPILER_cfg_keil251_H

#include "cfg_keil.h"

#ifndef _WCHAR_T_DEFINED_
#  define _WCHAR_T_DEFINED_
/** Typedef for wide character type */
typedef char wchar_t;
#endif

/* Place all emsys EMC code in dedicated sections */

#pragma userclass (near=sect_usbdata_init)
#pragma userclass (ucode=sect_UsbDriverCode)
#pragma userclass (hconst=sect_UsbDriverConstants)

/* Storage Class assignment.
 * class can be either "near", "data", "xdata", or left empty */

#undef  bool
/** (Re)define bool as byte */
#define bool byte

/** @todo rename to fit into EMC_ "namespace" */
#ifndef INIT_USB_STATICS_MANUAL
#  define INIT_USB_STATICS_MANUAL 1
#endif

#if INIT_USB_STATICS_MANUAL
/** Zero-initialization is postponed until dedicated init function */
#  define EMC_DECL_INIT_ZERO(v) v
#else
/** Zero-initialization is done by compiler */
#  define EMC_DECL_INIT_ZERO(v) v = 0
#endif

#endif /* EMC_CONFIG_COMPILER_cfg_keil251_H */
