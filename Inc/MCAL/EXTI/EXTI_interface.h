/********************************************************/
/*	Author		: Ahmed Rezk		        			*/
/*	Date		: 12 Feb 2023		        			*/
/*	file name	: EXTI_interface.h	        			*/
/*	file module	: external interrupt					*/
/*	Version		: V01				        			*/
/********************************************************/

/* file guard */
#ifndef EXTI_INTERFACE__H_
#define EXTI_INTERFACE__H_

void EXTI_VidInit(void);
void EXTI_VidEnableExti(uint8_t Copy_u8Line);
void EXTI_VidDisableExti(uint8_t Copy_u8Line);
void EXTI_VidSwTrigger(uint8_t Copy_u8Line);
void EXTI_VidSetSignalLatch(uint8_t Copy_u8Line, uint8_t Copy_u8Mode);
void EXTI0_VidSetCallBack(void (*Copy_VidPtrToFunc)(void));
void EXTI1_VidSetCallBack(void (*Copy_VidPtrToFunc)(void));

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



#endif	/* EXTI_INTERFACE__H_ */
