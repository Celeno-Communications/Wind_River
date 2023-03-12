/**
 * @file
 * @brief
 *
 * @author  emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2007, 2008 emsys Embedded Systems GmbH
 */

#include "M4OSA_Types.h"

/** Initially this identifier for M4OSA_malloc() contains the string "emc_malloc" */
extern M4OSA_Char emc_nonconst_malloc_string[];

/** The macro redirects to M4OSA_malloc. We use the ID 0x190 and the
    string "emc_malloc" for the additional parameters.
    @par History:
    - Herve asked us to use CoreID "0" and not an unused ID like "-1".
    - Alexandre requested "> 0x190 (0X190 is good)" on 12 Oct 2007 12:49. */
#define emc_std_malloc(size) \
  ((void*)M4OSA_malloc(size, (M4OSA_CoreID)0x190, emc_nonconst_malloc_string))
/** The macro redirects to M4OSA_free */
#define emc_std_free(ptr) M4OSA_free((M4OSA_MemAddr32)ptr)
/** The macro redirects to M4OSA_malloc. */

M4OSA_Char emc_nonconst_malloc_string[] = "emc_malloc";

#ifndef EMC_MALLOC_TRACE
#  define EMC_MALLOC_TRACE 0
#endif

#if EMC_MALLOC_TRACE

#  include "M4OSA_Memory.h"

static void* recent[256];
static int   recent_pos;
static int   recursive_call = 0;

M4OSA_MemAddr32
$ Super$$M4OSA_malloc (M4OSA_UInt32 size, M4OSA_CoreID coreID, M4OSA_Char * string);

M4OSA_MemAddr32
$ Sub$$M4OSA_malloc (M4OSA_UInt32 size, M4OSA_CoreID coreID, M4OSA_Char * string)
  {
    M4OSA_MemAddr32 result = $Super$$M4OSA_malloc (size, coreID, string);
    // EMC_BASE_LOG4(DEBUG, logger, "M4OSA_malloc(%d, %d, '%s') = @%x", size, coreID, string, result);
    if (0x190 == coreID) {
      recent_pos = (recent_pos + 1) % (sizeof(recent) / sizeof(recent[0]));
      if (!recursive_call) {
        recursive_call = 1;
        //EMC_BASE_LOG3(DEBUG, logger, "M4OSA_malloc(%d, '%s') = @%x", size, string, result);
        if (NULL != recent[recent_pos]) {
          //EMC_BASE_LOG1(INFO, logger, "malloc forgetting @%x", recent[recent_pos]);
        }
        recursive_call = 0;
      }
      recent[recent_pos] = result;
    }
    return result;
  }

  M4OSA_Void
  $ Super$$M4OSA_free (M4OSA_MemAddr32 address);

M4OSA_Void
$ Sub$$M4OSA_free (M4OSA_MemAddr32 address)
  {
    int i;
    if (NULL != address) {
      for (i = 0; i < sizeof(recent) / sizeof(recent[0]); ++i) {
        if (recent[i] == address) {
          if (!recursive_call) {
            recursive_call = 1;
            //EMC_BASE_LOG1(DEBUG, logger, "free @%x", address);
            recursive_call = 0;
          }
          recent[i] = NULL;
          break;
        }
      }
    }
    $ Super$$M4OSA_free (address);
  }

#endif /* EMC_MALLOC_TRACE */
