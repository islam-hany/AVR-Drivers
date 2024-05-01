/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: UART			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_
/*
Baud rate options:
2400
4800
9600
14400
19200
38400
57600
76800UL
115200UL
*/

#define UART_BAUDRATE	9600

/*
parity options:
ON
OFF
*/

#define UART_PARITY	OFF

/*
parity Types:
EVEN_PARITY
ODD_PARITY													
*/

#define UART_PARITY_TYPE	
/*
stop bit options:
1				for 1 stop bit
2				for 2 stop bits
*/
#define UART_STOPBITS	2
#endif