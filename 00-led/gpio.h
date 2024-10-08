#pragma once
#ifndef _STM32F103C8T6_GPIO_INCLUDE_
#define _STM32F103C8T6_GPIO_INCLUDE_
#include <stdint.h>

// gpio related
/* One of the 3 gpios */
typedef struct _SGpioControlBlock
{
    volatile uint32_t crl;
    volatile uint32_t crh;
    volatile uint32_t idr;
    volatile uint32_t odr;
    volatile uint32_t bsrr;
    volatile uint32_t brr;
    volatile uint32_t lock;
} SGpioControlBlock;

#define GPIOA_CTRL_BLOCK_ADDR ((SGpioControlBlock *)0x40010800)
#define GPIOB_CTRL_BLOCK_ADDR ((SGpioControlBlock *)0x40010C00)
#define GPIOC_CTRL_BLOCK_ADDR ((SGpioControlBlock *)0x40011000)

#define GPIO_MODE_OUT_SPPED_RESERVED (0b00)
#define GPIO_MODE_OUT_SPPED_10MHZ    (0b01)
#define GPIO_MODE_OUT_SPPED_2MHZ     (0b10)
#define GPIO_MODE_OUT_SPPED_50MHZ    (0b11)
#define GPIO_MODE_INPUT_ALL          (0b00)

#define GPIO_CNF_GP_OUT_PUSH_PULL    (0b00)
#define GPIO_CNF_GP_OUT_OPEN_DRAIN   (0b01)
#define GPIO_CNF_AF_OUT_PUSH_PULL    (0b10)
#define GPIO_CNF_AF_OUT_OPEN_DRAIN   (0b11)
#define GPIO_CNF_INPUT_ANALOG        (0b00)
#define GPIO_CNF_INPUT_FLOATING      (0b01)
#define GPIO_CNF_INPUT_PULL_UP_DOWN  (0b10)
#define GPIO_CNF_INPUT_PULL_RESERVED (0b11)

#define PA1 1
#define PA2 2
#define PA3 3

#endif //_STM32F103C8T6_GPIO_INCLUDE_