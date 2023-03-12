/**
 * @file
 * @brief   The Generic Port Access Layer API
 * @author  Stefan Schulze <stefan.schulze@emsys.de> +49-3677-68977-22
 * Copyright (C) 2013, 2020-2021 emsys Embedded Systems GmbH
 */

#ifndef EMC_HW_PORT_Port_H
#define EMC_HW_PORT_Port_H

#include "emc/hw/port/Port_fwd.h"

#if EMC_HW_PORT_INLINE_MMIO
#  include "emc/hw/port/private/Port_inline_mmio.h"
#else
#  include "emc/hw/port/private/Port_vtbl.h"
#endif

#endif /* EMC_HW_PORT_Port_H */
