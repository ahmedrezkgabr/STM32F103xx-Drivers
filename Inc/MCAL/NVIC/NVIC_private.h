/********************************************************/
/*	Author		: Ahmed Rezk		        			*/
/*	Date		: 11 Feb 2023		        			*/
/*	file name	: NVIC_private.h		        			*/
/*	file module	: nested vector interrupt controller	*/
/*	Version		: V01				        			*/
/********************************************************/

/* file guard */
#ifndef NVIC_PRIVATE__H_
#define NVIC_PRIVATE__H_

/* registers definition */
#define NVIC_MAPPED_BASE_ADDRESS	0xE000E100

/* Interrupt set-enable registers */	/* make it 4-byte addressable */
#define NVIC_ISER	((volatile uint32_t*)(NVIC_MAPPED_BASE_ADDRESS + 0x00))

/* Interrupt clear-enable registers */	/* make it 4-byte addressable */
#define NVIC_ICER	((volatile uint32_t*)(NVIC_MAPPED_BASE_ADDRESS + 0x80))

/* Interrupt set-pending registers */	/* make it 4-byte addressable */
#define NVIC_ISPR	((volatile uint32_t*)(NVIC_MAPPED_BASE_ADDRESS + 0x100))

/* Interrupt clear-pending registers */	/* make it 4-byte addressable */
#define NVIC_ICPR	((volatile uint32_t*)(NVIC_MAPPED_BASE_ADDRESS + 0x180))

/* Interrupt active bit registers */	/* make it 4-byte addressable */
#define NVIC_IABR	((volatile uint32_t*)(NVIC_MAPPED_BASE_ADDRESS + 0x200))

/* Interrupt priority registers */	/* uint8_t because it is byte addressable and i need to manipulate byte by byte */
#define NVIC_IPR	((volatile uint8_t*)(NVIC_MAPPED_BASE_ADDRESS + 0x300))

/* Software trigger interrupt register */
#define NVIC_STIR	*((volatile uint32_t*)(NVIC_MAPPED_BASE_ADDRESS + 0xE00))


/* before we create the driver of system control block peripheral */
#define SCB_MAPPED_BASE_ADDRESS		0xE000ED00
#define SCB_AIRCR	*((volatile uint32_t*)(SCB_MAPPED_BASE_ADDRESS + 0x0C))



#endif /* NVIC_PRIVATE__H_ */
