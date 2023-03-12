#ifndef __REG_BAP_H_
#define __REG_BAP_H_

#include "rwnx_config.h"

#if (PRIM_BAND)
#include "_reg_bap0.h"
#define REG_BAP_BASE_ADDR 	REG_BAP0_BASE_ADDR
#else
#include "_reg_bap1.h"
#define REG_BAP_BASE_ADDR 	REG_BAP1_BASE_ADDR
#endif

#endif //__REG_BAP_H_
