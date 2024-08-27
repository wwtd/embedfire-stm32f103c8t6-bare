#include "usart.h"
#include <stdint.h>

void usart_set_baud_rate(SUsartControlBlock *ptr, uint32_t baud_rate,
                         uint32_t clk_freq)
{
    // Adding (baud_rate / 2) is to achieve rounding to the nearest integer.
    uint32_t usart_div = ((clk_freq + (baud_rate / 2)) / (baud_rate));

    uint32_t mantissa = (usart_div / 16);
    uint32_t fraction = (usart_div % 16);
    ptr->brr          = (mantissa << 4) | (fraction & 0xF);
}