/* Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#include <emc/std/ctype.h>
#include <emc/std/errno.h>
#include <emc/std/limits.h>
#include <emc/std/signal.h>
#include <emc/std/stdlib.h>

#include <emc/std/assert.h>

// MSVC does not allow definition of intrinsic functions ?
int emc_std_abs(int n)
{
  return (n < 0) ? -n : n;
}

void (emc_std_abort)(void) {
  emc_std_raise(EMC_STD_SIGABRT);
#if !defined(__KLOCWORK__)
  // avoid a INFINITE_LOOP warning in klocwork
  // this is only a fallback, when raise does not abort
  while (1) {}
#endif
}

typedef void (* at_exit_handler_t)(void);

// this should be potentially a dynamic set of handler
// for a more sophisticated emulation
// currently only a fixed number of handlers is supported

#define ATEXIT_HANDLER_MAX 32

static at_exit_handler_t mg_atexit_handler[ATEXIT_HANDLER_MAX];
// potentially the count should be atomic
static unsigned int mg_atexit_handler_count = 0;

void emc_std_exit(int code)
{
  unsigned int i;

  for (i = mg_atexit_handler_count; i > 0; --i) {
    (*mg_atexit_handler[i - 1])();
  }
  emc_std__Exit(code);
}

int emc_std_atexit(void (* func)(void))
{
  if (func) {
    if (mg_atexit_handler_count < ATEXIT_HANDLER_MAX) {
      mg_atexit_handler[mg_atexit_handler_count++] = func;
      return 0;
    }
  }
  return -1;
}

#if defined(__arm)
volatile int emc_std_exit_emu_trap_never_returns = 1;
#else
#  define emc_std_exit_emu_trap_never_returns 1
#endif

void emc_std__Exit(int code)
{
  UNUSED_PARAM(code);
#if !defined(__KLOCWORK__)
#  if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 410000)
#    if (__TARGET_ARCH_ARM >= 5)
  __breakpoint(255);
#    endif
#  endif

  // avoid a INFINITE_LOOP warning in klocwork
  while (emc_std_exit_emu_trap_never_returns) {}
#endif
}

long(emc_std_atol)(const char* nptr) {
#if 0
  return emc_std_strtol(nptr, (char**)0, 10);
#else
  while ((emc_std_isspace)(*nptr)) {
    ++nptr;
  }
  if ('-' != *nptr) {
    if ((emc_std_isdigit)(*nptr)) {
      long result = *nptr++ - '0';
      while ((emc_std_isdigit)(*nptr)) {
        int digit = *nptr++ - '0';
        if ((EMC_STD_LONG_MAX / 10 > result) ||
            ((EMC_STD_LONG_MAX / 10 == result) && ((EMC_STD_LONG_MAX % 10) >= digit)))
        {
          result = result * 10 + digit;
        } else {
          emc_std_errno = EMC_STD_ERANGE;
          return EMC_STD_LONG_MAX;
        }
      }
      return result;
    }
  } else { /* negative result */
    if ((emc_std_isdigit)(*++nptr)) {
      long result = '0' - *nptr++;
      while ((emc_std_isdigit)(*nptr)) {
        int digit = '0' - *nptr++;
        if ((EMC_STD_LONG_MIN / 10 < result) ||
            ((EMC_STD_LONG_MIN / 10 == result) && ((EMC_STD_LONG_MIN % 10) <= digit)))
        {
          result = result * 10 + digit;
        } else {
          emc_std_errno = EMC_STD_ERANGE;
          return EMC_STD_LONG_MIN;
        }
      }
      return result;
    }
  }
  return 0;
#endif
}

#if 1 /* indirection to atol is already done inline in header!*/
int(emc_std_atoi)(const char* nptr) {
#  if 0
  return (int)emc_std_strtol(nptr, (char**)0, 10);
#  else
  return (int)emc_std_atol(nptr);
#  endif
}
#endif

long(emc_std_strtol)(const char* str, char** endptr, int base) {
  if (endptr || (base != 10)) {
    assert(0);
  }
  return emc_std_atol(str);
}

unsigned long(emc_std_strtoul)(const char* str, char** endptr, int base) {
  if (endptr || (base != 10)) {
    assert(0);
  }
  return (unsigned long)emc_std_atol(str);
}
