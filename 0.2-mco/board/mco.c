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
    set_gpio_crl_crh(GPIOA_CTRL_BLOCK_ADDR, PA8, GPIO_CNF_AF_OUT_PUSH_PULL, GPIO_MODE_OUT_SPPED_50MHZ);

    RCC_CFGR &= ~(0x7 << 24);
    RCC_CFGR |= (0x4 << 24);
}