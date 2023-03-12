/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#include "emc/std/private/HeapSummary.h"

void emc_heap_summary_init(struct EmcHeapSummary* self)
{
  self->bytes = 0;
  self->max_bytes = 0;
  self->chunks = 0;
  self->max_chunks = 0;
}

void emc_heap_summary_alloc(struct EmcHeapSummary* self,
                            unsigned size,
                            emc_std_bool error)
{
  self->bytes = error ? 0 : (self->bytes + size);
  self->chunks = self->chunks + 1;
  if (self->chunks > self->max_chunks) {
    self->max_chunks = self->chunks;
  }
  if (self->bytes > self->max_bytes) {
    self->max_bytes = self->bytes;
  }
}

void emc_heap_summary_free(struct EmcHeapSummary* self, unsigned size)
{
  self->bytes = self->bytes - size;
  self->chunks = self->chunks - 1;
}
