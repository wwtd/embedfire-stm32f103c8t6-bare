#include "delay.h"
#include "board.h"
#include "on-board-led.h"
#include "log.h"
#include <stdint.h>
#include "usart1.h"
#include "version.h"
#include "systick.h"

void print_usage(void)
{
    log_console_print(LOG_LEVEL_WARN, "---------------------------------");
    log_console_print(LOG_LEVEL_WARN, "USAGE: send num to control leds");
    log_console_print(LOG_LEVEL_WARN, "INPUT 1  --> trun on led 1");
    log_console_print(LOG_LEVEL_WARN, "INPUT 2  --> trun off led 1");
    log_console_print(LOG_LEVEL_WARN, "INPUT 3  --> trun on led 2");
    log_console_print(LOG_LEVEL_WARN, "INPUT 4  --> trun off led 2");
    log_console_print(LOG_LEVEL_WARN, "INPUT 5  --> trun on led 3");
    log_console_print(LOG_LEVEL_WARN, "INPUT 6  --> trun off led 3");
    log_console_print(LOG_LEVEL_WARN, "---------------------------------");
}

void print_version(void)
{
    log_console_print(LOG_LEVEL_WARN, "---------------------------------");
    log_console_print(LOG_LEVEL_WARN, "Git Version:\t%s",
                      version_get_git_version());
    log_console_print(LOG_LEVEL_WARN, "Build Time(UTC):\t%s",
                      version_get_build_time());
    log_console_print(LOG_LEVEL_WARN, "---------------------------------");
}

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
            log_console_print(LOG_LEVEL_WARN, "recv wrong num, see usage");
            print_usage();
            print_version();
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