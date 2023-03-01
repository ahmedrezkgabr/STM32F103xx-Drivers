/************************************************/
/*	Author		: Ahmed Rezk		        	*/
/*	Date		: 1 Mar 2023		        	*/
/*	file name	: TFT_config.h	 		    	*/
/*	file module	: thin film transistor			*/
/*	Version		: V01				        	*/
/************************************************/

/* file guard */
#ifndef TFT_CONFIG__H_
#define TFT_CONFIG__H_

#define TFT_V_PIXELS	160
#define TFT_H_PIXELS	128

/* write pin in pair PORT_x,PINx */
#define TFT_RST_PIN	PORT_A,PIN1

/* write pin in pair PORT_x,PINx */
#define TFT_A0_PIN	PORT_A,PIN2


#endif	/* TFT_CONFIG__H_ */
