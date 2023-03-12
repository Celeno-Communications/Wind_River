#/bin/sh

source $cl_install_dir/scripts/usleep.sh

chip_idx=$1
rescan=$2

. /var/run/cl6k_chip${chip_idx}.ini

if [ "$rescan" == "1" ]; then
	echo -n 1 > $CL_SYS_DEV_PATH/remove
	sleep 1
	echo -n 1 > /sys/bus/pci/rescan
	sleep 1
	echo -n 1 > $CL_SYS_DEV_PATH/enable
fi
