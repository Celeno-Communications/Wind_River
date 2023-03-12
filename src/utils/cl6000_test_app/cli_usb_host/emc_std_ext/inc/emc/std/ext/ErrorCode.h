/** @file
    @brief The ErrorCode similar to C++ standard
    Copyright (C) 2014-2015 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EXT_ErrorCode_H
#define EMC_STD_EXT_ErrorCode_H

#include "emc/std/ext/ErrorCategory.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/**
 * @struct EMC_ErrorCode
 * @ingroup emdoc_emc_std_ext_Error
 * The EMC USB Driver specific ErrorCode data type
 */
typedef struct EMC_ErrorCode {
  int                      value;    /**< the code value */
  const EMC_ErrorCategory* category; /**< the reference to the category */
} EMC_ErrorCode;

/** @memberof EMC_ErrorCode
 * Create an EMC USB Driver specific ErrorCode data type
 * @param value The error code value
 * @param category The used category
 * @return the create EMC_ErrorCode object
 */
static inline EMC_ErrorCode emc_error(int value, const EMC_ErrorCategory* category)
{
  EMC_ErrorCode result;
  result.value = value;
  result.category = category;
  return result;
}

/** @memberof EMC_ErrorCode
 * Create a EMC system specific ErrorCode object
 * @param  emc_stdemu_errno_value standard system error code
 * @return the created EMC_ErrorCode object
 */
static inline EMC_ErrorCode emc_system_error(int emc_stdemu_errno_value)
{
  return emc_error(emc_stdemu_errno_value, emc_system_category());
}

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_STD_EXT_ErrorCode_H */
