/**
 *
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/vendor/celeno/device/Tci.h"
#include "emc/vendor/celeno/device/TciReg.h"
#include "emc/std/ext/bitoperation.h"
#include "emc/std/assert.h"

void EMC_CELENO_TCI_init(void)
{
  EMC_CELENO_TCI_init_reg();
}

emc_std_bool EMC_CELENO_TCI_is_software_activation(void)
{
  emc_std_uint32_t act = emc_slice32(emc_std_uint32_t, 1, 0, EMC_CELENO_TCI_read_reg(0x04));
  return act == 0x0;
}

void EMC_CELENO_TCI_add_pdma(const PdmaDescriptor* pdma_desc,
                             emc_std_uint32_t pdma_desc_index,
                             emc_std_size_t len1st,
                             emc_std_bool non_std)
{
  emc_std_uint32_t val;
  emc_std_size_t   total_size = PdmaDescriptor_transfer_size(pdma_desc);

  // NON_STD_CTRL
  val = 0;
  emc_set_bit32(&val, 8, non_std);
  if (non_std) {
    emc_set_slice32(7, 0, &val, len1st);
  }
  EMC_CELENO_TCI_write_reg(0x18, val);

  // TOTAL_PACKET_LEN
  EMC_CELENO_TCI_write_reg(0x14, (emc_std_uint32_t)total_size);

  if (!non_std) {
    if (len1st) {
      // ETH_PKT_1ST_PART_LEN
      EMC_CELENO_TCI_write_reg(0x10, (emc_std_uint32_t)len1st);
      // ETH_PKT_START_ADDR2
      val = 0;
      emc_set_slice32(23, 0, &val, PdmaDescriptor_destination_address(pdma_desc) + len1st);
      EMC_CELENO_TCI_write_reg(0x0C, val);
    }
  }

  // ETH_PKT_START_ADDR
  val = 0;
  emc_set_slice32(31, 29, &val, PdmaDescriptor_LLI_channel_ds(pdma_desc));
  emc_set_slice32(28, 24, &val, pdma_desc_index);
  emc_set_slice32(23, 2, &val, (PdmaDescriptor_destination_address(pdma_desc) >> 2));
  emc_set_bit32(&val, 1, PdmaDescriptor_padding_present(pdma_desc));
  EMC_CELENO_TCI_write_reg(0x08, val);
}

emc_std_bool EMC_CELENO_TCI_is_pdma_done(emc_std_uint32_t pdma_desc_index)
{
  return emc_test_bit32(EMC_CELENO_TCI_read_reg(0x1C), pdma_desc_index);
}

emc_std_size_t EMC_CELENO_TCI_len1st_for_size(emc_std_size_t size)
{
  emc_std_assert(size > 4);
  emc_std_assert(!(size & 0x3));

  return size >> 1;
}

emc_std_size_t EMC_CELENO_TCI_nonstd_offset_for_pdma(const PdmaDescriptor* pdma_desc)
{
  emc_std_size_t offset;

  offset = 14;
  if (PdmaDescriptor_padding_present(pdma_desc)) {
    offset += 2;
  }

  return offset;
}

#if EMC_TEST

void EMC_CELENO_TCI_enable_software_activation(emc_std_bool enable)
{
  emc_std_uint32_t ctrl = EMC_CELENO_TCI_read_reg(0x04);
  emc_set_slice32(1, 0, &ctrl, enable ? 0x0 : 0x1);
  EMC_CELENO_TCI_write_reg(0x04, ctrl);
}

#endif
