btattach -S 921600 -B /dev/ttyUSB$1 -N -P celeno &
hciconfig hci$1 up

