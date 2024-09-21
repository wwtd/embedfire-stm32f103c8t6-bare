#pragma once
#ifndef _STM32F103C8T6_GENERAL_TIMER_INCLUDE_
#define _STM32F103C8T6_GENERAL_TIMER_INCLUDE_
#include "stdint.h"

typedef struct _SGeneralTimerControlBlock
{
    uint32_t cr1;
    uint32_t cr2;
    uint32_t smcr;
    uint32_t dier;
    uint32_t sr;
    uint32_t egr;
    uint32_t ccmr1;
    uint32_t ccmr2;
    uint32_t ccer;
    uint32_t cnt;
    uint32_t psc;
    uint32_t arr;
    uint32_t reserved;
    uint32_t ccr1;
    uint32_t ccr2;
    uint32_t ccr3;
    uint32_t ccr4;
    uint32_t reserved1;
    uint32_t dcr;
    uint32_t dmar;
} SGeneralTimerControlBlock;

#define TIM2_CTRL_BLOCK_ADDR ((SGeneralTimerControlBlock *)0x40000000)
#define TIM3_CTRL_BLOCK_ADDR ((SGeneralTimerControlBlock *)0x40000400)
#define TIM4_CTRL_BLOCK_ADDR ((SGeneralTimerControlBlock *)0x40000800)
#define TIM5_CTRL_BLOCK_ADDR ((SGeneralTimerControlBlock *)0x40000C00)

#endif //_STM32F103C8T6_GENERAL_TIMER_INCLUDE_