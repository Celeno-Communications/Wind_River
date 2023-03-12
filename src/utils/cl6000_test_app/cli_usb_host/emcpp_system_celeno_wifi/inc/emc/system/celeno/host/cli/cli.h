#ifndef EMC_SYSTEM_CELENO_HOST_CLI_cli_H
#define EMC_SYSTEM_CELENO_HOST_CLI_cli_H

#include <stdint.h>
#include <stddef.h>

/* Todo: document, that this header is for backward compatibility
 * everything is deprecated
 * new code shall use cli_usb.h
 */

/*
 * Reads the 32 bit register located ot <offset>.
 * The offset must be a multiple of 4.
 */
uint32_t cl_reg_read32(uint32_t offset);

/*
 * Writes <value> into the 32 bit register located at <offset>
 * Offset must be a multiple of 4.
 */
void cl_reg_write32(uint32_t offset, uint32_t value);

/*
 * Read a register and return true if (<value> & <bit_mask>) != 0.
 */
uint32_t cl_reg_get_bit(uint32_t reg, uint32_t bit_mask);

/*
 * Set bits that are 1 in the bit_mask. Bits that are not set are unchanged.
 */
void cl_reg_set_bit(uint32_t reg, uint32_t bit_mask);

/*
 * Clear bits that are 1 in the bitmask. Other bits are unchanged.
 */
void cl_reg_clear_bit(uint32_t reg, uint32_t bit_mask);

/*
 * Return (<value> & <mask>) >> <lsb>.
 */
uint32_t cl_reg_get_field(uint32_t reg, uint32_t mask, uint32_t lsb);

/*
 * Set bits (<value> << <lsb>) & mask. Only bits that are set to 1 in mask are changed.
 */
void cl_reg_set_field(uint32_t reg, uint32_t mask, uint32_t lsb, uint32_t val);

/// Helper
static inline int cl_reg_open(void)
{
  return 0;
}

static inline void cl_reg_close(void)
{}

#endif /* EMC_SYSTEM_CELENO_HOST_CLI_cli_H */
