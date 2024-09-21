#include "nvic.h"

void nvic_enable_interrupt(E_NVIC_CTRL_INDEX index)
{
    if ((NVIC_CTRL_WWDG <= index) && (index < NVIC_CTRL_I2C1_ER))
    {
        (NVIC_ISER_CONTROL_BASE_ADDR->iser0) |= ((0x01) << index);
    }
    else if ((NVIC_CTRL_I2C1_ER <= index)
             && (index < NVIC_CTRL_DMA2_Channel4_5))
    {
        (NVIC_ISER_CONTROL_BASE_ADDR->iser1)
            |= ((0x01) << (index - NVIC_CTRL_I2C1_ER));
    }
}