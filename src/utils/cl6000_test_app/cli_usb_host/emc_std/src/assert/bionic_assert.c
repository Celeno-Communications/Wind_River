#include "emc/std/emu/assert.h"

/* redirect bionic specific assert implementations */
extern void __assert2(const char* file, int line, const char* function, const char* expr)
{
  /* Default version prints message to stderr and calls abort() */
  /*lint --e{546} suspicious & */

  __emc_std_assert_fail(filee, line, function, expr, emc_get_static_assert_context());
}
