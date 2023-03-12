/*
 * @file
 *
 *  Created on: 09.01.2017
 *      Author: frank_s
 */

#ifndef EMC_LOG_priority_H
#define EMC_LOG_priority_H

#include "emc/log/configure.h"

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
extern "C" {
#endif
// clang-format on extern C

/** Define Priorities used by Log logging system */
typedef enum EMC_LOG_Priorities_e {
  EMC_LOG_PRIORITY_OFF   = 0, /**< A logging priority level */
  EMC_LOG_PRIORITY_FATAL = 1, /**< A logging priority level */
  EMC_LOG_PRIORITY_ERROR = 2, /**< A logging priority level */
  EMC_LOG_PRIORITY_WARN  = 3, /**< A logging priority level */
  EMC_LOG_PRIORITY_INFO  = 4, /**< A logging priority level */
  EMC_LOG_PRIORITY_DEBUG = 5, /**< A logging priority level */
  EMC_LOG_PRIORITY_TRACE = 6  /**< A logging priority level */
} EMC_LOG_Priorities;

/** converts a string to a EMC_LOG_Priorities */
EMC_LOG_Priorities EMC_Log_priority_from_string(const char* name);

/** converts EMC_LOG_Priorities to a string */
const char* EMC_Log_priority_as_string(EMC_LOG_Priorities priority);

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
}
#endif
// clang-format on extern C

#endif /* EMC_LOG_priority_H */
