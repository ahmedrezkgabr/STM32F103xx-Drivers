/************************************/
/*	Author		: Ahmed Rezk		*/
/*	Date		: 10 Feb 2023		*/
/*	file name	: bit_math.h		*/
/*	file module	: library			*/
/*	Version		: V01				*/
/************************************/

/* File Guard */
#ifndef BIT_MATH__H_
#define BIT_MATH__H_


#define	SET_BIT(VAR, BIT)	((VAR) |= (1 << (BIT)))
#define CLR_BIT(VAR, BIT)	((VAR) &= ~(1 << BIT))
#define GET_BIT(VAR, BIT)	(((VAR) >> (BIT)) & 1 )
#define TGL_BIT(VAR, BIT)	((VAR) ^= (1 << (BIT)))



#endif /* BIT_MATH__H_ */
