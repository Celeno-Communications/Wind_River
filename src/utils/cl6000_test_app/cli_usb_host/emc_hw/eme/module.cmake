eme_add_prerequisites(emc_std_ext)

if(EMC_HW_PORT_VTBL_MMIO)
  set(EMC_HW_PORT_VTBL 1)
endif()

if(EMC_MEMORY_POOL_TYPE_XTOS OR
   EMC_MEMORY_POOL_TYPE_TLSF OR
   EMC_MEMORY_POOL_TYPE_MALLOC OR
   EMC_MEMORY_POOL_TYPE_STATIC OR
   EMC_MEMORY_POOL_TYPE_UNCACHED)
 set(EMC_MEMORY_POOL 1)
endif()

if(EMC_MEMORY_POOL_TYPE_TLSF)
  eme_add_prerequisites(external_baisoku_tlsf)
endif()


