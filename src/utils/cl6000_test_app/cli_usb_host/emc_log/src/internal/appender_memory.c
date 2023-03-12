#include "emc/log/internal/appender_memory.h"
#include "emc/log/log.h"
#include "emc/std/stdatomic.h"
#include "emc/std/stddef.h"

typedef struct emc_log_appender_context {
  emc_log_appender        appender;
  emc_log_data_t*         records;
  emc_std_size_t          number_records;
  emc_std_atomic_intptr_t log_count;
} emc_log_appender_context;

static unsigned mg_instance_count = 0;

static emc_log_appender_context mg_instance[EMC_LOG_INTERNAL_APPENDER_MEMORY_INSTANCES];

static emc_log_appender_context* allocate_context(void)
{
  unsigned count = mg_instance_count++;
  return (count < EMC_LOG_INTERNAL_APPENDER_MEMORY_INSTANCES) ? &mg_instance[count] : EMC_STD_NULL;
}

static emc_log_data_t* next_record(void* context)
{
  emc_log_appender_context* self = (emc_log_appender_context*)context;
  unsigned                  log_count = (unsigned)emc_std_atomic_fetch_add_explicit(&self->log_count,
                                                                                    1,
                                                                                    emc_std_memory_order_acquire);

  emc_log_data_t* record = &self->records[log_count % self->number_records];
  return record;
}

static void output(void* context, const emc_logger_t* logger, emc_log_data_t* data)
{
  UNUSED_PARAM(context);
  UNUSED_PARAM(logger);
  UNUSED_PARAM(data);
}

static const emc_log_appender_ftbl ftbl = {
  "memory", &next_record, &output
};

static void init_context(emc_log_appender_context* self, void* memory, emc_std_size_t memory_size)
{
  if (self) {
    self->appender.ftbl = &ftbl;
    self->appender.context = self;
    self->records = (emc_log_data_t*)memory; // alignment?
    self->number_records = memory_size / sizeof(emc_log_data_t);

    emc_std_atomic_init(&self->log_count, 0);
  }
}

emc_log_appender* emc_log_appender_memory(void* memory, emc_std_size_t memory_size)
{
  emc_log_appender_context* self = allocate_context();
  init_context(self, memory, memory_size);
  return &self->appender;
}
