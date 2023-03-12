#include "emc/log/log.h"
#include "emc/log/internal/logger.h"
#include "emc/log/internal/appender.h"
#include "emc/log/internal/appender_null.h"
#include "emc/std/string.h"
#include "emc/std/stdatomic.h"
#include "emc/std/assert.h"
#include "emc/std/ext/bitoperation.h"
#include "emc/log/internal/timestamp.h"
#include "emc/std/stdio.h"
#include "emc/std/ext/stdlib.h"
#include "emc/std/ext/memcpy.h"

#define EMC_LOG_FLAG_PRIORITY_SET 0
#define EMC_LOG_FLAG_APPENDER_SET 1

#ifndef EMC_LOG_DEBUG
#  define EMC_LOG_DEBUG 0
#endif

#if EMC_LOG_DEBUG
#  include <stdio.h>
#endif

EMC_STATIC_LOG_LEVEL_DEFINE(EMC_LOG_LEVEL);

static emc_std_atomic_intptr_t mg_emc_log_count;

static emc_logger_t mg_logger_instance[EMC_LOG_INTERNAL_INSTANCES];

static emc_std_atomic_intptr_t mg_logger_instance_count;

static emc_logger_t* mg_root_logger = 0;

static emc_logger_t* allocate_logger(void)
{
  emc_std_intptr_t count =
    emc_std_atomic_fetch_add_explicit(&mg_logger_instance_count, 1, emc_std_memory_order_acquire);
  return (count < EMC_LOG_INTERNAL_INSTANCES) ? &mg_logger_instance[count] : EMC_STD_NULL;
}

static emc_logger_t* first_logger(void)
{
  return &mg_logger_instance[0];
}

static emc_logger_t* last_logger(void)
{
  emc_std_intptr_t count = emc_std_atomic_load_explicit(&mg_logger_instance_count, emc_std_memory_order_acquire);
  return (count < EMC_LOG_INTERNAL_INSTANCES)
         ? &mg_logger_instance[count] : &mg_logger_instance[EMC_LOG_INTERNAL_INSTANCES - 1];
}

static emc_logger_t* find_logger(emc_std_string_view name_view)
{
  /* The current implementation is simple linear search.
     Here we may improve with a recursive dfs search */

  emc_logger_t* logger;
  emc_logger_t* first = first_logger();
  emc_logger_t* last = last_logger();

  for (logger = first; logger != last; ++logger) {
    if (emc_std_string_view_equal(&logger->name, &name_view)) {
      return logger;
    }
  }
  return EMC_STD_NULL;
}

static void append_logger(emc_logger_t* parent, emc_logger_t* child)
{
  emc_std_assert(parent);
  emc_std_assert(child);

  child->parent = parent;
  if (parent->last_child) {
    child->next = parent->last_child->next;
    parent->last_child->next = child;
    parent->last_child = child;
  } else {
    child->next = child;
    parent->last_child = child;
  }
}

static inline emc_std_uint16_t compute_id(const emc_logger_t* logger)
{
  return (emc_std_uint16_t)(logger - first_logger());
}

static void init_logger(emc_logger_t* logger, emc_logger_t* parent, emc_std_string_view name_view)
{
#if EMC_LOG_DEBUG
  fprintf(stderr, "init ####%.*s####\n", (int)name_view.length, name_view.data);
#endif
  emc_std_memset(logger, 0, sizeof(emc_logger_t));
  logger->priority = EMC_LOG_PRIORITY_OFF;
  /* this should be implicit 0 by memset above */
  emc_set_bit32(&logger->flags, EMC_LOG_FLAG_PRIORITY_SET, emc_std_false);
  emc_set_bit32(&logger->flags, EMC_LOG_FLAG_APPENDER_SET, emc_std_false);
  logger->name = name_view;
  logger->hash = compute_id(logger);
  if (parent) {
    logger->priority = parent->priority;
    logger->appender = parent->appender;
#if EMC_LOG_DEBUG
    fprintf(stderr, "init parent ####%.*s####\n", (int)parent->name.length, parent->name.data);
#endif
    append_logger(parent, logger);
  } else {
#if EMC_LOG_DEBUG
    fprintf(stderr, "init no parent\n");
#endif
  }
}

static emc_logger_t* create_logger(emc_std_string_view name_view);

static emc_logger_t* parent_logger(emc_std_string_view name_view)
{
  emc_logger_t*       parent;
  emc_std_string_view parent_name;
  emc_std_size_t      split_pos = emc_std_string_view_rfind(&name_view, '.');
  if ((split_pos == 0) || (split_pos > name_view.length)) {
    parent = EMC_Log_root_logger();
  } else {
    emc_std_string_view_init_range(&parent_name, name_view.data, &name_view.data[split_pos]);
    parent = find_logger(parent_name);
    if (!parent) {
      parent = create_logger(parent_name);
    }
  }
  return parent;
}

static emc_logger_t* create_logger(emc_std_string_view name_view)
{
  emc_logger_t* logger;
  emc_logger_t* parent = parent_logger(name_view);

  logger = allocate_logger();
  if (logger) {
    init_logger(logger, parent, name_view);
  } else {
    /* as fallback use the parent logger */
    if (parent) {
      logger = parent;
    }
  }
  return logger;
}

emc_logger_t* EMC_Log_logger_by_index(unsigned index)
{
  emc_std_intptr_t count = emc_std_atomic_load_explicit(&mg_logger_instance_count, emc_std_memory_order_acquire);
  if (index < (unsigned)count) {
    return &mg_logger_instance[index];
  } else {
    return EMC_STD_NULL;
  }
}

static emc_std_size_t emc_min(emc_std_size_t a, emc_std_size_t b)
{ return (a < b) ? a : b; }

static char* put_string_view(char* begin, const char* end, const char* str, emc_std_size_t str_len)
{
  if (str && str_len && end && begin) {
    emc_std_size_t length = str_len;
    emc_std_size_t remaining = (emc_std_size_t)(end - begin);
    emc_std_size_t copy_length = emc_min(length, remaining);

    emc_std_ext_memcpy(begin, str, copy_length);
    return begin + copy_length;
  } else {
    return begin;
  }
}

static char* put_string(char* begin, const char* end, const char* str)
{
  if (str) {
    return put_string_view(begin, end, str, emc_std_strlen(str));
  } else {
    return begin;
  }
}

static char* put_dec(char* begin, const char* end, unsigned i)
{
  char buffer[12];
  return put_string(begin, end, emc_std_itoa((int)i, buffer, 10));
}

emc_std_size_t EMC_Log_logger_info(emc_logger_t* logger, char* buffer, emc_std_size_t buffer_size)
{
  emc_std_size_t length = 0;
  if (logger && buffer && (buffer_size > 0)) {
    char*       insert = buffer;
    const char* end = buffer + buffer_size - 1; /* ensure space for '\0' at the end*/

    insert = put_string(insert, end, "<logger id=\"");
    insert = put_dec(insert, end, logger->hash);
    insert = put_string(insert, end, "\" name=\"");
    insert = put_string_view(insert, end, logger->name.data, logger->name.length);
    insert = put_string(insert, end, "\" prio=\"");
    insert = put_string(insert, end, EMC_Log_priority_as_string(logger->priority));
    insert = put_string(insert, end, "\" prio_val=\"");
    insert = put_dec(insert, end, (unsigned)logger->priority);
    insert = put_string(insert, end, "\" prio_set=\"");
    insert = put_dec(insert, end, emc_test_bit32(logger->flags, EMC_LOG_FLAG_PRIORITY_SET));
    insert = put_string(insert, end, "\" appender=\"");
    if (logger->appender) {
      insert = put_string(insert, end, logger->appender->ftbl->name);
    }
    insert = put_string(insert, end, "\" appender_set=\"");
    insert = put_dec(insert, end, emc_test_bit32(logger->flags, EMC_LOG_FLAG_APPENDER_SET));
    insert = put_string(insert, end, "\"/>");
    *insert++ = '\0';
    length = (emc_std_size_t)(insert - buffer);
  }
  return length;
}

unsigned int EMC_Log_log_count(const emc_logger_t* logger)
{
  UNUSED_PARAM(logger);
  return (unsigned int)emc_std_atomic_load_explicit(&mg_emc_log_count, emc_std_memory_order_acquire);
}

emc_log_data_t* emc_logger_log_data(const emc_logger_t* logger,
                                    uint8_t length,
                                    uint8_t priority)
{
  emc_log_data_t* record = EMC_STD_NULL;

  if (logger && (logger->priority >= priority)) {
    emc_std_intptr_t log_count = emc_std_atomic_fetch_add_explicit(&mg_emc_log_count, 1, emc_std_memory_order_acquire);

    /*
       It is by convention, that every logger has an appender and every appender has a record function.
       That's why no pointer check will be done for performance reasons.
       assert(logger->appender);
       assert(logger->appender->record);
     */
    record = (logger->appender->ftbl->record)(logger->appender->context);

    if (record) {
      /*
         To avoid time consuming operations no cleanup will be done here.
         This will not lead to uninitialized memory as long as the log memory was initialized at start time
         and the records have fixed size.

         If necessary to initialize and memset should be avoided, set only the attributes originally set outside in the
            LOG MACROS.
       #if EMC_LOG_INTERNAL_USES_PC
          record->func = 0;
          record->line = 0;
          record->classname = 0;
       #elif EMC_LOG_INTERNAL_USES_FILE
          record->self = 0;
       #else
          record->self = 0;
       #endif
          record->thread_id = 0;
       */

      record->header.len_prio_id.len = length;
      record->header.len_prio_id.prio = priority;
      record->header.len_prio_id.id = logger->hash;
      record->header.log_count = log_count;
      record->header.timestamp = EMC_LOG_TIMESTAMP();
    }
  }
  return record;
}

void emc_logger_log_func(const emc_logger_t* logger, emc_log_data_t* data)
{
  /* It can be assumed, that there is a logger, when this function is called.
     Because this was allready checked by the emc_logger_log_data.
     It is also by convention, that every logger has an appender and every appender has an output function.
     That's why no pointer check will be done for performance reasons.

     assert(logger);
     assert(logger->appender);
     assert(logger->appender->output);
   */
  (*logger->appender->ftbl->output)(logger->appender->context, logger, data);
}

#define _EMC_LOG_LEVEL_DEFINE(prio)                              \
  (EMC_LOG_PRIORITY_ ## prio)

#define EMC_LOG_LEVEL_DEFINE(prio) \
  _EMC_LOG_LEVEL_DEFINE(prio)

emc_logger_t* EMC_Log_root_logger(void)
{
  if (!mg_root_logger) {
    emc_logger_t*       logger;
    emc_std_string_view name_view;

    emc_std_atomic_init(&mg_emc_log_count, 0);
    emc_std_atomic_init(&mg_logger_instance_count, 0);
    logger = allocate_logger();
    emc_std_string_view_init(&name_view, "");
    init_logger(logger, EMC_STD_NULL, name_view);
    /* this may be changed later to enforce explicit set_priority for root_logger */
    EMC_Log_set_priority(logger, EMC_LOG_LEVEL_DEFINE(EMC_LOG_LEVEL));
    EMC_Log_logger_set_appender(logger, emc_log_appender_null());
    mg_root_logger = logger;
    EMC_LOG(mg_root_logger, INFO, "logging initialized: "__DATE__ "-" __TIME__);
  }

  return mg_root_logger;
}

emc_logger_t* EMC_Log_logger(const char* category)
{
  emc_logger_t*       logger;
  emc_std_string_view name_view;
  emc_std_string_view_init(&name_view, category);
  logger = find_logger(name_view);
  if (!logger) {
    logger = create_logger(name_view);
    if (!logger) {
      logger = EMC_Log_root_logger(); /* ensure creation of root logger */
    }
  }
  return logger;
}

/* dfs until first explicit priority_set found */
static void update_priority(emc_logger_t* logger, unsigned int priority)
{
  emc_logger_t* first = 0;
  emc_logger_t* last = 0;
  emc_logger_t* child = 0;

  logger->priority = priority;

  last = logger->last_child;
  if (last) {
    first = last->next;
    child = first;
    do {
      /* the assumption is, that all loggers below that have an explicitly set appender are updated */
      if (!emc_test_bit32(child->flags, EMC_LOG_FLAG_PRIORITY_SET)) {
        update_priority(child, priority);
      }
      child = child->next;
    } while (child != first);
  }
}

void EMC_Log_set_priority(emc_logger_t* logger, unsigned int priority)
{
  if (logger) {
    emc_set_bit32(&logger->flags, EMC_LOG_FLAG_PRIORITY_SET, emc_std_true);
    update_priority(logger, priority);
  }
}

unsigned int EMC_Log_priority(const emc_logger_t* logger)
{
  if (logger) {
    return logger->priority;
  } else {
    return EMC_LOG_PRIORITY_OFF;
  }
}

/* dfs until first explicit appender_set found */
static void update_appender(emc_logger_t* logger, emc_log_appender* appender)
{
  emc_logger_t* first = 0;
  emc_logger_t* last = 0;
  emc_logger_t* child = 0;

  logger->appender = appender;

  last = logger->last_child;
  if (last) {
    first = last->next;
    child = first;
    do {
      /* the assumption is, that all loggers below an explicitly set appender are updated */
      if (!emc_test_bit32(child->flags, EMC_LOG_FLAG_APPENDER_SET)) {
        update_appender(child, appender);
      }
      child = child->next;
    } while (child != first);
  }
}

void EMC_Log_logger_set_appender(emc_logger_t* logger, emc_log_appender* appender)
{
  if (logger && appender) {
    emc_set_bit32(&logger->flags, EMC_LOG_FLAG_APPENDER_SET, emc_std_true);
    update_appender(logger, appender);
  }
}

emc_log_appender* EMC_Log_logger_appender(emc_logger_t* logger)
{
  return logger ? logger->appender : 0;
}

void EMC_Log_logger_print(emc_logger_t* logger)
{
#if EMC_LOG_DEBUG
  emc_logger_t* first = 0;
  emc_logger_t* last = 0;
  emc_logger_t* child = 0;

  unsigned        i;
  static unsigned indent_level = 0;
  if (logger == mg_root_logger) {
    indent_level = 0;
  }

  for (i = 0; i < indent_level; ++i) {
    fprintf(stderr, "   ");
  }
  fprintf(stderr, "name:\"%.*s\",prio=%s(set:%d)", (int)logger->name.length, logger->name.data,
          EMC_Log_priority_as_string(logger->priority),
          emc_test_bit32(logger->flags, EMC_LOG_FLAG_PRIORITY_SET));
  fprintf(stderr, " appender=\"%s\"(set:%d)", logger->appender->ftbl->name,
          emc_test_bit32(logger->flags, EMC_LOG_FLAG_APPENDER_SET));
  fprintf(stderr, "\n");

  indent_level++;

  last = logger->last_child;
  if (last) {
    first = last->next;
    child = first;
    do {
      EMC_Log_logger_print(child);
      child = child->next;
    } while (child != first);
  }

  indent_level--;
#else
  UNUSED_PARAM(logger);
#endif
}
