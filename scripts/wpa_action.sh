#!/bin/sh

source env.sh

IFNAME=$1
CMD=$2

# Perform this script for main APCLI only
if [ $IFNAME = "wlan0_0" -o $IFNAME = "wlan0_1" ]; then
    NVG="$cl_install_dir/scripts/nvram_get tcv0"
elif [ $IFNAME = "wlan1_0" -o $IFNAME = "wlan1_1" ]; then
    NVG="$cl_install_dir/scripts/nvram_get tcv1"
elif [ $IFNAME = "wlan2_0" -o $IFNAME = "wlan2_1" ]; then
    NVG="$cl_install_dir/scripts/nvram_get tcv2"
elif [ $IFNAME = "wlan3_0" -o $IFNAME = "wlan3_1" ]; then
    NVG="$cl_install_dir/scripts/nvram_get tcv3"
fi

WORK_MODE=$($NVG ce_work_mode)
BRIDGE_NAME=$($NVG ws_bridge)

if [ "$CMD" == "CONNECTED" ]; then
    if [ -n $BRIDGE_NAME ]; then
        if [ $WORK_MODE = "1" ];then
            brctl addif $BRIDGE_NAME $IFNAME
        fi
    fi
elif [ "$CMD" == "DISCONNECTED" ]; then
    logger -s "WiFi: Disconnecting `$IFNAME`"
    if [ -n $BRIDGE_NAME ]; then
        if [ $WORK_MODE = "1" ];then
            brctl delif $BRIDGE_NAME $IFNAME
        fi
    fi
fi
