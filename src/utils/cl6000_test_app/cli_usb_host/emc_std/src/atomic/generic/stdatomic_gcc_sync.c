/* Copyright (C) 2013 emsys Embedded Systems GmbH */
#include "emc/std/stdatomic.h"

void emc_std_atomic_thread_fence(emc_std_memory_order order)
{
  UNUSED_PARAM(order);
  __sync_synchronize();
}

void emc_std_atomic_store_explicit(volatile emc_std_atomic_intptr_t* object,
                                   emc_std_intptr_t desired,
                                   emc_std_memory_order order)
{
  if (emc_std_memory_order_relaxed != order) {
    emc_std_atomic_thread_fence(emc_std_memory_order_release);
  }
  __sync_lock_test_and_set(&object->a, desired); /* swap + acquire fence */
}

emc_std_intptr_t emc_std_atomic_load_explicit(volatile emc_std_atomic_intptr_t* object,
                                              emc_std_memory_order order)
{
  UNUSED_PARAM(order);
  return __sync_add_and_fetch(&object->a, 0); /* full barrier */
}

emc_std_intptr_t emc_std_atomic_exchange_explicit(volatile emc_std_atomic_intptr_t* object,
                                                  emc_std_intptr_t desired,
                                                  emc_std_memory_order order)
{
  if ((emc_std_memory_order_relaxed != order) &&
      (emc_std_memory_order_acquire != order) &&
      (emc_std_memory_order_consume != order))
  {
    emc_std_atomic_thread_fence(emc_std_memory_order_release);
  }
  return __sync_lock_test_and_set(&object->a, desired); /* swap + acquire fence */
}

emc_std_bool emc_std_atomic_compare_exchange_strong_explicit(volatile emc_std_atomic_intptr_t* object,
                                                             emc_std_intptr_t* expected,
                                                             emc_std_intptr_t desired,
                                                             emc_std_memory_order success,
                                                             emc_std_memory_order failure)
{
  emc_std_intptr_t actual =
    __sync_val_compare_and_swap(&object->a, *expected, desired); /* full barrier */
  UNUSED_PARAM(success); UNUSED_PARAM(failure);
  if (*expected != actual) {
    *expected = actual; return 0;
  }
  return 1;
}

emc_std_bool emc_std_atomic_compare_exchange_weak_explicit(volatile emc_std_atomic_intptr_t* object,
                                                           emc_std_intptr_t* expected,
                                                           emc_std_intptr_t desired,
                                                           emc_std_memory_order success,
                                                           emc_std_memory_order failure)
{
  return emc_std_atomic_compare_exchange_strong_explicit
           (object, expected, desired, success, failure);
}

#define define_emc_std_atomic_fetch_(key, op)                            \
  emc_std_intptr_t                                                       \
  emc_std_atomic_fetch_ ## key ## _explicit(volatile emc_std_atomic_intptr_t * object, \
                                            emc_std_intptr_t operand,    \
                                            emc_std_memory_order order)  \
  {                                                                      \
    UNUSED_PARAM(order);                                                 \
    return __sync_fetch_and_ ## key(&object->a, operand);                \
  } extern int emc_macro_requires_semicolon
define_emc_std_atomic_fetch_(add, +);
define_emc_std_atomic_fetch_(sub, -);
define_emc_std_atomic_fetch_(or, |);
define_emc_std_atomic_fetch_(xor, ^);
define_emc_std_atomic_fetch_(and, &);
#undef define_emc_std_atomic_fetch_

emc_std_bool emc_std_atomic_flag_test_and_set_explicit(volatile emc_std_atomic_flag* object,
                                                       emc_std_memory_order order)
{
  if ((emc_std_memory_order_relaxed != order) &&
      (emc_std_memory_order_acquire != order))
  {
    emc_std_atomic_thread_fence(emc_std_memory_order_release);
  }
  return __sync_lock_test_and_set(&object->a, 1);
}

void emc_std_atomic_flag_clear_explicit(volatile emc_std_atomic_flag* object,
                                        emc_std_memory_order order)
{
  UNUSED_PARAM(order);
  __sync_lock_release(&object->a);
}
