/* Copyright (C) 2013 emsys Embedded Systems GmbH */
#include "emc/std/stdatomic.h"
#include "cache.h"
#include "util_atomic.h"
#include "util_rt_services.h"

#if defined(__arm)
#  pragma diag_suppress 223
#endif

static inline void emc_ct_asserts(void)
{
  EMC_CT_ASSERT(sizeof(U32) == sizeof(emc_std_atomic_intptr_t));
  EMC_CT_ASSERT(sizeof(U32) == sizeof(emc_std_intptr_t));
  EMC_CT_ASSERT(sizeof(U32) == sizeof(emc_std_atomic_flag));
  EMC_CT_ASSERT(sizeof(U32) == sizeof(int));
}

static inline void do_not_warn(void) { emc_ct_asserts(); do_not_warn(); }

#if defined(__arm)
#  pragma diag_default 223
#endif

static inline void data_memory_barrier()
{
#if defined(__arm) && defined(__TARGET_FEATURE_MULTIPROCESSING)
  __dsb(15);
#else
  util_data_mem_barrier();
#endif
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

void emc_std_atomic_thread_fence(emc_std_memory_order order)
{
  if (emc_std_memory_order_relaxed != order) {
    data_memory_barrier();
  }
}

void emc_std_atomic_store_explicit(volatile emc_std_atomic_intptr_t* object,
                                   emc_std_intptr_t desired,
                                   emc_std_memory_order order)
{
  emc_std_atomic_thread_fence(order);
  *((U32*)&object->a) = desired;
}

emc_std_intptr_t emc_std_atomic_load_explicit(volatile emc_std_atomic_intptr_t* object,
                                              emc_std_memory_order order)
{
  emc_std_intptr_t result = (emc_std_intptr_t)*((U32*)&object->a);
  emc_std_atomic_thread_fence(order);
  return result;
}

emc_std_intptr_t emc_std_atomic_exchange_explicit(volatile emc_std_atomic_intptr_t* object,
                                                  emc_std_intptr_t desired,
                                                  emc_std_memory_order order)
{
  emc_std_intptr_t result;
  release_fence(order);
  result = (emc_std_intptr_t)util_atomic_swap_U32((U32*)&object->a, (U32)desired);
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
  emc_std_bool     result;
  release_fence(success);
  current = (emc_std_intptr_t)
            util_atomic_compare_and_swap_U32((U32*)&object->a, *expected, (U32)desired);
  result = current == *expected;
  *expected = current;
  acquire_fence(result ? success : failure);
  return result;
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

#define define_emc_std_atomic_fetch_(key)                                 \
  emc_std_intptr_t                                                       \
  emc_std_atomic_fetch_ ## key ## _explicit(volatile emc_std_atomic_intptr_t * object, \
                                            emc_std_intptr_t operand,    \
                                            emc_std_memory_order order)  \
  {                                                                      \
    emc_std_intptr_t result;                                             \
    release_fence(order);                                                \
    result = (emc_std_intptr_t)                                          \
             util_atomic_ ## key ## _U32((volatile U32*)&object->a, operand);   \
    acquire_fence(order);                                                \
    return result;                                                       \
  } extern int emc_macro_requires_semicolon

define_emc_std_atomic_fetch_(add);
define_emc_std_atomic_fetch_(sub);
define_emc_std_atomic_fetch_(or);
define_emc_std_atomic_fetch_(xor);
define_emc_std_atomic_fetch_(and);
#undef define_emc_std_atomic_fetch_

emc_std_bool emc_std_atomic_flag_test_and_set_explicit(volatile emc_std_atomic_flag* object,
                                                       emc_std_memory_order order)
{
  emc_std_bool result;
  release_fence(order);
  result = (emc_std_bool)util_atomic_swap_U32((U32*)&object->a, 1U);
  acquire_fence(order);
  return result;
}

void emc_std_atomic_flag_clear_explicit(volatile emc_std_atomic_flag* object,
                                        emc_std_memory_order order)
{
  release_fence(order);
  util_atomic_clear_bit_U32((volatile U32*)&object->a, 0);
  acquire_fence(order);
}
