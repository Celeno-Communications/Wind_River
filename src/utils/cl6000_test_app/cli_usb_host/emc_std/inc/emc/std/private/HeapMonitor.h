/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_PRIVATE_HeapMonitor_H
#define EMC_STD_PRIVATE_HeapMonitor_H

#include "emc/std/stdbool.h"
#include "emc/std/stdint.h"

typedef unsigned (* EmcHeapTimeFunction)(void);

struct EmcHeapRequest {
  char*    address; /* the pointer */
  unsigned size;    /* requested size in bytes */
  unsigned id;      /* unique number of this memory request */
  unsigned time;    /* usually the latest logging system's message id */
};

struct EmcHeapMonitor {
  struct EmcHeapRequest* begin, * begin_free, * end;
  unsigned               next_request_id;
  emc_std_intptr_t       max_request_index;
  emc_std_bool           did_overrun;
  EmcHeapTimeFunction    time_function;
};

void emc_heap_monitor_init(struct EmcHeapMonitor* self,
                           struct EmcHeapRequest* begin,
                           struct EmcHeapRequest* end,
                           EmcHeapTimeFunction func);

void emc_heap_monitor_alloc(struct EmcHeapMonitor* self,
                            void* address,
                            unsigned size);

/** Return the size of the freed chunk or 0 on error */
unsigned emc_heap_monitor_free(struct EmcHeapMonitor* self, void* address);

#endif /* EMC_STD_PRIVATE_HeapMonitor_H */
