#include "on-board-led.h"
#include "../chip/rcc.h"
#include "../chip/gpio.h"

void on_board_led_init()
{
    rcc_enable_ape2(GPIOA_ENABLE_MASK);
    set_gpio_crl_crh(GPIOA_CTRL_BLOCK_ADDR, PA1, GPIO_CNF_GP_OUT_OPEN_DRAIN, GPIO_MODE_OUT_SPPED_2MHZ);
    set_gpio_crl_crh(GPIOA_CTRL_BLOCK_ADDR, PA2, GPIO_CNF_GP_OUT_OPEN_DRAIN, GPIO_MODE_OUT_SPPED_2MHZ);
    set_gpio_crl_crh(GPIOA_CTRL_BLOCK_ADDR, PA3, GPIO_CNF_GP_OUT_OPEN_DRAIN, GPIO_MODE_OUT_SPPED_2MHZ);
    on_board_led_turn_off(FIRST);
    on_board_led_turn_off(SECOND);
    on_board_led_turn_off(THIRD);
}

void on_board_led_turn_on(E_LED_INDEX index)
{
    switch (index)
    {
        case FIRST:
            gpio_reset_by_pin(GPIOA_CTRL_BLOCK_ADDR, PA1);
            break;
        case SECOND:
            gpio_reset_by_pin(GPIOA_CTRL_BLOCK_ADDR, PA2);
            break;
        case THIRD:
            gpio_reset_by_pin(GPIOA_CTRL_BLOCK_ADDR, PA3);
            break;
    }
}

void on_board_led_turn_off(E_LED_INDEX index)
{
    switch (index)
    {
        case FIRST:
            gpio_set_by_pin(GPIOA_CTRL_BLOCK_ADDR, PA1);
            break;
        case SECOND:
            gpio_set_by_pin(GPIOA_CTRL_BLOCK_ADDR, PA2);
            break;
        case THIRD:
            gpio_set_by_pin(GPIOA_CTRL_BLOCK_ADDR, PA3);
            break;
    }
}
