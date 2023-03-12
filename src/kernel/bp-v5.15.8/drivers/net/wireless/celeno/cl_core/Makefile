# SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
obj-$(CPTCFG_CL6K) += cl_core.o

ccflags-y += -I$(src) -I$(src)/reg -Werror -D__CHECK_ENDIAN__ -DDEBUG
ifeq ($(CECFG_DUMMY_PHY),y)
	ccflags-y += -DCE_DUMMY_PHY
endif

cl-objs += core.o pci.o usb.o chip.o chip_config.o config.o lcu.o phy.o rf_boot.o
cl_core-y += $(cl-objs)

ifneq ($(CECFG_DEMO_ENABLED),)
ccflags-y += -DCONFIG_DEMO_ENABLED
endif
