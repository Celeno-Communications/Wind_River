#!/bin/sh

export LD_LIBRARY_PATH=/root/cl6000_fs/lib\n
export PATH=/root/cl6000_fs/bin:$PATH\n

usage()
{
	echo "-----------------------------------------------------"
	echo "#  Usage:"
	echo "#  debugfsh <PHY> <CHIP> <FILE> <values..>"
	echo "#  PHY  = 0 / 1"
	echo "#  CHIP = 0 / 1"
	echo -e "#\n#  example: ' dbg_per.sh 0 0' " 
	echo "-----------------------------------------------------"
	exit 1
}

case "$1" in
0)
	PHY=0
	offset=0x400000
	;;
1)
	PHY=1
	offset=0x500000
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

source /var/run/cl6k_chip${chip_idx}.ini

PCI_BASE_ADDR=${CL_PCI_BASE_ADDR?}
echo $PCI_BASE_ADDR
echo $offset

digital_gain_addr="($PCI_BASE_ADDR + $offset + 0x0097c)"
digital_gain=$(mem $(($PCI_BASE_ADDR + $offset + 0x0097c)))

evm_val_addr="($PCI_BASE_ADDR + $offset + 0x00738)"
evm_val=$(mem $(($PCI_BASE_ADDR + $offset + 0x00738)))

n_symbol_addr="($PCI_BASE_ADDR + $offset + 0x0073C)"
n_symbol=$(mem $(($PCI_BASE_ADDR + $offset + 0x0073C)))

adc_addr="($PCI_BASE_ADDR + $offset + 0x970)"
ADC=$(mem $(($PCI_BASE_ADDR + $offset + 0x970)))

rf_gain3_addr="($PCI_BASE_ADDR + $offset + 0x978)"
rf_gain3=$(mem $(($PCI_BASE_ADDR + $offset + 0x978))) 

rf_gain_addr="($PCI_BASE_ADDR + $offset + 0x96c)"
rf_gain=$(mem $(($PCI_BASE_ADDR + $offset + 0x96c))) 

echo "digital_gain	SS: $digital_gain"
echo "evm_val		: $evm_val"
echo "n_symbol		: $n_symbol"
echo "ADC		: $ADC"
echo "RF GAIN_ant3	: $rf_gain3"
echo "RF GAIN		: $rf_gain"
