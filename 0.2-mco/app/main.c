#include "delay.h"
#include "board.h"
#include "on-board-led.h"

int main(int argc, char *argv[])
{
    board_init();
    for (;;)
    {
        on_board_led_turn_on(FIRST);
        delay(1000);
        on_board_led_turn_off(FIRST);
        delay(1000);
    }
    return 0;
}