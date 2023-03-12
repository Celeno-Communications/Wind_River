#!/bin/bash

# Read MIB counters and print

source ./miblist.txt

# NOTE: Content of miblist.txt has been copied from excel, keep it updated.
# The reserved*N items are for ease of alignment with the excel table.
usage()
{
    echo  "-----------------------------------------------------"
    echo  "#  Usage:"
    echo  "#  mib_dump_Print <PHY> <CHIP> <MACHW_IDX> <PRINT_ALL_REGS>"
    echo  "#  PHY            = 0 / 1"
    echo  "#  CHIP           = 0 / 1"
    echo  "#  MACHW_IDX      = 0 / 1 / 2 / 3 / 4 / 5 / 6 / 7"
    echo  "#  PRINT_ALL_REGS = all / NONE"
    echo -e "#\n#  example: ' mib_dump_Print.sh 0 0 0 ' - dump registers values!=0 for primary idx 0 MACHW0"
    echo -e "#\n#  example: ' mib_dump_Print.sh 0 0 1 all' - dump all registers for primary idx 0 MACHW1"
    echo -e "#\n#  example: ' mib_dump_Print.sh 1 0 1 all' - dump all registers for secondary idx 0 MACHW1"
    echo  "-----------------------------------------------------"
    exit 1
}



setup() {
export LD_LIBRARY_PATH=/root/cl6000_fs/lib
export PATH=/root/cl6000_fs/bin:$PATH

case "$1" in
"0")
   PHY=0
   offset=0x0
   ;;
"1")
    PHY=1
    offset=0x80000
   ;;
*)
    echo "invalid PHY $1"
    usage
    exit 1
   ;;
esac

shift
case "$1" in
0)
   chip_idx="0"
   ;;
1)
    chip_idx="1"
   ;;
*)
    echo "invalid CHIP $1"
    usage
    exit 1
   ;;
esac

shift
case "$1" in
0)
   mac_hw_offset=0x0
   ;;
1)
    mac_hw_offset=0x10000
    ;;
2)
   mac_hw_offset=0x20000
   ;;
3)
    mac_hw_offset=0x30000
    ;;
4)
    if [[ "$PHY" = "0" ]]; then
        mac_hw_offset=0x40000
    else
        echo  "Invalid MACHW index:$1 for PHY: $PHY"
        usage
        exit 1
    fi
    ;;
5)
    if [[ "$PHY" = "0" ]]; then
        mac_hw_offset=0x50000
    else
        echo  "Invalid MACHW index:$1 for PHY: $PHY"
        usage
        exit 1
    fi
    ;;
6)
    if [[ "$PHY" = "0" ]]; then
        mac_hw_offset=0x60000
    else
        echo  "Invalid MACHW index:$1 for PHY: $PHY"
        usage
        exit 1
    fi
   ;;
7)
    if [[ "$PHY" = "0" ]]; then
        mac_hw_offset=0x70000
    else
        echo  "Invalid MACHW index:$1 for PHY: $PHY"
        usage
        exit 1
    fi
   ;;
*)
    echo  "invalid MACHW index: $1"
    usage
    exit 1
   ;;
esac

shift
case "$1" in
"all")
   print_all_regs=1
   ;;
"")
    print_all_regs=0
    ;;
*)
    echo  "invalid <PRINT_ALL_REGS> index"
    usage
    exit 1
   ;;
esac

source /var/run/cl6k_chip${chip_idx}.ini
vecho() {
  local x=1
  #echo $*
}

PCI_BASE_ADDR=${CL_PCI_BASE_ADDR?}
start=$(( $PCI_BASE_ADDR + $offset + $mac_hw_offset + 0x600800))
header() {
  echo "-----------------------------------------------------------------------------"
  echo "Counter                              Value            Dec.    Offs. Offs hex."
  echo "-----------------------------------------------------------------------------"
}

dump() {
  # param1 Counter name
  # param2 offset decimal
  local off_x4=$(($2 * 4))
  local addr=$(($start + $off_x4))
  local val=`mem $(($addr))`
  if [[ $print_all_regs -eq 0 ]] ; then
    if [[ $val != '00000000'  ]] ; then
        printf "%-36s 0x%8.8x %10u %6u   0x%8.8X\n" $1 0x$val 0x$val $off_x4 $addr
    fi
  else
    printf "%-36s 0x%8.8x %10u %6u   0x%8.8X\n" $1 0x$val 0x$val $off_x4 $addr

  fi
 }

footer() {
  echo "-----------------------------------------------------------------------------"
}


} # setup


# Check for reserved*N, Return number of.
reserved() {
   [ "${1/eserved/}" = "$1" ] && return 0
   vecho "Reserved... $1"
   local s=${1#*eserved}
   s=${s#\*}
   s=${s%%_*} # strip _comment
   vecho "Reserved [$s]"
   [ "$s" = "" ] && s=1
   return $s
}

main() {
  # Go thru whole list and print
  local off=0  NC=0  name

  header

  for name in ${MibVals}
  do
    reserved $name
    s=$?
    if [ $s -gt 0 ]; then
      vecho Skip $s from $off to $(($off+$s-1))
      let "off += $s"
        else
           dump $name $off
           let "off++"
           let "NC++"
        fi
  done

  footer

  echo "#Total number of counters=$NC"
  echo "#Last offset=$(( $off - 1 ))"
  echo "#Last addr=`printf 0x%8.8X $(( 4*($off - 1) + $start + 0))`"
}


#### MAIN ####
setup $1 $2 $3 $4
main
