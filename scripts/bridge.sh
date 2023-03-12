#!/bin/sh

source env.sh

chip_idx=$1
wlan_prefix="wlan$2"_
bridge_en=`$cl_install_dir/scripts/nvram_get chip$chip_idx ce_bridge_en`

if [ -z "$bridge_en" ] || [ $bridge_en -eq 0 ]; then
	exit
fi

iface_eth=`$cl_install_dir/scripts/nvram_get chip$chip_idx ce_iface_eth`
iface_vlan=`$cl_install_dir/scripts/nvram_get chip$chip_idx ce_iface_vlan`
iface_ip=`$cl_install_dir/scripts/nvram_get chip$chip_idx ce_iface_ip`
iface_ip="${iface_ip:=192.168.1.1}"
iface_ip="${iface_ip}/24"
iface_default_gw=`$cl_install_dir/scripts/nvram_get chip$chip_idx ce_iface_default_gw`

bss_num=`$cl_install_dir/scripts/nvram_get tcv$2 ce_bss_num`

for addr in $(ip a s dev $iface_eth | awk '/inet /{print $2}');
do
	ip a d $addr dev $iface_eth
done

bridge_name=`$cl_install_dir/scripts/nvram_get chip$chip_idx ha_upnp_iface`

brctl addbr $bridge_name 2>/dev/null
for addr in $(ip a s dev $bridge_name | awk '/inet /{print $2}'); do
	ip a d $addr dev $bridge_name
done
ip a a $iface_ip dev $bridge_name
ip link set $bridge_name up

if [ -n "$iface_vlan" ] ;then
	vconfig add $iface_eth $iface_vlan 2>/dev/null
	ip link set $iface_eth.$iface_vlan up
	ip a f dev $iface_eth.$iface_vlan
	brctl addif $bridge_name $iface_eth.$iface_vlan 2>/dev/null
else
	ip a f dev $iface_eth
	brctl addif $bridge_name $iface_eth 2>/dev/null
fi

route del -net 239.0.0.0 netmask 255.0.0.0 2>/dev/null
route add -net 224.0.0.0 netmask 240.0.0.0 dev $bridge_name 2>/dev/null

if [ -n "$iface_default_gw" ]; then
	route add default gw $iface_default_gw 2>/dev/null
fi

ip a f dev ${wlan_prefix}0

i=1
while [ $i -le "$bss_num" ]; do
	wlan_int=$wlan_prefix$(( i-1 ))
	brctl addif $bridge_name $wlan_int 2>/dev/null
	i=$(( i+1 ))
done
