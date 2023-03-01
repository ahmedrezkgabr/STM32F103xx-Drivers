/************************************************/
/*	Author		: Ahmed Rezk		        	*/
/*	Date		: 24 Feb 2023		        	*/
/*	file name	: SPI_interface.h 		    	*/
/*	file module	: serial peripheral interface	*/
/*	Version		: V01				        	*/
/************************************************/

/* file guard */
#ifndef SPI_INTERFACE__H_
#define SPI_INTERFACE__H_

/* SP1_STATUS */
#define SPI_DISABLE                 10
#define SPI_ENABLE                  11

/* SPI1_CLOCK_MODE */
#define SPI_CPOL_LOW_CPHA_RW        20
#define SPI_CPOL_LOW_CPHA_WR        21
#define SPI_CPOL_HIGH_CPHA_RW       22
#define SPI_CPOL_HIGH_CPHA_WR       23

/* SPI1_MASTER_SLAVE */
#define SPI_MASTER                  30
#define SPI_SLAVE                   31

/* SPI1_PRESCALLER */
#define SPI_FPCLK_DIVIDED_BY_2      0b000
#define SPI_FPCLK_DIVIDED_BY_4      0b001
#define SPI_FPCLK_DIVIDED_BY_8      0b010
#define SPI_FPCLK_DIVIDED_BY_16     0b011
#define SPI_FPCLK_DIVIDED_BY_32     0b100
#define SPI_FPCLK_DIVIDED_BY_64     0b101
#define SPI_FPCLK_DIVIDED_BY_128    0b110
#define SPI_FPCLK_DIVIDED_BY_256    0b111

/* SPI1_DATA_ORDER */
#define SPI_MSB_FIRST				40
#define SPI_LSB_FIRST 				41

/* SPI1_SS_MANAGE */
#define HW_SLAVE_MANAGEMENT         50
#define SW_SLAVE_MANAGEMENT         51

/* SPI1_DATA_SIZE */
#define SPI_8BIT_DATA               60
#define SPI_16BIT_DATA              71

/* SPI1_INT_STATUS */
#define SPI_INT_DISABLE             80
#define SPI_TXE_INT_ENABLE          81
#define SPI_RXNE_INT_ENABLE         82


/* APIs for SPI1 */
void SPI1_VidInit(void);
void SPI1_VidSendReceiveSynchronous(uint8_t Copy_u8DataToTransmit, uint8_t *Copy_pu8DataToReceive);
void SPI1_VidSendReceiveAsynchronous(uint8_t Copy_u8DataToTransmit, void (*Copy_VidPtrToFunc)(uint8_t));

#endif	/* SPI_INTERFACE__H_ */
