/**
 * @file
 * @brief The implementation of assert_fail using a customizable handler
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2004-2006, 2010, 2012 emsys Embedded Systems GmbH
 *
 ****************************************************************************/

#include "emc/std/emu/assert.h"
#include "emc/std/stdlib.h"
#include "emc/std/stdatomic.h"
#include "emc/std/emu/assert_handler.h"

static emc_std_atomic_intptr_t mg_assert_handler = EMC_STD_ATOMIC_VAR_INIT(0);
static emc_std_atomic_intptr_t mg_assert_handler_set = EMC_STD_ATOMIC_VAR_INIT(0);

static emc_std_assert_handler emc_get_std_assert_handler(void)
{
  return (emc_std_assert_handler)emc_std_atomic_load(&mg_assert_handler);
}

emc_std_assert_handler emc_std_set_assert_handler(emc_std_assert_handler handler)
{
  /*lint --e{546} suspicious & */
  emc_std_intptr_t old_handler;
  old_handler = emc_std_atomic_exchange(&mg_assert_handler, (emc_std_intptr_t)handler);
  emc_std_atomic_store(&mg_assert_handler_set, 1); /* Don't use arm_default, even if 'handler == 0' */
  return (emc_std_assert_handler)old_handler;
}

void __emc_std_assert_fail(EMC_STD_ASSERT_SRC_POS_PARAM
                           EMC_STD_ASSERT_FUNCTION_PARAM
                           EMC_STD_ASSERT_MESSAGE_PARAM
                           EMC_STD_ASSERT_CONTEXT_PARAM)
{
  emc_std_assert_handler ah;
#if EMC_STD_ASSERT_SRC_POS_FILE_LINE
  void* program_count = 0;
#elif EMC_STD_ASSERT_SRC_POS_PROGRAM_COUNT
  const char*  file_name = 0;
  unsigned int line = 0;
#endif
#if !EMC_STD_ASSERT_FUNCTION
  const char* function_name = 0;
#endif
#if !EMC_STD_ASSERT_MESSAGE
  const char* message = "";
#endif
  ah = emc_get_std_assert_handler();
  if (ah) {
    if (program_count) {
      file_name = "program_counter";
      line = (unsigned int)program_count;
    }
#if EMC_STD_ASSERT_CONTEXT
    (*ah)(file_name, line, function_name, message, context);
#else
    (*ah)(file_name, line, function_name, message);
#endif
  }
  emc_std_abort();
}
