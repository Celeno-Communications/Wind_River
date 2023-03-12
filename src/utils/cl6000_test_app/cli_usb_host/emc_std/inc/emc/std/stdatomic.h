/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_stdatomic_H
#define EMC_STD_stdatomic_H

#include "emc/std/stdbool.h"
#include "emc/std/stdint.h"

#if !defined(EMC_STD_ATOMIC_STD)
#  define EMC_STD_EMULATES_STDATOMIC 1
#else
#  if !EMC_STD_STDLIB_EMULATE

#    if defined(__cplusplus)
/* maybe this is only necessary for gcc but currently it's not possible to use stdatomic.h in C++ */
#      include <atomic>
#      define EMC_STD_NS ::std::
#      if defined(GCC_VERSION) && GCC_VERSION < 40500 && !defined(__clang__)
#        define ATOMIC_INT_LOCK_FREE 2
#      endif /* GCC <= 4.5 */
#    else /* ! __cplusplus */
#      include <stdatomic.h>
#      define EMC_STD_NS
#    endif /* ! __cplusplus */

#    define EMC_STD_EMULATES_STDATOMIC 0

#  else /* !(C_LIBRARY_HAS_STDATOMIC_H && !EMC_STD_STDLIB_EMULATE) */

#    define EMC_STD_EMULATES_STDATOMIC 1

#  endif /* !(C_LIBRARY_HAS_STDATOMIC_H && !EMC_STD_STDLIB_EMULATE) */
#endif

#if EMC_STD_EMULATES_STDATOMIC

#  include "emc/std/emu/stdatomic.h"

#else /*!EMC_STD_EMULATES_STDATOMIC */

#  define EMC_STD_ATOMIC_VAR_INIT ATOMIC_VAR_INIT
#  define emc_std_atomic_init atomic_init

typedef EMC_STD_NS memory_order emc_std_memory_order;
#  define emc_std_memory_order_relaxed EMC_STD_NS memory_order_relaxed
#  define emc_std_memory_order_consume EMC_STD_NS memory_order_consume
#  define emc_std_memory_order_acquire EMC_STD_NS memory_order_acquire
#  define emc_std_memory_order_release EMC_STD_NS memory_order_release
#  define emc_std_memory_order_acq_rel EMC_STD_NS memory_order_acq_rel
#  define emc_std_memory_order_seq_cst EMC_STD_NS memory_order_seq_cst
#  define emc_std_kill_dependency kill_dependency

#  define emc_std_atomic_is_lock_free EMC_STD_NS atomic_is_lock_free

#  define emc_std_atomic_thread_fence EMC_STD_NS atomic_thread_fence
#  define emc_std_atomic_signal_fence EMC_STD_NS atomic_signal_fence

#  if defined(GCC_VERSION) && GCC_VERSION < 50000
/* the ATOMIC_*_LOCK_FREE macros don't work as expected for the older gcc */
#    define EMC_STD_ATOMIC_BOOL_LOCK_FREE __GCC_ATOMIC_BOOL_LOCK_FREE
#    define EMC_STD_ATOMIC_CHAR_LOCK_FREE __GCC_ATOMIC_CHAR_LOCK_FREE
#    define EMC_STD_ATOMIC_CHAR16_T_LOCK_FREE __GCC_ATOMIC_CHAR16_T_LOCK_FREE
#    define EMC_STD_ATOMIC_CHAR32_T_LOCK_FREE __GCC_ATOMIC_CHAR32_T_LOCK_FREE
#    define EMC_STD_ATOMIC_WCHAR_T_LOCK_FREE __GCC_ATOMIC_WCHAR_T_LOCK_FREE
#    define EMC_STD_ATOMIC_SHORT_LOCK_FREE __GCC_ATOMIC_SHORT_LOCK_FREE
#    define EMC_STD_ATOMIC_INT_LOCK_FREE __GCC_ATOMIC_INT_LOCK_FREE
#    define EMC_STD_ATOMIC_LONG_LOCK_FREE __GCC_ATOMIC_LONG_LOCK_FREE
#    define EMC_STD_ATOMIC_LLONG_LOCK_FREE __GCC_ATOMIC_LLONG_LOCK_FREE
#    define EMC_STD_ATOMIC_POINTER_LOCK_FREE __GCC_ATOMIC_POINTER_LOCK_FREE
#  else
#    define EMC_STD_ATOMIC_BOOL_LOCK_FREE ATOMIC_BOOL_LOCK_FREE
#    define EMC_STD_ATOMIC_CHAR_LOCK_FREE ATOMIC_CHAR_LOCK_FREE
#    define EMC_STD_ATOMIC_CHAR16_T_LOCK_FREE ATOMIC_CHAR16_T_LOCK_FREE
#    define EMC_STD_ATOMIC_CHAR32_T_LOCK_FREE ATOMIC_CHAR32_T_LOCK_FREE
#    define EMC_STD_ATOMIC_WCHAR_T_LOCK_FREE ATOMIC_WCHAR_T_LOCK_FREE
#    define EMC_STD_ATOMIC_SHORT_LOCK_FREE ATOMIC_SHORT_LOCK_FREE
#    define EMC_STD_ATOMIC_INT_LOCK_FREE ATOMIC_INT_LOCK_FREE
#    define EMC_STD_ATOMIC_LONG_LOCK_FREE ATOMIC_LONG_LOCK_FREE
#    define EMC_STD_ATOMIC_LLONG_LOCK_FREE ATOMIC_LLONG_LOCK_FREE
#    define EMC_STD_ATOMIC_POINTER_LOCK_FREE ATOMIC_POINTER_LOCK_FREE
#  endif

typedef EMC_STD_NS atomic_intptr_t emc_std_atomic_intptr_t;

#  define emc_std_atomic_store EMC_STD_NS atomic_store
#  define emc_std_atomic_store_explicit EMC_STD_NS atomic_store_explicit
#  define emc_std_atomic_load EMC_STD_NS atomic_load
#  define emc_std_atomic_load_explicit EMC_STD_NS atomic_load_explicit
#  define emc_std_atomic_exchange EMC_STD_NS atomic_exchange
#  define emc_std_atomic_exchange_explicit EMC_STD_NS atomic_exchange_explicit
#  define emc_std_atomic_compare_exchange_strong EMC_STD_NS atomic_compare_exchange_strong
#  define emc_std_atomic_compare_exchange_strong_explicit \
  EMC_STD_NS atomic_compare_exchange_strong_explicit
#  define emc_std_atomic_compare_exchange_weak EMC_STD_NS atomic_compare_exchange_weak
#  define emc_std_atomic_compare_exchange_weak_explicit \
  EMC_STD_NS atomic_compare_exchange_weak_explicit
#  define emc_std_atomic_fetch_add EMC_STD_NS atomic_fetch_add
#  define emc_std_atomic_fetch_add_explicit EMC_STD_NS atomic_fetch_add_explicit
#  define emc_std_atomic_fetch_sub EMC_STD_NS atomic_fetch_sub
#  define emc_std_atomic_fetch_sub_explicit EMC_STD_NS atomic_fetch_sub_explicit
#  define emc_std_atomic_fetch_or EMC_STD_NS atomic_fetch_or
#  define emc_std_atomic_fetch_or_explicit EMC_STD_NS atomic_fetch_or_explicit
#  define emc_std_atomic_fetch_xor EMC_STD_NS atomic_fetch_xor
#  define emc_std_atomic_fetch_xor_explicit EMC_STD_NS atomic_fetch_xor_explicit
#  define emc_std_atomic_fetch_and EMC_STD_NS atomic_fetch_and
#  define emc_std_atomic_fetch_and_explicit EMC_STD_NS atomic_fetch_and_explicit

typedef EMC_STD_NS atomic_flag emc_std_atomic_flag;
#  define EMC_STD_ATOMIC_FLAG_INIT ATOMIC_FLAG_INIT
#  define EMCPP_ATOMIC_FLAG_INIT ATOMIC_FLAG_INIT
#  define emc_std_atomic_flag_test_and_set atomic_flag_test_and_set
#  define emc_std_atomic_flag_test_and_set atomic_flag_test_and_set
#  define emc_std_atomic_flag_test_and_set_explicit atomic_flag_test_and_set_explicit
#  define emc_std_atomic_flag_test_and_set_explicit atomic_flag_test_and_set_explicit
#  define emc_std_atomic_flag_clear atomic_flag_clear
#  define emc_std_atomic_flag_clear atomic_flag_clear
#  define emc_std_atomic_flag_clear_explicit atomic_flag_clear_explicit
#  define emc_std_atomic_flag_clear_explicit atomic_flag_clear_explicit

#endif /*!EMC_STD_EMULATES_STDATOMIC */

#endif /* EMC_STD_stdatomic_H */
