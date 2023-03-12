/* Copyright (C) 2013 emsys Embedded Systems GmbH */
#include "emc/std/private/malloc_debug.h"

#include "emc/std/private/HeapBreakpoint.h"
#include "emc/std/private/HeapChronicle.h"
#include "emc/std/private/HeapChunkStatistics.h"
#include "emc/std/private/HeapMonitor.h"
#include "emc/std/private/HeapSummary.h"
#include "emc/std/private/HeapTrace.h"

#include "emc/std/assert.h"
#include "emc/std/stdatomic.h"
#include "emc/std/stddef.h"
#include "emc/std/threads.h"

/* ensure that this file can also be compiled if EMC_STD_MALLOC_HEAP_TRACE_SIZE==0 (dist) */
#if EMC_STD_MALLOC_HEAP_TRACE_SIZE

EMC_DEFINE_LOCK_AND_UNLOCK_MG_(mtx);

struct EmcMallocTracePoints {
  unsigned next_request_id;
  unsigned id;
};

static struct EmcMallocDebugGlobals {
  struct EmcHeapSummary         summary;
  struct EmcHeapRequest         request[EMC_STD_MALLOC_HEAP_TRACE_SIZE];
  struct EmcHeapChunkGroup      chunk_group[16];
  struct EmcHeapReport          report[EMC_HEAP_TRACE_USAGE_SIZE];
  struct EmcHeapMonitor         monitor;
  struct EmcHeapChunkStatistics statistics;
  struct EmcHeapChronicle       chronicle;
  struct EmcHeapBreakpoint      breakpoint;
  struct EmcHeapTraceEntry      entries[EMC_STD_MALLOC_HEAP_TRACE_SIZE];
  struct EmcHeapTrace           trace;
  emc_std_uint8_t               trace_index;
  struct EmcMallocTracePoints   tracepoints[256];
} emc_malloc_debug_globals, * mg;

#  define end(ary) (ary + (sizeof((ary)) / sizeof((ary)[0])))
void emc_malloc_debug_init(EmcHeapTimeFunction tf)
{
  if (!lock_mg_mtx()) {
    return;
  }
  if (!mg) {
    mg = &emc_malloc_debug_globals;
    emc_heap_breakpoint_init(&mg->breakpoint);
    emc_heap_chronicle_init(&mg->chronicle, mg->report, end(mg->report));
    emc_heap_chunk_statistics_init(&mg->statistics, mg->chunk_group, end(mg->chunk_group));
    emc_heap_monitor_init(&mg->monitor, mg->request, end(mg->request), tf);
    emc_heap_summary_init(&mg->summary);
    emc_heap_trace_init(&mg->trace, mg->entries, end(mg->entries));
    mg->trace_index = 0;
  }
  unlock_mg_mtx();
}

#  undef end

void emc_malloc_debug_log_tracepoint(unsigned id)
{
  mg->tracepoints[mg->trace_index].next_request_id = mg->monitor.next_request_id;
  mg->tracepoints[mg->trace_index].id = id;
  mg->trace_index++;

}

void emc_malloc_debug_alloc(void* address, emc_std_size_t size)
{
  if (!lock_mg_mtx()) {
    return;
  }
  emc_heap_monitor_alloc(&mg->monitor, address, size);
  emc_heap_trace_alloc(&mg->trace, address, size);
  emc_heap_breakpoint_alloc(&mg->breakpoint, mg->monitor.did_overrun,
                            mg->monitor.next_request_id - 1, size);
  emc_heap_chunk_statistics_alloc(&mg->statistics, size);
  emc_heap_summary_alloc(&mg->summary, size, mg->monitor.did_overrun);
  unlock_mg_mtx();
}

void emc_malloc_debug_free(void* address)
{
  unsigned size;
  if (!lock_mg_mtx()) {
    return;
  }
  size = emc_heap_monitor_free(&mg->monitor, address);
  emc_heap_summary_free(&mg->summary, size);
  emc_heap_trace_free(&mg->trace, address, size);
  emc_heap_chunk_statistics_free(&mg->statistics, size);
  // TODO remove emc_heap_breakpoint_free(&mg->breakpoint, size);
  unlock_mg_mtx();
}

emc_std_bool emc_malloc_debug_summary(struct EmcHeapSummary* out_summary,
                                      unsigned* out_timestamp)
{
  emc_std_bool success = 0;
  if (!lock_mg_mtx()) {
    return 0;
  }
  *out_summary = mg->summary;
  *out_timestamp = (*mg->monitor.time_function)();
  success = !mg->monitor.did_overrun;
  unlock_mg_mtx();
  return success;
}

void emc_malloc_debug_report(void)
{
  if (!lock_mg_mtx()) {
    return;
  }
  emc_heap_chronicle_report(&mg->chronicle, mg->summary.bytes, mg->summary.max_bytes,
                            (*mg->monitor.time_function)());
  unlock_mg_mtx();
}

void emc_malloc_debug_break_relative(unsigned id)
{
  if (!lock_mg_mtx()) {
    return;
  }
  id += mg->monitor.next_request_id;
  emc_heap_breakpoint_set_request_id(&mg->breakpoint, id);
  unlock_mg_mtx();
}

#endif /* ndef EMC_STD_MALLOC_HEAP_TRACE_SIZE */
