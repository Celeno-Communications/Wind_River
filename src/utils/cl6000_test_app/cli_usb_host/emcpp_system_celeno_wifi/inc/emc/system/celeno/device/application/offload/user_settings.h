// clang-format off

/* user_settings_min_ecc.h
 *
 * Copyright (C) 2006-2021 wolfSSL Inc.
 *
 * This file is part of wolfSSL.
 *
 * wolfSSL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfSSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335, USA
 */

/* should be renamed to user_settings.h for customer use
 * generated from configure options:
 * ./configure \
    --enable-cryptonly --enable-ecc --enable-sp \
    --disable-rsa --disable-dh --disable-sha3 --disable-sha224 --disable-md5 \
    --disable-sha --disable-pkcs12 --disable-memory \
    --disable-chacha --disable-poly1305 --disable-sha512 --disable-sha384 \
    --disable-aesgcm --disable-aescbc --disable-aes --disable-rng \
    CFLAGS="-DNO_SIG_WRAPPER -DWOLFSSL_PUBLIC_MP -DECC_USER_CURVES \
        -DNO_ECC_SIGN -DNO_ECC_DHE -DNO_ECC_KEY_EXPORT"
 *
 * Cleaned up by David Garske
 */


#ifndef EMC_SYSTEM_CELENO_DEVICE_APPLICATION_OFFLOAD_user_settings_H
#define EMC_SYSTEM_CELENO_DEVICE_APPLICATION_OFFLOAD_user_settings_H


#ifdef __cplusplus
extern "C" {
#endif

/* WolfCrypt Only (no TLS) */
//#define WOLFCRYPT_ONLY

/* Endianness - defaults to little endian */
#ifdef __BIG_ENDIAN__
    #define BIG_ENDIAN_ORDER
#endif

/* Expose the math mp_ API's */
#define WOLFSSL_PUBLIC_MP

/* Use single precision math only */
#define WOLFSSL_SP
#define WOLFSSL_SP_SMALL
#ifdef __XTENSA__
#define WOLFSSL_SP_MATH
#endif
#define WOLFSSL_HAVE_SP_ECC

/* Enable Timing Resistance */
#define TFM_TIMING_RESISTANT
#define ECC_TIMING_RESISTANT

/* Enable ECC */
#define HAVE_ECC
#define ECC_USER_CURVES /* Only 256-Bit Curves */
#undef NO_ECC256
//#define ECC_SHAMIR

/* Optional Feature Disables */
#define NO_SIG_WRAPPER
//#define NO_ECC_KEY_EXPORT
//#define NO_ECC_DHE
//#define NO_ECC_SIGN
//#define NO_ECC_VERIFY

/* Disable Algorithms */
//#define NO_AES
#define HAVE_AESGCM
#define NO_AES_CBC
#define NO_DES3
#define NO_DSA
//#define NO_RSA
#define WOLFSSL_HAVE_SP_RSA
#define WC_NO_HARDEN
#define NO_DH
#define NO_RC4
#define NO_MD4
#define NO_MD5
#define NO_SHA
#define NO_PWDBASED
#define NO_PKCS12
#define NO_PKCS8
//#define WC_NO_RNG

/* Disable Features */
//#define NO_ASN
//#define NO_CERTS
//#define NO_WOLFSSL_MEMORY
//#define WOLFSSL_NO_PEM
#define WOLFSSL_PEM_TO_DER
//#define NO_CODING
#define NO_PSK
#ifndef DEBUG_WOLFSSL
    //#define DEBUG_WOLFSSL
    #define NO_ERROR_STRINGS
#endif

#define SINGLE_THREADED
#ifdef __XTENSA__
#define WOLFSSL_USER_IO
#define NO_FILESYSTEM
#endif
#define NO_WRITEV
#define NO_MAIN_DRIVER

#define CUSTOM_RAND_TYPE unsigned int
extern unsigned int my_rng_seed_gen(void);
#undef  CUSTOM_RAND_GENERATE
#define CUSTOM_RAND_GENERATE my_rng_seed_gen

#define NO_WOLFSSL_SERVER
#define NO_CRYPT_TEST
#define NO_CRYPT_BENCHMARK

#define NO_SESSION_CACHE
#define NO_CLIENT_CACHE

#define NO_OLD_TLS

#define WOLFSSL_STATIC_MEMORY
#define WOLFSSL_NO_MALLOC
#define WOLFSSL_SP_NO_MALLOC
//#define WOLFSSL_DEBUG_MEMORY
//#define WOLFSSL_DEBUG_STATIC_MEMORY

#ifdef __cplusplus
}
#endif

#endif /* EMC_SYSTEM_CELENO_DEVICE_APPLICATION_OFFLOAD_user_settings_H */

// clang-format on
