/* This linker script generated from xt-genldscripts.tpp for LSP /home/user/work/hp-trunk/cl6000lsp/bootrom/RI-2020.5/LX7_Denali/bootrom */
/* Linker Script for default link */
MEMORY
{
  iram0_0_seg :                        org = 0x40080000, len = 0x20000
  irom0_0_seg :                        org = 0x50000000, len = 0x2E0
  irom0_2_seg :                        org = 0x50000400, len = 0x178
  irom0_3_seg :                        org = 0x50000578, len = 0x4
  irom0_4_seg :                        org = 0x5000057C, len = 0x1C
  irom0_5_seg :                        org = 0x50000598, len = 0x4
  irom0_6_seg :                        org = 0x5000059C, len = 0x1C
  irom0_7_seg :                        org = 0x500005B8, len = 0x4
  irom0_8_seg :                        org = 0x500005BC, len = 0x1C
  irom0_9_seg :                        org = 0x500005D8, len = 0x44
  irom0_10_seg :                       org = 0x5000061C, len = 0x1C
  irom0_11_seg :                       org = 0x50000638, len = 0x4
  irom0_12_seg :                       org = 0x5000063C, len = 0x1C
  irom0_13_seg :                       org = 0x50000658, len = 0x4
  irom0_14_seg :                       org = 0x5000065C, len = 0x1C
  irom0_15_seg :                       org = 0x50000678, len = 0x4
  irom0_16_seg :                       org = 0x5000067C, len = 0x1C
  irom0_17_seg :                       org = 0x50000698, len = 0xF968
  SHAREDRAM_seg :                      org = 0x60000000, len = 0x40000
  BLSHAREDRAM_seg :                    org = 0x60040000, len = 0x10000
  BLPOSTMORTEM_seg :                   org = 0x60050000, len = 0x10000
  fake_memory_seg :                    org = 0x70000000, len = 0x100000
}

PHDRS
{
  dram0_0_phdr PT_LOAD;
  iram0_0_phdr PT_LOAD;
  irom0_0_phdr PT_LOAD;
  irom0_1_phdr PT_LOAD;
  irom0_2_phdr PT_LOAD;
  irom0_3_phdr PT_LOAD;
  irom0_4_phdr PT_LOAD;
  irom0_5_phdr PT_LOAD;
  irom0_6_phdr PT_LOAD;
  irom0_7_phdr PT_LOAD;
  irom0_8_phdr PT_LOAD;
  irom0_9_phdr PT_LOAD;
  irom0_10_phdr PT_LOAD;
  irom0_11_phdr PT_LOAD;
  irom0_12_phdr PT_LOAD;
  irom0_13_phdr PT_LOAD;
  irom0_14_phdr PT_LOAD;
  irom0_15_phdr PT_LOAD;
  irom0_16_phdr PT_LOAD;
  irom0_17_phdr PT_LOAD;
  SHAREDRAM_phdr PT_LOAD;
  SHAREDRAM_bss_phdr PT_LOAD;
  BLSHAREDRAM_phdr PT_LOAD;
  BLSHAREDRAM_bss_phdr PT_LOAD;
  BLPOSTMORTEM_phdr PT_LOAD;
  fake_memory_phdr PT_LOAD;
}


/*  Default entry point:  */
ENTRY(_ResetVector)


/*  Memory boundary addresses:  */
_memmap_mem_dram0_start = 0x40000000;
_memmap_mem_dram0_end   = 0x40040000;
_memmap_mem_dram1_start = 0x40040000;
_memmap_mem_dram1_end   = 0x40080000;
_memmap_mem_iram0_start = 0x40080000;
_memmap_mem_iram0_end   = 0x400c0000;
_memmap_mem_irom0_start = 0x50000000;
_memmap_mem_irom0_end   = 0x50100000;
_memmap_mem_sram_start = 0x60000000;
_memmap_mem_sram_end   = 0xe0000000;

/*  Memory segment boundary addresses:  */
_memmap_seg_iram0_0_start = 0x40080000;
_memmap_seg_iram0_0_max   = 0x400a0000;
_memmap_seg_irom0_0_start = 0x50000000;
_memmap_seg_irom0_0_max   = 0x500002e0;
_memmap_seg_irom0_2_start = 0x50000400;
_memmap_seg_irom0_2_max   = 0x50000578;
_memmap_seg_irom0_3_start = 0x50000578;
_memmap_seg_irom0_3_max   = 0x5000057c;
_memmap_seg_irom0_4_start = 0x5000057c;
_memmap_seg_irom0_4_max   = 0x50000598;
_memmap_seg_irom0_5_start = 0x50000598;
_memmap_seg_irom0_5_max   = 0x5000059c;
_memmap_seg_irom0_6_start = 0x5000059c;
_memmap_seg_irom0_6_max   = 0x500005b8;
_memmap_seg_irom0_7_start = 0x500005b8;
_memmap_seg_irom0_7_max   = 0x500005bc;
_memmap_seg_irom0_8_start = 0x500005bc;
_memmap_seg_irom0_8_max   = 0x500005d8;
_memmap_seg_irom0_9_start = 0x500005d8;
_memmap_seg_irom0_9_max   = 0x5000061c;
_memmap_seg_irom0_10_start = 0x5000061c;
_memmap_seg_irom0_10_max   = 0x50000638;
_memmap_seg_irom0_11_start = 0x50000638;
_memmap_seg_irom0_11_max   = 0x5000063c;
_memmap_seg_irom0_12_start = 0x5000063c;
_memmap_seg_irom0_12_max   = 0x50000658;
_memmap_seg_irom0_13_start = 0x50000658;
_memmap_seg_irom0_13_max   = 0x5000065c;
_memmap_seg_irom0_14_start = 0x5000065c;
_memmap_seg_irom0_14_max   = 0x50000678;
_memmap_seg_irom0_15_start = 0x50000678;
_memmap_seg_irom0_15_max   = 0x5000067c;
_memmap_seg_irom0_16_start = 0x5000067c;
_memmap_seg_irom0_16_max   = 0x50000698;
_memmap_seg_irom0_17_start = 0x50000698;
_memmap_seg_irom0_17_max   = 0x50010000;
_memmap_seg_SHAREDRAM_start = 0x60000000;
_memmap_seg_SHAREDRAM_max   = 0x60040000;
_memmap_seg_BLSHAREDRAM_start = 0x60040000;
_memmap_seg_BLSHAREDRAM_max   = 0x60050000;
_memmap_seg_BLPOSTMORTEM_start = 0x60050000;
_memmap_seg_BLPOSTMORTEM_max   = 0x60060000;
_memmap_seg_fake_memory_start = 0x70000000;
_memmap_seg_fake_memory_max   = 0x70100000;

PROVIDE(_memmap_reset_vector = 0x50000000);
PROVIDE(_memmap_vecbase_reset = 0x50000400);
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

  .irom0.text : ALIGN(4)
  {
    _irom0_text_start = ABSOLUTE(.);
    *(.irom0.literal .irom.literal .irom.text.literal .irom0.text .irom.text)
    . = ALIGN (4);
    _irom0_text_end = ABSOLUTE(.);
  } >irom0_17_seg :irom0_17_phdr

  .clib.text : ALIGN(4)
  {
    _clib_text_start = ABSOLUTE(.);
    *(.clib.literal .clib.text)
    . = ALIGN (4);
    _clib_text_end = ABSOLUTE(.);
  } >irom0_17_seg :irom0_17_phdr

  .rtos.text : ALIGN(4)
  {
    _rtos_text_start = ABSOLUTE(.);
    *(.rtos.literal .rtos.text)
    . = ALIGN (4);
    _rtos_text_end = ABSOLUTE(.);
  } >irom0_17_seg :irom0_17_phdr

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
    . = ALIGN(4);
    _rom_store_table = .;
    LONG(_iram0_text_start);
    LONG(_iram0_text_end);
    LONG(LOADADDR(.iram0.text));
    LONG(_sram_rodata_start);
    LONG(_sram_rodata_end);
    LONG(LOADADDR(.sram.rodata));
    LONG(_sram_text_start);
    LONG(_sram_text_end);
    LONG(LOADADDR(.sram.text));
    LONG(_sram_data_start);
    LONG(_sram_data_end);
    LONG(LOADADDR(.sram.data));
    LONG(__llvm_prf_names_start);
    LONG(__llvm_prf_names_end);
    LONG(LOADADDR(__llvm_prf_names));
    LONG(_dram0_rodata_start);
    LONG(_dram0_rodata_end);
    LONG(LOADADDR(.dram0.rodata));
    LONG(_clib_rodata_start);
    LONG(_clib_rodata_end);
    LONG(LOADADDR(.clib.rodata));
    LONG(_rtos_rodata_start);
    LONG(_rtos_rodata_end);
    LONG(LOADADDR(.rtos.rodata));
    LONG(_rodata_start);
    LONG(_rodata_end);
    LONG(LOADADDR(.rodata));
    LONG(_clib_data_start);
    LONG(_clib_data_end);
    LONG(LOADADDR(.clib.data));
    LONG(_clib_percpu_data_start);
    LONG(_clib_percpu_data_end);
    LONG(LOADADDR(.clib.percpu.data));
    LONG(_rtos_percpu_data_start);
    LONG(_rtos_percpu_data_end);
    LONG(LOADADDR(.rtos.percpu.data));
    LONG(_rtos_data_start);
    LONG(_rtos_data_end);
    LONG(LOADADDR(.rtos.data));
    LONG(_dram0_data_start);
    LONG(_dram0_data_end);
    LONG(LOADADDR(.dram0.data));
    LONG(_data_start);
    LONG(_data_end);
    LONG(LOADADDR(.data));
    LONG(0);
    LONG(0);
    LONG(0);
    _rom_store = .;
    . = ALIGN (4);
    _text_end = ABSOLUTE(.);
    _etext = .;
  } >irom0_17_seg :irom0_17_phdr

  _memmap_mem_irom0_max = ABSOLUTE(.);

  _memmap_mem_dram0_max = ABSOLUTE(.);

  .iram0.text : AT(LOADADDR(.text) + ((SIZEOF(.text) + 3) & 0xFFFFFFFC)) ALIGN(4)
  {
    _iram0_text_start = ABSOLUTE(.);
    *(.iram0.literal .iram.literal .iram.text.literal .iram0.text .iram.text)
    . = ALIGN (4);
    _iram0_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_0_end = ALIGN(0x8);
  } >iram0_0_seg :iram0_0_phdr

  _memmap_mem_iram0_max = ABSOLUTE(.);

  .ResetVector.text : ALIGN(4)
  {
    _ResetVector_text_start = ABSOLUTE(.);
    KEEP (*(.ResetVector.text))
    . = ALIGN (4);
    _ResetVector_text_end = ABSOLUTE(.);
  } >irom0_0_seg :irom0_0_phdr

  .ResetHandler.text : ALIGN(4)
  {
    _ResetHandler_text_start = ABSOLUTE(.);
    *(.ResetHandler.literal .ResetHandler.text)
    . = ALIGN (4);
    _ResetHandler_text_end = ABSOLUTE(.);
    _memmap_seg_irom0_0_end = ALIGN(0x8);
  } >irom0_0_seg :irom0_0_phdr



  .WindowVectors.text : ALIGN(4)
  {
    _WindowVectors_text_start = ABSOLUTE(.);
    KEEP (*(.WindowVectors.text))
    . = ALIGN (4);
    _WindowVectors_text_end = ABSOLUTE(.);
    _memmap_seg_irom0_2_end = ALIGN(0x8);
  } >irom0_2_seg :irom0_2_phdr


  .Level2InterruptVector.literal : ALIGN(4)
  {
    _Level2InterruptVector_literal_start = ABSOLUTE(.);
    *(.Level2InterruptVector.literal)
    . = ALIGN (4);
    _Level2InterruptVector_literal_end = ABSOLUTE(.);
    _memmap_seg_irom0_3_end = ALIGN(0x8);
  } >irom0_3_seg :irom0_3_phdr


  .Level2InterruptVector.text : ALIGN(4)
  {
    _Level2InterruptVector_text_start = ABSOLUTE(.);
    KEEP (*(.Level2InterruptVector.text))
    . = ALIGN (4);
    _Level2InterruptVector_text_end = ABSOLUTE(.);
    _memmap_seg_irom0_4_end = ALIGN(0x8);
  } >irom0_4_seg :irom0_4_phdr


  .Level3InterruptVector.literal : ALIGN(4)
  {
    _Level3InterruptVector_literal_start = ABSOLUTE(.);
    *(.Level3InterruptVector.literal)
    . = ALIGN (4);
    _Level3InterruptVector_literal_end = ABSOLUTE(.);
    _memmap_seg_irom0_5_end = ALIGN(0x8);
  } >irom0_5_seg :irom0_5_phdr


  .Level3InterruptVector.text : ALIGN(4)
  {
    _Level3InterruptVector_text_start = ABSOLUTE(.);
    KEEP (*(.Level3InterruptVector.text))
    . = ALIGN (4);
    _Level3InterruptVector_text_end = ABSOLUTE(.);
    _memmap_seg_irom0_6_end = ALIGN(0x8);
  } >irom0_6_seg :irom0_6_phdr


  .DebugExceptionVector.literal : ALIGN(4)
  {
    _DebugExceptionVector_literal_start = ABSOLUTE(.);
    *(.DebugExceptionVector.literal)
    . = ALIGN (4);
    _DebugExceptionVector_literal_end = ABSOLUTE(.);
    _memmap_seg_irom0_7_end = ALIGN(0x8);
  } >irom0_7_seg :irom0_7_phdr


  .DebugExceptionVector.text : ALIGN(4)
  {
    _DebugExceptionVector_text_start = ABSOLUTE(.);
    KEEP (*(.DebugExceptionVector.text))
    . = ALIGN (4);
    _DebugExceptionVector_text_end = ABSOLUTE(.);
    _memmap_seg_irom0_8_end = ALIGN(0x8);
  } >irom0_8_seg :irom0_8_phdr


  .NMIExceptionVector.literal : ALIGN(4)
  {
    _NMIExceptionVector_literal_start = ABSOLUTE(.);
    *(.NMIExceptionVector.literal)
    . = ALIGN (4);
    _NMIExceptionVector_literal_end = ABSOLUTE(.);
    _memmap_seg_irom0_9_end = ALIGN(0x8);
  } >irom0_9_seg :irom0_9_phdr


  .NMIExceptionVector.text : ALIGN(4)
  {
    _NMIExceptionVector_text_start = ABSOLUTE(.);
    KEEP (*(.NMIExceptionVector.text))
    . = ALIGN (4);
    _NMIExceptionVector_text_end = ABSOLUTE(.);
    _memmap_seg_irom0_10_end = ALIGN(0x8);
  } >irom0_10_seg :irom0_10_phdr


  .KernelExceptionVector.literal : ALIGN(4)
  {
    _KernelExceptionVector_literal_start = ABSOLUTE(.);
    *(.KernelExceptionVector.literal)
    . = ALIGN (4);
    _KernelExceptionVector_literal_end = ABSOLUTE(.);
    _memmap_seg_irom0_11_end = ALIGN(0x8);
  } >irom0_11_seg :irom0_11_phdr


  .KernelExceptionVector.text : ALIGN(4)
  {
    _KernelExceptionVector_text_start = ABSOLUTE(.);
    KEEP (*(.KernelExceptionVector.text))
    . = ALIGN (4);
    _KernelExceptionVector_text_end = ABSOLUTE(.);
    _memmap_seg_irom0_12_end = ALIGN(0x8);
  } >irom0_12_seg :irom0_12_phdr


  .UserExceptionVector.literal : ALIGN(4)
  {
    _UserExceptionVector_literal_start = ABSOLUTE(.);
    *(.UserExceptionVector.literal)
    . = ALIGN (4);
    _UserExceptionVector_literal_end = ABSOLUTE(.);
    _memmap_seg_irom0_13_end = ALIGN(0x8);
  } >irom0_13_seg :irom0_13_phdr


  .UserExceptionVector.text : ALIGN(4)
  {
    _UserExceptionVector_text_start = ABSOLUTE(.);
    KEEP (*(.UserExceptionVector.text))
    . = ALIGN (4);
    _UserExceptionVector_text_end = ABSOLUTE(.);
    _memmap_seg_irom0_14_end = ALIGN(0x8);
  } >irom0_14_seg :irom0_14_phdr


  .DoubleExceptionVector.literal : ALIGN(4)
  {
    _DoubleExceptionVector_literal_start = ABSOLUTE(.);
    *(.DoubleExceptionVector.literal)
    . = ALIGN (4);
    _DoubleExceptionVector_literal_end = ABSOLUTE(.);
    _memmap_seg_irom0_15_end = ALIGN(0x8);
  } >irom0_15_seg :irom0_15_phdr


  .DoubleExceptionVector.text : ALIGN(4)
  {
    _DoubleExceptionVector_text_start = ABSOLUTE(.);
    KEEP (*(.DoubleExceptionVector.text))
    . = ALIGN (4);
    _DoubleExceptionVector_text_end = ABSOLUTE(.);
    _memmap_seg_irom0_16_end = ALIGN(0x8);
  } >irom0_16_seg :irom0_16_phdr

  _memmap_mem_irom0_max = ABSOLUTE(.);

  .sram.rodata : AT(LOADADDR(.iram0.text) + ((SIZEOF(.iram0.text) + 3) & 0xFFFFFFFC)) ALIGN(4)
  {
    _sram_rodata_start = ABSOLUTE(.);
    *(.sram.rodata)
    . = ALIGN (4);
    _sram_rodata_end = ABSOLUTE(.);
  } >SHAREDRAM_seg :SHAREDRAM_phdr

  .sram.text : AT(LOADADDR(.sram.rodata) + (ADDR(.sram.text) - ADDR(.sram.rodata))) ALIGN(4)
  {
    _sram_text_start = ABSOLUTE(.);
    *(.sram.literal .sram.text)
    . = ALIGN (4);
    _sram_text_end = ABSOLUTE(.);
  } >SHAREDRAM_seg :SHAREDRAM_phdr

  .sram.data : AT(LOADADDR(.sram.text) + (ADDR(.sram.data) - ADDR(.sram.text))) ALIGN(4)
  {
    _sram_data_start = ABSOLUTE(.);
    *(.sram.data)
    . = ALIGN (4);
    _sram_data_end = ABSOLUTE(.);
  } >SHAREDRAM_seg :SHAREDRAM_phdr

  __llvm_prf_names : AT(LOADADDR(.sram.data) + (ADDR(__llvm_prf_names) - ADDR(.sram.data))) ALIGN(4)
  {
    __llvm_prf_names_start = ABSOLUTE(.);
    *(__llvm_prf_names)
    . = ALIGN (4);
    __llvm_prf_names_end = ABSOLUTE(.);
  } >SHAREDRAM_seg :SHAREDRAM_phdr

  .sram.bss (NOLOAD) : ALIGN(8)
  {
    . = ALIGN (8);
    _sram_bss_start = ABSOLUTE(.);
    *(.sram.bss)
    . = ALIGN (8);
    _sram_bss_end = ABSOLUTE(.);
    _memmap_seg_SHAREDRAM_end = ALIGN(0x8);
  } >SHAREDRAM_seg :SHAREDRAM_bss_phdr


  .dram0.rodata : AT(LOADADDR(__llvm_prf_names) + ((SIZEOF(__llvm_prf_names) + 3) & 0xFFFFFFFC)) ALIGN(4)
  {
    _dram0_rodata_start = ABSOLUTE(.);
    *(.dram0.rodata)
    *(.dram.rodata)
    . = ALIGN (4);
    _dram0_rodata_end = ABSOLUTE(.);
  } >BLSHAREDRAM_seg :BLSHAREDRAM_phdr

  .clib.rodata : AT(LOADADDR(.dram0.rodata) + (ADDR(.clib.rodata) - ADDR(.dram0.rodata))) ALIGN(4)
  {
    _clib_rodata_start = ABSOLUTE(.);
    *(.clib.rodata)
    . = ALIGN (4);
    _clib_rodata_end = ABSOLUTE(.);
  } >BLSHAREDRAM_seg :BLSHAREDRAM_phdr

  .rtos.rodata : AT(LOADADDR(.clib.rodata) + (ADDR(.rtos.rodata) - ADDR(.clib.rodata))) ALIGN(4)
  {
    _rtos_rodata_start = ABSOLUTE(.);
    *(.rtos.rodata)
    . = ALIGN (4);
    _rtos_rodata_end = ABSOLUTE(.);
  } >BLSHAREDRAM_seg :BLSHAREDRAM_phdr

  .rodata : AT(LOADADDR(.rtos.rodata) + (ADDR(.rodata) - ADDR(.rtos.rodata))) ALIGN(4)
  {
    _rodata_start = ABSOLUTE(.);
    *(.rodata)
    *(SORT(.rodata.sort.*))
    KEEP (*(SORT(.rodata.keepsort.*) .rodata.keep.*))
    *(.rodata.*)
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
    . = ALIGN(4);  /* this table MUST be 4-byte aligned */
    _bss_table_start = ABSOLUTE(.);
    LONG(_sram_bss_start)
    LONG(_sram_bss_end)
    LONG(_bss_start)
    LONG(_bss_end)
    _bss_table_end = ABSOLUTE(.);
    . = ALIGN (4);
    _rodata_end = ABSOLUTE(.);
  } >BLSHAREDRAM_seg :BLSHAREDRAM_phdr

  .clib.data : AT(LOADADDR(.rodata) + (ADDR(.clib.data) - ADDR(.rodata))) ALIGN(4)
  {
    _clib_data_start = ABSOLUTE(.);
    *(.clib.data)
    . = ALIGN (4);
    _clib_data_end = ABSOLUTE(.);
  } >BLSHAREDRAM_seg :BLSHAREDRAM_phdr

  .clib.percpu.data : AT(LOADADDR(.clib.data) + (ADDR(.clib.percpu.data) - ADDR(.clib.data))) ALIGN(4)
  {
    _clib_percpu_data_start = ABSOLUTE(.);
    *(.clib.percpu.data)
    . = ALIGN (4);
    _clib_percpu_data_end = ABSOLUTE(.);
  } >BLSHAREDRAM_seg :BLSHAREDRAM_phdr

  .rtos.percpu.data : AT(LOADADDR(.clib.percpu.data) + (ADDR(.rtos.percpu.data) - ADDR(.clib.percpu.data))) ALIGN(4)
  {
    _rtos_percpu_data_start = ABSOLUTE(.);
    *(.rtos.percpu.data)
    . = ALIGN (4);
    _rtos_percpu_data_end = ABSOLUTE(.);
  } >BLSHAREDRAM_seg :BLSHAREDRAM_phdr

  .rtos.data : AT(LOADADDR(.rtos.percpu.data) + (ADDR(.rtos.data) - ADDR(.rtos.percpu.data))) ALIGN(4)
  {
    _rtos_data_start = ABSOLUTE(.);
    *(.rtos.data)
    . = ALIGN (4);
    _rtos_data_end = ABSOLUTE(.);
  } >BLSHAREDRAM_seg :BLSHAREDRAM_phdr

  .dram0.data : AT(LOADADDR(.rtos.data) + (ADDR(.dram0.data) - ADDR(.rtos.data))) ALIGN(4)
  {
    _dram0_data_start = ABSOLUTE(.);
    *(.dram0.data)
    *(.dram.data)
    . = ALIGN (4);
    _dram0_data_end = ABSOLUTE(.);
  } >BLSHAREDRAM_seg :BLSHAREDRAM_phdr

  .data : AT(LOADADDR(.dram0.data) + (ADDR(.data) - ADDR(.dram0.data))) ALIGN(4)
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
  } >BLSHAREDRAM_seg :BLSHAREDRAM_phdr

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
    *(.bss)
    *(SORT(.bss.sort.*))
    KEEP (*(SORT(.bss.keepsort.*) .bss.keep.*))
    *(.bss.*)
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
    _memmap_seg_BLSHAREDRAM_end = ALIGN(0x8);
  } >BLSHAREDRAM_seg :BLSHAREDRAM_bss_phdr

  PROVIDE(__stack = 0x60050000);
  _heap_sentry = 0x60050000;

  REMOTE_STR : AT(LOADADDR(.data ) + ((SIZEOF(.data) + 3) & 0xFFFFFFFC))  ALIGN(4)
  {
    REMOTE_STR_start = ABSOLUTE(.);
    KEEP (*(rodata.offload))
    KEEP (*(REMOTE_STR))
    . = ALIGN (4);
    REMOTE_STR_end = ABSOLUTE(.);
    _memmap_seg_fake_memory_end = ALIGN(0x8);
  } >fake_memory_seg :fake_memory_phdr

  _memmap_mem_sram_max = ABSOLUTE(.);


  _memmap_mem_irom0_max = ABSOLUTE(.);

  .rom_store_end LOADADDR(.data) + SIZEOF(.data) : 
  { 
    _rom_store_end = .;
    ASSERT(LOADADDR(.data) + SIZEOF(.data) <= _memmap_seg_irom0_17_max, "Insufficient ROM space"); 
  } >irom0_17_seg
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

