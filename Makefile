# *************************************************************************
# *	(C) Copyright 2014, Celeno, Inc.
# *************************************************************************

-include ./src/celeno.mk

.PHONY: all bp hostapd iw build package install clean

export VERBOSE

all:
	$(MAKE) package
	$(MAKE) install

bp:
	./cl_hp_build.sh bp config
	./cl_hp_build.sh bp build

bp_clean:
	./cl_hp_build.sh bp clean

hostapd:
	./cl_hp_build.sh hostapd build
	cp src/utils/hostapd/hostapd/hostapd build/bin
	cp src/utils/hostapd/hostapd/hostapd_cli build/bin
iw:
	./cl_hp_build.sh iw 

build:
	./cl_hp_build.sh all
	./cl_hp_build.sh install

package: build
	./tools/pack_package.sh

# Not all platforms need the install script and not all tolerate interactive sudo call.
# So we'll do that only if platform really needs that. Platform can overwrite default
# script (and set permissions!) using platformdb/<class>/tools/
install:
	[ -x ./tools/cl_br_install.sh ] && ./tools/cl_br_install.sh || true

info:
	./cl_hp_build.sh info

clean:
	./cl_hp_build.sh clean
