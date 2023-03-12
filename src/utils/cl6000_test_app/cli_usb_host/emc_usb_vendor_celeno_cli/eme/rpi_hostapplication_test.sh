#! /usr/bin/env bash

set -x #local echo
set -e

whoami
id

REMOTE_IMX8=ubuntu@imx8-1.lan.emsys.de
REMOTE_PI=pi@rpi-imx8-1.lan.emsys.de

VID="33de"
PID="6000"
BCD=${1:-XXX}

SIGNATURE="${VID}:${PID}"
DEFAULT_APPLICATION=bin/emcpp_system_celeno_wifi/src/device/cli/bootloader_uio
APPLICATION=${2:-$DEFAULT_APPLICATION}
CURRENT_DIR=$(dirname $0)

# may fail if directory does not exist or no application using uio
ssh $REMOTE_PI rm -rf ci

set +e
ssh $REMOTE_IMX8 "lsof -t /dev/uio0 | xargs kill -INT"
set -e

ssh $REMOTE_IMX8 rm -rf ci
ssh $REMOTE_IMX8 mkdir ci
scp $APPLICATION $REMOTE_IMX8:~/ci

commit_hash="$(git rev-parse HEAD)"
archive_name="$commit_hash.tar.gz"
git archive --format=tar.gz $commit_hash -o  $archive_name

ssh $REMOTE_PI mkdir ci
# copy archive to raspberry
scp $archive_name $REMOTE_PI:~/ci
# unpack on raspberry
echo "cd ci; tar -xf $archive_name" | ssh $REMOTE_PI bash -C
# configure on raspberry
echo "cd ci; cmake -H. -Bbuild -GNinja -DCMAKE_TOOLCHAIN_FILE=eme/toolset/gcc8x64/toolset.cmake -DUSECASE=emcpp_system_celeno_wifi/eme/host_cli.usecase.cmake" | ssh $REMOTE_PI bash -C
# build on raspberry
echo "cd ci; ninja -C build HostGenericProtocol_functional_test HostExtendedProtocol_functional_test LibUsbConnectionSpeed" | ssh $REMOTE_PI bash -C


# start device, should trigger new enumeration
# redirect stdout stderr and stdin
ssh $REMOTE_IMX8 nohup /home/ubuntu/ci/$(basename $APPLICATION) -s 4 >/dev/null 2>/dev/null < /dev/null &

# give some time for enumeration to finish
sleep 3


echo "Check device has enumerated as VID:PID $SIGNATURE"
ssh $REMOTE_PI lsusb -d $SIGNATURE -v || (echo "Device $SIGNATURE not found. Aborting!"; exit 1)

echo "Check device is running expected firmware version"
ssh $REMOTE_PI lsusb -d $SIGNATURE -v | grep ${BCD} || (echo "Expected firmware version $BCD not found. Aborting!"; exit 1)

SPEED_OUTPUT=$(ssh $REMOTE_PI "sudo ./ci/build/emc_usb_vendor_celeno_cli/src/host/test/LibUsbConnectionSpeed 0x${VID} 0x${PID} 2>&1")
echo $SPEED_OUTPUT
if ! echo "$SPEED_OUTPUT" | grep --silent "speed=SS"; then
  echo "Abort: Speed missmatch - SS device expected."
  exit 1
fi

# start host test on raspberry
ssh $REMOTE_PI "./ci/build/emc_usb_vendor_celeno_cli/src/host/test/HostGenericProtocol_functional_test 0 1000 0x${PID}"
ssh $REMOTE_PI "./ci/build/emc_usb_vendor_celeno_cli/src/host/test/HostGenericProtocol_functional_test 0x40000000 1000 0x${PID}"
ssh $REMOTE_PI "./ci/build/emc_usb_vendor_celeno_cli/src/host/test/HostGenericProtocol_functional_test 0x40080000 1000 0x${PID}"
ssh $REMOTE_PI "./ci/build/emc_usb_vendor_celeno_cli/src/host/test/HostGenericProtocol_functional_test 0x60000000 1000 0x${PID}"

ssh $REMOTE_PI "./ci/build/emc_usb_vendor_celeno_cli/src/host/test/HostExtendedProtocol_functional_test 0x${PID}"

# start host test on raspberry, only bootloader app can have hs/fs speed limitation
if [[ $BCD == "0.10" ]]; then
  # run tests with high speed
  ssh $REMOTE_IMX8 sudo killall $(basename $APPLICATION)
  ssh $REMOTE_IMX8 nohup /home/ubuntu/ci/$(basename $APPLICATION) -s 3 >/dev/null 2>/dev/null < /dev/null &

  # give some time for enumeration to finish
  sleep 3

  echo "Check device has enumerated as VID:PID $SIGNATURE"
  ssh $REMOTE_PI lsusb -d $SIGNATURE -v || (echo "Device $SIGNATURE not found. Aborting!"; exit 1)

  echo "Check device is running expected firmware version"
  ssh $REMOTE_PI lsusb -d $SIGNATURE -v | grep ${BCD} || (echo "Expected firmware version $BCD not found. Aborting!"; exit 1)

  SPEED_OUTPUT=$(ssh $REMOTE_PI "sudo ./ci/build/emc_usb_vendor_celeno_cli/src/host/test/LibUsbConnectionSpeed 0x${VID} 0x${PID} 2>&1")
  echo $SPEED_OUTPUT
  if ! echo "$SPEED_OUTPUT" | grep --silent "speed=HS"; then
    echo "Abort: Speed missmatch - HS device expected."
    exit 1
  fi
  ssh $REMOTE_PI "./ci/build/emc_usb_vendor_celeno_cli/src/host/test/HostGenericProtocol_functional_test 0 1000 0x${PID}"
  ssh $REMOTE_PI "./ci/build/emc_usb_vendor_celeno_cli/src/host/test/HostExtendedProtocol_functional_test 0x${PID}"

  # run tests with full speed
  ssh $REMOTE_IMX8 sudo killall $(basename $APPLICATION)
  ssh $REMOTE_IMX8 nohup /home/ubuntu/ci/$(basename $APPLICATION) -s 2 >/dev/null 2>/dev/null < /dev/null &

  # give some time for enumeration to finish
  sleep 3

  echo "Check device has enumerated as VID:PID $SIGNATURE"
  ssh $REMOTE_PI lsusb -d $SIGNATURE -v || (echo "Device $SIGNATURE not found. Aborting!"; exit 1)

  echo "Check device is running expected firmware version"
  ssh $REMOTE_PI lsusb -d $SIGNATURE -v | grep ${BCD} || (echo "Expected firmware version $BCD not found. Aborting!"; exit 1)

  SPEED_OUTPUT=$(ssh $REMOTE_PI "sudo ./ci/build/emc_usb_vendor_celeno_cli/src/host/test/LibUsbConnectionSpeed 0x${VID} 0x${PID} 2>&1")
  echo $SPEED_OUTPUT
  if ! echo "$SPEED_OUTPUT" | grep --silent "speed=FS"; then
    echo "Abort: Speed missmatch - FS device expected."
    exit 1
  fi
  ssh $REMOTE_PI "./ci/build/emc_usb_vendor_celeno_cli/src/host/test/HostGenericProtocol_functional_test 0 1000 0x${PID}"
  ssh $REMOTE_PI "./ci/build/emc_usb_vendor_celeno_cli/src/host/test/HostExtendedProtocol_functional_test 0x${PID}"
fi
