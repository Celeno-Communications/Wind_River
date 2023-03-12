#!/bin/sh

if [ -z $cl_install_dir ] ; then
	echo "ERROR!!! missing env variable cl_install_dir"
fi

usage()
{
	echo "" >&2
	echo "Usage: $(basename $0) <BASE_ADDR> <NUM_OF_DWORDS>" >&2
	echo "" >&2
	echo "Example: $(basename $0) 0xC0008000 0x5" >&2
	echo "" >&2
	exit 2
}
if [ $# -ne 2 ]; then
	echo "" >&2
	printf "error: expecting 2 argument, aborting... [%s]\n" "$*"
	usage
fi

BASE_ADDR=$1
NUM_OF_DWORDS=$(($2))

echo "BASE_ADDR=$BASE_ADDR NUM_OF_DWORDS=$NUM_OF_DWORDS"

cnt=0

while [ "$cnt" -lt "$NUM_OF_DWORDS" ]
do
    # calc address from base
    addr=0x`printf "%X" $((BASE_ADDR+cnt*4))`
    val=0x`$cl_install_dir/bin/mem $addr`
    # read output data buffer into file
    echo "$cnt: $cl_install_dir/bin/mem $addr: $val"
    let cnt++
done

exit 0
