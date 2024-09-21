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

#define GPIOA_ENABLE_MASK  ((0x01) << 2)
#define GPIOB_ENABLE_MASK  ((0x01) << 3)
#define USART1_ENABLE_MASK ((0x01) << 14)

typedef enum
{
    PRESCALER_NO_DIV = 0x01,
    PRESCALER_DIV_2  = 0x02,
    PRESCALER_DIV_4  = 0x03,
    PRESCALER_DIV_8  = 0x04,
    PRESCALER_DIV_16 = 0x05,
} E_APB1_PRESCALER_MODE;
#define RCC_APB1_PRESCALER_NO_DIV_MASK (0b000)
#define RCC_APB1_PRESCALER_DIV_2_MASK  (0b100)
#define RCC_APB1_PRESCALER_DIV_4_MASK  (0b101)
#define RCC_APB1_PRESCALER_DIV_8_MASK  (0b110)
#define RCC_APB1_PRESCALER_DIV_16_MASK (0b111)

typedef enum
{
    PLL_SRC_HSI_DIV_2 = 0x01,
    PLL_SRC_HSE       = 0x02,
} E_PLL_SOURCE_TYPE;

typedef enum
{
    PLL_MULTI_FACTOR_2  = 0x01,
    PLL_MULTI_FACTOR_3  = 0x02,
    PLL_MULTI_FACTOR_4  = 0x03,
    PLL_MULTI_FACTOR_5  = 0x04,
    PLL_MULTI_FACTOR_6  = 0x05,
    PLL_MULTI_FACTOR_7  = 0x06,
    PLL_MULTI_FACTOR_8  = 0x07,
    PLL_MULTI_FACTOR_9  = 0x08,
    PLL_MULTI_FACTOR_10 = 0x09,
    PLL_MULTI_FACTOR_11 = 0x0a,
    PLL_MULTI_FACTOR_12 = 0x0b,
    PLL_MULTI_FACTOR_13 = 0x0c,
    PLL_MULTI_FACTOR_14 = 0x0d,
    PLL_MULTI_FACTOR_15 = 0x0e,
    PLL_MULTI_FACTOR_16 = 0x0f,
} E_PLL_MULTIPLICATION_FACTOR;
#define PLL_MULTIPLICATION_FACTOR_2_MASK  (0b0000)
#define PLL_MULTIPLICATION_FACTOR_3_MASK  (0b0001)
#define PLL_MULTIPLICATION_FACTOR_4_MASK  (0b0010)
#define PLL_MULTIPLICATION_FACTOR_5_MASK  (0b0011)
#define PLL_MULTIPLICATION_FACTOR_6_MASK  (0b0100)
#define PLL_MULTIPLICATION_FACTOR_7_MASK  (0b0101)
#define PLL_MULTIPLICATION_FACTOR_8_MASK  (0b0110)
#define PLL_MULTIPLICATION_FACTOR_9_MASK  (0b0111)
#define PLL_MULTIPLICATION_FACTOR_10_MASK (0b1000)
#define PLL_MULTIPLICATION_FACTOR_11_MASK (0b1001)
#define PLL_MULTIPLICATION_FACTOR_12_MASK (0b1010)
#define PLL_MULTIPLICATION_FACTOR_13_MASK (0b1011)
#define PLL_MULTIPLICATION_FACTOR_14_MASK (0b1100)
#define PLL_MULTIPLICATION_FACTOR_15_MASK (0b1101)
#define PLL_MULTIPLICATION_FACTOR_16_MASK (0b1110)

typedef enum
{
    SYSCLK_FROM_HSI        = 0x01,
    SYSCLK_FROM_HSE        = 0x02,
    SYSCLK_FROM_PLL        = 0x03,
    SYSCLK_SRC_UNAVAILABLE = 0x04,
} E_SYSCLK_SRC_TYPE;
#define SYSCLK_SRC_FROM_HSI_MASK    (0b00)
#define SYSCLK_SRC_FROM_HSE_MASK    (0b01)
#define SYSCLK_SRC_FROM_PLL_MASK    (0b10)
#define SYSCLK_SRC_UNAVAILABLE_MASK (0b11)

void rcc_enable_ape2(uint32_t mask);

void rcc_set_apb1_prescaler(E_APB1_PRESCALER_MODE prescaler_mode);

void rcc_set_hse_on();

void rcc_block_wait_hse_ready();

void rcc_set_pll_src(E_PLL_SOURCE_TYPE type);

void rcc_set_pll_multi_factor(E_PLL_MULTIPLICATION_FACTOR factor);

void rcc_set_pll_enable();

void rcc_block_wait_pll_ready();

void rcc_set_sysclk_src(E_SYSCLK_SRC_TYPE src_type);

void rcc_block_wait_sysclk_sts_pll();

#endif //_STM32F103C8T6_RCC_INCLUDE_