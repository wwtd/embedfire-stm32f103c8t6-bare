#include "board.h"
#include "on-board-led.h"
#include "active-buzzer.h"

void board_init()
{
    on_board_led_init();
    active_buzzer_init();
}