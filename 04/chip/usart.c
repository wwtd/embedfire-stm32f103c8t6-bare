#include "usart.h"
#include <stdbool.h>
#include <stdint.h>
#include "stddef.h"

void usart_set_baud_rate(SUsartControlBlock *ptr, uint32_t baud_rate,
                         uint32_t clk_freq)
{
    // Adding (baud_rate / 2) is to achieve rounding to the nearest integer.
    uint32_t usart_div = ((clk_freq + (baud_rate / 2)) / (baud_rate));

    uint32_t mantissa = (usart_div / 16);
    uint32_t fraction = (usart_div % 16);
    ptr->brr          = (mantissa << 4) | (fraction & 0xF);
}

void usart_enable_transmitter(SUsartControlBlock *ptr)
{
    ptr->cr1 |= USART_ENABLE_TRANSMITTER_MASK;
}

void usart_enable_receiver(SUsartControlBlock *ptr)
{
    ptr->cr1 |= USART_ENABLE_RECEIVER_MASK;
}

void usart_enable_usart(SUsartControlBlock *ptr)
{
    ptr->cr1 |= USART_ENABLE_MASK;
}

void usart_blocking_send_byte(SUsartControlBlock *ptr, uint8_t data)
{
    while (!usart_transmit_data_register_empty(ptr))
    {
        // wait
    }
    ptr->dr = data;
    while (!usart_transmit_data_register_empty(ptr))
    {
        // wait
    }
}

bool usart_transmit_data_register_empty(SUsartControlBlock *ptr)
{
    return (((ptr->sr) & (0x01 << 7)) == 0) ? false : true;
}

void usart_blocking_send_string(SUsartControlBlock *ptr, const char *str)
{
    uint8_t *byte_ptr = (uint8_t *)str;
    while ((*byte_ptr) != 0x00)
    {
        usart_blocking_send_byte(ptr, (*byte_ptr));
        ++byte_ptr;
    }
}

uint8_t usart_blocking_recv_byte(SUsartControlBlock *ptr)
{
    while (usart_recvive_data_register_empty(ptr))
    {
        // wait
    };
    return (uint8_t)((ptr->dr) & 0xFF);
}

bool usart_recvive_data_register_empty(SUsartControlBlock *ptr)
{
    return (((ptr->sr) & (1 << 5)) == 0) ? true : false;
}