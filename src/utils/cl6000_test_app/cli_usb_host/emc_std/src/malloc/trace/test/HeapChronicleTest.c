/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#include "emc/std/private/HeapChronicle.h"

#include "emc/std/assert.h"
#include "emc/std/signal.h"
#include "emc/std/stdlib.h"
#include "emc/std/string.h"

static void test_heap_chronicle_init(void)
{
  struct EmcHeapChronicle hc;
  struct EmcHeapReport    rep[2];
  emc_std_memset(&hc, 0xff, sizeof(hc));
  emc_std_memset(rep, 0xff, sizeof(rep));
  emc_heap_chronicle_init(&hc, rep, rep + 2);
  emc_std_assert(rep == hc.begin);
  emc_std_assert(rep == hc.next);
  emc_std_assert(rep + 2 == hc.end);
  emc_std_assert(0 == rep[0].timestamp);
  emc_std_assert(0 == rep[0].bytes);
  emc_std_assert(0 == rep[0].max_bytes);
  emc_std_assert(0 == rep[1].timestamp);
  emc_std_assert(0 == rep[1].bytes);
  emc_std_assert(0 == rep[1].max_bytes);
}

static void test_heap_chronicle_report(void)
{
  struct EmcHeapChronicle hc;
  struct EmcHeapReport    rep[2];
  emc_heap_chronicle_init(&hc, rep, rep + 2);
  emc_heap_chronicle_report(&hc, 1, 2, 3);
  emc_heap_chronicle_report(&hc, 4, 5, 6);
  emc_std_assert(1 == rep[0].timestamp);
  emc_std_assert(2 == rep[0].bytes);
  emc_std_assert(3 == rep[0].max_bytes);
  emc_std_assert(4 == rep[1].timestamp);
  emc_std_assert(5 == rep[1].bytes);
  emc_std_assert(6 == rep[1].max_bytes);
  emc_heap_chronicle_report(&hc, 7, 8, 9);
  emc_std_assert(7 == rep[0].timestamp);
  emc_std_assert(8 == rep[0].bytes);
  emc_std_assert(9 == rep[0].max_bytes);
}

static void fail(int sig) { UNUSED_PARAM(sig); emc_std_exit(-1); }

int main(int argc, char* argv[])
{
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  emc_std_signal(EMC_STD_SIGABRT, fail);
  test_heap_chronicle_init();
  test_heap_chronicle_report();
  return 0;
}
