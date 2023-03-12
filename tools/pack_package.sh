#!/bin/sh

USER_BIN_NAME=cl8000

# internal definitions
USER_HP_DIR=$( readlink -f "$(dirname $0)"/.. )
HP_OUT_DIR="$USER_HP_DIR"/build

TMP_DIR=$(mktemp -d)
PKG_DIR=$TMP_DIR/cl6k_host_pkg-$CONFIG_HOST_CL_VER-$PLATFORM

mkdir -p $PKG_DIR/$host_cfg_dir
mkdir -p $PKG_DIR/$host_install_dir
mkdir -p $PKG_DIR/var/run/

# Patch $HP_OUT_DIR with platform-specific files from platformdb
[ -d $USER_HP_DIR/filesystem/$host_install_dir ] && cp -av $USER_HP_DIR/filesystem/$host_install_dir/* $HP_OUT_DIR/

cp -a $HP_OUT_DIR/* $PKG_DIR/$host_install_dir

# Platform-specific files from platformdb may be outside of /$host_install_dir, hence this extra copying
[ -d $USER_HP_DIR/filesystem ] && cp -av $USER_HP_DIR/filesystem/* $PKG_DIR/

tar -cjf cl6k_host_pkg-$CONFIG_HOST_CL_VER-$PLATFORM.tar.bz2 -C $TMP_DIR cl6k_host_pkg-$CONFIG_HOST_CL_VER-$PLATFORM

rm -rf $TMP_DIR || true
