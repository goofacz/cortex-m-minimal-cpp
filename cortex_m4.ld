/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

ENTRY(interrupt_reset)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x0000000, LENGTH = 0x80000
    STACK (rw): ORIGIN = 0x20004FFC, LENGTH = 0K
    RAM (rw) : ORIGIN = 0x20000000, LENGTH = 0x10000
}
 
SECTIONS
{
    .text :
    {
        KEEP(*(.vector_table))
        *(.text)
        *(.text.*)
        KEEP(*(.text.__cxa_guard_acquire))
        KEEP(*(.text.__cxa_guard_release))
        KEEP(*(.text.__aeabi_atexit))
    } >FLASH
    
    .rodata :
    {
        *(.rodata.*)
        _INIT_ARRAY_BEGIN = .;
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array))
        _INIT_ARRAY_END = .;
    } >FLASH

    .data_flash_begin :
    {
        _DATA_FLASH_BEGIN = .;
    } >FLASH

    .data :
    {
        _DATA_RAM_BEGIN = .;
        *(.data.*)
        _DATA_RAM_END = .;
    } >RAM AT >FLASH

    .data_flash_end :
    {
        _DATA_FLASH_END = .;
    } >FLASH
   
    .bss :
    {
        _BSS_BEGIN = .;
        *(.bss.*)
        KEEP(*(.bss.__dso_handle))
        _BSS_END = .;
    } >RAM

    .stack :
    {
        _STACK_HEAD = .;
    } >STACK
}  
