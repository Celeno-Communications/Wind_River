/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#include "emc/std/private/HeapChunkStatistics.h"

#include "emc/std/assert.h"
#include "emc/std/signal.h"
#include "emc/std/stdlib.h"
#include "emc/std/string.h"

static void test_heap_chunk_statistics_init(void)
{
  struct EmcHeapChunkStatistics statistics;
  struct EmcHeapChunkGroup      group[3];
  emc_std_memset(&statistics, 0xff, sizeof(statistics));
  emc_std_memset(group, 0xff, sizeof(group));
  emc_heap_chunk_statistics_init(&statistics, group, group + 3);
  emc_std_assert(group == statistics.begin);
  emc_std_assert(group + 3 == statistics.end);
  emc_std_assert(0 == group[0].min_size);
  emc_std_assert(0 < group[0].max_size);
  emc_std_assert(group[0].max_size == group[1].min_size);
  emc_std_assert(group[1].max_size == group[2].min_size);
  emc_std_assert((~(unsigned)0) == group[2].max_size);
  emc_std_assert(0 == group[0].chunks && 0 == group[0].max_chunks);
  emc_std_assert(0 == group[1].chunks && 0 == group[1].max_chunks);
  emc_std_assert(0 == group[2].chunks && 0 == group[2].max_chunks);
}

static void test_heap_chunk_statistics_alloc(void)
{
  struct EmcHeapChunkStatistics statistics;
  struct EmcHeapChunkGroup      group[3];
  emc_heap_chunk_statistics_init(&statistics, group, group + 3);
  group[0].min_size = 0; group[0].max_size = 10;
  group[1].min_size = 10; group[1].max_size = 20;
  group[2].min_size = 0; group[2].max_size = 30;
  emc_heap_chunk_statistics_alloc(&statistics, 1);
  emc_std_assert(1 == group[0].chunks && 1 == group[0].max_chunks);
  emc_std_assert(0 == group[1].chunks && 0 == group[1].max_chunks);
  emc_std_assert(1 == group[2].chunks && 1 == group[2].max_chunks);
  emc_heap_chunk_statistics_alloc(&statistics, 20);
  emc_std_assert(1 == group[0].chunks && 1 == group[0].max_chunks);
  emc_std_assert(1 == group[1].chunks && 1 == group[1].max_chunks);
  emc_std_assert(2 == group[2].chunks && 2 == group[2].max_chunks);
  emc_heap_chunk_statistics_alloc(&statistics, 31);
  emc_std_assert(1 == group[0].chunks && 1 == group[0].max_chunks);
  emc_std_assert(1 == group[1].chunks && 1 == group[1].max_chunks);
  emc_std_assert(2 == group[2].chunks && 2 == group[2].max_chunks);
  emc_heap_chunk_statistics_alloc(&statistics, 30);
  emc_std_assert(1 == group[0].chunks && 1 == group[0].max_chunks);
  emc_std_assert(1 == group[1].chunks && 1 == group[1].max_chunks);
  emc_std_assert(3 == group[2].chunks && 3 == group[2].max_chunks);
}

static void test_heap_chunk_statistics_free(void)
{
  struct EmcHeapChunkStatistics statistics;
  struct EmcHeapChunkGroup      group[3];
  emc_heap_chunk_statistics_init(&statistics, group, group + 3);
  group[0].min_size = 0; group[0].max_size = 10;
  group[1].min_size = 10; group[1].max_size = 20;
  group[2].min_size = 0; group[2].max_size = 30;
  emc_heap_chunk_statistics_alloc(&statistics, 1);
  emc_heap_chunk_statistics_alloc(&statistics, 20);
  emc_heap_chunk_statistics_alloc(&statistics, 31);
  emc_heap_chunk_statistics_alloc(&statistics, 30);
  emc_heap_chunk_statistics_free(&statistics, 30);
  emc_std_assert(1 == group[0].chunks && 1 == group[0].max_chunks);
  emc_std_assert(1 == group[1].chunks && 1 == group[1].max_chunks);
  emc_std_assert(2 == group[2].chunks && 3 == group[2].max_chunks);
  emc_heap_chunk_statistics_free(&statistics, 31);
  emc_std_assert(1 == group[0].chunks && 1 == group[0].max_chunks);
  emc_std_assert(1 == group[1].chunks && 1 == group[1].max_chunks);
  emc_std_assert(2 == group[2].chunks && 3 == group[2].max_chunks);
  emc_heap_chunk_statistics_free(&statistics, 20);
  emc_std_assert(1 == group[0].chunks && 1 == group[0].max_chunks);
  emc_std_assert(0 == group[1].chunks && 1 == group[1].max_chunks);
  emc_std_assert(1 == group[2].chunks && 3 == group[2].max_chunks);
  emc_heap_chunk_statistics_free(&statistics, 1);
  emc_std_assert(0 == group[0].chunks && 1 == group[0].max_chunks);
  emc_std_assert(0 == group[1].chunks && 1 == group[1].max_chunks);
  emc_std_assert(0 == group[2].chunks && 3 == group[2].max_chunks);
}

static void fail(int sig) { UNUSED_PARAM(sig); emc_std_exit(-1); }

int main(int argc, char* argv[])
{
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  emc_std_signal(EMC_STD_SIGABRT, fail);
  test_heap_chunk_statistics_init();
  test_heap_chunk_statistics_alloc();
  test_heap_chunk_statistics_free();
  return 0;
}
