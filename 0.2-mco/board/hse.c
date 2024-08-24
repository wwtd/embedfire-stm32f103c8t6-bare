#include "hse.h"
#include "chip.h"
#include "rcc.h"

void hse_init()
{
    flash_set_latency(TWO_WAIT_STATE);
    rcc_set_apb1_prescaler(PRESCALER_DIV_2);
    rcc_set_hse_on();

    // Wait until HSE is ready (RCC_CR_HSERDY)
    while (!(*(volatile uint32_t *)(0x40021000) & (1 << 17))); // RCC->CR: address 0x40021000, HSERDY bit at position 17

    // Set PLL source to HSE (RCC_CFGR_PLLSRC)
    *(volatile uint32_t *)(0x40021004) |= (1 << 16); // RCC->CFGR: address 0x40021004, PLLSRC bit at position 16

    // Set PLL multiplication factor to 9 (RCC_CFGR_PLLMULL9)
    *(volatile uint32_t *)(0x40021004) |= (0x7 << 18); // RCC->CFGR: address 0x40021004, PLLMUL bits at position 18

    // Enable the PLL (RCC_CR_PLLON)
    *(volatile uint32_t *)(0x40021000) |= (1 << 24); // RCC->CR: address 0x40021000, PLLON bit at position 24

    // Wait until PLL is ready (RCC_CR_PLLRDY)
    while (!(*(volatile uint32_t *)(0x40021000) & (1 << 25))); // RCC->CR: address 0x40021000, PLLRDY bit at position 25

    // Set system clock source to PLL (RCC_CFGR_SW_PLL)
    *(volatile uint32_t *)(0x40021004) |= (0x2 << 0); // RCC->CFGR: address 0x40021004, SW bits at position 0

    // Wait until PLL is used as the system clock (RCC_CFGR_SWS_PLL)
    while ((*(volatile uint32_t *)(0x40021004) & (0x3 << 2)) != (0x2 << 2)); // RCC->CFGR: address 0x40021004, SWS bits at position 2
}