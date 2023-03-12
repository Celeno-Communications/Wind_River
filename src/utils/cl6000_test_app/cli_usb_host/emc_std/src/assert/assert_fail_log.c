/**
 * @file
 * @brief The implementation of the assert_fail for emc_log
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2004-2006, 2010, 2012 emsys Embedded Systems GmbH
 *
 ****************************************************************************/

#include "emc/std/configure.h"
#include "emc/std/emu/assert.h"
#include "emc/std/stdlib.h"
#include "emc/log/log.h"

EMC_STATIC_LOG_LEVEL_DEFINE(FATAL);

void __emc_std_assert_fail(EMC_STD_ASSERT_SRC_POS_PARAM
                           EMC_STD_ASSERT_FUNCTION_PARAM
                           EMC_STD_ASSERT_MESSAGE_PARAM
                           EMC_STD_ASSERT_CONTEXT_PARAM)
{
  emc_logger_t* logger = EMC_Log_root_logger();

#if EMC_STD_ASSERT_SRC_POS_FILE_LINE
  void* program_count = 0;
#elif EMC_STD_ASSERT_SRC_POS_PROGRAM_COUNT
  const char*  file_name = 0;
  unsigned int line = 0;
#endif

#if !EMC_STD_ASSERT_MESSAGE
  const char* message = "";
#endif
#if !EMC_STD_ASSERT_FUNCTION
  const char* function_name = 0;
#endif
  if (program_count) {
    EMC_LOG3(logger, FATAL, "assertion failed in %s() : pc=%p: %s",
             function_name ? function_name : "", program_count, message);
  } else {
    EMC_LOG4(logger, FATAL, "assertion failed in %s() : %s (%d): %s",
             function_name ? function_name : "", file_name, line, message);
  }
  UNUSED_PARAM(file_name);
  UNUSED_PARAM(line);
  UNUSED_PARAM(program_count);
  UNUSED_PARAM(function_name);
#if EMC_STD_ASSERT_MESSAGE
  UNUSED_PARAM(message);
#endif
#if EMC_STD_ASSERT_CONTEXT
  UNUSED_PARAM(context);
#endif

  emc_std_abort();
}
