/**
 * @file
 * @author  Ralf Oberländer <ralf.oberlaender@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 */

#ifndef EMC_SYSTEM_CELENO_configure_H
#define EMC_SYSTEM_CELENO_configure_H

#ifdef HAVE_CMAKE_CONFIGURE
#  include "emcpp_system_celeno_wifi/cmakeConfigure.h"
#endif

#include "emc/config/configure.h"

#if EMC_USB_VENDOR_CELENO_UMAC_APP_BUILD_ID >= 0x80
#  define CELENO_APP_BUILD_TYPE "debug"
#else
#  define CELENO_APP_BUILD_TYPE "release"
#endif

#ifndef CELENO_APP_VERSION_AS_STRING
#  define CELENO_APP_VERSION_AS_STRING \
  EMC_USB_VENDOR_CELENO_UMAC_APP "-app (ID " EMC_STRINGIZE(EMC_USB_VENDOR_CELENO_UMAC_APP_ID) ") " \
  "V" EMC_STRINGIZE(EMC_USB_VENDOR_CELENO_UMAC_APP_VERSION) "." EMC_STRINGIZE(EMC_USB_VENDOR_CELENO_UMAC_APP_BUILD_ID) \
  " (" CELENO_APP_BUILD_TYPE " build) " __DATE__ " " __TIME__
#endif

#ifndef CELENO_APP_VERSION_AS_INT
#  define CELENO_APP_VERSION_AS_INT \
  ((EMC_USB_VENDOR_CELENO_UMAC_APP_VERSION << 16) \
   | (EMC_USB_VENDOR_CELENO_UMAC_APP_ID << 8) \
   | EMC_USB_VENDOR_CELENO_UMAC_APP_BUILD_ID)
#endif

#define EMC_USB_VENDOR_CELENO_APP_IS_WIFI (EMC_USB_VENDOR_CELENO_UMAC_APP_ID == 2)
#define EMC_USB_VENDOR_CELENO_APP_IS_WIFI_FREERTOS (EMC_USB_VENDOR_CELENO_UMAC_APP_ID == 5)
#define EMC_USB_VENDOR_CELENO_APP_IS_OFFLOAD (EMC_USB_VENDOR_CELENO_UMAC_APP_ID == 4)
#define EMC_USB_VENDOR_CELENO_APP_IS_THROUGHPUT (EMC_USB_VENDOR_CELENO_UMAC_APP_ID == 3)
#define EMC_USB_VENDOR_CELENO_APP_IS_PCIE (EMC_USB_VENDOR_CELENO_UMAC_APP_ID == 6)

#ifdef __XTENSA__
#  define REG_MACSYS_GCU_BASE_ADDR (0x607C5000)
#  define MACSYS_GCU_UMAC_INT_MAP_2_ADDR (REG_MACSYS_GCU_BASE_ADDR + 0x0000019C)
#endif

#ifndef __XTENSA__
#  define EMC_USB_VENDOR_CELENO_TARGET_DRAM_MEMORY_SIZE (192 * 1024)
#  define EMC_USB_VENDOR_CELENO_TARGET_DRAM_MEMORY_ADDR (0x40000000)
#  define EMC_USB_VENDOR_CELENO_TARGET_IRAM_MEMORY_SIZE (128 * 1024)
#  define EMC_USB_VENDOR_CELENO_TARGET_IRAM_MEMORY_ADDR (0x40080000)
#  define EMC_USB_VENDOR_CELENO_TARGET_SRAM_MEMORY_SIZE (128 * 1024)
#  define EMC_USB_VENDOR_CELENO_TARGET_SRAM_MEMORY_ADDR (0x60000000)
#endif

#define UMAC_WRAPPER_TEST_CONTROL_BASE 0x60001000
#define UMAC_WRAPPER_TEST_STATUS_BASE 0x60001800

#define CELENO_ECM_NOTIFICATION_EP 0x82
#define CELENO_ECM_DATA_IN_EP 0x83
#define CELENO_ECM_DATA_OUT_EP 0x03

enum InterfaceNumbers {
  CELENO_CLI_IFC_NUM = 0
#if EMC_USB_VENDOR_CELENO_HAS_WIFI_FUNCTION
  , CELENO_WIFI_IFC_NUM
#endif
#if EMC_USB_VENDOR_CELENO_HAS_ECM_FUNCTION
  , CELENO_ECM_COMM_IFC_NUM,
  CELENO_ECM_DATA_IFC_NUM
#endif
  , CELENO_BT_IFC_NUM
};

/** In Endpoint address (tx) used for Bluetooth events
   @ingroup emdoc_emc_usb_vendor_celeno_wifi_Defines
   @showinitializer
 */
#if defined(__XTENSA__) || EMC_TEST
#  define CELENO_BT_EP_IN_EVT 0x87
#else
#  define CELENO_BT_EP_IN_EVT 0x85
#endif

/** In Endpoint address (tx) used for Bluetooth ACL data
   @ingroup emdoc_emc_usb_vendor_celeno_wifi_Defines
   @showinitializer
 */
#if defined(__XTENSA__) || EMC_TEST
#  define CELENO_BT_EP_IN_ACL 0x88
#else
#  define CELENO_BT_EP_IN_ACL 0x86
#endif

/** In Endpoint address (tx) used for Bluetooth SCO (iso) data
   @ingroup emdoc_emc_usb_vendor_celeno_wifi_Defines
   @showinitializer
 */
#if defined(__XTENSA__) || EMC_TEST
#  define CELENO_BT_EP_IN_SCO 0x89
#else
#  define CELENO_BT_EP_IN_SCO 0x87
#endif

/** Out Endpoint address (rx) used for BLUETOOTH ACL data
   @ingroup emdoc_emc_usb_vendor_celeno_wifi_Defines
   @showinitializer
 */
#if defined(__XTENSA__) || EMC_TEST
#  define CELENO_BT_EP_OUT_ACL 0x0A
#else
#  define CELENO_BT_EP_OUT_ACL 0x06
#endif

/** Out Endpoint address (rx) used for Bluetooth SCO (iso) data
   @ingroup emdoc_emc_usb_vendor_celeno_wifi_Defines
   @showinitializer
 */
#if defined(__XTENSA__) || EMC_TEST
#  define CELENO_BT_EP_OUT_SCO 0x0B
#else
#  define CELENO_BT_EP_OUT_SCO 0x07
#endif

/** The number of isochronous chunks per iso endpoint
   @ingroup emdoc_emc_usb_vendor_celeno_wifi_Defines
   @showinitializer
 */
#define CELENO_BT_ISO_NB_CHUNKS 8

/** The isochronous chunk capacity
   @ingroup emdoc_emc_usb_vendor_celeno_wifi_Defines
   @showinitializer
 */
#define CELENO_BT_ISO_CHUNK_CAPACITY 64U

/** The size of the DMA memory required for the CDC/ECM function, in bytes
   @ingroup emdoc_emc_usb_vendor_celeno_wifi_Defines
   @showinitializer
 */
//#define CELENO_ECM_DMA_MEMORY_SIZE 2048U
#define CELENO_ECM_DMA_MEMORY_SIZE (80 * 1024U)

#endif /* EMC_SYSTEM_CELENO_configure_H */
