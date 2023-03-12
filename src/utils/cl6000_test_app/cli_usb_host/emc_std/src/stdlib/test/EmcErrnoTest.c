/**
 * @file
 *
 * @brief   The test of private errno API
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

typedef int*(* errno_func)(void);

extern void emc_std_internal_set_errno_func(errno_func func);
extern int* emc_std_internal_errno(void);

static int emc_errno_mock_private_errno;

static int* emc_errno_moc(void)
{
  return &emc_errno_mock_private_errno;
}

typedef int EmcErrnoTest;

static int setUp(EmcErrnoTest* context) { UNUSED_PARAM(context); return 1; }

static int tearDown(EmcErrnoTest* context) { UNUSED_PARAM(context); return 1; }

static int test_errno_func(EmcErrnoTest* context)
{
  UNUSED_PARAM(context);
  emc_std_internal_set_errno_func(emc_errno_moc);

  if (&emc_errno_mock_private_errno != emc_std_internal_errno()) {
    return 0;
  }

  return 1;
}

int main(int argc, char* argv[])
{
  int fail_count = 0;
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  EMC_SIMPLE_TEST(EmcErrnoTest, test_errno_func);
  return fail_count;
}
