#pragma once
#ifndef _STM32F103C8T6_SYSTICK_INCLUDE_
#define _STM32F103C8T6_SYSTICK_INCLUDE_
#include <stdint.h>

typedef struct _SSystickControlBlock
{
    uint32_t stk_ctrl;
    uint32_t stk_load;
    uint32_t stk_val;
    uint32_t stk_calib;
} SSystickControlBlock;

#define SYSTICK_ENABLE_COUNTER_MASK   ((0x1) << 0)
#define SYSTICK_EXCEPTION_ENABLE_MASK ((0x01) << 1)
#define SYSTICK_SELECT_AHB_CLK_MASK   ((0x01) << 2)

#define SYSTICK_CONTROL_BLOCK_ADDR ((SSystickControlBlock *)0xE000E010)

void systick_init(uint32_t ticks);
uint32_t get_systick();
#endif //_STM32F103C8T6_SYSTICK_INCLUDE_