/**
 * @brief   An implementation that is pseudo atomic and may be used for single CPU environments.
 *
 * @author  Guenter Hildebrandt <guenter.hildebrandt@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2016 emsys Embedded Systems GmbH
 *
 *****************************************************************************/
#include "emc/std/stdatomic.h"
#include "emc/std/memory.h"
#include "emcpp/system/intel/audio/xtos/xtruntime_fwd.h"

static int int_level;

#define LOCK() int_level = _xtos_set_intlevel(GET_VALUE(CS_INT_LEVEL))
#define UNLOCK() _xtos_set_intlevel(int_level)

void emc_std_atomic_thread_fence(emc_std_memory_order order)
{
  UNUSED_PARAM(order);
}

void emc_std_atomic_store_explicit(volatile emc_std_atomic_intptr_t* object,
                                   emc_std_intptr_t desired,
                                   emc_std_memory_order order)
{
  UNUSED_PARAM(order);

  LOCK();
  object->a = desired;
  UNLOCK();
}

emc_std_intptr_t emc_std_atomic_load_explicit(volatile emc_std_atomic_intptr_t* object,
                                              emc_std_memory_order order)
{
  emc_std_intptr_t r;
  UNUSED_PARAM(order);

  LOCK();
  r = object->a;
  UNLOCK();
  return r;
}

emc_std_intptr_t emc_std_atomic_exchange_explicit(volatile emc_std_atomic_intptr_t* object,
                                                  emc_std_intptr_t desired,
                                                  emc_std_memory_order order)
{
  emc_std_intptr_t r;
  UNUSED_PARAM(order);
  LOCK();
  r = object->a;
  object->a = desired;
  UNLOCK();
  return r;
}

emc_std_bool emc_std_atomic_compare_exchange_strong_explicit(volatile emc_std_atomic_intptr_t* object,
                                                             emc_std_intptr_t* expected,
                                                             emc_std_intptr_t desired,
                                                             emc_std_memory_order success,
                                                             emc_std_memory_order failure)
{
  UNUSED_PARAM(success);
  UNUSED_PARAM(failure);
  LOCK();
  if (object->a == *expected) {
    object->a = desired;
    UNLOCK();
    return emc_std_true;
  }
  UNLOCK();
  return emc_std_false;
}

emc_std_bool emc_std_atomic_compare_exchange_weak_explicit(volatile emc_std_atomic_intptr_t* object,
                                                           emc_std_intptr_t* expected,
                                                           emc_std_intptr_t desired,
                                                           emc_std_memory_order success,
                                                           emc_std_memory_order failure)
{
  return emc_std_atomic_compare_exchange_strong_explicit(object, expected,
                                                         desired, success, failure);
}

emc_std_bool emc_std_atomic_flag_test_and_set_explicit(volatile emc_std_atomic_flag* object,
                                                       emc_std_memory_order order)
{
  emc_std_bool r;
  UNUSED_PARAM(order);
  LOCK();
  r = object->a ? emc_std_true : emc_std_false;
  object->a = 1;
  UNLOCK();
  return r;
}

void emc_std_atomic_flag_clear_explicit(volatile emc_std_atomic_flag* object,
                                        emc_std_memory_order order)
{
  UNUSED_PARAM(order);
  LOCK();
  object->a = 0;
  UNLOCK();
}

#define define_emc_std_atomic_fetch_(key, op)                             \
  emc_std_intptr_t                                                       \
  emc_std_atomic_fetch_ ## key ## _explicit(volatile emc_std_atomic_intptr_t * object, \
                                            emc_std_intptr_t operand,    \
                                            emc_std_memory_order order)  \
  {                                                                      \
    emc_std_intptr_t result;                                             \
    UNUSED_PARAM(order);                                                 \
    LOCK();                                                              \
    result = object->a;                                                  \
    object->a = object->a op operand;                                    \
    UNLOCK();                                                            \
    return result;                                                       \
  } extern int emc_macro_requires_semicolon

define_emc_std_atomic_fetch_(add, +);
define_emc_std_atomic_fetch_(sub, -);
define_emc_std_atomic_fetch_(or, |);
define_emc_std_atomic_fetch_(xor, ^);
define_emc_std_atomic_fetch_(and, &);
#undef define_emc_std_atomic_fetch_

#undef LOCK
#undef UNLOCK
