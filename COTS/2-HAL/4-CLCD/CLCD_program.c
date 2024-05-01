/*********************************************************/
/***********		Author: Islam Hany 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: CLCD 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-8/2020		 	**************/
/*********************************************************/
#define F_CPU 8000000
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"

static u8 CLCD_u8WriteLocaton;
void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	if (CLCD_u8WriteLocaton==16)
	{CLCD_voidGoToXY(1,0);}
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	CLCD_u8WriteLocaton++;
}

void CLCD_voidInit(void)
{
	_delay_ms(40);
	CLCD_voidSendCommand(0b00111000);
	CLCD_voidSendCommand(0b00001100);
	CLCD_voidSendCommand(1);
	CLCD_u8WriteLocaton=0;
}

void CLCD_voidSendString(const char* Copy_pu8String)
{
	u16 Local_u16Counter=0;
	while(Copy_pu8String[Local_u16Counter]!='\0')
	{
		CLCD_voidSendData(Copy_pu8String[Local_u16Counter]);
		Local_u16Counter++;
	}
}

void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8Address=0;
	if (Copy_u8XPos==0)
	{
		Local_u8Address=Copy_u8YPos;
	}
	else if (Copy_u8XPos==1)
	{
		Local_u8Address=0x40 + Copy_u8YPos;
	}
	CLCD_u8WriteLocaton=Local_u8Address;
	SET_BIT(Local_u8Address,7);
	CLCD_voidSendCommand(Local_u8Address);
}

void CLCD_voidWriteSpecialCharacter(const u8* Copy_pu8Pattern, u8 Copy_u8PatternNum, u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAdress=0, Local_u8Iterator;
	if (Copy_u8PatternNum<=7)
	{
		Local_u8CGRAMAdress=Copy_u8PatternNum*8;
		SET_BIT(Local_u8CGRAMAdress,6);
		CLCD_voidSendCommand(Local_u8CGRAMAdress);
		for (Local_u8Iterator=0 ; Local_u8Iterator<8 ; Local_u8Iterator++)
		{
			CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
		}
		CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);
		CLCD_voidSendData(Copy_u8PatternNum);
	}
	
}

void CLCD_voidWriteNumber(u32 Copy_u32Number, u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	if (Copy_u32Number==0)
	{
		CLCD_voidGoToXY( Copy_u8XPos, Copy_u8YPos);
		CLCD_voidSendData('0');
	}
	else
	{u8 i,k;
	char string[17]={0};
	for (i=0 ; Copy_u32Number>0 ;i++ )
	{
		char x=Copy_u32Number%10;
		Copy_u32Number/=10;
		string[i]='0'+x;
	}
	string[i]='\0';
	k=i-1;
	for (int j=0 ; j<i/2; j++)
	{
		
		char temp=string[j];
		string[j]=string[j+k];
		string[j+k]=temp;
		k-=2;
	}
	
	CLCD_voidGoToXY( Copy_u8XPos, Copy_u8YPos);
	CLCD_voidSendString(string);
	}
}