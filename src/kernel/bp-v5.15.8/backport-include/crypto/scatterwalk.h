#ifndef _BACKPORT_CRYPTO_SCATTERWALK_H
#define _BACKPORT_CRYPTO_SCATTERWALK_H
#include_next <crypto/scatterwalk.h>

/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Cryptographic scatter and gather helpers.
 *
 * Copyright (c) 2002 James Morris <jmorris@intercode.com.au>
 * Copyright (c) 2002 Adam J. Richter <adam@yggdrasil.com>
 * Copyright (c) 2004 Jean-Luc Cooke <jlcooke@certainkey.com>
 * Copyright (c) 2007 Herbert Xu <herbert@gondor.apana.org.au>
 */

#if LINUX_VERSION_IS_LESS(4,19,0)
#define scatterwalk_crypto_chain LINUX_BACKPORT(scatterwalk_crypto_chain)
static inline void scatterwalk_crypto_chain(struct scatterlist *head,
					    struct scatterlist *sg, int num)
{
	if (sg)
		sg_chain(head, num, sg);
	else
		sg_mark_end(head);
}
#endif

static inline void scatterwalk_pagedone(struct scatter_walk *walk, int out,
					unsigned int more)
{
	if (out) {
		struct page *page;

		page = sg_page(walk->sg) + ((walk->offset - 1) >> PAGE_SHIFT);
		flush_dcache_page(page);
	}

	if (more && walk->offset >= walk->sg->offset + walk->sg->length)
		scatterwalk_start(walk, sg_next(walk->sg));
}

#endif  /* _CRYPTO_SCATTERWALK_H */
