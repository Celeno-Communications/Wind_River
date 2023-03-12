/*
 * hci_nc - netcat-like tool to translate HCI interface
 *          to a network socket with a wide range of settings
 *
 * Copyright (c) 2022, Celeno/Renesas
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <poll.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <lib/bluetooth.h>
#include <lib/hci.h>


#define MAXIMUM_BUFFER_SIZE (1023 + 5)

static int port = 0;
static int do_verbose = 0;
static int do_udp = 0;
static int do_ipv6 = 0;
static int dev_id = 0;

static int sock_net = -1;
static int sock_hci = -1;
static int sock_listen = -1;

#define verbose(...) \
	do { \
		if (do_verbose) { \
			fprintf(stderr, __VA_ARGS__); \
			fflush(stderr); \
		} \
	} while (0)

int open_sock_hci(void)
{
	struct sockaddr_hci addr;
	int s;

	s = socket(AF_BLUETOOTH, SOCK_RAW, BTPROTO_HCI);
	if (s < 0) {
		perror("Problem opening BlueZ");
		return 3;
	}

	addr.hci_family = AF_BLUETOOTH;
	addr.hci_dev = dev_id;
	addr.hci_channel = HCI_CHANNEL_USER;

	if (bind(s, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
		perror("Problem binding HCI iface");
		return 3;
	}

	verbose("HCI connection to hci%d established\n", dev_id);

	sock_hci = s;
	return 0;
}

int open_sock_net(void)
{
	struct sockaddr_in addr;
	int s;
	int si;
	socklen_t addr_len;
	char buf[INET_ADDRSTRLEN];

	if (do_udp)
		s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	else
		s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s < 0) {
		perror("Problem opening stream socket");
		return 1;
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = INADDR_ANY;

	if (bind(s, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
		perror("Problem binding net iface");
		close(s);
		return 1;
	}

	if (!do_udp && (listen(s, 1) < 0)) {
		perror("Error when doing listen");
		close(s);
		return 4;
	}

	verbose("Listening on [any] %d ...\n", port);

	if (do_udp) {
		sock_net = s;
		return 0;
	}

	addr_len = sizeof(addr);
	si = accept(s, (struct sockaddr*)&addr, &addr_len);
	if (si < 0) {
		perror("Error while accept");
		close(s);
		return 2;
	}

	if (do_verbose) {
		inet_ntop(AF_INET, &addr.sin_addr, buf, sizeof(buf));
		verbose("Accept connection from [%s:%d]\n", buf,
		        ntohs(addr.sin_port));
	}

	sock_listen = s;
	sock_net = si;
	return 0;
}

int open_sock_net6(void)
{
	struct sockaddr_in6 addr;
	int s;
	int si;
	socklen_t addr_len;
	char buf[INET6_ADDRSTRLEN];

	if (do_udp)
		s = socket(AF_INET6, SOCK_DGRAM, IPPROTO_UDP);
	else
		s = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);
	if (s < 0) {
		perror("Problem opening stream socket");
		return 1;
	}

	addr.sin6_family = AF_INET6;
	addr.sin6_port = htons(port);
	addr.sin6_flowinfo = 0;
	addr.sin6_addr = in6addr_any;
	addr.sin6_scope_id = 0;

	if (bind(s, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
		perror("Problem binding net iface");
		close(s);
		return 1;
	}

	if (!do_udp && (listen(s, 1) < 0)) {
		perror("Error when doing listen");
		close(s);
		return 1;
	}

	verbose("Listening on [any] %d ...\n", port);

	if (do_udp) {
		sock_net = s;
		return 0;
	}

	addr_len = sizeof(addr);
	si = accept(s, (struct sockaddr*)&addr, &addr_len);
	if (si < 0) {
		perror("Error while accept");
		close(s);
		return 4;
	}

	if (do_verbose) {
		inet_ntop(AF_INET6, &addr.sin6_addr, buf, sizeof(buf));
		verbose("Accept connection from [%s]:%d\n", buf,
		        ntohs(addr.sin6_port));
	}

	sock_listen = s;
	sock_net = si;
	return 0;
}

void print_usage(const char *progname)
{
	printf("Usage: %s [-hlvu6] [-p <port>] [-d <hci_dev>]\n", progname);
	printf("	-h           Print help and exit\n");
	printf("	-l           Listen mode (only this supported now)\n");
	printf("	-v           Verbose mode\n");
	printf("	-u           UDP mode instead of default TCP\n");
	printf("	-6           IPv6 usage\n");
	printf("	-p <port>    Set up TCP/UDP port to listen\n");
	printf("	-d <hci_dev> Set which HCI device to use - 0, 1, ...\n");
}

int main_loop(void)
{
	struct pollfd fds[2];
	char buf[MAXIMUM_BUFFER_SIZE];
	ssize_t sz;
	ssize_t sz2;
	int detected;

	while (1) {
		fds[0].fd = sock_hci;
		fds[0].events = POLLIN | POLLHUP;
		fds[0].revents = 0;

		fds[1].fd = sock_net;
		fds[1].events = POLLIN | POLLHUP;
		fds[1].revents = 0;

		detected = poll(&fds[0], 2, 100);
		if (detected < 0) {
			perror("Poll resulted with");
			return 5;
		}

		if (fds[0].revents & (POLLHUP | POLLERR | POLLNVAL)) {
			verbose("HCI socket has been closed\n");
			return 0;
		}

		if (fds[1].revents & (POLLHUP | POLLERR | POLLNVAL)) {
			verbose("Net socket has been closed\n");
			return 0;
		}

		if (fds[0].revents & POLLIN) {
			sz = recv(fds[0].fd, buf, sizeof(buf), 0);
			if (sz < 0) {
				perror("Error receiving");
				return 6;
			}

			sz2 = send(fds[1].fd, buf, sz, 0);
			if (sz2 < 0) {
				perror("Error sending");
				return 6;
			}

			if (sz2 != sz) {
				printf("Error sending %d bytes, sent only %d bytes\n", (int)sz, (int)sz2);
			}
		}

		if (fds[1].revents & POLLIN) {
			sz = recv(fds[1].fd, buf, sizeof(buf), 0);
			if (sz < 0) {
				perror("Error receiving");
				return 6;
			}
			if (sz == 0) {
				verbose("Net socket has been closed\n");
				return 0;
			}

			sz2 = send(fds[0].fd, buf, sz, 0);
			if (sz2 < 0) {
				perror("Error sending");
				return 6;
			}

			if (sz2 != sz) {
				printf("Error sending %d bytes, sent only %d bytes\n", (int)sz, (int)sz2);
			}
		}
	}
}

int main(int argc, char* argv[])
{
	int opt;
	int do_usage = 0;
	int do_listen = 0;
	int res;

	while ((opt = getopt(argc, argv, "lvu6p:d:h")) != EOF) {
		switch(opt) {
		case 'h':
			do_usage = 1;
			break;
		case 'l':
			do_listen = 1;
			break;
		case 'v':
			do_verbose = 1;
			break;
		case 'u':
			do_udp = 1;
			break;
		case '6':
			do_ipv6 = 1;
			break;
		case 'p':
			port = strtol(optarg, NULL, 0);
			break;
		case 'd':
			dev_id = strtol(optarg, NULL, 10);
			break;
		}
	}

	if (do_usage) {
		print_usage(argv[0]);
		return 0;
	}

	if (!do_listen) {
		fprintf(stderr, "Connect mode is not supported yet\n");
		return 7;
	}

	if (port == 0) {
		fprintf(stderr, "Port is not set, type -h for help\n");
		return 7;
	}

	res = open_sock_hci();
	if (res) {
		close(sock_net);
		return res;
	}

	if (do_ipv6) {
		res = open_sock_net6();
		if (res)
			return res;
	} else {
		res = open_sock_net();
		if (res)
			return res;
	}

	res = main_loop();

	close(sock_hci);
	close(sock_net);
	close(sock_listen);

	return res;
}
