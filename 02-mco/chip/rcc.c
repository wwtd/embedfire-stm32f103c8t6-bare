#include "rcc.h"
#include <stdint.h>

void rcc_enable_ape2(uint32_t mask)
{
    SRccControlBlock *rcc_prt = RCC_CONTROL_BLOCK_ADDR;
    rcc_prt->ape2 |= mask;
    return;
}

void rcc_set_apb1_prescaler(E_APB1_PRESCALER_MODE prescaler_mode)
{
    SRccControlBlock *rcc_prt = RCC_CONTROL_BLOCK_ADDR;
    rcc_prt->cfg &= ~(0b111 << 8);
    switch (prescaler_mode)
    {
        case PRESCALER_NO_DIV: {
            rcc_prt->cfg |= RCC_APB1_PRESCALER_NO_DIV_MASK;
            break;
        }
        case PRESCALER_DIV_2: {
            rcc_prt->cfg |= RCC_APB1_PRESCALER_DIV_2_MASK;
            break;
        }
        case PRESCALER_DIV_4: {
            rcc_prt->cfg |= RCC_APB1_PRESCALER_DIV_4_MASK;
            break;
        }
        case PRESCALER_DIV_8: {
            rcc_prt->cfg |= RCC_APB1_PRESCALER_DIV_8_MASK;
            break;
        }
        case PRESCALER_DIV_16: {
            rcc_prt->cfg |= RCC_APB1_PRESCALER_DIV_16_MASK;
            break;
        }
        default:
            break;
    }
}

void rcc_set_hse_on()
{
    SRccControlBlock *rcc_prt = RCC_CONTROL_BLOCK_ADDR;
    rcc_prt->cr |= (1 << 16);
}

void rcc_block_wait_hse_ready()
{
    SRccControlBlock *rcc_prt = RCC_CONTROL_BLOCK_ADDR;
    while (((rcc_prt->cr) & (1 << 17)) == 0)
    {
    }
}

void rcc_set_pll_src(E_PLL_SOURCE_TYPE type)
{
    SRccControlBlock *rcc_prt = RCC_CONTROL_BLOCK_ADDR;
    rcc_prt->cfg &= ~(1 << 16);
    switch (type)
    {
        case PLL_SRC_HSI_DIV_2: {
            // do nothing
            break;
        }
        case PLL_SRC_HSE: {
            rcc_prt->cfg |= (1 << 16);
            break;
        }
        default:
            break;
    }
}

void rcc_set_pll_multi_factor(E_PLL_MULTIPLICATION_FACTOR factor)
{
    SRccControlBlock *rcc_prt = RCC_CONTROL_BLOCK_ADDR;
    rcc_prt->cfg &= ~(0b1111 << 18);
    switch (factor)
    {
        case PLL_MULTI_FACTOR_2: {
            rcc_prt->cfg |= (PLL_MULTIPLICATION_FACTOR_2_MASK << 18);
            break;
        }
        case PLL_MULTI_FACTOR_3: {
            rcc_prt->cfg |= (PLL_MULTIPLICATION_FACTOR_3_MASK << 18);
            break;
        }
        case PLL_MULTI_FACTOR_4: {
            rcc_prt->cfg |= (PLL_MULTIPLICATION_FACTOR_4_MASK << 18);
            break;
        }
        case PLL_MULTI_FACTOR_5: {
            rcc_prt->cfg |= (PLL_MULTIPLICATION_FACTOR_5_MASK << 18);
            break;
        }
        case PLL_MULTI_FACTOR_6: {
            rcc_prt->cfg |= (PLL_MULTIPLICATION_FACTOR_6_MASK << 18);
            break;
        }
        case PLL_MULTI_FACTOR_7: {
            rcc_prt->cfg |= (PLL_MULTIPLICATION_FACTOR_7_MASK << 18);
            break;
        }
        case PLL_MULTI_FACTOR_8: {
            rcc_prt->cfg |= (PLL_MULTIPLICATION_FACTOR_8_MASK << 18);
            break;
        }
        case PLL_MULTI_FACTOR_9: {
            rcc_prt->cfg |= (PLL_MULTIPLICATION_FACTOR_9_MASK << 18);
            break;
        }
        case PLL_MULTI_FACTOR_10: {
            rcc_prt->cfg |= (PLL_MULTIPLICATION_FACTOR_10_MASK << 18);
            break;
        }
        case PLL_MULTI_FACTOR_11: {
            rcc_prt->cfg |= (PLL_MULTIPLICATION_FACTOR_11_MASK << 18);
            break;
        }
        case PLL_MULTI_FACTOR_12: {
            rcc_prt->cfg |= (PLL_MULTIPLICATION_FACTOR_12_MASK << 18);
            break;
        }
        case PLL_MULTI_FACTOR_13: {
            rcc_prt->cfg |= (PLL_MULTIPLICATION_FACTOR_13_MASK << 18);
            break;
        }
        case PLL_MULTI_FACTOR_14: {
            rcc_prt->cfg |= (PLL_MULTIPLICATION_FACTOR_14_MASK << 18);
            break;
        }
        case PLL_MULTI_FACTOR_15: {
            rcc_prt->cfg |= (PLL_MULTIPLICATION_FACTOR_15_MASK << 18);
            break;
        }
        case PLL_MULTI_FACTOR_16: {
            rcc_prt->cfg |= (PLL_MULTIPLICATION_FACTOR_16_MASK << 18);
            break;
        }
        default:
            break;
    }
}

void rcc_set_pll_enable()
{
    SRccControlBlock *rcc_prt = RCC_CONTROL_BLOCK_ADDR;
    rcc_prt->cr |= (1 << 24);
}

void rcc_block_wait_pll_ready()
{
    SRccControlBlock *rcc_prt = RCC_CONTROL_BLOCK_ADDR;
    while (((rcc_prt->cr) & (0x1 << 25)) == 0)
    {
    }
}

void rcc_set_sysclk_src(E_SYSCLK_SRC_TYPE src_type)
{
    SRccControlBlock *rcc_prt = RCC_CONTROL_BLOCK_ADDR;
    rcc_prt->cfg &= ~(0b11);
    switch (src_type)
    {
        case SYSCLK_FROM_HSI: {
            rcc_prt->cfg |= SYSCLK_SRC_FROM_HSI_MASK;
            break;
        }
        case SYSCLK_FROM_HSE: {
            rcc_prt->cfg |= SYSCLK_SRC_FROM_HSE_MASK;
            break;
        }
        case SYSCLK_FROM_PLL: {
            rcc_prt->cfg |= SYSCLK_SRC_FROM_PLL_MASK;
            break;
        }
        case SYSCLK_SRC_UNAVAILABLE: {
            rcc_prt->cfg |= SYSCLK_SRC_UNAVAILABLE_MASK;
            break;
        }
        default:
            break;
    }
}

void rcc_block_wait_sysclk_sts_pll()
{
    SRccControlBlock *rcc_prt = RCC_CONTROL_BLOCK_ADDR;
    while ((((rcc_prt->cfg) & (0x3 << 2)) != (0x2 << 2)))
    {
    }
}