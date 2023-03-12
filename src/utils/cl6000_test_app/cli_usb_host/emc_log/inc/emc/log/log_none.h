/*
 * log_none.h
 *
 *  Created on: 10.01.2017
 *      Author: frank_s
 */

#ifndef EMC_LOG_log_none_H
#define EMC_LOG_log_none_H

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
extern "C" {
#endif
// clang-format on extern C

#define EMC_Log_logger(category) (0)
#define EMC_Log_root_logger() (0)
#define EMC_Log_logger_by_index(index) (0)

#define emc_logger_log_func(logger, data)

#define emc_logger_log_data(logger, length, priority) (0)

#define EMC_Log_logger_name(logger) "";

#define EMC_Log_enable(logger, enabled)
#define EMC_Log_is_enabled(logger) 0

#define EMC_Log_enable_timestamp(logger, enabled, recursive)
#define EMC_Log_is_timestamp_enabled(logger) 0

#define EMC_Log_set_priority(logger, priority)
#define EMC_Log_priority(logger) 0

#define EMC_Log_logger_info(logger, buffer, buffer_size) 0

#define EMC_Log_log_count(logger) 0

#define EMC_STATIC_LOG_LEVEL_DEFINE(prio) \
  struct emc_macro_requires_semicolon

#define EMC_LOG5(log, prio, msg, p1, p2, p3, p4, p5) \
  do {((void)(log)); ((void)(p1)); ((void)(p2)); ((void)(p3)); ((void)(p4)); ((void)(p5)); \
  } while (0)
#define EMC_LOG4(log, prio, msg, p1, p2, p3, p4) \
  do {((void)(log)); ((void)(p1)); ((void)(p2)); ((void)(p3)); ((void)(p4));} while (0)
#define EMC_LOG3(log, prio, msg, p1, p2, p3) \
  do {((void)(log)); ((void)(p1)); ((void)(p2)); ((void)(p3));} while (0)
#define EMC_LOG2(log, prio, msg, p1, p2) do {((void)(log)); ((void)(p1)); ((void)(p2));} while (0)
#define EMC_LOG1(log, prio, msg, p1) do {((void)(log)); ((void)(p1));} while (0)
#define EMC_LOG(log, prio, msg) do {((void)(log));} while (0)

#define EMC_FUNCTION(log, prio) do {((void)(log));} while (0)

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
}
#endif
// clang-format on extern C

#endif /* EMC_LOG_log_none_H */
