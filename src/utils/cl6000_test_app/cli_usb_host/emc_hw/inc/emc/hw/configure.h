/**
 * @file
 * @brief   Configuration of low level hardware access
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de>
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_HW_configure_H
#define EMC_HW_configure_H

#include "emc/config/configure.h"

/** @defgroup emdoc_emc_hw emc_hw - EMC HW Library
 *  @ingroup emsys_modules
 *
 */

#ifdef HAVE_CMAKE_CONFIGURE
#  include "emc_hw/cmakeConfigure.h"
#endif

#include "emc/config/configure.h"

/** Number Port Instances
 * @showinitializer
 * @ingroup emdoc_emc_port_Defines
 */
#ifndef EMC_MEMORY_POOL_TYPE_STATIC_INSTANCES
#  define EMC_MEMORY_POOL_TYPE_STATIC_INSTANCES 2
#endif

/** Number Small Chunks for Allocator
 * @showinitializer
 * @ingroup emdoc_emc_port_Defines
 */
#ifndef EMC_PORT_ALLOCATOR_NB_SMALL_CHUNKS
#  define EMC_PORT_ALLOCATOR_NB_SMALL_CHUNKS 48
#endif

/**  Number Medium Chunks for Allocator
 * @showinitializer
 * @ingroup emdoc_emc_port_Defines
 */
#ifndef EMC_PORT_ALLOCATOR_NB_MEDIUM_CHUNKS
#  define EMC_PORT_ALLOCATOR_NB_MEDIUM_CHUNKS 2
#endif

/**  Number Large Chunks for Allocator
 * @showinitializer
 * @ingroup emdoc_emc_port_Defines
 */
#ifndef EMC_PORT_ALLOCATOR_NB_LARGE_CHUNKS
#  define EMC_PORT_ALLOCATOR_NB_LARGE_CHUNKS 1
#endif

/** Size of Small Chunks for Allocator
 * @showinitializer
 * @ingroup emdoc_emc_port_Defines
 */
#ifndef EMC_PORT_ALLOCATOR_SMALL_CHUNK_SIZE
#  define EMC_PORT_ALLOCATOR_SMALL_CHUNK_SIZE 32
#endif

/**  Size of Medium Chunks for Allocator
 * @showinitializer
 * @ingroup emdoc_emc_port_Defines
 */
#ifndef EMC_PORT_ALLOCATOR_MEDIUM_CHUNK_SIZE
#  define EMC_PORT_ALLOCATOR_MEDIUM_CHUNK_SIZE 512
#endif

/** Size of Large Chunks for Allocator
 * @showinitializer
 * @ingroup emdoc_emc_port_Defines
 */
#ifndef EMC_PORT_ALLOCATOR_LARGE_CHUNK_SIZE
#  define EMC_PORT_ALLOCATOR_LARGE_CHUNK_SIZE 1024
#endif

/** @ingroup emdoc_emc_port_Defines
 * @brief Forces the direct memory mapped register read/write access via
 * *ptr = write_value
 * read_value = *ptr
 */
#ifndef EMC_HW_PORT_INLINE_MMIO
#  define EMC_HW_PORT_INLINE_MMIO 0
#endif

/** @ingroup emdoc_emc_port_Defines
 * @brief Enables a hook function to be called after the port was read
 */
#ifndef EMC_HW_PORT_READ_HOOK
#  define EMC_HW_PORT_READ_HOOK 0
#endif

/** @ingroup emdoc_emc_port_Defines
 * @brief Enables a hook function to be called before the port is written
 */
#ifndef EMC_HW_PORT_WRITE_HOOK
#  define EMC_HW_PORT_WRITE_HOOK 0
#endif

/** @ingroup emdoc_emc_memory_Defines
 * @brief Include an UncachedMemoryPool instance to the emc_hw_memory library
 */
#ifndef EMC_MEMORY_POOL_TYPE_UNCACHED
#  define EMC_MEMORY_POOL_TYPE_UNCACHED 1
#endif

#endif
