/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_PRIVATE_HeapSummary_H
#define EMC_STD_PRIVATE_HeapSummary_H

#include "emc/std/configure.h"
#include "emc/std/stdbool.h"

struct EmcHeapSummary {
  unsigned bytes, max_bytes;
  unsigned chunks, max_chunks;
};

void emc_heap_summary_init(struct EmcHeapSummary* self);
void emc_heap_summary_alloc(struct EmcHeapSummary* self,
                            unsigned size,
                            emc_std_bool error);
void emc_heap_summary_free(struct EmcHeapSummary* self, unsigned size);

#endif /* EMC_STD_PRIVATE_HeapSummary_H */
