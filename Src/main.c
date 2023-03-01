/********************************************/
/*	Author		: Ahmed Rezk		        */
/*	Date		: 10 Feb 2023		        */
/*	file name	: main.c		 		    */
/*	file module	: main					    */
/*	Version		: V01				        */
/********************************************/

/* INCLUDES */

/* Library */
#include "LIB/std_types.h"
#include "LIB/bit_math.h"

/* Lower layers interfaces */
/* micro-controller abstracted layer vendor peripherals */
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/AFIO/AFIO_interface.h"
#include "MCAL/DMA/DMA_interface.h"
#include "MCAL/SPI/SPI_interface.h"
#include "MCAL/USART/USART_interface.h"

/* micro-controller abstracted layer core peripherals */
#include "MCAL/NVIC/NVIC_interface.h"
#include "MCAL/STK/STK_interface.h"

/* service layer */
#include "SERVICES/OS/OS_interface.h"

/* hardware abstracted layer */
#include "HAL/LEDMAT/LEDMAT_interface.h"
#include "HAL/STP/STP_interface.h"
// #include "HAL/IR/IR_interface.h"

/* application layer */


uint8_t volatile Flag = 0;

void EXT0_CALLBACK(){

	if( Flag == 0 ){

		GPIO_VidSetPinValue(PORT_A ,PIN1, HIGH);
		Flag = 1 ;

	}

}

void EXT1_CALLBACK(){

	if( Flag == 1 ){

		GPIO_VidSetPinValue(PORT_A, PIN1, LOW);
		Flag = 0 ;

	}

}
void delay_us(uint32_t Copt_u32Time)
{
	STK_VidSetBusyWait(Copt_u32Time);
}


void func(uint8_t test)
{
	//volatile uint8_t local = test;
	asm("NOP");
}

int main(void)
{
	/* clock */
	RCC_VidInit();
	RCC_VidEnablePeripheralClock(APB2, GPIOA_RCC);
	RCC_VidEnablePeripheralClock(APB2, GPIOB_RCC);
	RCC_VidEnablePeripheralClock(APB2, AFIO_RCC);

	/* EXTIs pins directions == input pull-up */
	GPIO_VidSetPinMode(PORT_A, PIN0, INPUT_PULLUP_PULLDOWN);
	GPIO_VidSetPinMode(PORT_B, PIN1, INPUT_PULLUP_PULLDOWN);
	GPIO_VidSetPinValue(PORT_A, PIN0, HIGH);
	GPIO_VidSetPinValue(PORT_B, PIN1, HIGH);

	/* led pin direction == output @ 2MHz pull-pu pull-down */
	GPIO_VidSetPinMode(PORT_A, PIN1, OUTPUT_SPEED_2MHZ_PP);

	/* set software priority for EXTIs */
	NVIC_VidSetInterruptPriority(6, 1, 0, GROUP_XXXY);
	NVIC_VidSetInterruptPriority(7, 1, 0, GROUP_XXXY);


	/* enable EXTIs */
	NVIC_VidEnableInterrupt(6);
	NVIC_VidEnableInterrupt(7);

	/* choose the source of the lines */
	AFIO_VidSetEXTIConfig(LINE_0, AFIO_EXTI_PORT_A);
	AFIO_VidSetEXTIConfig(LINE_1, AFIO_EXTI_PORT_B);

	/* set call back functions */
	EXTI0_VidSetCallBack(EXT0_CALLBACK);
	EXTI1_VidSetCallBack(EXT1_CALLBACK);

	/* configure EXTIs */
	EXTI_VidSetSignalLatch(LINE_0, ON_CHANGE);
	EXTI_VidSetSignalLatch(LINE_1, ON_CHANGE);

	while(1);
	return 0;
}
