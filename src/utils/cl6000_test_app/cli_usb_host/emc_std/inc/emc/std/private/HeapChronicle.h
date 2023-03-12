/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_PRIVATE_HeapChronicle_H
#define EMC_STD_PRIVATE_HeapChronicle_H

#include "emc/std/configure.h"

EMC_EXTERN_C_BEGIN;

struct EmcHeapReport {
  unsigned timestamp;
  unsigned bytes;
  unsigned max_bytes;
};

struct EmcHeapChronicle {
  struct EmcHeapReport* begin, * next, * end;
};

void emc_heap_chronicle_init(struct EmcHeapChronicle* self,
                             struct EmcHeapReport* begin,
                             struct EmcHeapReport* end);

void emc_heap_chronicle_report(struct EmcHeapChronicle* self,
                               unsigned timestamp,
                               unsigned bytes,
                               unsigned max_bytes);

EMC_EXTERN_C_END;

#endif /* EMC_STD_PRIVATE_HeapChronicle_H */
