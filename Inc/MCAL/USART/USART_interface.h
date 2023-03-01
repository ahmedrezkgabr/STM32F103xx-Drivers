/********************************************************/
/*	Author		: Ahmed Rezk		        			*/
/*	Date		: 25 Feb 2023		        			*/
/*	file name	: USART_interface.h 		    		*/
/*	file module	: universal synch asynchronous Rx Tx	*/
/*	Version		: V01				        			*/
/********************************************************/

/* file guard */
#ifndef USART_INTERFACE__H_
#define USART_INTERFACE__H_

void USART1_VidInit(void);
void USART1_VidTransmitAsynchronous(uint8_t Copy_u8DataToTransmit,  void (*Copy_VidPtrToFunc)(uint8_t));
void USART1_VidTransmitSynchronous(uint8_t Copy_u8DataToTransmit);
void USART1_VidReceiveSynchronous(uint8_t *Copy_pu8DataToReceive);

#endif /* USART_INTERFACE__H_ */
