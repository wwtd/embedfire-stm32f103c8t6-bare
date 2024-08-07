#pragma once
#ifndef _STM32F103C8T6_RCC_INCLUDE_
#define _STM32F103C8T6_RCC_INCLUDE_
#include <stdint.h>

// rcc related
/* The reset and clock control module */
typedef struct _SRccControlBlock
{
    volatile uint32_t rc;   /* 0 - clock control */
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

#define RCC_CONTROL_BLOCK_ADDR (SRccControlBlock *)0x40021000
#define GPIOA_ENABLE_MASK      ((0x01) << 2)

#endif //_STM32F103C8T6_RCC_INCLUDE_