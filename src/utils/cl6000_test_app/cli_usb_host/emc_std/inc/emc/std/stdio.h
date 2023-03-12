/** @file
    @brief The indirection of stdio.h for all io operations.
    Copyright (C) 2004-2013 emsys Embedded Systems GmbH */
#ifndef EMC_STD_stdio_H
#define EMC_STD_stdio_H

#include "emc/std/configure.h"

#if EMC_STD_STDIO_NONE
#elif EMC_STD_STDIO_EMULATE
#  include "emc/std/emu/stdio.h"
#else //!EMC_STD_STDIO_EMULATE

/* fix some problems of the ARM std headers */
/*lint -esym(761,size_t,wchar_t) */
/*lint -esym(652,setjmp,system) */
/*lint -esym(534,close,creat,fclose,fprintf,fputc) */
/*lint -esym(534,fputs,fscanf,fseek,fwrite,lseek,memcpy,memmove,memset) */
/*lint -esym(534,printf,puts,scanf,sprintf,sscanf,strcat,strcpy) */
/*lint -esym(534,strncat,strncpy,unlink,write) */
/*lint !e537 Repeated include file 'FileName' */
/*lint !e534 Ignoring return value of function 'Symbol' */

#  include <stdio.h>

#  if _MSC_WDK_VER >= 10010586
#    include <ntstatus.h>
#    include <ntstrsafe.h>
#    undef snprintf
#    define snprintf RtlStringCbPrintfA
/* the above finally includes ntdef.h which provides defines for IN and OUT,
   but this conflicts with EndpointDirection::Direction::IN/OUT */
#    undef OUT
#    undef IN
#  endif

typedef FILE EMC_STD_FILE;
#  define EMC_STD_IONBF _IONBF
#  define EMC_STD_IOLBF _IOLBF
#  define EMC_STD_IOFBF _IOFBF
#  define EMC_STD_SEEK_SET SEEK_SET
#  define EMC_STD_SEEK_CUR SEEK_CUR
#  define EMC_STD_SEEK_END SEEK_END

#  define emc_std_puts puts
#  define emc_std_fputs fputs
#  define emc_std_stderr (stderr)
#  define EMC_STD_EOF (EOF)

#  define emc_std_fopen fopen
#  define emc_std_fread fread
#  define emc_std_fwrite fwrite
#  define emc_std_fseek fseek
#  define emc_std_fclose fclose
#  define emc_std_ferror ferror
#  define emc_std_feof feof
#  if defined(_POSIX_SOURCE)
#    define emc_std_fileno fileno
#  endif
#  define emc_std_setvbuf setvbuf
#  define emc_std_fprintf fprintf
#  define emc_std_vfprintf vfprintf
#  define emc_std_snprintf snprintf
#  define emc_std_vsnprintf vsnprintf

#endif /* !EMC_STD_STDIO_EMULATE */

#endif /* EMC_STD_stdio_H */
