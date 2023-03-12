#ifndef __REG_RXM_H_
#define __REG_RXM_H_

#include "rwnx_config.h"

#if (PRIM_BAND)
#include "_reg_rxm0.h"
#define REG_RXM_BASE_ADDR 	REG_RXM0_BASE_ADDR
#else
#include "_reg_rxm1.h"
#define REG_RXM_BASE_ADDR 	REG_RXM1_BASE_ADDR
#endif

#endif //__REG_RXM_H_
