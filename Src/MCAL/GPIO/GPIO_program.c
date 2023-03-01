/************************************************/
/*	Author		: Ahmed Rezk		        	*/
/*	Date		: 11 Feb 2023		        	*/
/*	file name	: GPIO_program.c 		    	*/
/*	file module	: general purpose input output	*/
/*	Version		: V01				        	*/
/************************************************/

/* INCLUDES */

/* Library */
#include "LIB/std_types.h"
#include "LIB/bit_math.h"

/* Lower layers interfaces */
/* None */

/* My own interface */
#include "MCAL/GPIO/GPIO_interface.h"

/* Private and configuration files */
#include "MCAL/GPIO/GPIO_private.h"
#include "MCAL/GPIO/GPIO_config.h"




void GPIO_VidSetPinMode(uint8_t Copy_u8Port, uint8_t Copy_u8Pin, uint8_t Copy_u8Mode)
{
	switch (Copy_u8Port)
	{
	case PORT_A:
		if (Copy_u8Pin < 8)			/* low register pins 0:7 */
		{
			/* clear the corresponding 4 bits */
			GPIOA_CRL &= ~(0b1111     << (Copy_u8Pin * 4));

			/* write the value of the mode */
			GPIOA_CRL |= (Copy_u8Mode << (Copy_u8Pin * 4));
		}
		else if (Copy_u8Pin < 16)	/* high register pins 8:15 */
		{
			/* the register is starting from 0 (pin 8 -> bits 0:3) */
			Copy_u8Pin -= 8;

			/* clear the corresponding 4 bits */
			GPIOA_CRH &= ~(0b1111     << (Copy_u8Pin * 4));

			/* write the value of the mode */
			GPIOA_CRH |= (Copy_u8Mode << (Copy_u8Pin * 4));
		}
		else
		{
			/* error */
		}
		break;

	case PORT_B:
		if (Copy_u8Pin < 8)			/* low register pins 0:7 */
		{
			/* clear the corresponding 4 bits */
			GPIOB_CRL &= ~(0b1111 << (Copy_u8Pin * 4));

			/* write the value of the mode */
			GPIOB_CRL |= (Copy_u8Mode << (Copy_u8Pin * 4));
		}
		else if (Copy_u8Pin < 16)	/* high register pins 8:15 */
		{
			/* the register is starting from 0 (pin 8 -> bits 0:3) */
			Copy_u8Pin -= 8;

			/* clear the corresponding 4 bits */
			GPIOB_CRH &= ~(0b1111 << (Copy_u8Pin * 4));

			/* write the value of the mode */
			GPIOB_CRH |= (Copy_u8Mode << (Copy_u8Pin * 4));
		}
		else
		{
			/* error */
		}
		break;

	case PORT_C:
		if (Copy_u8Pin < 8)			/* low register pins 0:7 */
		{
			/* clear the corresponding 4 bits */
			GPIOC_CRL &= ~(0b1111 << (Copy_u8Pin * 4));

			/* write the value of the mode */
			GPIOC_CRL |= (Copy_u8Mode << (Copy_u8Pin * 4));
		}
		else if (Copy_u8Pin < 16)	/* high register pins 8:15 */
		{
			/* the register is starting from 0 (pin 8 -> bits 0:3) */
			Copy_u8Pin -= 8;

			/* clear the corresponding 4 bits */
			GPIOC_CRH &= ~(0b1111 << (Copy_u8Pin * 4));

			/* write the value of the mode */
			GPIOC_CRH |= (Copy_u8Mode << (Copy_u8Pin * 4));
		}
		else
		{
			/* error */
		}
		break;

	case PORT_D:
		if (Copy_u8Pin < 8)			/* low register pins 0:7 */
		{
			/* clear the corresponding 4 bits */
			GPIOD_CRL &= ~(0b1111 << (Copy_u8Pin * 4));

			/* write the value of the mode */
			GPIOD_CRL |= (Copy_u8Mode << (Copy_u8Pin * 4));
		}
		else if (Copy_u8Pin < 16)	/* high register pins 8:15 */
		{
			/* the register is starting from 0 (pin 8 -> bits 0:3) */
			Copy_u8Pin -= 8;

			/* clear the corresponding 4 bits */
			GPIOD_CRH &= ~(0b1111 << (Copy_u8Pin * 4));

			/* write the value of the mode */
			GPIOD_CRH |= (Copy_u8Mode << (Copy_u8Pin * 4));
		}
		else
		{
			/* error */
		}
		break;

	case PORT_E:
		if (Copy_u8Pin < 8)			/* low register pins 0:7 */
		{
			/* clear the corresponding 4 bits */
			GPIOE_CRL &= ~(0b1111 << (Copy_u8Pin * 4));

			/* write the value of the mode */
			GPIOE_CRL |= (Copy_u8Mode << (Copy_u8Pin * 4));
		}
		else if (Copy_u8Pin < 16)	/* high register pins 8:15 */
		{
			/* the register is starting from 0 (pin 8 -> bits 0:3) */
			Copy_u8Pin -= 8;

			/* clear the corresponding 4 bits */
			GPIOE_CRH &= ~(0b1111 << (Copy_u8Pin * 4));

			/* write the value of the mode */
			GPIOE_CRH |= (Copy_u8Mode << (Copy_u8Pin * 4));
		}
		else
		{
			/* error */
		}
		break;

	case PORT_F:
		if (Copy_u8Pin < 8)			/* low register pins 0:7 */
		{
			/* clear the corresponding 4 bits */
			GPIOF_CRL &= ~(0b1111 << (Copy_u8Pin * 4));

			/* write the value of the mode */
			GPIOF_CRL |= (Copy_u8Mode << (Copy_u8Pin * 4));
		}
		else if (Copy_u8Pin < 16)	/* high register pins 8:15 */
		{
			/* the register is starting from 0 (pin 8 -> bits 0:3) */
			Copy_u8Pin -= 8;

			/* clear the corresponding 4 bits */
			GPIOF_CRH &= ~(0b1111 << (Copy_u8Pin * 4));

			/* write the value of the mode */
			GPIOF_CRH |= (Copy_u8Mode << (Copy_u8Pin * 4));
		}
		else
		{
			/* error */
		}
		break;

	case PORT_G:
		if (Copy_u8Pin < 8)			/* low register pins 0:7 */
		{
			/* clear the corresponding 4 bits */
			GPIOG_CRL &= ~(0b1111 << (Copy_u8Pin * 4));

			/* write the value of the mode */
			GPIOG_CRL |= (Copy_u8Mode << (Copy_u8Pin * 4));
		}
		else if (Copy_u8Pin < 16)	/* high register pins 8:15 */
		{
			/* the register is starting from 0 (pin 8 -> bits 0:3) */
			Copy_u8Pin -= 8;

			/* clear the corresponding 4 bits */
			GPIOG_CRH &= ~(0b1111 << (Copy_u8Pin * 4));

			/* write the value of the mode */
			GPIOG_CRH |= (Copy_u8Mode << (Copy_u8Pin * 4));
		}
		else
		{
			/* error */
		}
		break;

	default : /* error */	break;
	}
}

void GPIO_VidSetPinValue(uint8_t Copy_u8Port, uint8_t Copy_u8Pin, uint8_t Copy_u8Value)
{
	switch (Copy_u8Port)
	{
	case PORT_A:
		if (Copy_u8Value == LOW)	/* low */
		{
			/* using BRR */
			GPIOA_BRR = 1 << Copy_u8Pin;	/* equivalent to GPIOA_ODR $= ~(1 << Copy_u8Pin) */
		}
		else						/* anything but zero is high */
		{
			/* using BSRR */
			GPIOA_BSRR = 1 << Copy_u8Pin;	/* equivalent to GPIOA_ODR |= (1 << Copy_u8Pin) */
		}
		break;

	case PORT_B:
		if (Copy_u8Value == LOW)	/* low */
		{
			/* using BRR */
			GPIOB_BRR = 1 << Copy_u8Pin;	/* equivalent to GPIOB_ODR $= ~(1 << Copy_u8Pin) */
		}
		else						/* anything but zero is high */
		{
			/* using BSRR */
			GPIOB_BSRR = 1 << Copy_u8Pin;	/* equivalent to GPIOB_ODR |= (1 << Copy_u8Pin) */
		}
		break;

	case PORT_C:
		if (Copy_u8Value == LOW)	/* low */
		{
			/* using BRR */
			GPIOC_BRR = 1 << Copy_u8Pin;	/* equivalent to GPIOC_ODR $= ~(1 << Copy_u8Pin) */
		}
		else						/* anything but zero is high */
		{
			/* using BSRR */
			GPIOC_BSRR = 1 << Copy_u8Pin;	/* equivalent to GPIOC_ODR |= (1 << Copy_u8Pin) */
		}
		break;

	case PORT_D:
		if (Copy_u8Value == LOW)	/* low */
		{
			/* using BRR */
			GPIOD_BRR = 1 << Copy_u8Pin;	/* equivalent to GPIOD_ODR $= ~(1 << Copy_u8Pin) */
		}
		else						/* anything but zero is high */
		{
			/* using BSRR */
			GPIOD_BSRR = 1 << Copy_u8Pin;	/* equivalent to GPIOD_ODR |= (1 << Copy_u8Pin) */
		}
		break;

	case PORT_E:
		if (Copy_u8Value == LOW)	/* low */
		{
			/* using BRR */
			GPIOE_BRR = 1 << Copy_u8Pin;	/* equivalent to GPIOE_ODR $= ~(1 << Copy_u8Pin) */
		}
		else						/* anything but zero is high */
		{
			/* using BSRR */
			GPIOE_BSRR = 1 << Copy_u8Pin;	/* equivalent to GPIOE_ODR |= (1 << Copy_u8Pin) */
		}
		break;

	case PORT_F:
		if (Copy_u8Value == LOW)	/* low */
		{
			/* using BRR */
			GPIOF_BRR = 1 << Copy_u8Pin;	/* equivalent to GPIOF_ODR $= ~(1 << Copy_u8Pin) */
		}
		else						/* anything but zero is high */
		{
			/* using BSRR */
			GPIOF_BSRR = 1 << Copy_u8Pin;	/* equivalent to GPIOF_ODR |= (1 << Copy_u8Pin) */
		}
		break;

	case PORT_G:
		if (Copy_u8Value == LOW)	/* low */
		{
			/* using BRR */
			GPIOG_BRR = 1 << Copy_u8Pin;	/* equivalent to GPIOG_ODR $= ~(1 << Copy_u8Pin) */
		}
		else						/* anything but zero is high */
		{
			/* using BSRR */
			GPIOG_BSRR = 1 << Copy_u8Pin;	/* equivalent to GPIOG_ODR |= (1 << Copy_u8Pin) */
		}
		break;

	default : /* error */	break;
	}
}
uint8_t GPIO_U8GetPinValue(uint8_t Copy_u8Port, uint8_t Copy_u8Pin)
{
	uint8_t Loc_u8Result = 0;

	switch (Copy_u8Port)
	{
	case PORT_A:
		/* get the pin value from input data register of corresponding port */
		Loc_u8Result = GET_BIT(GPIOA_IDR, Copy_u8Pin);
		break;

	case PORT_B:
		/* get the pin value from input data register of corresponding port */
		Loc_u8Result = GET_BIT(GPIOB_IDR, Copy_u8Pin);
		break;

	case PORT_C:
		/* get the pin value from input data register of corresponding port */
		Loc_u8Result = GET_BIT(GPIOC_IDR, Copy_u8Pin);
		break;

	case PORT_D:
		/* get the pin value from input data register of corresponding port */
		Loc_u8Result = GET_BIT(GPIOD_IDR, Copy_u8Pin);
		break;

	case PORT_E:
		/* get the pin value from input data register of corresponding port */
		Loc_u8Result = GET_BIT(GPIOE_IDR, Copy_u8Pin);
		break;

	case PORT_F:
		/* get the pin value from input data register of corresponding port */
		Loc_u8Result = GET_BIT(GPIOF_IDR, Copy_u8Pin);
		break;

	case PORT_G:
		/* get the pin value from input data register of corresponding port */
		Loc_u8Result = GET_BIT(GPIOG_IDR, Copy_u8Pin);
		break;
	}

	/* return the filled result */
	return Loc_u8Result;
}

//void GPIO_VidSetPortMode(uint8_t Copy_u8Port, uint8_t Copy_u8Mode)
//{
//
//}
//void GPIO_VidSetPortValue(uint8_t Copy_u8Port, uint8_t Copy_u8Value)
//{
//
//}
//uint16_t GPIO_U16GetPortValue(uint8_t Copy_u8Port)
//{
//	return 0;
//}
