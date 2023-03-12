# SPDX-License-Identifier: GPL-2.0
#
# Cryptographic API
#
#
#obj-$(CPTCFG_CRYPTO) += crypto.o
#
#obj-$(CPTCFG_CRYPTO_ENGINE) += crypto_engine.o
#obj-$(CPTCFG_CRYPTO_FIPS) += fips.o
#
#obj-$(CPTCFG_CRYPTO_ALGAPI2) += crypto_algapi.o
#
#obj-$(CPTCFG_CRYPTO_AEAD2) += aead.o
#obj-$(CPTCFG_CRYPTO_AEAD2) += geniv.o
#
#obj-$(CPTCFG_CRYPTO_SKCIPHER2) += skcipher.o
#obj-$(CPTCFG_CRYPTO_SEQIV) += seqiv.o
#obj-$(CPTCFG_CRYPTO_ECHAINIV) += echainiv.o
#
#obj-$(CPTCFG_CRYPTO_HASH2) += crypto_hash.o
#
#obj-$(CPTCFG_CRYPTO_AKCIPHER2) += akcipher.o
ifeq ($(PLATFORM),EDK32)
obj-$(CPTCFG_CRYPTO_KPP2) += kpp.o
endif

#
#obj-$(CPTCFG_CRYPTO_DH) += dh_generic.o
#
#obj-$(CPTCFG_CRYPTO_RSA) += rsa_generic.o
#
#obj-$(CPTCFG_CRYPTO_SM2) += sm2_generic.o
#
#obj-$(CPTCFG_CRYPTO_ECDSA) += ecdsa_generic.o
#
#obj-$(CPTCFG_CRYPTO_ACOMP2) += crypto_acompress.o
#
#obj-$(CPTCFG_CRYPTO_MANAGER2) += cryptomgr.o
#obj-$(CPTCFG_CRYPTO_USER) += crypto_user.o
#obj-$(CPTCFG_CRYPTO_CMAC) += cmac.o
#obj-$(CPTCFG_CRYPTO_HMAC) += hmac.o
#obj-$(CPTCFG_CRYPTO_VMAC) += vmac.o
#obj-$(CPTCFG_CRYPTO_XCBC) += xcbc.o
#obj-$(CPTCFG_CRYPTO_NULL2) += crypto_null.o
#obj-$(CPTCFG_CRYPTO_MD4) += md4.o
#obj-$(CPTCFG_CRYPTO_MD5) += md5.o
#obj-$(CPTCFG_CRYPTO_RMD160) += rmd160.o
#obj-$(CPTCFG_CRYPTO_SHA1) += sha1_generic.o
#obj-$(CPTCFG_CRYPTO_SHA256) += sha256_generic.o
#obj-$(CPTCFG_CRYPTO_SHA512) += sha512_generic.o
#obj-$(CPTCFG_CRYPTO_SHA3) += sha3_generic.o
#obj-$(CPTCFG_CRYPTO_SM3) += sm3_generic.o
#obj-$(CPTCFG_CRYPTO_STREEBOG) += streebog_generic.o
#obj-$(CPTCFG_CRYPTO_WP512) += wp512.o
#obj-$(CPTCFG_CRYPTO_BLAKE2B) += blake2b_generic.o
#obj-$(CPTCFG_CRYPTO_BLAKE2S) += blake2s_generic.o
#obj-$(CPTCFG_CRYPTO_GF128MUL) += gf128mul.o
#obj-$(CPTCFG_CRYPTO_ECB) += ecb.o
#obj-$(CPTCFG_CRYPTO_CBC) += cbc.o
#obj-$(CPTCFG_CRYPTO_CFB) += cfb.o
#obj-$(CPTCFG_CRYPTO_PCBC) += pcbc.o
#obj-$(CPTCFG_CRYPTO_CTS) += cts.o
#obj-$(CPTCFG_CRYPTO_LRW) += lrw.o
#obj-$(CPTCFG_CRYPTO_XTS) += xts.o
#obj-$(CPTCFG_CRYPTO_CTR) += ctr.o
#obj-$(CPTCFG_CRYPTO_KEYWRAP) += keywrap.o
#obj-$(CPTCFG_CRYPTO_ADIANTUM) += adiantum.o
#obj-$(CPTCFG_CRYPTO_NHPOLY1305) += nhpoly1305.o
#obj-$(CPTCFG_CRYPTO_GCM) += gcm.o
#obj-$(CPTCFG_CRYPTO_CCM) += ccm.o
#obj-$(CPTCFG_CRYPTO_CHACHA20POLY1305) += chacha20poly1305.o
#obj-$(CPTCFG_CRYPTO_AEGIS128) += aegis128.o
#
#obj-$(CPTCFG_CRYPTO_PCRYPT) += pcrypt.o
#obj-$(CPTCFG_CRYPTO_CRYPTD) += cryptd.o
#obj-$(CPTCFG_CRYPTO_DES) += des_generic.o
#obj-$(CPTCFG_CRYPTO_FCRYPT) += fcrypt.o
#obj-$(CPTCFG_CRYPTO_BLOWFISH) += blowfish_generic.o
#obj-$(CPTCFG_CRYPTO_BLOWFISH_COMMON) += blowfish_common.o
#obj-$(CPTCFG_CRYPTO_TWOFISH) += twofish_generic.o
#obj-$(CPTCFG_CRYPTO_TWOFISH_COMMON) += twofish_common.o
#obj-$(CPTCFG_CRYPTO_SERPENT) += serpent_generic.o
#obj-$(CPTCFG_CRYPTO_AES) += aes_generic.o
#obj-$(CPTCFG_CRYPTO_SM4) += sm4_generic.o
#obj-$(CPTCFG_CRYPTO_AES_TI) += aes_ti.o
#obj-$(CPTCFG_CRYPTO_CAMELLIA) += camellia_generic.o
#obj-$(CPTCFG_CRYPTO_CAST_COMMON) += cast_common.o
#obj-$(CPTCFG_CRYPTO_CAST5) += cast5_generic.o
#obj-$(CPTCFG_CRYPTO_CAST6) += cast6_generic.o
#obj-$(CPTCFG_CRYPTO_ARC4) += arc4.o
#obj-$(CPTCFG_CRYPTO_TEA) += tea.o
#obj-$(CPTCFG_CRYPTO_KHAZAD) += khazad.o
#obj-$(CPTCFG_CRYPTO_ANUBIS) += anubis.o
#obj-$(CPTCFG_CRYPTO_SEED) += seed.o
#obj-$(CPTCFG_CRYPTO_CHACHA20) += chacha_generic.o
#obj-$(CPTCFG_CRYPTO_POLY1305) += poly1305_generic.o
#obj-$(CPTCFG_CRYPTO_DEFLATE) += deflate.o
#obj-$(CPTCFG_CRYPTO_MICHAEL_MIC) += michael_mic.o
#obj-$(CPTCFG_CRYPTO_CRC32C) += crc32c_generic.o
#obj-$(CPTCFG_CRYPTO_CRC32) += crc32_generic.o
#obj-$(CPTCFG_CRYPTO_CRCT10DIF) += crct10dif_common.o crct10dif_generic.o
#obj-$(CPTCFG_CRYPTO_AUTHENC) += authenc.o authencesn.o
#obj-$(CPTCFG_CRYPTO_LZO) += lzo.o lzo-rle.o
#obj-$(CPTCFG_CRYPTO_LZ4) += lz4.o
#obj-$(CPTCFG_CRYPTO_LZ4HC) += lz4hc.o
#obj-$(CPTCFG_CRYPTO_XXHASH) += xxhash_generic.o
#obj-$(CPTCFG_CRYPTO_842) += 842.o
#obj-$(CPTCFG_CRYPTO_RNG2) += rng.o
#obj-$(CPTCFG_CRYPTO_ANSI_CPRNG) += ansi_cprng.o
#obj-$(CPTCFG_CRYPTO_DRBG) += drbg.o
#obj-$(CPTCFG_CRYPTO_JITTERENTROPY) += jitterentropy_rng.o
#obj-$(CPTCFG_CRYPTO_TEST) += tcrypt.o
#obj-$(CPTCFG_CRYPTO_GHASH) += ghash-generic.o
#obj-$(CPTCFG_CRYPTO_USER_API) += af_alg.o
#obj-$(CPTCFG_CRYPTO_USER_API_HASH) += algif_hash.o
#obj-$(CPTCFG_CRYPTO_USER_API_SKCIPHER) += algif_skcipher.o
#obj-$(CPTCFG_CRYPTO_USER_API_RNG) += algif_rng.o
#obj-$(CPTCFG_CRYPTO_USER_API_AEAD) += algif_aead.o
#obj-$(CPTCFG_CRYPTO_ZSTD) += zstd.o
#obj-$(CPTCFG_CRYPTO_OFB) += ofb.o
obj-$(CPTCFG_CRYPTO_ECC) += ecc.o
#obj-$(CPTCFG_CRYPTO_ESSIV) += essiv.o
#obj-$(CPTCFG_CRYPTO_CURVE25519) += curve25519-generic.o

ecdh_generic-y += ecdh.o
ecdh_generic-y += ecdh_helper.o
obj-$(CPTCFG_CRYPTO_ECDH) += ecdh_generic.o
#
#obj-$(CPTCFG_CRYPTO_ECRDSA) += ecrdsa_generic.o

#
# generic algorithms and the async_tx api
#
#obj-$(CPTCFG_XOR_BLOCKS) += xor.o
#obj-$(CONFIG_ASYNC_CORE) += async_tx/
#obj-$(CONFIG_ASYMMETRIC_KEY_TYPE) += asymmetric_keys/
#obj-$(CPTCFG_CRYPTO_HASH_INFO) += hash_info.o
#obj-$(CPTCFG_CRYPTO_SIMD) += crypto_simd.o
