/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: WDT			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

#define TIMEOUT_16300us	0
#define TIMEOUT_32500us	1
#define TIMEOUT_65ms	2
#define TIMEOUT_130ms	3
#define TIMEOUT_260ms	4
#define TIMEOUT_520ms	5
#define TIMEOUT_1s		6
#define TIMEOUT_2100ms	7	

void WDT_voidSleep(u8 Copy_u8SleepTime);

void WDT_voidEnable(void);

void WDT_voidDisable();
	
#endif