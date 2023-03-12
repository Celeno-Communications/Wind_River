/* Copyright (C) 2013 emsys Embedded Systems GmbH */
#include "emc/std/stdatomic.h"
#includ <windows.h>

Rough draft
Not tested at all
Not using..Release, ..Acquire, ..NoFence variants

void emc_std_atomic_thread_fence(emc_std_memory_order order)
{
  UNUSED_PARAM(order);
  MemoryBarrier();
}

void emc_std_atomic_store_explicit(volatile emc_std_atomic_intptr_t* object,
                                   emc_std_intptr_t desired,
                                   emc_std_memory_order order)
{
  UNUSED_PARAM(order);
  InterlockedExchange((LONG volatile*)object->a, desired);
}

emc_std_intptr_t emc_std_atomic_load_explicit(volatile emc_std_atomic_intptr_t* object,
                                              emc_std_memory_order order)
{
  UNUSED_PARAM(order);
  return (emc_std_intptr_t)
         InterlockedExchangeAdd((LONG volatile*)object->a, 0);
}

emc_std_intptr_t emc_std_atomic_exchange_explicit(volatile emc_std_atomic_intptr_t* object,
                                                  emc_std_intptr_t desired,
                                                  emc_std_memory_order order)
{
  UNUSED_PARAM(order);
  return (emc_std_intptr_t)
         InterlockedExchange((LONG volatile*)object->a, desired);
}

emc_std_bool emc_std_atomic_compare_exchange_strong_explicit(volatile emc_std_atomic_intptr_t* object,
                                                             emc_std_intptr_t* expected,
                                                             emc_std_intptr_t desired,
                                                             emc_std_memory_order success,
                                                             emc_std_memory_order failure)
{
  LONG orig = InterlockedCompareExchange((LONG volatile*)object->a, desired, *expected);
  if (orig != *expected) {
    *expected = orig; return 0;
  }
  UNUSED_PARAM(success); UNUSED_PARAM(failure);
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

#define define_emc_std_atomic_fetch_(key, op)                           \
  emc_std_intptr_t                                                       \
  emc_std_atomic_fetch_ ## key ## _explicit(volatile emc_std_atomic_intptr_t * object, \
                                            emc_std_intptr_t operand,    \
                                            emc_std_memory_order order)  \
  {                                                                      \
    UNUSED_PARAM(order);                                                 \
    return _Interlocked ## op ## ((LONG volatile*)object->a, operand);    \
  } extern int emc_macro_requires_semicolon

define_emc_std_atomic_fetch_(add, Add);
define_emc_std_atomic_fetch_(sub, Sub);
define_emc_std_atomic_fetch_(or, Or);
define_emc_std_atomic_fetch_(xor, Xor);
define_emc_std_atomic_fetch_(and, And);
#undef define_emc_std_atomic_fetch_

emc_std_bool emc_std_atomic_flag_test_and_set_explicit(volatile emc_std_atomic_flag* object,
                                                       emc_std_memory_order order)
{
  UNUSED_PARAM(order);
  return InterlockedBitTestAndSet((LONG volatile*)object->a, 0);
}

void emc_std_atomic_flag_clear_explicit(volatile emc_std_atomic_flag* object,
                                        emc_std_memory_order order)
{
  UNUSED_PARAM(order);
  InterlockedBitTestAndReset((LONG volatile*)object->a, 0);
}
