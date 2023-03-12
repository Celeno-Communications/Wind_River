/* Automatically created during backport process */
#ifndef CPTCFG_BPAUTO_BUILD_CRYPTO_LIB_AES
#include_next <crypto/aes.h>
#else
#undef crypto_aes_sbox
#define crypto_aes_sbox LINUX_BACKPORT(crypto_aes_sbox)
#undef crypto_aes_inv_sbox
#define crypto_aes_inv_sbox LINUX_BACKPORT(crypto_aes_inv_sbox)
#undef aes_expandkey
#define aes_expandkey LINUX_BACKPORT(aes_expandkey)
#undef aes_encrypt
#define aes_encrypt LINUX_BACKPORT(aes_encrypt)
#undef aes_decrypt
#define aes_decrypt LINUX_BACKPORT(aes_decrypt)
#include <crypto/backport-aes.h>
#endif /* CPTCFG_BPAUTO_BUILD_CRYPTO_LIB_AES */
