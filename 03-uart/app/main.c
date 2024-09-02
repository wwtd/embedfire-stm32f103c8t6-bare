#include "delay.h"
#include "board.h"
#include "on-board-led.h"
#include "log.h"
#include <stdint.h>

int main(int argc, char *argv[])
{
    board_init();
    uint32_t loop_count = 0;
    for (;;)
    {
        on_board_led_turn_on(FIRST);
        log_console_print(LOG_LEVEL_DEBUG, "[%u]on", loop_count);
        delay(1000);
        on_board_led_turn_off(FIRST);
        log_console_print(LOG_LEVEL_DEBUG, "[%u]off", loop_count);
        delay(1000);
        loop_count++;
    }
    return 0;
}