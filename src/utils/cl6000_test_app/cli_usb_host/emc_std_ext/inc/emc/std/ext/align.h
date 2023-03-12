/** @file
    @brief Compiler specific alignment
    Copyright (C) 2013, 2020-2021 emsys Embedded Systems GmbH */

#ifndef EMC_STD_EXT_align_H
#define EMC_STD_EXT_align_H

/**
 * @def  EMC_STD_EXT_ALIGNAS(a)
 * alignas similar to C++ alignas()
 * @param a the alignment
 */
#if defined(__arm)
#  define EMC_STD_EXT_ALIGNAS(a) __align((a))
#elif defined(__GNUC__)
#  define EMC_STD_EXT_ALIGNAS(a) __attribute__((aligned((a))))
#elif defined(_MSC_VER)
#  define EMC_STD_EXT_ALIGNAS(a) __declspec(align(a))
#else
#  define EMC_STD_EXT_ALIGNAS(a)
#endif

#endif /* EMC_STD_EXT_align_H */
