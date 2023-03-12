#!/bin/bash
set -x #local echo
set -e
whoami
id

PID=${1:-XXX}
SIGNATURE="33de:$PID"

DEFAULT_APPLICATION=bin/emcpp_system_celeno_wifi/src/device/cli/bootloader_uio
APPLICATION=${2:-$DEFAULT_APPLICATION}

REMOTE_IMX8=ubuntu@imx8-1.lan.emsys.de
REMOTE_PI=pi@rpi-imx8-1.lan.emsys.de

CURRENT_DIR=$(dirname $0)

set +e
ssh $REMOTE_IMX8 "lsof -t /dev/uio0 | xargs kill -INT"
ssh $REMOTE_PI "sudo rmmod usbtpt"
set -e

ssh $REMOTE_IMX8 rm -rf ci
ssh $REMOTE_IMX8 mkdir ci
scp $APPLICATION $REMOTE_IMX8:~/ci

ssh $REMOTE_PI rm -rf ci
ssh $REMOTE_PI mkdir ci
scp $CURRENT_DIR/../functional_test/cli_command_test.py $REMOTE_PI:~/ci

# start device, should trigger new enumeration
# redirect stdout stderr and stdin
ssh $REMOTE_IMX8 nohup /home/ubuntu/ci/$(basename $APPLICATION) >/dev/null 2>/dev/null < /dev/null &

# give some time for enumeration to finish
sleep 3

echo "Check device has enumerated as VID:PID $SIGNATURE"
ssh $REMOTE_PI lsusb -d $SIGNATURE || (lsusb; echo "Device $SIGNATURE not found. Aborting!"; exit 1)

set +e
ssh $REMOTE_PI "rm -f /home/pi/ci/report.xml"
ssh $REMOTE_PI "cd /home/pi/ci && pytest --junitxml=report.xml"
set -e
scp $REMOTE_PI:/home/pi/ci/report.xml .

