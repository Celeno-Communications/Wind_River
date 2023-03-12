/* This linker script generated from xt-genldscripts.tpp for LSP /home/user/work/hp-trunk/cl6000lsp/lmac/RI-2020.5/LX7_Denali/lmac */
/* Linker Script for default link */
/* manual modified for umac */
MEMORY
{
  dram0_0_seg :                       	org = 0x40000000, len = 0x2FEFF
  config_seg  :                         org = 0x4002FF00, len = 0xD0
  exc_info_seg :                        org = 0x4002FFD0, len = 0x24
  bootrom_cfg_seg :                     org = 0x4002FFF4, len = 0x0C
  iram0_0_seg :                       	org = 0x40080000, len = 0x2E0
  iram0_2_seg :                       	org = 0x40080400, len = 0x178
  iram0_3_seg :                       	org = 0x40080578, len = 0x4
  iram0_4_seg :                       	org = 0x4008057C, len = 0x1C
  iram0_5_seg :                       	org = 0x40080598, len = 0x4
  iram0_6_seg :                       	org = 0x4008059C, len = 0x1C
  iram0_7_seg :                       	org = 0x400805B8, len = 0x4
  iram0_8_seg :                       	org = 0x400805BC, len = 0x1C
  iram0_9_seg :                       	org = 0x400805D8, len = 0x44
  iram0_10_seg :                      	org = 0x4008061C, len = 0x1C
  iram0_11_seg :                      	org = 0x40080638, len = 0x4
  iram0_12_seg :                      	org = 0x4008063C, len = 0x1C
  iram0_13_seg :                      	org = 0x40080658, len = 0x4
  iram0_14_seg :                      	org = 0x4008065C, len = 0x1C
  iram0_15_seg :                      	org = 0x40080678, len = 0x4
  iram0_16_seg :                      	org = 0x4008067C, len = 0x1C
  iram0_17_seg :                      	org = 0x40080698, len = 0x2F968
  irom0_0_seg :                       	org = 0x50000000, len = 0x100000
  dual_shared_memory_seg :            	org = 0x60000000, len = 0x3F00
  lmac_shared_memory_seg :            	org = 0x60003F00, len = 0x5C000
  umac_shared_memory_seg :            	org = 0x6005FF00, len = 0x100
  lamac_memory_seg :                  	org = 0x60100000, len = 0x40000
  remote_prim_umac_dram_seg :         	org = 0x60280000, len = 0x30000
  machw_mib_memory_seg :              	org = 0x60400B70, len = 0x400
  laphy_memory_seg :                  	org = 0x61900000, len = 0x100000
  fake_memory_seg :                   	org = 0x70000000, len = 0x100000
}

PHDRS
{
  dram0_0_phdr PT_LOAD;
  dram0_0_bss_phdr PT_LOAD;
  config_seg_phdr PT_LOAD;
  exc_info_phdr PT_LOAD;
  bootrom_cfg_phdr PT_LOAD;
  iram0_0_phdr PT_LOAD;
  iram0_1_phdr PT_LOAD;
  iram0_2_phdr PT_LOAD;
  iram0_3_phdr PT_LOAD;
  iram0_4_phdr PT_LOAD;
  iram0_5_phdr PT_LOAD;
  iram0_6_phdr PT_LOAD;
  iram0_7_phdr PT_LOAD;
  iram0_8_phdr PT_LOAD;
  iram0_9_phdr PT_LOAD;
  iram0_10_phdr PT_LOAD;
  iram0_11_phdr PT_LOAD;
  iram0_12_phdr PT_LOAD;
  iram0_13_phdr PT_LOAD;
  iram0_14_phdr PT_LOAD;
  iram0_15_phdr PT_LOAD;
  iram0_16_phdr PT_LOAD;
  iram0_17_phdr PT_LOAD;
  irom0_0_phdr PT_LOAD;
  dual_shared_memory_phdr PT_LOAD;
  dual_shared_memory_bss_phdr PT_LOAD;
  lmac_shared_memory_phdr PT_LOAD;
  lmac_shared_memory_bss_phdr PT_LOAD;
  umac_shared_memory_phdr PT_LOAD;
  umac_shared_memory_bss_phdr PT_LOAD;
  lamac_memory_phdr PT_LOAD;
  remote_prim_umac_dram_phdr PT_LOAD;
  machw_mib_memory_phdr PT_LOAD;
  laphy_memory_phdr PT_LOAD;
  fake_memory_phdr PT_LOAD;
}


/*  Default entry point:  */
ENTRY(_ResetVector)


/*  Memory boundary addresses:  */
_memmap_mem_dram0_start = 0x40000000;
_memmap_mem_dram0_end   = 0x40030000;
_memmap_mem_dram1_start = 0x40040000;
_memmap_mem_dram1_end   = 0x40080000;
_memmap_mem_iram0_start = 0x40080000;
_memmap_mem_iram0_end   = 0x400B0000;
_memmap_mem_irom0_start = 0x50000000;
_memmap_mem_irom0_end   = 0x50010000;
_memmap_mem_sram_start = 0x60000000;
_memmap_mem_sram_end   = 0xe0000000;

/*  Memory segment boundary addresses:  */
_memmap_seg_dram0_0_start  = 0x40000000;
_memmap_seg_dram0_0_max    = 0x4002feff;
_memmap_seg_config_start   = 0x4002ff00;
_memmap_seg_config_max     = 0x4002ffbf;
_memmap_seg_exc_info_start = 0x4002ffc0;
_memmap_seg_exc_info_max   = 0x40030000;
_memmap_seg_iram0_0_start = 0x40080000;
_memmap_seg_iram0_0_max   = 0x400802e0;
_memmap_seg_iram0_2_start = 0x40080400;
_memmap_seg_iram0_2_max   = 0x40080578;
_memmap_seg_iram0_3_start = 0x40080578;
_memmap_seg_iram0_3_max   = 0x4008057c;
_memmap_seg_iram0_4_start = 0x4008057c;
_memmap_seg_iram0_4_max   = 0x40080598;
_memmap_seg_iram0_5_start = 0x40080598;
_memmap_seg_iram0_5_max   = 0x4008059c;
_memmap_seg_iram0_6_start = 0x4008059c;
_memmap_seg_iram0_6_max   = 0x400805b8;
_memmap_seg_iram0_7_start = 0x400805b8;
_memmap_seg_iram0_7_max   = 0x400805bc;
_memmap_seg_iram0_8_start = 0x400805bc;
_memmap_seg_iram0_8_max   = 0x400805d8;
_memmap_seg_iram0_9_start = 0x400805d8;
_memmap_seg_iram0_9_max   = 0x4008061c;
_memmap_seg_iram0_10_start = 0x4008061c;
_memmap_seg_iram0_10_max   = 0x40080638;
_memmap_seg_iram0_11_start = 0x40080638;
_memmap_seg_iram0_11_max   = 0x4008063c;
_memmap_seg_iram0_12_start = 0x4008063c;
_memmap_seg_iram0_12_max   = 0x40080658;
_memmap_seg_iram0_13_start = 0x40080658;
_memmap_seg_iram0_13_max   = 0x4008065c;
_memmap_seg_iram0_14_start = 0x4008065c;
_memmap_seg_iram0_14_max   = 0x40080678;
_memmap_seg_iram0_15_start = 0x40080678;
_memmap_seg_iram0_15_max   = 0x4008067c;
_memmap_seg_iram0_16_start = 0x4008067c;
_memmap_seg_iram0_16_max   = 0x40080698;
_memmap_seg_iram0_17_start = 0x40080698;
_memmap_seg_iram0_17_max   = 0x400b0000;
_memmap_seg_irom0_0_start = 0x50000000;
_memmap_seg_irom0_0_max   = 0x50100000;
_memmap_seg_dual_shared_memory_start = 0x60000000;
_memmap_seg_dual_shared_memory_max   = 0x60003f00;
_memmap_seg_lmac_shared_memory_start = 0x60003f00;
_memmap_seg_lmac_shared_memory_max   = 0x6005ff00;
_memmap_seg_umac_shared_memory_start = 0x6005ff00;
_memmap_seg_umac_shared_memory_max   = 0x60060000;
_memmap_seg_lamac_memory_start = 0x60100000;
_memmap_seg_lamac_memory_max   = 0x60140000;
_memmap_seg_remote_prim_umac_dram_start = 0x60280000;
_memmap_seg_remote_prim_umac_dram_max   = 0x602b0000;
_memmap_seg_machw_mib_memory_start = 0x60400b70;
_memmap_seg_machw_mib_memory_max   = 0x60400f70;
_memmap_seg_laphy_memory_start = 0x61900000;
_memmap_seg_laphy_memory_max   = 0x61a00000;
_memmap_seg_fake_memory_start = 0x70000000;
_memmap_seg_fake_memory_max   = 0x70100000;

_rom_store_table = 0;
PROVIDE(_memmap_reset_vector = 0x40080000);
PROVIDE(_memmap_vecbase_reset = 0x40080400);
/* Various memory-map dependent cache attribute settings: */
_memmap_cacheattr_wb_base = 0x04444200;
_memmap_cacheattr_wt_base = 0x01111200;
_memmap_cacheattr_bp_base = 0x02222200;
_memmap_cacheattr_unused_mask = 0xF00000FF;
_memmap_cacheattr_wb_trapnull = 0x2444422F;
_memmap_cacheattr_wba_trapnull = 0x2444422F;
_memmap_cacheattr_wbna_trapnull = 0x2555522F;
_memmap_cacheattr_wt_trapnull = 0x2111122F;
_memmap_cacheattr_bp_trapnull = 0x2222222F;
_memmap_cacheattr_wb_strict = 0xF44442FF;
_memmap_cacheattr_wt_strict = 0xF11112FF;
_memmap_cacheattr_bp_strict = 0xF22222FF;
_memmap_cacheattr_wb_allvalid = 0x24444222;
_memmap_cacheattr_wt_allvalid = 0x21111222;
_memmap_cacheattr_bp_allvalid = 0x22222222;
_memmap_region_map = 0x0000007C;
PROVIDE(_memmap_cacheattr_reset = _memmap_cacheattr_wb_trapnull);

SECTIONS
{
  .dram0.rodata : ALIGN(4)
  {
    _dram0_rodata_start = ABSOLUTE(.);
    *(.dram0.rodata)
    *(.dram.rodata)
    . = ALIGN (4);
    _dram0_rodata_end = ABSOLUTE(.);
  } >dram0_0_seg :dram0_0_phdr


  .data.mg_umac_registers : ALIGN(4)
  {
    _mg_umac_config_start = ABSOLUTE(.);
    *(.data.mg_umac_config_registers)
    . = ALIGN (4);
    _mg_umac_config_end = ABSOLUTE(.);
  } >config_seg :config_seg_phdr


  .bss.mg_umac_crash_info : ALIGN(4)
  {
    _bssmg_umac_crash_info_start = ABSOLUTE(.);
    *(.bss.mg_umac_crash_info)
    . = ALIGN (4);
    _bss_mg_umac_crash_info_end = ABSOLUTE(.);
  } >exc_info_seg :exc_info_phdr

  .bss.mg_bootrom_cfg : ALIGN(4)
  {
    _bss_mg_bootrom_cfg_start = ABSOLUTE(.);
    *(.bss.mg_bootrom_cfg)
    . = ALIGN (4);
    _bss_mg_bootrom_cfg_end = ABSOLUTE(.);
  } >bootrom_cfg_seg :bootrom_cfg_phdr

  .clib.rodata : ALIGN(4)
  {
    _clib_rodata_start = ABSOLUTE(.);
    *(.clib.rodata)
    . = ALIGN (4);
    _clib_rodata_end = ABSOLUTE(.);
  } >dram0_0_seg :dram0_0_phdr

  .rtos.rodata : ALIGN(4)
  {
    _rtos_rodata_start = ABSOLUTE(.);
    *(.rtos.rodata)
    . = ALIGN (4);
    _rtos_rodata_end = ABSOLUTE(.);
  } >dram0_0_seg :dram0_0_phdr

  .rodata : ALIGN(4)
  {
    _rodata_start = ABSOLUTE(.);
    _offload_resident_start = ABSOLUTE(.);
    *(.rodata)
    *(SORT(.rodata.sort.*))
    KEEP (*(SORT(.rodata.keepsort.*) .rodata.keep.*))
    *(.rodata.*)
    _offload_resident_end = ABSOLUTE(.);
    *(.gnu.linkonce.r.*)
    *(.rodata1)
    __XT_EXCEPTION_TABLE__ = ABSOLUTE(.);
    KEEP (*(.xt_except_table))
    KEEP (*(.gcc_except_table))
    *(.gnu.linkonce.e.*)
    *(.gnu.version_r)
    KEEP (*(.eh_frame))
    /*  C++ constructor and destructor tables, properly ordered:  */
    KEEP (*crtbegin.o(.ctors))
    KEEP (*(EXCLUDE_FILE (*crtend.o) .ctors))
    KEEP (*(SORT(.ctors.*)))
    KEEP (*(.ctors))
    KEEP (*crtbegin.o(.dtors))
    KEEP (*(EXCLUDE_FILE (*crtend.o) .dtors))
    KEEP (*(SORT(.dtors.*)))
    KEEP (*(.dtors))
    /*  C++ exception handlers table:  */
    __XT_EXCEPTION_DESCS__ = ABSOLUTE(.);
    *(.xt_except_desc)
    *(.gnu.linkonce.h.*)
    __XT_EXCEPTION_DESCS_END__ = ABSOLUTE(.);
    *(.xt_except_desc_end)
    *(.dynamic)
    *(.gnu.version_d)
    . = ALIGN(4);		/* this table MUST be 4-byte aligned */
    _bss_table_start = ABSOLUTE(.);
    LONG(_bss_start)
    LONG(_bss_end)
    LONG(_sram_bss_start)
    LONG(_sram_bss_end)
    LONG(LMAC_SHAREDRAM_bss_start)
    LONG(LMAC_SHAREDRAM_bss_end)
    LONG(UMAC_SHAREDRAM_bss_start)
    LONG(UMAC_SHAREDRAM_bss_end)
    _bss_table_end = ABSOLUTE(.);
    . = ALIGN (4);
    _rodata_end = ABSOLUTE(.);
  } >dram0_0_seg :dram0_0_phdr

  .clib.data : ALIGN(4)
  {
    _clib_data_start = ABSOLUTE(.);
    *(.clib.data)
    . = ALIGN (4);
    _clib_data_end = ABSOLUTE(.);
  } >dram0_0_seg :dram0_0_phdr

  .clib.percpu.data : ALIGN(4)
  {
    _clib_percpu_data_start = ABSOLUTE(.);
    *(.clib.percpu.data)
    . = ALIGN (4);
    _clib_percpu_data_end = ABSOLUTE(.);
  } >dram0_0_seg :dram0_0_phdr

  .rtos.percpu.data : ALIGN(4)
  {
    _rtos_percpu_data_start = ABSOLUTE(.);
    *(.rtos.percpu.data)
    . = ALIGN (4);
    _rtos_percpu_data_end = ABSOLUTE(.);
  } >dram0_0_seg :dram0_0_phdr

  .rtos.data : ALIGN(4)
  {
    _rtos_data_start = ABSOLUTE(.);
    *(.rtos.data)
    . = ALIGN (4);
    _rtos_data_end = ABSOLUTE(.);
  } >dram0_0_seg :dram0_0_phdr

  .dram0.data : ALIGN(4)
  {
    _dram0_data_start = ABSOLUTE(.);
    *(.dram0.data)
    *(.dram.data)
    . = ALIGN (4);
    _dram0_data_end = ABSOLUTE(.);
  } >dram0_0_seg :dram0_0_phdr

  .data : ALIGN(4)
  {
    _data_start = ABSOLUTE(.);
    *(.data)
    *(SORT(.data.sort.*))
    KEEP (*(SORT(.data.keepsort.*) .data.keep.*))
    *(.data.*)
    *(.gnu.linkonce.d.*)
    KEEP(*(.gnu.linkonce.d.*personality*))
    *(.data1)
    *(.sdata)
    *(.sdata.*)
    *(.gnu.linkonce.s.*)
    *(.sdata2)
    *(.sdata2.*)
    *(.gnu.linkonce.s2.*)
    KEEP(*(.jcr))
    *(__llvm_prf_cnts)
    *(__llvm_prf_data)
    *(__llvm_prf_vnds)
    . = ALIGN (4);
    _data_end = ABSOLUTE(.);
  } >dram0_0_seg :dram0_0_phdr

  .bss (NOLOAD) : ALIGN(8)
  {
    . = ALIGN (8);
    _bss_start = ABSOLUTE(.);
    *(.dynsbss)
    *(.sbss)
    *(.sbss.*)
    *(.gnu.linkonce.sb.*)
    *(.scommon)
    *(.sbss2)
    *(.sbss2.*)
    *(.gnu.linkonce.sb2.*)
    *(.dynbss)
    *(EXCLUDE_FILE(*ipc_shared.o *hal_desc.o *txl_buffer_shared.o *txl_frame_shared.o *la_shared.o *la_mem_mac.o *la_mem_phy.o *hal_mib.o *imb_shared.o) .bss)
    *(EXCLUDE_FILE(*ipc_shared.o *hal_desc.o *txl_buffer_shared.o *txl_frame_shared.o *la_shared.o *la_mem_mac.o *la_mem_phy.o *hal_mib.o *imb_shared.o) .bss.*)
    *(SORT(.bss.sort.*))
    KEEP (*(SORT(.bss.keepsort.*) .bss.keep.*))
    *(.gnu.linkonce.b.*)
    *(COMMON)
    *(.clib.bss)
    *(.clib.percpu.bss)
    *(.rtos.percpu.bss)
    *(.rtos.bss)
    *(.dram0.bss)
    . = ALIGN (8);
    _bss_end = ABSOLUTE(.);
    _end = ALIGN(0x8);
    PROVIDE(end = ALIGN(0x8));
    _stack_sentry = ALIGN(0x8);
    _memmap_seg_dram0_0_end = ALIGN(0x8);
  } >dram0_0_seg :dram0_0_bss_phdr

  PROVIDE(__stack = 0x4002ff00);
  _heap_sentry = 0x4002ff00;

  EXC_INFORAM : ALIGN(4)
  {
    EXC_INFO_start = ABSOLUTE(.);
    *(EXC_INFORAM)
    . = ALIGN (4);
    EXC_INFO_end = ABSOLUTE(.);
    _memmap_seg_exc_info_end = ALIGN(0x8);
  } >exc_info_seg :exc_info_phdr


  _memmap_mem_dram0_max = ABSOLUTE(.);

  .ResetVector.text : ALIGN(4)
  {
    _ResetVector_text_start = ABSOLUTE(.);
    KEEP (*(.ResetVector.text))
    . = ALIGN (4);
    _ResetVector_text_end = ABSOLUTE(.);
  } >iram0_0_seg :iram0_0_phdr

  .ResetHandler.text : ALIGN(4)
  {
    _ResetHandler_text_start = ABSOLUTE(.);
    *(.ResetHandler.literal .ResetHandler.text)
    . = ALIGN (4);
    _ResetHandler_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_0_end = ALIGN(0x8);
  } >iram0_0_seg :iram0_0_phdr



  .WindowVectors.text : ALIGN(4)
  {
    _WindowVectors_text_start = ABSOLUTE(.);
    KEEP (*(.WindowVectors.text))
    . = ALIGN (4);
    _WindowVectors_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_2_end = ALIGN(0x8);
  } >iram0_2_seg :iram0_2_phdr


  .Level2InterruptVector.literal : ALIGN(4)
  {
    _Level2InterruptVector_literal_start = ABSOLUTE(.);
    *(.Level2InterruptVector.literal)
    . = ALIGN (4);
    _Level2InterruptVector_literal_end = ABSOLUTE(.);
    _memmap_seg_iram0_3_end = ALIGN(0x8);
  } >iram0_3_seg :iram0_3_phdr


  .Level2InterruptVector.text : ALIGN(4)
  {
    _Level2InterruptVector_text_start = ABSOLUTE(.);
    KEEP (*(.Level2InterruptVector.text))
    . = ALIGN (4);
    _Level2InterruptVector_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_4_end = ALIGN(0x8);
  } >iram0_4_seg :iram0_4_phdr


  .Level3InterruptVector.literal : ALIGN(4)
  {
    _Level3InterruptVector_literal_start = ABSOLUTE(.);
    *(.Level3InterruptVector.literal)
    . = ALIGN (4);
    _Level3InterruptVector_literal_end = ABSOLUTE(.);
    _memmap_seg_iram0_5_end = ALIGN(0x8);
  } >iram0_5_seg :iram0_5_phdr


  .Level3InterruptVector.text : ALIGN(4)
  {
    _Level3InterruptVector_text_start = ABSOLUTE(.);
    KEEP (*(.Level3InterruptVector.text))
    . = ALIGN (4);
    _Level3InterruptVector_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_6_end = ALIGN(0x8);
  } >iram0_6_seg :iram0_6_phdr


  .DebugExceptionVector.literal : ALIGN(4)
  {
    _DebugExceptionVector_literal_start = ABSOLUTE(.);
    *(.DebugExceptionVector.literal)
    . = ALIGN (4);
    _DebugExceptionVector_literal_end = ABSOLUTE(.);
    _memmap_seg_iram0_7_end = ALIGN(0x8);
  } >iram0_7_seg :iram0_7_phdr


  .DebugExceptionVector.text : ALIGN(4)
  {
    _DebugExceptionVector_text_start = ABSOLUTE(.);
    KEEP (*(.DebugExceptionVector.text))
    . = ALIGN (4);
    _DebugExceptionVector_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_8_end = ALIGN(0x8);
  } >iram0_8_seg :iram0_8_phdr


  .NMIExceptionVector.literal : ALIGN(4)
  {
    _NMIExceptionVector_literal_start = ABSOLUTE(.);
    *(.NMIExceptionVector.literal)
    . = ALIGN (4);
    _NMIExceptionVector_literal_end = ABSOLUTE(.);
    _memmap_seg_iram0_9_end = ALIGN(0x8);
  } >iram0_9_seg :iram0_9_phdr


  .NMIExceptionVector.text : ALIGN(4)
  {
    _NMIExceptionVector_text_start = ABSOLUTE(.);
    KEEP (*(.NMIExceptionVector.text))
    . = ALIGN (4);
    _NMIExceptionVector_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_10_end = ALIGN(0x8);
  } >iram0_10_seg :iram0_10_phdr


  .KernelExceptionVector.literal : ALIGN(4)
  {
    _KernelExceptionVector_literal_start = ABSOLUTE(.);
    *(.KernelExceptionVector.literal)
    . = ALIGN (4);
    _KernelExceptionVector_literal_end = ABSOLUTE(.);
    _memmap_seg_iram0_11_end = ALIGN(0x8);
  } >iram0_11_seg :iram0_11_phdr


  .KernelExceptionVector.text : ALIGN(4)
  {
    _KernelExceptionVector_text_start = ABSOLUTE(.);
    KEEP (*(.KernelExceptionVector.text))
    . = ALIGN (4);
    _KernelExceptionVector_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_12_end = ALIGN(0x8);
  } >iram0_12_seg :iram0_12_phdr


  .UserExceptionVector.literal : ALIGN(4)
  {
    _UserExceptionVector_literal_start = ABSOLUTE(.);
    *(.UserExceptionVector.literal)
    . = ALIGN (4);
    _UserExceptionVector_literal_end = ABSOLUTE(.);
    _memmap_seg_iram0_13_end = ALIGN(0x8);
  } >iram0_13_seg :iram0_13_phdr


  .UserExceptionVector.text : ALIGN(4)
  {
    _UserExceptionVector_text_start = ABSOLUTE(.);
    KEEP (*(.UserExceptionVector.text))
    . = ALIGN (4);
    _UserExceptionVector_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_14_end = ALIGN(0x8);
  } >iram0_14_seg :iram0_14_phdr


  .DoubleExceptionVector.literal : ALIGN(4)
  {
    _DoubleExceptionVector_literal_start = ABSOLUTE(.);
    *(.DoubleExceptionVector.literal)
    . = ALIGN (4);
    _DoubleExceptionVector_literal_end = ABSOLUTE(.);
    _memmap_seg_iram0_15_end = ALIGN(0x8);
  } >iram0_15_seg :iram0_15_phdr


  .DoubleExceptionVector.text : ALIGN(4)
  {
    _DoubleExceptionVector_text_start = ABSOLUTE(.);
    KEEP (*(.DoubleExceptionVector.text))
    . = ALIGN (4);
    _DoubleExceptionVector_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_16_end = ALIGN(0x8);
  } >iram0_16_seg :iram0_16_phdr


  .iram0.text : ALIGN(4)
  {
    _iram0_text_start = ABSOLUTE(.);
    *(.iram0.literal .iram.literal .iram.text.literal .iram0.text .iram.text)
    . = ALIGN (4);
    _iram0_text_end = ABSOLUTE(.);
  } >iram0_17_seg :iram0_17_phdr

  .text : ALIGN(4)
  {
    _stext = .;
    _text_start = ABSOLUTE(.);
    *(.entry.text)
    *(.init.literal)
    KEEP(*(.init))
    *(.literal.sort.* SORT(.text.sort.*))
    KEEP (*(.literal.keepsort.* SORT(.text.keepsort.*) .literal.keep.* .text.keep.* .literal.*personality* .text.*personality*))
    *(.literal .text .literal.* .text.* .stub .gnu.warning .gnu.linkonce.literal.* .gnu.linkonce.t.*.literal .gnu.linkonce.t.*)
    *(.fini.literal)
    KEEP(*(.fini))
    *(.gnu.version)
    . = ALIGN (4);
    _text_end = ABSOLUTE(.);
    _etext = .;
  } >iram0_17_seg :iram0_17_phdr

  .clib.text : ALIGN(4)
  {
    _clib_text_start = ABSOLUTE(.);
    *(.clib.literal .clib.text)
    . = ALIGN (4);
    _clib_text_end = ABSOLUTE(.);
  } >iram0_17_seg :iram0_17_phdr

  .rtos.text : ALIGN(4)
  {
    _rtos_text_start = ABSOLUTE(.);
    *(.rtos.literal .rtos.text)
    . = ALIGN (4);
    _rtos_text_end = ABSOLUTE(.);
  } >iram0_17_seg :iram0_17_phdr

  _memmap_mem_iram0_max = ABSOLUTE(.);

  .irom0.text : ALIGN(4)
  {
    _irom0_text_start = ABSOLUTE(.);
    *(.irom0.literal .irom.literal .irom.text.literal .irom0.text .irom.text)
    . = ALIGN (4);
    _irom0_text_end = ABSOLUTE(.);
    _memmap_seg_irom0_0_end = ALIGN(0x8);
  } >irom0_0_seg :irom0_0_phdr

  _memmap_mem_irom0_max = ABSOLUTE(.);

  SHAREDRAM : ALIGN(4)
  {
    SHAREDRAM_start = ABSOLUTE(.);
    *(SHAREDRAM)
    *ipc_shared.o(.bss .bss.*)
    . = ALIGN (4);
    SHAREDRAM_end = ABSOLUTE(.);
  } >dual_shared_memory_seg :dual_shared_memory_phdr

  .sram.rodata : ALIGN(4)
  {
    _sram_rodata_start = ABSOLUTE(.);
    *(.sram.rodata)
    . = ALIGN (4);
    _sram_rodata_end = ABSOLUTE(.);
  } >dual_shared_memory_seg :dual_shared_memory_phdr

  .sram.text : ALIGN(4)
  {
    _sram_text_start = ABSOLUTE(.);
    *(.sram.literal .sram.text)
    . = ALIGN (4);
    _sram_text_end = ABSOLUTE(.);
  } >dual_shared_memory_seg :dual_shared_memory_phdr

  .sram.data : ALIGN(4)
  {
    _sram_data_start = ABSOLUTE(.);
    *(.sram.data)
    . = ALIGN (4);
    _sram_data_end = ABSOLUTE(.);
  } >dual_shared_memory_seg :dual_shared_memory_phdr

  __llvm_prf_names : ALIGN(4)
  {
    __llvm_prf_names_start = ABSOLUTE(.);
    *(__llvm_prf_names)
    . = ALIGN (4);
    __llvm_prf_names_end = ABSOLUTE(.);
  } >dual_shared_memory_seg :dual_shared_memory_phdr

  .sram.bss (NOLOAD) : ALIGN(8)
  {
    . = ALIGN (8);
    _sram_bss_start = ABSOLUTE(.);
    *(.sram.bss)
    . = ALIGN (8);
    _sram_bss_end = ABSOLUTE(.);
    _memmap_seg_dual_shared_memory_end = ALIGN(0x8);
  } >dual_shared_memory_seg :dual_shared_memory_bss_phdr


  LMAC_SHAREDRAM : ALIGN(4)
  {
    LMAC_SHAREDRAM_start = ABSOLUTE(.);
    *(LMAC_SHAREDRAM)
    *hal_desc.o(.bss .bss.*)
    *la_shared.o(.bss .bss.*)
    *txl_frame_shared.o(.bss .bss.*)
    . = ALIGN (4);
    LMAC_SHAREDRAM_end = ABSOLUTE(.);
  } >lmac_shared_memory_seg :lmac_shared_memory_phdr

  LMAC_SHAREDRAM.bss (NOLOAD) : ALIGN(8)
  {
    . = ALIGN (8);
    LMAC_SHAREDRAM_bss_start = ABSOLUTE(.);
    *(LMAC_SHAREDRAM.bss)
    *txl_buffer_shared.o(.bss .bss.*)
    . = ALIGN (8);
    LMAC_SHAREDRAM_bss_end = ABSOLUTE(.);
    _memmap_seg_lmac_shared_memory_end = ALIGN(0x8);
  } >lmac_shared_memory_seg :lmac_shared_memory_bss_phdr


  UMAC_SHAREDRAM : ALIGN(4)
  {
    UMAC_SHAREDRAM_start = ABSOLUTE(.);
    *(UMAC_SHAREDRAM)
    . = ALIGN (4);
    UMAC_SHAREDRAM_end = ABSOLUTE(.);
  } >umac_shared_memory_seg :umac_shared_memory_phdr

  UMAC_SHAREDRAM.bss (NOLOAD) : ALIGN(8)
  {
    . = ALIGN (8);
    UMAC_SHAREDRAM_bss_start = ABSOLUTE(.);
    *(UMAC_SHAREDRAM.bss)
    . = ALIGN (8);
    UMAC_SHAREDRAM_bss_end = ABSOLUTE(.);
    _memmap_seg_umac_shared_memory_end = ALIGN(0x8);
  } >umac_shared_memory_seg :umac_shared_memory_bss_phdr


  LARAMMAC : ALIGN(4)
  {
    LARAMMAC_start = ABSOLUTE(.);
    KEEP (*(LARAMMAC))
    *la_mem_mac.o(.bss .bss.*)
    . = ALIGN (4);
    LARAMMAC_end = ABSOLUTE(.);
    _memmap_seg_lamac_memory_end = ALIGN(0x8);
  } >lamac_memory_seg :lamac_memory_phdr


  REMOTE_PRIMDRAM (NOLOAD): ALIGN(4)
  {
    REMOTE_PRIMDRAM_start = ABSOLUTE(.);
    KEEP (*(REMOTE_PRIMDRAM))
    . = ALIGN (4);
    REMOTE_PRIMDRAM_end = ABSOLUTE(.);
  } >remote_prim_umac_dram_seg :remote_prim_umac_dram_phdr

  MACHW_MIB : ALIGN(4)
  {
    MACHW_MIB_start = ABSOLUTE(.);
    KEEP (*(MACHW_MIB))
    *hal_mib.o(.bss .bss.*)
    . = ALIGN (4);
    MACHW_MIB_end = ABSOLUTE(.);
    _memmap_seg_machw_mib_memory_end = ALIGN(0x8);
  } >machw_mib_memory_seg :machw_mib_memory_phdr


  LARAMPHY : ALIGN(4)
  {
    LARAMPHY_start = ABSOLUTE(.);
    KEEP (*(LARAMPHY))
    *la_mem_phy.o(.bss .bss.*)
    . = ALIGN (4);
    LARAMPHY_end = ABSOLUTE(.);
    _memmap_seg_laphy_memory_end = ALIGN(0x8);
  } >laphy_memory_seg :laphy_memory_phdr


  REMOTE_STR : AT(LOADADDR(.data ) + ((SIZEOF(.data) + 3) & 0xFFFFFFFC))  ALIGN(4)
  {
    REMOTE_STR_start = ABSOLUTE(.);
    LONG(_offload_resident_start)
    LONG(_offload_resident_end)
    KEEP (*(rodata.offload))
    KEEP (*(REMOTE_STR))
    . = ALIGN (4);
    REMOTE_STR_end = ABSOLUTE(.);
    _memmap_seg_fake_memory_end = ALIGN(0x8);
  } >fake_memory_seg :fake_memory_phdr


  _memmap_mem_sram_max = ABSOLUTE(.);

  .debug  0 :  { *(.debug) }
  .line  0 :  { *(.line) }
  .debug_srcinfo  0 :  { *(.debug_srcinfo) }
  .debug_sfnames  0 :  { *(.debug_sfnames) }
  .debug_aranges  0 :  { *(.debug_aranges) }
  .debug_pubnames  0 :  { *(.debug_pubnames) }
  .debug_info  0 :  { *(.debug_info) }
  .debug_abbrev  0 :  { *(.debug_abbrev) }
  .debug_line  0 :  { *(.debug_line) }
  .debug_frame  0 :  { *(.debug_frame) }
  .debug_str  0 :  { *(.debug_str) }
  .debug_loc  0 :  { *(.debug_loc) }
  .debug_macinfo  0 :  { *(.debug_macinfo) }
  .debug_weaknames  0 :  { *(.debug_weaknames) }
  .debug_funcnames  0 :  { *(.debug_funcnames) }
  .debug_typenames  0 :  { *(.debug_typenames) }
  .debug_varnames  0 :  { *(.debug_varnames) }
  .xt.insn 0 :
  {
    KEEP (*(.xt.insn))
    KEEP (*(.gnu.linkonce.x.*))
  }
  .xt.prop 0 :
  {
    KEEP (*(.xt.prop))
    KEEP (*(.xt.prop.*))
    KEEP (*(.gnu.linkonce.prop.*))
  }
  .xt.lit 0 :
  {
    KEEP (*(.xt.lit))
    KEEP (*(.xt.lit.*))
    KEEP (*(.gnu.linkonce.p.*))
  }
  .debug.xt.callgraph 0 :
  {
    KEEP (*(.debug.xt.callgraph .debug.xt.callgraph.* .gnu.linkonce.xt.callgraph.*))
  }
  .note.gnu.build-id 0 :
  {
    KEEP(*(.note.gnu.build-id))
  }
}

