#! /bin/sh

cl_install_dir=${cl_install_dir-"/cl6k"}

PAL_B2B_UART_DIV=14
PAL_B2B_UART_FRAC=13

#Baudrate 921600
# divider = 640000000 / (921600 * 16 * 1)  = 43,4
# div = 43 => 0x2B
# frac 0,4 * 16 = 6,4 => 0x6
REAL_UART_DIV_L=0x2B
REAL_UART_FRAC=0x06

#Baudrate 115200
# divider = 640000000 / (115200 * 16 * 1)  = 347,2
# div = 347 => 0x15b
# frac 0,2 * 16 = 3,2 => 0x3
REAL_LOGGER_UART_DIV_M=0x01
REAL_LOGGER_UART_DIV_L=0x5B
REAL_LOGGER_UART_FRAC=0x03

set_uart_conf_palladium_b2b()
{
	local chip_idx=$1

	NVS chip${chip_idx}_bt pf_cfg_pf_uart_cfg_uart_div_l 0 $PAL_B2B_UART_DIV
	NVS chip${chip_idx}_bt pf_cfg_pf_uart_cfg_uart_frac 0 $PAL_B2B_UART_FRAC
	NVS chip${chip_idx}_bt pf_cfg_pf_logger_uart_cfg_logger_uart_div_l 0 $PAL_B2B_UART_DIV
	NVS chip${chip_idx}_bt pf_cfg_pf_logger_uart_cfg_logger_uart_frac 0 $PAL_B2B_UART_FRAC
}

set_uart_conf_real_chip()
{
	local chip_idx=$1

	NVS chip${chip_idx}_bt pf_cfg_pf_uart_cfg_uart_div_l 0 $REAL_UART_DIV_L
	NVS chip${chip_idx}_bt pf_cfg_pf_uart_cfg_uart_frac 0 $REAL_UART_FRAC
	NVS chip${chip_idx}_bt pf_cfg_pf_logger_uart_cfg_logger_uart_div_l 0 $REAL_LOGGER_UART_DIV_L
	NVS chip${chip_idx}_bt pf_cfg_pf_logger_uart_cfg_logger_uart_div_m 0 $REAL_LOGGER_UART_DIV_M
	NVS chip${chip_idx}_bt pf_cfg_pf_logger_uart_cfg_logger_uart_frac 0 $REAL_LOGGER_UART_FRAC

}

do_print_usage()
{
	cat <<-EOF
	Usage:
		bt_set_conf.sh command [flag]

		Commands:
		protium_usb - configure bt over usb for Protium
		palladium_usb - configure bt over usb for Pallaldium
		palladium_b2b - configure bt over UART for Paladium b2b
		tester_behaviour - enable tester behaviour
		alaska - configure alaska board
		twin_peaks - configure twin_peaks board
		rf_twin_peaks - configure rf twin_peaks board
		debug_hooks - enable BT debug counters
		set_agc - enable AGC
	EOF
}

NVG()
{
	file=$1
	key=$2
	default=$3
	val=`$cl_install_dir/scripts/nvram_get $file $key`
	if [ -n "$val" ]; then
		echo $val
	else
		echo $default
	fi
}

NVS()
{
	file=$1
	key=$2
	default=$3
	value_set=$4
	value_get="$(NVG $file $key $default)"

	if [ "$value_get" != "$value_set" ]; then
		`$cl_install_dir/scripts/nvram_set $file $key $value_set`
	fi
}

PF_GEN_CFG=(0x00 0x00 0x00 0x01)
LOCAL_FEA=(0xFF 0xFF 0xFF 0xFE 0x9B 0xFF 0x79 0x83)

# enable bt 
# chip idx 0/1
# bt_mode 0 - disable, 1 - bt over uart, 2 - bt over usb
bt_enable()
{
	local chip_idx=$1
	local bt_mode=$2

	NVS chip$chip_idx ce_bt_mode 0 $bt_mode
}

calib_disable()
{
	local chip_idx=$1
	local bt_mode=$2

	NVS chip$chip_idx ci_rf_calib_dis 0 $bt_mode
}

rf_bt_init()
{
	local chip_idx=$1
	local bt_mode=$2

	NVS chip$chip_idx ci_rf_bt_init 0 $bt_mode
}

zero_if_en()
{
	local chip_idx=$1
	local mode=$2

	NVS chip$chip_idx ci_rf_bt_zero_if_en 0 $mode
}


rf_init_disable()
{
	local chip_idx=$1
	local val=$2

	NVS chip$chip_idx ci_rf_init_dis 0 $val
}


phy_load_bootdrv_enable()
{
	local chip_idx=$1

	NVS chip$chip_idx ci_phy_load_bootdrv 0 1
}

phy_mac_addr_set()
{
	local chip_idx=$1
	local mac=$2

	NVS chip$chip_idx ce_phys_mac_addr 0 $mac
}

# enable fast boot (skip classic encryption init)
# PF_FAST_BOOT_ENABLED           ((bt_config.pf_cfg.pf_gen_cfg) & BIT0)
fastboot_enable()
{
	local -n arr=$1 

	FAST_BOOT_ENABLED=0x01
	arr[0]=$((${arr[0]} | $FAST_BOOT_ENABLED))
}

# PF_RF_BYPASS_ENABLED           ((bt_config.pf_cfg.pf_gen_cfg) & BIT1)
rf_bypass_enable()
{
	local -n arr=$1

	FR_BYPASS_ENABLED=0x02
	arr[0]=$((${arr[0]} | $FR_BYPASS_ENABLED))
}

# PF_AGC_ENABLED              (((bt_config.pf_cfg.pf_gen_cfg) & BIT2) >> 2)
pf_agc_enable()
{
	local -n arr=$1

	PF_AGC_ENABLED=0x04
	arr[0]=$((${arr[0]} | $PF_AGC_ENABLED))
}

pf_agc_disable()
{
	local -n arr=$1

	FRIC_SW_OVERWRITE_DISABLE=0xFB
	arr[0]=$((${arr[0]} & $FRIC_SW_OVERWRITE_DISABLE))
}

# PF_RF_ENABLED (bt_config.pf_cfg.pf_gen_cfg) & BIT3)
pf_rf_enable_enable()
{
	local -n arr=$1

	PF_RF_ENABLED=0x08
	arr[0]=$((${arr[0]} | $PF_RF_ENABLED))
}

# PF_RFIC_NEAR_ZERO_IF        (((bt_config.pf_cfg.pf_gen_cfg) & BIT4) >> 4)
near_zero_if_enable()
{
	local -n arr=$1

	NEAR_ZERO_IF_ENABLED=0x10
	arr[0]=$((${arr[0]} | $NEAR_ZERO_IF_ENABLED))
}

pf_gen_cfg_apply()
{
	local chip_idx=$1
	local -n PF_GEN_CFG_1=$2
	data=$(printf "%02x:%02x:%02x:%02x" ${PF_GEN_CFG_1[0]} ${PF_GEN_CFG_1[1]} ${PF_GEN_CFG_1[2]} ${PF_GEN_CFG_1[3]})
	NVS chip${chip_idx}_bt pf_cfg_pf_gen_cfg 0 $data
}

pf_gen_cfg_get()
{
	local chip_idx=$1
	local -n gen_cfg=$2

	str="$(NVG chip${chip_idx}_bt pf_cfg_pf_gen_cfg 0)"
	IFS=':' read -r -a array <<< "$str"
	str2hex array gen_cfg
}

bredr_disable()
{
	local -n arr=$1 

	arr[4]=$((${arr[4]} | 0x20))
}


local_fea_apply()
{
	local chip_idx=$1
	local -n local_fea=$2
	data=$(printf "%02x:%02x:%02x:%02x:%02x:%02x:%02x:%02x" ${local_fea[0]} ${local_fea[1]} ${local_fea[2]} ${local_fea[3]} ${local_fea[4]} ${local_fea[5]} ${local_fea[6]} ${local_fea[7]})
	NVS chip${chip_idx}_bt rw_data_local_fea 0 $data
}

#enabling testter behaviour
# + 003F0267
# - 00030267
# 31-24 23-16 15-8 7-0 
#       23-20 19-16
#define CONFIG_FORCE_CE_LEN_MAX               ((bt_config.rw_data.general_flags & BIT17) >> 17)
#define CONFIG_TESTER_BEHAVIOUR_ENABLE        ((bt_config.rw_data.general_flags & BIT18) >> 18)
#define CONFIG_AUTO_DATA_ENABLE               ((bt_config.rw_data.general_flags & BIT19) >> 19)
#define CONFIG_ISOC_DATA_TRANSFER_STUB_ENABLE ((bt_config.rw_data.general_flags & BIT20) >> 20)
#define CONFIG_THROUGHPUT_CALC_ENABLE         ((bt_config.rw_data.general_flags & BIT21) >> 21)
#define CONFIG_ENABLE_DEBUG_HOOKS             ((bt_config.rw_data.general_flags & BIT22) >> 22)
GENERAL_FLAGS=(0x67 0x02 0x03 0x0)

debug_hooks_enable()
{
	local -n arr=$1

	DEBUG_HOOKS_ENABLE=0x40
	arr[2]=$((${arr[2]} | $DEBUG_HOOKS_ENABLE))
}

throughput_calc_enable()
{
	local -n arr=$1 

	THROUGHPUT_CALC_ENABLE=0x20
	arr[2]=$((${arr[2]} | $THROUGHPUT_CALC_ENABLE))
}

isoc_data_transfer_sub_enable()
{
	local -n arr=$1 

	ISOC_DATA_TRANSFER_STUB_ENABLE=0x10
	arr[2]=$((${arr[2]} | $ISOC_DATA_TRANSFER_STUB_ENABLE))
}

auto_data_enable()
{
	local -n arr=$1 

	AUTO_DATA_ENABLE=0x08
	arr[2]=$((${arr[2]} | $AUTO_DATA_ENABLE))
}

tester_behaviour_enable()
{
	local -n arr=$1 

	TESTER_BEHAVIOUR_ENABLE=0x04
	arr[2]=$((${arr[2]} | $TESTER_BEHAVIOUR_ENABLE))
}

general_flags_apply()
{
	local chip_idx=$1
	local -n local_fea=$2
	data=$(printf "%02x:%02x:%02x:%02x" ${local_fea[0]} ${local_fea[1]} ${local_fea[2]} ${local_fea[3]})

	NVS chip${chip_idx}_bt rw_data_general_flags 0 $data
}

set_agc()
{

	local chip_idx=$1
	pf_gen_cfg_get  ${chip_idx} PF_GEN_CFG
	near_zero_if_enable PF_GEN_CFG
	pf_agc_enable PF_GEN_CFG
	pf_gen_cfg_apply ${chip_idx} PF_GEN_CFG
	zero_if_en ${chip_idx} 0

MODEM_REG_ADDR=(FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF
		FFFF)


MODEM_REG_VALUE=(00000001
		00000001
		00000000
		00000000
		00000000
		00000000
		00000000
		00000000
		00000000
		00000000
		00000000
		00000000
		00000000
		00000000
		00000000
		00000000
		00000000
		00000000
		00000000
		00000000
		00000000
		00000000
		00000000
		00000000
		00000000
		00000000)

	reg=""
	val=""
	j=0

	reg=($(grep -r "^0x.*" $cl_install_dir/firmware/bt_agc | awk -F'[x, \t]' '{print $2;}'))
	val=($(grep -r "^0x.*" $cl_install_dir/firmware/bt_agc | awk -F'[x, \t]' '{print $5;}'))

	for i in "${reg[@]}"
	do
		k=0
		while [ "${MODEM_REG_ADDR[$k]}" != "FFFF" ] && [ "${MODEM_REG_ADDR[$k]}" != "$i" ]; do
			k=$(( k + 1 ))
		done
		MODEM_REG_ADDR[$k]=$i
		MODEM_REG_VALUE[$k]=${val[$j]}
		j=$(( j + 1 ))
	done

	reg=""
	val=""
	for addr in "${MODEM_REG_ADDR[@]}"
	do
		if [ -z "$reg" ];
		then reg="${addr:2:2}:${addr:0:2}";
		else reg="$reg:${addr:2:2}:${addr:0:2}";
		fi
	done

	for data in "${MODEM_REG_VALUE[@]}"
	do
		if [ -z "$val" ];
		then val="${data:6:2}:${data:4:2}:${data:2:2}:${data:0:2}"
		else val="$val:${data:6:2}:${data:4:2}:${data:2:2}:${data:0:2}"
		fi
	done

	NVS chip${chip_idx}_bt rw_data_ram_modem_reg_addr 0 $reg
	NVS chip${chip_idx}_bt rw_data_ram_modem_reg_value 0 $val
}

general_flags_read()
{
	local chip_idx=$1
	local -n general_flags=$2

	str="$(NVG chip${chip_idx}_bt rw_data_general_flags 0)"

	IFS=':' read -r -a array <<< "$str"

	str2hex array general_flags
}

# parce configuration string
# assign new value only if it's not empty
str2hex()
{
	local -n str=$1
	local -n arr=$2
	local count=0
	local empty=1
	for i in "${str[@]}"
	do
		str[$count]=$((16#$i))
		if [ ${str[$count]} -ne "0" ]; then
			empty=0
		fi
		count=$count+1;
	done

	if [ $empty -eq 0 ]; then
		arr=("${str[@]}")
	fi
}

set_debug_hooks()
{
	local chip_idx=$1

	general_flags_read ${chip_idx} GENERAL_FLAGS
	debug_hooks_enable GENERAL_FLAGS
	general_flags_apply ${chip_idx} GENERAL_FLAGS
}

set_test_behaviour()
{
	local chip_idx=$1

	general_flags_read ${chip_idx} GENERAL_FLAGS
	throughput_calc_enable GENERAL_FLAGS
	isoc_data_transfer_sub_enable GENERAL_FLAGS
	auto_data_enable GENERAL_FLAGS
	tester_behaviour_enable GENERAL_FLAGS
	general_flags_apply ${chip_idx} GENERAL_FLAGS

	NVS chip${chip_idx}_bt rw_data_ll_isoc_bis_data_rate_allocation 0 0x64
	NVS chip${chip_idx}_bt rw_data_ll_isoc_cis_data_rate_allocation 0 0x64
	NVS chip${chip_idx}_bt rw_data_ll_ext_adv_max_data_len_supported 0 0x200
	NVS chip${chip_idx}_bt rw_data_bt_fw_le_scheduler_buffers 0 0x32
	NVS chip${chip_idx}_bt rw_data_ll_iso_max_tx_sdu_size 0 0x3EC
	NVS chip${chip_idx}_bt rw_data_ll_iso_max_rx_sdu_size 0 0x3EC
	NVS chip${chip_idx}_bt rw_data_ll_max_no_of_big_supported 0 1
	NVS chip${chip_idx}_bt rw_data_ll_max_no_of_bis_supported 0 1
	NVS chip${chip_idx}_bt rw_data_ll_max_no_of_bis_sync_supported 0 1
	NVS chip${chip_idx}_bt rw_data_ll_max_no_of_cis_supported 0 1
}

default_rfic_reg_val()
{
	local chip_idx=$1

	#RFIC delay BLE
	NVS chip${chip_idx}_bt radio_specific_params_rx_low_config_reg_val_1m 0x0800 0x000
	NVS chip${chip_idx}_bt radio_specific_params_rx_low_config_reg_val_2m 0x1000 0x0000
	NVS chip${chip_idx}_bt radio_specific_params_rx_low_config_reg_val_lr 0x0800 0x000

	#RFIC delay BR/EDR
	NVS chip${chip_idx}_bt rw_data_ram_bredr_low_if_rx_reg_val 0x0800 0x000
}

protium_usb_conf()
{
	fastboot_enable PF_GEN_CFG
	pf_agc_disable PF_GEN_CFG
	pf_gen_cfg_apply 0 PF_GEN_CFG
	pf_gen_cfg_apply 1 PF_GEN_CFG
	bredr_disable LOCAL_FEA
	local_fea_apply 0 LOCAL_FEA
	local_fea_apply 1 LOCAL_FEA

	# Enable BT over USB
	bt_enable 0 2
	bt_enable 1 2

	phy_load_bootdrv_enable 0
	phy_load_bootdrv_enable 1
	phy_mac_addr_set 0 "00:1c:51:11:22:33"
	phy_mac_addr_set 1 "00:1c:51:11:22:34"

	default_rfic_reg_val 0
	default_rfic_reg_val 1
}

palladium_usb_conf()
{
	protium_usb_conf
}

palladium_b2b_pcie_conf()
{
	fastboot_enable PF_GEN_CFG
	pf_agc_disable PF_GEN_CFG
	pf_gen_cfg_apply 0 PF_GEN_CFG
	pf_gen_cfg_apply 1 PF_GEN_CFG

	bredr_disable LOCAL_FEA
	local_fea_apply 0 LOCAL_FEA
	local_fea_apply 1 LOCAL_FEA

	set_uart_conf_palladium_b2b 0
	set_uart_conf_palladium_b2b 1

	# Enable BT over UART
	bt_enable 0 1
	bt_enable 1 1

	phy_load_bootdrv_enable 0
	phy_load_bootdrv_enable 1
	phy_mac_addr_set 0 "00:1c:51:11:22:33"
	phy_mac_addr_set 1 "00:1c:51:11:22:34"

	default_rfic_reg_val 0
	default_rfic_reg_val 1
}

alaska_conf()
{
	local chip_idx=$1

	# Enable BT over UART
	bt_enable ${chip_idx} 1

	fastboot_enable PF_GEN_CFG
	pf_gen_cfg_apply ${chip_idx} PF_GEN_CFG

	set_uart_conf_real_chip ${chip_idx}

	#RFIC delay BLE
	NVS chip${chip_idx}_bt radio_specific_params_rx_low_config_reg_val_1m 0 0x0800
	NVS chip${chip_idx}_bt radio_specific_params_rx_low_config_reg_val_2m 0 0x1000
	NVS chip${chip_idx}_bt radio_specific_params_rx_low_config_reg_val_lr 0 0x0800

	#RFIC delay BR/EDR
	NVS chip${chip_idx}_bt rw_data_ram_bredr_low_if_rx_reg_val 0 0x0800

	set_debug_hooks ${chip_idx}
}

rf_twin_peaks_conf()
{
	local chip_idx=$1

	bredr_disable LOCAL_FEA
	local_fea_apply ${chip_idx} LOCAL_FEA

	calib_disable ${chip_idx} 1
	# Enable BT over UART
	bt_enable ${chip_idx} 1
	rf_init_disable ${chip_idx} 1
	rf_bt_init ${chip_idx} 1
	zero_if_en ${chip_idx} 1

	fastboot_enable PF_GEN_CFG
	pf_rf_enable_enable PF_GEN_CFG
	pf_gen_cfg_apply ${chip_idx} PF_GEN_CFG

	set_uart_conf_real_chip ${chip_idx}

	default_rfic_reg_val ${chip_idx}

	set_debug_hooks ${chip_idx}
}

twin_peaks_conf()
{
	local chip_idx=$1

	bredr_disable LOCAL_FEA
	local_fea_apply ${chip_idx} LOCAL_FEA

	# Enable BT over UART
	bt_enable ${chip_idx} 1
	rf_init_disable ${chip_idx} 1

	fastboot_enable PF_GEN_CFG
	rf_bypass_enable PF_GEN_CFG
	pf_gen_cfg_apply ${chip_idx} PF_GEN_CFG

	set_uart_conf_real_chip ${chip_idx}

	default_rfic_reg_val ${chip_idx}

	set_debug_hooks ${chip_idx}
}


#####################################################################
# MAIN
#####################################################################

if [[ -z $1 ]]; then
	do_print_usage
	exit 0
fi
# parse command line parameters
while [[ $# -ge 1 ]]
do
	case "$1" in
		protium_usb)
			echo "start configuration for protium board with USB"
			protium_usb_conf
			break 2
		;;
		palladium_usb)
			echo "start configuration for palladium board with USB"
			palladium_usb_conf
			break 2
		;;
		palladium_b2b)
			echo "start configuration for palladium board with PCIe"
			palladium_b2b_pcie_conf
			break 2
		;;
		tester_behaviour)
			echo "Enable tester behaviour"
			set_test_behaviour 0
			set_test_behaviour 1
			break 2
		;;
		debug_hooks)
			set_debug_hooks 0
			set_debug_hooks 1
			break 2
		;;
		alaska)
			echo "start configuration for Alaska board"
			alaska_conf 0
			alaska_conf 1
			break 2
		;;
		twin_peaks)
			echo "start configuration for twin peaks board"
			twin_peaks_conf 0
			twin_peaks_conf 1
			break 2
		;;
		set_agc)
			set_agc 0
			set_agc 1
			break 2
		;;
		rf_twin_peaks)
			echo "start configuration for rf twin peaks board"
			rf_twin_peaks_conf 0
			rf_twin_peaks_conf 1
			break 2
		;;
		*)
			do_print_usage
			exit 0
		;;
	esac
	shift
done
echo "Finish configuration"
