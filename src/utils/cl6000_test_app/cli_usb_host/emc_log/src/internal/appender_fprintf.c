#include "emc/log/internal/appender_fprintf.h"
#include "emc/log/internal/logger.h"
#include "emc/std/ext/timestamp.h"
#include "emc/std/string.h"
#if EMC_LOG_INTERNAL_USES_TIMESTAMP
#  include "emc/std/time.h"
#endif

#include <stdio.h>

typedef struct emc_log_appender_context {
  emc_log_appender appender;
  emc_log_data_t   data;
  FILE*            file;
} emc_log_appender_context;

static unsigned mg_instance_count = 0;

static emc_log_appender_context mg_instance[EMC_LOG_INTERNAL_APPENDER_PRINTF_INSTANCES];

static emc_log_appender_context* allocate_context(void)
{
  unsigned count = mg_instance_count++;
  return (count < EMC_LOG_INTERNAL_APPENDER_PRINTF_INSTANCES) ? &mg_instance[count] : EMC_STD_NULL;
}

static emc_log_data_t* next_record(void* context)
{
  emc_log_appender_context* self = (emc_log_appender_context*)(context);
  emc_log_data_t*           record = &self->data;
  emc_std_memset(record, 0, sizeof(emc_log_data_t));
  return record;
}

static void print_priority(FILE* file, EMC_LOG_Priorities prio)
{
  static const char* const priority_colors[] = {
    "\033[0m",
    "\033[1;33;41m",
    "\033[1;37;41m",
    "\033[0;31m",
    "\033[0;32m",
    "\033[0;35m",
    "\033[0;34m",
    "\033[0m"
  };

  fprintf(file, "%s[%s]\033[0m ",
          priority_colors[prio],
          EMC_Log_priority_as_string(prio));
}

/** The minimum operator */
#ifndef MIN_OF
#  define MIN_OF(a, b)     ((a) > (b) ? (b) : (a))
#endif

/** The maximum operator */
#ifndef MAX_OF
#  define MAX_OF(a, b)     ((a) > (b) ? (a) : (b))
#endif

#define NAME_WIDTH_MIN 18
#define NAME_WIDTH_MAX 32

#if EMC_LOG_USES_HASH
static void print_hash(FILE* file, const emc_log_header_t* header)
{
  fprintf(file, "<\033[36m%05u\033[0m> ", header->len_prio_id.id);
}

#else /*EMC_LOG_USES_HASH*/

static void print_name(FILE* file, emc_std_string_view name)
{
  int width = (int)MIN_OF(name.length, NAME_WIDTH_MAX);

  if (width) {
    fprintf(file, "<\033[36m");
    if (name.data) {
      fprintf(file, "%.*s", width, name.data);
    }
    if (NAME_WIDTH_MAX < name.length) {
      fprintf(file, "..");
    } else if (NAME_WIDTH_MIN > width) {
      fprintf(file, "%*s", NAME_WIDTH_MIN - width, " ");
    }
    fprintf(file, "\033[0m> ");
  }
}

#endif /*EMC_LOG_USES_HASH*/

static void print_progress(FILE* file, const emc_log_header_t* header)
{
  fprintf(file, "(%d", (int)header->log_count);
#if EMC_LOG_INTERNAL_USES_TIMESTAMP
  {
    char buff[100];

    time_t sec = (time_t)((timestamp_t)(header->timestamp) / emc_timestamp_ticks_per_second());
    long   usec = (long)((timestamp_t)header->timestamp % emc_timestamp_ticks_per_second());

    strftime(buff, sizeof(buff), "%D %T", localtime(&sec));
    fprintf(file, "-%s.%09ld", buff, usec);
  }
#endif /*EMC_LOG_INTERNAL_USES_TIMESTAMP*/
  fprintf(file, ") ");
}

static void print_location(FILE* file, const emc_log_header_t* header)
{
  if (header->classname) {
    fprintf(file, "\033[0;33m%s\033[0m() at \033[0;32m%s\033[0m:%lu: ",
            header->func, header->classname, header->line);
  } else {
    fprintf(file, "%s at (%lu): ",
            header->func, header->line);
  }
}

static void output(void* context, const emc_logger_t* logger, emc_log_data_t* data)
{
  emc_log_appender_context* self = (emc_log_appender_context*)(context);

  UNUSED_PARAM(logger);

  print_priority(self->file, data->header.len_prio_id.prio);
  print_progress(self->file, &data->header);
#if EMC_LOG_USES_HASH
  print_hash(self->file, &data->header);
#else
  print_name(self->file, logger->name);
#endif
  print_location(self->file, &data->header);

  fprintf(self->file,
          (const char*)data->data[0],
          data->data[1], data->data[2], data->data[3], data->data[4], data->data[5]);

  fprintf(self->file, "\n");
}

static const emc_log_appender_ftbl ftbl = {
  "fprintf", &next_record, &output
};

static void init_context(emc_log_appender_context* self, FILE* file)
{
  if (self) {
    self->appender.ftbl = &ftbl;
    self->appender.context = self;
    self->file = file;
  }
}

emc_log_appender* emc_log_appender_fprintf(FILE* file)
{
  emc_log_appender_context* self = allocate_context();
  init_context(self, file);
  return &self->appender;
}
