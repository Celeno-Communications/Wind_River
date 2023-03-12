/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#include "emc/std/private/HeapMonitor.h"

#include "emc/std/assert.h"
#include "emc/std/signal.h"
#include "emc/std/stdlib.h"
#include "emc/std/string.h"

static unsigned mock_time(void) { return 100; }

static void test_heap_monitor_init(void)
{
  struct EmcHeapMonitor mon;
  struct EmcHeapRequest req[2];
  emc_std_memset(&mon, 0xff, sizeof(mon));
  emc_std_memset(req, 0xff, sizeof(req));
  emc_heap_monitor_init(&mon, req, req + 2, mock_time);
  emc_std_assert(req == mon.begin);
  emc_std_assert(req + 2 == mon.end);
  emc_std_assert(1 == mon.next_request_id);
  emc_std_assert(0 == mon.max_request_index);
  emc_std_assert(0 == mon.did_overrun);
  emc_std_assert(mock_time == mon.time_function);
  emc_std_assert(0 == req[0].address && 0 == req[0].size);
  emc_std_assert(0 == req[0].id && 0 == req[0].time);
  emc_std_assert(0 == req[1].address && 0 == req[1].size);
  emc_std_assert(0 == req[1].id && 0 == req[1].time);
}

static void test_heap_monitor_alloc(void)
{
  struct EmcHeapMonitor mon;
  struct EmcHeapRequest req[2];
  emc_heap_monitor_init(&mon, req, req + 2, mock_time);
  emc_heap_monitor_alloc(&mon, req, 10);
  emc_std_assert((void*)req == req[0].address && 10 == req[0].size);
  emc_std_assert(1 == req[0].id && 100 == req[0].time);
  emc_std_assert(0 == mon.max_request_index);
  emc_heap_monitor_alloc(&mon, req + 1, 20);
  emc_std_assert((void*)(req + 1) == req[1].address && 20 == req[1].size);
  emc_std_assert(2 == req[1].id && 100 == req[1].time);
  emc_std_assert(!mon.did_overrun);
  emc_std_assert(3 == mon.next_request_id);
  emc_std_assert(1 == mon.max_request_index);
  emc_heap_monitor_alloc(&mon, &mon, 30);
  emc_std_assert(mon.did_overrun);
}

static void test_heap_monitor_free(void)
{
  struct EmcHeapMonitor mon;
  struct EmcHeapRequest req[2];
  emc_heap_monitor_init(&mon, req, req + 2, mock_time);
  emc_std_assert(0 == emc_heap_monitor_free(&mon, &req + 1));
  emc_heap_monitor_alloc(&mon, &req, 10);
  emc_std_assert(0 == emc_heap_monitor_free(&mon, &req + 1));
  emc_std_assert(10 == emc_heap_monitor_free(&mon, &req));
  emc_std_assert(0 == req[0].address && 0 == req[0].size);
  emc_std_assert(0 == req[0].id && 0 == req[0].time);
}

static void fail(int sig) { UNUSED_PARAM(sig); emc_std_exit(-1); }

int main(int argc, char* argv[])
{
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  emc_std_signal(EMC_STD_SIGABRT, fail);
  test_heap_monitor_init();
  test_heap_monitor_alloc();
  test_heap_monitor_free();
  return 0;
}
