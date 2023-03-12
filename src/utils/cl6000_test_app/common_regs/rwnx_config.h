/**
 ****************************************************************************************
 *
 * @file rwnx_config.h
 *
 * @brief Inclusion of appropriate config files.
 *
 * This file should be included each time an NX_xxx definition is needed.
 * CFG_xxx macros must no be used in the code, only NX_xxx, defined in
 * the included config files.
 *
 * Copyright (C) RivieraWaves 2011-2013
 *
 ****************************************************************************************
 */

#ifndef _RWNX_CONFIG_H_
#define _RWNX_CONFIG_H_

/// Hardware versions
#define HW_2400_STEP_A0  0
#define HW_2400_STEP_B0  1
#define HW_8000_STEP_A0  2
#define HW_8000_STEP_B0  3
#define HW_6000_STEP_A0  4
#define HW_VERSION_MAX 5

//#define PRIM_BAND 1
/// @}

#endif // _RWNX_CONFIG_H_
