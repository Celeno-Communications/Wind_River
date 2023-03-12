/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#include "emc/std/private/HeapTrace.h"
#include "emc/std/string.h"

void emc_heap_trace_init(struct EmcHeapTrace* self,
                         struct EmcHeapTraceEntry* begin,
                         struct EmcHeapTraceEntry* end)
{
  self->begin = self->pos = begin;
  self->end = end;
}

static void add_entry(struct EmcHeapTrace* self, void* address, int size)
{
  self->pos->address = address;
  self->pos->size = size;
  if (++(self->pos) >= self->end) {
    self->pos = self->begin;
  }
}

void emc_heap_trace_alloc(struct EmcHeapTrace* self, void* address, unsigned size)
{
  add_entry(self, address, (int)size);
}

void emc_heap_trace_free(struct EmcHeapTrace* self, void* address, unsigned size)
{
  add_entry(self, address, -((int)size));
}
