/**
 * @file
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 */

#ifndef EMC_LOG_INTERNAL_logger_H
#define EMC_LOG_INTERNAL_logger_H

#include "emc/log/configure.h"
#include "emc/log/priority.h"
#include "emc/log/internal/appender_fwd.h"
#include "emc/std/ext/string_view.h"

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
extern "C" {
#endif
// clang-format on extern C

/** Definition of the c logger */
struct emc_logger {
  emc_std_string_view name;       /**< the logger name */
  EMC_LOG_Priorities  priority;   /**< the logger specific effective priority (set or inherited) */
  emc_log_appender*   appender;   /**< the appender */
  struct emc_logger*  parent;     /**< the parent logger */
  struct emc_logger*  next;       /**< the next logger on the same level */
  struct emc_logger*  last_child; /**< the last child logger */
  emc_std_uint32_t    flags;      /**< flags to specify specific behaviour */
  emc_std_uint16_t    hash;       /**< the hash value to identify the logger */
};

/** set the appender */
void EMC_Log_logger_set_appender(emc_logger_t* logger, emc_log_appender* appender);

/** query the appender set for a given logger */
emc_log_appender* EMC_Log_logger_appender(emc_logger_t* logger);

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
}
#endif
// clang-format on extern C

#endif
