#ifndef _REG_UMAC_H_
#define _REG_UMAC_H_

#include <stdint.h>
#include "_reg_umac.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_UMAC__H__FILEID__

#define REG_UMAC_COUNT  2

/**
 * @brief DRAM register definition
 *  196608 memory size
 * </pre>
 */
#define UMAC_DRAM_ADDR        (REG_UMAC_BASE_ADDR+0x00000000)
#define UMAC_DRAM_OFFSET      0x00000000
#define UMAC_DRAM_SIZE        0x00030000
#define UMAC_DRAM_END_ADDR    (UMAC_DRAM_ADDR + UMAC_DRAM_SIZE - 1)
/**
 * @brief IRAM register definition
 *  196608 memory size
 * </pre>
 */
#define UMAC_IRAM_ADDR        (REG_UMAC_BASE_ADDR+0x00040000)
#define UMAC_IRAM_OFFSET      0x00040000
#define UMAC_IRAM_SIZE        0x00030000
#define UMAC_IRAM_END_ADDR    (UMAC_IRAM_ADDR + UMAC_IRAM_SIZE - 1)


#undef DBG_FILEID
#endif //_REG_UMAC_H_
