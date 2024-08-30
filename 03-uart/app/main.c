#include "delay.h"
#include "board.h"
#include "on-board-led.h"
#include "usart1.h"

int main(int argc, char *argv[])
{
    board_init();
    for (;;)
    {
        on_board_led_turn_on(FIRST);
        uart1_send_string("on\r\n");
        delay(1000);
        on_board_led_turn_off(FIRST);
        uart1_send_string("off\r\n");
        delay(1000);
    }
    return 0;
}