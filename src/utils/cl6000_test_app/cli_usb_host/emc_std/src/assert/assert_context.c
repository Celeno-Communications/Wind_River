/**
 * @file
 * @brief The implementation of assert_context based on UNIQUE_SIGNATURE
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2004-2006, 2010, 2012 emsys Embedded Systems GmbH
 *
 ****************************************************************************/

#include "emc/std/configure.h"
#include "emc/config/module_id.h"
#include "emc/std/assert.h"
#include "emc/std/stdint.h"

emc_std_uint64_t emc_get_static_assert_context(void)
{
  return EMC_UNIQUE_SIGNATURE(EMC);
}
