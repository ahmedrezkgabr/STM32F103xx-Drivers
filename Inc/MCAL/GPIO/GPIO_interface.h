/************************************************/
/*	Author		: Ahmed Rezk		        	*/
/*	Date		: 11 Feb 2023		        	*/
/*	file name	: GPIO_interface.h		        */
/*	file module	: general purpose input output	*/
/*	Version		: V01				        	*/
/************************************************/


/* File Guard */
#ifndef GPIO_INTERFACE__H_
#define GPIO_INTERFACE__H_
#include "GPIO_private.h"

/* Ports */
#define PORT_A	GPIOA_PORT
#define PORT_B	GPIOB_PORT
#define PORT_C	GPIOC_PORT
#define PORT_D	GPIOD_PORT
#define PORT_E	GPIOE_PORT
#define PORT_F	GPIOF_PORT
#define PORT_G	GPIOG_PORT

/* Pins */
#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7
#define PIN8	8
#define PIN9	9
#define PIN10	10
#define PIN11	11
#define PIN12	12
#define PIN13	13
#define PIN14	14
#define PIN15	15

/* Values */
#define PIN_LOW		LOW
#define PIN_HIGH	HIGH

/* Modes */
/* input */
#define MODE_INPUT_ANALOG				INPUT_ANALOG
#define MODE_INPUT_FLOATING				INPUT_FLOATING
#define MODE_INPUT_PULLUP_PULLDOWN		INPUT_PULLUP_PULLDOWN

/* output @ 10MHz */
#define MODE_OUTPUT_SPEED_10MHZ_PP		OUTPUT_SPEED_10MHZ_PP
#define MODE_OUTPUT_SPEED_10MHZ_OD		OUTPUT_SPEED_10MHZ_OD
#define MODE_OUTPUT_SPEED_10MHZ_AFPP	OUTPUT_SPEED_10MHZ_AFPP
#define MODE_OUTPUT_SPEED_10MHZ_AFOD	OUTPUT_SPEED_10MHZ_AFOD

/* output @ 2MHz */
#define MODE_OUTPUT_SPEED_2MHZ_PP   	OUTPUT_SPEED_2MHZ_PP
#define MODE_OUTPUT_SPEED_2MHZ_OD   	OUTPUT_SPEED_2MHZ_OD
#define MODE_OUTPUT_SPEED_2MHZ_AFPP 	OUTPUT_SPEED_2MHZ_AFPP
#define MODE_OUTPUT_SPEED_2MHZ_AFOD 	OUTPUT_SPEED_2MHZ_AFOD

/* output @ 50MHz */
#define MODE_OUTPUT_SPEED_50MHZ_PP  	OUTPUT_SPEED_50MHZ_PP
#define MODE_OUTPUT_SPEED_50MHZ_OD  	OUTPUT_SPEED_50MHZ_OD
#define MODE_OUTPUT_SPEED_50MHZ_AFPP	OUTPUT_SPEED_50MHZ_AFPP
#define MODE_OUTPUT_SPEED_50MHZ_AFOD	OUTPUT_SPEED_50MHZ_AFOD


void GPIO_VidSetPinMode(uint8_t Copy_u8Port, uint8_t Copy_u8Pin, uint8_t Copy_u8Mode);
void GPIO_VidSetPinValue(uint8_t Copy_u8Port, uint8_t Copy_u8Pin, uint8_t Copy_u8Value);
uint8_t GPIO_U8GetPinValue(uint8_t Copy_u8Port, uint8_t Copy_u8Pin);

//void GPIO_VidSetPortMode(uint8_t Copy_u8Port, uint8_t Copy_u8Mode);
//void GPIO_VidSetPortValue(uint8_t Copy_u8Port, uint8_t Copy_u8Value);
//uint16_t GPIO_U16GetPortValue(uint8_t Copy_u8Port);

#endif /* GPIO_INTERFACE__H_ */
