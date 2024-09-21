#include "delay.h"

void delay(uint16_t count)
{
    volatile uint32_t counts = 8000 * count;

    while (counts--)
        ;
}
