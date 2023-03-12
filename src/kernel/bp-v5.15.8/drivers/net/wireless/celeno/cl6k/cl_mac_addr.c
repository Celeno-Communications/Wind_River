// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_mac_addr.h"
#include "cl_otp.h"

static int set_mask_addr_without_zeroing_bits(struct cl_hw *cl_hw, u64 mac64, u8 bss_num,
					      u8 first_mask_bit, u8 *mask_addr)
{
	u64 mask = mac64;
	s8 idx = 0;

	mask >>= first_mask_bit;
	mask += (bss_num - 1);

	/*
	 * After the following line the mask will contain the changed
	 * bits between the first BSS MAC and the last BSS MAC
	 */
	mask ^= (mac64 >> first_mask_bit);

	/* Find leftmost set bit */
	for (idx = 47 - first_mask_bit; (idx >= 0) && (!(mask & (1ULL << idx))); idx--)
		;

	if (idx < 0) {
		cl_dbg_err(cl_hw, "Invalid mask (mac=0x%02llx, first_mask_bit=%u, bss_num=%u)\n",
			   mac64, first_mask_bit, bss_num);
		mask = 0;
		eth_zero_addr(mask_addr);

		return -1;
	}

	mask = (1ULL << idx);
	mask |= (mask - 1);
	mask <<= first_mask_bit;

	for (idx = 0; idx < ETH_ALEN; idx++) {
		u8 shift = (8 * (ETH_ALEN - 1 - idx));

		mask_addr[idx] = (mask & ((u64)0xff << shift)) >> shift;
	}

	return 0;
}

static int mask_mac_by_bss_num(struct cl_hw *cl_hw, u8 *mac_addr, u8 *mask_addr,
			       bool use_lam, bool random_mac)
{
	u8 bss_num = cl_hw->conf->ce_bss_num;
	u8 first_mask_bit = cl_hw->chip->conf->ce_first_mask_bit;
	u8 i;
	/* Determine the bits necessary to cover the number of BSSIDs. */
	u8 num_bits_to_mask[MAX_BSS_NUM * 2 + 1] = {
		0, 0, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4
	};
	u8 mask_size = 0;
	u8 byte_num = ETH_ALEN - 1 - (first_mask_bit / 8);
	u8 bit_in_byte = first_mask_bit % 8; /* Referring to the index of the bit */

	if ((first_mask_bit + num_bits_to_mask[bss_num]) > (ETH_ALEN * 8)) {
		pr_err("Invalid combination of first_mask_bit + bss_num. "
		       "must be lower than 48 bit in total\n");
		return -1;
	}

	mask_size = num_bits_to_mask[bss_num - 1];

	/* Build mac and mask addr */
	for (i = 0; i < mask_size; i++) {
		/*
		 * Build mask - Convert to "1" the relevant bits in the mask
		 * addr in order to support the desired number of BSSIDs
		 */
		mask_addr[byte_num] |= (0x01 << bit_in_byte);

		/*
		 * Build mac -convert to "0" the relevant bits in the mac addr
		 * in order to support the desired number of BSSIDs
		 */
		if (random_mac && !use_lam)
			mac_addr[byte_num] &= ~(0x01 << bit_in_byte);

		bit_in_byte++;

		/* Support cases where the mask bits are not at the same byte. */
		if (bit_in_byte == 8) {
			byte_num--;
			bit_in_byte = 0;
		}
	}

	if (use_lam) {
		/* Mask LAM bit (Locally Administered Mac) */
		mask_addr[0] |= 0x02;
	} else {
		/*
		 * When not using LAM we do not zero the MAC address of the second BSS,
		 * so the mask (the modified bits between the first and last BSS) depends
		 * on initial MAC
		 */
		u64 mac64 = ether_addr_to_u64(mac_addr);

		set_mask_addr_without_zeroing_bits(cl_hw, mac64, bss_num,
						   first_mask_bit, mask_addr);
	}

	return 0;
}

#define MAC_FILTER_BITS 4
#define MAC_FILTER_MASK ((1 << MAC_FILTER_BITS) - 1)

static bool is_valid_mac_addr(u64 mac64, u8 first_mask_bit, u8 bss_num)
{
	u8 mac_bits = (mac64 >> first_mask_bit) & MAC_FILTER_MASK;
	u8 mac_diff = 0;
	u8 i;

	for (i = 0; i < bss_num; i++) {
		mac_diff |= mac_bits;
		mac_bits++;
	}

	return hweight8(mac_diff) <= MAC_FILTER_BITS;
}

static int cl_mac_addr_set_addresses(struct cl_hw *cl_hw, bool use_lam,
				     u8 *mask_addr)
{
	u8 first_mask_bit = cl_hw->chip->conf->ce_first_mask_bit;
	int i = 0;
	u8 bss_num = cl_hw->conf->ce_bss_num;
	u64 mac64 = ether_addr_to_u64(cl_hw->hw->wiphy->perm_addr);
	u64 mask64 = 0;
	u8 new_addr[ETH_ALEN] = {0};

	if (!use_lam && !is_valid_mac_addr(mac64, first_mask_bit, bss_num)) {
		cl_dbg_err(cl_hw,
			   "perm_addr %pM is invalid for bss_num %d without LAM\n",
			   cl_hw->hw->wiphy->perm_addr, bss_num);
		return -1;
	}

	cl_mac_addr_copy(cl_hw->addresses[i].addr,
			 cl_hw->hw->wiphy->perm_addr);
	for (i = 1; i < bss_num; i++) {
		u8 *prev_addr = cl_hw->addresses[i - 1].addr;

		if (use_lam) {
			mac64 = ether_addr_to_u64(prev_addr);
			mask64 = ether_addr_to_u64(mask_addr);
			if (i == 1)
				mac64 &= ~mask64;
			else
				mac64 += 1ULL << first_mask_bit;
			u64_to_ether_addr(mac64, new_addr);
			new_addr[0] |= 0x02;
			cl_mac_addr_copy(cl_hw->addresses[i].addr, new_addr);
		} else {
			mac64 = ether_addr_to_u64(prev_addr);
			mac64 += 1ULL << first_mask_bit;
			u64_to_ether_addr(mac64, cl_hw->addresses[i].addr);
		}
	}
	cl_hw->n_addresses = bss_num;

	return 0;
}

static int cl_mac_addr_set_tcv0(struct cl_hw *cl_hw, u8 *dflt_mac,
				u8 *dflt_mask, bool *random_mac)
{
	struct cl_chip *chip = cl_hw->chip;

	if (!cl_mac_addr_is_zero(chip->conf->ce_phys_mac_addr)) {
		/* Read MAC from NVRAM file */
		cl_mac_addr_copy(dflt_mac, chip->conf->ce_phys_mac_addr);
		cl_dbg_verbose(cl_hw, "Read MAC address from NVRAM [%pM]\n", dflt_mac);
	} else {
		/* Read MAC from otp */
		if (chip->otp_read_block &&
		    cl_otp_read_bytes(chip, dflt_mac,
				      ETH_ALEN, ADDR_MAC_ADDR_OTP)) {
			CL_DBG_ERROR(cl_hw, "Error reading MAC address from otp\n");

			return -1;
		}

		cl_dbg_verbose(cl_hw, "Read MAC address from otp [%pM]\n", dflt_mac);
	}

	/* Test if the new mac address is 00:00:00:00:00:00 or ff:ff:ff:ff:ff:ff */
	if (cl_mac_addr_is_zero(dflt_mac) || cl_mac_addr_is_broadcast(dflt_mac)) {
		/* Set celeno oui */
		dflt_mac[0] = 0x00;
		dflt_mac[1] = 0x1c;
		dflt_mac[2] = 0x51;
		get_random_bytes(&dflt_mac[3], 3);
		cl_dbg_verbose(cl_hw, "Random MAC address [%pM]\n", dflt_mac);
		*random_mac = true;
	}

	return 0;
}

int cl_mac_addr_set(struct cl_hw *cl_hw)
{
	bool random_mac = false;
	u8 dflt_mac[ETH_ALEN] = {0, 28, 81, 81, 81, 81};
	u8 dflt_mask[ETH_ALEN] = {0};
	bool use_lam = cl_hw->chip->conf->ce_lam_enable;
	struct wiphy *wiphy = cl_hw->hw->wiphy;

	if (cl_mac_addr_set_tcv0(cl_hw, dflt_mac, dflt_mask, &random_mac))
		return -1;

	/* For single BSS mask should be 0 */
	if (cl_hw->conf->ce_bss_num > 1)
		if (mask_mac_by_bss_num(cl_hw, dflt_mac, dflt_mask, use_lam, random_mac))
			return -1;

	/* Permanent address MAC (the MAC of the first BSS) */
	SET_IEEE80211_PERM_ADDR(cl_hw->hw, dflt_mac);

	/*
	 * MAX_BSS_NUM must be power of 2
	 * mac80211 doesn't handle non-contiguous masks
	 */
	if (!WARN_ON(MAX_BSS_NUM & (MAX_BSS_NUM - 1)))
		cl_mac_addr_array_to_nxmac(dflt_mask, &cl_hw->mask_low, &cl_hw->mask_hi);

	if (cl_mac_addr_set_addresses(cl_hw, use_lam, dflt_mask))
		return -1;

	wiphy->addresses = cl_hw->addresses;
	wiphy->n_addresses = cl_hw->n_addresses;

	return 0;
}
