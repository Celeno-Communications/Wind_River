/*
 * iwcl userspace tool
 *
 * Copyright (c) 2020, Celeno Communications
 */

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <linux/netlink.h>

#include <netlink/genl/genl.h>
#include <netlink/genl/family.h>
#include <netlink/genl/ctrl.h>
#include <netlink/msg.h>
#include <netlink/attr.h>

#include "iwcl.h"
#include "vendor_cmd.h"
#include "nl80211.h"
#include "cecli.h"

static int (*registered_handler)(struct nl_msg *, void *);
static void *registered_handler_data;

static int error_handler(struct sockaddr_nl *nla, struct nlmsgerr *err,
			 void *arg)
{
	int *ret = arg;

	*ret = err->error;

	return NL_STOP;
}

static int finish_handler(struct nl_msg *msg, void *arg)
{
	int *ret = arg;

	*ret = 0;

	return NL_SKIP;
}

static int ack_handler(struct nl_msg *msg, void *arg)
{
	int *ret = arg;

	*ret = 0;

	return NL_STOP;
}

int cl_msg_recv(struct nl_msg *msg, void **pdata, uint16_t *plen)
{
	struct genlmsghdr *gnlh = nlmsg_data(nlmsg_hdr(msg));
	struct nlattr *attrs[NL80211_ATTR_MAX + 1], *subattr[MAX_CL_VENDOR_ATTR + 1];

	nla_parse(attrs, NL80211_ATTR_MAX, genlmsg_attrdata(gnlh, 0), genlmsg_attrlen(gnlh, 0), NULL);

	if (!attrs[NL80211_ATTR_VENDOR_DATA]) {
		fprintf(stderr,"VENDOR_DATA not found\n");
		return NL_STOP;
	}

	if (nla_parse_nested(subattr, 1, attrs[NL80211_ATTR_VENDOR_DATA], NULL)) {
		fprintf(stderr,"vendor parse nested attr not found\n");
		return NL_STOP;
	}

	if (!subattr[CL_VENDOR_ATTR_REPLY]) {
		fprintf(stderr,"VENDOR_DATA not found\n");
		return NL_STOP;
	}

	*pdata = (void*) nla_data(subattr[CL_VENDOR_ATTR_REPLY]);
	*plen  =  nla_len(subattr[CL_VENDOR_ATTR_REPLY]);

	return NL_OK;
}

long parse_long(char ***pargv, int *pargc)
{
	long number;
	char *endptr;

	if (!*pargc)
		MY_FATAL("Not enough args");

	errno = 0;
	number = strtol(**pargv, &endptr, 0);

	if (endptr == **pargv || (number == LONG_MAX && errno == ERANGE)) {
		/* Handle error */
		MY_FATAL("Parsing error");
	} else {
		/* Computation succeeded */
		--*pargc;
		++*pargv;
	}

	return number;
}

void register_handler(int (*handler)(struct nl_msg *, void *), void *data)
{
	registered_handler = handler;
	registered_handler_data = data;
}

int reply_handler(struct nl_msg *msg, void *arg)
{
	if (registered_handler)
		return registered_handler(msg, arg);

	return NL_OK;
}

static int help_print(struct nl_msg *msg, void *arg)
{
	uint16_t len = 0;
	struct cl_msg_data *msg_data = NULL;

	cl_msg_recv(msg, (void **)&msg_data, &len);

	fprintf(stdout, "%s\n", msg_data->data);

	return 0;
}

static int handle_cmd(struct nl_sock *nl_sock, int nl80211_id, int devidx,
		      int argc, char **argv)
{
	struct nl_msg *msg = nlmsg_alloc();
	struct nlmsghdr *nlh = NULL;
	struct nlattr *nlttr = NULL;
	struct nl_cb *cb;
	struct genlmsghdr hdr = {
		.cmd = NL80211_CMD_VENDOR,
		.version = 0
	};
	int err = 0;
	char more_data = 0;

	if (!msg) {
		printf("%s(): failed to allocate netlink message\n", __func__);
		return -ENOMEM;
	}

	cb = nl_cb_alloc(NL_CB_DEFAULT);
	if (!cb) {
		printf("%s(): failed to allocate netlink callbacks\n", __func__);
		err = 2;
		goto out_free_msg;
	}

	genlmsg_put(msg, 0, 0, nl80211_id, 0, 0, NL80211_CMD_VENDOR, 0);
	NLA_PUT_U32(msg, NL80211_ATTR_IFINDEX, devidx);
	NLA_PUT_U32(msg, NL80211_ATTR_VENDOR_ID, CELENO_OUI);

	if (!strcmp(argv[0], "cecli")) {
		argc--;
		argv++;
		NLA_PUT_U32(msg, NL80211_ATTR_VENDOR_SUBCMD,
			    CL_VNDR_CMDS_CECLI);
		err = handle_cecli_cmd(msg, argc, argv);
	} else if (!strcmp(argv[0], "e2p")) {
		argc--;
		argv++;
		NLA_PUT_U32(msg, NL80211_ATTR_VENDOR_SUBCMD, CL_VNDR_CMDS_E2P);
		err = handle_e2p_cmd(msg, argc, argv);
	} else if (!strcmp(argv[0], "otp")) {
		argc--;
		argv++;
		NLA_PUT_U32(msg, NL80211_ATTR_VENDOR_SUBCMD, CL_VNDR_CMDS_OTP);
		err = handle_otp_cmd(msg, argc, argv);
	} else if (!strcmp(argv[0], "ATE")) {
		argc--;
		argv++;
		NLA_PUT_U32(msg, NL80211_ATTR_VENDOR_SUBCMD, CL_VNDR_CMDS_ATE);
		err = handle_ate_cmd(msg, argc, argv);
	} else if (!strcmp(argv[0], "help") || !strcmp(argv[0], "-h")) {
		argc--;
		argv++;
		NLA_PUT_U32(msg, NL80211_ATTR_VENDOR_SUBCMD, CL_VNDR_CMDS_HELP);
		register_handler(help_print, NULL);
	} else {
		printf("%s(): unknown command %s\n", __func__, *argv);
		err = -EINVAL;
	}

	if (err)
		goto out_cb;

	nl_cb_set(cb, NL_CB_VALID, NL_CB_CUSTOM, reply_handler, (void *)&more_data);

	while (1) {
		err = nl_send_auto_complete(nl_sock, msg);
		if (err < 0)
			goto out_cb;

		err = 1;
		nl_cb_err(cb, NL_CB_CUSTOM, error_handler, &err);
		nl_cb_set(cb, NL_CB_FINISH, NL_CB_CUSTOM, finish_handler, &err);
		nl_cb_set(cb, NL_CB_ACK, NL_CB_CUSTOM, ack_handler, &err);
		while (err > 0)
			nl_recvmsgs(nl_sock, cb);

		if (!more_data)
			break;

		nl_cb_set(cb, NL_CB_VALID, NL_CB_CUSTOM, reply_handler, (void *)&more_data);
		nlh = nlmsg_put(msg, 0, 0, nl80211_id, 0, 0);
		nlttr = nlmsg_find_attr(nlh, sizeof(struct genlmsghdr), NL80211_ATTR_VENDOR_DATA);
		*(char *)nla_data(nlttr) = CL_CECLI_MORE_DATA;
		memcpy(nlmsg_data(nlh), &hdr, sizeof(hdr));
	}

	goto out_cb;

 nla_put_failure:
	printf("%s(): building message failed\n", __func__);
	err = 2;
 out_cb:
	nl_cb_put(cb);
 out_free_msg:
	nlmsg_free(msg);

	return err;
}

static const char *argv0;

int main(int argc, char **argv)
{
	int err = 0;
	int idx;
	int nl80211_id;
	struct nl_sock *nl_sock = NULL;

	if (argc < 2) {
		fprintf(stderr, "Empty command arguments\n");
		return -1;
	}

	argc--;
	argv0 = *argv++;

	nl_sock = nl_socket_alloc();
	if (!nl_sock) {
		fprintf(stderr, "Failed to allocate netlink socket.\n");
		return -ENOMEM;
	}

	if (genl_connect(nl_sock)) {
		fprintf(stderr, "Failed to connect to generic netlink.\n");
		err = -ENOLINK;
		goto out_handle_destroy;
	}

	nl_socket_set_buffer_size(nl_sock, 8192, 8192);

	/* try to set NETLINK_EXT_ACK to 1, ignoring errors */
	err = 1;
	setsockopt(nl_socket_get_fd(nl_sock), SOL_NETLINK,
		   NETLINK_EXT_ACK, &err, sizeof(err));

	nl80211_id = genl_ctrl_resolve(nl_sock, "nl80211");
	if (nl80211_id < 0) {
		fprintf(stderr, "nl80211 not found.\n");
		err = -ENOENT;
		goto out_handle_destroy;
	}

	if ((idx = if_nametoindex(argv[0])) != 0) {
		argc--;
		argv++;
		err = handle_cmd(nl_sock, nl80211_id, idx, argc, argv);
	}

 out_handle_destroy:
	nl_socket_free(nl_sock);

	return err;
}

