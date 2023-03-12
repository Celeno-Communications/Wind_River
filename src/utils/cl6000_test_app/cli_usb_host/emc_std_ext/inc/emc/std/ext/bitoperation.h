/**
 * @file
 * @brief   some bit and word operations
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de>
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2020-2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_STD_EXT_bitoperation_H
#define EMC_STD_EXT_bitoperation_H

#include "emc/std/configure.h"
#include "emc/std/stdint.h"
#include <emc/std/stdbool.h>

#include "emc/std/ext/ct_assert.h"

/*lint --e{528}*/
/* lint isn't able to recognise the "inline" key word */

/*lint --e{014}*/
/* lint sees double declaration of these inline functions */

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** convert 2 uint8 to one uint16 */
static inline emc_std_uint16_t emc_to_uint16(emc_std_uint8_t high, emc_std_uint8_t low)
{
  return (emc_std_uint16_t)((((emc_std_uint16_t)(high)) << 8) + low);
}

/** extract high uint8 part of an uint16 */
#define emc_high_uint8(v) ((emc_std_uint8_t)(((v) >> 8) & 0xff))

/** extract low uint8 part of an uint16 */
#define emc_low_uint8(v) ((emc_std_uint8_t)((v) & 0xff))

/** extract high uint16 part of an uint32 */
#define emc_high_uint16(v) ((emc_std_uint16_t)(((v) >> 16) & 0xffff))

/** extract low uint16 part of an uint32 */
#define emc_low_uint16(v) ((emc_std_uint16_t)((v) & 0xffff))

#if !defined(emc_bitmask) || EMC_DOXYGEN
/**
 * Calculate a bitmask by specifying a range of set bits.
 *
 * Return a number where only bits from @c from_bit to @c to_bit are
 * set to one.
 *
 * If @c from_bit is bigger than the number of bits in the used
 * integral type or bigger than @c to_bit the result is undefined.
 *
 * @par Example:
 * @code
 * emc_bitmask(6,3)   == 0x0078   // 0000 0000 0111 1000
 * emc_bitmask(15,13) == 0xE000   // 1110 0000 0000 0000
 * emc_bitmask(4,4)   == 0x0010   // 0000 0000 0001 0000
 * @endcode
 *
 * @note We do @e not use <tt>(((1 << ((from_bit)+1)) - 1) ^ ((1
 * << (to_bit)) - 1))</tt> as this might cause an int overflow when
 * @c from_bit is the MSB.
 *
 * @ingroup emc_base_data_interface
 */
#  define  emc_bitmask(from_bit, to_bit)                                       \
  (((((1UL << (from_bit)) - 1) << 1) + 1) ^ ((1UL << (to_bit)) - 1))
#endif

/**
 * Sets a bit in a byte.
 *
 * @param b a byte
 * @param n the bit number
 * @param flag the value of the bit.
 */
static inline void emc_set_bit8(volatile emc_std_uint8_t* b, unsigned int n, emc_std_bool flag)
{
  *b = (emc_std_uint8_t)(flag
                         ? (emc_std_uint8_t)(*b | (emc_std_uint8_t)(1U << n))
                         : (emc_std_uint8_t)(*b & (emc_std_uint8_t) ~(1U << n)));
}

/**
 * Tests a bit in a byte.
 *
 * @param b a byte
 * @param n the bit number
 * @return bit value
 */
static inline emc_std_bool emc_test_bit8(volatile emc_std_uint8_t b, unsigned int n)
{
  return (b & (1 << n)) ? emc_std_true : emc_std_false;
}

/**
 * Sets a bit in a emc_std_uint16_t.
 *
 * @param b a byte
 * @param n the bit number
 * @param flag the value of the bit.
 */
static inline void emc_set_bit16(volatile emc_std_uint16_t* b, unsigned int n, emc_std_bool flag)
{
  *b = (emc_std_uint16_t)(flag
                          ? (emc_std_uint16_t)(*b | (emc_std_uint16_t)(1U << n))
                          : (emc_std_uint16_t)(*b & (emc_std_uint16_t) ~(1U << n)));
}

/**
 * Tests a bit in a emc_std_uint16_t.
 *
 * @param b a byte
 * @param n the bit number
 * @return bit value
 */
static inline emc_std_bool emc_test_bit16(volatile emc_std_uint16_t b, unsigned int n)
{
  return (b & (1 << n)) ? emc_std_true : emc_std_false;
}

/**
 * Sets a bit in a emc_std_uint32_t.
 *
 * @param b a emc_std_uint32_t
 * @param n the bit number
 * @param flag the value of the bit.
 */
static inline void emc_set_bit32(volatile emc_std_uint32_t* b, unsigned int n, emc_std_bool flag)
{
  *b = (emc_std_uint32_t)(flag
                          ? (emc_std_uint32_t)(*b | (emc_std_uint32_t)(1U << n))
                          : (emc_std_uint32_t)(*b & (emc_std_uint32_t) ~(1U << n)));
}

/**
 * Tests a bit in a emc_std_uint32_t.
 *
 * @param b a emc_std_uint32_t
 * @param n the bit number
 * @return bit value
 */
static inline emc_std_bool emc_test_bit32(volatile emc_std_uint32_t b, unsigned int n)
{
  return (b & (emc_std_uint32_t)(1 << n)) ? emc_std_true : emc_std_false;
}

/** @name Read a Bit-Slice
    Read the value of multiple bits (a so called bit slice).
    @{

    extracts the specified bits and converts the result into an integer type <S> (S - SliceType)
    (i.e. the selected bits are masked, and then shifted right so that
    the least selected bit is at the LSB of the result)
    example: to get bit 9:4 of data into an std::uint8_t, call emc_slice16(std::uint8_t, 9, 4, data);
 */

#define emc_slice8(S, h_bit, l_bit, input)                             \
  (S)(((input) & emc_bitmask((h_bit), (l_bit))) >> (l_bit))

#define emc_slice16(S, h_bit, l_bit, input)                             \
  (S)(((input) & emc_bitmask((h_bit), (l_bit))) >> (l_bit))

#define emc_slice32(S, h_bit, l_bit, input)                             \
  (S)(((input) & emc_bitmask((h_bit), (l_bit))) >> (l_bit))

/** @} */

/** @name Writes a Bit-Slice
    Writes the value of multiple bits (a so called bit slice).
    @{

    Writes multiple bits (a bit slice).
    @param input A 64/32/16/8-bit word.
    @param val The new value for that slice.
    @param h_bit The high bit position offset.
    @param l_bit The low bit position offset.
 */

#define emc_set_slice8(h_bit, l_bit, input, val)                       \
  {                                                                     \
    EMC_CT_ASSERT((h_bit) + 1 - (l_bit) <= sizeof(val) * 8) /*slice type to small*/; \
    EMC_CT_ASSERT((h_bit) >= (l_bit));                    /* h_bit has to be >= l_bit*/ /*lint !e685*/ \
    EMC_CT_ASSERT((h_bit) < sizeof(emc_std_uint8_t) * 8); /*h_bit out of source type size*/ \
    EMC_CT_ASSERT((l_bit) < sizeof(emc_std_uint8_t) * 8); /*l_bit out of source type size*/ \
  }                                                                     \
  (*input) = (emc_std_uint8_t)(((*input) & (emc_std_uint8_t)(~emc_bitmask((h_bit), (l_bit))))   \
                               | ((emc_std_uint8_t)(emc_bitmask((h_bit), (l_bit)))   \
                                  & (emc_std_uint8_t)((emc_std_uint8_t)(val) << (l_bit))))

#define emc_set_slice16(h_bit, l_bit, input, val)                       \
  {                                                                     \
    EMC_CT_ASSERT((h_bit) + 1 - (l_bit) <= sizeof(val) * 8) /*slice type to small*/; \
    EMC_CT_ASSERT((h_bit) >= (l_bit));                     /* h_bit has to be >= l_bit*/ /*lint !e685*/ \
    EMC_CT_ASSERT((h_bit) < sizeof(emc_std_uint16_t) * 8); /*h_bit out of source type size*/ \
    EMC_CT_ASSERT((l_bit) < sizeof(emc_std_uint16_t) * 8); /*l_bit out of source type size*/ \
  }                                                                     \
  (*input) = (emc_std_uint16_t)(((*input) & (emc_std_uint16_t)(~emc_bitmask((h_bit), (l_bit))))   \
                                | ((emc_std_uint16_t)(emc_bitmask((h_bit), (l_bit)))   \
                                   & (emc_std_uint16_t)((emc_std_uint16_t)(val) << (l_bit))))

#define emc_set_slice32(h_bit, l_bit, input, val)                       \
  {                                                                     \
    EMC_CT_ASSERT((h_bit) + 1 - (l_bit) <= sizeof(val) * 8) /*slice type to small*/; \
    EMC_CT_ASSERT((h_bit) >= (l_bit));                     /* h_bit has to be >= l_bit*/ /*lint !e685*/ \
    EMC_CT_ASSERT((h_bit) < sizeof(emc_std_uint32_t) * 8); /*h_bit out of source type size*/ \
    EMC_CT_ASSERT((l_bit) < sizeof(emc_std_uint32_t) * 8); /*l_bit out of source type size*/ \
  }                                                                     \
  (*input) = (emc_std_uint32_t)(((*input) & (emc_std_uint32_t)(~emc_bitmask((h_bit), (l_bit))))   \
                                | ((emc_std_uint32_t)(emc_bitmask((h_bit), (l_bit)))   \
                                   & (emc_std_uint32_t)((emc_std_uint32_t)(val) << (l_bit))))

/** @} */

// clang-format off extern C
#  ifdef __cplusplus
}
#  endif
// clang-format on extern C

#endif /*EMC_STD_EXT_bitoperation_H*/
