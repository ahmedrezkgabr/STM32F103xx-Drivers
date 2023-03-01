/****************************************************/
/*	Author		: Ahmed Rezk		        		*/
/*	Date		: 12 Feb 2023		        		*/
/*	file name	: AFIO_program.c 		    		*/
/*	file module	: alternative function input output	*/
/*	Version		: V01				        		*/
/****************************************************/

/* INCLUDES */

/* Library */
#include "LIB/std_types.h"
#include "LIB/bit_math.h"

/* Lower layers interfaces */
/* None */

/* My own interface */
#include "MCAL/AFIO/AFIO_interface.h"

/* Private and configuration files */
#include "MCAL/AFIO/AFIO_private.h"
#include "MCAL/AFIO/AFIO_config.h"



void AFIO_VidSetEXTIConfig(uint8_t Copy_u8Line, uint8_t Copy_u8PortMap)
{
	uint8_t Loc_u8RegisterIndex = 0;
	uint8_t Loc_u8Offset = 0;

	Loc_u8RegisterIndex = Copy_u8Line / 4;

	Loc_u8Offset = Copy_u8Line % 4;

	AFIO->AFIO_EXTICR[Loc_u8RegisterIndex] &=	~(0b1111 << (Loc_u8Offset * 4));
	AFIO->AFIO_EXTICR[Loc_u8RegisterIndex] |=	 (Copy_u8PortMap << (Loc_u8Offset * 4));
}

///* clear the corresponding 4 bits */
//			GPIOB_CRH &= ~(0b1111 << (Copy_u8Pin * 4));
//
//			/* write the value of the mode */
//			GPIOB_CRH |= (Copy_u8Mode << (Copy_u8Pin * 4));
