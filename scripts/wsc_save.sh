#!/bin/sh

chip_idx=$1
tcv_idx=$2
bss_idx=$3

wlan_idx=$(($chip_idx*2+$tcv_idx))
wlan_int="wlan${wlan_idx}_${bss_idx}"

NVG="$cl_install_dir/scripts/nvram_get tcv${tcv_idx}"
NVS="$cl_install_dir/scripts/nvram_set tcv${tcv_idx}"

HOSTAPD_CONFIG_FOLDER=${HOSTAPD_CONFIG_FOLDER:=/tmp}
config="${HOSTAPD_CONFIG_FOLDER}/hostapd_tcv${wlan_idx}.conf"
ctrl_interface="${HOSTAPD_CONFIG_FOLDER}/hostapd-${wlan_int}"

echo $$ > /tmp/wsc_save-${wlan_int}.pid

poll_conf_ready()
{
	local count=0
	local retries=0

	while [ $count == 0 ]; do
		count=$(grep -c "# WPS configuration - START" "$config")
		retries=$(( retries + 1 ))

		if [ "$count" != "1" ] && [ $retries -lt 5 ] ; then
			sleep 1
		fi
	done
}

get_from_conf()
{
	local _param=$1
	local _tmp=""

	_tmp="$(sed -n "/^# WPS configuration - START$/,/^# WPS configuration - END$/ {s/^$_param=\(.*\)/\1/p}" $config)"
	echo "$_tmp"
}

while true
do
	echo ""
	sleep 1
done | $cl_install_dir/bin/hostapd_cli -p $ctrl_interface |\
while read line
do
	if echo "$line" | grep -q WPS-NEW-AP-SETTINGS
	then
		poll_conf_ready

		ssid=$(get_from_conf ssid)
		wpa_pairwise=$(get_from_conf wpa_pairwise)
		wpa=$(get_from_conf wpa)

		if [ -n "$wpa" ] && [ "$wpa" != 0 ];
		then
			wpa_passphrase=$(get_from_conf wpa_passphrase)
			wpa_psk=$(get_from_conf wpa_psk)

			if echo $wpa_pairwise | grep -q TKIP
			then
				auth_mode=WPAPSKWPA2PSK
				encrypt_type=TKIPAES
			elif echo $wpa_pairwise | grep -q CCMP
			then
				auth_mode=WPA2PSK
				encrypt_type=AES
			fi

			if [ -n "$wpa_passphrase" ]
			then
				$NVS ha_wpa_passphrase$bss_idx "$wpa_passphrase"
			elif [ -n "$wpa_psk" ]
			then
				$NVS ha_wpa_passphrase$bss_idx "$wpa_psk"
			fi

		else
			auth_mode=OPEN
			encrypt_type=NONE
		fi

		if [ -n "$auth_mode" ] && [ -n "$encrypt_type" ]
		then
			ha_auth_mode=$($NVG ha_auth_mode | awk -F',' -v n=$bss_idx -v val=$auth_mode '{OFS=","; $n = val; print}')
			ha_encrypt_type=$($NVG ha_encrypt_type | awk -F',' -v n=$bss_idx -v val=$encrypt_type '{OFS=","; $n = val; print}')
			# Switch to configured state
			wps_state=$($NVG ha_wps_state | awk -F',' -v n=$bss_idx -v val=2 '{OFS=","; $n = val; print}')

			$NVS ha_ssid$bss_idx "$ssid"
			$NVS ha_auth_mode "$ha_auth_mode"
			$NVS ha_encrypt_type "$ha_encrypt_type"
			$NVS ha_wps_state "$wps_state"

			if [ "$chip_idx" == "0" ]; then
				$cl_install_dir/scripts/ce_host.sh reload_hostapd
			else
				$cl_install_dir/scripts/ce_host.sh reload_hostapd chip1
			fi
		else
			echo "wsc_save: auth_mode or encrypt_type are empty"
		fi
		exit 0
	fi
done
