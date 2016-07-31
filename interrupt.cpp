/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <stdint.h>

typedef void (* init_array_function) (void);

extern const uint32_t _BSS_BEGIN;
extern const uint32_t _BSS_END;
extern const uint32_t _DATA_FLASH_BEGIN;
extern const uint32_t _DATA_FLASH_END;
extern const uint32_t _DATA_RAM_BEGIN;
extern const uint32_t _DATA_RAM_END;
extern const init_array_function _INIT_ARRAY_BEGIN;
extern const init_array_function _INIT_ARRAY_END;

extern int main (void);

extern "C" 
{

static void initialize_bss_section (void)
{
    uint8_t* begin = (uint8_t*) &_BSS_BEGIN;
    uint8_t* end = (uint8_t*) &_BSS_END;

    for (uint8_t* bss_byte = begin; bss_byte < end; bss_byte++)    {
        *bss_byte = 0;
    }
}

static void initialize_data_section (void)
{
    uint8_t* begin = (uint8_t*) &_DATA_RAM_BEGIN;
    uint8_t* end = (uint8_t*) &_DATA_RAM_END;
    uint8_t* data_flash_byte = (uint8_t*) &_DATA_FLASH_BEGIN;

    for (uint8_t* data_ram_byte = begin; data_ram_byte < end; data_ram_byte++)
    {
        *data_ram_byte = *data_flash_byte;
        data_flash_byte++;
    }
}

static void initialize_init_array (void)
{    
    for (init_array_function function = _INIT_ARRAY_BEGIN; function < _INIT_ARRAY_END; function++)    {
        (*function) ();
    }
}

void interrupt_reset (void)
{
    initialize_bss_section ();
    initialize_data_section ();
    initialize_init_array ();

    main ();
    
    while (1)    {
        // ...
    }
}

void interrupt_nmi (void)
{
    while (1)    {
        // ...
    }
}

void interrupt_hard_fault (void)
{
    while (1)    {
        // ...
    }
}

void interrupt_memmanage (void)
{
    while (1)    {
        // ...
    }
}

void interrupt_bus_fault (void)
{
    while (1)    {
        // ...
    }
}

void interrupt_usage_fault (void)
{
    while (1)    {
        // ...
    }
}

void interrupt_reserved_0 (void)
{
    while (1)    {
        // ...
    }
}

void interrupt_reserved_1 (void)
{
    while (1)    {
        // ...
    }
}

void interrupt_reserved_2 (void)
{
    while (1)    {
        // ...
    }
}

void interrupt_reserved_3 (void)
{
    while (1)    {
        // ...
    }
}

void interrupt_svcall (void)
{
    while (1)    {
        // ...
    }
}

void interrupt_debug (void)
{
    while (1)    {
        // ...
    }
}


void interrupt_reserved_4 (void)
{
    while (1)    {
        // ...
    }
}

void interrupt_pendsv (void)
{
    while (1)    {
        // ...
    }
}

void interrupt_systick (void)
{
    while (1)    {
        // ...
    }
}

}
