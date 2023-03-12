/**
 * @file
 * @brief   Profiling macro wrapper.
 *
 * @author  Toralf Henze <toralf.henze@emsys.de> +49-3677-6897721
 *          emsys GmbH, D-98693 Ilmenau, Werner v. Siemens Str. 20
 *
 * Copyright (C) 2013,2015 emsys Embedded Systems GmbH
 */

#ifndef EMC_LOG_profiling_H
#define EMC_LOG_profiling_H

#include "emc/log/configure.h"
#include "emc/std/stdint.h"

//lint -esym(522,emc_sysprof_ev)
#if EMC_CUSTOMER_CONFIG
#  include "customer_profiling.h"
#else

/** perform sysprofiling for event with data */
#  define emc_sysprof_ev(id, data) do {} while (0)

/** perform sysprofiling for bandwidth value */
#  define emc_sysprof_bw(id, val) do {} while (0)

#  define emc_sysprof_func_entry(id) do {} while (0)
#  define emc_sysprof_func_leave(id) do {} while (0)

#  define emc_sysprof_timing_in(id, obj_id) do {} while (0)
#  define emc_sysprof_timing_out(id, obj_id) do {} while (0)
#  define emc_sysprof_timing_single(id, time) do {} while (0)

#endif

#endif /* EMC_LOG_profiling_H */
