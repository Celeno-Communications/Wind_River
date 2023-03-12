/**
 * @file
 * @author  Ralf Oberländer <ralf.oberlaender@emsys.de>
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#include "emc/hw/memory/PhysicalAddress.h"
#include "emc/vendor/celeno/device/AsicVersion.h"

int EMC_PhysicalAddress_is_supported(void)
{
  return 1;
}

inline static struct EMC_PhysicalAddress address_new(emc_std_uintptr_t address)
{
  struct EMC_PhysicalAddress physical_address;
  physical_address.handle = address;
  return physical_address;
}

// see CL6000 AXI spec.docx: Table 5, Table 12 - map 256kBytes instead of 192kBytes
//           internal=virtual            external=physical
// Step A
// UMAC DRAM 0x40000000 ... 0x4003FFFF   0x60280000 ... 0x602BFFFF
// UMAC IRAM 0x40080000 ... 0x400BFFFF   0x602C0000 ... 0x602FFFFF

// Step B
// UMAC DRAM 0x40000000 ... 0x4003FFFF   0x60280000 ... 0x602BFFFF  size 3FFFF
// UMAC IRAM 0x40080000 ... 0x400BFFFF   0x60500000 ... 0x6057FFFF  size 7FFFF

struct EMC_PhysicalAddress EMC_PhysicalAddress_new(void* address)
{
  if (((emc_std_uintptr_t)address & 0xFFFC0000) == 0x40000000) {
    return address_new(((emc_std_uintptr_t)address & 0x0003FFFF) + 0x60280000);
  }

  if ((mg_asic_version == EMC_USB_CELENO_STEP_A) && (((emc_std_uintptr_t)address & 0xFFFC0000) == 0x40080000)) {
    return address_new(((emc_std_uintptr_t)address & 0x0003FFFF) + 0x602C0000);
  }
  if ((mg_asic_version >= EMC_USB_CELENO_STEP_B) && (((emc_std_uintptr_t)address & 0xFFF80000) == 0x40080000)) {
    return address_new(((emc_std_uintptr_t)address & 0x0007FFFF) + 0x60500000);
  }

  return address_new((emc_std_uintptr_t)address);
}
