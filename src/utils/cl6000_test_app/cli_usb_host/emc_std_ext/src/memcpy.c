#include "emc/std/ext/memcpy.h"
#include "emc/std/stdint.h"

void* emc_std_ext_memcpy(void* dst, const void* src, emc_std_size_t n)
{
  emc_std_size_t*       dst_cpu = (emc_std_size_t*)dst;
  emc_std_size_t const* src_cpu = (emc_std_size_t const*)src;

  if ((((emc_std_size_t)src & (EMC_SIZEOF_POINTER - 1)) == 0) &&
      (((emc_std_size_t)dst & (EMC_SIZEOF_POINTER - 1)) == 0))
  {
    while (n >= EMC_SIZEOF_POINTER) {
      *dst_cpu++ = *src_cpu++;
      n -= EMC_SIZEOF_POINTER;
    }
  }

  {
    emc_std_uint8_t*       dst8 = (emc_std_uint8_t*)dst_cpu;
    emc_std_uint8_t const* src8 = (emc_std_uint8_t const*)src_cpu;
    while (n--) {
      *dst8++ = *src8++;
    }
  }
  return dst;
}
