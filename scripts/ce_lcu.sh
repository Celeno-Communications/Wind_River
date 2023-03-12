#!/bin/sh
# Configure firmware LCU debug
#
# Arg1: lcu configuration script name 
# Exit codes:
# * 0 is success of course.
# * Other values are fatal errors

THIS_SCRIPT=$0
VERBOSE="off"
dbg_dir="$cl_install_dir/scripts/dbg"
export chip_idx=$1
lcu_conf_file=$2

. $cl_install_dir/scripts/ce_mem.inc

source $cl_install_dir/scripts/fw.regs ${chip_idx} || noisy_error "Failed $cl_install_dir/scripts/fw.regs Bad PATH?"

noisy_error() {
    echo "${THIS_SCRIPT}: ERROR: " $*
    for e in PATH cl_install_dir CL_PCI_BASE_ADDR ; do
        eval "echo $e = \$$e"
    done
    #read
    exit 1
}

reset_lcu()  {
    # Clear eLA memory:
    mem_init LA_RAM || noisy_error "mem_init failure"
    # Reset LCU:
    mem_write "$LCU_COMMON_SW_RST_ADDR" 0x1
    mem_write "$LCU_PHY0_SW_RST_ADDR" 0x1
}

# Default Config file for LCU is pointed by "lcu_default.conf" link
if [ "$lcu_conf_file" == "default" ]; then
lcu_conf_file=$(readlink -f $dbg_dir/lcu_default.conf)
else
lcu_conf_file=$dbg_dir/$lcu_conf_file
fi

# Verify we have a valid conf file
if [ ! -x ${lcu_conf_file} ]; then
    noisy_error "${lcu_conf_file} not found"
    exit 1
fi

# Read lcu conf file name into an array - tokens separated by "_"
IFS='_' read -ra ARR <<< $(basename "$lcu_conf_file")

[ "${ARR[0]}" != "lcu" ] && noisy_error "unexpected config file prefix [${ARR[0]}], abort ..."

case "${ARR[1]}" in
    "mac"|"phy"|"bt") lcu_mode="${ARR[1]}" ;;
    ?"mac") lcu_mode="${ARR[1]}" ;;
    *) noisy_error "unexpected config file mode [${ARR[1]}], abort ..." ;;
esac

# Remember active lcu mode
echo "$lcu_mode" > /var/run/lcu"$chip_idx".mode
# Remember active lcu config
ln -sf ${lcu_conf_file} /var/run/lcu"$chip_idx".conf

reset_lcu && echo "ce_lcu.sh: Reset LCU (CHIP=$chip_idx)..."

echo "ce_lcu.sh: CHIP=${chip_idx} ${lcu_conf_file}"
VERBOSE="$VERBOSE" ${lcu_conf_file} || noisy_error "LCU config failed, trace will not run"

exit 0
