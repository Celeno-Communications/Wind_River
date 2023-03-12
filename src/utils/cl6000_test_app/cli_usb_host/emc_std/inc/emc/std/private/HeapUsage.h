/**
 * @file
 *
 * @brief Heap usage report
 *
 * @author  Andreas Bucher <andreas.bucher@intel.com>
 *
 * Copyright (C) 2015 Intel Mobile Communications GmbH
 *
 **********************************************************************/

#ifndef EMC_STD_PRIVATE_HeapUsage_H
#define EMC_STD_PRIVATE_HeapUsage_H

#include "emc/std/configure.h"
#include "emc/std/stddef.h"

EMC_EXTERN_C_BEGIN;

typedef struct {
  size_t used;
  size_t max_used;
  size_t size;
} EmcHeapReport;

void emc_heap_report(EmcHeapReport* report);

EMC_EXTERN_C_END;

#endif /* EMC_STD_PRIVATE_HeapUsage_H */
