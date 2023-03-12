#!/bin/sh

#
VERBOSE=${VERBOSE:="off"}
DRY_RUN=${DRY_RUN:="off"}
CHIP_IDX=${CHIP_IDX:=0}

mem_write()
{
    local addr=$1
    local val=$2

    if [ "$DRY_RUN" == "on" ]; then
        echo "mem $addr w $val"
    else
        mem "$addr" w "$val"
    fi
}

filename="$1"

if [ -z $filename ]; then
	echo "filename is missing..."
	exit
fi

# go over verification output file and fish all register addresses and data
XXX=`grep "axi_lite_monitor.* wr " $filename | awk -F'[ =,]' '{for (I=1;I<=NF;I++) if ($I == "address") {print $(I+1) "@" $(I+4)};}'`

for cmd in $XXX; do
IFS='@'
while read -r mem_addr mem_val
do
[ "$VERBOSE" == "on" ] && echo "mem_write=$mem_addr w $mem_val"
mem_write $mem_addr $mem_val
done <<< $cmd
unset IFS
done
