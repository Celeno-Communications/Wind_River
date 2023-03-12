/** @file
    @brief The generic ErrorCategory similar to C++ standard
    Copyright (C) 2014-2015 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EXT_ErrorCategory_H
#define EMC_STD_EXT_ErrorCategory_H

#include "emc/std/configure.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/**
 * @defgroup emdoc_emc_std_ext_Error Error Handling
 * @ingroup emdoc_emc_std_ext
 */

/**
 * @struct EMC_ErrorCategory
 * @ingroup emdoc_emc_std_ext_Error
 * The EMC extension specific ErrorCategory
 */
typedef struct EMC_ErrorCategory {
  const char* name; /**< the name of the category */
} EMC_ErrorCategory;

/** @memberof EMC_ErrorCategory
 * Provides the single instance of the EMC specific ErrorCategory object
 * @return the category object instance
 */
const EMC_ErrorCategory* emc_system_category(void);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_STD_EXT_ErrorCategory_H */
