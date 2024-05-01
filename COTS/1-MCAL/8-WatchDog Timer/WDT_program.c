/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: WDT			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "WDT_register.h"
#include "WDT_config.h"
#include "WDT_private.h"
#include "WDT_interface.h"


void WDT_voidSleep(u8 Copy_u8SleepTime)
{
	WDTCR&=~(0b111);
	WDTCR|=Copy_u8SleepTime;
}

void WDT_voidEnable()
{
	SET_BIT(WDTCR,WDTCR_WDE);
}


void WDT_voidDisable()
{
	WDTCR|=0b00011000;
	
	WDTCR=0;
}