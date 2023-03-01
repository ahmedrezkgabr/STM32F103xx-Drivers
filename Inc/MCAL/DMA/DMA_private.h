/****************************************************/
/*	Author		: Ahmed Rezk		        		*/
/*	Date		: 21 Feb 2023		        		*/
/*	file name	: DMA_private.h 		    		*/
/*	file module	: direct memory access controller	*/
/*	Version		: V01				        		*/
/****************************************************/

/* file guard */
#ifndef DMA_PRIVATE__H_
#define DMA_PRIVATE__H_

/* register definition */
typedef struct
{
	volatile uint32_t DMA_CCR;
	volatile uint32_t DMA_CNDTR;
	volatile uint32_t DMA_CPAR;
	volatile uint32_t DMA_CMAR;
	volatile uint32_t reserved;
}DMA_CHANNEL_t;

typedef struct
{
	volatile uint32_t DMA_ISR;
	volatile uint32_t DMA_IFCR;
	DMA_CHANNEL_t channels[7];
} DMA_t;

#define DMA_BASE_ADDRESS	0x40020000
#define DMA	((volatile DMA_t*)DMA_BASE_ADDRESS)

#endif /* DMA_PRIVATE__H_ */
