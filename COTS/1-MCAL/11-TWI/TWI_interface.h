/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: TWI			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

typedef enum
{
	NoError,StartCondtionError,RepeatedStartError,SlaveAdressWithWriteError,SlaveAdressWithReadError,
	MasterWriteByteError, MasterReadByteError
	}TWI_ErrStatus; 
	
u8 TWI_u8GetStatus(void);
	
void TWI_voidDisableMasterAck();

void TWI_voidEnableMasterAck();

//pass 0 in the slave address argument if master will not be addressed
void TWI_voidMasterInit(u8 Copy_u8SlaveAddress);

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_SendStartCondition();

TWI_ErrStatus TWI_SendRepeatedStart();

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8Data);

TWI_ErrStatus TWI_MasterReadDataByteWithAck(u8 *Copy_pu8Data);

TWI_ErrStatus TWI_MasterReadDataByteWithoutAck(u8 *Copy_pu8Data);

void TWI_SendStopConition();

#endif