/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_PRIVATE_HeapBreakpoint_H
#define EMC_STD_PRIVATE_HeapBreakpoint_H

#include "emc/std/stdbool.h"

EMC_EXTERN_C_BEGIN;

typedef unsigned EmcHeapSizeSequence[5];

struct EmcHeapBreakpoint {
  /** Break when a request id matches */
  unsigned request_id;
  /** Break when a sequence of block sizes matches */
  EmcHeapSizeSequence alloc_sequence;
  /* SizeSequence free_sequence; */
  /** The actual alloc size sequence is stored internally */
  struct {
    EmcHeapSizeSequence alloc_sequence;
    /* SizeSequence free_sequence; */
  } actual;

};

/** This is called from heap monitor code under configurable circumstances.
    It is suitable for setting breakpoints in a debugger. */
void emc_heap_breakpoint(void);

/** Private interface for unit tests.
    @return an internal value that is modified by emc_heap_debug_break calls.
    @private */
int emc_heap_breakpoint_count(void);

void emc_heap_breakpoint_init(struct EmcHeapBreakpoint* self);

void emc_heap_breakpoint_alloc(struct EmcHeapBreakpoint* self,
                               emc_std_bool did_overrun,
                               unsigned request_id,
                               unsigned size);

void emc_heap_breakpoint_free(struct EmcHeapBreakpoint* self, unsigned size);

static inline void emc_heap_breakpoint_set_request_id(struct EmcHeapBreakpoint* self, unsigned id)
{
  self->request_id = id;
}

EMC_EXTERN_C_END;

#endif /* EMC_STD_PRIVATE_HeapBreakpoint_H */
