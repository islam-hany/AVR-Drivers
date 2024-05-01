/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: EXTI			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_register.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"

void EXTI_voidInt0Init(void)
{
	#if (INT0_SENSE==LOW_LEVEL)
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		
	#elif (INT0_SENSE==ON_CHANGE)
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		
	#elif (INT0_SENSE==FALLING_EDGE)
		CLR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
	
	#elif (INT0_SENSE==RISING_EDGE)
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
	
	#else 
	#error "Wrong INT0_SENSE configuration option"
	#endif
	
	#if INT0_INITIAL_STATE == ENABLED 
		SET_BIT(GICR,GICR_INT0);
	#elif INT0_INITIAL_STATE == DISABLED
		CLR_BIT(GICR,GICR_INT0);
	#else
	#error "Wrong INT0_INITIAL_STATE configuration option"
	#endif
	
}

void EXTI_voidInt1Init(void)
{
	#if (INT1_SENSE==LOW_LEVEL)
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
						   
	#elif (INT1_SENSE==ON_CHANGE)
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
						   
	#elif (INT1_SENSE==FALLING_EDGE)
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
						   
	#elif (INT1_SENSE==RISING_EDGE)
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
	
	#else
	#error "Wrong INT1_SENSE configuration option"
	#endif
	
	#if INT1_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT1);
	#elif INT1_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT1);
	#else
	#error "Wrong INT1_INITIAL_STATE configuration option"
	#endif
	
}

void EXTI_voidInt2Init(void)
{
	#if (INT2_SENSE==FALLING_EDGE)
	CLR_BIT(MCUCSR,MCUCSR_ISC2);
	#elif (INT2_SENSE==RISING_EDGE)
	SET_BIT(MCUCSR,MCUCSR_ISC2);
	
	#else
	#error "Wrong INT2_SENSE configuration option"
	#endif
	
	#if INT2_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT2);
	#elif INT2_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT2);
	#else
	#error "Wrong INT2_INITIAL_STATE configuration option"
	#endif
}

u8 EXTI_voidInt0SetSense(u8 Copy_u8SenseType)
{
	u8 Local_u8ErrorState=0;	
	switch(Copy_u8SenseType)
	{
		case FALLING_EDGE:
		CLR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
		case RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
		break;
		case LOW_LEVEL:
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		break;
		case ON_CHANGE:
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		break;
		default: 
		Local_u8ErrorState=1;
		break;
	}
	return Local_u8ErrorState;
}

u8 EXTI_voidInt1SetSense(u8 Copy_u8SenseType)
{
	u8 Local_u8ErrorState=0;	
	switch(Copy_u8SenseType)
	{
		case FALLING_EDGE:
		CLR_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
		break;
		case RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
		break;
		case LOW_LEVEL:
		CLR_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
		break;
		case ON_CHANGE:
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
		break;
		default:
		Local_u8ErrorState=1;
		break;
	}
return Local_u8ErrorState;
	
}

u8 EXTI_voidInt2SetSense(u8 Copy_u8SenseType)
{
	u8 Local_u8ErrorState=0;	
	switch(Copy_u8SenseType)
	{
		case FALLING_EDGE:
		CLR_BIT(MCUCSR,MCUCSR_ISC2);
		break;
		case RISING_EDGE:
		SET_BIT(MCUCSR,MCUCSR_ISC2);
		break;
		default:
		Local_u8ErrorState=1;
		break;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8IntEnable(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState=0;
	switch(Copy_u8IntNumber)
	{
		case INT0:
		SET_BIT(GICR,GICR_INT0);
		break;
		case INT1:
		SET_BIT(GICR,GICR_INT1);
		break;
		case INT2:
		SET_BIT(GICR,GICR_INT2);
		break;
		default: Local_u8ErrorState=1; break;
	}
	return Local_u8ErrorState;
}


u8 EXTI_u8IntDisable(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState=0;
	switch(Copy_u8IntNumber)
	{
		case INT0:
		CLR_BIT(GICR,GICR_INT0);
		break;
		case INT1:
		CLR_BIT(GICR,GICR_INT1);
		break;
		case INT2:
		CLR_BIT(GICR,GICR_INT2);
		break;
		default: Local_u8ErrorState=1; break;
	}
	return Local_u8ErrorState;
}


void (*EXTI_pvInt0Func)(void)=0;

void (*EXTI_pvInt1Func)(void)=0;

void (*EXTI_pvInt2Func)(void)=0;

u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func) (void))
{
	u8 Local_u8ErrorState=0;
	if (Copy_pvInt0Func!=0)
	{
		EXTI_pvInt0Func=Copy_pvInt0Func;
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func) (void))
{
	u8 Local_u8ErrorState=0;
	if (Copy_pvInt1Func!=0)
	{
		EXTI_pvInt1Func=Copy_pvInt1Func;
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}
u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func) (void))
{
	u8 Local_u8ErrorState=0;
	if (Copy_pvInt2Func!=0)
	{
		EXTI_pvInt2Func=Copy_pvInt2Func;
	}
	else
	{
		Local_u8ErrorState=1;
	}
	return Local_u8ErrorState;
}


void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	if(EXTI_pvInt0Func!=0)
	{EXTI_pvInt0Func();}
}



void __vector_2(void)  __attribute__((signal));
void __vector_2(void)
{
	if(EXTI_pvInt1Func!=0)
	{EXTI_pvInt1Func();}
}



void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
	if(EXTI_pvInt2Func!=0)
	{EXTI_pvInt2Func();}
}