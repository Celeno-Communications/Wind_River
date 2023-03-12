/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#include "emc/std/private/HeapChronicle.h"
#include "emc/std/string.h"

void emc_heap_chronicle_init(struct EmcHeapChronicle* self,
                             struct EmcHeapReport* begin,
                             struct EmcHeapReport* end)
{
  self->begin = self->next = begin;
  self->end = end;
  emc_std_memset(self->begin, 0, (emc_std_size_t)((char*)self->end - (char*)self->begin));
}

void emc_heap_chronicle_report(struct EmcHeapChronicle* self,
                               unsigned timestamp,
                               unsigned bytes,
                               unsigned max_bytes)
{
  self->next->timestamp = timestamp;
  self->next->bytes = bytes;
  self->next->max_bytes = max_bytes;
  if (++self->next >= self->end) {
    self->next = self->begin;
  }
}
