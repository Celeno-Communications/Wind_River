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

#define SIZE_OF_BYTE                0x08
#define CLIB_CHANNEL_VECTOR_SIZE    8
#define CLIB_CHANNEL_VECTOR_SIZE_6G 15
#define CH_LIST_SIZE                59
#define CH_LIST_SIZE_6G             120

static const uint8_t ch_list_24g_5g_6g[NUM_TOTAL_PIVOTS] = {
	1, 6, 11, 36, 64, 100, 120, 140, 165, 9,
	41, 97, 137, 173, 209
};

static inline int e2p_module_hw_rev_id_a2n(unsigned char *module_hw_rev_id, char *arg)
{
	int i;

	for (i = 0; i < SIZE_MODULE_HW_REVID_E2P ; i++) {
		int temp;
		char *cp = strchr(arg, '.');
		if (cp) {
			*cp = 0;
			cp++;
		}
		if (sscanf(arg, "%d", &temp) != 1)
			return -1;
		if (temp < 0 || temp > 255)
			return -1;

		module_hw_rev_id[i] = temp;
		if (!cp)
			break;
		arg = cp;
	}
	if (i < SIZE_MODULE_HW_REVID_E2P - 1)
		return -1;

	return 0;
}


/*
 * Print function for e2p get commands
 */
static int e2p_addr_print(struct nl_msg *msg, void *arg)
{
	uint16_t len = 0;
	uint8_t val;
	struct cl_msg_data *msg_data = NULL;
	struct cl_e2p_get_reply *reply = NULL;

	cl_msg_recv(msg, (void **)&msg_data, &len);
	reply = (struct cl_e2p_get_reply *)msg_data->data;

	if (reply == NULL)
		MY_FATAL("Error in reply message");

	val = reply->e2p_data[0];

	fprintf(stdout, "0x%02x\n", val);

	return 0;
}

static int e2p_calib_print(struct nl_msg *msg, void *arg)
{
	uint16_t len = 0;
	struct cl_msg_data *msg_data = NULL;
	struct phy_calib *val = NULL;

	cl_msg_recv(msg, (void **)&msg_data, &len);
	val = (struct phy_calib *)msg_data->data;

	if (val == NULL || len == 0)
		MY_FATAL("Error in reply message");

	fprintf(stdout, "%d\n", (int8_t)val->power_offset);

	return 0;
}

static int e2p_one_byte_print(struct nl_msg *msg, void *arg)
{
	uint16_t len = 0;
	struct cl_e2p_get_reply *reply = NULL;
	struct cl_msg_data *msg_data = NULL;

	cl_msg_recv(msg, (void **)&msg_data, &len);
	reply = (struct cl_e2p_get_reply *)msg_data->data;

	if (reply == NULL)
		MY_FATAL("Error in reply message");

	fprintf(stdout, "%hhu\n", reply->e2p_data[0]);

	return 0;
}

static int e2p_two_bytes_print(struct nl_msg *msg, void *arg)
{
	uint16_t len = 0;
	struct cl_e2p_get_reply *reply = NULL;
	struct cl_msg_data *msg_data = NULL;

	cl_msg_recv(msg, (void **)&msg_data, &len);
	reply = (struct cl_e2p_get_reply *)msg_data->data;

	if (reply == NULL)
		MY_FATAL("Error in reply message");

	fprintf(stdout, "%hu\n", *(uint16_t *)&reply->e2p_data[0]);

	return 0;
}

static int e2p_module_hw_rev_id_print(struct nl_msg *msg, void *arg)
{
	uint16_t len = 0;
	uint8_t *module_hw_rev_id;
	struct cl_msg_data *msg_data = NULL;
	struct cl_e2p_get_reply *reply = NULL;

	cl_msg_recv(msg, (void **)&msg_data, &len);
	reply = (struct cl_e2p_get_reply *)msg_data->data;

	if (reply == NULL)
		MY_FATAL("Error in reply message");

	module_hw_rev_id = reply->e2p_data;
	fprintf(stdout, "module_hw_rev_id = [%u.%u]\n",
		module_hw_rev_id[0], module_hw_rev_id[1]);

	return 0;
}

static int8_t cl_calibration_pdi_to_power_offset(int8_t pdi)
{
	/*
	 * Get calib read PDI - Power Difference Index (valid values are 1 - 121 [0.25dBm]),
	  the user expect to get power offset in 0.25 dB resolution (valid values are -40 - 80)
	 */
	return pdi - 41;
}

static int e2p_get_table_print(struct nl_msg *msg, void *arg)
{
	struct cl_e2p_get_reply *reply = NULL;
	struct cl_msg_data *msg_data = NULL;
	uint16_t len = 0, pivot = 0, pl = 0, cal = 0, temp= 0, phy = 0;
	uint8_t *eeprom;
	uint8_t num_pivots = NUM_OF_PIVOTS(NL80211_BAND_2GHZ);

	cl_msg_recv(msg, (void **)&msg_data, &len);
	reply = (struct cl_e2p_get_reply *)msg_data->data;

	eeprom = reply->e2p_data;

	fprintf(stdout, "   Frequency Offset:           %u\n", *(uint16_t*)&eeprom[ADDR_FREQ_OFFSET_E2P]);

	fprintf(stdout, "  /================ Calibration Data ================\\\n");
	fprintf(stdout, " /====|=======|===========|===|==================|====\\\n");
	fprintf(stdout, "/Pivot|Channel|power level|phy|power offset (PDI)|temp|\n");
	fprintf(stdout, "|-----|-------|-----------|---|------------------|----|\n");

	cal = ADDR_CALIB_24G_E2P;
	temp = ADDR_TEMP_24G_E2P;

	for (pl = 0; pl < MAX_POWER_LEVELS; pl++) {
		for (phy = 0; phy < MAX_ANTENNAS; phy++) {
			for (pivot = 0; pivot < num_pivots; pivot++) {
				fprintf(stdout, "|%5d|%7d|%11d|%3d|%12d (%3d)|%4d|", pivot,
					ch_list_24g_5g_6g[pivot], pl, phy,
					cl_calibration_pdi_to_power_offset((int8_t)eeprom[cal]),
					(int8_t)eeprom[cal], (int8_t)eeprom[temp]);
				cal ++;
				temp ++;
				fprintf(stdout, "\n");
			}
		}
	}

	num_pivots = NUM_OF_PIVOTS(NL80211_BAND_5GHZ);

	for (pl = 0; pl < MAX_POWER_LEVELS; pl++) {
		for (phy = 0; phy < MAX_ANTENNAS; phy++) {
			for (pivot = NUM_OF_PIVOTS(NL80211_BAND_2GHZ);
			     pivot < num_pivots + NUM_OF_PIVOTS(NL80211_BAND_2GHZ); pivot++) {
				fprintf(stdout, "|%5d|%7d|%11d|%3d|%12d (%3d)|%4d|", pivot,
					ch_list_24g_5g_6g[pivot], pl, phy,
					cl_calibration_pdi_to_power_offset((int8_t)eeprom[cal]),
					(int8_t)eeprom[cal], (int8_t)eeprom[temp]);
				cal ++;
				temp ++;
				fprintf(stdout, "\n");
			}
		}
	}

	num_pivots = NUM_OF_PIVOTS(NL80211_BAND_6GHZ);

	for (pl = 0; pl < MAX_POWER_LEVELS; pl++) {
		for (phy = 0; phy < MAX_ANTENNAS; phy++) {
			for (pivot = NUM_OF_PIVOTS(NL80211_BAND_2GHZ) + NUM_OF_PIVOTS(NL80211_BAND_5GHZ);
			     pivot < NUM_TOTAL_PIVOTS; pivot++) {
				fprintf(stdout, "|%5d|%7d|%11d|%3d|%12d (%3d)|%4d|", pivot,
					ch_list_24g_5g_6g[pivot], pl, phy,
					cl_calibration_pdi_to_power_offset((int8_t)eeprom[cal]),
					(int8_t)eeprom[cal], (int8_t)eeprom[temp]);
				cal ++;
				temp ++;
				fprintf(stdout, "\n");
			}
		}
	}

	fprintf(stdout, "|-----|-------|-----------|---|------------------|----|\n");

	return 0;
}

/*
 * e2p get commands
 */
static int handle_e2p_get_addr(struct nl_msg *msg, int argc, char **argv)
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

	data.cmd_id = CL_E2P_GET_ADDR;
	PARSE_INT_VALIDATE_IN_RANGE(data.addr, &argv, &argc, 0,
				    EEPROM_LAST_BYTE);
	data.len = sizeof(uint8_t);

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(e2p_addr_print, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_e2p_get_power_level(struct nl_msg *msg, int argc,
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
		printf("E2P: Invalid power level idx, max val(%u)\n",
				MAX_POWER_LEVELS - 1);
		return -EINVAL;
	}

	data.cmd_id = CL_E2P_GET_POWER_LEVEL;
	data.addr = ADDR_WIFI_VAL_PL0_E2P + data.addr;
	data.len = sizeof(uint8_t);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(e2p_one_byte_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_e2p_get_freq_offset(struct nl_msg *msg, int argc,
				      char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_E2P_GET_FREQ_OFFSET;
	data.addr = ADDR_FREQ_OFFSET_E2P;
	data.len = SIZE_FREQ_OFFSET_E2P;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(e2p_two_bytes_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_e2p_get_module_hw_type(struct nl_msg *msg, int argc,
				      char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint8_t len;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_E2P_GET_MODULE_HW_TYPE;
	data.addr = ADDR_MODULE_HW_TYPE_E2P;
	data.len = SIZE_MODULE_HW_TYPE_E2P;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(e2p_one_byte_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_e2p_get_module_hw_rev_id(struct nl_msg *msg, int argc,
				      char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint8_t len;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_E2P_GET_MODULE_HW_REVID;
	data.addr = ADDR_MODULE_HW_REVID_E2P;
	data.len = SIZE_MODULE_HW_REVID_E2P;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(e2p_module_hw_rev_id_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_e2p_get_rfic_wifi_version(struct nl_msg *msg, int argc,
				      char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_E2P_GET_RFIC_WIFI_VERSION_FOR_CALIB;
	data.addr = ADDR_RFIC_WIFI_VERSION_FOR_CALIB_E2P;
	data.len = SIZE_RFIC_WIFI_VERSION_FOR_CALIB_E2P;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(e2p_two_bytes_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_e2p_get_rfic_bt_version(struct nl_msg *msg, int argc,
				      char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_E2P_GET_RFIC_BT_VERSION_FOR_CALIB;
	data.addr = ADDR_RFIC_BT_VERSION_FOR_CALIB_E2P;
	data.len = SIZE_RFIC_BT_VERSION_FOR_CALIB_E2P;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(e2p_two_bytes_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_e2p_get_rfic_lut_version(struct nl_msg *msg, int argc,
				      char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_E2P_GET_RFIC_LUT_VERSION_FOR_CALIB;
	data.addr = ADDR_RFIC_LUT_VERSION_FOR_CALIB_E2P;
	data.len = SIZE_RFIC_LUT_VERSION_FOR_CALIB_E2P;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(e2p_one_byte_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_e2p_get_calib(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct point e2p;
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

	data.cmd_id = CL_E2P_GET_CALIB;
	PARSE_U8(data.e2p.power_level, &argv, &argc);
	PARSE_U8(data.e2p.phy, &argv, &argc);
	PARSE_U8(data.e2p.chan, &argv, &argc);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	register_handler(e2p_calib_print, NULL);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_e2p_get_table(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_E2P_GET_TABLE;
	data.addr = 0;
	data.len = EEPROM_LAST_BYTE;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(e2p_get_table_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

/*
 * e2p set commands
 */
static int handle_e2p_set_addr(struct nl_msg *msg, int argc, char **argv)
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

	data.cmd_id = CL_E2P_SET_ADDR;
	PARSE_INT_VALIDATE_IN_RANGE(data.addr, &argv, &argc, 0,
				    EEPROM_LAST_BYTE);
	data.len = sizeof(uint8_t);
	PARSE_U8(data.val, &argv, &argc);
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_e2p_set_power_level(struct nl_msg *msg, int argc,
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
	data.cmd_id = CL_E2P_SET_POWER_LEVEL;
	data.len = sizeof(uint8_t);

	if (data.addr >= MAX_POWER_LEVELS) {
		printf("E2P: Invalid power level idx, max val(%u)\n",
				MAX_POWER_LEVELS - 1);
		return -EINVAL;
	}

	data.addr = ADDR_WIFI_VAL_PL0_E2P + data.addr;

	if (data.val > 121) {
		printf("Invalid offset [1- 121] = %d\n",data.val);
		return -EINVAL;
	}

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int handle_e2p_set_freq_offset(struct nl_msg *msg, int argc,
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

	data.cmd_id = CL_E2P_SET_FREQ_OFFSET;
	data.addr = ADDR_FREQ_OFFSET_E2P;
	data.len = SIZE_FREQ_OFFSET_E2P;
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

static int handle_e2p_set_module_hw_type(struct nl_msg *msg, int argc,
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

	data.cmd_id = CL_E2P_SET_MODULE_HW_TYPE;
	data.addr = ADDR_MODULE_HW_TYPE_E2P;
	data.len = SIZE_MODULE_HW_TYPE_E2P;
	PARSE_U8(data.module_hw_type, &argv, &argc);

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_e2p_set_module_hw_rev_id(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		uint16_t addr;
		uint16_t len;
		uint8_t module_hw_rev_id[SIZE_MODULE_HW_REVID_E2P];
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_E2P_SET_MODULE_HW_REVID;
	data.addr = ADDR_MODULE_HW_REVID_E2P;
	data.len = SIZE_MODULE_HW_REVID_E2P;

	if (e2p_module_hw_rev_id_a2n(data.module_hw_rev_id, argv[1])) {
		fprintf(stderr, "invalid module hw rev_id\n");
		return -EINVAL;
	}

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_e2p_set_rfic_wifi_version(struct nl_msg *msg, int argc,
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

	data.cmd_id = CL_E2P_SET_RFIC_WIFI_VERSION_FOR_CALIB;
	data.addr = ADDR_RFIC_WIFI_VERSION_FOR_CALIB_E2P;
	data.len = SIZE_RFIC_WIFI_VERSION_FOR_CALIB_E2P;
	PARSE_U16(data.rfic_wifi_version, &argv, &argc);

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_e2p_set_rfic_bt_version(struct nl_msg *msg, int argc,
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

	data.cmd_id = CL_E2P_SET_RFIC_BT_VERSION_FOR_CALIB;
	data.addr = ADDR_RFIC_BT_VERSION_FOR_CALIB_E2P;
	data.len = SIZE_RFIC_BT_VERSION_FOR_CALIB_E2P;
	PARSE_U16(data.rfic_bt_version, &argv, &argc);

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_e2p_set_rfic_lut_version(struct nl_msg *msg, int argc,
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

	data.cmd_id = CL_E2P_SET_RFIC_LUT_VERSION_FOR_CALIB;
	data.addr = ADDR_RFIC_LUT_VERSION_FOR_CALIB_E2P;
	data.len = SIZE_RFIC_LUT_VERSION_FOR_CALIB_E2P;
	PARSE_U8(data.rfic_lut_version, &argv, &argc);

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

static int handle_e2p_set_calib(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
		struct point e2p;
	} data;

	if (!msg)
		return -ENOMEM;

	--argc;
	++argv;

	if ((argc != 4) && (argc != 5)) {
		fprintf(stderr,"%s(): wrong num of parameters %d\n",
			__func__, argc);
		return -EINVAL;
	}

	data.cmd_id = CL_E2P_SET_CALIB;
	PARSE_U8(data.e2p.power_level, &argv, &argc);
	PARSE_U8(data.e2p.phy, &argv, &argc);
	PARSE_U8(data.e2p.chan, &argv, &argc);
	PARSE_S8(data.e2p.calib.power_offset, &argv, &argc);

	if (argc)
		PARSE_S8(data.e2p.calib.temp, &argv, &argc);

	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);

	return 0;
nla_put_failure:
	return -ENOBUFS;
}

static int e2p_help_print(struct nl_msg *msg, void *arg)
{
	uint16_t len = 0;
	struct cl_msg_data *msg_data;

	cl_msg_recv(msg, (void **)&msg_data, &len);

	fprintf(stdout,"%s\n", msg_data->data);

	return 0;
}

static int handle_e2p_help(struct nl_msg *msg, int argc, char **argv)
{
	struct __attribute__((__packed__)) {
		uint8_t cmd_id;
	} data;

	if (!msg)
		return -ENOMEM;

	data.cmd_id = CL_E2P_MAX;
	NLA_PUT(msg, NL80211_ATTR_VENDOR_DATA, sizeof(data), &data);
	register_handler(e2p_help_print, NULL);

	return 0;

nla_put_failure:
	return -ENOBUFS;
}

/*
 * Handlers for e2p set commands
 */
static int handle_e2p_set_cmd(struct nl_msg *msg, int argc, char **argv)
{
	if (!strcmp(argv[0], "addr"))
		return handle_e2p_set_addr(msg, argc, argv);
	else if (!strcmp(argv[0], "power_level"))
		return handle_e2p_set_power_level(msg, argc, argv);
	else if (!strcmp(argv[0], "freq_offset"))
		return handle_e2p_set_freq_offset(msg, argc, argv);
	else if (!strcmp(argv[0], "module_hw_type"))
		return handle_e2p_set_module_hw_type(msg, argc, argv);
	else if (!strcmp(argv[0], "module_hw_rev_id"))
		return handle_e2p_set_module_hw_rev_id(msg, argc, argv);
	else if (!strcmp(argv[0], "rfic_wifi_version"))
		return handle_e2p_set_rfic_wifi_version(msg, argc, argv);
	else if (!strcmp(argv[0], "rfic_bt_version"))
		return handle_e2p_set_rfic_bt_version(msg, argc, argv);
	else if (!strcmp(argv[0], "rfic_lut_version"))
		return handle_e2p_set_rfic_lut_version(msg, argc, argv);
	else if (!strcmp(argv[0], "calib"))
		return handle_e2p_set_calib(msg, argc, argv);
	else
		printf("%s(): unknown e2p set command %s\n", __func__, *argv);

	return handle_e2p_help(msg, argc, argv);
}

/*
 * Handlers for e2p get commands
 */
static int handle_e2p_get_cmd(struct nl_msg *msg, int argc, char **argv)
{
	if (!argc) {
		fprintf(stderr,"%s(): no parameters\n",
			__func__);
		return handle_e2p_help(msg, argc, argv);
	}

	if (!strcmp(argv[0], "addr"))
		return handle_e2p_get_addr(msg, argc, argv);
	else if (!strcmp(argv[0], "power_level"))
		return handle_e2p_get_power_level(msg, argc, argv);
	else if (!strcmp(argv[0], "freq_offset"))
		return handle_e2p_get_freq_offset(msg, argc, argv);
	else if (!strcmp(argv[0], "module_hw_type"))
		return handle_e2p_get_module_hw_type(msg, argc, argv);
	else if (!strcmp(argv[0], "module_hw_rev_id"))
		return handle_e2p_get_module_hw_rev_id(msg, argc, argv);
	else if (!strcmp(argv[0], "rfic_wifi_version"))
		return handle_e2p_get_rfic_wifi_version(msg, argc, argv);
	else if (!strcmp(argv[0], "rfic_bt_version"))
		return handle_e2p_get_rfic_bt_version(msg, argc, argv);
	else if (!strcmp(argv[0], "rfic_lut_version"))
		return handle_e2p_get_rfic_lut_version(msg, argc, argv);
	else if (!strcmp(argv[0], "table"))
		return handle_e2p_get_table(msg, argc, argv);
	else if (!strcmp(argv[0], "calib"))
		return handle_e2p_get_calib(msg, argc, argv);
	else
		printf("%s(): unknown e2p get command %s\n", __func__, *argv);

	return handle_e2p_help(msg, argc, argv);
}

int handle_e2p_cmd(struct nl_msg *msg, int argc, char **argv)
{
	if (!argc) {
		fprintf(stderr,"%s(): no parameters\n",
			__func__);
		return handle_e2p_help(msg, argc, argv);
	}
	if (!strcmp(argv[0], "get")) {
		argc--;
		argv++;
		return handle_e2p_get_cmd(msg, argc, argv);
	} else if (!strcmp(argv[0], "set")) {
		argc--;
		argv++;
		return handle_e2p_set_cmd(msg, argc, argv);
	} else {
		return handle_e2p_help(msg, argc, argv);
	}

	return -EINVAL;
}

