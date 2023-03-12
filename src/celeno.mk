##############################################################################
###                       Start global settings section                    ###
##############################################################################

# PLATFORMS:
# EDK32, RZG2M, RZG2L, HK6030, Cortina_venus, ubuntu64

export PLATFORM = HK6030
export CONFIG_HOST_CL_VER = 6.1.0.30

# Sanity checks
ifeq ($(PLATFORM),)
$(error PLATFORM not defined)
endif

# Default settings
DEF_CONF_SYSROOT_PATH=/
DEF_CONF_HOST_INSTALL_DIR = /cl6k
DEF_CONF_HOST_CFG_DIR = /nvram/cl6k
DEF_CONF_TRACE=n
DEF_CONF_HS20_SUPPORT=n
DEF_CONF_WPASUPP_ENABLE=y
DEF_CONF_BLUEZ_ENABLE=y
DEF_CONF_MAC_HW_DRV_SUPPORT=n
DEF_CONF_SYSSTAT_SUPPORT=n
DEF_CONF_IPERF_ENABLE=n
DEF_CONF_BT_SUPPORT=n
DEF_CONF_NTHREADS=4
DEF_CONF_DEMO_ENABLED=n

##############################################################################
###                    End Global settings section                         ###
##############################################################################

#----------------------------------------------------------------------------------------------------

##############################################################################

##############################################################################

##############################################################################

##############################################################################
# HOST PLATFORM = HK6030
##############################################################################

ifeq ($(PLATFORM),HK6030)

DEF_SDK_PATH = /home/developer/work/flexbuild_lsdk1812/build
DEF_CONF_CROSS_COMPILE = /usr/bin/aarch64-linux-gnu-
DEF_CONF_SYSROOT_PATH = $(DEF_SDK_PATH)/rfs/rootfs_buildroot_LS_arm64_tiny/staging
DEF_CONF_LINUX_SRC = $(DEF_SDK_PATH)/linux/linux/arm64/LS/output/LSDK-18.12-V4.14

# ARCH
DEF_CONF_ARCH=arm64

# Components choice (y/n)
DEF_CONF_LIBNL_ENABLE=y
DEF_CONF_BT_SUPPORT=y
#DEF_CONF_LIBSSL_ENABLE=n
endif
### EOP

##############################################################################

##############################################################################

##############################################################################
###                 Platform/OEM specific section END                      ###
##############################################################################

#----------------------------------------------------------------------------------------------------

##############################################################################
# Override defaults if necessary and export values
##############################################################################

# Paths used on the target host system
export host_install_dir = $(DEF_CONF_HOST_INSTALL_DIR)
export host_cfg_dir = $(DEF_CONF_HOST_CFG_DIR)

# Cross-compilation
export SDK_PATH = $(DEF_SDK_PATH)
export CROSS_COMPILE = $(DEF_CONF_CROSS_COMPILE)
export LINUX_SRC = $(DEF_CONF_LINUX_SRC)
export SYSROOT_PATH = $(DEF_CONF_SYSROOT_PATH)
export KDIR = $(DEF_CONF_LINUX_SRC)

CONFIG_ARCH = $(DEF_CONF_ARCH)
ifneq ($(CONFIG_ARCH),)
export ARCH=$(CONFIG_ARCH)
else
export ARCH=x86
endif

# Components selection

# Other options
export CECFG_HS20_SUPPORT = $(DEF_CONF_HS20_SUPPORT)
export CECFG_IPERF_ENABLE = $(DEF_CONF_IPERF_ENABLE)
export CECFG_LIBNL_ENABLE = $(DEF_CONF_LIBNL_ENABLE)
export CECFG_LIBSSL_ENABLE = $(DEF_CONF_LIBSSL_ENABLE)
export CECFG_SYSSTAT_SUPPORT = $(DEF_CONF_SYSSTAT_SUPPORT)
export CECFG_TRACE = $(DEF_CONF_TRACE)
export CECFG_WPASUPP_ENABLE = $(DEF_CONF_WPASUPP_ENABLE)
export CECFG_BLUEZ_ENABLE = $(DEF_CONF_BLUEZ_ENABLE)
export CECFG_DUMMY_PHY = $(DEF_CONF_DUMMY_PHY)
export CECFG_MAC_HW_DRV_SUPPORT = $(DEF_CONF_MAC_HW_DRV_SUPPORT)
export CECFG_CL_BT = $(DEF_CONF_BT_SUPPORT)
export CECFG_DEMO_ENABLED = $(DEF_CONF_DEMO_ENABLED)

export CONFIG_CELENO_PLATFORM = $(PLATFORM)
export CONFIG_CELENO_NTHREADS = $(DEF_CONF_NTHREADS)

