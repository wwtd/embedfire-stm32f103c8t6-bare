#pragma once
#ifndef _BOARD_INCLUDE_MCO_H_
#define _BOARD_INCLUDE_MCO_H_

typedef enum
{
    NO_CLOCK_OUTPUT = 0x1,
    SYSCLK_OUTPUT   = 0x2,
    HSI_OUTPUT      = 0x3,
    HSE_OUTPUT      = 0x4,
    HALF_PLL_OUTPUT = 0x5,
} E_MCO_OUTPUT_MODE;

#define MCO_NO_OUTPUT_MASK       (0b000)
#define MCO_SYSCLK_OUTPUT_MASK   (0b100)
#define MCO_HSI_OUTPUT_MASK      (0b101)
#define MCO_HSE_OUTPUT_MASK      (0b110)
#define MCO_HALF_PLL_OUTPUT_MASK (0b111)

void mco_init();

void mco_select_mode(E_MCO_OUTPUT_MODE output_mode);

#endif //_BOARD_INCLUDE_MCO_H_