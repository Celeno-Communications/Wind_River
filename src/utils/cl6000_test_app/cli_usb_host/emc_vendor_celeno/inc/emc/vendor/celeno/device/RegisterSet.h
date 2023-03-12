/**
 * @file
 * @brief
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_VENDOR_CELENO_DEVICE_RegisterSet_H
#define EMC_VENDOR_CELENO_DEVICE_RegisterSet_H

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

#pragma pack(push)
#pragma pack(1)

#define EMC_CELENO_UMAC_USB_regs_version 2U   /**< The version of the register file */
#define EMC_CELENO_UMAC_USB_regs_magic 0x524F /**< The magic "RO" */

/** Parameter block for UMAC */
typedef struct EMC_CELENO_UMAC_Param {
  uint32_t magic_version; /**< Register file version information and magic */
  uint32_t file_size;     /**< Register file size in bytes */
  uint32_t usb_profile;   /**< The selected USB profile (one of the EMC_CELENO_UMAC_USB_profile_xxx constants) */
  uint32_t capabilities;  /**< The UMAC/ASIC capabilities (bitwise OR of the EMC_CELENO_UMAC_CAPS_xxx constants) */
} EMC_CELENO_UMAC_Param;

/** Supported UMAC USB profiles */
#define EMC_CELENO_UMAC_USB_profile_wifi_bluetooth 1U /**< publish wifi and bluetooth function */
#define EMC_CELENO_UMAC_USB_profile_wifi_only 2U      /**< publish Wifi function only */
#define EMC_CELENO_UMAC_USB_profile_bluetooth_only 3U /**< publish bluetooth function only */

/** Supported UMAC/ASIC capabilities */
#define EMC_CELENO_UMAC_CAPS_HAS_USBWRAPPER 0x00000001U /**< USBWrapper block is available */

/** Parameter block for container mode (CONT) */
typedef struct EMC_CELENO_UPSTREAM_CONT_Param {
  uint32_t host_container_count; /**< The number of containers in a single host transfer */
  uint32_t container_size;       /**< Size of a packet container in bytes */
  uint32_t idle_time_us;         /**< the idle time to complete the USB transfer */
  uint32_t copy_threshold;       /**< Copy payload that is smaller than this value */
  uint32_t rxv_threshold;        /**< Flush intermediate buffer if it contains this number of RXVs */
  uint32_t capabilities;         /**< Capabilities (bitwise OR of EMC_CELENO_CONT_Capabilities_xxx flags) */
  uint32_t reserved_0;           /**< reserved for future use */
  uint32_t reserved_1;           /**< reserved for future use */
} EMC_CELENO_UPSTREAM_CONT_Param;

/** Capability bits for container mode (CONT) */
#define EMC_CELENO_CONT_Capabilities_try_merge_msdu 0x00000001U /**< Merge MSDU's if possible */

/** Parameter block for aggregation mode (AGGR) */
typedef struct EMC_CELENO_DOWNSTREAM_AGGR_Param {
  uint32_t host_transfer_packets;    /**< Number of packets in a single host transfer */
  uint32_t max_pdmas_per_usb_packet; /**< maximum number of pDMAs in a USB packet */
  uint32_t idle_time_us;             /**< the idle time to wait for packets before starting receive */
  uint32_t capabilities;             /**< Capabilities: [0..3] - operating mode (see EMC_CELENO_AGGR_OpMode_XXX) */
} EMC_CELENO_DOWNSTREAM_AGGR_Param;

/** DS_AGGR operating mode */
#define EMC_CELENO_AGGR_OpMode_normal 0x0U              /**< normal mode */
#define EMC_CELENO_AGGR_OpMode_no_xfer_split 0x1U       /**< do not split host transfers at device side */
#define EMC_CELENO_AGGR_OpMode_pad_pdmas 0x2U           /**< pad each pDMA to the next USB MPS */
#define EMC_CELENO_AGGR_OpMode_buffered 0x4U            /**< use intermediate buffer and iDMA for data receive */
#define EMC_CELENO_AGGR_OpMode_plain_idma 0x5U          /**< fill pDMA destination from pDMA source using iDMA copy */
#define EMC_CELENO_AGGR_OpMode_buffered_tci_split 0x6U  /**< buffered mode, copy packets as two parts */
#define EMC_CELENO_AGGR_OpMode_buffered_tci_nonstd 0x7U /**< buffered mode, modify packets to be none-standard */

/** Configuration settings for LLI channels (8 bits per LLI channel)
 * bitwise OR of the EMC_CELENO_LLI_US_CFG_xxx constants for US LLIs
 * bitwise OR of the EMC_CELENO_LLI_DS_CFG_xxx constants for DS LLIs
 * channel order byte by byte from 0, 1..14, 15
 * */
typedef struct EMC_CELENO_LLI_Configuration {
  uint32_t lli_config_0_3;   /**< Configuration of LLI channels 0 .. 3 */
  uint32_t lli_config_4_7;   /**< Configuration of LLI channels 4 .. 7 */
  uint32_t lli_config_8_11;  /**< Configuration of LLI channels 8 .. 11 */
  uint32_t lli_config_12_15; /**< Configuration of LLI channels 12 .. 15 */
} EMC_CELENO_LLI_Configuration;

#define EMC_CELENO_LLI_US_CFG_immediate_completion 0x01U /**< Complete pDMAs immediately */
#define EMC_CELENO_LLI_US_CFG_lmac_interrupt 0x02U       /**< Signal IRQ to LMAC for each completed pDMA */
#define EMC_CELENO_LLI_US_CFG_merge_and_pass 0x04U       /**< Pass buffers as is (no aggregation, merge RXV to data) */

#define EMC_CELENO_LLI_DS_CFG_tci_sw_mode 0x01U    /**< Use TCP Checksum Insertion HW for this LLI */
#define EMC_CELENO_LLI_DS_CFG_lmac_interrupt 0x02U /**< Signal IRQ to LMAC for each completed pDMA */

/** Register Set */
typedef struct EMC_CELENO_UMAC_Registers {
  EMC_CELENO_UMAC_Param            umac_param;         /**< The registers at global (UMAC) level */
  EMC_CELENO_UPSTREAM_CONT_Param   umac_cont_param[2]; /**< The registers for the upstream channels */
  EMC_CELENO_DOWNSTREAM_AGGR_Param umac_aggr_param[6]; /**< The registers for the downstream channels */
  EMC_CELENO_LLI_Configuration     lli_us_config;      /**< The registers for the upstream LLIs */
  EMC_CELENO_LLI_Configuration     lli_ds_config;      /**< The registers for the downstream LLIs */
} EMC_CELENO_UMAC_Registers;

#pragma pack(pop)

extern EMC_CELENO_UMAC_Registers mg_umac_config_registers;

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_VENDOR_CELENO_DEVICE_RegisterSet_H */
