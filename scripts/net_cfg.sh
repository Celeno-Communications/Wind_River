#!/bin/bash
# Note - This script has to be run with sudo !!!

# Variable Defaults
OUTPUT="/dev/null"
VERBOSE=""
DRY_RUN="off"

down_function() {

    # delete iptables NAT rules ...
    iptables -t nat -D POSTROUTING -d $IP11 -j SNAT --to-source $IP00
    iptables -t nat -D POSTROUTING -d $IP00 -j SNAT --to-source $IP11
    iptables -t nat -D PREROUTING -d $IP00 -j DNAT --to-destination $IP0
    iptables -t nat -D PREROUTING -d $IP11 -j DNAT --to-destination $IP1

    # delete arp table entries
    arp -d $IP00
    arp -d $IP11

    # delete statis routes
    route del $IP00
    route del $IP11
}


up_function() {

    # add static route & arp table entry for first nif
    ip route add $IP00 dev $IF1
    arp -s $IP00 $MAC0

    # add static route & arp table entry for first nif
    ip route add $IP11 dev $IF0
    arp -s $IP11 $MAC1

    # add iptables NAT rules ...
    iptables -t nat -A POSTROUTING -d $IP11 -j SNAT --to-source $IP00
    iptables -t nat -A POSTROUTING -d $IP00 -j SNAT --to-source $IP11
    iptables -t nat -A PREROUTING -d $IP00 -j DNAT --to-destination $IP0
    iptables -t nat -A PREROUTING -d $IP11 -j DNAT --to-destination $IP1
}

show_function() {
    echo ""
    route -n
    echo ""
    arp -n
    echo ""
    iptables -t nat --list
    echo ""
}

usage()
{
	echo "" >&2
	echo "Usage: $(basename $0) if1 if2 command" >&2
	echo "" >&2
	echo "command - up|down|show|restart" >&2
	echo "-v, verbose print level (optional)" >&2
	echo "-d, dry run - all but running commands (optional)" >&2
	echo "-h, help" >&2
	echo "" >&2
	echo "Example: $(basename $0) wlan0_0 wlan1_0 up" >&2
	echo "" >&2
	exit 2
}

while getopts 'vdh' OPTION
do
	case $OPTION in
	v)
		VERBOSE="-v";
		OUTPUT="/dev/stdout";
		;;
	d)
		DRY_RUN="on"
		;;
	h)
		usage
		;;
	\:) printf "argument missing from -%s option\n" $OPTARG
		usage
		;;
	\?)  printf "unknown option: -%s\n" $OPTARG
		usage
		;;
	esac
done>&2

shift $(($OPTIND - 1))

echo "" >$OUTPUT
echo "running $(basename $0) script ..." >$OUTPUT
echo "" >$OUTPUT

if [ $# -ne 3 ]; then
    printf "error: expecting 3 arguments, aborting... [%s]\n" "$*"
    usage
fi

echo "$(basename $0): DRY_RUN=$DRY_RUN" >$OUTPUT
echo "" >$OUTPUT

IF0="$1"
IF1="$2"
COMMAND="$3"

IF0_STATE=`ip -o link show | grep ${IF0%:*} | awk '{print $3}'`
IF1_STATE=`ip -o link show | grep ${IF1%:*} | awk '{print $3}'`

[ `echo "$IF0_STATE" | grep -wc "UP"` -eq 0 ] && { echo "$IF0: if is not UP, abort..."; exit 1; }
[ `echo "$IF1_STATE" | grep -wc "UP"` -eq 0 ] && { echo "$IF1: if is not UP, abort..."; exit 1; }

MAC0=`ifconfig $IF0 | awk '{for (I=1;I<=NF;I++) if ($I == "HWaddr") {print $(I+1)};}'`
IP0=`ifconfig $IF0 | awk '{for (I=1;I<=NF;I++) if ($I == "inet") {print $(I+1)};}' |sed 's/addr://'`
SUB0=`echo $IP0 | cut -s -f1-3 -d"."`
IP00=`echo $IP0 |sed s/$SUB0/11.0.0/` # benson - tbd: fix c type address assumption

MAC1=`ifconfig $IF1 | awk '{for (I=1;I<=NF;I++) if ($I == "HWaddr") {print $(I+1)};}'`
IP1=`ifconfig $IF1 | awk '{for (I=1;I<=NF;I++) if ($I == "inet") {print $(I+1)};}' |sed 's/addr://'`
SUB1=`echo $IP1 | cut -s -f1-3 -d"."`
IP11=`echo $IP1 |sed s/$SUB1/11.0.0/` # benson - tbd: fix c type address assumption

echo "$IF0: MAC0=$MAC0, IP0=$IP0, dummy IP=$IP00, state=$IF0_STATE."
echo "$IF1: MAC1=$MAC1, IP1=$IP1, dummy IP=$IP11, state=$IF1_STATE."
echo "Note: Please use the dummy IP addresses instead of the real ones !!!"

case $COMMAND in
    "up")
    [ "$DRY_RUN" == "off" ] && up_function
    ;;
    "down")
    [ "$DRY_RUN" == "off" ] && down_function
    ;;
    "show")
    show_function
    ;;
    "restart")
    down_function
    up_function
    ;;
    *)
    echo "Usage: $0 {up|down|show|restart}"
esac

echo "$(basename $0): done." >$OUTPUT
echo "" >$OUTPUT
exit 0




