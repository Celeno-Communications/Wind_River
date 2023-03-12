#ifndef _REG_LOGGER_RAM_H_
#define _REG_LOGGER_RAM_H_

#include <stdint.h>
#include "_reg_logger_ram.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_LOGGER_RAM__H__FILEID__

#define REG_LOGGER_RAM_COUNT  1

/**
 * @brief RAM register definition
 *  128K loggers memory register description
 *  131072 memory size
 * </pre>
 */
#define LOGGER_RAM_RAM_ADDR        (REG_LOGGER_RAM_BASE_ADDR+0x00000000)
#define LOGGER_RAM_RAM_OFFSET      0x00000000
#define LOGGER_RAM_RAM_SIZE        0x00020000
#define LOGGER_RAM_RAM_END_ADDR    (LOGGER_RAM_RAM_ADDR + LOGGER_RAM_RAM_SIZE - 1)


#undef DBG_FILEID
#endif //_REG_LOGGER_RAM_H_
