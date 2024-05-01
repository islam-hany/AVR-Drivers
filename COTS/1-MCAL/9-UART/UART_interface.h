/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: UART			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_voidSendString(const char *Copy_u8String);

void UART_voidInit();

void UART_voidSendData(u8 Copy_u8SentData);

u8 UART_u8RecieveData();

#endif