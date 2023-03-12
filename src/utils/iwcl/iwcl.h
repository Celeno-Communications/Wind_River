#ifndef __IWCL_H
#define __IWCL_H

#include "cl_nl_shared.h"

#ifndef SOL_NETLINK
#define SOL_NETLINK 270
#endif

/* support for extack if compilation headers are too old */
#ifndef NETLINK_EXT_ACK
#define NETLINK_EXT_ACK 11
enum nlmsgerr_attrs {
	NLMSGERR_ATTR_UNUSED,
	NLMSGERR_ATTR_MSG,
	NLMSGERR_ATTR_OFFS,
	NLMSGERR_ATTR_COOKIE,

	__NLMSGERR_ATTR_MAX,
	NLMSGERR_ATTR_MAX = __NLMSGERR_ATTR_MAX - 1
};
#endif

#define ETH_ALEN 6
#define MAX_ANTENNAS 2

#define MSG_SIZE 4095

struct cl_msg_data {
	char more_data;
	char data[MSG_SIZE];
} __attribute__((__packed__));

void register_handler(int (*handler)(struct nl_msg *, void *), void *data);

int handle_cecli_cmd(struct nl_msg *msg, int argc, char **argv);
int handle_e2p_cmd(struct nl_msg *msg, int argc, char **argv);
int handle_otp_cmd(struct nl_msg *msg, int argc, char **argv);
int handle_ate_cmd(struct nl_msg *msg, int argc, char **argv);

#endif // __IWCL_H
