#ifndef __REG_FPGA_DPHY_COMMON_H_
#define __REG_FPGA_DPHY_COMMON_H_

#if (PRIM_BAND)
#include "_reg_fpga_dphy_common_0.h"
#define REG_FPGA_DPHY_COMMON_BASE_ADDR 	REG_FPGA_DPHY_COMMON_0_BASE_ADDR
#else
#include "_reg_fpga_dphy_common_1.h"
#define REG_FPGA_DPHY_COMMON_BASE_ADDR 	REG_FPGA_DPHY_COMMON_1_BASE_ADDR
#endif

#endif //__REG_FPGA_DPHY_COMMON_H_
