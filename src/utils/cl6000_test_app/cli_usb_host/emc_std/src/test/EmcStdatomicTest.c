/* Copyright (C) 2011, 2012 emsys Embedded Systems GmbH */

#include "emc/std/stdatomic.h"
#include "emc/std/signal.h"
#include "emc/std/stdlib.h"

#include "emc/test/test_assert.h"

static void test_atomic_init(void)
{
  emc_std_intptr_t value_a = 0;
  emc_std_intptr_t value_b = value_a + 1;
  //emc_std_intptr_t value_c = value_b + 1;

  emc_std_atomic_intptr_t atomic_a;
  emc_std_atomic_intptr_t atomic_b;

  emc_std_atomic_init(&atomic_a, value_a);
  emc_std_atomic_init(&atomic_b, value_b);

  EMC_TEST_ASSERT(value_a == emc_std_atomic_load(&atomic_a));
  EMC_TEST_ASSERT(value_b == emc_std_atomic_load(&atomic_b));
}

static void test_atomic_is_lock_free(void)
{
  emc_std_atomic_intptr_t atomic_a;
  emc_std_bool            ignored_bool;

#if defined EMC_STD_ATOMIC_INT_LOCK_FREE
#  if 0 == EMC_STD_ATOMIC_INT_LOCK_FREE
  EMC_TEST_ASSERT(emc_std_atomic_is_lock_free(&atomic_a));
#  elif 2 == EMC_STD_ATOMIC_INT_LOCK_FREE
  EMC_TEST_ASSERT(emc_std_atomic_is_lock_free(&atomic_a));
#  else // Just check if the getters exist
  EMC_TEST_ASSERT(emc_std_atomic_is_lock_free(&atomic_a));
  ignored_bool = emc_std_atomic_is_lock_free(&atomic_a);
  EMC_TEST_ASSERT(1 == EMC_STD_ATOMIC_INT_LOCK_FREE);
#  endif
#else //!defined(ATOMIC_INT_LOCK_FREE)
  EMC_TEST_ASSERT(0);
#endif //!defined(ATOMIC_INT_LOCK_FREE)
  UNUSED_PARAM(ignored_bool);
}

static void test_atomic_store_and_load(void)
{
  emc_std_intptr_t value_a = 0;
  emc_std_intptr_t value_b = value_a + 1;
  emc_std_intptr_t value_c = value_b + 1;

  emc_std_atomic_intptr_t atomic_a;

  emc_std_atomic_store(&atomic_a, value_b);

  EMC_TEST_ASSERT(value_b == emc_std_atomic_load(&atomic_a));
  EMC_TEST_ASSERT(value_c != emc_std_atomic_load(&atomic_a));

}

static void test_atomic_exchange(void)
{
  emc_std_intptr_t value_a = 0;
  emc_std_intptr_t value_b = value_a + 1;
  emc_std_intptr_t value_c = value_b + 1;

  emc_std_atomic_intptr_t atomic_a;
  emc_std_atomic_init(&atomic_a, value_a);

  value_c = emc_std_atomic_exchange(&atomic_a, value_b);
  EMC_TEST_ASSERT(value_c == value_a);
}

static void test_atomic_compare_exchange_weak(void)
{
  emc_std_intptr_t value_a = 0;
  emc_std_intptr_t value_b = value_a + 1;
  emc_std_intptr_t value_c = value_b + 1;

  emc_std_atomic_intptr_t atomic_a;
  emc_std_atomic_init(&atomic_a, value_a);

  EMC_TEST_ASSERT(!emc_std_atomic_compare_exchange_weak(&atomic_a, &value_c, value_b));
  EMC_TEST_ASSERT(value_c == value_a);
  EMC_TEST_ASSERT(value_a == emc_std_atomic_load(&atomic_a));

  EMC_TEST_ASSERT(emc_std_atomic_compare_exchange_weak(&atomic_a, &value_c, value_b));
  EMC_TEST_ASSERT(value_c == value_a);
  EMC_TEST_ASSERT(value_b == emc_std_atomic_load(&atomic_a));
}

static void test_atomic_fetch_add(void)
{
#if 0
  emc_std_intptr_t value_a = 0;
  emc_std_intptr_t value_b = value_a + 1;
  emc_std_intptr_t value_c = value_b + 1;

  emc_std_atomic_intptr_t atomic_a;
  emc_std_atomic_init(&atomic_a, value_a);

  value_c = emc_std_atomic_fetch_add(&atomic_a, 1);
  EMC_TEST_ASSERT(value_c == value_a);
  EMC_TEST_ASSERT(value_b == emc_std_atomic_load(&atomic_a));
#endif
}

static void fail(int sig) { UNUSED_PARAM(sig); emc_std_exit(-1); }

int main(int argc, char* argv[])
{
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  emc_std_signal(EMC_STD_SIGABRT, fail);
  test_atomic_init();
  test_atomic_is_lock_free();
  test_atomic_store_and_load();
  test_atomic_exchange();
  test_atomic_compare_exchange_weak();
  test_atomic_fetch_add();
  return 0;
}
