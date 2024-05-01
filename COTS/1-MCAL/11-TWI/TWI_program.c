/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: TWI			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>
#include "TWI_register.h"
#include "TWI_private.h"
#include "TWI_config.h"
#include "TWI_interface.h"

void TWI_voidEnableMasterAck()
{
	//enable ACK bit while reading
	SET_BIT(TWCR,TWCR_TWEA);
}

void TWI_voidDisableMasterAck()
{
	//enable ACK bit while reading
	CLR_BIT(TWCR,TWCR_TWEA);
}

void TWI_voidMasterInit(u8 Copy_u8SlaveAddress)
{
	//set comm frequency to 400Kbps
	TWBR=2;
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);
	
	if (Copy_u8SlaveAddress!=0)
	{
		//assign address for microcontroller so that if is called it will work
		TWAR=Copy_u8SlaveAddress<<1;
	}
	
	//enable ACK bit while reading
	SET_BIT(TWCR,TWCR_TWEA);
	
	//enable TWI
	SET_BIT(TWCR,TWCR_TWEN);
	
}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	//enable ACK bit
	SET_BIT(TWCR,TWCR_TWEA);
	
	//Assign slave address
	TWAR=Copy_u8SlaveAddress<<1;
	
	//enable TWI
	SET_BIT(TWCR,TWCR_TWEN);
}

TWI_ErrStatus TWI_SendStartCondition()
{
	TWI_ErrStatus Local_ErrorStatus=NoError;
	
	//initiate communication with start condtion 
	SET_BIT(TWCR,TWCR_TWSTA);
	
	//clear flag to start the previous opertaion 
	SET_BIT(TWCR,TWCR_TWINT);
	
	while(0==(GET_BIT(TWCR,TWCR_TWINT)));
	
	//Check operation state in status register
	if((TWSR & 0xf8)!=START_ACK)
	{
		Local_ErrorStatus=StartCondtionError;
	}

	
	return Local_ErrorStatus;
	
}

TWI_ErrStatus TWI_SendRepeatedStart()
{
	TWI_ErrStatus Local_ErrorStatus=NoError;
	
	//initiate communication with start condtion
		SET_BIT(TWCR,TWCR_TWSTA);
		
		//clear flag to start the previous opertaion
		SET_BIT(TWCR,TWCR_TWINT);
		
		while(0==GET_BIT(TWCR,TWCR_TWINT));
		
		//Check operation state in status register
		if((TWSR& 0xf8)!=REP_START_ACK)
		{
			Local_ErrorStatus=RepeatedStartError;
		}
		
	return Local_ErrorStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrStatus Local_ErrorStatus=NoError;
	
	//Setting SLA+R/W
	TWDR=(Copy_u8SlaveAddress << 1);
	CLR_BIT(TWDR,0);      //for write request
	
 	//clear start condition
	CLR_BIT(TWCR,TWCR_TWSTA);
	
	//clear flag to start the previous opertaion
	SET_BIT(TWCR,TWCR_TWINT);
	
	while(0==GET_BIT(TWCR,TWCR_TWINT));
	
	//Check operation state in status register
	if((TWSR&(~(0b111)))!=SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrorStatus=SlaveAdressWithWriteError;
	}
	
	return Local_ErrorStatus;
}

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ErrStatus Local_ErrorStatus=NoError;
	
	//Setting SLA+R/W
	TWDR=(Copy_u8SlaveAddress<<1);
	SET_BIT(TWDR,0);      //for read request 
	
	//clear start condition
	CLR_BIT(TWCR,TWCR_TWSTA);
	
	//clear flag to start the previous opertaion
	SET_BIT(TWCR,TWCR_TWINT);
	
	while(0==GET_BIT(TWCR,TWCR_TWINT));
	
	//Check operation state in status register
	if((TWSR&(~(0b111)))!=SLAVE_ADD_AND_RD_ACK)
	{
		Local_ErrorStatus=SlaveAdressWithReadError;
	}
	
	return Local_ErrorStatus;
}

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8Data)
{
	TWI_ErrStatus Local_ErrorStatus=NoError;

	//putting data on data bus
	TWDR=Copy_u8Data;
	
	//clear flag to start the previous opertaion
	SET_BIT(TWCR,TWCR_TWINT);
	
	while(0==GET_BIT(TWCR,TWCR_TWINT));
	
	//Check operation state in status register
	if((TWSR&(~(0b111)))!=MSTR_WR_BYTE_ACK)
	{
		Local_ErrorStatus=MasterWriteByteError;
	}
	
	return Local_ErrorStatus;
}

TWI_ErrStatus TWI_MasterReadDataByteWithAck(u8 *Copy_pu8Data)
{
	TWI_ErrStatus Local_ErrorStatus=NoError;
	
	TWI_voidEnableMasterAck();
	//clear flag to allow the slave take data bus
	SET_BIT(TWCR,TWCR_TWINT);
	
	while(0==GET_BIT(TWCR,TWCR_TWINT));
	
	//Check operation state in status register
	if((TWSR & 0xf8)!=MSTR_RD_BYTE_WITH_ACK)
	{
		Local_ErrorStatus=MasterReadByteError;
	}
	else
	{
		//putting data on data bus
		*Copy_pu8Data=TWDR;
	}
	return Local_ErrorStatus;
}

TWI_ErrStatus TWI_MasterReadDataByteWithoutAck(u8 *Copy_pu8Data)
{
	TWI_ErrStatus Local_ErrorStatus=NoError;
	
	TWI_voidDisableMasterAck();
	//clear flag to allow the slave take data bus
	SET_BIT(TWCR,TWCR_TWINT);
	
	while(0==GET_BIT(TWCR,TWCR_TWINT));
	
	//Check operation state in status register
	if((TWSR & 0xf8)!=MSTR_RD_BYTE_WITH_NACK)
	{
		Local_ErrorStatus=MasterReadByteError;
	}
	else
	{
		//putting data on data bus
		*Copy_pu8Data=TWDR;
	}
	return Local_ErrorStatus;
}

void TWI_SendStopConition()
{
	//generate stop condition on bus
	SET_BIT(TWCR,TWCR_TWSTO);
	
	//clear flag to allow the slave take data bus
	SET_BIT(TWCR,TWCR_TWINT);
}

u8 TWI_u8GetStatus(void)
{
	return (TWSR & 0xF8);
}