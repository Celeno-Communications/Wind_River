/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#include <atomic>
#include <cstdint>

#include "emc/std/stdatomic.h"

static_assert(sizeof(emc_std_intptr_t) == sizeof(::std::atomic_flag),
              "cannot cast atomic_flag");

static volatile ::std::atomic_flag* to_std(volatile emc_std_atomic_flag* f)
{
  return reinterpret_cast<volatile ::std::atomic_flag*>(f);
}

static_assert(sizeof(emc_std_intptr_t) == sizeof(::std::atomic<emc_std_intptr_t>),
              "cannot cast atomic_intptr_t");

static volatile ::std::atomic<emc_std_intptr_t>* to_std(volatile emc_std_atomic_intptr_t* a)
{
  return reinterpret_cast<volatile ::std::atomic<emc_std_intptr_t>*>(a);
}

static const volatile ::std::atomic<emc_std_intptr_t>* to_std(const volatile emc_std_atomic_intptr_t* a)
{
  return reinterpret_cast<const volatile ::std::atomic<emc_std_intptr_t>*>(a);
}

static ::std::memory_order to_std(emc_std_memory_order order)
{
  switch (order) {
  default: // goto seq_cst
  case emc_std_memory_order_seq_cst: return ::std::memory_order_seq_cst;
  case emc_std_memory_order_acq_rel: return ::std::memory_order_acq_rel;
  case emc_std_memory_order_acquire: return ::std::memory_order_acquire;
  case emc_std_memory_order_release: return ::std::memory_order_release;
  case emc_std_memory_order_consume: return ::std::memory_order_consume;
  case emc_std_memory_order_relaxed: return ::std::memory_order_relaxed;
  }
}

static_assert(sizeof(emc_std_intptr_t) == sizeof(::std::intptr_t),
              "cannot cast intptr_t");

static ::std::intptr_t to_std(emc_std_intptr_t value)
{
  return static_cast< ::std::intptr_t>(value);
}

static ::std::intptr_t* to_std(emc_std_intptr_t* value)
{
  return &static_cast< ::std::intptr_t&>(*value);
}

void emc_std_atomic_thread_fence(emc_std_memory_order order)
{
  ::std::atomic_thread_fence(to_std(order));
}

void emc_std_atomic_store_explicit(volatile emc_std_atomic_intptr_t* object,
                                   emc_std_intptr_t desired,
                                   emc_std_memory_order order)
{
  ::std::atomic_store_explicit(to_std(object), desired, to_std(order));
}

emc_std_intptr_t emc_std_atomic_load_explicit(volatile emc_std_atomic_intptr_t* object,
                                              emc_std_memory_order order)
{
  return ::std::atomic_load_explicit(to_std(object), to_std(order));
}

emc_std_intptr_t emc_std_atomic_exchange_explicit(volatile emc_std_atomic_intptr_t* object,
                                                  emc_std_intptr_t desired,
                                                  emc_std_memory_order order)
{
  return ::std::atomic_exchange_explicit(to_std(object), desired, to_std(order));
}

emc_std_bool emc_std_atomic_compare_exchange_strong_explicit(volatile emc_std_atomic_intptr_t* object,
                                                             emc_std_intptr_t* expected,
                                                             emc_std_intptr_t desired,
                                                             emc_std_memory_order success,
                                                             emc_std_memory_order failure)
{
  return ::std::atomic_compare_exchange_strong_explicit
           (to_std(object), expected, desired, to_std(success), to_std(failure));
}

emc_std_bool emc_std_atomic_compare_exchange_weak_explicit(volatile emc_std_atomic_intptr_t* object,
                                                           emc_std_intptr_t* expected,
                                                           emc_std_intptr_t desired,
                                                           emc_std_memory_order success,
                                                           emc_std_memory_order failure)
{
  return ::std::atomic_compare_exchange_weak_explicit
           (to_std(object), expected, desired, to_std(success), to_std(failure));
}

#define define_emc_std_atomic_fetch_(key)                             \
  emc_std_intptr_t                                                    \
  emc_std_atomic_fetch_ ## key ## _explicit(volatile emc_std_atomic_intptr_t * object, \
                                            emc_std_intptr_t operand,   \
                                            emc_std_memory_order order) \
  {                                                                     \
    return ::std::atomic_fetch_ ## key ## _explicit                     \
             (to_std(object), operand, to_std(order));                         \
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
  return ::std::atomic_flag_test_and_set_explicit(to_std(object), to_std(order));
}

void emc_std_atomic_flag_clear_explicit(volatile emc_std_atomic_flag* object,
                                        emc_std_memory_order order)
{
  return ::std::atomic_flag_clear_explicit(to_std(object), to_std(order));
}
