#ifndef CL_NETLINK_H
#define CL_NETLINK_H

#include <linux/if_ether.h>
#include "cl_nl_shared.h"

#define EVENT_LOGGER_TAG_LEN     20
#define EVENT_LOGGER_CONTENT_LEN 256
#define MIN(_a, _b) (((_a) < (_b)) ? (_a) : (_b))
#define MAX(_a, _b) (((_a) > (_b)) ? (_a) : (_b))
#define BW_TO_MHZ(bw)  ((1 << (bw)) * 20)

enum cl_iface_conf {
	CL_IFCONF_AP,
	CL_IFCONF_STA,
	CL_IFCONF_REPEATER,
	CL_IFCONF_MESH_AP,
	CL_IFCONF_MESH_ONLY,

	CL_IFCONF_MAX
};

struct cl_event_logger {
	unsigned char priority;
	unsigned long timestamp;
	unsigned char bss_addr[ETH_ALEN];
	unsigned char tag[EVENT_LOGGER_TAG_LEN];
	unsigned char content[EVENT_LOGGER_CONTENT_LEN];
};

struct cl_netlink_csa_params {
	char bss_idx;
	char cs_cnt;
	char bandwidth;
	signed char sec_chan_offset;
	char ht;
	char vht;
	int freq;
	int center_freq1;
	int center_freq2;
};

struct cl_netlink_disassoc_params {
	char bss_idx;
	unsigned char addr[ETH_ALEN];
};

struct cl_netlink_if_add_param {
	char dev_name[NL80211_WIPHY_NAME_MAXLEN];
	char if_name[NL80211_WIPHY_NAME_MAXLEN];
	int if_type;
};
#endif // CL_NETLINK_H
