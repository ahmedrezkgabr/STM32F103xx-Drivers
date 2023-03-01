/********************************************/
/*	Author		: Ahmed Rezk		        */
/*	Date		: 20 Feb 2023		        */
/*	file name	: OS_private.h	 		    */
/*	file module	: operating system		    */
/*	Version		: V01				        */
/********************************************/

/* file guard */
#ifndef	OS_PRIVATE__H_
#define OS_PRIVATE__H_

typedef struct
{
	uint16_t priodicity;
	void (*Fptr)(void);
	uint8_t firstDelay;
	task_state_t state;
	// uint8_t state;
} task_t;
static void OS_VidScheduler(void);

#endif	/* OS_PRIVATE__H_ */
