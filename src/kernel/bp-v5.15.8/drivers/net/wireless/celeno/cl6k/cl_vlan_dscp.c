// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/if_vlan.h>
#include <linux/string.h>

#include "cl_vlan_dscp.h"
#include "cl_ip.h"
#include "cl_vif.h"
#include "cl_hw.h"
#include "cl_utils.h"

#define VLAN_DSCP_DBG(...) \
	do { \
		if (cl_hw->vlan_dscp.debug) \
			pr_debug(__VA_ARGS__); \
	} while (0)

static u8 get_vlan_pbit_up(struct cl_hw *cl_hw, u8 pbit_val, u16 vlan_id_val, u8 ap_idx)
{
	/* Get UP from VID + priority bits */
	u8 user_priority = 0;
	u8 pbit_found = 0;
	struct cl_vid_user *vid_user;
	struct cl_vlan_dhcp_params *vlan_dhcp_params =
		&cl_hw->vlan_dscp.vlan_dhcp_params[ap_idx];
	int j;

	for (j = 0; j < CL_USER_PRIO_VALS; j++) {
		vid_user = &vlan_dhcp_params->vlan_pbit_to_up[pbit_val][j];
		if (vid_user->vid == 0)
			break; /* End of vid list in this Pbit raw */

		if (vlan_id_val == vid_user->vid) {
			user_priority = vid_user->user_prio;
			pbit_found = 1;
			break;
		}
	}

	/* Use vlan_to_up mapping */
	if (pbit_found == 0)
		user_priority = vlan_dhcp_params->vlan_to_up[pbit_val];

	VLAN_DSCP_DBG("[%s] vlan_id_val=%u, pbit_val=%u, ap_idx=%u, user_priority=%u\n",
		      __func__, vlan_id_val, pbit_val, ap_idx, user_priority);

	return user_priority;
}

static u8 get_ip_user_priority(struct cl_hw *cl_hw, u8 *src_buf, u16 protocol, u8 ap_idx)
{
	/* Get UP from DSCP value */
	u8 user_priority = cl_hw->vlan_dscp.vlan_dhcp_params[ap_idx].dscp_to_up[0];
	u8 dscp_val = 0;

	if (protocol == ETH_P_IP) /* IPv4 */
		dscp_val = (*(src_buf + 1) & 0xfc) >> 2;
	else
		dscp_val = (ntohs(*(__be16 *)src_buf) >> 6) & 0x3f;

	if (dscp_val > 63) {
		VLAN_DSCP_DBG("[%s] bad DSCP value = %u\n", __func__, dscp_val);
		return user_priority;
	}

	/* Look for priority in the DSCP array */
	user_priority = cl_hw->vlan_dscp.vlan_dhcp_params[ap_idx].dscp_to_up[dscp_val];
	if (user_priority == U8_MAX) {
		/* Value wasn't found in the array. use regular parsing */
		if (protocol == ETH_P_IP) /* IPv4 */
			user_priority = (*(src_buf + 1) & 0xe0) >> 5;
		else /* IPv6 */
			user_priority = ((*src_buf) & 0x0e) >> 1;
	}

	VLAN_DSCP_DBG("[%s] dscp_val=%u, user_priority=%u, ap_idx=%u\n",
		      __func__, dscp_val, user_priority, ap_idx);

	return user_priority;
}

static int print_configuration(struct cl_hw *cl_hw, u8 ap_idx)
{
	/* Print all the configuration parameters for specific AP */
	struct cl_vlan_dscp *dscp = &cl_hw->vlan_dscp;
	struct cl_vlan_dhcp_params *param = &dscp->vlan_dhcp_params[ap_idx];
	u8 i, j;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "=====================================\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "AP %u\n", ap_idx);
	cl_snprintf(&buf, &len, &buf_size,
		    "=====================================\n");
	cl_snprintf(&buf, &len, &buf_size,
		    "enable = %s\n", dscp->enable[ap_idx] ? "True" : "False");
	cl_snprintf(&buf, &len, &buf_size,
		    "up_layer_based = %u [0-AUTO 2-VLAN 3-DSCP]\n", param->up_layer_based);
	cl_snprintf(&buf, &len, &buf_size,
		    "default_vlan_up = %u\n", param->default_vlan_up);

	cl_snprintf(&buf, &len, &buf_size, "\ndscp_to_up:\n");

	for (i = 0; i < CL_USER_DSCP_VALS; i++) {
		cl_snprintf(&buf, &len, &buf_size,
			    "dscp=%u up=%u", i, param->dscp_to_up[i]);
		if ((i + 1) % 8 == 0)
			cl_snprintf(&buf, &len, &buf_size, "\n");
		else
			cl_snprintf(&buf, &len, &buf_size, "\t");
	}

	cl_snprintf(&buf, &len, &buf_size, "\n\nvlan_to_up:\n");
	for (i = 0; i < CL_USER_PRIO_VALS; i++)
		cl_snprintf(&buf, &len, &buf_size,
			    "%3u ", param->vlan_to_up[i]);

	cl_snprintf(&buf, &len, &buf_size, "\n\nvlan_pbit_to_up:\n");
	for (i = 0; i < CL_USER_PRIO_VALS; i++) {
		cl_snprintf(&buf, &len, &buf_size, "pbit %u\t", i);
		for (j = 0; j < CL_USER_PRIO_VALS; j++)
			cl_snprintf(&buf, &len, &buf_size,
				    "v=%u,up=%u\t",
				    param->vlan_pbit_to_up[i][j].vid,
				    param->vlan_pbit_to_up[i][j].user_prio);

		cl_snprintf(&buf, &len, &buf_size, "\n");
	}

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static void read_dscp_parms_format1(struct cl_hw *cl_hw, char *buffer, u8 ap_idx)
{
	int i;
	int num_of_str;
	char *tok_ptr;
	char *mac_ptr;
	char *str_ptr[CL_USER_DSCP_VALS];
	u8 dscp;
	u8 user_prio;
	u32 val;
	struct cl_vlan_dhcp_params *vlan_dhcp_params =
		&cl_hw->vlan_dscp.vlan_dhcp_params[ap_idx];

	mac_ptr = strsep(&buffer, ";");
	for (num_of_str = 0; mac_ptr && (num_of_str < ARRAY_SIZE(str_ptr)); num_of_str++) {
		str_ptr[num_of_str] = mac_ptr;
		mac_ptr = strsep(&buffer, ";");
	}

	for (i = 0; i < num_of_str; i++) {
		val = U32_MAX;
		dscp = U8_MAX;
		user_prio = U8_MAX;

		/* Get DSCP 0-63 */
		tok_ptr = strsep(&str_ptr[i], ",");

		if (!tok_ptr) {
			pr_err("dscp_to_up0_7dec: dscp null\n");
			continue;
		}
		if (kstrtou32(tok_ptr, 10, &val) != 0) {
			pr_err("dscp_to_up0_7dec: invalid dscp (%s)\n", tok_ptr);
			continue;
		}
		if (val > 63) {
			pr_err("dscp_to_up0_7dec: dscp exceeds 63 (%u)\n", val);
			continue;
		}

		dscp = (u8)val;

		/* Get user priority */
		val = U32_MAX;
		tok_ptr = strsep(&str_ptr[i], ",");

		if (!tok_ptr) {
			pr_err("dscp_to_up0_7dec: up null\n");
			continue;
		}
		if (kstrtou32(tok_ptr, 10, &val) != 0) {
			pr_err("dscp_to_up0_7dec: invalid up (%s)\n", tok_ptr);
			continue;
		}
		if (val > 7) {
			pr_err("dscp_to_up0_7dec: up exceeds 7 (%u)\n", val);
			continue;
		}

		user_prio = (u8)val;

		/* At this point the 2 parameters are valid: dscp, and user_prio */
		if (vlan_dhcp_params->dscp_to_up[dscp] == U8_MAX)
			/* First time initialization for this dscp */
			vlan_dhcp_params->dscp_to_up[dscp] = user_prio;
		else
			pr_warn("dscp_to_up0_7dec[%u] is already set with user_prio %u."
				"Will not set it with a different user_prio %u\n",
				dscp, vlan_dhcp_params->dscp_to_up[dscp], user_prio);
	}
}

static void read_dscp_parms_format2(struct cl_hw *cl_hw, char *buffer, u8 ap_idx)
{
	int i;
	char *mac_ptr;
	u8 dscp_val;
	struct cl_vlan_dhcp_params *vlan_dhcp_params =
		&cl_hw->vlan_dscp.vlan_dhcp_params[ap_idx];

	for (i = 0, mac_ptr = strsep(&buffer, ","); mac_ptr; mac_ptr = strsep(&buffer, ","), i++) {
		if (i > (CL_USER_PRIO_VALS - 1)) {
			pr_err("dscp_to_up0_7dec: DSCP exceeds %d entries!"
			       "Remaining DSCP entries ignored\n", CL_USER_PRIO_VALS);
			break;
		}

		if (kstrtou8(mac_ptr, 10, &dscp_val) != 0) {
			pr_err("dscp_to_up0_7dec: Invalid dscp (%s)\n", mac_ptr);
			continue;
		}

		if (dscp_val > 63) {
			pr_err("dscp_to_up0_7dec: illegal dscp value %u."
			       "Converted to %u\n", dscp_val, (dscp_val & 0x3F));
			dscp_val &= 0x3F;
		}

		vlan_dhcp_params->dscp_to_up[dscp_val] = i;
	}

	if (i < (CL_USER_PRIO_VALS - 1))
		pr_warn("dscp_to_up0_7dec: only %d first DSCP entries filled in."
			"Remaining DSCP entries will remain unassigned\n", i + 1);
}

static void read_dscp_parms_from_buffer(struct cl_hw *cl_hw, char *buffer, u8 ap_idx)
{
	/*
	 * Initiate configuration per AP index by buffer by
	 * configuration parameter dscp_to_up0_7dec
	 */
	char *pch;
	struct cl_vlan_dhcp_params *vlan_dhcp_params =
		&cl_hw->vlan_dscp.vlan_dhcp_params[ap_idx];

	if (!buffer || (strlen(buffer) == 0))
		return;

	/* Initially fill with illegal dscp value */
	memset(vlan_dhcp_params->dscp_to_up, U8_MAX, CL_USER_DSCP_VALS);

	pch = strchr(buffer, ';');
	if (pch)
		/* Handle the follow format dscp_val1,up;dscp_val2,up;dscp_val3,up;... */
		read_dscp_parms_format1(cl_hw, buffer, ap_idx);
	else
		/* Handle the follow format dscp_to_up_0,dscp_to_up_1,dscp_to_up_2,... */
		read_dscp_parms_format2(cl_hw, buffer, ap_idx);
}

static void read_vlan_parms_format1(struct cl_hw *cl_hw, char *buffer, u8 ap_idx)
{
	int i, j, num_of_str;
	char *mac_ptr, *tok_ptr;
	char *str_ptr[CL_USER_PRIO_VALS * CL_USER_PRIO_VALS];
	u8 pbit, user_prio;
	u8 helper[CL_USER_PRIO_VALS];
	u16 vid;
	u32 val;
	struct cl_vlan_dhcp_params *vlan_dhcp_params = &cl_hw->vlan_dscp.vlan_dhcp_params[ap_idx];

	/*Initialize array */
	for (i = 0; i < CL_USER_PRIO_VALS; i++) {
		for (j = 0; j < CL_USER_PRIO_VALS; j++) {
			vlan_dhcp_params->vlan_pbit_to_up[i][j].vid = 0;
			vlan_dhcp_params->vlan_pbit_to_up[i][j].user_prio = 0;
		}
		helper[i] = 0;
	}

	mac_ptr = strsep(&buffer, ";");

	for (num_of_str = 0; mac_ptr && (num_of_str < ARRAY_SIZE(str_ptr)); num_of_str++) {
		str_ptr[num_of_str] = mac_ptr;
		mac_ptr = strsep(&buffer, ";");
	}

	for (i = 0; i < num_of_str; i++) {
		val = U32_MAX;
		pbit = U8_MAX;
		vid = U16_MAX;
		user_prio = U8_MAX;

		/* Get vid */
		tok_ptr = strsep(&str_ptr[i], ",");
		if (!tok_ptr) {
			pr_err("vlan_to_up0_7dec: vid null\n");
			continue;
		}
		if (kstrtou32(tok_ptr, 10, &val) != 0) {
			pr_err("vlan_to_up0_7dec: invalid vid (%s)\n", tok_ptr);
			continue;
		}
		if (val > 4095) {
			pr_err("vlan_to_up0_7dec: vid exceeds 4095 (%u)\n", val);
			continue;
		}

		vid = (u16)val;

		/* Get p-bit */
		val = U32_MAX;
		tok_ptr = strsep(&str_ptr[i], ",");

		if (!tok_ptr) {
			pr_err("vlan_to_up0_7dec: pbit null\n");
			continue;
		}
		if (kstrtou32(tok_ptr, 10, &val) != 0) {
			pr_err("vlan_to_up0_7dec: invalid pbit (%s)\n", tok_ptr);
			continue;
		}
		if (val > 7) {
			pr_err("vlan_to_up0_7dec: pbit exceeds 7 (%u)\n", val);
			continue;
		}

		pbit = (u8)val;

		/* Get user priority */
		val = U32_MAX;
		tok_ptr = strsep(&str_ptr[i], ",");

		if (!tok_ptr) {
			pr_err("vlan_to_up0_7dec: up null\n");
			continue;
		}
		if (kstrtou32(tok_ptr, 10, &val) != 0) {
			pr_err("vlan_to_up0_7dec: invalid up (%s)\n", tok_ptr);
			continue;
		}
		if (val > 7) {
			pr_err("vlan_to_up0_7dec: up exceeds 7 (%u)\n", val);
			continue;
		}

		user_prio = (u8)val;

		/* At this point all 3 parameters are valid: p-bit, vid and user_prio */
		if (vid != 0) {
			if (helper[pbit] < CL_USER_PRIO_VALS) {
				struct cl_vid_user *vid_user =
					&vlan_dhcp_params->vlan_pbit_to_up[pbit][helper[pbit]];

				vid_user->vid = vid;
				vid_user->user_prio = user_prio;
				helper[pbit]++;

				/*
				 * Mark the fact that vlan_pbit_to_up
				 * array has been initialized
				 */
				if (vlan_dhcp_params->vlan_pbit_to_up[0][0].user_prio == (u8)(-1))
					vlan_dhcp_params->vlan_pbit_to_up[0][0].user_prio = 0;
			}
		} else {
			vlan_dhcp_params->vlan_to_up[pbit] = user_prio;
		}
	}
}

static void read_vlan_parms_format2(struct cl_hw *cl_hw, char *buffer, u8 ap_idx)
{
	struct cl_vlan_dhcp_params *vlan_dhcp_params = &cl_hw->vlan_dscp.vlan_dhcp_params[ap_idx];
	int i;
	char *mac_ptr;
	u8 user_prio;

	for (i = 0, mac_ptr = strsep(&buffer, ","); mac_ptr; mac_ptr = strsep(&buffer, ","), i++) {
		if (i > (CL_USER_PRIO_VALS - 1)) {
			pr_warn("vlan_to_up0_7dec: Priority bit exceeds %d entries!"
				"Rest of Priority bits ignored\n", CL_USER_PRIO_VALS);
			break;
		}

		if (kstrtou8(mac_ptr, 10, &user_prio) != 0) {
			pr_err("dscp_to_up0_7dec: Invalid up (%s)\n", mac_ptr);
			continue;
		}

		if (user_prio > 7) {
			pr_err("vlan_to_up0_7dec[%d]: illegal user priority %u."
			       "Set it to %u\n", i, user_prio, (user_prio & 0x7));
			user_prio = (user_prio & 0x7);
		}

		vlan_dhcp_params->vlan_to_up[i] = user_prio;
	}

	if (i < (CL_USER_PRIO_VALS - 1))
		pr_warn("vlan_to_up0_7dec: only %d first priority bits entries filled in."
			"Remaining priority bits will remain unassigned\n", i + 1);
}

static void read_vlan_parms_from_buffer(struct cl_hw *cl_hw, char *buffer, u8 ap_idx)
{
	/*
	 * Initiate configuration per AP index by buffer
	 * by configuration parameter vlan_to_up0_7dec
	 */
	struct cl_vlan_dhcp_params *vlan_dhcp_params =
		&cl_hw->vlan_dscp.vlan_dhcp_params[ap_idx];
	int i;
	char *pch;

	if (!buffer || (strlen(buffer) == 0))
		return;

	/* Assume initially no change in vlan user priority */
	for (i = 0; i < CL_USER_PRIO_VALS; i++)
		vlan_dhcp_params->vlan_to_up[i] = i;

	/* Assume initially vid_pbit NVRAM parameter is not initialized */
	vlan_dhcp_params->vlan_pbit_to_up[0][0].user_prio = (u8)(-1);

	pch = strchr(buffer, ';');
	if (pch)
		/* Handle format vlan_id1,pbit,up;vlan_id2,pbit,up;vlan_id3,pbit,up.. */
		read_vlan_parms_format1(cl_hw, buffer, ap_idx);
	else
		/* Handle the follow format dscp_to_up_0,dscp_to_up_1,dscp_to_up_2,... */
		read_vlan_parms_format2(cl_hw, buffer, ap_idx);
}

static void read_layer_based_parms_from_buffer(struct cl_hw *cl_hw, char *buffer, u8 ap_idx)
{
	if (!buffer || (strlen(buffer) == 0))
		return;

	if ((strcmp(buffer, "AUTO") == 0) || (strcmp(buffer, "0") == 0))
		cl_hw->vlan_dscp.vlan_dhcp_params[ap_idx].up_layer_based = 0;
	else if ((strcmp(buffer, "VLAN") == 0) || (strcmp(buffer, "2") == 0))
		cl_hw->vlan_dscp.vlan_dhcp_params[ap_idx].up_layer_based = 2;
	else if ((strcmp(buffer, "DSCP") == 0) || (strcmp(buffer, "3") == 0))
		cl_hw->vlan_dscp.vlan_dhcp_params[ap_idx].up_layer_based = 3;
	else
		pr_err("%s: invalid input [%s]\n", __func__, buffer);
}

static void read_default_vlan_up_parms_from_buffer(struct cl_hw *cl_hw, char *buffer, u8 ap_idx)
{
	u8 default_vlan_up;

	if (!buffer || (strlen(buffer) == 0))
		return;

	if (kstrtou8(buffer, 10, &default_vlan_up) != 0) {
		pr_err("invalid param - %s\n", buffer);
		return;
	}

	if (default_vlan_up < 8)
		cl_hw->vlan_dscp.vlan_dhcp_params[ap_idx].default_vlan_up = default_vlan_up;
}

static int cl_vlan_dscp_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "qos usage:\n"
		 "-a : Set ce_dscp_to_up0_7dec0 [val]\n"
		 "-b : Set ce_vlan_to_up0_7dec0 [val]\n"
		 "-c : Set ce_up0_7_layer_based [val]\n"
		 "-d : Set ce_up0_7_default_vlan_user_prio [val]\n"
		 "-e : Enable/Disable QOS functionality [1/0]\n"
		 "-s : Show current QoS configuration\n"
		 "-v : Enable/Disable QOS debug [1/0]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

void cl_vlan_dscp_init(struct cl_hw *cl_hw)
{
	struct cl_tcv_conf *conf = cl_hw->conf;
	u8 ap_idx;

	for (ap_idx = 0; ap_idx < MAX_BSS_NUM; ap_idx++) {
		cl_hw->vlan_dscp.enable[ap_idx] = conf->ce_dscp_vlan_enable[ap_idx];
		cl_hw->vlan_dscp.vlan_dhcp_params[ap_idx].up_layer_based =
			conf->ce_up0_7_layer_based[ap_idx];
		cl_hw->vlan_dscp.vlan_dhcp_params[ap_idx].default_vlan_up =
			conf->ce_up0_7_default_vlan_user_prio[ap_idx];
	}

	/* Ce_dscp_to_up0_7decX */
	read_dscp_parms_from_buffer(cl_hw, conf->ce_dscp_to_up0_7dec0, 0);
	read_dscp_parms_from_buffer(cl_hw, conf->ce_dscp_to_up0_7dec1, 1);
	read_dscp_parms_from_buffer(cl_hw, conf->ce_dscp_to_up0_7dec2, 2);
	read_dscp_parms_from_buffer(cl_hw, conf->ce_dscp_to_up0_7dec3, 3);
	read_dscp_parms_from_buffer(cl_hw, conf->ce_dscp_to_up0_7dec4, 4);
	read_dscp_parms_from_buffer(cl_hw, conf->ce_dscp_to_up0_7dec5, 5);
	read_dscp_parms_from_buffer(cl_hw, conf->ce_dscp_to_up0_7dec6, 6);
	read_dscp_parms_from_buffer(cl_hw, conf->ce_dscp_to_up0_7dec7, 7);

	/* Ce_vlan_to_up0_7decX */
	read_vlan_parms_from_buffer(cl_hw, conf->ce_vlan_to_up0_7dec0, 0);
	read_vlan_parms_from_buffer(cl_hw, conf->ce_vlan_to_up0_7dec1, 1);
	read_vlan_parms_from_buffer(cl_hw, conf->ce_vlan_to_up0_7dec2, 2);
	read_vlan_parms_from_buffer(cl_hw, conf->ce_vlan_to_up0_7dec3, 3);
	read_vlan_parms_from_buffer(cl_hw, conf->ce_vlan_to_up0_7dec4, 4);
	read_vlan_parms_from_buffer(cl_hw, conf->ce_vlan_to_up0_7dec5, 5);
	read_vlan_parms_from_buffer(cl_hw, conf->ce_vlan_to_up0_7dec6, 6);
	read_vlan_parms_from_buffer(cl_hw, conf->ce_vlan_to_up0_7dec7, 7);
}

bool cl_vlan_dscp_is_enabled(struct cl_hw *cl_hw, struct cl_vif *cl_vif)
{
	return cl_hw->vlan_dscp.enable[cl_vif->vif_index];
}

u8 cl_vlan_dscp_check_ether_type(struct cl_hw *cl_hw, struct sk_buff *skb, u8 ap_idx)
{
	/* Calculate the user priority according to the celeno logic and configuration */
	struct cl_vlan_dhcp_params *vlan_dhcp_params = &cl_hw->vlan_dscp.vlan_dhcp_params[ap_idx];
	u8 user_priority = 0;
	u8 *src_buf = skb->data;

	/* VLAN TCI: 3-bit UP + 1-bit CFI + 12-bit VLAN ID */
	u16 vlan_id_val = 0;
	u8 pbit_val = 0;
	u16 ether_type = (src_buf[12] << 8) | src_buf[13];

	/* Skip the Ethernet Header.*/
	src_buf += ETH_HLEN;

	/*
	 * handel LLC packets
	 * if it's a LLC packet we should move the data pointer and to
	 * get the ether type from the llc header add support to other LLC
	 */
	if (ether_type <= 1500) {
		/* 802.3, 802.3 LLC
		 * DestMAC(6) + SrcMAC(6) + Length(2) +
		 * DSAP(1) + SSAP(1) + Control(1) +
		 * if the DSAP = 0xAA, SSAP=0xAA, Contorl = 0x03, it has a 5-bytes SNAP header.
		 * => + SNAP (5, OriginationID(3) + etherType(2))
		 */
		if (PKT_HAS_LLC_HDR(src_buf)) {
			/* Get new ether_type */
			ether_type = (src_buf[6] << 8) | src_buf[7];
			src_buf += LENGTH_LLC + LENGTH_SSNAP; /* Skip this LLC/SNAP header */
		}
	}

	if (ether_type == ETH_P_8021Q || skb->vlan_tci != 0) {
		if (skb->vlan_tci != 0) {
			pbit_val = (skb->vlan_tci >> VLAN_PRIO_SHIFT);
			vlan_id_val = skb->vlan_tci & VLAN_VID_MASK;
		} else {
			struct vlan_hdr *vhdr = (struct vlan_hdr *)src_buf;

			/* VLAN tag: 3-bit UP + 1-bit CFI + 12-bit VLAN ID */
			vlan_id_val = ntohs(vhdr->h_vlan_TCI) & VLAN_VID_MASK;
			ether_type = ntohs(vhdr->h_vlan_encapsulated_proto);
			pbit_val = ((ntohs(vhdr->h_vlan_TCI) & VLAN_PRIO_MASK) >> VLAN_PRIO_SHIFT);
		}

		/* Only use VLAN tag */
		if (vlan_dhcp_params->up_layer_based != CL_UP_BY_L3) {
			user_priority = get_vlan_pbit_up(cl_hw, pbit_val, vlan_id_val, ap_idx);
			goto out;
		}

		if (ether_type == ETH_P_8021Q)
			src_buf += sizeof(struct vlan_hdr); /* Skip the VLAN Header.*/
	}

	ether_type = ntohs(*(__be16 *)(src_buf - 2));

	if (vlan_dhcp_params->up_layer_based != CL_UP_BY_L2) {
		/*
		 * GET user priority by DSCP
		 * If it is an IP packet and up_layer_based == 3 (DSCP),
		 * we will check it's DSCP parameter
		 */
		if (ether_type == ETH_P_IP || ether_type == ETH_P_IPV6) {
			u8 version = (*src_buf & 0xf0);

			if ((version == IP_V_IPV6 || version == IP_V_IPV4))
				user_priority = get_ip_user_priority(cl_hw, src_buf,
								     ether_type, ap_idx);
		}
	}

out:
	VLAN_DSCP_DBG("ether_type=0x%X, vlan_tci=0x%X, pbit_val=%u, vlan_id_val=%u, priority=%u\n",
		      ether_type, skb->vlan_tci, pbit_val, vlan_id_val, user_priority);

	return user_priority;
}

int cl_vlan_dscp_cli(struct cl_hw *cl_hw, struct cl_vif *cl_vif, char *data)
{
	u8 ap_idx = cl_vif->vif_index;
	char *payload_start = data + 3;

	if (!(payload_start && strlen(payload_start)))
		return cl_vlan_dscp_cli_help(cl_hw);

	if (payload_start[strlen(payload_start) - 1] == ' ')
		payload_start[strlen(payload_start) - 1] = '\0';

	if (!strncmp(data, "-a.", 3)) {
		read_dscp_parms_from_buffer(cl_hw, payload_start, ap_idx);
	} else if (!strncmp(data, "-b.", 3)) {
		read_vlan_parms_from_buffer(cl_hw, payload_start, ap_idx);
	} else if (!strncmp(data, "-c.", 3)) {
		read_layer_based_parms_from_buffer(cl_hw, payload_start, ap_idx);
	} else if (!strncmp(data, "-d.", 3)) {
		read_default_vlan_up_parms_from_buffer(cl_hw, payload_start, ap_idx);
	} else if (!strncmp(data, "-e.", 3)) {
		if (kstrtobool(payload_start, &cl_hw->vlan_dscp.enable[ap_idx]) != 0)
			pr_err("invalid data - %s\n", payload_start);
	} else if (!strncmp(data, "-v.", 3)) {
		if (kstrtobool(payload_start, &cl_hw->vlan_dscp.debug) != 0)
			pr_err("invalid data - %s\n", payload_start);
	} else if (!strncmp(data, "-s.?", 4)) {
		return print_configuration(cl_hw, ap_idx);
	}

	pr_err("%s(): error in parameters\n", __func__);
	return cl_vlan_dscp_cli_help(cl_hw);
}
