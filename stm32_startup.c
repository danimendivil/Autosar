
#include <stdint.h>

#define SRAM_START  0x20000000U
#define SRAM_SIZE   (128*1024) //128KB
#define SRAM_END    (SRAM_START) + (SRAM_SIZE)

#define STACK_START     SRAM_END

void Reset_Handler  (void);
void NMI_Handler (void)                         __attribute__((weak,alias("Default_Handler")));
void HardFault_Handler (void)                   __attribute__((weak,alias("Default_Handler")));
void SVC_Handler (void)                         __attribute__((weak,alias("Default_Handler")));
void PendSV_Handler (void)                      __attribute__((weak,alias("Default_Handler")));
void SysTick_Handler (void)                     __attribute__((weak,alias("Default_Handler")));
void WWDG_Handler (void)                        __attribute__((weak,alias("Default_Handler")));
void PVD_Handler (void)                         __attribute__((weak,alias("Default_Handler")));
void RTC_TAMP_Handler (void)                    __attribute__((weak,alias("Default_Handler")));
void FLASH_Handler (void)                       __attribute__((weak,alias("Default_Handler")));
void RCC_CRS_Handler (void)                     __attribute__((weak,alias("Default_Handler")));
void EXTI0_1_Handler (void)                     __attribute__((weak,alias("Default_Handler")));
void EXTI2_3_Handler (void)                     __attribute__((weak,alias("Default_Handler")));
void EXTI4_15_Handler (void)                    __attribute__((weak,alias("Default_Handler")));
void UCPD1_UCPD2_USB_Handler (void)             __attribute__((weak,alias("Default_Handler")));
void DMA1_Channel1_Handler (void)               __attribute__((weak,alias("Default_Handler")));
void DMA1_Channel2_3_Handler (void)             __attribute__((weak,alias("Default_Handler")));
void DMA1_Channel4_5_6_Handler (void)           __attribute__((weak,alias("Default_Handler")));
void ADC_COMP_Handler (void)                    __attribute__((weak,alias("Default_Handler")));
void TIM1_BRK_UP_TRG_COM_Handler (void)         __attribute__((weak,alias("Default_Handler")));
void TIM1_CC_Handler (void)                     __attribute__((weak,alias("Default_Handler")));
void TIM2_Handler (void)                        __attribute__((weak,alias("Default_Handler")));
void TIM3_4_Handler (void)                      __attribute__((weak,alias("Default_Handler")));
void TIM6_DAC_LPTIM1_Handler (void)             __attribute__((weak,alias("Default_Handler")));
void TIM7_LPTIM2_Handler (void)                 __attribute__((weak,alias("Default_Handler")));
void TIM14_Handler (void)                       __attribute__((weak,alias("Default_Handler")));
void TIM15_Handler (void)                       __attribute__((weak,alias("Default_Handler")));
void TIM16_FDCAN_IT0_Handler (void)             __attribute__((weak,alias("Default_Handler")));
void TIM17_FDCAN_IT1_Handler (void)             __attribute__((weak,alias("Default_Handler")));
void I2C1_Handler (void)                        __attribute__((weak,alias("Default_Handler")));
void I2C2_I2C3_Handler (void)                   __attribute__((weak,alias("Default_Handler")));
void SPI1_Handler (void)                        __attribute__((weak,alias("Default_Handler")));
void SPI2_SPI3_Handler (void)                   __attribute__((weak,alias("Default_Handler")));
void USART1_Handler (void)                      __attribute__((weak,alias("Default_Handler")));
void USART2_LPUART2_Handler (void)              __attribute__((weak,alias("Default_Handler")));
void USART3_4_5_6_LPUART1_Handler (void)        __attribute__((weak,alias("Default_Handler")));
void CEC_Handler (void)                         __attribute__((weak,alias("Default_Handler")));
void AES_RNG_Handler (void)                     __attribute__((weak,alias("Default_Handler")));

uint32_t vectors[] __attribute__((section(".isr_vector"))) = 
{
    STACK_START,
    (uint32_t)&Reset_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&HardFault_Handler,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    (uint32_t)&SVC_Handler,
    0,
    0,
    (uint32_t)&PendSV_Handler,
    (uint32_t)&SysTick_Handler,
    (uint32_t)&WWDG_Handler,
    (uint32_t)&PVD_Handler,
    (uint32_t)&RTC_TAMP_Handler,
    (uint32_t)&FLASH_Handler,
    (uint32_t)&RCC_CRS_Handler,
    (uint32_t)&EXTI0_1_Handler,
    (uint32_t)&EXTI2_3_Handler,
    (uint32_t)&EXTI4_15_Handler,
    (uint32_t)&UCPD1_UCPD2_USB_Handler,
    (uint32_t)&DMA1_Channel1_Handler,
    (uint32_t)&DMA1_Channel2_3_Handler,
    (uint32_t)&DMA1_Channel4_5_6_Handler,
    (uint32_t)&ADC_COMP_Handler,
    (uint32_t)&TIM1_BRK_UP_TRG_COM_Handler,
    (uint32_t)&TIM1_CC_Handler,
    (uint32_t)&TIM2_Handler,
    (uint32_t)&TIM3_4_Handler,
    (uint32_t)&TIM6_DAC_LPTIM1_Handler,
    (uint32_t)&TIM7_LPTIM2_Handler,
    (uint32_t)&TIM14_Handler,
    (uint32_t)&TIM15_Handler,
    (uint32_t)&TIM16_FDCAN_IT0_Handler,
    (uint32_t)&TIM17_FDCAN_IT1_Handler,
    (uint32_t)&I2C1_Handler,
    (uint32_t)&I2C2_I2C3_Handler,
    (uint32_t)&SPI1_Handler,
    (uint32_t)&SPI2_SPI3_Handler, 
    (uint32_t)&USART1_Handler,
    (uint32_t)&USART2_LPUART2_Handler,
    (uint32_t)&USART3_4_5_6_LPUART1_Handler,
    (uint32_t)&CEC_Handler,
    (uint32_t)&AES_RNG_Handler,
};

void Default_Handler (void)
{
    while(1);
}

void Reset_Handler (void)
{

}


