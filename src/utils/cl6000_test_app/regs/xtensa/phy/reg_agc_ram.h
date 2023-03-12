#ifndef _REG_AGC_RAM_H_
#define _REG_AGC_RAM_H_

#include <stdint.h>
#include "phy/_reg_agc_ram.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_AGC_RAM__H__FILEID__

#define REG_AGC_RAM_COUNT  2

/**
 * @brief AGC_RAM register definition
 *  AGC Memory register description
 *  2048 memory size
 * </pre>
 */
#define AGC_RAM_AGC_RAM_ADDR        (REG_AGC_RAM_BASE_ADDR+0x00000000)
#define AGC_RAM_AGC_RAM_OFFSET      0x00000000
#define AGC_RAM_AGC_RAM_SIZE        0x00000800
#define AGC_RAM_AGC_RAM_END_ADDR    (AGC_RAM_AGC_RAM_ADDR + AGC_RAM_AGC_RAM_SIZE - 1)
/**
 * @brief FCAGC_RAM register definition
 *  FCAGC Memory register description
 *  512 memory size
 * </pre>
 */
#define AGC_RAM_FCAGC_RAM_ADDR        (REG_AGC_RAM_BASE_ADDR+0x00009000)
#define AGC_RAM_FCAGC_RAM_OFFSET      0x00009000
#define AGC_RAM_FCAGC_RAM_SIZE        0x00000200
#define AGC_RAM_FCAGC_RAM_END_ADDR    (AGC_RAM_FCAGC_RAM_ADDR + AGC_RAM_FCAGC_RAM_SIZE - 1)


#undef DBG_FILEID
#endif //_REG_AGC_RAM_H_
