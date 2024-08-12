#include "delay.h"
#include "board.h"

int main(int argc, char *argv[])
{
    board_init();
    for (;;)
    {
        on_board_led_turn_on(FIRST);
        delay(500);
        on_board_led_turn_off(FIRST);
        delay(500);
    }
    return 0;
}