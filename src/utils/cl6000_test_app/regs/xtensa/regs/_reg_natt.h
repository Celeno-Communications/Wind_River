#ifndef __REG_NATT_H_
#define __REG_NATT_H_

#include "rwnx_config.h"

#if (PRIM_BAND)
#include "_reg_natt0.h"
#define REG_NATT_BASE_ADDR 	REG_NATT0_BASE_ADDR
#else
#include "_reg_natt1.h"
#define REG_NATT_BASE_ADDR 	REG_NATT1_BASE_ADDR
#endif

#endif //__REG_NATT_H_
