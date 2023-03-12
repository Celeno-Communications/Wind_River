/* Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#include <emc/std/signal.h>
#include <emc/std/errno.h>

typedef void (* handler)(int);

static handler mg_handler_sigabrt;

void emc_std_internal_sig_dfl(int sig)
{
  UNUSED_PARAM(sig);
}

handler emc_std_signal(int sig, handler func)
{
  if (func && (sig == EMC_STD_SIGABRT)) {
    handler result = mg_handler_sigabrt ? mg_handler_sigabrt : EMC_STD_SIG_DFL;
    mg_handler_sigabrt = func;
    return result;
  } else {
    return EMC_STD_SIG_ERR;
  }
}

int emc_std_raise(int sig)
{
  if (sig == EMC_STD_SIGABRT) {
    if (mg_handler_sigabrt) {
      (*mg_handler_sigabrt)(sig);
    }
#if !defined(__KLOCWORK__)
    /* avoid a INFINITE_LOOP warning in klocwork
       this is a fallback to avoid leaving the raise() function,
       when no abort handler was set */
    while (1) {}
#else
    return -1;
#endif
  } else {
    emc_std_errno = EMC_STD_ENOTSUP;
    return -1;
  }
}
