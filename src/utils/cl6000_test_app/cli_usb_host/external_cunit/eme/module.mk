$(this).ALLOW_LIBRARY_CACHING := TRUE

PROJECT.INCLUDES += external_cunit/CUnit/Headers
PROJECT.INCLUDES += external_cunit/CUnit/Sources/Test
#PROJECT.INCLUDES += external_cunit/CUnit/Sources/Win

PROJECT.USED.LIBS.NAME += cunit

PROJECT.MODULELIST += external_cunit

#PREREQUISITES.LOCAL := emc_std
#PREREQUISITES.LOCAL += external_log4c
