/**
 * @file
 * @brief The implementation of assert_fail with abort
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2004-2006, 2010, 2012 emsys Embedded Systems GmbH
 *
 ****************************************************************************/

#include "emc/std/emu/assert.h"
#include "emc/std/stdlib.h"
#include "emc/std/stdint.h"

#if !EMC_STD_STDIO_NONE
#  include "emc/std/stdio.h"
#endif

//#if !defined(NDEBUG)
void __emc_std_assert_fail(EMC_STD_ASSERT_SRC_POS_PARAM
                           EMC_STD_ASSERT_FUNCTION_PARAM
                           EMC_STD_ASSERT_MESSAGE_PARAM
                           EMC_STD_ASSERT_CONTEXT_PARAM)
{
#if !EMC_STD_STDIO_NONE
#  if EMC_STD_ASSERT_SRC_POS_FILE_LINE
  void* program_count = 0;
#  elif EMC_STD_ASSERT_SRC_POS_PROGRAM_COUNT
  const char*  file_name = 0;
  unsigned int line = 0;
#  endif

#  if !EMC_STD_ASSERT_MESSAGE
  const char* message = 0;
#  endif
#  if !EMC_STD_ASSERT_FUNCTION
  const char* function_name = 0;
#  endif
  if (program_count) {
    const char* format = "\n assertion failed at pc: %p\n";
    fprintf(stderr, format, program_count);
  } else {

#  if EMC_STD_ASSERT_CONTEXT
    const char* format = (sizeof(emc_std_uint64_t) == sizeof(long unsigned))
                         ? "\n assertion(%s) failed in: %s:%d %s() context=%lx \n"
                         : "\n assertion(%s) failed in: %s:%d %s() context=%llx \n";
    fprintf(stderr,
            format,
            message ? message : "abort",
            file_name ? file_name : "unknown file",
            line,
            function_name ? function_name : "unknown function",
            context);
#  else /* !EMC_STD_ASSERT_CONTEXT */
    const char* format = "\n assertion(%s) failed in: %s:%d %s() \n";
    fprintf(stderr,
            format,
            message ? message : "abort",
            file_name ? file_name : "unknown file",
            line,
            function_name ? function_name : "unknown function");
#  endif /* !EMC_STD_ASSERT_CONTEXT */
  }
  fflush(stderr);
#else /* !EMC_STD_STDIO_NONE */
  UNUSED_PARAM(file_name);
  UNUSED_PARAM(line);
  UNUSED_PARAM(program_count);
  UNUSED_PARAM(function_name);
  UNUSED_PARAM(message);
#  if EMC_STD_ASSERT_CONTEXT
  UNUSED_PARAM(context);
#  endif
#endif /*! !EMC_STD_STDIO_NONE */
  emc_std_abort();
}

//#endif /*!defined(NDEBUG)*/
