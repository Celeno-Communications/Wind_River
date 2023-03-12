#!/bin/sh
#parameter 1 - matlab pc username - Math.Amir
#parameter 2 - matlab pc ip       -10.14.86.45
#parameter 3 - matlab input filename
ssh_version=$(ssh -V 2>&1)
echo ${ssh_version}
drop='Dropbear v2019.78'                              
if [[ $ssh_version == *"Dropbear v2019.78"* ]]; then
    board_ip=$(ifconfig eth1| grep -Eo 'inet (addr:)?([0-9]*\.){3}[0-9]*' | grep -Eo '([0-9]*\.){3}[0-9]*' | grep -v '127.0.0.1')
    board_mac_addr=$(ifconfig eth0 | grep -o -E '([[:xdigit:]]{1,2}:){5}[[:xdigit:]]{1,2}')
    echo -e "host_id=${board_mac_addr}" >> /tmp/$3
    dropbearconvert openssh dropbear /tmp/build/scripts/Matlab_calib/id_rsa /tmp/build/scripts/Matlab_calib/id_dropbear
    ssh -y -i /tmp/build/scripts/Matlab_calib/id_dropbear $1@$2 'C:\izik\denali_matlab.bat '${board_ip}''
else
    board_ip=$(ifconfig eth1| grep -Eo 'inet (addr:)?([0-9]*\.){3}[0-9]*' | grep -Eo '([0-9]*\.){3}[0-9]*' | grep -v '127.0.0.1')
    board_mac_addr=$(ifconfig eth0 | grep -o -E '([[:xdigit:]]{1,2}:){5}[[:xdigit:]]{1,2}')
    echo -e "host_id=${board_mac_addr}" >> /tmp/$3
    ssh -oStrictHostKeyChecking=no -i /tmp/build/scripts/Matlab_calib/id_rsa $1@$2 'C:\izik\denali_matlab.bat '${board_ip}''
fi
exit