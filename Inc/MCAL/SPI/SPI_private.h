/************************************************/
/*	Author		: Ahmed Rezk		        	*/
/*	Date		: 24 Feb 2023		        	*/
/*	file name	: SPI_private.h 		    	*/
/*	file module	: serial peripheral interface	*/
/*	Version		: V01				        	*/
/************************************************/

/* file guard */
#ifndef SPI_PRIVATE__H_
#define SPI_PRIVATE__H_

/* register definition */
typedef struct
{
	volatile uint32_t SPI1_CR1;
	volatile uint32_t SPI1_CR2;
	volatile uint32_t SPI1_SR;
	volatile uint32_t SPI1_DR;
	volatile uint32_t SPI1_CRCPR;
	volatile uint32_t SPI1_RXCRCR;
	volatile uint32_t SPI1_TXCRCR;
	volatile uint32_t SPI1_I2SCFGR;
	volatile uint32_t SPI1_I2SPR;
} SPI1_t;

#define SPI1_BASE_ADDRESS	0x40013000
#define SPI1	((SPI1_t *)SPI1_BASE_ADDRESS)

static void (*SPI1_callBack)(uint8_t) = NULL;

#endif	/* SPI_PRIVATE__H_ */
