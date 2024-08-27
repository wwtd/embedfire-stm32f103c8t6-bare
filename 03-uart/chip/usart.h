#pragma once
#ifndef _STM32F103C8T6_USART_INCLUDE_
#define _STM32F103C8T6_USART_INCLUDE_
#include <stdint.h>

typedef struct _SUsartControlBlock
{
    uint32_t sr;
    uint32_t dr;
    uint32_t brr;
    uint32_t cr1;
    uint32_t cr2;
    uint32_t cr3;
    uint32_t gtpr;
} SUsartControlBlock;
#define USART1_CONTROL_BLOCK_ADDR ((SUsartControlBlock *)0x40013800)
#define USART2_CONTROL_BLOCK_ADDR ((SUsartControlBlock *)0x40004400)
#define USART3_CONTROL_BLOCK_ADDR ((SUsartControlBlock *)0x40004800)
#define UART4_CONTROL_BLOCK_ADDR  ((SUsartControlBlock *)0x40004C00)
#define UART5_CONTROL_BLOCK_ADDR  ((SUsartControlBlock *)0x40005000)

void usart_set_baud_rate(SUsartControlBlock *ptr, uint32_t baud_rate,
                         uint32_t clk_freq);

#endif //_STM32F103C8T6_USART_INCLUDE_