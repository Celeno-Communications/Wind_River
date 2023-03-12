/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#include "emc/std/private/HeapChunkStatistics.h"
#include "emc/std/stdbool.h"

void emc_heap_chunk_statistics_init(struct EmcHeapChunkStatistics* self,
                                    struct EmcHeapChunkGroup* it,
                                    struct EmcHeapChunkGroup* end)
{
  self->begin = it;
  self->end = end;
  for (; it != end; ++it) {
    it->min_size = 1U << (it - self->begin);
    it->max_size = 1U << ((it - self->begin) + 1);
    it->chunks = it->max_chunks = 0;
  }
  self->begin->min_size = 0;
  (self->end - 1)->max_size = ~self->begin->min_size;
}

static void update(int /*emc_std_bool*/ is_alloc,
                   unsigned size,
                   struct EmcHeapChunkGroup* it,
                   struct EmcHeapChunkGroup* end)
{
  for (; it != end; ++it) {
    if ((it->min_size < size) && (size <= it->max_size)) {
      if (is_alloc) {
        ++it->chunks;
      } else {
        --it->chunks;
      }
      if (it->chunks > it->max_chunks) {
        it->max_chunks = it->chunks;
      }
    }
  }
}

void emc_heap_chunk_statistics_alloc(struct EmcHeapChunkStatistics* self, unsigned size)
{
  update(1, size, self->begin, self->end);
}

void emc_heap_chunk_statistics_free(struct EmcHeapChunkStatistics* self, unsigned size)
{
  update(0, size, self->begin, self->end);
}
