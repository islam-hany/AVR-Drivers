/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: HAL			****************/
/*****************		Component: CLCD		****************/
/*****************		Version: 1.00		****************/
/*****************		Date: 4/26/2023		****************/
/***********************************************************/
/***********************************************************/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/*
CLCD mode options:
MODE_4bit
MODE_8bit
*/

#define MODE MODE_4bit

#define CLCD_DATA_PORT	DIO_u8PORTD

#define CLCD_CTRL_PORT	DIO_u8PORTC

#define CLCD_RS_PIN		DIO_u8PIN0
#define CLCD_RW_PIN		DIO_u8PIN1
#define CLCD_E_PIN		DIO_u8PIN2


#endif