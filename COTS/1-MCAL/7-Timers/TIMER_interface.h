/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: TIMER			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define FALLING_EDGE	0
#define RISING_EDGE		1

#define ENABLED			1
#define DISABLED		2



void TIMER0_voidInit();
void TIMER1_voidSetTimerValue(u16 Copy_u16TimerValue);
u16 TIMER1_u16TimerReading();


void ICU_voidInit();

/*
Trigger Edge options:
.FALLING_EDGE
.RISING_EDGE
*/

u8 ICU_voidSetTriggerEdge(u8 Copy_u8Edge);

/*
Interrupt State options:
.ENABLED
.DISABLED
*/
void ICU_voidInterruptState(u8 Copy_u8State);

u16 ICU_u16ReadInputCapture();

u8 ICU_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));

void TIMER1_voidInit();
void TIMER1_voidSetICR(u16 Copy_u8ICRValue);
void TIMER1_voidSetChannelACompMatch(u16 Copy_u8CompMatchValue);


void TIMER0_u8SetCompMatchValue(u8 Copy_u8CompMatchValue);

u8 TIMER0_u8SetCallBackFunc(void (*Copy_pvCallBackFunc)(void));
	
#endif