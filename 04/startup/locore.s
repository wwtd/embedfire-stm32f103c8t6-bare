.section .vectors
.cpu cortex-m3
.thumb

.word   0x20005000  /* stack top address */
.word   _reset      /* 1 Reset */
.word   spin        /* 2 NMI */
.word   spin        /* 3 Hard Fault */
.word   spin        /* 4 MM Fault */
.word   spin        /* 5 Bus Fault */
.word   spin        /* 6 Usage Fault */
.word   spin        /* 7 RESERVED */
.word   spin        /* 8 RESERVED */
.word   spin        /* 9 RESERVED*/
.word   spin        /* 10 RESERVED */
.word   spin        /* 11 SV call */
.word   spin        /* 12 Debug reserved */
.word   spin        /* 13 RESERVED */
.word   spin        /* 14 PendSV */
.word   SysTick_Handler /* 15 SysTick */
.word   spin        /* 16 WWDG */
.word   spin        /* 17 PVD */
.word   spin        /* 18 TAMPER */
.word   spin        /* 19 RTC   */
.word   spin        /* 20 FLASH */
.word   spin        /* 21 RCC */
.word   spin        /* 22 EXTI0 */
.word   spin        /* 23 EXTI1 */
.word   spin        /* 24 EXTI2 */
.word   spin        /* 25 EXTI3 */
.word   spin        /* 26 EXTI4 */
.word   spin        /* 27 DMA1 Channel1 */
.word   spin        /* 28 DMA1 Channel2 */
.word   spin        /* 29 DMA1 Channel3 */
.word   spin        /* 30 DMA1 Channel4 */
.word   spin        /* 31 DMA1 Channel5 */
.word   spin        /* 32 DMA1 Channel6 */
.word   spin        /* 33 DMA1 Channel7 */
.word   spin        /* 34 ADC1 and ADC2 */
.word   spin        /* 35 USB High Priority or CAN TX */
.word   spin        /* 36 USB Low Priority or CAN RX0 */
.word   spin        /* 37 CAN RX1 */
.word   spin        /* 38 CAN SCE */
.word   spin        /* 39 EXTI line[9:5] */
.word   spin        /* 40 TIM1 Break */
.word   spin        /* 41 TIM1 Update */
.word   spin        /* 42 TIM1 Tigger and Commutation */
.word   spin        /* 43 TIM1 Capture Compare */
.word   spin        /* 44 TIM2 */
.word   spin        /* 45 TIM3 */
.word   spin        /* 46 TIM4 */
.word   spin        /* 47 I2C1 Event */
.word   spin        /* 48 I2C1 Error */
.word   spin        /* 49 I2C2 Event */
.word   spin        /* 50 I2C2 Error */
.word   spin        /* 51 SPI1 */
.word   spin        /* 52 SPI2 */
.word   USART1_Handler        /* 53 USART1 */
.word   spin        /* 54 USART2 */
.word   spin        /* 55 USART3 */
.word   spin        /* 56 EXTI Line[15:10] */
.word   spin        /* 57 RTC alarm through EXTI */
.word   spin        /* 58 USB wakeup through EXTI*/
.word   spin        /* 59 TIM8 Break */
.word   spin        /* 60 TIM8 Update*/
.word   spin        /* 61 TIM8 Tigger and Commutation */
.word   spin        /* 62 TIM8 Capture Compare*/
.word   spin        /* 63 ADC3*/
.word   spin        /* 64 FSMC*/
.word   spin        /* 65 SDIO*/
.word   spin        /* 66 TIM5*/
.word   spin        /* 67 SPI3*/
.word   spin        /* 68 UART4*/
.word   spin        /* 69 UART5*/
.word   spin        /* 70 TIM6*/
.word   spin        /* 71 TIM7*/
.word   spin        /* 72 DMA2 Channel1*/
.word   spin        /* 73 DMA2 Channel2*/
.word   spin        /* 74 DMA2 Channel3*/
.word   spin        /* 75 DMA2 Channel4 and Channel5*/

.section .text

.thumb_func
spin:   b spin

.thumb_func
_reset:
    bl main
    b .

/* THE END */
