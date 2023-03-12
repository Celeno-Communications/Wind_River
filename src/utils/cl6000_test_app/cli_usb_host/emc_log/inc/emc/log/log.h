/*
 * log.h
 *
 *  Created on: 09.01.2017
 *      Author: frank_s
 */

#ifndef EMC_LOG_log_H
#define EMC_LOG_log_H

#include "emc/log/configure.h"
#include "emc/log/priority.h"
#include "emc/std/stdint.h"
#include "emc/std/stddef.h"

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
extern "C" {
#endif
// clang-format on extern C

/* a place holder to extend the log with some profiling code */
#define EMC_LOG_ENTER_FUNCTION
#define EMC_LOG_EXIT_FUNCTION

typedef struct len_prio_id_s {
  unsigned char  len;  /**< length of the belonging log data structure (in bytes) */
  unsigned char  prio; /**< the priority of the log message */
  unsigned short id;   /**< the id of the logger sending this message */
} len_prio_id_t;

/** Structure containing all log message data,
 *  which are not the log message or message parameter.
 *  E.g.: Line, Priority, Log-Count, Timestamp, ...
 *
 *  The length of the whole log data structure (including the header)
 *  is also stored here (in bytes).
 */
typedef struct emc_log_header {
  len_prio_id_t    len_prio_id; /**< merge of length, priority and length into one word32 */
  emc_std_intptr_t log_count;   /**< the unique log count of this message */
  emc_std_uint64_t timestamp;   /**< the global timestamp for this message */
  unsigned long    line;        /**< the line number from the macro of this message */
  const void*      self;        /**< the this pointer of the object sending the message or the program_count */
  const char*      func;        /**< the name of the function sending the message */
  const char*      classname;   /**< the name of the class sending the message or the __FILE__ */
  unsigned long    thread_id;   /**< the id of the thread sending the message */
} emc_log_header_t;             /**< typedef for this structure */

/** Maximum number of data elements a log data object can hold (including the string) */
#define EMC_LOG_DATA_ELEMENT_NUMBER 6

typedef emc_std_uintptr_t emc_log_param_type_t;

/** The log data including the log header.
 *
 *  Consists of LogHeader and
 *  an array of unsigned long for the log parameter.
 *
 *  The array length is MAX_NUMBER_OF_DATA.
 */
typedef struct emc_log_data {
  /// the header structure containing meta-data
  emc_log_header_t header;
  /// the string parameter array
  emc_log_param_type_t data[EMC_LOG_DATA_ELEMENT_NUMBER];
} emc_log_data_t; /**< typedef for the log header */

typedef struct emc_logger emc_logger_t; /**< forwarding typedef for the logger structure */

void emc_logger_log_func(const emc_logger_t* logger, emc_log_data_t* data);

emc_log_data_t* emc_logger_log_data(const emc_logger_t* logger,
                                    unsigned char length,
                                    unsigned char priority);

/** Iterator used by the external API */
typedef struct external_iterator_s {
  emc_logger_t* logger; /**< The wrapped logger handle */
  unsigned long lookup; /**< Lookup value used to iterate over the hierarchy */
} external_iterator_t;  /**< Typedef for convenience */

/** Get a log category (logger) with name @p category */
emc_logger_t* EMC_Log_logger(const char* category);

/** Getter for the root-logger */
emc_logger_t* EMC_Log_root_logger(void);

/** return the logger identified by @p index
    @param index the index runs fro 0 to the number_of_logger -1
    @return 0 if the index is out of range
 */
emc_logger_t* EMC_Log_logger_by_index(unsigned index);

/** Getter for the name of the @p logger (the category) */
const char* EMC_Log_logger_name(const emc_logger_t* logger);

/** Setter to enable the @p logger
 * @param enabled If 0 the logger and all its children are disabled,
 *                in all other cases the logger & its children are enabled.
 * @param logger  is a category.
 */
void EMC_Log_enable(emc_logger_t* logger, unsigned int enabled);
/** Getter to retrieve the enabled status of the @p logger */
unsigned int EMC_Log_is_enabled(const emc_logger_t* logger);

/** Setter to enable the timestamp of the @p logger
 * @param enabled If 0 the logger does not use timestamps,
 *                in all other cases the logger uses timestamps.
 * @param recursive If != 0 the setting is propagated recursively
 * @param logger  is a category.
 *
 */
void EMC_Log_enable_timestamp(emc_logger_t* logger,
                              unsigned int enabled,
                              unsigned int recursive);
/** Getter to retrieve the timestamp status of the @p logger */
unsigned int EMC_Log_is_timestamp_enabled(const emc_logger_t* logger);

/** Getter to retrieve the current logcount of @p logger */
unsigned int EMC_Log_log_count(const emc_logger_t* logger);

/** Setter for the priority of the @p logger
 * @param priority The new priority the logger will use to dynamically filter the log messages.
 * @param logger it is a category.
 * Note: If a log priority has been disabled at compile time, it cannot be enabled at runtime.
 */
void EMC_Log_set_priority(emc_logger_t* logger, unsigned int priority);
/** Getter to retrieve the priority active for this @p logger */
unsigned int EMC_Log_priority(const emc_logger_t* logger);

/** provide the logger info of logger */
emc_std_size_t EMC_Log_logger_info(emc_logger_t* logger, char* buffer, emc_std_size_t buffer_size);

/*lint -emacro(506, EMC_LOG5, EMC_LOG4, EMC_LOG3, EMC_LOG2, EMC_LOG1, EMC_LOG, EMC_FUNCTION) */
/*lint -emacro(571, EMC_LOG5, EMC_LOG4, EMC_LOG3, EMC_LOG2, EMC_LOG1, EMC_LOG, EMC_FUNCTION) */

#if EMC_LOG_LOGGING_VARIANT == EMC_LOG_LOGGING_NONE
#  include "emc/log/log_none.h"
#endif

#if (EMC_LOG_LOGGING_VARIANT == EMC_LOG_LOGGING_INTERNAL) || (EMC_LOG_LOGGING_VARIANT == EMC_LOG_LOGGING_EMCPP)
#  include "emc/log/log_internal.h"
#endif

#if EMC_LOG_LOGGING_VARIANT == EMC_LOG_LOGGING_KPRINT
#  include "emc/log/log_kprint.h"
#endif

#if EMC_LOG_LOGGING_VARIANT == EMC_LOG_LOGGING_CUSTOMER
#  include "emc/log/log_customer.h"
#endif

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
}
#endif
// clang-format on extern C

#endif /* EMC_LOG_log_H */
