/********************************************************/
/*	Author		: Ahmed Rezk		        			*/
/*	Date		: 12 Feb 2023		        			*/
/*	file name	: EXTI_private.h	        			*/
/*	file module	: external interrupt					*/
/*	Version		: V01				        			*/
/********************************************************/

/* file guard */
#ifndef EXTI_PRIVATE__H_
#define EXTI_PRIVATE__H_

/* register definition */
typedef struct
{
	volatile uint32_t EXTI_IMR;		/* Interrupt mask register */
	volatile uint32_t EXTI_EMR;		/* Event mask register */
	volatile uint32_t EXTI_RTSR;	/* Rising trigger selection register */
	volatile uint32_t EXTI_FTSR;	/* Falling trigger selection register */
	volatile uint32_t EXTI_SWIER;	/* Software interrupt event register */
	volatile uint32_t EXTI_PR;		/* Pending register */
} EXTI_reg_t;

#define EXTI_BASE_ADDRESS	0x40010400

/* pointer to structure of type exti_reg_t*/
#define EXTI				((volatile EXTI_reg_t*) EXTI_BASE_ADDRESS)

#define LINE_0	0
#define LINE_1	1
#define LINE_2	2
#define LINE_3	3
#define LINE_4	4
#define LINE_5	5
#define LINE_6	6
#define LINE_7	7
#define LINE_8	8
#define LINE_9	9
#define LINE_10	10
#define LINE_11	11
#define LINE_12	12
#define LINE_13	13
#define LINE_14	14
#define LINE_15	15
#define LINE_16	16
#define LINE_17	17
#define LINE_18	18
#define LINE_19	19


#define FALLING_EDGE	0
#define RISING_EDGE		1
#define ON_CHANGE		2

static void (*EXTI0_callBack)(void) = NULL;
static void (*EXTI1_callBack)(void) = NULL;

#endif	/* EXTI_PRIVATE__H_ */
