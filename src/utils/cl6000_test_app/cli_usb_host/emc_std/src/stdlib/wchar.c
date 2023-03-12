/**
 * @file
 * @brief   implementation of the wchar.h prototypes
 *
 *
 * @author  Steffen <steffen.luzemann@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 ****************************************************************************/

#include "emc/std/assert.h"
#include "emc/std/wchar.h"
#include "emc/std/stdint.h"
#include "emc/std/emu/wchar.h"

emc_std_wchar_t* emc_wcscpy(emc_std_wchar_t* s1, const emc_std_wchar_t* s2)
{
  emc_std_uint32_t i = 0;
  while (*(s2 + i) != 0) {
    *(s1 + i) = *(s2 + i);
    i++;
  }
  *(s1 + i) = *(s2 + i);
  return s1;
}

emc_std_wchar_t* emc_wcsncpy(emc_std_wchar_t* dst, const emc_std_wchar_t* src, emc_std_size_t size)
{
  emc_std_size_t i;
  for (i = 0; i < size; ++i) {
    if (L'\0' == (dst[i] = src[i])) {
      break;
    }
  }
  for (; i < size; ++i) {
    dst[i] = L'\0';
  }
  return dst;
}

emc_std_size_t emc_wcslen(const emc_std_wchar_t* s)
{
  emc_std_uint32_t char_number = 0;
  while (*(s + char_number) != 0x0000) {
    char_number++;
  }
  return (emc_std_size_t)char_number;
}
