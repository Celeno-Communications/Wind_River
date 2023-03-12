#include "emc/log/internal/appender_null.h"
#include "emc/log/internal/appender.h"
#include "emc/std/stddef.h"

static emc_log_data_t* next_record(void* context)
{
  UNUSED_PARAM(context);
  return EMC_STD_NULL;
}

static void output(void* context, const emc_logger_t* logger, emc_log_data_t* data)
{
  UNUSED_PARAM(context);
  UNUSED_PARAM(logger);
  UNUSED_PARAM(data);
}

static const emc_log_appender_ftbl ftbl = {
  "null", &next_record, &output
};

static emc_log_appender mg_instance;

emc_log_appender* emc_log_appender_null()
{
  mg_instance.ftbl = &ftbl;
  mg_instance.context = EMC_STD_NULL;

  return &mg_instance;
}
