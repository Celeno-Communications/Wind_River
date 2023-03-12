/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_PRIVATE_HeapChunkStatistics_H
#define EMC_STD_PRIVATE_HeapChunkStatistics_H

struct EmcHeapChunkGroup {
  unsigned min_size; /* Exclusive */
  unsigned max_size; /* Inclusive */
  unsigned chunks;
  unsigned max_chunks;
};

struct EmcHeapChunkStatistics {
  struct EmcHeapChunkGroup* begin, * end;
};

void emc_heap_chunk_statistics_init(struct EmcHeapChunkStatistics* self,
                                    struct EmcHeapChunkGroup* begin,
                                    struct EmcHeapChunkGroup* end);

void emc_heap_chunk_statistics_alloc(struct EmcHeapChunkStatistics* self,
                                     unsigned size);

void emc_heap_chunk_statistics_free(struct EmcHeapChunkStatistics* self,
                                    unsigned size);

#endif /* EMC_STD_PRIVATE_HeapChunkStatistics_H */
