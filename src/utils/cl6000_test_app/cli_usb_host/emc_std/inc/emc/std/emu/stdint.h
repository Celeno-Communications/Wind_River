/** @file
    @brief Integer types.
    @see http://pubs.opengroup.org/onlinepubs/009695399/basedefs/stdint.h.html
    Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EMU_stdint_H
#define EMC_STD_EMU_stdint_H

typedef signed char emc_std_int8_t,      emc_std_int_least8_t;
typedef unsigned char emc_std_uint8_t,   emc_std_uint_least8_t;
typedef short emc_std_int16_t,           emc_std_int_least16_t;
typedef unsigned short emc_std_uint16_t, emc_std_uint_least16_t;
typedef int emc_std_int32_t, emc_std_int_least32_t,
  emc_std_int_fast8_t, emc_std_int_fast16_t, emc_std_int_fast32_t;
typedef unsigned emc_std_uint32_t, emc_std_uint_least32_t,
  emc_std_uint_fast8_t, emc_std_uint_fast16_t, emc_std_uint_fast32_t;
EMC_EXTENSION_TYPEDEF_LONG_LONG(emc_std_int64_t);
EMC_EXTENSION_TYPEDEF_LONG_LONG(emc_std_int_least64_t);
EMC_EXTENSION_TYPEDEF_LONG_LONG(emc_std_int_fast64_t);
EMC_EXTENSION_TYPEDEF_LONG_LONG(emc_std_intmax_t);
EMC_EXTENSION_TYPEDEF_ULONG_LONG(emc_std_uint64_t);
EMC_EXTENSION_TYPEDEF_ULONG_LONG(emc_std_uint_least64_t);
EMC_EXTENSION_TYPEDEF_ULONG_LONG(emc_std_uint_fast64_t);
EMC_EXTENSION_TYPEDEF_ULONG_LONG(emc_std_uintmax_t);

#if 4 == EMC_SIZEOF_POINTER
typedef emc_std_int32_t  emc_std_intptr_t;
typedef emc_std_uint32_t emc_std_uintptr_t;
#  if EMC_STD_STDINT_REQUIRES_MAX
#    ifndef INTPTR_MIN
#      define INTPTR_MIN (-2147483647 - 1)
#    endif
#    ifndef INTPTR_MAX
#      define INTPTR_MAX (2147483647)
#    endif
#    ifndef UINTPTR_MAX
#      define UINTPTR_MAX (4294967295U)
#    endif
#  endif   //EMC_STD_STDINT_REQUIRES_MAX

#elif 8 == EMC_SIZEOF_POINTER
typedef emc_std_int64_t  emc_std_intptr_t;
typedef emc_std_uint64_t emc_std_uintptr_t;
#  if EMC_STD_STDINT_REQUIRES_MAX
#    ifndef INTPTR_MIN
#      define INTPTR_MIN (-9223372036854775807L - 1)
#    endif
#    ifndef INTPTR_MAX
#      define INTPTR_MAX (9223372036854775807L)
#    endif
#    ifndef UINTPTR_MAX
#      define UINTPTR_MAX (18446744073709551615UL)
#    endif
#  endif   //EMC_STD_STDINT_REQUIRES_MAX

#endif

#endif
