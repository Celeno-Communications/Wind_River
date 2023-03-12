/** @file
    @brief Declares five types and several functions of general
           utility, and defines several macros.

    @see www.open-std.org/jtc1/sc22/wg14/www/docs/n1256.pdf
         7.20 General utilities

    @see http://www.opengroup.org/onlinepubs/000095399/basedefs/stdlib.h.html

    Copyright (C) 2011, 2012 emsys Embedded Systems GmbH */

#ifndef EMC_STD_stdlib_H
#define EMC_STD_stdlib_H

#include "emc/std/stddef.h" /* size_t, wchar_t */

#if !EMC_STD_STDLIB_EMULATE || !EMC_STD_MALLOC_EMULATE
#  include <stdlib.h>
#endif

/* disable lint warning about symbol redefinition for the following symbols */
/*lint -esym(652, emc_std_abort) */
/*lint -esym(652, emc_std_atoi) */

// clang-format off extern C
#  if defined(__cplusplus)
extern "C" {
#  endif
// clang-format on extern C

#if !EMC_STD_STDLIB_EMULATE

inline static void emc_std_abort(void) EMC_ATTRIBUTE_NORETURN;
inline static void emc_std_abort(void) { (abort)(); }

#  define emc_std_abort() do {                                   \
    emc_abort_info(__FILE__, __LINE__, __func__, "Aborted");    \
    abort();                                         \
} while (0)

inline static void emc_std_exit(int code) EMC_ATTRIBUTE_NORETURN;
inline static void emc_std_exit(int code) { (exit)(code); }

#  ifdef exit
#    define emc_std_exit(code) (exit(code))
#  endif

inline static int emc_std_atexit(void (* func)(void));
inline static int emc_std_atexit(void (* func)(void)) { return (atexit)(func); }

#  ifdef atexit
#    define emc_std_atexit(func) (atexit(func))
#  endif

inline static void emc_std__Exit(int code) EMC_ATTRIBUTE_NORETURN;

#  if defined(_MSC_VER) && _MSC_VER <= 1900
inline static void emc_std__Exit(int code) { (_exit)(code); }

#    ifdef exit
#      define emc_std__Exit(code) (_exit(code))
#    endif
#  else
inline static void emc_std__Exit(int code) { (_Exit)(code); }

#    ifdef exit
#      define emc_std__Exit(code) (_Exit(code))
#    endif
#  endif

#  define EMC_STD_EXIT_FAILURE EXIT_FAILURE
#  define EMC_STD_EXIT_SUCCESS EXIT_SUCCESS

inline static int emc_std_atoi(const char* nptr) { return (atoi)(nptr); }

#  ifdef atoi
#    define emc_std_atoi(nptr) (atoi(nptr))
#  endif

inline static long emc_std_atol(const char* nptr) { return (atol)(nptr); }

#  ifdef atol
#    define emc_std_atol(nptr) (atol(nptr))
#  endif

inline static long emc_std_strtol(const char* str, char** endptr, int base)
{ return (strtol)(str, endptr, base); }

#  ifdef strtol
#    define emc_std_strtol(str, endptr, base) (strtol(str, endptr, base))
#  endif

inline static unsigned long emc_std_strtoul(const char* str, char** endptr, int base)
{ return (strtoul)(str, endptr, base); }

#  ifdef strtoul
#    define emc_std_strtoul(str, endptr, base) (strtoul(str, endptr, base))
#  endif

inline static int emc_std_abs(int n) { return (abs)(n); }

#  ifdef abs
#    define emc_std_abs(n) (abs(n))
#  endif

#else /* EMC_STD_STDLIB_EMULATE */

#  if !defined(_MSC_VER)   // MSVC does not allow definition of intrinsic functions
int emc_std_abs(int n);
#  endif

/** Causes abnormal program termination, unless the signal SIGABRT
    is being caught and the signal handler does not return */
EMC_ATTRIBUTE_NORETURN void emc_std_abort(void);

#  define emc_std_abort() do {                               \
    emc_abort_info(__FILE__, __LINE__, __func__, "Aborted"); \
    (emc_std_abort)();                                       \
} while (0)

EMC_ATTRIBUTE_NORETURN void emc_std_exit(int code);

int emc_std_atexit(void (* func)(void));

EMC_ATTRIBUTE_NORETURN void emc_std__Exit(int code);

/** Unsuccessful termination for exit(), evaluates to a non-zero value */
#  define EMC_STD_EXIT_FAILURE -1
/** Successful termination for exit(), evaluates to 0 */
#  define EMC_STD_EXIT_SUCCESS 0

int emc_std_atoi(const char* nptr);
#  if 0
#    define emc_std_atoi(nptr) ((int)emc_std_strtol((nptr), (char**)0, 10))
#  else
#    define emc_std_atoi(nptr) ((int)emc_std_atol(nptr))
#  endif

long emc_std_atol(const char* nptr);
#  if 0
#    define emc_std_atol(nptr) (emc_std_strtol((nptr), (char**)0, 10))
#  endif

long emc_std_strtol(const char* str, char** endptr, int base);
unsigned long emc_std_strtoul(const char* str, char** endptr, int base);

#endif /* EMC_STD_STDLIB_EMULATE */

#if EMC_STD_MALLOC_EMULATE

/** allocates size bytes in heap and provides pointer on the allocated memory
 * @param size The size in bytes requested (should not be 0)
 * @return the pointer on the allocated memory
 * @retval 0 implies no heap memory available
 */
void* emc_std_malloc(emc_std_size_t size);

/** returns the memory referenced by @p ptr to the heap
 * @param ptr the pointer to a piece of memory allocated earlier from the heap,
 * which should be returned to the memory management
 */
void emc_std_free(void* ptr);

#else /* !EMC_STD_MALLOC_EMULATE */

inline static void* emc_std_malloc(emc_std_size_t size) { return (malloc)(size); }

inline static void emc_std_free(void* ptr) { (free)(ptr); }

#endif /* !EMC_STD_MALLOC_EMULATE */

#if 1 /* && defined NDEBUG */
#  define emc_abort_info(file, line, function, message) do {} while (0)
#else
void emc_abort_info(const char* file, int line, const char* function, const char* message);

extern const char* emc_abort_info_file;
extern int         emc_abort_info_line;
extern const char* emc_abort_info_function;
extern const char* emc_abort_info_message;
#endif

// clang-format off extern C
#  if defined(__cplusplus)
}
#  endif
// clang-format on extern C

#endif /* EMC_STD_stdlib_H */
