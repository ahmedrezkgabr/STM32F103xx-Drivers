/********************************************************/
/*	Author		: Ahmed Rezk		        			*/
/*	Date		: 11 Feb 2023		        			*/
/*	file name	: NVIC_program.c		        		*/
/*	file module	: nested vector interrupt controller	*/
/*	Version		: V01				        			*/
/********************************************************/

/* INCLUDES */

/* Library */
#include "LIB/std_types.h"
#include "LIB/bit_math.h"

/* Lower layers interfaces */
/* None */

/* My own interface */
#include "MCAL/NVIC/NVIC_interface.h"

/* Private and configuration files */
#include "MCAL/NVIC/NVIC_private.h"
#include "MCAL/NVIC/NVIC_config.h"

void NVIC_VidEnableInterrupt(uint8_t Copy_u8IntId)
{
	/* (/) Indicates the offset of the register to the first in his group and (%) indicates the bit in the register */
	uint8_t Loc_u8RegisterNumber = Copy_u8IntId / 32;
	uint8_t Loc_u8BitNumber = Copy_u8IntId % 32;

	/* because it is 4-byte addressable (the register of the same family can be looked like an array its index is the number of the register */
	SET_BIT(NVIC_ISER[Loc_u8RegisterNumber], Loc_u8BitNumber);
}

void NVIC_VidDisableInterrupt(uint8_t Copy_u8IntId)
{
	/* (/) Indicates the offset of the register to the first in his group and (%) indicates the bit in the register */
	uint8_t Loc_u8RegisterNumber = Copy_u8IntId / 32;
	uint8_t Loc_u8BitNumber = Copy_u8IntId % 32;

	/* because it is 4-byte addressable (the register of the same family can be looked like an array its index is the number of the register */
	SET_BIT(NVIC_ICER[Loc_u8RegisterNumber], Loc_u8BitNumber);
}

void NVIC_VidSetPendingFlag(uint8_t Copy_u8IntId)
{
	/* (/) Indicates the offset of the register to the first in his group and (%) indicates the bit in the register */
	uint8_t Loc_u8RegisterNumber = Copy_u8IntId / 32;
	uint8_t Loc_u8BitNumber = Copy_u8IntId % 32;

	/* because it is 4-byte addressable (the register of the same family can be looked like an array its index is the number of the register */
	SET_BIT(NVIC_ISPR[Loc_u8RegisterNumber], Loc_u8BitNumber);
}
void NVIC_VidClrPendingFlag(uint8_t Copy_u8IntId)
{
	/* (/) Indicates the offset of the register to the first in his group and (%) indicates the bit in the register */
	uint8_t Loc_u8RegisterNumber = Copy_u8IntId / 32;
	uint8_t Loc_u8BitNumber = Copy_u8IntId % 32;

	/* because it is 4-byte addressable (the register of the same family can be looked like an array its index is the number of the register */
	SET_BIT(NVIC_ICPR[Loc_u8RegisterNumber], Loc_u8BitNumber);
}
uint8_t NVIC_U8GetActiveFlag(uint8_t Copy_u8IntId)
{
	uint8_t Loc_u8Result = 0;

	/* (/) Indicates the offset of the register to the first in his group and (%) indicates the bit in the register */
	uint8_t Loc_u8RegisterNumber = Copy_u8IntId / 32;
	uint8_t Loc_u8BitNumber = Copy_u8IntId % 32;

	/* because it is 4-byte addressable (the register of the same family can be looked like an array its index is the number of the register */
	Loc_u8Result = GET_BIT(NVIC_IABR[Loc_u8RegisterNumber], Loc_u8BitNumber);

	return Loc_u8Result;
}

void NVIC_VidSetInterruptPriority(sint8_t Copy_s8IntId, sint8_t Copy_s8GroupPriority, sint8_t Copy_s8SubPriority, uint32_t Copy_u32GrpoupFormula)
{
	/*
	 * (Copy_u8GrpoupFormula - 0x05FA0300) / 0x100) = number of sub priority bits in the s.w priority
	 * shift left the group priority with the number of sub priority bits
	 * or the shifted group priority with the sub priority to formulate the 4-bits of the s.w priority
	 * */
	uint32_t Loc_u8Priority = Copy_s8SubPriority | (Copy_s8GroupPriority << ((Copy_u32GrpoupFormula - 0x05FA0300) / 0x100));

	/* core peripheral */
	if (Copy_s8IntId < 0)
	{
		/* later */
	}

	/* external peripheral */
	else
	{
		NVIC_IPR[Copy_s8IntId] = (uint8_t)(Loc_u8Priority << 4);
	}

	SCB_AIRCR = Copy_u32GrpoupFormula;
}





























