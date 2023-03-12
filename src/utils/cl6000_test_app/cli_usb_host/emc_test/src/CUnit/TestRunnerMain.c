#include "emc/test/CUnit/Asserter.h"
#include "emc/test/CUnit/CUnit.h"
#include <stdio.h>
#include <emc/log/log.h>
#if EMC_LOG_LOGGING_VARIANT == EMC_LOG_LOGGING_INTERNAL
#  include "emc/log/internal/logger.h"
#  include "emc/log/internal/appender.h"
#  if EMC_LOG_INTERNAL_APPENDER_PRINTF_INSTANCES > 0
#    include "emc/log/internal/appender_fprintf.h"
#  endif
#  include "emc/log/internal/appender_null.h"
#endif

#if EMC_LOG_LOGGING
#  define EMC_TEST_LOGGING 1
#else
#  define EMC_TEST_LOGGING 0
#endif

static void setup_logging(const char* log_level_name)
{
  if (log_level_name) {
#if EMC_TEST_LOGGING
    EMC_LOG_Priorities priority = EMC_Log_priority_from_string(log_level_name);
    EMC_Log_set_priority(EMC_Log_root_logger(), priority);
#  if EMC_LOG_LOGGING_VARIANT == EMC_LOG_LOGGING_INTERNAL
#    if EMC_LOG_INTERNAL_APPENDER_PRINTF_INSTANCES > 0
    EMC_Log_logger_set_appender(EMC_Log_root_logger(), emc_log_appender_fprintf(stderr));
#    endif
#  endif
#else /*!EMC_TEST_LOGGING*/
    printf("\nno logging support available for level=%s\n", log_level_name);
#endif
  } else {
#if EMC_TEST_LOGGING
#  if EMC_LOG_LOGGING_VARIANT == EMC_LOG_LOGGING_INTERNAL
    EMC_Log_logger_set_appender(EMC_Log_root_logger(), emc_log_appender_null());
#  endif
#endif
  }
}

/* CUnitTestRunnerMain is not placed in a c-file to prevent adding it to shared
 * object when linking unit tests dynamic. CUnitTestRunnerMain calls a function
 * that has to be defined by the CUnit test. This would produce an unresolved
 * symbol if you do not link the shared object against a CUnit test.
 */
int CUnitTestRunnerMain(int argc, char* argv[])
{
  const char* arg_log_level_name = 0;

  CU_BasicRunMode mode = CU_BRM_SILENT;
  CU_ErrorAction  on_error = CUEA_IGNORE;
  int             result = 0;
  int             i;

  setvbuf(stdout, NULL, _IONBF, 0);

  for (i = 1; i < argc; ++i) {
    fprintf(stderr, "argv[%d] = \"%s\"\n", i, argv[i]);
    if (0 == strcmp("-v", argv[i])) {
      mode = CU_BRM_VERBOSE;
    } else if (0 == strncmp("-l", argv[i], 2)) {
      arg_log_level_name = argv[i] + 2;
    } else if (0 == strncmp("-h", argv[i], 2)) {
      arg_log_level_name = argv[i] + 2;
      printf("\nUsage:  BasicTest [options]\n"
             "Options:  -v     verbose mode - max output to screen\n"
             "          -lPRIO enable logging with priority PRIO [TRACE..FATAL, OFF]\n"
             "          -h     print this message and exit.\n");
      return 0;
    }
  }

  if (CU_initialize_registry()) {
    printf("\nInitialization of Test Registry failed.");
  } else {
    EMC_CUNIT_TEST_SUITE_INSTANTIATION();

    setup_logging(arg_log_level_name);

    CU_basic_set_mode(mode);
    CU_set_error_action(on_error);
    CU_basic_run_tests();

    result = (int)CU_get_number_of_tests_failed();

    CU_cleanup_registry();
  }

  return result;
}
