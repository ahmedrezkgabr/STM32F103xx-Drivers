/****************************************************/
/*	Author		: Ahmed Rezk		        		*/
/*	Date		: 12 Feb 2023		        		*/
/*	file name	: AFIO_interface.h	        		*/
/*	file module	: alternative function input output	*/
/*	Version		: V01				        		*/
/****************************************************/


/* File Guard */
#ifndef AFIO_INTERFACE__H_
#define AFIO_INTERFACE__H_

#define AFIO_EXTI_PORT_A	0b0000
#define AFIO_EXTI_PORT_B	0b0001
#define AFIO_EXTI_PORT_C	0b0010
#define AFIO_EXTI_PORT_D	0b0011
#define AFIO_EXTI_PORT_E	0b0100
#define AFIO_EXTI_PORT_F	0b0101
#define AFIO_EXTI_PORT_G	0b0110

void AFIO_VidSetEXTIConfig(uint8_t Copy_u8Line, uint8_t Copy_u8PortMap);

#endif /* AFIO_INTERFACE__H_ */
