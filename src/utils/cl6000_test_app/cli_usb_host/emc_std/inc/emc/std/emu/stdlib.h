/** @file
    @brief Declares types, functions and macros of general utility.

    ANSI-C/ISO9899:
    http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1124.pdf
    7.20 General utilities <stdlib.h>

    POSIX/SUSv3:
    http://www.opengroup.org/onlinepubs/000095399/basedefs/stdlib.h.html

    Copyright (C) 2010-2013 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EMU_stdlib_H
#define EMC_STD_EMU_stdlib_H

#error "first use" /* @cond */
/* This header was added for future reference. Currently we don't intend to use it.
   Remove the error and move the following defines to emc/std/configure.h :

 #ifndef EMC_STD_EMULATE_POSIX_ADV
 #define EMC_STD_EMULATE_POSIX_ADV 0
 #endif
 #ifndef EMC_STD_EMULATE_POSIX_CX
 #define EMC_STD_EMULATE_POSIX_CX 0
 #endif
 #ifndef EMC_STD_EMULATE_POSIX_TSF
 #define EMC_STD_EMULATE_POSIX_TSF 0
 #endif
 #ifndef EMC_STD_EMULATE_POSIX_XSI
 #define EMC_STD_EMULATE_POSIX_XSI 0
 #endif

 */

/* Includes */

/* Inclusion of the stdlib header may also make visible all symbols
   from stddef, limits, math and sys/wait */
#include "emc/std/emu/stddef.h" /* size_t, wchar_t */
#if EMC_STD_EMULATE_POSIX_XSI
/* WNOHANG WUNTRACED WEXITSTATUS WIFEXITED WIFSIGNALED WIFSTOPPED WSTOPSIG WTERMSIG */
#  include "emc/std/emu/sys/wait.h"
#endif /* EMC_STD_EMULATE_POSIX_XSI */

/* Macros */

/** Unsuccessful termination for exit(), evaluates to a non-zero value */
#define EXIT_FAILURE -1
/** Successful termination for exit(), evaluates to 0 */
#define EXIT_SUCCESS 0
/** Null pointer */
#define NULL 0
/** Maximum value returned by rand(), at least 32767 */
#define RAND_MAX ((size_t)32767)
/** Maximum size of a character in the current locale, never greater than MB_LEN_MAX */
#define MB_CUR_MAX 1

/* Typedefs */

/** Structure type returned by div() function */
typedef struct { int quot; int rem; } div_t;
/** Structure type returned by ldiv() function */
typedef struct { long quot; long rem; } ldiv_t;
/** Structure type returned by lldiv() function */
typedef struct { long long quot; long long rem; } lldiv_t;

/* Functions */

/* 7.20.1 Numeric conversion functions */
/* 7.20.1.1 The atof function */
double atof(const char* nptr);
/* 7.20.1.2 The atoi, atol, and atoll functions */
int atoi(const char* nptr);
long atol(const char* nptr);
long long atoll(const char*);
/* 7.20.1.3 The strtod, strtof, and strtold functions */
double strtod(const char* restrict_nptr, char** restrict_endptr);
float strtof(const char* restrict_nptr, char** restrict_endptr);
long double strtold(const char* restrict_nptr, char** restrict_endptr);

/* 7.20.1.4 The strtol, strtoll, strtoul, and strtoull functions */
double strtod(const char* restrict_nptr, char** restrict_endptr);
long long strtoll(const char* restrict_nptr, char** restrict_endptr, int);
unsigned long strtoul(const char* restrict_nptr, char** restrict_endptr, int);
unsigned long long strtoull(const char* restrict_nptr, char** restrict_endptr, int);

/* 7.20.2 Pseudo-random sequence generation functions */
/* 7.20.2.1 The rand function */
int rand(void);
/* 7.20.2.2 The srand function */
void srand(unsigned seed);

/* 7.20.3 Memory management functions */
/* 7.20.3.1 The calloc function */
void* calloc(size_t nmemb, size_t size);
/* 7.20.3.2 The free function */
void free(void* ptr);
/* 7.20.3.3 The malloc function */
void* malloc(size_t size);
/* 7.20.3.4 The realloc function */
void* realloc(void* ptr, size_t size);

/* 7.20.4 Communication with the environment */
/* 7.20.4.1 The abort function */
void abort(void);
/* 7.20.4.2 The atexit function */
int atexit(void (* func)(void));
/* 7.20.4.3 The exit function */
void exit(int status);
/* 7.20.4.4 The _Exit function */
void _Exit(int status);
/* 7.20.4.5 The getenv function */
char* getenv(const char* name);
/* 7.20.4.6 The system function */
int system(const char* string);

/* 7.20.5 Searching and sorting utilities */
/* 7.20.5.1 The bsearch function */
void* bsearch(const void* key,
              const void* base,
              size_t nmemb,
              size_t size,
              int (* compar)(const void*, const void*));
/* 7.20.5.2 The qsort function */
void qsort(void* base, size_t nmemb, size_t size, int (* compar)(const void*, const void*));

/* 7.20.6 Integer arithmetic functions */
/* 7.20.6.1 The abs, labs and llabs functions */
int abs(int j);
long labs(long j);
long long llabs(long long j);
/* 7.20.6.2 The div, ldiv, and lldiv functions */
div_t div(int numer, int denom);
ldiv_t ldiv(long numer, long denom);
lldiv_t lldiv(long long numer, long long denom);

/* 7.20.7 Multibyte/wide character conversion functions */
/* 7.20.7.1 The mblen function */
int mblen(const char* s, size_t n);
/* 7.20.7.2 The mbtowc function */
int mbtowc(wchar_t* restrict_pcw, const char* restrict_s, size_t);
/* 7.20.7.3 The wctomb function */
int wctomb(char* s, wchar_t wchar);
/* 7.20.8 Multibyte/wide string conversion functions */
/* 7.20.8.1 The mbstowcs function */
size_t mbstowcs(wchar_t* restrict_pwc, const char* restrict_s, size_t n);
/* 7.20.8.2 The wcstombs function */
size_t wcstombs(char* restrict_s, const wchar_t* restrict_pwc, size_t n);

/* Extensions */

#if EMC_STD_EMULATE_POSIX_ADV
int posix_memalign(void**, size_t, size_t);
#endif /* EMC_STD_EMULATE_POSIX_ADV */

#if EMC_STD_EMULATE_POSIX_CX
int setenv(const char*, const char*, int);
int unsetenv(const char*)
#endif /* EMC_STD_EMULATE_POSIX_CX */

#if EMC_STD_EMULATE_POSIX_TSF
int rand_r(unsigned*);
#endif /* EMC_STD_EMULATE_POSIX_TSF */

#if EMC_STD_EMULATE_POSIX_XSI
long a64l(const char*);
double drand48(void);
char* ecvt(double, int, int* restrict, int* restrict); /* LEGACY */
double erand48(unsigned short[3]);
char* fcvt(double, int, int* restrict, int* restrict); /* LEGACY */
char* gcvt(double, int, char*);                        /* LEGACY */
int getsubopt(char**, char* const*, char**);
int grantpt(int);
char* initstate(unsigned, char*, size_t);
long jrand48(unsigned short[3]);
char* l64a(long);
void lcong48(unsigned short[7]);
long lrand48(void);
char* mktemp(char*); /* LEGACY */
int mkstemp(char*);
long mrand48(void);
long nrand48(unsigned short[3]);
int posix_openpt(int);
char* ptsname(int);
int putenv(char*);
long random(void);
char* realpath(const char* restrict, char* restrict);
unsigned short seed48(unsigned short[3]);
void setkey(const char*);
char* setstate(const char*);
void srand48(long);
void srandom(unsigned);
int unlockpt(int);
#endif /* EMC_STD_EMULATE_POSIX_XSI */

/* @endcond */
#endif /* EMC_STD_EMU_stdlib_H */
