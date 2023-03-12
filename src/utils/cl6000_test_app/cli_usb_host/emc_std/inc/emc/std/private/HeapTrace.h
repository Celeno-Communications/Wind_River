/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_PRIVATE_HeapTrace_H
#define EMC_STD_PRIVATE_HeapTrace_H

struct EmcHeapTraceEntry {
  char* address; /* the pointer */
  int   size;    /* requested size in bytes, positive for alloc, negative for free */
};

struct EmcHeapTrace {
  struct EmcHeapTraceEntry* begin, * pos, * end;
};

void emc_heap_trace_init(struct EmcHeapTrace* self,
                         struct EmcHeapTraceEntry* begin,
                         struct EmcHeapTraceEntry* end);

void emc_heap_trace_alloc(struct EmcHeapTrace* self,
                          void* address,
                          unsigned size);

void emc_heap_trace_free(struct EmcHeapTrace* self,
                         void* address,
                         unsigned size);

#endif /* EMC_STD_PRIVATE_HeapTrace_H */
