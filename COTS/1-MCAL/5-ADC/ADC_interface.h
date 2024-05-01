/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: ADC			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef struct 
{
	u8* Channel;
	u16* Result;
	u8 Size;
	void (*NotificationFunc)(void);
}Chain_t;

s32 Mapping(s32 Copy_s32InputMin,s32 Copy_s32InputMax,s32 Copy_s32OutputMin,s32 Copy_s32OutputMax,s32 Copy_s32Input);


void ADC_voidInit();

/*


*/

u8   ADC_u16StartConversionSync(u8 Copy_u8Channel, u16* Copy_pu16Result);

u8   ADC_u16StartConversionASync(u8 Copy_u8Channel, u16* Copy_pvResult, void (*Copy_pvNotificationFunc)(void));

u8 ADC_u8StartChainAsync(Chain_t* Copy_psChain);
#endif