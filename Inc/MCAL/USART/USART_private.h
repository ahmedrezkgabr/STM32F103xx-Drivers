/********************************************************/
/*	Author		: Ahmed Rezk		        			*/
/*	Date		: 25 Feb 2023		        			*/
/*	file name	: USART_private.h 		    			*/
/*	file module	: universal synch asynchronous Rx Tx	*/
/*	Version		: V01				        			*/
/********************************************************/

/* file guard */
#ifndef USART_PRIVATE__H_
#define USART_PRIVATE__H_

/* register definition */
typedef struct
{
	volatile uint32_t USART_SR;		/* status register */
	volatile uint32_t USART_DR;		/* data register */
	volatile uint32_t USART_BRR;	/* baud rate register */
	volatile uint32_t USART_CR1;	/* control register 1 */
	volatile uint32_t USART_CR2;	/* control register 2 */
	volatile uint32_t USART_CR3;	/* control register 3 */
	volatile uint32_t USART_GTPR;	/* guard time and pre-scaler register */
} USART_t;

#define USART1_BASE_ADDRESS		0x40013800
#define USART1					((volatile USART_t*)USART1_BASE_ADDRESS)

static void (*USART1_callBack)(uint8_t) = NULL;

#define USART_8_BITS			10
#define USART_9_BITS			11

#define  PARITY_DISABLE			20
#define  EVEN_PARITY			21
#define  ODD_PARITY				22

#define  INT_DISABLE			30
#define  TXE_INT_ENABLE			31
#define  TCE_INT_ENABLE			32
#define  RXNE_INT_ENABLE		33

#define  TRANSMITTER_ENABLE		40
#define  TRANSMITTER_DISABLE	41

#define  RECEIVER_ENABLE		50
#define  RECEIVER_DISABLE		51

#define  HALF_STOP_BIT			60
#define  ONE_STOP_BIT			61
#define  ONE_AND_HALF_STOP_BIT	62
#define  TWO_STOP_BIT			63

#endif /* USART_PRIVATE__H_ */
