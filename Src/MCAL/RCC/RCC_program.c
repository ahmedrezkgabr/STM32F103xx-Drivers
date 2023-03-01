/********************************************/
/*	Author		: Ahmed Rezk		        */
/*	Date		: 10 Feb 2023		        */
/*	file name	: RCC_program.c 		    */
/*	file module	: reset and clock control   */
/*	Version		: V01				        */
/********************************************/


/* INCLUDES */

/* Library */
#include "LIB/std_types.h"
#include "LIB/bit_math.h"

/* Lower layers interfaces */
/* None */

/* My own interface */
#include "MCAL/RCC/RCC_interface.h"

/* Private and configuration files */
#include "MCAL/RCC/RCC_private.h"
#include "MCAL/RCC/RCC_config.h"


void RCC_VidInit(void)
{
	uint32_t LOC_u32TimeOut = 0;
/* RCC_TYPE */
#if     RCC_TYPE == RCC_HSI
    /* high speed internal */

	/* BIT 1:0(system clock switch bits) -> Choose Between HSI OR HSE OR PLL */
	/* HSI Selected As A System Clock */
	CLR_BIT(RCC_CFGR, 0);
	CLR_BIT(RCC_CFGR, 1);

	/* Bit 0(hsi on) -> Enable The HSI Clock */
	SET_BIT(RCC_CR, 0);

	/* Bit 1(hsi ready) -> Checking While The HSI Clock Is Stable */
	while( (GET_BIT(RCC_CR, 1) == 0) && (LOC_u32TimeOut < 100000))
	{ LOC_u32TimeOut++; }
	if(LOC_u32TimeOut >= 100000)
	{ /*TimeOut*/ }

#elif   RCC_TYPE == RCC_HSE
	/* high speed internal */

	/* BIT 1:0(system clock switch bits) -> Choose Between HSI OR HSE OR PLL */
	/* HSI Selected As A System Clock */
	SET_BIT(RCC_CFGR, 0);
	CLR_BIT(RCC_CFGR, 1);

	/* Bit 16(hse on) -> Enable The HSE Clock */
	SET_BIT(RCC_CR, 16);

	/* Bit 17(hse ready) -> Checking While The HSE Clock Is Stable */
	while( (GET_BIT(RCC_CR, 17) == 0) && (LOC_u32TimeOut < 100000))
	{ LOC_u32TimeOut++; }
	if(LOC_u32TimeOut >= 100000)
	{ /*TimeOut*/ }

#elif   RCC_TYPE == RCC_HSE_BYPASS
	/* The HSEBYP Can Be Written Only When HSE Oscillator Is Disabled */
	/* HSE Clock Disabled */
	CLR_BIT(RCC_CR, 16);

	/* BIT 18 -> To Select HSE BYPASS */
	/* HSEBYPASS Clock Enable */
	SET_BIT(RCC_CR, 18);

	/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
	/* HSE Selected As A System Clock */
	SET_BIT(RCC_CFGR, 0);
	CLR_BIT(RCC_CFGR, 1);

	/* Bit 16(hse on) -> Enable The HSE Clock */
	SET_BIT(RCC_CR, 16);

	/* Bit 17(hse ready) -> Checking While The HSE Clock Is Stable */
	while((GET_BIT(RCC_CR, 17) == 0) && (LOC_u32TimeOut < 100000))
	{ LOC_u32TimeOut++; }
	if( LOC_u32TimeOut >= 100000 ){ /*TimeOut*/ }




#elif   RCC_TYPE == RCC_PLL
    /*phase locked loop */
	/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
	/* PLL Selected As A System Clock */
	CLR_BIT(RCC_CFGR, 0);
	SET_BIT(RCC_CFGR, 1);

    /* PLL_INPUT */
    #if     PLL_INPUT == RCC_PLL_HSI_DIV_2
        /* hsi divided by 2 */
		/* BIT 16 -> Choose PLL Source -> If HSI/2 OR HSE */
		/* PLL Entry Clock Source Is HSI Divided By 2 */
		CLR_BIT(RCC_CFGR, 16);

	#elif   PLL_INPUT == RCC_PLL_HSE
        /* hse */
		/* Bit 16 -> Enable The HSE Clock */
		SET_BIT(RCC_CR, 16);

		/* BIT 16 -> Choose PLL Source -> If HSI/2 OR HSE */
		/* PLL Entry Clock Source Is HSE */
		SET_BIT(RCC_CFGR, 16);

		/* BIT 17 -> IF PLL Source IS HSE Then Choose Between Divide HSE/2 Or Not  */
		/* HSE Is Not Divided */
		CLR_BIT(RCC_CFGR, 17);

    #elif   PLL_INPUT == RCC_PLL_HSE_DIV_2
        /* hse */
		/* Bit 16 -> Enable The HSE Clock */
		SET_BIT(RCC_CR, 16);

		/* BIT 16 -> Choose PLL Source -> If HSI/2 OR HSE */
		/* PLL Entry Clock Source Is HSE */
		SET_BIT(RCC_CFGR, 16);

		/* BIT 17 -> IF PLL Source IS HSE Then Choose Between Divide HSE/2 Or Not  */
		/* HSE Is Not Divided */
		SET_BIT(RCC_CFGR, 17);

    #else
        #error "wrong pll input"

    #endif  /* PLL_INPUT */

    /* Checking the value of multiplication factor */
    #if ((PLL_CLK_MUL_FAC > RCC_PLL_CLK_MUL_16)  ||  (PLL_CLK_MUL_FAC < RCC_PLL_CLK_MUL_2))
        #error "wrong multiplication factor"
    
    #else
		/*BIT 18:21(pll multiplication)*/
		RCC_CFGR &= ~((0b1111) << 18);			/* clear the four bits */
		RCC_CFGR |=  (PLL_CLK_MUL_FAC) << 18;	/* write the corresponding value */

    #endif

	/* Bit 25(pll ready) -> Checking While The HSE Clock Is Stable */
	while((GET_BIT(RCC_CR, 25) == 0) && (LOC_u32TimeOut < 100000))
	{ LOC_u32TimeOut++; }
	if( LOC_u32TimeOut >= 100000 ){ /*TimeOut*/ }
#else
    #error "wrong rcc type"

#endif  /* RCC_TYPE */

/* CLK_SECURITY_SYSTEM */
#if     CLK_SECURITY_SYSTEM == RCC_CSS_ENABLE
    /* css is on */
	SET_BIT(RCC_CR, 19);
#else
    /* css is off */
	CLR_BIT(RCC_CR, 19);
#endif  /* CLK_SECURITY_SYSTEM */
}

void RCC_VidEnablePeripheralClock (uint8_t Copy_u8PeripheralBus, uint8_t Copy_u8Peripheral)
{
    switch (Copy_u8PeripheralBus)
    {
        case AHB:
        	SET_BIT(RCC_AHBENR, Copy_u8Peripheral);
        	break;
        case APB1:
        	SET_BIT(RCC_APB1ENR, Copy_u8Peripheral);
        	break;
        case APB2:
        	SET_BIT(RCC_APB2ENR, Copy_u8Peripheral);
        	break;
        default :
        	break;
    }

}
void RCC_VidDisablePeripheralClock(uint8_t Copy_u8PeripheralBus, uint8_t Copy_u8Peripheral)
{
    switch (Copy_u8PeripheralBus)
    {
        case AHB:   CLR_BIT(RCC_AHBENR, Copy_u8Peripheral);     break;
        case APB1:  CLR_BIT(RCC_APB1ENR, Copy_u8Peripheral);    break;
        case APB2:  CLR_BIT(RCC_APB2ENR, Copy_u8Peripheral);    break;
        default : break;
    }
}
