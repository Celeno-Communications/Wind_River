/**
 * @file
 * @brief
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_SYSTEM_CELENO_DEVICE_APPLICATION_OFFLOAD_TargConfig_H
#define EMC_SYSTEM_CELENO_DEVICE_APPLICATION_OFFLOAD_TargConfig_H

#define B_LITTLE_ENDIAN

#define baAssert(x)

#ifndef TRUE
#  define TRUE 1
#endif

#ifndef FALSE
#  define FALSE 0
#endif

#define UMM_MALLOC
#include "../examples/malloc/umm_malloc.h"
#define baMalloc(s)        umm_malloc(s)
#define baRealloc(m, s)    umm_realloc(m, s)
#define baFree(m)          umm_free(m)

#if (__STDC_VERSION__ >= 199901L) /* C99: '-std=c99' in GCC */
#  include <stdint.h>
typedef uint8_t  U8;
typedef int8_t   S8;
typedef uint16_t U16;
typedef int16_t  S16;
typedef uint32_t U32;
typedef int32_t  S32;
typedef uint64_t U64;
typedef int64_t  S64;
#else
typedef unsigned char      U8;
typedef signed char        S8;
typedef unsigned short     U16;
typedef signed short       S16;
typedef unsigned long      U32;
typedef signed long        S32;
typedef unsigned long long U64;
typedef signed long long   S64;
#endif

typedef U8 BaBool;

static U32 sharkSslDemoTime = 0;

static inline U32 baGetUnixTime(void)
{
  return sharkSslDemoTime++;
}

typedef struct ThreadMutexBase {
  U32 mutex; /* TO BE IMPLEMENTED */
} ThreadMutexBase;

#define ThreadMutex_destructor(o)  /* TO BE IMPLEMENTED */
#define ThreadMutex_set(o)         /* TO BE IMPLEMENTED */
#define ThreadMutex_release(o)     /* TO BE IMPLEMENTED */
#define ThreadMutex_constructor(o) /* TO BE IMPLEMENTED */

#define SHARKSSL_USE_AES_128 1
#define SHARKSSL_USE_AES_192 0
#define SHARKSSL_USE_AES_256 0

#define SHARKSSL_ENABLE_AES_GCM 1
#define SHARKSSL_ENABLE_AES_CCM 0
#define SHARKSSL_ENABLE_AES_CBC 0

#define SHARKSSL_USE_CHACHA20 1
#define SHARKSSL_USE_SHA_256 1
#define SHARKSSL_USE_SHA_384 0
#define SHARKSSL_USE_SHA_512 0
#define SHARKSSL_USE_SHA1 0
#define SHARKSSL_USE_MD5 0
#define SHARKSSL_USE_POLY1305 1

#define SHARKSSL_SSL_SERVER_CODE 0
#define SHARKSSL_ENABLE_CLIENT_AUTH 1
#define SHARKSSL_SSL_CLIENT_CODE 1

#define SHARKSSL_ENABLE_SNI 0
#define SHARKSSL_ENABLE_RSA 1
#define SHARKSSL_ENABLE_SESSION_CACHE 0
#define SHARKSSL_ENABLE_SECURE_RENEGOTIATION 1
#define SHARKSSL_ENABLE_DHE_RSA 0
#define SHARKSSL_ENABLE_SELECT_CIPHERSUITE 1
#define SHARKSSL_SELECT_CIPHERSUITE_LIST_DEPTH 2
#define SHARKSSL_ENABLE_ALPN_EXTENSION 0
#define SHARKSSL_ENABLE_RSA_API 0
#define SHARKSSL_ENABLE_RSA_PKCS1 0
#define SHARKSSL_ENABLE_RSA_OAEP 0
#define SHARKSSL_ENABLE_ECDSA_API 1
#define SHARKSSL_ECDSA_ONLY_VERIFY 0
#define SHARKSSL_ENABLE_PEM_API 0
#define SHARKSSL_ENABLE_ENCRYPTED_PKCS8_SUPPORT 0
#define SHARKSSL_ENABLE_INFO_API 0
#define SHARKSSL_ENABLE_CERT_CHAIN 1
#define SHARKSSL_ENABLE_CA_LIST 1
#define SHARKSSL_ENABLE_CERTSTORE_API 0
#define SHARKSSL_ENABLE_CLONE_CERTINFO 0
#define SHARKSSL_ENABLE_CERT_KEYUSAGE 0
#define SHARKSSL_MD5_SMALL_FOOTPRINT 0
#define SHARKSSL_SHA1_SMALL_FOOTPRINT 0
#define SHARKSSL_SHA256_SMALL_FOOTPRINT 0
#define SHARKSSL_BIGINT_EXP_SLIDING_WINDOW_K 4
#define SHARKSSL_BIGINT_MULT_LOOP_UNROLL 1
#define SHARKSSL_ENABLE_AES_CTR_MODE 1
#define SHARKSSL_AES_CIPHER_LOOP_UNROLL 1
#define SHARKSSL_BIGINT_WORDSIZE 32
#define SHARKSSL_USE_ECC 1
#define SHARKSSL_ENABLE_ECDSA 1
#define SHARKSSL_ECC_VERIFY_POINT 1
#define SHARKSSL_ECC_TIMING_RESISTANT 0
#define SHARKSSL_ECC_USE_SECP256R1 1
#define SHARKSSL_ECC_USE_SECP384R1 1
#define SHARKSSL_ECC_USE_SECP521R1 0
#define SHARKSSL_ECC_USE_BRAINPOOLP256R1 0
#define SHARKSSL_ECC_USE_BRAINPOOLP384R1 0
#define SHARKSSL_ECC_USE_BRAINPOOLP512R1 0
#define SHARKSSL_ENABLE_ECDHE_RSA 1
#define SHARKSSL_ENABLE_ECDHE_ECDSA 1
#define SHARKSSL_OPTIMIZED_BIGINT_ASM 0
#define SHARKSSL_OPTIMIZED_CHACHA_ASM 0
#define SHARKSSL_OPTIMIZED_POLY1305_ASM 0
#define SHARKSSL_USE_RNG_TINYMT 0
#define SHARKSSL_USE_RNG_FORTUNA 0
#define SHARKSSL_RNG_MULTITHREADED 1
#define SHARKSSL_NOPACK 0
#define SHARKSSL_CHECK_DATE 0

#endif /* EMC_SYSTEM_CELENO_DEVICE_APPLICATION_OFFLOAD_TargConfig_H */
