# SPDX-License-Identifier: ISC

obj-$(CPTCFG_MT7921E) += mt7921e.o

CFLAGS_trace.o := -I$(src)

mt7921e-y := pci.o mac.o mcu.o dma.o eeprom.o main.o init.o debugfs.o trace.o
