/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#include "emc/std/private/HeapBreakpoint.h"

#include "emc/std/signal.h"
#include "emc/std/stdlib.h"

#include "emc/test/test_assert.h"

static void test_heap_breakpoint(void)
{
  int count = emc_heap_breakpoint_count();
  EMC_TEST_ASSERT(count == emc_heap_breakpoint_count());
  emc_heap_breakpoint();
  EMC_TEST_ASSERT(count + 1 == emc_heap_breakpoint_count());
  WRITEONLY_PARAM(count);
}

static void test_heap_breakpoint_init(void)
{
  int                      count = emc_heap_breakpoint_count();
  struct EmcHeapBreakpoint bp;
  emc_heap_breakpoint_init(&bp);
  EMC_TEST_ASSERT(0 == bp.request_id);
  EMC_TEST_ASSERT(0 == bp.alloc_sequence[0]);
  EMC_TEST_ASSERT(count == emc_heap_breakpoint_count());
  WRITEONLY_PARAM(count);
}

static int count_after_alloc(struct EmcHeapBreakpoint* bp,
                             emc_std_bool did_overrun,
                             unsigned id,
                             unsigned size)
{
  emc_heap_breakpoint_alloc(bp, did_overrun, id, size);
  return emc_heap_breakpoint_count();
}

static void test_heap_breakpoint_alloc(void)
{
  int                      count = emc_heap_breakpoint_count();
  unsigned                 id = 0;
  emc_std_bool             ok = 0;
  struct EmcHeapBreakpoint bp;
  emc_heap_breakpoint_init(&bp);

  bp.alloc_sequence[0] = 64;

  EMC_TEST_ASSERT(count == count_after_alloc(&bp, ok, id++, 32));
  emc_heap_breakpoint_set_request_id(&bp, id + 1);
  EMC_TEST_ASSERT(count == count_after_alloc(&bp, ok, id++, 32));
  EMC_TEST_ASSERT(++count == count_after_alloc(&bp, ok, id++, 32));
  EMC_TEST_ASSERT(count == count_after_alloc(&bp, ok, id++, 32));

  ++count;
  EMC_TEST_ASSERT(count == count_after_alloc(&bp, ok, id++, 64));

  bp.alloc_sequence[1] = 64;
  count_after_alloc(&bp, ok, id++, 64); /* optional trigger */
  count = emc_heap_breakpoint_count();
  EMC_TEST_ASSERT(++count == count_after_alloc(&bp, ok, id++, 64));

  bp.alloc_sequence[2] = 128;
  bp.alloc_sequence[3] = 128;
  bp.alloc_sequence[4] = 128;
  EMC_TEST_ASSERT(count == count_after_alloc(&bp, ok, id++, 64)); /* extra */
  EMC_TEST_ASSERT(count == count_after_alloc(&bp, ok, id++, 64));
  EMC_TEST_ASSERT(count == count_after_alloc(&bp, ok, id++, 64));
  EMC_TEST_ASSERT(count == count_after_alloc(&bp, ok, id++, 64));
  EMC_TEST_ASSERT(count == count_after_alloc(&bp, ok, id++, 128));
  EMC_TEST_ASSERT(count == count_after_alloc(&bp, ok, id++, 128));
  EMC_TEST_ASSERT(++count == count_after_alloc(&bp, ok, id++, 128));
  EMC_TEST_ASSERT(count == count_after_alloc(&bp, ok, id++, 128));

  EMC_TEST_ASSERT(++count == count_after_alloc(&bp, !ok, id++, 32));
}

static void test_heap_breakpoint_free(void)
{
  int                      count = emc_heap_breakpoint_count();
  struct EmcHeapBreakpoint bp;
  emc_heap_breakpoint_init(&bp);
  emc_heap_breakpoint_free(&bp, 512);
  EMC_TEST_ASSERT(count == emc_heap_breakpoint_count());
  emc_heap_breakpoint_free(&bp, 0);
  EMC_TEST_ASSERT(++count == emc_heap_breakpoint_count());
  WRITEONLY_PARAM(count);
}

static void fail(int sig) { UNUSED_PARAM(sig); emc_std_exit(-1); }

int main(int argc, char* argv[])
{
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  emc_std_signal(EMC_STD_SIGABRT, fail);
  test_heap_breakpoint();
  test_heap_breakpoint_init();
  test_heap_breakpoint_alloc();
  test_heap_breakpoint_free();
  return 0;
}
