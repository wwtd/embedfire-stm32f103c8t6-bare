#include "board.h"
#include "on-board-led.h"
#include "mco.h"
#include "hse.h"
#include "usart1.h"
#include "stdint.h"
#include "systick.h"

void board_init()
{
    hse_init();
    on_board_led_init();
    mco_init();
    uart1_init();
    systick_init(72000);
}
