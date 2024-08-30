#pragma once
#ifndef _STM32F103C8T6_USART_INCLUDE_
#define _STM32F103C8T6_USART_INCLUDE_
#include <stdint.h>
#include <stdbool.h>

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

#define USART_ENABLE_TRANSMITTER_MASK ((0x01) << 3)
#define USART_ENABLE_MASK             ((0x01) << 13)

void usart_set_baud_rate(SUsartControlBlock *ptr, uint32_t baud_rate,
                         uint32_t clk_freq);

void usart_enable_transmitter(SUsartControlBlock *ptr);

void usart_enable_usart(SUsartControlBlock *ptr);

bool usart_transmit_data_register_empty(SUsartControlBlock *ptr);

void usart_blocking_send_byte(SUsartControlBlock *ptr, uint8_t data);

void usart_blocking_send_string(SUsartControlBlock *ptr, char *str);

#endif //_STM32F103C8T6_USART_INCLUDE_