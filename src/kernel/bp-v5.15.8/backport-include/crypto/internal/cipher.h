#ifndef _BACKPORT_CRYPTO_INTERNAL_CIPHER_H
#define _BACKPORT_CRYPTO_INTERNAL_CIPHER_H
#include <crypto/algapi.h>


struct backport_crypto_cipher_spawn {
	struct crypto_spawn base;
};
#undef crypto_cipher_spawn
#define crypto_cipher_spawn backport_crypto_cipher_spawn

static inline int crypto_grab_cipher(struct crypto_cipher_spawn *spawn,
				     struct crypto_instance *inst,
				     const char *name, u32 type, u32 mask)
{
	type &= ~CRYPTO_ALG_TYPE_MASK;
	type |= CRYPTO_ALG_TYPE_CIPHER;
	mask |= CRYPTO_ALG_TYPE_MASK;
#if LINUX_VERSION_IS_LESS(5,6,0)
	spawn->base.inst = inst;
	return crypto_grab_spawn(&spawn->base, name, type, mask);
#else
	return crypto_grab_spawn(&spawn->base, inst, name, type, mask);
#endif
}

static inline void crypto_drop_cipher(struct crypto_cipher_spawn *spawn)
{
	crypto_drop_spawn(&spawn->base);
}

static inline struct crypto_alg *crypto_spawn_cipher_alg(
       struct crypto_cipher_spawn *spawn)
{
	return spawn->base.alg;
}

#endif // _BACKPORT_CRYPTO_INTERNAL_CIPHER_H
