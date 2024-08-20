#include "mco.h"
#include "rcc.h"
#include "gpio.h"
#include <stdint.h>

#define RCC_BASE   0x40021000
#define RCC_CFGR   (*((volatile uint32_t *)(RCC_BASE + 0x04)))
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH  (*((volatile uint32_t *)(GPIOA_BASE + 0x04)))

void mco_init()
{
    GPIOA_CRH &= ~(0xF << 0);
    GPIOA_CRH |= (0xB << 0);
    RCC_CFGR &= ~(0x7 << 24);
    RCC_CFGR |= (0x4 << 24);
}