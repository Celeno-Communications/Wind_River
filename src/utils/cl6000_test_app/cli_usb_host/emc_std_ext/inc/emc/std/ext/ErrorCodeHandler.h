/** @file
    @brief The ErrorCodeHandler similar to C++ standard
    Copyright (C) 2014-2015 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EXT_ErrorCodeHandler_H
#define EMC_STD_EXT_ErrorCodeHandler_H

#include "emc/std/ext/ErrorCode.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/**
 * @struct EMC_ErrorCodeHandler
 * @ingroup emdoc_emc_std_ext_Error
 * The EMC specific ErrorCodeHandler
 */
typedef struct EMC_ErrorCodeHandler {
  void (*invoke)(void* context, EMC_ErrorCode error); /**< The handler method to invode */
  void* context;                                      /**< The generic context */
} EMC_ErrorCodeHandler;

/** @memberof EMC_ErrorCodeHandler
 * Create a  EMC_ErrorCodeHandler
 * @param invoke The handler method to invode
 * @param context The generic context for the invoke method
 * @return the created EMC_ErrorCodeHandler object
 */
static __inline EMC_ErrorCodeHandler emc_error_code_handler(void (*invoke)(void*, EMC_ErrorCode),
                                                            void* context)
{
  EMC_ErrorCodeHandler result;
  result.invoke = invoke;
  result.context = context;
  return result;
}

/** @memberof EMC_ErrorCodeHandler
 * Initialize an EMC_ErrorCodeHandler
 * @param self The object to initialize
 * @param invoke The handler method to invode
 * @param context The generic context for the invoke method
 */
static __inline void EMC_ErrorCodeHandler_initialize(EMC_ErrorCodeHandler* self,
                                                     void (*invoke)(void*, EMC_ErrorCode),
                                                     void* context)
{
  self->invoke = invoke;
  self->context = context;
}

/** @memberof EMC_ErrorCodeHandler
 * Invoke an EMC_ErrorCodeHandler
 * @param self the handler oject
 * @param error the error code for invoke call
 */
static __inline void EMC_ErrorCodeHandler_invoke(EMC_ErrorCodeHandler* self, EMC_ErrorCode error)
{
  EMC_ErrorCodeHandler copy = *self;
  self->invoke = 0;
  self->context = 0;
  copy.invoke(copy.context, error);
}

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_STD_EXT_ErrorCodeHandler_H */
