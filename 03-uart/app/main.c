#include "delay.h"
#include "board.h"
#include "on-board-led.h"
#include "log.h"
#include <stdint.h>
#include "usart1.h"

void deal_input_char_func(uint8_t ch)
{
    log_console_print(LOG_LEVEL_DEBUG, "recv char : %c", (char)ch);
    switch (ch)
    {
        case '1': {
            on_board_led_turn_on(FIRST);
        }
        break;
        case '2': {
            on_board_led_turn_off(FIRST);
        }
        break;
        case '3': {
            on_board_led_turn_on(SECOND);
        }
        break;
        case '4': {
            on_board_led_turn_off(SECOND);
        }
        break;
        case '5': {
            on_board_led_turn_on(THIRD);
        }
        break;
        case '6': {
            on_board_led_turn_off(THIRD);
        }
        break;
        default: {
            log_console_print(LOG_LEVEL_WARN,
                              "recv a bad ctrl num, skip control");
            log_console_print(LOG_LEVEL_WARN,
                              "---------------------------------");
            log_console_print(LOG_LEVEL_WARN,
                              "USAGE: input number to control 3 leds on board");
            log_console_print(LOG_LEVEL_WARN, "INPUT 1  --> trun on led 1");
            log_console_print(LOG_LEVEL_WARN, "INPUT 2  --> trun off led 1");
            log_console_print(LOG_LEVEL_WARN, "INPUT 3  --> trun on led 2");
            log_console_print(LOG_LEVEL_WARN, "INPUT 4  --> trun off led 2");
            log_console_print(LOG_LEVEL_WARN, "INPUT 5  --> trun on led 3");
            log_console_print(LOG_LEVEL_WARN, "INPUT 6  --> trun off led 3");
            log_console_print(LOG_LEVEL_WARN,
                              "---------------------------------");
        }
        break;
    }
}

int main(int argc, char *argv[])
{
    board_init();

    for (;;)
    {
        uint8_t ch = uart1_blocking_recv_byte();
        deal_input_char_func(ch);
    }
    return 0;
}