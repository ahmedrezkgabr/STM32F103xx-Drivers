/********************************************/
/*	Author		: Ahmed Rezk		        */
/*	Date		: 22 Feb 2023		        */
/*	file name	: STP_config.h			    */
/*	file module	: serial to parallel        */
/********************************************/


/* file guard */
#ifndef STP_CONFIG__H_
#define STP_CONFIG__H_

/* please configure in pairs port, pin*/
#define STP_SERIAL_DATA					PORT_A,PIN0
#define STP_SHIFT_CLOCK					PORT_A,PIN1
#define STP_STORAGE_CLOCK				PORT_A,PIN2

#define STP_NUMBER_OF_PARALLEL_DATA_PINS	8

#endif /* STP_CONFIG__H_ */
