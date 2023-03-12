/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#include <stddef.h>

#if defined(XGOLD726) || defined(XGOLD716)
#  include "emc/std/emu/comneon_xalloc/xalloc.h"
#else
// todo: create dedicated redirection header to cover pragmas
#  if defined(__arm)
#    pragma diag_suppress 228
#  endif
#  include "usb_malloc_wrapper.h"
#  if defined(__arm)
#    pragma diag_default 228
#  endif
#endif

#include "external/baisoku/tlsf.h"
#include "emc/std/private/malloc_debug.h"
#include "emc/std/ext/dma_malloc.h"

void* emc_dma_malloc(emc_std_size_t size)
{
#if defined(XGOLD726) || defined(XGOLD716)
  void* ptr = ptf_malloc_dma_buffer(size);
#else
  void* ptr = usb_mw_malloc_dma_buffer(size);
#endif
  emc_malloc_debug_alloc(ptr, (unsigned)size);
  return ptr;
}

void emc_dma_free(void* ptr)
{
  if (!ptr) {
    return;
  }
  emc_malloc_debug_free(ptr);
#if defined(XGOLD726) || defined(XGOLD716)
  ptf_free_dma_buffer(ptr);
#else
  usb_mw_free_dma_buffer(ptr);
#endif
}

void emc_set_dma_cache_line_size(emc_std_size_t cache_line_size)
{
  UNUSED_PARAM(cache_line_size);
}

emc_std_size_t emc_dma_cache_line_size()
{
  return 0;
}
