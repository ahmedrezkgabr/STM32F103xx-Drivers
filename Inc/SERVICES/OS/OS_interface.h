/********************************************/
/*	Author		: Ahmed Rezk		        */
/*	Date		: 20 Feb 2023		        */
/*	file name	: OS_interface.h 		    */
/*	file module	: operating system		    */
/*	Version		: V01				        */
/********************************************/

/* file guard */
#ifndef	OS_INTERFACE__H_
#define OS_INTERFACE__H_

typedef enum
{
	TASK_READY,
	TASK_SUSPENDED
}task_state_t;
void OS_VidCreateTask(uint8_t Copy_u8Id, uint16_t Copy_u8Priodicity, void (*Copy_VidPtrToFunc)(void), uint8_t Copy_u8FirstDelay, task_state_t Copy_enState);
void OS_VidStart(void);



#endif	/* OS_INTERFACE__H_ */
