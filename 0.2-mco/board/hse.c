#include "hse.h"
#include "chip.h"

void hse_init()
{
    // according to datasheet, before use 72MHz full speed, you should config
    // ｛flash latency｝ & ｛apb1 prescaler｝
    flash_set_latency(TWO_WAIT_STATE);
    rcc_set_apb1_prescaler(PRESCALER_DIV_2);

    // set hse
    rcc_set_hse_on();
    rcc_block_wait_hse_ready();

    // set pll
    rcc_set_pll_src(PLL_SRC_HSE);
    rcc_set_pll_multi_factor(PLL_MULTI_FACTOR_9);
    rcc_set_pll_enable();
    rcc_block_wait_pll_ready();

    // set sysclk
    rcc_set_sysclk_src(SYSCLK_FROM_PLL);
    rcc_block_wait_sysclk_sts_pll();
}