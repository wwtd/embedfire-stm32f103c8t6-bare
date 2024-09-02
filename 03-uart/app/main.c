#include "delay.h"
#include "board.h"
#include "on-board-led.h"
#include "log.h"

int main(int argc, char *argv[])
{
    board_init();
    for (;;)
    {
        on_board_led_turn_on(FIRST);
        log_console_print(LOG_LEVEL_DEBUG, "on");
        delay(1000);
        on_board_led_turn_off(FIRST);
        log_console_print(LOG_LEVEL_DEBUG, "off");
        delay(1000);
    }
    return 0;
}