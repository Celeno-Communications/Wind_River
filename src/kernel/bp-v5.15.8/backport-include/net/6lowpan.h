#ifndef _BACKPORT_NET_6LOWPAN_H
#define _BACKPORT_NET_6LOWPAN_H
#include_next <net/6lowpan.h>

#if LINUX_VERSION_IS_LESS(4,7,0)
/* SCI/DCI is 4 bit width, so we have maximum 16 entries */
#define LOWPAN_IPHC_CTX_TABLE_SIZE	(1 << 4)

struct lowpan_iphc_ctx {
	u8 id;
	struct in6_addr pfx;
	u8 plen;
	unsigned long flags;
};

struct lowpan_iphc_ctx_table {
	spinlock_t lock;
	const struct lowpan_iphc_ctx_ops *ops;
	struct lowpan_iphc_ctx table[LOWPAN_IPHC_CTX_TABLE_SIZE];
};

struct backport_lowpan_dev {
	enum lowpan_lltypes lltype;
	struct dentry *iface_debugfs;
	struct lowpan_iphc_ctx_table ctx;

	/* must be last */
	u8 priv[] __aligned(sizeof(void *));
};
#undef lowpan_priv
#define lowpan_dev backport_lowpan_dev
#define lowpan_priv backport_lowpan_dev

static inline void lowpan_iphc_uncompress_eui48_lladdr(struct in6_addr *ipaddr,
						       const void *lladdr)
{
	/* fe:80::XXXX:XXff:feXX:XXXX
	 *        \_________________/
	 *              hwaddr
	 */
	ipaddr->s6_addr[0] = 0xFE;
	ipaddr->s6_addr[1] = 0x80;
	memcpy(&ipaddr->s6_addr[8], lladdr, 3);
	ipaddr->s6_addr[11] = 0xFF;
	ipaddr->s6_addr[12] = 0xFE;
	memcpy(&ipaddr->s6_addr[13], lladdr + 3, 3);
}

static inline
struct lowpan_dev *lowpan_dev(const struct net_device *dev)
{
	return netdev_priv(dev);
}
#endif



#endif	/* _BACKPORT_NET_6LOWPAN_H */
