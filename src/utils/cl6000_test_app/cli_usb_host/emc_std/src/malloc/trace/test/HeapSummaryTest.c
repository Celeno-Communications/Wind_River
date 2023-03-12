/* Copyright (C) 2011, 2012 emsys Embedded Systems GmbH */

#include "emc/std/private/HeapSummary.h"

#include "emc/std/signal.h"
#include "emc/std/stdlib.h"
#include "emc/test/test_assert.h"

static void test_heap_summary_init(void)
{
  struct EmcHeapSummary summary;
  emc_heap_summary_init(&summary);
  EMC_TEST_ASSERT(0 == summary.bytes);
  EMC_TEST_ASSERT(0 == summary.max_bytes);
  EMC_TEST_ASSERT(0 == summary.chunks);
  EMC_TEST_ASSERT(0 == summary.max_chunks);
}

static void test_heap_summary_alloc(void)
{
  emc_std_bool          overflow = 1;
  struct EmcHeapSummary summary;
  emc_heap_summary_init(&summary);
  emc_heap_summary_alloc(&summary, 123, !overflow);
  EMC_TEST_ASSERT(123 == summary.bytes);
  EMC_TEST_ASSERT(123 == summary.max_bytes);
  EMC_TEST_ASSERT(1 == summary.chunks);
  EMC_TEST_ASSERT(1 == summary.max_chunks);
  emc_heap_summary_alloc(&summary, 234, !overflow);
  EMC_TEST_ASSERT(357 == summary.bytes);
  EMC_TEST_ASSERT(357 == summary.max_bytes);
  EMC_TEST_ASSERT(2 == summary.chunks);
  EMC_TEST_ASSERT(2 == summary.max_chunks);
  emc_heap_summary_alloc(&summary, 345, overflow);
  EMC_TEST_ASSERT(0 == summary.bytes);
  EMC_TEST_ASSERT(357 == summary.max_bytes);
  EMC_TEST_ASSERT(3 == summary.chunks);
  EMC_TEST_ASSERT(3 == summary.max_chunks);
}

static void test_heap_summary_free(void)
{
  emc_std_bool          overflow = 1;
  struct EmcHeapSummary summary;
  emc_heap_summary_init(&summary);
  emc_heap_summary_alloc(&summary, 123, !overflow);
  emc_heap_summary_alloc(&summary, 234, !overflow);
  emc_heap_summary_free(&summary, 234);
  EMC_TEST_ASSERT(123 == summary.bytes);
  EMC_TEST_ASSERT(357 == summary.max_bytes);
  EMC_TEST_ASSERT(1 == summary.chunks);
  EMC_TEST_ASSERT(2 == summary.max_chunks);
}

static void fail(int sig) { UNUSED_PARAM(sig); emc_std_exit(-1); }

int main(int argc, char* argv[])
{
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  emc_std_signal(EMC_STD_SIGABRT, fail);
  test_heap_summary_init();
  test_heap_summary_alloc();
  test_heap_summary_free();
  return 0;
}
