#include "active-buzzer.h"
#include "delay.h"
#include "board.h"
#include "on-board-led.h"

int main(int argc, char *argv[])
{
    board_init();
    for (;;)
    {
        on_board_led_turn_on(FIRST);
        active_buzzer_start();
        delay(500);
        active_buzzer_stop();
        on_board_led_turn_off(FIRST);
        on_board_led_turn_on(SECOND);
        delay(500);
        on_board_led_turn_off(SECOND);
        on_board_led_turn_on(THIRD);
        delay(500);
        on_board_led_turn_off(THIRD);
    }
    return 0;
}