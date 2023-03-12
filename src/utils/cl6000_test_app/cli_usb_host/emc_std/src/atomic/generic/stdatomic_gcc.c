/* Copyright (C) 2013 emsys Embedded Systems GmbH */
#include "emc/std/stdatomic.h"

/* Since 4.7.x gcc provides memory-model aware intrinsics that allow
   a direct one-to-one mapping for stdatomic functions: */

static inline int to_gcc(emc_std_memory_order order)
{
  switch (order) {
  case emc_std_memory_order_relaxed: return __ATOMIC_RELAXED;
  case emc_std_memory_order_consume: return __ATOMIC_CONSUME;
  case emc_std_memory_order_acquire: return __ATOMIC_ACQUIRE;
  case emc_std_memory_order_release: return __ATOMIC_RELEASE;
  case emc_std_memory_order_acq_rel: return __ATOMIC_ACQ_REL;
  case emc_std_memory_order_seq_cst: return __ATOMIC_SEQ_CST;
  }
}

void emc_std_atomic_thread_fence(emc_std_memory_order order)
{
  __atomic_thread_fence(to_gcc(order));
}

...
