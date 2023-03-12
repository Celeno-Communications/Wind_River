/**
 * @file
 * @brief   The indirection for the CN specific malloc.h header.
 *
 *          Introduced to identify in the source files which use this
 *          specific header that it is the CN specific version, and
 *          no standard malloc.h.
 *
 * @author  Stefan Schulze <stefan.schulze@emsys.de> +49-3677-68977-22
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 ****************************************************************************/

#ifndef EMC_STD_EMU_COMNEON_XALLOC_xalloc_H
#define EMC_STD_EMU_COMNEON_XALLOC_xalloc_H

#if defined(__arm)
#  pragma diag_suppress 1297
#endif

/** @todo Clarify with CN to use a more unique name (e.g. xalloc.h) or a
 * more specific path to avoid inclusion of standard malloc.h by accident */
#include "malloc.h"

#if defined(__arm)
#  pragma diag_default 1297
#endif

#endif /* EMC_STD_EMU_COMNEON_XALLOC_xalloc_H */
