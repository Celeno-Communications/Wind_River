/**
 * @file
 * @author <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 */

#ifndef EMC_LOG_INTERNAL_appender_H
#define EMC_LOG_INTERNAL_appender_H

#include "emc/log/internal/appender_fwd.h"
#include "emc/log/log.h"

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
extern "C" {
#endif
// clang-format on extern C

typedef void (* emc_log_appender_output)(void* context,
                                         const emc_logger_t* logger,
                                         emc_log_data_t* data);

typedef emc_log_data_t*(* emc_log_record)(void* context);

/** Definition of the c log appender function table*/
typedef struct emc_log_appender_ftbl {
  const char*             name;   /**< the appender type name */
  emc_log_record          record; /**< the get next record function */
  emc_log_appender_output output; /**< the output function */
} emc_log_appender_ftbl;

/** Definition of the c log appender */
struct emc_log_appender {
  const emc_log_appender_ftbl* ftbl;    /**< the function table */
  void*                        context; /**< an optional context */
};

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
}
#endif
// clang-format on extern C

#endif
