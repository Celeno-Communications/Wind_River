#ifndef __REG_TXM_COMMON_H_
#define __REG_TXM_COMMON_H_

#include "rwnx_config.h"

#if (PRIM_BAND)
#include "_reg_txm0_common.h"
#define REG_TXM_COMMON_BASE_ADDR 	REG_TXM0_COMMON_BASE_ADDR
#else
#include "_reg_txm1_common.h"
#define REG_TXM_COMMON_BASE_ADDR 	REG_TXM1_COMMON_BASE_ADDR
#endif

#endif //__REG_TXM_COMMON_H_
