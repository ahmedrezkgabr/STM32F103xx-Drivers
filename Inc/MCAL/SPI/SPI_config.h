/************************************************/
/*	Author		: Ahmed Rezk		        	*/
/*	Date		: 24 Feb 2023		        	*/
/*	file name	: SPI_config.h 		    	*/
/*	file module	: serial peripheral interface	*/
/*	Version		: V01				        	*/
/************************************************/

/* file guard */
#ifndef SPI_CONFIG__H_
#define SPI_CONFIG__H_

/* write pin in pairs */
#define SPI1_SLAVE_PIN	PORT_A,PIN0

/* options:
 * SPI_DISABLE
 * SPI_ENABLE
 * */
#define SPI1_STATUS          SPI_ENABLE

/* options:
 * SPI_CPOL_LOW_CPHA_RW
 * SPI_CPOL_LOW_CPHA_WR
 * SPI_CPOL_HIGH_CPHA_RW
 * SPI_CPOL_HIGH_CPHA_WR
 * */
#define SPI1_CLOCK_MODE     SPI_CPOL_HIGH_CPHA_WR

/* options:
 * SPI_MASTER
 * SPI_SLAVE
 * */
#define SPI1_MASTER_SLAVE   SPI_MASTER

/* options:
 * SPI_FPCLK_DIVIDED_BY_2
 * SPI_FPCLK_DIVIDED_BY_4
 * SPI_FPCLK_DIVIDED_BY_8
 * SPI_FPCLK_DIVIDED_BY_16
 * SPI_FPCLK_DIVIDED_BY_32
 * SPI_FPCLK_DIVIDED_BY_64
 * SPI_FPCLK_DIVIDED_BY_128
 * SPI_FPCLK_DIVIDED_BY_256
 * */
#define SPI1_PRESCALLER     SPI_FPCLK_DIVIDED_BY_2

/* options:
 * SPI_MSB_FIRST
 * SPI_LSB_FIRST
 * */
#define SPI1_DATA_ORDER     SPI_MSB_FIRST

/* options:
 * HW_SLAVE_MANAGEMENT
 * SW_SLAVE_MANAGEMENT
 * */
#define SPI1_SS_MANAGE      SW_SLAVE_MANAGEMENT

/* options:
 * SPI_8BIT_DATA
 * SPI_16BIT_DATA
 * */
#define SPI1_DATA_SIZE      SPI_8BIT_DATA

/* options:
 * SPI_INT_DISABLE
 * SPI_TXE_INT_ENABLE
 * SPI_RXNE_INT_ENABLE
 * */
#define SPI1_INT_STATUS     SPI_TXE_INT_ENABLE

#endif	/* SPI_CONFIG__H_ */
