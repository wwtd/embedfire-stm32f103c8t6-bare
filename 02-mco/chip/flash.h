#pragma once
#ifndef _STM32F103C8T6_FLASH_INCLUDE_
#define _STM32F103C8T6_FLASH_INCLUDE_
#include "stdint.h"

// flash related
typedef struct _SFlashControlBlock
{
    uint32_t acr;
    uint32_t keyr;
    uint32_t optkeyr;
    uint32_t sr;
    uint32_t cr;
    uint32_t ar;
    uint32_t reserve;
    uint32_t obr;
    uint32_t wrpr;
} SFlashControlBlock;

#define FLASH_CTRL_BLOCK_ADDR ((SFlashControlBlock *)0x40022000)

typedef enum
{
    ZERO_WAIT_STATE = 0x1,
    ONE_WAIT_STATE  = 0x2,
    TWO_WAIT_STATE  = 0x3,
} E_FLASH_LATENCY_TYPE;

#define FLASH_ZERO_WAIT_STATE_MASK (0b000)
#define FLASH_ONE_WAIT_STATE_MASK  (0b001)
#define FLASH_TWO_WAIT_STATE_MASK  (0b010)

void flash_set_latency(E_FLASH_LATENCY_TYPE latency_type);

#endif //_STM32F103C8T6_FLASH_INCLUDE_