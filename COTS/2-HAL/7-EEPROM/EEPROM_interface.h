/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: HAL			****************/
/*****************		Component: EEPROM	****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

TWI_ErrStatus EEPROM_ReceiveDataByte(u8 *Copy_pu8DataByte, u16 Copy_u16DataAdress);

TWI_ErrStatus EEPROM_SendDataByte(u8 Copy_u8DataByte, u16 Copy_u16DataAdress);

#endif