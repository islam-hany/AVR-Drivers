/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: EXI			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


#define INT0 1
#define INT1 2
#define INT2 3

#define LOW_LEVEL	 1  // donot choose 0 as a configuration option since if the user inserted any other option it may be treats it as zero
#define ON_CHANGE	 2
#define FALLING_EDGE 3
#define RISING_EDGE	 4

#define ENABLED 1
#define DISABLED 2

void EXTI_voidInt0Init(void);

void EXTI_voidInt1Init(void);

void EXTI_voidInt2Init(void);

/* Inputs for Copy_u8SenseType for interrupt 0 and 1 are :
	1-FALLING_EDGE
	2-RISING_EDGE			
	3-ON_CHANGE
	4-LOW_LEVEL
	Outputs: returns 0 for no error and returns 1 for error		
*/
u8 EXTI_voidInt0SetSense(u8 Copy_u8SenseType);

u8 EXTI_voidInt1SetSense(u8 Copy_u8SenseType);

/* Inputs for Copy_u8SenseType for interrupt 2 are :
	1-FALLING_EDGE
	2-RISING_EDGE	
	Outputs: returns 0 for no error and returns 1 for error		
*/
u8 EXTI_voidInt2SetSense(u8 Copy_u8SenseType);

/* Inputs for Copy_u8IntNumber :
	 INT0
	 INT1
	 INT2	
	Outputs: returns 0 for no error and returns 1 for error		
*/
u8 EXTI_u8IntEnable(u8 Copy_u8IntNumber);

u8 EXTI_u8IntDisable(u8 Copy_u8IntNumber);

u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void));

u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void));

u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void));


#endif