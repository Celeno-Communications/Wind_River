#include "emc/std/emu/assert.h"

/* redirect arm specific assert implementation */
extern void __aeabi_assert(const char* expr, const char* file, int line)
{
  /* Default version prints message to stderr and calls abort() */
  /*lint --e{546} suspicious & */
  __emc_std_assert_fail(file, line, 0, expr, emc_get_static_assert_context());
}
