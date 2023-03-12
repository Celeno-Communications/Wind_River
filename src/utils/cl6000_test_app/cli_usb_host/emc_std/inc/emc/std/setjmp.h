/** @file
    @brief The std setjmp
    Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_setjmp_H
#define EMC_STD_setjmp_H

#include "emc/std/configure.h"

#if !EMC_STD_STDLIB_EMULATE

#  include <setjmp.h>

#else /* !USE_STDLIB */

#  include "emc/std/emu/setjmp.h"

#endif /* !USE_STDLIB */

#endif /* EMC_STD_setjmp_H */
