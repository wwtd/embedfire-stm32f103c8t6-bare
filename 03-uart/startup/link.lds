MEMORY
{
   flash(RX)  : ORIGIN = 0x08000000, LENGTH = 64K
   sram(WAIL) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
   .text : {
       *(.vectors*)
       *(.text*)
       *(.rodata*)
   } > flash

   .data : {
       _sdata = .;
       *(.data*)
       _edata = .;
   } > sram AT > flash

   .bss  : {
       __bss_start__ = .;
       _sbss = .;
       *(.bss*)
       *(COMMON)
       __bss_end__ = .;
       _ebss = .;
   } > sram

   .heap (NOLOAD) : {
       _sheap = .;
       . = ORIGIN(sram) + LENGTH(sram) - 4K;
       _eheap = .;
   } > sram

   .stack (NOLOAD) : {
       _sstack = .;
       . = ORIGIN(sram) + LENGTH(sram);
       _estack = .;
   } > sram
}
