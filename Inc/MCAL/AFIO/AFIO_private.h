/****************************************************/
/*	Author		: Ahmed Rezk		        		*/
/*	Date		: 12 Feb 2023		        		*/
/*	file name	: AFIO_private.h	        		*/
/*	file module	: alternative function input output	*/
/*	Version		: V01				        		*/
/****************************************************/


/* File Guard */
#ifndef AFIO_PRIVATE__H_
#define AFIO_PRIVATE__H_

typedef struct
{
	volatile uint32_t AFIO_EVCR;
	volatile uint32_t AFIO_MAPR;
	volatile uint32_t AFIO_EXTICR[4];
	volatile uint32_t AFIO_MAPR2;
} AFIO_reg_t;

#define AFIO_BASE_ADDRESS	0x40010000

/* pointer to struct of type afio_reg_t*/
#define AFIO				((volatile AFIO_reg_t*) AFIO_BASE_ADDRESS)

#endif /* AFIO_PRIVATE__H_ */
