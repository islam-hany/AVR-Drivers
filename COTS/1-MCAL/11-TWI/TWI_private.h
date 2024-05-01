/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: TWI			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

#define START_ACK				0x08			//start has been sent	
#define REP_START_ACK			0x10			//repeated start
#define SLAVE_ADD_AND_WR_ACK	0X18			//Master transmit(slave address + write requiste)ACK
#define SLAVE_ADD_AND_RD_ACK	0X40			//Master transmit(slave address + read requiste)ACK
#define MSTR_WR_BYTE_ACK		0X28			//Master transmit data ACK
#define MSTR_RD_BYTE_WITH_ACK	0X50			//Master received data with ACK
#define MSTR_RD_BYTE_WITH_NACK	0X58			//Master received data with no ACK
#define SLAVE_ADD_RCVD_RD_REQ	0XA8			//means that slave address is received with read request
#define SLAVE_ADD_RCVD_WR_REQ	0X60			//means that slave address is received with write request
#define	SLAVE_DATA_RECEIVED		0X80			//means that a byte is received 
#define SLAVE_BYTE_TRANSMITTED	0XB8			//means that the written byte is transmitted

#endif