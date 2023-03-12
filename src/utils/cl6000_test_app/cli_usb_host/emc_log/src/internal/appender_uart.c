/**
 * @file
 *
 * @author  Ralf Oberländer
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/log/internal/appender_uart.h"
#include "emc/log/internal/logger.h"

#include "emc/log/log.h"
#include "emc/std/string.h"
#include "emc/std/stdatomic.h"
#include "emc/std/ext/timestamp.h"
#include "external/snprintf/printf.h"

extern void sendString(const char* s);

static emc_log_data_t mg_log_data;

static emc_log_data_t* next_record(void* context)
{
  emc_log_data_t* record = &mg_log_data;
  UNUSED_PARAM(context);

  emc_std_memset(record, 0, sizeof(emc_log_data_t));
  return record;
}

static void output(void* context, const emc_logger_t* logger, emc_log_data_t* data)
{
  char string_buffer[128];

  UNUSED_PARAM(context);
  snprintf_(&string_buffer[0],
            sizeof(string_buffer),
            "[%s] (%04u)",
            EMC_Log_priority_as_string(data->header.len_prio_id.prio),
            data->header.log_count);
  sendString(&string_buffer[0]);

  snprintf_(&string_buffer[0],
            sizeof(string_buffer),
            " [%8d] ",
            data->header.timestamp);
  sendString(&string_buffer[0]);

  snprintf_(&string_buffer[0],
            sizeof(string_buffer),
            "%s(%lu): ",
            data->header.func,
            data->header.line);
  sendString(&string_buffer[0]);

  snprintf_(&string_buffer[0],
            sizeof(string_buffer),
            (const char*)data->data[0],
            data->data[1],
            data->data[2],
            data->data[3],
            data->data[4],
            data->data[5]);
  sendString(&string_buffer[0]);

  snprintf_(&string_buffer[0], sizeof(string_buffer), "\n\r");
  sendString(&string_buffer[0]);

  UNUSED_PARAM(logger);
}

static const emc_log_appender_ftbl ftbl = {
  "uart", &next_record, &output
};

static emc_log_appender mg_instance = {
  &ftbl, &mg_instance
};

emc_log_appender* emc_log_appender_uart()
{
  return &mg_instance;
}
