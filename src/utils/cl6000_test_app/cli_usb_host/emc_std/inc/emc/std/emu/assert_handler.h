/**
 * @file
 * @brief   A handler used in case of __emc_std_assert_fail()
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 ****************************************************************************/
#ifndef EMC_STD_EMU_assert_handler_H
#define EMC_STD_EMU_assert_handler_H

#include "emc/std/configure.h"
#include "emc/std/stdint.h"
#include "emc/std/emu/assert.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** @name assert_handler
 *  The system dependent assert_handler().
 */
/**@{*/

/** The type for assert callback functions.
 * It has to be guaranteed that this handler never will return!
 *
 * @param file_name     The name of the source file that caused the abortion.
 * @param line          The line number that caused the abortion.
 * @param function_name The name of the function that caused the abortion.
 * @param message       The abort message.
 * @param context       The additional context information for the abortion.
 */
typedef void (* emc_std_assert_handler)(const char* file_name,
                                        unsigned int line,
                                        const char* function_name,
                                        const char* message
                                        EMC_STD_ASSERT_CONTEXT_PARAM);

/**
 * Sets the assert handler.
 *
 * The abort handler will be called, when an abort() is called.
 * The abort handler must never return!
 *
 * @param handler the new assert handler
 *
 * @return the former assert handler
 */
emc_std_assert_handler emc_std_set_assert_handler(emc_std_assert_handler handler);

/**@}*/

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_STD_EMU_exit_emu_H */
