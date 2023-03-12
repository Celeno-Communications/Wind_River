#!/bin/bash

source scripts/dbg/rfic_wifi_mode_transition_reg_dbg.sh
#source ./rfic_bt_mode_transition_reg_dbg.sh

usage()
{
	echo "-----------------------------------------------------"
	echo "#  Usage:"
	echo "#  ./rfic_mode_transition_reg_dbg <transition>"
	echo "#  transition  = rfic_transition in format \"x[w/b]->y[w/b]\""
	echo -e "#  example: ./rfic_mode_transition_reg_dbg \"3w->4w\""
    echo -e "#  defualt transition is 3w->8w"
	echo "-----------------------------------------------------"
	exit 1
}

#====================development tools======================================================
export dummy_mem=1
export verbose=0
export mem_size=682
#===========SYSTEM MODE==========================================================
export LB_WIFI_MODE="NOLB_WIFI" #options: "NOLB","LB12","LB13"..etc all wifi LB types are supported, can be left empty
export LB_BT_MODE="NOLB_BT"    #options: "NOLB","LB3","LB15".. etc all BT LB types are supported, can be left empty
export CALIB_MODE="NO_CALIB"   #options: "NO_CALIB", "CALIB_WIFI", "CALIB_BT", "SW_CONTROL_WIFI"
export SYSTEM_MODE="CH0"       #options: "WIFI2X2", "CH0", "CH1"
export BGR_MODE="BGR0_BGR1_EN" #options: "BGR0_BGR1_DIS", ",BGR0_EN", "BGR1_EN", "BGR0_BGR1_EN"
export BT_SYS_MODE="NO_CALIB_BT" #options: "NO_CALIB", "BT_CALIB","SW_CONTROL_BT".. can be left empty
export SX=0                    #options: 0, 1


#============WIFI INPUT PARAMS===================================================
export DAC_CLK_SEL=0x2     #options: 0x0,0x1,0x2,0x3
export CH0_BB_BW=0x1       #options: 0x0,0x1,0x2,0x3,0x4,0x5
export CH1_BB_BW=0x1       #options: 0x0,0x1,0x2,0x3,0x4,0x5
export CH0_ADC=0x2         #options: 0x0,0x1,0x2,0x3
export CH1_ADC=0x2         #options: 0x0,0x1,0x2,0x3
export SX0_DIV_INT=115     #options: 0-255, according to channel and PLL calc
export SX1_DIV_INT=115     #options: 0-255, according to channel and PLL calc
export SX0_DIV_FRAC=233017 #options: 0-2^21-1, according to channel and PLL calc
export SX1_DIV_FRAC=233017 #options: 0-2^21-1, according to channel and PLL calc
export SX0_MEAS_TGT=17267  #options: 0-2^18-1, according to channel and PLL calc
export SX1_MEAS_TGT=17267  #options: 0-2^18-1, according to channel and PLL calc
export CH0_RX_GAIN=1
export CH1_RX_GAIN=1
export CH0_TX_GAIN=1
export CH1_TX_GAIN=1

#=======BT input params===============================================================
export CH_OVR_VAL=1
export MOD_SEL_OVR_VAL=0
export FILTER_BW_OVR_VAL=1
export TX_POWER_OVR_VAL=0
export LNA_GAIN_OVR_VAL=0
export LPF1_GAIN_OVR_VAL=0
export LPF2_GAIN_OVR_VAL=0
#=====================================================================================
if [ $dummy_mem -eq 1 ];
then
    mem=()
    i=0
    while [ $i -lt $mem_size ];
    do
        mem+=(0)
        i=$((i+1))
    done
fi



function addr_to_mem_index() {
    addr=$1
    if [[ ${addr} -lt 0x604B4400 ]];
    then
        addr_delta=$((${addr}-0x604B4000))
        index=$(($addr_delta/0x4))
    else
        addr_delta=$((${addr}-0x604B4400))
        index=$((($addr_delta/0x4)+0xA1))
    fi
}

function mem_write() {
    addr=$1
    val=$2
    if [ $dummy_mem -eq 1 ];
    then
        addr_to_mem_index $addr
        mem[$index]=$val
    else
       [ iwcl wlan0_0 cecli reg -w.${addr}.${val} ]
    fi
}

function mem_read() {
    addr=$1
    if [ $dummy_mem -eq 1 ]; then
        addr_to_mem_index $addr
        mem_val=${mem[$index]}
    else
        mem_val=$([ iwcl wlan0_0 cecli reg -r.${addr} ])
    fi

}

function write_field() {
    addr=$1
    printf -v addr_hex '%x' $addr
    offset=$2
    mask=$3
    value=$4
    value_to_write=$(($value<<$offset))
    mem_read ${addr}
    mem_masked=$(($mem_val&$mask))
    updated_val=$(($mem_masked|$value_to_write))
    mem_write $addr $updated_val
    if [ $verbose -eq 1 ]; then
        printf 'addr=0x%x , mem_index=%d ,val_to_write=0x%x, val_in_mem_before=0x%x, val_after_write=0x%x\n' $addr $index $value $mem_val $val
    fi
}

if [ "$1" = "--help" ] || [ "$1" = "--h" ] || [ "$1" = "-h" ];
then
    usage
    exit
fi

transion=$1
case $transion in
    "3w->4w")
        wifibtoff2wifistandby
        echo "test 3->4"
    ;;

    "4w->5w")
        wifistandby2wf_idle
    ;;

    "5w->6w")
        wf_idle2wf_chainconfig $DAC_CLK_SEL $CH0_BB_BW $CH1_BB_BW $CH0_ADC $CH1_ADC
    ;;

    "6w->7w")
        wf_chainconfig2wf_sxon
    ;;

    "7w->8w")
        if [ "$SYSTEM_MODE" = "WIFI2X2" ]; then
            if [ $SX==0 ]; then
                wf_sxon2wf_sxlocked $SX0_DIV_INT $SX0_DIV_FRAC $SX0_MEAS_TGT $SX1_DIV_INT $SX1_DIV_FRAC $SX1_MEAS_TGT  1 0 1 0 1 1 0 0 0 1 0 1
            fi
            if [ $SX==1 ]; then
                wf_sxon2wf_sxlocked $SX0_DIV_INT $SX0_DIV_FRAC $SX0_MEAS_TGT $SX1_DIV_INT $SX1_DIV_FRAC $SX1_MEAS_TGT  0 1 0 1 0 0 1 1 1 0 1 0
            fi
        fi
        if [ "$SYSTEM_MODE" = "CH0" ]; then
            if [ $SX==0 ]; then
                wf_sxon2wf_sxlocked $SX0_DIV_INT $SX0_DIV_FRAC $SX0_MEAS_TGT $SX1_DIV_INT $SX1_DIV_FRAC $SX1_MEAS_TGT  1 0 1 0 1 0 0 1 0 0 0 1
            fi
            if [ $SX==1 ]; then
                wf_sxon2wf_sxlocked $SX0_DIV_INT $SX0_DIV_FRAC $SX0_MEAS_TGT $SX1_DIV_INT $SX1_DIV_FRAC $SX1_MEAS_TGT  0 1 0 1 0 0 0 1 0 0 1 0
            fi
        fi
        if [ "$SYSTEM_MODE" = "CH1" ]; then
            if [ $SX==0 ]; then
                wf_sxon2wf_sxlocked $SX0_DIV_INT $SX0_DIV_FRAC $SX0_MEAS_TGT $SX1_DIV_INT $SX1_DIV_FRAC $SX1_MEAS_TGT  0 0 1 0 0 1 0 1 0 1 1 0
            fi
            if [ $SX==1 ]; then
                wf_sxon2wf_sxlocked $SX0_DIV_INT $SX0_DIV_FRAC $SX0_MEAS_TGT $SX1_DIV_INT $SX1_DIV_FRAC $SX1_MEAS_TGT  0 0 1 0 0 0 1 1 1 0 0 1
            fi
        fi       
    ;;

    "8w->8w")
        wf_sxlocked2sxlocked $SX0_DIV_INT $SX0_DIV_FRAC $SX0_MEAS_TGT $CH0_BB_BW $CH1_BB_BW $CH0_ADC $CH1_ADC $DAC_CLK_SEL
    ;;

    "8w->9w")
        wf_sxlocked2rxon $CH0_RX_GAIN $CH1_RX_GAIN $CH0_RX_GAIN $CH1_RX_GAIN $CH0_RX_GAIN $CH1_RX_GAIN
    ;;

    "8w->10w")
        wf_sxlocked2txon $CH0_TX_GAIN $CH1_TX_GAIN $CH0_TX_GAIN $CH1_TX_GAIN $CH0_TX_GAIN $CH1_TX_GAIN
    ;;

    "9w->8w")
        wf_rxon2sxlocked
    ;;

    "10w->8w")
        wf_txon2sxlocked
    ;;

    "reset_wifi")
        wf_reset2wifioff
    ;;
    
    "3w->8w"|"")
        echo "3w->8w"
        wifibtoff2wifistandby
        wifistandby2wf_idle
        wf_idle2wf_chainconfig $DAC_CLK_SEL $CH0_BB_BW $CH1_BB_BW $CH0_ADC $CH1_ADC
        wf_chainconfig2wf_sxon
        if [ "$SYSTEM_MODE" = "WIFI2X2" ]; then
            if [ $SX -eq 0 ]; then
                wf_sxon2wf_sxlocked $SX0_DIV_INT $SX0_DIV_FRAC $SX0_MEAS_TGT $SX1_DIV_INT $SX1_DIV_FRAC $SX1_MEAS_TGT  1 0 1 0 1 1 0 0 0 1 0 1
            fi
            if [ $SX -eq 1 ]; then
                wf_sxon2wf_sxlocked $SX0_DIV_INT $SX0_DIV_FRAC $SX0_MEAS_TGT $SX1_DIV_INT $SX1_DIV_FRAC $SX1_MEAS_TGT  0 1 0 1 0 0 1 1 1 0 1 0
            fi
        fi
        if [ "$SYSTEM_MODE" = "CH0" ]; then
            if [ $SX -eq 0 ]; then
                wf_sxon2wf_sxlocked $SX0_DIV_INT $SX0_DIV_FRAC $SX0_MEAS_TGT $SX1_DIV_INT $SX1_DIV_FRAC $SX1_MEAS_TGT  1 0 1 0 1 0 0 1 0 0 0 1
            fi
            if [ $SX -eq 1 ]; then
                wf_sxon2wf_sxlocked $SX0_DIV_INT $SX0_DIV_FRAC $SX0_MEAS_TGT $SX1_DIV_INT $SX1_DIV_FRAC $SX1_MEAS_TGT  0 1 0 1 0 0 0 1 0 0 1 0
            fi
        fi
        if [ "$SYSTEM_MODE" = "CH1" ]; then
            echo "no"
            if [ $SX -eq 0 ]; then
                wf_sxon2wf_sxlocked $SX0_DIV_INT $SX0_DIV_FRAC $SX0_MEAS_TGT $SX1_DIV_INT $SX1_DIV_FRAC $SX1_MEAS_TGT  0 0 1 0 0 1 0 1 0 1 1 0
            fi
            if [ $SX -eq 1 ]; then
                wf_sxon2wf_sxlocked $SX0_DIV_INT $SX0_DIV_FRAC $SX0_MEAS_TGT $SX1_DIV_INT $SX1_DIV_FRAC $SX1_MEAS_TGT  0 0 1 0 0 0 1 1 1 0 0 1
            fi
        fi
    ;;

    "4b->5b")
        echo "4b->5b"
        bt_rxon2chainconfig
    ;;

    "5b->6b")
        echo "5b->6b"
        bt_idle2bt_chainconfig
    ;;

    "6b->8b")
        echo "6b->8b"
        bt_chaincgf2sx1locked $CH_OVR_VAL $MOD_SEL_OVR_VAL $FILTER_BW_OVR_VAL
    ;;

    "8b->10b")
        echo "8b->10b"
        bt_sx1locked2txon $TX_POWER_OVR_VAL $TX_POWER_OVR_VAL $TX_POWER_OVR_VAL $TX_POWER_OVR_VAL $TX_POWER_OVR_VAL
    ;;

    "10b->6b")
        echo "10b->6b"
        bt_txon2chainconfig
    ;;

    "8b->9b")
        echo "8b->9b"
        bt_sx1locked2rxon $LNA_GAIN_OVR_VAL $LPF1_GAIN_OVR_VAL $LPF2_GAIN_OVR_VAL  \
                          $LNA_GAIN_OVR_VAL $LPF1_GAIN_OVR_VAL $LPF2_GAIN_OVR_VAL  \
                          $LNA_GAIN_OVR_VAL $LPF1_GAIN_OVR_VAL $LPF2_GAIN_OVR_VAL  \
                          $LNA_GAIN_OVR_VAL $LPF1_GAIN_OVR_VAL $LPF2_GAIN_OVR_VAL  \
                          $LNA_GAIN_OVR_VAL $LPF1_GAIN_OVR_VAL $LPF2_GAIN_OVR_VAL  \
                          $LNA_GAIN_OVR_VAL $LPF1_GAIN_OVR_VAL $LPF2_GAIN_OVR_VAL
    ;;

    "9b->6b")
        echo "9b->6b"
        bt_rxon2chainconfig
    ;;

    "all->3b")
        echo ("all->3b")
        bt_reset2btoff
    ;;     
            
esac
