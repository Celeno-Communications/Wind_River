/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_wctype_H
#define EMC_STD_wctype_H

#if !EMC_STD_STDLIB_EMULATE
#  if HAVE_WCTYPE_H
#    include <wctype.h>
#    define emc_std_wint_t wint_t
#  else /* !HAVE_WCTYPE_H */
typedef int emc_std_wint_t;
#  endif /* !HAVE_WCTYPE_H */
#else /* EMC_STD_STDLIB_EMULATE */
typedef int emc_std_wint_t;
#endif /* EMC_STD_STDLIB_EMULATE */

#endif /* EMC_STD_wctype_H */
