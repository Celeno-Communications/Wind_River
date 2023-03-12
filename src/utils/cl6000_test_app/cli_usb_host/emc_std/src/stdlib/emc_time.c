/**
 * @file
 * @brief   re-implementation of needed functions from <time.h>
 *
 *
 * @author  steffen <steffen.luzemann@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 ****************************************************************************/

#include "emc/std/configure.h"

#include "emc/std/emu/time.h"

static struct tm emc_tm;

struct tm* gmtime(const time_t* numeric_time)
{
  UNUSED_PARAM(numeric_time);

  /* this function provides a default time only */
  emc_tm.tm_sec = 0;

  emc_tm.tm_min = 0;
  emc_tm.tm_hour = 0;
  emc_tm.tm_mday = 27;
  emc_tm.tm_mon = 1;
  emc_tm.tm_year = 104;
  emc_tm.tm_wday = 2;
  emc_tm.tm_yday = 27;
  emc_tm.tm_isdst = 0;

  return &emc_tm;
}
