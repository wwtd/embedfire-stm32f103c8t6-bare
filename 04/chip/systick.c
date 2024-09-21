#include "systick.h"
#include <stdint.h>
#include <stddef.h>
#include "log.h"

static uint32_t gs_tick = 0;

void SysTick_Handler(void)
{
    gs_tick++;
    if(gs_tick % 1000 == 999)
    {
        log_console_print(LOG_LEVEL_WARN, "systick");
    }
}

uint32_t get_systick()
{
    return gs_tick; 
}

void systick_init(uint32_t ticks)
{
    SSystickControlBlock *ctrl_ptr = SYSTICK_CONTROL_BLOCK_ADDR;
    ctrl_ptr->stk_load             = ticks - 1;
    ctrl_ptr->stk_val              = 0;
    ctrl_ptr->stk_ctrl
        = (SYSTICK_ENABLE_COUNTER_MASK | SYSTICK_EXCEPTION_ENABLE_MASK
           | SYSTICK_SELECT_AHB_CLK_MASK);
}