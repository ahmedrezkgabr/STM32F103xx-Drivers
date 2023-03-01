/********************************************/
/*	Author		: Ahmed Rezk		        */
/*	Date		: 10 Feb 2023		        */
/*	file name	: RCC_config.h		        */
/*	file module	: reset and clock control   */
/*	Version		: V01				        */
/********************************************/



/* File Guard */
#ifndef RCC_CONFIG__H_
#define RCC_CONFIG__H_

/* Choose RCC type */
#define RCC_TYPE    RCC_HSI


/* If you have chosen Phase Locked Loop*/
#if RCC_TYPE == RCC_PLL

/* Choose the input of pll */
#define PLL_INPUT           RCC_PLL_HSI_DIV_2

/* Choose the multiplication factor */
#define PLL_CLK_MUL_FAC     RCC_PLL_CLK_MUL_2
#endif


/* Choose to enable or disable clock security system */
#define  CLK_SECURITY_SYSTEM    RCC_CSS_DISABLE


#endif /* RCC_CONFIG__H_ */
