/********************************************/
/*	Author		: Ahmed Rezk		        */
/*	Date		: 18 Feb 2023		        */
/*	file name	: LEDMAT_program.c		    */
/*	file module	: led matrix			    */
/*	Version		: V01				        */
/********************************************/


/* INCLUDES */

/* Library */
#include "LIB/std_types.h"
#include "LIB/bit_math.h"

/* Lower layers interfaces */
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/STK/STK_interface.h"

/* My own interface */
#include "HAL/LEDMAT/LEDMAT_interface.h"

/* Private and configuration files */
#include "HAL/LEDMAT/LEDMAT_private.h"
#include "HAL/LEDMAT/LEDMAT_config.h"



void LEDMAT_VidInit(void)
{
	/* all 16 pins are output */
	GPIO_VidSetPinMode(LEDMAT_COL0_PIN, 0b0010);
	GPIO_VidSetPinMode(LEDMAT_COL1_PIN, 0b0010);
	GPIO_VidSetPinMode(LEDMAT_COL2_PIN, 0b0010);
	GPIO_VidSetPinMode(LEDMAT_COL3_PIN, 0b0010);
	GPIO_VidSetPinMode(LEDMAT_COL4_PIN, 0b0010);
	GPIO_VidSetPinMode(LEDMAT_COL5_PIN, 0b0010);
	GPIO_VidSetPinMode(LEDMAT_COL6_PIN, 0b0010);
	GPIO_VidSetPinMode(LEDMAT_COL7_PIN, 0b0010);

	GPIO_VidSetPinMode(LEDMAT_ROW0_PIN, 0b0010);
	GPIO_VidSetPinMode(LEDMAT_ROW1_PIN, 0b0010);
	GPIO_VidSetPinMode(LEDMAT_ROW2_PIN, 0b0010);
	GPIO_VidSetPinMode(LEDMAT_ROW3_PIN, 0b0010);
	GPIO_VidSetPinMode(LEDMAT_ROW4_PIN, 0b0010);
	GPIO_VidSetPinMode(LEDMAT_ROW5_PIN, 0b0010);
	GPIO_VidSetPinMode(LEDMAT_ROW6_PIN, 0b0010);
	GPIO_VidSetPinMode(LEDMAT_ROW7_PIN, 0b0010);
}


void LEDMAT_VidDisplay(uint8_t * Copy_u8Data)
{
	uint8_t Loc_u8Iterator = 0;
	/* disable all columns */
	LEDMAT_VidDiableAllCol();
	LEDMAT_VidSetRawValue(Copy_u8Data[Loc_u8Iterator++]);
	GPIO_VidSetPinValue(LEDMAT_COL0_PIN, LOW);
	STK_VidSetBusyWait(TIME_2_5_M_SEC);	/* 2.5 ms */

	LEDMAT_VidDiableAllCol();
	LEDMAT_VidSetRawValue(Copy_u8Data[Loc_u8Iterator++]);
	GPIO_VidSetPinValue(LEDMAT_COL1_PIN, LOW);
	STK_VidSetBusyWait(TIME_2_5_M_SEC);	/* 2.5 ms */

	LEDMAT_VidDiableAllCol();
	LEDMAT_VidSetRawValue(Copy_u8Data[Loc_u8Iterator++]);
	GPIO_VidSetPinValue(LEDMAT_COL2_PIN, LOW);
	STK_VidSetBusyWait(TIME_2_5_M_SEC);	/* 2.5 ms */


	LEDMAT_VidDiableAllCol();
	LEDMAT_VidSetRawValue(Copy_u8Data[Loc_u8Iterator++]);
	GPIO_VidSetPinValue(LEDMAT_COL3_PIN, LOW);
	STK_VidSetBusyWait(TIME_2_5_M_SEC);	/* 2.5 ms */


	LEDMAT_VidDiableAllCol();
	LEDMAT_VidSetRawValue(Copy_u8Data[Loc_u8Iterator++]);
	GPIO_VidSetPinValue(LEDMAT_COL4_PIN, LOW);
	STK_VidSetBusyWait(TIME_2_5_M_SEC);	/* 2.5 ms */

	LEDMAT_VidDiableAllCol();
	LEDMAT_VidSetRawValue(Copy_u8Data[Loc_u8Iterator++]);
	GPIO_VidSetPinValue(LEDMAT_COL5_PIN, LOW);
	STK_VidSetBusyWait(TIME_2_5_M_SEC);	/* 2.5 ms */

	LEDMAT_VidDiableAllCol();
	LEDMAT_VidSetRawValue(Copy_u8Data[Loc_u8Iterator++]);
	GPIO_VidSetPinValue(LEDMAT_COL6_PIN, LOW);
	STK_VidSetBusyWait(TIME_2_5_M_SEC);	/* 2.5 ms */

	LEDMAT_VidDiableAllCol();
	LEDMAT_VidSetRawValue(Copy_u8Data[Loc_u8Iterator++]);
	GPIO_VidSetPinValue(LEDMAT_COL7_PIN, LOW);
	STK_VidSetBusyWait(TIME_2_5_M_SEC);	/* 2.5 ms */

}

static void LEDMAT_VidDiableAllCol(void)
{
	/* disable all columns */
	GPIO_VidSetPinValue(LEDMAT_COL0_PIN, HIGH);
	GPIO_VidSetPinValue(LEDMAT_COL1_PIN, HIGH);
	GPIO_VidSetPinValue(LEDMAT_COL2_PIN, HIGH);
	GPIO_VidSetPinValue(LEDMAT_COL3_PIN, HIGH);
	GPIO_VidSetPinValue(LEDMAT_COL4_PIN, HIGH);
	GPIO_VidSetPinValue(LEDMAT_COL5_PIN, HIGH);
	GPIO_VidSetPinValue(LEDMAT_COL6_PIN, HIGH);
	GPIO_VidSetPinValue(LEDMAT_COL7_PIN, HIGH);
}

static void LEDMAT_VidSetRawValue(uint8_t Copy_u8RowValue)
{
	uint8_t Loc_u8Iterator = 0;
	uint8_t Loc_u8BitValue = 0;


	Loc_u8BitValue = GET_BIT(Copy_u8RowValue, Loc_u8Iterator++);
	GPIO_VidSetPinValue(LEDMAT_ROW0_PIN, Loc_u8BitValue);

	Loc_u8BitValue = GET_BIT(Copy_u8RowValue, Loc_u8Iterator++);
	GPIO_VidSetPinValue(LEDMAT_ROW1_PIN, Loc_u8BitValue);

	Loc_u8BitValue = GET_BIT(Copy_u8RowValue, Loc_u8Iterator++);
	GPIO_VidSetPinValue(LEDMAT_ROW2_PIN, Loc_u8BitValue);

	Loc_u8BitValue = GET_BIT(Copy_u8RowValue, Loc_u8Iterator++);
	GPIO_VidSetPinValue(LEDMAT_ROW3_PIN, Loc_u8BitValue);

	Loc_u8BitValue = GET_BIT(Copy_u8RowValue, Loc_u8Iterator++);
	GPIO_VidSetPinValue(LEDMAT_ROW4_PIN, Loc_u8BitValue);

	Loc_u8BitValue = GET_BIT(Copy_u8RowValue, Loc_u8Iterator++);
	GPIO_VidSetPinValue(LEDMAT_ROW5_PIN, Loc_u8BitValue);

	Loc_u8BitValue = GET_BIT(Copy_u8RowValue, Loc_u8Iterator++);
	GPIO_VidSetPinValue(LEDMAT_ROW6_PIN, Loc_u8BitValue);

	Loc_u8BitValue = GET_BIT(Copy_u8RowValue, Loc_u8Iterator++);
	GPIO_VidSetPinValue(LEDMAT_ROW7_PIN, Loc_u8BitValue);



}
