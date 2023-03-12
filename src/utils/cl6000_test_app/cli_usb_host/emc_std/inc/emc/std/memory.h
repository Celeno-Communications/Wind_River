/**
 * @file
 * @brief   The indirection of the memory.h for memory related functions.
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 ****************************************************************************/
#ifndef EMC_STD_memory_H
#define EMC_STD_memory_H

#include "emc/std/configure.h"

#if !EMC_STD_STDLIB_EMULATE

#  if (C_LIBRARY_MEMORY_H == C_LIBRARY_MEMORY_H_STRING)
#    include <string.h>
#  elif (C_LIBRARY_MEMORY_H == C_LIBRARY_MEMORY_H_MEMORY)
#    include <memory.h>
#  else
#    include "emc/std/emu/memory.h"
#  endif

#else /* !EMC_STD_STDLIB_EMULATE */

#  include "emc/std/emu/memory.h"

#endif

#endif /* EMC_STD_memory_H */
