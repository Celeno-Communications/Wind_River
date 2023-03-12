#!/bin/sh

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

# Usermode debug helper for kernel driver
# This may run in small crippled shells. No bash stuff here please.
# Assumes /tmp is writable. We need min. ~ 0.5 MB free
chip_idx=$1
tcv_idx=$2

. /var/run/cl6k_chip${chip_idx}.ini

wlan_idx=$(($chip_idx*2+$tcv_idx))
BASEPATH="/sys/kernel/debug/ieee80211/chip${chip_idx}/cl"

FOLDER="/$(NVG chip$chip_idx ci_lcu_dump_folder tmp)"
DIRN=ce_dump_tcv${tcv_idx}
NNN=1
DIRNAME=${DIRN}_${NNN}

true && {
    # For QA setup: get only 1st dump for all devices. Do not create more dumps,
    # try to disable further firmware restarts.
    ls -d "$FOLDER/ce_dump_tcv*" && {
       echo > /dev/kmsg "UMH: dump already exists, not creating more dumps and disable fw restart"
       iwcl wlan${wlan_idx}_0 cecli tcv ce_fw_watchdog_mode=0
       echo > /dev/kmsg "<1>UMH: exiting"
       exit 6
    }
}

false && {
    # Stop dumps for this device only but do not touch the other device
    ls -d "$FOLDER/${DIRN}_*" && {
       echo > /dev/kmsg "UMH: dump for $DIRN already exists, not creating more dumps and disable fw restart"
       iwcl wlan${wlan_idx}_0 cecli tcv ce_fw_watchdog_mode=0
       echo > /dev/kmsg "<1>UMH: exiting"
       exit 7
    }
}

while true ; do
  DIRNAME=${DIRN}_${NNN}
  DIRPATH=$FOLDER/$DIRNAME
  if [ -e ${DIRPATH}.tbz -o -e ${DIRPATH} ] ; then
    NNN=$(( NNN + 1 ))
    [ "$NNN" -lt 10 ] && continue
    echo > /dev/kmsg "<1>UMH: too many dumps. Exiting"
    # TODO delete some old dumps?
    exit 3
  fi
  mkdir $DIRPATH && break
  NNN=$(( NNN + 1 ))
done

# Save stderr to file:
exec 2> $DIRPATH/umh_exec_err 1>&2

cd $DIRPATH

echo "UMH $0 $*" >README_UMH
echo "ASIC_VER=$ASIC_VER" >README_UMH
date +"%F-%Hh%Mm%S" >>README_UMH
uptime >>README_UMH

dmesg > ./dmesg

# Start collecting data...
for i in ${BASEPATH}/diags/*; do
  cat $i > ./$(basename $i) || rm ./$(basename $i)
done


ls /tmp/dbg_dump_file_tcv_${tcv_idx}.txt && {
    mv /tmp/dbg_dump_file_tcv_${tcv_idx}.txt .
}

# If eLA config file exist copy it to dump
ls -la /var/run/lcu"$chip_idx".conf && {
    conf_name=$(basename $(ls -la /var/run/lcu"$chip_idx".conf | awk '{print $NF}'))
    echo "$conf_name"
    cp /var/run/lcu"$chip_idx".conf ./$conf_name
}

lcumode=`cat /var/run/lcu"$chip_idx".mode`

echo "$lcumode" > ./lcu.mode
echo "cl_umh.sh: LCU mode is $lcumode"

case ${lcumode} in
    mac | phy | bt)
      # Attempt to generate VCD file
      cp $cl_install_dir/scripts/dbg/hwdiag.txt .
      cp $cl_install_dir/scripts/dbg/btdiag.txt .
      $cl_install_dir/bin/genvcd .
      ;;
    *)
      # Dump raw eLA data if available
      $cl_install_dir/bin/genvcd . la_raw_dump.txt || true
      ;;
esac

echo >>README_UMH "Debug data collection done."
cd ..

if [ -z "$CL_UMH_NO_PACK" ] ; then
  [ -e ${DIRNAME}.tbz ] && mv ${DIRNAME}.tbz ${DIRNAME}.tbz.OLD
  [ -e ${DIRNAME}.tar ] && rm ${DIRNAME}.tar
  # Tar & bzip in one command did not work for some reason...
  tar cf ${DIRNAME}.tar -C ${DIRPATH} ./
  bzip2 ${DIRNAME}.tar
  mv ${DIRNAME}.tar.bz2 ${DIRNAME}.tbz
fi

#TODO: Move the archive to external storage if desired

false && {
  # Delete previous dump dir:
  # Link /tmp/umh_dir to the new dump...
  rm ./umh_dir || true
  ln -sf $DIRNAME umh_dir
}

true && {
  # Delete all uncompressed dirs
  find $DIRNAME -type d -name "$DIRN*" -maxdepth 2 -exec rm -rf {} \;
}

#sync
exit 0

