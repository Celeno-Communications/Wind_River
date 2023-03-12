/** @file
    @brief Integer types.
    @see http://pubs.opengroup.org/onlinepubs/009695399/basedefs/stdint.h.html
    Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_stdint_H
#define EMC_STD_stdint_H

#include "emc/std/configure.h"

/// defined _STDINT (included stdint.h)
#if C_LIBRARY_HAS_STDINT_H
#  include <stdint.h>
#endif

#ifndef EMC_STD_STDINT_REQUIRES_MAX
#  if defined(_MSC_VER) && C_LIBRARY_HAS_STDINT_H
#    define EMC_STD_STDINT_REQUIRES_MAX 0
#  elif defined(__ARMCC_VERSION)
#    define EMC_STD_STDINT_REQUIRES_MAX 1
//#  elif C_LIBRARY_HAS_STDINT_H
//#    define EMC_STD_STDINT_REQUIRES_MAX 0
#  else
#    define EMC_STD_STDINT_REQUIRES_MAX 1
#  endif
#endif

#if !EMC_STD_STDLIB_EMULATE && !(_MSC_WDK_VER >= 10010586)
#  if C_LIBRARY_HAS_STDINT_H
#    include <stdint.h>
#  elif defined(_MSC_VER) && _MSC_VER <= 1600 /* VS2012 (msvc11) has stdint.h */
#    include <stdlib.h>                       /* includes crtdefs.h, which defines standard types */
#  endif

typedef int8_t        emc_std_int8_t;
typedef uint8_t       emc_std_uint8_t;
typedef int_least8_t  emc_std_int_least8_t;
typedef uint_least8_t emc_std_uint_least8_t;
typedef int_fast8_t   emc_std_int_fast8_t;
typedef uint_fast8_t  emc_std_uint_fast8_t;

typedef int16_t        emc_std_int16_t;
typedef uint16_t       emc_std_uint16_t;
typedef int_least16_t  emc_std_int_least16_t;
typedef uint_least16_t emc_std_uint_least16_t;
typedef int_fast16_t   emc_std_int_fast16_t;
typedef uint_fast16_t  emc_std_uint_fast16_t;

typedef int32_t        emc_std_int32_t;
typedef uint32_t       emc_std_uint32_t;
typedef int_least32_t  emc_std_int_least32_t;
typedef uint_least32_t emc_std_uint_least32_t;
typedef int_fast32_t   emc_std_int_fast32_t;
typedef uint_fast32_t  emc_std_uint_fast32_t;

typedef int64_t        emc_std_int64_t;
typedef uint64_t       emc_std_uint64_t;
typedef int_least64_t  emc_std_int_least64_t;
typedef uint_least64_t emc_std_uint_least64_t;
typedef int_fast64_t   emc_std_int_fast64_t;
typedef uint_fast64_t  emc_std_uint_fast64_t;

typedef intptr_t  emc_std_intptr_t;
typedef uintptr_t emc_std_uintptr_t;

typedef intmax_t  emc_std_intmax_t;
typedef uintmax_t emc_std_uintmax_t;
#else /* EMC_STD_STDLIB_EMULATE */
#  include "emc/std/emu/stdint.h"
#endif /* EMC_STD_STDLIB_EMULATE */

#if EMC_STD_STDINT_REQUIRES_MAX

#  ifndef SIZE_MAX
#    define SIZE_MAX 0xFFFFFFFF ///< Maximum value for size_t
#  endif

#  ifndef UINT8_MAX
#    define UINT8_MAX 0xFF ///< Maximum value for std::uint8_t
#  endif

#  ifndef INT8_MAX
#    define INT8_MAX 0x7F ///< Maximum value for std::int8_t
#  endif

#  ifndef UINT16_MAX
#    define UINT16_MAX 0xFFFF ///< Maximum value for std::uint16_t
#  endif

#  ifndef INT16_MAX
#    define INT16_MAX 0x7FFF ///< Maximum value for std::int16_t
#  endif

#  ifndef UINT32_MAX
#    define UINT32_MAX 0xFFFFFFFF ///< Maximum value for std::uint32_t
#  endif

#  ifndef INT32_MAX
#    define INT32_MAX 0x7FFFFFFF ///< Maximum value for std::int32_t
#  endif
#endif //EMC_STD_STDINT_REQUIRES_MAX

#endif /* EMC_STD_stdint_H */
