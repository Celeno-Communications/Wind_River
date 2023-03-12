#!/bin/bash

# Read BT debug counters and print

source ./bt_cntlist.txt

usage()
{
    echo  "-----------------------------------------------------"
    echo  "#  Usage:"
    echo  "#  bt_cnt_read <CHIP>"
    echo  "#  CHIP           = 0 / 1"
    echo -e "#\n#  example: ' bt_cnt_read.sh 0 ' - dump registers values!=0 for idx 0"
    echo  "-----------------------------------------------------"
    exit 1
}

setup() {
export LD_LIBRARY_PATH=/root/cl8000_fs/lib
export PATH=/root/cl8000_fs/bin:$PATH

case "$1" in
0)
   tcv_idx="0"
   ;;
1)
    tcv_idx="2"
   ;;
*)
    echo "invalid CHIP $1"
    usage
    exit 1
   ;;
esac

vecho() {
  local x=1
  #echo $*
}

offset=0x300000
start=$(($offset + 0x27800))
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
  addr_hex=$( printf "%x" $addr )
  local val=`iwcl wlan${tcv_idx}_0 cecli reg -r 0x$addr_hex`
  if [[ $print_all_regs -eq 0 ]] ; then
    if [[ $val != '0x00000000'  ]] ; then
        printf "%-36s 0x%8.8x %10u %6u   0x%8.8X\n" $1 $val $val $off_x4 $addr
    fi
  else
    printf "%-36s 0x%8.8x %10u %6u   0x%8.8X\n" $1 $val $val $off_x4 $addr

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

  for name in ${BTVals}
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
setup $1
main
