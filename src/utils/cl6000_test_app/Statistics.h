/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_VENDOR_CELENO_WIFI_DEVICE_RUNTIME_Statistics_H
#define EMC_USB_VENDOR_CELENO_WIFI_DEVICE_RUNTIME_Statistics_H

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** Version of statistics structure */
#define EMC_USB_CELENO_UMAC_STATISTICS_VERSION 1U

#pragma pack(push)
#pragma pack(1)

/** Generic min/max/average statistics */
typedef struct EMC_USB_CELENO_Statistics_MinMaxAvg_s {
  /** minimum value */
  uint32_t min;
  /** maximum value */
  uint32_t max;
  /** sum of values */
  uint64_t avg_sum;
  /** number of values in sum */
  uint32_t avg_cnt;

} EMC_USB_CELENO_Statistics_MinMaxAvg;

/** Statistics on pDMA handling for a specific LLI channel */
typedef struct EMC_USB_CELENO_Statistics_LLI_s {
  /** number of pDMAs got from USBWrapper */
  uint32_t pdma_get;
  /** number of pDMAs completed with success */
  uint32_t pdma_done;
  /** number of pDMAs completed with error */
  uint32_t pdma_done_error;

  /** number of pDMAs initially queued (before first completion) */
  uint32_t pdma_initial;
  /** pDMA pending time for very first pDMA in ticks */
  uint32_t pdma_pending_initial;

  /** pDMA pending interval statistics in ticks */
  EMC_USB_CELENO_Statistics_MinMaxAvg pdma_pending_range;
  /** pDMA completion count for recent update of minimum pending time*/
  uint32_t pdma_done_pending_min;
  /** pDMA completion count for recent update of maximum pending time*/
  uint32_t pdma_done_pending_max;

} EMC_USB_CELENO_Statistics_LLI;

/** Statistics maintained by UMAC */
typedef struct EMC_USB_CELENO_Statistics_s {
  /**< version marker */
  uint32_t version;
  /**< total size of statistic information in bytes (including version and size field) */
  uint32_t size;

  /**< UL pDMA statistics per LLI */
  EMC_USB_CELENO_Statistics_LLI lli_ul[16];
  /**< DL pDMA statistics per LLI */
  EMC_USB_CELENO_Statistics_LLI lli_dl[16];

} EMC_USB_CELENO_Statistics;

#pragma pack(pop)

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_VENDOR_CELENO_WIFI_DEVICE_RUNTIME_Statistics_H */
