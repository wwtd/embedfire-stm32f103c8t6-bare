#include "gpio.h"
#include "stddef.h"

uint8_t set_gpio_crl_crh(SGpioControlBlock *gpio_ptr, uint8_t contrl_num,
                         uint8_t cnf, uint8_t mode)
{
    if ((gpio_ptr != NULL) && (0 <= contrl_num && contrl_num <= 15)
        && (0 <= cnf && cnf <= 3) && (0 <= mode && mode <= 3))
    {
        uint32_t *reg;
        uint8_t   shift;

        if (contrl_num < 8)
        {
            reg   = (uint32_t *)(&(gpio_ptr->crl));
            shift = contrl_num * 4;
        }
        else
        {
            reg   = (uint32_t *)(&(gpio_ptr->crh));
            shift = (contrl_num - 8) * 4;
        }

        uint32_t mask = 0xF << shift;
        *reg &= ~mask;
        *reg |= ((cnf << 2) | mode) << shift;

        return 0;
    }
    return 1;
}

void gpio_reset_by_pin(SGpioControlBlock *gpio_ptr, uint8_t contrl_num)
{
    gpio_ptr->bsrr = 1 << (contrl_num + 16);
}

void gpio_set_by_pin(SGpioControlBlock *gpio_ptr, uint8_t contrl_num)
{
    gpio_ptr->bsrr = 1 << (contrl_num + 16);
}
