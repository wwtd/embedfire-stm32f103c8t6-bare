#include "uart.h"
#include "chip.h"

#define RCC_APB2ENR   (*((volatile unsigned int*)0x40021018))
#define GPIOA_CRH     (*((volatile unsigned int*)0x40010804))
#define USART1_SR     (*((volatile unsigned int*)0x40013800))
#define USART1_DR     (*((volatile unsigned int*)0x40013804))
#define USART1_BRR    (*((volatile unsigned int*)0x40013808))
#define USART1_CR1    (*((volatile unsigned int*)0x4001380C))

void uart1_init()
{
    // 1. 启用 GPIOA 和 USART1 时钟
    RCC_APB2ENR |= (1 << 2);  // GPIOA 时钟使能 (位2)
    RCC_APB2ENR |= (1 << 14); // USART1 时钟使能 (位14)

    // 2. 配置 PA9 为复用推挽输出（USART1_TX）
    GPIOA_CRH &= ~(0xF << 4);  // 清除 PA9 的配置
    GPIOA_CRH |= (0xB << 4);   // 配置 PA9 为 2MHz 复用推挽输出 (1011)

    // 3. 配置 USART1
    USART1_BRR = 0x1D4C;      // 设置波特率为 9600 (基于 72 MHz 系统时钟)
    USART1_CR1 |= (1 << 3);   // 启用发送功能 (TE)
    USART1_CR1 |= (1 << 13);  // 启用 USART1 (UE)

    // 4. 发送字符
    char *msg = "Hello";
    while (*msg) {
        while (!(USART1_SR & (1 << 7))); // 等待发送缓冲区为空 (TXE)
        USART1_DR = (*msg++ & 0xFF);     // 发送字符
    }
}