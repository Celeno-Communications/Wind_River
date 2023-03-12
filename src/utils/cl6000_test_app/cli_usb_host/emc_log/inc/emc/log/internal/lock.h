/**
 * @file
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 */

#ifndef EMC_LOG_INTERNAL_lock_H
#define EMC_LOG_INTERNAL_lock_H

#include "emc/log/configure.h"

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
extern "C" {
#endif
// clang-format on extern C

/** prototype for generic lock acquire function */
typedef int emc_lock_lock (void* context);
/** prototype for generic lock release function */
typedef int emc_lock_unlock (void* context);

/** generic lock object, used to synchronize code execution on the owning object */
typedef struct emc_log_lock {
  emc_lock_lock*   lock;    /**< acquire the lock */
  emc_lock_unlock* unlock;  /**< release the lock */
  void*            context; /**< the lock context */
} emc_log_lock_t;

/** null (NOP) lock function, set be default */
static inline int lock_null(void* context)
{
  UNUSED_PARAM(context);
  return 0;
}

/** null (NOP) unlock function, set be default */
static inline int unlock_null(void* context)
{
  UNUSED_PARAM(context);
  return 0;
}

/** default-initialize @param self, results in a null (NOP) synchronization object */
static inline void emc_log_lock_init(emc_log_lock_t* self)
{
  self->lock = lock_null;
  self->unlock = unlock_null;
  self->context = 0;
}

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
}
#endif
// clang-format on extern C

#endif /* EMC_LOG_INTERNAL_lock_H */
