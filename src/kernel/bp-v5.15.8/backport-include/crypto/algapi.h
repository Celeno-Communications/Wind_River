#ifndef _BACKPORT_CRYPTO_ALGAPI_H
#define _BACKPORT_CRYPTO_ALGAPI_H
#include_next <crypto/algapi.h>

#if LINUX_VERSION_IS_LESS(5,18,0)
/*
 * Maximum values for blocksize and alignmask, used to allocate
 * static buffers that are big enough for any combination of
 * algs and architectures. Ciphers have a lower maximum size.
 */
#define MAX_ALGAPI_BLOCKSIZE		160
#define MAX_ALGAPI_ALIGNMASK		63
#define MAX_CIPHER_BLOCKSIZE		16
#define MAX_CIPHER_ALIGNMASK		15
#endif

#if LINUX_VERSION_IS_LESS(5,6,0)
struct backport_crypto_instance {
	struct crypto_alg alg;

	struct crypto_template *tmpl;

	union {
		/* Node in list of instances after registration. */
		struct hlist_node list;
		/* List of attached spawns before registration. */
		struct crypto_spawn *spawns;
	};

	void *__ctx[] CRYPTO_MINALIGN_ATTR;
};
#undef crypto_instance
#define crypto_instance backport_crypto_instance


struct backport_crypto_spawn {
	struct list_head list;
	struct crypto_alg *alg;
	union {
		/* Back pointer to instance after registration.*/
		struct crypto_instance *inst;
		/* Spawn list pointer prior to registration. */
		struct crypto_spawn *next;
	};
	const struct crypto_type *frontend;
	u32 mask;
	bool dead;
	bool registered;
};
#undef crypto_spawn
#define crypto_spawn backport_crypto_spawn
#endif /* LINUX_VERSION_IS_LESS(5,6,0) */



#if LINUX_VERSION_IS_LESS(5,1,0)
int crypto_register_templates(struct crypto_template *tmpls, int count);
#endif
#if LINUX_VERSION_IS_LESS(5,1,0)
void crypto_unregister_templates(struct crypto_template *tmpls, int count);
#endif
#if LINUX_VERSION_IS_LESS(4,14,0)
int crypto_inst_setname(struct crypto_instance *inst, const char *name,
			struct crypto_alg *alg);
#endif

#if LINUX_VERSION_IS_LESS(4,14,0)
void __crypto_xor(u8 *dst, const u8 *src1, const u8 *src2, unsigned int size);

static inline void crypto_xor_cpy(u8 *dst, const u8 *src1, const u8 *src2,
				  unsigned int size)
{
	if (IS_ENABLED(CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS) &&
	    __builtin_constant_p(size) &&
	    (size % sizeof(unsigned long)) == 0) {
		unsigned long *d = (unsigned long *)dst;
		unsigned long *s1 = (unsigned long *)src1;
		unsigned long *s2 = (unsigned long *)src2;

		while (size > 0) {
			*d++ = *s1++ ^ *s2++;
			size -= sizeof(unsigned long);
		}
	} else {
		__crypto_xor(dst, src1, src2, size);
	}
}
#endif

#if LINUX_VERSION_IS_LESS(4,20,0)
int crypto_register_notifier(struct notifier_block *nb);
int crypto_unregister_notifier(struct notifier_block *nb);

/* Crypto notification events. */
enum {
	CRYPTO_MSG_ALG_REQUEST,
	CRYPTO_MSG_ALG_REGISTER,
	CRYPTO_MSG_ALG_LOADED,
};
#endif

#endif	/* _CRYPTO_ALGAPI_H */
