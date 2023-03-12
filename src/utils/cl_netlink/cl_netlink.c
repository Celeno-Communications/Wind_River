/*
 * cl_netlink userspace tool
 *
 * Copyright (c) 2020, Celeno Communications
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/wireless.h>
#include <linux/netlink.h>
#include <linux/nl80211.h>

#include <netlink/genl/genl.h>
#include <netlink/genl/ctrl.h>

#include "cl_netlink.h"

#define MAX_BUFF 128
#define MAX_CMD 256
#define MAX_TCV_NUM 4
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

struct cl_nl_descr {
	char *descr;
	int fd;
	int sock;
	int join_grp;
	int buf_sz;
	char *buf;
	void *private_data;
	void (*init)(struct cl_nl_descr *nl_descr);
	int (*open)(struct cl_nl_descr *nl_descr);
	void (*close)(struct cl_nl_descr *nl_descr);
	int (*recv)(struct cl_nl_descr *nl_descr);
};

#ifndef MAC2STR
#define MAC2STR(a) (a)[0], (a)[1], (a)[2], (a)[3], (a)[4], (a)[5]
#define MACSTR "%02x:%02x:%02x:%02x:%02x:%02x"
#endif

static int do_fork = 1;

static int nvram_get(char *file_str, char *key, char *val)
{
	FILE *fp = NULL;
	int status = 0;
	char *cl_install_dir = getenv("cl_install_dir");
	char nvg_command[MAX_BUFF] = {0};

	if (!cl_install_dir) {
		printf("cl_install_dir not found. Please export it\n");
		return -1;
	}

	snprintf(nvg_command, MAX_BUFF, "%s/scripts/nvram_get %s %s",
		 cl_install_dir, file_str, key);
	fp = popen(nvg_command, "r");

	if (fp == NULL) {
		printf("%s: popen error\n", __func__);
		return -1;
	}

	if (fgets(val, MAX_BUFF, fp) == NULL) {
		pclose(fp);
		return -1;
	}

	status = pclose(fp);

	if (status == -1) {
		printf("%s: fclose error\n", __func__);
		return -1;
	}

	return 0;
}

static int run_cmd(char *cmd)
{
	int rc = 0;

	rc = system(cmd);
	if (rc != 0) {
		fprintf(stderr, "Command (%s) exec failure: %d\n", cmd, rc);
	}
	return rc;
}

static void netlink_init(struct cl_nl_descr *nl_descr)
{
	printf("[%s] Initing: %s\n", __func__, nl_descr->descr);
	nl_descr->sock = -1;
}

static void netlink_close(struct cl_nl_descr *nl_descr)
{
	if (nl_descr->sock != -1) {
		printf("[%s] Closing %s: %u\n", __func__, nl_descr->descr,
		       nl_descr->sock);
		close(nl_descr->sock);
		nl_descr->sock = -1;
	}

	if (nl_descr->buf) {
		free(nl_descr->buf);
		nl_descr->buf = NULL;
	}
}

static void handle_event_ch_switch(struct cl_nl_event *event)
{
	char cmd[MAX_CMD];
	int len = 0;
	struct cl_netlink_csa_params *csa = (struct cl_netlink_csa_params *)event->data;

	len += snprintf(cmd + len, MAX_CMD - len,
		       "hostapd_cli -p /tmp/hostapd -iwlan%u_%u chan_switch %u %d center_freq1=%d ",
			event->tcv_idx, csa->bss_idx, csa->cs_cnt, csa->freq, csa->center_freq1);

	len += snprintf(cmd + len, MAX_CMD - len, "bandwidth=%d ", BW_TO_MHZ(csa->bandwidth));

	if (csa->center_freq2)
		len += snprintf(cmd + len, MAX_CMD - len, "center_freq2=%d ",
			       csa->center_freq2);

	if (csa->sec_chan_offset)
		len += snprintf(cmd + len, MAX_CMD - len, "sec_channel_offset=%d ",
			       csa->sec_chan_offset);

	if (csa->ht)
		len += snprintf(cmd + len, MAX_CMD - len, "ht ");

	if (csa->vht)
		len += snprintf(cmd + len, MAX_CMD - len, "vht");

	run_cmd(cmd);
}

static void handle_event_co_locate_update(struct cl_nl_event *event)
{
	char idx = 0;
	char tcv[32] = {0};
	char rnr_beacon[MAX_BUFF] = {0};
	char he_co_locate[MAX_BUFF] = {0};

	sprintf(tcv, "tcv%u", event->tcv_idx);
	if (nvram_get(tcv, "ha_he_co_locate", he_co_locate))
		return;

	for (idx = 0; idx < MAX_TCV_NUM; idx++) {
		if (idx == event->tcv_idx)
			continue;
		sprintf(tcv, "tcv%u", idx);
		if (!nvram_get(tcv, "ha_he_co_locate", he_co_locate)) {
			if (atoi(he_co_locate) == 0)
				continue;
			if (!nvram_get(tcv, "ha_rnr_beacon", rnr_beacon)) {
				char *en;
				char bss_idx = 0;

				for (en = strtok(rnr_beacon, ","); en;
				     bss_idx++, en = strtok(NULL, ",")) {
					if (!strcmp(en, "1")) {
						char cmd[MAX_CMD];

						sprintf(cmd, "hostapd_cli -p /tmp/hostapd -iwlan%u_%u update_beacon", idx, bss_idx);
						run_cmd(cmd);
					}
				}
			}
		}
	}
}

static void handle_event_disassoc(struct cl_nl_event *event)
{
	char cmd[MAX_CMD];
	struct cl_netlink_disassoc_params *disassoc = (struct cl_netlink_disassoc_params *)event->data;

	sprintf(cmd, "hostapd_cli -p /tmp/hostapd -iwlan%u_%u DISASSOCIATE " MACSTR, event->tcv_idx,
			disassoc->bss_idx, MAC2STR(disassoc->addr));

	run_cmd(cmd);
}

static void handle_event_if_add(struct cl_nl_event *event)
{
	char cmd[MAX_CMD];
	char type[8];
	struct cl_netlink_if_add_param *if_add = (struct cl_netlink_if_add_param *)event->data;

	if (if_add->if_type == CL_IFCONF_AP) {
		sprintf(type, "__ap");
	} else if (if_add->if_type == CL_IFCONF_STA) {
		sprintf(type, "station");
	} else {
		printf("unknown if_type %d !!!\n", if_add->if_type);
		return;
	}

	snprintf(cmd, MAX_CMD, "iw %s interface add %s type %s",
		 if_add->dev_name, if_add->if_name, type);

	run_cmd(cmd);
}

static void netlink_process_cl_rx_buf(struct cl_nl_event *event)
{
	switch (event->event_id) {
	case CL_NL_EVENT_ID_CH_SWITCH:
		handle_event_ch_switch(event);
		break;
	case CL_NL_EVENT_ID_CO_LOCATE_UPDATE:
		handle_event_co_locate_update(event);
		break;
	case CL_NL_EVENT_ID_DISASSOCIATE:
		handle_event_disassoc(event);
		break;
	case CL_NL_EVENT_ID_IF_ADD:
		handle_event_if_add(event);
		break;
	}
}

static int netlink_vendor_recv_cb(struct nl_msg *msg, void *arg)
{
	struct nlmsghdr* ret_hdr = nlmsg_hdr(msg);
	struct genlmsghdr *gnlh = nlmsg_data(ret_hdr);
	struct nlattr *attrs[NL80211_ATTR_MAX + 1];
	int rem;
	struct nlattr *current_attr = NULL;
	struct cl_nl_event *event = NULL;

	nla_parse(attrs, NL80211_ATTR_MAX,
		  genlmsg_attrdata(gnlh, 0), genlmsg_attrlen(gnlh, 0), NULL);

	if (!attrs[NL80211_ATTR_VENDOR_ID]) {
		fprintf(stderr,"Unable to find vendor ID\n");
		return NL_SKIP;
	}

	if (nla_get_u32(attrs[NL80211_ATTR_VENDOR_ID]) != CELENO_OUI)
		return NL_SKIP;

	if (!attrs[NL80211_ATTR_VENDOR_SUBCMD])
		return NL_SKIP;

	/* Currently - this the only supported event */
	if (nla_get_u32(attrs[NL80211_ATTR_VENDOR_SUBCMD]) != CL_VENDOR_EVENT_ASYNC)
		return NL_SKIP;

	if (!attrs[NL80211_ATTR_VENDOR_DATA])
		return NL_SKIP;

	nla_for_each_nested(current_attr, attrs[NL80211_ATTR_VENDOR_DATA], rem) {
		if (nla_ok(current_attr, rem) &&
				nla_type(current_attr) == CL_VENDOR_ATTR_DATA &&
				nla_len(current_attr) == sizeof(*event)) {
			event = nla_data(current_attr);
			netlink_process_cl_rx_buf(event);
		}
	}

	return NL_OK;
}

static int netlink_vendor_recv(struct cl_nl_descr *nl_descr)
{
	nl_recvmsgs_default((struct nl_sock *)nl_descr->private_data);
	return 0;
}

static int netlink_vendor_open(struct cl_nl_descr *nl_descr)
{
	struct nl_sock *nl_sock;
	int ret = 0;

	/* Already open */
	if (nl_descr->sock != -1)
		return nl_descr->sock;

	nl_sock = nl_socket_alloc();
	if (!nl_sock) {
		fprintf(stderr, "Unable to alloace socket\n");
		return -1;
	}

	nl_descr->private_data = nl_sock;
	ret = genl_connect(nl_sock);
	if (ret < 0) {
		fprintf(stderr, "Unable to connect: %d\n", ret);
		goto error;
	}

	nl_descr->sock = nl_socket_get_fd(nl_sock);

	ret = genl_ctrl_resolve_grp(nl_sock, "nl80211", "vendor");
	if (ret < 0) {
		fprintf(stderr, "Vendor group not found: %d\n", ret);
		goto error;
	}

	ret = nl_socket_add_membership(nl_sock, ret);
	if (ret < 0) {
		fprintf(stderr, "Unable to add membership: %d\n", ret);
		goto error;
	}

	nl_socket_disable_seq_check(nl_sock);
	ret = nl_socket_modify_cb(nl_sock, NL_CB_VALID, NL_CB_CUSTOM, netlink_vendor_recv_cb, NULL);
	if (ret < 0) {
		fprintf(stderr, "Unable to register callback: %d\n", ret);
		goto error;
	}

	return nl_descr->sock;

error:
	nl_descr->close(nl_descr);
	return -1;
}

static void netlink_vendor_close(struct cl_nl_descr *nl_descr)
{
	nl_socket_free((struct nl_sock *)nl_descr->private_data);
	nl_descr->private_data = NULL;
	/* Sock should be free already by nl_socket_free */
	nl_descr->sock = -1;
	netlink_close(nl_descr);
}

struct cl_nl_descr registered_ops[] = {
	{
	    .descr = "cl/vendor",
	    .fd = -1,
	    .sock = 0,
	    .join_grp = -1,
	    .buf_sz = 4096,
	    .private_data = NULL,
	    .init = netlink_init,
	    .open = netlink_vendor_open,
	    .recv = netlink_vendor_recv,
	    .close = netlink_vendor_close,
	}
};

static int netlink_task(void)
{
	fd_set readfds, exceptfds;
	struct timeval tv;
	int fd_num, nfds;
	struct cl_nl_descr *nl_descr = NULL;
	int i = 0;

	for (i = 0; i < ARRAY_SIZE(registered_ops); i++) {
		nl_descr = &registered_ops[i];

		nl_descr->init(nl_descr);
	}

	for (;;) {
		FD_ZERO(&readfds);
		FD_ZERO(&exceptfds);
		nfds = 0;

		for (i = 0; i < ARRAY_SIZE(registered_ops); i++) {
			nl_descr = &registered_ops[i];

			nl_descr->fd = nl_descr->open(nl_descr);
			if (nl_descr->fd > 0) {
				FD_SET(nl_descr->fd, &readfds);
				FD_SET(nl_descr->fd, &exceptfds);
				if (nl_descr->fd >= nfds)
					nfds = nl_descr->fd + 1;
			}
		}

		if (!nfds)
			continue;

		tv.tv_sec = 10;
		tv.tv_usec = 500000;
		fd_num = select(nfds, &readfds, NULL, &exceptfds, &tv);

		if (fd_num < 0) {
			fprintf(stderr, "error fd_num=%d\n", fd_num);
			break;
		}

		if (fd_num == 0)
			continue;

		/* Handle Netlink messages from kernel */
		for (i = 0; i < ARRAY_SIZE(registered_ops); i++) {
			nl_descr = &registered_ops[i];

			if ((nl_descr->fd > 0) && FD_ISSET(nl_descr->fd, &exceptfds)) {
				fprintf(stderr,
					"Closing socket %d at exception\n",
					nl_descr->fd);
				FD_CLR(nl_descr->fd, &readfds);
				nl_descr->close(nl_descr);
			}

			if ((nl_descr->fd > 0) && FD_ISSET(nl_descr->fd, &readfds)) {
				nl_descr->recv(nl_descr);
			}
		}
	}

	return 0;
}

int netlink_start(void)
{
	pid_t pid;

	printf("%s\n", __func__);

	/* background ourself */
	pid = do_fork ? fork() : getpid();

	switch (pid) {
	case -1:
		/* error */
		perror("fork/getpid");
		return -1;
	case 0:
		/* child, success */
		break;
	default:
		/* parent, success */
		if (do_fork)
			return 0;
		break;
	}

	// Main loop
	while (netlink_task() == -1);

	return 0;
}

int main(int argc, char **argv)
{
	netlink_start();
	return 0;
}
