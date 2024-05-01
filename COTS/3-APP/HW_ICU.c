#define F_CPU 8000000

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "GIE_interface.h"
#include "TIMER_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>

u16 OnTime=0;
u16 PeroidTime=0;
void ICU();
u16 Result;
int main(void)
{
	PORT_voidInit();
	TIMER0_u8SetCompMatchValue(0.25*256);
	
	TIMER1_voidInit();
	TIMER0_voidInit();
	ICU_voidInit();
	ICU_u8SetCallBack(ICU);
	GIE_voidEnable();
	
	CLCD_voidInit();
	CLCD_voidSendString("OnTime:");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("PTime:");
	while (1)
	{
		CLCD_voidWriteNumber(OnTime,0,9);
		CLCD_voidWriteNumber(PeroidTime,1,8);
	}
}

void ICU()
{
	static u16 FirstReading=0,SecondReading=0;
	static u8 NumberOfEdge=0;
	NumberOfEdge++;
	switch (NumberOfEdge)
	{
		case 1:
		FirstReading=ICU_u16ReadInputCapture();
		break;
		case 2:
		SecondReading=ICU_u16ReadInputCapture();
		PeroidTime=SecondReading-FirstReading;
		ICU_voidSetTriggerEdge(FALLING_EDGE);
		break;
		case 3:
		OnTime=ICU_u16ReadInputCapture()-SecondReading;
		ICU_voidInterruptState(DISABLED);
		break;
	}
}
