#pragma once
#ifndef _BOARD_INCLUDE_ON_BOARD_LED_H_
#define _BOARD_INCLUDE_ON_BOARD_LED_H_

typedef enum
{
    FIRST  = 1,
    SECOND = 2,
    THIRD  = 3,
} E_LED_INDEX;

void on_board_led_init();
void on_board_led_turn_on(E_LED_INDEX index);
void on_board_led_turn_off(E_LED_INDEX index);

#endif //_BOARD_INCLUDE_ON_BOARD_LED_H_