#include "mco.h"
#include "chip.h"

void mco_init()
{
    set_gpio_crl_crh(GPIOA_CTRL_BLOCK_ADDR, PA8, GPIO_CNF_AF_OUT_PUSH_PULL,
                     GPIO_MODE_OUT_SPPED_50MHZ);
    mco_select_mode(HSE_OUTPUT);
}

void mco_select_mode(E_MCO_OUTPUT_MODE output_mode)
{
    SRccControlBlock *rcc_ptr = RCC_CONTROL_BLOCK_ADDR;
    rcc_ptr->cfg &= ~(0x7 << 24);

    switch (output_mode)
    {
        case NO_CLOCK_OUTPUT: {
            rcc_ptr->cfg |= (MCO_NO_OUTPUT_MASK << 24);
            break;
        }
        case SYSCLK_OUTPUT: {
            rcc_ptr->cfg |= (MCO_SYSCLK_OUTPUT_MASK << 24);
            break;
        }
        case HSI_OUTPUT: {
            rcc_ptr->cfg |= (MCO_HSI_OUTPUT_MASK << 24);
            break;
        }
        case HSE_OUTPUT: {
            rcc_ptr->cfg |= (MCO_HSE_OUTPUT_MASK << 24);
            break;
        }
        case HALF_PLL_OUTPUT: {
            rcc_ptr->cfg |= (MCO_HALF_PLL_OUTPUT_MASK << 24);
            break;
        }
        default:
            break;
    }
}