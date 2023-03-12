#include "emc/log/internal/appender_buffered_transport.h"
#include "emc/log/log.h"
#include "emc/std/stdbool.h"
#include "emc/std/assert.h"
#include "emc/std/string.h"

typedef emc_log_data_t*(get_record_with_policy)(void* ctx);

typedef struct emc_log_appender_context_t {
  emc_log_appender appender;
  emc_log_data_t*  records;
  emc_std_size_t   number_records;
  emc_std_size_t   log_count;

  emc_std_size_t               threshold;
  timestamp_t                  timeout;
  EMC_LOG_AppenderBufferPolicy policy;
  get_record_with_policy*      policy_get_record;

  emc_std_size_t valid_entries;
  timestamp_t    last_log_ts;

  emc_std_size_t read_count;
  emc_std_bool   is_flushing;

  EMC_LOG_APPENDER_BUFFERED_TRANSPORT_send_func* send_func;
  void*                                          send_context;

  emc_log_lock_t sync;
} emc_log_appender_context;

static unsigned mg_instance_count = 0;

static emc_log_appender_context mg_instance[EMC_LOG_INTERNAL_APPENDER_BUFFERED_TRANSPORT_INSTANCES];

static emc_log_appender_context* allocate_context(void)
{
  unsigned count = mg_instance_count++;
  return (count < EMC_LOG_INTERNAL_APPENDER_BUFFERED_TRANSPORT_INSTANCES) ? &mg_instance[count] : EMC_STD_NULL;
}

static void lock_context(emc_log_appender_context* ctx)
{
  int err = ctx->sync.lock(ctx->sync.context);
  emc_std_assert(!err);
}

static void unlock_context(emc_log_appender_context* ctx)
{
  int err = ctx->sync.unlock(ctx->sync.context);
  emc_std_assert(!err);
}

static emc_log_data_t* get_record_policy_discard(void* ctx)
{
  emc_log_appender_context* self = (emc_log_appender_context*)ctx;
  emc_log_data_t*           record = 0;

  if (self->valid_entries < self->number_records) {
    ++self->valid_entries;
    record = &self->records[self->log_count % self->number_records];
    ++self->log_count;
  }

  return record;
}

static emc_log_data_t* get_record_policy_overwrite(void* ctx)
{
  emc_log_appender_context* self = (emc_log_appender_context*)ctx;
  emc_log_data_t*           record;

  record = &self->records[self->log_count % self->number_records];
  ++self->log_count;
  if (self->valid_entries < self->number_records) {
    ++self->valid_entries;
  } else {
    ++self->read_count;
  }

  return record;
}

static emc_log_data_t* next_record(void* context)
{
  emc_log_appender_context* self = (emc_log_appender_context*)context;
  return self->policy_get_record(self);
}

static void output(void* context, const emc_logger_t* logger, emc_log_data_t* data)
{
  emc_log_appender_context* self = (emc_log_appender_context*)context;
  self->last_log_ts = emc_timestamp();

  UNUSED_PARAM(logger);
  UNUSED_PARAM(data);
}

static const emc_log_appender_ftbl ftbl = {
  "buffered_transport", &next_record, &output
};

static void init_context(emc_log_appender_context* self, void* memory, emc_std_size_t memory_size)
{
  if (self) {
    emc_std_memset(self, 0, sizeof(emc_log_appender_context));
    self->appender.ftbl = &ftbl;
    self->appender.context = self;
    self->records = (emc_log_data_t*)memory; // alignment?
    self->number_records = memory_size / sizeof(emc_log_data_t);

    self->policy = EMC_LOG_APPENDER_BUFFER_POLICY_Overwrite;
    self->policy_get_record = get_record_policy_overwrite;

    emc_log_lock_init(&self->sync);
  }
}

emc_log_appender* emc_log_appender_buffered_transport(void* memory, emc_std_size_t memory_size)
{
  emc_log_appender_context* self = allocate_context();
  init_context(self, memory, memory_size);
  return &self->appender;
}

void emc_log_appender_buffered_transport_set_synchronization(emc_log_appender* self,
                                                             const emc_log_lock_t* sync)
{
  emc_log_appender_context* ctx = (emc_log_appender_context*)self;

  emc_log_lock_init(&ctx->sync);
  if (sync) {
    ctx->sync.lock = sync->lock;
    ctx->sync.unlock = sync->unlock;
    ctx->sync.context = sync->context;
  }
}

void emc_log_appender_buffered_transport_set_send_func(emc_log_appender* self,
                                                       EMC_LOG_APPENDER_BUFFERED_TRANSPORT_send_func* func,
                                                       void* context)
{
  emc_log_appender_context* ctx = (emc_log_appender_context*)self;

  lock_context(ctx);
  ctx->send_func = func;
  ctx->send_context = context;
  unlock_context(ctx);
}

void emc_log_appender_buffered_transport_set_timeout(emc_log_appender* self, timestamp_t timeout)
{
  emc_log_appender_context* ctx = (emc_log_appender_context*)self;

  lock_context(ctx);
  ctx->timeout = timeout;
  unlock_context(ctx);
}

void emc_log_appender_buffered_transport_set_threshold(emc_log_appender* self, emc_std_size_t entries)
{
  emc_log_appender_context* ctx = (emc_log_appender_context*)self;

  lock_context(ctx);
  ctx->threshold = entries;
  unlock_context(ctx);
}

void emc_log_appender_buffered_transport_set_policy(emc_log_appender* self, EMC_LOG_AppenderBufferPolicy policy)
{
  emc_log_appender_context* ctx = (emc_log_appender_context*)self;

  lock_context(ctx);

  ctx->policy = policy;
  switch (ctx->policy) {
  case EMC_LOG_APPENDER_BUFFER_POLICY_Discard:
    ctx->policy_get_record = get_record_policy_discard;
    break;

  case EMC_LOG_APPENDER_BUFFER_POLICY_Overwrite:
  default:
    ctx->policy_get_record = get_record_policy_overwrite;
    break;
  }

  unlock_context(ctx);
}

static void send_completion(void* context, emc_std_size_t size)
{
  emc_log_appender_context* ctx = (emc_log_appender_context*)context;
  emc_std_size_t            entries = size / sizeof(emc_log_data_t);

  lock_context(ctx);
  ctx->read_count += entries;
  ctx->valid_entries -= entries;
  ctx->is_flushing = emc_std_false;
  unlock_context(ctx);
}

static void flush(emc_log_appender_context* self)
{
  if (!self->is_flushing) {
    emc_std_size_t idx_rd = self->read_count % self->number_records;
    emc_std_size_t idx_wr = self->log_count % self->number_records;
    if (self->valid_entries) {
      emc_std_size_t entries;
      if (idx_rd < idx_wr) {
        entries = idx_wr - idx_rd;
      } else {
        // send the first part of the wrapped entries only, next flush will do the rest
        entries = self->number_records - idx_rd;
      }
      if (self->send_func) {
        self->is_flushing = emc_std_true;
        unlock_context(self);
        self->send_func(self->send_context,
                        &self->records[idx_rd], (entries * sizeof(emc_log_data_t)),
                        send_completion, self);
        lock_context(self);
      } else {
        self->read_count += entries;
        self->valid_entries -= entries;
      }
    }
  }
}

void emc_log_appender_buffered_transport_flush(emc_log_appender* self)
{
  emc_log_appender_context* ctx = (emc_log_appender_context*)self;

  lock_context(ctx);
  flush(ctx);
  unlock_context(ctx);
}

void emc_log_appender_buffered_transport_poll(emc_log_appender* self, timestamp_t now)
{
  emc_log_appender_context* ctx = (emc_log_appender_context*)self;

  lock_context(ctx);

  if (ctx->threshold) {
    if (ctx->valid_entries >= ctx->threshold) {
      flush(ctx);
    }
  }
  if (ctx->timeout) {
    timestamp_t diff = emc_timestamp_difference(now, ctx->last_log_ts);
    if (diff > ctx->timeout) {
      flush(ctx);
    }
  }

  unlock_context(ctx);
}
