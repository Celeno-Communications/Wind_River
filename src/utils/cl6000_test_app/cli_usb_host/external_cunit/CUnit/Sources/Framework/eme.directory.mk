ifndef EME_REDIRECT_MK_INCLUDED
include ../../../../eme/redirect.mk
endif

PROJECT.MAIN.TARGET.LIB.NAME := cunit

SOURCES =
SOURCES += CUError.c
SOURCES += MyMem.c
SOURCES += TestDB.c
SOURCES += TestRun.c
SOURCES += Util.c
