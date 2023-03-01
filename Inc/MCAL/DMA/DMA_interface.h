/****************************************************/
/*	Author		: Ahmed Rezk		        		*/
/*	Date		: 21 Feb 2023		        		*/
/*	file name	: DMA_interface.h 		    		*/
/*	file module	: direct memory access controller	*/
/*	Version		: V01				        		*/
/****************************************************/

/* file guard */
#ifndef DMA_INTERFACE__H_
#define DMA_INTERFACE__H_

void DMA_VidSetConfiguration(uint8_t Copy_u8Channel ,uint8_t Copy_u8Direction ,uint8_t Copy_u8CircularMode ,uint8_t Copy_u8Pinc ,uint8_t Copy_u8Minc ,uint8_t Copy_u8MemSize ,uint8_t Copy_u8PerSize ,uint8_t Copy_u8ChannelPriority);
void DMA_VidEnableChannel(uint8_t Copy_u8Channel);
void DMA_VidDisableChannel(uint8_t Copy_u8Channel);
void DMA_VidSetAddress(uint8_t Copy_u8Channel ,uint32_t * pu32PeripheralAddress ,uint32_t * pu32MemoryAddress ,uint16_t Copy_u16NDT);
void DMA_VidInterruptEnable(uint8_t Copy_u8Channel, uint8_t Copy_u8IntSource);

void DMA_VidSetCallBackChannel1(void (*Copy_VidPtrToFunc)(void));
void DMA_VidSetCallBackChannel2(void (*Copy_VidPtrToFunc)(void));
void DMA_VidSetCallBackChannel3(void (*Copy_VidPtrToFunc)(void));
void DMA_VidSetCallBackChannel4(void (*Copy_VidPtrToFunc)(void));
void DMA_VidSetCallBackChannel5(void (*Copy_VidPtrToFunc)(void));
void DMA_VidSetCallBackChannel6(void (*Copy_VidPtrToFunc)(void));
void DMA_VidSetCallBackChannel7(void (*Copy_VidPtrToFunc)(void));



/* channels */
#define CHANNEL1  0
#define CHANNEL2  1
#define CHANNEL3  2
#define CHANNEL4  3
#define CHANNEL5  4
#define CHANNEL6  5
#define CHANNEL7  6

/* DMA enable */
#define DMA_ENABLE  0
#define DMA_DISABLE 1

/* DMA configuration */
/* direction */
#define MEM_TO_MEM   0
#define PREI_TO_MEM  1
#define MEM_TO_PERI  2

/* circular */
#define DMA_ENABLE_CIRCULAR  0
#define DMA_DISABLE_CIRCULAR 1

/* PIN */
#define PERIPHERAL_INCREMENT_ENABLE  0
#define PERIPHERAL_INCREMENT_DISABLE 1
/* MIN */
#define MEM_INCREMENT_ENABLE  0
#define MEM_INCREMENT_DISABLE 1

/* element size */
#define BYTE       0
#define HALF_WORD  1
#define WORD       2

/* channel priority */
#define DMA_LOW         0
#define DMA_MEDIUM      1
#define DMA_HIGH        2
#define DMA_VERY_HIGH   3

#define  DMA_TCIE	1
#define  DMA_HTIE	2
#define  DMA_TEIE	3

#endif /* DMA_INTERFACE__H_ */
