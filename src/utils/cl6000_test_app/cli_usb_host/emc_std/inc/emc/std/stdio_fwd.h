/**
 * @file
 * @brief   forward declaration for stdio
 *
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 ****************************************************************************/

#ifndef EMC_STD_stdio_fwd_H
#define EMC_STD_stdio_fwd_H

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

#include <emc/std/stdio.h>

/*lint -esym(746, fprintf) */
/*lint -esym(534, fprintf) */
/** \lint 746,534:
 *
 * avoid fprintf sepcific lint problems\n
 * <karsten.pahnke@emsys.de>
 */

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_STD_stdio_fwd_H */
