/********************************************************/
/*	Author		: Ahmed Rezk		        			*/
/*	Date		: 25 Feb 2023		        			*/
/*	file name	: USART_program.c 		    			*/
/*	file module	: universal synch asynchronous Rx Tx	*/
/*	Version		: V01				        			*/
/********************************************************/


/* INCLUDES */

/* Library */
#include "LIB/std_types.h"
#include "LIB/bit_math.h"

/* Lower layers interfaces */
/* None */

/* My own interface */
#include "MCAL/USART/USART_interface.h"

/* Private and configuration files */
#include "MCAL/USART/USART_private.h"
#include "MCAL/USART/USART_config.h"


void USART1_IRQHandler(void)
{
	if(USART1_callBack)
		USART1_callBack((uint8_t)USART1->USART_DR);

	/* clear flags */
	/* bits 5 and 6 in SR are responsible for clearing the interrupt flags */
	CLR_BIT(USART1->USART_SR, 5);
	CLR_BIT(USART1->USART_SR, 6);
}

void USART1_VidInit(void)
{
/***************************************************************************************/
/********************************baud rate calculations*********************************/
/***************************************************************************************/
	/* calculating the integer part of the div */
	uint32_t Loc_u32Mantissa = (F_CPU) / (16 * USART1_BAUD_RATE);

	/* calculating the fraction */
	uint32_t Loc_u32Fraction = (((F_CPU * 100) / (16 * USART1_BAUD_RATE)) % 100) * 16;

	if(Loc_u32Fraction > 1500)	/* carry status */
	{
		Loc_u32Mantissa += 1 ;
		Loc_u32Fraction  = 0 ;
	}

#if USART1_STATUS == USART1_ENABLE

	/* clear the status register */
	USART1->USART_SR = 0x0000;

/***************************************************************************************/
/***************************************data size***************************************/
/***************************************************************************************/
	#if   USART1_DATA_SIZE == USART_8_BITS

		/* choose 8-bits data size */
		/* bit 12 in CR1 is responsible for choosing the data size */
		CLR_BIT(USART1->USART_CR1, 12);

	#elif USART1_DATA_SIZE == USART_9_BITS

		/* choose 9-bits data size */
		/* bit 12 in CR1 is responsible for choosing the data size */
		SET_BIT(USART1->USART_CR1, 12);

	#endif	/* nested if (data size) */

/***************************************************************************************/
/***************************************parity bit**************************************/
/***************************************************************************************/
	#if   USART1_PARITY == PARITY_DISABLE

		/* disable parity bit */
		/* bit 10 in CR1 is responsible for enabling and disabling parity bit */
		CLR_BIT(USART1->USART_CR1, 10);

	#elif USART1_PARITY == EVEN_PARITY

		/* enable parity bit */
		/* bit 10 in CR1 is responsible for enabling and disabling parity bit */
		SET_BIT(USART1->USART_CR1, 10);

		/* choose even parity bit */
		/* bit 11 in CR1 is responsible for choosing parity bit is even or odd */
		CLR_BIT(USART1->USART_CR1, 11);

	#elif USART1_PARITY == ODD_PARITY

		/* enable parity bit */
		/* bit 10 in CR1 is responsible for enabling and disabling parity bit */
		SET_BIT(USART1->USART_CR1, 10);

		/* choose even parity bit */
		/* bit 11 in CR1 is responsible for choosing parity bit is even or odd */
		SET_BIT(USART1->USART_CR1, 11);

	#endif	/* nested if (parity bit) */


/***************************************************************************************/
/***************************************interrupts**************************************/
/***************************************************************************************/
	#if  USART1_INTERRUPT == INT_DISABLE

		/* disable the three interrupts */
		/* bits 5, 6, and 7 in CR1 are responsible for enabling and disabling the interrupts */
		CLR_BIT(USART1->USART_CR1, 5);
		CLR_BIT(USART1->USART_CR1, 6);
		CLR_BIT(USART1->USART_CR1, 7);

	#elif USART1_INTERRUPT == TXE_INT_ENABLE

		/* enable transmit data register is empty interrupt */
		/* bit 7 in CR1 is responsible for enabling and disabling transmit data register is empty interrupt */
		SET_BIT(USART1->USART_CR1, 7);

	#elif USART1_INTERRUPT == TCE_INT_ENABLE

		/* enable transmission complete interrupt */
		/* bit 6 in CR1 is responsible for enabling and disabling transmission complete interrupt */
		SET_BIT(USART1->USART_CR1, 6);

	#elif USART1_INTERRUPT == RXNE_INT_ENABLE

		/* enable receive data register is empty interrupt  */
		/* bit 5 in CR1 is responsible for enabling and disabling receive data register is empty interrupt */
		SET_BIT(USART1->USART_CR1, 5);

	#endif	/* nested if (interrupt) */

/***************************************************************************************/
/**************************************transmitter?*************************************/
/***************************************************************************************/
	#if   USART1_TRANSMITTER == TRANSMITTER_ENABLE

		/* enable the MCU to be a transmitter */
		/* bit 3 in CR1 is responsible for enabling and disabling transmitter */
		SET_BIT(USART1->USART_CR1, 3);

	#elif USART1_TRANSMITTER == TRANSMITTER_DISABLE

		/* disable the MCU to be a transmitter */
		/* bit 3 in CR1 is responsible for enabling and disabling transmitter */
		CLR_BIT(USART1->USART_CR1, 3);

	#endif	/* nested if (transmitter?)*/

/***************************************************************************************/
/***************************************receiver?***************************************/
/***************************************************************************************/
	#if   USART1_RECEIVER == RECEIVER_ENABLE

		/* enable the MCU to be a receiver */
		/* bit 2 in CR1 is responsible for enabling and disabling receiver */
		SET_BIT(USART1->USART_CR1, 2);

	#elif USART1_RECEIVER == RECEIVER_DISABLE

		/* disable the MCU to be a receiver */
		/* bit 2 in CR1 is responsible for enabling and disabling receiver */
		CLR_BIT(USART1->USART_CR1, 2);

	#endif	/* nested if(receiver?)*/

/***************************************************************************************/
/***************************************stop bit****************************************/
/***************************************************************************************/
	#if   USART1_STOP_BITS == ONE_STOP_BIT

		/* choose one stop bit */
		/* bits 12 and 13 in CR2 are responsible for choosing stop bit varieties */
		CLR_BIT(USART1->USART_CR2, 12);
		CLR_BIT(USART1->USART_CR2, 13);

	#elif USART1_STOP_BITS == HALF_STOP_BIT

		/* choose half stop bit */
		/* bits 12 and 13 in CR2 are responsible for choosing stop bit varieties */
		SET_BIT(USART1->USART_CR2, 12);
		CLR_BIT(USART1->USART_CR2, 13);

	#elif USART1_STOP_BITS == TWO_STOP_BIT

		/* choose two stop bit */
		/* bits 12 and 13 in CR2 are responsible for choosing stop bit varieties */
		CLR_BIT(USART1->USART_CR2, 12);
		SET_BIT(USART1->USART_CR2, 13);

	#elif USART1_STOP_BITS == ONE_AND_HALF_STOP_BIT

		/* choose one and half stop bit */
		/* bits 12 and 13 in CR2 are responsible for choosing stop bit varieties */
		SET_BIT(USART1->USART_CR2, 12);
		SET_BIT(USART1->USART_CR2, 13);


	#endif	/* nested if(stop bit) */


	/* set baud rate */
	/* register BRR is responsible for baud rate fraction(0:3) mantissa(4:15) */
	USART1->USART_BRR = (Loc_u32Mantissa << 4) | (Loc_u32Fraction / 100) ;

	/* enable USART */
	/* bit 13 in CR1 is responsible for enabling and disabling the USART */
	SET_BIT(USART1->USART_CR1, 13);

#elif USART1_STATUS == USART1_DISABLE

	/* disable USART */
	/* bit 13 in CR1 is responsible for enabling and disabling the USART */
	CLR_BIT(USART1->USART_CR1, 13);

#endif	/* main if(USART enable) */
}

void USART1_VidTransmitAsynchronous(uint8_t Copy_u8DataToTransmit,  void (*Copy_VidPtrToFunc)(uint8_t))
{
	/* set call back */
	if(Copy_VidPtrToFunc)	/* function safety */
		USART1_callBack = Copy_VidPtrToFunc;

	/* send data */
	/* put data on DR */
	USART1->USART_DR = Copy_u8DataToTransmit;
}

void USART1_VidReceiveAsynchronous(void (*Copy_VidPtrToFunc)(uint8_t))
{
	/* set call back */
	if(Copy_VidPtrToFunc)	/* function safety */
		USART1_callBack = Copy_VidPtrToFunc;
}

void USART1_VidTransmitSynchronous(uint8_t Copy_u8DataToTransmit)
{
	/* send data */
	/* put data on DR */
	USART1->USART_DR = Copy_u8DataToTransmit;

	/* wait to complete sending */
	while(GET_BIT(USART1->USART_SR, 6) == 0);

	/* clear the flag by writing 0 on the flag */
	CLR_BIT(USART1->USART_SR, 6);
}

void USART1_VidReceiveSynchronous(uint8_t *Copy_pu8DataToReceive)
{
	/* wait to receive */
	while(GET_BIT(USART1->USART_SR, 5) == 0);

	/* fill the buffer by data register*/
	*Copy_pu8DataToReceive = (uint8_t)USART1->USART_DR;

	/* clear the flag by writing 0 on the flag */
	CLR_BIT(USART1->USART_SR, 5);
}
