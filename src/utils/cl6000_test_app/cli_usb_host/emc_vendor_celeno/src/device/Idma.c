/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#include "emc/vendor/celeno/device/Idma.h"
#include "emc/vendor/celeno/device/IdmaReg.h"
#include "emc/std/assert.h"
#include "emc/std/ext/memcpy.h"
#include "emc/std/ext/timestamp.h"
#include "emc/hw/memory/PhysicalAddress.h"

#define CELENO_IDMA_HANDLE_MISALIGNED 0
#define CELENO_IDMA_HANDLE_TIMEOUT 0

void CELENO_IDMA_memcpy_complete(CELENO_IDMA_CHANNEL channel)
{
#if CELENO_IDMA_HANDLE_TIMEOUT
  timestamp_t start = emc_timestamp();
  while (CELENO_IDMA_request_active(channel)) {
    timestamp_t duration = emc_timestamp_to_microseconds(emc_timestamp_difference(emc_timestamp(), start));
    emc_std_assert(duration < 1000);
    UNUSED_PARAM(duration);
  }
#else
  while (CELENO_IDMA_request_active(channel)) {}
#endif

  CELENO_IDMA_clear(channel);
  emc_std_assert(CELENO_IDMA_axi_any_error(channel) == 0);
}

#if CELENO_IDMA_HANDLE_MISALIGNED
void CELENO_IDMA_memcpy_start(CELENO_IDMA_CHANNEL channel, void* dst, const void* src, emc_std_size_t n)
{
  emc_std_size_t         count;
  const emc_std_uint8_t* src_ptr = src;
  emc_std_uint8_t*       dst_ptr = dst;
  emc_std_uint16_t       size;

  emc_std_assert(n <= 0xffff);

  // different misaligned addresses
  if (((emc_std_uintptr_t)src & 0x03) != ((emc_std_uintptr_t)dst & 0x03)) {
    emc_std_ext_memcpy(dst, src, n);
    return;
  }
  // fix equal misaligned addresses by copy the first bytes
  count = (emc_std_uintptr_t)src & 0x3;
  if (count > 0) {
    count = 4 - count;
    n -= count;
    while (count--) {
      *dst_ptr++ = *src_ptr++;
    }
  }
  // IDMA copy with aligned values
  size = (emc_std_uint16_t)(n & (~0x3));
  if (size) {
    emc_std_assert(!CELENO_IDMA_request_active(channel));
    CELENO_IDMA_source_address(channel, (emc_std_uint32_t)((emc_std_uintptr_t)src_ptr));
    CELENO_IDMA_destination_address(channel, (emc_std_uint32_t)((emc_std_uintptr_t)dst_ptr));
    CELENO_IDMA_info(channel, size);
  }
  // fix remaining bytes
  count = n & 0x3;
  src_ptr += size;
  dst_ptr += size;
  while (count--) {
    *dst_ptr++ = *src_ptr++;
  }
}

#else

void CELENO_IDMA_memcpy_start(CELENO_IDMA_CHANNEL channel, void* dst, const void* src, emc_std_size_t n)
{
  dst = (void*)EMC_PhysicalAddress_new(dst).handle;
  src = (void*)EMC_PhysicalAddress_new((void*)src).handle;
  emc_std_assert(n <= 0xffff);
  emc_std_assert(((emc_std_uintptr_t)src & 0x03) == 0);
  emc_std_assert(((emc_std_uintptr_t)dst & 0x03) == 0);
  emc_std_assert((n & 0x03) == 0);

  emc_std_assert(!CELENO_IDMA_request_active(channel));
  CELENO_IDMA_source_address(channel, (emc_std_uint32_t)((emc_std_uintptr_t)src));
  CELENO_IDMA_destination_address(channel, (emc_std_uint32_t)((emc_std_uintptr_t)dst));
  CELENO_IDMA_info(channel, n);
}

#endif

void CELENO_IDMA_memcpy(CELENO_IDMA_CHANNEL channel, void* dst, const void* src, emc_std_size_t n)
{
  if (n < CELENO_IDMA_COPY_THRESHOLD) {
    emc_std_ext_memcpy(dst, src, n);
  } else {
    CELENO_IDMA_memcpy_start(channel, dst, src, n);
    CELENO_IDMA_memcpy_complete(channel);
  }
}
