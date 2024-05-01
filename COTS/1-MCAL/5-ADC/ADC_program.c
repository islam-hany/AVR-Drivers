/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: ADC			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_register.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_interface.h"
 
static u8* ADC_u8ChainChannelArr=NULL;
static u16 ADC_u8ISRSourse;
static u8 ADC_u8ChannelSize=0;
static u16* ADC_pu16Result=NULL;
static u16* ADC_pu16ChainResult=NULL;
static void (*ADC_pvCallBackNotificationFunc)(void)=NULL;
static u8 ADC_BusyState=IDLE;

void ADC_voidInit()
{
	//reference voltage selection
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	
	#if (ADC_RESOlUTION == RES_8bit)
	
	//Activate Left adjust result 
	SET_BIT(ADMUX,ADMUX_ADLAR);
	
	#elif (ADC_RESOlUTION == RES_10bit)
	
	//Activate Right adjust result
	CLR_BIT(ADMUX,ADMUX_ADLAR);
	#endif
	
	//Set required prescaler
	ADCSRA&=~(0b111);
	ADCSRA|=ADC_PRESCALER;			//Bit Masking
	
	//ADC Enable
	SET_BIT(ADCSRA,ADCSRA_ADEN);
	
}

s32 Mapping(s32 Copy_s32InputMin,s32 Copy_s32InputMax,s32 Copy_s32OutputMin,s32 Copy_s32OutputMax,s32 Copy_s32Input)
{
	s32 Output=(((Copy_s32OutputMax-Copy_s32OutputMin)*(Copy_s32Input-Copy_s32InputMin))/(Copy_s32InputMax-Copy_s32InputMin))+Copy_s32OutputMin;
	return Output;
}





u8   ADC_u16StartConversionSync(u8 Copy_u8Channel, u16* Copy_pu16Result)
{	
	u32 Local_u32Counter=0;
	u8 Local_u8ErrorState=0;
	if (ADC_BusyState==IDLE)
	{
		ADC_BusyState=BUSY;
		//Set the required channel
		ADMUX&=~(0b1111);
		ADMUX|=Copy_u8Channel;
	
		//Start Conversion
		SET_BIT(ADCSRA,ADCSRA_ADSC);
	
		//Polling (busy waiting) until conversion is completed
		while((GET_BIT(ADCSRA,ADCSRA_ADIF)==0) && (Local_u32Counter != ADC_u32TIMEOUT));
		{
			Local_u32Counter++;
		}
		if (Local_u32Counter== ADC_u32TIMEOUT)
		{
			Local_u8ErrorState=1;
		}
		else
		{
			//Therefore the loop is broken due to the flag is raised
			//clear interrupt flag
			SET_BIT(ADCSRA,ADCSRA_ADIF);
		
			#if (ADC_RESOlUTION == RES_8bit)
			*Copy_pu16Result= ADCH;
			#elif (ADC_RESOlUTION == RES_10bit)
			*Copy_pu16Result= ADC;
			#endif
			
			ADC_BusyState=IDLE;
		}
		return Local_u8ErrorState;
	}
	else 
	return Local_u8ErrorState=BUSY_FUNC;
}

u8   ADC_u16StartConversionASync(u8 Copy_u8Channel, u16* Copy_pvResult, void (*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState=0;
	if (ADC_BusyState==IDLE)
	{
		ADC_u8ISRSourse=ASYNC;
		ADC_BusyState=BUSY;
		if ((Copy_pvNotificationFunc==NULL) || Copy_pvResult==NULL)
		Local_u8ErrorState=1;
		else
		{
			ADC_pu16Result=Copy_pvResult;
			ADC_pvCallBackNotificationFunc=Copy_pvNotificationFunc;
			
			//Set the required channel
			ADMUX&=~(0b1111);
			ADMUX|=Copy_u8Channel;
			
			//Start Conversion
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			
			//Enable the ADC interrupt
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
		
		return Local_u8ErrorState;
	}
	else 
	return Local_u8ErrorState=BUSY_FUNC;
}


u8 ADC_u8StartChainAsync(Chain_t* Copy_psChain)
{
	
	u8 Local_u8Errorstate=OK;
	if (Copy_psChain!=NULL)
	{
		if (ADC_BusyState==IDLE)
		{
			ADC_BusyState=BUSY; //the first thing because if any ADC_u8StartConversion is interrupt and called it will be in busy state
			ADC_pvCallBackNotificationFunc();
			ADC_u8ISRSourse=ChAIN_ASYNC;
			ADC_u8ChainChannelArr=Copy_psChain->Channel;
			ADC_pu16ChainResult=Copy_psChain->Result;
			ADC_pvCallBackNotificationFunc=Copy_psChain->NotificationFunc;
			ADC_u8ChannelSize=Copy_psChain->Size;
			
			//Set the required channel
			ADMUX&=~(0b1111);
			ADMUX|=Copy_psChain->Channel[0];
			
			//Start Conversion
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			
			//Enable the ADC interrupt
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
			Local_u8Errorstate=BUSY_FUNC;
		}
	}
	else
	{
		Local_u8Errorstate=NULL_POINTER;
	}
		
	return Local_u8Errorstate;
}












void __vector_16(void)	__attribute__((signal));
void __vector_16(void)
{
	if (ADC_u8ISRSourse==ASYNC)
	{
		ADC_BusyState=IDLE;
		#if (ADC_RESOlUTION == RES_8bit)
		*ADC_pu16Result= ADCH;
		#elif (ADC_RESOlUTION == RES_10bit)
		*ADC_pu16Result= ADC;
		#endif
		ADC_pvCallBackNotificationFunc();
		ADC_u8ISRSourse=0;
		// Disable the ADC interrupt
		CLR_BIT(ADCSRA,ADCSRA_ADIE);
	}
	else if (ADC_u8ISRSourse==ChAIN_ASYNC)
	{
		static u8 Local_u8Counter=0;
		
		#if (ADC_RESOlUTION == RES_8bit)
		ADC_pu16ChainResult[Local_u8Counter]= ADCH;
		#elif (ADC_RESOlUTION == RES_10bit)
		ADC_pu16ChainResult[Local_u8Counter]= ADC;
		#endif
		
		Local_u8Counter++;
		if (Local_u8Counter==ADC_u8ChannelSize)
		{
			ADC_BusyState=IDLE;			//the first thing because if any ADC_u8StartConversion is called in Notification function it can work
			ADC_pvCallBackNotificationFunc();
			Local_u8Counter==0;
			ADC_u8ISRSourse=0;
			// Disable the ADC interrupt
			CLR_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{			
			//Set the required channel
			ADMUX&=~(0b1111);
			ADMUX|=ADC_u8ChainChannelArr[Local_u8Counter];
			
			//Start Conversion
			SET_BIT(ADCSRA,ADCSRA_ADSC);
		}
	}
}