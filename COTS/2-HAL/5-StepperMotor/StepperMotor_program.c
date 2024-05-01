/*********************************************************/
/***********		Author: Amgad Samir 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: CLCD 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-8/2020		 	**************/
/*********************************************************/
#define F_CPU 8000000U
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "StepperMotor_config.h"
#include "StepperMotor_interface.h"

void StepperMotor_voidRotateAntiClock(u16 Copy_u16Angle)
{
	u32 Local_u32Iterator=0;
	for(Local_u32Iterator=0 ; Local_u32Iterator<Copy_u16Angle/0.704 ; Local_u32Iterator++ )
	{
		DIO_u8SetPinValue(STEPPER_PORT,BLUE_PIN,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(STEPPER_PORT,PINK_PIN,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,YELLOW_PIN,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,ORANGE_PIN,DIO_u8PIN_LOW);
		_delay_ms(2);
		DIO_u8SetPinValue(STEPPER_PORT,BLUE_PIN,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,PINK_PIN,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(STEPPER_PORT,PINK_PIN,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,YELLOW_PIN,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(STEPPER_PORT,YELLOW_PIN,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,ORANGE_PIN,DIO_u8PIN_HIGH);
		_delay_ms(2);
		
	}
}



void StepperMotor_voidRotateClock(u16 Copy_u16Angle)
{
	u32 Local_u32Iterator=0;
	for(Local_u32Iterator=0 ; Local_u32Iterator<Copy_u16Angle/0.704 ; Local_u32Iterator++ )
	{
		DIO_u8SetPinValue(STEPPER_PORT,BLUE_PIN,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,PINK_PIN,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,YELLOW_PIN,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,ORANGE_PIN,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(STEPPER_PORT,ORANGE_PIN,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,YELLOW_PIN,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(STEPPER_PORT,YELLOW_PIN,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,PINK_PIN,DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(STEPPER_PORT,PINK_PIN,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(STEPPER_PORT,BLUE_PIN,DIO_u8PIN_HIGH);
		_delay_ms(2);
	}
}