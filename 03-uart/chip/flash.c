#include "flash.h"

void flash_set_latency(E_FLASH_LATENCY_TYPE latency_type)
{
    SFlashControlBlock *flash_ptr = FLASH_CTRL_BLOCK_ADDR;
    flash_ptr->acr &= ~(0b111);

    switch (latency_type)
    {
        case ZERO_WAIT_STATE: {
            flash_ptr->acr |= FLASH_ZERO_WAIT_STATE_MASK;
            break;
        }
        case ONE_WAIT_STATE: {
            flash_ptr->acr |= FLASH_ONE_WAIT_STATE_MASK;
            break;
        }
        case TWO_WAIT_STATE: {
            flash_ptr->acr |= FLASH_TWO_WAIT_STATE_MASK;
            break;
        }
        default:
            break;
    }
}