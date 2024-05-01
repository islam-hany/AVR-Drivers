/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: HAL			****************/
/*****************		Component: KEYPAD	****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef KPAD_CONFIG_H_
#define KPAD_CONFIG_H_

#define KPAD_COLOUMN0_PIN	DIO_u8PIN3
#define KPAD_COLOUMN1_PIN	DIO_u8PIN2
#define KPAD_COLOUMN2_PIN	DIO_u8PIN1
#define KPAD_COLOUMN3_PIN	DIO_u8PIN0

#define KPAD_ROW0_PIN	DIO_u8PIN4
#define KPAD_ROW1_PIN	DIO_u8PIN5
#define KPAD_ROW2_PIN	DIO_u8PIN6
#define KPAD_ROW3_PIN	DIO_u8PIN7

/*choose KPAD port:
DIO_u8PORTA
DIO_u8PORTB
DIO_u8PORTC
DIO_u8PORTD
*/

#define KPAD_PORT	DIO_u8PORTA


#define NO_PRESSED_KEY 0xff

#define KPAD_R0C0	'1'
#define KPAD_R0C1	'2'
#define KPAD_R0C2	'3'
#define KPAD_R0C3	'+'
#define KPAD_R1C0	'4'
#define KPAD_R1C1	'5'
#define KPAD_R1C2	'6'
#define KPAD_R1C3	'-'
#define KPAD_R2C0	'7'
#define KPAD_R2C1	'8'
#define KPAD_R2C2	'9'
#define KPAD_R2C3	'/'
#define KPAD_R3C0	'*'
#define KPAD_R3C1	'0'
#define KPAD_R3C2	'#'
#define KPAD_R3C3	'x'



#endif