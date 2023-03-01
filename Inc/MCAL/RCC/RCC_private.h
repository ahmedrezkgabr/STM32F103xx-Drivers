/*	Author		: Ahmed Rezk		        */
/*	Date		: 10 Feb 2023		        */
/*	file name	: RCC_private.h		        */
/*	file module	: reset and clock control   */
/*	Version		: V01				        */
/********************************************/



/* File Guard */
#ifndef RCC_PRIVATE__H_
#define RCC_PRIVATE__H_

/* Register definition */
#define RCC_BASE_ADDRESS    0x40021000
#define RCC_CR              *((volatile uint32_t*)(RCC_BASE_ADDRESS + 0x00)) /* Clock control register */
#define RCC_CFGR            *((volatile uint32_t*)(RCC_BASE_ADDRESS + 0x04)) /* Clock configuration register */
#define RCC_CIR             *((volatile uint32_t*)(RCC_BASE_ADDRESS + 0x08)) /* Clock interrupt register */
#define RCC_APB2RSTR        *((volatile uint32_t*)(RCC_BASE_ADDRESS + 0x0C)) /* APB2 peripheral reset register */
#define RCC_APB1RSTR        *((volatile uint32_t*)(RCC_BASE_ADDRESS + 0x10)) /* APB1 peripheral reset register */
#define RCC_AHBENR          *((volatile uint32_t*)(RCC_BASE_ADDRESS + 0x14)) /* AHB peripheral clock enable register */
#define RCC_APB2ENR         *((volatile uint32_t*)(RCC_BASE_ADDRESS + 0x18)) /* APB2 peripheral clock enable register */
#define RCC_APB1ENR         *((volatile uint32_t*)(RCC_BASE_ADDRESS + 0x1C)) /* APB1 peripheral clock enable register */
#define RCC_BDCR            *((volatile uint32_t*)(RCC_BASE_ADDRESS + 0x20)) /* Backup domain control register */
#define RCC_CSR             *((volatile uint32_t*)(RCC_BASE_ADDRESS + 0x24)) /* Control/status register */

/* Varieties used in configuration file */

/* Clock type */
#define HSI         0   /* High speed internal */
#define HSE         1   /* High speed external */
#define HSE_BYPASS  2   /* High speed external with only input pin */
#define PLL         3   /* Phase locked loop */

/* PLL inputs */
#define PLL_HSI_DIV_2   4
#define PLL_HSE         5
#define PLL_HSE_DIV_2   6

/* PLL clock factor */
#define PLL_CLK_MUL_2       0b0000
#define PLL_CLK_MUL_3       0b0001
#define PLL_CLK_MUL_4       0b0010
#define PLL_CLK_MUL_5       0b0011
#define PLL_CLK_MUL_6       0b0100
#define PLL_CLK_MUL_7       0b0101
#define PLL_CLK_MUL_8       0b0110
#define PLL_CLK_MUL_9       0b0111
#define PLL_CLK_MUL_10      0b1000
#define PLL_CLK_MUL_11      0b1001
#define PLL_CLK_MUL_12      0b1010
#define PLL_CLK_MUL_13      0b1011
#define PLL_CLK_MUL_14      0b1100
#define PLL_CLK_MUL_15      0b1101
#define PLL_CLK_MUL_16      0b1110

/* Security system options */
#define CSS_DISABLE 0
#define CSS_ENABLE  1

/* AHB peripherals */
#define AHB_DMA1    0
#define AHB_DMA2    1
#define AHB_SRAM    2
#define AHB_FLITF   4
#define AHB_CRC     6
#define AHB_FSMC    8
#define AHB_SDIO    10

/* APB1 peripherals */
#define APB1_TIM2       0
#define APB1_TIM3       1
#define APB1_TIM4       2
#define APB1_TIM5       3
#define APB1_TIM6       4
#define APB1_TIM7       5
#define APB1_TIM12      6
#define APB1_TIM13      7
#define APB1_TIM14      8
#define APB1_WWDG       11
#define APB1_SPI2       14
#define APB1_SPI3       15
#define APB1_USART2     17
#define APB1_USART3     18
#define APB1_UART4      19
#define APB1_UART5      20
#define APB1_I2C1       21
#define APB1_I2C2       22
#define APB1_USB        23
#define APB1_CAN        25
#define APB1_BKP        27
#define APB1_PWR        28
#define APB1_DAC        29

/* APB2 peripherals */
#define APB2_AFIO   0
#define APB2_GPIOA  2
#define APB2_GPIOB  3
#define APB2_GPIOC  4
#define APB2_GPIOD  5
#define APB2_GPIOE  6
#define APB2_GPIOF  7
#define APB2_GPIOG  8
#define APB2_ADC1   9
#define APB2_ADC2   10
#define APB2_TIM1   11
#define APB2_SPI1   12
#define APB2_TIM8   13
#define APB2_USART1 14
#define APB2_ADC3   15
#define APB2_TIM9   19
#define APB2_TIM10  20
#define APB2_TIM11  21

/* Buses */
#define AHB_BUS     0
#define APB1_BUS    1
#define APB2_BUS    2

#endif /* RCC_PRIVATE__H_ */
