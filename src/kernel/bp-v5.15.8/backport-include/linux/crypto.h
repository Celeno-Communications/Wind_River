#ifndef __BACKPORT_CRYPTO_H 
#define __BACKPORT_CRYPTO_H
#include_next <linux/crypto.h>

/*
 * Algorithm masks and types.
 */
#define CRYPTO_ALG_TYPE_MASK		0x0000000f
#define CRYPTO_ALG_TYPE_CIPHER		0x00000001
#define CRYPTO_ALG_TYPE_COMPRESS	0x00000002
#define CRYPTO_ALG_TYPE_AEAD		0x00000003
#define CRYPTO_ALG_TYPE_SKCIPHER	0x00000005
#define CRYPTO_ALG_TYPE_KPP		0x00000008
#define CRYPTO_ALG_TYPE_ACOMPRESS	0x0000000a
#define CRYPTO_ALG_TYPE_SCOMPRESS	0x0000000b
#define CRYPTO_ALG_TYPE_RNG		0x0000000c
#define CRYPTO_ALG_TYPE_AKCIPHER	0x0000000d

#define CRYPTO_ALG_TYPE_ACOMPRESS_MASK	0x0000000e

/*
 * Set if the algorithm has a ->setkey() method but can be used without
 * calling it first, i.e. there is a default key.
 */
#define CRYPTO_ALG_OPTIONAL_KEY		0x00004000

/*
 * Don't trigger module loading
 */
#define CRYPTO_NOLOAD			0x00008000

/*
 * The algorithm may allocate memory during request processing, i.e. during
 * encryption, decryption, or hashing.  Users can request an algorithm with this
 * flag unset if they can't handle memory allocation failures.
 *
 * This flag is currently only implemented for algorithms of type "skcipher",
 * "aead", "ahash", "shash", and "cipher".  Algorithms of other types might not
 * have this flag set even if they allocate memory.
 *
 * In some edge cases, algorithms can allocate memory regardless of this flag.
 * To avoid these cases, users must obey the following usage constraints:
 *    skcipher:
 *	- The IV buffer and all scatterlist elements must be aligned to the
 *	  algorithm's alignmask.
 *	- If the data were to be divided into chunks of size
 *	  crypto_skcipher_walksize() (with any remainder going at the end), no
 *	  chunk can cross a page boundary or a scatterlist element boundary.
 *    aead:
 *	- The IV buffer and all scatterlist elements must be aligned to the
 *	  algorithm's alignmask.
 *	- The first scatterlist element must contain all the associated data,
 *	  and its pages must be !PageHighMem.
 *	- If the plaintext/ciphertext were to be divided into chunks of size
 *	  crypto_aead_walksize() (with the remainder going at the end), no chunk
 *	  can cross a page boundary or a scatterlist element boundary.
 *    ahash:
 *	- The result buffer must be aligned to the algorithm's alignmask.
 *	- crypto_ahash_finup() must not be used unless the algorithm implements
 *	  ->finup() natively.
 */
#define CRYPTO_ALG_ALLOCATES_MEMORY	0x00010000

/*
 * Transform masks and values (for crt_flags).
 */
#define CRYPTO_TFM_NEED_KEY		0x00000001
#if LINUX_VERSION_IS_LESS(5, 0, 0)
#ifdef CPTCFG_CRYPTO_STATS
void crypto_stats_init(struct crypto_alg *alg);
void crypto_stats_get(struct crypto_alg *alg);
void crypto_stats_aead_encrypt(unsigned int cryptlen, struct crypto_alg *alg, int ret);
void crypto_stats_aead_decrypt(unsigned int cryptlen, struct crypto_alg *alg, int ret);
void crypto_stats_ahash_update(unsigned int nbytes, int ret, struct crypto_alg *alg);
void crypto_stats_ahash_final(unsigned int nbytes, int ret, struct crypto_alg *alg);
void crypto_stats_akcipher_encrypt(unsigned int src_len, int ret, struct crypto_alg *alg);
void crypto_stats_akcipher_decrypt(unsigned int src_len, int ret, struct crypto_alg *alg);
void crypto_stats_akcipher_sign(int ret, struct crypto_alg *alg);
void crypto_stats_akcipher_verify(int ret, struct crypto_alg *alg);
void crypto_stats_compress(unsigned int slen, int ret, struct crypto_alg *alg);
void crypto_stats_decompress(unsigned int slen, int ret, struct crypto_alg *alg);
void crypto_stats_kpp_set_secret(struct crypto_alg *alg, int ret);
void crypto_stats_kpp_generate_public_key(struct crypto_alg *alg, int ret);
void crypto_stats_kpp_compute_shared_secret(struct crypto_alg *alg, int ret);
void crypto_stats_rng_seed(struct crypto_alg *alg, int ret);
void crypto_stats_rng_generate(struct crypto_alg *alg, unsigned int dlen, int ret);
void crypto_stats_skcipher_encrypt(unsigned int cryptlen, int ret, struct crypto_alg *alg);
void crypto_stats_skcipher_decrypt(unsigned int cryptlen, int ret, struct crypto_alg *alg);
#else
static inline void crypto_stats_init(struct crypto_alg *alg)
{}
static inline void crypto_stats_get(struct crypto_alg *alg)
{}
static inline void crypto_stats_aead_encrypt(unsigned int cryptlen, struct crypto_alg *alg, int ret)
{}
static inline void crypto_stats_aead_decrypt(unsigned int cryptlen, struct crypto_alg *alg, int ret)
{}
static inline void crypto_stats_ahash_update(unsigned int nbytes, int ret, struct crypto_alg *alg)
{}
static inline void crypto_stats_ahash_final(unsigned int nbytes, int ret, struct crypto_alg *alg)
{}
static inline void crypto_stats_akcipher_encrypt(unsigned int src_len, int ret, struct crypto_alg *alg)
{}
static inline void crypto_stats_akcipher_decrypt(unsigned int src_len, int ret, struct crypto_alg *alg)
{}
static inline void crypto_stats_akcipher_sign(int ret, struct crypto_alg *alg)
{}
static inline void crypto_stats_akcipher_verify(int ret, struct crypto_alg *alg)
{}
static inline void crypto_stats_compress(unsigned int slen, int ret, struct crypto_alg *alg)
{}
static inline void crypto_stats_decompress(unsigned int slen, int ret, struct crypto_alg *alg)
{}
static inline void crypto_stats_kpp_set_secret(struct crypto_alg *alg, int ret)
{}
static inline void crypto_stats_kpp_generate_public_key(struct crypto_alg *alg, int ret)
{}
static inline void crypto_stats_kpp_compute_shared_secret(struct crypto_alg *alg, int ret)
{}
static inline void crypto_stats_rng_seed(struct crypto_alg *alg, int ret)
{}
static inline void crypto_stats_rng_generate(struct crypto_alg *alg, unsigned int dlen, int ret)
{}
static inline void crypto_stats_skcipher_encrypt(unsigned int cryptlen, int ret, struct crypto_alg *alg)
{}
static inline void crypto_stats_skcipher_decrypt(unsigned int cryptlen, int ret, struct crypto_alg *alg)
{}
#endif
#endif /* < 5.0 */
/*
 * A helper struct for waiting for completion of async crypto ops
 */
struct backport_crypto_wait {
	struct completion completion;
	int err;
};
#undef crypto_wait
#define crypto_wait backport_crypto_wait

/*
 * Async ops completion helper functioons
 */
void crypto_req_done(struct crypto_async_request *req, int err);

#if LINUX_VERSION_IS_LESS(4,15,0)
static inline int crypto_wait_req(int err, struct crypto_wait *wait)
{
	switch (err) {
	case -EINPROGRESS:
	case -EBUSY:
		wait_for_completion(&wait->completion);
		reinit_completion(&wait->completion);
		err = wait->err;
		break;
	}

	return err;
}

static inline void crypto_init_wait(struct crypto_wait *wait)
{
	init_completion(&wait->completion);
}
#endif /* LINUX_VERSION_IS_LESS(4,15,0) */

#endif /* __BACKPORT_CRYPTO_H */

