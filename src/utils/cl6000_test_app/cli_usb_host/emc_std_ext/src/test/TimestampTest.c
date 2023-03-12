/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#include "emc/std/ext/timestamp.h"
#include "emc/std/assert.h"
#include "emc/std/signal.h"
#include "emc/std/stdlib.h"
#include "emc/std/string.h"

static void test_timestamp(void)
{
  timestamp_t ts1, ts2, dt;
  ts1 = emc_timestamp();
  ts2 = emc_timestamp();
  dt = emc_timestamp_difference(ts2, ts1);
  emc_std_assert(0 <= dt);

  ts2 = ts1 - 1;
  emc_std_assert(emc_timestamp_difference(ts1, ts1) == 0);
  emc_std_assert(emc_timestamp_difference(ts2, ts1) == emc_timestamp_wrap());
  emc_std_assert(emc_timestamp_difference(ts1, ts2) == 1);

  dt = emc_timestamp_ticks_per_second();
  emc_std_assert(emc_timestamp_to_seconds(dt) == 1);
  emc_std_assert(emc_timestamp_to_milliseconds(dt) == 1000);
  emc_std_assert(emc_timestamp_to_microseconds(dt) == 1000000);

  emc_std_assert(dt = emc_timestamp_ms_to_ticks(1000));
  emc_std_assert(dt = emc_timestamp_us_to_ticks(10000000));
}

static void fail(int sig) { UNUSED_PARAM(sig); emc_std_exit(-1); }

int main(int argc, char* argv[])
{
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  emc_std_signal(EMC_STD_SIGABRT, fail);
  test_timestamp();
  return 0;
}
