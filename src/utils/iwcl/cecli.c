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
#include "cecli.h"

#define MAX_BUF_SIZE 1024

char *message = NULL;

// callback to handle reply message from driver
static int print_vendor_cmd(struct nl_msg *msg, void *arg)
{
	struct cl_msg_data *msg_data = NULL;
	char *more_data = arg;
	int msg_data_len;
	uint16_t len;

	if (NL_OK != cl_msg_recv(msg, (void **)&msg_data, &len) ||
	    !msg_data)
		return NL_STOP;

	len = message ? strlen(message) : 0;
	msg_data_len = strlen(msg_data->data) + 1;
	*more_data = msg_data->more_data;

	if (!len){
		// Single msg received
		if (!msg_data->more_data) {
			fprintf(stdout, "%s\n", msg_data->data);
		} else {
			// First msg received
			message = (char *)malloc(msg_data_len);

			if (!message)
				goto alloc_failed;

			memcpy(message, msg_data->data, msg_data_len);
		}
	} else {
		message = (char *)realloc(message, len + msg_data_len);

		if (!message)
			goto alloc_failed;

		memcpy(message + len, msg_data->data, msg_data_len);
		// Last msg received
		if (!msg_data->more_data) {
			// Print message from driver
			fprintf(stdout, "%s\n", message);
			free(message);
		}
	}

	return NL_OK;

alloc_failed:
	fprintf(stderr, "Failed to alloc message\n");
	return NL_STOP;
}

static void celeno_no_parse(char *buf, int argc, char **argv)
{
	int data_len = 0;
	int i = 0;

	for (i = 0; i < argc; i++) {
		data_len += strlen(argv[i]);
		data_len++;
	}

	memset(buf, 0, MAX_BUF_SIZE);

	//data for driver, just text from cmd line
	for (i = 0; i < argc; i++) {
		strcat(buf, argv[i]);
		strcat(buf, " ");
	}

	buf[data_len - 1] = '\0'; // Remove the trailing space.
}

static void celeno_parser(struct cli_params *cli_params,
			  char *targv[], int argc, int base)
{

	char *params[CLI_MAX_PARAMS] = {NULL};
	uint32_t num_params = 0;
	uint8_t i = 0;
	int param_base = 0;
	char *endptr;
	char tmp[RF_CMD_MAX_LEN] = {0};
	char *argv = tmp;

	if (argc == 1) {
		strcpy(tmp, targv[0]);
		// Validity check #1 - command does not contain ".."
		if (strstr(argv, ".."))
			return;

		// Validity check #2 - command does not end with "."
		if ((strlen(argv) > 0) && (argv[strlen(argv)-1] == '.'))
			return;

		if (*argv == '-')
			argv++;

		params[num_params++] = argv;

		for (i = 0; argv[i] && num_params < CLI_MAX_PARAMS; i++) {
			if ('.' == argv[i]) {
				argv[i] = '\0';
				params[num_params++] = argv + i + 1;
			}
		}
	} else if (argc > 1) {
		for (i = 0; i < argc; i++)
			params[num_params++] = targv[i];

		if (params[0][0]  == '-')
			(params[0])++;
	} else {
		fprintf(stderr, "Invalid number of input argument\n");
		return;
	}

	cli_params->option = params[0][0];
	cli_params->num_params = (num_params - 1);

	for (i = 0; i < cli_params->num_params; i++) {
		// If parameter contains '0x' - force base 16
		param_base = strstr(params[i+1], "0x") ? 16 : base;

		cli_params->params[i] = (int32_t)strtol(params[i + 1],
							&endptr, param_base);

		// Validity check #3 - parameter contains valid characters
		if (*endptr != '\0') {
			memset(cli_params, 0 , sizeof(struct cli_params));
			break;
		}
	}
}

static int handle_cecli_agc_params(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_AGC_PARAMS;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_bf(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_BF;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_bsr(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_BSR;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_bsrp(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_BSRP;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_bss_color(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_BSS_COLOR;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_bw_sig(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_BW_SIG;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_cca(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_CCA;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_chip(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		char buf[MAX_BUF_SIZE];
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	celeno_no_parse(data.buf, argc, argv);

	data.cmd_id = CL_CECLI_CHIP;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_cma(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		char buf[MAX_BUF_SIZE];
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	celeno_no_parse(data.buf, argc, argv);

	data.cmd_id = CL_CECLI_CMA;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_config(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_CONFIG;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_debug(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		int8_t param;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	PARSE_S8(data.param, &argv, &argc);

	data.cmd_id = CL_CECLI_DEBUG;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_dual_nav(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_DUAL_NAV;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_edca(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_EDCA;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_envdet(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_ENVDET;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_fw(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_FW;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_igmp(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_IGMP;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_lcu(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_LCU;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_nco(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_NCO;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_noise(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_NOISE;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_omi(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_OMI;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_power(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_POWER;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_qos(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		char buf[MAX_BUF_SIZE];
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	celeno_no_parse(data.buf, argc, argv);

	data.cmd_id = CL_CECLI_QOS;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_radio(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint32_t param;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	PARSE_U32(data.param, &argv, &argc);

	data.cmd_id = CL_CECLI_RADIO;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_reg(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 16);

	data.cmd_id = CL_CECLI_REG;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_rfic(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_RFIC;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_rssi(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_RSSI;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_rxsens(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_RXSENS;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_rx_filter(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_RX_FILTER;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_sounding(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_SOUNDING;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}
static int handle_cecli_stats(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_STATS;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_tcv(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		char buf[MAX_BUF_SIZE];
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	celeno_no_parse(data.buf, argc, argv);

	data.cmd_id = CL_CECLI_TCV;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_temp(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_TEMP;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_tf(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_TF;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_tim(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_TIM;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_traffic(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_TRAFFIC;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_twt(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_TWT;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_tx(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_TX;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_txq(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_TXQ;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_ul_rssi(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_UL_RSSI;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_version(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		char buf[MAX_BUF_SIZE];
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	celeno_no_parse(data.buf, argc, argv);

	data.cmd_id = CL_CECLI_VERSION;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_vns(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_VNS;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_vw(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_VW;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_wrs(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_WRS;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_otp(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr,"%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_OTP;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_cecli_calib(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct cli_params cli_params;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc < 1) {
		fprintf(stderr, "%s(): no parameters provided\n", __func__);
		return -EINVAL;
	}

	memset(&data.cli_params, 0, (sizeof(struct cli_params)));
	celeno_parser(&data.cli_params, argv, argc, 10);

	data.cmd_id = CL_CECLI_CALIB;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(print_vendor_cmd, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int cecli_help_print(struct nl_msg *msg, void *arg)
{
	uint16_t len = 0;
	struct cl_msg_data *msg_data;

	cl_msg_recv(msg, (void **)&msg_data, &len);

	fprintf(stdout,"%s\n", msg_data->data);

	return 0;
}

static int handle_cecli_help(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_CECLI_MAX;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(cecli_help_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

int handle_cecli_cmd(struct nl_msg *msg, int argc, char **argv)
{
	if (!argc) {
		fprintf(stderr,"%s(): no parameters\n",
			__func__);
		return handle_cecli_help(msg, argc, argv);
	}

	else if (!strcmp(argv[0], "agc_params"))
		return handle_cecli_agc_params(msg, argc, argv);
	else if (!strcmp(argv[0], "bf"))
		return handle_cecli_bf(msg, argc, argv);
	else if (!strcmp(argv[0], "bsr"))
		return handle_cecli_bsr(msg, argc, argv);
	else if (!strcmp(argv[0], "bsrp"))
		return handle_cecli_bsrp(msg, argc, argv);
	else if (!strcmp(argv[0], "bss_color"))
		return handle_cecli_bss_color(msg, argc, argv);
	else if (!strcmp(argv[0], "bw_sig"))
		return handle_cecli_bw_sig(msg, argc, argv);
	else if (!strcmp(argv[0], "cca"))
		return handle_cecli_cca(msg, argc, argv);
	else if (!strcmp(argv[0], "chip"))
		return handle_cecli_chip(msg, argc, argv);
	else if (!strcmp(argv[0], "cma"))
		return handle_cecli_cma(msg, argc, argv);
	else if (!strcmp(argv[0], "config"))
		return handle_cecli_config(msg, argc, argv);
	else if (!strcmp(argv[0], "debug"))
		return handle_cecli_debug(msg, argc, argv);
	else if (!strcmp(argv[0], "dual_nav"))
		return handle_cecli_dual_nav(msg, argc, argv);
	else if (!strcmp(argv[0], "edca"))
		return handle_cecli_edca(msg, argc, argv);
	else if (!strcmp(argv[0], "envdet"))
		return handle_cecli_envdet(msg, argc, argv);
	else if (!strcmp(argv[0], "fw"))
		return handle_cecli_fw(msg, argc, argv);
	else if (!strcmp(argv[0], "igmp"))
		return handle_cecli_igmp(msg, argc, argv);
	else if (!strcmp(argv[0], "lcu"))
		return handle_cecli_lcu(msg, argc, argv);
	else if (!strcmp(argv[0], "nco"))
		return handle_cecli_nco(msg, argc, argv);
	else if (!strcmp(argv[0], "noise"))
		return handle_cecli_noise(msg, argc, argv);
	else if (!strcmp(argv[0], "omi"))
		return handle_cecli_omi(msg, argc, argv);
	else if (!strcmp(argv[0], "power"))
		return handle_cecli_power(msg, argc, argv);
	else if (!strcmp(argv[0], "qos"))
		return handle_cecli_qos(msg, argc, argv);
	else if (!strcmp(argv[0], "radio"))
		return handle_cecli_radio(msg, argc, argv);
	else if (!strcmp(argv[0], "reg"))
		return handle_cecli_reg(msg, argc, argv);
	else if (!strcmp(argv[0], "rfic"))
		return handle_cecli_rfic(msg, argc, argv);
	else if (!strcmp(argv[0], "rssi"))
		return handle_cecli_rssi(msg, argc, argv);
	else if (!strcmp(argv[0], "rxsens"))
		return handle_cecli_rxsens(msg, argc, argv);
	else if (!strcmp(argv[0], "rx_filter"))
		return handle_cecli_rx_filter(msg, argc, argv);
	else if (!strcmp(argv[0], "sounding"))
		return handle_cecli_sounding(msg, argc, argv);
	else if (!strcmp(argv[0], "stats"))
		return handle_cecli_stats(msg, argc, argv);
	else if (!strcmp(argv[0], "tcv"))
		return handle_cecli_tcv(msg, argc, argv);
	else if (!strcmp(argv[0], "temp"))
		return handle_cecli_temp(msg, argc, argv);
	else if (!strcmp(argv[0], "tf"))
		return handle_cecli_tf(msg, argc, argv);
	else if (!strcmp(argv[0], "tim"))
		return handle_cecli_tim(msg, argc, argv);
	else if (!strcmp(argv[0], "traffic"))
		return handle_cecli_traffic(msg, argc, argv);
	else if (!strcmp(argv[0], "twt"))
		return handle_cecli_twt(msg, argc, argv);
	else if (!strcmp(argv[0], "tx"))
		return handle_cecli_tx(msg, argc, argv);
	else if (!strcmp(argv[0], "txq"))
		return handle_cecli_txq(msg, argc, argv);
	else if (!strcmp(argv[0], "ul_rssi"))
		return handle_cecli_ul_rssi(msg, argc, argv);
	else if (!strcmp(argv[0], "version"))
		return handle_cecli_version(msg, argc, argv);
	else if (!strcmp(argv[0], "vns"))
		return handle_cecli_vns(msg, argc, argv);
	else if (!strcmp(argv[0], "vw"))
		return handle_cecli_vw(msg, argc, argv);
	else if (!strcmp(argv[0], "wrs"))
		return handle_cecli_wrs(msg, argc, argv);
	else if (!strcmp(argv[0], "otp"))
                return handle_cecli_otp(msg, argc, argv);
	else if (!strcmp(argv[0], "calib"))
		return handle_cecli_calib(msg, argc, argv);
	else if (!strcmp(argv[0], "help") || !strcmp(argv[0], "-h"))
		return handle_cecli_help(msg, argc, argv);
	else
		printf("%s(): unknown cecli command %s\n", __func__, *argv);

	return handle_cecli_help(msg, argc, argv);
}

