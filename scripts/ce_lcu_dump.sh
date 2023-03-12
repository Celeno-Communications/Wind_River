#!/bin/sh
# stop LCU & dump LCU memory of chip[ID] according to /var/run/lcu[ID].mode
# save dump as mactrace/xmactrace file.
# In mac/phy modes save also LCU registers as lamacconf file.
# Example: "sudo -E VERBOSE=on ce_lcu_dump.sh 0"

DRY_RUN=${DRY_RUN:="off"}
chip_idx="$1"
LCU_DUMP_DIR="$2"

if [ "$VERBOSE" == "on" ]; then
verbose="on"
V_OPT="-v"
fi

[ -z "$LCU_DUMP_DIR" ] && LCU_DUMP_DIR="/tmp"

LCU_DUMP_FILE="$LCU_DUMP_DIR/mactrace"
LCU_CFG_FILE="$LCU_DUMP_DIR/lamacconf"

lcu_config_flag="off"
xmac_flag="off"

. /var/run/cl6k_chip"$chip_idx".ini
. $cl_install_dir/scripts/ce_mem.inc

if [ -z "$CL_PCI_BASE_ADDR" ]; then
    echo "ERROR: CL_PCI_BASE_ADDR must be defined"
    exit 1
fi

if [ -z "$CL_HW_MODEL" ]; then
    echo "WARNING: CL_HW_MODEL is not defined, assuming ASIC..."
    CL_HW_MODEL="CL_ASIC"
fi

lcu_config_get()
{
    mem_read 0x7CF04C > $LCU_CFG_FILE
}

usage()
{
    echo "" >&2
    echo "Usage: $(basename $0) chip_idx [dump_dir - optional]" >&2
    echo "" >&2
    echo "chip_idx lmac/smac/umac - stop lcu and save lcu memory to file." >&2
    echo "chip_idx mac - stop lcu save lcu memory and configuration to files" >&2
    echo "chip_idx phy - stop lcu save lcu memory and configuration to files" >&2
    echo "" >&2
    echo "Example: $(basename $0) 0 /tmp" >&2
    echo "" >&2
    echo "If lmac/smac/umac - Raw data will be written to file, copy to PC to decode." >&2
    exit 2
}

if [ "$#" -lt 1 ]; then 
    usage
fi

lcu_mode=`cat /var/run/lcu"$chip_idx".mode`

case "$lcu_mode" in
    "lmac"|"smac"|"umac") xmac_flag="on"; LCU_DUMP_FILE="$LCU_DUMP_DIR"/"$lcu_mode"trace ;;
    "mac"|"phy") lcu_config_flag="on" ;;
    *) echo "unknown lcu_mode [$lcu_mode], abort ... "; usage ;;
esac

[ "$verbose" == "on" ] && echo "$0: lcu_mode=$lcu_mode"

## LCU_COMMON_REC_CMD - Stop LCU
mem_write 0x7CF020 0x4

## Read all LCU configuration registers into a file
[ "$lcu_config_flag" == "on" ] && lcu_mem $V_OPT -c "$LCU_CFG_FILE" cfg_file

## dump LCU buffer into a file
lcu_mem $V_OPT -f "$LCU_DUMP_FILE" dump || echo "lcu_mem returned error $?"

[ "$verbose" == "on" ] && echo "Done"

[ "$xmac_flag" == "on" ] && echo "Now copy the file $LCU_DUMP_FILE to a PC and run decoder parse_xt_trace.py"

