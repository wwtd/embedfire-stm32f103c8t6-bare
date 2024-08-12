#include "active-buzzer.h"
#include "rcc.h"
#include "gpio.h"

void active_buzzer_init()
{
    rcc_enable_ape2(GPIOB_ENABLE_MASK);
    set_gpio_crl_crh(GPIOB_CTRL_BLOCK_ADDR, PB1, GPIO_CNF_GP_OUT_OPEN_DRAIN, GPIO_MODE_OUT_SPPED_2MHZ);
    active_buzzer_stop();
}

void active_buzzer_start()
{
    gpio_set_by_pin(GPIOB_CTRL_BLOCK_ADDR, PB1);
}

void active_buzzer_stop()
{
    gpio_reset_by_pin(GPIOB_CTRL_BLOCK_ADDR, PB1);
}