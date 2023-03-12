/* Copyright (C) 2016 emsys Embedded Systems GmbH */
#include "emc/std/stdatomic.h"

void emc_std_atomic_store_explicit(volatile emc_std_atomic_intptr_t* object,
                                   emc_std_intptr_t desired,
                                   emc_std_memory_order order)
{
  UNUSED_PARAM(object);
  UNUSED_PARAM(desired);
  UNUSED_PARAM(order);
}

emc_std_intptr_t emc_std_atomic_load_explicit(volatile emc_std_atomic_intptr_t* object,
                                              emc_std_memory_order order)
{
  UNUSED_PARAM(object);
  UNUSED_PARAM(order);

  return 0;
}

emc_std_intptr_t emc_std_atomic_exchange_explicit(volatile emc_std_atomic_intptr_t* object,
                                                  emc_std_intptr_t desired,
                                                  emc_std_memory_order order)
{
  UNUSED_PARAM(object);
  UNUSED_PARAM(desired);
  UNUSED_PARAM(order);

  return 0;
}

emc_std_bool emc_std_atomic_compare_exchange_strong_explicit(volatile emc_std_atomic_intptr_t* object,
                                                             emc_std_intptr_t* expected,
                                                             emc_std_intptr_t desired,
                                                             emc_std_memory_order success,
                                                             emc_std_memory_order failure)
{
  UNUSED_PARAM(object);
  UNUSED_PARAM(expected);
  UNUSED_PARAM(desired);
  UNUSED_PARAM(success);
  UNUSED_PARAM(failure);

  return emc_std_false;
}

emc_std_bool emc_std_atomic_compare_exchange_weak_explicit(volatile emc_std_atomic_intptr_t* object,
                                                           emc_std_intptr_t* expected,
                                                           emc_std_intptr_t desired,
                                                           emc_std_memory_order success,
                                                           emc_std_memory_order failure)
{
  UNUSED_PARAM(object);
  UNUSED_PARAM(expected);
  UNUSED_PARAM(desired);
  UNUSED_PARAM(success);
  UNUSED_PARAM(failure);

  return emc_std_false;
}

emc_std_bool emc_std_atomic_flag_test_and_set_explicit(volatile emc_std_atomic_flag* object,
                                                       emc_std_memory_order order)
{
  UNUSED_PARAM(object);
  UNUSED_PARAM(order);

  return emc_std_false;
}

void emc_std_atomic_flag_clear_explicit(volatile emc_std_atomic_flag* object,
                                        emc_std_memory_order order)
{
  UNUSED_PARAM(object);
  UNUSED_PARAM(order);
}

void emc_std_atomic_thread_fence(emc_std_memory_order order)
{
  UNUSED_PARAM(order);
}

#define define_emc_std_atomic_fetch_(key)                                 \
  emc_std_intptr_t                                                       \
  emc_std_atomic_fetch_ ## key ## _explicit(volatile emc_std_atomic_intptr_t * object, \
                                            emc_std_intptr_t operand,    \
                                            emc_std_memory_order order)  \
  {                                                                      \
    UNUSED_PARAM(object);                                                \
    UNUSED_PARAM(operand);                                               \
    UNUSED_PARAM(order);                                                 \
    return 0;                                                            \
  } extern int emc_macro_requires_semicolon

define_emc_std_atomic_fetch_(add);
define_emc_std_atomic_fetch_(sub);
define_emc_std_atomic_fetch_(or);
define_emc_std_atomic_fetch_(xor);
define_emc_std_atomic_fetch_(and);
#undef define_emc_std_atomic_fetch_
