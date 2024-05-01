#define F_CPU 8000000

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "TIMER_interface.h"
#include "ADC_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>
void Servo();
u16 Result;
int main(void)
{
    PORT_voidInit();
	ADC_voidInit();
	TIMER1_voidSetICR(20000);
	TIMER1_voidInit();
	GIE_voidEnable();
    while (1) 
    {
		ADC_u16StartConversionASync(0,&Result,Servo);
		
    }
}

void Servo()
{
	TIMER1_voidSetChannelACompMatch(Mapping(0,1023,500,#define F_CPU 8000000

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "TIMER_interface.h"
#include "ADC_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>
void Servo();
u16 Result;
int main(void)
{
    PORT_voidInit();
	ADC_voidInit();
	TIMER1_voidSetICR(20000);
	TIMER1_voidInit();
	GIE_voidEnable();
    while (1) 
    {
		ADC_u16StartConversionASync(0,&Result,Servo);
		
    }
}

void Servo()
{
	TIMER1_voidSetChannelACompMatch(Mapping(0,1023,500,2500,Result));
},Result));
}