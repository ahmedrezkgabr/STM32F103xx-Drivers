/********************************************************/
/*	Author		: Ahmed Rezk		        			*/
/*	Date		: 25 Feb 2023		        			*/
/*	file name	: USART_config.h 		    			*/
/*	file module	: universal synch asynchronous Rx Tx	*/
/*	Version		: V01				        			*/
/********************************************************/

/* file guard */
#ifndef USART_CONFIG__H_
#define USART_CONFIG__H_

/* this frequency depending on RCC calculations */
#define F_CPU				8000000
#define USART1_BAUD_RATE	9600

/* options:
 * USART1_ENABLE
 * USART1_DISABLE
 * */
#define USART1_STATUS	USART1_ENABLE

/* options:
 * USART_8_BITS
 * USART_9_BITS
 * */
#define USART1_DATA_SIZE	USART_8_BITS

/* options:
 * PARITY_DISABLE
 * EVEN_PARITY
 * ODD_PARITY
 * */
#define USART1_PARITY_BIT	PARITY_DISABLE

/* options:
 * INT_DISABLE
 * TXE_INT_ENABLE		// transmit data register is empty interrupt
 * TCE_INT_ENABLE		// transmission complete interrupt
 * RXNE_INT_ENABLE		// receive data register is empty interrupt
 * */
#define USART1_INTERRUPT	TXE_INT_ENABLE

/* options:
 * TRANSMITTER_ENABLE
 * TRANSMITTER_DISABLE
 * */
#define USART1_TRANSMITTER TRANSMITTER_ENABLE

/* options:
 * RECEIVER_ENABLE
 * RECEIVER_DISABLE
 * */
#define USART1_RECEIVER	RECEIVER_ENABLE

/* options:
 * HALF_STOP_BIT
 * ONE_STOP_BIT
 * ONE_AND_HALF_STOP_BIT
 * TWO_STOP_BIT
 * */
#define USART1_STOP_BITS	ONE_STOP_BIT


#endif /* USART_CONFIG__H_ */
