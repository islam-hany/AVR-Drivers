/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: WDT			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef WDT_REGISTER_H_
#define WDT_REGISTER_H_

#define WDTCR		*((volatile u8*)0x41)
#define WDTCR_WDTOE		4				// Watchdog Turn-off Enable
#define WDTCR_WDE		3				//Watchdog Enable
#define WDTCR_WDP2		2				//Watchdog Timer Prescaler
#define WDTCR_WDP1		1				//Watchdog Timer Prescaler
#define WDTCR_WDP0		0				//Watchdog Timer Prescaler
	
#endif