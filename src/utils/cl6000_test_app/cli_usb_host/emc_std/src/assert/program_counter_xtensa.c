#include "emc/std/emu/program_counter.h"
#include "emc/std/stdint.h"

#define MAKE_PC_FROM_RA(ra, sp)    (((ra)& 0x3fffffff) | ((sp)& 0xc0000000))

void* emc_std_get_pc(void)
{
  emc_std_uint32_t ret_addr;
  emc_std_uint32_t stack_addr;
  __asm__ __volatile__ ("" ::: "memory");
  {
    register emc_std_uint32_t retptr __asm__ ("a0");
    register emc_std_uint32_t stackptr __asm__ ("a1");
    ret_addr = retptr;
    stack_addr = stackptr;
  }
  __asm__ __volatile__ ("" ::: "memory");

  return (void*)MAKE_PC_FROM_RA(ret_addr, stack_addr);
}
