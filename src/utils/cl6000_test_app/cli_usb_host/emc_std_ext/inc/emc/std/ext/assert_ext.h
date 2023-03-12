/**
 * @file
 * @brief   An extension of the Standard assertion API.
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 ****************************************************************************/
#ifndef EMC_STD_EXT_assert_ext_H
#define EMC_STD_EXT_assert_ext_H

#include "emc/std/configure.h"
#include "emc/std/assert.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/**
 * @brief A message function used only for assert_return
 *
 * The internal function, which is called when the assert_return wants
 * to print a message
 *
 * @param file     The name of the file, where the assertion failed.
 * @param line     The line number in that file.
 * @param function The name of the function.
 * @param message  The specific error message.
 */
void __assert_return_failed(const char* file, int line, const char* function, const char* message);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

/**
 * @macro assert_return(c)
 * @param c condition
 * returns if assertion c fails.
 */

/**
 * @macro assert_return_val(c,v)
 * @param c condition
 * @param v value
 * returns a value v if assertion c fails.
 */

#ifndef NDEBUG

#  define assert_return(c)                                              \
  if (!(c)) {                                                           \
    __assert_return_failed(__FILE__, __LINE__, __func__, "assert_return: " # c); \
    return;                                                             \
  }

#  define assert_return_val(c, v)                                       \
  if (!(c)) {                                                           \
    __assert_return_failed(__FILE__, __LINE__, __func__, "assert_return_val: " # c); \
    return (v);                                                         \
  }
#else /* !NDEBUG */

#  define assert_return(c)  if (!(c)) { return; }
#  define assert_return_val(c, v) if (!(c)) { return (v); }

#endif /* !NDEBUG */

#endif /* EMC_STD_EXT_assert_ext_H */
