#include "rcc.h"
#include <stdint.h>

void rcc_enable_ape2(uint32_t mask)
{
    SRccControlBlock *rp = RCC_CONTROL_BLOCK_ADDR;
    rp->ape2 |= mask;
    return;
}