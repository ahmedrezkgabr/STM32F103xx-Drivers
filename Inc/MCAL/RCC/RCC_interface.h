/********************************************/
/*	Author		: Ahmed Rezk		        */
/*	Date		: 10 Feb 2023		        */
/*	file name	: RCC_interface.h		    */
/*	file module	: reset and clock control   */
/*	Version		: V01				        */
/********************************************/



/* File Guard */
#ifndef RCC_INTERFACE__H_
#define RCC_INTERFACE__H_
#include "RCC_private.h"
/* Clock type */
#define RCC_HSI         HSI             /* High speed internal */
#define RCC_HSE         HSE             /* High speed external */
#define RCC_HSE_BYPASS  HSE_BYPASS      /* High speed external with only input pin */
#define RCC_PLL         PLL             /* Phase locked loop */

/* PLL inputs */
#define RCC_PLL_HSI_DIV_2   PLL_HSI_DIV_2
#define RCC_PLL_HSE         PLL_HSE
#define RCC_PLL_HSE_DIV_2   PLL_HSE_DIV_2


/* PLL clock factor */
#define RCC_PLL_CLK_MUL_2       PLL_CLK_MUL_2
#define RCC_PLL_CLK_MUL_3       PLL_CLK_MUL_3
#define RCC_PLL_CLK_MUL_4       PLL_CLK_MUL_4
#define RCC_PLL_CLK_MUL_5       PLL_CLK_MUL_5
#define RCC_PLL_CLK_MUL_6       PLL_CLK_MUL_6
#define RCC_PLL_CLK_MUL_7       PLL_CLK_MUL_7
#define RCC_PLL_CLK_MUL_8       PLL_CLK_MUL_8
#define RCC_PLL_CLK_MUL_9       PLL_CLK_MUL_9
#define RCC_PLL_CLK_MUL_10      PLL_CLK_MUL_10
#define RCC_PLL_CLK_MUL_11      PLL_CLK_MUL_11
#define RCC_PLL_CLK_MUL_12      PLL_CLK_MUL_12
#define RCC_PLL_CLK_MUL_13      PLL_CLK_MUL_13
#define RCC_PLL_CLK_MUL_14      PLL_CLK_MUL_14
#define RCC_PLL_CLK_MUL_15      PLL_CLK_MUL_15
#define RCC_PLL_CLK_MUL_16      PLL_CLK_MUL_16

/* Security system options */
#define RCC_CSS_DISABLE CSS_DISABLE
#define RCC_CSS_ENABLE  CSS_ENABLE



/* AHB peripherals */
#define    DMA1_RCC         AHB_DMA1
#define    DMA2_RCC         AHB_DMA2
#define    SRAM_RCC         AHB_SRAM
#define    FLITF_RCC        AHB_FLITF
#define    CRC_RCC          AHB_CRC
#define    FSMC_RCC         AHB_FSMC
#define    SDIO_RCC         AHB_SDIO

/* APB1 peripherals */
#define    TIM2_RCC         APB1_TIM2
#define    TIM3_RCC         APB1_TIM3
#define    TIM4_RCC         APB1_TIM4
#define    TIM5_RCC         APB1_TIM5
#define    TIM6_RCC         APB1_TIM6
#define    TIM7_RCC         APB1_TIM7
#define    TIM12_RCC        APB1_TIM12
#define    TIM13_RCC        APB1_TIM13
#define    TIM14_RCC        APB1_TIM14
#define    WWDG_RCC         APB1_WWDG
#define    SPI2_RCC         APB1_SPI2
#define    SPI3_RCC         APB1_SPI3
#define    USART2_RCC       APB1_USART2
#define    USART3_RCC       APB1_USART3
#define    UART4_RCC        APB1_UART4
#define    UART5_RCC        APB1_UART5
#define    I2C1_RCC         APB1_I2C1
#define    I2C2_RCC         APB1_I2C2
#define    USB_RCC          APB1_USB
#define    CAN_RCC          APB1_CAN
#define    BKP_RCC          APB1_BKP
#define    PWR_RCC          APB1_PWR
#define    DAC_RCC          APB1_DAC

/* APB2 peripherals */
#define    AFIO_RCC         APB2_AFIO    
#define    GPIOA_RCC        APB2_GPIOA
#define    GPIOB_RCC        APB2_GPIOB
#define    GPIOC_RCC        APB2_GPIOB
#define    GPIOD_RCC        APB2_GPIOC
#define    GPIOE_RCC        APB2_GPIOD
#define    GPIOF_RCC        APB2_GPIOF
#define    GPIOG_RCC        APB2_GPIOG
#define    ADC1_RCC         APB2_ADC1
#define    ADC2_RCC         APB2_ADC2
#define    TIM1_RCC         APB2_TIM1
#define    SPI1_RCC         APB2_SPI1
#define    TIM8_RCC         APB2_TIM8
#define    USART1_RCC       APB2_USART1
#define    ADC3_RCC         APB2_ADC3
#define    TIM9_RCC         APB2_TIM9
#define    TIM10_RCC        APB2_TIM10
#define    TIM11_RCC        APB2_TIM11

/* Buses */
#define    AHB              AHB_BUS
#define    APB1             APB1_BUS
#define    APB2             APB2_BUS

void RCC_VidInit(void);
void RCC_VidEnablePeripheralClock (uint8_t Copy_u8PeripheralBus, uint8_t Copy_u8Peripheral);
void RCC_VidDisablePeripheralClock(uint8_t Copy_u8PeripheralBus, uint8_t Copy_u8Peripheral);

#endif /* RCC_INTERFACE__H_ */
