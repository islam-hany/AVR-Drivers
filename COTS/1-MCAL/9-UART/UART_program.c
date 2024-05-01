/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: UART			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>
#include "UART_register.h"
#include "UART_private.h"
#include "UART_config.h"
#include "UART_interface.h"


void UART_voidInit()
{
	#if (UART_PARITY==ON && UART_STOPBITS==1)
	#if (UART_PARITY_TYPE==EVEN_PARITY)
	UCSRC=(1<<UCSRC_URSEL)|(1<<UCSRC_UCSZ1)|(1<<UCSRC_UCSZ0)|(1<<UCSRC_UPM1);
	#elif (UART_PARITY_TYPE==ODD_PARITY)
	UCSRC=(1<<UCSRC_URSEL)|(1<<UCSRC_UCSZ1)|(1<<UCSRC_UCSZ0)|(1<<UCSRC_UPM1)|(1<<UCSRC_UPM0);
	#endif
	
	#elif (UART_PARITY==ON && UART_STOPBITS==2)
	#if (UART_PARITY_TYPE==EVEN_PARITY)
	UCSRC=(1<<UCSRC_URSEL)|(1<<UCSRC_UCSZ1)|(1<<UCSRC_UCSZ0)|(1<<UCSRC_UPM1)|(1<<UCSRC_USBS);
	#elif (UART_PARITY_TYPE==ODD_PARITY)
	UCSRC=(1<<UCSRC_URSEL)|(1<<UCSRC_UCSZ1)|(1<<UCSRC_UCSZ0)|(1<<UCSRC_UPM1)|(1<<UCSRC_UPM0)|(1<<UCSRC_USBS);
	#endif
	
	#elif (UART_PARITY==OFF && UART_STOPBITS==1)
	UCSRC=(1<<UCSRC_URSEL)|(1<<UCSRC_UCSZ1)|(1<<UCSRC_UCSZ0);
	#elif (UART_PARITY==OFF && UART_STOPBITS==2)
	UCSRC=(1<<UCSRC_URSEL)|(1<<UCSRC_UCSZ1)|(1<<UCSRC_UCSZ0)|(1<<UCSRC_USBS);
	
	#endif
	
	//Baud rate settings
	u16 Local_u8Baudrate=((8000000UL)/(16UL*UART_BAUDRATE))-1;
	UBRRL=Local_u8Baudrate;
	UBRRH=Local_u8Baudrate>>8;

	
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);
}

void UART_voidSendData(u8 Copy_u8SentData)
{
	while(0==GET_BIT(UCSRA,UCSRA_UDRE));
	UDR=Copy_u8SentData;
}

u8 UART_u8RecieveData()
{
	while(0==GET_BIT(UCSRA,UCSRA_RXC));
	return UDR;
}

void UART_voidSendString(const char *Copy_u8String)
{
	u16 Local_u16Counter=0;
	while (Copy_u8String[Local_u16Counter]!='\0')
	{
		UART_voidSendData(Copy_u8String[Local_u16Counter]);
		Local_u16Counter++;
	}
}