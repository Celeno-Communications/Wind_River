/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#include "emc/std/private/HeapBreakpoint.h"
#include "emc/std/string.h"

static int mg_breakpoint_count;

void emc_heap_breakpoint(void)
{
  ++mg_breakpoint_count;
}

int emc_heap_breakpoint_count(void)
{
  return mg_breakpoint_count;
}

void emc_heap_breakpoint_init(struct EmcHeapBreakpoint* self)
{
  emc_std_memset(self, 0, sizeof(*self));
}

static int sequence_size(struct EmcHeapBreakpoint* self)
{
  int size = 0;
  int max_size = (int)(sizeof(self->alloc_sequence) / sizeof(self->alloc_sequence[0]));
  while (size < max_size && self->alloc_sequence[size]) {
    ++size;
  }
  return size;
}

static void rotate_actual_alloc_sequence(struct EmcHeapBreakpoint* self, int end)
{
  int       pos;
  unsigned* cache = self->actual.alloc_sequence;
  for (pos = 1; pos < end; ++pos) {
    cache[pos - 1] = cache[pos];
  }
}

static emc_std_bool is_size_sequence_equal_to_actual_alloc_sequence(struct EmcHeapBreakpoint* self,
                                                                    int end)
{
  int pos;
  for (pos = 0; pos < end && self->alloc_sequence[pos]; ++pos) {
    if (self->actual.alloc_sequence[pos] != self->alloc_sequence[pos]) {
      return 0;
    }
  }
  return 1;
}

static emc_std_bool is_size_seqence(struct EmcHeapBreakpoint* self, unsigned size)
{
  int seq_size = sequence_size(self);
  if (!seq_size) {
    return 0;
  }
  rotate_actual_alloc_sequence(self, seq_size);
  self->actual.alloc_sequence[seq_size - 1] = size;
  return is_size_sequence_equal_to_actual_alloc_sequence(self, seq_size);
}

void emc_heap_breakpoint_alloc(struct EmcHeapBreakpoint* self,
                               emc_std_bool did_overrun,
                               unsigned request_id,
                               unsigned size)
{
  if (did_overrun || is_size_seqence(self, size) ||
      ((request_id == self->request_id) && request_id))
  {
    emc_heap_breakpoint();
  }
}

void emc_heap_breakpoint_free(struct EmcHeapBreakpoint* self, unsigned size)
{
  UNUSED_PARAM(self);
  if (0 == size) {
    emc_heap_breakpoint();
  }
}
