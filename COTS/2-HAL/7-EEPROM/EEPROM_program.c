/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: HAL			****************/
/*****************		Component: EEPROM	****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define F_CPU 8000000UL
#include "TWI_interface.h"
#include "TWI_private.h"

#include <util/delay.h>
#include "EEPROM_private.h"
#include "EEPROM_config.h"
#include "EEPROM_interface.h"


TWI_ErrStatus EEPROM_SendDataByte(u8 Copy_u8DataByte, u16 Copy_u16DataAdress)
{
	TWI_ErrStatus Local_State=NoError;
	
	Local_State=TWI_SendStartCondition();
	
	if (NoError==Local_State)
	{
		u8 PageAddress=Copy_u16DataAdress>>8;
		u8 AddressPacket=((0b1010)<<3) | (A2_State<<2) | PageAddress;
		Local_State=TWI_SendSlaveAddressWithWrite(AddressPacket);
	}
	else
	{
		Local_State=StartCondtionError;
		return Local_State;
	}
	
	if (NoError==Local_State)
	Local_State=TWI_MasterWriteDataByte((u8)Copy_u16DataAdress);
	else
	{
		Local_State=SlaveAdressWithWriteError;
		return Local_State;
	}
	
	if (NoError==Local_State)
	{
		Local_State=TWI_MasterWriteDataByte(Copy_u8DataByte);
	}
	else
	{
		Local_State=MasterWriteByteError;
		return Local_State;
	}
	
	
	if (NoError==Local_State)
	{
		TWI_SendStopConition();
	}
	else
	{
		Local_State=MasterWriteByteError;
		return Local_State;
	}
	
	_delay_ms(11);
	return Local_State;
	
} 




TWI_ErrStatus EEPROM_ReceiveDataByte(u8 *Copy_pu8DataByte, u16 Copy_u16DataAdress)
{
	TWI_ErrStatus Local_State=NoError;
	
	Local_State=TWI_SendStartCondition();
	
	if (NoError==Local_State)
	{
		u8 PageAddress=Copy_u16DataAdress>>8;
		u8 AddressPacket=((0b1010)<<3) | (A2_State<<2) | PageAddress;
		Local_State=TWI_SendSlaveAddressWithWrite(AddressPacket);
	}
	else
	{
		Local_State=StartCondtionError;
		return Local_State;
	}
	
	if (NoError==Local_State)
	Local_State=TWI_MasterWriteDataByte((u8)Copy_u16DataAdress);
	else
	{
		Local_State=SlaveAdressWithWriteError;
		return Local_State;
	}
	
	if (NoError==Local_State)
	Local_State=TWI_SendRepeatedStart();
	else
	{
		Local_State=MasterWriteByteError;
		return Local_State;
	}
	
	if (NoError==Local_State)
	{
		u8 PageAddress=Copy_u16DataAdress>>8;
		u8 AddressPacket=((0b1010)<<3) | (A2_State<<2) | PageAddress;
		Local_State=TWI_SendSlaveAddressWithRead(AddressPacket);
	}
	else
	{
		Local_State=RepeatedStartError;
		return Local_State;
	}
	
	
	if (NoError==Local_State)
	Local_State=TWI_MasterReadDataByteWithoutAck(Copy_pu8DataByte);
	else
	{
		Local_State=SlaveAdressWithReadError;
		return Local_State;
	}
	
	if (NoError==Local_State)
	TWI_SendStopConition();
	else
	{
		Local_State=MasterReadByteError;
		return Local_State;
	}
	
	return Local_State;
}