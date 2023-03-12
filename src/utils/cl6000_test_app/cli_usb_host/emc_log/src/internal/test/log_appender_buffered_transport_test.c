/**
 * @file
 * @brief
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/log/log.h"
#include "emc/log/internal/logger.h"
#include "emc/log/internal/appender_buffered_transport.h"

#include "emc/test/unittest.h"
#include "emc/std/stdbool.h"
#include "emc/std/string.h"

#define MEM1_ITEMS 20
static emc_log_data_t mem1[MEM1_ITEMS];

EMC_STATIC_LOG_LEVEL_DEFINE(EMC_LOG_LEVEL);
static emc_log_appender* mg_appender = 0;
static emc_std_uintptr_t mg_lock_context;

static int lock_func(void* context)
{
  emc_std_uintptr_t* ctx = (emc_std_uintptr_t*)context;
  ++(*ctx);
  return 0;
}

static int unlock_func(void* context)
{
  emc_std_uintptr_t* ctx = (emc_std_uintptr_t*)context;
  --(*ctx);
  return 0;
}

void setUp(void)
{
  emc_log_lock_t sync;

  emc_std_memset(mem1, 0, sizeof(mem1));

  mg_appender = emc_log_appender_buffered_transport(mem1, sizeof(mem1));

  sync.lock = lock_func;
  sync.unlock = unlock_func;
  sync.context = &mg_lock_context;
  mg_lock_context = 0;
  emc_log_appender_buffered_transport_set_synchronization(mg_appender, &sync);
}

void tearDown(void)
{
  emc_log_appender_buffered_transport_set_synchronization(mg_appender, 0);
}

static void reset_appender(void)
{
  emc_log_appender_buffered_transport_set_send_func(mg_appender, 0, 0);

  emc_log_appender_buffered_transport_flush(mg_appender);
  emc_log_appender_buffered_transport_flush(mg_appender);
}

// clang-format off

EMC_CUNIT_START_TEST(log_appender_buffered_transport_test_create)
{
  emc_std_uint32_t idx;
  emc_log_appender* appender;

  EMC_CUNIT_ASSERT(mg_appender != EMC_STD_NULL);

  for (idx = 1; idx < EMC_LOG_INTERNAL_APPENDER_BUFFERED_TRANSPORT_INSTANCES; ++idx) {
    appender = emc_log_appender_buffered_transport(mem1, sizeof(mem1));
    EMC_CUNIT_ASSERT(appender != EMC_STD_NULL);
  }

  appender = emc_log_appender_buffered_transport(mem1, sizeof(mem1));
  EMC_CUNIT_ASSERT(appender == EMC_STD_NULL);
}
EMC_CUNIT_END_TEST

typedef struct {
  emc_std_uint32_t magic;
  emc_std_size_t size;
  emc_log_param_type_t param[MEM1_ITEMS];

  EMC_LOG_APPENDER_BUFFERED_TRANSPORT_complete_func* cb;
  void* cb_context;

} send_context;

void send_func(void* context, void* mem, emc_std_size_t size, EMC_LOG_APPENDER_BUFFERED_TRANSPORT_complete_func* cb, void* cb_context)
{
  send_context* ctx = (send_context*)context;
  emc_log_data_t* log = (emc_log_data_t*)mem;
  emc_std_size_t idx;

  ctx->magic = 0xBABEFACE;
  ctx->size = size;
  for (idx = 0; idx < size / sizeof(emc_log_data_t); ++idx) {
    ctx->param[idx] = log->data[1];
    ++log;
  }
  ctx->cb = cb;
  ctx->cb_context = cb_context;
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(log_appender_buffered_transport_test_flush)
{
  emc_std_size_t runs;
  emc_std_size_t run;
  emc_std_size_t flush_interval;
  emc_std_bool wrap;
  emc_std_size_t overlap;
  emc_std_size_t expected;
  emc_std_size_t i;
  send_context ctx;
  emc_logger_t* logger = EMC_Log_logger("emc.live");
  EMC_Log_logger_set_appender(logger, mg_appender);

  reset_appender();

  emc_log_appender_buffered_transport_set_send_func(mg_appender, send_func, &ctx);

  ctx.magic = 0xDEADBEEF;
  emc_log_appender_buffered_transport_flush(mg_appender);
  EMC_CUNIT_ASSERT(ctx.magic == 0xDEADBEEF);

  flush_interval = 3;
  runs = flush_interval * (sizeof(mem1) / sizeof(emc_log_data_t));
  wrap = emc_std_false;
  expected = 0;
  for (run = 1; run <= runs; ++run) {
    EMC_LOG1(logger, ERROR, "Log message %u", run);

    if ((run > 1) && 0 == ((run - 1) % MEM1_ITEMS)) {
      wrap = emc_std_true;
    }
    overlap = run % MEM1_ITEMS;

    if (0 == (run % flush_interval)) {
      ctx.magic = 0xDEADBEEF;
      ctx.size = 0;
      emc_std_memset(ctx.param, 0, sizeof(ctx.param));
      ctx.cb = 0;
      ctx.cb_context = 0;

      emc_log_appender_buffered_transport_flush(mg_appender);
      EMC_CUNIT_ASSERT(ctx.magic == 0xBABEFACE);
      expected += flush_interval;
      if (wrap) {
        expected -= overlap;
      }
      if (ctx.size != expected * sizeof(emc_log_data_t)) {
      }
      EMC_CUNIT_ASSERT(ctx.size == expected * sizeof(emc_log_data_t));
      for (i = 0; i < expected; ++i) {
        emc_std_size_t first = (expected > flush_interval) ? (run - expected) + 1 : (run - flush_interval) + 1;
        EMC_CUNIT_ASSERT(ctx.param[i] == first + i);
      }

      if (ctx.cb) {
        ctx.cb(ctx.cb_context, ctx.size);
      }

      expected = (expected < flush_interval) ? (flush_interval - expected) : 0;
      wrap = emc_std_false;
    }
  }

  EMC_CUNIT_ASSERT(0 == mg_lock_context);
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(log_appender_buffered_transport_test_poll_timeout)
{
  send_context ctx;
  timestamp_t now;
  emc_logger_t* logger = EMC_Log_logger("emc.live");
  EMC_Log_logger_set_appender(logger, mg_appender);

  reset_appender();

  emc_log_appender_buffered_transport_set_send_func(mg_appender, send_func, &ctx);

  now = emc_timestamp();
  EMC_LOG(logger, ERROR, "Log message");

  ctx.magic = 0xDEADBEEF;
  ctx.size = 0;
  ctx.cb = 0;
  ctx.cb_context = 0;

  emc_log_appender_buffered_transport_poll(mg_appender, now + 10000);
  EMC_CUNIT_ASSERT(ctx.magic == 0xDEADBEEF);

  emc_log_appender_buffered_transport_set_timeout(mg_appender, 2000);

  emc_log_appender_buffered_transport_poll(mg_appender, now);
  EMC_CUNIT_ASSERT(ctx.magic == 0xDEADBEEF);

  emc_log_appender_buffered_transport_poll(mg_appender, now + 10000);
  EMC_CUNIT_ASSERT(ctx.magic == 0xBABEFACE);
  EMC_CUNIT_ASSERT(ctx.size == sizeof(emc_log_data_t));

  if (ctx.cb) {
    ctx.cb(ctx.cb_context, ctx.size);
  }

  EMC_CUNIT_ASSERT(0 == mg_lock_context);
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(log_appender_buffered_transport_test_poll_threshold)
{
  send_context ctx;
  timestamp_t now;
  emc_logger_t* logger = EMC_Log_logger("emc.live");
  EMC_Log_logger_set_appender(logger, mg_appender);

  reset_appender();

  emc_log_appender_buffered_transport_set_send_func(mg_appender, send_func, &ctx);

  now = emc_timestamp();
  EMC_LOG(logger, ERROR, "Log message");

  ctx.magic = 0xDEADBEEF;
  ctx.size = 0;
  ctx.cb = 0;
  ctx.cb_context = 0;

  emc_log_appender_buffered_transport_poll(mg_appender, now);
  EMC_CUNIT_ASSERT(ctx.magic == 0xDEADBEEF);

  emc_log_appender_buffered_transport_set_threshold(mg_appender, 2);

  emc_log_appender_buffered_transport_poll(mg_appender, now);
  EMC_CUNIT_ASSERT(ctx.magic == 0xDEADBEEF);

  EMC_LOG(logger, ERROR, "Log message");
  emc_log_appender_buffered_transport_poll(mg_appender, now);
  EMC_CUNIT_ASSERT(ctx.magic == 0xBABEFACE);
  EMC_CUNIT_ASSERT(ctx.size == 2 * sizeof(emc_log_data_t));

  if (ctx.cb) {
    ctx.cb(ctx.cb_context, ctx.size);
  }

  EMC_CUNIT_ASSERT(0 == mg_lock_context);

}
EMC_CUNIT_END_TEST

static void test_overflow(EMC_LOG_AppenderBufferPolicy policy)
{
  send_context ctx;
  emc_std_size_t run;
  emc_std_size_t discard;
  emc_std_size_t size[2] = {0, 0};
  emc_std_size_t idx;

  emc_logger_t* logger = EMC_Log_logger("emc.live");
  EMC_Log_logger_set_appender(logger, mg_appender);

  emc_log_appender_buffered_transport_set_send_func(mg_appender, send_func, &ctx);

  ctx.magic = 0xDEADBEEF;
  ctx.size = 0;
  ctx.cb = 0;
  ctx.cb_context = 0;

  discard = 2;
  for (run = 0; run < MEM1_ITEMS + discard; ++run) {
    EMC_LOG1(logger, ERROR, "Log message %u", run);
  }
  EMC_CUNIT_ASSERT(ctx.magic == 0xDEADBEEF);

  emc_log_appender_buffered_transport_flush(mg_appender);
  EMC_CUNIT_ASSERT(ctx.magic == 0xBABEFACE);
  EMC_CUNIT_ASSERT(ctx.size > 0);
  EMC_CUNIT_ASSERT(ctx.size <= MEM1_ITEMS * sizeof(emc_log_data_t));

  run = (EMC_LOG_APPENDER_BUFFER_POLICY_Discard == policy) ? 0 : discard;
  for (idx = 0; idx < ctx.size / sizeof(emc_log_data_t); ++idx, ++run) {
    EMC_CUNIT_ASSERT(ctx.param[idx] == run);
  }
  size[0] = ctx.size;

  if (ctx.cb) {
    ctx.cb(ctx.cb_context, ctx.size);
  }

  // on wrap the logs will come in two sets
  if (size[0] < (MEM1_ITEMS * sizeof(emc_log_data_t))) {
    ctx.magic = 0xDEADBEEF;
    ctx.size = 0;
    ctx.cb = 0;
    ctx.cb_context = 0;

    emc_log_appender_buffered_transport_flush(mg_appender);
    EMC_CUNIT_ASSERT(ctx.magic == 0xBABEFACE);
    EMC_CUNIT_ASSERT(ctx.size == (MEM1_ITEMS  * sizeof(emc_log_data_t)) - size[0]);
    for (idx = 0; idx < ctx.size / sizeof(emc_log_data_t); ++idx, ++run) {
      EMC_CUNIT_ASSERT(ctx.param[idx] == run);
    }
    size[1] = ctx.size;

    if (ctx.cb) {
      ctx.cb(ctx.cb_context, ctx.size);
    }
  }

  EMC_CUNIT_ASSERT(size[0] + size[1] == MEM1_ITEMS * sizeof(emc_log_data_t));
}

EMC_CUNIT_START_TEST(log_appender_buffered_transport_test_policy_overwrite)
{
  reset_appender();

  emc_log_appender_buffered_transport_set_policy(mg_appender, EMC_LOG_APPENDER_BUFFER_POLICY_Overwrite);

  test_overflow(EMC_LOG_APPENDER_BUFFER_POLICY_Overwrite);

  EMC_CUNIT_ASSERT(0 == mg_lock_context);
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(log_appender_buffered_transport_test_policy_discard)
{
  reset_appender();

  emc_log_appender_buffered_transport_set_policy(mg_appender, EMC_LOG_APPENDER_BUFFER_POLICY_Discard);

  test_overflow(EMC_LOG_APPENDER_BUFFER_POLICY_Discard);

  EMC_CUNIT_ASSERT(0 == mg_lock_context);
}
EMC_CUNIT_END_TEST

EMC_CUNIT_TEST_SUITE(log_appender_buffered_transport_test);
EMC_CUNIT_TEST(log_appender_buffered_transport_test_create);
EMC_CUNIT_TEST(log_appender_buffered_transport_test_flush);
EMC_CUNIT_TEST(log_appender_buffered_transport_test_poll_timeout);
EMC_CUNIT_TEST(log_appender_buffered_transport_test_poll_threshold);
EMC_CUNIT_TEST(log_appender_buffered_transport_test_policy_overwrite);
EMC_CUNIT_TEST(log_appender_buffered_transport_test_policy_discard);
EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(log_appender_buffered_transport_test)

EMC_TEST_SUITE_DEFINE_MAIN()

// clang-format on
