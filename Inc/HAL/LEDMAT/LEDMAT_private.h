/********************************************/
/*	Author		: Ahmed Rezk		        */
/*	Date		: 18 Feb 2023		        */
/*	file name	: LEDMAT_private.h		    */
/*	file module	: led matrix			    */
/*	Version		: V01				        */
/********************************************/



/* File Guard */
#ifndef LEDMATRIX_PRIVATE__H_
#define LEDMATRIX_PRIVATE__H_

static void LEDMAT_VidDiableAllCol(void);
static void LEDMAT_VidSetRawValue(uint8_t Copy_u8RowValue);

/*
 * we need to produce 50 frame for each column (presistance of vision)
 * so we need 50 * 8 = 400 frame to complete the matrix each second
 * from configuration of RCC -> AHB = 8 MHz
 * input of STK is AHB / 8 = 1 MHz
 * so each count in the STK take 1 us
 * so we need 2.5 ms to delay
 * 2.5 = 2500 count in STK
 * */

#define TIME_2_5_M_SEC	2500	/* depending on configuration of RCC & STK and how many frames in 1 second (50 frame * 8 columns = 400 fps) (number of counts produce 1 mil second / 400 = 2500)*/

#endif /* LEDMATRIX_PRIVATE__H_ */
