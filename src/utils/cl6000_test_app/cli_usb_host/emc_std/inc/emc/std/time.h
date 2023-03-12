/**
 * @file
 * @brief   redirection
 *
 *
 * @author  steffen <steffen.luzemann@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 ****************************************************************************/

#ifndef EMC_STD_time_H
#define EMC_STD_time_H

#include "emc/std/configure.h"

#if EMC_STD_STDLIB_EMULATE
#  include <time.h>
//#  include "emc/std/emu/time.h"
#else
#  include <time.h>
#endif

#endif /* EMC_STD_time_H */
