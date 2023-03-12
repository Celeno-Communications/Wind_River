/* Copyright (C) 2016 emsys Embedded Systems GmbH */

#ifndef EMC_CONFIG_module_id_H
#define EMC_CONFIG_module_id_H

#include <emc/config/configure.h>

#if EMC_CUSTOMER_CONFIG
#  include "customer_module_id.h"
#else
#  define EMC_UNIQUE_SIGNATURE(module) 0
#endif

#endif /* EMC_CONFIG_module_id_H */
