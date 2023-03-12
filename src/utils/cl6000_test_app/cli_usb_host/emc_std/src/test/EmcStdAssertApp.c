/* Copyright (C) 2021 emsys Embedded Systems GmbH */

#include <emc/std/assert.h>

static void call_failing_assert(void)
{
  int value = 0;
  emc_std_assert(1 == value);
  UNUSED_PARAM(value);
}

int main(int argc, char* argv[])
{
  UNUSED_PARAM(argc);
  UNUSED_PARAM(argv);
  call_failing_assert();
  return 0;
}
