/**
 * @file
 *
 * @brief   The test of malloc API
 *
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de>
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2012 emsys Embedded Systems GmbH
 *
 ****************************************************************************/

#include <emc/test/SimpleTest.h>
#include "emc/std/stdlib.h"

typedef int EmcStdlibMallocTest;

static int setUp(EmcStdlibMallocTest* context) { UNUSED_PARAM(context); return 1; }

static int tearDown(EmcStdlibMallocTest* context) { UNUSED_PARAM(context); return 1; }

static int test_malloc_free(EmcStdlibMallocTest* context)
{
  void*  ptr = 0;
  size_t size = 0;
  UNUSED_PARAM(context);
  size = 16 * 1024;
  ptr = emc_std_malloc(size);
  if (!ptr) {
    return 0;
  }
  emc_std_free(ptr);
  return 1;
}

int main(int argc, char* argv[])
{
  int fail_count = 0;
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  EMC_SIMPLE_TEST(EmcStdlibMallocTest, test_malloc_free);
  return fail_count;
}
