/************************************************/
/*	Author		: Ahmed Rezk		        	*/
/*	Date		: 24 Feb 2023		        	*/
/*	file name	: SPI_program.c 		    	*/
/*	file module	: serial peripheral interface	*/
/*	Version		: V01				        	*/
/************************************************/


/* INCLUDES */

/* Library */
#include "LIB/std_types.h"
#include "LIB/bit_math.h"

/* Lower layers interfaces */
/* None */

/* My own interface */
#include "MCAL/SPI/SPI_interface.h"

/* Private and configuration files */
#include "MCAL/SPI/SPI_private.h"
#include "MCAL/SPI/SPI_config.h"

#include "MCAL/GPIO/GPIO_interface.h"


void SPI1_VidInit(void)
{

#if   SPI1_STATUS == SPI_ENABLE	/* check if SPI enabled or disabled */

/***************************************************************************************/
/**************************************clock mode***************************************/
/***************************************************************************************/
	#if		SPI1_CLOCK_MODE == SPI_CPOL_LOW_CPHA_RW	/* check the mode */

		/* choose clock phase as read then write */
		/* bit 0 in CR1 is responsible for choosing clock phase */
		CLR_BIT(SPI1->SPI1_CR1, 0);

		/* choose clock polarity as low polarity */
		/* bit 1 in CR1 is responsible for choosing clock polarity */
		CLR_BIT(SPI1->SPI1_CR1, 1);

	#elif	SPI1_CLOCK_MODE == SPI_CPOL_LOW_CPHA_WR

		/* choose clock phase write then read */
		/* bit 0 in CR1 is responsible for choosing clock phase */
		SET_BIT(SPI1->SPI1_CR1, 0);

		/* choose clock polarity as low polarity */
		/* bit 1 in CR1 is responsible for choosing clock polarity */
		CLR_BIT(SPI1->SPI1_CR1, 1);

	#elif	SPI1_CLOCK_MODE == SPI_CPOL_HIGH_CPHA_RW

		/* choose clock phase read then write */
		/* bit 0 in CR1 is responsible for choosing clock phase */
		CLR_BIT(SPI1->SPI1_CR1, 0);

		/* choose clock polarity high polarity */
		/* bit 1 in CR1 is responsible for choosing clock polarity */
		SET_BIT(SPI1->SPI1_CR1, 1);

	#elif	SPI1_CLOCK_MODE == SPI_CPOL_HIGH_CPHA_WR

		/* choose clock phase read then write */
		/* bit 0 in CR1 is responsible for choosing clock phase */
		SET_BIT(SPI1->SPI1_CR1, 0 );

		/* choose clock polarity as high polarity */
		/* bit 1 in CR1 is responsible for choosing clock polarity */
		SET_BIT(SPI1->SPI1_CR1, 1 );

	#endif	/* nested if (clock mode)*/

/***************************************************************************************/
/************************************master or slave************************************/
/***************************************************************************************/
	#if    SPI1_MASTER_SLAVE == SPI_MASTER	/* check master or slave */

		/* choose master */
		/* bit 2 in CR1 is responsible for choosing master or slave */
		SET_BIT(SPI1->SPI1_CR1, 2);

		/* according to data-sheet set bit SSI if master mode */
		/* bit 8 in CR1 is internal slave select */
		SET_BIT(SPI1->SPI1_CR1, 8);

	#elif  SPI1_MASTER_SLAVE == SPI_SLAVE

		/* choose slave */
		/* bit 2 in CR1 is responsible for choosing master or slave */
		CLR_BIT(SPI1->SPI1_CR1, 2);

		/* according to data-sheet clear bit SSI if slave mode */
		/* bit 8 in CR1 is internal slave select */
		CLR_BIT(SPI1->SPI1_CR1, 8);

	#endif	/* nested if (master or slave) */

/***************************************************************************************/
/***************************************data order**************************************/
/***************************************************************************************/
	#if   SPI1_DATA_ORDER == SPI_MSB_FIRST	/* check data order */

		/* choose LSB first */
		/* bit 7 in CR1 is responsible for choosing the data order */
		CLR_BIT(SPI1->SPI1_CR1, 7);

	#elif SPI1_DATA_ORDER == SPI_LSB_FIRST

		/* choose LSB first */
		/* bit 7 in CR1 is responsible for choosing the data order */
		SET_BIT(SPI1->SPI1_CR1, 7);

	#endif	/* nested if (data order) */

/***************************************************************************************/
/**************************************HW or SW SS**************************************/
/***************************************************************************************/
	#if   SPI1_SS_MANAGE  == HW_SLAVE_MANAGEMENT	/* hardware or software slave select */

		/* select hardware management */
		/* bit 9 in CR1 is responsible for choosing slave select management mode */
		CLR_BIT(SPI1->SPI1_CR1, 9);

	#elif SPI1_SS_MANAGE == SW_SLAVE_MANAGEMENT

		/* select software management */
		/* bit 9 in CR1 is responsible for choosing slave select management mode */
		SET_BIT(SPI1->SPI1_CR1, 9);

	#endif	/* nested if (slave select manage) */

/***************************************************************************************/
/***************************************data size***************************************/
/***************************************************************************************/
	#if   SPI1_DATA_SIZE == SPI_8BIT_DATA		/* data size */

		/* chose 8-bits mode */
		/* bit 11 in CR1 is responsible for choosing data size */
		CLR_BIT(SPI1->SPI1_CR1, 11);

	#elif SPI1_DATA_SIZE == SPI_16BIT_DATA

		/* chose 16-bits mode */
		/* bit 11 in CR1 is responsible for choosing data size */
		SET_BIT(SPI1->SPI1_CR1, 11);

	#endif	/* nested if (data size) */

/***************************************************************************************/
/************************************interrupt status***********************************/
/***************************************************************************************/
	#if   SPI1_INT_STATUS == SPI_INT_DISABLE	/* interrupt enable */

		/* disable all interrupts */
		/* CR2 is responsible for enabling and disabling interrupts */
		SPI1->SPI1_CR2 = 0;

	#elif SPI1_INT_STATUS == SPI_TXE_INT_ENABLE

		/* enable transmit interrupt */
		/* bit 7 in CR2 is responsible for enabling and disabling transmitting interrupt */
		SET_BIT(SPI1->SPI1_CR2, 7);

	#elif SPI1_INT_STATUS == SPI_RXNE_INT_ENABLE

		/* enable receive interrupt */
		/* bit 6 in CR2 is responsible for enabling and disabling receiving interrupt */
		SET_BIT(SPI1->SPI1_CR2, 6);

	#endif	/* nested if (interrupt) */

	/* set the pre-scaller  */
	/* bits 3, 4, and 5 in CR1 are responsible for choosing the pre-scaller mode */
	SPI1->SPI1_CR1 &= 0xFFC7;						/* clear the 3 bits */
	SPI1->SPI1_CR1 |= (SPI1_PRESCALLER << 3);		/* write the mode */

	/* enable SPI */
	/* bit 6 in CR1 is responsible for enabling and disabling SPI */
	SET_BIT(SPI1->SPI1_CR1, 6);

#elif MSP1_STATUS == MSPI_DISABLE

	/* disable SPI */
	/* bit 6 in CR1 is responsible for enabling and disabling SPI */
	CLR_BIT(SPI1->SPI1_CR1, 6);

#endif	/* main if */
}

void SPI1_VidSendReceiveSynchronous(uint8_t Copy_u8DataToTransmit, uint8_t *Copy_pu8DataToReceive)
{
	/* choose the slave first */

#if SPI1_SS_MANAGE == SW_SLAVE_MANAGEMENT
	/* clear slave select pin */
	/* SPI1_SLAVE_PIN => PORTx,PINx */
	GPIO_VidSetPinValue(SPI1_SLAVE_PIN, LOW);
#endif
	/* send data */
	/* but the data on DR */
	SPI1->SPI1_DR = Copy_u8DataToTransmit;

	/* wait busy flag to finish sending */
	/* busy wait flag is bit 7 in SPI status register */
	while(!GET_BIT(SPI1->SPI1_SR, 7));

	/* return the received data */
	/* fill the buffer of received data with the content of DR */
	*Copy_pu8DataToReceive = SPI1->SPI1_DR;

#if SPI1_SS_MANAGE == SW_SLAVE_MANAGEMENT
	/* set slave select pin again */
	/* SPI1_SLAVE_PIN => PORTx,PINx */
	GPIO_VidSetPinValue(SPI1_SLAVE_PIN, HIGH);
#endif
}

void SPI1_VidSendReceiveAsynchronous(uint8_t Copy_u8DataToTransmit, void (*Copy_VidPtrToFunc)(uint8_t))
{
	/* set call back function */
	if(Copy_VidPtrToFunc)	/* function safety */
		SPI1_callBack = Copy_VidPtrToFunc;

	/* choose the slave first */

#if SPI1_SS_MANAGE == SW_SLAVE_MANAGEMENT
	/* clear slave select pin */
	/* SPI1_SLAVE_PIN => PORTx,PINx */
	GPIO_VidSetPinValue(SPI1_SLAVE_PIN, LOW);
#endif

	/* send data */
	/* but the data on DR */
	SPI1->SPI1_DR = Copy_u8DataToTransmit;
}

void SPI1_IRQHandler(void)
{
	/* calling call back function */
	if(SPI1_callBack)
		SPI1_callBack(SPI1->SPI1_DR);

	/* set slave select pin again */
	/* SPI1_SLAVE_PIN => PORTx,PINx */
	GPIO_VidSetPinValue(SPI1_SLAVE_PIN, HIGH);
}
