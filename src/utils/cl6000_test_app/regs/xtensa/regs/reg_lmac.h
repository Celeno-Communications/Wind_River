#ifndef _REG_LMAC_H_
#define _REG_LMAC_H_

#include <stdint.h>
#include "_reg_lmac.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_LMAC__H__FILEID__

#define REG_LMAC_COUNT  2

/**
 * @brief DRAM register definition
 *  131072 memory size
 * </pre>
 */
#define LMAC_DRAM_ADDR        (REG_LMAC_BASE_ADDR+0x00000000)
#define LMAC_DRAM_OFFSET      0x00000000
#define LMAC_DRAM_SIZE        0x00020000
#define LMAC_DRAM_END_ADDR    (LMAC_DRAM_ADDR + LMAC_DRAM_SIZE - 1)
/**
 * @brief IRAM register definition
 *  262144 memory size
 * </pre>
 */
#define LMAC_IRAM_ADDR        (REG_LMAC_BASE_ADDR+0x00040000)
#define LMAC_IRAM_OFFSET      0x00040000
#define LMAC_IRAM_SIZE        0x00040000
#define LMAC_IRAM_END_ADDR    (LMAC_IRAM_ADDR + LMAC_IRAM_SIZE - 1)


#undef DBG_FILEID
#endif //_REG_LMAC_H_
