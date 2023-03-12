#ifndef _CL_REG_H_
#define _CL_REG_H_

#include <stdint.h>
#include "cli_usb.h"

#define XTENSA_PIF_BASE_ADDR 0x60000000

/*
 * Initializes the cl_reg facility.
 * Returns 0 on success and -1 upon failure.
 * In the latter case, errno will contain the error code.
 */

enum {
	CL_DEVICE_IS_PCI,
	CL_DEVICE_IS_USB
};

uint32_t (*cl_reg_read32)(uint32_t offset);
void (*cl_reg_write32)(uint32_t offset, uint32_t value);
int cl_reg_open(void);
void cl_reg_close(void);
int cl_get_wifi_mode(void);

static inline uint32_t cl_reg_get_bit(uint32_t reg, uint32_t bit)
{
	uint32_t retval = 0;

	retval = cl_reg_read32(reg);
	return !!(retval & bit);
}

static inline void cl_reg_set_bit(uint32_t reg, uint32_t bit)
{
	uint32_t retval = 0;

	retval = cl_reg_read32(reg);
        retval |= bit;
	cl_reg_write32(reg, retval);
}

static inline void cl_reg_clear_bit(uint32_t reg, uint32_t bit)
{
	uint32_t retval = 0;

        retval = cl_reg_read32(reg);
        retval &= ~bit;
	cl_reg_write32(reg, retval);
}

static inline uint32_t cl_reg_get_field(uint32_t reg, uint32_t mask, uint32_t lsb)
{
	uint32_t retval = 0;

	retval = cl_reg_read32(reg);
        return (retval & mask) >> lsb;
}

static inline void cl_reg_set_field(uint32_t reg, uint32_t mask, uint32_t lsb, uint32_t val)
{
	uint32_t retval = 0;

	retval = cl_reg_read32(reg);
	retval &= ~mask;
	retval |= (val<<lsb);
        cl_reg_write32(reg, retval);
}


void cl_reg_write8(uint32_t reg, uint8_t val);
void cl_reg_write16(uint32_t reg, uint16_t val);
struct CLI_USB_Config *cl_get_usb_config(void);
void cl_reg_usb_configure_timeouts(uint32_t transfer_timeout_ms, uint32_t connection_timeout_ms);
void cl_reg_usb_configure_verbose(bool verbose);

#define REG_PL_RD(addr)       cl_reg_read32(addr)
#define REG_PL_WR(addr, val)  cl_reg_write32(addr, val)

#define CL_REG_WRITE(val, addr)   cl_reg_write32(addr, val)
#define CL_REG_READ(addr)         cl_reg_read32(addr)

#endif /* _CL_REG_H_ */
