#ifndef __REG_TXM_STREAM_H_
#define __REG_TXM_STREAM_H_

#include "rwnx_config.h"

#if (PRIM_BAND)
#include "_reg_txm0_stream0.h"
#define REG_TXM_STREAM_BASE_ADDR 	REG_TXM0_STREAM0_BASE_ADDR
#else
#include "_reg_txm1_stream0.h"
#define REG_TXM_STREAM_BASE_ADDR 	REG_TXM1_STREAM0_BASE_ADDR
#endif

#endif //__REG_TXM_STREAM_H_
