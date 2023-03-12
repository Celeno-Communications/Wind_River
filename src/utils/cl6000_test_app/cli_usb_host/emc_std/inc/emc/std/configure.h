/* Copyright (C) 2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_configure_H
#define EMC_STD_configure_H

#ifdef HAVE_CMAKE_CONFIGURE
#  include "emc_std/cmakeConfigure.h"
#endif
#include "emc/config/configure.h"

/** @defgroup emc_base_std_interface Standard C
    @ingroup emdoc_emc_base
    Extend, emulate or include standard c headers.

    @cond EMDOC_EMC_STD_ENABLED
    @dir emc/std
    @ingroup emc_base_std_interface
    Files from @c emc/std redirect to standard or emulation headers.
    @dir emc/std/emu
    @ingroup emc_base_std_interface
    Files from @c emc/std/emu emulate standard headers.
    @dir emc/std/ext
    @ingroup emc_base_std_interface
    Files from @c emc/std/ext contain emsys extensions to the standard headers.
    @endcond */

#if !defined(EMC_LIB_USE_STDBOOL) || EMC_DOXYGEN
/** Set it to one at compile-time to enable @c @<stdbool.h@> defines.@hideinitializer
    @ingroup emdoc_emc_base_Defines */
#  define EMC_LIB_USE_STDBOOL 0
#endif

#if !defined(EMC_LIB_USE_MALLOC) || EMC_DOXYGEN
/** Set it to zero at compile-time to stop using the standard @c %malloc().@hideinitializer
    @ingroup emdoc_emc_base_Defines */
#  define EMC_LIB_USE_MALLOC 1
#endif

#if !defined(EMC_STD_STDLIB_EMULATE) || EMC_DOXYGEN
/** Set it to zero at compile-time stop using the standard library.@hideinitializer
    @ingroup emdoc_emc_base_Defines */
#  define EMC_STD_STDLIB_EMULATE 0
#endif

#if !defined(EMC_STD_MALLOC_EMULATE) || EMC_DOXYGEN
/** Set it to zero at compile-time stop using the standard library.@hideinitializer
    @ingroup emdoc_emc_base_Defines */
#  define EMC_STD_MALLOC_EMULATE 0
#endif

#ifndef EMC_STD_ASSERT_NONE
#  define EMC_STD_ASSERT_NONE 1
#endif

#ifndef EMC_STD_ASSERT_STD
#  define EMC_STD_ASSERT_STD 0
#endif

#ifndef EMC_STD_ASSERT_EMULATE
#  define EMC_STD_ASSERT_EMULATE 0
#endif

#ifndef EMC_STD_ASSERT_SRC_POS_FILE_LINE
#  define EMC_STD_ASSERT_SRC_POS_FILE_LINE 0
#endif
#ifndef EMC_STD_ASSERT_SRC_POS_HASH
#  define EMC_STD_ASSERT_SRC_POS_HASH 0
#endif
#ifndef EMC_STD_ASSERT_SRC_POS_PROGRAM_COUNT
#  define EMC_STD_ASSERT_SRC_POS_PROGRAM_COUNT 0
#endif

/** Use assert context */
#ifndef EMC_STD_ASSERT_CONTEXT
#  define EMC_STD_ASSERT_CONTEXT 0
#endif

/** Use assert reason message */
#ifndef EMC_STD_ASSERT_MESSAGE
#  define EMC_STD_ASSERT_MESSAGE 0
#endif

/** Use assert function name */
#ifndef EMC_STD_ASSERT_FUNCTION
#  define EMC_STD_ASSERT_FUNCTION 0
#endif

/** use 64 bit time stamp when available */
#ifndef EMC_STD_TIMESTAMP_USE_64BIT
#  define EMC_STD_TIMESTAMP_USE_64BIT 0
#endif

/** use emulated timestamp implementation */
#ifndef EMC_STD_TIMESTAMP_NULL
#  define EMC_STD_TIMESTAMP_NULL 0
#endif

/** use C11 std timestamp implementation */
#ifndef EMC_STD_TIMESTAMP_STD
#  define EMC_STD_TIMESTAMP_STD 0
#endif

/** use UTA timestamp implementation */
#ifndef EMC_STD_TIMESTAMP_UTA
#  define EMC_STD_TIMESTAMP_UTA 0
#endif

/** use pthreads timestamp implementation */
#ifndef EMC_STD_TIMESTAMP_PTHREADS
#  define EMC_STD_TIMESTAMP_PTHREADS 0
#endif

/** use Windows timestamp implementation */
#ifndef EMC_STD_TIMESTAMP_WINDOWS
#  define EMC_STD_TIMESTAMP_WINDOWS 0
#endif

/** use embos timestamp implementation */
#ifndef EMC_STD_TIMESTAMP_EMBOS
#  define EMC_STD_TIMESTAMP_EMBOS 0
#endif

/** use freertos timestamp implementation */
#ifndef EMC_STD_TIMESTAMP_FREERTOS
#  define EMC_STD_TIMESTAMP_FREERTOS 0
#endif

/** use XTOS timestamp implementation */
#ifndef EMC_STD_TIMESTAMP_XTOS
#  define EMC_STD_TIMESTAMP_XTOS 0
#endif

/** use WDK timestamp implementation */
#ifndef EMC_STD_TIMESTAMP_WDK
#  define EMC_STD_TIMESTAMP_WDK 0
#endif

/** use arch/xilinx timestamp implementation */
#ifndef EMC_STD_TIMESTAMP_XILINX
#  define EMC_STD_TIMESTAMP_XILINX 0
#endif

/** use emsys GigE core timestamp implementation */
#ifndef EMC_STD_TIMESTAMP_NET_EMSYS
#  define EMC_STD_TIMESTAMP_NET_EMSYS 0
#endif

/** use external provided timestamp implementation */
#ifndef EMC_STD_TIMESTAMP_EXTERN
#  define EMC_STD_TIMESTAMP_EXTERN 0
#endif

/** The number of entries that can be managed by #ADD_HEAP_LIST_ENTRY and #REMOVE_HEAP_LIST_ENTRY
    @ingroup emdoc_emc_base_Defines */
#if !defined(EMC_STD_MALLOC_HEAP_TRACE_SIZE) || EMC_DOXYGEN
#  define EMC_STD_MALLOC_HEAP_TRACE_SIZE 0
#endif
#ifndef EMC_HEAP_TRACE_USAGE_SIZE
#  define EMC_HEAP_TRACE_USAGE_SIZE 20
#endif

#endif /* EMC_STD_configure_H */
