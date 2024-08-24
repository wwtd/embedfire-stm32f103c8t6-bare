#pragma once
#ifndef _STM32F103C8T6_RCC_INCLUDE_
#define _STM32F103C8T6_RCC_INCLUDE_
#include <stdint.h>

// rcc related
/* The reset and clock control module */
typedef struct _SRccControlBlock
{
    volatile uint32_t cr;   /* 0 - clock control */
    volatile uint32_t cfg;  /* 4 - clock config */
    volatile uint32_t cir;  /* 8 - clock interrupt */
    volatile uint32_t apb2; /* c - peripheral reset */
    volatile uint32_t apb1; /* 10 - peripheral reset */
    volatile uint32_t ape3; /* 14 - peripheral enable */
    volatile uint32_t ape2; /* 18 - peripheral enable */
    volatile uint32_t ape1; /* 1c - peripheral enable */
    volatile uint32_t bdcr; /* 20 - xx */
    volatile uint32_t csr;  /* 24 - xx */
} SRccControlBlock;

#define RCC_CONTROL_BLOCK_ADDR ((SRccControlBlock *)0x40021000)

#define GPIOA_ENABLE_MASK ((0x01) << 2)
#define GPIOB_ENABLE_MASK ((0x01) << 3)

typedef enum {
    PRESCALER_NO_DIV = 0x01,
    PRESCALER_DIV_2 = 0x02,
    PRESCALER_DIV_4 = 0x03,
    PRESCALER_DIV_8 = 0x04,
    PRESCALER_DIV_16 = 0x05,
}E_APB1_PRESCALER_MODE;
#define RCC_APB1_PRESCALER_NO_DIV_MASK (0b000)
#define RCC_APB1_PRESCALER_DIV_2_MASK  (0b100)
#define RCC_APB1_PRESCALER_DIV_4_MASK  (0b101)
#define RCC_APB1_PRESCALER_DIV_8_MASK  (0b110)
#define RCC_APB1_PRESCALER_DIV_16_MASK (0b111)

void rcc_enable_ape2(uint32_t mask);

void rcc_set_apb1_prescaler(E_APB1_PRESCALER_MODE prescaler_mode);

void rcc_set_hse_on();

#endif //_STM32F103C8T6_RCC_INCLUDE_