#!/bin/sh
# UMH debug script for wait4cfm timeout issue
# All variables must be set by caller!

logfile=/tmp/umh_dbg.txt

echo "wait4cfm debug p0=$0 p1=$1 p2=$2" >> $logfile

[ "$1" = "wait4cfm" ] || exit 2 # not for us

## Create trace dump file only on the 1st time
#if ls /tmp/xt-trace-* > /dev/null 2>&1 ; then
#	exit 0
#fi

LA_CTRL_VAL=`cat /var/run/cl_la_ctrl`
echo "A_CTRL_VAL=$LA_CTRL_VAL" >> $logfile

# Determine whether LA runs in xtensa "enhanced" or legacy mode, and write corresponding stop bits:
# both the xtensa lmac stop bit and eLA ctrl_stop bit (0x2)
stopv=""
# Legacy mode?
[ "$LA_CTRL_VAL" = "0x00010209" ] && stopv=0x0002020A && suffx="std"
# Enhanced mode?
[ "$LA_CTRL_VAL" = "0x00018209" ] && stopv=0x0002820A && suffx="enh"
# UMAC Enhanced mode?
[ "$LA_CTRL_VAL" = "0x01008309" ] && stopv=0x0200830A && suffx="umac-enh"

printf "LA STOP VALUE=%8.8X\n" "$stopv" >> $logfile

[ "$stopv" = "" ] && { echo >> $logfile "Unknown LA mode" ; exit 1; }

source $cl_install_dir/scripts/fw.regs $3 || exit 3

mem $LA_CTRL_REG_ADDR w $stopv

mem $LA_STATUS_REG_ADDR >> $logfile

#Uncomment if you want also dmesg printout
# dmesg > /tmp/wait4cfm-dmesg.txt &

#eLA stopped. Now dump.
# Name the raw trace file with "std" or "enh", to remind how to decode it.

la_dump_mem --force /tmp/xt-trace-${suffx}.dmp
echo "la_dump_mem returned $?" >> $logfile

if true ; then
  SAVE_DIR=${cl_cfg_dir:?}
  echo "copying files: xt-trace-${suffx}.dmp and umh_dbg.txt into ${SAVE_DIR}" >> ${logfile}
  cp /tmp/xt-trace-${suffx}.dmp ${SAVE_DIR}
  cp ${logfile} ${SAVE_DIR}
  sync
fi

# Here you can ring bells, send emails...

