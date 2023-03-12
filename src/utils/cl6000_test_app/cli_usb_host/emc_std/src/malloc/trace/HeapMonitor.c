/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#include "emc/std/private/HeapMonitor.h"
#include "emc/std/private/HeapBreakpoint.h"
#include "emc/std/string.h"

typedef struct EmcHeapRequest* req_ptr;

void emc_heap_monitor_init(struct EmcHeapMonitor* self,
                           req_ptr it,
                           req_ptr end,
                           EmcHeapTimeFunction func)
{
  self->begin = self->begin_free = it;
  self->end = end;
  self->next_request_id = 1;
  self->max_request_index = 0;
  self->did_overrun = 0;
  self->time_function = func;
  emc_std_memset(it, 0, (emc_std_size_t)((char*)end - (char*)it));
}

static req_ptr find_request(req_ptr it, req_ptr end, void* address)
{
  for (; it != end; ++it) {
    if (it->address == address) {
      return it;
    }
  }
  return 0;
}

void emc_heap_monitor_alloc(struct EmcHeapMonitor* self, void* address, unsigned size)
{
  req_ptr request = find_request(self->begin_free, self->end, 0);
  if (request) {
    request->address = address;
    request->size = size;
    request->id = self->next_request_id;
    request->time = (*self->time_function)();
    self->next_request_id = self->next_request_id + 1;
    self->begin_free = request + 1;
    if (request > self->begin + self->max_request_index) {
      self->max_request_index = request - self->begin;
    }
  } else {
    self->did_overrun = 1;
  }
}

unsigned emc_heap_monitor_free(struct EmcHeapMonitor* self, void* address)
{
  req_ptr request = find_request(self->begin, self->end, address);
  if (request) {
    unsigned result = request->size;
    request->address = 0;
    request->size = 0;
    request->id = 0;
    request->time = 0;
    if (self->begin_free > request) {
      self->begin_free = request;
    }
    return result;
  } else {
    if (!self->did_overrun) {
      emc_heap_breakpoint();
    }
    return 0;
  }
}
