/********************************************/
/*	Author		: Ahmed Rezk		        */
/*	Date		: 22 Feb 2023		        */
/*	file name	: STP_program.c			    */
/*	file module	: serial to parallel        */
/********************************************/


/* INCLUDES */

/* Library */
#include "LIB/std_types.h"
#include "LIB/bit_math.h"

/* Lower layers interfaces */
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/STK/STK_interface.h"

/* My own interface */
#include "HAL/STP/STP_interface.h"

/* Private and configuration files */
#include "HAL/STP/STP_config.h"
#include "HAL/STP/STP_private.h"


/* send bit by bit starting from MSB */
void STP_VidSendSynchronous(uint8_t Copy_u8Data)
{
	sint8_t Loc_s8Iterator;
	uint8_t Loc_u8Bit;

	/* iterate over the bits from bit-7 to bit-0 */
	for(Loc_s8Iterator = STP_NUMBER_OF_PARALLEL_DATA_PINS - 1; Loc_s8Iterator >= 0; Loc_s8Iterator--)
	{
		/* get bit value */
		Loc_u8Bit = GET_BIT(Copy_u8Data, Loc_s8Iterator);

		/* send the bit on serial data pin */
		/* STP_SERIAL_DATA == PORT_x,PINx */
		GPIO_VidSetPinValue(STP_SERIAL_DATA, Loc_u8Bit);

		/* send pulse to shift clock */
		/* STP_SHIFT_CLOCK == PORT_x,PINx */
		GPIO_VidSetPinValue(STP_SHIFT_CLOCK, HIGH);
		STK_VidSetBusyWait(1);
		GPIO_VidSetPinValue(STP_SHIFT_CLOCK, LOW);
		STK_VidSetBusyWait(1);

	}

	/* send pulse to storage clock */
	/* STP_STORAGE_CLOCK == PORT_x,PINx */
	GPIO_VidSetPinValue(STP_STORAGE_CLOCK, HIGH);
	STK_VidSetBusyWait(1);
	GPIO_VidSetPinValue(STP_STORAGE_CLOCK, LOW);
	STK_VidSetBusyWait(1);
}
