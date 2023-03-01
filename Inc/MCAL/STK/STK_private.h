/********************************************/
/*	Author		: Ahmed Rezk		        */
/*	Date		: 13 Feb 2023		        */
/*	file name	: STK_private.h 		    */
/*	file module	: system tick			    */
/*	Version		: V01				        */
/********************************************/

/* File Guard */
#ifndef STK_PRIVATE__H_
#define STK_PRIVATE__H_

/* register definition */
#define STK_MAPPED_BASE_ADDRESS		0xE000E010


#define STK_CTRL	*((volatile uint32_t*)(STK_MAPPED_BASE_ADDRESS + 0x00))	/* system tick control register */
#define STK_LOAD	*((volatile uint32_t*)(STK_MAPPED_BASE_ADDRESS + 0x04))	/* system tick load register */
#define STK_VAL		*((volatile uint32_t*)(STK_MAPPED_BASE_ADDRESS + 0x08))	/* system tick value register */
#define STK_CALIB	*((volatile uint32_t*)(STK_MAPPED_BASE_ADDRESS + 0x0C))	/* system tick calibration register */

#define STK_AHB			0
#define STK_AHB_DIB_8	1

#endif /* STK_PRIVATE__H_ */
