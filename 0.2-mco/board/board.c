#include "board.h"
#include "on-board-led.h"
#include "mco.h"
#include "hse.h"
#include "stdint.h"

void board_init()
{
    hse_init();
    on_board_led_init();
    mco_init();
}
