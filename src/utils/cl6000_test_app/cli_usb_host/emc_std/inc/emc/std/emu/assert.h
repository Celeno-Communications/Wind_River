/**
 * @file
 * @brief   An emulation of the Standard assertion API.
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2004, 2005, 2006, 2010, 2012 emsys Embedded Systems GmbH
 *
 ****************************************************************************/
#ifndef EMC_STD_EMU_assert_H
#define EMC_STD_EMU_assert_H

#include "emc/std/stdint.h"

#if EMC_STD_ASSERT_SRC_POS_PROGRAM_COUNT
#  include "emc/std/emu/program_counter.h"
#endif

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/*lint -esym(746,__emc_std_assert_fail) */
/*lint -function(exit,__emc_std_assert_fail) */

#if defined(_lint) || defined(_MSC_VER)
#  undef __builtin_expect
#  define __builtin_expect(a, b) a
#endif

#if EMC_STD_ASSERT_SRC_POS_FILE_LINE
#  define EMC_STD_ASSERT_SRC_POS_PARAM const char* file_name, unsigned int line
#  define EMC_STD_ASSERT_SRC_POS_GET __FILE__, __LINE__
#elif EMC_STD_ASSERT_SRC_POS_PROGRAM_COUNT
extern unsigned int emc_std_assert_get_pc(void);
#  define EMC_STD_ASSERT_SRC_POS_PARAM void* program_count
#  define EMC_STD_ASSERT_SRC_POS_GET emc_std_get_pc()
#endif

#if EMC_STD_ASSERT_CONTEXT
#  define EMC_STD_ASSERT_CONTEXT_PARAM , emc_std_uint64_t context
#  define EMC_STD_ASSERT_CONTEXT_GET , emc_get_static_assert_context()
#else
#  define EMC_STD_ASSERT_CONTEXT_PARAM
#  define EMC_STD_ASSERT_CONTEXT_GET
#endif

#if EMC_STD_ASSERT_MESSAGE
#  define EMC_STD_ASSERT_MESSAGE_PARAM , const char* message
#  define EMC_STD_ASSERT_MESSAGE_GET(m) , # m
#else
#  define EMC_STD_ASSERT_MESSAGE_PARAM
#  define EMC_STD_ASSERT_MESSAGE_GET(m)
#endif

#if EMC_STD_ASSERT_FUNCTION
#  define EMC_STD_ASSERT_FUNCTION_PARAM , const char* function_name
#  define EMC_STD_ASSERT_FUNCTION_GET , __func__
#else
#  define EMC_STD_ASSERT_FUNCTION_PARAM
#  define EMC_STD_ASSERT_FUNCTION_GET
#endif

/** @brief An assertion exit function.
 *
 * The internal function, which is called if the assertion fails.
 *
 * \lint 746:\n
 * call to function not made in presence of a prototype\n
 * It shoul'd be improved by forward declaration.\n
 * The equivalent to exit is always necessary to indicate
 * none returning function in case of errors.\n
 * <karsten.pahnke@emsys.de>
 *
 * @param file_name     The name of the file, where the assertion failed.
 * @param line          The line number in that file.
 * @param function_name The name of the function.
 * @param message       The specific error message.
 * @param context       The context information for the assertion.
 */
void __emc_std_assert_fail(EMC_STD_ASSERT_SRC_POS_PARAM
                           EMC_STD_ASSERT_FUNCTION_PARAM
                           EMC_STD_ASSERT_MESSAGE_PARAM
                           EMC_STD_ASSERT_CONTEXT_PARAM) EMC_ATTRIBUTE_NORETURN;

#if defined(EMC_STD_ASSERT_IMPL_MEM) && EMC_STD_ASSERT_IMPL_MEM
/** STD EMU Assert reason */
struct emc_std_assert_reason {
#  if EMC_STD_ASSERT_MESSAGE
  const char* expression; ///< The assert expression
#  endif
#  if EMC_STD_ASSERT_SRC_POS_FILE_LINE
  const char*  file; ///<  The filename where the assert happened
  unsigned int line; ///<  The line where the assert happened
#  elif EMC_STD_ASSERT_SRC_POS_PROGRAM_COUNT
  void* program_count; ///<  The program count where the assert happened
#  endif
#  if EMC_STD_ASSERT_FUNCTION
  const char* function; ///< The function where the assert happened
#  endif
#  if EMC_STD_ASSERT_CONTEXT
  emc_std_uint64_t context; ///< The assert context
#  endif
};

#endif

/** @brief A function providing assertion context information.
 *
 * The internal function, which is called in case of assertion
 * fails to provide additional context information.
 *
 */
#if EMC_STD_ASSERT_CONTEXT
emc_std_uint64_t emc_get_static_assert_context(void);
#endif

#ifndef assert

#  ifdef NDEBUG         /* required by ANSI standard */

#    if C_COMPILER_SUPPORTS_VOID_CAST
#      define assert(p)   ((void)0)/** < Noop assert() macro. */
#    else /*C_COMPILER_SUPPORTS_VOID_CAST*/
#      define assert(p) /** < Empty assert() macro. */
#    endif /*C_COMPILER_SUPPORTS_VOID_CAST*/

#  else /*NDEBUG*/

/** @def assert
    If the assertion fails __emc_std_assert_fail() is called. */

#    define assert(expression) do { if (__builtin_expect(!(expression), 0)) { \
      __emc_std_assert_fail(EMC_STD_ASSERT_SRC_POS_GET \
                            EMC_STD_ASSERT_FUNCTION_GET \
                            EMC_STD_ASSERT_MESSAGE_GET(expression) \
                            EMC_STD_ASSERT_CONTEXT_GET); \
    }} /*lint --e(717) */ while (0)

#  endif /*NDEBUG*/

#endif /*assert*/

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_STD_EMU_assert_H */
