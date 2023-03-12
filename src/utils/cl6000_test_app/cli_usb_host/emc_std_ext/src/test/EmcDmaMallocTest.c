/* Copyright (C) 2018 emsys Embedded Systems GmbH */

#include "emc/std/stdlib.h"
#include "emc/std/ext/dma_malloc.h"
#include "emc/std/stdbool.h"
#include "emc/test/SimpleTest.h"

#include <stdio.h>

typedef int EmcDmaMallocTest;

static int setUp(EmcDmaMallocTest* context) { UNUSED_PARAM(context); return 1; }

static int tearDown(EmcDmaMallocTest* context) { UNUSED_PARAM(context); return 1; }

static int cover_dma_malloc_init(EmcDmaMallocTest* context)
{
  unsigned char  buffer[1024];
  emc_std_size_t size = sizeof(buffer);

  emc_std_dma_malloc_init(buffer, size);

  UNUSED_PARAM(context);
  return 1;
}

static int test_dma_malloc_cache_line_size(EmcDmaMallocTest* context)
{
  emc_std_size_t size = 0;
  emc_std_size_t new_size = 1024;
  emc_std_size_t initial_size = emc_dma_cache_line_size();

  UNUSED_PARAM(context);

  emc_set_dma_cache_line_size(new_size);
  size = emc_dma_cache_line_size();
  if (initial_size == 0) {
    if (size != 0) {
      return 0;
    }
  } else {
    if (size == 0) {
      return 0;
    }
  }
  return 1;
}

static int test_dma_malloc_and_free(EmcDmaMallocTest* context)
{
  emc_std_size_t new_size = 16 * 1024;

  void* ptr = 0;

  UNUSED_PARAM(context);

  ptr = emc_dma_malloc(new_size);
  if (!ptr) {
    return 0;
  }
  emc_dma_free(ptr);
  return 1;
}

int main(int argc, char* argv[])
{
  int fail_count = 0;

  UNUSED_PARAM(argc); UNUSED_PARAM(argv);

  EMC_SIMPLE_TEST(EmcDmaMallocTest, test_dma_malloc_cache_line_size);
  EMC_SIMPLE_TEST(EmcDmaMallocTest, test_dma_malloc_and_free);
  EMC_SIMPLE_TEST(EmcDmaMallocTest, cover_dma_malloc_init);

  return fail_count;
}
