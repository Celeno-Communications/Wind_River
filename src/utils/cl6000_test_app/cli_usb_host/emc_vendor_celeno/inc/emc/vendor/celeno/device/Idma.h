/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_VENDOR_CELENO_DEVICE_Idma_H
#define EMC_VENDOR_CELENO_DEVICE_Idma_H

#include "emc/std/stdint.h"
#include "emc/std/stddef.h"

/** The supported IDMA channels */
typedef enum CELENO_IDMA_CHANNEL {
  CELENO_IDMA_CHANNEL_0,
  CELENO_IDMA_CHANNEL_1,
  CELENO_IDMA_CHANNEL_2,
  CELENO_IDMA_CHANNEL_3,
  CELENO_IDMA_CHANNEL_4,
  CELENO_IDMA_CHANNEL_5
} CELENO_IDMA_CHANNEL;

/**
 * Start a memory transfer with IDMA hardware.
 *
 * The iDMA hardware requires 4 bytes alignment for source, destination and length.
 * The implementation handles also misaligned buffers but may copy parts or all with the CPU.
 * @param channel The channel that is used for the IDMA
 * @param dst The destination address.
 * @param src The source address.
 * @param n The number of bytes to copy
 */
void CELENO_IDMA_memcpy_start(CELENO_IDMA_CHANNEL channel, void* dst, const void* src, emc_std_size_t n);

/** Wait for IDMA memory transfer completion on @param channel, clear status. */
void CELENO_IDMA_memcpy_complete(CELENO_IDMA_CHANNEL channel);

/** when calling CELENO_IDMA_memcpy(): smaller packets will be copied by CPU, larger by IDMA */
#define CELENO_IDMA_COPY_THRESHOLD 32

/** Perform a synchronous memcpy with IDMA hardware (wraps CELENO_IDMA_memcpy_start and CELENO_IDMA_memcpy_complete) */
void CELENO_IDMA_memcpy(CELENO_IDMA_CHANNEL channel, void* dst, const void* src, emc_std_size_t n);

#endif /* EMC_VENDOR_CELENO_DEVICE_Idma_H */
