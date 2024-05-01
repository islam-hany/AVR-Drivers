/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: TIMER			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_register.h"
#include "TIMER_config.h"
#include "TIMER_private.h"
#include "TIMER_interface.h"

static void (*TIMER0_pvCallBackFunc)(void)=NULL;
static void (*ICU_pvCallBackFunc)(void)=NULL;

void ICU_voidInit()
{
	//Choosing initially Input Capture Edge triggering Select (rising edge)
	SET_BIT(TCCR1B,TCCR1B_ICES1);
	
	//Enable input capture interrupt
	SET_BIT(TIMSK,TIMSK_TICIE1);
	
}

//we need to make function to enable or disable any interrupt type in timers
void ICU_voidInterruptState(u8 Copy_u8State)
{
	if (ENABLED==Copy_u8State)	SET_BIT(TIMSK,TIMSK_TICIE1);
	else if (DISABLED==Copy_u8State)	CLR_BIT(TIMSK,TIMSK_TICIE1);
}

u16 ICU_u16ReadInputCapture()
{
	return ICR1;
}

u8 ICU_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState=OK;
	if (Copy_pvCallBackFunc==NULL)
	Local_u8ErrorState=NULL_POINTER;
	else
	{
		ICU_pvCallBackFunc=Copy_pvCallBackFunc;
	}
	return Local_u8ErrorState;
}


u8 ICU_voidSetTriggerEdge(u8 Copy_u8Edge)
{
	u8 Local_u8ErrorState=OK;
	if (Copy_u8Edge==FALLING_EDGE)
	CLR_BIT(TCCR1B,TCCR1B_ICES1);
	else if (Copy_u8Edge==RISING_EDGE)
	SET_BIT(TCCR1B,TCCR1B_ICES1);
	else
	{Local_u8ErrorState=NOK;}
	return Local_u8ErrorState;
}

void TIMER0_u8SetCompMatchValue(u8 Copy_u8CompMatchValue)
{
	OCR0=Copy_u8CompMatchValue;
}

void TIMER0_voidInit()
{
	//Selecting Fast PWM mode
	SET_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TCCR0,TCCR0_WGM00);
	
	SET_BIT(TCCR0,TCCR0_COM01);
	CLR_BIT(TCCR0,TCCR0_COM00);
	
	//Selecting Prescaler division by 8
	TCCR0&=~(0b111);
	TCCR0|=2;
}



void TIMER1_voidSetTimerValue(u16 Copy_u16TimerValue)
{
	TCNT1=Copy_u16TimerValue;
}

void TIMER1_voidInit()
{
	//Selecting Normal mode
	CLR_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	
	//Selecting Fast PWM with controlled Top value
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);
	
	//Selecting prescaler Division by 8
	TCCR1B&=~(0b111);
	TCCR1B|=2;
	
}

u16 TIMER1_u16TimerReading()
{
	return TCNT1;
}


void TIMER1_voidSetICR(u16 Copy_u8ICRValue)
{
	ICR1=Copy_u8ICRValue;
}

void TIMER1_voidSetChannelACompMatch(u16 Copy_u8CompMatchValue)
{
	OCR1A=Copy_u8CompMatchValue;
}

u8 TIMER0_u8SetCallBackFunc(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if (Copy_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc=Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}
	return Local_u8ErrorStatus;
}

void __vector_10(void)  __attribute__((signal));
void __vector_10()
{
	if (TIMER0_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc();
	}
}


void __vector_6(void)  __attribute__((signal));
void __vector_6()
{
	if (ICU_pvCallBackFunc!=NULL)
	{
		ICU_pvCallBackFunc();
	}
}