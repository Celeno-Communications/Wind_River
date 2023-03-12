/** @file
    @brief Declares a type and two functions and defines several
           macros, for handling various signals.

    @see www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf
         7.14 Signal handling

    @see http://pubs.opengroup.org/onlinepubs/009695399/basedefs/signal.h.html

    Copyright (C) 2011, 2012 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EMU_signal_H
#define EMC_STD_EMU_signal_H

// clang-format off extern C
#  if defined(__cplusplus)
extern "C" {
#  endif
// clang-format on extern C

/** Chooses how the receipt of the signal number @c sig is to be
    subsequently handled */
void(*emc_std_signal(int sig, void (* func)(int)))(int);

/** Sends the signal sig to the executing thread */
int emc_std_raise(int sig);

/** Integral type of an object that can be accessed as an atomic
    entity, even in the presence of asynchronous interrupts */
/*typedef int emc_std_sig_atomic_t;*/

#ifdef _POSIX_SOURCE
struct emc_std_pthread_attr_t;

union emc_std_sigval {
  int   sival_int;
  void* sival_ptr;
};

struct emc_std_sigevent {
  int                            sigev_notify;
  int                            sigev_signo;
  union emc_std_sigval           sigev_value;
  void                           (* sigev_notify_function)(union emc_std_sigval);
  struct emc_std_pthread_attr_t* sigev_notify_attributes;
};

#endif /* _POSIX_SOURCE */

/** Default signal handler used by the EMC_STD_SIG_DFL macro */
void emc_std_internal_sig_dfl(int sig);

// clang-format off extern C
#  if defined(__cplusplus)
}
#  endif
// clang-format on extern C

#define EMC_STD_SIGABRT 0x41425254 /* "ABRT" */
/* # define EMC_STD_SIGSEGV 0x53454756 / * "SEGV" */

#define EMC_STD_SIG_DFL emc_std_internal_sig_dfl
#define EMC_STD_SIG_ERR ((void (*)(int)) 0)

#endif /* EMC_STD_EMU_signal_H */
