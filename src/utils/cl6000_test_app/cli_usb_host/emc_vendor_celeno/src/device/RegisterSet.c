/**
 * @file
 * @brief
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/system/celeno/configure.h"
#include "emc/std/stdint.h"
#include "emc/vendor/celeno/device/RegisterSet.h"

// DWC3 TRB cache limit - iBuf - link TRB
#if (defined(__XTENSA__) || EMC_TEST)
#  define EMC_CELENO_UMAC_USB_PACKET_TRB_LIMIT (8 - 2)
#else
#  define EMC_CELENO_UMAC_USB_PACKET_TRB_LIMIT (4 - 2)
#endif

EMC_CELENO_UMAC_Registers mg_umac_config_registers = {
  // UMAC_GLOBAL_REGS
  {
    (EMC_CELENO_UMAC_USB_regs_magic << 16) | EMC_CELENO_UMAC_USB_regs_version, // magic and version
    sizeof(EMC_CELENO_UMAC_Registers),                                         // register file size
    EMC_CELENO_UMAC_USB_profile_wifi_bluetooth,                                // usb_profile
#if EMC_USB_VENDOR_CELENO_APP_IS_PCIE
    0 // capabilities
#else
    EMC_CELENO_UMAC_CAPS_HAS_USBWRAPPER // capabilities
#endif
  },
  {
    // US_CONT_U0_REGS
    {
      16,                                          // host_container_count
      1600,                                        // container_size
      50,                                          // idle_time_us
      200,                                         // copy_threshold
      1,                                           // rxv_threshold
      EMC_CELENO_CONT_Capabilities_try_merge_msdu, // capabilities
      0,                                           // reserved
      0                                            // reserved
    },
    // US_CONT_U5_REGS
    {
      16,                                          // host_container_count
      1600,                                        // container_size
      50,                                          // idle_time_us
      200,                                         // copy_threshold
      1,                                           // rxv_threshold
      EMC_CELENO_CONT_Capabilities_try_merge_msdu, // capabilities
      0,                                           // reserved
      0                                            // reserved
    },
  },
  {
    // DS_AGGR_D0_REGS
    {
      16,                                   // host_transfer_packets
      EMC_CELENO_UMAC_USB_PACKET_TRB_LIMIT, // max_pdmas_per_usb_packet
      20,                                   // idle_time_us
      0                                     // capabilities
    },
    // DS_AGGR_D1_REGS
    {
      16,                                   // host_transfer_packets
      EMC_CELENO_UMAC_USB_PACKET_TRB_LIMIT, // max_pdmas_per_usb_packet
      20,                                   // idle_time_us
      0                                     // capabilities
    },
    // DS_AGGR_D2_REGS
    {
      16,                                   // host_transfer_packets
      EMC_CELENO_UMAC_USB_PACKET_TRB_LIMIT, // max_pdmas_per_usb_packet
      20,                                   // idle_time_us
      0                                     // capabilities
    },
    // DS_AGGR_D3_REGS
    {
      16,                                   // host_transfer_packets
      EMC_CELENO_UMAC_USB_PACKET_TRB_LIMIT, // max_pdmas_per_usb_packet
      20,                                   // idle_time_us
      0                                     // capabilities
    },
    // DS_AGGR_BCN_REGS
    {
      16,                                   // host_transfer_packets
      EMC_CELENO_UMAC_USB_PACKET_TRB_LIMIT, // max_pdmas_per_usb_packet
      20,                                   // idle_time_us
      0                                     // capabilities
    },
    // DS_AGGR_HTP_REGS
    {
      16,                                   // host_transfer_packets
      EMC_CELENO_UMAC_USB_PACKET_TRB_LIMIT, // max_pdmas_per_usb_packet
      20,                                   // idle_time_us
      0                                     // capabilities
    },
  },
  // US_LLI_CONFIG
  {
    0, // config for LLIs U0 .. U3
    0, // config for LLIs U4 .. U7
    0, // config for LLIs U8 .. U11
    0  // config for LLIs U12 .. U15
  },
  // DS_LLI_CONFIG
  {
    0, // config for LLIs D0 .. D3
    0, // config for LLIs D4 .. D7
    0, // config for LLIs D8 .. D11
    0  // config for LLIs D12 .. D15
  }
};
