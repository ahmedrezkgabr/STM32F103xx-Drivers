/****************************************************/
/*	Author		: Ahmed Rezk		        		*/
/*	Date		: 21 Feb 2023		        		*/
/*	file name	: DMA_program.c 		    		*/
/*	file module	: direct memory access controller	*/
/*	Version		: V01				        		*/
/****************************************************/

/* INCLUDES */

/* Library */
#include "LIB/std_types.h"
#include "LIB/bit_math.h"

/* Lower layers interfaces */
/* None */

/* My own interface */
#include "MCAL/DMA/DMA_interface.h"

/* Private and configuration files */
#include "MCAL/DMA/DMA_private.h"
#include "MCAL/DMA/DMA_config.h"

/**************************************************************/
/** pointers to DMA channels from 1 to 7 call pack functions **/
/**************************************************************/
static void (*DMA_Channel1_callBack)(void) = NULL;
static void (*DMA_Channel2_callBack)(void) = NULL;
static void (*DMA_Channel3_callBack)(void) = NULL;
static void (*DMA_Channel4_callBack)(void) = NULL;
static void (*DMA_Channel5_callBack)(void) = NULL;
static void (*DMA_Channel6_callBack)(void) = NULL;
static void (*DMA_Channel7_callBack)(void) = NULL;


void DMA_VidSetConfiguration(uint8_t Copy_u8Channel ,uint8_t Copy_u8Direction ,uint8_t Copy_u8CircularMode ,uint8_t Copy_u8Pinc ,uint8_t Copy_u8Minc ,uint8_t Copy_u8MemSize ,uint8_t Copy_u8PerSize ,uint8_t Copy_u8ChannelPriority)
{
	/* disable DMA */
	/* bit 0 in DMA_CCRx is responsible for enabling and disabling DMA channel */
	CLR_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 0);

	/* set direction */
	/* bits 4, 14 in DMA_CCRx are responsible for choosing the direction of a channel */
	if(Copy_u8Direction == MEM_TO_MEM)
		SET_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 14);
	else if(Copy_u8Direction == PREI_TO_MEM)
		CLR_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 4);
	else if(Copy_u8Direction == MEM_TO_PERI)
		SET_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 4);

	/* set circular */
	/* bit 5 in DMA_CCRx is responsible for enabling and disabling circular mode for a channel */
	if(Copy_u8CircularMode == DMA_ENABLE_CIRCULAR)
		SET_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 5);
	else
		CLR_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 5);

	/* set Peripheral increment */
	/* bit 6 in DMA_CCRx is responsible for enabling and disabling peripheral increment for a channel (source if memory to memory) */
	if(Copy_u8Pinc == PERIPHERAL_INCREMENT_ENABLE)
		SET_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 6);
	else
		CLR_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 6);

	/* set memory increment */
	/* bit 7 in DMA_CCRx is responsible for enabling and disabling memory increment for a channel */
	if(Copy_u8Minc == MEM_INCREMENT_ENABLE)
		SET_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 7);
	else
		CLR_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 7);

	/* set peripheral size (source if memory to memory) */
	/* bits 8, 9 in DMA_CCRx are responsible for choosing the size of an element in a channel */
	if(Copy_u8PerSize == BYTE)
	{
		CLR_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 8);
		CLR_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 9);
	}
	else if(Copy_u8PerSize == HALF_WORD)
	{
		SET_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 8);
		CLR_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 9);
	}
	else if(Copy_u8PerSize == WORD)
	{
		CLR_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 8);
		SET_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 9);
	}

	/* set memory size */
	/* bits 10, 11 in DMA_CCRx are responsible for choosing the size of an element in a channel */
	if(Copy_u8MemSize == BYTE)
	{
		CLR_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 10);
		CLR_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 11);
	}
	else if(Copy_u8MemSize == HALF_WORD)
	{
		SET_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 10);
		CLR_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 11);
	}
	else if(Copy_u8MemSize == WORD)
	{
		CLR_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 10);
		SET_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 11);
	}


	/* set channel priority */
	/* bits 12, 13 in DMA_CCRx are responsible for choosing the priority a channel */
	if(Copy_u8ChannelPriority == DMA_LOW)
	{
		CLR_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 12);
		CLR_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 13);
	}
	else if (Copy_u8ChannelPriority == DMA_MEDIUM)
	{
		SET_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 12);
		CLR_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 13);
	}
	else if (Copy_u8ChannelPriority == DMA_HIGH)
	{
		CLR_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 12);
		SET_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 13);
	}
	else if (Copy_u8ChannelPriority == DMA_VERY_HIGH)
	{
		SET_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 12);
		SET_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 13);
	}
}

void DMA_VidEnableChannel(uint8_t Copy_u8Channel)
{
	/* clear the 4 flags for the given channel */
	/* IFCR is responsible for clearing flags by writing 1 on the flag */
	uint8_t Loc_u8StartFlag = Copy_u8Channel * 4;
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CGIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CGIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CHTIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag);		/* CTEIF */

	/* enable DMA */
	/* bit 0 in DMA_CCRx is responsible for enabling and disabling DMA channel */
	SET_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 0);
}

void DMA_VidDisableChannel(uint8_t Copy_u8Channel)
{
	/* disable DMA */
	/* bit 0 in DMA_CCRx is responsible for enabling and disabling DMA channel */
	CLR_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), 0);
}

void DMA_VidSetAddress(uint8_t Copy_u8Channel ,uint32_t * pu32PeripheralAddress ,uint32_t * pu32MemoryAddress ,uint16_t Copy_u16NDT)
{
	/* CPARx is responsible for holding the address of peripheral (source if memory to memory) */
	DMA->channels[Copy_u8Channel].DMA_CPAR = (uint32_t)pu32PeripheralAddress;

	/* CMARx is responsible for holding the address of memory */
	DMA->channels[Copy_u8Channel].DMA_CMAR = (uint32_t)pu32MemoryAddress;

	/* CNDTR is responsible for holding the size of the data block */
	DMA->channels[Copy_u8Channel].DMA_CNDTR = (uint16_t)Copy_u16NDT;
}

void DMA_VidInterruptEnable(uint8_t Copy_u8Channel, uint8_t Copy_u8IntSource)
{
	/* enable interrupt */
	/* bits 1, 2, and 3 in CCRx are responsible for enabling interrupt */
	/* Copy_u8IntSource will be 1, 2, or 3 => TCIE, HTIE, or TEIE respectively */
	SET_BIT((DMA->channels[Copy_u8Channel].DMA_CCR), Copy_u8IntSource);
}

/*****************************/
/** set call back functions **/
/*****************************/
void DMA_VidSetCallBackChannel1(void (*Copy_VidPtrToFunc)(void))
{
	if(Copy_VidPtrToFunc)
		DMA_Channel1_callBack = Copy_VidPtrToFunc;
}

void DMA_VidSetCallBackChannel2(void (*Copy_VidPtrToFunc)(void))
{
	if(Copy_VidPtrToFunc)
		DMA_Channel2_callBack = Copy_VidPtrToFunc;
}

void DMA_VidSetCallBackChannel3(void (*Copy_VidPtrToFunc)(void))
{
	if(Copy_VidPtrToFunc)
		DMA_Channel3_callBack = Copy_VidPtrToFunc;
}

void DMA_VidSetCallBackChannel4(void (*Copy_VidPtrToFunc)(void))
{
	if(Copy_VidPtrToFunc)
		DMA_Channel4_callBack = Copy_VidPtrToFunc;
}

void DMA_VidSetCallBackChannel5(void (*Copy_VidPtrToFunc)(void))
{
	if(Copy_VidPtrToFunc)
		DMA_Channel5_callBack = Copy_VidPtrToFunc;
}

void DMA_VidSetCallBackChannel6(void (*Copy_VidPtrToFunc)(void))
{
	if(Copy_VidPtrToFunc)
		DMA_Channel6_callBack = Copy_VidPtrToFunc;
}

void DMA_VidSetCallBackChannel7(void (*Copy_VidPtrToFunc)(void))
{
	if(Copy_VidPtrToFunc)
		DMA_Channel7_callBack = Copy_VidPtrToFunc;
}

/*******************************/
/** Interrupt request handler **/
/*******************************/
void DMA1_Channel1_IRQHandler(void)
{
	if(DMA_Channel1_callBack)
		DMA_Channel1_callBack();

	/* clear the 4 flags for the given channel */
	/* IFCR is responsible for clearing flags by writing 1 on the flag */
	uint8_t Loc_u8StartFlag = 0;
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CGIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CGIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CHTIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag);		/* CTEIF */
}

void DMA1_Channel2_IRQHandler(void)
{
	if(DMA_Channel2_callBack)
		DMA_Channel2_callBack();

	/* clear the 4 flags for the given channel */
	/* IFCR is responsible for clearing flags by writing 1 on the flag */
	uint8_t Loc_u8StartFlag = 4;
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CGIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CGIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CHTIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag);		/* CTEIF */
}

void DMA1_Channel3_IRQHandler(void)
{
	if(DMA_Channel3_callBack)
		DMA_Channel3_callBack();

	/* clear the 4 flags for the given channel */
	/* IFCR is responsible for clearing flags by writing 1 on the flag */
	uint8_t Loc_u8StartFlag = 8;
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CGIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CGIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CHTIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag);		/* CTEIF */
}

void DMA1_Channel4_IRQHandler(void)
{
	if(DMA_Channel4_callBack)
		DMA_Channel4_callBack();

	/* clear the 4 flags for the given channel */
	/* IFCR is responsible for clearing flags by writing 1 on the flag */
	uint8_t Loc_u8StartFlag = 12;
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CGIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CGIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CHTIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag);		/* CTEIF */
}

void DMA1_Channel5_IRQHandler(void)
{
	if(DMA_Channel5_callBack)
		DMA_Channel5_callBack();

	/* clear the 4 flags for the given channel */
	/* IFCR is responsible for clearing flags by writing 1 on the flag */
	uint8_t Loc_u8StartFlag = 16;
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CGIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CGIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CHTIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag);		/* CTEIF */
}

void DMA1_Channel6_IRQHandler(void)
{
	if(DMA_Channel6_callBack)
		DMA_Channel6_callBack();

	/* clear the 4 flags for the given channel */
	/* IFCR is responsible for clearing flags by writing 1 on the flag */
	uint8_t Loc_u8StartFlag = 20;
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CGIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CGIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CHTIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag);		/* CTEIF */
}

void DMA1_Channel7_IRQHandler(void)
{
	if(DMA_Channel7_callBack)
		DMA_Channel7_callBack();

	/* clear the 4 flags for the given channel */
	/* IFCR is responsible for clearing flags by writing 1 on the flag */
	uint8_t Loc_u8StartFlag = 24;
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CGIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CGIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag++);	/* CHTIF */
	SET_BIT((DMA->DMA_IFCR), Loc_u8StartFlag);		/* CTEIF */
}
