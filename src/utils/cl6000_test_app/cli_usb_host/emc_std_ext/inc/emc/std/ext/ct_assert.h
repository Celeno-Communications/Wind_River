/**
 * @file
 * @brief   A compile time assertion API.
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_STD_EXT_ct_assert_H
#define EMC_STD_EXT_ct_assert_H

/** Check integral expressions at compile-time */

/** @private defines whether the compiler is supporting _Static_assert */
#define EMC_STD_STATIC_ASSERT_DEFINED 0

/** @private enables static assert emulation via array size (negative in fail case).
 * This may cause problems with ISO C90, so the alternate solution of double defined switch cases is usable.
 */
#define EMC_STD_STATIC_ASSERT_EMULATION_ARRAY_SIZE 0

#if defined(__STDC__)
#  if defined(__STDC_VERSION__)
#    if (__STDC_VERSION__ >= 201112L)
/* C11 compiler should have a _Static_assert built in,
 * but that causes other problems, eg. related to restrictions where CT_ASSERTS can be placed.
 * That's why we are currently not activating the use of standard _Static_assert.
 */
#      undef EMC_STD_STATIC_ASSERT_DEFINED
#      define EMC_STD_STATIC_ASSERT_DEFINED 0
#    endif
#  endif
#endif

#if defined(_lint)
#  undef EMC_STD_STATIC_ASSERT_EMULATION_ARRAY_SIZE
#  define EMC_STD_STATIC_ASSERT_EMULATION_ARRAY_SIZE 1
#endif

#if EMC_STD_STATIC_ASSERT_DEFINED

#  define EMC_CT_ASSERT(pred) _Static_assert(pred, "")

#else /* !EMC_STD_STATIC_ASSERT_DEFINED */

/** @lint That should always compile to a const expression */
/*lint -emacro(506,EMC_CT_ASSERT)*/

#  if EMC_STD_STATIC_ASSERT_EMULATION_ARRAY_SIZE

#    define EMC_CT_ASSERT(pred)                 \
  do {                                      \
    char constraint[(pred) ? 1 : -1];       \
    UNUSED_PARAM(constraint);               \
  } while (0)

#  else /* !EMC_STD_STATIC_ASSERT_EMULATION_ARRAY_SIZE */

#    define EMC_CT_ASSERT(pred)                 \
  switch (0) {default: case 0: case (pred):;}
/* switch((int)(*(volatile int*)0)){case 0:case (pred):;} */

#  endif /* !EMC_STD_STATIC_ASSERT_EMULATION_ARRAY_SIZE */

#endif /* !EMC_STD_STATIC_ASSERT_DEFINED */

#endif /* EMC_STD_EXT_ct_assert_H */
