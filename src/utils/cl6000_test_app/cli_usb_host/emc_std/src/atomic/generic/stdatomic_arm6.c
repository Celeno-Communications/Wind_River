/* Copyright (C) 2013 emsys Embedded Systems GmbH */
#include "emc/std/stdatomic.h"

#pragma push
#pragma arm

#if __ARMCC_VERSION >= 400000
#  define emcpp_armv6_ldrex(ptr)      (__ldrex((ptr)))
#  define emcpp_armv6_strex(val, ptr) (__strex((val), (ptr)))
#else
__forceinline emc_std_intptr_t emcpp_armv6_ldrex(volatile emc_std_intptr_t* ptr)
{
  emc_std_intptr_t result; // Previous value
  __asm { LDREX result, [ptr] }
  return result;
}

__forceinline int emcpp_armv6_strex(emc_std_intptr_t val, volatile emc_std_intptr_t* ptr)
{
  int result; // 0 (success) or 1 (failure)
  __asm { STREX result, val, [ptr]; }
  return result;
}

#endif

static inline void data_memory_barrier()
{
  int should_be_zero = 0;
#pragma diag_suppress 2523 /* use of inline assembler is deprecated */
  __asm { MCR p15, 0, should_be_zero, c7, c10, 5 }
}

void emc_std_atomic_thread_fence(emc_std_memory_order order)
{
  if (emc_std_memory_order_relaxed != order) {
    data_memory_barrier();
  }
}

static inline void release_fence(emc_std_memory_order order)
{
  if ((emc_std_memory_order_relaxed != order) &&
      (emc_std_memory_order_acquire != order) &&
      (emc_std_memory_order_consume != order))
  {
    data_memory_barrier();
  }
}

static inline void acquire_fence(emc_std_memory_order order)
{
  if ((emc_std_memory_order_relaxed != order) &&
      (emc_std_memory_order_release != order))
  {
    data_memory_barrier();
  }
}

void emc_std_atomic_store_explicit(volatile emc_std_atomic_intptr_t* object,
                                   emc_std_intptr_t desired,
                                   emc_std_memory_order order)
{
  emc_std_atomic_thread_fence(order);
  object->a = desired;
}

emc_std_intptr_t emc_std_atomic_load_explicit(volatile emc_std_atomic_intptr_t* object,
                                              emc_std_memory_order order)
{
  emc_std_intptr_t result = object->a;
  emc_std_atomic_thread_fence(order);
  return result;
}

emc_std_intptr_t emc_std_atomic_exchange_explicit(volatile emc_std_atomic_intptr_t* object,
                                                  emc_std_intptr_t desired,
                                                  emc_std_memory_order order)
{
  emc_std_intptr_t result;
  release_fence(order);
  do {
    result = emcpp_armv6_ldrex(&object->a);
  } while (emcpp_armv6_strex(desired, &object->a));
  acquire_fence(order);
  return result;
}

emc_std_bool emc_std_atomic_compare_exchange_strong_explicit(volatile emc_std_atomic_intptr_t* object,
                                                             emc_std_intptr_t* expected,
                                                             emc_std_intptr_t desired,
                                                             emc_std_memory_order success,
                                                             emc_std_memory_order failure)
{
  emc_std_intptr_t current;
  release_fence(success);
  do {
    current = emcpp_armv6_ldrex(&object->a);
    if (current != *expected) {
      /*__clrex();*/
      *expected = current;
      acquire_fence(failure);
      return 0;
    }
  } while (emcpp_armv6_strex(desired, &object->a));
  acquire_fence(success);
  return 1;
}

emc_std_bool emc_std_atomic_compare_exchange_weak_explicit(volatile emc_std_atomic_intptr_t* object,
                                                           emc_std_intptr_t* expected,
                                                           emc_std_intptr_t desired,
                                                           emc_std_memory_order success,
                                                           emc_std_memory_order failure)
{
  emc_std_intptr_t current;
  release_fence(success);
  current = emcpp_armv6_ldrex(&object->a);
  if (current == *expected) {
    if (!emcpp_armv6_strex(desired, &object->a)) {
      acquire_fence(success);
      return 1;
    }
  } else {
    /* __clrex(); */
  }
  *expected = current;
  acquire_fence(failure);
  return 0;
}

#define define_emc_std_atomic_fetch_(key, op)                             \
  emc_std_intptr_t                                                       \
  emc_std_atomic_fetch_ ## key ## _explicit(volatile emc_std_atomic_intptr_t * object, \
                                            emc_std_intptr_t operand,    \
                                            emc_std_memory_order order)  \
  {                                                                      \
    emc_std_intptr_t result;                                             \
    release_fence(order);                                                \
    do {                                                                 \
      result = emcpp_armv6_ldrex(&object->a);                            \
    } while (emcpp_armv6_strex(result op operand, &object->a));          \
    acquire_fence(order);                                                \
    return result;                                                       \
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
  emc_std_intptr_t result;
  release_fence(order);
  do {
    result = emcpp_armv6_ldrex(&object->a);
  } while (emcpp_armv6_strex(1, &object->a));
  acquire_fence(order);
  return result;
}

void emc_std_atomic_flag_clear_explicit(volatile emc_std_atomic_flag* object,
                                        emc_std_memory_order order)
{
  if (emc_std_memory_order_relaxed != order) {
    emc_std_atomic_thread_fence(emc_std_memory_order_release);
  }
  release_fence(order);
  /* do { emcpp_armv6_ldrex(&object->a); } while (emcpp_armv6_strex(0, &object->a)); */
  object->a = 0;
  acquire_fence(order);
}

#pragma pop
