/*
 * log_internal.h
 *
 *  Created on: 25.04.2012
 *      Author: Enrico_s
 */

#ifndef EMC_LOG_log_internal_H
#define EMC_LOG_log_internal_H

#if EMC_LOG_INTERNAL_USES_PC
#  include "emc/std/emu/program_counter.h"
#endif

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
extern "C" {
#endif
// clang-format on extern C

#if EMC_LOG_INTERNAL_HAS_CONFIGURE
#  include "log_internal_configure.h"
#endif

#define _EMC_STATIC_LOG_LEVEL_DEFINE(prio)                            \
  static const unsigned int static_log_level = (EMC_LOG_PRIORITY_ ## prio)

#define EMC_STATIC_LOG_LEVEL_DEFINE(prio) \
  _EMC_STATIC_LOG_LEVEL_DEFINE(prio)

#define _EMC_LOG_HASHMSG(message) ((unsigned long)(message))

#define _EMC_LOG_SIZEOF_DATA(num) \
  (sizeof(emc_log_header_t) + (num * sizeof(unsigned long)))

#if EMC_LOG_INTERNAL_USES_PC
#  define _EMC_LOG_WRITE_HEADER(dat) \
  do { \
    dat->header.self = emc_std_get_pc();   \
  } while (0)

#elif EMC_LOG_INTERNAL_USES_FILE
#  define _EMC_LOG_WRITE_HEADER(dat) \
  do { \
    dat->header.func = __func__; \
    dat->header.line = __LINE__; \
    dat->header.classname = __FILE__; \
  } while (0)

#else /*!EMC_LOG_INTERNAL_USES_FILE*/

#  define _EMC_LOG_WRITE_HEADER(dat) \
  do { \
    dat->header.func = __func__; \
    dat->header.line = __LINE__; \
  } while (0)
#endif /*!EMC_LOG_INTERNAL_USES_FILE*/

#if EMC_LOG_INTERNAL_HAS_CONFIGURE
#  define _EMC_LOG_WRITE_FORMAT_STR(Log_data, str)    \
  do {                                                  \
    {                                                   \
      EMC_LOG_FORMAT_STR_CUSTOM(format_str, str);       \
      Log_data->data[0] = _EMC_LOG_HASHMSG(format_str); \
    }                                                   \
  } while (0)
#else
#  define _EMC_LOG_WRITE_FORMAT_STR(Log_data, str)    \
  do {                                                  \
    Log_data->data[0] = _EMC_LOG_HASHMSG(str);          \
  } while (0)
#endif

#define _EMC_LOG_P5(logger, prio, str, v1, v2, v3, v4, v5) \
  do { \
    emc_log_data_t* Log_data; \
    EMC_LOG_ENTER_FUNCTION; \
    Log_data = emc_logger_log_data(logger, _EMC_LOG_SIZEOF_DATA(6), EMC_LOG_PRIORITY_ ## prio); \
    if (Log_data != 0) {                                                \
      _EMC_LOG_WRITE_HEADER(Log_data);                                  \
      _EMC_LOG_WRITE_FORMAT_STR(Log_data, str);                         \
      Log_data->data[1] = (emc_log_param_type_t)v1;                     \
      Log_data->data[2] = (emc_log_param_type_t)v2;                     \
      Log_data->data[3] = (emc_log_param_type_t)v3;                     \
      Log_data->data[4] = (emc_log_param_type_t)v4;                     \
      Log_data->data[5] = (emc_log_param_type_t)v5;                     \
      emc_logger_log_func((logger), Log_data);                          \
    } EMC_LOG_EXIT_FUNCTION; \
  } while (0)

#define _EMC_LOG_P4(logger, prio, str, v1, v2, v3, v4) \
  do { \
    emc_log_data_t* Log_data; \
    EMC_LOG_ENTER_FUNCTION; \
    Log_data = emc_logger_log_data(logger, _EMC_LOG_SIZEOF_DATA(5), EMC_LOG_PRIORITY_ ## prio); \
    if (Log_data != 0) {                                                \
      _EMC_LOG_WRITE_HEADER(Log_data);                                  \
      _EMC_LOG_WRITE_FORMAT_STR(Log_data, str);                         \
      Log_data->data[1] = (emc_log_param_type_t)v1;                     \
      Log_data->data[2] = (emc_log_param_type_t)v2;                     \
      Log_data->data[3] = (emc_log_param_type_t)v3;                     \
      Log_data->data[4] = (emc_log_param_type_t)v4;                     \
      emc_logger_log_func((logger), Log_data);                          \
    } EMC_LOG_EXIT_FUNCTION;                                            \
  } while (0)

#define _EMC_LOG_P3(logger, prio, str, v1, v2, v3) \
  do { \
    emc_log_data_t* Log_data; \
    EMC_LOG_ENTER_FUNCTION; \
    Log_data = emc_logger_log_data(logger, _EMC_LOG_SIZEOF_DATA(4), EMC_LOG_PRIORITY_ ## prio); \
    if (Log_data != 0) {                                                \
      _EMC_LOG_WRITE_HEADER(Log_data);                                  \
      _EMC_LOG_WRITE_FORMAT_STR(Log_data, str);                         \
      Log_data->data[1] = (emc_log_param_type_t)v1;                     \
      Log_data->data[2] = (emc_log_param_type_t)v2;                     \
      Log_data->data[3] = (emc_log_param_type_t)v3;                     \
      emc_logger_log_func((logger), Log_data);                          \
    } EMC_LOG_EXIT_FUNCTION;                                            \
  } while (0)

#define _EMC_LOG_P2(logger, prio, str, v1, v2) \
  do { \
    emc_log_data_t* Log_data; \
    EMC_LOG_ENTER_FUNCTION; \
    Log_data = emc_logger_log_data(logger, _EMC_LOG_SIZEOF_DATA(3), EMC_LOG_PRIORITY_ ## prio); \
    if (Log_data != 0) {                                                \
      _EMC_LOG_WRITE_HEADER(Log_data);                                  \
      _EMC_LOG_WRITE_FORMAT_STR(Log_data, str);                         \
      Log_data->data[1] = (emc_log_param_type_t)v1;                     \
      Log_data->data[2] = (emc_log_param_type_t)v2;                     \
      emc_logger_log_func((logger), Log_data);                          \
    } EMC_LOG_EXIT_FUNCTION;                                            \
  } while (0)

#define _EMC_LOG_P1(logger, prio, str, v1) \
  do { \
    emc_log_data_t* Log_data; \
    EMC_LOG_ENTER_FUNCTION; \
    Log_data = emc_logger_log_data(logger, _EMC_LOG_SIZEOF_DATA(2), EMC_LOG_PRIORITY_ ## prio); \
    if (Log_data != 0) {                                                \
      _EMC_LOG_WRITE_HEADER(Log_data);                                  \
      _EMC_LOG_WRITE_FORMAT_STR(Log_data, str);                         \
      Log_data->data[1] = (emc_log_param_type_t)v1;                     \
      emc_logger_log_func((logger), Log_data);                          \
    } EMC_LOG_EXIT_FUNCTION;                                            \
  } while (0)

#define _EMC_LOG_P0(logger, prio, str) \
  do { \
    emc_log_data_t* Log_data; \
    EMC_LOG_ENTER_FUNCTION; \
    Log_data = emc_logger_log_data(logger, _EMC_LOG_SIZEOF_DATA(1), EMC_LOG_PRIORITY_ ## prio); \
    if (Log_data != 0) {                                                \
      _EMC_LOG_WRITE_HEADER(Log_data);                                  \
      _EMC_LOG_WRITE_FORMAT_STR(Log_data, str);                         \
      emc_logger_log_func((logger), Log_data);                          \
    } EMC_LOG_EXIT_FUNCTION;                                            \
  } while (0)

/** Provide logging with string & five value parameters */
#define EMC_LOG5(logger, prio, string, value1, value2, value3, value4, value5) \
  do { if ((static_log_level) >= (EMC_LOG_PRIORITY_ ## prio)) { \
      _EMC_LOG_P5((logger), prio, string, (value1), (value2), (value3), \
                  (value4), (value5)); \
    } } while (0)
/** Provide logging with string & four value parameters */
#define EMC_LOG4(logger, prio, string, value1, value2, value3, value4) \
  do { if ((static_log_level) >= (EMC_LOG_PRIORITY_ ## prio)) { \
      _EMC_LOG_P4((logger), prio, string, (value1), (value2), (value3), \
                  (value4)); \
    } } while (0)
/** Provide logging with string & three value parameters */
#define EMC_LOG3(logger, prio, string, value1, value2, value3) \
  do { if ((static_log_level) >= (EMC_LOG_PRIORITY_ ## prio)) { \
      _EMC_LOG_P3((logger), prio, string, (value1), (value2), (value3)); \
    } } while (0)
/** Provide logging with string & two value parameters */
#define EMC_LOG2(logger, prio, string, value1, value2) \
  do { if ((static_log_level) >= (EMC_LOG_PRIORITY_ ## prio)) { \
      _EMC_LOG_P2((logger), prio, string, (value1), (value2)); \
    } } while (0)
/** Provide logging with string & one value parameters */
#define EMC_LOG1(logger, prio, string, value1) \
  do { if ((static_log_level) >= (EMC_LOG_PRIORITY_ ## prio)) { \
      _EMC_LOG_P1((logger), prio, string, (value1)); \
    } } while (0)
/** Provide logging with only string parameter */
#define EMC_LOG(logger, prio, string) \
  do { if ((static_log_level) >= (EMC_LOG_PRIORITY_ ## prio)) { \
      _EMC_LOG_P0((logger), prio, string); \
    } } while (0)
/** Provide logging without parameters */
#define EMC_FUNCTION(logger, prio) \
  do { if ((static_log_level) >= (EMC_LOG_PRIORITY_ ## prio)) { \
      _EMC_LOG_P0((logger), prio, ""); \
    } } while (0)

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
}
#endif
// clang-format on extern C

#endif /* EMC_LOG_log_internal_H */
