#!/bin/sh

THIS_SCRIPT=$0
dbg_dir="$cl_install_dir/scripts/dbg"
tcv=$1
iwcl=$cl_install_dir/bin/iwcl
ce_dump_file=/tmp/ce_dump_tcv${tcv}_1.tar
mactrace_dir=/tmp/tmp_mactrace
server_addr="172.18.2.111"
server_user="math"
server_path="c:\\calib\\"

if [[ -f $ce_dump_file ]]; then
	rm $ce_dump_file
fi

if [[ -d $mactrace_dir ]]; then
	rm $mactrace_dir/*
else
	mkdir $mactrace_dir
fi


$iwcl wlan${tcv}_0 cecli lcu -c.0x3f.0.0.1
$dbg_dir/debugfsh 0 ${tcv} mactrace 1

while :
do
#	echo "Pres CTRL+C to stop..."
#	sleep 1
	if [[ -f $ce_dump_file ]]; then
		tar xvf $ce_dump_file -C /tmp/tmp_mactrace
		break
	fi
done

sshpass -p Heshbon4$ scp -oStrictHostKeyChecking=no /tmp/tmp_mactrace/mactrace math@172.18.2.111:$server_path

exit 0
