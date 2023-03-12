/**
 * @file
 * @brief
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/log/internal/lock.h"
#include "emc/test/unittest.h"

void setUp(void)
{}

void tearDown(void)
{}

static int lock_func(void* context)
{
  emc_std_uintptr_t* ctx = (emc_std_uintptr_t*)context;
  ++(*ctx);
  return 0;
}

static int unlock_func(void* context)
{
  emc_std_uintptr_t* ctx = (emc_std_uintptr_t*)context;
  --(*ctx);
  return 0;
}

// clang-format off

EMC_CUNIT_START_TEST(log_lock_test_default)
{
  emc_log_lock_t lock_instance;
  emc_log_lock_t* lock = &lock_instance;
  emc_std_uintptr_t context = 0;

  emc_log_lock_init(lock);
  EMC_CUNIT_ASSERT(0 != lock_instance.lock);
  EMC_CUNIT_ASSERT(0 != lock_instance.unlock);
  EMC_CUNIT_ASSERT(0 == lock_instance.context);

  EMC_CUNIT_ASSERT(0 == lock->lock(lock->context));
  EMC_CUNIT_ASSERT(0 == lock->unlock(lock->context));

  lock_instance.lock = lock_func;
  lock_instance.unlock = unlock_func;
  lock_instance.context = &context;

  EMC_CUNIT_ASSERT(0 == lock->lock(lock->context));
  EMC_CUNIT_ASSERT(1 == context);
  EMC_CUNIT_ASSERT(0 == lock->unlock(lock->context));
  EMC_CUNIT_ASSERT(0 == context);
}
EMC_CUNIT_END_TEST

EMC_CUNIT_TEST_SUITE(log_lock_test);
EMC_CUNIT_TEST(log_lock_test_default);
EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(log_lock_test)

EMC_TEST_SUITE_DEFINE_MAIN()

// clang-format on
