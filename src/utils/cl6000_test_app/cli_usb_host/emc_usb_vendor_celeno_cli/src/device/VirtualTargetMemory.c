/** Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/usb/vendor/celeno/cli/TargetMemory.h"
#include "emc/std/assert.h"
#include "emc/system/celeno/configure.h"

typedef struct memory_section_s {
  emc_std_uint32_t  physical_addr;
  emc_std_uint32_t* virtual_addr;
  emc_std_size_t    size;
} memory_section_t;

#define MAX_MEMORY_SECTIONS 10
static memory_section_t mg_memory_sections[MAX_MEMORY_SECTIONS] = {0};

void EMC_USB_CELENO_CLI_TargetMemory_add(void* memory, emc_std_uint32_t physical_addr, size_t size)
{
  for (emc_std_size_t i = 0; i < MAX_MEMORY_SECTIONS; i++) {
    if (mg_memory_sections[i].size == 0) {
      mg_memory_sections[i].physical_addr = physical_addr;
      mg_memory_sections[i].virtual_addr = memory;
      mg_memory_sections[i].size = size;
      return;
    }
  }
  emc_std_assert(0);
}

int EMC_USB_CELENO_CLI_TargetMemory_init(size_t size)
{
  for (emc_std_size_t section = 0; section < MAX_MEMORY_SECTIONS; section++) {
    if (mg_memory_sections[section].size) {
      emc_std_uint32_t* ptr = mg_memory_sections[section].virtual_addr;
      for (emc_std_size_t i = 0; i < mg_memory_sections[section].size / sizeof(emc_std_uint32_t); ++i) {
        *ptr++ = 0xDEADBEEF;
      }
    }
  }
  UNUSED_PARAM(size);
  return 0;
}

int EMC_USB_CELENO_CLI_TargetMemory_exit()
{
  return 0;
}

emc_std_uint32_t EMC_USB_CELENO_CLI_TargetMemory_begin()
{
  if (mg_memory_sections[0].size) {
    return mg_memory_sections[0].physical_addr;
  }
  return 0;
}

emc_std_uint32_t* EMC_USB_CELENO_CLI_TargetMemory_ptr(emc_std_uint32_t address)
{
  for (emc_std_size_t section = 0; section < MAX_MEMORY_SECTIONS; section++) {
    memory_section_t* sec = &mg_memory_sections[section];
    if (sec->size) {
      if ((sec->physical_addr <= address) && (address < sec->physical_addr + sec->size)) {
        return (emc_std_uint32_t*)(((emc_std_uint8_t*)sec->virtual_addr) + (address - sec->physical_addr));
      }
    }
  }
  emc_std_assert(0);
}
