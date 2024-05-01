/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: HAL			****************/
/*****************		Component: SSD		****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/


#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SSD_interface.h"

u8 segment[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01100111};

u8 SSD_u8SetValue(SSD_s* Copy_Properties)
{
	u8 Local_u8ErrorState=0;
	if(Copy_Properties->SSD_Type == SSD_u8COM_ANODE)
	{
		DIO_u8SetPortDirection(Copy_Properties->DIO_Port,DIO_u8PORT_OUTPUT);
		DIO_u8SetPortValue(Copy_Properties->DIO_Port,~(segment[Copy_Properties->SSD_Value]));
		DIO_u8SetPinDirection(Copy_Properties->SSD_EnablePort,Copy_Properties->SSD_EnablePin,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue(Copy_Properties->SSD_EnablePort,Copy_Properties->SSD_EnablePin,DIO_u8PIN_HIGH);
	}
	else if (Copy_Properties->SSD_Type == SSD_u8COM_CATHODE)
	{
		DIO_u8SetPortDirection(Copy_Properties->DIO_Port,DIO_u8PORT_OUTPUT);
		DIO_u8SetPortValue(Copy_Properties->DIO_Port,segment[Copy_Properties->SSD_Value]);
		DIO_u8SetPinDirection(Copy_Properties->SSD_EnablePort,Copy_Properties->SSD_EnablePin,DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue(Copy_Properties->SSD_EnablePort,Copy_Properties->SSD_EnablePin,DIO_u8PIN_LOW);
		
	}
	else Local_u8ErrorState=1;
	return Local_u8ErrorState;
}
u8 SSD_u8On(SSD_s* Copy_Properties)
{
	u8 Local_u8ErrorState=0;
	if(Copy_Properties->SSD_Type == SSD_u8COM_ANODE)
	{
		DIO_u8SetPinValue(Copy_Properties->SSD_EnablePort,Copy_Properties->SSD_EnablePin,DIO_u8PIN_HIGH);
		
	}
	else if (Copy_Properties->SSD_Type == SSD_u8COM_CATHODE)
	{
		DIO_u8SetPinValue(Copy_Properties->SSD_EnablePort,Copy_Properties->SSD_EnablePin,DIO_u8PIN_LOW);
	}
	else Local_u8ErrorState=1;
	return Local_u8ErrorState;
}
u8 SSD_u8Off(SSD_s* Copy_Properties)
{
	u8 Local_u8ErrorState=0;
	if(Copy_Properties->SSD_Type == SSD_u8COM_ANODE)
	{
		DIO_u8SetPinValue(Copy_Properties->SSD_EnablePort,Copy_Properties->SSD_EnablePin,DIO_u8PIN_LOW);
		
	}
	else if (Copy_Properties->SSD_Type == SSD_u8COM_CATHODE)
	{
		DIO_u8SetPinValue(Copy_Properties->SSD_EnablePort,Copy_Properties->SSD_EnablePin,DIO_u8PIN_HIGH);
	}
	else Local_u8ErrorState=1;
	return Local_u8ErrorState;
}

