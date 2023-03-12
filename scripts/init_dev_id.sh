#! /bin/sh

init_device_id_pci()
{
	i=0

	for device in /sys/bus/pci/devices/*;
	do
		if test -f "$device/vendor"; then
			vendor="$(cat $device/vendor)"
			if [ "$vendor" == "0x${ce_vendor_id_pci}" ]; then
				local ce_device_id="$(cat $device/device)"
				DEV_IDS[i]="$ce_device_id"
				((i=i+1))
			fi
		fi
	done
}

init_device_id_usb()
{
	i=0

	for device in /sys/bus/usb/devices/*;
	do
		if [ -f $device/idVendor ]; then
			vendor="$(cat $device/idVendor)"
			if [ "$vendor" == "${ce_vendor_id_usb}" ]; then
				local ce_device_id="$(cat $device/idProduct)"
				local serial="$(cat $device/serial)"

				DEV_IDS[i]="$ce_device_id"
				SER_NUMS[i]="$serial"

				if [ $i -eq 0 ]; then
					((i=i+1))
					continue
				fi

				for idx in $(seq $((i - 1)) -1 0); do
					if [ $ce_device_id -lt ${DEV_IDS[$idx]} ]; then
						_tmp=${DEV_IDS[$idx]}
						DEV_IDS[$idx]=${DEV_IDS[$idx + 1]}
						DEV_IDS[$idx + 1]=$_tmp
						_tmp=${SER_NUMS[$idx]}
						SER_NUMS[$idx]=${SER_NUMS[$idx + 1]}
						SER_NUMS[$idx + 1]=$_tmp
					elif [ $ce_device_id -eq ${DEV_IDS[$idx]} ]; then
						if [[ $serial -lt ${SER_NUMS[$idx]} ]]; then
							_tmp=${SER_NUMS[$idx]}
							SER_NUMS[$idx]=${SER_NUMS[$idx + 1]}
							SER_NUMS[$idx + 1]=$_tmp
						fi
					else
						break
					fi
				done
				((i=i+1))
			fi
		fi
	done
}

reset_gpio_bu_workaround()
{
	local chip_idx=0
	local id=-1

	while [ "$chip_idx" -lt "$CHIP_NUM" ]; do
		if [ -f $cl_cfg_dir/cl_chip$chip_idx.dat ]; then
			id=`$cl_install_dir/scripts/nvram_get chip$chip_idx ce_rst_gpio`
		fi
		#Reset chip via GPIO line (If GPIO exists)
		if [ -n "${id}" ] && [ $id -ge 0 ]; then
			echo "!!! reset gpio #$id !!!"
			echo -n $id > /sys/class/gpio/export
			if [ "$?" == "1" ]; then
				echo -n $id > /sys/class/gpio/unexport
				echo -n $id > /sys/class/gpio/export
			fi
			echo -n out > /sys/class/gpio/gpio$id/direction
			echo -n 0 > /sys/class/gpio/gpio$id/value
			usleep 200000
			echo -n 1 > /sys/class/gpio/gpio$id/value
			echo -n $id > /sys/class/gpio/unexport
		fi
		chip_idx=$((chip_idx+1))
	done
}

init_device_id()
{
	i=0

	source "$cl_install_dir/scripts/env.sh" || {
		echo "env.sh missing, please make sure that cl_install_dir is set properly ..."
		exit 1
	}

	init_device_id_pci
	if [ "$i" == "0" ]; then
		init_device_id_usb
	fi
}

CHIP_NUM=4
declare -a DEV_IDS
declare -a SER_NUMS

init_device_id

if [ $i -lt 2 ]; then
	echo "!!! found $i chips - try to reset gpio !!!"
	reset_gpio_bu_workaround
	sleep 3
	init_device_id
	echo "!!! found $i chips !!!"
fi
