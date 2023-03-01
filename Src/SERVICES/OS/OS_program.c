/********************************************/
/*	Author		: Ahmed Rezk		        */
/*	Date		: 20 Feb 2023		        */
/*	file name	: OS_program.c	 		    */
/*	file module	: operating system		    */
/*	Version		: V01				        */
/********************************************/


/* INCLUDES */

/* Library */
#include "LIB/std_types.h"
#include "LIB/bit_math.h"

/* my own interface */
#include "SERVICES/OS/OS_interface.h"

/* Lower layers interfaces */
#include "MCAL/STK/STK_interface.h"

/* Private and configuration files */
#include "SERVICES/OS/OS_private.h"
#include "SERVICES/OS/OS_config.h"

/* null definition */
#ifndef NULL
#define NULL	((void *)0)
#endif

#define TICK_TIME	10

/* array of structures of tasks */
static task_t OS_tasks[NUMBE_OF_TASKES] = {NULL};
static uint8_t u8TickCounts = 0;
void OS_VidCreateTask(uint8_t Copy_u8Id, uint16_t Copy_u8Priodicity, void (*Copy_VidPtrToFunc)(void), uint8_t Copy_u8FirstDelay, task_state_t Copy_enState)
{
	OS_tasks[Copy_u8Id].priodicity = Copy_u8Priodicity;
	OS_tasks[Copy_u8Id].Fptr = Copy_VidPtrToFunc;
	OS_tasks[Copy_u8Id].firstDelay = Copy_u8FirstDelay;
	OS_tasks[Copy_u8Id].state = Copy_enState;
}

void OS_VidStart(void)
{
	/* initialization */
	STK_VidInit();

	/* tick = 1ms */
	/* call scheduler every 1ms*/
	STK_VidSetIntervalPeriodic(TICK_TIME, OS_VidScheduler);
}

void OS_VidKillTask(uint8_t Copy_u8Id)
{
	OS_tasks[Copy_u8Id].Fptr = NULL;
}

void OS_VidPauseTask(uint8_t Copy_u8Id)
{
	OS_tasks[Copy_u8Id].state = TASK_SUSPENDED;
}

void OS_VidResume(uint8_t Copy_u8Id)
{
	OS_tasks[Copy_u8Id].state = TASK_READY;
}

static void OS_VidScheduler(void)
{
	uint8_t Copy_u8Iterator = 0;

	/* iterate over tasks depending on its priority */
	for(; Copy_u8Iterator < NUMBE_OF_TASKES; Copy_u8Iterator++)
	{
		/* function safety */
		if((OS_tasks[Copy_u8Iterator].Fptr != NULL) && (OS_tasks[Copy_u8Iterator].state == TASK_READY))
		{
			if(u8TickCounts % OS_tasks[Copy_u8Iterator].priodicity == 0)
			{
				/* my turn has come */
				if(OS_tasks[Copy_u8Iterator].firstDelay == 0)
				{
					OS_tasks[Copy_u8Iterator].Fptr();
				}
				else
				{
					/* my turn does not have come */
					OS_tasks[Copy_u8Iterator].firstDelay--;
				}
			}
			u8TickCounts++;

		}
	}
}
