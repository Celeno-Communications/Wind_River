#include <net/if.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <netlink/genl/genl.h>
#include <netlink/msg.h>
#include <netlink/attr.h>

#include "nl80211.h"
#include "iwcl.h"
#include "vendor_cmd.h"
#include "ate.h"

static int handle_ate_reset(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_ATE_RESET;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_ate_mode(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint8_t mode;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc != 1) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_ATE_MODE;
	PARSE_U8(data.mode, &argv, &argc);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_ate_bw(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint8_t bw;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc != 1) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_ATE_BW;
	PARSE_U8(data.bw, &argv, &argc);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_ate_mcs(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint8_t mcs;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc != 1) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_ATE_MCS;
	PARSE_U8(data.mcs, &argv, &argc);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_ate_nss(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint8_t nss;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc != 1) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_ATE_NSS;
	PARSE_U8(data.nss, &argv, &argc);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_ate_gi(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint8_t gi;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc != 1) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_ATE_GI;
	PARSE_U8(data.gi, &argv, &argc);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_ate_ltf(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint8_t ltf;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc != 1) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_ATE_LTF;
	PARSE_U8(data.ltf, &argv, &argc);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_ate_ldpc(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint8_t ldpc;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc != 1) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_ATE_LDPC;
	PARSE_U8(data.ldpc, &argv, &argc);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_ate_channel(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint32_t ch_num;
		uint32_t ch_bw;
		int32_t freq_delta;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc != 2 && argc != 3) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_ATE_CHANNEL;
	PARSE_U32(data.ch_num, &argv, &argc);
	PARSE_U32(data.ch_bw, &argv, &argc);
	if (argc)
		data.freq_delta = (int32_t)parse_long(&argv, &argc);
	else
		data.freq_delta = 0;

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_ate_ant(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint8_t ant;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc != 1) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_ATE_ANT;
	PARSE_U8(data.ant, &argv, &argc);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_ate_multi_ant(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint8_t bitmap;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc != 1) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_ATE_MULTI_ANT;
	PARSE_U8(data.bitmap, &argv, &argc);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_ate_packet_len(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint32_t packet_len;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc != 1) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_ATE_PACKET_LEN;
	PARSE_U32(data.packet_len, &argv, &argc);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_ate_freq_offset(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t offset;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc != 1) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_ATE_FREQ_OFFSET;
	PARSE_U16(data.offset, &argv, &argc);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int stats_handler(struct nl_msg *msg, void *arg)
{
	uint16_t len = 0;
	struct cl_msg_data *msg_data = NULL;
	struct ate_stats *stats = NULL;

	cl_msg_recv(msg, (void **)&msg_data, &len);
	stats = (struct ate_stats *)msg_data->data;

	printf("user space handler\n");

	if (stats == NULL)
		MY_FATAL("Error in reply message");

	fprintf(stdout,"TX_BW_20 = %u\n",stats->tx_bw20);
	fprintf(stdout,"TX_BW_40 = %u\n",stats->tx_bw40);
	fprintf(stdout,"TX_BW_80 = %u\n",stats->tx_bw80);
	fprintf(stdout,"TX_BW_160 = %u\n",stats->tx_bw160);
	fprintf(stdout,"RX_BW_20 = %u\n",stats->rx_bw20);
	fprintf(stdout,"RX_BW_40 = %u\n",stats->rx_bw40);
	fprintf(stdout,"RX_BW_80 = %u\n",stats->rx_bw80);
	fprintf(stdout,"RX_BW_160 = %u\n",stats->rx_bw160);
	fprintf(stdout,"FCS_ERROR = %u\n",stats->fcs_err);
	fprintf(stdout,"PHY_ERROR = %u\n",stats->phy_err);
	fprintf(stdout,"DELIMITER_ERROR = %u\n",stats->delimiter_err);
	fprintf(stdout,"RX_SUCCESS = %u\n", stats->rx_succsess);
	fprintf(stdout,"RSSI_0 = %d\n",stats->rssi0);
	fprintf(stdout,"RSSI_1 = %d\n",stats->rssi1);
	fprintf(stdout,"RSSI_2 = %d\n",stats->rssi2);
	fprintf(stdout,"RSSI_3 = %d\n",stats->rssi3);
	fprintf(stdout,"RSSI_4 = %d\n",stats->rssi4);
	fprintf(stdout,"RSSI_5 = %d\n",stats->rssi5);

	return 0;
}

static int handle_ate_stat(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc && !strcmp("reset", *argv)) {
		data.cmd_id = CL_ATE_STAT_RESET;
	} else {
		data.cmd_id = CL_ATE_STAT;
		register_handler(stats_handler, NULL);
	}

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_ate_power(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		int8_t power;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc != 1) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_ATE_POWER;
	PARSE_S8(data.power, &argv, &argc);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_ate_power_offset(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		int8_t offset[MAX_ANTENNAS];
	} data;
	int i;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	memset(data.offset, 0, MAX_ANTENNAS);
	data.cmd_id = CL_ATE_POWER_OFFSET;
	for (i = 0; argc && i < MAX_ANTENNAS; ++i)
		PARSE_S8(data.offset[i], &argv, &argc);

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_ate_tx_start(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint32_t tx_cnt;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc != 1) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_ATE_TX_START;
	PARSE_U32(data.tx_cnt, &argv, &argc);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_ate_tx_continuous(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_ATE_TX_CONTINUOUS;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_ate_tx_agg(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint32_t tx_cnt;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc != 1) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_ATE_TX_AGG;
	PARSE_U32(data.tx_cnt, &argv, &argc);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_ate_stop(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_ATE_STOP;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_ate_dummy_sta(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint8_t num_sta;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc != 1) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_ATE_DUMMY_STA;
	PARSE_U8(data.num_sta, &argv, &argc);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int ate_help_print(struct nl_msg *msg, void *arg)
{
	uint16_t len = 0;
	struct cl_msg_data *msg_data = NULL;

	cl_msg_recv(msg, (void **)&msg_data, &len);

	fprintf(stdout, "%s\n", msg_data->data);

	return 0;
}

static int handle_ate_help(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_ATE_MAX;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(ate_help_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

int handle_ate_cmd(struct nl_msg *msg, int argc, char **argv)
{
	if (!argc) {
		fprintf(stderr,"%s(): no parameters\n",
			__func__);
		return handle_ate_help(msg, argc, argv);
	}

	if (!strcmp(argv[0], "reset"))
		return handle_ate_reset(msg, argc, argv);
	else if (!strcmp(argv[0], "mode"))
		return handle_ate_mode(msg, argc, argv);
	else if (!strcmp(argv[0], "bw"))
		return handle_ate_bw(msg, argc, argv);
	else if (!strcmp(argv[0], "mcs"))
		return handle_ate_mcs(msg, argc, argv);
	else if (!strcmp(argv[0], "nss"))
		return handle_ate_nss(msg, argc, argv);
	else if (!strcmp(argv[0], "gi"))
		return handle_ate_gi(msg, argc, argv);
	else if (!strcmp(argv[0], "ltf"))
		return handle_ate_ltf(msg, argc, argv);
	else if (!strcmp(argv[0], "ldpc"))
		return handle_ate_ldpc(msg, argc, argv);
	else if (!strcmp(argv[0], "channel"))
		return handle_ate_channel(msg, argc, argv);
	else if (!strcmp(argv[0], "ant"))
		return handle_ate_ant(msg, argc, argv);
	else if (!strcmp(argv[0], "multi_ant"))
		return handle_ate_multi_ant(msg, argc, argv);
	else if (!strcmp(argv[0], "packet_len"))
		return handle_ate_packet_len(msg, argc, argv);
	else if (!strcmp(argv[0], "freq_offset"))
		return handle_ate_freq_offset(msg, argc, argv);
	else if (!strcmp(argv[0], "stat"))
		return handle_ate_stat(msg, argc, argv);
	else if (!strcmp(argv[0], "power"))
		return handle_ate_power(msg, argc, argv);
	else if (!strcmp(argv[0], "power_offset"))
		return handle_ate_power_offset(msg, argc, argv);
	else if (!strcmp(argv[0], "tx_start"))
		return handle_ate_tx_start(msg, argc, argv);
	else if (!strcmp(argv[0], "tx_continuous"))
		return handle_ate_tx_continuous(msg, argc, argv);
	else if (!strcmp(argv[0], "tx_agg"))
		return handle_ate_tx_agg(msg, argc, argv);
	else if (!strcmp(argv[0], "stop"))
		return handle_ate_stop(msg, argc, argv);
	else if (!strcmp(argv[0], "dummy_sta"))
		return handle_ate_dummy_sta(msg, argc, argv);
	else if (!strcmp(argv[0], "help") || !strcmp(argv[0], "-h"))
		return handle_ate_help(msg, argc, argv);
	else
		printf("%s(): unknown ATE command %s\n", __func__, *argv);

	return handle_ate_help(msg, argc, argv);
}

