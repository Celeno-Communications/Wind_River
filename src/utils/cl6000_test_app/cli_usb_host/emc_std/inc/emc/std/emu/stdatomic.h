/* Copyright (C) 2013, 2018 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EMU_stdatomic_H
#define EMC_STD_EMU_stdatomic_H

EMC_EXTERN_C_BEGIN;

/* @n1570 7.17.2 Initialization */

#define EMC_STD_ATOMIC_VAR_INIT(value) { value }
typedef struct { emc_std_intptr_t a; } emc_std_atomic_intptr_t;
void emc_std_atomic_init(volatile emc_std_atomic_intptr_t* a, emc_std_intptr_t m);

/* @n1570 7.17.3 Order and consistency */

typedef enum emc_std_memory_order {
  emc_std_memory_order_relaxed,
  emc_std_memory_order_consume,
  emc_std_memory_order_acquire,
  emc_std_memory_order_release,
  emc_std_memory_order_acq_rel,
  emc_std_memory_order_seq_cst
} emc_std_memory_order;

#define emc_std_kill_dependency(t) do { UNUSED_PARAM(t); } while (0)

/* @n1570 7.17.4 Fences */

void emc_std_atomic_thread_fence(emc_std_memory_order order);
void emc_std_atomic_signal_fence(emc_std_memory_order order);

/* @n1570 7.17.5 Lock-free property */

#define EMC_STD_ATOMIC_BOOL_LOCK_FREE 2
#define EMC_STD_ATOMIC_CHAR_LOCK_FREE 2
#define EMC_STD_ATOMIC_CHAR16_T_LOCK_FREE 2
#define EMC_STD_ATOMIC_CHAR32_T_LOCK_FREE 2
#define EMC_STD_ATOMIC_WCHAR_T_LOCK_FREE 2
#define EMC_STD_ATOMIC_SHORT_LOCK_FREE 2
#define EMC_STD_ATOMIC_INT_LOCK_FREE 2
#define EMC_STD_ATOMIC_LONG_LOCK_FREE 2
#define EMC_STD_ATOMIC_LLONG_LOCK_FREE 2
#define EMC_STD_ATOMIC_POINTER_LOCK_FREE 2

#ifndef ATOMIC_BOOL_LOCK_FREE
#  define ATOMIC_BOOL_LOCK_FREE EMC_STD_ATOMIC_BOOL_LOCK_FREE
#endif
#ifndef ATOMIC_CHAR_LOCK_FREE
#  define ATOMIC_CHAR_LOCK_FREE EMC_STD_ATOMIC_CHAR_LOCK_FREE
#endif
#ifndef ATOMIC_CHAR16_T_LOCK_FREE
#  define ATOMIC_CHAR16_T_LOCK_FREE EMC_STD_ATOMIC_CHAR16_T_LOCK_FREE
#endif
#ifndef ATOMIC_CHAR32_T_LOCK_FREE
#  define ATOMIC_CHAR32_T_LOCK_FREE EMC_STD_ATOMIC_CHAR32_T_LOCK_FREE
#endif
#ifndef ATOMIC_WCHAR_T_LOCK_FREE
#  define ATOMIC_WCHAR_T_LOCK_FREE EMC_STD_ATOMIC_WCHAR_T_LOCK_FREE
#endif
#ifndef ATOMIC_INT_LOCK_FREE
#  define ATOMIC_INT_LOCK_FREE EMC_STD_ATOMIC_INT_LOCK_FREE
#endif
#ifndef ATOMIC_LONG_LOCK_FREE
#  define ATOMIC_LONG_LOCK_FREE EMC_STD_ATOMIC_LONG_LOCK_FREE
#endif
#ifndef ATOMIC_LLONG_LOCK_FREE
#  define ATOMIC_LLONG_LOCK_FREE EMC_STD_ATOMIC_LLONG_LOCK_FREE
#endif
#ifndef ATOMIC_POINTER_LOCK_FREE
#  define ATOMIC_POINTER_LOCK_FREE EMC_STD_ATOMIC_POINTER_LOCK_FREE
#endif

emc_std_bool emc_std_atomic_is_lock_free(const volatile emc_std_atomic_intptr_t* obj);

/* @n1570 7.17.6 Atomic integer types */

/* Since we cannot emulate "_Atomic MyType*" or multiple atomic
   typedefs without "_Generic" selectors emc_std is limited to intptr_t. */

/* @n1570 7.17.7 Operations on atomic types */

void emc_std_atomic_store(volatile emc_std_atomic_intptr_t* object,
                          emc_std_intptr_t desired);

void emc_std_atomic_store_explicit(volatile emc_std_atomic_intptr_t* object,
                                   emc_std_intptr_t desired,
                                   emc_std_memory_order order);

emc_std_intptr_t emc_std_atomic_load(volatile emc_std_atomic_intptr_t* object);

emc_std_intptr_t emc_std_atomic_load_explicit(volatile emc_std_atomic_intptr_t* object,
                                              emc_std_memory_order order);

emc_std_intptr_t emc_std_atomic_exchange(volatile emc_std_atomic_intptr_t* object,
                                         emc_std_intptr_t desired);
emc_std_intptr_t emc_std_atomic_exchange_explicit(volatile emc_std_atomic_intptr_t* object,
                                                  emc_std_intptr_t desired,
                                                  emc_std_memory_order order);

emc_std_bool emc_std_atomic_compare_exchange_strong(volatile emc_std_atomic_intptr_t* object,
                                                    emc_std_intptr_t* expected,
                                                    emc_std_intptr_t desired);
emc_std_bool emc_std_atomic_compare_exchange_strong_explicit(volatile emc_std_atomic_intptr_t* object,
                                                             emc_std_intptr_t* expected,
                                                             emc_std_intptr_t desired,
                                                             emc_std_memory_order success,
                                                             emc_std_memory_order failure);

emc_std_bool emc_std_atomic_compare_exchange_weak(volatile emc_std_atomic_intptr_t* object,
                                                  emc_std_intptr_t* expected,
                                                  emc_std_intptr_t desired);
emc_std_bool emc_std_atomic_compare_exchange_weak_explicit(volatile emc_std_atomic_intptr_t* object,
                                                           emc_std_intptr_t* expected,
                                                           emc_std_intptr_t desired,
                                                           emc_std_memory_order success,
                                                           emc_std_memory_order failure);

#define declare_emc_std_atomic_fetch_(key)                            \
  emc_std_intptr_t                                                      \
  emc_std_atomic_fetch_ ## key(volatile emc_std_atomic_intptr_t * object, \
                               emc_std_intptr_t operand);               \
  emc_std_intptr_t                                                      \
    emc_std_atomic_fetch_ ## key ## _explicit(volatile emc_std_atomic_intptr_t * object, \
                                              emc_std_intptr_t operand,   \
                                              emc_std_memory_order order)
declare_emc_std_atomic_fetch_(add);
declare_emc_std_atomic_fetch_(sub);
declare_emc_std_atomic_fetch_(or);
declare_emc_std_atomic_fetch_(xor);
declare_emc_std_atomic_fetch_(and);
#undef declare_emc_std_atomic_fetch_

/* @n1570 7.17.8 Atomic flag type and operations */

typedef struct emc_std_private_flag { int a; } emc_std_atomic_flag;
/*lint -esym(1401, emc_std_private_flag::a) */
#define EMC_STD_ATOMIC_FLAG_INIT { 0 }

emc_std_bool emc_std_atomic_flag_test_and_set(volatile emc_std_atomic_flag* object);

emc_std_bool emc_std_atomic_flag_test_and_set_explicit(volatile emc_std_atomic_flag* object,
                                                       emc_std_memory_order order);

void emc_std_atomic_flag_clear(volatile emc_std_atomic_flag* object);
void emc_std_atomic_flag_clear_explicit(volatile emc_std_atomic_flag* object,
                                        emc_std_memory_order order);

EMC_EXTERN_C_END;

#endif
