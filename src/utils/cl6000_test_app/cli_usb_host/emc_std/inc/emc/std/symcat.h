/**
 * @file
 * @brief   The indirection of symcat.h.
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 ****************************************************************************/
#ifndef EMC_STD_symcat_H
#define EMC_STD_symcat_H

#include <emc/std/configure.h>

#if !EMC_STD_STDLIB_EMULATE

#  include <symcat.h>

#else /* EMC_STD_STDLIB_EMULATE */

#  include <emc/std/emu/symcat.h>

#endif /* EMC_STD_STDLIB_EMULATE */

#endif /* EMC_STD_symcat_H */
