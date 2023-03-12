/** @file
    @brief the std setjmp emulation
    Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EMU_setjmp_H
#define EMC_STD_EMU_setjmp_H

// clang-format off extern C
# ifdef __cplusplus
extern "C" {
# endif
// clang-format on extern C

/** The emulated type for a setjmp/longjmp buffer */
typedef int jmp_buf[96];
/* typedef int jmp_buf[32]; // ADS12: size suitable for the ARM */
/* typedef int jmp_buf[52]; // GCC Cygwin */
/* typedef long long jmp_buf[48]; // rvct21 - rvct30 (?) */
/* typedef int jmp_buf[16]; // msvc8 */
/* typedef char jmp_buf[8]; // ewarm 6.x (?) */

#define setjmp _setjmp                      /**< Redirection macro for setjmp() */
int  setjmp(jmp_buf /*env*/);               /**< Save location for a future longjmp() */
void longjmp(jmp_buf /*env*/, int /*val*/); /**< Return to a saved location */

// clang-format off extern C
# ifdef __cplusplus
} // extern "C"
# endif
// clang-format on extern C

#endif /* EMC_STD_EMU_setjmp_H */
