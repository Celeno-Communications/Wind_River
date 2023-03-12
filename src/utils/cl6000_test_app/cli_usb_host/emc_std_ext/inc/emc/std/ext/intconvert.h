/** @file
    @brief generic conversion on any type to uint32
    Copyright (C) 2013, 2020-2021 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EXT_intconvert_H
#define EMC_STD_EXT_intconvert_H

/** convert to uint32_t */
#define to_uint32(x) (*(emc_std_uint32_t*)&(x))

#endif
