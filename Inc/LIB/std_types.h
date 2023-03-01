/************************************/
/*	Author		: Ahmed Rezk		*/
/*	Date		: 10 Feb 2023		*/
/*	file name	: std_types.h		*/
/*	file module	: library			*/
/*	Version		: V01				*/
/************************************/

/* File Guard */
#ifndef STD_TYPES__H_
#define STD_TYPES__H_

typedef unsigned char 			uint8_t;
typedef unsigned short int 		uint16_t;
typedef unsigned long  int 		uint32_t;

typedef signed char 			sint8_t;
typedef signed short int 		sint16_t;
typedef signed long  int 		sint32_t;

typedef unsigned long long int 	uint64_t ;
typedef signed long long int 	sint64_t ;

typedef float  f32_t;
typedef double f64_t;

#ifndef NULL
#define NULL ((void *)0)
#endif

#endif /* STD_TYPES__H_ */
