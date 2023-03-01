/********************************************/
/*	Author		: Ahmed Rezk		        */
/*	Date		: 13 Feb 2023		        */
/*	file name	: STK_program.c 		    */
/*	file module	: system tick			    */
/*	Version		: V01				        */
/********************************************/


/* INCLUDES */

/* Library */
#include "LIB/std_types.h"
#include "LIB/bit_math.h"

/* Lower layers interfaces */
/* None */

/* My own interface */
#include "MCAL/STK/STK_interface.h"

/* Private and configuration files */
#include "MCAL/STK/STK_private.h"
#include "MCAL/STK/STK_config.h"


#ifndef NULL
#define NULL ((void *)0)
#endif

static void (*STK_callBack)(void) = NULL;


/* apply clock choice from configuration file
 * disable system tick interrupt
 * disable system tick
 * */
void STK_VidInit(void)
{
	/* apply clock choice from configuration file */
	/* bit 2 in STK_CTRL is responsible for choosing the signal source clock */
	#if (STK_CLKSOURCE == STK_AHB)
		SET_BIT(STK_CTRL, 2);

	#else
		CLR_BIT(STK_CTRL, 2);

	#endif

	/* disable system tick interrupt */
	/* bit 1 in STK_CTRL is responsible for enabling and disabling the interrupt */
	CLR_BIT(STK_CTRL, 1);

	/* disable system tick */
	/* bit 0 in STK_CTRL is responsible for enabling and disabling the system tick */
	CLR_BIT(STK_CTRL, 0);
}


/* set load register
 * enable system tick
 * busy wait until flag == 1 */
void STK_VidSetBusyWait(uint32_t Copy_u32Ticks)
{
	/* set load register */
	STK_LOAD = Copy_u32Ticks;

	/* enable system tick */
	/* bit 0 in STK_CTRL is responsible for enabling and disabling the system tick */
	SET_BIT(STK_CTRL, 0);

	/* busy wait until flag == 1 */
	/* bit 16 in STK_CTRL is the flag bit */
	while (!GET_BIT(STK_CTRL, 16));
	//GET_BIT(STK_CTRL, 16);

}

/* set load register
 * enable of interrupt and enable system tick
 * set call back */
void STK_VidSetIntervalSingle(uint32_t Copy_u32Ticks, void (*Copy_VidPtrToFunc)(void))
{
	/**/
	CLR_BIT(STK_CTRL, 0);
	STK_VAL = 0;

	/* set load register */
	STK_LOAD = Copy_u32Ticks;

	/* enable system tick */
	/* bit 0 in STK_CTRL is responsible for enabling and disabling the system tick */
	SET_BIT(STK_CTRL, 0);

	/* if the passed pointer is not point to null*/
	if(Copy_VidPtrToFunc)
		/* set the call back global pointer with the passed pointer */
		STK_callBack = Copy_VidPtrToFunc;

	SET_BIT(STK_CTRL, 1);
}

/* set load register
 * enable of interrupt and enable system tick
 * set call back */
void STK_VidSetIntervalPeriodic(uint32_t Copy_u32Ticks, void (*Copy_VidPtrToFunc)(void))
{
	/* set load register */
	STK_LOAD = Copy_u32Ticks;

	/* enable system tick */
	/* bit 0 in STK_CTRL is responsible for enabling and disabling the system tick */
	SET_BIT(STK_CTRL, 0);

	/* if the passed pointer is not point to null*/
	if(Copy_VidPtrToFunc)
		/* set the call back global pointer with the passed pointer */
		STK_callBack = Copy_VidPtrToFunc;

	/* enable the interrupt */
	SET_BIT(STK_CTRL, 1);
}

/* clear load register
 * clear value register */
void STK_VidStopTimer(void)
{
	/* clear load register */
	/* cleared by writing 0 */
	STK_LOAD = 0;

	/* clear value register */
	/* cleared by writing any value */
	STK_VAL = 0;
}

/* return load register minus(-) value register */
uint32_t STK_U32GetElapsedTime(void)
{
	/* return load register minus(-) value register */
	return (STK_LOAD - STK_VAL);
}

/* return value register */
uint32_t STK_U32GetRemaininigTime(void)
{
	/* return value register */
	return (STK_VAL);
}

/* check that callBack has been set
 * if not null call call back function */
void SysTick_Handler(void)
{
	/* check that callBack has been set
	 * if not null call call back function */
	if (STK_callBack)
		STK_callBack();
}
