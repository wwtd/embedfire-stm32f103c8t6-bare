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