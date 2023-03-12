#ifndef _REG_SMAC_H_
#define _REG_SMAC_H_

#include <stdint.h>
#include "_reg_smac.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_SMAC__H__FILEID__

#define REG_SMAC_COUNT  2

/**
 * @brief DRAM register definition
 *  163840 memory size
 * </pre>
 */
#define SMAC_DRAM_ADDR        (REG_SMAC_BASE_ADDR+0x00000000)
#define SMAC_DRAM_OFFSET      0x00000000
#define SMAC_DRAM_SIZE        0x00028000
#define SMAC_DRAM_END_ADDR    (SMAC_DRAM_ADDR + SMAC_DRAM_SIZE - 1)
/**
 * @brief IRAM register definition
 *  131072 memory size
 * </pre>
 */
#define SMAC_IRAM_ADDR        (REG_SMAC_BASE_ADDR+0x00040000)
#define SMAC_IRAM_OFFSET      0x00040000
#define SMAC_IRAM_SIZE        0x00020000
#define SMAC_IRAM_END_ADDR    (SMAC_IRAM_ADDR + SMAC_IRAM_SIZE - 1)


#undef DBG_FILEID
#endif //_REG_SMAC_H_
