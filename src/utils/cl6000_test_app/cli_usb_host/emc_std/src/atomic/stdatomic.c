/* Copyright (C) 2013 emsys Embedded Systems GmbH */
#include "emc/std/stdatomic.h"

emc_std_bool emc_std_atomic_is_lock_free(const volatile emc_std_atomic_intptr_t* obj)
{
  UNUSED_PARAM(obj);
  return 1;
}

void emc_std_atomic_init(volatile emc_std_atomic_intptr_t* a, emc_std_intptr_t m)
{
  a->a = m;
}

void emc_std_atomic_store(volatile emc_std_atomic_intptr_t* object,
                          emc_std_intptr_t desired)
{
  emc_std_atomic_store_explicit(object, desired, emc_std_memory_order_seq_cst);
}

emc_std_intptr_t emc_std_atomic_load(volatile emc_std_atomic_intptr_t* object)
{
  return emc_std_atomic_load_explicit(object, emc_std_memory_order_seq_cst);
}

emc_std_intptr_t emc_std_atomic_exchange(volatile emc_std_atomic_intptr_t* object,
                                         emc_std_intptr_t desired)
{
  return emc_std_atomic_exchange_explicit(object, desired, emc_std_memory_order_seq_cst);
}

emc_std_bool emc_std_atomic_compare_exchange_strong(volatile emc_std_atomic_intptr_t* object,
                                                    emc_std_intptr_t* expected,
                                                    emc_std_intptr_t desired)
{
  return emc_std_atomic_compare_exchange_strong_explicit
           (object, expected, desired, emc_std_memory_order_seq_cst, emc_std_memory_order_seq_cst);
}

emc_std_bool emc_std_atomic_compare_exchange_weak(volatile emc_std_atomic_intptr_t* object,
                                                  emc_std_intptr_t* expected,
                                                  emc_std_intptr_t desired)
{
  return emc_std_atomic_compare_exchange_weak_explicit
           (object, expected, desired, emc_std_memory_order_seq_cst, emc_std_memory_order_seq_cst);
}

emc_std_bool emc_std_atomic_flag_test_and_set(volatile emc_std_atomic_flag* object)
{
  return emc_std_atomic_flag_test_and_set_explicit(object, emc_std_memory_order_seq_cst);
}

void emc_std_atomic_flag_clear(volatile emc_std_atomic_flag* object)
{
  emc_std_atomic_flag_clear_explicit(object, emc_std_memory_order_seq_cst);
}
