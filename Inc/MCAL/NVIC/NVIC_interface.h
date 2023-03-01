/********************************************************/
/*	Author		: Ahmed Rezk		        			*/
/*	Date		: 11 Feb 2023		        			*/
/*	file name	: NVIC_interface.h		        		*/
/*	file module	: nested vector interrupt controller	*/
/*	Version		: V01				        			*/
/********************************************************/

/* file guard */
#ifndef NVIC_INTERFACE__H_
#define NVIC_INTERFACE__H_

void NVIC_VidEnableInterrupt(uint8_t Copy_u8IntId);
void NVIC_VidDisableInterrupt(uint8_t Copy_u8IntId);

void NVIC_VidSetPendingFlag(uint8_t Copy_u8IntId);
void NVIC_VidClrPendingFlag(uint8_t Copy_u8IntId);

uint8_t NVIC_U8GetActiveFlag(uint8_t Copy_u8IntId);

void NVIC_VidSetInterruptPriority(sint8_t Copy_s8IntId, sint8_t Copy_s8GroupPriority, sint8_t Copy_s8SubPriority, uint32_t Copy_u32GrpoupFormula);


/* register values (temporary)*/
/*X group bit, Y sub bit */
#define GROUP_XXXX	0x05FA0300
#define GROUP_XXXY	0x05FA0400
#define GROUP_XXYY	0x05FA0500
#define GROUP_XYYY	0x05FA0600
#define GROUP_YYYY	0x05FA0700

#endif /* NVIC_INTERFACE__H_ */
