/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: EXTI			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/


#ifndef EXTI_CONFIGE_H_
#define EXTI_CONFIGE_H_

/* 
	FALLING_EDGE
	RISING_EDGE			for interrupt 0 and 1 only
	ON_CHANGE
	LOW_LEVEL
*/
#define INT0_SENSE ON_CHANGE
#define INT1_SENSE ON_CHANGE

/* 
	ENABLED
	DISABLED
*/
#define INT0_INITIAL_STATE  DISABLED
#define INT1_INITIAL_STATE  DISABLED
#define INT2_INITIAL_STATE  ENABLED

/*  
	FALLING_EDGE
	RISING_EDGE			for interrupt 2
*/
#define INT2_SENSE FALLING_EDGE


#endif