/* Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#include <emc/std/errno.h>

typedef int*(* errno_func)(void);
static int        mg_errno;
static errno_func mg_errno_func;

/* Multithreaded projects must provide access to a thread-specific
   variable by registering a system-specific callback */
void emc_std_internal_set_errno_func(errno_func func)
{
  mg_errno_func = func;
}

int* emc_std_internal_errno()
{
  return mg_errno_func ? (*mg_errno_func)() : &mg_errno;
}
