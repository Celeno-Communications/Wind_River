#! /bin/sh

ORIG_PATH="$PATH"
cl_install_dir=${cl_install_dir-"/cl6k"}
cl_cfg_dir=${cl_cfg_dir-"/nvram/cl6k"}

source $cl_install_dir/scripts/hp.config
source $cl_install_dir/scripts/usleep.sh

test_directory_exists()
{
	if [ -z "${1}" ]; then
		echo no parameter given
		return 1
	fi
	dir_under_test=$1
	if [ ! -d $dir_under_test ]; then
		echo "Directory [$dir_under_test] does not exists"
		return 1
	fi

	return 0
}

test_file_exists()
{
	if [ -z "${1}" ]; then
		echo no parameter given
		return 1
	fi
	file_under_test=$1
	if [ ! -f $file_under_test -a ! -c $file_under_test ]; then
		echo "File [$file_under_test] does not exists"
		return 1
	fi

	return 0
}

is_auth_encrypt_combination_valid()
{
	local combination_valid="1"
	case "$ha_auth_mode" in
		OPEN)
			if [ "${ha_encrypt_type}" != "WEP" -a "${ha_encrypt_type}" != "NONE" ]; then
				combination_valid="0"
			fi
			;;
		SHARED|WEPAUTO)
			if [ "${ha_encrypt_type}" != "WEP" ]; then
				combination_valid="0"
			fi
			;;
		WPAPSK|WPA)
			if [ "${ha_encrypt_type}" != "TKIP" ]; then
				combination_valid="0"
			fi
			;;
		WPAPSKWPA2PSK|WPAWPA2)
			if [ "${ha_encrypt_type}" != "TKIPAES" ]; then
				combination_valid="0"
			fi
			;;
		WPA2PSK|WPA2|WPA3|WPA3SAE|WPA3SAE-MIXED)
			if [ "${ha_encrypt_type}" != "AES" ]; then
				combination_valid="0"
			fi
			;;
		*)
			combination_valid="0"
			;;
	esac
	echo $combination_valid
}

do_print_usage()
{
	cat <<-EOF
	Usage:
		ce_host.sh command [flag]

		Commands:
		production - start in production mode
		start - start driver and interfaces
		stop - stop driver and interfaces
		reload - stop and start the drivers in the same channel/BW and DFS state
		reload_hostapd - recreate hostapd.conf and apply
		br0 - setup default bridge
		fw_test - run FW test [lmac/umac/smac/lsmac/lumac/sumac/lsumac] [test binary name] [bootdrv - optional]
		bringup_dsp - run dsp bring up tests [test value] [phy number 0/1] mode [full test = 0, only dmem block = 1]
		version - Print host package version
		create_ini - create /var/run/cl6k_chipX.ini file
	EOF
}

stop_wsc()
{
	# kill wsc_save and hostapd_cli
	local wlan_int=$1

	if [ -f /tmp/wsc_save-${wlan_int}.pid ]
	then
		local pid=$(cat /tmp/wsc_save-${wlan_int}.pid)
		local cli_pid=$(ps | grep hostapd_cli | grep ${wlan_int} | grep -v grep | awk '{ print $1 }')

		[ -n $cli_pid ] && kill $cli_pid
		[ -n $pid ] && kill $pid

		rm -f /tmp/wsc_save-${wlan_int}.pid
	fi
}

get_scan_freq()
{
	local band=$1

	if [ "$band" == "6" ]; then
		echo "5955"
	elif [ "$band" == "5" ]; then
		echo "5180"
	else
		echo "2412"
	fi
}

get_iface_type()
{
	local vec_idx=$(($2+1))
	echo "$(NVG tcv${1} ce_iface_type | awk -F',' -v n=$vec_idx '{print $n}')"
}

get_tcv_enabled()
{
	local chip_idx=$1
	local vec_idx=$(($2+1))
	local tcv_enabled="$(NVG chip${chip_idx} ce_tcv_enabled | awk -F',' -v n=$vec_idx '{print $n}')"
	echo $tcv_enabled
}

get_chip_enabled()
{
	local chip_idx=$1

	if [ "$(get_tcv_enabled ${chip_idx} 0)" == "1" ] || [ "$(get_tcv_enabled ${chip_idx} 1)" == "1" ] ; then
		echo "1"
	else
		echo "0"
	fi
}

bring_interfaces_down()
{
	local chip_idx=$1
	local wlans=$(grep ".*wlan" /proc/net/dev | sed -e 's/:.*$//')
	local wlan_idx0=$(($chip_idx*2))
	local wlan_idx1=$(($chip_idx*2+1))

	for ifname in $wlans; do
		if [ `echo ${ifname} | grep -c "^wlan${wlan_idx0}"` -gt 0 -o `echo ${ifname} | grep -c "^wlan${wlan_idx1}"` -gt 0 ]; then
			ifconfig $ifname down
		fi
	done
}

set_wps_config_methods()
{
	local config_methods_dec=`printf "%d" "0x$1"`

	local WPS_CONFIG_METHODS_USBA=$(( 0x0001 ))
	local WPS_CONFIG_METHODS_ETHERNET=$(( 0x0002 ))
	local WPS_CONFIG_METHODS_LABEL=$(( 0x0004 ))
	local WPS_CONFIG_METHODS_DISPLAY=$(( 0x0008 ))
	local WPS_CONFIG_METHODS_ENT=$(( 0x0010 ))
	local WPS_CONFIG_METHODS_INT=$(( 0x0020 ))
	local WPS_CONFIG_METHODS_NFCI=$(( 0x0040 ))
	local WPS_CONFIG_METHODS_PBC=$(( 0x0080 ))
	local WPS_CONFIG_METHODS_KEYPAD=$(( 0x0100 ))
	local WPS_CONFIG_METHODS_VIRTUAL_PBC=$(( 0x0280 ))
	local WPS_CONFIG_METHODS_PHYSICAL_PBC=$(( 0x0480 ))
	local WPS_CONFIG_METHODS_VIRTUAL_DISPLAY=$(( 0x2008 ))
	local WPS_CONFIG_METHODS_PHYSICAL_DISPLAY=$(( 0x4008 ))

	config_methods_hostapd=""
	#push button
	if [ $(( $config_methods_dec & $WPS_CONFIG_METHODS_PHYSICAL_PBC )) -eq $WPS_CONFIG_METHODS_PHYSICAL_PBC ]
	then
		config_methods_hostapd="$config_methods_hostapd physical_push_button"
	fi
	if [ $(( $config_methods_dec & $WPS_CONFIG_METHODS_VIRTUAL_PBC )) -eq $WPS_CONFIG_METHODS_VIRTUAL_PBC ]
	then
		config_methods_hostapd="$config_methods_hostapd virtual_push_button"
	fi
	if [ $(( $config_methods_dec & $WPS_CONFIG_METHODS_PBC )) -eq $WPS_CONFIG_METHODS_PBC ]
	then
		config_methods_hostapd="$config_methods_hostapd push_button"
	fi
	#display
	if [ $(( $config_methods_dec & $WPS_CONFIG_METHODS_PHYSICAL_DISPLAY )) -eq $WPS_CONFIG_METHODS_PHYSICAL_DISPLAY ]
	then
		config_methods_hostapd="$config_methods_hostapd physical_display"
	fi
	if [ $(( $config_methods_dec & $WPS_CONFIG_METHODS_VIRTUAL_DISPLAY )) -eq $WPS_CONFIG_METHODS_VIRTUAL_DISPLAY ]
	then
		config_methods_hostapd="$config_methods_hostapd virtual_display"
	fi
	if [ $(( $config_methods_dec & $WPS_CONFIG_METHODS_DISPLAY )) -eq $WPS_CONFIG_METHODS_DISPLAY ]
	then
		config_methods_hostapd="$config_methods_hostapd display"
	fi
	if [ $(( $config_methods_dec & $WPS_CONFIG_METHODS_USBA )) -ne 0 ]
	then
		config_methods_hostapd="$config_methods_hostapd usba"
	fi
	if [ $(( $config_methods_dec & $WPS_CONFIG_METHODS_ETHERNET )) -ne 0 ]
	then
		config_methods_hostapd="$config_methods_hostapd ethernet"
	fi
	if [ $(( $config_methods_dec & $WPS_CONFIG_METHODS_LABEL )) -ne 0 ]
	then
		config_methods_hostapd="$config_methods_hostapd label"
	fi
	if [ $(( $config_methods_dec & $WPS_CONFIG_METHODS_KEYPAD )) -ne 0 ]
	then
		config_methods_hostapd="$config_methods_hostapd keypad"
	fi

	# Remove the leading space
	config_methods_hostapd="${config_methods_hostapd# }"
}

set_radius_configuration()
{
	local wlan_idx=$1
	local bss_idx=$2
	local i="$(( bss_idx+1 ))"
	local method="0"
	local conf=${UTILS_CONFIG_FOLDER}/"hostapd_tcv${wlan_idx}.conf"

	local own_ip_addr="$(NVG tcv${wlan_idx} ha_own_ip_addr | awk -F',' -v n=$i '{while($n==""&&n>0)n--;print $n}')"
	if [ -z $own_ip_addr ]; then
		own_ip_addr="192.168.192.1"
	fi
	local primary_select_method="$(NVG tcv${wlan_idx} ha_primary_select_method "0,0,0,0,0,0,0,0" | awk -F',' -v n=$i '{while($n==""&&n>0)n--;print $n}')"
	#HS2.0
	local interworking="$(NVG tcv${wlan_idx} ce_hs_interworking)"
	local access_network_type="$(NVG tcv${wlan_idx} ce_hs_access_network_type)"
	local venue_group="$(NVG tcv${wlan_idx} ce_hs_venue_group)"
	local venue_type="$(NVG tcv${wlan_idx} ce_hs_venue_type)"
	local internet="$(NVG tcv${wlan_idx} ce_hs_internet)"
	local asra="$(NVG tcv${wlan_idx} ce_hs_asra)"
	local esr="$(NVG tcv${wlan_idx} ce_hs_esr)"
	local uesa="$(NVG tcv${wlan_idx} ce_hs_uesa)"
	local hessid="$(NVG tcv${wlan_idx} ce_hs_hessid)"
	local roaming_consortium="$(NVG tcv${wlan_idx} ce_hs_roaming_consortium)"
	local venue_name="$(NVG tcv${wlan_idx} ce_hs_venue_name)"
	local network_auth_type="$(NVG tcv${wlan_idx} ce_hs_network_auth_type)"
	local ipaddr_type_availability="$(NVG tcv${wlan_idx} ce_hs_ipaddr_type_availability)"
	local domain_name="$(NVG tcv${wlan_idx} ce_hs_domain_name)"
	local anqp_3gpp_cell_net="$(NVG tcv${wlan_idx} ce_hs_anqp_3gpp_cell_net)"
	local nai_realm="$(NVG tcv${wlan_idx} ce_hs_nai_realm)"
	local qos_map_set="$(NVG tcv${wlan_idx} ce_hs_qos_map_set)"
	local wnm_sleep_mode="$(NVG tcv${wlan_idx} ce_hs_wnm_sleep_mode)"
	local hs20="$(NVG tcv${wlan_idx} ce_hs_hs20)"
	local disable_dgaf="$(NVG tcv${wlan_idx} ce_hs_disable_dgaf)"
	local osen="$(NVG tcv${wlan_idx} ce_hs_osen)"
	local anqp_domain_id="$(NVG tcv${wlan_idx} ce_hs_anqp_domain_id)"
	local hs20_deauth_req_timeout="$(NVG tcv${wlan_idx} ce_hs_hs20_deauth_req_timeout)"
	local hs20_oper_friendly_name="$(NVG tcv${wlan_idx} ce_hs_hs20_oper_friendly_name)"
	local hs20_wan_metrics="$(NVG tcv${wlan_idx} ce_hs_hs20_wan_metrics)"
	local hs20_conn_capab="$(NVG tcv${wlan_idx} ce_hs_hs20_conn_capab)"
	local hs20_operating_class="$(NVG tcv${wlan_idx} ce_hs_hs20_operating_class)"
	local osu_ssid="$(NVG tcv${wlan_idx} ce_hs_osu_ssid)"
	local osu_server_uri="$(NVG tcv${wlan_idx} ce_hs_osu_server_uri)"
	local osu_friendly_name="$(NVG tcv${wlan_idx} ce_hs_osu_friendly_name)"
	local osu_nai="$(NVG tcv${wlan_idx} ce_hs_osu_nai)"
	local osu_method_list="$(NVG tcv${wlan_idx} ce_hs_osu_method_list)"
	local osu_icon="$(NVG tcv${wlan_idx} ce_hs_osu_icon)"
	local osu_service_desc="$(NVG tcv${wlan_idx} ce_hs_osu_service_desc)"
	#HS2.0
	local radius_retry_init_interval="$(NVG tcv${wlan_idx} ha_radius_retry_init_interval)"
	local enable_keepalive="$(NVG tcv${wlan_idx} ha_radius_enable_keepalive)"
	local keepalive_interval="$(NVG tcv${wlan_idx} ha_radius_keepalive_interval)"
	local keepalive_threshold="$(NVG tcv${wlan_idx} ha_radius_keepalive_failure_threshold)"
	local acct_keepalive_interval="$(NVG tcv${wlan_idx} ha_radius_acct_keepalive_interval)"
	local acct_keepalive_threshold="$(NVG tcv${wlan_idx} ha_radius_acct_keepalive_failure_threshold)"

	local radius_operator_name="$(NVG tcv${wlan_idx} ha_radius_operator_name)"
	local radius_location_data="$(NVG tcv${wlan_idx} ha_radius_location_data)"

	local retransmit_failure_threshold="$(NVG tcv${wlan_idx} ha_radius_retransmit_failure_threshold)"
	if [ x"${retransmit_failure_threshold}" = "x" ]; then
		retransmit_failure_threshold=3
	else
		retransmit_failure_threshold=`echo $retransmit_failure_threshold | awk -F',' -v n=$i '{print $n}'`
	fi

	local acct_retransmit_failure_threshold="$(NVG tcv${wlan_idx} ha_radius_acct_retransmit_failure_threshold)"
	if [ x"${acct_retransmit_failure_threshold}" = "x" ]; then
		acct_retransmit_failure_threshold=3
	else
		acct_retransmit_failure_threshold=`echo $acct_retransmit_failure_threshold | awk -F',' -v n=$i '{print $n}'`
	fi

	local authentication_timeout="$(NVG tcv${wlan_idx} ha_radius_authentication_timeout)"
	if [ x"${authentication_timeout}" = "x" ]; then
		authentication_timeout=5
	else
		authentication_timeout=`echo $authentication_timeout | awk -F',' -v n=$i '{print $n}'`
	fi

	local acct_timeout="$(NVG tcv${wlan_idx} ha_radius_acct_timeout)"
	if [ x"${acct_timeout}" = "x" ]; then
		acct_timeout=5
	else
		acct_timeout=`echo $acct_timeout | awk -F',' -v n=$i '{print $n}'`
	fi

	local auth_holdoff_retries="$(NVG tcv${wlan_idx} ha_radius_auth_holdoff_retries)"
	if [ x"${auth_holdoff_retries}" = "x" ]; then
		auth_holdoff_retries=3
	else
		auth_holdoff_retries=`echo $auth_holdoff_retries | awk -F',' -v n=$i '{print $n}'`
	fi

	local auth_holdoff_timeout="$(NVG tcv${wlan_idx} ha_radius_auth_holdoff_timeout)"
	if [ x"${auth_holdoff_timeout}" = "x" ]; then
		auth_holdoff_timeout=60
	else
		auth_holdoff_timeout=`echo $auth_holdoff_timeout | awk -F',' -v n=$i '{print $n}'`
	fi

	local auth_holdoff_threshold="$(NVG tcv${wlan_idx} ha_radius_auth_holdoff_threshold)"
	if [ x"${auth_holdoff_threshold}" = "x" ]; then
		auth_holdoff_threshold=300
	else
		auth_holdoff_threshold=`echo $auth_holdoff_threshold | awk -F',' -v n=$i '{print $n}'`
	fi

	local disable_pmksa_caching="$(NVG tcv${wlan_idx} ha_disable_pmk_caching)"
	if [ x"${disable_pmksa_caching}" = "x" ]; then
		disable_pmksa_caching=0
	else
		disable_pmksa_caching=`echo $disable_pmksa_caching | awk -F',' -v n=$i '{print $n}'`
	fi

	local eap_reauth_period="$(NVG tcv${wlan_idx} ha_eap_reauth_period)"
	if [ -z "$eap_reauth_period" ]; then
		eap_reauth_period=0
	else
		eap_reauth_period=`echo $eap_reauth_period | awk -F',' -v n=$i '{print $n}'`
	fi

	local auth_server_addr="$(NVG tcv${wlan_idx} ha_auth_server_addr)"
	auth_server_addr=`echo $auth_server_addr | awk -F',' -v n=$i '{print $n}'`

	local auth_server_addr_secondary="$(NVG tcv${wlan_idx} ha_auth_server_addr_secondary)"
	auth_server_addr_secondary=`echo $auth_server_addr_secondary | awk -F',' -v n=$i '{print $n}'`

	local auth_server_port="$(NVG tcv${wlan_idx} ha_auth_server_port)"
	auth_server_port=`echo $auth_server_port | awk -F',' -v n=$i '{print $n}'`

	local auth_server_port_secondary="$(NVG tcv${wlan_idx} ha_auth_server_port_secondary)"
	auth_server_port_secondary=`echo $auth_server_port_secondary | awk -F',' -v n=$i '{print $n}'`

	local auth_server_shared_secret="$(NVG tcv${wlan_idx} ha_auth_server_shared_secret$i)"

	local auth_server_shared_secret_secondary="$(NVG tcv${wlan_idx} ha_auth_server_shared_secret_secondary$i)"

	local acct_server_addr="$(NVG tcv${wlan_idx} ha_acct_server_addr)"
	acct_server_addr=`echo $acct_server_addr | awk -F',' -v n=$i '{print $n}'`

	local acct_server_addr_secondary="$(NVG tcv${wlan_idx} ha_acct_server_addr_secondary)"
	acct_server_addr_secondary=`echo $acct_server_addr_secondary | awk -F',' -v n=$i '{print $n}'`

	local acct_server_port="$(NVG tcv${wlan_idx} ha_acct_server_port)"
	acct_server_port=`echo $acct_server_port | awk -F',' -v n=$i '{print $n}'`

	local acct_server_port_secondary="$(NVG tcv${wlan_idx} ha_acct_server_port_secondary)"
	acct_server_port_secondary=`echo $acct_server_port_secondary | awk -F',' -v n=$i '{print $n}'`

	local acct_server_shared_secret="$(NVG tcv${wlan_idx} ha_acct_server_shared_secret$i)"

	local acct_server_shared_secret_secondary="$(NVG tcv${wlan_idx} ha_acct_server_shared_secret_secondary$i)"

	local radius_acct_interim_interval="$(NVG tcv${wlan_idx} ha_radius_acct_interim_interval)"
	if [ -z "$radius_acct_interim_interval"  ]; then
		radius_acct_interim_interval=0
	else
		radius_acct_interim_interval=`echo $radius_acct_interim_interval | awk -F',' -v n=$i '{print $n}'`
	fi

	if [ "$radius_operator_name" != "" ]; then
		add_key "radius_auth_req_attr" "126:s:${radius_operator_name}" $wlan_idx
		add_key "radius_acct_req_attr" "126:s:${radius_operator_name}" $wlan_idx
	fi

	if [ "$radius_location_data" != "" ]; then
		add_key "radius_auth_req_attr" "128:s:${radius_location_data}" $wlan_idx
		add_key "radius_acct_req_attr" "128:s:${radius_location_data}" $wlan_idx
	fi

	local nas_ipv6_addr="$(NVG tcv${wlan_idx} ha_radius_nas_ipv6_addr | awk -F',' -v n=$i '{print $n}')"

	# Use IPv6 address instead of IPv4 (own_ip_addr) as an attribute in RADIUS Access-Request
	local use_nas_ipv6_addr="$(NVG tcv${wlan_idx} ha_radius_use_nas_ipv6_addr)"
	if [ -z "$use_nas_ipv6_addr" ]; then
		use_nas_ipv6_addr=0
	else
		use_nas_ipv6_addr=`echo $use_nas_ipv6_addr | awk -F',' -v n=$i '{print $n}'`
	fi

	#apply values of auth_server and acct_sever
	if [ "$primary_select_method" = "2" ]; then
		if [ $RANDOM -gt 16000 ]; then
			method="0"
		else
			method="1"
		fi
	elif [ "$primary_select_method" = "1" ]; then
		method="1"
	else
		method="0"
	fi

	if [ "$method" = "0" ]; then
		# These parameters should always be in the NVRAM on every platform
		if [ -n "$auth_server_addr" ] && [ -n "$auth_server_port" ] && [ -n "$auth_server_shared_secret" ] ; then
			add_key "auth_server_addr" "$auth_server_addr" $wlan_idx
			add_key "auth_server_port" "$auth_server_port" $wlan_idx
			add_key "auth_server_shared_secret" "$auth_server_shared_secret" $wlan_idx
		fi

		if [ -n "$auth_server_addr_secondary" ] && [ -n "$auth_server_port_secondary" ] && [ -n "$auth_server_shared_secret_secondary" ]; then
			add_key "auth_server_addr" "$auth_server_addr_secondary" $wlan_idx
			add_key "auth_server_port" "$auth_server_port_secondary" $wlan_idx
			add_key "auth_server_shared_secret" "$auth_server_shared_secret_secondary" $wlan_idx
		fi

		if [ -n "$acct_server_addr" ] && [ -n "$acct_server_port" ] && [ -n "$acct_server_shared_secret" ]; then
			add_key "acct_server_addr" "$acct_server_addr" $wlan_idx
			add_key "acct_server_port" "$acct_server_port" $wlan_idx
			add_key "acct_server_shared_secret" "$acct_server_shared_secret" $wlan_idx
		fi

		if [ "$radius_acct_interim_interval" != "" ]; then 
			add_key "radius_acct_interim_interval" "${radius_acct_interim_interval}" $wlan_idx
		fi

		if [ -n "$acct_server_addr_secondary" ] && [ -n "$acct_server_port_secondary" ] && [ -n "$acct_server_shared_secret_secondary" ]; then
			add_key "acct_server_addr" "$acct_server_addr_secondary" $wlan_idx
			add_key "acct_server_port" "$acct_server_port_secondary" $wlan_idx
			add_key "acct_server_shared_secret" "$acct_server_shared_secret_secondary" $wlan_idx
		fi
	else
		# These parameters should always be in the NVRAM on every platform
		if [ -n "$auth_server_addr_secondary" ] && [ -n "$auth_server_port_secondary" ] && [ -n "$auth_server_shared_secret_secondary" ]; then
			add_key "auth_server_addr" "$auth_server_addr_secondary" $wlan_idx
			add_key "auth_server_port" "$auth_server_port_secondary" $wlan_idx
			add_key "auth_server_shared_secret" "$auth_server_shared_secret_secondary" $wlan_idx
		fi

		if [ -n "$auth_server_addr" ] && [ -n "$auth_server_port" ] && [ -n "$auth_server_shared_secret" ] ; then
			add_key "auth_server_addr" "$auth_server_addr" $wlan_idx
			add_key "auth_server_port" "$auth_server_port" $wlan_idx
			add_key "auth_server_shared_secret" "$auth_server_shared_secret" $wlan_idx
		fi

		if [ -n "$acct_server_addr_secondary" ] && [ -n "$acct_server_port_secondary" ] && [ -n "$acct_server_shared_secret_secondary" ]; then
			add_key "acct_server_addr" "$acct_server_addr_secondary" $wlan_idx
			add_key "acct_server_port" "$acct_server_port_secondary" $wlan_idx
			add_key "acct_server_shared_secret" "$acct_server_shared_secret_secondary" $wlan_idx
		fi

		if [ -n "$acct_server_addr" ] && [ -n "$acct_server_port" ] && [ -n "$acct_server_shared_secret" ]; then
			add_key "acct_server_addr" "$acct_server_addr" $wlan_idx
			add_key "acct_server_port" "$acct_server_port" $wlan_idx
			add_key "acct_server_shared_secret" "$acct_server_shared_secret" $wlan_idx
		fi

		if [ "$radius_acct_interim_interval" != "" ]; then
			add_key "radius_acct_interim_interval" "${radius_acct_interim_interval}" $wlan_idx
		fi
	fi

	if [ "$disable_pmksa_caching" != "" ]; then
		add_key "disable_pmksa_caching" "${disable_pmksa_caching}" $wlan_idx
	fi

	#HS2.0
	if [ "$interworking" != "" ]; then
		set_key "interworking" "${interworking}" 1 $wlan_idx $bss_idx
	fi
	if [ "$venue_group" != "" ]; then
		set_key "venue_group" "${venue_group}" 1 $wlan_idx $bss_idx
	fi
	if [ "$venue_type" != "" ]; then
		set_key "venue_type" "${venue_type}" 1 $wlan_idx $bss_idx
	fi
	if [ "$access_network_type" != "" ]; then
		set_key "access_network_type" "${access_network_type}" 1 $wlan_idx $bss_idx
	fi
	if [ "$internet" != "" ]; then
		set_key "internet" "${internet}" 1 $wlan_idx $bss_idx
	fi
	if [ "$asra" != "" ]; then
		set_key "asra" "${asra}" 1 $wlan_idx $bss_idx
	fi
	if [ "$esr" != "" ]; then
		set_key "esr" "${esr}" 1 $wlan_idx $bss_idx
	fi
	if [ "$uesa" != "" ]; then
		set_key "uesa" "${uesa}" 1 $wlan_idx $bss_idx
	fi
	if [ "$hessid" != "" ]; then
		set_key "hessid" "${hessid}" 1 $wlan_idx $bss_idx
	fi
	if [ "$roaming_consortium" != "" ]; then
		set_key "roaming_consortium" "${roaming_consortium}" 1 $wlan_idx $bss_idx
	fi
	if [ "$venue_name" != "" ]; then
		set_key "venue_name" "${venue_name}" 1 $wlan_idx $bss_idx
	fi
	if [ "$network_auth_type" != "" ]; then
		set_key "network_auth_type" "${network_auth_type}" 1 $wlan_idx $bss_idx
	fi
	if [ "$ipaddr_type_availability" != "" ]; then
		set_key "ipaddr_type_availability" "${ipaddr_type_availability}" 1 $wlan_idx $bss_idx
	fi
	if [ "$domain_name" != "" ]; then
		set_key "domain_name" "${domain_name}" 1 $wlan_idx $bss_idx
	fi
	if [ "$anqp_3gpp_cell_net" != "" ]; then
		set_key "anqp_3gpp_cell_net" "${anqp_3gpp_cell_net}" 1 $wlan_idx $bss_idx
	fi
	if [ "$nai_realm" != "" ]; then
		set_key "nai_realm" "${nai_realm}" 1 $wlan_idx $bss_idx
	fi
	if [ "$wnm_sleep_mode" != "" ]; then
		set_key "wnm_sleep_mode" "${wnm_sleep_mode}" 1 $wlan_idx $bss_idx
	fi
	if [ "$qos_map_set" != "" ]; then
		set_key "qos_map_set" "${qos_map_set}" 1 $wlan_idx $bss_idx
	fi
	if [ "$hs20" != "" ]; then
		set_key "hs20" "${hs20}" 1 $wlan_idx $bss_idx
	fi
	if [ "$disable_dgaf" != "" ]; then
		set_key "disable_dgaf" "${disable_dgaf}" 1 $wlan_idx $bss_idx
	fi
	if [ "$osen" != "" ]; then
		set_key "osen" "${osen}" 1 $wlan_idx $bss_idx
	fi
	if [ "$anqp_domain_id" != "" ]; then
		set_key "anqp_domain_id" "${anqp_domain_id}" 1 $wlan_idx $bss_idx
	fi
	if [ "$hs20_deauth_req_timeout" != "" ]; then 
		set_key "hs20_deauth_req_timeout" "${hs20_deauth_req_timeout}" 1 $wlan_idx $bss_idx
	fi
	if [ "$hs20_oper_friendly_name" != "" ]; then
		set_key "hs20_oper_friendly_name" "${hs20_oper_friendly_name}" 1 $wlan_idx $bss_idx
	fi
	if [ "$hs20_wan_metrics" != "" ]; then
		set_key "hs20_wan_metrics" "${hs20_wan_metrics}" 1 $wlan_idx $bss_idx
	fi
	if [ "$hs20_conn_capab" != "" ]; then
		set_key "hs20_conn_capab" "${hs20_conn_capab}" 1 $wlan_idx $bss_idx
	fi
	if [ "$hs20_operating_class" != "" ]; then
		set_key "hs20_operating_class" "${hs20_operating_class}" 1 $wlan_idx $bss_idx
	fi
	if [ "$osu_ssid" != "" ]; then
		set_key "osu_ssid" "${osu_ssid}" 1 $wlan_idx $bss_idx
	fi
	if [ "$osu_server_uri" != "" ]; then
		set_key "osu_server_uri" "${osu_server_uri}" 1 $wlan_idx $bss_idx
	fi
	if [ "$osu_friendly_name" != "" ]; then
		set_key "osu_friendly_name" "${osu_friendly_name}" 1 $wlan_idx $bss_idx
	fi
	if [ "$osu_nai" != "" ]; then
		set_key "osu_nai" "${osu_nai}" 1 $wlan_idx $bss_idx
	fi
	if [ "$osu_method_list" != "" ]; then
		set_key "osu_method_list" "${osu_method_list}" 1 $wlan_idx $bss_idx
	fi
	if [ "$osu_icon" != "" ]; then
		set_key "osu_icon" "${osu_icon}" 1 $wlan_idx $bss_idx
	fi
	if [ "$osu_service_desc" != "" ]; then
		set_key "osu_service_desc" "${osu_service_desc}" 1 $wlan_idx $bss_idx
	fi
	#HS2.0

	set_key "own_ip_addr" "$own_ip_addr" 1 $wlan_idx $bss_idx
	set_key "radius_retry_init_interval" "$radius_retry_init_interval" 1 $wlan_idx $bss_idx
	set_key "enable_keepalive" "${enable_keepalive}" 1 $wlan_idx $bss_idx
	set_key "keepalive_interval" "${keepalive_interval}" 1 $wlan_idx $bss_idx
	set_key "keepalive_threshold" "${keepalive_threshold}" 1 $wlan_idx $bss_idx
	set_key "acct_keepalive_threshold" "${acct_keepalive_threshold}" 1 $wlan_idx $bss_idx
	set_key "acct_keepalive_interval" "${acct_keepalive_interval}" 1 $wlan_idx $bss_idx
	
	add_key "retransmit_failure_threshold" "${retransmit_failure_threshold}" $wlan_idx
	add_key "acct_retransmit_failure_threshold" "${acct_retransmit_failure_threshold}" $wlan_idx
	add_key "authentication_timeout" "${authentication_timeout}" $wlan_idx
	add_key "acct_timeout" "${acct_timeout}" $wlan_idx
	
	add_key "auth_holdoff_retries" "${auth_holdoff_retries}" $wlan_idx
	add_key "auth_holdoff_timeout" "${auth_holdoff_timeout}" $wlan_idx
	add_key "auth_holdoff_threshold" "${auth_holdoff_threshold}" $wlan_idx

	add_key "eap_reauth_period" "$eap_reauth_period" $wlan_idx

	# NAS-IPv6 Address: TLV param, type 95
	if [ ! -z $nas_ipv6_addr ]; then
		add_key "radius_auth_req_attr" "95:s:$nas_ipv6_addr" $wlan_idx
		if [ $use_nas_ipv6_addr == 1 ]; then
			add_key "radius_use_nas_ipv6_addr" 1 $wlan_idx
		else
			add_key "radius_use_nas_ipv6_addr" 0 $wlan_idx
		fi
	else
		add_key "radius_use_nas_ipv6_addr" 0 $wlan_idx
	fi

	sed -i "/wlan${wlan_idx}_$bss_idx/,/bss=.*/{/wpa_passphrase=/d}" $conf
}

set_pmf_hostpad_conf()
{
	local wlan_idx=$1
	local bss_idx=$2
	local ha_auth_mode=$3
	local ap="$(( bss_idx+1 ))"
	local ieee80211w="$(NVG tcv${wlan_idx} ha_ieee80211w 0,0,0,0,0,0,0,0 | awk -F',' -v n=$ap '{print $n}')"

	case "$ieee80211w" in
		0)
			set_key "ieee80211w" 0 1 $wlan_idx $bss_idx
			return
			;;
		1) # capable
			set_key "ieee80211w" 1 1 $wlan_idx $bss_idx
			if [ "$ha_auth_mode" = "WPA2" -o "$ha_auth_mode" = "WPA" ]; then
				set_key "wpa_key_mgmt" "WPA-EAP" 1 $wlan_idx $bss_idx
				set_key "auth_algs" 1 1 $wlan_idx $bss_idx
			else
				set_key "wpa_key_mgmt" "WPA-PSK" 1 $wlan_idx $bss_idx
				set_key "auth_algs" 3 1 $wlan_idx $bss_idx
			fi
			;;
		2) # required
			set_key "ieee80211w" 2 1 $wlan_idx $bss_idx
			if [ "$ha_auth_mode" = "WPA2" -o "ha_auth_mode" = "WPA" ]; then
				set_key "wpa_key_mgmt" "WPA-EAP WPA-EAP-SHA256" 1 $wlan_idx $bss_idx
				set_key "auth_algs" 1 1 $wlan_idx $bss_idx
			elif [ "$ha_auth_mode" = "WPA3" ]; then
				set_key "wpa_key_mgmt" "WPA-EAP-SUITE-B-192" 1 $wlan_idx $bss_idx
				set_key "auth_algs" 1 1 $wlan_idx $bss_idx
			elif [ "$ha_auth_mode" = "WPA3SAE" ]; then
				set_key "wpa_key_mgmt" "SAE" 1 $wlan_idx $bss_idx
				set_key "auth_algs" 1 1 $wlan_idx $bss_idx
			else
				set_key "wpa_key_mgmt" "WPA-PSK WPA-PSK-SHA256" 1 $wlan_idx $bss_idx
				set_key "auth_algs" 3 1 $wlan_idx $bss_idx
			fi
			;;
	esac
}

set_pmf_supplicant_conf()
{
	local wlan_idx=$1
	local ws_auth_mode=$2
	local conf=$3
	local ws_ieee80211w="$(NVG tcv${wlan_idx} ws_ieee80211w)"

	if [ ! -z $ws_ieee80211w ]; then
		case "$ws_ieee80211w" in
			0)
				sed -i '/^network=.*/a \ieee80211w=0' $conf
				return
				;;
			1) # capable
				sed -i '/^network=.*/a \ieee80211w=1' $conf
				if [ "$ws_auth_mode" = "WPA2" -o "$ws_auth_mode" = "WPA" ]; then
					sed -i 's/\(key_mgmt=\).*/\1WPA-EAP/' $conf
				else
					sed -i 's/\(key_mgmt=\).*/\1WPA-PSK/' $conf
				fi
				;;
			2) # required
				sed -i '/^network=.*/a \ieee80211w=2' $conf
				if [ "$ws_auth_mode" = "WPA2" -o "ws_auth_mode" = "WPA" ]; then
					sed -i 's/\(key_mgmt=\).*/\1WPA-EAP WPA-EAP-SHA256/' $conf
				elif [ "$ws_auth_mode" = "WPA3" ]; then
					sed -i 's/\(key_mgmt=\).*/\1WPA-EAP-SUITE-B-192/' $conf
				elif [ "$ws_auth_mode" = "WPA3SAE" ]; then
					sed -i 's/\(key_mgmt=\).*/\1SAE/' $conf
				else
					sed -i 's/\(key_mgmt=\).*/\1WPA-PSK WPA-PSK-SHA256/' $conf
				fi
				;;
		esac
	fi
}

set_he_mu_edca_conf()
{
	local wlan_idx=$1
	local bss_idx=$2
	local i=$(( bss_idx+1 ))
	local he_mu_edca_qos_info_param_count="$(NVG tcv${wlan_idx} ha_he_mu_edca_qos_info_param_count "0,0,0,0,0,0,0,0" | awk -F',' -v n=$i '{print $n}')"
	local he_mu_edca_qos_info_q_ack="$(NVG tcv${wlan_idx} ha_he_mu_edca_qos_info_q_ack "0,0,0,0,0,0,0,0" | awk -F',' -v n=$i '{print $n}')"
	local he_mu_edca_qos_info_queue_request="$(NVG tcv${wlan_idx} ha_he_mu_edca_qos_info_queue_request "0,0,0,0,0,0,0,0" | awk -F',' -v n=$i '{print $n}')"
	local he_mu_edca_qos_info_txop_request="$(NVG tcv${wlan_idx} ha_he_mu_edca_qos_info_txop_request "0,0,0,0,0,0,0,0" | awk -F',' -v n=$i '{print $n}')"
	local he_mu_edca_aifsn="$(NVG tcv${wlan_idx} ha_he_mu_edca_aifsn$i "3,7,2,2")"
	local he_mu_edca_acm="$(NVG tcv${wlan_idx} ha_he_mu_edca_acm$i "0,0,0,0")"
	local he_mu_edca_aci="$(NVG tcv${wlan_idx} ha_he_mu_edca_aci$i "0,1,2,3")"
	local he_mu_edca_ecwmin="$(NVG tcv${wlan_idx} ha_he_mu_edca_ecwmin$i "4,4,3,2")"
	local he_mu_edca_ecwmax="$(NVG tcv${wlan_idx} ha_he_mu_edca_ecwmax$i "10,10,4,3")"
	local he_mu_edca_timer="$(NVG tcv${wlan_idx} ha_he_mu_edca_timer$i "255,255,255,255")"
	local ac

	for ac in 1 2 3 4 ; do
		local prio=
		case $ac in
			1) prio=be ;;
			2) prio=bk ;;
			3) prio=vi ;;
			4) prio=vo ;;
		esac
		set_key "he_mu_edca_ac_${prio}_aifsn" "$(echo "$he_mu_edca_aifsn" | awk -F',' -v n=$ac '{print $n}')" 1 $wlan_idx $bss_idx
		set_key "he_mu_edca_ac_${prio}_acm" "$(echo "$he_mu_edca_acm" | awk -F',' -v n=$ac '{print $n}')" 1 $wlan_idx $bss_idx
		set_key "he_mu_edca_ac_${prio}_aci" "$(echo "$he_mu_edca_aci" | awk -F',' -v n=$ac '{print $n}')" 1 $wlan_idx $bss_idx
		set_key "he_mu_edca_ac_${prio}_ecwmin" "$(echo "$he_mu_edca_ecwmin" | awk -F',' -v n=$ac '{print $n}')" 1 $wlan_idx $bss_idx
		set_key "he_mu_edca_ac_${prio}_ecwmax" "$(echo "$he_mu_edca_ecwmax" | awk -F',' -v n=$ac '{print $n}')" 1 $wlan_idx $bss_idx
		set_key "he_mu_edca_ac_${prio}_timer" "$(echo "$he_mu_edca_timer" | awk -F',' -v n=$ac '{print $n}')" 1 $wlan_idx $bss_idx
	done
	set_key "he_mu_edca_qos_info_param_count" "$he_mu_edca_qos_info_param_count" 1 $wlan_idx $bss_idx
	set_key "he_mu_edca_qos_info_q_ack" "$he_mu_edca_qos_info_q_ack" 1 $wlan_idx $bss_idx
	set_key "he_mu_edca_qos_info_queue_request" "$he_mu_edca_qos_info_queue_request" 1 $wlan_idx $bss_idx
	set_key "he_mu_edca_qos_info_txop_request" "$he_mu_edca_qos_info_txop_request" 1 $wlan_idx $bss_idx
}

set_key()
{
	local key="$1"
	local value="$2"
	local enable="$3"
	local wlan_idx="$4"
	local bss_idx="$5"
	local conf=${UTILS_CONFIG_FOLDER}/"hostapd_tcv${wlan_idx}.conf"
	local found=0

	local sd="/wlan"${wlan_idx}"_"$bss_idx"/,/bss=.*/{/^#\{0,1\}${key}=.*/p}"
	local line="$(sed -n "$sd" $conf)"
	if [ -n "$line" ] ; then found=1 ; fi
	if [ $found -eq 0 ]; then
		if [ $enable -eq 1 ]; then
			echo "$key=$value" >> $conf
		fi
		return
	fi
	value="$(echo "$value" | sed -e 's/[/&\]/\\&/g')"
	if [ "${line} | cut -c1" = "#" -a $enable -eq 1 ]; then
		sed -i "s/^#\($key=\).*/\1"${value}"/" $conf
		return
	fi
	if [ $enable -eq 1 ]; then
		sed -i "/wlan"${wlan_idx}"_"$bss_idx"/,/bss=.*/{s/^\($key=\).*/\1${value}/}" $conf
	elif [ $enable -ne 1 -a "${line} | cut -c1" != "#" ]; then
		sed -i "/wlan"${wlan_idx}"_"$bss_idx"/,/bss=.*/{s/^\($key=\).*/#\1/}" $conf
	fi
}

add_key()
{
	local key="$1"
	local value="$2"
	local wlan_idx=$3
	local conf=${UTILS_CONFIG_FOLDER}/"hostapd_tcv${wlan_idx}.conf"
	echo "$key=$value" >> $conf
}

get_vht_mode()
{
	local band=$1
	local wlan_idx=$2

	if [ "$band" == "24" ]; then
		local vht_cap_24g="$(NVG tcv${wlan_idx} ci_vht_cap_24g 0)"

		if [ "$vht_cap_24g" == "1" ]; then
			echo "1"
		else
			echo "0"
		fi
	else
		echo "1"
	fi
}

set_wireless_mode()
{
	local wlan_idx=$1
	local band=$2
	local mode="$(NVG tcv${wlan_idx} ce_wireless_mode 3)"
	local vht=$(get_vht_mode $band $wlan_idx)

	case "$mode" in
		0) # Don't support HT/VHT/HE
			add_key "ieee80211n" "0" $wlan_idx
			add_key "ieee80211ac" "0" $wlan_idx
			add_key "ieee80211ax" "0" $wlan_idx
			;;
		1) # Support HT, don't support VHT and HE.
			add_key "ieee80211n" "1" $wlan_idx
			add_key "ieee80211ac" "0" $wlan_idx
			add_key "ieee80211ax" "0" $wlan_idx
			;;
		2) # Support HT and VHT. Don't support HE.
			add_key "ieee80211n" "1" $wlan_idx
			add_key "ieee80211ac" "$vht" $wlan_idx
			add_key "ieee80211ax" "0" $wlan_idx
			;;
		3) # Support HT, VHT and HE
			add_key "ieee80211n" "1" $wlan_idx
			add_key "ieee80211ac" "$vht" $wlan_idx
			add_key "ieee80211ax" "1" $wlan_idx
			;;
		4) # Support HE only.
			add_key "ieee80211n" "0" $wlan_idx
			add_key "ieee80211ac" "0" $wlan_idx
			add_key "ieee80211ax" "1" $wlan_idx
			;;
		*) # default
			add_key "ieee80211n" "0" $wlan_idx
			add_key "ieee80211ac" "0" $wlan_idx
			add_key "ieee80211ax" "0" $wlan_idx
			;;
	esac
}

set_security_hostpad_conf()
{
	local wlan_idx="$1"
	local ap_idx="$2"
	local ap=$(( ap_idx+1 ))
	local auth_algs=0
	local wpa_passphrase="$(NVG tcv${wlan_idx} ha_wpa_passphrase$ap 12345678)"
	ieee8021x=0
	local wpa_pairwise=
	local wpa_group_rekey="$(NVG tcv${wlan_idx} ha_wpa_group_rekey "0,0,0,0,0,0,0,0" | awk -F',' -v n=$i '{print $n}')"

	case "$ha_encrypt_type" in
		AES)
			wpa_pairwise="CCMP"
			;;
		TKIP)
			wpa_pairwise="TKIP"
			;;
		TKIPAES)
			wpa_pairwise="TKIP CCMP"
			;;
		WEP)
			wpa_pairwise="WEP40 WEP104"
			wpa_passphrase=""
			;;
		WPAPSK)
			wpa_val=1
			auth_algs=$HOSTAPD_AUTH_OPEN_SHARED

			if [ "$ieee80211r" = "1" ]; then
				if [ "$ft_clients_only" = "1" ]; then
					wpa_key_mgmt="FT-PSK"
				else
					wpa_key_mgmt="WPA-PSK FT-PSK"
				fi
			else
				wpa_key_mgmt="WPA-PSK"
			fi
			;;
		NONE)
			wpa_pairwise="NONE"
			;;
		*)
			echo "Invalid value for ha_encrypt_type"
			action_stop
			exit 1
			;;
	esac

	HOSTAPD_AUTH_OPEN=1
	HOSTAPD_AUTH_SHARED=2
	HOSTAPD_AUTH_OPEN_SHARED=3

	case "$ha_auth_mode" in
		OPEN)
			wpa_val=0
			wpa_passphrase=""
			auth_algs=$HOSTAPD_AUTH_OPEN
			;;
		SHARED)
			auth_algs=$HOSTAPD_AUTH_SHARED
			wpa_val=0
			wpa_passphrase=""
			;;
		WEPAUTO)
			auth_algs=$HOSTAPD_AUTH_OPEN_SHARED
			wpa_val=0
			wpa_passphrase=""
			;;
		WPAPSK)
			wpa_val=1
			auth_algs=$HOSTAPD_AUTH_OPEN_SHARED

			if [ "$ieee80211r" = "1" ]; then
				if [ "$ft_clients_only" = "1" ]; then
					wpa_key_mgmt="FT-PSK"
				else
					wpa_key_mgmt="WPA-PSK FT-PSK"
				fi
			else
				wpa_key_mgmt="WPA-PSK"
			fi
			;;
		WPA)
			ieee8021x=1
			wpa_val=1
			auth_algs=$HOSTAPD_AUTH_OPEN

			if [ "$ieee80211r" = "1" ]; then
				if [ "$ft_clients_only" = "1" ]; then
					wpa_key_mgmt="FT-EAP"
				else
					wpa_key_mgmt="WPA-EAP FT-EAP"
				fi
			else
				wpa_key_mgmt="WPA-EAP"
			fi
			;;
		WPA3SAE)
			wpa_val=2
			auth_algs=$HOSTAPD_AUTH_OPEN_SHARED

			if [ "$ieee80211r" = "1" ]; then
				if [ "$ft_clients_only" = "1" ]; then
					wpa_key_mgmt="FT-SAE"
				else
					wpa_key_mgmt="SAE FT-SAE"
				fi
			else
				wpa_key_mgmt="SAE"
			fi
			;;
		WPA3)
			ieee8021x=1
			wpa_val=2
			auth_algs=$HOSTAPD_AUTH_OPEN_SHARED

			if [ "$ieee80211r" = "1" ]; then
				if [ "$ft_clients_only" = "1" ]; then
					# TODO: Need to verify that FT-FILS-SHA384 is the right FT mode for WPA3-Enterprise mode
					wpa_key_mgmt="FT-FILS-SHA384"
				else
					# TODO: Need to verify that FT-FILS-SHA384 is the right FT mode for WPA3-Enterprise mode
					wpa_key_mgmt="WPA-EAP-SUITE-B-192 FT-FILS-SHA384"
				fi
			else
				wpa_key_mgmt="WPA-EAP-SUITE-B-192"
			fi
			;;
		WPA2PSK)
			wpa_val=2
			auth_algs=$HOSTAPD_AUTH_OPEN_SHARED

			if [ "$ieee80211r" = "1" ]; then
				if [ "$ft_clients_only" = "1" ]; then
					wpa_key_mgmt="FT-PSK"
				else
					wpa_key_mgmt="WPA-PSK FT-PSK"
				fi
			else
				wpa_key_mgmt="WPA-PSK"
			fi
			;;
		WPA2)
			ieee8021x=1
			wpa_val=2
			auth_algs=$HOSTAPD_AUTH_OPEN

			if [ "$ieee80211r" = "1" ]; then
				if [ "$ft_clients_only" = "1" ]; then
					wpa_key_mgmt="FT-EAP"
				else
					wpa_key_mgmt="WPA-EAP FT-EAP"
				fi
			else
				wpa_key_mgmt="WPA-EAP"
			fi
			;;
		WPAPSKWPA2PSK)
			wpa_val=3
			auth_algs=$HOSTAPD_AUTH_OPEN_SHARED

			if [ "$ieee80211r" = "1" ]; then
				if [ "$ft_clients_only" = "1" ]; then
					wpa_key_mgmt="FT-PSK"
				else
					wpa_key_mgmt="WPA-PSK FT-PSK"
				fi
			else
				wpa_key_mgmt="WPA-PSK"
			fi
			;;
		WPA1WPA2)
			ieee8021x=1
			wpa_val=3
			auth_algs=$HOSTAPD_AUTH_OPEN

			if [ "$ieee80211r" = "1" ]; then
				if [ "$ft_clients_only" = "1" ]; then
					wpa_key_mgmt="FT-EAP"
				else
					wpa_key_mgmt="WPA-EAP FT-EAP"
				fi
			else
				wpa_key_mgmt="WPA-EAP"
			fi
			;;
		*)
			echo "Invalid value for ha_auth_mode"
			action_stop
			exit 1
			;;
	esac

	auth_encrypt_combination_valid_result=$(is_auth_encrypt_combination_valid)
	if [ "$auth_encrypt_combination_valid_result" == "0" ]; then
		echo "Wrong configuration: ha_auth_mode = [$ha_auth_mode] and ha_encrypt_type = [$ha_encrypt_type]"
		action_stop
		exit 1
	fi

	if [ "$ha_auth_mode" = "OPEN" -o "$ha_auth_mode" = "SHARED" -o "$ha_auth_mode" = "WEPAUTO" ]; then
		if [ "${ha_encrypt_type}" = "WEP" ]; then
			wpa_val=0
			local wep_default_key="$(NVG tcv${wlan_idx} ha_wep_default_key "1,1,1,1,1,1,1,1" | awk -F',' -v n=$i '{print $n-1}')"
			local key1="$(NVG tcv${wlan_idx} ha_wep_key0_$i)"
			local key2="$(NVG tcv${wlan_idx} ha_wep_key1_$i)"
			local key3="$(NVG tcv${wlan_idx} ha_wep_key2_$i)"
			local key4="$(NVG tcv${wlan_idx} ha_wep_key3_$i)"
			if [ ${#key1} -eq 5 ] || [ ${#key1} -eq 13 ] ; then key1=\"${key1}\" ; fi
			if [ ${#key2} -eq 5 ] || [ ${#key2} -eq 13 ] ; then key2=\"${key2}\" ; fi
			if [ ${#key3} -eq 5 ] || [ ${#key3} -eq 13 ] ; then key3=\"${key3}\" ; fi
			if [ ${#key4} -eq 5 ] || [ ${#key4} -eq 13 ] ; then key4=\"${key4}\" ; fi
			set_key "wep_key0" "$key1" 1 $wlan_idx $ap_idx
			set_key "wep_key1" "$key2" 1 $wlan_idx $ap_idx
			set_key "wep_key2" "$key3" 1 $wlan_idx $ap_idx
			set_key "wep_key3" "$key4" 1 $wlan_idx $ap_idx
			set_key "wep_default_key" $wep_default_key 1 $wlan_idx $ap_idx
			set_key "auth_algs" $auth_algs 1 $wlan_idx $ap_idx
		else
			set_key "wep_key0" "none" 0 $wlan_idx $ap_idx
			set_key "wep_key1" "none" 0 $wlan_idx $ap_idx
			set_key "wep_key2" "none" 0 $wlan_idx $ap_idx
			set_key "wep_key3" "none" 0 $wlan_idx $ap_idx
			set_key "wep_default_key" "none" 0 $wlan_idx $ap_idx
		fi

	fi

	# replace passphrase parameter in hostapd.conf
	if [ $wpa_val -ne 0 ]; then
		set_key "wpa" "$wpa_val" 1 $wlan_idx $ap_idx

		if [ ${#wpa_passphrase} -eq 64 ]; then
			tmp_wpa=`echo $wpa_passphrase | sed 's/[a-fA-F0-9]//g'`
			if [ ${#tmp_wpa} -eq 0 ]; then
				set_key "wpa_passphrase" "none" 0 $wlan_idx $ap_idx
				set_key "wpa_psk" "$wpa_passphrase" 1 $wlan_idx $ap_idx
			else
				set_key "wpa_passphrase" "$wpa_passphrase" 1 $wlan_idx $ap_idx
			fi
		else
			set_key "wpa_passphrase" "$wpa_passphrase" 1 $wlan_idx $ap_idx
		fi

		set_key "wpa_key_mgmt" "$wpa_key_mgmt" 1 $wlan_idx $ap_idx
		set_key "wpa_group_rekey" "$wpa_group_rekey" 1 $wlan_idx $ap_idx
		if [ ${wpa_val} -eq 3 ]; then
			set_key "wpa_pairwise" "TKIP" 1 $wlan_idx $ap_idx
			set_key "rsn_pairwise" "TKIP CCMP" 1 $wlan_idx $ap_idx
		elif [ ${wpa_val} -eq 2 ]; then
			if [ ${ha_auth_mode} == "WPA3" ]; then
				local gcmp_len="$(NVG tcv${wlan_idx} ha_gcmp_key_len 256)"
				if [ "$gcmp_len" == "256" ]; then
					set_key "wpa_pairwise" "GCMP-256" 1 $wlan_idx $ap_idx
				elif [ "$gcmp_len" == "128" ]; then
					set_key "wpa_pairwise" "GCMP" 1 $wlan_idx $ap_idx
				else
					echo "cli Error: incorrect gcmp_len - check your nvram !!!!!"
				fi
			else
				set_key "wpa_pairwise" "CCMP" 1 $wlan_idx $ap_idx
			fi
		elif [ ${wpa_val} -eq 1 ]; then
			set_key "wpa_pairwise" "TKIP" 1 $wlan_idx $ap_idx
		else
			set_key "wpa_pairwise" "$wpa_pairwise" 1 $wlan_idx $ap_idx
		fi
		set_key "auth_algs" $auth_algs 1 $wlan_idx $ap_idx
	else
		#if value is not needed it should not be specified at all, otherwise hostapd reports error
		set_key "wpa" "0" 1 $wlan_idx $ap_idx
		set_key "wpa_passphrase" "none" 0 $wlan_idx $ap_idx
		set_key "wpa_key_mgmt" "none" 0 $wlan_idx $ap_idx
		set_key "wpa_group_rekey" "none" 0 $wlan_idx $ap_idx
		set_key "wpa_pairwise" "none" 0 $wlan_idx $ap_idx
		[ -n "${ha_encrypt_type}" ] && [ "${ha_encrypt_type}" != "WEP" ] && set_key "auth_algs" "1" 1 $wlan_idx $ap_idx

	fi
}

apply_acl()
{
	local wlan_idx=$1
	local ap_idx=$2
	local ap="$(( ap_idx+1 ))"
	local macaddr_acl="$(NVG tcv${wlan_idx} ha_macaddr_acl | awk -F',' -v n=$ap '{print $n}')"

	if [ -n "$macaddr_acl" ]; then
		set_key "macaddr_acl" "$macaddr_acl" 1 $wlan_idx $ap_idx
		if [ "$macaddr_acl" = "0" -o "$macaddr_acl" = "2" ]; then
			# accept unless in deny list
			NVG tcv${wlan_idx} ha_macaddr_acl_list${ap} | awk -F "," '{ for (i=1; i<=NF; i++) print $i }' > ${UTILS_CONFIG_FOLDER}/"hostapd_wlan${wlan_idx}_$ap_idx.list"
			set_key "deny_mac_file" ${UTILS_CONFIG_FOLDER}/"hostapd_wlan${wlan_idx}_$ap_idx.list" 1 $wlan_idx $ap_idx
		fi
		if [ "$macaddr_acl" = "1" ]; then
			# deny unless in accept list
			NVG tcv${wlan_idx} ha_macaddr_acl_list${ap} | awk -F "," '{ for (i=1; i<=NF; i++) print $i }' >${UTILS_CONFIG_FOLDER}/"hostapd_wlan${wlan_idx}_$ap_idx.list"
			set_key "accept_mac_file" ${UTILS_CONFIG_FOLDER}/"hostapd_wlan${wlan_idx}_$ap_idx.list" 1 $wlan_idx $ap_idx
		fi
	fi
}

get_secondary_channel()
{
	local _tmp=""
	local wlan_idx=$1
	local channel=$2

	if [ "$channel" -ge "36" ]; then
		local above_list="36 44 52 60 100 108 116 124 132 140 149 157"
		if [ "`echo $above_list | grep -c -w $channel`" == "1" ]; then
			_tmp=1 #above
		else
			_tmp=-1 #below
		fi
	else
		if [ $channel -le 4 ]; then
			_tmp=1 #above
		elif [ $channel -ge 10 ]; then
			_tmp=-1 #below
		elif [ `echo ${ce_channel_info_txt_24g} | grep -c 13,` -eq 0 ]; then
			# Channel 13 is not supported - use below extension channel
			_tmp=-1 #below
		else
			_tmp="$(NVG tcv${wlan_idx} ce_extension_channel 1)"
		fi
	fi

	echo $_tmp
}

bandwidth_to_idx()
{
	case "$1" in
		160)
			echo 3
			;;
		80)
			echo 2
			;;
		40)
			echo 1
			;;
		20)
			echo 0
			;;
	esac
}

idx_to_bandwidth()
{
	case "$1" in
		3)
			echo 160
			;;
		2)
			echo 80
			;;
		1)
			echo 40
			;;
		0)
			echo 20
			;;
	esac
}

ce_he_get_mcs_nss_bitmap()
{
	local str="$1"
	local rx_nss=$ce_rx_nss
	local i=1
	local bitmap=$(( 0xffff ))

	while [ $i -le $rx_nss ]; do
		curr_val=$(echo "$str" | awk -F',' -v n=$i '{print $n}')

		case $curr_val in
		7)
			curr_val=0
			;;
		9)
			curr_val=1
			;;
		11)
			curr_val=2
			;;
		*)
			curr_val=3
			;;
		esac

		bitmap=$(( ($bitmap & ~(3 << (2 * (i - 1)))) | ($curr_val << (2 * (i - 1))) ))
		i=$(( i+1 ))
	done

	bitmap=$(( $bitmap & 0xffff ))
	echo $bitmap
}

set_5ghz_oper()
{
	case "$channel_bandwidth" in
		0) # 20 MHz
			vht_oper_chwidth=0
			he_oper_chwidth=0
			;;
		1) # 20/40 MHz
			vht_oper_chwidth=0
			he_oper_chwidth=0
			;;
		2) # 20/40/80 MHz
			vht_oper_chwidth=1
			he_oper_chwidth=1
			case "$channel" in
				36|40|44|48)
					vht_oper_centr_freq_seg0_idx=42
					he_oper_centr_freq_seg0_idx=42
					;;
				52|56|60|64)
					vht_oper_centr_freq_seg0_idx=58
					he_oper_centr_freq_seg0_idx=58
					;;
				100|104|108|112)
					vht_oper_centr_freq_seg0_idx=106
					he_oper_centr_freq_seg0_idx=106
					;;
				116|120|124|128)
					vht_oper_centr_freq_seg0_idx=122
					he_oper_centr_freq_seg0_idx=122
					;;
				132|136|140|144)
					vht_oper_centr_freq_seg0_idx=138
					he_oper_centr_freq_seg0_idx=138
					;;
				149|153|157|161)
					vht_oper_centr_freq_seg0_idx=155
					he_oper_centr_freq_seg0_idx=155
					;;
			esac
			;;
		3) # 20/40/80/160 MHz
			vht_oper_chwidth=2
			he_oper_chwidth=2
			case "$channel" in
				36|40|44|48|52|56|60|64)
					vht_oper_centr_freq_seg0_idx=50
					he_oper_centr_freq_seg0_idx=42
					he_oper_centr_freq_seg1_idx=50
					;;
				100|104|108|112|116|120|124|128)
					vht_oper_centr_freq_seg0_idx=114
					he_oper_centr_freq_seg0_idx=106
					he_oper_centr_freq_seg1_idx=114
					;;
			esac
			;;
		esac
}

set_6ghz_he_oper()
{
	case "$channel_bandwidth" in
		0) # 20 MHz
			he_oper_chwidth=0
			;;
		1) # 20/40 MHz
			he_oper_chwidth=0
			case "$channel" in
				1|5)
					he_oper_centr_freq_seg0_idx=3
					;;
				9|13)
					he_oper_centr_freq_seg0_idx=11
					;;
				17|21)
					he_oper_centr_freq_seg0_idx=19
					;;
				25|29)
					he_oper_centr_freq_seg0_idx=27
					;;
				33|37)
					he_oper_centr_freq_seg0_idx=35
					;;
				41|45)
					he_oper_centr_freq_seg0_idx=43
					;;
				49|53)
					he_oper_centr_freq_seg0_idx=51
					;;
				57|61)
					he_oper_centr_freq_seg0_idx=59
					;;
				65|69)
					he_oper_centr_freq_seg0_idx=67
					;;
				73|77)
					he_oper_centr_freq_seg0_idx=75
					;;
				81|85)
					he_oper_centr_freq_seg0_idx=83
					;;
				89|93)
					he_oper_centr_freq_seg0_idx=91
					;;
				97|101)
					he_oper_centr_freq_seg0_idx=99
					;;
				105|109)
					he_oper_centr_freq_seg0_idx=107
					;;
				113|117)
					he_oper_centr_freq_seg0_idx=115
					;;
				121|125)
					he_oper_centr_freq_seg0_idx=123
					;;
				129|133)
					he_oper_centr_freq_seg0_idx=131
					;;
				137|141)
					he_oper_centr_freq_seg0_idx=139
					;;
				145|149)
					he_oper_centr_freq_seg0_idx=147
					;;
				153|157)
					he_oper_centr_freq_seg0_idx=155
					;;
				161|165)
					he_oper_centr_freq_seg0_idx=163
					;;
				169|173)
					he_oper_centr_freq_seg0_idx=171
					;;
				177|181)
					he_oper_centr_freq_seg0_idx=179
					;;
				185|189)
					he_oper_centr_freq_seg0_idx=187
					;;
				193|197)
					he_oper_centr_freq_seg0_idx=195
					;;
				201|205)
					he_oper_centr_freq_seg0_idx=203
					;;
				209|213)
					he_oper_centr_freq_seg0_idx=211
					;;
				217|221)
					he_oper_centr_freq_seg0_idx=219
					;;
				225|229)
					he_oper_centr_freq_seg0_idx=227
					;;
				233)
					he_oper_centr_freq_seg0_idx=233
					;;
			esac
			;;
		2) # 20/40/80 MHz
			he_oper_chwidth=1
			case "$channel" in
				1|5|9|13)
					he_oper_centr_freq_seg0_idx=7
					;;
				17|21|25|29)
					he_oper_centr_freq_seg0_idx=23
					;;
				33|37|41|45)
					he_oper_centr_freq_seg0_idx=39
					;;
				49|53|57|61)
					he_oper_centr_freq_seg0_idx=55
					;;
				65|69|73|77)
					he_oper_centr_freq_seg0_idx=71
					;;
				81|85|89|93)
					he_oper_centr_freq_seg0_idx=87
					;;
				97|101|105|109)
					he_oper_centr_freq_seg0_idx=103
					;;
				113|117|121|125)
					he_oper_centr_freq_seg0_idx=119
					;;
				129|133|137|141)
					he_oper_centr_freq_seg0_idx=135
					;;
				145|149|153|157)
					he_oper_centr_freq_seg0_idx=151
					;;
				161|165|169|173)
					he_oper_centr_freq_seg0_idx=167
					;;
				177|181|185|189)
					he_oper_centr_freq_seg0_idx=183
					;;
				193|197|201|205)
					he_oper_centr_freq_seg0_idx=199
					;;
				209|213|217|221)
					he_oper_centr_freq_seg0_idx=215
					;;
				225|229|233)
					he_oper_centr_freq_seg0_idx=231
					;;
			esac
			;;
			3) # 20/40/80/160 MHz
				he_oper_chwidth=2
				case "$channel" in
					1|5|9|13)
						he_oper_centr_freq_seg0_idx=7
						he_oper_centr_freq_seg1_idx=15
						;;
					17|21|25|29)
						he_oper_centr_freq_seg0_idx=23
						he_oper_centr_freq_seg1_idx=15
						;;
					33|37|41|45)
						he_oper_centr_freq_seg0_idx=39
						he_oper_centr_freq_seg1_idx=47
						;;
					49|53|57|61)
						he_oper_centr_freq_seg0_idx=55
						he_oper_centr_freq_seg1_idx=47
						;;
					65|69|73|77)
						he_oper_centr_freq_seg0_idx=71
						he_oper_centr_freq_seg1_idx=79
						;;
					81|85|89|93)
						he_oper_centr_freq_seg0_idx=87
						he_oper_centr_freq_seg1_idx=79
						;;
					97|101|105|109)
						he_oper_centr_freq_seg0_idx=103
						he_oper_centr_freq_seg1_idx=111
						;;
					113|117|121|125)
						he_oper_centr_freq_seg0_idx=119
						he_oper_centr_freq_seg1_idx=111
						;;
					129|133|137|141)
						he_oper_centr_freq_seg0_idx=135
						he_oper_centr_freq_seg1_idx=143
						;;
					145|149|153|157)
						he_oper_centr_freq_seg0_idx=151
						he_oper_centr_freq_seg1_idx=143
						;;
					161|165|169|173)
						he_oper_centr_freq_seg0_idx=167
						he_oper_centr_freq_seg1_idx=175
						;;
					177|181|185|189)
						he_oper_centr_freq_seg0_idx=183
						he_oper_centr_freq_seg1_idx=175
						;;
					193|197|201|205)
						he_oper_centr_freq_seg0_idx=199
						he_oper_centr_freq_seg1_idx=207
						;;
					209|213|217|221)
						he_oper_centr_freq_seg0_idx=215
						he_oper_centr_freq_seg1_idx=207
						;;
				esac
				;;
			esac
}

is_he_enabled()
{
	local wlan_idx=$1
	local mode="$(NVG tcv${wlan_idx} ce_wireless_mode 3)"

	if [ $mode -ge 3 ]; then
		echo "1"
	else
		echo "0"
	fi
}

configure_hostapd()
{
	local chip_idx=$1
	local tcv_idx=$2
	local bss_idx=$3
	local wlan_idx=$(($chip_idx*2+$tcv_idx))
	local i=$(( bss_idx+1 ))
	local wlan_int="wlan${wlan_idx}_${bss_idx}"
	local conf=${UTILS_CONFIG_FOLDER}/"hostapd_tcv${wlan_idx}.conf"
	local ctrl_interface=${UTILS_CONFIG_FOLDER}/hostapd
	local SSID="$(NVG tcv${wlan_idx} ha_ssid$i "CL6K_AP"${wlan_idx}"_"$bss_idx"")"
	local basic_ht_mcs="$(NVG tcv${wlan_idx} ha_basic_ht_mcs$i)"
	local disabled_ht_mcs="$(NVG tcv${wlan_idx} ha_disabled_ht_mcs$i)"
	local he_basic_mcs_nss_set="$(NVG tcv${wlan_idx} ha_he_basic_mcs_nss_set$i)"
	local hw_mode="$(NVG tcv${wlan_idx} ha_hw_mode)"
	local ci_band_num="$(NVG tcv${wlan_idx} ci_band_num)"

	if [ ! -f $conf ]; then
		cp -f $cl_install_dir/config/hostapd-template.conf $conf
		hostapd_conf_files="$hostapd_conf_files $conf"
		sed -i "1s/^/interface=$wlan_int\n/" $conf
		local wpa_val=0
		local wpa_key_mgmt=""
		local country_code="$(NVG chip$chip_idx ce_country_code)"
		local ieee80211d="$(NVG tcv${wlan_idx} ha_ieee80211d 0)"
		local ieee80211h="$(NVG tcv${wlan_idx} ha_ieee80211h 0)"
		local basic_rates="$(NVG tcv${wlan_idx} ha_basic_rates)"
		local supported_rates="$(NVG tcv${wlan_idx} ha_supported_rates)"
		local uapsd_en="$(NVG tcv${wlan_idx} ce_uapsd_en 1)"
		local channel="$(NVG tcv${wlan_idx} ha_channel)"
		local channel_bandwidth="$(NVG tcv${wlan_idx} ce_channel_bandwidth)"
		if [ "$is_reload" == "1" -a -n "${reload_channel[$wlan_idx]}" ]; then
			channel=${reload_channel[$wlan_idx]}
			channel_bandwidth="$(bandwidth_to_idx ${reload_bw[$wlan_idx]})"
		fi
		local stbc="$(NVG tcv${wlan_idx} ha_stbc 0)"
		local ap_pincode="$(NVG tcv${wlan_idx} ha_ap_pin 64013121)"
		local config_methods="$(NVG tcv${wlan_idx} ha_config_methods 2288)"
		local rts_threshold="$(NVG tcv${wlan_idx} ha_rts_threshold 2347)"
		local fragm_threshold="$(NVG tcv${wlan_idx} ha_fragm_threshold 2346)"
		local manufacturer="$(NVG tcv${wlan_idx} ha_manufacturer "Celeno")"
		local model_name="$(NVG tcv${wlan_idx} ha_model_name "CL6K")"
		local device_name="$(NVG tcv${wlan_idx} ha_device_name "$manufacturer $model_name")"
		local model_number="$(NVG tcv${wlan_idx} ha_model_number 20)"
		local serial_number="$(NVG tcv${wlan_idx} ha_serial_number 12345)"
		local device_type="$(NVG tcv${wlan_idx} ha_device_type "6-0050F204-1")"
		local dtim_period="$(NVG tcv${wlan_idx} ha_dtim_period 2)"
		set_key "rts_threshold" "$rts_threshold" 1 $wlan_idx $bss_idx
		set_key "fragm_threshold" "$fragm_threshold" 1 $wlan_idx $bss_idx
		local ht_capab=
		local vht_capab=
		local ce_rx_nss="$(NVG tcv${wlan_idx} ce_rx_nss 4)"
		local ht_oper_centr_freq_seg2_idx=
		local vht_oper_chwidth=0
		local vht_oper_centr_freq_seg0_idx=
		local vht_oper_centr_freq_seg1_idx=
		local he_oper_chwidth=
		local he_oper_centr_freq_seg0_idx=
		local he_oper_centr_freq_seg1_idx=
		local beacon_int="$(NVG tcv${wlan_idx} ha_beacon_int 100)"
		local ap_table_expiration_time="$(NVG tcv${wlan_idx} ha_ap_table_expiration_time 60)"

		case "$hw_mode" in
			0)
				hw_mode="a"
				;;
			1)
				hw_mode="b"
				;;
			2)
				hw_mode="g"
				;;
			3)
				# hw_mode is used for hostapd.conf and it should be equal to b or g only
				hw_mode="g"
				;;
		esac

		set_key "country_code" "$country_code" 1 $wlan_idx $bss_idx
		set_key "ieee80211d" "$ieee80211d" 1 $wlan_idx $bss_idx
		set_key "ieee80211h" "$ieee80211h" 1 $wlan_idx $bss_idx
		set_key "uapsd_advertisement_enabled" "$uapsd_en" 1 $wlan_idx $bss_idx

		if [ $channel_bandwidth -gt 0 ]; then
			local secondary_channel="$(get_secondary_channel ${wlan_idx} $channel)"
			case  "$secondary_channel" in
				-1)
				ht_capab="$ht_capab[HT40-]"
				;;
			1|*)
				ht_capab="$ht_capab[HT40+]"
				;;
			esac
		else
			ht_capab="$ht_capab[HT20]"
		fi

		if [ "$(NVG tcv${wlan_idx} ce_vht_rxldpc_en 1)" == "1" ]; then
			vht_capab="$vht_capab[RXLDPC]"
		fi

		if [ "$(NVG tcv${wlan_idx} ce_ht_rxldpc_en 1)" == "1" ]; then
			ht_capab="$ht_capab[LDPC]"
		fi

		if [ "$ci_band_num" == "5" ]; then
			set_5ghz_oper
		fi

		# 6GHz band configurations
		if [ "$ci_band_num" == "6" ]; then
			set_6ghz_he_oper
			if [ "$channel" == "2" ]; then
				op_class="136"
			else
				op_class=$((131 + $channel_bandwidth))
			fi

			set_key "op_class" $op_class 1 $wlan_idx $bss_idx
		fi

		local ce_bf_en="$(NVG tcv${wlan_idx} ce_bf_en 0)"
		if [ "$ce_bf_en" != "0" ]; then
			vht_capab="$vht_capab[SU-BEAMFORMER]"

			if [ "$(is_he_enabled $wlan_idx)" == "1" ]; then
				set_key "he_su_beamformer" "$he_su_beamformer" 1 $wlan_idx $bss_idx
			fi
		fi

		vht_capab="$vht_capab[SOUNDING-DIMENSION-4]"
		vht_capab="$vht_capab[BF-ANTENNA-4]" 

		local ha_short_guard_interval="$(NVG tcv${wlan_idx} ha_short_guard_interval 1)"
		case "$ha_short_guard_interval" in
			1)
				case "$channel_bandwidth" in
					0)
						ht_capab="$ht_capab[SHORT-GI-20]"
						;;
					1)
						ht_capab="$ht_capab[SHORT-GI-20][SHORT-GI-40]"
						;;
					2)
						ht_capab="$ht_capab[SHORT-GI-20][SHORT-GI-40]"
						vht_capab="$vht_capab[SHORT-GI-80]"
						;;
					3)
						ht_capab="$ht_capab[SHORT-GI-20][SHORT-GI-40]"
						vht_capab="$vht_capab[SHORT-GI-80][VHT160][SHORT-GI-160]"
						;;
				esac
				;;
			*)
				true
				;;
		esac

		local ha_max_mpdu_len="$(NVG tcv${wlan_idx} ha_max_mpdu_len 1)"
		case "$ha_max_mpdu_len" in
			0);;
			1) # 7991 octets
				vht_capab="$vht_capab[MAX-MPDU-7991]"
				;;
			2) # 11454 octets
				vht_capab="$vht_capab[MAX-MPDU-11454]"
				;;
			*)
				echo "Invalid ha_max_mpdu_len value [$ha_max_mpdu_len]"
				;;
		esac

		local ha_vht_max_ampdu_len_exp="$(NVG tcv${wlan_idx} ha_vht_max_ampdu_len_exp 7)"
		if [ $ha_vht_max_ampdu_len_exp -lt 8 ];	then
			vht_capab="$vht_capab[MAX-A-MPDU-LEN-EXP$ha_vht_max_ampdu_len_exp]"
		else
			echo "Invalid ha_vht_max_ampdu_len_exp value [$ha_vht_max_ampdu_len_exp]"
		fi

		if [ $stbc -eq 1 ]; then
			ht_capab="$ht_capab[TX-STBC]"
			vht_capab="$vht_capab[TX-STBC-2BY1]"
		fi

		ht_capab="$ht_capab[DSSS_CCK-40]"

		if [ $ci_band_num -ne 6 ]; then
			set_key "ht_capab" "$ht_capab" 1 $wlan_idx $bss_idx
			set_key "vht_capab" "$vht_capab" 1 $wlan_idx $bss_idx
			set_key "vht_oper_chwidth" "$vht_oper_chwidth" 1 $wlan_idx $bss_idx

			[ -n "$vht_oper_centr_freq_seg0_idx" ] && \
			set_key "vht_oper_centr_freq_seg0_idx" "$vht_oper_centr_freq_seg0_idx" 1 $wlan_idx $bss_idx

			[ -n "$vht_oper_centr_freq_seg1_idx" ] && \
				set_key "vht_oper_centr_freq_seg1_idx" "$vht_oper_centr_freq_seg1_idx" 1 $wlan_idx $bss_idx

			[ -n "$ht_oper_centr_freq_seg2_idx" ] && \
				set_key "ht_oper_centr_freq_seg2_idx" "$ht_oper_centr_freq_seg2_idx" 1 $wlan_idx $bss_idx
		fi

		if [ "$(is_he_enabled $wlan_idx)" == "1" ]; then
			[ -n "$he_oper_chwidth" ] && \
				set_key "he_oper_chwidth" "$he_oper_chwidth" 1 $wlan_idx $bss_idx

			[ -n "$he_oper_centr_freq_seg0_idx" ] && \
				set_key "he_oper_centr_freq_seg0_idx" "$he_oper_centr_freq_seg0_idx" 1 $wlan_idx $bss_idx

			[ -n "$he_oper_centr_freq_seg1_idx" ] && \
				set_key "he_oper_centr_freq_seg1_idx" "$he_oper_centr_freq_seg1_idx" 1 $wlan_idx $bss_idx
		fi

		set_key "channel" "$channel" 1 $wlan_idx $bss_idx
		set_key "hw_mode" "$hw_mode" 1 $wlan_idx $bss_idx
		set_key "beacon_int" "$beacon_int" 1 $wlan_idx $bss_idx
		set_key "ap_pin" "$ap_pincode" 1 $wlan_idx $bss_idx
		set_wps_config_methods "$config_methods"
		set_key "config_methods" "$config_methods_hostapd" 1 $wlan_idx $bss_idx
		set_key "device_name" "$device_name" 1 $wlan_idx $bss_idx
		set_key "manufacturer" "$manufacturer" 1 $wlan_idx $bss_idx
		set_key "model_name" "$model_name" 1 $wlan_idx $bss_idx
		set_key "model_number" "$model_number" 1 $wlan_idx $bss_idx
		set_key "serial_number" "$serial_number" 1 $wlan_idx $bss_idx
		set_key "device_type" "$device_type" 1 $wlan_idx $bss_idx
		set_key "dtim_period" "$dtim_period" 1 $wlan_idx $bss_idx

		if [ -n "$basic_rates" ]; then
			set_key "basic_rates" "$basic_rates" 1 $wlan_idx $bss_idx
		fi
		if [ -n "$supported_rates" ]; then
			set_key "supported_rates" "$supported_rates" 1 $wlan_idx $bss_idx
		fi

		if [ "x$ap_table_expiration_time" != "x" ];then
			set_key "ap_table_expiration_time" "$ap_table_expiration_time" 1 $wlan_idx $bss_idx
		fi

		set_wireless_mode $wlan_idx $ci_band_num
	else
		echo -e "\n" >> $conf
		add_key "bss" $wlan_int $wlan_idx
	fi

	# MBSS configuration
	local obss_interval="$(NVG tcv${wlan_idx} ha_obss_interval "0,0,0,0,0,0,0,0" | awk -F',' -v n=$i '{print $n}')"
	local ignore_broadcast_ssid="$(NVG tcv${wlan_idx} ha_ignore_broadcast_ssid "0,0,0,0,0,0,0,0" | awk -F',' -v n=$i '{print $n}')"
	local max_num_sta="$(NVG tcv${wlan_idx} ha_max_num_sta "255,255,255,255,255,255,255,255" | awk -F',' -v n=$i '{print $n}')"
	ha_auth_mode="$(NVG tcv${wlan_idx} ha_auth_mode | awk -F',' -v n=$i '{print $n}')"
	ha_encrypt_type="$(NVG tcv${wlan_idx} ha_encrypt_type | awk -F',' -v n=$i '{print $n}')"
	echo "Configuring $conf for ${wlan_int}: Encryption $ha_encrypt_type Auth $ha_auth_mode"
	local rrm_neighbor_report="$(NVG tcv${wlan_idx} ha_rrm_neighbor_report "0,0,0,0,0,0,0,0" | awk -F',' -v n=$i '{print $n}')"
	local rrm_beacon_report="$(NVG tcv${wlan_idx} ha_rrm_beacon_report "0,0,0,0,0,0,0,0" | awk -F',' -v n=$i '{print $n}')"
	local rnr="$(NVG tcv${wlan_idx} ha_rnr "0,0,0,0,0,0,0,0" | awk -F',' -v n=$i '{print $n}')"
	local ieee80211v="$(NVG tcv${wlan_idx} ha_ieee80211v_en "0,0,0,0,0,0,0,0" | awk -F',' -v n=$i '{print $n}')"
	local ieee80211r="$(NVG tcv${wlan_idx} ha_ieee80211r_en "0,0,0,0,0,0,0,0" | awk -F',' -v n=$i '{print $n}')"
	local ft_mobility_domain="$(NVG tcv${wlan_idx} ha_ft_mobility_domain "a1b2")"
	local bridge="$(NVG tcv${wlan_idx} ws_bridge "br0")"
	local nas_identifier="$(NVG tcv${wlan_idx} ha_nas_identifier | awk -F',' -v n=$i '{print $n}')"
	if [ -z "$nas_identifier" ]; then
		nas_identifier="ap$i.example.com"
	fi
	local r1_key_holder="$(NVG tcv${wlan_idx} ha_r1_key_holder 000102030405)"
	local pmk_r1_push="$(NVG tcv${wlan_idx} ha_pmk_r1_push 1)"
	local ft_psk_generate_local="$(NVG tcv${wlan_idx} ha_ft_psk_generate_local 1)"
	local ft_over_ds="$(NVG tcv${wlan_idx} ha_ft_over_ds 1)"
	ft_clients_only="$(NVG tcv${wlan_idx} ha_ft_clients_only 1)"
	local he_bss_color="$(NVG tcv${wlan_idx} ha_he_bss_color 0)"
	local disable_11n="$(NVG tcv${wlan_idx} ha_disable_11n "0,0,0,0,0,0,0,0" | awk -F',' -v n=$i '{print $n}')"
	local disable_11ac="$(NVG tcv${wlan_idx} ha_disable_11ac "0,0,0,0,0,0,0,0" | awk -F',' -v n=$i '{print $n}')"
	local disable_11ax="$(NVG tcv${wlan_idx} ha_disable_11ax "0,0,0,0,0,0,0,0" | awk -F',' -v n=$i '{print $n}')"

	set_key "ctrl_interface" "$ctrl_interface" 1 $wlan_idx $bss_idx
	set_key "ssid" "$SSID" 1 $wlan_idx $bss_idx

	if [ -n "$he_basic_mcs_nss_set" ]; then
		he_mcs_nss_bitmap=$(ce_he_get_mcs_nss_bitmap "$he_basic_mcs_nss_set")
		set_key "he_basic_mcs_nss_set" $(( he_mcs_nss_bitmap )) 1 $wlan_idx $bss_idx
	fi

	if [ $disable_11n -eq 1 ]; then
		set_key "disable_11n" "$disable_11n" 1 $wlan_idx $bss_idx
	fi

	if [ $disable_11ac -eq 1 ]; then
		set_key "disable_11ac" "$disable_11ac" 1 $wlan_idx $bss_idx
	fi

	if [ $disable_11ax -eq 1 ]; then
		set_key "disable_11ax" "$disable_11ax" 1 $wlan_idx $bss_idx
	fi

	if [ "$ieee80211r" = "1" ]; then
		set_key "bridge" "$bridge" 1 $wlan_idx $bss_idx

		for i in $(seq 0 1 16); do
			r0kh="$(NVG tcv${wlan_idx} ha_r0kh$i)"
			r1kh="$(NVG tcv${wlan_idx} ha_r1kh$i)"

			if [ "x$r0kh" != "x" ]; then
				add_key "r0kh" "$r0kh" 1 $bss_idx $wlan_idx
			fi

			if [ "x$r1kh" != "x" ]; then
				add_key "r1kh" "$r1kh" 1 $bss_idx $wlan_idx
			fi
		done

		set_key "mobility_domain" "$ft_mobility_domain" 1 $wlan_idx $bss_idx
		set_key "nas_identifier" "$nas_identifier" 1 $wlan_idx $bss_idx
		set_key "r1_key_holder" "$r1_key_holder" 1 $wlan_idx $bss_idx
		set_key "pmk_r1_push" "$pmk_r1_push" 1 $wlan_idx $bss_idx
		set_key "ft_psk_generate_local" "$ft_psk_generate_local" 1 $wlan_idx $bss_idx
		set_key "ft_over_ds" "$ft_over_ds" 1 $wlan_idx $bss_idx
	fi

	set_key "ignore_broadcast_ssid" "$ignore_broadcast_ssid" 1 $wlan_idx $bss_idx
	set_key "max_num_sta" "$max_num_sta" 1 $wlan_idx $bss_idx
	set_key "obss_interval" "$obss_interval" 1 $wlan_idx $bss_idx
	set_key "bss_transition" "$ieee80211v" 1 $wlan_idx $bss_idx

	if [ "$rrm_neighbor_report" = "1" ]; then
		set_key "rrm_neighbor_report" "$rrm_neighbor_report" 1 $wlan_idx $bss_idx
	fi
	if [ "$rrm_beacon_report" = "1" ]; then
		set_key "rrm_beacon_report" "$rrm_beacon_report" 1 $wlan_idx $bss_idx
	fi

	set_security_hostpad_conf $wlan_idx $bss_idx

	local wps_rf_bands=ag
	set_key "wps_rf_bands" "$wps_rf_bands" 1 $wlan_idx $bss_idx

	local ap_setup_locked=0
	set_key "ap_setup_locked" "$ap_setup_locked" 1 $wlan_idx $bss_idx

	wps="$(NVG tcv${wlan_idx} ha_wps_state "2,0,0,0,0,0,0,0" | awk -F',' -v n=$i '{print $n}')"

	if [ $wps -ne 0 ]; then
		local bridge_name="$(NVG tcv${wlan_idx} ha_upnp_iface "br0")"
		ap_setup_locked="$(NVG tcv${wlan_idx} ha_ap_setup_locked | awk -F',' -v n=$i '{print $n}')"

		set_key "wps_state" ${wps} 1 $wlan_idx $bss_idx
		set_key "ap_setup_locked" "$ap_setup_locked" 1 $wlan_idx $bss_idx

		if [ -n "$bridge_name" ] && [ -d /sys/class/net/$bridge_name ] && ifconfig $bridge_name 2>/dev/null | grep -q 'inet addr'
		then
			# "operstate's" value will be "up" only if any interface is included in the bridge.
			# Such it may occur the situation when there's no interfaces included, which
			# may cause errors with uPnP packets.

			set_key "upnp_iface" "$bridge_name" 1 $wlan_idx $bss_idx
			set_key "friendly_name" "WPS Access Point" 1 $wlan_idx $bss_idx
		fi
	else
		set_key "wps_state" "0" 1 $wlan_idx $bss_idx
	fi

	local UUID="$(NVG chip$chip_idx uuid1)"
	if [ -n "$UUID" ]; then
		set_key "uuid" "$UUID" 1 $wlan_idx $bss_idx
	fi

	local wmm_enabled="$(NVG tcv${wlan_idx} ha_wmm_enabled "1,1,1,1,1,1,1,1" | awk -F',' -v n=$i '{print $n}')"
	set_key "wmm_enabled" "$wmm_enabled" 1 $wlan_idx $bss_idx

	if [ "$wmm_enabled" = "1" ]; then
		local wmm_bss_aifsn="$(NVG tcv${wlan_idx} ha_wmm_bss_aifsn "3,7,2,2")"
		local wmm_bss_cwmin="$(NVG tcv${wlan_idx} ha_wmm_bss_cwmin "4,4,3,2")"
		local wmm_bss_cwmax="$(NVG tcv${wlan_idx} ha_wmm_bss_cwmax "10,10,4,3")"
		local wmm_bss_txop="$(NVG tcv${wlan_idx} ha_wmm_bss_txop "0,0,94,47")"
		local wmm_bss_acm="$(NVG tcv${wlan_idx} ha_wmm_bss_acm "0,0,0,0")"
		local ac

		for ac in 1 2 3 4 ; do
			local prio=
			case $ac in
				1) prio=be ;;
				2) prio=bk ;;
				3) prio=vi ;;
				4) prio=vo ;;
			esac
			set_key "wmm_ac_${prio}_aifs" "$(echo "$wmm_bss_aifsn" | awk -F',' -v n=$ac '{print $n}')" 1 $wlan_idx $bss_idx
			set_key "wmm_ac_${prio}_cwmin" "$(echo "$wmm_bss_cwmin" | awk -F',' -v n=$ac '{print $n}')" 1 $wlan_idx $bss_idx
			set_key "wmm_ac_${prio}_cwmax" "$(echo "$wmm_bss_cwmax" | awk -F',' -v n=$ac '{print $n}')" 1 $wlan_idx $bss_idx
			set_key "wmm_ac_${prio}_txop_limit" "$(echo "$wmm_bss_txop" | awk -F',' -v n=$ac '{print $n}')" 1 $wlan_idx $bss_idx
			set_key "wmm_ac_${prio}_acm" "$(echo "$wmm_bss_acm" | awk -F',' -v n=$ac '{print $n}')" 1 $wlan_idx $bss_idx
		done
	fi
	set_he_mu_edca_conf $wlan_idx $bss_idx

	if [ "$ha_auth_mode" = "WPA2" -o "$ha_auth_mode" = "WPA3" -o "$ha_auth_mode" = "WPA3SAE" -o "$ha_auth_mode" = "WPA2PSK" -o "$ha_auth_mode" = "WPAPSKWPA2PSK" ]; then
		set_pmf_hostpad_conf $wlan_idx $bss_idx $ha_auth_mode
	fi

	apply_acl $wlan_idx $bss_idx

	if [ $he_bss_color -ne 0 ]; then
		set_key "he_bss_color" "$he_bss_color" 1 $wlan_idx $bss_idx
	fi

	if [ -n "$basic_ht_mcs" ]; then
		set_key "basic_ht_mcs" "$basic_ht_mcs" 1 $wlan_idx $bss_idx
	fi

	if [ -n "$disabled_ht_mcs" ]; then
		set_key "disabled_ht_mcs" "$disabled_ht_mcs" 1 $wlan_idx $bss_idx
	fi

	if [ $rnr -eq 1 ]; then
		set_key "rnr" "$rnr" 1 $wlan_idx $bss_idx
	fi

	# Enable/disable RADIUS
	set_key "ieee8021x" "$ieee8021x" 1 $wlan_idx $bss_idx

	if [ "$ieee8021x" = "1" ]; then
		set_radius_configuration $wlan_idx $bss_idx
		set_key "eap_server" "0" 1 $wlan_idx $bss_idx
	else
		set_key "eap_server" "1" 1 $wlan_idx $bss_idx
	fi

	set_key "forward_id_enable" "$(NVG tcv${wlan_idx} ha_forward_id 0)" 1 $wlan_idx $bss_idx

	local ha_wps_win7_support="$(NVG tcv${wlan_idx} ha_wps_win7_support 1)"
	if [ "$ha_wps_win7_support" = 1 ]; then
		set_key ha_wps_win7_support "$ha_wps_win7_support" 1 $wlan_idx $bss_idx
	fi
}

update_channels()
{
	local chip_idx=$1
	if [ "$production_mode" = "1" ]; then
		return 1
	fi

	channel_info_file=$cl_install_dir/"config/channel_info.txt"

	if [ ! -r $channel_info_file ]; then
		return 1
	fi

	out_sep=";"
	bw_sep="#"
	country_code="$(NVG chip$chip_idx ce_country_code)"

	channels_24g=$(sed -n '/\[[[:space:]]*'${country_code}'[[:space:]]*[[:punct:]].*\]/,/\[/ {
		/2.4GHz\/\([[:digit:]]\+\)MHz/ {
		s/[[:space:]*]//g;
		s/)[^(]*(/ /g;
		s/2.4GHz\/\([[:digit:]]\+\)MHz.*(\(.*\)).*$/\1(\2)/;
		/,/ s/ /'${out_sep}'/g;
		/,/ ! s/ /,/g;p
		}
		}' < "$channel_info_file")

	channels_24g=$(echo $channels_24g | sed 's/ /'${bw_sep}'/g')

	export ce_channel_info_txt_24g=$channels_24g
}

configure_interfaces()
{
	local chip_idx=$1

	if [ "$(get_tcv_enabled $chip_idx 0)" == "0" ]; then
		return
	fi

	if [ ! -f /var/run/cl6k_chip$chip_idx.ini ]; then
		return
	fi

	local wlan_idx=$(($chip_idx*2))
	local AP="wlan${wlan_idx}"_
	local j=1
	local retry_cnt=0
	local max_retry_cnt=20
	local bss_num="$(NVG tcv${wlan_idx} ce_bss_num)"
	local noack_map="$(NVG tcv${wlan_idx} ce_noack_map "0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0")"

	while [ "$j" -le "$bss_num" ]; do
		local wlan_int="${AP}$(( j-1 ))"
		if [ "$(get_iface_type $wlan_idx $(( j-1 )))" != "3" ]; then
			j=$(( j+1 ))
			continue
		fi

		while [ "$(cat /sys/class/net/${wlan_int}/operstate)" != "up" ]; do
			sleep 1
			retry_cnt=$(( retry_cnt + 1 ))
			if [ $retry_cnt -eq $max_retry_cnt ]; then
				echo "retry_cnt=$retry_cnt and ${wlan_int} is not up - exit 1"
				action_stop
				exit 1
			fi
		done

		# Configure noack map per BSS
		local noack_val=`echo $noack_map | awk -F',' -v n=$j '{print $n}'`
		$IW ${wlan_int} set noack_map $noack_val

		j=$(( j+1 ))
	done
}

configure_bt_config()
{
	local chip_idx=$1
	local ce_bt_mode="$(NVG chip${chip_idx} ce_bt_mode 0)"
	if [ -x "$cl_install_dir/bin/cl_bt_config" -a "$ce_bt_mode" -gt 0 ] ; then
		$cl_install_dir/bin/cl_bt_config $cl_cfg_dir/cl_chip${chip_idx}_bt.dat \
			$cl_install_dir/firmware/bt_config_${chip_idx}.bin \
			$cl_install_dir/firmware/bt_nvram.csv
		ln -sf $cl_install_dir/firmware/bt_config_${chip_idx}.bin $LIB_FW_PATH/
		ln -sf $cl_cfg_dir/cl_chip${chip_idx}_bt.dat $LIB_FW_PATH/cl_chip${chip_idx}_bt.dat
	fi
}

init_lcu()
{
	local chip_idx=$1
	local lcu_conf_file="$(NVG chip$chip_idx ce_ela_mode "OFF")"
	local dbg_dir="$cl_install_dir/scripts/dbg"

	if [ "$lcu_conf_file" == "OFF" ] ; then
		echo "LCU disabled"
		return
	fi

	if [ "$lcu_conf_file" == "default" ]; then
		lcu_conf_file=$(basename $(ls -la ${dbg_dir}/lcu_default.conf | awk '{print $NF}'))
	fi

	# Read lcu conf file name into an array - tokens separated by "_"
	IFS='_' read -ra ARR <<< $(basename "$lcu_conf_file")

	[ "${ARR[0]}" != "lcu" ] && echo "unexpected config file prefix [${ARR[0]}], abort ..."

	case "${ARR[1]}" in
		"mac"|"phy"|"bt") lcu_mode="${ARR[1]}" ;;
		?"mac") lcu_mode="${ARR[1]}" ;;
		*) echo "unexpected config file mode [${ARR[1]}], abort ..." ;;
	esac

	# Remember active lcu mode
	echo "$lcu_mode" > /var/run/lcu"$chip_idx".mode
	# Remember active lcu config
	ln -sf ${dbg_dir}/${lcu_conf_file} /var/run/lcu"$chip_idx".conf
}

bring_interfaces_up()
{
	local chip_idx=$1
	local retry_cnt=0
	local max_retry_cnt=

	if [ "$CL_HW_MODEL" == "CL_ASIC" ]; then
		max_retry_cnt=20
	else
		max_retry_cnt=80
	fi

	if [ "$(get_tcv_enabled $chip_idx 0)" == "0" ]; then
		return
	fi

	local wlan_idx=$(($chip_idx*2))
	local AP="wlan${wlan_idx}"_
	local bss_num="$(NVG tcv${wlan_idx} ce_bss_num)"
	local ap_added_per_tcv=0

	while [ ! -d /sys/kernel/debug/ieee80211/chip${chip_idx}/cl/cl6k/ ]; do
		sleep 1
		retry_cnt=$(( retry_cnt + 1 ))
		if [ $retry_cnt -eq $max_retry_cnt ]; then
			echo "retry_cnt=$retry_cnt and no /sys/kernel/debug/ieee80211/chip${chip_idx}/cl/cl6k/ - exit 1"
			exit 1
		fi
	done

	echo "retry_cnt=$retry_cnt - found /sys/kernel/debug/ieee80211/chip${chip_idx}/cl/cl6k/"

	local j=0
	while [ "$j" -lt "$bss_num" ]; do
		local iface_type=$(get_iface_type $wlan_idx $j)
		if [ "$iface_type" == "3" ]; then
			configure_hostapd $chip_idx 0 $j
			if [ "$ap_added_per_tcv" -eq "0" ]; then
				$IW chip${chip_idx} interface add ${AP}${j} type __ap
				ap_added_per_tcv=1
			fi
		elif [ "$iface_type" == "2" ]; then
			if [ "$j" -eq "0" ]; then
				echo "STA Mode - set ${AP}${j} as STA"
			elif [ "$j" -eq "1" -a "$ap_added_per_tcv" -eq "1" ]; then
				echo "Repeater Mode - set ${AP}${j} as STA"
			else
				echo "Wrong configuration - ${AP}${j} cannot be STA"
				break
			fi
			$IW chip${chip_idx} interface add ${AP}${j} type station
			configure_supplicant $chip_idx 0 $j
			break
		elif [ "$iface_type" == "7" ]; then
			local bandwidth_idx="$(NVG tcv${wlan_idx} ce_channel_bandwidth 0)"
			local bandwidth="$(idx_to_bandwidth ${bandwidth_idx})"
			local channel="$(NVG tcv${wlan_idx} ha_channel)"
			local ssid="$(NVG tcv${wlan_idx} ws_ssid)"
			echo "Set ${AP}${j} as MESH $ssid"
			$IW chip${chip_idx} interface add ${AP}${j} type mp mesh_id $ssid
			$IW dev ${AP}${j} set channel $channel ${bandwidth}MHz
			configure_supplicant $chip_idx 0 $j
			break
		fi
		j=$(( j+1 ))
	done
}

pre_configure()
{
	local chip_idx=$1
	local bt_mode=$(NVG chip$chip_idx ce_bt_mode 0)
	NVS chip$chip_idx ce_production_mode 0 $production_mode
	NVS chip$chip_idx ce_lmac "lmacfw.bin" "lmacfw.bin"

	# Do not start bluetooth over USB if WIFI over PCIe
	if [ "$wifi_mode" == "PCI" ] && \
		 [ "$bt_mode" = "2" ]; then
		echo "Wrong configuration: BT over USB + WIFI over PCIe, aborting ..."
		exit 1
	fi

	if [ "$bt_mode" = "0" ]; then
		NVS chip$chip_idx ce_smac "no_load" "no_load"
	elif [ "$bt_mode" = "1" ]; then
		NVS chip$chip_idx ce_smac "no_load" "smacfw.bin"
		NVS chip${chip_idx}_bt pf_cfg_pf_transport_type 0 1
	elif [ "$bt_mode" = "2" ]; then
		NVS chip$chip_idx ce_smac "no_load" "smacfw.bin"
		NVS chip${chip_idx}_bt pf_cfg_pf_transport_type  0 2
	else
		echo "Wrong configuration bt_mode: aborting ..."
		exit 1
	fi

	if [ "$wifi_mode" == "USB" ]; then
		NVS chip$chip_idx ce_umac "umacfw.bin" "umacfw.bin"
	else
		NVS chip$chip_idx ce_umac "no_load" "no_load"
	fi

	configure_bt_config $chip_idx
}

post_configure()
{
	local chip_idx=$1
	local twin_peak="$(NVG chip$chip_idx ci_twin_peak_mode 0)"
	if [ "$production_mode" = "1" ]; then
		return
	fi
	if [ "$(get_tcv_enabled $chip_idx 0)" == "0" ]; then
		return
	fi

	if [ ! -f /var/run/cl6k_chip$chip_idx.ini ]; then
		return
	fi

	local wlan_idx=$(($chip_idx*2))
	local AP="wlan${wlan_idx}"_
	local bss_num="$(NVG tcv${wlan_idx} ce_bss_num)"
	local j=0

	while [ "$j" -lt "$bss_num" ]; do
		local iface_type="$(get_iface_type $wlan_idx $j)"
		local wlan_int="${AP}$j"
		if [ "$iface_type" -eq "0" ]; then
			ifconfig $wlan_int down 2>/dev/null
		fi

		j=$(( j+1 ))
	done

	if [ "$(NVG chip$chip_idx ci_phy_dev)" -le 1 -a $twin_peak -ne 1 ]; then
		$cl_install_dir/scripts/bridge.sh $chip_idx $wlan_idx
	fi
}

start_production()
{
	local chip_idx=$1
	local retry_cnt=0
	local max_retry_cnt=80

	if [ "$(get_tcv_enabled $chip_idx 0)" == "0" ]; then
		return
	fi

	local wlan_idx=$(($chip_idx*2))
	local AP="wlan${wlan_idx}_0"

	while [ ! -d /sys/kernel/debug/ieee80211/chip${chip_idx}/cl/cl6k/ ]; do
		sleep 1
		retry_cnt=$(( retry_cnt + 1 ))
		if [ $retry_cnt -eq $max_retry_cnt ]; then
			echo "retry_cnt=$retry_cnt and no /sys/kernel/debug/ieee80211/chip${chip_idx}/cl/cl6k/ - exit 1"
			exit 1
		fi
	done

	echo "retry_cnt=$retry_cnt - found /sys/kernel/debug/ieee80211/chip${chip_idx}/cl/cl6k/"

	$IW chip${chip_idx} interface add ${AP} type station
	ip link set dev ${AP} up

	echo "[ce_host] Finished loading the driver (production)"
}

do_start()
{
	local chip_idx=$1
	if [ "$(NVG chip$chip_idx ce_litepath_en 0)" = "1" ]; then
		if [ -f /lib/modules/puma_lpal.ko ];then
			lsmod | grep -q puma_lpal
			if [ $? -eq 1 ];then
				echo "trying to insmod puma_lpal.ko"
				insmod /lib/modules/puma_lpal.ko
			fi
		else
			echo "ERROR: ce_litepath_en=1 while puma_lpal.ko is missing - litepath is not supported in SDK"
		fi
	fi

	if [ "$(NVG chip$chip_idx ci_lttng_trace_en 0)" = "1" ]; then
		$cl_install_dir/scripts/trace_start.sh
	fi

	load_the_driver

	init_lcu $chip_idx

	if [ "$production_mode" = "0" ]; then
		bring_interfaces_up $chip_idx
	else
		start_production $chip_idx
	fi

	local telnetd_enable="$(NVG chip$chip_idx ci_telnetd_enable 0)"
	if [ "$telnetd_enable" = "1" ]; then
		telnetd >/dev/null 2>/dev/null
	fi
}

is_iface_up()
{
	local chip_idx=$1
	local wlans=$(grep ".*wlan" /proc/net/dev | sed -e 's/:.*$//')
	local wlan_idx0=$(($chip_idx*2))
	local wlan_idx1=$(($chip_idx*2+1))

	if [ `echo ${wlans} | grep -c "wlan${wlan_idx0}"` -eq 0 -a `echo ${wlans} | grep -c "wlan${wlan_idx1}"` -eq 0 ]; then
		echo "0"
	else
		echo "1"
	fi
}

do_stop()
{
	local chip_idx=$1
	# Check that chip is up
	if [ "$(is_iface_up $chip_idx)" == "1" ] ; then
		bring_interfaces_down $chip_idx
		rm -f /var/run/lcu"$chip_idx".conf 2>/dev/null
		rm -f /var/run/lcu"$chip_idx".mode 2>/dev/null
	fi
}

do_remove()
{
	killall cl_netlink > /dev/null

	if [ `ps | grep -v grep | grep -c trace_start.sh` -gt 0 ];
	then
		export LTTNG_HOME=/tmp/lttng
		lttng stop
		lttng destroy
		killall lttng-sessiond
		killall trace_start.sh
	fi

	do_rmmod
	#remove_lib_modules
}

store_bridges()
{
	stored_bridges=$(brctl show | tail -n +2 | awk '{
		if (NF == 4)
		{
			cur_br=$1
			print cur_br, $4
		}
		else if (NF == 1)
			print cur_br, $1
	}')
}

restore_bridges()
{
	while (( "$#" )); do
		brctl addif $1 $2 > /dev/null 2>&1
		shift 2
	done
}

do_dsp_bringup()
{
	local TEST_REQUESTED=$1
	local MODE=$2

	if [ "$CL_HW_MODEL" != "CL_PALLADIUM" -a "$CL_HW_MODEL" != "CL_PROTIUM" ]; then
		local wlan_idx=0
		local band="$(NVG tcv${wlan_idx} ci_band_num)"
		local bandwidth_idx="$(NVG tcv${wlan_idx} ce_channel_bandwidth)"
		local bandwidth="$(idx_to_bandwidth ${bandwidth_idx})"
		echo "do_dsp_bringup: running rf_boot - BAND=$band, wlan_idx=$wlan_idx, FW_TEST=$cl_install_dir/firmware"
		# init RF & clocks
		cl6000_boot -p "$cl_install_dir/firmware" -b "$band"g -w $bandwidth rf_boot
	fi

	cl6000_boot -p "$cl_install_dir/firmware" bringup_dsp $TEST_REQUESTED $MODE
}

action_dsp_bringup()
{
	action_stop
	mkdir -p $LIB_FW_PATH
	# for DSP testing - tcv0 is enough
	update_lib_firmware 0
	pre_init 0
	do_dsp_bringup $1 $2
}

prepare_fw_test_chip()
{
	FW_TEST_NAME=$2
	local chip_idx="chip$3"
	export ini_file=/var/run/cl6k_$chip_idx.ini

	case "$1" in
	"lmac")
		NVS $chip_idx ce_lmac "lmacfw.bin" $FW_TEST_NAME
		NVS $chip_idx ce_smac "smacfw.bin" "no_load"
		NVS $chip_idx ce_umac "no_load" "no_load"
		;;
	"smac")
		NVS $chip_idx ce_lmac "lmacfw.bin" "no_load"
		NVS $chip_idx ce_smac "smacfw.bin" $FW_TEST_NAME
		NVS $chip_idx ce_umac "no_load" "no_load"
		;;
	"lsmac")
		NVS $chip_idx ce_lmac "lmacfw.bin" $FW_TEST_NAME
		NVS $chip_idx ce_smac "smacfw.bin" $FW_TEST_NAME
		NVS $chip_idx ce_umac "no_load" "no_load"
		;;
	"lumac")
		NVS $chip_idx ce_lmac "lmacfw.bin" $FW_TEST_NAME
		NVS $chip_idx ce_smac "no_load" "no_load"
		NVS $chip_idx ce_umac "umacfw.bin" $FW_TEST_NAME
		;;
	"sumac")
		NVS $chip_idx ce_lmac "no_load" "no_load"
		NVS $chip_idx ce_smac "smacfw.bin" $FW_TEST_NAME
		NVS $chip_idx ce_umac "umacfw.bin" $FW_TEST_NAME
		;;
	"lsumac")
		NVS $chip_idx ce_lmac "lmacfw.bin" $FW_TEST_NAME
		NVS $chip_idx ce_smac "smacfw.bin" $FW_TEST_NAME
		NVS $chip_idx ce_umac "no_load" $FW_TEST_NAME
		;;
	"umac")
		NVS $chip_idx ce_lmac "lmacfw.bin" "no_load"
		NVS $chip_idx ce_smac "smacfw.bin" "no_load"
		NVS $chip_idx ce_umac "no_load" $FW_TEST_NAME
		;;
	esac

	source $ini_file || {
		echo "ERROR: Could not read $ini_file"
		echo "The device could not be detected or PCI ID or slot in NVRAM are incorrect."
		exit 1
	}

	[ "x$FW_TEST_NAME" == "x" ] && {
		echo "fw test name is missing, aborting ..."
		exit 1
	}

	# check if FW test bin exists
	if [ -f $cl_install_dir/firmware/$FW_TEST_NAME ]; then
		echo "+------------------------------------------------------+"
		echo "System Running FW Test Mode - $1 $FW_TEST_NAME !!!"
		echo "+------------------------------------------------------+"
	else
		echo "fw test file is missing, abort ... ($FW_TEST_NAME)"
		exit 1
	fi

	# elapse all the ASIC shared RAM.
	[ -x $cl_install_dir/bin/mem_init ] && {
		echo "do_fw_test: 0x40000 shared RAM will be elapsed"
		$cl_install_dir/bin/mem_init -o 0x60000000 -s 0x40000 "MAC_SHARED_RAM"
	} || {
		echo "do_fw_test: warning !!! mem_init is missing - shared RAM will not be elapsed."
	}

	# In case there is a pre-test script to be run before running the fw test - run it now ...
	[ -x $cl_install_dir/scripts/dbg/"$FW_TEST_NAME.pre.sh" ] && { $cl_install_dir/scripts/dbg/"$FW_TEST_NAME.pre.sh" "$1"; }

	if [ "$CL_HW_MODEL" != "CL_PALLADIUM" -a "$CL_HW_MODEL" != "CL_PROTIUM" ]; then
		if [ $(NVG chip0 ci_phy_dev) -ne 2 ]; then
			action_phy_load 0
		else
			local wlan_idx=0
			local band="$(NVG tcv${wlan_idx} ci_band_num)"
			local bandwidth_idx="$(NVG tcv${wlan_idx} ce_channel_bandwidth)"
			local bandwidth="$(idx_to_bandwidth ${bandwidth_idx})"
			echo "do_fw_test: running rf_boot - BAND=$band, wlan_idx=$wlan_idx, FW_TEST=$cl_install_dir/firmware"
			# init RF & clocks
			cl6000_boot -p "$cl_install_dir/firmware" -b "$band"g -w $bandwidth rf_boot
		fi
	fi
}

do_umac_usbtpt_insmod()
{
	do_umac_usbtpt_rmmod
	echo "Loading usbtpt/compat driver"
	insmod $cl_install_dir/modules/compat.ko
	cmd="insmod $cl_install_dir/modules/usbtpt.ko tpt_pid=0x${CL_USB_PROD_ID}"
	echo "${cmd}"
	$cmd
}

do_umac_usbtpt_rmmod()
{
	if lsmod | grep "usbtpt" &> /dev/null ; then
		echo "Unloading usbtpt.ko"
		rmmod usbtpt
	fi
	if lsmod | grep "compat" &> /dev/null ; then
		echo "Unloading compat.ko"
		rmmod compat
	fi
}

do_fw_test()
{
	if [ "$2" == "bootdrv" ]; then
		local boot_parmas="load_test $FW_TEST_NAME no_load no_load"
		if [ "$1" == "smac" ]; then
			boot_parmas="load_test no_load no_load $FW_TEST_NAME"
		elif [ "$1" == "umac" ]; then
			boot_parmas="load_test no_load $FW_TEST_NAME no_load"
		else
			boot_parmas="load_test $FW_TEST_NAME no_load no_load"
		fi

		local chip_idx=0
		while [ "$chip_idx" -lt "$CHIP_NUM" ]; do
			local ce_bt_mode="$(NVG chip${chip_idx} ce_bt_mode 0)"
			local bt_config=""
			if [ "$ce_bt_mode" -gt 0 ] ; then
				bt_config="-t bt_config_${chip_idx}.bin"
			fi
			reset_after_tests="0"
			if [ "$(get_chip_enabled ${chip_idx})" == "1" ] && \
			   [ -f /var/run/cl6k_chip$chip_idx.ini ]; then
				echo "Running test for chip $chip_idx"
				source /var/run/cl6k_chip$chip_idx.ini
				if [ "$1" == "umac" ]; then
					if [ "$FW_TEST_NAME" == "usbtpttestfw.bin" ] ||
					   [ "$FW_TEST_NAME" == "usbwrapperlmactestfw.bin" ] ||
					   [ "$FW_TEST_NAME" == "usbwrappersmactestfw.bin" ] ||
					   [ "$FW_TEST_NAME" == "usbwifiresettestfw.bin" ]; then
						reset_after_tests="1"
						do_umac_usbtpt_insmod
					fi
					if [ "$FW_TEST_NAME" == "usbclitestfw.bin" ]; then
						reset_after_tests="1"
					fi
				fi
				cl6000_boot -p "$cl_install_dir/firmware" ${bt_config} ${boot_parmas}
				do_umac_usbtpt_rmmod
			fi
			chip_idx=$((chip_idx+1))
		done
	else
		#update_lib_modules
		do_insmod
	fi
}

action_fw_test()
{
	action_stop
	mkdir -p $LIB_FW_PATH
	# for fw testing - tcv0 is enough
	local chip_idx=0
	while [ "$chip_idx" -lt "$CHIP_NUM" ]; do
		update_lib_firmware $chip_idx
		if [ "$(get_chip_enabled ${chip_idx})" == "1" ] ; then
			pre_init ${chip_idx}
			if [ -f /var/run/cl6k_chip$chip_idx.ini ]; then
				pre_configure ${chip_idx}
				prepare_fw_test_chip $1 $2 ${chip_idx}
			fi
		fi
		chip_idx=$((chip_idx+1))
	done
	do_fw_test $1 $3
}

init_based_on_device_id()
{
	local cl_pci_info="0x${ce_vendor_id_pci}:${ce_device_id}"

	for device in /sys/bus/pci/devices/*;
	do
		pci_info="$( cat $device/vendor ):$( cat $device/device )"

		case "$pci_info" in
		"$cl_pci_info")
			CL_SYS_DEV_PATH=$device
			CL_PCI_BASE_ADDR=$( cat "$CL_SYS_DEV_PATH/resource" | head -n 1 | awk '{ print $1 }' )
			CL_PCI_BASE_ADDR=0x`printf "%X" $CL_PCI_BASE_ADDR`
			CL_PCI_LAST_ADDR=$( cat "$CL_SYS_DEV_PATH/resource" | head -n 1 | awk '{ print $2 }' )
			CL_PCI_LAST_ADDR=0x`printf "%X" $CL_PCI_LAST_ADDR`

			#There are systems like LEDE that report in resource more than 7FFFFF,
			#the result is that boot_driver uses as mask to reach registers
			#0x800001 instead of 0x800000
			space_check=$(( CL_PCI_LAST_ADDR - CL_PCI_BASE_ADDR ))
			if [ $space_check -gt 8388607 ]; then
				let CL_PCI_LAST_ADDR=$CL_PCI_BASE_ADDR+0x7fffff
				#convert decimal to hexa again after arithmetic
				CL_PCI_LAST_ADDR=0x`printf "%X" $CL_PCI_LAST_ADDR`
			fi

			cat <<-EOF >> $ini_file
			export CL_PCIID=$pci_info
			export CL_SYS_DEV_PATH=$CL_SYS_DEV_PATH
			export CL_PCI_BASE_ADDR=$CL_PCI_BASE_ADDR
			export CL_PCI_LAST_ADDR=$CL_PCI_LAST_ADDR
			EOF

			#exit the for loop, only one instance supported in this mode
			break
			;;
		esac
	done
}

init_based_on_pci_port_id()
{
	local pci_port=$1
	local pci_domain=$2
	local pci_addr=$(printf "%04X:%02X:00.0" $pci_domain $pci_port)
	local device="/sys/bus/pci/devices/$pci_addr"
	local pci_info="$( cat $device/vendor ):$( cat $device/device )"
	local target_pci_info="0x${ce_vendor_id_pci}:${ce_device_id}"

	if [ "$pci_info" != "$target_pci_info" ]; then
		echo "+-----------------------------------------------+"
		echo "| ERROR: cl device NOT detected in slot $pci_port   |"
		echo "+-----------------------------------------------+"
		exit 1
	fi

	CL_SYS_DEV_PATH=$device
	CL_PCI_BASE_ADDR=$(cat "$CL_SYS_DEV_PATH/resource" | head -n 1 | awk '{ print $1 }')
	CL_PCI_BASE_ADDR=$(printf "0x%X" $CL_PCI_BASE_ADDR)
	CL_PCI_LAST_ADDR=$(cat "$CL_SYS_DEV_PATH/resource" | head -n 1 | awk '{ print $2 }')
	CL_PCI_LAST_ADDR=0x`printf "%X" $CL_PCI_LAST_ADDR`

	echo "export CL_SYS_DEV_PATH=$CL_SYS_DEV_PATH" >> $ini_file
	echo "export CL_PCI_BASE_ADDR=$CL_PCI_BASE_ADDR" >> $ini_file
	echo "export CL_PCI_LAST_ADDR=$CL_PCI_LAST_ADDR" >> $ini_file
}

update_lib_firmware()
{
	local chip_idx=$1
	local IDX0=$(($chip_idx*2))
	local lcu_conf_file="$(NVG chip$chip_idx ce_ela_mode "OFF")"

	ln -sf $cl_cfg_dir/cl_chip${chip_idx}.dat $LIB_FW_PATH/cl_chip${chip_idx}.dat
	ln -sf $cl_cfg_dir/cl_tcv${IDX0}.dat $LIB_FW_PATH/cl_tcv${IDX0}.dat
	ln -sf $cl_cfg_dir/calib/* $LIB_FW_PATH/

	if [ -d $cl_cfg_dir/rfic/ ]; then
		ln -sf $cl_cfg_dir/rfic/* $LIB_FW_PATH/
	fi

	# Default Config file for LCU is pointed by "lcu_default.conf" link
	if [ "$lcu_conf_file" != "OFF" ] ; then
		echo "[ce_host] Linking LCU in $lcu_conf_file Mode"
		local dbg_dir="$cl_install_dir/scripts/dbg"

		if [ "$lcu_conf_file" == "default" ]; then
			ln -sf $(readlink -f ${dbg_dir}/lcu_default.conf) \
				$LIB_FW_PATH/lcu_default.conf
		else
			ln -sf ${dbg_dir}/${lcu_conf_file} \
				$LIB_FW_PATH/${lcu_conf_file}
		fi
	else
		echo "LCU disabled"
	fi
}

CL_LIB_MOD_PATH=$cl_install_dir/lib/modules

update_lib_modules()
{
	local cl_lib_mod_dir=$CL_LIB_MOD_PATH/`uname -r`

	if [ -d $CL_LIB_MOD_PATH ]; then
		rm -rf $CL_LIB_MOD_PATH
	fi

	mkdir $CL_LIB_MOD_PATH
	ln -s $cl_install_dir/modules $cl_lib_mod_dir

	touch $cl_lib_mod_dir/modules.builtin
	touch $cl_lib_mod_dir/modules.order

	depmod -a -b $cl_install_dir
}

remove_lib_modules()
{
	if [ -d $CL_LIB_MOD_PATH ]; then
		rm -rf $CL_LIB_MOD_PATH
	fi
}

remove_lib_firmware()
{
	if [ -d $LIB_FW_PATH ]; then
		rm -rf $LIB_FW_PATH
	fi
}

check_config_files()
{
	local chip_idx=$1
	local IDX0=$(($chip_idx*2))

	if ! test_file_exists $cl_cfg_dir/cl_chip$chip_idx.dat ; then
		echo "Restoring defaults chip$chip_idx......"
		$cl_install_dir/scripts/restore_defaults.sh chip$chip_idx
	fi
	if ! test_file_exists $cl_cfg_dir/cl_tcv$IDX0.dat ; then
		echo "Restoring defaults for transceiver $IDX0......"
		$cl_install_dir/scripts/restore_defaults.sh tcv$IDX0
	fi
}

create_dir()
{
	# Check if directory exist.
	# If not create it.
	if [ ! -d "$1" ]; then
		echo "Creating "$1" directory"
		mkdir -p "$1"
	fi
}

is_6g_chip()
{
	local chip_idx=$1

	if [ "${2: -1}" == "6" ] || [ -f "$cl_cfg_dir/chip${chip_idx}_6g" ]; then
		echo "1"
	else
		echo "0"
	fi
}

basic_setup()
{
	local chip_idx=$1
	# Ensure Linux system stuff...
	mkdir -p /var/run/
	mountpoint -q /sys/kernel/debug || mount -t debugfs none /sys/kernel/debug/
	# Enable printk with time
	echo -n 1 > /sys/module/printk/parameters/time
	if [ ! -c /dev/kmsg ] ; then
		echo 'WARNING: /dev/kmsg not found. Add mknod -m 600 /dev/kmsg c 1 11 when building Linux filesystem.'
	fi

	CALIB_DIR="$cl_cfg_dir/calib"
	if [ ! -d $CALIB_DIR ]; then
		create_dir $CALIB_DIR
	fi
}

init_otp()
{
	local chip_idx=$1
	OTP_DIR="$cl_cfg_dir/otp"

	# Use default otp file if necessary
	ce_otp_mode=$(NVG chip$chip_idx ce_otp_mode 0)

	ce_otp_file="$OTP_DIR/otp${chip_idx}.bin"
	otp_base_file=$cl_install_dir/otp/"otp_base.bin"

	if [ $ce_otp_mode -eq 0 ]; then
		create_dir $OTP_DIR

		if [ ! -f $ce_otp_file ]; then
			echo "OTP file not found, copying default"
			cp $otp_base_file $ce_otp_file
		fi
		ln -sf $cl_cfg_dir/otp/* $LIB_FW_PATH/
	fi
}

set_phy_dev()
{
	local chip_idx=$1
	if [ -f "$cl_cfg_dir/cl8000_b2b" ]; then
		local sim_chip_num="$(NVG chip$chip_idx ci_sim_chip_num)"
		if [ "$sim_chip_num" == "0" ]; then
			# the palladium model is initiated from a different host
			NVS chip$chip_idx ci_phy_dev 0 2 # DUMMY
		else
			if [ $(NVG chip$chip_idx ci_phy_dev) -ne 4 ]; then
				NVS chip$chip_idx ci_phy_dev 0 3 # FRU
			fi
		fi
	elif [ -f "$cl_cfg_dir/cl8000_palladium" ] || [ -f "$cl_cfg_dir/cl8000_protium" ]; then
		NVS chip$chip_idx ci_phy_dev 0 2 # DUMMY
	fi
}

set_hw_model()
{
	local chip_idx=$1
	# check if the HW is palladium/protium/b2b/asic
	if [ -f "$cl_cfg_dir/cl8000_palladium" ]; then
		export CL_HW_MODEL="CL_PALLADIUM"
	elif [ -f "$cl_cfg_dir/cl8000_protium" ]; then
		export CL_HW_MODEL="CL_PROTIUM"
	elif [ -f "$cl_cfg_dir/cl8000_b2b" ]; then
		local sim_chip_num="$(NVG chip$chip_idx ci_sim_chip_num)"
		if [ "$sim_chip_num" == "0" ]; then
			export CL_HW_MODEL="CL_PALLADIUM"
		else
			export CL_HW_MODEL="CL_B2B"
		fi
	else
		export CL_HW_MODEL="CL_ASIC"
	fi
}

create_ini_file()
{
	local chip_idx=$1
	local ce_pci_id=$(NVG chip$chip_idx ce_pci_id)
	local ce_pci_port=$(NVG chip$chip_idx $ce_pci_id)
	local ce_pci_domain=$(NVG chip$chip_idx ce_pci_domain 0)
	CL_PATHX=${cl_install_dir}/bin:${cl_install_dir}/scripts

	source $cl_install_dir/scripts/init_dev_id.sh

	ce_device_id="${DEV_IDS[$chip_idx]}"
	ser_num="${SER_NUMS[$chip_idx]}"

	export ini_file=/var/run/cl6k_chip$chip_idx.ini
	[ -f "$ini_file" ] && rm -f "$ini_file"

	if [ -z "$ce_device_id" ]; then
		echo "ERROR: chip $chip_idx is not on bus"
		return
	fi

	if [ -z "$ce_pci_port" ]; then
		init_based_on_device_id
	else
		init_based_on_pci_port_id $ce_pci_port $ce_pci_domain || exit 1
	fi

	# set wifi_mode
	if [ -z "$CL_PCI_BASE_ADDR" ]; then
		wifi_mode="USB"
		echo "export CL_USB_PROD_ID=$ce_device_id" >> $ini_file
		echo "export CL_USB_SER_NUM=$ser_num" >> $ini_file
		echo "export CL_PCI_BASE_ADDR=" >> $ini_file
		echo "export CL_PCI_LAST_ADDR=" >> $ini_file
	else
		wifi_mode="PCI"
		echo "export CL_USB_PROD_ID=" >> $ini_file
		echo "export CL_USB_SER_NUM=" >> $ini_file
	fi

	set_hw_model $chip_idx

	echo "export cl_install_dir=$cl_install_dir" >> $ini_file
	echo "export PATH=$CL_PATHX:$ORIG_PATH" >> $ini_file
	echo "export CL_HW_MODEL=$CL_HW_MODEL" >> $ini_file

	source $ini_file || {
		echo "ERROR: Could not read $ini_file"
		echo "The device could not be detected or PCI ID or slot in NVRAM are incorrect."
		exit 1
	}

	reset.sh $chip_idx 1

	source $cl_install_dir/scripts/fw.regs $chip_idx
	# Chip/Version ID
	regv=$( $MEM $CE_ASIC_VERSION_ID_ADDR )
	if [ -z "$regv" -o "$regv" = "FFFFFFFF" ]; then
		echo "+---------------------------------------------------------------+"
		echo "| ERROR: Could not read ASIC_VER from $CE_ASIC_VERSION_ID_ADDR  |"
		echo "+---------------------------------------------------------------+"
		exit 1
	fi

	export ASIC_VER=${regv:6:1}
	echo "export ASIC_VER=$ASIC_VER" >> $ini_file # stepping without 0x
}

pre_init()
{
	local chip_idx=$1

	check_config_files $chip_idx

	set_phy_dev $chip_idx

	create_ini_file $chip_idx

	if [ ! -f "$ini_file" ]; then
		return
	fi

	if [ "$(is_6g_chip $chip_idx $ce_device_id)" == "0" ]; then
		update_channels $chip_idx
	fi

	# delete temp files from previous boot
	rm -f /tmp/boot_*_init* || true

	local SCRIPTS_SUBDIR="${cl_install_dir}/scripts"
	test_directory_exists "$SCRIPTS_SUBDIR" && CL_PATHX="${SCRIPTS_SUBDIR}:$CL_PATHX"

	ln -sf $cl_install_dir/config/channel_info.txt $LIB_FW_PATH/channel_info.txt
	ln -sf $cl_install_dir/firmware/${ASIC_VER}0/* $LIB_FW_PATH/
	ln -sf $cl_install_dir/firmware/* $LIB_FW_PATH/
	init_otp $chip_idx
	basic_setup $chip_idx
}

do_phy_load()
{
	local chip_idx=$1
	# use first TCV only in b2b setup (tcv0 or tcv2)
	local wlan_idx=$(($chip_idx*2))
	local band="$(NVG tcv${wlan_idx} ci_band_num)"
	local bandwidth_idx="$(NVG tcv${wlan_idx} ce_channel_bandwidth)"
	local bandwidth="$(idx_to_bandwidth ${bandwidth_idx})"
	local loopback_en=0
	local LOAD_DSP=load_dsp
	local bt_mode=$(NVG chip$chip_idx ce_bt_mode 0)
	export FW_DIR="$cl_install_dir/firmware/"

	if [ "$CL_HW_MODEL" == "CL_B2B" ]; then
		LOAD_DSP=load_dsp_b2b
	fi

	# To be used in the future
	if [ $(NVG chip$chip_idx ci_phy_dev) -eq 4 ]; then
		loopback_en=1
	fi

	echo -e "do_dsp_load: $CL_HW_MODEL HW - FW_DIR=$FW_DIR band="$band"g BW=$bandwidth loopback=$loopback\n"
	## init RF & clocks
	cl6000_boot -p $FW_DIR rf_boot -b "$band"g -w "$bandwidth" -e "$bt_mode"
	echo "rf_boot done. load dsp:"


	if [ "$CL_HW_MODEL" != "CL_B2B" -o "$FW_TEST_NAME" == "" -o "$FW_TEST_NAME" == "dspmbxtestfw.bin" ]; then
		## load DSP:
		cl6000_boot -p $FW_DIR $LOAD_DSP -b "$band"g -w $bandwidth
	fi
	echo  "+-------------------------------------------------------+"
	echo  "FINISHED LOAD DSP FOR chip_idx=${chip_idx} CL_PALLADIUM"
	echo  "+-------------------------------------------------------+"
}

do_bt_insmod()
{
	local bt_mode=$(NVG chip0 ce_bt_mode 0)

	if [ "$bt_mode" = "0" ]; then
		return 0
	fi

	insmod $cl_install_dir/modules/ecc.ko
	if [ "$TARGET_PLATFORM" == "EDK32" ]; then
		insmod $cl_install_dir/modules/kpp.ko
	fi
	insmod $cl_install_dir/modules/ecdh_generic.ko
	insmod $cl_install_dir/modules/bluetooth.ko
	insmod $cl_install_dir/modules/btcl.ko
	insmod $cl_install_dir/modules/btintel.ko
	insmod $cl_install_dir/modules/btrtl.ko
	insmod $cl_install_dir/modules/btbcm.ko
	if [ "$bt_mode" = "2" ]; then
		insmod $cl_install_dir/modules/btusb.ko
		#modprobe -v -d $cl_install_dir btusb
		#modprobe -v -d $cl_install_dir bnep
		#modprobe -v -d $cl_install_dir rfcomm
	elif [ "$bt_mode" = "1" ]; then
		insmod $cl_install_dir/modules/hci_uart.ko
		#modprobe -v -d $cl_install_dir hci_uart
		#modprobe -v -d $cl_install_dir bnep
		#modprobe -v -d $cl_install_dir rfcomm
	fi
	insmod $cl_install_dir/modules/bnep.ko
	insmod $cl_install_dir/modules/rfcomm.ko

	systemd_dir="/etc/dbus-1/system.d"
	if [ ! -d $systemd_dir ]; then
		mkdir $systemd_dir
	fi

	if [ ! -f $systemd_dir/bluetooth.conf ]; then
		cp $cl_install_dir/$systemd_dir/bluetooth.conf  $systemd_dir
	fi

	if [ -f /etc/init.d/S30dbus ]; then
		/etc/init.d/S30dbus restart
	fi

	$cl_install_dir/libexec/bluetooth/bluetoothd &
}

do_insmod()
{
	modparams="
	cl_install_dir=${cl_install_dir}
	cl_config_dir=${cl_cfg_dir}
	"

	if [ `lsmod | grep -c "\bcl6k\b"` -ne 0 ]; then
		return 0
	fi

	dmesg -c > /dev/null

#	modprobe -v -d $cl_install_dir cl6k $modparams
	insmod $cl_install_dir/modules/compat.ko
	insmod $cl_install_dir/modules/cfg80211.ko
	insmod $cl_install_dir/modules/mac80211.ko
	insmod $cl_install_dir/modules/cl_core.ko
	insmod $cl_install_dir/modules/cl6k.ko $modparams
	sleep 1
	if  [ `lsmod | grep -c compat` -eq 0 ] || [ `lsmod | grep -c cfg80211` -eq 0 ] ||\
		[ `lsmod | grep -c mac80211` -eq 0 ] || [ `lsmod | grep -c "\bcl6k\b"` -eq 0 ]; then
		echo "Failed to insert cl6k.ko"
		exit 1
	fi

	$cl_install_dir/bin/cl_netlink
}

do_bt_rmmod()
{
	killall btmon > /dev/null 2>&1
	killall btattach > /dev/null 2>&1
	killall l2test > /dev/null 2>&1
	killall hciattach > /dev/null 2>&1

	if service bluetooth status > /dev/null 2>&1; then
		service bluetooth stop
		systemctl disable bluetooth.service
	fi

	killall bluetoothd > /dev/null 2>&1
	sleep 1

	if [ `lsmod | grep -c "\bbluetooth\b"` -eq 0 ]; then
		return 0
	fi

	rmmod rfcomm
	rmmod bnep.ko
	rmmod btusb
	rmmod hci_uart
	rmmod btintel
	rmmod btrtl
	rmmod btbcm
	rmmod btcl
	rmmod bluetooth
	rmmod ecdh_generic
	rmmod ecc
	if [ "$TARGET_PLATFORM" == "EDK32" ]; then
		rmmod kpp
	fi

	#modprobe -d $cl_install_dir -r rfcomm
	#modprobe -d $cl_install_dir -r bnep
	#modprobe -d $cl_install_dir -r hci_uart
	#modprobe -d $cl_install_dir -r btusb
}


do_rmmod()
{
	do_bt_rmmod

	# Remove modules if all TCV's were unregistered
#	modprobe -d $cl_install_dir -r cl6k
	rmmod cl6k
	rmmod cl_core
	rmmod mac80211
	rmmod cfg80211
	rmmod compat
}

load_the_driver()
{
	# Workaround to prevent wpa_supplicant of running and bringing down our AP
	# interfaces on edk platforms
	if [ -f /sbin/wpa_supplicant ]; then
		chmod -x /sbin/wpa_supplicant
	fi

	#update_lib_modules
	do_insmod

	# test if do_insmod failed
	if [ $? -ne 0 ]; then
		echo "## do_insmod Failed"
		exit 1;
	fi
}

start_hostapd()
{
	local i=0
	hostapd_cmd="-B -P ${UTILS_CONFIG_FOLDER}/hostapd.pid $hostapd_conf_files"
	hostapd_dbg="$(NVG chip0 ha_debug)"
	hostapd_dbg=${hostapd_dbg:-0}
	local hostapd_log=
	if [ "$hostapd_dbg" != "0" ]; then
		hostapd_log="-f ${UTILS_CONFIG_FOLDER}/hostapd.log -"
		i=0
		while [ "$i" -lt "$hostapd_dbg" ]; do
			hostapd_log="$hostapd_log"d
			i=$((i+1))
		done
	fi

	$cl_install_dir/bin/hostapd $hostapd_log $hostapd_cmd

	# Configure wsc for wps
# TODO: fix the below code for WPS support
#	if [ "$wps" = 1 ]; then
#		if [ "$(get_tcv_enabled 0)" == "0" ]; then
#			return
#		fi
#		local wlan_idx=$(($chip_idx*2))
#		local bss_num="$(NVG tcv${wlan_idx} ce_bss_num)"
#		local j=0
#		while [ "$j" -lt "$bss_num" ]; do
#			if [ "$(get_iface_type $wlan_idx $j)" == "3" ]; then
#				local wlan_int="wlan${wlan_idx}_${j}"
#				stop_wsc "$wlan_int"
#				$cl_install_dir/scripts/wsc_save.sh $chip_idx 0 $j &
#			fi
#			j=$(( j+1 ))
#		done
#	fi
}

stop_hostapd()
{
	if [ -f ${UTILS_CONFIG_FOLDER}/hostapd.pid ]; then
		kill $(cat ${UTILS_CONFIG_FOLDER}/hostapd.pid)
		rm -f ${UTILS_CONFIG_FOLDER}/hostapd.pid
	fi

	rm -f ${UTILS_CONFIG_FOLDER}/hostapd_tcv*
}

update_hostapd()
{
	local chip_idx=0
	while [ "$chip_idx" -lt "$CHIP_NUM" ]; do
		if [ "$(get_chip_enabled ${chip_idx})" == "1" ] && \
		   [ -f /var/run/cl6k_chip$chip_idx.ini ]; then
			if [ "$(get_tcv_enabled $chip_idx 0)" == "0" ]; then
				continue
			fi
			local wlan_idx=$(($chip_idx*2))
			local AP="wlan${wlan_idx}"_
			local bss_num="$(NVG tcv${wlan_idx} ce_bss_num)"
			local j=0
			local conf=${UTILS_CONFIG_FOLDER}/"hostapd_tcv${wlan_idx}.conf"
			cp -f $cl_install_dir/config/hostapd-template.conf $conf
			hostapd_conf_files="$hostapd_conf_files $conf"
			while [ "$j" -lt "$bss_num" ]; do
				local wlan_int="${AP}$j"
				if [ "$(get_iface_type $wlan_idx $j)" == "3" ]; then
					configure_hostapd $chip_idx 0 $j
				fi
				j=$((j+1))
			done
		fi
		chip_idx=$((chip_idx+1))
	done
}

action_reload_hostapd()
{
	# If the first BSS is down then hostapd crashes when trying to reload it
	# The reason is that it gets an event of RTM_NEWLINK for the first BSS in
	# the middle of the startup process and then accesses an unallocated buffer
	local wlans=$($cl_install_dir/bin/hostapd_cli -p ${UTILS_CONFIG_FOLDER}/hostapd interface | grep ^wlan)
	for ifname in $wlans; do
		if [ `ifconfig $ifname 2>/dev/null | grep -c RUNNING` -eq 0 ]; then
			ifconfig $ifname up
		fi
	done

	stop_hostapd
	update_hostapd
	local retry_cnt=0
	local max_retry_cnt=12
	# Wait for hostapd to shut down before starting it again
	local ps_cmd="ps"
	if [ `ps x &> /dev/null; echo "$?"` -eq 0 ]; then
		ps_cmd="ps x"
	fi
	while [ "$(eval $ps_cmd | grep "hostapd" | grep -vc grep)" != "0" -a $retry_cnt -lt $max_retry_cnt ]
	do
		sleep 1
		retry_cnt=$(( retry_cnt + 1 ))
	done
	start_hostapd
	local chip_idx=0
	while [ "$chip_idx" -lt "$CHIP_NUM" ]; do
		configure_interfaces $chip_idx
		post_configure $chip_idx
		chip_idx=$((chip_idx+1))
	done
}

start_supplicant()
{
	ws_cmd="$per_bss_ws_cmd -B -P ${UTILS_CONFIG_FOLDER}/wpa_supplicant.pid"

	ws_dbg="$(NVG chip0 ws_debug)"
	ws_dbg=${ws_dbg:-0}
	if [ "$ws_dbg" != "0" ]; then
		local ws_log="-f ${UTILS_CONFIG_FOLDER}/wpa_supplicant_log.log -"
		local i=0
		while [ "$i" -lt "$ws_dbg" ]; do
			ws_log="$ws_log"d
			i=$((i+1))
		done
	fi
	$cl_install_dir/bin/wpa_supplicant $ws_cmd $ws_log && \
	wpa_cli -a $cl_install_dir/scripts/wpa_action.sh -B
}

stop_supplicant()
{
	# remove supplicant conf files
	if [ ! -f "${UTILS_CONFIG_FOLDER}/wpa_supplicant.pid" ]; then
		return
	fi

	for iface in `ls /var/run/wpa_supplicant/ | grep ^wlan`; do
		for j in `wpa_cli -i${iface} list_networks | grep ^[0-9] | cut -f1`; do
			wpa_cli -i${iface} remove_network $j; done
		wpa_cli -i${iface} disconnect
		ip addr flush dev ${iface}
		local wlan_idx=`echo $iface | cut -c5`
		local station_bridge=$(NVG tcv${wlan_idx} ws_bridge "br0")
		brctl delif $station_bridge ${iface}
	done

	kill $(cat ${UTILS_CONFIG_FOLDER}/wpa_supplicant.pid)
	rm -f ${UTILS_CONFIG_FOLDER}/wpa_supplicant*
}

configure_supplicant()
{
	local chip_idx=$1
	local tcv_idx=$2
	local bss_idx=$3
	local wlan_idx=$(($chip_idx*2+$tcv_idx))
	local conf="${UTILS_CONFIG_FOLDER}/wpa_supplicant_tcv${wlan_idx}.conf"
	local iface_type=$(get_iface_type $wlan_idx $bss_idx)
	local phy_dev="$(NVG chip$chip_idx ci_phy_dev)"
	local twin_peak="$(NVG chip$chip_idx ci_twin_peak_mode 0)"

	if [ ! -f $conf ]; then
		cp -f $cl_install_dir/config/wpa_supplicant-template.conf $conf
	fi
	if [ -z "$per_bss_ws_cmd" ]; then
		per_bss_ws_cmd="-c $conf -iwlan${wlan_idx}_${bss_idx}"
	else
		per_bss_ws_cmd="$per_bss_ws_cmd -N -c $conf -iwlan${wlan_idx}_${bss_idx}"
	fi

	local country_code="$(NVG chip$chip_idx ce_country_code)"
	echo "country=$country_code" >> $conf

	local uuid="$(NVG chip$chip_idx uuid1)"
	if [ -n "$uuid" ]; then
		echo "uuid=$uuid" >> $conf
	fi

	local auth_mode="$(NVG tcv${wlan_idx} ws_auth_mode)"
	local passphrase="$(NVG tcv${wlan_idx} ws_key)"
	local ssid="$(NVG tcv${wlan_idx} ws_ssid)"
	local identity="$(NVG tcv${wlan_idx} ws_identity)"
	local gcmp_len="$(NVG tcv${wlan_idx} ha_gcmp_key_len 256)"

	case "$auth_mode" in
	WPA2|WPA3)
		if [ "$auth_mode" = 'WPA2' ]; then
			sed -i '/^network=.*/a \\proto=WPA2' $conf
			sed -i '/^network=.*/a  pairwise=CCMP' $conf
			sed -i '/^network=.*/a  group=CCMP' $conf
		fi
		if [ "$auth_mode" = 'WPA3' ]; then
			sed -i '/^network=.*/a \\tproto=RSN' $conf
			if [ "$gcmp_len" == "256" ]; then
				sed -i '/^network=.*/a  \\tpairwise=GCMP-256' $conf
				sed -i '/^network=.*/a  \\tgroup=GCMP-256' $conf
			elif [ "$gcmp_len" == "128" ]; then
				sed -i '/^network=.*/a  \\tpairwise=GCMP' $conf
				sed -i '/^network=.*/a  \\tgroup=GCMP' $conf
			else
				echo "cli Error: incorrect gcmp_len - check your nvram !!!!!"
			fi
		fi
		sed -i '/^network=.*/a \\teap=PEAP' $conf
		sed -i "/^network=.*/a  identity=\"$identity\"" $conf
		sed -i "/^network=.*/a  password=\"$passphrase\"" $conf
		sed -i "/^network=.*/a  phase1=\"peapver=0\"" $conf
		sed -i "/^network=.*/a  phase2=\"MSCHAPV2\"" $conf
	;;
	WPA2PSK|WPAPSK|WPAPSKWPA2PSK|WPA3SAE)
		sed -i "/^network=.*/a  psk=\"$passphrase\"" $conf
		if [ "$auth_mode" = 'WPA2PSK' ]; then
			sed -i '/^network=.*/a \\proto=RSN' $conf
		elif [ "$auth_mode" = 'WPA3SAE' ]; then
			sed -i 's/\(key_mgmt=\).*/\1SAE/' $conf
		elif [ "$auth_mode" = 'WPAPSKWPA2PSK' ]; then
			sed -i "/^network=.*/a  pairwise=CCMP TKIP/" $conf
			sed -i "/^network=.*/a  group=CCMP TKIP/" $conf
		fi
	;;
	WEP|WEPSHARED)
		if [ "$auth_mode" == "WEPSHARED" ]; then
			sed -i 's/\(auth_alg=\).*/\1SHARED/' $conf
		fi
		if [ ${#passphrase} -eq 5 -o ${#passphrase} -eq 13 ]; then
			sed -i "/^network=.*/a  wep_key0=\"$passphrase\"" $conf
		else
			sed -i "/^network=.*/a  wep_key0=$passphrase" $conf
		fi
		sed -i 's/\(key_mgmt=\).*/\1NONE/' $conf
		;;
	OPEN)
		sed -i 's/\(auth_alg=\).*/\1OPEN/' $conf
		sed -i 's/\(key_mgmt=\).*/\1NONE/' $conf
		;;
	*)
		echo "cli Error: incorrect ws_auth_mode - check your nvram !!!!!"
	;;
	esac

	set_pmf_supplicant_conf $wlan_idx $auth_mode $conf
	
	# MESH configurations
	if [ "$iface_type" == "7" ]; then
		sed -i 's/\(mode=\).*/\15/' $conf
		local max_peer_links="$(NVG tcv${wlan_idx} ws_max_peer_links 10)"
		local mesh_max_inactivity="$(NVG tcv${wlan_idx} ws_mesh_max_inactivity)"
		echo "max_peer_links=$max_peer_links" >> $conf
		if [ -n "$mesh_max_inactivity" ]; then
			echo "mesh_max_inactivity=$mesh_max_inactivity" >> $conf
		fi
	fi

	local ci_band_num="$(NVG tcv${wlan_idx} ci_band_num)"

	# Set a single scan freq for EDKs
	if [ $phy_dev -gt 1 -o $twin_peak -eq 1 ]; then
		sed -i "/^network=.*/a  scan_freq=$(get_scan_freq $ci_band_num)" $conf
	fi

	sed -i "/^network=.*/a  ssid=\"$ssid\"" $conf
}

action_setup_bridge()
{
	local chip_idx=0
	while [ "$chip_idx" -lt "$CHIP_NUM" ]; do
		if [ "$(get_chip_enabled ${chip_idx})" == "1" ] && \
		   [ -f /var/run/cl6k_chip$chip_idx.ini ]; then
			if [ "$(get_tcv_enabled $chip_idx 0)" == "0" ]; then
				return
			fi
			local wlan_idx=$(($chip_idx*2))
			$cl_install_dir/scripts/bridge.sh ${wlan_idx}
		fi
		chip_idx=$((chip_idx+1))
	done
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

update_common_var()
{
	export cl_install_dir=${cl_install_dir-/cl6k}
	export cl_cfg_dir=${cl_cfg_dir-/nvram/cl6k}
	export PATH=$cl_install_dir/bin:$cl_install_dir/scripts:$cl_install_dir/scripts/rf_scripts:$PATH
	export LD_LIBRARY_PATH=$cl_install_dir/lib${LD_LIBRARY_PATH+:}$LD_LIBRARY_PATH

	echo 8 > /proc/sys/kernel/printk

	source "$cl_install_dir/scripts/env.sh" || {
		echo "env.sh missing, please make sure that  cl_install_dir is set properly ..."
		exit 1
	}

	NVG_VLAN="$cl_install_dir/scripts/nvram_get vlan"
	IW="$cl_install_dir/bin/iw"
	IWCL="$cl_install_dir/bin/iwcl"
	MEM="$cl_install_dir/bin/mem"

	# Create cl_cfg_dir if does not exist (assume it is writable)
	if [ ! -d $cl_cfg_dir ]; then
		echo "Config dir does not exist, creating $cl_cfg_dir ..."
		mkdir -p $cl_cfg_dir || exit 1
	fi

	NETWORK_MGR=/etc/init.d/network-manager
	if [ -f "$NETWORK_MGR" ]; then
		if $NETWORK_MGR status > /dev/null; then
			$NETWORK_MGR stop
		fi
	fi
}

action_reload()
{
	is_reload=1
	local chip_idx=0
	while [ "$chip_idx" -lt "$CHIP_NUM" ]; do
		if [ "$(get_chip_enabled ${chip_idx})" == "1" ] && \
		   [ -f /var/run/cl6k_chip$chip_idx.ini ]; then
			if [ "$(get_tcv_enabled $chip_idx 0)" == "0" ]; then
				continue
			fi
			local wlan_idx=$(($chip_idx*2))
			local AP="wlan${wlan_idx}"_0
			reload_channel[$wlan_idx]=`$IW $AP info | sed -nr '/channel / s/.*channel ([^"]+).*/\1/p' | awk '{print $1;}'`
			reload_bw[$wlan_idx]=`$IW $AP info | sed -nr '/width: / s/.*width: ([^"]+).*/\1/p' | awk '{print $1;}'`
		fi
		chip_idx=$((chip_idx+1))
	done

	store_bridges
	action_start
	restore_bridges $stored_bridges
}

action_stop()
{
	remove_lib_firmware

	# Check that cl module is up
	if [ `lsmod | grep -c "\bcl6k\b"` -eq 0 ]; then
		return
	fi

	stop_hostapd
	stop_supplicant

	local chip_idx=0
	while [ "$chip_idx" -lt "$CHIP_NUM" ]; do
		if [ "$(get_chip_enabled ${chip_idx})" == "1" ] || [ "$(is_iface_up $chip_idx)" == "1" ]; then
			do_stop $chip_idx
		fi
		chip_idx=$((chip_idx+1))
	done

	do_remove

	# delete temp files from previous rf_boot
	rm -f /tmp/boot_*_init* || true
	sleep 1
}

action_phy_load()
{
	local chip_idx=$1
	local phy_dev="$(NVG chip$chip_idx ci_phy_dev)"
	if [ "$phy_dev" != "2" ]; then
		local phy_load_bootdrv="$(NVG chip$chip_idx ci_phy_load_bootdrv 0)"
		if [ "$phy_load_bootdrv" == "1" ]; then
			do_phy_load $chip_idx
		fi
	fi
}

action_start()
{
	action_stop
	mkdir -p $LIB_FW_PATH

	local chip_idx=0
	while [ "$chip_idx" -lt "$CHIP_NUM" ]; do
		update_lib_firmware $chip_idx
		if [ "$(get_chip_enabled ${chip_idx})" == "1" ] ; then
			pre_init ${chip_idx}
			if [ -f /var/run/cl6k_chip$chip_idx.ini ]; then
				pre_configure ${chip_idx}
				action_phy_load ${chip_idx}
			fi
			RESET_EDK=0
		fi
		chip_idx=$((chip_idx+1))
	done

	chip_idx=0
	while [ "$chip_idx" -lt "$CHIP_NUM" ]; do
		if [ "$(get_chip_enabled ${chip_idx})" == "1" ] && \
		   [ -f /var/run/cl6k_chip$chip_idx.ini ]; then
			do_start $chip_idx
		fi
		chip_idx=$((chip_idx+1))
	done

	do_bt_rmmod
	do_bt_insmod

	if [ -n "$hostapd_conf_files" ]; then
		start_hostapd
		chip_idx=0
		while [ "$chip_idx" -lt "$CHIP_NUM" ]; do
			configure_interfaces $chip_idx
			chip_idx=$((chip_idx+1))
		done
	fi

	if [ -n "$per_bss_ws_cmd" ]; then
		start_supplicant
	fi

	chip_idx=0
	while [ "$chip_idx" -lt "$CHIP_NUM" ]; do
		post_configure $chip_idx
		chip_idx=$((chip_idx+1))
	done
}

run_action()
{
	case "$ACTION" in
		start)
			action_start
			;;
		stop)
			action_stop
			;;
		reload)
			action_reload
			;;
		version)
			echo "Version=$cl_package_version"
			exit 0
			;;
		reload_hostapd)
			action_reload_hostapd
			;;
		br0)
			action_setup_bridge
			;;
		bringup_dsp)
			action_dsp_bringup $1 $2 $3
			;;
		fw_test)
			action_fw_test $1 $2 $3
			;;
		create_ini)
			create_ini_file $1
			;;
		*)
			do_print_usage
			exit 0
			;;
	esac
}

#####################################################################
# MAIN
#####################################################################

export RESET_EDK=1
production_mode=0
UTILS_CONFIG_FOLDER=${UTILS_CONFIG_FOLDER:=/tmp}
LIB_FW_PATH=/lib/firmware/cl6k
CHIP_NUM=4

# parse command line parameters
while [[ $# -ge 1 ]]
do
	case "$1" in
		start|stop|reload|reload_hostapd|version|br0)
			ACTION=$1
		;;
		fw_test)
			ACTION=$1
			break 2
		;;
		bringup_dsp)
			ACTION=$1
			break 2
		;;
		production|prod)
			if [ -z "$ACTION" ]; then
				ACTION="start"
			fi
			production_mode=1
		;;
		create_ini)
			ACTION=$1
			break 2
		;;
		*)
			do_print_usage
			exit 0
		;;
	esac
	shift
done

update_common_var
run_action $2 $3 $4

echo "[ce_host] done"
