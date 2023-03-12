/** @file
    @brief Several macros relating to reporting error conditions.

    @see www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf
         7.5 Errors

    Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_errno_H
#define EMC_STD_errno_H

#include "emc/std/configure.h"

#if !EMC_STD_STDLIB_EMULATE

#  include <errno.h>

#  define EMC_STD_EDOM EDOM
#  define EMC_STD_ERANGE ERANGE
#  ifdef EILSEQ   /* in c99 but not in c++98 */
#    define EMC_STD_EILSEQ EILSEQ
#  endif

#  define emc_std_errno errno

#else /* EMC_STD_STDLIB_EMULATE */

#  define EMC_STD_EDOM 0x45444f4d     /* "EDOM" */
#  define EMC_STD_ERANGE 0x4552414e   /* "ERAN" */

// clang-format off extern C
#    if defined(__cplusplus)
extern "C" {
#    endif
// clang-format on extern C

int* emc_std_internal_errno(void);
void emc_std_internal_set_errno_func(int* (*func)(void));

// clang-format off extern C
#    if defined(__cplusplus)
}
#    endif
// clang-format on extern C

/** This macro provides seperate error values for each thread.  It
    expands to a modifiable lvalue that has type int.  Several library
    functions will set positive error numbers.  It is never set to
    zero by any library function. */
#  define emc_std_errno (*emc_std_internal_errno())

#endif /* EMC_STD_STDLIB_EMULATE */

#ifndef EMC_STD_EILSEQ
#  define EMC_STD_EILSEQ 0x45494c53   /* "EILS" */
#endif

#if !EMC_STD_STDLIB_EMULATE && defined ENOTSUP
#  define EMC_STD_ENOTSUP ENOTSUP
#else
#  define EMC_STD_ENOTSUP 0x454e5355   /* "ENSU" */
#endif

/* Most codes are only required in c++11.  We don't want to declare
   them in emc projects until they're actually used. */

#if defined(__cplusplus)

#  if !EMC_STD_STDLIB_EMULATE && defined E2BIG
#    define EMC_STD_E2BIG E2BIG
#  else
#    define EMC_STD_E2BIG 0x45324249   /* "E2BI" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EACCES
#    define EMC_STD_EACCES EACCES
#  else
#    define EMC_STD_EACCES 0x45414343   /* "EACC" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EAFNOSUPPORT
#    define EMC_STD_EAFNOSUPPORT EAFNOSUPPORT
#  else
#    define EMC_STD_EAFNOSUPPORT 0x4541464e   /* "EAFN" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EAGAIN
#    define EMC_STD_EAGAIN EAGAIN
#  else
#    define EMC_STD_EAGAIN 0x45414741   /* "EAGA" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EADDRINUSE
#    define EMC_STD_EADDRINUSE EADDRINUSE
#  else
#    define EMC_STD_EADDRINUSE 0x45414955   /* "EAIU" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EALREADY
#    define EMC_STD_EALREADY EALREADY
#  else
#    define EMC_STD_EALREADY 0x45414c52   /* "EALR" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EADDRNOTAVAIL
#    define EMC_STD_EADDRNOTAVAIL EADDRNOTAVAIL
#  else
#    define EMC_STD_EADDRNOTAVAIL 0x45414e41   /* "EANA" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EBADF
#    define EMC_STD_EBADF EBADF
#  else
#    define EMC_STD_EBADF 0x45424446   /* "EBDF" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EBADMSG
#    define EMC_STD_EBADMSG EBADMSG
#  else
#    define EMC_STD_EBADMSG 0x4542444d   /* "EBDM" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EBUSY
#    define EMC_STD_EBUSY EBUSY
#  else
#    define EMC_STD_EBUSY 0x45425553   /* "EBUS" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ECONNABORTED
#    define EMC_STD_ECONNABORTED ECONNABORTED
#  else
#    define EMC_STD_ECONNABORTED 0x45434142   /* "ECAB" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ECANCELED
#    define EMC_STD_ECANCELED ECANCELED
#  else
#    define EMC_STD_ECANCELED 0x4543414e   /* "ECAN" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ECHILD
#    define EMC_STD_ECHILD ECHILD
#  else
#    define EMC_STD_ECHILD 0x45434849   /* "ECHI" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ECONNREFUSED
#    define EMC_STD_ECONNREFUSED ECONNREFUSED
#  else
#    define EMC_STD_ECONNREFUSED 0x45435246   /* "ECRF" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ECONNRESET
#    define EMC_STD_ECONNRESET ECONNRESET
#  else
#    define EMC_STD_ECONNRESET 0x45435253   /* "ECRS" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EDEADLK
#    define EMC_STD_EDEADLK EDEADLK
#  else
#    define EMC_STD_EDEADLK 0x45444541   /* "EDEA" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EDESTADDRREQ
#    define EMC_STD_EDESTADDRREQ EDESTADDRREQ
#  else
#    define EMC_STD_EDESTADDRREQ 0x45444553   /* "EDES" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EEXIST
#    define EMC_STD_EEXIST EEXIST
#  else
#    define EMC_STD_EEXIST 0x45455849   /* "EEXI" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EFAULT
#    define EMC_STD_EFAULT EFAULT
#  else
#    define EMC_STD_EFAULT 0x45464155   /* "EFAU" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EFBIG
#    define EMC_STD_EFBIG EFBIG
#  else
#    define EMC_STD_EFBIG 0x45464249   /* "EFBI" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EHOSTUNREACH
#    define EMC_STD_EHOSTUNREACH EHOSTUNREACH
#  else
#    define EMC_STD_EHOSTUNREACH 0x45484f53   /* "EHOS" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EIDRM
#    define EMC_STD_EIDRM EIDRM
#  else
#    define EMC_STD_EIDRM 0x45494452   /* "EIDR" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EILSEQ
#    define EMC_STD_EILSEQ EILSEQ
#  else
#    define EMC_STD_EILSEQ 0x45494c53   /* "EILS" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EINPROGRESS
#    define EMC_STD_EINPROGRESS EINPROGRESS
#  else
#    define EMC_STD_EINPROGRESS 0x45494e50   /* "EINP" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EINTR
#    define EMC_STD_EINTR EINTR
#  else
#    define EMC_STD_EINTR 0x45494e54   /* "EINT" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EINVAL
#    define EMC_STD_EINVAL EINVAL
#  else
#    define EMC_STD_EINVAL 0x45494e56   /* "EINV" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EIO
#    define EMC_STD_EIO EIO
#  else
#    define EMC_STD_EIO 0x45494f20   /* "EIO " */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EISCONN
#    define EMC_STD_EISCONN EISCONN
#  else
#    define EMC_STD_EISCONN 0x45495343   /* "EISC" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EISDIR
#    define EMC_STD_EISDIR EISDIR
#  else
#    define EMC_STD_EISDIR 0x45495344   /* "EISD" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ELOOP
#    define EMC_STD_ELOOP ELOOP
#  else
#    define EMC_STD_ELOOP 0x454c4f4f   /* "ELOO" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EMFILE
#    define EMC_STD_EMFILE EMFILE
#  else
#    define EMC_STD_EMFILE 0x454d4649   /* "EMFI" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EMLINK
#    define EMC_STD_EMLINK EMLINK
#  else
#    define EMC_STD_EMLINK 0x454d4c49   /* "EMLI" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EMSGSIZE
#    define EMC_STD_EMSGSIZE EMSGSIZE
#  else
#    define EMC_STD_EMSGSIZE 0x454d5347   /* "EMSG" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENAMETOOLONG
#    define EMC_STD_ENAMETOOLONG ENAMETOOLONG
#  else
#    define EMC_STD_ENAMETOOLONG 0x454e414d   /* "ENAM" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENODATA
#    define EMC_STD_ENODATA ENODATA
#  else
#    define EMC_STD_ENODATA 0x454e4441   /* "ENDA" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENODEV
#    define EMC_STD_ENODEV ENODEV
#  else
#    define EMC_STD_ENODEV 0x454e4445   /* "ENDE" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENETDOWN
#    define EMC_STD_ENETDOWN ENETDOWN
#  else
#    define EMC_STD_ENETDOWN 0x454e4544   /* "ENED" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENOENT
#    define EMC_STD_ENOENT ENOENT
#  else
#    define EMC_STD_ENOENT 0x454e454e   /* "ENEN" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENETRESET
#    define EMC_STD_ENETRESET ENETRESET
#  else
#    define EMC_STD_ENETRESET 0x454e4552   /* "ENER" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENETUNREACH
#    define EMC_STD_ENETUNREACH ENETUNREACH
#  else
#    define EMC_STD_ENETUNREACH 0x454e4555   /* "ENEU" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENOEXEC
#    define EMC_STD_ENOEXEC ENOEXEC
#  else
#    define EMC_STD_ENOEXEC 0x454e4558   /* "ENEX" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENFILE
#    define EMC_STD_ENFILE ENFILE
#  else
#    define EMC_STD_ENFILE 0x454e4649   /* "ENFI" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENOLCK
#    define EMC_STD_ENOLCK ENOLCK
#  else
#    define EMC_STD_ENOLCK 0x454e4c43   /* "ENLC" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENOLINK
#    define EMC_STD_ENOLINK ENOLINK
#  else
#    define EMC_STD_ENOLINK 0x454e4c49   /* "ENLI" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENOMEM
#    define EMC_STD_ENOMEM ENOMEM
#  else
#    define EMC_STD_ENOMEM 0x454e4d45   /* "ENME" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENOMSG
#    define EMC_STD_ENOMSG ENOMSG
#  else
#    define EMC_STD_ENOMSG 0x454e4d53   /* "ENMS" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENOBUFS
#    define EMC_STD_ENOBUFS ENOBUFS
#  else
#    define EMC_STD_ENOBUFS 0x454e4f42   /* "ENOB" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENOPROTOOPT
#    define EMC_STD_ENOPROTOOPT ENOPROTOOPT
#  else
#    define EMC_STD_ENOPROTOOPT 0x454e5052   /* "ENPR" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENOTSOCK
#    define EMC_STD_ENOTSOCK ENOTSOCK
#  else
#    define EMC_STD_ENOTSOCK 0x454e534f   /* "ENSO" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENOSPC
#    define EMC_STD_ENOSPC ENOSPC
#  else
#    define EMC_STD_ENOSPC 0x454e5350   /* "ENSP" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENOSR
#    define EMC_STD_ENOSR ENOSR
#  else
#    define EMC_STD_ENOSR 0x454e5352   /* "ENSR" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENOSTR
#    define EMC_STD_ENOSTR ENOSTR
#  else
#    define EMC_STD_ENOSTR 0x454e5354   /* "ENST" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENOSYS
#    define EMC_STD_ENOSYS ENOSYS
#  else
#    define EMC_STD_ENOSYS 0x454e5359   /* "ENSY" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENOTCONN
#    define EMC_STD_ENOTCONN ENOTCONN
#  else
#    define EMC_STD_ENOTCONN 0x454e5443   /* "ENTC" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENOTDIR
#    define EMC_STD_ENOTDIR ENOTDIR
#  else
#    define EMC_STD_ENOTDIR 0x454e5444   /* "ENTD" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENOTEMPTY
#    define EMC_STD_ENOTEMPTY ENOTEMPTY
#  else
#    define EMC_STD_ENOTEMPTY 0x454e5445   /* "ENTE" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENOTRECOVERABLE
#    define EMC_STD_ENOTRECOVERABLE ENOTRECOVERABLE
#  else
#    define EMC_STD_ENOTRECOVERABLE 0x454e5452   /* "ENTR" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENOTTY
#    define EMC_STD_ENOTTY ENOTTY
#  else
#    define EMC_STD_ENOTTY 0x454e5454   /* "ENTT" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ENXIO
#    define EMC_STD_ENXIO ENXIO
#  else
#    define EMC_STD_ENXIO 0x454e5849   /* "ENXI" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EOPNOTSUPP
#    define EMC_STD_EOPNOTSUPP EOPNOTSUPP
#  else
#    define EMC_STD_EOPNOTSUPP 0x454f4e53   /* "EONS" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EOVERFLOW
#    define EMC_STD_EOVERFLOW EOVERFLOW
#  else
#    define EMC_STD_EOVERFLOW 0x454f5645   /* "EOVE" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EOWNERDEAD
#    define EMC_STD_EOWNERDEAD EOWNERDEAD
#  else
#    define EMC_STD_EOWNERDEAD 0x454f574e   /* "EOWN" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EPERM
#    define EMC_STD_EPERM EPERM
#  else
#    define EMC_STD_EPERM 0x45504552   /* "EPER" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EPIPE
#    define EMC_STD_EPIPE EPIPE
#  else
#    define EMC_STD_EPIPE 0x45504950   /* "EPIP" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EPROTONOSUPPORT
#    define EMC_STD_EPROTONOSUPPORT EPROTONOSUPPORT
#  else
#    define EMC_STD_EPROTONOSUPPORT 0x4550524e   /* "EPRN" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EPROTO
#    define EMC_STD_EPROTO EPROTO
#  else
#    define EMC_STD_EPROTO 0x4550524f   /* "EPRO" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EPROTOTYPE
#    define EMC_STD_EPROTOTYPE EPROTOTYPE
#  else
#    define EMC_STD_EPROTOTYPE 0x45505254   /* "EPRT" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EROFS
#    define EMC_STD_EROFS EROFS
#  else
#    define EMC_STD_EROFS 0x45524f46   /* "EROF" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ESPIPE
#    define EMC_STD_ESPIPE ESPIPE
#  else
#    define EMC_STD_ESPIPE 0x45535049   /* "ESPI" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ESRCH
#    define EMC_STD_ESRCH ESRCH
#  else
#    define EMC_STD_ESRCH 0x45535243   /* "ESRC" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ETIMEDOUT
#    define EMC_STD_ETIMEDOUT ETIMEDOUT
#  else
#    define EMC_STD_ETIMEDOUT 0x45544944   /* "ETID" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ETIME
#    define EMC_STD_ETIME ETIME
#  else
#    define EMC_STD_ETIME 0x4554494d   /* "ETIM" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined ETXTBSY
#    define EMC_STD_ETXTBSY ETXTBSY
#  else
#    define EMC_STD_ETXTBSY 0x45545854   /* "ETXT" */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EWOULDBLOCK
#    define EMC_STD_EWOULDBLOCK EWOULDBLOCK
#  else
#    define EMC_STD_EWOULDBLOCK 0x45574f55   /* "EWOU" */ /* Value may be equal to EAGAIN. */
#  endif

#  if !EMC_STD_STDLIB_EMULATE && defined EXDEV
#    define EMC_STD_EXDEV EXDEV
#  else
#    define EMC_STD_EXDEV 0x45584445   /* "EXDE" */
#  endif

#endif /* defined(__cplusplus) */

#endif /* EMC_STD_errno_H */
