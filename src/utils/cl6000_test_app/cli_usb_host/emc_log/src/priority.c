#include "emc/log/priority.h"
#include "emc/std/string.h"

EMC_LOG_Priorities EMC_Log_priority_from_string(const char* name)
{
  EMC_LOG_Priorities result;
  if (name == 0) {
    result = EMC_LOG_PRIORITY_OFF;
  } else if (emc_std_strcmp(name, "OFF") == 0) {
    result = EMC_LOG_PRIORITY_OFF;
  } else if (emc_std_strcmp(name, "FATAL") == 0) {
    result = EMC_LOG_PRIORITY_FATAL;
  } else if (emc_std_strcmp(name, "ERROR") == 0) {
    result = EMC_LOG_PRIORITY_ERROR;
  } else if (emc_std_strcmp(name, "WARN") == 0) {
    result = EMC_LOG_PRIORITY_WARN;
  } else if (emc_std_strcmp(name, "INFO") == 0) {
    result = EMC_LOG_PRIORITY_INFO;
  } else if (emc_std_strcmp(name, "DEBUG") == 0) {
    result = EMC_LOG_PRIORITY_DEBUG;
  } else if (emc_std_strcmp(name, "TRACE") == 0) {
    result = EMC_LOG_PRIORITY_TRACE;
  } else {
    result = EMC_LOG_PRIORITY_OFF;
  }
  return result;
}

const char* EMC_Log_priority_as_string(EMC_LOG_Priorities priority)
{
  static const char* const names[] = {
    "OFF  ",
    "FATAL",
    "ERROR",
    "WARN ",
    "INFO ",
    "DEBUG",
    "TRACE",
    "ALL  "
  };

  return names[priority];
}
