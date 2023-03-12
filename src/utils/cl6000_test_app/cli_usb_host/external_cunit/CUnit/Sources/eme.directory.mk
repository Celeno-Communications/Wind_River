ifndef EME_REDIRECT_MK_INCLUDED
include ../../../eme/redirect.mk
endif

SUBDIRS =
SUBDIRS += $(if $(EMC.CUNIT.RUNNER.AUTOMATED),Automated)
SUBDIRS += $(if $(EMC.CUNIT.RUNNER.BASIC),Basic)
SUBDIRS += $(if $(EMC.CUNIT.RUNNER.CONSOLE),Console)
SUBDIRS += $(if $(EMC.CUNIT.RUNNER.CURSES),Curses)
SUBDIRS += Framework
#SUBDIRS += Test
#SUBDIRS += Win



