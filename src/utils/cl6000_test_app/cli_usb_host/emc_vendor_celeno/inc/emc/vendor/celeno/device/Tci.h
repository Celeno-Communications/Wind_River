/**
 * @file
 * @brief
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_VENDOR_CELENO_DEVICE_Tci_H
#define EMC_VENDOR_CELENO_DEVICE_Tci_H

#include "emc/vendor/celeno/configure.h"
#include "emc/usb/vendor/celeno/usbwrapper/device/PdmaDescriptor.h"
#include "emc/std/stdint.h"
#include "emc/std/stddef.h"
#include "emc/std/stdbool.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** Initialize the TCI module. */
void EMC_CELENO_TCI_init(void);

/** Check if the TCI module is configured to be activated by software. */
emc_std_bool EMC_CELENO_TCI_is_software_activation(void);

/** Insert @param pdma_desc with @param pdma_desc_index to TCI command queue
 * @param len1st Size of first part of packet in bytes for TCI split mode if non-standard = false,
 *               offset of IP header in non-standard packet.
 * @param non_std Mark packet as non-standard IPV4 packet, IP offset will be set to len1st.
 */
void EMC_CELENO_TCI_add_pdma(const PdmaDescriptor* pdma_desc,
                             emc_std_uint32_t pdma_desc_index,
                             emc_std_size_t len1st,
                             emc_std_bool non_std);

/** Check if TCI is done for done for pDMA with @param pdma_desc_index. */
emc_std_bool EMC_CELENO_TCI_is_pdma_done(emc_std_uint32_t pdma_desc_index);

/** Return the length of the first part for given @param size (TCI split testing helper). */
emc_std_size_t EMC_CELENO_TCI_len1st_for_size(emc_std_size_t size);

/** Return the offset of the IP packet for given @param pdma_desc (TCI non-standard testing helper). */
emc_std_size_t EMC_CELENO_TCI_nonstd_offset_for_pdma(const PdmaDescriptor* pdma_desc);

#if EMC_TEST

/** Configure the TCI module SW activation mode. */
void EMC_CELENO_TCI_enable_software_activation(emc_std_bool enable);

#endif

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_VENDOR_CELENO_DEVICE_Tci_H */
