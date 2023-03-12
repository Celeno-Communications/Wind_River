#ifndef CL_NL_SHARED_H
#define CL_NL_SHARED_H

// All the below must be aligned with kernel
#define CELENO_OUI 0x001c51
#define NL80211_WIPHY_NAME_MAXLEN 64

#define CL_NL_MAX_PAYLOAD 512
struct cl_nl_event {
	char event_id;
	char tcv_idx;
	char data[CL_NL_MAX_PAYLOAD];
};

enum cl_nl_event_id {
	CL_NL_EVENT_ID_CH_SWITCH,
	CL_NL_EVENT_ID_CO_LOCATE_UPDATE,
	CL_NL_EVENT_ID_DISASSOCIATE,
	CL_NL_EVENT_ID_IF_ADD,

	CL_NL_EVENT_ID_MAX
};

enum cl_vndr_events {
	CL_VENDOR_EVENT_ASYNC,

	CL_VENDOR_EVENT_LAST
};

enum cl_vndr_cmds {
	CL_VNDR_CMDS_UNSPEC,
	CL_VNDR_CMDS_CECLI,
	CL_VNDR_CMDS_E2P,
	CL_VNDR_CMDS_OTP,
	CL_VNDR_CMDS_ATE,
	CL_VNDR_CMDS_HELP,
	CL_VNDR_CMDS_LAST
};

enum cl_vndr_nlattrs {
	CL_VENDOR_ATTR_UNSPEC,
	CL_VENDOR_ATTR_REPLY,
	CL_VENDOR_ATTR_DATA,
	CL_VENDOR_ATTR_LEN,

	NUM_CL_VENDOR_ATTR,
	MAX_CL_VENDOR_ATTR = NUM_CL_VENDOR_ATTR - 1
};


#endif // CL_NL_SHARED_H
