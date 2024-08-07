#include "chip.h"
#include <stdint.h>
#include <stddef.h>

#define COUNT_NUMBER (72 * 100)
void delay(void)
{
    volatile uint32_t count = 1000 * COUNT_NUMBER;

    while (count--)
        ;
}

void rcc_ctrl()
{
    SRccControlBlock *rp = RCC_CONTROL_BLOCK_ADDR;
    /* Turn on GPIO A clock*/
    rp->ape2 |= GPIOA_ENABLE_MASK;
}

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
            reg   = &(gpio_ptr->crl);
            shift = contrl_num * 4;
        }
        else
        {
            reg   = &(gpio_ptr->crh);
            shift = (contrl_num - 8) * 4;
        }

        uint32_t mask = 0xF << shift;
        *reg &= ~mask;
        *reg |= ((cnf << 2) | mode) << shift;

        return 0;
    }
    return 1;
}

void gpio_ctrl()
{
    SGpioControlBlock *AGpioCtrlPtr = GPIOA_CTRL_BLOCK_ADDR;
    set_gpio_crl_crh(AGpioCtrlPtr, PA1, GPIO_CNF_GP_OUT_OPEN_DRAIN,
                     GPIO_MODE_OUT_SPPED_2MHZ);
    set_gpio_crl_crh(AGpioCtrlPtr, PA2, GPIO_CNF_GP_OUT_OPEN_DRAIN,
                     GPIO_MODE_OUT_SPPED_2MHZ);
    set_gpio_crl_crh(AGpioCtrlPtr, PA3, GPIO_CNF_GP_OUT_OPEN_DRAIN,
                     GPIO_MODE_OUT_SPPED_2MHZ);
}

void turn_on_led(SGpioControlBlock *gpio_ptr, uint8_t contrl_num)
{
    gpio_ptr->bsrr = 1 << (contrl_num + 16);
}

void turn_off_led(SGpioControlBlock *gpio_ptr, uint8_t contrl_num)
{
    gpio_ptr->bsrr = 1 << (contrl_num);
}

void main(void)
{
    rcc_ctrl();
    gpio_ctrl();

    turn_off_led(GPIOA_CTRL_BLOCK_ADDR, PA1);
    turn_off_led(GPIOA_CTRL_BLOCK_ADDR, PA2);
    turn_off_led(GPIOA_CTRL_BLOCK_ADDR, PA3);
    while (1)
    {
        turn_on_led(GPIOA_CTRL_BLOCK_ADDR, PA1);
        delay();
        turn_off_led(GPIOA_CTRL_BLOCK_ADDR, PA1);
        turn_on_led(GPIOA_CTRL_BLOCK_ADDR, PA2);
        delay();
        turn_off_led(GPIOA_CTRL_BLOCK_ADDR, PA2);
        turn_on_led(GPIOA_CTRL_BLOCK_ADDR, PA3);
        delay();
        turn_off_led(GPIOA_CTRL_BLOCK_ADDR, PA3);
    }
    turn_off_led(GPIOA_CTRL_BLOCK_ADDR, PA1);
    turn_off_led(GPIOA_CTRL_BLOCK_ADDR, PA2);
    turn_off_led(GPIOA_CTRL_BLOCK_ADDR, PA3);
}

/* THE END */
