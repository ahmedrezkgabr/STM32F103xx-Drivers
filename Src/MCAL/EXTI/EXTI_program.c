/********************************************************/
/*	Author		: Ahmed Rezk		        			*/
/*	Date		: 12 Feb 2023		        			*/
/*	file name	: EXTI_program.c	        			*/
/*	file module	: external interrupt 					*/
/*	Version		: V01				        			*/
/********************************************************/

/* INCLUDES */

/* Library */
#include "LIB/std_types.h"
#include "LIB/bit_math.h"

/* Lower layers interfaces */
/* None */

/* My own interface */
#include "MCAL/EXTI/EXTI_interface.h"

/* Private and configuration files */
#include "MCAL/EXTI/EXTI_config.h"
#include "MCAL/EXTI/EXTI_private.h"

/* choose the line to be
 * choose the sense mode
 * disable the interrupt */
void EXTI_VidInit(void)
{
	/* choose the sense mode */
	/* registers EXTI_FTSR and EXTI_RTSR are responsible for falling and rising for each line respectively */
#if EXTI_MODE == FALLING_EDGE
	SET_BIT((EXTI->EXTI_FTSR), EXTI_LINE);

#elif EXTI_MODE == RISING_EDGE
	SET_BIT((EXTI->EXTI_RTSR), EXTI_LINE);

#elif EXTI_MODE == ON_CHANGE
	/* falling and rising in the same time */
	SET_BIT((EXTI->EXTI_FTSR), EXTI_LINE);
	SET_BIT((EXTI->EXTI_RTSR), EXTI_LINE);

#else
	#error "wrong external interrupt mode"

#endif

	/* disable the interrupt */
	/* register EXTI_IMR is responsible for disabling and enabling the interrupt */
	//EXTI->EXTI_IMR = 0x00000000;
}

void EXTI_VidSetSignalLatch(uint8_t Copy_u8Line, uint8_t Copy_u8Mode)
{
	/* choose the sense mode */
	/* registers EXTI_FTSR and EXTI_RTSR are responsible for falling and rising for each line respectively */
	switch(Copy_u8Mode)
	{
	case FALLING_EDGE	:
		SET_BIT((EXTI->EXTI_FTSR), Copy_u8Line);
		break;

	case RISING_EDGE	:
		SET_BIT((EXTI->EXTI_RTSR), Copy_u8Line);
		break;

	case ON_CHANGE		:
		/* falling and rising in the same time */
		SET_BIT((EXTI->EXTI_FTSR), Copy_u8Line);
		SET_BIT((EXTI->EXTI_RTSR), Copy_u8Line);
		break;

	default	:
		/* error */
		break;
	}
}

void EXTI_VidEnableExti(uint8_t Copy_u8Line)
{
	/* enable the external interrupt line */
	/* register EXTI_IMR is responsible for enabling and disabling the line interrupt */
	SET_BIT((EXTI->EXTI_IMR), Copy_u8Line);
}

void EXTI_VidDisableExti(uint8_t Copy_u8Line)
{
	/* disable the external interrupt line */
	/* register EXTI_IMR is responsible for enabling and disabling the line interrupt */
	CLR_BIT((EXTI->EXTI_IMR), Copy_u8Line);
}

void EXTI_VidSwTrigger(uint8_t Copy_u8Line)
{
//	/* If the interrupt is enabled, */
//	/* register EXTI_SWIER is responsible for software triggering */
//	SET_BIT((EXTI->EXTI_SWIER), Copy_u8Line);
}

void EXTI0_VidSetCallBack(void (*Copy_VidPtrToFunc)(void))
{
	/* if the passed pointer is not point to null*/
	if(Copy_VidPtrToFunc)
		/* set the call back global pointer with the passed pointer */
		EXTI0_callBack = Copy_VidPtrToFunc;
}

void EXTI1_VidSetCallBack(void (*Copy_VidPtrToFunc)(void))
{
	/* if the passed pointer is not point to null*/
	if(Copy_VidPtrToFunc)
		/* set the call back global pointer with the passed pointer */
		EXTI1_callBack = Copy_VidPtrToFunc;
}

void EXTI0_IRQHandler(void)
{
	if(EXTI0_callBack)
		EXTI0_callBack();

	SET_BIT((EXTI->EXTI_PR), 0);
}

void EXTI1_IRQHandler(void)
{
	if(EXTI1_callBack)
		EXTI1_callBack();

	SET_BIT((EXTI->EXTI_PR), 1);
}



