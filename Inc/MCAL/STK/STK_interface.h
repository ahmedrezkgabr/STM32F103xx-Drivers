/********************************************/
/*	Author		: Ahmed Rezk		        */
/*	Date		: 14 Feb 2023		        */
/*	file name	: STK_interface.h 		    */
/*	file module	: system tick			    */
/*	Version		: V02				        */
/********************************************/

/* File Guard */
#ifndef STK_INTERFACE__H_
#define STK_INTERFACE__H_

/* apply clock choice from configuration file
 * disable system tick interrupt
 * disable system tick
 * */
void STK_VidInit(void);

/* set load register
 * enable system tick
 * busy wait until flag == 1 */
void STK_VidSetBusyWait(uint32_t Copy_u32Ticks);

/* set load register
 * enable of interrupt and enable system tick
 * set call back */
void STK_VidSetIntervalSingle(uint32_t Copy_u32Ticks, void (*Copy_VidPtrToFunc)(void));

/* set load register
 * enable of interrupt and enable system tick
 * set call back */
void STK_VidSetIntervalPeriodic(uint32_t Copy_u32Ticks, void (*Copy_VidPtrToFunc)(void));

/* clear load register
 * clear value register */
void STK_VidStopTimer(void);

/* return load - value */
uint32_t STK_U32GetElapsedTime(void);

/* return value */
uint32_t STK_U32GetRemaininigTime(void);



#endif /* STK_INTERFACE__H_ */
