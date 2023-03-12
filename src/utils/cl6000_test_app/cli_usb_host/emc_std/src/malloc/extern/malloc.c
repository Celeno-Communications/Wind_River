#include "emc/std/stdlib.h"

#ifdef _MSC_VER
#  ifdef _MSC_WDK_VER
#    if _MSC_WDK_VER >= 10010586
#      define EMC_STD_MALLOC_EXTERN_DECL 1
#    endif
#  else
#    define EMC_STD_MALLOC_EXTERN_DECL 0
#  endif
#else
#  define EMC_STD_MALLOC_EXTERN_DECL 1
#endif

#if EMC_STD_MALLOC_EXTERN_DECL
extern void* malloc(size_t size);
extern void free(void* ptr);
#else /* !EMC_STD_MALLOC_EXTERN_DECL */
/* #error "No malloc/free emulation implemented yet!" */
#endif /* EMC_STD_MALLOC_EXTERN_DECL */

void* emc_std_malloc(size_t size)
{
  return malloc(size);
}

void emc_std_free(void* ptr)
{
  free(ptr);
}
