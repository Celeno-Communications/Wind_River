/**
 * @file
 * @brief
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/vendor/celeno/device/Idma.h"
#include "emc/std/ext/memcpy.h"

void CELENO_IDMA_memcpy_start(CELENO_IDMA_CHANNEL channel, void* dst, const void* src, emc_std_size_t n)
{
  UNUSED_PARAM(channel);
  emc_std_ext_memcpy(dst, src, n);
}

void CELENO_IDMA_memcpy_complete(CELENO_IDMA_CHANNEL channel)
{
  UNUSED_PARAM(channel);
}

void CELENO_IDMA_memcpy(CELENO_IDMA_CHANNEL channel, void* dst, const void* src, emc_std_size_t n)
{
  CELENO_IDMA_memcpy_start(channel, dst, src, n);
}
