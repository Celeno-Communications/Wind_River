/** @file
    @brief Functions for finding memory leaks.
    Copyright (C) 2004-2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_PRIVATE_malloc_debug_H
#define EMC_STD_PRIVATE_malloc_debug_H

#include "emc/std/stdbool.h"

#include "emc/std/private/HeapSummary.h"

EMC_EXTERN_C_BEGIN;

#if EMC_STD_MALLOC_HEAP_TRACE_SIZE

void emc_malloc_debug_init(unsigned (* time_function)(void));
void emc_malloc_debug_alloc(void* address, unsigned size);
void emc_malloc_debug_free(void* address);
void emc_malloc_debug_break_relative(unsigned delta_count);
void emc_malloc_debug_report(void);
emc_std_bool emc_malloc_debug_summary(struct EmcHeapSummary* out_summary,
                                      unsigned* out_timestamp);
void emc_malloc_debug_log_tracepoint(unsigned id);

#else /* !EMC_STD_MALLOC_HEAP_TRACE_SIZE */

#  define emc_malloc_debug_init(tf) do { UNUSED_PARAM(tf); } while (0)
#  define emc_malloc_debug_alloc(a, s) do { UNUSED_PARAM(a); UNUSED_PARAM(s); } while (0)
#  define emc_malloc_debug_free(a) do { UNUSED_PARAM(a); } while (0)
#  define emc_malloc_debug_break_relative(d) do { UNUSED_PARAM(d); } while (0)
#  define emc_malloc_debug_report() do {} while (0)
#  define emc_malloc_debug_summary(os, ot) (UNUSED_PARAM(ot), UNUSED_PARAM(od), 0)
#  define emc_malloc_debug_log_tracepoint(id)  (UNUSED_PARAM(id))

#endif /* !EMC_STD_MALLOC_HEAP_TRACE_SIZE */

EMC_EXTERN_C_END;

#endif /* EMC_STD_PRIVATE_malloc_debug_H */
