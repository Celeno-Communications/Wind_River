#include <net/if.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <netlink/genl/genl.h>
#include <netlink/msg.h>
#include <netlink/attr.h>

#include "nl80211.h"
#include "iwcl.h"
#include "vendor_cmd.h"
#include "e2p.h"
#include "otp.h"

#define SIZE_OF_BYTE                0x08
#define CLIB_CHANNEL_VECTOR_SIZE    8
#define CLIB_CHANNEL_VECTOR_SIZE_6G 15
#define CH_LIST_SIZE                59
#define CH_LIST_SIZE_6G             120

static inline int otp_parse_a2n(unsigned char *parse_input, uint8_t size, char *arg)
{
	int i;

	for (i = 0; i < size ; i++) {
		int temp;
		char *cp = strchr(arg, ':');
		if (cp) {
			*cp = 0;
			cp++;
		}
		if (sscanf(arg, "%d", &temp) != 1)
			return -1;
		if (temp < 0 || temp > 255)
			return -1;

		parse_input[i] = temp;
		if (!cp)
			break;
		arg = cp;
	}
	if (i < size - 1)
		return -1;

	return 0;
}

/*
 * Print function for otp get commands
 */
static int otp_calib_print(struct nl_msg *msg, void *arg)
{
	uint16_t len = 0;
	struct cl_msg_data *msg_data = NULL;
	int8_t val = 0;

	cl_msg_recv(msg, (void **)&msg_data, &len);
	val = *msg_data->data;

	if (len == 0)
		MY_FATAL("otp in reply message");

	fprintf(stdout, "%d\n", (int8_t)val);

	return 0;
}

static int otp_mac_print(struct nl_msg *msg, void *arg)
{
	uint16_t len = 0;
	uint8_t *mac;
	struct cl_msg_data *msg_data = NULL;
	struct cl_otp_get_reply *reply = NULL;

	cl_msg_recv(msg, (void **)&msg_data, &len);
	reply = (struct cl_otp_get_reply *)msg_data->data;

	if (reply == NULL)
		MY_FATAL("Error in reply message");

	mac = reply->otp_data;
	fprintf(stdout, "MAC address = [%02X:%02X:%02X:%02X:%02X:%02X]\n",
		mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

	return 0;
}

static int otp_one_byte_print(struct nl_msg *msg, void *arg)
{
	uint16_t len = 0;
	struct cl_otp_get_reply *reply = NULL;
	struct cl_msg_data *msg_data = NULL;

	cl_msg_recv(msg, (void **)&msg_data, &len);
	reply = (struct cl_otp_get_reply *)msg_data->data;

	if (reply == NULL)
		MY_FATAL("Error in reply message");

	fprintf(stdout, "%hhu\n", reply->otp_data[0]);

	return 0;
}

static int otp_two_bytes_print(struct nl_msg *msg, void *arg)
{
	uint16_t len = 0;
	struct cl_otp_get_reply *reply = NULL;
	struct cl_msg_data *msg_data = NULL;

	cl_msg_recv(msg, (void **)&msg_data, &len);
	reply = (struct cl_otp_get_reply *)msg_data->data;

	if (reply == NULL)
		MY_FATAL("Error in reply message");

	fprintf(stdout, "%hu\n", *(uint16_t *)&reply->otp_data[0]);

	return 0;
}

static int otp_module_hw_rev_id_print(struct nl_msg *msg, void *arg)
{
	uint16_t len = 0;
	uint8_t *module_hw_rev_id;
	struct cl_msg_data *msg_data = NULL;
	struct cl_otp_get_reply *reply = NULL;

	cl_msg_recv(msg, (void **)&msg_data, &len);
	reply = (struct cl_otp_get_reply *)msg_data->data;

	if (reply == NULL)
		MY_FATAL("Error in reply message");

	module_hw_rev_id = reply->otp_data;
	fprintf(stdout, "module_hw_rev_id = [%u:%u]\n",
		module_hw_rev_id[0], module_hw_rev_id[1]);

	return 0;
}

/*
 * otp get commands
 */

static int handle_otp_get_mac(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_OTP_GET_MAC;
	data.addr = ADDR_MAC_ADDR_OTP;
	data.len = SIZE_MAC_ADDR_OTP;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(otp_mac_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_otp_get_power_level(struct nl_msg *msg, int argc,
				      char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
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

	PARSE_U16(data.addr, &argv, &argc);

	if (data.addr >= MAX_POWER_LEVELS) {
		printf("OTP: Invalid power level idx, max val(%u)\n",
				MAX_POWER_LEVELS - 1);
		return -EINVAL;
	}

	data.cmd_id = CL_OTP_GET_POWER_LEVEL;
	data.addr = ADDR_WIFI_VAL_PL0_OTP + data.addr;
	data.len = sizeof(uint8_t);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(otp_one_byte_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_otp_get_freq_offset(struct nl_msg *msg, int argc,
				      char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_OTP_GET_FREQ_OFFSET;
	data.addr = ADDR_FREQ_OFFSET_OTP;
	data.len = SIZE_FREQ_OFFSET_OTP;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(otp_two_bytes_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_otp_get_module_hw_type(struct nl_msg *msg, int argc,
				      char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_OTP_GET_MODULE_HW_TYPE;
	data.addr = ADDR_MODULE_HW_TYPE_OTP;
	data.len = SIZE_MODULE_HW_TYPE_OTP;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(otp_one_byte_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_otp_get_module_hw_rev_id(struct nl_msg *msg, int argc,
				      char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_OTP_GET_MODULE_HW_REVID;
	data.addr = ADDR_MODULE_HW_REVID_OTP;
	data.len = SIZE_MODULE_HW_REVID_OTP;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(otp_module_hw_rev_id_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_otp_get_rfic_wifi_version(struct nl_msg *msg, int argc,
				      char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_OTP_GET_RFIC_WIFI_VERSION_FOR_CALIB;
	data.addr = ADDR_RFIC_WIFI_VERSION_FOR_CALIB_OTP;
	data.len = SIZE_RFIC_WIFI_VERSION_FOR_CALIB_OTP;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(otp_two_bytes_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_otp_get_rfic_bt_version(struct nl_msg *msg, int argc,
				      char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_OTP_GET_RFIC_BT_VERSION_FOR_CALIB;
	data.addr = ADDR_RFIC_BT_VERSION_FOR_CALIB_OTP;
	data.len = SIZE_RFIC_BT_VERSION_FOR_CALIB_OTP;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(otp_two_bytes_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_otp_get_rfic_lut_version(struct nl_msg *msg, int argc,
				      char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_OTP_GET_RFIC_LUT_VERSION_FOR_CALIB;
	data.addr = ADDR_RFIC_LUT_VERSION_FOR_CALIB_OTP;
	data.len = SIZE_RFIC_LUT_VERSION_FOR_CALIB_OTP;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(otp_one_byte_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_otp_get_calib(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct point otp;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc != 3) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_OTP_GET_CALIB;
	PARSE_U8(data.otp.power_level, &argv, &argc);
	PARSE_U8(data.otp.phy, &argv, &argc);
	PARSE_U8(data.otp.chan, &argv, &argc);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(otp_calib_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

/*
 * otp set commands
 */

static int handle_otp_set_addr(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
		uint8_t val;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc != 2) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_OTP_SET_ADDR;
	PARSE_INT_VALIDATE_IN_RANGE(data.addr, &argv, &argc, 0,
				    OTP_LAST_BYTE);
	data.len = sizeof(uint8_t);
	PARSE_U8(data.val, &argv, &argc);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_otp_set_mac(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
		uint8_t mac_addr[ETH_ALEN];
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_OTP_SET_MAC;
	data.addr = ADDR_MAC_ADDR_OTP;
	data.len = SIZE_MAC_ADDR_OTP;
	if (otp_parse_a2n(data.mac_addr, ETH_ALEN, argv[1])) {
		fprintf(stderr, "invalid mac address\n");
		return -EINVAL;
	}

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_otp_set_power_level(struct nl_msg *msg, int argc,
				      char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
		uint8_t val;
	} data;

	if (!msg)
		return -ENOMEM;
	--argc;
	++argv;

	if (argc != 2) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	PARSE_U16(data.addr, &argv, &argc);
	PARSE_U8(data.val, &argv, &argc);
	data.cmd_id = CL_OTP_SET_POWER_LEVEL;
	data.len = sizeof(uint8_t);

	if (data.addr >= MAX_POWER_LEVELS) {
		printf("OTP: Invalid power level idx, max val(%u)\n",
				MAX_POWER_LEVELS - 1);
		return -EINVAL;
	}

	data.addr = ADDR_WIFI_VAL_PL0_OTP + data.addr;

	if (data.val > 121) {
		printf("Invalid offset [1- 121] = %d\n",data.val);
		return -EINVAL;
	}

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_otp_set_freq_offset(struct nl_msg *msg, int argc,
				      char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
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

	data.cmd_id = CL_OTP_SET_FREQ_OFFSET;
	data.addr = ADDR_FREQ_OFFSET_OTP;
	data.len = SIZE_FREQ_OFFSET_OTP;
	PARSE_U16(data.offset, &argv, &argc);

	if (data.offset > 959) {
		printf("Invalid offset [0- 959] = %d\n",data.offset);
		return -EINVAL;
	}

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_otp_set_module_hw_type(struct nl_msg *msg, int argc,
				      char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
		uint8_t module_hw_type;
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

	data.cmd_id = CL_OTP_SET_MODULE_HW_TYPE;
	data.addr = ADDR_MODULE_HW_TYPE_OTP;
	data.len = SIZE_MODULE_HW_TYPE_OTP;
	PARSE_U8(data.module_hw_type, &argv, &argc);

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_otp_set_module_hw_rev_id(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
		uint8_t module_hw_rev_id[SIZE_MODULE_HW_REVID_OTP];
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_OTP_SET_MODULE_HW_REVID;
	data.addr = ADDR_MODULE_HW_REVID_OTP;
	data.len = SIZE_MODULE_HW_REVID_OTP;

	if (otp_parse_a2n(data.module_hw_rev_id, SIZE_MODULE_HW_REVID_OTP, argv[1])) {
		fprintf(stderr, "invalid module hw rev id\n");
		return -EINVAL;
	}

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_otp_set_rfic_wifi_version_for_calib(struct nl_msg *msg, int argc,
				      char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
		uint16_t rfic_wifi_version;
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

	data.cmd_id = CL_OTP_SET_RFIC_WIFI_VERSION_FOR_CALIB;
	data.addr = ADDR_RFIC_WIFI_VERSION_FOR_CALIB_OTP;
	data.len = SIZE_RFIC_WIFI_VERSION_FOR_CALIB_OTP;
	PARSE_U16(data.rfic_wifi_version, &argv, &argc);

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_otp_set_rfic_bt_version_for_calib(struct nl_msg *msg, int argc,
				      char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
		uint16_t rfic_bt_version;
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

	data.cmd_id = CL_OTP_SET_RFIC_BT_VERSION_FOR_CALIB;
	data.addr = ADDR_RFIC_BT_VERSION_FOR_CALIB_OTP;
	data.len = SIZE_RFIC_BT_VERSION_FOR_CALIB_OTP;
	PARSE_U16(data.rfic_bt_version, &argv, &argc);

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_otp_set_rfic_lut_version_for_calib(struct nl_msg *msg, int argc,
				      char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
		uint8_t rfic_lut_version;
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

	data.cmd_id = CL_OTP_SET_RFIC_LUT_VERSION_FOR_CALIB;
	data.addr = ADDR_RFIC_LUT_VERSION_FOR_CALIB_OTP;
	data.len = SIZE_RFIC_LUT_VERSION_FOR_CALIB_OTP;
	PARSE_U8(data.rfic_lut_version, &argv, &argc);

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_otp_set_calib(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct point otp;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if (argc != 4) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_OTP_SET_CALIB;
	PARSE_U8(data.otp.power_level, &argv, &argc);
	PARSE_U8(data.otp.phy, &argv, &argc);
	PARSE_U8(data.otp.chan, &argv, &argc);
	PARSE_S8(data.otp.calib.power_offset, &argv, &argc);

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int otp_help_print(struct nl_msg *msg, void *arg)
{
	uint16_t len = 0;
	struct cl_msg_data *msg_data;

	cl_msg_recv(msg, (void **)&msg_data, &len);

	fprintf(stdout,"%s\n", msg_data->data);

	return 0;
}

static int handle_otp_help(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_OTP_MAX;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(otp_help_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

/*
 * Handlers for otp set commands
 */
static int handle_otp_set_cmd(struct nl_msg *msg, int argc, char **argv)
{
	if (!strcmp(argv[0], "addr"))
		return handle_otp_set_addr(msg, argc, argv);
	else if (!strcmp(argv[0], "mac"))
		return handle_otp_set_mac(msg, argc, argv);
	else if (!strcmp(argv[0], "power_level"))
		return handle_otp_set_power_level(msg, argc, argv);
	else if (!strcmp(argv[0], "freq_offset"))
		return handle_otp_set_freq_offset(msg, argc, argv);
	else if (!strcmp(argv[0], "module_hw_type"))
		return handle_otp_set_module_hw_type(msg, argc, argv);
	else if (!strcmp(argv[0], "module_hw_rev_id"))
		return handle_otp_set_module_hw_rev_id(msg, argc, argv);
	else if (!strcmp(argv[0], "rfic_wifi_version"))
		return handle_otp_set_rfic_wifi_version_for_calib(msg, argc, argv);
	else if (!strcmp(argv[0], "rfic_bt_version"))
		return handle_otp_set_rfic_bt_version_for_calib(msg, argc, argv);
	else if (!strcmp(argv[0], "rfic_lut_version"))
		return handle_otp_set_rfic_lut_version_for_calib(msg, argc, argv);
	else if (!strcmp(argv[0], "calib"))
		return handle_otp_set_calib(msg, argc, argv);
	else
		printf("%s(): unknown otp set command %s\n", __func__, *argv);

	return handle_otp_help(msg, argc, argv);
}

/*
 * Handlers for otp get commands
 */
static int handle_otp_get_cmd(struct nl_msg *msg, int argc, char **argv)
{
	if (!argc) {
		fprintf(stderr,"%s(): no parameters\n",
			__func__);
		return handle_otp_help(msg, argc, argv);
	}

	if (!strcmp(argv[0], "mac"))
		return handle_otp_get_mac(msg, argc, argv);
	else if (!strcmp(argv[0], "power_level"))
		return handle_otp_get_power_level(msg, argc, argv);
	else if (!strcmp(argv[0], "freq_offset"))
		return handle_otp_get_freq_offset(msg, argc, argv);
	else if (!strcmp(argv[0], "module_hw_type"))
		return handle_otp_get_module_hw_type(msg, argc, argv);
	else if (!strcmp(argv[0], "module_hw_rev_id"))
		return handle_otp_get_module_hw_rev_id(msg, argc, argv);
	else if (!strcmp(argv[0], "rfic_wifi_version"))
		return handle_otp_get_rfic_wifi_version(msg, argc, argv);
	else if (!strcmp(argv[0], "rfic_bt_version"))
		return handle_otp_get_rfic_bt_version(msg, argc, argv);
	else if (!strcmp(argv[0], "rfic_lut_version"))
		return handle_otp_get_rfic_lut_version(msg, argc, argv);
	else if (!strcmp(argv[0], "calib"))
		return handle_otp_get_calib(msg, argc, argv);
	else
		printf("%s(): unknown otp get command %s\n", __func__, *argv);

	return handle_otp_help(msg, argc, argv);
}

int handle_otp_cmd(struct nl_msg *msg, int argc, char **argv)
{
	if (!argc) {
		fprintf(stderr,"%s(): no parameters\n",
			__func__);
		return handle_otp_help(msg, argc, argv);
	}
	if (!strcmp(argv[0], "get")) {
		argc--;
		argv++;
		return handle_otp_get_cmd(msg, argc, argv);
	} else if (!strcmp(argv[0], "set")) {
		argc--;
		argv++;
		return handle_otp_set_cmd(msg, argc, argv);
	} else {
		return handle_otp_help(msg, argc, argv);
	}

	return -EINVAL;
}
