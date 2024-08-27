#include "usart1.h"
#include "chip.h"
#include "gpio.h"
#include "rcc.h"
#include "usart.h"

#define RCC_APB2ENR   (*((volatile unsigned int*)0x40021018))
#define GPIOA_CRH     (*((volatile unsigned int*)0x40010804))
#define USART1_SR     (*((volatile unsigned int*)0x40013800))
#define USART1_DR     (*((volatile unsigned int*)0x40013804))
#define USART1_BRR    (*((volatile unsigned int*)0x40013808))
#define USART1_CR1    (*((volatile unsigned int*)0x4001380C))

void uart1_init()
{
    rcc_enable_ape2(GPIOA_ENABLE_MASK);
    rcc_enable_ape2(USART1_ENABLE_MASK);
    set_gpio_crl_crh(GPIOA_CTRL_BLOCK_ADDR, PA9, GPIO_CNF_AF_OUT_PUSH_PULL, GPIO_MODE_OUT_SPPED_2MHZ);

    usart_set_baud_rate(USART1_CONTROL_BLOCK_ADDR, 9600, 72000000);
    USART1_CR1 |= (1 << 3);   // 启用发送功能 (TE)
    USART1_CR1 |= (1 << 13);  // 启用 USART1 (UE)

    // 4. 发送字符
    char *msg = "Hello";
    while (*msg) {
        while (!(USART1_SR & (1 << 7))); // 等待发送缓冲区为空 (TXE)
        USART1_DR = (*msg++ & 0xFF);     // 发送字符
    }
}