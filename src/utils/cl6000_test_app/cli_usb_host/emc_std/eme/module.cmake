eme_add_prerequisites(emc_config)
#if ( NOT (EMC_STD_THREAD STREQUAL "STD") )
#  eme_add_prerequisites(emc_std_thread)
#endif()


if (EMC_STD_ASSERT STREQUAL "NONE")
   set(EMC_STD_ASSERT_NONE 1)
elseif (EMC_STD_ASSERT STREQUAL "STD")
   set(EMC_STD_ASSERT_STD 1)
elseif (EMC_STD_ASSERT STREQUAL "EMULATE")
   set(EMC_STD_ASSERT_EMULATE 1)
endif()

string(TOUPPER ${EMC_STD_ASSERT_ABI} EMC_STD_ASSERT_ABI_UPPERCASE)
string(TOUPPER ${EMC_STD_ASSERT_IMPL} EMC_STD_ASSERT_IMPL_UPPERCASE)
string(TOUPPER ${EMC_STD_ASSERT_SRC_POS} EMC_STD_ASSERT_SRC_POS_UPPERCASE)

if (EMC_STD_STDIO STREQUAL "NONE")
   set(EMC_STD_STDIO_NONE 1)
elseif (EMC_STD_STDIO STREQUAL "STD")
   set(EMC_STD_STDIO_STD 1)
elseif (EMC_STD_STDIO STREQUAL "EMULATE")
   set(EMC_STD_STDIO_EMULATE 1)
endif()

if (EMC_STD_STDLIB STREQUAL "EMULATE")
   set(EMC_STD_STDLIB_EMULATE 1)
endif()

if( NOT(EMC_STD_MALLOC STREQUAL "STD"))
  set(EMC_STD_MALLOC_EMULATE 1)
endif()

if(EMC_STD_MALLOC STREQUAL "AMS")
  eme_add_prerequisites(external_ams_heap)
elseif(EMC_STD_MALLOC STREQUAL "XALLOC")
  eme_add_prerequisites(external_comneon_util)
elseif(EMC_STD_MALLOC STREQUAL "tlsf")
  eme_add_prerequisites(external_baisoku_tlsf)
elseif(EMC_STD_MALLOC STREQUAL "XTOS")
  eme_add_prerequisites(external_sue)
  eme_add_prerequisites(emc_std_thread)
endif()

if(EMC_STD_DMA_MALLOC STREQUAL "UTA")
  eme_add_prerequisites(external_comneon_util)
endif()

if(EMC_STD_MALLOC MATCHES "^(rcx|XALLOC)$")
  eme_add_prerequisites(emc_log)
endif()

if((EMC_STD_MALLOC_LOCK STREQUAL "SPINLOCK") AND (NOT (EMC_STD_SPINLOCK STREQUAL "NONE")) )
  eme_add_prerequisites(emc_std_thread)
endif()

string(TOUPPER ${EMC_STD_ATOMIC} EMC_STD_ATOMIC_UPPERCASE)

string(TOUPPER ${EMC_STD_MUTEX} EMC_STD_MUTEX_UPPERCASE)
string(TOUPPER ${EMC_STD_SPINLOCK} EMC_STD_SPINLOCK_UPPERCASE)

if(EMC_STD_MUTEX MATCHES "extern")
  eme_add_prerequisites(emc_std_thread)
endif()

if((EMC_STD_MUTEX STREQUAL "uta") OR (EMC_STD_SPINLOCK STREQUAL "uta"))
  eme_add_prerequisites(external_comneon_uta_os)
endif()

if((EMC_STD_TIMESTAMP STREQUAL "embos") OR (EMC_STD_SPINLOCK STREQUAL "embos") )
  eme_add_prerequisites(external_embos)
endif()


string(TOUPPER ${EMC_STD_TIMESTAMP} EMC_STD_TIMESTAMP_UPPERCASE)

if(EMC_STD_MALLOC_LOCK STREQUAL "MUTEX")
  set(EMC_STD_MALLOC_LOCK_MUTEX 1)
  set(EMC_STD_MALLOC_LOCK_SPINLOCK 0)
elseif(EMC_STD_MALLOC_LOCK STREQUAL "SPINLOCK")
  set(EMC_STD_MALLOC_LOCK_MUTEX 0)
  set(EMC_STD_MALLOC_LOCK_SPINLOCK 1)
endif()

