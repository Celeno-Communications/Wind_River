/* Copyright (C) 2004-2013, 2018 emsys Embedded Systems GmbH */

#include "emc/std/emu/assert.h"
#include "emc/std/stdlib.h"

struct emc_std_assert_reason mg_emc_std_assert_reason;

void __emc_std_assert_fail(EMC_STD_ASSERT_SRC_POS_PARAM
                           EMC_STD_ASSERT_FUNCTION_PARAM
                           EMC_STD_ASSERT_MESSAGE_PARAM
                           EMC_STD_ASSERT_CONTEXT_PARAM)
{
#if EMC_STD_ASSERT_MESSAGE
  mg_emc_std_assert_reason.expression = message;
#endif
#if EMC_STD_ASSERT_SRC_POS_FILE_LINE
  mg_emc_std_assert_reason.file = file_name;
  mg_emc_std_assert_reason.line = line;
#elif EMC_STD_ASSERT_SRC_POS_PROGRAM_COUNT
  mg_emc_std_assert_reason.program_count = program_count;
#endif
#if EMC_STD_ASSERT_FUNCTION
  mg_emc_std_assert_reason.function = function_name;
#endif
#if EMC_STD_ASSERT_CONTEXT
  mg_emc_std_assert_reason.context = context;
#endif
  emc_std_abort();
}
