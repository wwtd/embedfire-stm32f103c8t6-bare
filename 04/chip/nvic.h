#pragma once
#ifndef _STM32F103C8T6_NVIC_INCLUDE_
#define _STM32F103C8T6_NVIC_INCLUDE_
#include <stdint.h>

typedef struct _SNVIC_ISER_Block
{
    uint32_t iser0;
    uint32_t iser1;
    uint32_t iser2;
} SNVIC_ISER_Block;

typedef struct _SNVIC_ICER_Block
{
    uint32_t icer0;
    uint32_t icer1;
    uint32_t icer2;
} SNVIC_ICER_Block;

typedef struct _SNVIC_ISPR_Block
{
    uint32_t ispr0;
    uint32_t ispr1;
    uint32_t ispr2;
} SNVIC_ISPR_Block;

typedef struct _SNVIC_ICPR_Block
{
    uint32_t icer0;
    uint32_t icer1;
    uint32_t icer2;
} SNVIC_ICPR_Block;

typedef struct _SNVIC_IABR_Block
{
    uint32_t iabr0;
    uint32_t iabr1;
    uint32_t iabr2;
} SNVIC_IABR_Block;

typedef struct _SNVIC_IPR_Block
{
    uint32_t ipr[21];
} SNVIC_IPR_Block;

#define NVIC_ISER_CONTROL_BASE_ADDR ((SNVIC_ISER_Block *)0xE000E100)
#define NVIC_ICER_CONTROL_BASE_ADDR ((SNVIC_ICER_Block *)0xE000E180)
#define NVIC_ISPR_CONTROL_BASE_ADDR ((SNVIC_ISPR_Block *)0xE000E200)
#define NVIC_ICPR_CONTROL_BASE_ADDR ((SNVIC_ICPR_Block *)0xE000E280)
#define NVIC_IABR_CONTROL_BASE_ADDR ((SNVIC_IABR_Block *)0xE000E300)
#define NVIC_IPR_CONTROL_BASE_ADDR  ((SNVIC_IPR_Block *)0xE000E400)

typedef enum
{
    NVIC_CTRL_WWDG            = 0x00,
    NVIC_CTRL_PVD             = 0x01,
    NVIC_CTRL_TAMPER          = 0x02,
    NVIC_CTRL_RTC             = 0x03,
    NVIC_CTRL_FLASH           = 0x04,
    NVIC_CTRL_RCC             = 0x05,
    NVIC_CTRL_EXTI0           = 0x06,
    NVIC_CTRL_EXTI1           = 0x07,
    NVIC_CTRL_EXTI2           = 0x08,
    NVIC_CTRL_EXTI3           = 0x09,
    NVIC_CTRL_EXTI4           = 0x0A,
    NVIC_CTRL_DMA1_Channel1   = 0x0B,
    NVIC_CTRL_DMA1_Channel2   = 0x0C,
    NVIC_CTRL_DMA1_Channel3   = 0x0D,
    NVIC_CTRL_DMA1_Channel4   = 0x0E,
    NVIC_CTRL_DMA1_Channel5   = 0x0F,
    NVIC_CTRL_DMA1_Channel6   = 0x10,
    NVIC_CTRL_DMA1_Channel7   = 0x11,
    NVIC_CTRL_ADC1_2          = 0x12,
    NVIC_CTRL_USB_HP_CAN_TX   = 0x13,
    NVIC_CTRL_USB_LP_CAN_RX0  = 0x14,
    NVIC_CTRL_CAN_RX1         = 0x15,
    NVIC_CTRL_CAN_SCE         = 0x16,
    NVIC_CTRL_EXTI9_5         = 0x17,
    NVIC_CTRL_TIM1_BRK        = 0x18,
    NVIC_CTRL_TIM1_UP         = 0x19,
    NVIC_CTRL_TIM1_TRG_COM    = 0x1A,
    NVIC_CTRL_TIM1_CC         = 0x1B,
    NVIC_CTRL_TIM2            = 0x1C,
    NVIC_CTRL_TIM3            = 0x1D,
    NVIC_CTRL_TIM4            = 0x1E,
    NVIC_CTRL_I2C1_EV         = 0x1F,
    NVIC_CTRL_I2C1_ER         = 0x20,
    NVIC_CTRL_I2C2_EV         = 0x21,
    NVIC_CTRL_I2C2_ER         = 0x22,
    NVIC_CTRL_SPI1            = 0x23,
    NVIC_CTRL_SPI2            = 0x24,
    NVIC_CTRL_USART1          = 0x25,
    NVIC_CTRL_USART2          = 0x26,
    NVIC_CTRL_USART3          = 0x27,
    NVIC_CTRL_EXTI15_10       = 0x28,
    NVIC_CTRL_RTCAlarm        = 0x29,
    NVIC_CTRL_USBWakeup       = 0x2A,
    NVIC_CTRL_TIM8_BRK        = 0x2B,
    NVIC_CTRL_TIM8_UP         = 0x2C,
    NVIC_CTRL_TIM8_TRG_COM    = 0x2D,
    NVIC_CTRL_TIM8_CC         = 0x2E,
    NVIC_CTRL_ADC3            = 0x2F,
    NVIC_CTRL_FSMC            = 0x30,
    NVIC_CTRL_SDIO            = 0x31,
    NVIC_CTRL_TIM5            = 0x32,
    NVIC_CTRL_SPI3            = 0x33,
    NVIC_CTRL_UART4           = 0x34,
    NVIC_CTRL_UART5           = 0x35,
    NVIC_CTRL_TIM6            = 0x36,
    NVIC_CTRL_TIM7            = 0x37,
    NVIC_CTRL_DMA2_Channel1   = 0x38,
    NVIC_CTRL_DMA2_Channel2   = 0x39,
    NVIC_CTRL_DMA2_Channel3   = 0x3A,
    NVIC_CTRL_DMA2_Channel4_5 = 0x3B,
} E_NVIC_CTRL_INDEX;

void nvic_enable_interrupt(E_NVIC_CTRL_INDEX index);

#endif //_STM32F103C8T6_NVIC_INCLUDE_