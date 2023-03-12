#ifndef __ATE_H
#define __ATE_H

// All the below must be aligned with kernel

struct ate_stats {
	uint32_t tx_bw20;
	uint32_t tx_bw40;
	uint32_t tx_bw80;
	uint32_t tx_bw160;
	uint32_t rx_bw20;
	uint32_t rx_bw40;
	uint32_t rx_bw80;
	uint32_t rx_bw160;
	uint32_t fcs_err;
	uint32_t phy_err;
	uint32_t delimiter_err;
	uint32_t rx_succsess;
	int8_t rssi0;
	int8_t rssi1;
	int8_t rssi2;
	int8_t rssi3;
	int8_t rssi4;
	int8_t rssi5;
};

enum cl_ate_cmd {
	CL_ATE_RESET,
	CL_ATE_MODE,
	CL_ATE_BW,
	CL_ATE_MCS,
	CL_ATE_NSS,
	CL_ATE_GI,
	CL_ATE_LTF,
	CL_ATE_LDPC,
	CL_ATE_CHANNEL,
	CL_ATE_ANT,
	CL_ATE_MULTI_ANT,
	CL_ATE_PACKET_LEN,
	CL_ATE_FREQ_OFFSET,
	CL_ATE_STAT_RESET,
	CL_ATE_STAT,
	CL_ATE_POWER,
	CL_ATE_POWER_OFFSET,
	CL_ATE_TX_START,
	CL_ATE_TX_CONTINUOUS,
	CL_ATE_TX_AGG,
	CL_ATE_STOP,
	CL_ATE_DUMMY_STA,

	CL_ATE_MAX
};
#endif // __ATE_H
