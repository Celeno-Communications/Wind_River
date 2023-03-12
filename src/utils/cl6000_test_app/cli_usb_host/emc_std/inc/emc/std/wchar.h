/**
 * @file
 * @brief   The indirection of wchar.h for unicode character operations
 *
 *
 * @author  Steffen <steffen.luzemann@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 ****************************************************************************/
#ifndef EMC_STD_wchar_H
#define EMC_STD_wchar_H

#include "emc/std/configure.h"
#include "emc/std/stddef.h"

#if !EMC_STD_STDLIB_EMULATE
#  if C_LIBRARY_HAS_WCHAR_H
#    if HAVE_WCTYPE_H
/* Visual C 8's wchar.h doesn't define wchar_t and imports
   ..printf() functions that break our std::* emulation. */
#      include <wctype.h>
#    else

#      if defined(__GNUC__)
#        if GCC_VERSION >= 40600
#          pragma GCC diagnostic push
#          pragma GCC diagnostic ignored "-Wtype-limits"
#        endif
#      endif
#      include <wchar.h>
#      if defined(__GNUC__)
#        if GCC_VERSION >= 40600
#          pragma GCC diagnostic pop
#        endif
#      endif
#    endif
#  else
#    include "emc/std/emu/wchar.h"
#  endif
#else
#  include "emc/std/emu/wchar.h"
#endif

#endif /* EMC_STD_wchar_H */
