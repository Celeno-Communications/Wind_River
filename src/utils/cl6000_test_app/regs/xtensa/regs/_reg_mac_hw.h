#ifndef __REG_MAC_HW_H_
#define __REG_MAC_HW_H_

#include "rwnx_config.h"

#if (PRIM_BAND)
#include "_reg_mac_hw0_mu0.h"
#define REG_MAC_HW_BASE_ADDR 	REG_MAC_HW0_MU0_BASE_ADDR
#else
#include "_reg_mac_hw1_mu0.h"
#define REG_MAC_HW_BASE_ADDR 	REG_MAC_HW1_MU0_BASE_ADDR
#endif

#endif //__REG_MAC_HW_H_
