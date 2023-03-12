#!/bin/sh
VERBOSE=${VERBOSE:="off"}
DRY_RUN=${DRY_RUN:="off"}
OUTPUT=${OUTPUT:="/dev/null"}
chip_idx=${chip_idx:=0}

source "$cl_install_dir/scripts/env.sh" || {
    echo "env.sh missing, please make sure that cl_install_dir is set properly ..."
    exit 1
}

if [ ! -f /var/run/cl6k_chip"$chip_idx".ini ]; then
    echo "/var/run/cl6k_chip"$chip_idx".ini is missing"
    exit 1
fi

. /var/run/cl6k_chip"$chip_idx".ini
if [ -z "$CL_PCI_BASE_ADDR" ]; then
    declare -x CL_PCI_BASE_ADDR="0x0"
fi

. $cl_install_dir/scripts/usleep.sh

NVG="$cl_install_dir/scripts/nvram_get chip${chip_idx}"

g_phy0_disabled=0 # enabled by default

g_phy_dev=$($NVG ci_phy_dev)

[ "$VERBOSE" == "on" ] && OUTPUT="/dev/stdout"
[ "$DRY_RUN" == "on" ] && echo "ce_mem.inc: ci_phy_dev=$g_phy_dev"

if [ -z "$CL_HW_MODEL" ]; then
    echo "WARNING: CL_HW_MODEL is not defined, assuming ASIC..."
    CL_HW_MODEL="CL_ASIC"
fi

get_phy_access()
{
    case "${g_phy_dev}" in
    "0"|"1"|"4")
    # OLYMPUS\ATHOS: ASIC - PHY0+PHY1
    # LB: B2B,PALLADIUM,PROTIUM - PHY0+PHY1
    local force_tcv0=$($NVG ci_force_tcv0_only)
    [ -z "$force_tcv0" ] && force_tcv0=0
    [ "$force_tcv0" == "1" ]
    ;;
    2)
    # DUMMY: PALLADIUM,PROTIUM - no PHY
    g_phy0_disabled=1
    ;;
    3)
    # FRU: B2B - PHY0 only
    g_phy0_disabled=0
    ;;
    *)
    g_phy0_disabled=0
    ;;
    esac
}

# Syntax:
# mem_read <address>
# Parameters:
# address - destination physical memory address to read from
# Description:
# Execute a 32b read operation
mem_read()
{
    local offset=$1
    local val=0

    get_phy_access

    # If PHY0 is disabled here avoid reading its registers
    if [ "$g_phy0_disabled" == "1" -a $(( offset & 0xF00000 )) -eq $(( 0x400000 )) ]; then
        return 0
    fi

    addr=`printf "%X" $(($CL_PCI_BASE_ADDR + $offset))`

    if [ "$DRY_RUN" == "on" ]; then
        val=12345678
        #echo "mem 0x$addr"
    else
        val=`mem 0x"$addr"`
    fi

    echo "$val"
}

# Syntax:
# mem_write <address> <data>
# Parameters:
# address - destination physical memory address to write to
# data - the 32b data to be written
# Description:
# Execute a 32b write operation
mem_write()
{
    local offset=$1
    local val=$2

    get_phy_access

    # If PHY0 is disabled here avoid writing to its registers
    if [ "$g_phy0_disabled" == "1" -a $(( offset & 0xF00000 )) -eq $(( 0x400000 )) ]; then
        return 0
    fi

    addr=`printf "%X" $(($CL_PCI_BASE_ADDR + $offset))`

    if [ "$DRY_RUN" == "on" ]; then
        echo "mem 0x$addr w $val"
    else
	if lsmod | grep -q "cl_core" ; then
		iwcl wlan0_0 cecli reg -w.0x60"$addr"."$val"
	else
		mem 0x"$addr" w "$val"
	fi
    fi
}

mem_write_burst()
{
    local offset
    local val

    read -ra ARR <<< $*
    echo "mem_write_burst: entry. [${ARR[@]}]" > ${OUTPUT}
    base_offset=${ARR[0]}
    val=${ARR[1]}

    echo "mem_write_burst: offset=$base_offset, val=$val." > ${OUTPUT}
    mem_write "$base_offset" "$val"

    arr_idx=0
    for param in ${ARR[@]}; do
        [[ arr_idx -lt 2 ]] && { let arr_idx=$arr_idx+1; continue; }
        let offset_idx=$arr_idx-1
        offset=`printf "0x%X" $((base_offset+4*offset_idx))`
        echo "mem_write_burst: offset=$offset, param=$param." > ${OUTPUT}
        mem_write "$offset" "$param"
        let arr_idx=$arr_idx+1
    done
}

mem_read_verify()
{
    local offset
    local val

    read -ra ARR <<< $*
    echo "mem_read_verify: entry. [${ARR[@]}]" > ${OUTPUT}
    base_offset=${ARR[0]}
    expected_val=${ARR[1]}
    [[ -n ${ARR[2]} ]] && expected_mask=${ARR[2]} || expected_mask=0xFFFFFFFF

    val=0x`mem_read "$base_offset"`
    echo "mem_read_verify: val=$val" > ${OUTPUT}

    val_masked=`printf "0x%X" $(( val & expected_mask ))`
    exp_masked=`printf "0x%X" $(( expected_val & expected_mask ))`
    echo "mem_read_verify: val_masked=$val_masked, exp_masked=$exp_masked" > ${OUTPUT}

    if [ x"exp_masked" == x"0" ]; then
        echo "mem_read_verify: warning - exp_masked value 0 (expected_val=$expected_val, expected_mask=$expected_mask)"
    fi

    if [ x"$val_masked" == x"$exp_masked" ]; then
        echo "mem_read_verify: got expected value" > ${OUTPUT}
        echo "$val"
    else
        echo "mem_read_verify: got un-expected value !!! (val_masked=$val_masked, exp_masked=$exp_masked)"
        exit 1
    fi
}

mem_rmw()
{
    local offset
    local val

    read -ra ARR <<< $*
    echo "mem_rmw: entry. [${ARR[@]}]" > ${OUTPUT}
    offset=${ARR[0]}
    mask=${ARR[1]}
    lsb=${ARR[2]}
    write_val=${ARR[3]}

    # read
    val=`mem_read "$offset"`
    echo "mem_rmw: read value=$val" > ${OUTPUT}

    # modify
    val=`printf "0x%X" $(( val & ~mask ))`
    echo "mem_rmw: read value after mask=$val" > ${OUTPUT}
    write_val=`printf "0x%X" $(( write_val << lsb))`
    echo "mem_rmw: write value after shift=$write_val" > ${OUTPUT}
    val=`printf "0x%X" $(( write_val | val))`

    # write
    echo "mem_rmw: offset=$offset, val=$val." > ${OUTPUT}
    mem_write "$offset" "$val"
}

mem_delay()
{
    echo "delay: entry. [$1] micro-seconds" > ${OUTPUT}
    usleep "$1"
}

# Syntax:
# mem_poll <address> <value> <timeout>
# Parameters:
# address - destination physical memory address to read from
# value - the value we expect to read before moving on to next command
# timeout - maximum time to wait for expected value in microseconds
# Description:
# Execute a while loop as long as the read value is different from the requested value,
# or the timeout has been reached. If timeout reached - test fails.
mem_poll()
{
    local offset
    local val

    read -ra ARR <<< $*
    echo "mem_poll: entry. [${ARR[@]}]" > ${OUTPUT}
    offset=${ARR[0]}
    expected=${ARR[1]}
    timeout=${ARR[2]}
    
    # make sure we have minimal 100 micro timeout
    [ -z "$timeout" ] && timeout=100
    [[ timeout -le 100 ]] && timeout=100

    echo "mem_poll: timeout=$timeout" > ${OUTPUT}

    # loop until success or timeout
    while [[ timeout -ge 100 ]]
    do
        # read
        val=0x`mem_read "$offset"`
        echo "mem_poll: read value=$val" > ${OUTPUT}
        # verify
        if [ x"$val" == x"$expected" ]; then
            echo "mem_poll: got expected value" > ${OUTPUT}
            return
        fi

        echo "mem_poll: usleep (timeout=$timeout val=$val, expected=$expected)"
        # sleep 100 micro, increment timeout and try again
        usleep 100
        let timeout=$timeout-100
    done

    # if we are here we got timeout - exit process
    echo "mem_poll: timeout occured !!! (val=$val, expected=$expected)"
    exit 1
}

mem_load_file()
{
    local offset
    local addr
    local val

    echo "mem_load_file: entry. [$1,$2]" > ${OUTPUT}
    file_name="$1"
    base_addr="$2"

    # make sure the file exist
    [ ! -f $file_name ] && { echo "$file_name not found"; exit 1; }

    if [ -x $cl_install_dir/bin/cl6000_boot ]; then
        file_basename=`basename $file_name`
        file_dirname=`dirname $file_name`
        echo "mem_load_file: load $file_basename from $file_dirname using cl6000_boot" > ${OUTPUT}
        cl6000_boot -b 5g -p "$file_dirname" load_file "$file_basename" "$base_addr"
    else
        # read bin file into lines of [[offest] [32b hex number]] couples.
        file_data=`od -v -Ax -t x4 -w4 $file_name`

        # loop over [[offest] [32b hex number]] couples
        while IFS=' ' read offset val
        do
            echo "mem_load_file: offset=$offset val=$val" > ${OUTPUT}
            [ -z $val ] && { echo "WARNING: undefined value for offset=$offset"; continue; }
            addr=`printf "0x%X" $(( base_addr + 0x$offset ))`
            val=0x"$val"
            mem_write "$addr" "$val"
        done<<<$file_data
    fi
}
