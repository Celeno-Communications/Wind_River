#!/bin/bash

set -e

VERBOSE=${VERBOSE=0}
OUTPUT="/dev/stdout"

# Path to host package
HP_DIR=$( dirname $( readlink -f $0 ))
# Path to output binaries
HP_OUT_DIR=$HP_DIR/build
# Path to Celeno driver
CL_DRV=$HP_DIR/src/kernel/bp/drivers/net/wireless/celeno/cl6k
# Path to NFS directory
NFS_DIR="$USER_NFS_DIR"
# IW include
IW_DIR=$HP_DIR/src/utils/iw
# LIBNL path
LIBNL_DIR=$HP_DIR/src/utils/libnl
# Runtime configuration file.
HP_CONFIG_FILE=$HP_OUT_DIR/scripts/hp.config

NTHREADS=$CONFIG_CELENO_NTHREADS

# openssl directory
if [ "$CONFIG_CELENO_PLATFORM" = "EDK32" ]; then
	export OPENSSL_DIR=openssl-1.0.2h
else
	export OPENSSL_DIR=openssl-1.1.1d
fi

if [ "$OPENSSL_DIR" = "openssl-1.1.1d" ]; then
	LIBCRYPTO=libcrypto.so.1.1
	LIBCRYPTO_SL=libcrypto.so
	LIBSSL=libssl.so.1.1
	LIBSSL_SL=libssl.so
else
	LIBCRYPTO=libcrypto.so.1.0.0
	LIBCRYPTO_SL=libcrypto.so.1
	LIBSSL=libssl.so.1.0.0
	LIBSSL_SL=libssl.so.1
fi

export KBUILD_EXTRA_SYMBOLS=

. $(dirname $0)/cl.config

# Cross-compilation
export CROSS_COMPILE=$USER_CONF_CROSS_COMPILE
export KERNELDIR=$USER_CONF_LINUX_SRC
export CFLAGS=$USER_CONF_CFLAGS
export LDFLAGS=$USER_CONF_LDFLAGS
export PKG_CONFIG_LIBDIR=$USER_PKG_CONFIG_LIBDIR
export PKG_CONFIG_PATH=$LIBNL_DIR:$USER_PKG_CONFIG_PATH
export PKG_CONFIG_SYSROOT_DIR=$USER_CONF_SYSROOT_PATH

# This function stores configuration variables from celeno.mk into a hp.config to be used
# by host package scripts at runtime.
write_config()
{
	echo "# Configuration file to use at runtime (generated automatically)" > "$HP_CONFIG_FILE"
}

usage()
{
	echo ""
	echo "Usage:"
	echo " `basename $0` [-v] [command]"
	echo " `basename $0` [-v] [package] [package_command]"
	echo " -h - print this menu"
	echo " -v - verbose print level (optional)"
	echo " [command] - info,extraclean,init,build,clean,all"
	echo " [package] - bp,hostapd,wpa_supplicant,iw,iwcl,cl_netlink,iperf,lcu_driver,cl_spi,e2p (optional)"
	echo " [package_command] - config,build,install,clean (optional)"
	echo "Examples:"
	echo " `basename $0` info - print host package information."
	echo " `basename $0` extraeclean - remove & deploy all packages from svn or archives."
	echo " `basename $0` init - deploy & patch all packages patches & supplements."
	echo " `basename $0` build - clean, rebuild & install all packages."
	echo " `basename $0` clean - clean all packages."
	echo " `basename $0` all - init if needed & build all packages"
	echo " `basename $0` hostapd build - build specific package"
	echo " `basename $0` genutil genvcd build - build specific gen utility"
	echo ""
	exit 1
}

print_params()
{
	# print configuration parameters
	echo "" >$OUTPUT
	echo "Configuration Parameters: " >$OUTPUT
	echo "=================================" >$OUTPUT
	echo "Platform=${PLATFORM?}"  >$OUTPUT
	echo "HP_DIR=$HP_DIR" >$OUTPUT
	echo "CL_DRV=$CL_DRV" >$OUTPUT
	echo "HP_OUT_DIR=$HP_OUT_DIR" >$OUTPUT
	echo "NFS_DIR=$NFS_DIR" >$OUTPUT
	echo "CROSS_COMPILE=$CROSS_COMPILE" >$OUTPUT
	echo "KERNELDIR=$KERNELDIR" >$OUTPUT
	echo "CFLAGS=$CFLAGS" >$OUTPUT
	echo "LDFLAGS=$LDFLAGS" >$OUTPUT
	echo "" >$OUTPUT
}

function init_hp_build_fs()
{
	cd $HP_DIR

	for dir in $CL_HP_FS
	do {
		# remove directory - if exist
		rm -rf $dir
		# create HP file system directories
		mkdir -p $dir
		echo ">>> download $dir from svn"
		svn co $USER_SVN_BRANCH/$dir
	}
	done

	# remove output directory - if exist
	rm -rf $HP_OUT_DIR
	# create HP output directory
	mkdir -p $HP_OUT_DIR
}

function build_cl_reg()
{
	case "$1" in
		'build')
			make -j $NTHREADS -C $HP_DIR/src/utils/cl_reg CC=${CROSS_COMPILE}gcc || exit
			;;
		'clean')
			make -C $HP_DIR/src/utils/cl_reg clean || exit
			;;
		*)
			build_cl_reg clean
			build_cl_reg build
			;;
	esac
}

function build_cl_usb_test_app()
{
	case "$1" in
		'build')
			make -C $HP_DIR/src/utils/cl6000_test_app \
			CC="${CROSS_COMPILE}gcc" CXX="${CROSS_COMPILE}g++" || exit
			;;
		'install')
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/cl6000_test_app/cl6000_boot
			;;
		'clean')
			make -C $HP_DIR/src/utils/cl6000_test_app clean || exit
			;;
		*)
			build_cl_usb_test_app clean
			build_cl_usb_test_app build
			;;
	esac
}

function build_cl_spi()
{
	case "$1" in
		'build')
			if [ "$CONFIG_CELENO_PLATFORM" = "RTL9607DA" ]; then
				make -j $NTHREADS -C $HP_DIR/src/utils/cl_spi CC=${CROSS_COMPILE}gcc LD=${CROSS_COMPILE}ld LDFLAGS+=$USER_CONF_ELF_I386 || exit
			else
				make -j $NTHREADS -C $HP_DIR/src/utils/cl_spi CC=${CROSS_COMPILE}gcc LD=${CROSS_COMPILE}ld LDFLAGS=$USER_CONF_ELF_I386 || exit
			fi
			;;
		'install')
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin ${HP_DIR}/src/utils/cl_spi/cl_spi
			install -d $HP_OUT_DIR/lib
			install -t $HP_OUT_DIR/lib $HP_DIR/src/utils/cl_spi/libspi.so
			;;
		'clean')
			make -C $HP_DIR/src/utils/cl_spi clean || exit
			;;
		*)
			build_cl_spi clean
			build_cl_spi build
			build_cl_spi install
			;;
	esac
}

function build_e2p()
{
	case "$1" in
		'build')
			make -j $NTHREADS -C $HP_DIR/src/utils/e2p CC=${CROSS_COMPILE}gcc || exit
			;;
		'install')
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin ${HP_DIR}/src/utils/e2p/e2p
			;;
		'clean')
			make -C $HP_DIR/src/utils/e2p clean || exit
			;;
		*)
			build_e2p clean
			build_e2p build
			build_e2p install
			;;
	esac
}

function build_otp()
{
        case "$1" in
                'build')
                        make -j $NTHREADS -C $HP_DIR/src/utils/otp CC=${CROSS_COMPILE}gcc || exit
                        ;;
                'install')
                        install -d $HP_OUT_DIR/bin
                        install -t $HP_OUT_DIR/bin ${HP_DIR}/src/utils/otp/otp
                        ;;
                'clean')
                        make -C $HP_DIR/src/utils/otp clean || exit
                        ;;
                *)
                        build_otp clean
                        build_otp build
                        build_otp install
                        ;;
        esac
}

function build_wpa_supplicant()
{
	if [ ! -d $HP_DIR/src/utils/wpa_supplicant ] ; then echo "missing $HP_DIR/src/utils/wpa_supplicant dir, aborting."; exit 1; fi
	if [ ! -e $HP_DIR/src/utils/wpa_supplicant/wpa_supplicant/defconfig ] ; then echo "missing $HP_DIR/src/utils/wpa_supplicant/wpa_supplicant/defconfig file, aborting." exit 1 ; fi

	case "$1" in
		'config')
			local conf=$HP_DIR/src/utils/wpa_supplicant/wpa_supplicant/.config
			local defaultconf=$HP_DIR/src/utils/wpa_supplicant/wpa_supplicant/defconfig

			if [ ! -f "$conf" ]; then
				cp -f "$defaultconf" "$conf"
			fi

			;;
		'build')
			if [ -z ${LIBS_FS_WPASUPP+x} ]; then LIBS_FS_WPASUPP=""; fi
			V="$VERBOSE" LIBS+=$LIBS_FS_WPASUPP \
				make -j $NTHREADS -C $HP_DIR/src/utils/wpa_supplicant/wpa_supplicant CC=${CROSS_COMPILE}gcc || exit
			;;
		'install')
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/wpa_supplicant/wpa_supplicant/wpa_cli \
				$HP_DIR/src/utils/wpa_supplicant/wpa_supplicant/wpa_passphrase \
				$HP_DIR/src/utils/wpa_supplicant/wpa_supplicant/wpa_supplicant
			;;
		'clean')
			make -C $HP_DIR/src/utils/wpa_supplicant/wpa_supplicant clean || exit
			;;
		*)
			build_wpa_supplicant config
			build_wpa_supplicant clean
			build_wpa_supplicant build
			build_wpa_supplicant install
			;;
	esac
}

function build_bluez()
{
	if [ ! -d $HP_DIR/src/utils/bluez-5.62 ] ; then echo "missing $HP_DIR/src/utils/bluez-5.62 dir, aborting."; exit 1; fi

	case "$1" in
		'config')
			cd $HP_DIR/src/utils/bluez-5.62
			[ ! -e config.status ] && ./configure \
				--prefix=$HP_OUT_DIR \
				--host=$( ${CROSS_COMPILE}gcc -dumpmachine ) \
				--enable-testing \
				--disable-udev \
				--enable-deprecated \
				--enable-client \
				--disable-manpages \
				--disable-systemd \
				--with-udevdir=$HP_OUT_DIR/etc \
				--with-dbusconfdir=$HP_OUT_DIR/etc \
				--with-dbussystembusdir=$HP_OUT_DIR/usr/share/dbus-1/system-services \
				CC="${CROSS_COMPILE}gcc" \
				CXX="${CROSS_COMPILE}g++"
			cd -
			;;
		'build')
			V="$VERBOSE" \
				make -C $HP_DIR/src/utils/bluez-5.62 || exit
			;;
		'install')
				make -C $HP_DIR/src/utils/bluez-5.62 install|| exit
			;;
		'clean')
			make -C $HP_DIR/src/utils/bluez-5.62 clean || exit
			;;
		*)
			build_bluez clean
			build_bluez config
			build_bluez build
			build_bluez install
			;;
	esac
}

function build_bt_config()
{
	if [ ! -d $HP_DIR/src/utils/bt_config ] ; then echo "missing $HP_DIR/src/utils/bt_config dir, aborting."; exit 1; fi

	case "$1" in
		'build')
			V="$VERBOSE" \
				CC=${CROSS_COMPILE}gcc make -C $HP_DIR/src/utils/bt_config || exit
			;;
		'install')
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/bt_config/cl_bt_config
			;;
		'clean')
			make -C $HP_DIR/src/utils/bt_config clean || exit
			;;
		*)
			build_bt_config clean
			build_bt_config build
			build_bt_config install
			;;
	esac
}

function build_hci_nc()
{
	if [ ! -d $HP_DIR/src/utils/hci_nc ] ; then echo "missing $HP_DIR/src/utils/hci_nc dir, aborting."; exit 1; fi

	case "$1" in
		'build')
			V="$VERBOSE" \
				CC=${CROSS_COMPILE}gcc make -C $HP_DIR/src/utils/hci_nc || exit
			;;
		'install')
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/hci_nc/hci_nc
			;;
		'clean')
			make -C $HP_DIR/src/utils/hci_nc clean || exit
			;;
		*)
			build_hci_nc clean
			build_hci_nc build
			build_hci_nc install
			;;
	esac
}

function build_hostapd()
{
	if [ ! -d $HP_DIR/src/utils/hostap ] ; then echo "missing $HP_DIR/src/utils/hostap dir, aborting."; exit 1; fi
	if [ ! -e $HP_DIR/src/utils/hostap/hostapd/defconfig ] ; then echo "missing $HP_DIR/src/utils/hostap/hostapd/defconfig file, aborting." exit 1 ; fi

	case "$1" in
		'config')
			local conf=$HP_DIR/src/utils/hostap/hostapd/.config
			local defaultconf=$HP_DIR/src/utils/hostap/hostapd/defconfig

			if [ ! -f "$conf" ]; then
				cp -f "$defaultconf" "$conf"
			fi

			;;
		'build')
			if [ -z ${LIBS_FS_HOSTAPD+x} ]; then LIBS_FS_HOSTAPD=""; fi
			V="$VERBOSE" LIBS+=$LIBS_FS_HOSTAPD CC=${CROSS_COMPILE}gcc \
				make -j $NTHREADS -C $HP_DIR/src/utils/hostap/hostapd || exit
			;;
		'install')
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/hostap/hostapd/hostapd \
				$HP_DIR/src/utils/hostap/hostapd/hostapd_cli
			if [ -f $HP_DIR/filesystem/cl8000/lib/libsqlite3.so.0 ]; then
				install -d $HP_OUT_DIR/lib
				install -t $HP_OUT_DIR/lib $HP_DIR/filesystem/cl8000/lib/libsqlite3.so.0
			fi
			;;
		'clean')
			make -C $HP_DIR/src/utils/hostap/hostapd clean || exit
			;;
		*)
			build_hostapd config
			build_hostapd clean
			build_hostapd build
			build_hostapd install
			;;
	esac
}

function build_iw()
{
	if [ ! -d ${IW_DIR-iw_directory} ] ; then echo "missing ${IW_DIR} dir, aborting."; exit 1; fi

	case "$1" in
		'config')
			;;
		'build')
			if [ -z ${LIBS_FS_IW+x} ]; then LIBS_FS_IW=""; fi
			V="$VERBOSE" LIBS+=$LIBS_FS_IW \
				make -j $NTHREADS -C ${IW_DIR} CC=${CROSS_COMPILE}gcc || exit
			;;
		'install')
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin ${IW_DIR}/iw
			;;
		'clean')
			make -C ${IW_DIR} clean || exit
			;;
		*)
			make -C ${IW_DIR} clean || exit
			if [ -z ${LIBS_FS_IW+x} ]; then LIBS_FS_IW=""; fi
			V="$VERBOSE" LIBS+=$LIBS_FS_IW \
				make -C ${IW_DIR} CC=${CROSS_COMPILE}gcc || exit
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin ${IW_DIR}/iw
			;;
	esac
}

function build_iwcl()
{
	if [ ! -d $HP_DIR/src/utils/iwcl ] ; then echo "missing $HP_DIR/src/utils/iwcl dir, aborting."; exit 1; fi

	case "$1" in
		'config')
			;;
		'build')
			V="$VERBOSE" \
			make -j $NTHREADS -C $HP_DIR/src/utils/iwcl CC=${CROSS_COMPILE}gcc || exit
			;;
		'install')
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/iwcl/iwcl
			;;
		'clean')
			make -C $HP_DIR/src/utils/iwcl clean || exit
			;;
		*)
			make -C $HP_DIR/src/utils/iwcl clean || exit
			V="$VERBOSE" \
			make -C $HP_DIR/src/utils/iwcl CC=${CROSS_COMPILE}gcc || exit
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/iwcl/iwcl
			;;
	esac
}

function build_cl_netlink()
{
	if [ ! -d $HP_DIR/src/utils/cl_netlink ] ; then echo "missing $HP_DIR/src/utils/cl_netlink dir, aborting."; exit 1; fi

	case "$1" in
		'config')
			;;
		'build')
			V="$VERBOSE" \
			make -j $NTHREADS -C $HP_DIR/src/utils/cl_netlink CC=${CROSS_COMPILE}gcc || exit
			;;
		'install')
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/cl_netlink/cl_netlink
			;;
		'clean')
			make -C $HP_DIR/src/utils/cl_netlink clean || exit
			;;
		*)
			make -C $HP_DIR/src/utils/cl_netlink clean || exit
			V="$VERBOSE" \
			make -j $NTHREADS -C $HP_DIR/src/utils/cl_netlink CC=${CROSS_COMPILE}gcc || exit
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/cl_netlink/cl_netlink
			;;
	esac
}

function build_iperf()
{
	if [ ! -d $HP_DIR/src/utils/iperf ]; then return; fi

	case "$1" in
		'config')
			cd $HP_DIR/src/utils/iperf
			[ ! -e config.status ] && ./configure \
				--host=$( ${CROSS_COMPILE}gcc -dumpmachine ) \
				CC="${CROSS_COMPILE}gcc $USER_CONF_M32" \
				CXX="${CROSS_COMPILE}g++ $USER_CONF_M32" \
				ac_cv_func_malloc_0_nonnull=yes
			cd -
			;;
		'build')
			V="$VERBOSE" \
				make -j $NTHREADS -C $HP_DIR/src/utils/iperf || exit
			;;
		'install')
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/iperf/src/iperf
			;;
		'clean')
			make -C $HP_DIR/src/utils/iperf clean || exit
			;;
		*)
			cd $HP_DIR/src/utils/iperf
			[ ! -e config.status ] && ./configure \
				--host=$( ${CROSS_COMPILE}gcc -dumpmachine ) \
				CC="${CROSS_COMPILE}gcc $USER_CONF_M32" \
				CXX="${CROSS_COMPILE}g++ $USER_CONF_M32" \
				ac_cv_func_malloc_0_nonnull=yes
			cd -
			make -C $HP_DIR/src/utils/iperf clean || exit
			V="$VERBOSE" \
				make -j $NTHREADS -C $HP_DIR/src/utils/iperf || exit
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/iperf/src/iperf
			;;
	esac
}

function build_libnl()
{
	if [ ! -d $HP_DIR/src/utils/libnl ] ; then echo "missing $HP_DIR/src/utils/libnl dir, aborting."; exit 1; fi
	case "$1" in
		'config')
			cd $HP_DIR/src/utils/libnl
			[ ! -e config.status ] && ./configure \
				--host=$( ${CROSS_COMPILE}gcc -dumpmachine ) \
				CC="${CROSS_COMPILE}gcc $USER_CONF_M32" \
				ac_cv_func_malloc_0_nonnull=yes
			cd -
			;;
		'build')
			make -j $NTHREADS -C $HP_DIR/src/utils/libnl || exit
			;;
		'install')
			install -d $HP_OUT_DIR/lib
			install -t $HP_OUT_DIR/lib $HP_DIR/src/utils/libnl/lib/.libs/libnl-3.so.200
			ln -s libnl-3.so.200 $HP_OUT_DIR/lib/libnl-3.so.1
			install -t $HP_OUT_DIR/lib $HP_DIR/src/utils/libnl/lib/.libs/libnl-genl-3.so.200
			ln -s libnl-genl-3.so.200 $HP_OUT_DIR/lib/libnl-genl-3.so.1
			;;
		'clean')
			make -C $HP_DIR/src/utils/libnl clean || exit
			;;
		*)
			build_libnl config
			build_libnl clean
			build_libnl build
			build_libnl install
			;;
	esac
}

function build_libssl()
{
	if [ ! -d "$HP_DIR/src/utils/$OPENSSL_DIR" ] ; then echo "missing $HP_DIR/src/utils/$OPENSSL_DIR dir, aborting."; exit 1; fi

	if ${CROSS_COMPILE}gcc -dumpmachine | grep -q "x86_64"; then
		openssl_target=linux-x86_64
	else
		openssl_target=linux-generic32
	fi

	if [ "$CONFIG_CELENO_PLATFORM" = "EDK32" ]; then
		openssl_target=linux-generic32
	fi

	case "$1" in
		'config')
			cd $HP_DIR/src/utils/$OPENSSL_DIR
			[ ! -e "$LIBSSL" ] && ./Configure $openssl_target $USER_CONF_M32 shared --prefix=$HP_OUT_DIR/lib --sysroot=$SYSROOT_PATH
			cd -
			;;
		'build')
			make -j $NTHREADS CC=${CROSS_COMPILE}gcc RANLIB=${CROSS_COMPILE}ranlib LD=${CROSS_COMPILE}ld MAKEDEPPROG=${CROSS_COMPILE}gcc -C $HP_DIR/src/utils/$OPENSSL_DIR || exit
			;;
		'install')
			install -d $HP_OUT_DIR/lib
			install -t $HP_OUT_DIR/lib $HP_DIR/src/utils/$OPENSSL_DIR/$LIBCRYPTO
			install -t $HP_OUT_DIR/lib $HP_DIR/src/utils/$OPENSSL_DIR/$LIBSSL
			ln -s $LIBCRYPTO $HP_OUT_DIR/lib/$LIBCRYPTO_SL
			ln -s $LIBSSL $HP_OUT_DIR/lib/$LIBSSL_SL
			;;
		'clean')
			make -j $NTHREADS -C $HP_DIR/src/utils/$OPENSSL_DIR clean || exit
			;;
		*)
			build_libssl config
			build_libssl clean
			build_libssl build
			build_libssl install
			;;
	esac
}


function build_sysstat()
{
	local SYSSTAT_DIR=$HP_DIR/src/utils/sysstat

	if [ ! -d $SYSSTAT_DIR ]; then return; fi

	case "$1" in
		'config')
			cd $SYSSTAT_DIR
			./configure --disable-documentation \
				--disable-nls \
				--disable-sensors \
				--disable-sa \
				--prefix=$HP_OUT_DIR/bin
			cd -
			;;
		'build')
			make -j $NTHREADS CC=${CROSS_COMPILE}gcc -C $SYSSTAT_DIR || exit
			;;
		'install')
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $SYSSTAT_DIR/mpstat
			;;
		'clean')
			make  -C $SYSSTAT_DIR clean || exit
			;;
		*)
			build_sysstat config
			build_sysstat clean
			build_sysstat build
			build_sysstat install
			;;
	esac
}

function build_lcu_driver()
{
	if [ ! -d $HP_DIR/src/utils/lcu_driver ] ; then return; fi

	case "$1" in
		'config')
			;;
		'build')
			V="$VERBOSE" \
				make -j $NTHREADS -C $HP_DIR/src/utils/lcu_driver CC=${CROSS_COMPILE}gcc || exit
			;;
		'install')
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/lcu_driver/lcu_driver
			;;
		'clean')
			make -C $HP_DIR/src/utils/lcu_driver clean || exit
			;;
		*)
			make -C $HP_DIR/src/utils/lcu_driver clean || exit
			V="$VERBOSE" \
				make -j $NTHREADS -C $HP_DIR/src/utils/lcu_driver CC=${CROSS_COMPILE}gcc
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/lcu_driver/lcu_driver
			;;
	esac
}

function build_lcu_mem()
{
	if [ ! -d $HP_DIR/src/utils/lcu_mem ] ; then return; fi

	case "$1" in
		'config')
			;;
		'build')
			V="$VERBOSE" \
				make -j $NTHREADS -C $HP_DIR/src/utils/lcu_mem CC=${CROSS_COMPILE}gcc || exit
			;;
		'install')
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/lcu_mem/lcu_mem
			;;
		'clean')
			make -C $HP_DIR/src/utils/lcu_mem clean || exit
			;;
		*)
			make -C $HP_DIR/src/utils/lcu_mem clean || exit
			V="$VERBOSE" \
				make -j $NTHREADS -C $HP_DIR/src/utils/lcu_mem CC=${CROSS_COMPILE}gcc
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/lcu_mem/lcu_mem
			;;
		esac
}

function build_extra()
{
	if [ ! -d $HP_DIR/extra ] ; then echo "missing $HP_DIR/extra dir, skipping."; return ; fi

	case "$1" in
		config)
			;;
		build| install| clean|*)
			for d in $HP_DIR/extra/*
			do
				V="$VERBOSE" \
					make -j $NTHREADS -C $d $1 CC=${CROSS_COMPILE}gcc DESTDIR=$HP_OUT_DIR || exit
			done
			;;
	esac
}

function build_boot_driver()
{
	if [ ! -d $HP_DIR/src/utils/boot_driver ] ; then return; fi

	case "$1" in
		'config')
			;;
		'build')
			V="$VERBOSE" \
			CL_DRV="$CL_DRV" \
			make -j $NTHREADS -C $HP_DIR/src/utils/boot_driver CC=${CROSS_COMPILE}gcc || exit
			;;
		'install')
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/boot_driver/cl6000_boot
			;;
		'clean')
			make -C $HP_DIR/src/utils/boot_driver clean || exit
			;;
		*)
			V="$VERBOSE" \
			CL_DRV="$CL_DRV" \
			make -j $NTHREADS -C $HP_DIR/src/utils/boot_driver CC=${CROSS_COMPILE}gcc || exit
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/boot_driver/cl6000_boot
			;;
	esac
}

function build_mac_hw_driver()
{
	if [ ! -d $HP_DIR/src/utils/mac_hw_driver ] ; then return; fi

	case "$1" in
		'config')
			;;
		'build')
			V="$VERBOSE" \
				make -j $NTHREADS -C $HP_DIR/src/utils/mac_hw_driver CC=${CROSS_COMPILE}gcc || exit
			;;
		'install')
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/mac_hw_driver/mac_hw_driver
			;;
		'clean')
			make -C $HP_DIR/src/utils/mac_hw_driver clean || exit
			;;
		*)
			make -C $HP_DIR/src/utils/mac_hw_driver clean || exit
			V="$VERBOSE" \
				make -j $NTHREADS -C $HP_DIR/src/utils/mac_hw_driver CC=${CROSS_COMPILE}gcc || exit
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/mac_hw_driver/mac_hw_driver
			;;
	esac
}

function build_devmem()
{
	if [ ! -d $HP_DIR/src/utils/devmem ] ; then echo "missing $HP_DIR/src/utils/devmem dir, aborting."; exit 1; fi

	case "$1" in
		'config')
			;;
		'build')
			V="$VERBOSE" \
				make -j $NTHREADS -C $HP_DIR/src/utils/devmem CC=${CROSS_COMPILE}gcc || exit
			;;
		'install')
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/devmem/mem
			;;
		'clean')
			make -C $HP_DIR/src/utils/devmem clean || exit
			;;
		*)
			make -C $HP_DIR/src/utils/devmem clean || exit
			V="$VERBOSE" \
				make -j $NTHREADS -C $HP_DIR/src/utils/devmem CC=${CROSS_COMPILE}gcc || exit
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/devmem/mem
			;;
	esac
}

function build_gen_util()
{
	local utilname="$1"

	if [ "$utilname" == "" ] ; then echo "missing utility name, aborting."; exit 1; fi
	if [ ! -d $HP_DIR/src/utils/$utilname ] ; then echo "missing $HP_DIR/src/utils/$utilname dir, aborting."; exit 1; fi

	case "$2" in
		'config')
			;;
		'build')
			V="$VERBOSE" \
				make -j $NTHREADS -C $HP_DIR/src/utils/$utilname CC=${CROSS_COMPILE}gcc || exit
			;;
		'install')
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/$utilname/$utilname
			;;
		'clean')
			make -C $HP_DIR/src/utils/$utilname clean || exit
			;;
		*)
			make -C $HP_DIR/src/utils/$utilname clean || exit
			V="$VERBOSE" \
				make -j $NTHREADS -C $HP_DIR/src/utils/$utilname CC=${CROSS_COMPILE}gcc
			install -d $HP_OUT_DIR/bin
			install -t $HP_OUT_DIR/bin $HP_DIR/src/utils/$utilname/$utilname
			;;
	esac
}

function build_bp()
{
	if [ ! -d $HP_DIR/src/kernel/bp ] ; then echo "missing $HP_DIR/src/kernel/bp dir, aborting."; exit 1; fi

	case "$1" in
		'config')
			if [ ! -f $HP_DIR/src/kernel/bp/.config ]; then
				unset CFLAGS LDFLAGS && make KLIB=$KERNELDIR KLIB_BUILD=$KERNELDIR -C $HP_DIR/src/kernel/bp defconfig-cl6k
			fi
			;;
		'build')
			unset CFLAGS LDFLAGS && make \
			KLIB=$KERNELDIR \
			KLIB_BUILD=$KERNELDIR \
			DRV_VERSION=${CONFIG_HOST_CL_VER} \
			-C $HP_DIR/src/kernel/bp \
			-j $NTHREADS || exit
			;;
		'install')
			mkdir -p $HP_OUT_DIR/modules
			find -L $HP_DIR/src/kernel/bp -name *.ko -exec cp -vf '{}' $HP_OUT_DIR/modules/ ';'
			modules_list=`find -L  $HP_OUT_DIR/modules -name *.ko`

			for mod_name in $modules_list; do
				${CROSS_COMPILE}strip -g ${mod_name}
			done

			${CROSS_COMPILE}strip -g $HP_OUT_DIR/bin/*
			;;
		'clean')

			# Yes, this is extremely ugly and inefficient, but it's temporary. :)
			find -L $HP_DIR/src/kernel/bp -name '*.ko'           -exec rm -rvf {} +
			find -L $HP_DIR/src/kernel/bp -name '*.o'            -exec rm -rvf {} +
			find -L $HP_DIR/src/kernel/bp -name '*.cmd'          -exec rm -rvf {} +	
			find -L $HP_DIR/src/kernel/bp -name '.tmp_versions'  -exec rm -rvf {} +
			find -L $HP_DIR/src/kernel/bp -name 'modules.order'  -exec rm -rvf {} +
			find -L $HP_DIR/src/kernel/bp -name 'Module.symvers' -exec rm -rvf {} +
			find -L $HP_DIR/src/kernel/bp -name 'top_version'    -exec rm -rvf {} +
			find -L $HP_DIR/src/kernel/bp -name '*.mod.c'        -exec rm -rvf {} +
			;;
		*)
			build_bp config
			build_bp clean
			build_bp build
			build_bp install
			;;
	esac
}

function install_scripts()
{
	if [ ! -d $HP_DIR/scripts ] ; then echo "missing $HP_DIR/scripts dir, aborting."; exit 1; fi
	rsync -aCq $HP_DIR/scripts $HP_OUT_DIR

	sed "s/__VERSION__/$CONFIG_HOST_CL_VER/" -i $HP_OUT_DIR/scripts/env.sh
	echo "TARGET_PLATFORM=$CONFIG_CELENO_PLATFORM" >> ${HP_OUT_DIR}/scripts/env.sh
	echo "ce_vendor_id_usb=33de" >> ${HP_OUT_DIR}/scripts/env.sh
	echo "ce_vendor_id_pci=1d69" >> ${HP_OUT_DIR}/scripts/env.sh

	write_config
}

function install_configs()
{
	if [ ! -d $HP_DIR/config ] ; then echo "missing $HP_DIR/config dir, aborting."; exit 1; fi
	rsync -aCq $HP_DIR/config $HP_OUT_DIR
}

function install_otp()
{
	if [ ! -d $HP_DIR/otp ] ; then echo "missing $HP_DIR/otp dir, aborting."; exit 1; fi
	rsync -aCq $HP_DIR/otp $HP_OUT_DIR
}

function install_firmware()
{
	if [ ! -d $HP_DIR/firmware ] ; then echo "missing $HP_DIR/firmware dir, aborting."; exit 1; fi
	rsync -aCq $HP_DIR/firmware $HP_OUT_DIR
}

function install_bin()
{
	if [ ! -d $HP_DIR/bin ] ; then echo "missing $HP_DIR/bin dir, skipping."; return ; fi
	rsync -aCq $HP_DIR/bin $HP_OUT_DIR
}

function init_all()
{
	if [ -z "$PLATFORM" ]; then
		echo 'ERROR! important config parameters missing! Run this from the makefile.' 
		exit 1
	fi

	print_params
}

function build_all()
{
	build_cl_usb_test_app build
	build_cl_reg build
	build_boot_driver build
	build_e2p build
	build_otp build

	if [ "$CECFG_LIBNL_ENABLE" = y ]; then
		build_libnl config
		build_libnl build
	fi

	if [ "$CECFG_LIBSSL_ENABLE" = y ]; then
		build_libssl config
		build_libssl build
	fi

	if [ "$CECFG_WPASUPP_ENABLE" = y ]; then
		build_wpa_supplicant config
		build_wpa_supplicant build
	fi

	if [ "$CECFG_BLUEZ_ENABLE" = y ]; then
		build_bluez config
		build_bluez build
	fi

	build_hostapd config
	build_hostapd build
	build_iw build
	build_iwcl build
	build_cl_netlink build

	if [ "$CECFG_IPERF_ENABLE" = y ]; then
		build_iperf config
		build_iperf build
	fi

	if [ "$CECFG_SYSSTAT_SUPPORT" = y ]; then
		build_sysstat config
		build_sysstat build
	fi
	build_lcu_driver build
	if [ "$CECFG_MAC_HW_DRV_SUPPORT" = y ]; then
		build_mac_hw_driver build
	fi
	build_devmem build
	build_lcu_mem build

	# build all gen utils
	for name in `find $HP_DIR/src/utils -maxdepth 1 -type d | sed 's|'$HP_DIR'/src/utils/\?||g' | grep -e gen -e mem_init`
	do
		build_gen_util $name build
	done

	if [ "$CECFG_CL_BT" = y ]; then
		build_bt_config config
		build_bt_config build
		build_hci_nc config
		build_hci_nc build
	fi

	build_bp config
	build_bp build
	build_extra build

	install_scripts
	install_configs
	install_otp
	install_firmware
	install_bin

	install -d $HP_OUT_DIR/bin
	cd $HP_OUT_DIR/bin

	for i in elmaRead elmaWrite elmaRMWrite riuRead riuWrite gcuWrite gcuRead mdmRead mdmWrite riuPoll riuRMWrite rcRead rcWrite ; do ln -nsf ../scripts/rf_scripts/csvParser.sh $i; done
	cd -
}

function install_all()
{
	build_boot_driver install
	build_e2p install
	build_otp install

	if [ "$CECFG_LIBNL_ENABLE" = y ]; then
		build_libnl install
	fi

	if [ "$CECFG_LIBSSL_ENABLE" = y ]; then
		build_libssl install
	fi

	if [ "$CECFG_WPASUPP_ENABLE" = y ]; then
		build_wpa_supplicant install
	fi

	if [ "$CECFG_BLUEZ_ENABLE" = y ]; then
		build_bluez install
	fi

	build_hostapd install
	build_iw install
	build_iwcl install
	build_cl_netlink install
	if [ "$CECFG_IPERF_ENABLE" = y ]; then
		build_iperf install
	fi

	if [ "$CECFG_SYSSTAT_SUPPORT" = y ]; then
		build_sysstat install
	fi

	build_lcu_driver install
	if [ "$CECFG_MAC_HW_DRV_SUPPORT" = y ]; then
		build_mac_hw_driver install
	fi
	build_devmem install
	build_lcu_mem install

	# build all gen utils
	for name in `find $HP_DIR/src/utils -maxdepth 1 -type d | sed 's|'$HP_DIR'/src/utils/\?||g' | grep -e gen -e mem_init`
	do
		build_gen_util $name install
	done

	if [ "$CECFG_CL_BT" = y ]; then
		build_bt_config install
	fi
	build_bp install

	install_scripts
	install_configs
	install_otp
	install_firmware
	install_bin

	cd $HP_OUT_DIR/bin
	for i in elmaRead elmaWrite elmaRMWrite riuRead riuWrite gcuWrite gcuRead mdmRead mdmWrite riuPoll riuRMWrite rcRead rcWrite ; do ln -nsf ../scripts/rf_scripts/csvParser.sh $i; done
	ln -nsf ../scripts/rf_scripts/dc_formatted.sh dc_formatted

	cd -
	build_extra install
}

function clean_all()
{
	build_cl_usb_test_app clean
	build_cl_reg clean
	build_boot_driver clean
	build_e2p clean
	build_otp clean

	if [ "$CECFG_LIBNL_ENABLE" = y ]; then
		build_libnl clean
	fi

	if [ "$CECFG_LIBSSL_ENABLE" = y ]; then
		build_libssl clean
	fi
	if [ "$CECFG_WPASUPP_ENABLE" = y ]; then
		build_wpa_supplicant clean
	fi

	if [ "$CECFG_BLUEZ_ENABLE" = y ]; then
		build_bluez clean
	fi

	build_hostapd clean
	build_iw clean
	build_iwcl clean
	build_cl_netlink clean
	if [ "$CECFG_IPERF_ENABLE" = y ]; then
		build_iperf clean
	fi

	if [ "$CECFG_SYSSTAT_SUPPORT" = y ]; then
		build_sysstat clean
	fi
	build_lcu_driver clean
	if [ "$CECFG_MAC_HW_DRV_SUPPORT" = y ]; then
		build_mac_hw_driver clean
	fi
	build_devmem clean
	build_lcu_mem clean

	# build all gen utils
	for name in `find $HP_DIR/src/utils -maxdepth 1 -type d | sed 's|'$HP_DIR'/src/utils/\?||g' | grep -e gen -e mem_init`
	do
		build_gen_util $name clean
	done

	build_bp clean
	if [ "$CECFG_CL_BT" = y ]; then
		build_bt_config clean
		build_hci_nc clean
	fi
	build_extra clean

	rm -rvf $HP_DIR/build $HP_DIR/cl6000_host_pkg-*.tar.bz2
}

if [ "$1" == "-v" ] ; then VERBOSE=1; shift; fi

if [ $# -lt 1 ] || [ "$1" = "-h" ] || [ "$1" = "--help" ]; then usage ; fi

if [ "$VERBOSE" == 1 ]
then
	echo ""
	echo "$0 running ..."
	echo ""
fi

# create a link from NFS directory to HP output directory
if [ -d "$NFS_DIR" ] ; then ln -sfn $HP_OUT_DIR $NFS_DIR/cl8000 ; fi

case "$1" in
	'info')
		print_params
		;;
	'extraclean')
		echo ">>> hp: This will completely remove your hp packages and re-deploy them from SVN."
		read -r -p "Are you sure? [Y/n]" reply
		reply=${reply,,} # tolower
		if [[ $reply =~ ^(yes|y| ) ]]; then
			init_hp_build_fs
		fi
		;;
	'init')
		echo ">>> hp: preparing hp..."
		init_all
		;;
	'build')
		echo ">>> hp: build all ..."
		build_all
		;;
	'install')
		echo ">>> hp: install all ..."
		rm -rf $HP_OUT_DIR/*
		install_all
		;;
	'wpa_supplicant')
		echo ">>> hp: $@ ..."
		build_wpa_supplicant "$2"
		;;
	'hostapd')
		echo ">>> hp: $@ ..."
		build_hostapd "$2"
		;;
	'bluez')
		echo ">>> hp: $@ ..."
		build_bluez "$2"
		;;
	'iw')
		echo ">>> hp: $@ ..."
		build_iw "$2"
		;;
	'iwcl')
		echo ">>> hp: $@ ..."
		build_iwcl "$2"
		;;
	'cl_netlink')
		echo ">>> hp: $@ ..."
		build_cl_netlink "$2"
		;;
	'iperf')
		echo ">>> hp: $@ ..."
		build_iperf "$2"
		;;
	'lcu_driver')
		echo ">>> hp: $@ ..."
		build_lcu_driver "$2"
		;;
	'cl_spi')
		echo ">>> hp: $@ ..."
		build_cl_spi "$2"
		;;
	'e2p')
		echo ">>> hp: $@ ..."
		build_e2p "$2"
		;;
        'otp')
                echo ">>> hp: $@ ..."
                build_otp "$2"
                ;;
	'boot_driver')
		echo ">>> hp: $@ ..."
		build_boot_driver "$2"
		;;
	'mac_hw_driver')
		if [ "$CECFG_MAC_HW_DRV_SUPPORT" = y ]; then
			echo ">>> hp: $@ ..."
			build_mac_hw_driver "$2"
		fi
		;;
	'devmem')
		echo ">>> hp: $@ ..."
		build_devmem "$2"
		;;
	'lcu_mem')
		echo ">>> hp: $@ ..."
		build_lcu_mem "$2"
		;;
	'genutil')
		echo ">>> hp: $@ ..."
		if [ "$2" == "" ]
		then
			echo ""
			echo " optional gen utilities:"
			echo "-------------------------"
			for name in `find $HP_DIR/src/utils -maxdepth 1 -type d | sed 's|'$HP_DIR'/src/utils/\?||g' | grep -e gen -e mem_init`
			do
				echo "$name"
			done
			echo ""
			exit 1
		fi
		build_gen_util "$2" "$3"
		;;
	'bp')
		echo ">>> hp: $@ ..."
		build_bp "$2"
		if [ "$CECFG_CL_BT" = y ]; then
			build_bt_config "$2"
		fi
		;;
	'scripts')
		echo ">>> hp: $@ ..."
		install_scripts
		;;
	'configs')
		echo ">>> hp: $@ ..."
		install_configs
		;;
	'otp')
		echo ">>> hp: $@ ..."
		install_otp
		;;
	'firmware')
		echo ">>> hp: $@ ..."
		install_firmware
		;;
	'bin')
		echo ">>> hp: $@ ..."
		install_bin
		;;
	'clean')
		echo ">>> hp: clean all ..."
		clean_all
		;;
	'all')
		echo ">>> hp: init & build all from scratch ..."
		init_all
		build_all
		;;
	'extra')
		build_extra config
		build_extra build
		build_extra install
		;;
	*)
		echo ">>> hp: invalid option \"$@\", aborting ..."
		exit 1
		;;
esac
