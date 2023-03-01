/************************************************/
/*	Author		: Ahmed Rezk		        	*/
/*	Date		: 11 Feb 2023		        	*/
/*	file name	: GPIO_private.h		        */
/*	file module	: general purpose input output	*/
/*	Version		: V01				        	*/
/************************************************/

/* File Guard */
#ifndef GPIO_PRIVATE__H_
#define GPIO_PRIVATE__H_

/* Register definition */
#define GPIOA_BASE_ADDRESS	0x40010800
#define GPIOB_BASE_ADDRESS	0x40010C00
#define GPIOC_BASE_ADDRESS	0x40011000
#define GPIOD_BASE_ADDRESS	0x40011400
#define GPIOE_BASE_ADDRESS	0x40011800
#define GPIOF_BASE_ADDRESS	0x40011C00
#define GPIOG_BASE_ADDRESS	0x40012000

/* General purpose input output (control register low) with offset 0x00 */
#define GPIOA_CRL	*((volatile uint32_t*)(GPIOA_BASE_ADDRESS + 0x00))
#define GPIOB_CRL	*((volatile uint32_t*)(GPIOB_BASE_ADDRESS + 0x00))
#define GPIOC_CRL	*((volatile uint32_t*)(GPIOC_BASE_ADDRESS + 0x00))
#define GPIOD_CRL	*((volatile uint32_t*)(GPIOD_BASE_ADDRESS + 0x00))
#define GPIOE_CRL	*((volatile uint32_t*)(GPIOE_BASE_ADDRESS + 0x00))
#define GPIOF_CRL	*((volatile uint32_t*)(GPIOF_BASE_ADDRESS + 0x00))
#define GPIOG_CRL	*((volatile uint32_t*)(GPIOG_BASE_ADDRESS + 0x00))

/* General purpose input output (control register high) with offset 0x04 */
#define GPIOA_CRH	*((volatile uint32_t*)(GPIOA_BASE_ADDRESS + 0x04))
#define GPIOB_CRH	*((volatile uint32_t*)(GPIOB_BASE_ADDRESS + 0x04))
#define GPIOC_CRH	*((volatile uint32_t*)(GPIOC_BASE_ADDRESS + 0x04))
#define GPIOD_CRH	*((volatile uint32_t*)(GPIOD_BASE_ADDRESS + 0x04))
#define GPIOE_CRH	*((volatile uint32_t*)(GPIOE_BASE_ADDRESS + 0x04))
#define GPIOF_CRH	*((volatile uint32_t*)(GPIOF_BASE_ADDRESS + 0x04))
#define GPIOG_CRH	*((volatile uint32_t*)(GPIOG_BASE_ADDRESS + 0x04))

/* General purpose input output (input data register) with offset 0x08 */
#define GPIOA_IDR	*((volatile uint32_t*)(GPIOA_BASE_ADDRESS + 0x08))
#define GPIOB_IDR	*((volatile uint32_t*)(GPIOB_BASE_ADDRESS + 0x08))
#define GPIOC_IDR	*((volatile uint32_t*)(GPIOC_BASE_ADDRESS + 0x08))
#define GPIOD_IDR	*((volatile uint32_t*)(GPIOD_BASE_ADDRESS + 0x08))
#define GPIOE_IDR	*((volatile uint32_t*)(GPIOE_BASE_ADDRESS + 0x08))
#define GPIOF_IDR	*((volatile uint32_t*)(GPIOF_BASE_ADDRESS + 0x08))
#define GPIOG_IDR	*((volatile uint32_t*)(GPIOG_BASE_ADDRESS + 0x08))

/* General purpose input (output output data register) with offset 0x0C */
#define GPIOA_ODR	*((volatile uint32_t*)(GPIOA_BASE_ADDRESS + 0x0C))
#define GPIOB_ODR	*((volatile uint32_t*)(GPIOB_BASE_ADDRESS + 0x0C))
#define GPIOC_ODR	*((volatile uint32_t*)(GPIOC_BASE_ADDRESS + 0x0C))
#define GPIOD_ODR	*((volatile uint32_t*)(GPIOD_BASE_ADDRESS + 0x0C))
#define GPIOE_ODR	*((volatile uint32_t*)(GPIOE_BASE_ADDRESS + 0x0C))
#define GPIOF_ODR	*((volatile uint32_t*)(GPIOF_BASE_ADDRESS + 0x0C))
#define GPIOG_ODR	*((volatile uint32_t*)(GPIOG_BASE_ADDRESS + 0x0C))

/* General purpose input (bit set reset register) with offset 0x10 */
#define GPIOA_BSRR	*((volatile uint32_t*)(GPIOA_BASE_ADDRESS + 0x10))
#define GPIOB_BSRR	*((volatile uint32_t*)(GPIOB_BASE_ADDRESS + 0x10))
#define GPIOC_BSRR	*((volatile uint32_t*)(GPIOC_BASE_ADDRESS + 0x10))
#define GPIOD_BSRR	*((volatile uint32_t*)(GPIOD_BASE_ADDRESS + 0x10))
#define GPIOE_BSRR	*((volatile uint32_t*)(GPIOE_BASE_ADDRESS + 0x10))
#define GPIOF_BSRR	*((volatile uint32_t*)(GPIOF_BASE_ADDRESS + 0x10))
#define GPIOG_BSRR	*((volatile uint32_t*)(GPIOG_BASE_ADDRESS + 0x10))

/* General purpose input (bit reset register) with offset 0x14 */
#define GPIOA_BRR	*((volatile uint32_t*)(GPIOA_BASE_ADDRESS + 0x14))
#define GPIOB_BRR	*((volatile uint32_t*)(GPIOB_BASE_ADDRESS + 0x14))
#define GPIOC_BRR	*((volatile uint32_t*)(GPIOC_BASE_ADDRESS + 0x14))
#define GPIOD_BRR	*((volatile uint32_t*)(GPIOD_BASE_ADDRESS + 0x14))
#define GPIOE_BRR	*((volatile uint32_t*)(GPIOE_BASE_ADDRESS + 0x14))
#define GPIOF_BRR	*((volatile uint32_t*)(GPIOF_BASE_ADDRESS + 0x14))
#define GPIOG_BRR	*((volatile uint32_t*)(GPIOG_BASE_ADDRESS + 0x14))

/* General purpose input (lock register) with offset 0x18 */
#define GPIOA_LCKR	*((volatile uint32_t*)(GPIOA_BASE_ADDRESS + 0x18))
#define GPIOB_LCKR	*((volatile uint32_t*)(GPIOB_BASE_ADDRESS + 0x18))
#define GPIOC_LCKR	*((volatile uint32_t*)(GPIOC_BASE_ADDRESS + 0x18))
#define GPIOD_LCKR	*((volatile uint32_t*)(GPIOD_BASE_ADDRESS + 0x18))
#define GPIOE_LCKR	*((volatile uint32_t*)(GPIOE_BASE_ADDRESS + 0x18))
#define GPIOF_LCKR	*((volatile uint32_t*)(GPIOF_BASE_ADDRESS + 0x18))
#define GPIOG_LCKR	*((volatile uint32_t*)(GPIOG_BASE_ADDRESS + 0x18))


/* Ports */
#define GPIOA_PORT	0
#define GPIOB_PORT	1
#define GPIOC_PORT	2
#define GPIOD_PORT	3
#define GPIOE_PORT	4
#define GPIOF_PORT	5
#define GPIOG_PORT	6

/* Values */
#define LOW		0
#define HIGH	1

/* Modes */
/* input */
#define INPUT_ANALOG              0b0000
#define INPUT_FLOATING            0b0100
#define INPUT_PULLUP_PULLDOWN     0b1000

/* output @ 10MHz */
#define OUTPUT_SPEED_10MHZ_PP     0b0001
#define OUTPUT_SPEED_10MHZ_OD     0b0101
#define OUTPUT_SPEED_10MHZ_AFPP   0b1001
#define OUTPUT_SPEED_10MHZ_AFOD   0b1101

/* output @ 2MHz */
#define OUTPUT_SPEED_2MHZ_PP      0b0010
#define OUTPUT_SPEED_2MHZ_OD      0b0110
#define OUTPUT_SPEED_2MHZ_AFPP    0b1010
#define OUTPUT_SPEED_2MHZ_AFOD    0b1110

/* output @ 50MHz */
#define OUTPUT_SPEED_50MHZ_PP     0b0011
#define OUTPUT_SPEED_50MHZ_OD     0b0111
#define OUTPUT_SPEED_50MHZ_AFPP   0b1011
#define OUTPUT_SPEED_50MHZ_AFOD   0b1111


#endif /* GPIO_PRIVATE__H_ */
