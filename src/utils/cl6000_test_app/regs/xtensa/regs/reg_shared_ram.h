#ifndef _REG_SHARED_RAM_H_
#define _REG_SHARED_RAM_H_

#include <stdint.h>
#include "_reg_shared_ram.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_SHARED_RAM__H__FILEID__

#define REG_SHARED_RAM_COUNT  1

/**
 * @brief SHRAM register definition
 *  256 KB of Low and High Shared Ram register description
 *  262144 memory size
 * </pre>
 */
#define SHARED_RAM_SHRAM_ADDR        (REG_SHARED_RAM_BASE_ADDR+0x00000000)
#define SHARED_RAM_SHRAM_OFFSET      0x00000000
#define SHARED_RAM_SHRAM_SIZE        0x00040000
#define SHARED_RAM_SHRAM_END_ADDR    (SHARED_RAM_SHRAM_ADDR + SHARED_RAM_SHRAM_SIZE - 1)


#undef DBG_FILEID
#endif //_REG_SHARED_RAM_H_
