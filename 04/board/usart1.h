#pragma once
#ifndef _BOARD_INCLUDE_USART1_H_
#define _BOARD_INCLUDE_USART1_H_
#include "stdint.h"

void uart1_init();

void uart1_send_string(const char *str);

uint8_t uart1_blocking_recv_byte();

void uart1_set_recv_cb(void (*func_ptr)(void));
#endif //_BOARD_INCLUDE_UART_H_