/************************************************/
/*	Author		: Ahmed Rezk		        	*/
/*	Date		: 1 Mar 2023		        	*/
/*	file name	: TFT_program.c 		    	*/
/*	file module	: thin film transistor			*/
/*	Version		: V01				        	*/
/************************************************/

/* INCLUDES */

/* Library */
#include "LIB/std_types.h"
#include "LIB/bit_math.h"

/* Lower layers interfaces */
#include "MCAL/SPI/SPI_interface.h"
#include "MCAL/STK/STK_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"

/* My own interface */
#include "HAL/TFT/TFT_interface.h"

/* Private and configuration files */
#include "HAL/TFT/TFT_private.h"
#include "HAL/TFT/TFT_config.h"


void TFT_VidInit		(void)
{
	/* reset pulse */
	GPIO_VidSetPinValue(TFT_RST_PIN, HIGH);
	STK_VidSetBusyWait(100);
	GPIO_VidSetPinValue(TFT_RST_PIN, LOW);
	STK_VidSetBusyWait(1);
	GPIO_VidSetPinValue(TFT_RST_PIN, HIGH);
	STK_VidSetBusyWait(100);
	GPIO_VidSetPinValue(TFT_RST_PIN, LOW);
	STK_VidSetBusyWait(100);
	GPIO_VidSetPinValue(TFT_RST_PIN, HIGH);
	STK_VidSetBusyWait(120000);

	/* send sleep out command */
	VidWriteCommand(0x11);

	/* wait for 150ms */
	STK_VidSetBusyWait(150000);

	/* send color mode command */
	VidWriteCommand(0x3A);

	/* send color mode parameters */
	VidWriteData(0x05);	/* RGB565 */



	/* send display on command*/
	VidWriteCommand(0x29);
}

void TFT_VidDrawImage	(const uint16_t * Copy_pu16Image)
{
	uint16_t Loc_u16Iterator;
	uint16_t Loc_u16SizeOfTft = TFT_V_PIXELS * TFT_H_PIXELS;

	/* set H address (start, end) */
	VidWriteCommand(0x2A);

	/* send parameters */
	VidWriteData(0);				/* start high */
	VidWriteData(0);				/* start low */
	VidWriteData(0);				/* end high */
	VidWriteData(TFT_H_PIXELS - 1);	/* end low */

	/* set V address (start, end) */
	VidWriteCommand(0x2B);

	/* send parameters */
	VidWriteData(0);				/* start high */
	VidWriteData(0);				/* start low */
	VidWriteData(0);				/* end high */
	VidWriteData(TFT_V_PIXELS - 1);	/* end low */


	/* RAM write of TFT */
	VidWriteCommand(0x2C);

	for (Loc_u16Iterator = 0; Loc_u16Iterator < Loc_u16SizeOfTft; Loc_u16Iterator++)
	{
		/* send high part of each pixel */
		VidWriteData(Copy_pu16Image[Loc_u16Iterator] >> 8);

		/* send low part of each pixel */
		VidWriteData(Copy_pu16Image[Loc_u16Iterator] & 0x00FF);
	}
}

static void VidWriteCommand	(uint8_t Copy_u8Command)
{
	uint8_t Loc_u8Temp;

	/* set A0 pin to low */
	GPIO_VidSetPinValue(TFT_A0_PIN, LOW);

	/* send command over SPI */
	SPI1_VidSendReceiveSynchronous(Copy_u8Command, &Loc_u8Temp);
}

static void VidWriteData	(uint8_t Copy_u8Data)
{
	uint8_t Loc_u8Temp;

	/* set A0 pin to high */
	GPIO_VidSetPinValue(TFT_A0_PIN, HIGH);

	/* send command over SPI */
	SPI1_VidSendReceiveSynchronous(Copy_u8Command, &Loc_u8Temp);
}
