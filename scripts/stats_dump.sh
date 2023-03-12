#!/bin/sh

print_usage()
{
	echo "stats_dump.sh <tcv> <option> <title>"
	echo "   tcv = 0/1/2/3"
	echo "   option = rx/tx/reset/all"
	echo "   title = free text (optional)"

}

case "$1" in
	0)
		IFACE=wlan0_0
		;;
	1)
		IFACE=wlan1_0
		;;
	2)
		IFACE=wlan2_0
		;;
	3)
		IFACE=wlan3_0
		;;
	*)
		print_usage
		exit 1
		;;
esac

dump_rx_stats()
{
	echo "RX RATE STATS:"
	iwcl $IFACE cecli stats -r.255
	echo "RX RSSI STATS:"
	iwcl $IFACE cecli stats -s.255
	echo "RX UPLINK STATS:"
	iwcl $IFACE cecli stats -u.1
	echo "RX FIRMWARE STATS:"
	iwcl $IFACE cecli fw -s.3
}

dump_tx_stats()
{
	echo "TX RATE STATS:"
	iwcl $IFACE cecli stats -t.255
	echo "TX WRS STATS:"
	iwcl $IFACE cecli wrs -s.255.4
	echo "TX QUEUE STATS:"
	iwcl $IFACE cecli txq -a
	echo "TX GLOBAL STATS:"
	iwcl $IFACE cecli txq -c
	echo "TX AMSDU STATS:"
	iwcl $IFACE cecli txq -f
	echo "TX FIRMWARE STATS:"
	iwcl $IFACE cecli fw -s.2
}

reset_stats()
{
	echo "RESET"
	iwcl $IFACE cecli stats -z.255
	iwcl $IFACE cecli stats -u.0	
	iwcl $IFACE cecli wrs -r.255.4
	iwcl $IFACE cecli txq -r
	iwcl $IFACE cecli fw -s.0
}

dump_stats()
{
	case "$1" in
		rx)
			dump_rx_stats
			;;
		tx)
			dump_tx_stats
			;;
		reset)
			reset_stats
			;;
		all)
			dump_rx_stats
			sleep 1
			dump_tx_stats
			reset_stats
			;;
		*)
			print_usage
			exit 1
			;;
	esac
}

# Print title if exists
if [ -n "$3" ]; then
	echo -e "****************** $3 ******************\n"
fi

dump_stats $2
