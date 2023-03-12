/// @file
/// @brief The EMC atomic implementation for WDK
/// @author Guenter Hildebrandt <guenter.hildebrandt@emsys.de>
/// Copyright (C) 2019 emsys Embedded Systems GmbH

#include "external/wdk10/ntddk.h"
#include "emc/std/stdatomic.h"

void emc_std_atomic_thread_fence(emc_std_memory_order order)
{
  UNUSED_PARAM(order);
  KeMemoryBarrier();
}

void emc_std_atomic_store_explicit(volatile emc_std_atomic_intptr_t* object,
                                   emc_std_intptr_t desired,
                                   emc_std_memory_order order)
{
  UNUSED_PARAM(order);
  InterlockedExchangePointer(reinterpret_cast<PVOID volatile*>(&object->a), reinterpret_cast<void*>(desired));
}

emc_std_intptr_t emc_std_atomic_load_explicit(volatile emc_std_atomic_intptr_t* object,
                                              emc_std_memory_order order)
{
  UNUSED_PARAM(order);
  return (emc_std_intptr_t)InterlockedExchangeAdd(reinterpret_cast<LONG volatile*>(&object->a), 0);
}

emc_std_intptr_t emc_std_atomic_exchange_explicit(volatile emc_std_atomic_intptr_t* object,
                                                  emc_std_intptr_t desired,
                                                  emc_std_memory_order order)
{
  UNUSED_PARAM(order);
  return (emc_std_intptr_t)
         InterlockedExchangePointer(reinterpret_cast<PVOID volatile*>(&object->a), reinterpret_cast<PVOID>(desired));
}

emc_std_bool emc_std_atomic_compare_exchange_strong_explicit(volatile emc_std_atomic_intptr_t* object,
                                                             emc_std_intptr_t* expected,
                                                             emc_std_intptr_t desired,
                                                             emc_std_memory_order success,
                                                             emc_std_memory_order failure)
{
  PVOID orig =
    InterlockedCompareExchangePointer(reinterpret_cast<PVOID volatile*>(&object->a),
                                      reinterpret_cast<PVOID>(desired),
                                      reinterpret_cast<PVOID>(*expected));
  if (orig != reinterpret_cast<PVOID>(*expected)) {
    expected = (emc_std_intptr_t*)orig; return 0;
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
    return Interlocked ## op ## ((LONG volatile*)&object->a, (LONG)operand);    \
  } extern int emc_macro_requires_semicolon

define_emc_std_atomic_fetch_(add, Add);
define_emc_std_atomic_fetch_(or, Or);
define_emc_std_atomic_fetch_(xor, Xor);
define_emc_std_atomic_fetch_(and, And);
#undef define_emc_std_atomic_fetch_

emc_std_intptr_t emc_std_atomic_fetch_sub_explicit(volatile emc_std_atomic_intptr_t* object,
                                                   emc_std_intptr_t operand,
                                                   emc_std_memory_order order)
{
  return emc_std_atomic_fetch_add_explicit(object, -operand, order);
}

emc_std_bool emc_std_atomic_flag_test_and_set_explicit(volatile emc_std_atomic_flag* object,
                                                       emc_std_memory_order order)
{
  UNUSED_PARAM(order);
  return InterlockedBitTestAndSet(reinterpret_cast<LONG volatile*>(object->a), 0);
}

void emc_std_atomic_flag_clear_explicit(volatile emc_std_atomic_flag* object,
                                        emc_std_memory_order order)
{
  UNUSED_PARAM(order);
  InterlockedBitTestAndReset(reinterpret_cast<LONG volatile*>(object->a), 0);
}
